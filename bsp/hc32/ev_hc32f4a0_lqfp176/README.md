# XHSC EV_F4A0_LQ176  BSP 

## 

 EV_F4A0_LQ176  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

EV_F4A0_LQ176  XHSC  HC32F4A0SITB  ARM Cortex-M4  240 MHz HC32F4A0SITB 



 ![board](figures/board.jpg)

EV_F4A0_LQ176  **** 

- MCUHC32F4A0SITB240MHz2048KB FLASH512KB RAM
- RAMIS62WV51216(SRAM, 1MB) IS42S16400J(SDRAM, 8MB)
- FLASH: MT29F2G08AB(Nand, 256MB) W25Q64(SPI NOR, 64MB)
- 
  - LED3  user LED(LED0,LED1,LED2)
  - 11 (K1~K9)WAKEUP(K10)RESET(K11)
- USBSDLCDUSB HSUSB FSUSB 3300DVP3.5mmLine in
- DAPJTAG/SWD

[EV_F4A0_LQ176](http://www.xhsc.com.cn)

## 

 BSP 

| ****  | **** |               ****                |
| :------------ | :-----------: | :-----------------------------------: |
| USB     |           |           UART1                  |
| LED           |          |           LED                        |
| ETH           |          |              					     |
| ADC           |          |                                       |
| CAN           |          |                                       |
| ****  | **** |               ****                |
| :------------ | :-----------: | :-----------------------------------: |
| GPIO          |          | PA0, PA1... PI13 ---> PIN: 0, 1...141 |
| UART          |          |              UART1~10                 |
| SPI           |          |              SPI1~6                   |
| I2C           |          |               I2C                 |


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

LEDLED11

USBCOM1 RT-Thread :

```
 \ | /
- RT -     Thread Operating System
 / | \     4.1.0 build Apr 24 2022 13:32:39
 2006 - 2022 Copyright by RT-Thread team
msh >
```

### 

 BSP  GPIO   1  env  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5/iar` 

## 

## 

:

-  [MCU](http://www.xhsc.com.cn)<mcu_eco@xhsc.com.cn>