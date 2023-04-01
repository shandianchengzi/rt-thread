
# STM32F103  BSP 

## 

FindYGL STM32F103  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

LY-STM32F103C8V1.2  ARM Cortex-M3  72Mhz STM32F103 



![board](figures/board.jpg)

 **** 

- MCUSTM32F103C8T6 72MHz64KB FLASH 20KB RAM
- 
  - LED1LEDLED1PB8
-  JTAG/SWD

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| 	LED          |          |      PB8                         |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PB15 ---> PIN: 0, 1...47|
| UART              |          | UART1                            |
| SPI               |      |                          |
| I2C               |      |                          |
| ADC               |      |                          |
| PWM               |      |                          |
| ****      | **** | ****                         |
|                   |              |                                  |

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

 LED  LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  ADCPWM ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

- [FindYGL](https://github.com/FindYGL) 