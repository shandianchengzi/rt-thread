# Raspberry PI 4

## 1. 

4BBCM27111.5GHzCortex A723A53LPDDR45V/3A USB-CGPIO 5V

Wi-Fi5.0MIPI CSIUSB40

RT-Thread BSP Raspberry Pi 4, RT-Thread


## 2. 

[env](https://www.rt-thread.org/page/download.html)console`bsp\raspberry-pi\raspi4-64`

```
scons
```

 `rtthread.elf`, `rtthread.bin` 

## 3. 
### 3.1 

raspi4 GPIO 14, GPIO 15

![raspi2](../raspi3-32/figures/raspberrypi-console.png)

 115200 8N1 

### 3.2 RTTSD

 u-boot 

### 3.3 RTTuboot

 bsp  `tools`  [u-boot64.bin](./tools/u-boot64.bin)  [config.txt](./tools/config.txt)  sd sd  [imager](https://www.raspberrypi.com/software/) 



**1.tftp**

windowstftpdtftp`bsp\raspberry-pi\raspi4-64`

**2.uboot**



```
setenv bootcmd "dhcp 0x00208000 x.x.x.x:rtthread.bin;dcache flush;go 0x00208000"
saveenv
reset
```

`x.x.x.x`tftppcip

**3.**

 python 

**3.**

tftpuboottftp



```
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Mar 29 2023 10:56:23
 2006 - 2022 Copyright by RT-Thread team
lwIP-2.1.2 initialized!
EMMC: assuming clock rate to be 100MHz
[I/sal.skt] Socket Abstraction Layer initialize success.
[I/utest] utest is initialize success.
[I/utest] total utest testcase num: (0)
[I/DBG] version is B1

[I/SDIO] SD card capacity 31166976 KB.
found part[0], begin: 4194304, size: 256.0MB
found part[1], begin: 272629760, size: 3.856GB
file system initialization done!
cpu 2 boot success
cpu 1 boot success
cpu 3 boot success
msh />
```

## 4. 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0,UART2,UART3,UART4,UART5 |
| GPIO |  | - |
| SPI |  | SPI0 |
| MAILBOX |  | - |
| WATCHDOG |  | - |
| HDMI |  | - |
| SDIO |  | - |
| ETH |  | - |

## 5. 

rt-thread100MB`board.c``platform_mem_desc``board.h`

## 6. 

[bernard][5]

[1]: https://www.rt-thread.org/page/download.html
[2]: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads
[3]: https://downloads.raspberrypi.org/raspbian_lite_latest
[4]: https://etcher.io
[5]: https://github.com/BernardXiong
