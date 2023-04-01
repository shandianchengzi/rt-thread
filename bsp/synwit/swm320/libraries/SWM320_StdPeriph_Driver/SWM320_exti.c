/******************************************************************************************************************************************
* : SWM320_exti.c
* : SWM320
* : http://www.synwit.com.cn/e/tool/gbook/?bid=1
* :
* : V1.1.0      20171025
* :
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
#include "SWM320_exti.h"

/******************************************************************************************************************************************
* : EXTI_Init()
* : 
*     : GPIO_TypeDef * GPIOx  GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n         GPIOPIN0PIN1PIN2... ... PIN22PIN23
*           uint32_t mode      EXTI_FALL_EDGEEXTI_RISE_EDGEEXTI_BOTH_EDGEEXTI_LOW_LEVELEXTI_HIGH_LEVEL
*     : 
* : GPIOAGPIOBGPIOCGPIOMPIN0--7NVICGPIOA0_IRQnNVICGPIOA_IRQn
*           NVIC_EnableIRQ()NVICNVIC_EnableIRQ(GPIOA0_IRQn)NVIC_EnableIRQ(GPIOA_IRQn)
******************************************************************************************************************************************/
void EXTI_Init(GPIO_TypeDef * GPIOx, uint32_t n, uint32_t mode)
{
    EXTI_Close(GPIOx, n);           //

    if(mode & 0x10)
    {
        GPIOx->INTLVLTRG |= (0x01 << n);            //

        if(mode & 0x01)
            GPIOx->INTRISEEN |= (0x01 << n);                //
        else
            GPIOx->INTRISEEN &= ~(0x01 << n);               //
    }
    else
    {
        GPIOx->INTLVLTRG &= ~(0x01 << n);           //

        if(mode & 0x02)
        {
            GPIOx->INTBE |= (0x01 << n);                //
        }
        else
        {
            GPIOx->INTBE &= ~(0x01 << n);               //

            if(mode & 0x01)
                GPIOx->INTRISEEN |= (0x01 << n);            //
            else
                GPIOx->INTRISEEN &= ~(0x01 << n);           //
        }
    }

    GPIOx->INTCLR = (1 << n);       //
}

/******************************************************************************************************************************************
* : EXTI_Open()
* : 
*     : GPIO_TypeDef * GPIOx  GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n         GPIOPIN0PIN1PIN2... ... PIN22PIN23
*     : 
* : 
******************************************************************************************************************************************/
void EXTI_Open(GPIO_TypeDef * GPIOx, uint32_t n)
{
    GPIOx->INTEN |= (0x01 << n);
}

/******************************************************************************************************************************************
* : EXTI_Close()
* : 
*     : GPIO_TypeDef * GPIOx  GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n         GPIOPIN0PIN1PIN2... ... PIN22PIN23
*     : 
* : 
******************************************************************************************************************************************/
void EXTI_Close(GPIO_TypeDef * GPIOx, uint32_t n)
{
    GPIOx->INTEN &= ~(0x01 << n);
}

/******************************************************************************************************************************************
* : EXTI_State()
* : 
*     : GPIO_TypeDef * GPIOx  GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n         GPIOPIN0PIN1PIN2... ... PIN22PIN23
*     : uint32_t  1     0 
* : 
******************************************************************************************************************************************/
uint32_t EXTI_State(GPIO_TypeDef * GPIOx, uint32_t n)
{
    return (GPIOx->INTSTAT >> n) & 0x01;
}

/******************************************************************************************************************************************
* : EXTI_RawState()
* : //
*     : GPIO_TypeDef * GPIOx  GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n         GPIOPIN0PIN1PIN2... ... PIN22PIN23
*     : uint32_t  1 /    0 /
* : 
******************************************************************************************************************************************/
uint32_t EXTI_RawState(GPIO_TypeDef * GPIOx, uint32_t n)
{
    return (GPIOx->INTRAWSTAT >> n) & 0x01;
}

/******************************************************************************************************************************************
* : EXTI_Clear()
* : 
*     : GPIO_TypeDef * GPIOx  GPIOGPIOAGPIOBGPIOCGPIOMGPIONGPIOP
*           uint32_t n         GPIOPIN0PIN1PIN2... ... PIN22PIN23
*     : 
* : 
******************************************************************************************************************************************/
void EXTI_Clear(GPIO_TypeDef * GPIOx, uint32_t n)
{
    GPIOx->INTCLR = (0x01 << n);
}
