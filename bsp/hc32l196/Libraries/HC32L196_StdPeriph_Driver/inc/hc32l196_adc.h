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
/******************************************************************************/
/** \file adc.h
 **
 ** Header file for AD Converter functions
 ** @link ADC Group Some description @endlink
 **
 **   - 2017-06-28 Alex    First Version
 **
 ******************************************************************************/

#ifndef __ADC_H__
#define __ADC_H__


/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ddl.h"


/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup AdcGroup AD Converter (ADC)
  **
 ******************************************************************************/
 
//@{

/******************************************************************************
 * Global definitions
 ******************************************************************************/
#define ADC_SCAN_CH0_EN     (0x1u)           /*!< SCANADC CH0 */
#define ADC_SCAN_CH1_EN     (0x1u<<1)        /*!< SCANADC CH1 */
#define ADC_SCAN_CH2_EN     (0x1u<<2)        /*!< SCANADC CH2 */
#define ADC_SCAN_CH3_EN     (0x1u<<3)        /*!< SCANADC CH3 */
#define ADC_SCAN_CH4_EN     (0x1u<<4)        /*!< SCANADC CH4 */
#define ADC_SCAN_CH5_EN     (0x1u<<5)        /*!< SCANADC CH5 */
#define ADC_SCAN_CH6_EN     (0x1u<<6)        /*!< SCANADC CH6 */
#define ADC_SCAN_CH7_EN     (0x1u<<7)        /*!< SCANADC CH7 */


