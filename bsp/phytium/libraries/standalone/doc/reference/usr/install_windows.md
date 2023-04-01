# 1. Windows10 SDK

Windows 10 SDK
- `msys64`Msys2 portable, WindowsshellCygwin POSIX   MinGW-w64"MinGW-"
- `setup_dev.py`, sdkprofile`PHYTIUM_DEV_PATH`gitSDKSDK
- `gcc-arm-10.3-2021.07-mingw-w64-i686-aarch64-none-elf.tar.xz``gcc-arm-10.3-2021.07-mingw-w64-i686-arm-none-eabi.tar.xz`, mingw64, SDKDEV`cross_tool`
- `tftp`, tftp, tftptftp32tftp
- `run_msys2.cmd`msys2 shell`PHYTIUM_DEV_PATH`
- `run_tftd.cmd`tftpd`PHYTIUM_DEV_PATH`
- `tftp/reinstall.cmd`, tftpd
- `tftp/uninstall.cmd`, tftpd

## 1.1 SDK

- [Windows10](https://pan.baidu.com/s/1V96isNcPq4F7nKi3_8GoGg) 
>WX64

- Windowsunzip7zipwinrar

## 1.2 SDK

- (1). Windows`PHYTIUM_DEV_PATH`(****)`E:\phytium-dev-windows-nt`

![](../../fig/add_path_for_win.png)

- (2). DEV`run_msys2.cmd`, msys2, `./setup_dev.py`

![](../../fig/install_for_mingw.png)

-3). DEVgitPhytium Standalone SDK

```
git clone https://gitee.com/phytium_embedded/phytium-standalone-sdk.git ./phytium-standalone-sdk
```

- (4). Phytium Standalone SDK`./install.py`

```
cd ./phytium-standalone-sdk
./install.py
```

![](../../fig/setup_win.png)

- (5). 

### Q: 

- 2Phytium Standalone SDKDEV
- https://gitee.com/phytium_embedded/phytium-standalone-sdk

![SDK](../../fig/git_url.png)

## 1.3 

- 
> `PHYTIUM_DEV_PATH`DEV

> `STANDALONE_SDK_ROOT`SDK

> `AARCH32_CROSS_PATH`32

> `AARCH64_CROSS_PATH`64

```
echo $PHYTIUM_DEV_PATH $STANDALONE_SDK_ROOT $AARCH32_CROSS_PATH $AARCH64_CROSS_PATH 
```

- ****
## 1.4 Windows 10Msys2

- (1). [Windows](https://pan.baidu.com/s/17WX5hec7t8_ubAKzFCwQAA)

> MGW6

- msys2, `msys2-x86_64-20210725.exe`
- mingw64-arm, `gcc-arm-10.3-2021.07-mingw-w64-i686-arm-none-eabi.tar.xz`, `gcc-arm-10.3-2021.07-mingw-w64-i686-aarch64-none-elf.tar.xz`
- tftp`tftp.zip`

- (2). WindowsDEV`D:/phytium-dev`, DEVWindows`PHYTIUM_DEV_PATH`

> Windows 10

> DEV

![](../../fig/add_path_for_win.png)

- (3). DEV`echo %PHYTIUM_DEV_PATH%`

![](../../fig/check_env_for_win.png)

- (4). `msys2-x86_64-20210725.exe``Msys2`DEVMsys2

![](../../fig/install_msys2.png)

![Msys2](../../fig/installing_msys2.png)

- (5). `Msys2``D:\phytium-dev\msys64\etc\pacman.d`

- mirrorlist.mingw32
```
Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/i686
```

- mirrorlist.mingw64
```
Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/x86_64
```

- mirrorlist.msys
```
Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/msys/$arch
```

- (6). `D:\phytium-dev\msys64``msys2_shell.cmd``Msys2``Msys2`

> 

> `default``y``default = all``y`

```
$ pacman -Syu
$ pacman -S  mingw-w64-x86_64-toolchain
$ pacman -S  base-devel git python3 python3-pip
```

![Msys2](../../fig/update_packman.png)

- (7). 
```
$ pacman -Q make git wget python3 python3-pip
```

## 1.5 

- DEV`run_msys2.cmd`, `Msys2``./uninstall.py`SDK

- `Msys2``rm /etc/profile.d/phytium_standalone_sdk.sh`SDK

- DEV`D:\phytium-dev\tftp`****Windows`uninstall.cmd`Tftd

- 