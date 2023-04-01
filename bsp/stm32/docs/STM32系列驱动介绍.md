#  STM32

 RT-Thread   I/O  API API

![rt_device](figures/rt_device.png)

 I/O 

-  API 
- 
- 

## 1. 

 BSP  BSP 

- **** MCU  TF  LCD 
- **** MCU ADC 
- **** ESP8266 



![Peripheral](figures/Peripheral.png)

## 2. 

 RT-Thread  STM32  BSP

### 2.1 

|  |                                                          |                                              |
| ---- | ------------------------------------------------------------ | ------------------------------------------------ |
| 1    | [GPIO](https://www.rt-thread.org/document/site/programming-manual/device/pin/pin/) |  GPIO                                    |
| 2    | [UART](https://www.rt-thread.org/document/site/programming-manual/device/uart/uart/) |                                  |
| 3    | [soft I2C](https://www.rt-thread.org/document/site/programming-manual/device/i2c/i2c/) |  I2C                             |
| 4    | [SPI](https://www.rt-thread.org/document/site/programming-manual/device/spi/spi/) |  SPI                                 |
| 5    | [ADC](https://www.rt-thread.org/document/site/programming-manual/device/adc/adc/) |                                |
| 6    | SDIO                                                         |  SDIO                                |
| 7    | [TIMER](https://www.rt-thread.org/document/site/programming-manual/device/hwtimer/hwtimer/) |  |
| 8    | [PWM](https://www.rt-thread.org/document/site/programming-manual/device/pwm/pwm/) |  PWM                         |
| 9    | [RTC](https://www.rt-thread.org/document/site/programming-manual/device/rtc/rtc/) |                                    |
| 10   | [WDT](https://www.rt-thread.org/document/site/programming-manual/device/watchdog/watchdog/) |                                        |
| 11   | [QSPI](https://www.rt-thread.org/document/site/programming-manual/device/spi/spi/#qspi_1) |  SPI124                    |

### 2.2 

|  |     |                                     |
| ---- | ------- | --------------------------------------- |
| 1    | SD      |  SPI  SDIO  SD(TF)  |
| 2    | ETH PHY |                                   |
| 3    | USB PHY | USB                                     |
| 4    | LCD     |                                   |

### 2.3 

|  |      |                    |
| ---- | -------- | ---------------------- |
| 1    | ESP8266  |  WIFI        |
| 2    | ENC28J60 | SPI  |

### 2.4 

 RT-Thread  `examples\test`  RT-Thread  env  BSP  `examples\test`  BSP 