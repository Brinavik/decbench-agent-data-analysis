
















typedef unsigned char __u8;
typedef __signed__ char __s8;
typedef unsigned short __u16;
typedef __signed__ short __s16;
typedef unsigned int __u32;
typedef __signed__ int __s32;
typedef unsigned long long __u64;
typedef __signed__ long long __s64;

typedef __u16 __le16;
typedef __u32 __le32;
typedef __u64 __le64;
typedef __u16 __be16;
typedef __u32 __be32;
typedef __u64 __be64;
struct ext2_acl_header
{
 __u32 aclh_size;
 __u32 aclh_file_count;
 __u32 aclh_acle_count;
 __u32 aclh_first_acle;
};

struct ext2_acl_entry
{
 __u32 acle_size;
 __u16 acle_perms;
 __u16 acle_type;
 __u16 acle_tag;
 __u16 acle_pad1;
 __u32 acle_next;

};




struct ext2_group_desc
{
 __u32 bg_block_bitmap;
 __u32 bg_inode_bitmap;
 __u32 bg_inode_table;
 __u16 bg_free_blocks_count;
 __u16 bg_free_inodes_count;
 __u16 bg_used_dirs_count;
 __u16 bg_flags;
 __u32 bg_exclude_bitmap_lo;
 __u16 bg_block_bitmap_csum_lo;
 __u16 bg_inode_bitmap_csum_lo;
 __u16 bg_itable_unused;
 __u16 bg_checksum;
};




struct ext4_group_desc
{
 __u32 bg_block_bitmap;
 __u32 bg_inode_bitmap;
 __u32 bg_inode_table;
 __u16 bg_free_blocks_count;
 __u16 bg_free_inodes_count;
 __u16 bg_used_dirs_count;
 __u16 bg_flags;
 __u32 bg_exclude_bitmap_lo;
 __u16 bg_block_bitmap_csum_lo;
 __u16 bg_inode_bitmap_csum_lo;
 __u16 bg_itable_unused;
 __u16 bg_checksum;
 __u32 bg_block_bitmap_hi;
 __u32 bg_inode_bitmap_hi;
 __u32 bg_inode_table_hi;
 __u16 bg_free_blocks_count_hi;
 __u16 bg_free_inodes_count_hi;
 __u16 bg_used_dirs_count_hi;
 __u16 bg_itable_unused_hi;
 __u32 bg_exclude_bitmap_hi;
 __u16 bg_block_bitmap_csum_hi;
 __u16 bg_inode_bitmap_csum_hi;
 __u32 bg_reserved;
};
struct ext2_dx_root_info {
 __u32 reserved_zero;
 __u8 hash_version;
 __u8 info_length;
 __u8 indirect_levels;
 __u8 unused_flags;
};
struct ext2_dx_entry {
 __le32 hash;
 __le32 block;
};

struct ext2_dx_countlimit {
 __le16 limit;
 __le16 count;
};




struct ext2_dx_tail {
 __le32 dt_reserved;
 __le32 dt_checksum;
};
struct ext2_new_group_input {
 __u32 group;
 __u32 block_bitmap;
 __u32 inode_bitmap;
 __u32 inode_table;
 __u32 blocks_count;
 __u16 reserved_blocks;
 __u16 unused;
};

struct ext4_new_group_input {
 __u32 group;
 __u64 block_bitmap;
 __u64 inode_bitmap;
 __u64 inode_table;
 __u32 blocks_count;
 __u16 reserved_blocks;
 __u16 unused;
};
struct ext2_inode {
       __u16 i_mode;
 __u16 i_uid;
 __u32 i_size;
 __u32 i_atime;
 __u32 i_ctime;
       __u32 i_mtime;
 __u32 i_dtime;
 __u16 i_gid;
 __u16 i_links_count;
 __u32 i_blocks;
       __u32 i_flags;
 union {
  struct {
   __u32 l_i_version;
  } linux1;
  struct {
   __u32 h_i_translator;
  } hurd1;
 } osd1;
       __u32 i_block[(((12 + 1) + 1) + 1)];
       __u32 i_generation;
 __u32 i_file_acl;
 __u32 i_size_high;
       __u32 i_faddr;
 union {
  struct {
   __u16 l_i_blocks_hi;
   __u16 l_i_file_acl_high;
   __u16 l_i_uid_high;
   __u16 l_i_gid_high;
   __u16 l_i_checksum_lo;
   __u16 l_i_reserved;
  } linux2;
  struct {
   __u8 h_i_frag;
   __u8 h_i_fsize;
   __u16 h_i_mode_high;
   __u16 h_i_uid_high;
   __u16 h_i_gid_high;
   __u32 h_i_author;
  } hurd2;
 } osd2;
};




struct ext2_inode_large {
       __u16 i_mode;
 __u16 i_uid;
 __u32 i_size;
 __u32 i_atime;
 __u32 i_ctime;
       __u32 i_mtime;
 __u32 i_dtime;
 __u16 i_gid;
 __u16 i_links_count;
 __u32 i_blocks;
       __u32 i_flags;
 union {
  struct {
   __u32 l_i_version;
  } linux1;
  struct {
   __u32 h_i_translator;
  } hurd1;
 } osd1;
       __u32 i_block[(((12 + 1) + 1) + 1)];
       __u32 i_generation;
 __u32 i_file_acl;
 __u32 i_size_high;
       __u32 i_faddr;
 union {
  struct {
   __u16 l_i_blocks_hi;
   __u16 l_i_file_acl_high;
   __u16 l_i_uid_high;
   __u16 l_i_gid_high;
   __u16 l_i_checksum_lo;
   __u16 l_i_reserved;
  } linux2;
  struct {
   __u8 h_i_frag;
   __u8 h_i_fsize;
   __u16 h_i_mode_high;
   __u16 h_i_uid_high;
   __u16 h_i_gid_high;
   __u32 h_i_author;
  } hurd2;
 } osd2;
       __u16 i_extra_isize;
 __u16 i_checksum_hi;
 __u32 i_ctime_extra;
 __u32 i_mtime_extra;
 __u32 i_atime_extra;
       __u32 i_crtime;
 __u32 i_crtime_extra;
 __u32 i_version_hi;
       __u32 i_projid;
};
static inline
struct ext2_inode *EXT2_INODE(struct ext2_inode_large *large_inode)
{
 return (struct ext2_inode *) large_inode;
}
struct ext4_encryption_policy {
  char version;
  char contents_encryption_mode;
  char filenames_encryption_mode;
  char flags;
  char master_key_descriptor[8];
} __attribute__((__packed__));

struct ext4_encryption_key {
        __u32 mode;
        char raw[64];
        __u32 size;
} __attribute__((__packed__));




struct ext2_super_block {
        __u32 s_inodes_count;
 __u32 s_blocks_count;
 __u32 s_r_blocks_count;
 __u32 s_free_blocks_count;
        __u32 s_free_inodes_count;
 __u32 s_first_data_block;
 __u32 s_log_block_size;
 __u32 s_log_cluster_size;
        __u32 s_blocks_per_group;
 __u32 s_clusters_per_group;
 __u32 s_inodes_per_group;
 __u32 s_mtime;
        __u32 s_wtime;
 __u16 s_mnt_count;
 __s16 s_max_mnt_count;
 __u16 s_magic;
 __u16 s_state;
 __u16 s_errors;
 __u16 s_minor_rev_level;
        __u32 s_lastcheck;
 __u32 s_checkinterval;
 __u32 s_creator_os;
 __u32 s_rev_level;
        __u16 s_def_resuid;
 __u16 s_def_resgid;
 __u32 s_first_ino;
 __u16 s_inode_size;
 __u16 s_block_group_nr;
 __u32 s_feature_compat;
        __u32 s_feature_incompat;
 __u32 s_feature_ro_compat;
        __u8 s_uuid[16] __attribute__((__nonstring__));
        __u8 s_volume_name[16] __attribute__((__nonstring__));
        __u8 s_last_mounted[64] __attribute__((__nonstring__));
        __u32 s_algorithm_usage_bitmap;




 __u8 s_prealloc_blocks;
 __u8 s_prealloc_dir_blocks;
 __u16 s_reserved_gdt_blocks;



        __u8 s_journal_uuid[16] __attribute__((__nonstring__));
        __u32 s_journal_inum;
 __u32 s_journal_dev;
 __u32 s_last_orphan;
        __u32 s_hash_seed[4];
        __u8 s_def_hash_version;
 __u8 s_jnl_backup_type;
 __u16 s_desc_size;
        __u32 s_default_mount_opts;
 __u32 s_first_meta_bg;
 __u32 s_mkfs_time;
        __u32 s_jnl_blocks[17];
        __u32 s_blocks_count_hi;
 __u32 s_r_blocks_count_hi;
 __u32 s_free_blocks_hi;
 __u16 s_min_extra_isize;
 __u16 s_want_extra_isize;
        __u32 s_flags;
 __u16 s_raid_stride;
 __u16 s_mmp_update_interval;
 __u64 s_mmp_block;
        __u32 s_raid_stripe_width;
 __u8 s_log_groups_per_flex;
 __u8 s_checksum_type;
 __u8 s_encryption_level;
 __u8 s_reserved_pad;
 __u64 s_kbytes_written;
        __u32 s_snapshot_inum;
 __u32 s_snapshot_id;
 __u64 s_snapshot_r_blocks_count;
        __u32 s_snapshot_list;

 __u32 s_error_count;
 __u32 s_first_error_time;
 __u32 s_first_error_ino;
        __u64 s_first_error_block;
 __u8 s_first_error_func[32] __attribute__((__nonstring__));
        __u32 s_first_error_line;
 __u32 s_last_error_time;
        __u32 s_last_error_ino;
 __u32 s_last_error_line;
 __u64 s_last_error_block;
        __u8 s_last_error_func[32] __attribute__((__nonstring__));

        __u8 s_mount_opts[64] __attribute__((__nonstring__));
        __u32 s_usr_quota_inum;
 __u32 s_grp_quota_inum;
 __u32 s_overhead_clusters;
        __u32 s_backup_bgs[2];
        __u8 s_encrypt_algos[4];
        __u8 s_encrypt_pw_salt[16];
        __le32 s_lpf_ino;
 __le32 s_prj_quota_inum;
        __le32 s_checksum_seed;
        __u8 s_wtime_hi;
 __u8 s_mtime_hi;
 __u8 s_mkfs_time_hi;
 __u8 s_lastcheck_hi;
 __u8 s_first_error_time_hi;
 __u8 s_last_error_time_hi;
 __u8 s_first_error_errcode;
 __u8 s_last_error_errcode;
        __le16 s_encoding;
 __le16 s_encoding_flags;
 __le32 s_reserved[95];
        __u32 s_checksum;
};
static inline int ext2fs_has_feature_dir_prealloc(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0001) != 0); } static inline void ext2fs_set_feature_dir_prealloc(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0001; } static inline void ext2fs_clear_feature_dir_prealloc(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0001; }
static inline int ext2fs_has_feature_imagic_inodes(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0002) != 0); } static inline void ext2fs_set_feature_imagic_inodes(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0002; } static inline void ext2fs_clear_feature_imagic_inodes(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0002; }
static inline int ext2fs_has_feature_journal(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0004) != 0); } static inline void ext2fs_set_feature_journal(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0004; } static inline void ext2fs_clear_feature_journal(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0004; }
static inline int ext2fs_has_feature_xattr(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0008) != 0); } static inline void ext2fs_set_feature_xattr(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0008; } static inline void ext2fs_clear_feature_xattr(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0008; }
static inline int ext2fs_has_feature_resize_inode(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0010) != 0); } static inline void ext2fs_set_feature_resize_inode(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0010; } static inline void ext2fs_clear_feature_resize_inode(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0010; }
static inline int ext2fs_has_feature_dir_index(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0020) != 0); } static inline void ext2fs_set_feature_dir_index(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0020; } static inline void ext2fs_clear_feature_dir_index(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0020; }
static inline int ext2fs_has_feature_lazy_bg(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0040) != 0); } static inline void ext2fs_set_feature_lazy_bg(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0040; } static inline void ext2fs_clear_feature_lazy_bg(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0040; }
static inline int ext2fs_has_feature_exclude_bitmap(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0100) != 0); } static inline void ext2fs_set_feature_exclude_bitmap(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0100; } static inline void ext2fs_clear_feature_exclude_bitmap(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0100; }
static inline int ext2fs_has_feature_sparse_super2(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0200) != 0); } static inline void ext2fs_set_feature_sparse_super2(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0200; } static inline void ext2fs_clear_feature_sparse_super2(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0200; }
static inline int ext2fs_has_feature_fast_commit(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0400) != 0); } static inline void ext2fs_set_feature_fast_commit(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0400; } static inline void ext2fs_clear_feature_fast_commit(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0400; }
static inline int ext2fs_has_feature_stable_inodes(struct ext2_super_block *sb) { return (((sb)->s_feature_compat & 0x0800) != 0); } static inline void ext2fs_set_feature_stable_inodes(struct ext2_super_block *sb) { (sb)->s_feature_compat |= 0x0800; } static inline void ext2fs_clear_feature_stable_inodes(struct ext2_super_block *sb) { (sb)->s_feature_compat &= ~0x0800; }

static inline int ext2fs_has_feature_sparse_super(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0001) != 0); } static inline void ext2fs_set_feature_sparse_super(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0001; } static inline void ext2fs_clear_feature_sparse_super(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0001; }
static inline int ext2fs_has_feature_large_file(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0002) != 0); } static inline void ext2fs_set_feature_large_file(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0002; } static inline void ext2fs_clear_feature_large_file(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0002; }
static inline int ext2fs_has_feature_huge_file(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0008) != 0); } static inline void ext2fs_set_feature_huge_file(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0008; } static inline void ext2fs_clear_feature_huge_file(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0008; }
static inline int ext2fs_has_feature_gdt_csum(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0010) != 0); } static inline void ext2fs_set_feature_gdt_csum(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0010; } static inline void ext2fs_clear_feature_gdt_csum(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0010; }
static inline int ext2fs_has_feature_dir_nlink(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0020) != 0); } static inline void ext2fs_set_feature_dir_nlink(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0020; } static inline void ext2fs_clear_feature_dir_nlink(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0020; }
static inline int ext2fs_has_feature_extra_isize(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0040) != 0); } static inline void ext2fs_set_feature_extra_isize(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0040; } static inline void ext2fs_clear_feature_extra_isize(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0040; }
static inline int ext2fs_has_feature_has_snapshot(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0080) != 0); } static inline void ext2fs_set_feature_has_snapshot(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0080; } static inline void ext2fs_clear_feature_has_snapshot(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0080; }
static inline int ext2fs_has_feature_quota(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0100) != 0); } static inline void ext2fs_set_feature_quota(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0100; } static inline void ext2fs_clear_feature_quota(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0100; }
static inline int ext2fs_has_feature_bigalloc(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0200) != 0); } static inline void ext2fs_set_feature_bigalloc(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0200; } static inline void ext2fs_clear_feature_bigalloc(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0200; }
static inline int ext2fs_has_feature_metadata_csum(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0400) != 0); } static inline void ext2fs_set_feature_metadata_csum(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0400; } static inline void ext2fs_clear_feature_metadata_csum(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0400; }
static inline int ext2fs_has_feature_replica(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x0800) != 0); } static inline void ext2fs_set_feature_replica(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x0800; } static inline void ext2fs_clear_feature_replica(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x0800; }
static inline int ext2fs_has_feature_readonly(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x1000) != 0); } static inline void ext2fs_set_feature_readonly(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x1000; } static inline void ext2fs_clear_feature_readonly(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x1000; }
static inline int ext2fs_has_feature_project(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x2000) != 0); } static inline void ext2fs_set_feature_project(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x2000; } static inline void ext2fs_clear_feature_project(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x2000; }
static inline int ext2fs_has_feature_shared_blocks(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x4000) != 0); } static inline void ext2fs_set_feature_shared_blocks(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x4000; } static inline void ext2fs_clear_feature_shared_blocks(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x4000; }
static inline int ext2fs_has_feature_verity(struct ext2_super_block *sb) { return (((sb)->s_feature_ro_compat & 0x8000) != 0); } static inline void ext2fs_set_feature_verity(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat |= 0x8000; } static inline void ext2fs_clear_feature_verity(struct ext2_super_block *sb) { (sb)->s_feature_ro_compat &= ~0x8000; }

static inline int ext2fs_has_feature_compression(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0001) != 0); } static inline void ext2fs_set_feature_compression(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0001; } static inline void ext2fs_clear_feature_compression(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0001; }
static inline int ext2fs_has_feature_filetype(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0002) != 0); } static inline void ext2fs_set_feature_filetype(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0002; } static inline void ext2fs_clear_feature_filetype(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0002; }
static inline int ext2fs_has_feature_journal_needs_recovery(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0004) != 0); } static inline void ext2fs_set_feature_journal_needs_recovery(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0004; } static inline void ext2fs_clear_feature_journal_needs_recovery(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0004; }
static inline int ext2fs_has_feature_journal_dev(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0008) != 0); } static inline void ext2fs_set_feature_journal_dev(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0008; } static inline void ext2fs_clear_feature_journal_dev(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0008; }
static inline int ext2fs_has_feature_meta_bg(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0010) != 0); } static inline void ext2fs_set_feature_meta_bg(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0010; } static inline void ext2fs_clear_feature_meta_bg(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0010; }
static inline int ext2fs_has_feature_extents(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0040) != 0); } static inline void ext2fs_set_feature_extents(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0040; } static inline void ext2fs_clear_feature_extents(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0040; }
static inline int ext2fs_has_feature_64bit(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0080) != 0); } static inline void ext2fs_set_feature_64bit(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0080; } static inline void ext2fs_clear_feature_64bit(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0080; }
static inline int ext2fs_has_feature_mmp(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0100) != 0); } static inline void ext2fs_set_feature_mmp(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0100; } static inline void ext2fs_clear_feature_mmp(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0100; }
static inline int ext2fs_has_feature_flex_bg(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0200) != 0); } static inline void ext2fs_set_feature_flex_bg(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0200; } static inline void ext2fs_clear_feature_flex_bg(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0200; }
static inline int ext2fs_has_feature_ea_inode(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x0400) != 0); } static inline void ext2fs_set_feature_ea_inode(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x0400; } static inline void ext2fs_clear_feature_ea_inode(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x0400; }
static inline int ext2fs_has_feature_dirdata(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x1000) != 0); } static inline void ext2fs_set_feature_dirdata(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x1000; } static inline void ext2fs_clear_feature_dirdata(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x1000; }
static inline int ext2fs_has_feature_csum_seed(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x2000) != 0); } static inline void ext2fs_set_feature_csum_seed(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x2000; } static inline void ext2fs_clear_feature_csum_seed(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x2000; }
static inline int ext2fs_has_feature_largedir(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x4000) != 0); } static inline void ext2fs_set_feature_largedir(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x4000; } static inline void ext2fs_clear_feature_largedir(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x4000; }
static inline int ext2fs_has_feature_inline_data(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x8000) != 0); } static inline void ext2fs_set_feature_inline_data(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x8000; } static inline void ext2fs_clear_feature_inline_data(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x8000; }
static inline int ext2fs_has_feature_encrypt(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x10000) != 0); } static inline void ext2fs_set_feature_encrypt(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x10000; } static inline void ext2fs_clear_feature_encrypt(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x10000; }
static inline int ext2fs_has_feature_casefold(struct ext2_super_block *sb) { return (((sb)->s_feature_incompat & 0x20000) != 0); } static inline void ext2fs_set_feature_casefold(struct ext2_super_block *sb) { (sb)->s_feature_incompat |= 0x20000; } static inline void ext2fs_clear_feature_casefold(struct ext2_super_block *sb) { (sb)->s_feature_incompat &= ~0x20000; }
static inline int ext4_hash_in_dirent(const struct ext2_inode *inode)
{
 return (inode->i_flags & 0x00000800) &&
  (inode->i_flags & 0x40000000);
}






