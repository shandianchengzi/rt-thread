/**
  ****************************************************************************************************
  * @file    fm33lc0xx_fl_wwdt.c
  * @author  FMSH Application Team
  * @brief   Src file of WWDT FL Module
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

/** @addtogroup WWDT
  * @{
  */

#ifdef FL_WWDT_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup WWDT_FL_Private_Macros
  * @{
  */

#define         IS_WWDT_INSTANCE(INTANCE)                ((INTANCE) == WWDT)

#define         IS_FL_WWDT_OVERFLOWPERIOD(__VALUE__)            (((__VALUE__) == FL_WWDT_PERIOD_1CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_4CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_16CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_64CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_128CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_256CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_512CNT)||\
                                                                 ((__VALUE__) == FL_WWDT_PERIOD_1024CNT))
/**
  * @}
  */

/** @addtogroup WWDT_FL_EF_Init
  * @{
  */

/**
  * @brief  WWDT
  *
  * @param  WWDTx 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_WWDT_DeInit(WWDT_Type *WWDTx)
{
    assert_param(IS_WWDT_INSTANCE(WWDTx));
    return FL_PASS;
}

/**
  * @brief   WWDT_InitStruct.
  *
  * @note   WWTD
  *
  * @param  WWDTx 
  *
  * @param  WWDT_InitStruct  @ref FL_WWDT_InitTypeDef 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_WWDT_Init(WWDT_Type *WWDTx, FL_WWDT_InitTypeDef *WWDT_InitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /*  */
    assert_param(IS_WWDT_INSTANCE(WWDTx));
    assert_param(IS_FL_WWDT_OVERFLOWPERIOD(WWDT_InitStruct->overflowPeriod));
    /*  */
    FL_RCC_EnableGroup2BusClock(FL_RCC_GROUP2_BUSCLK_WWDT);
    /*  */
    FL_WWDT_SetPeriod(WWDTx, WWDT_InitStruct->overflowPeriod);
    /*  */
    FL_WWDT_Enable(WWDTx);
    return status;
}

/**
  * @brief   WWDT_InitStruct 
  *
  * @param  WWDT_InitStruct  @ref FL_WWDT_InitTypeDef 
  *
  * @retval None
  */
void FL_WWDT_StructInit(FL_WWDT_InitTypeDef *WWDT_InitStruct)
{
    /*  */
    WWDT_InitStruct->overflowPeriod = FL_WWDT_PERIOD_1024CNT;
}

/**
  * @}
  */

#endif /* FL_WWDT_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
