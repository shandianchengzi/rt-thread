# loongson_pi2 

## 1. 

2K2K1000

|  |  |
| -- | -- |
|| 2K1000 |
|CPU| GS264 |
|| 1GHz |
|DDR3| 2GB |
|Flash| 8Mb SPI FLASH |

[][1] 2K1000  1GHz DDR3  DDR3  GPIO  1   3  USB HDMI LCD / SD  2  CAN  RTC  WIFI 2K  


## 2. 

**Ubuntu**[mips-sde-elf-gcc][2]ucb2

**windows**

[mips-2015.05-19-mips-sde-elf.exe](https://sourcery.mentor.com/GNUToolchain/package13851/public/mips-sde-elf/mips-2015.05-19-mips-sde-elf.exe)

bsp`rtconfig.py`

```python
if  CROSS_TOOL == 'gcc':
	PLATFORM    = 'gcc'
	EXEC_PATH   = "/opt/mips-2015.05-19-mips-sde-elf-i686-pc-linux-gnu/mips-2015.05/bin/"
```

`rtconfig.py`

`D:\mgc\embedded\codebench`envconsole`RTT_EXEC_PATH`

```
    set RTT_EXEC_PATH=D:\mgc\embedded\codebench\bin
```

 `scons --exec-path="GCC"` 

envconsole`bsp/ls2kdev``scons``rtthread.elf``rtthread.bin``rtthread.elf`

## 3.

rt-thread[pmon][3]tftp



![loongsonpi](figures/loongsonpi.png)

12VRS232RS232USB`LAN0`

`START````c`pmon



pmontftpip`ifconfig`ip`192.168.12.35`

```
ifaddr syn0 192.168.12.100 
load tftp://192.168.12.35/rtthread.elf;
g
```

`ifaddr`pmon`syn0`tftp`rtthread.elf`tftp`g`

rtthread

```
   zero      at       v0       v1       a0       a1       a2       a3   
 00000000 00000000 00000000 00000000 00000003 aafffea8 8f800000 8f1371d0
    t0       t1       t2       t3       t4       t5       t6       t7   
 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    s0       s1       s2       s3       s4       s5       s6       s7   
 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    t8       t9       k0       k1       gp       sp       s8       ra   
 00000000 00000000 00000000 00000000 00000000 aafffe88 00000000 8f0b1418
Current SR: 0x10008080

 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Apr  7 2020
 2006 - 2020 Copyright by rt-thread team
Hi, this is RT-Thread!!
msh >
```

## 4.

pmonTFTP

****
IPpmon`set ifconfig syn0:10.1.1.100``syn0`ipiprt-threadTFTPIP****

****

Debian`root``loongson`bootboot.cfg

```
title   TFTPBOOT
 kernel tftp://10.1.1.118/rtthread.elf
 args console=tty root=/dev/sda2
 initrd (wd0,0)/initrd.img
```

`tftp://10.1.1.118/rtthread.elf``10.1.1.118`tftpip

****

TFTPls2krt-thread

pmonTFTP

## 5.SATASSD

SATASSDmenuconfig

```
RT-Thread online packages  --->
	 			system packages  --->
	 				lwext4: an excellent choice of ext2/3/4 filesystem for microcontrollers
```



```
pkgs --update
```

`scons`SATASSD

## 6. 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0\UART4, |
| GPIO |  | - |
| PWM |  | - |
| GMAC |  |  |
| RTC  |  | - |
| SPI |  | - |
| SATA SSD |  | lwext4 |

## 7. 

[bernard][4]

[1]: http://ftp.loongnix.org/loongsonpi/pi_2/doc
[2]: https://pan.baidu.com/s/17dbdOE4NAJ-qEW7drVRq2w
[3]: http://ftp.loongnix.org/embedd/ls2k/
[4]: https://github.com/BernardXiong