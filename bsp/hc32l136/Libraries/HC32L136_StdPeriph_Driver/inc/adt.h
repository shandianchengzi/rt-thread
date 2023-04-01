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
/** \file adt.h
 **
 ** Headerfile for Advance Timer functions
 ** @link ADT Group Some description @endlink
 **
 **   - 2018-04-18 Husj    First Version
 **
 ******************************************************************************/

#ifndef __ADT_H__
#define __ADT_H__

/******************************************************************************
 * Include files
 ******************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l136.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup AdtGroup Advance Timer (ADT)
  **
 ******************************************************************************/
//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

 /**
 ******************************************************************************
 ** \brief 
 *****************************************************************************/
typedef enum en_adt_unit
{
    AdtTIM4    = 0u,            ///< TIM4
    AdtTIM5    = 1u,            ///< TIM5
    AdtTIM6    = 2u,            ///< TIM6
}en_adt_unit_t;

 /**
 ******************************************************************************
 ** \brief ADT CHx
 *****************************************************************************/
typedef enum en_adt_CHxX_port
{
    AdtCHxA    = 0u,            ///< CHx A
    AdtCHxB    = 1u,            ///< CHx B
}en_adt_CHxX_port_t;

 /**
 ******************************************************************************
 ** \brief ADT TRIG
 *****************************************************************************/
typedef enum en_adt_trig_port
{
    AdtTrigA    = 0u,            ///< TIMx A
    AdtTrigB    = 1u,            ///< TIMx B
    AdtTrigC    = 2u,            ///< TIMx C
    AdtTrigD    = 3u,            ///< TIMx D
}en_adt_trig_port_t;

