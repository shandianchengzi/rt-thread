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
 * FilePath: fgdma_hw.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:24:52
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   huanghe    2021-11-5    init commit
 * 1.1   zhugengyu  2022-5-16    modify according to tech manual.
 */

#ifndef DRIVERS_FGDMA_HW_H
#define DRIVERS_FGDMA_HW_H

#ifdef __cplusplus
extern "C"
{
#endif
/***************************** Include Files *********************************/

#include "fparameters.h"
#include "fio.h"
#include "fkernel.h"

/************************** Constant Definitions *****************************/

/** @name Register Map
 *
 * Register offsets from the base address of an GDMA device.
 * @{
 */
#define FGDMA_CTL_OFFSET            0x0U    /*  */
#define FGDMA_INTR_STATE_OFFSET     0x4U    /*  */
#define FGDMA_INTR_CTRL_OFFSET      0x8U    /*  */
#define FGDMA_LP_OFFSET             0xCU    /*  */
#define FGDMA_QOS_CFG_OFFSET        0x10U   /*  QoS  */

/* Channel register */
#define FGDMA_CHX_OFFSET(x)             ((x) * 0x60U)
#define FGDMA_CHX_CTL_OFFSET(x)         (0x20 + FGDMA_CHX_OFFSET(x)) /*  */
#define FGDMA_CHX_MODE_OFFSET(x)        (0x24 + FGDMA_CHX_OFFSET(x)) /*  */
#define FGDMA_CHX_INT_CTRL_OFFSET(x)    (0x28 + FGDMA_CHX_OFFSET(x)) /*  */
#define FGDMA_CHX_INT_STATE_OFFSET(x)   (0x2C + FGDMA_CHX_OFFSET(x)) /*  */
#define FGDMA_CHX_LVI_OFFSET(x)         (0x30 + FGDMA_CHX_OFFSET(x)) /*  BDL  */
#define FGDMA_CHX_TS_OFFSET(x)          (0x34 + FGDMA_CHX_OFFSET(x)) /*  Byte  */
#define FGDMA_CHX_UPSADDR_OFFSET(x)     (0x38 + FGDMA_CHX_OFFSET(x)) /* (32) */
#define FGDMA_CHX_LWSADDR_OFFSET(x)     (0x3C + FGDMA_CHX_OFFSET(x)) /* (32) */
#define FGDMA_CHX_UPDADDR_OFFSET(x)     (0x40 + FGDMA_CHX_OFFSET(x)) /* (32) */
#define FGDMA_CHX_LWDADDR_OFFSET(x)     (0x44 + FGDMA_CHX_OFFSET(x)) /* (32) */
#define FGDMA_CHX_XFER_CFG_OFFSET(x)    (0x48 + FGDMA_CHX_OFFSET(x)) /*  Burst  */
#define FGDMA_CHX_LCP_OFFSET(x)         (0x4C + FGDMA_CHX_OFFSET(x)) /*  BDL  */
#define FGDMA_CHX_SECCTL_OFFSET(x)      (0x50 + FGDMA_CHX_OFFSET(x)) /*  */
#define FGDMA_CHX_SEC_ATST_OFFSET(x)    (0x54 + FGDMA_CHX_OFFSET(x)) /* Secssid  Atst */
#define FGDMA_CHX_NSID_STRMID_OFFSET(x) (0x58 + FGDMA_CHX_OFFSET(x)) /* NSAID  StreamID  */
#define FGDMA_CHX_AW_CFG_OFFSET(x)      (0x5C + FGDMA_CHX_OFFSET(x)) /*  AXI AW  */
#define FGDMA_CHX_AR_CFG_OFFSET(x)      (0x60 + FGDMA_CHX_OFFSET(x)) /*  AXI AR  */
#define FGDMA_CHX_SECRSP_OFFSET(x)      (0x64 + FGDMA_CHX_OFFSET(x)) /*  Response  */

/** @name FGDMA_CTL_OFFSET Register
 */
#define FGDMA_CTL_OT_MASK               GENMASK(11, 8)
#define FGDMA_CTL_OT_SET(ot)            SET_REG32_BITS(ot, 11, 8) /* dma outstanding +1 */
#define FGDMA_CTL_RD_ARB                BIT(5) /* dma : 01Qos */
#define FGDMA_CTL_WR_ARB                BIT(4) /* dma : 01Qos */
#define FGDMA_CTL_SOFT_RESET            BIT(1) /* dma 10 */
#define FGDMA_CTL_ENABLE                BIT(0) /* dma 10disable */

/** @name FGDMA_INTR_STATE_OFFSET Register
 */
#define FGDMA_CHX_INTR_STATE(x)         BIT(x) /* channel-x  */

/** @name FGDMA_INTR_CTRL_OFFSET Register
 */
#define FGDMA_CHX_INTR_MASK(x)          BIT(x)  /* channel-x 1 0  */
#define FGDMA_CHX_INTR_GLOBAL_MASK      BIT(31) /*  mask 10  */

/** @name FGDMA_LP_OFFSET Register
 */
#define FGDMA_CHX_LP_CTL(x)             BIT(x)  /* channel-x 1  */

/** @name FGDMA_QOS_CFG_OFFSET Register
 */
#define FGDMA_QOS_CFG_ARGOS_MASK        GENMASK(7, 4)
#define FGDMA_QOS_CFG_ARGOS_SET(qos)    SET_REG32_BITS((qos), 7, 4) /*  QoS  */
#define FGDMA_QOS_CFG_AWQOS_MASK        GENMASK(3, 0)
#define FGDMA_QOS_CFG_AWQOS_SET(qos)    SET_REG32_BITS((qos), 3, 0) /*  QoS  */

/** @name FGDMA_CHX_CTL_OFFSET Register
 */
#define FGDMA_CHX_CTL_SOFT_RESET        BIT(4) /* 1  0  */
#define FGDMA_CHX_CTL_ENABLE            BIT(0) /* 1 0  */

/** @name FGDMA_CHX_MODE_OFFSET Register
 */
#define FGDMA_CHX_MODE_RD_QOS_MASK          GENMASK(23, 20)
#define FGDMA_CHX_MODE_RD_QOS_SET(qos)      SET_REG32_BITS((qos), 23, 20) /* CHX  Qos  */
#define FGDMA_CHX_MODE_RD_QOS_GET(qos)      GET_REG32_BITS((qos), 23, 20)
/*  cd_rd_qos  QoSS1 , 0  */
#define FGDMA_CHX_MODE_RD_QOS_EN            BIT(16)

#define FGDMA_CHX_MODE_WR_QOS_MASK          GENMASK(15, 12)
#define FGDMA_CHX_MODE_WR_QOS_SET(qos)      SET_REG32_BITS((qos), 15, 12) /* CHX  Qos  */
#define FGDMA_CHX_MODE_WR_QOS_GET(qos)      GET_REG32_BITS((qos), 15, 12)
/*  cx_wr_qos  QoS1 , 0  */
#define FGDMA_CHX_MODE_WR_QOS_EN            BIT(8)

/* CHX qos cfg  Qos1  0  */
#define FGDMA_CHX_MODE_BDL_ROLL_EN          BIT(4)
#define FGDMA_CHX_MODE_BDL_EN               BIT(0)  /* direct BDL , 0 Direct , 1 BDL  */

/** @name FGDMA_CHX_INT_CTRL_OFFSET Register
 */
#define FGDMA_CHX_INT_CTRL_TRANS_END_ENABLE     BIT(3)  /* CHX 10 */
#define FGDMA_CHX_INT_CTRL_BDL_END_ENABLE       BIT(2)  /* CHX bdl 10  */
#define FGDMA_CHX_INT_CTRL_FIFO_FULL_ENABLE     BIT(1)  /* CHX ARM 10 */
#define FGDMA_CHX_INT_CTRL_FIFO_EMPTY_ENABLE    BIT(0)  /* CHX ARM 10 */

/** @name FGDMA_CHX_INT_STATE_OFFSET Register
 */
#define FGDMA_CHX_INT_STATE_BUSY                BIT(4)  /* CHX 1 0 */
#define FGDMA_CHX_INT_STATE_TRANS_END           BIT(3)  /* CHX direct BDL BDL 10 */
#define FGDMA_CHX_INT_STATE_BDL_END             BIT(2)  /* CHX BDLBDL Direct 0   10 */
#define FGDMA_CHX_INT_STATE_FIFO_FULL           BIT(1)  /* CHX FIFO 10 */
#define FGDMA_CHX_INT_STATE_FIFO_EMPTY          BIT(0)  /* CHX FIFO 10 */
#define FGDMA_CHX_INT_STATE_ALL                 GENMASK(4, 0)

/** @name FGDMA_CHX_LVI_OFFSET Register
 */
#define FGDMA_CHX_LVI_SET(lvi)        SET_REG32_BITS((lvi - 1), 31, 0) /* CHX last vaild index, BDL=+1 */

/** @name FGDMA_CHX_TS_OFFSET Register
 */
#define FGDMA_CHX_TS_SET(ts)          SET_REG32_BITS((ts), 31, 0) /* CHX direct Byte */

/** @name FGDMA_CHX_UPSADDR_OFFSET Register
 */
#define FGDMA_CHX_UPSADDR_SET(addr)   SET_REG32_BITS((addr), 31, 0) /* CHX 32bits */

/** @name FGDMA_CHX_LWSADDR_OFFSET Register
 */
#define FGDMA_CHX_LWSADDR_SET(addr)   SET_REG32_BITS((addr), 31, 0) /* CHX 32bits */

/** @name FGDMA_CHX_UPDADDR_OFFSET Register
 */
#define FGDMA_CHX_UPDADDR_SET(addr)   SET_REG32_BITS((addr), 31, 0) /* CHX 32bits */

/** @name FGDMA_CHX_LWDADDR_OFFSET Register
 */
#define FGDMA_CHX_LWDADDR_SET(addr)   SET_REG32_BITS((addr), 31, 0) /* CHX 32bits */

/** @name FGDMA_CHX_XFER_CFG_OFFSET Register
 */
#define FGDMA_CHX_XFER_CFG_AR_LEN_SET(len)      SET_REG32_BITS((len), 31, 24) /* CHX Burst length  */
#define FGDMA_CHX_XFER_CFG_AR_SIZE_SET(size)    SET_REG32_BITS((size), 22, 20) /* CHX Size    12816 Byte */
#define FGDMA_CHX_XFER_CFG_AR_BRUST_SET(type)   SET_REG32_BITS((type), 17, 16) /* CHX Brust  0fix 1incr */
#define FGDMA_CHX_XFER_CFG_AW_LEN_SET(len)      SET_REG32_BITS((len), 15, 8) /* CHX Burst length  */
#define FGDMA_CHX_XFER_CFG_AW_SIZE_SET(size)    SET_REG32_BITS((size), 6, 4) /* CHX Size    12816 Byte */
#define FGDMA_CHX_XFER_CFG_AW_BRUST_SET(type)   SET_REG32_BITS((type), 1, 0) /* CHX Brust  0fix 1incr */

#define FGDMA_INCR                      1U
#define FGDMA_FIX                       0U

#define FGDMA_MAX_BURST_LEN             8U

/** @name FGDMA_CHX_LCP_OFFSET Register
 */
#define FGDMA_CHX_LCP_GET(reg_val)   GET_REG32_BITS((reg_val), 31, 0) /*  BDL  */

/** @name FGDMA_CHX_SECCTL_OFFSET Register
 */
#define FGDMA_CHX_SECCTL_SET(val)    GET_REG32_BITS((val), 31, 0) /* CHX  */

/** @name FGDMA_CHX_SEC_ATST_OFFSET Register
 */
#define FGDMA_CHX_SEC_ATST_SET(val)  SET_REG32_BITS((val), 31, 0)

/** @name FGDMA_CHX_NSID_STRMID_OFFSET Register
 */
#define FGDMA_CHX_NSID_STRMID_SET(val)  SET_REG32_BITS((val), 31, 0)

/** @name FGDMA_CHX_AW_CFG_OFFSET Register
 */
#define FGDMA_CHX_AW_CFG_AWCACHE_SET(val)        SET_REG32_BITS((val), 3, 0)  /* CHX dma arcache */
#define FGDMA_CHX_AW_CFG_AWREGION_MASK_SET(val)  SET_REG32_BITS((val), 7, 4) /* CHX dma arregion */
#define FGDMA_CHX_AW_CFG_AWPROT_SET(val)         SET_REG32_BITS((val), 9, 8)
#define FGDMA_CHX_AW_CFG_AWDOMAIN_SET(val)       SET_REG32_BITS((val), 13, 12) /* chx ardomain */
#define FGDMA_CHX_AW_CFG_AWSNOOP_SET(val)        SET_REG32_BITS((val), 18, 16)
#define FGDMA_CHX_AW_CFG_AWBAR_SET(val)          SET_REG32_BITS((val), 21, 20)

/** @name FGDMA_CHX_AR_CFG_OFFSET Register
 */
#define FGDMA_CHX_AR_CFG_AWCACHE_SET(val)        SET_REG32_BITS((val), 3, 0)  /* CHX dma arcache */
#define FGDMA_CHX_AR_CFG_AWREGION_MASK_SET(val)  SET_REG32_BITS((val), 7, 4) /* CHX dma arregion */
#define FGDMA_CHX_AR_CFG_AWPROT_SET(val)         SET_REG32_BITS((val), 9, 8)
#define FGDMA_CHX_AR_CFG_AWDOMAIN_SET(val)       SET_REG32_BITS((val), 13, 12) /* chx ardomain */
#define FGDMA_CHX_AR_CFG_AWSNOOP_SET(val)        SET_REG32_BITS((val), 19, 16)
#define FGDMA_CHX_AR_CFG_AWBAR_SET(val)          SET_REG32_BITS((val), 21, 20)

/** @name FGDMA_CHX_SECRSP_OFFSET Register
 */
#define FGDMA_CHX_SECRSP                         BIT(0) /* response  */

#define FGDMA_OUTSTANDING                        0xfU  /* outstanding0xf + 1 */

/**************************** Type Definitions *******************************/

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define FGDMA_READREG(base_addr, reg_offset) \
    FtIn32((base_addr) + (u32)(reg_offset))

#define FGDMA_WRITEREG(base_addr, reg_offset, data) \
    FtOut32((base_addr) + (u32)(reg_offset), (u32)(data))

/**
 * @name: FGdmaDisable
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 */
static inline void FGdmaDisable(uintptr base_addr)
{
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_CTL_OFFSET);
    reg_val &= ~FGDMA_CTL_ENABLE;
    FGDMA_WRITEREG(base_addr, FGDMA_CTL_OFFSET, reg_val);
}

