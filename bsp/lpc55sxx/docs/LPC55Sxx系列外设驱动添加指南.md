# LPC55Sxx 

## 1. 

 LPC55Sxx BSP  BSP 

## 2. 

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/rtthread-development-guide/rtthread-tool-manual/env/env-user-manual/)
-  Kconfig 
-  MCUXpresso 
-  RT-Thread 

## 3. 

 BSP  ``  LPCXpresso55S69-EVK BSP  I2C1 

> MCUXpresso [ NXP ](https://www.nxp.com/cn/support/developer-resources/software-development-tools/mcuxpresso-software-and-tools:MCUXPRESSO ) MCUXpresso 

LPCXpresso55S69 BSP  Flexcomm4I2CFlexcomm I2C

![spi_config](figures/i2c_config.png)

 I2C4 

### 1.  MCUXpresso 

 BSP  MCUXpresso 

![1543486779576](figures/open_mcuxpresso.png)

### 2.  I2C1 

 I2C1

![MCUXpresso Config Tool](figures/mcux_i2c.png)

 BSP MCUXpressDMA RT-Thread 

### 3.  Kconfig 

 board  Kconfig  I2C4  I2C1 

![Kconfig](figures/Kconfig2.png)

### 4. 

 ENV  menuconfig  I2C4 

![MenuConfig ](figures/config5.png)

### 5. 

 ENV DMAI2C1

![i2c_code](figures/i2c_code.png)

### 6. 

 `list_device`  I2C1 

![list i2c1 device](figures/run_i2c.png)

## 4. 

-  BSP  LPC55Sxx  RT-Thread 

  -  LPC55Sxx  [LPC55Sxx](./LPC55Sxx.md)

-  [RT_Thread GitHub](https://github.com/RT-Thread/rt-thread)  [RT-Thread ](https://www.rt-thread.org/qa/forum.php)

## 5. 

### 5.1 

 BSP  MCUXpresso  MCUXpresso 

|  |       | MCUXpresso ****            |
| :--: | :------- | :----------------------------------------------- |
|  1   | GPIO     |  |
|  2   | UART     |     |
|  3   | SPI      |     |
|  4   | I2C      |          |
|  5   | TIMER | 5.3      |
|  6   | PWM      |  5.3 |
|  7   | ADC      | 5.3  |
|  8   | RTC      |      |
|  9  | Watchdog |                         |

### 5.2 



#### 5.2.1 Timer 

 1.  lpc55sxx/lpc55s69_nxp_evk/board/Kconfig  Kconfig 

 ![timer Kconfig ](figures/timer_config1.png)

  2. 

![timer ](figures/timer_config2.png)

 3.  `list_device`  gpt1 

 ![timer ](figures/timer_config3.png)

#### 5.2.2 PWM 

 1.  MCUXpresso  PWM  MCUXpresso 

 ![pwm MCUXpresso ](figures/pwm_config1.png)

 2.  lpc55sxx/lpc55s69_nxp_evk/board/Kconfig  Kconfig 

 ![pwm Kconfig ](figures/pwm_config2.png)

 3. 

 ![pwm ](figures/pwm_config3.png)

4.  `list_device`  pwm 

 ![pwm ](figures/pwm_device.png)

#### 5.2.3 ADC 

 1.  MCUXpresso  ADC  MCUXpresso  ![adc MCUXpresso ](figures/adc_config1.png)

  2.  lpc55sxx/lpc55s69_nxp_evk/board/board/Kconfig  Kconfig ![adc Kconfig ](figures/adc_config2.png)
  3. 

![adc ](figures/adc_config3.png)

4.  `list_device`  adc0 

 ![adc ](figures/adc_config4.png)
