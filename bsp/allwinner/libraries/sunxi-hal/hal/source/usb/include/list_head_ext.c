/*===============================================================================================*
*                                                                                                *
* MMMMMMMM  MMMMMMM    MMMMMMM  MMMMMMMM    MMMMMMMM       MM      MM    MMMMMMMMMMMMM           *
*    MMM      MMM        MMM      MMM          MM      MM        . MM        MMM        MM       *
*    MMM      MMM        MMM      MMM          MM      MM          MM        MMM        MM.      *
*    MMM      MMM        MMM      MMM          MM    . MM          MM        MMM        MMMM     *
*    MMM      MMM        MMM      MMM          MM      MMMM                  MMM        MM       *
*    MMMMMMMMMMMM        MMM      MMM          MM          MMMM              MMMMMMMMMMM         *
*    MMM      MMM        MMM      MMM          MM              MMMM          MMM          .      *
*    MMM      MMM        MMM      MMM          MM                . MM        MMM          MM     *
*    MMM      MMM        MMM      MMM          .     MM            MMMM      MMM          MMMM   *
*    MMM      MMM        MM        MM                MM            MM.       MMM          MM     *
*    MMM      MMM  .     MM        MM.               MMMM          MM        MMM          MM     *
* MMMMMMMM  MMMMMMM  MM.                MMMMM         MM      MMMM        MMMMMMMMMMMMM.         *
*                                                                                                *
*================================================================================================
*
*                                              usb host module
*
*                             Copyright(C), 2006-2008, SoftWinners Co., Ltd.
*                                                  All Rights Reserved
*
* File Name :
*
* Author : GLHuang(HoLiGun)
*
* Version : 1.0
*
* Date : 2008.06.12
*
* Description :
*           list_headextention
* History :
*================================================================================================
*/

#include "usb_os_platform.h"

#include "usb_list.h"
#include "list_head_ext.h"
#include <hal_osal.h>

hal_spinlock_t list_lock;
//list_header_inputnode
//return :  0   //node
//listcritical
/*
********************************************************************************
*                     list_head_ext_remov_node_from_list
* Description:
*     list_header_inputnode_datanode
*
* Arguments:
*     node_data          : input.  node
*     list_header_input  : input.  
* Return value:
*     0 : success
*    !0 : fail
* note:
*     list, 
*  : 
*********************************************************************************
*/
int   list_head_ext_remov_node_from_list(void *node_data,
        struct usb_list_head *list_header_input)
{
    struct usb_list_head *list_start = NULL;
    struct usb_list_head *list_now   = NULL;
    struct usb_list_head *list_next  = NULL;
    __u32 sr = 0;

    /* check input */
    if (node_data == NULL || list_header_input == NULL)
    {
        hal_log_err("ERR : list_head_ext_remov_node_from_list() input == NULL");
        return -1;
    }

    /* list must not empty */
    if (usb_list_empty(list_header_input))
    {
        hal_log_err("ERR : list_head_ext_remov_node_from_list() func_drv->dev_list is empty");
        return -1 ;
    }

    //USB_OS_ENTER_CRITICAL(sr);
    /* list, node,  */
    list_start = list_header_input;
    list_now = list_start->next;

    while (list_start != list_now)
    {
        list_next = list_now->next;

        if (list_now->data == node_data)
        {
            list_now->data = NULL;
            list_head_unlink_and_del(list_now);
            list_now = NULL;
            //USB_OS_EXIT_CRITICAL(sr);
            return 0;
        }

        list_now = list_next;
    }

    //USB_OS_EXIT_CRITICAL(sr);
    return -1;
}


/*
********************************************************************************
*                     list_node_exist
* Description:
*     listdatanode
*
* Arguments:
*     node_data          : input.
*     list_header_input  : input.
* Return value:
*     0 : success
*    !0 : fail
* note:
*
*********************************************************************************
*/
s32 list_node_exist(void *data, struct usb_list_head *list_head)
{
    struct usb_list_head *list_start = NULL;
    struct usb_list_head *list_now = NULL;
    __u32 cup_sr    = 0;

    /* check input */
    if (data == NULL || list_head == NULL)
    {
        hal_log_err("ERR : list_node_exist: input == NULL");
        return -1;
    }

    //USB_OS_ENTER_CRITICAL(cup_sr);
    hal_spin_lock(&list_lock);
    /* list, datanode */
    list_start = list_head;
    list_now = list_start->next;

    while (list_now != list_start)
    {
        if (list_now->data == data)
        {
            //USB_OS_EXIT_CRITICAL(cup_sr);
            hal_spin_unlock(&list_lock);
            return 0;
        }

        list_now = list_now->next;
    }

    //USB_OS_EXIT_CRITICAL(cup_sr);
    hal_spin_unlock(&list_lock);
    return -1;
}

/*
*****************************************************************************
*                     del_node_from_list
*
* Description:
*     list, datanode
* Arguments:
*
* Returns:
*
* note:
*
*
*****************************************************************************
*/
s32 list_del_node_by_data(void *data, struct usb_list_head  *list)
{
    struct usb_list_head *list_now  = NULL;
    struct usb_list_head *list_next = NULL;
    u32  is_find = 0;
    __u32 cup_sr    = 0;

    if (data == NULL || list == NULL)
    {
        hal_log_err("ERR: list_del_node_by_data: input == NULL");
        return -1;
    }

    if (usb_list_empty(list))
    {
        hal_log_err("ERR: list_del_node_by_data: list is already empty");
        return -1;
    }

    //USB_OS_ENTER_CRITICAL(cup_sr);
    hal_spin_lock(&list_lock);
    list_now = list->next;
    list_next = NULL;

    //
    while (list_now != list)
    {
        list_next = list_now->next;

        //--<1>--req
        if (list_now->data == data)
        {
            /*  */
            usb_list_del_init(list_now);
            /* list */
            _usb_list_head_free(list_now);
            list_now = NULL;
            is_find = 1;
        }

        list_now = list_next;
    }

    //USB_OS_EXIT_CRITICAL(cup_sr);
    hal_spin_unlock(&list_lock);

    if (is_find)
    {
        return 0;
    }
    else
    {
        //hal_log_err("ERR: list_del_node_by_data: del failed");
        return -1;
    }
}

/*
*****************************************************************************
*                     list_destroy_whole_list
*
* Description:
*      list node, 
* Arguments:
*
* Returns:
*
* note:
*
*
*****************************************************************************
*/
s32 list_destroy_whole_list(struct usb_list_head  *list)
{
    struct usb_list_head *list_now  = NULL;
    struct usb_list_head *list_next = NULL;
    __u32 cup_sr    = 0;

    if (list == NULL)
    {
        hal_log_err("ERR: input == NULL");
        return -1;
    }

    if (usb_list_empty(list))
    {
        hal_log_err("ERR: list is already empty");
        return -1;
    }

    //USB_OS_ENTER_CRITICAL(cup_sr);
    hal_spin_lock(&list_lock);
    list_now  = list->next;
    list_next = NULL;

    //
    while (list_now != list)
    {
        //--<1>--node
        list_next = list_now->next;
        //--<2>--node, 
        usb_list_del_init(list_now);
        _usb_list_head_free(list_now);
        list_now = NULL;
        //--<3>--node
        list_now = list_next;
    }

    //USB_OS_EXIT_CRITICAL(cup_sr);
    hal_spin_unlock(&list_lock);
    return 0;
}