/******************************************************************************
 ** Global type definitions
 *****************************************************************************/

 /**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_mode
{
    AdcSglMode  = 0u,           /*!<  */
    AdcScanMode = 1u,           /*!< /*/   
}en_adc_mode_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_clk_sel
{
    AdcMskClkDiv1  = 0u<<2,        /*!< PCLK */
    AdcMskClkDiv2  = 1u<<2,        /*!< 1/2 PCLK */
    AdcMskClkDiv4  = 2u<<2,        /*!< 1/4 PCLK */
    AdcMskClkDiv8  = 3u<<2,        /*!< 1/8 PCLK */
} en_adc_clk_div_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_ref_vol_sel
{
    AdcMskRefVolSelInBgr1p5 = 0u<<9,        /*!<1.5V(SPS<=200kHz)*/
    AdcMskRefVolSelInBgr2p5 = 1u<<9,        /*!<2.5V(avdd>3V,SPS<=200kHz)*/
    AdcMskRefVolSelExtern1  = 2u<<9,        /*!<(max avdd)   PB01*/
    AdcMskRefVolSelAVDD     = 3u<<9,        /*!<AVDD*/
}en_adc_ref_vol_sel_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_samp_ch_sel
{
    AdcExInputCH0    =  0u,        /*!<PA00*/
    AdcExInputCH1    =  1u,        /*!<PA01*/
    AdcExInputCH2    =  2u,        /*!<PA02*/
    AdcExInputCH3    =  3u,        /*!<PA03*/
    AdcExInputCH4    =  4u,        /*!<PA04*/
    AdcExInputCH5    =  5u,        /*!<PA05*/
    AdcExInputCH6    =  6u,        /*!<PA06*/
    AdcExInputCH7    =  7u,        /*!<PA07*/
    AdcExInputCH8    =  8u,        /*!<PB00*/
    AdcExInputCH9    =  9u,        /*!<PB01*/
    AdcExInputCH10   =  10u,       /*!<PC00*/
    AdcExInputCH11   =  11u,       /*!<PC01*/
    AdcExInputCH12   =  12u,       /*!<PC02*/
    AdcExInputCH13   =  13u,       /*!<PC03*/
    AdcExInputCH14   =  14u,       /*!<PC04*/
    AdcExInputCH15   =  15u,       /*!<PC05*/
    AdcExInputCH16   =  16u,       /*!<PB02*/
    AdcExInputCH17   =  17u,       /*!<PB10*/
    AdcExInputCH18   =  18u,       /*!<PB11*/
    AdcExInputCH19   =  19u,       /*!<PB12*/
    AdcExInputCH20   =  20u,       /*!<PB13*/
    AdcExInputCH21   =  21u,       /*!<PB14*/
    AdcExInputCH22   =  22u,       /*!<PB15*/
    AdcExInputCH23   =  23u,       /*!<PE15*/
    AdcExInputCH24   =  24u,       /*!<PE14*/
    AdcExInputCH25   =  25u,       /*!<PE13*/

    AdcDacInput      =  26u,       /*!<DAC()*/                    
    AdcAVccdiv3Input =  27u,       /*!<1/3 AVCC()*/
    AdcAiTsInput     =  28u,       /*!<BGR_TS()*/
    AdcVref1_2Input  =  29u,       /*!<1.2V()*/

}en_adc_samp_ch_sel_t;

 /**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_op_buf
{
    AdcMskBufEnable  = 1u<<11,          /*!< BUF */
    AdcMskBufDisable = 0u,              /*!< BUF */  
} en_adc_op_buf_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_samp_cycle_sel
{
    AdcMskSampCycle4Clk  =  0u<<12,        /*!<4*/
    AdcMskSampCycle6Clk  =  1u<<12,        /*!<6*/
    AdcMskSampCycle8Clk  =  2u<<12,        /*!<8*/
    AdcMskSampCycle12Clk =  3u<<12,        /*!<12*/

}en_adc_samp_cycle_sel_t;

 /**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_in_ref
{
    AdcMskInRefEnable  = 1u<<14,          /*!<  */
    AdcMskInRefDisable = 0u,              /*!<  */  
}en_adc_in_ref_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_trig_sel
{
    AdcMskTrigTimer0     =  1u<<0,         /*!<timer0ADC*/
    AdcMskTrigTimer1     =  1u<<1,         /*!<timer1ADC*/
    AdcMskTrigTimer2     =  1u<<2,         /*!<timer2ADC*/
    AdcMskTrigTimer3     =  1u<<3,         /*!<timer3ADC*/
    AdcMskTrigTimer4     =  1u<<4,         /*!<timer4ADC*/
    AdcMskTrigTimer5     =  1u<<5,         /*!<timer5ADC*/
    AdcMskTrigTimer6     =  1u<<6,         /*!<timer6ADC*/
    AdcMskTrigUart0      =  1u<<7,         /*!<uart0ADC*/
    AdcMskTrigUart1      =  1u<<8,         /*!<uart1ADC*/
    AdcMskTrigLpuart0    =  1u<<9,         /*!<lpuart0ADC*/
    AdcMskTrigLpuart1    =  1u<<10,        /*!<lpuart1ADC*/
    AdcMskTrigVC0        =  1u<<11,        /*!<VC0ADC*/
    AdcMskTrigVC1        =  1u<<12,        /*!<VC1ADC*/
    AdcMskTrigRTC        =  1u<<13,        /*!<RTCADC*/
    AdcMskTrigPCA        =  1u<<14,        /*!<PCAADC*/
    AdcMskTrigSPI0       =  1u<<15,        /*!<SPI0ADC*/
    AdcMskTrigSPI1       =  1u<<16,        /*!<SPI1ADC*/
    AdcMskTrigDMA        =  1u<<17,        /*!<DMAADC*/
    AdcMskTrigPA03       =  1u<<18,        /*!<PA03ADC*/
    AdcMskTrigPB03       =  1u<<19,        /*!<PB03ADC*/
    AdcMskTrigPC03       =  1u<<20,        /*!<PC03ADC*/
    AdcMskTrigPD03       =  1u<<21,        /*!<PD03ADC*/
    AdcMskTrigPA07       =  1u<<22,        /*!<PA07ADC*/
    AdcMskTrigPB07       =  1u<<23,        /*!<PB07ADC*/
    AdcMskTrigPC07       =  1u<<24,        /*!<PC07ADC*/
    AdcMskTrigPD07       =  1u<<25,        /*!<PD07ADC*/
    AdcMskTrigPA11       =  1u<<26,        /*!<PA11ADC*/
    AdcMskTrigPB11       =  1u<<27,        /*!<PB11ADC*/
    AdcMskTrigPC11       =  1u<<28,        /*!<PC11ADC*/
    AdcMskTrigPA15       =  1u<<29,        /*!<PA15ADC*/
    AdcMskTrigPB15       =  1u<<30,        /*!<PB15ADC*/
    AdcMskTrigPC15       =  1u<<31,        /*!<PC15ADC*/
}en_adc_trig_sel_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_ext_trig_sel
{
    AdcExtTrig0     =  0u,         /*!< */
    AdcExtTrig1     =  1u,         /*!< */
}en_adc_ext_trig_sel_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_sqr_chmux
{
    AdcSQRCH0MUX     =  0u,         /*!<0*/
    AdcSQRCH1MUX     =  1u,         /*!<1*/
    AdcSQRCH2MUX     =  2u,         /*!<2*/
    AdcSQRCH3MUX     =  3u,         /*!<3*/
    AdcSQRCH4MUX     =  4u,         /*!<4*/
    AdcSQRCH5MUX     =  5u,         /*!<5*/
    AdcSQRCH6MUX     =  6u,         /*!<6*/
    AdcSQRCH7MUX     =  7u,         /*!<7*/
    AdcSQRCH8MUX     =  8u,         /*!<8*/
    AdcSQRCH9MUX     =  9u,         /*!<9*/
    AdcSQRCH10MUX    =  10u,        /*!<10*/
    AdcSQRCH11MUX    =  11u,        /*!<11*/
    AdcSQRCH12MUX    =  12u,        /*!<12*/
    AdcSQRCH13MUX    =  13u,        /*!<13*/
    AdcSQRCH14MUX    =  14u,        /*!<14*/
    AdcSQRCH15MUX    =  15u,        /*!<15*/
}en_adc_sqr_chmux_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_jqr_chmux
{
    AdcJQRCH0MUX     =  0u,         /*!<0*/
    AdcJQRCH1MUX     =  1u,         /*!<1*/
    AdcJQRCH2MUX     =  2u,         /*!<2*/
    AdcJQRCH3MUX     =  3u,         /*!<3*/
}en_adc_jqr_chmux_t;
/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_align
{
     AdcAlignRight  = 0u,
     AdcAlignLeft   = 1u,
}en_adc_align_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_result_acc
{
     AdcResultAccEnable  = 1u,
     AdcResultAccDisable = 0u,
}en_adc_result_acc_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_irq_type
{
    AdcMskIrqJqr =  1u<<5,        /*!<ADC*/
    AdcMskIrqSqr =  1u<<4,        /*!<ADC*/
    AdcMskIrqReg =  1u<<3,        /*!<ADC*/
    AdcMskIrqHt  =  1u<<2,        /*!<ADCHT*/
    AdcMskIrqLt  =  1u<<1,        /*!<ADCLT*/
    AdcMskIrqSgl =  1u<<0,        /*!<ADC*/

}en_adc_irq_type_t;


