# STM32L475Arduino

## 1 RTduino - RT-ThreadArduino

STM32L475[RTduino](https://github.com/RTduino/RTduino)RT-ThreadArduinoArduinoBSPArduinoRT-Thread[RTduino](https://github.com/RTduino/RTduino)

### 1.1 BSPArduino

Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

## 2 Arduino

BSPArduino UNO `pins_arduino.c`

### 2.1 Arduino

 [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

| Arduino           | STM32 | 5V    |                                            |
| --------------------- | --------- | ------- | -------------------------------------------- |
| 0 (D0)                | PA10      |        | Serial-RxRT-ThreadUARTuart1         |
| 1 (D1)                | PA9       |        | Serial-TxRT-ThreadUARTuart1         |
| 2 (D2)                | PB9       |        | IO                                         |
| 3 (D3)                | PD15      |        | PWM4-CH4RT-ThreadPWMpwm4          |
| 4 (D4)                | PA8       |        | IO                                         |
| 5 (D5)                | PD14      |        | IO                                         |
| 6 (D6)                | PB11      |        | PWM2-CH4RT-ThreadPWMpwm2          |
| 7 (D7)                | PB14      |        | IO                                         |
| 8 (D8)                | PB12      |        | IO                                         |
| 9 (D9)                | PD12      |        | PWM4-CH1RT-ThreadPWMpwm4          |
| 10 (D10)              | PB10      |        | PWM2-CH3RT-ThreadPWMpwm2          |
| 11 (D11)              | PB8       |        | PWM4-CH3RT-ThreadPWMpwm4          |
| 12 (D12)              | PB15      |        | IO                                         |
| 13 (D13)              | PB13      |        | IO                                         |
| 14 (D14)              | PA1       |        | -A                                       |
| 15 (D15)              | PA0       |        | -B                                       |
| 16 (D16)              | PB2       |        |                                           |
| 17 (D17)              | PD10      |        | KEY0                                         |
| 18 (D18)              | PD9       |        | KEY1                                         |
| 19 (D19)              | PD8       |        | KEY2                                         |
| 20 (D20)              | PC13      |        | KEY-WKUP                                     |
| 21 (D21)              | PE7       |        | LED                                      |
| 22 (D22, LED_BUILTIN) | PE8       |        | LED                                      |
| 23 (D23)              | PE9       |        | LEDPWM1-CH1RT-ThreadPWMpwm1  |
| 24 (D24)              | PB0       | 3.6V  |                                          |
| 25 (D25)              | PB1       |        |                                          |
| 26 (D26)              | PD4       |        |  CE                                      |
| 27 (D27)              | PD3       |        |                                        |
| 28 (D28, SS)          | PD5       |        |   CS                                   |
| 29 (D29)              | PB13      |         | SPI2-SCKRT-ThreadSPIspi2        |
| 30 (D30)              | PB14      |         | SPI2-MISORT-ThreadSPIspi2       |
| 31 (D31)              | PB15      |         | SPI2-MOSIRT-ThreadSPIspi2       |
| 32 (D32)              | PC7       |        | I2C1-SDART-ThreadI2Ci2c1        |
| 33 (D33)              | PC6       |        | I2C1-SCLRT-ThreadI2Ci2c1        |
| 34 (D34)              | PA2       |         | Serial2-TxRT-ThreadUARTuart2      |
| 35 (D35)              | PA3       |         | Serial2-RxRT-ThreadUARTuart2      |
| A0                    | PC2       |  | ADC1-CH3RT-ThreadADCadc1          |
| A1                    | PC4       |  | ADC1-CH13RT-ThreadADCadc1         |
| A2                    | --        |         |  ADC1-CH0RT-ThreadADCadc1 |
| A3                    | --        |         |  ADC1-CH17RT-ThreadADCadc1  |
| DAC0                  | PA4       | 3.6V  |  DAC1-CH1RT-ThreadDACdac1    |

> 
> 
> 1. analogWritePWMSTM324PWManalogWrite

### 2.2 Arduino

| STM32 | Arduino |        | STM32 | Arduino |        |
| --------- | ----------- | -------- | --------- | ----------- | -------- |
| PB8       | 11 (D11)    | PWM      | PB9       | 2 (D2)      | IO     |
| PC7       | A4          | I2C1-SDA | PA8       | 4 (D4)      | IO     |
| PD15      | 3 (D3)      | PWM      | PC6       | A5          | I2C1-SCL |
| PD13      | --          | --       | PD14      | 5 (D5)      | IO     |
| PC2       | A0          | ADC      | PD12      | 9 (D9)      | PWM      |
| PB14      | 7 (D7)      | IO     | PB15      | 12 (D12)    | IO     |
| PB12      | 8 (D8)      | IO     | PB13      | 13 (D13)    | IO     |
| PB10      | 10 (D10)    | PWM      | PB11      | 6 (D6)      | PWM      |
| PC4       | A1          | ADC      | PA4       | DAC0        | DAC      |

### 2.3 Arduino

|               | Arduino           | STM32 |
| ----------------- | --------------------- | --------- |
| -A            | 14 (D14)              | PA1       |
| -B            | 15 (D15)              | PA0       |
|                | 16 (D16)              | PB2       |
| KEY0              | 17 (D17)              | PD10      |
| KEY1              | 18 (D18)              | PD9       |
| KEY2              | 19 (D19)              | PD8       |
| KEY-WKUP          | 20 (D20)              | PC13      |
| LED              | 21 (D21)              | PE7       |
| LEDArduinoLED | 22 (D22, LED_BUILTIN) | PE8       |
| LEDPWM      | 23 (D23)              | PE9       |
|               | 24 (D24)              | PB0       |
|               | 25 (D25)              | PB1       |

## 3 

### 3.1 I2C

ArduinoI2Ci2c1i2c3  i2c4`pins_arduino.h` `RTDUINO_DEFAULT_IIC_BUS_NAME` ArduinoI2C** i2c4 **

- i2c1 PC7  SDAPC6  SCL I2C /
- i2c3  I2C  ICM20608  AP3216C 
- i2c4  I2C  AHT10 

I2CRT-Thread I2C`#include <Wire.h>`ArduinoI2C

### 3.2 SPI

Arduino SPIspi2`WIRELESS` `SCK``MISO``MOSI`RT-Thread SPI3`#include <SPI.h>`ArduinoSPIArduino `SS`,  `D28`

### 3.3 

 `Serial.`  `uart1`  `Serial2.`  `uart2` [](https://github.com/RTduino/RTduino/blob/master/examples/Basic/helloworld.cpp)

### 3.4 USB

USB[](https://github.com/RTduino/RTduino/tree/master/examples/USBSerial)

```Kconfig
RT-Thread online packages --->
    Arduino libraries --->
        [*] RTduino: Arduino Ecological Compatibility Layer
            [*] Enable USB Serial
```

## 4 

### 4.1 ADC

BSPSTM32ADC analogRead 

|          | Arduino | STM32 |
| ------------ | ----------- | --------- |
|  ADC | A2          | --        |
|  ADC   | A3          | --        |

### 4.2  (True Analog Output)

Arduino analogWrite PWMArduinoAVRDACArduinoDACArduinoMKRZeroArduino analogWrite 

|                        | Arduino | STM32 |
| -------------------------- | ----------- | --------- |
|  (True Analog Output) | DAC0        | PA4       |

PA4

```c
analogWrite(DAC0, 128);
```
