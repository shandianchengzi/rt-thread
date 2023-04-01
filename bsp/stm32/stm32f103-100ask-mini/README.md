# STM32F103 MiniBSP

## 

STM32F103 MiniBSP()



* 

* BSP

* 

BSPRT-ThreadRT-Thread

## 

STM32F103 MiniARM Cortex-M372MHzSTM32F103C8T6



![board](figures/board.png)

****

* MCU: STM32F103ZET672MHz512KB FLASH64KB RAM
* FLASH: W25Q64SPI8MB
* 
  * 1KEYPA0
  * LED1PA1
* USB
* SWD

[100AK STM32F103 Mini](https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-18944745104.11.be3473e3QHlR8S&id=666802425625)

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
| SPI      |        | SPI1/2                                |

## 



- 
  
   RT-Thread  RT-Thread  

- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

ST-LinkSWDST-LinkPCMiniPCUSB

#### 

 project.uvprojx  MDK5 

>  ST-Link  ST-Link

#### 

 LED  LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.1.1 build May 30 2022 17:15:31
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