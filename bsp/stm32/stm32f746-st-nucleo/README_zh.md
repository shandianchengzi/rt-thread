# STM32F746 NUCLEO-F746ZG BSP 
## 

 NUCLEO-F746ZG  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

NUCLEO-F746ZGst ARM Cortex-M7  216Mhz STM32F746 



![board](figures/en.high-perf_nucleo-144_mbed.jpg)

 **** 

- MCUSTM32f746 216MHz1MB FLASH 320KB RAM 16K CACHE

- 
  - LED 3LED1 (PB0),LED2PB7LED3PB14
  - 2B1PC13B2
- USB 3
- ST-LINK

ST [NUCLEO-F746zg](https://www.st.com/en/evaluation-tools/nucleo-f746zg.html)

## 

 BSP 

| ****      | **** | ****                              |
| :-----------------| :----------: | :-------------------------------------|
| USB 3        |          |                                       |
|             |      | PHY  LAN8720A LAN8742A |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PK15 ---> PIN: 0, 1...144 |
| UART              |          | UART3                                 |
| ****      | **** | ****                              |
|               |      |                               |

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

>  ST-LINK  ST-LINK 

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.0 build Jan  9 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  3  Ethernet  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 



## 

:

-  [BruceOu](https://github.com/Ouxiaolong/), <ouxiaolong@bruceou.cn>