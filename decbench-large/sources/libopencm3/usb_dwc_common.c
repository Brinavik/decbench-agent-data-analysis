#define LIBOPENCM3_CM3_COMMON_H 
#define BEGIN_DECLS 
#define END_DECLS 






#define LIBOPENCM3_DEPRECATED(x) __attribute__((deprecated(x)))


#define MMIO8(addr) (*(volatile uint8_t *)(addr))
#define MMIO16(addr) (*(volatile uint16_t *)(addr))
#define MMIO32(addr) (*(volatile uint32_t *)(addr))
#define MMIO64(addr) (*(volatile uint64_t *)(addr))


#define BBIO_SRAM(addr,bit) MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x22000000 + (bit) * 4)


#define BBIO_PERIPH(addr,bit) MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x42000000 + (bit) * 4)




#define BIT0 (1<<0)
#define BIT1 (1<<1)
#define BIT2 (1<<2)
#define BIT3 (1<<3)
#define BIT4 (1<<4)
#define BIT5 (1<<5)
#define BIT6 (1<<6)
#define BIT7 (1<<7)
#define BIT8 (1<<8)
#define BIT9 (1<<9)
#define BIT10 (1<<10)
#define BIT11 (1<<11)
#define BIT12 (1<<12)
#define BIT13 (1<<13)
#define BIT14 (1<<14)
#define BIT15 (1<<15)
#define BIT16 (1<<16)
#define BIT17 (1<<17)
#define BIT18 (1<<18)
#define BIT19 (1<<19)
#define BIT20 (1<<20)
#define BIT21 (1<<21)
#define BIT22 (1<<22)
#define BIT23 (1<<23)
#define BIT24 (1<<24)
#define BIT25 (1<<25)
#define BIT26 (1<<26)
#define BIT27 (1<<27)
#define BIT28 (1<<28)
#define BIT29 (1<<29)
#define BIT30 (1<<30)
#define BIT31 (1<<31)
#define __USBD_H 

#define __USBSTD_H 

struct usb_setup_data {
 uint8_t bmRequestType;
 uint8_t bRequest;
 uint16_t wValue;
 uint16_t wIndex;
 uint16_t wLength;
} __attribute__((packed));


#define USB_CLASS_VENDOR 0xFF



#define USB_REQ_TYPE_DIRECTION 0x80
#define USB_REQ_TYPE_IN 0x80
#define USB_REQ_TYPE_OUT 0x0

#define USB_REQ_TYPE_TYPE 0x60
#define USB_REQ_TYPE_STANDARD 0x00
#define USB_REQ_TYPE_CLASS 0x20
#define USB_REQ_TYPE_VENDOR 0x40

#define USB_REQ_TYPE_RECIPIENT 0x1F
#define USB_REQ_TYPE_DEVICE 0x00
#define USB_REQ_TYPE_INTERFACE 0x01
#define USB_REQ_TYPE_ENDPOINT 0x02
#define USB_REQ_TYPE_OTHER 0x03


#define USB_REQ_GET_STATUS 0
#define USB_REQ_CLEAR_FEATURE 1

#define USB_REQ_SET_FEATURE 3

#define USB_REQ_SET_ADDRESS 5
#define USB_REQ_GET_DESCRIPTOR 6
#define USB_REQ_SET_DESCRIPTOR 7
#define USB_REQ_GET_CONFIGURATION 8
#define USB_REQ_SET_CONFIGURATION 9
#define USB_REQ_GET_INTERFACE 10
#define USB_REQ_SET_INTERFACE 11
#define USB_REQ_SET_SYNCH_FRAME 12


#define USB_DT_DEVICE 1
#define USB_DT_CONFIGURATION 2
#define USB_DT_STRING 3
#define USB_DT_INTERFACE 4
#define USB_DT_ENDPOINT 5
#define USB_DT_DEVICE_QUALIFIER 6
#define USB_DT_OTHER_SPEED_CONFIGURATION 7
#define USB_DT_INTERFACE_POWER 8

#define USB_DT_OTG 9
#define USB_DT_DEBUG 10
#define USB_DT_INTERFACE_ASSOCIATION 11


#define USB_FEAT_ENDPOINT_HALT 0
#define USB_FEAT_DEVICE_REMOTE_WAKEUP 1
#define USB_FEAT_TEST_MODE 2


#define USB_DEV_STATUS_SELF_POWERED 0x01
#define USB_DEV_STATUS_REMOTE_WAKEUP 0x02


struct usb_device_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t bcdUSB;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
 uint8_t bMaxPacketSize0;
 uint16_t idVendor;
 uint16_t idProduct;
 uint16_t bcdDevice;
 uint8_t iManufacturer;
 uint8_t iProduct;
 uint8_t iSerialNumber;
 uint8_t bNumConfigurations;
} __attribute__((packed));

#define USB_DT_DEVICE_SIZE sizeof(struct usb_device_descriptor)




struct usb_device_qualifier_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t bcdUSB;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
 uint8_t bMaxPacketSize0;
 uint8_t bNumConfigurations;
 uint8_t bReserved;
} __attribute__((packed));




struct usb_interface {
 uint8_t *cur_altsetting;
 uint8_t num_altsetting;
 const struct usb_iface_assoc_descriptor *iface_assoc;
 const struct usb_interface_descriptor *altsetting;
};


struct usb_config_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t wTotalLength;
 uint8_t bNumInterfaces;
 uint8_t bConfigurationValue;
 uint8_t iConfiguration;
 uint8_t bmAttributes;
 uint8_t bMaxPower;


 const struct usb_interface *interface;
} __attribute__((packed));
#define USB_DT_CONFIGURATION_SIZE 9


#define USB_CONFIG_ATTR_DEFAULT 0x80
#define USB_CONFIG_ATTR_SELF_POWERED 0x40
#define USB_CONFIG_ATTR_REMOTE_WAKEUP 0x20






struct usb_interface_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bInterfaceNumber;
 uint8_t bAlternateSetting;
 uint8_t bNumEndpoints;
 uint8_t bInterfaceClass;
 uint8_t bInterfaceSubClass;
 uint8_t bInterfaceProtocol;
 uint8_t iInterface;


 const struct usb_endpoint_descriptor *endpoint;
 const void *extra;
 int extralen;
} __attribute__((packed));
#define USB_DT_INTERFACE_SIZE 9


struct usb_endpoint_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bEndpointAddress;
 uint8_t bmAttributes;
 uint16_t wMaxPacketSize;
 uint8_t bInterval;


 const void *extra;
 int extralen;
} __attribute__((packed));
#define USB_DT_ENDPOINT_SIZE 7


#define USB_ENDPOINT_ADDR_OUT(x) (x)
#define USB_ENDPOINT_ADDR_IN(x) (0x80 | (x))



