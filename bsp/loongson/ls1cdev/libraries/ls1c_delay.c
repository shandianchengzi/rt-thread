/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-06            first version
 */


#include "ls1c_clock.h"




/*
 * ms
 * @j ms
 */
void delay_ms(int j)
{
    int k_max = clk_get_cpu_rate()/1000/92;  // 1000ms
    int k = k_max;

    for ( ; j > 0; j--)
    {
        for (k = k_max; k > 0; k--)
        {
            __asm__ ("nop");        // 
        }
    }

    return ;
}


/*
 * us
 * @n us
 */
void delay_us(int n)
{
    int count_1us = 252000000 / 1000000 / 84;           // 1us
                    // 252000000cpu1000000us92
    int count_max;                                      // n
    int tmp;

    // 
    count_max = n * count_1us;
    if (10 >= n)                // <=10us
    {
        count_max = count_max / 3;
    }
    else if (100 >= n)          // <= 100us
    {
        count_max = count_max - count_max / 5;
    }
    else                        // > 100us
    {
        count_max = count_max - count_max / 10;
    }

    // 
    for (tmp = count_max; tmp > 0; tmp--)
    {
        __asm__ ("nop");        //             
    }

    return ;
}


/*
 * s
 * @i s
 */
void delay_s(int i)
{
    for ( ; i > 0; i--)
    {
        delay_ms(1000);
    }

    return ;
}



