/**
  *******************************************************************************************************
  * @file    fm33lc0xx_fl_u7816.c
  * @author  FMSH Application Team
  * @brief   Src file of U7816 FL Module
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

/** @addtogroup U7816
  * @{
  */

#ifdef FL_U7816_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup U7816_FL_Private_Macros
  * @{
  */


#define         IS_FL_U7816_INSTANCE(INTANCE)                       ((INTANCE) == U7816)

#define         IS_FL_U7816_CLOCK_FRQUENCE(__VALUE__)               (((__VALUE__) >=1000000)||\
                                                                     ((__VALUE__) <= 5000000))

#define         IS_FL_U7816_TX_PARITHERROR_AUTO_RETRY(__VALUE__)    (((__VALUE__) == FL_DISABLE)||\
                                                                     ((__VALUE__) == FL_ENABLE))

#define         IS_FL_U7816_RETRY_CNT(__VALUE__)                    (((__VALUE__) == FL_U7816_RETRY_COUNT_1)||\
                                                                     ((__VALUE__) == FL_U7816_RETRY_COUNT_3))

#define         IS_FL_U7816_BLOCKGUARD(__VALUE__)                   (((__VALUE__) == FL_ENABLE)||\
                                                                     ((__VALUE__) == FL_DISABLE))

#define         IS_FL_U7816_AUTO_PULL(__VALUE__)                    (((__VALUE__) == FL_ENABLE)||\
                                                                    ((__VALUE__) == FL_DISABLE))

#define         IS_FL_U7816_PARITH(__VALUE__)                       (((__VALUE__) == FL_U7816_PARITY_EVEN)||\
                                                                     ((__VALUE__) == FL_U7816_PARITY_ODD )||\
                                                                     ((__VALUE__) == FL_U7816_PARITY_ALWAYS_1)||\
                                                                     ((__VALUE__) == FL_U7816_PARITY_NONE))

#define         IS_FL_U7816_TX_GUARD(__VALUE__)                     (((__VALUE__) == FL_U7816_TX_GUARD_TIME_2ETU)||\
                                                                     ((__VALUE__) == FL_U7816_TX_GUARD_TIME_3ETU))

#define         IS_FL_U7816_RX_GUARD(__VALUE__)                     (((__VALUE__) == FL_U7816_RX_GUARD_TIME_2ETU)||\
                                                                     ((__VALUE__) == FL_U7816_RX_GUARD_TIME_1ETU))

#define         IS_FL_U7816_ERROR_GUARD(__VALUE__)                   (((__VALUE__) == FL_U7816_ERROR_GUARD_TIME_2ETU)||\
                                                                      ((__VALUE__) == FL_U7816_ERROR_GUARD_TIME_1ETU))

#define         IS_FL_U7816_ERROR_SIGNALWIDTH(__VALUE__)             (((__VALUE__) == FL_U7816_ERROR_SIGNAL_WIDTH_2ETU)||\
                                                                      ((__VALUE__) == FL_U7816_ERROR_SIGNAL_WIDTH_1P5ETU)||\
                                                                      ((__VALUE__) == FL_U7816_ERROR_SIGNAL_WIDTH_1ETU))

#define         IS_FL_U7816_RX_AUTO_ERROR_SIG(__VALUE__)             (((__VALUE__) == FL_DISABLE)||\
                                                                      ((__VALUE__) == FL_ENABLE))

#define         IS_FL_U7816_BIT_DIRECTION(__VALUE__)                 (((__VALUE__) == FL_U7816_BIT_ORDER_LSB_FIRST)||\
                                                                      ((__VALUE__) == FL_U7816_BIT_ORDER_MSB_FIRST))
/**
  * @}
  */

/** @addtogroup UART_FL_EF_Init
  * @{
  */

/**
  * @brief  U7816
  * @param  U7816x 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_U7816_DeInit(U7816_Type *U7816x)
{
    assert_param(IS_FL_U7816_INSTANCE(U7816x));
    /*  */
    FL_RCC_EnablePeripheralReset();
    /* U7816 */
    FL_RCC_EnableResetAPB1Peripheral(FL_RCC_RSTAPB_U7816);
    FL_RCC_DisableResetAPB1Peripheral(FL_RCC_RSTAPB_U7816);
    /*  */
    FL_RCC_DisableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_U7816);
    /*  */
    FL_RCC_DisablePeripheralReset();
    return FL_PASS;
}

