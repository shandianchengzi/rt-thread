# NUCLEO-L452RE BSP 

## 

 NUCLEO-L452RE  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 NUCLEO-L452RE Cortex-M4 ST-LINK/V2-1 /MINI USB  ArduinoST Zio ST Morpho 



![board](figures/board.jpg)

 **** 

- MCUSTM32L452RE 80MHz512KB FLASH 160KB RAM
- 
  - LED3USB communication(LD1 ),power LED(LD3 ),user LED(LD2 )
  - 2 B2 B1
- USB  3  COM 
-  ST-LINK/V2-1 

STMicroelectronics [NUCLEO-L452RE](https://www.st.com/en/evaluation-tools/nucleo-l452re.html#)

## 

 BSP 

| ****      | **** | ****                              |
| :---------------: | :----------: | :-----------------------------------: |
| ST-LINK           |          |                                       |
| USB         |          | UART2                                 |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PC15 ---> PIN: 0, 1...47  |
| UART              |          | UART1(TX:PA9 RX:PA10)UART2(TX:PA2  RX:PA2)                                 |
| SPI               |      |  SPI1                                       |
| I2C               |      |                                       |
| RTC               |      |                                       |
| PWM               |      |                                       |
| USB Device        |      |                                       |
| IWG               |      |                                       |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

>  ST-LINK  miniUSB 

#### 

 LED  LD3  LD2 

 PC , 115200-8-1-N RT-Thread :

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build May 31 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO  2  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

1. MCU  SRAM  SRAM1SRAM2 128KB32KB 160KB bsp  SRAM1 128KB.

## 

:

-  [](https://github.com/lhxzui), <iuzxhl@qq.com>