#ifndef __SWM341_CORDIC_H__
#define __SWM341_CORDIC_H__

#define CORDIC_PI   3.141592653589793

void CORDIC_Init(CORDIC_TypeDef * CORDICx);


/******************************************************************************************************************************************
* : CORDIC_Sin()
* : CORDICsin
*     : uint32_t radian       sin0.01~1.5616384
*     : 
* : 16384
******************************************************************************************************************************************/
static __INLINE void CORDIC_Sin(uint32_t radian)
{
    CORDIC->INPUT = radian;

    CORDIC->CMD = (1 << CORDIC_CMD_START_Pos) | (1 << CORDIC_CMD_SINCOS_Pos);
}

/******************************************************************************************************************************************
* : CORDIC_Sin_IsDone()
* : CORDICsin
*     : 
*     : uint32_t      0 sin    1 sin
* :
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Sin_IsDone(void)
{
    return (CORDIC->SIN & CORDIC_SIN_DONE_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : CORDIC_Sin_Result()
* : CORDICsin
*     : 
*     : uint32_t      sinResult[15:14]Result[13:0]
* : 
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Sin_Result(void)
{
    return CORDIC->SIN & (CORDIC_SIN_F_Msk | CORDIC_SIN_I_Msk);
}

/******************************************************************************************************************************************
* : CORDIC_Cos()
* : CORDICcos
*     : uint32_t radian       cos0.01~1.5616384
*     : 
* : 16384
******************************************************************************************************************************************/
static __INLINE void CORDIC_Cos(uint32_t radian)
{
    CORDIC->INPUT = radian;

    CORDIC->CMD = (1 << CORDIC_CMD_START_Pos) | (1 << CORDIC_CMD_SINCOS_Pos);
}

/******************************************************************************************************************************************
* : CORDIC_Cos_IsDone()
* : CORDICcos
*     : 
*     : uint32_t      0 cos    1 cos
* :
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Cos_IsDone(void)
{
    return (CORDIC->COS & CORDIC_COS_DONE_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : CORDIC_Cos_Result()
* : CORDICcos
*     : 
*     : uint32_t      cosResult[15:14]Result[13:0]
* : 
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Cos_Result(void)
{
    return CORDIC->COS & (CORDIC_COS_F_Msk | CORDIC_COS_I_Msk);
}

/******************************************************************************************************************************************
* : CORDIC_Arctan()
* : CORDICarctan
*     : uint32_t input        0.05~1000016384
*     : 
* : 16384
******************************************************************************************************************************************/
static __INLINE void CORDIC_Arctan(uint32_t input)
{
    if((input > 819) && (input <= 8192))
    {
        CORDIC->INPUT = input * 2;

        CORDIC->CMD = (1 << CORDIC_CMD_START_Pos) | (0 << CORDIC_CMD_SINCOS_Pos) | (0 << CORDIC_CMD_RANGE_Pos);
    }
    else if((input > 8192) && (input <= 32768))
    {
        CORDIC->INPUT = input;

        CORDIC->CMD = (1 << CORDIC_CMD_START_Pos) | (0 << CORDIC_CMD_SINCOS_Pos) | (1 << CORDIC_CMD_RANGE_Pos);
    }
    else if((input > 32768) && (input < 10000*16384))
    {
        CORDIC->INPUT = 32768*16384/input;

        CORDIC->CMD = (1 << CORDIC_CMD_START_Pos) | (0 << CORDIC_CMD_SINCOS_Pos) | (2 << CORDIC_CMD_RANGE_Pos);
    }
}

/******************************************************************************************************************************************
* : CORDIC_Arctan_IsDone()
* : CORDICarctan
*     : 
*     : uint32_t      0 arctan    1 arctan
* :
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Arctan_IsDone(void)
{
    return (CORDIC->ARCTAN & CORDIC_ARCTAN_DONE_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : CORDIC_Arctan_Result()
* : CORDICarctan
*     : 
*     : uint32_t      arctanResult[15:14]Result[13:0]
* : 
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Arctan_Result(void)
{
    return CORDIC->ARCTAN & (CORDIC_ARCTAN_F_Msk | CORDIC_ARCTAN_I_Msk);
}

/******************************************************************************************************************************************
* : CORDIC_Mul()
* : CORDIC
*     : uint16_t mul1 1
*           uint16_t mul2   2
*     : 
* : 16384
******************************************************************************************************************************************/
static __INLINE void CORDIC_Mul(uint16_t mul1, uint16_t mul2)
{
    CORDIC->INPUT = mul1 | (mul2 << 16);

    CORDIC->CMD = (1 << CORDIC_CMD_START_Pos) | (3 << CORDIC_CMD_MULDIV_Pos);
}

/******************************************************************************************************************************************
* : CORDIC_Mul_IsDone()
* : CORDIC
*     : 
*     : uint32_t      0     1 
* : 
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Mul_IsDone(void)
{
    return (CORDIC->SIN & CORDIC_SIN_DONE_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : CORDIC_Mul_Result()
* : CORDIC
*     : 
*     : uint32_t      Result[15:14]Result[13:0]
* : 
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Mul_Result(void)
{
    return CORDIC->SIN & (CORDIC_SIN_F_Msk | CORDIC_SIN_I_Msk);
}

/******************************************************************************************************************************************
* : CORDIC_Div()
* : CORDIC
*     : uint16_t dividend 
*           uint16_t divisor    
*     : 
* : 16384
******************************************************************************************************************************************/
static __INLINE void CORDIC_Div(uint16_t dividend, uint16_t divisor)
{
    CORDIC->INPUT = divisor | (dividend << 16);

    CORDIC->CMD = (1 << CORDIC_CMD_START_Pos) | (2 << CORDIC_CMD_MULDIV_Pos);
}

/******************************************************************************************************************************************
* : CORDIC_Div_IsDone()
* : CORDIC
*     : 
*     : uint32_t      0     1 
* :
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Div_IsDone(void)
{
    return (CORDIC->ARCTAN & CORDIC_ARCTAN_DONE_Msk) ? 1 : 0;
}

/******************************************************************************************************************************************
* : CORDIC_Div_Result()
* : CORDIC
*     : 
*     : uint32_t      Result[15:14]Result[13:0]
* : 
******************************************************************************************************************************************/
static __INLINE uint32_t CORDIC_Div_Result(void)
{
    return CORDIC->ARCTAN & (CORDIC_ARCTAN_F_Msk | CORDIC_ARCTAN_I_Msk);
}

#endif //__SWM341_CORDIC_H__
