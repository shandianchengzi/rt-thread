
# NUCLEO-L010RB  BSP 

## 

ST NUCLEO-L010RB  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

NUCLEO-L010RB  ST  ARM Cortex-M0+  Nucleo  ST-LINK/V2-1 /Arduino nano  STM32L010RB 



![board](figures/board.jpg)

 **** 

- MCUSTM32L010RB
	-  32MHz
	- 128KB FLASH
	- 20KB RAM
	- 512 byte EEPROM
- 
  - LED3USB communication(LD1 )power LED(LD3 )user LED(LD2 )
  - 1B1PC13B2RESET
- USB  3  COM arduino 
-  SWD

[STMicroelectronics NUCLEO-L010RB](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-l010rb.html#overview)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  ST-LINK         |          |                             |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PC15 ---> PIN: 0, 1...47 |
| UART              |          | UART2                             |
| SPI               |      |                            |
| I2C               |      |                     |
| RTC               |      |                        |
| PWM               |      |                       |
| USB Device        |      |                      |
| IWG               |      |                         |
| ****      | **** | ****                                                                  |

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

 LED  LED1  LED3  LED2 

USB  COM  2115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Apr  9 2020
 2006 - 2020 Copyright by rt-thread team
msh >

```
### 

 BSP  GPIO   2  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  RT-Thread BSP GPIO 
-  RT-Thread  PC 

## 

- : [xph](https://github.com/xupenghu)
- <xupenghu@outlook.com>
