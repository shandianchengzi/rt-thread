# D1 RT-Smart

### 

 RT-Smart 

```
git clone https://github.com/RT-Thread/userapps.git
```

![](figures/MQ1.png)

 `userapps`  RT-Thread rt-smart 

```shell
git clone -b rt-smart https://gitee.com/rtthread/rt-thread.git
```

![](figures/MQ2.png)

### 

 userapps\tools  `get_toolchain.py`  userapps\tools\gun_gcc  arm | riscv64

 D1S  RISCV-64 

```
python3 get_toolchain.py riscv64
```

 userapps  `smart-env.sh`  arm | riscv64

```
source smart-env.sh riscv64
```

![](figures/MQ3.png)


### 

 `rt-thread/bsp/allwinner/d1s` 

*  env `scons --menuconfig`  env

```shell
source ~/.env/env.sh
pkgs --update
```

 scons  `userapps/rt-thread/bsp/allwinner/d1s`  sd.bin uboot.dtbopensbirtthread.bin

### 

1 128G  TF

2 fdisk  TF  ubuntu  df  32GB TF 512  8M 16384`sudo fdisk /dev/sdb`onp116384

```shell
Command (m for help): o
Created a new DOS disklabel with disk identifier 0x3668b987.

Command (m for help): n
Partition type
   p   primary (0 primary, 0 extended, 4 free)
   e   extended (container for logical partitions)
Select (default p): p
Partition number (1-4, default 1): 1
First sector (2048-62410751, default 2048): 16384
Last sector, +sectors or +size{K,M,G,T,P} (16384-62410751, default 62410751): 

Created a new partition 1 of type 'Linux' and of size 29.8 GiB.

Command (m for help): w
The partition table has been altered.
```



![](figures/MQ5.png)

 sdb1  fat32 

```shell
$ sudo mkfs -t fat /dev/sdb1
```

 **Gparted** 

![](figures/MQ6.png)

3 RT-SMART 

```shell
sudo dd if=boot0_sdcard_sun20iw1p1.bin of=/dev/sdb bs=1024 seek=8
sudo dd if=sd.bin of=/dev/sdb bs=1024 seek=56
```

* **boot0_sdcard_sun20iw1p1.bin**  `userapps/rt-thread/bsp/allwinner/d1s/tools` 
*  /dev/sdb 



![](figures/MQ7.png)

###  RT-Smart

TF 

 TF 078 500000 RT-Smart 

![](figures/MQ8.png)

```shell
 \ | /
- RT -     Thread Smart Operating System
 / | \     5.0.0 build Nov  1 2022
 2006 - 2022 Copyright by rt-thread team
lwIP-2.0.2 initialized!
hal_sdc_create 0
card_detect insert
Initial card success. capacity :30436MB
sdmmc bytes_per_secotr:200, sector count:3b72400
found part[0], begin: 8388608, size: 29.732GB
found partition:sd0 of mbr at offset 0000000000004000, size:0000000003b6e400
hal_sdc_create 1
card_detect insert
Initial card failed!!
[E/drv-sdmmc] init sdmmc failed!
[E/drv-sdmmc] sdmmc_init failed!
[I/sal.skt] Socket Abstraction Layer initialize success.
[D/FAL] (fal_flash_init:47) Flash device |                  sdcard0 | addr: 0x00000000 | len: 0x76e480000 | blk_size: 0x00000200 |initialized finish.
[I/FAL] ==================== FAL partition table ====================
[I/FAL] | name       | flash_dev |   offset   |    length  |
[I/FAL] -------------------------------------------------------------
[I/FAL] | download   | sdcard0   | 0x00800000 | 0x00800000 |
[I/FAL] | easyflash  | sdcard0   | 0x01000000 | 0x00100000 |
[I/FAL] | filesystem | sdcard0   | 0x01100000 | 0x00c00000 |
[I/FAL] =============================================================
[I/FAL] RT-Thread Flash Abstraction Layer initialize success.
Hello RISC-V
[W/DBG] disp:[parser_disp_init_para 575]of_property_read screen1_output_type fail
msh />Mount "sd0p0" on "/" success
msh />
```

### 

 `userapps`  scons  `root/bin` 

![](figures/MQ9.png)

### 

 `root/bin`  hello  TF 

![](https://oss-club.rt-thread.org/uploads/20221101/f7709c3708b1d45f496e10c040d99f10.png)

 TF  helloworld 

```shell
msh /bin>ls
Directory /bin:
dbkit_client.elf    616960
elmFATKit.elf       373880
em.elf              585504
hdc_test.elf        339976
hello.elf           339624
lvgl.elf            1382168
lwIPKit.elf         976784
mmapctrl.elf        339976
ntp.elf             363560
ping.elf            344208
pmq.elf             345176
pong.elf            339624
syslog.elf          364736
syslogd.elf         377560
vi.elf              446568
webclient.elf       358048
msh /bin>
msh /bin>hello.elf
msh /bin>hello world!
```
