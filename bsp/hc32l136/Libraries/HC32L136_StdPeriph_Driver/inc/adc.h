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
#include "interrupts_hc32l136.h"

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
typedef enum en_adc_op_mode
{
    AdcSglMode  = 0u,        /*!<  */
    AdcSCanMode     = 1u,        /*!< ,*/   
} en_adc_op_mode_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_clk_sel
{
    AdcClkSysTDiv1  = 0u,        /*!< PCLK */
    AdcClkSysTDiv2  = 1u,        /*!< 1/2 PCLK */
    AdcClkSysTDiv4  = 2u,        /*!< 1/4 PCLK */
    AdcClkSysTDiv8  = 3u,        /*!< 1/8 PCLK */

} en_adc_clk_div_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_ref_vol_sel
{
    RefVolSelInBgr1p5 = 0u,        /*!<1.5V(SPS<=200kHz)*/
    RefVolSelInBgr2p5 = 1u,        /*!<2.5V(avdd>3V,SPS<=200kHz)*/
    RefVolSelExtern1  = 2u,        /*!<(max avdd)   PB01*/
    RefVolSelAVDD     = 3u,        /*!<AVDD*/

}en_adc_ref_vol_sel_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_samp_ch_sel
{
    AdcExInputCH0    =  0u,        /*!<0PA00*/
    AdcExInputCH1    =  1u,        /*!<1PA01*/
    AdcExInputCH2    =  2u,        /*!<2PA02*/
    AdcExInputCH3    =  3u,        /*!<3PA03*/
    AdcExInputCH4    =  4u,        /*!<4PA04*/
    AdcExInputCH5    =  5u,        /*!<5PA05*/
    AdcExInputCH6    =  6u,        /*!<6PA06*/
    AdcExInputCH7    =  7u,        /*!<7PA07*/
    AdcExInputCH8    =  8u,        /*!<8PB00*/
    AdcExInputCH9    =  9u,        /*!<8PB01*/
    AdcExInputCH10   =  10u,       /*!<8PC00*/
    AdcExInputCH11   =  11u,       /*!<1PC01*/
    AdcExInputCH12   =  12u,       /*!<2PC02*/
    AdcExInputCH13   =  13u,       /*!<3PC03*/
    AdcExInputCH14   =  14u,       /*!<4PC04*/
    AdcExInputCH15   =  15u,       /*!<5PC05*/
    AdcExInputCH16   =  16u,       /*!<6PB02*/
    AdcExInputCH17   =  17u,       /*!<7PB10*/
    AdcExInputCH18   =  18u,       /*!<8PB11*/
    AdcExInputCH19   =  19u,       /*!<8PB12*/
    AdcExInputCH20   =  20u,       /*!<7PB13*/
    AdcExInputCH21   =  21u,       /*!<8PB14*/
    AdcExInputCH22   =  22u,       /*!<8PB15*/
    AdcExInputCH23   =  23u,       /*!<8PC06*/  
    AdcOPA0Input     =  24u,       /*!<8OPA0*/
    AdcOPA1Input     =  25u,       /*!<8OPA1*/
    AdcOPA2Input     =  26u,       /*!<8OPA2*/                     
    AdcAVccDiV3Input =  27u,       /*!<1/3 AVCC()*/
    AdcAiTsInput     =  28u,       /*!<BGR_TS()*/
    AdcVref1P2Input  =  29u,       /*!<Vref1P2()*/

}en_adc_samp_ch_sel_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_samp_time_sel
{
    AdcSampTime4Clk  =  0u,        /*!<4*/
    AdcSampTime6Clk  =  1u,        /*!<6*/
    AdcSampTime8Clk  =  2u,        /*!<8*/
    AdcSampTime12Clk =  3u,        /*!<12*/

}en_adc_samp_time_sel_t;

