# FPGA

## 

**FPGA** RISC-VFPGA

 **FPGA** :

* [Nuclei DDR200T](https://nucleisys.com/developboard.php#ddr200t)
* [Nuclei MCU200T](https://nucleisys.com/developboard.php#mcu200t)
* [](https://nucleisys.com/developboard.php#demosoc100t)

### 

|  |  |
| ---  | --- |
|  | Nuclei RISC-V N/NX/UX  |
|  | RV32 or RV64 |
|  | 16MHz or uncertain freq |

****: FPGA bitstream**rtconfig.py****NUCLEI_SDK_CORE**.


## 

### 

[Nuclei RISC-V GCC ToolchainOpenOCD](https://doc.nucleisys.com/nuclei_sdk/quickstart.html#setup-tools-and-environment) 

### 

Nuclei RISC-V GCC ToolchainOpenOCD

#### Windows

 **D:\NucleiStudio\toolchain**, **PATH**,
**D:\NucleiStudio\toolchain\gcc\bin;D:\NucleiStudio\toolchain\openocd\bin;****PATH**

ENV

~~~cmd
set PATH=D:\NucleiStudio\toolchain\gcc\bin;D:\NucleiStudio\toolchain\openocd\bin;%PATH%
~~~

#### Linux

 **~/NucleiStudio/toolchain**, Linux``.bashrc``


~~~bash
export PATH=~/NucleiStudio/toolchain/gcc/bin:~/NucleiStudio/toolchain/openocd/bin:$PATH
~~~

ENV

~~~bash
export PATH=~/NucleiStudio/toolchain/gcc/bin:~/NucleiStudio/toolchain/openocd/bin:$PATH
~~~

****: RISC-V GCCOPENOCD

## 

### 

[Nuclei FPGA](https://nucleisys.com/upload/files/fpga/doc/Nuclei_FPGA_DebugKit_Intro_202012.pdf)

### 

[RT-Thread](https://github.com/RT-Thread/rt-thread)[ENV](https://www.rt-thread.org/document/site/tutorial/env-video/)

ENV, **rt-thread\bsp\nuclei\nuclei_fpga_eval**ENV

****: Nuclei GCCNuclei OpenOCD

1.  ``pkgs --update``**Nuclei SDK**

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

4. Nuclei RISC-V ``rtconfig.py````NUCLEI_SDK_CORE````NUCLEI_SDK_DOWNLOAD``
   - ``NUCLEI_SDK_CORE``[Supported Nuclei Cores](https://doc.nucleisys.com/nuclei_sdk/develop/buildsystem.html#core)
   - ``NUCLEI_SDK_DOWNLOAD````ilm``,``flash````flashxip``, [Supported Download Modes](https://doc.nucleisys.com/nuclei_sdk/develop/buildsystem.html#download)
   - NucleiN307(rv32imafc), ``flash``,
     ``NUCLEI_SDK_CORE````n307``, ``NUCLEI_SDK_DOWNLOAD````flash``.

5. ``rtconfig.py`` ``scons``

### 

, ENV``scons --run upload``

:

~~~
scons: Reading SConscript files ...
Supported downloaded modes for board nuclei_fpga_eval are ('ilm', 'flash', 'flashxip'), chosen downloaded mode is ilm
Upload application rtthread.elf using openocd and gdb
riscv-nuclei-elf-gdb rtthread.elf -ex "set remotetimeout 240"                     -ex "target remote | openocd --pipe -f D:/workspace/Sourcecode/rt-thread/bsp/nuclei/nuclei_fpga_eval/packages/nuclei_sdk-latest/SoC/demosoc/Board/nuclei_fpga_eval/openocd_demosoc.cfg"
              --batch -ex "monitor halt" -ex "monitor flash protect 0 0 last off" -ex "load"                     -ex "monitor resume" -ex "monitor shutdown" -ex "quit"
D:\Software\Nuclei\gcc\bin\riscv-nuclei-elf-gdb.exe: warning: Couldn't determine a path for the index cache directory.
Nuclei OpenOCD, i386 Open On-Chip Debugger 0.10.0+dev-g11f0cf429 (2020-07-15-04:09)
Licensed under GNU GPL v2
For bug reports, read
        http://openocd.org/doc/doxygen/bugs.html
rt_list_insert_before (n=0xdeadbeef, l=0x90000f80 <timer_thread_stack+464>) at D:\workspace\Sourcecode\rt-thread\include/rtservice.h:79
79          n->next = l;
cleared protection for sectors 0 through 63 on flash bank 0

Loading section .init, size 0x284 lma 0x80000000
Loading section .text, size 0xb30a lma 0x800002c0
Loading section .rodata, size 0x3248 lma 0x8000b5d0
Loading section .data, size 0x340 lma 0x8000e818
Start address 0x80000198, load size 60182
Transfer rate: 48 KB/sec, 10030 bytes/write.
shutdown command invoked
A debugging session is active.

        Inferior 1 [Remote target] will be detached.

Quit anyway? (y or n) [answered Y; input not from terminal]
[Inferior 1 (Remote target) detached]
~~~

, **(115200-N-8-1)**,  RT-Thread :

> Bit16MHz, 115200bps.

```
initialize rti_board_start:0 done

 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Apr 23 2020
 2006 - 2020 Copyright by rt-thread team
do components initialization.
initialize rti_board_end:0 done
initialize dfs_init:0 done
initialize libc_system_init:0 done
initialize finsh_system_init:0 done
msh />
```

(TeraTerm)``ps``:

~~~
msh />ps
thread   pri  status      sp     stack size max used left tick  error
-------- ---  ------- ---------- ----------  ------  ---------- ---
serrxsim   5  suspend 0x00000134 0x0000018c    77%   0x00000005 000
tshell    20  running 0x000002b0 0x00001000    17%   0x00000005 000
tidle0    31  ready   0x00000164 0x0000018c    89%   0x0000000b 000
timer      4  suspend 0x00000120 0x00000200    56%   0x00000009 000
msh />
~~~

### 

, ENV``scons --run debug``GDB

:

~~~
scons: Reading SConscript files ...
Supported downloaded modes for board nuclei_fpga_eval are ('ilm', 'flash', 'flashxip'), chosen downloaded mode is ilm
Debug application rtthread.elf using openocd and gdb
riscv-nuclei-elf-gdb rtthread.elf -ex "set remotetimeout 240"                     -ex "target remote | openocd --pipe -f D:/workspace/Sourcecode/rt-thread/bsp/nuclei/nuclei_fpga_eval/packages/nuclei_sdk-latest/SoC/demosoc/Board/nuclei_fpga_eval/openocd_demosoc.cfg"
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
Remote debugging using | openocd --pipe -f D:/workspace/Sourcecode/rt-thread/bsp/nuclei/nuclei_fpga_eval/packages/nuclei_sdk-latest/SoC/demosoc/Board/nuclei_fpga_eval/openocd_demosoc.cfg
Nuclei OpenOCD, i386 Open On-Chip Debugger 0.10.0+dev-g11f0cf429 (2020-07-15-04:09)
Licensed under GNU GPL v2
For bug reports, read
        http://openocd.org/doc/doxygen/bugs.html
0x0000000080000e80 in rt_thread_idle_entry (parameter=<optimized out>)
    at D:\workspace\Sourcecode\rt-thread\src\idle.c:253
253                     idle_hook_list[i]();
(gdb) load
Loading section .init, size 0x284 lma 0x80000000
Loading section .text, size 0xb30a lma 0x800002c0
Loading section .rodata, size 0x3248 lma 0x8000b5d0
Loading section .data, size 0x340 lma 0x8000e818
Start address 0x80000198, load size 60182
Transfer rate: 49 KB/sec, 10030 bytes/write.
(gdb) b main
Breakpoint 1 at 0x800002c0: file applications\main.c, line 35.
(gdb) c
Continuing.

Breakpoint 1, main () at applications\main.c:35
35          board_serial_init();
(gdb) n
rt_thread_exit () at D:\workspace\Sourcecode\rt-thread\src\thread.c:277
277         return rt_current_thread;
(gdb) c
Continuing.
~~~

:

* https://doc.nucleisys.com/nuclei_sdk/quickstart.html#debug-application

, **Nuclei Studio**, Debug Configuration, 
ELF, OPENOCDGDB, OPENOCD**bsp\nuclei\nuclei_fpga_eval\packages\nuclei_sdk-latest\SoC\demosoc\Board\nuclei_fpga_eval\openocd_demosoc.cfg**


## 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0 |

**:**

- RT-Thread [../libraries/demosoc/HAL_Drivers](../libraries/demosoc/HAL_Drivers)
- , 
- 8MHz57600bps, Bit16Mhz
- 

## 

:

- [fanghuaqi](https://github.com/fanghuaqi)

