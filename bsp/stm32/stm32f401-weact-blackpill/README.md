# STM32F401 BlackPill  BSP 

## 

 stm32f401-weact-blackpill  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F401  WeAct  ARM Cortex-M4  85Mhz STM32F401CC



![STM32F401CEU6](figures/22027805570288_192.jpg)

 **** 

- MCU*STM32F401CCU6* 84MHz256KB FLASH 64KB RAM
- 
  - LED2DS0PC13PWRpower LED
  - 3USER BOOT0 and RESET
- USB  3  COM 
-  SWD

[STM32F4x1 MiniF4 WeAct](https://github.com/WeActTC/MiniF4-STM32F4x1)

## 

 BSP 

| **** | **** | ****                                                |
| :----------------- | :----------: | :------------------------------------- |
| GPIO              |          | PA0, PA1... PH1 ---> PIN: 0, 1...47                     |
| UART              |          | UART1                             |
| SPI               |          |                               |
| I2C               |          |                               |
| RTC               |      |                  |
| WDT |  |  |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| USB Device        |      |                               |

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

>  ST-LINK  SWD 

#### 

 LED  LD2  LD3 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Feb 24 2023 15:38:04
 2006 - 2022 Copyright by RT-Thread team
msh >
```
### 

 BSP  GPIO  1  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 

## 

:

-  [Misthao](https://github.com/ZangCHSHub), <zangch924@foxmail.com>