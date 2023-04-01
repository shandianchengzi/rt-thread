# LPC55S16-EVK 

## 1. (Introduction)

LPC55S16 NXPCortex-M33


|  |  |
| -- | -- |
|| LPC5516/LPC55S16  |
|CPU| Cortex-M33 , with FPU |
|| 150MHz |

## 2. (Hardware development system)

EVK

![](./figures/board.png)



## 3. 

IDE:

* MDK5: V5.16
* IAR: 9.30.1

1) 

```bash
    git clone https://github.com/RT-Thread/rt-thread.git
```

2) env

Linux/Mac

```bash
    cd rt-thread/bsp/lpc55S16_evk
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

4) 

IAR:

```bash
scons --target=iar
```

MDK5:

```bash
scons --target=mdk5
```

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
| RTC        |      | RTC              |

## 5.

 BSP  0  ENV  BSP  

1.  bsp  env 
2.  menuconfig 
3.  pkgs --update 
4.  scons --target=mdk5/iar 

## 6. 

:
alex.yang@nxp.com
