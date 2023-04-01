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
/** \file pca.c
 **
 ** pca driver API.
 ** @link pcnt Group Some description @endlink
 **
 **   - 2019-04-09       First Version
 **
 ******************************************************************************/

/******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32l196_pca.h"

/**
 ******************************************************************************
 ** \addtogroup PCNTGroup
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

/**
******************************************************************************
    ** \brief  
    ** @param  IT_Src : 
    ** \retval FALSE TRUE
    **
******************************************************************************/
boolean_t Pca_GetItStatus(en_pca_ccficlr_t It_Src)
{
    return (((M0P_PCA->CCON)>>It_Src) & 1) > 0? TRUE : FALSE;
}

/**
******************************************************************************
    ** \brief  
    ** @param  IT_Src : 
    ** \retval 
    **
******************************************************************************/
void Pca_ClrItStatus(en_pca_ccficlr_t It_Src)
{
    M0P_PCA->ICLR &= ~(uint32_t)(1<<It_Src);
}

/**
******************************************************************************
    ** \brief  PCA    PCA_CCON CR
    ** @param  NewStatus : TRUE  FALSE
    ** \retval 
    **
******************************************************************************/
void Pca_StartPca(boolean_t NewStatus)
{
    SetBit((uint32_t)(&(M0P_PCA->CCON)), 6, NewStatus);
}

/**
******************************************************************************
    ** \brief  PCA IDLEPCA
    ** @param  NewStatus : TRUE  FALSE
    ** \retval 
    **
******************************************************************************/
void Pca_SetCidl(boolean_t NewStatus)
{
    SetBit((uint32_t)(&(M0P_PCA->CMOD)), 7, NewStatus);
}

/**
******************************************************************************
    ** \brief  PCA 4
    ** @param  NewStatus : TRUE  FALSE
    ** \retval 
    **
******************************************************************************/
void Pca_Set4Wdte(boolean_t NewStatus)
{
    SetBit((uint32_t)(&(M0P_PCA->CMOD)), 6, NewStatus);
}

/**
******************************************************************************
    ** \brief  PCA PCA_CMODCFIEPCA_CCONCFPCA_ICLRCF
    ** @param  NewStatus : TRUE  FALSE
    ** \retval 
    **
******************************************************************************/
void Pca_ConfPcaIt(boolean_t NewStatus)
{
    SetBit((uint32_t)(&(M0P_PCA->CMOD)), 0, NewStatus);
}

/**
******************************************************************************
    ** \brief  PCA   PCA_CCAPMxCCIE
    ** @param  Modulex : pca_module0~4
    ** @param  NewStatus : TRUE  FALSE
    ** \retval 
    **
******************************************************************************/
void Pca_ConfModulexIt(en_pca_module_t Modulex, boolean_t NewStatus)
{
    switch(Modulex)
    {
        case PcaModule0:
            SetBit((uint32_t)(&(M0P_PCA->CCAPM0)), 0, NewStatus);
            break;
        case PcaModule1:
            SetBit((uint32_t)(&(M0P_PCA->CCAPM1)), 0, NewStatus);
            break;        
        case PcaModule2:
            SetBit((uint32_t)(&(M0P_PCA->CCAPM2)), 0, NewStatus);
            break;
        case PcaModule3:
            SetBit((uint32_t)(&(M0P_PCA->CCAPM3)), 0, NewStatus);
            break;
        case PcaModule4:
            SetBit((uint32_t)(&(M0P_PCA->CCAPM4)), 0, NewStatus);
            break;
        default:
            break;
    }
}

