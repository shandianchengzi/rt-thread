#  

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

 RT-Thread  LPC  BSP

### 2.1 

|  |                                                          |                                              |
| ---- | ------------------------------------------------------------ | ------------------------------------------------ |
| 1    | [GPIO](https://www.rt-thread.org/document/site/programming-manual/device/pin/pin/) |  GPIO                                    |
| 2    | [UART](https://www.rt-thread.org/document/site/programming-manual/device/uart/uart/) |                                  |
| 3    | [soft I2C](https://www.rt-thread.org/document/site/programming-manual/device/i2c/i2c/) |  I2C  I2C                             |
| 4    | [SPI](https://www.rt-thread.org/document/site/programming-manual/device/spi/spi/) |  SPI                                 |
| 5    | [ADC](https://www.rt-thread.org/document/site/programming-manual/device/adc/adc/) |                                |
| 6    | [HWTIMER](https://www.rt-thread.org/document/site/programming-manual/device/hwtimer/hwtimer/) |  |
| 7    | [PWM](https://www.rt-thread.org/document/site/programming-manual/device/pwm/pwm/) |  PWM                         |
| 8    | [RTC](https://www.rt-thread.org/document/site/programming-manual/device/rtc/rtc/) |                                    |
| 9   | [WATCHDOG](https://www.rt-thread.org/document/site/programming-manual/device/watchdog/watchdog/) |                                        |

### 2.2 

|  |  |                          |
| ---- | ---- | ---------------------------- |
| 1    | SD   |  SDIO  SD(TF)  |

### 2.3 

|  |     |               |
| ---- | ------- | ----------------- |
| 1    | ESP8266 |  WIFI   |
| 2    | RW-007  | SPIWIFI |

### 2.4 

 RT-Thread  `examples\test`  RT-Thread  env  BSP  `examples\test`  BSP 