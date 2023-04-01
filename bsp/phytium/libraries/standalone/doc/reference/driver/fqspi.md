# FQSPI 

## 1. 

- QSPIMotorolaSPISPISPIMotorolaQSPI  SPI Flash 

- FT2000/4D2000E2000QSPI

- FT2000/4D2000 1  QSPI QSPI Flash 2Gb256MBFlash


## 2. 


- 
- drivers/qspi/fqspi

```
.
 fqspi_norflash.c
 fqspi_norflash.h
 fqspi_g.c
 fqspi_hw.c
 fqspi_hw.h
 fqspi_sinit.c
 fqspi.h
 fqspi.c
```


## 3. 


 FQSPI :

### 3.1  SFUD SPI

-  CONFIG_USE_QSPI  CONFIG_USE_SFUD 
-  SFUD 
-  SFUD  API  QSPI 

 SFUD [sfud.md](./sfud.md)

### 3.2  SFUD SPI

-  CONFIG_USE_QSPI 
-  QSPI 
-  QSPI  API  QSPI  QSPI 

## 4 

### [fqspi_nor_flash](../../../baremetal/example/peripheral/qspi/qspi_nor_flash/README.md)

### [qspi_sfud](../../../baremetal/example/storage/qspi_sfud/README.md)

## 4. API

### 4.1 

- QSPI 
```c
typedef struct
{
    u32 instance_id;  /* Id of device */
    uintptr base_addr; /* Base address of qspi */
    uintptr mem_start; /* Start address of qspi memory */
    u32 capacity;    /* Flash capacity */
    u32 dev_num;      /* Qspi device number */
    u32 channel;     /* channel number */
} FQspiConfig;
```

- QSPI 
```c
typedef struct
{
    FQspiConfig config;
    FQspiRdCfgDef rd_cfg;
    FQspiWrCfgDef wr_cfg;
    FQspiCommandPortDef cmd_def;
    FQspiCsTimingCfgDef cs_timing_cfg;
    u32 is_ready;    /**< Device is initialized and ready */
    u32 flash_size;  /* size of QSPI flash */
} FQspiCtrl;
```

- QSPI 
```c
typedef enum
{
    FQSPI_TRANSFER_1_1_1 = 0x0,
    FQSPI_TRANSFER_1_1_2 = 0x1,
    FQSPI_TRANSFER_1_1_4 = 0x2,
    FQSPI_TRANSFER_1_2_2 = 0x3,
    FQSPI_TRANSFER_1_4_4 = 0x4,
    FQSPI_TRANSFER_2_2_2 = 0x5,
    FQSPI_TRANSFER_4_4_4 = 0x6
}FQspiTransferMode;
```

- QSPI Flash
```c
typedef enum
{
    FQSPI_FLASH_CAP_4MB = 0b000,
    FQSPI_FLASH_CAP_8MB = 0b001,
    FQSPI_FLASH_CAP_16MB = 0b010,
    FQSPI_FLASH_CAP_32MB = 0b011,
    FQSPI_FLASH_CAP_64MB = 0b100,
    FQSPI_FLASH_CAP_128MB = 0b101,
    FQSPI_FLASH_CAP_256MB = 0b110,
} FQspiFlashCapcityType;
```

- QSPISCK
```c
typedef enum
{
    FQSPI_SCK_DIV_128 = 0x0,
    FQSPI_SCK_DIV_2 = 0x1,
    FQSPI_SCK_DIV_4 = 0x2,
    FQSPI_SCK_DIV_8 = 0x3,
    FQSPI_SCK_DIV_16 = 0x4,
    FQSPI_SCK_DIV_32 = 0x5,
    FQSPI_SCK_DIV_64 = 0x6
}FQspiSckDivType;
```

- QSPI
```c
typedef enum
{
    FQSPI_ADDR_SEL_3 = 0x0,
    FQSPI_ADDR_SEL_4 = 0x1,
}FQspiAddrType;
```

### 4.2 

- FQSPI_SUCCESS : fqspi success
- FQSPI_INVAL_PARAM : fqspi invalid input parameters
- FQSPI_NOT_READY : fqspi driver not ready
- FQSPI_NOT_ALLIGN : fqspi address not alligned
- FQSPI_NOT_SUPPORT : fqspi not support operation
- FQSPI_TIMEOUT : fqspi wait timeout

