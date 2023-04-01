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
 ** @link BT Timer3 Group Some description @endlink
 **
 ** History:
 **   - 2018-04-29   Husj     First Version
 **
 *****************************************************************************/

#ifndef __TIMER0_H__
#define __TIMER0_H__

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
 ** \defgroup Tim0Group Base Timer (BT)
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
 ** \brief Timer3 
 *****************************************************************************/
typedef enum en_tim0_channel
{
    Tim0CH0  = 0u,        ///< Timer30
    Tim0CH1  = 1u,        ///< Timer31
    Tim0CH2  = 2u,        ///< Timer32
}en_tim0_channel_t;

/**
 ******************************************************************************
 ** \brief  (MODE)(0/1/23)
 *****************************************************************************/
typedef enum en_tim0_work_mode
{
    Tim0WorkMode0  = 0u,         ///< 
    Tim0WorkMode1  = 1u,         ///< PWC
    Tim0WorkMode2  = 2u,         ///< 
    Tim0WorkMode3  = 3u,         ///< 
}en_tim0_work_mode_t;

/**
 ******************************************************************************
 ** \brief  (GATE_P)(0)
 *****************************************************************************/
typedef enum en_tim0_m0cr_gatep
{
    Tim0GatePositive = 0u,            ///< 
    Tim0GateOpposite = 1u,            ///< 
}en_tim0_m0cr_gatep_t;

/**
 ******************************************************************************
 ** \brief TIM3  (PRS)(0/1/23)
 *****************************************************************************/
typedef enum en_tim0_cr_timclkdiv
{
    Tim0PCLKDiv1   = 0u,           ///< Div 1
    Tim0PCLKDiv2   = 1u,           ///< Div 2
    Tim0PCLKDiv4   = 2u,           ///< Div 4
    Tim0PCLKDiv8   = 3u,           ///< Div 8
    Tim0PCLKDiv16  = 4u,           ///< Div 16
    Tim0PCLKDiv32  = 5u,           ///< Div 32
    Tim0PCLKDiv64  = 6u,           ///< Div 64
    Tim0PCLKDiv256 = 7u,           ///< Div 256
}en_tim0_cr_timclkdiv_t;

/**
 ******************************************************************************
 ** \brief / (CT)(0/1/23)
 *****************************************************************************/
typedef enum en_tim0_cr_ct
{
    Tim0Timer   = 0u,            ///< PCLK
    Tim0Counter = 1u,            ///< ETR
}en_tim0_cr_ct_t;


/**
 ******************************************************************************
 ** \brief  (MD)(0)
 *****************************************************************************/
typedef enum en_tim0_m0cr_md
{
    Tim032bitFreeMode  = 0u,         ///< 32/
    Tim016bitArrMode  = 1u,         ///< 16/
}en_tim0_m0cr_md_t;

/**
 ******************************************************************************
** \brief TIM3(0/1/23)
 *****************************************************************************/
typedef enum en_tim0_irq_type
{
    Tim0UevIrq   = 0u,         ///< /
    Tim0CA0Irq   = 2u,         ///< CH0A/(1/23)
    Tim0CA1Irq   = 3u,         ///< CH1A/(23)
    Tim0CA2Irq   = 4u,         ///< CH2A/(23)
    Tim0CB0Irq   = 5u,         ///< CH0B/(23)
    Tim0CB1Irq   = 6u,         ///< CH1B/(23)
    Tim0CB2Irq   = 7u,         ///< CH2B/(23)
    Tim0CA0E     = 8u,         ///< CH0A(23)()
    Tim0CA1E     = 9u,         ///< CH1A(23)()
    Tim0CA2E     = 10u,        ///< CH2A(23)()
    Tim0CB0E     = 11u,        ///< CH0B(23)()
    Tim0CB1E     = 12u,        ///< CH1B(23)()
    Tim0CB2E     = 13u,        ///< CH2B(23)()
    Tim0BkIrq    = 14u,        ///< (23
    Tim0TrigIrq  = 15u,        ///< (23   
}en_tim0_irq_type_t;

/**
 ******************************************************************************
 ** \brief  (Edg1stEdg2nd)(1)
 *****************************************************************************/
typedef enum en_tim0_m1cr_Edge
{
    Tim0PwcRiseToRise  = 0u,            ///< ()
    Tim0PwcFallToRise  = 1u,            ///< ()
    Tim0PwcRiseToFall  = 2u,            ///< ()
    Tim0PwcFallToFall  = 3u,            ///< ()
}en_tim0_m1cr_Edge_t;

