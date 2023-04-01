# RV32M1_VEGA 

## 1. 

RV32M1_VEGARISC-V 32RISC-V 32BLE

|  |  |
| -- | -- |
|| RV32M1 |
|CPU| RV32IMC, with extensons for post-incrementing load and stores, |
| | multiply-accumulate extensions, ALU extensions, hardware loops. |
| | RV32IEMC |
|| 48MHz72MHz |
| | 48MHz72MHz |
|SRAM| 256kB + 128kB |
|Flash| 1MB + 256kB |

## 2. 

GNU GCC 7.2.0 & newlib 2.5.0RV32IMCRV32M1RT-Thread ENV1.0

Windows[env][1]console`bsp/rv32m1_vega/ri5cy`

    scons

rtthread.elfrtthread.binrtthread.bin

## 3. 

JLinkRV32M1_VEGARISC-VJTAGJLinkPCWinUSBJTAGRV32M120pin JTAG

USBSDAUSBPC115200-N-8-1`[PTC7/PTC8]`

rtthread.bingdbopenocd`load`flash

JTAGgdbRV32M1_VEGA[](https://github.com/open-isa-org/open-isa.org/blob/master/RV32M1_Vega_Develop_Environment_Setup.pdf)

### 3.1 

 & `SW1`RT-Threadlogo

``` text
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Dec  5 2018
 2006 - 2018 Copyright by rt-thread team
File System initialized!
Hello RT-Thread!
msh />
```

## 4. 

|  |   |    |
| ------ | ----  | :------  |
| UART |  | UART0, RX(PTC7), TX(PTC8) |
|      |  | UART1, RX(PTA25), TX(PTA26) |
| clock |  |  |
| GPIO | IOpinmuxclock |  |
| MMC/SD |  |  |

### 4.1 IO

| IO |  |
| -- | -- |
| PTA22 | LED_BLUE |
| PTA23 | LED_GREEN |
| PTA24 | LED_RED |
| PTA24 | LED_STS |
| PTA25 | UART1_RX |
| PTA26 | UART1_TX |
| PTE8 | BTN_SW3 |
| PTE9 | BTN_SW4 |
| PTE12 | BTN_SW5 |
| PTA0 | BTN_SW2/BTN_NMI |

## 5. 

* [](https://github.com/open-isa-org/open-isa.org/blob/master/RV32M1_VEGA_Board_User_Guide.pdf)
* [](https://github.com/open-isa-org/open-isa.org/blob/master/Reference%20Manual%20and%20Data%20Sheet/RV32M1DS_Rev.1.1.pdf)
* [open-isa](https://github.com/open-isa-org/open-isa.org)

  [1]: https://www.rt-thread.org/page/download.html
