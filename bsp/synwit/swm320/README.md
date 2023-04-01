# SWM320 BSP 

 SYNWITCortex-M4SWM320MCU

---

## 

SWM320 BSP () 

 BSP RT-Thread 

## 

- 
  - 32ARM Cortex-M4 
  - 24
  - 120MHz
  - 
  - NVIC2408
  - SWD
- LDO
  - 2.0V3.6V
- SRAM
  - 128KB
- FLASH
  - 128KB/256KB/512KB
  - ISP
- 
  - UART8FIFO16
  - SPI8FIFOSPISSIMaster/slave
  - I2C710Master/slave
  - CAN2.0A(11Bit)2.0B29Bit
- PWM
  - 1216PWM
  - 
  - 
  - 
  - ADC
- 
  - 632
  - 
  - 
  - 
  - 32
- RTC
  - 
  - 
  - 
  - RTCSleep
- DMA
  - 
- SRAMC
  - 816SRAM
  - 24
- SDRAMC
  - 16BitSDRAM
  - PC133SDRAM
  - 2MB32MBSDRAM
- NORFLC
  - NOR FLASH
  - 816NOR FLASH
  - 24
- SDIO
  - SDIO
- TFT-LCD
  - SYNCLCD
  - 1024*768
  - 16Bit
  - 
- GPIO
  - 100GPIO
  - 2IO
  - 
  - 
  - 
  - 
  - 
  - 
- 
  - 2128SAR ADC
  - 1M SPS
  - 
  - singlescan
  - 
  - FIFO
  - PWM
- BOD
  - 
  - 
- 
  - 20MHz/40MHz1%
  - 32K
  - 232MHz

[](http://www.synwit.cn/support-1/3.html)

## 

 BSP  MDK5  MDK5 

 project.uvprojx  MDK5 

>  Jlink  Jlink  PC 

 RT_Thread [env](https://www.rt-thread.org/page/download.html)console `bsp/synwit/swm320` 

`scons`

rtthread.elfrtthread.bin rtthread.bin 

## 

### 

-  USB B-Type  PC CH340  MDK5  SWM320  pack

  >  USB B-Type 

-  Jlink  PC  Jlink 

 1 `[PC2/PC3]` USB  J11 115200-N-8-1

 [env](https://www.rt-thread.org/page/download.html) rtthread.bin ISP 

** keil **ISP 

### 

 & LEDRT-Threadlogo

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Dec 11 2018
 2006 - 2018 Copyright by rt-thread team
msh />
```
## 

 BSP 

| ****        | ****  | ****                              |
| :----------------- | :----------: | :----------------------------------- |
| GPIO               |          | PA0, PA1... PP23 ---> PIN: 0, 1...100 |
| UART               |          | UART0/1/2/3                           |
| ADC                |          | ADC0/1                                |
| TIM                |          | TIM0/1/2/3/4/5                        |
| I2C                |          |  I2C0/1                            |
| PWM                |          | PWM0/1/2/3/4/5                        |
| RTC                |          | RTC                                   |
| SPI                |          | SPI0/1                                |
| WDT                |          | WDT                                   |
| CRC                |          | CRC                                   |
| SDIO               |          | SDIO                                  |
| SRAM               |          | SRAM                                  |
| NOR FLASH          |          | NOR FLASH                             |
| CAN                |       |                                       |

## 

- [yanmowudi](https://github.com/yanmowudi)
- [](lik@synwit.cn)

## 

* [RT-Thread ](https://www.rt-thread.org/document/site/)

* [SWM320](https://www.synwit.cn/col.jsp?id=155)
