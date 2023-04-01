# STM32F723E-disco  BSP 

## 

 STM32F723E-disco  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F723E-disco  ST  ARM Cortex-M7  216Mhz STM32F723 



![board](figures/board.png)

 **** 

- MCUSTM32f723 216MHz512MB FLASH 256KB RAM
- 
  - 2Reset  User
- ST-LINK/V2-1

 [STM32F723E-disco ](https://www.st.com/en/evaluation-tools/32f723ediscovery.html)

 [STM32f723 ](https://www.st.com/zh/microcontrollers-microprocessors/stm32f723ie.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB    |          |              UART6                  |


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

LED 

 PC 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Mar  1 2023 16:20:11
 2006 - 2022 Copyright by RT-Thread team
msh >
```

### 

 BSP  GPIO  6  ENV  BSP 

1.  bsp  env 

2.  `menuconfig` 

3.  `pkgs --update` 

4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:
- [Rbb666](https://github.com/Rbb666)
