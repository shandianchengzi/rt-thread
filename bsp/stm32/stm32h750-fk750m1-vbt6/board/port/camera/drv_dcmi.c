/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2023-03-24     spaceman          the first version
 */

#include "board.h"
#include "drv_dcmi.h"

#ifdef BSP_USING_DCMI

#define DRV_DEBUG
#define LOG_TAG "drv.dcmi"
#include <drv_log.h>

static struct stm32_dcmi rt_dcmi_dev = {0};
static volatile uint8_t ov2640_fps; // 


static void rt_hw_dmci_dma_init(struct stm32_dcmi *dcmi_dev)
{
    RT_ASSERT(dcmi_dev != RT_NULL);
    DCMI_HandleTypeDef *_dcmi_handle = &dcmi_dev->dcmi_handle;
    DMA_HandleTypeDef *_dma_handle = &dcmi_dev->dma_handle;
    RT_ASSERT(_dcmi_handle != RT_NULL);
    RT_ASSERT(_dma_handle != RT_NULL);

    __HAL_RCC_DMA2_CLK_ENABLE(); // DMA2

    _dma_handle->Instance                 = DMA2_Stream7;            // DMA27
    _dma_handle->Init.Request             = DMA_REQUEST_DCMI;        // DMADCMI
    _dma_handle->Init.Direction           = DMA_PERIPH_TO_MEMORY;    // 
    _dma_handle->Init.PeriphInc           = DMA_PINC_DISABLE;        // 
    _dma_handle->Init.MemInc              = DMA_MINC_ENABLE;         // 
    _dma_handle->Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;     // DCMI32
    _dma_handle->Init.MemDataAlignment    = DMA_MDATAALIGN_WORD;     // 32
    _dma_handle->Init.Mode                = DMA_CIRCULAR;            // 
    _dma_handle->Init.Priority            = DMA_PRIORITY_LOW;        // 
    _dma_handle->Init.FIFOMode            = DMA_FIFOMODE_ENABLE;     // fifo
    _dma_handle->Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL; // fifo4*32bit
    _dma_handle->Init.MemBurst            = DMA_MBURST_SINGLE;       // 
    _dma_handle->Init.PeriphBurst         = DMA_PBURST_SINGLE;       // 

    if (HAL_DMA_Init(_dma_handle) != HAL_OK) {
        Error_Handler();
    }
    HAL_DMA_Init(_dma_handle);                      // DMA
    __HAL_LINKDMA(_dcmi_handle, DMA_Handle, *_dma_handle);  // DCMI
    HAL_NVIC_SetPriority(DMA2_Stream7_IRQn, 0, 0); // 
    HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);         // 
}

static rt_err_t rt_hw_dcmi_init(struct stm32_dcmi *dcmi_dev)
{
    RT_ASSERT(dcmi_dev != RT_NULL);
    DCMI_HandleTypeDef *_dcmi_handle = &dcmi_dev->dcmi_handle;
    RT_ASSERT(_dcmi_handle != RT_NULL);

    _dcmi_handle->Instance              = DCMI;
    _dcmi_handle->Init.SynchroMode      = DCMI_SYNCHRO_HARDWARE;   // VSHS
    _dcmi_handle->Init.PCKPolarity      = DCMI_PCKPOLARITY_RISING; // 
    _dcmi_handle->Init.VSPolarity       = DCMI_VSPOLARITY_LOW;     // VS
    _dcmi_handle->Init.HSPolarity       = DCMI_HSPOLARITY_LOW;     // HS
    _dcmi_handle->Init.CaptureRate      = DCMI_CR_ALL_FRAME;       // 
    _dcmi_handle->Init.ExtendedDataMode = DCMI_EXTEND_DATA_8B;     // 8
    _dcmi_handle->Init.JPEGMode         = DCMI_JPEG_DISABLE;       // JPEG
    _dcmi_handle->Init.ByteSelectMode   = DCMI_BSM_ALL;            // DCMI
    _dcmi_handle->Init.ByteSelectStart  = DCMI_OEBS_ODD;           //  / 
    _dcmi_handle->Init.LineSelectMode   = DCMI_LSM_ALL;            // 
    _dcmi_handle->Init.LineSelectStart  = DCMI_OELS_ODD;           // ,
    if (HAL_DCMI_Init(_dcmi_handle) != HAL_OK) {
        LOG_E("dcmi init error!");
        return -RT_ERROR;
    }

    HAL_NVIC_SetPriority(DCMI_IRQn, 0, 5); // 
    HAL_NVIC_EnableIRQ(DCMI_IRQn);         // DCMI

    DCMI->IER = 0x0;

    // JPG
    __HAL_DCMI_ENABLE_IT(_dcmi_handle, DCMI_IT_FRAME);
    __HAL_DCMI_ENABLE(_dcmi_handle);

    rt_hw_dmci_dma_init(dcmi_dev);

    return RT_EOK;
}

