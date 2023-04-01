# RA 

## 1. 

 RA  BSP  BSP 

## 2. 

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/rtthread-development-guide/rtthread-tool-manual/env/env-user-manual/)
-  [Kconfig](https://www.rt-thread.org/document/site/#/development-tools/kconfig/kconfig) 
-  [FSP](https://www2.renesas.cn/jp/zh/software-tool/flexible-software-package-fsp) 
-  RT-Thread [](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/programming-manual/device/device) 

## 3. 

 BSP  ``  ra6m4-cpk  UART9 

 UART 

### 3.1  Kconfig 

 BSP  board\kconfig  UART9 

![image-20220221161853343](figures/add_uart.png) 

![image-20220221163152761](figures/add_uart1.png) 

 BSP  ENV  `menuconfig`  UART9 

![image-20220221164229974](figures/add_uart2.png) 

### 3.2  uart_config.h 

Kconfig 

 `libraries\HAL_Drivers\config\ra6m4\uart_config.h`  UART9 

![image-20220221170945734](figures/add_uart3.png) 

### 3.3  drv_usart_v2.h 

 `libraries\HAL_Drivers\drv_usart_v2.c`

![image-20220221171806580](figures/add_uart4.png) 

![image-20220221172034531](figures/add_uart5.png) 

### 3.4 

1.  menuconfig  UART9  `scons --target=mdk5`  MDK 
2.  project  FSP  UART9 

![image-20220221180942314](figures/add_uart6.png) 

![image-20220221183752087](figures/add_uart8.png) 

3.  UART9  IO 

![image-20220221183405828](figures/add_uart7.png) 

4. debug  list_device  uart9  UART9 

![image-20220221185534932](figures/add_uart9.png) 
