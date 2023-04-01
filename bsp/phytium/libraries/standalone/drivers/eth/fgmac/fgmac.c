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
 * FilePath: fgmac.c
 * Date: 2022-04-06 14:46:52
 * LastEditTime: 2022-04-06 14:46:58
 * Description: This file is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */


/***************************** Include Files *********************************/
#include <string.h>

#include "fio.h"
#include "ferror_code.h"
#include "ftypes.h"
#include "fdebug.h"
#include "fassert.h"
#include "fgmac_hw.h"
#include "fgmac_phy.h"
#include "fgmac.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define FGMAC_DEBUG_TAG "FGMAC"
#define FGMAC_ERROR(format, ...)   FT_DEBUG_PRINT_E(FGMAC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGMAC_WARN(format, ...)    FT_DEBUG_PRINT_W(FGMAC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGMAC_INFO(format, ...)    FT_DEBUG_PRINT_I(FGMAC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGMAC_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FGMAC_DEBUG_TAG, format, ##__VA_ARGS__)


/************************** Function Prototypes ******************************/
static FError FGmacReset(FGmac *instance_p);
static FError FGmacDmaConfigure(FGmac *instance_p);
static FError FGmacControllerConfigure(FGmac *instance_p);
/************************** Variable Definitions *****************************/

/*****************************************************************************/

/*  */

/* - API
   - OPTION
   - I/OAPI  */

/* - API
   - OPTION
   - I/OAPI  */

/*
 * @name: FGmacStop
 * @msg: FGMAC
 * @return {*}
 * @param {FGmac} *instance_p 
 */
void FGmacStop(FGmac *instance_p)
{
    FASSERT(instance_p);
    uintptr base_addr = instance_p->config.base_addr;
    u32 reg_val;

    /* disable dma tx and rx */
    reg_val = FGMAC_READ_REG32(base_addr, FGMAC_DMA_OP_OFFSET);
    reg_val &= (~FGMAC_DMA_OP_ST);
    reg_val &= (~FGMAC_DMA_OP_SR);
    FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_OP_OFFSET, reg_val);

    /* disable gmac tx and rx */
    reg_val = FGMAC_READ_REG32(base_addr, FGMAC_CONF_OFFSET);
    reg_val &= (~FGMAC_CONF_TX_EN);
    reg_val &= (~FGMAC_CONF_RX_EN);
    FGMAC_WRITE_REG32(base_addr, FGMAC_CONF_OFFSET, reg_val);

}


/**
 * @name: FGmacCfgInitialize
 * @msg: init FGMAC controller
 * @param {FGmac} *instance_p, instance of FGmac controller
 * @param {FGmacConfig} *cofig_p, input configuration parameters
 * @return err code information, FGMAC_SUCCESS indicates successothers indicates failed
 */
FError FGmacCfgInitialize(FGmac *instance_p, const FGmacConfig *input_config_p)
{
    FASSERT(instance_p && input_config_p);
    FError ret = FGMAC_SUCCESS;

    /* indicating device is started */
    if (FT_COMPONENT_IS_READY == instance_p->is_ready)
    {
        FGMAC_WARN("device is already initialized!!!");
    }

    /* de-initialize device instance */
    FGmacDeInitialize(instance_p);
    instance_p->config = *input_config_p;


    /*Phy Awaken*/

    ret = FGmacPhyAwaken(instance_p);
    if (FGMAC_SUCCESS != ret)
    {
        FGMAC_ERROR("phy awaken failed!");
        return ret;
    }


    /* initialize the gmac controller */
    ret = FGmacReset(instance_p); // permmit failed
    if (FGMAC_SUCCESS != ret)
    {
        printf("FGmacReset failed \r\n");
    }


    ret = FGmacControllerConfigure(instance_p);
    if (FGMAC_SUCCESS != ret)
        return ret;

    /* initialize the gmac dma controller */
    ret = FGmacDmaConfigure(instance_p);
    if (FGMAC_SUCCESS == ret)
    {
        instance_p->is_ready = FT_COMPONENT_IS_READY;
    }

    return ret;
}

/**
 * @name: FGmacDeInitialize
 * @msg: deinit FGMAC controller
 * @param {FGmac} *instance_p, instance of FGmac controller
 * @return err code information, FGMAC_SUCCESS indicates successothers indicates failed
 */
FError FGmacDeInitialize(FGmac *instance_p)
{
    FASSERT(instance_p);
    FError ret = FGMAC_SUCCESS;

    instance_p->is_ready = 0;
    memset(instance_p, 0, sizeof(*instance_p));

    return ret;
}

/**
 * @name: FGmacReset
 * @msg: reset FGMAC controller
 * @param {FGmac} *instance_p, instance of FGmac controller
 * @return err code information, FGMAC_SUCCESS indicates successothers indicates failed
 */
