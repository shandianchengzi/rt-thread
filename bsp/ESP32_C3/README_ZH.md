
# ESP32-C3 BSP 

 | [English](README.md)

## 

RT-THREADESP32-C3[ESP32C3](http://luatos.com/t/esp32c3) BSP () 



- 
- BSP 

 BSP RT-Thread 

## 

LEDmenuconfig

- [LUATOS_ESP32C3](https://wiki.luatos.com/chips/esp32c3/board.html)

![LUATOS_ESP32C3](images/luatos_esp32c3.png)

- [HX-DK-](https://docs.wireless-tech.cn/doc/7/)

![hongxu](images/hx_shang.png)



LUATOS_ESP32C3 **** 

- MCU[esp32-c3](https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf)  160MHz 407.22 CoreMark; 2.55  CoreMark/MHz
- 384KB ROM,  400KB SRAM,
- 
  - LED2LED: D4 (IO12), D5IO13
  - 2K1BOOT K2(RST)
  - SPI FLASH: 4M 
- USB UART

 [ESP32-C3](https://wiki.luatos.com/chips/esp32c3/board.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| GPIO              |          |  |
| UART              |          | LUATOS_ESP32C3UART0_TXUART0_RXUSBCP2102|
| JTAG          |          | ESP32C3USBPC                                |

## ESP-IDF
ESP-IDF
1. Env
- 
```
pkgs --update
```
- IDFLinuxMacOSESP-IDFIDf
```
cd packages/ESP-IDF-latest
./install.sh
```
WindowsCommand PromptEnvPowerShellBSP
```
install.bat
```

- IDFBSP
LinuxMacOS
```
. export.sh
```
Windows
```
export.bat
```
Command Prompt

2. ESP-IDFpatch
- `SCons --menuconfig`
```
Hardware Drivers Config
    [*] Use local ESP-IDF installation
```
ESP-IDF
```
RT-Thread online packages
    peripheral libraries and drivers
        [ ] ESP-IDF: Espressif IoT Development Framework
```
- EnvFreeRTOS
```
pkgs --update
```
- ESP-IDF[VSCode](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md)ESP-IDFmaster
- ESP-IDF
```
git checkout 5c1044d84d625219eafa18c24758d9f0e4006b2c
# rtt.patchBSPrtt.patch
git am rtt.patch
```
- patchESP-IDFFreeRTOS

## 
1. BSPRT-Thread
```
scons --menuconfig
```
2. `scons --menuconfig`RT-Thread`CMakeLists.txt`
```
scons --target=esp-idf
```
3. EnvESP-IDF`idf.py`[](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/get-started/index.html#build-your-first-project)Windows`idf.py`Command PromptESP-IDFpatch[VSCode](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md)
4.  LED 1S 

## 

- RTTHREADESP32`Thomas`

## 

:

-  [supperthomas](https://github.com/supperthomas) <78900636@qq.com>
-  [tangzz98](https://github.com/tangzz98) <tangz98@outlook.com>

## 

- [chenyingchun0312](https://github.com/chenyingchun0312) RISCV
