# STM32F405  BSP 

## 

 SM1432F405  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

SM1432F405  ARM Cortex-M4  168MhzUSB,SD,io,,

:SM1432F405



![board](figures/board.png)

 **** 

- MCUSTM32F405RG 168MHz1024KB FLASH 196KB RAM
- 
  - LED4D1PC4D2PA8,D3PC5,D4PA10
  - 2K1(K2,PA13
- USBSD IO,

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB               |          |                                       |
| SD              |       |                                       |
|     MMA7660      |     |                               |
| LED              |       |                                       |
| ****      | **** | ****                              |
| GPIO              |          | PA0..PA15PB0..PB15,PC0..PC5 ---> PIN: 0..37 |
| UART              |          | UART2                             |
| SPI               |       |                               |
| I2C               |       |                               |
| SDIO              |      |                               |
| RTC               |      |                               |
| PWM               |      |                               |
| USB Device        |      |                               |
| USB Host          |      |                               |
| ****      | **** | ****                              |
|     W5500       |     |                               |
|     OLED       |     |                               |
|            |     |                               |
|           |     |                               |
|     TM1638A      |     |                               |
|     TM1638B      |     |                               |
|           |     |                               |
|           |     |                               |
|           |     |                               |
|           |     |                               |



## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

:

 project.uvprojx  MDK5 

> JLINKJLINK

:

> ENV,scons,.bin,Jlink

#### 



 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Feb 13 2019
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  2  SD   ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

-  [sunlichao](https://github.com/slcmcu/rt-thread), <sun-lichao@163.com>