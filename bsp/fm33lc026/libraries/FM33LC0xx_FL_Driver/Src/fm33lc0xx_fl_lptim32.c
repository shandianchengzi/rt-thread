/**
  ****************************************************************************************************
  * @file    fm33lc0xx_fl_lptim32.c
  * @author  FMSH Application Team
  * @brief   Src file of LPTIM32 FL Module
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

/** @addtogroup LPTIM32
  * @{
  */

#ifdef FL_LPTIM32_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup LPTIM32_FL_Private_Macros
  * @{
  */

#define         IS_LPTIM32_INSTANCE(INSTANCE)                           (((INSTANCE) == LPTIM32))

#define         IS_FL_LPTIM32_OPCLK_SOURCE(__VALUE__)                   (((__VALUE__) == FL_RCC_LPTIM32_CLK_SOURCE_APB1CLK)||\
                                                                         ((__VALUE__) == FL_RCC_LPTIM32_CLK_SOURCE_LSCLK)||\
                                                                         ((__VALUE__) == FL_RCC_LPTIM32_CLK_SOURCE_LPOSC)||\
                                                                         ((__VALUE__) == FL_RCC_LPTIM32_CLK_SOURCE_RCMF_PSC))

#define         IS_FL_LPTIM32_CLK_SOURCE(__VALUE__)                     (((__VALUE__) == FL_LPTIM32_CLK_SOURCE_INTERNAL)||\
                                                                         ((__VALUE__) == FL_LPTIM32_CLK_SOURCE_EXTERNAL))

#define         IS_FL_LPTIM32_PRESCALER(__VALUE__)                      (((__VALUE__) == FL_LPTIM32_PSC_DIV1)||\
                                                                         ((__VALUE__) == FL_LPTIM32_PSC_DIV2)||\
                                                                         ((__VALUE__) == FL_LPTIM32_PSC_DIV4)||\
                                                                         ((__VALUE__) == FL_LPTIM32_PSC_DIV8)||\
                                                                         ((__VALUE__) == FL_LPTIM32_PSC_DIV16)||\
                                                                         ((__VALUE__) == FL_LPTIM32_PSC_DIV32)||\
                                                                         ((__VALUE__) == FL_LPTIM32_PSC_DIV64)||\
                                                                         ((__VALUE__) == FL_LPTIM32_PSC_DIV128))

#define         IS_FL_LPTIM32_MODE(__VALUE__)                           (((__VALUE__) == FL_LPTIM32_OPERATION_MODE_NORMAL)||\
                                                                         ((__VALUE__) == FL_LPTIM32_OPERATION_MODE_EXTERNAL_TRIGGER_CNT)||\
                                                                         ((__VALUE__) == FL_LPTIM32_OPERATION_MODE_EXTERNAL_ASYNC_PULSE_CNT)||\
                                                                         ((__VALUE__) == FL_LPTIM32_OPERATION_MODE_TIMEOUT))

#define         IS_FL_LPTIM32_ETR_TRIGEER_EDGE(__VALUE__)               (((__VALUE__) == FL_LPTIM32_ETR_TRIGGER_EDGE_RISING)||\
                                                                         ((__VALUE__) == FL_LPTIM32_ETR_TRIGGER_EDGE_FALLING)||\
                                                                         ((__VALUE__) == FL_LPTIM32_ETR_TRIGGER_EDGE_BOTH))

#define         IS_FL_LPTIM32_ONE_PULSE_MODE(__VALUE__)                 (((__VALUE__) == FL_LPTIM32_ONE_PULSE_MODE_CONTINUOUS)||\
                                                                         ((__VALUE__) == FL_LPTIM32_ONE_PULSE_MODE_SINGLE))

#define         IS_FL_LPTIM32_ETR_COUNT_EDGE(__VALUE__)                 (((__VALUE__) == FL_LPTIM32_ETR_COUNT_EDGE_RISING)||\
                                                                         ((__VALUE__) == FL_LPTIM32_ETR_COUNT_EDGE_FALLING))

#define         IS_FL_LPTIM32_IC_EDGE(__VALUE__)                        (((__VALUE__) == FL_LPTIM32_IC_EDGE_RISING)||\
                                                                         ((__VALUE__) == FL_LPTIM32_IC_EDGE_FALLING)||\
                                                                         ((__VALUE__) == FL_LPTIM32_IC_EDGE_BOTH))

#define         IS_FL_LPTIM32_OC_POLARITY(__VALUE__)                    (((__VALUE__) == FL_LPTIM32_OC_POLARITY_NORMAL)||\
                                                                         ((__VALUE__) == FL_LPTIM32_OC_POLARITY_INVERT))

#define         IS_FL_LPTIM32_CHANNEL(__VALUE__)                        (((__VALUE__) == FL_LPTIM32_CHANNEL_1)||\
                                                                         ((__VALUE__) == FL_LPTIM32_CHANNEL_2))

