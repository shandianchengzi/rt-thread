# N32L40XCL_STB BSP 

## 

N32L40XCL_STB N32L406MCU

|       |           |
| --------- | ------------- |
|   | N32L406CBL7   |
| CPU       | ARM Cortex M4 |
|       | 64M           |
| SRAM  | 24K           |
| FLASH | 128K          |

## 

N32L40XCL_STB MDK5GCC

| IDE/ |                     |
| ---------- | ---------------------------- |
| MDK5       | V5.34                        |
| IAR        | V8.50                        |
| GCC        | GCC 6.2.1 20161205 (release) |

## 

- MCUN32L406CBL7 64MHz128KB FLASH
- 
  - LED 3LED1 (PA8)LED2PB4LED3PB5
  - 5RESET(NRST)WAKEUPPA0KEY1PA4KEY2PA5KEY3PA6

- USB (J3)
- :  CMSIS-DAP SWD (J4)JLINK

## 

 BSP 

|       |   |                                  |
| --------- | --------  | -------------------------------------|
| UART      |       | USART1/2/3, UART4/5                  |
| GPIO      |       | PA0, PA1... PD15 ---> PIN: 0, 1...63 |
| I2C       |       | I2C                              |
| SPI       |       | SPI1/2                               |
| ADC       |       | ADC                                  |
| CAN       |       | CAN                                  |
| DAC       |       | DAC                                  |
| HWTIMER   |       | TIMER1/2/3/4/5/6/7/8/9               |
| WDT       |       | IWDG                                 |
| RTC       |       | LSE/LSI/HSE                | 

## 

RTCRTCLSILSEHSE

### IO

| IO |  |
| ---- | -------------- |
| PA9  | USART1_TX      |
| PA10 | USART1_RX      |

| PA2  | USART2_TX      |
| PA3  | USART2_RX      |

| PB10 | USART3_TX      |
| PB11 | USART3_RX      |

| PB0  | UART4_TX       |
| PB1  | UART4_RX       |

| PB8  | UART5_TX       |
| PB9  | UART5_RX       |

| PA4  | SPI1_NSS       |
| PA5  | SPI1_SCK       |
| PA6  | SPI1_MISO      |
| PA7  | SPI1_MOSI      |

| PB12 | SPI2_NSS       |
| PB13 | SPI2_SCK       |
| PB14 | SPI2_MISO      |
| PB15 | SPI2_MOSI      |

| PA1  | ADC_IN2        |
| PA2  | ADC_IN3        |

| PA4  | DAC_OUT        |

| PB8  | CAN_RX         |
| PB9  | CAN_TX         |

## 

 RT-Thread  RT-Thread 

### 

 BSP  MDK5IAR GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

#### 

 LED LED3 

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
