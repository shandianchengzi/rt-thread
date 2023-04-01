# STM32F103 PROBSP

## 

STM32F103 ProBSP()



* 
* BSP

* 

BSPRT-ThreadRT-Thread

## 

STM32F103 ProARM Cortex-M372MHzSTM32F103ZET6



![board](figures/board.png)

****

* MCU: STM32F103ZET672MHz512KB FLASH64KB RAM
* RAM : IS62WV51216BLLSRAM1MB
* FLASH: W25Q64SPI8MB
* 
  * 4KEY1PA0KEY2PG15KEY3PC13KEY4PE3
  * LED1RGBPB0PB1PB5
* USB
* SWD

[100AK STM32F103 PRO](https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-18944745104.44.5ac45a43rRV6kG&id=676044382014)

## 

BSP

|      |      |                                                          |
| ------------ | :----------: | ------------------------------------------------------------ |
| USB    |          | UART1                                                        |
| RGB LED      |          | PB0, TIM3 CH3PB1, TIM3 CH4PB5, TIM3 CH2 |
|        |          | ADC1/2/3 CH10                                                |
| SPI FLASH    |          | W25Q64                                                       |
| EEPROM       |          | i2c1                                                     |
| **** | **** | ****                                                     |
| GPIO         |          | PA0, PA1... PK15 ---> PIN: 0, 1...176                        |
| UART         |          | UART1/2/3                                                    |
| SPI          |          | SPI1/2                                                       |
| ADC          |          | ADC1/2/3                                                     |
| TIM          |          | TIM2/3/4                                                     |
| PWM          |          | TIM3 CH2/3/4                                                 |
| CAN          |          | CAN1                                                         |

## 



- 

   RT-Thread  RT-Thread  

- 

   RT-Thread  ENV  BSP 

### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

ST-LinkSWDST-LinkPC

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