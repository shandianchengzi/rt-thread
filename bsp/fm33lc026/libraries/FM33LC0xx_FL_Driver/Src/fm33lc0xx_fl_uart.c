/**
  ****************************************************************************************************
  * @file    fm33lc0xx_fl_uart.c
  * @author  FMSH Application Team
  * @brief   Src file of UART FL Module
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

/** @addtogroup UART
  * @{
  */

#ifdef FL_UART_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup UART_FL_Private_Macros
  * @{
  */


#define         IS_UART_INSTANCE(INSTANCE)              (((INSTANCE) == UART0)||\
                                                         ((INSTANCE) == UART1)||\
                                                         ((INSTANCE) == UART4)||\
                                                         ((INSTANCE) == UART5))

#define         IS_FL_UART_CLKSRC(__VALUE__)            (((__VALUE__) == FL_RCC_UART1_CLK_SOURCE_APB1CLK)||\
                                                         ((__VALUE__) == FL_RCC_UART1_CLK_SOURCE_RCHF)||\
                                                         ((__VALUE__) == FL_RCC_UART1_CLK_SOURCE_SYSCLK)||\
                                                         ((__VALUE__) == FL_RCC_UART1_CLK_SOURCE_RCMF_PSC)||\
                                                         ((__VALUE__) == FL_RCC_UART0_CLK_SOURCE_APB1CLK)||\
                                                         ((__VALUE__) == FL_RCC_UART0_CLK_SOURCE_RCHF)||\
                                                         ((__VALUE__) == FL_RCC_UART0_CLK_SOURCE_SYSCLK)||\
                                                         ((__VALUE__) == FL_RCC_UART0_CLK_SOURCE_RCMF_PSC))


#define         IS_FL_UART_DATAWIDTH(__VALUE__)           (((__VALUE__) == FL_UART_DATA_WIDTH_7B)||\
                                                           ((__VALUE__) == FL_UART_DATA_WIDTH_8B)||\
                                                           ((__VALUE__) == FL_UART_DATA_WIDTH_9B)||\
                                                           ((__VALUE__) == FL_UART_DATA_WIDTH_6B))

#define         IS_FL_UART_STOPBITS(__VALUE__)            (((__VALUE__) == FL_UART_STOP_BIT_WIDTH_1B)||\
                                                           ((__VALUE__) == FL_UART_STOP_BIT_WIDTH_2B))

#define         IS_FL_UART_PARITY(__VALUE__)              (((__VALUE__) == FL_UART_PARITY_NONE)||\
                                                           ((__VALUE__) == FL_UART_PARITY_EVEN)||\
                                                           ((__VALUE__) == FL_UART_PARITY_ODD))

#define         IS_FL_UART_DIRECTION(__VALUE__)           (((__VALUE__) == FL_UART_DIRECTION_NONE)||\
                                                           ((__VALUE__) == FL_UART_DIRECTION_RX)||\
                                                           ((__VALUE__) == FL_UART_DIRECTION_TX)||\
                                                           ((__VALUE__) == FL_UART_DIRECTION_TX_RX))

#define         IS_FL_UART_INFRA_MODULATION(__VALUE__)    (((__VALUE__) == FL_DISABLE)||\
                                                           ((__VALUE__) == FL_ENABLE))


#define         IS_FL_UART_INFRARED_POLARITY(__VALUE__)        (((__VALUE__) == FL_UART_INFRARED_POLARITY_NORMAL)||\
                                                                ((__VALUE__) == FL_UART_INFRARED_POLARITY_INVERT))

#define         IS_FL_UART_INFRARED_MODULATION_DUTY(__VALUE__) (((__VALUE__) <= 100))


/**
  * @}
  */

/** @addtogroup UART_FL_EF_Init
  * @{
  */

