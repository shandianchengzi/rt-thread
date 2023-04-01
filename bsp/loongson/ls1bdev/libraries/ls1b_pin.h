/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-06            first version
 */

// (gpiopwm)

#ifndef __LOONGSON_PIN_H
#define __LOONGSON_PIN_H


// 
typedef enum
{
    PIN_PURPOSE_GPIO = 0,               // gpio
    PIN_PURPOSE_OTHER,                  // (gpio)
}pin_purpose_t;


// 
typedef enum
{
    PIN_REMAP_FIRST = 0,                // 
    PIN_REMAP_SECOND,                   // 
    PIN_REMAP_THIRD,                    // 
    PIN_REMAP_FOURTH,                   // 
    PIN_REMAP_FIFTH,                    // 
    PIN_REMAP_DEFAULT,                //
}pin_remap_t;


/*
 * pin(gpiogpio)
 * @gpio gpio
 * @purpose 
 */
void pin_set_purpose(unsigned int gpio, pin_purpose_t purpose);


/*
 * pinn
 * @gpio gpio
 * @remap n
 */
void pin_set_remap(unsigned int gpio, pin_remap_t remap);


#endif

