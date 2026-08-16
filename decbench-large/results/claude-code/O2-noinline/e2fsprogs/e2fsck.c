// Function: check_ea_in_inode @ 0x1f800
#include <stdint.h>

typedef uint8_t  __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;
typedef long     errcode_t;
typedef __u32    ext2_ino_t;
typedef __u32    blk_t;
typedef __u64    blk64_t;
typedef __u32    problem_t;

/* --- opaque / minimal on-disk and in-core structures --- */

struct region_struct;
typedef struct region_struct *region_t;

struct ext2_super_block {
	__u8	reserved_0[0x4c];
	__u32	s_rev_level;		/* 0x4c */
	__u8	reserved_50[0x58 - 0x50];
	__u16	s_inode_size;		/* 0x58 */
};

struct ext2_filsys {
	__u8	reserved_0[0x20];
	struct ext2_super_block *super;	/* 0x20 */
};

struct e2fsck_struct {
	struct ext2_filsys *fs;		/* 0x00 */
	__u8	reserved_8[0x48 - 0x08];
	__u32	flags;			/* 0x48 */
};
typedef struct e2fsck_struct *e2fsck_t;

struct ext2_inode;

struct ext2_inode_large {
	__u8	reserved_0[0x80];
	__u16	i_extra_isize;		/* 0x80 */
};

struct problem_context {
	errcode_t	errcode;	/* 0x00 */
	ext2_ino_t	ino, ino2, dir;	/* 0x08, 0x0c, 0x10 */
	struct ext2_inode *inode;	/* 0x18 */
	__u8		reserved_20[0x50 - 0x20];
	__u64		num;		/* 0x50 */
};

struct ext2_ext_attr_entry {
	__u8	e_name_len;		/* 0x00 */
	__u8	e_name_index;		/* 0x01 */
	__u16	e_value_offs;		/* 0x02 */
	__u32	e_value_inum;		/* 0x04 */
	__u32	e_value_size;		/* 0x08 */
	__u32	e_hash;			/* 0x0c */
	char	e_name[0];		/* 0x10 */
};

struct ea_quota {
	blk64_t	blocks;			/* 0x00 */
	__u64	inodes;			/* 0x08 */
};

/* --- constants / macros --- */

#define EXT2_GOOD_OLD_REV		0
#define EXT2_GOOD_OLD_INODE_SIZE	128
#define E2F_FLAG_ABORT			0x1

#define EXT2_INODE_SIZE(s) \
	(((s)->s_rev_level == EXT2_GOOD_OLD_REV) ? \
	 EXT2_GOOD_OLD_INODE_SIZE : (s)->s_inode_size)

#define EXT2_EXT_ATTR_PAD		4
#define EXT2_EXT_ATTR_ROUND		(EXT2_EXT_ATTR_PAD - 1)
#define EXT2_EXT_ATTR_SIZE(size) \
	(((size) + EXT2_EXT_ATTR_ROUND) & ~EXT2_EXT_ATTR_ROUND)
#define EXT2_EXT_ATTR_LEN(name_len) \
	(((name_len) + EXT2_EXT_ATTR_ROUND + \
	  sizeof(struct ext2_ext_attr_entry)) & ~EXT2_EXT_ATTR_ROUND)
#define EXT2_EXT_ATTR_NEXT(entry) \
	((struct ext2_ext_attr_entry *)((char *)(entry) + \
	 EXT2_EXT_ATTR_LEN((entry)->e_name_len)))
#define EXT2_EXT_IS_LAST_ENTRY(entry)	(*((__u32 *)(entry)) == 0)

/* problem codes (values observed in the binary) */
#define PR_1_INODE_ALLOC_REGION_FAILED	0x1003f
#define PR_1_INODE_EA_ALLOC_COLLISION	0x10069
#define PR_1_ATTR_NAME_LEN		0x10050
#define PR_1_ATTR_VALUE_SIZE		0x10053
#define PR_1_ATTR_HASH			0x10054

/* --- external helpers --- */

extern region_t region_create(blk_t start, blk_t end);
extern void region_free(region_t region);
extern int region_allocate(region_t region, blk_t start, int n);
extern __u32 ext2fs_ext_attr_hash_entry(struct ext2_ext_attr_entry *entry,
					void *data);
extern int fix_problem(e2fsck_t ctx, problem_t pr,
		       struct problem_context *pctx);
extern errcode_t e2fsck_write_inode_full(e2fsck_t ctx, ext2_ino_t ino,
					 struct ext2_inode *inode,
					 int bufsize, const char *proc);
extern int check_ea_inode(e2fsck_t ctx, struct ext2_ext_attr_entry *entry,
			  struct problem_context *pctx,
			  struct ea_quota *ea_ibody_quota);
