# AT32F425 AT-START  BSP 

## 

AT32F425 AT-STARTAT32F425MCU

|       |           |
| --------- | ------------- |
|   | AT32F425R8T7  |
| CPU       | ARM Cortex M4 |
|       | 96M           |
| SRAM  | 20K           |
| FLASH | 64K           |

## 

AT32F425-STARTMDK4MDK5IARGCC

| IDE/ |                    |
| ---------- | ---------------------------- |
| MDK4       | MDK4.74                      |
| MDK5       | MDK531                       |
| IAR        | IAR8.20                      |
| GCC        | GCC 5.4.1 20160919 (release) |

## 

- MCUAT32F425R8T7 96MHz64KB FLASH 20KB RAM
- 
  - LED3PC2PC3PC5
  - 1KEY_USERPA0)
- J8
-  AT-LINK SWD 

## 

 BSP 

|       |  |                        |
| --------- | -------- | :------------------------: |
| UART      |      | USART1/2/3                 |
| GPIO      |      | PA0...PF7                  |
| IIC       |      | GPIOI2C                |
| SPI       |      | SPI1/2                     |
| ADC       |      | ADC1                       |
| PWM       |      | TMR1/2                     |
| HWTIMER   |      | TMR3                       |
| CAN       |      | CAN1                       |
| WDT       |      |                            |
| RTC       |      |                            |
| FLASH     |      |                            |
| USB       |      |                            |

### IO

| IO |  |
| ---- | -------------- |
| PC2  | LED2           |
| PC3  | LED3           |
| PC5  | LED4           |
| PA9  | USART1_TX      |
| PA10 | USART1_RX      |
| PA2  | USART2_TX      |
| PA3  | USART2_RX      |
| PB10 | USART3_TX      |
| PB11 | USART3_RX      |
| PA4  | SPI1_NSS       |
| PA5  | SPI1_SCK       |
| PA6  | SPI1_MISO      |
| PA7  | SPI1_MOSI      |
| PB12 | SPI2_NSS       |
| PB13 | SPI2_SCK       |
| PB14 | SPI2_MISO      |
| PB15 | SPI2_MOSI      |
| PB6  | I2C1_SCL       |
| PB7  | I2C1_SDA       |
| PA8  | PWM_TMR1_CH1   |
| PA11 | PWM_TMR1_CH4   |
| PA0  | PWM_TMR2_CH1   |
| PA1  | PWM_TMR2_CH2   |
| PC0  | ADC1_IN10      |
| PC1  | ADC1_IN11      |
| PC2  | ADC1_IN12      |
| PC3  | ADC1_IN13      |
| PC4  | ADC1_IN14      |
| PC5  | ADC1_IN15      |
| PB8  | CAN1_RX        |
| PB9  | CAN1_TX        |
| PA11 | USB_DM         |
| PA12 | USB_DP         |

## 

     RT-Thread  RT-Thread  

### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

> AT-LINK SWDAT-LINK SWD

#### 

 LED LED2/3/4 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Jan 29 2023 17:05:16
 2006 - 2022 Copyright by RT-Thread team
msh >
```

## 

Keil_v5/Keil_v4/IARpackAT-STARTwww.arterytek.com

## 

:

- [sheltonyu]