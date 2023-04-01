/******************************************************************************************************************************************
* : SWM320_crc.c
* : SWM320CRC
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
#include "SWM320_crc.h"


/******************************************************************************************************************************************
* : CRC_Init()
* : CRC 
*     : CRC_TypeDef * CRCx    CRCCRC
*           uint32_t mode       CRC32_IN32CRC32_IN16CRC32_IN8CRC16_IN16CRC16_IN8
*           uint32_t out_not    
*           uint32_t out_rev    
*           uint32_t ini_val    CRC
*     : 
* : 
******************************************************************************************************************************************/
void CRC_Init(CRC_TypeDef * CRCx, uint32_t mode, uint32_t out_not, uint32_t out_rev, uint32_t ini_val)
{
    switch((uint32_t)CRCx)
    {
    case ((uint32_t)CRC):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_CRC_Pos);
        break;
    }

    CRCx->CR = (1 << CRC_CR_EN_Pos) |
               (mode << CRC_CR_CRC16_Pos) |
               (out_not << CRC_CR_ONOT_Pos) |
               (out_rev << CRC_CR_OREV_Pos);

    CRCx->INIVAL = ini_val;
}
