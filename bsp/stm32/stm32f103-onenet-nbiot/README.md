# STM32F103  OneNET NB-IoT  BSP 

## 

 RT-Thread  STM32F103 OneNET NB-IoT  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

OneNET NB-IoT V2.1  ARM Cortex-M3 32  STM32F103RET6 M5310 NB  OneNETCoAP+LwM2M  SHT20 ADXL345
BH1750FVI BMP180 LED 



<img src="figures\board_front.png" alt="board_front" style="zoom:80%;" />

 **** 

- MCUSTM32F103RET6 72MHz512KB FLASH 64KB RAM
- 
  - LED4PA4-PA7
  - 5KEY_RSTNRSTKEY1PC0KEY2PC1KEY3PC2KEY4PC3
- USB SIM OLED
- :   SWD 

OneNET [STM32 OneNET NB-IoT ](https://open.iot.10086.cn/bbs/thread-19650-1-1.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |   UART1                              |
| (BH1750FVI) |          |                            |
| (BMP180) |  |                            |
| (SHT20) |  |                            |
| M5310 NB-IoT |  |                            |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1...PD2 ---> PIN: 0, 1...63 |
| UART              |          | UART1/2/3/4                          |
| I2C               |          |                            |
| RTC            |          |  |
| IWDG |  |  |
| FLASH |          |  |
| ****      | **** | ****                              |
|  |      |                               |
| OLED |  | |

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

 LED  LED0 

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

 BSP  GPIO  1  Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 




## 

:

- [DriftSnail](https://github.com/DriftSnail) 

