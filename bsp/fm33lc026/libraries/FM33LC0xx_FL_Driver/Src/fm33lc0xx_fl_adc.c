/**
  ****************************************************************************************************
  * @file    fm33lc0xx_fl_adc.c
  * @author  FMSH Application Team
  * @brief   Src file of ADC FL Module
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

/** @addtogroup ADC
  * @{
  */

#ifdef FL_ADC_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup ADC_FL_PM ADC Private Macros
  * @{
  */

#define         IS_FL_ADC_INSTANCE(INSTANCE)                ((INSTANCE) == ADC)

#define         IS_FL_ADC_ADCCLK_SOURCE(__VALUE__)          (((__VALUE__) == FL_RCC_ADC_CLK_SOURCE_RCMF_PSC)||\
                                                            ((__VALUE__) == FL_RCC_ADC_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_RCC_ADC_CLK_SOURCE_XTHF)||\
                                                            ((__VALUE__) == FL_RCC_ADC_CLK_SOURCE_PLL))


#define         IS_FL_ADC_ADCCLK_PRESCALER(__VALUE__)       (((__VALUE__) == FL_RCC_ADC_PSC_DIV1)||\
                                                            ((__VALUE__) == FL_RCC_ADC_PSC_DIV2)||\
                                                            ((__VALUE__) == FL_RCC_ADC_PSC_DIV4)||\
                                                            ((__VALUE__) == FL_RCC_ADC_PSC_DIV8)||\
                                                            ((__VALUE__) == FL_RCC_ADC_PSC_DIV16)||\
                                                            ((__VALUE__) == FL_RCC_ADC_PSC_DIV32))


#define         IS_FL_ADC_CONTINUOUSCONVMODE(__VALUE__)     (((__VALUE__) == FL_ADC_CONV_MODE_SINGLE)||\
                                                            ((__VALUE__) == FL_ADC_CONV_MODE_CONTINUOUS))

#define         IS_FL_ADC_AUTO_MODE(__VALUE__)              (((__VALUE__) == FL_ADC_SINGLE_CONV_MODE_AUTO)||\
                                                            ((__VALUE__) == FL_ADC_SINGLE_CONV_MODE_SEMIAUTO))


#define         IS_FL_ADC_SCANDIRECTION(__VALUE__)          (((__VALUE__) == FL_ADC_SEQ_SCAN_DIR_FORWARD)||\
                                                            ((__VALUE__) == FL_ADC_SEQ_SCAN_DIR_BACKWARD))


#define         IS_FL_ADC_EXTERNALTRIGCONV(__VALUE__)       (((__VALUE__) == FL_ADC_TRIGGER_EDGE_NONE)||\
                                                            ((__VALUE__) == FL_ADC_TRIGGER_EDGE_RISING)||\
                                                            ((__VALUE__) == FL_ADC_TRIGGER_EDGE_FALLING)||\
                                                            ((__VALUE__) == FL_ADC_TRIGGER_EDGE_BOTH))

#define         IS_FL_ADC_EXTERNALTRIGSOURCE(__VALUE__)     (((__VALUE__) == FL_ADC_TRGI_PA8)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_PB9)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_ATIM)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_GPTIM0)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_GPTIM1)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_RTC)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_BSTIM1)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_COMP1)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_COMP2))

#define         IS_FL_ADC_CHANNEL_FAST_TIME(__VALUE__)      (((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_4_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_6_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_9_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_10_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_16_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_24_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_48_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_96_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_128_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_192_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_256_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_384_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_SOFTWARE_CONTROL))

#define         IS_FL_ADC_CHANNEL_SLOW_TIME(__VALUE__)      (((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_4_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_6_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_9_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_10_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_16_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_24_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_32_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_48_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_96_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_128_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_192_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_256_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_384_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_SOFTWARE_CONTROL))

#define         IS_FL_ADC_OVERSAMPCOFIG(__VALUE__)          (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_ADC_OVERSAMPINGRATIO(__VALUE__)       (((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_2X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_4X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_8X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_16X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_32X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_64X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_128X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_256X))

#define         IS_FL_ADC_OVERSAMPINGSHIFT(__VALUE__)       (((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_0B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_1B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_2B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_3B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_4B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_5B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_6B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_7B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_8B))

#define         ADC_CALIBRATIN_TIME_OUT                     (500000)
/**
  * @}
  */

