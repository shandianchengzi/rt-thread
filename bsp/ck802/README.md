CK802

## 

CK802CPU8CPU32CPU BSPFPGA

|  |  |
| ---- | ---- |
| CPU | CK802 |
|  | 600MHz |
| SRAM | 128K |
| FLASH | 256K |

## 

CK802CDKsconscsky-abiv2-elf-toolchain

| IDE/ |  |
| ---------- | --------- |
| CDK | CDK 1.6.0 |
| GCC | (C-SKY Tools V2.10.00(Minilibc), ABIV2, B20161206) 4.5.1 |

sconsRTT_EXEC_PATH

Windows

```shell
RTT_EXEC_PATH=r'D:\c-sky\CSKY\MinGW\csky-abiv2-elf-toolchain\bin'
```

Linux

```shell
RTT_EXEC_PATH=r'/opt/csky-abiv2-elf-tools-x86_64-minilibc-20161211/bin'
```

`scons --exec-path="GCC"`

## BSP

### CDK
#### 
project.cdkproj`Project->Build Active Project``Debug->Start/Stop Debugger``Debug->Continue Debugger`
#### 
`menuconfig``scons --target=cdk`
### Scons

#### 

`RTT_EXEC_PATH`[env](https://www.rt-thread.org/page/download.html)consolebspBSP

```
scons
```

 `scons --exec-path="GCC"` 

#### 

WindowsCSkyDebugServer.exegdb serverDebugServerConsole.exe

LinuxCSkyDebugServer.elfDebugServerConsole.exe

### 

 & RT-Threadlogo

```
\ | /
- RT -     Thread Operating System
 / | \     3.0.4 build Jun  5 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```

## 4. 

|  |   |  |
| ------ | ----  | ------ |
| UART |  | UART 1 |


## 5. 



- [tanek](https://github.com/TanekLiang)
