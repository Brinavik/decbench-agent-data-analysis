




















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


int fgetflags (const char * name, unsigned long * flags);
int fgetversion (const char * name, unsigned long * version);
int fsetflags (const char * name, unsigned long flags);
int fsetversion (const char * name, unsigned long version);
int fgetproject(const char *name, unsigned long *project);
int fsetproject(const char *name, unsigned long project);
int getflags (int fd, unsigned long * flags);
int getversion (int fd, unsigned long * version);
int iterate_on_dir (const char * dir_name,
      int (*func) (const char *, struct dirent *, void *),
      void * private_arg);
void list_super(struct ext2_super_block * s);
void list_super2(struct ext2_super_block * s, FILE *f);
void print_fs_errors (FILE * f, unsigned short errors);
void print_flags (FILE * f, unsigned long flags, unsigned options);
void print_fs_state (FILE * f, unsigned short state);
int setflags (int fd, unsigned long flags);
int setversion (int fd, unsigned long version);


void e2p_list_journal_super(FILE *f, char *journal_sb_buf,
       int exp_block_size, int flags);

void e2p_feature_to_string(int compat, unsigned int mask, char *buf,
                           size_t buf_len);
const char *e2p_feature2string(int compat, unsigned int mask);
const char *e2p_jrnl_feature2string(int compat, unsigned int mask);
int e2p_string2feature(char *string, int *compat, unsigned int *mask);
int e2p_jrnl_string2feature(char *string, int *compat_type, unsigned int *mask);
int e2p_edit_feature(const char *str, __u32 *compat_array, __u32 *ok_array);
int e2p_edit_feature2(const char *str, __u32 *compat_array, __u32 *ok_array,
        __u32 *clear_ok_array, int *type_err,
        unsigned int *mask_err);

int e2p_is_null_uuid(void *uu);
void e2p_uuid_to_str(void *uu, char *out);
const char *e2p_uuid2str(void *uu);

const char *e2p_hash2string(int num);
int e2p_string2hash(char *string);

const char *e2p_mntopt2string(unsigned int mask);
int e2p_string2mntopt(char *string, unsigned int *mask);
int e2p_edit_mntopts(const char *str, __u32 *mntopts, __u32 ok);

unsigned long parse_num_blocks(const char *arg, int log_block_size);
unsigned long long parse_num_blocks2(const char *arg, int log_block_size);

char *e2p_os2string(int os_type);
int e2p_string2os(char *str);

unsigned int e2p_percent(int percent, unsigned int base);

const char *e2p_encmode2string(int num);
int e2p_string2encmode(char *string);

int e2p_str2encoding(const char *string);
const char *e2p_encoding2str(int encoding);
int e2p_get_encoding_flags(int encoding);
int e2p_str2encoding_flags(int encoding, char *param, __u16 *flags);

const char *e2p_errcode2str(unsigned int err);

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
struct ea_quota {
 blk64_t blocks;
 __u64 inodes;
};

static int process_block(ext2_filsys fs, blk64_t *blocknr,
    e2_blkcnt_t blockcnt, blk64_t ref_blk,
    int ref_offset, void *priv_data);
static int process_bad_block(ext2_filsys fs, blk64_t *block_nr,
        e2_blkcnt_t blockcnt, blk64_t ref_blk,
        int ref_offset, void *priv_data);
static void check_blocks(e2fsck_t ctx, struct problem_context *pctx,
    char *block_buf,
    const struct ea_quota *ea_ibody_quota);
static void mark_table_blocks(e2fsck_t ctx);
static void alloc_bb_map(e2fsck_t ctx);
static void alloc_imagic_map(e2fsck_t ctx);
static void mark_inode_bad(e2fsck_t ctx, ino_t ino);
static void add_casefolded_dir(e2fsck_t ctx, ino_t ino);
static void handle_fs_bad_blocks(e2fsck_t ctx);
static void process_inodes(e2fsck_t ctx, char *block_buf);
static int process_inode_cmp(const void *a, const void *b);
static errcode_t scan_callback(ext2_filsys fs, ext2_inode_scan scan,
      dgrp_t group, void * priv_data);
static void adjust_extattr_refcount(e2fsck_t ctx, ext2_refcount_t refcount,
        char *block_buf, int adjust_sign);


struct process_block_struct {
 ext2_ino_t ino;
 unsigned is_dir:1, is_reg:1, clear:1, suppress:1,
    fragmented:1, compressed:1, bbcheck:1,
    inode_modified:1;
 blk64_t num_blocks;
 blk64_t max_blocks;
 blk64_t last_block;
 e2_blkcnt_t last_init_lblock;
 e2_blkcnt_t last_db_block;
 int num_illegal_blocks;
 blk64_t previous_block;
 struct ext2_inode *inode;
 struct problem_context *pctx;
 ext2fs_block_bitmap fs_meta_blocks;
 e2fsck_t ctx;
 blk64_t next_lblock;
 struct extent_tree_info eti;
};

struct process_inode_block {
 ext2_ino_t ino;
 struct ea_quota ea_ibody_quota;
 struct ext2_inode_large inode;
};

struct scan_callback_struct {
 e2fsck_t ctx;
 char *block_buf;
};




static struct process_inode_block *inodes_to_process;
static int process_inode_count;

static __u64 ext2_max_sizes[16 -
       10 + 1];
int e2fsck_pass1_check_device_inode(ext2_filsys fs __attribute__((unused)),
        struct ext2_inode *inode)
{
 int i;





 if (inode->i_flags & (0x00001000 | 0x00080000))
  return 0;
 if (inode->i_flags & (0x00000010 | 0x00000020)) {
  for (i=4; i < (((12 + 1) + 1) + 1); i++)
   if (inode->i_block[i])
    return 0;
 }
 return 1;
}





int e2fsck_pass1_check_symlink(ext2_filsys fs, ext2_ino_t ino,
          struct ext2_inode *inode, char *buf)
{
 unsigned int buflen;
 unsigned int len;

 if ((inode->i_size_high || inode->i_size == 0) ||
     (inode->i_flags & 0x00001000))
  return 0;

 if (inode->i_flags & 0x10000000) {
  size_t inline_size;

  if (inode->i_flags & 0x00080000)
   return 0;
  if (ext2fs_inline_data_size(fs, ino, &inline_size))
   return 0;
  if (inode->i_size != inline_size)
   return 0;

  return 1;
 }

 if (ext2fs_is_fast_symlink(inode)) {
  if (inode->i_flags & 0x00080000)
   return 0;
  buf = (char *)inode->i_block;
  buflen = sizeof(inode->i_block);
 } else {
  ext2_extent_handle_t handle;
  struct ext2_extent_info info;
  struct ext2fs_extent extent;
  blk64_t blk;
  int i;

  if (inode->i_flags & 0x00080000) {
   if (ext2fs_extent_open2(fs, ino, inode, &handle))
    return 0;
   if (ext2fs_extent_get_info(handle, &info) ||
       (info.num_entries != 1) ||
       (info.max_depth != 0)) {
    ext2fs_extent_free(handle);
    return 0;
   }
   if (ext2fs_extent_get(handle, 0x0001,
           &extent) ||
       (extent.e_lblk != 0) ||
       (extent.e_len != 1)) {
    ext2fs_extent_free(handle);
    return 0;
   }
   blk = extent.e_pblk;
   ext2fs_extent_free(handle);
  } else {
   blk = inode->i_block[0];

   for (i = 1; i < (((12 + 1) + 1) + 1); i++)
    if (inode->i_block[i])
     return 0;
  }

  if (blk < fs->super->s_first_data_block ||
      blk >= ext2fs_blocks_count(fs->super))
   return 0;

  if (io_channel_read_blk64(fs->io, blk, 1, buf))
   return 0;

  buflen = fs->blocksize;
 }

 if (inode->i_flags & 0x00000800)
  len = (( __u16)(__le16)(*(__u16 *)buf)) + 2;
 else
  len = strnlen(buf, buflen);

 if (len >= buflen)
  return 0;

 if (len != inode->i_size)
  return 0;
 return 1;
}





static void check_extents_inlinedata(e2fsck_t ctx,
         struct problem_context *pctx)
{
 if (!(pctx->inode->i_flags & (0x00080000 | 0x10000000)))
  return;

 if (!fix_problem(ctx, 0x010076, pctx))
  return;

 pctx->inode->i_flags &= ~(0x00080000 | 0x10000000);
 e2fsck_write_inode(ctx, pctx->ino, pctx->inode, "pass1");
}







static void check_immutable(e2fsck_t ctx, struct problem_context *pctx)
{
 if (!(pctx->inode->i_flags & (0x00000010 | 0x00000020)))
  return;

 if (!fix_problem(ctx, 0x010030, pctx))
  return;

 pctx->inode->i_flags &= ~(0x00000010 | 0x00000020);
 e2fsck_write_inode(ctx, pctx->ino, pctx->inode, "pass1");
}





static void check_size(e2fsck_t ctx, struct problem_context *pctx)
{
 struct ext2_inode *inode = pctx->inode;

 if (((inode)->i_size | ((__u64) (inode)->i_size_high << 32)) == 0)
  return;

 if (!fix_problem(ctx, 0x010032, pctx))
  return;

 ext2fs_inode_size_set(ctx->fs, inode, 0);
 e2fsck_write_inode(ctx, pctx->ino, pctx->inode, "pass1");
}




static blk64_t size_to_quota_blocks(ext2_filsys fs, size_t size)
{
 blk64_t clusters;

 clusters = (((size) + (fs->blocksize << fs->cluster_ratio_bits) - 1) / (fs->blocksize << fs->cluster_ratio_bits));
 return ((clusters) << (fs)->cluster_ratio_bits);
}





static problem_t check_large_ea_inode(e2fsck_t ctx,
          struct ext2_ext_attr_entry *entry,
          struct problem_context *pctx,
          blk64_t *quota_blocks)
{
 struct ext2_inode inode;
 __u32 hash;
 errcode_t retval;


 if ((entry->e_value_inum < (((ctx->fs->super)->s_rev_level == 0) ? 11 : (ctx->fs->super)->s_first_ino)) ||
     (entry->e_value_inum > ctx->fs->super->s_inodes_count)) {
  pctx->num = entry->e_value_inum;
  return 0x010083;
 }

 e2fsck_read_inode(ctx, entry->e_value_inum, &inode, "pass1");

 retval = ext2fs_ext_attr_hash_entry2(ctx->fs, entry, 
                                                     ((void *)0)
                                                         , &hash);
 if (retval) {
  com_err("check_large_ea_inode", retval,
   (gettext ("while hashing entry with e_value_inum = %u")),
   entry->e_value_inum);
  fatal_error(ctx, 0);
 }

 if (hash == entry->e_hash) {
  *quota_blocks = size_to_quota_blocks(ctx->fs,
           entry->e_value_size);
 } else {

  if (inode.i_mtime == pctx->ino &&
      inode.i_generation == pctx->inode->i_generation) {
   *quota_blocks = 0;
  } else {



   if (!(inode.i_flags & 0x00200000)) {
    pctx->num = entry->e_value_inum;
    return 0x010083;
   } else {
    pctx->num = entry->e_hash;
    return 0x010054;
   }
  }
 }

 if (!(inode.i_flags & 0x00200000)) {
  pctx->num = entry->e_value_inum;
  if (fix_problem(ctx, 0x010086, pctx)) {
   inode.i_flags |= 0x00200000;
   ext2fs_write_inode(ctx->fs, entry->e_value_inum,
        &inode);
  } else {
   return 0x010085;
  }
 }
 return 0;
}

static void inc_ea_inode_refs(e2fsck_t ctx, struct problem_context *pctx,
         struct ext2_ext_attr_entry *first, void *end)
{
 struct ext2_ext_attr_entry *entry;

 for (entry = first;
      (void *)entry < end && !(*((__u32 *)(entry)) == 0UL);
      entry = ( (struct ext2_ext_attr_entry *)( (char *)(entry) + ((((entry)->e_name_len) + (((unsigned) 1<<2)-1) + sizeof(struct ext2_ext_attr_entry)) & ~(((unsigned) 1<<2)-1))) )) {
  if (!entry->e_value_inum)
   continue;
  if (!ctx->ea_inode_refs) {
   pctx->errcode = ea_refcount_create(0,
          &ctx->ea_inode_refs);
   if (pctx->errcode) {
    pctx->num = 4;
    fix_problem(ctx, 0x010038, pctx);
    ctx->flags |= 0x0001;
    return;
   }
  }
  ea_refcount_increment(ctx->ea_inode_refs, entry->e_value_inum,
          0);
 }
}

static void check_ea_in_inode(e2fsck_t ctx, struct problem_context *pctx,
         struct ea_quota *ea_ibody_quota)
{
 struct ext2_super_block *sb = ctx->fs->super;
 struct ext2_inode_large *inode;
 struct ext2_ext_attr_entry *entry;
 char *start, *header, *end;
 unsigned int storage_size, remain;
 problem_t problem = 0;
 region_t region = 0;

 ea_ibody_quota->blocks = 0;
 ea_ibody_quota->inodes = 0;

 inode = (struct ext2_inode_large *) pctx->inode;
 storage_size = (((ctx->fs->super)->s_rev_level == 0) ? 128 : (ctx->fs->super)->s_inode_size) - 128 -
  inode->i_extra_isize;
 header = ((char *) inode) + 128 +
   inode->i_extra_isize;
 end = header + storage_size;
 start = header + sizeof(__u32);
 entry = (struct ext2_ext_attr_entry *) start;




 remain = storage_size - sizeof(__u32);

 region = region_create(0, storage_size);
 if (!region) {
  fix_problem(ctx, 0x01003F, pctx);
  problem = 0;
  ctx->flags |= 0x0001;
  return;
 }
 if (region_allocate(region, 0, sizeof(__u32))) {
  problem = 0x010069;
  goto fix;
 }

 while (remain >= sizeof(struct ext2_ext_attr_entry) &&
        !(*((__u32 *)(entry)) == 0UL)) {
  __u32 hash;

  if (region_allocate(region, (char *)entry - (char *)header,
        (((entry->e_name_len) + (((unsigned) 1<<2)-1) + sizeof(struct ext2_ext_attr_entry)) & ~(((unsigned) 1<<2)-1)))) {
   problem = 0x010069;
   goto fix;
  }


  remain -= sizeof(struct ext2_ext_attr_entry);


  if ((((entry->e_name_len) + (((unsigned) 1<<2)-1)) & ~(((unsigned) 1<<2)-1)) > remain) {
   pctx->num = entry->e_name_len;
   problem = 0x010050;
   goto fix;
  }


  remain -= (((entry->e_name_len) + (((unsigned) 1<<2)-1)) & ~(((unsigned) 1<<2)-1));

  if (entry->e_value_inum == 0) {

   if (entry->e_value_size > remain) {
    pctx->num = entry->e_value_size;
    problem = 0x010053;
    goto fix;
   }

   if (entry->e_value_size &&
       region_allocate(region,
         sizeof(__u32) + entry->e_value_offs,
         (((entry->e_value_size) + (((unsigned) 1<<2)-1)) & ~(((unsigned) 1<<2)-1))
                          )) {
    problem = 0x010069;
    goto fix;
   }

   hash = ext2fs_ext_attr_hash_entry(entry,
         start + entry->e_value_offs);


   if (entry->e_hash != 0 && entry->e_hash != hash) {
    pctx->num = entry->e_hash;
    problem = 0x010054;
    goto fix;
   }
  } else {
   blk64_t quota_blocks;

   problem = check_large_ea_inode(ctx, entry, pctx,
             &quota_blocks);
   if (problem != 0)
    goto fix;

   ea_ibody_quota->blocks += quota_blocks;
   ea_ibody_quota->inodes++;
  }



  if (entry->e_value_inum == 0)
   remain -= entry->e_value_size;

  entry = ( (struct ext2_ext_attr_entry *)( (char *)(entry) + ((((entry)->e_name_len) + (((unsigned) 1<<2)-1) + sizeof(struct ext2_ext_attr_entry)) & ~(((unsigned) 1<<2)-1))) );
 }

 if (region_allocate(region, (char *)entry - (char *)header,
       sizeof(__u32))) {
  problem = 0x010069;
  goto fix;
 }
fix:
 if (region)
  region_free(region);




 if (problem == 0 || !fix_problem(ctx, problem, pctx)) {
  inc_ea_inode_refs(ctx, pctx,
      (struct ext2_ext_attr_entry *)start, end);
  return;
 }


 *((__u32 *)header) = 0UL;
 e2fsck_write_inode_full(ctx, pctx->ino, pctx->inode,
    (((sb)->s_rev_level == 0) ? 128 : (sb)->s_inode_size), "pass1");
 ea_ibody_quota->blocks = 0;
 ea_ibody_quota->inodes = 0;
}

