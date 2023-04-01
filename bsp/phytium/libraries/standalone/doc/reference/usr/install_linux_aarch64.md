# 1. Linux arm aarch64 SDK

Linux arm aarch64SDK`./setup_dev.py``Linux arm aarch64`

![linux-aarch64](../../fig/is_aarch64.png)

Linux arm aarch64:
- `gcc-arm-10.3-2021.07-aarch64-aarch64-none-elf.tar.xz``gcc-arm-10.3-2021.07-aarch64-arm-none-eabi.tar.xz`,aarch64SDKDEV`cross_tool`
- `setup_dev.py`, sdkprofile`PHYTIUM_DEV_PATH`gitSDKSDK


## 1.1 SDK

- [Linux arm aarch64](https://pan.baidu.com/s/1lQC4n8wRDSLAMTXvzPn98g)

> LA64

- Linuxunzip
- Linux`sudo apt-get install build-essential`git, makepython3

## 1.2 SDK

- (1). DEV

- (2). DEV`./setup_dev.py`

![](../../fig/setup_aarch64_dev.png)

- (3). gitPhytium Standalone SDK

```
git clone https://gitee.com/phytium_embedded/phytium-standalone-sdk.git ./phytium-standalone-sdk
```

- (4). Phytium Standalone SDK`./install.py`

```
cd ./phytium-standalone-sdk
./install.py
```

![](../../fig/install_for_aarch64.png)

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
echo $PHYTIUM_DEV_PATH 
echo $STANDALONE_SDK_ROOT 
echo $AARCH32_CROSS_PATH 
echo $AARCH64_CROSS_PATH 
```
![](../../fig/check_env_for_aarch64.png)

- ****
## 1.4 

- DEV`./uninstall.py`SDK

- `rm /etc/profile.d/phytium_standalone_sdk.sh`SDK

- 