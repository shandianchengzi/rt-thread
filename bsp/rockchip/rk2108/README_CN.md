# Rockchip RK2108 BSP

---

****

[TOC]

---

## 

Rockchip RK2108 ARM Cortex-M4F with CacheBSP

```shell
bsp/rockchip
|-- common
|   |-- drivers                     # RT-Thread OS
|   |-- rk_hal                      # Rockchip HAL 
|   |   |-- lib
|   |   |   |-- bsp                 # 
|   |   |   |-- CMSIS               # CMSIS
|   |   |   `-- hal                 # HAL 
|-- rk2108
|   |-- application                 # 
|   |-- board                       # 
|   |   |-- common                  # 
|   |   `-- rk2108_evb              # rk2108_evb 
|   |-- driver                      # RK2108 
|   `-- image                       # 
`-- tools                           # Rockchip 
```

## 

### 

bsp/rockchip/rk2108

```shell
cd bsp/rockchip/rk2108
./mkimage.sh
```

### 

Rockchipresource_header_toolfirmware_mergersetting.inimkimage.shFirmware.img

loader

- rk2108_loader.binloaderrtthread.bin
- rk2108_loader_fake.binRockchipIDBlockbinpsrampsram.binloader_fake.bin
- rk2108_db_loader.binloader

### 

maskromresetmaskrom

LinuxRockchipupgrade_tool

```shell
sudo ./upgrade_firmware.sh
```

sudorule.dRockchiprw/etc/udev/rules.d70-usbboot.rules70-usbboot.rules

```shell
cd /etc/udev/rules.d
sudo touch 70-usbboot.rules
```

70-usbboot.rules2207Rockchip USBVID

```shell
SUBSYSTEM=="usb", ATTRS{idVendor}=="2207", GROUP="plugdev", MODE="0666", ENV{ID_MM_DEVICE_IGNORE}="1"
```

Rockchipupgrade_tool

```shell
./upgrade_firmware.sh
```

WindowsRockchipRKDevToolDriverAssitantRockchip

## 

Steven Liu : steven.liu@rock-chips.com