/**
 ******************************************************************************
 ** \brief ADT - Z
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_gconr_zmsk
{
    AdtZMaskDis   = 0u,      ///< Z
    AdtZMask4Cyl  = 1u,      ///< 4Z
    AdtZMask8Cyl  = 2u,      ///< 8Z
    AdtZMask16Cyl = 3u,      ///< 16Z
}en_adt_gconr_zmsk_t;

/**
 ******************************************************************************
 ** \brief ADT - 
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_cnt_ckdiv
{
    AdtClkPClk0        = 0u,         ///< PCLK0
    AdtClkPClk0Div2    = 1u,         ///< PCLK0/2
    AdtClkPClk0Div4    = 2u,         ///< PCLK0/4
    AdtClkPClk0Div8    = 3u,         ///< PCLK0/8
    AdtClkPClk0Div16   = 4u,         ///< PCLK0/16
    AdtClkPClk0Div64   = 5u,         ///< PCLK0/64
    AdtClkPClk0Div256  = 6u,         ///< PCLK0/256
    AdtClkPClk0Div1024 = 7u,         ///< PCLK0/1024
}en_adt_cnt_ckdiv_t;

/**
 ******************************************************************************
 ** \brief ADT
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_cnt_mode
{
    AdtSawtoothMode  = 0u,          ///< 
    AdtTriangleModeA = 4u,          ///< A
    AdtTriangleModeB = 5u,          ///< B
}en_adt_cnt_mode_t;

/**
 ******************************************************************************
 ** \brief ADT
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_cnt_dir
{
    AdtCntDown = 0u,      ///< 
    AdtCntUp   = 1u,      ///< 
}en_adt_cnt_dir_t;

/**
 ******************************************************************************
 ** \brief ADT
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_compare
{
    AdtCompareA = 0u,            ///< A
    AdtCompareB = 1u,            ///< B
    AdtCompareC = 2u,            ///< C
    AdtCompareD = 3u,            ///< D
}en_adt_compare_t;

/**
 ******************************************************************************
 ** \brief ADT
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_special_compare
{
    AdtSpclCompA = 0u,            ///< A
    AdtSpclCompB = 1u,            ///< B
}en_adt_special_compare_t;

/**
 ******************************************************************************
 ** \brief ADT - TIMx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_pconr_disval
{
    AdtTIMxDisValNorm = 0u,     ///< 0~3CHx
    AdtTIMxDisValHiZ  = 1u,     ///< 0~3CHx
    AdtTIMxDisValLow  = 2u,     ///< 0~3CHx
    AdtTIMxDisValHigh = 3u,     ///< 0~3CHx
}en_adt_pconr_disval_t;

/**
 ******************************************************************************
 ** \brief ADT - CHx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_pconr_dissel
{
    AdtCHxDisSel0 = 0u,        ///< 0
    AdtCHxDisSel1 = 1u,        ///< 1
    AdtCHxDisSel2 = 2u,        ///< 2
    AdtCHxDisSel3 = 3u,        ///< 3
}en_adt_pconr_dissel_t;

/**
 ******************************************************************************
 ** \brief ADT - CHx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_pconr_perc
{
    AdtCHxPeriodLow  = 0u,      ///< CHx
    AdtCHxPeriodHigh = 1u,      ///< CHx
    AdtCHxPeriodKeep = 2u,      ///< CHx
    AdtCHxPeriodInv  = 3u,      ///< CHx
}en_adt_pconr_perc_t;

/**
 ******************************************************************************
 ** \brief ADT - CHx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_pconr_cmpc
{
    AdtCHxCompareLow  = 0u,     ///< GCMxRCHx
    AdtCHxCompareHigh = 1u,     ///< GCMxRCHx
    AdtCHxCompareKeep = 2u,     ///< GCMxRCHx
    AdtCHxCompareInv  = 3u,     ///< GCMxRCHx
}en_adt_pconr_cmpc_t;

/**
 ******************************************************************************
 ** \brief ADT - CHx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_pconr_port_out
{
    AdtCHxPortOutLow  = 0u,  ///< CHx
    AdtCHxPortOutHigh = 1u,  ///< CHx
}en_adt_pconr_port_out_t;

/**
 ******************************************************************************
 ** \brief ADT - CHx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_pconr_capc
{
    AdtCHxCompareOutput = 0u,   ///< CHx
    AdtCHxCompareInput  = 1u,   ///< CHx
}en_adt_pconr_capc_t;

/**
 ******************************************************************************
 ** \brief ADT - CHx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_pconr_stastps
{
    AdtCHxStateSelSS   = 0u,    ///< CHxSTACBSTPCB
    AdtCHxStateSelKeep = 1u,    ///< CHx
}en_adt_pconr_stastps_t;

/**
 ******************************************************************************
 ** \brief ADT - CHx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_dconr_sepa
{
    AdtCHxDtSeperate = 0u,      ///< DTUARDTDAR
    AdtCHxDtEqual    = 1u,      ///< DTDARDTUAR
}en_adt_dconr_sepa_t;

/**
 ******************************************************************************
 ** \brief ADT - TRIx/TIMxIx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_fconr_nofick
{
    AdtFltClkPclk0      = 0u,    ///< PCLK0
    AdtFltClkPclk0Div4  = 1u,    ///< PCLK0/4
    AdtFltClkPclk0Div16 = 2u,    ///< PCLK0/16
    AdtFltClkPclk0Div64 = 3u,    ///< PCLK0/64
}en_adt_fconr_nofick_t;

/**
 ******************************************************************************
 ** \brief ADT - TIMx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_vperr_pcnts
{
    AdtPeriodCnts0 = 0u,         ///< 
    AdtPeriodCnts1 = 1u,         ///< 1
    AdtPeriodCnts2 = 2u,         ///< 2
    AdtPeriodCnts3 = 3u,         ///< 3
    AdtPeriodCnts4 = 4u,         ///< 4
    AdtPeriodCnts5 = 5u,         ///< 5
    AdtPeriodCnts6 = 6u,         ///< 6
    AdtPeriodCnts7 = 7u,         ///< 7
}en_adt_vperr_pcnts_t;

/**
 ******************************************************************************
 ** \brief ADT - 
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_vperr_pcnte
{
    AdtPeriodCnteDisable = 0u,     ///< 
    AdtPeriodCnteMin     = 1u,     ///< 
    AdtPeriodCnteMax     = 2u,     ///< 
    AdtPeriodCnteBoth    = 3u,     ///< 
}en_adt_vperr_pcnte_t;

/**
 ******************************************************************************
 ** \brief ADT - 
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_ttrig_trigxs
{
    AdtTrigxSelPA3  = 0u,    ///< PA3
    AdtTrigxSelPB3  = 1u,    ///< PB3
    AdtTrigxSelPC3  = 2u,    ///< PC3
    AdtTrigxSelPD3  = 3u,    ///< PD3
    AdtTrigxSelPA7  = 4u,    ///< PA7
    AdtTrigxSelPB7  = 5u,    ///< PB7
    AdtTrigxSelPC7  = 6u,    ///< PC7
    AdtTrigxSelPD7  = 7u,    ///< PD7
    AdtTrigxSelPA11 = 8u,    ///< PA11
    AdtTrigxSelPB11 = 9u,    ///< PB11
    AdtTrigxSelPC11 = 10u,   ///< PC11
    AdtTrigxSelPD1  = 11u,   ///< PD1
    AdtTrigxSelPA15 = 12u,   ///< PA15
    AdtTrigxSelPB15 = 13u,   ///< PB15
    AdtTrigxSelPC5  = 14u,   ///< PC5
    AdtTrigxSelPD5  = 15u,   ///< PD5
}en_adt_ttrig_trigxs_t;

/**
 ******************************************************************************
 ** \brief ADT AOS - AOSx
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_itrig_iaosxs
{
    AdtAosxTrigSelTim0Int   = 0u,    ///< TIM0_INT
    AdtAosxTrigSelTim1Int   = 1u,    ///< TIM1_INT
    AdtAosxTrigSelTim2Int   = 2u,    ///< TIM2_INT
    AdtAosxTrigSelLpTimInt  = 3u,    ///< LPTIMER_INT
    AdtAosxTrigSelTim4Int   = 4u,    ///< TIM4_INT
    AdtAosxTrigSelTim5Int   = 5u,    ///< TIM5_INT
    AdtAosxTrigSelTim6Int   = 6u,    ///< TIM6_INT
    AdtAosxTrigSelUart0Int  = 7u,    ///< UART0_INT
    AdtAosxTrigSelUart1Int  = 8u,    ///< UART1_INT
    AdtAosxTrigSelLpUartInt = 9u,    ///< LPUART_INT
    AdtAosxTrigSelVc0Int    = 10u,   ///< VC0_INT
    AdtAosxTrigSelVc1Int    = 11u,   ///< VC1_INT
    AdtAosxTrigSelRtcInt    = 12u,   ///< RTC_INT
    AdtAosxTrigSelPcaInt    = 13u,   ///< PCA_INT
    AdtAosxTrigSelSpiInt    = 14u,   ///< SPI_INT
    AdtAosxTrigSelAdcInt    = 15u,   ///< ADC_INT
}en_adt_itrig_iaosxs_t;

/**
 ******************************************************************************
 ** \brief ADT(///)
 **
 ** \note
 ******************************************************************************/

