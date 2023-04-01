# 

## 1. 

-  (Pin Ctrl) IO  IO 
- FPinCtrl  FT2000/4D2000  E2000

## 2. 

- FPinCtrl 
- 1. 
- 2. E2000
- 3. 
- 4. 

- 
```
fpinctrl.h
    fiopad.h  --> E2000
    fiopad.c

    fioctrl.h --> FT2000/4, D2000
    fioctrl.c
```

## 3. 

- 

## 4. 

- 

### [fpin_test](../../../baremetal/example/peripheral/pin/fioctrl_test)

- IO  D2000/FT2000-4 " 5-32  IO 

>  FIOCTRL_INDEX PADe.g.

|     |  |   |
| -------- | ------- | ------- |
|0x0208  |  [27 : 26] |  i2c_0_scl_pad  2'b10 |
|        |  [25 : 24] |  i2c_0_scl_pad  2'b00 |

```c
    #define FIOCTRL_I2C0_SCL_PAD        (FPinIndex)FIOCTRL_INDEX(0x208, 24) /* i2c0-scl: func 0 */
```
>  i2c0_scl_pad PAD0x208, 24

## 5. API

Note:

- FT2000/4  D2000 FIOCTRL_INDEX  index 
- E2000  FIOPAD_INDEX  index 

#### FPinGetFunc

```c
FPinFunc FPinGetFunc(const FPinIndex pin);
```

Note:

- IO

Input:

- {FPinIndex} pin IO

Return:

- {FPinFunc} 

#### FPinSetFunc

```c
void FPinSetFunc(const FPinIndex pin, FPinFunc func);
```

Note:

- IO

Input:

- {FPinIndex} pin IO
- {FPinFunc} func IO

Return:

- 

#### FPinGetPull

```c
FPinPull FPinGetPull(const FPinIndex pin);
```

Note:

- IO

Input:

- {FPinIndex} pin IO

Return:

- {FPinPull} 

#### FPinSetPull

```c
void FPinSetPull(const FPinIndex pin, FPinPull pull);
```

Note:

- IO

Input:

- {FPinIndex} pin IO
- {FPinPull} pull 

Return:

- 

#### FPinGetDelay

```c
FPinDelay FPinGetDelay(const FPinIndex pin, FPinDelayDir dir, FPinDelayType type);
```

Note:

- IO

Input:

- {FPinIndex} pin IO
- {FPinDelayDir} dir /
- {FPinDelayType} type /

Return:

- {FPinDelay} 

#### FPinGetDelayEn

```c
boolean FPinGetDelayEn(const FPinIndex pin, FPinDelayDir dir);
```

Note:

- IO

Input:

- {FPinIndex} pin IO
- {FPinDelayDir} dir /

Return:

- {boolean} TRUE: , FALSE: 

#### FPinSetDelay

```c
void FPinSetDelay(const FPinIndex pin, FPinDelayDir dir, FPinDelayType type, FPinDelay delay);
```

Note:

- IO

Input:

- {FPinIndex} pin IO
- {FPinDelayDir} dir /
- {FPinDelayType} type /
- {FPinDelay} delay 

Return:

- 

#### FPinSetDelayEn

```c
void FPinSetDelayEn(const FPinIndex pin, FPinDelayDir dir, boolean enable);
```

Note:

- /IO

Input:

- {FPinIndex} pin IO
- {FPinDelayDir} dir /
- {boolean} enable TRUE: , FALSE: 

Return:

- 

#### FPinGetDrive

```c
FPinDrive FPinGetDrive(const FPinIndex pin);
```

Note:

- IO
-  E2000 

Input:

- {FPinIndex} pin IO

Return:

- {FPinDrive} 

#### FPinSetDrive

```c
void FPinSetDrive(const FPinIndex pin, FPinDrive drive);
```

Note:

- IO
-  E2000 

Input:

- {FPinIndex} pin, IO
- {FPinDrive} drive, 

Return:

- 

#### 

```c

```

Note:

- 

Input:

- 

Return:

- 