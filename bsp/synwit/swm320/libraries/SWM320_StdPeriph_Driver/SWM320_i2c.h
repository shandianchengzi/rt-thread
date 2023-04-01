#ifndef __SWM320_I2C_H__
#define __SWM320_I2C_H__

typedef struct {
    uint8_t  Master;        //1 
    uint8_t  Addr7b;        //1 7     0 10

    uint32_t MstClk;        //
    uint8_t  MstIEn;        //

    uint16_t SlvAddr;       //
    uint8_t  SlvRxEndIEn;   //
    uint8_t  SlvTxEndIEn;   //
    uint8_t  SlvSTADetIEn;  //
    uint8_t  SlvSTODetIEn;  //
    uint8_t  SlvRdReqIEn;   //
    uint8_t  SlvWrReqIEn;   //
} I2C_InitStructure;


void I2C_Init(I2C_TypeDef * I2Cx, I2C_InitStructure * initStruct);

void I2C_Open(I2C_TypeDef * I2Cx);
void I2C_Close(I2C_TypeDef * I2Cx);

uint8_t I2C_Start(I2C_TypeDef * I2Cx, uint8_t addr);
void I2C_Stop(I2C_TypeDef * I2Cx);
uint8_t I2C_Write(I2C_TypeDef * I2Cx, uint8_t data);
uint8_t I2C_Read(I2C_TypeDef * I2Cx, uint8_t ack);

#endif //__SWM320_I2C_H__
