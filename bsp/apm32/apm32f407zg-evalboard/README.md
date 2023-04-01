# APM32F407ZG EVAL BOARD BSP 

## 

 APM32F407ZG EVAL EVAL BOARD BSP () 



- 
- BSP 

 BSP RT-Thread 

## 

APM32F407ZG EVAL BOARDJTAG/SWDIO

![image-20230112193936832](figures/APM32F407ZG-EVAL.png)

- [ ](https://www.geehy.com/support/apm32?id=192)


 **** 

- MCUAPM32F407ZGT6 168MHz1MKB FLASH 192+4KB RAM
-  RAM
-  FLASHW25Q16SPI, 16M bit
- 
  - LED3PC0/PC2/PC3
  - 4K1PB0K2PB1K3PF12K4PA5
- RS232LCDUSB HostUSB Device
-  JTAG/SWD

## 

 BSP 

| **** | **** | ****                             |
| :----------- | :----------: | :------------------------------------ |
| RS232  |          |  UART1       |
| SPI Flash |  | W25Q16 |
|  |  | PHY: LAN8720, RMII  |
| **** | **** | ****                             |
| GPIO         |          | PA0, PA1... PI11 ---> PIN: 0, 1...134 |
| UART         |          | UART1/2                               |
| ADC          |          | ADC1/2/3                              |
| DAC          |          | DAC1                                  |
| RTC          |          |             |
| TMR          |          | TMR1/2/3/4/5/6/7/8/9/10/11/12/13/14   |
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

****4 **APM32F407ZGT6** 

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

-[Aligagago ](https://github.com/Aligagago)

-[luobeihai](https://github.com/luobeihai)