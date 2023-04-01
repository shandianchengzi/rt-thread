# AXU4EV-E  BSP 

## 

 AXU4EV-E  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

AXU4EV-E    XILINX Zynq UltraScale+ MPSoCs  MPSoCs  XILINX Zynq UltraScale+ EV  ZU4EV Processing System(PS)+Programmable Logic(PL)ARM Cortex-A53 FPGA  PS  4  4GB  DDR4 SDRAM 1  8GB eMMC  1  256Mb  QSPI FLASH  PL  1  1GB DDR4 SDRAM  

[](http://www.alinx.cn/)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| R5-CPU0   |          | R5CPU0 |
| ****      | **** | ****                              |
|  |          |  |
| ****      | **** | ****                              |
| GPIO              |          |  |
| UART              |          | UART0                            |
| TIMER     |          |     TTC0         |
| EMMC |  | SD0 |
| EMAC |  | e0 |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  GCC 

#### 

1.  bsp  env `scons`

2.  bsp  `rtthread-zynqmp-r5.elf` 

3.  Xilinx Vitis  FSBL Debug ConfigurationApplication `rtthread-zynqmp-r5.elf` 

4.  PC  JTAG 

    rtconfig.py  BUILD Xilinx Vitis 

#### 

1.  bsp  env `scons`

2.  bsp  `rtthread-zynqmp-r5.elf` 

3.  Xilinx Vitis  Xilinx SDK  FSBL Xilinx  bootgen  BOOT.bin 

   

   ```
    bootgen -image ./output.bif -arch zynqmp -o ./BOOT.bin -w on
   ```
   
    output.bif 
   ```
   //arch = zynqmp; split = false; format = BIN
   the_ROM_image:
   {
        [bootloader, destination_cpu = r5-0]./fsbl.elf
        [destination_cpu = r5-0, exception_level = el-3]./rtthread-zynqmp-r5.elf
   }
   ```
   
4.  ALINX  BOOT.bin SD QSPI FLASH 


#### 



 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Nov 27 2020
 2006 - 2020 Copyright by rt-thread team
msh />
```

### 

 BSP  EMMC  DFS 

 BSP lwip

1. `RT_LWIP_PBUF_NUM`256
2. `RT_LWIP_MEM_ALIGNMENT`32RTTlwip 2.0.2`lwipopts.h``MEM_ALIGNMENT`


## 

BSP XILINX Zynq UltraScale+ MPSoCs 

1.   DDR memory  2G`zynqmp-r5.ld``psu_r5_ddr_0_MEM_0` `board.h``HEAP_END`
2.  `xparameters.h``XPAR_CPU_CORTEXR5_0_CPU_CLK_FREQ_HZ`
3. `drv_uart.c``rxmio`, `txmio` `xparameters.h``XPAR_PSU_UART_0_UART_CLK_FREQ_HZ`
4. `xparameters.h``XPAR_PSU_TTC_0_TTC_CLK_FREQ_HZ` 
5. SD`drv_sdcard.c`
6. PHY`xemacpsif_physpeed.c`ALINX

`xparameters.h`Xilinx Vitis`xparameters.h`



## 

- 

## 

:

-  [](https://github.com/Wang-Huachen/)
