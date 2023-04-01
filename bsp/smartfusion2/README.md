## RT-ThreadMicrosemi SmartFusion2FPGA

### 1. BSP

 RT-Thread  **FPGA M2S010**  [Microsemi](https://www.microsemi.com/)MicrochipSmartFusion2**FPGA** FPGA Fabric  **ARM Cortex-M3  MCU** 166MHz 256KB eNVM64KB eSRAMGPIOUARTI2CSPICANUSB

>  Microsemi FPGA  Actel 2010 Microsemi  Actel2018  Microchip  Microsemi

SmartFusion2 

![Microsemi_Smartfusion2_BD](figures/Microsemi_Smartfusion2_BD.jpg)

### 2. 

 RT-Thread PINSerialFinSHuart0

| ****      | **** |
| :----------------- | :----------: |
| GPIO              |          |
| UART              |          |
| SPI               |       |
| I2C               |       |
| RTC               |      |
| USB        |      |

### 3. scons

`rtconfig.py``SConstruct``SConscript`scons`scons`envarm-gccscons

- `scons`arm-gccBSP
- `scons -c` scons 
- `scons --target=mdk4`Keil MDK4
- `scons --target=mdk5`Keil MDK5
- `scons --dist`BSPRT-ThreadBSP

Kconfigrtconfig.h

### 4. 

#### 4.1 FPGA  

FPGA  SmartDesign  HDL  50M PLL  100M  MCU 

![](figures/top_sd.jpg)

MSS GPIO UARTGPIO_0LED

 FPGA [sf2_fpga_prj.rar](https://wcc-blog.oss-cn-beijing.aliyuncs.com/Libero/RT-Thread/sf2_fpga_prj.rar)

#### 4.2 ARM 

ARM  Keil MDK 5.26  M2S [Microsemi.M2Sxxx.1.0.64.pack](http://www.actel-ip.com/repositories/CMSIS-Pack/Microsemi.M2Sxxx.1.0.64.pack)

[Microsemi.M2Sxxx.1.0.64.pack](https://wcc-blog.oss-cn-beijing.aliyuncs.com/Libero/RT-Thread/Microsemi.M2Sxxx.1.0.64.pack)

 RT-Thread 

![](figures/files.jpg)

### 5. 

 ARM  ARM  FPGA JTAG_SEL  ARM  JLink JTAG  TMSTCKGND  ARM 

![](figures/jlink-ob.jpg)

 Flash 

![](figures/flash.jpg)



![](figures/finished.jpg)

 &  RT-Thread  LOG 

```c
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Jun  2 2020
 2006 - 2020 Copyright by rt-thread team
msh >
```

![](figures/log.jpg)

### 6. 

- FPGA  Libero V11.8.2.4 IDE
- ARM  Keil MDK 5.26SoftConsole IDE  `libcpu` 
-  ARM  JTAG_SEL  
-  SoftConsole  Flash Pro  ARM 
-  FPGA  MSS Libero `bsp\smartfusion2\libraries\sys_config` 

### 7. 

- [ - RT-Thread ](https://www.rt-thread.org/document/site/)
- [Microsemi Libero](https://blog.csdn.net/whik1194/article/details/102901710)

### 8. 

- Github[whik](https://github.com/whik)
- E-Mailwangchao149@foxmail.com