typedef enum en_adt_hw_trig
{
    AdtHwTrigAos0        = 0u,       ///< AOS0
    AdtHwTrigAos1        = 1u,       ///< AOS1
    AdtHwTrigAos2        = 2u,       ///< AOS2
    AdtHwTrigAos3        = 3u,       ///< AOS3
    AdtHwTrigCHxARise    = 4u,       ///< CHxA
    AdtHwTrigCHxAFall    = 5u,       ///< CHxA
    AdtHwTrigCHxBRise    = 6u,       ///< CHxB
    AdtHwTrigCHxBFall    = 7u,       ///< CHxB
    AdtHwTrigTimTriARise = 8u,       ///< TIMTRIA
    AdtHwTrigTimTriAFall = 9u,       ///< TIMTRIA
    AdtHwTrigTimTriBRise = 10u,      ///< TIMTRIB
    AdtHwTrigTimTriBFall = 11u,      ///< TIMTRIB
    AdtHwTrigTimTriCRise = 12u,      ///< TIMTRIC
    AdtHwTrigTimTriCFall = 13u,      ///< TIMTRIC
    AdtHwTrigTimTriDRise = 14u,      ///< TIMTRID
    AdtHwTrigTimTriDFall = 15u,      ///< TIMTRID
    AdtHwTrigEnd         = 16u,
}en_adt_hw_trig_t;