/***************************************************************************************************************************************
 *      : ov2640_dcmi_crop
 *
 *    :  displey_xsize displey_ysize - 
 *              sensor_xsizesensor_ysize - 
 *
 *    : DCMI
 *
 *        : 1. 4:3
 *              2. 4 OV2640_Set_Framesize 
 *              3. DCMI4
 *              4. 
 *****************************************************************************************************************************************/
static rt_err_t ov2640_dcmi_crop(struct stm32_dcmi *dcmi_dev, uint16_t displey_xsize, uint16_t displey_ysize, uint16_t sensor_xsize, uint16_t sensor_ysize)
{
    RT_ASSERT(dcmi_dev != RT_NULL);
    DCMI_HandleTypeDef *_dcmi_handle = &dcmi_dev->dcmi_handle;
    RT_ASSERT(_dcmi_handle != RT_NULL);

    uint16_t dcmi_x_offset, dcmi_y_offset; // pclk
    uint16_t dcmi_capcnt;                  // pclk
    uint16_t dcmi_vline;                   // 

    if ((displey_xsize >= sensor_xsize) || (displey_ysize >= sensor_ysize)) {
        LOG_E("actual displayed size (%d, %d) >= camera output size (%d, %d), exit dcmi cropping", displey_xsize, displey_ysize, sensor_xsize, sensor_ysize);
        return -RT_ERROR; // 
    }

    // rgb565
    // 22pclk
    // 0    
    dcmi_x_offset = sensor_xsize - displey_xsize; // sensor_xsize - lcd_xsize/2*2

    // 
    dcmi_y_offset = (sensor_ysize - displey_ysize) / 2 - 1; // 0-1

    // 22pclk2
    // 4
    dcmi_capcnt = displey_xsize * 2 - 1; // 0-1

    dcmi_vline = displey_ysize - 1; // 

    // LOG_D("%d  %d  %d  %d", dcmi_x_offset, dcmi_y_offset, dcmi_capcnt, dcmi_vline);
    HAL_DCMI_ConfigCrop(_dcmi_handle, dcmi_x_offset, dcmi_y_offset, dcmi_capcnt, dcmi_vline); // 
    HAL_DCMI_EnableCrop(_dcmi_handle);                                                        // 

    return RT_EOK;
}

/***************************************************************************************************************************************
 *    : ov2640_dma_transmit_continuous
 *
 *  :  dma_buffer - DMA
 *            dma_buffersize - 32
 *
 *  : DMA
 *
 *      : 1. DCMI
 *            2. OV2640RGB56512
 *            3. DMA32 dma_buffersize 4
 *                240*240  240*240*2 = 115200 
 *                dma_buffersize = 115200 / 4 = 28800 
 *
 *****************************************************************************************************************************************/
static void ov2640_dma_transmit_continuous(struct stm32_dcmi *dcmi_dev, uint32_t dma_buffer, uint32_t dma_buffersize)
{
    RT_ASSERT(dcmi_dev != RT_NULL);
    DCMI_HandleTypeDef *_dcmi_handle = &dcmi_dev->dcmi_handle;
    DMA_HandleTypeDef *_dma_handle = &dcmi_dev->dma_handle;
    RT_ASSERT(_dcmi_handle != RT_NULL);
    RT_ASSERT(_dma_handle != RT_NULL);

    _dma_handle->Init.Mode = DMA_CIRCULAR; // 

    HAL_DMA_Init(_dma_handle); // DMA

    // DCMI,
    HAL_DCMI_Start_DMA(_dcmi_handle, DCMI_MODE_CONTINUOUS, (uint32_t)dma_buffer, dma_buffersize);
}

/***************************************************************************************************************************************
 *    : ov2640_dma_transmit_snapshot
 *
 *  :  dma_buffer - DMA
 *            dma_buffersize - 32
 *
 *  : DMA
 *
 *      : 1. 
 *            2. OV2640RGB56512
 *            3. DMA32 dma_buffersize 4
 *                240*240  240*240*2 = 115200 
 *                dma_buffersize = 115200 / 4 = 28800 
 *            4. DCMI OV2640_DCMI_Resume() DCMI
 *
 *****************************************************************************************************************************************/
