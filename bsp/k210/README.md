# Kendryte K210

## 1. 

Kendryte K210 (SoC) (TSMC)  28 64

Kendryte K210 AIIoTSoCMCU

Kendryte

* 
* 
* 
* KPU
* TSMC 28nm-40C125C
* 
* IO
* 
* 3.3V/1.8V



|  |  |
| -- | -- |
|| K210 |
|CPU| RV64GC |
|| 400MHz |
|SRAM| 8MB |
|  | AESSHA256 |
| | DVPJTAGOTPFPIOAGPIOUARTSPIRTCISICWDTTimerPWM |

## 2. 

 K210 RT-Thread  K210  sdk  bsp/k210  latest  RT-Thread  Latest menuconfig:

```
RT-Thread online packages --->
    peripheral libraries and drivers --->
        Kendryte SDK --->
            [*] kendryte K210 SDK
```

 k210 SDK  C++17  C++ C++menuconfig

```
RT-Thread Components --->  C++ features
```

Windows[env][1]consolebsp/k210

    cd bsp/k210
    menuconfig #  k210 SDK
    pkgs --update

Linux

    scons --menuconfig

env~/.env

    source ~/.env/env.sh
    
    cd bsp/k210
    pkgs --update
risc-v[](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases)  
    
`rtconfig.py`risc-v
  
1. `kendryte``risc-v8.2.0`
2. C++ 17,k210nncaseC++ 17,C++ 17nncasePC
kmodel[shentalon](13212105191@163.com)  

scons  

```
    set RTT_EXEC_PATH=C:\Users\xxxx\Downloads\xpack-riscv-none-embed-gcc-10.2.0-1.2\bin
    scons
```


 `scons --exec-path="GCC"` 

rtthread.elfrtthread.binrtthread.bin  
SDK`menuconfig` RT-Thread online packages  peripheral libraries 
and drivers  the kendryte-sdk package for rt-threadSDKlatest
## 3. 

[K-Flash](https://kendryte.com/downloads/)bin

![K-Flash](images/flash.png)

### 3.1 

 & RT-Threadlogo

![terminal](images/k210.png)

K210-test_v0.2

    python -m serial.tools.miniterm --rts 0 --dtr 0 COM9 115200

## 4. 

|  |   |    |
| ------ | ----  | :------:  |
| UART |  | UARTshell |

## 5. 

[bernard](https://github.com/BernardXiong)

## 6. 

menuconfig

|  |  |
| -----  | --------- |
| Alignment size for CPU architecture data access | 8 |
| The stack size of idle thread | > 1024 |
| the device name for console | "uarths" |
| Set main thread stack size | 4096 |

## 7. 

* [datasheet][2]

  [1]: https://www.rt-thread.org/page/download.html
  [2]: https://s3.cn-north-1.amazonaws.com.cn/dl.kendryte.com/documents/kendryte_datasheet_20180919020633.pdf
