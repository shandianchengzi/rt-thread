/*
********************************************************************************************************************
*                                              usb_host
*
*                              (c) Copyright 2007-2009, holi.China
*                                       All Rights Reserved
*
* File Name     : usbh_buff_manager.c
*
* Author        : javen
*
* Version       : 2.0
*
* Date          : 2009.08.19
*
* Description   : USBH.
*                 fs_buffer < 32k
*                 fs_buffer >= 32k
*                 fs_buffer, dma
*
* :  device. device, buff
*
* History       :
*     v1.0  holi  2008.11.22 - , lun
*     v2.0  javen 2009.08.19 - lun  , 
********************************************************************************************************************
*/
#include "usb_os_platform.h"
#include "usbh_buff_manager.h"
#include  "error.h"
#include  "usb_msc_i.h"

static usbh_buff_manager_t usbh_buff_manager;

typedef int(* buff_blk_func_t)(void *pBuffer, unsigned int blk, unsigned int n, void *hDev);


/* usbh_temp_buff */
static unsigned int usbh_temp_buff_max_len(void)
{
    return usbh_buff_manager.temp_buff_len;
}

/*
*********************************************************************
*                     set_usbh_temp_buff_default
*
* Description:
*     usbh_temp_buff
* Arguments:
*
* Returns:
*
* note:
*
*
*********************************************************************
*/
static void set_usbh_temp_buff_default(usbh_temp_buff_t *temp_buff)
{
    unsigned int cpu_sr = 0;

    if (temp_buff == NULL)
    {
        //DMSG_PANIC("ERR: set_usbh_temp_buff_default: input error\n");
        //DMSG_PANIC("ERR: temp_buff = 0x%x\n", temp_buff);
        return ;
    }

    ENTER_CRITICAL(cpu_sr);
    temp_buff->dev_id        = 0xffffffff;
    temp_buff->start_lba     = 0;
    temp_buff->end_lba       = 0;
    temp_buff->sector_size   = 0;
    temp_buff->used_time     = 0;
    temp_buff->is_valid      = 0;
    temp_buff->is_busy       = 0;
    memset(temp_buff->buff, 0, temp_buff->buff_len);
    EXIT_CRITICAL(cpu_sr);
}

/* buffbusy, buff
 *
 * usbh_temp_buffdma, blk_readblk_write
 * buff, buffbusy
 * 
 */
static void set_usbh_temp_buff_busy(unsigned int buff_num)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int cpu_sr = 0;
    //unsigned int i = 0;

    if (buff_num >= buff_mgr->temp_buff_nr)
    {
        //DMSG_PANIC("ERR: set_usbh_temp_buff_busy: input error\n");
        //DMSG_PANIC("ERR: buff_num = 0x%x\n", buff_num);
        return ;
    }

    //for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        //if (buff_mgr->buff_array[i].buff == temp_buff)
        {
            ENTER_CRITICAL(cpu_sr);
            buff_mgr->buff_array[buff_num].is_busy = 1;
            EXIT_CRITICAL(cpu_sr);
        }
    }
}

/* buffbusy, buff */
static void set_usbh_temp_buff_free(unsigned int buff_num)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int cpu_sr = 0;
    //unsigned int i = 0;

    if (buff_num >= buff_mgr->temp_buff_nr)
    {
        //DMSG_PANIC("ERR: set_usbh_temp_buff_free: input error\n");
        //DMSG_PANIC("ERR: buff_num = 0x%x\n", buff_num);
        return ;
    }

    //for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        //if (buff_mgr->buff_array[i].buff == temp_buff)
        {
            ENTER_CRITICAL(cpu_sr);
            buff_mgr->buff_array[buff_num].is_busy = 0;
            EXIT_CRITICAL(cpu_sr);
        }
    }
}

