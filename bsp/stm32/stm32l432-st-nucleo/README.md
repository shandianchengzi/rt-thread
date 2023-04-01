# NUCLEO32-L432  BSP 

## 

ST NUCLEO32-L432  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 NUCLEO32-L432 Cortex-M4 Nucleo  ST-LINK/V2-1 /mirco USB Arduino nano 



![board](figures/board.jpg)

 **** 

- MCUSTM32L432KC 80MHz256KB FLASH 64KB RAM
- 
  - LED3USB communication(LD1 ),power LED(LD2 ),user LED(LD3 )
  - 1(B1)
- USB  3  COM 
-  ST-LINK/V2-1 

STMicroelectronics [NUCLEO-L432KC](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-nucleo/nucleo-l432kc.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  ST-LINK  |          | UART2                              |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PC15 ---> PIN: 0, 1...47 |
| UART              |          | UART2                             |
| SPI               |      | SPI1                             |
| I2C               |      |  I2C                       |
| RTC               |         |  |
| PWM               |      |                               |
| USB Device        |      |                              |
| IWG               |         |               |
| ****      | **** | ****                              |


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

 LED  LD1  LD2  LD3 

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

-  RT-Thread BSP GPIO 
-  RT-Thread  PC 

## 

:

-  [sun_shine](https://github.com/sunshine0824), <baozitai@163.com>