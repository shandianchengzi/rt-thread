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
 * FilePath: fgmac_hw.h
 * Date: 2022-04-06 14:46:52
 * LastEditTime: 2022-04-06 14:46:58
 * Description: This file is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#ifndef  DRIVERS_ETH_FGMAC_HW_H
#define  DRIVERS_ETH_FGMAC_HW_H


/* - 
- hardware interface of device || low-level driver function prototypes

- low-level
1. 
2. 
3. 
4. 

note: fooxx.h
*/

#ifdef __cplusplus
extern "C"
{
#endif
/***************************** Include Files *********************************/

#include "fkernel.h"
#include "fio.h"
#include "ftypes.h"

/************************** Constant Definitions *****************************/

/** @name Register Map
 *
 * Register offsets from the base address of an SD device.
 * @{
 */
/**** FGMAC CTRL ****/
#define FGMAC_CONF_OFFSET 0x00U                   /* MAC  */
#define FGMAC_FRAME_FILTER_OFFSET 0x04U           /* Mac  */
#define FGMAC_HASH_HIGH_OFFSET 0x08U              /*  */
#define FGMAC_HASH_LOW_OFFSET 0x0cU               /*  */
#define FGMAC_GMII_ADDR_OFFSET 0x10U              /* GMII  */
#define FGMAC_GMII_DATA_OFFSET 0x14U              /* GMII  */
#define FGMAC_FLOW_CTRL_OFFSET 0x18U              /*  */
#define FGMAC_VLAN_TAG_OFFSET 0x1cU               /* VLAN  */
#define FGMAC_VERSION_OFFSET 0x20U                /*  */
#define FGMAC_DEBUG_STATUS_OFFSET 0x24U           /*  */
#define FGMAC_LPI_CTRL_STATUS_OFFSET 0x30U        /* LPI ()  */
#define FGMAC_LPI_TIMER_CTRL_OFFSET 0x34U         /* LPI  */
#define FGMAC_INTR_STATUS_OFFSET 0x38U             /*  */
#define FGMAC_INTR_MASK_OFFSET 0x3CU               /*  */
#define FGMAC_MAC_ADDR0_UPPER16BIT_OFFSET 0x40U   /*  MAC  16  */
#define FGMAC_MAC_ADDR0_LOWER32BIT_OFFSET 0x44U   /*  MAC  32  */
#define FGMAC_MAC_ADDR1_UPPER16BIT_OFFSET 0x48U   /*  MAC  16  */
#define FGMAC_MAC_ADDR1_LOWER32BIT_OFFSET 0x4CU   /*  MAC  32  */
#define FGMAC_MAC_PHY_STATUS 0xD8U                /* MAC PHY  */

/**** FGMAC DMA CTRL ****/
#define FGMAC_DMA_BUS_MODE_OFFSET 0x1000U           /*  */
#define FGMAC_DMA_TX_POLL_REQ_OFFSET 0x1004U        /*  */
#define FGMAC_DMA_RX_POLL_REQ_OFFSET 0x1008U        /*  */
#define FGMAC_DMA_RX_LIST_BASE_OFFSET 0x100cU       /*  */
#define FGMAC_DMA_TX_LIST_BASE_OFFSET 0x1010U       /*  */
#define FGMAC_DMA_STATUS_OFFSET 0x1014U             /*  */
#define FGMAC_DMA_OP_OFFSET 0x1018U                 /*  */
#define FGMAC_DMA_INTR_OFFSET 0x101cU            /*  */
#define FGMAC_DMA_MISSED_FRAME_CNT_OFFSET 0x1020U   /*  */
#define FGMAC_DMA_RX_WATCHDOG_OFFSET 0x1024U        /*  */
#define FGMAC_DMA_AXI_BUS_MOD_OFFSET 0x1028U        /* AXI */
#define FGMAC_DMA_AXI_BUS_STATUS_OFFSET 0x102CU     /* AXI  */
#define FGMAC_DMA_HOST_TX_DESC_OFFSET 0x1048U       /*  */
#define FGMAC_DMA_HOST_RX_DESC_OFFSET 0x104CU       /*  */
#define FGMAC_DMA_HOST_TX_BUF_ADDR_OFFSET 0x1050U   /*  */
#define FGMAC_DMA_HOST_RX_BUF_ADDR_OFFSET 0x1054U   /*  */
#define FGMAC_DMA_HW_FUNC_OFFSET   0x1058U          /*  */

/** @name FGMAC_CONF_OFFSET Register
 */
#define FGMAC_CONF_RX_EN               BIT(2) /*  */
#define FGMAC_CONF_TX_EN               BIT(3) /*  */
#define FGMAC_CONF_DC               BIT(4) /*  */
#define FGMAC_CONF_BL_MASK          GENMASK(6, 5) /*  */
#define FGMAC_CONF_BL(x)            (FGMAC_CONF_BL_MASK & ((x) << 5))
#define FGMAC_CONF_ACS              BIT(7) /*  PAD/ CRC  */
#define FGMAC_CONF_LINK_UPDOWN      BIT(8) /*  up/down */
#define FGMAC_CONF_DISABLE_RETRY    BIT(9) /*  */
#define FGMAC_CONF_IPC              BIT(10) /*  */
#define FGMAC_CONF_DUPLEX_MODE      BIT(11) /*  */
#define FGMAC_CONF_LOOPBACK_MODE    BIT(12) /*  */
#define FGMAC_CONF_DO               BIT(13) /*  */
#define FGMAC_CONF_FES              BIT(14) /*  0: 10Mbps, 1: 100Mbps  d2000 ft2004*/
#define FGMAC_CONF_PORTSELECT       BIT(15) /*  0: GMII1000Mbps1: MII(10/100Mbps) */
#define FGMAC_CONF_DCRS             BIT(16) /*  */
#define FGMAC_CONF_IFG_MASK         GENMASK(19, 17) /*  */
#define FGMAC_CONF_IFG(x)           (FGMAC_CONF_IFG_MASK & ((x) << 17))
#define FGMAC_CONF_JE               BIT(20) /* Jumbo */
#define FGMAC_CONF_BE               BIT(21) /*  */
#define FGMAC_CONF_JD               BIT(22) /* Jabber  */
#define FGMAC_CONF_WD               BIT(23) /*  */
#define FGMAC_CONF_TC               BIT(24) /*  RGMII  */
#define FGMAC_CONF_CST              BIT(25) /*  CRC  */

/* CRCWDJabber JDBEDO()*/
#define FGMAC_CONF_INIT  (FGMAC_CONF_CST| FGMAC_CONF_WD| FGMAC_CONF_JD| FGMAC_CONF_BE| FGMAC_CONF_DO)

/** @name FGMAC_FRAME_FILTER_OFFSET Register
 */
#define FGMAC_FRAME_FILTER_PR           BIT(0)
#define FGMAC_FRAME_FILTER_HUC          BIT(1)  /*  */
#define FGMAC_FRAME_FILTER_HMC          BIT(2)  /*  */
#define FGMAC_FRAME_FILTER_DAIF         BIT(3)  /*  */
#define FGMAC_FRAME_FILTER_PM           BIT(4)  /*  */
#define FGMAC_FRAME_FILTER_DBF          BIT(5)  /*  */
#define FGMAC_FRAME_FILTER_PCF_MASK     (GENMASK(7, 6))  /*  */
#define FGMAC_FRAME_FILTER_PCF(x)       ((x) << 6)
#define FGMAC_FRAME_FILTER_SAIF         BIT(8)   /*  */
#define FGMAC_FRAME_FILTER_SAF          BIT(9)   /*  */
#define FGMAC_FRAME_FILTER_HPF          BIT(10)  /* hash  perfect  */
#define FGMAC_FRAME_FILTER_RA           BIT(31)  /*  */

/** @name FGMAC_HASH_HIGH_OFFSET Register
 */
#define FGMAC_HASH_HIGH_HTH_MASK        GENMASK(31, 0) /*  Hash  32  */

/** @name FGMAC_HASH_LOW_OFFSET Register
 */
#define FGMAC_HASH_LOW_HTH_MASK         GENMASK(31, 0) /*  Hash  32  */

/** @name FGMAC_GMII_ADDR_OFFSET Register
 */
#define FGMAC_MII_ADDR_GB               BIT(0) /* GMII  */
#define FGMAC_MII_ADDR_GW               BIT(1) /* GMII  */
#define FGMAC_MII_ADDR_CR_MASK          GENMASK(5, 2) /* CSR  */
#define FGMAC_MII_ADDR_CR(x)            (FGMAC_MII_ADDR_CR_MASK & ((x) << 2))
#define FGMAC_MII_ADDR_GR_MASK          GENMASK(10, 6) /* GMII  */
#define FGMAC_MII_ADDR_GR(x)            (FGMAC_MII_ADDR_GR_MASK & ((x) << 6))
#define FGMAC_MII_ADDR_PA_MASK          GENMASK(15, 11) /*  */
#define FGMAC_MII_ADDR_PA(x)            (FGMAC_MII_ADDR_PA_MASK & ((x) << 11))

/** @name FGMAC_GMII_DATA_OFFSET Register
 */
#define FGMAC_MII_DATA_GD_MASK          GENMASK(15, 0)

/** @name FGMAC_FLOW_CTRL_OFFSET Register
 */
#define FGMAC_FLOW_FCB                  BIT(0)
#define FGMAC_FLOW_BPA                  BIT(0)
#define FGMAC_FLOW_TFE                  BIT(1)
#define FGMAC_FLOW_RFE                  BIT(2) /*  */
#define FGMAC_FLOW_UP                   BIT(3) /*  */
#define FGMAC_FLOW_PLT_MASK             GENMASK(5, 4) /*  */
#define FGMAC_FLOW_PLT(x)               ((x) << 3)
#define FGMAC_FLOW_DZPQ                 BIT(7)
#define FGMAC_FLOW_PT_MASK              GENMASK(31, 16) /*  */

/** @name FGMAC_VLAN_TAG_OFFSET Register
 */
#define FGMAC_VLAN_TAG_VL_MASK          GENMASK(15, 0) /*  12  VLAN  */
#define FGMAC_VLAN_TAG_VL(x)            (FGMAC_VLAN_TAG_VL_MASK & ((x) << 15))
#define FGMAC_VLAN_TAG_ETV              BIT(16) /*  VLAN  */

/** @name FGMAC_VERSION_OFFSET Register
 */
#define FGMAC_VERSION_UDV_MASK          GENMASK(15, 8) /*  */
#define FGMAC_VERSION_SDV_MASK          GENMASK(7, 0) /*  */

/** @name FGMAC_LPI_CTRL_STATUS_OFFSET Register
 */
#define FGMAC_LPI_CTRL_STATS_TLPIEN      BIT(0) /*  LPI  */
#define FGMAC_LPI_CTRL_STATS_TLPIEX      BIT(1) /*  LPI  */
#define FGMAC_LPI_CTRL_STATS_RLPIEN      BIT(2) /*  LPI  */
#define FGMAC_LPI_CTRL_STATS_RLPIEX      BIT(3) /*  LPI  */
#define FGMAC_LPI_CTRL_STATS_TLPIST      BIT(8) /*  LPI  */
#define FGMAC_LPI_CTRL_STATS_RLPIST      BIT(9)  /*  LPI  */
#define FGMAC_LPI_CTRL_STATS_LPIEN       BIT(16) /* LPI  */
#define FGMAC_LPI_CTRL_STATS_PLS         BIT(17) /* PHY  */
#define FGMAC_LPI_CTRL_STATS_PLSEN       BIT(18) /*  */
#define FGMAC_LPI_CTRL_STATS_LPITXA      BIT(19) /* LPI  */

/** @name FGMAC_LPI_TIMER_CTRL_OFFSET Register
 */
#define FGMAC_LPI_TIMER_TWT_MASK        GENMASK(15, 0)
#define FGMAC_LPI_TIMER_LIT_MASK        GENMASK(25, 16)

/** @name FGMAC_INTR_STATUS_OFFSET Register
 */
#define FGMAC_ISR_STATUS_RSIS            BIT(0) /* RGMII/SMII Interrupt Status */
#define FGMAC_ISR_STATUS_PCSLSC          BIT(1) /* PCS  */
#define FGMAC_ISR_STATUS_PCSANC          BIT(2) /* PCS  */
#define FGMAC_ISR_STATUS_PMTIS           BIT(3)
#define FGMAC_ISR_STATUS_MMCIS           BIT(4)
#define FGMAC_ISR_STATUS_MMCRIS          BIT(5)  /* MMC  */
#define FGMAC_ISR_STATUS_MMCTIS          BIT(6)  /* MMC  */
#define FGMAC_ISR_STATUS_MMCRCOIS        BIT(7)  /*  */
#define FGMAC_ISR_STATUS_TIS             BIT(9)  /*  */
#define FGMAC_ISR_STATUS_LPIIS           BIT(10) /* LPI  */
#define FGMAC_ISR_STATUS_ALL_MASK        GENMASK(10, 0)

/** @name FGMAC_INTR_MASK_OFFSET Register
 */
#define FGMAC_ISR_MASK_RSIM             BIT(0) /* RGMII/SMII  */
#define FGMAC_ISR_MASK_PCSLSIM          BIT(1) /* PCS  */
#define FGMAC_ISR_MASK_PCSANCIM         BIT(2) /* PCS AN  */
#define FGMAC_ISR_MASK_PMTIM            BIT(3) /* PMT  */
#define FGMAC_ISR_MASK_TIM              BIT(9) /*  */
#define FGMAC_ISR_MASK_LPIIM            BIT(10) /* LPI  */
#define FGMAC_ISR_MASK_ALL_BITS         (GENMASK(3, 0) | GENMASK(10, 9))

#define FGMAC_8BIT_ADDR                 GENMASK(7, 0)

/** @name FGMAC_MAC_ADDR0_UPPER16BIT_OFFSET Register
 */
#define FGMAC_MAC_ADDR0_UPPER16BIT_A    GENMASK(15, 0) /* MAC  0[47:32] */

/** @name FGMAC_MAC_ADDR0_LOWER32BIT_OFFSET Register
 */
#define FGMAC_MAC_ADDR0_LOWER32BIT_A  GENMASK(31, 0) /* MAC  0[31:0] */

/** @name FGMAC_MAC_ADDR1_UPPER16BIT_OFFSET Register
 */
#define FGMAC_MAC_ADDR1_UPPER16BIT_A    GENMASK(15, 0) /* MAC  1[47:32] */
#define FGMAC_MAC_ADDR1_UPPER16BIT_MBC  GENMASK(29, 24)
#define FGMAC_MAC_ADDR1_UPPER16BIT_SA   BIT(30)
#define FGMAC_MAC_ADDR1_UPPER16BIT_AE   BIT(31)

/** @name FGMAC_MAC_ADDR1_LOWER32BIT_OFFSET Register
 */
#define FGMAC_MAC_ADDR1_LOWER16BIT_A   GENMASK(31, 0) /* MAC  1[31:0] */

/** @name FGMAC_MAC_PHY_STATUS Register
 */
#define FGMAC_RGSMIIIS_LNKMODE      BIT(0) /*  */
#define FGMAC_RGSMIIIS_LNKMODE_HALF  (0b0 << 0)
#define FGMAC_RGSMIIIS_LNKMODE_FULL  (0b1 << 0)
#define FGMAC_RGSMIIIS_SPEED         GENMASK(2, 1)
#define FGMAC_RGSMIIIS_SPEED_2_5MHZ  (0b00 << 1) /*   2.5MHz */
#define FGMAC_RGSMIIIS_SPEED_25MHZ   (0b01 << 1) /*  25MHz */
#define FGMAC_RGSMIIIS_SPEED_125MHZ  (0b10 << 1) /*  125MHz */
#define FGMAC_RGSMIIIS_LNKSTS       BIT(3)
#define FGMAC_RGSMIIIS_LNKSTS_UP     (0b1 << 3)
#define FGMAC_RGSMIIIS_LNKSTS_DOWN   (0b0 << 3)
#define FGMAC_RGSMIIIS_JAB_TIMEOUT   BIT(4)
#define FGMAC_RGSMIIIS_FALSECARDET  BIT(5)

/****************FGMAC DMA Register*******************/
/* Bus mode register definitions */
/** @name FGMAC_DMA_BUS_MODE_OFFSET Register
 */
#define FGMAC_DMA_BUS_SWR           BIT(0) /*  */
#define FGMAC_DMA_BUS_DA            BIT(1) /*  8xPBL  */
#define FGMAC_DMA_BUS_DSL_MASK      GENMASK(6, 2) /*  */
#define FGMAC_DMA_BUS_ATDS          BIT(7)
#define FGMAC_DMA_BUS_PBL_MASK      GENMASK(13, 8) /*  */
#define FGMAC_DMA_BUS_PBL(x)        ((x) << 8)
enum
{
    FGMAC_DMA_BUS_PBL_1  = 1,
    FGMAC_DMA_BUS_PBL_2  = 2,
    FGMAC_DMA_BUS_PBL_4  = 4,
    FGMAC_DMA_BUS_PBL_8  = 8,
    FGMAC_DMA_BUS_PBL_16  = 16,
    FGMAC_DMA_BUS_PBL_32  = 32
};
#define FGMAC_DMA_BUS_PR_MASK GENMASK(15, 14) /*  */
#define FGMAC_DMA_BUS_PR(x)          ((x) << 14)
#define FGMAC_DMA_BUS_FB            BIT(16) /*  */
#define FGMAC_DMA_BUS_RPBL_MASK     GENMASK(22, 17) /* RxDMA  */
#define FGMAC_DMA_BUS_RPBL(x)        ((x) << 17)
enum
{
    FGMAC_DMA_BUS_RPBL_1  = 1,
    FGMAC_DMA_BUS_RPBL_2  = 2,
    FGMAC_DMA_BUS_RPBL_4  = 4,
    FGMAC_DMA_BUS_RPBL_16  = 16,
    FGMAC_DMA_BUS_RPBL_32  = 32
};
#define FGMAC_DMA_BUS_USP           BIT(23)
#define FGMAC_DMA_BUS_8XPBL         BIT(24)
#define FGMAC_DMA_BUS_AAL           BIT(25)
#define FGMAC_DMA_BUS_MB            BIT(26) /*  */
#define FGMAC_DMA_BUS_TXPR          BIT(27) /*  */
#define FGMAC_DMA_BUS_PRWG          GENMASK(29, 18) /*  */

#define FGMAC_DMA_BUS_INIT          (FGMAC_DMA_BUS_FB | FGMAC_DMA_BUS_PBL(16) | FGMAC_DMA_BUS_RPBL(16))

/*  RxDMA  TxDMA ,
   FGMAC_DMA_BUS_DA=1 */
#define FGMAC_DMA_BUS_PRIORXTX_41       (3 << 14) /* 4:1 */
#define FGMAC_DMA_BUS_PRIORXTX_31       (2 << 14) /* 3:1 */
#define FGMAC_DMA_BUS_PRIORXTX_21       (1 << 14) /* 2:1 */
#define FGMAC_DMA_BUS_PRIORXTX_11       (0 << 14) /* 1:1 */

/** @name FGMAC_DMA_TX_POLL_REQ_OFFSET Register
 */
#define FGMAC_DMA_XMT_POLL_DEMAND_TPD GENMASK(31, 0)

/** @name FGMAC_DMA_RX_POLL_REQ_OFFSET Register
 */
#define FGMAC_DMA_RCV_POLL_DEMAND_RPD GENMASK(31, 0)

/** @name FGMAC_DMA_RX_LIST_BASE_OFFSET Register
 */
#define FGMAC_DMA_RCV_BASE_ADDR_START_REC_LIST GENMASK(31, 4)

/** @name FGMAC_DMA_TX_LIST_BASE_OFFSET Register
 */
#define FGMAC_DMA_TX_BASE_ADDR_START_TRA_LIST GENMASK(31, 4)

/** @name FGMAC_DMA_STATUS_OFFSET Register
 */
#define FGMAC_DMA_STATUS_GLPII               BIT(30)   /* FGMAC LPI interrupt */
#define FGMAC_DMA_STATUS_TTI                 BIT(29)   /*  */
#define FGMAC_DMA_STATUS_GPI                 BIT(28)   /* PMT interrupt */
#define FGMAC_DMA_STATUS_GMI                 BIT(27)  /* MMC interrupt */
#define FGMAC_DMA_STATUS_GLI                 BIT(26)  /* FGMAC Line interface int */
#define FGMAC_DMA_STATUS_EB_MASK             GENMASK(25, 23)     /* Error Bits Mask */
#define FGMAC_DMA_STATUS_TS_MASK             GENMASK(22, 20)     /* Transmit Process State */
#define FGMAC_DMA_STATUS_TS_STOPPED          (0b000 << 20)
#define FGMAC_DMA_STATUS_TS_GET_DESC         (0b001 << 20)
#define FGMAC_DMA_STATUS_TS_WAIT             (0b010 << 20)
#define FGMAC_DMA_STATUS_TS_QUEUE            (0b011 << 20)
#define FGMAC_DMA_STATUS_TS_PAUSE            (0b110 << 20)
#define FGMAC_DMA_STATUS_TS_CLOSE_DESC       (0b111 << 20)
#define FGMAC_DMA_STATUS_RS_MASK             GENMASK(19, 17) /* Receive Process State */
#define FGMAC_DMA_STATUS_NIS                 BIT(16)         /* Normal Interrupt Summary */
#define FGMAC_DMA_STATUS_AIS                 BIT(15)         /* Abnormal Interrupt Summary */
#define FGMAC_DMA_STATUS_ERI                 BIT(14)         /* Early Receive Interrupt */
#define FGMAC_DMA_STATUS_FBI                 BIT(13)         /* Fatal Bus Error Interrupt */
#define FGMAC_DMA_STATUS_ETI                 BIT(10)         /* Early Transmit Interrupt */
#define FGMAC_DMA_STATUS_RWT                 BIT(9)         /* Receive Watchdog Timeout */
#define FGMAC_DMA_STATUS_RPS                 BIT(8)         /* Receive Process Stopped */
#define FGMAC_DMA_STATUS_RU                  BIT(7)          /* Receive Buffer Unavailable */
#define FGMAC_DMA_STATUS_RI                  BIT(6)          /* Receive Interrupt */
#define FGMAC_DMA_STATUS_UNF                 BIT(5)         /* Transmit Underflow */
#define FGMAC_DMA_STATUS_OVF                 BIT(4)         /* Receive Overflow */
#define FGMAC_DMA_STATUS_TJT                 BIT(3)         /* Transmit Jabber Timeout */
#define FGMAC_DMA_STATUS_TU                  BIT(2)          /* Transmit Buffer Unavailable */
#define FGMAC_DMA_STATUS_TPS                 BIT(1)         /* Transmit Process Stopped */
#define FGMAC_DMA_STATUS_TI                  BIT(0)          /* Transmit Interrupt */

#define FGMAC_DMA_STATUS_CLR_ABLE            (GENMASK(5, 0) | GENMASK(10, 7)| FGMAC_DMA_STATUS_FBI | FGMAC_DMA_STATUS_AIS)  /* BIT [16 : 0] write 1 to clear */

/** @name FGMAC_DMA_OP_OFFSET Register
 */
#define FGMAC_DMA_OP_DT                      BIT(26)    /* No Dropping of TCP/IP csum Err Frame */
#define FGMAC_DMA_OP_RSF                     BIT(25)    /* Rx Store and Forward */
#define FGMAC_DMA_OP_DFF                     BIT(24)    /*   */
#define FGMAC_DMA_OP_RFA_2                   BIT(23)
#define FGMAC_DMA_OP_RFD_2                   BIT(22)
#define FGMAC_DMA_OP_TSF                     BIT(21)   /* Tx Store and Forward */
#define FGMAC_DMA_OP_FTF                     BIT(20)   /* Flush Tx FIFO */
#define FGMAC_DMA_OP_TTC_MASK                GENMASK(16, 14)
#define FGMAC_DMA_OP_TTC(x)                  ((x) << 14)   /* Tx Threshold Control */
enum
{
    FGMAC_DMA_OP_TTC_64 = 0b000,
    FGMAC_DMA_OP_TTC_128 = 0b001,
    FGMAC_DMA_OP_TTC_192 = 0b010,
    FGMAC_DMA_OP_TTC_256 = 0b011,
    FGMAC_DMA_OP_TTC_40  = 0b100,
    FGMAC_DMA_OP_TTC_32  = 0b101,
    FGMAC_DMA_OP_TTC_24  = 0b110,
    FGMAC_DMA_OP_TTC_16  = 0b111
};

#define FGMAC_DMA_OP_ST                      BIT(13)   /* Start/Stop Tx */
#define FGMAC_DMA_OP_RFD_MASK                GENMASK(12, 11)
#define FGMAC_DMA_OP_RFD(x)                  ((x) << 11) /* Threshold for DeActive Flow Control */
#define FGMAC_DMA_OP_RFA_MASK                GENMASK(10, 9) /* Threshold for Active Flow Control */
#define FGMAC_DMA_OP_EFC                     BIT(8)  /* Enable HW Flow control */
#define FGMAC_DMA_OP_FEF                     BIT(7)  /* Forward Error Frame */
#define FGMAC_DMA_OP_FUF                     BIT(6)  /* Forward Undersize Good Frame */
#define FGMAC_DMA_OP_RTC_MASK                GENMASK(4, 3)  /* Rx Threshold Control */
#define FGMAC_DMA_OP_OSF                     BIT(2)  /* Operate On Second Mode */
#define FGMAC_DMA_OP_SR                      BIT(1)  /* Start/Stop Rx */
#define FGMAC_DMA_OP_CLEAR_MASK              GENMASK(31, 0)
#define FGMAC_DMA_OP_INIT                    (FGMAC_DMA_OP_SR | FGMAC_DMA_OP_RSF)

/** @name FGMAC_DMA_INTR_OFFSET Register
 */
#define FGMAC_DMA_INTR_ENA_TIE               BIT(0) /* Transmit Interrupt */
#define FGMAC_DMA_INTR_ENA_TSE               BIT(1) /*  */
#define FGMAC_DMA_INTR_ENA_TUE               BIT(2) /* Transmit Buffer Unavailable */
#define FGMAC_DMA_INTR_ENA_THE               BIT(3) /*  Jabber  */
#define FGMAC_DMA_INTR_ENA_OVE               BIT(4) /*  */
#define FGMAC_DMA_INTR_ENA_UNE               BIT(5) /*  */
#define FGMAC_DMA_INTR_ENA_RIE               BIT(6) /* Receive Interrupt */
#define FGMAC_DMA_INTR_ENA_RUE               BIT(7) /*  */
#define FGMAC_DMA_INTR_ENA_RSE               BIT(8) /*  */
#define FGMAC_DMA_INTR_ENA_RWE               BIT(9) /*   */
#define FGMAC_DMA_INTR_ENA_ETE               BIT(10) /*   */
#define FGMAC_DMA_INTR_ENA_FBE               BIT(13) /* Fatal Bus Error */
#define FGMAC_DMA_INTR_ENA_ERE               BIT(14) /* Early Receive */
#define FGMAC_DMA_INTR_ENA_AIE               BIT(15) /* Abnormal Summary */
#define FGMAC_DMA_INTR_ENA_NIE               BIT(16) /* Normal Summary */
#define FGMAC_DMA_INTR_ENA_ALL_MASK          (GENMASK(10, 0) | GENMASK(16, 13))

/** @name FGMAC_DMA_MISSED_FRAME_CNT_OFFSET Register
 */
#define FGMAC_DMA_MISSED_FRAME_CTR_CMIS           GENMASK(15, 0) /*  */
#define FGMAC_DMA_MISSED_FRAME_CTR_OVMIS          BIT(16)
#define FGMAC_DMA_MISSED_FRAME_CTR_CFIFO          GENMASK(27, 17)
#define FGMAC_DMA_MISSED_FRAME_CTR_OVFIFO         BIT(28)

/** @name FGMAC_DMA_RX_WATCHDOG_OFFSET Register
 */
#define FGMAC_DMA_RX_WATCHDOG_RIWT                GENMASK(7, 0)

/** @name FGMAC_DMA_AXI_BUS_MOD_OFFSET Register
 */
#define FGMAC_DMA_AXI_BUS_MOD_UNDEF               BIT(0)  /* AXI  */
#define FGMAC_DMA_AXI_BUS_MOD_BLEN4               BIT(1)  /* AXI  4 */
#define FGMAC_DMA_AXI_BUS_MOD_BLEN8               BIT(2)  /* AXI  8 */
#define FGMAC_DMA_AXI_BUS_MOD_BLEN16              BIT(3)  /* AXI  16 */
#define FGMAC_DMA_AXI_BUS_MOD_BLEN32              BIT(4)  /* AXI  32 */
#define FGMAC_DMA_AXI_BUS_MOD_BLEN64              BIT(5)  /* AXI  64 */
#define FGMAC_DMA_AXI_BUS_MOD_BLEN128             BIT(6)  /* AXI  128 */
#define FGMAC_DMA_AXI_BUS_MOD_BLEN256             BIT(7)  /* AXI  256 */
#define FGMAC_DMA_AXI_BUS_MOD_AXI_AAL             BIT(12) /*  */
#define FGMAC_DMA_AXI_BUS_MOD_RD_OSR_LMT_MASK     GENMASK(19, 16)
#define FGMAC_DMA_AXI_BUS_MOD_RD_OSR_LMT(x)       ((x) << 16) /* XI   AXI  */
#define FGMAC_DMA_AXI_BUS_MOD_WR_OSR_LMT_MASK     GENMASK(23, 20)
#define FGMAC_DMA_AXI_BUS_MOD_WR_OSR_LMT(x)       ((x) << 20) /* AXI   AXI  */
#define FGMAC_DMA_AXI_BUS_MOD_UNLCK_ON_MGK_RWK    BIT(30)
#define FGMAC_DMA_AXI_BUS_MOD_EN_LPI              BIT(31)

#define FGMAC_DMA_DESC_ADDR_MASK                  GENMASK(31, 4)

#define FGMAC_MAC_ADDR_LEN                        6
#define FGMAC_RETRY_TIMES                         500
#define FGMAC_DELAY_US                            100
/**************************** Type Definitions *******************************/

typedef u8 FGmacMacAddr[FGMAC_MAC_ADDR_LEN];

enum
{
    FGMAC_CTRL_INTR = 0,
    FGMAC_DMA_INTR,

    FGMAC_MAX_INTR_TYPE
};

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
/* FGMACu32 */
#define FGMAC_READ_REG32(addr, reg_offset) FtIn32((addr) + (u32)(reg_offset))

/* FGMACu32 */
#define FGMAC_WRITE_REG32(addr, reg_offset, reg_value) FtOut32((addr) + (u32)(reg_offset), (u32)(reg_value))

/* FGMAC1,  */
#define FGMAC_SET_REG32(addr, reg_offset, set_bits) FtSetBit32((addr) + (u32)(reg_offset), (u32)(set_bits))

/* FGMAC0,  */
#define FGMAC_CLR_REG32(addr, reg_offset, clr_bits) FtClearBit32((addr) + (u32)(reg_offset), (u32)(clr_bits))

/* numidx1 */
#define FGMAC_DMA_INC_DESC(idx, num)                  (idx) = (((idx) + 1) % (num))

static inline void FGmacResumeDmaSend(uintptr base_addr)
{
    if (FGMAC_READ_REG32(base_addr, FGMAC_DMA_STATUS_OFFSET) & FGMAC_DMA_STATUS_TU)
    {
        FGMAC_SET_REG32(base_addr, FGMAC_DMA_STATUS_OFFSET, FGMAC_DMA_STATUS_TU); /* clear TBUS GMAC DMA flag */
        FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_TX_POLL_REQ_OFFSET, 0xff); /* resume DMA transmission */
    }
    else
    {
        FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_TX_POLL_REQ_OFFSET, 0xff); /* resume DMA transmission */
    }
}

