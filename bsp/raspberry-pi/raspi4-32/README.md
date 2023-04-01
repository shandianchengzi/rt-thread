# Raspberry PI 4

## 1. 

4BBCM27111.5GHzCortex A723A53LPDDR45V/3A USB-CGPIO 5V

Wi-Fi5.0MIPI CSIUSB40

RT-Thread BSP Raspberry Pi 4, RT-Thread


## 2. 

[env](https://www.rt-thread.org/page/download.html)console`bsp\raspberry-pi\raspi4-32`

```
scons
```

rtthread.elfkernel7.img


## 3. 
### 3.1 

raspi4 GPIO 14, GPIO 15

![raspi2](../raspi3-32/figures/raspberrypi-console.png)

 115200 8N1 

### 3.2 RTTSD

32GBSDboot

```
https://pan.baidu.com/s/1PxgvXAChUIOgueNXhgMs8w 
pioj 
```

sdsdkernel7.img

### 3.3 RTTuboot

ubootubootsd



**1.tftp**

windowstftpdtftp`bsp\raspberry-pi\raspi4-32`

**2.uboot**



```
setenv bootcmd "dhcp 0x00200000 x.x.x.x:kernel7.img;dcache flush;go 0x00200000"
saveenv
reset
```

`x.x.x.x`tftppcip

**3.**

`bsp\raspberry-pi\raspi4-32\link.ld``0x200000`

```
SECTIONS
{
    . = 0x8000;
    . = ALIGN(4096);
    .
    .
    .
}
```



```
SECTIONS
{
    . = 0x200000;
    . = ALIGN(4096);
    .
    .
    .
}
```



```
scons -c
scons
```

**3.**

tftpuboottftp



```
heap: 0x000607e8 - 0x040607e8

 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Oct 27 2020
 2006 - 2020 Copyright by rt-thread team
[I/SDIO] SD card capacity 31205376 KB.
found part[0], begin: 1048576, size: 29.777GB
file system initialization done!
Hi, this is RT-Thread!!
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
| BSC |  | - |
| DMA |  | - |
| DSI LCD/TOUCH |      | DSILCDTOUCH |
| ILI9486 SPI LCD |  | - |
| XPT2046 TOUCH |      | - |
| BULETOOTH |  | resetloadfirmware |

## 5. 

rt-thread100MB`board.c``platform_mem_desc``board.h``0x08000000`1Mcache4CPUGPU

## 6. 

[bernard][5]

[1]: https://www.rt-thread.org/page/download.html
[2]: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads
[3]: https://downloads.raspberrypi.org/raspbian_lite_latest
[4]: https://etcher.io
[5]: https://github.com/BernardXiong