struct ext2_dir_entry {
 __u32 inode;
 __u16 rec_len;
 __u16 name_len;
 char name[255];
};
struct ext2_dir_entry_2 {
 __u32 inode;
 __u16 rec_len;
 __u8 name_len;
 __u8 file_type;
 char name[255];
};






struct ext2_dir_entry_hash {
 __le32 hash;
 __le32 minor_hash;
};
struct ext2_dir_entry_tail {
 __u32 det_reserved_zero1;
 __u16 det_rec_len;
 __u16 det_reserved_name_len;
 __u32 det_checksum;
};
static inline unsigned int ext2fs_dir_rec_len(__u8 name_len,
      int extended)
{
 int rec_len = (name_len + 8 + (4 - 1));

 rec_len &= ~(4 - 1);
 if (extended)
  rec_len += 8;
 return rec_len;
}
struct mmp_struct {
 __u32 mmp_magic;
 __u32 mmp_seq;
 __u64 mmp_time;
 __u8 mmp_nodename[64] __attribute__((__nonstring__));
 __u8 mmp_bdevname[32] __attribute__((__nonstring__));
 __u16 mmp_check_interval;
 __u16 mmp_pad1;
 __u32 mmp_pad2[226];
 __u32 mmp_checksum;
};

struct ext3_extent_tail {
 __le32 et_checksum;
};





struct ext3_extent {
 __le32 ee_block;
 __le16 ee_len;
 __le16 ee_start_hi;
 __le32 ee_start;
};





struct ext3_extent_idx {
 __le32 ei_block;
 __le32 ei_leaf;

 __le16 ei_leaf_hi;
 __le16 ei_unused;
};




struct ext3_extent_header {
 __le16 eh_magic;
 __le16 eh_entries;
 __le16 eh_max;
 __le16 eh_depth;
 __le32 eh_generation;
};
struct ext3_ext_path {
 __u32 p_block;
 __u16 p_depth;
 struct ext3_extent *p_ext;
 struct ext3_extent_idx *p_idx;
 struct ext3_extent_header *p_hdr;
 struct buffer_head *p_bh;
};


typedef __u32 ext2_ino_t;
typedef __u32 blk_t;
typedef __u64 blk64_t;
typedef __u32 dgrp_t;
typedef __s32 ext2_off_t;
typedef __s64 ext2_off64_t;
typedef __s64 e2_blkcnt_t;
typedef __u32 ext2_dirhash_t;









typedef long errcode_t;

struct error_table {
 char const * const * msgs;
 long base;
 int n_msgs;
};
struct et_list;

extern void com_err (const char *, long, const char *, ...)
 __attribute__((format(printf, 3, 4)));

extern void com_err_va (const char *whoami, errcode_t code, const char *fmt,
   va_list args)
 __attribute__((format(printf, 3, 0)));

extern char const *error_message (long);
extern void (*com_err_hook) (const char *, long, const char *, va_list);
extern void (*set_com_err_hook (void (*) (const char *, long,
       const char *, va_list)))
 (const char *, long, const char *, va_list);
extern void (*reset_com_err_hook (void)) (const char *, long,
       const char *, va_list);
extern int init_error_table(const char * const *msgs, long base, int count);
extern char *(*set_com_err_gettext (char *(*) (const char *)))
 (const char *);

extern errcode_t add_error_table(const struct error_table * et);
extern errcode_t remove_error_table(const struct error_table * et);
extern void add_to_error_table(struct et_list *new_table);


extern const char *com_right(struct et_list *list, long code);
extern const char *com_right_r(struct et_list *list, long code, char *str, size_t len);
extern void initialize_error_table_r(struct et_list **list,
         const char **messages,
         int num_errors,
         long base);
extern void free_error_table(struct et_list *et);


extern int et_list_lock(void);
extern int et_list_unlock(void);





typedef long long ext2_loff_t;





ext2_loff_t ext2fs_llseek (int, ext2_loff_t, int);

typedef struct struct_io_manager *io_manager;
typedef struct struct_io_channel *io_channel;
typedef struct struct_io_stats *io_stats;
struct struct_io_channel {
 errcode_t magic;
 io_manager manager;
 char *name;
 int block_size;
 errcode_t (*read_error)(io_channel channel,
          unsigned long block,
          int count,
          void *data,
          size_t size,
          int actual_bytes_read,
          errcode_t error);
 errcode_t (*write_error)(io_channel channel,
           unsigned long block,
           int count,
           const void *data,
           size_t size,
           int actual_bytes_written,
           errcode_t error);
 int refcount;
 int flags;
 long reserved[14];
 void *private_data;
 void *app_data;
 int align;
};

struct struct_io_stats {
 int num_fields;
 int reserved;
 unsigned long long bytes_read;
 unsigned long long bytes_written;
};

struct struct_io_manager {
 errcode_t magic;
 const char *name;
 errcode_t (*open)(const char *name, int flags, io_channel *channel);
 errcode_t (*close)(io_channel channel);
 errcode_t (*set_blksize)(io_channel channel, int blksize);
 errcode_t (*read_blk)(io_channel channel, unsigned long block,
         int count, void *data);
 errcode_t (*write_blk)(io_channel channel, unsigned long block,
          int count, const void *data);
 errcode_t (*flush)(io_channel channel);
 errcode_t (*write_byte)(io_channel channel, unsigned long offset,
    int count, const void *data);
 errcode_t (*set_option)(io_channel channel, const char *option,
    const char *arg);
 errcode_t (*get_stats)(io_channel channel, io_stats *io_stats);
 errcode_t (*read_blk64)(io_channel channel, unsigned long long block,
     int count, void *data);
 errcode_t (*write_blk64)(io_channel channel, unsigned long long block,
     int count, const void *data);
 errcode_t (*discard)(io_channel channel, unsigned long long block,
        unsigned long long count);
 errcode_t (*cache_readahead)(io_channel channel,
         unsigned long long block,
         unsigned long long count);
 errcode_t (*zeroout)(io_channel channel, unsigned long long block,
        unsigned long long count);
 long reserved[14];
};
extern errcode_t io_channel_set_options(io_channel channel,
     const char *options);
extern errcode_t io_channel_write_byte(io_channel channel,
           unsigned long offset,
           int count, const void *data);
extern errcode_t io_channel_read_blk64(io_channel channel,
           unsigned long long block,
           int count, void *data);
extern errcode_t io_channel_write_blk64(io_channel channel,
     unsigned long long block,
     int count, const void *data);
extern errcode_t io_channel_discard(io_channel channel,
        unsigned long long block,
        unsigned long long count);
extern errcode_t io_channel_zeroout(io_channel channel,
        unsigned long long block,
        unsigned long long count);
extern errcode_t io_channel_alloc_buf(io_channel channel,
          int count, void *ptr);
extern errcode_t io_channel_cache_readahead(io_channel io,
         unsigned long long block,
         unsigned long long count);






extern io_manager unix_io_manager;
extern io_manager unixfd_io_manager;



extern io_manager sparse_io_manager;
extern io_manager sparsefd_io_manager;


extern io_manager undo_io_manager;
extern errcode_t set_undo_io_backing_manager(io_manager manager);
extern errcode_t set_undo_io_backup_file(char *file_name);


extern io_manager test_io_manager, test_io_backing_manager;
extern void (*test_io_cb_read_blk)
 (unsigned long block, int count, errcode_t err);
extern void (*test_io_cb_write_blk)
 (unsigned long block, int count, errcode_t err);
extern void (*test_io_cb_read_blk64)
 (unsigned long long block, int count, errcode_t err);
extern void (*test_io_cb_write_blk64)
 (unsigned long long block, int count, errcode_t err);
extern void (*test_io_cb_set_blksize)
 (int blksize, errcode_t err);





extern const struct error_table et_ext2_error_table;
extern void initialize_ext2_error_table(void);


extern void initialize_ext2_error_table_r(struct et_list **list);
struct ext2_ext_attr_header {
 __u32 h_magic;
 __u32 h_refcount;
 __u32 h_blocks;
 __u32 h_hash;
 __u32 h_checksum;

 __u32 h_reserved[3];
};

struct ext2_ext_attr_entry {
 __u8 e_name_len;
 __u8 e_name_index;
 __u16 e_value_offs;
 __u32 e_value_inum;
 __u32 e_value_size;
 __u32 e_hash;



};


struct ext2fs_hashmap;

struct ext2fs_hashmap_entry {
 void *data;
 const void *key;
 size_t key_len;
 struct ext2fs_hashmap_entry *next;
 struct ext2fs_hashmap_entry *list_next;
 struct ext2fs_hashmap_entry *list_prev;
};

struct ext2fs_hashmap *ext2fs_hashmap_create(
    uint32_t(*hash_fct)(const void*, size_t),
    void(*free_fct)(void*), size_t size);
int ext2fs_hashmap_add(struct ext2fs_hashmap *h,
         void *data, const void *key,size_t key_len);
void *ext2fs_hashmap_lookup(struct ext2fs_hashmap *h, const void *key,
       size_t key_len);
void *ext2fs_hashmap_iter_in_order(struct ext2fs_hashmap *h,
       struct ext2fs_hashmap_entry **it);
void ext2fs_hashmap_del(struct ext2fs_hashmap *h,
   struct ext2fs_hashmap_entry *e);
void ext2fs_hashmap_free(struct ext2fs_hashmap *h);

uint32_t ext2fs_djb2_hash(const void *str, size_t size);
typedef struct struct_ext2_filsys *ext2_filsys;





struct ext2fs_struct_generic_bitmap_base {
 errcode_t magic;
 ext2_filsys fs;
};

typedef struct ext2fs_struct_generic_bitmap_base *ext2fs_generic_bitmap;
typedef struct ext2fs_struct_generic_bitmap_base *ext2fs_inode_bitmap;
typedef struct ext2fs_struct_generic_bitmap_base *ext2fs_block_bitmap;
typedef struct ext2_struct_u32_list *ext2_badblocks_list;
typedef struct ext2_struct_u32_iterate *ext2_badblocks_iterate;

typedef struct ext2_struct_u32_list *ext2_u32_list;
typedef struct ext2_struct_u32_iterate *ext2_u32_iterate;


typedef struct ext2_struct_u32_list *badblocks_list;
typedef struct ext2_struct_u32_iterate *badblocks_iterate;






struct ext2_db_entry2 {
 ext2_ino_t ino;
 blk64_t blk;
 e2_blkcnt_t blockcnt;
};


struct ext2_db_entry {
 ext2_ino_t ino;
 blk_t blk;
 int blockcnt;
};

typedef struct ext2_struct_dblist *ext2_dblist;
typedef struct ext2_file *ext2_file_t;
struct blk_alloc_ctx;
struct opaque_ext2_group_desc;

struct struct_ext2_filsys {
 errcode_t magic;
 io_channel io;
 int flags;
 char * device_name;
 struct ext2_super_block * super;
 unsigned int blocksize;
 int fragsize;
 dgrp_t group_desc_count;
 unsigned long desc_blocks;
 struct opaque_ext2_group_desc * group_desc;
 unsigned int inode_blocks_per_group;
 ext2fs_inode_bitmap inode_map;
 ext2fs_block_bitmap block_map;

 errcode_t (*get_blocks)(ext2_filsys fs, ext2_ino_t ino, blk_t *blocks);
 errcode_t (*check_directory)(ext2_filsys fs, ext2_ino_t ino);
 errcode_t (*write_bitmaps)(ext2_filsys fs);
 errcode_t (*read_inode)(ext2_filsys fs, ext2_ino_t ino,
    struct ext2_inode *inode);
 errcode_t (*write_inode)(ext2_filsys fs, ext2_ino_t ino,
    struct ext2_inode *inode);
 ext2_badblocks_list badblocks;
 ext2_dblist dblist;
 __u32 stride;
 struct ext2_super_block * orig_super;
 struct ext2_image_hdr * image_header;
 __u32 umask;
 time_t now;
 int cluster_ratio_bits;
 __u16 default_bitmap_type;
 __u16 pad;



 __u32 reserved[5];




 void * priv_data;




 struct ext2_inode_cache *icache;
 io_channel image_io;




 errcode_t (*get_alloc_block)(ext2_filsys fs, blk64_t goal,
         blk64_t *ret);
 errcode_t (*get_alloc_block2)(ext2_filsys fs, blk64_t goal,
          blk64_t *ret, struct blk_alloc_ctx *ctx);
 void (*block_alloc_stats)(ext2_filsys fs, blk64_t blk, int inuse);




 void *mmp_buf;
 void *mmp_cmp;
 int mmp_fd;




 long mmp_last_written;


 struct ext2fs_progress_ops *progress_ops;


 __u32 csum_seed;

 io_channel journal_io;
 char *journal_name;


 errcode_t (*new_range)(ext2_filsys fs, int flags, blk64_t goal,
          blk64_t len, blk64_t *pblk, blk64_t *plen);
 void (*block_alloc_stats_range)(ext2_filsys fs, blk64_t blk, blk_t num,
     int inuse);


 struct ext2fs_hashmap* block_sha_map;

 const struct ext2fs_nls_table *encoding;
};




extern const char *ext2fs_block_string;
extern const char *ext2fs_inode_string;
extern const char *ext2fs_mark_string;
extern const char *ext2fs_unmark_string;
extern const char *ext2fs_test_string;
extern void ext2fs_warn_bitmap(errcode_t errcode, unsigned long arg,
          const char *description);
extern void ext2fs_warn_bitmap2(ext2fs_generic_bitmap bitmap,
    int code, unsigned long arg);
extern void ext2fs_mark_block_bitmap_range(ext2fs_block_bitmap bitmap,
        blk_t block, int num);
extern void ext2fs_unmark_block_bitmap_range(ext2fs_block_bitmap bitmap,
          blk_t block, int num);
extern int ext2fs_test_block_bitmap_range(ext2fs_block_bitmap bitmap,
       blk_t block, int num);
extern int ext2fs_test_inode_bitmap_range(ext2fs_inode_bitmap bitmap,
       ext2_ino_t inode, int num);
extern int ext2fs_mark_generic_bitmap(ext2fs_generic_bitmap bitmap,
      __u32 bitno);
extern int ext2fs_unmark_generic_bitmap(ext2fs_generic_bitmap bitmap,
        blk_t bitno);
extern int ext2fs_test_generic_bitmap(ext2fs_generic_bitmap bitmap,
          blk_t bitno);
extern int ext2fs_test_block_bitmap_range(ext2fs_block_bitmap bitmap,
       blk_t block, int num);
extern void ext2fs_set_bitmap_padding(ext2fs_generic_bitmap map);
extern __u32 ext2fs_get_generic_bitmap_start(ext2fs_generic_bitmap bitmap);
extern __u32 ext2fs_get_generic_bitmap_end(ext2fs_generic_bitmap bitmap);
extern void ext2fs_clear_generic_bmap(ext2fs_generic_bitmap bitmap);
extern errcode_t ext2fs_compare_generic_bmap(errcode_t neq,
          ext2fs_generic_bitmap bm1,
          ext2fs_generic_bitmap bm2);
extern void ext2fs_set_generic_bmap_padding(ext2fs_generic_bitmap bmap);
extern int ext2fs_mark_generic_bmap(ext2fs_generic_bitmap bitmap,
        blk64_t bitno);
extern int ext2fs_unmark_generic_bmap(ext2fs_generic_bitmap bitmap,
          blk64_t bitno);
extern int ext2fs_test_generic_bmap(ext2fs_generic_bitmap bitmap,
        blk64_t bitno);
extern int ext2fs_test_block_bitmap_range2(ext2fs_block_bitmap bitmap,
        blk64_t block, unsigned int num);
extern __u64 ext2fs_get_generic_bmap_start(ext2fs_generic_bitmap bitmap);
extern __u64 ext2fs_get_generic_bmap_end(ext2fs_generic_bitmap bitmap);
extern int ext2fs_test_block_bitmap_range2(ext2fs_block_bitmap bitmap,
        blk64_t block, unsigned int num);
extern void ext2fs_mark_block_bitmap_range2(ext2fs_block_bitmap bitmap,
         blk64_t block, unsigned int num);
extern void ext2fs_unmark_block_bitmap_range2(ext2fs_block_bitmap bitmap,
           blk64_t block, unsigned int num);
extern errcode_t ext2fs_find_first_zero_generic_bmap(ext2fs_generic_bitmap bitmap,
           __u64 start, __u64 end,
           __u64 *out);
extern errcode_t ext2fs_find_first_set_generic_bmap(ext2fs_generic_bitmap bitmap,
          __u64 start, __u64 end,
          __u64 *out);
inline void ext2fs_fast_set_bit(unsigned int nr,void * addr)
{
 unsigned char *ADDR = (unsigned char *) addr;

 ADDR += nr >> 3;
 *ADDR |= (unsigned char) (1 << (nr & 0x07));
}

inline void ext2fs_fast_clear_bit(unsigned int nr, void * addr)
{
 unsigned char *ADDR = (unsigned char *) addr;

 ADDR += nr >> 3;
 *ADDR &= (unsigned char) ~(1 << (nr & 0x07));
}


inline void ext2fs_fast_set_bit64(__u64 nr, void * addr)
{
 unsigned char *ADDR = (unsigned char *) addr;

 ADDR += nr >> 3;
 *ADDR |= (unsigned char) (1 << (nr & 0x07));
}

inline void ext2fs_fast_clear_bit64(__u64 nr, void * addr)
{
 unsigned char *ADDR = (unsigned char *) addr;

 ADDR += nr >> 3;
 *ADDR &= (unsigned char) ~(1 << (nr & 0x07));
}
inline __u16 ext2fs_swab16(__u16 val)
{
 return (val >> 8) | (__u16) (val << 8);
}

