# STM32G071 BSP

## 

 STM32G070RB-Nucleo  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32G070RB-Nucleo  ST  ARM Cortex-M0+  64Mhz STM32G070RB 



![board](figures/board.jpg)

 **** 

- MCUSTM32G070RB 64MHz128KB FLASH 36KB RAM
-  RAM
-  FLASH
- 
  - 1userPC13
- USB arduino 
-  SWD

 ST  [NUCLEO ](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-nucleo/nucleo-g070rb.html)

## 

 BSP 

| ****      | **** |           ****                |
| :----------------- | :----------: | :------------------------------------- |
| ST-LINK  |          |           USART2               |
| ****  | **** |               ****                 |
| GPIO         |          | PA0, PA1... PC15 ---> PIN: 0, 1...47  |
| UART         |          |             USART1/2/3                |
| TIM          |          |               TIM1/3                  |
| PWM          |          |                                       |
| SPI          |          |               SPI1/2                  |
| I2C          |          |                I2C                |
| ADC          |          |                                       |
| WDT          |          |                                       |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| RTC          |       |                              |

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

> ST-LinkPC

#### 



 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Jul  1 2020
 2006 - 2019 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO  UART  SPII2C  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- G0RTC [](https://www.rt-thread.org/qa/thread-424601-1-2.html)

## 

:

-  [NU-LL](https://github.com/NU-LL)
