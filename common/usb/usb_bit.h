#ifndef _USB_HW_BIT
#define _USB_HW_BIT

#define PERIPH_BASE           ((uint32_t)0x40000000U)      /*!< Peripheral base address */
#define APB1PERIPH_BASE        PERIPH_BASE
#define USB_BASE              (APB1PERIPH_BASE + 0x6800U)  /*!< USB_IP Peripheral Registers base address */
#define USB_PMAADDR           (APB1PERIPH_BASE + 0x6C00U)  /*!< USB_IP Packet Memory Area base address */


/* bit positions */
#define USB_EP_CTR_RX                            ((uint16_t)0x8000U)           /*!<  EndPoint Correct TRansfer RX */
#define USB_EP_DTOG_RX                           ((uint16_t)0x4000U)           /*!<  EndPoint Data TOGGLE RX */
#define USB_EPRX_STAT                            ((uint16_t)0x3000U)           /*!<  EndPoint RX STATus bit field */
#define USB_EP_SETUP                             ((uint16_t)0x0800U)           /*!<  EndPoint SETUP */
#define USB_EP_T_FIELD                           ((uint16_t)0x0600U)           /*!<  EndPoint TYPE */
#define USB_EP_KIND                              ((uint16_t)0x0100U)           /*!<  EndPoint KIND */
#define USB_EP_CTR_TX                            ((uint16_t)0x0080U)           /*!<  EndPoint Correct TRansfer TX */
#define USB_EP_DTOG_TX                           ((uint16_t)0x0040U)           /*!<  EndPoint Data TOGGLE TX */
#define USB_EPTX_STAT                            ((uint16_t)0x0030U)           /*!<  EndPoint TX STATus bit field */
#define USB_EPADDR_FIELD                         ((uint16_t)0x000FU)           /*!<  EndPoint ADDRess FIELD */

/* EndPoint REGister MASK (no toggle fields) */
#define USB_EPREG_MASK     (USB_EP_CTR_RX|USB_EP_SETUP|USB_EP_T_FIELD|USB_EP_KIND|USB_EP_CTR_TX|USB_EPADDR_FIELD)
                                                                         /*!< EP_TYPE[1:0] EndPoint TYPE */
#define USB_EP_TYPE_MASK                         ((uint16_t)0x0600U)           /*!< EndPoint TYPE Mask */
#define USB_EP_BULK                              ((uint16_t)0x0000U)           /*!< EndPoint BULK */
#define USB_EP_CONTROL                           ((uint16_t)0x0200U)           /*!< EndPoint CONTROL */
#define USB_EP_ISOCHRONOUS                       ((uint16_t)0x0400U)           /*!< EndPoint ISOCHRONOUS */
#define USB_EP_INTERRUPT                         ((uint16_t)0x0600U)           /*!< EndPoint INTERRUPT */
#define USB_EP_T_MASK                        ((uint16_t) ~USB_EP_T_FIELD & USB_EPREG_MASK)

#define USB_EPKIND_MASK                      ((uint16_t)~USB_EP_KIND & USB_EPREG_MASK) /*!< EP_KIND EndPoint KIND */
                                                                         /*!< STAT_TX[1:0] STATus for TX transfer */
#define USB_EP_TX_DIS                            ((uint16_t)0x0000U)           /*!< EndPoint TX DISabled */
#define USB_EP_TX_STALL                          ((uint16_t)0x0010U)           /*!< EndPoint TX STALLed */
#define USB_EP_TX_NAK                            ((uint16_t)0x0020U)           /*!< EndPoint TX NAKed */
#define USB_EP_TX_VALID                          ((uint16_t)0x0030U)           /*!< EndPoint TX VALID */
#define USB_EPTX_DTOG1                           ((uint16_t)0x0010U)           /*!< EndPoint TX Data TOGgle bit1 */
#define USB_EPTX_DTOG2                           ((uint16_t)0x0020U)           /*!< EndPoint TX Data TOGgle bit2 */
#define USB_EPTX_DTOGMASK  (USB_EPTX_STAT|USB_EPREG_MASK)
                                                                         /*!< STAT_RX[1:0] STATus for RX transfer */
#define USB_EP_RX_DIS                            ((uint16_t)0x0000U)           /*!< EndPoint RX DISabled */
#define USB_EP_RX_STALL                          ((uint16_t)0x1000U)           /*!< EndPoint RX STALLed */
#define USB_EP_RX_NAK                            ((uint16_t)0x2000U)           /*!< EndPoint RX NAKed */
#define USB_EP_RX_VALID                          ((uint16_t)0x3000U)           /*!< EndPoint RX VALID */
#define USB_EPRX_DTOG1                           ((uint16_t)0x1000U)           /*!< EndPoint RX Data TOGgle bit1 */
#define USB_EPRX_DTOG2                           ((uint16_t)0x2000U)           /*!< EndPoint RX Data TOGgle bit1 */
#define USB_EPRX_DTOGMASK  (USB_EPRX_STAT|USB_EPREG_MASK)


#define UID_BASE              ((uint32_t)0x1FFF7590U)        /*!< Unique device ID register base address */

#endif // _USB_HW_BIT

