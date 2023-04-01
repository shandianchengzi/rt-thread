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
 * FilePath: ftypes.h
 * Date: 2021-05-27 13:30:03
 * LastEditTime: 2022-02-18 08:24:15
 * Description: This files is for
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */


#ifndef _BSP_COMMON_FT_TYPE_H
#define _BSP_COMMON_FT_TYPE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stddef.h>

#define FT_COMPONENT_IS_READY 0x11111111U
#define FT_COMPONENT_IS_STARTED 0x22222222U

typedef uint8_t u8;            /* unsigned 8-bit */
typedef char s8;               /* signed 8-bit */
typedef uint16_t u16;          /* unsigned 16-bit */
typedef short s16;             /* signed 16-bit */
typedef uint32_t u32;          /* unsigned 32-bit */
typedef int32_t s32;           /* signed 32-bit */
typedef uint64_t u64;          /* unsigned 64-bit */
typedef int64_t s64;           /* unsigned */
typedef float f32;             /* 32-bit floating point */
typedef double f64;            /* 64-bit double precision FP */
typedef unsigned long boolean; /* boolean */
typedef uint64_t _time_t;
typedef size_t fsize_t;

typedef intptr_t intptr; /* intptr_t */
typedef uintptr_t uintptr;
typedef ptrdiff_t ptrdiff;

#ifdef __aarch64__
typedef u64 tick_t;
#else
typedef u32 tick_t;
#endif

/** @}*/
#if !defined(LONG) || !defined(ULONG)
typedef long LONG;
typedef unsigned long ULONG;
#endif

#define ULONG64_HI_MASK 0xFFFFFFFF00000000U
#define ULONG64_LO_MASK ~ULONG64_HI_MASK

#ifndef TRUE
#define TRUE 1U
#endif

#ifndef FALSE
#define FALSE 0U
#endif

#ifndef NULL
#define NULL 0U
#endif

#define _INLINE inline
#define _WEAK __attribute__((weak))

typedef void (*FIrqHandler)(void *InstancePtr);

typedef void (*FExceptionHandler)(void *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif // !
