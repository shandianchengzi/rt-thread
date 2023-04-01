# STM32F407 Robomaster CArduino

## 1 RTduino - RT-ThreadArduino

STM32F407 Robomaster C[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

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
| 0 (D0) | PH11 |  | LED |
| 1 (D1) | PB7 |  | Serial-RXRT-ThreadUARTuart1 |
| 2 (D2) | PA9 |  | Serial-TXRT-ThreadUARTuart1 |
| 3 (D3) | PG9 |  | Serial-RXRT-ThreadUARTuart6 |
| 4 (D4) | PG14 |  | Serial-TXRT-ThreadUARTuart6 |
| 5 (D5) | PF1 |  | I2C1-SCLRT-ThreadI2Ci2c1 |
| 6 (D6) | PF0 |  | I2C1-SDART-ThreadI2Ci2c1 |
| 7 (D7) | PE9 |  | PWM1-CH1RT-ThreadPWMpwm1 |
| 8 (D8) | PE11 |  | PWM1-CH2RT-ThreadPWMpwm1 |
| 9 (D9) | PE13 |  | PWM1-CH3RT-ThreadPWMpwm1 |
| 10 (D10) | PE14 |  | PWM1-CH4RT-ThreadPWMpwm1 |
| 11 (D11) | PC6 |  | PWM8-CH1RT-ThreadPWMpwm8 |
| 12 (D12) | PI6 |  | PWM8-CH2RT-ThreadPWMpwm8 |
| 13 (D13) | PI7 |  | PWM8-CH3RT-ThreadPWMpwm8 |
| 14 (A0) | -- |  |  ADCRT-ThreadADCadc1 |
| 15 (A1) | -- |  |  ADCRT-ThreadADCadc1 |

