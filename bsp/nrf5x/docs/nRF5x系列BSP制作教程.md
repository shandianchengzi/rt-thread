# Nordic  BSP 

 BSP  Nordic  BSP BSP  BSP  BSP 

stm32STM32[STM32](https://github.com/RT-Thread/rt-thread/blob/master/bsp/stm32/docs/STM32%E7%B3%BB%E5%88%97BSP%E5%88%B6%E4%BD%9C%E6%95%99%E7%A8%8B.md)

## 1. 

 BSP  BSP RT-Thread 

-   Nordic BSP 

   BSP  [Nordic ](../README.md) 

-  scons 

  RT-Thread  scons  scons  BSP 

- 

   RT-Thread  BSP 

-  kconfig 

  RT-Thread  menuconfig  menuconfig  kconfig  RT-Thread  kconfig 


##  BSP 

microbit BSP BSP

### 
 BSP  BSP  BSP  BSP BSP 

|  |  |
| ------- | ---- |
| libraries/templates/nrfx | nrfx BSP  |

### 

board/KconfigSOC_NRF52840 

SOC_NRF52840 SOC_NRF51822 [nrfx](https://github.com/xckhmf/nrfx)SConscriptpr

```
elif GetDepend('SOC_NRF51822') == True:
	define += ['NRF51822_XXAA']
	src += ['./mdk/system_nrf51.c']
	
	if rtconfig.PLATFORM in ['armcc']:
		src += ['./mdk/arm_startup_nrf51.s']
		
	if rtconfig.PLATFORM in ['gcc']:
		src += ['./mdk/gcc_startup_nrf51.S']
		
	if rtconfig.PLATFORM in ['iccarm']:
		D_SRC += ['./mdk/iar_startup_nrf51.s']
```

### templete.uvprojx

template.uvprojxsocjlinkSDK samplekeil

jlinkflash download

### rtconfig.py

rtconfig.pyCPUnrf52`cortex-m4` nrf51`cortex-m0`

### menuconfig

menuconfigRAM sizelink.sctsample

![image-20210403182242202](images/image-20210403182242202.png)

UART0 UART0 TX RX

![image-20210403182031505](images/image-20210403182031505.png)

`scons --target=mdk5`

### readme.md

readme.md, readme.md



## FAQ:

1. keil `No section matches selector - no section to be FIRST`

packagenrfxSconscriptarm_startup_nrf51.s