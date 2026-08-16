// Function: check_ea_in_inode @ 0x1f800
#include <stdint.h>

struct ext2_super_block_view {
    uint8_t pad_00[0x4c];
    uint32_t s_rev_level;
    uint8_t pad_50[8];
    uint16_t s_inode_size;
};

struct ext2_filsys_view {
    uint8_t pad_00[0x20];
    struct ext2_super_block_view *super;
};

struct e2fsck_struct_view {
    struct ext2_filsys_view *fs;
    uint8_t pad_08[0x40];
    uint32_t flags;
};

typedef struct e2fsck_struct_view *e2fsck_t;

struct ext2_inode_large_view {
    uint8_t pad_00[0x80];
    uint16_t i_extra_isize;
};

struct problem_context {
    uint64_t errcode;
    uint32_t ino;
    uint32_t ino2;
    uint32_t dir;
    uint32_t pad_14;
    struct ext2_inode_large_view *inode;
    void *dirent;
    uint64_t blk;
    uint64_t blk2;
    int64_t blkcount;
    uint32_t group;
    uint32_t csum1;
    uint32_t csum2;
    uint32_t pad_4c;
    uint64_t num;
    const char *str;
    uint32_t flags;
};

struct ea_quota {
    uint64_t blocks;
    uint64_t inodes;
};

struct ext2_ext_attr_ibody_header {
    uint32_t h_magic;
};

struct ext2_ext_attr_entry {
    uint8_t e_name_len;
    uint8_t e_name_index;
    uint16_t e_value_offs;
    uint32_t e_value_inum;
    uint32_t e_value_size;
    uint32_t e_hash;
    char e_name[];
};

void check_ea_in_inode(e2fsck_t ctx, struct problem_context *pctx,
                struct ea_quota *quota)
{
    extern void *region_create(uint64_t, uint64_t);
    extern int region_allocate(void *, uint64_t, int);
    extern void region_free(void *);
    extern uint32_t ext2fs_ext_attr_hash_entry(
        struct ext2_ext_attr_entry *, void *);
    extern uint32_t check_large_ea_inode(
        e2fsck_t, struct ext2_ext_attr_entry *,
        struct problem_context *, uint64_t *);
    extern int fix_problem(e2fsck_t, uint32_t, struct problem_context *);
    extern void e2fsck_write_inode_full(
        e2fsck_t, uint32_t, void *, int, const char *);
    extern void record_ea_inode_refs(
        e2fsck_t, struct problem_context *,
        struct ext2_ext_attr_entry *, void *);

    struct ext2_super_block_view *super = ctx->fs->super;
    struct ext2_inode_large_view *inode = pctx->inode;
    struct ext2_ext_attr_ibody_header *header;
    struct ext2_ext_attr_entry *first_entry;
    struct ext2_ext_attr_entry *entry;
    uint32_t inode_space;
    uint32_t storage_size;
    uint32_t free_space;
    uint32_t problem = 0;
    uint32_t entry_size;
    uint32_t name_size;
    uint32_t hash;
    uint64_t quota_blocks;
    void *region;

    quota->blocks = 0;
    quota->inodes = 0;

    inode_space = super->s_rev_level ? super->s_inode_size - 0x80 : 0;
    storage_size = inode_space - inode->i_extra_isize;
    header = (struct ext2_ext_attr_ibody_header *)
        ((uint8_t *)inode + 0x80 + inode->i_extra_isize);
    first_entry = (struct ext2_ext_attr_entry *)(header + 1);
    entry = first_entry;

    region = region_create(0, storage_size);
    if (region == 0) {
        fix_problem(ctx, 0x1003f, pctx);
        ctx->flags |= 1;
        return;
    }

    if (region_allocate(region, 0, 4) != 0) {
        problem = 0x10069;
    } else {
        free_space = storage_size - 4;

        while (free_space > 15 && *(uint32_t *)entry != 0) {
            entry_size = (entry->e_name_len + 19U) & ~3U;
            if (region_allocate(region,
                                (uint8_t *)entry - (uint8_t *)header,
                                (int)entry_size) != 0) {
                problem = 0x10069;
                break;
            }

            free_space -= 16;
            name_size = (entry->e_name_len + 3U) & ~3U;
            if (name_size > free_space) {
                pctx->num = entry->e_name_len;
                problem = 0x10050;
                break;
            }
            free_space -= name_size;

            if (entry->e_value_inum != 0) {
                problem = check_large_ea_inode(ctx, entry, pctx,
                                                &quota_blocks);
                if (problem != 0)
                    break;
                quota->inodes++;
                quota->blocks += quota_blocks;
            } else {
                if (entry->e_value_size > free_space) {
                    pctx->num = entry->e_value_size;
                    problem = 0x10053;
                    break;
                }

                if (entry->e_value_size != 0 &&
                    region_allocate(region, entry->e_value_offs + 4U,
                                    (int)((entry->e_value_size + 3U) &
                                          ~3U)) != 0) {
                    problem = 0x10069;
                    break;
                }

                hash = ext2fs_ext_attr_hash_entry(
                    entry, (uint8_t *)first_entry + entry->e_value_offs);
                if (entry->e_hash != 0 && entry->e_hash != hash) {
                    pctx->num = entry->e_hash;
                    problem = 0x10054;
                    break;
                }
                free_space -= entry->e_value_size;
            }

            entry = (struct ext2_ext_attr_entry *)
                ((uint8_t *)entry + entry_size);
        }

        if (problem == 0 &&
            region_allocate(region,
                            (uint8_t *)entry - (uint8_t *)header,
                            4) != 0)
            problem = 0x10069;
    }

    region_free(region);

    if (problem != 0 && fix_problem(ctx, problem, pctx)) {
        header->h_magic = 0;
        e2fsck_write_inode_full(ctx, pctx->ino, inode,
                                super->s_rev_level ?
                                    super->s_inode_size : 0x80,
                                "pass1");
        quota->blocks = 0;
        quota->inodes = 0;
        return;
    }

    record_ea_inode_refs(ctx, pctx, first_entry,
                         (uint8_t *)header + storage_size);
}


