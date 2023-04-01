# STM32G071 BSP

## 

 RT-Thread  STM32G071RB-Nucleo  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32G071RB-Nucleo  ST  ARM Cortex-M0+  64Mhz STM32G071RB 



![board](figures/board.jpg)

 **** 

- MCUSTM32G071RB 64MHz128KB FLASH 36KB RAM
-  RAM
-  FLASH
- 
  - 1userPC13
- USB arduino 
-  SWD

 ST  [NUCLEO ](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-nucleo/nucleo-g071rb.html)

## 

 BSP 

| ****      | **** | ****                                   |
| :----------------- | :----------: | :------------------------------------- |
| ST-LINK  |          |  LPUART                                 |
| ****      | **** | ****                                   |
| GPIO              |          | PA0, PA1... PC15 ---> PIN: 0, 1...47 |
| UART              |          | LPUART1, USART1/2                    |

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

> ST-LinkPC

#### 



 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Dec 21 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO  LPUART  SPII2C  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 

## 

:

-  [gztss](https://github.com/gztss)
