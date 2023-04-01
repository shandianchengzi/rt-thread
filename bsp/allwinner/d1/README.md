# RT-ThreadD1

 d1-allwinner-nezha  riscv64 

## 

-  RT-Thread Smart `git clone https://gitee.com/guozhanxin/rtthread-smart.git`

### windows 

-  RT-Thread ENV 

-  tools  `cd tools`

-  `riscv64` `python get_toolchain.py riscv64`

-  `cd ..`

-  `./smart-env.bat`

### ubuntu 

-  ubuntu shell 

-  tools  `cd tools`

-  `riscv64` `python get_toolchain.py riscv64`

-  `cd ..`

-  `source smart-env.sh riscv64`

### 

- `riscv64-unknown-linux-musl-gcc -v`

## 

- windows RT-Thread ENV  `menuconfig` `scons` 

- ubuntu  shell  `scons --menuconfig`  `scons` 


## 

- mkimage  img img  U-boot 

- SDNandFlash

- windows `AllwinnertechPhoeniSuitRelease20201225`

-  xfel NandFlash

## 

```c
## Booting kernel from Legacy Image at 45000000 ...
   Image Name:   
   Image Type:   RISC-V Linux Kernel Image (uncompressed)
   Data Size:    249576 Bytes = 243.7 KiB
   Load Address: 45000000
   Entry Point:  45000000
   Verifying Checksum ... OK
[01.861]
Starting kernel ...
heap: [0x45077bb0 - 0x48277bb0]
 \ | /
- RT -     Thread Smart Operating System
 / | \     5.0.0 build Jun 18 2022
 2006 - 2020 Copyright by rt-thread team
file system initialization done!
Hello RISC-V
msh />

```

## 

- [https://club.rt-thread.org/ask/article/389ac36250b57737.html](https://club.rt-thread.org/ask/article/389ac36250b57737.html)