inline __u32 ext2fs_swab32(__u32 val)
{
 return ((val>>24) | ((val>>8)&0xFF00) |
  ((val<<8)&0xFF0000) | (val<<24));
}



inline __u64 ext2fs_swab64(__u64 val)
{
 return (ext2fs_swab32((__u32) (val >> 32)) |
  (((__u64)ext2fs_swab32(val & 0xFFFFFFFFUL)) << 32));
}

inline int ext2fs_mark_block_bitmap(ext2fs_block_bitmap bitmap,
           blk_t block)
{
 return ext2fs_mark_generic_bitmap((ext2fs_generic_bitmap) bitmap,
       block);
}

inline int ext2fs_unmark_block_bitmap(ext2fs_block_bitmap bitmap,
      blk_t block)
{
 return ext2fs_unmark_generic_bitmap((ext2fs_generic_bitmap) bitmap,
         block);
}

inline int ext2fs_test_block_bitmap(ext2fs_block_bitmap bitmap,
           blk_t block)
{
 return ext2fs_test_generic_bitmap((ext2fs_generic_bitmap) bitmap,
       block);
}

inline int ext2fs_mark_inode_bitmap(ext2fs_inode_bitmap bitmap,
           ext2_ino_t inode)
{
 return ext2fs_mark_generic_bitmap((ext2fs_generic_bitmap) bitmap,
       inode);
}

inline int ext2fs_unmark_inode_bitmap(ext2fs_inode_bitmap bitmap,
      ext2_ino_t inode)
{
 return ext2fs_unmark_generic_bitmap((ext2fs_generic_bitmap) bitmap,
         inode);
}

inline int ext2fs_test_inode_bitmap(ext2fs_inode_bitmap bitmap,
           ext2_ino_t inode)
{
 return ext2fs_test_generic_bitmap((ext2fs_generic_bitmap) bitmap,
       inode);
}

inline void ext2fs_fast_mark_block_bitmap(ext2fs_block_bitmap bitmap,
         blk_t block)
{
 ext2fs_mark_generic_bitmap((ext2fs_generic_bitmap) bitmap, block);
}

inline void ext2fs_fast_unmark_block_bitmap(ext2fs_block_bitmap bitmap,
           blk_t block)
{
 ext2fs_unmark_generic_bitmap((ext2fs_generic_bitmap) bitmap, block);
}

inline int ext2fs_fast_test_block_bitmap(ext2fs_block_bitmap bitmap,
         blk_t block)
{
 return ext2fs_test_generic_bitmap((ext2fs_generic_bitmap) bitmap,
       block);
}

inline void ext2fs_fast_mark_inode_bitmap(ext2fs_inode_bitmap bitmap,
         ext2_ino_t inode)
{
 ext2fs_mark_generic_bitmap((ext2fs_generic_bitmap) bitmap, inode);
}

inline void ext2fs_fast_unmark_inode_bitmap(ext2fs_inode_bitmap bitmap,
           ext2_ino_t inode)
{
 ext2fs_unmark_generic_bitmap((ext2fs_generic_bitmap) bitmap, inode);
}

inline int ext2fs_fast_test_inode_bitmap(ext2fs_inode_bitmap bitmap,
        ext2_ino_t inode)
{
 return ext2fs_test_generic_bitmap((ext2fs_generic_bitmap) bitmap,
       inode);
}

inline blk_t ext2fs_get_block_bitmap_start(ext2fs_block_bitmap bitmap)
{
 return ext2fs_get_generic_bitmap_start((ext2fs_generic_bitmap) bitmap);
}

inline ext2_ino_t ext2fs_get_inode_bitmap_start(ext2fs_inode_bitmap bitmap)
{
 return ext2fs_get_generic_bitmap_start((ext2fs_generic_bitmap) bitmap);
}

inline blk_t ext2fs_get_block_bitmap_end(ext2fs_block_bitmap bitmap)
{
 return ext2fs_get_generic_bitmap_end((ext2fs_generic_bitmap) bitmap);
}

inline ext2_ino_t ext2fs_get_inode_bitmap_end(ext2fs_inode_bitmap bitmap)
{
 return ext2fs_get_generic_bitmap_end((ext2fs_generic_bitmap) bitmap);
}

inline int ext2fs_fast_test_block_bitmap_range(ext2fs_block_bitmap bitmap,
       blk_t block, int num)
{
 return ext2fs_test_block_bitmap_range(bitmap, block, num);
}

inline void ext2fs_fast_mark_block_bitmap_range(ext2fs_block_bitmap bitmap,
        blk_t block, int num)
{
 ext2fs_mark_block_bitmap_range(bitmap, block, num);
}

inline void ext2fs_fast_unmark_block_bitmap_range(ext2fs_block_bitmap bitmap,
          blk_t block, int num)
{
 ext2fs_unmark_block_bitmap_range(bitmap, block, num);
}



inline int ext2fs_mark_block_bitmap2(ext2fs_block_bitmap bitmap,
           blk64_t block)
{
 return ext2fs_mark_generic_bmap((ext2fs_generic_bitmap) bitmap,
     block);
}

inline int ext2fs_unmark_block_bitmap2(ext2fs_block_bitmap bitmap,
      blk64_t block)
{
 return ext2fs_unmark_generic_bmap((ext2fs_generic_bitmap) bitmap, block);
}

inline int ext2fs_test_block_bitmap2(ext2fs_block_bitmap bitmap,
           blk64_t block)
{
 return ext2fs_test_generic_bmap((ext2fs_generic_bitmap) bitmap,
     block);
}

inline int ext2fs_mark_inode_bitmap2(ext2fs_inode_bitmap bitmap,
           ext2_ino_t inode)
{
 return ext2fs_mark_generic_bmap((ext2fs_generic_bitmap) bitmap,
     inode);
}

inline int ext2fs_unmark_inode_bitmap2(ext2fs_inode_bitmap bitmap,
      ext2_ino_t inode)
{
 return ext2fs_unmark_generic_bmap((ext2fs_generic_bitmap) bitmap,
       inode);
}

inline int ext2fs_test_inode_bitmap2(ext2fs_inode_bitmap bitmap,
           ext2_ino_t inode)
{
 return ext2fs_test_generic_bmap((ext2fs_generic_bitmap) bitmap,
     inode);
}

inline void ext2fs_fast_mark_block_bitmap2(ext2fs_block_bitmap bitmap,
          blk64_t block)
{
 ext2fs_mark_generic_bmap((ext2fs_generic_bitmap) bitmap, block);
}

inline void ext2fs_fast_unmark_block_bitmap2(ext2fs_block_bitmap bitmap,
            blk64_t block)
{
 ext2fs_unmark_generic_bmap((ext2fs_generic_bitmap) bitmap, block);
}

inline int ext2fs_fast_test_block_bitmap2(ext2fs_block_bitmap bitmap,
         blk64_t block)
{
 return ext2fs_test_generic_bmap((ext2fs_generic_bitmap) bitmap,
     block);
}

inline void ext2fs_fast_mark_inode_bitmap2(ext2fs_inode_bitmap bitmap,
          ext2_ino_t inode)
{
 ext2fs_mark_generic_bmap((ext2fs_generic_bitmap) bitmap, inode);
}

inline void ext2fs_fast_unmark_inode_bitmap2(ext2fs_inode_bitmap bitmap,
            ext2_ino_t inode)
{
 ext2fs_unmark_generic_bmap((ext2fs_generic_bitmap) bitmap, inode);
}

inline int ext2fs_fast_test_inode_bitmap2(ext2fs_inode_bitmap bitmap,
         ext2_ino_t inode)
{
 return ext2fs_test_generic_bmap((ext2fs_generic_bitmap) bitmap,
     inode);
}

inline errcode_t ext2fs_find_first_zero_block_bitmap2(ext2fs_block_bitmap bitmap,
       blk64_t start,
       blk64_t end,
       blk64_t *out)
{
 __u64 o;
 errcode_t rv;

 rv = ext2fs_find_first_zero_generic_bmap((ext2fs_generic_bitmap) bitmap,
       start, end, &o);
 if (!rv)
  *out = o;
 return rv;
}

inline errcode_t ext2fs_find_first_zero_inode_bitmap2(ext2fs_inode_bitmap bitmap,
       ext2_ino_t start,
       ext2_ino_t end,
       ext2_ino_t *out)
{
 __u64 o;
 errcode_t rv;

 rv = ext2fs_find_first_zero_generic_bmap((ext2fs_generic_bitmap) bitmap,
       start, end, &o);
 if (!rv)
  *out = (ext2_ino_t) o;
 return rv;
}

inline errcode_t ext2fs_find_first_set_block_bitmap2(ext2fs_block_bitmap bitmap,
             blk64_t start,
             blk64_t end,
             blk64_t *out)
{
 __u64 o;
 errcode_t rv;

 rv = ext2fs_find_first_set_generic_bmap((ext2fs_generic_bitmap) bitmap,
      start, end, &o);
 if (!rv)
  *out = o;
 return rv;
}

inline errcode_t ext2fs_find_first_set_inode_bitmap2(ext2fs_inode_bitmap bitmap,
             ext2_ino_t start,
             ext2_ino_t end,
             ext2_ino_t *out)
{
 __u64 o;
 errcode_t rv;

 rv = ext2fs_find_first_set_generic_bmap((ext2fs_generic_bitmap) bitmap,
      start, end, &o);
 if (!rv)
  *out = (ext2_ino_t) o;
 return rv;
}

inline blk64_t ext2fs_get_block_bitmap_start2(ext2fs_block_bitmap bitmap)
{
 return ext2fs_get_generic_bmap_start((ext2fs_generic_bitmap) bitmap);
}

inline ext2_ino_t ext2fs_get_inode_bitmap_start2(ext2fs_inode_bitmap bitmap)
{
 return (ext2_ino_t) ext2fs_get_generic_bmap_start((ext2fs_generic_bitmap) bitmap);
}

inline blk64_t ext2fs_get_block_bitmap_end2(ext2fs_block_bitmap bitmap)
{
 return ext2fs_get_generic_bmap_end((ext2fs_generic_bitmap) bitmap);
}

inline ext2_ino_t ext2fs_get_inode_bitmap_end2(ext2fs_inode_bitmap bitmap)
{
 return (ext2_ino_t) ext2fs_get_generic_bmap_end((ext2fs_generic_bitmap) bitmap);
}

inline int ext2fs_fast_test_block_bitmap_range2(ext2fs_block_bitmap bitmap,
        blk64_t block,
        unsigned int num)
{
 return ext2fs_test_block_bitmap_range2(bitmap, block, num);
}

inline void ext2fs_fast_mark_block_bitmap_range2(ext2fs_block_bitmap bitmap,
         blk64_t block,
         unsigned int num)
{
 ext2fs_mark_block_bitmap_range2(bitmap, block, num);
}

inline void ext2fs_fast_unmark_block_bitmap_range2(ext2fs_block_bitmap bitmap,
           blk64_t block,
           unsigned int num)
{
 ext2fs_unmark_block_bitmap_range2(bitmap, block, num);
}





extern int ext2fs_set_bit(unsigned int nr,void * addr);
extern int ext2fs_clear_bit(unsigned int nr, void * addr);
extern int ext2fs_test_bit(unsigned int nr, const void * addr);


extern int ext2fs_set_bit64(__u64 nr,void * addr);
extern int ext2fs_clear_bit64(__u64 nr, void * addr);
extern int ext2fs_test_bit64(__u64 nr, const void * addr);
extern unsigned int ext2fs_bitcount(const void *addr, unsigned int nbytes);
struct blk_alloc_ctx {
 ext2_ino_t ino;
 struct ext2_inode *inode;
 blk64_t lblk;
 int flags;
};
struct ext2fs_extent {
 blk64_t e_pblk;
 blk64_t e_lblk;
 __u32 e_len;
 __u32 e_flags;
};

typedef struct ext2_extent_handle *ext2_extent_handle_t;
typedef struct ext2_extent_path *ext2_extent_path_t;
struct ext2_extent_info {
 int curr_entry;
 int curr_level;
 int num_entries;
 int max_entries;
 int max_depth;
 int bytes_avail;
 blk64_t max_lblk;
 blk64_t max_pblk;
 __u32 max_len;
 __u32 max_uninit_len;
};
typedef struct ext2_struct_inode_scan *ext2_inode_scan;
typedef struct ext2_icount *ext2_icount_t;
typedef struct stat64 ext2fs_struct_stat;
struct ext2_xattr_handle;
static inline int ext2fs_has_group_desc_csum(ext2_filsys fs)
{
 return ext2fs_has_feature_metadata_csum(fs->super) ||
        ext2fs_has_feature_gdt_csum(fs->super);
}


static inline int ext2fs_needs_large_file_feature(unsigned long long file_size)
{
 return file_size >= 0x80000000ULL;
}


extern void ext2fs_clear_block_uninit(ext2_filsys fs, dgrp_t group);
extern errcode_t ext2fs_new_inode(ext2_filsys fs, ext2_ino_t dir, int mode,
      ext2fs_inode_bitmap map, ext2_ino_t *ret);
extern errcode_t ext2fs_new_block(ext2_filsys fs, blk_t goal,
      ext2fs_block_bitmap map, blk_t *ret);
extern errcode_t ext2fs_new_block2(ext2_filsys fs, blk64_t goal,
       ext2fs_block_bitmap map, blk64_t *ret);
extern errcode_t ext2fs_new_block3(ext2_filsys fs, blk64_t goal,
       ext2fs_block_bitmap map, blk64_t *ret,
       struct blk_alloc_ctx *ctx);
extern errcode_t ext2fs_get_free_blocks(ext2_filsys fs, blk_t start,
     blk_t finish, int num,
     ext2fs_block_bitmap map,
     blk_t *ret);
extern errcode_t ext2fs_get_free_blocks2(ext2_filsys fs, blk64_t start,
      blk64_t finish, int num,
      ext2fs_block_bitmap map,
      blk64_t *ret);
extern errcode_t ext2fs_alloc_block(ext2_filsys fs, blk_t goal,
        char *block_buf, blk_t *ret);
extern errcode_t ext2fs_alloc_block2(ext2_filsys fs, blk64_t goal,
         char *block_buf, blk64_t *ret);
extern errcode_t ext2fs_alloc_block3(ext2_filsys fs, blk64_t goal,
         char *block_buf, blk64_t *ret,
         struct blk_alloc_ctx *ctx);

extern void ext2fs_set_alloc_block_callback(ext2_filsys fs,
         errcode_t (*func)(ext2_filsys fs,
             blk64_t goal,
             blk64_t *ret),
         errcode_t (**old)(ext2_filsys fs,
             blk64_t goal,
             blk64_t *ret));
blk64_t ext2fs_find_inode_goal(ext2_filsys fs, ext2_ino_t ino,
          struct ext2_inode *inode, blk64_t lblk);
extern void ext2fs_set_new_range_callback(ext2_filsys fs,
 errcode_t (*func)(ext2_filsys fs, int flags, blk64_t goal,
          blk64_t len, blk64_t *pblk, blk64_t *plen),
 errcode_t (**old)(ext2_filsys fs, int flags, blk64_t goal,
          blk64_t len, blk64_t *pblk, blk64_t *plen));
extern void ext2fs_set_block_alloc_stats_range_callback(ext2_filsys fs,
 void (*func)(ext2_filsys fs, blk64_t blk,
        blk_t num, int inuse),
 void (**old)(ext2_filsys fs, blk64_t blk,
        blk_t num, int inuse));



errcode_t ext2fs_new_range(ext2_filsys fs, int flags, blk64_t goal,
      blk64_t len, ext2fs_block_bitmap map, blk64_t *pblk,
      blk64_t *plen);



errcode_t ext2fs_alloc_range(ext2_filsys fs, int flags, blk64_t goal,
        blk_t len, blk64_t *ret);


extern int ext2fs_reserve_super_and_bgd(ext2_filsys fs,
     dgrp_t group,
     ext2fs_block_bitmap bmap);
extern void ext2fs_set_block_alloc_stats_callback(ext2_filsys fs,
        void (*func)(ext2_filsys fs,
              blk64_t blk,
              int inuse),
        void (**old)(ext2_filsys fs,
              blk64_t blk,
              int inuse));


void ext2fs_inode_alloc_stats(ext2_filsys fs, ext2_ino_t ino, int inuse);
void ext2fs_inode_alloc_stats2(ext2_filsys fs, ext2_ino_t ino,
          int inuse, int isdir);
void ext2fs_block_alloc_stats(ext2_filsys fs, blk_t blk, int inuse);
void ext2fs_block_alloc_stats2(ext2_filsys fs, blk64_t blk, int inuse);
void ext2fs_block_alloc_stats_range(ext2_filsys fs, blk64_t blk,
        blk_t num, int inuse);


extern errcode_t ext2fs_allocate_tables(ext2_filsys fs);
extern errcode_t ext2fs_allocate_group_table(ext2_filsys fs, dgrp_t group,
          ext2fs_block_bitmap bmap);


extern errcode_t ext2fs_u32_list_create(ext2_u32_list *ret, int size);
extern errcode_t ext2fs_u32_list_add(ext2_u32_list bb, __u32 blk);
extern int ext2fs_u32_list_find(ext2_u32_list bb, __u32 blk);
extern int ext2fs_u32_list_test(ext2_u32_list bb, blk_t blk);
extern errcode_t ext2fs_u32_list_iterate_begin(ext2_u32_list bb,
            ext2_u32_iterate *ret);
extern int ext2fs_u32_list_iterate(ext2_u32_iterate iter, blk_t *blk);
extern void ext2fs_u32_list_iterate_end(ext2_u32_iterate iter);
extern errcode_t ext2fs_u32_copy(ext2_u32_list src, ext2_u32_list *dest);
extern int ext2fs_u32_list_equal(ext2_u32_list bb1, ext2_u32_list bb2);

extern errcode_t ext2fs_badblocks_list_create(ext2_badblocks_list *ret,
         int size);
extern errcode_t ext2fs_badblocks_list_add(ext2_badblocks_list bb,
        blk_t blk);
extern int ext2fs_badblocks_list_test(ext2_badblocks_list bb,
        blk_t blk);
extern int ext2fs_u32_list_del(ext2_u32_list bb, __u32 blk);
extern void ext2fs_badblocks_list_del(ext2_u32_list bb, __u32 blk);
extern errcode_t
 ext2fs_badblocks_list_iterate_begin(ext2_badblocks_list bb,
         ext2_badblocks_iterate *ret);
extern int ext2fs_badblocks_list_iterate(ext2_badblocks_iterate iter,
      blk_t *blk);