static inline void FGmacResumeDmaRecv(uintptr base_addr)
{
    if (FGMAC_READ_REG32(base_addr, FGMAC_DMA_STATUS_OFFSET) & FGMAC_DMA_STATUS_RU)
    {
        FGMAC_SET_REG32(base_addr, FGMAC_DMA_STATUS_OFFSET, FGMAC_DMA_STATUS_RU); /* Clear RBUS GMAC DMA flag */
        FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_RX_POLL_REQ_OFFSET, 0xff); /* Resume DMA transmission*/
    }
    else
    {
        FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_RX_POLL_REQ_OFFSET, 0xff);
    }
}

static inline void FGmacStartDmaTrans(uintptr base_addr)
{
    FGMAC_SET_REG32(base_addr, FGMAC_DMA_OP_OFFSET, (FGMAC_DMA_OP_SR | FGMAC_DMA_OP_ST));     /* enable dma tx and rx */
    FGMAC_SET_REG32(base_addr, FGMAC_CONF_OFFSET, (FGMAC_CONF_RX_EN | FGMAC_CONF_TX_EN)); /* enable gmac tx and rx */

    /* clear Tx and Rx process stopped flags */
    FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_INTR_OFFSET,
                      (FGMAC_DMA_INTR_ENA_RIE | FGMAC_DMA_INTR_ENA_AIE | FGMAC_DMA_INTR_ENA_NIE));
}

