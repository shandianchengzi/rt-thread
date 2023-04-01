/*
********************************************************************************
*                                USB Hid Driver
*
*                (c) Copyright 2006-2010, All winners Co,Ld.
*                        All Right Reserved
*
* FileName      :  Hid_i.h
*
* Author        :  Javen
*
* Date          :  2010/06/02
*
* Description   :  Hid DriverUSB
*
* Others        :  NULL
*
* History:
*       <time>          <author>     <version >     <desc>
*      2010.06.02       Javen           1.0         build this file
*
********************************************************************************
*/
#ifndef  __HID_I_H__
#define  __HID_I_H__
#include <hal_osal.h>

//---------------------------------------------------------
//  
//---------------------------------------------------------
struct _HidRequest;
struct _HidDev;
struct _usbHidReport;

//----------------------------------------------------------------------
//
//
//----------------------------------------------------------------------
/* input, output, feature */
#define USB_HID_MAX_FIELDS      64
typedef struct _usbHidField{
    /* Field */
    unsigned int physical;              /* physical usage for this field                    */
    unsigned int logical;               /* logical usage for this field                     */
    unsigned int application;           /* application usage for this field                 */
    usbHidUsage_t *usage;       /* usage table for this function                    */
    unsigned int maxusage;              /* maximum usage index                              */
    unsigned int flags;             /* main-item flags (i.e. volatile,array,constant)   */
    unsigned int report_offset;     /* bit offset in the report                         */
    unsigned int report_size;           /* size of this field in the report                 */
    unsigned int report_count;          /* number of this field in the report               */
    unsigned int report_type;           /* (input,output,feature)                           */
    unsigned int *value;                /* last known value(s)                              */
    int logical_minimum;        /*                                         */
    int logical_maximum;        /*                                         */
    int physical_minimum;       /*                                         */
    int physical_maximum;       /*                                         */
    int unit_exponent;      /*                                          */
    unsigned int unit;                  /*                                            */

    /* Field */
    unsigned int Index;             /* ndex into report->field[]                        */
    struct _usbHidReport *HidReport; /* field  HID report                    */
}usbHidField_t;

#define  USB_HID_REPORT_TYPES       3   /*         */
#define  USB_HID_REPORT_MAX_NUM     256 /*   */

/* input, output, feature3 */
typedef struct _usbHidReport{
    unsigned int Id;                                    /* id of this report            */
    unsigned int Type;                                  /* report type,                 */

    unsigned int Maxfield;                              /* maximum valid field index    */
    usbHidField_t *Field[USB_HID_MAX_FIELDS];   /* fields of the report         */

    unsigned int Size;                                  /* size of the report (bits)    */
}usbHidReport_t;

/*  */
typedef struct _usbHidReportEnum{
    unsigned int numbered;   /* reprot */

    unsigned int ReportNum;  /* Report */
    usbHidReport_t *Report[USB_HID_REPORT_MAX_NUM];
}usbHidReportEnum_t;

#define  USB_HID_GLOBAL_STACK_SIZE          4
#define  USB_HID_COLLECTION_STACK_SIZE      4
typedef struct _usbHidParser {
    usbHidGlobalItems_t global;
    usbHidGlobalItems_t global_stack[USB_HID_GLOBAL_STACK_SIZE];
    unsigned int  global_stack_ptr;

    usbHidLocalItems_t local;

    unsigned int collection_stack[USB_HID_COLLECTION_STACK_SIZE];
    unsigned int collection_stack_ptr;

    struct _HidDev *HidDev;
}usbHidParser_t;


/* hidhid DATA */
typedef struct _usbHidEvnetExcursion{
    unsigned int BitOffset;
    unsigned int BitCount;
}usbHidEvnetExcursion_t;

//---------------------------------------------------------
//
//---------------------------------------------------------

/* Hid device state */
typedef enum _HidDev_state{
    HID_DEV_OFFLINE= 0,         /* HidDev       */
    HID_DEV_ONLINE,             /* HidDev       */
    HID_DEV_DIED,               /* HidDev        */
    HID_DEV_RESET               /* HidDevreset   */
}HidDev_State_t;

