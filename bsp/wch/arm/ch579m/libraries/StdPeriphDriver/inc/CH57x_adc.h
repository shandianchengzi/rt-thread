


#ifndef __CH57x_ADC_H__
#define __CH57x_ADC_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"


#define ROM_TMP_85C_ADDR    0x40634
#define ROM_TMP_25C_ADDR    0x40638


/**
  * @brief  adc single channel define
  */
typedef enum
{
    CH_EXTIN_0 = 0,         // ADC  0
    CH_EXTIN_1,             // ADC  1
    CH_EXTIN_2,             // ADC  2
    CH_EXTIN_3,             // ADC  3
    CH_EXTIN_4,             // ADC  4
    CH_EXTIN_5,             // ADC  5
    CH_EXTIN_6,             // ADC  6
    CH_EXTIN_7,             // ADC  7
    CH_EXTIN_8,             // ADC  8
    CH_EXTIN_9,             // ADC  9
    CH_EXTIN_10,            // ADC  10
    CH_EXTIN_11,            // ADC  11
    CH_EXTIN_12,            // ADC  12
    CH_EXTIN_13,            // ADC  13

    CH_INTE_VBAT,           // ADC 
    CH_INTE_VTEMP,          // ADC 

}ADC_SingleChannelTypeDef;

/**
  * @brief  adc differential channel define
  */
typedef enum
{
    CH_DIFF_0_2 = 0,            // ADC  #0-#2
    CH_DIFF_1_3,                // ADC  #1-#3

}ADC_DiffChannelTypeDef;

/**
  * @brief  adc sampling clock
  */
typedef enum
{
    SampleFreq_3_2 = 0,         // 3.2M 
    SampleFreq_2_67,            // 2.67M 
    SampleFreq_5_33,            // 5.33M 
    SampleFreq_4,               // 4M 
}ADC_SampClkTypeDef;


/**
  * @brief  adc signal PGA
  */
typedef enum
{
    ADC_PGA_1_4 = 0,            // -12dB, 1/4
    ADC_PGA_1_2,                // -6dB, 1/2
    ADC_PGA_0,                  // 0dB, 1
    ADC_PGA_2,                  // 6dB, 2
}ADC_SignalPGATypeDef;


// refer to ADC_SingleChannelTypeDef
#define     ADC_ChannelCfg( d )     (R8_ADC_CHANNEL = d)                                                /*  ADC  */
// refer to ADC_SampClkTypeDef
#define     ADC_SampClkCfg( d )     (R8_ADC_CFG=R8_ADC_CFG&(~RB_ADC_CLK_DIV)|(d<<6))                    /*  ADC  */
// refer to ADC_SignalPGATypeDef
#define     ADC_PGACfg( d )         (R8_ADC_CFG=R8_ADC_CFG&(~RB_ADC_PGA_GAIN)|(d<<4))               /*  ADC  */
#define     ADC_TempCalibCfg( d )   (R8_TEM_SENSOR=R8_TEM_SENSOR&(~RB_TEM_SEN_CALIB)|d)             /*  */

void ADC_ExtSingleChSampInit( ADC_SampClkTypeDef sp, ADC_SignalPGATypeDef ga );                     /*  */
void ADC_ExtDiffChSampInit( ADC_SampClkTypeDef sp, ADC_SignalPGATypeDef ga );                       /*  */
void TouchKey_ChSampInit( void );                                                                   /*  */
void ADC_InterTSSampInit( void );                                                                   /*  */
void ADC_InterBATSampInit( void );                                                                  /*  */

UINT16 ADC_ExcutSingleConver( void );                                                               /* ADC */
signed short ADC_DataCalib_Rough( void );
void ADC_DataCalib_Fine( PUINT16 dat, ADC_SignalPGATypeDef ga );
UINT16 TouchKey_ExcutSingleConver( UINT8 d );                                                       /* TouchKey */
int ADC_GetCurrentTS( UINT16 ts_v );                                                              /*  */

#define ADC_ReadConverValue()       (R16_ADC_DATA)                                                  /*  */
#define ADC_StartUp()               (R8_ADC_CONVERT = RB_ADC_START)                                 /* ADC */
#define ADC_GetITStatus()           ( R8_ADC_INT_FLAG & RB_ADC_IF_EOC )                             /* ADC */
#define ADC_ClearITFlag()           (R8_ADC_CONVERT = 0)                                            /* ADC */

#define TouchKey_GetITStatus()      ( R8_ADC_INT_FLAG & RB_ADC_IF_EOC )                             /* TouchKey */
#define TouchKey_ClearITFlag()      (R8_TKEY_CTRL |= RB_TKEY_PWR_ON)                                /* TouchKey */


#ifdef __cplusplus
}
#endif

#endif  // __CH57x_ADC_H__