/**
 ******************************************************************************
 ** \brief PWC (Oneshot)(1)
 *****************************************************************************/
typedef enum en_tim0_m1cr_oneshot
{
    Tim0PwcCycleDetect    = 0u,         ///< PWC
    Tim0PwcOneShotDetect  = 1u,         ///< PWC
}en_tim0_m1cr_oneshot_t;

/**
 ******************************************************************************
 ** \brief PWC IA0 (IA0S)(1)
 *****************************************************************************/
typedef enum en_tim0_m1_mscr_ia0s
{
    Tim0IA0Input    = 0u,         ///< IAO
    Tim0XORInput    = 1u,         ///< IA0 ETR GATE XOR(TIM0/1/2)/IA0 IA1 IA2 XOR(TIM3)
}en_tim0_m1_mscr_ia0s_t;

/**
 ******************************************************************************
 ** \brief PWC IB0 (IA0S)(1)
 *****************************************************************************/
typedef enum en_tim0_m1_mscr_ib0s
{
    Tim0IB0Input    = 0u,         ///< IBO
    Tim0TsInput     = 1u,         ///< TS
}en_tim0_m1_mscr_ib0s_t;

/**
 ******************************************************************************
 ** \brief   (CCPA0/CCPB0/ETP/BKP)(1/23)
 *****************************************************************************/
typedef enum en_tim0_port_polarity
{
    Tim0PortPositive      = 0u,         ///< 
    Tim0PortOpposite      = 1u,         ///< 
}en_tim0_port_polarity_t;

/**
 ******************************************************************************
 ** \brief  (FLTET/FLTA0/FLAB0)(1/23)
 *****************************************************************************/
typedef enum en_tim0_flt
{
    Tim0FltNone          = 0u,         ///< 
    Tim0FltPCLKCnt3      = 4u,         ///< PCLK 3
    Tim0FltPCLKDiv4Cnt3  = 5u,         ///< PCLK/4 3
    Tim0FltPCLKDiv16Cnt3 = 6u,         ///< PCLK/16 3
    Tim0FltPCLKDiv64Cnt3 = 7u,         ///< PCLK/64 3
}en_tim0_flt_t;

/**
 ******************************************************************************
 ** \brief   (OCMA/OCMB)(23)
 *****************************************************************************/
typedef enum en_tim0_m23_fltr_ocm
{
    Tim0ForceLow      = 0u,         ///< 0
    Tim0ForceHigh     = 1u,         ///< 1
    Tim0CMPForceLow   = 2u,         ///< 0
    Tim0CMPForceHigh  = 3u,         ///< 1
    Tim0CMPInverse    = 4u,         ///< 
    Tim0CMPOnePrdHigh = 5u,         ///< 
    Tim0PWMMode1      = 6u,         ///< PWM mode 1
    Tim0PWMMode2      = 7u,         ///< PWM mode 2
}en_tim0_m23_fltr_ocm_t;

/**
 ******************************************************************************
 ** \brief TS (TS)(1/23)
 *****************************************************************************/
typedef enum en_tim0_mscr_ts
{
    Tim0Ts0ETR        = 0u,         ///< ETR
    Tim0Ts1TIM0TRGO   = 1u,         ///< Timer0TRGO
    Tim0Ts2TIM1TRGO   = 2u,         ///< Timer1TRGO
    Tim0Ts3TIM2TRGO   = 3u,         ///< Timer2TRGO
    Tim0Ts4TIM3TRGO   = 4u,         ///< Timer3TRGO
    //Tim0Ts5IA0ED    = 5u,         ///< 
    Tim0Ts6IAFP       = 6u,         ///< CH0A 
    Tim0Ts7IBFP       = 7u,         ///< CH0B 
}en_tim0_mscr_ts_t;

/**
 ******************************************************************************
 ** \brief PWM (COMP)(23)
 *****************************************************************************/
typedef enum en_tim0_m23cr_comp
{
    Tim0IndependentPWM      = 0u,         ///< PWM
    Tim0ComplementaryPWM    = 1u,         ///< PWM
}en_tim0_m23cr_comp_t;

/**
 ******************************************************************************
 ** \brief  (DIR)(23)
 *****************************************************************************/
