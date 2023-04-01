# BSP README 

## 

 MIMXRT1060-EVK  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 



![board](figures/MIMXRT1060EVKB.jpg)

 **** 

- MCUMIMXRT1062DVL6A 600MHz4096KB FLASH 1024KB RAM
-  RAMIS42S16160J-6BLI32MB
-  FLASHS26KS512SDPBHI0264MB
- 
  - LED1D18 
  - 1
- USB SD LCD 
-  JTAG/SWD

NXP [MIMXRT1060-EVK](https://www.nxp.com.cn/design/development-boards/i-mx-evaluation-and-development-boards/i-mx-rt1060-evaluation-kit:MIMXRT1060-EVK)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| SPI Flash         |          |                                       |
|             |          |                                       |
| **** | **** | ****                              |
| GPIO         |          | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART         |          | UART1                                 |
| SPI          |      |                               |
| I2C          |      |                               |
| SDIO         |      |                               |
| RTC          |      |                               |
| PWM          |      |                               |
| USB Device   |      |                               |
| USB Host     |      |                               |
| IWG          |      |                               |
| **** | **** | ****                              |
| LVGL         |          |                                       |

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
 / | \     4.1.0 build Mar 10 2022 18:07:41
 2006 - 2022 Copyright by RT-Thread team
msh >
```
### 

 BSP  GPIO  1  SD Flash  ENV BSP ()

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk/iar` 

 [IMXRT  BSP ](../docs/IMXRTBSP.md)