/******************************************************************************
 ** Extern type definitions ('typedef')
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief  ADC
 *****************************************************************************/
typedef struct stc_adc_cfg
{
    en_adc_mode_t           enAdcMode;                  /*! ADC*/
    
    en_adc_clk_div_t        enAdcClkDiv;                /*! ADC*/
    en_adc_samp_cycle_sel_t enAdcSampCycleSel;          /*! ADC*/
    en_adc_ref_vol_sel_t    enAdcRefVolSel;             /*! ADC*/
    en_adc_op_buf_t         enAdcOpBuf;                 /*! ADC*/
    en_adc_in_ref_t         enInRef;                    /*! ADC*/
    
    en_adc_align_t          enAdcAlign;                 /*! ADC*/
}stc_adc_cfg_t;


/**
 ******************************************************************************
 ** \brief  ADC
 *****************************************************************************/
typedef struct stc_adc_sqr_cfg
{
    uint8_t                 u8SqrCnt;                   /*! ADC*/
    en_adc_result_acc_t     enResultAcc;                /*! ADC*/
    boolean_t               bSqrDmaTrig;                /*! ADCDMA*/
}stc_adc_sqr_cfg_t;

/**
 ******************************************************************************
 ** \brief  ADC
 *****************************************************************************/
typedef struct stc_adc_jqr_cfg
{
    uint8_t                 u8JqrCnt;                   /*! ADC*/
    boolean_t               bJqrDmaTrig;                /*! ADCDMA*/    
}stc_adc_jqr_cfg_t;


