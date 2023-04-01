/*
* Copyright (c) 2019-2025 Allwinner Technology Co., Ltd. ALL rights reserved.
*
* Allwinner is a trademark of Allwinner Technology Co.,Ltd., registered in
* the the People's Republic of China and other countries.
* All Allwinner Technology Co.,Ltd. trademarks are used with permission.
*
* DISCLAIMER
* THIRD PARTY LICENCES MAY BE REQUIRED TO IMPLEMENT THE SOLUTION/PRODUCT.
* IF YOU NEED TO INTEGRATE THIRD PARTYS TECHNOLOGY (SONY, DTS, DOLBY, AVS OR MPEGLA, ETC.)
* IN ALLWINNERSSDK OR PRODUCTS, YOU SHALL BE SOLELY RESPONSIBLE TO OBTAIN
* ALL APPROPRIATELY REQUIRED THIRD PARTY LICENCES.
* ALLWINNER SHALL HAVE NO WARRANTY, INDEMNITY OR OTHER OBLIGATIONS WITH RESPECT TO MATTERS
* COVERED UNDER ANY REQUIRED THIRD PARTY LICENSE.
* YOU ARE SOLELY RESPONSIBLE FOR YOUR USAGE OF THIRD PARTYS TECHNOLOGY.
*
*
* THIS SOFTWARE IS PROVIDED BY ALLWINNER"AS IS" AND TO THE MAXIMUM EXTENT
* PERMITTED BY LAW, ALLWINNER EXPRESSLY DISCLAIMS ALL WARRANTIES OF ANY KIND,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING WITHOUT LIMITATION REGARDING
* THE TITLE, NON-INFRINGEMENT, ACCURACY, CONDITION, COMPLETENESS, PERFORMANCE
* OR MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL ALLWINNER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS, OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __PLATFORM_GPIO_H__
#define __PLATFORM_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_MAX_BANK PL_BASE
#define BANK_BOUNDARY PL_BASE
#define SUNXI_GPIO_PBASE 0x0300B000

/* sunxi gpio irq*/
#define SUNXI_GIC_START 32
#define SUNXI_IRQ_GPIOB                (SUNXI_GIC_START + 43)  /* 75 gpiob interrupt */
#define SUNXI_IRQ_GPIOE                (SUNXI_GIC_START + 44)  /* 76 gpioe interrupt */
#define SUNXI_IRQ_GPIOG                (SUNXI_GIC_START + 46)  /* 78 gpiog interrupt */
#define SUNXI_IRQ_GPIOH                (SUNXI_GIC_START + 47)  /* 79 gpioh interrupt */

