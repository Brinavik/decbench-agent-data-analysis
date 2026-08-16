// Function: dwc_poll @ 0x80017f0
#include <stdint.h>

typedef struct usbd_device usbd_device;

typedef void (*usbd_event_callback)(void);
typedef void (*usbd_endpoint_callback)(usbd_device *, uint8_t);

typedef struct {
	volatile uint32_t control;
	volatile uint32_t _reserved04;
	volatile uint32_t interrupt;
	volatile uint32_t _reserved0c;
	volatile uint32_t size;
	volatile uint32_t dma;
	volatile uint32_t tx_fifo_status;
	volatile uint32_t _reserved1c;
} dwc_endpoint_registers;

typedef struct {
	volatile uint32_t _reserved000[4];
	volatile uint32_t reset_control;
	volatile uint32_t interrupt_status;
	volatile uint32_t interrupt_mask;
	volatile uint32_t receive_status;
	volatile uint32_t receive_status_pop;
	uint8_t _reserved024[0x900 - 0x24];
	dwc_endpoint_registers in_endpoint[4];
	uint8_t _reserved980[0xb00 - 0x980];
	dwc_endpoint_registers out_endpoint[4];
	uint8_t _reservedb80[0x1000 - 0xb80];
	volatile uint32_t fifo[1];
} dwc_registers;

typedef struct {
	uint8_t _reserved00[0x2c];
	dwc_registers *registers;
	uint8_t _reserved30[2];
	uint16_t rx_fifo_size;
} usbd_driver;

struct usbd_device {
	uint8_t _reserved00[0x20];
	usbd_event_callback user_callback_suspend;
	usbd_event_callback user_callback_resume;
	usbd_event_callback user_callback_sof;
	uint8_t _reserved2c[4];
	uint8_t control_request[8];
	uint8_t _reserved38[0x68 - 0x38];
	usbd_endpoint_callback user_callback_ctr[4][3];
	uint8_t _reserved98[0xdc - 0x98];
	usbd_driver *driver;
	uint8_t _reservede0[8];
	uint16_t fifo_mem_top;
	uint16_t fifo_mem_top_ep0;
	uint8_t force_nak[4];
	uint32_t out_endpoint_size[4];
	uint16_t rx_byte_count;
};

