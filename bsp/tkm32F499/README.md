# TKM32F499

## 

 TKM32F499  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

TKM32F499  TKM32F499  ARM Cortex-M4  240 MHz TKM32F499 



![board](figures/board.jpg)

 **** 

- MCUTKM32F499 240MHz 8MB RAMFPUDMA  42 
- 
  - LED3LD1PD8LD2PB14LD3PB15
  - 5  1 RESET
- TK808080

[TKM32F499](http://hjrkj.com/companyfile/1.html)

*[TKM32F499](http://hjrkj.com/product/13.html)*

## 

 BSP 

| **** | **** | ****     |
| :----------- | :----------: | :----------- |
| GPIO         |          |              |
| UART         |          | UART1UART2 |
| SPI          |      |              |
| I2C          |      |              |
| RTC          |      |              |
| PWM          |      |              |

## 



- 

   RT-Thread  RT-Thread  

- 

   RT-Thread  ENV  BSP 


### 

 BSP  MDK5  MDK5 

#### 

 PC1 PC

#### 

 project.uvprojx  MDK5 

>  bootloader  usb u 
>
> *  PA1  APP   KEIL 
> *     TK499_V2  U  KEIL  bin  U  
>
>  bootloader  PA13  BOOT    Bootloader  TK499  U  Bootloader.bin  bootloader
>
> 
>
> * bootloader 460800 rtthread 
> * https://www.amobbs.com/thread-5748003-1-1.html

#### 

 LD2 

USB  COM  1115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Oct 14 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```

*  bootloader 1460800

### 

 BSP  GPIO  1  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5` 


## 

[NU-LL](https://github.com/NU-LL)
