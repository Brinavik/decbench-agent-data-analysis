#define __USBD_H 

#define __USBSTD_H 

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


#define LIBOPENCM3_USB_AUDIO_H 
#define USB_CLASS_AUDIO 0x01


#define USB_AUDIO_SUBCLASS_UNDEFINED 0x00
#define USB_AUDIO_SUBCLASS_CONTROL 0x01
#define USB_AUDIO_SUBCLASS_AUDIOSTREAMING 0x02
#define USB_AUDIO_SUBCLASS_MIDISTREAMING 0x03


#define USB_AUDIO_DT_CS_UNDEFINED 0x20
#define USB_AUDIO_DT_CS_DEVICE 0x21
#define USB_AUDIO_DT_CS_CONFIGURATION 0x22
#define USB_AUDIO_DT_CS_STRING 0x23
#define USB_AUDIO_DT_CS_INTERFACE 0x24
#define USB_AUDIO_DT_CS_ENDPOINT 0x25


#define USB_AUDIO_TYPE_AC_DESCRIPTOR_UNDEFINED 0x00
#define USB_AUDIO_TYPE_HEADER 0x01
#define USB_AUDIO_TYPE_INPUT_TERMINAL 0x02
#define USB_AUDIO_TYPE_OUTPUT_TERMINAL 0x03
#define USB_AUDIO_TYPE_MIXER_UNIT 0x04
#define USB_AUDIO_TYPE_SELECTOR_UNIT 0x05
#define USB_AUDIO_TYPE_FEATURE_UNIT 0x06
#define USB_AUDIO_TYPE_PROCESSING_UNIT 0x07
#define USB_AUDIO_TYPE_EXTENSION_UNIT 0x08


struct usb_audio_header_descriptor_head {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint16_t bcdADC;
 uint16_t wTotalLength;
 uint8_t binCollection;

} __attribute__((packed));


struct usb_audio_header_descriptor_body {

 uint8_t baInterfaceNr;
} __attribute__((packed));


struct usb_audio_input_terminal_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bTerminalID;
 uint16_t wTerminalType;
 uint8_t bAssocTerminal;
 uint8_t bNrChannels;
 uint16_t wChannelConfig;
 uint8_t iChannelNames;
 uint8_t iTerminal;
} __attribute__((packed));


struct usb_audio_output_terminal_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bTerminalID;
 uint16_t wTerminalType;
 uint8_t bAssocTerminal;
 uint8_t bSourceID;
 uint8_t iTerminal;
} __attribute__((packed));


struct usb_audio_feature_unit_descriptor_head {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bUnitID;
 uint8_t bSourceID;
 uint8_t bControlSize;
 uint16_t bmaControlMaster;



} __attribute__((packed));


struct usb_audio_feature_unit_descriptor_body {

 uint16_t bmaControl;

} __attribute__((packed));


struct usb_audio_feature_unit_descriptor_tail {

 uint8_t iFeature;
} __attribute__((packed));






struct usb_audio_feature_unit_descriptor_2ch {
 struct usb_audio_feature_unit_descriptor_head head;
 struct usb_audio_feature_unit_descriptor_body channel_control[2];
 struct usb_audio_feature_unit_descriptor_tail tail;
} __attribute__((packed));


struct usb_audio_stream_interface_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bTerminalLink;
 uint8_t bDelay;
 uint16_t wFormatTag;
} __attribute__((packed));


struct usb_audio_stream_endpoint_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bEndpointAddress;
 uint8_t bmAttributes;
 uint16_t wMaxPacketSize;
 uint8_t bInterval;
 uint8_t bRefresh;
 uint8_t bSynchAddress;
} __attribute__((packed));


struct usb_audio_stream_audio_endpoint_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bmAttributes;
 uint8_t bLockDelayUnits;
 uint16_t wLockDelay;
} __attribute__((packed));







struct usb_audio_format_type1_descriptor_head {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bFormatType;
 uint8_t bNrChannels;
 uint8_t bSubFrameSize;
 uint8_t bBitResolution;
 uint8_t bSamFreqType;

} __attribute__((packed));


struct usb_audio_format_continuous_sampling_frequency {

 uint32_t tLowerSamFreq : 24;
 uint32_t tUpperSamFreq : 24;
} __attribute__((packed));


struct usb_audio_format_discrete_sampling_frequency {

 uint32_t tSamFreq : 24;
} __attribute__((packed));






struct usb_audio_format_type1_descriptor_1freq {
 struct usb_audio_format_type1_descriptor_head head;
 struct usb_audio_format_discrete_sampling_frequency freqs[1];
} __attribute__((packed));
#define LIBOPENCM3_USB_MIDI_H 
#define USB_MIDI_SUBTYPE_MS_DESCRIPTOR_UNDEFINED 0x00
#define USB_MIDI_SUBTYPE_MS_HEADER 0x01
#define USB_MIDI_SUBTYPE_MIDI_IN_JACK 0x02
#define USB_MIDI_SUBTYPE_MIDI_OUT_JACK 0x03
#define USB_MIDI_SUBTYPE_MIDI_ELEMENT 0x04


#define USB_MIDI_SUBTYPE_DESCRIPTOR_UNDEFINED 0x00
#define USB_MIDI_SUBTYPE_MS_GENERAL 0x01


#define USB_MIDI_JACK_TYPE_UNDEFINED 0x00
#define USB_MIDI_JACK_TYPE_EMBEDDED 0x01
#define USB_MIDI_JACK_TYPE_EXTERNAL 0x02


#define USB_MIDI_EP_CONTROL_UNDEFINED 0x00
#define USB_MIDI_ASSOCIATION_CONTROL 0x01



struct usb_midi_header_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint16_t bcdMSC;
 uint16_t wTotalLength;
} __attribute__((packed));


struct usb_midi_in_jack_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bJackType;
 uint8_t bJackID;
 uint8_t iJack;
} __attribute__((packed));


struct usb_midi_out_jack_descriptor_head {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bJackType;
 uint8_t bJackID;
 uint8_t bNrInputPins;

} __attribute__((packed));


struct usb_midi_out_jack_descriptor_body {

 uint8_t baSourceID;
 uint8_t baSourcePin;

} __attribute__((packed));


struct usb_midi_out_jack_descriptor_tail {

 uint8_t iJack;
} __attribute__((packed));






struct usb_midi_out_jack_descriptor {
 struct usb_midi_out_jack_descriptor_head head;
 struct usb_midi_out_jack_descriptor_body source[1];
 struct usb_midi_out_jack_descriptor_tail tail;
} __attribute__((packed));


struct usb_midi_element_descriptor_head {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bElementID;
 uint8_t bNrInputPins;

} __attribute__((packed));


struct usb_midi_element_descriptor_body {

 uint8_t baSourceID;
 uint8_t baSourcePin;

} __attribute__((packed));


struct usb_midi_element_descriptor_tail {

 uint8_t bNrOutputPins;
 uint8_t bInTerminalLink;
 uint8_t bOutTerminalLink;
 uint8_t bElCapsSize;
 uint16_t bmElementCaps;


 uint8_t iElement;
} __attribute__((packed));






struct usb_midi_element_descriptor {
 struct usb_midi_element_descriptor_head head;
 struct usb_midi_element_descriptor_body source[1];
 struct usb_midi_element_descriptor_tail tail;
} __attribute__((packed));


struct usb_midi_endpoint_descriptor_head {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubType;
 uint8_t bNumEmbMIDIJack;
} __attribute__((packed));


struct usb_midi_endpoint_descriptor_body {
 uint8_t baAssocJackID;
} __attribute__((packed));






struct usb_midi_endpoint_descriptor {
 struct usb_midi_endpoint_descriptor_head head;
 struct usb_midi_endpoint_descriptor_body jack[1];
} __attribute__((packed));
#define LIBOPENCM3_SCB_H 
#define LIBOPENCM3_CM3_MEMORYMAP_H 




#define PPBI_BASE (0xE0000000U)




#define ITM_BASE (PPBI_BASE + 0x0000)


#define DWT_BASE (PPBI_BASE + 0x1000)


#define FPB_BASE (PPBI_BASE + 0x2000)




#define SCS_BASE (PPBI_BASE + 0xE000)





#define TPIU_BASE (PPBI_BASE + 0x40000)







#define ITR_BASE (SCS_BASE + 0x0000)



#define SYS_TICK_BASE (SCS_BASE + 0x0010)


#define NVIC_BASE (SCS_BASE + 0x0100)


#define SCB_BASE (SCS_BASE + 0x0D00)


#define MPU_BASE (SCS_BASE + 0x0D90)
#define STIR_BASE (SCS_BASE + 0x0F00)

#define ID_BASE (SCS_BASE + 0x0FD0)
#define CORESIGHT_LSR_OFFSET 0xfb4
#define CORESIGHT_LAR_OFFSET 0xfb0


#define CORESIGHT_LSR_SLK (1<<1)

#define CORESIGHT_LSR_SLI (1<<0)

#define CORESIGHT_LAR_KEY 0xC5ACCE55
#define SCB_CPUID MMIO32(SCB_BASE + 0x00)


#define SCB_ICSR MMIO32(SCB_BASE + 0x04)


#define SCB_VTOR MMIO32(SCB_BASE + 0x08)


#define SCB_AIRCR MMIO32(SCB_BASE + 0x0C)


#define SCB_SCR MMIO32(SCB_BASE + 0x10)


#define SCB_CCR MMIO32(SCB_BASE + 0x14)
#define SCB_SHPR(ipr_id) MMIO8(SCS_BASE + 0xD18 + (ipr_id))



#define SCB_SHCSR MMIO32(SCB_BASE + 0x24)


#define SCB_DFSR MMIO32(SCB_BASE + 0x30)




#define SCB_CFSR MMIO32(SCB_BASE + 0x28)


#define SCB_HFSR MMIO32(SCB_BASE + 0x2C)


#define SCB_MMFAR MMIO32(SCB_BASE + 0x34)


#define SCB_BFAR MMIO32(SCB_BASE + 0x38)


#define SCB_AFSR MMIO32(SCB_BASE + 0x3C)


#define SCB_ID_PFR0 MMIO32(SCB_BASE + 0x40)


#define SCB_ID_PFR1 MMIO32(SCB_BASE + 0x44)


#define SCB_ID_DFR0 MMIO32(SCB_BASE + 0x48)


#define SCB_ID_AFR0 MMIO32(SCB_BASE + 0x4C)


#define SCB_ID_MMFR0 MMIO32(SCB_BASE + 0x50)


#define SCB_ID_MMFR1 MMIO32(SCB_BASE + 0x54)


#define SCB_ID_MMFR2 MMIO32(SCB_BASE + 0x58)


#define SCB_ID_MMFR3 MMIO32(SCB_BASE + 0x5C)


#define SCB_ID_ISAR0 MMIO32(SCB_BASE + 0x60)


#define SCB_ID_ISAR1 MMIO32(SCB_BASE + 0x64)


#define SCB_ID_ISAR2 MMIO32(SCB_BASE + 0x68)


#define SCB_ID_ISAR3 MMIO32(SCB_BASE + 0x6C)


#define SCB_ID_ISAR4 MMIO32(SCB_BASE + 0x70)


#define SCB_CPACR MMIO32(SCB_BASE + 0x88)


#define SCB_FPCCR MMIO32(SCB_BASE + 0x234)


#define SCB_FPCAR MMIO32(SCB_BASE + 0x238)


#define SCB_FPDSCR MMIO32(SCB_BASE + 0x23C)


#define SCB_MVFR0 MMIO32(SCB_BASE + 0x240)


#define SCB_MVFR1 MMIO32(SCB_BASE + 0x244)





#define SCB_CLIDR MMIO32(SCB_BASE + 0x78)


#define SCB_CTR MMIO32(SCB_BASE + 0x7C)


#define SCB_CCSIDR MMIO32(SCB_BASE + 0x80)


#define SCB_CCSELR MMIO32(SCB_BASE + 0x84)


#define SCB_ICIALLU MMIO32(SCB_BASE + 0x250)


#define SCB_ICIMVAU MMIO32(SCB_BASE + 0x258)


#define SCB_DCIMVAC MMIO32(SCB_BASE + 0x25C)


#define SCB_DCISW MMIO32(SCB_BASE + 0x260)


#define SCB_DCCMVAU MMIO32(SCB_BASE + 0x264)


#define SCB_DCCMVAC MMIO32(SCB_BASE + 0x268)


#define SCB_DCCSW MMIO32(SCB_BASE + 0x26C)


#define SCB_DCCIMVAC MMIO32(SCB_BASE + 0x270)


#define SCB_DCCISW MMIO32(SCB_BASE + 0x274)


#define SCB_BPIALL MMIO32(SCB_BASE + 0x278)
#define SCB_CPUID_IMPLEMENTER_LSB 24
#define SCB_CPUID_IMPLEMENTER (0xFF << SCB_CPUID_IMPLEMENTER_LSB)

#define SCB_CPUID_VARIANT_LSB 20
#define SCB_CPUID_VARIANT (0xF << SCB_CPUID_VARIANT_LSB)




#define SCB_CPUID_CONSTANT_LSB 16
#define SCB_CPUID_CONSTANT (0xF << SCB_CPUID_CONSTANT_LSB)
#define SCB_CPUID_CONSTANT_ARMV6 (0xC << SCB_CPUID_CONSTANT_LSB)
#define SCB_CPUID_CONSTANT_ARMV7 (0xF << SCB_CPUID_CONSTANT_LSB)