static int check_inode_extra_negative_epoch(__u32 xtime, __u32 extra) {
 return (xtime & (1U << 31)) != 0 &&
  (extra & ((1 << 2) - 1)) == ((1 << 2) - 1);
}
static void check_inode_extra_space(e2fsck_t ctx, struct problem_context *pctx,
        struct ea_quota *ea_ibody_quota)
{
 struct ext2_super_block *sb = ctx->fs->super;
 struct ext2_inode_large *inode;
 __u32 *eamagic;
 int min, max;

 ea_ibody_quota->blocks = 0;
 ea_ibody_quota->inodes = 0;

 inode = (struct ext2_inode_large *) pctx->inode;
 if ((((sb)->s_rev_level == 0) ? 128 : (sb)->s_inode_size) == 128) {

  return;
 }






 min = sizeof(inode->i_extra_isize) + sizeof(inode->i_checksum_hi);
 max = (((sb)->s_rev_level == 0) ? 128 : (sb)->s_inode_size) - 128;




 if (inode->i_extra_isize &&
     (inode->i_extra_isize < min || inode->i_extra_isize > max ||
      inode->i_extra_isize & 3)) {
  if (!fix_problem(ctx, 0x01004F, pctx))
   return;
  if (inode->i_extra_isize < min || inode->i_extra_isize > max)
   inode->i_extra_isize = sb->s_want_extra_isize;
  else
   inode->i_extra_isize = (inode->i_extra_isize + 3) & ~3;
  e2fsck_write_inode_full(ctx, pctx->ino, pctx->inode,
     (((sb)->s_rev_level == 0) ? 128 : (sb)->s_inode_size), "pass1");
 }


 if (inode->i_extra_isize >= max - sizeof(__u32))
  return;

 eamagic = (__u32 *) (((char *) inode) + 128 +
   inode->i_extra_isize);
 if (*eamagic == 0xEA020000) {

  check_ea_in_inode(ctx, pctx, ea_ibody_quota);
 }





 if (((sizeof(time_t) <= 4) ||
      (((sizeof(time_t) > 4) &&
        ctx->now < 2 * (1LL << 32)))) &&
     (check_inode_extra_negative_epoch(inode->i_atime, inode->i_atime_extra) ||
      check_inode_extra_negative_epoch(inode->i_ctime, inode->i_ctime_extra) ||
      check_inode_extra_negative_epoch(inode->i_crtime, inode->i_crtime_extra) ||
      check_inode_extra_negative_epoch(inode->i_mtime, inode->i_mtime_extra))) {

  if (!fix_problem(ctx, 0x010082, pctx))
   return;

  if (check_inode_extra_negative_epoch(inode->i_atime, inode->i_atime_extra))
   inode->i_atime_extra &= ~((1 << 2) - 1);
  if (check_inode_extra_negative_epoch(inode->i_ctime, inode->i_ctime_extra))
   inode->i_ctime_extra &= ~((1 << 2) - 1);
  if (check_inode_extra_negative_epoch(inode->i_crtime, inode->i_crtime_extra))
   inode->i_crtime_extra &= ~((1 << 2) - 1);
  if (check_inode_extra_negative_epoch(inode->i_mtime, inode->i_mtime_extra))
   inode->i_mtime_extra &= ~((1 << 2) - 1);
  e2fsck_write_inode_full(ctx, pctx->ino, pctx->inode,
     (((sb)->s_rev_level == 0) ? 128 : (sb)->s_inode_size), "pass1");
 }

}
static void check_is_really_dir(e2fsck_t ctx, struct problem_context *pctx,
    char *buf)
{
 struct ext2_inode *inode = pctx->inode;
 struct ext2_dir_entry *dirent;
 errcode_t retval;
 blk64_t blk;
 unsigned int i, rec_len, not_device = 0;
 int extent_fs;
 int inlinedata_fs;
 if ((((inode->i_mode) & 00170000) == 0040000) || (((inode->i_mode) & 00170000) == 0100000) ||
     (((inode->i_mode) & 00170000) == 0120000) || inode->i_block[0] == 0)
  return;
 extent_fs = ext2fs_has_feature_extents(ctx->fs->super);
 inlinedata_fs = ext2fs_has_feature_inline_data(ctx->fs->super);
 if (inlinedata_fs && (inode->i_flags & 0x10000000)) {
  size_t size;
  __u32 dotdot;
  unsigned int rec_len2;
  struct ext2_dir_entry de;

  if (ext2fs_inline_data_size(ctx->fs, pctx->ino, &size))
   return;




  if (size & 3)
   return;




  memcpy(&dotdot, inode->i_block, sizeof(dotdot));
  memcpy(&de, ((char *)inode->i_block) + (4),
         ext2fs_dir_rec_len(0, 0));
  dotdot = (( __u32)(__le32)(dotdot));
  de.inode = (( __u32)(__le32)(de.inode));
  de.rec_len = (( __u16)(__le16)(de.rec_len));
  ext2fs_get_rec_len(ctx->fs, &de, &rec_len2);
  if (dotdot >= ctx->fs->super->s_inodes_count ||
      (dotdot < (((ctx->fs->super)->s_rev_level == 0) ? 11 : (ctx->fs->super)->s_first_ino) &&
       dotdot != 2) ||
      de.inode >= ctx->fs->super->s_inodes_count ||
      (de.inode < (((ctx->fs->super)->s_rev_level == 0) ? 11 : (ctx->fs->super)->s_first_ino) &&
       de.inode != 0) ||
      rec_len2 > ((sizeof(__u32) * (((12 + 1) + 1) + 1))) -
         (4))
   return;

  goto isdir;
 } else if (extent_fs && (inode->i_flags & 0x00080000)) {

  if (ext2fs_bmap2(ctx->fs, pctx->ino, inode, 0, 0, 0, 0,
     &blk))
   return;

  not_device++;
 } else {
  for (i=0; i < (((12 + 1) + 1) + 1); i++) {
   blk = inode->i_block[i];
   if (!blk)
    continue;
   if (i >= 4)
    not_device++;

   if (blk < ctx->fs->super->s_first_data_block ||
       blk >= ext2fs_blocks_count(ctx->fs->super) ||
       ext2fs_fast_test_block_bitmap2(ctx->block_found_map,
          blk))
    return;
  }
  blk = inode->i_block[0];
 }






 if (((((inode->i_mode) & 00170000) == 0020000) || (((inode->i_mode) & 00170000) == 0060000)) &&
     (inode->i_links_count == 1) && !not_device)
  return;


 ehandler_operation((gettext ("reading directory block")));
 retval = ext2fs_read_dir_block4(ctx->fs, blk, buf, 0, pctx->ino);
 ehandler_operation(0);
 if (retval)
  return;

 dirent = (struct ext2_dir_entry *) buf;
 retval = ext2fs_get_rec_len(ctx->fs, dirent, &rec_len);
 if (retval)
  return;
 if ((ext2fs_dirent_name_len(dirent) != 1) ||
     (dirent->name[0] != '.') ||
     (dirent->inode != pctx->ino) ||
     (rec_len < 12) ||
     (rec_len % 4) ||
     (rec_len >= ctx->fs->blocksize - 12))
  return;

 dirent = (struct ext2_dir_entry *) (buf + rec_len);
 retval = ext2fs_get_rec_len(ctx->fs, dirent, &rec_len);
 if (retval)
  return;
 if ((ext2fs_dirent_name_len(dirent) != 2) ||
     (dirent->name[0] != '.') ||
     (dirent->name[1] != '.') ||
     (rec_len < 12) ||
     (rec_len % 4))
  return;

isdir:
 if (fix_problem(ctx, 0x010055, pctx)) {
  inode->i_mode = (inode->i_mode & 07777) | 0040000;
  e2fsck_write_inode_full(ctx, pctx->ino, inode,
     (((ctx->fs->super)->s_rev_level == 0) ? 128 : (ctx->fs->super)->s_inode_size),
     "check_is_really_dir");
 }
}

extern errcode_t e2fsck_setup_icount(e2fsck_t ctx, const char *icount_name,
         int flags, ext2_icount_t hint,
         ext2_icount_t *ret)
{
 unsigned int threshold;
 unsigned int save_type;
 ext2_ino_t num_dirs;
 errcode_t retval;
 char *tdb_dir;
 int enable;

 *ret = 0;

 profile_get_string(ctx->profile, "scratch_files", "directory", 0, 0,
      &tdb_dir);
 profile_get_uint(ctx->profile, "scratch_files",
    "numdirs_threshold", 0, 0, &threshold);
 profile_get_boolean(ctx->profile, "scratch_files",
       "icount", 0, 1, &enable);

 retval = ext2fs_get_num_dirs(ctx->fs, &num_dirs);
 if (retval)
  num_dirs = 1024;

 if (enable && tdb_dir && !access(tdb_dir, 
                                          2
                                              ) &&
     (!threshold || num_dirs > threshold)) {
  retval = ext2fs_create_icount_tdb(ctx->fs, tdb_dir,
        flags, ret);
  if (retval == 0)
   return 0;
 }
 e2fsck_set_bitmap_type(ctx->fs, 2, icount_name,
          &save_type);
 if (ctx->options & 0x20000)
  flags |= 0x02;
 retval = ext2fs_create_icount2(ctx->fs, flags, 0, hint, ret);
 ctx->fs->default_bitmap_type = save_type;
 return retval;
}

static errcode_t recheck_bad_inode_checksum(ext2_filsys fs, ext2_ino_t ino,
         e2fsck_t ctx,
         struct problem_context *pctx)
{
 errcode_t retval;
 struct ext2_inode_large inode;





 ctx->stashed_ino = 0;
 retval = ext2fs_read_inode_full(fs, ino, (struct ext2_inode *)&inode,
     sizeof(inode));
 if (retval && retval != (2133571474L))
  return retval;
 if (!retval)
  return 0;






 if (!fix_problem(ctx, 0x010068, pctx))
  return 0;

 retval = ext2fs_write_inode_full(fs, ino, (struct ext2_inode *)&inode,
      sizeof(inode));
 return retval;
}

static void reserve_block_for_root_repair(e2fsck_t ctx)
{
 blk64_t blk = 0;
 errcode_t err;
 ext2_filsys fs = ctx->fs;

 ctx->root_repair_block = 0;
 if (ext2fs_test_inode_bitmap2(ctx->inode_used_map, 2))
  return;

 err = ext2fs_new_block2(fs, 0, ctx->block_found_map, &blk);
 if (err)
  return;
 ext2fs_mark_block_bitmap2(ctx->block_found_map, blk);
 ctx->root_repair_block = blk;
}

static void reserve_block_for_lnf_repair(e2fsck_t ctx)
{
 blk64_t blk = 0;
 errcode_t err;
 ext2_filsys fs = ctx->fs;
 static const char name[] = "lost+found";
 ext2_ino_t ino;

 ctx->lnf_repair_block = 0;
 if (!ext2fs_lookup(fs, 2, name, sizeof(name)-1, 0, &ino))
  return;

 err = ext2fs_new_block2(fs, 0, ctx->block_found_map, &blk);
 if (err)
  return;
 ext2fs_mark_block_bitmap2(ctx->block_found_map, blk);
 ctx->lnf_repair_block = blk;
}

static errcode_t get_inline_data_ea_size(ext2_filsys fs, ext2_ino_t ino,
      size_t *sz)
{
 void *p;
 struct ext2_xattr_handle *handle;
 errcode_t retval;

 retval = ext2fs_xattrs_open(fs, ino, &handle);
 if (retval)
  return retval;

 retval = ext2fs_xattrs_read(handle);
 if (retval)
  goto err;

 retval = ext2fs_xattr_get(handle, "system.data", &p, sz);
 if (retval)
  goto err;
 ext2fs_free_mem(&p);
err:
 (void) ext2fs_xattrs_close(&handle);
 return retval;
}

static void finish_processing_inode(e2fsck_t ctx, ext2_ino_t ino,
        struct problem_context *pctx,
        int failed_csum)
{
 if (!failed_csum)
  return;






 pctx->errcode = recheck_bad_inode_checksum(ctx->fs, ino, ctx, pctx);
 if (pctx->errcode)
  ctx->flags |= 0x0001;
}







static int could_be_block_map(ext2_filsys fs, struct ext2_inode *inode)
{
 __u32 x;
 int i;

 for (i = 0; i < (((12 + 1) + 1) + 1); i++) {
  x = inode->i_block[i];



  if (x >= ext2fs_blocks_count(fs->super))
   return 0;
 }

 return 1;
}





static int fix_inline_data_extents_file(e2fsck_t ctx,
     ext2_ino_t ino,
     struct ext2_inode *inode,
     int inode_size,
     struct problem_context *pctx)
{
 size_t max_inline_ea_size;
 ext2_filsys fs = ctx->fs;
 int dirty = 0;


 if (!ext2fs_has_feature_extents(fs->super) &&
     !ext2fs_has_feature_inline_data(fs->super))
  return 0;


 if ((((inode->i_mode) & 00170000) == 0020000) ||
     (((inode->i_mode) & 00170000) == 0060000) ||
     (((inode->i_mode) & 00170000) == 0010000) ||
     (((inode->i_mode) & 00170000) == 0140000)) {
  check_extents_inlinedata(ctx, pctx);
  return 0;
 }


 if (ext2fs_extent_header_verify(inode->i_block,
     sizeof(inode->i_block)) == 0 &&
     fix_problem(ctx, 0x010077, pctx)) {
  inode->i_flags &= ~0x10000000;
  dirty = 1;
  goto out;
 }


 if (inode_size > 128)
  max_inline_ea_size = inode_size -
         (128 +
          ((struct ext2_inode_large *)inode)->i_extra_isize);
 else
  max_inline_ea_size = 0;
 if (((inode)->i_size | ((__u64) (inode)->i_size_high << 32)) <
     ((sizeof(__u32) * (((12 + 1) + 1) + 1))) + max_inline_ea_size &&
     fix_problem(ctx, 0x010078, pctx)) {
  inode->i_flags &= ~0x00080000;
  dirty = 1;
  goto out;
 }





 if (could_be_block_map(fs, inode) &&
     fix_problem(ctx, 0x010079, pctx)) {







  inode->i_flags &= ~(0x00080000 | 0x10000000);
  dirty = 1;
  goto out;
 }


 if (fix_problem(ctx, 0x01007A, pctx)) {
  e2fsck_clear_inode(ctx, ino, inode, 0, "pass1");
  return -1;
 }

out:
 if (dirty)
  e2fsck_write_inode(ctx, ino, inode, "pass1");

 return 0;
}

static void pass1_readahead(e2fsck_t ctx, dgrp_t *group, ext2_ino_t *next_ino)
{
 ext2_ino_t inodes_in_group = 0, inodes_per_block, inodes_per_buffer;
 dgrp_t start = *group, grp;
 blk64_t blocks_to_read = 0;
 errcode_t err = (2133571399L);

 if (ctx->readahead_kb == 0)
  goto out;


 inodes_per_block = (((1 << 10) << (ctx->fs->super)->s_log_block_size)/(((ctx->fs->super)->s_rev_level == 0) ? 128 : (ctx->fs->super)->s_inode_size));
 for (grp = start; grp < ctx->fs->group_desc_count; grp++) {
  if (ext2fs_bg_flags_test(ctx->fs, grp, 0x0001))
   continue;
  inodes_in_group = ctx->fs->super->s_inodes_per_group -
     ext2fs_bg_itable_unused(ctx->fs, grp);
  blocks_to_read += (inodes_in_group + inodes_per_block - 1) /
     inodes_per_block;
  if (blocks_to_read * ctx->fs->blocksize >
      ctx->readahead_kb * 1024)
   break;
 }

 err = e2fsck_readahead(ctx->fs, (0x10), start,
          grp - start + 1);
 if (err == 
           11
                 ) {
  ctx->readahead_kb /= 2;
  err = 0;
 }

out:
 if (err) {

  *group = ctx->fs->group_desc_count;
  *next_ino = ctx->fs->super->s_inodes_count;
 } else {




  *group = grp + 1;
  inodes_per_buffer = (ctx->inode_buffer_blocks ?
         ctx->inode_buffer_blocks :
         8) *
        ctx->fs->blocksize /
        (((ctx->fs->super)->s_rev_level == 0) ? 128 : (ctx->fs->super)->s_inode_size);
  inodes_in_group--;
  *next_ino = inodes_in_group -
       (inodes_in_group % inodes_per_buffer) + 1 +
       (grp * ctx->fs->super->s_inodes_per_group);
 }
}
static int quota_inum_is_super(struct ext2_super_block *sb, ext2_ino_t ino)
{
 enum quota_type qtype;

 for (qtype = 0; qtype < MAXQUOTAS; qtype++)
  if (*quota_sb_inump(sb, qtype) == ino)
   return 1;

 return 0;
}






static int quota_inum_is_reserved(ext2_filsys fs, ext2_ino_t ino)
{
 enum quota_type qtype;

 for (qtype = 0; qtype < MAXQUOTAS; qtype++)
  if (quota_type2inum(qtype, fs->super) == ino)
   return 1;

 return 0;
}

