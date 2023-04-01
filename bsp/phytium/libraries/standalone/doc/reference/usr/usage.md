# 
## 1.1
SDKtftpWindowsLinux
>`sudo`root

### 1.1.1  host Ubuntu 20.04 tftp 

- `host``tftp`

```
sudo apt-get install tftp-hpa tftpd-hpa
sudo apt-get install xinetd
```

-  `tftboot`, `/mnt/d/tftboot`, makefileUSR_BOOT_DIR,  tftboot `chmod 777 /**/tftboot`

-  tftpboot , `/etc/xinetd.d/tftp`

```
# /etc/xinetd.d/tftp

server tftp
{
  socket_type = dgram
  protocol = udp
  wait = yes
  user = root
  server =  /usr/sbin/in.tftpd
  server_args = -s /mnt/d/tftboot
  disable = no
  per_source = 11
  cps = 100 2
  flags = IPv4
}
```
---
Linuxvim
```
vim /etc/xinetd.d/tftp
```
---
- `tftp`

```
$ sudo service tftpd-hpa start
```

- `tftp``tftboot`
  /etc/default/tftpd-hpa
```
vim /etc/default/tftpd-hpa
```

```
$ sudo vim /etc/default/tftpd-hpa
# /etc/default/tftpd-hpa

TFTP_USERNAME="tftp"
TFTP_DIRECTORY="/mnt/d/tftboot"
TFTP_ADDRESS=":69"
TFTP_OPTIONS="-l -c -s"
```

- `tftp`

```
$ sudo service tftpd-hpa restart
```
>Linux`tftp`
- `tftp`
`tftp``tftboot`

```
$ tftp 192.168.4.50
tftp> get test1234
tftp> q
```

### 1.1.2  host Windows tftp 

- `tftp.zip``D:\**\phytium-dev-windows-nt\tftp`
  >`phytium-dev-windows-nt\tftp`
- ****Windows cmd`D:\**\phytium-dev-windows-nt\tftp``.\reinstall.cmd`Tftpd
![](../../fig/admin_rights.png)
![](../../fig/tftp32_srv.png)
  >Windowstftp

### 1.1.3 ipv4
- windows
![](../../fig/ipv4_setting.png)

## 1.2 
- Windows
[MobaXterm_Portable_v22.0](https://pan.baidu.com/s/1IjDG2j5YwK9IhpBR4ChoYA   )
  >ROOT

- Linuxwindows`tftp`SDK`D:\phytium-dev\phytium-standalone-sdk``run_tftd.cmd`tftptftpip
![](../../fig/config_tftp32.png)

### 1.2.1 .elf.bin
WSL:
- SDKWindows
  ```
  wsl
  ```
  ![](../../fig/wsl_teiminal.png)
- `baremetal``uart`wsl
  ```
  cd baremetal/example/peripheral/serial/fpl011_test
  ```
- 3264``32
  ```
  make load_ft2004_aarch32 
  ```
- 
  ```
   make clean boot
  ```
- .elf.bintftboot
![](../../fig/wsl_make_success.png)
![](../../fig/bin_show.png)

### 1.2.2 iphost
- windows
![](../../fig/Serial_inform.png)

- MobaXterm_Portable`Session``Serial``COM3``bps`115200

- `u-boot`ip`host`ip
  ```
  setenv ipaddr 192.168.4.20  
  setenv serverip 192.168.4.50 
  setenv gatewayip 192.168.4.1 
  ```
- `tftboot`
  ```
  tftpboot 0x90100000 baremetal.elf
  bootelf -p 0x90100000
  ```

  > `0x80100000`, `BIN``0x80100000``ELF``DRAM``0x90100000`

- `README.md`
![](../../fig/letter_shell.png)
  
<!-- 
- 1. `AARCH32/AARCH64``BIN``go`

```
# tftpboot 0x80100000 baremetal.bin
# dcache flush
# go 0x80100000
```

- 2. `AARCH32/AARCH64``ELF``DRAM``bootelf`

```
# tftpboot 0x90100000 baremetal.elf
# bootelf -p 0x90100000
```

 -->


<!-- ![](../../fig/config_tftp32.png)

- SDK`D:\phytium-dev\phytium-standalone-sdk``run_tftd.cmd`tftptftpip


- `%PHYTIUM_IDE_PATH%\tftp``tftpboot`

> `template_mingw64``USR_BOOT_DIR`tftp -->
## 1.3 baremetal

### 1.3.1 

- `~/standalone-sdk/example/template` baremetal 

  > `*` /
  ```
  $ ls
  Kconfig       --> menu
  makefile      --> makefile
  main.c        --> main
  sdkconfig     --> 
  sdkconfig.h   --> 
  inc           --> *
  src           --> *
  ```
  >makefileMakefile

### 1.3.2 

- , e.g `FT2000/4 AARCH32`, 

  ```
  make config_ft2004_aarch32
  ```

  > `FT2000-4``make config_ft2004_aarch32``make config_ft2004_aarch64`

  > `D2000``make config_d2000_aarch32``make config_d2000_aarch64`

- , `*.bin`
  ```
  $ make
  $ ls
  template.bin   --> 
  template.dis   --> 
  template.elf   --> ELF
  template.map   --> 
  ```
  ![](../../fig/compiling.png)

### 1.3.3 

- `BIN``ELF``tftpboot`
  ```
  $ cp ./baremetal.bin /mnt/d/tftboot
  $ cp ./baremetal.elf /mnt/d/tftboot
  ```
  > ~/standalone-sdk/example/aarch32_hello_world
  ![](../../fig/load_image.png)
- 1.2