/**
 * @name: FGdmaEnable
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 */
static inline void FGdmaEnable(uintptr base_addr)
{
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_CTL_OFFSET);
    reg_val |= FGDMA_CTL_ENABLE;
    FGDMA_WRITEREG(base_addr, FGDMA_CTL_OFFSET, reg_val);
}

/**
 * @name: FGdmaSoftwareReset
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 */
static inline void FGdmaSoftwareReset(uintptr base_addr)
{
    int delay = 100;
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_CTL_OFFSET);
    reg_val |= FGDMA_CTL_SOFT_RESET;
    FGDMA_WRITEREG(base_addr, FGDMA_CTL_OFFSET, reg_val);

    while (--delay > 0)
        ;

    reg_val = FGDMA_READREG(base_addr, FGDMA_CTL_OFFSET);
    reg_val &= ~FGDMA_CTL_SOFT_RESET;
    FGDMA_WRITEREG(base_addr, FGDMA_CTL_OFFSET, reg_val);
}

/**
 * @name: FGdmaIrqEnable
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 */
static inline void FGdmaIrqEnable(uintptr base_addr)
{
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_INTR_CTRL_OFFSET);
    reg_val |= FGDMA_CHX_INTR_GLOBAL_MASK;
    FGDMA_WRITEREG(base_addr, FGDMA_INTR_CTRL_OFFSET, reg_val);
}