#define SCB_CPUID_PARTNO_LSB 4
#define SCB_CPUID_PARTNO (0xFFF << SCB_CPUID_PARTNO_LSB)

#define SCB_CPUID_REVISION_LSB 0
#define SCB_CPUID_REVISION (0xF << SCB_CPUID_REVISION_LSB)







#define SCB_ICSR_NMIPENDSET (1 << 31)


#define SCB_ICSR_PENDSVSET (1 << 28)

#define SCB_ICSR_PENDSVCLR (1 << 27)

#define SCB_ICSR_PENDSTSET (1 << 26)

#define SCB_ICSR_PENDSTCLR (1 << 25)


#define SCB_ICSR_ISRPREEMPT (1 << 23)

#define SCB_ICSR_ISRPENDING (1 << 22)

#define SCB_ICSR_VECTPENDING_LSB 12
#define SCB_ICSR_VECTPENDING (0x1FF << SCB_ICSR_VECTPENDING_LSB)

#define SCB_ICSR_RETOBASE (1 << 11)


#define SCB_ICSR_VECTACTIVE_LSB 0
#define SCB_ICSR_VECTACTIVE (0x1FF << SCB_ICSR_VECTACTIVE_LSB)
#define SCB_VTOR_TBLOFF_LSB 9
#define SCB_VTOR_TBLOFF (0x7FFFFF << SCB_VTOR_TBLOFF_LSB)
#define SCB_AIRCR_VECTKEYSTAT_LSB 16
#define SCB_AIRCR_VECTKEYSTAT (0xFFFF << SCB_AIRCR_VECTKEYSTAT_LSB)
#define SCB_AIRCR_VECTKEY (0x05FA << SCB_AIRCR_VECTKEYSTAT_LSB)


#define SCB_AIRCR_ENDIANESS (1 << 15)





#define SCB_AIRCR_PRIGROUP_GROUP16_NOSUB (0x3 << 8)
#define SCB_AIRCR_PRIGROUP_GROUP8_SUB2 (0x4 << 8)
#define SCB_AIRCR_PRIGROUP_GROUP4_SUB4 (0x5 << 8)
#define SCB_AIRCR_PRIGROUP_GROUP2_SUB8 (0x6 << 8)
#define SCB_AIRCR_PRIGROUP_NOGROUP_SUB16 (0x7 << 8)
#define SCB_AIRCR_PRIGROUP_MASK (0x7 << 8)
#define SCB_AIRCR_PRIGROUP_SHIFT 8




#define SCB_AIRCR_SYSRESETREQ (1 << 2)

#define SCB_AIRCR_VECTCLRACTIVE (1 << 1)




#define SCB_AIRCR_VECTRESET (1 << 0)
#define SCB_SCR_SEVONPEND (1 << 4)


#define SCB_SCR_SLEEPDEEP (1 << 2)

#define SCB_SCR_SLEEPONEXIT (1 << 1)
#define SCB_CCR_STKALIGN (1 << 9)




#define SCB_CCR_BFHFNMIGN (1 << 8)


#define SCB_CCR_DIV_0_TRP (1 << 4)



#define SCB_CCR_UNALIGN_TRP (1 << 3)





#define SCB_CCR_USERSETMPEND (1 << 1)

#define SCB_CCR_NONBASETHRDENA (1 << 0)





#define SCB_CCR_BP (1 << 18)

#define SCB_CCR_IC (1 << 17)

#define SCB_CCR_DC (1 << 16)






#define SCB_SHPR_PRI_4_MEMMANAGE 0
#define SCB_SHPR_PRI_5_BUSFAULT 1
#define SCB_SHPR_PRI_6_USAGEFAULT 2
#define SCB_SHPR_PRI_7_RESERVED 3

#define SCB_SHPR_PRI_8_RESERVED 4
#define SCB_SHPR_PRI_9_RESERVED 5
#define SCB_SHPR_PRI_10_RESERVED 6
#define SCB_SHPR_PRI_11_SVCALL 7

#define SCB_SHPR_PRI_12_RESERVED 8
#define SCB_SHPR_PRI_13_RESERVED 9
#define SCB_SHPR_PRI_14_PENDSV 10
#define SCB_SHPR_PRI_15_SYSTICK 11
#define SCB_SHCSR_USGFAULTENA (1 << 18)

#define SCB_SHCSR_BUSFAULTENA (1 << 17)

#define SCB_SHCSR_MEMFAULTENA (1 << 16)



#define SCB_SHCSR_SVCALLPENDED (1 << 15)




#define SCB_SHCSR_BUSFAULTPENDED (1 << 14)

#define SCB_SHCSR_MEMFAULTPENDED (1 << 13)

#define SCB_SHCSR_USGFAULTPENDED (1 << 12)

#define SCB_SHCSR_SYSTICKACT (1 << 11)

#define SCB_SHCSR_PENDSVACT (1 << 10)


#define SCB_SHCSR_MONITORACT (1 << 8)

#define SCB_SHCSR_SVCALLACT (1 << 7)


#define SCB_SHCSR_USGFAULTACT (1 << 3)


#define SCB_SHCSR_BUSFAULTACT (1 << 1)

#define SCB_SHCSR_MEMFAULTACT (1 << 0)





#define SCB_CFSR_DIVBYZERO (1 << 25)

#define SCB_CFSR_UNALIGNED (1 << 24)


#define SCB_CFSR_NOCP (1 << 19)

#define SCB_CFSR_INVPC (1 << 18)

#define SCB_CFSR_INVSTATE (1 << 17)

#define SCB_CFSR_UNDEFINSTR (1 << 16)

#define SCB_CFSR_BFARVALID (1 << 15)


#define SCB_CFSR_STKERR (1 << 12)

#define SCB_CFSR_UNSTKERR (1 << 11)

#define SCB_CFSR_IMPRECISERR (1 << 10)

#define SCB_CFSR_PRECISERR (1 << 9)

#define SCB_CFSR_IBUSERR (1 << 8)

#define SCB_CFSR_MMARVALID (1 << 7)


#define SCB_CFSR_MSTKERR (1 << 4)

#define SCB_CFSR_MUNSTKERR (1 << 3)


#define SCB_CFSR_DACCVIOL (1 << 1)

#define SCB_CFSR_IACCVIOL (1 << 0)




#define SCB_HFSR_DEBUG_VT (1 << 31)

#define SCB_HFSR_FORCED (1 << 30)


#define SCB_HFSR_VECTTBL (1 << 1)
#define SCB_CTR_FORMAT_SHIFT 29
#define SCB_CTR_FORMAT_MASK 0x7

#define SCB_CTR_CWG_SHIFT 24
#define SCB_CTR_CWG_MASK 0xf

#define SCB_CTR_ERG_SHIFT 20
#define SCB_CTR_ERG_MASK 0xf

#define SCB_CTR_DMINLINE_SHIFT 16
#define SCB_CTR_DMINLINE_MASK 0x1f

#define SCB_CTR_IMINLINE_SHIFT 0
#define SCB_CTR_IMINLINE_MASK 0xf






#define SCB_CPACR_NONE 0
#define SCB_CPACR_PRIV 1
#define SCB_CPACR_FULL 3


#define SCB_CPACR_CP10 (1 << 20)

#define SCB_CPACR_CP11 (1 << 22)






struct scb_exception_stack_frame {
 uint32_t r0;
 uint32_t r1;
 uint32_t r2;
 uint32_t r3;
 uint32_t r12;
 uint32_t lr;
 uint32_t pc;
 uint32_t xpsr;
} __attribute__((packed));

#define SCB_GET_EXCEPTION_STACK_FRAME(f) do { __asm__ volatile ("mov %[frameptr], sp" : [frameptr]"=r" (f)); } while (0)





void scb_reset_system(void) __attribute__((noreturn));



void scb_reset_core(void) __attribute__((noreturn));
void scb_set_priority_grouping(uint32_t prigroup);



#define LIBOPENCM3_DESIG_H 


#define LIBOPENCM3_MEMORYMAP_COMMON_H 
#define LIBOPENCM3_MEMORYMAP_H 






#define FLASH_BASE (0x08000000U)
#define PERIPH_BASE (0x40000000U)
#define PERIPH_BASE_APB1 (PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2 (PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB1 (PERIPH_BASE + 0x20000)
#define PERIPH_BASE_AHB2 0x50000000U
#define PERIPH_BASE_AHB3 0x60000000U




#define TIM2_BASE (PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE (PERIPH_BASE_APB1 + 0x0400)
#define TIM4_BASE (PERIPH_BASE_APB1 + 0x0800)
#define TIM5_BASE (PERIPH_BASE_APB1 + 0x0c00)
#define TIM6_BASE (PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE (PERIPH_BASE_APB1 + 0x1400)
#define TIM12_BASE (PERIPH_BASE_APB1 + 0x1800)
#define TIM13_BASE (PERIPH_BASE_APB1 + 0x1c00)
#define TIM14_BASE (PERIPH_BASE_APB1 + 0x2000)
#define LPTIM1_BASE (PERIPH_BASE_APB1 + 0x2400)
#define RTC_BASE (PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE (PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE (PERIPH_BASE_APB1 + 0x3000)
#define I2S2_EXT_BASE (PERIPH_BASE_APB1 + 0x3400)
#define SPI2_BASE (PERIPH_BASE_APB1 + 0x3800)
#define SPI3_BASE (PERIPH_BASE_APB1 + 0x3c00)
#define I2S3_EXT_BASE (PERIPH_BASE_APB1 + 0x4000)
#define USART2_BASE (PERIPH_BASE_APB1 + 0x4400)
#define USART3_BASE (PERIPH_BASE_APB1 + 0x4800)
#define UART4_BASE (PERIPH_BASE_APB1 + 0x4c00)
#define UART5_BASE (PERIPH_BASE_APB1 + 0x5000)
#define I2C1_BASE (PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE (PERIPH_BASE_APB1 + 0x5800)
#define I2C3_BASE (PERIPH_BASE_APB1 + 0x5C00)
#define FMPI2C1_BASE (PERIPH_BASE_APB1 + 0x6000)
#define BX_CAN1_BASE (PERIPH_BASE_APB1 + 0x6400)
#define BX_CAN2_BASE (PERIPH_BASE_APB1 + 0x6800)

#define POWER_CONTROL_BASE (PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE (PERIPH_BASE_APB1 + 0x7400)
#define UART7_BASE (PERIPH_BASE_APB1 + 0x7800)
#define UART8_BASE (PERIPH_BASE_APB1 + 0x7c00)



#define TIM1_BASE (PERIPH_BASE_APB2 + 0x0000)
#define TIM8_BASE (PERIPH_BASE_APB2 + 0x0400)

#define USART1_BASE (PERIPH_BASE_APB2 + 0x1000)
#define USART6_BASE (PERIPH_BASE_APB2 + 0x1400)

#define ADC1_BASE (PERIPH_BASE_APB2 + 0x2000)
#define ADC2_BASE (PERIPH_BASE_APB2 + 0x2100)
#define ADC3_BASE (PERIPH_BASE_APB2 + 0x2200)
#define ADC_COMMON_BASE (PERIPH_BASE_APB2 + 0x2300)

#define SDIO_BASE (PERIPH_BASE_APB2 + 0x2C00)

#define SPI1_BASE (PERIPH_BASE_APB2 + 0x3000)
#define SPI4_BASE (PERIPH_BASE_APB2 + 0x3400)

#define SYSCFG_BASE (PERIPH_BASE_APB2 + 0x3800)
#define EXTI_BASE (PERIPH_BASE_APB2 + 0x3C00)
#define TIM9_BASE (PERIPH_BASE_APB2 + 0x4000)
#define TIM10_BASE (PERIPH_BASE_APB2 + 0x4400)
#define TIM11_BASE (PERIPH_BASE_APB2 + 0x4800)

#define SPI5_BASE (PERIPH_BASE_APB2 + 0x5000)
#define SPI6_BASE (PERIPH_BASE_APB2 + 0x5400)
#define SAI1_BASE (PERIPH_BASE_APB2 + 0x5800)
#define LTDC_BASE (PERIPH_BASE_APB2 + 0x6800)
#define DSI_BASE (PERIPH_BASE_APB2 + 0x6C00)



#define GPIO_PORT_A_BASE (PERIPH_BASE_AHB1 + 0x0000)
#define GPIO_PORT_B_BASE (PERIPH_BASE_AHB1 + 0x0400)
#define GPIO_PORT_C_BASE (PERIPH_BASE_AHB1 + 0x0800)
#define GPIO_PORT_D_BASE (PERIPH_BASE_AHB1 + 0x0C00)
#define GPIO_PORT_E_BASE (PERIPH_BASE_AHB1 + 0x1000)
#define GPIO_PORT_F_BASE (PERIPH_BASE_AHB1 + 0x1400)
#define GPIO_PORT_G_BASE (PERIPH_BASE_AHB1 + 0x1800)
#define GPIO_PORT_H_BASE (PERIPH_BASE_AHB1 + 0x1C00)
#define GPIO_PORT_I_BASE (PERIPH_BASE_AHB1 + 0x2000)
#define GPIO_PORT_J_BASE (PERIPH_BASE_AHB1 + 0x2400)
#define GPIO_PORT_K_BASE (PERIPH_BASE_AHB1 + 0x2800)

