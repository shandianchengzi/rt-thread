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

#ifdef BSP_USING_OV2640

#include <dfs_file.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include "drv_dcmi.h"
#include "drv_ov2640.h"
#include "drv_ov2640_cfg.h"

#define DRV_DEBUG
//#define CAMERA_DUMP
#define LOG_TAG     "drv.ov2640"
#include <drv_log.h>

#define CHIP_ADDRESS    0x30 /* OV2640 address */
// #define CHIP_ADDRESS    0x3C /* OV5640 address */
#define I2C_NAME        "i2c1"
#define PWDN_PIN    GET_PIN(D, 14)

struct rt_i2c_bus_device *i2c_bus  = RT_NULL;

#if defined(CAMERA_DUMP)
#define __is_print(ch) ((unsigned int)((ch) - ' ') < 127u - ' ')
static void dump_hex(const rt_uint8_t *ptr, rt_size_t buflen)
{
    unsigned char *buf = (unsigned char *)ptr;
    int i, j;

    for (i = 0; i < buflen; i += 16)
    {
        rt_kprintf("%08x:", i);

        for (j = 0; j < 16; j++)
        {
            if (i + j < buflen)
            {
                rt_kprintf("%02x", buf[i + j]);
            }
            else
            {
                rt_kprintf(" ");
            }
        }
        rt_kprintf(" ");

        for (j = 0; j < 16; j++)
        {
            if (i + j < buflen)
            {
                rt_kprintf("%c", __is_print(buf[i + j]) ? buf[i + j] : '.');
            }
        }
        rt_kprintf("\n");
    }
}
#endif

/* i2c read reg */
static rt_err_t read_reg(struct rt_i2c_bus_device *bus, rt_uint8_t reg, rt_uint8_t len, rt_uint8_t *buf)
{
    struct rt_i2c_msg msg[2] = {0, 0};

    RT_ASSERT(bus != RT_NULL);

    msg[0].addr  = CHIP_ADDRESS;
    msg[0].flags = RT_I2C_WR;
    msg[0].buf   = &reg;
    msg[0].len   = 1;

    msg[1].addr  = CHIP_ADDRESS;
    msg[1].flags = RT_I2C_RD;
    msg[1].len   = len;
    msg[1].buf   = buf;

    if (rt_i2c_transfer(bus, msg, 2) == 2)
    {
        return RT_EOK;
    }

    return -RT_ERROR;
}

/* i2c write reg */
static rt_err_t write_reg(struct rt_i2c_bus_device *bus, rt_uint8_t reg, rt_uint8_t data)
{
    rt_uint8_t buf[2];
    struct rt_i2c_msg msgs;

    RT_ASSERT(bus != RT_NULL);

    buf[0] = reg;
    buf[1] = data;

    msgs.addr = CHIP_ADDRESS;
    msgs.flags = RT_I2C_WR;
    msgs.buf = buf;
    msgs.len = 2;

    if (rt_i2c_transfer(bus, &msgs, 1) == 1)
    {
        return RT_EOK;
    }

    return -RT_ERROR;
}

static rt_err_t ov2640_read_id(struct rt_i2c_bus_device *bus, rt_uint16_t *id)
{
    rt_uint8_t read_value[2];

    write_reg(bus, OV2640_SEL_Registers, OV2640_SEL_SENSOR); //  SENSOR 

    read_reg(bus, OV2640_SENSOR_PIDH, 1, &read_value[0]); // ID
    read_reg(bus, OV2640_SENSOR_PIDL, 1, &read_value[1]); // ID

    *id = ((rt_uint16_t)(read_value[0] << 8) & 0xFF00);
    *id |= ((rt_uint16_t)(read_value[1]) & 0x00FF);

    if ((*id != OV2640_ID1) && (*id != OV2640_ID2)) {
        LOG_E("ov2640 init error, id: 0x%04x", *id);
        return -RT_ERROR;
    }

    LOG_I("ov2640 init success, id: 0x%04x", *id);

    return RT_EOK;
}

static rt_err_t ov2640_reset(struct rt_i2c_bus_device *bus)
{
    rt_pin_mode(PWDN_PIN, PIN_MODE_OUTPUT);

    rt_thread_mdelay(5);  // 5msPWDN
    rt_pin_write(PWDN_PIN, PIN_LOW);  // PWDN LED

    // OV2640>=3msOV2640RC6ms
    // 
    rt_thread_mdelay(5);

    write_reg(bus, OV2640_SEL_Registers, OV2640_SEL_SENSOR);   //  SENSOR 
    write_reg(bus, OV2640_SENSOR_COM7, 0x80);                  // 

    // OV2640>=2msSCCB10ms
    rt_thread_mdelay(10);
    return RT_EOK;
}

