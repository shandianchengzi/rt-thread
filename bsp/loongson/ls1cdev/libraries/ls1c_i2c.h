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

#ifndef __OPENLOONGSON_I2C_H
#define __OPENLOONGSON_I2C_H



// I2C
#define LS1C_I2C_CLOCK_DEFAULT              (100000)  // Hz. 
#define LS1C_I2C_CLOCK_MAX                  (400000)  // Hz, max 400 Kbits/sec


// I2C
typedef enum
{
    LS1C_I2C_0 = 0,
    LS1C_I2C_1,
    LS1C_I2C_2
}ls1c_i2c_t;


// I2C
typedef enum
{
    LS1C_I2C_DIRECTION_WRITE = 0,       // 
    LS1C_I2C_DIRECTION_READ,            // 
}ls1c_i2c_direction_t;


// I2C
typedef struct
{
    ls1c_i2c_t I2Cx;                    // i2c
    unsigned long clock;                // i2chz
}ls1c_i2c_info_t;


// I2C
typedef enum
{
    LS1C_I2C_ACK = 0,                   // 
    LS1C_I2C_NACK = 1,                  // 
}ls1c_i2c_ack_t;


// 
typedef enum
{
    LS1C_I2C_RET_OK = 0,                // OK
    LS1C_I2C_RET_TIMEOUT,               // 
}ls1c_i2c_ret_t;



/*
 * i2c
 * @i2c_info_p i2c
 */
void i2c_init(ls1c_i2c_info_t *i2c_info_p);


/*
 * ()ACK
 * @i2c_info_p i2c
 * @ret LS1C_I2C_ACK or LS1C_I2C_NACK
 */
ls1c_i2c_ack_t i2c_receive_ack(ls1c_i2c_info_t *i2c_info_p);


/*
 * 
 * @i2c_info_p i2c
 * @buf 
 * @len 
 */
ls1c_i2c_ret_t i2c_receive_data(ls1c_i2c_info_t *i2c_info_p, unsigned char *buf, int len);



/*
 * START
 * @i2c_info_p i2c
 * @slave_addr 
 * @direction ()
 */
ls1c_i2c_ret_t i2c_send_start_and_addr(ls1c_i2c_info_t *i2c_info_p, 
                                       unsigned char slave_addr,
                                       ls1c_i2c_direction_t direction);


/*
 * 
 * @i2c_info_p i2c
 * @data 
 * @len 
 */
ls1c_i2c_ret_t i2c_send_data(ls1c_i2c_info_t *i2c_info_p, unsigned char *data, int len);


/*
 * STOP
 * @i2c_info_p i2c
 */
void i2c_send_stop(ls1c_i2c_info_t *i2c_info_p);



#endif