/**
 ******************************************************************************
 ** \brief ADT(/)
 **
 ** \note
 ******************************************************************************/

typedef enum en_adt_hw_cnt
{
    AdtHwCntCHxALowCHxBRise   = 0u,      ///< CHxACHxB
    AdtHwCntCHxALowCHxBFall   = 1u,      ///< CHxACHxB
    AdtHwCntCHxAHighCHxBRise  = 2u,      ///< CHxACHxB
    AdtHwCntCHxAHighCHxBFall  = 3u,      ///< CHxACHxB
    AdtHwCntCHxBLowCHxARise   = 4u,      ///< CHxBCHxA
    AdtHwCntCHxBLowCHxAFall   = 5u,      ///< CHxBCHxA
    AdtHwCntCHxBHighChxARise  = 6u,      ///< CHxBCHxA
    AdtHwCntCHxBHighCHxAFall  = 7u,      ///< CHxBCHxA
    AdtHwCntTimTriARise       = 8u,      ///< TIMTRIA
    AdtHwCntTimTriAFall       = 9u,      ///< TIMTRIA
    AdtHwCntTimTriBRise       = 10u,     ///< TIMTRIB
    AdtHwCntTimTriBFall       = 11u,     ///< TIMTRIB
    AdtHwCntTimTriCRise       = 12u,     ///< TIMTRIC
    AdtHwCntTimTriCFall       = 13u,     ///< TIMTRIC
    AdtHwCntTimTriDRise       = 14u,     ///< TIMTRID
    AdtHwCntTimTriDFall       = 15u,     ///< TIMTRID
    AdtHwCntAos0              = 16u,     ///< AOS0
    AdtHwCntAos1              = 17u,     ///< AOS1
    AdtHwCntAos2              = 18u,     ///< AOS2
    AdtHwCntAos3              = 19u,     ///< AOS3
    AdtHwCntMax               = 20u,
}en_adt_hw_cnt_t;

/**
 ******************************************************************************
 ** \brief ADT
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_ptbrk_polarity
{
    AdtPtBrkHigh = 0u,     ///< 
    AdtPtBrkLow  = 1u,     ///< 
}en_adt_ptbrk_polarity_t;

/**
 ******************************************************************************
 ** \brief ADT PWM
 **
 ** \note
 ******************************************************************************/
typedef enum en_adt_pwm_dither_type
{
    AdtPwmDitherUnderFlow = 0u,    ///< PWM
    AdtPwmDitherOverFlow  = 1u,    ///< PWM
}en_adt_pwm_dither_type_t;

/**
 ******************************************************************************
 ** \brief ADT
 **
 ** \note
 ******************************************************************************/

typedef enum en_adt_irq_type
{
    AdtCMAIrq  = 0u,     ///< A
    AdtCMBIrq  = 1u,     ///< B
    AdtCMCIrq  = 2u,     ///< C
    AdtCMDIrq  = 3u,     ///< D
    AdtOVFIrq  = 6u,     ///< 
    AdtUDFIrq  = 7u,     ///< 
    AdtDTEIrq  = 8u,     ///< 
    AdtSAMLIrq = 14u,    ///< 
    AdtSAMHIrq = 15u,    ///< 
}en_adt_irq_type_t;

/**
 ******************************************************************************
 ** \brief ADT
 ** \note
 ******************************************************************************/
typedef struct stc_adt_sw_sync
{
    boolean_t               bAdTim4;      ///< Timer 4
    boolean_t               bAdTim5;      ///< Timer 5
    boolean_t               bAdTim6;      ///< Timer 6

}stc_adt_sw_sync_t;

/**
 ******************************************************************************
 ** \brief ADT AOS
 ** \note
 ******************************************************************************/
typedef struct stc_adt_aos_trig_cfg
{
    en_adt_itrig_iaosxs_t   enAos0TrigSrc;      ///< AOS0
    en_adt_itrig_iaosxs_t   enAos1TrigSrc;      ///< AOS1
    en_adt_itrig_iaosxs_t   enAos2TrigSrc;      ///< AOS2
    en_adt_itrig_iaosxs_t   enAos3TrigSrc;      ///< AOS3
}stc_adt_aos_trig_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT 
 ** \note
 ******************************************************************************/
typedef struct stc_adt_irq_trig_cfg
{
    boolean_t   bAdtSpecilMatchBTrigDmaEn;  ///< BDMA
    boolean_t   bAdtSpecilMatchATrigDmaEn;  ///< ADMA
    boolean_t   bAdtUnderFlowTrigDmaEn;     ///< DMA
    boolean_t   bAdtOverFlowTrigDmaEn;      ///< DMA
    boolean_t   bAdtCntMatchDTrigDmaEn;     ///< DDMA
    boolean_t   bAdtCntMatchCTrigDmaEn;     ///< CDMA
    boolean_t   bAdtCntMatchBTrigDmaEn;     ///< BDMA
    boolean_t   bAdtCntMatchATrigDmaEn;     ///< ADMA
    boolean_t   bAdtSpecilMatchBTrigEn;     ///< BADC
    boolean_t   bAdtSpecilMatchATrigEn;     ///< AADC
    boolean_t   bAdtUnderFlowTrigEn;        ///< ADC
    boolean_t   bAdtOverFlowTrigEn;         ///< ADC
    boolean_t   bAdtCntMatchDTrigEn;        ///< DADC
    boolean_t   bAdtCntMatchCTrigEn;        ///< CADC
    boolean_t   bAdtCntMatchBTrigEn;        ///< BADC
    boolean_t   bAdtCntMatchATrigEn;        ///< AADC
}stc_adt_irq_trig_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT Trig
 ** \note
 ******************************************************************************/
typedef struct stc_adt_port_trig_cfg
{
    en_adt_ttrig_trigxs_t   enTrigSrc;      ///< 
    boolean_t               bFltEn;         ///< 
    en_adt_fconr_nofick_t   enFltClk;       ///< 
}stc_adt_port_trig_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT Z
 ** \note
 ******************************************************************************/
typedef struct stc_adt_zmask_cfg
{
    en_adt_gconr_zmsk_t     enZMaskCycle;              ///< Z
    boolean_t               bFltPosCntMaksEn;          ///< ZFALSE(TRUE)
    boolean_t               bFltRevCntMaksEn;          ///< ZFALSE(TRUE)
}stc_adt_zmask_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT TIMxX
 ** \note
 ******************************************************************************/
