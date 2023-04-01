# ES-PDS-ES32F365x  BSP 
 EastSoftMCUCortex-M3ES32F365x 

## 1. 

 ES-PDS-ES32F365x  BSP () 
 BSP RT-Thread 

### 1.1  


ES-PDS-ES32F365x  ARM Cortex-M3  96MHz



 **** 

- MCUES32F3656LT 96MHz64KB SRAM512KB FLASH50 GPIOs
- SPI FLASH (MX25L648MB)I2C EEPROM (M24C04512B)
- GPIOUARTSPII2CCAN
- ESLink(EastSoft mini CDC ) SWD 

:

 BSP 

| **** | **** | ****        |
| :----------- | :----------: | :-------------- |
| SPI FLASH    |          | SPI0            |
| **** | **** | ****        |
| GPIO         |          | 50 GPIOs        |
| UART         |          | UART0/1/2/3/4/5 |
| SPI          |          | SPI0/1/2        |
| I2C          |          | I2C0/1          |
| CAN          |          | CAN0            |
| PWM          |          | PWM0/1          |
| TIMER        |          | TIMER0/1        |
| RTC          |          | RTC             |
| ADC          |          | ADC0            |

### 1.2  

[](http://www.essemi.com/)

## 2. 

 BSP  MDK5  MDK5 

****es32f365xbsp  es32f369xbsp es32f369xbspes32f36xx

           es32f365xes32f369xSRAMUSB

### 

 project.uvprojx  MDK5  JLink  JLink  ESLink "CMSIS-DAP Debugger"

### 

LED
```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Oct 11 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```
## 3. 

 BSP  GPIO  uart0  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

    art-thread

    ![kernel_config](../es32f369x/figures/k_conf.jpg)

    

    ![kernel_samples](../es32f369x/figures/k_ex.jpg)

    b

    ![driver_config](../es32f369x/figures/d_conf.jpg)

    

    ![d_ex](../es32f369x/figures/d_ex.jpg)

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 Env  [RT-Thread ](https://www.rt-thread.org/document/site/)

## 4. 

- [liuhongyan](https://gitee.com/liuhongyan98) 

## 5. 

- [ EastSoft ](http://www.essemi.com)

