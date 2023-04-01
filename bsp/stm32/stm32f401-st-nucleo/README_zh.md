# STM32F401 Nucleo-64  BSP 

## 

 STM32F401 Nucleo-64  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32 Nucleo-64  ST  STM32F401RE  ARM Cortex-M4  84 MHz STM32F401RE 



![board](figures/board.jpg)

STM32F401 Nucleo-64  **** 

- MCUSTM32F401RET6 84MHz512KB FLASH 96KB RAM
- 
  - LED3 USB communication (LD1), user LED (LD2), power LED (LD3) 
  - 2 USER and RESET 
- USB Arduino Uno  ST morpho 
-  ST-LINK/V2-1 

[Getting started with STM32 Nucleo board software development tools](https://www.st.com/resource/en/user_manual/dm00105928.pdf)

[STM32 Nucleo (64 pins) schematics](https://www.st.com/resource/en/schematic_pack/nucleo_64pins_sch.zip)

* ST [STM32 Nucleo-64 development board with STM32F401RE MCU](https://www.st.com/zh/evaluation-tools/nucleo-f401re.html)*

## 

 BSP 

| ****   | **** |               ****                 |
| :------------ | :----------: | :-----------------------------------: |
| GPIO          |          | PA0, PA1... PH1 ---> PIN: 0, 1...63    |
| UART          |          |              UART2                     |
| SPI           |          |              SPI1                      |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 Type-A to Mini-B  PC  LED LD3 (PWR)  LD1 (COM) 

#### 

 project.uvprojx  MDK5 

>  ST-LINK 

#### 

 LED  LD3  LD1  LD2 

USB  COM  2115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Mar  7 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO   2  ENV  BSP 

1.  BSP  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32  BSP . md)

## 

 pin  bsp  stm32 bsp  GPIO  bsp 

pin 

| STM32   |  pin |
|--------------|--------------|
| PA0 - PA15   | 0 - 15       | 
| PB0 - PB15   | 16 - 31      | 
| PC0 - PC15   | 32 - 47      |
| PD0 - ...    | 48 - ...     |  

## 

:

- [shaoguoji](https://github.com/shaoguoji) <752147916@qq.com>