# STM32BSP

## 

 RT-Thread  ENV  BSP 



1. 
2. 
3. 

## 

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/programming-manual/env/env/)

## 

 FlashSD BSP RT-Thread  ENV  BSP  F429  SPI Flash  ENV  BSP 

### 1

 `rt-thread\bsp\stm32\stm32f429-atk-apollo`  menuconfig 

![ menuconfig](figures/menuconfig_apolo.png)



![RT-Thread ](figures/config1.png)

 `Hardware Drivers Config`

### 2

 ************

![ ](figures/config2.png)

### 3 SPI Flash 

![ ](figures/spi_flash.png)

### 4

 Save  Esc 

![](figures/save.png)

### 5

 `pkgs --update` 

![1543477036034](figures/update.png)

### 6 MDK5 

 `scons --target=mdk5 -s`  MDK5 

![1543477194829](figures/scons_mdk5.png)

### 7

 MDK5 

![1543478492157](figures/complise.png)

### 8

 `list_device`  W25Q256  `SPI Flash` 

![1543478742034](figures/run_flash.png)

## 

GPIO  UART1 **** 

 ****  ``

![1543481275711](figures/on_chip_config.png)

 FinSH  `list_device`  I2C1 

![i2c_device](figures/i2c_device.png)

## 

 ENV  RT-Thread 