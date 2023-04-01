
# Memory pool

## 1. 

 (Memory Pool) malloc/free new/delete SDKTLSF

TLSF (Two-Level Segregated Fit memory allocator), 

- mallocfreereallocmemalignO(1)
- 4
- 
- 

TLSF(Two-Level Bitmap)(Segregated Free List)(memory pool)(free blocks)Good-Fit

TLSFmalloc

TLSF

## 2. 

FMemory Pool
- 
- 
- 
- 
- 
- 
- 


```
fmempory_pool
     fmempory_pool.c
     fmempory_pool.h
```

```
tlsf
     tlsf.c
     tlsf.h
```

## 3. 

 FMemory Pool :
- TLSF

## 4. 

### [memory pool](../../../baremetal/example/system/memory_pool_test)

## 5. API

### 5.1. 

- common/fmempory_pool.h

```c
typedef struct
{
    pool_t     pool_addr;
    FSListNode list;
} FMempPoolList; /*  */

typedef struct
{
    FMempPoolList *pools_list;   /*  */
    tlsf_t         tlsf_ptr;     /* tlsf */
    u32            is_ready;     /*  */
} FMemp; /*  */
```

### 5.2  

-  `0x0010000`

- [0x0] FMEMP_SUCCESS : success

- [0x0010000] FMEMP_ERR_INVALID_BUF : 

- [0x0010001] FMEMP_ERR_INIT_TLFS : TLFS

- [0x0010002] FMEMP_ERR_BAD_MALLOC : TLFS

### 5.3. API

#### FMempInit
- , 

```c
FError FMempInit(FMemp *memp, void *begin_addr, void *end_addr);
```

Note:

- begin_addr end_addr 

Input:

- {FMemp} *memp, 
- {void} *begin_addr, 
- {void} *end_addr, 

Return:

- {FError} FMEMP_SUCCESS

#### FMempRemove

- 

```c
void FMempRemove(FMemp *memp);
```

Note:

- 

Input:

- {FMemp} *memp    

Return:

- 

#### FMempMalloc

- 

```c
void *FMempMalloc(FMemp *memp, fsize_t nbytes);
```

Note:

- FMempFree

Input:

- {FMemp} *memp 
- {fsize_t} nbytes 

Return:

- {void *} NULL

#### FMempCalloc

- 

```c
void *FMempCalloc(FMemp *memp, fsize_t count, fsize_t size)
```

Note:

- FMempFree

Input:

- {FMemp} *memp 
- {fsize_t} count 
- {fsize_t} size 

Return:

- {void *} NULL

#### FMempMallocAlign

- 

```c
void *FMempMallocAlign(FMemp *memp, fsize_t size, fsize_t align);
```

Note:

- FMempFree

Input:

- {FMemp} *memp 
- {fsize_t} size 
- {fsize_t} align 

Return:

- {void *} NULL

#### FMempRealloc

- 

```c
void *FMempRealloc(FMemp *memp, void *ptr, fsize_t nbytes);
```

Note:

- FMempFree

Input:

- {FMemp} *memp 
- {void} *ptr 
- {fsize_t} nbytes 

Return:

- {void *} NULL

#### FMempFree

- 

```c
void FMempFree(FMemp *memp, void *ptr);
```

Note:

- FMempMalloc/FMempCalloc/FMempMallocAlign/FMempRealloc

Input:

- {FMemp} *memp 
- {void} *ptr 

Return:

- 

#### FMemProbe

- 

```c
void FMemProbe(FMemp *memp, u32 *total, u32 *used, u32 *max_used);
```

Note:

- 

Input:

- {FMemp} *memp 
- {u32} *total 
- {u32} *used 
- {u32} *max_used 

Return:

- 

#### FMemListAll

- 

```c
void FMemListAll(FMemp *memp);
```

Note:

- 

Input:

- {FMemp} *memp 

Return:

- 