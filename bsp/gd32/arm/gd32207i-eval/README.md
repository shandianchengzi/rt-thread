# GD32207I-EVALBSP

## 

GD32207I-EVAL-GD32F20X120M GD32207IK



![board](figures/board.jpg)

 **** 

- GD32207IK 120MHz3MB Flash256KB SRAM

- 

  - LED 5LED1 (LED2PF6LED3PF7LED4PF8LED5PF9
  - 3K1PA0K2PC13K3PB14  
  - General TM * 10 Advanced TM * 2Basic TM * 2
  -  * 1
  -  * 2
  - RTC * 1
  - USART * 4UART * 4
  - I2C * 3I2S * 1
  - SPI * 3
  - SDIO * 1
  - CAN2.0B * 2
  - USB2.0 OTG FS * 1
  - MAC * 1
  - TFT-LCD
  -  * 1 
  - Crypro/Hash * 1
  - EXMC/SDRAM * 1
  - ADC * 3
  - DAC * 2
  - 140GPIOs
  
- GD-LINK

## 

 BSP 

| ****  | **** | ****                                |
|:--------- |:--------:|:------------------------------------- |
| GPIO      |        | PA0, PA1... ---> PIN: 0, 1...143 |
| UART      |        | UART0 - UART7                        |
| I2C       |        | I2C1                                  |
| SPI       |        | SPI0 - SPI2                      |
| SPI FLASH |        |                                       |
| ADC       |        | ADC0 - ADC2                          |
| ****  | **** | ****                                |
|         |      |                                   |

## 



- 
  
   RT-Thread  RT-Thread  

- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  MDK4MDK5  IAR  GCC RT-Thread Studio MDK5 

#### 

 PCUSB232PA9(MCU TX)PA10(MCU RX)

#### 

 project.uvprojx  MDK5 

>  GD-Link   GD-Link  

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.1.0 build May  2 2022 23:45:28
 2006 - 2022 Copyright by RT-Thread team
msh >
```

### 

 BSP  GPIO  0 ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

## 



## 

:

- [BruceOu](https://github.com/Ouxiaolong/), <ouxiaolong@bruceou.cn>