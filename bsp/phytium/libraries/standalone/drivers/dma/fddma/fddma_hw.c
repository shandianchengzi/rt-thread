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
 * FilePath: fddma_hw.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:24:47
 * Description: This files is for ddma register rw operations
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   Zhugengyu  2022/5/13    init commit
 */

/***************************** Include Files *********************************/
#include <string.h>

#include "fkernel.h"
#include "fparameters.h"
#include "fassert.h"
#include "fdebug.h"

#include "fddma_hw.h"
#include "fddma.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define FDDMA_DEBUG_TAG "DDMA-HW"
#define FDDMA_ERROR(format, ...)   FT_DEBUG_PRINT_E(FDDMA_DEBUG_TAG, format, ##__VA_ARGS__)
#define FDDMA_WARN(format, ...)   FT_DEBUG_PRINT_W(FDDMA_DEBUG_TAG, format, ##__VA_ARGS__)
#define FDDMA_INFO(format, ...)    FT_DEBUG_PRINT_I(FDDMA_DEBUG_TAG, format, ##__VA_ARGS__)
#define FDDMA_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FDDMA_DEBUG_TAG, format, ##__VA_ARGS__)

/************************** Function Prototypes ******************************/

/****************************************************************************/
/**
 * @name: FDdmaDisable
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 */
void FDdmaDisable(uintptr base_addr)
{
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_CTL_OFFSET);
    reg_val &= ~FDDMA_CTL_ENABLE;
    FDdmaWriteReg(base_addr, FDDMA_CTL_OFFSET, reg_val);
    FDDMA_DEBUG("ddma @%p disabled : 0x%x", base_addr, FDdmaReadReg(base_addr, FDDMA_CTL_OFFSET));
    return;
}

/**
 * @name: FDdmaEnable
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 */
void FDdmaEnable(uintptr base_addr)
{
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_CTL_OFFSET);
    reg_val |= FDDMA_CTL_ENABLE;
    FDdmaWriteReg(base_addr, FDDMA_CTL_OFFSET, reg_val);
    FDDMA_DEBUG("ddma @%p enabled : 0x%x", base_addr, FDdmaReadReg(base_addr, FDDMA_CTL_OFFSET));
    return;
}

/**
 * @name: FDdmaSoftwareReset
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 */
void FDdmaSoftwareReset(uintptr base_addr)
{
    int delay = 10000;
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_CTL_OFFSET);
    reg_val |= FDDMA_CTL_SRST;
    FDdmaWriteReg(base_addr, FDDMA_CTL_OFFSET, reg_val);
    FDDMA_DEBUG("ddma @%p software reset start : 0x%x", base_addr, FDdmaReadReg(base_addr, FDDMA_CTL_OFFSET));

    while (--delay > 0) /* wait a while to do reset */
        ;

    reg_val &= ~FDDMA_CTL_SRST;
    FDdmaWriteReg(base_addr, FDDMA_CTL_OFFSET, reg_val); /* exit from software reset */
    FDDMA_DEBUG("ddma @%p software reset end : 0x%x", base_addr, FDdmaReadReg(base_addr, FDDMA_CTL_OFFSET));
    return;
}

/**
 * @name: FDdmaDisableGlobalIrq
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 */
void FDdmaDisableGlobalIrq(uintptr base_addr)
{
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_MASK_INTR_OFFSET);
    reg_val |= FDDMA_MASK_EN_GLOBAL_INTR; /* write 1 and disable interrupt */
    FDdmaWriteReg(base_addr, FDDMA_MASK_INTR_OFFSET, reg_val);
    return;
}

/**
 * @name: FDdmaEnableGlobalIrq
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 */
void FDdmaEnableGlobalIrq(uintptr base_addr)
{
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_MASK_INTR_OFFSET);
    reg_val &= ~FDDMA_MASK_EN_GLOBAL_INTR; /* write 0 and enable interrupt */
    FDdmaWriteReg(base_addr, FDDMA_MASK_INTR_OFFSET, reg_val);
    return;
}

