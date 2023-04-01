/*
*******************************************************************************
*                                              usb host module
*
*                             Copyright(C), 2006-2008, SoftWinners Co., Ltd.
*                                                  All Rights Reserved
*
* File Name :
*
* Author : GLHuang(HoLiGun)
*
* Version : 1.0
*
* Date : 2008.05.xx
*
* Description :
*
* History :
********************************************************************************************************************
*/
#ifndef __USB_HOST_COMMON_H__
#define __USB_HOST_COMMON_H__

#include "usb_os_platform.h"
#include "ch9.h"
//#include "sunxi_drv_list.h"
#include <aw_list.h>
#include "usb_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <log.h>
#include <hal_osal.h>

/* This is arbitrary.
 * From USB 2.0 spec Table 11-13, offset 7, a hub can
 * have up to 255 ports. The most yet reported is 10.
 */
#define USB_MAXCHILDREN     (31)

#define USB_MAX_VIRT_SUB_DEV_NR     16      //
//interface


/*
 * timeouts, in milliseconds, used for sending/receiving control messages
 * they typically complete within a few frames (msec) after they're issued
 * USB identifies 5 second timeouts, maybe more in a few cases, and a few
 * slow devices (like some MGE Ellipse UPSes) actually push that limit.
 */
#define USB_CTRL_GET_TIMEOUT    5000
#define USB_CTRL_SET_TIMEOUT    5000


//usb_device_id
struct usb_drv_dev_match_table
{
    /* which fields to match against? */
    uint16_t     match_flags;

    /* Used for product specific matches; range is inclusive */
    uint16_t     idVendor;
    uint16_t     idProduct;
    uint16_t     bcdDevice_lo;
    uint16_t     bcdDevice_hi;

    /* Used for device class matches */
    uint8_t      bDeviceClass;
    uint8_t      bDeviceSubClass;
    uint8_t      bDeviceProtocol;

    /* Used for interface class matches */
    uint8_t      bInterfaceClass;
    uint8_t      bInterfaceSubClass;
    uint8_t      bInterfaceProtocol;

    /* not matched against */
    uint32_t             driver_info;
};

/* Some useful macros to use to create struct usb_device_id */
#define USB_DEVICE_ID_MATCH_VENDOR          0x0001
#define USB_DEVICE_ID_MATCH_PRODUCT         0x0002
#define USB_DEVICE_ID_MATCH_DEV_LO          0x0004
#define USB_DEVICE_ID_MATCH_DEV_HI          0x0008
#define USB_DEVICE_ID_MATCH_DEV_CLASS       0x0010
#define USB_DEVICE_ID_MATCH_DEV_SUBCLASS    0x0020
#define USB_DEVICE_ID_MATCH_DEV_PROTOCOL    0x0040
#define USB_DEVICE_ID_MATCH_INT_CLASS       0x0080
#define USB_DEVICE_ID_MATCH_INT_SUBCLASS    0x0100
#define USB_DEVICE_ID_MATCH_INT_PROTOCOL    0x0200

#define USB_DEVICE_ID_MATCH_INT_INFO \
    (USB_DEVICE_ID_MATCH_INT_CLASS | USB_DEVICE_ID_MATCH_INT_SUBCLASS | USB_DEVICE_ID_MATCH_INT_PROTOCOL)
#define USB_DEVICE_ID_MATCH_DEVICE \
            (USB_DEVICE_ID_MATCH_VENDOR | USB_DEVICE_ID_MATCH_PRODUCT)


struct usb_host_virt_dev;

/* usbepusbep */
struct usb_host_virt_endpoint
{
    struct usb_endpoint_descriptor  desc;
    // struct usb_list_head urb_list;
    struct list_head urb_list;
    void *hcpriv;   //hcprivepep_priv
    unsigned char *extra;   /* Extra descriptors */
    int extralen;
};