static FError FGmacReset(FGmac *instance_p)
{
    FASSERT(instance_p);
    FGmacMacAddr mac_addr;
    uintptr base_addr = instance_p->config.base_addr;
    FError ret = FGMAC_SUCCESS;
    u32 reg_val;


    /* backup mac address before software reset */
    memset(mac_addr, 0, sizeof(mac_addr));
    FGmacGetMacAddr(base_addr, mac_addr);

    /* disable all gmac & dma intr */
    FGmacSetInterruptMask(instance_p, FGMAC_CTRL_INTR, FGMAC_ISR_MASK_ALL_BITS);
    FGmacSetInterruptMask(instance_p, FGMAC_DMA_INTR, FGMAC_DMA_INTR_ENA_ALL_MASK);

    /* stop gmac/dma tx and rx */
    FGmacStop(instance_p);

    /* do software reset per init */
    ret = FGmacSoftwareReset(base_addr, FGMAC_RETRY_TIMES);


    /* disable gmac & dma interrupts */
    FGmacSetInterruptMask(instance_p, FGMAC_CTRL_INTR, FGMAC_ISR_MASK_ALL_BITS);
    FGmacSetInterruptMask(instance_p, FGMAC_DMA_INTR, FGMAC_DMA_INTR_ENA_ALL_MASK);

    /* recover mac address after softwate reset */
    FGmacSetMacAddr(base_addr, mac_addr);

    return ret;// may return error
}

/**
 * @name: FGmacControllerSpeedConfig
 * @msg: fgmac speed configuration
 * @param {FGmac} *instance_p, instance of FGmac controller
 * @param {u32} speed, speed value
 * @return {*}
 */
void FGmacControllerSpeedConfig(FGmac *instance_p, u32 speed)
{
    FASSERT(instance_p);
    uintptr base_addr = instance_p->config.base_addr;
    u32 reg_val = 0;

    /* MAC */
    reg_val  = FGMAC_READ_REG32(base_addr, FGMAC_CONF_OFFSET);

    /* FES=1000Mbps */
    if (speed == FGMAC_PHY_SPEED_1000)
    {
        reg_val &= (~FGMAC_CONF_PORTSELECT);
        reg_val &= (~FGMAC_CONF_FES);
    }

    /* FES=100Mbps */
    if (speed == FGMAC_PHY_SPEED_100)
    {
        reg_val |= FGMAC_CONF_PORTSELECT;
        reg_val |= FGMAC_CONF_FES;
    }

    /* FES=10Mbps */
    if (speed == FGMAC_PHY_SPEED_10)
    {
        reg_val |= FGMAC_CONF_PORTSELECT;
        reg_val &= (~FGMAC_CONF_FES);
    }

    FGMAC_WRITE_REG32(base_addr, FGMAC_CONF_OFFSET, reg_val);
}

/**
 * @name: FGmacControllerDuplexConfig
 * @msg: fgmac deplex mode configuration
 * @param {FGmac} *instance_p, instance of FGmac controller
 * @param {u32} duplex, duplex mode
 * @return {*}
 */
void FGmacControllerDuplexConfig(FGmac *instance_p, u32 duplex)
{
    FASSERT(instance_p);
    uintptr base_addr = instance_p->config.base_addr;
    u32 reg_val = 0;

    /* MAC */
    reg_val  = FGMAC_READ_REG32(base_addr, FGMAC_CONF_OFFSET);

    /*  */
    if (duplex == FGMAC_PHY_MODE_FULLDUPLEX)
        reg_val |= FGMAC_CONF_DUPLEX_MODE;
    else
        reg_val &= ~FGMAC_CONF_DUPLEX_MODE;

    FGMAC_WRITE_REG32(base_addr, FGMAC_CONF_OFFSET, reg_val);

}

/**
 * @name: FGmacControllerConfigure
 * @msg: config FGMAC controller
 * @param {FGmac} *instance_p, instance of FGmac controller
 * @return err code information, FGMAC_SUCCESS indicates successothers indicates failed
 */
