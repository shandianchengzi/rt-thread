/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_uart2.c
* Author             : WCH
* Version            : V1.0
* Date               : 2018/12/15
* Description
*******************************************************************************/

#include "CH57x_common.h"

/*******************************************************************************
* Function Name  : UART2_DefInit
* Description    : 
* Input          : None
* Return         : None
*******************************************************************************/
void UART2_DefInit( void )
{
    UART2_BaudRateCfg( 115200 );
    R8_UART2_FCR = (2<<6) | RB_FCR_TX_FIFO_CLR | RB_FCR_RX_FIFO_CLR | RB_FCR_FIFO_EN;       // FIFO4
    R8_UART2_LCR = RB_LCR_WORD_SZ;
    R8_UART2_IER = RB_IER_TXD_EN;
    R8_UART2_DIV = 1;
}

/*******************************************************************************
* Function Name  : UART2_BaudRateCfg
* Description    : 
* Input          :
* Return         :
*******************************************************************************/
void UART2_BaudRateCfg( UINT32 baudrate )
{
    UINT32  x;

    x = 10 * GetSysClock() / 8 / baudrate;
    x = ( x + 5 ) / 10;
    R16_UART2_DL = (UINT16)x;
}

/*******************************************************************************
* Function Name  : UART2_ByteTrigCfg
* Description    : 
* Input          : b: 
                    refer to UARTByteTRIGTypeDef
* Return         :
*******************************************************************************/
void UART2_ByteTrigCfg( UARTByteTRIGTypeDef b )
{
    R8_UART2_FCR = (R8_UART2_FCR&~RB_FCR_FIFO_TRIG)|(b<<6);
}

/*******************************************************************************
* Function Name  : UART2_INTCfg
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
void UART2_INTCfg( UINT8 s,  UINT8 i )
{
    if( s )
    {
        R8_UART2_IER |= i;
        R8_UART2_MCR |= RB_MCR_INT_OE;
    }
    else
    {
        R8_UART2_IER &= ~i;
    }
}

/*******************************************************************************
* Function Name  : UART2_Reset
* Description    : 
* Input          : None
* Return         : None
*******************************************************************************/
void UART2_Reset( void )
{
    R8_UART2_IER = RB_IER_RESET;
}

/*******************************************************************************
* Function Name  : UART2_SendString
* Description    : 
* Input          : buf - 
                     l - 
* Return         : None
*******************************************************************************/
void UART2_SendString( PUINT8 buf, UINT16 l )
{
    UINT16 len = l;

    while(len)
    {
        if(R8_UART2_TFC != UART_FIFO_SIZE)
        {
            R8_UART2_THR = *buf++;
            len--;
        }
    }
}

/*******************************************************************************
* Function Name  : UART2_RecvString
* Description    : 
* Input          : buf - 
* Return         : 
*******************************************************************************/
UINT16 UART2_RecvString( PUINT8 buf )
{
    UINT16 len = 0;

    while( R8_UART2_RFC )
    {
        *buf++ = R8_UART2_RBR;
        len ++;
    }

    return (len);
}


