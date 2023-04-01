# QEMU/AArch64 VIRT

 | [English](README.md)

## 1. 

AArch64ARMv8 ISAA6464QEMUAArch64 VIRT

## 2. 

ARM Developer GNULinux/Windows
```
https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads/
```
x86_64 Hosted`xxx-aarch64-none-elf``RTT_EXEC_PATH`bin

`rt-thread/bsp/qemu-virt64-aarch64`
```
scons
```
`rtthread.elf``rtthread.bin`

 `scons --exec-path="GCC"` 

## 3. 

`qemu-system-aarch64``Cortex-A53/A57/A72`GIC`V2/V3``V2`8

WindowsQEMU
```
https://www.qemu.org/download/
```
LinuxUbuntuDeepinQEMU
```
sudo apt update
sudo apt install qemu-system-arm
```

qemu.batqemu.sh
```
heap: [0x40042aa0 - 0x40142aa0]

 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Aug  6 2021
 2006 - 2021 Copyright by rt-thread team
Hi, this is RT-Thread!!
msh />
```

VirtIO-Console
```
telnet 127.0.0.1 4321
```

taptap0qemu
```
-netdev user,id=net0
```

```
-netdev tap,id=net0,ifname=tap0
```

## 4.

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0 |
| RTC  |  | - |
| GPIO |  | - |
| VIRTIO BLK |  | - |
| VIRTIO NET |  | - |
| VIRTIO Console |  | - |
| VIRTIO GPU |  | 2D |
| VIRTIO Input |  | Keyboard, Mouse, Tablet |