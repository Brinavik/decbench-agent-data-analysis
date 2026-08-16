























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
struct buffer_head {



 e2fsck_t b_ctx;

 io_channel b_io;
 int b_size;
 int b_err;
 unsigned int b_dirty:1;
 unsigned int b_uptodate:1;
 unsigned long long b_blocknr;
 char b_data[4096];
};

struct inode {



 e2fsck_t i_ctx;

 ext2_ino_t i_ino;
 struct ext2_inode i_ext2;
};

struct kdev_s {



 e2fsck_t k_ctx;

 int k_dev;
};
typedef struct kmem_cache {
 int object_length;
} kmem_cache_t;
extern void * __jbd_kmalloc (char *where, size_t size, int flags, int retry);
typedef struct journal_header_s
{
 __be32 h_magic;
 __be32 h_blocktype;
 __be32 h_sequence;
} journal_header_t;
struct commit_header {
 __be32 h_magic;
 __be32 h_blocktype;
 __be32 h_sequence;
 unsigned char h_chksum_type;
 unsigned char h_chksum_size;
 unsigned char h_padding[2];
 __be32 h_chksum[(32 / sizeof(__u32))];
 __be64 h_commit_sec;
 __be32 h_commit_nsec;
};




typedef struct journal_block_tag3_s
{
 __be32 t_blocknr;
 __be32 t_flags;
 __be32 t_blocknr_high;
 __be32 t_checksum;
} journal_block_tag3_t;

typedef struct journal_block_tag_s
{
 __be32 t_blocknr;
 __be16 t_checksum;
 __be16 t_flags;
 __be32 t_blocknr_high;
} journal_block_tag_t;


struct jbd2_journal_block_tail {
 __be32 t_checksum;
};





typedef struct journal_revoke_header_s
{
 journal_header_t r_header;
 __be32 r_count;
} jbd2_journal_revoke_header_t;
typedef struct journal_superblock_s
{

 journal_header_t s_header;



 __be32 s_blocksize;
 __be32 s_maxlen;
 __be32 s_first;



 __be32 s_sequence;
 __be32 s_start;



 __s32 s_errno;



 __be32 s_feature_compat;
 __be32 s_feature_incompat;
 __be32 s_feature_ro_compat;

 __u8 s_uuid[16];


 __be32 s_nr_users;

 __be32 s_dynsuper;


 __be32 s_max_transaction;
 __be32 s_max_trans_data;


 __u8 s_checksum_type;
 __u8 s_padding2[3];

 __be32 s_num_fc_blks;

 __be32 s_padding[41];
 __be32 s_checksum;


 __u8 s_users[(16 * 48)];


} journal_superblock_t;
extern inline int jbd2_has_feature_checksum(journal_t *j); extern inline int jbd2_has_feature_checksum(journal_t *j) { return ((j)->j_format_version >= 2 && ((j)->j_superblock->s_feature_compat & (( __be32)ext2fs_swab32((__u32)(0x00000001)))) != 0); } extern inline void jbd2_set_feature_checksum(journal_t *j); extern inline void jbd2_set_feature_checksum(journal_t *j) { (j)->j_superblock->s_feature_compat |= (( __be32)ext2fs_swab32((__u32)(0x00000001))); } extern inline void jbd2_clear_feature_checksum(journal_t *j); extern inline void jbd2_clear_feature_checksum(journal_t *j) { (j)->j_superblock->s_feature_compat &= ~(( __be32)ext2fs_swab32((__u32)(0x00000001))); }

extern inline int jbd2_has_feature_revoke(journal_t *j); extern inline int jbd2_has_feature_revoke(journal_t *j) { return ((j)->j_format_version >= 2 && ((j)->j_superblock->s_feature_incompat & (( __be32)ext2fs_swab32((__u32)(0x00000001)))) != 0); } extern inline void jbd2_set_feature_revoke(journal_t *j); extern inline void jbd2_set_feature_revoke(journal_t *j) { (j)->j_superblock->s_feature_incompat |= (( __be32)ext2fs_swab32((__u32)(0x00000001))); } extern inline void jbd2_clear_feature_revoke(journal_t *j); extern inline void jbd2_clear_feature_revoke(journal_t *j) { (j)->j_superblock->s_feature_incompat &= ~(( __be32)ext2fs_swab32((__u32)(0x00000001))); }
extern inline int jbd2_has_feature_64bit(journal_t *j); extern inline int jbd2_has_feature_64bit(journal_t *j) { return ((j)->j_format_version >= 2 && ((j)->j_superblock->s_feature_incompat & (( __be32)ext2fs_swab32((__u32)(0x00000002)))) != 0); } extern inline void jbd2_set_feature_64bit(journal_t *j); extern inline void jbd2_set_feature_64bit(journal_t *j) { (j)->j_superblock->s_feature_incompat |= (( __be32)ext2fs_swab32((__u32)(0x00000002))); } extern inline void jbd2_clear_feature_64bit(journal_t *j); extern inline void jbd2_clear_feature_64bit(journal_t *j) { (j)->j_superblock->s_feature_incompat &= ~(( __be32)ext2fs_swab32((__u32)(0x00000002))); }
extern inline int jbd2_has_feature_async_commit(journal_t *j); extern inline int jbd2_has_feature_async_commit(journal_t *j) { return ((j)->j_format_version >= 2 && ((j)->j_superblock->s_feature_incompat & (( __be32)ext2fs_swab32((__u32)(0x00000004)))) != 0); } extern inline void jbd2_set_feature_async_commit(journal_t *j); extern inline void jbd2_set_feature_async_commit(journal_t *j) { (j)->j_superblock->s_feature_incompat |= (( __be32)ext2fs_swab32((__u32)(0x00000004))); } extern inline void jbd2_clear_feature_async_commit(journal_t *j); extern inline void jbd2_clear_feature_async_commit(journal_t *j) { (j)->j_superblock->s_feature_incompat &= ~(( __be32)ext2fs_swab32((__u32)(0x00000004))); }
extern inline int jbd2_has_feature_csum2(journal_t *j); extern inline int jbd2_has_feature_csum2(journal_t *j) { return ((j)->j_format_version >= 2 && ((j)->j_superblock->s_feature_incompat & (( __be32)ext2fs_swab32((__u32)(0x00000008)))) != 0); } extern inline void jbd2_set_feature_csum2(journal_t *j); extern inline void jbd2_set_feature_csum2(journal_t *j) { (j)->j_superblock->s_feature_incompat |= (( __be32)ext2fs_swab32((__u32)(0x00000008))); } extern inline void jbd2_clear_feature_csum2(journal_t *j); extern inline void jbd2_clear_feature_csum2(journal_t *j) { (j)->j_superblock->s_feature_incompat &= ~(( __be32)ext2fs_swab32((__u32)(0x00000008))); }
extern inline int jbd2_has_feature_csum3(journal_t *j); extern inline int jbd2_has_feature_csum3(journal_t *j) { return ((j)->j_format_version >= 2 && ((j)->j_superblock->s_feature_incompat & (( __be32)ext2fs_swab32((__u32)(0x00000010)))) != 0); } extern inline void jbd2_set_feature_csum3(journal_t *j); extern inline void jbd2_set_feature_csum3(journal_t *j) { (j)->j_superblock->s_feature_incompat |= (( __be32)ext2fs_swab32((__u32)(0x00000010))); } extern inline void jbd2_clear_feature_csum3(journal_t *j); extern inline void jbd2_clear_feature_csum3(journal_t *j) { (j)->j_superblock->s_feature_incompat &= ~(( __be32)ext2fs_swab32((__u32)(0x00000010))); }
extern inline int jbd2_has_feature_fast_commit(journal_t *j); extern inline int jbd2_has_feature_fast_commit(journal_t *j) { return ((j)->j_format_version >= 2 && ((j)->j_superblock->s_feature_incompat & (( __be32)ext2fs_swab32((__u32)(0x00000020)))) != 0); } extern inline void jbd2_set_feature_fast_commit(journal_t *j); extern inline void jbd2_set_feature_fast_commit(journal_t *j) { (j)->j_superblock->s_feature_incompat |= (( __be32)ext2fs_swab32((__u32)(0x00000020))); } extern inline void jbd2_clear_feature_fast_commit(journal_t *j); extern inline void jbd2_clear_feature_fast_commit(journal_t *j) { (j)->j_superblock->s_feature_incompat &= ~(( __be32)ext2fs_swab32((__u32)(0x00000020))); }





extern inline size_t journal_tag_bytes(journal_t *journal)
{
 size_t sz;

 if (jbd2_has_feature_csum3(journal))
  return sizeof(journal_block_tag3_t);

 sz = sizeof(journal_block_tag_t);

 if (jbd2_has_feature_csum2(journal))
  sz += sizeof(__u16);

 if (jbd2_has_feature_64bit(journal))
  return sz;

 return sz - sizeof(__u32);
}

extern inline int jbd2_journal_has_csum_v2or3(journal_t *journal)
{
 if (jbd2_has_feature_csum2(journal) || jbd2_has_feature_csum3(journal))
  return 1;

 return 0;
}

