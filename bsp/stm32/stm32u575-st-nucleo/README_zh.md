# NUCLEO-U575ZI-Q  BSP 

## 

 liukang  NUCLEO-U575ZI-Q  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32U575ZI  ST  ARM Cortex-M33  160 Mhz STM32U575 



![board](figures/board.png)

 **** 

- MCUSTM32U575ZI 160 MHz2048KB FLASH 786KB RAM
- USB USB arduino 
-  JTAG/SWD

 ST [STM32U575ZI](https://www.st.com/en/evaluation-tools/nucleo-u575zi-q.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          ||
| ****      | **** | ****                              |
| GPIO              |          | |
| UART              |          |   UART1                           |


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
 / | \     4.0.4 build Nov 14 2021 21:15:06
 2006 - 2021 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  UART1  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  UART1 1 

  ```c
  PA9     ------> USART1_TX
  PA10     ------> USART1_RX
  ```

## 

:

-  [liukang](https://github.com/liukangcc)

