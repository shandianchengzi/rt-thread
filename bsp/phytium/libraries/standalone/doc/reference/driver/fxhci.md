# FXHCI 

## 1. 

XHCIUSBUSB 3.0USB 2.0USB(USB 3.0 SuperSpeed, USB 2.0 Low-, Full-, and High-speed, USB 1.1 Low- and Full-speed)UHCI/OHCI/EHCI

XHCI,

1. (Host Configuration Space)

- xHCPCIPCIPCIxHC

2. (MMIO Space)

- xHCxHCIUSBI/OI/O(MMIO)

3. (Host Memory)

- xHC

## 2. 

- 

```
drivers/usb/fxhci
 fxhci.c
 fxhci.h
 fxhci_cmd.c
 fxhci_debug.c
 fxhci_dev.c
 fxhci_evt.c
 fxhci_hw.c
 fxhci_hw.h
 fxhci_private.h
 fxhci_roothub.c
```

## 3. 

- 1.  PCIe ,  XHCI 
- 2.  PCIe  XHCI  FPCIE  PCIe 
- 3.  FUSB  FUSB  FXHCI 
- 4.  FUSB 
- 5.  FUSB   

## 4 

- USBUSB
### [fxhci_host_pcie](../../../baremetal/example/peripheral/usb/fxhci_host_pcie)

- USB
### [fusb_fatfs](../../../baremetal/example/storage/fusb_fatfs)

## 5. API

### 5.1. 



### 5.2  

- [1] FXHCI_CC_SUCCESS : success
- [-65] FXHCI_CC_TIMEOUT : wait transfer timeout
- [-66] FXHCI_CC_CONTROLLER_ERROR : usb controller in wrong state
- [-67] FXHCI_CC_COMMUNICATION_ERROR : communication error
- [-68] FXHCI_CC_OUT_OF_MEMORY : memory used up
- [-69] FXHCI_CC_DRIVER_ERROR : driver in wrong state
- [-1] FXHCI_CC_GENERAL_ERROR : general error
- [0] FXHCI_CC_ZERO_BYTES : failed, transfer zero bytes

>XHCI
- [5] FXHCI_CC_TRB_ERROR : TRB error (XHCI spec.)
- [6] FXHCI_CC_STALL_ERROR : stall error (XHCI spec.)
- [7] FXHCI_CC_RESOURCE_ERROR : resource error (XHCI spec.)
- [8] FXHCI_CC_BANDWIDTH_ERROR : bandwidth error (XHCI spec.)
- [9] FXHCI_CC_NO_SLOTS_AVAILABLE : No available slot error (XHCI spec.)
- [13] FXHCI_CC_SHORT_PACKET : short packet error (XHCI spec.)
- [21] FXHCI_CC_EVENT_RING_FULL_ERROR : event ring full error (XHCI spec.)
- [24] FXHCI_CC_COMMAND_RING_STOPPED : command ring stopped error (XHCI spec.)
- [25] FXHCI_CC_STOPPED : command abort error (XHCI spec.)
- [26] FXHCI_CC_TRB_ERROR : stopped error (XHCI spec.)
- [27] FXHCI_CC_STOPPED_LENGTH_INVALID : stopped invalid length error (XHCI spec.)

### 5.3. API

#### FXhciHcInit

```c
FUsbHc *FXhciHcInit (FUsb *instance, uintptr base_addr)
```

Note:

- XHCI USB 

Input:

- {FUsb} *instance, USB
- {uintptr} base_addr, XHCI

Return:

- {FUsbHc *} XHCIUSB
