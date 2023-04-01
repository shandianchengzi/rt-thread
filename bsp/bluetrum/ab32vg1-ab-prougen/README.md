# AB32VG1  BSP 

## 



- 
- BSP 
- 

 BSP RT-Thread  RT-Thread 

## 

 `pkgs --update` 

 1.5M [Downloader](https://github.com/BLUETRUM/Downloader)  `.dcf`  `Downloader`  `` uart1 

 `romfs`  `romfs.c` [ RomFS](https://www.rt-thread.org/document/site/tutorial/qemu-network/filesystems/filesystems/#romfs)

 `cconfig.h` 

``` c
#define HAVE_SIGEVENT 1
#define HAVE_SIGINFO 1
#define HAVE_SIGVAL 1
```

 RAM 

``` c
rt_section(".irq.example.str")
static const char example_info[] = "example 0x%x";

rt_section(".irq.example")
void example_isr(void)
{
    rt_kprintf(example_info, 11);
    ...
}
```

## 

ab32vg1-prougen  (Bluetrum)  RISC-V  120Mhz AB32VG1



![board](figures/board.png)

 **** 

- MCUAB32VG1 120MHz 192MHz8Mbit FLASH 192KB RAM
- 
  - LED: RGB
  - : 3 , USER(s2,s3) and RESET(s1)
- USB SD 

## 

 BSP 

| **** | **** | ****                                  |
| :----------- | :----------: | :---------------------------------------- |
| USB    |          |                                           |
| SD         |          |                                           |
| IRDA         |          |                                           |
|      |          |                               |
| **** | **** | ****                                  |
| GPIO         |          | PA PB PE PF                               |
| UART         |          | UART0/1/2                                 |
| SDIO         |          |                                           |
| ADC          |          | 10bit SRADC  16bit SDADC                  |
| SPI          |      |                                           |
| I2C          |          |  I2C                                  |
| RTC          |          |                                           |
| WDT          |          |                                           |
| FLASH        |          |  FAL                                  |
| TIMER        |          |                                           |
| PWM          |          | LPWM  G1 G2 G3  |
| FM receive   |          |                                           |
| USB Device   |      |                                           |
| USB Host     |      |                                           |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 


### 

 BSP  GCC 

#### 

 PC

#### 

 `RT-Thread Studio`  `scons`  `.dcf`  `Downloader` 

#### 

 LED  LED 

 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Dec  9 2020
 2006 - 2020 Copyright by rt-thread team
msh >
```
### 

 BSP  GPIO  0  SD Flash  ENV BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons` 

## 

- [greedyhao](https://github.com/greedyhao)
