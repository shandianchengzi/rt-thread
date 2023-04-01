<!--
 * Copyright : (C) 2022 Phytium Information Technology, Inc. 
 * All Rights Reserved.
 *  
 * This program is OPEN SOURCE software: you can redistribute it and/or modify it  
 * under the terms of the Phytium Public License as published by the Phytium Technology Co.,Ltd,  
 * either version 1.0 of the License, or (at your option) any later version. 
 *  
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY;  
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the Phytium Public License for more details. 
 *  
 * 
 * FilePath: README.md
 * Date: 2022-10-17 15:16:12
 * LastEditTime: 2022-10-17 15:16:12
 * Description:  This file is for 
 * 
 * Modify History: 
 *  Ver   Who  Date   Changes
 * ----- ------  -------- --------------------------------------
-->

# AARCH64 

-  Phytium 

## 1. 

```shell
    scons --menuconfig
```



```
Standalone Setting > Board Configuration > Chip 
```

![](./figures/chip_select.png)
![](./figures/phytium_cpu_select.png)

## 2. 


```shell
    scons --menuconfig
```



```
Hardware Drivers Config > On-chip Peripheral Drivers
```

![](./figures/select_driver.png)


## 3. SDK


```shell
    scons --menuconfig
```



![](./figures/select_debug_info.png)



## 4. 

```shell
    scons -c
    scons
```

- 

```
rtthread_a64.bin
rtthread_a64.elf
rtthread_a64.map
```

## 5. 


- RT-ThreadPhytium BSP
```
python ./export_project.py -n=phytium-a64 -o=D:/proj/rt-thread-e2000/phytium-a64
```

![](./figures/export_project.png)


-  Kconfig  BSP_DIR  STANDALONE_DIR 
> env  menuconfig  SConstruct 

```
config BSP_DIR
    string
    option env="BSP_ROOT"
    default "."

config STANDALONE_DIR
    string
    option env="STANDALONE_DIR"
    default "libraries/standalone"
```

-  menuconfig  scons 


## 6.  RT-Studio

-  RT-Studio `RT-Thread Bsp ` 5.  BSP 
-  BSP 

![](./figures/import_project.png)