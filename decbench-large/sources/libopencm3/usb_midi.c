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
