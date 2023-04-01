/**
  *******************************************************************************************************
  * @file    fm33lc0xx_fl_divas.c
  * @author  FMSH Application Team
  * @brief   Src file of DIVAS FL Module
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

/** @addtogroup DIVAS
  * @{
  */

#ifdef FL_DIVAS_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup DIVAS_FL_Private_Macros
  * @{
  */
#define         IS_DIVAS_ALL_INSTANCE(INTENCE)              ((INTENCE) == DIV)

#define         IS_FL_DIVAS_DIVISOR(__VALUE__)              (((__VALUE__) != 0))

/**
  * @}
  */

/** @addtogroup DIVAS_FL_EF_Init
  * @{
  */

/**
  * @brief  DIVAS
  *
  * @param  DIVx 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_DIVAS_DeInit(DIV_Type *DIVx)
{
    /*  */
    assert_param(IS_DIVAS_ALL_INSTANCE(DIVx));
    /*  */
    FL_RCC_EnablePeripheralReset();
    /*  */
    FL_RCC_EnableResetAPB2Peripheral(FL_RCC_RSTAPB_DIVAS);
    FL_RCC_DisableResetAPB2Peripheral(FL_RCC_RSTAPB_DIVAS);
    /*  */
    FL_RCC_DisableGroup2BusClock(FL_RCC_GROUP2_BUSCLK_HDIV);
    /*  */
    FL_RCC_DisablePeripheralReset();
    return FL_PASS;
}

/**
  * @brief  DIVASDIV
  *
  * @param  DIVx 
  *
  * @retval 
  *         -FL_PASS 
  *         -FL_FAIL 
  */
FL_ErrorStatus FL_DIVAS_Init(DIV_Type *DIVx)
{
    /*  */
    assert_param(IS_DIVAS_ALL_INSTANCE(DIVx));
    /*  */
    FL_RCC_EnableGroup2BusClock(FL_RCC_GROUP2_BUSCLK_HDIV);
    return FL_PASS;
}

/**
  * @}
  */

/** @addtogroup DIVAS_FL_EF_Operation
  * @{
  */

/**
  * @brief 
  *
  * @param  DIVx        
  * @param  DivisorEnd  32
  * @param  Divisor     160
  * @param  Quotient     @ref int32_t  
  * @param  Residue      @ref int16_t  
  *
  * @retval 
  *         -0   
  *         -0 
  */
uint32_t FL_DIVAS_Hdiv_Calculation(DIV_Type *DIVx, int32_t DivisorEnd, int16_t Divisor, int32_t *Quotient, int16_t *Residue)
{
    uint32_t  TimeOut ;
    FL_DIV_WriteDividend_S32(DIVx, DivisorEnd);
    FL_DIV_WriteDivisor_S16(DIVx, Divisor);
    if(FL_DIV_IsActiveFlag_DividedZero(DIVx))
    {
        /*0 */
        *Quotient = 0;
        *Residue  = 0;
        return 1;
    }
    TimeOut = FL_DIVAS_SR_BUSY_TIMEOUT;
    while(FL_DIV_IsActiveFlag_Busy(DIVx))
    {
        TimeOut--;
        if(TimeOut == 0)
        {
            /* */
            *Quotient = 0;
            *Residue  = 0;
            return 3;
        }
    }
    *Quotient = FL_DIV_ReadQuotient_S32(DIVx);
    *Residue  = FL_DIV_ReadResidue_S16(DIVx);
    return 0;
}

/**
  * @}
  */

#endif /* FL_DIVAS_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
