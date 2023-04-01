/**
  ****************************************************************************************************
  * @file    fm33lc0xx_fl_exti.c
  * @author  FMSH Application Team
  * @brief   Src file of EXTI FL Module
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

/** @addtogroup EXTI
  * @{
  */

#ifdef FL_EXTI_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup EXTI_FL_Private_Macros
  * @{
  */

#define IS_EXTI_ALL_INSTANCE(INSTANCE)             (((INSTANCE) == FL_GPIO_EXTI_LINE_0)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_1)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_2)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_3)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_4)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_5)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_6)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_7)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_8)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_9)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_10)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_11)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_12)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_13)||\
                                                    ((INSTANCE) == FL_GPIO_EXTI_LINE_14))

#define IS_EXTI_CLK_SOURCE(__VALUE__)              (((__VALUE__) == FL_RCC_EXTI_CLK_SOURCE_HCLK)||\
                                                    ((__VALUE__) == FL_RCC_EXTI_CLK_SOURCE_LSCLK))

#define IS_EXTI_INPUT_GROUP(__VALUE__)             (((__VALUE__) == FL_GPIO_EXTI_INPUT_GROUP0)||\
                                                    ((__VALUE__) == FL_GPIO_EXTI_INPUT_GROUP1)||\
                                                    ((__VALUE__) == FL_GPIO_EXTI_INPUT_GROUP2)||\
                                                    ((__VALUE__) == FL_GPIO_EXTI_INPUT_GROUP3))

#define IS_EXTI_TRIG_EDGE(__VALUE__)               (((__VALUE__) == FL_GPIO_EXTI_TRIGGER_EDGE_RISING)||\
                                                    ((__VALUE__) == FL_GPIO_EXTI_TRIGGER_EDGE_FALLING)||\
                                                    ((__VALUE__) == FL_GPIO_EXTI_TRIGGER_EDGE_BOTH))

#define IS_EXTI_FILTER(__VALUE__)                  (((__VALUE__) == FL_ENABLE)||\
                                                    ((__VALUE__) == FL_DISABLE))

/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup EXTI_FL_Private_Consts
  * @{
  */

typedef void (*pSetExtiLineFunc)(GPIO_COMMON_Type *, uint32_t);
static const pSetExtiLineFunc setExtiLineFuncs[] =
{
    FL_GPIO_SetExtiLine0,
    FL_GPIO_SetExtiLine1,
    FL_GPIO_SetExtiLine2,
    FL_GPIO_SetExtiLine3,
    FL_GPIO_SetExtiLine4,
    FL_GPIO_SetExtiLine5,
    FL_GPIO_SetExtiLine6,
    FL_GPIO_SetExtiLine7,
    FL_GPIO_SetExtiLine8,
    FL_GPIO_SetExtiLine9,
    FL_GPIO_SetExtiLine10,
    NULL,
    FL_GPIO_SetExtiLine12,
    FL_GPIO_SetExtiLine13,
    FL_GPIO_SetExtiLine14,
};

typedef void (*pSetTrigEdgeFunc)(GPIO_COMMON_Type *, uint32_t, uint32_t);
static const pSetTrigEdgeFunc setTrigEdgeFuncs[] =
{
    FL_GPIO_SetTriggerEdge,
};

/**
  * @}
  */

/** @addtogroup EXTI_FL_EF_Init
  * @{
  */

/**
  * @brief  EXTI
  *
  * @param  EXTI_CommonInitStruct  @ref FL_EXTI_CommonInitTypeDef EXTI
  *
  * @retval ErrorStatus
  *         -FL_FAIL 
  *         -FL_PASS EXTI
  */
FL_ErrorStatus FL_EXTI_CommonInit(FL_EXTI_CommonInitTypeDef *EXTI_CommonInitStruct)
{
    assert_param(IS_EXTI_CLK_SOURCE(EXTI_CommonInitStruct->clockSource));
    /* IO */
    FL_RCC_EnableGroup1BusClock(FL_RCC_GROUP1_BUSCLK_PAD);
    /*  */
    FL_RCC_EnableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_EXTI);
    FL_RCC_SetEXTIClockSource(EXTI_CommonInitStruct->clockSource);
    return FL_PASS;
}

