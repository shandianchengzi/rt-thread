# bouffalo_lab bsp

## 1. 

bouffalo_lab bspbouffalo_labAIoTbouffalo_lab**LHAL** [bl_mcu_sdk](https://github.com/bouffalolab/bl_mcu_sdk) commitid:`47c662afae69309fd49d2721b5c9b93219a91af7`



|      |                  |                                      |
| ---- | :----------------------- | ---------------------------------------- |
| 1    | bl60x(bl602/bl604)       | RISC-V SiFive E24                        |
| 2    | bl70x(bl702/bl704/bl706) | RISC-V SiFive E24                        |
| 3    | bl61x(bl616/bl618)       | RISC-V T-Head E907                       |
| 4    | bl808                    | RISC-V T-Head E902(lp)+E907(m0)+C906(d0) |

**LHAL** 

|      | BL602/BL604 | BL702/BL704/BL706 | BL616/BL618 | BL808 |
| :------: | :---------: | :---------------: | :---------: | :---: |
|   ADC    |            |                  |            |      |
|   CAM    |      -      |                  |            |      |
|   CKS    |            |                  |            |      |
|   DAC    |            |                  |            |      |
|   DMA    |            |                  |            |      |
|  EFUSE   |            |                  |            |      |
|   EMAC   |      -      |                  |            |      |
|  FLASH   |            |                  |            |      |
|   GPIO   |            |                  |            |      |
|   I2C    |            |                  |            |      |
|   I2S    |            |                  |            |      |
|    IR    |            |                  |            |      |
|  MJPEG   |            |                  |            |      |
|  PWM_v1  |            |                  |      -      |   -   |
|  PWM_v2  |      -      |         -         |            |      |
|   RTC    |            |                  |            |      |
| SEC_AES  |            |                  |            |      |
| SEC_SHA  |            |                  |            |      |
| SEC_TRNG |            |                  |            |      |
| SEC_PKA  |            |                  |            |      |
|   SPI    |            |                  |            |      |
|  TIMER   |            |                  |            |      |
|   UART   |            |                  |            |      |
|  USB_v1  |      -      |                  |      -      |   -   |
|  USB_v2  |      -      |         -         |            |      |
|   WDG    |            |                  |            |      |

**** **** **** **-** 



## 2.  

bl60x/bl70x/bl61xbl808m0lpd0

bl61x

### 2.1. 



|     |                                                      |
| ----------- | ------------------------------------------------------------ |
| bl60x/bl70x | [Linux](https://gitee.com/bouffalolab/toolchain_gcc_sifive_linux)/[windows](https://gitee.com/bouffalolab/toolchain_gcc_sifive_windows) |
| bl61x/bl808 | [T-Head](https://occ.t-head.cn/community/download?id=4073475960903634944)[Linux](https://gitee.com/bouffalolab/linuxtoolchain_gcc_t-head)/[windows](https://gitee.com/bouffalolab/toolchain_gcc_t-head_windows) |

### 2.2. 

Windows[env][1] `tar -xvf Xuantie-900-gcc-elf-newlib-mingw-V2.6.1-20220906.tar.gz` WindowsWindows

`rtconfig.py`risc-v `EXEC_PATH`  `RTT_EXEC_PATH` 

Windows

```
set RTT_EXEC_PATH=C:\Users\xxxx\Downloads\Xuantie-900-gcc-elf-newlib-x86_64-V2.6.1\bin
```

Linux:

```
export RTT_EXEC_PATH=/opt/Xuantie-900-gcc-elf-newlib-x86_64-V2.6.1/bin
```

### 2.3. 

Windows[env][1]consolebsp/bouffalo_lab/bl61x

    cd bsp/bouffalo_lab/bl61x
    menuconfig
    pkgs --update

Linux

    scons --menuconfig

env~/.env

    source ~/.env/env.sh
    
    cd bsp/bouffalo_lab/bl61x
    pkgs --update

 `scons -j10`  `scons -j10 --verbose`  `scons --exec-path="GCC"` 

rtthread.elfrtthread.bin`libraries/bl_mcu_sdk/tools/bflb_tools/bflb_fw_post_proc`rtthread.bin`bouffalo_flash_cube`

curl`bflb_fw_post_proc``libraries/bl_mcu_sdk/tools/bflb_tools/bflb_fw_post_proc`

[windows](https://raw.githubusercontent.com/bouffalolab/bl_mcu_sdk/master/tools/bflb_tools/bflb_fw_post_proc/bflb_fw_post_proc.exe)

[Linux](https://raw.githubusercontent.com/bouffalolab/bl_mcu_sdk/master/tools/bflb_tools/bflb_fw_post_proc/bflb_fw_post_proc-ubuntu)

[macos](https://raw.githubusercontent.com/bouffalolab/bl_mcu_sdk/master/tools/bflb_tools/bflb_fw_post_proc/bflb_fw_post_proc-macos)

## 3. 

### 3.1. GUI

bsp[bouffalo_flash_cube-1.0.4](https://pan.baidu.com/s/1eG9pkxf3riAqQAu9aXiOjw?pwd=miv1)

1. 

2. flash_prog_cfg.ini

3. boot

4. "Download"

![Flash Download](figures/bouffalo_flash_cube.jpg)

### 3.2. 

`bsp/bouffalo_lab``bouffalo_flash_cube.sh``./`bouffalo_flash_cube.sh bl616 /dev/ttyUSB1`bouffalo_flash_cube



- bl616
- /dev/ttyUSB1linux/dev/ttyUSBx/dev/ttyACMxwindowsCOMx



### 4.  

 & RT-Threadlogo

![terminal](figures/rt-thread.jpg)



## 5. 

|       |              |
| ----- | ---------------------- |
| bl602 | BL602-IoT-3S/BL-HWC-G1 |
| bl702 | Maix Zero Sense        |
| bl616 | M0S Dock               |
| bl808 | M1s Dock               |



## 6. 

|  |  |               |
| :--- | :------- | :---------------- |
| UART |      | 2000000 |
| GPIO |      |                   |
| I2C  |    |                   |
| SPI  |    |                   |



## 7. 

[flyingcys](https://github.com/flyingcys)



## 8. 

* [datasheet][2]

  [1]: https://www.rt-thread.org/page/download.html
  [2]: https://github.com/bouffalolab/bl_docs



## 9. FAQ

|      | M1s Dock                                                     |
| ---- | :----------------------------------------------------------- |
| 1    |  windows  UART  USB converter   <br> USB converter  vcp <br>  https://dl.sipeed.com/shareURL/MAIX/tools/ftdi_vcp_driver |
| 2    |  TypeC  UART   USB  [ bl702 ](https://wiki.sipeed.com/hardware/zh/maix/m1s/other/start.html#-bl702-) ) |

