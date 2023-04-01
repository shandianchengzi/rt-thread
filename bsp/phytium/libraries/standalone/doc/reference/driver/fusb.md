
# FUSB 

## 1. 

USBUniversal Serial Bus, USBPlug and PlayPnPUSBUUSBUSB1.0USB1.1USB2.0USB3.0

USB, USBHost, USB, USBDeviceUUSBUSBUSBUSBUSBUSBUSBHubUSB HubUSB

USBUSBPipeUSBUSBEndpointENDP

USBUSBSetupINOUTUSBTransfer

## 2. 

- 
- drivers/usb
```
.
 Kconfig
 fusb.c
 fusb.h
 fusb_debug.c
 fusb_def.h
 fusb_dev.c
 fusb_g.c
 fusb_generic_hub.c
 fusb_generic_hub.h
 fusb_hid.c
 fusb_hid.h
 fusb_hub.c
 fusb_hub.h
 fusb_msc.c
 fusb_msc.h
 fusb_private.h
 fusb_sinit.c
```

-  [XHCI](./fxhci.md)

## 3. 

 FUSB 

- 1. FUSB E2000 E2000 

 FUSB 

- 1. USB XHCI
- 2.  FUSB 1Mb
- 3. USB
- 4. USBFUSB
- 5. USBFUSBUSB
- 6. USBUSB

## 4 

- USBUSB
### [fxhci_host](../../../baremetal/example/peripheral/usb/fxhci_host)

- USB
### [fusb_fatfs](../../../baremetal/example/storage/fusb_fatfs)

## 5. API

### 5.1. 

#### 5.1.1 USB

```c
typedef struct 
{
	FUsbDev *dev; /* device instance of this endpoint */
	int endpoint; /* endpoint address ep0 = 0, epn = n */
	FUsbDirection direction; /* type or direction of ep */
	int toggle; /* ep state for some device to toggle */
	int maxpacketsize; /* max packet size for ep transfer */
	FUsbEpType type; /* transfer type of ep, control, bulk or so on */
	int interval; /* expressed as binary logarithm of the number
			 		of microframes (i.e. t = 125us * 2^interval) */
} FUsbEndpoint; /* encapsulates a single endpoint of an USB device */
```

#### 5.1.2 USB

```c
typedef struct _FUsbDev
{
	FUsbHc *controller; /* Hc instance where device attached */
	FUsbEndpoint endpoints[FUSB_MAX_EP_NUM]; /* all Ep instance of device */
	int num_endp; /* num of Ep in use */
	FUsbDevAddr address; /* USB address */
	FUsbDevClass class;	/* USB device class, e.g hid */
	int hub; /* hub where device is attached to */
	int port; /* port where device is attached */
	FUsbSpeed speed; /* speed type of device */
	void *data; /* private data for specific type of device */
	FUsbDeviceDescriptor *descriptor; /* device descriptor ever get from device hw */
	FUsbConfigurationDescriptor *configuration; /* configure descriptor followed with interface descriptor ever get from device hw */
	FUsbConfigParser  config_parser; /* parser for configure descriptor */
	FUsbStringParser  string_parser; /* parser for string descriptor */
	void (*init)(FUsbDev *dev); /* device init function of specific device type for register */
	void (*destroy) (FUsbDev *dev); /* device deinit function of specific device type for register */
	void (*poll) (FUsbDev *dev); /* device poll function of specific device type for register */
} FUsbDev; /* encapsulates a single USB device */
```

#### 5.1.3 USB

