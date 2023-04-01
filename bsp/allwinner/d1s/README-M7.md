# M7 RT-Smart

## 

#### 

 ubuntu20.04(/docker/) + Window10/11

- ubuntu
- windows

#### 

**Ubuntu:**

```bash
sudo apt install libncurses5-dev scons gcc qemu-system
```

- qemuRISC-V
- gccmenucofig
- libncurses5-dev menucofig
- sconsRT-Smart

**Windows:**

- vscodewindowsubuntuwinlinux
- MobaXtermsshubuntuM7
- env_riscv_1.1.3.ziprisc-vENV

#### 

- https://gitee.com/rtthread/rt-thread rtthreadsubmodulertthread-smartrt-smart

rtthread-smartubuntu

RT-Smart

## 

QEMU

 qemu-riscv64  RT-Smart https://gitee.com/guozhanxin/rtthread-smart/tree/master/docs/risc-v64

 qemu-riscv64 RT-Smart `hello.elf` 

```
msh /bin>hello.elf
msh /bin>hello world!
```

## 

#### 

USBTTL

<img src="figures/board.png" style="zoom:50%;" />

#### 

1. 

2. toolsfel.zipfel

![1662705678296](figures/fel_driver.png)

#### 

 MobaXterm 500000

>  

<img src="figures/mobaxterm.png" alt="1662708288766" style="zoom: 50%;" />

#### 

 qemu-riscv64  scons  RT-Smart 

 `./mksdimg.sh` sd.bin D1s 

#### 

fel

1. tools xfel_v1.2.9.7z 

```shell
boot0_sdcard_sun20iw1p1_f133.bin   ---- boot
sd.bin                             ---- 
xfel.exe                           ---- 
```

2. tools env_riscv_1.1.3.zip env xfel_v1.2.9 

- boot xfel.exe write 8192 boot0_sdcard_sun20iw1p1_f133.bin
-  xfel.exe sd write 57344 sd.bin
-  xfel.exe reset

>  fel



```shell
11714@DESKTOP-VEL6MD9 E:\workspace\d1s-smart\env_riscv_1.1.3
> cd E:\workspace\d1s-smart\xfel_v1.2.9

11714@DESKTOP-VEL6MD9 E:\workspace\d1s-smart\xfel_v1.2.9
> xfel.exe write 8192 boot0_sdcard_sun20iw1p1_f133.bin
ERROR: Can't found any FEL device  ----  fel

## boot
11714@DESKTOP-VEL6MD9 E:\workspace\d1s-smart\xfel_v1.2.9
> xfel.exe write 8192 boot0_sdcard_sun20iw1p1_f133.bin
100% [================================================] 48.000 KB, 364.927 KB/s

## 
11714@DESKTOP-VEL6MD9 E:\workspace\d1s-smart\xfel_v1.2.9
> xfel.exe sd write 57344 sd.bin
write 7240Kbytes
swap buf:00023E00,len=512, cmdlen=512
Found SD card 126877696 bytes
100% [================================================] 7.070 MB, 219.468 KB/s

## 
11714@DESKTOP-VEL6MD9 E:\workspace\d1s-smart\xfel_v1.2.9
> xfel.exe reset
usb bulk recv error
```

 MobaXterm  **msh** 

```bash
[I/I2C] I2C bus [i2c2] registered

 \ | /
- RT -     Thread Smart Operating System
 / | \     5.0.0 build Oct 20 2022
 2006 - 2020 Copyright by rt-thread team
lwIP-2.0.2 initialized!
winusb class register done.
set samplerate:48000
set samplebits:16
set channels:2
set volume:80%
hal_sdc_create 0
card_detect insert
Initial card success. capacity :121MB
sdmmc bytes_per_secotr:200, sector count:3c800
found part[0], begin: 8388608, size: 90.0MB
found partition:sd0 of mbr at offset 0000000000004000, size:000000000002d000
found part[1], begin: 102760448, size: 23.0MB
found partition:sd1 of mbr at offset 0000000000031000, size:000000000000b800
hal_sdc_create 1
card_detect insert
Initial card success. capacity :7624MB
sdmmc bytes_per_secotr:200, sector count:ee4000
found part[0], begin: 512, size: 4194303.1023GB
found partition:sd0 of mbr at offset 0000000000000001, size:ffffffffffffffff
[I/sal.skt] Socket Abstraction Layer initialize success.
[D/FAL] (fal_flash_init:47) Flash device |                  sdcard0 | addr: 0x00000000 | len: 0x07900000 | blk_size: 0x00000200 |initialized finish.
```

#### ()

 D1s  `sdroot.bin`  `xfel`  `sdmmc`  romfs  `sdmmc` 

**1 romfs **

romfs  emmc  romfs  romfs 

 qemu-riscv64  python  userapps  root   `romfs.c` 

```bash
msh />cd bin
msh /bin>ls
Directory /bin:
syslogd.elf         423024
ping.elf            368104
webserver.elf       510216
hello.elf           366096
em.elf              601336
pong.elf            367024
syslog.elf          391128
vi.elf              528096
hdc_test.elf        367520
ntp.elf             392168
mmapctrl.elf        366992
pmq.elf             371600
webclient.elf       413784
lwIPKit.elf         998504
msh /bin>hello.elf
msh /bin>hello world!
```

**2**

sdroot.bin  emmc 

 RT-Smart 

```
git clone https://github.com/RT-Thread/userapps.git
```

![](figures\MQ1.png)

 rtthread rt-smart  `userapps`  `userapps`  scons  `./mksdcard.sh`  `sdroot.bin`  window  `xfel.exe `  :

```bash
xfel.exe sd write 8388608 sdroot.bin
```



```C
msh />ls
Directory /:
bin                 <DIR>
data                <DIR>
Directory /bin:
syslogd.elf         423024
ping.elf            368104
webserver.elf       510216
hello.elf           366096
em.elf              601336
pong.elf            367024
syslog.elf          391128
vi.elf              528096
hdc_test.elf        367520
ntp.elf             392168
mmapctrl.elf        366992
pmq.elf             371600
webclient.elf       413784
lwIPKit.elf         998504
msh /bin>hello.elf
msh /bin>hello world!
```

## D1S-EMMC 

![](figures/emmc_partition.png)

## Q&A

Q `VSCode` 

A `VSCode` Crtl+Shift+P  `VSCode`  C/C++: **Edit configurations(JSON)**  C/C++

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "${workspaceFolder}/bsp/allwinner/d1s",
                "${workspaceFolder}/include",
                "${workspaceFolder}/components/drivers/include",
                "${workspaceFolder}/bsp/allwinner/libraries/sunxi-hal/include"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "gnu17",
            "cppStandard": "gnu++14",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```

---

Q **mount** 

![](figures/mount.png)

A all_bin/sdroot.bin()  all_bin/sdroot.bin  8388608  mount 

```bash
xfel.exe sd write 8388608 all.bin/sdroot.bin
```
