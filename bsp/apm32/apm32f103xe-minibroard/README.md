# APM32F103ZE MINI BOARD BSP 

## 

 APM32F103ZE MINI MINI BOARD BSP () 



- 
- BSP 

 BSP RT-Thread 

## 

APM32F103ZE MINI BOARDJTAG/SWDIO

![board](figures/APM32F103ZE.png)

- [ ](https://www.geehy.com/support/apm32?id=192)


 **** 

- MCUAPM32F103ZET6 96MHz512KB FLASH 128KB RAM
-  RAM
-  FLASH
- 
  - LED2PE5/PE6
  - 2K1PA1K2PA0
- RS232USB SLAVE
-  JTAG/SWD



## 

 BSP 

| **** | **** | ****                             |
| :----------- | :----------: | :------------------------------------ |
| RS232  |          |  UART1/ UART2()       |
| **** | **** | ****                             |
| GPIO         |          | PA0, PA1... PG15 ---> PIN: 0, 1...108 |
| UART         |          | UART1/2                               |
| ADC          |          | ADC1/2/3                              |
| DAC          |          | DAC1                                  |
| RTC          |          |             |
| TMR          |          | TMR1/2/3/4/5/6/7/8                    |
| PWM          |          | TMR3 ->CH1/2/3/4                      |
| I2C          |          | I2C                               |
| SPI          |          | SPI1/2/3                              |
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

- packMINIwww.geehy.com;

## 

-[abbbcc ](https://gitee.com/abbbcc)

-[stevetong459 ](https://github.com/stevetong459)
