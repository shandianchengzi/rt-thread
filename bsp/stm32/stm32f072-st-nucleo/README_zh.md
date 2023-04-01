# NUCLEO-F072RB  BSP 

## 

 NUCLEO-F072RB  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

NUCLEO-F072RB  ST  STM32F072RBT6  ARM Cortex-M0  48 MHz STM32F072RBT6 



![board](figures/board.jpg)

NUCLEO-F072RB  **** 

- MCUSTM32F072RBT6 48MHz128KB FLASH 16KB RAM
- 
  - LED3 USB communication (LD1), user LED (LD2), power LED (LD3) 
  - 2 USER and RESET 
- USB Arduino Uno  ST morpho 
-  ST-LINK/V2-1 

[NUCLEO-F072RB](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-f072rb.html)

## 

 BSP 

| ****   | **** |               ****                 |
| :------------ | :----------: | :-----------------------------------: |
| GPIO          |          | PA0, PA1... PH1 ---> PIN: 0, 1...63    |
| UART          |          |              UART2                     |
| LED           |          |              LED2                      |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

 Type-A to Mini-B  PC  LED LD3 (PWR)  LD1 (COM) 

#### 

 project.uvprojx  MDK5 

>  ST-LINK 

#### 

 LED  LD3  LD1  LD2 

USB  COM  2115200-8-1-N RT-Thread :

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build May 30 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO   2  env  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

## 

:

-  [](https://github.com/lhxzui), <iuzxhl@qq.com>