# STM32F746-st-disco  BSP 

## 

 jinsheng  STM32F746-disco  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F746-disco  ST  ARM Cortex-M7  216Mhz STM32F746 



![board](figures/board.jpg)

 **** 

- MCUSTM32f746 216MHz1MB FLASH 340KB RAM
- 
  - LED1LED1PI1
  - 2Reset  User
- ST-LINK/V2-1

 [stm32f746-disco ](https://www.st.com/en/evaluation-tools/32f746gdiscovery.html)

 [stm32f746 ](https://www.st.com/en/microcontrollers/stm32f746ng.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB    |          |              UART1                  |
| QSPI Flash        |       |           QSPI1                            |
|             |       |            RMII                   |
| SDRAM             |       |            SDRAM1                           |
| SD              |      |            SD 4bits               |
| 4.3       |      |            LTDC                   |
| MEMS        |      |                               |

| **** | **** |               ****                |
| :----------------- | :----------: | :------------------------------------- |
| GPIO         |          |   PA0, PA1... PK7 ---> PIN: 0, 1...168 |
| UART         |          |              UART1                  |
| TIMER        |          |              Timer11                  |
| SPI               |      |                         |
| QSPI              |      | QSPI1                        |
| I2C               |      |                         |
| FLASH             |      |                         |
| WDT               |      |                         |
| SDIO              |      |                               |
| USB Device        |      |                               |
| USB Host          |      |                               |
| SAI               |      |                               |

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

>  st-link  st-link 

#### 

LED 

 PC 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Jan 30 2019
 2006 - 2018 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO  1  ENV  BSP 

1.  bsp  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:
- [jinsheng](https://github.com/jinsheng20)
