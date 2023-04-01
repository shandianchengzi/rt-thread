# STM32F411RCT ATK-NANO  BSP 

## 

 STM32F411RCT NANO  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

ATK-NANO STM32F411RCT  ARM Cortex-M4  100Mhz STM32F411RCT 



![board](figures/board.png)

 **** 

- MCUSTM32F411RCT6 100MHz256KB FLASH 128KB RAM
-  FLASHW25Q16SPI2MBEEPROM24c02
- 
  - LED8PC0-PC7
  - 4KEY_UPPA0KEY0PC8KEY1PC9KEY2PD2
- USB DS18B20/DHT11  USB SLAVE
-  ST-LINK SWD 

 [STM32F411RCT ATK NANO ](https://item.taobao.com/item.htm?&id=608105447281)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | -------------------------------------- |
| USB         |          |  UART1 |
| SPI Flash         |          |  SPI2 |
|          |          |  ADC1 |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1...PD2 ---> PIN: 0, 1...63 |
| UART              |          | UART1/2                  |
| SPI               |          | SPI2                        |
| I2C               |          |  I2C                              |
| RTC           |          |          |
| WDT           |          |                                    |
| ADC           |          |                                    |
| ****      | **** | ****                              |
| DS18B20/DHT11 |      |                                      |

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

>  JLink  JLink 

#### 

 LED  LED0 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1 Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- N/A

## 

:

-  bigaij, <bigaij@yeah.net>