# STM32H750-armfly-h7-tool  BSP 

## 

 zylx  STM32H750-armfly-h7-tool  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32H750  ARM Cortex-M7  400Mhz STM32H750 



![board](figures/board.jpg)

 **** 

- MCUSTM32H750 400MHz2MB FLASH 1MB RAM
- USB DAC
-  SWD

[ H7-TOOL ](http://armbbs.cn/forum.php?mod=viewthread&tid=89934&extra=page%3D2%26filter%3Dauthor%26orderby%3Ddateline)

## 

 BSP 

| **** | **** | **** |
| :----------- | :----------: | :------- |
| LCD          |        |          |
| ESP32        |          | AT   |
| **** | **** | **** |
| GPIO         |          |          |
| UART         |          | UART1    |
| USB Device   |          | USB HS   |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC TVCC  3.3V usb  TTLRX  TTLTX

#### 

 project.uvprojx  MDK5 

>  ST_LINK  ST_LINK 

#### 

LED

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Oct 25 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 1 

    PA10     ------> USART1_RX

    PA9     ------> USART1_TX 

## 

:

-  [zylx](https://github.com/qgyhd1234 )