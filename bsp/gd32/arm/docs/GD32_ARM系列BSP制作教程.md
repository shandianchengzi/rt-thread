# GD32  ARM BSP 

## 1. BSP 

BSP 

![BSP ](./figures/frame.png)

GD32 ARMBSPlibrariestoolsBoardslibrariesGD32Firmware LibraryRT-ThreaddriverstoolsPythonBoardsBoardsGD32407V-START

## 2. 

 BSP  BSP RT-Thread 

-   GD32 ARM BSP 
  
   BSP  [BSP ](../README.md) 

-  Scons 
  
  RT-Thread  Scons  Scons  BSP 

- 
  
   RT-Thread  BSP 

-  Kconfig 
  
  RT-Thread  menuconfig  menuconfig  Kconfig  RT-Thread  kconfig 

## 3. BSP

### 3.1 Keil

MDK for ARMKeil 4Keil 5Keil 44.74Keil 55.20MDK5.30

MDKMDK

[MDK](https://www.keil.com/download/product/)

![MDK_KEIL](./figures/mdk_keil.png)



GD32F4xx

[](http://www.gd32mcu.com/cn/download)

 ![Download](./figures/dowmload.png)

GigaDevice.GD32F4xx_DFP.2.1.0.pack

 ![install paxk](./figures/install_pack.png)

[Next]

 ![finish](./figures/pack_finish.png)

KeilFile->Device DatabaseGigadevice

 ![Gigadevice](./figures/Gigadevice.png)

### 3.2 BSP

**1.**

RT-ThreadBSPCortex-M4gd32407v-startBSPBSP

**2.BSP**

bsp/gd32/arm/gd32407v-start/SConstruct

```python
import os
import sys
import rtconfig

if os.getenv('RTT_ROOT'):
    RTT_ROOT = os.getenv('RTT_ROOT')
else:
    RTT_ROOT = os.path.normpath(os.getcwd() + '/../../../..')

sys.path = sys.path + [os.path.join(RTT_ROOT, 'tools')]
try:
    from building import *
except:
    print('Cannot found RT-Thread root directory, please check RTT_ROOT')
    print(RTT_ROOT)
    exit(-1)

TARGET = 'rtthread.' + rtconfig.TARGET_EXT

DefaultEnvironment(tools=[])
env = Environment(tools = ['mingw'],
    AS = rtconfig.AS, ASFLAGS = rtconfig.AFLAGS,
    CC = rtconfig.CC, CFLAGS = rtconfig.CFLAGS,
    AR = rtconfig.AR, ARFLAGS = '-rc',
    CXX = rtconfig.CXX, CXXFLAGS = rtconfig.CXXFLAGS,
    LINK = rtconfig.LINK, LINKFLAGS = rtconfig.LFLAGS)
env.PrependENVPath('PATH', rtconfig.EXEC_PATH)

if rtconfig.PLATFORM in ['iccarm']:
    env.Replace(CCCOM = ['$CC $CFLAGS $CPPFLAGS $_CPPDEFFLAGS $_CPPINCFLAGS -o $TARGET $SOURCES'])
    env.Replace(ARFLAGS = [''])
    env.Replace(LINKCOM = env["LINKCOM"] + ' --map rtthread.map')

Export('RTT_ROOT')
Export('rtconfig')

SDK_ROOT = os.path.abspath('./')

if os.path.exists(SDK_ROOT + '/libraries'):
    libraries_path_prefix = SDK_ROOT + '/libraries'
else:
    libraries_path_prefix = os.path.dirname(SDK_ROOT) + '/libraries'

SDK_LIB = libraries_path_prefix
Export('SDK_LIB')

# prepare building environment
objs = PrepareBuilding(env, RTT_ROOT, has_libcpu=False)

gd32_library = 'GD32F4xx_Firmware_Library'
rtconfig.BSP_LIBRARY_TYPE = gd32_library

# include libraries
objs.extend(SConscript(os.path.join(libraries_path_prefix, gd32_library, 'SConscript')))

# include drivers
objs.extend(SConscript(os.path.join(libraries_path_prefix, 'Drivers', 'SConscript')))

# make a building
DoBuilding(TARGET, objs)
```

make

**3.KEIL**

template.uvprojx

:

 ![Chip](./figures/chip.png)

FLASHRAM:

 ![storage](./figures/storage.png)



![rename](./figures/rename.png)

CMSIS-DAP Debugger

![Debug](./figures/debug.png)

GD32F4xx FMC

![FMC](./figures/FMC.png)

**4.board**

(1) bsp/gd32/arm/gd32407v-start/board/linker_scripts/link.icf



```
/*###ICF### Section handled by ICF editor, don't touch! /
/*-Editor annotation file-*/
/* IcfEditorFile="$TOOLKIT_DIR$\config\ide\IcfEditor\cortex_v1_0.xml" */
/*-Specials-*/
define symbol __ICFEDIT_intvec_start__ = 0x08000000;
/*-Memory Regions-*/
define symbol __ICFEDIT_region_ROM_start__ = 0x08000000;
define symbol __ICFEDIT_region_ROM_end__   = 0x082FFFFF;
define symbol __ICFEDIT_region_RAM_start__ = 0x20000000;
define symbol __ICFEDIT_region_RAM_end__   = 0x2002FFFF;
/*-Sizes-*/
define symbol __ICFEDIT_size_cstack__ = 0x2000;
define symbol __ICFEDIT_size_heap__   = 0x2000;
/ End of ICF editor section. ###ICF###*/

export symbol __ICFEDIT_region_RAM_end__;

define symbol __region_RAM1_start__ = 0x10000000;
define symbol __region_RAM1_end__   = 0x1000FFFF;

define memory mem with size = 4G;
define region ROM_region   = mem:[from __ICFEDIT_region_ROM_start__   to __ICFEDIT_region_ROM_end__];
define region RAM_region   = mem:[from __ICFEDIT_region_RAM_start__   to __ICFEDIT_region_RAM_end__];
define region RAM1_region  = mem:[from __region_RAM1_start__   to __region_RAM1_end__];

define block CSTACK    with alignment = 8, size = __ICFEDIT_size_cstack__   { };
define block HEAP      with alignment = 8, size = __ICFEDIT_size_heap__     { };

initialize by copy { readwrite };
do not initialize  { section .noinit };

keep { section FSymTab };
keep { section VSymTab };
keep { section .rti_fn* };
place at address mem:__ICFEDIT_intvec_start__ { readonly section .intvec };

place in ROM_region   { readonly };
place in RAM_region   { readwrite,
                        block CSTACK, block HEAP };                        
place in RAM1_region  { section .sram };
```

IARGD32F407xx_Datasheet_Rev2.1GD32F407VKT6flash3072KBSRAM192KBROMRAM

(2) bsp/gd32/arm/gd32407v-start/board/linker_scripts/link.ld



```
/* Program Entry, set to mark it as "used" and avoid gc */
MEMORY
{
    CODE (rx) : ORIGIN = 0x08000000, LENGTH = 3072k /* 3072KB flash */
    DATA (rw) : ORIGIN = 0x20000000, LENGTH =  192k /* 192KB sram */
}
ENTRY(Reset_Handler)
_system_stack_size = 0x200;

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        _stext = .;
        KEEP(*(.isr_vector))            /* Startup code */
        . = ALIGN(4);
        *(.text)                        /* remaining code */
        *(.text.*)                      /* remaining code */
        *(.rodata)                      /* read-only data (constants) */
        *(.rodata*)
        *(.glue_7)
        *(.glue_7t)
        *(.gnu.linkonce.t*)

        /* section information for finsh shell */
        . = ALIGN(4);
        __fsymtab_start = .;
        KEEP(*(FSymTab))
        __fsymtab_end = .;
        . = ALIGN(4);
        __vsymtab_start = .;
        KEEP(*(VSymTab))
        __vsymtab_end = .;
        . = ALIGN(4);

        /* section information for initial. */
        . = ALIGN(4);
        __rt_init_start = .;
        KEEP(*(SORT(.rti_fn*)))
        __rt_init_end = .;
        . = ALIGN(4);

        . = ALIGN(4);
        _etext = .;
    } > CODE = 0

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)

        /* This is used by the startup in order to initialize the .data secion */
        _sidata = .;
    } > CODE
    __exidx_end = .;

    /* .data section which is used for initialized data */

    .data : AT (_sidata)
    {
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        _sdata = . ;

        *(.data)
        *(.data.*)
        *(.gnu.linkonce.d*)

        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        _edata = . ;
    } >DATA

    .stack : 
    {
        . = . + _system_stack_size;
        . = ALIGN(4);
        _estack = .;
    } >DATA

    __bss_start = .;
    .bss :
    {
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .bss secion */
        _sbss = .;

        *(.bss)
        *(.bss.*)
        *(COMMON)

        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .bss secion */
        _ebss = . ;

        *(.bss.init)
    } > DATA
    __bss_end = .;

    _end = .;

    /* Stabs debugging sections.  */
    .stab          0 : { *(.stab) }
    .stabstr       0 : { *(.stabstr) }
    .stab.excl     0 : { *(.stab.excl) }
    .stab.exclstr  0 : { *(.stab.exclstr) }
    .stab.index    0 : { *(.stab.index) }
    .stab.indexstr 0 : { *(.stab.indexstr) }
    .comment       0 : { *(.comment) }
    /* DWARF debug sections.
     * Symbols in the DWARF debugging sections are relative to the beginning
     * of the section so we begin them at 0.  */
    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }
    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }
    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }
    /* SGI/MIPS DWARF 2 extensions */
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames  0 : { *(.debug_varnames) }
}
```

GCCGD32F407xx_Datasheet_Rev2.1GD32F407VKT6flash3072KBSRAM192KBCODEDATA LENGTH3072KB192KB

(3) bsp/gd32/arm/gd32407v-start/board/linker_scripts/link.sct


```
; *************************************************************
; *** Scatter-Loading Description File generated by uVision ***
; *************************************************************

LR_IROM1 0x08000000 0x00300000  {    ; load region size_region
  ER_IROM1 0x08000000 0x00300000  {  ; load address = execution address
   *.o (RESET, +First)
   *(InRoot$$Sections)
   .ANY (+RO)
  }
  RW_IRAM1 0x20000000 0x00030000  {  ; RW data
   .ANY (+RW +ZI)
  }
}
```

MDKGD32F407xx_Datasheet_Rev2.1 LR_IROM1  ER_IROM1  0x00300000RAM 192k RW_IRAM1  0x00030000

(4) bsp/gd32/arm/gd32407v-start/board/board.h



```c
#ifndef __BOARD_H__
#define __BOARD_H__

#include "gd32f4xx.h"
#include "drv_usart.h"
#include "drv_gpio.h"

#include "gd32f4xx_exti.h"

#define EXT_SDRAM_BEGIN    (0xC0000000U) /* the begining address of external SDRAM */
#define EXT_SDRAM_END      (EXT_SDRAM_BEGIN + (32U * 1024 * 1024)) /* the end address of external SDRAM */

// <o> Internal SRAM memory size[Kbytes] <8-64>
//  <i>Default: 64
#ifdef __ICCARM__
// Use *.icf ram symbal, to avoid hardcode.
extern char __ICFEDIT_region_RAM_end__;
#define GD32_SRAM_END          &__ICFEDIT_region_RAM_end__
#else
#define GD32_SRAM_SIZE         192
#define GD32_SRAM_END          (0x20000000 + GD32_SRAM_SIZE * 1024)
#endif

#ifdef __CC_ARM
extern int Image$$RW_IRAM1$$ZI$$Limit;
#define HEAP_BEGIN    (&Image$$RW_IRAM1$$ZI$$Limit)
#elif __ICCARM__
#pragma section="HEAP"
#define HEAP_BEGIN    (__segment_end("HEAP"))
#else
extern int __bss_end;
#define HEAP_BEGIN    (&__bss_end)
#endif

#define HEAP_END          GD32_SRAM_END

#endif
```

 HEAP_BEGIN  HEAP_END HEAP_BEGIN  HEAP_END 

(5) bsp/gd32/arm/gd32407v-start/board/board.c



```c
#include <stdint.h>
#include <rthw.h>
#include <rtthread.h>
#include <board.h>

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
    */
    void Error_Handler(void)
    {
    /* USER CODE BEGIN Error_Handler */
    /* User can add his own implementation to report the HAL error return state */
    while (1)
    {
    }
    /* USER CODE END Error_Handler */
    }

/** System Clock Configuration
*/
void SystemClock_Config(void)
{
    SysTick_Config(SystemCoreClock / RT_TICK_PER_SECOND);
    NVIC_SetPriority(SysTick_IRQn, 0);
}

/**
 * This is the timer interrupt service routine.
 *
    */
  void SysTick_Handler(void)
  {
    /* enter interrupt */
    rt_interrupt_enter();

    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
  }

/**
 * This function will initial GD32 board.
 */
    void rt_hw_board_init()
    {
    /* NVIC Configuration */
    #define NVIC_VTOR_MASK              0x3FFFFF80
    #ifdef  VECT_TAB_RAM
    /* Set the Vector Table base location at 0x10000000 */
    SCB->VTOR  = (0x10000000 & NVIC_VTOR_MASK);
    #else  /* VECT_TAB_FLASH  */
    /* Set the Vector Table base location at 0x08000000 */
    SCB->VTOR  = (0x08000000 & NVIC_VTOR_MASK);
    #endif

    SystemClock_Config();

#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif

#ifdef RT_USING_CONSOLE
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#endif

#ifdef BSP_USING_SDRAM
    rt_system_heap_init((void *)EXT_SDRAM_BEGIN, (void *)EXT_SDRAM_END);
#else
    rt_system_heap_init((void *)HEAP_BEGIN, (void *)HEAP_END);
#endif
}
```

SystemClock_ConfigSystemCoreClocksystem_gd32f4xx.c

(6) bsp/gd32/arm/gd32407v-start/board/Kconfig


```config
menu "Hardware Drivers Config"
config SOC_SERIES_GD32F4xx
    default y

config SOC_GD32407V
    bool 
    select SOC_SERIES_GD32F4xx
    select RT_USING_COMPONENTS_INIT
    select RT_USING_USER_MAIN
    default y

menu "Onboard Peripheral Drivers"

endmenu

menu "On-chip Peripheral Drivers"

    config BSP_USING_GPIO
        bool "Enable GPIO"
        select RT_USING_PIN
        default y

    menuconfig BSP_USING_UART
        bool "Enable UART"
        default y
        select RT_USING_SERIAL
        if BSP_USING_UART
            config BSP_USING_UART1
                bool "Enable UART1"
                default y

            config BSP_UART1_RX_USING_DMA
                bool "Enable UART1 RX DMA"
                depends on BSP_USING_UART1 && RT_SERIAL_USING_DMA
                default n
        endif

    menuconfig BSP_USING_SPI
        bool "Enable SPI BUS"
        default n
        select RT_USING_SPI
        if BSP_USING_SPI
            config BSP_USING_SPI1
                bool "Enable SPI1 BUS"
                default n

            config BSP_SPI1_TX_USING_DMA
                bool "Enable SPI1 TX DMA"
                depends on BSP_USING_SPI1
                default n

            config BSP_SPI1_RX_USING_DMA
                bool "Enable SPI1 RX DMA"
                depends on BSP_USING_SPI1
                select BSP_SPI1_TX_USING_DMA
                default n
        endif

    menuconfig BSP_USING_I2C1
        bool "Enable I2C1 BUS (software simulation)"
        default n
        select RT_USING_I2C
        select RT_USING_I2C_BITOPS
        select RT_USING_PIN
        if BSP_USING_I2C1
            config BSP_I2C1_SCL_PIN
                int "i2c1 scl pin number"
                range 1 216
                default 24
            config BSP_I2C1_SDA_PIN
                int "I2C1 sda pin number"
                range 1 216
                default 25
        endif
    source "../libraries/gd32_drivers/Kconfig"

endmenu

menu "Board extended module Drivers"

endmenu

endmenu
```



(7) bsp/gd32/arm/gd32407v-start/board/SConscript



```python
import os
import rtconfig
from building import *

Import('SDK_LIB')

cwd = GetCurrentDir()

# add general drivers
src = Split('''
board.c
''')

path =  [cwd]

startup_path_prefix = SDK_LIB

if rtconfig.PLATFORM in ['gcc']:
    src += [startup_path_prefix + '/GD32F4xx_Firmware_Library/CMSIS/GD/GD32F4xx/Source/GCC/startup_gd32f4xx.s']
elif rtconfig.PLATFORM in ['armcc', 'armclang']:
    src += [startup_path_prefix + '/GD32F4xx_Firmware_Library/CMSIS/GD/GD32F4xx/Source/ARM/startup_gd32f4xx.s']
elif rtconfig.PLATFORM in ['iccarm']:
    src += [startup_path_prefix + '/GD32F4xx_Firmware_Library/CMSIS/GD/GD32F4xx/Source/IAR/startup_gd32f4xx.s']

CPPDEFINES = ['GD32F407']
group = DefineGroup('Drivers', src, depend = [''], CPPPATH = path, CPPDEFINES = CPPDEFINES)

Return('group')
```

board.clibrariesSConscript

menuconfig

**5.menuconfig**


![Disable socket](./figures/disable_socket.png)



![Disable net](./figures/disable_net.png)

LWIP

![Disable lwip](./figures/disable_lwip.png)

GD32407V-STARTGD32407V-STARTMCU

**6.**
BSP2
LEDGPIO

LED

**7.**

applicationsmain.cLED

```c
#include <stdio.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* defined the LED2 pin: PC6 */
#define LED2_PIN GET_PIN(C, 6)

int main(void)
{
    int count = 1;

    /* set LED2 pin mode to output */
    rt_pin_mode(LED2_PIN, PIN_MODE_OUTPUT);

    while (count++)
    {
        rt_pin_write(LED2_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED2_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }

    return RT_EOK;
}
```

GPIO

**8.ENV**
envscons 

![scons](./figures/scons.png)



![scons_success](./figures/scons_success.png)

**9.envMDK**
envscons --target=mdk5

![scons_mdk5](./figures/scons_mdk5.png)

MDKMDK

![MDK Build](./figures/MDK_Build.png)



![MDK Build success](./figures/MDK_Build_Success.png)

### 3.3 GD-Link GD32

ENVMDKBSPGD32GD-linkGD-linkGD-link

1.GD-link

Options for Target -> Debug CMSIS-DAP DebuggerKeil4.74Keil5CMSIS-DAP Debugger

 ![CMSIS-DAP Debugger](./figures/CMSIS-DAP_Debugger.png)

2.Options for Target -> Debug ->SettingsSWJ Port SWIDcode0xXBAXXXXX

 ![setting1](./figures/setting1.png)

3.Options for Target -> Debug ->Settings -> Flash DownloadGD32flash

 ![setting2](./figures/setting2.png)

4.debug GD-Link

 ![GD link debug](./figures/gdlink_debug.png)

GD-Link

 ![GD link download](./figures/gdlink_download.png)



![download success](./figures/download_success.png)



![UART print](./figures/com_print.png)

LED

### 3.4 RT-Thread studio

rt-thread studio

scons --dist

![scons dist](./figures/scons_dist.png)

rt-thread studio

 ![import_rt-thread_studio](./figures/import_rt-thread_studio.png)

rt-thread studio

![rt-thread_studio](./figures/rt-thread_studio.png)

## 4. 

 RT-Thread GD32  BSP   BSP  BSP  BSP  

### 4.1 BSP 

GD32 BSP  3 ENV  IDE  GD32  BSP  BSP BSP  BSP 

 BSP 

#### 4.1.1 

- RT-Thread 
- main 
  -  LED main ****  LED 1HZ 
-  `rt_hw_board_init`  `rt_system_heap_init`
-  GPIO  FinSH  DMA
- 
-  GCC/MDK/IAR 
-  `dist`  BSP  `dist` 

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
- MDK/GCC/IAR  bin  rtthread.bin

### 4.2 BSP 

-  BSP  README.md README.md  BSP  BSP [GD32 ARM](./GD32 ARM.md)
-  BSP  2 
  -  BSP  GPIO  FinSH  MDK4MDK5 IAR  GCC MDK4 BSP  README.md 
  -  menuconfig  review 
-  BSP  BSP
-  GD32  Library  f1/f4  HAL 
-  BSP 
-  BSP  BSP 