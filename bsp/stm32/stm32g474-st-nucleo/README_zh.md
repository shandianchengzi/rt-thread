# NUCLEO-G474RE  BSP 

## 

 NUCLEO-G474RE  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

NUCLEO-G474RE  ST  STM32G4  Cortex-M4 Nucleo-64 



![board](figures/board.jpg)

 **** 

- MCUSTM32G431RB 170MHz128KB FLASH 32KB RAM
- 
  - LED1LD2PA5
- USB 
-  ST-LINK/SWD

NUCLEO-G474RE [](https://www.st.com/zh/evaluation-tools/nucleo-g474re.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |                                       |
| ****      | **** | ****                              |
| GPIO              |          |                                       |
| UART              |          | LPUART1 USART1/3 UART4                |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC,,

#### 

 project.uvprojx  MDK5 

>  ST-LINK  ST-LINK 

#### 

 LD2  500MS 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Oct  5 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  LPUART1  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  LPUART1

## 

:

-   [mazhiyuan](https://github.com/cndabai), <mazhiyuan@rt-thread.com>