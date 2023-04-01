# NUCLEO-L053R8  BSP 

## 

ST NUCLEO-L053R8  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

NUCLEO-L053R8  ST  ARM Cortex-M0+  Nucleo  ST-LINK/V2-1 /Arduino nano  STM32L053R8 



![board](figures/board.jpg)

 **** 

- MCUSTM32L053R8 32MHz64KB FLASH 8KB RAM
- 
  - LED3USB communication(LD1 ),power LED(LD3 ),user LED(LD2 )
  - 1B1PC13B2RESET
- USB  3  COM arduino 
-  SWD

STMicroelectronics [NUCLEO-L053R8](https://www.st.com/en/evaluation-tools/nucleo-l053r8.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  ST-LINK         |          |                             |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PC15 ---> PIN: 0, 1...47 |
| UART              |          | UART2                             |
| SPI               |      | SPI1                             |
| I2C               |      |  I2C                       |
| RTC               |      |                               |
| PWM               |      |                               |
| USB Device        |      |                              |
| IWG               |      |                                |
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

 LED  LD1  LD3  LD2 

USB  COM  2115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Jan  9 2019
 2006 - 2018 Copyright by rt-thread team
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

:

-  [sun_shine](https://github.com/sunshine0824), <baozitai@163.com>
