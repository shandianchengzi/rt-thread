/**
  ******************************************************************************
  * @file    hk32f0xx_divsqrt.h
  * @brief   hk32f0xx divsqrt  file.
  *          The file is the unique include file that the application programmer
	*          is using in the C source code.it is a patch file 
  ******************************************************************************
**/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HK32F0xx_DIVSQRT_H
#define __HK32F0xx_DIVSQRT_H

#ifdef __cplusplus
 extern "C" {
#endif
 
/* Includes ------------------------------------------------------------------*/
#include "hk32f0xx.h"


#define DVSQ_BUSY_WAIT_EN                           1                                     /* 1DVSQDVSQ */
  
// DVSQ
#define DVSQ                                        DIVSQRT   

// DVSQ
#define RCC_AHBPeriph_DVSQ                          ((uint32_t)0x00000001)
#define RCC_AHBPeriph_DVSQ_CLK_Enable()             RCC->AHBENR2 |= RCC_AHBPeriph_DVSQ     /* DVSQ */
#define RCC_AHBPeriph_DVSQ_CLK_Disable()            RCC->AHBENR2 &= ~RCC_AHBPeriph_DVSQ    /* DVSQ */

/* DVSQ */
#define DVSQ_IDLE_NO_OPERATION                      ((uint32_t)0x00000000)                /* , */
#define DVSQ_IDLE_SQRT                              ((uint32_t)0x20000000)                /* , */
#define DVSQ_IDLE_DIV                               ((uint32_t)0x40000000)                /* , */
#define DVSQ_BUSY_SQRT                              ((uint32_t)0xA0000000)                /* , */
#define DVSQ_BUSY_DIV                               ((uint32_t)0xC0000000)                /* , */

/* DVSQ */
#define DVSQ_EnableDivFastStart()                   DVSQ->CSR &= ~DIVSQRT_CSR_DFS         /*  */
#define DVSQ_DisableDivFastStart()                  DVSQ->CSR |= DIVSQRT_CSR_DFS          /*  */

/* DVSQ */
#define DVSQ_ConfigDivUnsigned()                    DVSQ->CSR |= DIVSQRT_CSR_UNSIGN_DIV   /* DVSQ */
#define DVSQ_ConfigDivSigned()                      DVSQ->CSR &= ~DIVSQRT_CSR_UNSIGN_DIV  /* DVSQ */

/* DVSQ */
#define DVSQ_ConfigSqrtPresHigh()                   DVSQ->CSR |= DIVSQRT_CSR_HPRESQRT    /* DVSQ */
#define DVSQ_ConfigSqrtPresNormal()                 DVSQ->CSR &= ~DIVSQRT_CSR_HPRESQRT    /* DVSQ */

/* DVSQCSRDVSQ_CSR_DFS1,,0, */
#define DVSQ_StartDivCalc()                         DVSQ->CSR |= DIVSQRT_CSR_DIV_SRT      /*  */

/* DVSQ */
#define DVSQ_IsBusy()                               ((DVSQ->CSR & DIVSQRT_CSR_BUSY)? 1:0) /* '1';  '0' */

/* DVSQ */
#if (DVSQ_BUSY_WAIT_EN == 1)
#define DVSQ_Wait()                                 while(DVSQ_IsBusy())   
#else
#define DVSQ_Wait()    
#endif



/*DIVSQRTAPI*/
void HK_Dvsq_Init(void);
uint32_t HK_Dvsq_Sqrt(uint32_t u32Radicand, FlagStatus eIsHighPres);
uint32_t HK_Dvsq_Divsion(uint32_t u32Dividend, uint32_t u32Divisor, uint32_t *u32pRemainder, FlagStatus eIsUnsigned, FlagStatus eIsFastStart);
             
#ifdef __cplusplus
}
#endif

#endif
