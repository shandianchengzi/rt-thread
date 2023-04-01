#  Seeed i.MX RT1052 Arch Mix  BSP 

## 

![Arch_Mix](figures/Arch_Mix.jpg)

Arch Mix  [Seeed Studio](https://www.seeedstudio.com/)  i.MX RT 1050  RGB  32M SDRAM 600MHZ LCD Seeed Studio 

### 

|  |  |
| ---- | ---- |
|  | i.MX RT 1052 |
|  | ARM Cortex-M7 |
|  | 600MHz |
|  | 512KB  SRAM |
|  | 32M SDRAM8M QSPI FLASH |

## 

Arch Mix MDK5IARGCC

| IDE/ |  |
| ---------- | --------- |
| MDK5 | MDK525 |
| IAR | IAR 8.11.3.13984 |
| GCC | GCC 5.4.1 20160919 (release) |

## BSP

### 

-  bsp  env 
- `menuconfig`
- `scons --target=mdk5 -s``scons --target=iar`

### 

 SWD 

>  board MIMXRT105x_QuadSPI_4KB_SEC.FLM  Keil5 `ARM\Flash` 
>
>  `Reset ` `Boot Mode ` `Reset ` `Boot Mode ```

### 

 LED  DS1 

 TTL  RXD/TXD (115200-N-8-1) & RT-Thread:

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build May  7 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```

## 

|  |   |  |
| ------ | ----  | ------ |
| UART |  | UART 1 |
| GPIO |  | GPIO1~GPIO5 |
| IIC |  |  |
| SPI |  |                                        |
| LCD |  |  |
| RTC |  |  |
| SDIO |  |  |
| SDRAM |  | 32M SDRAM 2M  Non Cache  |

## 



- [guozhanxin](https://github.com/Guozhanxin)