/* USB device number allocation bitmap */
struct usb_devmap
{
    uint32_t devicemap[128 / (8 * sizeof(unsigned long))];
};

struct usb_host_func_drv;

/*  */
struct usb_virt_bus
{
    struct usb_list_head  dev_list;     //list
    struct usb_list_head  drv_list;     //list

    struct hc_gen_dev *point_gen_hcd;   //hc_gen_dev

    int busnum;                     /* bus */
    const char *bus_name;           /* bus"usb_bus" */
    uint8_t otg_port;                    /* otg */

    uint8_t is_b_host;               /* true during some HNP roleswitches  */
    uint8_t b_hnp_enable;            /* OTG: did A-Host enable HNP */

    uint32_t devnum_next;            /* dev */

    struct usb_devmap devmap;   /* bitmap */

    struct usb_host_virt_dev *root_hub; /* root hub */

    void *hcpriv;               /* usb_hcd,hc_gen_dev */

    unsigned resuming_ports;    /* bit array: resuming root-hub ports */

    int32_t bandwidth_allocated;

    int32_t bandwidth_int_reqs;     /* number of Interrupt requests */
    int32_t bandwidth_isoc_reqs;    /* number of Isoc. requests */

    int32_t(*bus_match)(struct usb_host_virt_dev *dev, struct usb_host_func_drv *drv);
    int32_t(*bus_hotplug)(struct usb_host_virt_dev *dev, char *buffer, int buffer_size);
    int32_t(*bus_suspend)(struct usb_host_virt_dev *dev);
    int32_t(*bus_resume)(struct usb_host_virt_dev *dev);

    hal_sem_t BusLock;
    // USB_OS_KERNEL_EVENT *BusLock;
    //struct metux bus_metux;
};

/* usb_host_virt_devusb_interface
 * usb_set_configuration()
 *
 * lun
 */
struct usb_host_virt_sub_dev
{
    struct usb_host_func_drv *func_drv;     //
    //USB_OS_KERNEL_EVENT    *usb_virt_sub_dev_semi;
    hal_sem_t    usb_virt_sub_dev_semi;

    struct usb_host_virt_dev *father_dev;       //father
    struct usb_interface *sub_dev_interface;        //interface

    void *drv_pirv_data;                        //
};

/*  */
struct usb_host_virt_dev
{
    struct usb_host_virt_sub_dev virt_sub_dev_array[USB_MAX_VIRT_SUB_DEV_NR];

    //USB_OS_KERNEL_EVENT    *usb_virt_dev_semi;
    hal_sem_t    usb_virt_dev_semi;

    int devnum;                     /* Address on USB bus */
    enum usb_device_state   state;  /* state,configured, not attached */
    enum usb_device_speed   speed;  /*  */
    int     ttport;                 /* device port on that tt hub  */

    unsigned int toggle[2];         /* eptoggle */
    /* one bit for each endpoint ([0] = IN, [1] = OUT) */

    struct usb_host_virt_dev *parent;   /* hub, root hub  */
    struct usb_virt_bus *bus;           /*  */
    uint32_t  hub_port;                    /* hunport */

    struct usb_device_descriptor descriptor;    /*  */
    struct usb_host_virt_config *config;        /*  */
    struct usb_host_virt_config *actconfig;     /*  */

    struct usb_host_virt_endpoint ep0;
    struct usb_host_virt_endpoint *ep_in[16];   /* ep */
    struct usb_host_virt_endpoint *ep_out[16];  /* ep */

    u8 **rawdescriptors;    /* config(),  */
    int have_langid;        /* whether string_langid is valid yet */
    int string_langid;      /* language ID for strings  */
    char *manufacturer;     /*  */
    char *product;          /*  */
    char *serial;           /*  */

    int maxchild;       /* hubport  */
    struct usb_host_virt_dev *children[USB_MAXCHILDREN];
};