/**
 * @name: FGdmaIrqDisable
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 */
static inline void FGdmaIrqDisable(uintptr base_addr)
{
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_INTR_CTRL_OFFSET);
    reg_val &= ~FGDMA_CHX_INTR_GLOBAL_MASK;
    FGDMA_WRITEREG(base_addr, FGDMA_INTR_CTRL_OFFSET, reg_val);
}

/**
 * @name: FGdmaChanDisable
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 * @param {u32} chan, GDMA
 */
static inline void FGdmaChanDisable(uintptr base_addr, u32 chan)
{
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_CHX_CTL_OFFSET(chan));
    reg_val &= ~FGDMA_CHX_CTL_ENABLE; /*  */
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_CTL_OFFSET(chan), reg_val);
}

/**
 * @name: FGdmaChanEnable
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 * @param {u32} chan, GDMA
 */
static inline void FGdmaChanEnable(uintptr base_addr, u32 chan)
{
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_CHX_CTL_OFFSET(chan));
    reg_val |= FGDMA_CHX_CTL_ENABLE; /*  */
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_CTL_OFFSET(chan), reg_val);
}

/**
 * @name: FGdmaChanIrqDisable
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 * @param {u32} chan, GDMA
 */
static inline void FGdmaChanIrqDisable(uintptr base_addr, u32 chan)
{
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_INTR_CTRL_OFFSET);
    reg_val &= ~FGDMA_CHX_INTR_MASK(chan); /*  */
    FGDMA_WRITEREG(base_addr, FGDMA_INTR_CTRL_OFFSET, reg_val);
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_INT_CTRL_OFFSET(chan), 0x0U); /*  */
}

