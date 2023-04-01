# LM402-LoraWan  BSP 

## 

STM32WLE5JC SOC Lora BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

LM402-LoraWANSTM32WLE5JCLoraUSBCOMLDO



![board](figures/LM402_lora.jpg)

 **** 

- MCUSTM32WLE5JC 48MHz256KB FLASH 64KB RAM32KB+32KB
- :
  - LEDpower LED(LED4 ),3User LED(LED1 LED2 LED3 )
  - (B4)3 User Button(B1B2B3)
- USB(S1)

(https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-23675552484.16.14f23fb8Dhsg1H&id=670469995404)

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
 / | \     4.1.0 build Mar 30 2022 14:55:43
 2006 - 2022 Copyright by RT-Thread team
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