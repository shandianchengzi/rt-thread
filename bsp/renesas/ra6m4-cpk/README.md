#  CPK-RA6M4  BSP 

## 

 CPK-RA6M4  BSP ()  BSP RT-Thread 



- 
- BSP 

## 

 RA6M4 MCU  CPK-RA6M4 MCU  IDE RA6M4 MCU 



![image-20211011174017429](docs/picture/cpk-ra6m4.png) 

 **** 

- MCUR7FA6M4AF3CFB200MHzArm Cortex-M33 1MB , 256kB SRAM
-  J-Link 
-  PMOD 

****

## 

 BSP 

| **** | **** | **** |
| :----------------- | :----------------- | :------------- |
| UART               |                | UART7  |
| GPIO               |                |                |
| IIC                |                |            |
| WDT                |                |                |
| RTC                |                |                |
| ADC                |                |                |
| DAC                |                |                |
| SPI                |                |                |
| FLASH              |                |                |
| PWM                |                |                |
| CAN                |                |                |
|  SEGGER_RTT        |                |  segger_rttconsole |
| ...      |                    |                |
| **** | **** | **** |
| WiFi      |         |  [RW007 WiFi ](https://github.com/RT-Thread-packages/rw007)  |
|    |        |  [HS300x ](https://github.com/Guozhanxin/hs300x) |
|  |  | [zmod4410 ](https://github.com/ShermanShao/zmod4410) |
|  |  | [isl29035](https://github.com/ShermanShao/isl29035) |


## 



- 

   RT-Thread  RT-Thread  
- 

   RT-Thread  ENV  BSP 

### 

 BSP  MDK5  MDK5 

****

 USB  PC J-link  DEBUG  USB  UART7P613(TXD)P614(RXD)

****

-  project.uvprojx  MDK5 

>  J-Flash Lite  V7.50 [J-Link ](https://www.segger.com/downloads/jlink/)

-  J-Flash lite  R7FA6M4AF OK  BSP  MDK  /object/ra6m4.hex  Program Device 

![image-20211011181555421](docs/picture/jflash1.png) 

![image-20211011182047981](docs/picture/jflash2.png) 

![image-20211011182434519](docs/picture/jflash.png) 

![image-20211011182949604](docs/picture/jflash3.png) 

****



 PC , 115200-8-1-N RT-Thread  help 

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Oct 11 2021
 2006 - 2021 Copyright by rt-thread team

Hello RT-Thread!
msh >
msh >help
RT-Thread shell commands:
reboot           - Reboot System
help             - RT - Thread shell help.
ps               - List threads in the system.
free             - Show the memory usage in the system.
hello            - say hello world
clear            - clear the terminal screen
version          - show RT - Thread version information
list_thread      - list thread
list_sem         - list semaphore in system
list_event       - list event in system
list_mutex       - list mutex in system
list_mailbox     - list mail box in system
list_msgqueue    - list message queue in system
list_timer       - list timer in system
list_device      - list device in system
list             - list all commands in system

msh > 
```

****

 **bsp\ra6m4-cpk\src\hal_emtry.c**   `void hal_entry(void)`  src 

```c
void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");

    while (1)
    {
        rt_pin_write(LED3_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED3_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}
```

### 

****

- [](https://www2.renesas.cn/cn/zh/products/microcontrollers-microprocessors/ra-cortex-m-mcus/cpk-ra6m4-evaluation-board)
- [](https://www2.renesas.cn/cn/zh/document/mah/1527156?language=zh&r=1527191)
- [RA MCU ](https://www2.renesas.cn/cn/zh/document/gde/1520091)
- [RA6 MCU ](https://www2.renesas.cn/cn/zh/document/apn/ra6-quick-design-guide)
- [RA6M4_datasheet](https://www2.renesas.cn/cn/zh/document/dst/ra6m4-group-datasheet)
- [RA6M4 Group Users Manual: Hardware](https://www2.renesas.cn/cn/zh/document/man/ra6m4-group-user-s-manual-hardware)

**FSP **

 BSP  [FSP](https://www2.renesas.cn/jp/zh/software-tool/flexible-software-package-fsp#document) [RT-Thread ](https://club.rt-thread.org/)

1. [ (FSP) | Renesas](https://www.renesas.com/cn/zh/software-tool/flexible-software-package-fsp) FSP 3.5.0 
2.  CPK-RA6M4 
> [ CPK-RA6M4 ](https://www2.renesas.cn/jp/zh/products/microcontrollers-microprocessors/ra-cortex-m-mcus/cpk-ra6m4-evaluation-board)**** **CPK-RA6M4**
3.  **CPK-RA6M4** FSP [](https://www2.renesas.cn/document/ppt/1527171?language=zh&r=1527191)
4. [ FSP ](../docs/RAFSP.md) MDK  FSP 

**ENV **

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/#/development-tools/env/env)

 BSP  UART7  ENV 


1.  bsp  env 
2. `menuconfig`
3. `pkgs --update`
4. `scons --target=mdk5` 

**SEGGER_RTT**

RA6M4USBTTLRT-Thread[RTTHREAD_SEGGER_TOOL](https://github.com/supperthomas/RTTHREAD_SEGGER_TOOL)J-LinkRT-Threadconsole`RT-Thread Settings->->`SEGGER-RTT,

![jlink-rtt](docs/picture/jlink-rtt.png)

J-LinkRT-Threadconsole


## FAQ

###  MDK  DEBUG   Error: Flash Download failed Cortex-M33 

 Utilities 

![image-20211214102231248](docs/picture/readme_faq1.png) 

## 

  [RT-Thread ](https://club.rt-thread.org/)

## 

 CPK-RA6M4  [ RT-Thread ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/development-guide/github/github)
