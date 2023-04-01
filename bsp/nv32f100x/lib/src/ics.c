/*************************************************************!     
 *     QQ  123763203
 *         www.navota.com
 *
 * @file       ics.c
 * @brief      ICS)
 * @author     Navota
 * @date       2017-1-1
 ****************************************************************/
#include "common.h"
#include "ics.h"

/* ICSOSC */
#define ICS_C1_DEFAULT  0x04
#define ICS_C2_DEFAULT  0x20
#define ICS_C3_DEFAULT  0x54
#define ICS_C4_DEFAULT  0x00
#define ICS_S_DEFAULT   0x50
#define OSC_CR_DEFAULT  0


/*****************************************************************************//*!
   * 
   * @   ICSFEIFEE1
   *         OSC
   * 
   * @  pConfig  ICS
   *
   * @ 
   *
   * @ / 
   *****************************************************************************/
void FEI_to_FEE(ICS_ConfigType *pConfig)
{
	/*
	 * OSC
	 */
	OSC_Init(&pConfig->oscConfig); /*OSC */
	
	/* 
     * 31.25k~39.0625k
	 */
 
    ICS_SetClkDivider(pConfig->u32ClkFreq);

        /*FLL*/
	ICS->C1 =  ICS->C1 & ~ICS_C1_IREFS_MASK;
         
        /*FLL*/

#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop 
};        
#endif        
	while(ICS->S & ICS_S_IREFST_MASK);
	
        /* FLLICS*/
	while(!(ICS->S & ICS_S_LOCK_MASK));
		
	/*
     *FLLFLLFLL
	 * FLL
	 */
#if defined(CPU_NV32)
  /*ICS1*/
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) == 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
	}
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif
	
	/*
	 * 1/
	 */
    /*LOLS0*/
	ICS->S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   *
   * @   ICSFEIFBIICS
   *         2
   *        
   * @   pConfig    ICS. 
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FEI_to_FBI(ICS_ConfigType *pConfig)
{

        /*ICS*/
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(1);   
	ICS->C2 = ICS->C2 & ~(ICS_C2_LP_MASK); 
        /*ICS*/
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif        
	while(((ICS->S & ICS_S_CLKST_MASK) >> ICS_S_CLKST_SHIFT) !=1);
			
	/*
	 * ICS
	 */
#if defined(BUS_CLK_EQU_CORE_DIVIDE_BY_2)||defined(CPU_NV32) 
         /*ICS2*/       
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}

#else
	ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK));     
#endif        
	
     /*LOLS*/
	ICS->S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   *
   * @   ICSFEIFBEICS2
   *         OSC
   *
   * @   pConfig   ICS . 
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/

void FEI_to_FBE(ICS_ConfigType *pConfig)
{
	OSC_Init(&pConfig->oscConfig); /*OSC  */

         /*FLL*/

    ICS->C1 =  ICS->C1 & ~(ICS_C1_IREFS_MASK);
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(2);   
	ICS->C2 = ICS->C2 & ~(ICS_C2_LP_MASK); 
       
        /**/
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif        

	while(((ICS->S & ICS_S_CLKST_MASK) >> ICS_S_CLKST_SHIFT) !=2);  /*ICS*/
        while(ICS->S & ICS_S_IREFST_MASK);  /*FLL*/
			
	/* 
	 * ICS
	 */
#if defined(CPU_NV32)
        /*ICS2*/
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif
	/* 
	 * ICS2
	 */
        /* LOLS */
	ICS->S |= ICS_S_LOLS_MASK;	
}


/*****************************************************************************//*!
   *
   * @   ICSFEIFBE2 
   *         OSCEXTAL 
   *
   * @  pConfig  . 
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FEI_to_FBE_OSC(ICS_ConfigType *pConfig)
{
    
	OSC_Init(&pConfig->oscConfig); /* OSC */

	/* 
	 * FLL31.25k~39.0625k
	 */
    ICS_SetClkDivider(pConfig->u32ClkFreq);
    
        /*FLL*/
        ICS->C1 =  ICS->C1 & ~(ICS_C1_IREFS_MASK);/*FLL*/
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(2);  /**/ 
	ICS->C2 = ICS->C2 & ~(ICS_C2_LP_MASK); 
        
        /* */

