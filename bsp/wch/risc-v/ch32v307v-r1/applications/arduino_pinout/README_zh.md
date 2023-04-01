# CH32V307V-R1Arduino

[English](README.md) | ****

## 1 RTduino - RT-ThreadArduino

CH32V307V-R1  [RTduino](https://github.com/RTduino/RTduino) RT-Thread  Arduino Arduino  BSP Arduino RT-Thread [RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

BSPArduino UNO [pins_arduino.c](./pins_arduino.c)  [pins_arduino.h](./pins_arduino.h)

| Arduino | CH32 | 5V |                                      |
| ----------- | -------- | ---- | -------------------------------------- |
| 0 (D0)      | PA10     |     | Serial-RxRT-ThreadUARTuart1 |
| 1 (D1)      | PA9      |     | Serial-TxRT-ThreadUARTuart1 |
| 2 (D2)      | PA8      |     | PWM1-CH1RT-ThreadPWMpwm1    |
| 3 (D3)      | PA7      |     | PWM3-CH2RT-ThreadPWMpwm3    |
| 4 (D4)      | PA6      |     | PWM3-CH1RT-ThreadPWMpwm3    |
| 5 (D5)      | PB5      |     |                                        |
| 6 (D6)      | PB8      |     | PWM4-CH3RT-ThreadPWMpwm4    |
| 7 (D7)      | PB9      |     | PWM4-CH4RT-ThreadPWMpwm4    |
| 8 (D8)      | PB1      |     | PWM3-CH4RT-ThreadPWMpwm3    |
| 9 (D9)      | PB0      |     | PWM3-CH3RT-ThreadPWMpwm3    |
| 10 (D10)    | PB12     |     |                                        |
| 11 (D11)    | PB15     |     |                                        |
| 12 (D12)    | PB14     |     |                                        |
| 13 (D13)    | PB13     |     |                                        |
| 14 (D14)    | PB11     |     | I2C-SDART-ThreadI2Ci2c1   |
| 15 (D15)    | PB10     |     | I2C-SCLRT-ThreadI2Ci2c1   |
| A0          | PA0      |     | ADC1-CH0RT-ThreadADCadc1    |
| A1          | PA1      |     | ADC1-CH1RT-ThreadADCadc1    |
| A2          | PA2      |     | ADC1-CH2RT-ThreadADCadc1    |
| A3          | PA3      |     | ADC1-CH3RT-ThreadADCadc1    |
| A4          | PA4      |     | ADC1-CH4RT-ThreadADCadc1    |
| A5          | PA5      |     | ADC1-CH5RT-ThreadADCadc1    |

> 
> 
> 1. analogWritePWM4PWManalogWrite

## 3 

### 3.1 I2C

CH32V307-R1 I2C `SCL/D15`  `SDA/D14` RT-Thread I2C`#include <Wire.h>`ArduinoI2C

### 3.2 SPI

BSPArduinoSPI

### 3.3 

BSP `Serial.`  `uart1` [](https://github.com/RTduino/RTduino/blob/master/examples/Basic/helloworld.cpp)
