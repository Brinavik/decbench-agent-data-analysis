// Function: dwc_poll @ 0x8001714
#include <stdint.h>

typedef struct _usbd_device usbd_device;

typedef void (*usbd_callback)(void);
typedef void (*usbd_endpoint_callback)(usbd_device *usbd_dev, uint8_t ep);

struct usb_setup_data {
	uint8_t bmRequestType;
	uint8_t bRequest;
	uint16_t wValue;
	uint16_t wIndex;
	uint16_t wLength;
};

struct _usbd_driver {
	uint8_t operations[44];
	uint32_t base_address;
	uint8_t set_address_before_status;
	uint8_t _pad0;
	uint16_t rx_fifo_size;
};

struct _usbd_device {
	uint8_t _opaque0[28];
	usbd_callback user_callback_reset;
	usbd_callback user_callback_suspend;
	usbd_callback user_callback_resume;
	usbd_callback user_callback_sof;
	uint8_t control_state;
	uint8_t _pad0[3];
	struct usb_setup_data control_req;
	uint8_t *control_buf;
	uint16_t control_len;
	uint8_t _pad1[2];
	void (*control_complete)(usbd_device *usbd_dev,
				 struct usb_setup_data *req);
	uint8_t _opaque1[36];
	usbd_endpoint_callback user_callback_ctr[8][3];
	uint8_t _opaque2[20];
	const struct _usbd_driver *driver;
	uint8_t _opaque3[8];
	uint16_t fifo_mem_top;
	uint16_t fifo_mem_top_ep0;
	uint8_t force_nak[4];
	uint32_t doeptsiz[4];
	uint16_t rxbcnt;
};

extern void sub_8000790(usbd_device *usbd_dev);
extern void sub_8001364(const struct _usbd_driver *driver, uint8_t ep);
extern uint16_t sub_8001694(usbd_device *usbd_dev, uint8_t ep,
				   void *buf, uint16_t len);

#define MMIO32(address) \
	(*(volatile uint32_t *)(uintptr_t)(address))
#define OTG_REG(usbd_dev, offset) \
	MMIO32((usbd_dev)->driver->base_address + (offset))
#define OTG_GINTSTS(usbd_dev) OTG_REG((usbd_dev), 0x014U)
#define OTG_GINTMSK(usbd_dev) OTG_REG((usbd_dev), 0x018U)
#define OTG_GRXSTSP(usbd_dev) OTG_REG((usbd_dev), 0x020U)
#define OTG_DIEPINT(usbd_dev, ep) \
	OTG_REG((usbd_dev), 0x908U + 0x20U * (ep))
#define OTG_DIEPTSIZ(usbd_dev, ep) \
	OTG_REG((usbd_dev), 0x910U + 0x20U * (ep))
#define OTG_DOEPCTL(usbd_dev, ep) \
	OTG_REG((usbd_dev), 0xb00U + 0x20U * (ep))
#define OTG_DOEPTSIZ(usbd_dev, ep) \
	OTG_REG((usbd_dev), 0xb10U + 0x20U * (ep))
#define OTG_FIFO0(usbd_dev) OTG_REG((usbd_dev), 0x1000U)

enum {
	USB_TRANSACTION_IN = 0,
	USB_TRANSACTION_OUT = 1,
	USB_TRANSACTION_SETUP = 2
};

enum {
	OTG_GINTSTS_SOF = 1U << 3,
	OTG_GINTSTS_RXFLVL = 1U << 4,
	OTG_GINTSTS_USBSUSP = 1U << 11,
	OTG_GINTSTS_ENUMDNE = 1U << 13,
	OTG_GINTSTS_WKUINT = 1U << 31
};

enum {
	OTG_DIEPINT_XFRC = 1U << 0,
	OTG_DIEPTSIZ_PKTCNT = 1U << 19,
	OTG_DOEPCTL_CNAK = 1U << 26,
	OTG_DOEPCTL_SNAK = 1U << 27,
	OTG_DOEPCTL_EPENA = 1U << 31
};

enum {
	OTG_GRXSTSP_EPNUM_MASK = 0x0fU,
	OTG_GRXSTSP_BCNT_MASK = 0x7ff0U,
	OTG_GRXSTSP_PKTSTS_MASK = 0x1e0000U,
	OTG_GRXSTSP_OUT_DATA = 0x40000U,
	OTG_GRXSTSP_OUT_COMPLETE = 0x60000U,
	OTG_GRXSTSP_SETUP_COMPLETE = 0x80000U,
	OTG_GRXSTSP_SETUP_DATA = 0xc0000U
};

