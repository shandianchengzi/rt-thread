/*
 * Copyright (c) 2022 OpenLuat & AirM2M
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __CORE_I2C_H__
#define __CORE_I2C_H__
#include "bsp_common.h"
typedef struct
{
    uint8_t Data[2];
}I2C_CommonRegDataStruct;

void I2C_GlobalInit(void);
/**
 * @brief i2c
 *
 * @param I2CID I2C
 * @param Speed 100000400000
 */
void I2C_MasterSetup(uint8_t I2CID, uint32_t Speed);
/*
 * @brief i2c
 *
 * @param I2CID I2C
 * @param ChipAddress I2C
 * @param ChipAddressLen I2C 12
 * @param CB 
 * @param pParam pParam
 */
void I2C_Prepare(uint8_t I2CID, uint16_t ChipAddress, uint8_t ChipAddressLen, CBFuncEx_t CB, void *pParam);
/**
 * @brief i2c
 *
 * @param I2CID I2C
 * @param Operate 
 *  I2C_OP_READ_REG = 0,    //i2cstart
    I2C_OP_READ,        //i2c
    I2C_OP_WRITE,       //i2c
 * @param RegAddress 
 * @param Data 
 * @param Len 
 * @param Toms ms
 */
void I2C_MasterXfer(uint8_t I2CID, uint8_t Operate, uint8_t RegAddress, uint8_t *Data, uint32_t Len, uint16_t Toms);

/**
 * @brief i2c
 *
 * @param I2CID I2C
 * @param RegQueue 
 * @param TotalNum 
 * @param Toms ms
 * @param IsBlock 
 * @return =0  IsBlock=1IsBlock=00
 */
int32_t I2C_MasterWriteRegQueue(uint8_t I2CID, I2C_CommonRegDataStruct *RegQueue, uint32_t TotalNum, uint16_t Toms, uint8_t IsBlock);

/**
 * @brief i2c
 *
 * @param I2CID I2C
 * @param Result  =0return != 0
 * @return =0  
 */
int I2C_WaitResult(uint8_t I2CID, int32_t *Result);

int32_t I2C_BlockWrite(uint8_t I2CID, uint8_t ChipAddress, const uint8_t *Data, uint32_t Len, uint16_t Toms, CBFuncEx_t CB, void *pParam);

int32_t I2C_BlockRead(uint8_t I2CID, uint8_t ChipAddress, uint8_t *Reg, uint8_t *Data, uint32_t Len, uint16_t Toms, CBFuncEx_t CB, void *pParam);
#endif
