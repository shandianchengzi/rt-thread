# MM32F103xx BSP 

 MM32Cortex-M3MM32F103MCU

---

## 1. 

 MM32 MiniBoard BSP()  BSP RT-Thread 

### 1.1  

MM32 MiniBoard MM32MCU



MM32 MiniBoard

![MM32 MiniBoard Rev.D2](figures/MM32%20MiniBoard%20Rev.D2_1.jpg)

MM32 MiniBoard 

- MCUMM32F103RB  ARM 32-bit Cortex-M3 96MHz128KB FLASH 20KB SRAM
- 
  - LED44LEDGPIO
  - 1 1WakeUp
  - SPI Flash W25P808M bit50MHz
  - I2CEEPROMAT24C02256
  - 1ADC
  - 
- Micro-USBRS-232UART
- SWDJ-LinkU-LINK2MM32-LINK

[][https://www.mindmotion.com.cn]

### 1.2  MCU 

MM32F103RB 

|  |  |
| -- | -- |
|| MM32F103RB |
|CPU| ARM Cortex-M3 |
|| 96MHz |
|SRAM| 20KB |
|Flash|  128KB |

## 2. 

 BSP  MDK5  MDK5 

 project.uvprojx  MDK5 

>  Jlink  Jlink  PC 

 RT_Thread [env](https://www.rt-thread.org/page/download.html)console `bsp/mm32f103` 

`scons`

rtthread.elfrtthread.bin rtthread.bin 

## 3. 

### 3.1 

MM32-LINKJlinkPCMicro-USBJlinkUART1_TX(PA9)UART1_RX(PA10)GND

MM32-LINK

MM32-LINK+MiniBoard

![MM32-LINK+MiniBoard Rev.D2](figures/MM32%20MiniBoard%20Rev.D2_2.jpg)

* J-Link  DAP-Link 

### 3.2 

 & 1LEDRT-Threadlogo

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



-[StackRyan](https://github.com/StackRyan) email: yuanjyjyj@outlook.com

## 6. 

- [MM32F103xx ](https://www.mindmotion.com.cn/userfiles/images/MM32F103XiLieWenDang/DS_MM32F103xx_n_V1.09_SC.pdf)

- [MM32F103xx ](https://www.mindmotion.com.cn/userfiles/images/MM32F103XiLieWenDang/UM_MM32F103xx_n_V1.69_SC.pdf)

- [MiniBoardStartKit](https://www.mindmotion.com.cn/download.aspx?cid=2545)

- [keil pack](https://www.mindmotion.com.cn/download.aspx?cid=2546)

- [MM32 ](https://www.mindmotion.com.cn/download.aspx?cid=2547)