#define CRC_BASE (PERIPH_BASE_AHB1 + 0x3000)

#define RCC_BASE (PERIPH_BASE_AHB1 + 0x3800)
#define FLASH_MEM_INTERFACE_BASE (PERIPH_BASE_AHB1 + 0x3C00)
#define BKPSRAM_BASE (PERIPH_BASE_AHB1 + 0x4000)

#define DMA1_BASE (PERIPH_BASE_AHB1 + 0x6000)
#define DMA2_BASE (PERIPH_BASE_AHB1 + 0x6400)

#define ETHERNET_BASE (PERIPH_BASE_AHB1 + 0x8000)
#define DMA2D_BASE (PERIPH_BASE_AHB1 + 0xB000U)

#define USB_OTG_HS_BASE (PERIPH_BASE_AHB1 + 0x20000)



#define USB_OTG_FS_BASE (PERIPH_BASE_AHB2 + 0x00000)

#define DCMI_BASE (PERIPH_BASE_AHB2 + 0x50000)

#define CRYP_BASE (PERIPH_BASE_AHB2 + 0x60000)
#define HASH_BASE (PERIPH_BASE_AHB2 + 0x60400)

#define RNG_BASE (PERIPH_BASE_AHB2 + 0x60800)




#define FMC_BANK1 (PERIPH_BASE_AHB3)

#define FMC_BANK2 (PERIPH_BASE_AHB3 + 0x10000000U)

#define FMC_BANK3 (PERIPH_BASE_AHB3 + 0x20000000U)

#define QUADSPI_BANK (PERIPH_BASE_AHB3 + 0x30000000U)
#define FSMC_BASE (PERIPH_BASE_AHB3 + 0x40000000U)
#define FMC_BASE (PERIPH_BASE_AHB3 + 0x40000000U)
#define QUADSPI_BASE (PERIPH_BASE_AHB3 + 0x40001000U)

#define FMC_BANK5 (PERIPH_BASE_AHB3 + 0x60000000U)

#define FMC_BANK6 (PERIPH_BASE_AHB3 + 0x70000000U)


#define DBGMCU_BASE (PPBI_BASE + 0x00042000)


#define DESIG_FLASH_SIZE_BASE (0x1FFF7A22U)
#define DESIG_UNIQUE_ID_BASE (0x1FFF7A10U)
#define DESIG_UNIQUE_ID0 MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1 MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2 MMIO32(DESIG_UNIQUE_ID_BASE + 8)


#define ST_VREFINT_CAL MMIO16(0x1FFF7A2A)
#define ST_TSENSE_CAL1_30C MMIO16(0x1FFF7A2C)
#define ST_TSENSE_CAL2_110C MMIO16(0x1FFF7A2E)









uint16_t desig_get_flash_size(void);






void desig_get_unique_id(uint32_t *result);







void desig_get_unique_id_as_string(char *string,
       unsigned int string_len);
void desig_get_unique_id_as_dfu(char *string);


#define LIBOPENCM3_RCC_H 

#define LIBOPENCM3_PWR_H 

#define LIBOPENCM3_PWR_COMMON_V1_H 






#define PWR_CR MMIO32(POWER_CONTROL_BASE + 0x00)


#define PWR_CSR MMIO32(POWER_CONTROL_BASE + 0x04)






#define PWR_CR_DBP (1 << 8)


#define PWR_CR_PLS_LSB 5




#define PWR_CR_PLS_2V2 (0x0 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V3 (0x1 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V4 (0x2 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V5 (0x3 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V6 (0x4 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V7 (0x5 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V8 (0x6 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V9 (0x7 << PWR_CR_PLS_LSB)

#define PWR_CR_PLS_MASK (0x7 << PWR_CR_PLS_LSB)


#define PWR_CR_PVDE (1 << 4)


#define PWR_CR_CSBF (1 << 3)


#define PWR_CR_CWUF (1 << 2)


#define PWR_CR_PDDS (1 << 1)


#define PWR_CR_LPDS (1 << 0)






#define PWR_CSR_EWUP (1 << 8)




#define PWR_CSR_PVDO (1 << 2)


#define PWR_CSR_SBF (1 << 1)


#define PWR_CSR_WUF (1 << 0)





void pwr_disable_backup_domain_write_protect(void);
void pwr_enable_backup_domain_write_protect(void);
void pwr_enable_power_voltage_detect(uint32_t pvd_level);
void pwr_disable_power_voltage_detect(void);
void pwr_clear_standby_flag(void);
void pwr_clear_wakeup_flag(void);
void pwr_set_standby_mode(void);
void pwr_set_stop_mode(void);
void pwr_voltage_regulator_on_in_stop(void);
void pwr_voltage_regulator_low_power_in_stop(void);
void pwr_enable_wakeup_pin(void);
void pwr_disable_wakeup_pin(void);

_Bool 
    pwr_voltage_high(void);

_Bool 
    pwr_get_standby_flag(void);

_Bool 
    pwr_get_wakeup_flag(void);


#define PWR_CR_VOS_SHIFT 14
#define PWR_CR_VOS_MASK 0x3


#define PWR_CR_ADCDC1 (1 << 13)


#define PWR_CR_MRLVDS (1 << 11)
#define PWR_CR_MRUDS PWR_CR_MRLVDS


#define PWR_CR_LPLVDS (1 << 10)
#define PWR_CR_LPUDS PWR_CR_LPLVDS


#define PWR_CR_FPDS (1 << 9)




#define PWR_CSR_VOSRDY (1 << 14)


#define PWR_CSR_BRE (1 << 9)


#define PWR_CSR_BRR (1 << 3)



enum pwr_vos_scale {
 PWR_SCALE1 = 0x3,
 PWR_SCALE2 = 0x2,
 PWR_SCALE3 = 0x1,
};



void pwr_set_vos_scale(enum pwr_vos_scale scale);







#define RCC_CR MMIO32(RCC_BASE + 0x00)

#define RCC_PLLCFGR MMIO32(RCC_BASE + 0x04)

#define RCC_CFGR MMIO32(RCC_BASE + 0x08)

#define RCC_CIR MMIO32(RCC_BASE + 0x0c)

#define RCC_AHB1RSTR MMIO32(RCC_BASE + 0x10)

#define RCC_AHB2RSTR MMIO32(RCC_BASE + 0x14)

#define RCC_AHB3RSTR MMIO32(RCC_BASE + 0x18)


#define RCC_APB1RSTR MMIO32(RCC_BASE + 0x20)

#define RCC_APB2RSTR MMIO32(RCC_BASE + 0x24)



#define RCC_AHB1ENR MMIO32(RCC_BASE + 0x30)

#define RCC_AHB2ENR MMIO32(RCC_BASE + 0x34)

#define RCC_AHB3ENR MMIO32(RCC_BASE + 0x38)


#define RCC_APB1ENR MMIO32(RCC_BASE + 0x40)

#define RCC_APB2ENR MMIO32(RCC_BASE + 0x44)



#define RCC_AHB1LPENR MMIO32(RCC_BASE + 0x50)

#define RCC_AHB2LPENR MMIO32(RCC_BASE + 0x54)

#define RCC_AHB3LPENR MMIO32(RCC_BASE + 0x58)


#define RCC_APB1LPENR MMIO32(RCC_BASE + 0x60)

#define RCC_APB2LPENR MMIO32(RCC_BASE + 0x64)



#define RCC_BDCR MMIO32(RCC_BASE + 0x70)

#define RCC_CSR MMIO32(RCC_BASE + 0x74)



#define RCC_SSCGR MMIO32(RCC_BASE + 0x80)

#define RCC_PLLI2SCFGR MMIO32(RCC_BASE + 0x84)

#define RCC_PLLSAICFGR MMIO32(RCC_BASE + 0x88)

#define RCC_DCKCFGR MMIO32(RCC_BASE + 0x8C)

#define RCC_CKGATENR MMIO32(RCC_BASE + 0x90)

#define RCC_DCKCFGR2 MMIO32(RCC_BASE + 0x94)






#define RCC_CR_PLLSAIRDY (1 << 29)
#define RCC_CR_PLLSAION (1 << 28)
#define RCC_CR_PLLI2SRDY (1 << 27)
#define RCC_CR_PLLI2SON (1 << 26)
#define RCC_CR_PLLRDY (1 << 25)
#define RCC_CR_PLLON (1 << 24)
#define RCC_CR_CSSON (1 << 19)
#define RCC_CR_HSEBYP (1 << 18)
#define RCC_CR_HSERDY (1 << 17)
#define RCC_CR_HSEON (1 << 16)


#define RCC_CR_HSITRIM_SHIFT 3
#define RCC_CR_HSITRIM_MASK 0x1f
#define RCC_CR_HSIRDY (1 << 1)
#define RCC_CR_HSION (1 << 0)







#define RCC_PLLCFGR_PLLR_SHIFT 28
#define RCC_PLLCFGR_PLLR_MASK 0x7

#define RCC_PLLCFGR_PLLQ_SHIFT 24
#define RCC_PLLCFGR_PLLQ_MASK 0xf
#define RCC_PLLCFGR_PLLSRC (1 << 22)

#define RCC_PLLCFGR_PLLP_SHIFT 16
#define RCC_PLLCFGR_PLLP_MASK 0x3

#define RCC_PLLCFGR_PLLN_SHIFT 6
#define RCC_PLLCFGR_PLLN_MASK 0x1ff

#define RCC_PLLCFGR_PLLM_SHIFT 0
#define RCC_PLLCFGR_PLLM_MASK 0x3f







#define RCC_CFGR_MCO2_SHIFT 30
#define RCC_CFGR_MCO2_MASK 0x3
#define RCC_CFGR_MCO2_SYSCLK 0x0
#define RCC_CFGR_MCO2_PLLI2S 0x1
#define RCC_CFGR_MCO2_HSE 0x2
#define RCC_CFGR_MCO2_PLL 0x3


#define RCC_CFGR_MCO2PRE_SHIFT 27
#define RCC_CFGR_MCO2PRE_MASK 0x7
#define RCC_CFGR_MCO1PRE_SHIFT 24
#define RCC_CFGR_MCO1PRE_MASK 0x7
#define RCC_CFGR_MCOPRE_DIV_NONE 0x0
#define RCC_CFGR_MCOPRE_DIV_2 0x4
#define RCC_CFGR_MCOPRE_DIV_3 0x5
#define RCC_CFGR_MCOPRE_DIV_4 0x6
#define RCC_CFGR_MCOPRE_DIV_5 0x7


#define RCC_CFGR_PLLSRC_HSI_CLK 0x0
#define RCC_CFGR_PLLSRC_HSE_CLK 0x1


#define RCC_CFGR_I2SSRC (1 << 23)


#define RCC_CFGR_MCO1_SHIFT 21
#define RCC_CFGR_MCO1_MASK 0x3
#define RCC_CFGR_MCO1_HSI 0x0
#define RCC_CFGR_MCO1_LSE 0x1
#define RCC_CFGR_MCO1_HSE 0x2
#define RCC_CFGR_MCO1_PLL 0x3
#define RCC_CFGR_MCO_SHIFT RCC_CFGR_MCO1_SHIFT
#define RCC_CFGR_MCO_MASK RCC_CFGR_MCO1_MASK


#define RCC_CFGR_RTCPRE_SHIFT 16
#define RCC_CFGR_RTCPRE_MASK 0x1f

#define RCC_CFGR_PPRE2_SHIFT 13
#define RCC_CFGR_PPRE2_MASK 0x7
#define RCC_CFGR_PPRE1_SHIFT 10
#define RCC_CFGR_PPRE1_MASK 0x7




#define RCC_CFGR_PPRE_NODIV 0x0
#define RCC_CFGR_PPRE_DIV2 0x4
#define RCC_CFGR_PPRE_DIV4 0x5
#define RCC_CFGR_PPRE_DIV8 0x6
#define RCC_CFGR_PPRE_DIV16 0x7


#define RCC_CFGR_HPRE_SHIFT 4
#define RCC_CFGR_HPRE_MASK 0xf


#define RCC_CFGR_HPRE_NODIV 0x0
#define RCC_CFGR_HPRE_DIV2 (0x8 + 0)
#define RCC_CFGR_HPRE_DIV4 (0x8 + 1)
#define RCC_CFGR_HPRE_DIV8 (0x8 + 2)
#define RCC_CFGR_HPRE_DIV16 (0x8 + 3)
#define RCC_CFGR_HPRE_DIV64 (0x8 + 4)
#define RCC_CFGR_HPRE_DIV128 (0x8 + 5)
#define RCC_CFGR_HPRE_DIV256 (0x8 + 6)
#define RCC_CFGR_HPRE_DIV512 (0x8 + 7)



#define RCC_CFGR_SWS_SHIFT 2
#define RCC_CFGR_SWS_MASK 0x3
#define RCC_CFGR_SWS_HSI 0x0
#define RCC_CFGR_SWS_HSE 0x1
#define RCC_CFGR_SWS_PLL 0x2


#define RCC_CFGR_SW_SHIFT 0
#define RCC_CFGR_SW_HSI 0x0
#define RCC_CFGR_SW_HSE 0x1
#define RCC_CFGR_SW_PLL 0x2







#define RCC_CFGR_PPRE_DIV_NONE 0x0
#define RCC_CFGR_PPRE_DIV_2 0x4
#define RCC_CFGR_PPRE_DIV_4 0x5
#define RCC_CFGR_PPRE_DIV_8 0x6
#define RCC_CFGR_PPRE_DIV_16 0x7