extern inline int jbd2_journal_get_num_fc_blks(journal_superblock_t *jsb)
{
 int num_fc_blocks = ext2fs_swab32(( __u32)(__be32)(jsb->s_num_fc_blks));

 return num_fc_blocks ? num_fc_blocks : 256;
}




extern inline int tid_gt(tid_t x, tid_t y)
{
 int difference = (x - y);
 return (difference > 0);
}

extern inline int tid_geq(tid_t x, tid_t y)
{
 int difference = (x - y);
 return (difference >= 0);
}




extern int journal_blocks_per_page(struct inode *inode);
extern int jbd_blocks_per_page(struct inode *inode);
extern inline kmem_cache_t *do_cache_create(int len)
{
 kmem_cache_t *new_cache;

 new_cache = malloc(sizeof(*new_cache));
 if (new_cache)
  new_cache->object_length = len;
 return new_cache;
}

extern inline void do_cache_destroy(kmem_cache_t *cache)
{
 free(cache);
}





extern inline __u32 __hash_32(__u32 val)
{
 return val * 0x61C88647;
}

extern inline __u32 hash_32(__u32 val, unsigned int bits)
{

 return __hash_32(val) >> (32 - bits);
}

extern inline __u32 hash_64(__u64 val, unsigned int bits)
{
 if (sizeof(long) >= 8) {

  return val * 0x61C8864680B583EBull >> (64 - bits);
 } else {

  return hash_32((__u32)val ^ __hash_32(val >> 32), bits);
 }
}

extern inline void *kmalloc_array(unsigned n, unsigned size,
        int flags __attribute__((unused)))
{
 if (n && (~0U)/n < size)
  return 
        ((void *)0)
            ;
 return malloc(n * size);
}

extern inline __u32 jbd2_chksum(journal_t *j __attribute__((unused)),
      __u32 crc, const void *address,
      unsigned int length)
{
 return ext2fs_crc32c_le(crc, address, length);
}

extern inline void jbd2_descriptor_block_csum_set(journal_t *j,
          struct buffer_head *bh)
{
 struct jbd2_journal_block_tail *tail;
 __u32 csum;

 if (!jbd2_journal_has_csum_v2or3(j))
  return;

 tail = (struct jbd2_journal_block_tail *)(bh->b_data + j->j_blocksize -
   sizeof(struct jbd2_journal_block_tail));
 tail->t_checksum = 0;
 csum = jbd2_chksum(j, j->j_csum_seed, bh->b_data, j->j_blocksize);
 tail->t_checksum = (( __be32)ext2fs_swab32((__u32)(csum)));
}






int jbd2_journal_bmap(journal_t *journal, unsigned long block,
        unsigned long long *phys);
struct buffer_head *getblk(kdev_t ctx, unsigned long long blocknr,
      int blocksize);
int sync_blockdev(kdev_t kdev);
void ll_rw_block(int rw, int op_flags, int nr, struct buffer_head *bh[]);
void mark_buffer_dirty(struct buffer_head *bh);
void mark_buffer_uptodate(struct buffer_head *bh, int val);
void brelse(struct buffer_head *bh);
int buffer_uptodate(struct buffer_head *bh);
void wait_on_buffer(struct buffer_head *bh);
extern e2fsck_t e2fsck_global_ctx;
extern int jbd2_journal_recover (journal_t *journal);
extern int jbd2_journal_skip_recovery (journal_t *);


extern int jbd2_journal_init_revoke(journal_t *, int);
extern void jbd2_journal_destroy_revoke(journal_t *);
extern void jbd2_journal_destroy_revoke_record_cache(void);
extern void jbd2_journal_destroy_revoke_table_cache(void);
extern int jbd2_journal_init_revoke_record_cache(void);
extern int jbd2_journal_init_revoke_table_cache(void);


extern int jbd2_journal_set_revoke(journal_t *, unsigned long long, tid_t);
extern int jbd2_journal_test_revoke(journal_t *, unsigned long long, tid_t);
extern void jbd2_journal_clear_revoke(journal_t *);
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


static int bh_count = 0;
static int e2fsck_journal_verify_csum_type(journal_t *j,
        journal_superblock_t *jsb)
{
 if (!jbd2_journal_has_csum_v2or3(j))
  return 1;

 return jsb->s_checksum_type == 4;
}

static __u32 e2fsck_journal_sb_csum(journal_superblock_t *jsb)
{
 __u32 crc, old_crc;

 old_crc = jsb->s_checksum;
 jsb->s_checksum = 0;
 crc = ext2fs_crc32c_le(~0, (unsigned char *)jsb,
          sizeof(journal_superblock_t));
 jsb->s_checksum = old_crc;

 return crc;
}

static int e2fsck_journal_sb_csum_verify(journal_t *j,
      journal_superblock_t *jsb)
{
 __u32 provided, calculated;

 if (!jbd2_journal_has_csum_v2or3(j))
  return 1;

 provided = ext2fs_swab32(( __u32)(__be32)(jsb->s_checksum));
 calculated = e2fsck_journal_sb_csum(jsb);

 return provided == calculated;
}

static errcode_t e2fsck_journal_sb_csum_set(journal_t *j,
         journal_superblock_t *jsb)
{
 __u32 crc;

 if (!jbd2_journal_has_csum_v2or3(j))
  return 0;

 crc = e2fsck_journal_sb_csum(jsb);
 jsb->s_checksum = (( __be32)ext2fs_swab32((__u32)(crc)));
 return 0;
}





int jbd2_journal_bmap(journal_t *journal, unsigned long block,
        unsigned long long *phys)
{




 struct inode *inode = journal->j_inode;
 errcode_t retval;
 blk64_t pblk;

 if (!inode) {
  *phys = block;
  return 0;
 }

 retval= ext2fs_bmap2(inode->i_ctx->fs, inode->i_ino,
        &inode->i_ext2, 
                       ((void *)0)
                           , 0, (blk64_t) block,
        0, &pblk);
 *phys = pblk;
 return -1 * ((int) retval);

}

struct buffer_head *getblk(kdev_t kdev, unsigned long long blocknr,
      int blocksize)
{
 struct buffer_head *bh;
 int bufsize = sizeof(*bh) + kdev->k_ctx->fs->blocksize -
  sizeof(bh->b_data);

 bh = e2fsck_allocate_memory(kdev->k_ctx, bufsize, "block buffer");
 if (!bh)
  return 
        ((void *)0)
            ;

 if ((-1) >= 3)
  bh_count++;
 do { if ((4) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 132, __FUNCTION__); printf ("getblk for block %llu (%d bytes)(total %d)\n", blocknr, blocksize, bh_count); } } while (0)
                                 ;

 bh->b_ctx = kdev->k_ctx;
 if (kdev->k_dev == 1)
  bh->b_io = kdev->k_ctx->fs->io;
 else
  bh->b_io = kdev->k_ctx->journal_io;
 bh->b_size = blocksize;
 bh->b_blocknr = blocknr;

 return bh;
}

int sync_blockdev(kdev_t kdev)
{
 io_channel io;

 if (kdev->k_dev == 1)
  io = kdev->k_ctx->fs->io;
 else
  io = kdev->k_ctx->journal_io;

 return ((io)->manager->flush((io))) ? -
                               5 
                                   : 0;
}

void ll_rw_block(int rw, int op_flags __attribute__((unused)), int nr,
   struct buffer_head *bhp[])
{
 errcode_t retval;
 struct buffer_head *bh;

 for (; nr > 0; --nr) {
  bh = *bhp++;
  if (rw == 0 && !bh->b_uptodate) {
   do { if ((3) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 167, __FUNCTION__); printf ("reading block %llu/%p\n", bh->b_blocknr, (void *) bh); } } while (0)
                                 ;
   retval = io_channel_read_blk64(bh->b_io,
           bh->b_blocknr,
           1, bh->b_data);
   if (retval) {
    com_err(bh->b_ctx->device_name, retval,
     "while reading block %llu\n",
     bh->b_blocknr);
    bh->b_err = (int) retval;
    continue;
   }
   bh->b_uptodate = 1;
  } else if (rw == 1 && bh->b_dirty) {
   do { if ((3) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 181, __FUNCTION__); printf ("writing block %llu/%p\n", bh->b_blocknr, (void *) bh); } } while (0)

                  ;
   retval = io_channel_write_blk64(bh->b_io,
            bh->b_blocknr,
            1, bh->b_data);
   if (retval) {
    com_err(bh->b_ctx->device_name, retval,
     "while writing block %llu\n",
     bh->b_blocknr);
    bh->b_err = (int) retval;
    continue;
   }
   bh->b_dirty = 0;
   bh->b_uptodate = 1;
  } else {
   do { if ((3) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 197, __FUNCTION__); printf ("no-op %s for block %llu\n", rw == 0 ? "read" : "write", bh->b_blocknr); } } while (0)

                    ;
  }
 }
}

void mark_buffer_dirty(struct buffer_head *bh)
{
 bh->b_dirty = 1;
}

