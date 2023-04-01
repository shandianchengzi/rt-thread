/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-05-06     sundm75       first version
 */

#include "ls1c.h"
#include "ls1c_wdog.h"

/*
 WDT_EN;
 WDT_TIMER;
 WDT_SET ;
 0 ;
 0 
*/

static unsigned int WDT_timer = 0;

/*  */
unsigned int Wdog_Init(void)              
{
    return 0;
}

/* (WDT_EN) */
unsigned int Wdog_Enable(void)       
{
    unsigned int ctrl;
    ctrl = (WDT_EN);
    ctrl |= 0x01;

    WDT_EN = ctrl;
    return 0;
}

/* (WDT_EN) */
unsigned int Wdog_Disable(void)           
{
    unsigned int ctrl;
    ctrl = (WDT_EN);
    ctrl &= ~0x01;
    WDT_EN = ctrl;
    return 0;
}

/*  (WDT_SET) */
unsigned int Wdog_Set(void)               
{
    unsigned int ctrl;
    ctrl = (WDT_SET);
    ctrl |= 0x01;
    WDT_SET = ctrl;
    return 0;
}

/*  (WDT_SET) */
unsigned int Wdog_Reset(void)             
{
    unsigned int ctrl;
    ctrl = (WDT_SET);
    ctrl &= ~0x01;
    WDT_SET = ctrl;
    return 0;
}

/* (WDT_timer) */
unsigned int Wdog_GetValue(void)          
{
    unsigned int cnt;
    cnt = (WDT_TIMER);
    return cnt;
}

/* (WDT_timer)*/
unsigned int Wdog_LoadValue(unsigned int cnt)    
{
    WDT_TIMER = cnt;
    WDT_timer = cnt;
    return 0;
}

/*  */
unsigned int Wdog_GetPreValue(void)    
{
    return WDT_timer;
}
