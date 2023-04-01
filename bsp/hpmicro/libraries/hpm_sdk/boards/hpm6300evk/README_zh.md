# HPM6300EVK


::::{important}
:::{note}

:::
::::

## 


- 

    - 115200
    - 8
    - 
    - 1
    - 
    - ASCII

##  S1

- Bit 12

| Bit[2:1] |                 |
| -------- | ----------------------- |
| OFF, OFF | Quad SPI NOR flash  |
| OFF, ON  |                 |
| ON, OFF  |               |

(lab_hpm6300_evk_board)=
## 

(lab_hpm6300_evk_board_buttons)=
|  |  |
| ---- | -------- |
|PBUTN (sw3) | , TinyUF2 Boot, GPIO |
|WBUTN (sw1) | WAKE UP |
|RESET (sw2) | Reset |


## 

- SPI

|  |  |
| ---- | -------- |
| SPI3.CSN    | J28[24] |
| SPI3.SCLK   | J28[23] |
| SPI3.MISO   | J28[21] |
| SPI3.MOSI   | J28[19] |

- I2C

|  |  |
| ---- | -------- |
| I2C0.SCL    | J28[13] |
| I2C0.SDA    | J28[15] |

- ACMP

|  |  |
| ---- | -------- |
| CMP.INN5    | J26[7] |
| CMP.COMP_1  | J26[5] |

- GPTMR

|  |  |
| ---- | -------- |
| GPTMR2.CAPT_2  | J28[40] |
| GPTMR2.COMP_2  | J28[35] |