static void mark_buffer_clean(struct buffer_head * bh)
{
 bh->b_dirty = 0;
}

void brelse(struct buffer_head *bh)
{
 if (bh->b_dirty)
  ll_rw_block(1, 0, 1, &bh);
 do { if ((3) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 218, __FUNCTION__); printf ("freeing block %llu/%p (total %d)\n", bh->b_blocknr, (void *) bh, --bh_count); } } while (0)
                                           ;
 ext2fs_free_mem(&bh);
}

int buffer_uptodate(struct buffer_head *bh)
{
 return bh->b_uptodate;
}

void mark_buffer_uptodate(struct buffer_head *bh, int val)
{
 bh->b_uptodate = val;
}

void wait_on_buffer(struct buffer_head *bh)
{
 if (!bh->b_uptodate)
  ll_rw_block(0, 0, 1, &bh);
}


static void e2fsck_clear_recover(e2fsck_t ctx, int error)
{
 ext2fs_clear_feature_journal_needs_recovery(ctx->fs->super);


 if (error)
  ctx->fs->super->s_state &= ~0x0001;
 ext2fs_mark_super_dirty(ctx->fs);
}




struct process_block_struct {
 e2_blkcnt_t last_block;
};

static int process_journal_block(ext2_filsys fs,
     blk64_t *block_nr,
     e2_blkcnt_t blockcnt,
     blk64_t ref_block __attribute__((unused)),
     int ref_offset __attribute__((unused)),
     void *priv_data)
{
 struct process_block_struct *p;
 blk64_t blk = *block_nr;

 p = (struct process_block_struct *) priv_data;

 if (!blk || blk < fs->super->s_first_data_block ||
     blk >= ext2fs_blocks_count(fs->super))
  return 2;

 if (blockcnt >= 0)
  p->last_block = blockcnt;
 return 0;
}

static int ext4_fc_replay_scan(journal_t *j, struct buffer_head *bh,
    int off, tid_t expected_tid)
{
 e2fsck_t ctx = j->j_fs_dev->k_ctx;
 struct e2fsck_fc_replay_state *state;
 int ret = 1;
 struct ext4_fc_add_range ext;
 struct ext4_fc_tl tl;
 struct ext4_fc_tail tail;
 __u8 *start, *cur, *end, *val;
 struct ext4_fc_head head;
 struct ext2fs_extent ext2fs_ex = {0};

 state = &ctx->fc_replay_state;

 start = (__u8 *)bh->b_data;
 end = (__u8 *)bh->b_data + j->j_blocksize - 1;

 do { if ((1) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 296, __FUNCTION__); printf ("Scan phase starting, expected %d", expected_tid); } } while (0);
 if (state->fc_replay_expected_off == 0) {
  memset(state, 0, sizeof(*state));

  if ((( __u16)(__le16)(((struct ext4_fc_tl *)start)->fc_tag))
   != 0x0009) {
   do { if ((1) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 302, __FUNCTION__); printf ("Ending early!, not a head tag"); } } while (0);
   return 0;
  }
 }

 if (off != state->fc_replay_expected_off) {
  ret = -(2133571502L);
  goto out_err;
 }

 state->fc_replay_expected_off++;
 for (cur = start; cur < end; cur = cur + (( __u16)(__le16)(tl.fc_len)) + sizeof(tl)) {
  memcpy(&tl, cur, sizeof(tl));
  val = cur + sizeof(tl);

  do { if ((3) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 317, __FUNCTION__); printf ("Scan phase, tag:%s, blk %lld\n", tag2str((( __u16)(__le16)(tl.fc_tag))), bh->b_blocknr); } } while (0)
                                                    ;
  switch ((( __u16)(__le16)(tl.fc_tag))) {
  case 0x0001:
   memcpy(&ext, val, sizeof(ext));
   ret = ext2fs_decode_extent(&ext2fs_ex,
         (void *)&ext.fc_ex,
         sizeof(ext.fc_ex));
   if (ret)
    ret = 0;
   else
    ret = 1;

  case 0x0002:
  case 0x0004:
  case 0x0005:
  case 0x0003:
  case 0x0006:
  case 0x0007:
   state->fc_cur_tag++;
   state->fc_crc = jbd2_chksum(j, state->fc_crc, cur,
     sizeof(tl) + ext4_fc_tag_len(&tl));
   break;
  case 0x0008:
   state->fc_cur_tag++;
   memcpy(&tail, val, sizeof(tail));
   state->fc_crc = jbd2_chksum(j, state->fc_crc, cur,
      sizeof(tl) +
      
     __builtin_offsetof (
     struct ext4_fc_tail
     , 
     fc_crc
     )
             
            );
   do { if ((1) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 347, __FUNCTION__); printf ("tail tid %d, expected %d\n", (( __u32)(__le32)(tail.fc_tid)), expected_tid); } } while (0)
                                             ;
   if ((( __u32)(__le32)(tail.fc_tid)) == expected_tid &&
       (( __u32)(__le32)(tail.fc_crc)) == state->fc_crc) {
    state->fc_replay_num_tags = state->fc_cur_tag;
   } else {
    ret = state->fc_replay_num_tags ?
     0 : -(2133571503L);
   }
   state->fc_crc = 0;
   break;
  case 0x0009:
   memcpy(&head, val, sizeof(head));
   if ((( __u32)(__le32)(head.fc_features)) &
       ~0x0) {
    ret = -
          95
                    ;
    break;
   }
   if ((( __u32)(__le32)(head.fc_tid)) != expected_tid) {
    ret = -
          22
                ;
    break;
   }
   state->fc_cur_tag++;
   state->fc_crc = jbd2_chksum(j, state->fc_crc, cur,
     sizeof(tl) + ext4_fc_tag_len(&tl));
   break;
  default:
   ret = state->fc_replay_num_tags ?
    0 : -
                          125
                                   ;
  }
  if (ret < 0 || ret == 0)
   break;
 }

out_err:
 return ret;
}

static int __errcode_to_errno(errcode_t err, const char *func, int line)
{
 if (err == 0)
  return 0;
 fprintf(
        stderr
              , "Error \"%s\" encountered in function %s at line %d\n",
  error_message(err), func, line);
 if (err <= 256)
  return -err;
 return -
        14
              ;
}






static int make_room(struct extent_list *list, int i)
{
 int ret;

 if (list->count == list->size) {
  unsigned int new_size = (list->size + 341) *
     sizeof(struct ext2fs_extent);
  ret = __errcode_to_errno(ext2fs_resize_mem(0, new_size, &list->extents), __func__, 408);
  if (ret)
   return ret;
  list->size += 341;
 }

 memmove(&list->extents[i + 1], &list->extents[i],
   sizeof(list->extents[0]) * (list->count - i));
 list->count++;
 return 0;
}

static int ex_compar(const void *arg1, const void *arg2)
{
 const struct ext2fs_extent *ex1 = (const struct ext2fs_extent *)arg1;
 const struct ext2fs_extent *ex2 = (const struct ext2fs_extent *)arg2;

 if (ex1->e_lblk < ex2->e_lblk)
  return -1;
 if (ex1->e_lblk > ex2->e_lblk)
  return 1;
 return ex1->e_len - ex2->e_len;
}

static int ex_len_compar(const void *arg1, const void *arg2)
{
 const struct ext2fs_extent *ex1 = (const struct ext2fs_extent *)arg1;
 const struct ext2fs_extent *ex2 = (const struct ext2fs_extent *)arg2;

 if (ex1->e_len < ex2->e_len)
  return 1;

 if (ex1->e_lblk > ex2->e_lblk)
  return -1;

 return 0;
}

static void ex_sort_and_merge(struct extent_list *list)
{
 unsigned int i, j;

 if (list->count < 2)
  return;





 qsort(list->extents, list->count, sizeof(struct ext2fs_extent),
  ex_len_compar);

 for (i = 0; i < list->count; i++) {
  if (list->extents[i].e_len == 0) {
   list->count = i;
   break;
  }
 }

 if (list->count == 0)
  return;


 qsort(list->extents, list->count, sizeof(list->extents[0]),
  ex_compar);


 i = 0;
 while (i < list->count - 1) {
  if (((&list->extents[i])->e_lblk + (&list->extents[i])->e_len - 1) + 1 != list->extents[i + 1].e_lblk ||
   ((&list->extents[i])->e_pblk + (&list->extents[i])->e_len - 1) + 1 != list->extents[i + 1].e_pblk ||
   (list->extents[i].e_flags & 0x0002) !=
    (list->extents[i + 1].e_flags & 0x0002)) {
   i++;
   continue;
  }

  list->extents[i].e_len += list->extents[i + 1].e_len;
  for (j = i + 1; j < list->count - 1; j++)
   list->extents[j] = list->extents[j + 1];
  list->count--;
 }
}


static int ext4_modify_extent_list(e2fsck_t ctx, struct extent_list *list,
     struct ext2fs_extent *ex, int del)
{
 int ret, offset;
 unsigned int i;
 struct ext2fs_extent add_ex = *ex;