/** @addtogroup ADC_FL_EF_Init
  * @{
  */

/**
  * @brief  ADC
  * @param  None
  * @retval 
  *         -FL_PASS ADC
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_ADC_CommonDeInit(void)
{
    /*  */
    FL_RCC_DisableGroup2BusClock(FL_RCC_GROUP2_BUSCLK_ADC);
    /*  */
    FL_RCC_DisableGroup2OperationClock(FL_RCC_GROUP2_OPCLK_ADC);
    return FL_PASS;
}
/**
  * @brief  ADC
  * @param  ADC_CommonInitStruct  @ref FL_ADC_CommonInitTypeDef ADC
  * @retval 
  *         -FL_FAIL 
  *         -FL_PASS ADC
  */
FL_ErrorStatus FL_ADC_CommonInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /*  */
    assert_param(IS_FL_ADC_ADCCLK_PRESCALER(ADC_CommonInitStruct->clockPrescaler));
    assert_param(IS_FL_ADC_ADCCLK_SOURCE(ADC_CommonInitStruct->clockSource));
    /*  */
    FL_RCC_EnableGroup2BusClock(FL_RCC_GROUP2_BUSCLK_ADC);
    /*  */
    FL_RCC_EnableGroup2OperationClock(FL_RCC_GROUP2_OPCLK_ADC);
    /* ADCCLOCK */
    FL_RCC_SetADCPrescaler(ADC_CommonInitStruct->clockPrescaler);
    /* ADCCLOCK */
    FL_RCC_SetADCClockSource(ADC_CommonInitStruct->clockSource);
    return status;
}
/**
  * @brief   @ref FL_ADC_CommonInitTypeDef 
  * @param  ADC_CommonInitStruct  @ref FL_ADC_CommonInitTypeDef 
  * @retval None
  */
void FL_ADC_CommonStructInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    /*RCHFADC16*/
    ADC_CommonInitStruct->clockSource     = FL_RCC_ADC_CLK_SOURCE_RCHF;
    ADC_CommonInitStruct->clockPrescaler  = FL_RCC_ADC_PSC_DIV16;
}
/**
  * @brief  ADC
  * @param  ADCx  
  * @retval 
  *         -FL_PASS ADC
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_ADC_DeInit(ADC_Type *ADCx)
{
    FL_ErrorStatus status = FL_PASS;
    /*  */
    assert_param(IS_FL_ADC_INSTANCE(ADCx));
    /*  */
    FL_RCC_EnablePeripheralReset();
    FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_ADC);
    FL_RCC_DisableResetAPB2Peripheral(FL_RCC_RSTAPB_ADC);
    FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_ADCCR);
    FL_RCC_DisableResetAPB2Peripheral(FL_RCC_RSTAPB_ADCCR);
    FL_RCC_DisablePeripheralReset();
    return status;
}
/**
  * @brief  ADC
  * @note   ADCADC
  *         
  * @param  ADCx  
  * @param  ADC_InitStruct  @ref FL_ADC_InitTypeDef ADC
  * @retval 
  *         -FL_FAIL 
  *         -FL_PASS ADC
  */
