/*
*@:Copyright(c)2021PhytiumInformationTechnology,Inc.
*
*SPDX-License-Identifier:Apache-2.0.
*
 * @Date: 2021-04-07 09:53:07
 * @LastEditTime: 2021-04-07 15:31:34
 * @Description: This files is for
 *
 * @ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#include "ft_parameters.h"
#include "ft_uart_hw.h"

u8 inbyte(void)
{
    return FUart_RecvByte(FT_STDIN_BASEADDRESS);
}