 for (i = 0; i < list->count; i++) {
  if (((&list->extents[i])->e_lblk + (&list->extents[i])->e_len - 1) < add_ex.e_lblk)
   continue;


  if (list->extents[i].e_lblk > ((&add_ex)->e_lblk + (&add_ex)->e_len - 1))
   break;




  ext2fs_unmark_block_bitmap_range2(ctx->fs->block_map,
   list->extents[i].e_pblk, list->extents[i].e_len);

  if (list->extents[i].e_lblk < add_ex.e_lblk &&
   ((&list->extents[i])->e_lblk + (&list->extents[i])->e_len - 1) > ((&add_ex)->e_lblk + (&add_ex)->e_len - 1)) {
   ret = make_room(list, i + 1);
   if (ret)
    return ret;
   list->extents[i + 1] = list->extents[i];
   offset = ((&add_ex)->e_lblk + (&add_ex)->e_len - 1) + 1 - list->extents[i].e_lblk;
   list->extents[i + 1].e_lblk += offset;
   list->extents[i + 1].e_pblk += offset;
   list->extents[i + 1].e_len -= offset;
   list->extents[i].e_len =
    add_ex.e_lblk - list->extents[i].e_lblk;
   break;
  }


  if (add_ex.e_lblk <= list->extents[i].e_lblk &&
   ((&list->extents[i])->e_lblk + (&list->extents[i])->e_len - 1) <= ((&add_ex)->e_lblk + (&add_ex)->e_len - 1)) {

   list->extents[i].e_len = 0;
   continue;
  }


  if (((&list->extents[i])->e_lblk + (&list->extents[i])->e_len - 1) > ((&add_ex)->e_lblk + (&add_ex)->e_len - 1)) {
   offset = ((&add_ex)->e_lblk + (&add_ex)->e_len - 1) + 1 - list->extents[i].e_lblk;
   list->extents[i].e_lblk += offset;
   list->extents[i].e_pblk += offset;
   list->extents[i].e_len -= offset;
   break;
  }

  if (((&add_ex)->e_lblk + (&add_ex)->e_len - 1) >= ((&list->extents[i])->e_lblk + (&list->extents[i])->e_len - 1))
   list->extents[i].e_len =
    add_ex.e_lblk > list->extents[i].e_lblk ?
    add_ex.e_lblk - list->extents[i].e_lblk : 0;
 }

 if (add_ex.e_len && !del) {
  make_room(list, list->count);
  list->extents[list->count - 1] = add_ex;
 }

 ex_sort_and_merge(list);


 for (i = 0; i < list->count; i++)
  ext2fs_mark_block_bitmap_range2(ctx->fs->block_map,
   list->extents[i].e_pblk, list->extents[i].e_len);
 ext2fs_mark_bb_dirty(ctx->fs);

 return 0;
}

static int ext4_add_extent_to_list(e2fsck_t ctx, struct extent_list *list,
     struct ext2fs_extent *ex)
{
 return ext4_modify_extent_list(ctx, list, ex, 0 );
}

static int ext4_del_extent_from_list(e2fsck_t ctx, struct extent_list *list,
     struct ext2fs_extent *ex)
{
 return ext4_modify_extent_list(ctx, list, ex, 1 );
}

static int ext4_fc_read_extents(e2fsck_t ctx, ino_t ino)
{
 struct extent_list *extent_list = &ctx->fc_replay_state.fc_extent_list;

 if (extent_list->ino == ino)
  return 0;

 extent_list->ino = ino;
 return __errcode_to_errno(e2fsck_read_extents(ctx, extent_list), __func__, 589);
}
static void ext4_fc_flush_extents(e2fsck_t ctx, ino_t ino)
{
 struct extent_list *extent_list = &ctx->fc_replay_state.fc_extent_list;

 if (extent_list->ino == ino || extent_list->ino == 0)
  return;
 e2fsck_rewrite_extent_tree(ctx, extent_list);
 ext2fs_free_mem(&extent_list->extents);
 memset(extent_list, 0, sizeof(*extent_list));
}


struct dentry_info_args {
 ino_t parent_ino;
 int dname_len;
 ino_t ino;
 char *dname;
};

static inline int tl_to_darg(struct dentry_info_args *darg,
        struct ext4_fc_tl *tl, __u8 *val)
{
 struct ext4_fc_dentry_info fcd;
 int tag = (( __u16)(__le16)(tl->fc_tag));

 memcpy(&fcd, val, sizeof(fcd));

 darg->parent_ino = (( __u32)(__le32)(fcd.fc_parent_ino));
 darg->ino = (( __u32)(__le32)(fcd.fc_ino));
 darg->dname_len = ext4_fc_tag_len(tl) -
   sizeof(struct ext4_fc_dentry_info);
 darg->dname = malloc(darg->dname_len + 1);
 if (!darg->dname)
  return -
         12
               ;
 memcpy(darg->dname,
        val + sizeof(struct ext4_fc_dentry_info),
        darg->dname_len);
 darg->dname[darg->dname_len] = 0;
 do { if ((1) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 638, __FUNCTION__); printf ("%s: %s, ino %lu, parent %lu\n", tag == 0x0003 ? "create" : (tag == 0x0004 ? "link" : (tag == 0x0005 ? "unlink" : "error")), darg->dname, darg->ino, darg->parent_ino); } } while (0)



                                           ;
 return 0;
}

static int ext4_fc_handle_unlink(e2fsck_t ctx, struct ext4_fc_tl *tl, __u8 *val)
{
 struct dentry_info_args darg;
 int ret;

 ret = tl_to_darg(&darg, tl, val);
 if (ret)
  return ret;
 ext4_fc_flush_extents(ctx, darg.ino);
 ret = __errcode_to_errno(ext2fs_unlink(ctx->fs, darg.parent_ino, darg.dname, darg.ino, 0), __func__, 655)

                                  ;

 free(darg.dname);
 return ret;
}

static int ext4_fc_handle_link_and_create(e2fsck_t ctx, struct ext4_fc_tl *tl, __u8 *val)
{
 struct dentry_info_args darg;
 ext2_filsys fs = ctx->fs;
 struct ext2_inode_large inode_large;
 int ret, filetype, mode;

 ret = tl_to_darg(&darg, tl, val);
 if (ret)
  return ret;
 ext4_fc_flush_extents(ctx, 0);
 ret = __errcode_to_errno(ext2fs_read_inode(fs, darg.ino, (struct ext2_inode *)&inode_large), __func__, 674)
                                          ;
 if (ret)
  goto out;

 mode = inode_large.i_mode;

 if ((((mode) & 00170000) == 0100000))
  filetype = 1;
 else if ((((mode) & 00170000) == 0040000))
  filetype = 2;
 else if ((((mode) & 00170000) == 0020000))
  filetype = 3;
 else if ((((mode) & 00170000) == 0060000))
  filetype = 4;
 else if ((((mode) & 00170000) == 0120000))
  return 7;
 else if ((((mode) & 00170000) == 0010000))
  filetype = 5;
 else if ((((mode) & 00170000) == 0140000))
  filetype = 6;
 else {
  ret = -
        22
              ;
  goto out;
 }





 ext2fs_unlink(fs, darg.parent_ino, darg.dname, darg.ino,
   0x1);

 ret = __errcode_to_errno(ext2fs_link(fs, darg.parent_ino, darg.dname, darg.ino, filetype), __func__, 707)

                 ;
out:
 free(darg.dname);
 return ret;

}


static void ext4_fc_replay_fixup_iblocks(struct ext2_inode_large *ondisk_inode,
 struct ext2_inode_large *fc_inode)
{
 if (ondisk_inode->i_flags & 0x00080000) {
  struct ext3_extent_header *eh;

  eh = (struct ext3_extent_header *)(&ondisk_inode->i_block[0]);
  if ((( __u16)(__le16)(eh->eh_magic)) != 0xf30a) {
   memset(eh, 0, sizeof(*eh));
   eh->eh_magic = (( __le16)(__u16)(0xf30a));
   eh->eh_max = (( __le16)(__u16)((sizeof(ondisk_inode->i_block) - sizeof(struct ext3_extent_header)) / sizeof(struct ext3_extent)))


                               ;
  }
 } else if (ondisk_inode->i_flags & 0x10000000) {
  memcpy(ondisk_inode->i_block, fc_inode->i_block,
   sizeof(fc_inode->i_block));
 }
}

