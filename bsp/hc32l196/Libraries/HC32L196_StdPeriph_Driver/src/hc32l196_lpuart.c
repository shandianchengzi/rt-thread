/*************************************************************************************
* Copyright (C) 2017, Huada Semiconductor Co.,Ltd All rights reserved.
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
/** \file lpuart.c
 **
 ** LPUART function driver API.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2017-05-17  1.0  CJ First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "hc32l196_lpuart.h"
/**
 ******************************************************************************
 ** \addtogroup LPUartGroup
 ******************************************************************************/
//@{
/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/******************************************************************************/
/* Local variable definitions ('static')                                       */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] LPUARTxenIrqSelor
 **
 ** \retval OK
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_EnableIrq(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_irq_sel_t enIrqSel)
{

    SetBit((uint32_t)(&(LPUARTx->SCON)), enIrqSel, TRUE);

    return Ok;
}
/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] LPUARTxenIrqSelor
 **
 ** \retval OK
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_DisableIrq(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_irq_sel_t enIrqSel)
{

    SetBit((uint32_t)(&(LPUARTx->SCON)), enIrqSel, FALSE);

    return Ok;
}
/**
 ******************************************************************************
 ** \brief lpuart
 **
 ** \param [in] LPUARTxenClk 
 **
 ** \retval Ok 
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_SelSclk(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_sclksel_t enSclk)
{
    ASSERT(IS_VALID_CLK(enSclk));

    LPUARTx->SCON_f.SCLKSEL = enSclk;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] LPUARTxstcMultiCfg
 **
 ** \retval OK
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_SetMultiMode(M0P_LPUART_TypeDef* LPUARTx, stc_lpuart_multimode_t* pstcMultiCfg)
{

    if(NULL != pstcMultiCfg)
    {
        LPUARTx->SCON_f.ADRDET = TRUE;
        LPUARTx->SADDR = pstcMultiCfg->u8SlaveAddr;
        LPUARTx->SADEN = pstcMultiCfg->u8SaddEn;
    }
    else
    {
        return ErrorInvalidParameter;
    }

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] LPUARTx 
 **
 ** \retval Null
 ******************************************************************************/
void LPUart_HdModeEnable(M0P_LPUART_TypeDef* LPUARTx)
{
    LPUARTx->SCON_f.HDSEL = TRUE;
}


/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] LPUARTx 
 **
 ** \retval Null
 ******************************************************************************/
void LPUart_HdModeDisable(M0P_LPUART_TypeDef* LPUARTx)
{
    LPUARTx->SCON_f.HDSEL = FALSE;
}

/**
 ******************************************************************************
 ** \brief  LPUART/TB8
 **
 ** \param [in] LPUARTx 
 ** \param [in] TRUE-TB8FALSE-TB8
 **
 ** \retval Null
 ******************************************************************************/
void LPUart_SetTb8(M0P_LPUART_TypeDef* LPUARTx, boolean_t bTB8Value)
{
    LPUARTx->SCON_f.B8CONT = bTB8Value;

}

/**
 ******************************************************************************
 ** \brief RB8
 **
 ** \param [in] LPUARTx 
 **
 ** \retval RB8
 **\retval ErrorInvalidParameter
 ******************************************************************************/
boolean_t LPUart_GetRb8(M0P_LPUART_TypeDef* LPUARTx)
{
    return (LPUARTx->SBUF_f.DATA8);
}
/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] LPUARTx addr
 **
 ** \retval OK
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_SetSaddr(M0P_LPUART_TypeDef* LPUARTx,uint8_t u8Addr)
{
    LPUARTx->SADDR = u8Addr;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] u8IdxenFunc
 **
 ** \retval OK
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_EnableFunc(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_func_t enFunc)
{
    SetBit((uint32_t)(&(LPUARTx->SCON)), enFunc, TRUE);

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] u8IdxenFunc
 **
 ** \retval OK
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_DisableFunc(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_func_t enFunc)
{
    SetBit((uint32_t)(&(LPUARTx->SCON)), enFunc, FALSE);

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] u8Idx
 **
 ** \retval 
 ******************************************************************************/
