/******************************************************************************************************************************************
* : SWM320_flash.c
* : IAPFlashEEPROM
* : http://www.synwit.com.cn/e/tool/gbook/?bid=1
* :
* : V1.1.0      20171025
* :
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
#include "SWM320_flash.h"


IAP_Cache_Reset_t IAP_Cache_Reset = (IAP_Cache_Reset_t)0x11000601;
IAP_Flash_Param_t IAP_Flash_Param = (IAP_Flash_Param_t)0x11000681;
IAP_Flash_Erase_t IAP_Flash_Erase = (IAP_Flash_Erase_t)0x11000781;
IAP_Flash_Write_t IAP_Flash_Write = (IAP_Flash_Write_t)0x11000801;


/******************************************************************************************************************************************
* : FLASH_Erase()
* : Flash
*     : uint32_t addr         4K Byte
*     : 
* : 
******************************************************************************************************************************************/
void FLASH_Erase(uint32_t addr)
{
    __disable_irq();

    IAP_Flash_Erase(addr / 0x1000);

    IAP_Cache_Reset();

    __enable_irq();
}

/******************************************************************************************************************************************
* : FLASH_Write()
* : Flash
*     : uint32_t addr         
*           uint32_t buff[]         
*           uint32_t count          44
*     : 
* : 44
******************************************************************************************************************************************/
void FLASH_Write(uint32_t addr, uint32_t buff[], uint32_t count)
{
    __disable_irq();

    IAP_Flash_Write(addr, (uint32_t)buff, count/4);

    IAP_Cache_Reset();

    __enable_irq();
}

/******************************************************************************************************************************************
* : Flash_Param_at_xMHz()
* : FlashxMHz
*     : uint32_t x        
*     : 
* : 
******************************************************************************************************************************************/
void Flash_Param_at_xMHz(uint32_t x)
{
    __disable_irq();
    switch(x)
    {
    case 30:
        IAP_Flash_Param(0x489, 0xabf41f25);
        break;

    case 40:
        IAP_Flash_Param(0x489, 0xabf42929);
        break;

    case 80:
        IAP_Flash_Param(0x489, 0xabf8524d);
        break;

    case 120:
    default:
        IAP_Flash_Param(0x48a, 0xabfc7a6e);
        break;
    }
    __enable_irq();
}
