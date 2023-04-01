/*
 * Copyright: (C)2022PhytiumInformationTechnology,Inc.
 * All Rights Reserved.
 *
 * This program is OPEN SOURCE software: you can redistribute it and/or modify it
 * under the terms of the Phytium Public License as published by the Phytium Technology Co.,Ltd,
 * either version 1.0 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the Phytium Public License for more details.
 *
 *
 * FilePath: fgdma_intr.c
 * Date: 2022-05-16 17:01:48
 * LastEditTime: 2022-05-16 17:01:49
 * Description: This files is for interrupt api implmentation
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   huanghe    2021-11-5    init commit
 * 1.1   zhugengyu  2022-5-16    modify according to tech manual.
 */

/***************************** Include Files *********************************/
#include <string.h>

#include "fdebug.h"
#include "fassert.h"

#include "fgdma_hw.h"
#include "fgdma.h"
/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define FGDMA_DEBUG_TAG "GDMA-INTR"
#define FGDMA_ERROR(format, ...)   FT_DEBUG_PRINT_E(FGDMA_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGDMA_WARN(format, ...)    FT_DEBUG_PRINT_W(FGDMA_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGDMA_INFO(format, ...)    FT_DEBUG_PRINT_I(FGDMA_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGDMA_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FGDMA_DEBUG_TAG, format, ##__VA_ARGS__)

#define FGDMA_CALL_EVT_HANDLER(express, dma_chan, args) \
    do                                                  \
    {                                                   \
        if (express)                                    \
        {                                               \
            express(dma_chan, args);                    \
        }                                               \
    } while (0)

/************************** Function Prototypes ******************************/
/**
 * @name: FGdmaChanIrqHandler
 * @msg: GDMA
 * @return {void} 
 * @param {FGdmaChan} *chan_p, GDMA
 */
static void FGdmaChanIrqHandler(FGdmaChan *const chan_p)
{
    FGdma *const instance_p = chan_p->gdma;
    FASSERT(instance_p);
    uintptr base_addr = instance_p->config.base_addr;
    u32 chan_status = FGdmaReadChanStatus(base_addr, chan_p->config.chan_id);

    if (FGDMA_CHX_INT_STATE_BUSY & chan_status)
    {
        FGDMA_CALL_EVT_HANDLER(chan_p->evt_handlers[FGDMA_CHAN_EVT_BUSY],
                               chan_p, chan_p->evt_handler_args[FGDMA_CHAN_EVT_BUSY]);
    }

    if (FGDMA_CHX_INT_STATE_TRANS_END & chan_status)
    {
        FGDMA_CALL_EVT_HANDLER(chan_p->evt_handlers[FGDMA_CHAN_EVT_TRANS_END],
                               chan_p, chan_p->evt_handler_args[FGDMA_CHAN_EVT_TRANS_END]);
    }

    if (FGDMA_CHX_INT_STATE_BDL_END & chan_status)
    {
        FGDMA_CALL_EVT_HANDLER(chan_p->evt_handlers[FGDMA_CHAN_EVT_BDL_END],
                               chan_p, chan_p->evt_handler_args[FGDMA_CHAN_EVT_BDL_END]);
    }

    if (FGDMA_CHX_INT_STATE_FIFO_FULL & chan_status)
    {
        FGDMA_CALL_EVT_HANDLER(chan_p->evt_handlers[FGDMA_CHAN_EVT_FIFO_FULL],
                               chan_p, chan_p->evt_handler_args[FGDMA_CHAN_EVT_FIFO_FULL]);
    }

    if (FGDMA_CHX_INT_STATE_FIFO_EMPTY & chan_status)
    {
        FGDMA_CALL_EVT_HANDLER(chan_p->evt_handlers[FGDMA_CHAN_EVT_FIFO_EMPTY],
                               chan_p, chan_p->evt_handler_args[FGDMA_CHAN_EVT_FIFO_EMPTY]);
    }

    FGdmaClearChanStatus(base_addr, chan_p->config.chan_id, chan_status);
    return;
}

/**
 * @name: FGdmaIrqHandler
 * @msg: GDMA
 * @return {void} 
 * @param {s32} vector, 
 * @param {void} *args, 
 */
void FGdmaIrqHandler(s32 vector, void *args)
{
    FASSERT(args);
    FGdma *const instance_p = (FGdma * const)args;
    FASSERT(FT_COMPONENT_IS_READY == instance_p->is_ready);
    uintptr base_addr = instance_p->config.base_addr;
    u32 chan_id;

    u32 status = FGdmaReadStatus(base_addr);
    FGDMA_INFO("status: 0x%x", status);

    FGdmaIrqDisable(base_addr);
    for (chan_id = FGDMA_CHAN0_INDEX; chan_id < FGDMA_NUM_OF_CHAN; chan_id++)
    {
        if (!(FGDMA_CHX_INTR_STATE(chan_id) & status))
            continue;

        /* channel interrupt happens */
        FASSERT_MSG((NULL != instance_p->chans[chan_id]), "invalid chan interrupt event !!!");
        FGdmaChanIrqHandler(instance_p->chans[chan_id]);
    }
    FGdmaIrqEnable(base_addr);

    return;
}

/**
 * @name: FGdmaChanRegisterEvtHandler
 * @msg: GDMA
 * @return {void} 
 * @param {FGdmaChan} *chan_p, GDMA
 * @param {FGdmaChanEvtType} evt, 
 * @param {FGdmaChanEvtHandler} handler, 
 * @param {void} *handler_arg, 
 */
void FGdmaChanRegisterEvtHandler(FGdmaChan *const chan_p, FGdmaChanEvtType evt,
                                 FGdmaChanEvtHandler handler, void *handler_arg)
{
    FASSERT(chan_p);
    FASSERT(FGDMA_CHAN_NUM_OF_EVT > evt);

    chan_p->evt_handlers[evt] = handler;
    chan_p->evt_handler_args[evt] = handler_arg;

    return;
}