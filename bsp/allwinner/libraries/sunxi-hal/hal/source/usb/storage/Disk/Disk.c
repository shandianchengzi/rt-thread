/*
********************************************************************************************************************
*                                              usb host driver
*
*                              (c) Copyright 2007-2010, javen.China
*                                       All Rights Reserved
*
* File Name     : Disk.c
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
#include  "usb_os_platform.h"
#include  "error.h"
#include  "usb_msc_i.h"
#include  "Scsi2.h"
#include  "LunMgr_i.h"
#include  "BlkDev.h"

/*
*******************************************************************************
*                     DiskMediaChange
*
* Description:
*
*
* Parameters:
*
*
* Return value:
*    
*
* note:
*    
*
*******************************************************************************
*/
static void DiskMediaChange(__mscLun_t *mscLun)
{
    __UsbBlkDev_t *BlkDev = NULL;
    int ret = USB_STATUS_SUCCESS;

    if (mscLun == NULL)
    {
        hal_log_err("ERR: DiskMediaChange: mscLun == NULL");
        return;
    }

    BlkDev = (__UsbBlkDev_t *)mscLun->sdev_data;

    if (BlkDev == NULL)
    {
        hal_log_err("ERR: DiskMediaChange: BlkDev == NULL");
        return;
    }

    hal_sem_wait(mscLun->Lock);
    ret = ScsiTestUnitReady(mscLun);
    hal_sem_post(mscLun->Lock);

    switch (ret)
    {
        case USB_STATUS_SUCCESS:

            /* disk, disk */
            if (!BlkDev->is_RegDisk)
            {
                /*  */
                GetDiskInfo(BlkDev);

                /*  */
                if (mscLun->MediaPresent)
                {
                    UsbBlkDevUnReg(BlkDev);
                    UsbBlkDevReg(BlkDev, DEV_CLASS_DISK, 1);
                }
            }

            break;

        case USB_STATUS_MEDIA_NOT_PRESENT:
            if (BlkDev->is_RegDisk)
            {
                hal_log_err("ERR: DiskMediaChange: media is change");
                UsbBlkDevUnReg(BlkDev);
                UsbBlkDevReg(BlkDev, DEV_CLASS_USERDEF, 0);
            }

            break;

        case USB_STATUS_NOT_READY_TO_READY_TRANSITION:
            hal_log_info("[USB Disk]: media not ready to ready transition");
            break;

        default:
            BlkDev->ErrCmdNr++;

            if (BlkDev->ErrCmdNr > 3)
            {
                hal_log_err("ERR: too much error during test unit ready");
                BlkDev->ErrCmdNr = 0;

                if (BlkDev->is_RegDisk)
                {
                    UsbBlkDevUnReg(BlkDev);
                    UsbBlkDevReg(BlkDev, DEV_CLASS_USERDEF, 0);
                }
                else
                {
                    hal_log_err("ERR: device is not regist a disk device");
                }
            }
    }

    return;
}

/*
*******************************************************************************
*                     UsbBlkDevOpen
*
* Description:
*
*
* Parameters:
*
*
* Return value:
*    0  
*   !0  
*
* note:
*    
*
*******************************************************************************
*/
int DiskProbe(__mscLun_t *mscLun)
{
    __UsbBlkDev_t *BlkDev = NULL;
    unsigned int  cpu_sr;
    int ret = 0;

    if (mscLun == NULL)
    {
        hal_log_err("ERR: DiskProbe: input error");
        return -1;
    }

    /*  */
    BlkDev = UsbBlkDevAllocInit(mscLun);

    if (BlkDev == NULL)
    {
        hal_log_err("ERR: DiskProbe: alloc blkdev failed");
        return -1;
    }

    mscLun->sdev_data = (void *)BlkDev;

    if (mscLun->LunNo >= mscLun->mscDev->MaxLun - 1)
    {
        BlkDev->last_lun = 1;
        __wrn("disk, send last lun msg.........");
    }
    else
    {
        BlkDev->last_lun = 0;
    }

    printf("mscLun->LunNo=%d\n", mscLun->LunNo);
    printf("mscLun->mscDev->MaxLun=%d\n", mscLun->mscDev->MaxLun);
    printf("BlkDev->last_lun=%d\n", BlkDev->last_lun);
    /*  */
    GetDiskInfo(BlkDev);

    /*  */
    if (!mscLun->MediaPresent)
    {
        ret = UsbBlkDevReg(BlkDev, DEV_CLASS_USERDEF, 0);
    }
    else
    {
        ret = UsbBlkDevReg(BlkDev, DEV_CLASS_DISK, 1);
    }

    if (ret != USB_ERR_SUCCESS)
    {
        //DMSG_PANIC("ERR: DiskProbe: UsbBlkDevReg failed");
        return USB_ERR_REG_BLK_DEV_FAILED;
    }

    /* usb_monitor, scsi disk */
    {
        u32 is_reg = 1;
        //usbm_sendcmd(DEV_IOC_USR_HWSC_USBH_MSC_DEV_REG_SET, &is_reg);
    }
    /*
         MediaChangeSataUSB
     host
     hostepstall
     test_unit_ready
     
     */
    ENTER_CRITICAL(cpu_sr);
    mscLun->MediaChange = DiskMediaChange;
    EXIT_CRITICAL(cpu_sr);
    return USB_ERR_SUCCESS;
}

/*
*******************************************************************************
*                     UsbBlkDevOpen
*
* Description:
*
*
* Parameters:
*
*
* Return value:
*    0  
*   !0  
*
* note:
*    
*
*******************************************************************************
*/
int DiskRemove(__mscLun_t *mscLun)
{
    __UsbBlkDev_t *BlkDev = NULL;
    unsigned int  cpu_sr;

    if (mscLun == NULL)
    {
        hal_log_err("ERR: DiskRemove: input error");
        return -1;
    }

    BlkDev = (__UsbBlkDev_t *)mscLun->sdev_data;

    if (BlkDev == NULL)
    {
        hal_log_err("ERR: BlkDev == NULL");
        return -1;
    }

    /*  */
    UsbBlkDevUnReg(BlkDev);
    /* usb_monitor scsi disk */
    {
        u32 is_reg = 0;
        //usbm_sendcmd(DEV_IOC_USR_HWSC_USBH_MSC_DEV_REG_SET, &is_reg);
    }
    ShutDown(BlkDev);
    /* media change, MediaChange */
    ENTER_CRITICAL(cpu_sr);
    mscLun->MediaChange = NULL;
    EXIT_CRITICAL(cpu_sr);
    UsbBlkDevFree(BlkDev);
    mscLun->sdev_data = NULL;
    return USB_ERR_SUCCESS;
}


