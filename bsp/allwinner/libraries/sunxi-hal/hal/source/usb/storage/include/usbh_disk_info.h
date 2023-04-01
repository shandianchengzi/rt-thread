/*
********************************************************************************************************************
*                                              usb_host
*
*                              (c) Copyright 2007-2009, holi.China
*                                       All Rights Reserved
*
* File Name     : usbh_disk_info.h
*
* Author        : holi
*
* Version       : 1.0
*
* Date          : 2009.08.18
*
* Description   :
*
* History       :
*
********************************************************************************************************************
*/
#ifndef  __USBH_DISK_INFO_H__
#define  __USBH_DISK_INFO_H__
#include "mod_usbhost.h"
#include "usb_list.h"

typedef struct _usbh_disk_device_info
{
    char Classname[USB_HOST_MAX_STRING_LEN];    /*        */
    char DeviceName[USB_HOST_MAX_STRING_LEN];   /*    */

    usbhDeivceInfo_t DeivceInfo;                /*      */
} usbh_disk_device_info_t;

/* usbh_disk_info */
typedef struct tag_usbh_disk_info
{
    unsigned int  cnt;            //

    void *reghandle;    //

    //  usbh_disk_device_info_t device_info[USBH_DISK_INFO_MAX_DEVICE_NUMBER];
    struct usb_list_head device_list;
} usbh_disk_info_t;


//-----------------------------------------------------------
//
//-----------------------------------------------------------

void set_usbh_disk_status(unsigned int status);
unsigned int get_usbh_disk_status(void);

void usbh_disk_SaveDeviceInfo(usbh_disk_device_info_t *device_info);
void usbh_disk_FreeDeviceInfo(usbh_disk_device_info_t *device_info);

int usbh_disk_info_reg(void);
int usbh_disk_info_unreg(void);


#endif   //__USBH_DISK_INFO_H__

