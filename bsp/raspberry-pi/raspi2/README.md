# Raspberry PI 2B

## 1. 

Raspberry Pi 24Broadcom BCM2836 (ARMv7-A)VideoCore IV GPU1GB

RT-Thread BSP Raspberry Pi 2B , RT-Thread

![raspi2](figures/raspi2.png)

Raspberry Pi 2B

|    |  |
|------- | ------------------------------- |
|  CPU   | ARM Cortex-A74 |
|    | 900M |
| Memory | 1GB  (0x0000000 - 0x40000000) |
| | 0x3f000000 - 0x40000000peripheral |

## 2. 

Windows[env][1]

Linuxgcc [gcc-arm-none-eabi-4_8-2014q1_linux][2]

```
tar vxf gcc-arm-none-eabi-4_8-2014q1_linux.tar.bz2
```

Linux`bsp/raspi2/rtconfig.py`

```
EXEC_PATH = r'/opt/gcc-arm-none-eabi-4_8-2014q1_gri/bin'
```

 `/bin`

`rt-thread/bsp/raspi2`

```
scons
```

kernel.elfkernel.img
kernel.imgcpraspberry SD

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

kernel7.imgSD boot

### 3.2 

raspi2 GPIO 14, GPIO 15

![raspi2](figures/raspi_uart.png)

 115200 8N1 

SD2B

```text
 heap: 0x00020b20 - 0x00400000

 \ | /
- RT -     Thread Operating System
 / | \     3.1.0 build Aug 23 2018
 2006 - 2018 Copyright by rt-thread team
Hello RT-Thread!
msh >
```

## 4. 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0|

## 5. 

[bernard][5]

  [1]: https://www.rt-thread.org/page/download.html
  [2]: https://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q1-update/+download/gcc-arm-none-eabi-4_8-2014q1-20140314-linux.tar.bz2
  [3]: https://downloads.raspberrypi.org/raspbian_lite_latest
  [4]: https://etcher.io
  [5]: https://github.com/BernardXiong
