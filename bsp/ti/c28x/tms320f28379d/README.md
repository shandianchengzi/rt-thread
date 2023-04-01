# TMS320F28379D


## 1. 

TMS320F28379D BSP  C2000 Delfino MCU F28379D LaunchPad    
TMS320F28379D  32  (MCU)

![launch-28379d](figures/launch-28379d.png)



|  |  |
| -- | -- |
|| TMS320F28379D |
| CPU|  TMS320C28x 32  CPU |
||  (CLA) |
|| 200MHz |
|CLA | 200MHz |
|| 800MIPS |
|SRAM| 204kB |
|Flash| 1MB |

F28379D LaunchPad 
* USB  XDS100v2 
* TMS320F28379D CPU
*  LED
* 
* 
*  5V 
*  CAN  
* 
*  ADC  16 
*  SMA 
*  Sigma-Delta  BP 

## 2. 
TMS320F28379D  TI  Code Composer StudioTMS320F28379D  CCS6.0  BSP  CCS7/CCS8  TI  CCS[CCS ][3]
### 2.1 
 Code Composer Studio Project -> Import CCS Projects...

![import](figures/import.png)

 Select search -> directory  Browse...  TMS320F28379D BSP  Finish 

![import_dia](figures/import_dia.png)

### 2.2 
 CCS  C CCS 8  TI v18.1.3.LTS CCS 10  TI v20.2.1.LTS v20.2.0.LTSbugsegmentation fault Code Composer Studio 10.1.1  TI v20.2.4.LTS  Project Explorer  rt-thread BSPRAMFLASH
RAMFLASHbuild
![](figures/build.png)
## 3. 

 Mini-USB  CCS  XDS100v2 

![debug_as](figures/debug_as.png)

 Project Explorer  rt-thread  Debug As -> 1 Code Composer Debug Session

![launching](figures/launching.png)

 Launching Debug Session  CPU  CLA  C28xx_CPU1 OK 

CCS 

 CCS 115200-8-1-N RT-Thread :
```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.1.1 build Jul  4 2022 22:33:37
 2006 - 2022 Copyright by RT-Thread team
 msh >
 ```

## 4. 

*  Scons  CCS  env  menuconfig  CCS  C 

## 5. 

|  |   |    |
| ------ | ----  | :------:  |
| CPU Timer |  |  |
| GPIO |  | |
| SCI |  | SCIA/B/C |
| ePWM | | |
| ADC || |
| DAC | | |
| I2C | | |
| SPI | | |
| CAN | | |
| eCAP | | |

## 6. 


1. guyunjie < yunjie.gu1@gmail.com >
2. qiyu < qiyu_sjtu@163.com >

## 7. 

* [C2000 Delfino MCU F28379D LaunchPad ][1]
* TMS320F28379D [][2]

  [1]: http://www.ti.com.cn/tool/cn/launchxl-f28379d
  [2]: http://www.ti.com.cn/product/cn/tms320f28379d/technicaldocuments
  [3]: http://processors.wiki.ti.com/index.php/Download_CCS#Download_the_latest_CCS
