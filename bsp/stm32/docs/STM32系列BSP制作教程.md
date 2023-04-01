# STM32  BSP 

 BSP RT-Thread  STM32  BSP BSP  BSP  BSP 

 RT-Thread  BSP  BSP  BSP  Library  BSP  BSP  BSP 

 BSP  CubeMX  BSP CubeMX  BSP 

 BSP 

-  BSP  BSP 
-  BSP 
-  CubeMX  BSP 

## 1. BSP  

BSP 

![BSP ](./figures/frame.png)

 STM32  BSP BSP  BSP F1  BSP 

||||
| - | - | :-- |
|  | stm32/libraries |  HAL  HAL  |
| F1  BSP  | stm32/libraries/templates/stm32f10x | F1 BSP  F1 BSP |
|  BSP | stm32/stm32f103-atk-nano |  BSP  |

## 2. 

 BSP  BSP RT-Thread 

-   STM32  BSP 

   BSP  [BSP ](../README.md) 

-  Scons 

  RT-Thread  Scons  Scons  BSP 

- 

   RT-Thread  BSP 

-  Kconfig 

  RT-Thread  menuconfig  menuconfig  Kconfig  RT-Thread  kconfig 

-  CubeMX 

   STM32  BSP  CubeMX  CubeMX 

## 3. BSP 

 `stm32f103-atk-nano`  BSP  BSP

BSP 

1. 
2.  CubeMX 
3.  BSP  Kconfig 
4. 
5. 

 BSP

### 3.1 
 BSP  BSP  BSP  BSP BSP 

|  |  |
| ------- | ---- |
| libraries/templates/stm32f0xx | F0  BSP  |
| libraries/templates/stm32f10x | F1  BSP  |
| libraries/templates/stm32f4xx | F4  BSP  |
| libraries/templates/stm32f7xx | F7  BSP  |
| libraries/templates/stm32l4xx | L4  BSP  |

 F1  BSP 

![F1  BSP ](figures/bsp_template_dir.png)

 BSP  F1  `stm32f10x`  `stm32f103-atk-nano` 

![](./figures/copy.png)

 BSP  board  F1  BSP  `stm32f103-atk-nano`  BSP  board 

|  |  |
|-------------|-------------------------------------------------------|
| CubeMX_Config | CubeMX  |
| linker_scripts | BSP  |
|board.c/h | GPIO  |
| Kconfig |  |
| SConscript |  |

### 3.2  CubeMX 

 BSP  CubeMX  CubeMX  **CubeMX_Config**  `CubeMX_Config.ioc` 

![open_cubemx](figures/open_cubemx.png)

 CubeMX  STM32F103RBTx 

#### 3.2.1  CubeMX 



1. 

![](./figures/CubeMX_1.png)

2. 

![](./figures/CubeMX_2.png)

3.  CubeMX 

![](./figures/CubeMX_4.png)

 .c/.h  rt-thread  stm32xxx_hal_msp.c 

![generate-code](figures/generate-code.png)

 CubeMX 

![CubeMX 7](./figures/CubeMX_5.png)

#### 3.2.2 

 **board.c**  `SystemClock_Config()`  CubeMX 

 CubeMX `board/CubeMX_Config/Src/main.c`  main.c  board.c  BSP 

![board_1](./figures/board_1.png)

 **board.h**  FLASH  RAM  `STM32_FLASH_SIZE`  `STM32_SRAM_SIZE`  BSP  STM32F103RBTx  flash  128kram  20k

![ board.h](./figures/board_h.png)

#### 3.2.3 

 RAM  **HEAP_BEGIN**  **HEAP_END** **HEAP_BEGIN**  **HEAP_END**  [3.4.1 ](# 3.4.1 ) 

 RAM  L4  `0x20000000`  96k  `0x10000000`  32k 

![heap_config](figures/heap_config.png)

### 3.3  Kconfig 

 `board/Kconfig` 

- 
- BSP 



|              |      |                |
| ------------------ | -------- | ------------------ |
| SOC_STM32F103RB    |  | SOC_STM32xxx       |
| SOC_SERIES_STM32F1 |  | SOC_SERIES_STM32xx |

 BSP  BSP  GPIO 

![ Kconfig](./figures/Kconfig.png)

### 3.4 


#### 3.4.1 
**linker_scripts** 

![](./figures/linker_scripts.png)

 MDK  link.sct 

![linkscripts_change](figures/linkscripts_change.png)

 BSP  STM32F103RBFLASH  128k LR_IROM1  ER_IROM1  0x00020000RAM 20k  RW_IRAM1  0x00005000 [**3.2.3 **](# 3.2.3 )  BSP 

 iar  link.icf  gcc  link.lds

- link.icf 

  ![link_icf](figures/link_icf.png)

- link.lds 

  ![link_lds](figures/link_lds.png)


####  3.4.2 

**SConscript**  MDK/IAR 



![](./figures/SConscript.png)

 .s  CubeMX 

#### 3.4.3 

**template**  MDK/IAR MDK4/MDK5/IAR 

![MDK/IAR ](./figures/template_1.png)

 MDK5 

![](./figures/template_2.png)



![](./figures/template_3.png)

### 3.5 

 Env 

#### 3.5.1  rtconfig.h 

 Env  menuconfig  rtconfig.h 

![menuconfig](./figures/menuconfig_1.png)

![](./figures/menuconfig_2.png)

#### 3.5.2  MDK/IAR 
 MDK  BSP 

 env  `scons --target=mdk5` 

![ BSP ](./figures/menuconfig_3.png)



![ BSP ](./figures/menuconfig_4.png)

 BSP 

 `scons --target=mdk4`  `scons --target=iar` MDK4  IAR  BSP  GitHub  BSP MDK4

RT-Thread 

## 4. 

 RT-Thread STM32  BSP   BSP  BSP  BSP  

### 4.1 BSP 

STM32 BSP  3 ENV  IDE  STM32  BSP  BSP BSP  BSP 

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

#### 4.1.3 IDE 

- 
-  C99 
-  One ELF Section per FunctionMDK
- MDK/IAR build MDK/IAR 
- MDK/GCC/IAR  bin  rtthread.bin

### 4.2 BSP 

-  BSP  README.md README.md  BSP  BSP [STM32](./STM32.md)
-  BSP  2 
  -  BSP  GPIO  FinSH  MDK4MDK5 IAR  GCC MDK4 BSP  README.md 
  -  menuconfig  review 
-  BSP  BSP
-  STM32  Library  f1/f4  HAL 
-  BSP 
-  BSP  BSP 
