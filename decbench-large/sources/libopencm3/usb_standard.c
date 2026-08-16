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

int usbd_register_set_config_callback(usbd_device *usbd_dev,
           usbd_set_config_callback callback)
{
 int i;

 for (i = 0; i < 4; i++) {
  if (usbd_dev->user_callback_set_config[i]) {
   if (usbd_dev->user_callback_set_config[i] == callback) {
    return 0;
   }
   continue;
  }

  usbd_dev->user_callback_set_config[i] = callback;
  return 0;
 }

 return -1;
}

void usbd_register_set_altsetting_callback(usbd_device *usbd_dev,
     usbd_set_altsetting_callback callback)
{
 usbd_dev->user_callback_set_altsetting = callback;
}

static uint16_t build_config_descriptor(usbd_device *usbd_dev,
       uint8_t index, uint8_t *buf, uint16_t len)
{
 uint8_t *tmpbuf = buf;
 const struct usb_config_descriptor *cfg = &usbd_dev->config[index];
 uint16_t count, total = 0, totallen = 0;
 uint16_t i, j, k;

 memcpy(buf, cfg, count = ((len) < (cfg->bLength) ? (len) : (cfg->bLength)));
 buf += count;
 len -= count;
 total += count;
 totallen += cfg->bLength;


 for (i = 0; i < cfg->bNumInterfaces; i++) {

  if (cfg->interface[i].iface_assoc) {
   const struct usb_iface_assoc_descriptor *assoc =
     cfg->interface[i].iface_assoc;
   memcpy(buf, assoc, count = ((len) < (assoc->bLength) ? (len) : (assoc->bLength)));
   buf += count;
   len -= count;
   total += count;
   totallen += assoc->bLength;
  }

  for (j = 0; j < cfg->interface[i].num_altsetting; j++) {
   const struct usb_interface_descriptor *iface =
     &cfg->interface[i].altsetting[j];

   memcpy(buf, iface, count = ((len) < (iface->bLength) ? (len) : (iface->bLength)));
   buf += count;
   len -= count;
   total += count;
   totallen += iface->bLength;

   if (iface->extra) {
    memcpy(buf, iface->extra,
           count = ((len) < (iface->extralen) ? (len) : (iface->extralen)));
    buf += count;
    len -= count;
    total += count;
    totallen += iface->extralen;
   }

   for (k = 0; k < iface->bNumEndpoints; k++) {
    const struct usb_endpoint_descriptor *ep =
        &iface->endpoint[k];
    memcpy(buf, ep, count = ((len) < (ep->bLength) ? (len) : (ep->bLength)));
    buf += count;
    len -= count;
    total += count;
    totallen += ep->bLength;

    if (ep->extra) {
     memcpy(buf, ep->extra,
            count = ((len) < (ep->extralen) ? (len) : (ep->extralen)));
     buf += count;
     len -= count;
     total += count;
     totallen += ep->extralen;
    }
   }
  }
 }



 memcpy((tmpbuf + 2), &totallen, sizeof(uint16_t));

 return total;
}

static int usb_descriptor_type(uint16_t wValue)
{
 return wValue >> 8;
}

static int usb_descriptor_index(uint16_t wValue)
{
 return wValue & 0xFF;
}

static enum usbd_request_return_codes
usb_standard_get_descriptor(usbd_device *usbd_dev,
       struct usb_setup_data *req,
       uint8_t **buf, uint16_t *len)
{
 int i, array_idx, descr_idx;
 struct usb_string_descriptor *sd;

 descr_idx = usb_descriptor_index(req->wValue);

 switch (usb_descriptor_type(req->wValue)) {
 case 1:
  *buf = (uint8_t *) usbd_dev->desc;
  *len = ((*len) < (usbd_dev->desc->bLength) ? (*len) : (usbd_dev->desc->bLength));
  return USBD_REQ_HANDLED;
 case 2:
  *buf = usbd_dev->ctrl_buf;
  *len = build_config_descriptor(usbd_dev, descr_idx, *buf, *len);
  return USBD_REQ_HANDLED;
 case 3:
  sd = (struct usb_string_descriptor *)usbd_dev->ctrl_buf;

  if (descr_idx == 0) {

   sd->wData[0] = USB_LANGID_ENGLISH_US;
   sd->bLength = sizeof(sd->bLength) +
          sizeof(sd->bDescriptorType) +
          sizeof(sd->wData[0]);

   *len = ((*len) < (sd->bLength) ? (*len) : (sd->bLength));
  } else if (descr_idx == usbd_dev->extra_string_idx) {



   sd->bLength = strlen(usbd_dev->extra_string) * 2 +
          sizeof(sd->bLength) +
          sizeof(sd->bDescriptorType);

   *len = ((*len) < (sd->bLength) ? (*len) : (sd->bLength));

   for (i = 0; i < (*len / 2) - 1; i++) {
    sd->wData[i] =
     usbd_dev->extra_string[i];
   }
        } else {
   array_idx = descr_idx - 1;

   if (!usbd_dev->strings) {

    return USBD_REQ_NOTSUPP;
   }


   if (array_idx >= usbd_dev->num_strings) {
    return USBD_REQ_NOTSUPP;
   }



   if (req->wIndex != USB_LANGID_ENGLISH_US) {
    return USBD_REQ_NOTSUPP;
   }




   sd->bLength = strlen(usbd_dev->strings[array_idx]) * 2 +
          sizeof(sd->bLength) +
          sizeof(sd->bDescriptorType);

   *len = ((*len) < (sd->bLength) ? (*len) : (sd->bLength));

   for (i = 0; i < (*len / 2) - 1; i++) {
    sd->wData[i] =
     usbd_dev->strings[array_idx][i];
   }
  }

  sd->bDescriptorType = 3;
  *buf = (uint8_t *)sd;

  return USBD_REQ_HANDLED;
 }
 return USBD_REQ_NOTSUPP;
}

