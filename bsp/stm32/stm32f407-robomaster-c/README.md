# STM32F407 Robomaster C BSP 

## 

 STM32F407 Robomaster C  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

Robomaster C  ARM Cortex-M4  STM32F407IGH6TR 168MhzIMURoboMasterM3508 M2006UWBDJISDK



<img src="figures/board.png" alt="image-20210630111114846" style="zoom:50%;" />

>  C 

 **** 

- MCUSTM32F407IGH6TR,  168MHz, 1024KB FLASH, 192KB RAM(64KB CCM RAM)
- 
  -  LEDLED_R(PH12), LED_G(PH11), LED_B(PH11), 
  - KEY(PA0)
  - ADC_BAT(PF10)
- UART CAN PWM 
- SWD


[RoboMaster  C .pdf](https://rm-static.djicdn.com/tem/35228/RoboMaster%20%20%E5%BC%80%E5%8F%91%E6%9D%BF%20C%20%E5%9E%8B%E7%94%A8%E6%88%B7%E6%89%8B%E5%86%8C.pdf)

 RoboMaster[RoboMaster C ](https://www.robomaster.com/zh-CN/products/components/general/development-board-type-c/info) 

## 

 BSP 

| **** | **** | ****                             |
| :----------- | :----------: | :----------------------------------- |
| BMI088       |      |             |
| IST8310      |      |                            |
| **** | **** | ****                             |
| GPIO         |          | PA0, PA1... PH1 ---> PIN: 0, 1...144 |
| UART         |          | UART1(FinSH),  UART3(DBUS),  UART6          |
| CAN          |         | CAN1, CAN2                           |
| PWM          |      | TIM1(CH1/2/3/4), TIM4(CH3), TIM5(CH1/2/3), TIM8(CH1/2/3) |
| SPI          |      | SPI2 |
| IIC          |      | IIC(SDA-->PF0, SCL-->PF1) |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread [ENV ](https://docs.rt-thread.org/#/development-tools/env/env) BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 ST-Link/JLink/DapLink  MX1.25 4PinC 3.3V micro USB XT30  

#### 

 project.uvprojx  MDK5 

>  ST-LINK 

#### 

 LED LED 

 BSP  FinSH  1 ( C  UART2  4Pin )115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.1.1 build Jul 29 2022 23:31:38
 2006 - 2022 Copyright by RT-Thread team
msh >
```
>  [MobaXterm](https://mobaxterm.mobatek.net/)  [Xshell](https://www.netsarang.com/en/free-for-home-school/)

### 

 BSP  GPIO  UART1( UART2 4pin )  ENV  BSP 

1.  BSP  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32  BSP . md)

## 

-  XT30  USB  CAN5VIMU
-  scons  cmake  CLion  C [ Clion  rt-thread ](https://club.rt-thread.org/ask/article/2840.html)C openOCD  `stm32f4discovery.cfg`  `reset_config none`

## 

:

- [crazt](https://github.com/CraztTnspt) <crazt@foxmail.com>
- [Meng](https://github.com/Meng2025) <m@njust.edu.cn>

