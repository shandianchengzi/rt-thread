/******************************************************************************
* Copyright (C) 2019, Huada Semiconductor Co.,Ltd All rights reserved.
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
/** \file vc.h
 **
 ** Headerfile for Voltage Comparator functions
 ** @link VC Group Some description @endlink
 **
 **   - 2019-04-10    First Version
 **
 ******************************************************************************/

#ifndef __VC_H__
#define __VC_H__

/******************************************************************************
 * Include files
 ******************************************************************************/
#include "ddl.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup VcGroup Voltage Comparator (VC)
 **
 ******************************************************************************/
//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief VC
 *****************************************************************************/
typedef enum 
{
    VcChannel0 = 0u,                 //   0
    VcChannel1 = 1u,                 //   1
    VcChannel2 = 2u                  //   2
}en_vc_channel_t;


/**
 ******************************************************************************
 ** \brief VC                            VC_CR  VCx_HYS_SEL(x=012)
 *****************************************************************************/
typedef enum 
{
    VcDelayoff  = 0u,            //   
    VcDelay10mv = 1u,            //   10mv
    VcDelay20mv = 2u,            //   20mv
    VcDelay30mv = 3u,            //   30mv
}en_vc_cmp_delay_t;

/**
 ******************************************************************************
 ** \brief VC                       VC_CR  VCx_BIAS_SEL(x=012)
 *****************************************************************************/
typedef enum 
{
    VcBias300na  = 0u,            //   300nA
    VcBias1200na = 1u,            //   1.2uA
    VcBias10ua   = 2u,            //   10uA
    VcBias20ua   = 3u,            //   20uA
}en_vc_bias_current_t;

/**
 ******************************************************************************
 ** \brief VC                     VCx_CR  debounce_time(x=012)
 *****************************************************************************/
typedef enum 
{
    VcFilter7us     = 0u,            //   7us
    VcFilter14us    = 1u,            //   14us
    VcFilter28us    = 2u,            //   28us
    VcFilter112us   = 3u,            //   112us
    VcFilter450us   = 4u,            //   450us
    VcFilter1800us  = 5u,            //   1.8ms
    VcFilter7200us  = 6u,            //   7.2ms
    VcFilter28800us = 7u,            //   28.8ms
}en_vc_resp_filter_t;

/**
 ******************************************************************************
 ** \brief VC P
 *****************************************************************************/
typedef enum 
{                                                                                    
                                         //VC0             //VC1           //VC2
    VcInPCh0 = 0u,                //   0 PC0        0 PA0     0 PA5
    VcInPCh1 = 1u,                //   1 PC1        1 PA1     1 PB1
    VcInPCh2 = 2u,                //   2 PC2        2 PA2     2 PE9
    VcInPCh3 = 3u,                //   3 PC3        3 PA3     3 PE10
    VcInPCh4 = 4u,                //   4 PA0        4 PA4     4 PE11
    VcInPCh5 = 5u,                //   5 PA1        5 PA5     5 PE13
    VcInPCh6 = 6u,                //   6 PA2        6 PB1     6 PE14
    VcInPCh7 = 7u,                //   7 PA3        7 PB2     7 PE15
    VcInPCh8 = 8u,                //   7 PA4        8 PB10    8 PB11
    VcInPCh9 = 9u,                //   7 PA5        9 PB12    9 PB14
    VcInPCh10 = 10u,              //   7 PA6        10 PB13   10 PD9
    VcInPCh11 = 11u,              //   7 PA7        11 PB14   11 PD10
    VcInPCh12 = 12u,              //   7 PB4        12 PB4    12 PD11
    VcInPCh13 = 13u,              //   7 PB5        13 DAC0   13 PC7
    VcInPCh14 = 14u,              //   7 PB6        14 PB6    14 DAC0
    VcInPCh15 = 15u,              //   7 DAC0        15 PB7    15 DAC0                           
}en_vc_input_p_src_t;

/**
 ******************************************************************************
 ** \brief VC N
 *****************************************************************************/
typedef enum 
{
                                 //VC0                          //VC1                         //VC2
    VcInNCh0    = 0u,         //   0  PA0               0 PC0                0 PA5
    VcInNCh1    = 1u,         //   1  PA1               1 PC1                1 PB1
    VcInNCh2    = 2u,         //   2  PA2               2 PC2                2 PE11
    VcInNCh3    = 3u,         //   3  PA3               3 PC3                3 PE15
    VcInNCh4    = 4u,         //   4  PA4               4 PA0                4 PB11
    VcInNCh5    = 5u,         //   5  PA5               5 PA1                5 PB14
    VcInNCh6    = 6u,         //   6  PA6               6 PB0                6 PD10
    VcInNCh7    = 7u,         //   7  PA7               7 PB1                7 PD11
    VcInNCh8    = 8u,         //   8  PC4               8 PB2                8 PC7
    VcInNCh9    = 9u,         //   9  PC5               9 PB3                9 DAC0
    VcInNCh10   = 10u,        //   10 DAC0              10 DAC1              10 DAC0   
    ResDivOut   = 11u,        //                                             NA
    AiTs        = 12u,        //                 
    AiBg1p2     = 13u,        //   1.2V                 1.2V                 1.2V 
    AiAdcVref   = 14u,        //   ADCVREF              ADCVREF              ADCVREF
    AiLdo       = 15u,        //   LDO                  LDO                  LDO
}en_vc_input_n_src_t;

