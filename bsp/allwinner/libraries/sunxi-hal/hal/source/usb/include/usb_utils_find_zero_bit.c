/*
*******************************************************************************
*                                    usb host module
*
*                             Copyright(C), 2006-2008, SoftWinners Co., Ltd.
*                                                  All Rights Reserved
*
* File Name :
*
* Author : javen
*
* Version : 1.0
*
* Date : 2008.07.xx
*
* Description :
*
* History :
*******************************************************************************
*/
//#include "usb_host_config.h"

//#include "usb_host_base_types.h"
#include <stdio.h>
#include "usb_utils_find_zero_bit.h"
#define FIND_NEXT_ZERO_BIT_MAX_SIZE     (128)
#define FIND_NEXT_ZERO_BIT_NOT_FOUND        (0xffffffff)


/*
******************************************************************************
*
*             find_next_zero_bit
*
* Description:
*     nintbit0bit.
*
* Parameters:
*     addr    :   .
*     size    :   n,(32 * n).
*     offset  :   bit.
*
*  Return value:
*     0bit0xffffffff
*
******************************************************************************
*/
u32 find_next_zero_bit(const volatile u32 *addr, u32 size, u32 offset)
{
    u32 *p = (u32 *) addr ;
    u32 bit = FIND_NEXT_ZERO_BIT_NOT_FOUND;
    int k;      //
    int i, j;
    int n;      //int
    int m;      //
    n = size / 32;
    k = 32 - (offset % 32);
    m = offset / 32;

    //offset0 ~ size-1
    if (size > FIND_NEXT_ZERO_BIT_MAX_SIZE || offset >= size || m > n)
    {
        return bit;
    }

    //offsize
    for (j = 0; j < (n - m); j++)
    {
        if (j == 0) //offsize
        {
            for (i = 0; i < k; i++)
            {
                if (((*(p + m + j) >> ((offset % 32) + i))) & 0x01)
                {
                    continue;
                }
                else
                {
                    bit = (offset + i);
                    return bit;
                }
            }
        }
        else  //offsizej
        {
            for (i = 0; i < 32; i++)
            {
                if ((*(p + m + j) >> i) & 0x01)
                {
                    continue;
                }
                else
                {
                    //                  bit = (offset+(j*32)+i);
                    bit = ((j * 32) + i);
                    return bit;
                }
            }
        }
    }

    //addroffsize
    for (j = 0; j <= m; j++)
    {
        if (j != m) //addr
        {
            for (i = 0; i < 32; i++)
            {
                if (((*(p + j) >> i)) & 0x01)
                {
                    continue;
                }
                else
                {
                    bit = i + (j * 32);
                    return bit;
                }
            }
        }
        else  //offsize
        {
            for (i = 0; i < (32 - k); i++)
            {
                if (((*(p + j) >> i)) & 0x01)
                {
                    continue;
                }
                else
                {
                    bit = i + (j * 32);
                    return bit;
                }
            }
        }
    }

    return bit;
}

