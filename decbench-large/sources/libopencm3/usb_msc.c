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


#define __MSC_H 

typedef struct _usbd_mass_storage usbd_mass_storage;
#define USB_CLASS_MSC 0x08


#define USB_MSC_SUBCLASS_RBC 0x01
#define USB_MSC_SUBCLASS_ATAPI 0x02
#define USB_MSC_SUBCLASS_UFI 0x04
#define USB_MSC_SUBCLASS_SCSI 0x06
#define USB_MSC_SUBCLASS_LOCKABLE 0x07
#define USB_MSC_SUBCLASS_IEEE1667 0x08


#define USB_MSC_PROTOCOL_CBI 0x00
#define USB_MSC_PROTOCOL_CBI_ALT 0x01
#define USB_MSC_PROTOCOL_BBB 0x50


#define USB_MSC_REQ_CODES_ADSC 0x00
#define USB_MSC_REQ_CODES_GET 0xFC
#define USB_MSC_REQ_CODES_PUT 0xFD
#define USB_MSC_REQ_CODES_GML 0xFE
#define USB_MSC_REQ_CODES_BOMSR 0xFF


#define USB_MSC_REQ_BULK_ONLY_RESET 0xFF
#define USB_MSC_REQ_GET_MAX_LUN 0xFE

usbd_mass_storage *usb_msc_init(usbd_device *usbd_dev,
     uint8_t ep_in, uint8_t ep_in_size,
     uint8_t ep_out, uint8_t ep_out_size,
     const char *vendor_id,
     const char *product_id,
     const char *product_revision_level,
     const uint32_t block_count,
     int (*read_block)(uint32_t lba, uint8_t *copy_to),
     int (*write_block)(uint32_t lba, const uint8_t *copy_from));
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
#define CBW_SIGNATURE 0x43425355
#define CBW_STATUS_SUCCESS 0
#define CBW_STATUS_FAILED 1
#define CBW_STATUS_PHASE_ERROR 2


#define CSW_SIGNATURE 0x53425355
#define CSW_STATUS_SUCCESS 0
#define CSW_STATUS_FAILED 1
#define CSW_STATUS_PHASE_ERROR 2


#define SCSI_TEST_UNIT_READY 0x00
#define SCSI_REQUEST_SENSE 0x03
#define SCSI_FORMAT_UNIT 0x04
#define SCSI_READ_6 0x08
#define SCSI_WRITE_6 0x0A
#define SCSI_INQUIRY 0x12
#define SCSI_MODE_SENSE_6 0x1A
#define SCSI_SEND_DIAGNOSTIC 0x1D
#define SCSI_READ_CAPACITY 0x25
#define SCSI_READ_10 0x28





#define SCSI_REPORT_LUNS 0xA0
#define SCSI_PREVENT_ALLOW_MEDIUM_REMOVAL 0x1E
#define SCSI_MODE_SELECT_6 0x15
#define SCSI_MODE_SELECT_10 0x55
#define SCSI_MODE_SENSE_10 0x5A
#define SCSI_READ_12 0xA8
#define SCSI_READ_FORMAT_CAPACITIES 0x23
#define SCSI_READ_TOC_PMA_ATIP 0x43
#define SCSI_START_STOP_UNIT 0x1B
#define SCSI_SYNCHRONIZE_CACHE 0x35
#define SCSI_VERIFY 0x2F
#define SCSI_WRITE_10 0x2A
#define SCSI_WRITE_12 0xAA


enum sbc_sense_key {
 SBC_SENSE_KEY_NO_SENSE = 0x00,
 SBC_SENSE_KEY_RECOVERED_ERROR = 0x01,
 SBC_SENSE_KEY_NOT_READY = 0x02,
 SBC_SENSE_KEY_MEDIUM_ERROR = 0x03,
 SBC_SENSE_KEY_HARDWARE_ERROR = 0x04,
 SBC_SENSE_KEY_ILLEGAL_REQUEST = 0x05,
 SBC_SENSE_KEY_UNIT_ATTENTION = 0x06,
 SBC_SENSE_KEY_DATA_PROTECT = 0x07,
 SBC_SENSE_KEY_BLANK_CHECK = 0x08,
 SBC_SENSE_KEY_VENDOR_SPECIFIC = 0x09,
 SBC_SENSE_KEY_COPY_ABORTED = 0x0A,
 SBC_SENSE_KEY_ABORTED_COMMAND = 0x0B,
 SBC_SENSE_KEY_VOLUME_OVERFLOW = 0x0D,
 SBC_SENSE_KEY_MISCOMPARE = 0x0E
};

