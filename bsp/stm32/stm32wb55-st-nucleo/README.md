# P-NUCLEO-WB55  BSP 

## 

 P-NUCLEO-WB55  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

P-NUCLEO-WB55  ST  STM32WB55RGNucleo-68)STM32WB55CGUSB Dongle  ARM Cortex-M4Cortex-M0+  64 MHzM432 MHzM0+ STM32WB55 



![board](figures/board.png)

 **** 

- MCUSTM32WB55RG 64MHz1024KB FLASH 256KB RAM
- 
  - LED3LED1PB5LED2PB0LED3PB1
  - 4SW1-PC13,SW2-PD0,SW3-PD1SW4
- USB Arduino Uno  ST morpho 
-  ST-LINK/V2-1 

[P-NUCLEO-WB55](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/stm32-nucleo-expansion-boards/p-nucleo-wb55.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          | UART1 |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PH1 ---> PIN: 0, 1...63 |
| UART              |          | UART1/LPUART1                      |
| SPI               |          | SPI1/2                              |
| I2C               |          |  I2C                              |
| RTC               |      |                               |
| PWM               |      |                               |
| USB Device        |      |                               |
| USB Host          |      |                               |
| IWG               |      |                               |
| ****      | **** | ****                              |
|     xxx       |      |                                      |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

>  ST-LINK  ST-LINK 

#### 

 LED  LED1 

USB  COM  2115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build May 30 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  env  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 

## 

:

-  [Dozingfiretruck](https://gitee.com/Dozingfiretruck), <1473454180@qq.com>