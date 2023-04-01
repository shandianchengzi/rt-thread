#  GD32 ARM

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



### 2.1 

|  |                                                          |                                              |
| ---- | ------------------------------------------------------------ | ------------------------------------------------ |
| 1    | [GPIO](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/pin/pin.md) |  GPIO                                    |
| 2    | [UART](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/uart/uart_v1/uart) |                                  |
| 3    | [soft I2C](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/i2c/i2c.md) |  I2C                             |
| 4    | [SPI](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/spi/spi) |  SPI                                 |
| 5    | [ADC](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/adc/adc.md) |                                |
| 6    | SDIO                                                         |  SDIO                                |
| 7    | [TIMER](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/hwtimer/hwtimer.md) |  |
| 8    | [PWM](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/pwm/pwm.md) |  PWM                         |
| 9    | [RTC](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/rtc/rtc.md) |                                    |
| 10   | [WDT](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/watchdog/watchdog.md) |                                        |
| 11   | [QSPI](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/spi/spi.md) |  SPI124                    |

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