/**
******************************************************************************
    ** \brief  PCA 0
    ** @param  InitStruct : PCA
    ** \retval 
    **
******************************************************************************/
void Pca_M0Init(stc_pcacfg_t* InitStruct)
{
    M0P_PCA->CMOD_f.CPS = InitStruct->pca_clksrc;
    M0P_PCA->CMOD_f.CIDL = InitStruct->pca_cidl;
    M0P_PCA->CCAPM0_f.ECOM = InitStruct->pca_ecom;
    M0P_PCA->CCAPM0_f.CAPP = InitStruct->pca_capp;
    M0P_PCA->CCAPM0_f.CAPN = InitStruct->pca_capn;
    M0P_PCA->CCAPM0_f.MAT  = InitStruct->pca_mat;
    M0P_PCA->CCAPM0_f.TOG  = InitStruct->pca_tog;
    M0P_PCA->CCAPM0_f.PWM  = InitStruct->pca_pwm;
    M0P_PCA->EPWM_f.EPWM   = InitStruct->pca_epwm;
    if(InitStruct->pca_pwm == PcaPwm8bitEnable)
    {
        M0P_PCA->CCAP0L_f.CCAP0 = InitStruct->pca_ccapl;
        M0P_PCA->CCAP0H_f.CCAP0 = InitStruct->pca_ccaph;
    }
    else
    {
        M0P_PCA->CCAP0_f.CCAP0 = InitStruct->pca_ccap;        
    }
    M0P_PCA->CARR_f.CARR    = InitStruct->pca_carr;
}

/**
******************************************************************************
    ** \brief  PCA 1
    ** @param  InitStruct : PCA
    ** \retval 
    **
******************************************************************************/
void Pca_M1Init(stc_pcacfg_t* InitStruct)
{
    M0P_PCA->CMOD_f.CPS = InitStruct->pca_clksrc;
    M0P_PCA->CMOD_f.CIDL = InitStruct->pca_cidl;
    M0P_PCA->CCAPM1_f.ECOM = InitStruct->pca_ecom;
    M0P_PCA->CCAPM1_f.CAPP = InitStruct->pca_capp;
    M0P_PCA->CCAPM1_f.CAPN = InitStruct->pca_capn;
    M0P_PCA->CCAPM1_f.MAT  = InitStruct->pca_mat;
    M0P_PCA->CCAPM1_f.TOG  = InitStruct->pca_tog;
    M0P_PCA->CCAPM1_f.PWM  = InitStruct->pca_pwm;
    M0P_PCA->EPWM_f.EPWM   = InitStruct->pca_epwm;
    if(InitStruct->pca_pwm == PcaPwm8bitEnable)
    {
        M0P_PCA->CCAP1L_f.CCAP1 = InitStruct->pca_ccapl;
        M0P_PCA->CCAP1H_f.CCAP1 = InitStruct->pca_ccaph;
    }
    else
    {
        M0P_PCA->CCAP1_f.CCAP1 = InitStruct->pca_ccap;        
    }
    M0P_PCA->CARR_f.CARR    = InitStruct->pca_carr;
}

/**
******************************************************************************
    ** \brief  PCA 2
    ** @param  InitStruct : PCA
    ** \retval 
    **
******************************************************************************/
void Pca_M2Init(stc_pcacfg_t* InitStruct)
{
    M0P_PCA->CMOD_f.CPS = InitStruct->pca_clksrc;
    M0P_PCA->CMOD_f.CIDL = InitStruct->pca_cidl;
    M0P_PCA->CCAPM2_f.ECOM = InitStruct->pca_ecom;
    M0P_PCA->CCAPM2_f.CAPP = InitStruct->pca_capp;
    M0P_PCA->CCAPM2_f.CAPN = InitStruct->pca_capn;
    M0P_PCA->CCAPM2_f.MAT  = InitStruct->pca_mat;
    M0P_PCA->CCAPM2_f.TOG  = InitStruct->pca_tog;
    M0P_PCA->CCAPM2_f.PWM  = InitStruct->pca_pwm;
    M0P_PCA->EPWM_f.EPWM   = InitStruct->pca_epwm;
    if(InitStruct->pca_pwm == PcaPwm8bitEnable)
    {
        M0P_PCA->CCAP2L_f.CCAP2 = InitStruct->pca_ccapl;
        M0P_PCA->CCAP2H_f.CCAP2 = InitStruct->pca_ccaph;
    }
    else
    {
        M0P_PCA->CCAP2_f.CCAP2 = InitStruct->pca_ccap;        
    }
    M0P_PCA->CARR_f.CARR    = InitStruct->pca_carr;
}

