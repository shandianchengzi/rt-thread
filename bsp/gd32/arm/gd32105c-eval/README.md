# GD32105C-EVALBSP

## 

GD3105C-EVAL-GD32F10X108M GD32105VCT6 



![board](figures/board.jpg)

 **** 

- GD32105VCT6 108MHz256KB FLASH 96KB RAM 
- 
  - LED 5LED1 (LED2PC0LED3PC2LED4PE0LED5PE1
  - 3K1PA0K2PC13K3PB14
  - General TM * 4 Advanced TM * 1Basic TM * 2
  -  * 1
  -  * 2
  - RTC * 1
  - U(S)ART * 5
  - I2C * 2I2S * 2
  - SPI * 3
  - CAN2.0B * 2
  - USB2.0 OTG FS * 1
  - TFT-LCD
  - EXMC/SDRAM * 1
  - ADC * 2
  - DAC * 2
  - 80GPIOs
- USB OTG
- J-LINK



## 

 BSP 

| **** | **** | ****                        |
| :----------- | :----------: | :------------------------------ |
| GPIO         |          | PA0, PA1... ---> PIN: 0, 1...79 |
| UART         |          | UART0 - UART4                   |
| I2C          |          | I2C1                            |
| SPI          |          | SPI0 - SPI2                     |
| SPI FLASH    |          |                                 |
| ADC          |          | ADC0- ADC1                      |
| **** | **** | ****                        |
|          |      |                         |

## 



- 
  
   RT-Thread  RT-Thread  

- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  MDK4MDK5  IAR  GCC RT-Thread Studio MDK5 

#### 

 PCUSB232USART1

#### 

 project.uvprojx  MDK5 

>  J-Link   J-Link  

#### 

LED2

 PC , 115200-8-1-N RT-Thread :

```bash
\ | /
- RT -     Thread Operating System
 / | \     4.1.0 build May 15 2022 14:22:05
 2006 - 2022 Copyright by RT-Thread team
msh >
```

### 

 BSP  GPIO  1 ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

## 



## 

:

- [BruceOu](https://github.com/Ouxiaolong/), <ouxiaolong@bruceou.cn>