uint8_t LPUart_GetIsr(M0P_LPUART_TypeDef* LPUARTx)
{
    return (LPUARTx->ISR);
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] u8IdxenStatus
 **
 ** \retval 
 **\retval ErrorInvalidParameter
 ******************************************************************************/
boolean_t LPUart_GetStatus(M0P_LPUART_TypeDef* LPUARTx,en_lpuart_status_t enStatus)
{
    boolean_t bStatus = FALSE;

    ASSERT(IS_VALID_STATUS(enStatus));

    bStatus =  GetBit((uint32_t)(&(LPUARTx->ISR)), enStatus);

    return bStatus;
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] u8Idx
 **
 ** \retval OK
 ******************************************************************************/
en_result_t LPUart_ClrIsr(M0P_LPUART_TypeDef* LPUARTx)
{
    LPUARTx->ICR = 0u;
    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] u8IdxenStatus
 **
 ** \retval 
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_ClrStatus(M0P_LPUART_TypeDef* LPUARTx,en_lpuart_status_t enStatus)
{
    ASSERT(IS_VALID_STATUS(enStatus));

    SetBit((uint32_t)(&(LPUARTx->ICR)), enStatus, FALSE);

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART,
 **
 ** \param [in] u8IdxData
 **
 ** \retval Ok
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_SendData(M0P_LPUART_TypeDef* LPUARTx, uint8_t u8Data)
{
    while(FALSE == LPUart_GetStatus(LPUARTx,LPUartTxe))
    {}
    LPUARTx->SBUF_f.DATA = u8Data;
    while(FALSE == LPUart_GetStatus(LPUARTx,LPUartTC))
    {}
    LPUart_ClrStatus(LPUARTx,LPUartTC);
    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART,
 **
 ** \param [in] u8IdxData
 **
 ** \retval Ok
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_SendDataIt(M0P_LPUART_TypeDef* LPUARTx, uint8_t u8Data)
{
    LPUARTx->SBUF_f.DATA = u8Data;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] u8Idx
 **
 ** \retval 
 **\retval ErrorInvalidParameter
 ******************************************************************************/
uint8_t LPUart_ReceiveData(M0P_LPUART_TypeDef* LPUARTx)
{
    return (LPUARTx->SBUF_f.DATA);
}

/**
 ******************************************************************************
 ** \brief  LPUART
 **
 ** \param [in] u8IdxpstcCfg  @ref stc_lpuart_cfg_t
 **
 ** \retval OK
 **\retval ErrorInvalidParameter
 ******************************************************************************/
en_result_t LPUart_Init(M0P_LPUART_TypeDef* LPUARTx,stc_lpuart_cfg_t* pstcCfg)
{
    en_result_t enRet = Error;
    const uint32_t u32Over[3] = {0x4, 0x3, 0x2};
    uint16_t u16OverShift;
    float32_t f32Scnt=0;

    if(NULL == pstcCfg)
    {
        return ErrorInvalidParameter;
    }

    LPUARTx->SCON = 0;

    LPUARTx->SCON = (uint32_t)pstcCfg->enStopBit          |
                    (uint32_t)pstcCfg->enMmdorCk          |
                    (uint32_t)pstcCfg->stcBaud.enSclkDiv  |
                    (uint32_t)pstcCfg->stcBaud.enSclkSel  |
                    (uint32_t)pstcCfg->enRunMode;

    if((LPUartMskMode1 == pstcCfg->enRunMode) || (LPUartMskMode3 == pstcCfg->enRunMode))
    {
        u16OverShift = u32Over[pstcCfg->stcBaud.enSclkDiv/LPUartMsk8Or16Div];
        f32Scnt = (float32_t)(pstcCfg->stcBaud.u32Sclk)/(float32_t)(pstcCfg->stcBaud.u32Baud<<u16OverShift);
        LPUARTx->SCNT = (uint16_t)(float32_t)(f32Scnt + 0.5f);
        LPUart_EnableFunc(LPUARTx,LPUartRenFunc);       ///<
    }



    enRet = Ok;
    return enRet;
}
//@} // LPUartGroup
