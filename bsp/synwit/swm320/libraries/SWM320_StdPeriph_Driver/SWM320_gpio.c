/******************************************************************************************************************************************
* : SWM320_gpio.c
* : SWM320
* : http://www.synwit.com.cn/e/tool/gbook/?bid=1
* :
* : V1.1.0      20171025
* :
*
*
*******************************************************************************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS WITH CODING INFORMATION
* REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME. AS A RESULT, SYNWIT SHALL NOT BE HELD LIABLE
* FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
* OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN CONN-
* -ECTION WITH THEIR PRODUCTS.
*
* COPYRIGHT 2012 Synwit Technology
*******************************************************************************************************************************************/
#include "SWM320.h"
#include "SWM320_gpio.h"


/******************************************************************************************************************************************
* : GPIO_Init()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN22PIN23
*           uint32_t dir           0         1 
*           uint32_t pull_up       0     1 
*           uint32_t pull_down     0     1 
*     : 
* : GPIOAGPIOCGPIOMGPIOPGPIOBGPIONPN0PN1PN2
******************************************************************************************************************************************/
void GPIO_Init(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t dir, uint32_t pull_up, uint32_t pull_down)
{
    switch((uint32_t)GPIOx)
    {
    case ((uint32_t)GPIOA):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_GPIOA_Pos);

        PORT_Init(PORTA, n, 0, 1);          //PORTA.PINnGPIO
        if(dir == 1)
        {
            GPIOA->DIR |= (0x01 << n);
        }
        else
        {
            GPIOA->DIR &= ~(0x01 << n);
        }

        if(pull_up == 1)
            PORT->PORTA_PULLU |= (0x01 << n);
        else
            PORT->PORTA_PULLU &= ~(0x01 << n);
        break;

    case ((uint32_t)GPIOB):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_GPIOB_Pos);

        PORT_Init(PORTB, n, 0, 1);          //PORTB.PINnGPIO
        if(dir == 1)
        {
            GPIOB->DIR |= (0x01 << n);
        }
        else
        {
            GPIOB->DIR &= ~(0x01 << n);
        }

        if(pull_down == 1)
            PORT->PORTB_PULLD |= (0x01 << n);
        else
            PORT->PORTB_PULLD &= ~(0x01 << n);
        break;

    case ((uint32_t)GPIOC):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_GPIOC_Pos);

        PORT_Init(PORTC, n, 0, 1);          //PORTC.PINnGPIO
        if(dir == 1)
        {
            GPIOC->DIR |= (0x01 << n);
        }
        else
        {
            GPIOC->DIR &= ~(0x01 << n);
        }

        if(pull_up == 1)
            PORT->PORTC_PULLU |= (0x01 << n);
        else
            PORT->PORTC_PULLU &= ~(0x01 << n);
        break;

    case ((uint32_t)GPIOM):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_GPIOM_Pos);

        PORT_Init(PORTM, n, 0, 1);          //PORTM.PINnGPIO
        if(dir == 1)
        {
            GPIOM->DIR |= (0x01 << n);
        }
        else
        {
            GPIOM->DIR &= ~(0x01 << n);
        }

        if(pull_up == 1)
            PORT->PORTM_PULLU |= (0x01 << n);
        else
            PORT->PORTM_PULLU &= ~(0x01 << n);
        break;

    case ((uint32_t)GPION):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_GPION_Pos);

        PORT_Init(PORTN, n, 0, 1);          //PORTN.PINnGPIO
        if(dir == 1)
        {
            GPION->DIR |= (0x01 << n);
        }
        else
        {
            GPION->DIR &= ~(0x01 << n);
        }

        if(pull_down == 1)
            PORT->PORTN_PULLD |= (0x01 << n);
        else
            PORT->PORTN_PULLD &= ~(0x01 << n);
        break;

    case ((uint32_t)GPIOP):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_GPIOP_Pos);

        PORT_Init(PORTP, n, 0, 1);          //PORTP.PINnGPIO
        if(dir == 1)
        {
            GPIOP->DIR |= (0x01 << n);
        }
        else
        {
            GPIOP->DIR &= ~(0x01 << n);
        }

        if(pull_up == 1)
            PORT->PORTP_PULLU |= (0x01 << n);
        else
            PORT->PORTP_PULLU &= ~(0x01 << n);
        break;
    }
}

