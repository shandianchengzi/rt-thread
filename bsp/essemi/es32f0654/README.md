# ES-PDS-ES32F0654  BSP 
 EastSoftMCUCortex-M0ES32F0654LT

## 1. 

 ES-PDS-ES32F0654  BSP () 
 BSP RT-Thread 

### 1.1  


ES-PDS-ES32F0654  ARM Cortex-M0  48MHz



ES-PDS-ES32F0654-V1.1

![ES32F0654](figures/ES-PDS-ES32F0654-V1.1.jpg)

 **** 

- MCUES32F0654LT 48MHz32KB SRAM256KB FLASH54 GPIOs
- SPI FLASH (MX25L648MB)I2C EEPROM (M24C04512B)
- 
  - 1(PB00)
  - LED2(PC8/PC9)
  - 3K1(PF00)K2PF01)RESET(MRST)
- GPIOUARTSPII2C
- ESLink(EastSoft mini CDC ) SWD 

:

 BSP 

| ****      | **** | ****                             |
| :---------------- | :----------: | :------------------------------------|
| SPI FLASH         |          | SPI0                                 |
| ****      | **** | ****                             |
| GPIO              |          | 54 GPIOs                             |
| UART              |          | UART0/1/2/3                          |
| SPI               |          | SPI0/1                               |
| I2C               |          | I2C0/1                               |
| CAN               |          | CAN0                                 |
| PWM               |          | PWM0/1/2/3                           |
| TIMER             |          | TIMER0/1/2/3                         |
| RTC               |          | RTC                                  |
| PM                |          | Power Management                     |
| ADC               |          | ADC0                                 |

### 1.2  

- BSPUART2TIMER1UART3TIMER2

[](http://www.essemi.com/)

## 2. 

 BSP  MDK5  MDK5 

### 

 ESLink ( CDC ) Jlink  PC Jlink  UART2_TX(PC12)UART2_RX(PD2)GND 

ESlink(mini)

ESLink(mini) + ES-PDS-ES32F0654-V1.1

![ESLinkII](figures/ESLinkII-mini.jpg)

### 

 project.uvprojx  MDK5  JLink  JLink  ESLink "CMSIS-DAP Debugger"

### 

LED

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Jan 28 2019
 2006 - 2018 Copyright by rt-thread team
msh >
```
## 3. 

 BSP  GPIO  uart2  Flash  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

    art-thread

    ![kernel_config](figures/k_conf.jpg)

    

    ![kernel_sample](figures/k_ex.jpg)

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

