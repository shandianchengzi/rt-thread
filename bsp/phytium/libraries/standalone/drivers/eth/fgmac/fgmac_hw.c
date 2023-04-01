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
 * FilePath: fgmac_hw.c
 * Date: 2022-04-06 14:46:52
 * LastEditTime: 2022-04-06 14:46:58
 * Description: This file is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#include "fassert.h"
#include "fdebug.h"

#include "fgmac.h"
#include "fgmac_hw.h"


/***************************** Include Files *********************************/

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define FGMAC_DEBUG_TAG "FGMAC-HW"
#define FGMAC_ERROR(format, ...)   FT_DEBUG_PRINT_E(FGMAC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGMAC_WARN(format, ...)    FT_DEBUG_PRINT_W(FGMAC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGMAC_INFO(format, ...)    FT_DEBUG_PRINT_I(FGMAC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FGMAC_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FGMAC_DEBUG_TAG, format, ##__VA_ARGS__)

/************************** Function Prototypes ******************************/

/**
 * @name: FGmacGetMacAddr
 * @msg: FGMACMAC
 * @return {*}
 * @param {uintptr} base_addr 
 * @param {FGmacMacAddr} mac_addr MAC
 */
void FGmacGetMacAddr(uintptr base_addr, FGmacMacAddr mac_addr)
{
    u32 mac_high = FGMAC_READ_REG32(base_addr, FGMAC_MAC_ADDR0_UPPER16BIT_OFFSET);
    u32 mac_low = FGMAC_READ_REG32(base_addr, FGMAC_MAC_ADDR0_LOWER32BIT_OFFSET);

    /* get lower 32 bits of mac addr */
    mac_addr[0] = (u8)(mac_low & 0xff);
    mac_addr[1] = (u8)((mac_low >> 8) & 0xff);
    mac_addr[2] = (u8)((mac_low >> 16) & 0xff);
    mac_addr[3] = (u8)((mac_low >> 24) & 0xff);

    /* get upper 16 bits of mac addr */
    mac_addr[4] = (u8)(mac_high & 0xff);
    mac_addr[5] = (u8)((mac_high >> 8) & 0xff);

    return;
}

/**
 * @name: FGmacSetMacAddr
 * @msg: FGMACMAC
 * @return {*}
 * @param {uintptr} base_addr 
 * @param {FGmacMacAddr} mac_addr MAC
 */
void FGmacSetMacAddr(uintptr base_addr, const FGmacMacAddr mac_addr)
{
    u32 reg_val;

    reg_val = ((u32)mac_addr[5] << 8) | (u32)mac_addr[4];
    FGMAC_WRITE_REG32(base_addr, FGMAC_MAC_ADDR0_UPPER16BIT_OFFSET, reg_val);
    reg_val = ((u32)mac_addr[3] << 24) | ((u32)mac_addr[2] << 16) | ((u32)mac_addr[1] << 8) | mac_addr[0];
    FGMAC_WRITE_REG32(base_addr, FGMAC_MAC_ADDR0_LOWER32BIT_OFFSET, reg_val);

    return;
}

/**
 * @name: FGmacSoftwareReset
 * @msg: FGMAC    GMac   DMA  
 * @return {*}
 * @param {uintptr} base_addr 
 * @param {int} timeout 
 */
FError FGmacSoftwareReset(uintptr base_addr, int timeout)
{
    FASSERT(timeout > 1); /*  */
    u32 reg_val;

    FGMAC_SET_REG32(base_addr, FGMAC_DMA_BUS_MODE_OFFSET, FGMAC_DMA_BUS_SWR); /*1  MAC DMA  GMAC 0*/
    do
    {
        reg_val = FGMAC_READ_REG32(base_addr, FGMAC_DMA_BUS_MODE_OFFSET);
    }
    while ((reg_val & FGMAC_DMA_BUS_SWR) && (--timeout > 0));   /*swr10   */

    if ((0 >= timeout) && (reg_val & FGMAC_DMA_BUS_SWR))
    {
        FGMAC_ERROR("reset timeout, please check phy connection!!!");
        return FGMAC_ERR_TIMEOUT;
    }

    return FGMAC_SUCCESS;
}

FError FGmacFlushTxFifo(uintptr base_addr, int timeout)
{
    FASSERT(timeout > 1); /*  */
    u32 reg_val;
    FGMAC_SET_REG32(base_addr, FGMAC_DMA_OP_OFFSET, FGMAC_DMA_OP_FTF);

    do
    {
        reg_val = FGMAC_READ_REG32(base_addr, FGMAC_DMA_OP_OFFSET);
    }
    while ((reg_val & FGMAC_DMA_OP_FTF) && (--timeout > 0));

    if ((0 >= timeout) && (reg_val & FGMAC_DMA_OP_FTF))
    {
        FGMAC_ERROR("flush tx fifo timeout !!!");
        return FGMAC_ERR_TIMEOUT;
    }

    return FGMAC_SUCCESS;
}

/**
 * @name: FGmacPhyWaitBusBusy
 * @msg: wait phy gmii is not busy
 * @param {uintptr} base_addr, base address of FGmac controller register
 * @param {int} timeout, wait timeout
 * @return err code information, FGMAC_SUCCESS indicates successothers indicates failed
 */
FError FGmacPhyWaitBusBusy(uintptr base_addr, int timeout)
{
    u32 reg_val;

    /* Check for the Busy flag */
    do
    {
        reg_val = FGMAC_READ_REG32(base_addr, FGMAC_GMII_ADDR_OFFSET);
    }
    while ((FGMAC_MII_ADDR_GB & reg_val) && (0 <= --timeout));

    if (0 >= timeout)
    {
        FGMAC_ERROR("timeout when wait GMII timeout");
        return FGMAC_ERR_TIMEOUT;
    }

    return FGMAC_SUCCESS;
}