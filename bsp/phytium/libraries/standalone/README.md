# Phytium-Standalone-SDK

**v0.3.1** [ReleaseNote](./doc/ChangeLog.md)

## 1. 

### 1.1 

 Phytium  CPU   Baremetal RTOS

![LetterShell](./doc/fig/letter_shell.png)


### 1.2 




![Framework](./doc/design/system_2.png)

- PlatformCPU 

- Component

- FrameworkSDK

- ApplicationSDK

### 1.3. 

```
.
 Kconfig               --> 
 LICENSE               --> 
 README.md             --> 
 arch                  
  armv8             --> 
 baremetal
  example           --> 
 board                  
  d2000
  e2000
  ft2004            --> 
 common                
  fprintf.c
  fprintf.h
  fsleep.c
  fsleep.h          --> 
 configs
  ft2004_aarch32_defconfig
  ft2004_aarch64_defconfig  --> 
 doc
  ChangeLog.md      --> 
  reference         --> 
 drivers
  can
  dma
  watchdog          --> 
 install.py            --> 
 lib             
  Kconfiglib
  lib.mk
  libc
  nostdlib          --> 
 make
  build_baremetal.mk
  buildinfo.mk
  complier.mk
  preconfig.mk      --> 
 requirements.txt      --> python
 scripts
 standalone.mk
 third-party
  letter-shell-3.1  -->             
 tools
```

---

## 2. 

- WindowsLinuxSDKx86_64ARM AARCH64

![windows](./doc/fig/windows.png)![linux](./doc/fig/linux.png)![](./doc/fig/kylin.png)


- [Windows10 ](./doc/reference/usr/install_windows.md), [Linux x86_64 ](./doc/reference/usr/install_linux_x86_64.md)

- [](./doc/reference/usr/usage.md), Phytium Standalone SDK

- [](./baremetal/example)SDK

---

## 3. 

### 3.1 FT2000-4

FT-2000/4  4  2  1 Cluster L2 Cache

-  ARM v8 64  32 
- 
-  ASIMD 
-  2  DDR4  DDR 
-  34 Lane PCIE3.0 2  X16 2  X82  X1
-  2  GMACRGMII  10/100/1000 
-  1  SD  SD 2.0 
-  1  HDAudio 4  Codec
-  SM2SM3SM4 
-  4  UART1  LPC32  GPIO4  I2C1  QSPI2   SPI2  WDT16  GPIO  IO
- 

### 3.2 D2000

D2000  8  2  1 Cluster L2 Cache Cache  DDRI/O  PCIe IO  GMAC  IO 

-  ARM v8 64  32 
- 
-  ASIMD 
-  2  DDR  DDR4  LPDDR4 DDR 
-  34 Lane PCIE3.0 2  X16 2  X82  X1
-  2  GMACRGMII  10/100/1000 
-  1  SD  SD 2.0 
-  1  HDAudio 4  Codec
-  SM2SM3SM4SM9 
-  4  UART1  LPC32  GPIO4  I2C1  QSPI2  SPI2  WDT16  GPIO  IO
-  2 


### 3.3 E2000D

- E2000D 1cluster2cpu

- ARM v8 64 32 
- 
- L132KBL2256KB
- 1DDR4 DDR 
- 4 Lane PCIE3.0 4X1
- 4x1000M SGMII1RGMII/RMII1TSN
- 2USB2.0(OTG)
- 1HDAudio;2DP
- 2SATA3.0
- WDTDMACQSPIPWMNandSD/SDIO/eMMC SPI_MUARTI2CMIOCAN LPC_M_SGPIOLBCTimer

### 3.4 E2000S

- E2000S 1cluster1cpu

- ARM v8 64 32 
- 
- L132KBL2256KB
- 1DDR4 DDR 
- 2 Lane PCIE3.0 2X1
- 2x1000M SGMII/RGMII/RMII2NCSI
- 2USB2.0(OTG)
- 1HDAudio;2DP
- JPEG Encoder
- WDTDMACPWMQSPISD/SDIO/eMMCSPI_MUARTI2CMIOI3CPMBUS LPC_M_SGPIOoneWireTimer


## 4 

