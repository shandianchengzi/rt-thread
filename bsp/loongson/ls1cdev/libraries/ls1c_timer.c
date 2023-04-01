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

#include <ls1c.h>  
#include "ls1c_public.h"
#include "ls1c_pin.h"
#include "ls1c_clock.h"
#include "ls1c_regs.h"
#include "ls1c_pwm.h"
#include "ls1c_timer.h"


// (CNTRHRCLRC)
#define TIMER_COUNTER_MAX               (0xffffff)



/*
 * 
 * @timer 
 * @ret 
 */
unsigned int timer_get_reg_base(ls1c_timer_t timer)
{
    unsigned int reg_base = 0;

    switch (timer)
    {
        case TIMER_PWM0:
            reg_base = LS1C_REG_BASE_PWM0;
            break;

        case TIMER_PWM1:
            reg_base = LS1C_REG_BASE_PWM1;
            break;

        case TIMER_PWM2:
            reg_base = LS1C_REG_BASE_PWM2;
            break;

        case TIMER_PWM3:
            reg_base = LS1C_REG_BASE_PWM3;
            break;
    }

    return reg_base;
}


/*
 * 
 * @timer_info 
 */
void timer_init(timer_info_t *timer_info)
{
    unsigned int timer_reg_base = 0;        // 
    unsigned long timer_clk = 0;            // 
    unsigned long tmp;
    unsigned int ctrl = 0;                  // 
    
    // 
    if (NULL == timer_info)
    {
        return ;
    }

    /*
     * 
     *  =  * (ns) / 1000000000
     * 1cAPB126Mhz
     * 
     */
    timer_clk = clk_get_apb_rate();
    tmp = (timer_clk / 1000000) * (timer_info->time_ns / 1000);     // 100000000010000001000
    tmp = MIN(tmp, TIMER_COUNTER_MAX);

    // 
    ctrl = (1 << LS1C_PWM_INT_LRC_EN)
           | (0 << LS1C_PWM_INT_HRC_EN)
           | (0 << LS1C_PWM_CNTR_RST)
           | (0 << LS1C_PWM_INT_SR)
           | (1 << LS1C_PWM_INTEN)
           | (1 << LS1C_PWM_SINGLE)
           | (1 << LS1C_PWM_OE)
           | (1 << LS1C_PWM_CNT_EN);

    // 
    timer_reg_base = timer_get_reg_base(timer_info->timer);     // 
    reg_write_32(0,                     (volatile unsigned int *)(timer_reg_base + LS1C_PWM_HRC));
    reg_write_32(tmp--,                 (volatile unsigned int *)(timer_reg_base + LS1C_PWM_LRC));
    reg_write_32(0,                     (volatile unsigned int *)(timer_reg_base + LS1C_PWM_CNTR));
    reg_write_32(ctrl,                  (volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));

    return ;
}


/*
 * ()
 * @timer_info 
 * @ret TRUE or FALSE
 */
BOOL timer_is_time_out(timer_info_t *timer_info)
{
    unsigned int timer_reg_base = 0;        // 
    unsigned int ctrl;                      // 
    
    // 
    if (NULL == timer_info)
    {
        return FALSE;
    }

    // 
    timer_reg_base = timer_get_reg_base(timer_info->timer);
    ctrl = reg_read_32((volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));

    // 
    if (ctrl & (1 << LS1C_PWM_INT_SR))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}



/*
 * 
 * @timer_info 
 */
void timer_stop(timer_info_t *timer_info)
{
    unsigned int timer_reg_base = 0;
    
    // 
    if (NULL == timer_info)
    {
        return ;
    }

    timer_reg_base = timer_get_reg_base(timer_info->timer);
    reg_write_32(0, (volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));

    return ;
}

/*
 * ()ns
 * @timer_info 
 * @ret ns
 */
unsigned long timer_get_time_ns(timer_info_t *timer_info)
{
    unsigned int timer_reg_base = 0;
    unsigned int cntr = 0;                  // CNTR
    unsigned long time_ns = 0;              // ns
    unsigned long timer_clk = 0;            // 

    // CNTR
    timer_reg_base = timer_get_reg_base(timer_info->timer);
    cntr = reg_read_32((volatile unsigned int *)(timer_reg_base + LS1C_PWM_CNTR));

    /*
     * CNTRus
     *  = (CNTR * 1000000000) / 
     *   = (CNTR * 1000) / ( / 1000000)
     */
    timer_clk = clk_get_apb_rate();
    time_ns = (cntr * 1000 ) / (timer_clk /1000000);
//    printf("[%s] time_us=%lu, cntr=%d, timer_clk=%d\n", __FUNCTION__, time_ns, cntr, timer_clk);

    return time_ns;
}

