# STM32F469-ST-DISCO  BSP 

## 

 STM32F469-ST-DISCO  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F469-ST-DISCO  ST  ARM Cortex-M4  180Mhz STM32F469 



![board](figures/board.png)

 **** 

- MCUSTM32F469NIH6U 180MHz2048KB FLASH 384KB (64KB  CCM) RAM
-  RAM25Q128A16MB
-  FLASH7LL12D9NOR16MB
- 
  - LED4LD1PG6LD2PD4LD3PD5LD4PK3
  - 1USERPA0
  - LCD4800480TFT
  - SAIDAC
- Arduino UNO V3 MicroSD LCD I2C 
-  ST-LINK/V2-1 SWD 

 ST  [STM32F469-ST-DISCO ](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-discovery-kits/32f469idiscovery.html)

## 

 BSP 

| **** | **** | **** |
| :-----: | :-----: | :-----: |
| SDRAM  |  | 16MB |
| LCD |  | MIPIotm8009a |
| SDCARD |  | 200ms |
| TOUCH |  | ft6206 |
| **** | **** | **** |
| GPIO  |  |  |
| USART |  | USART3 |
| SPI |  | SPI3 |
| QSPI |  |  |
| I2C |  | I2C |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| SDIO |  |  |
| USB Device |  |  |
| **** | **** | **** |
|  |  |  |

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

>  st-link  st-link 

#### 

LED (LD1) 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Apr  9 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  3  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- STM32F469NIH6U RAM 384KB 384KB  64KB  CCM data RAM `board.h`  384KB  (384 - 64)KB  320KB 
-  STM32CubeMX  USART3  PB10  PB11

## 

:

-  [WillianChan](https://github.com/willianchanlovegithub)

