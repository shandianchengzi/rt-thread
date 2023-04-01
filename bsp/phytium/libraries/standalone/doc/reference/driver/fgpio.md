# FGPIO 

## 1. 

- GPIO(General-purpose input/output)

- FT2000/4D2000 GPIO  GPIO  16 8ABGPIOIO

- FGPIO  GPIO 

- FGPIO_VERSION_1  FT2000/4D2000  GPIOFGPIO_VERSION_2  E2000 GPIO

## 2. 

- FGPIO GPIO

- 1. GPIO 
- 2. GPIO 
- 3. GPIO 
- 4. GPIO 
- 5. GPIO 
- 6. GPIO 

- 
- drivers/pin/fgpio
```
.
 Kconfig
 fgpio.c
 fgpio.h
 fgpio_g.c
 fgpio_hw.h
 fgpio_selftest.c
 fgpio_intr.c
 fgpio_sinit.c
```

## 3. 

- FGPIO  FT2000/4, D2000E2000 D2000  E2000 

-  FGPIO 
- 1. FT2000/4, D2000E2000 GPIO
- 2.  GPIO 
- 3.  GPIO 
- 4.  GPIO  GPIO 
- 5.  GPIO 

## 4 

-  GPIO  GPIO 

### [fgpio_irq](../../../baremetal/example/peripheral/pin/fgpio_irq)

-  GPIO  PWM 

### [fgpio_soft_pwm](../../../baremetal/example/peripheral/pin/fgpio_soft_pwm)

## 5. API

### 5.1. 

#### FGpioConfig

```c
typedef struct
{
    u32 instance_id; /* GPIOID */
    uintptr base_addr; /* GPIO */
#if defined(FGPIO_VERSION_1) /* FT2000-4, D2000 */
    u32 irq_num; /* GPIO */
#elif defined(FGPIO_VERSION_2) /* E2000 GPIO 0 ~ 5 */
    u32 irq_num[FGPIO_PIN_NUM]; /* GPIO */
#endif
    u32 irq_priority; /*  */
} FGpioConfig; /* GPIO */
```

#### FGpioPin

```c
typedef struct _FGpioPin
{
    FGpioPinId index; /*  */
    u32 is_ready;
    FGpio *instance;
    FGpioInterruptCallback irq_cb; /* , Port-A */
    void *irq_cb_params; /* , Port-A */
    boolean irq_one_time; /* Port-A, TRUE:  */
} FGpioPin; /* GPIO */
```

#### FGpio

```c
typedef struct _FGpio
{
    FGpioConfig config;
    u32 is_ready;
    FGpioPin *pins[FGPIO_PORT_NUM][FGPIO_PIN_NUM];
} FGpio; /* GPIO */
```
### 5.2  

- [0x0] FGPIO_SUCCESS : success

- [0x1050000] FGPIO_ERR_INVALID_PARA : invalid input parameters

- [0x1050001] FGPIO_ERR_INVALID_STATE : invalid state


### 5.3 API

#### FGpioLookupConfig

```c
const FGpioConfig *FGpioLookupConfig(u32 instance_id);
```

Note:

- GPIO

Input:

-  {u32} instance_id, GPIO

Return:

- {const FGpioConfig *} GPIO

#### FGpioCfgInitialize

```c
FError FGpioCfgInitialize(FGpio *const instance, const FGpioConfig *const config);
```

Note:

- GPIO

Input:

- {FGpio} *instance, GPIO
- {FGpioConfig} *config, GPIO

Return:

- {FError} FGPIO_SUCCESS 

#### FGpioDeInitialize

```c
void FGpioDeInitialize(FGpio *const instance);
```

Note:

- GPIO

Input:

- {FGpio} *instance, GPIO

Return:

- 

#### FGpioPinInitialize

```c
FError FGpioPinInitialize(FGpio *const instance, FGpioPin *const pin,
                          const FGpioPinId pin_id);
```

Note:

- GPIO

Input:

- {FGpio} *instance, GPIO
- {FGpioPin} *pin_instance, GPIO
- {FGpioPinId} index, GPIO

