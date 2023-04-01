# GD32303E-EVALBSP

## 

GD3303E-EVAL-GD32F30X120M GD32303ZET6 

 **** 

- GD32303ZET6 120MHz512KB FLASH 64KB RAM 
- 
  
  - LED 5LED1 (LED2PF0LED3PF1LED4PF2LED5PF3
  - 4K1PA0K2PC13K3PF5K4PF4
  - General TM * 4Advanced TM * 2Basic TM * 2
  -  * 1
  -  * 2
  - RTC * 1
  - USART * 3UART * 2
  - I2C * 2I2S * 2
  - SPI * 3
  - CAN2.0B * 1
  - USB2.0 OTG FS * 1
  - TFT-LCD
  - EXMC/SDRAM * 1
  - ADC * 3
  - DAC * 2
  - 112GPIOs
- USB 
- GD-LINK

## 

 BSP 

| **** | **** | ****                         |
| :----------- | :----------: | :------------------------------- |
| GPIO         |          | PA0, PA1... ---> PIN: 0, 1...111 |
| UART         |          | UART0 - UART4                    |
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

 PCUSB232USART1

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