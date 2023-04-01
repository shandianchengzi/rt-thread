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
 * FilePath: fsdmmc_hw.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:54:24
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   zhugengyu  2021/12/2    init
 */

#ifndef  DRIVERS_MMC_FSDMMC_HW_H
#define  DRIVERS_MMC_FSDMMC_HW_H

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
 * Register offsets from the base address of an SD device.
 * @{
 */
#define FSDMMC_CONTROLL_SETTING_REG_OFFSET 0x00  /* Controller configuration register */
#define FSDMMC_ARGUMENT_REG_OFFSET 0x04          /* Parameter register */
#define FSDMMC_CMD_SETTING_REG_OFFSET 0x08       /* Command register */
#define FSDMMC_CLOCK_DIV_REG_OFFSET 0x0C         /* Clock division register */
#define FSDMMC_SOFTWARE_RESET_REG_OFFSET 0x10    /* Reset control register */
#define FSDMMC_POWER_CONTROLL_REG_OFFSET 0x14    /* Power control register */
#define FSDMMC_TIMEOUT_CMD_REG_OFFSET 0x18       /* Cmd Timeout setting register */
#define FSDMMC_TIMEOUT_DATA_REG_OFFSET 0x1C      /* Data timeout setting register */
#define FSDMMC_NORMAL_INT_EN_REG_OFFSET 0x20     /* Interrupt Enable Register */
#define FSDMMC_ERROR_INT_EN_REG_OFFSET 0x24      /* Error Interrupt Enable Register */
#define FSDMMC_BD_ISR_EN_REG_OFFSET 0x28         /* Data Transfer Interrupt Enable Register */
#define FSDMMC_CAPABILIES_REG_OFFSET 0x2c        /* capabilies register */
#define FSDMMC_SD_DRV_REG_OFFSET 0x30            /* SD card driver phase register */
#define FSDMMC_SD_SAMP_REG_OFFSET 0x34           /* SD card sampling phase register */
#define FSDMMC_SD_SEN_REG_OFFSET 0x38            /* Card detection controller */
#define FSDMMC_HDS_AXI_REG_CONF1_REG_OFFSET 0x3c /* AXI boundary configuration register 1 */
#define FSDMMC_DAT_IN_M_RX_BD_REG_OFFSET 0x40    /*  SD BD RX address register */
#define FSDMMC_DAT_IN_M_TX_BD_REG_OFFSET 0x60    /*  SD BD TX address register */
#define FSDMMC_BLK_CNT_REG_OFFSET 0x80           /*  Block reads and writes configuration registers */
#define FSDMMC_HDS_AXI_REG_CONF2_REG_OFFSET 0xa8 /*  AXI boundary configuration register 2 */
#define FSDMMC_NORMAL_INT_STATUS_REG_OFFSET 0xc0 /*  Interrupt status register */
#define FSDMMC_ERROR_INT_STATUS_REG_OFFSET 0xc4  /*  ERROR interrupt register */
#define FSDMMC_BD_ISR_REG_OFFSET  0xc8           /*  Data Transfer Interrupt Status Register */
#define FSDMMC_BD_STATUS_REG_OFFSET 0xcc         /*  BD descriptor register */
#define FSDMMC_STATUS_REG_OFFSET 0xd0            /*  Status register */
#define FSDMMC_BLOCK_REG_OFFSET 0xd4             /*  Block length register */
#define FSDMMC_CMD_RESP_1_REG_OFFSET 0xe0        /*  Command response register 1 */
#define FSDMMC_CMD_RESP_2_REG_OFFSET 0xe4        /*  Command response register 2 */
#define FSDMMC_CMD_RESP_3_REG_OFFSET 0xe8        /*  Command response register 3 */
#define FSDMMC_CMD_RESP_4_REG_OFFSET 0xec        /*  Command response register 4 */

/** @name FSDMMC_CONTROLL_SETTING_REG_OFFSET Register
 */
#define FSDMMC_PERMDW_MASK     GENMASK(11, 10)
#define FSDMMC_PERMDW(x)       (FSDMMC_PERMDW_MASK & ((x) << 10)) /*  */
#define FSDMMC_PERMDW_LIT_END  FSDMMC_PERMDW(0x0)
#define FSDMMC_PERMDW_BIG_END  FSDMMC_PERMDW(0x1)
#define FSDMMC_PERMDW_STD_END  FSDMMC_PERMDW(0x3)

#define FSDMMC_PERMDR_MASK     GENMASK(9, 8)
#define FSDMMC_PERMDR(x)       (FSDMMC_PERMDR_MASK & ((x) << 8)) /*  */
#define FSDMMC_PERMDR_LIT_END  FSDMMC_PERMDR(0x0)
#define FSDMMC_PERMDR_BIG_END  FSDMMC_PERMDR(0x1)
#define FSDMMC_PERMDR_STD_END  FSDMMC_PERMDR(0x3)

/** @name FSDMMC_ARGUMENT_REG_OFFSET Register
 */
#define FSDMMC_ARGUMENT_MASK  GENMASK(31, 0)

/** @name FSDMMC_CMD_SETTING_REG_OFFSET Register
 */
#define FSDMMC_CMD_RESP_MASK              GENMASK(1, 0)
#define FSDMMC_CMD_SETTING_RTS(x)         (FSDMMC_CMD_RESP_MASK & ((x) << 0))     /* 0: No response 01: Response byte length 136 10: Response byte length 48 11: Response byte length 48 */
#define FSDMMC_CMD_NO_RESP                FSDMMC_CMD_SETTING_RTS(0x0)  /* 00  */
#define FSDMMC_CMD_RESP_136_BIT           FSDMMC_CMD_SETTING_RTS(0x1)  /* 01 136 */
#define FSDMMC_CMD_RESP_48_BIT            FSDMMC_CMD_SETTING_RTS(0x2)  /* 10:  48 */
#define FSDMMC_CMD_RESP_48_BIT_BUSY_CHECK FSDMMC_CMD_SETTING_RTS(0x3) /* 11:  48, check busy after resp */

#define FSDMMC_CMD_SETTING_CRCE BIT(3)                             /* 0: CRC check is not performed on CMD response 1: CRC check is performed on CMD response */
#define FSDMMC_CMD_SETTING_CICE BIT(4)                             /* 0CMD  1CMD  */
#define FSDMMC_CMD_SETTING_CMDTP(x) (GENMASK(7, 6) & ((x) << 6))   /*  */
#define FSDMMC_CMD_SETTING_CMDI(x) (GENMASK(13, 8) & ((x) << 8))   /*  */
#define FSDMMC_CMD_SETTING_TRTY(x) (GENMASK(15, 14) & ((x) << 14)) /* 10 adtc  ,  */


/** @name FSDMMC_CLOCK_DIV_REG_OFFSET Register
 */
#define FSDMMC_CLK_DIVIDER(clk) (GENMASK(31, 0) & ((FSDMMC_CLK_FREQ_HZ / (2 * (clk))) - 1))

/** @name FSDMMC_SOFTWARE_RESET_REG_OFFSET Register
 */
#define FSDMMC_SOFTWARE_RESET_SRST  BIT(0)  /*  */
#define FSDMMC_SOFTWARE_RESET_BDRST BIT(2) /* DMA BD  0 */
#define FSDMMC_SOFTWARE_RESET_CFCLF BIT(3) /*  0 */

/** @name FSDMMC_TIMEOUT_CMD_REG_OFFSET Register
 */
#define FSDMMC_TIMEOUT_CMD_MASK    GENMASK(31, 0)

/** @name FSDMMC_TIMEOUT_DATA_REG_OFFSET Register
 */
#define FSDMMC_TIMEOUT_DATA_MASK   GENMASK(31, 0)

/** @name FSDMMC_NORMAL_INT_EN_REG_OFFSET Register
 */
#define FSDMMC_NORMAL_INT_EN_ECC    BIT(0)    /*  */
#define FSDMMC_NORMAL_INT_EN_ECCRCE BIT(1)    /*  */
#define FSDMMC_NORMAL_INT_EN_ECIE   BIT(15)   /*  */
#define FSDMCC_NORMAL_INT_ALL_BITS  (FSDMMC_NORMAL_INT_EN_ECC | FSDMMC_NORMAL_INT_EN_ECCRCE |\
                                     FSDMMC_NORMAL_INT_EN_ECIE)

