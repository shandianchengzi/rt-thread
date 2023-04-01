# STM32F072 NucleoArduino

[English](README.md) | ****

## 1 RTduino - RT-ThreadArduino

STM32F072 Nucleo[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

![nucleo-f072-pinout](nucleo-f072-pinout.png)

BSPArduino UNO [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

| Arduino           | STM32 | 5V |                                             |
| --------------------- | --------- | ---- | --------------------------------------------- |
| 0 (D0)                | PA3       |     | Serial-RxRT-ThreadUARTuart2        |
| 1 (D1)                | PA2       |     | Serial-TxRT-ThreadUARTuart2        |
| 2 (D2)                | PA10      |     |                                               |
| 3 (D3)                | PB3       |     | PWM2-CH2RT-ThreadPWMpwm2           |
| 4 (D4)                | PB5       |     |                                               |
| 5 (D5)                | PB4       |     | PWM3-CH1RT-ThreadPWMpwm3           |
| 6 (D6)                | PB10      |     | PWM2-CH3RT-ThreadPWMpwm2           |
| 7 (D7)                | PA8       |     |                                               |
| 8 (D8)                | PA9       |     |                                               |
| 9 (D9)                | PC7       |     | PWM3-CH2RT-ThreadPWMpwm3           |
| 10 (D10)              | PB6       |     | PWM16-CHN1RT-ThreadPWMpwm16        |
| 11 (D11)              | PA7       |     | PWM17-CH1RT-ThreadPWMpwm17         |
| 12 (D12)              | PA6       |     |                                               |
| 13 (D13, LED_BUILTIN) | PA5       |     | LED                                       |
| 14 (D14)              | PB9       |     | I2C-SDART-ThreadI2Ci2c1            |
| 15 (D15)              | PB8       |     | I2C-SCLRT-ThreadI2Ci2c1            |
| 16 (D16)              | PC13      |     |                                     |
| A0                    | PA0       |     | ADC1-CH0RT-ThreadADCadc1           |
| A1                    | PA1       |     | ADC1-CH1RT-ThreadADCadc1           |
| A2                    | PA4       |     | ADC1-CH4RT-ThreadADCadc1           |
| A3                    | PB0       |     | ADC1-CH8RT-ThreadADCadc1           |
| A4                    | PC1       |     | ADC1-CH11RT-ThreadADCadc1          |
| A5                    | PC0       |     | ADC1-CH10RT-ThreadADCadc1          |
| A6                    | --        |      |  ADC1-CH17RT-ThreadADCadc1 |
| A7                    | --        |      |  ADC1-CH16RT-ThreadADCadc1   |

> 
> 
> 1. analogWritePWMSTM324PWManalogWrite
> 2. USART2NucleoArduinoD0D1IOD0D1STM32 USART2SB62SB63
> 3. NucleoArduinoAVDDAREFVDDSB57
> 4. D10PWM()****CHx-20%CHxN-80%

> 
> 
> 1. [STM32 Nucleo-64](https://www.st.com/resource/en/user_manual/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf)

## 3 

### 3.1 I2C

STM32F072 NucleoI2C `SCL/D15`  `SDA/D14` RT-Thread I2C`#include <Wire.h>`ArduinoI2C

### 3.2 SPI

BSPArduinoSPI

### 3.3 

BSP `Serial.`  `uart2` [](https://github.com/RTduino/RTduino/blob/master/examples/Basic/helloworld.cpp)
