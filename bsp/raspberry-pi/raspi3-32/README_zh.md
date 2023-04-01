# Raspberry PI 3B(32)

## 1. 

Raspberry Pi 34Broadcom BCM2837 (ARMv8)VideoCore IV GPU1GB

RT-Thread BSP Raspberry Pi 3B 32, RT-Thread

RT-ThreadCortex-AAPARM9Cortex-AXilinxZynq

RT-ThreadRT-ThreadRT-ThreadCortex-A[2B](https://www.raspberrypi.org/products/raspberry-pi-2-model-b/)[3B](https://www.raspberrypi.org/products/raspberry-pi-3-model-b/)[4B](https://www.raspberrypi.org/products/raspberry-pi-4-model-b/)

RT-Thread2BCortex-A732RT-Thread3Cortex-A53 64Cortex-A7

![raspi3_f](figures/raspi3_f.jpg)

![raspi3_b](figures/raspi3_b.jpg)

Raspberry Pi 3B

|    |  |
|------- | ------------------------------- |
|  CPU   | quad-core ARM Cortex A53(ARMv8) |
|    | 1.2 GHz |
| GPU | VideoCore IV |
| GPU | 400MHz |
| Memory | 1GB  (0x0000000 - 0x40000000) |
| | 0x3f000000 - 0x40000000peripheral |



![GPIO-Pinout-Diagram-2](figures/GPIO-Pinout-Diagram-2.png)

## 2. 

Windows[env][1]

Linuxgcc gcc-arm-none-eabi-5_4-2016q3

```
tar vxf gcc-arm-none-eabi-5_4-2016q3-20160926-linux.tar.bz2
```

Linux`bsp/raspi3-32/rtconfig.py`

```
EXEC_PATH = r'/opt/gcc-arm-none-eabi-5_4-2016q3/bin'
```

 `/bin`

`rt-thread/bsp/raspi3-32`

```
scons
```

rtthread.elfkernel7.img
kernel7.imgcpraspberry SD

### 2.1 eclipse  ###
  eclipse cdt 
  eclipse cdt workspace ,xxx\xxx\rt-thread\bsp
 Import  General-> Existing Peojects into Workspace  Browse.. raspi3Finish

btw:scons,qemu debug,ARM JTAG

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

raspi3 GPIO 14, GPIO 15



![raspberrypi-console](figures/raspberrypi-console.png)

 115200 8N1 

SD3B

```text
heap: 0x0005d784 - 0x0045d784

 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Jan  9 2020
 2006 - 2019 Copyright by rt-thread team
[I/I2C] I2C bus [i2c0] registered
[I/I2C] I2C bus [i2c1] registered
[I/SDIO] SD card capacity 15558144 KB.
found part[0], begin: 1048576, size: 63.0MB
found part[1], begin: 67108864, size: 14.793GB
file system initialization done!
boot cpu:3
msh />cpu = 0x00000003
cpu 3 startup.
start OK: CPU 3
boot cpu:2
cpu = 0x00000002
cpu 2 startup.
start OK: CPU 2
boot cpu:1
cpu = 0x00000001
cpu 1 startup.
start OK: CPU 1
Hello RT-Thread!

msh />
```

## 4. 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0|
| GPIO |  | - |
| IIC |  | - |
| SPI |  | - |
| CPU Timer |  | - |
| SD |  | - |
| RTC |  | - |
| WDT |  | - |
| MAILBOX |  | - |
| SMP |  | - |
| FRAMEBUFFER |  | HDMI |

## 5. 

[bernard][5]

[1]: https://www.rt-thread.org/page/download.html
[2]: https://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q1-update/+download/gcc-arm-none-eabi-4_8-2014q1-20140314-linux.tar.bz2
[3]: https://downloads.raspberrypi.org/raspbian_lite_latest
[4]: https://etcher.io
[5]: https://github.com/BernardXiong
