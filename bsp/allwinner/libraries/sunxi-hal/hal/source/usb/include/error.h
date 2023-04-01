/*
********************************************************************************************************************
*                                              usb host driver
*
*                              (c) Copyright 2007-2010, javen.China
*                                       All Rights Reserved
*
* File Name     : error.h
*
* Author        : javen
*
* Version       : 2.0
*
* Date          : 2010.03.02
*
* Description   : 
*
* History       :
*
********************************************************************************************************************
*/
#define  USB_ERR_SUCCESS                    0       /*              */
#define  USB_ERR_UNKOWN_ERROR               -1      /*          */

/*  */
#define  USB_ERR_BAD_ARGUMENTS              1       /*          */
#define  USB_ERR_DATA_OVERFLOW              2       /*          */

/*  */
#define  USB_ERR_IO_DEVICE_OFFLINE          500     /*        */
#define  USB_ERR_IO_DEVICE_DIEAD            501     /*        */
#define  USB_ERR_IO_DEVICE_BUSY             502     /*        */
#define  USB_ERR_COMMAND_NEED_RETRY         503     /*      */
#define  USB_ERR_COMMAND_SEND_FAILED        504     /*      */
#define  USB_ERR_COMMAND_EXECUTE_FAILED     505     /*      */
#define  USB_ERR_RESET_POERT_FAILED         506     /* reset    */
#define  USB_ERR_UNKOWN_DEVICE              507     /*          */
#define  USB_ERR_DEVICE_PROBE_FAILED        508     /*    */
#define  USB_ERR_DEVICE_REMOVE_FAILED       509     /*      */

#define  USB_ERR_MEDIA_NOT_PRESENT          510     /*    */
#define  USB_ERR_NOT_SUPPORT_COMMAND        511     /*      */


/*  */
#define  USB_ERR_CREATE_SIME_FAILED         1000    /*    */
#define  USB_ERR_MALLOC_FAILED              1001    /*      */
#define  USB_ERR_CREATE_THREAD_FAILED       1002    /*      */
#define  USB_ERR_REG_BLK_DEV_FAILED         1003    /*    */
#define  USB_ERR_CREATE_TIMER_FAILED        1004    /* timer    */

/* USB */
#define  USB_ERR_ALLOC_URB_FAILED           2000    /* URB      */


