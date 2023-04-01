/******************************************************************************
*
* NOTE:
******************************************************************************/

#ifndef _NVxx_CONFIG_H_
#define _NVxx_CONFIG_H_


#include <stdint.h>

#define CPU_NV32
#define TEST


//#define TRIM_IRC                    /*!< TRIMIRCTRIM37.5K--48M */
//#define SPI0_PINREMAP               /*!< SPI0 */
//#define ENABLE_WDOG               /*!<  */
//#define DISABLE_NMI               /*!< NMI */

/*!  */      
//#define PRINT_SYS_LOG           

#if     !defined(BOOT_LOADER)
#endif

//#define OUTPUT_BUSCLK             /*!< PH2 */
#define ICS_TRIM_VALUE  0x2c   


    /*! 
     */
   //#define USE_FEE                         /*!< FEE */
   //#define USE_FEE_OSC                     /*!< OSC */
     #define USE_FEI                         /*!< IRC */
  // #define USE_FBELP	
   //#define USE_FBE_OSC

   /*! . */
   //#define EXT_CLK_FREQ_KHZ	32          /* in KHz */
   //#define EXT_CLK_FREQ_KHZ	4000        /* in KHz */
   //#define EXT_CLK_FREQ_KHZ	4000        /* in KHz */
   //#define EXT_CLK_FREQ_KHZ	1000        /* in KHz */
     #define EXT_CLK_FREQ_KHZ	10000       /* in KHz */
    /*! UART */
    #define TERM_PORT   UART1               /*!< UART1UART1 */


    /*  */
    #if	defined(USE_FEI)
        #define  BUS_CLK_HZ		40000000L

    #elif  (EXT_CLK_FREQ_KHZ == 10000)
        #define  BUS_CLK_HZ		50000000L
    #elif  (EXT_CLK_FREQ_KHZ == 12000)
        #define  BUS_CLK_HZ   30000000L
    #elif  (EXT_CLK_FREQ_KHZ == 8000)
        #define  BUS_CLK_HZ		24000000L
    #elif  (EXT_CLK_FREQ_KHZ == 4000)
        #define  BUS_CLK_HZ		40000000L
    #elif  (EXT_CLK_FREQ_KHZ == 32)
        #define  BUS_CLK_HZ		16777216L
    #else   
        #define  BUS_CLK_HZ		60000000L
    #endif

    /*! define UART baud rate */
    #define UART_PRINT_BITRATE              115200      /*! UART */


#endif /* NVxx_CONFIG_H_ */
