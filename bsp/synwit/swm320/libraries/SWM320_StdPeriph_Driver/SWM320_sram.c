/******************************************************************************************************************************************
* : SWM320_sram.c
* : SWM320SRAM
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
#include "SWM320_sram.h"


/******************************************************************************************************************************************
* : SRAM_Init()
* : SRAM
*     : SRAM_InitStructure * initStruct     SRAM 
*     : 
* : 
******************************************************************************************************************************************/
void SRAM_Init(SRAM_InitStructure * initStruct)
{
    uint32_t i;

    // SRAMSDRAM
    do {
        SYS->CLKEN |=  (1 << SYS_CLKEN_SDRAM_Pos);

        while(SDRAMC->REFDONE == 0);
        SDRAMC->REFRESH &= ~(1 << SDRAMC_REFRESH_EN_Pos);

        for(i = 0; i < 1000; i++) __NOP();
        SYS->CLKEN &= ~(1 << SYS_CLKEN_SDRAM_Pos);
    } while(0);

    SYS->CLKEN |= (1 << SYS_CLKEN_RAMC_Pos);
    for(i = 0; i < 10; i++) __NOP();

    SRAMC->CR = (initStruct->ClkDiv << SRAMC_CR_RWTIME_Pos) |
                (initStruct->DataWidth << SRAMC_CR_BYTEIF_Pos) |
                (0 << SRAMC_CR_HBLBDIS_Pos);    // 
}