#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(((ICS->S & ICS_S_CLKST_MASK) >> ICS_S_CLKST_SHIFT) !=2);/*ICS*/
        while(ICS->S & ICS_S_IREFST_MASK);   /*FLL*/
			
	/* 
	 * FLLICS
	 */
#if defined(CPU_NV32)
             /*ICS2*/
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif
	/* 
	 * ICS2
	 */
        /*LOLS */
	ICS->S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   *
   * @   ICSFEIFEEICS2 
   *         OSCEXTAL
   *
   * @   pConfig    
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/

void FEI_to_FEE_OSC(ICS_ConfigType *pConfig)
{

	OSC_Init(&pConfig->oscConfig); /* OSC */

	/* 
	 * FLL31.25k~39.0625k
	 */
    ICS_SetClkDivider(pConfig->u32ClkFreq);

        /* FLL */
        
    ICS->C1 =  ICS->C1 & ~(ICS_C1_IREFS_MASK);

        /**/
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(ICS->S & ICS_S_IREFST_MASK); /*FLL*/
	
        /*FLLICS */
	while(!(ICS->S & ICS_S_LOCK_MASK));
#if defined(CPU_NV32)	
       /*2*/	
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif
	/* 
	 * ICS
	 */

     /* LOLS */
	ICS->S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   *
   * @  ICSFEEFEI.
   *        
   * @   pConfig   
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FEE_to_FEI(ICS_ConfigType *pConfig)
{
       /*FLL*/ 
    ICS->C1 =  ICS->C1 | (ICS_C1_IREFS_MASK);
	
        /**/
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(!(ICS->S & ICS_S_IREFST_MASK)); /*FLL*/
	
        /*FLLICS */
	while(!(ICS->S & ICS_S_LOCK_MASK));
         /*LOLS*/
	ICS->S |= ICS_S_LOLS_MASK;

	/* 
	 * FLLICS
	 */
#if defined(CPU_NV32)
        /*ICS2*/
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif
	/* 
	 * / 16MHz
	 */
	    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
      OSC_Disable();            /*  OSC */
}

/*****************************************************************************//*!
   *
   * @  ICSFEEFBI.
   *        
   * @  pConfig    
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FEE_to_FBI(ICS_ConfigType *pConfig)
{
        /*LOLS*/
	ICS->S |= ICS_S_LOLS_MASK;
	
  /* ICS */
	/* FLL */ 
	/* LP = 0 bypassFLL*/
        
    ICS->C1 =  ICS->C1 | (ICS_C1_IREFS_MASK);
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(1);   
	ICS->C2 = ICS->C2 & ~(ICS_C2_LP_MASK); 

        /*  */
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(!(ICS->S & ICS_S_IREFST_MASK));  /*FLL*/
	while(((ICS->S & ICS_S_CLKST_MASK) >> ICS_S_CLKST_SHIFT) !=1);  /*ICS*/
	
#if defined(BUS_CLK_EQU_CORE_DIVIDE_BY_2)||defined(CPU_NV32)  
         /*ICS2*/      
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}

#else
	ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK));
       
#endif    
        OSC_Disable();            
}

/*****************************************************************************//*!
   *
   * @   ICSFEEFBE
   *        
   * @   pConfig  
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/

void FEE_to_FBE(ICS_ConfigType *pConfig)
{
        /*LOLS*/
	ICS->S |= ICS_S_LOLS_MASK;
	
	
        /* LP = 0 */
        /*ICS*/
        /* LP = 0 bypassFLL*/

	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(2);   
	ICS->C2 = ICS->C2 & ~(ICS_C2_LP_MASK); 

        /**/
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(((ICS->S & ICS_S_CLKST_MASK) >> ICS_S_CLKST_SHIFT) !=2);
	
   /* ICS
	 * : 20MHz
	 */
#if defined(CPU_NV32)
        /*ICS2*/	 
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif
}

/*****************************************************************************//*!
   *
   * @  ICSFBIFBE
   *        
   * @   pConfig   . 
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FBI_to_FBE(ICS_ConfigType *pConfig)
{
	OSC_Init(&pConfig->oscConfig); /*OSC*/
    
	/* FLL */
	/**/

       ICS->C1 =  ICS->C1 & ~(ICS_C1_IREFS_MASK);
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(2);   


	/*  */

