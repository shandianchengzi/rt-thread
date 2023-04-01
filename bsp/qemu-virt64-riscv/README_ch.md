# RT-Smart QEMU SYSTEM RISC-V RV64 BSP

 | [English](./README.md)

## 1. 

QEMU System RISC-V 64  virt BSP

## 2. 

1.  [rt-smart SDK](http://117.143.63.254:9012/www/rt-smart/) risc-v 64.
1.  `RTT_EXEC_PATH`  bin ,  `/home/user/xxx/yyy/bin`
1.  `RTT_CC_PREFIX` ,  `riscv64-unknown-linux-musl-`
1.  `RTT_CC` ,  `gcc`
1.  `riscv64-unknown-linux-musl-gcc -v`  -march  -mabi
1.  `rtconfig.py:40`  `DEVICE  = ' -mcmodel=medany -march=rv64imac -mabi=lp64 '`
1. `scons --menuconfig`
    *  `-march`  `v`,  `Using RISC-V Vector Extension`, 
    *  `-march`  `f/d`,  `Enable FPU`, 
1. `scons`

## 3. 

 qemu qemu  `qemu-system-riscv64 --version`

 `qemu-nographic.sh`/`qemu-nographic.bat` 

> if your -march contains characters v, using qemu-v-nographic.*
