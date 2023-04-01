# STM32F427 Robomaster AArduino

## 1 RTduino - RT-ThreadArduino

STM32F427 Robomaster A[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

 [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

| Arduino  | STM32 | 5V |   |
| ------------------- | --------- | ---- | ------------------------------------------------------------------------- |
| 0 (D0) | PF14 |  | LED |
| 1 (D1) | PD9 |  | Serial-RXRT-ThreadUARTuart3 |
| 2 (D2) | PD8 |  | Serial-TXRT-ThreadUARTuart3 |
| 3 (D3) | PG9 |  | Serial-RXRT-ThreadUARTuart6 |
| 4 (D4) | PG14 |  | Serial-TXRT-ThreadUARTuart6 |
| 5 (D5) | PE0 |  | Serial-RXRT-ThreadUARTuart8 |
| 6 (D6) | PE1 |  | Serial-TXRT-ThreadUARTuart8 |
| 7 (D7) | PE7 |  | Serial-RXRT-ThreadUARTuart7 |
| 8 (D8) | PE8 |  | Serial-TXRT-ThreadUARTuart7 |
| 9 (D9) | PH6 |  | PWM12-CH1RT-ThreadPWMpwm12 |
| 10 (D10) | PD12 |  | PWM4-CH1RT-ThreadPWMpwm4 |
| 11 (D11) | PD13 |  | PWM4-CH2RT-ThreadPWMpwm4 |
| 12 (D12) | PD14 |  | PWM4-CH3RT-ThreadPWMpwm4 |
| 13 (D13) | PD15 |  | PWM4-CH4RT-ThreadPWMpwm4 |
| 14 (D14) | PH10 |  | PWM5-CH1RT-ThreadPWMpwm5 |
| 15 (D15) | PH11 |  | PWM5-CH2RT-ThreadPWMpwm5 |
| 16 (D16) | PH12 |  | PWM5-CH3RT-ThreadPWMpwm5 |
| 17 (D17) | PI0 |  | PWM5-CH4RT-ThreadPWMpwm5 |
| 18 (D18) | PA0 |  | PWM2-CH1RT-ThreadPWMpwm2 |
| 19 (D19) | PA1 |  | PWM2-CH2RT-ThreadPWMpwm2 |
| 20 (D20) | PA2 |  | PWM2-CH3RT-ThreadPWMpwm2 |
| 21 (D21) | PA3 |  | PWM2-CH4RT-ThreadPWMpwm2 |
| 22 (D22) | PI5 |  | PWM8-CH1RT-ThreadPWMpwm8 |
| 23 (D23) | PI6 |  | PWM8-CH2RT-ThreadPWMpwm8 |
| 24 (D24) | PI7 |  | PWM8-CH3RT-ThreadPWMpwm8 |
| 25 (D25) | PI2 |  | PWM8-CH4RT-ThreadPWMpwm8 |
| 26 (D26) | PF1 |  |  |
| 27 (D27) | PF0 |  |  |
| 28 (D28) | PE4 |  | I2C1-SCLRT-ThreadI2Ci2c1 |
| 29 (D29) | PE5 |  | I2C1-SDART-ThreadI2Ci2c1 |
| 30 (D30) | PE6 |  |  |
| 31 (D31) | PE12 |  |  |
| 32 (D32) | PC2 |  |  |
| 33 (D33) | PB0 |  |  |
| 34 (D34) | PC3 |  |  |
| 35 (D35) | PB1 |  |  |
| 36 (D36) | PC4 |  |  |
| 37 (D37) | PC0 |  |  |
| 38 (D38) | PC5 |  |  |
| 39 (D39) | PC1 |  |  |
| 40 (D40) | PA5 |  |  |
| 41 (D41) | PA4 |  |  |
| 42 (D42) | PF10 |  |  |
| 43 (D43) | PI9 |  |  |
| 44 (A0) | -- |  |  ADCRT-ThreadADCadc1 |
| 45 (A1) | -- |  |  ADCRT-ThreadADCadc1 |
