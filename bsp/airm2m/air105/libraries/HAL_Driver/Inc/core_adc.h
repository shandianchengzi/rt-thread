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

#ifndef __CORE_ADC_H__
#define __CORE_ADC_H__
#define ADC_VALUE_ERROR (0xffffffff)
void ADC_GlobalInit(void);
/**
 * @brief globalinit00ADC_GetChannelValue
 *
 * @param Channel 
 * @param OnOff 
 */
void ADC_ChannelOnOff(uint8_t Channel, uint8_t OnOff);
/**
 * @brief ADC12bit1.8V09:5
 *
 * @param Channel 
 * @return != ADC_VALUE_ERROR 
 */
uint32_t ADC_GetChannelValue(uint8_t Channel);
/**
 * @brief 1~51:1 6demo
 *
 * @param OnOff 
 */
void ADC_IntelResistance(uint8_t OnOff);
#endif
