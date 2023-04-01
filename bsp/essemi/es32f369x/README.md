# ES-PDS-ES32F369x  BSP 
 EastSoftMCUCortex-M3ES32F3696LT

## 1. 

 ES-PDS-ES32F369x  BSP () 
 BSP RT-Thread 

### 1.1  


ES-PDS-ES32F369x  ARM Cortex-M3  96MHz



ES-PDS-ES32F369x-V1.3

![ES32F0654](figures/ES-PDS-ES32F369x-V1.3.jpg)

 **** 

- MCUES32F3696LT 96MHz96KB SRAM512KB FLASH50 GPIOs
- SPI FLASH (MX25L648MB)I2C EEPROM (M24C04512B)
- 
  - 1(PA05)
  - LED2(PF00/PF01)
  - 6PB02PB12PC10PC11PC12RESET(MRST)
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

### 

 ESLink ( CDC ) Jlink  PC Jlink  UART0_TX(PB10)UART0_RX(PB11)GND 

ESlink(mini)

ESLink(mini) + ES-PDS-ES32F369x-V1.3

![ESLinkII](figures/ESLinkII-mini.jpg)

### 

 project.uvprojx  MDK5  JLink  JLink  ESLink "CMSIS-DAP Debugger"

### 

LED
```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Jan 23 2020
 2006 - 2019 Copyright by rt-thread team
msh>
```
## 3. 

 BSP  GPIO  uart0  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

    art-thread

    ![kernel_config](figures/k_conf.jpg)

    

    ![kernel_samples](figures/k_ex.jpg)

    b

    ![driver_config](figures/d_conf.jpg)

    

    ![driver_sample](figures/d_ex.jpg)

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 Env  [RT-Thread ](https://www.rt-thread.org/document/site/)

## 4. 

- [liuhongyan](https://gitee.com/liuhongyan98) 

## 5. 

- [ EastSoft ](http://www.essemi.com)

