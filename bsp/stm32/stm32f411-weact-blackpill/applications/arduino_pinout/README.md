# STM32F411-weact-blackpill Arduino

## 1 RTduino - RT-ThreadArduino

STM32F411-weact-blackpill [RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

 [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

![pinout](images/weact-blackpill-f411-pinout.png)

| Arduino  | STM32 | 5V |   |
| ------------------- | --------- | ---- | ------------------------------------------------------------------------- |
| 0 (D0) | PC13 |  | LED |
| 1 (D1) | PC14 |  | I2C1-SDART-ThreadI2Ci2c1 |
| 2 (D2) | PC15 |  | I2C1-SCLRT-ThreadI2Ci2c1 |
| 3 (D3) | PA2 |  | Serial2-TXRT-ThreadUARTuart2 |
| 4 (D4) | PA3 |  | Serial2-RXRT-ThreadUARTuart2 |
| 5 (D5) | PB2 |  |  |
| 6 (D6) | PB10 |  |  |
| 7 (D7) | PB9 |  | PWM4-CH4RT-ThreadPWMpwm4 |
| 8 (D8) | PB8 |  | PWM4-CH3RT-ThreadPWMpwm4 |
| 9 (D9) | PB7 |  | PWM4-CH2RT-ThreadPWMpwm4 |
| 10 (D10) | PB6 |  | PWM4-CH1RT-ThreadPWMpwm4 |
| 11 (D11) | PB5 |  | SPI1-MOSIRT-ThreadSPIspi1 |
| 12 (D12) | PB4 |  | SPI1-MISORT-ThreadSPIspi1 |
| 13 (D13) | PB3 |  | SPI1-SCKRT-ThreadSPIspi1 |
| 14 (D14) | PA15 |  | SPI1-RT-ThreadSPIspi1 |
| 15 (D15) | PA12 |  | USB- [TinyUSB](https://github.com/RT-Thread-packages/tinyusb)  |
| 16 (D16) | PA11 |  | USB- [TinyUSB](https://github.com/RT-Thread-packages/tinyusb)  |
| 17 (D17) | PA10 |  | Serial-RXRT-ThreadUARTuart1 |
| 18 (D18) | PA9 |  | Serial-TXRT-ThreadUARTuart1 |
| 19 (D19) | PA8 |  |  |
| 20 (D20) | PB15 |  | PWM1-CH3RT-ThreadPWMpwm1 |
| 21 (D21) | PB14 |  | PWM1-CH2RT-ThreadPWMpwm1 |
| 22 (D22) | PB13 |  | PWM1-CH1RT-ThreadPWMpwm1 |
| 23 (D23) | PB12 |  |  |
| 24 (A0) | PA0 |  | ADC1-CH0RT-ThreadADCadc1 |
| 25 (A1) | PA1 |  | ADC1-CH1RT-ThreadADCadc1 |
| 26 (A2) | PA4 |  | ADC1-CH4RT-ThreadADCadc1 |
| 27 (A3) | PA5 |  | ADC1-CH5RT-ThreadADCadc1 |
| 28 (A4) | PA6 |  | ADC1-CH6RT-ThreadADCadc1 |
| 29 (A5) | PA7 |  | ADC1-CH7RT-ThreadADCadc1 |
| 30 (A6) | PB0 |  | ADC1-CH8RT-ThreadADCadc1 |
| 31 (A7) | PB1 |  | ADC1-CH9RT-ThreadADCadc1 |
| 32 (A8) | -- |  |  ADCRT-ThreadADCadc1 |
| 33 (A9) | -- |  |  ADCRT-ThreadADCadc1 |
