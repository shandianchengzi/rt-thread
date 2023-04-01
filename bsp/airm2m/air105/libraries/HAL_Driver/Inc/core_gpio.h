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

#ifndef __CORE_GPIO_H__
#define __CORE_GPIO_H__
#include "bsp_common.h"
/**
 * @brief GPIO
 *
 * @param Fun PINpDatavoid *->uint32_t

 */
void GPIO_GlobalInit(CBFuncEx_t Fun);

/**
 * @brief GPIO
 *
 * @param Pin Pin
 * @param IsInput 10
 * @param InitValue 10

 */
void GPIO_Config(uint32_t Pin, uint8_t IsInput, uint8_t InitValue);
/**
 * @brief GPIO
 *
 * @param Pin Pin
 * @param IsPull 
 * @param IsUp 

 */
void GPIO_PullConfig(uint32_t Pin, uint8_t IsPull, uint8_t IsUp);

/**
 * @brief GPIO
 *
 * @param Pin Pin
 * @param IsLevel 01
 * @param IsRiseHigh 
 * @param IsFallLow 
 */
void GPIO_ExtiConfig(uint32_t Pin, uint8_t IsLevel, uint8_t IsRiseHigh, uint8_t IsFallLow);

/**
 * @brief GPIO
 *
 * @param Pin Pin
 * @param Function 0~3GPIO1
 */
void GPIO_Iomux(uint32_t Pin, uint32_t Function);

/**
 * @brief GPIO
 *
 * @param Pin Pin
 * @param Level 10
 */
void GPIO_Output(uint32_t Pin, uint8_t Level);

/**
 * @brief GPIO
 *
 * @param Pin Pin
 * @return 1 0
 */
uint8_t GPIO_Input(uint32_t Pin);

/**
 * @brief GPIOpinSTM32GPIO
 *
 * @param Port 
 * @param Pins Pin
 * @param Level 10
 */
void GPIO_OutputMulti(uint32_t Port, uint32_t Pins, uint32_t Level);

/**
 * @brief GPIOpin
 *
 * @param Port 
 * @return
 */
uint32_t GPIO_InputMulti(uint32_t Port);

void GPIO_ExtiSetHWTimerCB(CBFuncEx_t CB, void *pParam);
void GPIO_ODConfig(uint32_t Pin, uint8_t InitValue);
#endif
