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
 * FilePath: fsdmmc_intr.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:54:53
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   zhugengyu  2021/12/2    init
 */

/***************************** Include Files *********************************/
#include "fassert.h"
#include "fio.h"
#include "fdebug.h"

#include "fsdmmc_hw.h"
#include "fsdmmc.h"

/************************** Constant Definitions *****************************/
#define FSDMMC_DEBUG_TAG "FSDMMC-INTR"
#define FSDMMC_ERROR(format, ...)   FT_DEBUG_PRINT_E(FSDMMC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FSDMMC_WARN(format, ...)    FT_DEBUG_PRINT_W(FSDMMC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FSDMMC_INFO(format, ...)    FT_DEBUG_PRINT_I(FSDMMC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FSDMMC_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FSDMMC_DEBUG_TAG, format, ##__VA_ARGS__)

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/
static void FSdmmcCallEvtHandler(FSdmmcEventHandler handler, FSdmmc *instance_p)
{
    if (NULL != handler)
    {
        handler((void *)instance_p);
    }
}

/************************** Function Prototypes ******************************/
extern u32 FSdmmcMakeRawCmd(FSdmmcCmd *cmd_p);
extern void FSdmmcSendCmd(uintptr base_addr, FSdmmcCmd *cmd_p);
extern FError FSdmmcSendData(uintptr base_addr, boolean read, FSdmmcCmd *cmd_p);

/************************** Variable Definitions *****************************/

/*****************************************************************************/
/**
 * @name: FSdmmcGetInterruptMask
 * @msg: FSDMMC
 * @return {u32} 
 * @param {uintptr} base_addr FSDMMC
 * @param {u32} intr_type FSDMMC, FSDMMC_INTR_NUM
 * @note FSDMMC
 */
u32 FSdmmcGetInterruptMask(uintptr base_addr, u32 intr_type)
{
    u32 mask;

    switch (intr_type)
    {
    case FSDMMC_CMD_INTR:
        mask = FSDMMC_READ_REG(base_addr, FSDMMC_NORMAL_INT_EN_REG_OFFSET);
        break;
    case FSDMMC_ERROR_INTR:
        mask = FSDMMC_READ_REG(base_addr, FSDMMC_ERROR_INT_EN_REG_OFFSET);
        break;
    case FSDMMC_DMA_BD_INTR:
        mask = FSDMMC_READ_REG(base_addr, FSDMMC_BD_ISR_EN_REG_OFFSET);
        break;
    default:
        FASSERT(0);
        break;
    }

    return mask;
}

/**
 * @name: FSdmmcSetInterruptMask
 * @msg: FSDMMC
 * @param {uintptr} base_addr FSDMMC
 * @param {u32} intr_type FSDMMC, FSDMMC_INTR_NUM
 * @param {u32} mask 
 * @param {boolean} enable TRUE:, FALSE:
 * @note FSDMMC
 */
void FSdmmcSetInterruptMask(uintptr base_addr, u32 intr_type, u32 mask, boolean enable)
{
    u32 old_mask = FSdmmcGetInterruptMask(base_addr, intr_type);
    u32 new_mask = 0;

    if (TRUE == enable)
        new_mask = old_mask | mask;
    else
        new_mask = old_mask & (~mask);

    switch (intr_type)
    {
    case FSDMMC_CMD_INTR:
        FSDMMC_WRITE_REG(base_addr, FSDMMC_NORMAL_INT_EN_REG_OFFSET, new_mask);
        break;
    case FSDMMC_ERROR_INTR:
        FSDMMC_WRITE_REG(base_addr, FSDMMC_ERROR_INT_EN_REG_OFFSET, new_mask);
        break;
    case FSDMMC_DMA_BD_INTR:
        FSDMMC_WRITE_REG(base_addr, FSDMMC_BD_ISR_EN_REG_OFFSET, new_mask);
        break;
    default:
        FASSERT(0);
        break;
    }

    return;
}

/**
 * @name: FSdmmcCmdInterrupHandler
 * @msg: 
 * @return {*} 
 * @param {s32} vector 
 * @param {void} *param 
 * @note FSDMMC
 */
void FSdmmcCmdInterrupHandler(s32 vector, void *param)
{
    FASSERT(param);
    u32 status;
    FSdmmc *instance_p = (FSdmmc *)param;
    uintptr base_addr = instance_p->config.base_addr;

    /* clear interrupts */
    status = FSDMMC_READ_REG(base_addr, FSDMMC_NORMAL_INT_STATUS_REG_OFFSET);

    if (status & FSDMMC_NORMAL_INT_STATUS_CR) /*  */
    {
        FSdmmcCallEvtHandler(instance_p->evt_handler[FSDMMC_EVT_CARD_REMOVED], instance_p);
    }

    if (status & FSDMMC_NORMAL_INT_STATUS_CC) /*  */
    {
        FSdmmcCallEvtHandler(instance_p->evt_handler[FSDMMC_EVT_CMD_DONE], instance_p);
    }

    if (status & FSDMMC_NORMAL_INT_STATUS_EI) /*  */
    {
        FSdmmcCallEvtHandler(instance_p->evt_handler[FSDMMC_EVT_CMD_ERROR], instance_p);
    }

    FSdmmcClearNormalInterruptStatus(base_addr);
}

/**
 * @name: FSdmmcDmaInterrupHandler
 * @msg: DMA
 * @return {*}
 * @param {s32} vector 
 * @param {void} *param 
 * @note FSDMMC
 */
