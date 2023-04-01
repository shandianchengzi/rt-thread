/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-12-28     unknow       copy by STemwin
 */
#ifndef __DRV_LCD_H
#define __DRV_LCD_H
#include <rtthread.h>
#include "rtdevice.h"
#include <drv_common.h>

#ifdef BSP_USING_TOUCH_CAP
#define LCD_W 800
#define LCD_H 480
#endif // BSP_USING_TOUCH_CAP

#ifdef BSP_USING_TOUCH_RES
#define LCD_W 320
#define LCD_H 480
#endif // BSP_USING_TOUCH_RES

//LCD
typedef struct
{
    uint16_t width;         //LCD 
    uint16_t height;        //LCD 
    uint16_t id;            //LCD ID
    uint8_t  dir;           //01
    uint16_t wramcmd;       //gram
    uint16_t setxcmd;       //x
    uint16_t setycmd;       //y
}_lcd_dev;

//LCD
extern _lcd_dev lcddev; //LCD

typedef struct
{
  __IO uint16_t REG;
  __IO uint16_t RAM;
}LCD_CONTROLLER_TypeDef;

//
#define L2R_U2D  0      //,
#define L2R_D2U  1      //,
#define R2L_U2D  2      //,
#define R2L_D2U  3      //,

#define U2D_L2R  4      //,
#define U2D_R2L  5      //,
#define D2U_L2R  6      //,
#define D2U_R2L  7      //,

#ifdef BSP_USING_TOUCH_CAP
#define DFT_SCAN_DIR  L2R_U2D  //
#endif // BSP_USING_TOUCH_CAP

#ifdef BSP_USING_TOUCH_RES
#define DFT_SCAN_DIR  D2U_L2R  //
#endif // BSP_USING_TOUCH_RES

//LCD
#define SSD_HOR_RESOLUTION      800     //LCD
#define SSD_VER_RESOLUTION      480     //LCD
//LCD
#define SSD_HOR_PULSE_WIDTH     1       //
#define SSD_HOR_BACK_PORCH      46      //
#define SSD_HOR_FRONT_PORCH     210     //

#define SSD_VER_PULSE_WIDTH     1       //
#define SSD_VER_BACK_PORCH      23      //
#define SSD_VER_FRONT_PORCH     22      //
//
#define SSD_HT  (SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS (SSD_HOR_BACK_PORCH)
#define SSD_VT  (SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)


void lcd_fill_array(rt_uint16_t x_start, rt_uint16_t y_start, rt_uint16_t x_end, rt_uint16_t y_end, void *pcolor);

#endif
