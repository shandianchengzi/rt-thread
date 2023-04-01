# GD32303C-STARTBSP

## 

GD32303C-START-GD32F30X120M GD32303C



![board](figures/board.png)

 **** 

- GD32305R 120MHz1024KB FLASH 96KB RAM 

- 
  
  - LED 3LED1 (PB14LED2PB15LED3 (
  - 2K1PA0K2

- USB 

- GD-LINK

## 

 BSP 

| ****  | **** | ****                                |
|:--------- |:--------:|:------------------------------------- |
| GPIO      |        | PA0, PA1... ---> PIN: 0, 1...50 |
| UART      |        | UART1                           |
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
 / | \     5.0.0 build Sep 23 2022 11:24:37
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

- [liYony](https://github.com/liYony), <usthli@163.com>