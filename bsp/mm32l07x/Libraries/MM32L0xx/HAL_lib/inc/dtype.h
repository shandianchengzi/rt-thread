/****************************************Copyright (c)****************************************************
** 

**--------------File Info---------------------------------------------------------------------------------
** File name:			dtype.h
** modified Date:  		22/08/2017
** Last Version:		V2.0.0
** Descriptions:		
**	
*********************************************************************************************************/
#ifndef _DTYPE_H_
#define _DTYPE_H_     //

/*********************************************************************************************************
/
*********************************************************************************************************/
#define     __I     volatile const    // 
#define     __O     volatile          //
#define     __IO    volatile          //

/*********************************************************************************************************

*********************************************************************************************************/
typedef unsigned char  int8u;         //8 
typedef signed   char  int8s;		  //8 
typedef unsigned short int16u;        //16
typedef signed   short int16s;        //16
typedef unsigned int   int32u;        //32
typedef signed   int   int32s;        //32 
typedef float          fp32;          //32
typedef double         fp64;          //64

/*********************************************************************************************************

*********************************************************************************************************/
//typedef   signed          char int8_t;
//typedef   signed short     int int16_t;
//typedef   signed           int int32_t;
//
//typedef unsigned          char uint8_t;
//typedef unsigned short     int uint16_t;
//typedef unsigned           int uint32_t;
//
//typedef int32_t   s32;
//typedef int16_t   s16;
//typedef int8_t    s8;
//typedef uint32_t  u32;
//typedef uint16_t  u16;
//typedef uint8_t   u8;
/*
typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;	
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))
*/
#endif  //_DTYPE_H_
