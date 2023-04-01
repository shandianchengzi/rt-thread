# NUCLEO-F413ZH  BSP 

## 

 RT-Thread  NUCLEO-F413ZH  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 NUCLEO-F413ZH  ARM Cortex-M4  100Mhz NUCLEO-F413ZH 



![board](figures/board.png)

 **** 

- MCUSTM32F413ZH 100MHz1536KB FLASH 320KB RAM
- 
  - LED8user LED (JP5)(PB0LD1PB7LD2PB14LD3), USB communication (LD4), over current (LD5), power LED (LD6), USB FAULT (LD7), VBUS (LD8)
  - 2B1USERPC13B2RESET
- USB  3  COM 
-  ST-LINK/V2-1 

 [NUCLEO-F413ZH ](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-f413zh.html)

## 

 BSP 

| **** | **** | ****                              |
| :------------ | :----------: | :-----------------------------------: |
|STLINK TO USART|         |                  UART3                 |

| **** | **** |               ****                |
| :------------ | :----------: | :-----------------------------------: |
| GPIO         |          |                                        |
| UART         |          |              UART2/3                   |
| SPI          |          |              SPI2                      |
| I2C          |          |              I2C1()            |
| TIMER        |          |              TIM11/13/14               |
| PWM          |          |              PWM2_CH4                  |
| ADC          |          |              ADC1_IN5                  |
| RTC          |          |              |
| WDT          |          |                              |
| Onchip Flash |          |             Flash                  |
| USB OTG_FS   |          |         OTGFS as USB device            |
| Onchip Flash |          |             Flash                  |
| USB Device   |          |         OTGFS as USB device            |
| RNG          |          |       Random Number Generator          |
| UDID         |          |     Unique Device Identifier           |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

 Type-A to Micro-B  PC  LED LD6 (PWR)  LD4 (COM) 

#### 

 project.uvprojx  MDK5 

>  ST-LINK  Micro USB 

#### 

JP5LD1LED

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Apr 28 2020
 2006 - 2020 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  UART3  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

- [flybreak](https://github.com/XYX12306) <2669599387@qq.com>