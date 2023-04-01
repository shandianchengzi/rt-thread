


#ifndef __CH57x_FLASH_H__
#define __CH57x_FLASH_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"

#define ROM_UUID_ADDR        0x40608         // chip UID address ( ID-48bit + CKS-16bit )
#define ROM_MAC_ADDR         0x40608         // NET MAC address 48bit

// ID
void GetUniqueID(PUINT8 buf);                                           /* ID6B-ID 2B-CKS */

// MAC
void GetMACAddress(PUINT8 buf);                                         /* MAC6B-MAC */


UINT8 FlashBlockErase(UINT32 addr);
UINT8 FlashWriteDW(UINT32 addr, UINT32 dat);
UINT8 FlashWriteBuf(UINT32 addr, PUINT32 pdat, UINT16 len);



#ifdef __cplusplus
}
#endif

#endif  // __CH57x_FLASH_H__

