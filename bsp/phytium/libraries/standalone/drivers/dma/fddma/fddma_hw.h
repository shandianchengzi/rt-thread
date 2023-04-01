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
 * FilePath: fddma_hw.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:24:52
 * Description: This files is for register definition
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   Zhugengyu  2022/5/13    init commit
 */

#ifndef  DRIVERS_FDDMA_HW_H
#define  DRIVERS_FDDMA_HW_H

#ifdef __cplusplus
extern "C"
{
#endif
/***************************** Include Files *********************************/

#include "fassert.h"
#include "ftypes.h"
#include "fio.h"
#include "fkernel.h"

/************************** Constant Definitions *****************************/
/** @name Register Map
 *
 * Register offsets from the base address of an GPIO device.
 * @{
 */
#define FDDMA_CTL_OFFSET                        0x0 /*  */
#define FDDMA_CHAN_0_3_CFG_OFFSET               0x4 /* DMA0~3 */
#define FDDMA_STA_OFFSET                        0x8 /*  */
#define FDDMA_MASK_INTR_OFFSET                  0xC /*  */
/* AXI */
#define FDDMA_UP_AXI_AW_CFG_OFFSET              0x10 /* AXI */
#define FDDMA_UP_AXI_AR_CFG_OFFSET              0x14 /* AXI */
#define FDDMA_DOWN_AXI_AW_CFG_OFFSET            0x18 /* AXI */
#define FDDMA_DOWN_AXI_AR_CFG_OFFSET            0x1C /* AXI */

#define FDDMA_CHAN_BIND_OFFSET                  0x20 /* DMA */
#define FDDMA_GCAP_OFFSET                       0x24 /* DMA */
#define FDDMA_CHAN_4_7_CFG_OFFSET               0x28 /* DMA4~7 */

#define FDDMA_CHAN_OFFSET(chan)                 (0x40 * (chan))
#define FDDMA_CHAN_DDR_UP_ADDR_OFFSET(chan)     (0x40 + FDDMA_CHAN_OFFSET(chan)) /* /32 */
#define FDDMA_CHAN_DDR_LOW_ADDR_OFFSET(chan)    (0x44 + FDDMA_CHAN_OFFSET(chan)) /* /32 */
#define FDDMA_CHAN_DEV_ADDR_OFFSET(chan)        (0x48 + FDDMA_CHAN_OFFSET(chan)) /* /32 */
#define FDDMA_CHAN_TS_OFFSET(chan)              (0x4C + FDDMA_CHAN_OFFSET(chan)) /*  */
#define FDDMA_CHAN_CRT_UP_ADDR_OFFSET(chan)     (0x50 + FDDMA_CHAN_OFFSET(chan)) /* 32 */
#define FDDMA_CHAN_CRT_LOW_ADDR_OFFSET(chan)    (0x54 + FDDMA_CHAN_OFFSET(chan)) /* 32 */
#define FDDMA_CHAN_CTL_OFFSET(chan)             (0x58 + FDDMA_CHAN_OFFSET(chan)) /*  */
#define FDDMA_CHAN_STS_OFFSET(chan)             (0x5C + FDDMA_CHAN_OFFSET(chan)) /*  */
#define FDDMA_CHAN_TIMEOUT_CNT_OFFSET(chan)     (0x60 + FDDMA_CHAN_OFFSET(chan)) /*  */

/** @name FDDMA_CTL_OFFSET Register
 */
#define FDDMA_CTL_SRST                          BIT(1) /* 1:  */
#define FDDMA_CTL_ENABLE                        BIT(0) /* 1:  */

/** @name FDDMA_CHAN_0_3_CFG_OFFSET Register
 */
#define FDDMA_CHAN_0_3_SEL_EN(chan)             BIT((chan) * 8 + 7)      /* 1: chan */
#define FDDMA_CHAN_0_3_SEL(chan, sel)           ((sel) <<  ((chan) * 8)) /* chansel */
#define FDDMA_CHAN_0_3_SEL_MASK(chan)           (GENMASK(7, 0) << ((chan) * 8))

/** @name FDDMA_STA_OFFSET Register
 */
#define FDDMA_STA_CHAN_REQ_DONE(chan)           BIT((chan) * 4) /* chanblock110 */

/** @name FDDMA_MASK_INTR_OFFSET Register
 */
#define FDDMA_MASK_EN_GLOBAL_INTR               BIT(31)   /*  */
#define FDDMA_MASK_EN_CHAN_INTR(chan)           BIT(chan) /* chan */

/** @name FDDMA_CHAN_BIND_OFFSET Register
 */
#define FDDMA_CHAN_BIND(chan)                   BIT(chan) /* 1: DMA */

/** @name FDDMA_CHAN_4_7_CFG_OFFSET Register
 */
#define FDDMA_CHAN_4_7_SEL_EN(chan)             BIT(((chan) - 4) * 8 + 7) /* 1: chan */
#define FDDMA_CHAN_4_7_SEL(chan, sel)           ((sel) <<  (((chan) - 4) * 8)) /* chansel */
#define FDDMA_CHAN_4_7_SEL_MASK(chan)           (GENMASK(7, 0) << (((chan) - 4) * 8))

/** @name FDDMA_CHAN_CTL_OFFSET Register
 */
#define FDDMA_CHAN_CTL_RX_MODE                  BIT(2)  /* 1 dma_rx_req, 0 dma_tx_req */
#define FDDMA_CHAN_CTL_SRST                     BIT(1)  /* 1:  */
#define FDDMA_CHAN_CTL_EN                       BIT(0)  /* 1:  */

/** @name FDDMA_CHAN_STS_OFFSET Register
 */
#define FDDMA_CHAN_STS_FIFO_EMPTY               BIT(1)  /* 1: FIFO */
#define FDDMA_CHAN_STS_FIFO_FULL                BIT(0)  /* 1: FIFO */

/** @name FDDMA_CHAN_TIMEOUT_CNT_OFFSET Register
 */
#define FDDMA_CHAN_TIMEOUT_EN                   BIT(32)  /* 1:  */
#define FDDMA_CHAN_TIMEOUT_CNT_SET(cnt)         SET_REG32_BITS((cnt), 27, 0)  /*  */
#define FDDMA_CHAN_TIMEOUT_CNT_MASK             GENMASK(27, 0)
/**************************** Type Definitions *******************************/

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
/**
 * @name: FDdmaReadReg
 * @msg: DDMA
 * @return {u32} 
 * @param {uintptr} base_addr, DDMA
 * @param {u32} reg_off, DDMA
 */
static inline u32 FDdmaReadReg(uintptr base_addr, u32 reg_off)
{
    return FtIn32(base_addr + reg_off);
}

/**
 * @name: FDdmaWriteReg
 * @msg: DDMA
 * @return {}
 * @param {uintptr} base_addr, DDMA
 * @param {u32} reg_off, DDMA
 * @param {u32} reg_val, 
 */
static inline void FDdmaWriteReg(uintptr base_addr, u32 reg_off, u32 reg_val)
{
    FtOut32(base_addr + reg_off, reg_val);
    return;
}

/**
 * @name: FDdmaReadStatus
 * @msg: DDMA
 * @return {u32} 
 * @param {uintptr} base_addr, DDMA
 */
static inline u32 FDdmaReadStatus(uintptr base_addr)
{
    return FDdmaReadReg(base_addr, FDDMA_STA_OFFSET);
}

/**
 * @name: FDdmaReadChanStatus
 * @msg: DDMA
 * @return {u32} 
 * @param {uintptr} base_addr, DDMA
 * @param {u32} chan, DDMA
 */
static inline u32 FDdmaReadChanStatus(uintptr base_addr, u32 chan)
{
    return FDdmaReadReg(base_addr, FDDMA_CHAN_STS_OFFSET(chan));
}

/************************** Function Prototypes ******************************/
/* DDMA */
void FDdmaSoftwareReset(uintptr base_addr);

/* DDMA */
void FDdmaDisable(uintptr base_addr);

/* DDMA */
void FDdmaEnable(uintptr base_addr);

/* DDMA */
void FDdmaResetChan(uintptr base_addr, u32 chan);

/* DDMA */
FError FDdmaDisableChan(uintptr base_addr, u32 chan);

/* DDMA */
void FDdmaEnableChan(uintptr base_addr, u32 chan);

/* DDMA */
void FDdmaDisableGlobalIrq(uintptr base_addr);

/* DDMA */
void FDdmaEnableGlobalIrq(uintptr base_addr);

/* DDMA */
void FDdmaDisableChanIrq(uintptr base_addr, u32 chan);

/* DDMA */
void FDdmaEnableChanIrq(uintptr base_addr, u32 chan);

/* DDMA */
void FDdmaClearChanIrq(uintptr base_addr, u32 chan);

/*  */
boolean FDdmaIsChanRunning(uintptr base_addr, u32 chan);

/* DDMA */
void FDdmaSetChanSelection(uintptr base_addr, u32 chan, u32 slave_id);

/*  */
void FDdmaSetChanBind(uintptr base_addr, u32 chan, boolean bind);

/*  */
void FDdmaSetChanDirection(uintptr base_addr, u32 chan, boolean is_rx);

/*  */
void FDdmaSetChanTimeout(uintptr base_addr, u32 chan, u32 timeout);

#ifdef __cplusplus
}
#endif

#endif