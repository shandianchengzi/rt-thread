# GD32VF103R_STARTBSP

## 

GD32VF103V_EVAL-GD32VF1108M GD32VF103RB 



![board](figures/board.jpg)

 **** 

- GD32VF103RB  108MHz128KB FLASH 32KB RAM 

- 
  
  - LED 2LED1PA7LED2PA8LED3PA10LED4PC13
  - 2K1K2PA0

- USB 

- GD-Link


## 

 BSP 

| ****  | **** | ****                                |
|:--------- |:--------:|:------------------------------------- |
| GPIO      |        | PA0, PA1... ---> PIN: 0, 1...50 |
| UART      |        | UART0 - UART4                         |
| I2C       |        | I2C1                                  |
| SPI       |        | SPI0 - SPI2                           |
| ADC       |        | ADC0 - ADC1                           |
| ****  | **** | ****                                |
|         |      |                                   |

## 



- 
  
   RT-Thread  RT-Thread  

- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  GCC 

#### 

 PCUSBTTLUSART1

#### 

`scons `GD-Link

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.1.1 build Jun  8 2022 00:49:01
 2006 - 2022 Copyright by RT-Thread team
msh >
```

### 

 BSP  GPIO  1 ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons `

## 



## 

:

- [BruceOu](https://github.com/Ouxiaolong/), <ouxiaolong@bruceou.cn>