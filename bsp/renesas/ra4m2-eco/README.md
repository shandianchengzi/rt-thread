#  CPK-RA6M4  BSP 

## 

 RA-Eco-RA4M2-100PIN  BSP ()  BSP RT-Thread 



- 
- BSP 

## 

 RA4M2 MCU  RA-Eco-RA4M2-100PIN  IDE RA4M2 MCU 



![image-20221208102517429](docs/pictures/eco-ra4m2.jpg)

 **** 

- MCUR7FA4M2AD3CFB100MHzArm Cortex-M33 512kB , 128kB SRAM
-  SWD 
-  PMOD Arduino Uno

****

## 

 BSP 

| **** | **** | **** |
| :----------------- | :----------------- | :------------- |
| UART               |                | UART9  |
| GPIO               |                |                |
| SPI                |                |                |
| ...      |                    |                |
| **** | **** | **** |
|      |         |    |


## 



- 

   RT-Thread  RT-Thread  
- 

   RT-Thread  ENV  BSP 

### 

 BSP  MDK5  MDK5 

****

 USB () PCSWD DEBUG  USB  UART9P109(TXD)P110(RXD)

****

-  project.uvprojx  MDK5 

>  J-Flash Lite  V7.50 [J-Link ](https://www.segger.com/downloads/jlink/)

-  J-Flash lite  R7FA4M2AD OK  BSP  MDK  /object/rtthread.hex  Program Device 

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

- [](https://bbs.elecfans.com/jishu_2313024_1_1.html)
- [RA4M2](https://bbs.elecfans.com/forum.php?mod=attachment&aid=MTIwMDQxN3wxYWU5YWFiMnwxNjcwNDY2MTg2fDU5NTQxMXwyMzEyNjc4)
- [RA4M2](https://bbs.elecfans.com/forum.php?mod=attachment&aid=MTIwMDQxNnxjOTJiOTgyOHwxNjcwNDY2MTg2fDU5NTQxMXwyMzEyNjc4)

**FSP **
 [RA-Eco-RA4M2-100PIN](https://bbs.elecfans.com/jishu_2312678_1_1.html) bsp/renesas/docs
**ENV **

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/#/development-tools/env/env)

 BSP  UART9  ENV 


1.  bsp  env 
2. `menuconfig`
3. `pkgs --update`
4. `scons --target=mdk5` 


## FAQ

###  MDK  DEBUG   Error: Flash Download failed Cortex-M33 

 Utilities 

![image-20211214102231248](docs/pictures/readme_faq1.png)

## 

  [RT-Thread ](https://club.rt-thread.org/)

## 

 RA4M2  [ RT-Thread ](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/development-guide/github/github)
