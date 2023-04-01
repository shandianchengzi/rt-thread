/*
*******************************************************************************
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
* Date : 2008.05.xx
*
* Description :
*
* History :
**:list 
********************************************************************************************************************
*/



#ifndef _USB_LIST_H_
#define _USB_LIST_H_

#include <libc.h>
#include <log.h>
#include <hal_osal.h>
//#include "usb_host_config.h"


//#define   USE_USB_LIST_BUFF   0x01        //usb_listbuff

struct usb_list_head
{
    struct usb_list_head *next;
    struct usb_list_head *prev;
    void *data;
};

#define __USB_LIST_HEAD_INIT(name) { &(name), &(name) ,NULL}

//
#define USB_LIST_HEAD(name) \
    struct usb_list_head name = __USB_LIST_HEAD_INIT(name)

//
#define USB_INIT_LIST_HEAD(ptr) do { \
        (ptr)->next = (ptr); (ptr)->prev = (ptr); \
        (ptr)->data = NULL;\
    } while (0)

/* listnode
 *
 * list_head  :  
 * list_next  :  node
 * data       :  node
 */
#define usb_list_for_each_entry(list_head, list_next, data) \
    for((list_next) = (list_head)->next, (data) = list_next->data; \
        (list_next) != (list_head);       \
        (list_next) = (list_head)->next, (data) = list_next->data)

//=========================================================

//prev,next
static inline void __usb_list_add(struct usb_list_head *node,
                                  struct usb_list_head *prev,
                                  struct usb_list_head *next)
{
    node->next = next;
    node->prev = prev;
    prev->next = node;
    next->prev = node;
}

//nodehead
static inline void usb_list_add(struct usb_list_head *node, struct usb_list_head *head)
{
    __usb_list_add(node, head, head->next);
}

//nodehead
static inline void usb_list_add_tail(struct usb_list_head *node, struct usb_list_head *head)
{
    __usb_list_add(node, head->prev, head);
}

//=========================================================

//prev,next
static inline void __usb_list_del(struct usb_list_head *prev, struct usb_list_head *next)
{
    next->prev = prev;
    prev->next = next;
}

//listentry
static inline void usb_list_del(struct usb_list_head *entry)
{
    __usb_list_del(entry->prev, entry->next);
    //entry->next = LIST_POISON1;
    //entry->prev = LIST_POISON2;
    entry->next = entry;
    entry->prev = entry;
}

//list_deldata
static inline void usb_list_del_init(struct usb_list_head *entry)
{
    __usb_list_del(entry->prev, entry->next);
    USB_INIT_LIST_HEAD(entry);
}

//
static inline int usb_list_empty(const struct usb_list_head *head)
{
    return head->next == head;
}

//-------------------------------------------------------------------
//
//
//-------------------------------------------------------------------
__s32 ListMemoryInit(void);
__s32 ListMemoryExit(void);
void *ListMemoryMalloc(__u32 size, u8 *file_name, u32 line_nr);
void ListMemoryFree(void *addr, u8 *file_name, u32 line_nr);


/* list_headinit */
static struct usb_list_head *_list_head_malloc_init(void)
{
    struct usb_list_head *list = NULL;
    //buff
    //list = ListMemoryMalloc(sizeof(struct usb_list_head), USB_MEM_FILE_TRIGGER, USB_MEM_LINE_TRIGGER);
    list = hal_malloc(sizeof(struct usb_list_head));

    if (list == NULL)
    {
        __err("PANIC : _list_head_malloc_init() : no mem\n");
        return NULL;
    }

    USB_INIT_LIST_HEAD(list);
    return list;
}

/* list_head */
static void _usb_list_head_free(struct usb_list_head *list)
{
    if (list == NULL)
    {
        __err("PANIC : _list_head_free() : try to free NULL\n");
        return ;
    }

    //ListMemoryFree((void *)list, USB_MEM_FILE_TRIGGER, USB_MEM_LINE_TRIGGER);
    hal_free((void *)list);
    return ;
}

/*
********************************************************************************
*                     list_head_malloc_and_add
*
* Description:
*     list_headdatalist_headlist
* list_head_malloc_and_add()
*
* Arguments:
*     data  : input. 
*     head  : input. 
* Return value:
*      head->data
* note:
*     void
*********************************************************************************
*/
static inline void list_head_malloc_and_add(void *data, struct usb_list_head *head)
{
    __u32 lock = 0;
    struct usb_list_head *list = _list_head_malloc_init();

    if (list == NULL)
    {
        __err("ERR: _list_head_malloc_init failed\n");
        return;
    }

    //USB_OS_ENTER_CRITICAL(lock);
    list->data = data;
    usb_list_add_tail(list, head);
    //USB_OS_EXIT_CRITICAL(lock);
    return;
}

/*
********************************************************************************
*                     list_head_unlink_and_del
*
* Description:
*     listheadnode ,freenode, node
* list_head_malloc_and_add()
*
* Arguments:
*     head  : input. node
* Return value:
*      head->data
* note:
*     void
*********************************************************************************
*/
static inline void *list_head_unlink_and_del(struct usb_list_head *head)
{
    void *ret = NULL;
    __u32 lock = 0;

    if (head == NULL)
    {
        __err("PANIC : list_head_unlink_and_del() : try to free NULL\n");
        return NULL ;
    }

    //--1--unlink from list
    //USB_OS_ENTER_CRITICAL(lock);
    usb_list_del(head);
    ret = head->data;
    //USB_OS_EXIT_CRITICAL(lock);
    _usb_list_head_free(head);
    return ret;
}

#endif


