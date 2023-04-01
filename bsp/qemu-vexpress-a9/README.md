# QEMU VExpress A9

## 1 

- Versatile ExpressARM LtdCortexA9uATXCoreTile Express A9x4 [ARM][1] 

- Versatile ExpressFPGACortex-AFPGA

- QEMU/VExpress A9QEMUARM VExpress-A9 FPGAQEMU/VExpressCortex-A9Cortex-A9Cortex-A15VExpress FPGA

- RT-Thread BSPQEMU/VExpress-A9VExpress FPGAFPGA

QEMU/VExpress-A9

|  |  |
| -- | -- |
| CPU | ARM Cortex-A9 |
|  | NA |
| Memory | 128MB(0x60000000 - 0x68000000) |

## 2 

- [env][2]`bsp/qemu-vexpress-a9`env`scons -j4`

![image-20220626114422344](figures/image-20220626114422344.png)



- rtthread.elfrtthread.binQEMUelfrtthread.elf

  ![image-20220626114611158](figures/image-20220626114611158.png)



- RT-Thread Env

  ![image-20220626113747893](figures/image-20220626113747893.png)

- GCC 

  ![image-20220626114020634](figures/image-20220626114020634.png)

- Linux[GNU GCC][3]

## 3 

### 3.1 

bsp

|  |   |    |
| ------ | ----  | :------:  |
| qemu.bat | Windows |  |
| qemu.sh | Linux |  |
| qemu-dbg.bat | Windows |  |
| qemu-dbg.sh | Linux |  |
| qemu-nographic.bat | Windows |  |
| qemu-nographic.sh | Linux |  |

### 3.2 RT-Studio IDERT-Thread



- QEMURT-ThreadQEMU-VEXPRESS-A9

  ![image-20220626125511399](figures/image-20220626125511399.png)

- qemu-a9

  ![image-20220626125644099](figures/image-20220626125644099.png)

- main

  ![image-20220626125717698](figures/image-20220626125717698.png)

- 

  ![image-20220626125837849](figures/image-20220626125837849.png)



###  3.3 Windows ENVRT-Thread

#### 3.3.1 QEMU

- RT-Threadbspenvenvqemu.batstdio

- SD

  > SDmkfsmount

  ![image-20220626115233881](figures/image-20220626115233881.png)

  ![image-20220626115854706](figures/image-20220626115854706.png)

- 

  ![image-20220626115504981](figures/image-20220626115504981.png)

- **.bat**

#### 3.3.2 QEMU

msh **CTRL+C**  **y**  QEMU 

```shell
hello rt-thread
msh />
msh />
msh />Terminate batch job (Y/N)? y
```

### 3.4 Windows VSCode RT-Thread

[VS CodeRT-Thread](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/application-note/setup/qemu/vscode/an0021-qemu-vscode?id=%e4%bd%bf%e7%94%a8-vs-code-%e5%bc%80%e5%8f%91-rt-thread)



###  3.5 LinuxRT-Thread

#### 3.5.1 QEMU

LinuxWindowsWindows**env****qemu-system-arm**Linux`./qemu.sh`

```shell
bsp/qemu-vexpress-a9$ ./qemu-nographic.sh
./qemu-nographic.sh: line 5: /usr/bin/qemu-system-arm: No such file or directory
```

Linux**qemu-system-arm****Linux Ubuntu**

```shell
bsp/qemu-vexpress-a9$ sudo apt-get install qemu-system-arm
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following package was automatically installed and is no longer required:
  tinyproxy-bin
Use 'sudo apt autoremove' to remove it.
Suggested packages:
  vde2
The following NEW packages will be installed:
  qemu-system-arm
0 upgraded, 1 newly installed, 0 to remove and 168 not upgraded.
Need to get 0 B/7,722 kB of archives.
After this operation, 36.6 MB of additional disk space will be used.
Selecting previously unselected package qemu-system-arm.
(Reading database ... 159586 files and directories currently installed.)
Preparing to unpack .../qemu-system-arm_1%3a4.2-3ubuntu6.17_amd64.deb ...
Unpacking qemu-system-arm (1:4.2-3ubuntu6.17) ...
Setting up qemu-system-arm (1:4.2-3ubuntu6.17) ...
Processing triggers for man-db (2.9.1-1) ...
```

