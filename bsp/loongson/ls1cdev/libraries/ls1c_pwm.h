/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-06            first version
 */


#ifndef __OPENLOONGSON_PWM_H
#define __OPENLOONGSON_PWM_H


// pwm
#define LS1C_PWM0_GPIO06                    (6)         // gpio06pwm0
#define LS1C_PWM0_GPIO04                    (4)         // gpio04pwm0
#define LS1C_PWM1_GPIO92                    (92)        // gpio92pwm1
#define LS1C_PWM1_GPIO05                    (5)         // gpio05pwm1
#define LS1C_PWM2_GPIO52                    (52)        // gpio52pwm2
#define LS1C_PWM2_GPIO46                    (46)        // gpio46pwm2
#define LS1C_PWM3_GPIO47                    (47)        // gpio47pwm3
#define LS1C_PWM3_GPIO53                    (53)        // gpio53pwm3
// ...gpiogpio



// pwmbit
#define LS1C_PWM_INT_LRC_EN                 (11)        // 
#define LS1C_PWM_INT_HRC_EN                 (10)        // 
#define LS1C_PWM_CNTR_RST                   (7)         // CNTR
#define LS1C_PWM_INT_SR                     (6)         // 
#define LS1C_PWM_INTEN                      (5)         // 
#define LS1C_PWM_SINGLE                     (4)         // 
#define LS1C_PWM_OE                         (3)         // 
#define LS1C_PWM_CNT_EN                     (0)         // 


// pwm
enum
{
    // --pwm
    PWM_MODE_NORMAL = 0,
    
    // pwm
    PWM_MODE_PULSE
};


// pwm
typedef struct
{
    unsigned int gpio;                      // PWMngpio
    unsigned int mode;                      // ()
    float duty;                             // pwm
    unsigned long period_ns;                // pwm(ns)
}pwm_info_t;




/*
 * PWMn
 * @pwm_info PWMn
 */
void pwm_init(pwm_info_t *pwm_info);


/*
 * pwm
 * @pwm_info PWMn
 */
void pwm_disable(pwm_info_t *pwm_info);



/*
 * PWM
 * @pwm_info PWMn
 */
void pwm_enable(pwm_info_t *pwm_info);


#endif

