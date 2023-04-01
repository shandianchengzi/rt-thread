/*
********************************************************************************************************************
*                                              usb host driver
*
*                              (c) Copyright 2007-2010, javen.China
*                                       All Rights Reserved
*
* File Name     : usb_list.c
*
* Author        : javen
*
* Version       : 2.0
*
* Date          : 2010.03.02
*
* Description   : 256list headlist
*
* History       :
*
********************************************************************************************************************
*/

#include "usb_host_base_types.h"
#include "usb_os_platform.h"
#include "usb_list.h"

#include  "Horse.h"


static void *list_memory_base = NULL;

#define  MAX_LIST_BLOCK_NUM         256

/*
*******************************************************************************
*                     ListMemoryInit
*
* Description:
*    256list head
*
* Parameters:
*    void
*
* Return value:
*    0 : success
*   !0 : fail
*
* note:
*    void
*
*******************************************************************************
*/
__s32 ListMemoryInit(void)
{
    list_memory_base = HorseHeadInit(sizeof(struct list_head), MAX_LIST_BLOCK_NUM);

    if (list_memory_base == NULL)
    {
        DMSG_PANIC("ERR: HorseHeadInit failed\n");
        return -1;
    }

    return 0;
}

/*
*******************************************************************************
*                     ListMemoryExit
*
* Description:
*    256list head
*
* Parameters:
*    void
*
* Return value:
*    0 : success
*   !0 : fail
*
* note:
*    void
*
*******************************************************************************
*/
__s32 ListMemoryExit(void)
{
    if (list_memory_base)
    {
        HorseHeadExit(list_memory_base);
        list_memory_base = NULL;
    }

    return 0;
}

/*
*******************************************************************************
*                     ListMemoryMalloc
*
* Description:
*    256list headlist head
*
* Parameters:
*    void
*
* Return value:
*    list head
*
* note:
*    void
*
*******************************************************************************
*/
void *ListMemoryMalloc(__u32 size, u8 *file_name, u32 line_nr)
{
    void *addr = NULL;
    addr = HorseBlockMalloc(list_memory_base);

    if (addr == NULL)
    {
        addr = USB_OS_MALLOC(size, file_name, line_nr);
        DMSG_INFO("HorseBlockMalloc failed, must USB_OS_MALLOC, addr = %x\n", addr);
    }

    return addr;
}

/*
*******************************************************************************
*                     ListMemoryFree
*
* Description:
*    ListMemoryMalloclist head
*
* Parameters:
*    void
*
* Return value:
*    void
*
* note:
*    void
*
*******************************************************************************
*/
void ListMemoryFree(void *addr, u8 *file_name, u32 line_nr)
{
    if (addr)
    {
        if (HorseBlockFree(list_memory_base, addr) != 0)
        {
            DMSG_INFO("HorseBlockFree failed, must USB_OS_FREE, addr = %x\n", addr);
            USB_OS_FREE(addr);
        }
    }
}







