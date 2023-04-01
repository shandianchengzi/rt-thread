 /*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 *                             first version
 */
// 


#ifndef __OPENLOONGSON_TIMER_H
#define __OPENLOONGSON_TIMER_H


#include "ls1c_public.h"


// 
typedef enum
{
    TIMER_PWM0,                     // PWM0
    TIMER_PWM1,                     // PWM1
    TIMER_PWM2,                     // PWM2
    TIMER_PWM3                      // PWM3
}ls1c_timer_t;


// 
typedef struct
{
    ls1c_timer_t timer;                  // 
    unsigned long time_ns;          // 
    unsigned long time_h_ns;          // 
}timer_info_t;

/*
 * 
 * @timer_info 
 */
void timer_init(timer_info_t *timer_info);

/*
 * 
 * @timer_info 
 * @ret TRUE or FALSE
 */
BOOL timer_is_time_out(timer_info_t *timer_info);

/*
 * 
 * @timer_info 
 */
void timer_stop(timer_info_t *timer_info);

/*
 * ()ns
 * @timer_info 
 * @ret ns
 */
unsigned long timer_get_time_ns(timer_info_t *timer_info);

/*
 * timer
 * @timer_info 
 */
void timer_print_regs(timer_info_t *timer_info);

/*
 * 
 * @timer_info 
 */
void timer_int_clr(timer_info_t *timer_info);

/*
 * 
 * @timer_info 
 */
void timer_cnt_clr(timer_info_t *timer_info);

/*
 * 
 * @timer_info 
 * @hrc  lrc  10
*/
void timer_int_init(timer_info_t *timer_info, int hrc, int lrc);
#endif