/**
  * @brief  UART
  * @param  UARTx 
  * @retval :
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_UART_DeInit(UART_Type *UARTx)
{
    FL_ErrorStatus status = FL_PASS;
    /*  */
    assert_param(IS_UART_INSTANCE(UARTx));
    /*  */
    FL_RCC_EnablePeripheralReset();
    if(UARTx == UART0)
    {
        /*UART*/
        FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_UART0);
        FL_RCC_DisableResetAPB2Peripheral(FL_RCC_RSTAPB_UART0);
        /*  */
        FL_RCC_DisableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_UART0);
        /*  */
        FL_RCC_DisableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_UART0);
    }
    else
        if(UARTx == UART1)
        {
            /*UART*/
            FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_UART1);
            FL_RCC_DisableResetAPB2Peripheral(FL_RCC_RSTAPB_UART1);
            /*  */
            FL_RCC_DisableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_UART1);
            /*  */
            FL_RCC_DisableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_UART1);
        }
        else
            if(UARTx == UART4)
            {
                /*UART*/
                FL_RCC_EnableResetAPB1Peripheral(FL_RCC_RSTAPB_UART4);
                FL_RCC_DisableResetAPB1Peripheral(FL_RCC_RSTAPB_UART4);
                /*  */
                FL_RCC_DisableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_UART4);
            }
            else
                if(UARTx == UART5)
                {
                    /*UART*/
                    FL_RCC_EnableResetAPB1Peripheral(FL_RCC_RSTAPB_UART5);
                    FL_RCC_DisableResetAPB1Peripheral(FL_RCC_RSTAPB_UART5);
                    /*  */
                    FL_RCC_DisableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_UART5);
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
  * @brief  UART
  *
  * @param  UARTx  
  * @param  initStruct  @ref FL_UART_InitTypeDef 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_UART_Init(UART_Type *UARTx, FL_UART_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    uint32_t Fclk = 0, baudRate = 0;
    /*  */
    assert_param(IS_UART_INSTANCE(UARTx));
    assert_param(IS_FL_UART_CLKSRC(initStruct->clockSrc));
    assert_param(IS_FL_UART_DATAWIDTH(initStruct->dataWidth));
    assert_param(IS_FL_UART_PARITY(initStruct->parity));
    assert_param(IS_FL_UART_STOPBITS(initStruct->stopBits));
    assert_param(IS_FL_UART_DIRECTION(initStruct->transferDirection));
    if(UARTx == UART0)
    {
        /**/
        FL_RCC_SetUART0ClockSource(initStruct->clockSrc);
        /* baudrate , */
        switch(initStruct->clockSrc)
        {
            case FL_RCC_UART0_CLK_SOURCE_APB1CLK:
                Fclk = FL_RCC_GetAPB1ClockFreq();
                break;
            case FL_RCC_UART0_CLK_SOURCE_RCHF:
                Fclk = FL_RCC_GetRCHFClockFreq();
                break;
            case FL_RCC_UART0_CLK_SOURCE_SYSCLK:
                Fclk = FL_RCC_GetSystemClockFreq();
                break;
            case FL_RCC_UART0_CLK_SOURCE_RCMF_PSC:
                Fclk = FL_RCC_GetRCMFClockFreq();
                break;
        }
        baudRate = Fclk / initStruct->baudRate - 1;
    }
    if(UARTx == UART1)
    {
        /**/
        FL_RCC_SetUART1ClockSource(initStruct->clockSrc);
        /* baudrate , */
        switch(initStruct->clockSrc)
        {
            case FL_RCC_UART1_CLK_SOURCE_APB1CLK:
                Fclk = FL_RCC_GetAPB1ClockFreq();
                break;
            case FL_RCC_UART1_CLK_SOURCE_RCHF:
                Fclk = FL_RCC_GetRCHFClockFreq();
                break;
            case FL_RCC_UART1_CLK_SOURCE_SYSCLK:
                Fclk = FL_RCC_GetSystemClockFreq();
                break;
            case FL_RCC_UART1_CLK_SOURCE_RCMF_PSC:
                Fclk = FL_RCC_GetRCMFClockFreq();
                break;
        }
        baudRate = Fclk / initStruct->baudRate - 1;
    }
    if(UARTx == UART0)
    {
        /**/
        FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_UART0);
        /**/
        FL_RCC_EnableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_UART0);
    }
    else
        if(UARTx == UART1)
        {
            /**/
            FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_UART1);
            /**/
            FL_RCC_EnableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_UART1);
        }
        else
            if(UARTx == UART4)
            {
                /**/
                FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_UART4);
                Fclk = FL_RCC_GetAPB2ClockFreq();
                baudRate = Fclk / initStruct->baudRate - 1;
            }
            else
                if(UARTx == UART5)
                {
                    FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_UART5);
                    Fclk = FL_RCC_GetAPB2ClockFreq();
                    baudRate = Fclk / initStruct->baudRate - 1;
                }
    /**/
    if(initStruct->transferDirection & FL_UART_DIRECTION_TX)
    {
        FL_UART_EnableTX(UARTx);
    }
    if(initStruct->transferDirection & FL_UART_DIRECTION_RX)
    {
        FL_UART_EnableRX(UARTx);
    }
    /**/
    FL_UART_WriteBaudRate(UARTx, baudRate);
    /**/
    FL_UART_SetStopBitsWidth(UARTx, initStruct->stopBits);
    /**/
    FL_UART_SetDataWidth(UARTx, initStruct->dataWidth);
    /**/
    FL_UART_SetParity(UARTx, initStruct->parity);
    status = FL_PASS;
    return status;
}

