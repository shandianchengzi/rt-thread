/**
  *******************************************************************************************************
  * @file    fm33lc0xx_fl_rtc.c
  * @author  FMSH Application Team
  * @brief   Src file of RTC FL Module
  *******************************************************************************************************
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
  *******************************************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "fm33lc0xx_fl.h"

/** @addtogroup FM33LC0XX_FL_Driver
  * @{
  */

/** @addtogroup RTC
  * @{
  */

#ifdef FL_RTC_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup RTC_FL_Private_Macros
  * @{
  */

#define IS_RTC_INSTANCE(RTCx)                     ((RTCx) == RTC)

/**
  * @}
  */

/** @addtogroup RTC_FL_EF_Init
  * @{
  */

/**
  * @brief  RTC
  * @param  RTCx 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_RTC_DeInit(RTC_Type *RTCx)
{
    FL_ErrorStatus result = FL_PASS;
    /* Check the parameters */
    assert_param(IS_RTC_INSTANCE(RTCx));
    RTCx->IER       = 0x00000000U;
    RTCx->WER       = 0x00000000U;
    RTCx->ADJUST    = 0x00000000U;
    RTCx->ADSIGN    = 0x00000000U;
    RTCx->ALARM     = 0x00000000U;
    RTCx->BCDDAY    = 0x00000000U;
    RTCx->BCDHOUR   = 0x00000000U;
    RTCx->BCDMIN    = 0x00000000U;
    RTCx->BCDMONTH  = 0x00000000U;
    RTCx->BCDSEC    = 0x00000000U;
    RTCx->BCDWEEK   = 0x00000000U;
    RTCx->BCDYEAR   = 0x00000000U;
    RTCx->SBSCNT    = 0x00000000U;
    RTCx->TMSEL     = 0x00000000U;
    RTCx->WER       = 0x00000000U;
    return result;
}

/**
  * @brief  RTC
  * @param  RTCx 
  * @param  initStruct  @ref FL_RTC_InitTypeDef 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_RTC_Init(RTC_Type *RTCx, FL_RTC_InitTypeDef *initStruct)
{
    /*  */
    assert_param(IS_RTC_INSTANCE(RTCx));
    /*  */
    FL_RCC_EnableGroup1BusClock(FL_RCC_GROUP1_BUSCLK_RTC);
    /*  */
    FL_RTC_ConfigTime(RTCx, initStruct);
    return FL_PASS;
}

/**
  * @brief  RTC
  * @param  RTCx 
  * @param  initStruct  @ref FL_RTC_InitTypeDef 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_RTC_ConfigTime(RTC_Type *RTCx, FL_RTC_InitTypeDef *initStruct)
{
    /*  */
    FL_RTC_WriteEnable(RTCx);
    /*  */
    FL_RTC_WriteSecond(RTCx, initStruct->second);
    /*  */
    FL_RTC_WriteMinute(RTCx, initStruct->minute);
    /*  */
    FL_RTC_WriteHour(RTCx, initStruct->hour);
    /*  */
    FL_RTC_WriteDay(RTCx, initStruct->day);
    /*  */
    FL_RTC_WriteWeek(RTCx, initStruct->week);
    /*  */
    FL_RTC_WriteMonth(RTCx, initStruct->month);
    /*  */
    FL_RTC_WriteYear(RTCx, initStruct->year);
    /*  */
    FL_RTC_WriteDisable(RTCx);
    return FL_PASS;
}

/**
  * @brief  RTC
  * @param  RTCx 
  * @param  initStruct  @ref FL_RTC_InitTypeDef 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_RTC_GetTime(RTC_Type *RTCx, FL_RTC_InitTypeDef *initStruct)
{
    /*  */
    initStruct->second = FL_RTC_ReadSecond(RTCx);
    /*  */
    initStruct->minute  = FL_RTC_ReadMinute(RTCx);
    /*  */
    initStruct->hour = FL_RTC_ReadHour(RTCx);
    /*  */
    initStruct->day = FL_RTC_ReadDay(RTCx);
    /*  */
    initStruct->week = FL_RTC_ReadWeek(RTCx);
    /*  */
    initStruct->month = FL_RTC_ReadMonth(RTCx);
    /*  */
    initStruct->year = FL_RTC_ReadYear(RTCx);
    return FL_PASS;
}

/**
  * @brief   @ref FL_RTC_InitTypeDef 
  * @param  initStruct  @ref FL_RTC_InitTypeDef 
  *
  * @retval None
  */
void FL_RTC_StructInit(FL_RTC_InitTypeDef *initStruct)
{
    initStruct->year    = 0x00;
    initStruct->month   = 0x00;
    initStruct->day     = 0x00;
    initStruct->week    = 0x00;
    initStruct->hour    = 0x00;
    initStruct->minute  = 0x00;
    initStruct->second  = 0x00;
}

/**
  * @}
  */

#endif /* FL_RTC_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
