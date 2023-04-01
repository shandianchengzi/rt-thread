# LPC55s69-nxp-evkArduino

## 1 RTduino - RT-ThreadArduino

LPC55s69-nxp-evk[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

 [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

![LPC55s69-nxp-evk-pinout1](LPC55s69-nxp-evk-pinout1.png)

![LPC55s69-nxp-evk-pinout2](LPC55s69-nxp-evk-pinout2.png)

| Arduino  | LPC55 | 5V |   |
| ------------------- | --------- | ---- | ------------------------------------------------------------------------- |
| 0 (D0) | P(1,24) | / | Serial2-RXRT-ThreadUARTuart2 |
| 1 (D1) | P(0,27) | / | Serial2-TXRT-ThreadUARTuart2 |
| 2 (D2) | P(0,15) | / |  |
| 3 (D3) | P(1,6) | / |  |
| 4 (D4) | P(1,7) | / | PWM2-CH2RT-ThreadPWMpwm2 |
| 5 (D5) | P(1,4) | / | PWM2-CH1RT-ThreadPWMpwm2 |
| 6 (D6) | P(1,10) | / |  |
| 7 (D7) | P(1,9) | / | PWM1-CH0RT-ThreadPWMpwm1 |
| 8 (D8) | P(1,8) | / |  |
| 9 (D9) | P(1,5) | / |  |
| 10 (D10) | P(1,1) | / |  |
| 11 (D11) | P(0,26) | / |  |
| 12 (D12) | P(1,3) | / | PWM0-CH3RT-ThreadPWMpwm0 |
| 13 (D13) | P(1,2) | / |  |
| 14 (D14) | P(1,21) | / | I2C4-SDART-ThreadI2Ci2c4 |
| 15 (D15) | P(1,20) | / | I2C4-SCLRT-ThreadI2Ci2c4 |
| 16 (A0) | P(0,16) | / | ADC0-CH8RT-ThreadADCadc0 |
| 17 (A1) | P(0,23) | / | ADC0-CH0RT-ThreadADCadc0 |
| 18 (A2) | -- | / |  |
| 19 (A3) | P(1,31) | / |  |
| 20 (A4) | P(0,13) | / | I2C1-SDART-ThreadI2Ci2c1 |
| 21 (A5) | P(0,14) | / | I2C1-SCLRT-ThreadI2Ci2c1 |
| 22 (A6) | -- |  |  ADCRT-ThreadADCadc1 |
| 23 (A7) | -- |  |  ADCRT-ThreadADCadc1 |

> 
>
> 1. xxxxxxxxx
> 2. xxxxxxxxx