/**
 * @name: FGdmaChanIrqEnable
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 * @param {u32} chan, GDMA
 * @param {u32} umask, 
 */
static inline void FGdmaChanIrqEnable(uintptr base_addr, u32 chan, u32 umask)
{
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_INTR_CTRL_OFFSET);
    reg_val |= FGDMA_CHX_INTR_MASK(chan); /*  */
    FGDMA_WRITEREG(base_addr, FGDMA_INTR_CTRL_OFFSET, reg_val);
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_INT_CTRL_OFFSET(chan), umask); /*  */
}

/**
 * @name: FGdmaChanReset
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 * @param {u32} chan, GDMA
 */
static inline void FGdmaChanReset(uintptr base_addr, u32 chan)
{
    int delay = 100;
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_CHX_CTL_OFFSET(chan));
    reg_val |= FGDMA_CHX_CTL_SOFT_RESET;
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_CTL_OFFSET(chan), reg_val);

    while (--delay > 0)
        ;

    reg_val = FGDMA_READREG(base_addr, FGDMA_CHX_CTL_OFFSET(chan));
    reg_val &= ~FGDMA_CHX_CTL_SOFT_RESET;
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_CTL_OFFSET(chan), reg_val);
}

/**
 * @name: FGdmaReadStatus
 * @msg: GDMA
 * @return {u32} 
 * @param {uintptr} base_addr, GDMA
 */
