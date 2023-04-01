# I2C 

## 1. 


- I2C I2C  (SDA)  (SCL) 

- I2C 

- I2C  FT2000/4D2000


## 2. 

I2C  I2C 

- 
- 

## 3. 

 I2C 

- 1. I2C FT2000/4, D2000E2000FT2000/4
- 2. FT2000/4, D2000I2CIOI2C0I2CI2C1/I2C2/I2C3IO
- 3. E2000MIOIICMIOIICMIO
- 4. FT2000/4, D2000I2C48MHz,E2000I2C50MHz 

 I2C 

- 1. I2C
- 2.  I2C  I2C 
- 3. 
- 4. 
- 5. 

## 4. 

### [fi2c_eeprom](../../../baremetal/example/peripheral/i2c/fi2c_eeprom/README.md)

### [fi2c_slave](../../../baremetal/example/peripheral/i2c/fi2c_master_slave/README.md)


## 5. API


### 5.1. 

- drivers/i2c/fi2c/fi2c.h

```c

typedef struct
{
    u32         instance_id; /* Device instance id */
    uintptr     base_addr;   /* Device base address */
    u32         irq_num;     /* Device intrrupt id */
    u32         irq_prority;  /* Device intrrupt priority */
    u32         ref_clk_hz;   /* Input reference clock frequency in Hz */
    u32         work_mode;   /* Device work mode Slave or Master */
    u32         slave_addr;      /* Slave Address writing/reading to/from */
    boolean     use_7bit_addr;  /* Slave in-chip address offset in 7bit or 10bit */
    u32         speed_rate;  /* I2C speed rate */
} FI2cConfig; /* Device configure setting */
```

- I2C

```c

typedef struct
{
    FI2cConfig  config;             /* Current active configs */
    u32         is_ready;           /* Device is initialized and ready */
    volatile u32    status;
    FI2cFrameTX     txframe;
    FI2cFrameRX     rxframe;
    /** only apply to master device **/
    /* Master intrrupt handler */
    FI2cEvtHandler master_evt_handlers[FI2C_MASTER_INTR_EVT_NUM];  

    /** only apply to slave device **/
    /* Slave intrrupt handler */
    FI2cEvtHandler slave_evt_handlers[FI2C_SLAVE_INTR_EVT_NUM];

} FI2c; /* Device instance */
```

- I2C

### 5.2  

-  `0x10b0000`

- [0x0] FI2C_SUCCESS : fi2c success

- [0x10b0001] FI2C_ERR_INVAL_PARM : fi2c invalid input parameters

- [0x10b0002] FI2C_ERR_NOT_READY : fi2c driver not ready

- [0x10b0001] FI2C_ERR_INVAL_PARM : fi2c invalid input parameters

- [0x10b0003] FI2C_ERR_TIMEOUT : fi2c wait timeout

- [0x10b0004] FI2C_ERR_NOT_SUPPORT : fi2c non support operation

- [0x10b0005] FI2C_ERR_INVAL_STATE : fi2c invalid state

### 5.3 API


```c
const FI2cConfig *FI2cLookupConfig(u32 instance_id);
```
- I2C

Note:
    
    - FI2cConfigFI2cCfgInitialize

Input:

    - u32 instance_id, I2C    

Return:

    - const FI2cConfig *,  NULL


```c
FError FI2cCfgInitialize(FI2c *instance_p, const FI2cConfig *cofig_p);
```
- I2C

Note:

    - I2CI2C

Input:

    - FI2c *instance_p, I2C 
    
    - const FI2cConfig *cofig_p I2C 

Return:

    FError6.2

```c
void FI2cDeInitialize(FI2c *instance_p);
```

- I2C

Note:

    - 

Input:

    - FI2c *instance_p, I2C 

Return:

    

```c
const char *FI2cErrorToMessage(FError error);
```

- I2C

Note:

    - FI2C

Input:

    - {FError} error, I2C

Return:

    - {const char *}, NULL

```c
FError FI2cMasterReadPoll(FI2c *instance_p, u32 mem_addr, u8 mem_byte_len, u8 *buf_p, u32 buf_len);
```
- I2C

Note:
    - I2C
    - Master

Input:
    - @param {FI2c} *instance_p I2C 
    - @param {u32} inchip_addr 
    - @param {u8} mem_byte_len, Size of internal memory address 1->8bit ~ 4->32bit
    - @param {u8} *buf_p 
    - @param {int} buf_len 

Return:
    - @return {FError *} 

```c
FError FI2cMasterReadIntr(FI2c *instance_p, u32 mem_addr, u8 mem_byte_len, u8 *buf_p, u32 buf_len);
```
- I2C

Note:
    - I2C
    - Master

Input:
    - @param {FI2c} *instance_p I2C 
    - @param {u32} inchip_addr 
    - @param {u8} *buf_p 
    - @param {u8} mem_byte_len, Size of internal memory address 1->8bit ~ 4->32bit
    - @param {int} buf_len 

Return:
    - @return {FError *} 

```c
FError FI2cMasterWriteIntr(FI2c *instance_p, u32 mem_addr, u8 mem_byte_len, const u8 *buf_p, u32 buf_len);
```
- I2C
Note:
    - I2C
    - Master

Input:
    - @param {FI2c} *instance_p I2C 
    - @param {u32} inchip_addr 
    - @param {u8} mem_byte_len, Size of internal memory address 1->8bit ~ 4->32bit
    - @param {u8} *buf_p 
    - @param {size_t} buf_len 

Return:
    - @return {FError *} 

```c
FError FError FI2cMasterWritePoll(FI2c *instance_p, u32 mem_addr, u8 mem_byte_len, const u8 *buf_p, u32 buf_len);
```
- I2C

Note:
    - I2C
    - Master

Input:
    - @param {FI2c} *instance_p I2C 
    - @param {u32} inchip_addr 
    - @param {u8} mem_byte_len, Size of internal memory address 1->8bit ~ 4->32bit
    - @param {u8} *buf_p 
    - @param {size_t} buf_len 

Return:
    - @return {FError *} 

```c
u32 FI2cGetIntr(FI2c *instance_p);
```
- I2C instance_p

Note:
    - I2C

Input:
    - @param {FI2c} *instance_p I2C 

Return:
    - @return {u32} 

```c
FError FI2cMasterSetupIntr(FI2c *instance_p,u32 mask);
```
- I2C

Note:
    - I2C
    - Master

Input:
    - {FI2c} *instance_p I2C
    - {u32} mask 
Return:
    - {FError *} 

```c
void FI2cMasterRegisterIntrHandler(FI2c *instance_p, u32 evt, FI2cEvtHandler handler);
```
- I2C

Note:
    

Input:
    - @param {FI2c} *instance_p I2C
    - @param {u32} evt  FI2C_MASTER_INTR_EVT_NUM
    - @param {FI2cEvtHandler} handler 

Return:

    

```c
FError FI2cSlaveSetupIntr(FI2c *instance_p);
```

- I2C

Note:
    - I2C
    - Slave

Input:
    - @param {FI2c} *instance_p I2C
    - @param {u32} evt  FI2C_MASTER_INTR_EVT_NUM
    - @param {FI2cEvtHandler} handler 

Return:
    - {FError *} 

```c
void FI2cSlaveRegisterIntrHandler(FI2c *instance_p, u32 evt, FI2cEvtHandler handler);
```

- I2C

Note:
    

Input:
    - @param {FI2c} *instance_p I2C
    - @param {u32} evt  FI2C_SLAVE_INTR_EVT_NUM
    - @param {FI2cEvtHandler} handler 

Return:

    
