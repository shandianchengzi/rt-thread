/******************************************************************************************************************************************
* : SWM320_norflash.c
* : SWM320NOR Flash
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
#include "SWM320_norflash.h"


/******************************************************************************************************************************************
* : NORFL_Init()
* : NOR Flash
*     : NORFL_InitStructure * initStruct    NOR Flash
*     : 
* : 
******************************************************************************************************************************************/
void NORFL_Init(NORFL_InitStructure * initStruct)
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

    SYS->CLKEN |= (1 << SYS_CLKEN_NORFL_Pos);

    NORFLC->CR = ((initStruct->DataWidth == 8 ? 1 : 0) << NORFLC_CR_BYTEIF_Pos) |
                 (initStruct->WELowPulseTime << NORFLC_CR_WRTIME_Pos) |
                 (initStruct->OEPreValidTime << NORFLC_CR_RDTIME_Pos);

    NORFLC->IE = 3;
    NORFLC->IF = 3;     // 
    if(initStruct->OperFinishIEn)  NORFLC->IM &= ~(1 << NORFLC_IM_FINISH_Pos);
    else                           NORFLC->IM |=  (1 << NORFLC_IM_FINISH_Pos);
    if(initStruct->OperTimeoutIEn) NORFLC->IM &= ~(1 << NORFLC_IM_TIMEOUT_Pos);
    else                           NORFLC->IM |=  (1 << NORFLC_IM_TIMEOUT_Pos);
}

/******************************************************************************************************************************************
* : NORFL_ChipErase()
* : NOR Flash
*     : 
*     : uint32_t          0     1 
* : 
******************************************************************************************************************************************/
uint32_t NORFL_ChipErase(void)
{
    uint32_t res;

    NORFLC->CMD = (NORFL_CMD_CHIP_ERASE << NORFLC_CMD_CMD_Pos);

    while(((NORFLC->IF & NORFLC_IF_FINISH_Msk) == 0) &&
          ((NORFLC->IF & NORFLC_IF_TIMEOUT_Msk) == 0)) __NOP();

    if(NORFLC->IF & NORFLC_IF_FINISH_Msk)  res = 0;
    else                                   res = 1;

    NORFLC->IF = NORFLC_IF_FINISH_Msk | NORFLC_IF_TIMEOUT_Msk;

    return res;
}

/******************************************************************************************************************************************
* : NORFL_SectorErase()
* : NOR Flash
*     : uint32_t addr     
*     : uint32_t          0     1 
* : MX29LV128DB 88K25564K    MX29LV128DT 25564K88K
******************************************************************************************************************************************/
uint32_t NORFL_SectorErase(uint32_t addr)
{
    uint32_t res;

    NORFLC->ADDR = addr;
    NORFLC->CMD = (NORFL_CMD_SECTOR_ERASE << NORFLC_CMD_CMD_Pos);

    while(((NORFLC->IF & NORFLC_IF_FINISH_Msk) == 0) &&
          ((NORFLC->IF & NORFLC_IF_TIMEOUT_Msk) == 0)) __NOP();

    if(NORFLC->IF & NORFLC_IF_FINISH_Msk)  res = 0;
    else                                   res = 1;

    NORFLC->IF = NORFLC_IF_FINISH_Msk | NORFLC_IF_TIMEOUT_Msk;

    return res;
}

/******************************************************************************************************************************************
* : NORFL_Write()
* : NOR Flash
*     : uint32_t addr     
*           uint32_t data       
*     : uint32_t          0     1 
* : 168
******************************************************************************************************************************************/
uint32_t NORFL_Write(uint32_t addr, uint32_t data)
{
    uint32_t res;

    NORFLC->ADDR = addr;
    NORFLC->CMD = (NORFL_CMD_PROGRAM << NORFLC_CMD_CMD_Pos) | (data << NORFLC_CMD_DATA_Pos);

    while(((NORFLC->IF & NORFLC_IF_FINISH_Msk) == 0) &&
          ((NORFLC->IF & NORFLC_IF_TIMEOUT_Msk) == 0)) __NOP();

    if(NORFLC->IF & NORFLC_IF_FINISH_Msk)  res = 0;
    else                                   res = 1;

    NORFLC->IF = NORFLC_IF_FINISH_Msk | NORFLC_IF_TIMEOUT_Msk;

    return res;
}

/******************************************************************************************************************************************
* : NORFL_Read()
* : NOR Flash
*     : uint32_t addr     
*     : uint32_t          
* : 168
******************************************************************************************************************************************/
uint32_t NORFL_Read(uint32_t addr)
{
    NORFLC->ADDR = addr;
    NORFLC->CMD = (NORFL_CMD_READ << NORFLC_CMD_CMD_Pos);

    return (NORFLC->CMD & NORFLC_CMD_DATA_Msk);
}

/******************************************************************************************************************************************
* : NORFL_ReadID()
* : NOR FlashID
*     : uint32_t id_addr  ID
*     : uint16_t          ID
* : 
******************************************************************************************************************************************/
uint16_t NORFL_ReadID(uint32_t id_addr)
{
    uint16_t id;

    NORFLC->CMD = (NORFL_CMD_AUTO_SELECT << NORFLC_CMD_CMD_Pos);

    NORFLC->ADDR = id_addr;
    NORFLC->CMD = (NORFL_CMD_READ << NORFLC_CMD_CMD_Pos);

    id = NORFLC->CMD & NORFLC_CMD_DATA_Msk;

    NORFLC->CMD = (NORFL_CMD_RESET << NORFLC_CMD_CMD_Pos);  // ID

    return id;
}
