# GD32407V-STARTBSP

## 

GD32407V-START-GD32F4XX168M GD32407V 



![board](figures/board.jpg)

 **** 

- GD32407VKT6 168MHz3072KB FLASH 192KB RAM 

- 
  
  - LED 2LED1 (LED2PC6
  - 2K1K2PA0

- USB 

- GD-LINK

## 

 BSP 

| **** | **** | ****                        |
| :----------- | :----------: | :------------------------------ |
| GPIO         |          | PA0, PA1... ---> PIN: 0, 1...81 |
| UART         |          | UART0 - UART5                   |
| I2C          |          | I2C1                            |
| SPI          |          | SPI0 - SPI2                    |
| SPI FLASH    |          |                                 |
| ADC          |          | ADC0 - ADC2                     |
| **** | **** | ****                        |
|          |      |                         |

## 



- 
  
   RT-Thread  RT-Thread  

- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  MDK4MDK5  IAR  GCC RT-Thread Studio MDK5 

#### 

 PCUSBTTLPA2(MCU TX)PA3(MCU RX)

#### 

 project.uvprojx  MDK5 

>  GD-Link   GD-Link  

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Jan  9 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO  1 ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

## 



## 

:

- [BruceOu](https://github.com/Ouxiaolong/), <ouxiaolong@bruceou.cn>