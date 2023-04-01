# STM32F429  BSP 

## 

 RT-Thread  STM32F429  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32F429  ARM Cortex-M4  180Mhz STM32F429 



![board](figures/board.jpg)

 **** 

- MCUSTM32F429IGT6 180MHz1024KB FLASH 256KB RAM
-  RAMIS42S16400JSDRAM8MB
-  FLASHW25Q128SPI16MB
- 
  - LEDRGB
  - 2K1PA0K2PC13
- USB SD LCD 
-  JTAG/SWD

 [STM32 ](https://fire-stm32.taobao.com/index.htm)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| RS232         |          |  |
| SPI Flash         |          |                                       |
|              |          |      ADC1                          |
|             |          |                                       |
| MPU6050 |          |                   |
| SDRAM             |          |                                       |
| LCD               |          |  RGB                             |
| SD              |      |                                       |
| CAN               |      |                                       |
| EMW1062 |  | |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART              |          | UART1/2                             |
| SPI               |          | SPI1/2/5                              |
| I2C               |          |  I2C                              |
| ADC               |          |                                     |
| RTC               |          |  |
| WDT               |          |                                       |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| SDIO              |      |                               |
| PWM               |      |                               |
| USB Device        |      |                               |
| USB Host          |      |                               |
| ****      | **** | ****                              |
|          |      |                               |

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

>  JLink  JLink 

#### 

 LED  LED  LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
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



## 

:

- [SummerGift](https://github.com/SummerGGift)