void dwc_poll(usbd_device *usbd_dev)
{
	uint32_t intsts = OTG_GINTSTS(usbd_dev);
	uint8_t ep;

	if (intsts & OTG_GINTSTS_ENUMDNE) {
		OTG_GINTSTS(usbd_dev) = OTG_GINTSTS_ENUMDNE;
		usbd_dev->fifo_mem_top = usbd_dev->driver->rx_fifo_size;
		sub_8000790(usbd_dev);
		return;
	}

	for (ep = 0; ep < 4; ep++) {
		if (OTG_DIEPINT(usbd_dev, ep) & OTG_DIEPINT_XFRC) {
			usbd_endpoint_callback callback =
				usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_IN];

			if (callback != 0)
				callback(usbd_dev, ep);
			OTG_DIEPINT(usbd_dev, ep) = OTG_DIEPINT_XFRC;
		}
	}

	if (intsts & OTG_GINTSTS_RXFLVL) {
		uint32_t rxstsp = OTG_GRXSTSP(usbd_dev);
		uint32_t pktsts = rxstsp & OTG_GRXSTSP_PKTSTS_MASK;
		uint8_t rx_ep = rxstsp & OTG_GRXSTSP_EPNUM_MASK;

		switch (pktsts) {
		case OTG_GRXSTSP_SETUP_COMPLETE:
			usbd_dev->user_callback_ctr[rx_ep][USB_TRANSACTION_SETUP](
				usbd_dev, rx_ep);
			/* fall through */
		case OTG_GRXSTSP_OUT_COMPLETE:
			OTG_DOEPTSIZ(usbd_dev, rx_ep) = usbd_dev->doeptsiz[rx_ep];
			if (usbd_dev->force_nak[rx_ep])
				OTG_DOEPCTL(usbd_dev, rx_ep) |=
					OTG_DOEPCTL_EPENA | OTG_DOEPCTL_SNAK;
			else
				OTG_DOEPCTL(usbd_dev, rx_ep) |=
					OTG_DOEPCTL_EPENA | OTG_DOEPCTL_CNAK;
			return;

		case OTG_GRXSTSP_OUT_DATA:
			usbd_dev->rxbcnt =
				(uint16_t)((rxstsp & OTG_GRXSTSP_BCNT_MASK) >> 4);
			if (usbd_dev->user_callback_ctr[rx_ep][USB_TRANSACTION_OUT])
				usbd_dev->user_callback_ctr[rx_ep][USB_TRANSACTION_OUT](
					usbd_dev, rx_ep);
			break;

		case OTG_GRXSTSP_SETUP_DATA:
			if (OTG_DIEPTSIZ(usbd_dev, rx_ep) & OTG_DIEPTSIZ_PKTCNT)
				sub_8001364(usbd_dev->driver, rx_ep);
			usbd_dev->rxbcnt =
				(uint16_t)((rxstsp & OTG_GRXSTSP_BCNT_MASK) >> 4);
			(void)sub_8001694(usbd_dev, rx_ep,
					  &usbd_dev->control_req, 8);
			break;

		default:
			return;
		}

		if (usbd_dev->rxbcnt) {
			uint32_t i;

			for (i = 0; i < usbd_dev->rxbcnt; i += 4)
				(void)OTG_FIFO0(usbd_dev);
		}
		usbd_dev->rxbcnt = 0;
	}

	if (intsts & OTG_GINTSTS_USBSUSP) {
		if (usbd_dev->user_callback_suspend)
			usbd_dev->user_callback_suspend();
		OTG_GINTSTS(usbd_dev) = OTG_GINTSTS_USBSUSP;
	}

	if (intsts & OTG_GINTSTS_WKUINT) {
		if (usbd_dev->user_callback_resume)
			usbd_dev->user_callback_resume();
		OTG_GINTSTS(usbd_dev) = OTG_GINTSTS_WKUINT;
	}

	if ((intsts & OTG_GINTSTS_SOF) && usbd_dev->user_callback_sof) {
		usbd_dev->user_callback_sof();
		OTG_GINTSTS(usbd_dev) = OTG_GINTSTS_SOF;
	}

	if (usbd_dev->user_callback_sof) {
		OTG_GINTMSK(usbd_dev) |= OTG_GINTSTS_SOF;
	} else {
		OTG_GINTSTS(usbd_dev) = OTG_GINTSTS_SOF;
		OTG_GINTMSK(usbd_dev) &= ~OTG_GINTSTS_SOF;
	}
}