/**
  * @brief  EXTI
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_EXTI_CommonDeinit(void)
{
    /*  */
    FL_RCC_DisableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_EXTI);
    return FL_PASS;
}

/**
  * @brief   EXTI_CommonInitStruct 
  * @param  EXTI_CommonInitStruct  @ref FL_EXTI_CommonInitTypeDef 
  *
  * @retval None
  */
void FL_EXTI_CommonStructInit(FL_EXTI_CommonInitTypeDef *EXTI_CommonInitStruct)
{
    EXTI_CommonInitStruct->clockSource = FL_RCC_EXTI_CLK_SOURCE_LSCLK;
}

/**
  * @brief  EXTI
  *
  * @param  extiLineX 
  * @param  EXTI_InitStruct  @ref FL_EXTI_InitTypeDef EXTI
  *
  * @retval ErrorStatus
  *         -FL_FAIL 
  *         -FL_PASS EXTI
  */
FL_ErrorStatus FL_EXTI_Init(uint32_t extiLineX, FL_EXTI_InitTypeDef *EXTI_InitStruct)
{
    uint8_t extiLineId;
    uint32_t tmpExtiLineX;
    /*  */
    assert_param(IS_EXTI_ALL_INSTANCE(extiLineX));
    assert_param(IS_EXTI_INPUT_GROUP(EXTI_InitStruct->input));
    assert_param(IS_EXTI_TRIG_EDGE(EXTI_InitStruct->triggerEdge));
    assert_param(IS_EXTI_FILTER(EXTI_InitStruct->filter));
    /* EXTIid */
    tmpExtiLineX = extiLineX;
    for(extiLineId = 0; tmpExtiLineX != FL_GPIO_EXTI_LINE_0; tmpExtiLineX >>= 1, extiLineId++);
    /* IO */
    setExtiLineFuncs[extiLineId](GPIO, EXTI_InitStruct->input << (2 * extiLineId));
    /*  */
    EXTI_InitStruct->filter == FL_ENABLE ? FL_GPIO_EnableDigitalFilter(GPIO, extiLineX) : FL_GPIO_DisableDigitalFilter(GPIO, extiLineX);
    /*  */
    setTrigEdgeFuncs[extiLineId / 16](GPIO, extiLineX, EXTI_InitStruct->triggerEdge);
    /* 332K */
        for(uint16_t i;i<1000;++i)
        {
            __NOP();
        }
    /*  */
    FL_GPIO_ClearFlag_EXTI(GPIO, extiLineX);
    /*  */
    NVIC_ClearPendingIRQ(GPIO_IRQn);
    return FL_PASS;
}

/**
  * @brief  EXTI
  *
  * @retval ErrorStatus
  *         -FL_FAIL 
  *         -FL_PASS EXTI
  */
FL_ErrorStatus FL_EXTI_DeInit(uint32_t extiLineX)
{
    uint8_t extiLineId;
    uint32_t tmpExtiLineX;
    /*  */
    assert_param(IS_EXTI_ALL_INSTANCE(extiLineX));
    /* EXTIid */
    tmpExtiLineX = extiLineX;
    for(extiLineId = 0; tmpExtiLineX != FL_GPIO_EXTI_LINE_0; tmpExtiLineX >>= 1, extiLineId++);
    /*  */
    FL_GPIO_ClearFlag_EXTI(GPIO, extiLineX);
    /*  */
    setTrigEdgeFuncs[extiLineId / 16](GPIO, extiLineX, FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE);
    /*  */
    FL_GPIO_DisableDigitalFilter(GPIO, extiLineX);
    return FL_PASS;
}

/**
  * @brief   EXTI_InitStruct 
  * @param  EXTI_InitStruct  @ref FL_EXTI_InitTypeDef 
  *
  * @retval None
  */
void FL_EXTI_StructInit(FL_EXTI_InitTypeDef *EXTI_InitStruct)
{
    EXTI_InitStruct->filter = FL_DISABLE;
    EXTI_InitStruct->input = FL_GPIO_EXTI_INPUT_GROUP0;
    EXTI_InitStruct->triggerEdge = FL_GPIO_EXTI_TRIGGER_EDGE_RISING;
}

/**
  * @}
  */

#endif /* FL_EXTI_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
