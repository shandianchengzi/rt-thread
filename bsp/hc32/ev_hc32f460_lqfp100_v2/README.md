# XHSC EV_F460_LQ100_V2  BSP 

## 

 EV_F460_LQ100_V2  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

EV_F460_LQ100_V2  XHSC  HC32F460PETB  ARM Cortex-M4  200 MHz HC32F460PETB 



 ![board](figures/board.jpg)

EV_F460_LQ100_V2  **** 

- MCU: HC32F460PETB200MHz512KB FLASH192KB RAM
- 
  - LED: 4 User LED(LED0LED1LED2LED3)
  - : 11 (K1~K9), WAKEUP(K10), RESET(K11)
- : USBSDUSB FS3.5mmLine in
- : DAPJTAG/SWD

[EV_F460_LQ100_V2](http://www.xhsc.com.cn)

## 

 BSP 

| ****  | **** |               ****                |
| :------------ | :-----------: | :-----------------------------------: |
| USB     |           |           UART4                  |
| LED           |          |           LED                   |
| ****  | **** |               ****                |
| :------------ | :-----------: | :-----------------------------------: |
| ADC           |          | ADC1: CH10, CH11, CH12,<br>ADC2: CH7 |
| CAN           |          |              CAN1                      |
| GPIO          |          | PA0, PA1... PH2 ---> PIN: 0, 1...82 |
| I2C           |          |  |
| UART          |          |              UART1~4                 |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

Type-A to MircoUSBPC

#### 

 project.uvprojx  MDK5 

>  DAP 

#### 

LEDLED1

USBCOM4 RT-Thread :

```
 \ | /
- RT -     Thread Operating System
 / | \     4.1.1 build May 25 2022 08:55:55
 2006 - 2022 Copyright by RT-Thread team
msh >
```

### 

 BSP  GPIO   4  env  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

## 

## 

:

-  [MCU](http://www.xhsc.com.cn)<mcu_eco@xhsc.com.cn>