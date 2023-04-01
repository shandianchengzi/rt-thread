# STM32H750-artpi  BSP 

## 

  STM32H750-ART-PI  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32H750 RTTHREAD ARM Cortex-M7  480Mhz STM32H750 



![board](figures/board.jpg)

 **** 

- MCUSTM32H750 480MHz128KB FLASH, 1MB RAM
- USB USB OTGRGB888
-  ST-LINK

 [H750-ART-PI](https://www.rt-thread.org/product/153.html)

 [sdk-bsp-stm32h750-realthread-artpi](https://github.com/RT-Thread-Studio/sdk-bsp-stm32h750-realthread-artpi)

 [ART-PI](https://art-pi.gitee.io/website)

## 

 BSP 

| **** | **** | ****                  |
| :----------- | :----------: | :------------------------ |
| LED          |        |         |
| BUTTON       |        | button        |
| QSPI  FLASH  |        | 1MB w25q64  QSPIFLASH |
| SPI  FLASH   |        | 2MB w25q128 SPI FLASH     |
| SDCARD       |        | sdcard                |
| AP6212       |        | WIFI & BLUETOOTH          |
| LCD RG888    |        |                 |
| **** | **** | ****                  |
| GPIO         |          |                           |
| UART         |          | UART4 UART3               |
| SPI          |          | SPI                       |
| QSPI         |          |                           |
|              |              |                           |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC TVCC  3.3V usb  TTLRX  TTLTX

#### 

 project.uvprojx  MDK5 

>  ST_LINK  ST_LINK 

#### 

LED

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Oct 25 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 4 

    PI9  ------> USART4_RX

    PA0 ------> USART4_TX 

- Bootloader   

    bootloader ART-PiBOOT bootloader bootloader  artpi_bootloader.bin flash PC ART-Pi  artpi_bootloader.bin  ART-Pi 

     bin  ART-Pi sdk  art_pi_bootloader  [ART-Pi ](https://github.com/RT-Thread-Studio/sdk-bsp-stm32h750-realthread-artpi/blob/master/documents/UM5002-RT-Thread%20ART-Pi%20%E5%BC%80%E5%8F%91%E6%89%8B%E5%86%8C.md) bin  Debug 
    
-  flash 

     [ART-Pi ](https://github.com/RT-Thread-Studio/sdk-bsp-stm32h750-realthread-artpi/blob/master/documents/UM5005-RT-Thread%20ART-Pi%20%E5%B8%B8%E8%A7%81%E9%97%AE%E9%A2%98%E8%A7%A3%E7%AD%94.md) MDK5

## 

ART-Pi 

RT-Thread [](https://club.rt-thread.org/)

-  ART-Pi  QQ (1016035998)

## 

 ART-Pi  [ART-Pi ](https://github.com/RT-Thread-Studio/sdk-bsp-stm32h750-realthread-artpi/blob/master/documents/UM5004-RT-Thread ART-Pi .md) 