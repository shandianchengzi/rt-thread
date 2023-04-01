/*
*@:Copyright(c)2021PhytiumInformationTechnology,Inc.
*
*SPDX-License-Identifier:Apache-2.0.
*
 * @Date: 2021-04-07 09:53:07
 * @LastEditTime: 2021-05-11 10:18:14
 * @Description: This files is for definition of system-level types
 *
 * @ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#ifndef FT_TYPES_H
#define FT_TYPES_H
#include <stdint.h>
#include <stddef.h>

/*  Constant Definitions */

#ifndef TRUE
#define TRUE 1U
#endif

#ifndef FALSE
#define FALSE 0U
#endif

#ifndef NULL
#define NULL 0U
#endif

#define FT_NULL NULL

#define FT_COMPONENT_IS_READLY 0x11111111U
#define FT_COMPONENT_IS_STARTED 0x22222222U

#define __STATIC_INLINE static inline

#define FT_OUT   /*   */
#define FT_IN    /*  */
#define FT_INOUT /*  */
#define FT_IO volatile

typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;
typedef int ft_base_t;
typedef ft_base_t bool_t;

typedef intptr_t INTPTR;
typedef uintptr_t UINTPTR;
typedef ptrdiff_t PTRDIFF;

#define __STATIC_INLINE static inline
#define LOCAL static

#define LLSB(x) ((x)&0xff) /* 32bit word byte/word swap macros */
#define LNLSB(x) (((x) >> 8) & 0xff)
#define LNMSB(x) (((x) >> 16) & 0xff)
#define LMSB(x) (((x) >> 24) & 0xff)
#define U32SWAP(x) ((LLSB(x) << 24) |  \
                    (LNLSB(x) << 16) | \
                    (LNMSB(x) << 8) |  \
                    (LMSB(x)))

#define FT_SWAP32(x) U32SWAP((u32)x)

#endif //
