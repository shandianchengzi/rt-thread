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
 * FilePath: fnand_hw.c
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:56:36
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#include "fnand_hw.h"
#include "fnand.h"



void FNandEnable(uintptr_t base_address)
{
    FNAND_SETBIT(base_address, FNAND_CTRL0_OFFSET, FNAND_CTRL0_EN_MASK); /*  */
}


void FNandHwReset(uintptr_t base_address)
{
    FNAND_WRITEREG(base_address, FNAND_INTRMASK_OFFSET, FNAND_INTRMASK_ALL_INT_MASK); /*  */
    FNAND_WRITEREG(base_address, FNAND_STATE_OFFSET, FNAND_STATE_ALL_BIT);      /*  */
    FNAND_WRITEREG(base_address, FNAND_ERROR_CLEAR_OFFSET, FNAND_ERROR_ALL_CLEAR);  /*  */
    FNAND_WRITEREG(base_address, FNAND_FIFO_FREE_OFFSET, FNAND_FIFO_FREE_MASK);     /* fifo */
    // FNAND_CLEARBIT(base_address,FNAND_CTRL0_OFFSET,FNAND_CTRL0_SPARE_SIZE_EN_MASK|FNAND_CTRL0_ECC_EN_MASK ); /* ECC spare size  */
}


void FNandHwInit(uintptr_t base_address, FNandInterMode inter_mode)
{
    // FNAND_WRITEREG(base_address, FNAND_CTRL1_OFFSET, FNAND_CTRL1_SAMPL_PHASE_MAKE(1UL)); /*  */
    FNAND_SETBIT(base_address, FNAND_CTRL1_OFFSET, FNAND_CTRL1_SAMPL_PHASE_MAKE(5UL));
    FNAND_CLEARBIT(base_address, FNAND_CTRL1_OFFSET, FNAND_CTRL1_ECC_DATA_FIRST_EN_MASK);

    // FNAND_SETBIT(base_address, FNAND_CTRL1_OFFSET, FNAND_CTRL1_ECC_DATA_FIRST_EN_MASK); /* ECC   */
    FNAND_WRITEREG(base_address, FNAND_INTERVAL_OFFSET, FNAND_INTERVAL_TIME_MAKE(1UL)); /*   */
    FNAND_WRITEREG(base_address, FNAND_FIFO_LEVEL0_FULL_OFFSET, FNAND_FIFO_LEVEL0_FULL_THRESHOLD_MASK & 4);   /*  1/2 full, default 0 */
    FNAND_WRITEREG(base_address, FNAND_FIFO_LEVEL1_EMPTY_OFFSET, FNAND_FIFO_LEVEL1_EMPTY_THRESHOLD_MASK & 4); /*  1/2 empty, default 0 */
    FNAND_WRITEREG(base_address, FNAND_FIFO_FREE_OFFSET, FNAND_FIFO_FREE_MASK);   /* fifo  */
    FNAND_WRITEREG(base_address, FNAND_ERROR_CLEAR_OFFSET, FNAND_ERROR_CLEAR_DSP_ERR_CLR_MASK); /*  */
    FNAND_WRITEREG(base_address, FNAND_CTRL0_OFFSET, FNAND_CTRL0_ECC_CORRECT_MAKE(1UL) | FNAND_CTRL0_INTER_MODE((unsigned long)(inter_mode))); /*  2  */
}