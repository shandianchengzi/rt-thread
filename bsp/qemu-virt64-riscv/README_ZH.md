# QEMU/RISCV64 VIRT

 | [English](README.md)

## 1. 

RISC-V(ISA)QEMURISCV64 VIRT

## 2. 

,sifive
```
https://www.sifive.com/software
```


Ubuntu



```
export RTT_EXEC_PATH=~/gcc/bin
```

`rt-thread/bsp/qemu-virt64-riscv`
```
scons
```
`rtthread.elf``rtthread.bin`

 `scons --exec-path="GCC"` 

## 3. 

riscv64,M-Mode

*M-Mode*

`qemu-system-riscv64`

```
sudo apt install qemu-system-misc
```

```
./qemu-nographic.sh
```


```
heap: [0x80035804 - 0x86435804]

 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build May 21 2021
 2006 - 2021 Copyright by rt-thread team
Hello RISC-V!
msh />
```

*S-Mode*

S-Modemenuconfig

```
scons --menuconfig
```

```
RISCV qemu virt64 configs  ---> 
    [*] RT-Thread run in riscv smode
```
`scons`

rt-threadS-Modeopensbi,opensbirt-thread

qemuqemuopensbi`./qemu-nographic-smode.sh`

`sudo apt install qemu-system-misc`qemuopensbi

```
git clone git@github.com:riscv/opensbi.git
cd opensbi
make PLATFORM=generic CROSS_COMPILE=~/gcc/bin/riscv64-unknown-elf-
```
`/build/platform/generic/firmware/fw_jump.elf`

:

```
qemu-system-riscv64 -nographic -machine virt -m 256M -kernel rtthread.bin -bios ~/opensbi/build/platform/generic/firmware/fw_jump.elf
```

```
OpenSBI v0.9
   ____                    _____ ____ _____
  / __ \                  / ____|  _ \_   _|
 | |  | |_ __   ___ _ __ | (___ | |_) || |
 | |  | | '_ \ / _ \ '_ \ \___ \|  _ < | |
 | |__| | |_) |  __/ | | |____) | |_) || |_
  \____/| .__/ \___|_| |_|_____/|____/_____|
        | |
        |_|

Platform Name             : riscv-virtio,qemu
Platform Features         : timer,mfdeleg
.
.
.
Boot HART ISA             : rv64imafdcsu
Boot HART Features        : scounteren,mcounteren
Boot HART PMP Count       : 16
Boot HART PMP Granularity : 4
Boot HART PMP Address Bits: 54
Boot HART MHPM Count      : 0
Boot HART MHPM Count      : 0
Boot HART MIDELEG         : 0x0000000000000222
Boot HART MEDELEG         : 0x000000000000b109
heap: [0x80235a58 - 0x86635a58]

 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build May 21 2021
 2006 - 2021 Copyright by rt-thread team
Hello RISC-V!
msh />
```
## 4. 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART0 |
| PLIC |  | - |
| CLIC |  | - |

## 5. 

[bernard][1]

[1]: https://github.com/BernardXiong
