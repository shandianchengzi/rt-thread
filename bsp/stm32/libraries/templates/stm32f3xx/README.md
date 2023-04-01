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
  - LEDxLD2PB13
  - xB1B2
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
| UART              |          | UART2/x/x                       |
| SPI               |          |                               |
| I2C               |          |                             |
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
 / | \     4.0.4 build Jul 28 2021
 2006 - 2021 Copyright by rt-thread team
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

- xxx

## 

:

-  [xxx](https://), <xxx@xxx.com>
