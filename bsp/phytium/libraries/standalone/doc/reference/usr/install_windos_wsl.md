
# 1. WindowsWSL Linux SDK


WindowsWSL LinuxLinuxLinuxWindows
Linux x86_64SDK`Linux x86_64`
```
uname -a
```
![linux-x86_64](../../fig/is_x86_64.png)

SDK

## 1.1 SDK

- [Linux x86_64](https://pan.baidu.com/s/1KsGcHoqOJ8nv4G1G-L5gtQ  )

>LX64

WindowsWSL Linux
- [WSL Linux](https://zhuanlan.zhihu.com/p/146545159)

Ubuntu
- [WSL ](https://blog.csdn.net/qq_18625805/article/details/109732122)

cmdWSL
```
wsl -l -v
```
WSL2WSL2WSL1
```
wsl --set-version Ubuntu-20.04 1
```

>20.04Ubuntu


![wsl_l_v](../../fig/wsl_l_v.png)
Linux
```
apt update
apt upgrade
```
Linuxgit, makepython3
```
sudo apt-get install build-essential
```

## 1.2 SDK

- (1). DEV

![DEV](../../fig/uncompress_for_x86.png)

Linux x86_64
- `gcc-arm-10.3-2021.07-x86_64-aarch64-none-elf.tar.xz``gcc-arm-10.3-2021.07-x86_64-arm-none-eabi.tar.xz`aarch64SDKDEV`cross_tool`
- `setup_dev.py`, sdkprofile`PHYTIUM_DEV_PATH`gitSDKSDK


- (2). DEV`./setup_dev.py`

![](../../fig/setup_x86_dev.png)
**
```
python3 setup_dev.py
```
>[5]`source /etc/profile.d/phytium_dev.sh`

- (3). gitPhytium Standalone SDK

```
git clone https://gitee.com/phytium_embedded/phytium-standalone-sdk.git ./phytium-standalone-sdk
```

- (4). Phytium Standalone SDK`./install.py`

```
cd ./phytium-standalone-sdk
./install.py
```
![](../../fig/install_for_x86.png)

- (5). 

### Q: 

- 2Phytium Standalone SDKDEV
- https://gitee.com/phytium_embedded/phytium-standalone-sdk

## 1.3 

- 
> `PHYTIUM_DEV_PATH`DEV

> `STANDALONE_SDK_ROOT`SDK

> `AARCH32_CROSS_PATH`32

> `AARCH64_CROSS_PATH`64

```
echo $PHYTIUM_DEV_PATH $STANDALONE_SDK_ROOT $AARCH32_CROSS_PATH $AARCH64_CROSS_PATH 
```
![](../../fig/check_env_for_x86.png)

- ****
## 1.4 

- DEV`./uninstall.py`SDK

- `rm /etc/profile.d/phytium_standalone_sdk.sh`SDK

- 
