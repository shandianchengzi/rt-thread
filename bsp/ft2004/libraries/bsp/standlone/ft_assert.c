/*
*@:Copyright(c)2021PhytiumInformationTechnology,Inc.
*
*SPDX-License-Identifier:Apache-2.0.
*
 * @Date: 2021-04-07 09:53:07
 * @LastEditTime: 2021-05-18 13:43:09
 * @Description: This files is for type definition
 *
 * @ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 */

#include "ft_types.h"
#include "ft_assert.h"

/*************   *****************/
u32 Ft_assertStatus;

/************** 1 0  ******************/
s32 Ft_assertWait = 1;

/*  */
static Ft_assertCallback Ft_assertCallbackRoutine = NULL;

/************************** Function Prototypes ******************************/
void Ft_assert(FT_IN char *File, s32 Line)
{
    if (Ft_assertCallbackRoutine != NULL)
    {
        Ft_assertCallbackRoutine(File, Line);
    }

    while (Ft_assertWait != 0)
    {
    }
}

void Ft_assertSetCallBack(Ft_assertCallback Routine)
{
    Ft_assertCallbackRoutine = Routine;
}