extern int check_ext_attr_ibody(e2fsck_t ctx, struct problem_context *pctx,
				char *start, char *end);

static int check_ea_in_inode(e2fsck_t ctx, struct problem_context *pctx,
		     struct ea_quota *ea_ibody_quota)
{
	struct ext2_super_block *sb = ctx->fs->super;
	struct ext2_inode_large *inode;
	struct ext2_ext_attr_entry *entry;
	char *start, *header, *end;
	unsigned int storage_size, remain;
	problem_t problem = 0;
	region_t region;

	ea_ibody_quota->blocks = 0;
	ea_ibody_quota->inodes = 0;

	inode = (struct ext2_inode_large *) pctx->inode;
	storage_size = EXT2_INODE_SIZE(sb) - EXT2_GOOD_OLD_INODE_SIZE -
		inode->i_extra_isize;
	header = ((char *) inode) + EXT2_GOOD_OLD_INODE_SIZE +
		inode->i_extra_isize;
	start = header + sizeof(__u32);
	end = header + storage_size;
	entry = (struct ext2_ext_attr_entry *) start;

	/* scan all entry headers into a region to detect overlaps */
	region = region_create(0, storage_size);
	if (!region) {
		fix_problem(ctx, PR_1_INODE_ALLOC_REGION_FAILED, pctx);
		ctx->flags |= E2F_FLAG_ABORT;
		return 0;
	}

	/* the EA magic occupies the first __u32 */
	if (region_allocate(region, 0, sizeof(__u32))) {
		problem = PR_1_INODE_EA_ALLOC_COLLISION;
		goto fix;
	}

	remain = storage_size - sizeof(__u32);

	while (remain > sizeof(struct ext2_ext_attr_entry) - 1) {
		if (EXT2_EXT_IS_LAST_ENTRY(entry))
			break;

		if (region_allocate(region, (char *) entry - header,
				    EXT2_EXT_ATTR_LEN(entry->e_name_len))) {
			problem = PR_1_INODE_EA_ALLOC_COLLISION;
			goto fix;
		}

		/* the entry header eats this space */
		remain -= sizeof(struct ext2_ext_attr_entry);

		/* is the attribute name length sane? */
		if (EXT2_EXT_ATTR_SIZE(entry->e_name_len) > remain) {
			pctx->num = entry->e_name_len;
			problem = PR_1_ATTR_NAME_LEN;
			goto fix;
		}

		/* the attribute name eats this space */
		remain -= EXT2_EXT_ATTR_SIZE(entry->e_name_len);

		if (entry->e_value_inum) {
			struct ea_quota ea_ibody_val_quota;
			int ret;

			ret = check_ea_inode(ctx, entry, pctx,
					     &ea_ibody_val_quota);
			if (ret) {
				problem = ret;
				goto fix;
			}
			ea_ibody_quota->blocks += ea_ibody_val_quota.blocks;
			ea_ibody_quota->inodes += 1;
		} else {
			__u32 hash;

			/* is the value size sane? */
			if (entry->e_value_size > remain) {
				pctx->num = entry->e_value_size;
				problem = PR_1_ATTR_VALUE_SIZE;
				goto fix;
			}

			if (entry->e_value_size &&
			    region_allocate(region,
					    sizeof(__u32) + entry->e_value_offs,
					    EXT2_EXT_ATTR_SIZE(entry->e_value_size))) {
				problem = PR_1_INODE_EA_ALLOC_COLLISION;
				goto fix;
			}

			hash = ext2fs_ext_attr_hash_entry(entry,
							  start + entry->e_value_offs);

			/* e_hash may legitimately be 0 in old inodes */
			if (entry->e_hash != 0 && entry->e_hash != hash) {
				pctx->num = entry->e_hash;
				problem = PR_1_ATTR_HASH;
				goto fix;
			}

			/* the value eats this space */
			remain -= entry->e_value_size;
		}

		entry = EXT2_EXT_ATTR_NEXT(entry);
	}

	/* the terminating (last) entry */
	if (region_allocate(region, (char *) entry - header, sizeof(__u32))) {
		problem = PR_1_INODE_EA_ALLOC_COLLISION;
		goto fix;
	}

	region_free(region);
	return check_ext_attr_ibody(ctx, pctx, start, end);

fix:
	region_free(region);
	if (fix_problem(ctx, problem, pctx)) {
		/* clear the in-inode extended attributes */
		*((__u32 *) header) = 0;
		e2fsck_write_inode_full(ctx, pctx->ino, pctx->inode,
					EXT2_INODE_SIZE(sb), "pass1");
		ea_ibody_quota->blocks = 0;
		ea_ibody_quota->inodes = 0;
		return 0;
	}
	return check_ext_attr_ibody(ctx, pctx, start, end);
}


