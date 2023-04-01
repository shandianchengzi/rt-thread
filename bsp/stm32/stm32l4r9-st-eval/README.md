# STM32L4R9I-EVAL bsp

## 

 JHB  STM32L4R9I-EVAL  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 



![board](figures/board.png)

 **** 

- MCUSTM32L4R9 120MHz2048KB FLASH 640KB RAM
-  FLASHM29W128GL70ZA6ENOR FLASH16MB
- 
  - 4LED1 - 4
  - 1wakeupPC13
  - TFTLCD 2
  -  ST LINK
- SD USB OTG Micro USB 
- ST-LINK Micro USB 
 ST  [STM32L4R9I-EVAL](https://www.st.com/content/st_com/zh/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-eval-boards/stm32l4r9i-eval.html)
## 

 BSP 

| ****      		| **** 	| ****                              		|
| :-----------------	| :----------: 	| :-----------------------------------------|
|  ST-LINK  	|          	| PB10 PB11 USART3                      	|
| LCD            		|          	| DSI mode round lcd                        |
| TOUCH            		|          	| touch for round lcd                       |
| SRAM              	|          	|                              				|
| ****     		| **** 	| ****                              		|
| GPIO              	|          	| 											|
| UART              	|          	| USART3                             		|





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

>  STLINK  STLINK 

#### 

 LED  LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Apr 4 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  3 SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 3 PB10 PB11

- stm32L4R9 RAM 

 ```
      RAM1 (rw) : ORIGIN = 0x20000000, LENGTH =  192k /* 192K sram  */
      RAM2 (rw) : ORIGIN = 0x10000000, LENGTH =   64k /* 64K sram    */ 
      RAM3 (rw) : ORIGIN = 0x20040000, LENGTH =  384k /* 384K sram heap*/ 
 ```


## 

:

-  [jhb](https://github.com/jhbdream?tab=repositories)