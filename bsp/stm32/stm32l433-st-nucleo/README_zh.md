# NUCLEO-L433RC  BSP 

## 

ST NUCLEO-L433RC  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 NUCLEO-L433RC Cortex-M4 Nucleo  ST-LINK/V2-1 /mirco USB Arduino nano 



![board](figures/board.jpg)

 **** 

- MCUSTM32L433RC 80MHz256KB FLASH 64KB RAM
- 
  - LED4USB communication(LD1 )USB overcurrent(LD2 )power LED(LD3 )user LED(LD4 )
  - 2 USER and RESET 
- USB Arduino Uno  ST morpho 
-  ST-LINK/V2-1 

[STM32 Nucleo](https://www.st.com/resource/zh/user_manual/dm00105928-getting-started-with-stm32-nucleo-board-software-development-tools-stmicroelectronics.pdf)

[NUCLEO-L433RC-P schematic](https://www.st.com/resource/en/schematic_pack/nucleo-l433rc-p_sch.zip)

STMicroelectronics [NUCLEO-L433RC-P](https://www.st.com/content/st_com/zh/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-l433rc-p.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------ |
| GPIO              |          | PA0, PA1... PH1 ---> PIN: 0, 1...63    |
| UART              |          | UART1, UART2                           |
| SPI               |          | SPI1                                   |
| RTC               |          |              |


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

 LED  LD1   LD3  LD4 

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

-  [Sunwancn](https://github.com/Sunwancn), <bwsheng2000@163.com>