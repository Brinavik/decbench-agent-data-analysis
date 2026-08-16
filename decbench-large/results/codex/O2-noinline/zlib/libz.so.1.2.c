// Function: deflate_slow @ 0x4950
#include <stddef.h>

typedef unsigned char Byte;
typedef unsigned char uch;
typedef unsigned short ush;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef unsigned long ulg;
typedef ush Pos;
typedef uInt IPos;

struct internal_state;

typedef struct z_stream_s {
    Byte *next_in;
    uInt avail_in;
    uLong total_in;
    Byte *next_out;
    uInt avail_out;
    uLong total_out;
    char *msg;
    struct internal_state *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    uLong adler;
    uLong reserved;
} z_stream;

typedef struct ct_data_s {
    union {
        ush freq;
        ush code;
    } fc;
    union {
        ush dad;
        ush len;
    } dl;
} ct_data;

struct static_tree_desc_s;

typedef struct tree_desc_s {
    ct_data *dyn_tree;
    int max_code;
    const struct static_tree_desc_s *stat_desc;
} tree_desc;

typedef struct internal_state {
    z_stream *strm;
    int status;
    Byte *pending_buf;
    ulg pending_buf_size;
    Byte *pending_out;
    ulg pending;
    int wrap;
    void *gzhead;
    ulg gzindex;
    Byte method;
    int last_flush;
    uInt w_size;
    uInt w_bits;
    uInt w_mask;
    Byte *window;
    ulg window_size;
    Pos *prev;
    Pos *head;
    uInt ins_h;
    uInt hash_size;
    uInt hash_bits;
    uInt hash_mask;
    uInt hash_shift;
    long block_start;
    uInt match_length;
    IPos prev_match;
    int match_available;
    uInt strstart;
    uInt match_start;
    uInt lookahead;
    uInt prev_length;
    uInt max_chain_length;
    uInt max_lazy_match;
    int level;
    int strategy;
    uInt good_match;
    int nice_match;
    ct_data dyn_ltree[573];
    ct_data dyn_dtree[61];
    ct_data bl_tree[39];
    tree_desc l_desc;
    tree_desc d_desc;
    tree_desc bl_desc;
    ush bl_count[16];
    int heap[573];
    int heap_len;
    int heap_max;
    uch depth[573];
    uch *sym_buf;
    uInt lit_bufsize;
    uInt sym_next;
    uInt sym_end;
    ulg opt_len;
    ulg static_len;
    uInt matches;
    uInt insert;
    ush bi_buf;
    int bi_valid;
    ulg high_water;
} deflate_state;

typedef enum {
    need_more = 0,
    block_done = 1,
    finish_started = 2,
    finish_done = 3
} block_state;

extern const uch _length_code[];
extern const uch _dist_code[];
extern void fill_window(deflate_state *s);
extern uInt longest_match(deflate_state *s, IPos cur_match);
extern void _tr_flush_block(deflate_state *s, char *buf, ulg stored_len,
                            int last);
extern void flush_pending(z_stream *strm);

