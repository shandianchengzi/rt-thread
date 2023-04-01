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

#ifndef __CORE_DCMI_H__
#define __CORE_DCMI_H__

/**
 * @brief 
 *
 * @param VsyncLevel  0 VSYNC  1 VSYNC 
 * @param HsyncLevel  0 HSYNC  1 HSYNC 
 * @param PclkPOL Pixel 0 1
 * @param DataBits 8~14
 * @param FrameRate 0150%225%
 */
void DCMI_Setup(uint8_t VsyncLevel, uint8_t HsyncLevel, uint8_t PclkPOL, uint8_t DataBit, uint32_t FrameRate);

/**
 * @brief 
 *
 * @param OnOff 0  1 
 * @param BufLen 4byte00320*24016bit320*2/4N81280
 * @param ImageW 
 * @param ImageW 
 * @param DataByte 1byte
 * @param OutH 
 */
void DCMI_CaptureSwitch(uint8_t OnOff, uint32_t BufLen, uint32_t ImageW, uint32_t ImageH, uint8_t DataByte, uint32_t *OutH);
void DCMI_SetCallback(CBFuncEx_t CB, void *pData);
/**
 * @brief 
 *
 * @param OnOff 0  1 
 * @param VStart 
 * @param HStart 16bit*2
 * @param VLen 1
 * @param HLen 16bit*2
 */
void DCMI_SetCROPConfig(uint8_t OnOff, uint32_t VStart, uint32_t HStart, uint32_t VLen, uint32_t HLen);
#endif
