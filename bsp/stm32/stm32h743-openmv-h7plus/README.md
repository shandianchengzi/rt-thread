# OPENMV4-H7-PLUS  BSP 

## 

 OPENMVH7-PLUS BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

OPENMV4-H7-PLUS  OPENMV STM32H7 Cortex-M7  



![board](figures/board.png)

 **** 

- MCUSTM32H743IIK6 480MHz2MB FLASH 1M RAM , Core Mark Score: 2400
- 
  - RGB3LED_R PC0, LED_G(PC1), LED_BPC2
  - SRAM:   32MB 
  - QSPI FLASH: 32MB 
-  SWD

 [OpenMV4 H7 Plus](https://singtown.com/product/50812/openmv4-h7-plus/)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| GPIO              |          |                                        |
| USART             |          | USART1(PB14 TX)(PB15 RX) |
| SDRAM |  | IS42S32800  BANK1 |
| QSPI FLASH |  | W25Q256JV |
| SDIO |  | USD-1040310811 |
| USBCDC |  |  |
| RTC |  | |
| CAMERA |  | OV5640 |
| DCMI |  |  |
| I2C |  | I2C1(PB8 SCL)(PB9 SDA); I2C2 (PB10 SCL)(PB11 SDA) |

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

>  ST-LINK   ST-LINK 

#### 

 LED_R  500MS 

USBTTLUSART1115200-8-1-N,  RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Oct  2 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
BSPUSBCDCshell

### 

 BSP  GPIO  USART1QSPI FLASHUSBCDCCAMERA ENV BSP 

1.  bsp  env 
2. `menuconfig`
3. `pkgs --update`
4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  RT-Thread  PC  BSP  GPIO 

## 

:

-  [super_mcu] <super_mcu@qq.com>