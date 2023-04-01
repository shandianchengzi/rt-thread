#  IMXRT  BSP 

## 

 RT-Thread  imxrt1052-atk-commander  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 imxrt1052-atk-commander  ARM Cortex-M7  600Mhz RT1052CVL5B 



![board](figures/board.png)

 **  ** 

- MCURT1052CVL5B 100MHzSRAM512KBI/D Cache32KB
-  SDRAM W9825G6KH 32M 
-  SPI FLASH W25Q64 8M 
-  SPI FLASH W25Q256 32M 
-  EEPROM AT24C02 256 
- 
  - LED2 DS0 DS1
  - 4 
- USB 
-  JTAG/SWD 

 [ IMXRT ](http://www.openedv.com/forum.php?mod=viewthread&tid=268974)

## 

 BSP 

|  |  |                               |
| :------------ | :----------: | :-----------------------------------: |
| GPIO         |          | GPIO1~GPIO5  |
| UART         |          |  UART1UART4      |
| SPI         |           |  SPI3      |
| **** | **** |               ****                |
|  SPI FLASH    |           |  SPI3      |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  MDK5 

#### 

 Type-A to Mini-B  USB  PC 

#### 

 RT1052  FLASHboard MIMXRT105x_QuadSPI_4KB_SEC.FLM  MDK ARMFlash project.uvprojx  MDK5 

![](figures/flash.png)

 JLink 

#### 

 LED  DS1 

USB  1115200-8-1-N RT-Thread :

```c
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build May 24 2019
 2006 - 2019 Copyright by rt-thread team
msh />
```
### 

 BSP  GPIO   1  ENV  BSP 

1.  BSP  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32  BSP . md)

## 



## 

:

- [misonyo](https://github.com/misonyo) <misonyo@foxmail.com>