typedef enum en_tim0_m23cr_dir
{
    Tim0CntUp      = 0u,         ///< 
    Tim0CntDown    = 1u,         ///< 
}en_tim0_m23cr_dir_t;

/**
 ******************************************************************************
 ** \brief  (PWM2S)(23)
 *****************************************************************************/
typedef enum en_tim0_m23cr_pwm2s
{
    Tim0DoublePointCmp      = 0u,         ///< CCRA,CCRBOCREFA
    Tim0SinglePointCmp      = 1u,         ///< CCRAOCREFA
}en_tim0_m23cr_pwm2s_t;

/**
 ******************************************************************************
 ** \brief GATEPWM  (CSG)(23)
 *****************************************************************************/
typedef enum en_tim0_m23cr_csg
{
     Tim0PWMCompGateCmpOut    = 0u,         ///< PWMGate
     Tim0PWMCompGateCapIn     = 1u,         ///< PWMGate
}en_tim0_m23cr_csg_t;


/**
 ******************************************************************************
 ** \brief   (CCR0A,CCR0B)(23)
 *****************************************************************************/
typedef enum en_tim0_m23_ccrx
{
     Tim0CCR0A    = 0u,         ///< CCR0A
     Tim0CCR0B    = 1u,         ///< CCR0B
     Tim0CCR1A    = 2u,         ///< CCR1A
     Tim0CCR1B    = 3u,         ///< CCR1B
     Tim0CCR2A    = 4u,         ///< CCR2A
     Tim0CCR2B    = 5u,         ///< CCR2B
}en_tim0_m23_ccrx_t;

/**
 ******************************************************************************
 ** \brief  OCREF  (OCCS)(23)
 *****************************************************************************/
typedef enum en_tim0_m23ce_occs
{
     Tim0OC_Ref_Clr  = 0u,         ///< VCOC_Ref_Clr
     Tim0ETRf        = 1u,         ///< ETRf
}en_tim0_m23ce_occs_t;

/**
 ******************************************************************************
 ** \brief    (CIS/CISB)(23)
 *****************************************************************************/
typedef enum en_tim0_m23_cisa_cisb
{
     Tim0CmpIntNone        = 0u,         ///< 
     Tim0CmpIntRise        = 1u,         ///< 
     Tim0CmpIntFall        = 2u,         ///< 
     Tim0CmpIntRiseFall    = 3u,         ///< 
}en_tim0_m23_cisa_cisb_t;

/**
 ******************************************************************************
 ** \brief TIM3 - CHx(BKSA/BKSB)(23)
 **
 ** \note
 ******************************************************************************/
typedef enum en_tim0_m23_crchx_bks
{
    Tim0CHxBksHiZ         = 0u,         ///< CHx
    Tim0CHxBksNorm        = 1u,         ///< CHx
    Tim0CHxBksLow         = 2u,         ///< CHx
    Tim0CHxBksHigh        = 3u,         ///< CHx
}en_tim0_m23_crchx_bks_t;

/**
 ******************************************************************************
** \brief TIM3 - CHx(CRx/CFx)(23)
 **
 ** \note
 ******************************************************************************/
typedef enum en_tim0_m23_crch0_cfx_crx
{
    Tim0CHxCapNone        = 0u,         ///< CHx
    Tim0CHxCapRise        = 1u,         ///< CHx
    Tim0CHxCapFall        = 2u,         ///< CHx
    Tim0CHxCapFallRise    = 3u,         ///< CHx
}en_tim0_m23_crch0_cfx_crx_t;

/**
 ******************************************************************************
** \brief TIM3 - CHx(CSA/CSB)(23)
 **
 ** \note
 ******************************************************************************/
typedef enum en_tim0_m23_crch0_csa_csb
{
    Tim0CHxCmpMode        = 0u,         ///< CHx
    Tim0CHxCapMode        = 1u,         ///< CHx
}en_tim0_m23_crch0_csa_csb_t;

/**
 ******************************************************************************
 ** \brief   DMA  (CCDS)(23)
 *****************************************************************************/
typedef enum en_tim0_m23_mscr_ccds
{
     Tim0CmpTrigDMA  = 0u,         ///< DMA
     Tim0UEVTrigDMA  = 1u,         ///< DMA
}en_tim0_m23_mscr_ccds_t;

/**
 ******************************************************************************
 ** \brief    (MSM)(23)
 *****************************************************************************/