Return:

- {FError} FGPIO_SUCCESS 

#### FGpioPinDeInitialize

```c
void FGpioPinDeInitialize(FGpioPin *const pin);
```

Note:

- GPIO

Input:

- {FGpioPin} *pin_instance, GPIO

Return:

- {FError} FGPIO_SUCCESS 

#### FGpioGetPinIrqSourceType

```c
FGpioIrqSourceType FGpioGetPinIrqSourceType(FGpioPin *const pin);
```

Note:

- 

Input:

- {FGpioPin} *pin_instance, GPIO

Return:

- {FGpioIrqSourceType} 

#### FGpioSetDirection

```c
void FGpioSetDirection(FGpioPin *const pin, FGpioDirection dir);
```

Note:

- GPIO
-  GPIO 

Input:

- @param {FGpioPin} *instance, GPIO
- @param {FGpioDirection} dir, GPIO

Return:

- 

#### FGpioGetDirection

```c
FGpioDirection FGpioGetDirection(FGpioPin *const pin);
```

Note:

- GPIO
-  GPIO 

Input:

- {FGpioPin} *pin, GPIO

Return:

- {FGpioDirection} GPIO

#### FGpioSetOutputValue

```c
FError FGpioSetOutputValue(FGpioPin *const pin, const FGpioPinVal output);
```

Note:

- GPIO
-  GPIO  GPIO 

Input:

- {FGpioPin} *pin, GPIO
- {FGpioPinVal} output, GPIO

Return:

- {FError} FGPIO_SUCCESS 

#### FGpioGetInputValue

- GPIO

```c
FGpioPinVal FGpioGetInputValue(FGpioPin *const pin);
```

Note:

-  GPIO  GPIO 

Input:

- {FGpioPin} *instance, GPIO
- {FGpioPinVal} output, GPIO

Return:

- {FGpioPinVal} /

#### FGpioGetInterruptMask

- GPIO A 

```c
void FGpioGetInterruptMask(FGpio *const instance, u32 *mask, u32 *enabled)
```

Note:

- APin

Input:

- {FGpio} *instance, GPIO
- {u32} *mask, GPIO A
- {u32} *enabled, GPIO A

Return:

- 
#### FGpioSetInterruptMask

- GPIO A

```c
void FGpioSetInterruptMask(FGpioPin *const pin, boolean enable);
```

Note:

- indexAB

Input:

- {FGpioPin} *pin, GPIO
- {boolean} enable, TRUEGPIOFALSEGPIO

Return:

- 
#### FGpioGetInterruptType

- GPIO A

```c
void FGpioGetInterruptType(FGpio *const instance, u32 *levels, u32 *polarity)
```

Note:

- APin

Input:

- {FGpio} *instance, GPIO
- {u32} *levels, GPIO A
- {u32} *polarity, GPIO A

Return:

- 

#### FGpioSetInterruptType

- GPIO

```c
void FGpioSetInterruptType(FGpioPin *const pin, const FGpioIrqType type)
```

Note:

- indexAB

Input:

- {FGpioPin} *pin, GPIO
- {FGpioIrqType} type, GPIO

Return:

- 

#### FGpioInterruptHandler

- GPIO

```c
void FGpioInterruptHandler(s32 vector, void *param)
```

Note:

- InterrtupGPIO

Input:

- {s32} vector, 1
- {void} *param, 2

Return:

- 


#### FGpioPinInterruptHandler

- GPIO

```c
void FGpioPinInterruptHandler(s32 vector, void *param)
```

Note:

- Gic

Input:

- {s32} vector, 1
- {void} *param, 2

Return:

- 

#### FGpioRegisterInterruptCB

- GPIO

```c
void FGpioRegisterInterruptCB(FGpioPin *const pin, FGpioInterruptCallback cb, void *cb_param, boolean irq_one_time)
```

Note:

- `FGpioInterruptHandler`

Input:

- {FGpioPin} pin, GPIO
- {FGpioInterruptCallback} cb, GPIO
- {void} *cb_param, GPIO
- {boolean} irq_one_time, TRUE

Return:

- 
