# GD32VF103 #

## 

gd32vf103v-eval  RISC-V 

### 

|  |  |
| -- | -- |
|     | Bumblebee                                     |
|        |  32-bit RV32IMAC                                         |
|        | 108 MHz                                              |

## 

### 
 Eclipse 

![](figures/open_eclipse.png)

 Eclipse  RT-Thread 

![](figures/file.png)



![](figures/exist.png)



![](figures/finish_port.png)


### 
 Build Tools Path

![build_path](figures/build_path.png)

 MCU  Build Tools Path  SDK 

 OpenOCD Path

![open_ocd](figures/open_ocd.png)

 MCU  OpenOCD Path  SDK 

 RISC-V Toolchains Path

![risc-v](figures/risc-v-tool.png)

 MCU  RISC-V Toolchains Paths  SDK 



![build](figures/build_project.png)

## 

### 

1.   JLink_Windows_V622c.exe () JLink 
2.   Zadig.exe Options->List All Devices
3.   1  J-Link2  WinUSB  3  Replace Driver 

![zadig](figures/zadig.png)



![close](figures/close.png)

###  GDB 

 Run->Debug Configurations Debug 

![open_debug](figures/open_debug.png)

 OpenOCD  GDB ServerGCC GDB  GDB Client GDB OpenOCD Debugging OpenOCD 

Main 

Main 

![main_select](figures/main_select.png)

 GD32VF103GD32VF103xB\GD32VF103xB.elf

Debugger 
 Debugger 

![debug_select](figures/debug_select.png)

 Debugger 
Config options  OpenOCD  cfg 


### 

(115200-N-8-1) RT-Thread 

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Jul 24 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```

## 

|  |   |    |
| ------ | ----  | :------:  |
| USART |  | UART0_TX/RXGPIO 9/10 |

## 5. 


- [tyustli](https://github.com/tyustli)

