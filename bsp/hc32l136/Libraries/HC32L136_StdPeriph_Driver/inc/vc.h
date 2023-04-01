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
/** \file vc.h
 **
 ** Headerfile for Voltage Comparator functions
 ** @link VC Group Some description @endlink
 **
 **   - 2017-06-28 Alex    First Version
 **
 ******************************************************************************/

#ifndef __VC_H__
#define __VC_H__

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
typedef enum en_vc_channel
{
    VcChannel0 = 0u,                 ///< 0
    VcChannel1 = 1u,                 ///< 1
}en_vc_channel_t;


/**
 ******************************************************************************
 ** \brief VC
 *****************************************************************************/
typedef enum en_vc_cmp_delay
{
    VcDelayoff  = 0u,            ///< 
    VcDelay10mv = 1u,            ///< 10mv
    VcDelay20mv = 2u,            ///< 20mv
    VcDelay30mv = 3u,            ///< 30mv
}en_vc_cmp_delay_t;

/**
 ******************************************************************************
 ** \brief VC
 *****************************************************************************/
typedef enum en_vc_bias_current
{
    VcBias300na  = 0u,            ///< 300na
    VcBias1200na = 1u,            ///< 1.2ua
    VcBias10ua   = 2u,            ///< 10ua
    VcBias20ua   = 3u,            ///< 20ua
}en_vc_bias_current_t;

/**
 ******************************************************************************
 ** \brief VC
 *****************************************************************************/
typedef enum en_vc_resp_filter
{
    VcFilter7us     = 0u,            ///< 7us
    VcFilter14us    = 1u,           ///< 14us
    VcFilter28us    = 2u,           ///< 28us
    VcFilter112us   = 3u,          ///< 112us
    VcFilter450us   = 4u,          ///< 450us
    VcFilter1800us  = 5u,         ///< 1.8ms
    VcFilter7200us  = 6u,         ///< 7.2ms
    VcFilter28800us = 7u,        ///< 28.8ms
}en_vc_resp_filter_t;

/**
 ******************************************************************************
 ** \brief VC P
 *****************************************************************************/
typedef enum en_vc_input_p_src
{																					
                                   //VC0                        //VC1
    VcInPCh0 = 0u,                ///< 0 PC0		0 PA0
    VcInPCh1 = 1u,                ///< 1 PC1		0 PA1
    VcInPCh2 = 2u,                ///< 2 PC2		0 PA2
    VcInPCh3 = 3u,                ///< 3 PC3		0 PA3
    VcInPCh4 = 4u,                ///< 4 PA0		0 PA4
    VcInPCh5 = 5u,                ///< 5 PA1		0 PA5
    VcInPCh6 = 6u,                ///< 6 PA2		0 PB1
    VcInPCh7 = 7u,                ///< 7 PA3		0 PB2
    VcInPCh8 = 8u,                ///< 7 PA4		0 PB10
    VcInPCh9 = 9u,                ///< 7 PA5		0 PB12
    VcInPCh10 = 10u,                ///< 7 PA6		0 PB13
    VcInPCh11 = 11u,                ///< 7 PA7		0 PB14
    VcInPCh12 = 12u,                ///< 7 PB4		0 PB4
    VcInPCh13 = 13u,                ///< 7 PB5		0 PB5
    VcInPCh14 = 14u,                ///< 7 PB6		0 PB6
    VcInPCh15 = 15u,                ///< 7 PB7		0 PB7                           
}en_vc_input_p_src_t;

/**
 ******************************************************************************
 ** \brief VC N
 *****************************************************************************/