FL_ErrorStatus FL_ADC_Init(ADC_Type *ADCx, FL_ADC_InitTypeDef  *ADC_InitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    uint32_t i = 0;
    /*  */
    assert_param(IS_FL_ADC_INSTANCE(ADCx));
    assert_param(IS_FL_ADC_CONTINUOUSCONVMODE(ADC_InitStruct->conversionMode));
    assert_param(IS_FL_ADC_AUTO_MODE(ADC_InitStruct->autoMode));
    assert_param(IS_FL_ADC_SCANDIRECTION(ADC_InitStruct->scanDirection));
    assert_param(IS_FL_ADC_EXTERNALTRIGCONV(ADC_InitStruct->externalTrigConv));
    assert_param(IS_FL_ADC_OVERSAMPCOFIG(ADC_InitStruct->oversamplingMode));
    assert_param(IS_FL_ADC_OVERSAMPINGRATIO(ADC_InitStruct->overSampingMultiplier));
    assert_param(IS_FL_ADC_OVERSAMPINGSHIFT(ADC_InitStruct->oversamplingShift));
    /* ADC */
    FL_RCC_EnableGroup1BusClock(FL_RCC_GROUP1_BUSCLK_ANAC);
    FL_SVD_EnableADCMonitor(SVD);
    if(!FL_VREF_IsEnabled(VREF))
    {
        FL_VREF_ClearFlag_Ready(VREF);
        FL_VREF_Enable(VREF);   /* VREF_ENVREF1p2 */
    }
    FL_VREF_EnableTemperatureSensor(VREF);  /* PTAT_EN */
    while(FL_VREF_IsActiveFlag_Ready(VREF) == 0)
    {
        if(i >= 128000)
        {
            break;
        }
        i++;
    }
    FL_ADC_Disable(ADCx);
    if(FL_ADC_IsEnabled(ADCx) == 0U)
    {
        /*  */
        FL_ADC_SetConversionMode(ADCx, ADC_InitStruct->conversionMode);
        /*  */
        FL_ADC_SetSingleConversionAutoMode(ADCx, ADC_InitStruct->autoMode);
        /*  */
        if(ADC_InitStruct->waitMode)
        {
            FL_ADC_EnableWaitMode(ADCx);
        }
        else
        {
            FL_ADC_DisableWaitMode(ADCx);
        }
        /**/
        if(ADC_InitStruct->overrunMode)
        {
            FL_ADC_EnableOverrunMode(ADCx);
        }
        else
        {
            FL_ADC_DisableOverrunMode(ADCx);
        }
        /*  */
        FL_ADC_SetSequenceScanDirection(ADCx, ADC_InitStruct->scanDirection);
        /* */
        FL_ADC_SetSamplingTimeControlMode(ADCx, FL_ADC_SAMPLING_TIME_CONTROL_BY_REG);
        FL_ADC_SetSamplingStartControlMode(ADCx, FL_ADC_SAMPLING_START_CONTROL_BY_REG);
        /*  */
        FL_ADC_SetTriggerEdge(ADCx, ADC_InitStruct->externalTrigConv);
        /*  */
        FL_ADC_SetTriggerSource(ADCx, ADC_InitStruct->triggerSource);
        /**/
        FL_ADC_SetSamplingInterval(ADCx, FL_ADC_SAMPLING_INTERVAL_11_CYCLE);
        FL_ADC_SetFastChannelSamplingTime(ADCx, ADC_InitStruct->fastChannelTime);
        FL_ADC_SetSlowChannelSamplingTime(ADCx, ADC_InitStruct->lowChannelTime);
        if(ADC_InitStruct->oversamplingMode)
        {
            /*
            1625620bit4bit16bit*/
            FL_ADC_SetOverSamplingMultiplier(ADCx, ADC_InitStruct->overSampingMultiplier);
            FL_ADC_SetOverSamplingShift(ADCx, ADC_InitStruct->oversamplingShift);
            /*  */
            FL_ADC_EnableOverSampling(ADCx);
        }
        else
        {
            /*  */
            FL_ADC_DisableOverSampling(ADCx);
        }
    }
    else
    {
        status = FL_FAIL;
    }
    return status;
}
/**
  * @brief   @ref FL_ADC_InitTypeDef 
  * @param  ADC_InitStruct  @ref FL_ADC_InitTypeDef 
  * @retval None
  */
void FL_ADC_StructInit(FL_ADC_InitTypeDef *ADC_InitStruct)
{
    ADC_InitStruct->conversionMode        = FL_ADC_CONV_MODE_SINGLE;
    ADC_InitStruct->autoMode              = FL_ADC_SINGLE_CONV_MODE_AUTO;
    ADC_InitStruct->scanDirection         = FL_ADC_SEQ_SCAN_DIR_FORWARD;
    ADC_InitStruct->externalTrigConv      = FL_ADC_TRIGGER_EDGE_NONE;
    ADC_InitStruct->overrunMode           = FL_ENABLE;
    ADC_InitStruct->waitMode              = FL_ENABLE;
    ADC_InitStruct->fastChannelTime       = FL_ADC_FAST_CH_SAMPLING_TIME_4_ADCCLK;
    ADC_InitStruct->lowChannelTime        = FL_ADC_SLOW_CH_SAMPLING_TIME_192_ADCCLK;
    ADC_InitStruct->oversamplingMode      = FL_ENABLE;
    ADC_InitStruct->overSampingMultiplier = FL_ADC_OVERSAMPLING_MUL_16X;
    ADC_InitStruct->oversamplingShift     = FL_ADC_OVERSAMPLING_SHIFT_4B;
}

/**
  * @}
  */

#endif /* FL_ADC_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