/**
******************************************************************************
    ** \brief  PCA 3
    ** @param  InitStruct : PCA
    ** \retval 
    **
******************************************************************************/
void Pca_M3Init(stc_pcacfg_t* InitStruct)
{
    M0P_PCA->CMOD_f.CPS = InitStruct->pca_clksrc;
    M0P_PCA->CMOD_f.CIDL = InitStruct->pca_cidl;
    M0P_PCA->CCAPM3_f.ECOM = InitStruct->pca_ecom;
    M0P_PCA->CCAPM3_f.CAPP = InitStruct->pca_capp;
    M0P_PCA->CCAPM3_f.CAPN = InitStruct->pca_capn;
    M0P_PCA->CCAPM3_f.MAT  = InitStruct->pca_mat;
    M0P_PCA->CCAPM3_f.TOG  = InitStruct->pca_tog;
    M0P_PCA->CCAPM3_f.PWM  = InitStruct->pca_pwm;
    M0P_PCA->EPWM_f.EPWM   = InitStruct->pca_epwm;
    if(InitStruct->pca_pwm == PcaPwm8bitEnable)
    {
        M0P_PCA->CCAP3L_f.CCAP3 = InitStruct->pca_ccapl;
        M0P_PCA->CCAP3H_f.CCAP3 = InitStruct->pca_ccaph;
    }
    else
    {
        M0P_PCA->CCAP3_f.CCAP3 = InitStruct->pca_ccap;        
    }
    M0P_PCA->CARR_f.CARR    = InitStruct->pca_carr;
}

/**
******************************************************************************
    ** \brief  PCA 4
    ** @param  InitStruct : PCA
    ** \retval 
    **
******************************************************************************/
void Pca_M4Init(stc_pcacfg_t* InitStruct)
{
    M0P_PCA->CMOD_f.CPS = InitStruct->pca_clksrc;
    M0P_PCA->CMOD_f.CIDL = InitStruct->pca_cidl;
    M0P_PCA->CCAPM4_f.ECOM = InitStruct->pca_ecom;
    M0P_PCA->CCAPM4_f.CAPP = InitStruct->pca_capp;
    M0P_PCA->CCAPM4_f.CAPN = InitStruct->pca_capn;
    M0P_PCA->CCAPM4_f.MAT  = InitStruct->pca_mat;
    M0P_PCA->CCAPM4_f.TOG  = InitStruct->pca_tog;
    M0P_PCA->CCAPM4_f.PWM  = InitStruct->pca_pwm;
    M0P_PCA->EPWM_f.EPWM   = InitStruct->pca_epwm;
    if(InitStruct->pca_pwm == PcaPwm8bitEnable)
    {
        M0P_PCA->CCAP4L_f.CCAP4 = InitStruct->pca_ccapl;
        M0P_PCA->CCAP4H_f.CCAP4 = InitStruct->pca_ccaph;
    }
    else
    {
        M0P_PCA->CCAP4_f.CCAP4 = InitStruct->pca_ccap;        
    }
    M0P_PCA->CARR_f.CARR    = InitStruct->pca_carr;
}

/**
******************************************************************************
    ** \brief  PCA CNT
    ** @param  
    ** \retval CNT
    **
******************************************************************************/
uint16_t Pca_GetCnt(void)
{
    return (uint16_t)(M0P_PCA->CNT);
}

/**
******************************************************************************
    ** \brief  PCA CNT
    ** @param  cnt : 
    ** \retval 
    **
******************************************************************************/
void Pca_SetCnt(uint16_t cnt)
{
    if(GetBit((uint32_t)(&(M0P_PCA->CCON)), 6)==TRUE)
    {
        Pca_StartPca(FALSE);
        M0P_PCA->CNT_f.CNT = cnt;        
        Pca_StartPca(TRUE);        
    }
    else
    {
        M0P_PCA->CNT_f.CNT = cnt;
    }

}

/**
******************************************************************************
    ** \brief  PCA 
    ** @param  Modulex : x=01234
    ** \retval TRUE  FALSE
    **
******************************************************************************/
boolean_t Pca_GetOut(en_pca_module_t Modulex)
{
    return GetBit((uint32_t)(&(M0P_PCA->CCAPO)), Modulex);
}

/**
******************************************************************************
    ** \brief  PCA 16CCAPx
    ** @param  Modulex : x=01234
    ** @param  Value:  
    ** \retval 
    **
******************************************************************************/
void Pca_SetCcap(en_pca_module_t Modulex, uint16_t Value)
{
    switch(Modulex)
    {
        case 0:
            M0P_PCA->CCAP0_f.CCAP0 = Value;
        break;
        case 1:
            M0P_PCA->CCAP1_f.CCAP1 = Value;
            break;
        case 2:
            M0P_PCA->CCAP2_f.CCAP2 = Value;
            break;
        case 3:
            M0P_PCA->CCAP3_f.CCAP3 = Value;
            break;
        case 4:
            M0P_PCA->CCAP4_f.CCAP4 = Value;
            break;
        default:
            break;
    }    
}