static inline void FGmacStopDmaTrans(uintptr base_addr)
{
    FGMAC_CLR_REG32(base_addr, FGMAC_DMA_OP_OFFSET, (FGMAC_DMA_OP_SR | FGMAC_DMA_OP_ST)); /* disable dma tx and rx */
    FGMAC_CLR_REG32(base_addr, FGMAC_CONF_OFFSET, (FGMAC_CONF_RX_EN | FGMAC_CONF_TX_EN)); /* disable gmac tx and rx */
}

static inline void FGmacResmuDmaUnderflow(uintptr base_addr)
{
    if (FGMAC_DMA_STATUS_UNF & FGMAC_READ_REG32(base_addr, FGMAC_DMA_STATUS_OFFSET))
    {
        FGMAC_SET_REG32(base_addr, FGMAC_DMA_STATUS_OFFSET, FGMAC_DMA_STATUS_UNF);  /* clear TBUS GMAC DMA flag */
        FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_TX_POLL_REQ_OFFSET, 0xff); /* resume DMA transmission*/
    }
}

/************************** Function Prototypes ******************************/
/* FGMACMAC */
void FGmacGetMacAddr(uintptr base_addr, FGmacMacAddr mac_addr);

/* FGMACMAC */
void FGmacSetMacAddr(uintptr base_addr, const FGmacMacAddr mac_addr);

/* FGMAC */
FError FGmacSoftwareReset(uintptr base_addr, int timeout);

FError FGmacFlushTxFifo(uintptr base_addr, int timeout);

void FGmacStopDmaTrans(uintptr base_addr);

/* wait fgmac mii not busy */
FError FGmacPhyWaitBusBusy(uintptr base_addr, int timeout);

#ifdef __cplusplus
}
#endif

#endif