enum sbc_asc {
 SBC_ASC_NO_ADDITIONAL_SENSE_INFORMATION = 0x00,
 SBC_ASC_PERIPHERAL_DEVICE_WRITE_FAULT = 0x03,
 SBC_ASC_LOGICAL_UNIT_NOT_READY = 0x04,
 SBC_ASC_UNRECOVERED_READ_ERROR = 0x11,
 SBC_ASC_INVALID_COMMAND_OPERATION_CODE = 0x20,
 SBC_ASC_LBA_OUT_OF_RANGE = 0x21,
 SBC_ASC_INVALID_FIELD_IN_CDB = 0x24,
 SBC_ASC_WRITE_PROTECTED = 0x27,
 SBC_ASC_NOT_READY_TO_READY_CHANGE = 0x28,
 SBC_ASC_FORMAT_ERROR = 0x31,
 SBC_ASC_MEDIUM_NOT_PRESENT = 0x3A
};

enum sbc_ascq {
 SBC_ASCQ_NA = 0x00,
 SBC_ASCQ_FORMAT_COMMAND_FAILED = 0x01,
 SBC_ASCQ_INITIALIZING_COMMAND_REQUIRED = 0x02,
 SBC_ASCQ_OPERATION_IN_PROGRESS = 0x07
};

enum trans_event {
 EVENT_CBW_VALID,
 EVENT_NEED_STATUS
};

struct usb_msc_cbw {
 uint32_t dCBWSignature;
 uint32_t dCBWTag;
 uint32_t dCBWDataTransferLength;
 uint8_t bmCBWFlags;
 uint8_t bCBWLUN;
 uint8_t bCBWCBLength;
 uint8_t CBWCB[16];
} __attribute__((packed));

struct usb_msc_csw {
 uint32_t dCSWSignature;
 uint32_t dCSWTag;
 uint32_t dCSWDataResidue;
 uint8_t bCSWStatus;
} __attribute__((packed));

struct sbc_sense_info {
 uint8_t key;
 uint8_t asc;
 uint8_t ascq;
};

struct usb_msc_trans {
 uint8_t cbw_cnt;
 union {
  struct usb_msc_cbw cbw;
  uint8_t buf[1];
 } cbw;

 uint32_t bytes_to_read;
 uint32_t bytes_to_write;
 uint32_t byte_count;


 uint32_t lba_start;
 uint32_t block_count;
 uint32_t current_block;

 uint8_t msd_buf[512];

 
_Bool 
     csw_valid;
 uint8_t csw_sent;
 union {
  struct usb_msc_csw csw;
  uint8_t buf[1];
 } csw;
};

struct _usbd_mass_storage {
 usbd_device *usbd_dev;
 uint8_t ep_in;
 uint8_t ep_in_size;
 uint8_t ep_out;
 uint8_t ep_out_size;

 const char *vendor_id;
 const char *product_id;
 const char *product_revision_level;
 uint32_t block_count;

 int (*read_block)(uint32_t lba, uint8_t *copy_to);
 int (*write_block)(uint32_t lba, const uint8_t *copy_from);

 void (*lock)(void);
 void (*unlock)(void);

 struct usb_msc_trans trans;
 struct sbc_sense_info sense;
};

static usbd_mass_storage _mass_storage;



static const uint8_t _spc3_inquiry_response[36] = {
 0x00,
 0x80,
 0x04,
 0x02,
 0x20,
 0x00,
 0x00,
 0x00,

 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,

 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,

 0x20, 0x20, 0x20, 0x20
};

static const uint8_t _spc3_request_sense[18] = {
 0x70,
 0x00,
 0x00,

 0, 0, 0, 0,
 0x0a,

 0, 0, 0, 0,
 0x00,
 0x00,
 0x00,
 0x00,
 0x00,
 0x00
};



static void set_sbc_status(usbd_mass_storage *ms,
      enum sbc_sense_key key,
      enum sbc_asc asc,
      enum sbc_ascq ascq)
{
 ms->sense.key = (uint8_t) key;
 ms->sense.asc = (uint8_t) asc;
 ms->sense.ascq = (uint8_t) ascq;
}

