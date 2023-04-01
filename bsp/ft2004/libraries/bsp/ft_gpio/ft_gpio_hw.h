/*
*@:Copyright(c)2021PhytiumInformationTechnology,Inc.
*
*SPDX-License-Identifier:Apache-2.0.
*
 * @Date: 2021-04-27 17:55:22
 * @LastEditTime: 2021-04-28 08:39:20
 * @Description: This files is for
 *
 * @ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#ifndef FT_BSP_GPIO_HW_H
#define FT_BSP_GPIO_HW_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ft_types.h"
#include "ft_io.h"

#define GPIO_CTRL_ID_0 0
#define GPIO_CTRL_ID_1 1

/* base address of gpio register */
#define GPIO_CTRL0_PA_BASE 0x28004000
#define GPIO_CTRL1_PA_BASE 0x28005000
#define GPIO_GROUPA_OFFSET 0x0
#define GPIO_GROUPB_OFFSET 0xc

/* offset of register map */
#define GPIO_SWPORTA_DR 0x00  //A 
#define GPIO_SWPORTA_DDR 0x04 //A 
#define GPIO_EXT_PORTA 0x08   //A 

#define GPIO_SWPORTB_DR 0x0c  //B 
#define GPIO_SWPORTB_DDR 0x10 //B 
#define GPIO_EXT_PORTB 0x14   //B 

#define GPIO_INTEN 0x18         //A 
#define GPIO_INTMASK 0x1c       //A 
#define GPIO_INTTYPE_LEVEL 0x20 //A 
#define GPIO_INT_POLARITY 0x24  //A 
#define GPIO_INTSTATUS 0x28     //A 
#define GPIO_RAW_INTSTATUS 0x2c //A 

#define GPIO_LS_SYNC 0x30   //
#define GPIO_DEBOUNCE 0x34  //
#define GPIO_PORTA_EOI 0x38 //A 

/* misc marco */
#define GPIO_GROUP_A 0
#define GPIO_OFF 0
#define GPIO_ON 1
#define GPIO_INPUT 0
#define GPIO_OUTPUT 1

    inline static u32 FGpio_GetBaseAddr(FT_IN u32 ctrlId, FT_IN u32 groupId)
    {
        static const u32 CtrlAddr[2] = {GPIO_CTRL0_PA_BASE, GPIO_CTRL1_PA_BASE};
        static const u32 GroupOff[2] = {GPIO_GROUPA_OFFSET, GPIO_GROUPB_OFFSET};
        return CtrlAddr[ctrlId] + GroupOff[groupId];
    }

/**
 * @name: FGpio_WriteReg
 * @msg:  write gpio register
 * @param {u32} BaseAddress base addr of i2c
 * @param {u32} RegOffset   addr offset of i2c register
 * @param {u32} RegisterValue val to be write into register
 * @return {void}
 */
#define FGpioA_WriteReg(ctrlId, RegOffset, RegisterValue) Ft_out32(FGpio_GetBaseAddr(ctrlId, GPIO_GROUP_A) + (u32)RegOffset, (u32)RegisterValue)

/**
 * @name: FGpio_ReadReg
 * @msg:  read gpio register
 * @param {u32} BaseAddress base addr of i2c
 * @param {u32} RegOffset   addr offset of i2c register
 * @return {u32} val read from register
 */
#define FGpioA_ReadReg(ctrlId, RegOffset) Ft_in32(FGpio_GetBaseAddr(ctrlId, GPIO_GROUP_A) + (u32)RegOffset)

#ifdef __cplusplus
}
#endif

#endif