struct usb_host_func_drv_ext
{
    int32_t (*probe_ext)(struct usb_host_virt_sub_dev *dev);    //usb_host_func_drv{}probeextend
    //_usb_core_func_drv_probe_interface()
    int32_t (*disconnect_ext)(struct usb_host_virt_sub_dev *dev);   /* drv */
};

#define USB_HOST_FUNC_DRV_PROBE_SUCCESS    0x11
#define USB_HOST_FUNC_DRV_PROBE_FAIL       0x22

/* usb */
struct usb_host_func_drv
{
    struct usb_list_head  virt_dev_list;  /* virt_dev */
    const char *func_drv_name;                  //
    const char *func_drv_auther;      /*    */

    int32_t(*probe)(struct usb_interface *intf, const struct usb_drv_dev_match_table *id);
    void (*disconnect)(struct usb_interface *intf);     //unmatch
    int(*ioctl)(struct usb_interface *intf, unsigned int code, void *buf);
    int32_t(*suspend)(struct usb_interface *intf);
    int(*resume)(struct usb_interface *intf);

    const struct usb_drv_dev_match_table *match_table;  //

    //===========================================================
    //==usb corefunc drv===
    //===========================================================
    struct usb_host_func_drv_ext  func_drv_ext;
};



/*
 * urb->transfer_flags:
 */
#define URB_SHORT_NOT_OK    0x0001  /* report short reads as errors */
#define URB_ISO_ASAP        0x0002  /* iso-only, urb->start_frame ignored */
#define URB_NO_TRANSFER_DMA_MAP 0x0004  /* urb->transfer_dma valid on submit */
#define URB_NO_SETUP_DMA_MAP    0x0008  /* urb->setup_dma valid on submit */
#define URB_ASYNC_UNLINK    0x0010  /* usb_unlink_urb() returns asap */
#define URB_NO_FSBR     0x0020  /* UHCI-specific */
#define URB_ZERO_PACKET     0x0040  /* Finish bulk OUTs with short packet */
#define URB_NO_INTERRUPT    0x0080  /* HINT: no non-error interrupt needed */


struct usb_iso_packet_descriptor
{
    unsigned int offset;
    unsigned int length;        /* expected length */
    unsigned int actual_length;
    int status;
};

typedef struct urb URB;

typedef void (*usb_complete_t)(URB *my_urb);

struct urb
{
    hal_spinlock_t lock_urb;                     // lock for the URB
    //USB_OS_KERNEL_SOFT_TIMER *wait_urb_timer;   //urbtimerout timer
    osal_timer_t wait_urb_timer;
    void *hcpriv;                               //hcd
    int32_t bandwidth;                              //bandwidth for INT/ISO request
    uint32_t use_count;                              //concurrent submissions counter
    uint8_t reject;                                  //submissions will fail
    int unlinked;                               //unlink error code

    struct usb_host_virt_dev *dev;              //dev

    uint32_t pipe;                                   //devpipe
    int32_t status;                                 //(return) non-ISO status
    uint32_t transfer_flags;                         // (in) URB_SHORT_NOT_OK | ...

    struct usb_host_virt_endpoint *ep;      /* (internal) pointer to endpoint */
    void *transfer_buffer;                      //data buff

    unsigned long transfer_dma;                           //dma addr,0
    int32_t transfer_buffer_length;                 //
    int32_t actual_length;                          //actual transfer length

    uint8_t *setup_packet;                           //setup packet (control only)
    unsigned long setup_dma;                              //dma addr for setup_packet, 0
    int32_t start_frame;                            //start frame (ISO)
    int32_t number_of_packets;                      //number of ISO packets */
    int32_t interval;                               //transfer interval (INT/ISO)
    int32_t error_count;                            //number of ISO errors
    void *context;                              //context for completion, USB_OS_KERNEL_EVENT
    usb_complete_t complete;                    //completion routine

    //struct usb_iso_packet_descriptor iso_frame_desc[0];   //ISO ONLY
    // struct usb_list_head *wrapper_urb;              //wrapper
    struct list_head urb_list;              //wrapper

