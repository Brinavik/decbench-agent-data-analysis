#define __CDC_H 








#define USB_CLASS_CDC 0x02


#define USB_CDC_SUBCLASS_DLCM 0x01
#define USB_CDC_SUBCLASS_ACM 0x02



#define USB_CDC_PROTOCOL_NONE 0x00
#define USB_CDC_PROTOCOL_AT 0x01



#define USB_CLASS_DATA 0x0A


#define CS_INTERFACE 0x24
#define CS_ENDPOINT 0x25



#define USB_CDC_TYPE_HEADER 0x00
#define USB_CDC_TYPE_CALL_MANAGEMENT 0x01
#define USB_CDC_TYPE_ACM 0x02

#define USB_CDC_TYPE_UNION 0x06




struct usb_cdc_header_descriptor {
 uint8_t bFunctionLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint16_t bcdCDC;
} __attribute__((packed));


struct usb_cdc_union_descriptor {
 uint8_t bFunctionLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bControlInterface;
 uint8_t bSubordinateInterface0;

} __attribute__((packed));
struct usb_cdc_call_management_descriptor {
 uint8_t bFunctionLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bmCapabilities;
 uint8_t bDataInterface;
} __attribute__((packed));


struct usb_cdc_acm_descriptor {
 uint8_t bFunctionLength;
 uint8_t bDescriptorType;
 uint8_t bDescriptorSubtype;
 uint8_t bmCapabilities;
} __attribute__((packed));



#define USB_CDC_REQ_SET_LINE_CODING 0x20

#define USB_CDC_REQ_SET_CONTROL_LINE_STATE 0x22



struct usb_cdc_line_coding {
 uint32_t dwDTERate;
 uint8_t bCharFormat;
 uint8_t bParityType;
 uint8_t bDataBits;
} __attribute__((packed));

enum usb_cdc_line_coding_bCharFormat {
 USB_CDC_1_STOP_BITS = 0,
 USB_CDC_1_5_STOP_BITS = 1,
 USB_CDC_2_STOP_BITS = 2,
};

enum usb_cdc_line_coding_bParityType {
 USB_CDC_NO_PARITY = 0,
 USB_CDC_ODD_PARITY = 1,
 USB_CDC_EVEN_PARITY = 2,
 USB_CDC_MARK_PARITY = 3,
 USB_CDC_SPACE_PARITY = 4,
};



#define USB_CDC_NOTIFY_SERIAL_STATE 0x20



struct usb_cdc_notification {
 uint8_t bmRequestType;
 uint8_t bNotification;
 uint16_t wValue;
 uint16_t wIndex;
 uint16_t wLength;
} __attribute__((packed));