/******************************************************************************************************************************************
* : GPIO_SetBit()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN22PIN23
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_SetBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    GPIOx->DATA |= (0x01 << n);
}

/******************************************************************************************************************************************
* : GPIO_ClrBit()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN22PIN23
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_ClrBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    GPIOx->DATA &= ~(0x01 << n);
}

/******************************************************************************************************************************************
* : GPIO_InvBit()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN22PIN23
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_InvBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    GPIOx->DATA ^= (0x01 << n);
}

/******************************************************************************************************************************************
* : GPIO_GetBit()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN22PIN23
*     :   0    1 
* : 
******************************************************************************************************************************************/
uint32_t GPIO_GetBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    return ((GPIOx->DATA >> n) & 0x01);
}

/******************************************************************************************************************************************
* : GPIO_SetBits()
* : nw
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN22PIN23
*           uint32_t w             
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_SetBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFFFF >> (24 - w);

    GPIOx->DATA |= (bits << n);
}

/******************************************************************************************************************************************
* : GPIO_ClrBits()
* : nw
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN22PIN23
*           uint32_t w             
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_ClrBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFFFF >> (24 - w);

    GPIOx->DATA &= ~(bits << n);
}

/******************************************************************************************************************************************
* : GPIO_InvBits()
* : nw
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN22PIN23
*           uint32_t w             
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_InvBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFFFF >> (24 - w);

    GPIOx->DATA ^= (bits << n);
}

/******************************************************************************************************************************************
* : GPIO_GetBits()
* : nw
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN22PIN23
*           uint32_t w             
*     : nw 0    1 
*           0n1n+1... ...wn+w
* : 
******************************************************************************************************************************************/
uint32_t GPIO_GetBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFFFF >> (24 - w);

    return ((GPIOx->DATA >> n) & bits);
}

/******************************************************************************************************************************************
* : GPIO_AtomicSetBit()
* : --ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOD
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicSetBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    *((volatile uint32_t *)(0x42000000 + ((uint32_t)&GPIOx->DATA - 0x40000000)*32 + n*4)) = 1;
}

/******************************************************************************************************************************************
* : GPIO_AtomicClrBit()
* : --ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOD
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicClrBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    *((volatile uint32_t *)(0x42000000 + ((uint32_t)&GPIOx->DATA - 0x40000000)*32 + n*4)) = 0;
}

/******************************************************************************************************************************************
* : GPIO_AtomicInvBit()
* : --ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOD
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicInvBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    *((volatile uint32_t *)(0x42000000 + ((uint32_t)&GPIOx->DATA - 0x40000000)*32 + n*4)) = 1 - *((volatile uint32_t *)(0x42000000 + ((uint32_t)&GPIOx->DATA - 0x40000000)*32 + n*4));
}

/******************************************************************************************************************************************
* : GPIO_AtomicSetBits()
* : nw--ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOD
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w      
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicSetBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFFFF >> (24 - w);

    __disable_irq();
    GPIOx->DATA |= (bits << n);
    __enable_irq();
}

/******************************************************************************************************************************************
* : GPIO_AtomicClrBits()
* : nw--ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOD
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w             
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicClrBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFFFF >> (24 - w);

    __disable_irq();
    GPIOx->DATA &= ~(bits << n);
    __enable_irq();
}

/******************************************************************************************************************************************
* : GPIO_AtomicInvBits()
* : nw--ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIOD
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w             
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicInvBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFFFF >> (24 - w);

    __disable_irq();
    GPIOx->DATA ^= (bits << n);
    __enable_irq();
}
