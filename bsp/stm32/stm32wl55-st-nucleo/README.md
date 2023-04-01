# NUCLEO-WL55JC2  BSP 

## 

 ST  NUCLEO-WL55JC2  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 NUCLEO-WL55JC2 Cortex-M4 Nucleo  ST-LINK/V3E /mirco USB Arduino nano 



![board](figures/NUCLEO-WL55JC2.png)

 **** 

- MCUSTM32WLJC2 48MHz256KB FLASH 64KB RAM32KB+32KB
- :
  - LEDUSB communication(LED6 ),power LED(LED5 ),3User LED(LED1 LED2 LED3 )
  - (B4)3 User Button(B1B2B3)
- USB  3  COM 
-  ST-LINK/V3E 

STMicroelectronics [STM32WL-Serials](https://www.st.com/en/microcontrollers-microprocessors/stm32wl-series.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  ST-LINK  |          | LPUART1                              |
| ****      | **** | ****                              |
| GPIO              |          | LED1(PB15)\LED2(PB9)\LED3(PB11) |
| UART              |          | LPUART1    |
| ****      | **** | **** |

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

 LED LED6  LED5 LED1\LED2\LED3 

USB  COM LPUART1115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Sep  9 2020
 2006 - 2020 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  LPUART1 ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  RT-Thread  PC .

## 

:

-  [forest-rain] <693097971@qq.com>