static FError FGmacControllerConfigure(FGmac *instance_p)
{
    FASSERT(instance_p);
    FGmacMacAddr mac_addr;
    uintptr base_addr = instance_p->config.base_addr;
    FError ret = FGMAC_SUCCESS;
    u32 reg_val = 0;

    /********gmac ctrl reg init*********/
    /* Set the WD bit according to ETH Watchdog value */
    /* Set the JD: bit according to ETH Jabber value */
    /* Set the IFG bit according to ETH InterFrameGap value */
    /* Set the DCRS bit according to ETH CarrierSense value */
    /* Set the FES bit according to ETH Speed value */
    /* Set the DO bit according to ETH ReceiveOwn value */
    /* Set the LM bit according to ETH LoopbackMode value */
    /* Set the DM bit according to ETH Mode value */
    /* Set the IPCO bit according to ETH ChecksumOffload value */
    /* Set the DR bit according to ETH RetryTransmission value */
    /* Set the ACS bit according to ETH AutomaticPadCRCStrip value */
    /* Set the BL bit according to ETH BackOffLimit value */
    /* Set the DC bit according to ETH DeferralCheck value */

    /* MAC */
    reg_val  = FGMAC_READ_REG32(base_addr, FGMAC_CONF_OFFSET);

    /* DCRSLM */
    reg_val &= ~(FGMAC_CONF_DCRS | FGMAC_CONF_LOOPBACK_MODE);

    /* IFG */
    reg_val |= FGMAC_CONF_IFG(0);

    /* 1000Mbps default */
    reg_val &= (~FGMAC_CONF_PORTSELECT);
    reg_val &= (~FGMAC_CONF_FES);

    /*  */
    if (instance_p->config.duplex_mode)
        reg_val |= FGMAC_CONF_DUPLEX_MODE;
    else
        reg_val &= ~FGMAC_CONF_DUPLEX_MODE;

    /* IPS */
    if (FGMAC_CHECKSUM_BY_HARDWARE == instance_p->config.cheksum_mode)
        reg_val |= FGMAC_CONF_IPC;
    else
        reg_val &= ~FGMAC_CONF_IPC;

    /* DR=1,  */
    reg_val |= FGMAC_CONF_DISABLE_RETRY;

    /*  PAD/ CRC ,  */
    reg_val |= FGMAC_CONF_ACS;

    /* ,  */
    reg_val |= FGMAC_CONF_BL(0);

    /*  */
    reg_val &= ~FGMAC_CONF_DC;

    /* CRCWDJabber JDBEDO()*/
    reg_val |= (FGMAC_CONF_CST | FGMAC_CONF_WD | FGMAC_CONF_JD | FGMAC_CONF_BE | FGMAC_CONF_DO);

    FGMAC_WRITE_REG32(base_addr, FGMAC_CONF_OFFSET, reg_val);

    /********gmac filter reg init*********/
    /* Set the RA bit according to ETH ReceiveAll value */
    /* Set the SAF and SAIF bits according to ETH SourceAddrFilter value */
    /* Set the PCF bit according to ETH PassControlFrames value */
    /* Set the DBF bit according to ETH BroadcastFramesReception value */
    /* Set the DAIF bit according to ETH DestinationAddrFilter value */
    /* Set the PR bit according to ETH PromiscuousMode value */
    /* Set the PM, HMC and HPF bits according to ETH MulticastFramesFilter value */
    /* Set the HUC and HPF bits according to ETH UnicastFramesFilter value */

    /* MAC */
    reg_val  = FGMAC_READ_REG32(base_addr, FGMAC_FRAME_FILTER_OFFSET);

    /* RA */
    reg_val |= FGMAC_FRAME_FILTER_RA;

    /* PCF 10b */
    reg_val |= FGMAC_FRAME_FILTER_PCF(2);

    /* DBF */
    reg_val &= ~FGMAC_FRAME_FILTER_DBF;

    /* PM */
    reg_val &= ~FGMAC_FRAME_FILTER_PM;

    /* DAIF */
    reg_val &= ~FGMAC_FRAME_FILTER_DAIF;

    /* PR */
    reg_val &= ~FGMAC_FRAME_FILTER_PR;
    FGMAC_WRITE_REG32(base_addr, FGMAC_FRAME_FILTER_OFFSET, reg_val);

    /********hash reg*********/
    FGMAC_WRITE_REG32(base_addr, FGMAC_HASH_HIGH_OFFSET, 0x0);
    FGMAC_WRITE_REG32(base_addr, FGMAC_HASH_LOW_OFFSET, 0x0);

    /********gmac flow ctrl reg init*********/

    /* Set the PT bit according to ETH PauseTime value */
    /* Set the DZPQ bit according to ETH ZeroQuantaPause value */
    /* Set the PLT bit according to ETH PauseLowThreshold value */
    /* Set the UP bit according to ETH UnicastPauseFrameDetect value */
    /* Set the RFE bit according to ETH ReceiveFlowControl value */
    /* Set the TFE bit according to ETH TransmitFlowControl value */
    reg_val = FGMAC_READ_REG32(base_addr, FGMAC_FLOW_CTRL_OFFSET);
    /* DZPQ */
    reg_val |= FGMAC_FLOW_DZPQ;

    /* PLT */
    reg_val |= FGMAC_FLOW_PLT(0);

    /* RFE */
    reg_val &= ~FGMAC_FLOW_RFE;

    /* TFE */
    reg_val &= ~FGMAC_FLOW_TFE;
    FGMAC_WRITE_REG32(base_addr, FGMAC_FLOW_CTRL_OFFSET, reg_val);

    /********vlan tag reg*********/
    /* Set the ETV bit according to ETH VLANTagComparison value */
    /* Set the VL bit according to ETH VLANTagIdentifier value */
    /*  VLAN  VL */
    reg_val = FGMAC_VLAN_TAG_VL(0);
    /* VLAN ETV  1-12bit 0-16bit */
    reg_val &= ~FGMAC_VLAN_TAG_ETV;
    FGMAC_WRITE_REG32(base_addr, FGMAC_VLAN_TAG_OFFSET, reg_val);

    return ret;
}

