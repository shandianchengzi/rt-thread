# NUCLEO-F412ZG  BSP 

## 

 RT-Thread  NUCLEO-F412ZG  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 NUCLEO-F412ZG  ARM Cortex-M4  100Mhz STM32F411ZG 



![board](figures/board.png)

 **** 

- MCUSTM32F412ZG 100MHz1024KB FLASH 256KB RAM
- 
  - LED3 USB communication (LD1), user LED (LD2), power LED (LD3) 
  - 2 USER and RESET 
- USB  3  COM 
-  ST-LINK/V2-1 

 [NUCLEO-F412ZG ](https://www.st.com/en/evaluation-tools/nucleo-f412zg.html)

## 

 BSP 

| **** | **** |               ****                |
| :------------ | :----------: | :-----------------------------------: |
| GPIO         |          | PA0, PA1... PH1 ---> PIN: 0, 1...63 |
| UART         |          |              UART2,UART3            |
| Onchip Flash |          |                                     |
|  USB Device  |          |                                     |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 Type-A to Micro-B  PC  LED LD3 (PWR)  LD1 (COM) 

#### 

 project.uvprojx  MDK5 

>  ST-LINK 

#### 

 LED  LD3  LD1  LD2 

USB  COM  3115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Oct 20 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO   3  ENV  BSP 

1.  BSP  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32  BSP . md)

## 



## 

:

- [flybreak](https://github.com/guozhanxin) <g1171407708@163.com>