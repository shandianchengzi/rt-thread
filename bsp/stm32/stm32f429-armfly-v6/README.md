# STM32F429 armfly-v6  BSP 

## 

 RT-Thread  STM32F429 armfly-v6  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

armfly-v6 STM32F429  ARM Cortex-M4  180Mhz STM32F429 



![board](figures/board.png)

 **** 

- MCUSTM32F429IGT6 180MHz2048KB FLASH 256KB RAM
-  RAMMT48LC4M32B2SDRAM16MB32bit
-  FLASHW25Q64BVSSIGSPI8MBHY27UF081G2ANAND128MB
- 
  - LED4IO LED1 - LED4
  - 4k1PI8K2PC13k3PH4
- USB SD LCD 
- SWD

 [STM32 v6 ](https://armfly.taobao.com/)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| IO            |          |                     |
| SPI Flash         |          |                                       |
|             |          |                                       |
| MPU6050 |          |                                       |
| SDRAM             |          |                                       |
| SD              |      |                                       |
| LCD               |      |  RGB                                 |
| CAN               |  |                                            |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART              |          | UART1                             |
| SPI               |          | SPI1/2/5                              |
| I2C               |          |  I2C                              |
| ADC               |          |                                     |
| RTC               |          |  |
| WDT               |          |                                       |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| SDIO              |      |                               |
| PWM               |      |                               |
| USB Device        |      |                               |
| USB Host          |      |                               |
| ****      | **** | ****                              |
| ad7606 |      |                               |

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

 LED LED2 - 4 LED1 

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



## 

:

- [zylx](https://github.com/qgyhd1234)