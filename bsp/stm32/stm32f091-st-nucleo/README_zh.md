# NUCLEO-F091RC  BSP 

## 

 RT-Thread  STM32F091RC-NUCLEO  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F091RC-NuCLEO  ST  ARM Cortex-M0  48Mhz STM32F091 



![board](figures/board.jpg)

 **** 

- MCUSTM32F091RC 48MHz256KB FLASH 32KB RAM
-  RAM
-  FLASH
- 
  - 1userPC13
- USB arduino 
-  SWD

[NUCLEO-F091RC](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-f091rc.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| ST-LINK  |          |  USART2 |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PC15 ---> PIN: 0, 1...64 |
| UART              |          | USART1/2                            |
| SPI               |          | SPI1                              |
| I2C |  |  |
| TIMER     |          |                               |
| ADC |  |  |
| RTC               |      |  |
| PWM               |      |                               |
| FLASH |  |  |
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



 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Dec 21 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO   2  SPII2C  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 

## 

:

-  [zylx](https://github.com/qgyhd1234)