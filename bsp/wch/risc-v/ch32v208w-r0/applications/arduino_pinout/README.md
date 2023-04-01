# CH32V208W-R0 Arduino

## 1 RTduino - RT-ThreadArduino

CH32V208W-R0[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

 [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

![ch32v208w-pinout](ch32v208w-pinout.png)
| Arduino  | STM32 | 5V |   |
| ------------------- | --------- | ---- | ------------------------------------------------------------------------- |
| 0 (D0) | PA9 |  | Serial2-TXRT-ThreadUARTuart1 |
| 1 (D1) | PB0 |  | Serial2-RXRT-ThreadUARTuart1 |
| 2 (D2) | PB4 |  |  |
| 3 (D3) | PB6 |  | PWM4-CH1RT-ThreadPWMpwm4 |
| 4 (D4) | PB7 |  | PWM4-CH2RT-ThreadPWMpwm4 |
| 5 (D5) | PB8 |  | PWM4-CH3RT-ThreadPWMpwm4 |
| 6 (D6) | PB9 |  | PWM4-CH4RT-ThreadPWMpwm4 |
| 7 (D7) | PA8 |  | PWM1-CH1RT-ThreadPWMpwm1 |
| 8 (D8) | PB1 |  | PWM3-CH4RT-ThreadPWMpwm3 |
| 9 (D9) | PB0 |  | PWM3-CH3RT-ThreadPWMpwm3 |
| 10 (D10) | PB12 |  |  |
| 11 (D11) | PB15 |  |  |
| 12 (D12) | PB14 |  |  |
| 13 (D13) | PB13 |  |  |
| 14 (D14) | PB11 |  | I2C1-SDART-ThreadI2Ci2c1 |
| 15 (D15) | PB10 |  | I2C1-SCLRT-ThreadI2Ci2c1 |
| 16 (A0) | PA0 |  | ADC1-CH0RT-ThreadADCadc1 |
| 17 (A1) | PA1 |  | ADC1-CH1RT-ThreadADCadc1 |
| 18 (A2) | PA2 |  | ADC1-CH2RT-ThreadADCadc1 |
| 19 (A3) | PA3 |  | ADC1-CH3RT-ThreadADCadc1 |
| 20 (A4) | PA4 |  | ADC1-CH4RT-ThreadADCadc1 |
| 21 (A5) | PA5 |  | ADC1-CH5RT-ThreadADCadc1 |

> 
>
> 1. analogWritePWM4PWManalogWrite

## 3 

### 3.1 I2C

CH32V208W-R0  I2C `SCL/D15`  `SDA/D14` RT-Thread I2C`#include <Wire.h>`ArduinoI2C

### 3.2 SPI

BSPArduinoSPI

### 3.3 

BSP `Serial.`  `uart1` [](https://github.com/RTduino/RTduino/blob/master/examples/Basic/helloworld.cpp)