#  6M5  BSP 

## 

 6  BSP ()  BSP RT-Thread 



- 
- BSP 

## 

 RA6M5 MCU  6 IDE RA6M5 MCU 



![image-20211011174017429](docs/picture/ebf_ra6m5.jpg)

 **** 

![image-20211011174017430](docs/picture/ebf_ra6m_2.jpg)
![image-20211011174017431](docs/picture/ebf_ra6m_3.jpg)

****

## 

 BSP 

| **** | **** | ****          |
| :----------------- | :----------------- | :------------- |
| UART     |        | UART4  |
| GPIO     |        |                 |
| ... |          |                 |
| **** | **** | ****          |
| ... |          |                 |


## 



- 
  
   RT-Thread  RT-Thread  
- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  MDK5  MDK5 

****

 USB  PC J-link  DEBUG  USB  UART4P512(TXD)P511(RXD)

****

-  project.uvprojx  MDK5 

>  J-Flash Lite  V7.50 [J-Link ](https://www.segger.com/downloads/jlink/)

-  J-Flash lite  R7FA6M5BH OK  BSP  MDK  /object/rtthread.hex  Program Device 

****



 PC , 115200-8-1-N RT-Thread  help 

```
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Nov 14 2022 20:43:44
 2006 - 2022 Copyright by RT-Thread team

Hello RT-Thread!
msh >
msh >
msh >
msh >ls
ls: command not found.
msh >lis
list_thread
list_sem
list_event
list_mutex
list_mailbox
list_msgqueue
list_timer
list_device
list
msh >listd
msh >list_d
list_device
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

- [](https://doc.embedfire.com/products/link/zh/latest/mcu/renesas/ebf_ra6m.html?from_wecom=1)
- [RA MCU ](https://www2.renesas.cn/cn/zh/document/gde/1520091)
- [RA6 MCU ](https://www2.renesas.cn/cn/zh/document/apn/ra6-quick-design-guide)

**FSP **

 BSP  [FSP](https://www2.renesas.cn/jp/zh/software-tool/flexible-software-package-fsp#document) [RT-Thread ](https://club.rt-thread.org/)

1. [ (FSP) | Renesas](https://www.renesas.com/cn/zh/software-tool/flexible-software-package-fsp) FSP 3.5.0 
2. [ FSP ](./docs/FSP.md) MDK  FSP 

**ENV **

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/#/development-tools/env/env)

 BSP  UART4  ENV 


1.  bsp  env 
2. `menuconfig`
3. `pkgs --update`
4. `scons --target=mdk5` 


## 

  [RT-Thread ](https://club.rt-thread.org/)

## 

 6M5  [ RT-Thread ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/development-guide/github/github)