#define USB_ENDPOINT_ATTR_CONTROL 0x00
#define USB_ENDPOINT_ATTR_ISOCHRONOUS 0x01
#define USB_ENDPOINT_ATTR_BULK 0x02
#define USB_ENDPOINT_ATTR_INTERRUPT 0x03
#define USB_ENDPOINT_ATTR_TYPE 0x03

#define USB_ENDPOINT_ATTR_NOSYNC 0x00
#define USB_ENDPOINT_ATTR_ASYNC 0x04
#define USB_ENDPOINT_ATTR_ADAPTIVE 0x08
#define USB_ENDPOINT_ATTR_SYNC 0x0C
#define USB_ENDPOINT_ATTR_SYNCTYPE 0x0C

#define USB_ENDPOINT_ATTR_DATA 0x00
#define USB_ENDPOINT_ATTR_FEEDBACK 0x10
#define USB_ENDPOINT_ATTR_IMPLICIT_FEEDBACK_DATA 0x20
#define USB_ENDPOINT_ATTR_USAGETYPE 0x30




struct usb_string_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t wData[];
} __attribute__((packed));


struct usb_iface_assoc_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bFirstInterface;
 uint8_t bInterfaceCount;
 uint8_t bFunctionClass;
 uint8_t bFunctionSubClass;
 uint8_t bFunctionProtocol;
 uint8_t iFunction;
} __attribute__((packed));
#define USB_DT_INTERFACE_ASSOCIATION_SIZE sizeof(struct usb_iface_assoc_descriptor)


enum usb_language_id {
 USB_LANGID_ENGLISH_US = 0x409,
};




enum usbd_request_return_codes {
 USBD_REQ_NOTSUPP = 0,
 USBD_REQ_HANDLED = 1,
 USBD_REQ_NEXT_CALLBACK = 2,
};

typedef struct _usbd_driver usbd_driver;
typedef struct _usbd_device usbd_device;

extern const usbd_driver st_usbfs_v1_usb_driver;
extern const usbd_driver stm32f107_usb_driver;
extern const usbd_driver stm32f207_usb_driver;
extern const usbd_driver st_usbfs_v2_usb_driver;
#define otgfs_usb_driver stm32f107_usb_driver
#define otghs_usb_driver stm32f207_usb_driver
extern const usbd_driver efm32lg_usb_driver;
extern const usbd_driver efm32hg_usb_driver;
extern const usbd_driver lm4f_usb_driver;
extern usbd_device * usbd_init(const usbd_driver *driver,
          const struct usb_device_descriptor *dev,
          const struct usb_config_descriptor *conf,
          const char * const *strings, int num_strings,
          uint8_t *control_buffer,
          uint16_t control_buffer_size);


extern void usbd_register_reset_callback(usbd_device *usbd_dev,
      void (*callback)(void));

extern void usbd_register_suspend_callback(usbd_device *usbd_dev,
        void (*callback)(void));

extern void usbd_register_resume_callback(usbd_device *usbd_dev,
       void (*callback)(void));

extern void usbd_register_sof_callback(usbd_device *usbd_dev,
           void (*callback)(void));

typedef void (*usbd_control_complete_callback)(usbd_device *usbd_dev,
  struct usb_setup_data *req);

typedef enum usbd_request_return_codes (*usbd_control_callback)(
  usbd_device *usbd_dev,
  struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
  usbd_control_complete_callback *complete);

typedef void (*usbd_set_config_callback)(usbd_device *usbd_dev,
      uint16_t wValue);

typedef void (*usbd_set_altsetting_callback)(usbd_device *usbd_dev,
          uint16_t wIndex, uint16_t wValue);

typedef void (*usbd_endpoint_callback)(usbd_device *usbd_dev, uint8_t ep);
extern int usbd_register_control_callback(usbd_device *usbd_dev, uint8_t type,
       uint8_t type_mask,
       usbd_control_callback callback);
extern int usbd_register_set_config_callback(usbd_device *usbd_dev,
       usbd_set_config_callback callback);




extern void usbd_register_set_altsetting_callback(usbd_device *usbd_dev,
     usbd_set_altsetting_callback callback);


extern void usbd_register_extra_string(usbd_device *usbd_dev, int index, const char* string);


extern void usbd_poll(usbd_device *usbd_dev);
extern void usbd_disconnect(usbd_device *usbd_dev, 
                                                  _Bool 
                                                       disconnected);
extern void usbd_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
  uint16_t max_size, usbd_endpoint_callback callback);
extern uint16_t usbd_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
    const void *buf, uint16_t len);
extern uint16_t usbd_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
          void *buf, uint16_t len);





extern void usbd_ep_stall_set(usbd_device *usbd_dev, uint8_t addr,
         uint8_t stall);






extern uint8_t usbd_ep_stall_get(usbd_device *usbd_dev, uint8_t addr);






extern void usbd_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);


#define LIBOPENCM3_USB_DWC_OTG_COMMON_H 


#define OTG_GOTGCTL 0x000
#define OTG_GOTGINT 0x004
#define OTG_GAHBCFG 0x008
#define OTG_GUSBCFG 0x00C
#define OTG_GRSTCTL 0x010
#define OTG_GINTSTS 0x014
#define OTG_GINTMSK 0x018
#define OTG_GRXSTSR 0x01C
#define OTG_GRXSTSP 0x020
#define OTG_GRXFSIZ 0x024
#define OTG_GNPTXFSIZ 0x028
#define OTG_GNPTXSTS 0x02C
#define OTG_GCCFG 0x038
#define OTG_CID 0x03C
#define OTG_HPTXFSIZ 0x100
#define OTG_DIEPTXF(x) (0x104 + 4*((x)-1))


#define OTG_HCFG 0x400
#define OTG_HFIR 0x404
#define OTG_HFNUM 0x408
#define OTG_HPTXSTS 0x410
#define OTG_HAINT 0x414
#define OTG_HAINTMSK 0x418
#define OTG_HPRT 0x440
#define OTG_HCCHAR(x) (0x500 + 0x20*(x))
#define OTG_HCINT(x) (0x508 + 0x20*(x))
#define OTG_HCINTMSK(x) (0x50C + 0x20*(x))
#define OTG_HCTSIZ(x) (0x510 + 0x20*(x))



#define OTG_DCFG 0x800
#define OTG_DCTL 0x804
#define OTG_DSTS 0x808
#define OTG_DIEPMSK 0x810
#define OTG_DOEPMSK 0x814
#define OTG_DAINT 0x818
#define OTG_DAINTMSK 0x81C
#define OTG_DVBUSDIS 0x828
#define OTG_DVBUSPULSE 0x82C
#define OTG_DIEPEMPMSK 0x834

#define OTG_DIEPCTL0 0x900
#define OTG_DIEPCTL(x) (0x900 + 0x20*(x))
#define OTG_DOEPCTL0 0xB00
#define OTG_DOEPCTL(x) (0xB00 + 0x20*(x))
#define OTG_DIEPINT(x) (0x908 + 0x20*(x))
#define OTG_DOEPINT(x) (0xB08 + 0x20*(x))
#define OTG_DIEPTSIZ0 0x910
#define OTG_DIEPTSIZ(x) (0x910 + 0x20*(x))
#define OTG_DOEPTSIZ0 0xB10
#define OTG_DOEPTSIZ(x) (0xB10 + 0x20*(x))
#define OTG_DTXFSTS(x) (0x918 + 0x20*(x))


#define OTG_PCGCCTL 0xE00


#define OTG_FIFO(x) (((x) + 1) << 12)




#define OTG_GOTGCTL_BSVLD (1 << 19)
#define OTG_GOTGCTL_ASVLD (1 << 18)
#define OTG_GOTGCTL_DBCT (1 << 17)
#define OTG_GOTGCTL_CIDSTS (1 << 16)
#define OTG_GOTGCTL_DHNPEN (1 << 11)
#define OTG_GOTGCTL_HSHNPEN (1 << 10)
#define OTG_GOTGCTL_HNPRQ (1 << 9)
#define OTG_GOTGCTL_HNGSCS (1 << 8)
#define OTG_GOTGCTL_SRQ (1 << 1)
#define OTG_GOTGCTL_SRQSCS (1 << 0)


#define OTG_GOTGINT_DBCDNE (1 << 19)
#define OTG_GOTGINT_ADTOCHG (1 << 18)
#define OTG_GOTGINT_HNGDET (1 << 17)
#define OTG_GOTGINT_HNSSCHG (1 << 9)
#define OTG_GOTGINT_SRSSCHG (1 << 8)
#define OTG_GOTGINT_SEDET (1 << 2)


#define OTG_GAHBCFG_GINT 0x0001
#define OTG_GAHBCFG_TXFELVL 0x0080
#define OTG_GAHBCFG_PTXFELVL 0x0100


#define OTG_GUSBCFG_TOCAL 0x00000003
#define OTG_GUSBCFG_SRPCAP 0x00000100
#define OTG_GUSBCFG_HNPCAP 0x00000200
#define OTG_GUSBCFG_TRDT_MASK (0xf << 10)
#define OTG_GUSBCFG_NPTXRWEN 0x00004000
#define OTG_GUSBCFG_FHMOD 0x20000000
#define OTG_GUSBCFG_FDMOD 0x40000000
#define OTG_GUSBCFG_CTXPKT 0x80000000
#define OTG_GUSBCFG_PHYSEL (1 << 6)


#define OTG_GRSTCTL_AHBIDL (1 << 31)

#define OTG_GRSTCTL_TXFNUM_MASK (0x1f << 6)
#define OTG_GRSTCTL_TXFNUM_ALL (0x10 << 6)
#define OTG_GRSTCTL_TXFFLSH (1 << 5)
#define OTG_GRSTCTL_RXFFLSH (1 << 4)

#define OTG_GRSTCTL_FCRST (1 << 2)
#define OTG_GRSTCTL_HSRST (1 << 1)
#define OTG_GRSTCTL_CSRST (1 << 0)


#define OTG_GINTSTS_WKUPINT (1 << 31)
#define OTG_GINTSTS_SRQINT (1 << 30)
#define OTG_GINTSTS_DISCINT (1 << 29)
#define OTG_GINTSTS_CIDSCHG (1 << 28)

#define OTG_GINTSTS_PTXFE (1 << 26)
#define OTG_GINTSTS_HCINT (1 << 25)
#define OTG_GINTSTS_HPRTINT (1 << 24)

#define OTG_GINTSTS_IPXFR (1 << 21)
#define OTG_GINTSTS_INCOMPISOOUT (1 << 21)
#define OTG_GINTSTS_IISOIXFR (1 << 20)
#define OTG_GINTSTS_OEPINT (1 << 19)
#define OTG_GINTSTS_IEPINT (1 << 18)

#define OTG_GINTSTS_EOPF (1 << 15)
#define OTG_GINTSTS_ISOODRP (1 << 14)
#define OTG_GINTSTS_ENUMDNE (1 << 13)
#define OTG_GINTSTS_USBRST (1 << 12)
#define OTG_GINTSTS_USBSUSP (1 << 11)
#define OTG_GINTSTS_ESUSP (1 << 10)

#define OTG_GINTSTS_GONAKEFF (1 << 7)
#define OTG_GINTSTS_GINAKEFF (1 << 6)
#define OTG_GINTSTS_NPTXFE (1 << 5)
#define OTG_GINTSTS_RXFLVL (1 << 4)
#define OTG_GINTSTS_SOF (1 << 3)
#define OTG_GINTSTS_OTGINT (1 << 2)
#define OTG_GINTSTS_MMIS (1 << 1)
#define OTG_GINTSTS_CMOD (1 << 0)


#define OTG_GINTMSK_MMISM 0x00000002
#define OTG_GINTMSK_OTGINT 0x00000004
#define OTG_GINTMSK_SOFM 0x00000008
#define OTG_GINTMSK_RXFLVLM 0x00000010
#define OTG_GINTMSK_NPTXFEM 0x00000020
#define OTG_GINTMSK_GINAKEFFM 0x00000040
#define OTG_GINTMSK_GONAKEFFM 0x00000080
#define OTG_GINTMSK_ESUSPM 0x00000400
#define OTG_GINTMSK_USBSUSPM 0x00000800
#define OTG_GINTMSK_USBRST 0x00001000
#define OTG_GINTMSK_ENUMDNEM 0x00002000
#define OTG_GINTMSK_ISOODRPM 0x00004000
#define OTG_GINTMSK_EOPFM 0x00008000
#define OTG_GINTMSK_EPMISM 0x00020000
#define OTG_GINTMSK_IEPINT 0x00040000
#define OTG_GINTMSK_OEPINT 0x00080000
#define OTG_GINTMSK_IISOIXFRM 0x00100000
#define OTG_GINTMSK_IISOOXFRM 0x00200000
#define OTG_GINTMSK_IPXFRM 0x00200000
#define OTG_GINTMSK_PRTIM 0x01000000
#define OTG_GINTMSK_HCIM 0x02000000
#define OTG_GINTMSK_PTXFEM 0x04000000
#define OTG_GINTMSK_CIDSCHGM 0x10000000
#define OTG_GINTMSK_DISCINT 0x20000000
#define OTG_GINTMSK_SRQIM 0x40000000
#define OTG_GINTMSK_WUIM 0x80000000



#define OTG_GRXSTSP_FRMNUM_MASK (0xf << 21)
#define OTG_GRXSTSP_PKTSTS_MASK (0xf << 17)
#define OTG_GRXSTSP_PKTSTS_GOUTNAK (0x1 << 17)
#define OTG_GRXSTSP_PKTSTS_OUT (0x2 << 17)
#define OTG_GRXSTSP_PKTSTS_IN (0x2 << 17)
#define OTG_GRXSTSP_PKTSTS_OUT_COMP (0x3 << 17)
#define OTG_GRXSTSP_PKTSTS_IN_COMP (0x3 << 17)
#define OTG_GRXSTSP_PKTSTS_SETUP_COMP (0x4 << 17)
#define OTG_GRXSTSP_PKTSTS_DTERR (0x5 << 17)
#define OTG_GRXSTSP_PKTSTS_SETUP (0x6 << 17)
#define OTG_GRXSTSP_PKTSTS_CHH (0x7 << 17)
#define OTG_GRXSTSP_DPID_MASK (0x3 << 15)
#define OTG_GRXSTSP_DPID_DATA0 (0x0 << 15)
#define OTG_GRXSTSP_DPID_DATA1 (0x2 << 15)
#define OTG_GRXSTSP_DPID_DATA2 (0x1 << 15)
#define OTG_GRXSTSP_DPID_MDATA (0x3 << 15)
#define OTG_GRXSTSP_BCNT_MASK (0x7ff << 4)
#define OTG_GRXSTSP_EPNUM_MASK (0xf << 0)



#define OTG_GCCFG_NOVBUSSENS (1 << 21)

#define OTG_GCCFG_VBDEN (1 << 21)
#define OTG_GCCFG_SOFOUTEN (1 << 20)
#define OTG_GCCFG_VBUSBSEN (1 << 19)
#define OTG_GCCFG_VBUSASEN (1 << 18)

#define OTG_GCCFG_PWRDWN (1 << 16)



#define OTG_CID_HAS_VBDEN 0x00002000




#define OTG_DCTL_POPRGDNE (1 << 11)
#define OTG_DCTL_CGONAK (1 << 10)
#define OTG_DCTL_SGONAK (1 << 9)
#define OTG_DCTL_SGINAK (1 << 8)
#define OTG_DCTL_TCTL_MASK (7 << 4)
#define OTG_DCTL_GONSTS (1 << 3)
#define OTG_DCTL_GINSTS (1 << 2)
#define OTG_DCTL_SDIS (1 << 1)
#define OTG_DCTL_RWUSIG (1 << 0)


#define OTG_DCFG_DSPD 0x0003
#define OTG_DCFG_NZLSOHSK 0x0004
#define OTG_DCFG_DAD 0x07F0
#define OTG_DCFG_PFIVL 0x1800


#define OTG_DSTS_SUSPSTS (1 << 0)



#define OTG_DIEPMSK_BIM (1 << 9)
#define OTG_DIEPMSK_TXFURM (1 << 8)

#define OTG_DIEPMSK_INEPNEM (1 << 6)
#define OTG_DIEPMSK_INEPNMM (1 << 5)
#define OTG_DIEPMSK_ITTXFEMSK (1 << 4)
#define OTG_DIEPMSK_TOM (1 << 3)

#define OTG_DIEPMSK_EPDM (1 << 1)
#define OTG_DIEPMSK_XFRCM (1 << 0)



#define OTG_DOEPMSK_BOIM (1 << 9)
#define OTG_DOEPMSK_OPEM (1 << 8)

#define OTG_DOEPMSK_B2BSTUP (1 << 6)

#define OTG_DOEPMSK_OTEPDM (1 << 4)
#define OTG_DOEPMSK_STUPM (1 << 3)

#define OTG_DOEPMSK_EPDM (1 << 1)
#define OTG_DOEPMSK_XFRCM (1 << 0)


#define OTG_DIEPCTL0_EPENA (1 << 31)
#define OTG_DIEPCTL0_EPDIS (1 << 30)

#define OTG_DIEPCTLX_SD0PID (1 << 28)
#define OTG_DIEPCTL0_SNAK (1 << 27)
#define OTG_DIEPCTL0_CNAK (1 << 26)
#define OTG_DIEPCTL0_TXFNUM_MASK (0xf << 22)
#define OTG_DIEPCTL0_STALL (1 << 21)

#define OTG_DIEPCTL0_EPTYP_MASK (0x3 << 18)
#define OTG_DIEPCTL0_NAKSTS (1 << 17)

#define OTG_DIEPCTL0_USBAEP (1 << 15)

#define OTG_DIEPCTL0_MPSIZ_MASK (0x3 << 0)
#define OTG_DIEPCTL0_MPSIZ_64 (0x0 << 0)
#define OTG_DIEPCTL0_MPSIZ_32 (0x1 << 0)
#define OTG_DIEPCTL0_MPSIZ_16 (0x2 << 0)
#define OTG_DIEPCTL0_MPSIZ_8 (0x3 << 0)


#define OTG_DOEPCTL0_EPENA (1 << 31)
#define OTG_DOEPCTL0_EPDIS (1 << 30)

#define OTG_DOEPCTLX_SD0PID (1 << 28)
#define OTG_DOEPCTL0_SNAK (1 << 27)
#define OTG_DOEPCTL0_CNAK (1 << 26)

#define OTG_DOEPCTL0_STALL (1 << 21)
#define OTG_DOEPCTL0_SNPM (1 << 20)
#define OTG_DOEPCTL0_EPTYP_MASK (0x3 << 18)
#define OTG_DOEPCTL0_NAKSTS (1 << 17)

#define OTG_DOEPCTL0_USBAEP (1 << 15)

#define OTG_DOEPCTL0_MPSIZ_MASK (0x3 << 0)
#define OTG_DOEPCTL0_MPSIZ_64 (0x0 << 0)
#define OTG_DOEPCTL0_MPSIZ_32 (0x1 << 0)
#define OTG_DOEPCTL0_MPSIZ_16 (0x2 << 0)
#define OTG_DOEPCTL0_MPSIZ_8 (0x3 << 0)



#define OTG_DIEPINTX_TXFE (1 << 7)
#define OTG_DIEPINTX_INEPNE (1 << 6)

#define OTG_DIEPINTX_ITTXFE (1 << 4)
#define OTG_DIEPINTX_TOC (1 << 3)

#define OTG_DIEPINTX_EPDISD (1 << 1)
#define OTG_DIEPINTX_XFRC (1 << 0)



#define OTG_DOEPINTX_B2BSTUP (1 << 6)

#define OTG_DOEPINTX_OTEPDIS (1 << 4)
#define OTG_DOEPINTX_STUP (1 << 3)

#define OTG_DOEPINTX_EPDISD (1 << 1)
#define OTG_DOEPINTX_XFRC (1 << 0)



#define OTG_DIEPSIZ0_STUPCNT_1 (0x1 << 29)
#define OTG_DIEPSIZ0_STUPCNT_2 (0x2 << 29)
#define OTG_DIEPSIZ0_STUPCNT_3 (0x3 << 29)
#define OTG_DIEPSIZ0_STUPCNT_MASK (0x3 << 29)

#define OTG_DIEPSIZ0_PKTCNT (1 << 19)

#define OTG_DIEPSIZ0_XFRSIZ_MASK (0x7f << 0)






#define OTG_HNPTXFSIZ_PTXFD_MASK (0xffff0000)
#define OTG_HNPTXFSIZ_PTXSA_MASK (0x0000ffff)


#define OTG_HPTXFSIZ_PTXFD_MASK (0xffff0000)
#define OTG_HPTXFSIZ_PTXSA_MASK (0x0000ffff)



#define OTG_HCFG_FSLSS (1 << 2)
#define OTG_HCFG_FSLSPCS_48MHz (0x1 << 0)
#define OTG_HCFG_FSLSPCS_6MHz (0x2 << 0)
#define OTG_HCFG_FSLSPCS_MASK (0x3 << 0)



#define OTG_HFIR_FRIVL_MASK (0x0000ffff)


#define OTG_HFNUM_FTREM_MASK (0xffff0000)
#define OTG_HFNUM_FRNUM_MASK (0x0000ffff)


#define OTG_HPTXSTS_PTXQTOP_MASK (0xff000000)
#define OTG_HPTXSTS_PTXQTOP_ODDFRM (1<<31)
#define OTG_HPTXSTS_PTXQTOP_EVENFRM (0<<31)
#define OTG_HPTXSTS_PTXQTOP_CHANNEL_NUMBER_MASK (0xf<<27)
#define OTG_HPTXSTS_PTXQTOP_ENDPOINT_NUMBER_MASK (0xf<<27)
#define OTG_HPTXSTS_PTXQTOP_TYPE_INOUT (0x00<<25)
#define OTG_HPTXSTS_PTXQTOP_TYPE_ZEROLENGTH (0x01<<25)
#define OTG_HPTXSTS_PTXQTOP_TYPE_DISABLECMD (0x11<<25)
#define OTG_HPTXSTS_PTXQTOP_TERMINATE (1<<24)
#define OTG_HPTXSTS_PTXQSAV_MASK (0x00ff0000)
#define OTG_HPTXSTS_PTXFSAVL_MASK (0x0000ffff)



#define OTG_HAINTMSK_HAINT_MASK (0x0000ffff)



#define OTG_HAINTMSK_HAINTM_MASK (0x0000ffff)



#define OTG_HPRT_PSPD_HIGH (0x0 << 17)
#define OTG_HPRT_PSPD_FULL (0x1 << 17)
#define OTG_HPRT_PSPD_LOW (0x2 << 17)
#define OTG_HPRT_PSPD_MASK (0x3 << 17)
#define OTG_HPRT_PTCTL_DISABLED (0x0 << 13)
#define OTG_HPRT_PTCTL_J (0x1 << 13)
#define OTG_HPRT_PTCTL_K (0x2 << 13)
#define OTG_HPRT_PTCTL_SE0_NAK (0x3 << 13)
#define OTG_HPRT_PTCTL_PACKET (0x4 << 13)
#define OTG_HPRT_PTCTL_FORCE_ENABLE (0x5 << 13)
#define OTG_HPRT_PPWR (1 << 12)
#define OTG_HPRT_PLSTS_DM (1 << 11)
#define OTG_HPRT_PLSTS_DP (1 << 10)

#define OTG_HPRT_PRST (1 << 8)
#define OTG_HPRT_PSUSP (1 << 7)
#define OTG_HPRT_PRES (1 << 6)
#define OTG_HPRT_POCCHNG (1 << 5)
#define OTG_HPRT_POCA (1 << 4)
#define OTG_HPRT_PENCHNG (1 << 3)
#define OTG_HPRT_PENA (1 << 2)
#define OTG_HPRT_PCDET (1 << 1)
#define OTG_HPRT_PCSTS (1 << 0)


#define OTG_HCCHAR_CHENA (1 << 31)
#define OTG_HCCHAR_CHDIS (1 << 30)
#define OTG_HCCHAR_ODDFRM (1 << 29)
#define OTG_HCCHAR_DAD_MASK (0x7f << 22)
#define OTG_HCCHAR_MCNT_1 (0x1 << 20)
#define OTG_HCCHAR_MCNT_2 (0x2 << 20)
#define OTG_HCCHAR_MCNT_3 (0x3 << 20)
#define OTG_HCCHAR_MCNT_MASK (0x3 << 20)
#define OTG_HCCHAR_EPTYP_CONTROL (0 << 18)
#define OTG_HCCHAR_EPTYP_ISOCHRONOUS (1 << 18)
#define OTG_HCCHAR_EPTYP_BULK (2 << 18)
#define OTG_HCCHAR_EPTYP_INTERRUPT (3 << 18)
#define OTG_HCCHAR_EPTYP_MASK (3 << 18)
#define OTG_HCCHAR_LSDEV (1 << 17)

#define OTG_HCCHAR_EPDIR_OUT (0 << 15)
#define OTG_HCCHAR_EPDIR_IN (1 << 15)
#define OTG_HCCHAR_EPDIR_MASK (1 << 15)
#define OTG_HCCHAR_EPNUM_MASK (0xf << 11)
#define OTG_HCCHAR_MPSIZ_MASK (0x7ff << 0)



#define OTG_HCINT_DTERR (1 << 10)
#define OTG_HCINT_FRMOR (1 << 9)
#define OTG_HCINT_BBERR (1 << 8)
#define OTG_HCINT_TXERR (1 << 7)

#define OTG_HCINT_NYET (1 << 6)
#define OTG_HCINT_ACK (1 << 5)
#define OTG_HCINT_NAK (1 << 4)
#define OTG_HCINT_STALL (1 << 3)

#define OTG_HCINT_AHBERR (1 << 2)
#define OTG_HCINT_CHH (1 << 1)
#define OTG_HCINT_XFRC (1 << 0)



#define OTG_HCINTMSK_DTERRM (1 << 10)
#define OTG_HCINTMSK_FRMORM (1 << 9)
#define OTG_HCINTMSK_BBERRM (1 << 8)
#define OTG_HCINTMSK_TXERRM (1 << 7)

#define OTG_HCINTMSK_NYET (1 << 6)
#define OTG_HCINTMSK_ACKM (1 << 5)
#define OTG_HCINTMSK_NAKM (1 << 4)
#define OTG_HCINTMSK_STALLM (1 << 3)

#define OTG_HCINTMSK_AHBERR (1 << 2)
#define OTG_HCINTMSK_CHHM (1 << 1)
#define OTG_HCINTMSK_XFRCM (1 << 0)



#define OTG_HCTSIZ_DOPING (1 << 31)
#define OTG_HCTSIZ_DPID_DATA0 (0x0 << 29)
#define OTG_HCTSIZ_DPID_DATA1 (0x2 << 29)
#define OTG_HCTSIZ_DPID_DATA2 (0x1 << 29)
#define OTG_HCTSIZ_DPID_MDATA (0x3 << 29)
#define OTG_HCTSIZ_DPID_MASK (0x3 << 29)
#define OTG_HCTSIZ_PKTCNT_MASK (0x3ff << 19)
#define OTG_HCTSIZ_XFRSIZ_MASK (0x7ffff << 0)
#define __USB_PRIVATE_H 

#define MAX_USER_CONTROL_CALLBACK 4
#define MAX_USER_SET_CONFIG_CALLBACK 4

#define MIN(a,b) ((a) < (b) ? (a) : (b))


struct _usbd_device {
 const struct usb_device_descriptor *desc;
 const struct usb_config_descriptor *config;
 const char * const *strings;
 int num_strings;

 uint8_t *ctrl_buf;
 uint16_t ctrl_buf_len;

 uint8_t current_address;
 uint8_t current_config;

 uint16_t pm_top;


 void (*user_callback_reset)(void);
 void (*user_callback_suspend)(void);
 void (*user_callback_resume)(void);
 void (*user_callback_sof)(void);

 struct usb_control_state {
  enum {
   IDLE, STALLED,
   DATA_IN, LAST_DATA_IN, STATUS_IN,
   DATA_OUT, LAST_DATA_OUT, STATUS_OUT,
  } state;
  struct usb_setup_data req __attribute__((aligned(4)));
  uint8_t *ctrl_buf;
  uint16_t ctrl_len;
  usbd_control_complete_callback complete;
  
 _Bool 
      needs_zlp;
 } control_state;

 struct user_control_callback {
  usbd_control_callback cb;
  uint8_t type;
  uint8_t type_mask;
 } user_control_callback[4];

 usbd_endpoint_callback user_callback_ctr[8][3];


 usbd_set_config_callback user_callback_set_config[4];

 usbd_set_altsetting_callback user_callback_set_altsetting;

 const struct _usbd_driver *driver;


 int extra_string_idx;
 const char* extra_string;



 uint16_t fifo_mem_top;
 uint16_t fifo_mem_top_ep0;
 uint8_t force_nak[4];




 uint32_t doeptsiz[4];





 uint16_t rxbcnt;
};

enum _usbd_transaction {
 USB_TRANSACTION_IN,
 USB_TRANSACTION_OUT,
 USB_TRANSACTION_SETUP,
};




void _usbd_control_in(usbd_device *usbd_dev, uint8_t ea);
void _usbd_control_out(usbd_device *usbd_dev, uint8_t ea);
void _usbd_control_setup(usbd_device *usbd_dev, uint8_t ea);

enum usbd_request_return_codes _usbd_standard_request_device(usbd_device *usbd_dev,
      struct usb_setup_data *req, uint8_t **buf,
      uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request_interface(usbd_device *usbd_dev,
         struct usb_setup_data *req, uint8_t **buf,
         uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request_endpoint(usbd_device *usbd_dev,
        struct usb_setup_data *req, uint8_t **buf,
        uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request(usbd_device *usbd_dev, struct usb_setup_data *req,
      uint8_t **buf, uint16_t *len);

void _usbd_reset(usbd_device *usbd_dev);


struct _usbd_driver {
 usbd_device *(*init)(void);
 void (*set_address)(usbd_device *usbd_dev, uint8_t addr);
 void (*ep_setup)(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
    uint16_t max_size, usbd_endpoint_callback cb);
 void (*ep_reset)(usbd_device *usbd_dev);
 void (*ep_stall_set)(usbd_device *usbd_dev, uint8_t addr,
        uint8_t stall);
 void (*ep_nak_set)(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);
 uint8_t (*ep_stall_get)(usbd_device *usbd_dev, uint8_t addr);
 uint16_t (*ep_write_packet)(usbd_device *usbd_dev, uint8_t addr,
        const void *buf, uint16_t len);
 uint16_t (*ep_read_packet)(usbd_device *usbd_dev, uint8_t addr,
       void *buf, uint16_t len);
 void (*poll)(usbd_device *usbd_dev);
 void (*disconnect)(usbd_device *usbd_dev, 
                                          _Bool 
                                               disconnected);
 uint32_t base_address;
 
_Bool 
     set_address_before_status;
 uint16_t rx_fifo_size;
};
#define __USB_DWC_COMMON_H_ 

void dwc_set_address(usbd_device *usbd_dev, uint8_t addr);
void dwc_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
   uint16_t max_size,
   void (*callback)(usbd_device *usbd_dev, uint8_t ep));
void dwc_endpoints_reset(usbd_device *usbd_dev);
void dwc_ep_stall_set(usbd_device *usbd_dev, uint8_t addr, uint8_t stall);
uint8_t dwc_ep_stall_get(usbd_device *usbd_dev, uint8_t addr);
void dwc_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);
uint16_t dwc_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
       const void *buf, uint16_t len);
uint16_t dwc_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
      void *buf, uint16_t len);
void dwc_poll(usbd_device *usbd_dev);
void dwc_disconnect(usbd_device *usbd_dev, 
                                          _Bool 
                                               disconnected);




#define dev_base_address (usbd_dev->driver->base_address)
#define REBASE(x) MMIO32((x) + (dev_base_address))

void dwc_set_address(usbd_device *usbd_dev, uint8_t addr)
{
 (*(volatile uint32_t *)((0x800) + ((usbd_dev->driver->base_address)))) = ((*(volatile uint32_t *)((0x800) + ((usbd_dev->driver->base_address)))) & ~0x07F0) | (addr << 4);
}

