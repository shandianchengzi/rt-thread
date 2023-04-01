# STM32F107 C/Eval  BSP 

## 

 STM32F107 C/Eval  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

C/Eval-STM32F107  ARM Cortex-M3 ST 



![board](figures/board.png)

 **** 

- MCUSTM32F107VCT6 72MHz256KB FLASH 64KB RAM
- 
  - LED3LED1PD13LED2PD14LED3PD15
- USB SD 
-  SWD

 [STM32F107 C/Eval ](http://bmrtechcom9808.bs03.pc51.com/BMRM/Micrium/STM32F107_Chinese%20version%20user%20manual.pdf)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          | UART2                             |
|             |      |                                       |
| SD              |      |                                       |
| CAN               |      |                                       |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PE15 ---> PIN: 0, 1...100 |
| UART              |          | UART2                                 |
| SPI               |      |                               |
| I2C               |      |                               |
| RTC               |      |                               |
| PWM               |      |                               |
| USB Device        |      |                               |
| USB Host          |      |                               |
| IWG               |      |                               |
| ****      | **** | ****                              |
| EMW3280           |      |                                       |

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

>  ST_LINK  ST_LINK 

#### 

LED1LED1

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  2  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

-  [whj](https://github.com/whj4674672), <whj4674672@163.com>