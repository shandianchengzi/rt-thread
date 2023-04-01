#ifndef __SWM341_DMA_H__
#define __SWM341_DMA_H__


typedef struct {
    uint8_t  Mode;          //DMA_MODE_SINGLEDMA_MODE_CIRCLE

    uint8_t  Unit;          //DMA_UNIT_BYTEDMA_UNIT_HALFWORDDMA_UNIT_WORD

    uint32_t Count;         // Unit 0x100000

    uint32_t SrcAddr;

    uint32_t DstAddr;

    uint8_t  SrcAddrInc;    //0     1 

    uint8_t  DstAddrInc;

    uint8_t  Handshake;     //DMA_HS_NODMA_CH0_UART0TXDMA_CH0_SPI0TX... ...

    uint8_t  Priority;      //DMA_PRI_LOWDMA_PRI_HIGH

    uint8_t  DoneIE;        //
} DMA_InitStructure;


#define DMA_CH0     0
#define DMA_CH1     1
#define DMA_CH2     2
#define DMA_CH3     3

#define DMA_MODE_SINGLE         0       // 
#define DMA_MODE_CIRCLE         1       // 

#define DMA_UNIT_BYTE       0
#define DMA_UNIT_HALFWORD   1
#define DMA_UNIT_WORD       2

#define DMA_PRI_LOW         0
#define DMA_PRI_HIGH        1


#define DMA_HS_NO           (0 << 4)    // Handshake
#define DMA_HS_SRC          (1 << 4)    //     DMAUnit
#define DMA_HS_DST          (2 << 4)    // DMAUnit
#define DMA_HS_EXT          (4 << 4)    //   DMAUnit
#define DMA_HS_MSK          (7 << 4)

#define DMA_DIR_RX          (0 << 7)    // SRC --> DST
#define DMA_DIR_TX          (1 << 7)    // DST --> SRC
#define DMA_DIR_MSK         (1 << 7)

// 
#define DMA_CH0_UART1RX     (0 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH0_SPI1RX      (1 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH0_UART2RX     (2 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH0_ADC0        (3 | DMA_HS_SRC | DMA_DIR_RX)

#define DMA_CH1_UART0RX     (0 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH1_SPI0RX      (1 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH1_UART3RX     (2 | DMA_HS_SRC | DMA_DIR_RX)

#define DMA_CH2_UART3RX     (0 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH2_SPI0RX      (1 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH2_UART0RX     (2 | DMA_HS_SRC | DMA_DIR_RX)

#define DMA_CH3_UART2RX     (0 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH3_SPI1RX      (1 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH3_UART1RX     (2 | DMA_HS_SRC | DMA_DIR_RX)
#define DMA_CH3_ADC1        (3 | DMA_HS_SRC | DMA_DIR_RX)

// 
#define DMA_CH0_UART0TX     (0 | DMA_HS_DST | DMA_DIR_RX)
#define DMA_CH0_SPI0TX      (1 | DMA_HS_DST | DMA_DIR_RX)
#define DMA_CH0_UART3TX     (2 | DMA_HS_DST | DMA_DIR_RX)

#define DMA_CH1_UART1TX     (0 | DMA_HS_DST | DMA_DIR_RX)
#define DMA_CH1_SPI1TX      (1 | DMA_HS_DST | DMA_DIR_RX)
#define DMA_CH1_UART2TX     (2 | DMA_HS_DST | DMA_DIR_RX)

#define DMA_CH2_UART2TX     (0 | DMA_HS_DST | DMA_DIR_RX)
#define DMA_CH2_SPI1TX      (1 | DMA_HS_DST | DMA_DIR_RX)
#define DMA_CH2_UART1TX     (2 | DMA_HS_DST | DMA_DIR_RX)

#define DMA_CH3_UART3TX     (0 | DMA_HS_DST | DMA_DIR_RX)
#define DMA_CH3_SPI0TX      (1 | DMA_HS_DST | DMA_DIR_RX)
#define DMA_CH3_UART0TX     (2 | DMA_HS_DST | DMA_DIR_RX)

// 
#define DMA_EXHS_TIMR0      (0 | DMA_HS_EXT | DMA_DIR_RX)
#define DMA_EXHS_TIMR1      (1 | DMA_HS_EXT | DMA_DIR_RX)
#define DMA_EXHS_TIMR2      (2 | DMA_HS_EXT | DMA_DIR_RX)
#define DMA_EXHS_TIMR3      (3 | DMA_HS_EXT | DMA_DIR_RX)
#define DMA_EXHS_TIMR4      (4 | DMA_HS_EXT | DMA_DIR_RX)
#define DMA_EXHS_TRIG0      (5 | DMA_HS_EXT | DMA_DIR_RX)   // DMA_TRIG0
#define DMA_EXHS_TRIG1      (6 | DMA_HS_EXT | DMA_DIR_RX)   // DMA_TRIG1



void DMA_CH_Init(uint32_t chn, DMA_InitStructure * initStruct); //DMA
void DMA_CH_Open(uint32_t chn);
void DMA_CH_Close(uint32_t chn);

void DMA_CH_INTEn(uint32_t chn);                //DMA
void DMA_CH_INTDis(uint32_t chn);               //DMA
void DMA_CH_INTClr(uint32_t chn);               //DMA
uint32_t DMA_CH_INTStat(uint32_t chn);          //DMA1     0 


#endif //__SWM341_DMA_H__
