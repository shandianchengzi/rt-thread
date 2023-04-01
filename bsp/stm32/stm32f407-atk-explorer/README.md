# STM32F407  BSP 

## 

 RT-Thread  STM32F407  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32F407  ARM Cortex-M4  168Mhz STM32F407 



![board](figures/board.png)

 **** 

- MCUSTM32F407ZGT6 168MHz1024KB FLASH 192KB RAM
-  RAMIS62WV512161MB
-  FLASHW25Q128SPI16MB
- 
  - LED2DS0PB1DS1PB0
  - 4KEY_UPPIN0K0PIN68K1PIN67K2PIN66
- USB SD LCD USB SLAVEUSB HOST
-  JTAG/SWD

 [STM32 ](https://eboard.taobao.com/index.htm)

## 

 BSP 

| **** | **** |               ****                |
| :------------ | :----------: | :-----------------------------------: |
| USB (COM1) |          |                                    |
| COM2         |     | PWM  CubeMX  UART2  |
| COM3         |     |                                           |
| MPU6050      |          |                                       |
| Flash        |      |                               |
| SRAM         |      |  LVGL  RT_USING_MEMHEAP_AS_HEAP  |
| TFTLCD       |      | F407  LTDC  MCU LCD RGB  |
| LCD-TOUCH    |      |  GT9147,  |
| SD         |      | FATFS |
| W25Q128 |  | LittleFS |
|        |      |                               |
| WM8978       |      |                                       |
| **** | **** |               ****                |
| GPIO         |          | PA0, PA1... PH1 ---> PIN: 0, 1...144 |
| UART         |          |              UART1/2/3              |
| SPI          |          |               SPI1/2/3                |
| I2C          |          |       I2C1, I2C2[]     |
| ADC          |          |                                       |
| RTC          |          |  |
| WDT          |          |                                       |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| PWM          |      |                               |
| USB Device   |      |                               |
| USB Host     |      |                               |
| **** | **** |               ****                |
| ATK-ESP8266  |  | COM3 |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

>  JLink  JLink 

#### 

 LED  LED  LED 

 PC , 115200-8-1-N RT-Thread :

>  PuTTyXShell sscom

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

- [guozhanxin](https://github.com/Guozhanxin)