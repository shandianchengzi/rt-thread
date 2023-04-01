# GD32470-LCKFBBSP

## 

GD32470Z-LCKFBGD32F470240MGD32F470ZGT6

![board](figures/board.png)

> 20221205GD32F450ZGT6GD32F470ZGT6 GD32F450ZGT6200SDRAM 256KGD32F470ZGT6240SDRAM 512K

 **** 

- GD32F470ZGT6 240MHzCPUARM Cortex-M41024KB FLASH 512KB RAM 
- 
  
  - LED 4LED1 (PE3LED2PD7LED3PG3LED4PA5
  - LED
  - 3KEY_UPPA0RESET(NRST)BOOT0PB2
  - General TM * 10Advanced TM * 2Basic TM * 2
  - SysTick * 1
  -  * 2
  - RTC * 1
  - USART * 4UART * 4
  - I2C * 3I2S * 2
  - SPI * 6
  - SDIO * 1
  - CAN * 2
  - USBFS+HS
  -  * 1
  - TFT-LCD
  - EXMC/SDRAM * 1
  - ADC * 3
  - DAC * 2
  - 114GPIOs
- CMSIS-DAP
- RGBMCU
- SDIO-TF
- SPI FlashW25Q64
- SDRAMW9825G6KH-6I
- Type-C USB
- SWDUART
- 2*20PIN 2.5468IO
- [](https://lckfb.com/)

## 

 BSP 

| **** | **** | ****                           |
|:-------- |:--------:|:-------------------------------- |
| GPIO     |        | PA0, PA1... ---> PIN: 0, 1...113 |
| UART     |        | UART0 - UART7                    |
| **** | **** | ****                           |
|        |      |                              |

## 



- 
  
   RT-Thread  RT-Thread  

- 
  
   RT-Thread  ENV  BSP 

### 

 BSP  MDK5 GCC RT-Thread Studio MDK5 

#### 

 PCUSB2TTLUSART0

#### 

 project.uvprojx  MDK5 

>  CMSIS-DAP  CMSIS-DAP  

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Mar  3 2023 00:43:44
 2006 - 2022 Copyright by RT-Thread team
msh />
```

### 

 BSP  GPIO  1 ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

## 



## 

:

- [yuanzihao](https://github.com/zihao-yuan/), <y@yzh.email>
