# HDSC HC32L196  BSP 

## 

 HC32L196  BSP () 



- 
- BSP 
- 

 BSP  RT-Thread  RT-Thread 

## 

HC32L196  HC32L196  ARM Cortex-M0+  48MHz



![board](figures/board.jpg)

HC32L196  **** 

- MCU: HC32L196JCTA8MHz 48MHz256KB FLASH 32KB RAM
- 
  - LED:  D2 D1
  - : RESET
- :  SWD
- : MicroUSB

[HC32L196 : vtl9](https://pan.baidu.com/s/1WzSHr_Vl2aIVbZ-WJDAHZg)

## 

 BSP 

| ****  | **** |               ****                |
| :------------ | :-----------: | :-----------------------------------: |
| GPIO          |          | PA0, PA1... PF15 ---> PIN: 0, 1...95 |
| UART          |          |              UART0, UART1                 |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  GCC  MDK5 

#### 

 MicroUSB  PC  D1 

#### 

 project.uvprojx  MDK5 

>  J-LINK 

#### 

 LED  D2 

USBTTL PA9(TX)  PA10(RX) RT-Thread :

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Sep  7 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO  01  env  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5` 

## 

## 

:

-  , <815611030@qq.com>
