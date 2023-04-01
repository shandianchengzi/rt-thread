/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-06            first version
 */


#ifndef __OPENLOONGSON_GPIO_H
#define __OPENLOONGSON_GPIO_H



// 1cgpio0,1,2,3,4...
// 32
// 32gpio"port"gpio"pin"
// port = gpio / 32
// pin  = gpio % 32
// GPIO50port=1,pin=18
#define GPIO_GET_PORT(gpio)                 ((gpio) / 32)
#define GPIO_GET_PIN(gpio)                  ((gpio) % 32)


// gpio--
typedef enum{
    gpio_mode_output = 0,       // 
    gpio_mode_input = 1         // 
}gpio_mode_t;


//  gpio
typedef enum{
    gpio_level_low = 0,         // 
    gpio_level_high = 1         // 
}gpio_level_t;


typedef enum {
    // 
	IRQ_TYPE_EDGE_RISING	= 0x00000001,
	// 
	IRQ_TYPE_EDGE_FALLING	= 0x00000002,
	IRQ_TYPE_EDGE_BOTH	= (IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING),
	// 
	IRQ_TYPE_LEVEL_HIGH	= 0x00000004,
	// 
	IRQ_TYPE_LEVEL_LOW	= 0x00000008,
	IRQ_TYPE_LEVEL_MASK	= (IRQ_TYPE_LEVEL_LOW | IRQ_TYPE_LEVEL_HIGH),	
}gpio_irq_type_t;



/*
 * gpioCFG
 * @gpio gpio
 * @ret CFG
 */
volatile unsigned int *gpio_get_cfg_reg(unsigned int gpio);

/*
 * gpio
 * @gpio gpio[0, 127]
 * @mode gpio()
 *
 * : gpio50
 * gpio_init(50, gpio_mode_output);
 */
void gpio_init(unsigned int gpio, gpio_mode_t mode);


/*
 * gpio
 * @gpio gpio[0, 127]
 * @level 
 *
 * : gpio50
 * gpio_set(50, gpio_level_low);
 */
void gpio_set(unsigned int gpio, gpio_level_t level);



/*
 * gpio
 * @gpio gpio[0,127]
 *
 * : gpio50
 * gpio_level_t level;
 * level = gpio_get(50);
 */
unsigned int gpio_get(unsigned int gpio);



/**
 * 
 * @gpio gpio
 * @type  or 
 */
void gpio_set_irq_type(unsigned int gpio, gpio_irq_type_t type);



#endif

