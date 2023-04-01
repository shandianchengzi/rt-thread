# xxx Arduino

## 1 RTduino - RT-ThreadArduino

xxx [RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

 [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

![xxx-pinout](xxx-pinout.jpg)
| Arduino  | STM32 | 5V |   |
| ------------------- | --------- | ---- | ------------------------------------------------------------------------- |
| 0 (D0) | PA3 | / | Serial-RXRT-ThreadUARTuart2 |
| 1 (D1) | PA2 | / | Serial-TXRT-ThreadUARTuart2 |
| 2 (D2) | PA10 | / |  |
| 3 (D3) | PB3 | / | PWM2-CH2RT-ThreadPWMpwm2 |
| 4 (D4) | PB5 | / |  |
| 5 (D5) | PB4 | / | PWM3-CH1RT-ThreadPWMpwm3 |
| 6 (D6) | PB10 | / | PWM2-CH3RT-ThreadPWMpwm2 |
| 7 (D7) | PA8 | / |  |
| 8 (D8) | PA9 | / |  |
| 9 (D9) | PC7 | / | PWM3-CH0RT-ThreadPWMpwm3 |
| 10 (D10) | PB6 | / | PWM4-CH1RT-ThreadPWMpwm4 |
| 11 (D11) | PA7 | / | PWM17-CH1RT-ThreadPWMpwm17 |
| 12 (D12) | PA6 | / |  |
| 13 (D13) | PA5 | / |  |
| 14 (D14) | PB9 | / | I2C1-SDART-ThreadI2Ci2c1 |
| 15 (D15) | PB8 | / | I2C1-SCLRT-ThreadI2Ci2c1 |
| 16 (D16) | PA5 | / |  |
| 17 (A0) | PA0 | / | ADC1-CH5RT-ThreadADCadc1 |
| 18 (A1) | PA1 | / | ADC1-CH6RT-ThreadADCadc1 |
| 19 (A2) | PA4 | / | ADC1-CH9RT-ThreadADCadc1 |
| 20 (A3) | PB0 | / | ADC1-CH15RT-ThreadADCadc1 |
| 21 (A4) | PC1 | / | ADC1-CH2RT-ThreadADCadc1 |
| 22 (A5) | PC0 | / | ADC1-CH1RT-ThreadADCadc1 |
| 23 (A6) | -- |  |  ADCRT-ThreadADCadc1 |
| 24 (A7) | -- |  |  ADCRT-ThreadADCadc1 |

> 
>
> 1. xxxxxxxxx
> 2. xxxxxxxxx
