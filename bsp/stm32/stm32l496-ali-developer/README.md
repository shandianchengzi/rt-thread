# STM32L496 Ali Develoeprkit BSP 

## 

 RT-Thread  STM32L496 Ali Developer Kit  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

Developer Kit STM32L496 [](http://www.notioni.com/) ARM Cortex-M4  80Mhz STM32L496 



![board](figures/board.png)

 **** 

- MCUSTM32L496VGT6  80MHz1MB FLASH 320KB RAM
- 
  - LED3
  - 3APE11MPE14BPE10
  - 1
  - 1
  - 1
  - 1
  - 1
  - SHTC11
  - TFTLCD 1
  - WIFI BK72311
  -  ST LINK V2.1 
- SD USB OTG Micro USB 
- ST-LINK Micro USB 

 [](https://github.com/alibaba/AliOS-Things/wiki/AliOS-Things-Developer-Kit-Hardware-Guide)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  ST-LINK  |          | lpuart1 |
| SD               |          |                                       |
|         |         |                             |
|          |         |                              |
|        |         |                             |
|            |         |                                     |
| TFTLCD           |         |                                      |
| WIFI |  | |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PI15 ---> PIN: 0, 1...144 |
| UART              |          | LPUART1,UART2/3 |
| SPI               |          | SPI1/2 |
| QSPI              |          |                                      |
| I2C               |          |  I2C 2/3/4 |
| TIM               |          | TIM15/16/17 |
| ADC               |          | ADC1 |
| RTC               |          |  |
| WDT               |          |                                      |
| PWM               |          | PWM3 |
| USB Device        |      |                               |
| USB Host          |      |                               |
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

>  ST-LINK  USB 

#### 

 LED  LED 

 PC , 115200-8-1-N RT-Thread :


```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  SD  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

- [guozhanxin](https://github.com/guozhanxin)