typedef enum en_vc_input_n_src
{
                                 //VC0                          //VC1
    VcInNCh0    = 0u,         ///< 0  PA0	        0 PC0
    VcInNCh1    = 1u,         ///< 1  PA1		0 PC1
    VcInNCh2    = 2u,         ///< 2  PA2		0 PC2
    VcInNCh3    = 3u,         ///< 3  PA3		0 PC3
    VcInNCh4    = 4u,         ///< 4  PA4		0 PA0
    VcInNCh5    = 5u,         ///< 5  PA5		0 PA1
    VcInNCh6    = 6u,         ///< 6  PA6		0 PB0
    VcInNCh7    = 7u,         ///< 7  PA7		0 PB1
    VcInNCh8    = 8u,         ///< 8  PC4		0 PB2
    VcInNCh9    = 9u,         ///< 9  PC5		0 PB3
    VcInNCh10   = 10u,        ///< 10 PB0 		0 PB4   
    ResDivOut   = 11u,        ///< Vcc                      Vcc
    AiTs        = 12u,        ///<                   
    AiBg1p2     = 13u,        ///< BGR 1.2V                    BGR 1.2V
    AiAdcVref   = 14u,        ///< ADCVREF                     ADCVREF
    AiLdo       = 15u,        ///< LDO                         LDO
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
 ** \brief VC
 *****************************************************************************/
typedef enum en_vc_stat
{
    VcCmpResult  = 0u,                ///< VC
    VcIntrResult = 1u,               ///< VC
}en_vc_stat_t;

/**
 ******************************************************************************
 ** \brief VC
 *****************************************************************************/
typedef enum en_vc_output_config
{
    VcOutInvTimer = 0u,              ///< Timer0,1,2,3
    VcOutTIM0RCLR = 1u,              ///< TIM0 REFCLR
    VcOutTIM1RCLR = 2u,              ///< TIM1 REFCLR
    VcOutTIM2RCLR = 3u,              ///< TIM2 REFCLR
    VcOutTIM3RCLR = 4u,              ///< TIM3 REFCLR
    VcOutTIMBK    = 5u,              ///< Timer0,1,2,3
    VcOutInvTIM4  = 9u,              ///< Timer4
    VcOutTIM4     = 10u,             ///< Timer4
    VcOutInvTIM5  = 11u,             ///< Timer5
    VcOutTIM5     = 12u,             ///< Timer5
    VcOutInvTIM6  = 13u,             ///< Timer6
    VcOutTIM6     = 14u,             ///< Timer6
    VcOutBrake    = 15u,             ///< Advanced Timer
    VcOutDisable  = 16u,             ///< 
}en_vc_output_config_t;

/**
 ******************************************************************************
 ** \brief VC DIVVref
 *****************************************************************************/
typedef enum en_vc_div_vref
{
    VcDivVrefAvcc = 0u,              ///< AVCC
    VcDivVrefAdc  = 1u,               ///< ADC_CR0 SREF
}en_vc_div_vref_t;

/**
 ******************************************************************************
 ** \brief VC
 *****************************************************************************/
typedef struct stc_vc_dac_config
{
    boolean_t           bDivEn;       ///< / 6-bit VCC divider
    uint8_t             u8DivVal;     ///< 6-bit VCC divider
    en_vc_div_vref_t    enDivVref;    ///< 6-bit VCC divider
}stc_vc_dac_config_t;

/**
 ******************************************************************************
 ** \brief VC
 *****************************************************************************/
typedef struct stc_vc_channel_config
{
    en_vc_channel_t         enVcChannel;        ///< VC
    en_vc_cmp_delay_t       enVcCmpDly;         ///< VC
    en_vc_bias_current_t    enVcBiasCurrent;    ///< VC
    en_vc_resp_filter_t     enVcFilterTime;     ///< 
    en_vc_input_p_src_t     enVcInPin_P;        ///< P
    en_vc_input_n_src_t     enVcInPin_N;        ///< N
    en_vc_output_config_t   enVcOutConfig;      ///< 
    en_vc_irq_sel_t         enVcIrqSel;         ///< 
    func_ptr_t              pfnAnalogCmpCb;     ///< 
}stc_vc_channel_config_t;

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

//VC init/deinit

en_result_t Vc_ChannelInit(en_vc_channel_t enChannel,
                            stc_vc_channel_config_t *pstcChannelConfig);
en_result_t Vc_ChannelDeInit(en_vc_channel_t enChannel);
en_result_t Vc_DACInit(stc_vc_dac_config_t *pstcDacConfig);
//VC function enable/disable
en_result_t Vc_EnableChannel(en_vc_channel_t enChannel);
en_result_t Vc_DisableChannel(en_vc_channel_t enChannel);

//VC filter enable/disable
en_result_t Vc_EnableFilter(en_vc_channel_t enChannel);
en_result_t Vc_DisableFilter(en_vc_channel_t enChannel);

//get stat
boolean_t Vc_GetStat(en_vc_channel_t enChannel, en_vc_stat_t enStat);
//clear stat
void Vc_ClearIrq(en_vc_channel_t enChannel);

//irq enable/disable
en_result_t Vc_EnableIrq(en_vc_channel_t enChannel);
en_result_t Vc_DisableIrq(en_vc_channel_t enChannel);
en_result_t Vc_ConfigIrq(en_vc_channel_t enChannel, en_vc_irq_sel_t enSel);
//@} // VcGroup

#ifdef __cplusplus
}
#endif

#endif /* __VC_H__ */
/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

