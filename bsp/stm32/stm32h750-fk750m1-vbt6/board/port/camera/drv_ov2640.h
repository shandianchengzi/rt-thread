
/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2023-03-24     spaceman          the first version
 */

#ifndef __DRV_OV2640_H__
#define __DRV_OV2640_H__

#include <rtthread.h>
#include <lcd_port.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  OV2640 ID
 */
#define OV2640_ID1      0x2640U
#define OV2640_ID2      0x2642U

#define OV2640_Enable  1
#define OV2640_Disable 0

//  ov2640_set_pixformat() 
#define Pixformat_RGB565 0
#define Pixformat_JPEG   1

// OV2640 ov2640_set_effect() 
#define OV2640_Effect_Normal      0 // 
#define OV2640_Effect_Negative    1 // 
#define OV2640_Effect_BW          2 // 
#define OV2640_Effect_BW_Negative 3 // +

// 1. OV2640
// 2. 
// 3. SVGA 800*600,  30
// 4. UXGA 1600*1200,15
// 5. 4
// 6. 4:3
#define OV2640_Width  400 // 
#define OV2640_Height 300 // 

// 1. 4
// 2. RGB565DCMIOV26404:3
// 3.  OV2640_Width  OV2640_Height
// 4. PCLK dcmi_ov2640_cfg.h  0xd3 
#define Display_Width  LCD_WIDTH
#define Display_Height LCD_HEIGHT

// 1.RGB565 *2 
// 2.JPG 640*480JPG30K
//   2,
#define OV2640_BufferSize Display_Width *Display_Height * 2 / 4 // DMA32
// #define  OV2640_BufferSize       100*1024/4   // DMA32

#define OV2640_SEL_Registers 0xFF // 
#define OV2640_SEL_DSP       0x00 // 0x00  DSP    
#define OV2640_SEL_SENSOR    0x01 // 0x01  SENSOR 

// DSP  (0xFF = 0x00)
#define OV2640_DSP_RESET  0xE0 //  SCCBJPEGDVP
#define OV2640_DSP_BPADDR 0x7C // :
#define OV2640_DSP_BPDATA 0x7D // :

// SENSOR  (0xFF = 0x01)
#define OV2640_SENSOR_COM7  0x12 // ,
#define OV2640_SENSOR_REG04 0x04 // 4,
#define OV2640_SENSOR_PIDH  0x0a // ID
#define OV2640_SENSOR_PIDL  0x0b // ID

void ov2640_set_pixformat(struct rt_i2c_bus_device *bus, rt_uint8_t pixformat);

rt_err_t ov2640_set_framesize(struct rt_i2c_bus_device *bus, rt_uint16_t width, rt_uint16_t height);

rt_err_t ov2640_set_horizontal_mirror(struct rt_i2c_bus_device *bus, rt_uint8_t configstate);
rt_err_t ov2640_set_vertical_flip(struct rt_i2c_bus_device *bus, rt_uint8_t configstate);

void ov2640_set_saturation(struct rt_i2c_bus_device *bus, rt_int8_t saturation);
void ov2640_set_brightness(struct rt_i2c_bus_device *bus, rt_int8_t brightness);
void ov2640_set_contrast(struct rt_i2c_bus_device *bus, rt_int8_t contrast);
void ov2640_set_effect(struct rt_i2c_bus_device *bus, rt_uint8_t effect_mode);

#ifdef __cplusplus
}
#endif

#endif
