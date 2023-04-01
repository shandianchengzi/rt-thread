# Infineon Psoc6-CY8CKIT-062S2-43012 

## 

 `RT-Thread`  `PSoC6 CY8CKIT-062S2-43012` BSP () 



- 
- BSP 
- 

 BSP RT-Thread  `RT-Thread` 

## 

`PSoC6 CY8CKIT-062S2-43012` 32CPU ARM Cortex-M4  ARM Cortex-M0150-MHz Arm Cortex-M4F CPU ()100-MHz Cortex M0+ CPUMPU PSoC6 

[CY8CPROTO-062-4343W - Infineon Technologies](https://www.infineon.com/cms/en/product/evaluation-boards/cy8cproto-062-4343w/)

 **** 

- MCUCY8C624ABZI-S2D44Cortex-M4 150MHzCortex-M0 100MHz2MB Flash  1MB SRAM
	    MCU [PSoC 6 MCU: CY8C62x8, CY8C62xA Datasheet (infineon.com)](https://www.infineon.com/dgdl/Infineon-PSOC_6_MCU_CY8C62X8_CY8C62XA-DataSheet-v17_00-EN.pdf?fileId=8ac78c8c7d0d8da4017d0ee7d03a70b1)
- microSD card , 64-Mb Quad-SPI NOR flash CYW43012 Wi-Fi + Bluetooth Combo Chip
- ModusToolbox 2.0/MDK V5
		PSoC Creator  [ModusToolbox Software - Infineon Technologies](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
- CY8CKIT-062-BLE PSoC 6 BLE Pioneer Kit
		 https://www.cypress.com/file/390496/download

## 

 BSP 

| **** | **** |   ****    |
| :----------: | :----------: | :-----------: |
|  USB   |          |     UART5     |
|     GPIO     |          |              |
|     UART     |          |    UART0-5    |
|     I2C      |          | + I2C |
|     RTC      |          |              |
|     WDT      |          |              |
|     PWM      |          |              |
|     SPI      |          |              |
|  HardTimer   |          |              |
|     DAC      |          |     IDAC      |
|    Flash     |          |   Falsh   |
|    Touch     |          |       |
|     SDIO     |      |              |
|  USB Device  |      |              |
|   USB Host   |      |              |

## 

 BSP  `MDK V5`  `RT-Thread Studio` ARMClang / GCC

###  MDK V5 

#### 

 PC

#### 

1

 MDK  `Infineon-PSoC6`  [keil](https://www.keil.com/dd2/pack) 

![mdk_package](./figures/mdk_package.png)

2  `MDK`

3

 `DAP-LINK`  `SWD` 

###  RT-Thread Studio 

#### 

*   `RT-Thread Studio` >> RT-Thread Studio

![](./figures/studio1.png)

*  `PSoC6 CY8CKIT-062S2-43012` 

![](./figures/studio2.png)

#### 

*  IDE 

![](./figures/studio3-build.png)

*  `Debug`  `Download` /

  

  ![](./figures/studio4-download.png)

## 

 115200LED  500HZ  `RT-Thread` 

`MobaXterm`

```
 \ | /
- RT -     Thread Operating System
 / | \     4.1.1 build Jul 25 2022 18:03:35
 2006 - 2022 Copyright by RT-Thread team
msh >
```

## 

:

- [Rbb666](https://github.com/Rbb666)