static FError FGmacDmaConfigure(FGmac *instance_p)
{
    FASSERT(instance_p);
    u32 reg_val;
    FError ret = FGMAC_SUCCESS;
    uintptr base_addr = instance_p->config.base_addr;

    /********DMA*********/
    /* Set the AAL bit according to ETH AddressAlignedBeats value */
    /* Set the FB bit according to ETH FixedBurst value */
    /* Set the RPBL and 4*PBL bits according to ETH RxDMABurstLength value */
    /* Set the PBL and 4*PBL bits according to ETH TxDMABurstLength value */
    /* Set the Enhanced DMA descriptors bit according to ETH EnhancedDescriptorFormat value*/
    /* Set the DSL bit according to ETH DesciptorSkipLength value */
    /* Set the PR and DA bits according to ETH DMAArbitration value */
    reg_val  = FGMAC_READ_REG32(base_addr, FGMAC_DMA_BUS_MODE_OFFSET);
    reg_val |= FGMAC_DMA_BUS_AAL;
    /*  PBL USP */
    reg_val |= FGMAC_DMA_BUS_USP;
    /* RxDMA PBL RPBL */
    reg_val |= FGMAC_DMA_BUS_RPBL(32);

    /*  FB */
    reg_val |= FGMAC_DMA_BUS_FB;

    /*  RxDMA  TxDMA  PR */
    reg_val |= FGMAC_DMA_BUS_PR(0);

    /*  PBL */
    reg_val |= FGMAC_DMA_BUS_PBL(32);

    /*  ATDS */
    reg_val |= FGMAC_DMA_BUS_ATDS;


    FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_BUS_MODE_OFFSET, reg_val);

    /* dma set bus mode */
    // FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_BUS_MODE_OFFSET, FGMAC_DMA_BUS_INIT);

    /********DMA*********/
    /* Set the DT bit according to ETH DropTCPIPChecksumErrorFrame value */
    /* Set the RSF bit according to ETH ReceiveStoreForward value */
    /* Set the DFF bit according to ETH FlushReceivedFrame value */
    /* Set the TSF bit according to ETH TransmitStoreForward value */
    /* Set the TTC bit according to ETH TransmitThresholdControl value */
    /* Set the FEF bit according to ETH ForwardErrorFrames value */
    /* Set the FUF bit according to ETH ForwardUndersizedGoodFrames value */
    /* Set the RTC bit according to ETH ReceiveThresholdControl value */
    /* Set the OSF bit according to ETH SecondFrameOperate value */
    reg_val  = FGMAC_READ_REG32(base_addr, FGMAC_DMA_OP_OFFSET);
    reg_val &= FGMAC_DMA_OP_CLEAR_MASK;
    /*  TCP / IP  DT */
    reg_val &= ~FGMAC_DMA_OP_DT;

    /*  RSF */
    reg_val |= FGMAC_DMA_OP_RSF;

    /*  DFF */
    reg_val &= ~FGMAC_DMA_OP_DFF;

    /*  TSF */
    reg_val |= FGMAC_DMA_OP_TSF;

    /*  TTC */
    reg_val |= FGMAC_DMA_OP_TTC(7);

    /*  OSF */
    reg_val |= FGMAC_DMA_OP_OSF;
    FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_OP_OFFSET, reg_val);

    /* DMAFIFO FTF */
    ret = FGmacFlushTxFifo(base_addr, FGMAC_RETRY_TIMES);

    if (FGMAC_SUCCESS != ret)
    {
        printf("FGmac Flush Failed\r\n");
    }

    /* AXI  BLEN 16,8,4 */
    reg_val = (FGMAC_DMA_AXI_BUS_MOD_BLEN16 | FGMAC_DMA_AXI_BUS_MOD_BLEN8 | FGMAC_DMA_AXI_BUS_MOD_BLEN4);
    FGMAC_WRITE_REG32(base_addr, FGMAC_DMA_AXI_BUS_MOD_OFFSET, reg_val);

    return ret;
}
