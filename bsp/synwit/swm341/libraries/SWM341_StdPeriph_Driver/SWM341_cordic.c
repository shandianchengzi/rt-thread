/******************************************************************************************************************************************
* : SWM341_cordic.c
* : SWM341CORDIC
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
#include "SWM341_cordic.h"


/******************************************************************************************************************************************
* : CORDIC_Init()
* : CORDIC
*     : CORDIC_TypeDef * CORDICx  CORDICCORDIC
*     : 
* : CORDICDIVCORDIC_Arctan()
******************************************************************************************************************************************/
void CORDIC_Init(CORDIC_TypeDef * CORDICx)
{
    switch((uint32_t)CORDICx)
    {
    case ((uint32_t)CORDIC):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_CORDIC_Pos);
        break;
    }
}