/*
*********************************************************************
*                     set_usbh_temp_buff_valid
*
* Description:
*     device, buffer
* Arguments:
*     buff         :  input.  buff
*     dev_id       :  input.  
*     start_lba    :  input.  
*     sector_size  :  input.  
* Returns:
*
* note:
*
*
*********************************************************************
*/
static int set_usbh_temp_buff_valid(unsigned int buff_num, unsigned int dev_id, unsigned int start_lba, unsigned int sector_size)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    //unsigned int i = 0;
    unsigned int cpu_sr = 0;

    if (buff_num >= buff_mgr->temp_buff_nr || sector_size == 0)
    {
        //DMSG_PANIC("ERR: set_usbh_temp_buff_valid: input error\n");
        //DMSG_PANIC("ERR: buff_num = %d, sector_size = 0x%x\n", buff_num, sector_size);
        return -1;
    }

    //for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        //buff
        //if (buff_mgr->buff_array[i].buff == buff)
        {
            ENTER_CRITICAL(cpu_sr);
            buff_mgr->buff_array[buff_num].dev_id        = dev_id;
            buff_mgr->buff_array[buff_num].sector_size   = sector_size;
            buff_mgr->buff_array[buff_num].start_lba     = start_lba;
            buff_mgr->buff_array[buff_num].end_lba       = start_lba + (buff_mgr->buff_array[buff_num].buff_len / sector_size) - 1;
            buff_mgr->buff_array[buff_num].used_time     = 1;  /* fs */
            buff_mgr->buff_array[buff_num].is_valid      = 1;
            EXIT_CRITICAL(cpu_sr);
            /*
                        //DMSG_TEMP_TEST("valid buffer is %d, start_lba = %d, end_lba = %d\n",
                                  i, start_lba, buff_mgr->buff_array[i].end_lba);
            */
            return 0;
        }
    }

    ////DMSG_PANIC("ERR: the buff is not belong to usbh temp buff manager\n");
    //return -1;
}

/*
***************************************************************************
*                     set_usbh_temp_buff_invalid
*
* Description:
*     devbufflbabuffer,buffer
* Arguments:
*     dev_id  :  input.  
*     lba     :  input.  buff
* Returns:
*     
* note:
*
*
***************************************************************************
*/
static int set_usbh_temp_buff_invalid(unsigned int dev_id, unsigned int lba)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int i = 0;

    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        //devlbabuff
        if ((buff_mgr->buff_array[i].dev_id == dev_id)
            && (buff_mgr->buff_array[i].start_lba <= lba)
            && (lba <= buff_mgr->buff_array[i].end_lba))
        {
            set_usbh_temp_buff_default(&(buff_mgr->buff_array[i]));
        }
    }

    return 0;
}

/*
*********************************************************************
*                     set_usbh_temp_buff_invalid_by_dev
*
* Description:
*     dev_idbuff
* Arguments:
*     dev_id  :  input.  
* Returns:
*     
* note:
*
*
*********************************************************************
*/
int set_usbh_temp_buff_invalid_by_dev(unsigned int dev_id)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int i = 0;

    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        //dev_idbuff
        if (buff_mgr->buff_array[i].dev_id == dev_id)
        {
            set_usbh_temp_buff_default(&(buff_mgr->buff_array[i]));
        }
    }

    return 0;
}

/*
*********************************************************************
*                     set_usbh_temp_buff_invalid
*
* Description:
*     dev_idbuff
* Arguments:
*     dev_id  :  input.  
* Returns:
*     
* note:
*
*********************************************************************
*/
int set_all_usbh_temp_buff_invalid(void)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int i = 0;

    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        set_usbh_temp_buff_default(&(buff_mgr->buff_array[i]));
    }

    return 0;
}