static rt_err_t ov2640_config(struct rt_i2c_bus_device *bus, const rt_uint8_t (*configdata)[2])
{
    rt_uint32_t i    = 0;

    for (i = 0; configdata[i][0]; i++) {
        write_reg(bus, configdata[i][0], configdata[i][1]); // 
    }

    return RT_EOK;
}

void ov2640_set_pixformat(struct rt_i2c_bus_device *bus, rt_uint8_t pixformat)
{
    const rt_uint8_t(*configdata)[2];
    uint32_t i; // 

    switch (pixformat) {
        case Pixformat_RGB565:
            configdata = OV2640_RGB565_Config;
            break;
        case Pixformat_JPEG:
            configdata = OV2640_JPEG_Config;
            break;
        default:
            break;
    }

    for (i = 0; configdata[i][0]; i++) {
        write_reg(bus, configdata[i][0], configdata[i][1]); // 
    }
}

rt_err_t ov2640_set_framesize(struct rt_i2c_bus_device *bus, rt_uint16_t width, rt_uint16_t height)
{
    if ((width % 4) || (height % 4)) // 4
    {
        return -RT_ERROR; // 
    }

    write_reg(bus, OV2640_SEL_Registers,OV2640_SEL_DSP); //  dsp

    write_reg(bus, 0x5a, width / 4 & 0xff);                                   // outw7~0 bit/4
    write_reg(bus, 0x5b, height / 4 & 0xff);                                  // outh7~0 bit/4
    write_reg(bus, 0x5c, (width / 4 >> 8 & 0x03) | (height / 4 >> 6 & 0x04)); // zmhhbit[2:0]outh  8 bitoutw  9~8 bit

    write_reg(bus, OV2640_DSP_RESET, 0x00); // 

    return RT_EOK; // 
}

rt_err_t ov2640_set_horizontal_mirror(struct rt_i2c_bus_device *bus, rt_uint8_t configstate)
{
    rt_uint8_t ov2640_reg; // 

    write_reg(bus, OV2640_SEL_Registers, OV2640_SEL_SENSOR); //  sensor 
    read_reg(bus, OV2640_SENSOR_REG04, 1, &ov2640_reg);      //  0x04 

    // reg04,4 0x04bit[7]
    if (configstate == OV2640_Enable) // 
    {
        ov2640_reg |= 0x80; // bit[7]1
    } else                  // 
    {
        ov2640_reg &= ~0x80; // bit[7]0
    }
    return write_reg(bus, OV2640_SENSOR_REG04, ov2640_reg); // 
}

rt_err_t ov2640_set_vertical_flip(struct rt_i2c_bus_device *bus, rt_uint8_t configstate)
{
    rt_uint8_t ov2640_reg; // 

    write_reg(bus, OV2640_SEL_Registers, OV2640_SEL_SENSOR); //  sensor 
    read_reg(bus, OV2640_SENSOR_REG04, 1, &ov2640_reg);      //  0x04 

    // reg04,4 0x04bit[6]
    if (configstate == OV2640_Enable) {
        // openmv
        // bit[4]1
        ov2640_reg |= 0x40 | 0x10; // bit[6]1
    } else                         // 
    {
        ov2640_reg &= ~(0x40 | 0x10); // bit[6]bit[4]0
    }
    return write_reg(bus, OV2640_SENSOR_REG04, ov2640_reg); // 
}

void ov2640_set_saturation(struct rt_i2c_bus_device *bus, rt_int8_t saturation)
{
    write_reg(bus, OV2640_SEL_Registers, OV2640_SEL_DSP); //  dsp

    switch (saturation) {
        case 2:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x02);
            write_reg(bus, OV2640_DSP_BPADDR, 0x03);
            write_reg(bus, OV2640_DSP_BPDATA, 0x68);
            write_reg(bus, OV2640_DSP_BPDATA, 0x68);
            break;

        case 1:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x02);
            write_reg(bus, OV2640_DSP_BPADDR, 0x03);
            write_reg(bus, OV2640_DSP_BPDATA, 0x58);
            write_reg(bus, OV2640_DSP_BPDATA, 0x58);
            break;

        case 0:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x02);
            write_reg(bus, OV2640_DSP_BPADDR, 0x03);
            write_reg(bus, OV2640_DSP_BPDATA, 0x48);
            write_reg(bus, OV2640_DSP_BPDATA, 0x48);
            break;

        case -1:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x02);
            write_reg(bus, OV2640_DSP_BPADDR, 0x03);
            write_reg(bus, OV2640_DSP_BPDATA, 0x38);
            write_reg(bus, OV2640_DSP_BPDATA, 0x38);
            break;

        case -2:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x02);
            write_reg(bus, OV2640_DSP_BPADDR, 0x03);
            write_reg(bus, OV2640_DSP_BPDATA, 0x28);
            write_reg(bus, OV2640_DSP_BPDATA, 0x28);
            break;

        default:
            break;
    }
}

