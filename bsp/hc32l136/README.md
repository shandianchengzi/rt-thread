# HDSC HC32LFx3x-STK-V2.0  BSP 

## 

 HC32LFx3x-STK-V2.0  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

HC32LFx3x-STK-V2.0  HDSC  HC32L136  ARM Cortex-M0  48 MHz



![board](figures/board.png)

HC32LFx3x-STK-V2.0  **** 

- MCUHC32L136 48MHz64KB FLASH 8KB RAM
- 
- 
- DAP JTAG/SWD

## 

 BSP 

| ****  | **** |               ****                |
| :------------ | :-----------: | :-----------------------------------: |
| GPIO          |          | PA0, PA1... PI15 ---> PIN: 0, 1...63  |
| UART          |          |              UART0~1                 |
| LED           |          |              LED                     |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK4MDK5IARGCC MDK5 

#### 



#### 

 project.uvprojx  MDK5 

>  J-LINK 

#### 

 LED 

PA2PA3 RT-Thread :

```
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Aug 20 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```

### 

 BSP  GPIO   1  env  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

## 

## 

:

-  [Ching], <515892376@qq.com>