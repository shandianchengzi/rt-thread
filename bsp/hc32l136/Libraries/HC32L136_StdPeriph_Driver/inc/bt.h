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
/** \file bt.h
 **
 ** API
 ** @link BT Group Some description @endlink
 **
 ** History:
 **   - 2018-04-18   Husj     First Version
 **
 *****************************************************************************/

#ifndef __BT_H__
#define __BT_H__

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
 ** \defgroup BtGroup Base Timer (BT)
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
 ** \brief 
 *****************************************************************************/
typedef enum en_bt_unit
{
    TIM0    = 0u,           ///< Timer 0
    TIM1    = 1u,           ///< Timer 1
    TIM2    = 2u,           ///< Timer 2
}en_bt_unit_t;

/**
 ******************************************************************************
 ** \brief  (MODE)(0/1/23)
 *****************************************************************************/
typedef enum en_bt_work_mode
{
    BtWorkMode0  = 0u,         ///< 
    BtWorkMode1  = 1u,         ///< PWC
    BtWorkMode2  = 2u,         ///< 
    BtWorkMode3  = 3u,         ///< 
}en_bt_work_mode_t;

/**
 ******************************************************************************
 ** \brief  (GATE_P)(0)
 *****************************************************************************/
typedef enum en_bt_m0_gatep
{
    BtGatePositive = 0u,            ///< 
    BtGateOpposite = 1u,            ///< 
}en_bt_m0_gatep_t;

/**
 ******************************************************************************
 ** \brief TIM  (PRS)(0/1/23)
 *****************************************************************************/
typedef enum en_bt_cr_timclkdiv
{
    BtPCLKDiv1   = 0u,           ///< Div 1
    BtPCLKDiv2   = 1u,           ///< Div 2
    BtPCLKDiv4   = 2u,           ///< Div 4
    BtPCLKDiv8   = 3u,           ///< Div 8
    BtPCLKDiv16  = 4u,           ///< Div 16
    BtPCLKDiv32  = 5u,           ///< Div 32
    BtPCLKDiv64  = 6u,           ///< Div 64
    BtPCLKDiv256 = 7u,           ///< Div 256
}en_bt_cr_timclkdiv_t;

/**
 ******************************************************************************
 ** \brief / (CT)(0/1/23)
 *****************************************************************************/
typedef enum en_bt_cr_ct
{
    BtTimer   = 0u,            ///< PCLK
    BtCounter = 1u,            ///< ETR
}en_bt_cr_ct_t;


/**
 ******************************************************************************
 ** \brief  (MD)(0)
 *****************************************************************************/
typedef enum en_bt_m0cr_md
{
    Bt32bitFreeMode  = 0u,         ///< 32/
    Bt16bitArrMode  = 1u,         ///< 16/
}en_bt_m0cr_md_t;

/**
 ******************************************************************************
** \brief BT0/BT1/BT2(0/1/23)
 *****************************************************************************/
typedef enum en_bt_irq_type
{
    BtUevIrq   = 0u,         ///< /
    BtCA0Irq   = 2u,         ///< /A(1/23)
    BtCB0Irq   = 5u,         ///< /B(23)
    BtCA0E     = 8u,         ///< CH0A(23),
    BtCB0E     = 11u,        ///< CH0B(23),
    BtBkIrq    = 14u,        ///< (23)
    BtTrigIrq  = 15u,        ///< (23)   
}en_bt_irq_type_t;

/**
 ******************************************************************************
 ** \brief  (Edg1stEdg2nd)(1)
 *****************************************************************************/
typedef enum en_bt_m1cr_Edge
{
    BtPwcRiseToRise  = 0u,            ///< ()
    BtPwcFallToRise  = 1u,            ///< ()
    BtPwcRiseToFall  = 2u,            ///< ()
    BtPwcFallToFall  = 3u,            ///< ()
}en_bt_m1cr_Edge_t;

/**
 ******************************************************************************
 ** \brief PWC (Oneshot)(1)
 *****************************************************************************/
typedef enum en_bt_m1cr_oneshot
{
    BtPwcCycleDetect    = 0u,         ///< PWC
    BtPwcOneShotDetect  = 1u,         ///< PWC
}en_bt_m1cr_oneshot_t;

