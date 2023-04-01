/*
********************************************************************************
*                                    eMOD
*                   the Easy Portable/Player Develop Kits
*                               mod_duckweed sub-system
*                          (module name, e.g.mpeg4 decoder plug-in) module
*
*          (c) Copyright 2010-2012, Allwinner Microelectronic Co., Ltd.
*                              All Rights Reserved
*
* File   : webcam_linklist_manager.h
* Version: V1.0
* By     : Eric_wang
* Date   : 2010-1-4
* Description:
********************************************************************************
*/
#ifndef _WEBCAM_LINKLIST_MANAGER_H_
#define _WEBCAM_LINKLIST_MANAGER_H_
#include "typedef.h"
#include "drv_webcam.h"

//2
/*******************************************************************************
 2 :
(1). vdrv_task() webcam_irq_handle()2full2free2
     
(2). ISRvdrv_task()
    full2_insert( isr ), wt
    full2_delete( vdrv_task ), rd
    free2_insert( vdrv_task ), wt
    free2_delete( isr ), rd

    full2_delete()free2_insert()
    
*******************************************************************************/

#define FRMID_CNT (WEBCAM_BUFFER_NUM+1)

typedef enum{
    WEBCAM_LISTTYPE_FREE = 0,
    WEBCAM_LISTTYPE_FULL = 1,
} WEBCAM_LINKLIST_TYPE;
typedef struct tag_WEBCAM_LINKLIST_MANAGER __webcam_linklist_manager_t;
typedef void    (*WEBCAM_LINKLIST_MANAGER_Initial)     (__webcam_linklist_manager_t *thiz, WEBCAM_LINKLIST_TYPE type);
typedef __s32   (*WEBCAM_LINKLIST_MANAGER_Insert)      (__webcam_linklist_manager_t *thiz, __s32 frame_id);
typedef __s32   (*WEBCAM_LINKLIST_MANAGER_Delete)      (__webcam_linklist_manager_t *thiz);
typedef __s32   (*WEBCAM_LINKLIST_MANAGER_Exit)        (__webcam_linklist_manager_t *thiz);
typedef struct tag_WEBCAM_LINKLIST_MANAGER
{
    WEBCAM_LINKLIST_TYPE list_type;
    __s32 frmid_array[FRMID_CNT];  //index,  index__webcam_frame_t webcam_frame[WEBCAM_BUFFER_NUM]index
    __s32 wt;
    __s32 rd;
    WEBCAM_LINKLIST_MANAGER_Initial    initial;
    WEBCAM_LINKLIST_MANAGER_Insert     insert_element;
    WEBCAM_LINKLIST_MANAGER_Delete     delete_element;
    WEBCAM_LINKLIST_MANAGER_Exit       exit;
} __webcam_linklist_manager_t; //WEBCAM_BUFFER_NUMwt,rd().
extern __webcam_linklist_manager_t* webcam_linklist_manager_init(void);

#endif  /* _WEBCAM_LINKLIST_MANAGER_H_ */

