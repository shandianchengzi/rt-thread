/*
********************************************************************************************************************
*                                              usb host driver
*
*                              (c) Copyright 2007-2010, javen.China
*                                       All Rights Reserved
*
* File Name     : usb_msc_i.h
*
* Author        : javen
*
* Version       : 2.0
*
* Date          : 2010.03.02
*
* Description   :
*
* History       :
*
********************************************************************************************************************
*/
#ifndef  __USB_MSC_I_H__
#define  __USB_MSC_I_H_

#include "usb_host_common.h"

/* Sub Classes */
#define USBMSC_SUBCLASS_RBC             0x01        /* Typically, flash devices */
#define USBMSC_SUBCLASS_8020            0x02        /* CD-ROM                   */
#define USBMSC_SUBCLASS_QIC             0x03        /* QIC-157 Tapes            */
#define USBMSC_SUBCLASS_UFI             0x04        /* Floppy                   */
#define USBMSC_SUBCLASS_8070            0x05        /* Removable media          */
#define USBMSC_SUBCLASS_SCSI            0x06        /* Transparent              */
#define USBMSC_SUBCLASS_ISD200          0x07        /* ISD200 ATA               */

#define USBMSC_SUBCLASS_MIN             USBMSC_SUBCLASS_RBC
#define USBMSC_SUBCLASS_MAX             USBMSC_SUBCLASS_ISD200

/* Protocol */
#define USBMSC_INTERFACE_PROTOCOL_CBIT  0x00    /* Control/Bulk/Interrupt       */
#define USBMSC_INTERFACE_PROTOCOL_CBT   0x01    /* Control/Bulk w/o interrupt   */
#define USBMSC_INTERFACE_PROTOCOL_BOT   0x50    /* bulk only                    */

/*  */
struct __mscDev;
struct __ScsiCmnd;
struct __mscLun;


#define  MSC_MAX_LUN            15      /* msc15Lun       */
#define  SCSI_INQUERY_LEN       36      /* inquery36  */
#define  SCSI_MAX_INQUERY_LEN   44      /* inquery36  */
#define  MSC_IOBUF_SIZE         64


/* mscDev */
typedef enum __mscDev_state
{
    MSC_DEV_OFFLINE = 0,        /* mscDev       */
    MSC_DEV_ONLINE,             /* mscDev       */
    MSC_DEV_DIED,               /* mscDev         */
    MSC_DEV_RESET               /* mscDevreset    */
} mscDev_state_t;

typedef int(* msc_ResetRecovery)(struct __mscDev *mscDev);
typedef int(* msc_Transport)(struct __mscDev *mscDev, struct __ScsiCmnd *ScsiCmnd);
typedef int(* msc_StopTransport)(struct __mscDev *mscDev);
typedef int(* msc_ProtocolHandler)(struct __mscDev *mscDev, struct __ScsiCmnd *ScsiCmnd);


/* mscDev, mscDev */
typedef struct __mscDev
{
    struct usb_host_virt_dev *pusb_dev; /* mscDev Public USB Device   */
    struct usb_interface    *pusb_intf; /* Public usb interface             */

    /* device information */
    unsigned char InterfaceNo;           /*                                */
    unsigned char *transport_name;       /*                        */
    unsigned char *Protocol_name;        /*                            */
    unsigned char SubClass;              /*                                  */
    unsigned char Protocol;              /*                              */
    unsigned char MaxLun;                /* Lun                          */
    unsigned int mscDevNo;             /* mscDev                         */
    unsigned int lun_num;              /* mscDevlun                */

    /* device manager */
    struct __mscLun *Lun[MSC_MAX_LUN];      /* Lun                */
    struct usb_list_head cmd_list;              /*                      */
    hal_sem_t scan_lock;         /* scan remove  */
    hal_sem_t DevLock;           /* mscDev*/
    hal_sem_t ThreadSemi;        /*                    */
    hal_sem_t notify_complete;   /* thread/          */
    mscDev_state_t state;                   /* mscDev     */

    struct rt_thread *MainThreadId;                     /* ID                     */
    struct rt_thread *MediaChangeId;                        /* media changeID       */

    unsigned int SuspendTime;                      /* Suspend        */

    /* command transport */
    unsigned int BulkIn;                           /* bulk in  pipe                */
    unsigned int BulkOut;                          /* bulk out pipe                */
    unsigned int CtrlIn;                           /* ctrl in  pipe                */
    unsigned int CtrlOut;                          /* ctrl out pipe                */
    unsigned int IntIn;                            /* interrupt in pipe            */
    unsigned char  EpInterval;                       /* int Bulk */

    unsigned int Tag;                              /* SCSI-II queued command tag   */
    unsigned int busy;                             /*          */
    struct __ScsiCmnd *ScsiCmnd;            /* current srb                  */
    struct urb *CurrentUrb;                 /* USB requests                 */
    hal_sem_t UrbWait;           /* wait for Urb done            */
    struct usb_ctrlrequest *CtrlReq;        /* control requests             */
    unsigned char *iobuf;                            /* mscDev, CBWCSW*/

    osal_timer_t TimerHdle;    /* timer                    */

    msc_ResetRecovery   ResetRecovery;      /* USB Controller reset         */
    msc_Transport       Transport;          /* msc        */
    msc_StopTransport   StopTransport;      /* msc                  */
    msc_ProtocolHandler ProtocolHandler;    /* msc                      */
} __mscDev_t;

