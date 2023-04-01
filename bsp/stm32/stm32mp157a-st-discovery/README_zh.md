# STM32MP157A-DK1  BSP 

## 

 RT-Thread  STM32MP157A-DK1  BSP () 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

STM32MP157A-DK1  ST  Cortex-A7  + Cortex-M4 Cortex-A7  800 MHZCortex-M4  209MHZSTM32MP157A  Flash



											![board](figures/board.png)

 **** 

- MCUSTM32MP157AACx
- 
  - LED4 LD4 (PA14) LD6 (PA13)LD7 (PH7)LD8 (PD11)
  - 4WAKE_UPRESET (NRST)USER1(PA14)USER2 (PA13)
- USB SD MIPIUSB HOSTAudioHDMIArduino
-  JTAG/SWD

 ST  [STM32MP157A-DK1 ](https://www.st.com/content/st_com/zh/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-discovery-kits/stm32mp157a-dk1.html)

## 

 BSP 

| **** | **** |     ****     |
| :----------- | :----------: | :--------------: |
| USB    |          |                  |
| SD         |      |                  |
|        |      |                  |
|      |      |                  |
| **** | **** |     ****     |
| GPIO         |          |                  |
| UART         |          | UART4 (ST-Link)  |
| EXTI         |          |                  |
| SPI          |          |                  |
| TIM          |          |                  |
| LPTIM        |          |                  |
| I2C          |          |  |
| ADC          |          |                  |
| DAC          |          |                  |
| WWDG         |          |                  |
| USB Device   |      |                  |
| USB Host     |      |                  |


## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP   IAR  IAR 

#### 

 PC

#### 

 project.eww  IAR 

>  ST-LINK  ST-LINK

#### 

 LED  LD8  Hello RT-Thread!

 PC , 115200-8-1-N RT-Thread :

>  PuTTyXShell sscom

```bash
 \ | /
- RT -     Thread Operating System
 / | \     3.1.1 build Nov 19 2018
 2006 - 2018 Copyright by rt-thread team
msh >
Hello RT-Thread!
```
#### 
##### 1. WWDG

1.  bsp  env 
2.  `menuconfig`   Hardware Drivers config  wwdg
3.  `scons --target=iar` 
4.  wwdg LD5 
5.  `wwdg_sample`  wwdg  Finsh 
6. `wwdg_sample run`  wwdg 
7. `wwdg_sample set`  wwdg 
8.  wwdg  LD5 

##### 2. DAC

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
#### 3. LPTIM

1.  bsp  env 
2.  `menuconfig`   Hardware Drivers config  lptim
3.  `scons --target=iar` 
4. lptim  `"hello rt-thread!"`
5.  `lptim_sample`  lptim  Finsh 
6. `lptim_sample run`  lptim 
7. `lptim_sample set`  lptim 


### 

 BSP  GPIO  4  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=iar` 

 [STM32  BSP ](../docs/STM32BSP.md)

## 

1.  "Engineering Mode"   DK1 BOOT BOOT0=0BOOT2=1"Engineering Mode"

   																<img src="figures\boot_switch.png" alt="boot_switch" style="zoom:50%;" />

2. 

## 

:

- [liukang](https://github.com/thread-liu) 

