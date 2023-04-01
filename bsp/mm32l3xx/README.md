# MM32 MiniBoard Rev.D2 BSP 

 MM32Cortex-M3MM32L373PFMCU

---

## 1. 

AEMM32 MiniBoardBSP()  BSP RT-Thread 

### 1.1  

MM32 MiniBoard Rev.D2 MM32MCU



MM32 MiniBoard Rev.D2 

![MM32 MiniBoard Rev.D2](figures/MM32%20MiniBoard%20Rev.D2_1.jpg)

MM32 MiniBoard Rev.D2 

- MCUMM32L373PF  ARM 32-bit Cortex-M3 96MHz128KB FLASH 20KB SRAM
- 
  - LED44LEDGPIO
  - 1 1WakeUp
  - SPI Flash W25P808M bit50MHz
  - I2CEEPROMAT24C02256
  - 1ADC
  - 
- Micro-USBRS-232UART
- SWDJ-LinkU-LINK2MM32-LINK

[][http://www.mm32.com.cn]

### 1.2  MCU 

MM32L373PF 

|  |  |
| -- | -- |
|| MM32L373PF |
|CPU| ARM Cortex-M3 |
|| 96MHz |
|SRAM| 20KB |
|Flash|  128KB |

## 2. 

 BSP  MDK5  MDK5 

 project.uvprojx  MDK5 

>  Jlink  Jlink  PC 

 RT_Thread [env](https://www.rt-thread.org/page/download.html)console `bsp/mm32l37x` 

`scons`

rtthread.elfrtthread.bin rtthread.bin 

## 3. 

### 3.1 

MM32-LINKJlinkPCMicro-USBJlinkUART1_TX(PA9)UART1_RX(PA10)GND

MM32-LINK

MM32-LINK+MiniBoard Rev.D2

![MM32-LINK+MiniBoard Rev.D2](figures/MM32%20MiniBoard%20Rev.D2_2.jpg)

### 3.2 

 & 4LEDRT-Threadlogo

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Dec 11 2018
 2006 - 2018 Copyright by rt-thread team
msh />
```

## 4. 

|        |  |                          |
| ---------- | :------: | :--------------------------: |
| UART       |      | UART1/2                   |
| GPIO       |      | / |

## 5. 



-[Henryhuang](https://github.com/huangzushui) email: huangzushui@mindmotion.com.cn

## 6. 

- [MM32L3xx_n](http://www.mm32.com.cn/getfile.aspx?id=1062)

- [MM32L3xx_n](http://www.mm32.com.cn/getfile.aspx?id=578)

- [MiniBoardStartKit](http://www.mm32.com.cn/download.aspx?cid=2545)

- [keil pack](http://www.mm32.com.cn/download.aspx?cid=2546)

- [MM32 ](http://www.mm32.com.cn/download.aspx?cid=2547)
