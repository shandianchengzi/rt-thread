# NUCLEO-L496ZG  BSP 

## 

 ST  (144)NUCLEO-L496ZG  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

NUCLEO-L496ZG  ST  STM32L4  Cortex-M4 Nucleo-144  mbed ArduinoST Zio ST Morpho 



![board](figures/board.png)

 **** 

- MCUSTM32L496ZG 80MHz1MB FLASH 320KB RAM
- 
  - LED3LED1 (PB0),LED2PB7LED3PB14
  - 1K1PC13
- USB OTG 
-  ST-LINK/SWD

 [L496ZG](https://www.st.com/content/st_com/zh/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-l496zg.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| ****      | **** | ****                              |
| GPIO              |          |                                        |
| UART              |          | LPUART1                                |

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

>  ST-LINK   ST-LINK 

#### 

 LED2  500MS 

ST-LINK PC , , 115200-8-1-N,  RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Oct  2 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  LPUART1  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)



5. USBD CDC[STM32L496 USB CDC](https://club.rt-thread.org/ask/article/2959.html)

## 

-  RT-Thread  PC  BSP  GPIO 

## 

:

-  [super_mcu] <super_mcu@qq.com>