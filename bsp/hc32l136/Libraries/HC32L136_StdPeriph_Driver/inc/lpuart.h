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
#include "interrupts_hc32l136.h"

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

typedef enum en_lpuart_channel
{
    LPUART0 = 0u, ///<2
    LPUART1 = 1u, ///<3
}en_lpuart_channel_t;
/**
 ******************************************************************************
 ** \brief lpuart sclk
 ******************************************************************************/

typedef enum en_lpuart_sclk_sel
{
    LPUart_Pclk   = 0u, ///<pclk
    LPUart_Pclk_1 = 1u, ///<pclk
    LPUart_Xtl    = 2u, ///<
    LPUart_Rcl    = 3u, ///<
} en_lpuart_sclksel_t;

/**
 ******************************************************************************
 ** \brief lpuart/
 ******************************************************************************/
typedef enum en_lpuart_mmdorck
{
    LPUartDataOrAddr = 0u, ///<SBUF[8]
    LPUartEven       = 1u, ///<   
    LPUartOdd        = 2u, ///<    
}en_lpuart_mmdorck_t;

/**
 ******************************************************************************
 ** \brief lpuart
 ******************************************************************************/
typedef enum en_lpuart_multimode
{
    LPUartNormal = 0u, ///<
    LPUartMulti  = 1u, ///<
}en_lpuart_multimode_t;
/**
 ******************************************************************************
 ** \brief lpuart
 ******************************************************************************/

typedef struct stc_lpuart_multimode
{
    en_lpuart_multimode_t enMulti_mode; ///<
    uint8_t             u8SlaveAddr;  ///<
    uint8_t                u8SaddEn;  ///<
}stc_lpuart_multimode_t;

/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/

typedef enum en_lpuart_mode
{
    LPUartMode0 = 0u, ///<0    
    LPUartMode1 = 1u, ///<1
    LPUartMode2 = 2u, ///<2
    LPUartMode3 = 3u, ///<3
} en_lpuart_mode_t;
/**
 ******************************************************************************
 ** \brief lpuart stop
 ******************************************************************************/

typedef enum en_lpuart_stop
{
    LPUart1bit  = 0u, ///<1 
    LPUart15bit = 1u, ///<1.5
    LPUart2bit  = 2u, ///<2
} en_lpuart_stop_t;
/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/
typedef enum en_lpuart_func
{
    LPUartTx     = 0u, ///<mode0TX    
    LPUartRx     = 1u, ///<mode0RX and TX ,mode0RX  
    LPUartDmaTx  = 3u, ///<DMA
    LPUartDmaRx  = 4u, ///<DMA
    LPUartCtsRts = 5u, ///<
}en_lpuart_func_t;
/**
 ******************************************************************************
 ** \brief lpuart
 ******************************************************************************/
typedef enum en_lpuart_irq_sel
{
    LPUartTxIrq  = 0u,  ///<        
    LPUartRxIrq  = 1u,  ///<
    LPUartFEIrq  = 3u,  ///<
    LPUartCtsIrq = 4u,  ///<CTS
    LPUartPEIrq  = 5u,  ///<
    LPUartTxEIrq = 6u,  ///<TX   
}en_lpuart_irq_sel_t;
/**
 ******************************************************************************
 ** \brief lpuart
 ******************************************************************************/

typedef struct stc_lpuart_irq_cb
{
    func_ptr_t pfnTxIrqCb;    ///<     
    func_ptr_t pfnRxFEIrqCb;  ///<
    func_ptr_t pfnRxIrqCb;    ///< 
    func_ptr_t pfnCtsIrqCb;   ///<CTS 
    func_ptr_t pfnPEIrqCb;    ///< 
}stc_lpuart_irq_cb_t;
/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/
typedef enum en_lpuart_status
{
    LPUartCts   = 0u,  ///<CTS
    LPUartRC    = 1u,  ///<
    LPUartTC    = 2u,  ///<
    LPUartPE    = 3u,  ///<
    LPUartFE    = 4u,  ///<  
    LPUartCtsIf = 5u,  ///CTS
    LPUartTxe   = 6u,  ///TXbuff
}en_lpuart_status_t;
/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/
typedef struct stc_lpuart_instance_data
{   
    uint32_t               u32Idx;               ///< 
    M0P_LPUART_TypeDef     *pstcInstance;        ///< 
    stc_lpuart_irq_cb_t    stcLPUartInternIrqCb;   ///< 
} stc_lpuart_instance_data_t;
/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/
typedef enum en_lpuart_clkdiv
{
    LPUart16Or32Div = 0u,///<01/316232
    LPUart8Or16Div  = 1u,///<01/38216
    LPUart4Or8Div   = 2u,///<01/3428
}en_lpuart_clkdiv_t;
/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/
typedef struct stc_lpuart_sclk_sel
{
    en_lpuart_clkdiv_t  enSclk_Prs; ///<
    en_lpuart_sclksel_t enSclk_sel; ///<
}stc_lpuart_sclk_sel_t;
/**
 ******************************************************************************
 ** \brief lpuart 
 ******************************************************************************/
