# STM32F429  BSP 

## 

 RT-Thread  STM32F429  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32F429  ARM Cortex-M4  180Mhz STM32F429 



![board](figures/board.png)

 **** 

- MCUSTM32F429IGT6 180MHz1024KB FLASH 256KB RAM
-  RAMW9825G6KHSDRAM32MB
-  FLASHW25Q256SPI32MBMT29F4G08NAND512MB
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
| USB         |          |                                       |
| COM2              |          | PWM  CubeMX  UART2  |
| COM3              |          |  CubeMX  UART3  |
| SPI Flash         |          |                                       |
|             |          |                                       |
| MPU9250 |          |                                       |
| SDRAM             |          |                                       |
| SD              |      |                                       |
| CAN               |      |    USB Host  CubeMX                                      |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART              |          | UART1/2/3                             |
| SPI               |          | SPI1/2/5                              |
| I2C               |          |  I2C                              |
| CAN               |          | PA12->TX, PA11->RX                                   |
| ADC               |          |                                     |
| RTC               |          |  |
| WDT               |          |                                       |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| SDIO              |      |                               |
| PWM               |      |                               |
| USB Device        |      |                               |
| USB Host          |      |  CAN1  CubeMX                          |
| ****      | **** | ****                              |
| ATK-ESP8266   |      |                               |

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

>  JLink  JLink 

#### 

 LED  LED 

 PC , 115200-8-1-N RT-Thread :

>  PuTTyXShell sscom

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
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

- [SummerGift](https://github.com/SummerGGift)