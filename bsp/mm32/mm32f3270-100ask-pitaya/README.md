# PitayaLiteBSP

## 

PitayaLiteBSP()



* 

* BSP

* 

BSPRT-ThreadRT-Thread

## 

PitayaLiteARM Cortex-M3120MHzMM32F3277G8P


![board](figures/board.png)

****

* MCU: MM32F3273G8P120MHz512KB FLASH128KB RAM
* 
  * 1KEYPA0
  * LED1PA1
* USB
* DAP

[Pitaya](https://item.taobao.com/item.htm?id=682573965671)

[](http://download.100ask.org/boards/MindMotion/pitaya_lite/index.html)

## 

BSP

|      |      |                                     |
| -------- |:--------:| ------------------------------------- |
| USB   |        | UART1                                 |
| LED    |        | PA1                               |
|      |        | KEY(PA0)                              |
| **** | **** | ****                                |
| GPIO     |        | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART     |        | UART1/2/3                             |

## 



- 
  
   RT-Thread  RT-Thread  

- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

DAPUSBPC

#### 

 project.uvprojx  MDK5 

>  CMSIS-DAP  CMSIS-DAP

#### 

 LED  LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Aug 31 2022 14:22:43
 2006 - 2022 Copyright by RT-Thread team
msh />
```

### 

 BSP  GPIO  1  ADCFlash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

: 

* 100ask-Alen, :<3062056224@qq.com>