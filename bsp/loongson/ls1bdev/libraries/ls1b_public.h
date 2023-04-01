/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-06            first version
 */

// 

#ifndef __LOONGSON_PUBLIC_H
#define __LOONGSON_PUBLIC_H


#include <stdio.h>


// pmonmain()
struct callvectors {
	int     (*open) (char *, int, int);
	int     (*close) (int);
	int     (*read) (int, void *, int);
	int     (*write) (int, void *, int);
	long long   (*lseek) (int, long long, int);
	int     (*printf) (const char *, ...);
	void    (*cacheflush) (void);
	char    *(*gets) (char *);
};
#define	myprintf (*callvec->printf)
#define	mygets   (*callvec->gets)
extern struct callvectors *callvec;


#define MIN(a, b)           ((a) > (b) ? (b) : (a))
#define MAX(a, b)           ((a) > (b) ? (a) : (b))

#define DIV_ROUND_UP(n, d)      (((n) + (d) - 1) / (d))

typedef enum
{
    FALSE=0, 
    TRUE=1
}BOOL;

/*
 * 1
 * @reg 
 * @bit 1bit
 */
void reg_set_one_bit(volatile unsigned int *reg, unsigned int bit);


/*
 * 
 * @reg 
 * @bit bit
 */
void reg_clr_one_bit(volatile unsigned int *reg, unsigned int bit);


/*
 * 
 * @reg 
 * @bit bit
 * @ret 
 */
unsigned int reg_get_bit(volatile unsigned int *reg, unsigned int bit);


/*
 * 8bit()
 * @data 
 * @addr 
 */
void reg_write_8(unsigned char data, volatile unsigned char *addr);


/*
 * 8bit()
 * @addr 
 * @ret 
 */
unsigned char reg_read_8(volatile unsigned char *addr);


/*
 * 32bit
 * @data 
 * @addr 
 */
void reg_write_32(unsigned int data, volatile unsigned int *addr);


/*
 * 32bit
 * @addr 
 * @ret 
 */
unsigned int reg_read_32(volatile unsigned int *addr);


/**
 * ffs - find first bit set
 * @x: the word to search
 */
int ls1b_ffs(int x);

/*
 * fls - find last (most-significant) bit set
 * @x: the word to search
 *
 * This is defined the same way as ffs.
 * Note fls(0) = 0, fls(1) = 1, fls(0x80000000) = 32.
 */
int ls1b_fls(int x);


#endif

