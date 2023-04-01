# HIFIVE1 #

## 

[HIFIVE1](https://www.sifive.com/products/hifive1/)  SiFive  RISC-V  SoC Freedom E310 

![1538284005769](figures/board.png)



### 

|  |  |
| -- | -- |
|Soc| SiFive Freedom E310 (FE310) |
|     | SiFive E31 RISC-V Core                                      |
|        |  32-bit RV32IMAC                                         |
|        | 320+ MHz                                              |
|  | 1.61 DMIPs/MHz, 2.73 Coremark/MHz            |
|SRAM| 16KB |
|Flash| 16MB QSPI + 16KB Cache |

## 

###  Freedom Studio

Freedom Studio  SiFive  SiFive  RISC-V GCC OpenOCD

[](https://www.sifive.com/products/tools/)

![1538295358180](figures/dowmload.png)

 rt-thread 

![1538295750998](figures/untar.png)

### 

 IDE  `F:\FreedomStudio\SiFive\riscv64-unknown-elf-gcc-20171231-x86_64-w64-mingw32\bin` 

  `rt-thread/bsp/hifive1/`  env  gcc 

```
set RTT_EXEC_PATH=F:\FreedomStudio\SiFive\riscv64-unknown-elf-gcc-20171231-x86_64-w64-mingw32\bin
```

`scons --exec-path="GCC"`

### 

 ******** 

```
set path=%path%;;;
```



```
set path=%path%;F:\FreedomStudio\SiFive\riscv64-unknown-elf-gcc-20171231-x86_64-w64-mingw32\bin;F:\FreedomStudio\build-tools\bin
```

![1538296570129](figures/env.png)

###  env  IDE

 cd  IDE 

![1538296766437](figures/cd.png)

 Freedom Studio  Tab   IDE

![1538296878924](figures/open_ide.png)

 workspace  IDE

![1538296978929](figures/ide.png)

### 

 `File->Import` 

![1538297215062](figures/import.png)



![1538297303505](figures/import2.png)

![1538297553367](figures/import3.png)



### 

![1538297679868](figures/build.png)



![1538297922206](figures/builded.png)




## 

### 

1.  Micro USB 

2.  IDE  `F:\FreedomStudio\SiFive\Drivers` 

### 

 `Window->preferences`    `cross_prefix`  `riscv64-unknown-elf-`

![1538298633528](figures/string.png)

###  Debug 

 `rtthread.elf` , Debug 

![1538298914673](figures/debug.png)

 Debug 

![1538299063801](figures/debug1.png)

 `Debugger`  

```
-f openocd.cfg

set mem inaccessible-by-default off
set arch riscv:rv32
set remotetimeout 250
```



![1538299273874](figures/debug2.png)

 `startup` ********

![1538299521246](figures/debug3.png)

 main 

![1538299736730](figures/run.png)

### 

(115200-N-8-1)RT-Thread

```
 \ | /
- RT -     Thread Operating System
 / | \     3.0.4 build May 30 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```

## 4. 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0_RX/TXGPIO 16/17 |


### 4.1 IO

| IO |  |
| -- | -- |
| GPIO19 | LED_GREEN |
| GPIO21 | LED_BLUE |
| GPIO22 | LED_RED |

## 5. 


- [tanek](https://github.com/TanekLiang)

## 6. 

* [HIFIVE1 Info](https://www.sifive.com/products/hifive1/)
* [HIFIVE1 Software Development Tools](https://www.sifive.com/products/tools/)
* [hifive1-getting-started-guide](https://www.sifive.com/documentation/boards/hifive1/hifive1-getting-started-guide/)
* [hifive1-schematics](https://www.sifive.com/documentation/boards/hifive1/hifive1-schematics/)