    uint32_t urb_sn;                                 //urb sn ,just for debug

    uint32_t is_busy;                                /* flag. urbhcd, urb dequeue */
    uint32_t need_dispose;                           /* flag. urbhcd, urb dequeue */
    struct usb_iso_packet_descriptor iso_frame_desc[0];
};

/**
 * usb_fill_control_urb - initializes a control urb
 * @urb: pointer to the urb to initialize.
 * @dev: pointer to the struct usb_device for this urb.
 * @pipe: the endpoint pipe
 * @setup_packet: pointer to the setup_packet buffer
 * @transfer_buffer: pointer to the transfer buffer
 * @buffer_length: length of the transfer buffer
 * @complete: pointer to the usb_complete_t function
 * @context: what to set the urb context to.
 *
 * Initializes a control urb with the proper information needed to submit
 * it to a device.
 */
static inline void usb_fill_control_urb(struct urb *urb,
                                        struct usb_host_virt_dev *dev,
                                        unsigned int pipe,
                                        unsigned char *setup_packet,
                                        void *transfer_buffer,
                                        int buffer_length,
                                        usb_complete_t complete,
                                        void *context)
{
    urb->lock_urb               = 0;
    urb->dev                    = dev;
    urb->pipe                   = pipe;
    urb->setup_packet           = setup_packet;
    urb->transfer_buffer        = transfer_buffer;
    urb->transfer_buffer_length = buffer_length;
    urb->complete               = complete;
    urb->context                = context;
}

/**
 * usb_fill_bulk_urb - macro to help initialize a bulk urb
 * @urb: pointer to the urb to initialize.
 * @dev: pointer to the struct usb_device for this urb.
 * @pipe: the endpoint pipe
 * @transfer_buffer: pointer to the transfer buffer
 * @buffer_length: length of the transfer buffer
 * @complete: pointer to the usb_complete_t function
 * @context: what to set the urb context to.
 *
 * Initializes a bulk urb with the proper information needed to submit it
 * to a device.
 */
static void usb_fill_bulk_urb(struct urb *urb,
                              struct usb_host_virt_dev *dev,
                              unsigned int pipe,
                              void *transfer_buffer,
                              int buffer_length,
                              usb_complete_t complete,
                              void *context)
{
    uint32_t cpu_sr = 0;
    //USB_OS_ENTER_CRITICAL(cpu_sr);
    urb->lock_urb               = 0;
    urb->dev                    = dev;
    urb->pipe                   = pipe;
    urb->transfer_buffer        = transfer_buffer;
    urb->transfer_buffer_length = buffer_length;
    urb->complete               = complete;
    urb->context                = context;
    //USB_OS_EXIT_CRITICAL(cpu_sr);
}

/**
 * usb_fill_int_urb - macro to help initialize a interrupt urb
 * @urb: pointer to the urb to initialize.
 * @dev: pointer to the struct usb_device for this urb.
 * @pipe: the endpoint pipe
 * @transfer_buffer: pointer to the transfer buffer
 * @buffer_length: length of the transfer buffer
 * @complete: pointer to the usb_complete_t function
 * @context: what to set the urb context to.
 * @interval: what to set the urb interval to, encoded like
 *  the endpoint descriptor's bInterval value.
 *
 * Initializes a interrupt urb with the proper information needed to submit
 * it to a device.
 * Note that high speed interrupt endpoints use a logarithmic encoding of
 * the endpoint interval, and express polling intervals in microframes
 * (eight per millisecond) rather than in frames (one per millisecond).
 */
