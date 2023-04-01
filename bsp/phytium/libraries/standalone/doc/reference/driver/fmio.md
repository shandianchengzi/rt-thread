# I2C 

## 1. 

- E2000  MIO  UART  I2C.
- MIO E2000

## 2. 

MIO MIO

- I2C
- 

## 3. 

 MIO 

- 1. MIO E2000 Q D SE2000
- 2. IICIIC

 MIO 

- 1. ID
- 2. 
- 3. I2Cuart

## 5. API

### 5.1. 

- drivers/mio/fmio/fmio.h

```c

typedef struct
{
    FMioConfig config;  /* mio config */
    u32 is_ready;   /* mio initialize the complete flag */
}FMioCtrl;

```

```c

typedef struct
{
    u32     instance_id;        /*mio id*/
    uintptr func_base_addr; /*I2C or UART function address*/
    u32     irq_num;     /* Device intrrupt id */
    uintptr mio_base_addr;  /*MIO control address*/
    u32     version;            /*mio version*/
    u32     function_type;      /*mio function type*/
    u32     mio_status;         /*mio function type status*/
} FMioConfig;               /*mio configs*/

```
- MIO

### 5.3 API

```c
const FMioConfig *FMioLookupConfig(u32 instance_id);
```
- MIO

Note:
    
    - FMioConfigFMioSelectFunc

Input:

    - u32 instance_id, MIO    

Return:

    - const FMioConfig *,  NULL


```c
FError FMioSelectFunc(uintptr addr, u32 mio_type);
```
- MIO

Note:
    - Mio

Input:
    - uintptr addr, MIO
    - u32 mio_type, MIO
Return:
    - @return {FError *} 

```c
u32 FMioGetFunc(uintptr addr);
```
- MIO

Note:
    - Mio

Input:
    - uintptr addr, MIO

Return:
    - @return {u32} MIO

```c
u32 FMioGetVersion(uintptr addr);
```
- 

Note:
    - Mio

Input:
    - uintptr addr, MIO

Return:
    - @return {u32} MIO

```c
FError FMioFuncInit(FMioCtrl *instance_p, u32 mio_type)
```
- MIO

Note:
    - MIO

Input:
    - FMioCtrl *instance_p, 
    - u32 mio_type,IIC

Return:
    - @return {u32} 

```c
FError FMioFuncDeinit(FMioCtrl *instance_p)
```

- MIO

Note:
    - MIO

Input:
    - FMioCtrl *instance_p, 

Return:
    - @return {u32} 

```c
uintptr FMioFuncGetAddress(FMioCtrl *instance_p,u32 mio_type);
```
- 

Note:
    - ,

Input:
    - FMioCtrl *instance_p, 
    - u32 mio_type, UARTI2c

Return:
    - @return {uintptr} 

```c
u32 FMioFuncGetIrqNum(FMioCtrl *instance_p,u32 mio_type);
```
- 

Note:
    - ,

Input:
    - FMioCtrl *instance_p, 
    - u32 mio_type, UARTI2c

Return:
    - @return {u32} 