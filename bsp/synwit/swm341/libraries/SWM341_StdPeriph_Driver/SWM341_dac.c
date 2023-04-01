/******************************************************************************************************************************************
* : SWM341_dac.c
* : SWM341DAC
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
#include "SWM341.h"
#include "SWM341_dac.h"


/******************************************************************************************************************************************
* : DAC_Init()
* : DAC 
*     : DAC_TypeDef * DACx    DACDAC
*           uint32_t format     DAC_FORMAT_LSB12BDAC_FORMAT_MSB12BDAC_FORMAT_8B
*     : 
* : 
******************************************************************************************************************************************/
void DAC_Init(DAC_TypeDef * DACx, uint32_t format)
{
    switch((uint32_t)DACx)
    {
    case ((uint32_t)DAC):
        SYS->CLKEN1 |= (0x01 << SYS_CLKEN1_DAC_Pos);
        break;
    }

    DACx->CR = (format << DAC_CR_DHRFMT_Pos);
}

/******************************************************************************************************************************************
* : DAC_Open()
* : DAC 
*     : DAC_TypeDef * DACx    DACDAC
*     : 
* : 
******************************************************************************************************************************************/
void DAC_Open(DAC_TypeDef * DACx)
{
    DACx->CR |= (1 << ADC_CR_EN_Pos);
}

/******************************************************************************************************************************************
* : DAC_Init()
* : DAC 
*     : DAC_TypeDef * DACx    DACDAC
*     : 
* : 
******************************************************************************************************************************************/
void DAC_Close(DAC_TypeDef * DACx)
{
    DACx->CR &= ~DAC_CR_EN_Msk;
}
