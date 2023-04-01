# WeAct Studio STM32H7xx Core Board BSP 

## 

 WeAct Studio STM32H7xx Core Board  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32H7xx Core Board  WeAct Studio  ARM Cortex-M7 480Mhz128KB ROM 2MB ROM 1MB RAM8MB SPI Flash8MB QSPI Flash

* 2*22 Pin 2.54mm I/O x 2
* 4 Pin 2.54mm SW x 1
* USB C (type C) x 1
* MicroSD TF x 1
* 8Bit DCMI x 1
* User Key K1 (PC13) x 1
* NRST Key x 1
* BOOT0 Key x 1



![board](figures/board.jpg)

[STM32H7xx Core Board](https://github.com/WeActTC/MiniSTM32H7xx)

## 

 BSP 

| ****     | **** |         ****         |
| :--------------- | :----------: | :----------------------: |
| 0.96' ST7735 TFT |          |           SPI1           |
| TF Card          |        |                          |
| SPI Flash        |          | W25Q64JVLittlefsSPI1 |
| QSPI Flash       |        |    W25Q64JVLittlefs    |
| OV7670 Camera    |        |                          |
| OV2640 Camera    |        |                          |
| OV7725 Camera    |        |                          |
| OV5640-AF Camera |        |                          |
| ****     | **** |         ****         |
| GPIO             |          |                          |
| UART             |          |          USART1          |
|                  |          |        SPI1SPI4        |
| USB Device       |        |          USB HS          |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

 PC usb  PB14(USART1_TX)  PB15(USART1_RX)

#### 

 project.uvprojx  MDK5 

>  WeAct Studio [STM32 ](http://www.weact-tc.cn/2019/11/30/STM32Download/#more)
>
> [](https://github.com/WeActTC/MiniSTM32H7xx/blob/master/SDK/QSPI_Flasher/README.md)flash

#### 

LED

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     5.0.0 build Oct 15 2022 16:28:21
 2006 - 2022 Copyright by RT-Thread team
msh />
```
### 

 BSP  GPIO  1  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk4/mdk5/iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

-  128k  Keil 
  -  keil  H743  2MB Flash 
  -  STM32H7x_2048.FLM  `Keil\Keil_v5\ARM\Flash` 
  - 
- 1 

    PB14     ------> USART1_TX

    PB15     ------> USART1_RX

## 

:

-  [NU-LL](https://github.com/NU-LL )