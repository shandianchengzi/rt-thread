# STM32F103 Blue-PillArduino

[English](README.md) | ****

## 1 RTduino - RT-ThreadArduino

STM32F103 Blue-Pill[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

 [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

![blue-pill-f103-pinout](blue-pill-f103-pinout.jpg)

| Arduino         | STM32 | 5V |                                                                         |
| ------------------- | --------- | ---- | ------------------------------------------------------------------------- |
| 0 (D0)              | PB7       |     |                                                                           |
| 1 (D1)              | PB6       |     |                                                                           |
| 2 (D2)              | PB5       |     | PWM3-CH2RT-ThreadPWMpwm3                                       |
| 3 (D3)              | PB4       |     | PWM3-CH1RT-ThreadPWMpwm3                                       |
| 4 (D4)              | PB3       |     | PWM2-CH2RT-ThreadPWMpwm2                                       |
| 5 (D5)              | PA15      |     | PWM2-CH1RT-ThreadPWMpwm2                                       |
| 6 (D6)              | PA8       |     |                                                                           |
| 7 (D7, SS)          | PB12      |     | SPI                                                                 |
| 8 (D8, LED_BUILTIN) | PC13      |     | LED                                                                   |
| 9 (D9)              | PC14      |     |                                                                           |
| 10 (D10)            | PC15      |     |                                                                           |
| 11 (D11)            | PA0       |     |                                                                           |
| 12 (D12)            | PB0       |     | PWM3-CH3RT-ThreadPWMpwm3                                       |
| 13 (D13)            | PB1       |     | PWM3-CH4RT-ThreadPWMpwm3                                       |
| 14 (D14)            | PB9       |     | I2C-SDART-ThreadI2Ci2c1                                      |
| 15 (D15)            | PB8       |     | I2C-SCLRT-ThreadI2Ci2c1                                      |
| 16 (D16)            | PA12      |     | USB-DP [TinyUSB](https://github.com/RT-Thread-packages/tinyusb)  |
| 17 (D17)            | PA11      |     | USB-DM [TinyUSB](https://github.com/RT-Thread-packages/tinyusb)  |
| 18 (D18)            | PA10      |     | Serial-RxRT-ThreadUARTuart1                                    |
| 19 (D19)            | PA9       |     | Serial-TxRT-ThreadUARTuart1                                    |
| 20 (D20)            | PA2       |     | Serial2-TxRT-ThreadUARTuart2                                   |
| 21 (D21)            | PA3       |     | Serial2-RxRT-ThreadUARTuart2                                   |
| 22 (D22)            | PB10      |     | Serial3-TxRT-ThreadUARTuart3                                   |
| 23 (D23)            | PB11      |     | Serial3-RxRT-ThreadUARTuart3                                   |
| 24 (D24)            | PB15      |     | SPI-MOSIRT-ThreadSPIspi2                                       |
| 25 (D25)            | PB14      |     | SPI-MISORT-ThreadSPIspi2                                       |
| 26 (D26)            | PB13      |     | SPI-SCK RT-ThreadSPIspi2                                       |
| 27 (A0)             | PA1       |     | ADC1-CH1RT-ThreadADCadc1                                       |
| 28 (A1)             | PA4       |     | ADC1-CH4RT-ThreadADCadc1                                       |
| 29 (A2)             | PA5       |     | ADC1-CH5RT-ThreadADCadc1                                       |
| 30 (A3)             | PA6       |     | ADC1-CH6RT-ThreadADCadc1                                       |
| 31 (A4)             | PA7       |     | ADC1-CH7RT-ThreadADCadc1                                       |
| 32 (A5)             | --        |      |  ADCRT-ThreadADCadc1                                   |
| 33 (A6)             | --        |      |  ADCRT-ThreadADCadc1                                     |

> 
> 
> 1. analogWritePWMSTM324PWManalogWrite

## 3 

### 3.1 I2C (Wire.h)

I2C `D14`  `D15` RT-Thread I2C`#include <Wire.h>`ArduinoI2C

### 3.2 SPI

SPI `D24` `D25`  `D26` RT-Thread SPI`#include <SPI.h>`ArduinoSPI(SS) `D7`

### 3.3 

 `Serial.`  `uart1`  `Serial2.`  `uart2`  `Serial3.`  `uart3` [](https://github.com/RTduino/RTduino/blob/master/examples/Basic/helloworld.cpp)

### 3.4 USB

BSPUSB[](https://github.com/RTduino/RTduino/tree/master/examples/USBSerial)

```Kconfig
RT-Thread online packages --->
    Arduino libraries --->
        [*] RTduino: Arduino Ecological Compatibility Layer
            [*] Enable USB Serial
```
