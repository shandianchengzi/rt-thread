# HPM6750EVK

## 

HPM6750816Mhz2MRAMSDRAMQuad SPI NOR flash SD/eMMCLCDDMAI2S

 ![hpm6750evk](../../doc/images/boards/hpm6750evk/hpm6750evk.png "hpm6750evk")

## 

- HPM6750IVM  (816Mhz, 2MB)
- 
  - 256Mb SDRAM
  - 128Mb Quad SPI NOR Flash
- /
  - LCD
  - (DVP)
- 
  - 1000 Mbits PHY
  - 100 Mbits PHY
- USB
  - USB type C (USB 2.0 OTG) connector x3
- 
  - Line in
  - Mic
  - Speaker
  - DAO
- 
  - TF
  - FT2232
  - 
  - RGB LED
  - CAN
- 
  - 

##  S1

- Bit 12

| Bit[2:1] |                 |
| -------- | ----------------------- |
| OFF, OFF | Quad SPI NOR flash  |
| OFF, ON  |                 |
| ON, OFF  |               |

- Bit 3PWM

| Bit3 |  |
| ---- | -------- |
| OFF  |  |
| ON   | PWM      |

(lab_hpm6750_evk_board)=
## 

(lab_hpm6750_evk_board_buttons)=
|  |  |
| ---- | -------- |
|PBUTN (S2) | , TinyUF2 Boot, GPIO |
|WBUTN (S3) | WAKE UP |
|RESET (S4) | Reset |

## 

- J12 `P-UH P-UL`PWM

  ![image-1](../../doc/images/boards/hpm6750evk/hpm6750evk_pwm_output_pin.png "image-1")

- SPI

|  |  |
| ---- | -------- |
| SPI2.CSN    | J20[6] |
| SPI2.SCLK   | J20[7] |
| SPI2.MISO   | J20[8] |
| SPI2.MOSI   | J20[9] |

- I2C

|  |  |
| ---- | -------- |
| I2C0.SCL    | J20[3] |
| I2C0.SDA    | J20[4] |

- CORE1

|  |  |
| ---- | -------- |
| UART13.TXD    | J20[5] |
| UART13.RXD    | J20[6] |

- ACMP

|  |  |
| ---- | -------- |
| CMP.INN6    | J12[8] |
| CMP.COMP_1  | J12[6] |

- GPTMR

|  |  |
| ---- | -------- |
| GPTMR4.CAPT_1  | J12[6] |
| GPTMR3.COMP_1  | J12[7] |