/** @name FSDMMC_ERROR_INT_EN_REG_OFFSET Register
 */
#define FSDMMC_ERROR_INT_EN_CNR BIT(4)   /*  */
#define FSDMMC_ERROR_INT_EN_CIR BIT(3)   /*  */
#define FSDMMC_ERROR_INT_EN_CCRCE BIT(1) /*  CRC  */
#define FSDMMC_ERROR_INT_EN_CTE BIT(0)   /*  */
#define FSDMMC_ERROR_INT_ALL_BITS   (FSDMMC_ERROR_INT_EN_CNR | FSDMMC_ERROR_INT_EN_CIR |\
                                     FSDMMC_ERROR_INT_EN_CCRCE | FSDMMC_ERROR_INT_EN_CTE)

/** @name FSDMMC_BD_ISR_EN_REG_OFFSET Register
 */
#define FSDMMC_BD_ISR_EN_ETRS BIT(0)      /* DMA  */
#define FSDMMC_BD_ISR_EN_EDTE BIT(3)      /*  */
#define FSDMMC_BD_ISR_EN_ECMDE BIT(4)     /*  */
#define FSDMMC_BD_ISR_EN_ETRE BIT(5)      /*  */
#define FSDMMC_BD_ISR_EN_ENRCRCE BIT(6)   /* CRC  */
#define FSDMMC_BD_ISR_EN_EDATFRAXE BIT(7) /* AXI  */
#define FSDMMC_BD_ISR_EN_RESPE BIT(8)     /*  SD AXI BR  */
#define FSDMMC_BD_ISR_EN_EDAISE BIT(15)   /* DMA  */
#define FSDMMC_BD_ISR_ALL_BITS (FSDMMC_BD_ISR_EN_ETRS | FSDMMC_BD_ISR_EN_EDTE |         \
                                FSDMMC_BD_ISR_EN_ECMDE | FSDMMC_BD_ISR_EN_ETRE |        \
                                FSDMMC_BD_ISR_EN_ENRCRCE | FSDMMC_BD_ISR_EN_EDATFRAXE | \
                                FSDMMC_BD_ISR_EN_RESPE | FSDMMC_BD_ISR_EN_EDAISE)


