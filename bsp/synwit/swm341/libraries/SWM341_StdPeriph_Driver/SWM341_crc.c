/******************************************************************************************************************************************
* : SWM341_crc.c
* : SWM341CRC
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
#include "SWM341_crc.h"


/******************************************************************************************************************************************
* : CRC_Init()
* : CRC 
*     : CRC_TypeDef * CRCx        CRCCRC
*           CRC_InitStructure * initStruct    CRC
*     : 
* : 
******************************************************************************************************************************************/
void CRC_Init(CRC_TypeDef * CRCx, CRC_InitStructure * initStruct)
{
    switch((uint32_t)CRCx)
    {
    case ((uint32_t)CRC):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_CRC_Pos);
        break;
    }

    CRCx->INIVAL = initStruct->init_crc;

    CRCx->CR = (1 << CRC_CR_EN_Pos) |
               (initStruct->Poly << CRC_CR_POLY_Pos) |
               (initStruct->in_width << CRC_CR_IBIT_Pos) |
               (initStruct->in_rev << CRC_CR_IREV_Pos) |
               (initStruct->in_not << CRC_CR_INOT_Pos) |
               (initStruct->out_rev << CRC_CR_OREV_Pos) |
               (initStruct->out_not << CRC_CR_ONOT_Pos);
}


/******************************************************************************************************************************************
* : CRC_SetInitVal()
* : CRC
*     : CRC_TypeDef * CRCx        CRCCRC
*           uint32_t init_crc       CRC
*     : 
* : 
******************************************************************************************************************************************/
void CRC_SetInitVal(CRC_TypeDef * CRCx, uint32_t init_crc)
{
    CRCx->INIVAL = init_crc;

    CRCx->CR |= (1 << CRC_CR_EN_Pos);
}