/**
  * @brief  U7816
  * @param  U7816x 
  * @param  U7816_InitStruct  @ref FL_U7816_InitTypeDef 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_U7816_Init(U7816_Type *U7816x, FL_U7816_InitTypeDef *U7816_InitStruct)
{
    uint32_t Fclk;
    uint32_t tempClkdiv;
    /*  */
    assert_param(IS_FL_U7816_INSTANCE(U7816x));
    assert_param(IS_FL_U7816_CLOCK_FRQUENCE(U7816_InitStruct->outputClockFreqence));
    assert_param(IS_FL_U7816_TX_PARITHERROR_AUTO_RETRY(U7816_InitStruct->txAutoRetry));
    assert_param(IS_FL_U7816_RETRY_CNT(U7816_InitStruct->retryCnt));
    assert_param(IS_FL_U7816_BLOCKGUARD(U7816_InitStruct->blockGuard));
    assert_param(IS_FL_U7816_PARITH(U7816_InitStruct->parity));
    assert_param(IS_FL_U7816_RX_GUARD(U7816_InitStruct->rxGuardTime));
    assert_param(IS_FL_U7816_ERROR_GUARD(U7816_InitStruct->errorGuardTime));
    assert_param(IS_FL_U7816_ERROR_SIGNALWIDTH(U7816_InitStruct->errorSignalWidth));
    assert_param(IS_FL_U7816_RX_AUTO_ERROR_SIG(U7816_InitStruct->rxAutoErrorSignal));
    assert_param(IS_FL_U7816_BIT_DIRECTION(U7816_InitStruct->transferOrder));
    assert_param(IS_FL_U7816_AUTO_PULL(U7816_InitStruct->strongPullUp));
    assert_param(IS_FL_U7816_TX_GUARD(U7816_InitStruct->txGuardTime));
    /*  */
    FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_U7816);
    /*  */
    Fclk = FL_RCC_GetAPB1ClockFreq();
    tempClkdiv = Fclk / U7816_InitStruct->outputClockFreqence - 1;
    FL_U7816_WriteClockDivision(U7816x, tempClkdiv);
    /* error signal */
    if(U7816_InitStruct->txAutoRetry == FL_ENABLE)
    {
        FL_U7816_EnableTXParityErrorAutoRetry(U7816x);
    }
    else
    {
        FL_U7816_DisableTXParityErrorAutoRetry(U7816x);
    }
    /*  */
    FL_U7816_SetRetryCount(U7816x, U7816_InitStruct->retryCnt);
    /* etu */
    FL_U7816_SetTXGuardTime(U7816x, U7816_InitStruct->txGuardTime);
    /* */
    if(U7816_InitStruct->strongPullUp == FL_ENABLE)
    {
        FL_U7816_EnablePullup(U7816x);
    }
    else
    {
        FL_U7816_DisablePullup(U7816x);
    }
    /* ,block guard time */
    if(U7816_InitStruct->blockGuard == FL_ENABLE)
    {
        FL_U7816_EnableBlockGuardTime(U7816x);
    }
    else
    {
        FL_U7816_DisableBlockGuardTime(U7816x);
    }
    /*  */
    FL_U7816_SetParity(U7816x, U7816_InitStruct->parity);
    /* etu */
    FL_U7816_SetRXGuardTime(U7816x, U7816_InitStruct->rxGuardTime);
    /* etu */
    FL_U7816_SetErrorGuardTime(U7816x, U7816_InitStruct->errorGuardTime);
    /*  etu */
    FL_U7816_SetErrorSignalWidth(U7816x, U7816_InitStruct->errorSignalWidth);
    /* error signal */
    if(U7816_InitStruct->rxAutoErrorSignal == FL_ENABLE)
    {
        FL_U7816_EnableRXParityErrorAutoRetry(U7816x);
    }
    else
    {
        FL_U7816_DisableRXParityErrorAutoRetry(U7816x);
    }
    /* bit */
    FL_U7816_SetBitOrder(U7816x, U7816_InitStruct->transferOrder);
    /* baud */
    FL_U7816_WriteBaudRate(U7816x, U7816_InitStruct->baud);
    /* etu */
    FL_U7816_WriteExtraGuardTime(U7816x, U7816_InitStruct->extraGuardTime);
    return FL_PASS;
}

/**
  * @brief   @ref FL_U7816_InitTypeDef 
  * @param  U7816_InitStruct  @ref FL_U7816_InitTypeDef 
  *
  * @retval None
  */
void FL_U7816_StructInit(FL_U7816_InitTypeDef *U7816_InitStruct)
{
    U7816_InitStruct->outputClockFreqence   = 4000000;
    U7816_InitStruct->txAutoRetry           = FL_ENABLE;
    U7816_InitStruct->retryCnt              = FL_U7816_RETRY_COUNT_1;
    U7816_InitStruct->strongPullUp          = FL_ENABLE;
    U7816_InitStruct->blockGuard            = FL_DISABLE;
    U7816_InitStruct->parity                = FL_U7816_PARITY_EVEN;
    U7816_InitStruct->rxGuardTime           = FL_U7816_RX_GUARD_TIME_2ETU;
    U7816_InitStruct->txGuardTime           = FL_U7816_TX_GUARD_TIME_2ETU;
    U7816_InitStruct->errorGuardTime        = FL_U7816_ERROR_GUARD_TIME_1ETU;
    U7816_InitStruct->errorSignalWidth      = FL_U7816_ERROR_SIGNAL_WIDTH_2ETU;
    U7816_InitStruct->rxAutoErrorSignal     = FL_ENABLE;
    U7816_InitStruct->transferOrder         = FL_U7816_BIT_ORDER_LSB_FIRST;
    U7816_InitStruct->baud                  = 372 - 1;
    U7816_InitStruct->extraGuardTime        = 0;
}

/**
  * @}
  */

#endif /* FL_U7816_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
