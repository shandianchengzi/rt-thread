1C


---

## 1. 

1CGS2321CMLC NAND Flash1CCameraUSB OTGUSB HOSTAC97/I2SLCDSPIUART

BSP

|  |  |
| -- | -- |
|| 1C300A/1C300B |
|CPU| GS232 |
|| 300MHz |
|SDRAM| 32MB |
|Flash| 128MB NandFlash512K NorFlash |

## 2. 

Windows[env][1]1CLS232MIPS32envMIPS

* [mips-2015.05-19-mips-sde-elf.exe][2]

`D:\mgc\embedded\codebench`envconsole`RTT_EXEC_PATH`

```
    set RTT_EXEC_PATH=D:\mgc\embedded\codebench\bin
```

envconsole`bsp/ls1cdev`

```
    scons
```

 `scons --exec-path="GCC"` 

rtthread.elfrtthread.bin

## 3. 

PC115200-N-8-1`[GPIO36/GPIO37]`

PMONtftp

enterPMON

```
PMON> ifaddr syn0 192.168.1.100
PMON> load tftp://192.168.1.5/rtthread.elf
PMON> g
```

### 3.1 

 & RT-Threadlogo

```

 \ | /
- RT -     Thread Operating System
 / | \     3.0.4 build May 10 2018
 2006 - 2018 Copyright by rt-thread team
eth_inited!
lwIP-1.4.1 initialized!
msh />Link is up in FULL DUPLEX mode
Link is with 100M Speed

```

## 4. 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UART2UART |
| IIC |  |  |
| SPI |  |  |
| GPIO |  |  |
| ETH |  | RMII |

### 4.1 IO

| IO |  |
| -- | -- |
|  | GPIO36/GPIO37 |

## 5. 



- [zhuangwei123](https://github.com/zhuangwei123)

## 6. 

* 1C[][3]
* 1C[][4]

  [1]: https://www.rt-thread.org/page/download.html
  [2]: https://sourcery.mentor.com/GNUToolchain/package13851/public/mips-sde-elf/mips-2015.05-19-mips-sde-elf.exe
  [3]: http://www.loongson.cn/uploadfile/cpu/1C/Loongson_1C300_user.pdf
  [4]: http://www.loongson.cn/uploadfile/cpu/1C/Loongson_1C300_data.pdf
