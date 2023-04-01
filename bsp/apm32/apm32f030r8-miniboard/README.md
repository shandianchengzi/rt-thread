# APM32F030R8 MINI BOARD BSP 

## 

 APM32F030R8 MINI MINI BOARD BSP () 



- 
- BSP 

 BSP RT-Thread 

## 

APM32F030R8 MINI BOARDJTAG/SWDIO

![image-20230112193014399](figures/APM32F030R8-MINI.png)

- [ ](https://www.geehy.com/support/apm32?id=192)


 **** 

- MCUAPM32F030R8T6 48MHz64KB FLASH 8KB RAM
-  RAM
-  FLASH
- 
  - LED2PB6/PB7
  - 2K1PA1K2PA0
- RS232USB SLAVE
-  JTAG/SWD

## 

 BSP 

| **** | **** | ****                             |
| :----------- | :----------: | :------------------------------------ |
| RS232  |          |  UART1/ UART2()       |
| **** | **** | ****                             |
| GPIO         |          | PA0, PA1... PF10 ---> PIN: 0, 1...89 |
| UART         |          | UART1/2                               |
| ADC          |          | ADC1                              |
| DAC          |          | DAC1                                  |
| RTC          |          |             |
| TMR          |          | TMR1/3/6/7/14/15/16/17     |
| PWM          |          | TMR3 ->CH1/2/3/4                      |
| I2C          |          | I2C                               |
| SPI          |          | SPI1/2                              |
| WDT          |          | IWDT                                  |

## 

 RT-Thread  RT-Thread  


### 

 BSP MDK5  MDK5 

#### 

 PC

#### 
- MDK

    project.uvprojx  MDK5 

>  J-Link  J-Link 

- J-Flash

  ENVsconsMDKbinJ-Flashbin

##### 1J-Flash

![board](figures/JFlash_Leader_01.png)

****4 **APM32F030R8T6** 

##### 2

![board](figures/JFlash_Leader_02.png)
##### 3bin0x8000000
![board](figures/JFlash_Leader_03.png)
##### 4
![board](figures/JFlash_Leader_04.png)

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.1.0 build Aug 20 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```
## 

- packMINIwww.geehy.com

## 

-[abbbcc ](https://gitee.com/abbbcc)

-[stevetong459 ](https://github.com/stevetong459)

-[luobeihai](https://github.com/luobeihai)