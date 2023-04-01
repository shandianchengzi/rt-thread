/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-06            first version
 * 2021-02-02     michael5hzg@gmail.com       adapt to ls1b
 */

// (gpiopwm)


#include "ls1b_public.h"
#include "ls1b_regs.h"
#include "ls1b_gpio.h"
#include "ls1b_pin.h"


/*
 * pin(gpiogpio)
 * @gpio gpio
 * @purpose 
 */
void pin_set_purpose(unsigned int gpio, pin_purpose_t purpose)
{
    volatile unsigned int *gpio_cfgx;           // GPIO_CFGx
    unsigned int pin = GPIO_GET_PIN(gpio);

    gpio_cfgx = gpio_get_cfg_reg(gpio);
    if (PIN_PURPOSE_GPIO == purpose)            // gpio
    {
        reg_set_one_bit(gpio_cfgx, pin);
    }
    else                                        // (gpio)
    {
        reg_clr_one_bit(gpio_cfgx, pin);
    }

    return ;
}



/*
 * pinn
 * @gpio gpio
 * @remap n
 */
void pin_set_remap(unsigned int gpio, pin_remap_t remap)
{
    volatile unsigned int *reg = NULL;          // 
    unsigned int port = GPIO_GET_PORT(gpio);
    unsigned int pin  = GPIO_GET_PIN(gpio);
    int i;

    /*pin0*/
    for (i = 0; i <= 4; i++)
    {
        reg = (volatile unsigned int *)((LS1B_CBUS_FIRST0) + ((port) * 0x04) + ((i) * 0x10));
        // 0
        reg_clr_one_bit(reg, pin);
    }

    if (remap == PIN_REMAP_DEFAULT) return;

    switch (port)
    {
    case 0:
        switch (remap)
        {
        case PIN_REMAP_FIRST:
            reg = (volatile unsigned int *)LS1B_CBUS_FIRST0;
            break;
        case PIN_REMAP_SECOND:
            reg = (volatile unsigned int *)LS1B_CBUS_SECOND0;
            break;
        case PIN_REMAP_THIRD:
            reg = (volatile unsigned int *)LS1B_CBUS_THIRD0;
            break;
        case PIN_REMAP_FOURTH:
            reg = (volatile unsigned int *)LS1B_CBUS_FOURTH0;
            break;
        case PIN_REMAP_FIFTH:
            reg = (volatile unsigned int *)LS1B_CBUS_FIFTH0;
            break;
        }
        break;

    case 1:
        switch (remap)
        {
        case PIN_REMAP_FIRST:
            reg = (volatile unsigned int *)LS1B_CBUS_FIRST1;
            break;
        case PIN_REMAP_SECOND:
            reg = (volatile unsigned int *)LS1B_CBUS_SECOND1;
            break;
        case PIN_REMAP_THIRD:
            reg = (volatile unsigned int *)LS1B_CBUS_THIRD1;
            break;
        case PIN_REMAP_FOURTH:
            reg = (volatile unsigned int *)LS1B_CBUS_FOURTH1;
            break;
        case PIN_REMAP_FIFTH:
            reg = (volatile unsigned int *)LS1B_CBUS_FIFTH1;
            break;
        }
        break;

    case 2:
        switch (remap)
        {
        case PIN_REMAP_FIRST:
            reg = (volatile unsigned int *)LS1B_CBUS_FIRST2;
            break;
        case PIN_REMAP_SECOND:
            reg = (volatile unsigned int *)LS1B_CBUS_SECOND2;
            break;
        case PIN_REMAP_THIRD:
            reg = (volatile unsigned int *)LS1B_CBUS_THIRD2;
            break;
        case PIN_REMAP_FOURTH:
            reg = (volatile unsigned int *)LS1B_CBUS_FOURTH2;
            break;
        case PIN_REMAP_FIFTH:
            reg = (volatile unsigned int *)LS1B_CBUS_FIFTH2;
            break;
        }
        break;

    case 3:
        switch (remap)
        {
        case PIN_REMAP_FIRST:
            reg = (volatile unsigned int *)LS1B_CBUS_FIRST3;
            break;
        case PIN_REMAP_SECOND:
            reg = (volatile unsigned int *)LS1B_CBUS_SECOND3;
            break;
        case PIN_REMAP_THIRD:
            reg = (volatile unsigned int *)LS1B_CBUS_THIRD3;
            break;
        case PIN_REMAP_FOURTH:
            reg = (volatile unsigned int *)LS1B_CBUS_FOURTH3;
            break;
        case PIN_REMAP_FIFTH:
            reg = (volatile unsigned int *)LS1B_CBUS_FIFTH3;
            break;
        }
        break;

    default:
        return ;
    }

    // 1
    reg_set_one_bit(reg, pin);

    return ;
}



