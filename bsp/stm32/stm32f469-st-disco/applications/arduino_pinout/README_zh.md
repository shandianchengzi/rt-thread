# STM32F469 DiscoveryArduino

[English](README.md) | ****

## 1 RTduino - RT-ThreadArduino

STM32F469 Discovery[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

![disco-f469-pinout](disco-f469-pinout.png)

BSPArduino UNO [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

| Arduino           | STM32 | 5V |                                             |
| --------------------- | --------- | ---- | --------------------------------------------- |
| 0 (D0)                | PG9       |     | Serial-RxRT-ThreadUARTuart3        |
| 1 (D1)                | PG14      |     | Serial-TxRT-ThreadUARTuart3        |
| 2 (D2)                | PG13      |     |                                               |
| 3 (D3)                | PA1       |     | PWM2-CH2RT-ThreadPWMpwm2           |
| 4 (D4)                | PG12      |     |                                               |
| 5 (D5)                | PA2       |     | PWM2-CH3RT-ThreadPWMpwm2           |
| 6 (D6)                | PA6       |     | PWM3-CH1RT-ThreadPWMpwm3           |
| 7 (D7)                | PG11      |     |                                               |
| 8 (D8)                | PG10      |     |                                               |
| 9 (D9)                | PA7       |     | PWM3-CH2RT-ThreadPWMpwm3           |
| 10 (D10)              | PH6       |     | PWM12-CH1RT-ThreadPWMpwm12         |
| 11 (D11)              | PB15      |     | PWM12-CH2RT-ThreadPWMpwm12         |
| 12 (D12)              | PB14      |     |                                               |
| 13 (D13, LED_BUILTIN) | PD3       |     | LED1                                      |
| 14 (D14)              | PB9       |     | I2C-SDART-ThreadI2Ci2c1            |
| 15 (D15)              | PB8       |     | I2C-SCLRT-ThreadI2Ci2c1            |
| 16 (D16)              | PA0       |     |                                         |
| 17D17               | PG6       |     | LED2                                      |
| 18D18               | PD4       |     | LED3                                      |
| 19D19               | PD5       |     | LED4                                      |
| 20D20               | PK3       |     | LED5                                      |
| A0                    | PB1       |     | ADC1-CH9RT-ThreadADCadc1           |
| A1                    | PC2       |     | ADC1-CH12RT-ThreadADCadc1          |
| A2                    | PC3       |     | ADC1-CH13RT-ThreadADCadc1          |
| A3                    | PC4       |     | ADC1-CH14RT-ThreadADCadc1          |
| A4                    | PC5       |     | ADC1-CH15RT-ThreadADCadc1          |
| A5                    | PA4       |     | ADC1-CH4RT-ThreadADCadc1           |
| A6                    | --        |      |  ADC1-CH17RT-ThreadADCadc1 |
| A7                    | --        |      |  ADC1-CH16RT-ThreadADCadc1   |

> 
> 
> 1. analogWritePWMSTM324PWManalogWrite

> 
> 
> 1. [STM32F469 Discovery](https://www.st.com/zh/evaluation-tools/32f469idiscovery.html#documentation)

## 3 

### 3.1 I2C

BSPI2C `SCL/D15`  `SDA/D14` RT-Thread I2C`#include <Wire.h>`ArduinoI2C

### 3.2 SPI

BSPArduinoSPI

### 3.3 

BSP `Serial.`  `uart3` [](https://github.com/RTduino/RTduino/blob/master/examples/Basic/helloworld.cpp)

### 3.4 USB

BSPUSB[](https://github.com/RTduino/RTduino/tree/master/examples/USBSerial)

```Kconfig
RT-Thread online packages --->
    Arduino libraries --->
        [*] RTduino: Arduino Ecological Compatibility Layer
            [*] Enable USB Serial
```