typedef enum en_tim0_m23_mscr_msm
{
     Tim0SlaveMode    = 0u,         ///< 
     Tim0MasterMode   = 1u,         ///< 
}en_tim0_m23_mscr_msm_t;

/**
 ******************************************************************************
 ** \brief    (MMS)(23)
 *****************************************************************************/
typedef enum en_tim0_m23_mscr_mms
{
     Tim0MasterUG         = 0u,         ///< UG()
     Tim0MasterCTEN       = 1u,         ///< CTEN
     Tim0MasterUEV        = 2u,         ///< UEV
     Tim0MasterCMPSO      = 3u,         ///< 
     Tim0MasterOCA0Ref    = 4u,         ///< OCA0_Ref
     Tim0MasterOCB0Ref    = 5u,         ///< OCB0_Ref
     //Tim0MasterOCB0Ref  = 6u,
     //Tim0MasterOCB0Ref  = 7u,
}en_tim0_m23_mscr_mms_t;

/**
 ******************************************************************************
 ** \brief    (SMS)(23)
 *****************************************************************************/
typedef enum en_tim0_m23_mscr_sms
{
     Tim0SlaveIClk        = 0u,         ///< 
     Tim0SlaveResetTIM    = 1u,         ///< 
     Tim0SlaveTrigMode    = 2u,         ///< 
     Tim0SlaveEClk        = 3u,         ///< 
     Tim0SlaveCodeCnt1    = 4u,         ///< 1
     Tim0SlaveCodeCnt2    = 5u,         ///< 2
     Tim0SlaveCodeCnt3    = 6u,         ///< 3
     Tim0SlaveGateCtrl    = 7u,         ///< 
}en_tim0_m23_mscr_sms_t;

/**
 ******************************************************************************
 ** \brief  (CTEN)
 *****************************************************************************/
typedef enum en_tim0_start
{
    Tim0CTENDisable = 0u,            ///< 
    Tim0CTENEnable  = 1u,            ///< 
}en_tim0_start_t;

/**
 ******************************************************************************
 ** \brief TIM3 mode0 (0)
 *****************************************************************************/
typedef struct stc_tim0_mode0_config
{
    en_tim0_work_mode_t     enWorkMode;       ///< 
    en_tim0_m0cr_gatep_t    enGateP;          ///< 
    boolean_t               bEnGate;          ///< 
    en_tim0_cr_timclkdiv_t  enPRS;            ///< 
    boolean_t               bEnTog;           ///< 
    en_tim0_cr_ct_t         enCT;             ///< /
    en_tim0_m0cr_md_t       enCntMode;        ///< 
    
    func_ptr_t              pfnTim0Cb;        ///< Timer3[void function(void)]
}stc_tim0_mode0_config_t;

/**
 ******************************************************************************
 ** \brief TIM3 mode1 (1)
 *****************************************************************************/
typedef struct stc_tim0_mode1_config
{
    en_tim0_work_mode_t     enWorkMode;       ///< 
    en_tim0_cr_timclkdiv_t  enPRS;            ///< 
    en_tim0_cr_ct_t         enCT;             ///< /
    en_tim0_m1cr_oneshot_t  enOneShot;        ///< /
    
    func_ptr_t              pfnTim0Cb;        ///< Timer3[void function(void)]

}stc_tim0_mode1_config_t;

/**
 ******************************************************************************
 ** \brief PWC(1)
 *****************************************************************************/
typedef struct stc_tim0_pwc_input_config
{
    en_tim0_mscr_ts_t          enTsSel;       ///< 
    en_tim0_m1_mscr_ia0s_t     enIA0Sel;      ///< CHA0
    en_tim0_m1_mscr_ib0s_t     enIB0Sel;      ///< CHB0
    en_tim0_port_polarity_t    enETRPhase;    ///< ETR
    en_tim0_flt_t              enFltETR;      ///< ETR
    en_tim0_flt_t              enFltIA0;      ///< CHA0
    en_tim0_flt_t              enFltIB0;      ///< CHB0
}stc_tim0_pwc_input_config_t;

/**
 ******************************************************************************
 ** \brief TIM3 mode23 (23)
 *****************************************************************************/