/*
 * timer
 * @timer_info 
 */
void timer_print_regs(timer_info_t *timer_info)
{
    unsigned int timer_reg_base = 0;

    timer_reg_base = timer_get_reg_base(timer_info->timer);
    printf("CNTR=0x%x, HRC=0x%x, LRC=0x%x, CTRL=0x%x\n",
              reg_read_32((volatile unsigned int *)(timer_reg_base + LS1C_PWM_CNTR)),
              reg_read_32((volatile unsigned int *)(timer_reg_base + LS1C_PWM_HRC)),
              reg_read_32((volatile unsigned int *)(timer_reg_base + LS1C_PWM_LRC)),
              reg_read_32((volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL)));

    return ;
}

/*
 * 
 * @timer_info 
 */
void timer_int_clr(timer_info_t *timer_info)
{
    unsigned int timer_reg_base = 0;        // 
    unsigned int ctrl ;  
    
    // 
    if (NULL == timer_info)
    {
        return ;
    }
    timer_reg_base = timer_get_reg_base(timer_info->timer);     // 
    ctrl = reg_read_32((volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));
    ctrl = ctrl | (1<<LS1C_PWM_INT_SR) ;
    reg_write_32(ctrl , (volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));
    ctrl = ctrl & (~(1<<LS1C_PWM_INT_SR))  ;
    reg_write_32(ctrl , (volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));

    return ;
}
/*
 * 
 * @timer_info 
 */
void timer_cnt_clr(timer_info_t *timer_info)
{
    unsigned int timer_reg_base = 0;        // 
    unsigned int ctrl ;  
    
    // 
    if (NULL == timer_info)
    {
        return ;
    }
    timer_reg_base = timer_get_reg_base(timer_info->timer);     // 
    ctrl = reg_read_32((volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));
    ctrl = ctrl | (1<<LS1C_PWM_CNTR_RST);
    reg_write_32(ctrl , (volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));
    ctrl = ctrl & (~(1<<LS1C_PWM_CNTR_RST)) ;
    reg_write_32(ctrl , (volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));

    return ;
}

/*
 * 
 * @timer_info 
 * @hrc  lrc  10
*/
void timer_int_init(timer_info_t *timer_info, int hrc, int lrc)
{
    unsigned int timer_reg_base = 0;        // 
    unsigned long timer_clk = 0;            // 
    unsigned long h_value, l_value;
    unsigned int ctrl = 0;                  // 
    
    // 
    if (NULL == timer_info)
    {
        return ;
    }

    /*
     * 
     *  =  * (ns) / 1000000000
     * 1cAPB126Mhz
     * 
     */
    timer_clk = clk_get_apb_rate();
    l_value = (timer_clk / 1000000) * (timer_info->time_ns / 1000);     // 100000000010000001000
    l_value = MIN(l_value, TIMER_COUNTER_MAX);
    h_value = (timer_clk / 1000000) * (timer_info->time_h_ns / 1000);     // 100000000010000001000
    h_value = MIN(h_value, l_value);

    // 
    ctrl = (lrc << LS1C_PWM_INT_LRC_EN)
           | (hrc << LS1C_PWM_INT_HRC_EN)
           | (0 << LS1C_PWM_CNTR_RST)
           | (0 << LS1C_PWM_INT_SR)
           | (1 << LS1C_PWM_INTEN)
           | (1 << LS1C_PWM_SINGLE)
           | (1 << LS1C_PWM_OE)
           | (1 << LS1C_PWM_CNT_EN);

    // 
    timer_reg_base = timer_get_reg_base(timer_info->timer);     // 
    reg_write_32(0,                     (volatile unsigned int *)(timer_reg_base + LS1C_PWM_HRC));
    reg_write_32(l_value--,                 (volatile unsigned int *)(timer_reg_base + LS1C_PWM_LRC));
    reg_write_32(h_value--,                 (volatile unsigned int *)(timer_reg_base + LS1C_PWM_HRC));
    reg_write_32(0,                     (volatile unsigned int *)(timer_reg_base + LS1C_PWM_CNTR));
    reg_write_32(ctrl,                  (volatile unsigned int *)(timer_reg_base + LS1C_PWM_CTRL));

    return ;
}