static int ext4_fc_handle_inode(e2fsck_t ctx, __u8 *val)
{
 int ino, inode_len = 128;
 struct ext2_inode_large *inode = 
                                 ((void *)0)
                                     , *fc_inode = 
                                                   ((void *)0)
                                                       ;
 __le32 fc_ino;
 __u8 *fc_raw_inode;
 errcode_t err;
 blk64_t blks;

 memcpy(&fc_ino, val, sizeof(fc_ino));
 fc_raw_inode = val + sizeof(fc_ino);
 ino = (( __u32)(__le32)(fc_ino));

 if ((((ctx->fs->super)->s_rev_level == 0) ? 128 : (ctx->fs->super)->s_inode_size) > 128)
  inode_len += (( __u16)(__le16)(((struct ext2_inode_large *)fc_raw_inode)->i_extra_isize))
                                                            ;
 err = ext2fs_get_mem(inode_len, &inode);
 if (err)
  goto out;
 err = ext2fs_get_mem(inode_len, &fc_inode);
 if (err)
  goto out;
 ext4_fc_flush_extents(ctx, ino);

 err = ext2fs_read_inode_full(ctx->fs, ino, (struct ext2_inode *)inode,
     inode_len);
 if (err)
  goto out;
 memcpy(fc_inode, fc_raw_inode, inode_len);



 memcpy(inode, fc_inode, 
                        __builtin_offsetof (
                        struct ext2_inode_large
                        , 
                        i_block
                        )
                                                                  );
 memcpy(&inode->i_generation, &fc_inode->i_generation,
  inode_len - 
             __builtin_offsetof (
             struct ext2_inode_large
             , 
             i_generation
             )
                                                            );
 ext4_fc_replay_fixup_iblocks(inode, fc_inode);
 err = ext2fs_count_blocks(ctx->fs, ino, EXT2_INODE(inode), &blks);
 if (err)
  goto out;
 ext2fs_iblk_set(ctx->fs, EXT2_INODE(inode), blks);
 ext2fs_inode_csum_set(ctx->fs, ino, inode);

 err = ext2fs_write_inode_full(ctx->fs, ino, (struct ext2_inode *)inode,
     inode_len);
 if (err)
  goto out;
 if (inode->i_links_count)
  ext2fs_mark_inode_bitmap2(ctx->fs->inode_map, ino);
 else
  ext2fs_unmark_inode_bitmap2(ctx->fs->inode_map, ino);
 ext2fs_mark_ib_dirty(ctx->fs);

out:
 ext2fs_free_mem(&inode);
 ext2fs_free_mem(&fc_inode);
 return __errcode_to_errno(err, __func__, 793);
}




static int ext4_fc_handle_add_extent(e2fsck_t ctx, __u8 *val)
{
 struct ext2fs_extent extent;
 struct ext4_fc_add_range add_range;
 ino_t ino;
 int ret = 0;

 memcpy(&add_range, val, sizeof(add_range));
 ino = (( __u32)(__le32)(add_range.fc_ino));
 ext4_fc_flush_extents(ctx, ino);

 ret = ext4_fc_read_extents(ctx, ino);
 if (ret)
  return ret;
 memset(&extent, 0, sizeof(extent));
 ret = __errcode_to_errno(ext2fs_decode_extent( &extent, (void *)add_range.fc_ex, sizeof(add_range.fc_ex)), __func__, 814)

                            ;
 if (ret)
  return ret;
 return ext4_add_extent_to_list(ctx,
  &ctx->fc_replay_state.fc_extent_list, &extent);
}




static int ext4_fc_handle_del_range(e2fsck_t ctx, __u8 *val)
{
 struct ext2fs_extent extent;
 struct ext4_fc_del_range del_range;
 int ret, ino;

 memcpy(&del_range, val, sizeof(del_range));
 ino = (( __u32)(__le32)(del_range.fc_ino));
 ext4_fc_flush_extents(ctx, ino);

 memset(&extent, 0, sizeof(extent));
 extent.e_lblk = (( __u32)(__le32)(del_range.fc_lblk));
 extent.e_len = (( __u32)(__le32)(del_range.fc_len));
 ret = ext4_fc_read_extents(ctx, ino);
 if (ret)
  return ret;
 return ext4_del_extent_from_list(ctx,
  &ctx->fc_replay_state.fc_extent_list, &extent);
}






static int ext4_fc_replay(journal_t *journal, struct buffer_head *bh,
    enum passtype pass, int off, tid_t expected_tid)
{
 e2fsck_t ctx = journal->j_fs_dev->k_ctx;
 struct e2fsck_fc_replay_state *state = &ctx->fc_replay_state;
 int ret = 1;
 struct ext4_fc_tl tl;
 __u8 *start, *end, *cur, *val;

 if (pass == PASS_SCAN) {
  state->fc_current_pass = PASS_SCAN;
  return ext4_fc_replay_scan(journal, bh, off, expected_tid);
 }

 if (state->fc_replay_num_tags == 0)
  goto replay_done;

 if (state->fc_current_pass != pass) {

  state->fc_current_pass = pass;

  ctx->fs->flags |= 0x200000;
  ret = __errcode_to_errno(ext2fs_read_bitmaps(ctx->fs), __func__, 873);
  if (ret) {
   do { if ((1) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 875, __FUNCTION__); printf ("Error %d while reading bitmaps\n", ret); } } while (0);
   return ret;
  }
  state->fc_super_state = ctx->fs->super->s_state;






  ctx->fs->super->s_state |= 0x0002;
  ctx->fs->super->s_state |= 0x0020;
  ext2fs_mark_super_dirty(ctx->fs);
  ext2fs_flush(ctx->fs);
 }

 start = (__u8 *)bh->b_data;
 end = (__u8 *)bh->b_data + journal->j_blocksize - 1;

 for (cur = start; cur < end; cur = cur + (( __u16)(__le16)(tl.fc_len)) + sizeof(tl)) {
  memcpy(&tl, cur, sizeof(tl));
  val = cur + sizeof(tl);

  if (state->fc_replay_num_tags == 0)
   goto replay_done;
  do { if ((3) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 900, __FUNCTION__); printf ("Replay phase processing %s tag\n", tag2str((( __u16)(__le16)(tl.fc_tag)))); } } while (0)
                                    ;
  state->fc_replay_num_tags--;
  switch ((( __u16)(__le16)(tl.fc_tag))) {
  case 0x0003:
  case 0x0004:
   ret = ext4_fc_handle_link_and_create(ctx, &tl, val);
   break;
  case 0x0005:
   ret = ext4_fc_handle_unlink(ctx, &tl, val);
   break;
  case 0x0001:
   ret = ext4_fc_handle_add_extent(ctx, val);
   break;
  case 0x0002:
   ret = ext4_fc_handle_del_range(ctx, val);
   break;
  case 0x0006:
   ret = ext4_fc_handle_inode(ctx, val);
   break;
  case 0x0008:
   ext4_fc_flush_extents(ctx, 0);
  case 0x0007:
  case 0x0009:
   break;
  default:
   ret = -
         125
                  ;
   break;
  }
  if (ret < 0)
   break;
  ret = 1;
 }
 return ret;
replay_done:
 do { if ((1) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 935, __FUNCTION__); printf ("End of fast commit replay\n"); } } while (0);
 if (state->fc_current_pass != pass)
  return 0;

 ext2fs_calculate_summary_stats(ctx->fs, 0 );
 ext2fs_write_block_bitmap(ctx->fs);
 ext2fs_write_inode_bitmap(ctx->fs);
 ext2fs_mark_super_dirty(ctx->fs);
 ext2fs_set_gdt_csum(ctx->fs);
 ctx->fs->super->s_state = state->fc_super_state;
 ext2fs_flush(ctx->fs);

 return 0;
}

