# GD32 RISC-VBSP

## 

 RT-Thread  ENV  BSP 



1. 
2. 
3. 

## 

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/programming-manual/env/env/)

## 

 FlashSD BSP RT-Thread  ENV  BSP GD32VFf103V-EVAL UART1 ENV  BSP 

### 1

 `rt-thread\bsp\gd32\risc-v\gd32vf103v-eval`  menuconfig 

![ menuconfig](figures/menuconfig_gd32vf103v-eval.png)



![RT-Thread ](figures/config1.png)

 `Hardware Drivers Config`

### 2

 ************

![ ](figures/config2.png)

### 3 UART1 

![ ](figures/UART1.png)

### 4

 Save  Esc 

![](figures/save.png)

### 5

 `pkgs --update` 

![1543477036034](figures/update.png)

### 6

gcc

![1543478492157](figures/scons.png)

gccRISC-VMCU

### 7

J-Link/GD-LinkGDDFUOpenOCD

### 8

 `list_device`  uart1 `UART1` 

![1543478742034](figures/run_flash.png)



## 

 ENV  RT-Thread 