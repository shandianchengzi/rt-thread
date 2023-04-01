# i.MX RT1052  EVK Pro  BSP 

## 

 RT-Thread  i.MX RT1052 EVK Pro  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

i.MX RT1052 EVK Pro  ARM Cortex-M7  600Mhz RT1052 



![board](figures/board.png)

****

- MCUi.MX RT1052 600MHz
- 32MB SDRAM128MB NANDFLASH32MB QSPI FLASH2Kb EEPROM
- 
  - MPU6050
  - AP3216C
  - LEDRGB 
- USB SD LCD 
-  JTAG/SWD

 [i.MX RT1052 EVK Pro ](https://fire-stm32.taobao.com/index.htm)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| RS232         |              |  UART2|
| RS485             |          |  UART5                             |
| RGB                |          |                           |
| MPU6050 |          |    I2C1               |
| AP3216C              |      |         I2C1                              |
| EEPROM               |      |             I2C1                          |
| ****      | **** | ****                              |
| GPIO              |          |  |
| UART              |          |      UART1                       |
| I2C               |          |                              |
| RTC               |          |  |
| WDT               |          |                                       |
| PWM               |      |                              |
| GPT               |      |                              |
| CAN               |      |        CAN1                      |

## Keil IDE 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

 RT1052  FLASH boardMIMXRT105x_QuadSPI_4KB_SEC.FLM  MDK ARMFlash project.uvprojx  MDK5 

![](figures/flash.png)

 CMSIS-DAP  CMSIS-DAP 

#### 

 LED  LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build May 5 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO   1  MPU6050  ENV  BSP 

1.  bsp  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [IMXRTBSP](../docs/IMXRTBSP.md)

## RT-Thread Studio 

### 

*  `RT-Thread Studio`  `RT-Thread Bsp` 

<img src="figures/1.png" style="zoom:80%;" />

*  `imxrt1052-fire-pro` Bsp

<img src="figures/2.png" style="zoom: 67%;" />

* 

<img src="figures/3.png" style="zoom:80%;" />

### 

>  `jlink` 

*  `imxrt1052-fire-pro\board\JLink_Vxxx` 

<img src="figures/4.png" style="zoom:80%;" />

*  `RT-Thread Studio`  `repo\Extract\Debugger_Support_Packages\SEGGER\J-Link\JLink_Vxxx` 

<img src="figures/5.png" style="zoom: 67%;" />

### 

* 

<img src="figures/6.png" style="zoom: 67%;" />

* 

<img src="figures/7.png" style="zoom: 67%;" />

* 

<img src="figures/8.png" style="zoom: 67%;" />

* 

<img src="figures/9.png" style="zoom: 67%;" />

## 



## 

:

- [tyustli](https://github.com/tyustli)