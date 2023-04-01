/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_uart3.c
* Author             : WCH
* Version            : V1.0
* Date               : 2018/12/15
* Description
*******************************************************************************/

#include "CH57x_common.h"

/*******************************************************************************
* Function Name  : UART3_DefInit
* Description    : 
* Input          : None
* Return         : None
*******************************************************************************/
void UART3_DefInit( void )
{
    UART3_BaudRateCfg( 115200 );
    R8_UART3_FCR = (2<<6) | RB_FCR_TX_FIFO_CLR | RB_FCR_RX_FIFO_CLR | RB_FCR_FIFO_EN;       // FIFO4
    R8_UART3_LCR = RB_LCR_WORD_SZ;
    R8_UART3_IER = RB_IER_TXD_EN;
    R8_UART3_DIV = 1;
}

/*******************************************************************************
* Function Name  : UART3_BaudRateCfg
* Description    : 
* Input          :
* Return         :
*******************************************************************************/
void UART3_BaudRateCfg( UINT32 baudrate )
{
    UINT32  x;

    x = 10 * GetSysClock() / 8 / baudrate;
    x = ( x + 5 ) / 10;
    R16_UART3_DL = (UINT16)x;
}

/*******************************************************************************
* Function Name  : UART3_ByteTrigCfg
* Description    : 
* Input          : b: 
                    refer to UARTByteTRIGTypeDef
* Return         :
*******************************************************************************/
void UART3_ByteTrigCfg( UARTByteTRIGTypeDef b )
{
    R8_UART3_FCR = (R8_UART3_FCR&~RB_FCR_FIFO_TRIG)|(b<<6);
}

/*******************************************************************************
* Function Name  : UART3_INTCfg
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
void UART3_INTCfg( UINT8 s,  UINT8 i )
{
    if( s )
    {
        R8_UART3_IER |= i;
        R8_UART3_MCR |= RB_MCR_INT_OE;
    }
    else
    {
        R8_UART3_IER &= ~i;
    }
}

/*******************************************************************************
* Function Name  : UART3_Reset
* Description    : 
* Input          : None
* Return         : None
*******************************************************************************/
void UART3_Reset( void )
{
    R8_UART3_IER = RB_IER_RESET;
}

/*******************************************************************************
* Function Name  : UART3_SendString
* Description    : 
* Input          : buf - 
                     l - 
* Return         : None
*******************************************************************************/
void UART3_SendString( PUINT8 buf, UINT16 l )
{
    UINT16 len = l;

    while(len)
    {
        if(R8_UART3_TFC != UART_FIFO_SIZE)
        {
            R8_UART3_THR = *buf++;
            len--;
        }
    }
}

/*******************************************************************************
* Function Name  : UART3_RecvString
* Description    : 
* Input          : buf - 
* Return         : 
*******************************************************************************/
UINT16 UART3_RecvString( PUINT8 buf )
{
    UINT16 len = 0;

    while( R8_UART3_RFC )
    {
        *buf++ = R8_UART3_RBR;
        len ++;
    }

    return (len);
}


