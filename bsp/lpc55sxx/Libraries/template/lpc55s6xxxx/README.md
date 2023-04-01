# LPC55S69-EVK 

## 1. (Introduction)

LPC55S69 NXPCortex-M33


|  |  |
| -- | -- |
|| LPC556x/LPC55S6x  |
|CPU| Cortex-M33 Dual Core, with FPU |
|| 150MHz |
|| 8Flexcomm(USART/SPI/I2C/I2S) / 150MHz SPI / USB(11) |
|| PowerQuad DSP / :PRINCE/PUF/CASPER/AES-256/HASH |

## 2. (Hardware development system)

EVK

![](./figures/board.png)



## 3. 


|          |                                                          |
| ------------ | ------------------------------------------------------------ |
| PC   | Linux/MacOS/Windows                                          |
|        | arm-none-eabi-gcc version 6.3.1 20170620 (release)/armcc/iar |
|      | scons/mdk5/iar                                               |
|  | Env/(MDKIARarm-none-eabi-gcc)/git/         |

1) 

```bash
    git clone https://github.com/RT-Thread/rt-thread.git
```

2) env

Linux/Mac

```bash
    cd rt-thread/bsp/lpc55s69_evk
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
    set RTT_EXEC_PATH=[GCC]
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
    LINK rtthread-lpc55s69.elf
    arm-none-eabi-objcopy -O binary rtthread-lpc55s6x.elf rtthread.bin
    arm-none-eabi-size rtthread-lpc55s69.elf
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


### 4.1 IO

| PIO |  |
| -- | -- |
| PIO0_29 | Flexcomm0 USART RXD |
| PIO0_30 | Flexcomm0 USART TXD |
|  |  |
| PIO0_7 | SDIO SD0_CLK |
| PIO0_8 | SDIO SD0_CMD |
| PIO0_9 | SDIO SD0_POW_EN |
| PIO0_15 | SDIO SD0_WR_PRT |
| PIO0_17 | SDIO SD0_CARD_INT |
| PIO0_24 | SDIO SD0_D(0) |
| PIO0_25 | SDIO SD0_D(1) |
| PIO0_31 | SDIO SD0_D(2) |
| PIO1_0 | SDIO SD0_D(3) |
|  |  |
| PIO0_26 | High Speed SPI MOSI |
| PIO1_2 | High Speed SPI SCK |
| PIO1_3 | High Speed SPI MISO |
|  |  |
| PIO1_4 | GPIO1_4 output LED BLUE |
| PIO1_6 | GPIO1_6 output LED RED |
| PIO1_7 | GPIO1_7 output LED GREEN |
|  |  |
| PIO0_27 | Flexcomm2 USART TXD mikro BUS |
| PIO1_24 | Flexcomm2 USART RXD mikro BUS |
|  |  |
| PIO1_20 | Flexcomm4 I2C SCL |
| PIO1_21 | Flexcomm4 I2C SDA |

## 5. menuconfig Bsp

|  |  |
| -- | -- |
| Device type | MDK/IAR |

*RT-Thread

## 6. 

:
[Magicoe][2] < [magicoe@163.com][3] >

[AlexYang][2] < [alex.yang@nxp.com][3] >

[1]: https://www.rt-thread.org/page/download.html
[2]: https://github.com/Magicoe
[3]: mailto:magicoe@163.com
