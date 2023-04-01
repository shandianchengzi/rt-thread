# FSATA 

## 1. 

SATA(Serial ATA)PATA(Parallel ATA)
SATA

## 2. 

AHCISATA
- AHCI
- PIO/
- DMA/
- AHCI


```
fsata

     fsata_g.c
     fsata_hw.c
     fsata_hw.h
     fsata_intr.c
     fsata_sinit.c
     fsata.c
     fsata.h
```

## 3. 

 fsata :

- ahci
- sata

## 4 

### [sata](../../../baremetal/example/peripheral/sata)

### [sata](../../../baremetal/example/storage/sata_fatfs)

## 5. API

### 5.1. 

- fsata

```c
typedef struct
{
	FSataConfig config; 	/* sata */
	u32 is_ready;		/* sata */
	u32 private_data;
	FSataAhciIoPorts port[FSATA_AHCI_MAX_PORTS];
	u16 *ataid[FSATA_AHCI_MAX_PORTS];
	u32	n_ports;
	u32	cap;	/* cache of HOST_CAP register */
	u32	port_map; /* cache of HOST_PORTS_IMPL reg */
	u32	link_port_map; /*linkup port map*/
	
	FSataIrqCallBack fsata_dhrs_cb; /* device-to-host register fis interrupt */
    void *dhrs_args;
	FSataIrqCallBack fsata_pss_cb; /* pio setup fis interrupt */
    void *pss_args;
	FSataIrqCallBack fsata_dss_cb; /* dma setup fis interrupt */
    void *dss_args;
	FSataIrqCallBack fsata_sdbs_cb; /* set device bits interrupt */
    void *sdbs_args;
	FSataIrqCallBack fsata_pcs_cb; /* port connect change status interrupt */
    void *pcs_args;
} FSataCtrl;
```

- fsata

```c
typedef struct
{
	uintptr base_addr; /* sata */
	const char *instance_name; /* instance name */
	u32 irq_num;     /* Irq number */
} FSataConfig; /* sata */
```

- fsata port memmory
```c
typedef struct
{
	uintptr	port_mmio;
	FSataAhciCommandList *cmd_list; /*  Command List structure, will include cmd_tbl's address */
	uintptr cmd_tbl_base_addr; /* command table addr, also the command table's first part */
	FSataAhciCommandTablePrdt *cmd_tbl_prdt;	/* command table's second part , cmd_tbl + cmd_tbl_prdt = command table*/
	FSataAhciRecvFis *rx_fis;	/* Received FIS Structure */
	uintptr mem;
	FSataInfo dev_info;
} FSataAhciIoPorts;
```

- fsata
```c
typedef struct
{
	unsigned char if_type;		/* type of the interface */
	unsigned char part_type;	/* partition type */
	unsigned char type;		/* device type */
	unsigned char removable;	/* removable device */
	char vendor[BLK_VEN_SIZE + 1]; /* device vendor string */
	char product[BLK_PRD_SIZE + 1]; /* device product number */
	char revision[BLK_REV_SIZE + 1]; /* firmware revision */
	unsigned long lba;		/* number of blocks */
	unsigned long blksz;		/* block size */

}FSataInfo;
```