/**
 ******************************************************************************
 ** \brief PWC IA0 (IA0S)(1)
 *****************************************************************************/
typedef enum en_bt_m1_mscr_ia0s
{
    BtIA0Input    = 0u,         ///< IAO
    BtXORInput    = 1u,         ///< IA0 ETR GATE XOR(TIM0/1/2)/IA0 IA1 IA2 XOR(TIM3)
}en_bt_m1_mscr_ia0s_t;

/**
 ******************************************************************************
 ** \brief PWC IB0 (IA0S)(1)
 *****************************************************************************/
typedef enum en_bt_m1_mscr_ib0s
{
    BtIB0Input    = 0u,         ///< IBO
    BtTsInput     = 1u,         ///< TS
}en_bt_m1_mscr_ib0s_t;

/**
 ******************************************************************************
 ** \brief   (CCPA0/CCPB0/ETP/BKP)(1/23)
 *****************************************************************************/
typedef enum en_bt_port_polarity
{
    BtPortPositive      = 0u,         ///< 
    BtPortOpposite      = 1u,         ///< 
}en_bt_port_polarity_t;

/**
 ******************************************************************************
 ** \brief  (FLTET/FLTA0/FLAB0)(1/23)
 *****************************************************************************/
typedef enum en_bt_flt
{
    BtFltNone          = 0u,         ///< 
    BtFltPCLKCnt3      = 4u,         ///< PCLK 3
    BtFltPCLKDiv4Cnt3  = 5u,         ///< PCLK/4 3
    BtFltPCLKDiv16Cnt3 = 6u,         ///< PCLK/16 3
    BtFltPCLKDiv64Cnt3 = 7u,         ///< PCLK/64 3
}en_bt_flt_t;

/**
 ******************************************************************************
 ** \brief   (OCMA/OCMB)(23)
 *****************************************************************************/
typedef enum en_bt_m23_fltr_ocm
{
    BtForceLow      = 0u,         ///< 0
    BtForceHigh     = 1u,         ///< 1
    BtCMPForceLow   = 2u,         ///< 0
    BtCMPForceHigh  = 3u,         ///< 1
    BtCMPInverse    = 4u,         ///< 
    BtCMPOnePrdHigh = 5u,         ///< 
    BtPWMMode1      = 6u,         ///< PWM mode 1
    BtPWMMode2      = 7u,         ///< PWM mode 2
}en_bt_m23_fltr_ocm_t;

/**
 ******************************************************************************
 ** \brief TS (TS)(1/23)
 *****************************************************************************/
typedef enum en_bt_mscr_ts
{
    BtTs0ETR        = 0u,         ///< ETR
    BtTs1TIM0TRGO   = 1u,         ///< Timer0TRGO
    BtTs2TIM1TRGO   = 2u,         ///< Timer1TRGO
    BtTs3TIM2TRGO   = 3u,         ///< Timer2TRGO
    BtTs4TIM3TRGO   = 4u,         ///< Timer3TRGO
    //BtTs5IA0ED    = 5u,         ///< 
    BtTs6IAFP       = 6u,         ///< CH0A 
    BtTs7IBFP       = 7u,         ///< CH0B 
}en_bt_mscr_ts_t;

/**
 ******************************************************************************
 ** \brief PWM (COMP)(23)
 *****************************************************************************/
typedef enum en_bt_m23cr_comp
{
    BtIndependentPWM      = 0u,         ///< PWM
    BtComplementaryPWM    = 1u,         ///< PWM
}en_bt_m23cr_comp_t;

/**
 ******************************************************************************
 ** \brief  (DIR)(23)
 *****************************************************************************/
typedef enum en_bt_m23cr_dir
{
    BtCntUp      = 0u,         ///< 
    BtCntDown    = 1u,         ///< 
}en_bt_m23cr_dir_t;

/**
 ******************************************************************************
 ** \brief  (PWM2S)(23)
 *****************************************************************************/
typedef enum en_bt_m23cr_pwm2s
{
    BtDoublePointCmp      = 0u,         ///< CCRA,CCRBOCREFA
    BtSinglePointCmp      = 1u,         ///< CCRAOCREFA
}en_bt_m23cr_pwm2s_t;

