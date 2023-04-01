# STM32H743-st-nucleo  BSP 

## 

 tyustli  STM32H743-st-nucleo  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32H743  ST  ARM Cortex-M7  400Mhz STM32H743 



![board](figures/board.jpg)

 **** 

- MCUSTM32H743 400MHz2MB FLASH 1MB RAM
- USB arduino 
-  JTAG/SWD

 ST [STM32H743](https://www.st.com/en/evaluation-tools/nucleo-h743zi.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |  
| ****      | **** | ****                              |
| GPIO              |          | |
| UART              |          |   UART3                                   |


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

>  ST_LINK  ST_LINK 

#### 

LED

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Mar 5 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  3  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 3 

    PD8     ------> USART3_TX

    PD9     ------> USART3_RX 

## 

:

-  [tyustli](https://github.com/tyustli)