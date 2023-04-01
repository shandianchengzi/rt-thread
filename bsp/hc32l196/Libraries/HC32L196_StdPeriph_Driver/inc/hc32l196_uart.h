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
/** \file uart.h
 **
 ** Headerfile for UART functions
 **  
 **
 ** History:
 **   - 2017-05-10   Cathy     First Version
 **
 *****************************************************************************/

#ifndef __UART_H__
#define __UART_H__
/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "hc32l196_ddl.h"


#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup UartGroup Universal Asynchronous Receiver/Transmitter (UART)
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
 **\brief uart
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief uart/
 ******************************************************************************/
typedef enum en_uart_mmdorck
{
    UartMskDataOrAddr = 0u,     ///<SBUF[8]
    UartMskEven       = 0x4u,   ///<   
    UartMskOdd        = 0x8u,   ///<    
}en_uart_mmdorck_t;

/**
 ******************************************************************************
 ** \brief uart
 ******************************************************************************/
typedef struct stc_uart_multimode
{
    uint8_t             u8SlaveAddr;    ///<
    uint8_t             u8SaddEn;       ///<
}stc_uart_multimode_t;

/**
 ******************************************************************************
 ** \brief uart 
 ******************************************************************************/

typedef enum en_uart_mode
{
    UartMskMode0 = 0x00u, ///<0    
    UartMskMode1 = 0x40u, ///<1
    UartMskMode2 = 0x80u, ///<2
    UartMskMode3 = 0xc0u, ///<3
} en_uart_mode_t;
/**
 ******************************************************************************
 ** \brief uart stop
 ******************************************************************************/

typedef enum en_uart_stop
{
    UartMsk1bit   = 0x0000u, ///<1 
    UartMsk1_5bit = 0x4000u, ///<1.5
    UartMsk2bit   = 0x8000u, ///<2
} en_uart_stop_t;
/**
 ******************************************************************************
 ** \brief uart 
 ******************************************************************************/
typedef enum en_uart_func
{
    UartRenFunc    = 4u,    ///<0-TX; ///<1-mode0RX&TX ,mode0RX;       
    UartDmaRxFunc  = 16u,   ///<DMA   
    UartDmaTxFunc  = 17u,   ///<DMA
    UartRtsFunc    = 18u,   ///<RTS
    UartCtsFunc    = 19u,   ///<CTS
    UartHdFunc     = 22u,   ///<    
}en_uart_func_t;
/**
 ******************************************************************************
 ** \brief uart
 ******************************************************************************/
typedef enum en_uart_irq_sel
{
    UartRxIrq  = 0u,    ///<
    UartTxIrq  = 1u,    ///<        
    UartTxEIrq = 8u,    ///<TX
    UartPEIrq  = 13u,   ///<
    UartCtsIrq = 20u,   ///<CTS    
    UartFEIrq  = 21u,   ///< 
}en_uart_irq_sel_t;

/**
 ******************************************************************************
 ** \brief uart 
 ******************************************************************************/
typedef enum en_uart_status
{
    UartRC    = 0u,  ///<
    UartTC    = 1u,  ///<
    UartFE    = 2u,  ///<
    UartTxe   = 3u,  ///<TXbuff    
    UartPE    = 4u,  ///<
    UartCtsIf = 5u,  ///<CTS
    UartCts   = 6u,  ///<CTS
}en_uart_status_t;

/**
 ******************************************************************************
 ** \brief uart 
 ******************************************************************************/
typedef enum en_uart_clkdiv
{
    UartMsk16Or32Div = 0u,      ///<01/316232
    UartMsk8Or16Div  = 0x200u,  ///<01/38216
}en_uart_clkdiv_t;
/**
 ******************************************************************************
 ** \brief uart Mode1Mode3
 ******************************************************************************/
typedef struct stc_uart_baud
{
    en_uart_clkdiv_t     enClkDiv;      ///<
    uint32_t             u32Pclk;       ///<pclk
    uint32_t             u32Baud;       ///<
} stc_uart_baud_t;
/**
 ******************************************************************************
 ** \uart 
 ******************************************************************************/

typedef struct stc_uart_cfg
{
    en_uart_mode_t       enRunMode;     ///<
    en_uart_mmdorck_t    enMmdorCk;     ///<
    en_uart_stop_t       enStopBit;     ///<
    stc_uart_baud_t      stcBaud;       ///<Mode1/3
} stc_uart_cfg_t;

//UART
en_result_t Uart_Init(M0P_UART_TypeDef* UARTx, stc_uart_cfg_t* pstcCfg);

///< UART /
void Uart_HdModeEnable(M0P_UART_TypeDef* UARTx);
void Uart_HdModeDisable(M0P_UART_TypeDef* UARTx);

//UART
en_result_t Uart_SetMultiMode(M0P_UART_TypeDef* UARTx,stc_uart_multimode_t* pstcMultiCfg);

//TB8
void Uart_SetTb8(M0P_UART_TypeDef* UARTx, boolean_t bTB8Value);
//RB8
boolean_t Uart_GetRb8(M0P_UART_TypeDef* UARTx);

//
en_result_t Uart_EnableIrq(M0P_UART_TypeDef* UARTx, en_uart_irq_sel_t enIrqSel);
en_result_t Uart_DisableIrq(M0P_UART_TypeDef* UARTx, en_uart_irq_sel_t enIrqSel);
                             
//
en_result_t Uart_EnableFunc(M0P_UART_TypeDef* UARTx, en_uart_func_t enFunc);
en_result_t Uart_DisableFunc(M0P_UART_TypeDef* UARTx, en_uart_func_t enFunc);

// 
uint8_t Uart_GetIsr(M0P_UART_TypeDef* UARTx);
boolean_t Uart_GetStatus(M0P_UART_TypeDef* UARTx,en_uart_status_t enStatus);
en_result_t Uart_ClrIsr(M0P_UART_TypeDef* UARTx);
en_result_t Uart_ClrStatus(M0P_UART_TypeDef* UARTx,en_uart_status_t enStatus);

//
///< 
en_result_t Uart_SendDataPoll(M0P_UART_TypeDef* UARTx, uint8_t u8Data);
///< 
en_result_t Uart_SendDataIt(M0P_UART_TypeDef* UARTx, uint8_t u8Data);
uint8_t Uart_ReceiveData(M0P_UART_TypeDef* UARTx);

//@} // UartGroup

#ifdef __cplusplus
#endif

#endif /* __UART_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/