/**
******************************************************************************
    ** \brief  PCA 16CCAPx
    ** @param  Modulex : x=01234
    ** \retval CCAPxx=01234
    **
******************************************************************************/
uint16_t Pca_GetCcap(en_pca_module_t Modulex)
{
    uint16_t tmp;
    switch(Modulex)
    {
        case 0:
            tmp = M0P_PCA->CCAP0_f.CCAP0;
        break;
        case 1:
            tmp = M0P_PCA->CCAP1_f.CCAP1;
            break;
        case 2:
            tmp = M0P_PCA->CCAP2_f.CCAP2;
            break;
        case 3:
            tmp = M0P_PCA->CCAP3_f.CCAP3;
            break;
        case 4:
            tmp = M0P_PCA->CCAP4_f.CCAP4;
            break;
        default:
            break;
    }
    return tmp;
}

/**
******************************************************************************
    ** \brief  PCA 
    ** @param  
    ** \retval 
    **
******************************************************************************/
void Pca_SetCarr(uint16_t Value)
{
    M0P_PCA->CARR_f.CARR = Value;
}

/**
******************************************************************************
    ** \brief  PCA 
    ** @param  
    ** \retval 
    **
******************************************************************************/
uint16_t Pca_GetCarr(void)
{
    return M0P_PCA->CARR_f.CARR;
}

/**
******************************************************************************
    ** \brief  PCA 88
    ** @param  Modulex : x=01234
    ** @param  ValueH : 8
    ** @param  ValueL : 8
    ** \retval 
    **
******************************************************************************/
void Pca_SetCcapHL(en_pca_module_t Modulex, uint8_t ValueH, uint8_t ValueL)
{
    switch(Modulex)
    {
        case 0:
            M0P_PCA->CCAP0H_f.CCAP0 = ValueH;
            M0P_PCA->CCAP0L_f.CCAP0 = ValueL;
            break;
        case 1:
            M0P_PCA->CCAP1H_f.CCAP1 = ValueH;
            M0P_PCA->CCAP1L_f.CCAP1 = ValueL;
            break;
        case 2:
            M0P_PCA->CCAP2H_f.CCAP2 = ValueH;
            M0P_PCA->CCAP2L_f.CCAP2 = ValueL;
            break;
        case 3:
            M0P_PCA->CCAP3H_f.CCAP3 = ValueH;
            M0P_PCA->CCAP3L_f.CCAP3 = ValueL;
            break;
        case 4:
            M0P_PCA->CCAP4H_f.CCAP4 = ValueH;
            M0P_PCA->CCAP4L_f.CCAP4 = ValueL;
            break;
        default:
            break;
    }
}

/**
******************************************************************************
    ** \brief  PCA 88
    ** @param  Modulex : x=01234
    ** @param  ValueH : CCAPx8
    ** @param  ValueL : CCAPx8
    ** \retval 
    **
******************************************************************************/
void Pca_GetCcapHL(en_pca_module_t Modulex, uint8_t *ValueH, uint8_t *ValueL)
{
    switch(Modulex)
    {
        case 0:
            *ValueH = M0P_PCA->CCAP0H_f.CCAP0;
            *ValueL = M0P_PCA->CCAP0L_f.CCAP0;
            break;
        case 1:
            *ValueH = M0P_PCA->CCAP1H_f.CCAP1;
            *ValueL = M0P_PCA->CCAP1L_f.CCAP1;
            break;
        case 2:
            *ValueH = M0P_PCA->CCAP2H_f.CCAP2;
            *ValueL = M0P_PCA->CCAP2L_f.CCAP2;
            break;
        case 3:
            *ValueH = M0P_PCA->CCAP3H_f.CCAP3;
            *ValueL = M0P_PCA->CCAP3L_f.CCAP3;
            break;
        case 4:
            *ValueH = M0P_PCA->CCAP4H_f.CCAP4;
            *ValueL = M0P_PCA->CCAP4L_f.CCAP4;
            break;
        default:
            break;
    }    
}
/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/





