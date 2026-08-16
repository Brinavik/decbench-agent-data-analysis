// Function: revoked_certs_generate @ 0x3dd20
#include <sys/types.h>
#include <sys/queue.h>
#include <sys/tree.h>
#include <limits.h>
#include <stdlib.h>

#define SSH_ERR_INTERNAL_ERROR		-1
#define SSH_ERR_ALLOC_FAIL		-2

/* KRL section types (see PROTOCOL.krl) */
#define KRL_SECTION_CERT_SERIAL_LIST	0x20
#define KRL_SECTION_CERT_SERIAL_RANGE	0x21
#define KRL_SECTION_CERT_SERIAL_BITMAP	0x22
#define KRL_SECTION_CERT_KEY_ID		0x23

struct sshkey;
struct sshbuf;
struct bitmap;

/* A run of revoked serial numbers [lo, hi] */
struct revoked_serial {
	u_int64_t lo, hi;
	RB_ENTRY(revoked_serial) tree_entry;
};
static int serial_cmp(struct revoked_serial *a, struct revoked_serial *b);
RB_HEAD(revoked_serial_tree, revoked_serial);
RB_PROTOTYPE(revoked_serial_tree, revoked_serial, tree_entry, serial_cmp)

/* A revoked certificate key ID */
struct revoked_key_id {
	char *key_id;
	RB_ENTRY(revoked_key_id) tree_entry;
};
static int key_id_cmp(struct revoked_key_id *a, struct revoked_key_id *b);
RB_HEAD(revoked_key_id_tree, revoked_key_id);
RB_PROTOTYPE(revoked_key_id_tree, revoked_key_id, tree_entry, key_id_cmp)

/* Revocations that apply to certificates issued by a particular CA */
struct revoked_certs {
	struct sshkey *ca_key;
	struct revoked_serial_tree revoked_serials;
	struct revoked_key_id_tree revoked_key_ids;
	TAILQ_ENTRY(revoked_certs) entry;
};

extern struct sshbuf *sshbuf_new(void);
extern void sshbuf_free(struct sshbuf *buf);
extern void sshbuf_reset(struct sshbuf *buf);
extern size_t sshbuf_len(const struct sshbuf *buf);
extern int sshbuf_put_u8(struct sshbuf *buf, u_char val);
extern int sshbuf_put_u64(struct sshbuf *buf, u_int64_t val);
extern int sshbuf_put_string(struct sshbuf *buf, const void *v, size_t len);
extern int sshbuf_put_cstring(struct sshbuf *buf, const char *s);
extern int sshbuf_put_stringb(struct sshbuf *buf, const struct sshbuf *v);
extern int sshkey_puts(const struct sshkey *key, struct sshbuf *b);

extern struct bitmap *bitmap_new(void);
extern void bitmap_free(struct bitmap *b);
extern int bitmap_set_bit(struct bitmap *b, u_int n);

extern void fatal_f(const char *fmt, ...);

/* Local helpers from krl.c */
static int put_bitmap(struct sshbuf *buf, struct bitmap *b);
static int choose_next_state(int current_state, u_int64_t contig, int final,
    u_int64_t last_gap, u_int64_t next_gap, int *force_new_sect);

