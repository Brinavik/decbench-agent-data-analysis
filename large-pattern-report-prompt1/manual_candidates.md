| project | opt_level | binary | function | agent | pattern | hit | evidence |
| --- | --- | --- | --- | --- | --- | --- | --- |
| bash | O2-noinline | man2html | scan_format | codex | ST-01 | candidate | custom struct INTDEF absent; custom fields used=['next'] |
| bash | O2-noinline | man2html | scan_format | codex | FN-01 | candidate | parameter 2: TABLEROW** vs TblRow** |
| bash | O2-noinline | man2html | scan_format | claude-code | ST-01 | candidate | custom struct INTDEF absent; custom fields used=['next'] |
| coreutils | O2-noinline | chown | usage | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| coreutils | O2-noinline | chown | usage | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| coreutils | O2-noinline | comm | compare_files | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: col_sep, hard_LC_COLLATE, issued_disorder_warning, seen_unpairable |
| coreutils | O2-noinline | comm | compare_files | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| coreutils | O2-noinline | comm | compare_files | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: col_sep, hard_LC_COLLATE, issued_disorder_warning, seen_unpairable, total_option |
| coreutils | O2-noinline | comm | compare_files | claude-code | LAYOUT-01 | candidate | struct linebuffer.size: idx_t vs size_t; struct linebuffer.length: idx_t vs size_t |
| coreutils | O2-noinline | comm | compare_files | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| coreutils | O2-noinline | cp | copy_reg | codex | ST-01 | candidate | custom struct F_triple absent; custom fields used=['st_dev', 'st_ino'] |
| coreutils | O2-noinline | df | filter_mount_list | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: devlist_table, mount_list, print_grand_total, show_all_fs, show_listed_fs, show_local_fs |
| coreutils | O2-noinline | df | filter_mount_list | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| coreutils | O2-noinline | df | filter_mount_list | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: devlist_table, mount_list, print_grand_total, show_all_fs, show_listed_fs, show_local_fs |
| coreutils | O2-noinline | df | filter_mount_list | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| coreutils | O2-noinline | sort | mergelines_node | claude-code | LAYOUT-01 | candidate | struct merge_node.queued:  vs _Bool |
| coreutils | O2-noinline | touch | main | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: amtime_now, change_times, newtime, no_create, no_dereference, ref_file |
| coreutils | O2-noinline | touch | main | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| coreutils | O2-noinline | touch | main | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| diffutils | O2-noinline | cmp | cmp | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: buffer, file, file_desc, ignore_initial, stat_buf |
| diffutils | O2-noinline | cmp | cmp | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| diffutils | O2-noinline | cmp | cmp | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: buf_size, buffer, bytes, file, file_desc, ignore_initial, opt_print_bytes, stat_buf |
| diffutils | O2-noinline | cmp | cmp | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| diffutils | O2-noinline | diff3 | output_diff3_edscript | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: finalwrite, flagging, overlap_only, simple_only |
| diffutils | O2-noinline | diff3 | output_diff3_edscript | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| diffutils | O2-noinline | diff3 | output_diff3_edscript | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: finalwrite, flagging, overlap_only, show_2nd, simple_only |
| diffutils | O2-noinline | diff3 | output_diff3_edscript | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| dpkg | O2-noinline | dpkg-divert | diversion_add | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: opt_divertto, opt_rename, opt_test, opt_verbose |
| dpkg | O2-noinline | dpkg-divert | diversion_add | codex | ST-01 | candidate | custom struct dpkg_arch absent; custom fields used=['name'] |
| dpkg | O2-noinline | dpkg-divert | diversion_add | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| dpkg | O2-noinline | dpkg-divert | diversion_add | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: opt_divertto, opt_pkgname, opt_pkgname_match_any, opt_rename, opt_test, opt_verbose |
| dpkg | O2-noinline | dpkg-divert | diversion_add | claude-code | ST-01 | candidate | custom struct dpkg_arch absent; custom fields used=['name'] |
| dpkg | O2-noinline | dpkg-divert | diversion_add | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| dpkg | O2-noinline | dpkg-query | pkg_array_match_patterns | codex | FN-01 | candidate | parameter 2: pkg_array_visitor_func* vs pkg_array_apply_func* |
| e2fsprogs | O2-noinline | e2fsck | check_ea_in_inode | codex | ST-01 | candidate | custom struct ext2_dir_entry absent; custom fields used=['inode'] |
| e2fsprogs | O2-noinline | e2fsck | check_ea_in_inode | claude-code | ST-01 | candidate | custom struct ext2_dir_entry absent; custom fields used=['inode'] |
| gnutls | O2-noinline | certtool | yyparse | codex | FN-01 | candidate | parameter 1: parser_control* vs void* |
| gnutls | O2-noinline | certtool | yyparse | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: yycheck, yydefact, yydefgoto, yypact, yypgoto, yyr1, yyr2, yystos, yytable, yytranslate |
| gnutls | O2-noinline | certtool | yyparse | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| gnutls | O2-noinline | psktool | process_options | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| gnutls | O2-noinline | gnutls-cli | send_ocsp_request | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| gnutls | O2-noinline | gnutls-serv | main | codex | SC-01 | candidate | address-taken externs=['gl_array_list_implementation', 'x509_cred', 'srp_cred', 'psk_cred', 'anon_cred', 'anti_replay', 'session_ticket_key', 'x509_key_count', 'rawpk_key_count']; source statics=['generate', 'http', 'strip_crlf', 'x509ctype', 'debug', 'nodb', 'noticket', 'earlydata', 'listener_list', 'DEFAULT_DATA', 'cache_db', 'cache_db_ptr', 'cache_db_alloc'] |
| gnutls | O2-noinline | gnutls-serv | main | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| gnutls | O2-noinline | gnutls-serv | main | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: x509ctype |
| gnutls | O2-noinline | gnutls-serv | main | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| libacl | O2-noinline | chacl | main | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| libacl | O2-noinline | setfacl | restore | codex | PTR-01 | candidate | possible pointer typedef in struct do_set_args.seq: seq_t vs command_sequence * |
| libacl | O2-noinline | setfacl | restore | codex | LAYOUT-01 | candidate | struct do_set_args.seq: seq_t vs command_sequence * |
| libopencm3 | O2-noinline | cdcacm | dwc_poll | claude-code | FN-01 | candidate | parameter 1: usbd_device* vs void* |
| libopencm3 | O2-noinline | usbmidi | dwc_poll | claude-code | FN-01 | candidate | parameter 1: usbd_device* vs void* |
| openssh-portable | O2-noinline | ssh-pkcs11-helper | pkcs11_fetch_rsa_pubkey | codex | ST-01 | candidate | custom struct _CK_INFO absent; custom fields used=['flags'] |
| openssh-portable | O2-noinline | ssh-pkcs11-helper | pkcs11_fetch_rsa_pubkey | claude-code | ST-01 | candidate | custom struct _CK_INFO absent; custom fields used=['flags'] |
| openssh-portable | O2-noinline | ssh-sk-helper | cert_parse | codex | ST-01 | candidate | custom struct keytype absent; custom fields used=['cert', 'type'] |
| openssh-portable | O2-noinline | ssh-sk-helper | cert_parse | claude-code | ST-01 | candidate | custom struct keytype absent; custom fields used=['cert', 'type'] |
| shadow | O2-noinline | groupmod | grp_update | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | groupmod | grp_update | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: aflg, group_name, group_newid, group_newname, group_passwd, is_shadow_grp, user_list |
| shadow | O2-noinline | groupmod | grp_update | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | grpunconv | main | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: gr_locked, sgr_locked |
| shadow | O2-noinline | grpunconv | main | codex | ST-01 | candidate | custom struct sgrp absent; custom fields used=['sg_passwd'] |
| shadow | O2-noinline | grpunconv | main | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | grpunconv | main | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: gr_locked, sgr_locked |
| shadow | O2-noinline | grpunconv | main | claude-code | ST-01 | candidate | custom struct sgrp absent; custom fields used=['sg_passwd'] |
| shadow | O2-noinline | grpunconv | main | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | login | main | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: amroot, fflg, hflg, hostname, pamh, pflg, username |
| shadow | O2-noinline | login | main | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | newusers | close_files | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: gr_locked, is_shadow_grp, pw_locked, sgr_locked, spw_locked, sub_gid_locked, sub_uid_locked |
| shadow | O2-noinline | newusers | close_files | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | newusers | close_files | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: gr_locked, is_shadow_grp, pw_locked, sgr_locked, spw_locked, sub_gid_locked, sub_uid_locked |
| shadow | O2-noinline | newusers | close_files | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | useradd | grp_update | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: is_shadow_grp, user_groups, user_name |
| shadow | O2-noinline | useradd | grp_update | codex | ST-01 | candidate | custom struct sgrp absent; custom fields used=['sg_mem'] |
| shadow | O2-noinline | useradd | grp_update | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | useradd | grp_update | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: is_shadow_grp, user_groups, user_name |
| shadow | O2-noinline | useradd | grp_update | claude-code | ST-01 | candidate | custom struct sgrp absent; custom fields used=['sg_mem'] |
| shadow | O2-noinline | useradd | grp_update | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | vipw | main | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: quiet |
| shadow | O2-noinline | vipw | main | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | vipw | main | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | usermod | update_gshadow | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: aflg, user_groups, user_name, user_newname |
| shadow | O2-noinline | usermod | update_gshadow | codex | ST-01 | candidate | custom struct sgrp absent; custom fields used=['sg_adm', 'sg_mem'] |
| shadow | O2-noinline | usermod | update_gshadow | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| shadow | O2-noinline | usermod | update_gshadow | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: aflg, user_groups, user_name, user_newname |
| shadow | O2-noinline | usermod | update_gshadow | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | bootlogd | main | codex | SC-01 | candidate | address-taken externs=['buffer_out']; source statics=['first_run', 'inside_esc'] |
| sysvinit | O2-noinline | bootlogd | main | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | bootlogd | main | claude-code | SC-01 | candidate | address-taken externs=['inptr', 'createlogfile']; source statics=['first_run', 'inside_esc'] |
| sysvinit | O2-noinline | bootlogd | main | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | init | check_init_fifo | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | init | check_init_fifo | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | killall5 | readproc | codex | FN-01 | candidate | parameter 1: void vs int |
| sysvinit | O2-noinline | killall5 | readproc | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | killall5 | readproc | claude-code | FN-01 | candidate | parameter 1: void vs int |
| sysvinit | O2-noinline | last | list | codex | SC-01 | candidate | address-taken externs=['records_printed']; source statics=['utsize', 'buf', 'fpos', 'bpos', 'btmp'] |
| sysvinit | O2-noinline | last | list | codex | ST-01 | candidate | custom struct oldutmp absent; custom fields used=['ut_host', 'ut_line', 'ut_user'] |
| sysvinit | O2-noinline | last | list | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | last | list | claude-code | SC-01 | candidate | address-taken externs=['recno']; source statics=['utsize', 'buf', 'fpos', 'bpos', 'btmp'] |
| sysvinit | O2-noinline | last | list | claude-code | ST-01 | candidate | custom struct oldutmp absent; custom fields used=['ut_host', 'ut_line', 'ut_user'] |
| sysvinit | O2-noinline | last | list | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | shutdown | wall | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | shutdown | wall | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | sulogin | getpasswd | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: timeout |
| sysvinit | O2-noinline | sulogin | getpasswd | codex | ST-01 | candidate | custom struct chardata absent; custom fields used=['eol', 'erase', 'kill', 'parity'] |
| sysvinit | O2-noinline | sulogin | getpasswd | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | sulogin | getpasswd | claude-code | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: timeout |
| sysvinit | O2-noinline | sulogin | getpasswd | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | wall | wall | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| sysvinit | O2-noinline | wall | wall | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| zlib | O2-noinline | libz.so.1.2 | deflate_slow | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| zlib | O2-noinline | libz.so.1.2 | deflate_slow | claude-code | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| zlib | O2-noinline | minigzipsh | main | codex | SC-01 | candidate | file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: prog |
| zlib | O2-noinline | minigzipsh | main | codex | ARR-01 | candidate | static arrays/pointers and extern objects exist but role mapping is incomplete |
| zlib | O2-noinline | minigzip64 | inflate_fast | codex | PTR-01 | candidate | possible pointer typedef in struct inflate_state.head: gz_headerp vs struct gz_header_s * |
| zlib | O2-noinline | minigzip64 | inflate_fast | codex | LAYOUT-01 | candidate | struct inflate_state.head: gz_headerp vs struct gz_header_s *; struct inflate_state.lencode: code const * vs const code *; struct inflate_state.distcode: code const * vs const code *; struct inflate_state.codes: code[(852 +592)] vs code[1444] |