/* USB Hid device type */
//#define  USB_HID_DEVICE_TYPE_UNKOWN       0x00    /*  */
//#define  USB_HID_DEVICE_TYPE_KEYBOARD 0x01    /*    */
//#define  USB_HID_DEVICE_TYPE_MOUSE        0x02    /*    */

typedef int (* Hid_SoftReset)(struct _HidDev *HidDev);
typedef int (* Hid_ResetRecovery)(struct _HidDev *HidDev);
typedef int (* Hid_Transport)(struct _HidDev *HidDev, struct _HidRequest *HidReq);
typedef int (* Hid_StopTransport)(struct _HidDev *HidDev);

typedef int (* HidClientProbe)(struct _HidDev *);
typedef int (* HidClientRemove)(struct _HidDev *);

/* USB */
typedef struct _HidDev{
    struct usb_host_virt_dev *pusb_dev;     /* mscDev Public USB Device  */
    struct usb_interface     *pusb_intf;    /* Public usb interface             */

    /* device information */
    unsigned char InterfaceNo;                      /*                           */
    unsigned char SubClass;                             /*                            */
    unsigned char Protocol;                             /*                          */
    unsigned int DevType;                           /*                          */
    unsigned int DevNo;                             /*  hid            */

    /* device manager */
    HidDev_State_t State;                   /* Dev             */

    unsigned char *ReportDesc;                      /* Hidreport       */
    unsigned int ReportSize;                        /* report                 */

    usbHidCollectionItems_t *collection;        /* List of HID collections              */
    unsigned collection_size;                   /* Number of allocated hid_collections  */
    unsigned maxcollection;                     /* Number of parsed collections         */
    unsigned maxapplication;                    /* Number of applications               */
    usbHidReportEnum_t HidReportEnum[USB_HID_REPORT_TYPES];     /*       */

    /* transport */
    unsigned int CtrlIn;                            /* ctrl in  pipe                    */
    unsigned int CtrlOut;                           /* ctrl out pipe                    */
    unsigned int IntIn;                         /* interrupt in pipe                */
    unsigned char  EpInterval;                      /* int       */
    unsigned int OnceTransferLength;                /* ep             */

    unsigned int busy;                              /*            */
    struct urb *CurrentUrb;                 /* USB requests                     */
    hal_sem_t UrbWait;          /* wait for Urb done                */
    struct usb_ctrlrequest *CtrlReq;        /* control requests                 */

    /* USB */
    Hid_SoftReset     SoftReset;            /*  hid device  */
    Hid_ResetRecovery ResetRecovery;        /* reset device                     */
    Hid_Transport     Transport;            /*                            */
    Hid_StopTransport StopTransport;        /*                          */

    /* Hid */
    HidClientProbe  ClientProbe;
    HidClientRemove ClientRemove;

    void *Extern;                           /* hid, mouse, keyboard */
}HidDev_t;

typedef void (* HidClientDone)(struct _HidRequest *);

/* Hid  */
typedef struct _HidRequest{
    HidDev_t *HidDev;

    void *buffer;                           /* Data buffer                  */
    unsigned int DataTransferLength;                /* Size of data buffer          */
    unsigned int ActualLength;                      /* actual transport length      */

    HidClientDone Done;
    unsigned int Result;                            /*                      */

    void *Extern;                           /* hid, mouse, keyboard */
}HidRequest_t;

//-----------------------------------------------------
//  Hid 
//-----------------------------------------------------
#define  USB_HID_TRANSPORT_SUCCESS              0x00  /*            */

#define  USB_HID_TRANSPORT_DEVICE_DISCONNECT    0x01  /*            */
#define  USB_HID_TRANSPORT_DEVICE_RESET         0x02  /*            */
#define  USB_HID_TRANSPORT_PIPE_HALT            0x03  /*          */
#define  USB_HID_TRANSPORT_CANCEL_CMD           0x04  /*    */

#define  USB_HID_TRANSPORT_UNKOWN_ERR           0xFF  /*            */


//-----------------------------------------------------
//
//-----------------------------------------------------
int HidSentRequest(HidRequest_t *HidReq);
int HidGetInputReport(HidDev_t *HidDev, unsigned int Usagepage, unsigned int Usage, unsigned int *BitOffset, unsigned int *BitCount);


#endif   //__HID_I_H__

