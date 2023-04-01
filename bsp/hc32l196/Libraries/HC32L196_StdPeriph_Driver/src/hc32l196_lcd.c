/******************************************************************************
* Copyright (C) 2019, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by:
* Huada Semiconductor Co.,Ltd ("HDSC").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with HDSC
* components. This software is licensed by HDSC to be adapted only
* for use in systems utilizing HDSC components. HDSC shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. HDSC is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* Disclaimer:
* HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
* WARRANTY OF NONINFRINGEMENT.
* HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
* SAVINGS OR PROFITS,
* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
* FROM, THE SOFTWARE.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/
/******************************************************************************/
/** \file lcd.c
 **
 ** lcd driver API.
 **
 **   - 2019-04-02    First Version
 **
 ******************************************************************************/

/******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32l196_lcd.h"


/**
 ******************************************************************************
 ** \addtogroup AdcGroup
 ******************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/

/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*****************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/
 
/**
******************************************************************************
    ** \brief  LCDINTF
    ** 
    ** @param  
    ** \retval 
    **
******************************************************************************/
boolean_t Lcd_GetItStatus(void)
{
    return (((M0P_LCD->CR1)>>11)&0x01)? TRUE : FALSE;
}

/**
******************************************************************************
    ** \brief  INTF
    ** 
    ** @param  
    ** \retval 
    **
******************************************************************************/
void Lcd_ClearItPendingBit(void)
{
    SetBit((uint32_t)(&(M0P_LCD->INTCLR)), 10, 0);
}

/**
******************************************************************************
    ** \brief  LCD
    **
    ** \param pstcSegComPara stcSegCom
    **
    ** \retval enRet 
    **
******************************************************************************/
en_result_t Lcd_GetSegCom(stc_lcd_segcompara_t *pstcSegComPara,stc_lcd_segcom_t *pstcSegCom)
{
    en_result_t enRet = Error;
    pstcSegCom->stc_seg32_51_com0_8_t.seg32_51_com0_8 = 0xffffffffu;
    pstcSegCom->u32Seg0_31                            = 0xffffffffu;
    if(pstcSegComPara->u8MaxSeg>51)
    {
            return ErrorInvalidParameter;
    }
    switch(pstcSegComPara->LcdBiasSrc)
    {
        case LcdInResHighPower:
        case LcdInResLowPower:
        case LcdInResMidPower:
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Mux = 1;
            break;
        case LcdExtCap:
        case LcdExtRes:
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Mux = 0;
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Seg32_35 = 0;
            break;
        default:
            return ErrorInvalidParameter;
    }
    switch(pstcSegComPara->LcdDuty)
    {
        case LcdStatic:
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Com0_3 = (~1u)&0x0fu;
            break;
        case LcdDuty2:
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Com0_3 = (~3u)&0x0fu;
            break;
        case LcdDuty3:
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Com0_3 = (~7u)&0x0fu;
            break;
        case LcdDuty4:
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Com0_3 = (~15u)&0x0fu;
            break;
        case LcdDuty6:
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Com0_3 = 0;
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Seg39Com4 = 0;
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Seg38Com5 = 0;
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Seg37Com6 = 1;
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Seg36Com7 = 1;
            break;
        case LcdDuty8:
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Com0_3 = 0;
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Seg39Com4 = 0;
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Seg38Com5 = 0;
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Seg37Com6 = 0;
            pstcSegCom->stc_seg32_51_com0_8_t.segcom_bit.Seg36Com7 = 0;
                break;            
        default:
            return ErrorInvalidParameter;
    }
    enRet = Ok;
    return enRet;
}

/**
******************************************************************************
    ** \brief  LCD COMSEGSeg
    **
    ** \param [in] pstcSegCom
    **
    ** \retval enRet 
    **
******************************************************************************/
void Lcd_SetSegCom(stc_lcd_segcom_t *pstcSegCom)
{
    M0P_LCD->POEN0 = pstcSegCom->u32Seg0_31;
    M0P_LCD->POEN1 = pstcSegCom->stc_seg32_51_com0_8_t.seg32_51_com0_8;
}

/**
******************************************************************************
    ** \brief  LCD
    **
    ** \param stcLcdCfg
    **
    ** \retval 
    **
******************************************************************************/
void Lcd_Init(stc_lcd_cfg_t *pstcLcdCfg)
{
    M0P_LCD->CR0_f.BSEL   = pstcLcdCfg->LcdBiasSrc;
    M0P_LCD->CR0_f.DUTY   = pstcLcdCfg->LcdDuty;
    M0P_LCD->CR0_f.BIAS   = pstcLcdCfg->LcdBias;
    M0P_LCD->CR0_f.CPCLK  = pstcLcdCfg->LcdCpClk;
    M0P_LCD->CR0_f.LCDCLK = pstcLcdCfg->LcdScanClk;
    M0P_LCD->CR1_f.MODE   = pstcLcdCfg->LcdMode;
    M0P_LCD->CR1_f.CLKSRC = pstcLcdCfg->LcdClkSrc;
    M0P_LCD->CR0_f.EN     = pstcLcdCfg->LcdEn;
}

/**
******************************************************************************
    ** \brief  
    **
    ** \param  
    **
    ** \retval 
    **
******************************************************************************/
void Lcd_FullDisp(void)
{
    uint8_t tmp;
    volatile uint32_t *ram = NULL;
    ram = &M0P_LCD->RAM0;
    for(tmp=0;tmp<16;tmp++)
    {
        *ram = 0xffffffffu;
        ram++;
    }
}

/**
******************************************************************************
    ** \brief  
    **
    ** \param 
    **
    ** \retval 
    **
******************************************************************************/
void Lcd_ClearDisp(void)
{
    uint8_t tmp;
    volatile uint32_t *ram = NULL;
    ram = &M0P_LCD->RAM0;
    for(tmp=0;tmp<16;tmp++)
    {
            *ram = 0;
            ram++;
    }
}

/**
 ******************************************************************************
 ** \brief  LCD RAM 0-f
 **
 ** \param u8Row RAM0-15u8Data
 **
 ** \retval enRet 
 **
 ******************************************************************************/
en_result_t Lcd_WriteRam(uint8_t u8Row,uint32_t u32Data)
{
    en_result_t  enRet = Error;
    volatile uint32_t *ram = NULL;
    ram = (volatile uint32_t*)&M0P_LCD->RAM0;

    if (u8Row > 15)
    {
        enRet = ErrorInvalidParameter;
        return enRet;
    }
    
    ram += u8Row;
    *ram = u32Data;
    enRet = Ok;
    return  enRet; 
}

/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

