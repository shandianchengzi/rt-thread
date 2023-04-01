# STM32 

## 1. 

 STM32 BSP  BSP 

## 2. 

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/rtthread-development-guide/rtthread-tool-manual/env/env-user-manual/)
-  Kconfig 
-  STM32CubeMX 
-  RT-Thread 

## 3. 

 BSP  ``  stm32f429-atk-apollo BSP  SPI3 

>  stm32cubemx  STM32cube<http://www.stm32cube.com/>  ``  stm32cubemx 

 BSP  SPI1SPI2  SPI5 SPI3  SPI3

![spi_config](figures/spi_config.png)

 SPI3 

### 1 STM32CubeMX 

 BSP  STM32CubeMX 

![1543486779576](figures/cubemx.png)

### 2 SPI3 

 SPI3

![1543487684698](figures/cube_spi3.png)

>  BSP STM32CubeMX ********DMA RT-Thread  STM32CubeMX  RT-Thread  STM32CubeMX   `stm32fxx_hal_msp.c`  `stm32fxx_hal_conf.h` 
>
>  STM32CubeMX  CubeMX 

### 3 Kconfig 

 board  Konfig  SPI2  SPI2  SPI3

![1543542657074](figures/Kconfig2.png)

### 4

 ENV  menuconfig  SPI3 

![1543543081284](figures/config5.png)

### 5

 ENV DMA

![spi_code](figures/spi_code.png)

### 6

 `list_device`  spi3 

![1543543446786](figures/run_spi3.png)


## 4. 

-  BSP  STM32  RT-Thread 
  -  STM32  [STM32](STM32.md)
-  [RT_Thread GitHub](https://github.com/RT-Thread/rt-thread)  [RT-Thread ](https://www.rt-thread.org/qa/forum.php)
-  .c/.h  rt-thread  stm32xxx_hal_msp.c 

![generate-code](figures/generate-code.png)

## 5. 

### 5.1 CubeMX

 stm32  BSP  CubeMX  BSP 

stm32  BSP   CubeMX   `stm32XXxx_hal_conf.h`  `stm32XXxx_hal_msp.c`  HAL  `stm32XXxx_hal_conf.h`  HAL  `stm32XXxx_hal_msp.c`  CubeMX 

### 5.2 

 BSP  CubeMX  CubeMX 

|  |      | CubeMx ****            |
| :--: | :------- | :----------------------------------------------------------- |
|  1   | GPIO     |                                                  |
|  2   | UART     | ****     |
|  3   | SPI      | ****     |
|  4   | I2C      | PIN                                 |
|  5   | TIMER    | ** internal Clock ** 5.3      |
|  7   | PWM      | ** internal Clock  channelx PWM Generation CHx**  5.3 |
|  8   | ADC      | **** 5.3  |
|  9   | RTC      | ** RTC  LSE **     |
|  10  | Watchdog | ****                                             |
|  11  | EMAC     | ** ETH  RMII **              |
|  12  | SDRAM    | ** SDRAM **    |
|  13  | SDIO     | **SDIOboard.c** |

### 5.3 



#### 5.3.1 TIMER 

 1.  STM32CubeMX  timer  Cube 

 ![timer CubeMX ](figures/timer_config1.png)

 2.  stm32/stm32f429-atk-apollo/board/Kconfig  Kconfig 

 ![timer Kconfig ](figures/timer_config2.png)

  3.  TIM11_CONFIG   stm32/libraries/HAL_Drivers/config/f4/tim_config.h 

 ![timer ](figures/timer_config3.png)
 ![timer ](figures/timer_config4.png)

#### 5.3.2 PWM 

 1.  STM32CubeMX  PWM  Cube 

 ![pwm CubeMX ](figures/pwm_config1.png)

 2.  stm32/stm32f429-atk-apollo/board/Kconfig  Kconfig 

 ![pwm Kconfig ](figures/pwm_config2.png)

 3.  PWM2_CONFIG   stm32/libraries/HAL_Drivers/config/f4/pwm_config.h 

 ![pwm ](figures/pwm_config3.png)
 ![pwm ](figures/pwm_config4.png)

#### 5.3.3 ADC 

 1.  STM32CubeMX  ADC  Cube 

 ![adc CubeMX ](figures/adc_config1.png)

 2.  stm32/stm32f429-atk-apollo/board/Kconfig  Kconfig 

 ![adc Kconfig ](figures/adc_config2.png)

 3.  ADC1_CONFIG   stm32/libraries/HAL_Drivers/config/f4/adc_config.h 

 ![adc ](figures/adc_config3.png)
 ![adc ](figures/adc_config4.png)

#### 5.3.4 

 1.  STM32CubeMX  TIMER  Cube 

 ![pulse_encoder CubeMX ](figures/pulse_encoder_config1.png)

 2.  stm32/stm32f407-atk-explorer/board/Kconfig  Kconfig 

 ![pulse_encoder Kconfig ](figures/pulse_encoder_config2.png)

 3.  PULSE_ENCODER4_CONFIG   stm32/libraries/HAL_Drivers/config/f4/pulse_encoder_config.h 

 ![pulse_encoder ](figures/pulse_encoder_config3.png)
 ![pulse_encoder ](figures/pulse_encoder_config4.png)