/**
 ******************************************************************************
 ** \brief GATEPWM  (CSG)(23)
 *****************************************************************************/
typedef enum en_bt_m23cr_csg
{
     BtPWMCompGateCmpOut    = 0u,         ///< PWMGate
     BtPWMCompGateCapIn     = 1u,         ///< PWMGate
}en_bt_m23cr_csg_t;


/**
 ******************************************************************************
 ** \brief   (CCR0A,CCR0B)(23)
 *****************************************************************************/
typedef enum en_bt_m23_ccrx
{
     BtCCR0A    = 0u,         ///< CCR0A
     BtCCR0B    = 1u,         ///< CCR0B
}en_bt_m23_ccrx_t;

/**
 ******************************************************************************
 ** \brief  OCREF  (OCCS)(23)
 *****************************************************************************/
typedef enum en_bt_m23ce_occs
{
     BtOC_Ref_Clr  = 0u,         ///< VCOC_Ref_Clr
     BtETRf        = 1u,         ///< ETRf
}en_bt_m23ce_occs_t;

/**
 ******************************************************************************
 ** \brief    (CIS/CISB)(23)
 *****************************************************************************/
typedef enum en_bt_m23_cisa_cisb
{
     BtCmpIntNone        = 0u,         ///< 
     BtCmpIntRise        = 1u,         ///< 
     BtCmpIntFall        = 2u,         ///< 
     BtCmpIntRiseFall    = 3u,         ///< 
}en_bt_m23_cisa_cisb_t;

/**
 ******************************************************************************
 ** \brief BT - CHx(BKSA/BKSB)(23)
 **
 ** \note
 ******************************************************************************/
typedef enum en_bt_m23_crch0_bks
{
    BtCHxBksHiZ         = 0u,         ///< CHx
    BtCHxBksNorm        = 1u,         ///< CHx
    BtCHxBksLow         = 2u,         ///< CHx
    BtCHxBksHigh        = 3u,         ///< CHx
}en_bt_m23_crch0_bks_t;

/**
 ******************************************************************************
** \brief BT - CHx(CRx/CFx)(23)
 **
 ** \note
 ******************************************************************************/
typedef enum en_bt_m23_crch0_cfx_crx
{
    BtCHxCapNone        = 0u,         ///< CHx
    BtCHxCapRise        = 1u,         ///< CHx
    BtCHxCapFall        = 2u,         ///< CHx
    BtCHxCapFallRise    = 3u,         ///< CHx
}en_bt_m23_crch0_cfx_crx_t;

/**
 ******************************************************************************
** \brief BT - CHx(CSA/CSB)(23)
 **
 ** \note
 ******************************************************************************/
typedef enum en_bt_m23_crch0_csa_csb
{
    BtCHxCmpMode        = 0u,         ///< CHx
    BtCHxCapMode        = 1u,         ///< CHx
}en_bt_m23_crch0_csa_csb_t;

/**
 ******************************************************************************
 ** \brief   DMA  (CCDS)(23)
 *****************************************************************************/
typedef enum en_bt_m23_mscr_ccds
{
     BtCmpTrigDMA  = 0u,         ///< DMA
     BtUEVTrigDMA  = 1u,         ///< DMA
}en_bt_m23_mscr_ccds_t;

/**
 ******************************************************************************
 ** \brief    (MSM)(23)
 *****************************************************************************/
typedef enum en_bt_m23_mscr_msm
{
     BtSlaveMode    = 0u,         ///< 
     BtMasterMode   = 1u,         ///< 
}en_bt_m23_mscr_msm_t;

/**
 ******************************************************************************
 ** \brief    (MMS)(23)
 *****************************************************************************/
typedef enum en_bt_m23_mscr_mms
{
     BtMasterUG         = 0u,         ///< UG()
     BtMasterCTEN       = 1u,         ///< CTEN
     BtMasterUEV        = 2u,         ///< UEV
     BtMasterCMPSO      = 3u,         ///< 
     BtMasterOCA0Ref    = 4u,         ///< OCA0_Ref
     BtMasterOCB0Ref    = 5u,         ///< OCB0_Ref
     //BtMasterOCB0Ref  = 6u,
     //BtMasterOCB0Ref  = 7u,
}en_bt_m23_mscr_mms_t;

