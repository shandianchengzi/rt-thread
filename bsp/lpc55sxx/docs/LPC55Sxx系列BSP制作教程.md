# LPC55Sxx  BSP 

 BSP RT-Thread  LPC55Sxx BSP BSP  BSP  BSP 

 RT-Thread  BSP  BSP  BSP  Libraries  BSP  BSP  BSP 

 BSP  MCUXpresso Config Tools MCUXpresso  BSP 

 BSP 

-  BSP  BSP 
- BSP 
-  MCUXpresso 

## 1. BSP 

BSP 

![BSP ](./figures/frame.png)

LPC55Sxx  BSP  SDK BSP LPC55S6x  BSP 

|  |  |  |
| - | - | :-- |
|  SDK | lpc55sxx/libraries/LPC55S69 | LPC55S69 SDK |
| drivers | lpc55sxx/libraries/drivers | LPC55Sxx  RTT  |
|  BSP | lpc55sxx/lpc55s69_evk | NXP  LPCXpressp55S69 EVK  BSP |

## 2. 

 BSP  BSP RT-Thread 

-   LPC55Sxx BSP 

   BSP  [BSP ](../README.md) 

-  scons 

  RT-Thread  scons  scons  BSP 

- 

   RT-Thread  BSP 

-  kconfig 

  RT-Thread  menuconfig  menuconfig  kconfig  RT-Thread  kconfig 

-  MCUXpresso 

   lpc  BSP  MCUXpresso  MCUXpresso 

## 3. BSP 

 `LPCXpresso55S69-EVK`  BSP  BSP

BSP 

1. 
2.  MCUXpresso 
3.  BSP  Kconfig 
4. 
5. 

 BSP

### 3.1 

 BSP  BSP  BSP  BSP BSP 

|  |  |
| ------- | ---- |
| libraries/templates/lpc55s6xxxx | LPC55S6x BSP  |

 LPC55S6x  BSP 

![LPC  BSP ](figures/bsp_template_dir.png)

 BSP  LPC55S6x  `lpc55s6xxxx`  `lpc55s69-nxp-evk`  +  + 

![](./figures/copy.png)

 BSP  board  LPC55S6x  BSP `lpc55s69-nxp-evk`  BSP  board 

|  |  |
|-------------|-------------------------------------------------------|
| MCUX_Config | MCUX_Config  |
| linker_scripts |  |
| Kconfig |  |
| SConscript |  |

### 3.2  MCUXpresso 

 MCUXpresso [ NXP ](https://www.nxp.com/cn/support/developer-resources/software-development-tools/mcuxpresso-software-and-tools:MCUXPRESSO ) MCUXpresso 

 BSP  MCUXpresso  MCUXpresso  MCUX_Config  `MCUX_Config.mex` 

![mcuxpresso config tool](figures/open_mcuxpresso.png)

 MCUXpresso  RT-Thread  RT-Thread 

1. BSP 

![](./figures/mcuxpresso_1.png)

2.  MCU  clock gate 

![](./figures/mcuxpresso_clock1.png)

3.  BSP  MCUX_Config  `pin_mux.c`  `pin_mux.h` `clock_config.c`  `clock_config.h` 

![](./figures/mcupresso_clock2.png)

 MCUXpresso 

pin_mux.c/pin_mux.h/clock_config.c/clock_config.hBSPboardKconfigpin_mux/clock_config

![MCUXpresso COnfig Tool  7](./figures/mcupresso_3.png)

### 3.3  Kconfig 

 `board/Kconfig` 

- 
- BSP 



|              |      |                |
| ------------------ | -------- | ------------------ |
| SOC_LPC55S6X | BSP  | SOC_LPC55S6x |
| SOC_LPC55S6X_SERIES | BSP  | SOC_LPC55S6X_SERIES,LPC55S6xLPC55S66LPC55S69 |

 BSP  BSP  GPIO 

![ Kconfig](./figures/Kconfig.png)

![ Kconfig](./figures/board_kconfig2.png)

### 3.4 



#### 3.4.1 

**linker_scripts** 

![](./figures/linker_scripts.png)

 MDK  link.sct 

![linkscripts_change](figures/link-scf.png)

 BSP LPC55S69JBD100FLASH  608kBCore0Flash456KB m_text_size  0x71E00m_text_sizem_interrupts_size  m_core1_image_size  608kB

 IAR  link.icf  GCC  link.lds

- link.icf 

  ![link_icf](figures/link-icf.png)

- link.lds 

  ![link_lds](figures/link-lds.png)

####  3.4.2 

 SDK  `fsl_device_registers.h` 

![](./figures/SConscript.png)

#### 3.4.3 

**template**  MDK/IAR MDK5/IAR 

![MDK/IAR ](./figures/template_1.png)

 MDK5 

![](./figures/template_2.png)



![](./figures/template_3.png)

![](./figures/template_4.png)

### 3.5 

 Env 

#### 3.5.1  rtconfig.h 

 Env  menuconfig  rtconfig.h 

![ menuconfig ](./figures/menuconfig_1.png)

![](./figures/menuconfig_2.png)

#### 3.5.2  MDK/IAR 

 MDK  BSP 

 env  `scons --target=mdk5` 

![ BSP ](./figures/menuconfig_3.png)



![ BSP ](./figures/menuconfig_4.png)

 BSP 

 `scons --target=mdk5`  `scons --target=iar` mdk5  IAR  BSP  GitHub  BSP

RT-Thread 

## 4. 

 RT-Thread LPC  BSP   BSP  BSP  BSP  

### 1. BSP 

LPC BSP  3 ENV  IDE  LPC  BSP  BSP BSP  BSP 

 BSP 

#### 

-  RT-Thread 
- main 
  -  LED main  **  **  LED 1HZ 
-  `rt_hw_board_init`  `rt_system_heap_init`
-  GPIO  FinSH  DMA
- 
-  GCC/MDK/IAR 

#### ENV 

-  100RT_TICK_PER_SECOND
- BSP RT_DEBUG
-  256IDLE_THREAD_STACK_SIZE
- RT_USING_COMPONENTS_INIT
-  user main RT_USING_USER_MAIN
-  libcRT_USING_LIBC
- FinSH  MSH FINSH_USING_MSH_ONLY

#### IDE 

- 
-  C99 
-  One ELF Setion per FunctionMDK
- keil/iar  build  keil/iar 
- MDK/GCC/IAR  bin  rtthread.bin

### 2. BSP 

-  BSP  README.md README.md  BSP  BSP  [LPC55Sxx ](./LPC55Sxx . md) 
-  BSP  2 
  -  BSP  GPIO  FinSH  MDK5 IAR  GCC  MDK4 BSP  README.md 
  -  menuconfig  review 
-  BSP  BSP
-  LPC  Library  LPC55S6xSDK
-  BSP 
-  BSP  BSP 