static errcode_t e2fsck_get_journal(e2fsck_t ctx, journal_t **ret_journal)
{
 struct process_block_struct pb;
 struct ext2_super_block *sb = ctx->fs->super;
 struct ext2_super_block jsuper;
 struct problem_context pctx;
 struct buffer_head *bh;
 struct inode *j_inode = 
                         ((void *)0)
                             ;
 struct kdev_s *dev_fs = 
                         ((void *)0)
                             , *dev_journal;
 const char *journal_name = 0;
 journal_t *journal = 
                      ((void *)0)
                          ;
 errcode_t retval = 0;
 io_manager io_ptr = 0;
 unsigned long long start = 0;
 int ret;
 int ext_journal = 0;
 int tried_backup_jnl = 0;

 clear_problem_context(&pctx);

 journal = e2fsck_allocate_memory(ctx, sizeof(journal_t), "journal");
 if (!journal) {
  return (2133571398L);
 }

 dev_fs = e2fsck_allocate_memory(ctx, 2*sizeof(struct kdev_s), "kdev");
 if (!dev_fs) {
  retval = (2133571398L);
  goto errout;
 }
 dev_journal = dev_fs+1;

 dev_fs->k_ctx = dev_journal->k_ctx = ctx;
 dev_fs->k_dev = 1;
 dev_journal->k_dev = 2;

 journal->j_dev = dev_journal;
 journal->j_fs_dev = dev_fs;
 journal->j_inode = 
                   ((void *)0)
                       ;
 journal->j_blocksize = ctx->fs->blocksize;

 if (uuid_is_null(sb->s_journal_uuid)) {
  if (!sb->s_journal_inum) {
   retval = (2133571369L);
   goto errout;
  }
  j_inode = e2fsck_allocate_memory(ctx, sizeof(*j_inode),
       "journal inode");
  if (!j_inode) {
   retval = (2133571398L);
   goto errout;
  }

  j_inode->i_ctx = ctx;
  j_inode->i_ino = sb->s_journal_inum;

  if ((retval = ext2fs_read_inode(ctx->fs,
      sb->s_journal_inum,
      &j_inode->i_ext2))) {
  try_backup_journal:
   if (sb->s_jnl_backup_type != 1 ||
       tried_backup_jnl)
    goto errout;
   memset(&j_inode->i_ext2, 0, sizeof(struct ext2_inode));
   memcpy(&j_inode->i_ext2.i_block[0], sb->s_jnl_blocks,
          (((12 + 1) + 1) + 1)*4);
   j_inode->i_ext2.i_size_high = sb->s_jnl_blocks[15];
   j_inode->i_ext2.i_size = sb->s_jnl_blocks[16];
   j_inode->i_ext2.i_links_count = 1;
   j_inode->i_ext2.i_mode = 0100000 | 0600;
   e2fsck_use_inode_shortcuts(ctx, 1);
   ctx->stashed_ino = j_inode->i_ino;
   ctx->stashed_inode = &j_inode->i_ext2;
   tried_backup_jnl++;
  }
  if (!j_inode->i_ext2.i_links_count ||
      !(((j_inode->i_ext2.i_mode) & 00170000) == 0100000)) {
   retval = (2133571416L);
   goto try_backup_journal;
  }
  if (((&j_inode->i_ext2)->i_size | ((__u64) (&j_inode->i_ext2)->i_size_high << 32)) / journal->j_blocksize <
      1024) {
   retval = (2133571413L);
   goto try_backup_journal;
  }
  pb.last_block = -1;
  retval = ext2fs_block_iterate3(ctx->fs, j_inode->i_ino,
            1, 0,
            process_journal_block, &pb);
  if ((pb.last_block + 1) * ctx->fs->blocksize <
      (int) ((&j_inode->i_ext2)->i_size | ((__u64) (&j_inode->i_ext2)->i_size_high << 32))) {
   retval = (2133571413L);
   goto try_backup_journal;
  }
  if (tried_backup_jnl && !(ctx->options & 0x0001)) {
   retval = ext2fs_write_inode(ctx->fs, sb->s_journal_inum,
          &j_inode->i_ext2);
   if (retval)
    goto errout;
  }

  journal->j_total_len = ((&j_inode->i_ext2)->i_size | ((__u64) (&j_inode->i_ext2)->i_size_high << 32)) /
   journal->j_blocksize;
  journal->j_inode = j_inode;
  ctx->journal_io = ctx->fs->io;
  if ((ret = jbd2_journal_bmap(journal, 0, &start)) != 0) {
   retval = (errcode_t) (-1 * ret);
   goto errout;
  }

 } else {
  ext_journal = 1;
  if (!ctx->journal_name) {
   char uuid[37];

   uuid_unparse(sb->s_journal_uuid, uuid);
   ctx->journal_name = blkid_get_devname(ctx->blkid,
             "UUID", uuid);
   if (!ctx->journal_name)
    ctx->journal_name = blkid_devno_to_devname(sb->s_journal_dev);
  }
  journal_name = ctx->journal_name;

  if (!journal_name) {
   fix_problem(ctx, 0x000011, &pctx);
   retval = (2133571415L);
   goto errout;
  }

  do { if ((1) <= (-1)) { printf ("" "(%s, %d): %s: ", "journal.c", 1089, __FUNCTION__); printf ("Using journal file %s\n", journal_name); } } while (0);
  io_ptr = unix_io_manager;
 }






 if (ext_journal)

 {
  int flags = 0x0001;
  if (!(ctx->mount_flags & 2 &&
        ctx->mount_flags & 4))
   flags |= 0x0002;
  if ((ctx->mount_flags & 4) &&
      (ctx->options & 0x0100))
   flags &= ~0x0002;


  retval = io_ptr->open(journal_name, flags,
          &ctx->journal_io);
 }
 if (retval)
  goto errout;

 ((ctx->journal_io)->manager->set_blksize((ctx->journal_io),ctx->fs->blocksize));

 if (ext_journal) {
  blk64_t maxlen;

  start = ext2fs_journal_sb_start(ctx->fs->blocksize) - 1;
  bh = getblk(dev_journal, start, ctx->fs->blocksize);
  if (!bh) {
   retval = (2133571398L);
   goto errout;
  }
  ll_rw_block(0, 0, 1, &bh);
  if ((retval = bh->b_err) != 0) {
   brelse(bh);
   goto errout;
  }
  memcpy(&jsuper, start ? bh->b_data : bh->b_data + 1024,
         sizeof(jsuper));




  if (jsuper.s_magic != 0xEF53 ||
      !ext2fs_has_feature_journal_dev(&jsuper)) {
   fix_problem(ctx, 0x000012, &pctx);
   retval = (2133571415L);
   brelse(bh);
   goto errout;
  }

  if (memcmp(jsuper.s_uuid, ctx->fs->super->s_journal_uuid,
      sizeof(jsuper.s_uuid))) {
   fix_problem(ctx, 0x000013, &pctx);
   retval = (2133571415L);
   brelse(bh);
   goto errout;
  }


  if (ext2fs_has_feature_metadata_csum(&jsuper)) {
   struct struct_ext2_filsys fsx;
   struct ext2_super_block superx;
   void *p;

   p = start ? bh->b_data : bh->b_data + 1024;
   memcpy(&fsx, ctx->fs, sizeof(fsx));
   memcpy(&superx, ctx->fs->super, sizeof(superx));
   fsx.super = &superx;
   ext2fs_set_feature_metadata_csum(fsx.super);
   if (!ext2fs_superblock_csum_verify(&fsx, p) &&
       fix_problem(ctx, 0x00004A,
     &pctx)) {
    ext2fs_superblock_csum_set(&fsx, p);
    mark_buffer_dirty(bh);
   }
  }
  brelse(bh);

  maxlen = ext2fs_blocks_count(&jsuper);
  journal->j_total_len = (maxlen < 1ULL << 32) ? maxlen : (1ULL << 32) - 1;
  start++;
 }

 if (!(bh = getblk(dev_journal, start, journal->j_blocksize))) {
  retval = (2133571398L);
  goto errout;
 }

 journal->j_sb_buffer = bh;
 journal->j_superblock = (journal_superblock_t *)bh->b_data;
 if (ext2fs_has_feature_fast_commit(ctx->fs->super))
  journal->j_fc_replay_callback = ext4_fc_replay;
 else
  journal->j_fc_replay_callback = 
                                 ((void *)0)
                                     ;






 *ret_journal = journal;
 e2fsck_use_inode_shortcuts(ctx, 0);
 return 0;

errout:
 e2fsck_use_inode_shortcuts(ctx, 0);
 if (dev_fs)
  ext2fs_free_mem(&dev_fs);
 if (j_inode)
  ext2fs_free_mem(&j_inode);
 if (journal)
  ext2fs_free_mem(&journal);
 return retval;
}

static errcode_t e2fsck_journal_fix_bad_inode(e2fsck_t ctx,
           struct problem_context *pctx)
{
 struct ext2_super_block *sb = ctx->fs->super;
 int recover = ext2fs_has_feature_journal_needs_recovery(ctx->fs->super);
 int has_journal = ext2fs_has_feature_journal(ctx->fs->super);

 if (has_journal || sb->s_journal_inum) {

  pctx->ino = sb->s_journal_inum;
  if (fix_problem(ctx, 0x00000F, pctx)) {
   if (has_journal && sb->s_journal_inum)
    printf("*** journal has been deleted ***\n\n");
   ext2fs_clear_feature_journal(sb);
   sb->s_journal_inum = 0;
   memset(sb->s_jnl_blocks, 0, sizeof(sb->s_jnl_blocks));
   ctx->flags |= 0x0080;
   ctx->fs->flags &= ~0x200;
   e2fsck_clear_recover(ctx, 1);
   return 0;
  }
  return (2133571504L);
 } else if (recover) {
  if (fix_problem(ctx, 0x000017, pctx)) {
   e2fsck_clear_recover(ctx, 1);
   return 0;
  }
  return (2133571395L);
 }
 return 0;
}


static void clear_v2_journal_fields(journal_t *journal)
{
 e2fsck_t ctx = journal->j_dev->k_ctx;
 struct problem_context pctx;

 clear_problem_context(&pctx);

 if (!fix_problem(ctx, 0x00002A, &pctx))
  return;

 ctx->flags |= 0x4000;
 memset(((char *) journal->j_superblock) + 0x0024, 0,
        ctx->fs->blocksize-0x0024);
 mark_buffer_dirty(journal->j_sb_buffer);
}