/**
 ******************************************************************************
 ** \brief    (SMS)(23)
 *****************************************************************************/
typedef enum en_bt_m23_mscr_sms
{
     BtSlaveIClk        = 0u,         ///< 
     BtSlaveResetTIM    = 1u,         ///< 
     BtSlaveTrigMode    = 2u,         ///< 
     BtSlaveEClk        = 3u,         ///< 
     BtSlaveCodeCnt1    = 4u,         ///< 1
     BtSlaveCodeCnt2    = 5u,         ///< 2
     BtSlaveCodeCnt3    = 6u,         ///< 3
     BtSlaveGateCtrl    = 7u,         ///< 
}en_bt_m23_mscr_sms_t;

/**
 ******************************************************************************
 ** \brief  (CTEN)
 *****************************************************************************/
typedef enum en_bt_start
{
    BtCTENDisable = 0u,            ///< 
    BtCTENEnable  = 1u,            ///< 
}en_bt_start_t;

/**
 ******************************************************************************
 ** \brief BaseTimer mode0 (0)
 *****************************************************************************/
typedef struct stc_bt_mode0_config
{
    en_bt_work_mode_t     enWorkMode;       ///< 
    en_bt_m0_gatep_t      enGateP;          ///< 
    boolean_t             bEnGate;          ///< 
    en_bt_cr_timclkdiv_t  enPRS;            ///< 
    boolean_t             bEnTog;           ///< 
    en_bt_cr_ct_t         enCT;             ///< /
    en_bt_m0cr_md_t       enCntMode;        ///< 
    
    func_ptr_t            pfnTim0Cb;        ///< Timer0[void function(void)]
    func_ptr_t            pfnTim1Cb;        ///< Timer1[void function(void)]
    func_ptr_t            pfnTim2Cb;        ///< Timer2[void function(void)]
}stc_bt_mode0_config_t;

/**
 ******************************************************************************
 ** \brief BaseTimer mode1 (1)
 *****************************************************************************/
typedef struct stc_bt_mode1_config
{
    en_bt_work_mode_t     enWorkMode;       ///< 
    en_bt_cr_timclkdiv_t  enPRS;            ///< 
    en_bt_cr_ct_t         enCT;             ///< /
    en_bt_m1cr_oneshot_t  enOneShot;        ///< /
    
    
    func_ptr_t          pfnTim0Cb;        ///< Timer0[void function(void)]
    func_ptr_t          pfnTim1Cb;        ///< Timer1[void function(void)]
    func_ptr_t          pfnTim2Cb;        ///< Timer2[void function(void)]
}stc_bt_mode1_config_t;

/**
 ******************************************************************************
 ** \brief PWC(1)
 *****************************************************************************/
typedef struct stc_bt_pwc_input_config
{
    en_bt_mscr_ts_t          enTsSel;       ///< 
    en_bt_m1_mscr_ia0s_t     enIA0Sel;      ///< CHA0
    en_bt_m1_mscr_ib0s_t     enIB0Sel;      ///< CHB0
    en_bt_port_polarity_t    enETRPhase;    ///< ETR
    en_bt_flt_t              enFltETR;      ///< ETR
    en_bt_flt_t              enFltIA0;      ///< CHA0
    en_bt_flt_t              enFltIB0;      ///< CHB0
}stc_bt_pwc_input_config_t;

/**
 ******************************************************************************
 ** \brief BaseTimer mode23 (23)
 *****************************************************************************/
typedef struct stc_bt_mode23_config
{
    en_bt_work_mode_t         enWorkMode;       ///< 
    en_bt_m23cr_dir_t         enCntDir;         ///< 
    en_bt_cr_timclkdiv_t      enPRS;            ///< 
    en_bt_cr_ct_t             enCT;             ///< /
    en_bt_m23cr_comp_t        enPWMTypeSel;     ///< PWM/
    en_bt_m23cr_pwm2s_t       enPWM2sSel;       ///< OCREFA
    boolean_t                 bOneShot;         ///< /
    boolean_t                 bURSSel;          ///< 
    
    func_ptr_t                pfnTim0Cb;        ///< Timer0[void function(void)]
    func_ptr_t                pfnTim1Cb;        ///< Timer1[void function(void)]
    func_ptr_t                pfnTim2Cb;        ///< Timer2[void function(void)]
}stc_bt_mode23_config_t;

