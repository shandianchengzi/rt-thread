# i.MX RT  BSP 

 BSP RT-Thread  i.MX RT  BSP BSP  BSP  BSP 

 RT-Thread  i.MX RT  BSP  BSP  Env  BSP  BSP 


 BSP  MCUXpresso Config Tools MCUXpresso  BSP 

 BSP 

-  BSP  BSP 
- BSP 
-  MCUXpresso 

## 1. BSP 

BSP 

![BSP ](./figures/frame.png)

i.MX RT  BSP  SDK BSP 1050  BSP 

|  |  |  |
| - | - | :-- |
|  SDK | imxrt/libraries/MIMXRT1050 | 1050  SDK |
| drivers | imxrt/libraries/drivers | i.MX RT  RTT  |
|  BSP | imxrt/imxrt1052-nxp-evk | NXP  imxrt1050 EVK  BSP |

## 2. 

 BSP  BSP RT-Thread 

-   i.MX RT  BSP 

   BSP  [BSP ](../README.md) 

-  scons 

  RT-Thread  scons  scons  BSP 

- 

   RT-Thread  BSP 

-  kconfig 

  RT-Thread  menuconfig  menuconfig  kconfig  RT-Thread  kconfig 

-  MCUXpresso 

   i.MX RT  BSP  MCUXpresso  MCUXpresso 

## 3. BSP 

 `imxrt1052-fire-pro`  BSP  BSP

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
| libraries/templates/imxrt1050xxx | 1050  BSP  |

 1050  BSP 

![F1  BSP ](figures/bsp_template_dir.png)

 BSP  1050  `imxrt1050xxx`  `imxrt1052-fire-pro`  +  + 

![](./figures/copy.png)

 BSP  board  1050  BSP  `imxrt1052-fire-pro`  BSP  board 

|  |  |
|-------------|-------------------------------------------------------|
| MCUX_Config | MCUX_Config  |
| linker_scripts |  |
| Kconfig |  |
| SConscript |  |

### 3.2  MCUXpresso 

 MCUXpresso [ NXP ](https://www.nxp.com/cn/support/developer-resources/software-development-tools/mcuxpresso-software-and-tools:MCUXPRESSO ) MCUXpresso 

 BSP  MCUXpresso  MCUXpresso  MCUX_Config  `MCUX_Config.mex` 

![open_cubemx](figures/open_mcuxpress.png)

 MCUXpresso  RT-Thread  RT-Thread 

1. BSP 

![](./figures/mcuxpress_1.png)

2.  MCU  clock gate 

![](./figures/mcuxpress_clock1.png)

3.  BSP  MCUX_Config  `pin_mux.c`  `pin_mux.h` `clock_config.c`  `clock_config.h` 

![](./figures/mcupress_clock2.png)

 MCUXpresso 

![CubeMX  7](./figures/mcupress_3.png)

### 3.3  Kconfig 

 `board/Kconfig` 

- 
- BSP 



|              |      |                |
| ------------------ | -------- | ------------------ |
| SOC_MIMXRT1052CVL5B    | BSP  | SOC_MIMXRT10xxx       |
| SOC_IMXRT1050_SERIES    | BSP  | SOC_IMXRT10xx_SERIES,i.MX RT 10151020105010601064       |

 BSP  BSP  GPIO 

![ Kconfig](./figures/Kconfig.png)

![ Kconfig](./figures/board_kconfig2.png)

### 3.4 



#### 3.4.1 

**linker_scripts** 

![](./figures/linker_scripts.png)

 MDK  link.sct 

![linkscripts_change](figures/link-scf.png)

 BSP  MIMIRT1052CVL5B QSPI FLASH  32MB m_text_size  0x1fffdbffm_text_sizem_interrupts_size  m_flash_config_size  32MB

 IAR  link.icf  GCC  link.lds

- link.icf 

  ![link_icf](figures/link-icf.png)

- link.lds 

  ![link_lds](figures/link-lds.png)

####  3.4.2 

 SDK  `fsl_device_registers.h` 

![](./figures/SConscript.png)

#### 3.4.3 

**template**  MDK/IAR MDK4/MDK5/IAR 

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

 `scons --target=mdk4`  `scons --target=iar` mdk4  IAR  BSP  GitHub  BSP

RT-Thread 

## 4. 

 RT-Thread i.MX RT  BSP   BSP  BSP  BSP  

### 1. BSP 

i.MX RT BSP  3 ENV  IDE  i.MX RT  BSP  BSP BSP  BSP 

 BSP 

#### 

-  RT-Thread 
- main 
  -  LED main  LED 1HZ 
-  `rt_hw_board_init`  `rt_system_heap_init`
-  GPIO  FinSH  DMA
- 
-  GCC/MDK/IAR 

#### ENV 

-  1000RT_TICK_PER_SECOND
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

-  BSP  README.md README.md  BSP  BSP  [i.MX RT ](./IMXRT.md) 
-  BSP  2 
  -  BSP  GPIO  FinSH  MDK4MDK5 IAR  GCC  MDK4 BSP  README.md 
  -  menuconfig  review 
-  BSP  BSP
-  i.MX RT  Library  1050  FSL 
-  BSP 
-  BSP  BSP 