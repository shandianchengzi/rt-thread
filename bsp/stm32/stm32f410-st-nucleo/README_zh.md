# STM32F410-Nucleo-64  BSP 

## 

 RT-Thread  STM32F410-Nucleo-64  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32F410-Nucleo-64  ARM Cortex-M4  84Mhz STM32F410RB 



![board](figures/board.png)

 **** 

- MCUSTM32F410RBT6 100MHz128KB FLASH 32KB RAM
- 
  - LED3 USB communication (LD1), user LED (LD2), power LED (LD3) 
  - 2 USER and RESET 
-  ST-LINK/V2-1 

 [STM32F410-Nucleo-64 ](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-f410rb.html)

## 

 BSP 

| **** | **** |               ****                |
| :------------ | :----------: | :-----------------------------------: |
| GPIO         |          | PA0, PA1... ---> PIN: 0, 1...63 |
| UART         |          |              UART2             |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 Type-A to Mini-B  PC  LED LD3 (PWR)  LD1 (COM) 

#### 

 project.uvprojx  MDK5 

>  ST-LINK 

#### 

 LED  LD3  LD1  LD2 

USB  COM  2115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Mar  7 2020
 2006 - 2020 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO   2  ENV  BSP 

1.  BSP  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

- [tanglj86](https://github.com/tanglj86/rt-thread) <tanglj86@gmail.com>