### 4.3 API

#### FQspiLookupConfig

- FQSPI

```c
const FQspiConfig *FQspiLookupConfig(u32 instance_id)
```

Note:

- `FQspiCfgInitialize`

Input:

- u32 instance_id, FQSPI

Return:

- const FQspiConfig *, NULL


#### FQspiCfgInitialize

- FQSPI

```c
FError FQspiCfgInitialize(FQspiCtrl *instance_p, const FQspiConfig *input_config_p);
```

Note:

- FQSPIFQSPI

Input:

- FQspiCtrl *instance_p, FQSPI

- const FQspiConfig *input_config_p, FQSPI

Return:

- FError, FQSPI_SUCCESS 


#### FQspiDeInitialize

- FQSPI

```c
void FQspiDeInitialize(FQspiCtrl *instance_p)
```

Note:

- FQSPI

Input:

- FQspiCtrl *instance_p, FQSPI

Return:




#### FQspiCommandPortConfig
- FQSPI

```c
FError FQspiCommandPortConfig(FQspiCtrl *pctrl)
```

Note:

- FQSPI
- FQSPI

Input:
 
- FQspiCtrl *pctrl, FQSPI

Return:

- FError, FQSPI_SUCCESS 


#### FQspiRdCfgConfig

- FQSPI

```c
FError FQspiRdCfgConfig(FQspiCtrl *pctrl)
```

Note:

- FQSPI
- QSPI

Input:
 
- FQspiCtrl *pctrl, FQSPI

Return:

- FError, FQSPI_SUCCESS 


#### FQspiSetLdPortData

- FQSPI

```c
FError FQspiSetLdPortData(FQspiCtrl *pctrl, const u8 *buf, size_t len)
```

Note:

- FQSPI
- flash

Input:
 
- FQspiCtrl *pctrl, FQSPI

- const u8 *buf, 

- size_t len, buf

Return:

- FError, FQSPI_SUCCESS 

#### FQspiFlashSpecialInstruction
- flashflashS25FS256S NorFlash

```c
FError FQspiFlashSpecialInstruction(FQspiCtrl *pctrl, u8 cmd, u8 *buf, size_t len);
```

Note:

- FQSPI
- flashRDID, RDSR1, RDSR2, RDCR

Input:
 
- FQspiCtrl *pctrl, FQSPI

- u8 cmd, flash

- u8 *buf, 

- size_t len, buf

Return:

- FError, FQSPI_SUCCESS 

#### FQspiFlashWriteReg
- flash

```c
FError FQspiFlashWriteReg(FQspiCtrl *pctrl, u8 command, const u8 *buf, size_t len)
```

Note:

- FQSPI

Input:

- FQspiCtrl *pctrl, FQSPI

- u8 command, 

- const u8 *buf, 

- size_t len, buf

Return:

- FError, FQSPI_SUCCESS 

#### FQspiFlashReadDataConfig

- flash

```c
FError FQspiFlashReadDataConfig(FQspiCtrl *pctrl, u8 command)
```

Note:

- FQSPI
- flashreadfast readquad read

Input:

- FQspiCtrl *pctrl, FQSPI

- u8 command flashflash

Return:

- FError, FQSPI_SUCCESS 

#### FQspiFlashReadData

- norflash

```c
size_t FQspiFlashReadData(FQspiCtrl *pctrl, u32 chip_addr, u8 *buf, size_t len)
```

Note:

- FQSPI
- FQspiFlashReadDataConfig

Input:

- FQspiCtrl *pctrl, FQSPI

- u32 chip_addr, 

- u8 *buf , 

- size_t len, buf

Return:

- FError, FQSPI_SUCCESS 

#### FQspiNorFlashWrite

- norflash 

```c
FError FQspiFlashWriteData(FQspiCtrl *pctrl, u8 command, u32 chip_addr, const u8 *buf, size_t len)
```

Note:

- FQSPI

Input:

- FQspiCtrl *pctrl, FQSPI

- u8 command flashflash

- u32 chip_addr, 

- u8 *buf , 

- size_t len, buf

Return:

- FError, FQSPI_SUCCESS 
