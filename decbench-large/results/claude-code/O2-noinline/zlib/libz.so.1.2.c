// Function: deflate_slow @ 0x4950
/* Reconstruction of the function at virtual address 0x4950.
 * It is zlib's deflate_slow(): the "slow" (lazy-matching) deflate strategy. */

typedef unsigned char  uch, Byte, Bytef, uchf;
typedef unsigned short ush, ushf, Pos, Posf;
typedef unsigned int   uInt, IPos;
typedef unsigned long  ulg, uLong;

/* ---- limits and codes (from zlib deflate.h / trees.h) -------------------- */
#define MIN_MATCH      3
#define MAX_MATCH      258
#define MIN_LOOKAHEAD  (MAX_MATCH + MIN_MATCH + 1)   /* 262 */
#define MAX_DIST(s)    ((s)->w_size - MIN_LOOKAHEAD)
#define TOO_FAR        4096
#define NIL            0

#define LENGTH_CODES   29
#define LITERALS       256
#define L_CODES        (LITERALS + 1 + LENGTH_CODES)  /* 286 */
#define D_CODES        30
#define BL_CODES       19
#define HEAP_SIZE      (2 * L_CODES + 1)              /* 573 */
#define MAX_BITS       15

/* flush values and strategies (from zlib.h) */
#define Z_NO_FLUSH     0
#define Z_FINISH       4
#define Z_FILTERED     1

typedef enum {
    need_more,      /* block not completed, need more input or more output */
    block_done,     /* block flush performed */
    finish_started, /* finish started, need only more output at next deflate */
    finish_done     /* finish done, accept no more input or output */
} block_state;

/* ---- supporting types --------------------------------------------------- */
typedef struct ct_data_s {
    union { ush freq; ush code; } fc;
    union { ush dad;  ush len;  } dl;
} ct_data;
#define Freq fc.freq

typedef struct tree_desc_s {
    ct_data                    *dyn_tree;
    int                         max_code;
    const struct static_tree_desc_s *stat_desc;
} tree_desc;

typedef struct z_stream_s {
    Bytef  *next_in;
    uInt    avail_in;
    uLong   total_in;
    Bytef  *next_out;
    uInt    avail_out;
    uLong   total_out;
    const char *msg;
    struct internal_state *state;
    void  *zalloc;
    void  *zfree;
    void  *opaque;
    int     data_type;
    uLong   adler;
    uLong   reserved;
} z_stream, *z_streamp;

typedef struct internal_state {
    z_streamp strm;
    int       status;
    Bytef    *pending_buf;
    ulg       pending_buf_size;
    Bytef    *pending_out;
    ulg       pending;
    int       wrap;
    void     *gzhead;
    ulg       gzindex;
    Byte      method;
    int       last_flush;

    uInt      w_size;
    uInt      w_bits;
    uInt      w_mask;
    Bytef    *window;
    ulg       window_size;
    Posf     *prev;
    Posf     *head;
    uInt      ins_h;
    uInt      hash_size;
    uInt      hash_bits;
    uInt      hash_mask;
    uInt      hash_shift;
    long      block_start;
    uInt      match_length;
    IPos      prev_match;
    int       match_available;
    uInt      strstart;
    uInt      match_start;
    uInt      lookahead;
    uInt      prev_length;
    uInt      max_chain_length;
    uInt      max_lazy_match;
    int       level;
    int       strategy;
    uInt      good_match;
    int       nice_match;

    struct ct_data_s dyn_ltree[HEAP_SIZE];
    struct ct_data_s dyn_dtree[2 * D_CODES + 1];
    struct ct_data_s bl_tree[2 * BL_CODES + 1];
    struct tree_desc_s l_desc;
    struct tree_desc_s d_desc;
    struct tree_desc_s bl_desc;
    ush       bl_count[MAX_BITS + 1];
    int       heap[2 * L_CODES + 1];
    int       heap_len;
    int       heap_max;
    uch       depth[2 * L_CODES + 1];
    uchf     *sym_buf;
    uInt      lit_bufsize;
    uInt      sym_next;
    uInt      sym_end;
    ulg       opt_len;
    ulg       static_len;
    uInt      matches;
    uInt      insert;
    ush       bi_buf;
    int       bi_valid;
    ulg       high_water;
} deflate_state;

/* ---- external routines and tables --------------------------------------- */
extern void  fill_window(deflate_state *s);
extern uInt  longest_match(deflate_state *s, IPos cur_match);
extern void  flush_pending(z_streamp strm);
extern void  _tr_flush_block(deflate_state *s, char *buf, ulg stored_len,
                             int last);

extern const uch _length_code[MAX_MATCH - MIN_MATCH + 1];
extern const uch _dist_code[512];
#define d_code(dist) \
    ((dist) < 256 ? _dist_code[dist] : _dist_code[256 + ((dist) >> 7)])

/* ---- inline helper macros (from deflate.c / trees.h) -------------------- */
#define UPDATE_HASH(s,h,c) \
    (h = (((h) << s->hash_shift) ^ (c)) & s->hash_mask)

#define INSERT_STRING(s, str, match_head) \
   (UPDATE_HASH(s, s->ins_h, s->window[(str) + (MIN_MATCH-1)]), \
    match_head = s->prev[(str) & s->w_mask] = s->head[s->ins_h], \
    s->head[s->ins_h] = (Pos)(str))

