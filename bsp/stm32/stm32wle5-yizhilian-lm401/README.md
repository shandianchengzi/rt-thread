# LM401-LoraWan  BSP 

## 

STM32WLE5CB SOC Lora BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

LM401-LoraWANSTM32WLE5CBLoraUSBCOMLDO



![board](figures/LM401_lora.jpg)

 **** 

- MCUSTM32WLE5CB 48MHz128KB FLASH 48KB RAM16KB+32KB
- :
  - LEDpower LED(LED4 ),3User LED(LED1 LED2 LED3 )
  - (B4)3 User Button(B1B2B3)
- USB(S1)

(https://item.taobao.com/item.htm?spm=a1z0d.6639537.1997196601.33.7e207484TKjwGe&id=655801203935)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
|  USB  |          | LPUART1                              |
| ****      | **** | ****                              |
| GPIO              |          | LED1(PB5)\LED2(PB4)\LED3(PB3) |
| UART              |          | LPUART1    |
| ****      | **** | **** |

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

>  ST_LINK  ST_LINK 

#### 

 LED LED5 LED1\LED2\LED3 

USB  COM LPUART1115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Oct 10 2020
 2006 - 2021 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  LPUART1 ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  RT-Thread  PC .

## 

:

-  [CaocoWang] <18092050692@163.com>