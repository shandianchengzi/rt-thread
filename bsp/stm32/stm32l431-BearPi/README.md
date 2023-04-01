# Bear-Pi  BSP 

## 

Bear-Pi  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 Bear-Pi Cortex-M4 ST-LINK/V2-1 /mirco USB Arduino nano 



![board](figures/board.jpg)

 **** 

- MCUSTM32L431RC 80MHz256KB FLASH 64KB RAM
- 
  - SPI FLASH: 8M
  - 2
  - E53
  - LCD: 240 * 240 tft
  - LEDLED 
- USB  3  COM 
-  ST-LINK/V2-1 

Bear-Pi  [Bear-Pi](http://www.holdiot.com/product/showproduct.php?id=26)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  ST-LINK  |          | UART1                              |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PC15 ---> PIN: 0, 1...47 |
| UART              |          | UART1                             |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

>  ST-LINK  microUSB 

#### 

 LED  D5 LED 

USB  COM  1115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Dec 28 2020
 2006 - 2020 Copyright by rt-thread team
---Welcome use BearPi---
msh >
```
### 

 BSP  GPIO  2  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  RT-Thread BSP GPIO 
-  RT-Thread  PC 

## 

:

-  [RiceChen](https://github.com/RiceChen), <980307037@qq.com>