static inline u32 FGdmaReadStatus(uintptr base_addr)
{
    return FGDMA_READREG(base_addr, FGDMA_INTR_STATE_OFFSET);
}

/**
 * @name: FGdmaReadChanStatus
 * @msg: GDMA
 * @return {u32} 
 * @param {uintptr} base_addr, GDMA
 * @param {u32} chan, 
 */
static inline u32 FGdmaReadChanStatus(uintptr base_addr, u32 chan)
{
    return FGDMA_READREG(base_addr, FGDMA_CHX_INT_STATE_OFFSET(chan));
}

/**
 * @name: FGdmaClearChanStatus
 * @msg: GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 * @param {u32} chan, 
 * @param {u32} status, 
 */
static inline void FGdmaClearChanStatus(uintptr base_addr, u32 chan, u32 status)
{
    FGDMA_WRITEREG(base_addr, FGDMA_CHX_INT_STATE_OFFSET(chan), status); /* 10 */
}

/**
 * @name: FGdmaSetChanClock
 * @msg: /GDMA
 * @return {void} 
 * @param {uintptr} base_addr, GDMA
 * @param {u32} chan, 
 * @param {boolean} enableTRUE: , FALSE: 
 */
static inline void FGdmaSetChanClock(uintptr base_addr, u32 chan, boolean enable)
{
    u32 reg_val = FGDMA_READREG(base_addr, FGDMA_LP_OFFSET);
    if (enable)
        reg_val &= ~FGDMA_CHX_LP_CTL(chan); /* 0 */
    else
        reg_val |= FGDMA_CHX_LP_CTL(chan); /* 1 */
    FGDMA_WRITEREG(base_addr, FGDMA_LP_OFFSET, reg_val);

    return;
}

/************************** Function Prototypes ******************************/


#ifdef __cplusplus
}
#endif

#endif