typedef struct stc_adt_TIMxX_port_cfg
{
    en_adt_pconr_capc_t     enCap;      ///< 
    boolean_t               bOutEn;     ///< 
    en_adt_pconr_perc_t     enPerc;     ///< 
    en_adt_pconr_cmpc_t     enCmpc;     ///< 
    en_adt_pconr_stastps_t  enStaStp;   ///< 
    en_adt_pconr_port_out_t enStaOut;   ///< 
    en_adt_pconr_port_out_t enStpOut;   ///< 
    en_adt_pconr_disval_t   enDisVal;   ///< 
    en_adt_pconr_dissel_t   enDisSel;   ///< 
    boolean_t               bFltEn;     ///< 
    en_adt_fconr_nofick_t   enFltClk;   ///< 
}stc_adt_CHxX_port_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT
 ** \note
 ******************************************************************************/
typedef struct stc_adt_break_port_cfg
{
    boolean_t               bPortEn;    ///< 
    en_adt_ptbrk_polarity_t enPol;      ///< 
}stc_adt_break_port_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT3
 ** \note
 ******************************************************************************/
typedef struct stc_adt_disable_3_cfg
{
    stc_adt_break_port_cfg_t    stcBrkPtCfg[16];    ///< 
    boolean_t                   bFltEn;             ///< 
    en_adt_fconr_nofick_t       enFltClk;           ///< 
    boolean_t                   bSwBrk;             ///< 
}stc_adt_disable_3_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT1
 ** \note
 ******************************************************************************/
typedef struct stc_adt_disable_1_cfg
{
    boolean_t   bTim6OutSH;     ///< TIM6
    boolean_t   bTim5OutSH;     ///< TIM5
    boolean_t   bTim4OutSH;     ///< TIM4
    boolean_t   bTim6OutSL;     ///< TIM6
    boolean_t   bTim5OutSL;     ///< TIM5
    boolean_t   bTim4OutSL;     ///< TIM4
}stc_adt_disable_1_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT PWM
 ** \note
 ******************************************************************************/
typedef struct stc_adt_pwm_dither_cfg
{
    en_adt_pwm_dither_type_t    enAdtPDType;    ///< PWM
    boolean_t   bTimxBPDEn;                     ///< PWMB
    boolean_t   bTimxAPDEn;                     ///< PWMA
}stc_adt_pwm_dither_cfg_t;


/**
 ******************************************************************************
 ** \brief ADT
 ** \note
 ******************************************************************************/
typedef struct stc_adt_basecnt_cfg
{
    en_adt_cnt_mode_t       enCntMode;      ///< 
    en_adt_cnt_dir_t        enCntDir;       ///< 
    en_adt_cnt_ckdiv_t      enCntClkDiv;    ///< 
}stc_adt_basecnt_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT
 ** \note
 ******************************************************************************/
typedef struct stc_adt_cntstate_cfg
{
    uint16_t         u16Counter;      ///< 
    boolean_t        enCntDir;        ///< 
    uint8_t          u8ValidPeriod;   ///< 
    boolean_t        bCMSBDF;         ///< B
    boolean_t        bCMSBUF;         ///< A
    boolean_t        bCMSADF;         ///< B
    boolean_t        bCMSAUF;         ///< A
    boolean_t        bDTEF;           ///< 
    boolean_t        bUDFF;           ///< 
    boolean_t        bOVFF;           ///< 
    boolean_t        bCMDF;           ///< D
    boolean_t        bCMCF;           ///< C
    boolean_t        bCMBF;           ///< B
    boolean_t        bCMAF;           ///< A
}stc_adt_cntstate_cfg_t;

/**
 ******************************************************************************
 ** \brief ADT
 ** \note
 ******************************************************************************/
typedef struct stc_adt_validper_cfg
{
    en_adt_vperr_pcnts_t    enValidCnt;     ///< 
    en_adt_vperr_pcnte_t    enValidCdt;     ///< 
    boolean_t               bPeriodD;       ///< D
    boolean_t               bPeriodC;       ///< C
    boolean_t               bPeriodB;       ///< B
    boolean_t               bPeriodA;       ///< A
}stc_adt_validper_cfg_t;

