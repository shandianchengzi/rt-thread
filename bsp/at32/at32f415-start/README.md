# AT32F415 AT-START  BSP 

## 

AT32F415 AT-STARTAT32F415MCU

|       |           |
| --------- | ------------- |
|   | AT32F415RCT7  |
| CPU       | ARM Cortex M4 |
|       | 150M          |
| SRAM  | 32K           |
| FLASH | 256K          |

## 

AT32F415-STARTMDK4MDK5IARGCC

| IDE/ |                    |
| ---------- | ---------------------------- |
| MDK4       | MDK4.74                      |
| MDK5       | MDK531                       |
| IAR        | IAR8.20                      |
| GCC        | GCC 5.4.1 20160919 (release) |

## 

- MCUAT32F415RCT7 150MHz256KB FLASH 32KB RAM
- 
  - LED3PC2PC3PC5
  - 1KEY_USERPA0)
- J8
- JLINK AT-LINK SWD 

## 

 BSP 

|       |  |                        |
| --------- | -------- | :------------------------: |
| UART      |      | USART1/2/3                 |
| GPIO      |      | PA0...PF5                  |
| IIC       |      | GPIOI2C                |
| SPI       |      | SPI1/2                     |
| ADC       |      | ADC1                       |
| PWM       |      | TMR1/2                     |
| HWTIMER   |      | TMR3/4/5                   |
| SDIO      |      | SDIO1                      |
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
| PC8  | SDIO1_D0       |
| PC9  | SDIO1_D1       |
| PC10 | SDIO1_D2       |
| PC11 | SDIO1_D3       |
| PC12 | SDIO1_CK       |
| PD2  | SDIO1_CMD      |
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
 / | \     4.1.0 build May 11 2022
 2006 - 2022 Copyright by RT-Thread team
msh />
```

## 

Keil_v5/Keil_v4/IARpackAT-STARTwww.arterytek.com

## 

:

- [sheltonyu]