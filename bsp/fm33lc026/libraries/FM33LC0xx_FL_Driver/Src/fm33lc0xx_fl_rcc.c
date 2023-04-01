/**
  ****************************************************************************************************
  * @file    fm33lc0xx_fl_rcc.c
  * @author  FMSH Application Team
  * @brief   Src file of RCC FL Module
  ****************************************************************************************************
  * @attention
  *
  * Copyright (c) [2021] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under Mulan PSL v2.
  * You can use this software according to the terms and conditions of the Mulan PSL v2.
  * You may obtain a copy of Mulan PSL v2 at:
  *          http://license.coscl.org.cn/MulanPSL2
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
  * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
  * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
  * See the Mulan PSL v2 for more details.
  *
  ****************************************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "fm33lc0xx_fl.h"

/** @addtogroup FM33LC0XX_FL_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

#ifdef FL_RCC_DRIVER_ENABLED

/** @addtogroup RCC_FL_EF_Operation
  * @{
  */

/**
  * @brief  USB
  *
  * @retval USBSYSCLK(Hz)
  */
uint32_t FL_RCC_GetUSBClockFreqToSysclk(void)
{
    if(FL_RCC_GetUSBClockOutput() == FL_RCC_USB_CLK_OUT_48M)
    {
        return 48000000;
    }
    else
    {
        return 60000000;
    }
}

/**
  * @brief  SYSCLK
  *
  * @note    @ref XTHF_VALUE 
  *
  * @retval (Hz)
  *
  */
uint32_t FL_RCC_GetSystemClockFreq(void)
{
    uint32_t frequency = 0;
    /*  */
    switch(FL_RCC_GetSystemClockSource())
    {
        /* RCHF */
        case FL_RCC_SYSTEM_CLK_SOURCE_RCHF:
            /* RCHF8MHz ,1624M */
            frequency = FL_RCC_GetRCHFClockFreq();
            break;
        /* XTHF */
        case FL_RCC_SYSTEM_CLK_SOURCE_XTHF:
            frequency = XTHFClock;
            break;
        /* PLL */
        case FL_RCC_SYSTEM_CLK_SOURCE_PLL:
            frequency = FL_RCC_GetPLLClockFreq();
            break;
        /* RCMF */
        case FL_RCC_SYSTEM_CLK_SOURCE_RCMF_PSC:
            /* RCMF */
            frequency = FL_RCC_GetRCMFClockFreq();
            break;
        /* LSCLK */
        case FL_RCC_SYSTEM_CLK_SOURCE_LSCLK:
            #ifdef USE_LSCLK_CLOCK_SRC_LPOSC
            frequency = 32000;
            #else
            frequency = XTLFClock;
            #endif
            break;
        /* USB BCK */
        case FL_RCC_SYSTEM_CLK_SOURCE_USBCLK:
            /* USB */
            frequency = FL_RCC_GetUSBClockFreqToSysclk();
            break;
        /* LPOSC */
        case FL_RCC_SYSTEM_CLK_SOURCE_LPOSC:
            frequency = 32000;
            break;
        default:
            frequency = FL_RCC_GetRCHFClockFreq();
            break;
    }
    return frequency;
}
/**
  * @brief  AHB
  *
  * @retval AHB(Hz)
  *
  */
uint32_t FL_RCC_GetAHBClockFreq(void)
{
    uint32_t frequency = 0;
    /* AHBAHB */
    switch(FL_RCC_GetAHBPrescaler())
    {
        case FL_RCC_AHBCLK_PSC_DIV1:
            frequency = FL_RCC_GetSystemClockFreq();
            break;
        case FL_RCC_AHBCLK_PSC_DIV2:
            frequency = FL_RCC_GetSystemClockFreq() / 2;
            break;
        case FL_RCC_AHBCLK_PSC_DIV4:
            frequency = FL_RCC_GetSystemClockFreq() / 4;
            break;
        case FL_RCC_AHBCLK_PSC_DIV8:
            frequency = FL_RCC_GetSystemClockFreq() / 8;
            break;
        case FL_RCC_AHBCLK_PSC_DIV16:
            frequency = FL_RCC_GetSystemClockFreq() / 16;
            break;
        default:
            frequency = FL_RCC_GetSystemClockFreq();
            break;
    }
    return frequency;
}

/**
  * @brief  APB1
  *
  * @retval APB1(Hz)
  *
  */
