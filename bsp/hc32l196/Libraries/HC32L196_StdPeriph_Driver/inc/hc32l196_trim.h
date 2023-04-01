/******************************************************************************
* Copyright (C) 2018, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by:
* Huada Semiconductor Co.,Ltd ("HDSC").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with HDSC
* components. This software is licensed by HDSC to be adapted only
* for use in systems utilizing HDSC components. HDSC shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. HDSC is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* Disclaimer:
* HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
* WARRANTY OF NONINFRINGEMENT.
* HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
* SAVINGS OR PROFITS,
* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
* FROM, THE SOFTWARE.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/
/*****************************************************************************/
/** \file trim.h
 **
 ** TRIM API
 **  
 **
 ** History:
 **   - 2018-04-21   Lux     V1.0
 **
 *****************************************************************************/

#ifndef __TRIM_H__
#define __TRIM_H__

/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"


#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup TrimGroup Clock Trimming (TRIM)
 **
 ******************************************************************************/
//@{

/******************************************************************************
 ** Global pre-processor symbols/macros ('#define')                            
 ******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

 /**
 ******************************************************************************
 ** \brief     (MON_EN)
 *****************************************************************************/
typedef enum en_trim_monitor
{
    TrimMonDisable = 0u,            ///< 
    TrimMonEnable  = 0x40u,         ///< 
}en_trim_monitor_t; 
 
 /**
 ******************************************************************************
 ** \brief / (CALCLK_SEL)
 *****************************************************************************/
typedef enum en_trim_calclksel
{
    TrimCalMskRCH = 0x000u,            ///< RCH
    TrimCalMskXTH = 0x010u,            ///< XTH
    TrimCalMskRCL = 0x020u,            ///< RCL
    TrimCalMskXTL = 0x030u,            ///< XTL
    TrimCalMskPLL = 0x100u,            ///< PLL
}en_trim_calclksel_t;

/**
 ******************************************************************************
 ** \brief  (REFCLK_SEL)
 *****************************************************************************/
typedef enum en_trim_refclksel
{
    TrimRefMskRCH    = 0x0u,            ///< RCH
    TrimRefMskXTH    = 0x2u,            ///< XTH
    TrimRefMskRCL    = 0x4u,            ///< RCL
    TrimRefMskXTL    = 0x6u,            ///< XTL
    TrimRefMskIRC10K = 0x8u,            ///< IRC10K
    TrimRefMskExtClk = 0xau,            ///< 
}en_trim_refclksel_t;

/**
 ******************************************************************************
 ** \brief 
 *****************************************************************************/
typedef enum en_trim_inttype
{
    TrimStop     = 0x01u,            ///< 
    TrimCalCntOf = 0x02u,            ///< 
    TrimXTLFault = 0x04u,            ///< XTL 
    TrimXTHFault = 0x08u,            ///< XTH 
    TrimPLLFault = 0x10u,            ///< PLL 
}en_trim_inttype_t;

/**
 ******************************************************************************
 ** \brief TRIM  
 *****************************************************************************/
typedef struct stc_trim_cfg
{
    en_trim_monitor_t    enMON;         ///< 
    en_trim_calclksel_t  enCALCLK;      ///< 
    uint32_t             u32CalCon;     ///< 
    en_trim_refclksel_t  enREFCLK;      ///< 
    uint32_t             u32RefCon;     ///< 
}stc_trim_cfg_t;

/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/
///<<
///<Trim 
en_result_t Trim_Init(stc_trim_cfg_t* pstcCfg);
///<//
void Trim_Run(void);
void Trim_Stop(void);

///<
uint32_t Trim_RefCntGet(void);
///<
uint32_t Trim_CalCntGet(void);
 
///<
////
void Trim_EnableIrq(void);
void Trim_DisableIrq(void);
///<
boolean_t Trim_GetIntFlag(en_trim_inttype_t enIntType);
///<
en_result_t Trim_ClearIntFlag(en_trim_inttype_t enIntType);

//@} // TrimGroup

#ifdef __cplusplus
#endif


#endif /* __TRIM_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