**qemu-system-arm**

```shell
/bsp/qemu-vexpress-a9$ qemu-system-arm --version
QEMU emulator version 4.2.1 (Debian 1:4.2-3ubuntu6.17)
Copyright (c) 2003-2019 Fabrice Bellard and the QEMU Project developers
```

#### 3.5.2 QEMU

Linux`qemu-nographic.sh`

```shell
bsp/qemu-vexpress-a9$ ./qemu-nographic.sh
WARNING: Image format was not specified for 'sd.bin' and probing guessed raw.
         Automatically detecting the format is dangerous for raw images, write operations on block 0 will be restricted.
         Specify the 'raw' format explicitly to remove the restrictions.
ALSA lib confmisc.c:767:(parse_card) cannot find card '0'
ALSA lib conf.c:4732:(_snd_config_evaluate) function snd_func_card_driver returned error: No such file or directory
ALSA lib confmisc.c:392:(snd_func_concat) error evaluating strings
ALSA lib conf.c:4732:(_snd_config_evaluate) function snd_func_concat returned error: No such file or directory
ALSA lib confmisc.c:1246:(snd_func_refer) error evaluating name
ALSA lib conf.c:4732:(_snd_config_evaluate) function snd_func_refer returned error: No such file or directory
ALSA lib conf.c:5220:(snd_config_expand) Evaluate error: No such file or directory
ALSA lib pcm.c:2642:(snd_pcm_open_noupdate) Unknown PCM default
alsa: Could not initialize DAC
alsa: Failed to open `default':
alsa: Reason: No such file or directory
ALSA lib confmisc.c:767:(parse_card) cannot find card '0'
ALSA lib conf.c:4732:(_snd_config_evaluate) function snd_func_card_driver returned error: No such file or directory
ALSA lib confmisc.c:392:(snd_func_concat) error evaluating strings
ALSA lib conf.c:4732:(_snd_config_evaluate) function snd_func_concat returned error: No such file or directory
ALSA lib confmisc.c:1246:(snd_func_refer) error evaluating name
ALSA lib conf.c:4732:(_snd_config_evaluate) function snd_func_refer returned error: No such file or directory
ALSA lib conf.c:5220:(snd_config_expand) Evaluate error: No such file or directory
ALSA lib pcm.c:2642:(snd_pcm_open_noupdate) Unknown PCM default
alsa: Could not initialize DAC
alsa: Failed to open `default':
alsa: Reason: No such file or directory
audio: Failed to create voice `lm4549.out'

 \ | /
- RT -     Thread Operating System
 / | \     4.1.0 build Nov 24 2021 19:49:17
 2006 - 2021 Copyright by rt-thread team
lwIP-2.1.2 initialized!
[I/sal.skt] Socket Abstraction Layer initialize success.
[I/SDIO] SD card capacity 65536 KB.
[I/SDIO] switching card to high speed failed!
[W/POSIX.delay] Please consider implementing rt_hw_us_delay() in another file.
[W/POSIX.delay] Please consider implementing rt_hw_us_delay() in another file.
[W/POSIX.delay] Please consider implementing rt_hw_us_delay() in another file.
hello rt-thread
msh />
msh />
msh />
```

**** RT-Threadlogomsh

#### 3.5.3 QEMU

LinuxQEMUWindowsmsh **CTRL+A**  **X**  QEMU 

```shell
hello rt-thread
msh />
msh />
msh />QEMU: Terminated
```



## 4 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0/1 |
| SD/MMC |  |  |
| CLCD |  |  |
| Key |  |  |
| Mouse |  |  |
| EMAC |  |  |



## 5 

[bernard][4]  [recan-li][5]

[1]: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.subset.boards.express/index.html
[2]: https://www.rt-thread.org/page/download.html
[3]: https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q3-update/+download/gcc-arm-none-eabi-5_4-2016q3-20160926-linux.tar.bz2
[4]: https://github.com/BernardXiong
[5]: https://github.com/recan-li
