/******************************************************************************************************************************************
* : SWM320_lcd.c
* : SWM320LCD
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
#include "SWM320_lcd.h"

#include <string.h>

/******************************************************************************************************************************************
* : LCD_Init()
* : LCD
*     : LCD_TypeDef * LCDx    LCDLCD
*           LCD_InitStructure * initStruct    LCD
*     : 
* : 
******************************************************************************************************************************************/
void LCD_Init(LCD_TypeDef * LCDx, LCD_InitStructure * initStruct)
{
    switch((uint32_t)LCDx)
    {
    case ((uint32_t)LCD):
        SYS->CLKEN |= (0x01 << SYS_CLKEN_LCD_Pos);
        break;
    }

    LCDx->CR0 = ((initStruct->HnPixel - 1) << LCD_CR0_HPIX_Pos) |
                ((initStruct->VnPixel - 1) << LCD_CR0_VPIX_Pos) |
                (initStruct->ClkAlways << LCD_CR0_DCLK_Pos) |
                (initStruct->HsyncWidth << LCD_CR0_HLOW_Pos);

    LCDx->CR1 = ((initStruct->Hfp - 1) << LCD_CR1_HFP_Pos)  |
                ((initStruct->Hbp - 1) << LCD_CR1_HBP_Pos)  |
                ((initStruct->Vfp - 1) << LCD_CR1_VFP_Pos)  |
                ((initStruct->Vbp - 1) << LCD_CR1_VBP_Pos)  |
                (initStruct->ClkDiv << LCD_CR1_DCLKDIV_Pos) |
                (initStruct->SamplEdge << LCD_CR1_DCLKINV_Pos);

    LCDx->IE = 1;
    LCDx->IF = 1;   //
    if(initStruct->IntEOTEn) LCD_INTEn(LCDx);
    else                     LCD_INTDis(LCDx);

    switch((uint32_t)LCDx)
    {
    case ((uint32_t)LCD):
        if(initStruct->IntEOTEn)
        {
            NVIC_EnableIRQ(LCD_IRQn);
        }
        else
        {
            NVIC_DisableIRQ(LCD_IRQn);
        }
        break;
    }
}

/******************************************************************************************************************************************
* : LCD_Start()
* : 
*     : LCD_TypeDef * LCDx    LCDLCD
*     : 
* : 
******************************************************************************************************************************************/
void LCD_Start(LCD_TypeDef * LCDx)
{
    LCDx->START |= (1 << LCD_START_GO_Pos) | (1 << LCD_START_BURST_Pos);
}

/******************************************************************************************************************************************
* : LCD_IsBusy()
* : 
*     : LCD_TypeDef * LCDx    LCDLCD
*     : uint32_t          1     0 
* : 
******************************************************************************************************************************************/
uint32_t LCD_IsBusy(LCD_TypeDef * LCDx)
{
    return (LCDx->START & LCD_START_GO_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : LCD_INTEn()
* : LCD
*     : LCD_TypeDef * LCDx    LCDLCD
*     : 
* : 
******************************************************************************************************************************************/
void LCD_INTEn(LCD_TypeDef * LCDx)
{
    LCDx->IM = 0;
}

/******************************************************************************************************************************************
* : LCD_INTDis()
* : LCD
*     : LCD_TypeDef * LCDx    LCDLCD
*     : 
* : 
******************************************************************************************************************************************/
void LCD_INTDis(LCD_TypeDef * LCDx)
{
    LCDx->IM = 1;
}

/******************************************************************************************************************************************
* : LCD_INTClr()
* : LCD
*     : LCD_TypeDef * LCDx    LCDLCD
*     : 
* : 
******************************************************************************************************************************************/
void LCD_INTClr(LCD_TypeDef * LCDx)
{
    LCDx->IF = 1;
}

/******************************************************************************************************************************************
* : LCD_INTStat()
* : LCD
*     : LCD_TypeDef * LCDx    LCDLCD
*     : uint32_t          1     0 
* : 
******************************************************************************************************************************************/
uint32_t LCD_INTStat(LCD_TypeDef * LCDx)
{
    return (LCDx->IF & 0x01) ? 1 : 0;
}
