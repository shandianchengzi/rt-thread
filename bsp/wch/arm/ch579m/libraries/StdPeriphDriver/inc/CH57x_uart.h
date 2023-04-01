


#ifndef __CH57x_UART_H__
#define __CH57x_UART_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "CH579SFR.h"
#include "core_cm0.h"


/**
  * @brief  LINE error and status define
  */
#define  STA_ERR_BREAK      RB_LSR_BREAK_ERR       // 
#define  STA_ERR_FRAME      RB_LSR_FRAME_ERR       // 
#define  STA_ERR_PAR        RB_LSR_PAR_ERR         // 
#define  STA_ERR_FIFOOV     RB_LSR_OVER_ERR        // 

#define  STA_TXFIFO_EMP     RB_LSR_TX_FIFO_EMP     // FIFO
#define  STA_TXALL_EMP      RB_LSR_TX_ALL_EMP      // 
#define  STA_RECV_DATA      RB_LSR_DATA_RDY        // 


/**
  * @brief  Configuration UART TrigByte num
  */
typedef enum
{
    UART_1BYTE_TRIG = 0,        // 1
    UART_2BYTE_TRIG,            // 2
    UART_4BYTE_TRIG,            // 4
    UART_7BYTE_TRIG,            // 7

}UARTByteTRIGTypeDef;


/****************** UART0 */
void UART0_DefInit( void );                             /*  */
void UART0_BaudRateCfg( UINT32 baudrate );              /*  */
void UART0_ByteTrigCfg( UARTByteTRIGTypeDef b );        /*  */
void UART0_INTCfg( UINT8 s,  UINT8 i );                 /*  */
void UART0_Reset( void );                               /*  */

#define UART0_CLR_RXFIFO()       (R8_UART0_FCR |= RB_FCR_RX_FIFO_CLR)          /* FIFO */
#define UART0_CLR_TXFIFO()       (R8_UART0_FCR |= RB_FCR_TX_FIFO_CLR)          /* FIFO */

#define UART0_GetITFlag()       (R8_UART0_IIR&RB_IIR_INT_MASK)          /*  */
// please refer to LINE error and status define
#define UART0_GetLinSTA()       (R8_UART0_LSR)          /*  */

#define UART0_SendByte(b)       (R8_UART0_THR = b)      /*  */
void UART0_SendString( PUINT8 buf, UINT16 l );          /*  */
#define UART0_RecvByte()        ( R8_UART0_RBR )        /*  */
UINT16 UART0_RecvString( PUINT8 buf );                  /*  */



/****************** UART1 */
void UART1_DefInit( void );                             /*  */
void UART1_BaudRateCfg( UINT32 baudrate );              /*  */
void UART1_ByteTrigCfg( UARTByteTRIGTypeDef b );        /*  */
void UART1_INTCfg( UINT8 s,  UINT8 i );                 /*  */
void UART1_Reset( void );                               /*  */

#define UART1_CLR_RXFIFO()       (R8_UART1_FCR |= RB_FCR_RX_FIFO_CLR)          /* FIFO */
#define UART1_CLR_TXFIFO()       (R8_UART1_FCR |= RB_FCR_TX_FIFO_CLR)          /* FIFO */

#define UART1_GetITFlag()       (R8_UART1_IIR&RB_IIR_INT_MASK)          /*  */
// please refer to LINE error and status define
#define UART1_GetLinSTA()       (R8_UART1_LSR)          /*  */

#define UART1_SendByte(b)       (R8_UART1_THR = b)      /*  */
void UART1_SendString( PUINT8 buf, UINT16 l );          /*  */
#define UART1_RecvByte()        ( R8_UART1_RBR )        /*  */
UINT16 UART1_RecvString( PUINT8 buf );                  /*  */



/****************** UART2 */
void UART2_DefInit( void );                             /*  */
void UART2_BaudRateCfg( UINT32 baudrate );              /*  */
void UART2_ByteTrigCfg( UARTByteTRIGTypeDef b );        /*  */
void UART2_INTCfg( UINT8 s,  UINT8 i );                 /*  */
void UART2_Reset( void );                               /*  */

#define UART2_CLR_RXFIFO()       (R8_UART2_FCR |= RB_FCR_RX_FIFO_CLR)          /* FIFO */
#define UART2_CLR_TXFIFO()       (R8_UART2_FCR |= RB_FCR_TX_FIFO_CLR)          /* FIFO */

#define UART2_GetITFlag()       (R8_UART2_IIR&RB_IIR_INT_MASK)          /*  */
// please refer to LINE error and status define
#define UART2_GetLinSTA()       (R8_UART2_LSR)          /*  */

#define UART2_SendByte(b)       (R8_UART2_THR = b)      /*  */
void UART2_SendString( PUINT8 buf, UINT16 l );          /*  */
#define UART2_RecvByte()        ( R8_UART2_RBR )        /*  */
UINT16 UART2_RecvString( PUINT8 buf );                  /*  */




/****************** UART3 */
void UART3_DefInit( void );                             /*  */
void UART3_BaudRateCfg( UINT32 baudrate );              /*  */
void UART3_ByteTrigCfg( UARTByteTRIGTypeDef b );        /*  */
void UART3_INTCfg( UINT8 s,  UINT8 i );                 /*  */
void UART3_Reset( void );                               /*  */

#define UART3_CLR_RXFIFO()       (R8_UART3_FCR |= RB_FCR_RX_FIFO_CLR)          /* FIFO */
#define UART3_CLR_TXFIFO()       (R8_UART3_FCR |= RB_FCR_TX_FIFO_CLR)          /* FIFO */

#define UART3_GetITFlag()       (R8_UART3_IIR&RB_IIR_INT_MASK)          /*  */
// please refer to LINE error and status define
#define UART3_GetLinSTA()       (R8_UART3_LSR)          /*  */

#define UART3_SendByte(b)       (R8_UART3_THR = b)      /*  */
void UART3_SendString( PUINT8 buf, UINT16 l );          /*  */
#define UART3_RecvByte()        ( R8_UART3_RBR )        /*  */
UINT16 UART3_RecvString( PUINT8 buf );                  /*  */



#ifdef __cplusplus
}
#endif

#endif  // __CH57x_UART_H__

