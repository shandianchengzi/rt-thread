# EK-RA6M3-lvgl 

## ENV 

BSPenv `menuconfig` 

![](picture/lvgl/00.png)

## RGB 

 `Hardware Drivers Config  On-chip Peripheral Drivers  Enable LVGL for LCD`  `Enable LVGL for LCD_RGB565` 

![](picture/lvgl/12.png)

 `pkgs --update`  lvgl  `packages` 

![](picture/lvgl/02.png)

env  `scons --target=mdk5`  mdk 

![](picture/lvgl/03.png)

### fsp  GLCDC 

 mdk  `Tools->RA Smart Configurator`  rasc 

![](picture/lvgl/04.png)

 New Stack `Graphics->Graphics LCD` LCD 

![](picture/lvgl/05.png)

 `Interrupt->Callback Function`  `_ra_port_display_callback`

![](picture/lvgl/06.png)

 `Input->Graphics Layer 1->Framebuffer`  `Number of framebuffers` 1

![](picture/lvgl/07.png)

 LCD  Pins 

![](picture/lvgl/08.png)

 LCD_TCONx 

![](picture/lvgl/09.png)

 `Generate Project Content` 

![](picture/lvgl/10.png)

### 

 rasc  mdk 

![](picture/lvgl/11.png)

## SPI(ILI9431) 

### 



![](picture/lvgl/tft-pin.png)

 `Hardware Drivers Config  On-chip Peripheral Drivers  Enable LVGL for LCD`  `Enable LVGL for LCD_ILI9431` 

![](picture/lvgl/01.png)

 `RT-Thread online packages  peripheral libraries and drivers  TFT-LCD ILI9341 SPI screen driver software package`  `ILI9341` 

![](picture/lvgl/ili9341.png)

 `pkgs --update`  lvgl  `packages` 

![](picture/lvgl/02.png)

env  `scons --target=mdk5`  mdk 

![](picture/lvgl/03.png)

### fsp  SPI 

 mdk  `Tools->RA Smart Configurator`  rasc 

![](picture/lvgl/04.png)

 New Stack `Connectivity->SPI(r_spi)` SPI 

![](picture/lvgl/13.png)

 `Callback` SPI0 `spi0_callback`

![](picture/lvgl/14.png)

 SPI SPI0 Pins 

![](picture/lvgl/15.png)

 `Generate Project Content` 

![](picture/lvgl/16.png)

### 

 rasc  mdk 

![](picture/lvgl/11.png)