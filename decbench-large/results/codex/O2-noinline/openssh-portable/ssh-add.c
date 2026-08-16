// Function: revoked_certs_generate @ 0x3dd20
#include <stddef.h>
#include <stdint.h>

struct sshbuf;
struct sshkey;
struct bitmap;

struct revoked_serial {
	uint64_t lo;
	uint64_t hi;
	struct revoked_serial *left;
	struct revoked_serial *right;
	struct revoked_serial *parent;
};

struct revoked_key_id {
	char *key_id;
	struct revoked_key_id *left;
	struct revoked_key_id *right;
	struct revoked_key_id *parent;
};

struct revoked_certs {
	struct sshkey *ca_key;
	struct revoked_serial *revoked_serials;
	struct revoked_key_id *revoked_key_ids;
};

extern struct sshbuf *sshbuf_new(void);
extern void sshbuf_free(struct sshbuf *);
extern void sshbuf_reset(struct sshbuf *);
extern size_t sshbuf_len(const struct sshbuf *);
extern int sshbuf_put_string(struct sshbuf *, const void *, size_t);
extern int sshbuf_put_stringb(struct sshbuf *, const struct sshbuf *);
extern int sshbuf_put_u8(struct sshbuf *, uint8_t);
extern int sshbuf_put_u64(struct sshbuf *, uint64_t);
extern int sshbuf_put_cstring(struct sshbuf *, const char *);
extern int sshkey_puts(const struct sshkey *, struct sshbuf *);
extern struct revoked_serial *revoked_serial_min(struct revoked_serial *);
extern struct revoked_serial *revoked_serial_next(struct revoked_serial *);
extern struct revoked_key_id *revoked_key_id_min(struct revoked_key_id *);
extern struct revoked_key_id *revoked_key_id_next(struct revoked_key_id *);
extern int choose_next_state(int, uint64_t, int, uint64_t, uint64_t, int *);
extern struct bitmap *bitmap_new(void);
extern void bitmap_free(struct bitmap *);
extern int bitmap_set_bit(struct bitmap *, unsigned int);
extern int sshbuf_put_bitmap(struct sshbuf *, const struct bitmap *);
extern void sshlog(const char *, const char *, int, int, int,
    const char *, const char *, ...);

int
revoked_certs_generate(struct revoked_certs *rc, struct sshbuf *buf)
{
	enum {
		KRL_SECTION_CERT_SERIAL_LIST = 0x20,
		KRL_SECTION_CERT_SERIAL_RANGE = 0x21,
		KRL_SECTION_CERT_SERIAL_BITMAP = 0x22,
		KRL_SECTION_CERT_KEY_ID = 0x23
	};
	struct revoked_serial *rs, *nrs;
	struct revoked_key_id *rki;
	struct sshbuf *sect;
	struct bitmap *bitmap = NULL;
	uint64_t bitmap_start = 0, last_serial = 0;
	uint64_t contig, next_gap, i;
	int r, state = 0, next_state, force_new_sect;

	if ((sect = sshbuf_new()) == NULL)
		return -2;
	if (rc->ca_key == NULL) {
		if ((r = sshbuf_put_string(buf, NULL, 0)) != 0)
			goto out;
	} else if ((r = sshkey_puts(rc->ca_key, buf)) != 0) {
		goto out;
	}
	if ((r = sshbuf_put_string(buf, NULL, 0)) != 0)
		goto out;

	for (rs = revoked_serial_min(rc->revoked_serials); rs != NULL;
	    rs = nrs) {
		nrs = revoked_serial_next(rs);
		contig = rs->hi - rs->lo + 1;
		next_gap = nrs == NULL ? 0 : nrs->lo - rs->hi;
		next_state = choose_next_state(state, contig, nrs == NULL,
		    state == 0 ? 0 : rs->lo - last_serial, next_gap,
		    &force_new_sect);

		if (state != 0 && (force_new_sect || state != next_state ||
		    state == KRL_SECTION_CERT_SERIAL_RANGE)) {
			if (state == KRL_SECTION_CERT_SERIAL_BITMAP) {
				if ((r = sshbuf_put_bitmap(sect, bitmap)) != 0)
					goto out;
				bitmap_free(bitmap);
				bitmap = NULL;
			}
			if ((r = sshbuf_put_u8(buf, (uint8_t)state)) != 0 ||
			    (r = sshbuf_put_stringb(buf, sect)) != 0)
				goto out;
			sshbuf_reset(sect);
		}

		if (state != next_state || force_new_sect) {
			sshbuf_reset(sect);
			state = next_state;
			if (state == KRL_SECTION_CERT_SERIAL_BITMAP) {
				if ((bitmap = bitmap_new()) == NULL) {
					r = -2;
					goto out;
				}
				bitmap_start = rs->lo;
				if ((r = sshbuf_put_u64(sect, bitmap_start)) != 0)
					goto out;
			}
		}

		switch (state) {
		case KRL_SECTION_CERT_SERIAL_LIST:
			for (i = 0; i < contig; i++) {
				if ((r = sshbuf_put_u64(sect, rs->lo + i)) != 0)
					goto out;
			}
			break;
		case KRL_SECTION_CERT_SERIAL_RANGE:
			if ((r = sshbuf_put_u64(sect, rs->lo)) != 0 ||
			    (r = sshbuf_put_u64(sect, rs->hi)) != 0)
				goto out;
			break;
		case KRL_SECTION_CERT_SERIAL_BITMAP:
			if (rs->lo - bitmap_start >= UINT64_C(0x80000000)) {
				sshlog("krl.c", "revoked_certs_generate", 677, 1,
				    2, NULL, "insane bitmap gap");
				goto out;
			}
			for (i = 0; i < contig; i++) {
				if (bitmap_set_bit(bitmap,
				    (unsigned int)(rs->lo - bitmap_start + i)) != 0) {
					r = -2;
					goto out;
				}
			}
			break;
		}
		last_serial = rs->hi;
	}

	if (state != 0) {
		if (state == KRL_SECTION_CERT_SERIAL_BITMAP) {
			if ((r = sshbuf_put_bitmap(sect, bitmap)) != 0)
				goto out;
			bitmap_free(bitmap);
			bitmap = NULL;
		}
		if ((r = sshbuf_put_u8(buf, (uint8_t)state)) != 0 ||
		    (r = sshbuf_put_stringb(buf, sect)) != 0)
			goto out;
	}
	sshbuf_reset(sect);

	for (rki = revoked_key_id_min(rc->revoked_key_ids); rki != NULL;
	    rki = revoked_key_id_next(rki)) {
		if ((r = sshbuf_put_cstring(sect, rki->key_id)) != 0)
			goto out;
	}
	if (sshbuf_len(sect) != 0) {
		if ((r = sshbuf_put_u8(buf, KRL_SECTION_CERT_KEY_ID)) != 0 ||
		    (r = sshbuf_put_stringb(buf, sect)) != 0)
			goto out;
	}

out:
	bitmap_free(bitmap);
	sshbuf_free(sect);
	return r;
}