static void set_sbc_status_good(usbd_mass_storage *ms)
{
 set_sbc_status(ms,
         SBC_SENSE_KEY_NO_SENSE,
         SBC_ASC_NO_ADDITIONAL_SENSE_INFORMATION,
         SBC_ASCQ_NA);
}

static uint8_t *get_cbw_buf(struct usb_msc_trans *trans)
{
 return &trans->cbw.cbw.CBWCB[0];
}

static void scsi_read_6(usbd_mass_storage *ms,
   struct usb_msc_trans *trans,
   enum trans_event event)
{
 if (EVENT_CBW_VALID == event) {
  uint8_t *buf;

  buf = get_cbw_buf(trans);

  trans->lba_start = (buf[2] << 8) | buf[3];
  trans->block_count = buf[4];
  trans->current_block = 0;




  trans->bytes_to_write = trans->block_count << 9;

  set_sbc_status_good(ms);
 }
}

static void scsi_write_6(usbd_mass_storage *ms,
    struct usb_msc_trans *trans,
    enum trans_event event)
{
 (void) ms;

 if (EVENT_CBW_VALID == event) {
  uint8_t *buf;

  buf = get_cbw_buf(trans);

  trans->lba_start = ((0x1f & buf[1]) << 16)
        | (buf[2] << 8) | buf[3];
  trans->block_count = buf[4];
  trans->current_block = 0;

  trans->bytes_to_read = trans->block_count << 9;
 }
}

static void scsi_write_10(usbd_mass_storage *ms,
     struct usb_msc_trans *trans,
     enum trans_event event)
{
 (void) ms;

 if (EVENT_CBW_VALID == event) {
  uint8_t *buf;

  buf = get_cbw_buf(trans);

  trans->lba_start = (buf[2] << 24) | (buf[3] << 16) |
     (buf[4] << 8) | buf[5];
  trans->block_count = (buf[7] << 8) | buf[8];
  trans->current_block = 0;

  trans->bytes_to_read = trans->block_count << 9;
 }
}

static void scsi_read_10(usbd_mass_storage *ms,
    struct usb_msc_trans *trans,
    enum trans_event event)
{
 if (EVENT_CBW_VALID == event) {
  uint8_t *buf;

  buf = get_cbw_buf(trans);

  trans->lba_start = (buf[2] << 24) | (buf[3] << 16)
       | (buf[4] << 8) | buf[5];
  trans->block_count = (buf[7] << 8) | buf[8];




  trans->bytes_to_write = trans->block_count << 9;

  set_sbc_status_good(ms);
 }
}

static void scsi_read_capacity(usbd_mass_storage *ms,
          struct usb_msc_trans *trans,
          enum trans_event event)
{
 if (EVENT_CBW_VALID == event) {
  trans->msd_buf[0] = ms->block_count >> 24;
  trans->msd_buf[1] = 0xff & (ms->block_count >> 16);
  trans->msd_buf[2] = 0xff & (ms->block_count >> 8);
  trans->msd_buf[3] = 0xff & ms->block_count;


  trans->msd_buf[4] = 0;
  trans->msd_buf[5] = 0;
  trans->msd_buf[6] = 2;
  trans->msd_buf[7] = 0;
  trans->bytes_to_write = 8;
  set_sbc_status_good(ms);
 }
}

static void scsi_format_unit(usbd_mass_storage *ms,
        struct usb_msc_trans *trans,
        enum trans_event event)
{
 if (EVENT_CBW_VALID == event) {
  uint32_t i;

  memset(trans->msd_buf, 0, 512);

  for (i = 0; i < ms->block_count; i++) {
   (*ms->write_block)(i, trans->msd_buf);
  }

  set_sbc_status_good(ms);
 }
}

static void scsi_request_sense(usbd_mass_storage *ms,
          struct usb_msc_trans *trans,
          enum trans_event event)
{
 if (EVENT_CBW_VALID == event) {
  uint8_t *buf;

  buf = &trans->cbw.cbw.CBWCB[0];

  trans->bytes_to_write = buf[4];
  memcpy(trans->msd_buf, _spc3_request_sense,
         sizeof(_spc3_request_sense));

  trans->msd_buf[2] = ms->sense.key;
  trans->msd_buf[12] = ms->sense.asc;
  trans->msd_buf[13] = ms->sense.ascq;
 }
}

