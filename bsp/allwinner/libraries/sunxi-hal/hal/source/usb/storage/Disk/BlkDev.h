/*
********************************************************************************************************************
*                                              usb host driver
*
*                              (c) Copyright 2007-2010, javen.China
*                                       All Rights Reserved
*
* File Name     : UsbBlkDev.h
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
#ifndef  __BLKDEV_H__
#define  __BLKDEV_H__

#include  "usbh_disk_info.h"

#define  USB_BLK_DEV_MAGIC              0x5a13d099
#define  USB_BULK_DISK_MAX_NAME_LEN     32

typedef struct __UsbBlkDev
{
    unsigned int   last_lun;               //1
    unsigned int   Magic;                  /*                  */
    __mscLun_t *Lun;                /* sdscsi device    */

    /* Disk information */
    unsigned int used;                     /*                      */
    __dev_devop_t DiskOp;           /*                      */

    /* Disk manager */
    void *DevParaHdle;      /* open                     */
    void *DevRegHdle;       /* reg                      */

    unsigned int DevNo;                                /* , host_id, target_id, lun    */
    unsigned char ClassName[USB_BULK_DISK_MAX_NAME_LEN]; /* , "disk"               */
    unsigned char DevName[USB_BULK_DISK_MAX_NAME_LEN];   /* , "SCSI_DISK_000"      */

    unsigned int is_RegDisk;               /* disk                           */
    unsigned int ErrCmdNr;                 /* test_unit_ready,           */

    void *Extern;                   /* , cd                               */

    usbh_disk_device_info_t device_info;
} __UsbBlkDev_t;

//------------------------------------------
//
//------------------------------------------
__UsbBlkDev_t *UsbBlkDevAllocInit(__mscLun_t *mscLun);
int UsbBlkDevFree(__UsbBlkDev_t *BlkDev);

void GetDiskInfo(__UsbBlkDev_t *BlkDev);
void ShutDown(__UsbBlkDev_t *BlkDev);

int UsbBlkDevReg(__UsbBlkDev_t *BlkDev, unsigned char *ClassName, unsigned int RegDisk);
int UsbBlkDevUnReg(__UsbBlkDev_t *BlkDev);


#endif   //__BLKDEV_H__