static inline void usb_fill_int_urb(struct urb *urb,
                                    struct usb_host_virt_dev *dev,
                                    unsigned int pipe,
                                    void *transfer_buffer,
                                    int buffer_length,
                                    usb_complete_t complete,
                                    void *context,
                                    int interval)
{
    urb->lock_urb               = 0;
    urb->dev                    = dev;
    urb->pipe                   = pipe;
    urb->transfer_buffer        = transfer_buffer;
    urb->transfer_buffer_length = buffer_length;
    urb->complete               = complete;
    urb->context                = context;

    if (dev->speed == USB_SPEED_HIGH)
    {
        urb->interval = 1 << (interval - 1);
    }
    else
    {
        urb->interval = interval;
    }

    urb->start_frame = -1;
}


/* this maximum is arbitrary */
//#define USB_MAXINTERFACES 32
#define USB_MAXINTERFACES   16

/* hostconfig */
struct usb_host_virt_config
{
    struct usb_config_descriptor desc;      //config desc 

    char *string;

    /* the interfaces associated with this configuration,
     * stored in no particular order */
    struct usb_interface *interfac[USB_MAXINTERFACES];  //set configdesc

    /* Interface information available even when this is not the
     * active configuration */
    struct usb_interface_cache *intf_cache[USB_MAXINTERFACES];  //interface
    unsigned char *extra;
    int extralen;
};



/* host-side wrapper for one interface setting's parsed descriptors */
struct usb_host_virt_interface
{
    struct usb_interface_descriptor desc;

    /* array of desc.bNumEndpoint endpoints associated with this
     * interface setting.  these will be in no particular order.
     */
    struct usb_host_virt_endpoint *endpoint;    //desc.bNumEndpoint

    char *string;               /* iInterface string, if present */
    unsigned char *extra;       /* Extra descriptors */
    int extralen;
};


enum usb_interface_condition
{
    USB_INTERFACE_UNBOUND = 0,
    USB_INTERFACE_BINDING,
    USB_INTERFACE_BOUND,
    USB_INTERFACE_UNBINDING
};

/* interfaceinterfacedevice */
struct usb_interface
{
    struct usb_host_virt_sub_dev *virt_sub_dev;     //virt_sub_dev

    /* array of alternate settings for this interface,
     * stored in no particular order */
    struct usb_host_virt_interface *altsetting;     //usb_interface_cache->
    struct usb_host_virt_interface *cur_altsetting; // the currently active alternate setting
    uint32_t num_altsetting; /* number of alternate settings */
    int32_t minor;              /* minor number this interface is bound to */
    enum usb_interface_condition condition;     /* state of binding */

};




/**
 * struct usb_interface_cache - long-term representation of a device interface
 * @num_altsetting: number of altsettings defined.
 * @ref: reference counter.
 * @altsetting: variable-length array of interface structures, one for
 *  each alternate setting that may be selected.  Each one includes a
 *  set of endpoint configurations.  They will be in no particular order.
 *
 * These structures persist for the lifetime of a usb_device, unlike
 * struct usb_interface (which persists only as long as its configuration
 * is installed).  The altsetting arrays can be accessed through these
 * structures at any time, permitting comparison of configurations and
 * providing support for the /proc/bus/usb/devices pseudo-file.
 */
//interface,AlternateSetting
struct usb_interface_cache
{
    uint8_t num_altsetting;  //number of alternate settings
    struct usb_host_virt_interface *altsetting_array;   //usb_host_virt_interface[],
};

/* -------------------------------------------------------------------------- */

/*
 * For various legacy reasons, Linux has a small cookie that's paired with
 * a struct usb_device to identify an endpoint queue.  Queue characteristics
 * are defined by the endpoint's descriptor.  This cookie is called a "pipe",
 * an unsigned int encoded as:
 *
 *  - direction:    bit 7       (0 = Host-to-Device [Out],
 *                   1 = Device-to-Host [In] ...
 *                  like endpoint bEndpointAddress)
 *  - device address:   bits 8-14       ... bit positions known to uhci-hcd
 *  - endpoint:     bits 15-18      ... bit positions known to uhci-hcd
 *  - pipe type:    bits 30-31  (00 = isochronous, 01 = interrupt,
 *                   10 = control, 11 = bulk)
 *
 * Given the device address and endpoint descriptor, pipes are redundant.
 */

