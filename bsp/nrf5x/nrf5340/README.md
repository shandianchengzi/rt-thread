# nRF5340-PCA10095 BSP

## 

nRF5340



|                                                |                 |                                 |
| ------------------------------------------------------------ | --------------------------- | ----------------------------------- |
| [PCA10095](https://www.nordicsemi.com/Products/Development-hardware/nRF5340-DK) | QSPI FLASH, 4 button4 LED | UART0                               |

|                                                              |                             |                                     |


`menuconfig` -> `Hardware Driver Config` -> `Select Bsp board`





- 
- 

## 

## 

 BSP 

| **** | **** |        ****        |
| :----------- | :----------: | :--------------------: |
| GPIO         |          |         GPION          |
| UART         |          |         UART0 1000000|
| PWM          |          |                    |
| SPI          |          |                    |
| QSPI         |          | QSPI FLASH |
| RTC          |          |                        |
| ADC          |          |                        |
|              |              |                        |
|              |              |                        |
|              |              |                        |



### 

 BSP  GPIO   0  env  BSP 

1.  bsp  env 

2. `menuconfig`

3. `pkgs --update`

4. `scons --target=mdk5` 



## 

.configboard/Kconfigboard/$(board_name)README.md.config

## 

## 

:

-  [Andrew], <andrew.li@nordicsemi.no>