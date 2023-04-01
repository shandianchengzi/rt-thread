#ifndef __SWM341_UART_H__
#define __SWM341_UART_H__

typedef struct {
    uint32_t Baudrate;

    uint8_t  DataBits;          //UART_DATA_8BITUART_DATA_9BIT

    uint8_t  Parity;            //UART_PARITY_NONEUART_PARITY_ODDUART_PARITY_EVENUART_PARITY_ONEUART_PARITY_ZERO

    uint8_t  StopBits;          //UART_STOP_1BITUART_STOP_2BIT

    uint8_t  RXThreshold;       //0--7
    uint8_t  RXThresholdIEn;    //RX FIFO >  RXThreshold

    uint8_t  TXThreshold;       //0--7
    uint8_t  TXThresholdIEn;    //TX FIFO <= TXThreshold

    uint8_t  TimeoutTime;       // = TimeoutTime/(Baudrate/10) 
    uint8_t  TimeoutIEn;        // TimeoutTime/(Baudrate/10) RX
} UART_InitStructure;


#define UART_DATA_8BIT      0
#define UART_DATA_9BIT      1

#define UART_PARITY_NONE    0
#define UART_PARITY_ODD     1
#define UART_PARITY_EVEN    3
#define UART_PARITY_ONE     5
#define UART_PARITY_ZERO    7

#define UART_STOP_1BIT      0
#define UART_STOP_2BIT      1

#define UART_RTS_1BYTE      0
#define UART_RTS_2BYTE      1
#define UART_RTS_4BYTE      2
#define UART_RTS_6BYTE      3

#define UART_ABR_RES_OK     1
#define UART_ABR_RES_ERR    2

#define UART_ERR_FRAME      1
#define UART_ERR_PARITY     2
#define UART_ERR_NOISE      3


void UART_Init(UART_TypeDef * UARTx, UART_InitStructure * initStruct);  //UART
void UART_Open(UART_TypeDef * UARTx);
void UART_Close(UART_TypeDef * UARTx);

void UART_WriteByte(UART_TypeDef * UARTx, uint8_t data);                //
uint32_t UART_ReadByte(UART_TypeDef * UARTx, uint32_t * data);          //Valid

uint32_t UART_IsTXBusy(UART_TypeDef * UARTx);
uint32_t UART_IsRXFIFOEmpty(UART_TypeDef * UARTx);                      //FIFOUART_ReadByte()
uint32_t UART_IsTXFIFOFull(UART_TypeDef * UARTx);                       //FIFOUART_WriteByte()


void UART_SetBaudrate(UART_TypeDef * UARTx, uint32_t baudrate);         //
uint32_t UART_GetBaudrate(UART_TypeDef * UARTx);                        //

void UART_CTSConfig(UART_TypeDef * UARTx, uint32_t enable, uint32_t polarity);
uint32_t UART_CTSLineState(UART_TypeDef * UARTx);

void UART_RTSConfig(UART_TypeDef * UARTx, uint32_t enable, uint32_t polarity, uint32_t threshold);
uint32_t UART_RTSLineState(UART_TypeDef * UARTx);

void UART_LINConfig(UART_TypeDef * UARTx, uint32_t detectedLen, uint32_t detectedIEn, uint32_t generatedLen, uint32_t generatedIEn);
void UART_LINGenerate(UART_TypeDef * UARTx);
uint32_t UART_LINIsDetected(UART_TypeDef * UARTx);
uint32_t UART_LINIsGenerated(UART_TypeDef * UARTx);

void UART_ABRStart(UART_TypeDef * UARTx, uint32_t detectChar);
uint32_t UART_ABRIsDone(UART_TypeDef * UARTx);


void UART_INTRXThresholdEn(UART_TypeDef * UARTx);
void UART_INTRXThresholdDis(UART_TypeDef * UARTx);
uint32_t UART_INTRXThresholdStat(UART_TypeDef * UARTx);
void UART_INTTXThresholdEn(UART_TypeDef * UARTx);
void UART_INTTXThresholdDis(UART_TypeDef * UARTx);
uint32_t UART_INTTXThresholdStat(UART_TypeDef * UARTx);
void UART_INTTimeoutEn(UART_TypeDef * UARTx);
void UART_INTTimeoutDis(UART_TypeDef * UARTx);
uint32_t UART_INTTimeoutStat(UART_TypeDef * UARTx);

void UART_INTTXDoneEn(UART_TypeDef * UARTx);
void UART_INTTXDoneDis(UART_TypeDef * UARTx);
uint32_t UART_INTTXDoneStat(UART_TypeDef * UARTx);

#endif //__SWM341_UART_H__
