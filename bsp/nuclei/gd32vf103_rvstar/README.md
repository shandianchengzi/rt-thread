# RVSTAR #

## 

**RVSTAR** [Nuclei](https://nucleisys.com/)RISC-VGD32VF103

 **RVSTAR**  [RVSTAR](https://www.rvmcu.com/quickstart-doc-u-rvstar.html)

### 

|  |             |
| ---- | --------------- |
|  | Nuclei N205     |
|  | 32-bit RV32IMAC |
|  | 108 MHz         |

## 

### 

[Nuclei RISC-V GCC ToolchainOpenOCD](https://doc.nucleisys.com/nuclei_sdk/quickstart.html#setup-tools-and-environment) 

### 

Nuclei RISC-V GCC ToolchainOpenOCD

#### Windows

 **D:\Software\Nuclei**, **PATH**,
**D:\Software\Nuclei\gcc\bin;D:\Software\Nuclei\openocd\bin;****PATH**

ENV

~~~cmd
set PATH=D:\Software\Nuclei\gcc\bin;D:\Software\Nuclei\openocd\bin;%PATH%
~~~

#### Linux

 **~/Software/Nuclei**, Linux``.bashrc``


~~~bash
export PATH=~/Software/Nuclei/gcc/bin:~/Software/Nuclei/openocd/bin:$PATH
~~~

ENV

~~~bash
export PATH=~/Software/Nuclei/gcc/bin:~/Software/Nuclei/openocd/bin:$PATH
~~~

****: RISC-V GCCOPENOCD

## 

### [](https://doc.nucleisys.com/nuclei_board_labs/hw/hw.html#on-board-debugger-driver)

### 

[RT-Thread](https://github.com/RT-Thread/rt-thread)[ENV](https://www.rt-thread.org/document/site/tutorial/env-video/)

ENV, **rt-thread\bsp\nuclei\gd32vf103_rvstar**ENV

****: Nuclei GCCNuclei OpenOCD

1.  ``pkgs --update``**Nuclei SDK**,

   ```c
     .stack ORIGIN(RAM) + LENGTH(RAM) - __TOT_STACK_SIZE (NOLOAD) :
     {
   	...
       PROVIDE( _sp = . );
       PROVIDE( __rt_rvstack = . );//
     } >RAM AT>RAM
   ```

2. ****:  ``menuconfig``

3.  ``scons -c``

4.  ``scons``

### 

, ENV``scons --run upload``

:

~~~bat
57856@DESKTOP-4LATIEU D:\workspace\Sourcecode\rt-thread\bsp\nuclei\gd32vf103_rvstar
> scons --run upload
scons: Reading SConscript files ...
Supported downloaded modes for board gd32vf103v_rvstar are flashxip, chosen downloaded mode is flashxip
Upload application rtthread.elf using openocd and gdb
riscv-nuclei-elf-gdb rtthread.elf -ex "set remotetimeout 240"                     -ex "target remote | openocd --pipe -f D:/workspace/Sourcecode/rt-thread/bsp/nuclei/gd32vf103_rvstar/packages/nuclei_sdk-latest/SoC/gd32vf103/Board/gd32vf103v_rvstar/openocd_gd32vf103.cfg"                     --batch -ex "monitor halt" -ex "monitor flash protect 0 0 last off" -ex "load"                     -ex "monitor resume" -ex "monitor shutdown" -ex "quit"
D:\Software\Nuclei\gcc\bin\riscv-nuclei-elf-gdb.exe: warning: Couldn't determine a path for the index cache directory.
Nuclei OpenOCD, 64-bit Open On-Chip Debugger 0.10.0+dev-00014-g0eae03214 (2019-12-12-07:43)
Licensed under GNU GPL v2
For bug reports, read
        http://openocd.org/doc/doxygen/bugs.html
rt_assert_handler (ex_string=ex_string@entry=0x800ab10 "0", func=func@entry=0x800ac14 <__FUNCTION__.3090> "rt_sem_take", line=line@entry=363) at D:\workspace\Sourcecode\rt-thread\src\kservice.c:1371
1371                while (dummy == 0);
cleared protection for sectors 0 through 127 on flash bank 0

Loading section .init, size 0x264 lma 0x8000000
Loading section .text, size 0xa646 lma 0x8000280
Loading section .rodata, size 0x2a80 lma 0x800a8c8
Loading section .data, size 0x350 lma 0x800d348
Start address 0x800015c, load size 54906
Transfer rate: 6 KB/sec, 9151 bytes/write.
shutdown command invoked
A debugging session is active.

        Inferior 1 [Remote target] will be detached.

Quit anyway? (y or n) [answered Y; input not from terminal]
[Inferior 1 (Remote target) detached]
~~~

, (115200-N-8-1),  RT-Thread 

```
initialize rti_board_start:0 done

 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Jun  9 2020
 2006 - 2020 Copyright by rt-thread team
do components initialization.
initialize rti_board_end:0 done
initialize rt_work_sys_workqueue_init:0 done
initialize rt_hw_pin_init:0 done
initialize libc_system_init:0 done
initialize finsh_system_init:0 done
msh >
```

(TeraTerm)``ps``:

~~~
msh >ps
thread   pri  status      sp     stack size max used left tick  error
-------- ---  ------- ---------- ----------  ------  ---------- ---
tshell    20  running 0x000000f8 0x00000800    21%   0x00000008 000
sys_work  23  suspend 0x00000098 0x00000800    07%   0x0000000a 000
tidle0    31  ready   0x000000b8 0x0000018c    46%   0x00000013 000
timer      4  suspend 0x00000098 0x00000200    29%   0x00000009 000
msh >list_device
device           type         ref count
-------- -------------------- ----------
pin      Miscellaneous Device 0
uart4    Character Device     2
msh >version

 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Jun 11 2020
 2006 - 2020 Copyright by rt-thread team
msh >free
total memory: 14208
used memory : 5248
maximum allocated memory: 6424
~~~

### 

#### GDB

, ENV``scons --run debug``GDB



~~~bat
57856@DESKTOP-4LATIEU D:\workspace\Sourcecode\rt-thread\bsp\nuclei\gd32vf103_rvstar
> scons --run debug
scons: Reading SConscript files ...
Supported downloaded modes for board gd32vf103v_rvstar are flashxip, chosen downloaded mode is flashxip
Debug application rtthread.elf using openocd and gdb
riscv-nuclei-elf-gdb rtthread.elf -ex "set remotetimeout 240"                     -ex "target remote | openocd --pipe -f D:/workspace/Sourcecode/rt-thread/bsp/nuclei/gd32vf103_rvstar/packages/nuclei_sdk-latest/SoC/gd32vf103/Board/gd32vf103v_rvstar/openocd_gd32vf103.cfg"
D:\Software\Nuclei\gcc\bin\riscv-nuclei-elf-gdb.exe: warning: Couldn't determine a path for the index cache directory.
GNU gdb (GDB) 8.3.0.20190516-git
Copyright (C) 2019 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "--host=i686-w64-mingw32 --target=riscv-nuclei-elf".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from rtthread.elf...
Remote debugging using | openocd --pipe -f D:/workspace/Sourcecode/rt-thread/bsp/nuclei/gd32vf103_rvstar/packages/nuclei_sdk-latest/SoC/gd32vf103/Board/gd32vf103v_rvstar/openocd_gd32vf103.cfg
Nuclei OpenOCD, 64-bit Open On-Chip Debugger 0.10.0+dev-00014-g0eae03214 (2019-12-12-07:43)
Licensed under GNU GPL v2
For bug reports, read
        http://openocd.org/doc/doxygen/bugs.html
0x080011ca in rt_thread_idle_excute () at D:\workspace\Sourcecode\rt-thread\src\idle.c:153
153         while (_has_defunct_thread())
(gdb) b irq_entry
Breakpoint 1 at 0x8003840: file D:\workspace\Sourcecode\rt-thread\libcpu\risc-v\nuclei\interrupt_gcc.S, line 190.
(gdb) c
Continuing.
Note: automatically using hardware breakpoints for read-only addresses.

Breakpoint 1, irq_entry () at D:\workspace\Sourcecode\rt-thread\libcpu\risc-v\nuclei\interrupt_gcc.S:190
190         SAVE_CONTEXT
(gdb) c
~~~

:

* https://doc.nucleisys.com/nuclei_sdk/quickstart.html#debug-application

#### Nuclei Studio IDE

, [**Nuclei Studio IDE**](https://nucleisys.com/download.php).

1. Nuclei Studio IDE, **Nuclei_RT-Thread****C Project**Project Type**Empty Project**,
   Toolchain**RISC-V Cross GCC**, **Finish**.

   ![Create A RISC-V C Project](doc/images/create_c_project.png)

2. **rt-thread**Nuclei Studio**Nuclei_RT-Thread**
   **Link to files and folders**, **OK**, **rt-thread**
   `scons`

   ![Drop and link RT-Thread source code](doc/images/link_rtthread_code.png)

3. OpenOCD Debugging Configuration, ELF, **Disable auto build**, :

   ![Create OpenOCD Debugging Configuration](doc/images/create_gdb_cfg.png)

4. **Debugger**Tab, OPENOCD, OPENOCD
*bsp\nuclei\gd32vf103_rvstar\packages\nuclei_sdk-latest\SoC\gd32vf103\Board\gd32vf103v_rvstar\openocd_gd32vf103.cfg*
    **Debug**

   ![Configure OpenOCD configuration file](doc/images/config_openocd_cfg.png)

5. 

   ![Debug in Nuclei Studio IDE](doc/images/start_debug_in_ide.png)

6. 

## 

|     |  |                              |
| ------- | -------- | :------------------------------: |
| UART    |      | RV-STARUART4,  |
| GPIO    |      |            |
| SPI     |      |                          |
| I2C     |      |                          |
| HWTIMER |      |                          |
| PWM     |      |                          |
| WDT     |      |                          |
| RTC     |      |                          |
| ADC     |      |                          |

### Pinmux

`menuconfig`
`Hardware Drivers Config -> On-chip Peripheral Drivers`
GPIOpinux
 `board/board.c`  `rt_hw_drivers_init`


****

* I2CPinmux

I2C1SCLSDAPB10PB11menuconfigI2C1
board.c`rt_hw_i2c_drvinit`

~~~c
/* Configure PB10 PB11 (I2C1 SCL SDA) as alternate function  */
gpio_init(GPIOB, GPIO_MODE_AF_OD, GPIO_OSPEED_50MHZ, GPIO_PIN_10 | GPIO_PIN_11);
~~~

* SPIPinmux

SPI0SCK MISOMOSIPA5, PA6PA7menuconfigSPI0
board.c`rt_hw_spi_drvinit`

~~~c
/* Configure PA5 PA6 PA7 (SPI0 SCK MISO MOSI) as alternate function */
gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_5 | GPIO_PIN_7);
gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
~~~

* 

### 

- RT-Thread [../libraries/gd32vf103/HAL_Drivers](../libraries/gd32vf103/HAL_Drivers)
- , 
- GD32VF103 `menuconfig -> Hardware Drivers Config -> On-chip Peripheral Drivers` 
- HWTIMERPWMTIMER

## 


- [fanghuaqi](https://github.com/fanghuaqi)