#define _tr_tally_lit(s, c, flush) \
  { uch cc = (c); \
    s->sym_buf[s->sym_next++] = 0; \
    s->sym_buf[s->sym_next++] = 0; \
    s->sym_buf[s->sym_next++] = cc; \
    s->dyn_ltree[cc].Freq++; \
    flush = (s->sym_next == s->sym_end); \
  }

#define _tr_tally_dist(s, distance, length, flush) \
  { uch len = (uch)(length); \
    ush dist = (ush)(distance); \
    s->sym_buf[s->sym_next++] = (uch)dist; \
    s->sym_buf[s->sym_next++] = (uch)(dist >> 8); \
    s->sym_buf[s->sym_next++] = len; \
    dist--; \
    s->dyn_ltree[_length_code[len] + LITERALS + 1].Freq++; \
    s->dyn_dtree[d_code(dist)].Freq++; \
    flush = (s->sym_next == s->sym_end); \
  }

#define deflate_slow(s, last) { \
   _tr_flush_block(s, (s->block_start >= 0L ? \
                   (char *)&s->window[(unsigned)s->block_start] : \
                   (char *)0), \
                (ulg)((long)s->strstart - s->block_start), \
                (last)); \
   s->block_start = s->strstart; \
   flush_pending(s->strm); \
}

#define FLUSH_BLOCK(s, last) { \
   deflate_slow(s, last); \
   if (s->strm->avail_out == 0) return (last) ? finish_done : need_more; \
}

#define check_match(s, start, match, length)   /* no-op unless debugging */

/* ---- the target function ------------------------------------------------ */
static block_state deflate_slow(deflate_state *s, int flush)
{
    IPos hash_head;          /* head of hash chain */
    int  bflush;             /* set if current block must be flushed */

    /* Process the input block. */
    for (;;) {
        /* Make sure that we always have enough lookahead, except
         * at the end of the input file. We need MAX_MATCH bytes
         * for the next match, plus MIN_MATCH bytes to insert the
         * string following the next match.
         */
        if (s->lookahead < MIN_LOOKAHEAD) {
            fill_window(s);
            if (s->lookahead < MIN_LOOKAHEAD && flush == Z_NO_FLUSH) {
                return need_more;
            }
            if (s->lookahead == 0) break; /* flush the current block */
        }

        /* Insert the string window[strstart .. strstart+2] in the
         * dictionary, and set hash_head to the head of the hash chain:
         */
        hash_head = NIL;
        if (s->lookahead >= MIN_MATCH) {
            INSERT_STRING(s, s->strstart, hash_head);
        }

        /* Find the longest match, discarding those <= prev_length. */
        s->prev_length = s->match_length, s->prev_match = s->match_start;
        s->match_length = MIN_MATCH - 1;

        if (hash_head != NIL && s->prev_length < s->max_lazy_match &&
            s->strstart - hash_head <= MAX_DIST(s)) {
            /* To simplify the code, we prevent matches with the string
             * of window index 0 (in particular we have to avoid a match
             * of the string with itself at the start of the input file).
             */
            s->match_length = longest_match(s, hash_head);
            /* longest_match() sets match_start */

            if (s->match_length <= 5 && (s->strategy == Z_FILTERED
                || (s->match_length == MIN_MATCH &&
                    s->strstart - s->match_start > TOO_FAR)
                )) {

                /* If prev_match is also MIN_MATCH, match_start is garbage
                 * but we will ignore the current match anyway.
                 */
                s->match_length = MIN_MATCH - 1;
            }
        }
        /* If there was a match at the previous step and the current
         * match is not better, output the previous match:
         */
        if (s->prev_length >= MIN_MATCH && s->match_length <= s->prev_length) {
            uInt max_insert = s->strstart + s->lookahead - MIN_MATCH;
            /* Do not insert strings in hash table beyond this. */

            check_match(s, s->strstart - 1, s->prev_match, s->prev_length);

            _tr_tally_dist(s, s->strstart - 1 - s->prev_match,
                           s->prev_length - MIN_MATCH, bflush);

            /* Insert in hash table all strings up to the end of the match.
             * strstart-1 and strstart are already inserted. If there is not
             * enough lookahead, the last two strings are not inserted in
             * the hash table.
             */
            s->lookahead -= s->prev_length - 1;
            s->prev_length -= 2;
            do {
                if (++s->strstart <= max_insert) {
                    INSERT_STRING(s, s->strstart, hash_head);
                }
            } while (--s->prev_length != 0);
            s->match_available = 0;
            s->match_length = MIN_MATCH - 1;
            s->strstart++;

            if (bflush) FLUSH_BLOCK(s, 0);

        } else if (s->match_available) {
            /* If there was no match at the previous position, output a
             * single literal. If there was a match but the current match
             * is longer, truncate the previous match to a single literal.
             */
            _tr_tally_lit(s, s->window[s->strstart - 1], bflush);
            if (bflush) {
                deflate_slow(s, 0);
            }
            s->strstart++;
            s->lookahead--;
            if (s->strm->avail_out == 0) return need_more;
        } else {
            /* There is no previous match to compare with, wait for
             * the next step to decide.
             */
            s->match_available = 1;
            s->strstart++;
            s->lookahead--;
        }
    }
    if (s->match_available) {
        _tr_tally_lit(s, s->window[s->strstart - 1], bflush);
        s->match_available = 0;
    }
    s->insert = s->strstart < MIN_MATCH - 1 ? s->strstart : MIN_MATCH - 1;
    if (flush == Z_FINISH) {
        FLUSH_BLOCK(s, 1);
        return finish_done;
    }
    if (s->sym_next)
        FLUSH_BLOCK(s, 0);
    return block_done;
}


