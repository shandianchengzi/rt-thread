# JuiceVm  BSP 

 Risc-V 64bit imaJuiceVm

---

## 

 JuiceVm  JuiceVm  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

JuiceVm  juice  Risc-V 64bit ima Risc-V 64bit 

![](static/juicevm_rtt.jpg)

****

- MCURisc-V 64bit ima300MB RAMM-MODE,S-MODE,
- 
  - UART0
- UART
- :  GDB TODO

Juice[JuiceVm ](https://whycan.com/t_5844.html)

## 

 BSP 

|****     |****|****                             |
| :----------------- | :----------: | :-----------------------------------|
| GPIO              |      |                               |
| MMU(SV39)         |      |                               |
| UART              |          | UART0                                |
| SDIO              |      |                               |
| RTC               |      |                               |
| PWM               |      |                               |
| USB Device        |      |                               |
| USB Host          |      |                               |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 

### 

 BSP  GCC  GCC 

#### 
##### toolchain 
-  xpack-dev-tools  [](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/tag/v8.3.0-2.1)
  ```
  wget https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases/download/v8.3.0-2.1/xpack-riscv-none-embed-gcc-8.3.0-2.1-linux-x64.tar.gz 
  ```
- /opt 
  ```
  tar vxf xpack-riscv-none-embed-gcc-8.3.0-2.1-linux-x64.tar.gz -C /opt
  ```
- rt-thread/bsp/juicevm
 ```
 scons
 ```
-  JuiceVm

https://whycan.com/files/members/1390/juice_vm_release_for_Linux_57ba985a.zip

- 
  ./juice_vm_for_Linux.out -a -g ./rtthread.bin

#### 

console RT-Thread :

```c
global_vm_log_init output_mode_sel: 0  JUICE_VM_LOG_MAX_NUM:600
      gg ,ggg,         gg      ,a8a,     ,gggg,   ,ggggggg, ,ggg,         ,g,ggg, ,ggg,_,ggg,  
     dP8dP  Y8a        88     ,8   8,  ,88   Y8b,dP      Y8dP  Y8a       ,8dP  Y8dP  Y88P  Y8b 
    dP YYb, `88        88     d8   8b d8      `Yd8'    a  YYb, `88       d8Yb, `88'  `88'  `88 
   ,8  `8`   88        88     88   88d8'   8b  d88      Y8P'`   88       88 `   88    88    88 
   I8   Yb   88        88     88   8,8I     Y88P`8baaaa         88       88     88    88    88 
   `8b, `8,  88        88     Y8   8I8'        ,d8P             I8       8I     88    88    88 
    ` Y88888 88        88     `8, ,8d8         d8               `8,     ,8'     88    88    88 
         Y8  88        888888   8,8 Y8,        Y8,               Y8,   ,8P      88    88    88 
         ,88,Y8b,____,d88`8b,  ,d8b,`Yba,,_____`Yba,,_____,       Yb,_,dP       88    88    Y8,
     ,ad88888  Y888888P Y8  Y88P   Y8 ` Y8888888 ` Y8888888         Y8P         88    88    `Y8
   ,dP '   Yb                                                                                  
  ,8'      I8                                                                                  
 ,8'       I8                                                                                  
 I8,      ,8'                                                                                  
 `Y8,___,d8'                                                                                   
    Y888P                                                                                      
 email:                                                                       juicemail@163.com
version:57ba985a 57ba985a Fri, 23 Apr 2021 17:22:20 +0800 xiaoxiaohuixxh feat(Rt-thread): uart port pass
firm_addr:./rtthread.bin
fd = 3
file_size = 44872
interrupt_vertor_register_mag_init
rv_csr_register_init
csr_addr_misa 8000000000040101
csr_addr_mvendorid 0000000000000000
csr_addr_marchid 0000000000000000
csr_addr_mimpid 0000000000000000
csr_addr_mhartid 0000000000000000
rv_peripheral_device_init
[rv64_sim][dev][mmu]rv.c(5593):rv_peripheral_device_mmu_init,Sv39 mode support only
[rv64_sim][dev][mtime]rv.c(5252):rv_peripheral_device_mtime_init
[rv64_sim][dev][mtime]rv.c(5271):pdev_mtime_irq_info 0x7f334d2d0910 92c00003 92c00007
[rv64_sim][dev][mtime]rv.c(5277):pdev_mtime_irq_info_smode 0x7f334d2d0900 92c00003 92c00007
[rv64_sim][dev][uart0]rv.c(5061):rv_peripheral_device_uart0_init
[rv64_sim][dev][uart0]rv.c(5077):pdev_uart0_irq_info 0x7f334d2d08f0
rv sim start...loading
cpu run...
heap: [0x8000cb60 - 0x92c00000]

 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Apr 26 2021
 2006 - 2021 Copyright by rt-thread team
Hello RT-Thread!
msh >
```

### 

 BSP  UART0 

```
./juice_vm_for_Linux.out
```

## 

rv64ima,Risc-Vc

## 

- [Juice](https://github.com/xiaoxiaohuixxh)
- [](juicemail@163.com)

## 

* [RT-Thread ](https://www.rt-thread.org/document/site/)

* [JuiceVm ](https://whycan.com/t_5844.html)

