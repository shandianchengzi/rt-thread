# STM32F767  BSP 

## 

 RT-Thread  STM32F767  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32F767  ARM Cortex-M7  216Mhz STM32F767 



![board](figures/board.jpg)

 **** 

- MCUSTM32f767 216MHz1MB FLASH 512KB RAM16K CACHE
-  SDRAMW9825G6KH32MB
-  NAND FLASH MT29F4G08512MB
-  SPI FLASH W25Q25632M 
- 
  - LED2DS0PB1DS1PB0
  - 4KEY_UPPA0K0PH3K1PH2K2PC13
- USB SD LCD 
-  JTAG/SWD

 [STM32 ](https://eboard.taobao.com/index.htm)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |           |                                       |
| RS232             |          |  CubeMX  UART2  |
| QSPI Flash        |          |                                       |
|             |           |                                        |
| MPU9250 |           |                                       |
| SDRAM             |          |                                       |
| SD              |           |                                       |
| CAN               |      |                                       |
| EMW1062 |  | |
| ****      | **** | ****                              |
| GPIO              |          | PA0PA1... PK15 ---> PIN: 01...176 |
| UART              |          |                                       |
| SPI               |          | SPI2 |
| I2C               |          |  I2C                              |
| ADC               |         |                                     |
| RTC               |          |  |
| WDT               |          |                                       |
| PWM               |          |                                       |
| SDIO              |          |                                       |
| FLASH             |          |                                       |
| USB Device        |      |                               |
| USB Host          |      |                               |
| ****      | **** | ****                              |
|          |      |                               |

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

>  Jlink  Jlink 

#### 

LED 

 PC 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Dec 10 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

- [BalanceTWK](https://github.com/balanceTWK)
