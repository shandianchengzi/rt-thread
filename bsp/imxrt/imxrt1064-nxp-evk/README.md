# BSP README 

## 

 MIMXRT1064-EVK  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 



![board](figures/MIMXRT1064EVK-TOP.jpg)

 **** 

- MCUMIMXRT1064DVL6A 600MHz4096KB FLASH 1024KB RAM
-  RAMIS42S16160J-6BLI32MB
-  FLASHS26KS512SDPBHI0264MB
- 
  - LED1D18 
  - 1
- USB SD LCD 
-  JTAG/SWD

NXP [MIMXRT1064-EVK](https://www.nxp.com/support/developer-resources/evaluation-and-development-boards/i.mx-evaluation-and-development-boards/mimxrt1064-evk-i.mx-rt1064-evaluation-kit:MIMXRT1064-EVK)

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
| UART              |          | UART1                                 |
| SPI               |        |                               |
| I2C               |      |                                |
| SDIO              |      |                               |
| RTC               |      |                               |
| PWM               |      |                               |
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

 BSP  MDK4MDK5  IAR GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

>  CMSIS-DAP  USB 

#### 

LED1Hz

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Jul  5 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  SD Flash  ENV BSP ()

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk/iar` 

 [IMXRT  BSP ](../docs/IMXRTBSP.md)


## 

:

-  [](https://github.com/xfwangqiang, https://gitee.com/xfwangqiang), <164877907@qq.com>