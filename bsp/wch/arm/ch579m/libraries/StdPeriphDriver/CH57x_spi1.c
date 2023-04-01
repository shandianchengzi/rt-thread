/********************************** (C) COPYRIGHT *******************************
* File Name          : CH57x_SPI1.c
* Author             : WCH
* Version            : V1.0
* Date               : 2019/4/29
* Description
*******************************************************************************/

#include "CH57x_common.h"


/*******************************************************************************
* Function Name  : SPI1_MasterDefInit
* Description    : 0+3+8MHz
* Input          : None
* Return         : None
*******************************************************************************/
void SPI1_MasterDefInit( void )
{
    R8_SPI1_CLOCK_DIV = 4;      // 4
    R8_SPI1_CTRL_MOD = RB_SPI_ALL_CLEAR;
    R8_SPI1_CTRL_MOD = RB_SPI_MOSI_OE | RB_SPI_SCK_OE ;
    R8_SPI1_CTRL_CFG |= RB_SPI_AUTO_IF;        // BUFFER/FIFOIF_BYTE_END
    R8_SPI1_CTRL_CFG &= ~RB_SPI_DMA_ENABLE;    // DMA
}

/*******************************************************************************
* Function Name  : SPI1_CLKCfg
* Description    : SPI1 = d*Tsys
* Input          : c: 
* Return         : None
*******************************************************************************/
void SPI1_CLKCfg( UINT8 c )
{
    if(c==2)
        R8_SPI1_CTRL_CFG |= RB_SPI_MST_DLY_EN;
    else
        R8_SPI1_CTRL_CFG &= ~RB_SPI_MST_DLY_EN;
    R8_SPI1_CLOCK_DIV = c;
}

/*******************************************************************************
* Function Name  : SPI1_DataMode
* Description    : 
* Input          : m: 
                    refer to ModeBitOrderTypeDef
* Return         : None
*******************************************************************************/
void SPI1_DataMode( ModeBitOrderTypeDef m )
{
    switch( m )
    {
        case Mode0_LowBitINFront:
            R8_SPI1_CTRL_MOD &= ~RB_SPI_MST_SCK_MOD;
            R8_SPI1_CTRL_CFG |= RB_SPI_BIT_ORDER;
            break;
        case Mode0_HighBitINFront:
            R8_SPI1_CTRL_MOD &= ~RB_SPI_MST_SCK_MOD;
            R8_SPI1_CTRL_CFG &= ~RB_SPI_BIT_ORDER;
            break;
        case Mode3_LowBitINFront:
            R8_SPI1_CTRL_MOD |= RB_SPI_MST_SCK_MOD;
            R8_SPI1_CTRL_CFG |= RB_SPI_BIT_ORDER;
            break;
        case Mode3_HighBitINFront:
            R8_SPI1_CTRL_MOD |= RB_SPI_MST_SCK_MOD;
            R8_SPI1_CTRL_CFG &= ~RB_SPI_BIT_ORDER;
            break;
        default:
            break;
    }
}

/*******************************************************************************
* Function Name  : SPI1_MasterSendByte
* Description    :  (buffer)
* Input          : d: 
* Return         : None
*******************************************************************************/
void SPI1_MasterSendByte( UINT8 d )
{
    R8_SPI1_CTRL_MOD &= ~RB_SPI_FIFO_DIR;
    R8_SPI1_BUFFER = d;
    while( !(R8_SPI1_INT_FLAG & RB_SPI_FREE) );
}

/*******************************************************************************
* Function Name  : SPI1_MasterRecvByte
* Description    :  (buffer)
* Input          : None
* Return         : 
*******************************************************************************/
UINT8 SPI1_MasterRecvByte( void )
{
    R8_SPI1_CTRL_MOD &= ~RB_SPI_FIFO_DIR;
    R8_SPI1_BUFFER = 0xFF;           // 
    while( !(R8_SPI1_INT_FLAG & RB_SPI_FREE) );
    return ( R8_SPI1_BUFFER );
}


/*******************************************************************************
* Function Name  : SPI1_MasterTrans
* Description    : FIFO
* Input          : pbuf: 
                   len: 4095
* Return         : None
*******************************************************************************/
void SPI1_MasterTrans( UINT8 *pbuf, UINT16 len )
{
    UINT16 sendlen;

    sendlen = len;
    R8_SPI1_CTRL_MOD &= ~RB_SPI_FIFO_DIR;                     // 
    R16_SPI1_TOTAL_CNT = sendlen;                             // 
    R8_SPI1_INT_FLAG = RB_SPI_IF_CNT_END;
    while( sendlen )
    {
        if( R8_SPI1_FIFO_COUNT < SPI_FIFO_SIZE )
        {
            R8_SPI1_FIFO = *pbuf;
            pbuf++;
            sendlen--;
        }
    }
    while( R8_SPI1_FIFO_COUNT != 0 );                         // FIFO
}

/*******************************************************************************
* Function Name  : SPI1_MasterRecv
* Description    : FIFO
* Input          : pbuf: 
                   len: 4095
* Return         : None
*******************************************************************************/
void SPI1_MasterRecv( UINT8 *pbuf, UINT16 len )
{
    UINT16  readlen;

    readlen = len;
    R8_SPI1_CTRL_MOD |= RB_SPI_FIFO_DIR;                     // 
    R16_SPI1_TOTAL_CNT = len;                                // FIFO0 */
    R8_SPI1_INT_FLAG = RB_SPI_IF_CNT_END;
    while( readlen )
    {
        if( R8_SPI1_FIFO_COUNT )
        {
            *pbuf = R8_SPI1_FIFO;
            pbuf++;
            readlen--;
        }
    }
}