extern void ext2fs_badblocks_list_iterate_end(ext2_badblocks_iterate iter);
extern errcode_t ext2fs_badblocks_copy(ext2_badblocks_list src,
           ext2_badblocks_list *dest);
extern int ext2fs_badblocks_equal(ext2_badblocks_list bb1,
      ext2_badblocks_list bb2);
extern int ext2fs_u32_list_count(ext2_u32_list bb);


extern errcode_t badblocks_list_create(badblocks_list *ret, int size);
extern errcode_t badblocks_list_add(badblocks_list bb, blk_t blk);
extern int badblocks_list_test(badblocks_list bb, blk_t blk);
extern errcode_t badblocks_list_iterate_begin(badblocks_list bb,
           badblocks_iterate *ret);
extern int badblocks_list_iterate(badblocks_iterate iter, blk_t *blk);
extern void badblocks_list_iterate_end(badblocks_iterate iter);
extern void badblocks_list_free(badblocks_list bb);


extern errcode_t ext2fs_update_bb_inode(ext2_filsys fs,
     ext2_badblocks_list bb_list);


extern void ext2fs_free_block_bitmap(ext2fs_block_bitmap bitmap);
extern void ext2fs_free_inode_bitmap(ext2fs_inode_bitmap bitmap);
extern errcode_t ext2fs_copy_bitmap(ext2fs_generic_bitmap src,
        ext2fs_generic_bitmap *dest);
extern errcode_t ext2fs_allocate_block_bitmap(ext2_filsys fs,
           const char *descr,
           ext2fs_block_bitmap *ret);
extern errcode_t ext2fs_allocate_subcluster_bitmap(ext2_filsys fs,
         const char *descr,
         ext2fs_block_bitmap *ret);
extern int ext2fs_get_bitmap_granularity(ext2fs_block_bitmap bitmap);
extern errcode_t ext2fs_allocate_inode_bitmap(ext2_filsys fs,
           const char *descr,
           ext2fs_inode_bitmap *ret);
extern errcode_t ext2fs_fudge_inode_bitmap_end(ext2fs_inode_bitmap bitmap,
            ext2_ino_t end, ext2_ino_t *oend);
extern errcode_t ext2fs_fudge_block_bitmap_end(ext2fs_block_bitmap bitmap,
            blk_t end, blk_t *oend);
extern errcode_t ext2fs_fudge_block_bitmap_end2(ext2fs_block_bitmap bitmap,
      blk64_t end, blk64_t *oend);
extern void ext2fs_clear_inode_bitmap(ext2fs_inode_bitmap bitmap);
extern void ext2fs_clear_block_bitmap(ext2fs_block_bitmap bitmap);
extern errcode_t ext2fs_resize_inode_bitmap(__u32 new_end, __u32 new_real_end,
         ext2fs_inode_bitmap bmap);
extern errcode_t ext2fs_resize_inode_bitmap2(__u64 new_end,
          __u64 new_real_end,
          ext2fs_inode_bitmap bmap);
extern errcode_t ext2fs_resize_block_bitmap(__u32 new_end, __u32 new_real_end,
         ext2fs_block_bitmap bmap);
extern errcode_t ext2fs_resize_block_bitmap2(__u64 new_end,
          __u64 new_real_end,
          ext2fs_block_bitmap bmap);
extern errcode_t ext2fs_compare_block_bitmap(ext2fs_block_bitmap bm1,
          ext2fs_block_bitmap bm2);
extern errcode_t ext2fs_compare_inode_bitmap(ext2fs_inode_bitmap bm1,
          ext2fs_inode_bitmap bm2);
extern errcode_t ext2fs_set_inode_bitmap_range(ext2fs_inode_bitmap bmap,
     ext2_ino_t start, unsigned int num,
     void *in);
extern errcode_t ext2fs_set_inode_bitmap_range2(ext2fs_inode_bitmap bmap,
      __u64 start, size_t num,
      void *in);
extern errcode_t ext2fs_get_inode_bitmap_range(ext2fs_inode_bitmap bmap,
     ext2_ino_t start, unsigned int num,
     void *out);
extern errcode_t ext2fs_get_inode_bitmap_range2(ext2fs_inode_bitmap bmap,
      __u64 start, size_t num,
      void *out);
extern errcode_t ext2fs_set_block_bitmap_range(ext2fs_block_bitmap bmap,
     blk_t start, unsigned int num,
     void *in);
extern errcode_t ext2fs_set_block_bitmap_range2(ext2fs_block_bitmap bmap,
      blk64_t start, size_t num,
      void *in);
extern errcode_t ext2fs_get_block_bitmap_range(ext2fs_block_bitmap bmap,
     blk_t start, unsigned int num,
     void *out);
extern errcode_t ext2fs_get_block_bitmap_range2(ext2fs_block_bitmap bmap,
      blk64_t start, size_t num,
      void *out);


extern __u32 ext2fs_inode_bitmap_checksum(ext2_filsys fs, dgrp_t group);
extern __u32 ext2fs_block_bitmap_checksum(ext2_filsys fs, dgrp_t group);
extern dgrp_t ext2fs_group_of_blk2(ext2_filsys fs, blk64_t);
extern blk64_t ext2fs_group_first_block2(ext2_filsys fs, dgrp_t group);
extern blk64_t ext2fs_group_last_block2(ext2_filsys fs, dgrp_t group);
extern int ext2fs_group_blocks_count(ext2_filsys fs, dgrp_t group);
extern blk64_t ext2fs_inode_data_blocks2(ext2_filsys fs,
      struct ext2_inode *inode);
extern blk64_t ext2fs_inode_i_blocks(ext2_filsys fs,
         struct ext2_inode *inode);
extern blk64_t ext2fs_get_stat_i_blocks(ext2_filsys fs,
     struct ext2_inode *inode);
extern blk64_t ext2fs_blocks_count(struct ext2_super_block *super);
extern void ext2fs_blocks_count_set(struct ext2_super_block *super,
        blk64_t blk);
extern void ext2fs_blocks_count_add(struct ext2_super_block *super,
        blk64_t blk);
extern blk64_t ext2fs_r_blocks_count(struct ext2_super_block *super);
extern void ext2fs_r_blocks_count_set(struct ext2_super_block *super,
          blk64_t blk);
extern void ext2fs_r_blocks_count_add(struct ext2_super_block *super,
          blk64_t blk);
extern blk64_t ext2fs_free_blocks_count(struct ext2_super_block *super);
extern void ext2fs_free_blocks_count_set(struct ext2_super_block *super,
      blk64_t blk);
extern void ext2fs_free_blocks_count_add(struct ext2_super_block *super,
      blk64_t blk);

extern struct ext2_group_desc *ext2fs_group_desc(ext2_filsys fs,
       struct opaque_ext2_group_desc *gdp,
       dgrp_t group);
extern blk64_t ext2fs_block_bitmap_csum(ext2_filsys fs, dgrp_t group);
extern blk64_t ext2fs_block_bitmap_loc(ext2_filsys fs, dgrp_t group);
extern void ext2fs_block_bitmap_loc_set(ext2_filsys fs, dgrp_t group,
     blk64_t blk);
extern __u32 ext2fs_inode_bitmap_csum(ext2_filsys fs, dgrp_t group);
extern blk64_t ext2fs_inode_bitmap_loc(ext2_filsys fs, dgrp_t group);
extern void ext2fs_inode_bitmap_loc_set(ext2_filsys fs, dgrp_t group,
     blk64_t blk);
extern blk64_t ext2fs_inode_table_loc(ext2_filsys fs, dgrp_t group);
extern void ext2fs_inode_table_loc_set(ext2_filsys fs, dgrp_t group,
           blk64_t blk);
extern __u32 ext2fs_bg_free_blocks_count(ext2_filsys fs, dgrp_t group);
extern void ext2fs_bg_free_blocks_count_set(ext2_filsys fs, dgrp_t group,
      __u32 n);
extern __u32 ext2fs_bg_free_inodes_count(ext2_filsys fs, dgrp_t group);
extern void ext2fs_bg_free_inodes_count_set(ext2_filsys fs, dgrp_t group,
      __u32 n);
extern __u32 ext2fs_bg_used_dirs_count(ext2_filsys fs, dgrp_t group);
extern void ext2fs_bg_used_dirs_count_set(ext2_filsys fs, dgrp_t group,
           __u32 n);
extern __u32 ext2fs_bg_itable_unused(ext2_filsys fs, dgrp_t group);
extern void ext2fs_bg_itable_unused_set(ext2_filsys fs, dgrp_t group,
         __u32 n);
extern __u16 ext2fs_bg_flags(ext2_filsys fs, dgrp_t group);
extern void ext2fs_bg_flags_zap(ext2_filsys fs, dgrp_t group);
extern int ext2fs_bg_flags_test(ext2_filsys fs, dgrp_t group, __u16 bg_flag);
extern void ext2fs_bg_flags_set(ext2_filsys fs, dgrp_t group, __u16 bg_flags);
extern void ext2fs_bg_flags_clear(ext2_filsys fs, dgrp_t group, __u16 bg_flags);
extern __u16 ext2fs_bg_checksum(ext2_filsys fs, dgrp_t group);
extern void ext2fs_bg_checksum_set(ext2_filsys fs, dgrp_t group, __u16 checksum);
extern blk64_t ext2fs_file_acl_block(ext2_filsys fs,
         const struct ext2_inode *inode);
extern void ext2fs_file_acl_block_set(ext2_filsys fs,
          struct ext2_inode *inode, blk64_t blk);
extern errcode_t ext2fs_inode_size_set(ext2_filsys fs, struct ext2_inode *inode,
           ext2_off64_t size);


extern errcode_t ext2fs_block_iterate(ext2_filsys fs,
          ext2_ino_t ino,
          int flags,
          char *block_buf,
          int (*func)(ext2_filsys fs,
        blk_t *blocknr,
        int blockcnt,
        void *priv_data),
          void *priv_data);
errcode_t ext2fs_block_iterate2(ext2_filsys fs,
    ext2_ino_t ino,
    int flags,
    char *block_buf,
    int (*func)(ext2_filsys fs,
         blk_t *blocknr,
         e2_blkcnt_t blockcnt,
         blk_t ref_blk,
         int ref_offset,
         void *priv_data),
    void *priv_data);
errcode_t ext2fs_block_iterate3(ext2_filsys fs,
    ext2_ino_t ino,
    int flags,
    char *block_buf,
    int (*func)(ext2_filsys fs,
         blk64_t *blocknr,
         e2_blkcnt_t blockcnt,
         blk64_t ref_blk,
         int ref_offset,
         void *priv_data),
    void *priv_data);


extern errcode_t ext2fs_bmap(ext2_filsys fs, ext2_ino_t ino,
        struct ext2_inode *inode,
        char *block_buf, int bmap_flags,
        blk_t block, blk_t *phys_blk);
extern errcode_t ext2fs_bmap2(ext2_filsys fs, ext2_ino_t ino,
         struct ext2_inode *inode,
         char *block_buf, int bmap_flags, blk64_t block,
         int *ret_flags, blk64_t *phys_blk);
errcode_t ext2fs_map_cluster_block(ext2_filsys fs, ext2_ino_t ino,
       struct ext2_inode *inode, blk64_t lblk,
       blk64_t *pblk);
extern errcode_t ext2fs_check_desc(ext2_filsys fs);


extern errcode_t ext2fs_close(ext2_filsys fs);
extern errcode_t ext2fs_close2(ext2_filsys fs, int flags);
extern errcode_t ext2fs_close_free(ext2_filsys *fs);
extern errcode_t ext2fs_flush(ext2_filsys fs);
extern errcode_t ext2fs_flush2(ext2_filsys fs, int flags);
extern int ext2fs_bg_has_super(ext2_filsys fs, dgrp_t group_block);
extern errcode_t ext2fs_super_and_bgd_loc2(ext2_filsys fs,
        dgrp_t group,
        blk64_t *ret_super_blk,
        blk64_t *ret_old_desc_blk,
        blk64_t *ret_new_desc_blk,
        blk_t *ret_used_blks);
extern int ext2fs_super_and_bgd_loc(ext2_filsys fs,
        dgrp_t group,
        blk_t *ret_super_blk,
        blk_t *ret_old_desc_blk,
        blk_t *ret_new_desc_blk,
        int *ret_meta_bg);
extern void ext2fs_update_dynamic_rev(ext2_filsys fs);


extern __u32 ext2fs_crc32_be(__u32 crc, unsigned char const *p, size_t len);
extern __u32 ext2fs_crc32c_le(__u32 crc, unsigned char const *p, size_t len);


extern void ext2fs_init_csum_seed(ext2_filsys fs);
extern errcode_t ext2fs_mmp_csum_set(ext2_filsys fs, struct mmp_struct *mmp);
extern int ext2fs_mmp_csum_verify(ext2_filsys, struct mmp_struct *mmp);
extern int ext2fs_verify_csum_type(ext2_filsys fs, struct ext2_super_block *sb);
extern errcode_t ext2fs_superblock_csum_set(ext2_filsys fs,
         struct ext2_super_block *sb);
extern int ext2fs_superblock_csum_verify(ext2_filsys fs,
      struct ext2_super_block *sb);
extern errcode_t ext2fs_ext_attr_block_csum_set(ext2_filsys fs,
     ext2_ino_t inum, blk64_t block,
     struct ext2_ext_attr_header *hdr);
extern int ext2fs_ext_attr_block_csum_verify(ext2_filsys fs, ext2_ino_t inum,
          blk64_t block,
          struct ext2_ext_attr_header *hdr);




extern void ext2fs_initialize_dirent_tail(ext2_filsys fs,
       struct ext2_dir_entry_tail *t);
extern int ext2fs_dirent_has_tail(ext2_filsys fs,
      struct ext2_dir_entry *dirent);
extern int ext2fs_dirent_csum_verify(ext2_filsys fs, ext2_ino_t inum,
         struct ext2_dir_entry *dirent);
extern int ext2fs_dir_block_csum_verify(ext2_filsys fs, ext2_ino_t inum,
     struct ext2_dir_entry *dirent);
extern errcode_t ext2fs_dir_block_csum_set(ext2_filsys fs, ext2_ino_t inum,
        struct ext2_dir_entry *dirent);
extern errcode_t ext2fs_get_dx_countlimit(ext2_filsys fs,
       struct ext2_dir_entry *dirent,
       struct ext2_dx_countlimit **cc,
       int *offset);
extern errcode_t ext2fs_dx_csum(ext2_filsys fs, ext2_ino_t inum,
    struct ext2_dir_entry *dirent,
    __u32 *crc, struct ext2_dx_tail **ret_t);
extern errcode_t ext2fs_extent_block_csum_set(ext2_filsys fs,
           ext2_ino_t inum,
           struct ext3_extent_header *eh);
extern int ext2fs_extent_block_csum_verify(ext2_filsys fs,
        ext2_ino_t inum,
        struct ext3_extent_header *eh);
extern errcode_t ext2fs_block_bitmap_csum_set(ext2_filsys fs, dgrp_t group,
           char *bitmap, int size);
extern int ext2fs_block_bitmap_csum_verify(ext2_filsys fs, dgrp_t group,
        char *bitmap, int size);
extern errcode_t ext2fs_inode_bitmap_csum_set(ext2_filsys fs, dgrp_t group,
           char *bitmap, int size);
extern int ext2fs_inode_bitmap_csum_verify(ext2_filsys fs, dgrp_t group,
        char *bitmap, int size);
extern errcode_t ext2fs_inode_csum_set(ext2_filsys fs, ext2_ino_t inum,
           struct ext2_inode_large *inode);
extern int ext2fs_inode_csum_verify(ext2_filsys fs, ext2_ino_t inum,
        struct ext2_inode_large *inode);
extern void ext2fs_group_desc_csum_set(ext2_filsys fs, dgrp_t group);
extern int ext2fs_group_desc_csum_verify(ext2_filsys fs, dgrp_t group);
extern errcode_t ext2fs_set_gdt_csum(ext2_filsys fs);
extern __u16 ext2fs_group_desc_csum(ext2_filsys fs, dgrp_t group);


extern errcode_t ext2fs_init_dblist(ext2_filsys fs, ext2_dblist *ret_dblist);
extern errcode_t ext2fs_add_dir_block(ext2_dblist dblist, ext2_ino_t ino,
          blk_t blk, int blockcnt);
extern errcode_t ext2fs_add_dir_block2(ext2_dblist dblist, ext2_ino_t ino,
           blk64_t blk, e2_blkcnt_t blockcnt);
extern void ext2fs_dblist_sort(ext2_dblist dblist,
          int (*sortfunc)(const void *,
          const void *));
extern void ext2fs_dblist_sort2(ext2_dblist dblist,
    int (*sortfunc)(const void *,
           const void *));
extern errcode_t ext2fs_dblist_iterate(ext2_dblist dblist,
 int (*func)(ext2_filsys fs, struct ext2_db_entry *db_info,
      void *priv_data),
 void *priv_data);
extern errcode_t ext2fs_dblist_iterate2(ext2_dblist dblist,
 int (*func)(ext2_filsys fs, struct ext2_db_entry2 *db_info,
      void *priv_data),
 void *priv_data);
extern errcode_t ext2fs_dblist_iterate3(ext2_dblist dblist,
 int (*func)(ext2_filsys fs, struct ext2_db_entry2 *db_info,
      void *priv_data),
 unsigned long long start,
 unsigned long long count,
 void *priv_data);
extern errcode_t ext2fs_set_dir_block(ext2_dblist dblist, ext2_ino_t ino,
          blk_t blk, int blockcnt);
extern errcode_t ext2fs_set_dir_block2(ext2_dblist dblist, ext2_ino_t ino,
           blk64_t blk, e2_blkcnt_t blockcnt);
extern errcode_t ext2fs_copy_dblist(ext2_dblist src,
        ext2_dblist *dest);
extern int ext2fs_dblist_count(ext2_dblist dblist);
extern blk64_t ext2fs_dblist_count2(ext2_dblist dblist);
extern errcode_t ext2fs_dblist_get_last(ext2_dblist dblist,
     struct ext2_db_entry **entry);
extern errcode_t ext2fs_dblist_get_last2(ext2_dblist dblist,
     struct ext2_db_entry2 **entry);
extern errcode_t ext2fs_dblist_drop_last(ext2_dblist dblist);


extern errcode_t
 ext2fs_dblist_dir_iterate(ext2_dblist dblist,
      int flags,
      char *block_buf,
      int (*func)(ext2_ino_t dir,
           int entry,
           struct ext2_dir_entry *dirent,
           int offset,
           int blocksize,
           char *buf,
           void *priv_data),
      void *priv_data);
extern errcode_t ext2fs_read_dir_block(ext2_filsys fs, blk_t block,
           void *buf);
extern errcode_t ext2fs_read_dir_block2(ext2_filsys fs, blk_t block,
     void *buf, int flags);
