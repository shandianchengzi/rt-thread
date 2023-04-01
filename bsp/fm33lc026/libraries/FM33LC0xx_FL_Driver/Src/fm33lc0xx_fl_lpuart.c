/**
  ****************************************************************************************************
  * @file    fm33lc0xx_fl_lpuart.c
  * @author  FMSH Application Team
  * @brief   Src file of LPUART FL Module
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

/** @addtogroup LPUART
  * @{
  */

#ifdef FL_LPUART_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup LPUART_FL_Private_Macros
  * @{
  */
#define         IS_LPUART_INSTANCE(INSTANCE)               (((INSTANCE) == LPUART0)||\
                                                            ((INSTANCE) == LPUART1))

#define         IS_FL_LPUART_CLKSRC(__VALUE__)             (((__VALUE__) == FL_RCC_LPUART_CLK_SOURCE_LSCLK)||\
                                                            ((__VALUE__) == FL_RCC_LPUART_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_RCC_LPUART_CLK_SOURCE_RCMF))

#define         IS_FL_LPUART_BAUDRATE(__VALUE__)            (((__VALUE__) == FL_LPUART_BAUDRATE_300)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_600)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_1200)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_2400)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_4800)||\
                                                             ((__VALUE__) == FL_LPUART_BAUDRATE_9600))

#define         IS_FL_LPUART_DATAWIDTH(__VALUE__)           (((__VALUE__) == FL_LPUART_DATA_WIDTH_6B)||\
                                                             ((__VALUE__) == FL_LPUART_DATA_WIDTH_7B)||\
                                                             ((__VALUE__) == FL_LPUART_DATA_WIDTH_8B)||\
                                                             ((__VALUE__) == FL_LPUART_DATA_WIDTH_9B))

#define         IS_FL_LPUART_STOPBITS(__VALUE__)            (((__VALUE__) == FL_LPUART_STOP_BIT_WIDTH_1B)||\
                                                             ((__VALUE__) == FL_LPUART_STOP_BIT_WIDTH_2B))

#define         IS_FL_LPUART_PARITY(__VALUE__)              (((__VALUE__) == FL_LPUART_PARITY_NONE)||\
                                                             ((__VALUE__) == FL_LPUART_PARITY_EVEN)||\
                                                             ((__VALUE__) == FL_LPUART_PARITY_ODD))

#define         IS_FL_LPUART_DIRECTION(__VALUE__)           (((__VALUE__) == FL_LPUART_DIRECTION_NONE)||\
                                                             ((__VALUE__) == FL_LPUART_DIRECTION_RX)||\
                                                             ((__VALUE__) == FL_LPUART_DIRECTION_TX)||\
                                                             ((__VALUE__) == FL_LPUART_DIRECTION_TX_RX))

/**
  * @}
  */

/** @addtogroup LPUART_FL_EF_Init
  * @{
  */

/**
  * @brief  LPUART
  * @param  LPUARTx 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_LPUART_DeInit(LPUART_Type *LPUARTx)
{
    FL_ErrorStatus status = FL_PASS;
    /*  */
    assert_param(IS_LPUART_INSTANCE(LPUARTx));
    /*  */
    FL_RCC_EnablePeripheralReset();
    if(LPUARTx == LPUART0)
    {
        /*LPUART*/
        FL_RCC_EnableResetAPB1Peripheral(FL_RCC_RSTAPB_LPUART0);
        FL_RCC_DisableResetAPB1Peripheral(FL_RCC_RSTAPB_LPUART0);
        /*  */
        FL_RCC_IsEnabledGroup3BusClock(FL_RCC_GROUP3_BUSCLK_LPUART0);
        /*  */
        FL_RCC_DisableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_LPUART0);
    }
    else
        if(LPUARTx == LPUART1)
        {
            /*LPUART*/
            FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_LPUART1);
            FL_RCC_DisableResetAPB2Peripheral(FL_RCC_RSTAPB_LPUART1);
            /*  */
            FL_RCC_IsEnabledGroup3BusClock(FL_RCC_GROUP3_BUSCLK_LPUART1);
            /*  */
            FL_RCC_DisableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_LPUART1);
        }
        else
        {
            status = FL_FAIL;
        }
    /*  */
    FL_RCC_DisablePeripheralReset();
    return (status);
}

