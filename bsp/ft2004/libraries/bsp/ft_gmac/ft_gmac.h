/*
*@:Copyright(c)2021PhytiumInformationTechnology,Inc.
*
*SPDX-License-Identifier:Apache-2.0.
*
 * @Date: 2021-04-07 09:53:07
 * @LastEditTime: 2021-05-24 14:32:56
 * @Description: This files is for
 *
 * @ModifyHistory:
 *  VerWhoDateChanges
 * ---------------------------------------------------------
 * 1.00a hh  2021-02-05 First release
 */

#ifndef FT_GMAC_H
#define FT_GMAC_H

#include "ft_types.h"
#define GMAC_INC_DESC(x, y) (x) = (((x) + 1) % y)
/**
 * @name: Callback invoked when frame(s) have been sent or received in interrupt
 *          driven DMA mode .to set the send callback ,invoke FGmac_SetHandler()
 * @msg:
 * @param {void} *CallBackRef
 * @return {*}
 */
typedef void (*FGmac_IntrCallback_t)(void *CallBackRef);

/**
 * @name:  FGmac_ErrIntrCallback_t
 * @msg:   Callback whem asynchronous error occurs. To set this callback, invoke
 *          FGmac_ErrIntrCallback_t .
 * @param {void} *CallBackRef
 * @param {u32} ErrorWord  definition varies with Error
 * @return {*}
 */
typedef void (*FGmac_ErrIntrCallback_t)(void *CallBackRef, u32 ErrorWord);

/**
 *
 *
 */
typedef void (*Ft_Gmac_MacPhyStatus_Callback)(void *CallBackRef, u32 MacPhyStatus);

/** GMAC_SPEED   */
#define GMAC_SPEED_10M 0x00000001U
#define GMAC_SPEED_100M 0x00000002U
#define GMAC_SPEED_1000M 0x00000004U

#define IS_RIGHT_SPEED()

/* GMAC_AutoNegotiation */
#define GMAC_AUTONEGOTIATION_ENABLE 0x00000001U
#define GMAC_AUTONEGOTIATION_DISABLE 0x00000000U

/* GMAC_Duplex_Mode */
#define GMAC_MODE_FULLDUPLEX 0x00000001U
#define GMAC_MODE_HALFDUPLEX 0x00000000U

/* GMAC_Rx_Mode */
#define GMAC_RXPOLLING_MODE 0x00000000U
#define GMAC_RXINTERRUPT_MODE 0x00000001U

/* GMAC_Checksum_Mode */
#define GMAC_CHECKSUM_BY_SOFTWARE 0x00000000U
#define GMAC_CHECKSUM_BY_HARDWARE 0x00000001U

/* GMAC_Media_Interface */
#define GMAC_MEDIA_INTERFACE_RGMII 0x00000000U
#define GMAC_MEDIA_INTERFACE_MII 0x00000001U

/* Gmac Error value */

#define GMAC_ERROR_TRANSMIT_PROCESS_STOPPED 0x00000001U
#define GMAC_ERROR_TRANSMIT_UNAVAILABLE_STATUS 0x00000002U
#define GMAC_ERROR_TRANSMIT_JABBER_TIMEOUT 0x00000004U
#define GMAC_ERROR_RECEIVE_FIFO_OVERFLOW 0x00000008U
#define GMAC_ERROR_TRANSMIT_UNDERFLOW 0x00000010U
#define GMAC_ERROR_RECEIVE_BUFFER_UNAVAILABLE 0x00000020U
#define GMAC_ERROR_RECEIVE_PROCESS_STOPPED 0x00000040U
#define GMAC_ERROR_RECEIVE_WATCHDOG_TIMEOUT 0x00000080U
#define GMAC_ERROR_EARLY_TRANSMIT_INTERRUPT 0x000000100U
#define GMAC_ERROR_FATAL_BUS_ERROR 0x000000200U
#define GMAC_ERROR_UNDEFINED 0x000000400U

typedef enum
{
    FT_GMAC_TX_COMPLETE_CB_ID = 0x01U,    /*!< Gmac Tx Complete Callback ID        */
    FT_GMAC_RX_COMPLETE_CB_ID = 0x02U,    /*!< Gmac Rx Complete Callback ID        */
    FT_GMAC_DMA_ERROR_CB_ID = 0x03U,      /*!< Gmac DMA Error Callback ID          */
    FT_GMAC_MAC_PHY_STATUS_CB_ID = 0x04U, /*!<           */
} FGmac_IsrCallbackSelect_t;

/* Gmac DMA Descriptors data structure definition */

typedef struct
{
    volatile u32 Status;     /*!< Status */
    u32 Control;             /*!< Control and Buffer1, Buffer2 lengths */
    u32 Buffer1Addr;         /*!< Buffer1 address pointer */
    u32 Buffer2NextDescAddr; /*!< Buffer2 or next descriptor address pointer */
} FGmac_DmaDesc_t;

/*  Received Frame Informations structure definition */
typedef struct
{
    FGmac_DmaDesc_t *FSRxDesc; /*!< First Segment Rx Desc */
    FGmac_DmaDesc_t *LSRxDesc; /*!< Last Segment Rx Desc */
    u32 SegCount;              /*!< Segment count */
    u32 length;                /*!< Frame length */
    u32 buffer;                /*!< Frame buffer */
} FGmac_DmaRxFrameInfos;

typedef struct
{
    u32 InstanceId;          /* Id of device */
    uintptr_t CommonAddress; /* Gmac Common Register */
    uintptr_t BaseAddress;   /* Physical base address of Mac Private Address */
    u32 IRQ_NUM;
    u32 IRQPriority;
    s32 PhyAddr;         /* Phy Ic Addre1 ,-1 is need to auto check*/
    u32 clkMDC;          /* MDC clock access PHY. [1.0MHz ~2.5MHz] */
    u32 AutoNegotiation; /* Selects or not the AutoNegotiation mode for the external PHY
                                                           The AutoNegotiation allows an automatic setting of the Speed (10/100/1000Mbps)
                                                           and the mode (half/full-duplex).
                                                           This parameter can be a value of @ref GMAC_AutoNegotiation */
    u32 Speed;           /* Sets the Ethernet speed: 10/100/1000 Mbps.
                                                           This parameter can be a value of @ref GMAC_SPEED */
    u32 DuplexMode;      /* Selects the MAC duplex mode: Half-Duplex or Full-Duplex mode
                                                           This parameter can be a value of @ref GMAC_Duplex_Mode */
    u32 RxMode;          /* Selects the Ethernet Rx mode: Polling mode, Interrupt mode.
                                                           This parameter can be a value of @ref GMAC_Rx_Mode */
    u32 ChecksumMode;    /* Selects if the checksum is check by hardware or by software.
                                                         This parameter can be a value of @ref GMAC_Checksum_Mode */
    u32 MediaInterface;  /* Selects the media-independent interface or the reduced media-independent interface.
                                                         This parameter can be a value of @ref GMAC_Media_Interface */
    u8 MacAddr[6];       /* 6 bytes Mac address */

} FGmac_Config_t;

/* Only for Dma ring structure */
struct DescRingData
{
    u32 DescIndex;     /* For Current Desc position */
    u32 DescBufIndex;  /* For Current Desc buffer buf position */
    u32 DescMaxNumber; /* Max Number for  Desc and Desc buffer */
    u8 *DescBufBase;   /*  Desc buffer Base */
};

typedef struct
{
    FGmac_Config_t Config; /* Hardware configuration */
    u32 IsReady;           /* Device is initialised and ready */
    u32 Options;           /* Current options word  */

    FGmac_DmaDesc_t *RxDesc; /*!< Rx descriptor to Get   */
    struct DescRingData RxDescRingData;
    FGmac_DmaDesc_t *TxDesc; /*!< Tx descriptor to Set   */
    struct DescRingData TxDescRingData;

    FGmac_IntrCallback_t SendHandler;
    FGmac_IntrCallback_t RecvHandler;
    Ft_Gmac_MacPhyStatus_Callback StatusHandler;
    void *SendArgs;
    void *RecvArgs;
    void *StatusArgs;
    FGmac_ErrIntrCallback_t ErrorHandler;
    void *ErrorArgs;

    FGmac_DmaRxFrameInfos DMARxFrameInfos; /* Only for chain structure */

} Ft_Gmac_t;

/**
 * @name: FGmac_DmaRxDescRingInit
 * @msg:   DMA  ring
 * @param {Ft_Gmac_t} *Gmac  Gmac
 * @param {FGmac_DmaDesc_t} *DMARxDescTab  DMA 
 * @param {u8} *RxBuff  DMA 
 * @param {u32} DescBufPerLength 
 * @param {u32} RxBuffCount 
 * @return {s32} Common_status 
 */
s32 FGmac_DmaRxDescRingInit(Ft_Gmac_t *Gmac,
                            FGmac_DmaDesc_t *DMATxDescTab,
                            u8 *TxBuff,
                            u32 DescBufPerLength,
                            u32 TxBuffCount);

