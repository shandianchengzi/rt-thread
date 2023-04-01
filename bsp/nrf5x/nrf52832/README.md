# nRF52832-PCA10040 BSP

## 

nRF52832[PCA10040](https://www.nordicsemi.com/Software-and-tools/Development-Kits/nRF52-DK)


- 
- 

## 

PCA10040-nRF52832Nordic nRF52832 ARM Cortex-M464 MHz



![](../docs/images/nrf52832.png)

PCA10040-nrf52832 **** 

- MCUNRF52832 64MHz512kB FLASH 64kB RAM
- MCU : GPIO, UART, SPI, I2C(TWI), RTC,TIMER,NFC,PWM,ADC
- 
  - LED4 
  - 54USER and 1RESET 
- Arduino Uno 
-  J-LINK 

NORDIC[PCA10040](https://www.nordicsemi.com/Software-and-tools/Development-Kits/nRF52-DK)



## 

 BSP 

| **** | **** |   ****    |
| :----------- | :----------: | :-----------: |
| GPIO         |          |     GPION     |
| UART         |          |     UART0     |
| PWM          |          |           |
| SPI          |          |           |
| RTC          |          |               |
| ADC          |          |               |
| TIMER        |          | TIMER0~TIMER4 |
|              |              |               |
|              |              |               |



### 

 BSP  GPIO   0  env  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 


### VS Code



1. 

    ```bash
    export RTT_CC=gcc
    export RTT_EXEC_PATH=</bin>
    ```

2. `Cortex-debug`
3. [nRF Command Line Tools](https://www.nordicsemi.com/Software-and-tools/Development-Tools/nRF-Command-Line-Tools)`nrfjprog`
4. .vscode/settings.json`JlinkGDBServer`sample

    ```json
    {
        "cortex-debug.armToolchainPath": "/usr/local/gcc-arm-none-eabi-9-2019-q4-major/bin/",
        "cortex-debug.armToolchainPrefix": "arm-none-eabi",
        "cortex-debug.JLinkGDBServerPath": "/Applications/SEGGER/JLink/JLinkGDBServer"
    }
    ```

5. ``->``->`build```->``->`flash``debug`->`run`VS Codedebug

## 

.configboard/Kconfigboard/$(board_name)README.md

## 

## 

:

-  