typedef struct __disk_info_t
{
    unsigned int capacity;             /*          */
    unsigned int sector_size;          /*                        */
} disk_info_t;

typedef enum __mscLun_state
{
    MSC_LUN_DEL = 0,        /* mscDev     */
    MSC_LUN_ADD,            /* mscDev   */
    MSC_LUN_CANCEL          /* mscDev   */
} mscLun_state_t;


typedef int(* LunProbe)(struct __mscLun *);       /* lun  */
typedef int(* LunRemove)(struct __mscLun *);      /* lun  */
typedef void (* LunMediaChange)(struct __mscLun *); /* media change */


/* Lun, Lun */
typedef struct __mscLun
{
    __mscDev_t *mscDev;             /* LunmscDev                      */
    unsigned int LunNo;                    /* lun                            */

    /* device information */
    unsigned int DeviceType;               /*                            */
    unsigned int MediumType;               /* CD_ROM           */
    unsigned char  DiskSubClass;             /*                              */
    unsigned int ScsiLevel;                /* scsi                       */
    unsigned char Inquiry[SCSI_MAX_INQUERY_LEN]; /* inquire        */
    unsigned char *Vendor;                   /*                                */
    unsigned char *Product;                  /*                              */
    unsigned char *Revision;                 /*                            */

    /* Lun */
    disk_info_t disk_info;          /*                              */

    unsigned int WriteProtect: 1;          /*                        */
    unsigned int RemoveAble: 1;            /*                      */
    unsigned int Changed: 1;               /*                        */
    unsigned int MediaPresent: 1;          /*                      */
    unsigned int WCE: 1;                   /* cache                          */
    unsigned int RCD: 1;                   /* cache                          */
    unsigned int use_10_for_rw: 1;         /* first try 10-byte read / write       */
    unsigned int use_10_for_ms: 1;         /* first try 10-byte mode sense/select  */
    unsigned int skip_ms_page_8: 1;        /* do not use MODE SENSE page 0x08      */
    unsigned int skip_ms_page_3f: 1;       /* do not use MODE SENSE page 0x3f      */
    unsigned int use_192_bytes_for_3f: 1;  /* ask for 192 bytes from page 0x3f     */

    hal_sem_t Lock;      /*  */

    LunProbe        Probe;
    LunRemove       Remove;
    LunMediaChange  MediaChange;

    void *sdev_data;                /* top levelscsi disk   */
} __mscLun_t;

/*  */
typedef enum scsi_data_direction
{
    DATA_NONE = 0,          /* No Data                  */
    DATA_TO_DEVICE,         /* Data Out. host->device   */
    DATA_FROM_DEVICE,       /* Data in. device->host    */
} scsi_data_direction_t;

/* command block */
typedef struct __scsi_transport_cmd
{
    scsi_data_direction_t data_direction;   /* IN - DATA_IN or DATA_OUT         */
    unsigned int Tag;                      /* SCSI-II queued command tag               */
    unsigned int Timeout;                  /* IN - Timeout for this command Block      */
    unsigned int dwLun;                    /* IN - Logical Number for Logic Device.    */
    unsigned int CBLen;                    /* The length of command block              */
    void *CommandBlock;             /* IN - Pointer to the command block buffer.*/
} __scsi_transport_cmd_t;

typedef void (*LunDone)(struct __ScsiCmnd *);   /* mscDevLun cmd  */

/* ScsiCmnd, ScsiCmnd */
typedef struct __ScsiCmnd
{
    __mscLun_t *sc_lun;                     /*                        */
    //  struct list_head list;                  /* devicecmd_list     */

    __scsi_transport_cmd_t cmnd;            /* Command Block                */
    unsigned int retries;                          /* retry              */
    unsigned int allowed;                          /* retry              */

    void *buffer;                           /* Data buffer                  */
    unsigned int DataTransferLength;               /* Size of data buffer          */
    unsigned int ActualLength;                     /* actual transport length      */

    hal_sem_t complete;          /* Lun cmd          */
    LunDone Done;

    unsigned int Result;                           /*                */
} __ScsiCmnd_t;

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
#define  USB_STOR_TRANSPORT_GOOD        0   /*                  */
#define  USB_STOR_TRANSPORT_FAILED      1   /*    */
#define  USB_STOR_TRANSPORT_ERROR       2   /*                  */


//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
int mscDevQueueCmnd(__mscLun_t *mscLun, __ScsiCmnd_t *ScsiCmnd);
unsigned int mscDevOnline(__mscDev_t *mscDev);

#endif   //__USB_MSC_I_H__