/** @name FSDMMC_SD_DRV_REG_OFFSET Register
 */
#define FSDMMC_SD_DRV_MASK    GENMASK(31, 0) /*  */

/** @name FSDMMC_SD_SAMP_REG_OFFSET Register
 */
#define FSDMMC_SD_SAMP_MASK   GENMASK(31, 0) /*  */

/** @name FSDMMC_SD_SEN_REG_OFFSET Register
 */
#define FSDMMC_SD_SEN_REG_CREFR BIT(1)                          /*  AXI  */
#define FSDMMC_SD_SEN_REG_CRES BIT(2)                           /* CARD  0 -0-1 1: -1-0 */
#define FSDMMC_SD_SEN_REG_DEBNCE(x) ((x << 8) & GENMASK(31, 8)) /*  */

/** @name FSDMMC_HDS_AXI_REG_CONF1_REG_OFFSET Register
 */
#define FSDMMC_HDS_AXI_CONF1_AWREGION_HDS_M     GENMASK(22, 19)
#define FSDMMC_HDS_AXI_CONF1_AWSNOOP_HDS_M      GENMASK(18, 16)
#define FSDMMC_HDS_AXI_CONF1_ARBAR_HDS_M        GENMASK(15, 14)
#define FSDMMC_HDS_AXI_CONF1_ARDOMAIN_HDS_M     GENMASK(13, 12)
#define FSDMMC_HDS_AXI_CONF1_ARREGION_HDS_M     GENMASK(11, 8)
#define FSDMMC_HDS_AXI_CONF1_ARSNOOP_HDS_M      GENMASK(7, 4)
#define FSDMMC_HDS_AXI_CONF1_AWBAR_HDS_M        GENMASK(3, 2)
#define FSDMMC_HDS_AXI_CONF1_AWDOMAIN_HDS_M     GENMASK(1, 0)

/** @name FSDMMC_DAT_IN_M_RX_BD_REG_OFFSET Register
 */
#define FSDMMC_DAT_IN_M_RX_BD_MASK              GENMASK(31, 0)

/** @name FSDMMC_DAT_IN_M_TX_BD_REG_OFFSET Register
 */
#define FSDMMC_DAT_IN_M_TX_BD_MASK              GENMASK(31, 0)

/** @name FSDMMC_BLK_CNT_REG_OFFSET Register
 */
#define FSDMMC_BLK_CNT_MASK                     GENMASK(31, 0)

/** @name FSDMMC_HDS_AXI_REG_CONF2_REG_OFFSET Register
 */
