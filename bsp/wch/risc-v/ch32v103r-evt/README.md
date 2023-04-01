# ch32v103r-evt BSP 
## 

ch32v103r-evt  CH32V103 MCU  WCH-Link  RISC-V 



<img src="figures/2022-03-27_182300.bmp" alt="2022-03-27_182300" style="zoom:50%;" />



-  V3A  80MHz 
- 
- 20KB SRAM64KB CodeFlash
- 2.7V ~ 5.5VGPIO
- //
- /POR/PDR
- PVD
- 7 DMA 
- 16 TouchKey 
- 1612 ADC 
- 7
- 1 USB2.0 /
- 2 IIC  SMBus/PMBus
- 3 USART 
- 2 SPI  Master  Slave 
- 51 I/O  I/O 16
- CRC 96 ID
- SWD
- LQFP64MLQFP48QFN48

 [WCH CHV103](http://www.wch.cn/products/CH32V103.html?)

## 

 RISC-V GCC 

| IDE/ |            |
| ---------- | -------------------- |
| GCC        | WCH RISC-V GCC 8.2.0 |


## 

 BSP 

|       |  |                        |
| --------- | -------- | :------------------------:|
| UART      |      | USART 1       |
| GPIO      |      | PA0...PE15                  |


### IO

| IO |  |
| ---- | -------------- |
| PA9(wch-link)  | USART1_TX      |
| PA10(wch-link) | USART1_RX      |



## 

     RT-Thread  RT-Thread  

### 

 BSP  SCons

#### SCons 

 RISC-V GCC  RT_Studio 

```
import os
ARCH     = 'risc-v'
CPU      = 'ch32v1'
# toolchains options
CROSS_TOOL  = 'gcc'

#------- toolchains path -------------------------------------------------------
if os.getenv('RTT_CC'):
    CROSS_TOOL = os.getenv('RTT_CC')

if  CROSS_TOOL == 'gcc':
    PLATFORM    = 'gcc'
    EXEC_PATH   = r'D:/Softwares/RT_ThreadStudio/repo/Extract/ToolChain_Support_Packages/WCH/RISC-V-GCC-WCH/8.2.0/bin'
else:
    print('Please make sure your toolchains is GNU GCC!')
    exit(0)

# if os.getenv('RTT_EXEC_PATH'):
    # EXEC_PATH = os.getenv('RTT_EXEC_PATH')

```

 scons 

```
LT@DESKTOP-WIN10 E:\WorkSpaces\rt-thread\bsp\wch\risc-v\ch32v103r-evt                             
>scons                                                                                           
scons: Reading SConscript files ...                                                               
Newlib version:3.0.0                                                                              
scons: done reading SConscript files.                                                             
scons: Building targets ...                                                                       
scons: building associated VariantDir targets: build                                              
CC build\applications\main.o                                                                      
CC build\board\board.o                                                                            
CC build\board\ch32v10x_it.o                                                                      
....                            
CC build\libraries\ch32_library\StdPeriph_Driver\src\ch32v10x_misc.o                              
CC build\libraries\ch32_library\StdPeriph_Driver\src\ch32v10x_pwr.o                               
CC build\libraries\ch32_library\StdPeriph_Driver\src\ch32v10x_rcc.o                               
CC build\libraries\ch32_library\StdPeriph_Driver\src\ch32v10x_rtc.o                               
CC build\libraries\ch32_library\StdPeriph_Driver\src\ch32v10x_spi.o                               
CC build\libraries\ch32_library\StdPeriph_Driver\src\ch32v10x_tim.o                               
CC build\libraries\ch32_library\StdPeriph_Driver\src\ch32v10x_usart.o                             
CC build\libraries\ch32_library\StdPeriph_Driver\src\ch32v10x_wwdg.o                              
LINK rtthread.elf                                                                                 
riscv-none-embed-objcopy -O binary rtthread.elf rtthread.bin                                      
riscv-none-embed-size rtthread.elf                                                                
text    data     bss     dec     hex filename                                                  
63540     392    8080   72012   1194c rtthread.elf                                              
scons: done building targets.                                                                     
```

#### 

 wch-link  PC

#### 

WCH_RISC-V_Programmerbsp`rtthread.bin` ,

![image-20220404205018822](figures/image-20220404205018822.png)

>  WCH_RISC-V_Programmer  MRS IDE

#### 


 wch-link WCHDapLink SERIAL115200-8-1-N RT-Thread :

```bash

 \ | /
- RT -     Thread Operating System
 / | \     4.1.0 build Apr  4 2022 16:57:50
 2006 - 2022 Copyright by RT-Thread team

 MCU: CH32V103C8T6
 SysClk: 72000000Hz
 www.wch.cn
msh >ps
thread   pri  status      sp     stack size max used left tick  error
-------- ---  ------- ---------- ----------  ------  ---------- ---
tshell    20  running 0x00000140 0x00000400    83%   0x00000003 000
tidle0    31  ready   0x000000b0 0x00000100    70%   0x00000002 000
timer      4  suspend 0x000000e0 0x00000200    43%   0x00000009 000
main      10  suspend 0x00000140 0x00000800    20%   0x0000000f 000
```

## 

:

- [blta](https://github.com/blta)