/*
*********************************************************************
*                     select_invalid_usbh_temp_buff
*
* Description:
*     buffdevice
* Arguments:
*
* Returns:
*
* note:
*   :
*       1buffbusy, 
*       2invalid buff
*       3valid bufffsbuff
*       4buffbit, busybuff
*       5, , NULL
*
*
*********************************************************************
*/
static void *select_invalid_usbh_temp_buff(unsigned int *buff_num)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    void *temp_buff = NULL;
    unsigned int min_used = 0xffffffff;       //
    //unsigned int buff_num = 0;               //buff
    unsigned int i = 0;

    if (buff_num == NULL)
    {
        return NULL;
    }

    //--<1>--invalidbuffer
    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        //--<1-1>--busy, 
        if (buff_mgr->buff_array[i].is_busy)
        {
            continue;
        }

        //--<1-2>--invalidbuffer
        if (buff_mgr->buff_array[i].is_valid == 0)
        {
            temp_buff = buff_mgr->buff_array[i].buff;
            *buff_num  = i;
            set_usbh_temp_buff_default(&(buff_mgr->buff_array[*buff_num]));
            return temp_buff;
        }

        //--<1-3>--bufferfsbuff
        if (min_used > buff_mgr->buff_array[i].used_time)
        {
            min_used  = buff_mgr->buff_array[i].used_time;
            *buff_num  = i;
            temp_buff = buff_mgr->buff_array[i].buff;
        }

        //--<1-4>--, used_time2
        //, fs,  
        buff_mgr->buff_array[i].used_time = buff_mgr->buff_array[i].used_time >> 1;
    }

    //--<2>--fsbuffer
    if (min_used != 0xffffffff)
    {
        set_usbh_temp_buff_default(&(buff_mgr->buff_array[*buff_num]));
        return temp_buff;
    }

    //--<3>--buffer,
    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        if (buff_mgr->buff_array[i].is_busy == 0)
        {
            temp_buff = buff_mgr->buff_array[i].buff;
            *buff_num  = i;
            set_usbh_temp_buff_default(&(buff_mgr->buff_array[*buff_num]));
            return temp_buff;
        }
    }

    //--<4>--buffbusy, buff
    temp_buff = NULL;
    return temp_buff;
}

/* buffer, buffer */
static int select_best_buffer(unsigned int dev_id, unsigned int lba, unsigned int size, unsigned int *nr)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int max_len = 0;  /* buffer */
    unsigned int i = 0;

    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        if ((dev_id == buff_mgr->buff_array[i].dev_id) && buff_mgr->buff_array[i].is_valid)
        {
            /* buffer */
            if (buff_mgr->buff_array[i].start_lba <= lba && buff_mgr->buff_array[i].end_lba >= lba)
            {
                if (max_len <= (buff_mgr->buff_array[i].end_lba - lba + 1))
                {
                    max_len = (buff_mgr->buff_array[i].end_lba - lba + 1);
                    *nr = i;
                }

                if (max_len >= size)
                {
                    break;
                }
            }
        }
    }

    if (i >= buff_mgr->temp_buff_nr && max_len == 0)
    {
        ////DMSG_PANIC("find best buffer find\n");
        *nr = 0xff;
        return -1;
    }

    return 0;
}

/*
******************************************************************************
*                     read_usbh_temp_buff
*
* Description:
*     device, buffer
*
* Arguments:
*     dev_id  :  input.  buff
*     lba     :  input.  
*     size    :  input.  
*     buff    :  output. 
*
* Returns:
*     is_copy = 1: buffer
*     is_copy = 0: buffer
*
* note:
*                     start     lba                 lba+size           end
*     usbh_temp_buff: |---------|----------------------|----------------|
*                               |----valid_sector------|
*                               |-------------left_sector---------------|
*
******************************************************************************
*/
static int read_usbh_temp_buff(unsigned int dev_id, unsigned int lba, unsigned int size, void *buff, unsigned int is_copy)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int buff_start        = 0;  /* buff       */
    unsigned int valid_sector      = 0;  /* buffer       */
    unsigned int max_valid_sector  = 0;  /* buffer   */
    unsigned int buff_len          = 0;  /*          */
    unsigned int buff_no           = 0;
#define min( x, y )          ( (x) < (y) ? (x) : (y) )

    if (buff == NULL)
    {
        //DMSG_PANIC("ERR: read_usbh_temp_buff: input error\n");
        return 0;
    }

    if (select_best_buffer(dev_id, lba, size, &buff_no) == 0)
    {
        max_valid_sector = buff_mgr->buff_array[buff_no].end_lba - lba + 1;

        if (is_copy)
        {
            buff_start  = (lba - buff_mgr->buff_array[buff_no].start_lba) * (buff_mgr->buff_array[buff_no].sector_size);
            valid_sector = min(size, max_valid_sector);
            buff_len    = valid_sector * (buff_mgr->buff_array[buff_no].sector_size);

            if (buff_mgr->buff_array[buff_no].buff == NULL)
            {
                //DMSG_PANIC("ERR: usbh temp buff had free, can not used\n");
                return -1;
            }

            //DMSG_TEMP_TEST("special buffer is %d, start_lba = %d, end_lba = %d\n",
                           //buff_no,
                           //buff_mgr->buff_array[buff_no].start_lba,
                           //buff_mgr->buff_array[buff_no].end_lba);
            buff_mgr->buff_array[buff_no].used_time++;
            memcpy(buff, (void *)((unsigned char *)(buff_mgr->buff_array[buff_no].buff) + buff_start), buff_len);
            return valid_sector;
        }
    }

    return max_valid_sector;
}

