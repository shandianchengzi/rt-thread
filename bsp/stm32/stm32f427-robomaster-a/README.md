# STM32F427 RoboMaster A BSP 

## 

 RoboMaster A  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

RoboMasterDIYSTM32F427IIH6IMURoboMasterM3508 M2006UWBDJISDK



![board](figures/board.png)

 **** 

- MCUSTM32f427IIH6 180MHz2048KB FLASH 256KB RAM(64KB CCM RAM)
- 
  - LED2D10PE11D9PE14
  - 1KEYPB2
- SD  OLED 
-  JTAG/SWD

 RoboMaster [RoboMaster A](https://www.robomaster.com/zh-CN/products/components/general/development-board)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| SD              |      |                                       |
| CAN               |      |    24vXT30usb          |
| ****      | **** | ****                              |
| GPIO              |          | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART              |          | UART1/3/6/7/8                         |
| SPI               |      | SPI5                                  |
| I2C               |      |                                       |
| SDIO              |      |                               |
| RTC               |        |                                       |
| PWM               |      |                               |
| ****      | **** | ****                              |
|                 |...           |  ...

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

usbj-link PC

#### 

 project.uvprojx  MDK5 

>  xxx  xxx 

#### 

LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.2 build Sep  1 2019
 2006 - 2019 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  6  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- **24vXT30() ** ()CAN

## 

:
- [a1012112796](https://github.com/a1012112796)