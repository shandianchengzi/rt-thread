# STM32MP157A-EV1  BSP 

## 

 RT-Thread  STM32MP157A-EV1  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32MP157A-EV1  ST  Cortex-A7  + Cortex-M4 Cortex-A7  650MHZCortex-M4  209MHZ



											![board](figures/board.png)

 **** 

- MCUSTM32MP157AAAx
- 
  - LED4 LD4(PD8), LD5(PD9), LD2(PA13), LD3(PA14)
  - 4WAKE_UP, RESET (NRST), USER1(PA13), USER2 (PA14)
- USB SD MIPIUSB HOSTAudioHDMIArduino
-  JTAG/SWD

 ST  [STM32MP157A-DK1 ](https://www.st.com/content/st_com/zh/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-discovery-kits/stm32mp157a-dk1.html)

## 

 BSP 

| ****   | **** |    ****     |
| :------------- | :----------: | :-------------: |
| USB      |          |                 |
| PMIC           |      | ST  IC  |
|          |      |     OV5640      |
| MFX            |      | ST  |
| FMC            |      |   NAND FLASH    |
| QSPI FLASH     |      |   MX25L51245G   |
| OpenAMP        |      |         |
|  |      |                 |
| SD           |      |     SDMMC1      |
| eMMC           |      |     SDMMC2      |
|          |      |     |
|        |      |                 |
| ****   | **** |    ****     |
| GPIO           |          |                 |
| UART           |          | UART4 (ST-Link) |
| EXTI           |          |                 |
| SPI            |          |                 |
| TIM            |          |                 |
| LPTIM          |          |                 |
| I2C            |          |             |
| ADC            |          |                 |
| DAC            |          |                 |
| WWDG           |          |                 |
| MDMA           |      |                 |
| SPDIFRX        |      |                 |
| DFSDM          |      |                 |
| PWM            |      |                 |
| FDCAN          |      |                 |
| CRC            |      |                 |
| RNG            |      |                 |
| HASH           |      |                 |


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

>  ST-LINK  ST-LINK 

#### 

 LED  LD4 

 PC , 115200-8-1-N RT-Thread :

>  PuTTyXShell sscom

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
```
#### 
##### 1. DAC

1.  bsp  env 
2. `menuconfig`  Hardware Drivers config  dac
3.   `scons --target=iar` 

###### Finsh

 `dac probe`  DAC 

```c
msh />dac probe dac1
probe dac1 success
```

 `dac enable` 

```c
msh />dac enable 1
dac1 channel 1 enables success
```

 DAC  `dac write` 

```c
msh />dac write 1 1000
dac1 channel 1 write value is 1000
```

 `dac disable` 

```c
msh />dac disable 1
dac1 channel 1 disable success
```

### 

 BSP  GPIO  4  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

1.  "Engineering Mode"   DK1 BOOT BOOT0=0BOOT2=1"Engineering Mode"

   																<img src="figures\boot.png" alt="boot" style="zoom:50%;" />

2. 

## 

:

- [liukang](https://github.com/thread-liu) 

