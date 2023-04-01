# AT32F421 AT-START  BSP 

## 

AT32F421 AT-STARTAT32F421MCU

|       |           |
| --------- | ------------- |
|   | AT32F421C8T7  |
| CPU       | ARM Cortex M4 |
|       | 120M          |
| SRAM  | 16K           |
| FLASH | 64K           |

## 

AT32F421-STARTMDK4MDK5IARGCC

| IDE/ |                    |
| ---------- | ---------------------------- |
| MDK4       | MDK4.74                      |
| MDK5       | MDK531                       |
| IAR        | IAR8.20                      |
| GCC        | GCC 5.4.1 20160919 (release) |

## 

- MCUAT32F421C8T7 120MHz64KB FLASH 16KB RAM
- 
  - LED3PF6PF7PB11
  - 1KEY_USERPA0)
- J8
- JLINK AT-LINK SWD 

## 

 BSP 

|       |  |                        |
| --------- | -------- | :------------------------: |
| UART      |      | USART1/2                   |
| GPIO      |      | PA0...PF7                  |
| IIC       |      | GPIOI2C                |
| SPI       |      | SPI1/2                     |
| ADC       |      | ADC1                       |
| PWM       |      | TMR1                       |
| HWTIMER   |      | TMR3                       |
| WDT       |      |                            |
| RTC       |      |                            |
| FLASH     |      |                            |

### IO

| IO |  |
| ---- | -------------- |
| PF6  | LED2           |
| PF7  | LED3           |
| PB11 | LED4           |
| PA9  | USART1_TX      |
| PA10 | USART1_RX      |
| PA2  | USART2_TX      |
| PA3  | USART2_RX      |
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
| PA0  | ADC1_IN0       |
| PA1  | ADC1_IN1       |
| PA4  | ADC1_IN4       |
| PA5  | ADC1_IN5       |
| PA6  | ADC1_IN6       |

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
 / | \     5.0.0 build Jan 18 2023 09:19:32
 2006 - 2022 Copyright by RT-Thread team
msh />
```

## 

Keil_v5/Keil_v4/IARpackAT-STARTwww.arterytek.com

## 

:

- [sheltonyu]