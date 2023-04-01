/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-06            first version
 */


#ifndef __OPENLOONGSON_CLOCK_H
#define __OPENLOONGSON_CLOCK_H



/*
 * PLL
 * @ret PLL
 */
unsigned long clk_get_pll_rate(void);


/*
 * CPU
 * @ret CPU
 */
unsigned long clk_get_cpu_rate(void);



/*
 * DDR
 * @ret DDR
 */
unsigned long clk_get_ddr_rate(void);


/*
 * APB
 * @ret APB
 */
unsigned long clk_get_apb_rate(void);


/*
 * DC
 * @ret DC
 */
unsigned long clk_get_dc_rate(void);



#endif

