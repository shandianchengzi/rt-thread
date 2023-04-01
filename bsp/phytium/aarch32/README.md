
# AARCH32 

-  Phytium 


## 1. 

- Windows Env 

```shell
    menuconfig
```

- Linux 

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
Hardware Drivers > On-chip Peripheral Drivers
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
rtthread_a32.bin
rtthread_a32.elf
rtthread_a32.map
```

## 5. 


- RT-ThreadPhytium BSP
```
python ./export_project.py -n=phytium-a32 -o=D:/proj/rt-thread-e2000/phytium-a32
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