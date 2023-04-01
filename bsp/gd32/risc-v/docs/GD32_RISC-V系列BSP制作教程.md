# GD32  RISC-V BSP 

## 1. BSP 

BSP 

![BSP ](./figures/frame.png)

GD32BSPlibrariestoolsBoardslibrariesGD32Firmware LibraryRT-ThreaddriverstoolsPythonBoardsBoardsGD32VF103V_EVAL

## 2. 

 BSP  BSP RT-Thread 

-   GD32  RISC-V BSP 
  
   BSP  [BSP ](../README.md) 

-  RISC-VMCU
  
-  Scons 
  
  RT-Thread  Scons  Scons  BSP 

- 
  
   RT-Thread  BSP 

-  Kconfig 
  
  RT-Thread  menuconfig  menuconfig  Kconfig  RT-Thread  kconfig 

## 3. BSP

### 3.1 GCC

RISC-VMCUxPack GNU RISC-V Embedded GCC

GCC

[GCC](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/)

![GCC](./figures/gcc.png)





### 3.2 BSP

**1.**
RT-ThreadBSPRISC-VGD32 ARM
```
risc-v
docs # 
gd32vf103v-eval # BSP
libraries # 
  gd32_drivers
  GD32VF103_Firmware_Library # GD
tools
  OpenOCD # OpenOCD 
README.md
```
**2.BSP**
bsp/gd32/risc-v/gd32vf103v-eval/SConstruct
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
    CC = rtconfig.CC, CCFLAGS = rtconfig.CFLAGS,
    AR = rtconfig.AR, ARFLAGS = '-rc',
    CXX = rtconfig.CXX, CXXFLAGS = rtconfig.CXXFLAGS,
    LINK = rtconfig.LINK, LINKFLAGS = rtconfig.LFLAGS)
env.PrependENVPath('PATH', rtconfig.EXEC_PATH)
env['ASCOM'] = env['ASPPCOM']

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
# objs = PrepareBuilding(env, RTT_ROOT, has_libcpu=False)
objs = PrepareBuilding(env, RTT_ROOT)

gd32_library = 'GD32VF103_Firmware_Library'
rtconfig.BSP_LIBRARY_TYPE = gd32_library

# include libraries
objs.extend(SConscript(os.path.join(libraries_path_prefix, gd32_library, 'SConscript')))

# include drivers
objs.extend(SConscript(os.path.join(libraries_path_prefix, 'gd32_drivers', 'SConscript')))

# make a building
DoBuilding(TARGET, objs)
```
make

bsp/gd32/risc-v/gd32vf103v-eval/rtconfig.py
```python
import os

# toolchains options
ARCH='risc-v'
CPU='bumblebee'
CROSS_TOOL='gcc'

# bsp lib config
BSP_LIBRARY_TYPE = None

if os.getenv('RTT_CC'):
    CROSS_TOOL = os.getenv('RTT_CC')
if os.getenv('RTT_ROOT'):
    RTT_ROOT = os.getenv('RTT_ROOT')

# cross_tool provides the cross compiler
# EXEC_PATH is the compiler execute path, for example, CodeSourcery, Keil MDK, IAR
if  CROSS_TOOL == 'gcc':
    PLATFORM    = 'gcc'
    EXEC_PATH   = EXEC_PATH   = r'D:/gcc/xpack-riscv-none-embed-gcc-10.2.0-1.2/bin'
else:
    print('Please make sure your toolchains is GNU GCC!')
    exit(0)

if os.getenv('RTT_EXEC_PATH'):
    EXEC_PATH = os.getenv('RTT_EXEC_PATH')

CORE = 'risc-v'
BUILD = 'debug'
MAP_FILE = 'rtthread.map'
LINK_FILE = '../libraries/GD32VF103_Firmware_Library/RISCV/env_Eclipse/GD32VF103xB.lds'