/**
  * @brief  UART
  *
  * @param  UARTx 
  *
  * @param  initStruct  @ref FL_UART_InfraRed_InitTypeDef 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_UART_InfraRed_Init(UART_Type *UARTx, FL_UART_InfraRed_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    uint32_t  tempTZBRG = 0, tempTH = 0;
    /*  */
    assert_param(IS_UART_INSTANCE(UARTx));
    assert_param(IS_FL_UART_INFRARED_POLARITY(initStruct->polarity));
    assert_param(IS_FL_UART_INFRARED_MODULATION_DUTY(initStruct->modulationDuty));
    FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_UARTIR);
    /**/
    FL_UART_EnableIRModulation(UARTx);
    /**/
    FL_UART_SetIRPolarity(UART, initStruct->polarity);
    /**/
    tempTZBRG = (uint32_t)((FL_RCC_GetAPB1ClockFreq() * 1.0) / initStruct->modulationFrequency - 1);
    /*  */
    if((tempTZBRG >> 4) != 0)
    {
        tempTH = (uint32_t)(((float)initStruct->modulationDuty / 100.0) * ((float)(tempTZBRG + 1) / (float)(tempTZBRG >> 4)) + 0.5);
    }
    else
    {
        tempTH = (uint32_t)(((float)initStruct->modulationDuty / 100.0) * (float)(tempTZBRG + 1) + 0.5);
    }
    /* 95% */
    tempTH = ((float)((tempTZBRG >> 4) * tempTH) / (float)(tempTZBRG + 1)) < 0.95f ? tempTH : tempTH - 1;
    /*  */
    FL_UART_WriteIRModulationDuty(UART, tempTH);
    FL_UART_WriteIRModulationFrequency(UART, tempTZBRG);
    status = FL_PASS;
    return status;
}

/**
  * @brief   @ref FL_UART_InfraRed_InitTypeDef 
  * @param  initStruct  @ref FL_UART_InfraRed_InitTypeDef 
  *
  * @retval None
  */
void FL_UART_InfraRed_StructInit(FL_UART_InfraRed_InitTypeDef *initStruct)
{
    initStruct->polarity                  = FL_UART_INFRARED_POLARITY_NORMAL;
    initStruct->modulationDuty            = 50;
    initStruct->modulationFrequency       = 38000;
}

/**
  * @brief   @ref FL_UART_InitTypeDef 
  * @param  initStruct  @ref FL_UART_InitTypeDef 
  *
  * @retval None
  */
void FL_UART_StructInit(FL_UART_InitTypeDef *initStruct)
{
    initStruct->baudRate            = 115200;
    initStruct->dataWidth           = FL_UART_DATA_WIDTH_8B;
    initStruct->stopBits            = FL_UART_STOP_BIT_WIDTH_1B;
    initStruct->parity              = FL_UART_PARITY_EVEN ;
    initStruct->transferDirection   = FL_UART_DIRECTION_TX_RX;
    initStruct->clockSrc            = 0;
}

/**
  * @}
  */

#endif /* FL_UART_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
