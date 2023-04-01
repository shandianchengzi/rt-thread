# APM32F107VC EVAL BOARD BSP 

## 

 APM32F107 EVALEVAL BOARD BSP () 



- 
- BSP 

 BSP RT-Thread 

## 

APM32F107 EVAL BOARDJTAG/SWDIO

![image-20230112142637973](figures/APM32F107VC-EVAL.png)

- [ ](https://www.geehy.com/support/apm32?id=192)


 **** 

- MCUAPM32F107VCT6 72MHz256KB FLASH 64KB RAM
-  RAM
-  FLASHW25Q16SPI, 16M bit
- 
  - LED3PE7/PE8/PE9
  - 3K1PE10K2PC0K3PE12
- USBSPI LCDUSB OTG
-  JTAG/SWD

## 

 BSP 

| **** | **** | ****                             |
| :----------- | :----------: | :------------------------------------ |
| USBUSART |          |  UART4      |
| SPI Flash |  | W25Q16 |
| EEPROM |  | i2c1 |
|  |  | PHY: DP83848, RMII  |
| **** | **** | ****                             |
| GPIO         |          | PA0, PA1... PG15 ---> PIN: 0, 1...108 |
| UART         |          | UART1/2/3/4                           |
| ADC          |          | ADC1/2                              |
| DAC          |          | DAC1                                  |
| RTC          |          |             |
| TMR          |          | TMR1/2/3/4/5/6/7                    |
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

****4 **APM32F107VCT6** 

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

- packwww.geehy.com

## 

-[abbbcc ](https://gitee.com/abbbcc)

-[stevetong459 ](https://github.com/stevetong459)

-[luobeihai](https://github.com/luobeihai)