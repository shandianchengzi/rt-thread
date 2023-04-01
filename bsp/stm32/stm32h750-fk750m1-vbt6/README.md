# FANKE FK750M1-VBT6  BSP 

## 

 FANKE FK750M1-VBT6  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

FK750M1-VBT6  FANKE  ARM Cortex-M7 480Mhz128KB ROM1MB RAM 8MB QSPI Flash

*  W25Q64 8M 
* 1 1 
* 1  BOOT 
* 1  LED
* 1  Type C 
* 1  TF 
* 1 SPI 
*  73  IO 



![board](figures/board.jpg)

## 

 BSP 

| **** | **** | **** |
| :----------------- | :----------------: | :------------: |
| TF Card            |              |                |
| QSPI Flash         |              |    W25Q64JV    |
| OV2640 Camera      |                |                |
| OV5640 Camera      |              |                |
| 0.96' LCD          |              |     160*80     |
| 1.14' LCD          |              |    240*135    |
| 1.30' LCD          |                |    240*240    |
| 1.54' LCD          |              |    240*240    |
| 1.69' LCD          |              |    240*280    |
| 2.00' LCD          |              |    240*320    |
| **** | **** | **** |
| GPIO               |                |                |
| UART               |                |     USART1     |
| SPI                |                |                |
| RTC                |                |                |
| USB Device         |              |                |

## 



- 

   RT-Thread  RT-Thread  
- 

   RT-Thread  ENV  BSP 

### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC usb  PA9 ( USART1_TX )  PA10 ( USART1_RX )

#### 

 project.uvprojx  MDK5 

#### 

LED

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Mar 22 2023 00:10:44
 2006 - 2022 Copyright by RT-Thread team
msh />
```

### 

 BSP  GPIO  1  ENV BSP 

1.  bsp  env 
2.  `menuconfig` 
3.  `pkgs --update` 
4.  `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  V1.1  V1.0 
-  LCD  110k  128k 

  1. H750  2M ram 128k  ST 
     1.  keil  H743  2MB Flash 
     2. bsp\stm32\stm32h750-weact-ministm32h7xx  h750  keil  ram 
  2.  bootloader  qspi flash 
- 1 

  PA9     ------> USART1_TX

  PA10     ------> USART1_RX

## 

:

- [NU-LL](https://github.com/NU-LL)
