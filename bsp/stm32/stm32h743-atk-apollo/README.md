# STM32H743-atk-apollo  BSP 

## 

 whj4674672  STM32H743-atk-apollo  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32H743  ARM Cortex-M7  400Mhz STM32H743 



![board](figures/board.jpg)

 **** 

- MCUSTM32H743 400MHz2MB FLASH 1MB RAM
-  SDRAMW9825G6KH32MB
-  NAND FLASHH27U4G8F2512MB
-  QSPI FLASHW25Q25632MB
- 
  - LED2DS0PB1DS1PB0
  - 4KEY_UPPA0K0PH3K1PH2K2PC13
- USB SD LCD 
-  JTAG/SWD

 [STM32](https://eboard.taobao.com/index.htm)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| COM2        |          |                                       |
| QSPI Flash        |          |                                       |
|             |      |                                       |
| SD              |      |                                       |
| CAN-FD             |      |                                       |
| SDRAM             |          |                                       |
| LCD               |          |                                       |
| MPU9250 |      |                                       |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART              |          |                                       |
| SPI               |      | SPI2 |
| I2C               |      | PCF8574 |
| SDIO              |      |                                       |
| RTC               |          |                                       |
| PWM               |      |                                       |
| USB Device        |      |                                       |
| USB Host          |      |                                       |
| IWG               |          |                                       |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |

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

 BSP  GPIO  1  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

1. UART2 DMAHEAPCACHEWTrt_device_readSCB_InvalidateDCache_by_AddrSCB_InvalidateDCache
2. FALFLASH32

## 

:

-  [whj4674672](https://github.com/whj4674672), <whj4674672@163.com>