/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_trig_sel
{
    AdcTrigTimer0     =  0u,         /*!<timer0ADC*/
    AdcTrigTimer1     =  1u,         /*!<timer1ADC*/
    AdcTrigTimer2     =  2u,         /*!<timer2ADC*/
    AdcTrigTimer3     =  3u,         /*!<timer3ADC*/
    AdcTrigTimer4     =  4u,         /*!<timer4ADC*/
    AdcTrigTimer5     =  5u,         /*!<timer5ADC*/
    AdcTrigTimer6     =  6u,         /*!<timer6ADC*/
    AdcTrigUart0      =  7u,         /*!<uart0ADC*/
    AdcTrigUart1      =  8u,         /*!<uart1ADC*/
    AdcTrigLpuart0    =  9u,         /*!<lpuart0ADC*/
    AdcTrigLpuart1    =  10u,        /*!<lpuart1ADC*/
    AdcTrigVC0        =  11u,        /*!<VC0ADC*/
    AdcTrigVC1        =  12u,        /*!<VC1ADC*/
    AdcTrigRTC        =  13u,        /*!<RTCADC*/
    AdcTrigPCA        =  14u,        /*!<PCAADC*/
    AdcTrigSPI0       =  15u,        /*!<SPI0ADC*/
    AdcTrigSPI1       =  16u,        /*!<SPI1ADC*/
    AdcTrigDMA        =  17u,        /*!<DMAADC*/
    AdcTrigPA03       =  18u,        /*!<PA03ADC*/
    AdcTrigPB03       =  19u,        /*!<PB03ADC*/
    AdcTrigPC03       =  20u,        /*!<PC03ADC*/
    AdcTrigPD03       =  21u,        /*!<PD03ADC*/
    AdcTrigPA07       =  22u,        /*!<PA07ADC*/
    AdcTrigPB07       =  23u,        /*!<PB07ADC*/
    AdcTrigPC07       =  24u,        /*!<PC07ADC*/
    AdcTrigPD07       =  25u,        /*!<PD07ADC*/
    AdcTrigPA11       =  26u,        /*!<PA11ADC*/
    AdcTrigPB11       =  27u,        /*!<PB11ADC*/
    AdcTrigPC11       =  28u,        /*!<PC11ADC*/
    AdcTrigPA15       =  29u,        /*!<PA15ADC*/
    AdcTrigPB15       =  30u,        /*!<PB15ADC*/
    AdcTrigPC15       =  31u,        /*!<PC15ADC*/
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
    CH0MUX     =  0u,         /*!<0*/
    CH1MUX     =  1u,         /*!<1*/
    CH2MUX     =  2u,         /*!<2*/
    CH3MUX     =  3u,         /*!<3*/
    CH4MUX     =  4u,         /*!<4*/
    CH5MUX     =  5u,         /*!<5*/
    CH6MUX     =  6u,         /*!<6*/
    CH7MUX     =  7u,         /*!<7*/
    CH8MUX     =  8u,         /*!<8*/
    CH9MUX     =  9u,         /*!<9*/
    CH10MUX    =  10u,        /*!<10*/
    CH11MUX    =  11u,        /*!<11*/
    CH12MUX    =  12u,        /*!<12*/
    CH13MUX    =  13u,        /*!<13*/
    CH14MUX    =  14u,        /*!<14*/
    CH15MUX    =  15u,        /*!<15*/
}en_adc_sqr_chmux_t;
/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_jqr_chmux
{
    JQRCH0MUX     =  0u,         /*!<0*/
    JQRCH1MUX     =  1u,         /*!<1*/
    JQRCH2MUX     =  2u,         /*!<2*/
    JQRCH3MUX     =  3u,         /*!<3*/
}en_adc_jqr_chmux_t;
/**
 ******************************************************************************
 ** \brief ADC
 *****************************************************************************/
typedef enum en_adc_align
{
     AlignRight  = 0u,
     AlignLeft = 1u,    
}en_adc_align_t;
/******************************************************************************
 * Extern type definitions ('typedef')                                        *
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief  ADC
 *****************************************************************************/
typedef struct stc_adc_cfg
{
    /*! ADC*/
    en_adc_op_mode_t enAdcOpMode;

    /*! ADC*/
    en_adc_clk_div_t  enAdcClkDiv;

    /*! ADC*/
    en_adc_samp_time_sel_t  enAdcSampTimeSel;

    /*! ADC*/
    en_adc_ref_vol_sel_t    enAdcRefVolSel;

    /*! ADC*/
    boolean_t    bAdcInBufEn;
}stc_adc_cfg_t;

 /**
 ******************************************************************************
 ** \brief  ADC DMA
 *****************************************************************************/
typedef enum en_adc_dmatrig
{
   /*!DMA*/ 
  DmaJqr = 0, 
   /*!DMA*/   
  DmaSqr = 1   
}en_adc_dmatrig_t;
 /**
 ******************************************************************************
 ** \brief  ADC
 *****************************************************************************/
typedef struct stc_adc_ext_trig_cfg
{
    /*! */
    en_adc_ext_trig_sel_t   enAdcExtTrigRegSel;
    
    /*! ADC*/
    en_adc_trig_sel_t       enAdcTrig0Sel;

    /*! ADC*/
    en_adc_trig_sel_t       enAdcTrig1Sel;

}stc_adc_ext_trig_cfg_t;

/**
 ******************************************************************************
 ** \brief  ADC
 *****************************************************************************/
typedef struct stc_adc_irq
{
    /*!<ADC*/
    boolean_t  bAdcJQRIrq;   
    /*!<ADC*/
    boolean_t  bAdcSQRIrq;  
    /*! ADC*/
    boolean_t  bAdcRegCmp;
    /*! ADC*/
    boolean_t  bAdcHhtCmp;
    /*! ADC*/
    boolean_t  bAdcLltCmp;    
    /*!<ADC*/
    boolean_t  bAdcIrq;
}stc_adc_irq_t;

typedef struct stc_adc_threshold_cfg
{
   
    boolean_t bAdcRegCmp ;      /*!ADC*/ 

    boolean_t bAdcHhtCmp ;     /*!ADC*/ 

    boolean_t bAdcLltCmp ;     /*!ADC*/
    
    uint32_t u32AdcRegHighThd; /*!ADC*/
    
    uint32_t u32AdcRegLowThd; /*!ADC*/ 
    
    en_adc_samp_ch_sel_t enThCh; /*!*/
    
}stc_adc_threshold_cfg_t;
/**
 ******************************************************************************
 ** \brief  ADC
 *****************************************************************************/
