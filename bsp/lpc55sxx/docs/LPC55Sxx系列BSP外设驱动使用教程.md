# BSP 

## 

 RT-Thread  ENV  BSP 



1. 
2. 
3. 

## 

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/rtthread-development-guide/rtthread-tool-manual/env/env-user-manual/)

## 

 FlashSD BSP RT-Thread  ENV  BSP NXPLPC55S69-EVK  MMA8562  ENV  BSP 

### 1

 `rt-thread\bsp\lpc55sxx\lpc55s69_evk` "ConEmu Here"

![ConEmu](figures/menuconfig_ConEmu.png)

 menuconfig 

![ menuconfig](figures/menuconfig_lpc5500.png)



![RT-Thread ](figures/config1.png)

 `Hardware Drivers Config`

### 2

 ************

![ ](figures/config2.png)

### 3 MMA8562 

![ ](figures/mma8562.png)

### 4

 Save  Esc 

![](figures/save.png)

### 5

 `pkgs --update` 

![](figures/update.png)

### 6 MDK5 

 `scons --target=mdk5`  MDK5 

![MDK](figures/scons_mdk5.png)

### 7

 MDK5 

![MDK5](figures/compile_mdk.png)

### 8

 `list_device`  I2C MMA8562 I2C , `MMA8562` 

![](figures/i2c_device1.png)

## 

GPIO  UART0 **** 

 ****  ``

![1543481275711](figures/on_chip_config.png)

 FinSH  `list_device`  PWM 

![i2c_device](figures/uart_device.png)

## 

 ENV  RT-Thread 