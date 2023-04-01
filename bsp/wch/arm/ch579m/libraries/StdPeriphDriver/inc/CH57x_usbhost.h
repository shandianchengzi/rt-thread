


#ifndef __CH57x_USBHOST_H__
#define __CH57x_USBHOST_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"

/***************************************** UUUSBhub */
#define FOR_ROOT_UDISK_ONLY
/***************************************** U,  */
#define DISK_BASE_BUF_LEN       512         /* 512,20484096U,0.HpDISK_BASE_BUF */



// 
#define ERR_SUCCESS         0x00    // 
#define ERR_USB_CONNECT     0x15    /* USB, */
#define ERR_USB_DISCON      0x16    /* USB, */
#define ERR_USB_BUF_OVER    0x17    /* USB */
#define ERR_USB_DISK_ERR    0x1F    /* USB,USB, */
#define ERR_USB_TRANSFER    0x20    /* NAK/STALL0x20~0x2F */
#define ERR_USB_UNSUPPORT   0xFB    /*USB*/
#define ERR_USB_UNKNOWN     0xFE    /**/
#define ERR_AOA_PROTOCOL    0x41    /* */

/*USB,1*/
#define ROOT_DEV_DISCONNECT  0
#define ROOT_DEV_CONNECTED   1
#define ROOT_DEV_FAILED      2
#define ROOT_DEV_SUCCESS     3
#define DEV_TYPE_KEYBOARD   ( USB_DEV_CLASS_HID | 0x20 )
#define DEV_TYPE_MOUSE      ( USB_DEV_CLASS_HID | 0x30 )
#define DEF_AOA_DEVICE       0xF0
#define DEV_TYPE_UNKNOW      0xFF


/*
: USB(USB_DEVICE_ADDR)
  
0x02    Root-HUBUSBHUB
0x1x    Root-HUBHUBxUSB,x1~n
*/
#define HUB_MAX_PORTS           4
#define WAIT_USB_TOUT_200US     800   // USB


typedef struct
{
    UINT8   DeviceStatus;              // ,0-,1-,2-,3-
    UINT8   DeviceAddress;             // USB
    UINT8   DeviceSpeed;               // 0,0
    UINT8   DeviceType;                // 
    UINT16  DeviceVID;
    UINT16  DevicePID;
    UINT8   GpVar[4];                    // 
    UINT8   GpHUBPortNum;                // ,HUBHUB
} _RootHubDev;


extern _RootHubDev  ThisUsbDev;
extern UINT8  UsbDevEndp0Size;              // USB0 */
extern UINT8  FoundNewDev;

extern PUINT8  pHOST_RX_RAM_Addr;
extern PUINT8  pHOST_TX_RAM_Addr;
#define pSetupReq   ((PUSB_SETUP_REQ)pHOST_TX_RAM_Addr)
extern UINT8  Com_Buffer[];

/* USB */
extern const UINT8  SetupGetDevDescr[];    //**/
extern const UINT8  SetupGetCfgDescr[];    //**/
extern const UINT8  SetupSetUsbAddr[];     //*USB*/
extern const UINT8  SetupSetUsbConfig[];   //*USB*/
extern const UINT8  SetupSetUsbInterface[];//*USB*/
extern const UINT8  SetupClrEndpStall[];   //*STALL*/


void  DisableRootHubPort(void)  ;                   // ROOT-HUB,,
UINT8   AnalyzeRootHub( void ) ;         // ROOT-HUB,ROOT-HUB
// ERR_SUCCESS,ERR_USB_CONNECT,ERR_USB_DISCON
void    SetHostUsbAddr( UINT8 addr );                 // USBUSB
void    SetUsbSpeed( UINT8 FullSpeed );               // USB
void    ResetRootHubPort(void);                          // ,,,
UINT8   EnableRootHubPort(void);                          // ROOT-HUB,bUH_PORT_EN1,
void    SelectHubPort( UINT8 HubPortIndex );// HubPortIndex=0ROOT-HUB,ROOT-HUBHUB
UINT8   WaitUSB_Interrupt( void );                    // USB
// ,/PID,,20uSNAK(0,0xFFFF),0,/
UINT8   USBHostTransact( UINT8 endp_pid, UINT8 tog, UINT32 timeout );  // endp_pid: 4token_pid, 4
UINT8   HostCtrlTransfer( PUINT8 DataBuf, PUINT8 RetLen );  // ,8pSetupReq,DataBuf
// ,DataBuf,ReqLen


void CopySetupReqPkg( PCCHAR pReqPkt );            // 
UINT8 CtrlGetDeviceDescr( void );                    // , pHOST_TX_RAM_Addr 
UINT8 CtrlGetConfigDescr( void );                    // , pHOST_TX_RAM_Addr 
UINT8 CtrlSetUsbAddress( UINT8 addr );                         // USB
UINT8 CtrlSetUsbConfig( UINT8 cfg );                           // USB
UINT8 CtrlClearEndpStall( UINT8 endp ) ;                       // STALL
UINT8 CtrlSetUsbIntercace( UINT8 cfg );                        // USB


void    USB_HostInit( void );                                  // USB



/*************************************************************/


UINT8 InitRootDevice( void );

UINT8   CtrlGetHIDDeviceReport( UINT8 infc );          // HIDSET_IDLEGET_REPORT
UINT8   CtrlGetHubDescr( void );                       // HUB,TxBuffer
UINT8   HubGetPortStatus( UINT8 HubPortIndex );        // HUB,TxBuffer
UINT8   HubSetPortFeature( UINT8 HubPortIndex, UINT8 FeatureSelt );  // HUB
UINT8   HubClearPortFeature( UINT8 HubPortIndex, UINT8 FeatureSelt );  // HUB



#ifdef __cplusplus
}
#endif

#endif  // __CH57x_USBHOST_H__