block_state deflate_slow(deflate_state *s, int flush)
{
    IPos hash_head;
    int bflush;

    for (;;) {
        if (s->lookahead < 262) {
            fill_window(s);
            if (s->lookahead < 262 && flush == 0)
                return need_more;
            if (s->lookahead == 0)
                break;
        }

        hash_head = 0;
        if (s->lookahead >= 3) {
            s->ins_h = ((s->ins_h << s->hash_shift) ^
                        s->window[s->strstart + 2]) & s->hash_mask;
            hash_head = s->head[s->ins_h];
            s->prev[s->strstart & s->w_mask] = hash_head;
            s->head[s->ins_h] = (Pos)s->strstart;
        }

        s->prev_length = s->match_length;
        s->prev_match = s->match_start;
        s->match_length = 2;

        if (hash_head != 0 && s->prev_length < s->max_lazy_match &&
            s->strstart - hash_head <= s->w_size - 262) {
            s->match_length = longest_match(s, hash_head);

            if (s->match_length <= 5 &&
                (s->strategy == 1 ||
                 (s->match_length == 3 &&
                  s->strstart - s->match_start > 4096))) {
                s->match_length = 2;
            }
        }

        if (s->prev_length >= 3 && s->match_length <= s->prev_length) {
            uInt max_insert = s->strstart + s->lookahead - 3;
            ush dist = (ush)(s->strstart - 1 - s->prev_match);
            uch lc = (uch)(s->prev_length - 3);
            uInt code;

            s->sym_buf[s->sym_next++] = (uch)dist;
            s->sym_buf[s->sym_next++] = (uch)(dist >> 8);
            s->sym_buf[s->sym_next++] = lc;
            s->dyn_ltree[_length_code[lc] + 257].fc.freq++;
            dist--;
            code = dist < 256 ? _dist_code[dist]
                              : _dist_code[256 + (dist >> 7)];
            s->dyn_dtree[code].fc.freq++;
            bflush = s->sym_next == s->sym_end;

            s->lookahead -= s->prev_length - 1;
            s->prev_length -= 2;
            do {
                if (++s->strstart <= max_insert) {
                    s->ins_h = ((s->ins_h << s->hash_shift) ^
                                s->window[s->strstart + 2]) & s->hash_mask;
                    hash_head = s->head[s->ins_h];
                    s->prev[s->strstart & s->w_mask] = hash_head;
                    s->head[s->ins_h] = (Pos)s->strstart;
                }
            } while (--s->prev_length != 0);
            s->match_available = 0;
            s->match_length = 2;
            s->strstart++;

            if (bflush) {
                _tr_flush_block(
                    s,
                    s->block_start >= 0
                        ? (char *)&s->window[(uInt)s->block_start]
                        : NULL,
                    (ulg)((long)s->strstart - s->block_start), 0);
                s->block_start = s->strstart;
                flush_pending(s->strm);
                if (s->strm->avail_out == 0)
                    return need_more;
            }
        } else if (s->match_available) {
            uch cc = s->window[s->strstart - 1];

            s->sym_buf[s->sym_next++] = 0;
            s->sym_buf[s->sym_next++] = 0;
            s->sym_buf[s->sym_next++] = cc;
            s->dyn_ltree[cc].fc.freq++;
            bflush = s->sym_next == s->sym_end;

            if (bflush) {
                _tr_flush_block(
                    s,
                    s->block_start >= 0
                        ? (char *)&s->window[(uInt)s->block_start]
                        : NULL,
                    (ulg)((long)s->strstart - s->block_start), 0);
                s->block_start = s->strstart;
                flush_pending(s->strm);
            }
            s->strstart++;
            s->lookahead--;
            if (s->strm->avail_out == 0)
                return need_more;
        } else {
            s->match_available = 1;
            s->strstart++;
            s->lookahead--;
        }
    }

    if (s->match_available) {
        uch cc = s->window[s->strstart - 1];

        s->sym_buf[s->sym_next++] = 0;
        s->sym_buf[s->sym_next++] = 0;
        s->sym_buf[s->sym_next++] = cc;
        s->dyn_ltree[cc].fc.freq++;
        s->match_available = 0;
    }

    s->insert = s->strstart < 2 ? s->strstart : 2;

    if (flush == 4) {
        _tr_flush_block(
            s,
            s->block_start >= 0
                ? (char *)&s->window[(uInt)s->block_start]
                : NULL,
            (ulg)((long)s->strstart - s->block_start), 1);
        s->block_start = s->strstart;
        flush_pending(s->strm);
        return s->strm->avail_out == 0 ? finish_started : finish_done;
    }

    if (s->sym_next != 0) {
        _tr_flush_block(
            s,
            s->block_start >= 0
                ? (char *)&s->window[(uInt)s->block_start]
                : NULL,
            (ulg)((long)s->strstart - s->block_start), 0);
        s->block_start = s->strstart;
        flush_pending(s->strm);
        if (s->strm->avail_out == 0)
            return need_more;
    }

    return block_done;
}


