# RABSP

## 1. 

 RT-Thread  ENV  BSP 



1. 
2. 
3. 

## 2. 

-  ENV [RT-Thread env ](https://www.rt-thread.org/document/site/programming-manual/env/env/)
-  [FSP](https://www2.renesas.cn/jp/zh/software-tool/flexible-software-package-fsp) 

## 3. 

 SPISDIOADC  BSP RT-Thread  ENV  BSP  RA6M4-CPK  SPI  ENV  BSP 

### 3.1 

 BSP  menuconfig 

![image-20220218162910778](figures/menuconfig_ra6m4cpk.png) 


 ![config1](figures/config1.png) 

 `Hardware Drivers Config`

### 3.2 

 ************

![](figures/config2.png) 

### 3.3  SPI Flash 

![image-20220218163357420](figures/menuconfig_spi.png) 

![image-20220218163714429](figures/menuconfig_spi1.png) 



### 3.4 

 Save  Esc 

![](figures/save.png) 



### 3.5  MDK5 

 `scons --target=mdk5`  MDK5 

![image-20220218164532436](figures/scons_mdk5.png) 

### 3.6 FSP  SPI 

![image-20220218171841353](figures/fsp_spi.png) 

![image-20220218172446068](figures/fsp_spi1.png) 

 Pins  SPI1 ** SSLx  None**

 FSP

![image-20220218174145848](figures/fsp_spi2.png) 

### 3.7 

 MDK5  FSP   

![image-20220218174811328](figures/mdk_build.png) 

 debug 

![image-20220218175442360](figures/mdk_build1.png) 

### 3.8 

 `list_device`  spi1  SPI1 

![image-20220218175926965](figures/run_spi1.png) 

## 4. 

 SPI [RAFSP.md](RAFSP.md)

 ENV  FSP 