void ov2640_set_brightness(struct rt_i2c_bus_device *bus, rt_int8_t brightness)
{
    write_reg(bus, OV2640_SEL_Registers, OV2640_SEL_DSP); //  dsp

    switch (brightness) {
        case 2:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x09);
            write_reg(bus, OV2640_DSP_BPDATA, 0x40);
            write_reg(bus, OV2640_DSP_BPDATA, 0x00);
            break;

        case 1:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x09);
            write_reg(bus, OV2640_DSP_BPDATA, 0x30);
            write_reg(bus, OV2640_DSP_BPDATA, 0x00);
            break;

        case 0:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x09);
            write_reg(bus, OV2640_DSP_BPDATA, 0x20);
            write_reg(bus, OV2640_DSP_BPDATA, 0x00);
            break;

        case -1:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x09);
            write_reg(bus, OV2640_DSP_BPDATA, 0x10);
            write_reg(bus, OV2640_DSP_BPDATA, 0x00);
            break;

        case -2:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x09);
            write_reg(bus, OV2640_DSP_BPDATA, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x00);
            break;

        default:
            break;
    }
}

void ov2640_set_contrast(struct rt_i2c_bus_device *bus, rt_int8_t contrast)
{
    write_reg(bus, OV2640_SEL_Registers, OV2640_SEL_DSP); //  dsp

    switch (contrast) {
        case 2:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x07);
            write_reg(bus, OV2640_DSP_BPDATA, 0x20);
            write_reg(bus, OV2640_DSP_BPADDR, 0x28);
            write_reg(bus, OV2640_DSP_BPDATA, 0x0c);
            write_reg(bus, OV2640_DSP_BPDATA, 0x06);
            break;

        case 1:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x07);
            write_reg(bus, OV2640_DSP_BPDATA, 0x20);
            write_reg(bus, OV2640_DSP_BPADDR, 0x24);
            write_reg(bus, OV2640_DSP_BPDATA, 0x16);
            write_reg(bus, OV2640_DSP_BPDATA, 0x06);
            break;

        case 0:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x07);
            write_reg(bus, OV2640_DSP_BPDATA, 0x20);
            write_reg(bus, OV2640_DSP_BPADDR, 0x20);
            write_reg(bus, OV2640_DSP_BPDATA, 0x20);
            write_reg(bus, OV2640_DSP_BPDATA, 0x06);
            break;

        case -1:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x07);
            write_reg(bus, OV2640_DSP_BPDATA, 0x20);
            write_reg(bus, OV2640_DSP_BPADDR, 0x1c);
            write_reg(bus, OV2640_DSP_BPDATA, 0x2a);
            write_reg(bus, OV2640_DSP_BPDATA, 0x06);
            break;

        case -2:
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x04);
            write_reg(bus, OV2640_DSP_BPADDR, 0x07);
            write_reg(bus, OV2640_DSP_BPDATA, 0x20);
            write_reg(bus, OV2640_DSP_BPADDR, 0x18);
            write_reg(bus, OV2640_DSP_BPDATA, 0x34);
            write_reg(bus, OV2640_DSP_BPDATA, 0x06);
            break;

        default:
            break;
    }
}

void ov2640_set_effect(struct rt_i2c_bus_device *bus, rt_uint8_t effect_mode)
{
    write_reg(bus, OV2640_SEL_Registers, OV2640_SEL_DSP); //  dsp

    switch (effect_mode) {
        case OV2640_Effect_Normal: // 
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x00);
            write_reg(bus, OV2640_DSP_BPADDR, 0x05);
            write_reg(bus, OV2640_DSP_BPDATA, 0x80);
            write_reg(bus, OV2640_DSP_BPDATA, 0x80);
            break;

        case OV2640_Effect_Negative: // 
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x40);
            write_reg(bus, OV2640_DSP_BPADDR, 0x05);
            write_reg(bus, OV2640_DSP_BPDATA, 0x80);
            write_reg(bus, OV2640_DSP_BPDATA, 0x80);
            break;

        case OV2640_Effect_BW: // 
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x18);
            write_reg(bus, OV2640_DSP_BPADDR, 0x05);
            write_reg(bus, OV2640_DSP_BPDATA, 0x80);
            write_reg(bus, OV2640_DSP_BPDATA, 0x80);
            break;

        case OV2640_Effect_BW_Negative: // +
            write_reg(bus, OV2640_DSP_BPADDR, 0x00);
            write_reg(bus, OV2640_DSP_BPDATA, 0x58);
            write_reg(bus, OV2640_DSP_BPADDR, 0x05);
            write_reg(bus, OV2640_DSP_BPDATA, 0x80);
            write_reg(bus, OV2640_DSP_BPDATA, 0x80);
            break;

        default:
            break;
    }
}