#define RCC_CFGR_HPRE_DIV_NONE 0x0
#define RCC_CFGR_HPRE_DIV_2 (0x8 + 0)
#define RCC_CFGR_HPRE_DIV_4 (0x8 + 1)
#define RCC_CFGR_HPRE_DIV_8 (0x8 + 2)
#define RCC_CFGR_HPRE_DIV_16 (0x8 + 3)
#define RCC_CFGR_HPRE_DIV_64 (0x8 + 4)
#define RCC_CFGR_HPRE_DIV_128 (0x8 + 5)
#define RCC_CFGR_HPRE_DIV_256 (0x8 + 6)
#define RCC_CFGR_HPRE_DIV_512 (0x8 + 7)







#define RCC_CIR_CSSC (1 << 23)


#define RCC_CIR_PLLSAIRDYC (1 << 22)
#define RCC_CIR_PLLI2SRDYC (1 << 21)
#define RCC_CIR_PLLRDYC (1 << 20)
#define RCC_CIR_HSERDYC (1 << 19)
#define RCC_CIR_HSIRDYC (1 << 18)
#define RCC_CIR_LSERDYC (1 << 17)
#define RCC_CIR_LSIRDYC (1 << 16)


#define RCC_CIR_PLLSAIRDYIE (1 << 14)
#define RCC_CIR_PLLI2SRDYIE (1 << 13)
#define RCC_CIR_PLLRDYIE (1 << 12)
#define RCC_CIR_HSERDYIE (1 << 11)
#define RCC_CIR_HSIRDYIE (1 << 10)
#define RCC_CIR_LSERDYIE (1 << 9)
#define RCC_CIR_LSIRDYIE (1 << 8)


#define RCC_CIR_CSSF (1 << 7)


#define RCC_CIR_PLLSAIRDYF (1 << 6)
#define RCC_CIR_PLLI2SRDYF (1 << 5)
#define RCC_CIR_PLLRDYF (1 << 4)
#define RCC_CIR_HSERDYF (1 << 3)
#define RCC_CIR_HSIRDYF (1 << 2)
#define RCC_CIR_LSERDYF (1 << 1)
#define RCC_CIR_LSIRDYF (1 << 0)






#define RCC_AHB1RSTR_OTGHSRST (1 << 29)
#define RCC_AHB1RSTR_ETHMACRST (1 << 25)
#define RCC_AHB1RSTR_DMA2DRST (1 << 23)
#define RCC_AHB1RSTR_DMA2RST (1 << 22)
#define RCC_AHB1RSTR_DMA1RST (1 << 21)
#define RCC_AHB1RSTR_CRCRST (1 << 12)
#define RCC_AHB1RSTR_GPIOKRST (1 << 10)
#define RCC_AHB1RSTR_GPIOJRST (1 << 9)
#define RCC_AHB1RSTR_GPIOIRST (1 << 8)
#define RCC_AHB1RSTR_GPIOHRST (1 << 7)
#define RCC_AHB1RSTR_GPIOGRST (1 << 6)
#define RCC_AHB1RSTR_GPIOFRST (1 << 5)
#define RCC_AHB1RSTR_GPIOERST (1 << 4)
#define RCC_AHB1RSTR_GPIODRST (1 << 3)
#define RCC_AHB1RSTR_GPIOCRST (1 << 2)
#define RCC_AHB1RSTR_GPIOBRST (1 << 1)
#define RCC_AHB1RSTR_GPIOARST (1 << 0)






#define RCC_AHB1RSTR_IOPKRST RCC_AHB1RSTR_GPIOKRST
#define RCC_AHB1RSTR_IOPJRST RCC_AHB1RSTR_GPIOJRST
#define RCC_AHB1RSTR_IOPIRST RCC_AHB1RSTR_GPIOIRST
#define RCC_AHB1RSTR_IOPHRST RCC_AHB1RSTR_GPIOHRST
#define RCC_AHB1RSTR_IOPGRST RCC_AHB1RSTR_GPIOGRST
#define RCC_AHB1RSTR_IOPFRST RCC_AHB1RSTR_GPIOFRST
#define RCC_AHB1RSTR_IOPERST RCC_AHB1RSTR_GPIOERST
#define RCC_AHB1RSTR_IOPDRST RCC_AHB1RSTR_GPIODRST
#define RCC_AHB1RSTR_IOPCRST RCC_AHB1RSTR_GPIOCRST
#define RCC_AHB1RSTR_IOPBRST RCC_AHB1RSTR_GPIOBRST
#define RCC_AHB1RSTR_IOPARST RCC_AHB1RSTR_GPIOARST




#define RCC_AHB2RSTR_OTGFSRST (1 << 7)
#define RCC_AHB2RSTR_RNGRST (1 << 6)
#define RCC_AHB2RSTR_HASHRST (1 << 5)
#define RCC_AHB2RSTR_CRYPRST (1 << 4)
#define RCC_AHB2RSTR_DCMIRST (1 << 0)




#define RCC_AHB3RSTR_QSPIRST (1 << 1)
#define RCC_AHB3RSTR_FSMCRST (1 << 0)





#define RCC_APB1RSTR_UART8RST (1 << 31)
#define RCC_APB1RSTR_UART7RST (1 << 30)
#define RCC_APB1RSTR_DACRST (1 << 29)
#define RCC_APB1RSTR_PWRRST (1 << 28)
#define RCC_APB1RSTR_CAN2RST (1 << 26)
#define RCC_APB1RSTR_CAN1RST (1 << 25)
#define RCC_APB1RSTR_I2C3RST (1 << 23)
#define RCC_APB1RSTR_I2C2RST (1 << 22)
#define RCC_APB1RSTR_I2C1RST (1 << 21)
#define RCC_APB1RSTR_UART5RST (1 << 20)
#define RCC_APB1RSTR_UART4RST (1 << 19)
#define RCC_APB1RSTR_USART3RST (1 << 18)
#define RCC_APB1RSTR_USART2RST (1 << 17)
#define RCC_APB1RSTR_SPI3RST (1 << 15)
#define RCC_APB1RSTR_SPI2RST (1 << 14)
#define RCC_APB1RSTR_WWDGRST (1 << 11)
#define RCC_APB1RSTR_TIM14RST (1 << 8)
#define RCC_APB1RSTR_TIM13RST (1 << 7)
#define RCC_APB1RSTR_TIM12RST (1 << 6)
#define RCC_APB1RSTR_TIM7RST (1 << 5)
#define RCC_APB1RSTR_TIM6RST (1 << 4)
#define RCC_APB1RSTR_TIM5RST (1 << 3)
#define RCC_APB1RSTR_TIM4RST (1 << 2)
#define RCC_APB1RSTR_TIM3RST (1 << 1)
#define RCC_APB1RSTR_TIM2RST (1 << 0)




#define RCC_APB2RSTR_DSIRST (1 << 27)
#define RCC_APB2RSTR_LTDCRST (1 << 26)
#define RCC_APB2RSTR_SAI1RST (1 << 22)
#define RCC_APB2RSTR_SPI6RST (1 << 21)
#define RCC_APB2RSTR_SPI5RST (1 << 20)
#define RCC_APB2RSTR_TIM11RST (1 << 18)
#define RCC_APB2RSTR_TIM10RST (1 << 17)
#define RCC_APB2RSTR_TIM9RST (1 << 16)
#define RCC_APB2RSTR_SYSCFGRST (1 << 14)
#define RCC_APB2RSTR_SPI4RST (1 << 13)
#define RCC_APB2RSTR_SPI1RST (1 << 12)
#define RCC_APB2RSTR_SDIORST (1 << 11)
#define RCC_APB2RSTR_ADCRST (1 << 8)
#define RCC_APB2RSTR_USART6RST (1 << 5)
#define RCC_APB2RSTR_USART1RST (1 << 4)
#define RCC_APB2RSTR_TIM8RST (1 << 1)
#define RCC_APB2RSTR_TIM1RST (1 << 0)






#define RCC_AHB1ENR_OTGHSULPIEN (1 << 30)
#define RCC_AHB1ENR_OTGHSEN (1 << 29)
#define RCC_AHB1ENR_ETHMACPTPEN (1 << 28)
#define RCC_AHB1ENR_ETHMACRXEN (1 << 27)
#define RCC_AHB1ENR_ETHMACTXEN (1 << 26)
#define RCC_AHB1ENR_ETHMACEN (1 << 25)
#define RCC_AHB1ENR_DMA2DEN (1 << 23)
#define RCC_AHB1ENR_DMA2EN (1 << 22)
#define RCC_AHB1ENR_DMA1EN (1 << 21)
#define RCC_AHB1ENR_CCMDATARAMEN (1 << 20)
#define RCC_AHB1ENR_BKPSRAMEN (1 << 18)
#define RCC_AHB1ENR_CRCEN (1 << 12)
#define RCC_AHB1ENR_GPIOKEN (1 << 10)
#define RCC_AHB1ENR_GPIOJEN (1 << 9)
#define RCC_AHB1ENR_GPIOIEN (1 << 8)
#define RCC_AHB1ENR_GPIOHEN (1 << 7)
#define RCC_AHB1ENR_GPIOGEN (1 << 6)
#define RCC_AHB1ENR_GPIOFEN (1 << 5)
#define RCC_AHB1ENR_GPIOEEN (1 << 4)
#define RCC_AHB1ENR_GPIODEN (1 << 3)
#define RCC_AHB1ENR_GPIOCEN (1 << 2)
#define RCC_AHB1ENR_GPIOBEN (1 << 1)
#define RCC_AHB1ENR_GPIOAEN (1 << 0)






#define RCC_AHB1ENR_IOPKEN RCC_AHB1ENR_GPIOKEN
#define RCC_AHB1ENR_IOPJEN RCC_AHB1ENR_GPIOJEN
#define RCC_AHB1ENR_IOPIEN RCC_AHB1ENR_GPIOIEN
#define RCC_AHB1ENR_IOPHEN RCC_AHB1ENR_GPIOHEN
#define RCC_AHB1ENR_IOPGEN RCC_AHB1ENR_GPIOGEN
#define RCC_AHB1ENR_IOPFEN RCC_AHB1ENR_GPIOFEN
#define RCC_AHB1ENR_IOPEEN RCC_AHB1ENR_GPIOEEN
#define RCC_AHB1ENR_IOPDEN RCC_AHB1ENR_GPIODEN
#define RCC_AHB1ENR_IOPCEN RCC_AHB1ENR_GPIOCEN
#define RCC_AHB1ENR_IOPBEN RCC_AHB1ENR_GPIOBEN
#define RCC_AHB1ENR_IOPAEN RCC_AHB1ENR_GPIOAEN




#define RCC_AHB2ENR_OTGFSEN (1 << 7)
#define RCC_AHB2ENR_RNGEN (1 << 6)
#define RCC_AHB2ENR_HASHEN (1 << 5)
#define RCC_AHB2ENR_CRYPEN (1 << 4)
#define RCC_AHB2ENR_DCMIEN (1 << 0)




#define RCC_AHB3ENR_QSPIEN (1 << 1)
#define RCC_AHB3ENR_FSMCEN (1 << 0)

#define RCC_AHB3ENR_FMCEN (1 << 0)





#define RCC_APB1ENR_UART8EN (1 << 31)
#define RCC_APB1ENR_UART7EN (1 << 30)
#define RCC_APB1ENR_DACEN (1 << 29)
#define RCC_APB1ENR_PWREN (1 << 28)
#define RCC_APB1ENR_CAN2EN (1 << 26)
#define RCC_APB1ENR_CAN1EN (1 << 25)
#define RCC_APB1ENR_I2C3EN (1 << 23)
#define RCC_APB1ENR_I2C2EN (1 << 22)
#define RCC_APB1ENR_I2C1EN (1 << 21)
#define RCC_APB1ENR_UART5EN (1 << 20)
#define RCC_APB1ENR_UART4EN (1 << 19)
#define RCC_APB1ENR_USART3EN (1 << 18)
#define RCC_APB1ENR_USART2EN (1 << 17)
#define RCC_APB1ENR_SPI3EN (1 << 15)
#define RCC_APB1ENR_SPI2EN (1 << 14)
#define RCC_APB1ENR_WWDGEN (1 << 11)
#define RCC_APB1ENR_TIM14EN (1 << 8)
#define RCC_APB1ENR_TIM13EN (1 << 7)
#define RCC_APB1ENR_TIM12EN (1 << 6)
#define RCC_APB1ENR_TIM7EN (1 << 5)
#define RCC_APB1ENR_TIM6EN (1 << 4)
#define RCC_APB1ENR_TIM5EN (1 << 3)
#define RCC_APB1ENR_TIM4EN (1 << 2)
#define RCC_APB1ENR_TIM3EN (1 << 1)
#define RCC_APB1ENR_TIM2EN (1 << 0)




