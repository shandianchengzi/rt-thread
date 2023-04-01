# HPM6750EVKMINI

## 
HPM6750816Mhz2MRAMSDRAMQuad SPI NOR flash SD/eMMCLCDDMAI2S

 ![hpm6750evkmini](../../doc/images/boards/hpm6750evkmini/hpm6750evkmini.png "hpm6750evkmini")
## 
- HPM6750IVM  (816Mhz, 2MB)
- 
  - 128Mb SDRAM
  - 64Mb Quad SPI NOR Flash
- /
  - LCD
  - (DVP)
- WiFi
  - RW007
- USB
  - USB type C (USB 2.0 OTG) connector x2
- 
  - Mic
  - DAO
- 
  - TF
  - FT2232
  - 
  - RGB LED
- 
  - ART-PI
##  S1
- Bit 12

| Bit[2:1] | |
|----------|------------|
|OFF, OFF| Quad SPI NOR flash  |
|OFF, ON|  |
|ON, OFF|  |

(lab_hpm6750_evkmini_board)=
## 
(lab_hpm6750_evkmini_board_buttons)=
|  |  |
|----------|------------|
|PBUTN (S2) | , TinyUF2 Boot, GPIO |
|WBUTN (S3) | WAKE UP |
|RESET (S4) | Reset |


## 


- SPI

|  |  |
| ---- | -------- |
| SPI2.CSN    | P1[24] |
| SPI2.SCLK   | P1[23] |
| SPI2.MISO   | P1[21] |
| SPI2.MOSI   | P1[19] |

- I2C

|  |  |
| ---- | -------- |
| I2C0.SCL    | P1[13] |
| I2C0.SDA    | P1[15] |

- CORE1

|  |  |
| ---- | -------- |
| UART13.TXD    | P1[8] |
| UART13.RXD    | P1[10] |

- ACMP

|  |  |
| ---- | -------- |
| CMP.INN6    | P2[11] |
| CMP.COMP_1  | P1[7] |

- GPTMR

|  |  |
| ---- | -------- |
| GPTMR2.CAPT_2  | P2[15] |
| GPTMR2.COMP_2  | P2[19] |