/**
  * @brief  LPUART
  *
  * @note   MCTL32768Hz
  *         
  * @param  LPUARTx  
  * @param  initStruct  @ref FL_LPUART_InitTypeDef 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_LPUART_Init(LPUART_Type *LPUARTx, FL_LPUART_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    uint16_t  MCTLVel = 0;
    /*  */
    assert_param(IS_LPUART_INSTANCE(LPUARTx));
    assert_param(IS_FL_LPUART_CLKSRC(initStruct->clockSrc));
    assert_param(IS_FL_LPUART_BAUDRATE(initStruct->baudRate));
    assert_param(IS_FL_LPUART_DATAWIDTH(initStruct->dataWidth));
    assert_param(IS_FL_LPUART_STOPBITS(initStruct->stopBits));
    assert_param(IS_FL_LPUART_PARITY(initStruct->parity));
    assert_param(IS_FL_LPUART_DIRECTION(initStruct->transferDirection));
    if(LPUARTx == LPUART0)
    {
        /**/
        FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_LPUART0);
        /**/
        FL_RCC_EnableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_LPUART0);
        /**/
        FL_RCC_SetLPUART0ClockSource(initStruct->clockSrc << RCC_OPCCR1_LPUART0CKS_Pos);
        if(initStruct->clockSrc == FL_RCC_LPUART0_CLK_SOURCE_RCMF)
        {
            FL_RCC_RCMF_Enable();
        }
    }
    else
    {
        /**/
        FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_LPUART1);
        /**/
        FL_RCC_EnableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_LPUART1);
        /**/
        FL_RCC_SetLPUART1ClockSource(initStruct->clockSrc << RCC_OPCCR1_LPUART1CKS_Pos);
        if(initStruct->clockSrc == FL_RCC_LPUART1_CLK_SOURCE_RCMF)
        {
            FL_RCC_RCMF_Enable();
        }
    }
    /**/
    if(initStruct->transferDirection & FL_LPUART_DIRECTION_TX)
    {
        do
        {
            FL_LPUART_EnableTX(LPUARTx);
        } while(FL_LPUART_IsEnabledTX(LPUARTx) != FL_SET);
    }
    if(initStruct->transferDirection & FL_LPUART_DIRECTION_RX)
    {
        do
        {
            FL_LPUART_EnableRX(LPUARTx);
        } while(FL_LPUART_IsEnabledRX(LPUARTx) != FL_SET);
    }
    /**/
    FL_LPUART_SetBaudRate(LPUARTx, initStruct->baudRate);
    /**/
    FL_LPUART_SetStopBitsWidth(LPUARTx, initStruct->stopBits);
    /**/
    FL_LPUART_SetDataWidth(LPUARTx, initStruct->dataWidth);
    /**/
    FL_LPUART_SetParity(LPUARTx, initStruct->parity);
    /*MCTL*/
    switch(initStruct->baudRate)
    {
        case FL_LPUART_BAUDRATE_9600:
            MCTLVel = 0x0552;
            break;
        case FL_LPUART_BAUDRATE_4800:
            MCTLVel = 0x1EFB;
            break;
        case FL_LPUART_BAUDRATE_2400:
            MCTLVel = 0x16DB;
            break;
        case FL_LPUART_BAUDRATE_1200:
            MCTLVel = 0x0492;
            break;
        case FL_LPUART_BAUDRATE_600:
            MCTLVel = 0x16D6;
            break;
        case FL_LPUART_BAUDRATE_300:
            MCTLVel = 0x0842;
            break;
        default:
            MCTLVel = 0x0552;
            break;
    }
    FL_LPUART_WriteBitModulation(LPUARTx, MCTLVel);
    status = FL_PASS;
    return status;
}

/**
  * @brief   @ref FL_LPUART_InitTypeDef 
  * @param  initStruct  @ref FL_LPUART_InitTypeDef 
  *
  * @retval None
  */
void FL_LPUART_StructInit(FL_LPUART_InitTypeDef *initStruct)
{
    initStruct->baudRate            = FL_LPUART_BAUDRATE_9600;
    initStruct->dataWidth           = FL_LPUART_DATA_WIDTH_8B;
    initStruct->stopBits            = FL_LPUART_STOP_BIT_WIDTH_1B;
    initStruct->parity              = FL_LPUART_PARITY_NONE ;
    initStruct->transferDirection   = FL_LPUART_DIRECTION_TX_RX;
    initStruct->clockSrc            = FL_RCC_LPUART_CLK_SOURCE_LSCLK;
}

/**
  * @}
  */

#endif /* FL_LPUART_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
