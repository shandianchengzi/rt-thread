# Maxim-MAX32660- EVSYS

## 

MAX32660[MAX32660](https://www.maximintegrated.com/en/products/microcontrollers/MAX32660.html)

Datasheet: [MAX32660_datasheet](https://datasheets.maximintegrated.com/en/ds/MAX32660.pdf)

User Guide[MAX32660_UserGuide](https://pdfserv.maximintegrated.com/en/an/AN6659.pdf)

:  [MAX32660-EVSYS](https://www.maximintegrated.com/en/products/microcontrollers/MAX32660-EVSYS.html)

datasheet [MAX32660-EVSYS.pdf)](https://datasheets.maximintegrated.com/en/ds/MAX32660-EVSYS.pdf)

IDE: [keil pack](http://www.mxim.net/microcontroller/pack/Maxim.MAX32660.1.2.0.pack) [eclipse](https://www.maximintegrated.com/en/design/software-description.html/swpart=SFW0001500A)



- 

## MAX32660

- RAM  96KB    0x20000000~0x20018000
- ROM  256KB   0x0 ~ 0x40000
- 16KB I-cache
- UART 2  UART0  UART1
- GPIO  14
- I2C  2 Master/Slave 3.4Mbps
- ARM Cortex-M4F, 96MHz
- MPU
- SPI 2  Master/Slave
- I2S  Master/Slave
- 4 channel DMA
- 3 32bit  Timer
- Watchdog
- RTC

## 

MAX32660-EVSYSMAX32660ARM Cortex-M4F96MHzFPU



![board](doc/images/board.jpg)



![pins](doc/images/pins.jpg)

MAX32660-EVSYS **** 

- MCUMAX32660
- 
  - LED1GPIO P0_13  
  - 1GPIO P0_12,   
- CMSIS-DAP

## 

 BSP 

| **** | **** |    ****    |
| :----------------- | :----------------: | :-------------------: |
| GPIO               |                |                       |
| UART               |                | UART0, UART1(console) |
| PWM                |                   |                       |
| SPI                |                |      SPI0, SPI1      |
| RTC                |                |          RTC          |
| I2S                |                   |                       |
| I2C                |                |      I2C0, I2C1      |
| TIMER              |                   |                       |
| Watchdog           |                   |                       |

### 

 BSP   env  BSP 

1.  bsp  env 
2.  `menuconfig`
3. `scons --target=mdk5/vsc

## 

keilGCC

## FAQ

### GCC

arm-none-eabi-gccrtconfig.pyEXEC_PATH  

openocdeclipse

`C:\Maxim\Toolchain\bin`

vscodebsp

ctrl+shift+bscons

F5

buildluanch.json

```
            //"preLaunchTask": "build"
```

## 

:

- [supperthomas], <78900636@qq.com>
