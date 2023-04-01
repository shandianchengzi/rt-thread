# STM32L433 Ali Starterkit BSP 

## 

STM32L433 Ali Starterkit Kit  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

Starter Kit STM32L433[](http://www.notioni.com/) ARM Cortex-M4  80Mhz STM32L433 



![board](figures/board.png)

 **** 

- MCUSTM32L433CCT6  80MHz256KB FLASH 64KB RAM
- 
  - LED2
  - 2APE11BPE10
  - 1
  - 1
  - 1
  - TFTLCD 1
  - WIFI BK72311
  -  ST LINK V2.1 
- ST-LINK Micro USB 

 [](https://github.com/alibaba/AliOS-Things/wiki/AliOS-Things-Starter-Kit-Hardware-Guide)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  ST-LINK  |          | lpuart1 |
|          |         |                              |
|        |         |                             |
|            |         |                                     |
| TFTLCD           |         |                                      |
| WIFI |  | |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PI15 ---> PIN: 0, 1...144 |
| UART              |          | UART1,UART2/3 |
| SPI               |          | SPI1/2 |
| QSPI              |          |                                      |
| I2C               |          |  I2C 2/3/4 |
| TIM               |          | TIM15/16/17 |
| ADC               |          | ADC1 |
| RTC               |          |  |
| WDT               |          |                                      |
| PWM               |          | PWM3 |
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
 / | \     4.1.0 build Dec 27 2021 00:47:23
 2006 - 2021 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  2 SD  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

- [supperthomas](https://github.com/supperthomas)