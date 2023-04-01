/**
  *******************************************************************************************************
  * @file    fm33lc0xx_fl_bstim32.c
  * @author  FMSH Application Team
  * @brief   Src file of BSTIM32 FL Module
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

/** @addtogroup BSTIM32
  * @{
  */

#ifdef FL_BSTIM32_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------------*/
/** @addtogroup BSTIM32_FL_Private_Macros
  * @{
  */

#define         IS_FL_BSTIM32_INSTANCE(INSTANCE)                    ((INSTANCE) == BSTIM32)

#define         IS_FL_BSTIM32_AUTORELOAD_MODE(__VALUE__)           (((__VALUE__) == FL_ENABLE)||\
                                                                    ((__VALUE__) == FL_DISABLE))

#define         IS_FL_BSTIM32_CLOCK_SRC(__VALUE__)                 (((__VALUE__) == FL_RCC_BSTIM32_CLK_SOURCE_APB2CLK)||\
                                                                    ((__VALUE__) == FL_RCC_BSTIM32_CLK_SOURCE_LSCLK)||\
                                                                    ((__VALUE__) == FL_RCC_BSTIM32_CLK_SOURCE_LPOSC)||\
                                                                    ((__VALUE__) == FL_RCC_BSTIM32_CLK_SOURCE_RCMF_PSC))

/**
  * @}
  */

/** @addtogroup BSTIM32_FL_EF_Init
  * @{
  */

/**
  * @brief  BSTIM32
  * @param  BSTIM32x 
  * @retval :
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_BSTIM32_DeInit(BSTIM32_Type *BSTIM32x)
{
    assert_param(IS_FL_BSTIM32_INSTANCE(BSTIM32x));
    /*  */
    FL_RCC_EnablePeripheralReset();
    /*  */
    FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_BSTIM32);
    FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_BSTIM32);
    /*  */
    FL_RCC_DisableGroup4BusClock(FL_RCC_GROUP4_BUSCLK_BSTIM32);
    FL_RCC_DisableGroup2OperationClock(FL_RCC_GROUP2_OPCLK_BSTIM32);
    /*  */
    FL_RCC_DisablePeripheralReset();
    return FL_PASS;
}
/**
  * @brief  BSTIM32
  * @param  BSTIM32x    
  * @param  initStruct   @ref FL_BSTIM32_InitTypeDef 
  *
  * @retval :
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_BSTIM32_Init(BSTIM32_Type *BSTIM32x, FL_BSTIM32_InitTypeDef *initStruct)
{
    uint32_t i = 4000;
    /*  */
    assert_param(IS_FL_BSTIM32_INSTANCE(BSTIM32x));
    assert_param(IS_FL_BSTIM32_CLOCK_SRC(initStruct->clockSource));
    assert_param(IS_FL_BSTIM32_AUTORELOAD_MODE(initStruct->autoReloadState));
    /*  */
    FL_RCC_EnableGroup4BusClock(FL_RCC_GROUP4_BUSCLK_BSTIM32);
    /*  */
    FL_RCC_SetBSTIM32ClockSource(initStruct->clockSource);
    FL_RCC_EnableGroup2OperationClock(FL_RCC_GROUP2_OPCLK_BSTIM32);
    /*  */
    FL_BSTIM32_WritePrescaler(BSTIM32x, initStruct->prescaler);
    /*  */
    FL_BSTIM32_EnableUpdateEvent(BSTIM32x);
    FL_BSTIM32_WriteAutoReload(BSTIM32x, initStruct->autoReload);
    if(initStruct->autoReloadState == FL_ENABLE)
    {
        FL_BSTIM32_EnableARRPreload(BSTIM32x);
    }
    else
    {
        FL_BSTIM32_DisableARRPreload(BSTIM32x);
    }
    /*  */
    FL_BSTIM32_GenerateUpdateEvent(BSTIM32x);
    while((!FL_BSTIM32_IsActiveFlag_Update(BSTIM32x))&&i)
    {
        i--;
    }
    /*UIFUG*/
    FL_BSTIM32_ClearFlag_Update(BSTIM32x);
    return FL_PASS;
}

/**
  * @brief   @ref FL_BSTIM32_InitTypeDef 
  * @param  initStruct  @ref FL_BSTIM32_InitTypeDef 
  *
  * @retval None
  */
void FL_BSTIM32_StructInit(FL_BSTIM32_InitTypeDef *initStruct)
{
    initStruct->prescaler         = 0;
    initStruct->autoReload        = 0xFFFFFFFF;
    initStruct->autoReloadState   = FL_ENABLE;
    initStruct->clockSource       = FL_RCC_BSTIM32_CLK_SOURCE_APB2CLK;
}

/**
  * @}
  */

#endif /* FL_BSTIM32_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