/**
 * @name: FDdmaDisableChanIrq
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 */
void FDdmaDisableChanIrq(uintptr base_addr, u32 chan)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_MASK_INTR_OFFSET);
    reg_val |= FDDMA_MASK_EN_CHAN_INTR(chan);
    FDdmaWriteReg(base_addr, FDDMA_MASK_INTR_OFFSET, reg_val);
    return;
}

/**
 * @name: FDdmaEnableChanIrq
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 */
void FDdmaEnableChanIrq(uintptr base_addr, u32 chan)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    u32 reg_val  = FDdmaReadReg(base_addr, FDDMA_MASK_INTR_OFFSET);
    reg_val &= ~FDDMA_MASK_EN_CHAN_INTR(chan); /* write 0 and enable  */
    FDdmaWriteReg(base_addr, FDDMA_MASK_INTR_OFFSET, reg_val);
    return;
}

/**
 * @name: FDdmaDisableChan
 * @msg: DDMA
 * @return {FError} FDDMA_SUCCESS 
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 */
FError FDdmaDisableChan(uintptr base_addr, u32 chan)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    int delay = 1000;
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan));
    reg_val &= ~FDDMA_CHAN_CTL_EN;
    FDdmaWriteReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan), reg_val);

    /*  1b0 1b0  */
    do
    {
        reg_val = FDdmaReadReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan));
        if (delay-- <= 0)
            break;
    }
    while (reg_val & FDDMA_CHAN_CTL_EN);

    FDDMA_DEBUG("ddma @%p chan %d disabled : 0x%x", base_addr, chan, FDdmaReadReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan)));
    return (delay > 0) ? FDDMA_SUCCESS : FDDMA_ERR_WAIT_TIMEOUT;
}

/**
 * @name: FDdmaEnableChan
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 */
void FDdmaEnableChan(uintptr base_addr, u32 chan)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan));
    reg_val |= FDDMA_CHAN_CTL_EN;
    FDdmaWriteReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan), reg_val);
    FDDMA_DEBUG("ddma @%p chan %d enabled : 0x%x", base_addr, chan, FDdmaReadReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan)));
    return;
}

/**
 * @name: FDdmaClearChanIrq
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 */
void FDdmaClearChanIrq(uintptr base_addr, u32 chan)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    /* write 1 to clear irq status of channel */
    FDdmaWriteReg(base_addr, FDDMA_STA_OFFSET, FDDMA_STA_CHAN_REQ_DONE(chan));
}

/**
 * @name: FDdmaResetChan
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 */
void FDdmaResetChan(uintptr base_addr, u32 chan)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    int delay = 1000;
    u32 reg_val;

    if (FDdmaIsChanRunning(base_addr, chan)) /* disable channel if running */
        (void)FDdmaDisableChan(base_addr, chan);

    reg_val  = FDdmaReadReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan));
    reg_val |= FDDMA_CHAN_CTL_SRST;
    FDdmaWriteReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan), reg_val);

    while (--delay > 0) /* wait a while to do reset */
        ;

    reg_val &= ~FDDMA_CHAN_CTL_SRST;
    FDdmaWriteReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan), reg_val);
    FDDMA_DEBUG("chan reset done, ctrl: 0x%x", FDdmaReadReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan)));
    return;
}

/**
 * @name: FDdmaIsChanRunning
 * @msg: 
 * @return {boolean} TRUE: 
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 */
boolean FDdmaIsChanRunning(uintptr base_addr, u32 chan)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan));
    return (FDDMA_CHAN_CTL_EN & reg_val) ? TRUE : FALSE;
}

/**
 * @name: FDdmaSetChanSelection
 * @msg: DDMA
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 * @param {u32} slave_id, slave id
 */