/*
******************************************************************************
*                     write_usbh_temp_buff
*
* Description:
*     device, usbh_temp_buff, 
* Arguments:
*     dev_id  :  input.  buff
*     lba     :  input.  
*     size    :  input.  
*     buff    :  input.  
*
* Returns:
*     buff
* note:
*
*
******************************************************************************
*/
static void *write_usbh_temp_buff(unsigned int dev_id, unsigned int lba, unsigned int size, const void *buff)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int buff_start  = 0;  /* buff */
    unsigned int buff_len    = 0;  /*  */
    unsigned int i           = 0;

    if (buff == NULL)
    {
        //DMSG_PANIC("ERR: write_usbh_temp_buff: input error\n");
        return NULL;
    }

    //--<1>--buffbuff
    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        //dev_id, buff, lbabuff
        if ((dev_id == buff_mgr->buff_array[i].dev_id) && buff_mgr->buff_array[i].is_valid)
        {
            //lbabuff, sizebuff, 
            if ((buff_mgr->buff_array[i].start_lba <= (lba + size))
                && ((lba + size) < buff_mgr->buff_array[i].end_lba)
                && (buff_mgr->buff_array[i].start_lba <= lba)
                && (lba < buff_mgr->buff_array[i].end_lba))
            {
                buff_start = (lba - buff_mgr->buff_array[i].start_lba) * (buff_mgr->buff_array[i].sector_size);
                buff_len   = size * (buff_mgr->buff_array[i].sector_size);

                if (buff_mgr->buff_array[i].buff == NULL)
                {
                    //DMSG_PANIC("ERR: usbh temp buff had free, can not used\n");
                    return NULL;
                }

                buff_mgr->buff_array[i].used_time++;
                memcpy((void *)((unsigned char *)(buff_mgr->buff_array[i].buff) + buff_start), buff, buff_len);
                //blk
                //return buff_mgr->buff_array[i].buff;
                return (void *)((unsigned char *)(buff_mgr->buff_array[i].buff) + buff_start);
            }
        }
    }

    return NULL;
}