#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(((ICS->S & ICS_S_CLKST_MASK) >> ICS_S_CLKST_SHIFT) !=2); /*ICS*/
	while((ICS->S & ICS_S_IREFST_MASK));/*FLL*/

        /* 
	 * :20MHz
	 */
#if defined(CPU_NV32)
         /*2*/
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif
}

/*****************************************************************************//**
   *
   * @  ICSFBIFEE
   *        
   * @   pConfig     
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FBI_to_FEE(ICS_ConfigType *pConfig)
{
	OSC_Init(&pConfig->oscConfig); /*OSC*/
 
	/* FLL */
	/* FLLICS*/

    ICS->C1 =  ICS->C1 & ~(ICS_C1_IREFS_MASK);
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK));   

        /**/
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     

	while((ICS->S & ICS_S_CLKST_MASK));   /*FLLICS*/
	while((ICS->S & ICS_S_IREFST_MASK));  /*FLL*/
	
     /* 
	 * : 20MHz
	 */
#if defined(CPU_NV32)
        /*2*/
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif
       /*LOLS*/
	ICS->S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   *
   * @  ICSFBIFBIP 
   * 
   * @   pConfig    
   *
   * @ 
   *
   * @ / 
   * @  
   * @   ICS_ConfigType
   *****************************************************************************/
void FBI_to_FBILP(ICS_ConfigType *pConfig)
{
	/*
	 * 8MHz4MHz
	 */
	ICS->C2 |= ICS_C2_LP_MASK;	/* */
}



/*****************************************************************************//*!
   *
   * @  ICSFBIFEI
   * 
   * @  pConfig  . 
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FBI_to_FEI(ICS_ConfigType *pConfig)
{
     /* FLL */
	/*FLLICS*/
    ICS->C1 =  ICS->C1 | (ICS_C1_IREFS_MASK);
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK));   
	
        /**/

#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while((ICS->S & ICS_S_CLKST_MASK));    /*FLLICS*/
	while(!(ICS->S & ICS_S_IREFST_MASK));  /*FLL*/

        
	/* 
	 * ICSFLL
	 */
#if defined(CPU_NV32)
         /*2*/
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif

        /*LOLS */
	ICS->S |= ICS_S_LOLS_MASK;	
}

/*****************************************************************************//*!
   *
   * @   ICSFBEFBI
   *        
   * @   pConfig    
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FBE_to_FBI(ICS_ConfigType *pConfig)
{
        /*FLL*/
	/*ICS*/
    ICS->C1 =  ICS->C1 | (ICS_C1_IREFS_MASK);
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK)) | ICS_C1_CLKS(1);   
	
        /**/
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(((ICS->S & ICS_S_CLKST_MASK) >> ICS_S_CLKST_SHIFT) != 1);/*ICS*/
	while(!(ICS->S & ICS_S_IREFST_MASK)); /*FLL*/
	
	/* 
	 * ICS
	 */
	 
#if defined(CPU_NV32)
        /*2*/
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif
        
    /* 
     * OSC
     */
    OSC_Disable();
}


/*****************************************************************************//*!
   *
   * @  ICSFBEFEE
   *        
   * @  pConfig   . 
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FBE_to_FEE(ICS_ConfigType *pConfig)
{
	
        /*FLL*/
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK));   
	
        /*ICS*/
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while(ICS->S & ICS_S_CLKST_MASK);

	
	/* 
    * ICSFLL
	 * :  <= 20MHz
	 */
#if defined(CPU_NV32)
         /*ICS2*/
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}	
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif	
         /* LOLS */
	ICS->S |= ICS_S_LOLS_MASK;	
}


/*****************************************************************************//*!
   *
   * @  ICSFBEFEI
   *        
   * @  pConfig     
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FBE_to_FEI(ICS_ConfigType *pConfig)
{
    /* FLL*/
	/*FLLICS*/

    ICS->C1 =  ICS->C1 | (ICS_C1_IREFS_MASK);
	ICS->C1 = (ICS->C1 & ~(ICS_C1_CLKS_MASK));   
	
        /**/
#if defined(IAR)        
	asm(
		"nop \n"
		"nop \n"
	);
#elif defined(__MWERKS__)
	asm{
		nop 
		nop
        };        
