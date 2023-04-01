/******************************************************************************************************************************************
* : SWM341_wdt.c
* : SWM341WDT
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
#include "SWM341_wdt.h"


/******************************************************************************************************************************************
* : WDT_Init()
* : WDT
*     : WDT_TypeDef * WDTx        WDT
*           uint32_t int_period     1--2^161/10240WDT
*           uint32_t rst_period     1--2^161/10240WDT
*     : 
* : 
******************************************************************************************************************************************/
void WDT_Init(WDT_TypeDef * WDTx, uint32_t int_period, uint32_t rst_period)
{
    SYS->CLKEN0 |= (1 << SYS_CLKEN0_WDT_Pos);

    WDT_Stop(WDTx);     //

    WDTx->CR &= ~WDT_CR_CKDIV_Msk;
    WDTx->CR |= (4 << WDT_CR_CKDIV_Pos);    //  32 

    if(int_period == 0)
    {
        WDTx->CR &= ~(1 << WDT_CR_INTEN_Pos);

        NVIC_DisableIRQ(WDT_IRQn);
    }
    else
    {
        WDTx->CR |=  (1 << WDT_CR_INTEN_Pos);

        WDTx->INTVAL = int_period;

        WDTx->IF = 1;
        NVIC_EnableIRQ(WDT_IRQn);
    }

    if(rst_period == 0)
    {
        WDTx->CR &= ~(1 << WDT_CR_RSTEN_Pos);

        WDTx->RSTVAL = int_period;
    }
    else
    {
        WDTx->CR |=  (1 << WDT_CR_RSTEN_Pos);

        WDTx->RSTVAL = rst_period;
    }
}

/******************************************************************************************************************************************
* : WDT_Start()
* : WDT
*     : WDT_TypeDef * WDTx        WDT
*     : 
* : 
******************************************************************************************************************************************/
void WDT_Start(WDT_TypeDef * WDTx)
{
    WDTx->CR |=  (1 << WDT_CR_EN_Pos);
}

/******************************************************************************************************************************************
* : WDT_Stop()
* : WDT
*     : WDT_TypeDef * WDTx        WDT
*     : 
* : 
******************************************************************************************************************************************/
void WDT_Stop(WDT_TypeDef * WDTx)
{
    WDTx->CR &= ~(1 << WDT_CR_EN_Pos);
}

/******************************************************************************************************************************************
* : WDT_Feed()
* : 
*     : WDT_TypeDef * WDTx        WDT
*     : 
* : 
******************************************************************************************************************************************/
void WDT_Feed(WDT_TypeDef * WDTx)
{
    WDTx->FEED = 0x55;
}

/******************************************************************************************************************************************
* : WDT_INTClr()
* : 
*     : WDT_TypeDef * WDTx        WDT
*     : 
* : 
******************************************************************************************************************************************/
void WDT_INTClr(WDT_TypeDef * WDTx)
{
    WDTx->IF = 1;
}

/******************************************************************************************************************************************
* : WDT_INTStat()
* : 
*     : WDT_TypeDef * WDTx        WDT
*     : int32_t                   1     0 
* : 
******************************************************************************************************************************************/
uint32_t WDT_INTStat(WDT_TypeDef * WDTx)
{
    return WDTx->IF;
}
