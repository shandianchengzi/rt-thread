/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2023-03-24     spaceman          the first version
 */

#ifndef __DRV_LCD_SPI_EXT_H__
#define __DRV_LCD_SPI_EXT_H__

#include <rtthread.h>
#include <drv_spi.h>

#ifdef __cplusplus
extern "C" {
#endif

void Set_SPI_Handle_Ext(SPI_HandleTypeDef *handle);

/**
 * @brief  
 * @param  pData  : 
 * @param  Size   : 
 * @retval status
 */

rt_err_t SPI_Transmit_Ext(uint16_t pData, uint32_t Size);

/**
 * @brief  
 * @param  pData  : 
 * @param  Size   : 
 * @retval status
 */
rt_err_t SPI_TransmitBuffer_Ext(uint16_t *pData, uint32_t Size);

#ifdef __cplusplus
}
#endif

#endif /* __DRV_LCD_SPI_EXT_H__ */
