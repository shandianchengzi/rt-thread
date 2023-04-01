# STM32F103 ATK-NANO  BSP 

## 

 RT-Thread  STM32F103 ATK-NANO  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

ATK-NANO STM32F103  ARM Cortex-M3  72Mhz STM32F103 



![board](figures/board.png)

 **** 

- MCUSTM32F103RBT6 72MHz128KB FLASH 20KB RAM
-  FLASHW25Q16SPI2MBEEPROM24c02
- 
  - LED8PC0-PC7
  - 4KEY_UPPA0KEY0PC8KEY1PC9KEY2PD2
- USB DS18B20/DHT11  USB SLAVE
-  ST-LINK SWD 

 [STM32 ATK-NANO ](https://eboard.taobao.com/index.htm)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |   UART1                              |
| SPI Flash         |          |      SPI1                            |
|              |          |      ADC1                            |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1...PD2 ---> PIN: 0, 1...63 |
| UART              |          | UART1/2/3                             |
| SPI               |          | SPI1/2                              |
| I2C               |          |  I2C                              |
| RTC               |          |  |
| WDT               |          |                                       |
| ADC               |          |                                       |
| FLASH |  |  [FAL](https://github.com/RT-Thread-packages/fal) |
| ****      | **** | ****                              |
| DS18B20/DHT11  |      |                               |


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

>  PuTTyXShell sscom

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 


## 

:

- [guozhanxin](https://github.com/Guozhanxin) 