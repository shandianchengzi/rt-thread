# STM32F769-ST-DISCO  BSP 

## 

 RT-Thread  STM32F769-ST-DISCO  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32F769-ST-DISCO  ST  ARM Cortex-M7  216Mhz STM32F769 



![stm32f769-st-disco](figures/board.jpg)

 **** 

- MCUSTM32F769NIH6 216MHz2048KB FLASH 512KB RAM
-  RAM MT48LC4M32B2128MB
-  FLASH MX25L51245G512MB
- 
  - LED3LD1PJ13LD2PJ5LD3PA12
  - 1USERPA0
  - SAIDAC
- Arduino UNO V3 MicroSD LCD I2C 
-  ST-LINK/V2-1 SWD 

 ST  [STM32F769-ST-DISCO ](https://www.st.com/en/evaluation-tools/32f769idiscovery.html)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          | UART1 |
| ETH |  | MII, PHY: DP83848C |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PK7 ---> PIN: 0, 1...167 |
| UART              |          | UART1UART5                             |
| ****      | **** | ****                              |
|     ESP8266      |      | UART5                             |

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

LED (LD1) 

 PC , 115200-8-1-N RT-Thread :

```bash
\ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Sep 10 2019
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

- 

## 

:

-  [WillianChan](https://github.com/willianchanlovegithub)