static errcode_t e2fsck_journal_load(journal_t *journal)
{
 e2fsck_t ctx = journal->j_dev->k_ctx;
 journal_superblock_t *jsb;
 struct buffer_head *jbh = journal->j_sb_buffer;
 struct problem_context pctx;

 clear_problem_context(&pctx);

 ll_rw_block(0, 0, 1, &jbh);
 if (jbh->b_err) {
  com_err(ctx->device_name, jbh->b_err, "%s",
   (gettext ("reading journal superblock\n")));
  return jbh->b_err;
 }

 jsb = journal->j_superblock;

 if (jsb->s_header.h_magic != htonl(0xc03b3998U))
  return e2fsck_journal_fix_bad_inode(ctx, &pctx);

 switch (ntohl(jsb->s_header.h_blocktype)) {
 case 3:
  journal->j_format_version = 1;
  if (jsb->s_feature_compat ||
      jsb->s_feature_incompat ||
      jsb->s_feature_ro_compat ||
      jsb->s_nr_users)
   clear_v2_journal_fields(journal);
  break;

 case 4:
  journal->j_format_version = 2;
  if (ntohl(jsb->s_nr_users) > 1 &&
      uuid_is_null(ctx->fs->super->s_journal_uuid))
   clear_v2_journal_fields(journal);
  if (ntohl(jsb->s_nr_users) > 1) {
   fix_problem(ctx, 0x000010, &pctx);
   return (2133571414L);
  }
  break;





 case 1:
 case 2:
 case 5:
  return (2133571504L);




 default:
  return (2133571414L);
 }

 if (((journal)->j_format_version >= 2 && ((journal)->j_superblock->s_feature_incompat & (( __be32)ext2fs_swab32((__u32)((~(0x00000001| 0x00000004| 0x00000002| 0x00000008| 0x00000010 | 0x00000020))))))))
  return (2133571395L);

 if (((journal)->j_format_version >= 2 && ((journal)->j_superblock->s_feature_ro_compat & (( __be32)ext2fs_swab32((__u32)((~0)))))))
  return (2133571396L);


 if (jbd2_has_feature_csum2(journal) && jbd2_has_feature_csum3(journal))
  return (2133571504L);

 if (jbd2_journal_has_csum_v2or3(journal) &&
     jbd2_has_feature_checksum(journal))
  return (2133571504L);

 if (!e2fsck_journal_verify_csum_type(journal, jsb) ||
     !e2fsck_journal_sb_csum_verify(journal, jsb))
  return (2133571504L);

 if (jbd2_journal_has_csum_v2or3(journal))
  journal->j_csum_seed = jbd2_chksum(journal, ~0, jsb->s_uuid,
         sizeof(jsb->s_uuid));




 if (jsb->s_blocksize != htonl(journal->j_blocksize)) {
  com_err(ctx->program_name, (2133571504L),
   (gettext ("%s: no valid journal superblock found\n")),
   ctx->device_name);
  return (2133571504L);
 }

 if (ntohl(jsb->s_maxlen) < journal->j_total_len)
  journal->j_total_len = ntohl(jsb->s_maxlen);
 else if (ntohl(jsb->s_maxlen) > journal->j_total_len) {
  com_err(ctx->program_name, (2133571504L),
   (gettext ("%s: journal too short\n")),
   ctx->device_name);
  return (2133571504L);
 }

 journal->j_tail_sequence = ntohl(jsb->s_sequence);
 journal->j_transaction_sequence = journal->j_tail_sequence;
 journal->j_tail = ntohl(jsb->s_start);
 journal->j_first = ntohl(jsb->s_first);
 if (jbd2_has_feature_fast_commit(journal)) {
  if (ntohl(jsb->s_maxlen) - jbd2_journal_get_num_fc_blks(jsb)
   < 1024) {
   com_err(ctx->program_name, (2133571504L),
    (gettext ("%s: incorrect fast commit blocks\n")),
    ctx->device_name);
   return (2133571504L);
  }
  journal->j_fc_last = ntohl(jsb->s_maxlen);
  journal->j_last = journal->j_fc_last -
     jbd2_journal_get_num_fc_blks(jsb);
  journal->j_fc_first = journal->j_last + 1;
 } else {
  journal->j_last = ntohl(jsb->s_maxlen);
 }

 return 0;
}

static void e2fsck_journal_reset_super(e2fsck_t ctx, journal_superblock_t *jsb,
           journal_t *journal)
{
 char *p;
 union {
  uuid_t uuid;
  __u32 val[4];
 } u;
 __u32 new_seq = 0;
 int i;





 if (jsb->s_header.h_magic != htonl(0xc03b3998U) ||
     jsb->s_header.h_blocktype != htonl(3)) {
  jsb->s_header.h_magic = htonl(0xc03b3998U);
  jsb->s_header.h_blocktype = htonl(4);
 }



 p = ((char *) jsb) + sizeof(journal_header_t);
 memset (p, 0, ctx->fs->blocksize-sizeof(journal_header_t));

 jsb->s_blocksize = htonl(ctx->fs->blocksize);
 jsb->s_maxlen = htonl(journal->j_total_len);
 jsb->s_first = htonl(1);






 uuid_generate(u.uuid);
 for (i = 0; i < 4; i ++)
  new_seq ^= u.val[i];
 jsb->s_sequence = htonl(new_seq);
 e2fsck_journal_sb_csum_set(journal, jsb);

 mark_buffer_dirty(journal->j_sb_buffer);
 ll_rw_block(1, 0, 1, &journal->j_sb_buffer);
}

static errcode_t e2fsck_journal_fix_corrupt_super(e2fsck_t ctx,
        journal_t *journal,
        struct problem_context *pctx)
{
 struct ext2_super_block *sb = ctx->fs->super;
 int recover = ext2fs_has_feature_journal_needs_recovery(ctx->fs->super);

 if (ext2fs_has_feature_journal(sb)) {
  if (fix_problem(ctx, 0x000015, pctx)) {
   e2fsck_journal_reset_super(ctx, journal->j_superblock,
         journal);
   journal->j_transaction_sequence = 1;
   e2fsck_clear_recover(ctx, recover);
   return 0;
  }
  return (2133571504L);
 } else if (e2fsck_journal_fix_bad_inode(ctx, pctx))
  return (2133571504L);

 return 0;
}

static void e2fsck_journal_release(e2fsck_t ctx, journal_t *journal,
       int reset, int drop)
{
 journal_superblock_t *jsb;

 if (drop)
  mark_buffer_clean(journal->j_sb_buffer);
 else if (!(ctx->options & 0x0001)) {
  jsb = journal->j_superblock;
  jsb->s_sequence = htonl(journal->j_tail_sequence);
  if (reset)
   jsb->s_start = 0;
  e2fsck_journal_sb_csum_set(journal, jsb);
  mark_buffer_dirty(journal->j_sb_buffer);
 }
 brelse(journal->j_sb_buffer);

 if (ctx->journal_io) {
  if (ctx->fs && ctx->fs->io != ctx->journal_io)
   ((ctx->journal_io)->manager->close((ctx->journal_io)));
  ctx->journal_io = 0;
 }


 if (journal->j_inode)
  ext2fs_free_mem(&journal->j_inode);

 if (journal->j_fs_dev)
  ext2fs_free_mem(&journal->j_fs_dev);
 ext2fs_free_mem(&journal);
}





errcode_t e2fsck_check_ext3_journal(e2fsck_t ctx)
{
 struct ext2_super_block *sb = ctx->fs->super;
 journal_t *journal;
 int recover = ext2fs_has_feature_journal_needs_recovery(ctx->fs->super);
 struct problem_context pctx;
 problem_t problem;
 int reset = 0, force_fsck = 0;
 errcode_t retval;


 if (!ext2fs_has_feature_journal(sb) &&
     !recover && sb->s_journal_inum == 0 && sb->s_journal_dev == 0 &&
     uuid_is_null(sb->s_journal_uuid))
   return 0;

 clear_problem_context(&pctx);
 pctx.num = sb->s_journal_inum;

 retval = e2fsck_get_journal(ctx, &journal);
 if (retval) {
  if ((retval == (2133571369L)) ||
      (retval == (2133571370L)) ||
      (retval == (2133571413L)) ||
      (retval == (2133571416L)))
   return e2fsck_journal_fix_bad_inode(ctx, &pctx);
  return retval;
 }

 retval = e2fsck_journal_load(journal);
 if (retval) {
  if ((retval == (2133571504L)) ||
      ((retval == (2133571395L)) &&
      (!fix_problem(ctx, 0x000026,
      &pctx))) ||
      ((retval == (2133571396L)) &&
      (!fix_problem(ctx, 0x000025,
      &pctx))) ||
      ((retval == (2133571414L)) &&
      (!fix_problem(ctx, 0x000027, &pctx))))
   retval = e2fsck_journal_fix_corrupt_super(ctx, journal,
          &pctx);
  e2fsck_journal_release(ctx, journal, 0, 1);
  return retval;
 }






no_has_journal:
 if (!ext2fs_has_feature_journal(sb)) {
  recover = ext2fs_has_feature_journal_needs_recovery(sb);
  if (fix_problem(ctx, 0x000016, &pctx)) {
   if (recover &&
       !fix_problem(ctx, 0x000017, &pctx))
    goto no_has_journal;




   force_fsck = recover ||
    (sb->s_journal_inum < (((sb)->s_rev_level == 0) ? 11 : (sb)->s_first_ino));

   sb->s_journal_inum = 0;
   sb->s_journal_dev = 0;
   memset(sb->s_journal_uuid, 0,
          sizeof(sb->s_journal_uuid));
   e2fsck_clear_recover(ctx, force_fsck);
  } else if (!(ctx->options & 0x0001)) {
   ext2fs_set_feature_journal(sb);
   ctx->fs->flags &= ~0x200;
   ext2fs_mark_super_dirty(ctx->fs);
  }
 }

 if (ext2fs_has_feature_journal(sb) &&
     !ext2fs_has_feature_journal_needs_recovery(sb) &&
     journal->j_superblock->s_start != 0) {

  fix_problem(ctx, 0x000018, &pctx);
  if (ctx->superblock)
   problem = 0x00002C;
  else
   problem = 0x00002B;
  if (fix_problem(ctx, problem, &pctx)) {
   ctx->options |= 0x0100;
   ext2fs_set_feature_journal_needs_recovery(sb);
   ext2fs_mark_super_dirty(ctx->fs);
  } else if (fix_problem(ctx,
           0x000019, &pctx)) {
   reset = 1;
   sb->s_state &= ~0x0001;
   ext2fs_mark_super_dirty(ctx->fs);
  }
 }






 if (!ext2fs_has_feature_journal_needs_recovery(sb) &&
     journal->j_superblock->s_errno) {
  ctx->fs->super->s_state |= 0x0002;
  ext2fs_mark_super_dirty(ctx->fs);
  journal->j_superblock->s_errno = 0;
  e2fsck_journal_sb_csum_set(journal, journal->j_superblock);
  mark_buffer_dirty(journal->j_sb_buffer);
 }

 e2fsck_journal_release(ctx, journal, reset, 0);
 return retval;
}

