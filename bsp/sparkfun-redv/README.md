# SparkFun RED-V #

## 1 

[SparkFun RED-V](https://www.sparkfun.com/products/15594)   RISC-V  SoC Freedom E310-002 (FE310)  SiFive  Freedom Everywhere  SoCs  FE310  HiFive1-rev-b 320MHz SiFive 32 RV32IMAC  1.61 DMIPs/MHz Arm Cortex-M4 

![](figures/board.jpg)

### 1.1 

|  |  |
| -- | -- |
|Soc| SiFive Freedom E310 (FE310-G002) |
|     | SiFive E31 RISC-V Core                                      |
|        |  32-bit RV32IMAC                                         |
|        | 320+ MHz                                              |
|  | 1.61 DMIPs/MHz, 2.73 Coremark/MHz            |
|SRAM| 16KB |
|Flash| 32 Mbit Off-Chip (ISSI SPI Flash) |

### 1.2 

- 16KB L1 
- 16KB  SRAM 
- /
- 
- OTP 
-  PLL 
-  UARTQSPIPWM 
- +



## 2 

### 2.2  Freedom Studio

[Freedom Studio](https://www.sifive.com/software)  SiFive  SiFive  RISC-V GCC OpenOCD

 v2019.08.1 

- [FreedomStudio-2019-08-1-lin64](https://static.dev.sifive.com/dev-tools/FreedomStudio/2019.08/FreedomStudio-2019-08-1-lin64.tar.gz)
- [FreedomStudio-2019-08-1-win64](https://static.dev.sifive.com/dev-tools/FreedomStudio/2019.08/FreedomStudio-2019-08-1-win64.zip)
- [FreedomStudio-2019-08-1-mac64](https://static.dev.sifive.com/dev-tools/FreedomStudio/2019.08/FreedomStudio-2019-08-1-mac64.tar.gz)

 Freedom Studio  Windows  `FreedomStudio-2019-08-1-win64\SiFive\Drivers` 

- HiFive1_Driver.exe
- sifive-winusb-utility.exe

### 2.3 

 `SiFive/riscv64-unknown-elf-gcc-8.3.0-2019.08.0/bin/`  Env 

```shell
set RTT_EXEC_PATH=
set path=%path%;
```



```shell
set RTT_EXEC_PATH=C:\FreedomStudio-2019-08-1-win64\SiFive\riscv64-unknown-elf-gcc-8.3.0-2019.08.0\bin
set path=%path%;C:\FreedomStudio-2019-08-1-win64\SiFive\riscv64-unknown-elf-gcc-8.3.0-2019.08.0\bin
```

 `scons --exec-path="GCC"` 

### 2.4  Env  IDE

 Env  cd  FreedomStudio  `FreedomStudio.exe`  IDE

```
cd C:\FreedomStudio-2019-08-1-win64
FreedomStudio.exe
```

### 2.5 

 `File -> Import...` `C/C++`  `Existing Code as Makefile Project`  Next 

![](figures/import_makefile_project.png)

 bsp  `Cross GCC`  Finish 

![](figures/import_makefile_project_bsp.png)

### 2.6 



![build](figures/freedomstudio_compile.png)

 `Build Finished`  `rtthread.elf` 



## 3 

### 3.1  Debug 

 type-c usb  `rtthread.elf`  `Debug As->1 As JLink launch`

 Debugger  `FE310` 

![](figures/debug_Debugger.png)

 Config  'Target Architecture'  'riscv:cv32'  Debug 

![](figures/debug_Config.png)

### 3.2 

115200-N-8-1 RT-Thread 

![](./figures/debug_terminal_msh.png)

 LED  1Hz  Tab  RT-Thread 

```
msh >
RT-Thread shell commands:
give_me_five     - Show the SiFive logo
memcheck         - check memory data
memtrace         - dump memory trace information
clear            - clear the terminal screen
version          - show RT-Thread version information
list_thread      - list thread
list_sem         - list semaphore in system
list_event       - list event in system
list_mutex       - list mutex in system
list_mailbox     - list mail box in system
list_msgqueue    - list message queue in system
list_mempool     - list memory pool in system
list_timer       - list timer in system
list_device      - list device in system
help             - RT-Thread shell help.
ps               - List threads in the system.
free             - Show the memory usage in the system.
```



## 4 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0_RX/TXGPIO 16/17 |



## 5 


- [luhuadong](https://github.com/luhuadong)



## 6 

* [RED-V Schematic](https://cdn.sparkfun.com/assets/d/d/1/e/7/RedFive.pdf)
* [RED-V Development Guide](https://learn.sparkfun.com/tutorials/red-v-development-guide)
* [Getting Started with the SparkFun Red-V](https://www.digikey.dk/da/maker/projects/getting-started-with-the-sparkfun-red-v/a28c5ce7d21a452db4aa3f4b94f345f4)
* [Freedom E310-G002 Datasheet](https://cdn.sparkfun.com/assets/5/b/e/6/2/fe310-g002-ds.pdf)
* [Freedom E310-G002 Manual](https://cdn.sparkfun.com/assets/7/f/0/2/7/fe310-g002-manual-v19p05.pdf)
* [Freedom Studio User Manual](https://static.dev.sifive.com/dev-tools/FreedomStudio/2020.06/freedom-studio-manual-4.7.2-2020-06-0.pdf)
