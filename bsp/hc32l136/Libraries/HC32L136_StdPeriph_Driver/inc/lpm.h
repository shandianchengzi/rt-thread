/******************************************************************************
* Copyright (C) 2017, Huada Semiconductor Co.,Ltd All rights reserved.
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
/** \file lpm.h
 **
 ** Lpm API
 **  
 **
 ** History:
 **   - 2017-06-06   Lux     V1.0
 **
 *****************************************************************************/

#ifndef __LPM_H__
#define __LPM_H__

/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 *******************************************************************************
 ** \defgroup LpmGroup Low Power Management (LPM)
 **
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
 ** \brief  (SEVONPEND)
 *****************************************************************************/
typedef enum en_lpm_sevonpend
{
    SevPndDisable = 0u,            ///< 
    SevPndEnable  = 1u,            ///< 
}en_lpm_sevonpend_t; 
 
 /**
 ******************************************************************************
 ** \brief  (SLEEPDEEP)
 *****************************************************************************/
typedef enum en_lpm_sleepdeep
{
    SlpDpDisable = 0u,            ///< 
    SlpDpEnable  = 1u,            ///< 
}en_lpm_sleepdeep_t;

/**
 ******************************************************************************
 ** \brief  (SLEEPONEXIT)
 *****************************************************************************/
typedef enum en_lpm_sleeponexit
{
    SlpExtDisable = 0u,            ///< 
    SlpExtEnable  = 1u,            ///< 
}en_lpm_sleeponexit_t;

/**
 ******************************************************************************
 ** \brief Low Power Mode  
 *****************************************************************************/
typedef struct stc_lpm_config
{
    en_lpm_sevonpend_t   enSEVONPEND;        ///< :,WFE,.
    en_lpm_sleepdeep_t   enSLEEPDEEP;        ///< :WFI;:WFI.        
    en_lpm_sleeponexit_t enSLEEPONEXIT;      ///< :,;:.
}stc_lpm_config_t;

/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/
///<
///<
en_result_t Lpm_Config(stc_lpm_config_t* pstcConfig);
///<
void Lpm_GotoLpmMode(void);

//@} // LpmGroup

#ifdef __cplusplus
#endif


#endif /* __LPM_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


