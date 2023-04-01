# BSP README 

## 

 xxx  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 





![board](figures/board.png)

 **** 

- MCUSTM32xxx xxxMHzxxxKB FLASH xxxKB RAM
-  RAMxMB
-  FLASHxMB
- 
  - LEDxDS0PB1DS1PB0
  - xK0PA0K1PC13
- USB SD LCD 
-  JTAG/SWD

 [xxx](https://xxx)

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
| GPIO              |          | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART              |          | UART1/x/x                             |
| SPI               |          | SPI1/x/x                              |
| I2C               |          |  I2C                              |
| SDIO              |      |                               |
| RTC               |      |                               |
| PWM               |      |                               |
| USB Device        |      |                               |
| USB Host          |      |                               |
| IWG               |      |                               |
| xxx               |      |                               |
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

>  xxx  xxx 

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

 BSP  GPIO  1  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- xxx

## 

:

-  [xxx](https://), <xxx@xxx.com>