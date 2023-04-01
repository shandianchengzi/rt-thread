# STM32L431-BearPiArduino

## 1 RTduino - RT-ThreadArduino

STM32L431-BearPi[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

![bearpi-l431-pinout](bearpi-l431-pinout.png)

BSPE53 [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

| Arduino           | STM32 | 5V |                                             |
| --------------------- | --------- | ---- | --------------------------------------------- |
| 0 (D0)                | PA1       |     | SPI-SCK,RT-ThreadSPIspi1            |
| 1 (D1)                | PA4       |     | SPI-SS,RT-ThreadSPIspi1             |
| 2 (D2)                | PA0       |     |                                                      |
| 3 (D3)                | PB9       |     |                                                      |
| 4 (D4)                | PB8       |     | PWM16-CH1RT-ThreadPWMpwm16         |
| 5 (D5)                | PB6       |     | I2C-SCLRT-ThreadI2Ci2c1            |
| 6 (D6)                | PB7       |     | I2C-SDART-ThreadI2Ci2c1            |
| 7 (D7)                | PA6       |     | SPI-MISORT-ThreadSPIspi1           |
| 8 (D8)                | PA12      |     | SPI-MOSIRT-ThreadSPIspi1           |
| 9 (D9)                | PC9       |     |                                                      |
| 10 (D10)              | PC4       |     | Serial3-TxRT-ThreadUARTuart3       |
| 11 (D11)              | PC5       |     | Serial3-RxRT-ThreadUARTuart3       |
| 12 (D12)              | PA8       |     | PWM1-CH1RT-ThreadPWMpwm1           |
| A0                    | PC2       |     | ADC1-CH3RT-ThreadADCadc1           |
| DAC0                  | PA5       |     | DAC1-CH2RT-ThreadDACdac1           |

> 
> 
> 1. E5317(RTduino9D9)PWMPC9PWMGPIO
