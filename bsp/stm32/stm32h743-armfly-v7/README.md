# STM32H743-armfly-V7  BSP

## 

 STM32H743-armfly-V7  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32-V7  ARM Cortex-M7  400Mhz STM32H743 



![board](figures/board.jpg)

 **** 

1. CPU STM32H743XIH6/TFBGA240, Flash 2MBRAM 1MB480MHz

2. SDRAM3232MB

3. QSPI Flash  432MBXIP

4. NAND Flash  8128MB

5. EEPROM16KB

6. SPIFLASH: 8MB

7. RGB 24bitI2C

8. 1DM9162 PHYCPUMAC,DM9000AEPFMC16bit

9. USB1USB HOST 1USB Device 

10. RS4851

11. RS2321DB9TTL UART

12. CAN2

13. SD1SDIO2TTL

14. WM8978I2SCODECFMSI4704

15. PS2/1

16. 

17. 

18. MPU6050. 

19. BH1750

20. BMP180

21. 3. 5

22. 

23. ADC. DAC

24. SPI. TTL. I2C (V5. V6

\- AD7705TM770516ADC

\- VS1053B MP3

\- GPS TTL

\- GPRSTTL

\- WiFiESP8266

\- OLED(8bit)

\- AD7606  16ADC 8

\- ADS1256 824ADC

\- DAC8501DAC(0-5V)

\- DAC8563DAC( -10V -> +10V)

\- AD9833 DDS   

25. 5V3.3VIO (32GPIO

 [STM32-V7](https://armfly.taobao.com/index.htm)

## 

 BSP 

| ****      | **** | ****                              |
| :----------------- | :----------: | :------------------------------------- |
| ****      | **** | ****                              |
| GPIO              |          |                                      |
| UART              |          | PA9,PA10                                     |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK4MDK5  IAR  GCC  MDK5 

#### 

USBTTLDB9 PCJLINKJTAGSWD

#### 

 project.uvprojx  MDK5 

>  JLINK  JLINK 

#### 

LED

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Aug  3 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  1  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

- 1 

    PA10     ------> USART1_RX

    PA9     ------> USART1_TX 

## 

:

-  [bkk](https://github.com/ghmoai )