#define         IS_FL_LPTIM32_CAPTURE_SOURCE(__VALUE__)                 (((__VALUE__) == FL_LPTIM32_IC_CAPTURE_SOURCE_GROUP0)||\
                                                                         ((__VALUE__) == FL_LPTIM32_IC_CAPTURE_SOURCE_GROUP1)||\
                                                                         ((__VALUE__) == FL_LPTIM32_IC_CAPTURE_SOURCE_GROUP2)||\
                                                                         ((__VALUE__) == FL_LPTIM32_IC_CAPTURE_SOURCE_GROUP3))


/**
  * @}
  */

/** @addtogroup LPTIM32_FL_EF_Init
  * @{
  */

/**
  * @brief  LPTIM32
  * @param  LPTIM32x 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_LPTIM32_DeInit(LPTIM32_Type *LPTIM32x)
{
    FL_ErrorStatus status = FL_FAIL;
    assert_param(IS_LPTIM32_INSTANCE(LPTIM32x));
    /*  */
    FL_RCC_EnablePeripheralReset();
    /*LPTIM*/
    FL_RCC_EnableResetAPB1Peripheral(FL_RCC_RSTAPB_LPTIM32);
    FL_RCC_DisableResetAPB1Peripheral(FL_RCC_RSTAPB_LPTIM32);
    /*  */
    FL_RCC_DisableGroup1BusClock(FL_RCC_GROUP1_BUSCLK_LPTIM32);
    FL_RCC_DisableGroup2OperationClock(FL_RCC_GROUP2_OPCLK_LPTIM32);
    /*  */
    FL_RCC_DisablePeripheralReset();
    status = FL_PASS;
    return status;
}
/**
  * @brief  LPTIM32
  *
  * @note    @ref FL_LPTIM32_OPERATION_MODE_EXTERNAL_ASYNC_PULSE_CNT LPTIM32
  *         LPTIM32
  * @param  LPTIM32x  
  * @param  initStruct  @ref FL_LPTIM32_InitTypeDef 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_LPTIM32_Init(LPTIM32_Type *LPTIM32x, FL_LPTIM32_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /*  */
    assert_param(IS_LPTIM32_INSTANCE(LPTIM32x));
    assert_param(IS_FL_LPTIM32_OPCLK_SOURCE(initStruct->clockSource));
    assert_param(IS_FL_LPTIM32_CLK_SOURCE(initStruct->prescalerClockSource));
    assert_param(IS_FL_LPTIM32_PRESCALER(initStruct->prescaler));
    assert_param(IS_FL_LPTIM32_MODE(initStruct->mode));
    assert_param(IS_FL_LPTIM32_ETR_TRIGEER_EDGE(initStruct->triggerEdge));
    assert_param(IS_FL_LPTIM32_ONE_PULSE_MODE(initStruct->onePulseMode));
    assert_param(IS_FL_LPTIM32_ETR_COUNT_EDGE(initStruct->countEdge));
    /*  */
    if(LPTIM32x == LPTIM32)
    {
        /*  */
        FL_RCC_EnableGroup1BusClock(FL_RCC_GROUP1_BUSCLK_LPTIM32);
        /*  */
        if(initStruct->mode != FL_LPTIM32_OPERATION_MODE_EXTERNAL_ASYNC_PULSE_CNT)
        {
            /*  */
            FL_RCC_EnableGroup2OperationClock(FL_RCC_GROUP2_OPCLK_LPTIM32);
            /*  */
            FL_RCC_SetLPTIM32ClockSource(initStruct->clockSource);
        }
    }
    /*  */
    FL_LPTIM32_SetClockSource(LPTIM32x, initStruct->prescalerClockSource);
    /*  */
    FL_LPTIM32_SetPrescaler(LPTIM32x, initStruct->prescaler);
    /*  */
    FL_LPTIM32_SetOperationMode(LPTIM32x, initStruct->mode);
    /*  */
    switch(initStruct->mode)
    {
        case FL_LPTIM32_OPERATION_MODE_NORMAL:
        {
        }
        break;
        case FL_LPTIM32_OPERATION_MODE_EXTERNAL_TRIGGER_CNT:
        {
            /*  */
            FL_LPTIM32_SetETRTriggerEdge(LPTIM32x, initStruct->triggerEdge);
        }
        break;
        case FL_LPTIM32_OPERATION_MODE_EXTERNAL_ASYNC_PULSE_CNT:
        {
            /*  */
            FL_LPTIM32_SetETRCountEdge(LPTIM32x, initStruct->countEdge);
            /*  */
            FL_LPTIM32_EnableETRFilter(LPTIM32x);
        }
        break;
        case FL_LPTIM32_OPERATION_MODE_TIMEOUT:
        {
            /*  */
            FL_LPTIM32_SetETRTriggerEdge(LPTIM32x, initStruct->triggerEdge);
        }
        break;
    }
    /*  */
    FL_LPTIM32_SetOnePulseMode(LPTIM32x, initStruct->onePulseMode);
    /*  */
    FL_LPTIM32_WriteAutoReload(LPTIM32x, initStruct->autoReload);
    return status;
}
/**
  * @brief   @ref FL_LPTIM32_InitTypeDef 
  * @param  initStruct  @ref FL_LPTIM32_InitTypeDef 
  *
  * @retval None
  */