void FDdmaSetChanSelection(uintptr base_addr, u32 chan, u32 slave_id)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    FASSERT_MSG((FDDMA_MAX_SLAVE_ID >= slave_id), "invalid slave id %d", slave_id);
    u32 reg_val;

    if (FDDMA_CHAN_4 > chan)
    {
        reg_val = FDdmaReadReg(base_addr, FDDMA_CHAN_0_3_CFG_OFFSET);
        reg_val &= ~FDDMA_CHAN_0_3_SEL_MASK(chan);
        reg_val |= FDDMA_CHAN_0_3_SEL(chan, slave_id);
        reg_val |= FDDMA_CHAN_0_3_SEL_EN(chan);
        FDdmaWriteReg(base_addr, FDDMA_CHAN_0_3_CFG_OFFSET, reg_val);
        FDDMA_DEBUG("ddma@%p set chan-%d slave id-%d, 0x%x", base_addr, chan, slave_id, FDdmaReadReg(base_addr, FDDMA_CHAN_0_3_CFG_OFFSET));
    }
    else
    {
        reg_val = FDdmaReadReg(base_addr, FDDMA_CHAN_4_7_CFG_OFFSET);
        reg_val &= ~FDDMA_CHAN_4_7_SEL_MASK(chan);
        reg_val |= FDDMA_CHAN_4_7_SEL(chan, slave_id);
        reg_val |= FDDMA_CHAN_4_7_SEL_EN(chan);
        FDdmaWriteReg(base_addr, FDDMA_CHAN_4_7_CFG_OFFSET, reg_val);
        FDDMA_DEBUG("ddma@%p set chan-%d slave id-%d, 0x%x", base_addr, chan, slave_id, FDdmaReadReg(base_addr, FDDMA_CHAN_4_7_CFG_OFFSET));
    }

    return;
}

/**
 * @name: FDdmaSetChanBind
 * @msg: 
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 * @param {boolean} bind, TRUE: FALSE: 
 */
void FDdmaSetChanBind(uintptr base_addr, u32 chan, boolean bind)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_CHAN_BIND_OFFSET);

    if (bind)
        reg_val |= BIT(chan);
    else
        reg_val &= ~BIT(chan);

    FDDMA_DEBUG("ddma@%p %s chan-%d, 0x%x", base_addr, bind ? "bind" : "unbind", chan, FDdmaReadReg(base_addr, FDDMA_CHAN_BIND_OFFSET));
    FDdmaWriteReg(base_addr, FDDMA_CHAN_BIND_OFFSET, reg_val);
    return;
}

/**
 * @name: FDdmaSetChanDirection
 * @msg: 
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 * @param {boolean} is_rx, TRUE: , FALSE: 
 */
void FDdmaSetChanDirection(uintptr base_addr, u32 chan, boolean is_rx)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan));
    if (is_rx)
        reg_val |= FDDMA_CHAN_CTL_RX_MODE; /* device to memory */
    else
        reg_val &= ~FDDMA_CHAN_CTL_RX_MODE; /* memory to device */
    FDdmaWriteReg(base_addr, FDDMA_CHAN_CTL_OFFSET(chan), reg_val);
    return;
}

/**
 * @name: FDdmaSetChanTimeout
 * @msg: 
 * @return {*}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 * @param {u32} timeout, 0
 */
void FDdmaSetChanTimeout(uintptr base_addr, u32 chan, u32 timeout)
{
    FASSERT_MSG((FDDMA_NUM_OF_CHAN > chan), "chan %d not support", chan);
    u32 reg_val = FDdmaReadReg(base_addr, FDDMA_CHAN_TIMEOUT_CNT_OFFSET(chan));

    if (0 < timeout)
    {
        reg_val &= ~FDDMA_CHAN_TIMEOUT_CNT_MASK;
        reg_val |= FDDMA_CHAN_TIMEOUT_CNT_SET(timeout);
        reg_val |= FDDMA_CHAN_TIMEOUT_EN;
    }
    else
    {
        reg_val &= ~FDDMA_CHAN_TIMEOUT_EN;
    }

    FDdmaWriteReg(base_addr, FDDMA_CHAN_TIMEOUT_CNT_OFFSET(chan), reg_val);
    return;
}