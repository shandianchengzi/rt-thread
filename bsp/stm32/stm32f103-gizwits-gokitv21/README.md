# GoKit V2.1  BSP 

## 

 GoKit V2.1  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

GoKit V2.1  (GizWits)  ARM Cortex-M3  72Mhz STM32F103 



![board](figures/board.png)

 **** 

- MCUSTM32F103C8T6 72MHz64KB FLASH 20KB RAM
- 
  - LED4LED1 - LED4
  - 1RESET 
- USB 
-  SWD

 [GoKit V2.1 ](http://docs.gizwits.com/zh-cn/deviceDev/Gokit2%E4%BD%BF%E7%94%A8%E6%8C%87%E5%8D%97.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| LED               |          |                                       |
| RGB LED           |      |                                       |
| ****      | **** | ****                              |
| GPIO              |          | PA0-PA15PB0-PB15PC13              |
| UART              |          | UART1                                 |
| SPI               |      |                                       |
| I2C               |      |                                       |
| SDIO              |      |                                       |
| RTC               |      |                                       |
| PWM               |      |                                       |
| USB Device        |      |                                       |
| USB Host          |      | 		                               |
| IWG               |      | 		                               |
| ****      | **** | ****                              |
|   gokit v2.3      |      |                                       |

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

>  Jlink  Jlink 

#### 

LED4 

 PC , 115200-8-1-N RT-Thread :

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Jun  7 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO  1  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

## 

:

-  [](https://github.com/lhxzui), <iuzxhl@qq.com>