/**
 ******************************************************************************
 ** \brief GATEPWM (23)
 *****************************************************************************/
typedef struct stc_bt_m23_gate_config
{
    en_bt_m23cr_csg_t        enGateFuncSel;      ///< Gate
    boolean_t                bGateRiseCap;       ///< GATE
    boolean_t                bGateFallCap;       ///< GATE
}stc_bt_m23_gate_config_t;

/**
 ******************************************************************************
 ** \brief CHA/CHB (23)
 *****************************************************************************/
typedef struct stc_bt_m23_compare_config
{
    en_bt_m23_crch0_csa_csb_t  enCh0ACmpCap;     ///< CH0A/
    en_bt_m23_fltr_ocm_t       enCH0ACmpCtrl;    ///< CH0A
    en_bt_port_polarity_t      enCH0APolarity;   ///< CH0A
    boolean_t                  bCh0ACmpBufEn;    ///< A /
    en_bt_m23_cisa_cisb_t      enCh0ACmpIntSel;  ///< CHA
    
    en_bt_m23_crch0_csa_csb_t  enCh0BCmpCap;     ///< CH0B/
    en_bt_m23_fltr_ocm_t       enCH0BCmpCtrl;    ///< CH0B
    en_bt_port_polarity_t      enCH0BPolarity;   ///< CH0B
    boolean_t                  bCH0BCmpBufEn;    ///< B /
    en_bt_m23_cisa_cisb_t      enCH0BCmpIntSel;  ///< CHB0
}stc_bt_m23_compare_config_t;

/**
 ******************************************************************************
 ** \brief CHA/CHB (23)
 *****************************************************************************/
typedef struct stc_bt_m23_input_config
{
    en_bt_m23_crch0_csa_csb_t  enCh0ACmpCap;     ///< CH0A/
    en_bt_m23_crch0_cfx_crx_t  enCH0ACapSel;     ///< CH0A
    en_bt_flt_t                enCH0AInFlt;      ///< CH0A
    en_bt_port_polarity_t      enCH0APolarity;   ///< CH0A
    
    en_bt_m23_crch0_csa_csb_t  enCh0BCmpCap;     ///< CH0B/
    en_bt_m23_crch0_cfx_crx_t  enCH0BCapSel;     ///< HC0B
    en_bt_flt_t                enCH0BInFlt;      ///< CH0B
    en_bt_port_polarity_t      enCH0BPolarity;   ///< CH0B
    
}stc_bt_m23_input_config_t;   

/**
 ******************************************************************************
 ** \brief ETR(23)
 *****************************************************************************/
typedef struct stc_bt_m23_etr_input_config
{
    en_bt_port_polarity_t     enETRPolarity;  ///< ETR
    en_bt_flt_t               enETRFlt;       ///< ETR
}stc_bt_m23_etr_input_config_t;

/**
 ******************************************************************************
 ** \brief BK(23)
 *****************************************************************************/
typedef struct stc_bt_m23_bk_input_config
{
    boolean_t                 bEnBrake;         ///< 
    boolean_t                 bEnVC0Brake;      ///< VC0
    boolean_t                 bEnVC1Brake;      ///< VC1
    boolean_t                 bEnSafetyBk;      ///< safety
    boolean_t                 bEnBKSync;        ///< TIM0/TIM1/TIM2
    en_bt_m23_crch0_bks_t     enBkCH0AStat;     ///< CHA
    en_bt_m23_crch0_bks_t     enBkCH0BStat;     ///< CHB
    en_bt_port_polarity_t     enBrakePolarity;  ///< BK
    en_bt_flt_t               enBrakeFlt;       ///< BK
}stc_bt_m23_bk_input_config_t;

/**
 ******************************************************************************
** \brief (23)
 *****************************************************************************/
typedef struct stc_bt_m23_dt_config
{
    boolean_t       bEnDeadTime;      ///< CHA
    uint8_t         u8DeadTimeValue;  ///< CHA
}stc_bt_m23_dt_config_t;

/**
 ******************************************************************************
 ** \brief ADC(23)
 *****************************************************************************/