static void scsi_mode_sense_6(usbd_mass_storage *ms,
         struct usb_msc_trans *trans,
         enum trans_event event)
{
 (void) ms;

 if (EVENT_CBW_VALID == event) {
   trans->bytes_to_write = 4;

   trans->msd_buf[0] = 3;
   trans->msd_buf[1] = 0;
   trans->msd_buf[2] = 0;
   trans->csw.csw.dCSWDataResidue = 4;
 }
}

static void scsi_inquiry(usbd_mass_storage *ms,
    struct usb_msc_trans *trans,
    enum trans_event event)
{
 if (EVENT_CBW_VALID == event) {
  uint8_t evpd;
  uint8_t *buf;

  buf = get_cbw_buf(trans);
  evpd = 1 & buf[1];

  if (0 == evpd) {
   size_t len;
   trans->bytes_to_write = sizeof(_spc3_inquiry_response);
   memcpy(trans->msd_buf, _spc3_inquiry_response,
          sizeof(_spc3_inquiry_response));

   len = strlen(ms->vendor_id);
   len = ((len) < (8) ? (len) : (8));
   memcpy(&trans->msd_buf[8], ms->vendor_id, len);

   len = strlen(ms->product_id);
   len = ((len) < (16) ? (len) : (16));
   memcpy(&trans->msd_buf[16], ms->product_id, len);

   len = strlen(ms->product_revision_level);
   len = ((len) < (4) ? (len) : (4));
   memcpy(&trans->msd_buf[32], ms->product_revision_level,
          len);

   trans->csw.csw.dCSWDataResidue =
    sizeof(_spc3_inquiry_response);

   set_sbc_status_good(ms);
  } else {


  }
 }
}

static void scsi_command(usbd_mass_storage *ms,
    struct usb_msc_trans *trans,
    enum trans_event event)
{
 if (EVENT_CBW_VALID == event) {

  trans->csw_sent = 0;
  trans->csw.csw.dCSWSignature = 0x53425355;
  trans->csw.csw.dCSWTag = trans->cbw.cbw.dCBWTag;
  trans->csw.csw.dCSWDataResidue = 0;
  trans->csw.csw.bCSWStatus = 0;

  trans->bytes_to_write = 0;
  trans->bytes_to_read = 0;
  trans->byte_count = 0;
 }

 switch (trans->cbw.cbw.CBWCB[0]) {
 case 0x00:
 case 0x1D:

  set_sbc_status_good(ms);
  break;
 case 0x04:
  scsi_format_unit(ms, trans, event);
  break;
 case 0x03:
  scsi_request_sense(ms, trans, event);
  break;
 case 0x1A:
  scsi_mode_sense_6(ms, trans, event);
  break;
 case 0x08:
  scsi_read_6(ms, trans, event);
  break;
 case 0x12:
  scsi_inquiry(ms, trans, event);
  break;
 case 0x25:
  scsi_read_capacity(ms, trans, event);
  break;
 case 0x28:
  scsi_read_10(ms, trans, event);
  break;
 case 0x0A:
  scsi_write_6(ms, trans, event);
  break;
 case 0x2A:
  scsi_write_10(ms, trans, event);
  break;
 default:
  set_sbc_status(ms, SBC_SENSE_KEY_ILLEGAL_REQUEST,
     SBC_ASC_INVALID_COMMAND_OPERATION_CODE,
     SBC_ASCQ_NA);

  trans->bytes_to_write = 0;
  trans->bytes_to_read = 0;
  trans->csw.csw.bCSWStatus = 1;
  break;
 }
}




