# RK3568 

 | [English](README.md)

## 1. 

RK3568  SOC 22nm  2GHzCortex-A55  Mali G52 GPU 4K  1080P  SATA/PCIE/USB3.0  0.8T NPU AI LPDDR4 

 RT-Thread BSP RK3568  RADXA ROCK 3A  RK3568 4B

## 2. 

ARM Developer GNULinux/Windows
```
https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads/
```
x86_64 Hosted`xxx-aarch64-none-elf``RTT_EXEC_PATH`bin

`rt-thread/bsp/rockchip/rk3568`
```
scons
```
`rtthread.elf``rtthread.bin`

 `scons --exec-path="GCC"` 

## 3. 

RK3568  Kernel  SD [](https://wiki.t-firefly.com/zh_CN/ROC-RK3568-PC/hardware_doc.html)|[RADXA ROCK 3A](https://wiki.radxa.com/Rock3/install/microSD)

 Kernel `rtthread.bin` EFI `boot.cmd`
```shell
fatload mmc 1:1 0x208000 /rtthread.bin;dcache flush;go 0x208000
```
`boot.scr`:
```shell
# Linux  uboot-mkimage Windows  MSYS2  u-boot-tools 
mkimage -C none -A arm -T script -d boot.cmd boot.scr
```

 UART0~9 UART2[](https://wiki.t-firefly.com/zh_CN/ROC-RK3568-PC/debug.html)|[RADXA ROCK 3A](https://wiki.radxa.com/Rock3/dev/serial-console) 1500000

```
heap: [0x002663f0 - 0x042663f0]

 \ | /
- RT -     Thread Operating System
 / | \     4.1.0 build Mar 19 2022 17:17:29
 2006 - 2022 Copyright by RT-Thread team
Hi, this is RT-Thread!!
msh />
```

## 4.

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0~9 |