typedef struct stc_tim0_mode23_config
{
    en_tim0_work_mode_t         enWorkMode;       ///< 
    en_tim0_m23cr_dir_t         enCntDir;         ///< 
    en_tim0_cr_timclkdiv_t      enPRS;            ///< 
    en_tim0_cr_ct_t             enCT;             ///< /
    en_tim0_m23cr_comp_t        enPWMTypeSel;     ///< PWM/
    en_tim0_m23cr_pwm2s_t       enPWM2sSel;       ///< OCREFA
    boolean_t                   bOneShot;         ///< /
    boolean_t                   bURSSel;          ///< 
    
    func_ptr_t                  pfnTim0Cb;        ///< Timer3[void function(void)]
}stc_tim0_mode23_config_t;

/**
 ******************************************************************************
 ** \brief GATEPWM (23)
 *****************************************************************************/
typedef struct stc_tim0_m23_gate_config
{
    en_tim0_m23cr_csg_t        enGateFuncSel;      ///< Gate
    boolean_t                  bGateRiseCap;       ///< GATE
    boolean_t                  bGateFallCap;       ///< GATE
}stc_tim0_m23_gate_config_t;

/**
 ******************************************************************************
 ** \brief CHA/CHB (23)
 *****************************************************************************/
typedef struct stc_tim0_m23_compare_config
{
    en_tim0_m23_crch0_csa_csb_t  enCHxACmpCap;     ///< CH0A/
    en_tim0_m23_fltr_ocm_t       enCHxACmpCtrl;    ///< CH0A
    en_tim0_port_polarity_t      enCHxAPolarity;   ///< CH0A
    boolean_t                    bCHxACmpBufEn;    ///< A /
    en_tim0_m23_cisa_cisb_t      enCHxACmpIntSel;  ///< CHA
    
    en_tim0_m23_crch0_csa_csb_t  enCHxBCmpCap;     ///< CH0B/
    en_tim0_m23_fltr_ocm_t       enCHxBCmpCtrl;    ///< CH0B
    en_tim0_port_polarity_t      enCHxBPolarity;   ///< CH0B
    boolean_t                    bCHxBCmpBufEn;    ///< B /
    en_tim0_m23_cisa_cisb_t      enCHxBCmpIntSel;  ///< CHB0
}stc_tim0_m23_compare_config_t;

/**
 ******************************************************************************
 ** \brief CHA/CHB (23)
 *****************************************************************************/
typedef struct stc_tim0_m23_input_config
{
    en_tim0_m23_crch0_csa_csb_t  enCHxACmpCap;     ///< CH0A/
    en_tim0_m23_crch0_cfx_crx_t  enCHxACapSel;     ///< CH0A
    en_tim0_flt_t                enCHxAInFlt;      ///< CH0A
    en_tim0_port_polarity_t      enCHxAPolarity;   ///< CH0A
    
    en_tim0_m23_crch0_csa_csb_t  enCHxBCmpCap;     ///< CH0A/
    en_tim0_m23_crch0_cfx_crx_t  enCHxBCapSel;     ///< CH0B
    en_tim0_flt_t                enCHxBInFlt;      ///< CH0B
    en_tim0_port_polarity_t      enCHxBPolarity;   ///< CH0B
    
}stc_tim0_m23_input_config_t;   

/**
 ******************************************************************************
 ** \brief ETR(23)
 *****************************************************************************/
typedef struct stc_tim0_m23_etr_input_config
{
    en_tim0_port_polarity_t     enETRPolarity;  ///< ETR
    en_tim0_flt_t               enETRFlt;       ///< ETR
}stc_tim0_m23_etr_input_config_t;

/**
 ******************************************************************************
 ** \brief BK(23)
 *****************************************************************************/
typedef struct stc_tim0_m23_bk_input_config
{
    boolean_t                   bEnBrake;         ///< 
    boolean_t                   bEnVC0Brake;      ///< VC0
    boolean_t                   bEnVC1Brake;      ///< VC1
    boolean_t                   bEnSafetyBk;      ///< safety
    boolean_t                   bEnBKSync;        ///< TIM0/TIM1/TIM2
    en_tim0_m23_crchx_bks_t     enBkCH0AStat;     ///< CHA
    en_tim0_m23_crchx_bks_t     enBkCH0BStat;     ///< CHB
    en_tim0_m23_crchx_bks_t     enBkCH1AStat;     ///< CHA
    en_tim0_m23_crchx_bks_t     enBkCH1BStat;     ///< CHB
    en_tim0_m23_crchx_bks_t     enBkCH2AStat;     ///< CHA
    en_tim0_m23_crchx_bks_t     enBkCH2BStat;     ///< CHB
    en_tim0_port_polarity_t     enBrakePolarity;  ///< BK
    en_tim0_flt_t               enBrakeFlt;       ///< BK
}stc_tim0_m23_bk_input_config_t;