void FL_LPTIM32_StructInit(FL_LPTIM32_InitTypeDef *initStruct)
{
    initStruct->clockSource           = FL_RCC_LPTIM32_CLK_SOURCE_APB1CLK;
    initStruct->prescalerClockSource  = FL_LPTIM32_CLK_SOURCE_INTERNAL;
    initStruct->prescaler             = FL_LPTIM32_PSC_DIV1;
    initStruct->autoReload            = 0;
    initStruct->mode                  = FL_LPTIM32_OPERATION_MODE_NORMAL;
    initStruct->countEdge             = FL_LPTIM32_ETR_COUNT_EDGE_RISING;
    initStruct->triggerEdge           = FL_LPTIM32_ETR_TRIGGER_EDGE_RISING;
    initStruct->onePulseMode          = FL_LPTIM32_ONE_PULSE_MODE_CONTINUOUS;
}

/**
  * @brief  LPTIM32
  *
  * @param  LPTIM32x  
  * @param  initStruct_IC  @ref FL_LPTIM32_IC_InitTypeDef 
  * @param  channel LPTIM32
  *         
  *         @arg @ref FL_LPTIM32_CHANNEL_1
  *         @arg @ref FL_LPTIM32_CHANNEL_2
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_LPTIM32_IC_Init(LPTIM32_Type *LPTIM32x, uint32_t channel, FL_LPTIM32_IC_InitTypeDef *initStruct_IC)
{
    FL_ErrorStatus status = FL_PASS;
    /*  */
    assert_param(IS_LPTIM32_INSTANCE(LPTIM32x));
    assert_param(IS_FL_LPTIM32_CHANNEL(channel));
    assert_param(IS_FL_LPTIM32_IC_EDGE(initStruct_IC->ICEdge));
    assert_param(IS_FL_LPTIM32_CAPTURE_SOURCE(initStruct_IC->ICSource));
    /*  */
    FL_LPTIM32_IC_SetCaptureSource(LPTIM32, initStruct_IC->ICSource, channel);
    /*  */
    FL_LPTIM32_IC_SetCaptureEdge(LPTIM32, initStruct_IC->ICEdge, channel);
    /*  */
    FL_LPTIM32_SetChannelMode(LPTIM32, FL_LPTIM32_CHANNEL_MODE_INPUT, channel);
    return status;
}
/**
  * @brief   @ref FL_LPTIM32_IC_InitTypeDef 
  * @param  initStruct_IC  @ref FL_LPTIM32_IC_InitTypeDef 
  *
  * @retval None
  */
void FL_LPTIM32_IC_StructInit(FL_LPTIM32_IC_InitTypeDef *initStruct_IC)
{
    initStruct_IC->ICEdge      = FL_LPTIM32_IC_EDGE_RISING;
    initStruct_IC->ICSource    = FL_LPTIM32_IC_CAPTURE_SOURCE_GROUP0;
}

/**
  * @brief  LPTIM32
  *
  * @param  LPTIM32x  
  * @param  initStruct_OC  @ref FL_LPTIM32_OC_InitTypeDef 
  * @param  channel LPTIM32
  *         
  *         @arg @ref FL_LPTIM32_CHANNEL_1
  *         @arg @ref FL_LPTIM32_CHANNEL_2
  *
  * @retval ErrorStatus
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_LPTIM32_OC_Init(LPTIM32_Type *LPTIM32x, uint32_t channel, FL_LPTIM32_OC_InitTypeDef *initStruct_OC)
{
    FL_ErrorStatus result = FL_PASS;
    /*  */
    assert_param(IS_LPTIM32_INSTANCE(LPTIM32x));
    assert_param(IS_FL_LPTIM32_CHANNEL(channel));
    assert_param(IS_FL_LPTIM32_OC_POLARITY(initStruct_OC->OCPolarity));
    /*  */
    FL_LPTIM32_OC_SetPolarity(LPTIM32x, initStruct_OC->OCPolarity, channel);
    /*  */
    switch(channel)
    {
        case FL_LPTIM32_CHANNEL_1:
            FL_LPTIM32_WriteCompareCH1(LPTIM32x, initStruct_OC->compareValue);
            break;
        case FL_LPTIM32_CHANNEL_2:
            FL_LPTIM32_WriteCompareCH2(LPTIM32x, initStruct_OC->compareValue);
            break;
        default :
            result = FL_FAIL;
            break;
    }
    /*  */
    FL_LPTIM32_SetChannelMode(LPTIM32x, FL_LPTIM32_CHANNEL_MODE_OUTPUT, channel);
    return result;
}

/**
  * @brief   @ref FL_LPTIM32_OC_InitTypeDef 
  * @param  initStruct_OC  @ref FL_LPTIM32_OC_InitTypeDef 
  *
  * @retval None
  */
void FL_LPTIM32_OC_StructInit(FL_LPTIM32_OC_InitTypeDef *initStruct_OC)
{
    initStruct_OC->compareValue  = 0;
    initStruct_OC->OCPolarity    = FL_LPTIM32_OC_POLARITY_NORMAL;
}

/**
  * @}
  */

#endif /* FL_LPTIM32_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
