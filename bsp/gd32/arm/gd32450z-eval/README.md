# GD32450Z-EVALBSP

## 

GD32450Z-EVAL-GD32F4XX168M GD32F450ZKT6

 **** 

- GD32F450ZKT6 200MHz3072KB FLASH 256KB RAM 

- 
  
  - LED 3LED1 (PD4LED2PD5LED3PG3
  - 2K1PA0K2PC13K3PB14
  - General TM * 10Advanced TM * 2Basic TM * 2
  -  * 1
  -  * 2
  - RTC * 1
  - USART * 4UART * 4
  - I2C * 3I2S * 2
  - SPI * 6
  - CAN2.0B * 2
  - USB2.0 OTG * 2
  -  * 1
  - TFT-LCD
  - EXMC/SDRAM * 1
  - ADC * 3
  - DAC * 2
  - 114GPIOs
- USB 

- GD-LINK

## 

 BSP 

| **** | **** | ****                         |
| :----------- | :----------: | :------------------------------- |
| GPIO         |          | PA0, PA1... ---> PIN: 0, 1...113 |
| UART         |          | UART0 - UART7                    |
| I2C          |          | I2C1                             |
| SPI          |          | SPI0 - SPI2                      |
| SPI FLASH    |          |                                  |
| ADC          |          | ADC0 - ADC2                      |
| **** | **** | ****                         |
|          |      |                          |

## 



- 
  
   RT-Thread  RT-Thread  

- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  MDK4MDK5  IAR  GCC RT-Thread Studio MDK5 

#### 

 PCUSB232USART0

#### 

 project.uvprojx  MDK5 

>  GD-Link   GD-Link  

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Jan  9 2021
 2006 - 2021 Copyright by rt-thread team
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