void e2fsck_pass1(e2fsck_t ctx)
{
 int i;
 __u64 max_sizes;
 ext2_filsys fs = ctx->fs;
 ext2_ino_t ino = 0;
 struct ext2_inode *inode = 
                           ((void *)0)
                               ;
 ext2_inode_scan scan = 
                       ((void *)0)
                           ;
 char *block_buf = 
                   ((void *)0)
                       ;

 struct resource_track rtrack;

 unsigned char frag, fsize;
 struct problem_context pctx;
 struct scan_callback_struct scan_struct;
 struct ext2_super_block *sb = ctx->fs->super;
 const char *old_op;
 const char *eop_next_inode = (gettext ("getting next inode from scan"));
 int imagic_fs, extent_fs, inlinedata_fs, casefold_fs;
 int low_dtime_check = 1;
 unsigned int inode_size = (((fs->super)->s_rev_level == 0) ? 128 : (fs->super)->s_inode_size);
 unsigned int bufsize;
 int failed_csum = 0;
 ext2_ino_t ino_threshold = 0;
 dgrp_t ra_group = 0;
 struct ea_quota ea_ibody_quota;

 init_resource_track(&rtrack, ctx->fs->io);
 clear_problem_context(&pctx);


 if (!e2fsck_can_readahead(ctx->fs))
  ctx->readahead_kb = 0;
 else if (ctx->readahead_kb == ~0ULL)
  ctx->readahead_kb = e2fsck_guess_readahead(ctx->fs);
 pass1_readahead(ctx, &ra_group, &ino_threshold);

 if (!(ctx->options & 0x0002))
  fix_problem(ctx, 0x010000, &pctx);

 if (ext2fs_has_feature_dir_index(fs->super) &&
     !(ctx->options & 0x0008)) {
  if (ext2fs_u32_list_create(&ctx->dirs_to_hash, 50))
   ctx->dirs_to_hash = 0;
 }







 for (i = 10; i <= 16; i++) {
  max_sizes = 12 + (1ULL << ((i) - 2));
  max_sizes = max_sizes + (1ULL << ((i) - 2)) * (1ULL << ((i) - 2));
  max_sizes = max_sizes + (1ULL << ((i) - 2)) * (1ULL << ((i) - 2)) * (1ULL << ((i) - 2));
  max_sizes = (max_sizes * (1UL << i));
  ext2_max_sizes[i - 10] = max_sizes;
 }


 imagic_fs = ext2fs_has_feature_imagic_inodes(sb);
 extent_fs = ext2fs_has_feature_extents(sb);
 inlinedata_fs = ext2fs_has_feature_inline_data(sb);
 casefold_fs = ext2fs_has_feature_casefold(sb);




 pctx.errcode = e2fsck_allocate_inode_bitmap(fs, (gettext ("in-use inode map")),
          2,
          "inode_used_map",
          &ctx->inode_used_map);
 if (pctx.errcode) {
  pctx.num = 1;
  fix_problem(ctx, 0x010024, &pctx);
  ctx->flags |= 0x0001;
  return;
 }
 pctx.errcode = e2fsck_allocate_inode_bitmap(fs,
   (gettext ("directory inode map")),
   3,
   "inode_dir_map", &ctx->inode_dir_map);
 if (pctx.errcode) {
  pctx.num = 2;
  fix_problem(ctx, 0x010024, &pctx);
  ctx->flags |= 0x0001;
  return;
 }
 pctx.errcode = e2fsck_allocate_inode_bitmap(fs,
   (gettext ("regular file inode map")), 2,
   "inode_reg_map", &ctx->inode_reg_map);
 if (pctx.errcode) {
  pctx.num = 6;
  fix_problem(ctx, 0x010024, &pctx);
  ctx->flags |= 0x0001;
  return;
 }
 pctx.errcode = e2fsck_allocate_subcluster_bitmap(fs,
   (gettext ("in-use block map")), 2,
   "block_found_map", &ctx->block_found_map);
 if (pctx.errcode) {
  pctx.num = 1;
  fix_problem(ctx, 0x010025, &pctx);
  ctx->flags |= 0x0001;
  return;
 }
 pctx.errcode = e2fsck_allocate_block_bitmap(fs,
   (gettext ("metadata block map")), 2,
   "block_metadata_map", &ctx->block_metadata_map);
 if (pctx.errcode) {
  pctx.num = 1;
  fix_problem(ctx, 0x010025, &pctx);
  ctx->flags |= 0x0001;
  return;
 }
 if (casefold_fs) {
  pctx.errcode =
   e2fsck_allocate_inode_bitmap(fs,
           (gettext ("inode casefold map")),
           2,
           "inode_casefold_map",
           &ctx->inode_casefold_map);
  if (pctx.errcode) {
   pctx.num = 1;
   fix_problem(ctx, 0x010024, &pctx);
   ctx->flags |= 0x0001;
   return;
  }
 }
 pctx.errcode = e2fsck_setup_icount(ctx, "inode_link_info", 0, 
                                                              ((void *)0)
                                                                  ,
        &ctx->inode_link_info);
 if (pctx.errcode) {
  fix_problem(ctx, 0x010026, &pctx);
  ctx->flags |= 0x0001;
  return;
 }
 bufsize = inode_size;
 if (bufsize < sizeof(struct ext2_inode_large))
  bufsize = sizeof(struct ext2_inode_large);
 inode = (struct ext2_inode *)
  e2fsck_allocate_memory(ctx, bufsize, "scratch inode");

 inodes_to_process = (struct process_inode_block *)
  e2fsck_allocate_memory(ctx,
           (ctx->process_inode_size *
     sizeof(struct process_inode_block)),
           "array of inodes to process");
 process_inode_count = 0;

 pctx.errcode = ext2fs_init_dblist(fs, 0);
 if (pctx.errcode) {
  fix_problem(ctx, 0x010027, &pctx);
  ctx->flags |= 0x0001;
  goto endit;
 }
 if (!(ctx->options & 0x0001)) {
  if (fs->super->s_last_orphan) {
   fs->super->s_last_orphan = 0;
   ext2fs_mark_super_dirty(fs);
  }
 }

 mark_table_blocks(ctx);
 pctx.errcode = ext2fs_convert_subcluster_bitmap(fs,
      &ctx->block_found_map);
 if (pctx.errcode) {
  fix_problem(ctx, 0x010061, &pctx);
  ctx->flags |= 0x0001;
  goto endit;
 }
 block_buf = (char *) e2fsck_allocate_memory(ctx, fs->blocksize * 3,
          "block interate buffer");
 if ((((fs->super)->s_rev_level == 0) ? 128 : (fs->super)->s_inode_size) == 128)
  e2fsck_use_inode_shortcuts(ctx, 1);
 e2fsck_intercept_block_allocations(ctx);
 old_op = ehandler_operation((gettext ("opening inode scan")));
 pctx.errcode = ext2fs_open_inode_scan(fs, ctx->inode_buffer_blocks,
           &scan);
 ehandler_operation(old_op);
 if (pctx.errcode) {
  fix_problem(ctx, 0x010028, &pctx);
  ctx->flags |= 0x0001;
  goto endit;
 }
 ext2fs_inode_scan_flags(scan, 0x0008 |
          0x0020, 0);
 ctx->stashed_inode = inode;
 scan_struct.ctx = ctx;
 scan_struct.block_buf = block_buf;
 ext2fs_set_inode_callback(scan, scan_callback, &scan_struct);
 if (ctx->progress && ((ctx->progress)(ctx, 1, 0,
           ctx->fs->group_desc_count)))
  goto endit;
 if ((fs->super->s_wtime &&
      fs->super->s_wtime < fs->super->s_inodes_count) ||
     (fs->super->s_mtime &&
      fs->super->s_mtime < fs->super->s_inodes_count) ||
     (fs->super->s_mkfs_time &&
      fs->super->s_mkfs_time < fs->super->s_inodes_count))
  low_dtime_check = 0;

 if (ext2fs_has_feature_mmp(fs->super) &&
     fs->super->s_mmp_block > fs->super->s_first_data_block &&
     fs->super->s_mmp_block < ext2fs_blocks_count(fs->super))
  ext2fs_mark_block_bitmap2(ctx->block_found_map,
       fs->super->s_mmp_block);


 (void) e2fsck_get_lost_and_found(ctx, 0);

 while (1) {
  if (ino % (fs->super->s_inodes_per_group * 4) == 1) {
   if (e2fsck_mmp_update(fs))
    fatal_error(ctx, 0);
  }
  old_op = ehandler_operation(eop_next_inode);
  pctx.errcode = ext2fs_get_next_inode_full(scan, &ino,
         inode, inode_size);
  if (ino > ino_threshold)
   pass1_readahead(ctx, &ra_group, &ino_threshold);
  ehandler_operation(old_op);
  if (ctx->flags & (0x0001 | 0x0002))
   goto endit;
  if (pctx.errcode == (2133571394L)) {





   if (ino == 1 &&
       fix_problem(ctx, 0x01007B,
     &pctx)) {
    errcode_t err;

    e2fsck_clear_inode(ctx, ino, inode, 0, "pass1");
    ext2fs_badblocks_list_free(ctx->fs->badblocks);
    ctx->fs->badblocks = 
                        ((void *)0)
                            ;
    err = ext2fs_read_bb_inode(ctx->fs,
       &ctx->fs->badblocks);
    if (err) {
     fix_problem(ctx, 0x010028,
          &pctx);
     ctx->flags |= 0x0001;
    } else
     ctx->flags |= 0x0004;
    goto endit;
   }
   if (!ctx->inode_bb_map)
    alloc_bb_map(ctx);
   ext2fs_mark_inode_bitmap2(ctx->inode_bb_map, ino);
   ext2fs_mark_inode_bitmap2(ctx->inode_used_map, ino);
   continue;
  }
  if (pctx.errcode &&
      pctx.errcode != (2133571474L) &&
      pctx.errcode != (2133571497L)) {
   fix_problem(ctx, 0x010028, &pctx);
   ctx->flags |= 0x0001;
   goto endit;
  }
  if (!ino)
   break;
  pctx.ino = ino;
  pctx.inode = inode;
  ctx->stashed_ino = ino;


  if (pctx.errcode == (2133571497L) &&
      inode->i_links_count > 0 &&
      fix_problem(ctx, 0x010067, &pctx)) {
   pctx.errcode = 0;
   e2fsck_clear_inode(ctx, ino, inode, 0, "pass1");
  }
  failed_csum = pctx.errcode != 0;
  if (inode->i_dtime && low_dtime_check &&
      inode->i_dtime < ctx->fs->super->s_inodes_count) {
   if (fix_problem(ctx, 0x010036, &pctx)) {
    inode->i_dtime = inode->i_links_count ?
     0 : ctx->now;
    e2fsck_write_inode(ctx, ino, inode,
         "pass1");
    failed_csum = 0;
   }
  }

  if (inode->i_links_count) {
   pctx.errcode = ext2fs_icount_store(ctx->inode_link_info,
        ino, inode->i_links_count);
   if (pctx.errcode) {
    pctx.num = inode->i_links_count;
    fix_problem(ctx, 0x01002A, &pctx);
    ctx->flags |= 0x0001;
    goto endit;
   }
  } else if ((ino >= (((fs->super)->s_rev_level == 0) ? 11 : (fs->super)->s_first_ino)) &&
      !quota_inum_is_reserved(fs, ino)) {
   if (!inode->i_dtime && inode->i_mode) {
    if (fix_problem(ctx,
         0x010004, &pctx)) {
     inode->i_dtime = ctx->now;
     e2fsck_write_inode(ctx, ino, inode,
          "pass1");
     failed_csum = 0;
    }
   }
   do { finish_processing_inode((ctx), (ino), (&pctx), (failed_csum)); if ((ctx)->flags & 0x0001) return; } while (0);
   continue;
  }

  if ((inode->i_flags & 0x40000000) &&
      ((!(((inode->i_mode) & 00170000) == 0040000) &&
        fix_problem(ctx, 0x010088, &pctx)) ||
       (!casefold_fs &&
        fix_problem(ctx, 0x010089, &pctx)))) {
   inode->i_flags &= ~0x40000000;
   e2fsck_write_inode(ctx, ino, inode, "pass1");
  }


  if ((inode->i_flags & 0x10000000) &&
      (inode->i_flags & 0x00080000)) {
   int res = fix_inline_data_extents_file(ctx, ino, inode,
              inode_size,
              &pctx);
   if (res < 0) {

    continue;
   }
  }


  if ((inode->i_flags & 0x10000000) && !inlinedata_fs &&
      (ino >= (((fs->super)->s_rev_level == 0) ? 11 : (fs->super)->s_first_ino))) {
   size_t size = 0;

   pctx.errcode = get_inline_data_ea_size(fs, ino, &size);
   if (!pctx.errcode &&
       fix_problem(ctx, 0x01006F, &pctx)) {
    ext2fs_set_feature_inline_data(sb);
    ext2fs_mark_super_dirty(fs);
    inlinedata_fs = 1;
   } else if (fix_problem(ctx, 0x010070, &pctx)) {
    e2fsck_clear_inode(ctx, ino, inode, 0, "pass1");

    continue;
   }
  }


  if ((inode->i_flags & 0x10000000) && inlinedata_fs &&
      (ino >= (((fs->super)->s_rev_level == 0) ? 11 : (fs->super)->s_first_ino))) {
   size_t size = 0;
   errcode_t err;
   int flags;

   flags = fs->flags;
   if (failed_csum)
    fs->flags |= 0x200000;
   err = get_inline_data_ea_size(fs, ino, &size);
   fs->flags = (flags & 0x200000) |
        (fs->flags & ~0x200000);

   switch (err) {
   case 0:

    break;
   case (2133571418L):
   case (2133571488L):
   case (2133571489L):
   case (2133571486L):
   case (2133571487L):
   case (2133571490L):
   case (2133571491L):
   case (2133571492L):
   case (2133571485L):
   case (2133571494L):
   case (2133571495L):
   case (2133571493L):
   case (2133571479L):
   case (2133571498L):
   case (2133571506L):

    if (fix_problem(ctx, 0x010075,
      &pctx)) {
     err = ext2fs_inode_size_set(fs, inode, 0);
     if (err) {
      pctx.errcode = err;
      ctx->flags |= 0x0001;
      goto endit;
     }
     inode->i_flags &= ~0x10000000;
     memset(&inode->i_block, 0,
            sizeof(inode->i_block));
     e2fsck_write_inode(ctx, ino, inode,
          "pass1");
     failed_csum = 0;
    }
    break;
   default:

    pctx.errcode = err;
    ctx->flags |= 0x0001;
    goto endit;
   }
  }
  if ((inode->i_flags & 0x00080000) && !extent_fs &&
      (inode->i_links_count || (ino == 1) ||
       (ino == 2) || (ino == 8))) {
   if ((ext2fs_extent_header_verify(inode->i_block,
       sizeof(inode->i_block)) == 0) &&
       fix_problem(ctx, 0x01005B, &pctx)) {
    ext2fs_set_feature_extents(sb);
    ext2fs_mark_super_dirty(fs);
    extent_fs = 1;
   } else if (fix_problem(ctx, 0x01005A, &pctx)) {
   clear_inode:
    e2fsck_clear_inode(ctx, ino, inode, 0, "pass1");
    if (ino == 1)
     ext2fs_mark_inode_bitmap2(ctx->inode_used_map,
         ino);

    continue;
   }
  }
  if (extent_fs && !(inode->i_flags & 0x00080000) &&
      (inode->i_links_count || (ino == 1) ||
       (ino == 2) || (ino == 8)) &&
      ((((inode->i_mode) & 00170000) == 0100000) ||
       (((inode->i_mode) & 00170000) == 0040000))) {
   void *ehp;







   ehp = inode->i_block;

   if ((ext2fs_extent_header_verify(ehp,
      sizeof(inode->i_block)) == 0) &&
       (fix_problem(ctx, 0x01005C, &pctx))) {
    inode->i_flags |= 0x00080000;




    e2fsck_write_inode(ctx, ino, inode, "pass1");
    failed_csum = 0;
   }
  }

  if (ino == 1) {
   struct process_block_struct pb;

   if ((failed_csum || inode->i_mode || inode->i_uid ||
        inode->i_gid || inode->i_links_count ||
        (inode->i_flags & 0x10000000) ||
        inode->i_file_acl) &&
       fix_problem(ctx, 0x010065, &pctx)) {
    memset(inode, 0, sizeof(struct ext2_inode));
    e2fsck_write_inode(ctx, ino, inode,
         "clear bad inode");
    failed_csum = 0;
   }

   pctx.errcode = ext2fs_copy_bitmap(ctx->block_found_map,
         &pb.fs_meta_blocks);
   if (pctx.errcode) {
    pctx.num = 4;
    fix_problem(ctx, 0x010025, &pctx);
    ctx->flags |= 0x0001;
    goto endit;
   }
   pb.ino = 1;
   pb.num_blocks = pb.last_block = 0;
   pb.last_db_block = -1;
   pb.num_illegal_blocks = 0;
   pb.suppress = 0; pb.clear = 0; pb.is_dir = 0;
   pb.is_reg = 0; pb.fragmented = 0; pb.bbcheck = 0;
   pb.inode = inode;
   pb.pctx = &pctx;
   pb.ctx = ctx;
   pctx.errcode = ext2fs_block_iterate3(fs, ino, 0,
         block_buf, process_bad_block, &pb);
   ext2fs_free_block_bitmap(pb.fs_meta_blocks);
   if (pctx.errcode) {
    fix_problem(ctx, 0x010029, &pctx);
    ctx->flags |= 0x0001;
    goto endit;
   }
   if (pb.bbcheck)
    if (!fix_problem(ctx, 0x010016, &pctx)) {
    ctx->flags |= 0x0001;
    goto endit;
   }
   ext2fs_mark_inode_bitmap2(ctx->inode_used_map, ino);
   clear_problem_context(&pctx);
   do { finish_processing_inode((ctx), (ino), (&pctx), (failed_csum)); if ((ctx)->flags & 0x0001) return; } while (0);
   continue;
  } else if (ino == 2) {





   if (!(((inode->i_mode) & 00170000) == 0040000)) {
    if (fix_problem(ctx, 0x010001, &pctx))
     goto clear_inode;
   }
   if (inode->i_dtime && inode->i_links_count) {
    if (fix_problem(ctx, 0x010002, &pctx)) {
     inode->i_dtime = 0;
     e2fsck_write_inode(ctx, ino, inode,
          "pass1");
     failed_csum = 0;
    }
   }
  } else if (ino == 8) {
   ext2fs_mark_inode_bitmap2(ctx->inode_used_map, ino);
   if (fs->super->s_journal_inum == 8) {
    if (!(((inode->i_mode) & 00170000) == 0100000) &&
        fix_problem(ctx, 0x010035,
      &pctx)) {
     inode->i_mode = 0100000;
     e2fsck_write_inode(ctx, ino, inode,
          "pass1");
     failed_csum = 0;
    }
    check_blocks(ctx, &pctx, block_buf, 
                                       ((void *)0)
                                           );
    do { finish_processing_inode((ctx), (ino), (&pctx), (failed_csum)); if ((ctx)->flags & 0x0001) return; } while (0);
    continue;
   }
   if ((inode->i_links_count ||
        inode->i_blocks || inode->i_block[0]) &&
       fix_problem(ctx, 0x010034,
     &pctx)) {
    memset(inode, 0, inode_size);
    ext2fs_icount_store(ctx->inode_link_info,
          ino, 0);
    e2fsck_write_inode_full(ctx, ino, inode,
       inode_size, "pass1");
    failed_csum = 0;
   }
  } else if (quota_inum_is_reserved(fs, ino)) {
   ext2fs_mark_inode_bitmap2(ctx->inode_used_map, ino);
   if (ext2fs_has_feature_quota(fs->super) &&
       quota_inum_is_super(fs->super, ino)) {
    if (!(((inode->i_mode) & 00170000) == 0100000) &&
        fix_problem(ctx, 0x010062,
       &pctx)) {
     inode->i_mode = 0100000;
     e2fsck_write_inode(ctx, ino, inode,
       "pass1");
     failed_csum = 0;
    }
    check_blocks(ctx, &pctx, block_buf, 
                                       ((void *)0)
                                           );
    do { finish_processing_inode((ctx), (ino), (&pctx), (failed_csum)); if ((ctx)->flags & 0x0001) return; } while (0);
    continue;
   }
   if ((inode->i_links_count ||
        inode->i_blocks || inode->i_block[0]) &&
       fix_problem(ctx, 0x010063,
     &pctx)) {
    memset(inode, 0, inode_size);
    ext2fs_icount_store(ctx->inode_link_info,
          ino, 0);
    e2fsck_write_inode_full(ctx, ino, inode,
       inode_size, "pass1");
    failed_csum = 0;
   }
  } else if (ino < (((fs->super)->s_rev_level == 0) ? 11 : (fs->super)->s_first_ino)) {
   problem_t problem = 0;

   ext2fs_mark_inode_bitmap2(ctx->inode_used_map, ino);
   if (ino == 5) {
    if ((((inode->i_mode) & 00170000) == 0040000))
     problem = 0x010003;
   } else if (ino == 7) {
    if (inode->i_mode &&
        !(((inode->i_mode) & 00170000) == 0100000))
     problem = 0x010003;
   } else {
    if (inode->i_mode != 0)
     problem = 0x010003;
   }
   if (problem) {
    if (fix_problem(ctx, problem, &pctx)) {
     inode->i_mode = 0;
     e2fsck_write_inode(ctx, ino, inode,
          "pass1");
     failed_csum = 0;
    }
   }
   check_blocks(ctx, &pctx, block_buf, 
                                      ((void *)0)
                                          );
   do { finish_processing_inode((ctx), (ino), (&pctx), (failed_csum)); if ((ctx)->flags & 0x0001) return; } while (0);
   continue;
  }

  if (!inode->i_links_count) {
   do { finish_processing_inode((ctx), (ino), (&pctx), (failed_csum)); if ((ctx)->flags & 0x0001) return; } while (0);
   continue;
  }
  if (inode->i_dtime) {
   if (fix_problem(ctx, 0x010005, &pctx)) {
    inode->i_dtime = 0;
    e2fsck_write_inode(ctx, ino, inode, "pass1");
    failed_csum = 0;
   }
  }

  ext2fs_mark_inode_bitmap2(ctx->inode_used_map, ino);
  switch (fs->super->s_creator_os) {
      case 1:
   frag = inode->osd2.hurd2.h_i_frag;
   fsize = inode->osd2.hurd2.h_i_fsize;
   break;
      default:
   frag = fsize = 0;
  }

  if (inode->i_faddr || frag || fsize ||
      (!ext2fs_has_feature_largedir(fs->super) &&
      ((((inode->i_mode) & 00170000) == 0040000) && inode->i_size_high)))
   mark_inode_bad(ctx, ino);
  if ((fs->super->s_creator_os != 1) &&
      !ext2fs_has_feature_64bit(fs->super) &&
      inode->osd2.linux2.l_i_file_acl_high != 0)
   mark_inode_bad(ctx, ino);
  if ((fs->super->s_creator_os != 1) &&
      !ext2fs_has_feature_huge_file(fs->super) &&
      (inode->osd2.linux2.l_i_blocks_hi != 0))
   mark_inode_bad(ctx, ino);
  if (inode->i_flags & 0x00002000) {
   if (imagic_fs) {
    if (!ctx->inode_imagic_map)
     alloc_imagic_map(ctx);
    ext2fs_mark_inode_bitmap2(ctx->inode_imagic_map,
        ino);
   } else {
    if (fix_problem(ctx, 0x01002F, &pctx)) {
     inode->i_flags &= ~0x00002000;
     e2fsck_write_inode(ctx, ino,
          inode, "pass1");
     failed_csum = 0;
    }
   }
  }

  check_inode_extra_space(ctx, &pctx, &ea_ibody_quota);
  check_is_really_dir(ctx, &pctx, block_buf);





  if (extent_fs && (inode->i_flags & 0x00080000) &&
      (((inode->i_mode) & 00170000) == 0120000) &&
      !ext2fs_inode_has_valid_blocks2(fs, inode) &&
      fix_problem(ctx, 0x01005D, &pctx)) {
   inode->i_flags &= ~0x00080000;
   e2fsck_write_inode(ctx, ino, inode, "pass1");
   failed_csum = 0;
  }

  if ((inode->i_flags & 0x00000800) &&
      add_encrypted_file(ctx, &pctx) < 0)
   goto clear_inode;

  if (casefold_fs && inode->i_flags & 0x40000000)
   ext2fs_mark_inode_bitmap2(ctx->inode_casefold_map, ino);

  if ((((inode->i_mode) & 00170000) == 0040000)) {
   ext2fs_mark_inode_bitmap2(ctx->inode_dir_map, ino);
   e2fsck_add_dir_info(ctx, ino, 0);
   ctx->fs_directory_count++;
   if (inode->i_flags & 0x40000000)
    add_casefolded_dir(ctx, ino);
  } else if ((((inode->i_mode) & 00170000) == 0100000)) {
   ext2fs_mark_inode_bitmap2(ctx->inode_reg_map, ino);
   ctx->fs_regular_count++;
  } else if ((((inode->i_mode) & 00170000) == 0020000) &&
      e2fsck_pass1_check_device_inode(fs, inode)) {
   check_extents_inlinedata(ctx, &pctx);
   check_immutable(ctx, &pctx);
   check_size(ctx, &pctx);
   ctx->fs_chardev_count++;
  } else if ((((inode->i_mode) & 00170000) == 0060000) &&
      e2fsck_pass1_check_device_inode(fs, inode)) {
   check_extents_inlinedata(ctx, &pctx);
   check_immutable(ctx, &pctx);
   check_size(ctx, &pctx);
   ctx->fs_blockdev_count++;
  } else if ((((inode->i_mode) & 00170000) == 0120000) &&
      e2fsck_pass1_check_symlink(fs, ino, inode,
            block_buf)) {
   check_immutable(ctx, &pctx);
   ctx->fs_symlinks_count++;
   if (inode->i_flags & 0x10000000) {
    do { finish_processing_inode((ctx), (ino), (&pctx), (failed_csum)); if ((ctx)->flags & 0x0001) return; } while (0);
    continue;
   } else if (ext2fs_is_fast_symlink(inode)) {
    ctx->fs_fast_symlinks_count++;
    check_blocks(ctx, &pctx, block_buf,
          &ea_ibody_quota);
    do { finish_processing_inode((ctx), (ino), (&pctx), (failed_csum)); if ((ctx)->flags & 0x0001) return; } while (0);
    continue;
   }
  }
  else if ((((inode->i_mode) & 00170000) == 0010000) &&
    e2fsck_pass1_check_device_inode(fs, inode)) {
   check_extents_inlinedata(ctx, &pctx);
   check_immutable(ctx, &pctx);
   check_size(ctx, &pctx);
   ctx->fs_fifo_count++;
  } else if (((((inode->i_mode) & 00170000) == 0140000)) &&
      e2fsck_pass1_check_device_inode(fs, inode)) {
   check_extents_inlinedata(ctx, &pctx);
   check_immutable(ctx, &pctx);
   check_size(ctx, &pctx);
   ctx->fs_sockets_count++;
  } else
   mark_inode_bad(ctx, ino);
  if (!(inode->i_flags & 0x00080000) &&
      !(inode->i_flags & 0x10000000)) {
   if (inode->i_block[12])
    ctx->fs_ind_count++;
   if (inode->i_block[(12 + 1)])
    ctx->fs_dind_count++;
   if (inode->i_block[((12 + 1) + 1)])
    ctx->fs_tind_count++;
  }
  if (!(inode->i_flags & 0x00080000) &&
      !(inode->i_flags & 0x10000000) &&
      (inode->i_block[12] ||
       inode->i_block[(12 + 1)] ||
       inode->i_block[((12 + 1) + 1)] ||
       ext2fs_file_acl_block(fs, inode))) {
   struct process_inode_block *itp;

   itp = &inodes_to_process[process_inode_count];
   itp->ino = ino;
   itp->ea_ibody_quota = ea_ibody_quota;
   if (inode_size < sizeof(struct ext2_inode_large))
    memcpy(&itp->inode, inode, inode_size);
   else
    memcpy(&itp->inode, inode, sizeof(itp->inode));
   process_inode_count++;
  } else
   check_blocks(ctx, &pctx, block_buf, &ea_ibody_quota);

  do { finish_processing_inode((ctx), (ino), (&pctx), (failed_csum)); if ((ctx)->flags & 0x0001) return; } while (0);

  if (ctx->flags & (0x0001 | 0x0002))
   goto endit;

  if (process_inode_count >= ctx->process_inode_size) {
   process_inodes(ctx, block_buf);

   if (ctx->flags & (0x0001 | 0x0002))
    goto endit;
  }
 }
 process_inodes(ctx, block_buf);
 ext2fs_close_inode_scan(scan);
 scan = 
       ((void *)0)
           ;

 reserve_block_for_root_repair(ctx);
 reserve_block_for_lnf_repair(ctx);






 if (ctx->refcount) {
  adjust_extattr_refcount(ctx, ctx->refcount, block_buf, -1);
  ea_refcount_free(ctx->refcount);
  ctx->refcount = 0;
 }
 if (ctx->refcount_extra) {
  adjust_extattr_refcount(ctx, ctx->refcount_extra,
     block_buf, +1);
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

 if (ctx->invalid_bitmaps)
  handle_fs_bad_blocks(ctx);


 if (ctx->block_ea_map) {
  ext2fs_free_block_bitmap(ctx->block_ea_map);
  ctx->block_ea_map = 0;
 }


 destroy_encryption_policy_map(ctx);

 if (ctx->flags & 0x0400) {
  clear_problem_context(&pctx);
  pctx.errcode = ext2fs_create_resize_inode(fs);
  if (pctx.errcode) {
   if (!fix_problem(ctx, 0x01004E,
      &pctx)) {
    ctx->flags |= 0x0001;
    goto endit;
   }
   pctx.errcode = 0;
  }
  if (!pctx.errcode) {
   e2fsck_read_inode(ctx, 7, inode,
       "recreate inode");
   inode->i_mtime = ctx->now;
   e2fsck_write_inode(ctx, 7, inode,
        "recreate inode");
  }
  ctx->flags &= ~0x0400;
 }

 if (ctx->flags & 0x0004) {






  ctx->use_superblock = 0;
  goto endit;
 }

 if (ctx->large_dirs && !ext2fs_has_feature_largedir(fs->super)) {
  if (fix_problem(ctx, 0x020039, &pctx)) {
   ext2fs_set_feature_largedir(fs->super);
   fs->flags &= ~0x200;
   ext2fs_mark_super_dirty(fs);
  }
  if (fs->super->s_rev_level == 0 &&
      fix_problem(ctx, 0x010033, &pctx)) {
   ext2fs_update_dynamic_rev(fs);
   ext2fs_mark_super_dirty(fs);
  }
 }

 if (ctx->block_dup_map) {
  if (ctx->options & 0x0002) {
   clear_problem_context(&pctx);
   fix_problem(ctx, 0x010014, &pctx);
  }
  e2fsck_pass1_dupblocks(ctx, block_buf);
 }
 ctx->flags |= 0x8000;
endit:
 e2fsck_use_inode_shortcuts(ctx, 0);
 ext2fs_free_mem(&inodes_to_process);
 inodes_to_process = 0;

 if (scan)
  ext2fs_close_inode_scan(scan);
 if (block_buf)
  ext2fs_free_mem(&block_buf);
 if (inode)
  ext2fs_free_mem(&inode);





 ctx->lost_and_found = 0;

 if ((ctx->flags & (0x0001 | 0x0002)) == 0)
  print_resource_track(ctx, (gettext ("Pass 1")), &rtrack, ctx->fs->io);
 else
  ctx->invalid_bitmaps++;
}






static errcode_t scan_callback(ext2_filsys fs,
          ext2_inode_scan scan __attribute__((unused)),
          dgrp_t group, void * priv_data)
{
 struct scan_callback_struct *scan_struct;
 e2fsck_t ctx;

 scan_struct = (struct scan_callback_struct *) priv_data;
 ctx = scan_struct->ctx;

 process_inodes((e2fsck_t) fs->priv_data, scan_struct->block_buf);

 if (ctx->progress)
  if ((ctx->progress)(ctx, 1, group+1,
        ctx->fs->group_desc_count))
   return (2133571409L);

 return 0;
}




static void process_inodes(e2fsck_t ctx, char *block_buf)
{
 int i;
 struct ext2_inode *old_stashed_inode;
 ext2_ino_t old_stashed_ino;
 const char *old_operation;
 char buf[80];
 struct problem_context pctx;




 if (process_inode_count == 0)
  return;
 old_operation = ehandler_operation(0);
 old_stashed_inode = ctx->stashed_inode;
 old_stashed_ino = ctx->stashed_ino;
 qsort(inodes_to_process, process_inode_count,
        sizeof(struct process_inode_block), process_inode_cmp);
 clear_problem_context(&pctx);
 for (i=0; i < process_inode_count; i++) {
  pctx.inode = ctx->stashed_inode =
   (struct ext2_inode *) &inodes_to_process[i].inode;
  pctx.ino = ctx->stashed_ino = inodes_to_process[i].ino;




  sprintf(buf, (gettext ("reading indirect blocks of inode %u")),
   pctx.ino);
  ehandler_operation(buf);
  check_blocks(ctx, &pctx, block_buf,
        &inodes_to_process[i].ea_ibody_quota);
  if (ctx->flags & (0x0001 | 0x0002))
   break;
 }
 ctx->stashed_inode = old_stashed_inode;
 ctx->stashed_ino = old_stashed_ino;
 process_inode_count = 0;



 ehandler_operation(old_operation);
}

static int process_inode_cmp(const void *a, const void *b)
{
 const struct process_inode_block *ib_a =
  (const struct process_inode_block *) a;
 const struct process_inode_block *ib_b =
  (const struct process_inode_block *) b;
 int ret;

 ret = (ib_a->inode.i_block[12] -
        ib_b->inode.i_block[12]);
 if (ret == 0)





  ret = ext2fs_file_acl_block(0, ext2fs_const_inode(&ib_a->inode)) -
   ext2fs_file_acl_block(0, ext2fs_const_inode(&ib_b->inode));
 if (ret == 0)
  ret = ib_a->ino - ib_b->ino;
 return ret;
}




static void mark_inode_bad(e2fsck_t ctx, ino_t ino)
{
 struct problem_context pctx;

 if (!ctx->inode_bad_map) {
  clear_problem_context(&pctx);

  pctx.errcode = e2fsck_allocate_inode_bitmap(ctx->fs,
    (gettext ("bad inode map")), 2,
    "inode_bad_map", &ctx->inode_bad_map);
  if (pctx.errcode) {
   pctx.num = 3;
   fix_problem(ctx, 0x010024, &pctx);

   ctx->flags |= 0x0001;
   return;
  }
 }
 ext2fs_mark_inode_bitmap2(ctx->inode_bad_map, ino);
}

static void add_casefolded_dir(e2fsck_t ctx, ino_t ino)
{
 struct problem_context pctx;

 if (!ctx->casefolded_dirs) {
  pctx.errcode = ext2fs_u32_list_create(&ctx->casefolded_dirs, 0);
  if (pctx.errcode)
   goto error;
 }
 pctx.errcode = ext2fs_u32_list_add(ctx->casefolded_dirs, ino);
 if (pctx.errcode == 0)
  return;
error:
 fix_problem(ctx, 0x01008C, &pctx);

 ctx->flags |= 0x0001;
}




static void alloc_bb_map(e2fsck_t ctx)
{
 struct problem_context pctx;

 clear_problem_context(&pctx);
 pctx.errcode = e2fsck_allocate_inode_bitmap(ctx->fs,
   (gettext ("inode in bad block map")), 2,
   "inode_bb_map", &ctx->inode_bb_map);
 if (pctx.errcode) {
  pctx.num = 4;
  fix_problem(ctx, 0x010024, &pctx);

  ctx->flags |= 0x0001;
  return;
 }
}




static void alloc_imagic_map(e2fsck_t ctx)
{
 struct problem_context pctx;

 clear_problem_context(&pctx);
 pctx.errcode = e2fsck_allocate_inode_bitmap(ctx->fs,
   (gettext ("imagic inode map")), 2,
   "inode_imagic_map", &ctx->inode_imagic_map);
 if (pctx.errcode) {
  pctx.num = 5;
  fix_problem(ctx, 0x010024, &pctx);

  ctx->flags |= 0x0001;
  return;
 }
}
static inline void mark_block_used(e2fsck_t ctx, blk64_t block)
{
 struct problem_context pctx;

 clear_problem_context(&pctx);

 if (ext2fs_fast_test_block_bitmap2(ctx->block_found_map, block)) {
  if (ext2fs_has_feature_shared_blocks(ctx->fs->super) &&
      !(ctx->options & 0x40000)) {
   return;
  }
  if (!ctx->block_dup_map) {
   pctx.errcode = e2fsck_allocate_block_bitmap(ctx->fs,
     (gettext ("multiply claimed block map")),
     2, "block_dup_map",
     &ctx->block_dup_map);
   if (pctx.errcode) {
    pctx.num = 3;
    fix_problem(ctx, 0x010025,
         &pctx);

    ctx->flags |= 0x0001;
    return;
   }
  }
  ext2fs_fast_mark_block_bitmap2(ctx->block_dup_map, block);
 } else {
  ext2fs_fast_mark_block_bitmap2(ctx->block_found_map, block);
 }
}





static inline void mark_blocks_used(e2fsck_t ctx, blk64_t block,
          unsigned int num)
{
 if (ext2fs_test_block_bitmap_range2(ctx->block_found_map, block, num))
  ext2fs_mark_block_bitmap_range2(ctx->block_found_map, block, num);
 else {
  unsigned int i;

  for (i = 0; i < num; i += (1 << (ctx->fs)->cluster_ratio_bits))
   mark_block_used(ctx, block + i);
 }
}
static void adjust_extattr_refcount(e2fsck_t ctx, ext2_refcount_t refcount,
        char *block_buf, int adjust_sign)
{
 struct ext2_ext_attr_header *header;
 struct problem_context pctx;
 ext2_filsys fs = ctx->fs;
 blk64_t blk;
 __u32 should_be;
 ea_value_t count;

 clear_problem_context(&pctx);

 ea_refcount_intr_begin(refcount);
 while (1) {
  if ((blk = ea_refcount_intr_next(refcount, &count)) == 0)
   break;
  pctx.blk = blk;
  pctx.errcode = ext2fs_read_ext_attr3(fs, blk, block_buf,
           pctx.ino);
  if (pctx.errcode) {
   fix_problem(ctx, 0x01003B, &pctx);
   return;
  }
  header = (struct ext2_ext_attr_header *) block_buf;
  pctx.blkcount = header->h_refcount;
  should_be = header->h_refcount + adjust_sign * (int)count;
  pctx.num = should_be;
  if (fix_problem(ctx, 0x01003C, &pctx)) {
   header->h_refcount = should_be;
   pctx.errcode = ext2fs_write_ext_attr3(fs, blk,
            block_buf,
            pctx.ino);
   if (pctx.errcode) {
    fix_problem(ctx, 0x01003D,
         &pctx);
    continue;
   }
  }
 }
}




static int check_ext_attr(e2fsck_t ctx, struct problem_context *pctx,
      char *block_buf, struct ea_quota *ea_block_quota)
{
 ext2_filsys fs = ctx->fs;
 ext2_ino_t ino = pctx->ino;
 struct ext2_inode *inode = pctx->inode;
 blk64_t blk;
 char * end;
 struct ext2_ext_attr_header *header;
 struct ext2_ext_attr_entry *first, *entry;
 blk64_t quota_blocks = ((1) << (fs)->cluster_ratio_bits);
 __u64 quota_inodes = 0;
 region_t region = 0;
 int failed_csum = 0;

 ea_block_quota->blocks = 0;
 ea_block_quota->inodes = 0;

 blk = ext2fs_file_acl_block(fs, inode);
 if (blk == 0)
  return 0;
 if (!ext2fs_has_feature_xattr(fs->super) ||
     (blk < fs->super->s_first_data_block) ||
     (blk >= ext2fs_blocks_count(fs->super))) {
  mark_inode_bad(ctx, ino);
  return 0;
 }


 if (!ctx->block_ea_map) {
  pctx->errcode = e2fsck_allocate_block_bitmap(fs,
     (gettext ("ext attr block map")),
     2, "block_ea_map",
     &ctx->block_ea_map);
  if (pctx->errcode) {
   pctx->num = 2;
   fix_problem(ctx, 0x010025, pctx);
   ctx->flags |= 0x0001;
   return 0;
  }
 }


 if (!ctx->refcount) {
  pctx->errcode = ea_refcount_create(0, &ctx->refcount);
  if (pctx->errcode) {
   pctx->num = 1;
   fix_problem(ctx, 0x010038, pctx);
   ctx->flags |= 0x0001;
   return 0;
  }
 }







 if (ext2fs_fast_test_block_bitmap2(ctx->block_ea_map, blk)) {
  ea_block_quota->blocks = ((1) << (fs)->cluster_ratio_bits);
  ea_block_quota->inodes = 0;

  if (ctx->ea_block_quota_blocks) {
   ea_refcount_fetch(ctx->ea_block_quota_blocks, blk,
       &quota_blocks);
   if (quota_blocks)
    ea_block_quota->blocks = quota_blocks;
  }

  if (ctx->ea_block_quota_inodes)
   ea_refcount_fetch(ctx->ea_block_quota_inodes, blk,
       &ea_block_quota->inodes);

  if (ea_refcount_decrement(ctx->refcount, blk, 0) == 0)
   return 1;

  if (!ctx->refcount_extra) {
   pctx->errcode = ea_refcount_create(0,
        &ctx->refcount_extra);
   if (pctx->errcode) {
    pctx->num = 2;
    fix_problem(ctx, 0x010038, pctx);
    ctx->flags |= 0x0001;
    return 0;
   }
  }
  ea_refcount_increment(ctx->refcount_extra, blk, 0);
  return 1;
 }





 pctx->blk = blk;
 pctx->errcode = ext2fs_read_ext_attr3(fs, blk, block_buf, pctx->ino);
 if (pctx->errcode == (2133571479L)) {
  pctx->errcode = 0;
  failed_csum = 1;
 } else if (pctx->errcode == (2133571489L))
  pctx->errcode = 0;

 if (pctx->errcode &&
     fix_problem(ctx, 0x010039, pctx)) {
  pctx->errcode = 0;
  goto clear_extattr;
 }
 header = (struct ext2_ext_attr_header *) block_buf;
 pctx->blk = ext2fs_file_acl_block(fs, inode);
 if (((ctx->ext_attr_ver == 1) &&
      (header->h_magic != 0xEA010000)) ||
     ((ctx->ext_attr_ver == 2) &&
      (header->h_magic != 0xEA020000))) {
  if (fix_problem(ctx, 0x01003A, pctx))
   goto clear_extattr;
 }

 if (header->h_blocks != 1) {
  if (fix_problem(ctx, 0x01003E, pctx))
   goto clear_extattr;
 }

 if (pctx->errcode && fix_problem(ctx, 0x010039, pctx))
  goto clear_extattr;

 region = region_create(0, fs->blocksize);
 if (!region) {
  fix_problem(ctx, 0x01003F, pctx);
  ctx->flags |= 0x0001;
  return 0;
 }
 if (region_allocate(region, 0, sizeof(struct ext2_ext_attr_header))) {
  if (fix_problem(ctx, 0x010040, pctx))
   goto clear_extattr;
 }

 first = (struct ext2_ext_attr_entry *)(header+1);
 end = block_buf + fs->blocksize;
 entry = first;
 while ((char *)entry < end && *(__u32 *)entry) {
  __u32 hash;

  if (region_allocate(region, (char *)entry - (char *)header,
              (((entry->e_name_len) + (((unsigned) 1<<2)-1) + sizeof(struct ext2_ext_attr_entry)) & ~(((unsigned) 1<<2)-1)))) {
   if (fix_problem(ctx, 0x010040, pctx))
    goto clear_extattr;
   break;
  }
  if ((ctx->ext_attr_ver == 1 &&
       (entry->e_name_len == 0 || entry->e_name_index != 0)) ||
      (ctx->ext_attr_ver == 2 &&
       entry->e_name_index == 0)) {
   if (fix_problem(ctx, 0x010041, pctx))
    goto clear_extattr;
   break;
  }
  if (entry->e_value_inum == 0) {
   if (entry->e_value_offs + entry->e_value_size >
       fs->blocksize) {
    if (fix_problem(ctx, 0x010042, pctx))
     goto clear_extattr;
    break;
   }
   if (entry->e_value_size &&
       region_allocate(region, entry->e_value_offs,
         (((entry->e_value_size) + (((unsigned) 1<<2)-1)) & ~(((unsigned) 1<<2)-1)))) {
    if (fix_problem(ctx, 0x010040,
      pctx))
     goto clear_extattr;
   }

   hash = ext2fs_ext_attr_hash_entry(entry, block_buf +
         entry->e_value_offs);

   if (entry->e_hash != hash) {
    pctx->num = entry->e_hash;
    if (fix_problem(ctx, 0x010054, pctx))
     goto clear_extattr;
    entry->e_hash = hash;
   }
  } else {
   problem_t problem;
   blk64_t entry_quota_blocks;

   problem = check_large_ea_inode(ctx, entry, pctx,
             &entry_quota_blocks);
   if (problem && fix_problem(ctx, problem, pctx))
    goto clear_extattr;

   quota_blocks += entry_quota_blocks;
   quota_inodes++;
  }

  entry = ( (struct ext2_ext_attr_entry *)( (char *)(entry) + ((((entry)->e_name_len) + (((unsigned) 1<<2)-1) + sizeof(struct ext2_ext_attr_entry)) & ~(((unsigned) 1<<2)-1))) );
 }
 if (region_allocate(region, (char *)entry - (char *)header, 4)) {
  if (fix_problem(ctx, 0x010040, pctx))
   goto clear_extattr;
 }
 region_free(region);





 if (failed_csum &&
     fix_problem(ctx, 0x01006C, pctx)) {
  pctx->errcode = ext2fs_write_ext_attr3(fs, blk, block_buf,
             pctx->ino);
  if (pctx->errcode)
   return 0;
 }

 if (quota_blocks != ((1U) << (fs)->cluster_ratio_bits)) {
  if (!ctx->ea_block_quota_blocks) {
   pctx->errcode = ea_refcount_create(0,
      &ctx->ea_block_quota_blocks);
   if (pctx->errcode) {
    pctx->num = 3;
    goto refcount_fail;
   }
  }
  ea_refcount_store(ctx->ea_block_quota_blocks, blk,
      quota_blocks);
 }

 if (quota_inodes) {
  if (!ctx->ea_block_quota_inodes) {
   pctx->errcode = ea_refcount_create(0,
      &ctx->ea_block_quota_inodes);
   if (pctx->errcode) {
    pctx->num = 4;
refcount_fail:
    fix_problem(ctx, 0x010038, pctx);
    ctx->flags |= 0x0001;
    return 0;
   }
  }

  ea_refcount_store(ctx->ea_block_quota_inodes, blk,
      quota_inodes);
 }
 ea_block_quota->blocks = quota_blocks;
 ea_block_quota->inodes = quota_inodes;

 inc_ea_inode_refs(ctx, pctx, first, end);
 ea_refcount_store(ctx->refcount, blk, header->h_refcount - 1);
 mark_block_used(ctx, blk);
 ext2fs_fast_mark_block_bitmap2(ctx->block_ea_map, blk);
 return 1;

clear_extattr:
 if (region)
  region_free(region);
 ext2fs_file_acl_block_set(fs, inode, 0);
 e2fsck_write_inode(ctx, ino, inode, "check_ext_attr");
 return 0;
}


static int handle_htree(e2fsck_t ctx, struct problem_context *pctx,
   ext2_ino_t ino, struct ext2_inode *inode,
   char *block_buf)
{
 struct ext2_dx_root_info *root;
 ext2_filsys fs = ctx->fs;
 errcode_t retval;
 blk64_t blk;

 if ((!(((inode->i_mode) & 00170000) == 0040000) &&
      fix_problem(ctx, 0x010048, pctx)) ||
     (!ext2fs_has_feature_dir_index(fs->super) &&
      fix_problem(ctx, 0x010047, pctx)))
  return 1;

 pctx->errcode = ext2fs_bmap2(fs, ino, inode, 0, 0, 0, 0, &blk);

 if ((pctx->errcode) ||
     (blk == 0) ||
     (blk < fs->super->s_first_data_block) ||
     (blk >= ext2fs_blocks_count(fs->super))) {
  if (fix_problem(ctx, 0x010049, pctx))
   return 1;
  else
   return 0;
 }

 retval = io_channel_read_blk64(fs->io, blk, 1, block_buf);
 if (retval && fix_problem(ctx, 0x010049, pctx))
  return 1;


 root = (struct ext2_dx_root_info *) (block_buf + 24);

 if ((root->reserved_zero || root->info_length < 8) &&
     fix_problem(ctx, 0x010049, pctx))
  return 1;

 pctx->num = root->hash_version;
 if ((root->hash_version != 0) &&
     (root->hash_version != 1) &&
     (root->hash_version != 2) &&
     (root->hash_version != 6) &&
     fix_problem(ctx, 0x01004A, pctx))
  return 1;

 if (ext4_hash_in_dirent(inode)) {
  if (root->hash_version != 6 &&
      fix_problem(ctx, 0x01008D, pctx))
   return 1;
 } else {
  if (root->hash_version == 6 &&
     fix_problem(ctx, 0x01008E, pctx))
   return 1;
 }

 if ((root->unused_flags & 0x1) &&
     fix_problem(ctx, 0x01004B, pctx))
  return 1;

 pctx->num = root->indirect_levels;

 if (root->indirect_levels > 3 &&
     fix_problem(ctx, 0x01004C, pctx))
  return 1;


 if (root->indirect_levels > ext2_dir_htree_level(fs) &&
     !ext2fs_has_feature_largedir(fs->super)) {
  int blockbits = ((fs->super)->s_log_block_size + 10) + 10;
  unsigned idx_pb = 1 << (blockbits - 3);


  if (((pctx->inode)->i_size | ((__u64) (pctx->inode)->i_size_high << 32)) <
      (idx_pb - 1) * (idx_pb - 2) << blockbits &&
      pctx->inode->i_blocks <
      (idx_pb - 1) * (idx_pb - 2) << (blockbits - 9) &&
      fix_problem(ctx, 0x01004C, pctx))
   return 1;
 }

 if (root->indirect_levels > 2 ||
     ext2fs_needs_large_file_feature(((inode)->i_size | ((__u64) (inode)->i_size_high << 32))))
  ctx->large_dirs++;

 return 0;
}

void e2fsck_clear_inode(e2fsck_t ctx, ext2_ino_t ino,
   struct ext2_inode *inode, int restart_flag,
   const char *source)
{
 inode->i_flags = 0;
 inode->i_links_count = 0;
 ext2fs_icount_store(ctx->inode_link_info, ino, 0);
 inode->i_dtime = ctx->now;
 if (ino < (((ctx->fs->super)->s_rev_level == 0) ? 11 : (ctx->fs->super)->s_first_ino))
  memset(inode->i_block, 0, sizeof(inode->i_block));

 ext2fs_unmark_inode_bitmap2(ctx->inode_dir_map, ino);
 ext2fs_unmark_inode_bitmap2(ctx->inode_used_map, ino);
 if (ctx->inode_reg_map)
  ext2fs_unmark_inode_bitmap2(ctx->inode_reg_map, ino);
 if (ctx->inode_bad_map)
  ext2fs_unmark_inode_bitmap2(ctx->inode_bad_map, ino);





 ctx->flags |= restart_flag;

 if (ino == 1)
  memset(inode, 0, sizeof(struct ext2_inode));

 e2fsck_write_inode(ctx, ino, inode, source);
}







static int has_unaligned_cluster_map(e2fsck_t ctx,
         blk64_t last_pblk, blk64_t last_lblk,
         blk64_t pblk, blk64_t lblk)
{
 blk64_t cluster_mask;

 if (!ctx->fs->cluster_ratio_bits)
  return 0;
 cluster_mask = ((1 << (ctx->fs)->cluster_ratio_bits) - 1);





 if ((lblk & cluster_mask) != (pblk & cluster_mask))
  return 1;




 if (last_pblk && (lblk & cluster_mask) != 0 &&
     ((lblk) >> (ctx->fs)->cluster_ratio_bits) == ((last_lblk) >> (ctx->fs)->cluster_ratio_bits) &&
     ((pblk) >> (ctx->fs)->cluster_ratio_bits) != ((last_pblk) >> (ctx->fs)->cluster_ratio_bits))
  return 1;

 return 0;
}

static void scan_extent_node(e2fsck_t ctx, struct problem_context *pctx,
        struct process_block_struct *pb,
        blk64_t start_block, blk64_t end_block,
        blk64_t eof_block,
        ext2_extent_handle_t ehandle,
        int try_repairs)
{
 struct ext2fs_extent extent;
 blk64_t blk, last_lblk;
 unsigned int i, n;
 int is_dir, is_leaf;
 problem_t problem;
 struct ext2_extent_info info;
 int failed_csum = 0;

 if (pctx->errcode == (2133571476L))
  failed_csum = 1;

 pctx->errcode = ext2fs_extent_get_info(ehandle, &info);
 if (pctx->errcode)
  return;
 if (!(ctx->options & 0x8000) &&
     !pb->eti.force_rebuild) {
  struct extent_tree_level *etl;

  etl = pb->eti.ext_info + info.curr_level;
  etl->num_extents += info.num_entries;
  etl->max_extents += info.max_entries;







  if (info.curr_level && info.num_entries < info.max_entries)
   etl->max_extents--;
 }

 pctx->errcode = ext2fs_extent_get(ehandle, 0x0003,
       &extent);
 while ((pctx->errcode == 0 ||
  pctx->errcode == (2133571476L)) &&
        info.num_entries-- > 0) {
  is_leaf = extent.e_flags & 0x0001;
  is_dir = (((pctx->inode->i_mode) & 00170000) == 0040000);
  last_lblk = extent.e_lblk + extent.e_len - 1;

  problem = 0;
  pctx->blk = extent.e_pblk;
  pctx->blk2 = extent.e_lblk;
  pctx->num = extent.e_len;
  pctx->blkcount = extent.e_lblk + extent.e_len;

  if (extent.e_pblk == 0 ||
      extent.e_pblk < ctx->fs->super->s_first_data_block ||
      extent.e_pblk >= ext2fs_blocks_count(ctx->fs->super))
   problem = 0x010058;
  else if (extent.e_lblk < start_block)
   problem = 0x01005E;
  else if ((end_block && last_lblk > end_block) &&
    !(last_lblk > eof_block &&
      ((extent.e_flags & 0x0002) ||
       (pctx->inode->i_flags & 0x00100000))))
   problem = 0x01006E;
  else if (is_leaf && extent.e_len == 0)
   problem = 0x010066;
  else if (is_leaf &&
    (extent.e_pblk + extent.e_len) >
    ext2fs_blocks_count(ctx->fs->super))
   problem = 0x010059;
  else if (is_leaf && is_dir && !pctx->inode->i_size_high &&
    !ext2fs_has_feature_largedir(ctx->fs->super) &&
    ((extent.e_lblk + extent.e_len) >
     (1U << (21 - ctx->fs->super->s_log_block_size))))
   problem = 0x010044;

  if (is_leaf && problem == 0 && extent.e_len > 0) {







   if (extent.e_lblk < pb->next_lblock)
    problem = 0x01007D;
   else if (extent.e_lblk + extent.e_len > pb->next_lblock)
    pb->next_lblock = extent.e_lblk + extent.e_len;
  }





  if (try_repairs && is_dir && problem == 0 &&
      (extent.e_flags & 0x0002) &&
      fix_problem(ctx, 0x010073, pctx)) {
   extent.e_flags &= ~0x0002;
   pb->inode_modified = 1;
   pctx->errcode = ext2fs_extent_replace(ehandle, 0,
             &extent);
   if (pctx->errcode)
    return;
   failed_csum = 0;
  }
  if (try_repairs && problem) {
report_problem:
   if (fix_problem(ctx, problem, pctx)) {
    if (ctx->invalid_bitmaps) {







     pctx->errcode = ext2fs_extent_get(
         ehandle,
         0x0005,
         &extent);
     ctx->flags |= 0x0008;
     if (pctx->errcode ==
          (2133571456L)) {
      pctx->errcode = 0;
      break;
     }
     continue;
    }
    e2fsck_read_bitmaps(ctx);
    pb->inode_modified = 1;
    pctx->errcode =
     ext2fs_extent_delete(ehandle, 0);
    if (pctx->errcode) {
     pctx->str = "ext2fs_extent_delete";
     return;
    }
    pctx->errcode = ext2fs_extent_fix_parents(ehandle);
    if (pctx->errcode &&
        pctx->errcode != (2133571456L)) {
     pctx->str = "ext2fs_extent_fix_parents";
     return;
    }
    pctx->errcode = ext2fs_extent_get(ehandle,
          0x0000,
          &extent);
    if (pctx->errcode == (2133571456L)) {
     pctx->errcode = 0;
     break;
    }
    failed_csum = 0;
    continue;
   }
   goto next;
  }

  if (!is_leaf) {
   blk64_t lblk = extent.e_lblk;
   int next_try_repairs = 1;

   blk = extent.e_pblk;






   if (pb->ino != 7 &&
       extent.e_pblk < ctx->fs->super->s_blocks_count &&
       ext2fs_test_block_bitmap2(ctx->block_metadata_map,
            extent.e_pblk)) {
    next_try_repairs = 0;
    pctx->blk = blk;
    fix_problem(ctx,
         0x010071,
         pctx);
    if ((ctx->options & 0x0008) == 0)
     ctx->flags |= 0x0008;
   }
   pctx->errcode = ext2fs_extent_get(ehandle,
        0x000C, &extent);
   if (pctx->errcode &&
       pctx->errcode != (2133571476L)) {
    pctx->str = "EXT2_EXTENT_DOWN";
    problem = 0x01005F;
    if (!next_try_repairs)
     return;
    if (pctx->errcode == (2133571447L))
     goto report_problem;
    return;
   }

   if (extent.e_lblk != lblk) {
    struct ext2_extent_info e_info;

    pctx->errcode = ext2fs_extent_get_info(ehandle,
               &e_info);
    if (pctx->errcode) {
     pctx->str = "ext2fs_extent_get_info";
     return;
    }
    pctx->blk = lblk;
    pctx->blk2 = extent.e_lblk;
    pctx->num = e_info.curr_level - 1;
    problem = 0x01006D;
    if (fix_problem(ctx, problem, pctx)) {
     pb->inode_modified = 1;
     pctx->errcode =
      ext2fs_extent_fix_parents(ehandle);
     if (pctx->errcode) {
      pctx->str = "ext2fs_extent_fix_parents";
      return;
     }
    }
   }
   scan_extent_node(ctx, pctx, pb, extent.e_lblk,
      last_lblk, eof_block, ehandle,
      next_try_repairs);
   if (pctx->errcode)
    return;
   pctx->errcode = ext2fs_extent_get(ehandle,
        0x000B, &extent);
   if (pctx->errcode) {
    pctx->str = "EXT2_EXTENT_UP";
    return;
   }
   mark_block_used(ctx, blk);
   pb->num_blocks++;
   goto next;
  }

  if ((pb->previous_block != 0) &&
      (pb->previous_block+1 != extent.e_pblk)) {
   if (ctx->options & 0x0800) {
    char type = '?';

    if (pb->is_dir)
     type = 'd';
    else if (pb->is_reg)
     type = 'f';

    printf(("%6lu(%c): expecting %6lu "
     "actual extent "
     "phys %6lu log %lu len %lu\n"),
           (unsigned long) pctx->ino, type,
           (unsigned long) pb->previous_block+1,
           (unsigned long) extent.e_pblk,
           (unsigned long) extent.e_lblk,
           (unsigned long) extent.e_len);
   }
   pb->fragmented = 1;
  }






  if (try_repairs && is_dir &&
      pb->last_block + 1 < extent.e_lblk) {
   blk64_t new_lblk;

   new_lblk = pb->last_block + 1;
   if ((1 << (ctx->fs)->cluster_ratio_bits) > 1)
    new_lblk = ((new_lblk +
          (1 << (ctx->fs)->cluster_ratio_bits) - 1) &
         ~((1 << (ctx->fs)->cluster_ratio_bits) - 1)) |
        (extent.e_pblk &
         ((1 << (ctx->fs)->cluster_ratio_bits) - 1));
   pctx->blk = extent.e_lblk;
   pctx->blk2 = new_lblk;
   if (fix_problem(ctx, 0x010072, pctx)) {
    extent.e_lblk = new_lblk;
    pb->inode_modified = 1;
    pctx->errcode = ext2fs_extent_replace(ehandle,
        0, &extent);
    if (pctx->errcode) {
     pctx->errcode = 0;
     goto alloc_later;
    }
    pctx->errcode = ext2fs_extent_fix_parents(ehandle);
    if (pctx->errcode)
     goto failed_add_dir_block;
    pctx->errcode = ext2fs_extent_goto(ehandle,
        extent.e_lblk);
    if (pctx->errcode)
     goto failed_add_dir_block;
    last_lblk = extent.e_lblk + extent.e_len - 1;
    failed_csum = 0;
   }
  }
alloc_later:
  if (is_dir) {
   while (++pb->last_db_block <
          (e2_blkcnt_t) extent.e_lblk) {
    pctx->errcode = ext2fs_add_dir_block2(
       ctx->fs->dblist,
       pb->ino, 0,
       pb->last_db_block);
    if (pctx->errcode) {
     pctx->blk = 0;
     pctx->num = pb->last_db_block;
     goto failed_add_dir_block;
    }
   }

   for (i = 0; i < extent.e_len; i++) {
    pctx->errcode = ext2fs_add_dir_block2(
       ctx->fs->dblist,
       pctx->ino,
       extent.e_pblk + i,
       extent.e_lblk + i);
    if (pctx->errcode) {
     pctx->blk = extent.e_pblk + i;
     pctx->num = extent.e_lblk + i;
    failed_add_dir_block:
     fix_problem(ctx, 0x01002B, pctx);

     ctx->flags |= 0x0001;
     return;
    }
   }
   if (extent.e_len > 0)
    pb->last_db_block = extent.e_lblk + extent.e_len - 1;
  }
  if (has_unaligned_cluster_map(ctx, pb->previous_block,
           pb->last_block,
           extent.e_pblk,
           extent.e_lblk)) {
   for (i = 0; i < extent.e_len; i++) {
    pctx->blk = extent.e_lblk + i;
    pctx->blk2 = extent.e_pblk + i;
    fix_problem(ctx, 0x010074, pctx);
    mark_block_used(ctx, extent.e_pblk + i);
    mark_block_used(ctx, extent.e_pblk + i);
   }
  }




  if (ctx->fs->cluster_ratio_bits &&
      pb->previous_block &&
      (((extent.e_pblk) >> (ctx->fs)->cluster_ratio_bits) ==
       ((pb->previous_block) >> (ctx->fs)->cluster_ratio_bits)))

   blk = ((((extent.e_pblk) >> (ctx->fs)->cluster_ratio_bits) + 1) << (ctx->fs)->cluster_ratio_bits)

                                           ;
  else

   blk = ((((extent.e_pblk) >> (ctx->fs)->cluster_ratio_bits)) << (ctx->fs)->cluster_ratio_bits)
                                         ;

  if (blk < extent.e_pblk + extent.e_len) {
   mark_blocks_used(ctx, blk,
      extent.e_pblk + extent.e_len - blk);
   n = (((extent.e_pblk + extent.e_len - blk) + ((1 << (ctx->fs)->cluster_ratio_bits)) - 1) / ((1 << (ctx->fs)->cluster_ratio_bits)))
                                    ;
   pb->num_blocks += n;
  }
  pb->last_block = extent.e_lblk + extent.e_len - 1;
  pb->previous_block = extent.e_pblk + extent.e_len - 1;
  start_block = pb->last_block = last_lblk;
  if (is_leaf && !is_dir &&
      !(extent.e_flags & 0x0002))
   pb->last_init_lblock = last_lblk;
 next:
  pctx->errcode = ext2fs_extent_get(ehandle,
        0x0005,
        &extent);
 }


 if (failed_csum &&
     fix_problem(ctx, 0x01006A, pctx)) {
  pb->inode_modified = 1;
  pctx->errcode = ext2fs_extent_replace(ehandle, 0, &extent);
  if (pctx->errcode)
   return;
 }

 if (pctx->errcode == (2133571452L))
  pctx->errcode = 0;
}

static void check_blocks_extents(e2fsck_t ctx, struct problem_context *pctx,
     struct process_block_struct *pb)
{
 struct ext2_extent_info info;
 struct ext2_inode *inode = pctx->inode;
 ext2_extent_handle_t ehandle;
 ext2_filsys fs = ctx->fs;
 ext2_ino_t ino = pctx->ino;
 errcode_t retval;
 blk64_t eof_lblk;
 struct ext3_extent_header *eh;


 eh = (struct ext3_extent_header *) &inode->i_block[0];
 retval = ext2fs_extent_header_verify(eh, sizeof(inode->i_block));
 if (retval) {
  if (fix_problem(ctx, 0x010081, pctx))
   e2fsck_clear_inode(ctx, ino, inode, 0,
        "check_blocks_extents");
  pctx->errcode = 0;
  return;
 }


 pctx->errcode = ext2fs_extent_open2(fs, ino, inode, &ehandle);
 if (pctx->errcode) {
  if (fix_problem(ctx, 0x010056, pctx))
   e2fsck_clear_inode(ctx, ino, inode, 0,
        "check_blocks_extents");
  pctx->errcode = 0;
  return;
 }

 retval = ext2fs_extent_get_info(ehandle, &info);
 if (retval == 0) {
  int max_depth = info.max_depth;

  if (max_depth >= 5)
   max_depth = 5 -1;
  ctx->extent_depth_count[max_depth]++;
 }


 pctx->blk = info.max_depth;
 pctx->blk2 = ext2fs_max_extent_depth(ehandle);
 if (pctx->blk2 < pctx->blk &&
     fix_problem(ctx, 0x01007F, pctx))
  pb->eti.force_rebuild = 1;


 pctx->blk = 5;
 if (pctx->blk2 > pctx->blk)
  fix_problem(ctx, 0x014005, pctx);
 memset(pb->eti.ext_info, 0, sizeof(pb->eti.ext_info));
 pb->eti.ino = pb->ino;

 pb->next_lblock = 0;

 eof_lblk = ((((inode)->i_size | ((__u64) (inode)->i_size_high << 32)) + fs->blocksize - 1) >>
  ((fs->super)->s_log_block_size + 10)) - 1;
 scan_extent_node(ctx, pctx, pb, 0, 0, eof_lblk, ehandle, 1);
 if (pctx->errcode &&
     fix_problem(ctx, 0x010057, pctx)) {
  pb->num_blocks = 0;
  inode->i_blocks = 0;
  e2fsck_clear_inode(ctx, ino, inode, 0x0004,
       "check_blocks_extents");
  pctx->errcode = 0;
 }
 ext2fs_extent_free(ehandle);


 if ((((inode->i_mode) & 00170000) == 0040000) &&
     e2fsck_dir_will_be_rehashed(ctx, ino))
  return;

 if (ctx->options & 0x4000)
  e2fsck_rebuild_extents_later(ctx, ino);
 else
  e2fsck_should_rebuild_extents(ctx, pctx, &pb->eti, &info);
}






static void check_blocks_inline_data(e2fsck_t ctx, struct problem_context *pctx,
         struct process_block_struct *pb)
{
 int flags;
 size_t inline_data_size = 0;

 if (!pb->is_dir) {
  pctx->errcode = 0;
  return;
 }


 pctx->errcode = ext2fs_add_dir_block2(ctx->fs->dblist, pb->ino, 0, 0);
 if (pctx->errcode)
  goto err;


 flags = ctx->fs->flags;
 ctx->fs->flags |= 0x200000;
 pctx->errcode = ext2fs_inline_data_size(ctx->fs, pb->ino,
      &inline_data_size);
 ctx->fs->flags = (flags & 0x200000) |
    (ctx->fs->flags & ~0x200000);
 if (pctx->errcode) {
  pctx->errcode = 0;
  return;
 }

 if (inline_data_size <= ((sizeof(__u32) * (((12 + 1) + 1) + 1))))
  return;

 pctx->errcode = ext2fs_add_dir_block2(ctx->fs->dblist, pb->ino, 0, 1);
 if (pctx->errcode)
  goto err;

 return;
err:
 pctx->blk = 0;
 pctx->num = 0;
 fix_problem(ctx, 0x01002B, pctx);
 ctx->flags |= 0x0001;
}





static void check_blocks(e2fsck_t ctx, struct problem_context *pctx,
    char *block_buf, const struct ea_quota *ea_ibody_quota)
{
 ext2_filsys fs = ctx->fs;
 struct process_block_struct pb;
 ext2_ino_t ino = pctx->ino;
 struct ext2_inode *inode = pctx->inode;
 unsigned bad_size = 0;
 int dirty_inode = 0;
 int extent_fs;
 int inlinedata_fs;
 __u64 size;
 struct ea_quota ea_block_quota;

 pb.ino = ino;
 pb.num_blocks = ((ea_ibody_quota ? ea_ibody_quota->blocks : 0) >> (ctx->fs)->cluster_ratio_bits)
                                                   ;
 pb.last_block = ~0;
 pb.last_init_lblock = -1;
 pb.last_db_block = -1;
 pb.num_illegal_blocks = 0;
 pb.suppress = 0; pb.clear = 0;
 pb.fragmented = 0;
 pb.compressed = 0;
 pb.previous_block = 0;
 pb.is_dir = (((inode->i_mode) & 00170000) == 0040000);
 pb.is_reg = (((inode->i_mode) & 00170000) == 0100000);
 pb.max_blocks = 1U << (31 - fs->super->s_log_block_size);
 pb.inode = inode;
 pb.pctx = pctx;
 pb.ctx = ctx;
 pb.inode_modified = 0;
 pb.eti.force_rebuild = 0;
 pctx->ino = ino;
 pctx->errcode = 0;

 extent_fs = ext2fs_has_feature_extents(ctx->fs->super);
 inlinedata_fs = ext2fs_has_feature_inline_data(ctx->fs->super);

 if (check_ext_attr(ctx, pctx, block_buf, &ea_block_quota)) {
  if (ctx->flags & (0x0001 | 0x0002))
   goto out;
  pb.num_blocks += ((ea_block_quota.blocks) >> (ctx->fs)->cluster_ratio_bits);
 }

 if (inlinedata_fs && (inode->i_flags & 0x10000000))
  check_blocks_inline_data(ctx, pctx, &pb);
 else if (ext2fs_inode_has_valid_blocks2(fs, inode)) {
  if (extent_fs && (inode->i_flags & 0x00080000))
   check_blocks_extents(ctx, pctx, &pb);
  else {
   int flags;




   if (dirty_inode) {
    e2fsck_write_inode(ctx, ino, inode,
         "check_blocks");
    dirty_inode = 0;
   }
   flags = fs->flags;
   fs->flags |= 0x200000;
   pctx->errcode = ext2fs_block_iterate3(fs, ino,
      pb.is_dir ? 1 : 0,
      block_buf, process_block, &pb);




   pb.last_init_lblock = pb.last_block;






   if (pb.inode_modified)
    e2fsck_read_inode(ctx, ino, inode,
        "check_blocks");
   fs->flags = (flags & 0x200000) |
        (fs->flags & ~0x200000);

   if (ctx->options & 0x4000) {



    if (!(((inode->i_mode) & 00170000) == 0040000) ||
        !e2fsck_dir_will_be_rehashed(ctx, ino))
     e2fsck_rebuild_extents_later(ctx, ino);
   }
  }
 }
 end_problem_latch(ctx, 0x0010);
 end_problem_latch(ctx, 0x0080);
 if (ctx->flags & (0x0001 | 0x0002))
  goto out;
 if (pctx->errcode)
  fix_problem(ctx, 0x010029, pctx);

 if (pb.fragmented && pb.num_blocks < fs->super->s_blocks_per_group) {
  if ((((inode->i_mode) & 00170000) == 0040000))
   ctx->fs_fragmented_dir++;
  else
   ctx->fs_fragmented++;
 }

 if (pb.clear) {
  e2fsck_clear_inode(ctx, ino, inode, 0x0004,
       "check_blocks");
  return;
 }

 if (inode->i_flags & 0x00001000) {
  if (handle_htree(ctx, pctx, ino, inode, block_buf)) {
   inode->i_flags &= ~0x00001000;
   dirty_inode++;
  } else {
   e2fsck_add_dx_dir(ctx, ino, inode, pb.last_block+1);
  }
 }

 if (!pb.num_blocks && pb.is_dir &&
     !(inode->i_flags & 0x10000000)) {
  if (fix_problem(ctx, 0x010006, pctx)) {
   e2fsck_clear_inode(ctx, ino, inode, 0, "check_blocks");
   ctx->fs_directory_count--;
   return;
  }
 }

 if (ino != quota_type2inum(PRJQUOTA, fs->super) &&
     (ino == 2 || ino >= (((ctx->fs->super)->s_rev_level == 0) ? 11 : (ctx->fs->super)->s_first_ino)) &&
     !(inode->i_flags & 0x00200000)) {
  quota_data_add(ctx->qctx, (struct ext2_inode_large *) inode,
          ino,
          pb.num_blocks * ((1 << 10) << (fs->super)->s_log_cluster_size));
  quota_data_inodes(ctx->qctx, (struct ext2_inode_large *) inode,
      ino, (ea_ibody_quota ?
     ea_ibody_quota->inodes : 0) +
      ea_block_quota.inodes + 1);
 }

 if (!ext2fs_has_feature_huge_file(fs->super) ||
     !(inode->i_flags & 0x00040000))
  pb.num_blocks *= (fs->blocksize / 512);
 pb.num_blocks *= (1 << (fs)->cluster_ratio_bits);






 size = ((inode)->i_size | ((__u64) (inode)->i_size_high << 32));
 if (pb.is_dir) {
  unsigned nblock = size >> ((fs->super)->s_log_block_size + 10);
  if (inode->i_flags & 0x10000000) {
   int flags;
   size_t sz = 0;
   errcode_t err;

   flags = ctx->fs->flags;
   ctx->fs->flags |= 0x200000;
   err = ext2fs_inline_data_size(ctx->fs, pctx->ino,
            &sz);
   ctx->fs->flags = (flags &
       0x200000) |
      (ctx->fs->flags &
       ~0x200000);
   if (err || sz != size) {
    bad_size = 7;
    pctx->num = sz;
   }
  } else if (size & (fs->blocksize - 1))
   bad_size = 5;
  else if (nblock > (pb.last_block + 1))
   bad_size = 1;
  else if (nblock < (pb.last_block + 1)) {
   if (((pb.last_block + 1) - nblock) >
       fs->super->s_prealloc_dir_blocks)
    bad_size = 2;
  }
 } else {
  if ((pb.last_init_lblock >= 0) &&

      (size < (__u64)pb.last_init_lblock * fs->blocksize) &&
      !(inode->i_flags & 0x00100000))
   bad_size = 3;
  else if (!(extent_fs && (inode->i_flags & 0x00080000)) &&
    size > ext2_max_sizes[fs->super->s_log_block_size])

   bad_size = 4;
  else if ((extent_fs && (inode->i_flags & 0x00080000)) &&
    size >
    ((1ULL << (32 + ((fs->super)->s_log_block_size + 10))) - 1))

   bad_size = 6;
 }

 if (bad_size && !(((inode->i_mode) & 00170000) == 0120000)) {

  if (bad_size != 7)
   pctx->num = (pb.last_block + 1) * fs->blocksize;
  pctx->group = bad_size;
  if (fix_problem(ctx, 0x01000C, pctx)) {
   ext2fs_inode_size_set(fs, inode, pctx->num);
   if (((inode)->i_size | ((__u64) (inode)->i_size_high << 32)) == 0 &&
       (inode->i_flags & 0x10000000)) {
    memset(inode->i_block, 0,
           sizeof(inode->i_block));
    inode->i_flags &= ~0x10000000;
   }
   dirty_inode++;
  }
  pctx->num = 0;
 }
 if ((((inode->i_mode) & 00170000) == 0100000) &&
     ext2fs_needs_large_file_feature(((inode)->i_size | ((__u64) (inode)->i_size_high << 32))))
  ctx->large_files++;
 if ((fs->super->s_creator_os != 1) &&
     ((pb.num_blocks != ext2fs_inode_i_blocks(fs, inode)) ||
      (ext2fs_has_feature_huge_file(fs->super) &&
       (inode->i_flags & 0x00040000) &&
       (inode->osd2.linux2.l_i_blocks_hi != 0)))) {
  pctx->num = pb.num_blocks;
  if (fix_problem(ctx, 0x01000D, pctx)) {
   inode->i_blocks = pb.num_blocks;
   inode->osd2.linux2.l_i_blocks_hi = pb.num_blocks >> 32;
   dirty_inode++;
  }
  pctx->num = 0;
 }






 if (ext2fs_has_feature_bigalloc(fs->super) &&
     ((((inode->i_mode) & 00170000) == 0100000) || (((inode->i_mode) & 00170000) == 0040000)) &&
     ext2fs_inode_data_blocks2(fs, inode) > 0 &&
     (ino == 2 || ino >= (((fs->super)->s_rev_level == 0) ? 11 : (fs->super)->s_first_ino)) &&
     !(inode->i_flags & (0x00080000 | 0x10000000)) &&
     fix_problem(ctx, 0x010080, pctx)) {
  pctx->errcode = e2fsck_rebuild_extents_later(ctx, ino);
  if (pctx->errcode)
   goto out;
 }

 if (ctx->dirs_to_hash && pb.is_dir &&
     !(ctx->lost_and_found && ctx->lost_and_found == ino) &&
     !(inode->i_flags & 0x00001000) &&
     ((inode->i_size / fs->blocksize) >= 3))
  e2fsck_rehash_dir_later(ctx, ino);

out:
 if (dirty_inode)
  e2fsck_write_inode(ctx, ino, inode, "check_blocks");
}
static int process_block(ext2_filsys fs,
    blk64_t *block_nr,
    e2_blkcnt_t blockcnt,
    blk64_t ref_block __attribute__((unused)),
    int ref_offset __attribute__((unused)),
    void *priv_data)
{
 struct process_block_struct *p;
 struct problem_context *pctx;
 blk64_t blk = *block_nr;
 int ret_code = 0;
 problem_t problem = 0;
 e2fsck_t ctx;

 p = (struct process_block_struct *) priv_data;
 pctx = p->pctx;
 ctx = p->ctx;






 if (p->is_dir && blockcnt == 0 && blk == 0) {
  pctx->errcode = ext2fs_add_dir_block2(fs->dblist, p->ino, 0, 0);
  if (pctx->errcode) {
   pctx->blk = blk;
   pctx->num = blockcnt;
   goto failed_add_dir_block;
  }
  p->last_db_block++;
 }

 if (blk == 0)
  return 0;
 if (p->previous_block && p->ino != 7) {
  if (p->previous_block+1 != blk) {
   if (ctx->options & 0x0800) {
    char type = '?';

    if (p->is_dir)
     type = 'd';
    else if (p->is_reg)
     type = 'f';

    printf((gettext ("%6lu(%c): expecting %6lu " "got phys %6lu (blkcnt %lld)\n"))
                                      ,
           (unsigned long) pctx->ino, type,
           (unsigned long) p->previous_block+1,
           (unsigned long) blk,
           (long long) blockcnt);
   }
   p->fragmented = 1;
  }
 }

 if (p->is_dir && !ext2fs_has_feature_largedir(fs->super) &&
     !pctx->inode->i_size_high &&
     blockcnt > (1 << (21 - fs->super->s_log_block_size)))
  problem = 0x010044;
 if (p->is_dir && p->num_blocks + 1 >= p->max_blocks)
  problem = 0x010044;
 if (p->is_reg && p->num_blocks + 1 >= p->max_blocks)
  problem = 0x010045;
 if (!p->is_dir && !p->is_reg && blockcnt > 0)
  problem = 0x010046;

 if (blk < fs->super->s_first_data_block ||
     blk >= ext2fs_blocks_count(fs->super))
  problem = 0x01000E;







 if (blockcnt < 0 &&
     p->ino != 7 &&
     blk < ctx->fs->super->s_blocks_count &&
     ext2fs_test_block_bitmap2(ctx->block_metadata_map, blk)) {
  pctx->blk = blk;
  fix_problem(ctx, 0x010071, pctx);
  if ((ctx->options & 0x0008) == 0)
   ctx->flags |= 0x0008;
 }

 if (problem) {
  p->num_illegal_blocks++;
  if (p->ino != 7 &&
      ref_block != 0 &&
      ext2fs_test_block_bitmap2(ctx->block_metadata_map,
           ref_block)) {
   *block_nr = 0;
   return 0;
  }
  if (!p->suppress && (p->num_illegal_blocks % 12) == 0) {
   if (fix_problem(ctx, 0x010011, pctx)) {
    p->clear = 1;
    return 2;
   }
   if (fix_problem(ctx, 0x01002D, pctx)) {
    p->suppress = 1;
    set_latch_flags(0x0010,
      0x0008, 0);
   }
  }
  pctx->blk = blk;
  pctx->blkcount = blockcnt;
  if (fix_problem(ctx, problem, pctx)) {
   blk = *block_nr = 0;
   ret_code = 1;
   p->inode_modified = 1;
   if (problem == 0x010044)
    return ret_code;
   goto mark_dir;
  } else
   return 0;
 }

 if (p->ino == 7) {







  if (blockcnt == (-2))
   mark_block_used(ctx, blk);
  p->num_blocks++;
 } else if (!(ctx->fs->cluster_ratio_bits &&
       p->previous_block &&
       (((blk) >> (ctx->fs)->cluster_ratio_bits) ==
        ((p->previous_block) >> (ctx->fs)->cluster_ratio_bits)) &&
       (blk & ((1 << (ctx->fs)->cluster_ratio_bits) - 1)) ==
       ((unsigned) blockcnt & ((1 << (ctx->fs)->cluster_ratio_bits) - 1)))) {
  mark_block_used(ctx, blk);
  p->num_blocks++;
 } else if (has_unaligned_cluster_map(ctx, p->previous_block,
          p->last_block, blk, blockcnt)) {
  pctx->blk = blockcnt;
  pctx->blk2 = blk;
  fix_problem(ctx, 0x010074, pctx);
  mark_block_used(ctx, blk);
  mark_block_used(ctx, blk);
 }
 if (blockcnt >= 0)
  p->last_block = blockcnt;
 p->previous_block = blk;
mark_dir:
 if (p->is_dir && (blockcnt >= 0)) {
  while (++p->last_db_block < blockcnt) {
   pctx->errcode = ext2fs_add_dir_block2(fs->dblist,
             p->ino, 0,
             p->last_db_block);
   if (pctx->errcode) {
    pctx->blk = 0;
    pctx->num = p->last_db_block;
    goto failed_add_dir_block;
   }
  }
  pctx->errcode = ext2fs_add_dir_block2(fs->dblist, p->ino,
            blk, blockcnt);
  if (pctx->errcode) {
   pctx->blk = blk;
   pctx->num = blockcnt;
  failed_add_dir_block:
   fix_problem(ctx, 0x01002B, pctx);

   ctx->flags |= 0x0001;
   return 2;
  }
 }
 return ret_code;
}

static int process_bad_block(ext2_filsys fs,
        blk64_t *block_nr,
        e2_blkcnt_t blockcnt,
        blk64_t ref_block __attribute__((unused)),
        int ref_offset __attribute__((unused)),
        void *priv_data)
{
 struct process_block_struct *p;
 blk64_t blk = *block_nr;
 blk64_t first_block;
 dgrp_t i;
 struct problem_context *pctx;
 e2fsck_t ctx;

 if (!blk)
  return 0;

 p = (struct process_block_struct *) priv_data;
 ctx = p->ctx;
 pctx = p->pctx;

 pctx->ino = 1;
 pctx->blk = blk;
 pctx->blkcount = blockcnt;

 if ((blk < fs->super->s_first_data_block) ||
     (blk >= ext2fs_blocks_count(fs->super))) {
  if (fix_problem(ctx, 0x010012, pctx)) {
   *block_nr = 0;
   return 1;
  } else
   return 0;
 }

 if (blockcnt < 0) {
  if (ext2fs_test_block_bitmap2(p->fs_meta_blocks, blk)) {
   p->bbcheck = 1;
   if (fix_problem(ctx, 0x01004D, pctx)) {
    *block_nr = 0;
    return 1;
   }
  } else if (ext2fs_test_block_bitmap2(ctx->block_found_map,
          blk)) {
   p->bbcheck = 1;
   if (fix_problem(ctx, 0x010015,
     pctx)) {
    *block_nr = 0;
    return 1;
   }
   if (ctx->flags & (0x0001 | 0x0002))
    return 2;
  } else
   mark_block_used(ctx, blk);
  return 0;
 }



 ctx->fs_badblocks_count++;






 if (!ext2fs_test_block_bitmap2(ctx->block_found_map, blk)) {
  ext2fs_mark_block_bitmap2(ctx->block_found_map, blk);
  return 0;
 }



 first_block = fs->super->s_first_data_block;

 for (i = 0; i < fs->group_desc_count; i++ ) {
  pctx->group = i;
  pctx->blk = blk;
  if (!ext2fs_bg_has_super(fs, i))
   goto skip_super;
  if (blk == first_block) {
   if (i == 0) {
    if (fix_problem(ctx,
      0x010019,
      pctx)) {
     *block_nr = 0;
     return 1;
    }
    return 0;
   }
   fix_problem(ctx, 0x01001B, pctx);
   return 0;
  }
  if ((blk > first_block) &&
      (blk <= first_block + fs->desc_blocks)) {
   if (i == 0) {
    pctx->blk = *block_nr;
    if (fix_problem(ctx,
   0x01001A, pctx)) {
     *block_nr = 0;
     return 1;
    }
    return 0;
   }
   fix_problem(ctx, 0x01001C, pctx);
   return 0;
  }
 skip_super:
  if (blk == ext2fs_block_bitmap_loc(fs, i)) {
   if (fix_problem(ctx, 0x01000A, pctx)) {
    ctx->invalid_block_bitmap_flag[i]++;
    ctx->invalid_bitmaps++;
   }
   return 0;
  }
  if (blk == ext2fs_inode_bitmap_loc(fs, i)) {
   if (fix_problem(ctx, 0x01000B, pctx)) {
    ctx->invalid_inode_bitmap_flag[i]++;
    ctx->invalid_bitmaps++;
   }
   return 0;
  }
  if ((blk >= ext2fs_inode_table_loc(fs, i)) &&
      (blk < (ext2fs_inode_table_loc(fs, i) +
       fs->inode_blocks_per_group))) {





   return 0;
  }
  first_block += fs->super->s_blocks_per_group;
 }





 if ((blk == p->inode->i_block[12]) ||
     (blk == p->inode->i_block[(12 + 1)]) ||
     (blk == p->inode->i_block[((12 + 1) + 1)])) {
  p->bbcheck = 1;
  if (fix_problem(ctx, 0x010015, pctx)) {
   *block_nr = 0;
   return 1;
  }
  if (ctx->flags & (0x0001 | 0x0002))
   return 2;
  return 0;
 }

 pctx->group = -1;


 fix_problem(ctx, 0x01001D, pctx);

 return 0;
}

static void new_table_block(e2fsck_t ctx, blk64_t first_block, dgrp_t group,
       const char *name, int num, blk64_t *new_block)
{
 ext2_filsys fs = ctx->fs;
 dgrp_t last_grp;
 blk64_t old_block = *new_block;
 blk64_t last_block;
 dgrp_t flexbg;
 unsigned flexbg_size;
 int i, is_flexbg;
 char *buf;
 struct problem_context pctx;

 clear_problem_context(&pctx);

 pctx.group = group;
 pctx.blk = old_block;
 pctx.str = name;






 is_flexbg = ext2fs_has_feature_flex_bg(fs->super);
 if (is_flexbg) {
  flexbg_size = 1 << fs->super->s_log_groups_per_flex;
  flexbg = group / flexbg_size;
  first_block = ext2fs_group_first_block2(fs,
       flexbg_size * flexbg);
  last_grp = group | (flexbg_size - 1);
  if (last_grp >= fs->group_desc_count)
   last_grp = fs->group_desc_count - 1;
  last_block = ext2fs_group_last_block2(fs, last_grp);
 } else
  last_block = ext2fs_group_last_block2(fs, group);
 pctx.errcode = ext2fs_get_free_blocks2(fs, first_block, last_block,
            num, ctx->block_found_map,
            new_block);
 if (is_flexbg && (pctx.errcode == (2133571400L)))
  pctx.errcode = ext2fs_get_free_blocks2(fs,
    fs->super->s_first_data_block,
    ext2fs_blocks_count(fs->super),
    num, ctx->block_found_map, new_block);
 if (pctx.errcode) {
  pctx.num = num;
  fix_problem(ctx, 0x01001E, &pctx);
  ext2fs_unmark_valid(fs);
  ctx->flags |= 0x0001;
  return;
 }
 pctx.errcode = ext2fs_get_mem(fs->blocksize, &buf);
 if (pctx.errcode) {
  fix_problem(ctx, 0x01001F, &pctx);
  ext2fs_unmark_valid(fs);
  ctx->flags |= 0x0001;
  return;
 }
 ext2fs_mark_super_dirty(fs);
 fs->flags &= ~0x200;
 pctx.blk2 = *new_block;
 fix_problem(ctx, (old_block ? 0x010020 :
     0x010021), &pctx);
 pctx.blk2 = 0;
 for (i = 0; i < num; i++) {
  pctx.blk = i;
  ext2fs_mark_block_bitmap2(ctx->block_found_map, (*new_block)+i);
  if (old_block) {
   pctx.errcode = io_channel_read_blk64(fs->io,
       old_block + i, 1, buf);
   if (pctx.errcode)
    fix_problem(ctx, 0x010022, &pctx);
   pctx.blk = (*new_block) + i;
   pctx.errcode = io_channel_write_blk64(fs->io, pctx.blk,
             1, buf);
  } else {
   pctx.blk = (*new_block) + i;
   pctx.errcode = ext2fs_zero_blocks2(fs, pctx.blk, 1,
          
         ((void *)0)
             , 
               ((void *)0)
                   );
  }

  if (pctx.errcode)
   fix_problem(ctx, 0x010023, &pctx);
 }
 ext2fs_free_mem(&buf);
}
static void handle_fs_bad_blocks(e2fsck_t ctx)
{
 ext2_filsys fs = ctx->fs;
 dgrp_t i;
 blk64_t first_block;
 blk64_t new_blk;

 for (i = 0; i < fs->group_desc_count; i++) {
  first_block = ext2fs_group_first_block2(fs, i);

  if (ctx->invalid_block_bitmap_flag[i]) {
   new_blk = ext2fs_block_bitmap_loc(fs, i);
   new_table_block(ctx, first_block, i, (gettext ("block bitmap")),
     1, &new_blk);
   ext2fs_block_bitmap_loc_set(fs, i, new_blk);
  }
  if (ctx->invalid_inode_bitmap_flag[i]) {
   new_blk = ext2fs_inode_bitmap_loc(fs, i);
   new_table_block(ctx, first_block, i, (gettext ("inode bitmap")),
     1, &new_blk);
   ext2fs_inode_bitmap_loc_set(fs, i, new_blk);
  }
  if (ctx->invalid_inode_table_flag[i]) {
   new_blk = ext2fs_inode_table_loc(fs, i);
   new_table_block(ctx, first_block, i, (gettext ("inode table")),
     fs->inode_blocks_per_group,
     &new_blk);
   ext2fs_inode_table_loc_set(fs, i, new_blk);
   ctx->flags |= 0x0004;
  }
 }
 ctx->invalid_bitmaps = 0;
}





static void mark_table_blocks(e2fsck_t ctx)
{
 ext2_filsys fs = ctx->fs;
 blk64_t b;
 dgrp_t i;
 unsigned int j;
 struct problem_context pctx;

 clear_problem_context(&pctx);

 for (i = 0; i < fs->group_desc_count; i++) {
  pctx.group = i;

  ext2fs_reserve_super_and_bgd(fs, i, ctx->block_found_map);
  ext2fs_reserve_super_and_bgd(fs, i, ctx->block_metadata_map);




  if (ext2fs_inode_table_loc(fs, i)) {
   for (j = 0, b = ext2fs_inode_table_loc(fs, i);
        j < fs->inode_blocks_per_group;
        j++, b++) {
    if (ext2fs_test_block_bitmap2(ctx->block_found_map,
            b)) {
     pctx.blk = b;
     if (!ctx->invalid_inode_table_flag[i] &&
         fix_problem(ctx,
      0x010009, &pctx)) {
      ctx->invalid_inode_table_flag[i]++;
      ctx->invalid_bitmaps++;
     }
    } else {
        ext2fs_mark_block_bitmap2(
      ctx->block_found_map, b);
        ext2fs_mark_block_bitmap2(
      ctx->block_metadata_map, b);
        }
   }
  }




  if (ext2fs_block_bitmap_loc(fs, i)) {
   if (ext2fs_test_block_bitmap2(ctx->block_found_map,
         ext2fs_block_bitmap_loc(fs, i))) {
    pctx.blk = ext2fs_block_bitmap_loc(fs, i);
    if (fix_problem(ctx, 0x010007, &pctx)) {
     ctx->invalid_block_bitmap_flag[i]++;
     ctx->invalid_bitmaps++;
    }
   } else {
       ext2fs_mark_block_bitmap2(ctx->block_found_map,
         ext2fs_block_bitmap_loc(fs, i));
       ext2fs_mark_block_bitmap2(ctx->block_metadata_map,
         ext2fs_block_bitmap_loc(fs, i));
   }
  }



  if (ext2fs_inode_bitmap_loc(fs, i)) {
   if (ext2fs_test_block_bitmap2(ctx->block_found_map,
         ext2fs_inode_bitmap_loc(fs, i))) {
    pctx.blk = ext2fs_inode_bitmap_loc(fs, i);
    if (fix_problem(ctx, 0x010008, &pctx)) {
     ctx->invalid_inode_bitmap_flag[i]++;
     ctx->invalid_bitmaps++;
    }
   } else {
       ext2fs_mark_block_bitmap2(ctx->block_metadata_map,
         ext2fs_inode_bitmap_loc(fs, i));
       ext2fs_mark_block_bitmap2(ctx->block_found_map,
         ext2fs_inode_bitmap_loc(fs, i));
   }
  }
 }
}







static errcode_t pass1_get_blocks(ext2_filsys fs, ext2_ino_t ino,
      blk_t *blocks)
{
 e2fsck_t ctx = (e2fsck_t) fs->priv_data;
 int i;

 if ((ino != ctx->stashed_ino) || !ctx->stashed_inode)
  return (2133571393L);

 for (i=0; i < (((12 + 1) + 1) + 1); i++)
  blocks[i] = ctx->stashed_inode->i_block[i];
 return 0;
}

static errcode_t pass1_read_inode(ext2_filsys fs, ext2_ino_t ino,
      struct ext2_inode *inode)
{
 e2fsck_t ctx = (e2fsck_t) fs->priv_data;

 if ((ino != ctx->stashed_ino) || !ctx->stashed_inode)
  return (2133571393L);
 *inode = *ctx->stashed_inode;
 return 0;
}

static errcode_t pass1_write_inode(ext2_filsys fs, ext2_ino_t ino,
       struct ext2_inode *inode)
{
 e2fsck_t ctx = (e2fsck_t) fs->priv_data;

 if ((ino == ctx->stashed_ino) && ctx->stashed_inode &&
  (inode != ctx->stashed_inode))
  *ctx->stashed_inode = *inode;
 return (2133571393L);
}

static errcode_t pass1_check_directory(ext2_filsys fs, ext2_ino_t ino)
{
 e2fsck_t ctx = (e2fsck_t) fs->priv_data;

 if ((ino != ctx->stashed_ino) || !ctx->stashed_inode)
  return (2133571393L);

 if (!(((ctx->stashed_inode->i_mode) & 00170000) == 0040000))
  return (2133571402L);
 return 0;
}

static errcode_t e2fsck_get_alloc_block(ext2_filsys fs, blk64_t goal,
     blk64_t *ret)
{
 e2fsck_t ctx = (e2fsck_t) fs->priv_data;
 errcode_t retval;
 blk64_t new_block;

 if (ctx->block_found_map) {
  retval = ext2fs_new_block2(fs, goal, ctx->block_found_map,
        &new_block);
  if (retval)
   return retval;
  if (fs->block_map) {
   ext2fs_mark_block_bitmap2(fs->block_map, new_block);
   ext2fs_mark_bb_dirty(fs);
  }
 } else {
  if (!fs->block_map) {
   retval = ext2fs_read_block_bitmap(fs);
   if (retval)
    return retval;
  }

  retval = ext2fs_new_block2(fs, goal, fs->block_map, &new_block);
  if (retval)
   return retval;
 }

 *ret = new_block;
 return (0);
}

static errcode_t e2fsck_new_range(ext2_filsys fs, int flags, blk64_t goal,
      blk64_t len, blk64_t *pblk, blk64_t *plen)
{
 e2fsck_t ctx = (e2fsck_t) fs->priv_data;
 errcode_t retval;

 if (ctx->block_found_map)
  return ext2fs_new_range(fs, flags, goal, len,
     ctx->block_found_map, pblk, plen);

 if (!fs->block_map) {
  retval = ext2fs_read_block_bitmap(fs);
  if (retval)
   return retval;
 }

 return ext2fs_new_range(fs, flags, goal, len, fs->block_map,
    pblk, plen);
}

static void e2fsck_block_alloc_stats(ext2_filsys fs, blk64_t blk, int inuse)
{
 e2fsck_t ctx = (e2fsck_t) fs->priv_data;


 if (ctx->block_found_map &&
     ctx->block_metadata_map &&
     inuse < 0 &&
     ext2fs_test_block_bitmap2(ctx->block_metadata_map, blk))
  return;

 if (ctx->block_found_map) {
  if (inuse > 0)
   ext2fs_mark_block_bitmap2(ctx->block_found_map, blk);
  else
   ext2fs_unmark_block_bitmap2(ctx->block_found_map, blk);
 }
}

static void e2fsck_block_alloc_stats_range(ext2_filsys fs, blk64_t blk,
        blk_t num, int inuse)
{
 e2fsck_t ctx = (e2fsck_t) fs->priv_data;


 if (ctx->block_found_map &&
     ctx->block_metadata_map &&
     inuse < 0 &&
     ext2fs_test_block_bitmap_range2(ctx->block_metadata_map, blk, num))
  return;

 if (ctx->block_found_map) {
  if (inuse > 0)
   ext2fs_mark_block_bitmap_range2(ctx->block_found_map,
       blk, num);
  else
   ext2fs_unmark_block_bitmap_range2(ctx->block_found_map,
       blk, num);
 }
}

void e2fsck_use_inode_shortcuts(e2fsck_t ctx, int use_shortcuts)
{
 ext2_filsys fs = ctx->fs;

 if (use_shortcuts) {
  fs->get_blocks = pass1_get_blocks;
  fs->check_directory = pass1_check_directory;
  fs->read_inode = pass1_read_inode;
  fs->write_inode = pass1_write_inode;
  ctx->stashed_ino = 0;
 } else {
  fs->get_blocks = 0;
  fs->check_directory = 0;
  fs->read_inode = 0;
  fs->write_inode = 0;
 }
}

void e2fsck_intercept_block_allocations(e2fsck_t ctx)
{
 ext2fs_set_alloc_block_callback(ctx->fs, e2fsck_get_alloc_block, 0);
 ext2fs_set_block_alloc_stats_callback(ctx->fs,
      e2fsck_block_alloc_stats, 0);
 ext2fs_set_new_range_callback(ctx->fs, e2fsck_new_range, 
                                                         ((void *)0)
                                                             );
 ext2fs_set_block_alloc_stats_range_callback(ctx->fs,
     e2fsck_block_alloc_stats_range, 
                                    ((void *)0)
                                        );
}
