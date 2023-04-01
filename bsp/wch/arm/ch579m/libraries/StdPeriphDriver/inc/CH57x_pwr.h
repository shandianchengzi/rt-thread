


#ifndef __CH57x_PWR_H__
#define __CH57x_PWR_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"

/**
  * @brief  Peripher CLK control bit define
  */
#define BIT_SLP_CLK_TMR0                 (0x00000001)  /*!< TMR0 peripher clk bit */
#define BIT_SLP_CLK_TMR1                 (0x00000002)  /*!< TMR1 peripher clk bit */
#define BIT_SLP_CLK_TMR2                 (0x00000004)  /*!< TMR2 peripher clk bit */
#define BIT_SLP_CLK_TMR3                 (0x00000008)  /*!< TMR3 peripher clk bit */
#define BIT_SLP_CLK_UART0                (0x00000010)  /*!< UART0 peripher clk bit */
#define BIT_SLP_CLK_UART1                (0x00000020)  /*!< UART1 peripher clk bit */
#define BIT_SLP_CLK_UART2                (0x00000040)  /*!< UART2 peripher clk bit */
#define BIT_SLP_CLK_UART3                (0x00000080)  /*!< UART3 peripher clk bit */
#define BIT_SLP_CLK_SPI0                 (0x00000100)  /*!< SPI0 peripher clk bit */
#define BIT_SLP_CLK_SPI1                 (0x00000200)  /*!< SPI1 peripher clk bit */
#define BIT_SLP_CLK_PWMX                 (0x00000400)  /*!< PWMX peripher clk bit */
#define BIT_SLP_CLK_LCD                  (0x00000800)  /*!< LCD peripher clk bit */
#define BIT_SLP_CLK_USB                  (0x00001000)  /*!< USB peripher clk bit */
#define BIT_SLP_CLK_ETH                  (0x00002000)  /*!< ETH peripher clk bit */
#define BIT_SLP_CLK_LED                  (0x00004000)  /*!< LED peripher clk bit */
#define BIT_SLP_CLK_BLE                  (0x00008000)  /*!< BLE peripher clk bit */
#define BIT_SLP_CLK_RAMX                 (0x10000000)  /*!< RAM14K peripher clk bit */
#define BIT_SLP_CLK_RAM2K                (0x20000000)  /*!< RAM2K peripher clk bit */
#define BIT_SLP_CLK_ALL                  (0x3000FFFF)  /*!< All peripher clk bit */

/**
  * @brief  unit of controllable power supply
  */
#define UNIT_SYS_LSE                RB_CLK_XT32K_PON        // 32K 
#define UNIT_SYS_LSI                RB_CLK_INT32K_PON       // 32K 
#define UNIT_SYS_HSE                RB_CLK_XT32M_PON        // 32M 
#define UNIT_SYS_HSI                RB_CLK_INT32M_PON       // 32M 
#define UNIT_SYS_PLL                RB_CLK_PLL_PON          // PLL 
#define UNIT_ETH_PHY                (0x80)                  //  ETH-PHY


void PWR_DCDCCfg( UINT8 s );                                  /* DC/DC */
void PWR_UnitModCfg( UINT8 s, UINT8 unit );                   /*  */
void PWR_PeriphClkCfg( UINT8 s, UINT16 perph );               /*  */

void PowerMonitor( UINT8 s );                                 /*  */

void PWR_PeriphWakeUpCfg( UINT8 s, UINT16 perph );              /*  */
void LowPower_Idle( void );                                 /* -IDLE */
void LowPower_Halt_1( void );                               /* -Halt_1 */
void LowPower_Halt_2( void );                               /* -Halt_2 */
void LowPower_Sleep( UINT8 rm );                            /* -Sleep */
void LowPower_Shutdown( UINT8 rm );                         /* -Shutdown */
void EnterCodeUpgrade( void );                              /* BOOT */



#ifdef __cplusplus
}
#endif

#endif  // __CH57x_PWR_H__