#endif     
	while((ICS->S & ICS_S_CLKST_MASK));   /*FLLICS*/
	while(!(ICS->S & ICS_S_IREFST_MASK)); /*FLL*/

  /* 
   * FLLICS
   */

#if defined(CPU_NV32)

       /*2*/	
	if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) != 1)
	{
		ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(1);
	}
#else
    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
#endif	
         /*LOLS*/
	ICS->S |= ICS_S_LOLS_MASK;	
        
    /*
     *OSC
     */
    OSC_Disable();
}

/*****************************************************************************//*!
   *
   * @  ICSFBEFBELP
   *
   * @   pConfig   . 
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FBE_to_FBELP(ICS_ConfigType *pConfig)
{
	/* enter low power mode */
        /**/
 	ICS->C2 = ICS->C2 | (ICS_C2_LP_MASK); 
}
/*****************************************************************************//*!
   *
   * @  ICSFBELPFBE
   * 
   * @   pConfig     . 
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FBELP_to_FBE(ICS_ConfigType *pConfig)
{
	/* enter low power mode */
        /**/
 	ICS->C2 = ICS->C2 & ~(ICS_C2_LP_MASK); 
}

/*****************************************************************************//*!
   *
   * @  ICSFBILPFBI 
   * 
   * @   pConfig  . 
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/
void FBILP_to_FBI(ICS_ConfigType *pConfig)
{
	/* enter low power mode */
        /**/
	ICS->C2 = ICS->C2 & ~(ICS_C2_LP_MASK); 
}

/*****************************************************************************//*!
   *
   * @   (IRC). 
   * 
   * @   u16TrimValue    
   *
   * @ 
   *
   * @ / 
   *****************************************************************************/

void ICS_Trim(uint16_t u16TrimValue)
{
   ICS->C3 =  (uint8_t) u16TrimValue;  /**/
   ICS->C4 = (ICS->C4 & ~(ICS_C4_SCFTRIM_MASK)) | ((u16TrimValue>>8) & 0x01);
   while(!(ICS->S & ICS_S_LOCK_MASK));    
}
/*****************************************************************************//*!
   *
   * @  FLL31.25k~39.0625k
   *
   * @  u32ClkFreqKHz    .
   *
   * @ 
   *
   * @ / 
   *****************************************************************************/

void ICS_SetClkDivider(uint32_t u32ClkFreqKHz)
{
    
    switch(u32ClkFreqKHz)
    {
        case 8000L:
        case 10000L:
            /* 8MHz or 10MHz*/
            ICS->C1 = (ICS->C1 & ~(ICS_C1_RDIV_MASK)) | ICS_C1_RDIV(3);	
                                                                         /*8MHz 8000/256 = 31.25K */ 
                                                                        /*10MHz 8000/256 = 31.25K*/ 
            break;
        case 4000L:
            /* 4MHz */
            ICS->C1 = (ICS->C1 & ~(ICS_C1_RDIV_MASK)) | ICS_C1_RDIV(2);	
                                                                        /*4MHz 4000/128 = 31.25K*/
            break;
        case 12000L:
            /* 12MHz */
            ICS->C1 = (ICS->C1 & ~(ICS_C1_RDIV_MASK)) | ICS_C1_RDIV(3);	
                                                                        /*12MHz12000/512 = 23.43K*/
            break;
        case 16000L:
            /* 16MHz */
            ICS->C1 = (ICS->C1 & ~(ICS_C1_RDIV_MASK)) | ICS_C1_RDIV(4);	
                                                                        /* 16MHz 16000/512 = 31.25K */
            break;
        case 20000L:
            /* 20MHz */
            ICS->C1 = (ICS->C1 & ~(ICS_C1_RDIV_MASK)) | ICS_C1_RDIV(4); 
                                                                        /*20MHz 20000/512 = 39.0625K */
            break;
        case 32L:
            /* 32KHz */
            ICS->C1  &= ~(ICS_C1_RDIV_MASK);
            break;
        default:
            break;
    }
}
/*****************************************************************************//*!
   *
   * @  ICS.
   * 
   * @  pConfig  .  
   *
   * @ 
   *
   * @ / 
   * @   ICS_ConfigType
   *****************************************************************************/


