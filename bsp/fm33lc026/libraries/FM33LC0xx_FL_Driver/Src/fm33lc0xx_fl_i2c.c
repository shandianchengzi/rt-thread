/**
  *******************************************************************************************************
  * @file    fm33lc0xx_fl_i2c.c
  * @author  FMSH Application Team
  * @brief   Src file of I2C FL Module
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

/** @addtogroup I2C
  * @{
  */

#ifdef FL_I2C_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup I2C_FL_Private_Macros
  * @{
  */

#define         IS_FL_I2C_INSTANCE(INSTANCE)                    ((INSTANCE) == I2C)

#define         IS_FL_I2C_BAUDRATE(__VALUE__)                   (((__VALUE__) > 0 )&&((__VALUE__) <= 1000000))

#define         IS_FL_I2C_CLOCKSRC(__VALUE__)                   (((__VALUE__) == FL_RCC_I2C_CLK_SOURCE_APB1CLK )||\
                                                                 ((__VALUE__) == FL_RCC_I2C_CLK_SOURCE_RCHF)||\
                                                                 ((__VALUE__) == FL_RCC_I2C_CLK_SOURCE_SYSCLK)||\
                                                                 ((__VALUE__) == FL_RCC_I2C_CLK_SOURCE_RCMF_PSC ))

#define         IS_FL_I2C_MSATER_TIMEOUT(__VALUE__)             (((__VALUE__) == FL_IWDT_PERIOD_125MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_16000MS))


#define         IS_FL_I2C_SLAVE_ACK(__VALUE__)                  (((__VALUE__) == FL_ENABLE)||\
                                                                 ((__VALUE__) == FL_DISABLE))



#define         IS_FL_I2C_ANGLOGFILTER(__VALUE__)               (((__VALUE__) == FL_ENABLE)||\
                                                                 ((__VALUE__) == FL_DISABLE))

#define         IS_FL_I2C_ADDRSIZE10BIT(__VALUE__)              (((__VALUE__) == FL_ENABLE)||\
                                                                 ((__VALUE__) == FL_DISABLE))

#define         IS_FL_I2C_SLAVE_SCLSEN(__VALUE__)               (((__VALUE__) == FL_ENABLE)||\
                                                                 ((__VALUE__) == FL_DISABLE))

/**
  * @}
  */

/** @addtogroup I2C_FL_EF_Init
  * @{
  */

/**
  * @brief  I2C.
  * @param  I2Cx 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_I2C_DeInit(I2C_Type *I2Cx)
{
    assert_param(IS_FL_I2C_INSTANCE(I2Cx));
    /*  */
    FL_RCC_EnablePeripheralReset();
    /* I2C */
    FL_RCC_EnableResetAPB1Peripheral(FL_RCC_RSTAPB_I2C);
    FL_RCC_DisableResetAPB1Peripheral(FL_RCC_RSTAPB_I2C);
    /*  */
    FL_RCC_DisableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_I2C);
    FL_RCC_DisableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_I2C);
    /*  */
    FL_RCC_DisablePeripheralReset();
    return FL_PASS;
}

/**
  * @brief  I2C.
  * @param  I2Cx 
  * @param  I2C_InitStruct  @ref FL_I2C_MasterMode_InitTypeDef 
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_I2C_MasterMode_Init(I2C_Type *I2Cx, FL_I2C_MasterMode_InitTypeDef *I2C_InitStruct)
{
    uint32_t I2C_Clk_Freq = 0, BRG = 0;
    assert_param(IS_FL_I2C_INSTANCE(I2Cx));
    assert_param(IS_FL_I2C_CLOCKSRC(I2C_InitStruct->clockSource));
    assert_param(IS_FL_I2C_BAUDRATE(I2C_InitStruct->baudRate));
    /*  */
    FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_I2C);
    FL_RCC_EnableGroup1OperationClock(FL_RCC_GROUP1_OPCLK_I2C);
    /* I2C */
    FL_RCC_SetI2CClockSource(I2C_InitStruct->clockSource);
    /*  */
    switch(I2C_InitStruct->clockSource)
    {
        case FL_RCC_I2C_CLK_SOURCE_APB1CLK:
            I2C_Clk_Freq = FL_RCC_GetAPB1ClockFreq();
            break;
        case FL_RCC_I2C_CLK_SOURCE_RCHF:
            I2C_Clk_Freq = FL_RCC_GetRCHFClockFreq();
            break;
        case FL_RCC_I2C_CLK_SOURCE_SYSCLK:
            I2C_Clk_Freq = FL_RCC_GetSystemClockFreq();
            break;
        case FL_RCC_I2C_CLK_SOURCE_RCMF_PSC:
            I2C_Clk_Freq = FL_RCC_GetRCMFClockFreq();
            break;
        default:
            break;
    }
    /*  */
    BRG = (uint32_t)(I2C_Clk_Freq / (2 * I2C_InitStruct->baudRate)) - 1;
    FL_I2C_Master_WriteSCLHighWidth(I2Cx, BRG);
    FL_I2C_Master_WriteSCLLowWidth(I2Cx, BRG);
    FL_I2C_Master_WriteSDAHoldTime(I2Cx, (uint32_t)(BRG / 2.0 + 0.5));
    /*  */
    FL_I2C_Master_Enable(I2C);
    return FL_PASS;
}

