# Winner Micro W60X 

## 

W60X [](http://www.winnermicro.com) Wi-Fi SoC  IoT Wi-Fi  Cortex-M3  QFlashSDIOSPIUARTGPIOICPWMIS7816 , 

`packages/wm_libraries/DOC `

## 

|        |  |                                             |
| ---------- | :------: | :---------------------------------------------: |
| UART       |      | UART0/UART1/UART2                               |
| GPIO       |      |                     |
| SPI        |      |  SPI SPI BUS8/32bit         |
| WDT        |      |                                             |
| I2C        |      |  I2C   I2C                            |
| RTC        |      |  ntp  Alarm                       |
| ADC        |      | 8 channel ADC  CPU W601     |
| PWM        |      | 5 channel PWM                               |
| Timer      |      | 5Timers                               |
| Crypto     |      |  AES/DES/3DES/RC/SHA1/MD3/CRC |
| WiFi       |      |  IEEE802.11b/g/n staapap+sta  |
|      |      |  WiFi  standby        |

## 



- 

     RT-Thread  RT-Thread  

- 

     RT-Thread  ENV  BSP 

### 

 BSP  MDK5  IAR  GCC  MDK5 

#### 

1. env  `pkgs --update` 

2. env  `scons --target=mdk5` 

2.  project.uvprojx  MDK5 

#### 



- JLink

     JLink  MDK5 JLink  ****  `packages/wm_libraries/DOC`  `WM_W60X_SWD`

- 

     `Bin`  `.img`  Xmodem  UART0-115200 `packages/wm_libraries/DOC`  `WM_W60X_`

#### 

`UART0` RT-Thread  logo 

```bash
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Mar 21 2019
 2006 - 2019 Copyright by rt-thread team
```

- `UART0` `115200`

### 

 BSP  GPIO  UART0  ENV  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5`  `scons --target=iar` 

## 

>  W600 , Flash  2M Flash  1M Flash `packages/wm_libraries/DOC` 

- WM_W60X_2M_Flash
- WM_W60X_2M_Flash
- WM_W60X_2M_Flash

## 

[RT_Thread](https://github.com/RT-Thread/rt-thread)

[WinnerMicro](https://github.com/WinnerMicro)

## 

[flyingcys](https://github.com/flyingcys) < [294102238@qq.com](mailto:294102238@qq.com) >