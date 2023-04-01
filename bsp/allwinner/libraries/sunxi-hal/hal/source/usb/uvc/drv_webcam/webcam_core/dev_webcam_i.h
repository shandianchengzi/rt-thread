/*
*********************************************************************************************************
*                                                    MELIS
*                                    the Easy Portable/Player Develop Kits
*                                                 WEBCAM Driver
*
*                                    (c) Copyright 2012-2016, Kingvan.Tong China
*                                             All Rights Reserved
*
* File    : drv_webcam.h
* By      : Kingvan
* Version : v1.0
* Date    : 2012-9-27
* Descript:
* Update  : date                auther         ver     notes
*           2012-9-27 11:09:13  Kingvan.Tong   2.0     build the file.
*********************************************************************************************************
*/
#ifndef _DEV_WEBCAM_I_H_
#define _DEV_WEBCAM_I_H_
#include "hal_sem.h"
#include "sunxi_hal_common.h"
#include "webcam_linklist_manager.h"

typedef enum capture_state_e
{
    CAPTURE_NONE  = 0,
    CAPTURE_ON,
    CAPTURE_ON_AND_CALLBACK,
    CAPTURE_REMOVE,
}capture_state;

typedef struct STRUCT_WEBCAM_DEV
{
    hal_sem_t webcam_lock;    ///WEBCAM_DEVsemaphore

    __s32                       webcam_frame_num;  //webcam_frame, <= WEBCAM_BUFFER_NUM
    __webcam_frame_t            webcam_frame[WEBCAM_BUFFER_NUM];
    __webcam_frame_t            *p_webcam_frame[WEBCAM_BUFFER_NUM];
    __s32                       frame_id_last;//index
    __s32                       frame_id_last_b;//
    __webcam_linklist_manager_t *full2; //,
    __webcam_linklist_manager_t *free2;
    __s32                       diftion;
    __s64                       pts;  //PTS
    __u32                       pts_flag; //PTSaux = 0:CSIPTS; 1:PTS; 2.PTS
    __pCBK_t                    CB_GetPts;

    __webcam_mode_t             webcam_mode_last;//

    capture_state               capture;
    transport_cb_t              tran_cb;
    uvc_irq_t                   irq_cb;
    __u32                       used_addr0;
    __u32                       used_addr1;

}__webcam_dev_t;

#endif  /* _DEV_WEBCAM_I_H_ */

