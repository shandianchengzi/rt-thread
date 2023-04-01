# GD32 ARMBSP

## 

 RT-Thread  ENV  BSP 



1. 
2. 
3. 

## 

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/programming-manual/env/env/)

## 

 FlashSD BSP RT-Thread  ENV  BSP GD32407V-START UART2  ENV  BSP 

### 1

 `rt-thread\bsp\gd32\arm\gd32407v-start`  menuconfig 

![ menuconfig](figures/menuconfig_gd32407v-start.png)



![RT-Thread ](figures/config1.png)

 `Hardware Drivers Config`

### 2

 ************

![ ](figures/config2.png)

### 3 UART2 

![ ](figures/UART2.png)

### 4

 Save  Esc 

![](figures/save.png)

### 5

 `pkgs --update` 

![1543477036034](figures/update.png)

### 6 MDK5 

 `scons --target=mdk5`  MDK5 

![1543477194829](figures/scons_mdk5.png)

### 7

 MDK5 

![1543478492157](figures/complise.png)

### 8

 `list_device`  uart2 `UART2` 

![1543478742034](figures/run_flash.png)



## 

 ENV  RT-Thread 