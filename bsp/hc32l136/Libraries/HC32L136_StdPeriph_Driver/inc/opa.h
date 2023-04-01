/*******************************************************************************
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
/******************************************************************************/
/** \file OPA.h
 **
 ** Headerfile for OPA functions
 ** @link OPA Group Some description @endlink 
 **
 ** History:
 **   - 2018-04-15   Devi     First Version
 **
 ******************************************************************************/

#ifndef __OPA_H__
#define __OPA_H__

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l136.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup OPAGroup  (OPA)
  **
 ******************************************************************************/
//@{

/**
 *******************************************************************************
 ** function prototypes.
 ******************************************************************************/
/**
 *******************************************************************************
 ** \brief OPA
 ** \note
 ******************************************************************************/
typedef enum en_opa_channel
{
    OPA0 = 0u, ///<<OPA0
    OPA1 = 1u, ///<<OPA1
    OPA2 = 2u, ///<<OPA2
}en_opa_channel_t;

/**
 *******************************************************************************
 ** \brief OPA
 ** \note
 ******************************************************************************/
typedef enum en_opa_invert_pagagain
{
    Gain15         = 0u,               ///< 15
    Gain07         = 1u,               ///< 7
    Gain13_3       = 2u,               ///< 13/3
    Gain03         = 3u,               ///< 3
    Gain05_3       = 4u,               ///< 5/3
    Gain01         = 5u,               ///< 1
    Gain01_3        = 6u,               ///< 1/3
    Gain11_5       = 7u,               ///< 11/5   
}en_opa_invert_pagagain_t;

/**
 *******************************************************************************
 ** \brief OPA
 ** \note
 ******************************************************************************/
typedef enum en_opa_noinvert_pagagain
{
    Gain16         = 0u,               ///< 16
    Gain08         = 1u,               ///< 8
    Gain16_3       = 2u,               ///< 16/3
    Gain04         = 3u,               ///< 4
    Gain08_3       = 4u,               ///< 8/3
    Gain02         = 5u,               ///< 2
    Gain04_3       = 6u,               ///< 4/3
    Gain16_5       = 7u,               ///< 16/5   
}en_opa_noinvert_pagagain_t;

/**
 *******************************************************************************
 ** \brief 
 ******************************************************************************/
typedef enum opa_metergain
{
    OpaMeterGain3 = 0u,                        
    OpaMeterGain1_3 = 1u,               
    OpaMeterGain1 = 2u,                             
}en_opa_metergain_t;


/**
 *******************************************************************************
 ** \brief opa 
 ******************************************************************************/
typedef enum opa_modesel
{
    OpaUintMode     = 0u,           ///< PGA        
    OpaForWardMode  = 1u,           ///< PGA            
    OpaOppositeMode = 2u,           ///< PGA              
    OpaThreeOppMode = 3u,           ///< 3OPAPGA
    OpaThreeForMode = 4u,           ///< 3OPAPGA
    OpaDiffMode     = 5u,           ///< PGA
    OpaMeterMode    = 6u,           ///< 
    OpaGpMode       = 7u,           ///<        
}en_opa_modesel_t;

/**
 *******************************************************************************
 ** \brief opa 
 ******************************************************************************/
typedef enum opa_calsel
{
    OpaSoftMode         = 0u,           ///<      
    OpaSoftTriggerMode  = 1u,           ///<       
    OpaADCTriggerMode   = 2u,           ///< ADC                  
}en_opa_calsel_t;

/**
 ******************************************************************************
 ** \brief OPA
 *****************************************************************************/
typedef struct stc_opa_gain_config
{
    en_opa_invert_pagagain_t     enInGain;  ///< 
    en_opa_noinvert_pagagain_t   enNoInGain;  ///< 
}stc_opa_gain_config_t;


/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
///< OPA
en_result_t OPA_Init(void);
///< OPA
en_result_t OPA_DeInit(void);
///< OPA
en_result_t OPA_Operate(en_opa_channel_t enchannel ,en_opa_modesel_t enMode,stc_opa_gain_config_t *pstrGain);
///< OPA
en_result_t OPA_ThreeOperate(en_opa_modesel_t enMode,stc_opa_gain_config_t *pstrGain0,stc_opa_gain_config_t *pstrGain1,stc_opa_gain_config_t *pstrGain2);
///< OPA 
en_result_t OPA_MeterOperate(en_opa_metergain_t enGainMode);
///< OPA
en_result_t OPA_Cal(en_opa_calsel_t enCalMode);


//@} // OPA Group

#ifdef __cplusplus
#endif

#endif /* __OPA_H__ */
/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/