void FSdmmcDmaInterrupHandler(s32 vector, void *param)
{
    FASSERT(param);
    u32 status;
    FSdmmc *instance_p = (FSdmmc *)param;
    uintptr base_addr = instance_p->config.base_addr;

    /* clear interrupts */
    status = FSDMMC_READ_REG(base_addr, FSDMMC_BD_ISR_REG_OFFSET);

    if (status & FSDMMC_BD_ISR_REG_DAIS) /* DMA  */
    {
        FSdmmcCallEvtHandler(instance_p->evt_handler[FSDMMC_EVT_DATA_ERROR], instance_p);
    }

    if (status & FSDMMC_BD_ISR_REG_RESPE) /*  SD AXI BR  */
    {
        FSdmmcCallEvtHandler(instance_p->evt_handler[FSDMMC_EVT_DATA_READ_DONE], instance_p);
    }

    if (status & FSDMMC_BD_ISR_REG_DATFRAX) /* AXI */
    {
        FSDMMC_ERROR("FSDMMC_BD_ISR_REG_DATFRAX");
    }

    if (status & FSDMMC_BD_ISR_REG_NRCRC) /*  CRC */
    {
        FSDMMC_ERROR("FSDMMC_BD_ISR_REG_NRCRC");
    }

    if (status & FSDMMC_BD_ISR_REG_TRE) /* CRC */
    {
        FSDMMC_ERROR("FSDMMC_BD_ISR_REG_TRE");
    }

    if (status & FSDMMC_BD_ISR_REG_CMDE) /* */
    {
        FSDMMC_ERROR("FSDMMC_BD_ISR_REG_CMDE");
    }

    if (status & FSDMMC_BD_ISR_REG_DTE) /* */
    {
        FSDMMC_ERROR("FSDMMC_BD_ISR_REG_DTE");
    }

    if (status & FSDMMC_BD_ISR_REG_TRS) /* DMA */
    {
        FSdmmcCallEvtHandler(instance_p->evt_handler[FSDMMC_EVT_DATA_WRITE_DONE], instance_p);
    }

    FSdmmcClearBDInterruptStatus(base_addr);
}

/**
 * @name: FSdmmcErrInterrupHandler
 * @msg: 
 * @return {*}
 * @param {s32} vector 
 * @param {void} *param 
 * @note FSDMMC
 */
void FSdmmcErrInterrupHandler(s32 vector, void *param)
{
    FASSERT(param);
    u32 status;
    FSdmmc *instance_p = (FSdmmc *)param;
    uintptr base_addr = instance_p->config.base_addr;

    status = FSDMMC_READ_REG(base_addr, FSDMMC_ERROR_INT_STATUS_REG_OFFSET);

    if (status & FSDMMC_ERROR_INT_STATUS_CNR) /*  */
    {
        FSdmmcCallEvtHandler(instance_p->evt_handler[FSDMMC_EVT_CMD_RESP_ERROR], instance_p);
    }

    if (status & FSDMMC_ERROR_INT_STATUS_CIR) /*  */
    {
        FSDMMC_ERROR("FSDMMC_ERROR_INT_STATUS_CIR");
    }

    if (status & FSDMMC_ERROR_INT_STATUS_CCRCE) /*  CRC  */
    {
        FSDMMC_ERROR("FSDMMC_ERROR_INT_STATUS_CCRCE");
    }

    if (status & FSDMMC_ERROR_INT_STATUS_CTE) /*  */
    {
        FSDMMC_ERROR("FSDMMC_ERROR_INT_STATUS_CTE");
    }

    /* clear command error status */
    FSdmmcClearErrorInterruptStatus(base_addr);
}

/**
 * @name: FSdmmcRegisterInterruptHandler
 * @msg: 
 * @return {*}
 * @param {FSdmmc} *instance_p FSDMMC
 * @param {u32} event FSDMMCFSDMMC_EVT_NUM
 * @param {FSdmmcEventHandler} handler, FSDMMC
 * @note FSDMMCFSdmmcCmdInterrupHandlerFSdmmcErrInterrupHandler
 * FSdmmcDmaInterrupHandler
 */
void FSdmmcRegisterInterruptHandler(FSdmmc *instance_p, u32 event, FSdmmcEventHandler handler)
{
    FASSERT(instance_p);
    instance_p->evt_handler[event] = handler;
}

/**
 * @name: FSdmmcInterruptTransfer
 * @msg: FSDMMC/
 * @return {FError} FSDMMC_SUCCESS //
 * @param {FSdmmc} *instance_p FSDMMC
 * @param {FSdmmcCmd} *cmd_data_p FSDMMC
 * @note FSDMMCFSDMMC
 */
FError FSdmmcInterruptTransfer(FSdmmc *instance_p, FSdmmcCmd *cmd_data_p)
{
    FASSERT(instance_p && cmd_data_p);
    uintptr base_addr = instance_p->config.base_addr;
    FError ret = FSDMMC_SUCCESS;

    if (FALSE == FSdmmcCheckIfCardExists(base_addr))
    {
        FSDMMC_ERROR("card not found !!! fsdio ctrl base 0x%x", base_addr);
        return FSDMMC_ERR_CARD_NO_FOUND;
    }

    if (cmd_data_p->flag & FSDMMC_CMD_FLAG_EXP_DATA)
    {
        /* transfer data */
        FSDMMC_INFO("====DATA [%d] START: buf: %p=====", cmd_data_p->cmdidx, cmd_data_p->data_p);
        ret = FSdmmcSendData(base_addr,
                             (FSDMMC_CMD_FLAG_READ_DATA == (cmd_data_p->flag & FSDMMC_CMD_FLAG_READ_DATA)),
                             cmd_data_p);
    }
    else
    {
        /* transfer command */
        FSDMMC_INFO("=====CMD [%d] START=====", cmd_data_p->cmdidx);
        FSdmmcSendCmd(base_addr, cmd_data_p);
    }

    return ret;
}