extern errcode_t ext2fs_read_dir_block3(ext2_filsys fs, blk64_t block,
     void *buf, int flags);
extern errcode_t ext2fs_read_dir_block4(ext2_filsys fs, blk64_t block,
     void *buf, int flags, ext2_ino_t ino);
extern errcode_t ext2fs_write_dir_block(ext2_filsys fs, blk_t block,
     void *buf);
extern errcode_t ext2fs_write_dir_block2(ext2_filsys fs, blk_t block,
      void *buf, int flags);
extern errcode_t ext2fs_write_dir_block3(ext2_filsys fs, blk64_t block,
      void *buf, int flags);
extern errcode_t ext2fs_write_dir_block4(ext2_filsys fs, blk64_t block,
      void *buf, int flags, ext2_ino_t ino);


extern errcode_t ext2fs_dirhash(int version, const char *name, int len,
    const __u32 *seed,
    ext2_dirhash_t *ret_hash,
    ext2_dirhash_t *ret_minor_hash);

extern errcode_t ext2fs_dirhash2(int version, const char *name, int len,
     const struct ext2fs_nls_table *charset,
     int hash_flags,
     const __u32 *seed,
     ext2_dirhash_t *ret_hash,
     ext2_dirhash_t *ret_minor_hash);


extern errcode_t ext2fs_get_rec_len(ext2_filsys fs,
        struct ext2_dir_entry *dirent,
        unsigned int *rec_len);
extern errcode_t ext2fs_set_rec_len(ext2_filsys fs,
        unsigned int len,
        struct ext2_dir_entry *dirent);
extern errcode_t ext2fs_dir_iterate(ext2_filsys fs,
         ext2_ino_t dir,
         int flags,
         char *block_buf,
         int (*func)(struct ext2_dir_entry *dirent,
       int offset,
       int blocksize,
       char *buf,
       void *priv_data),
         void *priv_data);
extern errcode_t ext2fs_dir_iterate2(ext2_filsys fs,
         ext2_ino_t dir,
         int flags,
         char *block_buf,
         int (*func)(ext2_ino_t dir,
       int entry,
       struct ext2_dir_entry *dirent,
       int offset,
       int blocksize,
       char *buf,
       void *priv_data),
         void *priv_data);


extern errcode_t ext2fs_dup_handle(ext2_filsys src, ext2_filsys *dest);


extern errcode_t ext2fs_expand_dir(ext2_filsys fs, ext2_ino_t dir);


extern __u32 ext2fs_ext_attr_hash_entry(struct ext2_ext_attr_entry *entry,
     void *data);
extern errcode_t ext2fs_ext_attr_hash_entry2(ext2_filsys fs,
          struct ext2_ext_attr_entry *entry,
          void *data, __u32 *hash);
extern errcode_t ext2fs_read_ext_attr(ext2_filsys fs, blk_t block, void *buf);
extern errcode_t ext2fs_read_ext_attr2(ext2_filsys fs, blk64_t block,
           void *buf);
extern errcode_t ext2fs_read_ext_attr3(ext2_filsys fs, blk64_t block,
           void *buf, ext2_ino_t inum);
extern errcode_t ext2fs_write_ext_attr(ext2_filsys fs, blk_t block,
           void *buf);
extern errcode_t ext2fs_write_ext_attr2(ext2_filsys fs, blk64_t block,
           void *buf);
extern errcode_t ext2fs_write_ext_attr3(ext2_filsys fs, blk64_t block,
           void *buf, ext2_ino_t inum);
extern errcode_t ext2fs_adjust_ea_refcount(ext2_filsys fs, blk_t blk,
        char *block_buf,
        int adjust, __u32 *newcount);
extern errcode_t ext2fs_adjust_ea_refcount2(ext2_filsys fs, blk64_t blk,
        char *block_buf,
        int adjust, __u32 *newcount);
extern errcode_t ext2fs_adjust_ea_refcount3(ext2_filsys fs, blk64_t blk,
        char *block_buf,
        int adjust, __u32 *newcount,
        ext2_ino_t inum);
errcode_t ext2fs_xattrs_write(struct ext2_xattr_handle *handle);
errcode_t ext2fs_xattrs_read(struct ext2_xattr_handle *handle);
errcode_t ext2fs_xattrs_iterate(struct ext2_xattr_handle *h,
    int (*func)(char *name, char *value,
         size_t value_len, void *data),
    void *data);
errcode_t ext2fs_xattr_get(struct ext2_xattr_handle *h, const char *key,
      void **value, size_t *value_len);
errcode_t ext2fs_xattr_set(struct ext2_xattr_handle *handle,
      const char *key,
      const void *value,
      size_t value_len);
errcode_t ext2fs_xattr_remove(struct ext2_xattr_handle *handle,
         const char *key);
errcode_t ext2fs_xattrs_open(ext2_filsys fs, ext2_ino_t ino,
        struct ext2_xattr_handle **handle);
errcode_t ext2fs_xattrs_close(struct ext2_xattr_handle **handle);
errcode_t ext2fs_free_ext_attr(ext2_filsys fs, ext2_ino_t ino,
          struct ext2_inode_large *inode);
errcode_t ext2fs_xattrs_count(struct ext2_xattr_handle *handle, size_t *count);
errcode_t ext2fs_xattr_inode_max_size(ext2_filsys fs, ext2_ino_t ino,
          size_t *size);

errcode_t ext2fs_xattrs_flags(struct ext2_xattr_handle *handle,
         unsigned int *new_flags, unsigned int *old_flags);
extern void ext2fs_ext_attr_block_rehash(struct ext2_ext_attr_header *header,
      struct ext2_ext_attr_entry *end);
extern __u32 ext2fs_get_ea_inode_hash(struct ext2_inode *inode);
extern void ext2fs_set_ea_inode_hash(struct ext2_inode *inode, __u32 hash);
extern __u64 ext2fs_get_ea_inode_ref(struct ext2_inode *inode);
extern void ext2fs_set_ea_inode_ref(struct ext2_inode *inode, __u64 ref_count);


extern errcode_t ext2fs_extent_header_verify(void *ptr, int size);
extern errcode_t ext2fs_extent_open(ext2_filsys fs, ext2_ino_t ino,
        ext2_extent_handle_t *handle);
extern errcode_t ext2fs_extent_open2(ext2_filsys fs, ext2_ino_t ino,
     struct ext2_inode *inode,
     ext2_extent_handle_t *ret_handle);
extern void ext2fs_extent_free(ext2_extent_handle_t handle);
extern errcode_t ext2fs_extent_get(ext2_extent_handle_t handle,
       int flags, struct ext2fs_extent *extent);
extern errcode_t ext2fs_extent_node_split(ext2_extent_handle_t handle);
extern errcode_t ext2fs_extent_replace(ext2_extent_handle_t handle, int flags,
           struct ext2fs_extent *extent);
extern errcode_t ext2fs_extent_insert(ext2_extent_handle_t handle, int flags,
          struct ext2fs_extent *extent);
extern errcode_t ext2fs_extent_set_bmap(ext2_extent_handle_t handle,
     blk64_t logical, blk64_t physical,
     int flags);
extern errcode_t ext2fs_extent_delete(ext2_extent_handle_t handle, int flags);
extern errcode_t ext2fs_extent_get_info(ext2_extent_handle_t handle,
     struct ext2_extent_info *info);
extern errcode_t ext2fs_extent_goto(ext2_extent_handle_t handle,
        blk64_t blk);
extern errcode_t ext2fs_extent_goto2(ext2_extent_handle_t handle,
         int leaf_level, blk64_t blk);
extern errcode_t ext2fs_extent_fix_parents(ext2_extent_handle_t handle);
extern size_t ext2fs_max_extent_depth(ext2_extent_handle_t handle);
extern errcode_t ext2fs_fix_extents_checksums(ext2_filsys fs, ext2_ino_t ino,
           struct ext2_inode *inode);
extern errcode_t ext2fs_count_blocks(ext2_filsys fs, ext2_ino_t ino,
         struct ext2_inode *inode, blk64_t *ret_count);
extern errcode_t ext2fs_decode_extent(struct ext2fs_extent *to, void *from,
          int len);







errcode_t ext2fs_fallocate(ext2_filsys fs, int flags, ext2_ino_t ino,
      struct ext2_inode *inode, blk64_t goal,
      blk64_t start, blk64_t len);


extern errcode_t ext2fs_file_open2(ext2_filsys fs, ext2_ino_t ino,
       struct ext2_inode *inode,
       int flags, ext2_file_t *ret);
extern errcode_t ext2fs_file_open(ext2_filsys fs, ext2_ino_t ino,
      int flags, ext2_file_t *ret);
extern ext2_filsys ext2fs_file_get_fs(ext2_file_t file);
struct ext2_inode *ext2fs_file_get_inode(ext2_file_t file);
extern ext2_ino_t ext2fs_file_get_inode_num(ext2_file_t file);
extern errcode_t ext2fs_file_close(ext2_file_t file);
extern errcode_t ext2fs_file_flush(ext2_file_t file);
extern errcode_t ext2fs_file_read(ext2_file_t file, void *buf,
      unsigned int wanted, unsigned int *got);
extern errcode_t ext2fs_file_write(ext2_file_t file, const void *buf,
       unsigned int nbytes, unsigned int *written);
extern errcode_t ext2fs_file_llseek(ext2_file_t file, __u64 offset,
       int whence, __u64 *ret_pos);
extern errcode_t ext2fs_file_lseek(ext2_file_t file, ext2_off_t offset,
       int whence, ext2_off_t *ret_pos);
errcode_t ext2fs_file_get_lsize(ext2_file_t file, __u64 *ret_size);
extern ext2_off_t ext2fs_file_get_size(ext2_file_t file);
extern errcode_t ext2fs_file_set_size(ext2_file_t file, ext2_off_t size);
extern errcode_t ext2fs_file_set_size2(ext2_file_t file, ext2_off64_t size);


extern char *ext2fs_find_block_device(dev_t device);


extern errcode_t ext2fs_sync_device(int fd, int flushb);


extern void ext2fs_free(ext2_filsys fs);
extern void ext2fs_free_dblist(ext2_dblist dblist);
extern void ext2fs_badblocks_list_free(ext2_badblocks_list bb);
extern void ext2fs_u32_list_free(ext2_u32_list bb);


extern void ext2fs_free_generic_bitmap(ext2fs_inode_bitmap bitmap);
extern errcode_t ext2fs_make_generic_bitmap(errcode_t magic, ext2_filsys fs,
         __u32 start, __u32 end,
         __u32 real_end,
         const char *descr, char *init_map,
         ext2fs_generic_bitmap *ret);
extern errcode_t ext2fs_allocate_generic_bitmap(__u32 start,
      __u32 end,
      __u32 real_end,
      const char *descr,
      ext2fs_generic_bitmap *ret);
extern errcode_t ext2fs_copy_generic_bitmap(ext2fs_generic_bitmap src,
         ext2fs_generic_bitmap *dest);
extern void ext2fs_clear_generic_bitmap(ext2fs_generic_bitmap bitmap);
extern errcode_t ext2fs_fudge_generic_bitmap_end(ext2fs_inode_bitmap bitmap,
       errcode_t magic,
       errcode_t neq,
       ext2_ino_t end,
       ext2_ino_t *oend);
extern void ext2fs_set_generic_bitmap_padding(ext2fs_generic_bitmap map);
extern errcode_t ext2fs_resize_generic_bitmap(errcode_t magic,
           __u32 new_end,
           __u32 new_real_end,
           ext2fs_generic_bitmap bmap);
extern errcode_t ext2fs_compare_generic_bitmap(errcode_t magic, errcode_t neq,
            ext2fs_generic_bitmap bm1,
            ext2fs_generic_bitmap bm2);
extern errcode_t ext2fs_get_generic_bitmap_range(ext2fs_generic_bitmap bmap,
       errcode_t magic,
       __u32 start, __u32 num,
       void *out);
extern errcode_t ext2fs_set_generic_bitmap_range(ext2fs_generic_bitmap bmap,
       errcode_t magic,
       __u32 start, __u32 num,
       void *in);
extern errcode_t ext2fs_find_first_zero_generic_bitmap(ext2fs_generic_bitmap bitmap,
             __u32 start, __u32 end,
             __u32 *out);
extern errcode_t ext2fs_find_first_set_generic_bitmap(ext2fs_generic_bitmap bitmap,
             __u32 start, __u32 end,
             __u32 *out);


void ext2fs_free_generic_bmap(ext2fs_generic_bitmap bmap);
errcode_t ext2fs_alloc_generic_bmap(ext2_filsys fs, errcode_t magic,
        int type, __u64 start, __u64 end,
        __u64 real_end,
        const char *descr,
        ext2fs_generic_bitmap *ret);
errcode_t ext2fs_copy_generic_bmap(ext2fs_generic_bitmap src,
       ext2fs_generic_bitmap *dest);
void ext2fs_clear_generic_bmap(ext2fs_generic_bitmap bitmap);
errcode_t ext2fs_fudge_generic_bmap_end(ext2fs_generic_bitmap bitmap,
     errcode_t neq,
     __u64 end, __u64 *oend);
void ext2fs_set_generic_bmap_padding(ext2fs_generic_bitmap bmap);
errcode_t ext2fs_resize_generic_bmap(ext2fs_generic_bitmap bmap,
         __u64 new_end,
         __u64 new_real_end);
errcode_t ext2fs_compare_generic_bmap(errcode_t neq,
          ext2fs_generic_bitmap bm1,
          ext2fs_generic_bitmap bm2);
errcode_t ext2fs_get_generic_bmap_range(ext2fs_generic_bitmap bmap,
     __u64 start, unsigned int num,
     void *out);
errcode_t ext2fs_set_generic_bmap_range(ext2fs_generic_bitmap bmap,
     __u64 start, unsigned int num,
     void *in);
errcode_t ext2fs_convert_subcluster_bitmap(ext2_filsys fs,
        ext2fs_block_bitmap *bitmap);
errcode_t ext2fs_count_used_clusters(ext2_filsys fs, blk64_t start,
         blk64_t end, blk64_t *out);


extern errcode_t ext2fs_get_num_dirs(ext2_filsys fs, ext2_ino_t *ret_num_dirs);


extern errcode_t ext2fs_get_device_size(const char *file, int blocksize,
     blk_t *retblocks);
extern errcode_t ext2fs_get_device_size2(const char *file, int blocksize,
     blk64_t *retblocks);


extern int ext2fs_get_dio_alignment(int fd);
errcode_t ext2fs_get_device_sectsize(const char *file, int *sectsize);
errcode_t ext2fs_get_device_phys_sectsize(const char *file, int *sectsize);


errcode_t ext2fs_iblk_add_blocks(ext2_filsys fs, struct ext2_inode *inode,
     blk64_t num_blocks);
errcode_t ext2fs_iblk_sub_blocks(ext2_filsys fs, struct ext2_inode *inode,
     blk64_t num_blocks);
errcode_t ext2fs_iblk_set(ext2_filsys fs, struct ext2_inode *inode, blk64_t b);


extern errcode_t ext2fs_image_inode_write(ext2_filsys fs, int fd, int flags);
extern errcode_t ext2fs_image_inode_read(ext2_filsys fs, int fd, int flags);
extern errcode_t ext2fs_image_super_write(ext2_filsys fs, int fd, int flags);
extern errcode_t ext2fs_image_super_read(ext2_filsys fs, int fd, int flags);
extern errcode_t ext2fs_image_bitmap_write(ext2_filsys fs, int fd, int flags);
extern errcode_t ext2fs_image_bitmap_read(ext2_filsys fs, int fd, int flags);


errcode_t ext2fs_read_ind_block(ext2_filsys fs, blk_t blk, void *buf);
errcode_t ext2fs_write_ind_block(ext2_filsys fs, blk_t blk, void *buf);


extern errcode_t ext2fs_initialize(const char *name, int flags,
       struct ext2_super_block *param,
       io_manager manager, ext2_filsys *ret_fs);
extern errcode_t ext2fs_calculate_summary_stats(ext2_filsys fs, int super_only);


extern void ext2fs_free_icount(ext2_icount_t icount);
extern errcode_t ext2fs_create_icount_tdb(ext2_filsys fs, char *tdb_dir,
       int flags, ext2_icount_t *ret);
extern errcode_t ext2fs_create_icount2(ext2_filsys fs, int flags,
           unsigned int size,
           ext2_icount_t hint, ext2_icount_t *ret);
extern errcode_t ext2fs_create_icount(ext2_filsys fs, int flags,
          unsigned int size,
          ext2_icount_t *ret);
extern errcode_t ext2fs_icount_fetch(ext2_icount_t icount, ext2_ino_t ino,
         __u16 *ret);
extern errcode_t ext2fs_icount_increment(ext2_icount_t icount, ext2_ino_t ino,
      __u16 *ret);
extern errcode_t ext2fs_icount_decrement(ext2_icount_t icount, ext2_ino_t ino,
      __u16 *ret);
extern errcode_t ext2fs_icount_store(ext2_icount_t icount, ext2_ino_t ino,
         __u16 count);
extern ext2_ino_t ext2fs_get_icount_size(ext2_icount_t icount);
errcode_t ext2fs_icount_validate(ext2_icount_t icount, FILE *);



extern errcode_t ext2fs_get_memalign(unsigned long size,
         unsigned long align, void *ptr);


extern errcode_t ext2fs_inline_data_init(ext2_filsys fs, ext2_ino_t ino);
extern errcode_t ext2fs_inline_data_size(ext2_filsys fs, ext2_ino_t ino,
      size_t *size);
extern errcode_t ext2fs_inline_data_get(ext2_filsys fs, ext2_ino_t ino,
     struct ext2_inode *inode,
     void *buf, size_t *size);
extern errcode_t ext2fs_inline_data_set(ext2_filsys fs, ext2_ino_t ino,
     struct ext2_inode *inode,
     void *buf, size_t size);


extern errcode_t ext2fs_create_inode_cache(ext2_filsys fs,
        unsigned int cache_size);
extern void ext2fs_free_inode_cache(struct ext2_inode_cache *icache);
extern errcode_t ext2fs_flush_icache(ext2_filsys fs);
extern errcode_t ext2fs_get_next_inode_full(ext2_inode_scan scan,
         ext2_ino_t *ino,
         struct ext2_inode *inode,
         int bufsize);

extern errcode_t ext2fs_open_inode_scan(ext2_filsys fs, int buffer_blocks,
      ext2_inode_scan *ret_scan);
extern void ext2fs_close_inode_scan(ext2_inode_scan scan);
extern errcode_t ext2fs_get_next_inode(ext2_inode_scan scan, ext2_ino_t *ino,
          struct ext2_inode *inode);
extern errcode_t ext2fs_inode_scan_goto_blockgroup(ext2_inode_scan scan,
         int group);
