#  RA

 RT-Thread   I/O  API API

![image-20220308143402996](figures/rtdevice.png) 

 I/O 

-  API 
- 
- 

## 1. 

 BSP  BSP 

- ****(Onboard Peripheral Drivers) MCU  TF 
- ****(On-chip Peripheral Drivers) MCU ADC 
- ****(Board extended module Drivers) RW007 



![Peripheral](figures/Peripheral.png) 

## 2. 

 RT-Thread  RA  BSP

### 2.1 

|                                                          |                                              |
| ------------------------------------------------------------ | ------------------------------------------------ |
| [GPIO](https://www.rt-thread.org/document/site/programming-manual/device/pin/pin/) |  GPIO                                    |
| [UART](https://www.rt-thread.org/document/site/programming-manual/device/uart/uart/) |                                  |
| [I2C](https://www.rt-thread.org/document/site/programming-manual/device/i2c/i2c/) |  I2C                             |
| [SPI](https://www.rt-thread.org/document/site/programming-manual/device/spi/spi/) |  SPI                                 |
| [ADC](https://www.rt-thread.org/document/site/programming-manual/device/adc/adc/) |                                |
| SDIO                                                         |  SDIO                                |
| [TIMER](https://www.rt-thread.org/document/site/programming-manual/device/hwtimer/hwtimer/) |  |
| [PWM](https://www.rt-thread.org/document/site/programming-manual/device/pwm/pwm/) |  PWM                         |
| [RTC](https://www.rt-thread.org/document/site/programming-manual/device/rtc/rtc/) |                                    |
| [WDT](https://www.rt-thread.org/document/site/programming-manual/device/watchdog/watchdog/) |                                        |
| [QSPI](https://www.rt-thread.org/document/site/programming-manual/device/spi/spi/#qspi_1) |  SPI124                    |

### 2.2 

|     |                                     |
| ------- | --------------------------------------- |
| I2C     |  I2C                           |
| SDIO    |  SPI  SDIO  SD(TF)  |

### 2.3 

|      |                    |
| -------- | ---------------------- |
| [RW007](https://github.com/RT-Thread-packages/rw007) | SPI  WIFI         |
| [HS300x](https://github.com/Guozhanxin/hs300x) | I2C      |
| [ZMOD4410](https://github.com/ShermanShao/zmod4410) | I2C  |

### 2.4 

 RT-Thread  `examples\test`  RT-Thread  env  BSP  `examples\test`  BSP 