static void msc_data_rx_cb(usbd_device *usbd_dev, uint8_t ep)
{
 usbd_mass_storage *ms;
 struct usb_msc_trans *trans;
 int len, max_len, left;
 void *p;

 ms = &_mass_storage;
 trans = &ms->trans;


 left = sizeof(struct usb_msc_cbw) - trans->cbw_cnt;
 if (0 < left) {
  max_len = ((ms->ep_out_size) < (left) ? (ms->ep_out_size) : (left));
  p = &trans->cbw.buf[0x1ff & trans->cbw_cnt];
  len = usbd_ep_read_packet(usbd_dev, ep, p, max_len);
  trans->cbw_cnt += len;

  if (sizeof(struct usb_msc_cbw) == trans->cbw_cnt) {
   scsi_command(ms, trans, EVENT_CBW_VALID);
   if (trans->byte_count < trans->bytes_to_read) {


    return;
   }
  }
 }

 if (trans->byte_count < trans->bytes_to_read) {
  if (0 < trans->block_count) {
   if ((0 == trans->byte_count) && (
                                   ((void *)0) 
                                        != ms->lock)) {
    (*ms->lock)();
   }
  }

  left = trans->bytes_to_read - trans->byte_count;
  max_len = ((ms->ep_out_size) < (left) ? (ms->ep_out_size) : (left));
  p = &trans->msd_buf[0x1ff & trans->byte_count];
  len = usbd_ep_read_packet(usbd_dev, ep, p, max_len);
  trans->byte_count += len;

  if (0 < trans->block_count) {
   if (0 == (0x1ff & trans->byte_count)) {
    uint32_t lba;

    lba = trans->lba_start + trans->current_block;
    if (0 != (*ms->write_block)(lba,
           trans->msd_buf)) {

    }
    trans->current_block++;
   }
  }


  if (
     0 
           == trans->csw_valid) {
   scsi_command(ms, trans, EVENT_NEED_STATUS);
   trans->csw_valid = 
                     1
                         ;
  }
  left = sizeof(struct usb_msc_csw) - trans->csw_sent;
  if (0 < left) {
   max_len = ((ms->ep_out_size) < (left) ? (ms->ep_out_size) : (left));
   p = &trans->csw.buf[trans->csw_sent];
   len = usbd_ep_write_packet(usbd_dev, ms->ep_in, p,
         max_len);
   trans->csw_sent += len;
  }

 } else if (trans->byte_count < trans->bytes_to_write) {
  if (0 < trans->block_count) {
   if ((0 == trans->byte_count) && (
                                   ((void *)0) 
                                        != ms->lock)) {
    (*ms->lock)();
   }

   if (0 == (0x1ff & trans->byte_count)) {
    uint32_t lba;

    lba = trans->lba_start + trans->current_block;
    if (0 != (*ms->read_block)(lba,
          trans->msd_buf)) {

    }
    trans->current_block++;
   }
  }

  left = trans->bytes_to_write - trans->byte_count;
  max_len = ((ms->ep_out_size) < (left) ? (ms->ep_out_size) : (left));
  p = &trans->msd_buf[0x1ff & trans->byte_count];
  len = usbd_ep_write_packet(usbd_dev, ms->ep_in, p, max_len);
  trans->byte_count += len;
 } else {
  if (0 < trans->block_count) {
   if (trans->current_block == trans->block_count) {
    uint32_t lba;

    lba = trans->lba_start + trans->current_block;
    if (0 != (*ms->write_block)(lba,
           trans->msd_buf)) {

    }

    trans->current_block = 0;
    if (
       ((void *)0) 
            != ms->unlock) {
     (*ms->unlock)();
    }
   }
  }
  if (
     0 
           == trans->csw_valid) {
   scsi_command(ms, trans, EVENT_NEED_STATUS);
   trans->csw_valid = 
                     1
                         ;
  }

  left = sizeof(struct usb_msc_csw) - trans->csw_sent;
  if (0 < left) {
   max_len = ((ms->ep_out_size) < (left) ? (ms->ep_out_size) : (left));
   p = &trans->csw.buf[trans->csw_sent];
   len = usbd_ep_write_packet(usbd_dev, ms->ep_in, p,
         max_len);
   trans->csw_sent += len;
  }
 }
}


