# NUCLEO-L476RG  BSP 

## 

 ST  (64)NUCLEO-L476RG  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 NUCLEO-L476RG Cortex-M4 Nucleo  ST-LINK/V2-1 /mirco USB Arduino nano 



![board](figures/board.png)

 **** 

- MCUSTM32L476RG 80MHz1024KB FLASH 128KB RAM96+32
- 
  - LED3USB communication(LD1 ),power LED(LD3 ),user LED(LD2 )
  - 1(B1)
- USB  3  COM 
-  ST-LINK/V2-1 

STMicroelectronics [NUCLEO-L476RG](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-nucleo/nucleo-l476rg.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  ST-LINK  |          | UART2                              |
| ****      | **** | ****                              |
| GPIO              |          |          |
| UART              |          | UART2    |
| IIC               |          |  |
| RTC               |          |  |
| SPI               |          | SPI1/2/3 |
| ADC               |          | ADC1_IN1/ADC2_IN2/ADC3_IN3 |
| TIME              |          | TIME15/16/17 |
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

 BSP  GPIO  2  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  RT-Thread  PC  BSP  GPIO 

## 

:

-  [GW] <gycgwzw@gmail.com>