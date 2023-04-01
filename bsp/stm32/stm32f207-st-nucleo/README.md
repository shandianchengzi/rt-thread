# BSP README 

## 

 STM32F207 Nucleo-144  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32 Nucleo-144  ST  STM32F207ZG  ARM Cortex-M3  120 MHz STM32F207ZG 



![board](figures/board.jpg)

 **** 

- MCUSTM3207ZG 120MHz1MB FLASH 128KB RAM
- 
  - LED3LD1PB0LD2PB7LD3PB14
  - 2 USER and RESET 
- USB Arduino Uno  ST morpho 
-  JTAG/SWD

[Getting started with STM32 Nucleo board software development tools](https://www.st.com/resource/en/user_manual/dm00105928-getting-started-with-stm32-nucleo-board-software-development-tools-stmicroelectronics.pdf)

[STM32 Nucleo (144 pins) schematics](https://www.st.com/resource/en/schematic_pack/nucleo_144pins_sch.zip)

* ST [STM32 Nucleo-144 development board with STM32F207ZG MCU](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-f207zg.html)*

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
|             |          |                                       |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PH1 ---> PIN: 0, 1...144 |
| UART              |          | UART3                          |
| SPI               |          |                               |
| I2C               |          |                               |
| RTC               |      |                               |
| PWM               |      |                               |
| USB Device        |      |                               |
| USB Host          |      |                               |
| IWG               |      |                               |

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

>  xxx  xxx 

#### 

 LD3 

USB  COM  3115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Apr 12 2021
 2006 - 2021 Copyright by rt-thread team
msh >

```
### 

 BSP  GPIO  3  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  pin  bsp  stm32 bsp  GPIO  bsp 

  pin 

  | STM32  |  pin |
  | ------------ | ------------ |
  | PA0 - PA15   | 0 - 15       |
  | PB0 - PB15   | 16 - 31      |
  | PC0 - PC15   | 32 - 47      |
  | PD0 - ...    | 48 - ...     |


## 

:

-  [wanghaijing](https://github.com/whj4674672) <whj4674672@163.com>