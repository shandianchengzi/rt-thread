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
 * FilePath: fusb_private.h
 * Date: 2022-02-11 13:33:11
 * LastEditTime: 2022-02-18 09:21:22
 * Description: This files is for definition of internal function interface
 *
 * ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.0   Zhugengyu  2022/2/7    init commit
 */

#pragma once

/***************************** Include Files *********************************/
#ifdef __aarch64__
    #include "faarch64.h"
#else
    #include "fcp15.h"
#endif

#include "fkernel.h"
#include "fio.h"
#include "fassert.h"
#include "fusb.h"

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/************************** Variable Definitions *****************************/

/***************** Macros (Inline Functions) Definitions *********************/
#define FUSB_REG32_GET_BITS(x, a, b)                  (u32)((((u32)(x)) & GENMASK(a, b)) >> b)
#define FUSB_REG32_SET_BITS(x, a, b)                  (u32)((((u32)(x)) << b) & GENMASK(a, b))
#define FUSB_REG64_GET_BITS(x, a, b)                  (u64)((((u64)(x)) & GENMASK_ULL(a, b)) >> b)
#define FUSB_REG64_SET_BITS(x, a, b)                  (u64)((((u64)(x)) << b) & GENMASK_ULL(a, b))

/************************** Function Prototypes ******************************/
/* USBUSBHc */
FUsbHc *FUsbAllocateHc(FUsb *instance);

/* USBUSBHc */
void FUsbDetachHc(FUsbHc *controller);

/* USB */
FUsbDev *FUsbInitDevEntry(FUsbHc *controller, int slot_id);

/* USB */
int FUsbDecodeMaxPacketSz0(FUsbSpeed speed, u8 bMaxPacketSize0);

/*  */
int FUsbSpeedtoDefaultMaxPacketSz(FUsbSpeed speed);

/* USB */
FError FUsbSetupConfigParser(FUsbDev *dev, const void *buf, u32 buf_len);

/* USB */
void FUsbRevokeConfigParser(FUsbDev *dev);

/*  */
void FUsbSetupStringParser(FUsbDev *dev);

/*  */
void FUsbRevokeStringParser(FUsbDev *dev);

/* FUsbStringParser */
FError FUsbSearchStringDescriptor(FUsb *instance, FUsbDev *dev, u8 id);

/*  */
const char *FUsbGetString(const FUsbDev *const dev);

/* / */
const FUsbDescriptor *FUsbGetDescriptorFromParser(FUsbConfigParser *parser, FUsbDescriptorType type);

/* USB */
void FUsbNopDevInit(FUsbDev *dev);

/* USB */
void FUsbGenericDevInit(FUsbDev *dev);

/*  */
void FUsbDumpDeviceDescriptor(const FUsbDeviceDescriptor *descriptor);

/*  */
void FUsbDumpConfigDescriptor(const FUsbConfigurationDescriptor *descriptor);

/*  */
void FUsbDumpInterfaceDescriptor(const FUsbInterfaceDescriptor *descriptor);

/*  */
void FUsbDumpEndpointDescriptor(const FUsbEndpointDescriptor *descriptor);