/*
********************************************************************************************************
*                     usbh_msc_special_read
*
* Description:
*     usbh_temp_buff, usbh_temp_buff
* usbh_temp_buffdevice
*
* Arguments:
*     pBuffer           :  output. 
*     blk               :  input.  
*     n                 :  input.  
*     hDev              :  input.  
*     dev_id            :  input.  
*     blk_read_entry    :  input.  , sd_read.
*
* Returns:
*     blk
* note:
*
*  usbh_temp_buff:
*
*      1user buffer sizeusb temp buffer size
*      (1)temp buffer, buffer
*      (2)user buffer, 
*      (3)usb temp buffer
*           devicecopyuser buffer
*
*      2user buffer sizeusb temp buffer size
*      (1)usb temp buffer
*      (2)usb temp buffer sizeuser buffer
*      (3)usb temp buffer sizeusb temp buffer
*           devicecopyuser buffer
*
********************************************************************************************************
*/
#if 1
int usbh_msc_special_read(void *pBuffer,
                          unsigned int blk,
                          unsigned int n,
                          void *hDev,
                          unsigned int dev_id,
                          unsigned int secter_size,
                          void *blk_read_entry)
{
    unsigned char *Buffer_temp   = (unsigned char *)pBuffer;
    unsigned int temp_sector_1 = 0;            //
    unsigned int total_len     = 0;            //
    unsigned int left_sector   = 0;            /*   */
    //  unsigned int sector_nr     = 0;            //
    void *usbh_temp_buff = NULL;        //usbh_temp_buff
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    buff_blk_func_t buff_blk_read;

    //--<1>--check input
    if (pBuffer == NULL || n == 0 || hDev == NULL || blk_read_entry == NULL)
    {
        //DMSG_PANIC("ERR : usbh_msc_special_read: input is error\n");
        //DMSG_PANIC("ERR : usbh_msc_special_read: pBuffer = 0x%x, n = %d, hDev = 0x%x,blk_read  = 0x%x\n",
        //           pBuffer, n, hDev, blk_read_entry);
        return 0;
    }

    //DMSG_TEMP_TEST("read: --<1-0>--, Buffer_temp_s = %x, Buffer_temp_e = %x\n",
    //               Buffer_temp, (Buffer_temp + n * secter_size));
    buff_blk_read  = (buff_blk_func_t)blk_read_entry;
    total_len = (n * secter_size);

    if (total_len < usbh_temp_buff_max_len())
    {
        unsigned int buff_num = 0;
        //(1)temp buffer, buffer
        temp_sector_1 = read_usbh_temp_buff(dev_id, blk, n, pBuffer, 0);
        //DMSG_TEMP_TEST("read: --<1-1>--, secter_size = %d, blk = %d, n = %d, temp_sector_1 = %d\n",
         //              secter_size, blk, n, temp_sector_1);

        //(2)user buffer, 
        if (temp_sector_1 >= n)
        {
            ////DMSG_TEMP_TEST("read: --<1-2>--, secter_size = %d, blk = %d, n = %d, temp_sector_1 = %d\n",
            //               secter_size, blk, n, temp_sector_1);
            return read_usbh_temp_buff(dev_id, blk, n, pBuffer, 1);
        }

        /*
        (3)usb temp buffer
             devicecopyuser buffer
        */
        //--<3-1>--buff, device
        usbh_temp_buff = select_invalid_usbh_temp_buff(&buff_num);

        if (usbh_temp_buff == NULL)
        {
            //DMSG_PANIC("ERR: select_invalid_usbh_temp_buff failed\n");
            //usbh_temp_buff, 
            return buff_blk_read(pBuffer, blk, n, hDev);
        }

        //--<3-2>--
        set_usbh_temp_buff_busy(buff_num);
        temp_sector_1 = buff_blk_read(usbh_temp_buff, blk, buff_mgr->temp_buff_len / secter_size, hDev);
        set_usbh_temp_buff_free(buff_num);

        if (temp_sector_1 != (buff_mgr->temp_buff_len / secter_size))
        {
            //DMSG_PANIC("ERR: usbh_msc_special_read: buff_blk_read failed\n");
            return 0;
        }

        //--<3-3>--buff
        set_usbh_temp_buff_valid(buff_num, dev_id, blk, secter_size);
        //--<3-4>--, fs
        memcpy(pBuffer, usbh_temp_buff, total_len);
        //DMSG_TEMP_TEST("memcpy1: pBuffer = %x,pBuffer_s = %x, pBuffer_e = %x\n",
                       //(unsigned int)pBuffer, Buffer_temp, Buffer_temp + total_len);
        //DMSG_TEMP_TEST("read: --<1-3>--, secter_size = %d, blk = %d, n = %d, total_len = %d\n",
                       //secter_size, blk, n, total_len);
        return n;
    }
    else
    {
        unsigned int buff_num = 0;
        //(1)usb temp buffer
        temp_sector_1 = read_usbh_temp_buff(dev_id, blk, n, pBuffer, 1);
        //DMSG_TEMP_TEST("read: --<2-1>--, secter_size = %d, blk = %d, n = %d, temp_sector_1 = %d\n",
                       //secter_size, blk, n, temp_sector_1);

        if (((n - temp_sector_1) * secter_size) >= usbh_temp_buff_max_len())
        {
            //(2)usb temp buffer sizeuser buffer
            left_sector = buff_blk_read(Buffer_temp + (temp_sector_1 * secter_size),
                                        (blk + temp_sector_1),
                                        (n - temp_sector_1),
                                        hDev);
            //DMSG_TEMP_TEST("read: --<2-2>--, secter_size = %d, blk = %d, n = %d, left_sector = %d\n",
                           //secter_size, blk, n, left_sector);
            //DMSG_TEMP_TEST("memcpy4: pBuffer_s = %x, pBuffer_e = %x\n",
                           //Buffer_temp + (temp_sector_1 * secter_size),
                           //Buffer_temp + (temp_sector_1 * secter_size) + ((n - temp_sector_1) * secter_size));

            if (left_sector)
            {
                return (left_sector + temp_sector_1);
            }
            else
            {
                return 0;  /* read faild */
            }
        }
        else
        {
            /* (3)usb temp buffer sizeusb temp buffer
                    devicecopyuser buffer */
            //--<3-1>--buff, device
            usbh_temp_buff = select_invalid_usbh_temp_buff(&buff_num);

            if (usbh_temp_buff == NULL)
            {
                //DMSG_PANIC("ERR: select_invalid_usbh_temp_buff failed\n");
                //usbh_temp_buff, 
                return buff_blk_read(pBuffer, blk, n, hDev);
            }

            //--<3-2>--
            set_usbh_temp_buff_busy(buff_num);
            left_sector = buff_blk_read(usbh_temp_buff, (blk + temp_sector_1), buff_mgr->temp_buff_len / secter_size, hDev);
            set_usbh_temp_buff_free(buff_num);

            if (left_sector != (buff_mgr->temp_buff_len / secter_size))
            {
                //DMSG_PANIC("ERR: usbh_msc_special_read: buff_blk_read failed\n");
                return 0;
            }

            //--<3-3>--buff
            set_usbh_temp_buff_valid(buff_num, dev_id, (blk + temp_sector_1), secter_size);
            //--<3-4>--, fs
            memcpy(Buffer_temp + (temp_sector_1 * secter_size),
                          usbh_temp_buff,
                         ((n - temp_sector_1) * secter_size));
            //DMSG_TEMP_TEST("memcpy2: pBuffer_s = %x, pBuffer_e = %x\n",
                          // Buffer_temp + (temp_sector_1 * secter_size),
                          // Buffer_temp + (temp_sector_1 * secter_size) + ((n - temp_sector_1) * secter_size));
            //DMSG_TEMP_TEST("read: --<2-3>--, secter_size = %d, blk = %d, n = %d, left_sector = %d\n",
                         //  secter_size, blk, n, (n - temp_sector_1));
            return n;
        }
    }
}
#else
/*
********************************************************************************************************
*                     usbh_msc_special_read
*
* Description:
*     usbh_temp_buff, usbh_temp_buff
* usbh_temp_buffdevice
*
* Arguments:
*     pBuffer           :  output. 
*     blk               :  input.  
*     n                 :  input.  
*     hDev              :  input.  
*     dev_id            :  input.  
*     blk_read_entry    :  input.  , sd_read.
*
* Returns:
*     blk
* note:
*
*  usbh_temp_buff:
*
********************************************************************************************************
*/
int usbh_msc_special_read(void *pBuffer,
                          unsigned int blk,
                          unsigned int n,
                          void *hDev,
                          unsigned int dev_id,
                          unsigned int secter_size,
                          void *blk_read_entry)
{
    unsigned char *Buffer_temp = (unsigned char *)pBuffer;
    unsigned int this_len = 0;   //
    unsigned int sector_nr = 0;  //
    void *usbh_temp_buff = NULL;   //usbh_temp_buff
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    buff_blk_func_t buff_blk_read;

    //--<1>--check input
    if (pBuffer == NULL || n == 0 || hDev == NULL || blk_read_entry == NULL)
    {
        //DMSG_PANIC("ERR : usbh_msc_special_read: input is error\n");
        //DMSG_PANIC("ERR : usbh_msc_special_read: pBuffer = 0x%x, n = %d, hDev = 0x%x,blk_read  = 0x%x\n",
                   pBuffer, n, hDev, blk_read_entry);
        return 0;
    }

    //--<2>--, usbh_temp_buff
    /* 1usbh_temp_buff
     * 2pBuffer
     * 3
     */
    sector_nr = n;
    this_len = n * secter_size;
    buff_blk_read  = (buff_blk_func_t)blk_read_entry;

    if (this_len <= usbh_temp_buff_max_len())
    {
        int ret = 0;
        //--<3-1>--usbh_temp_buff, 
        /*
                if(read_usbh_temp_buff(dev_id, blk, n, pBuffer) == 0){
                    return sector_nr;
                }
        */
        sector_nr = read_usbh_temp_buff(dev_id, blk, n, pBuffer, 0);

        if (sector_nr)
        {
            /* buffer, buffer,  */
            if (sector_nr /*> (n/2)*/)
            {
                sector_nr = read_usbh_temp_buff(dev_id, blk, n, pBuffer, 1);

                if (sector_nr < n)
                {
                    sector_nr += buff_blk_read(Buffer_temp + (sector_nr * secter_size),
                                               (blk + sector_nr),
                                               (n - sector_nr),
                                               hDev);
                }

                return sector_nr;
            }
        }

        //--<3-2>--buff, device
        usbh_temp_buff = select_invalid_usbh_temp_buff();

        if (usbh_temp_buff == NULL)
        {
            //DMSG_PANIC("ERR: select_invalid_usbh_temp_buff failed\n");
            //usbh_temp_buff, 
            return buff_blk_read(pBuffer, blk, n, hDev);
        }

        //--<3-3>--
        set_usbh_temp_buff_busy(usbh_temp_buff);
        ret = buff_blk_read(usbh_temp_buff, blk, buff_mgr->temp_buff_len / secter_size, hDev);
        set_usbh_temp_buff_free(usbh_temp_buff);

        if (ret != (buff_mgr->temp_buff_len / secter_size))
        {
            //DMSG_PANIC("ERR: usbh_msc_special_read: buff_blk_read failed\n");
            return 0;
        }

        //--<3-2-4>--buff
        set_usbh_temp_buff_valid(usbh_temp_buff, dev_id, blk, secter_size);
        //--<3-4>--, fs
        memcpy(pBuffer, usbh_temp_buff, this_len);
        return n;
    }
    else
    {
        /*
         *******************************************************************
         * 32k, usbh_temp_buffusbh_temp_buff
         * usbh_temp_buffdevice
         *******************************************************************
         */
        sector_nr = read_usbh_temp_buff(dev_id, blk, n, pBuffer, 1);

        if (sector_nr)
        {
            if (sector_nr < n)
            {
                sector_nr += buff_blk_read(Buffer_temp + (sector_nr * secter_size),
                                           (blk + sector_nr),
                                           (n - sector_nr),
                                           hDev);
            }
        }
        else
        {
            sector_nr = buff_blk_read(pBuffer, blk, n, hDev);
        }

        return sector_nr;
    }
}
#endif

