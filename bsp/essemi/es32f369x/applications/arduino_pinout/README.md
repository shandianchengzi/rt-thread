# ES32F3696Arduino

## 1 RTduino - RT-ThreadArduino

ES32F3696[RTduino](https://github.com/RTduino/RTduino)GPIO/PWMI2C/SPIarduino uno4ledGPIO[RTduino](https://github.com/RTduino/RTduino)

### 1.1 Keil+Env

1. Env  menuconfig  RT-Thread Studio IDE  RT-Thread Settings

```Kconfig
Hardware Drivers Config --->
    Onboard Peripheral Drivers --->
        [*] Compatible with Arduino Ecosystem (RTduino)
```

2. RTduino (SPI,I2C,Adafrui)

```Kconfig
RT-Thread online packages --->
    system packages --->
        RTduino: Arduino Ecological Compatibility Layer
```

3.  pkgs --updateRTduino
4. scons --target=mdk5

### 1.2 RT-Thread Studio

1.   ->  -> BSP

   ![image-20220630160208893](picture/image-20220630160208893.png)

2. es32f369xbsp(es32f3696lx)

   ![image-20220630160331334](picture/image-20220630160331334.png)

3. RT-Thread SettingsRTduino

   ![image-20220706134522478](picture/image-20220706134522478.png)

   Studio

* 

1. Unknown flag "-T"

   ->->C/C++->GNU ARM Cross C++ Linker -> Generallds`"${workspace_loc:/${ProjName}/drivers/linker_scripts/link.lds}"`

   ![image-20220701145240404](picture/image-20220701145240404.png)

2. Fault

    ->->C/C++->GNU ARM Cross C++ Complier-> Miscellaneous Other compiler flags ` -mcpu=cortex-m3 -mthumb`

   ![image-20220701145153781](picture/image-20220701145153781.png)

## 2 Arduino

BSPArduino UNOLED [pins_arduino.c](pins_arduino.c)  [pins_arduino.h](pins_arduino.h)

| Arduino | ES32 |              |
| --------------- | ------------ | ---------------- |
| D0              | PE3          | UART2 RX         |
| D1              | PE2          | UART2 TX         |
| D2              | PE4          | IO           |
| D3              | PA2          | PWM2 3       |
| D4              | PE5          | IO           |
| D5              | PA1          | PWM2 2       |
| D6              | PA0          | PWM2 1       |
| D7              | PE6          | IO           |
| D8              | PB8          | IO           |
| D9              | PB9          | IO           |
| D10             | PB0          | SPI/IO   |
| D11             | PB5          | SPI1_MOSI/IO |
| D12             | PB4          | SPI1_MISO/IO |
| D13             | PD3          | SPI1_SCK/IO  |
| D14             | PB7          | I2C0_SDA         |
| D15             | PB6          | I2C0_SCL         |
| D16             | PC8          | LED4             |
| D17             | PC12         | LED5             |
| D18             | PC7          | LED6             |
| D19             | PC6          | LED7             |
| D20             | PF1          | KEY_UP           |
| D21             | PF4          | KEY_DOWN         |
| D22             | PF6          | KEY_LEFT         |
| D23             | PF0          | KEY_RIGHT        |
| D24             | PF7          | KEY_CENTER       |
| A0              | PC0          | ADC              |
| A1              | PC1          | ADC              |
| A2              | PC2          | ADC              |
| A3              | PC3          | ADC              |
| A4              | PA4          | ADC              |
| A5              | PA5          | ADC              |



## 3 I2C

ES32-ArduinoI2Ci2c0

I2CRT-Thread I2C`#include <Wire.h>`ArduinoI2C`Adafruit_I2CDevice.h`

## 4 SPI

ES32-ArduinoSPIspi0 `SCK``MISO``MOSI`RT-Thread SPI3`#include <SPI.h>`ArduinoSPIArduino`Adafruit_SPIDevice.h`

## 5 

applications/arduino_pinout/examples/arduino_examples.cpparduino,arduino_examples.cppapplications/arduino_main.cpp

1. RTduino



|                  |                |                                                          |
| ---------------------- | ------------------ | ------------------------------------------------------------ |
| ARDU_TEST_GPIO         | GPIO       | /0.5s |
| ARDU_TEST_PWM          | PWM    | PWMPWM |
| ARDU_TEST_ADAFRUIT_I2C | AdafruitI2C    | AdafruitI2C"ABtestabtest" |
| ARDU_TEST_ADAFRUIT_SPI | AdafruitSPI    | AdafruitSPI"test"        |
| ARDU_TEST_I2C          | I2C            | I2C"test"              |
| ARDU_TEST_SPI          | SPI            | SPI"test"        |
| ARDU_TEST_INT          |            |                  |
| ARDU_TEST_DIGITAL_READ |          |                  |
| ARDU_TEST_ADC_READ     | ADC            | ADC                        |
| ARDU_TEST_BMI160_PKG   | BMI160 | BMI160 |

2. arduino

   [DFRobot_BMI160](https://github.com/DFRobot/DFRobot_BMI160)

    packages\RTduino-latest\libraries\user

   856Wire.requestFrom(dev->id,(uint8_t)len);

   BMI160DFRobot_BMI160keil
   
   1. INT8_CUINT8_Cpins_arduino.hArduino 
   
      ```c
      #ifndef INT8_C
      #define INT8_C(x) ((int8_t)x)
      #endif
      #ifndef UINT8_C
      #define UINT8_C(x) ((uint8_t)x)
      #endif
      ```

   2. Data initializer is not allowed
   
      AC5arduino_main.cppDFRobot_BMI160.cpp --cpp11 --gnu
   
      AC6 --cpp11 --c11 --gnu
   
   RT-Thread Studio

## 6 

### 1.ADC
ES32ADC
### 2.IOpinMode
IOpinModeIOpinModeIO
### 3.SPI/I2C/UART

spi0i2c0uart2(),spi/i2c/uartESCodeMaker

SPIbegin

### 4.RTduino "posix/xxx.h cannot find"
 "posix/xxx.h cannot find"rt-threadgithub

## 7 

- [ | RT-ThreadArduinoES32](https://mp.weixin.qq.com/s/O693pgCLl1xOGxE9O7zaHA)