int rt_hw_ov2640_init(void)
{
    extern rt_err_t ov2640_dcmi_crop(uint16_t displey_xsize, uint16_t displey_ysize, uint16_t sensor_xsize, uint16_t sensor_ysize);

    static rt_uint16_t id = 0;
    rt_device_t dcmi_dev = RT_NULL;

    i2c_bus = rt_i2c_bus_device_find(I2C_NAME);
    if (i2c_bus == RT_NULL)
    {
        LOG_E("can't find %c deivce", I2C_NAME);
        return -RT_ERROR;
    }

    /* dcmi init */
    dcmi_dev = rt_device_find("dcmi");
    if (dcmi_dev == RT_NULL)
    {
        LOG_E("can't find dcmi device!");
        return -RT_ERROR;
    }
    rt_device_open(dcmi_dev, RT_DEVICE_FLAG_RDWR);

    ov2640_reset(i2c_bus);
    ov2640_read_id(i2c_bus, &id);
    ov2640_config(i2c_bus, OV2640_SVGA_Config); //  SVGA  ------>  800*600  30
    // ov2640_config(i2c_bus, OV2640_UXGA_Config);  //  UXGA  ------>  1600*120015
    ov2640_set_framesize(i2c_bus, OV2640_Width, OV2640_Height);                   // OV2640

    // OV2640
    struct stm32_dcmi_cropsize cropsize = {Display_Width, Display_Height, OV2640_Width, OV2640_Height};
    rt_device_control(dcmi_dev, DCMI_CTRL_CROP, &cropsize);

    ov2640_set_pixformat(i2c_bus, Pixformat_RGB565);
    // ov2640_set_pixformat(i2c_bus, Pixformat_JPEG);

    ov2640_set_saturation(i2c_bus, 0);
    ov2640_set_brightness(i2c_bus, 0);
    ov2640_set_contrast(i2c_bus, 0);
    ov2640_set_effect(i2c_bus, OV2640_Effect_Normal);

    return RT_EOK;
}
INIT_APP_EXPORT(rt_hw_ov2640_init);

#ifdef DRV_DEBUG
#ifdef FINSH_USING_MSH
#ifdef BSP_USING_LCD_SPI
#include "drv_lcd_spi.h"
int camera_sample(int argc, char **argv)
{
    rt_device_t dcmi_dev = RT_NULL;
    rt_uint8_t fps = 0;
    dcmi_dev = rt_device_find("dcmi");
    if (dcmi_dev == RT_NULL)
    {
        LOG_E("can't find dcmi device!");
        return -RT_ERROR;
    }
    struct stm32_dcmi* stm32_dcmi_dev = DCMI_DEVICE(dcmi_dev);

    // malloc dma memory
    struct rt_memheap* axi_sram = (struct rt_memheap*)rt_object_find("axi_sram", RT_Object_Class_MemHeap);
    void* buff_ptr = rt_memheap_alloc(axi_sram, OV2640_BufferSize);

    // DMA
    struct stm32_dcmi_dma_transmitbuffer transmitbuffer = {(uint32_t)buff_ptr, OV2640_BufferSize};
    rt_device_control(dcmi_dev, DCMI_CTRL_TRANSMIT_CONTINUOUS, &transmitbuffer);

    while (1) {
        rt_sem_take(&stm32_dcmi_dev->cam_semaphore, RT_WAITING_FOREVER);
        // rt_device_control(dcmi_dev, DCMI_CTRL_SUSPEND, RT_NULL);

        // 
        lcd_copybuffer(0, 0, Display_Width, Display_Height, (uint16_t *)buff_ptr);
        // rt_device_control(dcmi_dev, DCMI_CTRL_RESUME, RT_NULL);
        rt_device_control(dcmi_dev, DCMI_CTRL_GET_FPS, &fps);
        LOG_D("fps: %d", fps);
    }
    rt_memheap_free(buff_ptr);
}
MSH_CMD_EXPORT(camera_sample, record picture to lcd);

#endif /* BSP_USING_LCD_SPI */
#endif /* FINSH_USING_MSH */
#endif /* DRV_DEBUG */

#endif
