# STM32F302-Nucleo-64  BSP 

## 

 RT-Thread  STM32F302-Nucleo-64  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32F302-Nucleo-64  ARM Cortex-M4  72 Mhz STM32F302R8 



![board](figures/board.png)

 **** 

- MCUSTM32F302R8T6 72 MHz64KB FLASH 16KB SRAM
- 
  - LED3 LD1, LD2, LD3
  - 2 B1(USER),B2(RESET)
-  ST-LINK/V2-1 

 [STM32F302-Nucleo-64 ](https://www.st.com/en/evaluation-tools/nucleo-f302r8.html)

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

 Type-A to Mini-B  PC 

#### 

 project.uvprojx  MDK5 

>  ST-LINK 

#### 



USB  COM  2 RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Mar  7 2021
 2006 - 2021 Copyright by rt-thread team
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

- [Mr.Tiger](https://github.com/MrYangMouren/rt-thread)<1039241323@qq.com>