static void ov2640_dma_transmit_snapshot(struct stm32_dcmi *dcmi_dev, uint32_t dma_buffer, uint32_t dma_buffersize)
{
    RT_ASSERT(dcmi_dev != RT_NULL);
    DCMI_HandleTypeDef *_dcmi_handle = &dcmi_dev->dcmi_handle;
    DMA_HandleTypeDef *_dma_handle = &dcmi_dev->dma_handle;
    RT_ASSERT(_dcmi_handle != RT_NULL);
    RT_ASSERT(_dma_handle != RT_NULL);

    _dma_handle->Init.Mode = DMA_NORMAL; // 

    HAL_DMA_Init(_dma_handle); // DMA

    HAL_DCMI_Start_DMA(_dcmi_handle, DCMI_MODE_SNAPSHOT, (uint32_t)dma_buffer, dma_buffersize);
}

/***************************************************************************************************************************************
 *    : ov2640_dcmi_suspend
 *
 *  : dcmi
 *
 *      : 1. dcmi
 *            2.  ov2640_dcmi_resume() dcmi
 *            3. dcmidma
 *fanke
 *****************************************************************************************************************************************/
static void ov2640_dcmi_suspend(struct stm32_dcmi *dcmi_dev)
{
    RT_ASSERT(dcmi_dev != RT_NULL);
    DCMI_HandleTypeDef *_dcmi_handle = &dcmi_dev->dcmi_handle;
    RT_ASSERT(_dcmi_handle != RT_NULL);

    HAL_DCMI_Suspend(_dcmi_handle); // dcmi
}

/***************************************************************************************************************************************
 *    : ov2640_dcmi_resume
 *
 *  : dcmi
 *
 *      : 1. dcmi
 *            2.  ov2640_dma_transmit_snapshot() dcmi
 *               dcmi
 *
 *****************************************************************************************************************************************/
static void ov2640_dcmi_resume(struct stm32_dcmi *dcmi_dev)
{
    RT_ASSERT(dcmi_dev != RT_NULL);
    DCMI_HandleTypeDef *_dcmi_handle = &dcmi_dev->dcmi_handle;
    RT_ASSERT(_dcmi_handle != RT_NULL);

    _dcmi_handle->State = HAL_DCMI_STATE_BUSY;     // dcmi
    _dcmi_handle->Instance->CR |= DCMI_CR_CAPTURE; // dcmi
}

/***************************************************************************************************************************************
 *    : ov2640_dcmi_stop
 *
 *  : dcmidmadcmidcmi
 *
 *****************************************************************************************************************************************/
static void ov2640_dcmi_stop(struct stm32_dcmi *dcmi_dev)
{
    RT_ASSERT(dcmi_dev != RT_NULL);
    DCMI_HandleTypeDef *_dcmi_handle = &dcmi_dev->dcmi_handle;
    RT_ASSERT(_dcmi_handle != RT_NULL);

    HAL_DCMI_Stop(_dcmi_handle);
}

void DCMI_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    HAL_DCMI_IRQHandler(&rt_dcmi_dev.dcmi_handle);

    /* leave interrupt */
    rt_interrupt_leave();
}

void DMA2_Stream7_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    HAL_DMA_IRQHandler(&rt_dcmi_dev.dma_handle);

    /* leave interrupt */
    rt_interrupt_leave();
}

/* Capture a frame of the image */
void HAL_DCMI_FrameEventCallback(DCMI_HandleTypeDef *hdcmi)
{
    /* enter interrupt */
    rt_interrupt_enter();

    static uint32_t dcmi_tick       = 0;   // 
    static uint8_t dcmi_frame_count = 0;   // 
    if (HAL_GetTick() - dcmi_tick >= 1000) //  1s 
    {
        dcmi_tick        = HAL_GetTick();    // 
        ov2640_fps       = dcmi_frame_count; // fps
        dcmi_frame_count = 0;                // 0
    }
    dcmi_frame_count++; // +1

    rt_sem_release(&rt_dcmi_dev.cam_semaphore);
    /* leave interrupt */
    rt_interrupt_leave();
}

void HAL_DCMI_ErrorCallback(DCMI_HandleTypeDef *hdcmi)
{
    /* enter interrupt */
    rt_interrupt_enter();

    if (HAL_DCMI_GetError(hdcmi) == HAL_DCMI_ERROR_OVR) {
        LOG_E("FIFO overflow error");
    }
    LOG_E("error:0x%08x", HAL_DCMI_GetError(hdcmi));

    /* leave interrupt */
    rt_interrupt_leave();
}

static rt_err_t rt_dcmi_init(rt_device_t dev)
{
    RT_ASSERT(dev != RT_NULL);
    rt_err_t result = RT_EOK;
    struct stm32_dcmi *_rt_dcmi_dev = DCMI_DEVICE(dev);

    result = rt_hw_dcmi_init(_rt_dcmi_dev);
    if (result != RT_EOK) {
        return result;
    }

    return result;
}

