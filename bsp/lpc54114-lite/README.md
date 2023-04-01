# LPC54114-Lite  BSP 

## 

 LPC54114-Lite  BSP () LPC54114-Lite  NXP LPC54110 Board 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

LPC54114-Lite 



![LPC54114-Lite](figures/LPC54114-Lite(LPC54110).jpg)

****

- MCULPC54114J256BD64 Cortex-M4/M0+  MCU  100MHz256KB FLASH 192KB RAM
-  FLASH MD25D16SIG16MBIT
- 
  - LED8 LD4-LD7PIO0_30PIO0_29PIO0_26PIO0_25LD8-LD11PIO0_22PIO0_21PIO0_19PIO0_15
  - 4 PB2-PB5PIO1_8PIO1_9PIO1_10PIO1_11
- USBTF
- SWD

LPC54114-Lite  [](http://www.manley.com.cn/web/admin_ml32/pic/down/LPC54110%BF%AA%B7%A2%B0%E5%D3%C3%BB%A7%CA%D6%B2%E1.pdf)[](http://www.manley.com.cn/web/product_detail.asp?pro=326)

## 

 BSP 

|****     |****|****                             |
| ----------------- | :----------: | ------------------------------------- |
| SPI Flash |  |-                                       |
| SPI TF  |  |-                                       |
| I2C  <BR>(PCT2075DP) |  |-      |
| I2S  /  <BR>(WM8904) |  |      |
| PDM  <BR>(SPH0641LM4H) |  |-      |
|****     |****|****                             |
| GPIO              |          | PIO0_0 ... PIO1_31 ---> PIN: 0, 1...63 |
| UART              |          | UART0                            |
| SPI               |      | SPI2         |
| I2C               |      | I2C4          |
| ADC          |  |  |
| PWM               |      |                               |
| USB Device        |      |                               |
| IWG               |      |                               |
|****     |****|****                             |
| Arduino  |      |-                                      |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 Micro USB  CN1  PC mbedSerial  MDK5  LPC54114  pack

#### 

 project.uvprojx  MDK5 

>  CMSIS-DAP  Micro USB 

#### 

 LD4  LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
## 

-  mbedSerial 
-  MDK5 pack
- BSP  M4 

## 

:

- [yangjie](https://github.com/yangjie11)