# NUCLEO-F446ZE  BSP 

## 

 NUCLEO-F446ZE  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

NUCLEO-F446ZE  ST  STM32F4  Cortex-M4 Nucleo-144  mbed ArduinoST Zio ST Morpho 



![board](figures/board.jpg)

 **** 

- MCUSTM32f446ZE 180MHz512KB FLASH 128KB RAM
- 
  - LED3LED1 (PB0),LED2PB7LED3PB14
- USB 
-  ST-LINK/SWD

NUCLEO-F446ZE [](https://www.st.com/zh/evaluation-tools/nucleo-f446ze.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| ****      | **** | ****                              |
| GPIO              |          |                                       |
| UART              |          | UART1                                 |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC,,

#### 

 project.uvprojx  MDK5 

>  ST-LINK  ST-LINK 

#### 

 LED2  500MS 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Jan  7 2019
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  3  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  UART1

## 

:

-   <qihengchuan8888@163.com>