# N32G452XX MINI-SYSTEM BSP 

## 

N32G452 MINI-SYSTEM N32G452()MCU

|       |           |
| --------- | ------------- |
|   | N32G452RCL7  |
| CPU       | ARM Cortex M4 |
|       | 144M          |
| SRAM  | 80K144K |
| FLASH | 256K         |

## 

N32G452 MINI-SYSTEM MDK5GCC

| IDE/ |                    |
| ---------- | ---------------------------- |
| MDK5       | MDK533                       |
| GCC        | GCC 6.2.1 20161205 (release) |

## 

- MCUN32G452RCL7 144MHz256KB FLASH 80KB144KB RAM
- J8
- JLINK NS-LINK SWD 

## 

 BSP 

|       |  |                        |
| --------- | -------- | :------------------------: |
| UART      | ()     | USART1/2/3                 |
| GPIO      | ()     | PA0...PF7                  |
| ADC       | ()     | ADC1/2                     |
| PWM       | ()     | TMR1/2                     |
| HWTIMER   | ()     | TMR6/7                     |

### IO

| IO |  |
| ---- | -------------- |
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
| PC0  | ADC1/2_IN10    |
| PC1  | ADC1/2_IN11    |
| PC2  | ADC1/2_IN12    |
| PC3  | ADC1/2_IN13    |

## 

     RT-Thread  RT-Thread  

### 

 BSP  MDK5 GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

#### 

 LED LED1 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Aug 19 2021
 2006 - 2021 Copyright by rt-thread team
msh />
```

## 

1.  J-LINK J-Flash`Options->Project settings->production->Start application`N32G43xFAE

## 

:

- [LinYuanbo](https://github.com/Lim-LinYuanbo)
- [breo.com](https://github.com/breo-shenzhen)