#define FSDMMC_HDS_AXI_CONF2_SD_ARPROT          GENMASK(29, 27)
#define FSDMMC_HDS_AXI_CONF2_SD_AWPROT          GENMASK(26, 24)
#define FSDMMC_HDS_AXI_CONF2_SD_ARCACHE_M       GENMASK(23, 20)
#define FSDMMC_HDS_AXI_CONF2_SD_AWCACHE_M       GENMASK(19, 16)
#define FSDMMC_HDS_AXI_CONF2_HDA_ARPRO          GENMASK(13, 11)
#define FSDMMC_HDS_AXI_CONF2_HDA_AWPROT         GENMASK(10, 8)
#define FSDMMC_HDS_AXI_CONF2_HDA_ARCACHE_M      GENMASK(7, 4)
#define FSDMMC_HDS_AXI_CONF2_HDA_AWCACHE_M      GENMASK(3, 0)

/** @name FSDMMC_NORMAL_INT_STATUS_REG_OFFSET Register
 */
#define FSDMMC_NORMAL_INT_STATUS_EI BIT(15) /*  */
#define FSDMMC_NORMAL_INT_STATUS_CR BIT(1)  /*  */
#define FSDMMC_NORMAL_INT_STATUS_CC BIT(0)  /*  */
#define FSDMMC_NORMAL_INT_STATUS_ALL_MASK (FSDMMC_NORMAL_INT_STATUS_EI | FSDMMC_NORMAL_INT_STATUS_CR | FSDMMC_NORMAL_INT_STATUS_CC)

/** @name FSDMMC_ERROR_INT_STATUS_REG_OFFSET Register
 */
#define FSDMMC_ERROR_INT_STATUS_CNR BIT(4)   /*  */
#define FSDMMC_ERROR_INT_STATUS_CIR BIT(3)   /*  */
#define FSDMMC_ERROR_INT_STATUS_CCRCE BIT(1) /*  CRC  */
#define FSDMMC_ERROR_INT_STATUS_CTE BIT(0)   /*  */
#define FSDMMC_ERROR_INT_STATUS_ALL_MASK (FSDMMC_ERROR_INT_STATUS_CNR | FSDMMC_ERROR_INT_STATUS_CIR | FSDMMC_ERROR_INT_STATUS_CCRCE | FSDMMC_ERROR_INT_STATUS_CTE)

/** @name FSDMMC_BD_ISR_REG_OFFSET Register
 */
#define FSDMMC_BD_ISR_REG_DAIS BIT(15)   /* DMA */
#define FSDMMC_BD_ISR_REG_RESPE BIT(8)   /*  SD AXI BR */
#define FSDMMC_BD_ISR_REG_DATFRAX BIT(7) /* AXI */
#define FSDMMC_BD_ISR_REG_NRCRC BIT(6)   /*  CRC */
#define FSDMMC_BD_ISR_REG_TRE BIT(5)     /* CRC */
#define FSDMMC_BD_ISR_REG_CMDE BIT(4)    /* */
#define FSDMMC_BD_ISR_REG_DTE BIT(3)     /* */
#define FSDMMC_BD_ISR_REG_TRS BIT(0)     /* DMA */

/** @name FSDMMC_BD_STATUS_REG_OFFSET Register
 */
#define FSDMMC_BD_STATUS_MASK       GENMASK(31, 0) /* BD  */

/** @name FSDMMC_STATUS_REG_OFFSET Register
 */
#define FSDMMC_STATUS_REG_DATMAST(x) (GENMASK(30, 27) & ((x) << 27)) /* data_master  */
#define FSDMMC_STATUS_REG_CDIF BIT(26)                               /*  */
#define FSDMMC_STATUS_REG_CDRF BIT(25)                               /*  */
#define FSDMMC_STATUS_REG_CLSL BIT(24)                               /*  */
#define FSDMMC_STATUS_REG_DLSL(x) (GENMASK(23, 20) & ((x) << 20))    /*  */
#define FSDMMC_STATUS_REG_CDSL BIT(19)                               /*  */
#define FSDMMC_STATUS_REG_CST(x) (GENMASK(15, 12) & ((x) << 12))     /* cmd_host state  */
#define FSDMMC_STATUS_IDIE     (0x1 << 12)
#define FSDMMC_STATUS_REG_CSM(x) (GENMASK(11, 7) & ((x) << 7))
#define FSDMMC_STATUS_REG_DAT_AVA BIT(6) /* DAT_AVA   */
#define FSDMMC_STATUS_REG_CRC_VALID BIT(5)
#define FSDMMC_STATUS_REG_CICMD BIT(0) /* RO 0x0 CMD  */
#define FSDMMC_STATUS_CMD_BUSY  (0x0 << 0)
#define FSDMMC_STATUS_CMD_READY (0x1 << 0)