```c
typedef struct _FUsbHc
{
	FUsbHc *next; /* next Hc instance in the list */
	uintptr reg_base; /* base address of Hc register */
	FUsb *usb; /* instance of USB system */
	FUsbHcType type; /* type of Hc, e.g XHCI */
	FUsbDev *devices[FUSB_MAX_DEV_NUM];	/* dev 0 is root hub, 127 is last addressable */

	/* start():     Resume operation. */
	void (*start) (FUsbHc *controller);
	/* stop():      Stop operation but keep controller initialized. */
	void (*stop) (FUsbHc *controller);
	/* reset():     Perform a controller reset. The controller needs to
	                be (re)initialized afterwards to work (again). */
	void (*reset) (FUsbHc *controller);
	/* init():      Initialize a (previously reset) controller
	                to a working state. */
	void (*init) (FUsbHc *controller);
	/* shutdown():  Stop operation, detach host controller and shutdown
	                this driver instance. After calling shutdown() any
					other usage of this hci_t* is invalid. */
	void (*shutdown) (FUsbHc *controller);

	FUsbTransCode (*bulk) (FUsbEndpoint *ep, int size, u8 *data, int finalize);
	FUsbTransCode (*control) (FUsbDev *dev, FUsbDirection pid, int dr_length,
							  void *devreq, int data_length, u8 *data);
	void* (*create_intr_queue) (FUsbEndpoint *ep, int reqsize, int reqcount, int reqtiming);
	void (*destroy_intr_queue) (FUsbEndpoint *ep, void *queue);
	u8* (*poll_intr_queue) (void *queue);
	void *instance; /* instance to specific Hc implementation, e.g XHCI */

	/* set_address():		Tell the USB device its address (xHCI
					controllers want to do this by
					themselves). Also, allocate the FUsbDev
					structure, initialize enpoint 0
					(including MPS) and return it. */
	FUsbDev *(*set_address) (FUsbHc *controller, FUsbSpeed speed,
				  			 int hubport, int hubaddr);
	/* finish_device_config():	Another hook for xHCI, returns 0 on success. */
	int (*finish_device_config) (FUsbDev *dev);
	/* destroy_device(): Finally, destroy all structures that
						 were allocated during set_address()
						 and finish_device_config(). */
	void (*destroy_device) (FUsbHc *controller, int devaddr);
} FUsbHc; /* encapsulates a single USB host */
```

#### 5.1.4 USB

```c
typedef struct
{
	void *(*malloc_align)(size_t size, size_t align);
	void (*free)(void *mem);
} FUsbMemAllocator; /* memory allocator used in USB system */

typedef struct
{
    u32 instance_id; /* id for this USB system */
    uintptr base_addr; /* base addr of Hc register, set as 0 for pci-usb */
	u32 irq_num;
	u32 irq_priority;
	FUsbMemAllocator allocator; /* memory allocator to support dynamic memory */
} FUsbConfig; /* configure data of the USB system */
```

#### 5.1.4 USB

```c
typedef struct _FUsb
{
    FUsbConfig config; /* configuration of USB system */
    void *pcie_instance; /* NULL if unused */
	void *pcie_info[FUSB_MAX_CTRL_NUM]; /* NULL if unused */
	FUsbHc *hc; /* first hc, there might have multiple hc in pcie-mode */
	/* hook to set init function for specific device type */
	FUsbDevInitFunc dev_init[FUSB_MAX_DEV_TYPE_NUM];
	u32 dev_init_num; /* number of init function in used */
	u32 is_ready; /* indicator of system okay */
} FUsb; /* instance of the USB system */
```

### 5.2  


-  `0x1110000`

- [0x0] FUSB_SUCCESS : success
- [0x1110000] FUSB_ERR_WAIT_TIMEOUT : wait for status timeout
- [0x1110001] FUSB_ERR_INVALID_PARA : invalid input parameters
- [0x1110002] FUSB_ERR_NOT_SUPPORT : parameters or feature not supported
- [0x1110003] FUSB_ERR_NON_INSTANCE : cannot find instance
- [0x1110004] FUSB_ERR_INVALID_DATA : invalid input data
- [0x1110005] FUSB_ERR_DESC_PARSE_ERR : failed to parse descriptor
- [0x1110006] FUSB_ERR_ALLOCATE_FAIL : failed to allocate memory from memory pool
- [0x1110007] FUSB_ERR_TRANS_FAIL : failed to transfer data


- 

- [0] FUSB_CC_ZERO_BYTES : failed, transfer zero bytes
- [1] FUSB_CC_SUCCESS : transfer success with bytes unkonwn

### 5.3. API

#### FUsbLookupConfig

```c
const FUsbConfig *FUsbLookupConfig(u32 instance_id)
```

Note:

- USB

Input:

- {u32} instance_id USB

Return:

- {const FUsbConfig *} USB

#### FUsbCfgInitialize

```c
FError FUsbCfgInitialize(FUsb *instance, const FUsbConfig *input_config)
```

Note:

- USB
- PCIEUSB HcPCIE

Input:

- {FUsb} *instance, USB
- {const FUsbConfig} *input_config, USB

Return:

- {FError} 

#### FUsbDeInitialize

```c
void FUsbDeInitialize(FUsb *instance);
```

Note:

- USB

Input:

- {FUsb} *instance, USB

Return:

- 