typedef struct stc_bt_m23_adc_trig_config
{
    boolean_t     bEnTrigADC;          ///< ADC
    boolean_t     bEnUevTrigADC;       ///< ADC
    boolean_t     bEnCH0ACmpTrigADC;   ///< CH0AADC
    boolean_t     bEnCH0BCmpTrigADC;   ///< CH0BADC
}stc_bt_m23_adc_trig_config_t;

/**
 ******************************************************************************
 ** \brief  DMA (23)
 *****************************************************************************/
typedef struct stc_bt_m23_trig_dma_config
{
    boolean_t              bUevTrigDMA;      ///<  DMA
    boolean_t              bTITrigDMA;       ///< Trig DMA
    boolean_t              bCmpATrigDMA;     ///< ADMA
    boolean_t              bCmpBTrigDMA;     ///< BDMA
    en_bt_m23_mscr_ccds_t  enCmpUevTrigDMA;  ///< DMA
}stc_bt_m23_trig_dma_config_t;

/**
 ******************************************************************************
 ** \brief   (23)
 *****************************************************************************/
typedef struct stc_bt_m23_master_slave_config
{
    en_bt_m23_mscr_msm_t      enMasterSlaveSel;  ///< 
    en_bt_m23_mscr_mms_t      enMasterSrc;       ///< 
    en_bt_m23_mscr_sms_t      enSlaveModeSel;    ///< 
    en_bt_mscr_ts_t           enTsSel;           ///< 
}stc_bt_m23_master_slave_config_t;

/**
 ******************************************************************************
 ** \brief  OCREF (23)
 *****************************************************************************/
typedef struct stc_bt_m23_OCREF_Clr_config
{
    en_bt_m23ce_occs_t       enOCRefClrSrcSel;  ///< OCREF
    boolean_t                bVCClrEn;          ///< VCOCREF_Clr
}stc_bt_m23_OCREF_Clr_config_t;

/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/
//

//
boolean_t Bt_GetIntFlag(en_bt_unit_t enUnit, en_bt_irq_type_t enBtIrq);
//
en_result_t Bt_ClearIntFlag(en_bt_unit_t enUnit, en_bt_irq_type_t enBtIrq);
//
en_result_t Bt_ClearAllIntFlag(en_bt_unit_t enUnit);
//0
en_result_t Bt_Mode0_EnableIrq(en_bt_unit_t enUnit);
//1
en_result_t Bt_Mode1_EnableIrq (en_bt_unit_t enUnit, en_bt_irq_type_t enBtIrq);
//2
en_result_t Bt_Mode23_EnableIrq (en_bt_unit_t enUnit, en_bt_irq_type_t enBtIrq);
//0
en_result_t Bt_Mode0_DisableIrq(en_bt_unit_t enUnit);
//1
en_result_t Bt_Mode1_DisableIrq (en_bt_unit_t enUnit, en_bt_irq_type_t enBtIrq);
//2
en_result_t Bt_Mode23_DisableIrq (en_bt_unit_t enUnit, en_bt_irq_type_t enBtIrq);


//0

//timer
en_result_t Bt_Mode0_Init(en_bt_unit_t enUnit, stc_bt_mode0_config_t* pstcConfig);
//timer /
en_result_t Bt_M0_Run(en_bt_unit_t enUnit);
en_result_t Bt_M0_Stop(en_bt_unit_t enUnit);
//
en_result_t Bt_M0_ARRSet(en_bt_unit_t enUnit, uint16_t u16Data);
//16/
en_result_t Bt_M0_Cnt16Set(en_bt_unit_t enUnit, uint16_t u16Data);
uint16_t Bt_M0_Cnt16Get(en_bt_unit_t enUnit);
//32/
en_result_t Bt_M0_Cnt32Set(en_bt_unit_t enUnit, uint32_t u32Data);
uint32_t Bt_M0_Cnt32Get(en_bt_unit_t enUnit);
///
en_result_t Bt_M0_EnTOG_Output(en_bt_unit_t enUnit, boolean_t bEnOutput);


//1