/**
 ******************************************************************************
** \brief (23)
 *****************************************************************************/
typedef struct stc_tim0_m23_dt_config
{
    boolean_t       bEnDeadTime;      ///< CHA
    uint8_t         u8DeadTimeValue;  ///< CHA
}stc_tim0_m23_dt_config_t;

/**
 ******************************************************************************
 ** \brief ADC(23)
 *****************************************************************************/
typedef struct stc_tim0_m23_adc_trig_config
{
    boolean_t     bEnTrigADC;          ///< ADC
    boolean_t     bEnUevTrigADC;       ///< ADC
    boolean_t     bEnCH0ACmpTrigADC;   ///< CH0AADC
    boolean_t     bEnCH0BCmpTrigADC;   ///< CH0BADC
    boolean_t     bEnCH1ACmpTrigADC;   ///< CH0AADC
    boolean_t     bEnCH1BCmpTrigADC;   ///< CH0BADC
    boolean_t     bEnCH2ACmpTrigADC;   ///< CH0AADC
    boolean_t     bEnCH2BCmpTrigADC;   ///< CH0BADC
}stc_tim0_m23_adc_trig_config_t;

/**
 ******************************************************************************
 ** \brief  DMA (23)
 *****************************************************************************/
typedef struct stc_tim0_m23_trig_dma_config
{
    boolean_t                bUevTrigDMA;      ///<  DMA
    boolean_t                bTITrigDMA;       ///< Trig DMA
    boolean_t                bCmpA0TrigDMA;    ///< CH0ADMA
    boolean_t                bCmpB0TrigDMA;    ///< CH0BDMA
    boolean_t                bCmpA1TrigDMA;    ///< CH1ADMA
    boolean_t                bCmpB1TrigDMA;    ///< CH1BDMA
    boolean_t                bCmpA2TrigDMA;    ///< CH2ADMA
    boolean_t                bCmpB2TrigDMA;    ///< CH2BDMA
    en_tim0_m23_mscr_ccds_t  enCmpUevTrigDMA;  ///< DMA
}stc_tim0_m23_trig_dma_config_t;

/**
 ******************************************************************************
 ** \brief   (23)
 *****************************************************************************/
typedef struct stc_tim0_m23_master_slave_config
{
    en_tim0_m23_mscr_msm_t      enMasterSlaveSel;  ///< 
    en_tim0_m23_mscr_mms_t      enMasterSrc;       ///< 
    en_tim0_m23_mscr_sms_t      enSlaveModeSel;    ///< 
    en_tim0_mscr_ts_t           enTsSel;           ///< 
}stc_tim0_m23_master_slave_config_t;

/**
 ******************************************************************************
 ** \brief  OCREF (23)
 *****************************************************************************/
typedef struct stc_tim0_m23_OCREF_Clr_config
{
    en_tim0_m23ce_occs_t       enOCRefClrSrcSel;  ///< OCREF
    boolean_t                  bVCClrEn;          ///< VCOCREF_Clr
}stc_tim0_m23_OCREF_Clr_config_t;

/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/
//

//
boolean_t Tim0_GetIntFlag(en_tim0_irq_type_t enTim0Irq);
//
en_result_t Tim0_ClearIntFlag(en_tim0_irq_type_t enTim0Irq);
//
en_result_t Tim0_ClearAllIntFlag(void);
//0
en_result_t Tim0_Mode0_EnableIrq(void);
//1
en_result_t Tim0_Mode1_EnableIrq (en_tim0_irq_type_t enTim0Irq);
//2
en_result_t Tim0_Mode23_EnableIrq (en_tim0_irq_type_t enTim0Irq);
//0
en_result_t Tim0_Mode0_DisableIrq(void);
//1
en_result_t Tim0_Mode1_DisableIrq (en_tim0_irq_type_t enTim0Irq);
//2
en_result_t Tim0_Mode23_DisableIrq (en_tim0_irq_type_t enTim0Irq);


//0