/* NOTE:  these are not the standard USB_ENDPOINT_XFER_* values!! */
/* (yet ... they're the values used by usbfs) */
#define PIPE_ISOCHRONOUS        0u
#define PIPE_INTERRUPT          1u
#define PIPE_CONTROL            2u
#define PIPE_BULK               3u

#define usb_pipein(pipe)        ((pipe) & USB_DIR_IN)
#define usb_pipeout(pipe)       (!usb_pipein(pipe))

#define usb_pipedevice(pipe)    (((pipe) >> 8) & 0x7f)
#define usb_pipeendpoint(pipe)  (((pipe) >> 15) & 0xf)

#define usb_pipetype(pipe)      (((pipe) >> 30) & 3)

#define usb_pipeisoc(pipe)      (usb_pipetype((pipe)) == PIPE_ISOCHRONOUS)
#define usb_pipeint(pipe)       (usb_pipetype((pipe)) == PIPE_INTERRUPT)
#define usb_pipecontrol(pipe)   (usb_pipetype((pipe)) == PIPE_CONTROL)
#define usb_pipebulk(pipe)      (usb_pipetype((pipe)) == PIPE_BULK)

/* The D0/D1 toggle bits ... USE WITH CAUTION (they're almost hcd-internal) */
#define usb_gettoggle(dev, ep, out)         (((dev)->toggle[out] >> (ep)) & 1)
#define usb_dotoggle(dev, ep, out)          ((dev)->toggle[out] ^= (1 << (ep)))
#define usb_settoggle(dev, ep, out, bit)    ((dev)->toggle[out] = ((dev)->toggle[out] & ~(1 << (ep))) | ((bit) << (ep)))


static inline unsigned int __create_pipe(struct usb_host_virt_dev *dev, unsigned int endpoint)
{
    return (dev->devnum << 8) | (endpoint << 15);
}

/* Create various pipes... */
#define usb_sndctrlpipe(dev,endpoint)   ((PIPE_CONTROL << 30) | __create_pipe(dev,endpoint))
#define usb_rcvctrlpipe(dev,endpoint)   ((PIPE_CONTROL << 30) | __create_pipe(dev,endpoint) | USB_DIR_IN)
#define usb_sndisocpipe(dev,endpoint)   ((PIPE_ISOCHRONOUS << 30) | __create_pipe(dev,endpoint))
#define usb_rcvisocpipe(dev,endpoint)   ((PIPE_ISOCHRONOUS << 30) | __create_pipe(dev,endpoint) | USB_DIR_IN)
#define usb_sndbulkpipe(dev,endpoint)   ((PIPE_BULK << 30) | __create_pipe(dev,endpoint))
#define usb_rcvbulkpipe(dev,endpoint)   ((PIPE_BULK << 30) | __create_pipe(dev,endpoint) | USB_DIR_IN)
#define usb_sndintpipe(dev,endpoint)    ((PIPE_INTERRUPT << 30) | __create_pipe(dev,endpoint))
#define usb_rcvintpipe(dev,endpoint)    ((PIPE_INTERRUPT << 30) | __create_pipe(dev,endpoint) | USB_DIR_IN)



static uint16_t usb_maxpacket(struct usb_host_virt_dev *udev, int pipe, int is_out)
{
    struct usb_host_virt_endpoint   *ep;
    unsigned            epnum = usb_pipeendpoint(pipe);

    if (is_out)
    {
        ep = udev->ep_out[epnum];
    }
    else
    {
        ep = udev->ep_in[epnum];
    }

    if (!ep)
    {
        __err("PANIC : usb_maxpacket() not found ep\n");
        return 0;
    }

    /* NOTE:  only 0x07ff bits are for packet size... */
    return le16_to_cpu(ep->desc.wMaxPacketSize);
}


#endif




