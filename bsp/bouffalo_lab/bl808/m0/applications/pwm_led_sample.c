/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author         Notes
 * 2023-3-27     wcx1024979076   first version.
 */
/*
 *  PWM 
 *  pwm_led_sample 
 * pwm_led_sample
 *  PWM  LED LED
*/
#include <rtthread.h>
#include <rtdevice.h>

#ifdef RT_USING_PWM

#define LED_PIN_NUM          8     /* LED PINdrv_gpio.c */
#define PWM_DEV_NAME        "pwm"  /* PWM */
#define PWM_DEV_CHANNEL      0       /* PWM */
struct rt_device_pwm *pwm_dev;      /* PWM */
static int pwm_led_sample(int argc, char *argv[])
{
    rt_uint32_t period, pulse, dir;
    period = 500000;    /* 0.5msns */
    dir = 1;            /* PWM */
    pulse = 0;          /* PWMns */

    /*  */
    pwm_dev = (struct rt_device_pwm *)rt_device_find(PWM_DEV_NAME);
    if (pwm_dev == RT_NULL)
    {
        rt_kprintf("pwm sample run failed! can't find %s device!\n", PWM_DEV_NAME);
        return -RT_ERROR;
    }
    /* PWM */
    rt_pwm_set(pwm_dev, PWM_DEV_CHANNEL, period, pulse);
    /*  */
    rt_pwm_enable(pwm_dev, PWM_DEV_CHANNEL);

    while (1)
    {
        rt_thread_mdelay(50);
        if (dir)
        {
            pulse += 400000;      /* 05000ns */
        }
        else
        {
            pulse -= 400000;      /* 5000ns */
        }
        if (pulse >= period)
        {
            dir = 0;
        }
        if (0 == pulse)
        {
            dir = 1;
        }
        /* PWM */
        rt_pwm_set(pwm_dev, PWM_DEV_CHANNEL, period, pulse);
    }
}
/*  msh  */
MSH_CMD_EXPORT(pwm_led_sample, pwm sample);

#endif   /* RT_USING_PWM */