typedef enum
{
    GPIO_PB0 = GPIOB(0),
    GPIO_PB1 = GPIOB(1),
    GPIO_PB2 = GPIOB(2),
    GPIO_PB3 = GPIOB(3),
    GPIO_PB4 = GPIOB(4),
    GPIO_PB5 = GPIOB(5),
    GPIO_PB6 = GPIOB(6),
    GPIO_PB7 = GPIOB(7),
    GPIO_PB8 = GPIOB(8),
    GPIO_PB9 = GPIOB(9),
    GPIO_PB10 = GPIOB(10),
    GPIO_PB11 = GPIOB(11),
    GPIO_PB12 = GPIOB(12),
    GPIO_PB13 = GPIOB(13),

    GPIO_PC0 = GPIOC(0),
    GPIO_PC1 = GPIOC(1),
    GPIO_PC2 = GPIOC(2),
    GPIO_PC3 = GPIOC(3),
    GPIO_PC4 = GPIOC(4),
    GPIO_PC5 = GPIOC(5),
    GPIO_PC6 = GPIOC(6),
    GPIO_PC7 = GPIOC(7),
    GPIO_PC8 = GPIOC(8),
    GPIO_PC9 = GPIOC(9),
    GPIO_PC10 = GPIOC(10),
    GPIO_PC11 = GPIOC(11),
    GPIO_PC12 = GPIOC(12),
    GPIO_PC13 = GPIOC(13),
    GPIO_PC14 = GPIOC(14),
    GPIO_PC15 = GPIOC(15),
    GPIO_PC16 = GPIOC(16),

    GPIO_PD0 = GPIOD(0),
    GPIO_PD1 = GPIOD(1),
    GPIO_PD2 = GPIOD(2),
    GPIO_PD3 = GPIOD(3),
    GPIO_PD4 = GPIOD(4),
    GPIO_PD5 = GPIOD(5),
    GPIO_PD6 = GPIOD(6),
    GPIO_PD7 = GPIOD(7),
    GPIO_PD8 = GPIOD(8),
    GPIO_PD9 = GPIOD(9),
    GPIO_PD10 = GPIOD(10),
    GPIO_PD11 = GPIOD(11),
    GPIO_PD12 = GPIOD(12),
    GPIO_PD13 = GPIOD(13),
    GPIO_PD14 = GPIOD(14),
    GPIO_PD15 = GPIOD(15),
    GPIO_PD16 = GPIOD(16),
    GPIO_PD17 = GPIOD(17),
    GPIO_PD18 = GPIOD(18),
    GPIO_PD19 = GPIOD(19),
    GPIO_PD20 = GPIOD(20),
    GPIO_PD21 = GPIOD(21),
    GPIO_PD22 = GPIOD(22),

    GPIO_PE0 = GPIOE(0),
    GPIO_PE1 = GPIOE(1),
    GPIO_PE2 = GPIOE(2),
    GPIO_PE3 = GPIOE(3),
    GPIO_PE4 = GPIOE(4),
    GPIO_PE5 = GPIOE(5),
    GPIO_PE6 = GPIOE(6),
    GPIO_PE7 = GPIOE(7),
    GPIO_PE8 = GPIOE(8),
    GPIO_PE9 = GPIOE(9),
    GPIO_PE10 = GPIOE(10),
    GPIO_PE11 = GPIOE(11),
    GPIO_PE12 = GPIOE(12),
    GPIO_PE13 = GPIOE(13),
    GPIO_PE14 = GPIOE(14),
    GPIO_PE15 = GPIOE(15),
    GPIO_PE16 = GPIOE(16),
    GPIO_PE17 = GPIOE(17),
    GPIO_PE18 = GPIOE(18),
    GPIO_PE19 = GPIOE(19),
    GPIO_PE20 = GPIOE(20),
    GPIO_PE21 = GPIOE(21),

    GPIO_PF0 = GPIOF(0),
    GPIO_PF1 = GPIOF(1),
    GPIO_PF2 = GPIOF(2),
    GPIO_PF3 = GPIOF(3),
    GPIO_PF4 = GPIOF(4),
    GPIO_PF5 = GPIOF(5),
    GPIO_PF6 = GPIOF(6),

    GPIO_PG0 = GPIOG(0),
    GPIO_PG1 = GPIOG(1),
    GPIO_PG2 = GPIOG(2),
    GPIO_PG3 = GPIOG(3),
    GPIO_PG4 = GPIOG(4),
    GPIO_PG5 = GPIOG(5),
    GPIO_PG6 = GPIOG(6),
    GPIO_PG7 = GPIOG(7),

    GPIO_PH0 = GPIOH(0),
    GPIO_PH1 = GPIOH(1),
    GPIO_PH2 = GPIOH(2),
    GPIO_PH3 = GPIOH(3),
    GPIO_PH4 = GPIOH(4),
    GPIO_PH5 = GPIOH(5),
    GPIO_PH6 = GPIOH(6),
    GPIO_PH7 = GPIOH(7),
    GPIO_PH8 = GPIOH(8),
    GPIO_PH9 = GPIOH(9),
    GPIO_PH10 = GPIOH(10),
    GPIO_PH11 = GPIOH(11),
    GPIO_PH12 = GPIOH(12),
    GPIO_PH13 = GPIOH(13),
    GPIO_PH14 = GPIOH(14),
    GPIO_PH15 = GPIOH(15),

    GPIO_PI0 = GPIOI(0),
    GPIO_PI1 = GPIOI(1),
    GPIO_PI2 = GPIOI(2),
    GPIO_PI3 = GPIOI(3),
    GPIO_PI4 = GPIOI(4),
    GPIO_PI5 = GPIOI(5),

    GPIO_PL0 = GPIOL(0),
    GPIO_PL1 = GPIOL(1),
    GPIO_PL2 = GPIOL(2),
    GPIO_PL3 = GPIOL(3),
    GPIO_PL4 = GPIOL(4),
    GPIO_PL5 = GPIOL(5),
} gpio_pin_t;

#ifdef __cplusplus
}
#endif
#endif /* __PLATFORM_GPIO_H__ */