/**
  * @brief   @ref FL_I2C_MasterMode_InitTypeDef 
  * @param  I2C_InitStruct  @ref FL_I2C_MasterMode_InitTypeDef 
  *
  * @retval None
  */
void FL_I2C_MasterMode_StructInit(FL_I2C_MasterMode_InitTypeDef *I2C_InitStruct)
{
    I2C_InitStruct->clockSource = FL_RCC_I2C_CLK_SOURCE_RCHF;
    I2C_InitStruct->baudRate = 40000;
}

/**
  * @brief  I2C.
  * @param  I2Cx 
  * @param  I2C_InitStruct  @ref FL_I2C_SlaveMode_InitTypeDef .
  * @note   
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_I2C_SlaveMode_Init(I2C_Type *I2Cx, FL_I2C_SlaveMode_InitTypeDef *I2C_InitStruct)
{
    assert_param(IS_FL_I2C_INSTANCE(I2Cx));
    assert_param(IS_FL_I2C_SLAVE_ACK(I2C_InitStruct->ACK));
    assert_param(IS_FL_I2C_ADDRSIZE10BIT(I2C_InitStruct->ownAddrSize10bit));
    assert_param(IS_FL_I2C_SLAVE_SCLSEN(I2C_InitStruct->SCLSEN));
    /*  */
    FL_RCC_EnableGroup3BusClock(FL_RCC_GROUP3_BUSCLK_I2C);
    /* SDA */
    FL_I2C_Slave_EnableSDAStretching(I2Cx);
    /* SCL */
    FL_I2C_Slave_EnableSCLAnalogFilter(I2Cx);
    /* ACK */
    if(I2C_InitStruct->ACK == FL_ENABLE)
    {
        FL_I2C_Slave_EnableACK(I2Cx);
    }
    else
    {
        FL_I2C_Slave_DisableACK(I2Cx);
    }
    /*    */
    if(I2C_InitStruct->ownAddrSize10bit == FL_ENABLE)
    {
        FL_I2C_Slave_Enable10BitAddress(I2Cx);
        FL_I2C_Slave_WriteSlaveAddress(I2Cx, I2C_InitStruct->ownAddr);
    }
    else
    {
        FL_I2C_Slave_Disable10BitAddress(I2Cx);
        FL_I2C_Slave_WriteSlaveAddress(I2Cx, I2C_InitStruct->ownAddr & 0x7F);
    }
    /*  */
    if(I2C_InitStruct->SCLSEN == FL_ENABLE)
    {
        FL_I2C_Slave_EnableSCLStretching(I2Cx);
    }
    else
    {
        FL_I2C_Slave_DisableSCLStretching(I2Cx);
    }
    /*  */
    FL_I2C_Slave_Enable(I2Cx);
    return FL_PASS;
}

/**
  * @brief   @ref FL_I2C_SlaveMode_InitTypeDef 
  * @param  I2C_InitStruct  @ref FL_I2C_SlaveMode_InitTypeDef 
  *
  * @retval None
  */

void FL_I2C_SlaveMode_StructInit(FL_I2C_SlaveMode_InitTypeDef *I2C_InitStruct)
{
    I2C_InitStruct->ACK                 = FL_ENABLE;
    I2C_InitStruct->ownAddr             = 0x55;
    I2C_InitStruct->ownAddrSize10bit    = FL_DISABLE;
    I2C_InitStruct->SCLSEN              = FL_DISABLE;
}

/**
  * @}
  */

#endif /* FL_I2C_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
