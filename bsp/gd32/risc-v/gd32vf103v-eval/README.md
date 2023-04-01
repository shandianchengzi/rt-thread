# GD32VF103V_EVALBSP

## 

GD32VF103V_EVAL-GD32VF1108M GD32VF103VB 



![board](figures/board.jpg)

 **** 

- GD32VF103VBT6  108MHz128KB FLASH 32KB RAM 
- 
  - LED 4LED1PC0LED2PC2LED3PE0LED4PE1
  - 2K1K2PA0, PC13, PB14, PC5, PC4)
  - General TM * 4 Advanced TM * 1Basic TM * 2
  -  * 1
  -  * 2
  - RTC * 1
  - USART * 3UART * 2
  - I2C * 2I2S * 2
  - SPI * 3
  - CAN2.0B * 2
  - USB2.0 OTG FS * 1
  - TFT-LCD
  - EXMC/SDRAM * 1
  - ADC * 2
  - DAC * 2
  - 80GPIOs
- GD-Link/J-link

## 

 BSP 

| ****  | **** | ****                                |
|:--------- |:--------:|:------------------------------------- |
| GPIO      |        | PA0, PA1... ---> PIN: 0, 1...79 |
| UART      |        | UART0 - UART4                         |
| I2C       |        | I2C1                                  |
| SPI       |        | SPI0 - SPI2                           |
| ADC       |        | ADC0 - ADC2                            |
| ****  | **** | ****                                |
|         |      |                                   |

## 



- 
  
   RT-Thread  RT-Thread  

- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  GCC 

#### 

 PCUSB232USART0

#### 

`scons `J-link/GD-Link

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.1.1 build Jun  8 2022 00:49:01
 2006 - 2022 Copyright by RT-Thread team
msh >
```

### 

 BSP  GPIO  0 ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons `

## 



## 

:

- [BruceOu](https://github.com/Ouxiaolong/), <ouxiaolong@bruceou.cn>