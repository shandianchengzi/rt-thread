/*
********************************************************************************************************************
*                                              usb_host
*
*                              (c) Copyright 2007-2009, holi.China
*                                       All Rights Reserved
*
* File Name     : msc_buff_manager.h
*
* Author        : javen
*
* Version       : 2.0
*
* Date          : 2009.08.19
*
* Description   :
*
* History       :
*     v1.0  holi  2008.11.22 - , lun
*     v2.0  javen 2009.08.19 - lun  
********************************************************************************************************************
*/
#ifndef _USBH_BUFF_MANAGER_H_
#define _USBH_BUFF_MANAGER_H_

typedef void       *__hdle;

/* usb host  buffer */
typedef struct tag_usbh_temp_buff
{
    unsigned int num;            /* bufferbuffer     */

    unsigned int dev_id;         /* id,        */
    unsigned int start_lba;      /*                              */
    unsigned int end_lba;        /* ,            */
    unsigned int sector_size;    /*                              */

    unsigned int used_time;      /*                  */

    void *buff;         /*                  */
    unsigned int buff_len;       /* buffer                         */

    unsigned int is_valid;       /* buff               */
    unsigned int is_busy;        /* buffdevice
                           usbh_buff_manager      */
} usbh_temp_buff_t;


#define  USBH_TEMP_BUFFER_MAX_NUM    8              //buffer, 4
#define  USBH_TEMP_BUFFER_MAX_LEN    (32 * 1024)    //32k, k, palloc

typedef struct tag_usbh_buff_manager
{
    unsigned int temp_buff_len;    /* buff, usbh_temp_buff_tbuff_len */
    unsigned int temp_buff_nr;     /* buff */

    usbh_temp_buff_t buff_array[USBH_TEMP_BUFFER_MAX_NUM];
} usbh_buff_manager_t;


//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
int usbh_msc_special_read(void *pBuffer,
                          unsigned int blk,
                          unsigned int n,
                          __hdle hDev,
                          unsigned int dev_id,
                          unsigned int secter_size,
                          void *blk_read_entry);

int usbh_msc_special_write(void *pBuffer,
                           unsigned int blk,
                           unsigned int n,
                           __hdle hDev,
                           unsigned int dev_id,
                           unsigned int secter_size,
                           void *blk_write_entry);

int set_usbh_temp_buff_invalid_by_dev(unsigned int dev_id);
int set_all_usbh_temp_buff_invalid(void);

int init_usbh_buff_manager(void);
int exit_usbh_buff_manager(void);

#endif





