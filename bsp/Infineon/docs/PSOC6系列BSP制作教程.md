# Infineon-PSOC6  BSP 

 BSP RT-Thread  Infineon-PSOC6  BSP 

BSP  BSP  Library  BSP  BSP  BSP 

## 1.BSP  

![](./figures/frame.png)

 PSOC6  BSP BSP  BSP PSOC62  BSP 

|                     |                               |                                                          |
| ----------------------- | ----------------------------------- | :----------------------------------------------------------- |
|                   | Infineon/libraries                  |  HAL  HAL        |
| PSOC6  BSP  | Infineon/libraries/templates/PSOC6X | PSOC6  BSP  PSOC6  BSP |
|  BSP          | Infineon/psoc6-cy8ckit-062S2-43012  |  BSP                                   |

## 2. 

 BSP  BSP RT-Thread 

-   PSOC6  BSP 

   BSP  [BSP ](../psoc6-cy8ckit-062S2-43012/README.md) 

-  Scons 

  RT-Thread  Scons  Scons  BSP 

- 

   RT-Thread  BSP 

-  Kconfig 

  RT-Thread  menuconfig  menuconfig  Kconfig  RT-Thread  kconfig 

## 3. BSP 

 `psoc6-cy8ckit-062S2-43012`  BSP  BSP

BSP 

1. 
2. 
3.  BSP  Kconfig 
4. 
5. 

 BSP

### 3.1 

 BSP  BSP  BSP  BSP BSP 

|                    |                  |
| -------------------------- | -------------------- |
| libraries/templates/PSOC62 | PSOC62  BSP  |

 PSOC62  BSP 

![](./figures/bsp_template_dir.png)

 BSP  board  PSOC62  BSP  `psoc6-cy8ckit-062S2-43012`  BSP  board 

|                       |                         |
| ------------------------- | ----------------------------------------- |
| linker_scripts  | BSP                         |
| board.c/h                 | GPIO  |
| Kconfig                   |                   |
| SConscript                |                 |

### 3.2 

 **board.h**  FLASH  RAM `IFX_SRAM_SIZE`  BSP  CY8CKIT-062S2-43012  RAM  1M

![](./figures/board_h.png)

#### 3.2.1 

 RAM  **HEAP_BEGIN**  **HEAP_END** **HEAP_BEGIN**  **HEAP_END**   [3.5.1 ](# 3.5.1 ) 

 RAM 

![](figures/heap_config.png)

### 3.3  Kconfig 

 `board/Kconfig` 

- 
- BSP 



|                |      |                    |
| -------------------- | -------- | ---------------------- |
| SOC_CY8C624ABZI_S2D44 |  | SOC_CY8C6xxx_xxxx  |
| SOC_SERIES_IFX_PSOC62 |  | SOC_SERIES_IFX_PSOC6x |

 BSP  BSP 

![](./figures/Kconfig.png)

### 3.4 

#### 3.4.1 

 BSP  Modus ** PSOC6 **

![](./figures/hal_config2.png)

Modus  Modus  `mtb_shared` ** PSOC6 **

![](./figures/hal_config3.png)

 BSP  `libraries/IFX_PSOC6_HAL` ** PSOC6 **

![](./figures/hal_config1.png)

 [TARGET_CY8CKIT-062S2-43012](https://github.com/Infineon/TARGET_CY8CKIT-062S2-43012/releases)  **V3.0.0**  BSP  libs 

![](./figures/hal_config4.png)

 BSP  libs 

![](./figures/hal_config4-1.png)

### 3.5 



#### 3.5.1 

**linker_scripts** 

![](./figures/linker_scripts.png)

 **GCC**  link.ld 

![](./figures/link_lds.png)

****

**FLASH**  **RAM**  **TARGET_CY8CKIT-062S2-43012**  TARGET_CY8CKIT-062S2-43012/COMPONENT_CM4/TOOLCHAIN_ARMTOOLCHAIN_GCC_ARM/cy8c6xxa_cm4_dual.sct.ld

![](./figures/link_ifx1.png)

![](./figures/link_ifx2.png)

****

 BSP   `CY8CKIT-062S2-43012` FLASH  **2M** FLASH_SIZE  `0x00020000`RAM  **1M**  RAM_SIZE  `0x000FD800` [**3.2.1 **](# 3.2.1 )  BSP 

---

MDK  link.sct

* link.sct 

![](./figures/linkscripts_change.png)

####  3.5.2 

**SConscript**  **MDK/IAR/RT-Thread Studio** 

** PSOC6 **

![](./figures/hal_config5.png)



![](./figures/hal_config5-1.png)

** PSOC6 **

![](./figures/hal_config6.png)



![](./figures/hal_config7.png)

 **CPPDEFINES**  

![](./figures/SConscript2.png)

BSP  lib/SConscript 

![](./figures/SConscript1.png)

****

 GCC  **main**  **entry**

![](./figures/entry.png)

#### 3.5.3 

rtconfig.py  **CROSS_TOOL**  PSCOC6  GCC  ArmClang 

![](./figures/rt_configpy.png)

#### 3.5.4 

MDK 

**template**  MDK/IAR MDK4/MDK5/IAR 

![](./figures/template_1.png)

 MDK5 

![](./figures/template_2.png)



![](./figures/template_3.png)

---

**RT-Thread Studio** 

1 ENV  `scons --dist` 

![](./figures/dist1.png)

 BSP  `dist` 

![](./figures/dist2.png)

 dist  RT-Thread Studio 

![](./figures/dist3.png)

 RT-Thread Studio  IDE  `>>RT-Thread Studio `

![](./figures/studio1.png)

 dist 

![](./figures/studio2.png)

 finsh  Studio 

![](./figures/studio2-1.png)

 RT-Thread Settings 

![](./figures/studio3.png)

RT-Thread Settings  board/Kconfig /

![](./figures/studio4.png)

### 3.6 

* MDK5  Env 

* RT-Thread Studio Env / scons 

 scons 

![](./figures/studio5.png)

#### 3.6.1  rtconfig.h 

**MDK5**

 Env  menuconfig  rtconfig.h 

![](./figures/menuconfig_1.png)

![](./figures/menuconfig_2.png)

---

**RT-Thread Studio**

/ scons 

#### 3.6.2  MDK 

 MDK  BSP 

 env  `scons --target=mdk5` 

![](./figures/menuconfig_3.png)

 BSP 

 `scons --target=mdk4`  `scons --target=iar` MDK4  IAR  BSP  GitHub  BSP MDK4

---

**RT-Thread Studio** / scons 

RT-Thread 

### 3.7 RT-Thread Studio 

1 Studio 

![](./figures/studio_cfg1.png)

2

![](./figures/studio_cfg2.png)

3Debugger OpenOCD 

![](./figures/studio_cfg3.png)

## 4. 

 RT-Thread PSOC6  BSP   BSP  BSP  BSP  

### 4.1 BSP 

PSOC6 BSP  3 ENV  IDE  PSOC6  BSP  BSP BSP  BSP 

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
- FinSH  MSH FINSH_USING_MSH_ONLY

### 4.2 BSP 

-  BSP  README.md README.md  BSP  BSP 
-  BSP  2 
  -  BSP  GPIO  FinSH  MDK5 IAR  GCC MDK4 BSP  README.md 
  -  menuconfig  review 
-  BSP  BSP
-  PSOC6  Library  PSOC62  HAL 
-  BSP 
-  BSP  BSP 