/*
****************************************************************************
*                     usbh_msc_special_write
*
* Description:
*     usbh_temp_buff, usbh_temp_buff
* usbh_temp_buffdevice
*
* Arguments:
*     pBuffer           :  input.  device
*     blk               :  input.  
*     n                 :  input.  
*     hDev              :  input.  
*     dev_id            :  input.  
*     blk_write_entry   :  input.  , sd_write.
*
* Returns:
*     blk
* note:
*  , usbh_temp_buff
*      1usbh_temp_buff
*      2pBuffer
*      3
*
*  usbh_temp_buff:
*      1data_len < 32k, pBuffer, 
*         (1)usbh_temp_buff, device
*         (2)usbh_temp_buff, usbh_temp_buff
*         (3)buff(pbuffer)
*
*      2data_len >= 32k, pBuffer, 
*         (1)usbh_temp_buff
*         (2)buff, 
*         (3)buff

*
****************************************************************************
*/
int usbh_msc_special_write(void *pBuffer,
                           unsigned int blk,
                           unsigned int n,
                           void *hDev,
                           unsigned int dev_id,
                           unsigned int secter_size,
                           void *blk_write_entry)
{
    unsigned int this_len = 0;     //
    void *usbh_temp_buff = NULL;   //usbh_temp_buff
    buff_blk_func_t buff_blk_write;

    //--<1>--check input
    if (pBuffer == NULL || n == 0 || hDev == NULL || blk_write_entry == NULL)
    {
        //DMSG_PANIC("ERR : usbh_msc_special_read: input is error\n");
        //DMSG_PANIC("ERR : usbh_msc_special_read: pBuffer = 0x%x, n = %d, hDev = 0x%x,blk_read  = 0x%x\n",
        //           pBuffer, n, hDev, blk_write_entry);
        return 0;
    }

    //--<3>--, usbh_temp_buff
    /* 1usbh_temp_buff
     * 2pBuffer
     * 3
     */
    this_len = n * secter_size;
    buff_blk_write = (buff_blk_func_t)blk_write_entry;

    if (this_len < usbh_temp_buff_max_len())
    {
        unsigned int buff_num = 0;
        //--<3-1-1>--usbh_temp_buff, usbh_temp_buffbuff
        usbh_temp_buff = write_usbh_temp_buff(dev_id, blk, n, pBuffer);

        if (usbh_temp_buff != NULL)
        {
            //, 
            return buff_blk_write(usbh_temp_buff, blk, n, hDev);
        }

        //, buff
        //buff,
        set_usbh_temp_buff_invalid(dev_id, blk);
        //--<3-1-2>--buff, buff
        usbh_temp_buff = select_invalid_usbh_temp_buff(&buff_num);

        if (usbh_temp_buff == NULL)
        {
            //DMSG_PANIC("ERR: select_invalid_usbh_temp_buff failed\n");
            //usbh_temp_buff, 
            return buff_blk_write(pBuffer, blk, n, hDev);
        }

        memcpy(usbh_temp_buff, pBuffer, this_len);
        /*
         **********************************************************
         * this_len32k,usbh_temp_buff
         **********************************************************
         */
        //--<3-1-3>--usbh_temp_buff
        return buff_blk_write(usbh_temp_buff, blk, n, hDev);
    }
    else
    {
        //32k, dev_idbuffer
        set_usbh_temp_buff_invalid_by_dev(dev_id);
        return buff_blk_write(pBuffer, blk, n, hDev);
    }
}

