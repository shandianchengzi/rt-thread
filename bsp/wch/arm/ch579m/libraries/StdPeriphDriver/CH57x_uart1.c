/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_uart1.c
* Author             : WCH
* Version            : V1.0
* Date               : 2018/12/15
* Description
*******************************************************************************/

#include "CH57x_common.h"

/*******************************************************************************
* Function Name  : UART1_DefInit
* Description    : 
* Input          : None
* Return         : None
*******************************************************************************/
void UART1_DefInit( void )
{
    UART1_BaudRateCfg( 115200 );
    R8_UART1_FCR = (2<<6) | RB_FCR_TX_FIFO_CLR | RB_FCR_RX_FIFO_CLR | RB_FCR_FIFO_EN;       // FIFO4
    R8_UART1_LCR = RB_LCR_WORD_SZ;
    R8_UART1_IER = RB_IER_TXD_EN;
    R8_UART1_DIV = 1;
}

/*******************************************************************************
* Function Name  : UART1_BaudRateCfg
* Description    : 
* Input          :
* Return         :
*******************************************************************************/
void UART1_BaudRateCfg( UINT32 baudrate )
{
    UINT32  x;

    x = 10 * GetSysClock() / 8 / baudrate;
    x = ( x + 5 ) / 10;
    R16_UART1_DL = (UINT16)x;
}

/*******************************************************************************
* Function Name  : UART1_ByteTrigCfg
* Description    : 
* Input          : b: 
                    refer to UARTByteTRIGTypeDef
* Return         :
*******************************************************************************/
void UART1_ByteTrigCfg( UARTByteTRIGTypeDef b )
{
    R8_UART1_FCR = (R8_UART1_FCR&~RB_FCR_FIFO_TRIG)|(b<<6);
}

/*******************************************************************************
* Function Name  : UART1_INTCfg
* Description    : 
* Input          : s:  
                    ENABLE  - 
                    DISABLE - 
                   i:  
                    RB_IER_MODEM_CHG  -  UART0 
                    RB_IER_LINE_STAT  - 
                    RB_IER_THR_EMPTY  - 
                    RB_IER_RECV_RDY   - 
* Return         : None
*******************************************************************************/
void UART1_INTCfg( UINT8 s,  UINT8 i )
{
    if( s )
    {
        R8_UART1_IER |= i;
        R8_UART1_MCR |= RB_MCR_INT_OE;
    }
    else
    {
        R8_UART1_IER &= ~i;
    }
}

/*******************************************************************************
* Function Name  : UART1_Reset
* Description    : 
* Input          : None
* Return         : None
*******************************************************************************/
void UART1_Reset( void )
{
    R8_UART1_IER = RB_IER_RESET;
}

/*******************************************************************************
* Function Name  : UART1_SendString
* Description    : 
* Input          : buf - 
                     l - 
* Return         : None
*******************************************************************************/
void UART1_SendString( PUINT8 buf, UINT16 l )
{
    UINT16 len = l;

    while(len)
    {
        if(R8_UART1_TFC != UART_FIFO_SIZE)
        {
            R8_UART1_THR = *buf++;
            len--;
        }
    }
}

/*******************************************************************************
* Function Name  : UART1_RecvString
* Description    : 
* Input          : buf - 
* Return         : 
*******************************************************************************/
UINT16 UART1_RecvString( PUINT8 buf )
{
    UINT16 len = 0;

    while( R8_UART1_RFC )
    {
        *buf++ = R8_UART1_RBR;
        len ++;
    }

    return (len);
}


