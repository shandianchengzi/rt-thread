# ch32v307v-r1 BSP 

[English](README.md) | ****

## 1 

CH32V307V-R1  WCH  RISC-V  144Mhz RISC-V 

![board](./figures/ch32v307.jpg)

****

- MCUCH32V307VCT6 144MHzFLASH  RAM 
- LED2  LEDsLED1blueLED2blue
- 2 ResetUser 
- USB2 Tpye-C
- 1  10M PHY
-  WCH-Link 

[ RISC-V  CH32V307](https://www.wch.cn/products/CH32V307.html)  [](https://github.com/openwch/ch32v307)

## 2 

 RISC-V GCC 

| IDE/ |            |
| ---------- | -------------------- |
| GCC        | WCH RISC-V GCC 8.2.0 |

## 3 

>  RT-Thread  RT-Thread  

### 3.1  Env  BSP

 Env  BSP 

#### 3.1.1  BSP

1. [ WCH ](https://github.com/NanjingQinheng/sdk-toolchain-RISC-V-GCC-WCH/archive/refs/tags/V1.0.0.zip)
2.  Env [](https://github.com/RT-Thread/env-windows/releases)
3.  RT-Thread[](https://github.com/RT-Thread/rt-thread/archive/refs/heads/master.zip)
4.  BSP  Env  `scons --exec-path=D:\sdk-toolchain-RISC-V-GCC-WCH-1.0.0\bin` 
5.  **rtthread.bin** 

![sconscompile](./figures/sconscompile.jpg)

#### 3.1.2 

 wch-link  PC

#### 3.1.3 

 WCH RISC-V MCU ProgrammerTool  **rtthread.bin** 

![tool](./figures/tool.png)

>  Chip Mem  224K ROM + 96K RAM

#### 3.1.4 

 wch-link WCHDapLink SERIAL 115200-8-1-N RT-Thread 

![end](./figures/end.png)

#### 3.1.5 

 WCH RISC-V MCU ProgrammerTool  WCH-LinkUtility.[](https://club.rt-thread.org/ask/article/44e5b4bc129ff373.html)

### 3.2  VSCode 

 Env  `scons --target=vsc`  VSCode .  `code .`  VSCode.

 **VSCode **  `scons -j12 --exec-path=D:\sdk-toolchain-RISC-V-GCC-WCH-1.0.0\bin` 

![vscode-terminal](./figures/vscode-terminal.png)

### 3.3  RT-Thread Studio 

#### 3.3.1 

 RT-Thread Studio ->

![import](./figures/import.png)

RT-Thread Bsp 

![windows](./figures/windows.png)

Bsp  `\rt-thread\bsp\wch\risc-v\ch32v307v-r1` 

![config](./figures/config.png)

#### 3.3.2 



![set](./figures/set.png)

 Toolchain path 

![toolchain](./figures/toolchain.png)

 Prefix 

![prefix](./figures/prefix.png)



![toolset](./figures/toolset.png)

#### 3.3.3 



![success](./figures/success.png)
