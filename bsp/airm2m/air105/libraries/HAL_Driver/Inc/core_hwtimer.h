/*
 * Copyright (c) 2022 OpenLuat & AirM2M
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __CORE_HWTIMER_H__
#define __CORE_HWTIMER_H__


/**
 * @brief PWM
 *
 * @param HWTimerID ID
 * @param Period 24M
 * @param Duty 0.1%50KHz500KHz1%
 * @param IsOnePulse 
 */
void HWTimer_SetPWM(uint8_t HWTimerID, uint32_t Period, uint16_t Duty, uint8_t IsOnePulse);

/**
 * @brief PWM48M
 *
 * @param HWTimerID ID
 * @param HighCnt 
 * @param LowCnt 
 * @param IsOnePulse 
 */
void HWTimer_StartPWM(uint8_t HWTimerID, uint32_t HighCnt, uint32_t LowCnt, uint8_t IsOnePulse);

/**
 * @brief 
 *
 * @param HWTimerID ID
 */
void HWTimer_Stop(uint8_t HWTimerID);
/**
 * @brief IO
 *
 * @param HWTimerID ID
 * @param nCount 
 * @param Repeat 
 * @param InputByte IO81byte81byte
 * @param CmdDoneCB 
 * @param pCmdDoneParam 
 *
 */
void HWTimer_InitOperationQueue(uint8_t HWTimerID, uint32_t nCount, uint32_t Repeat, uint32_t InputByte, CBFuncEx_t CmdDoneCB, void *pCmdDoneParam);
/**
 * @brief IO
 *
 * @param HWTimerID ID
 * @param pCmd IO
 */
void HWTimer_AddOperation(uint8_t HWTimerID, OPQueue_CmdStruct *pCmd);
/**
 * @brief IO
 *
 * @param HWTimerID ID
 */
void HWTimer_StartOperationQueue(uint8_t HWTimerID);
/**
 * @brief IOAddOperationinit
 *
 * @param HWTimerID ID
 */
void HWTimer_ClearOperationQueue(uint8_t HWTimerID);
/**
 * @brief IOinitHWTimer_CheckOperationQueueDone
 *
 * @param HWTimerID ID
 */
void HWTimer_FreeOperationQueue(uint8_t HWTimerID);
/**
 * @brief OP_QUEUE_CMD_CBCBOP_QUEUE_CMD_CB
 *
 * @param HWTimerID ID
 */
void HWTimer_AddEndCmdInOperationQueue(uint8_t HWTimerID);
/**
 * @brief IO
 *
 * @param HWTimerID ID
 * @return =0
 */
uint8_t HWTimer_CheckOperationQueueDone(uint8_t HWTimerID);
/**
 * @brief IOIO
 *
 * @param HWTimerID ID
 * @param Value copy
 * @return byteinitInputByte
 */
int HWTimer_GetOperationQueueInputResult(uint8_t HWTimerID, uint8_t *Value);

/**
 * @brief IO
 *
 * @param HWTimerID ID
 * @param CB 
 * @param CB 
 * @return 
 */
uint32_t HWTimer_GetOperationQueueCaptureResult(uint8_t HWTimerID, CBFuncEx_t CB, void *pParam);
#endif
