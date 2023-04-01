# STM32L475  BSP 

## 

 RT-Thread  STM32L475  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32L475  ARM Cortex-M4  80Mhz STM32L475 



![board](figures/board.png)

 **** 

- MCUSTM32L475VET6 80MHz512KB FLASH 128KB RAM
-  FLASHW25Q128  NM25Q128EVBSPI16MB
- 
  - RGB 1
  - 4KEY_UPPC13K0PD10K1PD9K2PD8
  - 
  - 1
  - 1
  - 1
  - 1
  - 1
  - AHT101
  - TFTLCD 1
  - WIFI AP61811
  -  ST LINK V2.1 
- SD USB OTGMicro USB 
- ST-LINK Micro USB 

 [STM32 ](https://eboard.taobao.com/index.htm)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------ |
|  ST-LINK  |          |                                    |
| QSPI_FLASH         |          |                                   |
| SD                |          |  SPI1  |
|         |         |                             |
|          |         |                              |
|            |         |                                     |
| TFTLCD           |         |  SPI3  |
|            |         |                      |
|        |         |                           |
| AP6181 WIFI  |  | SDIO  |
| ****      | **** | ****                              |
| GPIO              |          |                                      |
| UART              |          |                                      |
| SPI               |          |                                      |
| QSPI              |          |                                      |
| I2C               |          |                                      |
| TIM               |          |                                      |
| ADC               |          |                                      |
| RTC               |          |  |
| WDT               |          |                                      |
| PWM               |          |                                      |
| USB Device        |      |                          |
| USB Host          |      |                               |
| ****      | **** | ****                              |
| NRF24L01   |         |  NRF24L01  `NRF24L01_CE_PIN`  `NRF24_IRQ_PIN`  SPI  |
| ATK-ESP8266   |      |                               |
| ENC28J60   |         |                               |
 RT-Thread  [RT-Thread IoT-Board SDK](https://github.com/RT-Thread/IoT_Board)

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

 BSP  GPIO  1  SD Flash  ENV  BSP 

1.  bsp  ENV 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

ST-Linkhttps://github.com/armink/HackSTLinkUpgrade

## 

:

- [SummerGift](https://github.com/SummerGGift)