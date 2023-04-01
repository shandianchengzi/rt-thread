/*
 * Copyright (c) 2022 OpenLuat & AirM2M
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __CORE_UART_H__
#define __CORE_UART_H__
#include "bsp_common.h"
/**
 * @brief DMA
 *
 * @param UartID  0~MAXUSART1~UARTX0log
 * @param BaudRate 
 * @param IsRxCacheEnable RX
 * @param DataBits 5~8
 * @param Parity 
 *  UART_PARITY_NONE,
    UART_PARITY_ODD,
    UART_PARITY_EVEN,
 * @param StopBits 
 *  UART_STOP_BIT1,
    UART_STOP_BIT1_5,
    UART_STOP_BIT2,
 * @param CB DMA TXRX
 */
void Uart_BaseInit(uint8_t UartID, uint32_t BaudRate, uint8_t IsRxCacheEnable, uint8_t DataBits, uint8_t Parity, uint8_t StopBits, CBFuncEx_t CB);


void Uart_SetCb(uint8_t UartID, CBFuncEx_t CB);

void Uart_DeInit(uint8_t UartID);
/**
 * @brief bootloader
 *
 * @param UartID  0~MAXUSART1~UARTX0log
 * @param Data
 * @param Len
 */
void Uart_BlockTx(uint8_t UartID, uint8_t *Data, uint32_t Len);

void Uart_NoBlockTx(uint8_t UartID, uint8_t Data);

void Uart_EnableRxIrq(uint8_t UartID);

void Uart_EnableTxDoneIrq(uint8_t UartID);
/**
 * @brief DMA
 *
 * @param UartID  0~5
 * @param Stream DMA
 * @param Channel DMA
 * @return >0 
 */
int Uart_DMATxInit(uint8_t UartID, uint8_t Stream, uint32_t Channel);

int Uart_DMARxInit(uint8_t UartID, uint8_t Stream, uint32_t Channel);

/**
 * @brief DMAAPP
 *
 * @param UartID  0~5
 * @param Stream DMA
 * @param Data
 * @param Len
 */
void Uart_DMATx(uint8_t UartID, uint8_t Stream, const uint8_t *Data, uint32_t Len);

void Uart_DMARx(uint8_t UartID, uint8_t Stream, uint8_t *Data, uint32_t Len);

uint32_t Uart_RxBufferRead(uint8_t UartID, uint8_t *Data, uint32_t Len);

void Uart_RxBufferCB(uint8_t UartID, CBFuncEx_t CB);

uint32_t Uart_FifoRead(uint8_t UartID, uint8_t *Data);
/**
 * @brief FIFO
 *
 * @param UartID  0~5
 * @param Data
 * @param Len
 * @return <0  =0 fifobuffer_doneall_done >0 fifo
 */
int32_t Uart_BufferTx(uint8_t UartID, const uint8_t *Data, uint32_t Len);
void Uart_BufferTxStop(uint8_t UartID);
void Uart_PrintReg(uint8_t UartID);
void Uart_ChangeBR(uint8_t UartID, uint32_t BaudRate);
uint32_t Uart_GetLastError(uint8_t UartID);
void Uart_GlobalInit(void);
#endif