static rt_err_t rt_dcmi_open(rt_device_t dev, rt_uint16_t oflag)
{
    RT_ASSERT(dev != RT_NULL);

    return RT_EOK;
}

static rt_err_t rt_dcmi_close(rt_device_t dev)
{
    RT_ASSERT(dev != RT_NULL);

    return RT_EOK;
}

static rt_err_t rt_dcmi_control(rt_device_t dev, int cmd, void *args)
{
    RT_ASSERT(dev != RT_NULL);
    struct stm32_dcmi *_rt_dcmi_dev = DCMI_DEVICE(dev);

    switch (cmd) {
        case DCMI_CTRL_CROP: {
            RT_ASSERT(args != RT_NULL);
            struct stm32_dcmi_cropsize* cropsize = (struct stm32_dcmi_cropsize*)args;
            ov2640_dcmi_crop(_rt_dcmi_dev, cropsize->displey_xsize, cropsize->displey_ysize, cropsize->sensor_xsize, cropsize->sensor_ysize);
        } break;
        case DCMI_CTRL_TRANSMIT_CONTINUOUS: {
            RT_ASSERT(args != RT_NULL);
            struct stm32_dcmi_dma_transmitbuffer* transmitbuffer = (struct stm32_dcmi_dma_transmitbuffer*)args;
            ov2640_dma_transmit_continuous(_rt_dcmi_dev, transmitbuffer->dma_buffer, transmitbuffer->dma_buffersize);
        } break;
        case DCMI_CTRL_TRANSMIT_SNAPSHOT: {
            RT_ASSERT(args != RT_NULL);
            struct stm32_dcmi_dma_transmitbuffer* transmitbuffer = (struct stm32_dcmi_dma_transmitbuffer*)args;
            ov2640_dma_transmit_snapshot(_rt_dcmi_dev, transmitbuffer->dma_buffer, transmitbuffer->dma_buffersize);
        } break;
        case DCMI_CTRL_SUSPEND: {
            ov2640_dcmi_suspend(_rt_dcmi_dev);
        } break;
        case DCMI_CTRL_RESUME: {
            ov2640_dcmi_resume(_rt_dcmi_dev);
        } break;
        case DCMI_CTRL_STOP: {
            ov2640_dcmi_stop(_rt_dcmi_dev);
        } break;
        case DCMI_CTRL_GET_FPS: {
            *(uint8_t*)args = ov2640_fps;
        } break;

        default:
            return -RT_EINVAL;
    }

    return RT_EOK;
}

static rt_ssize_t rt_dcmi_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    return RT_EOK;
}

static rt_ssize_t rt_dcmi_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    return RT_EOK;
}

#ifdef RT_USING_DEVICE_OPS
const static struct rt_device_ops dcmi_ops =
{
    rt_dcmi_init,
    rt_dcmi_open,
    rt_dcmi_close,
    rt_dcmi_read,
    rt_dcmi_write,
    rt_dcmi_control,
};
#endif

int dcmi_init(void)
{
    int ret              = 0;
    rt_device_t device = &rt_dcmi_dev.parent;

    /* memset rt_dcmi_dev to zero */
    memset(&rt_dcmi_dev, 0x00, sizeof(rt_dcmi_dev));

    /* init cam_semaphore semaphore */
    ret = rt_sem_init(&rt_dcmi_dev.cam_semaphore, "cam_sem", 0, RT_IPC_FLAG_FIFO);
    if (ret != RT_EOK) {
        LOG_E("init semaphore failed!\n");
        ret = -RT_ENOMEM;
        goto __exit;
    }

    device->type      = RT_Device_Class_Miscellaneous;
#ifdef RT_USING_DEVICE_OPS
    device->ops = &dcmi_ops;
#else
    device->init      = rt_dcmi_init;
    device->open      = rt_dcmi_open;
    device->close     = rt_dcmi_close;
    device->read      = rt_dcmi_read;
    device->write     = rt_dcmi_write;
    device->control   = rt_dcmi_control;
#endif
    device->user_data = RT_NULL;

    ret = rt_device_register(device, "dcmi", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE);
    if (ret != RT_EOK) {
        LOG_E("dcmi registered fail!\n\r");
        return -RT_ERROR;
    }

    LOG_I("dcmi init success!");

    return RT_EOK;
__exit:
    if (ret != RT_EOK) {
        rt_sem_delete(&rt_dcmi_dev.cam_semaphore);
    }
    return ret;
}
INIT_BOARD_EXPORT(dcmi_init);

#endif /* BSP_USING_DCMI */
