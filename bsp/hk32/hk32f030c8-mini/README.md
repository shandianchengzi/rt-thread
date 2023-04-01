# HK32F030C8T6-MINI BSP 

## 



![board](figures/board.jpg)

HK32F030C8T6-MINIHK32F030C8T6MCU

|       |           |
| --------- | ------------- |
|   | HK32F030C8T6  |
| CPU       | ARM Cortex M0 |
|       | 72M           |
| SRAM  | 10K           |
| FLASH | 64K           |

## 

HK32F030C8T6-MINIMDK5GCC

| IDE/ |                    |
| ---------- | ---------------------------- |
| MDK5       | MDK523                       |
| GCC        | GCC 5.4.1 20160919 (release) |

## 

- MCUHK32F030C8T6 72MHz64KB FLASH 10KB RAM
- 
  - LED2VCCPB4
  - 2KEY1(PA1)WK_UPPA0)
  - NRF24L01
  - OLED
  - EEPROM(M24C08,8K bits)
- J10
- JTAG

## 

 BSP 

|     |  |         |
| ------- | -------- | :---------: |
| UART    |      |  USART1/2   |
| GPIO    |      |  PA0...PF7  |
| IIC     |      | GPIOI2C |
| SPI     |      |    SPI1     |
| ADC     |    |             |
| PWM     |    |             |
| HWTIMER |    |             |
| WDT     |    |             |
| RTC     |    |             |
| FLASH   |    |             |

### IO

| IO |  |
| ---- | -------------- |
| PB4  | LED            |
| PA1  | KEY1           |
| PA0  | KEY_WKUP       |
| PB6  | USART1_TX      |
| PB7  | USART1_RX      |
| PA2  | USART2_TX      |
| PA3  | USART2_RX      |
| PA4  | SPI1_NSS       |
| PA5  | SPI1_SCK       |
| PA6  | SPI1_MISO      |
| PA7  | SPI1_MOSI      |
| PB8  | I2C1_SCL       |
| PB9  | I2C1_SDA       |
| PB10  | I2C2_SCL       |
| PB11  | I2C2_SDA       |

## 

     RT-Thread  RT-Thread  

### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

>  JLink  JLink 

#### 

 LED LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Mar  9 2020
 2006 - 2020 Copyright by rt-thread team
msh />
```

## 

Keil_v5/Keil_v4/IARpackHK-MINIhttp://www.hsxp-hk.com/

## 

:

- [jonas](https://github.com/JonasWen) 