if PLATFORM == 'gcc':
    # toolchains
    PREFIX = 'riscv-none-embed-'
    CC = PREFIX + 'gcc'
    AS = PREFIX + 'gcc'
    AR = PREFIX + 'ar'
    CXX = PREFIX + 'g++'
    LINK = PREFIX + 'gcc'
    TARGET_EXT = 'elf'
    SIZE = PREFIX + 'size'
    OBJDUMP = PREFIX + 'objdump'
    OBJCPY = PREFIX + 'objcopy'

    DEVICE = ' -march=rv32imac -mabi=ilp32 -DUSE_PLIC -DUSE_M_TIME -DNO_INIT -mcmodel=medany -msmall-data-limit=8 -L.  -nostartfiles  -lc '
    CFLAGS = DEVICE
    CFLAGS += ' -save-temps=obj'
    AFLAGS = '-c'+ DEVICE + ' -x assembler-with-cpp'
    AFLAGS += ' -Iplatform -Ilibraries/RISCV/include -Ilibraries/RISCV/env_Eclipse'
    LFLAGS = DEVICE
    LFLAGS += ' -Wl,--gc-sections,-cref,-Map=' + MAP_FILE
    LFLAGS += ' -T ' + LINK_FILE
    LFLAGS += ' -Wl,-wrap=memset'
    
    CPATH = ''
    LPATH = ''
    
    if BUILD == 'debug':
        CFLAGS += ' -O0 -g3'
        AFLAGS += ' -g3'
    else:
        CFLAGS += ' -O2'
    
    CXXFLAGS = CFLAGS 
    
    POST_ACTION = OBJCPY + ' -O binary $TARGET rtthread.bin\n' + SIZE + ' $TARGET \n'

def dist_handle(BSP_ROOT, dist_dir):
    import sys
    cwd_path = os.getcwd()
    sys.path.append(os.path.join(os.path.dirname(BSP_ROOT), 'tools'))
    from sdk_dist import dist_do_building
dist_do_building(BSP_ROOT, dist_dir)
```
gd32vf103v-evalGD32VF103VBGD32VF103xB.lds

**3.board**
(1) bsp/gd32/risc-v/gd32vf103v-eval/board/Kconfig


```
menu "Hardware Drivers Config"

config SOC_SERIES_GD32VF103V
    bool
    default y

config SOC_GD32VF103V
    bool
    select SOC_SERIES_GD32VF103V
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
            config BSP_USING_UART0
                bool "Enable UART0"
                default y
    
            config BSP_UART0_RX_USING_DMA
                bool "Enable UART0 RX DMA"
                depends on BSP_USING_UART0 
                select RT_SERIAL_USING_DMA
                default n
    
            config BSP_USING_UART1
                bool "Enable UART1"
                default n
    
            config BSP_UART1_RX_USING_DMA
                bool "Enable UART1 RX DMA"
                depends on BSP_USING_UART1 
                select RT_SERIAL_USING_DMA
                default n
    
            config BSP_USING_UART2
                bool "Enable UART2"
                default n
    
            config BSP_UART2_RX_USING_DMA
                bool "Enable UART2 RX DMA"
                depends on BSP_USING_UART2 
                select RT_SERIAL_USING_DMA
                default n
    
            config BSP_USING_UART3
                bool "Enable UART3"
                default n
    
            config BSP_UART3_RX_USING_DMA
                bool "Enable UART3 RX DMA"
                depends on BSP_USING_UART3 
                select RT_SERIAL_USING_DMA
                default n
    
            config BSP_USING_UART4
                bool "Enable UART4"
                default n
    
            config BSP_UART4_RX_USING_DMA
                bool "Enable UART4 RX DMA"
                depends on BSP_USING_UART4 
                select RT_SERIAL_USING_DMA
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
    
    menuconfig BSP_USING_ADC
        bool "Enable ADC"
        default n
        select RT_USING_ADC
        if BSP_USING_ADC
            config BSP_USING_ADC0
                bool "Enable ADC0"
                default n
    
            config BSP_USING_ADC1
                bool "Enable ADC1"
                default n
    
            config BSP_USING_ADC2
                bool "Enable ADC2"
                default n
        endif
    
    menuconfig BSP_USING_TIM
        bool "Enable timer"
        default n
        select RT_USING_HWTIMER
        if BSP_USING_TIM
            config BSP_USING_TIM10
                bool "Enable TIM10"
                default n
    
            config BSP_USING_TIM11
                bool "Enable TIM11"
                default n
    
            config BSP_USING_TIM12
                bool "Enable TIM13"
                default n
        endif
    
    menuconfig BSP_USING_ONCHIP_RTC
        bool "Enable RTC"
        select RT_USING_RTC
        default n
        if BSP_USING_ONCHIP_RTC
            choice
                prompt "Select clock source"
                default BSP_RTC_USING_LSE
    
                config BSP_RTC_USING_LSE
                    bool "RTC USING LSE"
    
                config BSP_RTC_USING_LSI
                    bool "RTC USING LSI"
            endchoice
        endif
    
    config BSP_USING_WDT
        bool "Enable Watchdog Timer"
        select RT_USING_WDT
        default n
    
    source "../libraries/gd32_drivers/Kconfig"

