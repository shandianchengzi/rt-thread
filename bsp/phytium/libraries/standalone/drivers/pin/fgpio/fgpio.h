/*
 * Copyright: (C)2022PhytiumInformationTechnology,Inc.
 * All Rights Reserved.
 *
 * This program is OPEN SOURCE software: you can redistribute it and/or modify it
 * under the terms of the Phytium Public License as published by the Phytium Technology Co.,Ltd,
 * either version 1.0 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the Phytium Public License for more details.
 *
 *
 * FilePath: fgpio.h
 * Date: 2022-02-10 14:53:42
 * LastEditTime: 2022-02-18 08:25:35
 * Description: This files is for GPIO user API definition
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   zhugengyu  2022-3-1     init commit
 */


#ifndef  DRIVERS_FGPIO_H
#define  DRIVERS_FGPIO_H

#ifdef __cplusplus
extern "C"
{
#endif

/***************************** Include Files *********************************/
#include "ftypes.h"
#include "fassert.h"
#include "ferror_code.h"
#include "sdkconfig.h"

/************************** Constant Definitions *****************************/
#define FGPIO_SUCCESS            FT_SUCCESS
#define FGPIO_ERR_INVALID_PARA   FT_MAKE_ERRCODE(ErrModBsp, ErrBspGpio, 0x0)
#define FGPIO_ERR_INVALID_STATE  FT_MAKE_ERRCODE(ErrModBsp, ErrBspGpio, 0x1)
#define FGPIO_ERR_NOT_INIT       FT_MAKE_ERRCODE(ErrModBsp, ErrBspGpio, 0x2)
#define FGPIO_ERR_ALREADY_INIT   FT_MAKE_ERRCODE(ErrModBsp, ErrBspGpio, 0x3)

#if defined(CONFIG_TARGET_F2000_4) || defined(CONFIG_TARGET_D2000)
#define FGPIO_VERSION_1 /* FT2000/4D2000GPIO 0 ~ 1 */
#elif defined(CONFIG_TARGET_E2000)
#define FGPIO_VERSION_2 /* E2000GPIO 3 ~ 5 */
#else
#error "Invalid target board !!!"
#endif

typedef enum
{
    FGPIO_PORT_A = 0,
#if defined(FGPIO_VERSION_1) /* FT2000-4, D2000 */
    FGPIO_PORT_B,
#endif

    FGPIO_PORT_NUM
} FGpioPortIndex; /* GPIO */

typedef enum
{
    FGPIO_PIN_0 = 0,
    FGPIO_PIN_1,
    FGPIO_PIN_2,
    FGPIO_PIN_3,
    FGPIO_PIN_4,
    FGPIO_PIN_5,
    FGPIO_PIN_6,
    FGPIO_PIN_7,
#if defined(FGPIO_VERSION_2) /* E2000 GPIO 0 ~ 5 */
    FGPIO_PIN_8,
    FGPIO_PIN_9,
    FGPIO_PIN_10,
    FGPIO_PIN_11,
    FGPIO_PIN_12,
    FGPIO_PIN_13,
    FGPIO_PIN_14,
    FGPIO_PIN_15,
#endif

    FGPIO_PIN_NUM
} FGpioPinIndex; /* GPIO */

#if defined(FGPIO_VERSION_1) /* FT2000-4, D2000 */
FASSERT_STATIC(8 == FGPIO_PIN_NUM); /* pin 0 ~ 7 */
FASSERT_STATIC(2 == FGPIO_PORT_NUM); /* port a/b */
#elif defined(FGPIO_VERSION_2) /* E2000 GPIO 0 ~ 5 */
FASSERT_STATIC(16 == FGPIO_PIN_NUM); /* pin 0 ~ 15 */
FASSERT_STATIC(1 == FGPIO_PORT_NUM); /* port a */
#endif
typedef enum
{
    FGPIO_DIR_INPUT = 0, /*  */
    FGPIO_DIR_OUTPUT /*  */
} FGpioDirection; /* GPIO */

typedef enum
{
    FGPIO_IRQ_TYPE_EDGE_FALLING = 0, /*  */
    FGPIO_IRQ_TYPE_EDGE_RISING, /*  */
    FGPIO_IRQ_TYPE_LEVEL_LOW, /*  */
    FGPIO_IRQ_TYPE_LEVEL_HIGH /*  */
} FGpioIrqType; /* GPIO */

typedef enum
{
    FGPIO_IRQ_NOT_SUPPORT, /*  */
    FGPIO_IRQ_BY_CONTROLLER, /*  */
#if defined(FGPIO_VERSION_2) /* E2000 GPIO 0 ~ 5 */
    FGPIO_IRQ_BY_PIN, /*  */
#endif
} FGpioIrqSourceType;

typedef enum
{
    FGPIO_PIN_LOW = 0, /*  */
    FGPIO_PIN_HIGH /*  */
} FGpioPinVal; /* GPIO */

/**************************** Type Definitions *******************************/
typedef struct _FGpioPin FGpioPin;
typedef struct _FGpio FGpio;

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

typedef struct
{
    u32 ctrl; /* GPIO */
    FGpioPortIndex port; /* GPIO */
    FGpioPinIndex  pin; /* GPIO */
} FGpioPinId; /* GPIO */

typedef void (*FGpioInterruptCallback)(s32 vector, void *param); /* GPIO */

typedef struct _FGpioPin
{
    FGpioPinId index; /*  */
    u32 is_ready;
    FGpio *instance;
    FGpioInterruptCallback irq_cb; /* , Port-A */
    void *irq_cb_params; /* , Port-A */
    boolean irq_one_time; /* Port-A, TRUE:  */
} FGpioPin; /* GPIO */

typedef struct _FGpio
{
    FGpioConfig config;
    u32 is_ready;
    FGpioPin *pins[FGPIO_PORT_NUM][FGPIO_PIN_NUM];
} FGpio; /* GPIO */

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
/* GPIO */
#define FGPIO_PIN(port, pin)   \
    (FGpioPinId) { \
        (port), (pin) \
    }

/************************** Function Prototypes ******************************/
/* GPIO */
const FGpioConfig *FGpioLookupConfig(u32 instance_id);

/* GPIO */
FError FGpioCfgInitialize(FGpio *const instance, const FGpioConfig *const config);

/* GPIO */
FError FGpioPinInitialize(FGpio *const instance, FGpioPin *const pin,
                          const FGpioPinId pin_id);

/* GPIO */
void FGpioPinDeInitialize(FGpioPin *const pin);

/*  */
FGpioIrqSourceType FGpioGetPinIrqSourceType(FGpioPinId pin_id);

/* GPIO */
void FGpioDeInitialize(FGpio *const instance);

/* GPIO */
void FGpioSetDirection(FGpioPin *const pin, FGpioDirection dir);

/* GPIO */
FGpioDirection FGpioGetDirection(FGpioPin *const pin);

/* GPIO */
FError FGpioSetOutputValue(FGpioPin *const pin, const FGpioPinVal output);

/* GPIO */
FGpioPinVal FGpioGetInputValue(FGpioPin *const pin);

/* GPIO A */
void FGpioGetInterruptMask(FGpio *const instance, u32 *mask, u32 *enabled);

/* GPIO A */
void FGpioSetInterruptMask(FGpioPin *const pin, boolean enable);

/* GPIO A */
void FGpioGetInterruptType(FGpio *const instance, u32 *levels, u32 *polarity);

/* GPIO A */
void FGpioSetInterruptType(FGpioPin *const pin, const FGpioIrqType type);

/* GPIO */
void FGpioInterruptHandler(s32 vector, void *param);

#if defined(FGPIO_VERSION_2) /* E2000 GPIO 0 ~ 2 */
/* GPIO */
void FGpioPinInterruptHandler(s32 vector, void *param);
#endif

/* GPIO A */
void FGpioRegisterInterruptCB(FGpioPin *const pin, FGpioInterruptCallback cb,
                              void *cb_param, boolean irq_one_time);

/* GPIO */
void FGpioDumpRegisters(uintptr base_addr);

#ifdef __cplusplus
}
#endif

#endif