static void msc_data_tx_cb(usbd_device *usbd_dev, uint8_t ep)
{
 usbd_mass_storage *ms;
 struct usb_msc_trans *trans;
 int len, max_len, left;
 void *p;

 ms = &_mass_storage;
 trans = &ms->trans;

 if (trans->byte_count < trans->bytes_to_write) {
  if (0 < trans->block_count) {
   if (0 == (0x1ff & trans->byte_count)) {
    uint32_t lba;

    lba = trans->lba_start + trans->current_block;
    if (0 != (*ms->read_block)(lba,
          trans->msd_buf)) {

    }
    trans->current_block++;
   }
  }

  left = trans->bytes_to_write - trans->byte_count;
  max_len = ((ms->ep_out_size) < (left) ? (ms->ep_out_size) : (left));
  p = &trans->msd_buf[0x1ff & trans->byte_count];
  len = usbd_ep_write_packet(usbd_dev, ep, p, max_len);
  trans->byte_count += len;
 } else {
  if (0 < trans->block_count) {
   if (trans->current_block == trans->block_count) {
    trans->current_block = 0;
    if (
       ((void *)0) 
            != ms->unlock) {
     (*ms->unlock)();
    }
   }
  }
  if (
     0 
           == trans->csw_valid) {
   scsi_command(ms, trans, EVENT_NEED_STATUS);
   trans->csw_valid = 
                     1
                         ;
  }

  left = sizeof(struct usb_msc_csw) - trans->csw_sent;
  if (0 < left) {
   max_len = ((ms->ep_out_size) < (left) ? (ms->ep_out_size) : (left));
   p = &trans->csw.buf[trans->csw_sent];
   len = usbd_ep_write_packet(usbd_dev, ep, p, max_len);
   trans->csw_sent += len;
  } else if (sizeof(struct usb_msc_csw) == trans->csw_sent) {

   trans->lba_start = 0xffffffff;
   trans->block_count = 0;
   trans->current_block = 0;
   trans->cbw_cnt = 0;
   trans->bytes_to_read = 0;
   trans->bytes_to_write = 0;
   trans->byte_count = 0;
   trans->csw_sent = 0;
   trans->csw_valid = 
                     0
                          ;
  }
 }
}




static enum usbd_request_return_codes
msc_control_request(usbd_device *usbd_dev,
      struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
      usbd_control_complete_callback *complete)
{
 (void)complete;
 (void)usbd_dev;

 switch (req->bRequest) {
 case 0xFF:

  return USBD_REQ_HANDLED;
 case 0xFE:

  *buf[0] = 0;
  *len = 1;
  return USBD_REQ_HANDLED;
 }

 return USBD_REQ_NOTSUPP;
}


static void msc_set_config(usbd_device *usbd_dev, uint16_t wValue)
{
 usbd_mass_storage *ms = &_mass_storage;

 (void)wValue;

 usbd_ep_setup(usbd_dev, ms->ep_in, 0x02,
        ms->ep_in_size, msc_data_tx_cb);
 usbd_ep_setup(usbd_dev, ms->ep_out, 0x02,
        ms->ep_out_size, msc_data_rx_cb);

 usbd_register_control_callback(
    usbd_dev,
    0x20 | 0x01,
    0x60 | 0x1F,
    msc_control_request);
}
usbd_mass_storage *usb_msc_init(usbd_device *usbd_dev,
     uint8_t ep_in, uint8_t ep_in_size,
     uint8_t ep_out, uint8_t ep_out_size,
     const char *vendor_id,
     const char *product_id,
     const char *product_revision_level,
     const uint32_t block_count,
     int (*read_block)(uint32_t lba,
         uint8_t *copy_to),
     int (*write_block)(uint32_t lba,
          const uint8_t *copy_from))
{
 _mass_storage.usbd_dev = usbd_dev;
 _mass_storage.ep_in = ep_in;
 _mass_storage.ep_in_size = ep_in_size;
 _mass_storage.ep_out = ep_out;
 _mass_storage.ep_out_size = ep_out_size;
 _mass_storage.vendor_id = vendor_id;
 _mass_storage.product_id = product_id;
 _mass_storage.product_revision_level = product_revision_level;
 _mass_storage.block_count = block_count - 1;
 _mass_storage.read_block = read_block;
 _mass_storage.write_block = write_block;
 _mass_storage.lock = 
                     ((void *)0)
                         ;
 _mass_storage.unlock = 
                       ((void *)0)
                           ;

 _mass_storage.trans.lba_start = 0xffffffff;
 _mass_storage.trans.block_count = 0;
 _mass_storage.trans.current_block = 0;
 _mass_storage.trans.cbw_cnt = 0;
 _mass_storage.trans.bytes_to_read = 0;
 _mass_storage.trans.bytes_to_write = 0;
 _mass_storage.trans.byte_count = 0;
 _mass_storage.trans.csw_valid = 
                                0
                                     ;
 _mass_storage.trans.csw_sent = 0;

 set_sbc_status_good(&_mass_storage);

 usbd_register_set_config_callback(usbd_dev, msc_set_config);

 return &_mass_storage;
}
