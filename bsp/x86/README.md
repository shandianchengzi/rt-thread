# RT-Thread for x86

RT-Threadx86qemuLinuxWindowsEnviso

## 

RT-Thread for x86newlib

*[i386-unknown-elf_for_x86_64-pc-linux-gnu_latest.tar.bz2](http://117.143.63.254:9012/www/rt-smart/i386-unknown-elf_for_x86_64-pc-linux-gnu_latest.tar.bz2)

rtconfig.pyEXEC_PATH

```python
if  CROSS_TOOL == 'gcc':
    PLATFORM    = 'gcc'
    EXEC_PATH   = os.getenv('RTT_EXEC_PATH') or 'E:/Program Files/CodeSourcery/Sourcery_CodeBench_Lite_for_IA32_ELF/bin'

```

x86 bspscons

```bash
scons
```

### 

RT-Thread for x86menuconfigLinux`scons --menuconfig`

menuconfigKconfigubuntuncurses5

```bash
sudo apt install libncurses5-dev
```

## 

ubuntu`qemu-system-i386``grub`  `xorriso`

```bash
sudo apt install qemu-system-x86 grub-common xorriso
```

`./run.sh`qemu(iso)

```bash
~/workspace/rt-thread/bsp/x86$ ./run.sh
xorriso 1.4.8 : RockRidge filesystem manipulator, libburnia project.

Drive current: -outdev 'stdio:bootable.iso'
Media current: stdio file, overwriteable
Media status : is blank
Media summary: 0 sessions, 0 data blocks, 0 data,  135g free
Added to ISO image: directory '/'='/tmp/grub.uLz91i'
xorriso : UPDATE : 578 files added in 1 seconds
Added to ISO image: directory '/'='/home/bernard/workspace/rt-thread/bsp/x86/root'
xorriso : UPDATE : 582 files added in 1 seconds
xorriso : NOTE : Copying to System Area: 512 bytes from file '/usr/lib/grub/i386-pc/boot_hybrid.img'
ISO image produced: 6007 sectors
Written to medium : 6007 sectors at LBA 0
Writing to 'stdio:bootable.iso' completed successfully.


 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Aug 22 2021
 2006 - 2021 Copyright by rt-thread team
Floppy Inc : NEC765B controller  Floppy Type : 2.88MB
hello!
msh />
```

qemuCtrl-A + Xqemu
