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
 * FilePath: fsdmmc_dma.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:49:31
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
#include "fsdmmc_dma.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define FSDMMC_DEBUG_TAG "FSDMMC-DMA"
#define FSDMMC_ERROR(format, ...)   FT_DEBUG_PRINT_E(FSDMMC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FSDMMC_WARN(format, ...)    FT_DEBUG_PRINT_W(FSDMMC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FSDMMC_INFO(format, ...)    FT_DEBUG_PRINT_I(FSDMMC_DEBUG_TAG, format, ##__VA_ARGS__)
#define FSDMMC_DEBUG(format, ...)   FT_DEBUG_PRINT_D(FSDMMC_DEBUG_TAG, format, ##__VA_ARGS__)

/************************** Function Prototypes ******************************/

/************************** Variable Definitions *****************************/

/*****************************************************************************/
/**
 * @name: FSdmmcSetReadDMA
 * @msg: DMA
 * @return {*}
 * @param {uintptr} base_addr FSDMMC 
 * @param {uintptr} card_addr 
 * @param {u32} blk_cnt block
 * @param {void} *buf_p 
 */
void FSdmmcSetReadDMA(uintptr base_addr, uintptr card_addr, u32 blk_cnt, void *buf_p)
{
    FASSERT(buf_p);

    u32 dsth = UPPER_32_BITS((uintptr)buf_p); /* DMA--> sd read buf */
    u32 dstl = LOWER_32_BITS((uintptr)buf_p);
    u32 srch = UPPER_32_BITS((uintptr)card_addr); /* DMA --> sd card */
    u32 srcl = LOWER_32_BITS((uintptr)card_addr);

    FSDMMC_INFO("sd card: 0x%x:0x%x ==> mem space: 0x%x:0x%x",
                srch, srcl, dsth, dstl);

    FSDMMC_INFO("read %d blks from 0x%x", blk_cnt, card_addr);

    /* DMA  */
    FSDMMC_SET_BIT(base_addr, FSDMMC_SOFTWARE_RESET_REG_OFFSET, FSDMMC_SOFTWARE_RESET_BDRST);
    FSDMMC_CLR_BIT(base_addr, FSDMMC_SOFTWARE_RESET_REG_OFFSET, FSDMMC_SOFTWARE_RESET_BDRST);

    /*  */
    FSDMMC_WRITE_REG(base_addr, FSDMMC_BLK_CNT_REG_OFFSET, blk_cnt);

    /*  */
    FSdmmcClearErrorInterruptStatus(base_addr);
    FSdmmcClearBDInterruptStatus(base_addr);
    FSdmmcClearNormalInterruptStatus(base_addr);

    FSDMMC_INFO("base addr: 0x%x buf_p: %p", base_addr, buf_p);

    /* DMA 4  cycle
     4B- 4B-SD  4B- SD  4B */
    FSDMMC_WRITE_REG(base_addr, FSDMMC_DAT_IN_M_RX_BD_REG_OFFSET, dstl);
    FSDMMC_WRITE_REG(base_addr, FSDMMC_DAT_IN_M_RX_BD_REG_OFFSET, dsth);
    FSDMMC_WRITE_REG(base_addr, FSDMMC_DAT_IN_M_RX_BD_REG_OFFSET, srcl);
    FSDMMC_WRITE_REG(base_addr, FSDMMC_DAT_IN_M_RX_BD_REG_OFFSET, srch);


    FSDMMC_INFO("DMA READ START!");
    return;
}

/**
 * @name: FSdmmcSetWriteDMA
 * @msg: DMA
 * @return {*}
 * @param {uintptr} base_addr FSDMMC 
 * @param {uintptr} card_addr 
 * @param {u32} blk_cnt block
 * @param {void} *buf_p 
 */
void FSdmmcSetWriteDMA(uintptr base_addr, uintptr card_addr, u32 blk_cnt, const void *buf_p)
{
    FASSERT(buf_p);
    u32 srch = UPPER_32_BITS((uintptr)buf_p); /* DMA--> sd read buf */
    u32 srcl = LOWER_32_BITS((uintptr)buf_p);
    u32 dsth = UPPER_32_BITS((uintptr)card_addr); /* DMA --> sd card */
    u32 dstl = LOWER_32_BITS((uintptr)card_addr);

    FSDMMC_INFO("mem space: 0x%x:0x%x ==> sd card: 0x%x:0x%x",
                srch, srcl, dsth, dstl);

    FSDMMC_INFO("write %d blks from 0x%x", blk_cnt, card_addr);

    /* DMA  */
    FSDMMC_SET_BIT(base_addr, FSDMMC_SOFTWARE_RESET_REG_OFFSET, FSDMMC_SOFTWARE_RESET_BDRST);
    FSDMMC_CLR_BIT(base_addr, FSDMMC_SOFTWARE_RESET_REG_OFFSET, FSDMMC_SOFTWARE_RESET_BDRST);

    /*  */
    FSDMMC_WRITE_REG(base_addr, FSDMMC_BLK_CNT_REG_OFFSET, blk_cnt);

    /*  */
    FSdmmcClearErrorInterruptStatus(base_addr);
    FSdmmcClearBDInterruptStatus(base_addr);
    FSdmmcClearNormalInterruptStatus(base_addr);

    /* DMA 4  cycle
     4B- 4B-SD  4B- SD  4B */
    FSDMMC_WRITE_REG(base_addr, FSDMMC_DAT_IN_M_TX_BD_REG_OFFSET, srcl);
    FSDMMC_WRITE_REG(base_addr, FSDMMC_DAT_IN_M_TX_BD_REG_OFFSET, srch);
    FSDMMC_WRITE_REG(base_addr, FSDMMC_DAT_IN_M_TX_BD_REG_OFFSET, dstl);
    FSDMMC_WRITE_REG(base_addr, FSDMMC_DAT_IN_M_TX_BD_REG_OFFSET, dsth);

    FSDMMC_INFO("DMA WRITE START!");
    return;
}