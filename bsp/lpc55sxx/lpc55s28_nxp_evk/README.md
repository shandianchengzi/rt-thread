# LPC55S28-EVK 

## 1. (Introduction)

LPC55S28 NXPCortex-M33


|  |  |
| -- | -- |
|| LPC5528/LPC55S28  |
|CPU| Cortex-M33 Dual Core, with FPU |
|| 150MHz |
|| 8Flexcomm(USART/SPI/I2C/I2S) / 150MHz SPI / USB(11) |
|| PowerQuad DSP / :PRINCE/PUF/CASPER/AES-256/HASH |

## 2. (Hardware development system)

EVK

![](./figures/board.png)



## 3. 


|          |                                                  |
| ------------ | ---------------------------------------------------- |
| PC   | Linux/MacOS/Windows                                  |
|        | armcc                                                |
|      | scons/mdk5                                           |
|  | Env/(MDKIARarm-none-eabi-gcc)/git/ |

1) 

```bash
    git clone https://github.com/RT-Thread/rt-thread.git
```

2) env

Linux/Mac

```bash
    cd rt-thread/bsp/lpc55S28_evk
    scons --menuconfig
    source ~/.env/env.sh
    pkgs --upgrade
```

Windows

>[RT-Thread][1]ENV

3) 

Linux/Mac

```bash
    scons --menuconfig
```

Windows(ENV)

```bash
    menuconfig
```

menuconfigMDK/IAR

4) (Mac/Linux)

Windows IAR

```bash
    SET RTT_CC=iar
    scons --target=iar -s
```

Windows MDK5*

```bash
    scons --target=mdk5 -s
```

*mdk4

**MDK  IAR **



5) 

MDKIAR

Windows arm-none-eabi-gcc
gcc

```bash
    SET RTT_EXEC_PATH=[GCC]
```

Linux/Mac arm-none-eabi-gcc
gcc

```bash
    export RTT_EXEC_PATH=[GCC]
```

WindowsLinux/Mac arm-none-eabi-gcc

```bash
    scons -j4
```

 `scons --exec-path="GCC"` 



```bash
    LINK rtthread-lpc55S28.elf
    arm-none-eabi-objcopy -O binary rtthread-lpc55s6x.elf rtthread.bin
    arm-none-eabi-size rtthread-lpc55S28.elf
    text    data     bss     dec     hex filename
    41596     356    1456   43408    a990 rtthread-lpc55s6x.elf
    scons: done building targets.
```


rtthread-lpc55s6x.elfrtthread.binrtthread.bin

## 3. 

 ISP 

### 3.1 

 & Flexcomm0*RT-Threadlogo

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Jul 30 2019
 2006 - 2019 Copyright by rt-thread team
uising armclang, version: 6120001
msh />
```

*


## 4. 

|        |  |                          |
| ---------- | :------: | :--------------------------: |
| UART       |      | UART0/2                 |
| GPIO       |      |  |
| SPI        |      | High Speed SPI     |
| USB Device |  |           |
| USB Host   |   |       |
| Windowed WatchDog |   |                         |
| ADC |  |  |
| I2C       |      | MMA8562          |
| I2C Sensor |      | MMA8562 |
| RTC        |      | RTC              |
| SDIO       |      | SD                     |
| I2S        |   |       |

## 6. 

:
alex.yang@nxp.com
