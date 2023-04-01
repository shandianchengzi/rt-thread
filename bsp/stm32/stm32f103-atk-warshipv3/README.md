# STM32F103 V3 BSP 

## 

 V3  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F103V3



![board](figures/board.png)

 **** 

- MCUSTM32F103ZET6 72MHz512KB FLASH 64KB RAM
-  RAM
-  FLASHW25Q128SPI2128MBEEPROM24c02
- 
  - LED2DS0PB5DS1PE5
  - 4K0PA0K1PE4, K2 (PE3) , K3 (PE2)
- USB SD LCD USB SLAVE
-  ST-LINK SWD 

[V3](http://www.openedv.com/thread-13912-1-1.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |    UART1                              |
| SPI Flash         |          |   W25Q128 128M FLASH  SPI2           |
|             |          |    DM9000                             |
| SD              |          |                                      |
| RS485             |          |    USART2                            |
| ****      | **** | ****                               |
| GPIO              |          | PA0, PA1... PG15 ---> PIN: 0, 1...111 |
| UART              |          | UART1/2/3                             |
| SPI               |          | SPI1/2                            	  |
| I2C               |          |  I2C                              |
| ADC               |          |                                      |
| RTC               |          |  |
| PWM               |          | TIM3 CH1  TIM3 CH2                   |
| CAN               |          |                                      |
| IWG               |          |                                      |
| ****       | **** | ****                              |
|    esp8266        |          |    USART3                            |

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

>  ST-Link  ST-Link 

#### 

 LED  

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Mar 10 2019
 2006 - 2019 Copyright by rt-thread team
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

-  12MHz ;
- USBTTLPC ;
-  PuTTyXShell sscom

## 

:

-  [obito0](https://github.com/obito0), <496420502@qq.com>