# nRF52840-PCA10056 BSP

## 

nRF52840



|                                                |                 |                                 |
| ------------------------------------------------------------ | --------------------------- | ----------------------------------- |
| [PCA10056](https://www.nordicsemi.com/Software-and-tools/Development-Kits/nRF52840-DK) | QSPI FLASH, 4 button4 LED | UART0                               |
| [ARDUINO NANO 33 BLE](https://store.arduino.cc/usa/nano-33-ble-sense-with-headers) | 3 LED                       | jlink shellRTT  |
|                                                              |                             |                                     |

[BSP_BOARD_NRF52840](https://github.com/supperthomas/BSP_BOARD_NRF52840)

`menuconfig` -> `Hardware Driver Config` -> `Select Bsp board`





- 
- 

## 

PCA10056-nRF52840Nordic nRF52840 ARM Cortex-M464 MHz



![image-20201017202046725](../docs/images/nrf52840.png)

PCA10056-nrf52840  **** 

- MCUNRF52840 64MHz1MB FLASH 256kB RAM
- MCU : GPIO, UART, SPI, I2C(TWI), RTC,TIMER,NFC,QSPI,PWM,ADC,USB,I2S
- 
  - LED4USB communication (LD1), user LED (LD2), power LED (LD3) 
  - 54USER and 1RESET 
  - USB:   1
- USB deviceArduino Uno 
-  J-LINK 

NORDIC[PCA10056](https://www.nordicsemi.com/Software-and-tools/Development-Kits/nRF52840-DK)



## 

 BSP 

| **** | **** |          ****           |
| :----------- | :----------: | :-------------------------: |
| GPIO         |          |            GPION            |
| UART         |          |            UART0            |
| PWM          |          |                         |
| SPI          |          |                         |
| QSPI         |          |   QSPI FLASH    |
| RTC          |          |                             |
| ADC          |          |                             |
| SEGGER_RTT   |          | segger_rttconsole |
|              |              |                             |
|              |              |                             |



### 

 BSP  GPIO   0  env  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 



## 

.configboard/Kconfigboard/$(board_name)README.md.config

## 

## 

:

-  [supperthomas], <78900636@qq.com>