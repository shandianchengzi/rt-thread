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


#include "ls1b_public.h"
#include "ls1b_regs.h"
#include "ls1b_gpio.h"
#include "ls1b_pin.h"


/*
 * gpioCFG
 * @gpio gpio
 * @ret CFG
 */
volatile unsigned int *gpio_get_cfg_reg(unsigned int gpio)
{
    volatile unsigned int *gpio_cfgx = NULL;            // GPIO_CFGx
    unsigned int port = GPIO_GET_PORT(gpio);

    switch (port)
    {
        case 0:
            gpio_cfgx = (volatile unsigned int *)LS1B_GPIO_CFG0;
            break;

        case 1:
            gpio_cfgx = (volatile unsigned int *)LS1B_GPIO_CFG1;
            break;
        default:
            gpio_cfgx = NULL;
            break;
    }

    return gpio_cfgx;
}


/*
 * gpioEN
 * @gpio gpio
 * @ret EN
 */
volatile unsigned int *gpio_get_en_reg(unsigned int gpio)
{
    volatile unsigned int *gpio_enx = NULL;         // GPIO_ENx
    unsigned int port = GPIO_GET_PORT(gpio);
    
    switch (port)
    {
        case 0:
            gpio_enx = (volatile unsigned int *)LS1B_GPIO_EN0;
            break;

        case 1:
            gpio_enx = (volatile unsigned int *)LS1B_GPIO_EN1;
            break;
        default:
            gpio_enx    = NULL;
            return gpio_enx;
    }

    return gpio_enx;
}

/*
 * gpio
 * @gpio gpio[0, 127]
 * @mode gpio()
 *
 * : gpio50
 * gpio_init(50, gpio_mode_output);
 */
void gpio_init(unsigned int gpio, gpio_mode_t mode)
{
    volatile unsigned int *gpio_enx = NULL;        // GPIO_ENx
    unsigned int pin = GPIO_GET_PIN(gpio);

    // pinGPIO
    pin_set_purpose(gpio, PIN_PURPOSE_GPIO);

    // gpio()
    gpio_enx  = gpio_get_en_reg(gpio);
    if (gpio_mode_output == mode)       // 
    {
        reg_clr_one_bit(gpio_enx, pin);
    }
    else                                // 
    {
        reg_set_one_bit(gpio_enx, pin);
    }

    return ;
}


/*
 * gpio
 * @gpio gpio[0, 127]
 * @level 
 *
 * : gpio50
 * gpio_set(50, gpio_level_low);
 */
void gpio_set(unsigned int gpio, gpio_level_t level)
{
    volatile unsigned int *gpio_outx = NULL;       // GPIO_OUTx
    unsigned int port   = GPIO_GET_PORT(gpio);
    unsigned int pin    = GPIO_GET_PIN(gpio);

    // 
    switch (port)
    {
        case 0:
            gpio_outx = (volatile unsigned int *)LS1B_GPIO_OUT0;
            break;

        case 1:
            gpio_outx = (volatile unsigned int *)LS1B_GPIO_OUT1;
            break;
        default:        // 
            return ;
    }

    // 
    if (gpio_level_low == level)
    {
        reg_clr_one_bit(gpio_outx, pin);
    }
    else
    {
        reg_set_one_bit(gpio_outx, pin);
    }

    return ;
}


/*
 * gpio
 * @gpio gpio[0,127]
 *
 * : gpio50
 * gpio_level_t level;
 * level = gpio_get(50);
 */
unsigned int gpio_get(unsigned int gpio)
{
    volatile unsigned int *gpio_inx = NULL;        // GPIO_INx
    unsigned int port   = GPIO_GET_PORT(gpio);
    unsigned int pin    = GPIO_GET_PIN(gpio);

    // 
    switch (port)
    {
        case 0:
            gpio_inx = (volatile unsigned int *)LS1B_GPIO_IN0;
            break;

        case 1:
            gpio_inx = (volatile unsigned int *)LS1B_GPIO_IN1;
            break;
        default:        // 
            return 0;
    }

    // 
    return reg_get_bit(gpio_inx, pin);
}


/**
 * 
 * @gpio gpio
 * @type  or 
 */
void gpio_set_irq_type(unsigned int gpio, gpio_irq_type_t type)
{
    volatile unsigned int *int_pol = NULL;     // 
    volatile unsigned int *int_edge = NULL;    // 
    unsigned int port = GPIO_GET_PORT(gpio);
    unsigned int pin  = GPIO_GET_PIN(gpio);

    // 
    switch (port)
    {
        case 0:     // GPIO[31:0]
            int_pol     = (volatile unsigned int *)LS1B_INT2_POL;
            int_edge    = (volatile unsigned int *)LS1B_INT2_EDGE;
            break;

        case 1:     // GPIO[63:32]
            int_pol     = (volatile unsigned int *)LS1B_INT3_POL;
            int_edge    = (volatile unsigned int *)LS1B_INT3_EDGE;
            break;

    }

    // 
    switch (type)
    {
        case IRQ_TYPE_EDGE_RISING:
            *int_pol    |= (1 << pin);
            *int_edge   |= (1 << pin);
            break;

        case IRQ_TYPE_EDGE_FALLING:
            *int_pol    &= ~(1 << pin);
            *int_edge   |= (1 << pin);
            break;

        case IRQ_TYPE_LEVEL_HIGH:
            *int_pol    |= (1 << pin);
            *int_edge   &= ~(1 << pin);
            break;

        case IRQ_TYPE_LEVEL_LOW:
            *int_pol    &= ~(1 << pin);
            *int_edge   &= ~(1 << pin);
            break;

        default:
            break;
    }

    return ;
}


    
