# i.MX RT 

## 1. 

 i.MX RT BSP  BSP 

## 2. 

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/programming-manual/env/env/)
-  Kconfig 
-  MCUXpresso 
-  RT-Thread 

## 3. 

 BSP  ``  imxrrt1052-fire-pro BSP  I2C2 

> MCUXpresso [ NXP ](https://www.nxp.com/cn/support/developer-resources/software-development-tools/mcuxpresso-software-and-tools:MCUXPRESSO ) MCUXpresso 

 Pro BSP  I2C1 I2C2

![spi_config](figures/i2c2_config.png)

 I2C2 

### 1.  MCUXpresso 

 BSP  MCUXpresso 

![1543486779576](figures/open_mcuxpress.png)

### 2.  I2C2 

 I2C2

![1543487684698](figures/mcux_i2c2.png)

 BSP MCUXpressDMA RT-Thread 

### 3.  Kconfig 

 board  Konfig  I2C1  I2C1  I2C2

![1543542657074](figures/Kconfig2.png)

### 4. 

 ENV  menuconfig  I2C2 

![1543543081284](figures/config5.png)

### 5. 

 ENV DMAI2C2

![spi_code](figures/i2c2_code.png)

### 6. 

 `list_device`  I2C2 

![1543543446786](figures/run_i2c2.png)

## 4. 

-  BSP  i.MX RT  RT-Thread 

  -  i.MX RT  [i.MX RT](./IMXRT.md)

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
|  5   | GPT(HWTIMER) | 5.3      |
|  6   | PWM      |  5.3 |
|  7   | ADC      | 5.3  |
|  8   | RTC      |      |
|  9  | Watchdog |                         |
|  10  | SDRAM    |     |

### 5.2 



#### 5.2.1 GPT 

 1.  imxrt/imxrt1052-fire-pro/board/Kconfig  Kconfig 

 ![timer Kconfig ](figures/gpt_config1.png)

  2. 

 ![timer ](figures/gpt_config2.png)

 3.  `list_device`  gpt1 

 ![timer ](figures/gpt_config3.png)

#### 5.2.2 PWM 

 1.  MCUXpresso  PWM  MCUXpresso 

 ![pwm CubeMX ](figures/pwm_config1.png)

 2.  imxrt/imxrt1052-fire-pro/board/Kconfig  Kconfig 

 ![pwm Kconfig ](figures/pwm_config2.png)

 3. 

 ![pwm ](figures/pwm_config3.png)

4.  `list_device`  pwm 

 ![pwm ](figures/pwm_device.png)

#### 5.2.3 ADC 

 1.  MCUXpresso  ADC  MCUXpresso 

 ![adc CubeMX ](figures/adc_config1.png)

 2.  imxrt/imxrt1052-fire-pro/board/Kconfig  Kconfig 

 ![adc Kconfig ](figures/adc_config2.png)

 3. 

 ![adc ](figures/adc_config3.png)

4.  `list_device`  adc1 

 ![adc ](figures/adc_config4.png)