typedef struct stc_lpuart_baud
{
    uint32_t             u32Sclk;        ///<sclk
    en_lpuart_mode_t     enRunMode;      ///< 
    uint32_t             u32Baud;        ///< 
} stc_lpuart_baud_t;
/**
 ******************************************************************************
 ** \lpuart 
 ******************************************************************************/

typedef struct stc_lpuart_config
{
    en_lpuart_mode_t       enRunMode;      ///< 
    stc_lpuart_sclk_sel_t* pstcLpuart_clk; ///<
    en_lpuart_stop_t       enStopBit;      ///<
    stc_lpuart_multimode_t* pstcMultiMode; ///<
    stc_lpuart_irq_cb_t*  pstcIrqCb;       ///<          
    boolean_t           bTouchNvic;      ///<NVIC    
} stc_lpuart_config_t;
//
en_result_t LPUart_EnableIrq(uint8_t u8Idx,
                           en_lpuart_irq_sel_t enIrqSel);
en_result_t LPUart_DisableIrq(uint8_t u8Idx,
                            en_lpuart_irq_sel_t enIrqSel);
// 
en_result_t LPUart_Init(uint8_t u8Idx, 
                      stc_lpuart_config_t* pstcConfig);
//LPUART
en_result_t LPUart_SetMode(uint8_t u8Idx,en_lpuart_mode_t enMode);
//LPUART
en_result_t LPUart_SetMultiMode(uint8_t u8Idx,stc_lpuart_multimode_t* pstcMultiConfig);
//LPUART/TB8
en_result_t LPUart_SetMMDOrCk(uint8_t u8Idx,en_lpuart_mmdorck_t enTb8);
//
en_result_t LPUart_SetSaddr(uint8_t u8Idx,uint8_t u8Addr);
//
en_result_t LPUart_SetSaddrEn(uint8_t u8Idx,uint8_t u8Addren);
//
en_result_t LPUart_SetStopBit(uint8_t u8Idx,uint8_t u8Len);
//bit8
boolean_t LPUart_GetRb8(uint8_t u8Idx);
//
en_result_t LPUart_SelSclk(uint8_t u8Idx,en_lpuart_sclksel_t enClk);
//
uint32_t LPUart_GetSclk(uint8_t u8Idx);
//
en_result_t LPUart_SetClkDiv(uint8_t u8Idx,en_lpuart_clkdiv_t enClkDiv);
//
uint16_t LPUart_CalScnt(uint8_t u8Idx,stc_lpuart_baud_t *pstcBaud);
//
en_result_t LPUart_SetBaud(uint8_t u8Idx,uint16_t u16Scnt);
//
uint32_t LPUart_GetBaud(uint8_t u8Idx,uint8_t u8Mode,uint32_t u32Pclk);
                             
//
en_result_t LPUart_EnableFunc(uint8_t u8Idx, en_lpuart_func_t enFunc);
en_result_t LPUart_DisableFunc(uint8_t u8Idx, en_lpuart_func_t enFunc);
//bit
boolean_t LPUart_GetStatus(uint8_t u8Idx,en_lpuart_status_t enStatus);
//bit
en_result_t LPUart_ClrStatus(uint8_t u8Idx,en_lpuart_status_t enStatus);
//
uint8_t LPUart_GetIsr(uint8_t u8Idx);
//
en_result_t LPUart_ClrIsr(uint8_t u8Idx);
//
en_result_t LPUart_SendData(uint8_t u8Idx, uint8_t u8Data);
//
uint8_t LPUart_ReceiveData(uint8_t u8Idx);

//@} // LPUartGroup

#ifdef __cplusplus
#endif

#endif /* __UART_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/



