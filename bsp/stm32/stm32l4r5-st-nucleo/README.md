# STM32L4R5ZI-NUCLEO bsp

## 

 QYZ  STM32L4R5ZI-NUCLEO  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 



![board](figures/board.bmp)

 **** 

- MCUSTM32L4R5ZI 120MHz2048KB FLASH 640KB RAM
- 
  - 3LD1 - 3
  - 2
  -  ST LINK
- USB OTG Micro USB 
- ST-LINK Micro USB 
 ST  [STM32L4R5ZI-NUCLEO](https://www.st.com/en/evaluation-tools/nucleo-l4r5zi.html)
## 

 BSP 

| ****      		| **** 	| ****                              		|
| :-----------------	| :----------: 	| :-----------------------------------------|
|  ST-LINK  	|          	| PG7 PG8 LPUART1                           |
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

 project.eww  IAR 

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

 BSP  GPIO  LPUART1 USBFlash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- LPUART1 PG7 PG8

- stm32L4R5ZI RAM 

 ```
      RAM1 (rw) : ORIGIN = 0x20000000, LENGTH =  192k /* 192K sram  */
      RAM2 (rw) : ORIGIN = 0x10000000, LENGTH =   64k /* 64K sram   */ 
      RAM3 (rw) : ORIGIN = 0x20040000, LENGTH =  384k /* 384K sram heap*/ 
 ```


## 

:
