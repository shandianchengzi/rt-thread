# STM32F411-Nucleo-64  BSP 

## 

 RT-Thread  STM32F411-Nucleo-64  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 STM32F411-Nucleo-64  ARM Cortex-M4  100Mhz STM32F411RE 



![board](figures/board.png)

 **  ** 

- MCUSTM32F411RET6 100MHz512KB FLASH 128KB RAM
- 
  - LED3 USB communication (LD1), user LED (LD2), power LED (LD3) 
  - 2 USER and RESET 
- USB  3  COM 
-  ST-LINK/V2-1 

 [STM32F411-Nucleo-64 ](https://www.st.com/en/evaluation-tools/nucleo-f411re.html)

## 

 BSP 

| **** | **** |               ****                |
| :------------ | :----------: | :-----------------------------------: |
| GPIO         |          | PA0, PA1... PH1 ---> PIN: 0, 1...63 |
| UART         |          |              UART2             |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 Type-A to Mini-B  PC  LED LD3 (PWR)  LD1 (COM) 

#### 

 project.uvprojx  MDK5 

>  ST-LINK 

#### 

 LED  LD3  LD1  LD2 

USB  COM  2115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO   2  ENV  BSP 

1.  BSP  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32  BSP . md)

## 



## 

:

- [misonyo](https://github.com/misonyo) <misonyo@foxmail.com>