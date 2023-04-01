# STM32F103 - M3S  BSP 

## 

 STM32F103 - M3S  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F103 - M3S  ARM Cortex-M3  72Mhz STM32F103 



![board](figures/board.png)

 **** 

- MCUSTM32F103ZET6 72MHz512KB FLASH 64KB RAM
-  RAM24C022KB
-  FLASHW25Q648MB
- 
  - LED2LED2PE5LED3PB5
  - 4S1PE4S2PE3S3PE2S4PA0
- USB SD RS232 LCD NRF24L01
-  JTAG/SWD

 [STM32F103-M3S ](https://item.taobao.com/item.htm?spm=a1z10.1-c.w4004-1022655459.10.44ae4d22Wa8UIo&id=44835368405)

## 

 BSP 

| **** | **** | **** |
| :-----: | :-----: | :-----: |
| SDCARD |  |  |
| SPI FLASH |  | W25Q648MB |
| EEPRAM |  | 24c022KB |
| **** | **** | **** |
| GPIO  |  |  |
| USART |  | USART1 |
| SDIO |  |  |
| SPI |  | SPI1/2/3 |
| I2C |  | I2C |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| **** | **** | **** |
| NRF24L01 |  |  NRF24L01  `NRF24L01_CE_PIN`  `NRF24_IRQ_PIN`  SPI  |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

>  st-link  st-link 

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Apr  9 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  SecureCRT  XCOM V2.0

## 

:

-  [WillianChan](https://github.com/willianchanlovegithub)