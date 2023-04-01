# Allwinner tina

## 1. 

Allwinner tina ARM9SOC


|  |  |
| -- | -- |
|| tina |
|CPU| ARM9 |
|| 408MHz |
|DDR | 32MB |
|SPI Nor Flash | 8/16MB|

## 2. 

|  |  |
| --- | --- |
|PC|Linux/MacOS|
||arm-none-eabi-gcc version 6.3.1 20170620 (release)|
||scons|
1) 

```
    git clone https://github.com/RT-Thread/rt-thread.git
```
2) env
```
    cd rt-thread/bsp/allwinner_tina
    scons --menuconfig
    source ~/.env/env.sh
    pkgs --upgrade
    
```
3) 
```
    pushd /tmp
    git clone https://github.com/Icenowy/sunxi-tools.git
    pushd sunxi-tools
    git checkout -b f1c100s origin/f1c100s
    make
    sudo make install
    popd
    popd
```
4) 
```
    scons
```
rtthread.elfrtthread.binrtthread.bin

## 3. 
**Linux/MacOS,Linux/MaxOS**
rtthread.bin

1)
 arm-eabi-gcc
```
    pushd ../../..
    git clone https://github.com/uestczyh222/tina-spl.git
    pushd tina-spl
    make
    cp output/f1c100s.bin ../rt-thread/bsp/tina/tina-spl.bin
    popd
    popd
```
2)

```
1.flash 14(flash)
2.USB
3.
4.
```

```
    sudo sunxi-fel -p write  0x00000000 tina-spl.bin
    sudo sunxi-fel exec 0x00000000
    sudo sunxi-fel -p write  0x80000000 rtthread.bin
    sudo sunxi-fel exec 0x80000000
```

### 3.1 

 & 0RT-Threadlogo

```
 \ | /
- RT -     Thread Operating System
 / | \     3.0.2 build Feb  8 2018
 2006 - 2017 Copyright by rt-thread team
periph_get_pll_clk:600000000
cpu_get_clk:408000000
ahb_get_clk:200000000
apb_get_clk:100000000
msh />
```


## 4. 

|  |   |    |
| ------ | :----:  | :------:  |
| UART |  | UART0/1/2 |
| GPIO |  | / |
| clock |  | / |
| mmu |  | / |


### 4.1 IO

| IO |  |
| -- | -- |
| PE8 | USART2 RX |
| PE7 | USART2 TX |
| PA3 | USART1 RX |
| PA2 | USART1 TX |
| PE1 | USART0 TX |
| PE0 | USART0 RX |


## 5. 

:
[uestczyh222][4] < [lymz@foxmail.com][5] >


  [1]: https://www.rt-thread.org/page/download.html
  [4]: https://github.com/uestczyh222
  [5]: mailto:lymz@foxmail.com
