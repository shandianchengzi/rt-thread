# STM32F767-V1  BSP 

## 

  STM32F767-V1  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32F767-V1  ARM Cortex-M7  216Mhz STM32F767 



![board](figures/board.jpg)

 **** 

- MCUSTM32F767 216MHz1MB FLASH 512KB RAM 16K CACHE
-  RAM8MB
-  FLASH16MB
- 
  - LEDRGB 
  - 2K1PA0K2PC13
- USB SD LCD 
-  JTAG/SWD

 [STM32 ](https://fire-stm32.taobao.com/index.htm)

## 

 BSP 

| ****      | **** | ****                                                |
| :---------------- | :----------: | :------------------------------------------------------ |
| USB         |          |                                                         |
| RS232             |          |                                       |
| QSPI Flash        |          |                                                         |
|             |          |  ADC1                                               |
|             |      |                                                   |
| MPU6050  |          |                                                         |
| SDRAM             |          |                                                         |
| LCD               |          |  RGB                                              |
| SD              |          |                                                         |
| CAN               |      |                                                         |
| EMW1062           |      |                                                         |
| ****      | **** | ****                                                |
| GPIO              |          | PA0, PA1... PK15 ---> PIN: 0, 1...176                   |
| UART              |          | UART1/x/x                                               |
| SPI               |      |                                                         |
| I2C               |          |  I2C                                                |
| ADC               |          |                                                         |
| RTC               |          |                               |
| WDT               |          |                                                         |
| FLASH             |          |  [FAL](https://github.com/RT-Thread-packages/fal) |
| SDIO              |          |                                                         |
| PWM               |      |                                                 |
| USB Device        |      |                                                 |
| USB Host          |      |                                                 |
| ****      | **** | ****                                                |
|               |      |                                                 |

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

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Dec 10 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  SD Flash  ENV  BSP 

1.  bsp  ENV 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

-  [greedyhao](https://github.com/greedyhao), <hao_kr@163.com>