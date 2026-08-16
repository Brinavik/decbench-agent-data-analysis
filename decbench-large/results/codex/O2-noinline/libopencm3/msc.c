// Function: _usbd_standard_request_device @ 0x8001914
#include <stdint.h>

typedef struct _usbd_device usbd_device;

struct usb_setup_data {
	uint8_t bmRequestType;
	uint8_t bRequest;
	uint16_t wValue;
	uint16_t wIndex;
	uint16_t wLength;
} __attribute__((packed));

enum usbd_request_return_codes {
	USBD_REQ_NOTSUPP = 0,
	USBD_REQ_HANDLED = 1,
	USBD_REQ_NEXT_CALLBACK = 2
};

enum {
	USB_REQ_GET_STATUS = 0,
	USB_REQ_CLEAR_FEATURE = 1,
	USB_REQ_SET_FEATURE = 3,
	USB_REQ_SET_ADDRESS = 5,
	USB_REQ_GET_DESCRIPTOR = 6,
	USB_REQ_SET_DESCRIPTOR = 7,
	USB_REQ_GET_CONFIGURATION = 8,
	USB_REQ_SET_CONFIGURATION = 9
};

extern enum usbd_request_return_codes usb_standard_set_address(
	usbd_device *usbd_dev, struct usb_setup_data *req,
	uint8_t **buf, uint16_t *len);
extern enum usbd_request_return_codes usb_standard_set_configuration(
	usbd_device *usbd_dev, struct usb_setup_data *req,
	uint8_t **buf, uint16_t *len);
extern enum usbd_request_return_codes usb_standard_get_configuration(
	usbd_device *usbd_dev, struct usb_setup_data *req,
	uint8_t **buf, uint16_t *len);
extern enum usbd_request_return_codes usb_standard_get_descriptor(
	usbd_device *usbd_dev, struct usb_setup_data *req,
	uint8_t **buf, uint16_t *len);
extern enum usbd_request_return_codes usb_standard_device_get_status(
	usbd_device *usbd_dev, struct usb_setup_data *req,
	uint8_t **buf, uint16_t *len);

enum usbd_request_return_codes _usbd_standard_request_device(
	usbd_device *usbd_dev, struct usb_setup_data *req,
	uint8_t **buf, uint16_t *len)
{
	enum usbd_request_return_codes (*command)(
		usbd_device *, struct usb_setup_data *, uint8_t **,
		uint16_t *) = 0;

	switch (req->bRequest) {
	case USB_REQ_CLEAR_FEATURE:
	case USB_REQ_SET_FEATURE:
		break;
	case USB_REQ_SET_ADDRESS:
		command = usb_standard_set_address;
		break;
	case USB_REQ_SET_CONFIGURATION:
		command = usb_standard_set_configuration;
		break;
	case USB_REQ_GET_CONFIGURATION:
		command = usb_standard_get_configuration;
		break;
	case USB_REQ_GET_DESCRIPTOR:
		command = usb_standard_get_descriptor;
		break;
	case USB_REQ_GET_STATUS:
		command = usb_standard_device_get_status;
		break;
	case USB_REQ_SET_DESCRIPTOR:
		break;
	}

	if (!command) {
		return USBD_REQ_NOTSUPP;
	}

	return command(usbd_dev, req, buf, len);
}


