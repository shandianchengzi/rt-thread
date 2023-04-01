 /*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-02   michael5hzg@gmail.com	adapt to ls1b
 */
// 


#ifndef __LOONGSON_UART_H
#define __LOONGSON_UART_H


#include "ls1b_public.h"


// 
#define LS1B_UART_DAT_OFFSET            (0)
#define LS1B_UART_IER_OFFSET            (1)
#define LS1B_UART_IIR_OFFSET            (2)
#define LS1B_UART_FCR_OFFSET            (2)
#define LS1B_UART_LCR_OFFSET            (3)
#define LS1B_UART_MCR_OFFSET            (4)
#define LS1B_UART_LSR_OFFSET            (5)
#define LS1B_UART_MSR_OFFSET            (6)

#define LS1B_UART_LSB_OFFSET            (0)     // 1
#define LS1B_UART_MSB_OFFSET            (1)     // 2

/* interrupt enable register */
#define	IER_IRxE	0x1	/*  */
#define	IER_ITxE	0x2	/*  */
#define	IER_ILE	    0x4	/*  */
#define	IER_IME	    0x8	/* Modem */

/* interrupt identification register */
#define	IIR_IMASK	0xf	/* mask */
#define	IIR_RXTOUT	0xc	/* receive timeout */
#define	IIR_RLS		0x6	/* receive line status */
#define	IIR_RXRDY	0x4	/* receive ready */
#define	IIR_TXRDY	0x2	/* transmit ready */
#define	IIR_NOPEND	0x1	/* nothing */
#define	IIR_MLSC	0x0	/* modem status */
#define	IIR_FIFO_MASK	0xc0	/* set if FIFOs are enabled */

/* fifo control register */
#define	FIFO_ENABLE		0x01	/* enable fifo */
#define	FIFO_RCV_RST	0x02	/* reset receive fifo */
#define	FIFO_XMT_RST	0x04	/* reset transmit fifo */
#define	FIFO_DMA_MODE	0x08	/* enable dma mode */
#define	FIFO_TRIGGER_1	0x00	/* trigger at 1 char */
#define	FIFO_TRIGGER_4	0x40	/* trigger at 4 chars */
#define	FIFO_TRIGGER_8	0x80	/* trigger at 8 chars */
#define	FIFO_TRIGGER_14	0xc0	/* trigger at 14 chars */

// 
/* character format control register */
#define	CFCR_DLAB	0x80	/* divisor latch */
#define	CFCR_SBREAK	0x40	/* send break */
#define	CFCR_PZERO	0x30	/* zero parity */
#define	CFCR_PONE	0x20	/* one parity */
#define	CFCR_PEVEN	0x10	/* even parity */
#define	CFCR_PODD	0x00	/* odd parity */
#define	CFCR_PENAB	0x08	/* parity enable */
#define	CFCR_STOPB	0x04	/* 2 stop bits */
#define	CFCR_8BITS	0x03	/* 8 data bits */
#define	CFCR_7BITS	0x02	/* 7 data bits */
#define	CFCR_6BITS	0x01	/* 6 data bits */
#define	CFCR_5BITS	0x00	/* 5 data bits */

/* modem control register */
#define	MCR_LOOPBACK	0x10	/* loopback */
#define	MCR_IENABLE	0x08	/* output 2 = int enable */
#define	MCR_DRS		0x04	/* output 1 = xxx */
#define	MCR_RTS		0x02	/* enable RTS */
#define	MCR_DTR		0x01	/* enable DTR */

/* line status register */
#define	LSR_RCV_FIFO	0x80	/* error in receive fifo */
#define	LSR_TSRE	0x40	/* transmitter empty */
#define	LSR_TXRDY	0x20	/* transmitter ready */
#define	LSR_BI		0x10	/* break detected */
#define	LSR_FE		0x08	/* framing error */
#define	LSR_PE		0x04	/* parity error */
#define	LSR_OE		0x02	/* overrun error */
#define	LSR_RXRDY	0x01	/* receiver ready */
#define	LSR_RCV_MASK	0x1f


// 
typedef enum
{
    LS1B_UART00 = 0,        // UART0UART00UART01
    LS1B_UART01,
    LS1B_UART1,
    LS1B_UART2,
    LS1B_UART3,
    LS1B_UART4,
    LS1B_UART5,
    LS1B_UART6,
    LS1B_UART7,
    LS1B_UART8,
    LS1B_UART9,
    LS1B_UART10,
    LS1B_UART11
}ls1b_uart_t;


// 
typedef struct
{
    ls1b_uart_t UARTx;              // 
    unsigned int baudrate;          // 
    BOOL rx_enable;                 // ()
}ls1b_uart_info_t;



/*
 * 
 * @UARTx 
 * @ret 
 */
void *uart_get_base(ls1b_uart_t UARTx);


/*
 * 
 * @uart_info_p 
 */
void uart_init(ls1b_uart_info_t *uart_info_p);


/*
 * 2
 */
void uart2_init(void);


/*
 * 2
 * @str 
 */
void uart2_print(const char *str);


/*
 * 
 * @str 
 */
void uart_debug_print(const char *str);


/*
 * 
 * @ch 
 */
void uart_debug_putc(unsigned char ch);


/*
 * 
 * @uartx 
 * @ch 
 */
void uart_putc(ls1b_uart_t uartx, unsigned char ch);


/*
 * 
 * @uartx 
 * @str 
 */
void uart_print(ls1b_uart_t uartx, const char *str);


#endif

