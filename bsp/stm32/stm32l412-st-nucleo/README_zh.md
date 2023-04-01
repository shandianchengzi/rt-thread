# NUCLEO32-L412  BSP 

## 

ST NUCLEO32-L412  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 NUCLEO32-L412 Cortex-M4 Nucleo  ST-LINK/V2-1 /mirco USB Arduino nano 



![board](figures/board.jpg)

 **** 

- MCUSTM32L412RB 80MHz128KB FLASH 40KB RAM
- 
  - LED4LD1COM LD25V_USB LD35V_PWR LD4USER 
  - 2B1B2
- USB  3  COM 
-  ST-LINK/V2-1 

STMicroelectronics [NUCLEO-L412RB-P](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-l412rb-p.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  ST-LINK  |          | UART2                            |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PC15 ---> PIN: 0, 1...47 |
| UART              |          | UART2                           |
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
 / | \     4.0.3 build Apr 24 2020
 2006 - 2020 Copyright by rt-thread team
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

-  [luhuadong](https://github.com/luhuadong), <luhuadong@163.com>