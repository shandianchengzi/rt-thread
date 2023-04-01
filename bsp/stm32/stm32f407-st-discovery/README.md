# STM32F4DISCOVERY  BSP 

## 

 RT-Thread  STM32F4DISCOVERY  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F4DISCOVERY  ST  ARM Cortex-M4  168Mhz STM32F407 



![board](figures/board.png)

 **** 

- MCUSTM32F407VGT6 168MHz1024KB FLASH 192KB RAM
- 
  - LED4 LEDs LD3orangePD13LD4(greenPD12)LD5 (red,PD14) and LD6 (bluePD15)
  - 2Reset  User
-  ST-LINK/V2SWD	

 ST  [STM32F4DISCOVERY](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-discovery-kits/stm32f4discovery.html)

## 

 BSP 

| **** | **** |               ****                |
| :------------ | :----------: | :-----------------------------------: |
| GPIO         |          | PA0, PA1... PH1 ---> PIN: 0, 1...144 |
| UART         |          |              UART1              |
| SPI          |          |               SPI1               |
| I2C          |          |                I2C                |

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

>  ST-LINK ST-LINK 

#### 

 LED  LD1  LD2  LD5 

 PC , 115200-8-1-N RT-Thread :

```c
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

- [misonyo](https://github.com/misonyo) 