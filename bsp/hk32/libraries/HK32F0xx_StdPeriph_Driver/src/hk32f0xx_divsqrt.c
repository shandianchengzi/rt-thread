/**
  *****************************************************************************************************
  * @file    hk32f0xx_divsqrt.h
  * @brief   hk32f0xx divsqrt  file.
  *          The file is the unique include file that the application programmer
    *          is using in the C source code.it is a patch file
  *****************************************************************************************************
**/


/* Define to prevent recursive inclusion -------------------------------------*/


#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/

#include "hk32f0xx_divsqrt.h"

/*******************************************************************************************************
* @function: HK_Dvsq_Init
* @brief:    DVSQ
********************************************************************************************************/
void HK_Dvsq_Init(void)
{
    RCC_AHBPeriph_DVSQ_CLK_Enable();
}

/*******************************************************************************************************
* @function: HK_Dvsq_Divsion
* @brief:    DVSQ
* @param:    u32Dividend: 32
* @param:    u32Divisor: 
* @param:    u32pRemainder: 
* @param:    u8IsUnsigned: 1-
                           0-
* @param:    u8IsFastStart: 1-()
*                           0-()
*            FlagStatus"hk32f0xx.h"
* @return:   
* @note  :   u32 32          e enum
*******************************************************************************************************/
uint32_t HK_Dvsq_Divsion(uint32_t u32Dividend, uint32_t u32Divisor, uint32_t *u32pRemainder,
                         FlagStatus eIsUnsigned, FlagStatus eIsFastStart)
{
    DVSQ_Wait();

    // 
    if (eIsUnsigned == SET)
        DVSQ_ConfigDivUnsigned();
    else
        DVSQ_ConfigDivSigned();

    // 
    if (eIsFastStart == SET)
    {
        DVSQ_EnableDivFastStart();

        DVSQ->DIVIDEND = u32Dividend;
        DVSQ->DIVISOR  = u32Divisor;

        DVSQ_Wait();

        *u32pRemainder = DVSQ->REMAINDER;
    }
    else
    {
        DVSQ_DisableDivFastStart();

        DVSQ->DIVIDEND = u32Dividend;
        DVSQ->DIVISOR  = u32Divisor;

        DVSQ_StartDivCalc();

        DVSQ_Wait();

        *u32pRemainder = DVSQ->REMAINDER;
    }

    return DVSQ->RES;
}

/*******************************************************************************************************
* @function: HK_Dvsq_Sqrt
* @brief:    DVSQ
* @param:    u32Radicand: 
* @param:    eIsHighPres: 1-
*                         0-
*                         FlagStatus"hk32f0xx.h"
* @return:   
* @note  :   u32 32          e enum
*******************************************************************************************************/
uint32_t HK_Dvsq_Sqrt(uint32_t u32Radicand, FlagStatus eIsHighPres)
{
    DVSQ_Wait();

    // 
    if (eIsHighPres == SET)
        DVSQ_ConfigSqrtPresHigh();
    else
        DVSQ_ConfigSqrtPresNormal();

    DVSQ->RADICAND = u32Radicand;

    DVSQ_Wait();

    return DVSQ->RES;
}

