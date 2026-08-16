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
