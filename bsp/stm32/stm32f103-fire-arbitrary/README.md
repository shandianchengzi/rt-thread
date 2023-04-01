# STM32F103  BSP 

## 

 RT-Thread  STM32F103  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32F103  ARM Cortex-M3  72Mhz STM32F103 



![board](figures/board.png)

 **** 

- MCUSTM32F103ZET6 72MHz512KB FLASH 64KB RAM
-  RAMIS62WV51216BLLSRAM1MB
-  FLASHW25Q64SPI8MB
- 
  - LED1RGB2LEDD4PF7D5PF8
  - 2K1PA0K2PC13
- USB SD LCD 
-  JTAG/SWD

 [STM32 ](https://fire-stm32.taobao.com/index.htm)

## 

 BSP 

| **** | **** | ****                              |
| :------------ | :----------: | :------------------------------------- |
| USB    |          |  UART1                            |
| RS232        |          |  UART2                            |
| SPI Flash    |          | W25Q64                                |
|        |          | W5500                                 |
|        |          |  ADC1                              |
| SD         |          |                                       |
| CAN          |          |                                       |
| SDRAM        |      |                                       |
| WIFI ESP8266 |      |                                       |
| **** | **** | ****                              |
| GPIO         |          | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART         |          | UART1/2/3                             |
| SPI          |          | SPI1/2/3                              |
| I2C          |          |  I2C                              |
| ADC          |          |                                      |
| RTC          |          |  |
| WDT          |          |                                       |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| SDIO         |          |                                      |
| PWM          |          |                                      |
| USB Device   |          |                                      |
| USB Host     |      |                               |
| **** | **** | ****                              |
|          |      |                               |

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

 LED  LED 

 PC , 115200-8-1-N RT-Thread :

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