/**
 * @name: FGmac_DmaTxDescRingInit
 * @msg:   DMA  ring
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @param {FGmac_DmaDesc_t} *DMATxDescTab  DMA 
 * @param {u8} *TxBuff   DMA 
 * @param {u32} DescBufPerLength 
 * @param {u32} TxBuffCount 
 * @return {s32} Common_status 
 */
s32 FGmac_DmaTxDescRingInit(Ft_Gmac_t *Gmac,
                            FGmac_DmaDesc_t *DMATxDescTab,
                            u8 *TxBuff,
                            u32 DescBufPerLength,
                            u32 TxBuffCount);

/**
 * @name: FGmac_TransmitframeRingPoll
 * @msg:  DMA
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @param {uint32_t} FrameLength 
 * @return {s32} Common_status 
 */
s32 FGmac_TransmitframeRingPoll(Ft_Gmac_t *Gmac, uint32_t FrameLength);

/**
 * @name: FGmac_RingGetReceivedFrame_IT
 * @msg:  ringDMA
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @return {s32} Common_status 
 */
s32 FGmac_RingGetReceivedFrame_IT(Ft_Gmac_t *Gmac);

/**
 * @name: FGmac_ResumeTransmission
 * @msg:   DMA_STATUS_TU DMA  
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @return {void}
 */
void FGmac_ResumeTransmission(Ft_Gmac_t *Gmac);

/**
 * @name: FGmac_SetTransmitUnderflow
 * @msg:   DMA_STATUS_UNF DMA  
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @return {void}
 */
void FGmac_SetTransmitUnderflow(Ft_Gmac_t *Gmac);

/**
 * @name: FGmac_ResumeTransmissionReception
 * @msg:   DMA_STATUS_RU DMA  
 * @param {Ft_Gmac_t} *Gmac
 * @return {void}
 */
void FGmac_ResumeTransmissionReception(Ft_Gmac_t *Gmac);

/**
 * @name: Ft_Gmac_LookupConfig
 * @msg:   Gmac  
 * @param {u32} InstanceId Gmac 
 * @return {FGmac_Config_t *} Gmac
 */
FGmac_Config_t *Ft_Gmac_LookupConfig(u32 InstanceId);

/**
 * @name: Ft_Gmac_HwInitialize
 * @msg:  Gmac Mac  Phy 
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @return {s32} Common_status 
 */
s32 Ft_Gmac_HwInitialize(Ft_Gmac_t *Gmac);

/**
 * @name: Ft_GmacCfgInitialize
 * @msg:  
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @param {FGmac_Config_t} *Config
 * @return {s32} Common_status 
 */
s32 Ft_GmacCfgInitialize(Ft_Gmac_t *Gmac, FGmac_Config_t *Config);

/**
 * @name: Ft_Gmac_Start
 * @msg:  Gmac  
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @return {s32}  Common_status 
 */
s32 Ft_Gmac_Start(Ft_Gmac_t *Gmac);

/**
 * @name: Ft_Gmac_Stop
 * @msg:  Gmac  
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @return {s32} Common_status 
 */
s32 Ft_Gmac_Stop(Ft_Gmac_t *Gmac);

/**
 * @name: FGmac_IntrHandler
 * @msg:  Gmac Gmac 
 * @param {void} *Args Ft_Gmac_t *Gmac 
 * @return {void}
 */
void FGmac_IntrHandler(void *Args);

/**
 * @name: FGmac_SetHandler
 * @msg:  SelectIndex  
 * @param {Ft_Gmac_t} *Gmac Gmac
 * @param {FGmac_IsrCallbackSelect_t} SelectIndex
 * @param {void} *FuncPtr
 * @param {void} *Args
 * @return {s32} Common_status 
 */
s32 FGmac_SetHandler(Ft_Gmac_t *Gmac, FGmac_IsrCallbackSelect_t SelectIndex, void *FuncPtr, void *Args);

void Ft_Gmac_Phy_Debug(Ft_Gmac_t *Gmac);

/**
 * @name: Ft_Gmac_UseDefaultMacAddr
 * @msg:  ubootMac0
 * @in param{Ft_Gmac_t *}:  Gmac
 * @out param{u8 *}:  Mac
 * @return {None}:
 */
void Ft_Gmac_UseDefaultMacAddr(Ft_Gmac_t *Gmac, u8 *MacAddr);

#endif // !GMAC_H