/******************************************************************************
 * Global definitions
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
en_result_t Adt_ConfigHwCntUp(en_adt_unit_t enAdtUnit, en_adt_hw_cnt_t enAdtHwCntUp);
en_result_t Adt_ClearHwCntUp(en_adt_unit_t enAdtUnit);
en_result_t Adt_ConfigHwCntDwn(en_adt_unit_t enAdtUnit, en_adt_hw_cnt_t enAdtHwCntDwn);
en_result_t Adt_ClearHwCntDwn(en_adt_unit_t enAdtUnit);
en_result_t Adt_ConfigHwStart(en_adt_unit_t enAdtUnit, en_adt_hw_trig_t enAdtHwStart);
en_result_t Adt_ClearHwStart(en_adt_unit_t enAdtUnit);
en_result_t Adt_EnableHwStart(en_adt_unit_t enAdtUnit);
en_result_t Adt_DisableHwStart(en_adt_unit_t enAdtUnit);
en_result_t Adt_ConfigHwStop(en_adt_unit_t enAdtUnit, en_adt_hw_trig_t enAdtHwStop);
en_result_t Adt_ClearHwStop(en_adt_unit_t enAdtUnit);
en_result_t Adt_EnableHwStop(en_adt_unit_t enAdtUnit);
en_result_t Adt_DisableHwStop(en_adt_unit_t enAdtUnit);
en_result_t Adt_ConfigHwClear(en_adt_unit_t enAdtUnit, en_adt_hw_trig_t enAdtHwClear);
en_result_t Adt_ClearHwClear(en_adt_unit_t enAdtUnit);
en_result_t Adt_EnableHwClear(en_adt_unit_t enAdtUnit);
en_result_t Adt_DisableHwClear(en_adt_unit_t enAdtUnit);
en_result_t Adt_ConfigHwCaptureA(en_adt_unit_t enAdtUnit, en_adt_hw_trig_t enAdtHwCaptureA);
en_result_t Adt_ClearHwCaptureA(en_adt_unit_t enAdtUnit);
en_result_t Adt_ConfigHwCaptureB(en_adt_unit_t enAdtUnit, en_adt_hw_trig_t enAdtHwCaptureB);
en_result_t Adt_ClearHwCaptureB(en_adt_unit_t enAdtUnit);

en_result_t Adt_SwSyncStart(stc_adt_sw_sync_t* pstcAdtSwSyncStart);
en_result_t Adt_SwSyncStop(stc_adt_sw_sync_t* pstcAdtSwSyncStop);
en_result_t Adt_SwSyncClear(stc_adt_sw_sync_t* pstcAdtSwSyncClear);
en_result_t Adt_GetSwSyncState(stc_adt_sw_sync_t* pstcAdtSwSyncState);

en_result_t Adt_AosTrigConfig(stc_adt_aos_trig_cfg_t* pstcAdtAosTrigCfg);

en_result_t Adt_IrqTrigConfig(en_adt_unit_t enAdtUnit,
                              stc_adt_irq_trig_cfg_t* pstcAdtIrqTrigCfg);

en_result_t Adt_PortTrigConfig(en_adt_trig_port_t enAdtTrigPort,
                               stc_adt_port_trig_cfg_t* pstcAdtPortTrigCfg);

en_result_t Adt_CHxXPortConfig(en_adt_unit_t enAdtUnit,
                                en_adt_CHxX_port_t enAdtCHxXPort,
                                stc_adt_CHxX_port_cfg_t* pstcAdtCHxXCfg);

en_result_t Adt_EnableBreakPort(uint8_t port, stc_adt_break_port_cfg_t* pstcAdtBrkPtCfg);
void Adt_ClearBrakePort(void);
en_result_t Adt_Disable3Cfg(stc_adt_disable_3_cfg_t* pstcAdtDisable3);
boolean_t Adt_GetPortBrakeFlag(void);
void Adt_ClearPortBrakeFlag(void);
en_result_t Adt_Disable1Cfg(stc_adt_disable_1_cfg_t* pstcAdtDisable1);
boolean_t Adt_GetSameBrakeFlag(void);
void Adt_ClearSameBrakeFlag(void);

en_result_t Adt_PwmDitherConfig(en_adt_unit_t enAdtUnit, stc_adt_pwm_dither_cfg_t* pstcAdtPwmDitherCfg);

en_result_t Adt_Init(en_adt_unit_t enAdtUnit, stc_adt_basecnt_cfg_t* pstcAdtBaseCntCfg);
en_result_t Adt_DeInit(en_adt_unit_t enAdtUnit);

en_result_t Adt_StartCount(en_adt_unit_t enAdtUnit);
en_result_t Adt_StopCount(en_adt_unit_t enAdtUnit);
en_result_t Adt_SetCount(en_adt_unit_t enAdtUnit, uint16_t u16Value);
uint16_t Adt_GetCount(en_adt_unit_t enAdtUnit);
en_result_t Adt_ClearCount(en_adt_unit_t enAdtUnit);
en_result_t Adt_GetCntState(en_adt_unit_t enAdtUnit, stc_adt_cntstate_cfg_t* pstcAdtCntState);
en_result_t Adt_SetPeriod(en_adt_unit_t enAdtUnit, uint16_t u16Period);
en_result_t Adt_SetPeriodBuf(en_adt_unit_t enAdtUnit, uint16_t u16PeriodBuf);
en_result_t Adt_ClearPeriodBuf(en_adt_unit_t enAdtUnit);
en_result_t Adt_SetValidPeriod(en_adt_unit_t enAdtUnit,
                               stc_adt_validper_cfg_t* pstcAdtValidPerCfg);
en_result_t Adt_SetCompareValue(en_adt_unit_t enAdtUnit,
                                en_adt_compare_t enAdtCompare,
                                uint16_t u16Compare);
en_result_t Adt_EnableValueBuf(en_adt_unit_t enAdtUnit,
                                 en_adt_CHxX_port_t enAdtCHxXPort,
                                 boolean_t bCompareBufEn);
en_result_t Adt_ClearValueBuf(en_adt_unit_t enAdtUnit,
                                     en_adt_CHxX_port_t enAdtCHxXPort);
en_result_t Adt_GetCaptureValue(en_adt_unit_t enAdtUnit,
                                en_adt_CHxX_port_t enAdtCHxXPort,
                                uint16_t* pu16Capture);
en_result_t Adt_GetCaptureBuf(en_adt_unit_t enAdtUnit,
                                en_adt_CHxX_port_t enAdtCHxXPort,
                                uint16_t* pu16CaptureBuf);

en_result_t Adt_SetDTUA(en_adt_unit_t enAdtUnit,
                        uint16_t u16Value);
en_result_t Adt_SetDTDA(en_adt_unit_t enAdtUnit,
                        uint16_t u16Value);
en_result_t Adt_ConfigDT(en_adt_unit_t enAdtUnit,
                         boolean_t bDTEn,
                         boolean_t bEqual);

en_result_t Adt_ConfigIrq(en_adt_unit_t enAdtUnit,
                          en_adt_irq_type_t enAdtIrq,
                          boolean_t bEn,
                          func_ptr_t pfnIrqCalbak);
en_result_t Adt_GetIrqFlag(en_adt_unit_t enAdtUnit,
                           en_adt_irq_type_t enAdtIrq,
                           boolean_t* pbFlag);
en_result_t Adt_ClearIrqFlag(en_adt_unit_t enAdtUnit,
                             en_adt_irq_type_t enAdtIrq);
en_result_t Adt_ConfigZMask(en_adt_unit_t enAdtUnit, 
                            stc_adt_zmask_cfg_t* pstcAdtZMaskCfg);

//@} // ADT Group

#ifdef __cplusplus
}
#endif

#endif /* __ADT_H__ */
/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