extern void ext2fs_set_inode_callback
 (ext2_inode_scan scan,
  errcode_t (*done_group)(ext2_filsys fs,
     ext2_inode_scan scan,
     dgrp_t group,
     void * priv_data),
  void *done_group_data);
extern int ext2fs_inode_scan_flags(ext2_inode_scan scan, int set_flags,
       int clear_flags);
extern errcode_t ext2fs_read_inode_full(ext2_filsys fs, ext2_ino_t ino,
     struct ext2_inode * inode,
     int bufsize);
extern errcode_t ext2fs_read_inode(ext2_filsys fs, ext2_ino_t ino,
       struct ext2_inode * inode);
extern errcode_t ext2fs_read_inode2(ext2_filsys fs, ext2_ino_t ino,
        struct ext2_inode * inode,
        int bufsize, int flags);
extern errcode_t ext2fs_write_inode_full(ext2_filsys fs, ext2_ino_t ino,
      struct ext2_inode * inode,
      int bufsize);
extern errcode_t ext2fs_write_inode(ext2_filsys fs, ext2_ino_t ino,
       struct ext2_inode * inode);
extern errcode_t ext2fs_write_inode2(ext2_filsys fs, ext2_ino_t ino,
         struct ext2_inode * inode,
         int bufsize, int flags);
extern errcode_t ext2fs_write_new_inode(ext2_filsys fs, ext2_ino_t ino,
       struct ext2_inode * inode);
extern errcode_t ext2fs_get_blocks(ext2_filsys fs, ext2_ino_t ino, blk_t *blocks);
extern errcode_t ext2fs_check_directory(ext2_filsys fs, ext2_ino_t ino);


extern io_manager inode_io_manager;
extern errcode_t ext2fs_inode_io_intern(ext2_filsys fs, ext2_ino_t ino,
     char **name);
extern errcode_t ext2fs_inode_io_intern2(ext2_filsys fs, ext2_ino_t ino,
      struct ext2_inode *inode,
      char **name);


extern errcode_t ext2fs_check_if_mounted(const char *file, int *mount_flags);
extern errcode_t ext2fs_check_mount_point(const char *device, int *mount_flags,
       char *mtpt, int mtlen);






extern errcode_t ext2fs_punch(ext2_filsys fs, ext2_ino_t ino,
         struct ext2_inode *inode,
         char *block_buf, blk64_t start,
         blk64_t end);


extern errcode_t ext2fs_lookup(ext2_filsys fs, ext2_ino_t dir, const char *name,
    int namelen, char *buf, ext2_ino_t *inode);
extern errcode_t ext2fs_namei(ext2_filsys fs, ext2_ino_t root, ext2_ino_t cwd,
   const char *name, ext2_ino_t *inode);
errcode_t ext2fs_namei_follow(ext2_filsys fs, ext2_ino_t root, ext2_ino_t cwd,
         const char *name, ext2_ino_t *inode);
extern errcode_t ext2fs_follow_link(ext2_filsys fs, ext2_ino_t root, ext2_ino_t cwd,
   ext2_ino_t inode, ext2_ino_t *res_inode);


int ext2fs_native_flag(void);


extern errcode_t ext2fs_new_dir_block(ext2_filsys fs, ext2_ino_t dir_ino,
    ext2_ino_t parent_ino, char **block);
extern errcode_t ext2fs_new_dir_inline_data(ext2_filsys fs, ext2_ino_t dir_ino,
    ext2_ino_t parent_ino, __u32 *iblock);


extern const struct ext2fs_nls_table *ext2fs_load_nls_table(int encoding);
extern int ext2fs_check_encoded_name(const struct ext2fs_nls_table *table,
         char *s, size_t len, char **pos);
extern int ext2fs_casefold_cmp(const struct ext2fs_nls_table *table,
          const unsigned char *str1, size_t len1,
          const unsigned char *str2, size_t len2);


extern errcode_t ext2fs_mkdir(ext2_filsys fs, ext2_ino_t parent, ext2_ino_t inum,
         const char *name);


struct ext2fs_journal_params {
 blk_t num_journal_blocks;
 blk_t num_fc_blocks;
};
extern errcode_t ext2fs_get_journal_params(
  struct ext2fs_journal_params *params, ext2_filsys fs);
extern errcode_t ext2fs_zero_blocks(ext2_filsys fs, blk_t blk, int num,
        blk_t *ret_blk, int *ret_count);
extern errcode_t ext2fs_zero_blocks2(ext2_filsys fs, blk64_t blk, int num,
         blk64_t *ret_blk, int *ret_count);
extern errcode_t ext2fs_create_journal_superblock(ext2_filsys fs,
        __u32 num_blocks, int flags,
        char **ret_jsb);
extern errcode_t ext2fs_create_journal_superblock2(ext2_filsys fs,
        struct ext2fs_journal_params *params,
        int flags, char **ret_jsb);
extern errcode_t ext2fs_add_journal_device(ext2_filsys fs,
        ext2_filsys journal_dev);
extern errcode_t ext2fs_add_journal_inode(ext2_filsys fs, blk_t num_blocks,
       int flags);
extern errcode_t ext2fs_add_journal_inode2(ext2_filsys fs, blk_t num_blocks,
        blk64_t goal, int flags);
extern errcode_t ext2fs_add_journal_inode3(ext2_filsys fs,
        struct ext2fs_journal_params *params,
        blk64_t goal, int flags);
extern int ext2fs_default_journal_size(__u64 num_blocks);
extern int ext2fs_journal_sb_start(int blocksize);


extern errcode_t ext2fs_open(const char *name, int flags, int superblock,
        unsigned int block_size, io_manager manager,
        ext2_filsys *ret_fs);
extern errcode_t ext2fs_open2(const char *name, const char *io_options,
         int flags, int superblock,
         unsigned int block_size, io_manager manager,
         ext2_filsys *ret_fs);





extern blk64_t ext2fs_descriptor_block_loc2(ext2_filsys fs,
     blk64_t group_block, dgrp_t i);
extern blk_t ext2fs_descriptor_block_loc(ext2_filsys fs, blk_t group_block,
      dgrp_t i);
errcode_t ext2fs_get_data_io(ext2_filsys fs, io_channel *old_io);
errcode_t ext2fs_set_data_io(ext2_filsys fs, io_channel new_io);
errcode_t ext2fs_rewrite_to_io(ext2_filsys fs, io_channel new_io);


extern errcode_t ext2fs_get_pathname(ext2_filsys fs, ext2_ino_t dir, ext2_ino_t ino,
          char **name);






errcode_t ext2fs_link(ext2_filsys fs, ext2_ino_t dir, const char *name,
        ext2_ino_t ino, int flags);
errcode_t ext2fs_unlink(ext2_filsys fs, ext2_ino_t dir, const char *name,
   ext2_ino_t ino, int flags);


errcode_t ext2fs_symlink(ext2_filsys fs, ext2_ino_t parent, ext2_ino_t ino,
    const char *name, const char *target);
int ext2fs_is_fast_symlink(struct ext2_inode *inode);


errcode_t ext2fs_mmp_read(ext2_filsys fs, blk64_t mmp_blk, void *buf);
errcode_t ext2fs_mmp_write(ext2_filsys fs, blk64_t mmp_blk, void *buf);
errcode_t ext2fs_mmp_clear(ext2_filsys fs);
errcode_t ext2fs_mmp_init(ext2_filsys fs);
errcode_t ext2fs_mmp_start(ext2_filsys fs);
errcode_t ext2fs_mmp_update(ext2_filsys fs);
errcode_t ext2fs_mmp_update2(ext2_filsys fs, int immediately);
errcode_t ext2fs_mmp_stop(ext2_filsys fs);
unsigned ext2fs_mmp_new_seq(void);


extern errcode_t ext2fs_read_bb_inode(ext2_filsys fs,
          ext2_badblocks_list *bb_list);


extern errcode_t ext2fs_read_bb_FILE2(ext2_filsys fs, FILE *f,
          ext2_badblocks_list *bb_list,
          void *priv_data,
          void (*invalid)(ext2_filsys fs,
            blk_t blk,
            char *badstr,
            void *priv_data));
extern errcode_t ext2fs_read_bb_FILE(ext2_filsys fs, FILE *f,
         ext2_badblocks_list *bb_list,
         void (*invalid)(ext2_filsys fs,
           blk_t blk));


extern errcode_t ext2fs_create_resize_inode(ext2_filsys fs);


extern errcode_t ext2fs_rw_bitmaps(ext2_filsys fs, int flags, int num_threads);
extern errcode_t ext2fs_read_bitmaps(ext2_filsys fs);
extern errcode_t ext2fs_read_inode_bitmap (ext2_filsys fs);
extern errcode_t ext2fs_read_block_bitmap(ext2_filsys fs);
extern errcode_t ext2fs_write_bitmaps(ext2_filsys fs);
extern errcode_t ext2fs_write_inode_bitmap(ext2_filsys fs);
extern errcode_t ext2fs_write_block_bitmap (ext2_filsys fs);
extern void ext2fs_sha512(const unsigned char *in, unsigned long in_size,
     unsigned char out[64]);


extern errcode_t ext2fs_dirent_swab_in2(ext2_filsys fs, char *buf, size_t size,
     int flags);
extern errcode_t ext2fs_dirent_swab_in(ext2_filsys fs, char *buf, int flags);
extern errcode_t ext2fs_dirent_swab_out2(ext2_filsys fs, char *buf, size_t size,
      int flags);
extern errcode_t ext2fs_dirent_swab_out(ext2_filsys fs, char *buf, int flags);
extern void ext2fs_swap_ext_attr(char *to, char *from, int bufsize,
     int has_header);
extern void ext2fs_swap_ext_attr_header(struct ext2_ext_attr_header *to_header,
     struct ext2_ext_attr_header *from_hdr);
extern void ext2fs_swap_ext_attr_entry(struct ext2_ext_attr_entry *to_entry,
           struct ext2_ext_attr_entry *from_entry);
extern void ext2fs_swap_super(struct ext2_super_block * super);
extern void ext2fs_swap_group_desc(struct ext2_group_desc *gdp);
extern void ext2fs_swap_group_desc2(ext2_filsys, struct ext2_group_desc *gdp);
extern void ext2fs_swap_inode_full(ext2_filsys fs, struct ext2_inode_large *t,
       struct ext2_inode_large *f, int hostorder,
       int bufsize);
extern void ext2fs_swap_inode(ext2_filsys fs,struct ext2_inode *t,
         struct ext2_inode *f, int hostorder);
extern void ext2fs_swap_mmp(struct mmp_struct *mmp);


extern int ext2fs_open_file(const char *pathname, int flags, mode_t mode);
extern int ext2fs_stat(const char *path, ext2fs_struct_stat *buf);
extern int ext2fs_fstat(int fd, ext2fs_struct_stat *buf);


extern int ext2fs_inode_has_valid_blocks(struct ext2_inode *inode);
extern int ext2fs_inode_has_valid_blocks2(ext2_filsys fs,
       struct ext2_inode *inode);


extern int ext2fs_parse_version_string(const char *ver_string);
extern int ext2fs_get_library_version(const char **ver_string,
          const char **date_string);


extern errcode_t ext2fs_write_bb_FILE(ext2_badblocks_list bb_list,
          unsigned int flags,
          FILE *f);
inline errcode_t ext2fs_get_mem(unsigned long size, void *ptr)
{
 void *pp;

 pp = malloc(size);
 if (!pp)
  return (2133571398L);
 memcpy(ptr, &pp, sizeof (pp));
 return 0;
}

inline errcode_t ext2fs_get_memzero(unsigned long size, void *ptr)
{
 void *pp;

 pp = malloc(size);
 if (!pp)
  return (2133571398L);
 memset(pp, 0, size);
 memcpy(ptr, &pp, sizeof(pp));
 return 0;
}

inline errcode_t ext2fs_get_array(unsigned long count, unsigned long size,
        void *ptr)
{
 if (count && (~0UL)/count < size)
  return (2133571398L);
 return ext2fs_get_mem(count*size, ptr);
}

inline errcode_t ext2fs_get_arrayzero(unsigned long count,
     unsigned long size, void *ptr)
{
 if (count && (~0UL)/count < size)
  return (2133571398L);

 return ext2fs_get_memzero((size_t)count * size, ptr);
}




inline errcode_t ext2fs_free_mem(void *ptr)
{
 void *p;

 memcpy(&p, ptr, sizeof(p));
 free(p);
 p = 0;
 memcpy(ptr, &p, sizeof(p));
 return 0;
}




inline errcode_t ext2fs_resize_mem(unsigned long __attribute__((unused)) old_size,
         unsigned long size, void *ptr)
{
 void *p;



 memcpy(&p, ptr, sizeof(p));
 p = realloc(p, size);
 if (!p)
  return (2133571398L);
 memcpy(ptr, &p, sizeof(p));
 return 0;
}




inline errcode_t ext2fs_resize_array(unsigned long size,
           unsigned long old_count,
           unsigned long count, void *ptr)
{
 unsigned long old_size;
 errcode_t retval;

 if (count && (~0UL)/count < size)
  return (2133571398L);

 size *= count;
 old_size = size * old_count;
 retval = ext2fs_resize_mem(old_size, size, ptr);
 if (retval)
  return retval;

 if (size > old_size) {
  void *p;

  memcpy(&p, ptr, sizeof(p));
  memset((char *)p + old_size, 0, size - old_size);
  memcpy(ptr, &p, sizeof(p));
 }

 return 0;
}





inline void ext2fs_mark_super_dirty(ext2_filsys fs)
{
 fs->flags |= 0x04 | 0x02;
}




inline void ext2fs_mark_changed(ext2_filsys fs)
{
 fs->flags |= 0x02;
}




inline int ext2fs_test_changed(ext2_filsys fs)
{
 return (fs->flags & 0x02);
}




inline void ext2fs_mark_valid(ext2_filsys fs)
{
 fs->flags |= 0x08;
}




inline void ext2fs_unmark_valid(ext2_filsys fs)
{
 fs->flags &= ~0x08;
}




inline int ext2fs_test_valid(ext2_filsys fs)
{
 return (fs->flags & 0x08);
}




inline void ext2fs_mark_ib_dirty(ext2_filsys fs)
{
 fs->flags |= 0x10 | 0x02;
}




inline void ext2fs_mark_bb_dirty(ext2_filsys fs)
{
 fs->flags |= 0x20 | 0x02;
}




inline int ext2fs_test_ib_dirty(ext2_filsys fs)
{
 return (fs->flags & 0x10);
}




inline int ext2fs_test_bb_dirty(ext2_filsys fs)
{
 return (fs->flags & 0x20);
}




inline dgrp_t ext2fs_group_of_blk(ext2_filsys fs, blk_t blk)
{
 return ext2fs_group_of_blk2(fs, blk);
}



inline dgrp_t ext2fs_group_of_ino(ext2_filsys fs, ext2_ino_t ino)
{
 return (ino - 1) / fs->super->s_inodes_per_group;
}




inline blk_t ext2fs_group_first_block(ext2_filsys fs, dgrp_t group)
{
 return (blk_t) ext2fs_group_first_block2(fs, group);
}




inline blk_t ext2fs_group_last_block(ext2_filsys fs, dgrp_t group)
{
 return (blk_t) ext2fs_group_last_block2(fs, group);
}

inline blk_t ext2fs_inode_data_blocks(ext2_filsys fs,
     struct ext2_inode *inode)
{
 return (blk_t) ext2fs_inode_data_blocks2(fs, inode);
}

inline int ext2fs_htree_intnode_maxrecs(ext2_filsys fs, int blocks)
{
 int csum_size = 0;

 if (((fs->super)->s_feature_ro_compat &
      0x0400) != 0)
  csum_size = sizeof(struct ext2_dx_tail);
 return blocks * ((fs->blocksize - (8 + csum_size)) /
      sizeof(struct ext2_dx_entry));
}




inline unsigned int ext2fs_div_ceil(unsigned int a, unsigned int b)
{
 if (!a)
  return 0;
 return ((a - 1) / b) + 1;
}

inline __u64 ext2fs_div64_ceil(__u64 a, __u64 b)
{
 if (!a)
  return 0;
 return ((a - 1) / b) + 1;
}

inline int ext2fs_dirent_name_len(const struct ext2_dir_entry *entry)
{
 return entry->name_len & 0xff;
}

inline void ext2fs_dirent_set_name_len(struct ext2_dir_entry *entry, int len)
{
 entry->name_len = (entry->name_len & 0xff00) | (len & 0xff);
}

inline int ext2fs_dirent_file_type(const struct ext2_dir_entry *entry)
{
 return entry->name_len >> 8;
}

inline void ext2fs_dirent_set_file_type(struct ext2_dir_entry *entry, int type)
{
 entry->name_len = (entry->name_len & 0xff) | (type << 8);
}

inline struct ext2_inode *ext2fs_inode(struct ext2_inode_large * large_inode)
{

 return (struct ext2_inode *) large_inode;
}

inline const struct ext2_inode *
ext2fs_const_inode(const struct ext2_inode_large * large_inode)
{

 return (const struct ext2_inode *) large_inode;
}
static inline unsigned int ext2_dir_htree_level(ext2_filsys fs)
{
 if (ext2fs_has_feature_largedir(fs->super))
  return 3;

 return 2;
}



typedef struct _profile_t *profile_t;

typedef void (*profile_syntax_err_cb_t)(const char *file, long err,
     int line_num);
long profile_init
 (const char * const *files, profile_t *ret_profile);

void profile_release
 (profile_t profile);

long profile_set_default
 (profile_t profile, const char *def_string);

long profile_get_string
 (profile_t profile, const char *name, const char *subname,
   const char *subsubname, const char *def_val,
   char **ret_string);
long profile_get_integer
 (profile_t profile, const char *name, const char *subname,
   const char *subsubname, int def_val,
   int *ret_default);

long profile_get_uint
 (profile_t profile, const char *name, const char *subname,
  const char *subsubname, unsigned int def_val,
  unsigned int *ret_int);

long profile_get_double
 (profile_t profile, const char *name, const char *subname,
  const char *subsubname, double def_val,
  double *ret_float);

long profile_get_boolean
 (profile_t profile, const char *name, const char *subname,
   const char *subsubname, int def_val,
   int *ret_default);

long profile_iterator_create
 (profile_t profile, const char *const *names,
     int flags, void **ret_iter);

void profile_iterator_free
 (void **iter_p);

long profile_iterator
 (void **iter_p, char **ret_name, char **ret_value);

profile_syntax_err_cb_t profile_set_syntax_err_cb(profile_syntax_err_cb_t hook);





extern const struct error_table et_prof_error_table;
extern void initialize_prof_error_table(void);


extern void initialize_prof_error_table_r(struct et_list **list);