/*
*********************************************************************
*                     init_usbh_buff_manager
*
* Description:
*      usbh bufferUSBH
* Arguments:
*
* Returns:
*
* note:
*
*
*********************************************************************
*/
int init_usbh_buff_manager(void)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int i = 0;
    unsigned int page = 0;
    //--<1>--usbh_buff_manager
    memset(buff_mgr, 0, sizeof(usbh_buff_manager_t));
    buff_mgr->temp_buff_nr  = USBH_TEMP_BUFFER_MAX_NUM;
    buff_mgr->temp_buff_len = USBH_TEMP_BUFFER_MAX_LEN;
    page = ((buff_mgr->temp_buff_len + 1023) >> 10) << 10;
    //DMSG_INFO("usb temp buffer size is %d\n", buff_mgr->temp_buff_len);

    //--<2>--temp_buff
    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        buff_mgr->buff_array[i].buff = (void *)hal_malloc(page);

        if (buff_mgr->buff_array[i].buff == NULL)
        {
            //,
            //DMSG_PANIC("ERR: init_usbh_buff_manager: USB_OS_PAGE_MALLOC failed\n");
            goto failed;
        }

        memset((void *)buff_mgr->buff_array[i].buff, 0, buff_mgr->temp_buff_len);
        buff_mgr->buff_array[i].buff_len = buff_mgr->temp_buff_len;
        buff_mgr->buff_array[i].num = i;
        set_usbh_temp_buff_default(&(buff_mgr->buff_array[i]));
    }

    return 0;