//timer
en_result_t Bt_Mode1_Init(en_bt_unit_t enUnit, stc_bt_mode1_config_t* pstcConfig);
//PWC 
en_result_t Bt_M1_Input_Config(en_bt_unit_t enUnit, stc_bt_pwc_input_config_t* pstcConfig);
//PWC
en_result_t Bt_M1_PWC_Edge_Sel(en_bt_unit_t enUnit,en_bt_m1cr_Edge_t enEdgeSel);
//timer /
en_result_t Bt_M1_Run(en_bt_unit_t enUnit);
en_result_t Bt_M1_Stop(en_bt_unit_t enUnit);
//16/
en_result_t Bt_M1_Cnt16Set(en_bt_unit_t enUnit, uint16_t u16Data);
uint16_t Bt_M1_Cnt16Get(en_bt_unit_t enUnit);
//
uint16_t Bt_M1_PWC_CapValueGet(en_bt_unit_t enUnit);


//23

//timer
en_result_t Bt_Mode23_Init(en_bt_unit_t enUnit, stc_bt_mode23_config_t* pstcConfig);
//timer /
en_result_t Bt_M23_Run(en_bt_unit_t enUnit);
en_result_t Bt_M23_Stop(en_bt_unit_t enUnit);
//PWM
en_result_t Bt_M23_EnPWM_Output(en_bt_unit_t enUnit, boolean_t bEnOutput, boolean_t bEnAutoOutput);
//
en_result_t Bt_M23_ARRSet(en_bt_unit_t enUnit, uint16_t u16Data, boolean_t bArrBufEn);
//16/
en_result_t Bt_M23_Cnt16Set(en_bt_unit_t enUnit, uint16_t u16Data);
uint16_t Bt_M23_Cnt16Get(en_bt_unit_t enUnit);
//CCR0A/CCR0B/
en_result_t Bt_M23_CCR_Set(en_bt_unit_t enUnit, en_bt_m23_ccrx_t enCCRSel, uint16_t u16Data);
uint16_t Bt_M23_CCR_Get(en_bt_unit_t enUnit, en_bt_m23_ccrx_t enCCRSel);
//PWMGATE
en_result_t Bt_M23_GateFuncSel(en_bt_unit_t enUnit,stc_bt_m23_gate_config_t* pstcConfig);
//
en_result_t Bt_M23_MasterSlave_Set(en_bt_unit_t enUnit, stc_bt_m23_master_slave_config_t* pstcConfig);
//CH0A/CH0B
en_result_t Bt_M23_PortOutput_Config(en_bt_unit_t enUnit, stc_bt_m23_compare_config_t* pstcConfig);
//CH0A/CH0B
en_result_t Bt_M23_PortInput_Config(en_bt_unit_t enUnit, stc_bt_m23_input_config_t* pstcConfig);
//ERT
en_result_t Bt_M23_ETRInput_Config(en_bt_unit_t enUnit, stc_bt_m23_etr_input_config_t* pstcConfig);
//BK
en_result_t Bt_M23_BrakeInput_Config(en_bt_unit_t enUnit, stc_bt_m23_bk_input_config_t* pstcConfig);
//ADC
en_result_t Bt_M23_TrigADC_Config(en_bt_unit_t enUnit, stc_bt_m23_adc_trig_config_t* pstcConfig);
//
en_result_t Bt_M23_DT_Config(en_bt_unit_t enUnit, stc_bt_m23_dt_config_t* pstcConfig);
//
en_result_t Bt_M23_SetValidPeriod(en_bt_unit_t enUnit, uint8_t u8ValidPeriod);
//OCREF
en_result_t Bt_M23_OCRefClr(en_bt_unit_t enUnit, stc_bt_m23_OCREF_Clr_config_t* pstcConfig);
//DMA
en_result_t Bt_M23_EnDMA(en_bt_unit_t enUnit, stc_bt_m23_trig_dma_config_t* pstcConfig);
//A
en_result_t Bt_M23_EnSwTrigCapCmpA(en_bt_unit_t enUnit);
//B
en_result_t Bt_M23_EnSwTrigCapCmpB(en_bt_unit_t enUnit);
//
en_result_t Bt_M23_EnSwUev(en_bt_unit_t enUnit);
//
en_result_t Bt_M23_EnSwTrig(en_bt_unit_t enUnit);
//
en_result_t Bt_M23_EnSwBk(en_bt_unit_t enUnit);


//@} // BtGroup

#ifdef __cplusplus
#endif


#endif /* __BT_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


