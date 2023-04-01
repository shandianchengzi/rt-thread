# STM32F103  iBox BSP 

## 

 STM32F103  iBox  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

iBox ARM Cortex-M3  72MHz, STM32F103 



![board](figures/board.png)

 **** 

- MCUSTM32F103ZE 72MHz512KB FLASH 64KB RAM
-  RAM
-  FLASH
- 
  - LED3D7PE10D6PE9,D43(PE12)
  - 1sw1(PE15)
  -  1 U5 (PG6)
- I2CSPI
-  JTAG/SWD

 [iBox ](http://www.hw100k.com/forum.php?mod=viewthread&tid=3441&extra=page%3D2) 

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|             |          |  W5500    SPI2                    |
| RS485             |          |  MAX485   UART4                   |
| LoRa              |          |    LSD4RF-2F717N30  SPI1    |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PG15 ---> PIN: 0, 1...144 |
| UART              |          | UART1                                 |
| SPI               |      |                                       |
| I2C               |          |  I2C (J14)                        |
| RTC               |          |  |
| ADC               |          | ADC1_CHANEL_10, ADC1_CHANNEL_11       |
| PWM               |      |                                       |
| IWG               |          | iwdg_sample wdt                 |
| FLASH             |          |  FAL                            |
| ****      | **** | ****                              |
| WIFI  ESP8266     |          |  ESP-02    UART3              |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

USB Tx   TXD,  Rx   RXD , PC12V Jlink 

#### 

 project.uvprojx  MDK5 

>  JLink  JLink

#### 

 LED  LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Jan 11 2019
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1 WIFI  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  12MHz ;
-  WIFI ESP8266 ,  CH_PD (PG1)  ; 
-  W5500, ; 
-  Lora  sx12xx  ;
-  MAX485,    ;

## 

:

-  [XiaojieFan](https://github.com/XiaojieFan), <dingo1688@126.com>
