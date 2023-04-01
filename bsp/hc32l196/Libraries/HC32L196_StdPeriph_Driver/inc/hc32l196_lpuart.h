/******************************************************************************
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
/*****************************************************************************/
/** \file lpuart.h
 **
 ** Headerfile for LPUART functions
 **  
 **
 ** History:
 **   - 2017-05-10   Cathy     First Version
 **
 *****************************************************************************/

#ifndef __LPUART_H__
#define __LPUART_H__
/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"


#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup LPUartGroup Universal Asynchronous Receiver/Transmitter (LPUART)
 **
 ******************************************************************************/
//@{

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
 /**
 ******************************************************************************
 **\brief LPuart
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief lpuart sclk
 ******************************************************************************/

typedef enum en_lpuart_sclk_sel
{
    LPUartMskPclk   = 0u<<11, ///<pclk
    LPUartMskXtl    = 2u<<11, ///<
    LPUartMskRcl    = 3u<<11, ///<
} en_lpuart_sclksel_t;

/**
 ******************************************************************************
 ** \brief lpuart/
 ******************************************************************************/
typedef enum en_lpuart_mmdorck
{
    LPUartDataOrAddr = 0u, ///<SBUF[8]
    LPUartEven       = 0x4u, ///<   
    LPUartOdd        = 0x8u, ///<    
}en_lpuart_mmdorck_t;

/**
 ******************************************************************************
 ** \brief lpuart
 ******************************************************************************/

typedef struct stc_lpuart_multimode
{
    uint8_t             u8SlaveAddr;  ///<
    uint8_t             u8SaddEn;  ///<
}stc_lpuart_multimode_t;

/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/

typedef enum en_lpuart_mode
{
    LPUartMskMode0 = 0x00u, ///<0    
    LPUartMskMode1 = 0x40u, ///<1
    LPUartMskMode2 = 0x80u, ///<2
    LPUartMskMode3 = 0xc0u, ///<3
} en_lpuart_mode_t;
/**
 ******************************************************************************
 ** \brief lpuart stop
 ******************************************************************************/

typedef enum en_lpuart_stop
{
    LPUart1bit  = 0x0000u,  ///<1 
    LPUart1_5bit = 0x4000u, ///<1.5
    LPUart2bit  = 0x8000u,  ///<2
} en_lpuart_stop_t;
/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/
typedef enum en_lpuart_func
{
    LPUartRenFunc    = 4u,    ///<0-TX; ///<1-mode0RX&TX ,mode0RX;       
    LPUartDmaRxFunc  = 16u,   ///<DMA   
    LPUartDmaTxFunc  = 17u,   ///<DMA
    LPUartRtsFunc    = 18u,   ///<RTS
    LPUartCtsFunc    = 19u,   ///<CTS
    LPUartHdFunc     = 22u,   ///<    
}en_lpuart_func_t;
/**
 ******************************************************************************
 ** \brief lpuart
 ******************************************************************************/
typedef enum en_lpuart_irq_sel
{
    LPUartRxIrq  = 0u,    ///<
    LPUartTxIrq  = 1u,    ///<        
    LPUartTxEIrq = 8u,    ///<TX
    LPUartPEIrq  = 13u,   ///<
    LPUartCtsIrq = 20u,   ///<CTS    
    LPUartFEIrq  = 21u,   ///< 
}en_lpuart_irq_sel_t;

/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/
typedef enum en_lpuart_status
{
    LPUartRC    = 0u,  ///<
    LPUartTC    = 1u,  ///<
    LPUartFE    = 2u,  ///<
    LPUartTxe   = 3u,  ///<TXbuff    
    LPUartPE    = 4u,  ///<
    LPUartCtsIf = 5u,  ///<CTS
    LPUartCts   = 6u,  ///<CTS
}en_lpuart_status_t;

/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/
typedef enum en_lpuart_clkdiv
{
    LPUartMsk16Or32Div = 0u,        ///<01/316232
    LPUartMsk8Or16Div  = 0x200u,    ///<01/38216
    LPUartMsk4Or8Div   = 0x400u,    ///<01/3428
}en_lpuart_clkdiv_t;

/**
 ******************************************************************************
 ** \brief lpuart Mode1Mode3
 ******************************************************************************/
typedef struct stc_lpuart_baud
{
    en_lpuart_sclksel_t  enSclkSel;      ///<
    en_lpuart_clkdiv_t   enSclkDiv;     ///< 
    uint32_t             u32Sclk;        ///<sclk
    uint32_t             u32Baud;        ///< 
} stc_lpuart_baud_t;
/**
 ******************************************************************************
 ** \lpuart 
 ******************************************************************************/
typedef struct stc_lpuart_cfg
{
    en_lpuart_mode_t       enRunMode;      ///<
    en_lpuart_mmdorck_t    enMmdorCk;      ///<
    en_lpuart_stop_t       enStopBit;      ///<    
    stc_lpuart_baud_t      stcBaud;        ///<Mode1/3                                                        
} stc_lpuart_cfg_t;

// 
en_result_t LPUart_Init(M0P_LPUART_TypeDef* LPUARTx, stc_lpuart_cfg_t* pstcCfg);

// LPUART /
void LPUart_HdModeEnable(M0P_LPUART_TypeDef* LPUARTx);
void LPUart_HdModeDisable(M0P_LPUART_TypeDef* LPUARTx);


//TB8
void LPUart_SetTb8(M0P_LPUART_TypeDef* LPUARTx, boolean_t bTB8Value);

//bit8
boolean_t LPUart_GetRb8(M0P_LPUART_TypeDef* LPUARTx);

//
en_result_t LPUart_EnableIrq(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_irq_sel_t enIrqSel);
en_result_t LPUart_DisableIrq(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_irq_sel_t enIrqSel);

//
en_result_t LPUart_EnableFunc(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_func_t enFunc);
en_result_t LPUart_DisableFunc(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_func_t enFunc);

//
boolean_t LPUart_GetStatus(M0P_LPUART_TypeDef* LPUARTx,en_lpuart_status_t enStatus);
//
en_result_t LPUart_ClrStatus(M0P_LPUART_TypeDef* LPUARTx,en_lpuart_status_t enStatus);
//
uint8_t LPUart_GetIsr(M0P_LPUART_TypeDef* LPUARTx);
//
en_result_t LPUart_ClrIsr(M0P_LPUART_TypeDef* LPUARTx);

//
en_result_t LPUart_SendData(M0P_LPUART_TypeDef* LPUARTx, uint8_t u8Data);
//
en_result_t LPUart_SendDataIt(M0P_LPUART_TypeDef* LPUARTx, uint8_t u8Data);
//
uint8_t LPUart_ReceiveData(M0P_LPUART_TypeDef* LPUARTx);

//LPUARTxenClk 
en_result_t LPUart_SelSclk(M0P_LPUART_TypeDef* LPUARTx, en_lpuart_sclksel_t enSclk);

//LPUART
en_result_t LPUart_SetMultiMode(M0P_LPUART_TypeDef* LPUARTx, stc_lpuart_multimode_t* pstcMultiCfg);

//LPUART
en_result_t LPUart_SetSaddr(M0P_LPUART_TypeDef* LPUARTx,uint8_t u8Addr);

//@} // LPUartGroup

#ifdef __cplusplus
#endif

#endif /* __UART_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/



