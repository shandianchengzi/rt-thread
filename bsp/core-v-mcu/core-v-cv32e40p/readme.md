# Core-V-MCU BSP 

[English](readme_EN.md) | ****

## 1 MCU

Core-V-MCUcv32e40pOpen Hardware Group(OpenHW)RISC-Vcv32e40p

![CORE-V-MCU_Block_Diagram](figures/CORE-V-MCU_Block_Diagram.png)

**Core-V-MCU**

- 2xUART
- 2xI2C master
- 1xI2C slave
- 2xQSPI master
- 1xCAMERA
- 1xSDIO
- 4xPWM
- eFPGA with 4 math units

[Core-V-MCU](https://docs.openhwgroup.org/projects/core-v-mcu/doc-src/overview.html)

[OpenHW](https://www.openhwgroup.org/)

## 2 

 RISC-V GCC 

| IDE/ |               |
| ---------- | ----------------------- |
| GCC        | riscv32-unknown-elf-gcc |

## 3 

>Core-V-MCURT-ThreadCore-V-MCUQEMU,qemuubuntu18.04qemu

### 3.1 EnvBSP

EnvBSP

#### 3.1.1 BSP

1. 1[LinuxGCC](https://github.com/Yaochenger/openhw-/tree/master/toolchain))Linux

2. 2LinuxENV

   ```shell
   wget https://gitee.com/RT-Thread-Mirror/env/raw/master/install_ubuntu.sh
   chmod 777 install_ubuntu.sh
   ./install_ubuntu.sh --gitee
   ```

3. 3LinuxPLCT[qemu]([plctlab/plct-qemu at plct-corev-upstream-sync-dma (github.com)](https://github.com/plctlab/plct-qemu/tree/plct-corev-upstream-sync-dma)),README.rstLinuxqemu[qemu](https://github.com/Yaochenger/openhw-/releases/tag/qemu-linux)

4. WindowsRT-Thread[](https://github.com/RT-Thread/rt-thread/archive/refs/heads/master.zip)Linux

5. WindowsBSPEnv,`scons --exec-path=`WindowsRT-StudioLinux

   ```shell
   scons --exec-path=D:\RT-ThreadStudio\repo\Extract\ToolChain_Support_Packages
   \RISC-V\RISC-V-GCC-RV32\2022-04-12\bin
   ```

    rtthread.elf

   ![compilation result of core-v-mcu ](figures/compilation result of core-v-mcu .png)

6. rtthread.elfrtthread.elfqemubin

   ```shell
   ./qemu-system-riscv32 -M core_v_mcu -bios none -kernel rtthread.elf -nographic -monitor none -serial stdio
   ```

   

   ![test-result1](figures/test-result1.png)

   7. 

```shell
scons --dist
```

Linux

### 3.2Liunx

#### 3.2.1 

1.**rtconfig.h**,**#ifndef RT_CONFIG_H__**,**#define RT_CONFIG_H__**,**#ifndef RT_CONFIG_H__**,**#endif**,

![remove ifdef](figures/remove ifdef.png)

2.makefile

```shell
scons --target=makefile
```

3.**make**

4.qemurtthread.elf`/home/wangshun/bin/qemu-riscv/bin/qemu-system-riscv32`Linux

```shell
/home/wangshun/bin/qemu-riscv/bin/qemu-system-riscv32 -M core_v_mcu -bios none -kernel rtthread.elf -nographic -monitor none -serial stdio
```

BSPRT-ThreadFinshversionrt-threadTap

![test-result2](figures/test-result2.png)

Core-V-MCURT-Thread

### 3.3 RT-ThreadOpenHWCore-V-IDE

1.[core-v-sdk](https://github.com/openhwgroup/core-v-sdk),[README.md](https://github.com/openhwgroup/core-v-sdk#readme)LinuxIDE

2.workspaceIDEworkspace

3.`Import projects `

![import_2](figures/import_2.png)

4.`Existing Code as Makefile Project`

![makefile project](figures/makefile project.png)

5.

![settings](figures/settings.png)

6.

![Properites](figures/Properites.png)

7.

![make](figures/make.png)

8.

![IDE-MAKE](figures/IDE-MAKE.png)

9.IDE**3.2.1**IDEIDECore-V-MCURT-Thread

```shell
/home/wangshun/bin/qemu-riscv/bin/qemu-system-riscv32 -M core_v_mcu -bios none -kernel rtthread.elf -nographic -monitor none -serial stdio
```

### 3.4

1.Debug Configurations 

![debug](figures/debug.png)

2.`GDB OpenOCD Debugging`

![openocd](figures/openocd.png)

3.

`OpenHW/CORE-V-SDKv0.0.0.4/registers/csr`,SDK

![register file](figures/register file.png)

3.

`/home/wangshun/OpenHW/CORE-V-SDKv0.0.0.4/registers/peripheral`,SDK

![svd](figures/svd.png)

3.qemu

`Start OpenOCD locally`

![debug2](figures/debug2.png)

4.

```shell
/home/wangshun/bin/qemu-riscv/bin/qemu-system-riscv32 -M core_v_mcu -bios none -kernel rtthread.elf -nographic -monitor none -serial stdio -s -S
```

5.debug

 ![run](figures/run.png)

### 4.CLI

	OPENHWFreeRTOSCLIRT-ThreadCLICLIFreeRTOSCLIFreeRTOSAPIRT-ThreadAPI

#### 4.1

	ENVmenuconfigCorevMCU_CLexample.cmain.cmenuconfig

> `RT-Thread online packages`
>     `miscellaneous packages --->`
>        ` [*] CorevMCU_CLI`