//timer
en_result_t Tim0_Mode0_Init(stc_tim0_mode0_config_t* pstcConfig);
//timer /
en_result_t Tim0_M0_Run(void);
en_result_t Tim0_M0_Stop(void);
//
en_result_t Tim0_M0_ARRSet(uint16_t u16Data);
//16/
en_result_t Tim0_M0_Cnt16Set(uint16_t u16Data);
uint16_t Tim0_M0_Cnt16Get(void);
//32/
en_result_t Tim0_M0_Cnt32Set(uint32_t u32Data);
uint32_t Tim0_M0_Cnt32Get(void);
///
en_result_t Tim0_M0_EnTOG_Output(boolean_t bEnOutput);


//1

//timer
en_result_t Tim0_Mode1_Init(stc_tim0_mode1_config_t* pstcConfig);
//PWC 
en_result_t Tim0_M1_Input_Config(stc_tim0_pwc_input_config_t* pstcConfig);
//PWC
en_result_t Tim0_M1_PWC_Edge_Sel(en_tim0_m1cr_Edge_t enEdgeSel);
//timer /
en_result_t Tim0_M1_Run(void);
en_result_t Tim0_M1_Stop(void);
//16/
en_result_t Tim0_M1_Cnt16Set(uint16_t u16Data);
uint16_t Tim0_M1_Cnt16Get(void);
//
uint16_t Tim0_M1_PWC_CapValueGet(void);


//1

//timer
en_result_t Tim0_Mode23_Init(stc_tim0_mode23_config_t* pstcConfig);
//timer /
en_result_t Tim0_M23_Run(void);
en_result_t Tim0_M23_Stop(void);
//PWM
en_result_t Tim0_M23_EnPWM_Output(boolean_t bEnOutput, boolean_t bEnAutoOutput);
//
en_result_t Tim0_M23_ARRSet(uint16_t u16Data, boolean_t bArrBufEn);
//16/
en_result_t Tim0_M23_Cnt16Set(uint16_t u16Data);
uint16_t Tim0_M23_Cnt16Get(void);
//CCR0A/CCR0B/
en_result_t Tim0_M23_CCR_Set(en_tim0_m23_ccrx_t enCCRSel, uint16_t u16Data);
uint16_t Tim0_M23_CCR_Get(en_tim0_m23_ccrx_t enCCRSel);
//PWMGATE
en_result_t Tim0_M23_GateFuncSel(stc_tim0_m23_gate_config_t* pstcConfig);
//
en_result_t Tim0_M23_MasterSlave_Set(stc_tim0_m23_master_slave_config_t* pstcConfig);
//CH0A/CH0B
en_result_t Tim0_M23_PortOutput_Config(en_tim0_channel_t enTim0Chx, stc_tim0_m23_compare_config_t* pstcConfig);
//CH0A/CH0B
en_result_t Tim0_M23_PortInput_Config(en_tim0_channel_t enTim0Chx, stc_tim0_m23_input_config_t* pstcConfig);
//ERT
en_result_t Tim0_M23_ETRInput_Config(stc_tim0_m23_etr_input_config_t* pstcConfig);
//BK
en_result_t Tim0_M23_BrakeInput_Config(stc_tim0_m23_bk_input_config_t* pstcConfig);
//ADC
en_result_t Tim0_M23_TrigADC_Config(stc_tim0_m23_adc_trig_config_t* pstcConfig);
//
en_result_t Tim0_M23_DT_Config(stc_tim0_m23_dt_config_t* pstcConfig);
//
en_result_t Tim0_M23_SetValidPeriod(uint8_t u8ValidPeriod);
//OCREF
en_result_t Tim0_M23_OCRefClr(stc_tim0_m23_OCREF_Clr_config_t* pstcConfig);
//DMA
en_result_t Tim0_M23_EnDMA(stc_tim0_m23_trig_dma_config_t* pstcConfig);
//A
en_result_t Tim0_M23_EnSwTrigCapCmpA(en_tim0_channel_t enTim0Chx);
//B
en_result_t Tim0_M23_EnSwTrigCapCmpB(en_tim0_channel_t enTim0Chx);
//
en_result_t Tim0_M23_EnSwUev(void);
//
en_result_t Tim0_M23_EnSwTrig(void);
//
en_result_t Tim0_M23_EnSwBk(void);


//@} // Tim0Group

#ifdef __cplusplus
#endif


#endif /* __BT_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


