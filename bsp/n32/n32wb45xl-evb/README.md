# N32WB45XL_EVB BSP 

## 

N32WB45XL_EVB N32WB452MCU

|       |           |
| --------- | ------------- |
|   | N32WB452LEQ6  |
| CPU       | ARM Cortex M4 |
|       | 144M          |
| SRAM  | 144K          |
| FLASH | 512K          |

## 

N32WB45XL_EVB MDK5GCC

| IDE/ |                    |
| ---------- | ---------------------------- |
| MDK5       | V5.34                        |
| IAR        | V8.50                        |
| GCC        | GCC 6.2.1 20161205 (release) |

## 

- MCUN32WB452LEQ6 144MHz512KB FLASH
- 
  - LED 4D1 (PD0)D10PD1D11PE2D12PE3
  - 4S2(RST)S3WKUP/PA0K04PD8K05PD9

- USB (J4)
- :  CMSIS-DAP SWD (J3)JLINK

## 

 BSP 

|       |   |                                  |
| --------- | --------  | -------------------------------------|
| UART      |       | USART1/2/3, UART4/5/6/7              |
| GPIO      |       | PA0, PA1... PE15 ---> PIN: 0, 1...79 |
| I2C       |       | I2C                              |
| SPI       |       | SPI1/2/3                             |
| ADC       |       | ADC1/2                               |
| CAN       |       | CAN1/2                               |
| DAC       |       | DAC1/2                               |
| HWTIMER   |       | TIMER1/2/3/4/5/6/7/8                 |
| WDT       |       | IWDG                                 |
| RTC       |       | LSE/LSI/HSE                | 

### IO

| IO |  |
| ---- | -------------- |
| PA9  | USART1_TX      |
| PA10 | USART1_RX      |

| PA2  | USART2_TX      |
| PA3  | USART2_RX      |

| PB10 | USART3_TX      |
| PB11 | USART3_RX      |

| PA13 | UART4_TX       |
| PA14 | UART4_RX       |

| PB13 | UART5_TX       |
| PB14 | UART5_RX       |

| PB0  | UART6_TX       |
| PB1  | UART6_RX       |

| PC2  | UART7_TX       |
| PC3  | UART7_RX       |

| PA4  | SPI1_NSS       |
| PA5  | SPI1_SCK       |
| PA6  | SPI1_MISO      |
| PA7  | SPI1_MOSI      |

| PB12 | SPI2_NSS       |
| PB13 | SPI2_SCK       |
| PB14 | SPI2_MISO      |
| PB15 | SPI2_MOSI      |

| PA15 | SPI3_NSS       |
| PB3  | SPI3_SCK       |
| PB4  | SPI3_MISO      |
| PB5  | SPI3_MOSI      |

| PA1  | ADC1_IN2       |
| PA3  | ADC1_IN4       |

| PA4  | ADC2_IN1       |
| PA5  | ADC2_IN2       |

| PA4  | DAC_OUT1       |
| PA5  | DAC_OUT2       |

| PB8  | CAN1_RX        |
| PB9  | CAN1_TX        |

| PB12 | CAN2_RX        |
| PB13 | CAN2_TX        |

## 

 RT-Thread  RT-Thread  

### 

 BSP  MDK5IAR GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

#### 

 LED D1 

 PC , 115200-8-1-N RT-Thread :

```
 \ | /
- RT -     Thread Operating System
 / | \     4.1.1 build Apr 24 2022 17:24:22
 2006 - 2022 Copyright by RT-Thread team
msh >
```

## 



## 

:

- [WangQian](https://github.com/NationsHuanghanbin)