void dwc_poll(usbd_device *usbd_dev)
{
	extern void sub_80008a0(usbd_device *);
	extern void sub_8001440(usbd_driver *, uint8_t);
	extern uint16_t sub_8001770(usbd_device *, uint8_t, void *, uint16_t);

	enum {
		USB_TRANSACTION_IN = 0,
		USB_TRANSACTION_OUT = 1,
		USB_TRANSACTION_SETUP = 2
	};
	enum {
		GINTSTS_SOF = 0x00000008,
		GINTSTS_RXFLVL = 0x00000010,
		GINTSTS_USBSUSP = 0x00000800,
		GINTSTS_ENUMDNE = 0x00002000,
		GINTSTS_WKUPINT = 0x80000000
	};
	enum {
		RX_STATUS_OUT_DATA = 0x00040000,
		RX_STATUS_OUT_COMPLETE = 0x00060000,
		RX_STATUS_SETUP_COMPLETE = 0x00080000,
		RX_STATUS_SETUP_DATA = 0x000c0000,
		RX_STATUS_PACKET_MASK = 0x001e0000
	};
	enum {
		EPINT_TRANSFER_COMPLETE = 0x00000001,
		EPCTL_CLEAR_NAK = 0x04000000,
		EPCTL_SET_NAK = 0x08000000,
		EPCTL_ENABLE = 0x80000000
	};

	usbd_driver *driver = usbd_dev->driver;
	dwc_registers *regs = driver->registers;
	uint32_t interrupt_status = regs->interrupt_status;
	uint8_t ep;

	if (interrupt_status & GINTSTS_ENUMDNE) {
		regs->interrupt_status = GINTSTS_ENUMDNE;
		usbd_dev->fifo_mem_top = driver->rx_fifo_size;
		sub_80008a0(usbd_dev);
		return;
	}

	for (ep = 0; ep < 4; ep++) {
		if (regs->in_endpoint[ep].interrupt & EPINT_TRANSFER_COMPLETE) {
			usbd_endpoint_callback callback =
				usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_IN];

			if (callback != 0)
				callback(usbd_dev, ep);

			regs = usbd_dev->driver->registers;
			regs->in_endpoint[ep].interrupt = EPINT_TRANSFER_COMPLETE;
		}
	}

	if (interrupt_status & GINTSTS_RXFLVL) {
		uint32_t receive_status = regs->receive_status_pop;
		uint32_t packet_status = receive_status & RX_STATUS_PACKET_MASK;

		ep = receive_status & 0x0f;

		switch (packet_status) {
		case RX_STATUS_SETUP_COMPLETE:
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_SETUP](usbd_dev, ep);
			/* fall through */
		case RX_STATUS_OUT_COMPLETE:
			regs = usbd_dev->driver->registers;
			regs->out_endpoint[ep].size = usbd_dev->out_endpoint_size[ep];
			if (usbd_dev->force_nak[ep])
				regs->out_endpoint[ep].control |= EPCTL_ENABLE | EPCTL_SET_NAK;
			else
				regs->out_endpoint[ep].control |= EPCTL_ENABLE | EPCTL_CLEAR_NAK;
			return;

		case RX_STATUS_OUT_DATA: {
			usbd_endpoint_callback callback;
			uint32_t bytes_discarded;

			usbd_dev->rx_byte_count = (receive_status >> 4) & 0x7ff;
			callback = usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_OUT];
			if (callback != 0)
				callback(usbd_dev, ep);

			if (usbd_dev->rx_byte_count != 0) {
				regs = usbd_dev->driver->registers;
				for (bytes_discarded = 0;
				     bytes_discarded < usbd_dev->rx_byte_count;
				     bytes_discarded += 4)
					(void)regs->fifo[0];
			}
			usbd_dev->rx_byte_count = 0;
			break;
		}

		case RX_STATUS_SETUP_DATA: {
			uint32_t bytes_discarded;

			if (regs->in_endpoint[ep].size & 0x00080000)
				sub_8001440(usbd_dev->driver, ep);

			usbd_dev->rx_byte_count = (receive_status >> 4) & 0x7ff;
			(void)sub_8001770(usbd_dev, ep, usbd_dev->control_request, 8);

			if (usbd_dev->rx_byte_count != 0) {
				regs = usbd_dev->driver->registers;
				for (bytes_discarded = 0;
				     bytes_discarded < usbd_dev->rx_byte_count;
				     bytes_discarded += 4)
					(void)regs->fifo[0];
			}
			usbd_dev->rx_byte_count = 0;
			break;
		}

		default:
			break;
		}
	}

	if (interrupt_status & GINTSTS_USBSUSP) {
		if (usbd_dev->user_callback_suspend != 0)
			usbd_dev->user_callback_suspend();
		regs = usbd_dev->driver->registers;
		regs->interrupt_status = GINTSTS_USBSUSP;
	}

	if (interrupt_status & GINTSTS_WKUPINT) {
		if (usbd_dev->user_callback_resume != 0)
			usbd_dev->user_callback_resume();
		regs = usbd_dev->driver->registers;
		regs->interrupt_status = GINTSTS_WKUPINT;
	}

	if (interrupt_status & GINTSTS_SOF) {
		if (usbd_dev->user_callback_sof != 0)
			usbd_dev->user_callback_sof();

		regs = usbd_dev->driver->registers;
		regs->interrupt_status = GINTSTS_SOF;
		if (usbd_dev->user_callback_sof != 0)
			regs->interrupt_mask |= GINTSTS_SOF;
		else
			regs->interrupt_mask &= ~GINTSTS_SOF;
	}
}