/**
 ******************************************************************************
 ** \brief  ADC
 *****************************************************************************/
typedef struct stc_adc_threshold_cfg
{
    boolean_t bAdcRegCmp ;                  /*!ADC*/ 
    boolean_t bAdcHtCmp ;                   /*!ADC*/ 
    boolean_t bAdcLtCmp ;                   /*!ADC*/
    
    uint32_t u32AdcHighThd;                 /*!ADC*/
    uint32_t u32AdcLowThd;                  /*!ADC*/ 
    
    en_adc_samp_ch_sel_t    enSampChSel;    /*!ADC*/
    
}stc_adc_threshold_cfg_t;


/******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
//ADC 
en_result_t Adc_Init(stc_adc_cfg_t* pstcAdcCfg);

//ADC 
void Adc_EnableIrq(void);
//ADC 
void Adc_DisableIrq(void);

//ADC /
boolean_t Adc_GetIrqStatus(en_adc_irq_type_t enAdcIrq);
//ADC /
void Adc_ClrIrqStatus(en_adc_irq_type_t enAdcIrq);

//ADC 
void Adc_Enable(void);
//ADC 
void Adc_Disable(void);

//ADC 
en_result_t Adc_SqrModeCfg(stc_adc_sqr_cfg_t* pstcAdcSqrCfg);
//ADC 
en_result_t Adc_JqrModeCfg(stc_adc_jqr_cfg_t* pstcAdcJqrCfg);

//ADC Sgl  
en_result_t Adc_CfgSglChannel( en_adc_samp_ch_sel_t enstcAdcSampCh);
//ADC SQR  
en_result_t Adc_CfgSqrChannel(en_adc_sqr_chmux_t enstcAdcSqrChMux, en_adc_samp_ch_sel_t enstcAdcSampCh);
//ADC JQR  
en_result_t Adc_CfgJqrChannel(en_adc_jqr_chmux_t enstcAdcJqrChMux, en_adc_samp_ch_sel_t enstcAdcSampCh);

///<ADC 
void Adc_SglExtTrigCfg(en_adc_trig_sel_t enAdcTrigSel, boolean_t bValue);
///<ADC 
void Adc_SqrExtTrigCfg(en_adc_trig_sel_t enAdcTrigSel, boolean_t bValue);
///<ADC 
void Adc_JqrExtTrigCfg(en_adc_trig_sel_t enAdcTrigSel, boolean_t bValue);

//ADC 
void Adc_ThresholdCfg(stc_adc_threshold_cfg_t* pstcAdcThrCfg);

//ADC 
void Adc_SGL_Start(void);
//ADC 
void Adc_SGL_Stop(void);

//ADC 
void Adc_SGL_Always_Start(void);
//ADC 
void Adc_SGL_Always_Stop(void);

//ADC 
void Adc_SQR_Start(void);
//ADC 
void Adc_SQR_Stop(void);

//ADC 
void Adc_JQR_Start(void);
//ADC 
void Adc_JQR_Stop(void);

//
uint32_t Adc_GetSglResult(void);
//
uint32_t Adc_GetSqrResult(en_adc_sqr_chmux_t enstcAdcSqrChMux);
//
uint32_t Adc_GetJqrResult(en_adc_jqr_chmux_t enstcAdcJqrChMux);

//
uint32_t Adc_GetAccResult(void);
//clear ADC 
void Adc_ClrAccResult(void);

//@}
#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
