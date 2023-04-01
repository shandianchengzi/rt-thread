


#ifndef __CH57x_SYS_H__
#define __CH57x_SYS_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"



/**
  * @brief  rtc interrupt event define
  */
typedef enum
{
    RST_STATUS_SW = 0,          // 
    RST_STATUS_RPOR,            // 
    RST_STATUS_WTR,             // 
    RST_STATUS_MR,              // 
    RST_STATUS_LRM0,            // -
    RST_STATUS_GPWSM,           // 
    RST_STATUS_LRM1,            //  -
    RST_STATUS_LRM2,            //  -

}SYS_ResetStaTypeDef;

/**
  * @brief  rtc interrupt event define
  */
typedef enum
{
    INFO_ROM_READ = 0,          // FlashROM  
    INFO_RESET_EN = 2,          // RST#
    INFO_BOOT_EN,               //  BootLoader 
    INFO_DEBUG_EN,              // 
    INFO_LOADER,                // Bootloader 
    STA_SAFEACC_ACT,            // RWA

}SYS_InfoStaTypeDef;


#define SYS_GetChipID()             R8_CHIP_ID                                  /* ID */
#define SYS_GetAccessID()           R8_SAFE_ACCESS_ID                           /* ID */
UINT8 SYS_GetInfoSta( SYS_InfoStaTypeDef i );                                   /*  */
// refer to SYS_ResetStaTypeDef
#define SYS_GetLastResetSta()       (R8_RESET_STATUS&RB_RESET_FLAG)             /*  */
void SYS_ResetExecute( void );                                                  /*  */
#define SYS_ResetKeepBuf( d )       (R8_GLOB_RESET_KEEP = d)                    /*    */

void SYS_DisableAllIrq( PUINT32 pirqv);                                         /*  */
void SYS_RecoverIrq( UINT32 irq_status );                                       /*  */
UINT32 SYS_GetSysTickCnt( void );                                               /* (SYSTICK) */

#define  WWDG_SetCounter( c )       (R8_WDOG_COUNT = c)                         /*  */
void  WWDG_ITCfg( UINT8 s );                            /*  */
void  WWDG_ResetCfg( UINT8 s );                         /*  */
#define  WWDG_GetFlowFlag()         (R8_RST_WDOG_CTRL&RB_WDOG_INT_FLAG)         /*  */
void WWDG_ClearFlag(void);                                                      /*  */


void mDelayuS( UINT16 t );      /* uS  */
void mDelaymS( UINT16 t );      /* mS  */



#ifdef __cplusplus
}
#endif

#endif  // __CH57x_SYS_H__