/**
 ******************************************************************************
 ** \brief VC
 *****************************************************************************/
typedef enum en_vc_irq_sel
{
    VcIrqNone = 0u,            ///< 
    VcIrqRise = 1u,            ///< 
    VcIrqFall = 2u,            ///< 
    VcIrqHigh = 3u,            ///< 

}en_vc_irq_sel_t;

/**
 ******************************************************************************
 ** \brief VC                       VC_IFR
 *****************************************************************************/
typedef enum en_vc_stat
{
    Vc0_Intf    = 0u,          //   VC0
    Vc1_Intf    = 1u,          //   VC1
    Vc0_Filter  = 2u,          //   VC0 Filter           
    Vc1_Filter  = 3u,          //   VC1 Filter           
    Vc2_Intf    = 4u,          //   VC2  
    Vc2_Filter  = 5u           //   VC2 Filter      
}en_vc_ifr_t;

/**
 ******************************************************************************
 ** \brief VC                      VCx_OUT_CFG(x=012)
 ** \note       VC0CHX = CHAVC1 VC2CHX = CHB
 *****************************************************************************/
typedef enum en_vc_output_cfg
{
    VcOutInvTimer = 0u,              //   Timer0,1,2,3 REFCLR
    VcOutTIM0RCLR = 1u,              //   TIM0 REFCLR
    VcOutTIM1RCLR = 2u,              //   TIM1 REFCLR
    VcOutTIM2RCLR = 3u,              //   TIM2 REFCLR
    VcOutTIM3RCLR = 4u,              //   TIM3 REFCLR
    VcOutTIMBK    = 5u,              //   Timer0,1,2,3
    VcOutInvTIM4  = 9u,              //   Timer4
    VcOutTIM4     = 10u,             //   Timer4CHX
    VcOutInvTIM5  = 11u,             //   Timer5
    VcOutTIM5     = 12u,             //   Timer5CHX
    VcOutInvTIM6  = 13u,             //   Timer6
    VcOutTIM6     = 14u,             //   Timer6CHX
    VcOutBrake    = 15u,             //   Advanced Timer
    VcOutDisable  = 16u              //       
}en_vc_output_cfg_t;

/**
 ******************************************************************************
 ** \brief VC DIVVref                   VC_CR   VC_REF2P5_SEL
 *****************************************************************************/
typedef enum en_vc_div_vref
{
    VcDivVrefAvcc = 0u,              ///< AVCC
    VcDivVrefAdc  = 1u,               ///< ADC_CR0 SREF
}en_vc_div_vref_t;

/**
 ******************************************************************************
 ** \brief VC               VC_CR   VC_REF2P5_SEL  VC_DIV_EN  VC_DIV
 *****************************************************************************/
typedef struct stc_vc_dac_cfg
{
    boolean_t           bDivEn;       //   VC_CR: VC_DIV_EN
    uint8_t             u8DivVal;     //   VC_CR: VC_DIV 0-63
    en_vc_div_vref_t    enDivVref;    //   VC_CR: VC_REF2P5_SEL
}stc_vc_dac_cfg_t;

/**
 ******************************************************************************
 ** \brief VC                
 *****************************************************************************/
typedef struct stc_vc_channel_cfg
{
    en_vc_channel_t         enVcChannel;        //   VC
    en_vc_cmp_delay_t       enVcCmpDly;         //   VC
    en_vc_bias_current_t    enVcBiasCurrent;    //   VC
    en_vc_resp_filter_t     enVcFilterTime;     //   
    en_vc_input_p_src_t     enVcInPin_P;        //   P
    en_vc_input_n_src_t     enVcInPin_N;        //   N
    en_vc_output_cfg_t      enVcOutCfg;         //   
    boolean_t               bFlten;             //   
}stc_vc_channel_cfg_t;

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
extern void Vc_CfgItType(en_vc_channel_t Channelx, en_vc_irq_sel_t ItType);
extern void  Vc_ItCfg(en_vc_channel_t Channelx, boolean_t NewStatus);
extern boolean_t Vc_GetItStatus(en_vc_ifr_t Result);
extern void Vc_ClearItStatus(en_vc_ifr_t NewStatus);
extern en_result_t Vc_DacInit(stc_vc_dac_cfg_t *pstcDacCfg);
extern void Vc_Init(stc_vc_channel_cfg_t *pstcChannelCfg);
extern void Vc_Cmd(en_vc_channel_t enChannel, boolean_t NewStatus);



#ifdef __cplusplus
}
#endif

#endif /* __VC_H__ */
/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