typedef __u32 qid_t;
struct qt_disk_dqdbheader {
 __le32 dqdh_next_free;

 __le32 dqdh_prev_free;

 __le16 dqdh_entries;
 __le16 dqdh_pad1;
 __le32 dqdh_pad2;
} __attribute__ ((packed));

struct dquot;
struct quota_handle;


struct qtree_fmt_operations {

 void (*mem2disk_dqblk)(void *disk, struct dquot *dquot);

 void (*disk2mem_dqblk)(struct dquot *dquot, void *disk);

 int (*is_id)(void *disk, struct dquot *dquot);
};


struct qtree_mem_dqinfo {
 unsigned int dqi_blocks;
 unsigned int dqi_free_blk;
 unsigned int dqi_free_entry;
 unsigned int dqi_entry_size;
 struct qtree_fmt_operations *dqi_ops;

};

void qtree_write_dquot(struct dquot *dquot);
struct dquot *qtree_read_dquot(struct quota_handle *h, qid_t id);
void qtree_delete_dquot(struct dquot *dquot);
int qtree_entry_unused(struct qtree_mem_dqinfo *info, char *disk);
int qtree_scan_dquots(struct quota_handle *h,
  int (*process_dquot) (struct dquot *, void *), void *data);

int qtree_dqstr_in_blk(struct qtree_mem_dqinfo *info);


struct v2_mem_dqinfo {
 struct qtree_mem_dqinfo dqi_qtree;
 unsigned int dqi_flags;
 unsigned int dqi_used_entries;

 unsigned int dqi_data_blocks;

};

struct v2_mem_dqblk {
 long long dqb_off;
};

struct quotafile_ops;


extern struct quotafile_ops quotafile_ops_2;

typedef int64_t qsize_t;

enum quota_type {
 USRQUOTA = 0,
 GRPQUOTA = 1,
 PRJQUOTA = 2,
 MAXQUOTAS = 3,
};
typedef struct quota_ctx *quota_ctx_t;
struct dict_t;

struct quota_ctx {
 ext2_filsys fs;
 struct dict_t *quota_dict[MAXQUOTAS];
 struct quota_handle *quota_file[MAXQUOTAS];
};
struct quotafile_ops;


struct util_dqinfo {
 time_t dqi_bgrace;
 time_t dqi_igrace;
 union {
  struct v2_mem_dqinfo v2_mdqi;
 } u;
};

struct quota_file {
 ext2_filsys fs;
 ext2_ino_t ino;
 ext2_file_t e2_file;
};


struct quota_handle {
 enum quota_type qh_type;
 int qh_fmt;
 int qh_file_flags;
 int qh_io_flags;
 struct quota_file qh_qf;
 unsigned int (*e2fs_read)(struct quota_file *qf, ext2_loff_t offset,
    void *buf, unsigned int size);
 unsigned int (*e2fs_write)(struct quota_file *qf, ext2_loff_t offset,
     void *buf, unsigned int size);
 struct quotafile_ops *qh_ops;
 struct util_dqinfo qh_info;
};


struct util_dqblk {
 qsize_t dqb_ihardlimit;
 qsize_t dqb_isoftlimit;
 qsize_t dqb_curinodes;
 qsize_t dqb_bhardlimit;
 qsize_t dqb_bsoftlimit;
 qsize_t dqb_curspace;
 time_t dqb_btime;
 time_t dqb_itime;
 union {
  struct v2_mem_dqblk v2_mdqb;
 } u;
};


struct dquot {
 struct dquot *dq_next;
 qid_t dq_id;
 int dq_flags;
 struct quota_handle *dq_h;
 struct util_dqblk dq_dqb;
};




struct quotafile_ops {

 int (*check_file) (struct quota_handle *h, int type, int fmt);

 int (*init_io) (struct quota_handle *h);

 int (*new_io) (struct quota_handle *h);

 int (*end_io) (struct quota_handle *h);

 int (*write_info) (struct quota_handle *h);

 struct dquot *(*read_dquot) (struct quota_handle *h, qid_t id);

 int (*commit_dquot) (struct dquot *dquot);

 int (*scan_dquots) (struct quota_handle *h,
       int (*process_dquot) (struct dquot *dquot,
        void *data),
       void *data);

 int (*report) (struct quota_handle *h, int verbose);
};


extern struct quotafile_ops quotafile_ops_meta;



errcode_t quota_file_open(quota_ctx_t qctx, struct quota_handle *h,
     ext2_ino_t qf_ino, enum quota_type type,
     int fmt, int flags);



errcode_t quota_file_create(struct quota_handle *h, ext2_filsys fs,
       enum quota_type qtype, int fmt);


errcode_t quota_file_close(quota_ctx_t qctx, struct quota_handle *h);


struct dquot *get_empty_dquot(void);

errcode_t quota_inode_truncate(ext2_filsys fs, ext2_ino_t ino);

const char *quota_type2name(enum quota_type qtype);
ext2_ino_t quota_type2inum(enum quota_type qtype, struct ext2_super_block *);

void update_grace_times(struct dquot *q);





const char *quota_get_qf_name(enum quota_type, int fmt, char *buf);


errcode_t quota_init_context(quota_ctx_t *qctx, ext2_filsys fs,
        unsigned int qtype_bits);
void quota_data_inodes(quota_ctx_t qctx, struct ext2_inode_large *inode,
         ext2_ino_t ino, int adjust);
void quota_data_add(quota_ctx_t qctx, struct ext2_inode_large *inode,
      ext2_ino_t ino, qsize_t space);
void quota_data_sub(quota_ctx_t qctx, struct ext2_inode_large *inode,
      ext2_ino_t ino, qsize_t space);
errcode_t quota_write_inode(quota_ctx_t qctx, enum quota_type qtype);



errcode_t quota_read_all_dquots(quota_ctx_t qctx, ext2_ino_t qf_ino,
    enum quota_type type, unsigned int flags);
errcode_t quota_compute_usage(quota_ctx_t qctx);
void quota_release_context(quota_ctx_t *qctx);
errcode_t quota_remove_inode(ext2_filsys fs, enum quota_type qtype);
int quota_file_exists(ext2_filsys fs, enum quota_type qtype);
void quota_set_sb_inum(ext2_filsys fs, ext2_ino_t ino, enum quota_type qtype);
errcode_t quota_compare_and_update(quota_ctx_t qctx, enum quota_type qtype,
       int *usage_inconsistent);
int parse_quota_opts(const char *opts, int (*func)(char *));


int parse_quota_types(const char *in_str, unsigned int *qtype_bits,
        char **err_token);







static inline ext2_ino_t *quota_sb_inump(struct ext2_super_block *sb,
      enum quota_type qtype)
{
 switch (qtype) {
 case USRQUOTA:
  return &sb->s_usr_quota_inum;
 case GRPQUOTA:
  return &sb->s_grp_quota_inum;
 case PRJQUOTA:
  return &sb->s_prj_quota_inum;
 default:
  return 
        ((void *)0)
            ;
 }

 return 
       ((void *)0)
           ;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
















struct list_head {
 struct list_head *next, *prev;
};
static __inline__ void __list_add(struct list_head * new,
 struct list_head * prev,
 struct list_head * next)
{
 next->prev = new;
 new->next = next;
 new->prev = prev;
 prev->next = new;
}




static __inline__ void list_add(struct list_head *new, struct list_head *head)
{
 __list_add(new, head, head->next);
}




static __inline__ void list_add_tail(struct list_head *new, struct list_head *head)
{
 __list_add(new, head->prev, head);
}
static __inline__ void __list_del(struct list_head * prev,
      struct list_head * next)
{
 next->prev = prev;
 prev->next = next;
}

static __inline__ void list_del(struct list_head *entry)
{
 __list_del(entry->prev, entry->next);
}

static __inline__ int list_empty(struct list_head *head)
{
 return head->next == head;
}




static __inline__ void list_splice(struct list_head *list, struct list_head *head)
{
 struct list_head *first = list->next;

 if (first != list) {
  struct list_head *last = list->prev;
  struct list_head *at = head->next;

  first->prev = head;
  head->next = first;

  last->next = at;
  at->prev = last;
 }
}








typedef unsigned int tid_t;
typedef struct journal_s journal_t;
typedef struct kdev_s *kdev_t;

struct buffer_head;
struct inode;

typedef unsigned int gfp_t;





typedef __u64 u64;
enum passtype {PASS_SCAN, PASS_REVOKE, PASS_REPLAY};




struct journal_s
{
 unsigned long j_flags;
 int j_errno;
 struct buffer_head * j_sb_buffer;
 struct journal_superblock_s *j_superblock;
 int j_format_version;
 unsigned long j_head;
 unsigned long j_tail;
 unsigned long j_fc_first;
 unsigned long j_fc_off;
 unsigned long j_fc_last;
 unsigned long j_free;
 unsigned long j_first, j_last;
 kdev_t j_dev;
 kdev_t j_fs_dev;
 int j_blocksize;
 unsigned int j_blk_offset;
 unsigned int j_total_len;
 struct inode * j_inode;
 tid_t j_tail_sequence;
 tid_t j_transaction_sequence;
 __u8 j_uuid[16];
 struct jbd2_revoke_table_s *j_revoke;
 struct jbd2_revoke_table_s *j_revoke_table[2];
 tid_t j_failed_commit;
 __u32 j_csum_seed;
 int (*j_fc_replay_callback)(struct journal_s *journal,
        struct buffer_head *bh,
        enum passtype pass, int off,
        tid_t expected_tid);

};
struct ext4_fc_tl {
 __le16 fc_tag;
 __le16 fc_len;
};


struct ext4_fc_head {
 __le32 fc_features;
 __le32 fc_tid;
};


struct ext4_fc_add_range {
 __le32 fc_ino;
 __u8 fc_ex[12];
};


struct ext4_fc_del_range {
 __le32 fc_ino;
 __le32 fc_lblk;
 __le32 fc_len;
};





struct ext4_fc_dentry_info {
 __le32 fc_parent_ino;
 __le32 fc_ino;
 __u8 fc_dname[0];
};


struct ext4_fc_inode {
 __le32 fc_ino;
 __u8 fc_raw_inode[0];
};


struct ext4_fc_tail {
 __le32 fc_tid;
 __le32 fc_crc;
};




enum {



 EXT4_FC_REASON_OK = 0,
 EXT4_FC_REASON_INELIGIBLE,
 EXT4_FC_REASON_ALREADY_COMMITTED,
 EXT4_FC_REASON_FC_START_FAILED,
 EXT4_FC_REASON_FC_FAILED,




 EXT4_FC_REASON_XATTR = 0,
 EXT4_FC_REASON_CROSS_RENAME,
 EXT4_FC_REASON_JOURNAL_FLAG_CHANGE,
 EXT4_FC_REASON_NOMEM,
 EXT4_FC_REASON_SWAP_BOOT,
 EXT4_FC_REASON_RESIZE,
 EXT4_FC_REASON_RENAME_DIR,
 EXT4_FC_REASON_FALLOC_RANGE,
 EXT4_FC_REASON_INODE_JOURNAL_DATA,
 EXT4_FC_COMMIT_FAILED,
 EXT4_FC_REASON_MAX
};
static inline const char *tag2str(__u16 tag)
{
 switch (tag) {
 case 0x0004:
  return "ADD_ENTRY";
 case 0x0005:
  return "DEL_ENTRY";
 case 0x0001:
  return "ADD_RANGE";
 case 0x0003:
  return "CREAT_DENTRY";
 case 0x0002:
  return "DEL_RANGE";
 case 0x0006:
  return "INODE";
 case 0x0007:
  return "PAD";
 case 0x0008:
  return "TAIL";
 case 0x0009:
  return "HEAD";
 default:
  return "ERROR";
 }
}


static inline int ext4_fc_tag_len(struct ext4_fc_tl *tl)
{
 return (( __u16)(__le16)(tl->fc_len));
}

#pragma GCC diagnostic pop
struct dir_info {
 ext2_ino_t ino;
 ext2_ino_t dotdot;
 ext2_ino_t parent;
};






struct dx_dir_info {
 ext2_ino_t ino;
 short depth;
 __u8 hashversion;
 __u8 casefolded_hash:1;
 blk_t numblocks;
 struct dx_dirblock_info *dx_block;
};







struct dx_dirblock_info {
 int type;
 int flags;
 blk64_t phys;
 blk64_t parent;
 blk64_t previous;
 ext2_dirhash_t min_hash;
 ext2_dirhash_t max_hash;
 ext2_dirhash_t node_min_hash;
 ext2_dirhash_t node_max_hash;
};






struct encrypted_file_info;
struct resource_track {
 struct timeval time_start;
 struct timeval user_start;
 struct timeval system_start;
 void *brk_start;
 unsigned long long bytes_read;
 unsigned long long bytes_written;
};
typedef struct ea_refcount *ext2_refcount_t;




typedef struct e2fsck_struct *e2fsck_t;







struct extent_list {
 blk64_t blocks_freed;
 struct ext2fs_extent *extents;
 unsigned int count;
 unsigned int size;
 unsigned int ext_read;
 errcode_t retval;
 ext2_ino_t ino;
};


struct e2fsck_fc_replay_state {
 struct extent_list fc_extent_list;
 int fc_replay_num_tags;
 int fc_replay_expected_off;
 enum passtype fc_current_pass;
 int fc_cur_tag;
 unsigned int fc_crc;
 __u16 fc_super_state;
};

struct e2fsck_struct {
 ext2_filsys fs;
 const char *program_name;
 char *filesystem_name;
 char *device_name;
 char *io_options;
 FILE *logf;
 char *log_fn;
 FILE *problem_logf;
 char *problem_log_fn;
 int flags;
 int options;
 unsigned blocksize;
 blk64_t use_superblock;
 blk64_t superblock;
 blk64_t num_blocks;
 blk64_t free_blocks;
 ext2_ino_t free_inodes;
 int mount_flags;
 int openfs_flags;
 blkid_cache blkid;


 jmp_buf abort_loc;

 unsigned long abort_code;

 int (*progress)(e2fsck_t ctx, int pass, unsigned long cur,
   unsigned long max);

 ext2fs_inode_bitmap inode_used_map;
 ext2fs_inode_bitmap inode_bad_map;
 ext2fs_inode_bitmap inode_dir_map;
 ext2fs_inode_bitmap inode_bb_map;
 ext2fs_inode_bitmap inode_imagic_map;
 ext2fs_inode_bitmap inode_reg_map;
 ext2fs_inode_bitmap inode_casefold_map;

 ext2fs_block_bitmap block_found_map;
 ext2fs_block_bitmap block_dup_map;
 ext2fs_block_bitmap block_ea_map;




 ext2_icount_t inode_count;
 ext2_icount_t inode_link_info;

 ext2_refcount_t refcount;
 ext2_refcount_t refcount_extra;




 ext2_refcount_t ea_block_quota_blocks;
 ext2_refcount_t ea_block_quota_inodes;




 ext2_refcount_t ea_inode_refs;





 int *invalid_inode_bitmap_flag;
 int *invalid_block_bitmap_flag;
 int *invalid_inode_table_flag;
 int invalid_bitmaps;




 char *block_buf;




 ext2_ino_t stashed_ino;
 struct ext2_inode *stashed_inode;




 ext2_ino_t lost_and_found;
 int bad_lost_and_found;




 struct dir_info_db *dir_info;




 ext2_ino_t dx_dir_info_count;
 ext2_ino_t dx_dir_info_size;
 struct dx_dir_info *dx_dir_info;




 ext2_u32_list dirs_to_hash;




 struct encrypted_file_info *encrypted_files;




 int process_inode_size;
 int inode_buffer_blocks;
 unsigned int htree_slack_percentage;




 io_channel journal_io;
 char *journal_name;




 quota_ctx_t qctx;




 struct resource_track global_rtrack;





 int progress_fd;
 int progress_pos;
 int progress_last_percent;
 unsigned int progress_last_time;
 int interactive;
 char start_meta[2], stop_meta[2];


 __u32 fs_directory_count;
 __u32 fs_regular_count;
 __u32 fs_blockdev_count;
 __u32 fs_chardev_count;
 __u32 fs_links_count;
 __u32 fs_symlinks_count;
 __u32 fs_fast_symlinks_count;
 __u32 fs_fifo_count;
 __u32 fs_total_count;
 __u32 fs_badblocks_count;
 __u32 fs_sockets_count;
 __u32 fs_ind_count;
 __u32 fs_dind_count;
 __u32 fs_tind_count;
 __u32 fs_fragmented;
 __u32 fs_fragmented_dir;
 __u32 large_files;
 __u32 large_dirs;
 __u32 fs_ext_attr_inodes;
 __u32 fs_ext_attr_blocks;
 __u32 extent_depth_count[5];


 time_t now;
 time_t time_fudge;
 int ext_attr_ver;
 profile_t profile;
 int blocks_per_page;
 ext2_u32_list casefolded_dirs;


 blk64_t root_repair_block, lnf_repair_block;





 void *priv_data;
 ext2fs_block_bitmap block_metadata_map;


 unsigned long long readahead_kb;




 ext2fs_inode_bitmap inodes_to_rebuild;


 char *undo_file;


