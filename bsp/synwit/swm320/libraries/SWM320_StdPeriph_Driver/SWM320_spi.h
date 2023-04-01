#ifndef __SWM320_SPI_H__
#define __SWM320_SPI_H__

typedef struct {
    uint8_t  FrameFormat;   //SPI_FORMAT_SPISPI_FORMAT_TI_SSI
    uint8_t  SampleEdge;    //SPISPI_FIRST_EDGESPI_SECOND_EDGE
    uint8_t  IdleLevel;     //SPISPI_LOW_LEVELSPI_HIGH_LEVEL
    uint8_t  WordSize;      //, 4-16
    uint8_t  Master;        //1     0 
    uint8_t  clkDiv;        //SPI_CLK = SYS_CLK / clkDivSPI_CLKDIV_4SPI_CLKDIV_8... ... SPI_CLKDIV_512

    uint8_t  RXHFullIEn;    //FIFO
    uint8_t  TXEmptyIEn;    //FIFO  
    uint8_t  TXCompleteIEn; //FIFO  
} SPI_InitStructure;

#define SPI_FORMAT_SPI          0       //Motorola SPI 
#define SPI_FORMAT_TI_SSI       1       //TI SSI 

#define SPI_FIRST_EDGE          0       //
#define SPI_SECOND_EDGE         1       //

#define SPI_LOW_LEVEL           0       //
#define SPI_HIGH_LEVEL          1       //

#define SPI_CLKDIV_4            0
#define SPI_CLKDIV_8            1
#define SPI_CLKDIV_16           2
#define SPI_CLKDIV_32           3
#define SPI_CLKDIV_64           4
#define SPI_CLKDIV_128          5
#define SPI_CLKDIV_256          6
#define SPI_CLKDIV_512          7



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


void SPI_INTRXHalfFullEn(SPI_TypeDef * SPIx);
void SPI_INTRXHalfFullDis(SPI_TypeDef * SPIx);
void SPI_INTRXHalfFullClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTRXHalfFullStat(SPI_TypeDef * SPIx);
void SPI_INTRXFullEn(SPI_TypeDef * SPIx);
void SPI_INTRXFullDis(SPI_TypeDef * SPIx);
void SPI_INTRXFullClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTRXFullStat(SPI_TypeDef * SPIx);
void SPI_INTRXOverflowEn(SPI_TypeDef * SPIx);
void SPI_INTRXOverflowDis(SPI_TypeDef * SPIx);
void SPI_INTRXOverflowClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTRXOverflowStat(SPI_TypeDef * SPIx);

void SPI_INTTXHalfFullEn(SPI_TypeDef * SPIx);
void SPI_INTTXHalfFullDis(SPI_TypeDef * SPIx);
void SPI_INTTXHalfFullClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTTXHalfFullStat(SPI_TypeDef * SPIx);
void SPI_INTTXEmptyEn(SPI_TypeDef * SPIx);
void SPI_INTTXEmptyDis(SPI_TypeDef * SPIx);
void SPI_INTTXEmptyClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTTXEmptyStat(SPI_TypeDef * SPIx);
void SPI_INTTXCompleteEn(SPI_TypeDef * SPIx);
void SPI_INTTXCompleteDis(SPI_TypeDef * SPIx);
void SPI_INTTXCompleteClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTTXCompleteStat(SPI_TypeDef * SPIx);

void SPI_INTTXWordCompleteEn(SPI_TypeDef * SPIx);
void SPI_INTTXWordCompleteDis(SPI_TypeDef * SPIx);
void SPI_INTTXWordCompleteClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTTXWordCompleteStat(SPI_TypeDef * SPIx);


#endif //__SWM320_SPI_H__