static errcode_t recover_ext3_journal(e2fsck_t ctx)
{
 struct problem_context pctx;
 journal_t *journal;
 errcode_t retval;

 clear_problem_context(&pctx);

 retval = jbd2_journal_init_revoke_record_cache();
 if (retval)
  return retval;

 retval = jbd2_journal_init_revoke_table_cache();
 if (retval)
  return retval;

 retval = e2fsck_get_journal(ctx, &journal);
 if (retval)
  return retval;

 retval = e2fsck_journal_load(journal);
 if (retval)
  goto errout;

 retval = jbd2_journal_init_revoke(journal, 1024);
 if (retval)
  goto errout;

 retval = -jbd2_journal_recover(journal);
 if (retval)
  goto errout;

 if (journal->j_failed_commit) {
  pctx.ino = journal->j_failed_commit;
  fix_problem(ctx, 0x00003A, &pctx);
  journal->j_superblock->s_errno = -
                                   22
                                         ;
  mark_buffer_dirty(journal->j_sb_buffer);
 }

 journal->j_tail_sequence = journal->j_transaction_sequence;

errout:
 jbd2_journal_destroy_revoke(journal);
 jbd2_journal_destroy_revoke_record_cache();
 jbd2_journal_destroy_revoke_table_cache();
 e2fsck_journal_release(ctx, journal, 1, 0);
 return retval;
}

errcode_t e2fsck_run_ext3_journal(e2fsck_t ctx)
{
 io_manager io_ptr = ctx->fs->io->manager;
 int blocksize = ctx->fs->blocksize;
 errcode_t retval, recover_retval;
 io_stats stats = 0;
 unsigned long long kbytes_written = 0;

 printf((gettext ("%s: recovering journal\n")), ctx->device_name);
 if (ctx->options & 0x0001) {
  printf((gettext ("%s: won't do journal recovery while read-only\n")),
         ctx->device_name);
  return (2133571405L);
 }

 if (ctx->fs->flags & 0x04)
  ext2fs_flush(ctx->fs);

 recover_retval = recover_ext3_journal(ctx);





 if (ctx->fs->super->s_kbytes_written &&
     ctx->fs->io->manager->get_stats)
  ctx->fs->io->manager->get_stats(ctx->fs->io, &stats);
 if (stats && stats->bytes_written)
  kbytes_written = stats->bytes_written >> 10;

 ext2fs_mmp_stop(ctx->fs);
 ext2fs_free(ctx->fs);
 retval = ext2fs_open(ctx->filesystem_name, ctx->openfs_flags,
        ctx->superblock, blocksize, io_ptr,
        &ctx->fs);
 if (retval) {
  com_err(ctx->program_name, retval,
   (gettext ("while trying to re-open %s")),
   ctx->device_name);
  fatal_error(ctx, 0);
 }
 ctx->fs->priv_data = ctx;
 ctx->fs->now = ctx->now;
 ctx->fs->flags |= 0x200;
 ctx->fs->super->s_kbytes_written += kbytes_written;


 e2fsck_clear_recover(ctx, recover_retval != 0);





 retval = e2fsck_check_ext3_journal(ctx);
 return retval ? retval : recover_retval;
}





static const char * const journal_names[] = {
 ".journal", "journal", ".journal.dat", "journal.dat", 0 };

void e2fsck_move_ext3_journal(e2fsck_t ctx)
{
 struct ext2_super_block *sb = ctx->fs->super;
 struct problem_context pctx;
 struct ext2_inode inode;
 ext2_filsys fs = ctx->fs;
 ext2_ino_t ino;
 errcode_t retval;
 const char * const * cpp;
 dgrp_t group;
 int mount_flags;

 clear_problem_context(&pctx);





 if ((ctx->options & 0x0001) ||
     (sb->s_journal_inum == 0) ||
     !ext2fs_has_feature_journal(sb))
  return;




 if (ext2fs_read_inode(fs, sb->s_journal_inum, &inode) != 0)
  return;




 if ((sb->s_jnl_backup_type == 0) ||
     ((sb->s_jnl_backup_type == 1) &&
      memcmp(inode.i_block, sb->s_jnl_blocks, (((12 + 1) + 1) + 1)*4))) {
  if (fix_problem(ctx, 0x00002D, &pctx)) {
   memcpy(sb->s_jnl_blocks, inode.i_block,
          (((12 + 1) + 1) + 1)*4);
   sb->s_jnl_blocks[15] = inode.i_size_high;
   sb->s_jnl_blocks[16] = inode.i_size;
   sb->s_jnl_backup_type = 1;
   ext2fs_mark_super_dirty(fs);
   fs->flags &= ~0x200;
  }
 }




 if (sb->s_journal_inum == 8)
  return;




 if (inode.i_links_count != 1)
  return;





 retval = ext2fs_check_if_mounted(ctx->filesystem_name, &mount_flags);
 if (retval || (mount_flags & 1))
  return;





 for (cpp = journal_names; *cpp; cpp++) {
  retval = ext2fs_lookup(fs, 2, *cpp,
           strlen(*cpp), 0, &ino);
  if ((retval == 0) && (ino == sb->s_journal_inum))
   break;
 }
 if (*cpp == 0)
  return;


 retval = ext2fs_read_bitmaps(fs);
 if (retval)
  return;

 pctx.str = *cpp;
 if (!fix_problem(ctx, 0x000028, &pctx))
  return;






 if ((retval = ext2fs_unlink(fs, 2, *cpp, ino, 0)) != 0)
  goto err_out;
 if ((retval = ext2fs_write_inode(fs, 8, &inode)) != 0)
  goto err_out;
 sb->s_journal_inum = 8;
 ext2fs_mark_super_dirty(fs);
 fs->flags &= ~0x200;
 inode.i_links_count = 0;
 inode.i_dtime = ctx->now;
 if ((retval = ext2fs_write_inode(fs, ino, &inode)) != 0)
  goto err_out;

 group = ext2fs_group_of_ino(fs, ino);
 ext2fs_unmark_inode_bitmap2(fs->inode_map, ino);
 ext2fs_mark_ib_dirty(fs);
 ext2fs_bg_free_inodes_count_set(fs, group, ext2fs_bg_free_inodes_count(fs, group) + 1);
 ext2fs_group_desc_csum_set(fs, group);
 fs->super->s_free_inodes_count++;
 return;

err_out:
 pctx.errcode = retval;
 fix_problem(ctx, 0x000029, &pctx);
 fs->super->s_state &= ~0x0001;
 ext2fs_mark_super_dirty(fs);
 return;
}





int e2fsck_fix_ext3_journal_hint(e2fsck_t ctx)
{
 struct ext2_super_block *sb = ctx->fs->super;
 struct problem_context pctx;
 char uuid[37], *journal_name;
 struct stat st;

 if (!ext2fs_has_feature_journal(sb) ||
     uuid_is_null(sb->s_journal_uuid))
   return 0;

 uuid_unparse(sb->s_journal_uuid, uuid);
 journal_name = blkid_get_devname(ctx->blkid, "UUID", uuid);
 if (!journal_name)
  return 0;

 if (stat(journal_name, &st) < 0) {
  free(journal_name);
  return 0;
 }

 if (st.st_rdev != sb->s_journal_dev) {
  clear_problem_context(&pctx);
  pctx.num = st.st_rdev;
  if (fix_problem(ctx, 0x000033, &pctx)) {
   sb->s_journal_dev = st.st_rdev;
   ext2fs_mark_super_dirty(ctx->fs);
  }
 }

 free(journal_name);
 return 0;
}
