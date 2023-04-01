# amebaz on RT-Thread

## 1 

amebaz RealtekCortex-M4WiFi SOCrtl8710b

|  |  |
| -- | -- |
|| amebaz |
|CPU| Cortex-M4 |
|| 125MHz |

## 2 

|          |                                                          |
| ------------ | ------------------------------------------------------------ |
| PC   | Linux/MacOS/Windows                                          |
|        | arm-none-eabi-gcc version 6.3.1 20170620 (release) |
|      | scons                                               |
|  | Env/(IARarm-none-eabi-gcc)/git/         |

## 3 

```bash
    git clone https://github.com/RT-Thread/rt-thread.git
```

## 4 

### 4.1 Windows 

Windows`GCC toolchain`  `IAR IDE`

#### 4.1.1 IAR 

IAR amebaz `IAR 7.X` 

#### 4.4.2 GCC 

GCC RT-Thread  env  GCC 

[env](https://www.rt-thread.org/page/download.html)

env[RT-Thread env ](https://www.rt-thread.org/document/site/rtthread-development-guide/rtthread-tool-manual/env/env-user-manual/)

### 4.2 Linux/Mac 

Linux/Mac  GCC 

```bash
    cd rt-thread/bsp/amebaz
    scons --menuconfig
    source ~/.env/env.sh
    pkgs --upgrade
```

## 5 

### 5.1 Windows 

 `menuconfig` 

```bash
    menuconfig
```

### 5.2 Linux/Mac 

Linux/Mac

```bash
    scons --menuconfig
```

## 6 

amebaz  package  package(realtek-ameba)

```bash
    pkgs --update
```

## 7 

### 7.1 Windows 

#### 7.1.1 IAR 

IARproject.eww Project  Rebuild All 

![ ](figures/iar_build.png)

#### 7.1.2 GCC 

envGCC rt-thread/bsp/amebaz  `scons`  `image2_all_ota1.bin` 

```bash
    scons
```

### 7.2 Linux/Mac 

GCCgcc

```bash
    export RTT_EXEC_PATH=[GCC]
```

 GCC  `scons` 

```bash
    scons
```

 `scons --exec-path="GCC"` 



```bash
LINK rtthread.axf
arm-none-eabi-objcopy -j .ram_image2.entry -j .ram_image2.data -j .ram_image2.bss -j .ram_image2.skb.bss -j .ram_heap.data -Obinary rtthread.axf ram_2.r.bin
arm-none-eabi-objcopy -j .xip_image2.text -Obinary rtthread.axf xip_image2.bin
arm-none-eabi-objcopy -j .ram_rdp.text -Obinary rtthread.axf rdp.bin
python gen_bin.py
is_law = 1
start = 10005000, end = 0, base = 10000000
Input file size: 65852
copy size 45372
start = 10005000, end = 0, base = 10000000
Input file size: 45372
copy size 24892
start = 0, end = 0, base = 0
Input file size: 336816
copy size 336816
size = 361772
checksum 209b36c
'true' is not recognized as an internal or external command,
operable program or batch file.
Done...
scons: done building targets.
```

 image2_all_ota1.bin 

## 8 

### 8.1 IAR



ajlinkA14(CLK),A15(TMS),GND,VCC

b IAR  Project  Download  Download active application 

![IAR](figures/iar_download.png)

c

### 8.2 



a

 `micros usb`  `FLASH`  `RST`  `RST`  `FLASH` 

b

 Image Tool  `micros usb`  1.5Mbps

![](figures/image-tool_v2.2.0.png)

boot `boot_all.bin`, OTA1  image2_all_ota1.bin 

c

 Download 

## 9 

 `micro usb` 115200 8  1  `RST` 

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Oct 25 2018
 2006 - 2018 Copyright by rt-thread team
lwIP-2.0.2 initialized!

Initializing WIFI ...
LDO Mode, BD_Info: 0

LDO Mode, BD_Info: 0

WIFI initialized
[I/WIFI] amebaz_wifi_start success
build time: Oct 25 2018 10:52:02
Hello RT-Thread!
[I/WLAN.dev] wlan init success
[I/WLAN.lwip] eth device init ok name:w0
msh >
```

## 10 WIFI

### wifi

wifi 

```bash
    wifi scan
```

  

|  |                      |
| ---- | ------------------------ |
| wifi | wifiwifi |
| scan | wifi         |

 wifi 

```bash
scan ap down
             SSID                      MAC              security    rssi   chn    Mbps
------------------------------- -----------------    -------------- ----   ---    ----
NEO-shanghai-ap2                58:66:ba:a1:ee:71    WPA2_TKIP_PSK   -74    11    0
WQ1                             88:25:93:94:51:54    WPA2_AES_PSK    -76    13    0
shyc1                           a0:40:a0:a3:e8:c9    WPA2_AES_PSK    -77    13    0
KVIP                            70:65:82:3b:71:43    WPA2_AES_PSK    -83    11    0
YST2016                         88:25:93:c6:67:d1    WPA2_TKIP_PSK   -84     4    0
```

> wifi wifi

### wifi 

 wifi  

```bash
    wifi join ssid 123456789
```



|       |                                |
| --------- | ---------------------------------- |
| wifi      | wifiwifi           |
| join      | wifi                   |
| ssid      |                          |
| 123456789 |  |

 `wifi w0 join realthread_VIP 123456789` 

```bash

WIFI  wlan0 Setting:
==============================
      MODE => STATION
      SSID => realthread_VIP
   CHANNEL => 6
  SECURITY => AES
  PASSWORD => 123456789
[I/WLAN.mgnt] wifi connect success ssid:realthread_VIP

```

IPifconfig

```bash
network interface: w0 (Default)
MTU: 1500
MAC: 00 e0 4c d5 ac 46
FLAGS: UP LINK_UP ETHARP BROADCAST
ip address: 172.16.200.110
gw address: 172.16.200.1
net mask  : 255.255.255.0
dns server #0: 172.16.200.1
dns server #1: 223.5.5.5
```

## 

|        |  |                          |
| ---------- | :------: | :--------------------------: |
| UART       |      | UART0                        |
| WLAN       |  | STA                |

## 

:
[flyingcys][4] < [flyingcys@163.com][5] >

  [1]: https://www.rt-thread.org/page/download.html
  [4]: https://github.com/flyingcys
  [5]: mailto:flyingcys@163.com
