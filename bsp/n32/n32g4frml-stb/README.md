# N32G4FRML-STB BSP 

## 

N32G4FRML-STB N32G4FR

![](./figures/board.png)


 **** 

- N32G4FRML 144MHz512KB Flash144KB SRAM
- 

  - LED 3D1 (PA8D2PB4D3PB5
  - 3S1PA4S2PA5S3PA5  
  - General TM * 4Advanced TM * 2Basic TM * 2
  -  * 1
  -  * 2
  - RTC * 1
  - USART * 3UART * 4
  - I2C * 4I2S * 2
  - SPI * 3
  - SDIO * 1
  - CAN2.0B * 2
  - USB2.0   * 1
  - DVP * 1
  - EXMC/SDRAM * 1
  - ADC * 2
  - DAC * 2
- NS-LinkJ-Link



## 

 BSP 

| **** | **** | ****                         |
| :----------- | :----------: | :------------------------------- |
| GPIO         |          | PA0, PA1... ---> PIN: 0, 1...143 |
| UART         |          | UART0 - UART7                    |
| I2C          |          | I2C1                             |
| SPI          |          | SPI0 - SPI2                      |
| SPI FLASH    |          |                                  |
| ADC          |          | ADC0 - ADC2                      |
| **** | **** | ****                         |
|          |      |                          |



## 



- 

   RT-Thread  RT-Thread  

- 

   RT-Thread  ENV  BSP 

### 

 BSP MDK /IAR GCC  MDK5 

#### 

 PCUSB232PA9(MCU TX)PA10(MCU RX)

#### 

 project.uvprojx  MDK5 

>  NS-Link   NS-Link  

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Dec 24 2022 22:54:17
 2006 - 2022 Copyright by RT-Thread team
msh >
```

### 

 BSP  GPIO  0 ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5`/iar

## 



## 

:

- [BruceOu](https://github.com/Ouxiaolong/), <ouxiaolong@bruceou.cn>



