# STM32F411 BlackPill  BSP 

## 

 STM32F411 BlackPill  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F411 BlackPill  WeAct  ARM Cortex-M4  100Mhz STM32F411CE



![board](figures/board.png)

 **** 

- MCUSTM32F411CEU 100MHz512KB FLASH 128KB RAM
- 
  - LED: 2 , user LED (LD1), power LED (LD2)
  - : 3 , USER, BOOT0 and RESET
- USB  3  COM 
- : SWD

[STM32F4x1 MiniF4 WeAct](https://github.com/WeActTC/MiniF4-STM32F4x1)

## 

 BSP 

| **** | **** |                        ****                         |
| :----------- | :----------: | :-----------------------------------------------------: |
| GPIO         |          |           PA0, PA1... PH1 ---> PIN: 0, 1...47           |
| UART         |          |                          UART1                          |
| SPI          |          |                                                         |
| IIC          |          |                                                         |
| RTC          |          |                               |
| WDT          |          |                                                         |
| FLASH        |          |  [FAL](https://github.com/RT-Thread-packages/fal) |
| USB Device   |          |                                                         |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 

### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 Type-A to Type-C  PC  LED LD2 (PWR) 

#### 

 project.uvprojx  MDK5 

>  ST-LINK 

#### 

 LED  LD2  LD1 

COM  2115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Feb 27 2020
 2006 - 2020 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO   1  ENV  BSP 

1.  BSP  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32  BSP . md)

## 



## 

:

- [greedyhao](https://github.com/greedyhao) <hao_kr@163.com>
