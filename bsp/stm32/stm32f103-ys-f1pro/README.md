# STM32F103 YS-F1Pro  BSP 

## 

 YS-F1Pro  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

YS-F1Pro



![board](figures/board.jpg)

 **** 

- MCUSTM32F103ZET6 72MHz512KB FLASH 64KB RAM
-  RAMIS62WV51216BLL-55LI1M
-  FLASHW25Q128128MBEEPROM24c02
- 
  - LED3LED1PB0LED2PG6LED3PG7
  - 2KEY1PA0KEY2PC13
- USB SD LCD USB SLAVE
-  ST-LINK SWD 

[F103](http://www.ing10.cn/product.php?id=16)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| USB         |          |    UART1                              |
| ****      | **** | ****                               |
| GPIO              |          | PA0, PA1... PG15 ---> PIN: 0, 1...111 |
| UART              |          | UART1                           |

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

>  ST-Link  ST-Link 

#### 

D1(LED1) 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Sep  1 2022 16:42:09
 2006 - 2022 Copyright by RT-Thread team
msh >
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

- PuTTyXShell sscom
- BSP

## 

:

-  [liYony](https://github.com/liYony)<usthli@163.com>