#define RCC_APB2ENR_DSIEN (1 << 27)
#define RCC_APB2ENR_LTDCEN (1 << 26)
#define RCC_APB2ENR_SAI1EN (1 << 22)
#define RCC_APB2ENR_SPI6EN (1 << 21)
#define RCC_APB2ENR_SPI5EN (1 << 20)
#define RCC_APB2ENR_TIM11EN (1 << 18)
#define RCC_APB2ENR_TIM10EN (1 << 17)
#define RCC_APB2ENR_TIM9EN (1 << 16)
#define RCC_APB2ENR_SYSCFGEN (1 << 14)
#define RCC_APB2ENR_SPI4EN (1 << 13)
#define RCC_APB2ENR_SPI1EN (1 << 12)
#define RCC_APB2ENR_SDIOEN (1 << 11)
#define RCC_APB2ENR_ADC3EN (1 << 10)
#define RCC_APB2ENR_ADC2EN (1 << 9)
#define RCC_APB2ENR_ADC1EN (1 << 8)
#define RCC_APB2ENR_USART6EN (1 << 5)
#define RCC_APB2ENR_USART1EN (1 << 4)
#define RCC_APB2ENR_TIM8EN (1 << 1)
#define RCC_APB2ENR_TIM1EN (1 << 0)




#define RCC_AHB1LPENR_OTGHSULPILPEN (1 << 30)
#define RCC_AHB1LPENR_OTGHSLPEN (1 << 29)
#define RCC_AHB1LPENR_ETHMACPTPLPEN (1 << 28)
#define RCC_AHB1LPENR_ETHMACRXLPEN (1 << 27)
#define RCC_AHB1LPENR_ETHMACTXLPEN (1 << 26)
#define RCC_AHB1LPENR_ETHMACLPEN (1 << 25)
#define RCC_AHB1LPENR_DMA2DLPEN (1 << 23)
#define RCC_AHB1LPENR_DMA2LPEN (1 << 22)
#define RCC_AHB1LPENR_DMA1LPEN (1 << 21)
#define RCC_AHB1LPENR_SRAM3LPEN (1 << 19)
#define RCC_AHB1LPENR_BKPSRAMLPEN (1 << 18)
#define RCC_AHB1LPENR_SRAM2LPEN (1 << 17)
#define RCC_AHB1LPENR_SRAM1LPEN (1 << 16)
#define RCC_AHB1LPENR_FLITFLPEN (1 << 15)
#define RCC_AHB1LPENR_CRCLPEN (1 << 12)
#define RCC_AHB1LPENR_GPIOKLPEN (1 << 10)
#define RCC_AHB1LPENR_GPIOJLPEN (1 << 9)
#define RCC_AHB1LPENR_GPIOILPEN (1 << 8)
#define RCC_AHB1LPENR_GPIOHLPEN (1 << 7)
#define RCC_AHB1LPENR_GPIOGLPEN (1 << 6)
#define RCC_AHB1LPENR_GPIOFLPEN (1 << 5)
#define RCC_AHB1LPENR_GPIOELPEN (1 << 4)
#define RCC_AHB1LPENR_GPIODLPEN (1 << 3)
#define RCC_AHB1LPENR_GPIOCLPEN (1 << 2)
#define RCC_AHB1LPENR_GPIOBLPEN (1 << 1)
#define RCC_AHB1LPENR_GPIOALPEN (1 << 0)





#define RCC_AHB1LPENR_IOPKLPEN RCC_AHB1LPENR_GPIOKLPEN
#define RCC_AHB1LPENR_IOPJLPEN RCC_AHB1LPENR_GPIOJLPEN
#define RCC_AHB1LPENR_IOPILPEN RCC_AHB1LPENR_GPIOILPEN
#define RCC_AHB1LPENR_IOPHLPEN RCC_AHB1LPENR_GPIOHLPEN
#define RCC_AHB1LPENR_IOPGLPEN RCC_AHB1LPENR_GPIOGLPEN
#define RCC_AHB1LPENR_IOPFLPEN RCC_AHB1LPENR_GPIOFLPEN
#define RCC_AHB1LPENR_IOPELPEN RCC_AHB1LPENR_GPIOELPEN
#define RCC_AHB1LPENR_IOPDLPEN RCC_AHB1LPENR_GPIODLPEN
#define RCC_AHB1LPENR_IOPCLPEN RCC_AHB1LPENR_GPIOCLPEN
#define RCC_AHB1LPENR_IOPBLPEN RCC_AHB1LPENR_GPIOBLPEN
#define RCC_AHB1LPENR_IOPALPEN RCC_AHB1LPENR_GPIOALPEN




#define RCC_AHB2LPENR_OTGFSLPEN (1 << 7)
#define RCC_AHB2LPENR_RNGLPEN (1 << 6)
#define RCC_AHB2LPENR_HASHLPEN (1 << 5)
#define RCC_AHB2LPENR_CRYPLPEN (1 << 4)
#define RCC_AHB2LPENR_DCMILPEN (1 << 0)



#define RCC_AHB3LPENR_QSPIEN (1 << 1)
#define RCC_AHB3LPENR_FSMCLPEN (1 << 0)
#define RCC_AHB3LPENR_FMCLPEN (1 << 0)





#define RCC_APB1LPENR_UART8EN (1 << 31)
#define RCC_APB1LPENR_UART7EN (1 << 30)
#define RCC_APB1LPENR_DACLPEN (1 << 29)
#define RCC_APB1LPENR_PWRLPEN (1 << 28)
#define RCC_APB1LPENR_CAN2LPEN (1 << 26)
#define RCC_APB1LPENR_CAN1LPEN (1 << 25)
#define RCC_APB1LPENR_I2C3LPEN (1 << 23)
#define RCC_APB1LPENR_I2C2LPEN (1 << 22)
#define RCC_APB1LPENR_I2C1LPEN (1 << 21)
#define RCC_APB1LPENR_UART5LPEN (1 << 20)
#define RCC_APB1LPENR_UART4LPEN (1 << 19)
#define RCC_APB1LPENR_USART3LPEN (1 << 18)
#define RCC_APB1LPENR_USART2LPEN (1 << 17)
#define RCC_APB1LPENR_SPI3LPEN (1 << 15)
#define RCC_APB1LPENR_SPI2LPEN (1 << 14)
#define RCC_APB1LPENR_WWDGLPEN (1 << 11)
#define RCC_APB1LPENR_TIM14LPEN (1 << 8)
#define RCC_APB1LPENR_TIM13LPEN (1 << 7)
#define RCC_APB1LPENR_TIM12LPEN (1 << 6)
#define RCC_APB1LPENR_TIM7LPEN (1 << 5)
#define RCC_APB1LPENR_TIM6LPEN (1 << 4)
#define RCC_APB1LPENR_TIM5LPEN (1 << 3)
#define RCC_APB1LPENR_TIM4LPEN (1 << 2)
#define RCC_APB1LPENR_TIM3LPEN (1 << 1)
#define RCC_APB1LPENR_TIM2LPEN (1 << 0)



#define RCC_APB2LPENR_DSILPEN (1 << 27)
#define RCC_APB2LPENR_LTDCLPEN (1 << 26)
#define RCC_APB2LPENR_SAI1LPEN (1 << 22)
#define RCC_APB2LPENR_SPI6LPEN (1 << 21)
#define RCC_APB2LPENR_SPI5LPEN (1 << 20)
#define RCC_APB2LPENR_TIM11LPEN (1 << 18)
#define RCC_APB2LPENR_TIM10LPEN (1 << 17)
#define RCC_APB2LPENR_TIM9LPEN (1 << 16)
#define RCC_APB2LPENR_SYSCFGLPEN (1 << 14)
#define RCC_APB2LPENR_SPI1LPEN (1 << 12)
#define RCC_APB2LPENR_SDIOLPEN (1 << 11)
#define RCC_APB2LPENR_ADC3LPEN (1 << 10)
#define RCC_APB2LPENR_ADC2LPEN (1 << 9)
#define RCC_APB2LPENR_ADC1LPEN (1 << 8)
#define RCC_APB2LPENR_USART6LPEN (1 << 5)
#define RCC_APB2LPENR_USART1LPEN (1 << 4)
#define RCC_APB2LPENR_TIM8LPEN (1 << 1)
#define RCC_APB2LPENR_TIM1LPEN (1 << 0)






#define RCC_BDCR_BDRST (1 << 16)
#define RCC_BDCR_RTCEN (1 << 15)

#define RCC_BDCR_RTCSEL_SHIFT 8
#define RCC_BDCR_RTCSEL_MASK 0x3
#define RCC_BDCR_RTCSEL_NONE 0
#define RCC_BDCR_RTCSEL_LSE 1
#define RCC_BDCR_RTCSEL_LSI 2
#define RCC_BDCR_RTCSEL_HSE 3
#define RCC_BDCR_LSEMOD (1 << 3)
#define RCC_BDCR_LSEBYP (1 << 2)
#define RCC_BDCR_LSERDY (1 << 1)
#define RCC_BDCR_LSEON (1 << 0)






#define RCC_CSR_LPWRRSTF (1 << 31)
#define RCC_CSR_WWDGRSTF (1 << 30)
#define RCC_CSR_IWDGRSTF (1 << 29)
#define RCC_CSR_SFTRSTF (1 << 28)
#define RCC_CSR_PORRSTF (1 << 27)
#define RCC_CSR_PINRSTF (1 << 26)
#define RCC_CSR_BORRSTF (1 << 25)
#define RCC_CSR_RMVF (1 << 24)
#define RCC_CSR_RESET_FLAGS (RCC_CSR_LPWRRSTF | RCC_CSR_WWDGRSTF | RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF | RCC_CSR_PORRSTF | RCC_CSR_PINRSTF | RCC_CSR_BORRSTF)


#define RCC_CSR_LSIRDY (1 << 1)
#define RCC_CSR_LSION (1 << 0)
#define RCC_SSCGR_SSCGEN (1 << 31)
#define RCC_SSCGR_SPREADSEL (1 << 30)

#define RCC_SSCGR_INCSTEP_SHIFT 13
#define RCC_SSCGR_INCSTEP_MASK 0x7fff

#define RCC_SSCGR_MODPER_SHIFT 0
#define RCC_SSCGR_MODPER_MASK 0x1fff
#define RCC_PLLI2SCFGR_PLLI2SR_SHIFT 28
#define RCC_PLLI2SCFGR_PLLI2SR_MASK 0x7

#define RCC_PLLI2SCFGR_PLLI2SQ_SHIFT 24
#define RCC_PLLI2SCFGR_PLLI2SQ_MASK 0xf

#define RCC_PLLI2SCFGR_PLLI2SN_SHIFT 6
#define RCC_PLLI2SCFGR_PLLI2SN_MASK 0x1ff




#define RCC_PLLSAICFGR_PLLSAIR_SHIFT 28
#define RCC_PLLSAICFGR_PLLSAIR_MASK 0x7


#define RCC_PLLSAICFGR_PLLSAIQ_SHIFT 24
#define RCC_PLLSAICFGR_PLLSAIQ_MASK 0xF


#define RCC_PLLSAICFGR_PLLSAIP_SHIFT 16
#define RCC_PLLSAICFGR_PLLSAIP_MASK 0x3



#define RCC_PLLSAICFGR_PLLSAIP_DIV2 0x0
#define RCC_PLLSAICFGR_PLLSAIP_DIV4 0x1
#define RCC_PLLSAICFGR_PLLSAIP_DIV6 0x2
#define RCC_PLLSAICFGR_PLLSAIP_DIV8 0x3



#define RCC_PLLSAICFGR_PLLSAIN_SHIFT 6
#define RCC_PLLSAICFGR_PLLSAIN_MASK 0x1FF



#define RCC_DCKCFGR_DSISEL (1 << 29)
#define RCC_DCKCFGR_SDMMCSEL (1 << 28)
#define RCC_DCKCFGR_48MSEL (1 << 27)
#define RCC_DCKCFGR_TIMPRE (1 << 24)

#define RCC_DCKCFGR_SAI1BSRC_SHIFT 22
#define RCC_DCKCFGR_SAI1BSRC_MASK 0x3

#define RCC_DCKCFGR_SAI1ASRC_SHIFT 20
#define RCC_DCKCFGR_SAI1ASRC_MASK 0x3


#define RCC_DCKCFGR_SAI1SRC_SAIQ 0x0
#define RCC_DCKCFGR_SAI1SRC_I2SQ 0x1
#define RCC_DCKCFGR_SAI1SRC_ALT 0x2
#define RCC_DCKCFGR_SAI1SRC_ERROR 0x3

#define RCC_DCKCFGR_PLLSAIDIVR_SHIFT 16
#define RCC_DCKCFGR_PLLSAIDIVR_MASK 0x3
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_2 0x0
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_4 0x1
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_8 0x2
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_16 0x3

#define RCC_DCKCFGR_PLLSAIDIVQ_SHIFT 8
#define RCC_DCKCFGR_PLLSAIDIVQ_MASK 0x1f

#define RCC_DCKCFGR_PLLI2SDIVQ_SHIFT 0
#define RCC_DCKCFGR_PLLI2SDIVQ_MASK 0x1f






#define RCC_CKGATENR_EVTCL_CKEN (1<<7)
#define RCC_CKGATENR_RCC_CKEN (1<<6)
#define RCC_CKGATENR_FLITF_CKEN (1<<5)
#define RCC_CKGATENR_SRAM_CKEN (1<<4)
#define RCC_CKGATENR_SPARE_CKEN (1<<3)
#define RCC_CKGATENR_CM4DBG_CKEN (1<<2)
#define RCC_CKGATENR_AHB2APB2_CKEN (1<<1)
#define RCC_CKGATENR_AHB2APB1_CKEN (1<<0)



extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;



enum rcc_clock_3v3 {
 RCC_CLOCK_3V3_84MHZ,
 RCC_CLOCK_3V3_96MHZ,
 RCC_CLOCK_3V3_168MHZ,
 RCC_CLOCK_3V3_180MHZ,
 RCC_CLOCK_3V3_END
};

struct rcc_clock_scale {
 uint8_t pllm;
 uint16_t plln;
 uint8_t pllp;
 uint8_t pllq;
 uint8_t pllr;
 uint8_t pll_source;
 uint32_t flash_config;
 uint8_t hpre;
 uint8_t ppre1;
 uint8_t ppre2;
 enum pwr_vos_scale voltage_scale;
 uint32_t ahb_frequency;
 uint32_t apb1_frequency;
 uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_12mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_16mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_END];

enum rcc_osc {
 RCC_PLL,
 RCC_PLLSAI,
 RCC_PLLI2S,
 RCC_HSE,
 RCC_HSI,
 RCC_LSE,
 RCC_LSI
};

#define _REG_BIT(base,bit) (((base) << 5) + (bit))

enum rcc_periph_clken {

 RCC_GPIOA = (((0x30) << 5) + (0)),
 RCC_GPIOB = (((0x30) << 5) + (1)),
 RCC_GPIOC = (((0x30) << 5) + (2)),
 RCC_GPIOD = (((0x30) << 5) + (3)),
 RCC_GPIOE = (((0x30) << 5) + (4)),
 RCC_GPIOF = (((0x30) << 5) + (5)),
 RCC_GPIOG = (((0x30) << 5) + (6)),
 RCC_GPIOH = (((0x30) << 5) + (7)),
 RCC_GPIOI = (((0x30) << 5) + (8)),
 RCC_GPIOJ = (((0x30) << 5) + (9)),
 RCC_GPIOK = (((0x30) << 5) + (10)),
 RCC_CRC = (((0x30) << 5) + (12)),
 RCC_BKPSRAM = (((0x30) << 5) + (18)),
 RCC_CCMDATARAM = (((0x30) << 5) + (20)),
 RCC_DMA1 = (((0x30) << 5) + (21)),
 RCC_DMA2 = (((0x30) << 5) + (22)),
 RCC_DMA2D = (((0x30) << 5) + (23)),
 RCC_ETHMAC = (((0x30) << 5) + (25)),
 RCC_ETHMACTX = (((0x30) << 5) + (26)),
 RCC_ETHMACRX = (((0x30) << 5) + (27)),
 RCC_ETHMACPTP = (((0x30) << 5) + (28)),
 RCC_OTGHS = (((0x30) << 5) + (29)),
 RCC_OTGHSULPI = (((0x30) << 5) + (30)),


 RCC_DCMI = (((0x34) << 5) + (0)),
 RCC_CRYP = (((0x34) << 5) + (4)),
 RCC_HASH = (((0x34) << 5) + (5)),
 RCC_RNG = (((0x34) << 5) + (6)),
 RCC_OTGFS = (((0x34) << 5) + (7)),


 RCC_FSMC = (((0x38) << 5) + (0)),
 RCC_FMC = (((0x38) << 5) + (0)),
 RCC_QUADSPI = (((0x38) << 5) + (1)),


 RCC_TIM2 = (((0x40) << 5) + (0)),
 RCC_TIM3 = (((0x40) << 5) + (1)),
 RCC_TIM4 = (((0x40) << 5) + (2)),
 RCC_TIM5 = (((0x40) << 5) + (3)),
 RCC_TIM6 = (((0x40) << 5) + (4)),
 RCC_TIM7 = (((0x40) << 5) + (5)),
 RCC_TIM12 = (((0x40) << 5) + (6)),
 RCC_TIM13 = (((0x40) << 5) + (7)),
 RCC_TIM14 = (((0x40) << 5) + (8)),
 RCC_WWDG = (((0x40) << 5) + (11)),
 RCC_SPI2 = (((0x40) << 5) + (14)),
 RCC_SPI3 = (((0x40) << 5) + (15)),
 RCC_USART2 = (((0x40) << 5) + (17)),
 RCC_USART3 = (((0x40) << 5) + (18)),
 RCC_UART4 = (((0x40) << 5) + (19)),
 RCC_UART5 = (((0x40) << 5) + (20)),
 RCC_I2C1 = (((0x40) << 5) + (21)),
 RCC_I2C2 = (((0x40) << 5) + (22)),
 RCC_I2C3 = (((0x40) << 5) + (23)),
 RCC_CAN1 = (((0x40) << 5) + (25)),
 RCC_CAN2 = (((0x40) << 5) + (26)),
 RCC_PWR = (((0x40) << 5) + (28)),
 RCC_DAC = (((0x40) << 5) + (29)),
 RCC_UART7 = (((0x40) << 5) + (30)),
 RCC_UART8 = (((0x40) << 5) + (31)),


 RCC_TIM1 = (((0x44) << 5) + (0)),
 RCC_TIM8 = (((0x44) << 5) + (1)),
 RCC_USART1 = (((0x44) << 5) + (4)),
 RCC_USART6 = (((0x44) << 5) + (5)),
 RCC_ADC1 = (((0x44) << 5) + (8)),
 RCC_ADC2 = (((0x44) << 5) + (9)),
 RCC_ADC3 = (((0x44) << 5) + (10)),
 RCC_SDIO = (((0x44) << 5) + (11)),
 RCC_SPI1 = (((0x44) << 5) + (12)),
 RCC_SPI4 = (((0x44) << 5) + (13)),
 RCC_SYSCFG = (((0x44) << 5) + (14)),
 RCC_TIM9 = (((0x44) << 5) + (16)),
 RCC_TIM10 = (((0x44) << 5) + (17)),
 RCC_TIM11 = (((0x44) << 5) + (18)),
 RCC_SPI5 = (((0x44) << 5) + (20)),
 RCC_SPI6 = (((0x44) << 5) + (21)),
 RCC_SAI1EN = (((0x44) << 5) + (22)),
 RCC_LTDC = (((0x44) << 5) + (26)),
 RCC_DSI = (((0x44) << 5) + (27)),



 RCC_RTC = (((0x70) << 5) + (15)),


 SCC_GPIOA = (((0x50) << 5) + (0)),
 SCC_GPIOB = (((0x50) << 5) + (1)),
 SCC_GPIOC = (((0x50) << 5) + (2)),
 SCC_GPIOD = (((0x50) << 5) + (3)),
 SCC_GPIOE = (((0x50) << 5) + (4)),
 SCC_GPIOF = (((0x50) << 5) + (5)),
 SCC_GPIOG = (((0x50) << 5) + (6)),
 SCC_GPIOH = (((0x50) << 5) + (7)),
 SCC_GPIOI = (((0x50) << 5) + (8)),
 SCC_GPIOJ = (((0x50) << 5) + (9)),
 SCC_GPIOK = (((0x50) << 5) + (10)),
 SCC_CRC = (((0x50) << 5) + (12)),
 SCC_FLTIF = (((0x50) << 5) + (15)),
 SCC_SRAM1 = (((0x50) << 5) + (16)),
 SCC_SRAM2 = (((0x50) << 5) + (17)),
 SCC_BKPSRAM = (((0x50) << 5) + (18)),
 SCC_SRAM3 = (((0x50) << 5) + (19)),
 SCC_DMA1 = (((0x50) << 5) + (21)),
 SCC_DMA2 = (((0x50) << 5) + (22)),
 SCC_DMA2D = (((0x50) << 5) + (23)),
 SCC_ETHMAC = (((0x50) << 5) + (25)),
 SCC_ETHMACTX = (((0x50) << 5) + (26)),
 SCC_ETHMACRX = (((0x50) << 5) + (27)),
 SCC_ETHMACPTP = (((0x50) << 5) + (28)),
 SCC_OTGHS = (((0x50) << 5) + (29)),
 SCC_OTGHSULPI = (((0x50) << 5) + (30)),


 SCC_DCMI = (((0x54) << 5) + (0)),
 SCC_CRYP = (((0x54) << 5) + (4)),
 SCC_HASH = (((0x54) << 5) + (5)),
 SCC_RNG = (((0x54) << 5) + (6)),
 SCC_OTGFS = (((0x54) << 5) + (7)),


 SCC_QSPIC = (((0x58) << 5) + (1)),
 SCC_FMC = (((0x58) << 5) + (0)),
 SCC_FSMC = (((0x58) << 5) + (0)),


 SCC_TIM2 = (((0x60) << 5) + (0)),
 SCC_TIM3 = (((0x60) << 5) + (1)),
 SCC_TIM4 = (((0x60) << 5) + (2)),
 SCC_TIM5 = (((0x60) << 5) + (3)),
 SCC_TIM6 = (((0x60) << 5) + (4)),
 SCC_TIM7 = (((0x60) << 5) + (5)),
 SCC_TIM12 = (((0x60) << 5) + (6)),
 SCC_TIM13 = (((0x60) << 5) + (7)),
 SCC_TIM14 = (((0x60) << 5) + (8)),
 SCC_WWDG = (((0x60) << 5) + (11)),
 SCC_SPI2 = (((0x60) << 5) + (14)),
 SCC_SPI3 = (((0x60) << 5) + (15)),
 SCC_USART2 = (((0x60) << 5) + (17)),
 SCC_USART3 = (((0x60) << 5) + (18)),
 SCC_UART4 = (((0x60) << 5) + (19)),
 SCC_UART5 = (((0x60) << 5) + (20)),
 SCC_I2C1 = (((0x60) << 5) + (21)),
 SCC_I2C2 = (((0x60) << 5) + (22)),
 SCC_I2C3 = (((0x60) << 5) + (23)),
 SCC_CAN1 = (((0x60) << 5) + (25)),
 SCC_CAN2 = (((0x60) << 5) + (26)),
 SCC_PWR = (((0x60) << 5) + (28)),
 SCC_DAC = (((0x60) << 5) + (29)),
 SCC_UART7 = (((0x60) << 5) + (30)),
 SCC_UART8 = (((0x60) << 5) + (31)),


 SCC_TIM1 = (((0x64) << 5) + (0)),
 SCC_TIM8 = (((0x64) << 5) + (1)),
 SCC_USART1 = (((0x64) << 5) + (4)),
 SCC_USART6 = (((0x64) << 5) + (5)),
 SCC_ADC1 = (((0x64) << 5) + (8)),
 SCC_ADC2 = (((0x64) << 5) + (9)),
 SCC_ADC3 = (((0x64) << 5) + (10)),
 SCC_SDIO = (((0x64) << 5) + (11)),
 SCC_SPI1 = (((0x64) << 5) + (12)),
 SCC_SPI4 = (((0x64) << 5) + (13)),
 SCC_SYSCFG = (((0x64) << 5) + (14)),
 SCC_TIM9 = (((0x64) << 5) + (16)),
 SCC_TIM10 = (((0x64) << 5) + (17)),
 SCC_TIM11 = (((0x64) << 5) + (18)),
 SCC_SPI5 = (((0x64) << 5) + (20)),
 SCC_SPI6 = (((0x64) << 5) + (21)),
 SCC_SAI1 = (((0x64) << 5) + (22)),
 SCC_LTDC = (((0x64) << 5) + (26)),
 SCC_DSI = (((0x64) << 5) + (27)),
};

enum rcc_periph_rst {

 RST_GPIOA = (((0x10) << 5) + (0)),
 RST_GPIOB = (((0x10) << 5) + (1)),
 RST_GPIOC = (((0x10) << 5) + (2)),
 RST_GPIOD = (((0x10) << 5) + (3)),
 RST_GPIOE = (((0x10) << 5) + (4)),
 RST_GPIOF = (((0x10) << 5) + (5)),
 RST_GPIOG = (((0x10) << 5) + (6)),
 RST_GPIOH = (((0x10) << 5) + (7)),
 RST_GPIOI = (((0x10) << 5) + (8)),
 RST_GPIOJ = (((0x10) << 5) + (9)),
 RST_GPIOK = (((0x10) << 5) + (10)),
 RST_CRC = (((0x10) << 5) + (12)),
 RST_DMA1 = (((0x10) << 5) + (21)),
 RST_DMA2 = (((0x10) << 5) + (22)),
 RST_DMA2D = (((0x10) << 5) + (23)),
 RST_ETHMAC = (((0x10) << 5) + (25)),
 RST_OTGHS = (((0x10) << 5) + (29)),


 RST_DCMI = (((0x14) << 5) + (0)),
 RST_CRYP = (((0x14) << 5) + (4)),
 RST_HASH = (((0x14) << 5) + (5)),
 RST_RNG = (((0x14) << 5) + (6)),
 RST_OTGFS = (((0x14) << 5) + (7)),


 RST_QSPI = (((0x18) << 5) + (1)),
 RST_FSMC = (((0x18) << 5) + (0)),
 RST_FMC = (((0x18) << 5) + (0)),


 RST_TIM2 = (((0x20) << 5) + (0)),
 RST_TIM3 = (((0x20) << 5) + (1)),
 RST_TIM4 = (((0x20) << 5) + (2)),
 RST_TIM5 = (((0x20) << 5) + (3)),
 RST_TIM6 = (((0x20) << 5) + (4)),
 RST_TIM7 = (((0x20) << 5) + (5)),
 RST_TIM12 = (((0x20) << 5) + (6)),
 RST_TIM13 = (((0x20) << 5) + (7)),
 RST_TIM14 = (((0x20) << 5) + (8)),
 RST_WWDG = (((0x20) << 5) + (11)),
 RST_SPI2 = (((0x20) << 5) + (14)),
 RST_SPI3 = (((0x20) << 5) + (15)),
 RST_USART2 = (((0x20) << 5) + (17)),
 RST_USART3 = (((0x20) << 5) + (18)),
 RST_UART4 = (((0x20) << 5) + (19)),
 RST_UART5 = (((0x20) << 5) + (20)),
 RST_I2C1 = (((0x20) << 5) + (21)),
 RST_I2C2 = (((0x20) << 5) + (22)),
 RST_I2C3 = (((0x20) << 5) + (23)),
 RST_CAN1 = (((0x20) << 5) + (25)),
 RST_CAN2 = (((0x20) << 5) + (26)),
 RST_PWR = (((0x20) << 5) + (28)),
 RST_DAC = (((0x20) << 5) + (29)),
 RST_UART7 = (((0x20) << 5) + (30)),
 RST_UART8 = (((0x20) << 5) + (31)),


 RST_TIM1 = (((0x24) << 5) + (0)),
 RST_TIM8 = (((0x24) << 5) + (1)),
 RST_USART1 = (((0x24) << 5) + (4)),
 RST_USART6 = (((0x24) << 5) + (5)),
 RST_ADC = (((0x24) << 5) + (8)),
 RST_SDIO = (((0x24) << 5) + (11)),
 RST_SPI1 = (((0x24) << 5) + (12)),
 RST_SPI4 = (((0x24) << 5) + (13)),
 RST_SYSCFG = (((0x24) << 5) + (14)),
 RST_TIM9 = (((0x24) << 5) + (16)),
 RST_TIM10 = (((0x24) << 5) + (17)),
 RST_TIM11 = (((0x24) << 5) + (18)),
 RST_SPI5 = (((0x24) << 5) + (20)),
 RST_SPI6 = (((0x24) << 5) + (21)),
 RST_SAI1RST = (((0x24) << 5) + (22)),
 RST_LTDC = (((0x24) << 5) + (26)),
 RST_DSI = (((0x24) << 5) + (27)),


 RST_BDCR = (((0x70) << 5) + (16)),
};

#undef _REG_BIT

#define LIBOPENCM3_RCC_COMMON_ALL_H 





void rcc_peripheral_enable_clock(volatile uint32_t *reg, uint32_t en);
void rcc_peripheral_disable_clock(volatile uint32_t *reg, uint32_t en);
void rcc_peripheral_reset(volatile uint32_t *reg, uint32_t reset);
void rcc_peripheral_clear_reset(volatile uint32_t *reg, uint32_t clear_reset);

void rcc_periph_clock_enable(enum rcc_periph_clken clken);
void rcc_periph_clock_disable(enum rcc_periph_clken clken);
void rcc_periph_reset_pulse(enum rcc_periph_rst rst);
void rcc_periph_reset_hold(enum rcc_periph_rst rst);
void rcc_periph_reset_release(enum rcc_periph_rst rst);

void rcc_set_mco(uint32_t mcosrc);
void rcc_osc_bypass_enable(enum rcc_osc osc);
void rcc_osc_bypass_disable(enum rcc_osc osc);







_Bool 
    rcc_is_osc_ready(enum rcc_osc osc);






void rcc_wait_for_osc_ready(enum rcc_osc osc);






uint16_t rcc_get_div_from_hpre(uint8_t div_val);





void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_wait_for_sysclk_status(enum rcc_osc osc);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_plli2s_config(uint16_t n, uint8_t r);
void rcc_pllsai_config(uint16_t n, uint16_t p, uint16_t q, uint16_t r);
void rcc_pllsai_postscalers(uint8_t q, uint8_t r);
void rcc_set_sysclk_source(uint32_t clk);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_rtcpre(uint32_t rtcpre);
void rcc_set_main_pll_hsi(uint32_t pllm, uint32_t plln, uint32_t pllp,
     uint32_t pllq, uint32_t pllr);
void rcc_set_main_pll_hse(uint32_t pllm, uint32_t plln, uint32_t pllp,
     uint32_t pllq, uint32_t pllr);
uint32_t rcc_system_clock_source(void);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);
void __attribute__((deprecated("Use rcc_clock_setup_pll as direct replacement"))) rcc_clock_setup_hse_3v3(const struct rcc_clock_scale *clock);
uint32_t rcc_get_usart_clk_freq(uint32_t usart);
uint32_t rcc_get_timer_clk_freq(uint32_t timer);
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c);
uint32_t rcc_get_spi_clk_freq(uint32_t spi);


#define LIBOPENCM3_GPIO_H 

#define LIBOPENCM3_GPIO_COMMON_F24_H 



#define LIBOPENCM3_GPIO_COMMON_F234_H 



#define LIBOPENCM3_GPIO_COMMON_ALL_H 







#define GPIO_LCKK (1 << 16)







#define GPIO0 (1 << 0)
#define GPIO1 (1 << 1)
#define GPIO2 (1 << 2)
#define GPIO3 (1 << 3)
#define GPIO4 (1 << 4)
#define GPIO5 (1 << 5)
#define GPIO6 (1 << 6)
#define GPIO7 (1 << 7)
#define GPIO8 (1 << 8)
#define GPIO9 (1 << 9)
#define GPIO10 (1 << 10)
#define GPIO11 (1 << 11)
#define GPIO12 (1 << 12)
#define GPIO13 (1 << 13)
#define GPIO14 (1 << 14)
#define GPIO15 (1 << 15)
#define GPIO_ALL 0xffff




void gpio_set(uint32_t gpioport, uint16_t gpios);
void gpio_clear(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_get(uint32_t gpioport, uint16_t gpios);
void gpio_toggle(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_port_read(uint32_t gpioport);
void gpio_port_write(uint32_t gpioport, uint16_t data);
void gpio_port_config_lock(uint32_t gpioport, uint16_t gpios);








#define GPIOA GPIO_PORT_A_BASE
#define GPIOB GPIO_PORT_B_BASE
#define GPIOC GPIO_PORT_C_BASE
#define GPIOD GPIO_PORT_D_BASE
#define GPIOE GPIO_PORT_E_BASE
#define GPIOF GPIO_PORT_F_BASE
#define GPIOG GPIO_PORT_G_BASE
#define GPIOH GPIO_PORT_H_BASE






#define GPIO_MODER(port) MMIO32((port) + 0x00)
#define GPIOA_MODER GPIO_MODER(GPIOA)
#define GPIOB_MODER GPIO_MODER(GPIOB)
#define GPIOC_MODER GPIO_MODER(GPIOC)
#define GPIOD_MODER GPIO_MODER(GPIOD)
#define GPIOE_MODER GPIO_MODER(GPIOE)
#define GPIOF_MODER GPIO_MODER(GPIOF)
#define GPIOG_MODER GPIO_MODER(GPIOG)
#define GPIOH_MODER GPIO_MODER(GPIOH)


#define GPIO_OTYPER(port) MMIO32((port) + 0x04)
#define GPIOA_OTYPER GPIO_OTYPER(GPIOA)
#define GPIOB_OTYPER GPIO_OTYPER(GPIOB)
#define GPIOC_OTYPER GPIO_OTYPER(GPIOC)
#define GPIOD_OTYPER GPIO_OTYPER(GPIOD)
#define GPIOE_OTYPER GPIO_OTYPER(GPIOE)
#define GPIOF_OTYPER GPIO_OTYPER(GPIOF)
#define GPIOG_OTYPER GPIO_OTYPER(GPIOG)
#define GPIOH_OTYPER GPIO_OTYPER(GPIOH)


#define GPIO_OSPEEDR(port) MMIO32((port) + 0x08)
#define GPIOA_OSPEEDR GPIO_OSPEEDR(GPIOA)
#define GPIOB_OSPEEDR GPIO_OSPEEDR(GPIOB)
#define GPIOC_OSPEEDR GPIO_OSPEEDR(GPIOC)
#define GPIOD_OSPEEDR GPIO_OSPEEDR(GPIOD)
#define GPIOE_OSPEEDR GPIO_OSPEEDR(GPIOE)
#define GPIOF_OSPEEDR GPIO_OSPEEDR(GPIOF)
#define GPIOG_OSPEEDR GPIO_OSPEEDR(GPIOG)
#define GPIOH_OSPEEDR GPIO_OSPEEDR(GPIOH)


#define GPIO_PUPDR(port) MMIO32((port) + 0x0c)
#define GPIOA_PUPDR GPIO_PUPDR(GPIOA)
#define GPIOB_PUPDR GPIO_PUPDR(GPIOB)
#define GPIOC_PUPDR GPIO_PUPDR(GPIOC)
#define GPIOD_PUPDR GPIO_PUPDR(GPIOD)
#define GPIOE_PUPDR GPIO_PUPDR(GPIOE)
#define GPIOF_PUPDR GPIO_PUPDR(GPIOF)
#define GPIOG_PUPDR GPIO_PUPDR(GPIOG)
#define GPIOH_PUPDR GPIO_PUPDR(GPIOH)


#define GPIO_IDR(port) MMIO32((port) + 0x10)
#define GPIOA_IDR GPIO_IDR(GPIOA)
#define GPIOB_IDR GPIO_IDR(GPIOB)
#define GPIOC_IDR GPIO_IDR(GPIOC)
#define GPIOD_IDR GPIO_IDR(GPIOD)
#define GPIOE_IDR GPIO_IDR(GPIOE)
#define GPIOF_IDR GPIO_IDR(GPIOF)
#define GPIOG_IDR GPIO_IDR(GPIOG)
#define GPIOH_IDR GPIO_IDR(GPIOH)


#define GPIO_ODR(port) MMIO32((port) + 0x14)
#define GPIOA_ODR GPIO_ODR(GPIOA)
#define GPIOB_ODR GPIO_ODR(GPIOB)
#define GPIOC_ODR GPIO_ODR(GPIOC)
#define GPIOD_ODR GPIO_ODR(GPIOD)
#define GPIOE_ODR GPIO_ODR(GPIOE)
#define GPIOF_ODR GPIO_ODR(GPIOF)
#define GPIOG_ODR GPIO_ODR(GPIOG)
#define GPIOH_ODR GPIO_ODR(GPIOH)


#define GPIO_BSRR(port) MMIO32((port) + 0x18)
#define GPIOA_BSRR GPIO_BSRR(GPIOA)
#define GPIOB_BSRR GPIO_BSRR(GPIOB)
#define GPIOC_BSRR GPIO_BSRR(GPIOC)
#define GPIOD_BSRR GPIO_BSRR(GPIOD)
#define GPIOE_BSRR GPIO_BSRR(GPIOE)
#define GPIOF_BSRR GPIO_BSRR(GPIOF)
#define GPIOG_BSRR GPIO_BSRR(GPIOG)
#define GPIOH_BSRR GPIO_BSRR(GPIOH)


#define GPIO_LCKR(port) MMIO32((port) + 0x1c)
#define GPIOA_LCKR GPIO_LCKR(GPIOA)
#define GPIOB_LCKR GPIO_LCKR(GPIOB)
#define GPIOC_LCKR GPIO_LCKR(GPIOC)
#define GPIOD_LCKR GPIO_LCKR(GPIOD)
#define GPIOE_LCKR GPIO_LCKR(GPIOE)
#define GPIOF_LCKR GPIO_LCKR(GPIOF)
#define GPIOG_LCKR GPIO_LCKR(GPIOG)
#define GPIOH_LCKR GPIO_LCKR(GPIOH)


#define GPIO_AFRL(port) MMIO32((port) + 0x20)
#define GPIOA_AFRL GPIO_AFRL(GPIOA)
#define GPIOB_AFRL GPIO_AFRL(GPIOB)
#define GPIOC_AFRL GPIO_AFRL(GPIOC)
#define GPIOD_AFRL GPIO_AFRL(GPIOD)
#define GPIOE_AFRL GPIO_AFRL(GPIOE)
#define GPIOF_AFRL GPIO_AFRL(GPIOF)
#define GPIOG_AFRL GPIO_AFRL(GPIOG)
#define GPIOH_AFRL GPIO_AFRL(GPIOH)


#define GPIO_AFRH(port) MMIO32((port) + 0x24)
#define GPIOA_AFRH GPIO_AFRH(GPIOA)
#define GPIOB_AFRH GPIO_AFRH(GPIOB)
#define GPIOC_AFRH GPIO_AFRH(GPIOC)
#define GPIOD_AFRH GPIO_AFRH(GPIOD)
#define GPIOE_AFRH GPIO_AFRH(GPIOE)
#define GPIOF_AFRH GPIO_AFRH(GPIOF)
#define GPIOG_AFRH GPIO_AFRH(GPIOG)
#define GPIOH_AFRH GPIO_AFRH(GPIOH)



#define GPIO_MODE(n,mode) ((mode) << (2 * (n)))
#define GPIO_MODE_MASK(n) (0x3 << (2 * (n)))



#define GPIO_MODE_INPUT 0x0
#define GPIO_MODE_OUTPUT 0x1
#define GPIO_MODE_AF 0x2
#define GPIO_MODE_ANALOG 0x3
#define GPIO_OTYPE_PP 0x0

#define GPIO_OTYPE_OD 0x1




#define GPIO_OSPEED(n,speed) ((speed) << (2 * (n)))
#define GPIO_OSPEED_MASK(n) (0x3 << (2 * (n)))



#define GPIO_OSPEED_2MHZ 0x0
#define GPIO_OSPEED_25MHZ 0x1
#define GPIO_OSPEED_50MHZ 0x2
#define GPIO_OSPEED_100MHZ 0x3




#define GPIO_PUPD(n,pupd) ((pupd) << (2 * (n)))
#define GPIO_PUPD_MASK(n) (0x3 << (2 * (n)))



#define GPIO_PUPD_NONE 0x0
#define GPIO_PUPD_PULLUP 0x1
#define GPIO_PUPD_PULLDOWN 0x2
#define GPIO_LCKK (1 << 16)







#define GPIO_AFR(n,af) ((af) << ((n) * 4))
#define GPIO_AFR_MASK(n) (0xf << ((n) * 4))



#define GPIO_AF0 0x0
#define GPIO_AF1 0x1
#define GPIO_AF2 0x2
#define GPIO_AF3 0x3
#define GPIO_AF4 0x4
#define GPIO_AF5 0x5
#define GPIO_AF6 0x6
#define GPIO_AF7 0x7
#define GPIO_AF8 0x8
#define GPIO_AF9 0x9
#define GPIO_AF10 0xa
#define GPIO_AF11 0xb
#define GPIO_AF12 0xc
#define GPIO_AF13 0xd
#define GPIO_AF14 0xe
#define GPIO_AF15 0xf







void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
       uint16_t gpios);
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
        uint16_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios);








#define GPIOI GPIO_PORT_I_BASE
#define GPIOJ GPIO_PORT_J_BASE
#define GPIOK GPIO_PORT_K_BASE





#define GPIOI_MODER GPIO_MODER(GPIOI)
#define GPIOJ_MODER GPIO_MODER(GPIOJ)
#define GPIOK_MODER GPIO_MODER(GPIOK)


#define GPIOI_OTYPER GPIO_OTYPER(GPIOI)
#define GPIOJ_OTYPER GPIO_OTYPER(GPIOJ)
#define GPIOK_OTYPER GPIO_OTYPER(GPIOK)


#define GPIOI_OSPEEDR GPIO_OSPEEDR(GPIOI)
#define GPIOJ_OSPEEDR GPIO_OSPEEDR(GPIOJ)
#define GPIOK_OSPEEDR GPIO_OSPEEDR(GPIOK)


#define GPIOI_PUPDR GPIO_PUPDR(GPIOI)
#define GPIOJ_PUPDR GPIO_PUPDR(GPIOJ)
#define GPIOK_PUPDR GPIO_PUPDR(GPIOK)


#define GPIOI_IDR GPIO_IDR(GPIOI)
#define GPIOJ_IDR GPIO_IDR(GPIOJ)
#define GPIOK_IDR GPIO_IDR(GPIOK)


#define GPIOI_ODR GPIO_ODR(GPIOI)
#define GPIOJ_ODR GPIO_ODR(GPIOJ)
#define GPIOK_ODR GPIO_ODR(GPIOK)


#define GPIOI_BSRR GPIO_BSRR(GPIOI)
#define GPIOJ_BSRR GPIO_BSRR(GPIOJ)
#define GPIOK_BSRR GPIO_BSRR(GPIOK)


#define GPIOI_LCKR GPIO_LCKR(GPIOI)
#define GPIOJ_LCKR GPIO_LCKR(GPIOJ)
#define GPIOK_LCKR GPIO_LCKR(GPIOK)


#define GPIOI_AFRL GPIO_AFRL(GPIOI)
#define GPIOJ_AFRL GPIO_AFRL(GPIOJ)
#define GPIOK_AFRL GPIO_AFRL(GPIOK)


#define GPIOI_AFRH GPIO_AFRH(GPIOI)
#define GPIOJ_AFRH GPIO_AFRH(GPIOJ)
#define GPIOK_AFRH GPIO_AFRH(GPIOK)
static const struct usb_device_descriptor dev = {
 .bLength = sizeof(struct usb_device_descriptor),
 .bDescriptorType = 1,
 .bcdUSB = 0x0200,
 .bDeviceClass = 0,
 .bDeviceSubClass = 0,
 .bDeviceProtocol = 0,
 .bMaxPacketSize0 = 64,
 .idVendor = 0x6666,
 .idProduct = 0x5119,
 .bcdDevice = 0x0100,
 .iManufacturer = 1,
 .iProduct = 2,
 .iSerialNumber = 3,
 .bNumConfigurations = 1,
};




static const struct usb_midi_endpoint_descriptor midi_bulk_endp[] = {{



 .head = {
  .bLength = sizeof(struct usb_midi_endpoint_descriptor),
  .bDescriptorType = 0x25,
  .bDescriptorSubType = 0x01,
  .bNumEmbMIDIJack = 1,
 },
 .jack[0] = {
  .baAssocJackID = 0x01,
 },
}, {



 .head = {
  .bLength = sizeof(struct usb_midi_endpoint_descriptor),
  .bDescriptorType = 0x25,
  .bDescriptorSubType = 0x01,
  .bNumEmbMIDIJack = 1,
 },
 .jack[0] = {
  .baAssocJackID = 0x03,
 },
} };




static const struct usb_endpoint_descriptor bulk_endp[] = {{

 .bLength = 7,
 .bDescriptorType = 5,
 .bEndpointAddress = 0x01,
 .bmAttributes = 0x02,
 .wMaxPacketSize = 0x40,
 .bInterval = 0x00,

 .extra = &midi_bulk_endp[0],
 .extralen = sizeof(midi_bulk_endp[0])
}, {
 .bLength = 7,
 .bDescriptorType = 5,
 .bEndpointAddress = 0x81,
 .bmAttributes = 0x02,
 .wMaxPacketSize = 0x40,
 .bInterval = 0x00,

 .extra = &midi_bulk_endp[1],
 .extralen = sizeof(midi_bulk_endp[1])
} };




static const struct {
 struct usb_audio_header_descriptor_head header_head;
 struct usb_audio_header_descriptor_body header_body;
} __attribute__((packed)) audio_control_functional_descriptors = {
 .header_head = {
  .bLength = sizeof(struct usb_audio_header_descriptor_head) +
      1 * sizeof(struct usb_audio_header_descriptor_body),
  .bDescriptorType = 0x24,
  .bDescriptorSubtype = 0x01,
  .bcdADC = 0x0100,
  .wTotalLength =
      sizeof(struct usb_audio_header_descriptor_head) +
      1 * sizeof(struct usb_audio_header_descriptor_body),
  .binCollection = 1,
 },
 .header_body = {
  .baInterfaceNr = 0x01,
 },
};




static const struct usb_interface_descriptor audio_control_iface[] = {{
 .bLength = 9,
 .bDescriptorType = 4,
 .bInterfaceNumber = 0,
 .bAlternateSetting = 0,
 .bNumEndpoints = 0,
 .bInterfaceClass = 0x01,
 .bInterfaceSubClass = 0x01,
 .bInterfaceProtocol = 0,
 .iInterface = 0,

 .extra = &audio_control_functional_descriptors,
 .extralen = sizeof(audio_control_functional_descriptors)
} };




static const struct {
 struct usb_midi_header_descriptor header;
 struct usb_midi_in_jack_descriptor in_embedded;
 struct usb_midi_in_jack_descriptor in_external;
 struct usb_midi_out_jack_descriptor out_embedded;
 struct usb_midi_out_jack_descriptor out_external;
} __attribute__((packed)) midi_streaming_functional_descriptors = {

 .header = {
  .bLength = sizeof(struct usb_midi_header_descriptor),
  .bDescriptorType = 0x24,
  .bDescriptorSubtype = 0x01,
  .bcdMSC = 0x0100,
  .wTotalLength = sizeof(midi_streaming_functional_descriptors),
 },

 .in_embedded = {
  .bLength = sizeof(struct usb_midi_in_jack_descriptor),
  .bDescriptorType = 0x24,
  .bDescriptorSubtype = 0x02,
  .bJackType = 0x01,
  .bJackID = 0x01,
  .iJack = 0x00,
 },

 .in_external = {
  .bLength = sizeof(struct usb_midi_in_jack_descriptor),
  .bDescriptorType = 0x24,
  .bDescriptorSubtype = 0x02,
  .bJackType = 0x02,
  .bJackID = 0x02,
  .iJack = 0x00,
 },

 .out_embedded = {
  .head = {
   .bLength = sizeof(struct usb_midi_out_jack_descriptor),
   .bDescriptorType = 0x24,
   .bDescriptorSubtype = 0x03,
   .bJackType = 0x01,
   .bJackID = 0x03,
   .bNrInputPins = 1,
  },
  .source[0] = {
   .baSourceID = 0x02,
   .baSourcePin = 0x01,
  },
  .tail = {
   .iJack = 0x00,
  }
 },

 .out_external = {
  .head = {
   .bLength = sizeof(struct usb_midi_out_jack_descriptor),
   .bDescriptorType = 0x24,
   .bDescriptorSubtype = 0x03,
   .bJackType = 0x02,
   .bJackID = 0x04,
   .bNrInputPins = 1,
  },
  .source[0] = {
   .baSourceID = 0x01,
   .baSourcePin = 0x01,
  },
  .tail = {
   .iJack = 0x00,
  },
 },
};




static const struct usb_interface_descriptor midi_streaming_iface[] = {{
 .bLength = 9,
 .bDescriptorType = 4,
 .bInterfaceNumber = 1,
 .bAlternateSetting = 0,
 .bNumEndpoints = 2,
 .bInterfaceClass = 0x01,
 .bInterfaceSubClass = 0x03,
 .bInterfaceProtocol = 0,
 .iInterface = 0,

 .endpoint = bulk_endp,

 .extra = &midi_streaming_functional_descriptors,
 .extralen = sizeof(midi_streaming_functional_descriptors)
} };

static const struct usb_interface ifaces[] = {{
 .num_altsetting = 1,
 .altsetting = audio_control_iface,
}, {
 .num_altsetting = 1,
 .altsetting = midi_streaming_iface,
} };




static const struct usb_config_descriptor config = {
 .bLength = 9,
 .bDescriptorType = 2,
 .wTotalLength = 0,

 .bNumInterfaces = 2,
 .bConfigurationValue = 1,
 .iConfiguration = 0,
 .bmAttributes = 0x80,
 .bMaxPower = 0x32,

 .interface = ifaces,
};

static char usb_serial_number[25];

static const char *usb_strings[] = {
 "libopencm3.org",
 "MIDI demo",
 usb_serial_number
};


uint8_t usbd_control_buffer[128];


const uint8_t sysex_identity[] = {
 0x04,
 0xf0,
 0x7e,
 0x00,
 0x04,
 0x7d,
 0x66,
 0x66,
 0x04,
 0x51,
 0x19,
 0x00,
 0x04,
 0x00,
 0x01,
 0x00,
 0x05,
 0xf7,
 0x00,
 0x00,
};

static void usbmidi_data_rx_cb(usbd_device *usbd_dev, uint8_t ep)
{
 (void)ep;

 char buf[64];
 int len = usbd_ep_read_packet(usbd_dev, 0x01, buf, 64);





 if (len) {
  while (usbd_ep_write_packet(usbd_dev, 0x81, sysex_identity,
         sizeof(sysex_identity)) == 0);
 }

 gpio_toggle((((0x40000000U) + 0x20000) + 0x0800), (1 << 5));
}

static void usbmidi_set_config(usbd_device *usbd_dev, uint16_t wValue)
{
 (void)wValue;

 usbd_ep_setup(usbd_dev, 0x01, 0x02, 64,
   usbmidi_data_rx_cb);
 usbd_ep_setup(usbd_dev, 0x81, 0x02, 64, 
                                                          ((void *)0)
                                                              );
}

static void button_send_event(usbd_device *usbd_dev, int pressed)
{
 char buf[4] = { 0x08,
   0x80,
   60,
   64,
 };

 buf[0] |= pressed;
 buf[1] |= pressed << 4;

 while (usbd_ep_write_packet(usbd_dev, 0x81, buf, sizeof(buf)) == 0);
}

static void button_poll(usbd_device *usbd_dev)
{
 static uint32_t button_state = 0;






 uint32_t old_button_state = button_state;
 button_state = (button_state << 1) | ((*(volatile uint32_t *)(((((0x40000000U) + 0x20000) + 0x0000)) + 0x10)) & 1);
 if ((0 == button_state) != (0 == old_button_state)) {
  button_send_event(usbd_dev, !!button_state);
 }
}

int main(void)
{
 usbd_device *usbd_dev;

 rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);

 rcc_periph_clock_enable(RCC_GPIOA);
 rcc_periph_clock_enable(RCC_GPIOB);
 rcc_periph_clock_enable(RCC_OTGHS);


 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0400), 0x2, 0x0, (1 << 14) | (1 << 15));
 gpio_set_af((((0x40000000U) + 0x20000) + 0x0400), 0xc, (1 << 14) | (1 << 15));

 desig_get_unique_id_as_string(usb_serial_number, sizeof(usb_serial_number));


 gpio_mode_setup((((0x40000000U) + 0x20000) + 0x0000), 0x0, 0x0, (1 << 0));

 usbd_dev = usbd_init(&stm32f207_usb_driver, &dev, &config,
   usb_strings, 3,
   usbd_control_buffer, sizeof(usbd_control_buffer));

 usbd_register_set_config_callback(usbd_dev, usbmidi_set_config);

 while (1) {
  usbd_poll(usbd_dev);
  button_poll(usbd_dev);
 }
}
