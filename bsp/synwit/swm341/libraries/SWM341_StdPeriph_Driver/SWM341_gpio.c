/******************************************************************************************************************************************
* : SWM341_gpio.c
* : SWM341
* : http://www.synwit.com.cn/e/tool/gbook/?bid=1
* :
* : V1.0.0      2016130
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
#include "SWM341.h"
#include "SWM341_gpio.h"


/******************************************************************************************************************************************
* : GPIO_Init()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t dir           0         1 
*           uint32_t pull_up       
*           uint32_t pull_down     
*           uint32_t open_drain    
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_Init(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t dir, uint32_t pull_up, uint32_t pull_down, uint32_t open_drain)
{
    PORT_TypeDef * PORTx = PORTA;

    switch((uint32_t)GPIOx)
    {
    case ((uint32_t)GPIOA):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_GPIOA_Pos);

        PORTx = PORTA;
        break;

    case ((uint32_t)GPIOB):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_GPIOB_Pos);

        PORTx = PORTB;
        break;

    case ((uint32_t)GPIOC):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_GPIOC_Pos);

        PORTx = PORTC;
        break;

    case ((uint32_t)GPIOD):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_GPIOD_Pos);

        PORTx = PORTD;
        break;

    case ((uint32_t)GPIOE):
        SYS->CLKEN1 |= (0x01 << SYS_CLKEN1_GPIOE_Pos);

        PORTx = PORTE;
        break;

    case ((uint32_t)GPIOM):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_GPIOM_Pos);

        PORTx = PORTM;
        break;

    case ((uint32_t)GPION):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_GPION_Pos);

        PORTx = PORTN;
        break;
    }

    PORT_Init(PORTx, n, 0, 1);          //PORTx.PINnGPIO
    if(dir == 1)
    {
        GPIOx->DIR |= (0x01 << n);
    }
    else
    {
        GPIOx->DIR &= ~(0x01 << n);
    }

    if(pull_up == 1)     PORTx->PULLU |=  (1 << n);
    else                 PORTx->PULLU &= ~(1 << n);
    if(pull_down == 1)   PORTx->PULLD |=  (1 << n);
    else                 PORTx->PULLD &= ~(1 << n);
    if(open_drain == 1)  PORTx->OPEND |=  (1 << n);
    else                 PORTx->OPEND &= ~(1 << n);
}

/******************************************************************************************************************************************
* : GPIO_SetBit()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_SetBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    GPIOx->ODR |= (0x01 << n);
}

/******************************************************************************************************************************************
* : GPIO_ClrBit()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_ClrBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    GPIOx->ODR &= ~(0x01 << n);
}

/******************************************************************************************************************************************
* : GPIO_InvBit()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_InvBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    GPIOx->ODR ^= (0x01 << n);
}

/******************************************************************************************************************************************
* : GPIO_GetBit()
* : 
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     :   0    1 
* : 
******************************************************************************************************************************************/
uint32_t GPIO_GetBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    return ((GPIOx->IDR >> n) & 0x01);
}

/******************************************************************************************************************************************
* : GPIO_SetBits()
* : nw
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w             
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_SetBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFF >> (16 - w);

    GPIOx->ODR |= (bits << n);
}

/******************************************************************************************************************************************
* : GPIO_ClrBits()
* : nw
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w             
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_ClrBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFF >> (16 - w);

    GPIOx->ODR &= ~(bits << n);
}

/******************************************************************************************************************************************
* : GPIO_InvBits()
* : nw
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w             
*     : 
* : 
******************************************************************************************************************************************/
void GPIO_InvBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFF >> (16 - w);

    GPIOx->ODR ^= (bits << n);
}

/******************************************************************************************************************************************
* : GPIO_GetBits()
* : nw
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w             
*     : nw 0    1 
*           0n1n+1... ...wn+w
* : 
******************************************************************************************************************************************/
uint32_t GPIO_GetBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFF >> (16 - w);

    return ((GPIOx->IDR >> n) & bits);
}

/******************************************************************************************************************************************
* : GPIO_AtomicSetBit()
* : --ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicSetBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    *(&GPIOx->DATAPIN0 + n) = 1;
}

/******************************************************************************************************************************************
* : GPIO_AtomicClrBit()
* : --ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicClrBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    *(&GPIOx->DATAPIN0 + n) = 0;
}

/******************************************************************************************************************************************
* : GPIO_AtomicInvBit()
* : --ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicInvBit(GPIO_TypeDef * GPIOx, uint32_t n)
{
    *(&GPIOx->DATAPIN0 + n) = 1 - *(&GPIOx->DATAPIN0 + n);
}

/******************************************************************************************************************************************
* : GPIO_AtomicSetBits()
* : nw--ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w      
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicSetBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFF >> (16 - w);

    __disable_irq();
    GPIOx->ODR |= (bits << n);
    __enable_irq();
}

/******************************************************************************************************************************************
* : GPIO_AtomicClrBits()
* : nw--ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w             
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicClrBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFF >> (16 - w);

    __disable_irq();
    GPIOx->ODR &= ~(bits << n);
    __enable_irq();
}

/******************************************************************************************************************************************
* : GPIO_AtomicInvBits()
* : nw--ISR
*     : GPIO_TypeDef * GPIOx      GPIOGPIOAGPIOBGPIOCGPIODGPIOEGPIOMGPION
*           uint32_t n             GPIOPIN0PIN1PIN2... ... PIN14PIN15
*           uint32_t w             
*     : 
* : GPIOx16ISRGPIOxGPIO_Atomic
******************************************************************************************************************************************/
void GPIO_AtomicInvBits(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t w)
{
    uint32_t bits;

    bits = 0xFFFF >> (16 - w);

    __disable_irq();
    GPIOx->ODR ^= (bits << n);
    __enable_irq();
}