void dwc_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
   uint16_t max_size,
   void (*callback) (usbd_device *usbd_dev, uint8_t ep))
{




 uint8_t dir = addr & 0x80;
 addr &= 0x7f;

 if (addr == 0) {

  if (max_size >= 64) {
   (*(volatile uint32_t *)((0x900) + ((usbd_dev->driver->base_address)))) = (0x0 << 0);
  } else if (max_size >= 32) {
   (*(volatile uint32_t *)((0x900) + ((usbd_dev->driver->base_address)))) = (0x1 << 0);
  } else if (max_size >= 16) {
   (*(volatile uint32_t *)((0x900) + ((usbd_dev->driver->base_address)))) = (0x2 << 0);
  } else {
   (*(volatile uint32_t *)((0x900) + ((usbd_dev->driver->base_address)))) = (0x3 << 0);
  }

  (*(volatile uint32_t *)((0x910) + ((usbd_dev->driver->base_address)))) =
   (max_size & (0x7f << 0));
  (*(volatile uint32_t *)((0x900) + ((usbd_dev->driver->base_address)))) |=
   (1 << 31) | (1 << 27);


  usbd_dev->doeptsiz[0] = (0x1 << 29) |
   (1 << 19) |
   (max_size & (0x7f << 0));
  (*(volatile uint32_t *)(((0xB10 + 0x20*(0))) + ((usbd_dev->driver->base_address)))) = usbd_dev->doeptsiz[0];
  (*(volatile uint32_t *)(((0xB00 + 0x20*(0))) + ((usbd_dev->driver->base_address)))) |=
      (1 << 31) | (1 << 27);

  (*(volatile uint32_t *)((0x028) + ((usbd_dev->driver->base_address)))) = ((max_size / 4) << 16) |
      usbd_dev->driver->rx_fifo_size;
  usbd_dev->fifo_mem_top += max_size / 4;
  usbd_dev->fifo_mem_top_ep0 = usbd_dev->fifo_mem_top;

  return;
 }

 if (dir) {
  (*(volatile uint32_t *)(((0x104 + 4*((addr)-1))) + ((usbd_dev->driver->base_address)))) = ((max_size / 4) << 16) |
          usbd_dev->fifo_mem_top;
  usbd_dev->fifo_mem_top += max_size / 4;

  (*(volatile uint32_t *)(((0x910 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) =
      (max_size & (0x7f << 0));
  (*(volatile uint32_t *)(((0x900 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |=
      (1 << 31) | (1 << 27) | (type << 18)
      | (1 << 15) | (1 << 28)
      | (addr << 22) | max_size;

  if (callback) {
   usbd_dev->user_callback_ctr[addr][USB_TRANSACTION_IN] =
       (void *)callback;
  }
 }

 if (!dir) {
  usbd_dev->doeptsiz[addr] = (1 << 19) |
     (max_size & (0x7f << 0));
  (*(volatile uint32_t *)(((0xB10 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) = usbd_dev->doeptsiz[addr];
  (*(volatile uint32_t *)(((0xB00 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |= (1 << 31) |
      (1 << 15) | (1 << 26) |
      (1 << 28) | (type << 18) | max_size;

  if (callback) {
   usbd_dev->user_callback_ctr[addr][USB_TRANSACTION_OUT] =
       (void *)callback;
  }
 }
}

void dwc_endpoints_reset(usbd_device *usbd_dev)
{
 int i;

 usbd_dev->fifo_mem_top = usbd_dev->fifo_mem_top_ep0;


 for (i = 1; i < 4; i++) {
  if ((*(volatile uint32_t *)(((0xB00 + 0x20*(i))) + ((usbd_dev->driver->base_address)))) & (1 << 31)) {
   (*(volatile uint32_t *)(((0xB00 + 0x20*(i))) + ((usbd_dev->driver->base_address)))) |= (1 << 30);
  }
  if ((*(volatile uint32_t *)(((0x900 + 0x20*(i))) + ((usbd_dev->driver->base_address)))) & (1 << 31)) {
   (*(volatile uint32_t *)(((0x900 + 0x20*(i))) + ((usbd_dev->driver->base_address)))) |= (1 << 30);
  }
 }


 (*(volatile uint32_t *)((0x010) + ((usbd_dev->driver->base_address)))) = (1 << 5) | (0x10 << 6)
         | (1 << 4);
}

void dwc_ep_stall_set(usbd_device *usbd_dev, uint8_t addr, uint8_t stall)
{
 if (addr == 0) {
  if (stall) {
   (*(volatile uint32_t *)(((0x900 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |= (1 << 21);
  } else {
   (*(volatile uint32_t *)(((0x900 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) &= ~(1 << 21);
  }
 }

 if (addr & 0x80) {
  addr &= 0x7F;

  if (stall) {
   (*(volatile uint32_t *)(((0x900 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |= (1 << 21);
  } else {
   (*(volatile uint32_t *)(((0x900 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) &= ~(1 << 21);
   (*(volatile uint32_t *)(((0x900 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |= (1 << 28);
  }
 } else {
  if (stall) {
   (*(volatile uint32_t *)(((0xB00 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |= (1 << 21);
  } else {
   (*(volatile uint32_t *)(((0xB00 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) &= ~(1 << 21);
   (*(volatile uint32_t *)(((0xB00 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |= (1 << 28);
  }
 }
}

uint8_t dwc_ep_stall_get(usbd_device *usbd_dev, uint8_t addr)
{

 if (addr & 0x80) {
  return ((*(volatile uint32_t *)(((0x900 + 0x20*(addr & 0x7f))) + ((usbd_dev->driver->base_address)))) &
    (1 << 21)) ? 1 : 0;
 } else {
  return ((*(volatile uint32_t *)(((0xB00 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) &
    (1 << 21)) ? 1 : 0;
 }
}

void dwc_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak)
{

 if (addr & 0x80) {
  return;
 }

 usbd_dev->force_nak[addr] = nak;

 if (nak) {
  (*(volatile uint32_t *)(((0xB00 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |= (1 << 27);
 } else {
  (*(volatile uint32_t *)(((0xB00 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |= (1 << 26);
 }
}

uint16_t dwc_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
         const void *buf, uint16_t len)
{
 const uint32_t *buf32 = buf;




 int i;

 addr &= 0x7F;


 if ((*(volatile uint32_t *)(((0x910 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) & (1 << 19)) {
  return 0;
 }


 (*(volatile uint32_t *)(((0x910 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) = (1 << 19) | len;
 (*(volatile uint32_t *)(((0x900 + 0x20*(addr))) + ((usbd_dev->driver->base_address)))) |= (1 << 31) |
         (1 << 26);




 for (i = len; i > 0; i -= 4) {
  (*(volatile uint32_t *)(((((addr) + 1) << 12)) + ((usbd_dev->driver->base_address)))) = *buf32++;
 }
 return len;
}

uint16_t dwc_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
      void *buf, uint16_t len)
{
 int i;
 uint32_t *buf32 = buf;




 uint32_t extra;




 (void) addr;
 len = ((len) < (usbd_dev->rxbcnt) ? (len) : (usbd_dev->rxbcnt));



 for (i = len; i >= 4; i -= 4) {
  *buf32++ = (*(volatile uint32_t *)(((((0) + 1) << 12)) + ((usbd_dev->driver->base_address))));
  usbd_dev->rxbcnt -= 4;
 }
 if (i) {
  extra = (*(volatile uint32_t *)(((((0) + 1) << 12)) + ((usbd_dev->driver->base_address))));

  if (usbd_dev->rxbcnt < 4) {

   usbd_dev->rxbcnt = 0;
  } else {
   usbd_dev->rxbcnt -= 4;
  }
  memcpy(buf32, &extra, i);
 }

 return len;
}

static void dwc_flush_txfifo(usbd_device *usbd_dev, int ep)
{
 uint32_t fifo;

 (*(volatile uint32_t *)(((0x900 + 0x20*(ep))) + ((usbd_dev->driver->base_address)))) |= (1 << 27);

 while (!((*(volatile uint32_t *)(((0x908 + 0x20*(ep))) + ((usbd_dev->driver->base_address)))) & (1 << 6))) {

 }

 fifo = ((*(volatile uint32_t *)(((0x900 + 0x20*(ep))) + ((usbd_dev->driver->base_address)))) & (0xf << 22)) >> 22;

 while (!((*(volatile uint32_t *)((0x010) + ((usbd_dev->driver->base_address)))) & (1 << 31))) {

 }

 (*(volatile uint32_t *)((0x010) + ((usbd_dev->driver->base_address)))) = (fifo << 6) | (1 << 5);

 (*(volatile uint32_t *)(((0x910 + 0x20*(ep))) + ((usbd_dev->driver->base_address)))) = 0;
 while (((*(volatile uint32_t *)((0x010) + ((usbd_dev->driver->base_address)))) & (1 << 5))) {

 }
}

void dwc_poll(usbd_device *usbd_dev)
{

 uint32_t intsts = (*(volatile uint32_t *)((0x014) + ((usbd_dev->driver->base_address))));
 int i;

 if (intsts & (1 << 13)) {

  (*(volatile uint32_t *)((0x014) + ((usbd_dev->driver->base_address)))) = (1 << 13);
  usbd_dev->fifo_mem_top = usbd_dev->driver->rx_fifo_size;
  _usbd_reset(usbd_dev);
  return;
 }





 for (i = 0; i < 4; i++) {
  if ((*(volatile uint32_t *)(((0x908 + 0x20*(i))) + ((usbd_dev->driver->base_address)))) & (1 << 0)) {

   if (usbd_dev->user_callback_ctr[i]
             [USB_TRANSACTION_IN]) {
    usbd_dev->user_callback_ctr[i]
     [USB_TRANSACTION_IN](usbd_dev, i);
   }

   (*(volatile uint32_t *)(((0x908 + 0x20*(i))) + ((usbd_dev->driver->base_address)))) = (1 << 0);
  }
 }


 if (intsts & (1 << 4)) {

  uint32_t rxstsp = (*(volatile uint32_t *)((0x020) + ((usbd_dev->driver->base_address))));
  uint32_t pktsts = rxstsp & (0xf << 17);
  uint8_t ep = rxstsp & (0xf << 0);

  if (pktsts == (0x4 << 17)) {
   usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_SETUP] (usbd_dev, ep);
  }

  if (pktsts == (0x3 << 17)
   || pktsts == (0x4 << 17)) {
   (*(volatile uint32_t *)(((0xB10 + 0x20*(ep))) + ((usbd_dev->driver->base_address)))) = usbd_dev->doeptsiz[ep];
   (*(volatile uint32_t *)(((0xB00 + 0x20*(ep))) + ((usbd_dev->driver->base_address)))) |= (1 << 31) |
    (usbd_dev->force_nak[ep] ?
     (1 << 27) : (1 << 26));
   return;
  }

  if ((pktsts != (0x2 << 17)) &&
      (pktsts != (0x6 << 17))) {
   return;
  }

  uint8_t type;
  if (pktsts == (0x6 << 17)) {
   type = USB_TRANSACTION_SETUP;
  } else {
   type = USB_TRANSACTION_OUT;
  }

  if (type == USB_TRANSACTION_SETUP
   && ((*(volatile uint32_t *)(((0x910 + 0x20*(ep))) + ((usbd_dev->driver->base_address)))) & (1 << 19))) {



   dwc_flush_txfifo(usbd_dev, ep);
  }


  usbd_dev->rxbcnt = (rxstsp & (0x7ff << 4)) >> 4;

  if (type == USB_TRANSACTION_SETUP) {
   dwc_ep_read_packet(usbd_dev, ep, &usbd_dev->control_state.req, 8);
  } else if (usbd_dev->user_callback_ctr[ep][type]) {
   usbd_dev->user_callback_ctr[ep][type] (usbd_dev, ep);
  }


  for (i = 0; i < usbd_dev->rxbcnt; i += 4) {

   (void)(*(volatile uint32_t *)(((((0) + 1) << 12)) + ((usbd_dev->driver->base_address))));
  }

  usbd_dev->rxbcnt = 0;
 }

 if (intsts & (1 << 11)) {
  if (usbd_dev->user_callback_suspend) {
   usbd_dev->user_callback_suspend();
  }
  (*(volatile uint32_t *)((0x014) + ((usbd_dev->driver->base_address)))) = (1 << 11);
 }

 if (intsts & (1 << 31)) {
  if (usbd_dev->user_callback_resume) {
   usbd_dev->user_callback_resume();
  }
  (*(volatile uint32_t *)((0x014) + ((usbd_dev->driver->base_address)))) = (1 << 31);
 }

 if (intsts & (1 << 3)) {
  if (usbd_dev->user_callback_sof) {
   usbd_dev->user_callback_sof();
  }
  (*(volatile uint32_t *)((0x014) + ((usbd_dev->driver->base_address)))) = (1 << 3);
 }

 if (usbd_dev->user_callback_sof) {
  (*(volatile uint32_t *)((0x018) + ((usbd_dev->driver->base_address)))) |= 0x00000008;
 } else {
  (*(volatile uint32_t *)((0x018) + ((usbd_dev->driver->base_address)))) &= ~0x00000008;
 }
}

void dwc_disconnect(usbd_device *usbd_dev, 
                                          _Bool 
                                               disconnected)
{
 if (disconnected) {
  (*(volatile uint32_t *)((0x804) + ((usbd_dev->driver->base_address)))) |= (1 << 1);
 } else {
  (*(volatile uint32_t *)((0x804) + ((usbd_dev->driver->base_address)))) &= ~(1 << 1);
 }
}
