/**
  *******************************************************************************************************
  * @file    fm33lc0xx_fl_opa.c
  * @author  FMSH Application Team
  * @brief   Src file of OPA FL Module
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

/** @addtogroup OPA
  * @{
  */

#ifdef FL_OPA_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup OPA_FL_Private_Macros
  * @{
  */

#define         IS_OPA_ALL_INSTANCE(INTENCE)               (((INTENCE) == OPA1)||\
                                                            ((INTENCE) == OPA2))

#define         IS_FL_OPA_INP_CHANNAL(__VALUE__)           (((__VALUE__) == FL_OPA_INP_SOURCE_INP1)||\
                                                            ((__VALUE__) == FL_OPA_INP_SOURCE_INP2))


#define         IS_FL_OPA_INN_CHANNAL(__VALUE__)           (((__VALUE__) == FL_OPA_INN_SOURCE_INN1)||\
                                                            ((__VALUE__) == FL_OPA_INN_SOURCE_INN2)||\
                                                            ((__VALUE__) == FL_OPA_INN_SOURCE_VREF)||\
                                                            ((__VALUE__) == FL_OPA_INN_SOURCE_THREE_QUARTERS_VREF)||\
                                                            ((__VALUE__) == FL_OPA_INN_SOURCE_HALF_VREF)||\
                                                            ((__VALUE__) == FL_OPA_INN_SOURCE_ONE_QUARTER_VREF)||\
                                                            ((__VALUE__) == FL_OPA_INN_SOURCE_ONE_EIGHTH_VREF))

#define         IS_FL_OPA_MODE(__VALUE__)                  (((__VALUE__) == FL_OPA_MODE_STANDALONE)||\
                                                            ((__VALUE__) == FL_OPA_MODE_COMPARATOR)||\
                                                            ((__VALUE__) == FL_OPA_MODE_PGA)||\
                                                            ((__VALUE__) == FL_OPA_MODE_BUFFER))

#define         IS_FL_OPA_DIGITALFILTER(__VALUE__)         (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_OPA_NEGTIVE_TO_PIN(__VALUE__)        (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_OPA_LOW_POWER_MODE(__VALUE__)        (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_OPA_GAIN(__VALUE__)                  (((__VALUE__) == FL_OPA_GAIN_X2)||\
                                                            ((__VALUE__) == FL_OPA_GAIN_X4)||\
                                                            ((__VALUE__) == FL_OPA_GAIN_X8)||\
                                                            ((__VALUE__) == FL_OPA_GAIN_X16))

/**
  * @}
  */

/** @addtogroup OPA_FL_EF_Init
  * @{
  */

/**
  * @brief  OPA
  * @param  OPAx 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_OPA_DeInit(OPA_Type *OPAx)
{
    /*  */
    assert_param(IS_OPA_ALL_INSTANCE(OPAx));
    /*  */
    FL_RCC_EnablePeripheralReset();
    /*  */
    FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_OPA);
    FL_RCC_DisableResetAPB2Peripheral(FL_RCC_RSTAPB_OPA);
    /*  */
    FL_RCC_DisableGroup1BusClock(FL_RCC_GROUP1_BUSCLK_ANAC);
    /*  */
    FL_RCC_DisablePeripheralReset();
    return FL_PASS;
}

/**
  * @brief  OPA
  *
  * @param  OPAx  
  * @param  initStruct  @ref FL_OPA_InitTypeDef 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_OPA_Init(OPA_Type *OPAx, FL_OPA_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /*  */
    assert_param(IS_OPA_ALL_INSTANCE(OPAx));
    assert_param(IS_FL_OPA_INP_CHANNAL(initStruct->INP));
    assert_param(IS_FL_OPA_INN_CHANNAL(initStruct->INN));
    assert_param(IS_FL_OPA_MODE(initStruct->mode));
    assert_param(IS_FL_OPA_DIGITALFILTER(initStruct->digitalFilter));
    assert_param(IS_FL_OPA_NEGTIVE_TO_PIN(initStruct->negtiveToPin));
    assert_param(IS_FL_OPA_LOW_POWER_MODE(initStruct->lowPowermode));
    assert_param(IS_FL_OPA_GAIN(initStruct->gain));
    /**/
    FL_RCC_EnableGroup1BusClock(FL_RCC_GROUP1_BUSCLK_ANAC);
    /**/
    FL_OPA_SetMode(OPAx, initStruct->mode);
    /**/
    FL_OPA_SetINNSource(OPAx, initStruct->INN);
    /**/
    FL_OPA_SetINPSource(OPAx, initStruct->INP);
    /**/
    if(initStruct->lowPowermode == FL_ENABLE)
    {
        FL_OPA_EnableLowPowerMode(OPAx);
    }
    if(initStruct->mode == FL_OPA_MODE_PGA)
    {
        /*PGA*/
        FL_OPA_PGA_SetGain(OPAx, initStruct->gain);
        if(initStruct->negtiveToPin == FL_ENABLE)
        {
            /*PGAPIN*/
            FL_OPA_PGA_EnableINNConnectToPin(OPAx);
        }
    }
    return status;
}

/**
  * @brief   @ref FL_OPA_InitTypeDef 
  * @param  initStruct  @ref FL_OPA_InitTypeDef 
  *
  * @retval None
  */

void FL_OPA_StructInit(FL_OPA_InitTypeDef *initStruct)
{
    initStruct->INP              = FL_OPA_INP_SOURCE_INP1;
    initStruct->INN              = FL_OPA_INN_SOURCE_INN1;
    initStruct->mode             = FL_OPA_MODE_STANDALONE;
    initStruct->digitalFilter    = FL_DISABLE;
    initStruct->negtiveToPin     = FL_DISABLE;
    initStruct->gain             = FL_OPA_GAIN_X2;
    initStruct->lowPowermode     = FL_DISABLE;
}

/**
  * @}
  */

#endif /* FL_OPA_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