/** @name FSDMMC_BLOCK_REG_OFFSET Register
 */
#define FSDMMC_BLOCK_MASK       GENMASK(31, 0)

/** @name FSDMMC_CMD_RESP_1_REG_OFFSET Register
 */
#define FSDMMC_CMD_RESP_1_MASK  GENMASK(31, 0)

/** @name FSDMMC_CMD_RESP_2_REG_OFFSET Register
 */
#define FSDMMC_CMD_RESP_2_MASK  GENMASK(31, 0)

/** @name FSDMMC_CMD_RESP_3_REG_OFFSET Register
 */
#define FSDMMC_CMD_RESP_3_MASK  GENMASK(31, 0)

/** @name FSDMMC_CMD_RESP_4_REG_OFFSET Register
 */
#define FSDMMC_CMD_RESP_4_MASK  GENMASK(31, 0)

#define FSDMMC_DEFAULT_DRV            1
#define FSDMMC_DEFAULT_SAMP           5
#define FSDMMC_SEN_CREFR_VAL          (0x1 << 1)
#define FSDMMC_SEN_DEBNCE_VAL         (0xB << 8)
#define FSDMMC_CMD_TIMEOUT            10000000  /* 1s */
#define FSDMMC_DATA_TIMEOUT           40000000 /* 4s */
#define FSDMMC_AXI_CONF1              0x1001
#define FSDMMC_AXI_CONF2              0x12221222
#define FSDMMC_TIMEOUT                5000000  /* timeout for retries */
#define FSDMMC_BLOCK_SIZE             512

#define FSDMMC_DMA_ADDR_ALIGN         32
/**************************** Type Definitions *******************************/

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/

#define FSDMMC_READ_REG(addr, reg_offset) FtIn32((addr) + (u32)(reg_offset))
#define FSDMMC_WRITE_REG(addr, reg_offset, reg_value) FtOut32((addr) + (u32)(reg_offset), (u32)(reg_value))
#define FSDMMC_SET_BIT(addr, reg_offset, bit) FtSetBit32((addr) + (u32)(reg_offset), (u32)(bit))
#define FSDMMC_CLR_BIT(addr, reg_offset, bit) FtClearBit32((addr) + (u32)(reg_offset), (u32)(bit))

/* ,  */
static inline boolean FSdmmcCheckIfCardExists(uintptr base_addr)
{
    return (FSDMMC_STATUS_REG_CDSL != (FSDMMC_STATUS_REG_CDSL & FSDMMC_READ_REG(base_addr, FSDMMC_STATUS_REG_OFFSET)));
}

/*  */
static inline void FSdmmcClearNormalInterruptStatus(uintptr base_addr)
{
    FSDMMC_WRITE_REG(base_addr, FSDMMC_NORMAL_INT_STATUS_REG_OFFSET, (0x1));
}

/*  */
static inline void FSdmmcClearErrorInterruptStatus(uintptr base_addr)
{
    FSDMMC_WRITE_REG(base_addr, FSDMMC_ERROR_INT_STATUS_REG_OFFSET, (0x1));
}

/* DMA */
static inline void FSdmmcClearBDInterruptStatus(uintptr base_addr)
{
    FSDMMC_WRITE_REG(base_addr, FSDMMC_BD_ISR_REG_OFFSET, (0x1));
}

/************************** Function Prototypes ******************************/
/* FSDMMC */
FError FSdmmcReset(uintptr base_addr);

/*  */
FError FSdmmcSoftwareReset(uintptr base_addr, int retries);

/* FSDMMC */
FError FSdmmcSetCardClk(uintptr base_addr, u32 clk_freq_hz);

/*  */
void FSdmmcSendPrivateCmd(uintptr base_addr, u32 cmd, u32 arg);

/*  */
FError FSdmmcWaitStatus(uintptr base_addr, int retries);

/*  */
FError FSdmmcWaitDMAStatus(uintptr base_addr, boolean read, int retries);

#ifdef __cplusplus
}
#endif

#endif