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






static void stall_transaction(usbd_device *usbd_dev)
{
 usbd_ep_stall_set(usbd_dev, 0, 1);
 usbd_dev->control_state.state = IDLE;
}
static 
      _Bool 
           needs_zlp(uint16_t len, uint16_t wLength, uint8_t ep_size)
{
 if (len < wLength) {
  if (len && (len % ep_size == 0)) {
   return 
         1
             ;
  }
 }
 return 
       0
            ;
}


int usbd_register_control_callback(usbd_device *usbd_dev, uint8_t type,
       uint8_t type_mask,
       usbd_control_callback callback)
{
 int i;

 for (i = 0; i < 4; i++) {
  if (usbd_dev->user_control_callback[i].cb) {
   continue;
  }

  usbd_dev->user_control_callback[i].type = type;
  usbd_dev->user_control_callback[i].type_mask = type_mask;
  usbd_dev->user_control_callback[i].cb = callback;
  return 0;
 }

 return -1;
}

static void usb_control_send_chunk(usbd_device *usbd_dev)
{
 if (usbd_dev->desc->bMaxPacketSize0 <
   usbd_dev->control_state.ctrl_len) {

  usbd_ep_write_packet(usbd_dev, 0,
         usbd_dev->control_state.ctrl_buf,
         usbd_dev->desc->bMaxPacketSize0);
  usbd_dev->control_state.state = DATA_IN;
  usbd_dev->control_state.ctrl_buf +=
   usbd_dev->desc->bMaxPacketSize0;
  usbd_dev->control_state.ctrl_len -=
   usbd_dev->desc->bMaxPacketSize0;
 } else {

  usbd_ep_write_packet(usbd_dev, 0,
         usbd_dev->control_state.ctrl_buf,
         usbd_dev->control_state.ctrl_len);

  usbd_dev->control_state.state =
   usbd_dev->control_state.needs_zlp ?
   DATA_IN : LAST_DATA_IN;
  usbd_dev->control_state.needs_zlp = 
                                     0
                                          ;
  usbd_dev->control_state.ctrl_len = 0;
  usbd_dev->control_state.ctrl_buf = 
                                    ((void *)0)
                                        ;
 }
}

static int usb_control_recv_chunk(usbd_device *usbd_dev)
{
 uint16_t packetsize = ((usbd_dev->desc->bMaxPacketSize0) < (usbd_dev->control_state.req.wLength - usbd_dev->control_state.ctrl_len) ? (usbd_dev->desc->bMaxPacketSize0) : (usbd_dev->control_state.req.wLength - usbd_dev->control_state.ctrl_len))

                                    ;
 uint16_t size = usbd_ep_read_packet(usbd_dev, 0,
           usbd_dev->control_state.ctrl_buf +
           usbd_dev->control_state.ctrl_len,
           packetsize);

 if (size != packetsize) {
  stall_transaction(usbd_dev);
  return -1;
 }

 usbd_dev->control_state.ctrl_len += size;

 return packetsize;
}

static enum usbd_request_return_codes
usb_control_request_dispatch(usbd_device *usbd_dev,
        struct usb_setup_data *req)
{
 int i, result = 0;
 struct user_control_callback *cb = usbd_dev->user_control_callback;


 for (i = 0; i < 4; i++) {
  if (cb[i].cb == 
                 ((void *)0)
                     ) {
   break;
  }

  if ((req->bmRequestType & cb[i].type_mask) == cb[i].type) {
   result = cb[i].cb(usbd_dev, req,
       &(usbd_dev->control_state.ctrl_buf),
       &(usbd_dev->control_state.ctrl_len),
       &(usbd_dev->control_state.complete));
   if (result == USBD_REQ_HANDLED ||
       result == USBD_REQ_NOTSUPP) {
    return result;
   }
  }
 }


 return _usbd_standard_request(usbd_dev, req,
          &(usbd_dev->control_state.ctrl_buf),
          &(usbd_dev->control_state.ctrl_len));
}


static void usb_control_setup_read(usbd_device *usbd_dev,
  struct usb_setup_data *req)
{
 usbd_dev->control_state.ctrl_buf = usbd_dev->ctrl_buf;
 usbd_dev->control_state.ctrl_len = req->wLength;

