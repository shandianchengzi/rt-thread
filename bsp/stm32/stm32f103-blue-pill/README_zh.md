# STM32F103C8T6(BluePill) BSP 

[[English]](README.md)

## 

 STM32F103C8T6(BluePill)  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 



## 

STM32F103C8T6SWD3RTCSTM32



![board](figures/Bluepill_pinout.png)

 **** 

- MCUSTM32F103C8T6 72MHz64KB FLASH 20KB RAM
-  RAM
-  FLASH
- 
  - LED1 PC13
- 
- SWD



## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------- | :------------------------------------- |
| 	LED		    |           |       PC13                          |
| ****      | **** | ****                              |
| GPIO              |              |          |
| UART              |          | UART1                                |



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

>  J-Link  J-Link 

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Mar 10 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  ADCSPI ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)



## 

- USBTTLPC ;



##  & 

- [obito0](https://github.com/obito0)[](../stm32f103-mini-system)
- [Meco Man](https://github.com/mysterywolf): jiantingman@foxmail.com