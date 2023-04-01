/******************************************************************************************************************************************
* : SWM341_lcd.c
* : SWM341LCD
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
#include "SWM341_lcd.h"

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
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_LCD_Pos);
        break;
    }

    LCDx->CR  = ((initStruct->ClkDiv - 2)  << LCD_CR_CLKDIV_Pos)   |
                (initStruct->SampleEdge    << LCD_CR_CLKINV_Pos)   |
                (1                         << LCD_CR_CLKALW_Pos)   |
                ((initStruct->Format & 1)  << LCD_CR_FORMAT_Pos)   |
                ((initStruct->Format >> 1) << LCD_CR_SEREN_Pos)    |
                (1                         << LCD_CR_BURSTEN_Pos)  |
                (0                         << LCD_CR_BURSTLEN_Pos) |
                ((1-initStruct->IntEOTEn)  << LCD_CR_AUTORESTA_Pos);

    LCDx->CRH = ((initStruct->HsyncWidth - 1) << LCD_CRH_HSW_Pos) |
                ((initStruct->Hbp - 1)        << LCD_CRH_HBP_Pos) |
                ((initStruct->HnPixel - 1)    << LCD_CRH_PIX_Pos) |
                ((initStruct->Hfp - 1)        << LCD_CRH_HFP_Pos);

    LCDx->CRV = ((initStruct->VsyncWidth - 1) << LCD_CRV_VSW_Pos) |
                ((initStruct->Vbp - 1)        << LCD_CRV_VBP_Pos) |
                ((initStruct->VnPixel - 1)    << LCD_CRV_PIX_Pos) |
                ((initStruct->Vfp - 1)        << LCD_CRV_VFP_Pos);

    LCDx->BGC = initStruct->Background;

    LCDx->L[0].LCR = (1    << LCD_LCR_EN_Pos)   |
                     (0    << LCD_LCR_CKEN_Pos) |
                     (0xFF << LCD_LCR_ALPHA_Pos);

    LCDx->L[0].WHP = (0                         << LCD_WHP_STA_Pos) |
                     ((initStruct->HnPixel - 1) << LCD_WHP_STP_Pos);

    LCDx->L[0].WVP = (0                         << LCD_WVP_STA_Pos) |
                     ((initStruct->VnPixel - 1) << LCD_WVP_STP_Pos);

    LCDx->L[0].ADDR = initStruct->DataSource;

    LCDx->L[0].LLEN = (initStruct->HnPixel - 1);

    LCDx->IF = 1;   //
    LCDx->IE = initStruct->IntEOTEn;

    switch((uint32_t)LCDx)
    {
    case ((uint32_t)LCD):
        if(initStruct->IntEOTEn) NVIC_EnableIRQ(LCD_IRQn);
        break;
    }
}

/******************************************************************************************************************************************
* : LCD_LayerInit()
* : LCD
*     : LCD_TypeDef * LCDx    LCDLCD
*           uint32_t layerx     LCDLCD_LAYER_1LCD_LAYER_2
*           LCD_LayerInitStructure * initStruct    LCD
*     : 
* : 
******************************************************************************************************************************************/
void LCD_LayerInit(LCD_TypeDef * LCDx, uint32_t layerx, LCD_LayerInitStructure * initStruct)
{
    LCDx->L[layerx].LCR = (1                 << LCD_LCR_EN_Pos)   |
                          (0                 << LCD_LCR_CKEN_Pos) |
                          (initStruct->Alpha << LCD_LCR_ALPHA_Pos);

    LCDx->L[layerx].WHP = (initStruct->HStart << LCD_WHP_STA_Pos) |
                          (initStruct->HStop  << LCD_WHP_STP_Pos);

    LCDx->L[layerx].WVP = (initStruct->VStart << LCD_WVP_STA_Pos) |
                          (initStruct->VStop  << LCD_WVP_STP_Pos);

    LCDx->L[layerx].ADDR = initStruct->DataSource;

    LCDx->L[layerx].LLEN = (initStruct->HStop - initStruct->HStart);

    LCD->CR |= (1 << LCD_CR_VBPRELOAD_Pos);
}

