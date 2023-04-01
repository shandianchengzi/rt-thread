


#ifndef __CH57x_USBDEV_H__
#define __CH57x_USBDEV_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"

/* USB99 */
extern PUINT8  pEP0_RAM_Addr;       //ep0(64)+ep4_out(64)+ep4_in(64)
extern PUINT8  pEP1_RAM_Addr;       //ep1_out(64)+ep1_in(64)
extern PUINT8  pEP2_RAM_Addr;       //ep2_out(64)+ep2_in(64)
extern PUINT8  pEP3_RAM_Addr;       //ep3_out(64)+ep3_in(64)

#define pSetupReqPak        ((PUSB_SETUP_REQ)pEP0_RAM_Addr)
#define pEP0_DataBuf        (pEP0_RAM_Addr)
#define pEP1_OUT_DataBuf    (pEP1_RAM_Addr)
#define pEP1_IN_DataBuf     (pEP1_RAM_Addr+64)
#define pEP2_OUT_DataBuf    (pEP2_RAM_Addr)
#define pEP2_IN_DataBuf     (pEP2_RAM_Addr+64)
#define pEP3_OUT_DataBuf    (pEP3_RAM_Addr)
#define pEP3_IN_DataBuf     (pEP3_RAM_Addr+64)
#define pEP4_OUT_DataBuf    (pEP0_RAM_Addr+64)
#define pEP4_IN_DataBuf     (pEP0_RAM_Addr+128)



void USB_DeviceInit( void );            /* USB48 */
void USB_DevTransProcess( void );       /* USB */

void DevEP1_OUT_Deal( UINT8 l );        /* 1 */
void DevEP2_OUT_Deal( UINT8 l );        /* 2 */
void DevEP3_OUT_Deal( UINT8 l );        /* 3 */
void DevEP4_OUT_Deal( UINT8 l );        /* 4 */

void DevEP1_IN_Deal( UINT8 l );     /* 1 */
void DevEP2_IN_Deal( UINT8 l );     /* 2 */
void DevEP3_IN_Deal( UINT8 l );     /* 3 */
void DevEP4_IN_Deal( UINT8 l );     /* 4 */

// 0-  (!0)-
#define EP1_GetINSta()      (R8_UEP1_CTRL&UEP_T_RES_NAK)        /* 1 */
#define EP2_GetINSta()      (R8_UEP2_CTRL&UEP_T_RES_NAK)        /* 2 */
#define EP3_GetINSta()      (R8_UEP3_CTRL&UEP_T_RES_NAK)        /* 3 */
#define EP4_GetINSta()      (R8_UEP4_CTRL&UEP_T_RES_NAK)        /* 4 */



#ifdef __cplusplus
}
#endif

#endif  // __CH57x_USBDEV_H__