 struct e2fsck_fc_replay_state fc_replay_state;
};


struct extent_tree_level {
 unsigned int num_extents;
 unsigned int max_extents;
};

struct extent_tree_info {
 ext2_ino_t ino;
 int force_rebuild;
 struct extent_tree_level ext_info[5];
};


typedef __u64 region_addr_t;
typedef struct region_struct *region_t;
extern void e2fsck_pass1(e2fsck_t ctx);
extern void e2fsck_pass1_dupblocks(e2fsck_t ctx, char *block_buf);
extern void e2fsck_pass2(e2fsck_t ctx);
extern void e2fsck_pass3(e2fsck_t ctx);
extern void e2fsck_pass4(e2fsck_t ctx);
extern void e2fsck_pass5(e2fsck_t ctx);


extern errcode_t e2fsck_allocate_context(e2fsck_t *ret);
extern errcode_t e2fsck_reset_context(e2fsck_t ctx);
extern void e2fsck_free_context(e2fsck_t ctx);
extern int e2fsck_run(e2fsck_t ctx);



extern void read_bad_blocks_file(e2fsck_t ctx, const char *bad_blocks_file,
     int replace_bad_blocks);


extern void e2fsck_add_dir_info(e2fsck_t ctx, ext2_ino_t ino, ext2_ino_t parent);
extern void e2fsck_free_dir_info(e2fsck_t ctx);
extern int e2fsck_get_num_dirinfo(e2fsck_t ctx);
extern struct dir_info_iter *e2fsck_dir_info_iter_begin(e2fsck_t ctx);
extern struct dir_info *e2fsck_dir_info_iter(e2fsck_t ctx,
          struct dir_info_iter *);
extern void e2fsck_dir_info_iter_end(e2fsck_t ctx, struct dir_info_iter *);
extern int e2fsck_dir_info_set_parent(e2fsck_t ctx, ext2_ino_t ino,
          ext2_ino_t parent);
extern int e2fsck_dir_info_set_dotdot(e2fsck_t ctx, ext2_ino_t ino,
          ext2_ino_t dotdot);
extern int e2fsck_dir_info_get_parent(e2fsck_t ctx, ext2_ino_t ino,
          ext2_ino_t *parent);
extern int e2fsck_dir_info_get_dotdot(e2fsck_t ctx, ext2_ino_t ino,
          ext2_ino_t *dotdot);


extern void e2fsck_add_dx_dir(e2fsck_t ctx, ext2_ino_t ino,
         struct ext2_inode *inode, int num_blocks);
extern struct dx_dir_info *e2fsck_get_dx_dir_info(e2fsck_t ctx, ext2_ino_t ino);
extern void e2fsck_free_dx_dir_info(e2fsck_t ctx);
extern ext2_ino_t e2fsck_get_num_dx_dirinfo(e2fsck_t ctx);
extern struct dx_dir_info *e2fsck_dx_dir_info_iter(e2fsck_t ctx,
         ext2_ino_t *control);


typedef __u64 ea_key_t;
typedef __u64 ea_value_t;

extern errcode_t ea_refcount_create(size_t size, ext2_refcount_t *ret);
extern void ea_refcount_free(ext2_refcount_t refcount);
extern errcode_t ea_refcount_fetch(ext2_refcount_t refcount, ea_key_t ea_key,
       ea_value_t *ret);
extern errcode_t ea_refcount_increment(ext2_refcount_t refcount,
           ea_key_t ea_key, ea_value_t *ret);
extern errcode_t ea_refcount_decrement(ext2_refcount_t refcount,
           ea_key_t ea_key, ea_value_t *ret);
extern errcode_t ea_refcount_store(ext2_refcount_t refcount, ea_key_t ea_key,
       ea_value_t count);
extern size_t ext2fs_get_refcount_size(ext2_refcount_t refcount);
extern void ea_refcount_intr_begin(ext2_refcount_t refcount);
extern ea_key_t ea_refcount_intr_next(ext2_refcount_t refcount,
          ea_value_t *ret);


extern const char *ehandler_operation(const char *op);
extern void ehandler_init(io_channel channel);



struct problem_context;
int add_encrypted_file(e2fsck_t ctx, struct problem_context *pctx);




__u32 find_encryption_policy(e2fsck_t ctx, ext2_ino_t ino);

void destroy_encryption_policy_map(e2fsck_t ctx);
void destroy_encrypted_file_info(e2fsck_t ctx);


errcode_t e2fsck_rebuild_extents_later(e2fsck_t ctx, ext2_ino_t ino);
int e2fsck_ino_will_be_rebuilt(e2fsck_t ctx, ext2_ino_t ino);
void e2fsck_pass1e(e2fsck_t ctx);
errcode_t e2fsck_check_rebuild_extents(e2fsck_t ctx, ext2_ino_t ino,
           struct ext2_inode *inode,
           struct problem_context *pctx);
errcode_t e2fsck_should_rebuild_extents(e2fsck_t ctx,
     struct problem_context *pctx,
     struct extent_tree_info *eti,
     struct ext2_extent_info *info);
errcode_t e2fsck_read_extents(e2fsck_t ctx, struct extent_list *extents);
errcode_t e2fsck_rewrite_extent_tree(e2fsck_t ctx,
         struct extent_list *extents);


extern errcode_t e2fsck_check_ext3_journal(e2fsck_t ctx);
extern errcode_t e2fsck_run_ext3_journal(e2fsck_t ctx);
extern void e2fsck_move_ext3_journal(e2fsck_t ctx);
extern int e2fsck_fix_ext3_journal_hint(e2fsck_t ctx);


extern void set_up_logging(e2fsck_t ctx);


extern void e2fsck_hide_quota(e2fsck_t ctx);
extern void e2fsck_validate_quota_inodes(e2fsck_t ctx);


extern errcode_t e2fsck_setup_icount(e2fsck_t ctx, const char *icount_name,
         int flags, ext2_icount_t hint,
         ext2_icount_t *ret);
extern void e2fsck_use_inode_shortcuts(e2fsck_t ctx, int use_shortcuts);
extern int e2fsck_pass1_check_device_inode(ext2_filsys fs,
        struct ext2_inode *inode);
extern int e2fsck_pass1_check_symlink(ext2_filsys fs, ext2_ino_t ino,
          struct ext2_inode *inode, char *buf);
extern void e2fsck_clear_inode(e2fsck_t ctx, ext2_ino_t ino,
          struct ext2_inode *inode, int restart_flag,
          const char *source);
extern void e2fsck_intercept_block_allocations(e2fsck_t ctx);


extern int e2fsck_process_bad_inode(e2fsck_t ctx, ext2_ino_t dir,
        ext2_ino_t ino, char *buf);


extern int e2fsck_reconnect_file(e2fsck_t ctx, ext2_ino_t inode);
extern errcode_t e2fsck_expand_directory(e2fsck_t ctx, ext2_ino_t dir,
      int num, int gauranteed_size);
extern ext2_ino_t e2fsck_get_lost_and_found(e2fsck_t ctx, int fix);
extern errcode_t e2fsck_adjust_inode_count(e2fsck_t ctx, ext2_ino_t ino,
        int adj);
errcode_t e2fsck_readahead(ext2_filsys fs, int flags, dgrp_t start,
      dgrp_t ngroups);


errcode_t e2fsck_readahead_dblist(ext2_filsys fs, int flags,
      ext2_dblist dblist,
      unsigned long long start,
      unsigned long long count);
int e2fsck_can_readahead(ext2_filsys fs);
unsigned long long e2fsck_guess_readahead(ext2_filsys fs);


extern region_t region_create(region_addr_t min, region_addr_t max);
extern void region_free(region_t region);
extern int region_allocate(region_t region, region_addr_t start, int n);


void e2fsck_rehash_dir_later(e2fsck_t ctx, ext2_ino_t ino);
int e2fsck_dir_will_be_rehashed(e2fsck_t ctx, ext2_ino_t ino);
errcode_t e2fsck_rehash_dir(e2fsck_t ctx, ext2_ino_t ino,
       struct problem_context *pctx);
void e2fsck_rehash_directories(e2fsck_t ctx);


void sigcatcher_setup(void);


void check_super_block(e2fsck_t ctx);
int check_backup_super_block(e2fsck_t ctx);
void check_resize_inode(e2fsck_t ctx);


extern void *e2fsck_allocate_memory(e2fsck_t ctx, unsigned long size,
        const char *description);
extern int ask(e2fsck_t ctx, const char * string, int def);
extern int ask_yn(e2fsck_t ctx, const char * string, int def);
extern void fatal_error(e2fsck_t ctx, const char * fmt_string);
extern void log_out(e2fsck_t ctx, const char *fmt, ...)
 __attribute__((format(printf, 2, 3)));
extern void log_err(e2fsck_t ctx, const char *fmt, ...)
 __attribute__((format(printf, 2, 3)));
extern void e2fsck_read_bitmaps(e2fsck_t ctx);
extern void e2fsck_write_bitmaps(e2fsck_t ctx);
extern void preenhalt(e2fsck_t ctx);
extern char *string_copy(e2fsck_t ctx, const char *str, size_t len);
extern int fs_proc_check(const char *fs_name);
extern int check_for_modules(const char *fs_name);

extern void print_resource_track(e2fsck_t ctx,
     const char *desc,
     struct resource_track *track,
     io_channel channel);
extern void init_resource_track(struct resource_track *track,
    io_channel channel);




extern int inode_has_valid_blocks(struct ext2_inode *inode);
extern void e2fsck_read_inode(e2fsck_t ctx, unsigned long ino,
         struct ext2_inode * inode, const char * proc);
extern void e2fsck_read_inode_full(e2fsck_t ctx, unsigned long ino,
       struct ext2_inode *inode,
       const int bufsize, const char *proc);
extern void e2fsck_write_inode(e2fsck_t ctx, unsigned long ino,
          struct ext2_inode * inode, const char * proc);
extern void e2fsck_write_inode_full(e2fsck_t ctx, unsigned long ino,
                               struct ext2_inode * inode, int bufsize,
                               const char *proc);



extern blk64_t get_backup_sb(e2fsck_t ctx, ext2_filsys fs,
      const char *name, io_manager manager);
extern int ext2_file_type(unsigned int mode);
extern int write_all(int fd, char *buf, size_t count);
void dump_mmp_msg(struct mmp_struct *mmp, const char *fmt, ...)
 __attribute__((format(printf, 2, 3)));
errcode_t e2fsck_mmp_update(ext2_filsys fs);

extern void e2fsck_set_bitmap_type(ext2_filsys fs,
       unsigned int default_type,
       const char *profile_name,
       unsigned int *old_type);
extern errcode_t e2fsck_allocate_inode_bitmap(ext2_filsys fs,
           const char *descr,
           int default_type,
           const char *profile_name,
           ext2fs_inode_bitmap *ret);
extern errcode_t e2fsck_allocate_block_bitmap(ext2_filsys fs,
           const char *descr,
           int default_type,
           const char *profile_name,
           ext2fs_block_bitmap *ret);
extern errcode_t e2fsck_allocate_subcluster_bitmap(ext2_filsys fs,
         const char *descr,
         int default_type,
         const char *profile_name,
         ext2fs_block_bitmap *ret);
unsigned long long get_memory_size(void);


extern void e2fsck_clear_progbar(e2fsck_t ctx);
extern int e2fsck_simple_progress(e2fsck_t ctx, const char *label,
      float percent, unsigned int dpynum);
typedef __u32 problem_t;

struct problem_context {
 errcode_t errcode;
 ext2_ino_t ino, ino2, dir;
 struct ext2_inode *inode;
 struct ext2_dir_entry *dirent;
 blk64_t blk, blk2;
 e2_blkcnt_t blkcount;
 dgrp_t group;
 __u32 csum1, csum2;
 __u64 num, num2;
 const char *str;
};
int fix_problem(e2fsck_t ctx, problem_t code, struct problem_context *pctx);
int end_problem_latch(e2fsck_t ctx, int mask);
int set_latch_flags(int mask, int setflags, int clearflags);
int get_latch_flags(int mask, int *value);
void clear_problem_context(struct problem_context *pctx);


void print_e2fsck_message(FILE *f, e2fsck_t ctx, const char *msg,
     struct problem_context *pctx, int first,
     int recurse);




errcode_t e2fsck_allocate_context(e2fsck_t *ret)
{
 e2fsck_t context;
 errcode_t retval;
 char *time_env;

 retval = ext2fs_get_mem(sizeof(struct e2fsck_struct), &context);
 if (retval)
  return retval;

 memset(context, 0, sizeof(struct e2fsck_struct));

 context->process_inode_size = 256;
 context->ext_attr_ver = 2;
 context->blocks_per_page = 1;
 context->htree_slack_percentage = 255;

 time_env = getenv("E2FSCK_TIME");
 if (time_env)
  context->now = (time_t) strtoull(time_env, 
                                            ((void *)0)
                                                , 0);
 else {
  context->now = time(0);
  if (context->now < 1262322000)
   context->flags |= 0x2000;
 }

 *ret = context;
 return 0;
}





errcode_t e2fsck_reset_context(e2fsck_t ctx)
{
 int i;

 ctx->flags &= (0x2000 | 0x4000);
 ctx->lost_and_found = 0;
 ctx->bad_lost_and_found = 0;
 if (ctx->inode_used_map) {
  ext2fs_free_inode_bitmap(ctx->inode_used_map);
  ctx->inode_used_map = 0;
 }
 if (ctx->inode_dir_map) {
  ext2fs_free_inode_bitmap(ctx->inode_dir_map);
  ctx->inode_dir_map = 0;
 }
 if (ctx->inode_reg_map) {
  ext2fs_free_inode_bitmap(ctx->inode_reg_map);
  ctx->inode_reg_map = 0;
 }
 if (ctx->block_found_map) {
  ext2fs_free_block_bitmap(ctx->block_found_map);
  ctx->block_found_map = 0;
 }
 if (ctx->inode_casefold_map) {
  ext2fs_free_block_bitmap(ctx->inode_casefold_map);
  ctx->inode_casefold_map = 0;
 }
 if (ctx->inode_link_info) {
  ext2fs_free_icount(ctx->inode_link_info);
  ctx->inode_link_info = 0;
 }
 if (ctx->journal_io) {
  if (ctx->fs && ctx->fs->io != ctx->journal_io)
   ((ctx->journal_io)->manager->close((ctx->journal_io)));
  ctx->journal_io = 0;
 }
 if (ctx->fs && ctx->fs->dblist) {
  ext2fs_free_dblist(ctx->fs->dblist);
  ctx->fs->dblist = 0;
 }
 e2fsck_free_dir_info(ctx);
 e2fsck_free_dx_dir_info(ctx);
 if (ctx->refcount) {
  ea_refcount_free(ctx->refcount);
  ctx->refcount = 0;
 }
 if (ctx->refcount_extra) {
  ea_refcount_free(ctx->refcount_extra);
  ctx->refcount_extra = 0;
 }
 if (ctx->ea_block_quota_blocks) {
  ea_refcount_free(ctx->ea_block_quota_blocks);
  ctx->ea_block_quota_blocks = 0;
 }
 if (ctx->ea_block_quota_inodes) {
  ea_refcount_free(ctx->ea_block_quota_inodes);
  ctx->ea_block_quota_inodes = 0;
 }
 if (ctx->ea_inode_refs) {
  ea_refcount_free(ctx->ea_inode_refs);
  ctx->ea_inode_refs = 0;
 }
 if (ctx->block_dup_map) {
  ext2fs_free_block_bitmap(ctx->block_dup_map);
  ctx->block_dup_map = 0;
 }
 if (ctx->block_ea_map) {
  ext2fs_free_block_bitmap(ctx->block_ea_map);
  ctx->block_ea_map = 0;
 }
 if (ctx->block_metadata_map) {
  ext2fs_free_block_bitmap(ctx->block_metadata_map);
  ctx->block_metadata_map = 0;
 }
 if (ctx->inode_bb_map) {
  ext2fs_free_inode_bitmap(ctx->inode_bb_map);
  ctx->inode_bb_map = 0;
 }
 if (ctx->inode_bad_map) {
  ext2fs_free_inode_bitmap(ctx->inode_bad_map);
  ctx->inode_bad_map = 0;
 }
 if (ctx->inode_imagic_map) {
  ext2fs_free_inode_bitmap(ctx->inode_imagic_map);
  ctx->inode_imagic_map = 0;
 }
 if (ctx->dirs_to_hash) {
  ext2fs_u32_list_free(ctx->dirs_to_hash);
  ctx->dirs_to_hash = 0;
 }
 destroy_encrypted_file_info(ctx);




 if (ctx->invalid_inode_bitmap_flag) {
  ext2fs_free_mem(&ctx->invalid_inode_bitmap_flag);
  ctx->invalid_inode_bitmap_flag = 0;
 }
 if (ctx->invalid_block_bitmap_flag) {
  ext2fs_free_mem(&ctx->invalid_block_bitmap_flag);
  ctx->invalid_block_bitmap_flag = 0;
 }
 if (ctx->invalid_inode_table_flag) {
  ext2fs_free_mem(&ctx->invalid_inode_table_flag);
  ctx->invalid_inode_table_flag = 0;
 }
 if (ctx->casefolded_dirs) {
  ext2fs_u32_list_free(ctx->casefolded_dirs);
  ctx->casefolded_dirs = 0;
 }
 if (ctx->inode_count) {
  ext2fs_free_icount(ctx->inode_count);
  ctx->inode_count = 0;
 }


 ctx->fs_directory_count = 0;
 ctx->fs_regular_count = 0;
 ctx->fs_blockdev_count = 0;
 ctx->fs_chardev_count = 0;
 ctx->fs_links_count = 0;
 ctx->fs_symlinks_count = 0;
 ctx->fs_fast_symlinks_count = 0;
 ctx->fs_fifo_count = 0;
 ctx->fs_total_count = 0;
 ctx->fs_badblocks_count = 0;
 ctx->fs_sockets_count = 0;
 ctx->fs_ind_count = 0;
 ctx->fs_dind_count = 0;
 ctx->fs_tind_count = 0;
 ctx->fs_fragmented = 0;
 ctx->fs_fragmented_dir = 0;
 ctx->large_files = 0;
 ctx->large_dirs = 0;

 for (i=0; i < 5; i++)
  ctx->extent_depth_count[i] = 0;


 ctx->superblock = ctx->use_superblock;

 return 0;
}

void e2fsck_free_context(e2fsck_t ctx)
{
 if (!ctx)
  return;

 e2fsck_reset_context(ctx);
 if (ctx->blkid)
  blkid_put_cache(ctx->blkid);

 if (ctx->profile)
  profile_release(ctx->profile);

 if (ctx->filesystem_name)
  ext2fs_free_mem(&ctx->filesystem_name);

 if (ctx->device_name)
  ext2fs_free_mem(&ctx->device_name);

 if (ctx->log_fn)
  free(ctx->log_fn);

 if (ctx->logf)
  fclose(ctx->logf);

 if (ctx->problem_log_fn)
  free(ctx->problem_log_fn);

 if (ctx->problem_logf) {
  fputs("</problem_log>\n", ctx->problem_logf);
  fclose(ctx->problem_logf);
 }
 ext2fs_free_mem(&ctx);
}





typedef void (*pass_t)(e2fsck_t ctx);

static pass_t e2fsck_passes[] = {
 e2fsck_pass1, e2fsck_pass1e, e2fsck_pass2, e2fsck_pass3,
 e2fsck_pass4, e2fsck_pass5, 0 };

int e2fsck_run(e2fsck_t ctx)
{
 int i;
 pass_t e2fsck_pass;


 if (
    _setjmp (
    ctx->abort_loc
    )
                          ) {
  ctx->flags &= ~0x0010;
  return (ctx->flags & ((0x0001 | 0x0002) | 0x0004));
 }
 ctx->flags |= 0x0010;


 for (i=0; (e2fsck_pass = e2fsck_passes[i]); i++) {
  if (ctx->flags & ((0x0001 | 0x0002) | 0x0004))
   break;
  if (e2fsck_mmp_update(ctx->fs))
   fatal_error(ctx, 0);
  e2fsck_pass(ctx);
  if (ctx->progress)
   (void) (ctx->progress)(ctx, 0, 0, 0);
 }
 ctx->flags &= ~0x0010;

 if (ctx->flags & ((0x0001 | 0x0002) | 0x0004))
  return (ctx->flags & ((0x0001 | 0x0002) | 0x0004));
 return 0;
}