failed:

    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        if (buff_mgr->buff_array[i].buff)
        {
            hal_free(buff_mgr->buff_array[i].buff);
            buff_mgr->buff_array[i].buff = NULL;
        }
        else
        {
            //DMSG_PANIC("ERR: parameter is invalid, pfree failed\n");
        }
    }

    memset(buff_mgr, 0, sizeof(usbh_buff_manager_t));
    return -1;
}

/*
*********************************************************************
*                     exit_usbh_buff_manager
*
* Description:
*     sdsd
* Arguments:
*
* Returns:
*
* note:
*
*
*********************************************************************
*/
int exit_usbh_buff_manager(void)
{
    usbh_buff_manager_t *buff_mgr = &usbh_buff_manager;
    unsigned int i = 0;
    set_all_usbh_temp_buff_invalid();

    for (i = 0; i < buff_mgr->temp_buff_nr; i++)
    {
        if (buff_mgr->buff_array[i].buff)
        {
            hal_free(buff_mgr->buff_array[i].buff);
            buff_mgr->buff_array[i].buff = NULL;
        }
        else
        {
            //DMSG_PANIC("ERR: parameter is invalid, pfree failed\n");
        }
    }

    memset(buff_mgr, 0, sizeof(usbh_buff_manager_t));
    return 0;
}

