# BM3803

## 1. 

BM3803SPARC V832


|  |  |
| -- | -- |
|| BM3803 |
|CPU| SPARC V8 |
|| 50 - 100MHz |
|SRAM | 2MB |

## 2. 

|  |  |
| --- | --- |
|PC|Windows|
||sparc-gaisler-elf-gcc|
||scons|
1) 
```
git clone https://github.com/RT-Thread/rt-thread.git
```
2) 
```
 https://www.gaisler.com/index.php/downloads/compilers
 https://www.gaisler.com/index.php/downloads/debug-tools
```
3) env
```
envbsp/bm3803
menuconfig
```
4) 
```
rtconfig.pyEXEC_PATH
scons
```
rtthread-bm3803.elfrtthread.binrtthread-bm3803.elf

5) 
```
 https://www.gaisler.com/eclipse/qsg_sw_ide.pdf
```
