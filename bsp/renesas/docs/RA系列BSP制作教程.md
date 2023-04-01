# RA  BSP 

 RENESAS RA  BSP  RA  BSP RA  BSP 

 RA  BSP  RA boardRT-Thread  RT-Thread `renesas\libraries\HAL_Drivers` BSP 

 RA  BSP **[](https://www2.renesas.cn/jp/zh/software-tool/flexible-software-package-fsp)** FSP RA  ARM FSP  HAL 

RA  BSP 

-  FSP  RA  BSP 
- 
-  FSP 

## 1. BSP  

BSP 

![BSP ](./figures/frame.png)

 BSP  BSP ra6m4-cpk 

||||
| - | - | :-- |
|  | renesas\libraries\HAL_Drivers |  RT-Thread  |
|  BSP | renesas\ra6m4-cpk | CPK-RA6M4  BSP  |

## 2. 

 BSP  BSP RT-Thread 

-  RA  BSP 

   BSP  [BSP ](../README.md) 

-  [Scons](https://www.rt-thread.org/document/site/#/development-tools/scons/scons) 

  RT-Thread  Scons  Scons  BSP 

- [](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/device)

   RT-Thread  BSP 

-  [Kconfig](https://www.rt-thread.org/document/site/#/development-tools/kconfig/kconfig) 

  RT-Thread  menuconfig  menuconfig  Kconfig  RT-Thread  kconfig 

-  [FSP](https://www2.renesas.cn/jp/zh/software-tool/flexible-software-package-fsp) 

  FSP  BSP  FSP 

## 3. BSP 

 CPK-RA6M4  BSP  BSP BSP  MDK  scons 

BSP 

1.  BSP 
2.  RA 
3. 
4.  Kconfig 
5. 
6. 
7.  GCC 
8.  rtconfig.py 

 BSP

### 3.1  BSP 

-  BSP  BSP  `\renesas\libraries\bsp-template`  `\renesas`  **CPK-RA6M4**  BSP  **ra6m4-cpk** ra6m4-cpk  **ra6m4-test**  BSP 

![image-20220217155725977](figures/bsp_crate.png) 

![image-20220217160140135](figures/bsp_crate1.png) 

![image-20220217161302858](figures/bsp_crate2.png) 

### 3.2  RA 

 FSP  RA 

-  FSP  /eclipse/rasc.exe 

![fsp_crate](figures/fsp_crate.png) 

![fsp_crate1](figures/fsp_crate1.png) 

![fsp_crate2](figures/fsp_crate2.png) 

![fsp_crate3](figures/fsp_crate3.png) 

![fsp_crate4](figures/fsp_crate4.png) 

![fsp_crate5](figures/fsp_crate5.png) 

![image-20220211182959790](figures/fsp_crate6.png) 

 RA  BSP 

### 3.3 

RA  GPIOUART

-  `template.uvprojx` 

![image-20220214174740157](figures/template_open.png) 

-  MDK 
> **Debug **  Debug  Device  Debug  Device 

![img](figures/template_config4.png) 

> **Device ** Device  device

![img](figures/template_config.png) 

> **Output **  `Name of Exexutable` rtthread `Create HEX File` HEX 

![image-20220218144358105](figures/template_config1.png) 

> **User ** TrustZone  Secure & Non-Secure  Flat mode cmd /c "start "Renesas" /w cmd /c ""$Slauncher\rasc_launcher.bat" "3.5.0" --gensecurebundle --compiler ARMv6 "$Pconfiguration.xml" "$L%L" 2> "%%TEMP%%\rasc_stderr.out"""

![img](figures/template_config2.png) 

> **C/C++ **-Wextra-Wconversion-Wshadow  
>
>  ra6m4-cpk -Wno-license-management -Wuninitialized -Wall -Wmissing-declarations -Wpointer-arith -Waggregate-return -Wfloat-equal

![img](figures/template_config3.png)  

> **Utilities **`Use External Tool for Flash Programming` `OK` 

![img](figures/template_config5.png) 

-  MDK  FSP

> ** MDK  FSP**
>
> 1.  MDK Tools -> Customize Tools Menu
> 2.  new : RA Smart Configurator
> 3. Command  rasc.exe (setup_fsp_xxxxx )
> 4. Initial Folder : $P
> 5. Arguments : --device $D --compiler ARMv6 configuration.xml
> 6.  OK Tools -> RA smart Configurator  
  ![img](figures/fsp_config.png) 
> 7. **RA Smart Config**  
  ![img](figures/fsp_config1.png) 

-  UART 
>  Stacks  New Stack  UART  
  ![image](figures/fsp_uart.png) 
>  msh  UART  UART  RT-Thread  **name** **channel**  **callback** channel = **X**name = g_uart**X**callback = user_uart**X**_callback  
  ![image](figures/fsp_uart1.png) 

### 3.4  Kconfig 

 `board/Kconfig`  `libraries/Kconfig` 

- 
- BSP 

`renesas\libraries\Kconfig` 

|              |      |                |
| ------------------ | -------- | ------------------ |
| SOC_R7FA6M4AF      |  | SOC_R7FAxxxxx      |
| SOC_SERIES_R7FA6M4 |  | SOC_SERIES_R7FAxxx |



![image-20220422164816261](figures\Kconfig1.png) 

 BSP  BSP  GPIO 

![ Kconfig](./figures/Kconfig.png) 

### 3.5 
-  config

![image-20220422163750161](figures\drv_config.png) 

	UART

![image-20220422164058202](figures\drv_config_uart.png) 

-  startup.c

>  **ra6m4-cpk\ra\fsp\src\bsp\cmsis\Device\RENESAS\Source\startup.c**

```c
#ifdef __ARMCC_VERSION
    main();
#elif defined(__GNUC__)
    extern int entry(void);
    entry();
#endif
```

![img](figures/startup_c.png) 

-  SRAM 

![image-20220303113833249](figures/board_config.png) 

-  GPIO 

 BSP  IRQ  FSP  IO  IRQ 

![image-20220217174433724](figures/bsp_gpio.png) 

- 

 RA  BSP  `src/hal_entry.c`  FSP  LED  `while(1)` 

```c
/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-10     Sherman       first version
 */

#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>

#define LED_PIN    BSP_IO_PORT_01_PIN_06 /* Onboard LED pins */

void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");

    while (1)
    {
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}
```

-  rtconfig.py CPU

![image-20220303165348085](figures/rtconfig_py.png) 

### 3.6 

 Env 

-  rtconfig.h 

 Env  menuconfig  rtconfig.h 

![menuconfig](./figures/menuconfig_1.png) 

 GPIO  console  UART 

![](./figures/menuconfig_2.png) 

 console 

![image-20220303103240414](figures/menuconfig2.png) 

-  MDK 
 MDK  BSP 

 env  `scons --target=mdk5` 

![ BSP ](./figures/menuconfig_3.png) 



![ BSP ](./figures/menuconfig_4.png) 

 MDK  BSP  GCC  GCC  

### 3.7  GCC 

GCC  IDE  e2studio e2studio 

![image-20220218114041568](figures/e2studio1.png) 

![image-20220218113955219](figures/e2studio.png) 

![image-20220218114633339](figures/e2studio2.png) 

![image-20220218114839257](figures/e2studio3.png) 

![image-20220218115035562](figures/e2studio4.png) 

![image-20220218115332866](figures/e2studio5.png) 

 xxx.ld  copy  BSP  script 

![image-20220218115715957](figures/e2studio6.png) 

- 

> **ra6m4-cpk\script\fsp.ld**

![image-20220215182642126](figures/linkscript1.png) 

>  text ** text{  } **

```shell
/* section information for finsh shell */
. = ALIGN(4);
__fsymtab_start = .;
KEEP(*(FSymTab))
__fsymtab_end = .;

. = ALIGN(4);
__vsymtab_start = .;
KEEP(*(VSymTab))
__vsymtab_end = .;

/* section information for initial. */
. = ALIGN(4);
__rt_init_start = .;
KEEP(*(SORT(.rti_fn*)))
__rt_init_end = .;

. = ALIGN(4);
KEEP(*(FalPartTable))
```

> 

![img](figures/linkscript.png) 

### 3.8  rtconfig.py 

![image-20220303165348085](figures/rtconfig_py.png) 

 scons [](https://www.rt-thread.org/document/site/#/development-tools/scons/scons?id=)     

 GCC  MDK  BSP  MDK  scons 

RT-Thread 

## 4. 

 RT-Thread RA  BSP   BSP  BSP  BSP  

### 4.1 BSP 

RA  3 ENV  IDE  RA  BSP  BSP BSP  BSP 

 BSP 

#### 4.1.1 

- RT-Thread 
- main 
  -  LED main ****  LED 1HZ 
-  `rt_hw_board_init`  `rt_system_heap_init`
-  GPIO  FinSH  DMA
- 
-  GCCMDK 
-  `scons --dist`  BSP  `dist` 

#### 4.1.2 ENV 

-  1000RT_TICK_PER_SECOND
- BSP RT_DEBUG
-  256IDLE_THREAD_STACK_SIZE
- RT_USING_COMPONENTS_INIT
-  user main RT_USING_USER_MAIN
-  libcRT_USING_LIBC
- FinSH  MSH FINSH_USING_MSH_ONLY

#### 4.1.3 IDE 

- 
-  C99 
-  One ELF Section per FunctionMDK
- MDK/IAR build MDK/IAR 
- MDK/GCC/IAR  hex  rtthread.hex

### 4.2 BSP 

-  BSP  README.md README.md  BSP  BSP [RA](./RA.md)
-  BSP  2 
  -  BSP  GPIO  FinSH  MDK5 IAR  GCC MDK4 BSP  README.md 
  -  menuconfig  review 
-  BSP  BSP
-  BSP 
-  BSP  BSP 
