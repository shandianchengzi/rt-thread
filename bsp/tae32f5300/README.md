#  TAE32F5300_EVAL_BOARD  BSP 

## 

 TAE32F5300_EVAL_BOARD  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

![image-20210905115438031](.\figures\TAE32_EVBorad.png)

TAE32F5300_EVAL_BOARD  TAE32F5300  ARM Cortex-M3  90 MHzERPU can 485 USB LED

TAE32F5300_EVAL_BOARD  **  ** 

- MCUTAE32F5300 90MHz75KBFLASH  16KB  FLASH ,  16KB  SRAM+8KB  SRAM SRAM 4KB+4KB
- 
  - 
  - USB
  - LED
  - 
  - 
  - 
  - 
  - EEPROM
  - 
  - RS485
  - CAN
  - uart lcd
-  JTAG/SWD

 [TAE32F5300_EVAL_BOARD](http://www.tai-action.com/)

## 

 BSP 

| **  **  | **  ** |               **  **                |
| :------------ | :-----------: | :-----------------------------------: |
| LED           |          |           LED                   |
| **  **  | **  ** |               **  **                |
| :------------ | :-----------: | :-----------------------------------: |
| GPIO          |          | PA0, PA1... PI15 ---> PIN: 0, 1...144 |
| UART          |          |              UART0~1                 |
| I2C           |          |               I2C                 |
| LED           |          |              LED1~3                     |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  GCC  MDK5 

#### 

#### CMSIS-DAP 

| TAE32  | CMSIS-DAP |
| :---------- | :-------: |
| SWDIO       |   SWDIO   |
| SWCLK       |   SWCLK   |
| VCC         |   3.3v    |
| GND         |    GND    |

 USB 

| TAE32  |  USB |
| :---------- | :-------: |
| RXD(PA10)   |    TXD    |
| TXD(PA11)   |    RXD    |
| GND         |    GND    |

#### 

 project.uvprojx  MDK5 

>  CMSIS-DAP 

#### 

 LED PB6  500ms 
```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Aug 29 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO   0  env  BSP 

1.  bsp  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk5` 

## 

## 

:

-  qinweizhong <369247354@qq.com>