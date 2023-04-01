/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-06            first version
 */

// i2c


#include "ls1c_public.h"
#include "ls1c_regs.h"
#include "ls1c_clock.h"
#include "ls1c_i2c.h"
#include "ls1c_delay.h"



/*
 * I2C
 * 
 * 
 */
#define LS1C_I2C_PRER_LOW_OFFSET            (0)     // 
#define LS1C_I2C_PRER_HIGH_OFFSET           (1)     // 
#define LS1C_I2C_CONTROL_OFFSET             (2)     // 
#define LS1C_I2C_DATA_OFFSET                (3)     // 
#define LS1C_I2C_CMD_OFFSET                 (4)     // 
#define LS1C_I2C_STATUS_OFFSET              (4)     // 


// 
#define LS1C_I2C_CONTROL_EN                 (0x80)  // i2c
#define LS1C_I2C_CONTROL_IEN                (0x40)  // 

// 
#define LS1C_I2C_CMD_START                  (0x90)  // START
#define LS1C_I2C_CMD_STOP                   (0x40)  // STOP
#define LS1C_I2C_CMD_READ                   (0x20)  // ACK
#define LS1C_I2C_CMD_WRITE                  (0x10)  // 
#define LS1C_I2C_CMD_READ_ACK               (0x20)  // ACK
#define LS1C_I2C_CMD_READ_NACK              (0x28)  // NACK
#define LS1C_I2C_CMD_IACK                   (0x00)  // 

// 
#define LS1C_I2C_STATUS_IF                  (0x01)  // 
#define LS1C_I2C_STATUS_TIP                 (0x02)  // 10
#define LS1C_I2C_STATUS_ARBLOST             (0x20)  // I2CI2C
#define LS1C_I2C_STATUS_BUSY                (0x40)  // I2C
#define LS1C_I2C_STATUS_NACK                (0x80)  // 10


/*
 * i2c
 * @I2Cx I2C
 */
void *i2c_get_base(ls1c_i2c_t I2Cx)
{
    void *base = NULL;
    
    switch (I2Cx)
    {
        case LS1C_I2C_0:
            base = (void *)LS1C_I2C0_BASE;
            break;

        case LS1C_I2C_1:
            base = (void *)LS1C_I2C1_BASE;
            break;

        case LS1C_I2C_2:
            base = (void *)LS1C_I2C2_BASE;
            break;

        default:
            base = NULL;
            break;
    }

    return base;
}


/*
 * 
 * @i2c_info_p i2c
 * @cmd 
 */
void i2c_cmd(ls1c_i2c_info_t *i2c_info_p, unsigned char cmd)
{
    void *i2c_base = i2c_get_base(i2c_info_p->I2Cx);

    reg_write_8(cmd, i2c_base + LS1C_I2C_CMD_OFFSET);

    return ;
}


/*
 * STARTSTART
 * @i2c_info_p i2c
 */
void i2c_cmd_start(ls1c_i2c_info_t *i2c_info_p)
{
    i2c_cmd(i2c_info_p, LS1C_I2C_CMD_START);
    return ;
}


/*
 * STOPSTOP
 * @i2c_info_p i2c
 */
void i2c_cmd_stop(ls1c_i2c_info_t *i2c_info_p)
{
    i2c_cmd(i2c_info_p, LS1C_I2C_CMD_STOP);
    return ;
}


/*
 * 
 * @i2c_info_p i2c
 */
void i2c_cmd_write(ls1c_i2c_info_t *i2c_info_p)
{
    i2c_cmd(i2c_info_p, LS1C_I2C_CMD_WRITE);
    return ;
}


/*
 * ackack
 * @i2c_info_p i2c
 */
void i2c_cmd_read_ack(ls1c_i2c_info_t *i2c_info_p)
{
    i2c_cmd(i2c_info_p, LS1C_I2C_CMD_READ_ACK);
    return ;
}


/*
 * nack,nack
 * @i2c_info_p i2c
 */
void i2c_cmd_read_nack(ls1c_i2c_info_t *i2c_info_p)
{
    i2c_cmd(i2c_info_p, LS1C_I2C_CMD_READ_NACK);
    return ;
}


/*
 * 
 * @i2c_info_p i2c
 */
void i2c_cmd_iack(ls1c_i2c_info_t *i2c_info_p)
{
    i2c_cmd(i2c_info_p, LS1C_I2C_CMD_IACK);
    return ;
}


/*
 * 
 * @i2c_info_p i2c
 * @ret 
 */
unsigned char i2c_get_status(ls1c_i2c_info_t *i2c_info_p)
{
    void *i2c_base = i2c_get_base(i2c_info_p->I2Cx);

    return reg_read_8(i2c_base + LS1C_I2C_STATUS_OFFSET);
}


/*
 * Poll the i2c status register until the specified bit is set.
 * Returns 0 if timed out (100 msec).
 * @i2c_info_p i2c
 * @bit 
 * @ret true or false
 */
int i2c_poll_status(ls1c_i2c_info_t *i2c_info_p, unsigned long bit)
{
    int loop_cntr = 20000;

    do {
        delay_us(1);
    } while ((i2c_get_status(i2c_info_p) & bit) && (0 < --loop_cntr));

    return (0 < loop_cntr);
}