endmenu

menu "Board extended module Drivers"

endmenu

endmenu
```


(2) bsp/gd32/risc-v/gd32vf103v-eval/board/SConscript

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
    src += [startup_path_prefix + '/GD32VF103_Firmware_Library/RISCV/env_Eclipse/start.S']
    src += [startup_path_prefix + '/GD32VF103_Firmware_Library/RISCV/env_Eclipse/entry.S']

CPPDEFINES = ['GD32VF103V_EVAL']
group = DefineGroup('Drivers', src, depend = [''], CPPPATH = path, CPPDEFINES = CPPDEFINES)


Return('group')
```
board.clibrariesSConscript



**4.**
(1) bsp/gd32/risc-v/libraries/GD32VF103_Firmware_Library/RISCV/env_Eclipse/start.S
GCC  entry()  rt_thread_startup()C

![start](./figures/start.png)


(2) bsp/gd32/risc-v/libraries/GD32VF103_Firmware_Library/RISCV/env_Eclipse/GD32VF103xB.lds
GD32VF103xB.ldsRT-Thread
```
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

/* section information for modules */
. = ALIGN(4);
__rtmsymtab_start = .;
KEEP(*(RTMSymTab))
__rtmsymtab_end = .;
```

![GD32VF103xB](./figures/GD32VF103xB.png)

**5.**
BSP0

LEDGPIO

LED

**6.**
applicationsmain.cLED

```c
#include <stdio.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* defined the LED1 pin: PC0 */
#define LED1_PIN GET_PIN(C, 0)

int main(void)
{
    int count = 1;

    /* set LED1 pin mode to output */
    rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
    
    while (count++)
    {
        rt_pin_write(LED1_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED1_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
    
    return RT_EOK;
}
```

GPIO

**7.ENV**
envscons 

![scons ](./figures/scons.png)



![scons_success](./figures/scons_success.png) 

**8.VS CodeGD32**
envscons --target=vsc

![vsc](./figures/vsc.png)

VSCodeGD32c_cpp_properties.jsonVS Code

### 3.3
ENVGD32VF103V-SEVALOpenOCD

OpenOCDRISC-VOpenOCDGD-LinkJ-LinkOpenOCDbsp/gd32/risc-v/toolsVS Code

**1.bsp/gd32/risc-v/gd32vf103v-eval/.vscode/tasks.json**

tasks.jsontasks.json
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "download",
            "type": "shell",
            "command": "../tools/OpenOCD/bin/openocd.exe",
            "args": [
                "-f",
                "../tools/interface/openocd_gdlink_riscv.cfg",
                "-c",
                "program rtthread.elf exit"
            ] 
        }
    ]
}
```
download
->

![svc_run_task](./figures/svc_run_task.png)

taskdownload

![svc_download](./figures/svc_download.png)



![svc_download_success](./figures/svc_download_success.png)


0

![run](./figures/run.png)

LED


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
-  GCC/IAR 
-  `dist`  BSP  `dist` 

#### 4.1.2 ENV 

-  1000RT_TICK_PER_SECOND
- BSP RT_DEBUG
-  256IDLE_THREAD_STACK_SIZE
- RT_USING_COMPONENTS_INIT
-  user main RT_USING_USER_MAIN
-  libcRT_USING_LIBC
- FinSH  MSH FINSH_USING_MSH_ONLY

### 4.2 BSP 

-  BSP  README.md README.md  BSP  BSP [GD32](./GD32 RISC-V.md)
-  BSP  2 
  -  BSP  GPIO  FinSH IAR  GCC  BSP  README.md 
  -  menuconfig  review 
-  BSP  BSP
-  BSP 
-  BSP  BSP 