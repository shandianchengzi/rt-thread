#ifndef __SWM341_SPI_H__
#define __SWM341_SPI_H__

typedef struct {
    uint8_t  FrameFormat;   //SPI_FORMAT_SPISPI_FORMAT_TI_SSI
    uint8_t  SampleEdge;    //SPISPI_FIRST_EDGESPI_SECOND_EDGE
    uint8_t  IdleLevel;     //SPISPI_LOW_LEVELSPI_HIGH_LEVEL
    uint8_t  WordSize;      //, 4-16
    uint8_t  Master;        //1     0 
    uint8_t  clkDiv;        //SPI_CLK = SYS_CLK / clkDivSPI_CLKDIV_4SPI_CLKDIV_8... ... SPI_CLKDIV_512

    uint8_t  RXThreshold;   //1--8
    uint8_t  RXThresholdIEn;//RX FIFO >= RXThreshold

    uint8_t  TXThreshold;   //0--7
    uint8_t  TXThresholdIEn;//TX FIFO <= TXThreshold

    uint8_t  TXCompleteIEn; //FIFO
} SPI_InitStructure;

#define SPI_FORMAT_SPI          0       //Motorola SPI 
#define SPI_FORMAT_TI_SSI       1       //TI SSI 
#define SPI_FORMAT_I2S          2
#define SPI_FORMAT_FLASH        3       //SPI Flash 

#define SPI_FIRST_EDGE          0       //
#define SPI_SECOND_EDGE         1       //

#define SPI_LOW_LEVEL           0       //
#define SPI_HIGH_LEVEL          1       //

#define SPI_CLKDIV_2            8
#define SPI_CLKDIV_4            0
#define SPI_CLKDIV_8            1
#define SPI_CLKDIV_16           2
#define SPI_CLKDIV_32           3
#define SPI_CLKDIV_64           4
#define SPI_CLKDIV_128          5
#define SPI_CLKDIV_256          6
#define SPI_CLKDIV_512          7


/* Interrupt Type */
#define SPI_IT_RX_OVF       (1 << 0)    //RX FIFO Overflow
#define SPI_IT_RX_FULL      (1 << 1)    //RX FIFO Full
#define SPI_IT_RX_HFULL     (1 << 2)    //RX FIFO Half Full
#define SPI_IT_TX_EMPTY     (1 << 3)    //TX FIFO Empty
#define SPI_IT_TX_HFULL     (1 << 4)    //TX FIFO Half Full
#define SPI_IT_RX_THRES     (1 << 5)    //RX FIFO ThresholdFIFOCTRL.RFTHR
#define SPI_IT_TX_THRES     (1 << 6)    //TX FIFO ThresholdFIFOCTRL.TFTHR
#define SPI_IT_TX_DONE      (1 << 9)    //TX DoneFIFO
#define SPI_IT_CS_FALL      (1 << 10)   //CS
#define SPI_IT_CS_RISE      (1 << 11)   //CS


void SPI_Init(SPI_TypeDef * SPIx, SPI_InitStructure * initStruct);      //SPI
void SPI_Open(SPI_TypeDef * SPIx);                                      //SPI
void SPI_Close(SPI_TypeDef * SPIx);                                     //SPI

uint32_t SPI_Read(SPI_TypeDef * SPIx);
void SPI_Write(SPI_TypeDef * SPIx, uint32_t data);
void SPI_WriteWithWait(SPI_TypeDef * SPIx, uint32_t data);
uint32_t SPI_ReadWrite(SPI_TypeDef * SPIx, uint32_t data);

uint32_t SPI_IsRXEmpty(SPI_TypeDef * SPIx);             //FIFOSPI_Read()
uint32_t SPI_IsTXFull(SPI_TypeDef * SPIx);              //FIFOSPI_Write()
uint32_t SPI_IsTXEmpty(SPI_TypeDef * SPIx);             //FIFO


void SPI_INTEn(SPI_TypeDef * SPIx, uint32_t it);        //
void SPI_INTDis(SPI_TypeDef * SPIx, uint32_t it);       //
void SPI_INTClr(SPI_TypeDef * SPIx, uint32_t it);       //
uint32_t SPI_INTStat(SPI_TypeDef * SPIx, uint32_t it);  //




typedef struct {
    uint8_t  Mode;          //I2S_MASTER_TXI2S_MASTER_RXI2S_MASTER_TX_RXI2S_SLAVE_TXI2S_SLAVE_RXI2S_SLAVE_TX_RX
    uint8_t  FrameFormat;   //I2S_I2S_PHILIPSI2S_MSB_JUSTIFIEDI2S_PCM_SHORTI2S_PCM_LONG0I2S_PCM_LONG1
    uint8_t  DataLen;       //I2S_DATALEN_8I2S_DATALEN_16I2S_DATALEN_24I2S_DATALEN_32
    uint32_t ClkFreq;       //I2S_SCLK Frequency

    uint8_t  RXThreshold;   //1--8
    uint8_t  RXThresholdIEn;//RX FIFO >= RXThreshold

    uint8_t  TXThreshold;   //0--7
    uint8_t  TXThresholdIEn;//TX FIFO <= TXThreshold

    uint8_t  TXCompleteIEn; //FIFO
} I2S_InitStructure;

#define I2S_MASTER_RX       5
#define I2S_MASTER_TX       6
#define I2S_SLAVE_RX        1
#define I2S_SLAVE_TX        2

#define I2S_I2S_PHILIPS     0
#define I2S_MSB_JUSTIFIED   1
#define I2S_PCM_SHORT       2
#define I2S_PCM_LONG0       3   //PCM Long Mode Sync Width 1 SCLK period
#define I2S_PCM_LONG1       4   //PCM Long Mode Sync Width 1 Data Length

#define I2S_DATALEN_8       0
#define I2S_DATALEN_16      1
#define I2S_DATALEN_24      2
#define I2S_DATALEN_32      3

void I2S_Init(SPI_TypeDef * SPIx, I2S_InitStructure * initStruct);      //I2S
void I2S_Open(SPI_TypeDef * SPIx);                                      //I2S
void I2S_Close(SPI_TypeDef * SPIx);                                     //I2S
void I2S_MCLKConfig(SPI_TypeDef * SPIx, uint32_t output_enable, uint32_t mclk_freq);


#endif //__SWM341_SPI_H__
