# STM32F412 NucleoArduino

## 1 RTduino - RT-ThreadArduino

STM32F412 Nucleo[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

![nucleo-f412-pinout](nucleo-f412-pinout.png)

BSPArduino UNO [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

| Arduino           | STM32 | 5V |                                             |
| --------------------- | --------- | ---- | --------------------------------------------- |
| 0 (D0)                | PG9       |     | Serial-RxRT-ThreadUARTuart3        |
| 1 (D1)                | PG14      |     | Serial-TxRT-ThreadUARTuart3        |
| 2 (D2)                | PF15      |     |                                               |
| 3 (D3)                | PE13      |     | PWM1-CH3RT-ThreadPWMpwm1           |
| 4 (D4)                | PF14      |     |                                               |
| 5 (D5)                | PE11      |     | PWM1-CH2RT-ThreadPWMpwm1           |
| 6 (D6)                | PE9       |     | PWM1-CH1RT-ThreadPWMpwm1           |
| 7 (D7)                | PF13      |     |                                               |
| 8 (D8)                | PF12      |     |                                               |
| 9 (D9)                | PD15      |     | PWM4-CH4RT-ThreadPWMpwm4           |
| 10 (D10)              | PD14      |     | PWM4-CH3RT-ThreadPWMpwm4           |
| 11 (D11)              | PA7       |     | PWM14-CH1RT-ThreadPWMpwm14         |
| 12 (D12)              | PA6       |     |                                               |
| 13 (D13)              | PA5       |     |                                               |
| 14 (D14)              | PB9       |     | I2C-SDART-ThreadI2Ci2c1          |
| 15 (D15)              | PB8       |     | I2C-SCLRT-ThreadI2Ci2c1          |
| 16 (D16)              | PC13      |     |                                   |
| 17 (D17, LED_BUILTIN) | PB0       |     | LED1                                      |
| 18 (D18)              | PB7       |     | LED2                                      |
| 19 (D19)              | PB14      |     | LED3                                      |
| A0                    | PA3       |     | ADC1-CH3RT-ThreadADCadc1           |
| A1                    | PC0       |     | ADC1-CH10RT-ThreadADCadc1          |
| A2                    | PC3       |     | ADC1-CH13RT-ThreadADCadc1          |
| A3                    | PC1       |     | ADC1-CH11RT-ThreadADCadc1          |
| A4                    | PC4       |     | ADC1-CH14RT-ThreadADCadc1          |
| A5                    | PC5       |     | ADC1-CH15RT-ThreadADCadc1          |
| A6                    | --        |      |  ADC1-CH17RT-ThreadADCadc1 |
| A7                    | --        |      |  ADC1-CH16RT-ThreadADCadc1   |

> 
> 
> 1. analogWritePWMSTM324PWManalogWrite
> 2. NucleoArduinoAVDDAREFVDDSB57

> 
> 
> 1. [STM32 Nucleo-144](https://www.st.com/resource/en/user_manual/um1974-stm32-nucleo144-boards-mb1137-stmicroelectronics.pdf)

## 3 

### 3.1 I2C

I2C `SCL/D15`  `SDA/D14` RT-Thread I2C`#include <Wire.h>`ArduinoI2C

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