typedef struct stc_adc_irq_calbakfn_pt
{
    /*! ADC*/
    func_ptr_t  pfnAdcJQRIrq;
    /*! ADC*/
    func_ptr_t  pfnAdcSQRIrq;    
    /*! ADC*/
    func_ptr_t  pfnAdcRegIrq;
    /*! ADC*/
    func_ptr_t  pfnAdcHhtIrq;
    /*! ADC*/
    func_ptr_t  pfnAdcLltIrq;
    /*! ADC*/
    func_ptr_t  pfnAdcIrq; 
}stc_adc_irq_calbakfn_pt_t;

/******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
//ADC initialization
en_result_t Adc_Init(stc_adc_cfg_t* pstcAdcConfig);
//ADC ExtTrig Register config
en_result_t Adc_ExtTrigCfg(stc_adc_ext_trig_cfg_t* pstcExtTrigConfig);
//ADC de-init
void Adc_DeInit(void);

//ADC conversion start
void Adc_SGL_Start(void);
//ADC conversion stop
void Adc_SGL_Stop(void);

//ADC SQR conversion start
void Adc_SQR_Start(void);
//ADC SQR conversion stop
void Adc_SQR_Stop(void);

//ADC JQR conversion start
void Adc_JQR_Start(void);
//ADC JQR conversion stop
void Adc_JQR_Stop(void);

//ADC conversion enable
void Adc_Enable(void);
//ADC conversion disable
void Adc_Disable(void);

//ADC single covert mode configuration
en_result_t Adc_ConfigSglMode(stc_adc_cfg_t* pstcAdcConfig);
//ADC SQR mode configuration
en_result_t Adc_ConfigSqrMode(stc_adc_cfg_t* pstcAdcConfig, uint8_t u8AdcSampCnt,boolean_t  bAdcResultAccEn);
//ADC JQR mode configuration
en_result_t Adc_ConfigJqrMode(stc_adc_cfg_t* pstcAdcConfig, uint8_t u8AdcSampCnt,boolean_t  bAdcResultAccEn);

//ADC single covert mode channel configuraion 
en_result_t Adc_ConfigSglChannel( en_adc_samp_ch_sel_t enstcAdcSampCh);
//ADC SQR mode channel configuraion 
en_result_t Adc_ConfigSqrChannel(en_adc_sqr_chmux_t enstcAdcSqrChMux, en_adc_samp_ch_sel_t enstcAdcSampCh);
//ADC JQR mode channel configuraion 
en_result_t Adc_ConfigJqrChannel(en_adc_jqr_chmux_t enstcAdcJqrChMux, en_adc_samp_ch_sel_t enstcAdcSampCh);
//ADC DMA Trigger 
en_result_t Adc_ConfigDmaTrig(en_adc_dmatrig_t enAdcDmaTrig);
//ADC IRQ configuration
void Adc_ConfigIrq(stc_adc_irq_t* pstcAdcIrqCfg,
                   stc_adc_irq_calbakfn_pt_t* pstcAdcIrqCalbaks);
//ADC enable IRQ
void Adc_EnableIrq(void);
//ADC disable IRQ
void Adc_DisableIrq(void);
//ADC enable threshold compare
void Adc_ThresholdCfg(stc_adc_threshold_cfg_t* stcAdcThrCfg);
//ADC get IRQ state
void Adc_GetIrqState(stc_adc_irq_t* pstcAdcIrqState);
//ADC clear IRQ states
void Adc_ClrSglIrqState(void);
void Adc_ClrJqrIrqState(void);
void Adc_ClrSqrIrqState(void);
void Adc_ClrRegIrqState(void);
void Adc_ClrHtIrqState(void);
void Adc_ClrLtIrqState(void);

//ADC
boolean_t Adc_PollSglBusyState(void);
//ADC
boolean_t Adc_PollSqrBusyState(void);
//ADC
boolean_t Adc_PollJqrBusyState(void);
//ADC
boolean_t Adc_PollRegBusyState(void);
//ADC
boolean_t Adc_PollHTBusyState(void);
//ADC
boolean_t Adc_PollLtBusyState(void);
//
en_result_t Adc_GetSglResult(uint16_t* pu16AdcResult);
//
en_result_t Adc_GetSqrResult(uint16_t* pu16AdcResult,uint8_t SQRChannelIndex);
//
en_result_t Adc_GetJqrResult(uint16_t* pu16AdcResult,uint8_t JQRChannelIndex);
//
en_result_t Adc_GetAccResult(uint32_t* pu32AdcAccResult);
//clear ADC accumulated result
void Adc_ClrAccResult(void);
//
en_result_t Adc_SetVref(en_adc_ref_vol_sel_t enAdcRefVolSel);
//
en_result_t Adc_SetAlign(en_adc_align_t enAlign);
//@}
#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