/******************************************************************************************************************************************
* : LCD_SetLayerPos()
* : LCD
*     : LCD_TypeDef * LCDx    LCDLCD
*           uint32_t layerx     LCDLCD_LAYER_1LCD_LAYER_2
*           uint16_t hstart, uint16_t hstop, uint16_t vstart, uint16_t vstop LCD_LayerInitStructure
*     : 
* : 
******************************************************************************************************************************************/
void LCD_SetLayerPos(LCD_TypeDef * LCDx, uint32_t layerx, uint16_t hstart, uint16_t hstop, uint16_t vstart, uint16_t vstop)
{
    LCDx->L[layerx].WHP = (hstart << LCD_WHP_STA_Pos) |
                          (hstop  << LCD_WHP_STP_Pos);

    LCDx->L[layerx].WVP = (vstart << LCD_WVP_STA_Pos) |
                          (vstop  << LCD_WVP_STP_Pos);

    LCD->CR |= (1 << LCD_CR_VBPRELOAD_Pos);
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
    LCDx->START |= (1 << LCD_START_GO_Pos);
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
    LCDx->IE = 1;
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
    LCDx->IE = 0;
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
*     : uint32_t          0    0 
* : 
******************************************************************************************************************************************/
uint32_t LCD_INTStat(LCD_TypeDef * LCDx)
{
    return (LCDx->IF & 1);
}


/******************************************************************************************************************************************
* : MPULCD_Init()
* : MPU LCD
*     : LCD_TypeDef * LCDx    LCDLCD
*           MPULCD_InitStructure * initStruct    MPU LCD
*     : 
* : 
******************************************************************************************************************************************/
void MPULCD_Init(LCD_TypeDef * LCDx, MPULCD_InitStructure * initStruct)
{
    switch((uint32_t)LCDx)
    {
    case ((uint32_t)LCD):
        SYS->CLKEN0 |= (0x01 << SYS_CLKEN0_LCD_Pos);
        __NOP();__NOP();__NOP();
        break;
    }

    LCDx->CR  = (1              << LCD_CR_MPUEN_Pos) |
                (LCD_FMT_RGB565 << LCD_CR_FORMAT_Pos);  //MPURGB565

    LCDx->L[0].LCR |= (1 << LCD_LCR_EN_Pos);            //MPULayer1

    LCDx->MPUCR = ((initStruct->RDHoldTime    - 1) << LCD_MPUCR_RDHOLD_Pos) |
                  ((initStruct->WRHoldTime    - 1) << LCD_MPUCR_WRHOLD_Pos) |
                  ((initStruct->CSFall_WRFall - 1) << LCD_MPUCR_CS0WR0_Pos) |
                  ((initStruct->WRRise_CSRise - 1) << LCD_MPUCR_WR1CS1_Pos) |
                  ((initStruct->RDCSRise_Fall - 1) << LCD_MPUCR_RCS1_0_Pos) |
                  ((initStruct->WRCSRise_Fall - 1) << LCD_MPUCR_WCS1_0_Pos);
}

void LCD_WR_REG(LCD_TypeDef * LCDx, uint16_t reg)
{
    LCDx->MPUIR = reg;
    while(LCD_IsBusy(LCDx)) __NOP();
}

void LCD_WR_DATA(LCD_TypeDef * LCDx, uint16_t val)
{
    LCDx->MPUDR = val;
    while(LCD_IsBusy(LCDx)) __NOP();
}

void LCD_WriteReg(LCD_TypeDef * LCDx, uint16_t reg, uint16_t val)
{
    LCDx->MPUIR = reg;
    while(LCD_IsBusy(LCDx)) __NOP();

    LCDx->MPUDR = val;
    while(LCD_IsBusy(LCDx)) __NOP();
}

uint16_t LCD_ReadReg(LCD_TypeDef * LCDx, uint16_t reg)
{
    LCDx->MPUIR = reg;
    while(LCD_IsBusy(LCDx)) __NOP();

    return LCDx->MPUDR;
}

/******************************************************************************************************************************************
* : MPULCD_DMAStart()
* : MPU LCD DMA
*     : LCD_TypeDef * LCDx    LCDLCD
*           uint32_t * buff     
*           uint16_t hpix       
*           uint16_t vpix       
*     : 
* : 
******************************************************************************************************************************************/
void MPULCD_DMAStart(LCD_TypeDef * LCDx, uint32_t * buff, uint16_t hpix, uint16_t vpix)
{
    LCDx->MPUAR = (uint32_t)buff;

    LCDx->MPULEN = ((vpix - 1) << LCD_MPULEN_VPIX_Pos) |
                   ((hpix - 1) << LCD_MPULEN_HPIX_Pos);

    LCDx->START |= (1 << LCD_START_GO_Pos);
}

/******************************************************************************************************************************************
* : MPULCD_DMABusy()
* : MPU LCD DMA
*     : LCD_TypeDef * LCDx    LCDLCD
*     : uint32_t          1    0 
* : 
******************************************************************************************************************************************/
uint32_t MPULCD_DMABusy(LCD_TypeDef * LCDx)
{
    return (LCDx->START & LCD_START_GO_Msk) ? 1 : 0;
}