void ICS_Init(ICS_ConfigType *pConfig)
{
  if(pConfig->u8ClkMode == ICS_CLK_MODE_FEE)
  {    
        pConfig->oscConfig.bIsCryst = 1;   /* OSC */ 
        pConfig->oscConfig.bWaitInit = 1;  /*  */       
     
      /*FEEOSC*/
        FEI_to_FEE(pConfig);             
  }
  else if (pConfig->u8ClkMode == ICS_CLK_MODE_FEE_OSC)
  {     
        pConfig->oscConfig.bIsCryst = 0;     /*OSCEEXTAL*/ 

     /*FEEOSCEEXTAL*/
        FEI_to_FEE_OSC(pConfig);                
  }
  else if (pConfig->u8ClkMode == ICS_CLK_MODE_FBE_OSC)
  {
        pConfig->oscConfig.bIsCryst = 0;  /* is clockOSCEXTAL */            
        /* FBEOSCEXTAL*/
        FEI_to_FBE_OSC(pConfig);               
  } 
	else if(pConfig->u8ClkMode == ICS_CLK_MODE_FBELP )
	{
	pConfig->oscConfig.bIsCryst = 1;        /* OSC */
        pConfig->oscConfig.bWaitInit = 1;       /* */		

        /* FBEOSC*/
                    FEI_to_FBE(pConfig);    /*PBE*/            
		    FBE_to_FBELP(pConfig);   /*FBELP*/
		    ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
	}
		else if(pConfig->u8ClkMode == ICS_CLK_MODE_FBILP )
	{
       
            /* OSCEXTAL*/            
		    pConfig->oscConfig.bIsCryst = 0; 
     
            /* FBEOSCEXTAL*/
              FEI_to_FBI(pConfig);               
	      FBI_to_FBILP(pConfig); 
	      ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
	}
  else
  {
      
       /*ICSFEI*/
        #if defined(CPU_NV32)
        if(((ICS->C2 & ICS_C2_BDIV_MASK)>>5) == 1)
        {
            ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
        }
        #else
            ICS->C2 = (ICS->C2 & ~(ICS_C2_BDIV_MASK)) | ICS_C2_BDIV(0);
        #endif
  }

}
/*****************************************************************************//*!
   *
   * @  ICS.
   * 
   * @    
   *
   * @ 
   *
   * @ / 
   * @   ICS_Init
   *****************************************************************************/

void ICS_DeInit(void)
{
    ICS->C1 = ICS_C1_DEFAULT;
    ICS->C2 = ICS_C2_DEFAULT;
    ICS->C3 = ICS_C3_DEFAULT;
    ICS->C4 = ICS_C4_DEFAULT;
    while(ICS->S != ICS_S_DEFAULT)
        ;       
}

/*****************************************************************************//*!
   *
   * @  XOSC
   * 
   * @   pConfig   osc
   *
   * @ 
   *
   * @ / 
   *****************************************************************************/
void OSC_Init(OSC_ConfigType *pConfig)
{
	uint8   cr = 0;
	/* 
	 * 
	 */
	if(pConfig->bGain) /**/
	{
		/* high gain */
		cr |= OSC_CR_HGO_MASK ;		
	}  
	
	if(pConfig->bRange)  /**/
	{
		cr |= OSC_CR_RANGE_MASK; /* */	
	}

	if(pConfig->bStopEnable) /*OSC*/
	{
		cr |= OSC_CR_OSCSTEN_MASK; /*OSC*/
	}

	if(pConfig->bIsCryst)     /*OSC*/
	{
		cr |= OSC_CR_OSCOS_MASK; /**/
	}

	if(pConfig->bEnable)  /*OSC*/
	{
		cr |= OSC_CR_OSCEN_MASK;
	}
    
    OSC->CR = cr;   /**/
    
	if(pConfig->bWaitInit)
	{

		/* 
     *
		 */
		while(!(OSC->CR & OSC_CR_OSCINIT_MASK));
		
	}
}

/*****************************************************************************//*!
   *
   * @  OSC.
   * 
   * @       
   *
   * @ 
   *
   * @ / 
   * @    ICS_Init
   *****************************************************************************/

void OSC_DeInit(void)
{
    OSC->CR = OSC_CR_DEFAULT;
}
                                                	




