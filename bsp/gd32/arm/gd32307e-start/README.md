# GD32307E-STARTBSP

## 

GD3307E-START-GD32F30X120M GD32307VE 



![board](figures/board.jpg)

 **** 

- GD32307VE 120MHz512KB FLASH 96KB RAM 

- 
  
  - LED 2LED1PC6
  - 2K1K2PA0

- USB 

- GD-LINK

## 

 BSP 

| ****  | **** | ****                                |
|:--------- |:--------:|:------------------------------------- |
| GPIO      |        | PA0, PA1...---> PIN: 0, 1...79 |
| UART      |        | UART0 - UART4                         |
| I2C       |        | I2C1                                  |
| SPI       |        | SPI0 - SPI2                      |
| SPI FLASH |        |                                       |
| ADC       |        | ADC0 - ADC1                           |
| ****  | **** | ****                                |
|         |      |                                   |

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
 / | \     4.1.0 build May  3 2022 09:26:08
 2006 - 2022 Copyright by RT-Thread team
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