- fsata
```c
#define	FSATA_PORT_IRQ_COLD_PRES	BIT(31) /* cold presence detect */
#define	FSATA_PORT_IRQ_TF_ERR		BIT(30) /* task file error */
#define	FSATA_PORT_IRQ_HBUS_ERR	    BIT(29) /* host bus fatal error */
#define	FSATA_PORT_IRQ_HBUS_DATA_ERR	BIT(28) /* host bus data error */
#define	FSATA_PORT_IRQ_IF_ERR		BIT(27) /* interface fatal error */
#define	FSATA_PORT_IRQ_IF_NONFATAL	BIT(26) /* interface non-fatal error */
#define	FSATA_PORT_IRQ_OVERFLOW	    BIT(24) /* xfer exhausted available S/G */
#define	FSATA_PORT_IRQ_BAD_PMP	    BIT(23) /* incorrect port multiplier */

#define	FSATA_PORT_IRQ_PHYRDY		BIT(22) /* PhyRdy changed */
#define	FSATA_PORT_IRQ_DEV_ILCK	    BIT(7) /* device interlock */
#define	FSATA_PORT_IRQ_CONNECT	    BIT(6) /* port connect change status */
#define	FSATA_PORT_IRQ_SG_DONE	    BIT(5) /* descriptor processed */
#define	FSATA_PORT_IRQ_UNK_FIS	    BIT(4) /* unknown FIS rx'd */
#define	FSATA_PORT_IRQ_SDB_FIS	    BIT(3) /* Set Device Bits FIS rx'd */
#define	FSATA_PORT_IRQ_DMAS_FIS	    BIT(2) /* DMA Setup FIS rx'd */
#define	FSATA_PORT_IRQ_PIOS_FIS	    BIT(1) /* PIO Setup FIS rx'd */
#define	FSATA_PORT_IRQ_D2H_REG_FIS	BIT(0) /* D2H Register FIS rx'd */
```

### 5.2  

- FSATA_SUCCESS : success
- FSATA_ERR_INVAILD_PARAMETER : 
- FSATA_ERR_TIMEOUT : 
- FSATA_ERR_OPERATION : 
- FSATA_UNKNOWN_DEVICE : 

### 5.3. API

#### FSataLookupConfig

- Fata

```c
const FSataConfig *FSataLookupConfig(void);
```

Note:

- instance_name

Input:

- {void} 

Return:

- {const FSataConfig *}  fsataNULL

#### FSataCfgInitialize

- fsata, 

```c
FError FSataCfgInitialize(FSataCtrl *instance_p, const FSataConfig *input_config_p);
```

Note:

- FSataLookupConfig

Input:

- {FSataCtrl} *instance_p fsata
- {FSataConfig} *input_config_p fsata

Return:

- {FError} FSATA_SUCCESS 

#### FSataAhciInit

- ahci, 

```c
FError FSataAhciInit(FSataCtrl *instance_p);
```

Note:

- ahciport memorymem

Input:

- {FSataCtrl} *instance_p fsata

Return:

- {FError} FSATA_SUCCESS 


#### FSataAhciReadInfo

- sata

```c
FError FSataAhciReadInfo(FSataCtrl *instance_p, u8 port);
```

Note:

- FSataLookupConfig

Input:

- {FSataCtrl} *instance_p fsata
- {u8} port fsataport

Return:

- {FError} FSATA_SUCCESS 

#### FSataReadWrite

- piosata

```c
FError FSataReadWrite(FSataCtrl *instance_p, u8 port, u32 start,
					  u16 blk_cnt, u8 *buffer, u8 is_write);
```

Note:

- piosatabuffer

Input:

- {FSataCtrl} *instance_p fsata
- {u8} port fsataport
- {u32} start block
- {u16} blk_cnt block
- {u8} *buffer 
- {u8} is_write /

Return:

- {FError} FSATA_SUCCESS 

#### FSataFPDmaReadWrite

- dmasata

```c
FError FSataFPDmaReadWrite(FSataCtrl *instance_p, u8 port, u32 start,
					  u16 blk_cnt, u8 *buffer, u8 is_write);
```

Note:

- dmasatabuffer

Input:

- {FSataCtrl} *instance_p fsata
- {u8} port fsataport
- {u32} start block
- {u16} blk_cnt block
- {u8} *buffer 
- {u8} is_write /

Return:

- {FError} FSATA_SUCCESS 

/* set specific sata irq function entry */
FError FSataSetHandler(FSataCtrl *instance_p, u32 handler_type,
					   void *func_pointer, void *call_back_ref);


#### FSataSetHandler

- 

```c
FError FSataSetHandler(FSataCtrl *instance_p, u32 handler_type,
					   void *func_pointer, void *call_back_ref);
```

Note:

- 

Input:

- {FSataCtrl} *instance_p fsata
- {u32} handler_type 
- {void} *func_pointer 
- {void} *call_back_ref 

Return:

- {FError} FSATA_SUCCESS 
