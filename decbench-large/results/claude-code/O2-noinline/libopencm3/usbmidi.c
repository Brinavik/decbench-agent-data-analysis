// Function: dwc_poll @ 0x80017f0
#include <stdint.h>

/*
 * Reconstruction of the USB dwc_poll (DWC2 / STM32-style) device interrupt handler
 * located at 0x80017f0.
 *
 * arg0 (usbp) is the USB driver object.  usbp+0xDC points to a controller
 * object whose field +0x2C holds the dwc_poll core register base.  The relevant
 * register offsets are the standard DWC2 device layout:
 *      +0x14  GINTSTS          global interrupt status
 *      +0x18  GINTMSK          global interrupt mask
 *      +0x20  GRXSTSP          receive status read & pop
 *      +0x908 + ep*0x20  DIEPINT[ep]
 *      +0x910 + ep*0x20  DIEPTSIZ[ep]
 *      +0xB00 + ep*0x20  DOEPCTL[ep]
 *      +0xB10 + ep*0x20  DOEPTSIZ[ep]
 *      +0x1000           data FIFO
 */

/* per-endpoint callback table stored inline in the driver object at +0x68 */
typedef struct {
    void (*in_cb)(void *usbp, uint8_t ep);      /* +0x00 (abs +0x68) */
    void (*out_cb)(void *usbp, uint32_t ep);    /* +0x04 (abs +0x6C) */
    void (*setup_cb)(void *usbp, uint32_t ep);  /* +0x08 (abs +0x70) */
} ep_ops_t;

extern void     sub_80008a0(void *usbp);                                   /* bus reset / enum-done */
extern uint32_t sub_8001770(void *usbp, uint32_t ep, void *dst, uint32_t len); /* pop packet from FIFO */
extern void     sub_8001440(void *ctrl, uint32_t ep);                      /* prime OUT endpoint */

#define dwc_poll(ctrl)   (*(volatile uint8_t **)((char *)(ctrl) + 0x2C))
#define REG(o, off) (*(volatile uint32_t *)((o) + (off)))
#define DHW(base, off) (*(uint16_t *)((char *)(base) + (off)))

void dwc_poll(void *usbp)
{
    void *ctrl = *(void **)((char *)usbp + 0xDC);
    volatile uint8_t *otg = dwc_poll(ctrl);
    ep_ops_t *ops = (ep_ops_t *)((char *)usbp + 0x68);
    uint32_t gintsts = REG(otg, 0x14);

    /* ---- ENUMDNE : speed enumeration done ---- */
    if (gintsts & 0x2000) {
        uint16_t speed = *(volatile uint16_t *)((char *)ctrl + 0x32);
        REG(otg, 0x14) = 0x2000;                 /* clear ENUMDNE */
        DHW(usbp, 0xE8) = speed;
        sub_80008a0(usbp);
        return;
    }

    /* ---- IN endpoint transfer-complete servicing (endpoints 0..3) ---- */
    for (int ep = 0; ep < 4; ep++) {
        otg = dwc_poll(ctrl);
        if (REG(otg, 0x908 + ep * 0x20) & 1) {   /* DIEPINT.XFRC */
            if (ops[ep].in_cb) {
                ops[ep].in_cb(usbp, (uint8_t)ep);
                ctrl = *(void **)((char *)usbp + 0xDC);
                otg = dwc_poll(ctrl);
            }
            REG(otg, 0x908 + ep * 0x20) = 1;     /* clear XFRC */
        }
    }

    /* ---- RXFLVL : Rx FIFO non-empty ---- */
    if (gintsts & 0x10) {
        otg = dwc_poll(ctrl);
        uint32_t grxstsp = REG(otg, 0x20);
        uint32_t ep = grxstsp & 0xF;             /* EPNUM */

        switch (grxstsp & 0x1E0000) {            /* PKTSTS */
        case 0x80000:                            /* SETUP transaction complete */
            ops[ep].setup_cb(usbp, ep);
            ctrl = *(void **)((char *)usbp + 0xDC);
            otg = dwc_poll(ctrl);
            /* fall through */
        case 0x60000:                            /* OUT transfer complete */
            REG(otg, 0xB10 + ep * 0x20) = *(uint32_t *)((char *)usbp + 0xF0 + ep * 4);
            REG(otg, 0xB00 + ep * 0x20) |=
                (*(uint8_t *)((char *)usbp + 0xEC + ep) == 0) ? 0x84000000u : 0x88000000u;
            return;

        case 0x40000:                            /* OUT data packet received */
            DHW(usbp, 0x100) = (uint16_t)((grxstsp >> 4) & 0x7FF);   /* BCNT */
            if (ops[ep].out_cb)
                ops[ep].out_cb(usbp, ep);
            break;

        case 0xC0000:                            /* SETUP data packet received */
            if (REG(otg, 0x910 + ep * 0x20) & 0x80000)
                sub_8001440(ctrl, ep);
            DHW(usbp, 0x100) = (uint16_t)((grxstsp >> 4) & 0x7FF);   /* BCNT */
            sub_8001770(usbp, ep, (char *)usbp + 0x30, 8);
            break;

        default:
            return;
        }

        /* drain the remaining bytes of the packet from the data FIFO */
        {
            uint16_t cnt = DHW(usbp, 0x100);
            if (cnt) {
                int i = 0;
                do {
                    i += 4;
                    (void)REG(otg, 0x1000);
                } while (i < (int)cnt);
            }
            DHW(usbp, 0x100) = 0;
        }
    }

    /* ---- USBSUSP : suspend ---- */
    if (gintsts & 0x800) {
        void (*suspend_cb)(void) = *(void (**)(void))((char *)usbp + 0x20);
        if (suspend_cb)
            suspend_cb();
        ctrl = *(void **)((char *)usbp + 0xDC);
        otg = dwc_poll(ctrl);
        REG(otg, 0x14) = 0x800;                  /* clear USBSUSP */
    }

    /* ---- WKUPINT : resume / wakeup ---- */
    if ((int32_t)gintsts < 0) {
        void (*wakeup_cb)(void) = *(void (**)(void))((char *)usbp + 0x24);
        if (wakeup_cb)
            wakeup_cb();
        ctrl = *(void **)((char *)usbp + 0xDC);
        otg = dwc_poll(ctrl);
        REG(otg, 0x14) = 0x80000000;             /* clear WKUPINT */
    }

    /* ---- SOF : (re)configure and service start-of-frame ---- */
    {
        void (*sof_cb)(void) = *(void (**)(void))((char *)usbp + 0x28);

        if (gintsts & 8) {                       /* SOF pending in GINTSTS */
            if (sof_cb) {
                sof_cb();
                ctrl = *(void **)((char *)usbp + 0xDC);
                otg = dwc_poll(ctrl);
                REG(otg, 0x14) = 8;              /* clear SOF */
                REG(otg, 0x18) |= 8;             /* enable SOF interrupt */
            } else {
                otg = dwc_poll(*(void **)((char *)usbp + 0xDC));
                REG(otg, 0x14) = 8;              /* clear SOF */
                REG(otg, 0x18) &= ~8u;           /* disable SOF interrupt */
            }
        } else {
            otg = dwc_poll(*(void **)((char *)usbp + 0xDC));
            if (sof_cb)
                REG(otg, 0x18) |= 8;             /* enable SOF interrupt */
            else
                REG(otg, 0x18) &= ~8u;           /* disable SOF interrupt */
        }
    }
}


