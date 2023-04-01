# Raspberry PI 3-64

## 1. 

Raspberry Pi 3

* B : 4 Broadcom BCM2837 (ARMv8-A) 1.2GHzVideoCore IV GPU1GB100 Base-T Ethernet
* B+: 4 Broadcom BCM2837B0 Cortex-A53 (ARMv8) 1.4GHz, 1GB LPDDR2 SDRAM GigaE over USB 2.0
* A+: 4 Broadcom BCM2837B0 Cortex-A53 (ARMv8) 1.4GHz, 512MB LPDDR2 SDRAM

RT-Thread BSP Raspberry Pi 3 64, RT-Thread


## 2. 

### 2.1 Window

Windows[env][1]

windowsaarch64gccgcc-arm-8.3aarch64-elf

gcc`\env\tools\gnu_gcc\arm_gcc`

`bsp\raspberry-pi\raspi3-64\rtconfig.py`



```
EXEC_PATH = r'E:/env_released_1.1.2/env/tools/gnu_gcc/arm_gcc/gcc-arm-8.3-2019.03-i686-mingw32-aarch64-elf/bin'
```

`bsp\raspberry-pi\raspi3-64\`scons

**window**

`gcc-arm-8.3-2019.03-i686-mingw32-aarch64-elf.tar.xz`7-zip
`/bin/aarch64-elf-ld.exe`size0
:

```
collect2.exe:fatal error:CreateProcess:No such file or directory
```

### 2.2 Linux

Linux[gcc][2]Linuxgcc`gcc-arm-8.3-2019.03-x86_64-aarch64-elf`

`bsp\raspberry-pi\raspi3-64`scons


## 3. 

### 3.1 [raspbian][3]raspbian SD

Windows[etcher.io][4]etcher,img

, linux

```
unzip 2018-06-27-raspbian-stretch-lite.zip
```

SDlinux

```
sudo dd if=2018-06-27-raspbian-stretch-lite.img of=/dev/xxx bs=32M conv=fsync
```

**: /dev/xxx SD**

Windowsetcher2018-06-27-raspbian-stretch-lite.imgSD

kernel8.imgSD boot kernel*.img

### 3.2 

raspi3 GPIO 14, GPIO 15(pi2GPIO)

![raspi2](figures/raspi_uart.png)

 115200 8N1 

SD

```text
 heap: 0x00020b20 - 0x00400000

 \ | /
- RT -     Thread Operating System
 / | \     3.1.0 build Aug 23 2019
 2006 - 2019 Copyright by rt-thread team
Hello RT-Thread!
msh >
```

## 4. 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0|
| GPIO |  | - |
| I2C |  | - |
| RTC |  | - |
| SDIO |  | SDCARD |
| SPI |  | - |
| TIMER |  | - |
| WDT |  | - |
| MBOX |  | - |
| FRAMEBUFFER |  | HDMI |

## 5. 

[bigmagic123][5]

[1]: https://www.rt-thread.org/page/download.html
[2]: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads
[3]: https://downloads.raspberrypi.org/raspbian_lite_latest
[4]: https://etcher.io
[5]: https://github.com/bigmagic123
