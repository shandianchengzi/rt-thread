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
/** \file pca.h
 **
 ** PCAAPI
 **  
 **
 ** History:
 **   - 2017-04-15   Husj     First version
 **
 *****************************************************************************/

#ifndef __PCA_H__
#define __PCA_H__

/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l136.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup PcaGroup Programmable Counter Array (PCA)
 **
 ******************************************************************************/
//@{

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

 /**
 ******************************************************************************
 ** \brief PCA 
 *****************************************************************************/
typedef enum en_pca_module
{
    Module0    = 0u,        ///< 0
    Module1    = 1u,        ///< 1
    Module2    = 2u,        ///< 2
    Module3    = 3u,        ///< 3
    Module4    = 4u,        ///< 4
}en_pca_module_t;

/**
 ******************************************************************************
 ** \brief PCA / (CR)
 *****************************************************************************/
typedef enum en_pca_start
{
    CRStop  = 0u,            ///< 
    CRStart = 1u,            ///< 
}en_pca_start_t;

/**
 ******************************************************************************
 ** \brief PCA IDLE / (CIDL)
 *****************************************************************************/
typedef enum en_pca_cidl
{
    IdleGoOn = 0u,            ///<  PCA
    IdleStop = 1u,            ///<  PCA 
}en_pca_cidl_t;

/**
 ******************************************************************************
 ** \brief PCA 4 WDT (WDTE)
 *****************************************************************************/
typedef enum en_pca_wdte
{
    PCAWDTDisable = 0u,            ///<  PCA4 WDT
    PCAWDTEnable  = 1u,            ///<  PCA4 WDT
}en_pca_wdte_t;

/**
 ******************************************************************************
 ** \brief PCA  (CPS)
 *****************************************************************************/
typedef enum en_pca_clksel
{
    PCAPCLKDiv32  = 0u,         ///< PCLK/32
    PCAPCLKDiv16  = 1u,         ///< PCLK/16
    PCAPCLKDiv8   = 2u,         ///< PCLK/8
    PCAPCLKDiv4   = 3u,         ///< PCLK/4
    PCAPCLKDiv2   = 4u,         ///< PCLK/2
    PCATimer0Over = 5u,         ///< timer0 overflow
    PCATimer1Over = 6u,         ///< timer1 overflow
    PCAECI        = 7u,         ///< ECI ,PCLK
}en_pca_clksel_t;

/**
 ******************************************************************************
 ** \brief PCA  (ECOM)
 *****************************************************************************/
typedef enum en_pca_ecom
{
    ECOMDisable = 0u,            ///< 
    ECOMEnable  = 1u,            ///< 
}en_pca_ecom_t;

/**
 ******************************************************************************
 ** \brief PCA  (CAPP)
 *****************************************************************************/
typedef enum en_pca_capp
{
    CAPPDisable = 0u,            ///< 
    CAPPEnable  = 1u,            ///< 
}en_pca_capp_t;

/**
 ******************************************************************************
 ** \brief PCA  (CAPN)
 *****************************************************************************/
typedef enum en_pca_capn
{
    CAPNDisable = 0u,            ///< 
    CAPNEnable  = 1u,            ///< 
}en_pca_capn_t;

/**
 ******************************************************************************
 ** \brief PCA  (MAT)
 *****************************************************************************/
typedef enum en_pca_mat
{
    MATDisable = 0u,            ///< 
    MATEnable  = 1u,            ///< 
}en_pca_mat_t;

/**
 ******************************************************************************
 ** \brief PCA  (TOG)
 *****************************************************************************/
typedef enum en_pca_tog
{
    TOGDisable = 0u,            ///< 
    TOGEnable  = 1u,            ///< 
}en_pca_tog_t;

/**
 ******************************************************************************
 ** \brief PCA 8bit (8bitPWM)
 *****************************************************************************/
typedef enum en_pca_pwm_8_bit
{
    PCA8bitPWMDisable = 0u,            ///<  PWM
    PCA8bitPWMEnable  = 1u,            ///< CCPxPWM
}en_pca_8bit_pwm_t;

/**
 ******************************************************************************
 ** \brief PCA 16bit (16bitPWM)
 *****************************************************************************/
typedef enum en_pca_pwm_16_bit
{
    PCA16bitPWMDisable = 0u,            ///< 16bitPWM 
    PCA16bitPWMEnable  = 1u,            ///< 16bitPWM 
}en_pca_16bit_pwm_t;

/**
 ******************************************************************************
 ** \brief PCA  
 *****************************************************************************/
typedef struct stc_pca_config
{
    en_pca_cidl_t     enCIDL;       ///< /
    en_pca_wdte_t     enWDTE;       ///< WDT
    en_pca_clksel_t   enCPS;        ///< 
    
    func_ptr_t        pfnPcaCb;     ///< Pca[void function(void)]
}stc_pca_config_t;

/**
 ******************************************************************************
 ** \brief PCA  
 *****************************************************************************/
typedef struct stc_pca_capmodconfig
{
    en_pca_ecom_t enECOM;                ///< 
    en_pca_capp_t enCAPP;                ///< 
    en_pca_capn_t enCAPN;                ///< 
    en_pca_mat_t  enMAT;                 ///< 
    en_pca_tog_t  enTOG;                 ///< 
    en_pca_8bit_pwm_t  en8bitPWM;        ///< 8
}stc_pca_capmodconfig_t;

/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/
//Interrupt related
//PCA
boolean_t Pca_GetIntFlag(en_pca_module_t enModule);
//PCA
boolean_t Pca_GetCntIntFlag(void);
//PCA
en_result_t Pca_ClearIntFlag(en_pca_module_t enModule);
//PCA
en_result_t Pca_ClearCntIntFlag(void);
//PCA
en_result_t Pca_EnableIrq (en_pca_module_t enModule);
//PCA
en_result_t Pca_EnableCntIrq (void);
//PCA
en_result_t Pca_DisableIrq(en_pca_module_t enModule);
//PCA
en_result_t Pca_DisableCntIrq(void);

//PCA
//PCA
en_result_t Pca_Init(stc_pca_config_t* pstcConfig);
//PCA
en_result_t Pca_CapModConfig(en_pca_module_t enModule, stc_pca_capmodconfig_t* pstcCapMod);
//PCA/
en_result_t Pca_Run(void);
en_result_t Pca_Stop(void);
//PCA16
en_result_t Pca_CmpData16Set(en_pca_module_t enModule, uint16_t u16Data);
//PCA16
uint16_t Pca_CapData16Get(en_pca_module_t enModule);
//PCA8
en_result_t Pca_CmpDataHSet(en_pca_module_t enModule, uint8_t u8Data);
//PCA8
en_result_t Pca_CmpDataLSet(en_pca_module_t enModule, uint8_t u8Data);
//PCA/
en_result_t Pca_Cnt16Set(uint16_t u16Data);
uint16_t Pca_Cnt16Get(void);
//PCA/
en_result_t Pca_CARRSet(uint16_t u16Data);
uint16_t Pca_CARRGet(void);
//PCA PWM/
en_result_t Pca_Enable16bitPWM(void);
en_result_t Pca_Disable16bitPWM(void);
//PCA
boolean_t Pca_GetCmpHighFlag(en_pca_module_t enModule);
//@} // PcaGroup

#ifdef __cplusplus
#endif


#endif /* __PCA_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