 if (usb_control_request_dispatch(usbd_dev, req)) {
  if (req->wLength) {
   usbd_dev->control_state.needs_zlp =
    needs_zlp(usbd_dev->control_state.ctrl_len,
     req->wLength,
     usbd_dev->desc->bMaxPacketSize0);

   usb_control_send_chunk(usbd_dev);
  } else {

   usbd_ep_write_packet(usbd_dev, 0, 
                                    ((void *)0)
                                        , 0);
   usbd_dev->control_state.state = STATUS_IN;
  }
 } else {

  stall_transaction(usbd_dev);
 }
}

static void usb_control_setup_write(usbd_device *usbd_dev,
        struct usb_setup_data *req)
{
 if (req->wLength > usbd_dev->ctrl_buf_len) {
  stall_transaction(usbd_dev);
  return;
 }


 usbd_dev->control_state.ctrl_buf = usbd_dev->ctrl_buf;
 usbd_dev->control_state.ctrl_len = 0;

 if (req->wLength > usbd_dev->desc->bMaxPacketSize0) {
  usbd_dev->control_state.state = DATA_OUT;
 } else {
  usbd_dev->control_state.state = LAST_DATA_OUT;
 }

 usbd_ep_nak_set(usbd_dev, 0, 0);
}




void _usbd_control_setup(usbd_device *usbd_dev, uint8_t ea)
{
 struct usb_setup_data *req = &usbd_dev->control_state.req;
 (void)ea;

 usbd_dev->control_state.complete = 
                                   ((void *)0)
                                       ;

 usbd_ep_nak_set(usbd_dev, 0, 1);

 if (req->wLength == 0) {
  usb_control_setup_read(usbd_dev, req);
 } else if (req->bmRequestType & 0x80) {
  usb_control_setup_read(usbd_dev, req);
 } else {
  usb_control_setup_write(usbd_dev, req);
 }
}

void _usbd_control_out(usbd_device *usbd_dev, uint8_t ea)
{
 (void)ea;

 switch (usbd_dev->control_state.state) {
 case DATA_OUT:
  if (usb_control_recv_chunk(usbd_dev) < 0) {
   break;
  }
  if ((usbd_dev->control_state.req.wLength -
     usbd_dev->control_state.ctrl_len) <=
     usbd_dev->desc->bMaxPacketSize0) {
   usbd_dev->control_state.state = LAST_DATA_OUT;
  }
  break;
 case LAST_DATA_OUT:
  if (usb_control_recv_chunk(usbd_dev) < 0) {
   break;
  }




  if (usb_control_request_dispatch(usbd_dev,
     &(usbd_dev->control_state.req))) {

   usbd_ep_write_packet(usbd_dev, 0, 
                                    ((void *)0)
                                        , 0);
   usbd_dev->control_state.state = STATUS_IN;
  } else {
   stall_transaction(usbd_dev);
  }
  break;
 case STATUS_OUT:
  usbd_ep_read_packet(usbd_dev, 0, 
                                  ((void *)0)
                                      , 0);
  usbd_dev->control_state.state = IDLE;
  if (usbd_dev->control_state.complete) {
   usbd_dev->control_state.complete(usbd_dev,
     &(usbd_dev->control_state.req));
  }
  usbd_dev->control_state.complete = 
                                    ((void *)0)
                                        ;
  break;
 default:
  stall_transaction(usbd_dev);
 }
}

void _usbd_control_in(usbd_device *usbd_dev, uint8_t ea)
{
 (void)ea;
 struct usb_setup_data *req = &(usbd_dev->control_state.req);

 switch (usbd_dev->control_state.state) {
 case DATA_IN:
  usb_control_send_chunk(usbd_dev);
  break;
 case LAST_DATA_IN:
  usbd_dev->control_state.state = STATUS_OUT;
  usbd_ep_nak_set(usbd_dev, 0, 0);
  break;
 case STATUS_IN:
  if (usbd_dev->control_state.complete) {
   usbd_dev->control_state.complete(usbd_dev,
     &(usbd_dev->control_state.req));
  }


  if ((req->bmRequestType == 0) &&
      (req->bRequest == 5)) {
   usbd_dev->driver->set_address(usbd_dev, req->wValue);
  }
  usbd_dev->control_state.state = IDLE;
  break;
 default:
  stall_transaction(usbd_dev);
 }
}
