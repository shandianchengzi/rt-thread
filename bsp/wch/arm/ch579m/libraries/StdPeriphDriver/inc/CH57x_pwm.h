


#ifndef __CH57x_PWM_H__
#define __CH57x_PWM_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"

/**
  * @brief  channel of PWM define
  */

#define CH_PWM4     0x01                // PWM4 
#define CH_PWM5     0x02                // PWM5 
#define CH_PWM6     0x04                // PWM6 
#define CH_PWM7     0x08                // PWM7 
#define CH_PWM8     0x10                // PWM8 
#define CH_PWM9     0x20                // PWM9 
#define CH_PWM10    0x40                // PWM10 
#define CH_PWM11    0x80                // PWM11 



/**
  * @brief  channel of PWM define
  */
typedef enum
{
    High_Level = 0,                     // 
    Low_Level,                          // 
}PWMX_PolarTypeDef;


/**
  * @brief  Configuration PWM4_11 Cycle size
  */
typedef enum
{
    PWMX_Cycle_256 = 0,                 // 256 PWMX
    PWMX_Cycle_255,                     // 255 PWMX
    PWMX_Cycle_128,                     // 128 PWMX
    PWMX_Cycle_127,                     // 127 PWMX
    PWMX_Cycle_64,                      // 64 PWMX
    PWMX_Cycle_63,                      // 63 PWMX
    PWMX_Cycle_32,                      // 32 PWMX
    PWMX_Cycle_31,                      // 31 PWMX
}PWMX_CycleTypeDef;


#define PWMX_CLKCfg( d )            (R8_PWM_CLOCK_DIV=d)                /* PWM4-PWM11 = d*Tsys */
void PWMX_CycleCfg( PWMX_CycleTypeDef cyc );                            /* PWM4-PWM11  */

#define PWM4_ActDataWidth( d )      (R8_PWM4_DATA = d)                  /* PWM4  */
#define PWM5_ActDataWidth( d )      (R8_PWM5_DATA = d)                  /* PWM5  */
#define PWM6_ActDataWidth( d )      (R8_PWM6_DATA = d)                  /* PWM6  */
#define PWM7_ActDataWidth( d )      (R8_PWM7_DATA = d)                  /* PWM7  */
#define PWM8_ActDataWidth( d )      (R8_PWM8_DATA = d)                  /* PWM8  */
#define PWM9_ActDataWidth( d )      (R8_PWM9_DATA = d)                  /* PWM9  */
#define PWM10_ActDataWidth( d )     (R8_PWM10_DATA = d)                 /* PWM10  */
#define PWM11_ActDataWidth( d )     (R8_PWM11_DATA = d)                 /* PWM11  */

//  = /
void PWMX_ACTOUT( UINT8 ch, UINT8 da, PWMX_PolarTypeDef pr, UINT8 s);   /* PWM4-PWM11 */
void PWMX_AlterOutCfg( UINT8 ch, UINT8 s);          /* PWM  */





#ifdef __cplusplus
}
#endif

#endif  // __CH57x_PWM_H__

