# BSP README 

## 

ek-tm4c123gxl BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 





![](E:\00MyWorkSpace\tm4c123_rtos\tm4c123bsp\figures\board.jpg)

 **** 

- MCUTM4C123Gh6PM 80MHz256KB FLASH 32KB RAM
-  RAMxMB
-  FLASHxMB
- 
  - LED1PF1PF2,PF3
  - 2SW1PF4SW2PF0
- ICDIUSB
- ICDI

TI [TM4C123G](https://www.ti.com/tool/EK-TM4C123GXL?DCMP=stellaris-launchpad&HQS=tm4c123g-launchpad)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| SPI Flash         |          |                                       |
|             |          |                                       |
| SD              |      |                                       |
| CAN               |      |                                       |
| ****      | **** | ****                              |
| GPIO              |          | PF0, PF1... PF4---> PIN: 0, 1...4 |
| UART              |          | UART0/1/2/3                        |
| SPI               |          | SPI0/1/2                            |
| I2C               |          |  I2C                              |
| SDIO              |      |                               |
| RTC               |      |                               |
| PWM               |      | PWM0/1/2/3/4/5/6/7             |
| USB Device        |      |                               |
| USB Host          |      |                               |
| IWG               |      |                               |
| ****      | **** | ****                              |
|     xxx       |      |                                      |

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

>  ICDI USB

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  0  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- BSPboard/tm4c123gh6pz_config.c/hboard.c

## 

:

-  [AHTYDHD](https://github.com/LYH-ux), <1780328728@qq.com>