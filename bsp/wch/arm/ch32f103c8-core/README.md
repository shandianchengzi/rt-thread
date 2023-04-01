# ch32f103c8 BSP 
## 
|       |           |
| --------- | ------------- |
|   | ch32f103c8    |
| CPU       | ARM Cortex M3 |
|       | 72M           |
| SRAM  | 20K           |
| FLASH | 64K           |

## 

MDK5

| IDE/ |                    |
| ---------- | ---------------------------- |
| MDK5       | MDK534                       |




## 

 BSP 

|       |  |                        |
| --------- | -------- | :------------------------:|
| UART      |      | USART1/2/3                 |
| GPIO      |      | PA0...PD2                  |
| IIC       |      | I2C(7)                |
| SPI       |      | SPI1/2                     |
| WDT       |      | IWDG                       |
| RTC       |      |            |


### IO

| IO |  |
| ---- | -------------- |
| PA9  | USART1_TX      |
| PA10 | USART1_RX      |
| PA2  | USART2_TX      |
| PA3  | USART2_RX      |
| PC10 | USART3_TX      |
| PC11 | USART3_RX      |
| PA4  | SPI1_CS        |
| PA5  | SPI1_SCK       |
| PA6  | SPI1_MISO      |
| PA7  | SPI1_MOSI      |
| PB12 | SPI2_CS        |
| PB13 | SPI2_SCK       |
| PB14 | SPI2_MISO      |
| PB15 | SPI2_MOSI      |
| PB8  | I2C1_SCL       |
| PB9  | I2C1_SDA       |
| PB10  | I2C2_SCL      |
| PB11  | I2C2_SDA      |


## 

     RT-Thread  RT-Thread  

### 

 BSP  MDK5  MDK5 

#### 

 PC

#### 

 project.uvprojx  MDK5 

>  SWD  wch-linkdaplink 

#### 


 PC , 115200-8-1-N RT-Thread :

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.4 build Aug 30 2021
 2006 - 2021 Copyright by rt-thread team
msh >
```

## 

:

- [charlown](https://github.com/charlown) 