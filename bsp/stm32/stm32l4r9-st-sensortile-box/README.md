# STM32L4R9ZI-MKSBOX1V1 bsp

## 

 supperthomas  STM32L4R9ZI-MKSBOX1V1  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 



![board](figures/board.png)

 **** 

- MCUSTM32L4R9 120MHz2048KB FLASH 640KB RAM
- 
  - 2LED1PB5LED 2(PF2) 
  - UART1: RX(PA9) TX(PA10)
  - 1USER_PB1PG1
  -  BLE SPBTLE-1SSPI/UART)
  - STTS751(I2C3_SDA PG8  I2C3_SCL PG7 )
  - HTS221 LPS22HH   I2C3_SDA(PB7) I2C3_SCL(PB6)
  - LIS2DW12  CS_ACC(PE11)
  - 
- SD USB OTG Micro USB 
- ST-LINK Micro USB 
 ST  [STM32L4R9ZI-MKSBOX1V1](https://www.st.com/zh/evaluation-tools/steval-mksbox1v1.html)

## 

 BSP 

|   ****    |  ****     |   ****   |
| ---- | ---- | ---- |
|  ST-LINK  |  | RX(PA9) TX(PA10) ST-LINK ST-LINK |
| BLE SPBTLE-1S |  |  |
|  |  |  |
|  |  |  |
|   ****      |    ****   |   ****    |
| GPIO |  | LED1PB5LED 2(PF2) USER_PB1PG1 |
| UART |  | UART1: RX(PA9) TX(PA10)   CONSOLE |
| USBD |  | USBD CDC  |
| SPI1 |  | SPI1_MOSI(PE15) SPI1_MISO(PE14) SPI1_CLK(PE13) |
| SPI2 |  | SPI2_MOSI(PC3) SPI2_MISO(PD3) SPI2_SCK(PD1) SPI2_CS(PD0) |
| IIC1 |  | I2C1_SCL(PB6)   I2C_SDA(PB7) |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

>  STLINK NUCLEOSTLINKSWD

 LED  LED 

 PC , STLINK115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Mar 22 2020
 2006 - 2020 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1 SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 1 PA9   PA10ST-LINK
- ST-LINKDFU


## 

- :

  - [super_mcu] [super_mcu@qq.com](mailto:super_mcu@qq.com)

-  

   [STM32L4R9ZI-MKSBOX1V1](https://github.com/supperthomas/BSP_BOARD_STM32L4R9ZI_MKSBOX1V1.git)

