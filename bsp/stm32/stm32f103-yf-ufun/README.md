# STM32F103 yf-ufun  BSP 

## 

 STM32F103 yf-ufun  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

yf-ufun STM32F103  ARM Cortex-M3  72Mhz STM32F103  Micro SD usb ISP USB LED TTP224N-BSBCH340 USB BOOT RGB LEDRTC SWD  miniPCIe 



![board](figures/board.jpg)

 **** 

- MCUSTM32F103RCT6 72MHz256KB FLASH 48KB RAM
- 
  - LED2LED3RPA3LED1RGBPA1PA2PA0
  - 5K1 4
- USB SD miniPCIe 
-  SWD 

 [ufun ] :  https://pan.baidu.com/s/12WzPnuGVufoiKUtzhdXNeg :  mp4h

## 

 BSP 

| ****      | **** | ****                             |
| :----------------- | :----------: | :------------------------------------|
| USB         |          |                                       |
|             |      |                                       |
| LED               |          |                                       |
| RGB LED           |      |                                       |
|           |      |                                       |
| ****      | **** | ****                              |
| GPIO              |          | PA0-PA14PB0-PB15PC0-PC5PC7-PC12 |
| UART              |          | UART1                                 |
| SPI               |      | SPI1 |
| I2C               |      |  I2C |
| SDIO              |      |                                       |
| RTC               |      |                                       |
| PWM               |      |                                       |
| USB Device        |      |                                       |
| USB Host          |      | 		                               |
| IWG               |      | 		                               |
| ****      | **** | ****                              |

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

 project.uvprojx  MDK5 

>  Jlink  Jlink 

#### 

LED3 

 PC , 115200-8-1-N RT-Thread :

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build May 23 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO  1  Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

## 

:

-  [](https://github.com/lhxzui), <iuzxhl@qq.com>