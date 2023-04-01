# STM32H747-ST-DISCOVERY  BSP 

## 

 [SummerGift](https://github.com/SummerLife)  STM32H747-ST-DISCOVERY  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32H747I-DISCO  ST  ARM Cortex-M7  480Mhz STM32H747 



![board](figures/board.png)

 **** 

- MCUSTM32H747 480MHz2MB FLASH 1MB RAM
- USB arduino 
-  JTAG/SWD

 ST  [STM32H747I-DISCO](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-discovery-kits/stm32h747i-disco.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          ||
| ****      | **** | ****                              |
| GPIO              |          | |
| UART              |          |   UART1                                  |


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

 project.uvprojx  MDK5 MDK  5.29  ST-LINK V3

>  ST_LINK  ST_LINK 

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Feb 24 2020
 2006 - 2020 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO   1  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  1 

    PA9     ------> USART1_TX

    PA10   ------> USART1_RX 

## 

:

-  [SummerGift](https://github.com/SummerLife)