uint32_t FL_RCC_GetAPB1ClockFreq(void)
{
    uint32_t frequency = 0;
    /* APB1APBAHB */
    switch(FL_RCC_GetAPB1Prescaler())
    {
        case FL_RCC_APB1CLK_PSC_DIV1:
            frequency = FL_RCC_GetAHBClockFreq();
            break;
        case FL_RCC_APB1CLK_PSC_DIV2:
            frequency = FL_RCC_GetAHBClockFreq() / 2;
            break;
        case FL_RCC_APB1CLK_PSC_DIV4:
            frequency = FL_RCC_GetAHBClockFreq() / 4;
            break;
        case FL_RCC_APB1CLK_PSC_DIV8:
            frequency = FL_RCC_GetAHBClockFreq() / 8;
            break;
        case FL_RCC_APB1CLK_PSC_DIV16:
            frequency = FL_RCC_GetAHBClockFreq() / 16;
            break;
        default:
            frequency = FL_RCC_GetAHBClockFreq();
            break;
    }
    return frequency;
}
/**
  * @brief  APB2
  *
  * @retval APB2(Hz)
  *
  */
uint32_t FL_RCC_GetAPB2ClockFreq(void)
{
    uint32_t frequency = 0;
    /* APB2APBAHB */
    switch(FL_RCC_GetAPB2Prescaler())
    {
        case FL_RCC_APB2CLK_PSC_DIV1:
            frequency = FL_RCC_GetAHBClockFreq();
            break;
        case FL_RCC_APB2CLK_PSC_DIV2:
            frequency = FL_RCC_GetAHBClockFreq() / 2;
            break;
        case FL_RCC_APB2CLK_PSC_DIV4:
            frequency = FL_RCC_GetAHBClockFreq() / 4;
            break;
        case FL_RCC_APB2CLK_PSC_DIV8:
            frequency = FL_RCC_GetAHBClockFreq() / 8;
            break;
        case FL_RCC_APB2CLK_PSC_DIV16:
            frequency = FL_RCC_GetAHBClockFreq() / 16;
            break;
        default:
            frequency = FL_RCC_GetAHBClockFreq();
            break;
    }
    return frequency;
}
/**
  * @brief  RCMF
  *
  * @retval RCMF(Hz)
  *
  */
uint32_t FL_RCC_GetRCMFClockFreq(void)
{
    uint32_t frequency = 0;
    switch(FL_RCC_RCMF_GetPrescaler())
    {
        case FL_RCC_RCMF_PSC_DIV1:
            frequency = 4000000;
            break;
        case FL_RCC_RCMF_PSC_DIV4:
            frequency = 1000000;
            break;
        case FL_RCC_RCMF_PSC_DIV8:
            frequency = 500000;
            break;
        case FL_RCC_RCMF_PSC_DIV16:
            frequency = 250000;
            break;
        default:
            frequency = 4000000;
            break;
    }
    return frequency;
}
/**
  * @brief  RCHF
  *
  * @retval RCHF(Hz)
  *
  */
uint32_t FL_RCC_GetRCHFClockFreq(void)
{
    uint32_t frequency = 0;
    switch(FL_RCC_RCHF_GetFrequency())
    {
        case FL_RCC_RCHF_FREQUENCY_8MHZ:
            frequency = 8000000;
            break;
        case FL_RCC_RCHF_FREQUENCY_16MHZ:
            frequency = 16000000;
            break;
        case FL_RCC_RCHF_FREQUENCY_24MHZ:
            frequency = 24000000;
            break;
        default:
            frequency = 8000000;
            break;
    }
    return frequency;
}
/**
  * @brief  PLL
  *
  * @retval PLL(Hz)
  *
  */
uint32_t FL_RCC_GetPLLClockFreq(void)
{
    uint32_t frequency = 0;
    uint32_t multiplier = 0;
    /* PLL */
    switch(FL_RCC_PLL_GetClockSource())
    {
        case FL_RCC_PLL_CLK_SOURCE_RCHF:
            /* RCHF */
            frequency = FL_RCC_GetRCHFClockFreq();
            break;
        case FL_RCC_PLL_CLK_SOURCE_XTHF:
            frequency = XTHFClock;
            break;
        default:
            frequency = FL_RCC_GetRCHFClockFreq();
            break;
    }
    /* PLL */
    switch(FL_RCC_PLL_GetPrescaler())
    {
        case FL_RCC_PLL_PSC_DIV1:
            break;
        case FL_RCC_PLL_PSC_DIV2:
            frequency /= 2;
            break;
        case FL_RCC_PLL_PSC_DIV4:
            frequency /= 4;
            break;
        case FL_RCC_PLL_PSC_DIV8:
            frequency /= 8;
            break;
        case FL_RCC_PLL_PSC_DIV12:
            frequency /= 12;
            break;
        case FL_RCC_PLL_PSC_DIV16:
            frequency /= 16;
            break;
        case FL_RCC_PLL_PSC_DIV24:
            frequency /= 24;
            break;
        case FL_RCC_PLL_PSC_DIV32:
            frequency /= 32;
            break;
        default:
            break;
    }
    multiplier = FL_RCC_PLL_ReadMultiplier() + 1;
    frequency *= multiplier;
    return frequency;
}

/**
  * @}
  */

#endif /* FL_RCC_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
