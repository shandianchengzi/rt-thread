/******************************************************************************************************************************************
* : SWM341_iofilt.c
* : SWM341IOPAD
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
#include "SWM341_iofilt.h"


static uint32_t Width[2];


/******************************************************************************************************************************************
* : IOFILT_Init()
* : IO
*     : uint32_t IOFILTn   0-1
*           uint32_t signal      IOFILT0_PB5IOFILT0_PB4...
*           uint32_t width       width  HRC  IOFILT_WIDTH_2IOFILT_WIDTH_4...
*     : 
* : 
******************************************************************************************************************************************/
void IOFILT_Init(uint32_t IOFILTn, uint32_t signal, uint32_t width)
{
    SYS->CLKSEL &= ~SYS_CLKSEL_IOFILT_Msk;
    SYS->CLKSEL |= (0 << SYS_CLKSEL_IOFILT_Pos);    //HRC

    SYS->CLKEN1 |= (1 << SYS_CLKEN1_IOFILT_Pos);

    *(&SYS->IOFILT0 + IOFILTn) = (signal << SYS_IOFILT_IOSEL_Pos)  |
                                 (0      << SYS_IOFILT_CLKDIV_Pos) |
                                 (width  << SYS_IOFILT_TIM_Pos);

    Width[IOFILTn] = width;
}

/******************************************************************************************************************************************
* : IOFILT_Open()
* : IO
*     : uint32_t IOFILTn   0-1
*     : 
* : 
******************************************************************************************************************************************/
void IOFILT_Open(uint32_t IOFILTn)
{
    *(&SYS->IOFILT0 + IOFILTn) |= (Width[IOFILTn] << SYS_IOFILT_TIM_Pos);
}

/******************************************************************************************************************************************
* : IOFILT_Close()
* : IOPAD
*     : uint32_t IOFILTn   0-1
*     : 
* : 
******************************************************************************************************************************************/
void IOFILT_Close(uint32_t IOFILTn)
{
    *(&SYS->IOFILT0 + IOFILTn) &= ~SYS_IOFILT_TIM_Msk;
}