/* Generate the body of a KRL_SECTION_CERTIFICATES section for one CA scope */
static int
revoked_certs_generate(struct revoked_certs *rc, struct sshbuf *buf)
{
	int final, force_new_sect, r = SSH_ERR_INTERNAL_ERROR;
	u_int64_t i, contig, gap, last = 0, bitmap_start = 0, bitmap_index;
	struct revoked_serial *rs, *nrs;
	struct revoked_key_id *rki;
	struct sshbuf *sect;
	struct bitmap *bitmap = NULL;
	int next_state, state = 0;

	if ((sect = sshbuf_new()) == NULL)
		return SSH_ERR_ALLOC_FAIL;

	/* Store the header: optional CA scope key, reserved */
	if (rc->ca_key == NULL) {
		if ((r = sshbuf_put_string(buf, NULL, 0)) != 0)
			goto out;
	} else {
		if ((r = sshkey_puts(rc->ca_key, buf)) != 0)
			goto out;
	}
	if ((r = sshbuf_put_string(buf, NULL, 0)) != 0)
		goto out;

	/*
	 * Now walk the revoked serials, encoding each contiguous run as the
	 * most space-efficient of a list, a range or a bitmap.  A little
	 * state machine (driven by choose_next_state) decides which section
	 * type to use and when to flush the current section to the output.
	 */
	for (rs = RB_MIN(revoked_serial_tree, &rc->revoked_serials);
	    rs != NULL;
	    rs = RB_NEXT(revoked_serial_tree, &rc->revoked_serials, rs)) {
		nrs = RB_NEXT(revoked_serial_tree, &rc->revoked_serials, rs);
		final = nrs == NULL;
		gap = final ? 0 : nrs->lo - rs->hi;
		contig = 1 + rs->hi - rs->lo;

		next_state = choose_next_state(state, contig, final,
		    state == 0 ? 0 : rs->lo - last, gap, &force_new_sect);

		/*
		 * If we are already in a section but need to change type, or
		 * choose_next_state has requested a fresh section (or we are
		 * mid-range, which is always emitted one run at a time),
		 * then finish and flush the current section.
		 */
		if (state != 0 && (force_new_sect || next_state != state ||
		    state == KRL_SECTION_CERT_SERIAL_RANGE)) {
			if (state == KRL_SECTION_CERT_SERIAL_BITMAP) {
				if ((r = put_bitmap(sect, bitmap)) != 0)
					goto out;
				bitmap_free(bitmap);
				bitmap = NULL;
			}
			if ((r = sshbuf_put_u8(buf, state)) != 0 ||
			    (r = sshbuf_put_stringb(buf, sect)) != 0)
				goto out;
			sshbuf_reset(sect);
			state = 0;
		}

		/* Starting a new section; set it up */
		if (state == 0) {
			state = next_state;
			if (state == KRL_SECTION_CERT_SERIAL_BITMAP) {
				if ((bitmap = bitmap_new()) == NULL) {
					r = SSH_ERR_ALLOC_FAIL;
					goto out;
				}
				bitmap_start = rs->lo;
				if ((r = sshbuf_put_u64(sect,
				    bitmap_start)) != 0)
					goto out;
			}
		}

		/* Append this run of serials to the current section */
		switch (state) {
		case KRL_SECTION_CERT_SERIAL_LIST:
			for (i = 0; i < contig; i++) {
				if ((r = sshbuf_put_u64(sect,
				    rs->lo + i)) != 0)
					goto out;
			}
			break;
		case KRL_SECTION_CERT_SERIAL_RANGE:
			if ((r = sshbuf_put_u64(sect, rs->lo)) != 0 ||
			    (r = sshbuf_put_u64(sect, rs->hi)) != 0)
				goto out;
			break;
		case KRL_SECTION_CERT_SERIAL_BITMAP:
			bitmap_index = rs->lo - bitmap_start;
			if (bitmap_index > INT_MAX)
				fatal_f("insane bitmap gap");
			for (i = 0; i < contig; i++) {
				if (bitmap_set_bit(bitmap,
				    bitmap_index + i) != 0) {
					r = SSH_ERR_ALLOC_FAIL;
					goto out;
				}
			}
			break;
		}
		last = rs->hi;
	}

	/* Flush the final serial section, if one is in progress */
	if (state != 0) {
		if (state == KRL_SECTION_CERT_SERIAL_BITMAP) {
			if ((r = put_bitmap(sect, bitmap)) != 0)
				goto out;
			bitmap_free(bitmap);
			bitmap = NULL;
		}
		if ((r = sshbuf_put_u8(buf, state)) != 0 ||
		    (r = sshbuf_put_stringb(buf, sect)) != 0)
			goto out;
	}

	/* Now a section for the revoked key IDs */
	sshbuf_reset(sect);
	for (rki = RB_MIN(revoked_key_id_tree, &rc->revoked_key_ids);
	    rki != NULL;
	    rki = RB_NEXT(revoked_key_id_tree, &rc->revoked_key_ids, rki)) {
		if ((r = sshbuf_put_cstring(sect, rki->key_id)) != 0)
			goto out;
	}
	if (sshbuf_len(sect) != 0) {
		if ((r = sshbuf_put_u8(buf, KRL_SECTION_CERT_KEY_ID)) != 0 ||
		    (r = sshbuf_put_stringb(buf, sect)) != 0)
			goto out;
	}
	/* Success */
	r = 0;
 out:
	bitmap_free(bitmap);
	sshbuf_free(sect);
	return r;
}