/*
 * i2c
 * @i2c_info_p i2c
 */
void i2c_init(ls1c_i2c_info_t *i2c_info_p)
{
    void *i2c_base = i2c_get_base(i2c_info_p->I2Cx);
    unsigned long i2c_clock = i2c_info_p->clock;
    unsigned char ctrl = reg_read_8(i2c_base + LS1C_I2C_CONTROL_OFFSET);
    unsigned long prescale = 0;

    /* make sure the device is disabled */
    ctrl = ctrl & ~(LS1C_I2C_CONTROL_EN | LS1C_I2C_CONTROL_IEN);
    reg_write_8(ctrl, i2c_base + LS1C_I2C_CONTROL_OFFSET);

    // 
    i2c_clock = MIN(i2c_clock, LS1C_I2C_CLOCK_MAX);     // 
    prescale = clk_get_apb_rate();
    prescale = (prescale / (5 * i2c_clock)) - 1;
    reg_write_8(prescale & 0xff, i2c_base + LS1C_I2C_PRER_LOW_OFFSET);
    reg_write_8(prescale >> 8, i2c_base + LS1C_I2C_PRER_HIGH_OFFSET);
    
    // 
    i2c_cmd_iack(i2c_info_p);
    ctrl = ctrl | LS1C_I2C_CONTROL_EN;
    reg_write_8(ctrl, i2c_base + LS1C_I2C_CONTROL_OFFSET);

    return ;
}


/*
 * ()ACK
 * @i2c_info_p i2c
 * @ret LS1C_I2C_ACK or LS1C_I2C_NACK
 */
ls1c_i2c_ack_t i2c_receive_ack(ls1c_i2c_info_t *i2c_info_p)
{
    ls1c_i2c_ack_t ret = LS1C_I2C_NACK;
    
    if (LS1C_I2C_STATUS_NACK & i2c_get_status(i2c_info_p))
    {
        ret = LS1C_I2C_NACK;
    }
    else
    {
        ret = LS1C_I2C_ACK;
    }

    return ret;
}


/*
 * 
 * @i2c_info_p i2c
 * @buf 
 * @len 
 */
ls1c_i2c_ret_t i2c_receive_data(ls1c_i2c_info_t *i2c_info_p, unsigned char *buf, int len)
{
    void *i2c_base = i2c_get_base(i2c_info_p->I2Cx);
    int i = 0;

    for (i=0; i<len; i++)
    {
        // 
        if (i != (len - 1))
            i2c_cmd_read_ack(i2c_info_p);
        else 
            i2c_cmd_read_nack(i2c_info_p);

        // 
        if (!i2c_poll_status(i2c_info_p, LS1C_I2C_STATUS_TIP))
            return LS1C_I2C_RET_TIMEOUT;

        // 
        *buf++ = reg_read_8(i2c_base + LS1C_I2C_DATA_OFFSET);
    }

    return LS1C_I2C_RET_OK;
}


/*
 * START
 * @i2c_info_p i2c
 * @slave_addr 
 * @direction ()
 */
ls1c_i2c_ret_t i2c_send_start_and_addr(ls1c_i2c_info_t *i2c_info_p, 
                                       unsigned char slave_addr,
                                       ls1c_i2c_direction_t direction)
{
    void *i2c_base = i2c_get_base(i2c_info_p->I2Cx);
    unsigned char data = 0;
    
    // i2c
    if (!i2c_poll_status(i2c_info_p, LS1C_I2C_STATUS_BUSY))
        return LS1C_I2C_RET_TIMEOUT;

    // 
    data = (slave_addr << 1) | ((LS1C_I2C_DIRECTION_READ == direction) ? 1 : 0);
    reg_write_8(data , i2c_base + LS1C_I2C_DATA_OFFSET);

    // 
    i2c_cmd_start(i2c_info_p);

    // 
    if (!i2c_poll_status(i2c_info_p, LS1C_I2C_STATUS_TIP))
        return LS1C_I2C_RET_TIMEOUT;

    return LS1C_I2C_RET_OK;
}


/*
 * 
 * @i2c_info_p i2c
 * @data 
 * @len 
 */
ls1c_i2c_ret_t i2c_send_data(ls1c_i2c_info_t *i2c_info_p, unsigned char *data, int len)
{
    void *i2c_base = i2c_get_base(i2c_info_p->I2Cx);
    int i = 0;

    for (i=0; i<len; i++)
    {
        // 
        reg_write_8(*data++, i2c_base + LS1C_I2C_DATA_OFFSET);

        // 
        reg_write_8(LS1C_I2C_CMD_WRITE, i2c_base + LS1C_I2C_CMD_OFFSET);

        // 
        if (!i2c_poll_status(i2c_info_p, LS1C_I2C_STATUS_TIP))
            return LS1C_I2C_RET_TIMEOUT;

        // 
        if (LS1C_I2C_ACK != i2c_receive_ack(i2c_info_p))
            return len;
    }

    return LS1C_I2C_RET_OK;
}



/*
 * STOP
 * @i2c_info_p i2c
 */
void i2c_send_stop(ls1c_i2c_info_t *i2c_info_p)
{
    i2c_cmd_stop(i2c_info_p);
    return ;
}


