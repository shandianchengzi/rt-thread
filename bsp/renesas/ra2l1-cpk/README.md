#  CPK-RA2L1 

## 

 CPK-RA2L1  BSP ()  BSP RT-Thread 



- 
- BSP 

## 

CPK-RA2L1  IDE[RA2L1 MCU ](https://www2.renesas.cn/cn/zh/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ra2l1-48mhz-arm-cortex-m23-ultra-low-power-general-purpose-microcontroller)



![image-20220707141215644](docs/picture/ra2l1-cpk.png) 

 **** 

- MCUR7FA2L1AB2DFM48MHzArm Cortex-M23 256kB , 32kB SRAM
-  J-Link 
-  PMOD 

****


## 



- 

   RT-Thread  RT-Thread  
- 

   RT-Thread  ENV  BSP 

### 

 BSP  MDK5  MDK5 

****

 USB  PC J-link  DEBUG  USB  UART9P109(TXD)P110(RXD)

![image-20220707144056181](docs/picture/ra2l1-cpk1.png) 

****

-  project.uvprojx  MDK5 

>  J-Flash Lite  V7.50 [J-Link ](https://www.segger.com/downloads/jlink/)

-  J-Flash lite  R7FA2L1AB OK  BSP  MDK  /object/ra6m4.hex  Program Device 

![image-20211011182434519](docs/picture/jflash.png) 

![image-20220707115828323](docs/picture/jflash1.png) 

![image-20220707144644438](docs/picture/jflash2.png) 

![image-20220707144752679](docs/picture/jflash3.png) 

****



 PC , 115200-8-1-N RT-Thread  help 

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.1.0 build Jul  7 2022 14:44:40
 2006 - 2022 Copyright by RT-Thread team

Hello RT-Thread!
msh >
msh >
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
icu_sample       - icu sample

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

- [](https://www2.renesas.cn/cn/zh/products/microcontrollers-microprocessors/ra-cortex-m-mcus/cpk-ra2l1-evaluation-board#overview)
- [RA MCU ](https://www2.renesas.cn/cn/zh/document/gde/1520091)
- [datasheet](https://www2.renesas.cn/cn/zh/document/dst/ra2l1-group-datasheet?language=en&r=1596841)
- [Users Manual: Hardware](https://www2.renesas.cn/jp/zh/document/mah/ra2l1-group-users-manual-hardware?language=en&r=1398061)

**FSP **

 BSP  [FSP](https://www2.renesas.cn/jp/zh/software-tool/flexible-software-package-fsp#document) [RT-Thread ](https://club.rt-thread.org/)

1. [ (FSP) | Renesas](https://www.renesas.com/cn/zh/software-tool/flexible-software-package-fsp) FSP 3.5.0 
2.  CPK-RA6M4 
> [ ](https://www2.renesas.cn/cn/zh/products/microcontrollers-microprocessors/ra-cortex-m-mcus/cpk-ra2l1-evaluation-board#overview)**** **CPK-RA2L1**
3.  **** FSP [](https://www2.renesas.cn/cn/zh/document/gde/1596896?language=zh&r=1596841)
4. [ FSP ](./docs/FSP.md) MDK  FSP 

**ENV **

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/#/development-tools/env/env)

 BSP UARTIRQ3 ENV 


1.  bsp  env 
2. `menuconfig`
3. `pkgs --update`
4. `scons --target=mdk5` 


## FAQ

###  MDK  DEBUG   Error: Flash Download failed Cortex-M23 

 Utilities 

![image-20211214102231248](docs/picture/readme_faq1.png) 

## 

  [RT-Thread ](https://club.rt-thread.org/)

## 

BSP [ RT-Thread ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/development-guide/github/github)
