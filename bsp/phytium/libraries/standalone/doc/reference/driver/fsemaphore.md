# FSemaphore 

## 1. 

SemaphoreE2000 32  UNLOCK  LOCKED 

## 2. 

FSemaphore  Semaphore 

```
fsemaphore
    .
     fsemaphore.c
     fsemaphore.h
     fsemaphore_g.c
     fsemaphore_hw.h
     fsemaphore_sinit.c
```

## 3. 

 FSemaphore :

-  Semaphore 
-  Semaphore 
- /

## 4. 

### [Semaphore](../../../baremetal/example/peripheral/ipc/fsemaphore_test)

## 5. API


### 5.1. 

#### FSemaConfig

- Semaphore

```c
typedef struct 
{
    u32 id;             /* Semaphoreid */
    uintptr base_addr;  /* Semaphore */
} FSemaConfig; /* Semaphore */
```

#### FSemaLocker

- Semaphore

```c
typedef struct
{
    u32 index;                              /* Semaphoreid */
#define FSEMA_LOCKER_NAME_LEN       32U
    char name[FSEMA_LOCKER_NAME_LEN];       /* Semaphore */
    u32 owner;                              /* Semaphore */
    FSema *sema;                            /* Semaphore */
} FSemaLocker; /* Semaphore */
```

#### FSema

- Semaphore

```c
typedef struct _FSema
{
    FSemaConfig config;                       /* Semaphore */
    u32 is_ready;                             /* Semaphore */
    FSemaLocker *locker[FSEMA_NUM_OF_LOCKER]; /* Semaphorelocker[i] == NULL  */
} FSema; /* Semaphore */
```
### 5.2  

FSEMA_SUCCESS                    
FSEMA_ERR_NOT_INIT              
FSEMA_ERR_NO_AVAILABLE_LOCKER   
FSEMA_ERR_LOCK_TIMEOUT          
FSEMA_ERR_NO_PERMISSION         

### 5.3. API

#### FSemaLoopkupConfig

```c
const FSemaConfig *FSemaLoopkupConfig(u32 instance_id)
```

Note:

- Semaphore

Input:

- {u32} instance_id, Semaphoreid

Return:

- {const FSemaConfig *} Semaphore

#### FSemaCfgInitialize

```c
FError FSemaCfgInitialize(FSema *const instance, const FSemaConfig *input_config)
```

Note:

- Semaphore

Input:

- {FSema} *instance, Semaphore
- {FSemaConfig} *input_config, Semaphore

Return:

- {FError} FSEMA_SUCCESS 

#### FSemaDeInitialize

```c
void FSemaDeInitialize(FSema *const instance)
```

Note:

- Semaphore

Input:

- {FSema} *instance, Semaphore

Return:

- 

#### FSemaCreateLocker

```c
FError FSemaCreateLocker(FSema *const instance, FSemaLocker *const locker)
```

Note:

- Semaphore

Input:

- {FSema} *instance, Semaphore
- {FSemaLocker} *locker, Semaphore

Return:

- {FError} FSEMA_SUCCESS 

#### FSemaDeleteLocker

```c
FError FSemaDeleteLocker(FSemaLocker *const locker)
```

Note:

- Semaphore

Input:

- {FSemaLocker} *locker, Semaphore

Return:

- {FError} FSEMA_SUCCESS 

#### FSemaTryLock

```c
FError FSemaTryLock(FSemaLocker *const locker, u32 owner, u32 try_times, FSemaRelaxHandler relax_handler)
```

Note:

- Semaphore

Input:

- {FSemaLocker} *locker, Semaphore
- {u32} owner, 
- {u32} try_times, 
- {FSemaRelaxHandler} relax_handler, relax

Return:

- {FError} FSEMA_SUCCESS FSEMA_ERR_LOCK_TIMEOUT 

#### FSemaUnlock

```c
FError FSemaUnlock(FSemaLocker *const locker, u32 owner)
```

Note:

- Semaphore

Input:

- {FSemaLocker} *locker, Semaphore
- {u32} owner, 

Return:

- {FError} FSEMA_SUCCESS

#### FSemaUnlockAll

```c
FError FSemaUnlockAll(FSema *const instance)
```

Note:

- Semaphore

Input:

- {FSema} *instance, Semaphore

Return:

- {FError} FSEMA_SUCCESS

#### FSemaIsLocked

```c
boolean FSemaIsLocked(FSemaLocker *locker)
```

Note:

- Semaphore

Input:

- {FSemaLocker} *locker, Semaphore

Return:

- {boolean} TRUE: 

