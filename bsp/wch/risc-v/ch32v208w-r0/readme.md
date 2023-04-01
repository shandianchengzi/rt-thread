# CH32V208W-R0 BSP 

****

## 1 

CH32V208W-R0  WCH  RISC-V  144Mhz RISC-V 

![board](./figures/ch32v208.png)

****

- MCUCH32V208WBU6 144MHzFLASHRAM
- LED2
- 3 Download  ,Reset User 
- USB2Tpye-C
- 1 10M PHY
-  WCH-Link 

## 2 

 RISC-V GCC 

| IDE/ |            |
| ---------- | -------------------- |
| GCC        | WCH RISC-V GCC 8.2.0 |

## 3 

> RT-Thread  RT-Thread  

### 3.1 EnvBSP

EnvBSP

#### 3.1.1 BSP

1. [WCH](https://github.com/NanjingQinheng/sdk-toolchain-RISC-V-GCC-WCH/archive/refs/tags/V1.0.0.zip)
2. Env[](https://github.com/RT-Thread/env-windows/releases)
3. RT-Thread[](https://github.com/RT-Thread/rt-thread/archive/refs/heads/master.zip)
4. BSPEnv `scons --exec-path=D:\sdk-toolchain-RISC-V-GCC-WCH-1.0.0\bin` 
5.  **rtthread.bin** 

![sconscompile](./figures/sconscompile.jpg)

#### 3.1.2 

 wch-link  PC

#### 3.1.3 

 WCH RISC-V MCU ProgrammerTool  **rtthread.bin**  

![tool](./figures/tool.png)

#### 3.1.4 

 wch-link WCHDapLink SERIAL115200-8-1-N RT-Thread 

![end](./figures/end.png)

### 3.2 VSCode

Env `scons --target=vsc` VSCode.  `code .` VSCode.

 **VSCode **  `scons -j12 --exec-path=D:\sdk-toolchain-RISC-V-GCC-WCH-1.0.0bin` 

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