static enum usbd_request_return_codes
usb_standard_set_address(usbd_device *usbd_dev,
    struct usb_setup_data *req, uint8_t **buf,
    uint16_t *len)
{
 (void)req;
 (void)buf;
 (void)len;


 if ((req->bmRequestType != 0) || (req->wValue >= 128)) {
  return USBD_REQ_NOTSUPP;
 }

 usbd_dev->current_address = req->wValue;





 if (usbd_dev->driver->set_address_before_status) {
  usbd_dev->driver->set_address(usbd_dev, req->wValue);
 }

 return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_set_configuration(usbd_device *usbd_dev,
          struct usb_setup_data *req,
          uint8_t **buf, uint16_t *len)
{
 unsigned i;
 int found_index = -1;
 const struct usb_config_descriptor *cfg;

 (void)req;
 (void)buf;
 (void)len;

 if (req->wValue > 0) {
  for (i = 0; i < usbd_dev->desc->bNumConfigurations; i++) {
   if (req->wValue
       == usbd_dev->config[i].bConfigurationValue) {
    found_index = i;
    break;
   }
  }
  if (found_index < 0) {
   return USBD_REQ_NOTSUPP;
  }
 }

 usbd_dev->current_config = found_index + 1;

 if (usbd_dev->current_config > 0) {
  cfg = &usbd_dev->config[usbd_dev->current_config - 1];


  for (i = 0; i < cfg->bNumInterfaces; i++) {
   if (cfg->interface[i].cur_altsetting) {
    *cfg->interface[i].cur_altsetting = 0;
   }
  }
 }


 usbd_dev->driver->ep_reset(usbd_dev);

 if (usbd_dev->user_callback_set_config[0]) {




  for (i = 0; i < 4; i++) {
   usbd_dev->user_control_callback[i].cb = 
                                          ((void *)0)
                                              ;
  }

  for (i = 0; i < 4; i++) {
   if (usbd_dev->user_callback_set_config[i]) {
    usbd_dev->user_callback_set_config[i](usbd_dev,
        req->wValue);
   }
  }
 }

 return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_get_configuration(usbd_device *usbd_dev,
          struct usb_setup_data *req,
          uint8_t **buf, uint16_t *len)
{
 (void)req;

 if (*len > 1) {
  *len = 1;
 }
 if (usbd_dev->current_config > 0) {
  const struct usb_config_descriptor *cfg =
   &usbd_dev->config[usbd_dev->current_config - 1];
  (*buf)[0] = cfg->bConfigurationValue;
 } else {
  (*buf)[0] = 0;
 }

 return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_set_interface(usbd_device *usbd_dev,
      struct usb_setup_data *req,
      uint8_t **buf, uint16_t *len)
{
 const struct usb_config_descriptor *cfx =
  &usbd_dev->config[usbd_dev->current_config - 1];
 const struct usb_interface *iface;

 (void)buf;

 if (req->wIndex >= cfx->bNumInterfaces) {
  return USBD_REQ_NOTSUPP;
 }

 iface = &cfx->interface[req->wIndex];

 if (req->wValue >= iface->num_altsetting) {
  return USBD_REQ_NOTSUPP;
 }

 if (iface->cur_altsetting) {
  *iface->cur_altsetting = req->wValue;
 } else if (req->wValue > 0) {
  return USBD_REQ_NOTSUPP;
 }

 if (usbd_dev->user_callback_set_altsetting) {
   usbd_dev->user_callback_set_altsetting(usbd_dev,
              req->wIndex,
              req->wValue);
 }

 *len = 0;

 return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_get_interface(usbd_device *usbd_dev,
      struct usb_setup_data *req,
      uint8_t **buf, uint16_t *len)
{
 uint8_t *cur_altsetting;
 const struct usb_config_descriptor *cfx =
  &usbd_dev->config[usbd_dev->current_config - 1];

 if (req->wIndex >= cfx->bNumInterfaces) {
  return USBD_REQ_NOTSUPP;
 }

 *len = 1;
 cur_altsetting = cfx->interface[req->wIndex].cur_altsetting;
 (*buf)[0] = (cur_altsetting) ? *cur_altsetting : 0;

 return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_device_get_status(usbd_device *usbd_dev,
          struct usb_setup_data *req,
          uint8_t **buf, uint16_t *len)
{
 (void)usbd_dev;
 (void)req;



 if (*len > 2) {
  *len = 2;
 }
 (*buf)[0] = 0;
 (*buf)[1] = 0;

 return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_interface_get_status(usbd_device *usbd_dev,
      struct usb_setup_data *req,
      uint8_t **buf, uint16_t *len)
{
 (void)usbd_dev;
 (void)req;


 if (*len > 2) {
  *len = 2;
 }
 (*buf)[0] = 0;
 (*buf)[1] = 0;

 return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_endpoint_get_status(usbd_device *usbd_dev,
     struct usb_setup_data *req,
     uint8_t **buf, uint16_t *len)
{
 (void)req;

 if (*len > 2) {
  *len = 2;
 }
 (*buf)[0] = usbd_ep_stall_get(usbd_dev, req->wIndex) ? 1 : 0;
 (*buf)[1] = 0;

 return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_endpoint_stall(usbd_device *usbd_dev,
       struct usb_setup_data *req,
       uint8_t **buf, uint16_t *len)
{
 (void)buf;
 (void)len;

 usbd_ep_stall_set(usbd_dev, req->wIndex, 1);

 return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_endpoint_unstall(usbd_device *usbd_dev,
         struct usb_setup_data *req,
         uint8_t **buf, uint16_t *len)
{
 (void)buf;
 (void)len;

 usbd_ep_stall_set(usbd_dev, req->wIndex, 0);

 return USBD_REQ_HANDLED;
}




enum usbd_request_return_codes
_usbd_standard_request_device(usbd_device *usbd_dev,
         struct usb_setup_data *req, uint8_t **buf,
         uint16_t *len)
{
 enum usbd_request_return_codes (*command)(usbd_device *usbd_dev,
  struct usb_setup_data *req,
  uint8_t **buf, uint16_t *len) = 
                                 ((void *)0)
                                     ;

 switch (req->bRequest) {
 case 1:
 case 3:
  if (req->wValue == 1) {

  }

  if (req->wValue == 2) {

  }

  break;
 case 5:




  command = usb_standard_set_address;
  break;
 case 9:
  command = usb_standard_set_configuration;
  break;
 case 8:
  command = usb_standard_get_configuration;
  break;
 case 6:
  command = usb_standard_get_descriptor;
  break;
 case 0:




  command = usb_standard_device_get_status;
  break;
 case 7:

  break;
 }

 if (!command) {
  return USBD_REQ_NOTSUPP;
 }

 return command(usbd_dev, req, buf, len);
}

enum usbd_request_return_codes
_usbd_standard_request_interface(usbd_device *usbd_dev,
     struct usb_setup_data *req, uint8_t **buf,
     uint16_t *len)
{
 enum usbd_request_return_codes (*command)(usbd_device *usbd_dev,
  struct usb_setup_data *req,
  uint8_t **buf, uint16_t *len) = 
                                 ((void *)0)
                                     ;

 switch (req->bRequest) {
 case 1:
 case 3:

  break;
 case 10:
  command = usb_standard_get_interface;
  break;
 case 11:
  command = usb_standard_set_interface;
  break;
 case 0:
  command = usb_standard_interface_get_status;
  break;
 }

 if (!command) {
  return USBD_REQ_NOTSUPP;
 }

 return command(usbd_dev, req, buf, len);
}

enum usbd_request_return_codes
_usbd_standard_request_endpoint(usbd_device *usbd_dev,
    struct usb_setup_data *req, uint8_t **buf,
    uint16_t *len)
{
 enum usbd_request_return_codes (*command) (usbd_device *usbd_dev,
  struct usb_setup_data *req,
  uint8_t **buf, uint16_t *len) = 
                                 ((void *)0)
                                     ;

 switch (req->bRequest) {
 case 1:
  if (req->wValue == 0) {
   command = usb_standard_endpoint_unstall;
  }
  break;
 case 3:
  if (req->wValue == 0) {
   command = usb_standard_endpoint_stall;
  }
  break;
 case 0:
  command = usb_standard_endpoint_get_status;
  break;
 case 12:





  break;
 }

 if (!command) {
  return USBD_REQ_NOTSUPP;
 }

 return command(usbd_dev, req, buf, len);
}

enum usbd_request_return_codes
_usbd_standard_request(usbd_device *usbd_dev, struct usb_setup_data *req,
         uint8_t **buf, uint16_t *len)
{

 if ((req->bmRequestType & 0x60) != 0x00) {
  return USBD_REQ_NOTSUPP;
 }

 switch (req->bmRequestType & 0x1F) {
 case 0x00:
  return _usbd_standard_request_device(usbd_dev, req, buf, len);
 case 0x01:
  return _usbd_standard_request_interface(usbd_dev, req,
       buf, len);
 case 0x02:
  return _usbd_standard_request_endpoint(usbd_dev, req, buf, len);
 default:
  return USBD_REQ_NOTSUPP;
 }
}
