#  EK-RA6M3  BSP 

## 

 EK-RA6M3  BSP ()  BSP RT-Thread 



- 
- BSP 

## 

 RA6M3 MCU  EK-RA6M3 MCU  IDE RA6M3 MCU 



![](docs/picture/ek-ra6m3g.png) 



 **** 

- MCUR7FA6M3AH120MHzArm Cortex-M4 2MB , 640KB SRAM
-  J-Link 
-  PMOD 

****

## 

 BSP 

| **** | **** | **** |
| :----------------- | :----------------- | :------------- |
| UART               |                | UART7  |
| GPIO               |                |                |
| LCD          |          |                          |

* /[ (rt-thread.org)](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/tutorial/make-bsp/renesas-ra/RABSP)

## 



- 

   RT-Thread  RT-Thread  
- 

   RT-Thread  ENV  BSP 

### 

 BSP  MDK5  MDK5 

****

 USB  PC J-link  DEBUG  USB  UART7P401(TXD)P402(RXD)

****

-  project.uvprojx  MDK5 

-  MDK  Debug 

****



 PC , 115200-8-1-N RT-Thread  help 

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Jan  4 2023 10:14:56
 2006 - 2022 Copyright by RT-Thread team
Hello RT-Thread!
msh >
msh >help
help             - RT-Thread shell help.
ps               - List threads in the system.
free             - Show the memory usage in the system.
clear            - clear the terminal screen
version          - show RT-Thread version information
list             - list objects

msh > 
```

****

 **bsp\ra6m3-ek\src\hal_emtry.c**   `void hal_entry(void)`  src 

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

**FSP **

 BSP  [FSP](https://www2.renesas.cn/jp/zh/software-tool/flexible-software-package-fsp#document) [RT-Thread ](https://club.rt-thread.org/)

1. [ (FSP) | Renesas](https://www.renesas.com/cn/zh/software-tool/flexible-software-package-fsp) FSP 3.5.0 
2.  EK-RA6M3 
> [ EK-RA6M3 ](https://www.renesas.cn/cn/zh/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ek-ra6m3-evaluation-kit-ra6m3-mcu-group#document) ****   ** EK-RA6M3** 
3.  **EK-RA6M3** FSP [](https://www2.renesas.cn/document/ppt/1527171?language=zh&r=1527191)
4. [ FSP ](../docs/RAFSP.md) MDK  FSP 

**ENV **

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/#/development-tools/env/env)

 BSP  UART7  ENV 


1.  bsp  env 
2. `menuconfig`
3. `pkgs --update`
4. `scons --target=mdk5`  

## 

  [RT-Thread ](https://club.rt-thread.org/)

## 

  EK-RA6M3  [ RT-Thread ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/development-guide/github/github)