| Hardware Interface             | Platform Supported         | Platform Developing         | Component                 |
| ------------------------------ | -------------------------- | --------------------------- | ------------------------- |
| Generic Intrrupt Controller v3 | FT2000/4<br>E2000<br>D2000 |                             | gic/fgic                  |
| Generic Timer                  | FT2000/4<br>E2000<br>D2000 |                             | generic_timer             |
| UART (PrimeCell PL011)         | FT2000/4<br>E2000<br>D2000 |                             | usart/pl011_uart          |
| 10/100/1000MB-ETHERNET         | FT2000/4<br>E2000<br>D2000 |                             | eth/fgmac<br>eth/fxmac    |
| ADC                            | E2000                      |                             | adc/fadc                  |
| CAN                            | FT2000/4<br>E2000<br>D2000 |                             | can/fcan                  |
| DDMA                           |                            | E2000                       | dma/fddma                 |
| GDMA                           | E2000                      |                             | dma/gdma                  |
| GPIO                           | FT2000/4<br>E2000<br>D2000 |                             | gpio/fgpio                |
| I2C                            | FT2000/4<br>E2000<br>D2000 |                             | i2c/fi2c                  |
| QSPI (Nor Flash)               | FT2000/4<br>E2000<br>D2000 |                             | qspi/fqspi                |
| SPI                            | FT2000/4<br>E2000<br>D2000 |                             | spi/fspim                 |
| TIMER & TACHO                  | E2000                      |                             | timer/ftimer_tacho        |
| MIO                            | E2000                      |                             | mio/fmio                  |
| SDMMC                          |                            | FT2000/4<br>D2000           | mmc/fsdmmc                |
| SDIO                           | E2000                      |                             | mmc/fsdio                 |
| PCIE                           | FT2000/4<br>D2000<br>E2000 |                             | pcie/fpcie                |
| NAND                           | E2000                      |                             | nand/fnand                |
| RTC                            | FT2000/4<br>D2000          |                             | rtc/frtc                  |
| SATA                           | FT2000/4<br>D2000<br>E2000 |                             | sata/fsata                |
| USB-PCI                        |                            | FT2000/4<br>E2000<br>D2000  | usb/fxhci                 |
| PWM                            | E2000                      |                             | pwm/fpwm                  |
| WDT                            | FT2000/4<br>D2000<br>E2000 |                             | watchdog/fwdt             |


| Third-Party                    | Platform Supported         | Platform Developing         | Component                 |
| ------------------------------ | -------------------------- | --------------------------- | ------------------------- |
| LWIP 2.1.2                     | FT2000/4<br>D2000<br>E2000 |                             | lwip-2.1.2                |
| Letter shell 3.1               | FT2000/4<br>D2000<br>E2000 |                             | letter-shell-3.1          |
| Sdmmc                          | FT2000/4<br>D2000          |                             | sdmmc                     |
| Sfud 1.1.0                     | FT2000/4<br>D2000<br>E2000 |                             | sfud-1.1.0                |
| Backtrace                      | FT2000/4<br>D2000<br>E2000 |                             | backtrace                 |
| Tlsf                           | FT2000/4<br>D2000<br>E2000 |                             | tlsf-3.1.0                |
| Fatfs (RAM/Sd/SATA)            | FT2000/4<br>D2000<br>E2000 |                             | fatfs-0.1.3               |
| Ymodem                         | FT2000/4<br>D2000<br>E2000 |                             |                           |
| OpenAMP                        | FT2000/4<br>D2000<br>E2000 |                             | openamp                   |
| LittleFS-2.4.2                 |                            | FT2000/4<br>E2000<br>D2000  | littlefs-2.4.2            |
| SPIFFS-0.3.7                   | FT2000/4<br>D2000<br>E2000 |                             | spiffs-0.3.7              |

---

## 5. API

### 5.1 DRIVERS

#### 5.1.1 [FI2C](./doc/reference/driver/fi2c.md)

#### 5.1.2 [FPL011](./doc/reference/driver/fpl011.md)

#### 5.1.3 [FRTC](./doc/reference/driver/frtc.md)

#### 5.1.4 [FWDT](./doc/reference/driver/fwdt.md)

#### 5.1.5 [FSPIM](./doc/reference/driver/fspim.md)

#### 5.1.6 [FQSPI](./doc/reference/driver/fqspi.md)

#### 5.1.7 [FSDMMC](./doc/reference/driver/fsdmmc.md)

#### 5.1.8 [FSATA](./doc/reference/driver/fsata.md)

#### 5.1.9 [FPCIE](./doc/reference/driver/fpcie.md)

#### 5.1.10 [FUSB](./doc/reference/driver/fusb.md)

#### 5.1.11 [FGPIO](./doc/reference/driver/fgpio.md)

#### 5.1.12 [FGIC](./doc/reference/driver/fgic.md)

#### 5.1.13 [FDDMA](./doc/reference/driver/fddma.md)

#### 5.1.14 [FCAN](./doc/reference/driver/fcan.md)

#### 5.1.15 [FADC](./doc/reference/driver/fadc.md)

#### 5.1.16 [FPWM](./doc/reference/driver/fpwm.md)

#### 5.1.17 [FSDIO](./doc/reference/driver/fsdio.md)

### 5.2 MEMORY
#### 5.2.1 [FMEMORY_POOL](./doc/reference/sdk/fmemory_pool.md)

### 5.3 CPU

#### 5.3.1 [MMU](./doc/reference/processor/mmu.md)

#### 5.3.2 [FPINCTRL](./doc/reference/sdk/fpinctrl.md)

#### 5.3.2 [INTERRUPT](./doc/reference/processor/interrupt.md)

---

## 6. 



huanghe@phytium.com.cn

zhugengyu@phytium.com.cn

wangxiaodong1030@phytium.com.cn

liushengming1118@phytium.com.cn


---

## 6. 


- ARM Architecture Reference Manual
- ARM Cortex-A Series Programmers Guide
- Programmer Guide for ARMv8-A
- ARM System Developers Guide Designing and Optimizing System Software
- FT-20004 -V1.4
- D2000 -V1.0
- Bare-metal programming for ARM  A hands-on guide
- Using the GNU Compiler Collection
- Using ld, The GNU Linker
- Using as, The GNU Assembler
- Armv8-A memory model guide

---

## 7. 

Phytium Public License 1.0 (PPL-1.0)