#### FUsbPoll

```c
void FUsbPoll(FUsb *instance)
```

Note:

- USB, 

Input:

- {FUsb} *instance, USB

Return:

- 

#### FUsbExit

```c
void FUsbExit(FUsb *instance)
```

Note:

- USB

Input:

- {FUsb} *instance, USB

Return:

- 


#### FUsbAssignDevInitFunc

```c
FError FUsbAssignDevInitFunc(FUsb *instance, const FUsbDevIndex *index, FUsbDevInitHandler handler)
```

Note:

- USBUSB

Input:

- {FUsb} *instance, USB
- {FUsbDevIndex} *index, USB
- {FUsbDevInitHandler} handler, USB

Return:

- {FError} 

#### FUsbGetAllDevEntries

```c
size_t FUsbGetAllDevEntries(FUsbHc *controller, FUsbDev *devs[], size_t max_dev_num)
```

Note:

- USBUSB

Input:

- {FUsbHc} *controller, USB
- {FUsbDev} *devs, USB
- {size_t} max_dev_num, USB

Return:

- {size_t} USB

#### FUsbSetFeature

```c
FUsbTransCode FUsbSetFeature(FUsbDev *dev, int endp, int feature, int rtype)
```

Note:

- USB//

Input:

- {FUsbDev} *dev, USB
- {int} endp, (0x00)//
- {int} feature, 
- {int} rtype, FUsbGenerateReqType

Return:

- {FUsbTransCode} 00

#### FUsbGetStatus

```c
FUsbTransCode FUsbGetStatus(FUsbDev *dev, int intf, int rtype, int len, void *data)
```

Note:

- USB//

Input:

- {FUsbDev} *dev, USB
- {int} intf(0x00)//
- {int} rtype, FUsbGenerateReqType
- {int} len, Data Stage
- {void} *data, Data Stage

Return:

- {FUsbTransCode} 00

#### FUsbGetDescriptor

```c
FUsbTransCode FUsbGetDescriptor(FUsbDev *dev, int rtype, FUsbDescriptorType desc_type, int desc_idx, void *data, size_t len)
```

Note:

- USB

Input:

- {FUsbDev} *dev, USB
- {int} rtype, FUsbGenerateReqType
- {FUsbDescriptorType} desc_type, 
- {int} desc_idx, 
- {void} *data, Data Stage
- {size_t} len, Data Stage

Return:

- {FUsbTransCode} 00

#### FUsbGetStringDescriptor

```c
FUsbTransCode FUsbGetStringDescriptor(FUsbDev *dev, int rtype, FUsbDescriptorType desc_type, int desc_idx, int lang_id, void *data, size_t len)
```

Note:

- USB

Input:

- {FUsbDev} *dev, USB
- {int} rtype, FUsbGenerateReqType
- {int} desc_type, 
- {int} desc_idx, 
- {int} lang_id, 
- {void} *data, Data Stage
- {size_t} len, Data Stage

Return:

- {int} 00

#### FUsbSetConfiguration

```c
FUsbTransCode FUsbSetConfiguration(FUsbDev *dev)
```

Note:

- USB

Input:

- {FUsbDev} *dev, USB

Return:

- {FUsbTransCode} 00

#### FUsbClearFeature

```c
FUsbTransCode FUsbClearFeature(FUsbDev *dev, int endp, int feature, int rtype)
```

Note:

- USB//

Input:

- {FUsbDev} *dev, USB
- {int} endp, (0x00)//
- {int} feature
- {int} rtype, FUsbGenerateReqType

Return:

- {FUsbTransCode} 00

#### FUsbDumpAllDescriptors

```c
void FUsbDumpAllDescriptors(FUsbDev *dev)
```

Note:

- USB

Input:

- {FUsbDev} *dev, USB

Return:

- 

#### FUsbDetachDev

```c
void FUsbDetachDev(FUsbHc *controller, int devno)
```

Note:

- USBUSB(USB)

Input:

- {FUsbHc} *controller, USB
- {int} devno, USB

Return:

- 


#### FUsbAttachDev

```c
FUsbDevAddr FUsbAttachDev(FUsbHc *controller, int hubaddress, int port, FUsbSpeed speed)
```

Note:

- USBUSB(USB)

Input:

- {FUsbHc} *controller, USB
- {int} hubaddress, Hub
- {int} port, Port
- {FUsbSpeed} speed, USB

Return:

- {FUsbDevAddr} USB
