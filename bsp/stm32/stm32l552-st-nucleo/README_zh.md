# NUCLEO-L552ZE-Q  BSP 

## 

 liukang  NUCLEO-L552ZE-Q  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32L552ZE  ST  ARM Cortex-M33  110Mhz STM32L552 



![board](figures/board.png)

 **** 

- MCUSTM32L552ZE 110MHz256KB FLASH 256KB RAM
- USB USB arduino 
-  JTAG/SWD

 ST [STM32L552ZE]([NUCLEO-L552ZE-Q - STM32 Nucleo-144 development board with STM32L552ZE MCU, SMPS, supports Arduino, ST Zio and morpho connectivity - STMicroelectronics](https://www.st.com/en/evaluation-tools/nucleo-l552ze-q.html))

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          ||
| ****      | **** | ****                              |
| GPIO              |          | |
| UART              |          |   LPUART1                           |


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

 BSP  GPIO  LPUART1  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  LPUART1 1 

  PG7     ------> LPUART1_TX
  PG8     ------> LPUART1_RX

## 

:

-  [liukang](https://github.com/liukangcc)

