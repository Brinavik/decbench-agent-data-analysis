// Function: main @ 0x165c0

uint main(int param_1,undefined8 *param_2)

{
  char cVar1;
  undefined2 uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  char *pcVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ushort **ppuVar13;
  int *piVar14;
  ulong uVar15;
  uint uVar16;
  undefined8 *puVar17;
  ulong uVar18;
  undefined4 *puVar19;
  long *plVar20;
  undefined *puVar21;
  long in_FS_OFFSET;
  bool bVar22;
  byte bVar23;
  uint local_16c;
  long local_150;
  uint local_148;
  uint local_144;
  long local_140;
  long local_130;
  int local_128;
  int local_124;
  long local_120;
  undefined *local_118;
  undefined8 local_110;
  long *local_108;
  uint local_100 [2];
  long local_f8 [10];
  ulong local_a8;
  uint local_84 [3];
  undefined1 local_78 [56];
  long local_40;
  
  bVar23 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_120 = 0;
  clear_problem_context(local_f8);
  sigcatcher_setup();
  setlocale(5,"");
  setlocale(0,"");
  bindtextdomain("e2fsprogs","/usr/share/locale");
  textdomain("e2fsprogs");
  set_com_err_gettext(PTR_gettext_001b1fd0);
  iVar4 = ext2fs_parse_version_string("1.46.5");
  iVar5 = ext2fs_get_library_version(0,&local_110);
  if (iVar5 < iVar4) {
    uVar11 = dcgettext(0,"Error: ext2fs library version out of date!\n",5);
    __fprintf_chk(stderr,1,&DAT_00178907,uVar11);
    DAT_001b7134 = DAT_001b7134 + 1;
  }
  lVar8 = FUN_0011a330(param_1,param_2,&local_108);
  if (lVar8 != 0) {
    uVar11 = dcgettext(0,"while trying to initialize program",5);
    com_err("e2fsck",lVar8,&DAT_00178907,uVar11);
                    /* WARNING: Subroutine does not return */
    exit(8);
  }
  FUN_0011a2b0();
  set_up_logging(local_108);
  if ((FILE *)local_108[5] != (FILE *)0x0) {
    fputs("E2fsck run: ",(FILE *)local_108[5]);
    if (0 < param_1) {
      puVar17 = param_2;
      while( true ) {
        pcVar9 = (char *)*puVar17;
        puVar17 = puVar17 + 1;
        fputs(pcVar9,(FILE *)local_108[5]);
        if (param_2 + (ulong)(param_1 - 1) + 1 == puVar17) break;
        fputc(0x20,(FILE *)local_108[5]);
      }
    }
    fputc(10,(FILE *)local_108[5]);
  }
  if ((FILE *)local_108[7] != (FILE *)0x0) {
    fputs("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n",(FILE *)local_108[7]);
    __fprintf_chk(local_108[7],1,"<problem_log time=\"%lu\">\n",local_108[0x69]);
    __fprintf_chk(local_108[7],1,"<invocation prog=\"%s\"",*param_2);
    if (1 < param_1) {
      uVar18 = 1;
      do {
        puVar17 = param_2 + uVar18;
        uVar15 = uVar18 & 0xffffffff;
        uVar18 = uVar18 + 1;
        __fprintf_chk(local_108[7],1," arg%d=\"%s\"",uVar15,*puVar17);
      } while ((long)param_1 != uVar18);
    }
    fputs("/>\n",(FILE *)local_108[7]);
  }
  init_resource_track(local_108 + 0x50,0);
  if ((((*(byte *)((long)local_108 + 0x4c) & 2) == 0) || (DAT_001b7134 != 0)) &&
     (log_err(local_108,"e2fsck %s (%s)\n","1.46.5","30-Dec-2021"), DAT_001b7134 != 0)) {
    uVar11 = error_message(0x7f2bb700);
    uVar12 = dcgettext(0,"\tUsing %s, %s\n",5);
    log_err(local_108,uVar12,uVar11,local_110);
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  FUN_00118290(local_108);
  if (((*(byte *)((long)local_108 + 0x4c) & 0xe) == 0) && ((int)local_108[0x5b] == 0)) {
    uVar11 = dcgettext(0,"need terminal for interactive repairs",5);
                    /* WARNING: Subroutine does not return */
    fatal_error(local_108,uVar11);
  }
  local_148 = 0x1000;
  local_150 = 0;
  local_108[0xc] = local_108[0xb];
  local_140 = 0;
  local_16c = 0x4100000;
  local_130 = -1;
  local_144 = 0;
LAB_0011689c:
  pcVar9 = getenv("TEST_IO_FLAGS");
  if ((pcVar9 == (char *)0x0) && (pcVar9 = getenv("TEST_IO_BLOCK"), pcVar9 == (char *)0x0)) {
    local_118 = unix_io_manager;
  }
  else {
    local_118 = test_io_manager;
    test_io_backing_manager = unix_io_manager;
  }
  profile_get_boolean(local_108[0x6c],"options","old_bitmaps",0,0,&local_128);
  if (local_128 == 0) {
    local_16c = local_16c | 0x30000;
  }
  else {
    local_16c = local_16c | 0x10000;
  }
  if ((*(uint *)((long)local_108 + 0x4c) & 1) == 0) {
    uVar16 = local_16c | 1;
    if ((*(uint *)((long)local_108 + 0x7c) & 6) != 6) {
      uVar16 = local_16c | 0x4001;
    }
    local_16c = uVar16;
    if (((*(uint *)((long)local_108 + 0x7c) & 4) != 0) &&
       (local_16c = uVar16 & 0xffffbfff, (*(uint *)((long)local_108 + 0x4c) & 0x100) == 0)) {
      local_16c = uVar16;
    }
  }
  if ((local_108[0x75] != 0) && (iVar4 = FUN_00118480(local_108,&local_118), iVar4 != 0)) {
                    /* WARNING: Subroutine does not return */
    exit(8);
  }
  puVar21 = local_118;
  *(uint *)(local_108 + 0x10) = local_16c;
  lVar10 = FUN_00118830(local_108,local_16c,local_118);
  lVar8 = lVar10;
  if ((local_108[0xc] != 0) || ((local_108[9] & 0x200000100U) != 0)) {
LAB_00116b80:
    lVar10 = lVar8;
    if (lVar8 - 0x7f2bb743U < 2) {
LAB_001170e8:
      lVar8 = lVar10;
      if (local_120 != 0) goto LAB_001170f6;
      goto LAB_00117050;
    }
LAB_00116b91:
    lVar8 = lVar10;
    if (lVar10 != 0) goto LAB_00117050;
LAB_00116b9a:
    uVar16 = *(uint *)(local_108 + 9);
    *(uint *)(local_120 + 0x10) = *(uint *)(local_120 + 0x10) | 0x200;
    if ((uVar16 & 0x800) == 0) goto code_r0x00116bb6;
    goto LAB_00116c13;
  }
  if ((lVar10 != 0x7f2bb713 && lVar10 != 0x7f2bb798) && (lVar10 != 0x7f2bb73c)) {
    if (lVar10 == 0) {
      local_140 = ext2fs_check_desc(local_120);
      if (local_140 != 0) goto LAB_00116ffd;
      goto LAB_00116b9a;
    }
    if (1 < lVar10 - 0x7f2bb743U) goto LAB_00117050;
    goto LAB_001170e8;
  }
  if (lVar10 != 0) {
    local_f8[0] = lVar10;
    fix_problem(local_108,0x44,local_f8);
  }
  if (local_140 != 0) {
LAB_00116ffd:
    local_f8[0] = local_140;
    fix_problem(local_108,0x45,local_f8);
    local_f8[0] = 0;
    lVar8 = local_140;
    if ((local_140 != 0xc) && (local_140 != 0x7f2bb746)) goto LAB_00116a0c;
    goto LAB_00117050;
  }
LAB_00116a0c:
  local_f8[0] = 0;
  if ((*(byte *)(local_120 + 0x12) & 1) != 0) {
    ext2fs_free();
    local_120 = 0;
LAB_00116a25:
    if (lVar10 == 0) {
      uVar11 = dcgettext(0,"Group descriptors look bad...",5);
    }
    else {
      uVar11 = dcgettext(0,"Superblock invalid,",5);
    }
    lVar8 = local_108[1];
    uVar12 = dcgettext(0,"%s: %s trying backup blocks...\n",5);
    log_out(local_108,uVar12,lVar8,uVar11);
    local_130 = local_108[0xc];
    get_backup_sb(local_108,local_120,local_108[2],puVar21);
    if (local_120 != 0) {
      ext2fs_close_free(&local_120);
    }
    lVar8 = FUN_00118830(local_108,local_16c,puVar21);
    local_150 = lVar10;
    if ((lVar10 == 0) && (lVar8 != 0)) {
      if (local_120 != 0) {
        ext2fs_close_free(&local_120);
      }
      uVar11 = error_message(lVar8);
      lVar8 = local_108[1];
      uVar12 = dcgettext(0,"%s: %s while using the backup blocks",5);
      log_out(local_108,uVar12,lVar8,uVar11);
      lVar8 = local_108[1];
      uVar11 = dcgettext(0,"%s: going back to original superblock\n",5);
      log_out(local_108,uVar11,lVar8);
      local_108[0xc] = local_130;
      lVar8 = FUN_00118830(local_108,local_16c,puVar21);
      local_150 = 0;
    }
    goto LAB_00116b80;
  }
  if (1 < *(uint *)(local_120 + 0x30)) goto LAB_00116a25;
  if (1 < lVar10 - 0x7f2bb743U) goto LAB_00116b91;
LAB_001170f6:
  lVar3 = *(long *)(local_120 + 0x20);
  lVar8 = lVar10;
  if (lVar3 != 0) {
    local_84[0] = *(uint *)(lVar3 + 0x5c) & 0xfffff1c0;
    local_84[1] = *(uint *)(lVar3 + 0x60) & 0xfffc1821;
    local_84[2] = *(uint *)(lVar3 + 100) & 0xffff0884;
    plVar20 = local_108;
    if ((local_84[0] == 0) && (local_84[1] == 0 && local_84[2] == 0)) goto LAB_00117050;
    goto LAB_0011713e;
  }
LAB_00117050:
  lVar10 = local_108[2];
  if (local_150 != 0) {
    lVar8 = local_150;
  }
  uVar11 = dcgettext(0,"while trying to open %s",5);
  com_err(local_108[1],lVar8,uVar11,lVar10);
  if (lVar8 == 0x7f2bb714) {
    uVar11 = dcgettext(0,
                       "The filesystem revision is apparently too high for this version of e2fsck.\n(Or the filesystem superblock is corrupt)\n\n"
                       ,5);
    log_out(local_108,&DAT_00178907,uVar11);
    fix_problem(local_108,4,local_f8);
    goto LAB_00117290;
  }
  if (lVar8 < 0x1f) {
    switch(lVar8) {
    case 1:
    case 0xd:
      puVar21 = &DAT_00178937;
      if ((*(byte *)((long)local_108 + 0x4c) & 1) == 0) {
        puVar21 = &DAT_0017893b;
      }
      uVar11 = dcgettext(0,"You must have %s access to the filesystem or be root\n",5);
      log_out(local_108,uVar11,puVar21);
      goto LAB_00117290;
    case 2:
      pcVar9 = "Possibly non-existent device?\n";
      break;
    default:
      goto switchD_001170c4_caseD_3;
    case 6:
      pcVar9 = "Possibly non-existent or swap device?\n";
      break;
    case 0x10:
      pcVar9 = "Filesystem mounted or opened exclusively by another program?\n";
      break;
    case 0x1e:
      pcVar9 = "Disk write-protected; use the -n option to do a read-only\ncheck of the device.\n";
    }
LAB_001176cb:
    uVar11 = dcgettext(0,pcVar9,5);
    log_out(local_108,&DAT_00178907,uVar11);
  }
  else {
    if (lVar8 == 0x7f2bb724) {
      pcVar9 = "Could this be a zero-length partition?\n";
      goto LAB_001176cb;
    }
    if (lVar8 == 0x7f2bb73c) {
      if ((local_16c & 0x800000) != 0) {
        fix_problem(local_108,4,local_f8);
        goto LAB_00117290;
      }
      if (local_120 != 0) {
        ext2fs_close_free(&local_120);
      }
      lVar8 = local_108[1];
      uVar11 = dcgettext(0,"%s: Trying to load superblock despite errors...\n",5);
      log_out(local_108,uVar11,lVar8);
      local_16c = local_16c | 0x800000;
      if (local_130 != -1) {
        local_108[0xc] = local_130;
      }
      goto LAB_0011689c;
    }
switchD_001170c4_caseD_3:
    fix_problem(local_108,4,local_f8);
    if (lVar8 == 0x7f2bb713) {
      check_plausibility(local_108[2],4,0);
    }
  }
LAB_00117290:
                    /* WARNING: Subroutine does not return */
  fatal_error(local_108,0);
code_r0x00116bb6:
  iVar4 = 0x400 << ((byte)*(undefined4 *)(*(long *)(local_120 + 0x20) + 0x18) & 0x1f);
  local_f8[0] = ext2fs_get_device_size2(local_108[2],iVar4,local_108 + 0xd);
  bVar22 = local_f8[0] == 0x10;
  if (bVar22) {
    ext2fs_close_free(&local_120);
    local_f8[0] = ext2fs_get_device_size2(local_108[2],iVar4,local_108 + 0xd);
  }
  if (local_f8[0] == 0x7f2bb750) {
    local_108[0xd] = 0;
  }
  else if (local_f8[0] != 0) {
    fix_problem(local_108,0xc,local_f8);
    *(uint *)(local_108 + 9) = *(uint *)(local_108 + 9) | 1;
                    /* WARNING: Subroutine does not return */
    fatal_error(local_108,0);
  }
  *(uint *)(local_108 + 9) = *(uint *)(local_108 + 9) | 0x800;
  if (bVar22) goto LAB_0011689c;
LAB_00116c13:
  plVar20 = local_108;
  lVar8 = *(long *)(local_120 + 0x20);
  *local_108 = local_120;
  uVar16 = *(uint *)(lVar8 + 0x4c);
  *(long *)(local_120 + 0xb8) = local_108[0x69];
  if (1 < uVar16) {
    lVar8 = local_108[2];
    uVar11 = dcgettext(0,"while trying to open %s",5);
    com_err(local_108[1],0x7f2bb714,uVar11,lVar8);
    goto LAB_001171ea;
  }
  pcVar9 = (char *)local_108[3];
  if (pcVar9 == (char *)0x0) {
    if (*(char *)(lVar8 + 0x78) != '\0') {
      lVar10 = string_copy(local_108,lVar8 + 0x78,0x10);
      plVar20[3] = lVar10;
      pcVar9 = (char *)local_108[3];
      if (pcVar9 != (char *)0x0) goto LAB_00116c3f;
    }
    plVar20 = local_108;
    lVar10 = string_copy(local_108,local_108[2],0);
    plVar20[3] = lVar10;
    pcVar9 = (char *)local_108[3];
  }
LAB_00116c3f:
  cVar1 = *pcVar9;
  if (cVar1 != '\0') {
    ppuVar13 = __ctype_b_loc();
    do {
      if (((*(byte *)((long)*ppuVar13 + (long)cVar1 * 2 + 1) & 0x20) != 0) || (cVar1 == ':')) {
        *pcVar9 = '_';
      }
      cVar1 = pcVar9[1];
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
  }
  if (local_108[7] != 0) {
    __fprintf_chk(local_108[7],1,"<filesystem dev=\"%s\"");
    iVar4 = uuid_is_null(lVar8 + 0x68);
    if (iVar4 == 0) {
      uuid_unparse(lVar8 + 0x68,local_78);
      __fprintf_chk(local_108[7],1," uuid=\"%s\"");
    }
    if (*(char *)(lVar8 + 0x78) != '\0') {
      __fprintf_chk(local_108[7],1," label=\"%.*s\"",0x10,lVar8 + 0x78);
    }
    fputs("/>\n",(FILE *)local_108[7]);
  }
  ehandler_init(*(undefined8 *)(local_120 + 8));
  lVar10 = local_120;
  iVar4 = FUN_00118200(*(undefined8 *)(local_120 + 0x20));
  if ((iVar4 != 0) && ((local_16c & 0x100000) != 0)) {
    lVar8 = FUN_00118950(lVar10,local_108);
    if (lVar8 != 0) {
                    /* WARNING: Subroutine does not return */
      fatal_error(local_108,0);
    }
    ext2fs_close_free(local_108);
    local_16c = local_16c & 0xffefffff;
    goto LAB_0011689c;
  }
  if (local_108[5] != 0) {
    e2p_uuid2str(lVar8 + 0x68);
    __fprintf_chk(local_108[5],1,"Filesystem UUID: %s\n");
  }
  if (((*(byte *)((long)local_108 + 0x7c) & 0x11) == 0) &&
     (lVar10 = e2fsck_check_ext3_journal(local_108), lVar10 != 0)) {
    lVar8 = local_108[3];
    uVar11 = dcgettext(0,"while checking journal for %s",5);
    com_err(local_108[1],lVar10,uVar11,lVar8);
    uVar11 = dcgettext(0,"Cannot proceed with file system check",5);
                    /* WARNING: Subroutine does not return */
    fatal_error(local_108,uVar11);
  }
  plVar20 = local_108;
  iVar4 = FUN_001181f0(lVar8);
  if (iVar4 != 0) {
    if ((*(byte *)((long)plVar20 + 0x4c) & 1) == 0) {
      if ((*(byte *)((long)plVar20 + 0x49) & 2) != 0) {
        lVar8 = plVar20[3];
        uVar11 = dcgettext(0,"unable to set superblock flags on %s\n",5);
        com_err(local_108[1],0,uVar11,lVar8);
                    /* WARNING: Subroutine does not return */
        fatal_error(local_108,0);
      }
      lVar8 = e2fsck_run_ext3_journal(plVar20);
      if (lVar8 == 0x7f2bb7af) {
        pcVar9 = "Journal checksum error found in %s\n";
        lVar8 = local_108[3];
      }
      else {
        if (lVar8 != 0x7f2bb7ae) {
          if (lVar8 != 0) {
            uVar11 = dcgettext(0,"while recovering journal of %s",5);
            com_err(local_108[1],lVar8,uVar11);
          }
          goto LAB_0011739f;
        }
        lVar8 = local_108[3];
        pcVar9 = "Journal corrupted in %s\n";
      }
      uVar11 = dcgettext(0,pcVar9,5);
      log_out(local_108,uVar11,lVar8);
LAB_0011739f:
      ext2fs_close_free(local_108);
      *(uint *)(local_108 + 9) = *(uint *)(local_108 + 9) | 0x200;
      goto LAB_0011689c;
    }
    uVar11 = dcgettext(0,
                       "Warning: skipping journal recovery because doing a read-only filesystem check.\n"
                       ,5);
    log_out(local_108,&DAT_00178907,uVar11);
    (**(code **)(*(long *)(*(long *)(*local_108 + 8) + 8) + 0x38))();
    plVar20 = local_108;
  }
  local_84[0] = *(uint *)(lVar8 + 0x5c) & 0xfffff1c0;
  local_84[1] = *(uint *)(lVar8 + 0x60) & 0xfffc1821;
  local_84[2] = *(uint *)(lVar8 + 100) & 0xffff0884;
  if ((local_84[0] != 0) || (local_84[1] != 0 || local_84[2] != 0)) {
LAB_0011713e:
    lVar8 = plVar20[2];
    uVar18 = 0;
    uVar11 = dcgettext(0,"%s has unsupported feature(s):",5);
    log_err(local_108,uVar11,lVar8);
    do {
      iVar4 = 0x20;
      uVar16 = local_84[uVar18];
      uVar6 = 1;
      do {
        while ((uVar6 & uVar16) == 0) {
          uVar6 = uVar6 * 2;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) goto LAB_001171c8;
        }
        uVar11 = e2p_feature2string(uVar18 & 0xffffffff,uVar6);
        log_err(local_108," %s",uVar11);
        iVar4 = iVar4 + -1;
        uVar6 = uVar6 * 2;
      } while (iVar4 != 0);
LAB_001171c8:
      uVar18 = uVar18 + 1;
    } while (uVar18 != 3);
    log_err(local_108,"\n");
LAB_001171ea:
    uVar11 = dcgettext(0,"Get a newer version of e2fsck!",5);
                    /* WARNING: Subroutine does not return */
    fatal_error(local_108,uVar11);
  }
  iVar4 = FUN_00118210(lVar8);
  if ((iVar4 != 0) && (*(long *)(local_120 + 0x168) == 0)) {
    uVar2 = *(undefined2 *)(lVar8 + 0x27c);
    lVar8 = plVar20[2];
    uVar11 = dcgettext(0,"%s has unsupported encoding: %0x\n",5);
    log_err(local_108,uVar11,lVar8,uVar2);
    goto LAB_001171ea;
  }
  if ((plVar20[0xc] != 0) && ((*(byte *)((long)plVar20 + 0x4c) & 1) == 0)) {
    ext2fs_mark_super_dirty(local_120);
  }
  lVar10 = sysconf(0x1e);
  uVar16 = (uint)lVar10;
  if ((int)(uint)lVar10 < 1) {
    uVar16 = local_148;
  }
  uVar6 = 1;
  if (*(uint *)(local_120 + 0x28) <= uVar16) {
    uVar6 = uVar16 / *(uint *)(local_120 + 0x28);
  }
  *(uint *)(local_108 + 0x6d) = uVar6;
  if (local_108[0xc] != 0) {
    set_latch_flags(0x50,4,0);
  }
  ext2fs_mark_valid(local_120);
  check_super_block(local_108);
  if ((*(byte *)(local_108 + 9) & 3) != 0) {
                    /* WARNING: Subroutine does not return */
    fatal_error(local_108,0);
  }
  FUN_00118e40();
  check_resize_inode(local_108);
  if (DAT_001b7120 == 0) {
    if (DAT_001b7138 != 0) {
      read_bad_blocks_file(local_108,0,DAT_001b7128 == 0);
    }
  }
  else {
    read_bad_blocks_file(local_108,DAT_001b7120,DAT_001b712c);
  }
  lVar10 = local_120;
  if ((*(byte *)(local_108 + 9) & 3) != 0) {
                    /* WARNING: Subroutine does not return */
    fatal_error(local_108,0);
  }
  ext2fs_mark_valid(local_120);
  lVar10 = ext2fs_read_bb_inode(lVar10,lVar10 + 0x88);
  if (lVar10 != 0) {
    error_message(lVar10);
    lVar10 = local_108[1];
    uVar11 = dcgettext(0,"%s: %s while reading bad blocks inode\n",5);
    log_out(local_108,uVar11,lVar10);
    preenhalt(local_108);
    uVar11 = dcgettext(0,"This doesn\'t bode well, but we\'ll try to go on...\n",5);
    log_out(local_108,&DAT_00178907,uVar11);
  }
  uVar6 = 0xffffffff;
  if ((*(char *)(lVar8 + 0xfd) == '\x01') && (iVar4 = FUN_001181c0(lVar8), iVar4 == 0)) {
    uVar6 = *(int *)(lVar8 + 0x148) << 0xc | *(uint *)(lVar8 + 0x14c) >> 0x14;
  }
  iVar4 = FUN_001181d0(lVar8);
  if (iVar4 != 0) {
    clear_problem_context(local_f8);
    local_f8[0] = quota_init_context(local_108 + 0x4f,*local_108,0);
    if (local_f8[0] != 0) {
      fix_problem(local_108,0x4c,local_f8);
                    /* WARNING: Subroutine does not return */
      fatal_error(local_108,0);
    }
  }
  uVar7 = e2fsck_run(local_108);
  e2fsck_clear_progbar(local_108);
  if ((((int)local_108[0x41] == 0) && ((*(byte *)(local_108 + 9) & 0x80) != 0)) &&
     (iVar4 = fix_problem(local_108,0x60001,local_f8), iVar4 != 0)) {
    if ((int)uVar6 < 0x400) {
      ext2fs_get_journal_params(local_100,local_120);
    }
    else {
      local_100[1] = 0;
      local_100[0] = uVar6;
    }
    uVar6 = local_100[0];
    uVar11 = dcgettext(0,"Creating journal (%d blocks): ",5);
    log_out(local_108,uVar11,uVar6);
    fflush(stdout);
    lVar10 = ext2fs_add_journal_inode3(local_120,local_100,0xffffffffffffffff);
    if (lVar10 == 0) {
      uVar11 = dcgettext(0," Done.\n",5);
      log_out(local_108,&DAT_00178907,uVar11);
      uVar11 = dcgettext(0,"\n*** journal has been regenerated ***\n",5);
      log_out(local_108,&DAT_00178907,uVar11);
    }
    else {
      uVar11 = error_message();
      log_out(local_108,"%s: while trying to create journal\n",uVar11);
    }
  }
  if ((uVar7 & 1) != 0) {
    uVar11 = dcgettext(0,"aborted",5);
                    /* WARNING: Subroutine does not return */
    fatal_error(local_108,uVar11);
  }
  if ((uVar7 & 2) == 0) {
    if ((local_108[0x4f] != 0) && ((int)local_108[0x41] == 0)) {
      uVar18 = 0;
      plVar20 = local_108;
      do {
        piVar14 = (int *)FUN_00118220(lVar8,uVar18 & 0xffffffff);
        if (*piVar14 != 0) {
          local_124 = 0;
          local_a8 = uVar18;
          lVar10 = quota_compare_and_update(plVar20[0x4f]);
          if (((lVar10 != 0) || (plVar20 = local_108, local_124 != 0)) &&
             ((iVar4 = fix_problem(local_108,0x60002,local_f8), plVar20 = local_108, iVar4 != 0 &&
              (local_f8[0] = quota_write_inode(local_108[0x4f],1 << ((byte)uVar18 & 0x1f)),
              plVar20 = local_108, local_f8[0] != 0)))) {
            fix_problem(local_108,0x60006,local_f8);
            plVar20 = local_108;
          }
        }
        uVar18 = uVar18 + 1;
      } while (uVar18 != 3);
      quota_release_context(plVar20 + 0x4f);
    }
  }
  else {
    lVar10 = local_108[3];
    if (lVar10 == 0) {
      lVar10 = local_108[2];
    }
    uVar11 = dcgettext(0,"%s: e2fsck canceled.\n",5);
    log_out(local_108,uVar11,lVar10);
    local_144 = 0x20;
  }
  lVar10 = local_120;
  if (uVar7 == 4) {
    uVar11 = dcgettext(0,"Restarting e2fsck from the beginning...\n",5);
    log_out(local_108,&DAT_00178907,uVar11);
    lVar8 = e2fsck_reset_context(local_108);
    if (lVar8 != 0) {
      uVar11 = dcgettext(0,"while resetting context",5);
      com_err(local_108[1],lVar8,&DAT_00178907,uVar11);
                    /* WARNING: Subroutine does not return */
      fatal_error(local_108,0);
    }
    ext2fs_close_free(local_108);
    local_148 = uVar16;
    goto LAB_0011689c;
  }
  iVar4 = ext2fs_test_changed(local_120);
  plVar20 = local_108;
  if ((local_108[9] & 0x100000007U) == 0) {
    iVar5 = ext2fs_test_valid(lVar10);
    if (iVar5 == 0) {
      *(ushort *)(lVar8 + 0x3a) = *(ushort *)(lVar8 + 0x3a) & 0xfffe;
    }
    else {
      if ((*(byte *)(lVar8 + 0x3a) & 1) == 0) {
        local_144 = local_144 | 1;
      }
      *(undefined2 *)(lVar8 + 0x3a) = 1;
      iVar5 = check_backup_super_block(plVar20);
      plVar20 = local_108;
      if (iVar5 != 0) {
        *(uint *)(local_120 + 0x10) = *(uint *)(local_120 + 0x10) & 0xfffffdff;
      }
    }
    if ((*(byte *)((long)plVar20 + 0x49) & 0x20) == 0) {
      *(int *)(lVar8 + 0x40) = (int)plVar20[0x69];
    }
    *(undefined2 *)(lVar8 + 0x34) = 0;
    puVar19 = (undefined4 *)(lVar8 + 0x194);
    for (lVar10 = 0x1b; lVar10 != 0; lVar10 = lVar10 + -1) {
      *puVar19 = 0;
      puVar19 = puVar19 + (ulong)bVar23 * -2 + 1;
    }
    local_f8[0] = ext2fs_set_gdt_csum(*plVar20);
    if (local_f8[0] != 0) {
      fix_problem(local_108,0x60003,local_f8);
    }
    ext2fs_mark_super_dirty(local_120);
  }
  plVar20 = local_108;
  iVar5 = FUN_001181e0(*(undefined8 *)(*local_108 + 0x20));
  if ((iVar5 == 0) || ((*(uint *)((long)plVar20 + 0x4c) & 0x40008) != 0x40008)) {
    if ((*(byte *)((long)plVar20 + 0x4c) & 1) == 0) {
      e2fsck_write_bitmaps(plVar20);
      if (((*(byte *)(local_120 + 0x10) & 4) != 0) &&
         (local_f8[0] = ext2fs_flush(*local_108), local_f8[0] != 0)) {
        fix_problem(local_108,0x60004,local_f8);
      }
      local_f8[0] = (**(code **)(*(long *)(*(long *)(*local_108 + 8) + 8) + 0x38))();
      plVar20 = local_108;
      if (local_f8[0] != 0) {
        fix_problem(local_108,0x60005,local_f8);
        plVar20 = local_108;
      }
    }
    if (iVar4 != 0) {
      if ((*(byte *)((long)plVar20 + 0x49) & 0x40) != 0) {
        local_144 = local_144 | 1;
      }
      if ((*(byte *)((long)plVar20 + 0x4c) & 2) == 0) {
        lVar10 = plVar20[3];
        uVar11 = dcgettext(0,"\n%s: ***** FILE SYSTEM WAS MODIFIED *****\n",5);
        log_out(local_108,uVar11,lVar10);
        plVar20 = local_108;
      }
      if ((*(byte *)((long)plVar20 + 0x7c) & 2) != 0) {
        lVar10 = plVar20[3];
        uVar11 = dcgettext(0,"%s: ***** REBOOT SYSTEM *****\n",5);
        log_out(local_108,uVar11,lVar10);
        local_144 = local_144 | 2;
        plVar20 = local_108;
      }
    }
  }
  iVar4 = ext2fs_test_valid(local_120);
  uVar16 = local_144 & 0x20;
  if (iVar4 == 0) {
    lVar10 = plVar20[3];
    uVar11 = dcgettext(0,"\n%s: ********** WARNING: Filesystem still has errors **********\n\n",5);
    log_out(local_108,uVar11,lVar10);
    local_144 = local_144 & 0xfffffffe | 4;
    plVar20 = local_108;
    if (uVar16 == 0) goto LAB_00117e36;
  }
  else {
    if (uVar16 == 0) {
LAB_00117e36:
      FUN_00119400(plVar20);
      goto LAB_00117e3e;
    }
    if ((*(byte *)(lVar8 + 0x3a) & 2) != 0) {
      lVar10 = plVar20[3];
      uVar11 = dcgettext(0,"\n%s: ********** WARNING: Filesystem still has errors **********\n\n",5)
      ;
      log_out(local_108,uVar11,lVar10);
      local_144 = local_144 & 0xfffffffe | 4;
      plVar20 = local_108;
    }
  }
  profile_get_boolean(plVar20[0x6c],"options","allow_cancellation",0,0,&local_124);
  uVar16 = local_144 & 0xfffffffe;
  local_144 = uVar16;
  if (((local_124 != 0) && (iVar4 = ext2fs_test_valid(local_120), iVar4 != 0)) &&
     (local_144 = 0, (*(ushort *)(lVar8 + 0x3a) & 3) != 1)) {
    local_144 = uVar16;
  }
LAB_00117e3e:
  print_resource_track(local_108,0,local_108 + 0x50,*(undefined8 *)(*local_108 + 8));
  ext2fs_close_free(local_108);
  free((void *)local_108[0x4e]);
  if (local_108[5] != 0) {
    __fprintf_chk(local_108[5],1,"Exit status: %d\n",local_144);
  }
  e2fsck_free_context(local_108);
  remove_error_table(et_ext2_error_table);
  remove_error_table(et_prof_error_table);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_144;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: signal_progress_on @ 0x18250

void signal_progress_on(void)

{
  if (e2fsck_global_ctx != 0) {
    *(code **)(e2fsck_global_ctx + 0x160) = FUN_0011b500;
  }
  return;
}



// Function: signal_cancel @ 0x18270

void signal_cancel(void)

{
  if (e2fsck_global_ctx != 0) {
    *(uint *)(e2fsck_global_ctx + 0x48) = *(uint *)(e2fsck_global_ctx + 0x48) | 2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(0x20);
}



// Function: check_mount @ 0x18290

void check_mount(long param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char *pcVar7;
  
  lVar4 = ext2fs_check_if_mounted(*(undefined8 *)(param_1 + 0x10),param_1 + 0x7c);
  if (lVar4 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x10);
    uVar5 = dcgettext(0,"while determining whether %s is mounted.",5);
    com_err("ext2fs_check_if_mount",lVar4,uVar5,uVar6);
    return;
  }
  uVar1 = *(uint *)(param_1 + 0x7c);
  if ((uVar1 & 0x11) == 0) {
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x4c);
  if ((uVar1 & 6) == 6) {
    if ((uVar2 & 0x200) == 0) {
      return;
    }
    if ((uVar2 & 1) != 0) goto LAB_001182dc;
LAB_001183b6:
    if (((uVar2 & 0x100) == 0) || ((uVar1 & 4) == 0)) goto LAB_001182dc;
  }
  else if ((uVar2 & 1) == 0) goto LAB_001183b6;
  if ((uVar2 & 0x200) == 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x10);
    pcVar7 = "Warning!  %s is mounted.\n";
    if ((uVar1 & 1) == 0) {
      pcVar7 = "Warning!  %s is in use.\n";
    }
    uVar5 = dcgettext(0,pcVar7,5);
    log_out(param_1,uVar5,uVar6);
    return;
  }
LAB_001182dc:
  uVar6 = *(undefined8 *)(param_1 + 0x10);
  pcVar7 = "Warning!  %s is mounted.\n";
  if ((uVar1 & 1) == 0) {
    pcVar7 = "Warning!  %s is in use.\n";
  }
  uVar5 = dcgettext(0,pcVar7 + 10,5);
  log_out(param_1,uVar5,uVar6);
  if ((*(int *)(param_1 + 0x2d8) != 0) && ((*(byte *)(param_1 + 0x7c) & 0x10) == 0)) {
    puts("\a\a\a\a");
    uVar6 = dcgettext(0,
                      "\n\nWARNING!!!  The filesystem is mounted.   If you continue you ***WILL***\ncause ***SEVERE*** filesystem damage.\n\n"
                      ,5);
    log_out(param_1,&DAT_00178907,uVar6);
    puts("\a\a\a");
    uVar6 = dcgettext(0,"Do you really want to continue",5);
    iVar3 = ask_yn(param_1,uVar6,0);
    if (iVar3 != 0) {
      return;
    }
    uVar6 = dcgettext(0,"check aborted.\n",5);
    __printf_chk(1,&DAT_00178907,uVar6);
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  uVar6 = dcgettext(0,"Cannot continue, aborting.\n\n",5);
                    /* WARNING: Subroutine does not return */
  fatal_error(param_1,uVar6);
}



// Function: e2fsck_setup_tdb @ 0x18480

ulong e2fsck_setup_tdb(long param_1,undefined8 *param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char *__s;
  size_t sVar7;
  size_t sVar8;
  char *__name;
  uint *puVar9;
  ulong uVar10;
  undefined8 uVar11;
  ulong uVar12;
  long in_FS_OFFSET;
  char *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = (char *)0x0;
  if ((*(char **)(param_1 + 0x3a8) == (char *)0x0) || (**(char **)(param_1 + 0x3a8) == '\0')) {
    pcVar4 = getenv("E2FSPROGS_UNDO_DIR");
    local_48 = pcVar4;
    if (pcVar4 == (char *)0x0) {
      profile_get_string(*(undefined8 *)(param_1 + 0x360),"defaults","undo_dir",0,
                         "/var/lib/e2fsprogs",&local_48);
      pcVar4 = local_48;
      iVar3 = strcmp(local_48,"none");
      if ((iVar3 != 0) && (*pcVar4 != '\0')) {
        iVar3 = access(pcVar4,2);
        pcVar4 = local_48;
        if (iVar3 == 0) {
          pcVar4 = strdup(*(char **)(param_1 + 0x10));
          if (pcVar4 != (char *)0x0) {
            bVar2 = true;
            goto LAB_001185ed;
          }
          __name = (char *)0x0;
          uVar12 = 0xc;
          uVar10 = 0xc;
LAB_001187d8:
          free(local_48);
          goto LAB_00118689;
        }
      }
      uVar12 = 0;
      free(pcVar4);
      goto LAB_001184f9;
    }
    iVar3 = strcmp(pcVar4,"none");
    if ((iVar3 != 0) && (*pcVar4 != '\0')) {
      iVar3 = access(pcVar4,2);
      if (iVar3 == 0) {
        pcVar4 = strdup(*(char **)(param_1 + 0x10));
        bVar2 = false;
        if (pcVar4 == (char *)0x0) {
          __name = (char *)0x0;
          uVar12 = 0xc;
          uVar10 = 0xc;
        }
        else {
LAB_001185ed:
          __s = __xpg_basename(pcVar4);
          sVar7 = strlen(local_48);
          sVar8 = strlen(__s);
          __name = malloc(sVar7 + 0x10 + sVar8);
          if (__name == (char *)0x0) {
            uVar12 = 0xc;
            uVar10 = 0xc;
            free(pcVar4);
          }
          else {
            __sprintf_chk(__name,1,0xffffffffffffffff,"%s/e2fsck-%s.e2undo",local_48,__s);
            free(pcVar4);
            iVar3 = unlink(__name);
            if (iVar3 < 0) {
              puVar9 = (uint *)__errno_location();
              uVar1 = *puVar9;
              uVar12 = (ulong)uVar1;
              if (uVar1 != 2) {
                uVar10 = (ulong)(int)uVar1;
                uVar5 = dcgettext(0,"while trying to delete %s",5);
                com_err(*(undefined8 *)(param_1 + 8),uVar10,uVar5,__name);
                goto LAB_00118680;
              }
            }
            uVar10 = set_undo_io_backing_manager(*param_2);
            if (uVar10 == 0) {
              *param_2 = undo_io_manager;
              uVar10 = set_undo_io_backup_file(__name);
              if (uVar10 == 0) {
                uVar5 = *(undefined8 *)(param_1 + 0x10);
                uVar11 = dcgettext(0,
                                   "Overwriting existing filesystem; this can be undone using the command:\n    e2undo %s %s\n\n"
                                   ,5);
                __printf_chk(1,uVar11,__name,uVar5);
                if (bVar2) {
                  free(local_48);
                }
                free(__name);
                goto LAB_001184f6;
              }
            }
            uVar12 = uVar10 & 0xffffffff;
          }
LAB_00118680:
          if (bVar2) goto LAB_001187d8;
        }
LAB_00118689:
        free(__name);
        goto LAB_00118533;
      }
    }
LAB_001184f6:
    uVar12 = 0;
  }
  else {
    uVar10 = set_undo_io_backing_manager(*param_2);
    if (uVar10 == 0) {
      uVar5 = *(undefined8 *)(param_1 + 0x3a8);
      *param_2 = undo_io_manager;
      uVar10 = set_undo_io_backup_file(uVar5);
      if (uVar10 == 0) {
        uVar5 = *(undefined8 *)(param_1 + 0x10);
        uVar11 = *(undefined8 *)(param_1 + 0x3a8);
        uVar6 = dcgettext(0,
                          "Overwriting existing filesystem; this can be undone using the command:\n    e2undo %s %s\n\n"
                          ,5);
        uVar12 = 0;
        __printf_chk(1,uVar6,uVar11,uVar5);
        goto LAB_001184f9;
      }
    }
    uVar12 = uVar10 & 0xffffffff;
LAB_00118533:
    uVar5 = dcgettext(0,"while trying to setup undo file\n",5);
    com_err(*(undefined8 *)(param_1 + 8),uVar10,&DAT_00178907,uVar5);
  }
LAB_001184f9:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: try_open_fs @ 0x18830

long try_open_fs(long param_1,undefined4 param_2,undefined8 param_3,long *param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  long *plVar6;
  
  *param_4 = 0;
  lVar1 = *(long *)(param_1 + 0x60);
  uVar3 = *(undefined8 *)(param_1 + 0x20);
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  if (lVar1 == 0) {
    lVar1 = ext2fs_open2(uVar4,uVar3,param_2,0,0,param_3,param_4);
  }
  else {
    iVar2 = 7;
    iVar5 = 0x400;
    if (*(int *)(param_1 + 0x50) == 0) {
      while (plVar6 = param_4, lVar1 = ext2fs_open2(uVar4,uVar3,param_2,lVar1,iVar5,param_3),
            lVar1 != 0) {
        iVar5 = iVar5 * 2;
        iVar2 = iVar2 + -1;
        if (iVar2 == 0) {
          return lVar1;
        }
        if (*param_4 != 0) {
          ext2fs_free(*param_4,plVar6);
          *param_4 = 0;
        }
        lVar1 = *(long *)(param_1 + 0x60);
        uVar3 = *(undefined8 *)(param_1 + 0x20);
        uVar4 = *(undefined8 *)(param_1 + 0x10);
      }
      goto LAB_001188f3;
    }
    lVar1 = ext2fs_open2(uVar4,uVar3,param_2,lVar1,*(int *)(param_1 + 0x50),param_3,param_4);
  }
  if (lVar1 != 0) {
    return lVar1;
  }
LAB_001188f3:
  *(long *)(*param_4 + 0xe0) = param_1;
  e2fsck_set_bitmap_type(*param_4,2,"default",0);
  return 0;
}



// Function: e2fsck_check_mmp @ 0x18950

long e2fsck_check_mmp(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  long in_FS_OFFSET;
  undefined1 auStack_98 [104];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(auStack_98);
  lVar3 = *(long *)(param_1 + 0x110);
  if (lVar3 != 0) {
LAB_0011898c:
    lVar3 = ext2fs_mmp_read(param_1,*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x168),lVar3);
    if (lVar3 != 0) goto LAB_00118a7f;
    uVar6 = *(uint *)(*(long *)(param_1 + 0x110) + 4);
    if (uVar6 == 0xff4d4d50) {
LAB_001189e5:
      uVar6 = (uint)*(ushort *)(*(long *)(param_1 + 0x110) + 0x70);
      uVar1 = (uint)*(ushort *)(*(long *)(param_1 + 0x20) + 0x166);
      if (uVar6 < uVar1) {
        uVar6 = uVar1;
      }
      if (uVar6 < 5) {
        uVar6 = 5;
      }
      uVar1 = uVar6 * 2 + 1;
      if ((DAT_001b7130 != 0) || (0x14 < uVar1)) {
        uVar4 = dcgettext(0,
                          "MMP interval is %u seconds and total wait time is %u seconds. Please wait...\n"
                          ,5);
        log_out(param_2,uVar4,uVar6,uVar1 * 2);
      }
      goto LAB_00118a10;
    }
    if (uVar6 == 0xe24d4d50) {
      lVar3 = 0x7f2bb78c;
    }
    else {
      if (uVar6 < 0xe24d4d50) goto LAB_001189e5;
      lVar3 = 0x7f2bb78e;
    }
switchD_00118aa8_caseD_7f2bb78c:
    uVar4 = dcgettext(0,"while checking MMP block",5);
    com_err(*(undefined8 *)(param_2 + 8),lVar3,&DAT_00178907,uVar4);
    uVar4 = *(undefined8 *)(param_2 + 0x18);
    uVar5 = dcgettext(0,
                      "If you are sure the filesystem is not in use on any node, run:\n\'tune2fs -f -E clear_mmp %s\'\n"
                      ,5);
    dump_mmp_msg(*(undefined8 *)(param_1 + 0x110),uVar5,uVar4);
    goto LAB_00118a10;
  }
  lVar3 = ext2fs_get_mem(*(undefined4 *)(param_1 + 0x28),param_1 + 0x110);
  if (lVar3 == 0) {
    lVar3 = *(long *)(param_1 + 0x110);
    goto LAB_0011898c;
  }
LAB_00118a7f:
  if (lVar3 == 0x7f2bb78d) {
    iVar2 = fix_problem(param_2,0x42,auStack_98);
    if (iVar2 != 0) {
      lVar3 = 0;
      *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x168) = 0;
      ext2fs_mark_super_dirty(param_1);
    }
    goto LAB_00118a10;
  }
  switch(lVar3) {
  case 0x7f2bb78a:
    iVar2 = fix_problem(param_2,0x43,auStack_98);
    break;
  case 0x7f2bb78b:
    uVar4 = dcgettext(0,"while checking MMP block",5);
    com_err(*(undefined8 *)(param_2 + 8),0x7f2bb78b,&DAT_00178907,uVar4);
    dump_mmp_msg(*(undefined8 *)(param_1 + 0x110),0);
    goto LAB_00118a10;
  case 0x7f2bb78c:
  case 0x7f2bb78e:
    goto switchD_00118aa8_caseD_7f2bb78c;
  default:
    uVar4 = dcgettext(0,"while reading MMP block",5);
    com_err(*(undefined8 *)(param_2 + 8),lVar3,&DAT_00178907,uVar4);
    goto LAB_00118a10;
  case 0x7f2bb79a:
    iVar2 = fix_problem(param_2,0x47,auStack_98);
  }
  if (iVar2 != 0) {
    lVar3 = 0;
    ext2fs_mmp_clear(param_1);
  }
LAB_00118a10:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: is_on_batt @ 0x18c40

bool is_on_batt(void)

{
  int iVar1;
  FILE *pFVar2;
  DIR *__dirp;
  dirent *pdVar3;
  long in_FS_OFFSET;
  bool bVar4;
  int local_20c;
  char local_208 [80];
  undefined1 local_1b8 [80];
  char local_168 [296];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  pFVar2 = fopen("/sys/class/power_supply/AC/online","r");
  if (pFVar2 != (FILE *)0x0) {
    iVar1 = __isoc99_fscanf(pFVar2,"%u\n",&local_20c);
    if (iVar1 == 1) {
      fclose(pFVar2);
      bVar4 = local_20c == 0;
      goto LAB_00118d00;
    }
    fclose(pFVar2);
  }
  pFVar2 = fopen("/proc/apm","r");
  if (pFVar2 == (FILE *)0x0) {
    __dirp = opendir("/proc/acpi/ac_adapter");
    if (__dirp == (DIR *)0x0) {
LAB_00118e2e:
      bVar4 = false;
    }
    else {
      do {
        do {
          do {
            pdVar3 = readdir(__dirp);
            if (pdVar3 == (dirent *)0x0) {
              closedir(__dirp);
              goto LAB_00118e2e;
            }
            iVar1 = strncmp(".",pdVar3->d_name,1);
          } while (iVar1 == 0);
          __snprintf_chk(local_168,0x11d,1,0x11d,"/proc/acpi/ac_adapter/%s/state",pdVar3->d_name);
          pFVar2 = fopen(local_168,"r");
        } while (pFVar2 == (FILE *)0x0);
        iVar1 = __isoc99_fscanf(pFVar2,"%79s %79s",local_1b8,local_208);
        if (iVar1 != 2) {
          local_208[0] = '\0';
        }
        fclose(pFVar2);
        iVar1 = strncmp(local_208,"off-line",8);
      } while (iVar1 != 0);
      closedir(__dirp);
      bVar4 = true;
    }
  }
  else {
    iVar1 = __isoc99_fscanf(pFVar2,"%79s %79s %79s %x",local_208,local_208,local_208,&local_20c);
    if (iVar1 != 4) {
      local_20c = 1;
    }
    fclose(pFVar2);
    bVar4 = local_20c != 1;
  }
LAB_00118d00:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_if_skip @ 0x18e40

void check_if_skip(long *param_1)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  char *pcVar11;
  uint uVar12;
  ulong uVar13;
  long in_FS_OFFSET;
  int local_b0;
  int local_ac;
  undefined1 local_a8 [8];
  int local_a0;
  int local_9c;
  long local_80;
  long local_78;
  long local_40;
  
  lVar3 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar4 = FUN_00118c40();
  if ((*(byte *)((long)param_1 + 0x49) & 0x40) != 0) goto LAB_00118e75;
  profile_get_boolean(param_1[0x6c],"options","broken_system_clock",0,0,&local_ac);
  if ((*(byte *)((long)param_1 + 0x49) & 0x20) != 0) {
    local_ac = 1;
  }
  profile_get_boolean(param_1[0x6c],"options","defer_check_on_battery",0,1,&local_b0);
  if (local_b0 == 0) {
    iVar4 = 0;
  }
  if ((DAT_001b7120 != 0) || ((*(uint *)((long)param_1 + 0x4c) & 0x100) != 0 || DAT_001b7138 != 0))
  goto LAB_00118e75;
  if ((*(uint *)((long)param_1 + 0x4c) & 0x1000) != 0) goto LAB_001191ba;
  uVar13 = (ulong)*(uint *)(*(long *)(lVar3 + 0x20) + 0x40);
  if (param_1[0x69] < (long)uVar13) {
    uVar13 = uVar13 - param_1[0x6a];
  }
  uVar1 = *(ushort *)(*(long *)(lVar3 + 0x20) + 0x3a);
  if (((uVar1 & 2) == 0) && (iVar5 = ext2fs_test_valid(lVar3), iVar5 != 0)) {
    if ((uVar1 & 1) == 0) {
      uVar12 = 0;
      lVar6 = dcgettext(0," was not cleanly unmounted",5);
      goto LAB_00118f7e;
    }
    iVar5 = check_backup_super_block(param_1);
    if (iVar5 != 0) {
      uVar12 = 0;
      lVar6 = dcgettext(0," primary superblock features different from backup",5);
      goto LAB_00118f7e;
    }
    lVar6 = *(long *)(lVar3 + 0x20);
    if ((*(short *)(lVar6 + 0x36) < 1) ||
       ((uint)*(ushort *)(lVar6 + 0x34) < (uint)(int)*(short *)(lVar6 + 0x36))) {
      uVar12 = *(uint *)(lVar6 + 0x44);
      if (local_ac == 0) {
        if (uVar12 != 0) {
          if (param_1[0x69] < (long)uVar13) {
            lVar6 = dcgettext(0," has filesystem last checked time in the future",5);
            if (iVar4 == 0) {
              uVar12 = 0;
              goto LAB_00118f7e;
            }
          }
          else if ((long)(ulong)uVar12 <= (long)(param_1[0x69] - uVar13)) {
            lVar6 = dcgettext(0," has gone %u days without being checked",5);
            lVar8 = param_1[0x69] - (ulong)*(uint *)(*(long *)(lVar3 + 0x20) + 0x40);
            uVar12 = (uint)(lVar8 / 0x15180);
            if ((iVar4 == 0) ||
               ((long)(ulong)(uint)(*(int *)(*(long *)(lVar3 + 0x20) + 0x44) * 2) <= lVar8))
            goto LAB_00118f7e;
          }
        }
      }
      else if (uVar12 != 0) {
        log_out(param_1,&DAT_001783f4,param_1[3]);
        uVar7 = dcgettext(0,"ignoring check interval, broken_system_clock set\n",5);
        log_out(param_1,&DAT_00178907,uVar7);
      }
    }
    else {
      lVar6 = dcgettext(0," has been mounted %u times without being checked",5);
      uVar1 = *(ushort *)(*(long *)(lVar3 + 0x20) + 0x34);
      uVar12 = (uint)uVar1;
      if ((iVar4 == 0) || ((uint)(*(short *)(*(long *)(lVar3 + 0x20) + 0x36) * 2) <= (uint)uVar1))
      goto LAB_00118f7e;
    }
  }
  else {
    uVar12 = 0;
    lVar6 = dcgettext(0," contains a file system with errors",5);
LAB_00118f7e:
    if (lVar6 != 0) {
      log_out(param_1,&DAT_00178907,param_1[3]);
      log_out(param_1,lVar6,uVar12);
      uVar7 = dcgettext(0,", check forced.\n",5);
      log_out(param_1,&DAT_00178907,uVar7);
LAB_00118e75:
      if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
  clear_problem_context(local_a8);
  local_a0 = *(int *)(*(long *)(lVar3 + 0x20) + 0x10);
  local_9c = (int)param_1[0xf];
  if (((local_a0 != local_9c) && ((*(byte *)((long)param_1 + 0x4c) & 1) == 0)) &&
     (iVar5 = fix_problem(param_1,0x3f,local_a8), iVar5 != 0)) {
    *(int *)(*(long *)(lVar3 + 0x20) + 0x10) = (int)param_1[0xf];
    ext2fs_mark_super_dirty(lVar3);
  }
  clear_problem_context(local_a8);
  local_80 = ext2fs_free_blocks_count(*(undefined8 *)(lVar3 + 0x20));
  local_78 = param_1[0xe];
  if (((local_80 != local_78) && ((*(byte *)((long)param_1 + 0x4c) & 1) == 0)) &&
     (iVar5 = fix_problem(param_1,0x40,local_a8), iVar5 != 0)) {
    ext2fs_free_blocks_count_set(*(undefined8 *)(lVar3 + 0x20),param_1[0xe]);
    ext2fs_mark_super_dirty(lVar3);
  }
  uVar7 = ext2fs_blocks_count(*(undefined8 *)(lVar3 + 0x20));
  lVar8 = ext2fs_blocks_count(*(undefined8 *)(lVar3 + 0x20));
  lVar9 = ext2fs_free_blocks_count(*(undefined8 *)(lVar3 + 0x20));
  lVar6 = param_1[3];
  iVar5 = **(int **)(lVar3 + 0x20);
  iVar2 = (*(int **)(lVar3 + 0x20))[4];
  uVar10 = dcgettext(0,"%s: clean, %u/%u files, %llu/%llu blocks",5);
  log_out(param_1,uVar10,lVar6,iVar5 - iVar2,iVar5,lVar8 - lVar9,uVar7,uVar10);
  lVar3 = *(long *)(lVar3 + 0x20);
  if (*(short *)(lVar3 + 0x36) < 1) {
    if (((local_ac != 0) || (*(uint *)(lVar3 + 0x44) == 0)) ||
       ((long)(param_1[0x69] - (ulong)*(uint *)(lVar3 + 0x40)) <
        (long)(ulong)*(uint *)(lVar3 + 0x44))) goto LAB_001191a9;
LAB_00119177:
    pcVar11 = " (check deferred; on battery)";
    if (iVar4 == 0) {
      pcVar11 = " (check after next mount)";
    }
    uVar7 = dcgettext(0,pcVar11,5);
    log_out(param_1,&DAT_00178907,uVar7);
  }
  else {
    iVar5 = (int)*(short *)(lVar3 + 0x36) - (uint)*(ushort *)(lVar3 + 0x34);
    lVar6 = (long)iVar5;
    if (lVar6 < 1) {
      lVar6 = 1;
    }
    if (((local_ac == 0) && (*(uint *)(lVar3 + 0x44) != 0)) &&
       ((long)(ulong)*(uint *)(lVar3 + 0x44) <=
        (long)(param_1[0x69] - (ulong)*(uint *)(lVar3 + 0x40)))) goto LAB_00119177;
    if (iVar5 < 6) {
      if (iVar5 < 2) goto LAB_00119177;
      uVar7 = dcgettext(0," (check in %ld mounts)",5);
      log_out(param_1,uVar7,lVar6);
    }
  }
LAB_001191a9:
  log_out(param_1,"\n");
LAB_001191ba:
  ext2fs_close_free(param_1);
  e2fsck_free_context();
                    /* WARNING: Subroutine does not return */
  exit(0);
}



// Function: show_stats @ 0x19400

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void show_stats(long *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  ulong uVar14;
  uint uVar15;
  int iVar16;
  uint *puVar17;
  long in_FS_OFFSET;
  bool bVar18;
  double dVar19;
  int local_50;
  int local_4c;
  int local_44;
  long local_40;
  
  lVar9 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar4 = param_1[0x5c];
  lVar5 = param_1[0x60];
  lVar6 = param_1[0x5e];
  uVar1 = **(uint **)(lVar9 + 0x20);
  uVar15 = uVar1 - (*(uint **)(lVar9 + 0x20))[4];
  uVar7 = ext2fs_blocks_count();
  lVar8 = ext2fs_blocks_count(*(undefined8 *)(lVar9 + 0x20));
  lVar9 = ext2fs_free_blocks_count(*(undefined8 *)(lVar9 + 0x20));
  uVar14 = lVar8 - lVar9;
  if (uVar15 == 0) {
    local_4c = 0;
    iVar11 = 0;
    local_50 = 0;
  }
  else {
    local_50 = (int)((uint)((int)param_1[99] * 10000) / uVar15 + 5) / 10;
    local_4c = (int)((uint)(*(int *)((long)param_1 + 0x31c) * 10000) / uVar15 + 5) / 10;
    iVar11 = (int)((uint)(((int)param_1[99] + *(int *)((long)param_1 + 0x31c)) * 10000) / uVar15 + 5
                  ) / 10;
  }
  if (DAT_001b7130 == 0) {
    lVar9 = param_1[3];
    uVar10 = dcgettext(0,"%s: %u/%u files (%0d.%d%% non-contiguous), %llu/%llu blocks\n",5);
    log_out(param_1,uVar10,lVar9,uVar15,uVar1,(long)iVar11 / 10 & 0xffffffff,
            (long)iVar11 % 10 & 0xffffffff,uVar14,uVar7,10);
LAB_0011996d:
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  profile_get_boolean(param_1[0x6c],"options","report_features",0,0,&local_44);
  if ((DAT_001b7130 != 0) && (local_44 != 0)) {
    iVar11 = 0;
    log_out(param_1,"\nFilesystem features:");
    local_44 = 0;
    puVar17 = (uint *)(*(long *)(*param_1 + 0x20) + 0x5c);
    do {
      iVar16 = 0x20;
      uVar13 = 1;
      iVar12 = local_44;
      do {
        while ((uVar13 & *puVar17) != 0) {
          iVar11 = iVar11 + 1;
          uVar10 = e2p_feature2string(iVar12,uVar13);
          log_out(param_1," %s",uVar10);
          iVar16 = iVar16 + -1;
          uVar13 = uVar13 * 2;
          iVar12 = local_44;
          if (iVar16 == 0) goto LAB_00119a39;
        }
        uVar13 = uVar13 * 2;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
LAB_00119a39:
      local_44 = iVar12 + 1;
      puVar17 = puVar17 + 1;
    } while (local_44 < 3);
    if (iVar11 == 0) {
      log_out(param_1," (none)");
    }
    log_out(param_1,"\n");
  }
  dVar19 = (double)uVar15 * _DAT_00178cd0;
  uVar10 = dcngettext(0,"\n%12u inode used (%2.2f%%, out of %u)\n",
                      "\n%12u inodes used (%2.2f%%, out of %u)\n",uVar15,5);
  log_out(dVar19 / (double)uVar1,param_1,uVar10,uVar15,uVar1);
  lVar9 = param_1[99];
  uVar10 = dcngettext(0,"%12u non-contiguous file (%0d.%d%%)\n",
                      "%12u non-contiguous files (%0d.%d%%)\n",(int)lVar9,5);
  log_out(param_1,uVar10,(int)lVar9,(long)local_50 / 10 & 0xffffffff,
          (long)local_50 % 10 & 0xffffffff);
  uVar2 = *(undefined4 *)((long)param_1 + 0x31c);
  uVar10 = dcngettext(0,"%12u non-contiguous directory (%0d.%d%%)\n",
                      "%12u non-contiguous directories (%0d.%d%%)\n",uVar2,5);
  log_out(param_1,uVar10,uVar2,(long)local_4c / 10 & 0xffffffff,(long)local_4c % 10 & 0xffffffff);
  uVar2 = *(undefined4 *)((long)param_1 + 0x314);
  lVar9 = param_1[0x62];
  uVar3 = *(undefined4 *)((long)param_1 + 0x30c);
  uVar10 = dcgettext(0,"             # of inodes with ind/dind/tind blocks: %u/%u/%u\n",5);
  log_out(param_1,uVar10,uVar3,(int)lVar9,uVar2);
  lVar9 = 4;
  while (*(int *)((long)param_1 + lVar9 * 4 + 0x330) == 0) {
    bVar18 = lVar9 == 0;
    lVar9 = lVar9 + -1;
    if (bVar18) goto LAB_0011965c;
  }
  uVar10 = dcgettext(0,"             Extent depth histogram: ",5);
  log_out(param_1,&DAT_00178907,uVar10);
  local_44 = 0;
  while( true ) {
    log_out(param_1,&DAT_00179651,*(undefined4 *)((long)param_1 + (long)local_44 * 4 + 0x330));
    iVar11 = local_44 + 1;
    if ((int)lVar9 <= local_44) break;
    local_44 = iVar11;
    if (iVar11 != 0) {
      fputc(0x2f,stdout);
    }
  }
  local_44 = iVar11;
  log_out(param_1,"\n");
LAB_0011965c:
  iVar11 = (int)lVar4 * 2 + -1;
  iVar12 = (int)lVar5 - iVar11;
  dVar19 = (double)uVar14 * _DAT_00178cd0;
  uVar10 = dcngettext(0,"%12llu block used (%2.2f%%, out of %llu)\n",
                      "%12llu blocks used (%2.2f%%, out of %llu)\n",uVar14,5);
  log_out(dVar19 / (double)uVar7,param_1,uVar10,uVar14,uVar7);
  uVar2 = *(undefined4 *)((long)param_1 + 0x304);
  uVar10 = dcngettext(0,"%12u bad block\n","%12u bad blocks\n",uVar2,5);
  log_out(param_1,uVar10,uVar2);
  lVar9 = param_1[100];
  uVar10 = dcngettext(0,"%12u large file\n","%12u large files\n",(int)lVar9,5);
  log_out(param_1,uVar10,(int)lVar9);
  uVar2 = *(undefined4 *)((long)param_1 + 0x2e4);
  uVar10 = dcngettext(0,"\n%12u regular file\n","\n%12u regular files\n",uVar2,5);
  log_out(param_1,uVar10,uVar2);
  lVar9 = param_1[0x5c];
  uVar10 = dcngettext(0,"%12u directory\n","%12u directories\n",(int)lVar9,5);
  log_out(param_1,uVar10,(int)lVar9);
  uVar2 = *(undefined4 *)((long)param_1 + 0x2ec);
  uVar10 = dcngettext(0,"%12u character device file\n","%12u character device files\n",uVar2,5);
  log_out(param_1,uVar10,uVar2);
  lVar9 = param_1[0x5d];
  uVar10 = dcngettext(0,"%12u block device file\n","%12u block device files\n",(int)lVar9,5);
  log_out(param_1,uVar10,(int)lVar9);
  uVar2 = *(undefined4 *)((long)param_1 + 0x2fc);
  uVar10 = dcngettext(0,"%12u fifo\n","%12u fifos\n",uVar2,5);
  log_out(param_1,uVar10,uVar2);
  lVar9 = param_1[0x5e];
  uVar10 = dcngettext(0,"%12u link\n","%12u links\n",(int)lVar6 - iVar11,5);
  log_out(param_1,uVar10,(int)lVar9 - iVar11);
  uVar2 = *(undefined4 *)((long)param_1 + 0x2f4);
  uVar10 = dcngettext(0,"%12u symbolic link","%12u symbolic links",uVar2,5);
  log_out(param_1,uVar10,uVar2);
  lVar9 = param_1[0x5f];
  uVar10 = dcngettext(0," (%u fast symbolic link)\n"," (%u fast symbolic links)\n",(int)lVar9,5);
  log_out(param_1,uVar10,(int)lVar9);
  lVar9 = param_1[0x61];
  uVar10 = dcngettext(0,"%12u socket\n","%12u sockets\n",(int)lVar9,5);
  log_out(param_1,uVar10,(int)lVar9);
  log_out(param_1,"------------\n");
  uVar10 = dcngettext(0,"%12u file\n","%12u files\n",iVar12,5);
  log_out(param_1,uVar10,iVar12);
  goto LAB_0011996d;
}



// Function: usage @ 0x19bb0

void usage(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 8);
  uVar1 = dcgettext(0,
                    "Usage: %s [-panyrcdfktvDFV] [-b superblock] [-B blocksize]\n\t\t[-l|-L bad_blocks_file] [-C fd] [-j external_journal]\n\t\t[-E extended-options] [-z undo_file] device\n"
                    ,5);
  __fprintf_chk(stderr,1,uVar1,uVar2);
  uVar2 = dcgettext(0,
                    "\nEmergency help:\n -p                   Automatic repair (no questions)\n -n                   Make no changes to the filesystem\n -y                   Assume \"yes\" to all questions\n -c                   Check for bad blocks and add them to the badblock list\n -f                   Force checking even if filesystem is marked clean\n"
                    ,5);
  __fprintf_chk(stderr,1,&DAT_00178907,uVar2);
  uVar2 = dcgettext(0,
                    " -v                   Be verbose\n -b superblock        Use alternative superblock\n -B blocksize         Force blocksize when looking for superblock\n -j external_journal  Set location of the external journal\n -l bad_blocks_file   Add to badblocks list\n -L bad_blocks_file   Set badblocks list\n -z undo_file         Create an undo file\n"
                    ,5);
  __fprintf_chk(stderr,1,&DAT_00178907,uVar2);
                    /* WARNING: Subroutine does not return */
  exit(0x10);
}



// Function: syntax_err_report @ 0x19c50

void syntax_err_report(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = error_message(param_2);
  uVar2 = dcgettext(0,"Syntax error in e2fsck config file (%s, line #%d)\n\t%s\n",5);
  __fprintf_chk(stderr,1,uVar2,param_1,param_3,uVar1);
                    /* WARNING: Subroutine does not return */
  exit(8);
}



// Function: parse_extended_opts @ 0x19cb0

void parse_extended_opts(long param_1,undefined8 param_2)

{
  FILE *pFVar1;
  int iVar2;
  char *__ptr;
  ulong uVar3;
  char *pcVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined *puVar8;
  char *pcVar9;
  int iVar10;
  long in_FS_OFFSET;
  char *local_48;
  long local_40;
  
  iVar10 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  __ptr = (char *)string_copy(param_1,param_2,0);
  pcVar7 = __ptr;
  if (__ptr == (char *)0x0) {
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      free((void *)0x0);
      return;
    }
  }
  else {
LAB_00119d3c:
    do {
      if (*pcVar7 == '\0') break;
      local_48 = strchr(pcVar7,0x2c);
      pcVar9 = local_48;
      if (local_48 != (char *)0x0) {
        *local_48 = '\0';
        pcVar9 = local_48 + 1;
      }
      pcVar4 = strchr(pcVar7,0x3d);
      if (pcVar4 == (char *)0x0) {
        iVar2 = strcmp(pcVar7,"ea_ver");
        if (iVar2 != 0) {
          iVar2 = strcmp(pcVar7,"readahead_kb");
          pcVar4 = (char *)0x0;
          if (iVar2 != 0) goto LAB_00119e4e;
        }
        goto LAB_00119e80;
      }
      *pcVar4 = '\0';
      pcVar4 = pcVar4 + 1;
      iVar2 = strcmp(pcVar7,"ea_ver");
      if (iVar2 == 0) {
        uVar3 = strtoul(pcVar4,&local_48,0);
        if ((*local_48 != '\0') || (1 < (int)uVar3 - 1U)) {
          pcVar7 = (char *)dcgettext(0,"Invalid EA version.\n",5);
          puVar8 = &DAT_00178907;
          goto LAB_00119ead;
        }
        *(int *)(param_1 + 0x358) = (int)uVar3;
      }
      else {
        iVar2 = strcmp(pcVar7,"readahead_kb");
        if (iVar2 == 0) {
          uVar5 = strtoull(pcVar4,&local_48,0);
          if (*local_48 == '\0') {
            *(ulonglong *)(param_1 + 0x398) = uVar5;
            pcVar7 = pcVar9;
            if (pcVar9 == (char *)0x0) break;
            goto LAB_00119d3c;
          }
          pcVar7 = (char *)dcgettext(0,"Invalid readahead buffer size.\n",5);
          puVar8 = &DAT_00178907;
LAB_00119ead:
          iVar10 = iVar10 + 1;
          __fprintf_chk(stderr,1,puVar8,pcVar7);
        }
        else {
LAB_00119e4e:
          iVar2 = strcmp(pcVar7,"fragcheck");
          if (iVar2 == 0) {
            *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x800;
          }
          else {
            iVar2 = strcmp(pcVar7,"journal_only");
            if (iVar2 == 0) {
              if (pcVar4 != (char *)0x0) goto LAB_00119e80;
              *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x1000;
            }
            else {
              iVar2 = strcmp(pcVar7,"discard");
              if (iVar2 == 0) {
                *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x2000;
              }
              else {
                iVar2 = strcmp(pcVar7,"nodiscard");
                if (iVar2 == 0) {
                  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xffffdfff;
                }
                else {
                  iVar2 = strcmp(pcVar7,"optimize_extents");
                  if (iVar2 == 0) {
                    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffeffff;
                  }
                  else {
                    iVar2 = strcmp(pcVar7,"no_optimize_extents");
                    if (iVar2 == 0) {
                      *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x10000;
                    }
                    else {
                      iVar2 = strcmp(pcVar7,"inode_count_fullmap");
                      if (iVar2 == 0) {
                        *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x20000;
                      }
                      else {
                        iVar2 = strcmp(pcVar7,"no_inode_count_fullmap");
                        if (iVar2 == 0) {
                          *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffdffff;
                        }
                        else {
                          iVar2 = strcmp(pcVar7,"log_filename");
                          if (iVar2 == 0) {
                            if (pcVar4 == (char *)0x0) {
LAB_00119e80:
                              iVar10 = iVar10 + 1;
                            }
                            else {
                              uVar6 = string_copy(param_1,pcVar4,0);
                              *(undefined8 *)(param_1 + 0x30) = uVar6;
                            }
                          }
                          else {
                            iVar2 = strcmp(pcVar7,"problem_log");
                            if (iVar2 == 0) {
                              if (pcVar4 == (char *)0x0) goto LAB_00119e80;
                              uVar6 = string_copy(param_1,pcVar4,0);
                              *(undefined8 *)(param_1 + 0x40) = uVar6;
                            }
                            else {
                              iVar2 = strcmp(pcVar7,"bmap2extent");
                              if (iVar2 == 0) {
                                *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x4000;
                              }
                              else {
                                iVar2 = strcmp(pcVar7,"fixes_only");
                                if (iVar2 == 0) {
                                  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x8000;
                                }
                                else {
                                  iVar2 = strcmp(pcVar7,"unshare_blocks");
                                  if (iVar2 == 0) {
                                    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x40100;
                                  }
                                  else {
                                    iVar2 = strcmp(pcVar7,"check_encoding");
                                    if (iVar2 != 0) {
                                      puVar8 = (undefined *)
                                               dcgettext(0,"Unknown extended option: %s\n",5);
                                      goto LAB_00119ead;
                                    }
                                    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x100000
                                    ;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      pcVar7 = pcVar9;
    } while (pcVar9 != (char *)0x0);
    free(__ptr);
    pFVar1 = stderr;
    if (iVar10 != 0) {
      pcVar7 = (char *)dcgettext(0,
                                 "\nExtended options are separated by commas, and may take an argument which\nis set off by an equals (\'=\') sign.  Valid extended options are:\n\n"
                                 ,5);
      fputs(pcVar7,pFVar1);
      pFVar1 = stderr;
      pcVar7 = (char *)dcgettext(0,"\tea_ver=<ea_version (1 or 2)>\n",5);
      fputs(pcVar7,pFVar1);
      fputs("\tfragcheck\n",stderr);
      fputs("\tjournal_only\n",stderr);
      fputs("\tdiscard\n",stderr);
      fputs("\tnodiscard\n",stderr);
      fputs("\toptimize_extents\n",stderr);
      fputs("\tno_optimize_extents\n",stderr);
      fputs("\tinode_count_fullmap\n",stderr);
      fputs("\tno_inode_count_fullmap\n",stderr);
      pFVar1 = stderr;
      pcVar7 = (char *)dcgettext(0,"\treadahead_kb=<buffer size>\n",5);
      fputs(pcVar7,pFVar1);
      fputs("\tbmap2extent\n",stderr);
      fputs("\tunshare_blocks\n",stderr);
      fputs("\tfixes_only\n",stderr);
      fputs("\tcheck_encoding\n",stderr);
      fputc(10,stderr);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: reserve_stdio_fds @ 0x1a2b0

void reserve_stdio_fds(void)

{
  int __fd;
  int *piVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined8 uStack_18;
  
  do {
    __fd = open("/dev/null",2);
    if (__fd < 0) {
      piVar1 = __errno_location();
      pcVar2 = strerror(*piVar1);
      uVar3 = dcgettext(0,"ERROR: Couldn\'t open /dev/null (%s)\n",5);
      __fprintf_chk(stderr,1,uVar3,pcVar2,uStack_18);
      return;
    }
  } while (__fd < 3);
  close(__fd);
  return;
}



// Function: PRS @ 0x1a330

long PRS(int param_1,char **param_2,long *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  bool bVar3;
  FILE *__stream;
  uint uVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  size_t sVar11;
  char *__dest;
  undefined8 uVar12;
  int *piVar13;
  long lVar14;
  char *pcVar15;
  undefined1 *puVar16;
  __sigset_t *p_Var17;
  char *pcVar18;
  long in_FS_OFFSET;
  bool bVar19;
  byte bVar20;
  char *local_118;
  uint local_ec;
  long local_e8;
  undefined8 local_e0;
  sigaction local_d8;
  long local_40;
  
  bVar20 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar6 = e2fsck_allocate_context(&local_e8);
  __stream = stdout;
  if (lVar6 == 0) {
    *param_3 = local_e8;
    e2fsck_global_ctx = local_e8;
    setvbuf(__stream,(char *)0x0,2,0x2000);
    setvbuf(stderr,(char *)0x0,2,0x2000);
    pcVar7 = getenv("E2FSCK_FORCE_INTERACTIVE");
    if ((pcVar7 == (char *)0x0) &&
       ((iVar5 = isatty(0), iVar5 == 0 || (iVar5 = isatty(1), iVar5 == 0)))) {
      *(undefined1 *)(local_e8 + 0x2dc) = 1;
      *(undefined1 *)(local_e8 + 0x2de) = 2;
    }
    else {
      *(undefined4 *)(local_e8 + 0x2d8) = 1;
    }
    puVar16 = &DAT_001b70a0;
    for (lVar14 = 0x7f; lVar14 != 0; lVar14 = lVar14 + -1) {
      *puVar16 = 0x3d;
      puVar16 = puVar16 + (ulong)bVar20 * -2 + 1;
    }
    puVar16 = &DAT_001b7020;
    for (lVar14 = 0x7f; lVar14 != 0; lVar14 = lVar14 + -1) {
      *puVar16 = 0x20;
      puVar16 = puVar16 + (ulong)bVar20 * -2 + 1;
    }
    add_error_table(et_ext2_error_table);
    add_error_table(et_prof_error_table);
    blkid_get_cache(local_e8 + 0x88,0);
    if ((param_1 == 0) || (*param_2 == (char *)0x0)) {
      *(char **)(local_e8 + 8) = "e2fsck";
    }
    else {
      *(char **)(local_e8 + 8) = *param_2;
    }
    uVar8 = get_memory_size();
    bVar3 = false;
    local_118 = (char *)0x0;
    *(undefined8 *)(local_e8 + 0x398) = 0xffffffffffffffff;
switchD_0011a4ed_caseD_72:
    local_ec = getopt(param_1,param_2,"panyrcC:B:dE:fvtFVM:b:I:j:P:l:L:N:SsDkz:");
    lVar14 = local_e8;
    pcVar7 = optarg;
    if (local_ec != 0xffffffff) goto code_r0x0011a4e6;
    if (DAT_001b7134 == 0) {
      if (param_1 + -1 != optind) {
        FUN_00119bb0(local_e8);
LAB_0011b156:
        uVar9 = dcgettext(0,"The -c and the -l/-L options may not be both used at the same time.\n",
                          5);
        __fprintf_chk(stderr,1,&DAT_00178907,uVar9);
                    /* WARNING: Subroutine does not return */
        exit(0x10);
      }
      if ((*(uint *)(local_e8 + 0x4c) & 0x408) == 0x408) {
        uVar9 = dcgettext(0,"The -n and -D options are incompatible.",5);
        com_err(*(undefined8 *)(local_e8 + 8),0,&DAT_00178907,uVar9);
                    /* WARNING: Subroutine does not return */
        fatal_error(local_e8,0);
      }
      if ((*(byte *)(local_e8 + 0x4c) & 8) != 0) {
        if (DAT_001b7138 != 0) {
          uVar9 = dcgettext(0,"The -n and -c options are incompatible.",5);
          com_err(*(undefined8 *)(local_e8 + 8),0,&DAT_00178907,uVar9);
                    /* WARNING: Subroutine does not return */
          fatal_error(local_e8,0);
        }
        if (DAT_001b7120 != (void *)0x0) {
          uVar9 = dcgettext(0,"The -n and -l/-L options are incompatible.",5);
          com_err(*(undefined8 *)(local_e8 + 8),0,&DAT_00178907,uVar9);
                    /* WARNING: Subroutine does not return */
          fatal_error(local_e8,0);
        }
        *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 1;
      }
      lVar10 = (long)optind;
      pcVar7 = strchr(param_2[lVar10],0x3f);
      if (pcVar7 == (char *)0x0) {
        *(undefined8 *)(lVar14 + 0x20) = 0;
      }
      else {
        *(char **)(lVar14 + 0x20) = pcVar7 + 1;
        *pcVar7 = '\0';
        lVar10 = (long)optind;
        lVar14 = local_e8;
      }
      uVar9 = blkid_get_devname(*(undefined8 *)(lVar14 + 0x88),param_2[lVar10],0);
      *(undefined8 *)(lVar14 + 0x10) = uVar9;
      if (*(long *)(local_e8 + 0x10) == 0) {
        pcVar7 = param_2[optind];
        uVar9 = dcgettext(0,"Unable to resolve \'%s\'",5);
        com_err(*(undefined8 *)(local_e8 + 8),0,uVar9,pcVar7);
                    /* WARNING: Subroutine does not return */
        fatal_error(local_e8,0);
      }
      if (local_118 != (char *)0x0) {
        FUN_00119cb0(local_e8,local_118);
      }
      pcVar7 = getenv("E2FSCK_FIXES_ONLY");
      if (pcVar7 != (char *)0x0) {
        *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 0x8000;
      }
      if ((*(uint *)(local_e8 + 0x4c) & 0x8400) == 0x8400) {
        uVar9 = dcgettext(0,"The -D and -E fixes_only options are incompatible.",5);
        com_err(*(undefined8 *)(local_e8 + 8),0,&DAT_00178907,uVar9);
                    /* WARNING: Subroutine does not return */
        fatal_error(local_e8,0);
      }
      if ((*(uint *)(local_e8 + 0x4c) & 0xc000) == 0xc000) {
        uVar9 = dcgettext(0,"The -E bmap2extent and fixes_only options are incompatible.",5);
        com_err(*(undefined8 *)(local_e8 + 8),0,&DAT_00178907,uVar9);
                    /* WARNING: Subroutine does not return */
        fatal_error(local_e8,0);
      }
      pcVar7 = getenv("E2FSCK_CONFIG");
      if (pcVar7 != (char *)0x0) {
        PTR_s__etc_e2fsck_conf_001b20b0 = pcVar7;
      }
      profile_set_syntax_err_cb(FUN_00119c50);
      profile_init(&PTR_s__etc_e2fsck_conf_001b20b0,local_e8 + 0x360);
      profile_get_boolean(*(undefined8 *)(local_e8 + 0x360),"options","report_time",0,0,&local_ec);
      if (local_ec != 0) {
        *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 0x30;
      }
      profile_get_boolean(*(undefined8 *)(local_e8 + 0x360),"options","report_verbose",0,0,&local_ec
                         );
      if (local_ec != 0) {
        DAT_001b7130 = 1;
      }
      profile_get_boolean(*(undefined8 *)(local_e8 + 0x360),"options","no_optimize_extents",0,0,
                          &local_ec);
      if (local_ec != 0) {
        *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 0x10000;
      }
      profile_get_boolean(*(undefined8 *)(local_e8 + 0x360),"options","inode_count_fullmap",0,0,
                          &local_ec);
      if (local_ec != 0) {
        *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 0x20000;
      }
      if (*(long *)(local_e8 + 0x398) == -1) {
        profile_get_integer(*(undefined8 *)(local_e8 + 0x360),"options","readahead_mem_pct",0,
                            0xffffffff,&local_ec);
        uVar8 = uVar8 >> 10;
        if (local_ec < 0x65) {
          *(ulong *)(local_e8 + 0x398) = ((long)(int)local_ec * uVar8) / 100;
        }
        profile_get_integer(*(undefined8 *)(local_e8 + 0x360),"options","readahead_kb",0,0xffffffff,
                            &local_ec);
        if (-1 < (int)local_ec) {
          *(long *)(local_e8 + 0x398) = (long)(int)local_ec;
        }
        if ((uVar8 < *(ulong *)(local_e8 + 0x398)) &&
           (*(ulong *)(local_e8 + 0x398) != 0xffffffffffffffff)) {
          *(ulong *)(local_e8 + 0x398) = uVar8;
        }
      }
      if ((*(uint *)(local_e8 + 0x4c) & 0x2008) == 0x2008) {
        *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) & 0xffffdfff;
      }
      if (bVar3) {
        iVar5 = open(*(char **)(local_e8 + 0x10),0,0);
        if (iVar5 < 0) {
          uVar9 = *(undefined8 *)(local_e8 + 0x10);
          uVar12 = dcgettext(0,"while opening %s for flushing",5);
          piVar13 = __errno_location();
          com_err("open",(long)*piVar13,uVar12,uVar9);
                    /* WARNING: Subroutine does not return */
          fatal_error(local_e8,0);
        }
        lVar14 = ext2fs_sync_device(iVar5,1);
        if (lVar14 != 0) {
          uVar9 = *(undefined8 *)(local_e8 + 0x10);
          uVar12 = dcgettext(0,"while trying to flush %s",5);
          com_err("ext2fs_sync_device",lVar14,uVar12,uVar9);
                    /* WARNING: Subroutine does not return */
          fatal_error(local_e8,0);
        }
        close(iVar5);
      }
      if (DAT_001b7138 == 0) {
        p_Var17 = &local_d8.sa_mask;
        for (lVar14 = 0x24; lVar14 != 0; lVar14 = lVar14 + -1) {
          *(undefined4 *)p_Var17->__val = 0;
          p_Var17 = (__sigset_t *)((long)p_Var17 + ((ulong)bVar20 * -2 + 1) * 4);
        }
        local_d8.__sigaction_handler.sa_handler = FUN_00118270;
        sigaction(2,&local_d8,(sigaction *)0x0);
        sigaction(0xf,&local_d8,(sigaction *)0x0);
        local_d8.sa_flags = 0x10000000;
        local_d8.__sigaction_handler.sa_handler = FUN_00118250;
        sigaction(10,&local_d8,(sigaction *)0x0);
        local_d8.__sigaction_handler.sa_handler = FUN_0011b260;
        sigaction(0xc,&local_d8,(sigaction *)0x0);
        goto LAB_0011a36e;
      }
      if (DAT_001b7120 != (void *)0x0) goto LAB_0011b156;
      p_Var17 = &local_d8.sa_mask;
      for (lVar14 = 0x24; lVar14 != 0; lVar14 = lVar14 + -1) {
        *(undefined4 *)p_Var17->__val = 0;
        p_Var17 = (__sigset_t *)((long)p_Var17 + ((ulong)bVar20 * -2 + 1) * 4);
      }
      local_d8.__sigaction_handler.sa_handler = FUN_00118270;
      sigaction(2,&local_d8,(sigaction *)0x0);
      sigaction(0xf,&local_d8,(sigaction *)0x0);
      local_d8.sa_flags = 0x10000000;
      local_d8.__sigaction_handler.sa_handler = FUN_00118250;
      sigaction(10,&local_d8,(sigaction *)0x0);
      local_d8.__sigaction_handler.sa_handler = FUN_0011b260;
      sigaction(0xc,&local_d8,(sigaction *)0x0);
      pcVar7 = getenv("PATH");
      if (pcVar7 == (char *)0x0) goto LAB_0011b024;
      sVar11 = strlen(pcVar7);
      __dest = malloc((long)((int)sVar11 + 0xc));
      if (__dest == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
        fatal_error(local_e8,"Couldn\'t malloc() newpath");
      }
      pcVar15 = "PATH=/sbin";
      pcVar18 = __dest;
      for (lVar14 = 0xb; lVar14 != 0; lVar14 = lVar14 + -1) {
        *pcVar18 = *pcVar15;
        pcVar15 = pcVar15 + (ulong)bVar20 * -2 + 1;
        pcVar18 = pcVar18 + (ulong)bVar20 * -2 + 1;
      }
      strcat(__dest,":");
      strcat(__dest,pcVar7);
      goto LAB_0011ac59;
    }
  }
LAB_0011a36e:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
switchD_0011a4ed_caseD_47:
  FUN_00119bb0(local_e8);
LAB_0011b024:
  __dest = malloc(0xc);
  if (__dest == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fatal_error(local_e8,"Couldn\'t malloc() newpath");
  }
  pcVar7 = "PATH=/sbin";
  pcVar15 = __dest;
  for (lVar14 = 0xb; lVar14 != 0; lVar14 = lVar14 + -1) {
    *pcVar15 = *pcVar7;
    pcVar7 = pcVar7 + (ulong)bVar20 * -2 + 1;
    pcVar15 = pcVar15 + (ulong)bVar20 * -2 + 1;
  }
LAB_0011ac59:
  putenv(__dest);
  goto LAB_0011a36e;
code_r0x0011a4e6:
  switch(local_ec) {
  case 0x42:
    iVar5 = atoi(optarg);
    *(int *)(local_e8 + 0x50) = iVar5;
    goto switchD_0011a4ed_caseD_72;
  case 0x43:
    *(code **)(local_e8 + 0x160) = FUN_0011b500;
    iVar5 = __isoc99_sscanf(pcVar7,&DAT_0017adb6,local_e8 + 0x2c8);
    if (iVar5 == 1) {
      iVar5 = *(int *)(local_e8 + 0x2c8);
      if (iVar5 < 0) {
        *(undefined8 *)(local_e8 + 0x160) = 0;
        iVar5 = -iVar5;
        *(int *)(local_e8 + 0x2c8) = iVar5;
      }
      else if (iVar5 == 0) goto switchD_0011a4ed_caseD_72;
      iVar5 = dup(iVar5);
      if (iVar5 < 0) {
        piVar13 = __errno_location();
        uVar9 = error_message((long)*piVar13);
        uVar2 = *(undefined4 *)(local_e8 + 0x2c8);
        uVar12 = dcgettext(0,"Error validating file descriptor %d: %s\n",5);
        __fprintf_chk(stderr,1,uVar12,uVar2,uVar9);
        uVar9 = dcgettext(0,"Invalid completion information file descriptor",5);
                    /* WARNING: Subroutine does not return */
        fatal_error(local_e8,uVar9);
      }
      close(iVar5);
      goto switchD_0011a4ed_caseD_72;
    }
    goto LAB_0011a686;
  case 0x44:
    *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 0x400;
    goto switchD_0011a4ed_caseD_72;
  case 0x45:
    local_118 = optarg;
    goto switchD_0011a4ed_caseD_72;
  case 0x46:
    bVar3 = true;
    goto switchD_0011a4ed_caseD_72;
  default:
    goto switchD_0011a4ed_caseD_47;
  case 0x49:
    lVar14 = local_e8 + 0x25c;
    goto LAB_0011a66c;
  case 0x4c:
    DAT_001b712c = DAT_001b712c + 1;
  case 0x6c:
    if (DAT_001b7120 != (void *)0x0) {
      free(DAT_001b7120);
    }
    DAT_001b7120 = (void *)string_copy(local_e8,optarg,0);
    goto switchD_0011a4ed_caseD_72;
  case 0x4e:
    uVar9 = string_copy(local_e8,optarg,0);
    *(undefined8 *)(lVar14 + 0x18) = uVar9;
    goto switchD_0011a4ed_caseD_72;
  case 0x50:
    lVar14 = local_e8 + 600;
LAB_0011a66c:
    iVar5 = __isoc99_sscanf(optarg,&DAT_0017adb6,lVar14);
    if (iVar5 == 1) goto switchD_0011a4ed_caseD_72;
LAB_0011a686:
    uVar1 = local_ec;
    pcVar7 = optarg;
    uVar9 = dcgettext(0,"\nInvalid non-numeric argument to -%c (\"%s\")\n\n",5);
    __fprintf_chk(stderr,1,uVar9,uVar1,pcVar7);
                    /* WARNING: Subroutine does not return */
    exit(1);
  case 0x56:
    DAT_001b7134 = 1;
    goto switchD_0011a4ed_caseD_72;
  case 0x61:
  case 0x70:
    if ((*(byte *)(local_e8 + 0x4c) & 0xc) == 0) {
      *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 2;
      goto switchD_0011a4ed_caseD_72;
    }
    break;
  case 0x62:
    iVar5 = __isoc99_sscanf(optarg,&DAT_00186df0,&local_e0);
    *(undefined8 *)(local_e8 + 0x58) = local_e0;
    if (iVar5 == 1) {
      *(uint *)(local_e8 + 0x48) = *(uint *)(local_e8 + 0x48) | 0x100;
      goto switchD_0011a4ed_caseD_72;
    }
    goto LAB_0011a686;
  case 99:
    iVar5 = DAT_001b7138 + 1;
    bVar19 = DAT_001b7138 != 0;
    DAT_001b7138 = iVar5;
    if (bVar19) {
      *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 0x200;
    }
    *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 0x40;
    goto switchD_0011a4ed_caseD_72;
  case 100:
    *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 0x80;
    goto switchD_0011a4ed_caseD_72;
  case 0x66:
    *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 0x100;
    goto switchD_0011a4ed_caseD_72;
  case 0x6a:
    uVar9 = blkid_get_devname(*(undefined8 *)(local_e8 + 0x88),optarg,0);
    *(undefined8 *)(lVar14 + 0x270) = uVar9;
    pcVar7 = optarg;
    if (*(long *)(local_e8 + 0x270) == 0) {
      uVar9 = dcgettext(0,"Unable to resolve \'%s\'",5);
      com_err(*(undefined8 *)(local_e8 + 8),0,uVar9,pcVar7);
                    /* WARNING: Subroutine does not return */
      fatal_error(local_e8,0);
    }
    goto switchD_0011a4ed_caseD_72;
  case 0x6b:
    DAT_001b7128 = DAT_001b7128 + 1;
    goto switchD_0011a4ed_caseD_72;
  case 0x6e:
    if ((*(uint *)(local_e8 + 0x4c) & 6) == 0) {
      *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 8;
      goto switchD_0011a4ed_caseD_72;
    }
    break;
  case 0x72:
    goto switchD_0011a4ed_caseD_72;
  case 0x74:
    uVar1 = *(uint *)(local_e8 + 0x4c);
    uVar4 = uVar1 | 0x20;
    if ((uVar1 & 0x10) == 0) {
      uVar4 = uVar1 | 0x10;
    }
    *(uint *)(local_e8 + 0x4c) = uVar4;
    goto switchD_0011a4ed_caseD_72;
  case 0x76:
    DAT_001b7130 = 1;
    goto switchD_0011a4ed_caseD_72;
  case 0x79:
    if ((*(uint *)(local_e8 + 0x4c) & 10) == 0) {
      *(uint *)(local_e8 + 0x4c) = *(uint *)(local_e8 + 0x4c) | 4;
      goto switchD_0011a4ed_caseD_72;
    }
    break;
  case 0x7a:
    *(char **)(local_e8 + 0x3a8) = optarg;
    goto switchD_0011a4ed_caseD_72;
  }
  uVar9 = dcgettext(0,"Only one of the options -p/-a, -n or -y may be specified.",5);
                    /* WARNING: Subroutine does not return */
  fatal_error(local_e8,uVar9);
}



// Function: e2fsck_clear_progbar @ 0x1b210

void e2fsck_clear_progbar(long param_1)

{
  if ((*(byte *)(param_1 + 0x48) & 0x20) == 0) {
    return;
  }
  __printf_chk(1,&DAT_00178902,param_1 + 0x2dc,&DAT_001b7050,param_1 + 0x2de);
  fflush(stdout);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xffffffdf;
  return;
}



// Function: signal_progress_off @ 0x1b260

void signal_progress_off(void)

{
  long lVar1;
  
  lVar1 = e2fsck_global_ctx;
  if (e2fsck_global_ctx != 0) {
    e2fsck_clear_progbar(e2fsck_global_ctx);
    *(undefined8 *)(lVar1 + 0x160) = 0;
  }
  return;
}



// Function: e2fsck_simple_progress @ 0x1b290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 e2fsck_simple_progress(float param_1,long param_2,char *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  long in_FS_OFFSET;
  timeval local_48;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (((*(byte *)(param_2 + 0x48) & 0x40) == 0) &&
     (iVar5 = (int)((double)(param_1 * _DAT_00178ce4) + _DAT_00178cd8),
     *(int *)(param_2 + 0x2d0) != iVar5)) {
    *(int *)(param_2 + 0x2d0) = iVar5;
    gettimeofday(&local_48,(__timezone_ptr_t)0x0);
    iVar1 = (int)(local_48.tv_usec / 0x1e848) + (int)local_48.tv_sec * 8;
    if ((*(int *)(param_2 + 0x2d4) != iVar1) || ((iVar5 == 0 || (iVar5 == 1000)))) {
      *(int *)(param_2 + 0x2d4) = iVar1;
      *(uint *)(param_2 + 0x48) = *(uint *)(param_2 + 0x48) | 0x20;
      *(uint *)(param_2 + 0x2cc) = *(int *)(param_2 + 0x2cc) + 1U & 3;
      sVar3 = strlen(param_3);
      uVar4 = -(int)sVar3 + 0x42;
      uVar2 = -(int)sVar3 + 0x49;
      if (-1 < (int)uVar4) {
        uVar2 = uVar4;
      }
      uVar4 = uVar2 & 0xfffffff8;
      if (param_4 != 0) {
        uVar4 = (uVar2 & 0xfffffff8) - 8;
      }
      iVar1 = (int)(((float)(int)uVar4 * param_1 + _DAT_00178ce8) / DAT_00178ce0);
      __printf_chk(1,"%s%s: |%s%s",param_2 + 0x2dc,param_3,(long)&DAT_001b7120 - (long)(iVar1 + 1),
                   (long)&DAT_001b70a0 - (long)(int)((uVar4 - iVar1) + 1));
      if (iVar5 == 1000) {
        fputc(0x7c,stdout);
      }
      else {
        fputc((int)(char)(&DAT_00178cc8)[*(uint *)(param_2 + 0x2cc) & 3],stdout);
      }
      __printf_chk((double)param_1,1,&DAT_00178916);
      if (param_4 == 0) {
        fputs(" \r",stdout);
      }
      else {
        __printf_chk(1,&DAT_00178921,param_4);
      }
      fputs((char *)(param_2 + 0x2de),stdout);
      if (iVar5 == 1000) {
        e2fsck_clear_progbar(param_2);
      }
      fflush(stdout);
    }
  }
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// Function: e2fsck_update_progress @ 0x1b500

undefined8 e2fsck_update_progress(long param_1,int param_2,undefined8 param_3,ulong param_4)

{
  size_t sVar1;
  long in_FS_OFFSET;
  char acStack_428 [1032];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 != 0) {
    if (*(int *)(param_1 + 0x2c8) == 0) {
      FUN_0011b190(param_2,param_3,param_4 & 0xffffffff);
      e2fsck_simple_progress(param_1,*(undefined8 *)(param_1 + 0x18),0);
    }
    else {
      __snprintf_chk(acStack_428,0x400,1,0x400,"%d %lu %lu %s\n",param_2,param_3,param_4,
                     *(undefined8 *)(param_1 + 0x18));
      sVar1 = strlen(acStack_428);
      write_all(*(undefined4 *)(param_1 + 0x2c8),acStack_428,sVar1);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_allocate_context @ 0x1b5c0

long e2fsck_allocate_context(undefined8 *param_1)

{
  long lVar1;
  long lVar2;
  char *__nptr;
  ulonglong uVar3;
  time_t tVar4;
  ulong uVar5;
  undefined8 *puVar6;
  long in_FS_OFFSET;
  byte bVar7;
  undefined8 *local_28;
  
  bVar7 = 0;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = ext2fs_get_mem(0x3f8);
  if (lVar2 == 0) {
    *local_28 = 0;
    local_28[0x7e] = 0;
    puVar6 = (undefined8 *)((ulong)(local_28 + 1) & 0xfffffffffffffff8);
    for (uVar5 = (ulong)(((int)local_28 -
                         (int)(undefined8 *)((ulong)(local_28 + 1) & 0xfffffffffffffff8)) + 0x3f8U
                        >> 3); uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + (ulong)bVar7 * -2 + 1;
    }
    *(undefined4 *)(local_28 + 0x4b) = 0x100;
    *(undefined4 *)(local_28 + 0x6b) = 2;
    *(undefined4 *)(local_28 + 0x6d) = 1;
    *(undefined4 *)(local_28 + 0x4c) = 0xff;
    __nptr = getenv("E2FSCK_TIME");
    if (__nptr == (char *)0x0) {
      tVar4 = time((time_t *)0x0);
      local_28[0x69] = tVar4;
      if ((long)local_28[0x69] < 0x4b3d8150) {
        *(uint *)(local_28 + 9) = *(uint *)(local_28 + 9) | 0x2000;
      }
    }
    else {
      uVar3 = strtoull(__nptr,(char **)0x0,0);
      local_28[0x69] = uVar3;
    }
    *param_1 = local_28;
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_reset_context @ 0x1b6e0

undefined8 e2fsck_reset_context(long *param_1)

{
  long lVar1;
  long lVar2;
  
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) & 0x6000;
  param_1[0x45] = 0;
  if (param_1[0x2d] != 0) {
    ext2fs_free_inode_bitmap();
    param_1[0x2d] = 0;
  }
  if (param_1[0x2f] != 0) {
    ext2fs_free_inode_bitmap();
    param_1[0x2f] = 0;
  }
  if (param_1[0x32] != 0) {
    ext2fs_free_inode_bitmap();
    param_1[0x32] = 0;
  }
  if (param_1[0x34] != 0) {
    ext2fs_free_block_bitmap();
    param_1[0x34] = 0;
  }
  if (param_1[0x33] != 0) {
    ext2fs_free_block_bitmap();
    param_1[0x33] = 0;
  }
  if (param_1[0x38] != 0) {
    ext2fs_free_icount();
    param_1[0x38] = 0;
  }
  lVar1 = param_1[0x4d];
  lVar2 = *param_1;
  if (lVar1 != 0) {
    if (lVar2 == 0) {
      param_1[0x4d] = 0;
      goto LAB_0011b7f9;
    }
    if (lVar1 != *(long *)(lVar2 + 8)) {
      (**(code **)(*(long *)(lVar1 + 8) + 0x18))();
      lVar2 = *param_1;
    }
    param_1[0x4d] = 0;
  }
  if ((lVar2 != 0) && (*(long *)(lVar2 + 0x90) != 0)) {
    ext2fs_free_dblist();
    *(undefined8 *)(*param_1 + 0x90) = 0;
  }
LAB_0011b7f9:
  e2fsck_free_dir_info(param_1);
  e2fsck_free_dx_dir_info(param_1);
  if (param_1[0x39] != 0) {
    ea_refcount_free();
    param_1[0x39] = 0;
  }
  if (param_1[0x3a] != 0) {
    ea_refcount_free();
    param_1[0x3a] = 0;
  }
  if (param_1[0x3b] != 0) {
    ea_refcount_free();
    param_1[0x3b] = 0;
  }
  if (param_1[0x3c] != 0) {
    ea_refcount_free();
    param_1[0x3c] = 0;
  }
  if (param_1[0x3d] != 0) {
    ea_refcount_free();
    param_1[0x3d] = 0;
  }
  if (param_1[0x35] != 0) {
    ext2fs_free_block_bitmap();
    param_1[0x35] = 0;
  }
  if (param_1[0x36] != 0) {
    ext2fs_free_block_bitmap();
    param_1[0x36] = 0;
  }
  if (param_1[0x72] != 0) {
    ext2fs_free_block_bitmap();
    param_1[0x72] = 0;
  }
  if (param_1[0x30] != 0) {
    ext2fs_free_inode_bitmap();
    param_1[0x30] = 0;
  }
  if (param_1[0x2e] != 0) {
    ext2fs_free_inode_bitmap();
    param_1[0x2e] = 0;
  }
  if (param_1[0x31] != 0) {
    ext2fs_free_inode_bitmap();
    param_1[0x31] = 0;
  }
  if (param_1[0x49] != 0) {
    ext2fs_u32_list_free();
    param_1[0x49] = 0;
  }
  destroy_encrypted_file_info(param_1);
  if (param_1[0x3e] != 0) {
    ext2fs_free_mem(param_1 + 0x3e);
    param_1[0x3e] = 0;
  }
  if (param_1[0x3f] != 0) {
    ext2fs_free_mem(param_1 + 0x3f);
    param_1[0x3f] = 0;
  }
  if (param_1[0x40] != 0) {
    ext2fs_free_mem(param_1 + 0x40);
    param_1[0x40] = 0;
  }
  if (param_1[0x6e] != 0) {
    ext2fs_u32_list_free();
    param_1[0x6e] = 0;
  }
  if (param_1[0x37] != 0) {
    ext2fs_free_icount();
    param_1[0x37] = 0;
  }
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0xc] = param_1[0xb];
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  return 0;
}



// Function: e2fsck_free_context @ 0x1baa0

void e2fsck_free_context(long param_1)

{
  long local_10 [2];
  
  if (param_1 != 0) {
    local_10[0] = param_1;
    e2fsck_reset_context();
    if (*(long *)(local_10[0] + 0x88) != 0) {
      blkid_put_cache(*(long *)(local_10[0] + 0x88));
    }
    if (*(long *)(local_10[0] + 0x360) != 0) {
      profile_release(*(long *)(local_10[0] + 0x360));
    }
    if (*(long *)(local_10[0] + 0x10) != 0) {
      ext2fs_free_mem(local_10[0] + 0x10);
    }
    if (*(long *)(local_10[0] + 0x18) != 0) {
      ext2fs_free_mem(local_10[0] + 0x18);
    }
    if (*(void **)(local_10[0] + 0x30) != (void *)0x0) {
      free(*(void **)(local_10[0] + 0x30));
    }
    if (*(FILE **)(local_10[0] + 0x28) != (FILE *)0x0) {
      fclose(*(FILE **)(local_10[0] + 0x28));
    }
    if (*(void **)(local_10[0] + 0x40) != (void *)0x0) {
      free(*(void **)(local_10[0] + 0x40));
    }
    if (*(FILE **)(local_10[0] + 0x38) != (FILE *)0x0) {
      fputs("</problem_log>\n",*(FILE **)(local_10[0] + 0x38));
      fclose(*(FILE **)(local_10[0] + 0x38));
    }
    ext2fs_free_mem(local_10);
  }
  return;
}



// Function: e2fsck_run @ 0x1bb90

uint e2fsck_run(undefined8 *param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  undefined **ppuVar5;
  uint uVar6;
  
  iVar1 = _setjmp((__jmp_buf_tag *)(param_1 + 0x12));
  uVar2 = *(uint *)(param_1 + 9);
  if (iVar1 == 0) {
    uVar2 = uVar2 | 0x10;
    pcVar4 = e2fsck_pass1;
    ppuVar5 = &PTR_e2fsck_pass1e_001b1808;
    *(uint *)(param_1 + 9) = uVar2;
    do {
      uVar6 = uVar2 & 7;
      if (uVar6 != 0) goto LAB_0011bc54;
      lVar3 = e2fsck_mmp_update(*param_1);
      if (lVar3 != 0) {
                    /* WARNING: Subroutine does not return */
        fatal_error(param_1,0);
      }
      (*pcVar4)(param_1);
      if ((code *)param_1[0x2c] != (code *)0x0) {
        (*(code *)param_1[0x2c])(param_1,0,0,0);
      }
      pcVar4 = (code *)*ppuVar5;
      ppuVar5 = ppuVar5 + 1;
      uVar2 = *(uint *)(param_1 + 9);
    } while (pcVar4 != (code *)0x0);
    uVar6 = uVar2 & 7;
  }
  else {
    uVar6 = uVar2 & 7;
  }
LAB_0011bc54:
  *(uint *)(param_1 + 9) = uVar2 & 0xffffffef;
  return uVar6;
}



// Function: check_super_value @ 0x1bd20

undefined8
check_super_value(long param_1,undefined8 param_2,ulong param_3,ulong param_4,ulong param_5,ulong param_6
            )

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  undefined1 auStack_98 [80];
  ulong local_48;
  undefined8 local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (((param_5 <= param_3) || ((param_4 & 1) == 0)) &&
     (((param_4 & 2) == 0 || (param_3 <= param_6)))) {
    uVar1 = 1;
    if (((param_4 & 4) == 0) || ((param_3 - 1 & param_3) == 0)) goto LAB_0011bd61;
  }
  clear_problem_context(auStack_98);
  local_48 = param_3;
  local_38 = param_2;
  fix_problem(param_1,0xb,auStack_98);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1;
  uVar1 = 0;
LAB_0011bd61:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: release_inode_blocks @ 0x1bdc0

undefined4
release_inode_blocks(long *param_1,undefined4 param_2,long param_3,long param_4,undefined8 param_5)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined4 uVar6;
  long in_FS_OFFSET;
  bool bVar7;
  int local_8c;
  long *local_88;
  long local_80;
  undefined8 local_78;
  uint local_70;
  uint local_6c;
  ulong local_68;
  int local_60;
  int local_5c;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  long local_40;
  
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar3 = FUN_0011bc80(param_3);
  iVar2 = ext2fs_inode_has_valid_blocks2(lVar1,uVar3);
  if (iVar2 != 0) {
    local_5c = 0;
    local_58 = 0;
    local_50 = 0;
    local_80 = (ulong)(uint)(*(int *)(*param_1 + 0x28) * 3) + param_4;
    bVar7 = *(short *)(param_3 + 0x1a) != 0;
    if (bVar7) {
      local_6c = *(uint *)(lVar1 + 0x28);
      local_68 = (((ulong)local_6c - 1) +
                 CONCAT44(*(undefined4 *)(param_3 + 0x6c),*(uint *)(param_3 + 4))) / (ulong)local_6c
      ;
      local_6c = *(uint *)(param_3 + 4) % local_6c;
    }
    else {
      local_68 = 0;
      local_6c = 0;
    }
    local_70 = (uint)bVar7;
    local_60 = 0;
    local_88 = param_1;
    local_78 = param_5;
    local_48 = param_3;
    lVar4 = ext2fs_block_iterate3(lVar1,param_2,2,param_4,FUN_0011c0a0,&local_88);
    if (lVar4 != 0) {
      uVar3 = dcgettext(0,"while calling ext2fs_block_iterate for inode %u",5);
      uVar6 = 1;
      com_err("release_inode_blocks",lVar4,uVar3,param_2);
      goto LAB_0011bee4;
    }
    if (local_5c != 0) {
      uVar6 = 1;
      goto LAB_0011bee4;
    }
    e2fsck_read_inode_full(param_1,param_2,uVar3,0xa0,"release_inode_blocks");
    if (local_60 != 0) {
      ext2fs_iblk_sub_blocks(lVar1,uVar3);
    }
    lVar4 = ext2fs_file_acl_block(lVar1,uVar3);
    if (lVar4 != 0) {
      lVar5 = ext2fs_adjust_ea_refcount3(lVar1,lVar4,param_4,0xffffffff,&local_8c,param_2);
      if (lVar5 == 0x7f2bb75a) {
        local_8c = 1;
      }
      else {
        if (lVar5 != 0) {
          uVar6 = 1;
          uVar3 = dcgettext(0,"while calling ext2fs_adjust_ea_refcount2 for inode %u",5);
          com_err("release_inode_blocks",lVar5,uVar3,param_2);
          goto LAB_0011bee4;
        }
        if (local_8c == 0) {
          if (param_1[0x4f] != 0) {
            quota_data_sub(param_1[0x4f],param_3,0,*(undefined4 *)(*param_1 + 0x28));
          }
          ext2fs_block_alloc_stats2(lVar1,lVar4,0xffffffff);
          param_1[0xe] = param_1[0xe] + 1;
        }
      }
      ext2fs_file_acl_block_set(lVar1,uVar3,0);
      uVar6 = 0;
      goto LAB_0011bee4;
    }
  }
  uVar6 = 0;
LAB_0011bee4:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: release_inode_block @ 0x1c0a0

undefined4
release_inode_block(long param_1,ulong *param_2,long param_3,undefined8 param_4,undefined8 param_5,
            long *param_6)

{
  int *piVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  int iVar5;
  ulong uVar6;
  int *piVar7;
  long lVar8;
  uint uVar9;
  undefined4 uVar10;
  
  uVar2 = *param_2;
  lVar8 = param_6[2];
  uVar10 = *(undefined4 *)(param_1 + 0xc0);
  plVar3 = (long *)*param_6;
  *(ulong *)(lVar8 + 0x28) = uVar2;
  *(long *)(lVar8 + 0x38) = param_3;
  if ((uVar2 == 0) || (uVar6 = uVar2 >> ((byte)uVar10 & 0x3f), param_6[7] == uVar6)) {
    return 0;
  }
  lVar4 = *(long *)(param_1 + 0x20);
  param_6[7] = uVar6;
  if ((uVar2 < *(uint *)(lVar4 + 0x14)) || (uVar6 = ext2fs_blocks_count(), uVar6 <= uVar2)) {
    fix_problem(plVar3,0x21,lVar8);
  }
  else {
    iVar5 = ext2fs_test_block_bitmap2(*(undefined8 *)(param_1 + 0x58),uVar2);
    if (iVar5 != 0) {
      uVar10 = 0;
      if ((int)param_6[3] != 0) {
        if (param_3 < 0) {
          lVar8 = io_channel_read_blk64(*(undefined8 *)(param_1 + 8),uVar2,1,param_6[1]);
          param_6[6] = lVar8;
          if (lVar8 != 0) goto LAB_0011c248;
          piVar7 = (int *)param_6[1];
          uVar9 = *(uint *)(param_1 + 0x28) >> 2;
          if (uVar9 != 0) {
            piVar1 = piVar7 + uVar9;
            do {
              if (*piVar7 != 0) {
                return 0;
              }
              piVar7 = piVar7 + 1;
            } while (piVar7 != piVar1);
          }
          lVar8 = param_6[4];
        }
        else {
          lVar8 = param_6[4];
          if (param_3 < lVar8) {
            return 0;
          }
        }
        if ((param_3 == lVar8) && (*(int *)((long)param_6 + 0x1c) != 0)) {
          lVar8 = io_channel_read_blk64(*(undefined8 *)(param_1 + 8),uVar2,1,param_6[1]);
          param_6[6] = lVar8;
          if (lVar8 != 0) goto LAB_0011c248;
          memset((void *)((long)*(int *)((long)param_6 + 0x1c) + param_6[1]),0,
                 (ulong)(uint)(*(int *)(param_1 + 0x28) - *(int *)((long)param_6 + 0x1c)));
          lVar8 = io_channel_write_blk64(*(undefined8 *)(param_1 + 8),uVar2,1,param_6[1]);
          param_6[6] = lVar8;
          if (lVar8 != 0) goto LAB_0011c248;
        }
        *(int *)(param_6 + 5) = (int)param_6[5] + 1;
        uVar10 = 1;
        *param_2 = 0;
      }
      if (plVar3[0x4f] != 0) {
        quota_data_sub(plVar3[0x4f],param_6[8],0,*(undefined4 *)(*plVar3 + 0x28));
      }
      ext2fs_block_alloc_stats2(param_1,uVar2,0xffffffff);
      plVar3[0xe] = plVar3[0xe] + 1;
      return uVar10;
    }
    fix_problem(plVar3,0x22,lVar8);
  }
LAB_0011c248:
  *(undefined4 *)((long)param_6 + 0x2c) = 1;
  return 2;
}



// Function: e2fsck_write_all_quotas @ 0x1c380

long e2fsck_write_all_quotas(long *param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long in_FS_OFFSET;
  long local_98 [10];
  long local_48;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_0011c370(*(undefined4 *)(*(long *)(*param_1 + 0x20) + 100));
  lVar2 = 0;
  if (iVar1 != 0) {
    lVar3 = 0;
    clear_problem_context(local_98);
    lVar2 = local_98[0];
    do {
      local_98[0] = lVar2;
      local_48 = lVar3;
      local_98[0] = quota_write_inode(param_1[0x4f],1 << ((byte)lVar3 & 0x1f));
      if (local_98[0] != 0) {
        fix_problem(param_1,0x60006,local_98);
        break;
      }
      lVar3 = lVar3 + 1;
      lVar2 = 0;
    } while (lVar3 != 3);
    quota_release_context(param_1 + 0x4f);
    lVar2 = local_98[0];
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_read_all_quotas @ 0x1c440

long e2fsck_read_all_quotas(long *param_1)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  
  iVar1 = FUN_0011c370(*(undefined4 *)(*(long *)(*param_1 + 0x20) + 100));
  if (iVar1 != 0) {
    lVar2 = quota_init_context(param_1 + 0x4f);
    if (lVar2 != 0) {
      return lVar2;
    }
    iVar1 = 0;
    do {
      piVar3 = (int *)FUN_0011bcf0(*(undefined8 *)(*param_1 + 0x20),iVar1);
      if ((*piVar3 != 0) &&
         (lVar2 = quota_read_all_dquots(param_1[0x4f],*piVar3,iVar1,3), lVar2 != 0)) {
        quota_release_context(param_1 + 0x4f);
        return lVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 3);
  }
  return 0;
}



// Function: release_orphan_inodes @ 0x1c4e0

bool release_orphan_inodes(long *param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  long in_FS_OFFSET;
  bool bVar8;
  undefined8 local_160;
  long local_158;
  uint local_150;
  undefined8 local_140;
  undefined8 local_f8;
  ushort local_e8 [10];
  uint local_d4;
  short local_ce;
  long local_40;
  
  lVar5 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar7 = *(uint *)(*(long *)(lVar5 + 0x20) + 0xe8);
  if (uVar7 != 0) {
    clear_problem_context(&local_158);
    local_158 = FUN_0011c440(param_1);
    if (local_158 != 0) {
      fix_problem(param_1,0x4c,&local_158);
      bVar8 = true;
      goto LAB_0011c519;
    }
    puVar1 = *(uint **)(lVar5 + 0x20);
    puVar1[0x3a] = 0;
    ext2fs_mark_super_dirty(lVar5);
    if ((*(byte *)((long)puVar1 + 0x3a) & 2) == 0) {
      uVar2 = 0xb;
      if (puVar1[0x13] != 0) {
        uVar2 = puVar1[0x15];
      }
      if ((uVar7 < uVar2) || (*puVar1 < uVar7)) {
        clear_problem_context(&local_158);
        local_150 = uVar7;
        fix_problem(param_1,0x23,&local_158);
LAB_0011c76d:
        bVar8 = true;
        if (param_1[0x4f] != 0) {
          quota_release_context(param_1 + 0x4f);
          bVar8 = true;
        }
      }
      else {
        local_160 = e2fsck_allocate_memory
                              (param_1,*(int *)(lVar5 + 0x28) * 4,"block iterate buffer");
        e2fsck_read_bitmaps(param_1);
        uVar4 = FUN_0011bc80(local_e8);
        do {
          e2fsck_read_inode_full(param_1,uVar7,uVar4,0xa0,"release_orphan_inodes");
          clear_problem_context(&local_158);
          local_150 = uVar7;
          local_140 = uVar4;
          if (local_ce == 0) {
            local_f8 = dcgettext(0,"Clearing",5);
          }
          else {
            local_f8 = dcgettext(0,"Truncating",5);
          }
          fix_problem(param_1,0x20,&local_158);
          uVar2 = local_d4;
          if (local_d4 != 0) {
            puVar1 = *(uint **)(lVar5 + 0x20);
            uVar6 = 0xb;
            if (puVar1[0x13] != 0) {
              uVar6 = puVar1[0x15];
            }
            if ((uVar6 <= local_d4) && (local_d4 <= *puVar1)) goto LAB_0011c64c;
            local_150 = local_d4;
            fix_problem(param_1,0x24,&local_158);
LAB_0011c7f4:
            ext2fs_free_mem(&local_160);
            goto LAB_0011c76d;
          }
LAB_0011c64c:
          iVar3 = FUN_0011bdc0(param_1,uVar7,local_e8,local_160,&local_158);
          if (iVar3 != 0) goto LAB_0011c7f4;
          uVar6 = 0;
          if (local_ce == 0) {
            if (param_1[0x4f] != 0) {
              quota_data_inodes(param_1[0x4f],local_e8,uVar7,0xffffffff);
            }
            ext2fs_inode_alloc_stats2(lVar5,uVar7,0xffffffff,(local_e8[0] & 0xf000) == 0x4000);
            *(int *)(param_1 + 0xf) = (int)param_1[0xf] + 1;
            uVar6 = *(uint *)(param_1 + 0x69);
          }
          local_d4 = uVar6;
          e2fsck_write_inode_full(param_1,uVar7,uVar4,0xa0,"delete_file");
          uVar7 = uVar2;
        } while (uVar2 != 0);
        ext2fs_free_mem(&local_160);
        lVar5 = FUN_0011c380(param_1);
        bVar8 = lVar5 != 0;
      }
      goto LAB_0011c519;
    }
    if (param_1[0x4f] != 0) {
      quota_release_context(param_1 + 0x4f);
    }
  }
  bVar8 = false;
LAB_0011c519:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar8;
}



// Function: e2fsck_fix_dirhash_hint @ 0x1c880

void e2fsck_fix_dirhash_hint(long *param_1)

{
  long lVar1;
  int iVar2;
  long in_FS_OFFSET;
  undefined1 auStack_88 [104];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = *(long *)(*param_1 + 0x20);
  if ((((*(byte *)((long)param_1 + 0x4c) & 1) == 0) &&
      (iVar2 = FUN_0011c870(*(undefined4 *)(lVar1 + 0x5c)), iVar2 != 0)) &&
     ((*(byte *)(lVar1 + 0x160) & 3) == 0)) {
    clear_problem_context(auStack_88);
    iVar2 = fix_problem(param_1,0x34,auStack_88);
    if (iVar2 != 0) {
      *(uint *)(lVar1 + 0x160) = *(uint *)(lVar1 + 0x160) | 1;
      ext2fs_mark_super_dirty(*param_1);
    }
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: check_resize_inode @ 0x1c930

void check_resize_inode(long *param_1)

{
  ushort *puVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  int *piVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  long extraout_RDX;
  long extraout_RDX_00;
  int iVar11;
  short *psVar12;
  undefined2 uVar13;
  uint uVar14;
  long in_FS_OFFSET;
  byte bVar15;
  int local_150;
  long local_140;
  undefined1 local_138 [8];
  undefined4 local_130;
  ulong local_e8;
  short local_c8 [13];
  short local_ae;
  int local_a0 [15];
  int local_64 [9];
  long local_40;
  
  bVar15 = 0;
  lVar10 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_140 = 0;
  clear_problem_context(local_138);
  iVar4 = FUN_0011c920(*(undefined4 *)(*(long *)(lVar10 + 0x20) + 0x5c));
  lVar5 = extraout_RDX;
  if (iVar4 == 0) {
LAB_0011cb50:
    if ((*(ushort *)(lVar5 + 0xce) != 0) &&
       (local_e8 = (ulong)*(ushort *)(lVar5 + 0xce), iVar4 = fix_problem(param_1,0x2e,local_138),
       iVar4 != 0)) {
      *(undefined2 *)(*(long *)(lVar10 + 0x20) + 0xce) = 0;
      ext2fs_mark_super_dirty(lVar10);
    }
  }
  else {
    iVar4 = FUN_0011c340(*(undefined4 *)(extraout_RDX + 0x60));
    if (iVar4 != 0) {
      iVar4 = fix_problem(param_1,0x51,local_138);
      if (iVar4 != 0) {
        uVar13 = 0;
        lVar5 = FUN_0011bc90(*(undefined8 *)(lVar10 + 0x20));
        *(undefined2 *)(lVar5 + 0xce) = uVar13;
        ext2fs_mark_super_dirty(lVar10);
      }
      iVar4 = FUN_0011c920(*(undefined4 *)(*(long *)(lVar10 + 0x20) + 0x5c));
      lVar5 = extraout_RDX_00;
      if (iVar4 == 0) goto LAB_0011cb50;
    }
  }
  local_130 = 7;
  lVar5 = ext2fs_read_inode(lVar10,7,local_c8);
  if (lVar5 == 0) {
    lVar5 = *(long *)(lVar10 + 0x20);
    iVar4 = FUN_0011c920(*(undefined4 *)(lVar5 + 0x5c));
    if (iVar4 != 0) {
      iVar4 = 1;
      lVar8 = 0;
      do {
        if (lVar8 != 0xd) {
          if (local_a0[lVar8] != 0) {
            bVar3 = (int)lVar8 < 0xf;
            goto LAB_0011ca11;
          }
          if (iVar4 == 0xf) goto code_r0x0011ca0f;
        }
        lVar8 = lVar8 + 1;
        iVar4 = iVar4 + 1;
      } while( true );
    }
    piVar7 = local_a0;
    while (local_a0[0] == 0) {
      piVar7 = piVar7 + 1;
      if (piVar7 == local_64) goto LAB_0011ca86;
      local_a0[0] = *piVar7;
    }
    iVar4 = fix_problem(param_1,0x2f,local_138);
    if (iVar4 != 0) {
      psVar12 = local_c8;
      for (lVar10 = 0x10; lVar10 != 0; lVar10 = lVar10 + -1) {
        psVar12[0] = 0;
        psVar12[1] = 0;
        psVar12[2] = 0;
        psVar12[3] = 0;
        psVar12 = psVar12 + ((ulong)bVar15 * -2 + 1) * 4;
      }
      e2fsck_write_inode(param_1,7,local_c8,"clear_resize");
    }
  }
  else {
    iVar4 = FUN_0011c920(*(undefined4 *)(*(long *)(lVar10 + 0x20) + 0x5c));
    if (iVar4 != 0) {
      *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 0x400;
    }
  }
  goto LAB_0011ca86;
code_r0x0011ca0f:
  bVar3 = false;
LAB_0011ca11:
  if (((((local_a0[0xd] == 0) || (bVar3)) || (local_ae == 0)) ||
      ((-1 < local_c8[0] || ((uint)local_a0[0xd] < *(uint *)(lVar5 + 0x14))))) ||
     (uVar6 = ext2fs_blocks_count(lVar5), uVar6 <= (uint)local_a0[0xd])) {
LAB_0011ca50:
    iVar4 = fix_problem(param_1,0x30,local_138);
    if (iVar4 == 0) {
      bVar15 = *(byte *)((long)param_1 + 0x4c);
    }
    else {
      psVar12 = local_c8;
      for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
        psVar12[0] = 0;
        psVar12[1] = 0;
        psVar12[2] = 0;
        psVar12[3] = 0;
        psVar12 = psVar12 + ((ulong)bVar15 * -2 + 1) * 4;
      }
      e2fsck_write_inode(param_1,7,local_c8,"clear_resize");
      *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 0x400;
      bVar15 = *(byte *)((long)param_1 + 0x4c);
    }
    if ((bVar15 & 1) == 0) {
      puVar1 = (ushort *)(*(long *)(lVar10 + 0x20) + 0x3a);
      *puVar1 = *puVar1 & 0xfffe;
      ext2fs_mark_super_dirty(lVar10);
    }
  }
  else {
    lVar5 = e2fsck_allocate_memory(param_1,*(int *)(lVar10 + 0x28) * 2,"resize dind buffer");
    uVar14 = *(uint *)(lVar10 + 0x28);
    local_140 = lVar5;
    lVar8 = ext2fs_read_ind_block(lVar10,local_a0[0xd],lVar5);
    if (lVar8 != 0) goto LAB_0011ca50;
    iVar11 = *(int *)(*(long *)(lVar10 + 0x20) + 0x14);
    uVar6 = *(ulong *)(lVar10 + 0x38) & 0xffffffff;
    iVar9 = iVar11 + (int)*(ulong *)(lVar10 + 0x38);
    uVar2 = *(uint *)(lVar10 + 0x28);
    iVar4 = iVar9 + 1;
    local_150 = iVar4;
    if ((iVar11 == 0) && (local_150 = iVar9 + 2, uVar2 != 0x400)) {
      local_150 = iVar4;
    }
    if (*(ushort *)(*(long *)(lVar10 + 0x20) + 0xce) >> 2 != 0) {
      lVar5 = (ulong)uVar14 + lVar5;
      iVar4 = local_150;
      while ((uVar6 = uVar6 % (ulong)(uVar2 >> 2), *(int *)(local_140 + uVar6 * 4) == iVar4 &&
             (lVar8 = ext2fs_read_ind_block(lVar10,iVar4,lVar5), lVar8 == 0))) {
        iVar11 = 0;
        uVar14 = 1;
        if (1 < *(uint *)(lVar10 + 0x30)) {
          do {
            iVar9 = ext2fs_bg_has_super(lVar10,uVar14);
            if (iVar9 != 0) {
              if (*(int *)(lVar5 + (long)iVar11 * 4) !=
                  iVar4 + *(int *)(*(long *)(lVar10 + 0x20) + 0x20) * uVar14) goto LAB_0011ca50;
              iVar11 = iVar11 + 1;
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 < *(uint *)(lVar10 + 0x30));
        }
        uVar6 = (ulong)((int)uVar6 + 1);
        if ((int)(uint)(*(ushort *)(*(long *)(lVar10 + 0x20) + 0xce) >> 2) <=
            (1 - local_150) + iVar4) goto LAB_0011ca74;
        iVar4 = iVar4 + 1;
        uVar2 = *(uint *)(lVar10 + 0x28);
      }
      goto LAB_0011ca50;
    }
  }
LAB_0011ca74:
  if (local_140 != 0) {
    ext2fs_free_mem(&local_140);
  }
LAB_0011ca86:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: check_super_block @ 0x1cdb0

void check_super_block(long *param_1)

{
  ushort *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  uint *puVar7;
  undefined2 uVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  long lVar15;
  undefined8 uVar16;
  ulong uVar17;
  uint uVar18;
  ulong extraout_RDX;
  ulong uVar19;
  uint uVar20;
  long in_FS_OFFSET;
  bool bVar21;
  ulong local_e0;
  ulong local_d8;
  byte local_cc;
  long local_c8;
  int local_c0;
  int local_b4;
  int local_b0;
  int local_ac;
  undefined1 local_a8 [8];
  uint local_a0;
  uint local_9c;
  ulong local_80;
  ulong local_78;
  uint local_68;
  uint local_64;
  uint local_60;
  ulong local_58;
  char *local_48;
  long local_40;
  
  lVar6 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_e0._0_4_ = 0x80;
  puVar7 = *(uint **)(lVar6 + 0x20);
  uVar18 = puVar7[8];
  uVar20 = puVar7[6];
  if (puVar7[0x13] != 0) {
    local_e0._0_4_ = (uint)(ushort)puVar7[0x16];
  }
  uVar12 = puVar7[7];
  uVar3 = *(undefined4 *)(lVar6 + 0xc0);
  lVar14 = e2fsck_allocate_memory
                     (param_1,(ulong)*(uint *)(lVar6 + 0x30) << 2,"invalid_inode_bitmap");
  uVar13 = *(uint *)(lVar6 + 0x30);
  param_1[0x3e] = lVar14;
  lVar14 = e2fsck_allocate_memory(param_1,(ulong)uVar13 << 2,"invalid_block_bitmap");
  uVar13 = *(uint *)(lVar6 + 0x30);
  param_1[0x3f] = lVar14;
  lVar15 = e2fsck_allocate_memory(param_1,(ulong)uVar13 << 2,"invalid_inode_table");
  lVar14 = *(long *)(lVar6 + 0x20);
  param_1[0x40] = lVar15;
  uVar4 = *(undefined4 *)(lVar14 + 0x1c);
  uVar5 = *(undefined4 *)(lVar14 + 0x18);
  iVar10 = FUN_0011c320(*(undefined4 *)(lVar14 + 0x60),lVar14,0xffffffff);
  uVar19 = (ulong)(uint)(((0x400 << ((byte)uVar4 & 0x1f)) / (0x400 << ((byte)uVar5 & 0x1f))) *
                        0xfff8) << 0x20;
  uVar17 = 0xffffffffffff;
  if (uVar19 < 0x1000000000000) {
    uVar17 = uVar19;
  }
  if (extraout_RDX < uVar19) {
    uVar19 = extraout_RDX;
  }
  if (iVar10 == 0) {
    uVar17 = uVar19;
  }
  clear_problem_context(local_a8);
  iVar10 = FUN_0011bd20(param_1,"inodes_count",*puVar7,1,1,0);
  if (iVar10 == 0) goto LAB_0011cf0d;
  uVar16 = ext2fs_blocks_count(puVar7);
  iVar10 = FUN_0011bd20(param_1,"blocks_count",uVar16,3,1,uVar17);
  if (iVar10 == 0) goto LAB_0011cf0d;
  uVar16 = ext2fs_blocks_count(puVar7);
  iVar10 = FUN_0011bd20(param_1,"first_data_block",puVar7[5],2,0,uVar16);
  if (((iVar10 == 0) ||
      (iVar10 = FUN_0011bd20(param_1,"log_block_size",puVar7[6],3,0,6), iVar10 == 0)) ||
     (iVar10 = FUN_0011bd20(param_1,"log_cluster_size",puVar7[7],3,puVar7[6],0x13), iVar10 == 0))
  goto LAB_0011cf0d;
  local_cc = (byte)uVar20;
  iVar10 = 0x400 << (local_cc & 0x1f);
  uVar20 = iVar10 * 8;
  uVar13 = 0xfff8;
  if (uVar20 < 0xfff9) {
    uVar13 = uVar20;
  }
  iVar11 = FUN_0011bd20(param_1,"clusters_per_group",puVar7[9],3,8,uVar13);
  if (iVar11 == 0) goto LAB_0011cf0d;
  local_c0._0_1_ = (byte)uVar12;
  local_c8._0_1_ = (byte)uVar3;
  uVar20 = uVar20 << ((byte)local_c8 & 0x1f);
  uVar12 = ((0x400 << ((byte)local_c0 & 0x1f)) / iVar10) * 0xfff8;
  if (uVar20 < uVar12) {
    uVar12 = uVar20;
  }
  iVar11 = FUN_0011bd20(param_1,"blocks_per_group",puVar7[8],3,8,uVar12);
  if (iVar11 == 0) goto LAB_0011cf0d;
  iVar10 = iVar10 / (int)(uint)local_e0;
  uVar18 = (uVar18 - 4) * iVar10;
  if (0x10000U - iVar10 < uVar18) {
    uVar18 = 0x10000U - iVar10;
  }
  iVar10 = FUN_0011bd20(param_1,"inodes_per_group",puVar7[10],3,(long)iVar10,uVar18);
  if (iVar10 == 0) goto LAB_0011cf0d;
  uVar17 = ext2fs_blocks_count(puVar7);
  uVar16 = ext2fs_r_blocks_count(puVar7);
  iVar10 = FUN_0011bd20(param_1,"r_blocks_count",uVar16,2,0,uVar17 >> 1);
  if (((iVar10 == 0) ||
      (iVar10 = FUN_0011bd20(param_1,"reserved_gdt_blocks",*(undefined2 *)((long)puVar7 + 0xce),2,0,
                             *(uint *)(lVar6 + 0x28) >> 2), iVar10 == 0)) ||
     (iVar10 = FUN_0011bd20(param_1,"desc_size",*(undefined2 *)((long)puVar7 + 0xfe),6,0,0x400),
     iVar10 == 0)) goto LAB_0011cf0d;
  uVar17 = (ulong)puVar7[10] * (ulong)*(uint *)(lVar6 + 0x30);
  if (0xffffffff < uVar17) {
    local_58 = uVar17;
    fix_problem(param_1,0x50,local_a8);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
    goto LAB_0011cf0d;
  }
  if (*puVar7 != uVar17) {
    local_a0 = *puVar7;
    local_9c = (uint)uVar17;
    iVar10 = fix_problem(param_1,0xd,local_a8);
    if (iVar10 != 0) {
      *puVar7 = (uint)uVar17;
      ext2fs_mark_super_dirty(lVar6);
      goto LAB_0011d1cd;
    }
    uVar18 = *puVar7;
    local_48 = "inodes_count";
LAB_0011d7b6:
    local_58 = (ulong)uVar18;
    fix_problem(param_1,0xb,local_a8);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
    goto LAB_0011cf0d;
  }
LAB_0011d1cd:
  if (puVar7[0x13] == 0) {
LAB_0011d1d8:
    uVar8 = 0x80;
  }
  else {
    iVar10 = FUN_0011bd20(param_1,"first_ino",puVar7[0x15],3,0xb,*puVar7);
    if (iVar10 == 0) goto LAB_0011cf0d;
    if (puVar7[0x13] == 0) goto LAB_0011d1d8;
    uVar8 = (undefined2)puVar7[0x16];
  }
  iVar10 = FUN_0011bd20(param_1,"inode_size",uVar8,7,0x80,*(undefined4 *)(lVar6 + 0x28));
  if (iVar10 == 0) goto LAB_0011cf0d;
  uVar18 = puVar7[9] << ((byte)*(undefined4 *)(lVar6 + 0xc0) & 0x1f);
  if (puVar7[8] != uVar18) {
    local_48 = "block_size";
    goto LAB_0011d7b6;
  }
  if (((*(byte *)((long)param_1 + 0x49) & 8) == 0) ||
     (uVar17 = param_1[0xd], uVar19 = ext2fs_blocks_count(puVar7), uVar19 <= uVar17)) {
LAB_0011d229:
    uVar17 = 0;
    if (puVar7[6] == 0) {
      uVar17 = (ulong)(*(int *)(lVar6 + 0xc0) == 0);
    }
    if (puVar7[5] == uVar17) {
      if ((puVar7[0x13] != 0) && (0x80 < (ushort)puVar7[0x16])) {
        uVar9 = (ushort)puVar7[0x57];
        local_58 = (ulong)uVar9;
        uVar18 = (ushort)puVar7[0x16] - 0x80;
        if ((uVar9 != 0) &&
           ((((uVar9 < 4 || (uVar18 < uVar9)) || ((uVar9 & 3) != 0)) &&
            (iVar10 = fix_problem(param_1,0x4d,local_a8), iVar10 != 0)))) {
          *(undefined2 *)(puVar7 + 0x57) = 0x20;
          ext2fs_mark_super_dirty(lVar6);
        }
        uVar9 = *(ushort *)((long)puVar7 + 0x15e);
        local_58 = (ulong)uVar9;
        if ((uVar9 != 0) &&
           ((((uVar18 < uVar9 || (uVar9 < 4)) || ((uVar9 & 3) != 0)) &&
            (iVar10 = fix_problem(param_1,0x4e,local_a8), iVar10 != 0)))) {
          *(undefined2 *)((long)puVar7 + 0x15e) = 0x20;
          ext2fs_mark_super_dirty(lVar6);
        }
      }
      lVar14 = *(long *)(lVar6 + 0x20);
      iVar10 = FUN_0011c360(*(undefined4 *)(lVar14 + 100));
      if (iVar10 == 0) {
LAB_0011dd71:
        iVar10 = FUN_0011c300(*(undefined4 *)(lVar14 + 0x60));
        if (iVar10 != 0) {
          iVar10 = fix_problem(param_1,0x4b,local_a8);
          if (iVar10 != 0) {
            lVar14 = FUN_0011bce0(*(undefined8 *)(lVar6 + 0x20));
            *(undefined4 *)(lVar14 + 0x270) = 0;
            ext2fs_mark_super_dirty(lVar6);
          }
          lVar14 = *(long *)(lVar6 + 0x20);
        }
      }
      else {
        iVar10 = FUN_0011c830();
        if (iVar10 != 0) {
          iVar10 = fix_problem(param_1,0x46,local_a8);
          if (iVar10 != 0) {
            FUN_0011bca0(*(undefined8 *)(lVar6 + 0x20));
            ext2fs_mark_super_dirty(lVar6);
            for (uVar18 = 0; uVar18 < *(uint *)(lVar6 + 0x30); uVar18 = uVar18 + 1) {
              ext2fs_group_desc_csum_set(lVar6,uVar18);
            }
          }
          lVar14 = *(long *)(lVar6 + 0x20);
          iVar10 = FUN_0011c360(*(undefined4 *)(lVar14 + 100));
          if (iVar10 == 0) goto LAB_0011dd71;
        }
      }
      iVar10 = FUN_0011c320(*(undefined4 *)(lVar14 + 0x60));
      if ((iVar10 != 0) && (iVar10 = FUN_0011c330(), iVar10 == 0)) {
        iVar10 = fix_problem(param_1,0x48,local_a8);
        if (iVar10 != 0) {
          FUN_0011bcd0(*(undefined8 *)(lVar6 + 0x20));
          ext2fs_mark_super_dirty(lVar6);
        }
        lVar14 = *(long *)(lVar6 + 0x20);
      }
      if ((*(byte *)((long)param_1 + 0x4d) & 0x40) != 0) {
        FUN_0011bcd0(lVar14);
        ext2fs_mark_super_dirty(lVar6);
        lVar14 = *(long *)(lVar6 + 0x20);
      }
      iVar10 = FUN_0011c340(*(undefined4 *)(lVar14 + 0x60));
      if (iVar10 != 0) {
        if (*(ulong *)(lVar6 + 0x38) < (ulong)*(uint *)(lVar14 + 0x104)) {
          local_68 = (uint)*(ulong *)(lVar6 + 0x38);
          local_58 = (ulong)*(uint *)(lVar14 + 0x104);
          iVar10 = fix_problem(param_1,0x49,local_a8);
          if (iVar10 != 0) {
            lVar14 = FUN_0011bcc0(*(undefined8 *)(lVar6 + 0x20));
            *(undefined4 *)(lVar14 + 0x104) = 0;
            ext2fs_mark_super_dirty(lVar6);
          }
        }
      }
      local_e0 = (ulong)puVar7[5];
      lVar14 = ext2fs_blocks_count(puVar7);
      local_d8 = lVar14 - 1;
      iVar10 = FUN_0011c840(*(undefined8 *)(lVar6 + 0x20));
      local_c0 = 0;
      local_c8 = 0;
      uVar17 = 0;
      while (uVar18 = (uint)uVar17, uVar18 < *(uint *)(lVar6 + 0x30)) {
        local_68 = uVar18;
        iVar11 = FUN_0011c310(*(undefined4 *)(*(long *)(lVar6 + 0x20) + 0x60));
        if (iVar11 == 0) {
          local_e0 = ext2fs_group_first_block2(lVar6,uVar17);
          local_d8 = ext2fs_group_last_block2(lVar6,uVar17);
        }
        uVar19 = ext2fs_block_bitmap_loc(lVar6,uVar17);
        if ((uVar19 < local_e0) ||
           (uVar19 = ext2fs_block_bitmap_loc(lVar6,uVar17), local_d8 < uVar19)) {
          local_80 = ext2fs_block_bitmap_loc(lVar6,uVar17);
          iVar11 = fix_problem(param_1,1,local_a8);
          if (iVar11 != 0) {
            ext2fs_block_bitmap_loc_set(lVar6,uVar17,0);
          }
        }
        lVar14 = ext2fs_block_bitmap_loc(lVar6,uVar17);
        if (lVar14 == 0) {
          piVar2 = (int *)(param_1[0x3f] + uVar17 * 4);
          *piVar2 = *piVar2 + 1;
          *(int *)(param_1 + 0x41) = (int)param_1[0x41] + 1;
        }
        uVar19 = ext2fs_inode_bitmap_loc(lVar6,uVar17);
        if ((uVar19 < local_e0) ||
           (uVar19 = ext2fs_inode_bitmap_loc(lVar6,uVar17), local_d8 < uVar19)) {
          local_80 = ext2fs_inode_bitmap_loc(lVar6,uVar17);
          iVar11 = fix_problem(param_1,2,local_a8);
          if (iVar11 != 0) {
            ext2fs_inode_bitmap_loc_set(lVar6,uVar17,0);
          }
        }
        lVar14 = ext2fs_inode_bitmap_loc(lVar6,uVar17);
        if (lVar14 == 0) {
          piVar2 = (int *)(param_1[0x3e] + uVar17 * 4);
          *piVar2 = *piVar2 + 1;
          *(int *)(param_1 + 0x41) = (int)param_1[0x41] + 1;
        }
        uVar19 = ext2fs_inode_table_loc(lVar6,uVar17);
        if ((uVar19 < local_e0) ||
           (lVar14 = ext2fs_inode_table_loc(lVar6,uVar17),
           local_d8 < ((ulong)*(uint *)(lVar6 + 0x48) - 1) + lVar14)) {
          local_80 = ext2fs_inode_table_loc(lVar6,uVar17);
          iVar11 = fix_problem(param_1,3,local_a8);
          if (iVar11 != 0) {
            ext2fs_inode_table_loc_set(lVar6,uVar17,0);
          }
        }
        lVar14 = ext2fs_inode_table_loc(lVar6,uVar17);
        if (lVar14 == 0) {
          piVar2 = (int *)(param_1[0x40] + uVar17 * 4);
          *piVar2 = *piVar2 + 1;
          *(int *)(param_1 + 0x41) = (int)param_1[0x41] + 1;
        }
        uVar20 = ext2fs_bg_free_blocks_count(lVar6,uVar17);
        local_c8 = local_c8 + (ulong)uVar20;
        iVar11 = ext2fs_bg_free_inodes_count(lVar6,uVar17);
        local_c0 = local_c0 + iVar11;
        uVar20 = ext2fs_bg_free_blocks_count(lVar6,uVar17);
        if (((puVar7[8] < uVar20) ||
            (uVar20 = ext2fs_bg_free_inodes_count(lVar6,uVar17), puVar7[10] < uVar20)) ||
           (uVar20 = ext2fs_bg_used_dirs_count(lVar6,uVar17), puVar7[10] < uVar20)) {
          ext2fs_unmark_valid(lVar6);
        }
        bVar21 = false;
        iVar11 = ext2fs_group_desc_csum_verify(lVar6,uVar17);
        if (iVar11 == 0) {
          uVar9 = ext2fs_bg_checksum(lVar6,uVar17);
          local_64 = (uint)uVar9;
          uVar9 = ext2fs_group_desc_csum(lVar6,uVar17);
          local_60 = (uint)uVar9;
          iVar11 = fix_problem(param_1,0x35,local_a8);
          bVar21 = iVar11 != 0;
          if (bVar21) {
            ext2fs_bg_flags_clear(lVar6,uVar17,2);
            ext2fs_bg_flags_clear(lVar6,uVar17,1);
            ext2fs_bg_itable_unused_set(lVar6,uVar17,0);
          }
          ext2fs_unmark_valid(lVar6);
        }
        if (iVar10 == 0) {
          iVar11 = ext2fs_bg_flags_test(lVar6,uVar17,2);
          if (((iVar11 != 0) || (iVar11 = ext2fs_bg_flags_test(lVar6,uVar17,1), iVar11 != 0)) ||
             (iVar11 = ext2fs_bg_itable_unused(lVar6,uVar17), iVar11 != 0)) {
            iVar11 = fix_problem(param_1,0x36,local_a8);
            if (iVar11 != 0) {
              bVar21 = true;
              ext2fs_bg_flags_clear(lVar6,uVar17,2);
              ext2fs_bg_flags_clear(lVar6,uVar17,1);
              ext2fs_bg_itable_unused_set(lVar6,uVar17,0);
            }
            ext2fs_unmark_valid(lVar6);
          }
          if ((uVar18 == *(int *)(lVar6 + 0x30) - 1U) &&
             (iVar11 = ext2fs_bg_flags_test(lVar6,uVar17,2), iVar11 != 0)) {
            iVar11 = fix_problem(param_1,0x39,local_a8);
            if (iVar11 != 0) goto LAB_0011d58d;
LAB_0011d66e:
            ext2fs_unmark_valid(lVar6);
          }
LAB_0011d676:
          if (bVar21) goto LAB_0011d5ab;
        }
        else {
          if ((uVar18 != *(int *)(lVar6 + 0x30) - 1U) ||
             (iVar11 = ext2fs_bg_flags_test(lVar6,uVar17,2), iVar11 == 0)) {
LAB_0011d617:
            uVar20 = ext2fs_bg_itable_unused(lVar6,uVar17);
            uVar12 = ext2fs_bg_free_inodes_count(lVar6,uVar17);
            if ((uVar12 < uVar20) ||
               (uVar20 = ext2fs_bg_itable_unused(lVar6,uVar17), puVar7[10] < uVar20)) {
              uVar20 = ext2fs_bg_itable_unused(lVar6,uVar17);
              local_80 = (ulong)uVar20;
              iVar11 = fix_problem(param_1,0x38,local_a8);
              if (iVar11 != 0) {
                bVar21 = true;
                ext2fs_bg_itable_unused_set(lVar6,uVar17,0);
              }
              goto LAB_0011d66e;
            }
            goto LAB_0011d676;
          }
          iVar11 = fix_problem(param_1,0x39,local_a8);
          if (iVar11 == 0) {
            ext2fs_unmark_valid(lVar6);
            goto LAB_0011d617;
          }
LAB_0011d58d:
          ext2fs_bg_flags_clear(lVar6,uVar17,2);
          ext2fs_unmark_valid(lVar6);
          if (iVar10 != 0) {
            bVar21 = true;
            goto LAB_0011d617;
          }
LAB_0011d5ab:
          ext2fs_group_desc_csum_set(lVar6,uVar17);
        }
        if ((*(byte *)(param_1 + 9) & 3) != 0) goto LAB_0011cf0d;
        uVar17 = (ulong)(uVar18 + 1);
      }
      param_1[0xe] = local_c8 << ((byte)*(undefined4 *)(lVar6 + 0xc0) & 0x3f);
      *(int *)(param_1 + 0xf) = local_c0;
      uVar17 = ext2fs_free_blocks_count(puVar7);
      uVar19 = ext2fs_blocks_count(puVar7);
      if ((uVar19 < uVar17) || (*puVar7 < puVar7[4])) {
        ext2fs_unmark_valid(lVar6);
      }
      if (((int)param_1[0x41] != 0) && ((*(byte *)((long)param_1 + 0x4c) & 1) == 0)) {
        *(ushort *)((long)puVar7 + 0x3a) = *(ushort *)((long)puVar7 + 0x3a) & 0xfffe;
        ext2fs_mark_super_dirty(lVar6);
      }
      clear_problem_context(local_a8);
      if ((*(byte *)((long)param_1 + 0x4c) & 1) == 0) {
        iVar11 = uuid_is_null(puVar7 + 0x1a);
        if ((((iVar11 != 0) &&
             (iVar11 = FUN_0011c360(*(undefined4 *)(*(long *)(*param_1 + 0x20) + 100)), iVar11 == 0)
             ) && ((iVar10 == 0 || ((*(byte *)((long)param_1 + 0x7c) & 1) == 0)))) &&
           (iVar10 = fix_problem(param_1,9,local_a8), iVar10 != 0)) {
          uuid_generate(puVar7 + 0x1a);
          ext2fs_init_csum_seed(lVar6);
          *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) & 0xfffffdff | 4;
        }
      }
      profile_get_boolean(param_1[0x6c],"options","clear_test_fs_flag",0,1,&local_ac);
      if ((*(byte *)((long)param_1 + 0x4c) & 1) == 0) {
        lVar14 = *(long *)(lVar6 + 0x20);
        if ((local_ac != 0) && ((*(byte *)(lVar14 + 0x160) & 4) != 0)) {
          iVar10 = fs_proc_check(&DAT_00178ef4);
          if (((iVar10 != 0) || (iVar10 = check_for_modules(&DAT_00178ef4), iVar10 != 0)) &&
             (iVar10 = fix_problem(param_1,0x3b,local_a8), iVar10 != 0)) {
            uVar18 = *(uint *)(lVar6 + 0x10);
            puVar7 = (uint *)(*(long *)(lVar6 + 0x20) + 0x160);
            *puVar7 = *puVar7 & 0xfffffffb;
            *(uint *)(lVar6 + 0x10) = uVar18 & 0xfffffdff | 4;
          }
          if ((*(byte *)((long)param_1 + 0x4c) & 1) != 0) goto LAB_0011da68;
          lVar14 = *(long *)(lVar6 + 0x20);
        }
        if ((*(int *)(lVar14 + 0x48) == 1) &&
           (iVar10 = FUN_0011c350(*(undefined4 *)(lVar14 + 0x60)), iVar10 != 0)) {
          iVar10 = fix_problem(param_1,0xe,local_a8);
          if (iVar10 != 0) {
            FUN_0011bcb0(*(undefined8 *)(lVar6 + 0x20));
            ext2fs_mark_super_dirty(lVar6);
            *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) & 0xfffffdff;
          }
          if ((*(byte *)((long)param_1 + 0x4c) & 1) != 0) goto LAB_0011da68;
          lVar14 = *(long *)(lVar6 + 0x20);
        }
        if ((*(int *)(lVar14 + 0x4c) == 0) &&
           ((*(int *)(lVar14 + 0x5c) != 0 || (*(long *)(lVar14 + 0x60) != 0)))) {
          iVar10 = fix_problem(param_1,0x1a,local_a8);
          if (iVar10 != 0) {
            ext2fs_update_dynamic_rev(lVar6);
            ext2fs_mark_super_dirty(lVar6);
            *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) & 0xfffffdff;
          }
          if ((*(byte *)((long)param_1 + 0x4c) & 1) != 0) goto LAB_0011da68;
        }
        iVar10 = FUN_0011c4e0(param_1);
        if (iVar10 != 0) {
          puVar1 = (ushort *)(*(long *)(lVar6 + 0x20) + 0x3a);
          *puVar1 = *puVar1 & 0xfffe;
          ext2fs_mark_super_dirty(lVar6);
        }
      }
LAB_0011da68:
      profile_get_boolean(param_1[0x6c],"options","accept_time_fudge",0,1,&local_b4);
      profile_get_boolean(param_1[0x6c],"options","buggy_init_scripts",0,local_b4,&local_b4);
      param_1[0x6a] = (ulong)(-(uint)(local_b4 != 0) & 0x15180);
      profile_get_boolean(param_1[0x6c],"options","broken_system_clock",0,0,&local_b0);
      uVar18 = *(uint *)((long)param_1 + 0x4c) & 0x100;
      if (uVar18 == 0) {
        lVar14 = *(long *)(lVar6 + 0x20);
        if (*(int *)(lVar14 + 0x44) != 0) {
          if (local_b0 == 0) {
            uVar20 = *(uint *)(param_1 + 9);
            if ((uVar20 & 0x2000) == 0) goto LAB_0011dbbd;
LAB_0011db15:
            if (*(int *)(lVar14 + 0x44) != 0) {
LAB_0011db1c:
              if ((uVar20 & 0x2000) == 0) {
                lVar14 = *(long *)(lVar6 + 0x20);
                uVar13 = (uint)param_1[0x69];
                goto LAB_0011db2d;
              }
            }
          }
          else {
LAB_0011dc3f:
            if (*(int *)(lVar14 + 0x44) != 0) goto LAB_0011dc1a;
          }
        }
      }
      else if ((local_b0 == 0) && (uVar20 = *(uint *)(param_1 + 9), (uVar20 & 0x2000) == 0)) {
        lVar14 = *(long *)(lVar6 + 0x20);
LAB_0011dbbd:
        uVar12 = *(uint *)(lVar14 + 0x2c);
        uVar13 = (uint)param_1[0x69];
        if (uVar13 < uVar12) {
          local_58 = (ulong)uVar12;
          uVar16 = 0x31;
          if ((long)(ulong)uVar12 <= (long)((param_1[0x69] & 0xffffffffU) + param_1[0x6a])) {
            uVar16 = 0x3c;
          }
          iVar10 = fix_problem(param_1,uVar16,local_a8);
          if (iVar10 != 0) {
            *(int *)(*(long *)(lVar6 + 0x20) + 0x2c) = (int)param_1[0x69];
            *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) | 4;
          }
          if ((*(byte *)((long)param_1 + 0x4d) & 1) == 0) {
            lVar14 = *(long *)(lVar6 + 0x20);
            goto LAB_0011dc3f;
          }
LAB_0011dc1a:
          if (local_b0 == 0) {
            uVar20 = *(uint *)(param_1 + 9);
            goto LAB_0011db1c;
          }
        }
        else {
          if (uVar18 == 0) goto LAB_0011db15;
LAB_0011db2d:
          uVar18 = *(uint *)(lVar14 + 0x30);
          if (uVar13 < uVar18) {
            local_58 = (ulong)uVar18;
            uVar16 = 0x32;
            if ((long)(ulong)uVar18 <= (long)((ulong)uVar13 + param_1[0x6a])) {
              uVar16 = 0x3d;
            }
            iVar10 = fix_problem(param_1,uVar16,local_a8);
            if (iVar10 != 0) {
              *(int *)(*(long *)(lVar6 + 0x20) + 0x30) = (int)param_1[0x69];
              *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) | 4;
            }
          }
        }
      }
      e2fsck_validate_quota_inodes(param_1);
      e2fsck_move_ext3_journal(param_1);
      e2fsck_fix_ext3_journal_hint(param_1);
      FUN_0011c880(param_1);
      e2fsck_hide_quota(param_1);
      goto LAB_0011cf0d;
    }
    local_80 = (ulong)puVar7[5];
    local_78 = uVar17;
    fix_problem(param_1,8,local_a8);
  }
  else {
    local_80 = ext2fs_blocks_count(puVar7);
    local_78 = param_1[0xd];
    iVar10 = fix_problem(param_1,5,local_a8);
    if (iVar10 == 0) goto LAB_0011d229;
  }
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
LAB_0011cf0d:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: check_backup_super_block @ 0x1df40

undefined8 check_backup_super_block(long *param_1)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  uint uVar6;
  long in_FS_OFFSET;
  int local_428;
  int local_424;
  int local_410;
  short local_3f0;
  uint local_3dc;
  ushort local_3d0;
  int local_3cc;
  uint local_3c8;
  uint local_3c4;
  undefined1 local_3c0 [232];
  int local_2d8;
  long local_20;
  
  lVar1 = *param_1;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (((((*(byte *)(lVar1 + 0x11) & 2) != 0) && (iVar3 = ext2fs_test_valid(lVar1), iVar3 != 0)) &&
      ((*(byte *)(*(long *)(lVar1 + 0x20) + 0x3a) & 2) == 0)) &&
     (((param_1[9] & 0x100000003U) == 0 && (1 < *(uint *)(lVar1 + 0x30))))) {
    uVar6 = 1;
    do {
      iVar3 = ext2fs_bg_has_super(lVar1,uVar6);
      if (iVar3 != 0) {
        uVar4 = ext2fs_group_first_block2(lVar1,uVar6);
        lVar5 = (**(code **)(*(long *)(*(long *)(lVar1 + 8) + 8) + 0x28))
                          (*(long *)(lVar1 + 8),uVar4,0xfffffc00,&local_428);
        if ((((lVar5 == 0) && (local_3f0 == -0x10ad)) &&
            ((local_3dc < 2 && (local_410 + 10U < 0x11)))) &&
           ((local_3dc == 0 || (0x7f < local_3d0)))) {
          piVar2 = *(int **)(lVar1 + 0x20);
          uVar4 = 1;
          if (((piVar2[0x17] != local_3cc) ||
              ((((((piVar2[0x18] ^ local_3c8) & 0xffffffbb) != 0 ||
                 (((piVar2[0x19] ^ local_3c4) & 0xffffffdd) != 0)) || (piVar2[1] != local_424)) ||
               ((piVar2[0x54] != local_2d8 || (*piVar2 != local_428)))))) ||
             (iVar3 = memcmp(piVar2 + 0x1a,local_3c0,0x10), iVar3 != 0)) goto LAB_0011e0a3;
          break;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(lVar1 + 0x30));
  }
  uVar4 = 0;
LAB_0011e0a3:
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



// Function: check_inode_extra_negative_epoch @ 0x1e170

bool check_inode_extra_negative_epoch(int param_1,uint param_2)

{
  if (-1 < param_1) {
    return false;
  }
  return (param_2 & 3) == 3;
}



// Function: quota_inum_is_super @ 0x1e190

undefined8 quota_inum_is_super(undefined8 param_1,ulong param_2)

{
  int iVar1;
  undefined1 auVar2 [12];
  
  param_2 = param_2 & 0xffffffff;
  iVar1 = 0;
  do {
    auVar2 = FUN_0011e140(param_1,iVar1);
    if (*auVar2._0_8_ == (int)param_2) {
      return 1;
    }
    iVar1 = auVar2._8_4_ + 1;
  } while (iVar1 != 3);
  return 0;
}



// Function: pass1_get_blocks @ 0x1e1c0

undefined8 pass1_get_blocks(long param_1,int param_2,long param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = 0x7f2bb741;
  if ((*(int *)(*(long *)(param_1 + 0xe0) + 0x218) == param_2) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 0xe0) + 0x220), lVar1 != 0)) {
    lVar2 = 0;
    do {
      *(undefined4 *)(param_3 + lVar2) = *(undefined4 *)(lVar1 + 0x28 + lVar2);
      lVar2 = lVar2 + 4;
    } while (lVar2 != 0x3c);
    uVar3 = 0;
  }
  return uVar3;
}



// Function: pass1_read_inode @ 0x1e210

undefined8 pass1_read_inode(long param_1,int param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0x7f2bb741;
  if ((*(int *)(*(long *)(param_1 + 0xe0) + 0x218) == param_2) &&
     (puVar1 = *(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x220), puVar1 != (undefined8 *)0x0)) {
    uVar2 = puVar1[1];
    uVar3 = 0;
    *param_3 = *puVar1;
    param_3[1] = uVar2;
    uVar2 = puVar1[3];
    param_3[2] = puVar1[2];
    param_3[3] = uVar2;
    uVar2 = puVar1[5];
    param_3[4] = puVar1[4];
    param_3[5] = uVar2;
    uVar2 = puVar1[7];
    param_3[6] = puVar1[6];
    param_3[7] = uVar2;
    uVar2 = puVar1[9];
    param_3[8] = puVar1[8];
    param_3[9] = uVar2;
    uVar2 = puVar1[0xb];
    param_3[10] = puVar1[10];
    param_3[0xb] = uVar2;
    uVar2 = puVar1[0xd];
    param_3[0xc] = puVar1[0xc];
    param_3[0xd] = uVar2;
    uVar2 = puVar1[0xf];
    param_3[0xe] = puVar1[0xe];
    param_3[0xf] = uVar2;
  }
  return uVar3;
}



// Function: pass1_write_inode @ 0x1e290

undefined8 pass1_write_inode(long param_1,int param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (((*(int *)(*(long *)(param_1 + 0xe0) + 0x218) == param_2) &&
      (puVar1 = *(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x220), puVar1 != (undefined8 *)0x0))
     && (puVar1 != param_3)) {
    uVar2 = param_3[1];
    *puVar1 = *param_3;
    puVar1[1] = uVar2;
    uVar2 = param_3[3];
    puVar1[2] = param_3[2];
    puVar1[3] = uVar2;
    uVar2 = param_3[5];
    puVar1[4] = param_3[4];
    puVar1[5] = uVar2;
    uVar2 = param_3[7];
    puVar1[6] = param_3[6];
    puVar1[7] = uVar2;
    uVar2 = param_3[9];
    puVar1[8] = param_3[8];
    puVar1[9] = uVar2;
    uVar2 = param_3[0xb];
    puVar1[10] = param_3[10];
    puVar1[0xb] = uVar2;
    uVar2 = param_3[0xd];
    puVar1[0xc] = param_3[0xc];
    puVar1[0xd] = uVar2;
    uVar2 = param_3[0xf];
    puVar1[0xe] = param_3[0xe];
    puVar1[0xf] = uVar2;
    return 0x7f2bb741;
  }
  return 0x7f2bb741;
}



// Function: pass1_check_directory @ 0x1e310

undefined8 pass1_check_directory(long param_1,int param_2)

{
  ushort *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0x7f2bb741;
  if (((*(int *)(*(long *)(param_1 + 0xe0) + 0x218) == param_2) &&
      (puVar1 = *(ushort **)(*(long *)(param_1 + 0xe0) + 0x220), puVar1 != (ushort *)0x0)) &&
     (uVar2 = 0, (*puVar1 & 0xf000) != 0x4000)) {
    uVar2 = 0x7f2bb74a;
  }
  return uVar2;
}



// Function: e2fsck_block_alloc_stats @ 0x1e350

void e2fsck_block_alloc_stats(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  lVar3 = *(long *)(lVar1 + 0x1a0);
  if (lVar3 == 0) {
    return;
  }
  if ((param_3 < 0) && (*(long *)(lVar1 + 0x390) != 0)) {
    iVar2 = ext2fs_test_block_bitmap2(*(long *)(lVar1 + 0x390));
    if (iVar2 != 0) {
      return;
    }
    lVar3 = *(long *)(lVar1 + 0x1a0);
    if (lVar3 == 0) {
      return;
    }
  }
  else if (0 < param_3) {
    ext2fs_mark_block_bitmap2();
    return;
  }
  ext2fs_unmark_block_bitmap2(lVar3,param_2);
  return;
}



// Function: could_be_block_map @ 0x1e3d0

undefined8 could_be_block_map(long param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_2 + 0x28);
  do {
    uVar1 = *puVar3;
    uVar2 = ext2fs_blocks_count(*(undefined8 *)(param_1 + 0x20));
    if (uVar2 <= uVar1) {
      return 0;
    }
    puVar3 = puVar3 + 1;
  } while (puVar3 != (uint *)(param_2 + 100));
  return 1;
}



// Function: alloc_bb_map @ 0x1e430

void alloc_bb_map(undefined8 *param_1)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  long local_88 [10];
  undefined8 local_38;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_88);
  uVar1 = dcgettext(0,"inode in bad block map",5);
  local_88[0] = e2fsck_allocate_inode_bitmap(*param_1,uVar1,2,"inode_bb_map",param_1 + 0x30);
  if (local_88[0] != 0) {
    local_38 = 4;
    fix_problem(param_1,0x10024,local_88);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: alloc_imagic_map @ 0x1e4e0

void alloc_imagic_map(undefined8 *param_1)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  long local_88 [10];
  undefined8 local_38;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_88);
  uVar1 = dcgettext(0,"imagic inode map",5);
  local_88[0] = e2fsck_allocate_inode_bitmap(*param_1,uVar1,2,"inode_imagic_map",param_1 + 0x31);
  if (local_88[0] != 0) {
    local_38 = 5;
    fix_problem(param_1,0x10024,local_88);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: mark_inode_bad @ 0x1e590

void mark_inode_bad(undefined8 *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  long lVar2;
  long in_FS_OFFSET;
  long local_88 [10];
  undefined8 local_38;
  long local_20;
  
  lVar2 = param_1[0x2e];
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (lVar2 == 0) {
    clear_problem_context(local_88);
    uVar1 = dcgettext(0,"bad inode map",5);
    local_88[0] = e2fsck_allocate_inode_bitmap(*param_1,uVar1,2,"inode_bad_map",param_1 + 0x2e);
    if (local_88[0] != 0) {
      local_38 = 3;
      fix_problem(param_1,0x10024,local_88);
      *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
      goto LAB_0011e5c1;
    }
    lVar2 = param_1[0x2e];
  }
  ext2fs_mark_inode_bitmap2(lVar2,param_2);
LAB_0011e5c1:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_extents_inlinedata @ 0x1e660

void check_extents_inlinedata(undefined8 param_1,long param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  
  if ((*(uint *)(*(long *)(param_2 + 0x18) + 0x20) & 0x10080000) == 0) {
    return;
  }
  iVar4 = fix_problem(param_1,0x10076,param_2);
  if (iVar4 != 0) {
    lVar3 = *(long *)(param_2 + 0x18);
    uVar2 = *(undefined4 *)(param_2 + 8);
    puVar1 = (uint *)(lVar3 + 0x20);
    *puVar1 = *puVar1 & 0xeff7ffff;
    e2fsck_write_inode(param_1,uVar2,lVar3,"pass1");
    return;
  }
  return;
}



// Function: check_immutable @ 0x1e6c0

void check_immutable(undefined8 param_1,long param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  
  if ((*(byte *)(*(long *)(param_2 + 0x18) + 0x20) & 0x30) == 0) {
    return;
  }
  iVar4 = fix_problem(param_1,0x10030,param_2);
  if (iVar4 != 0) {
    lVar3 = *(long *)(param_2 + 0x18);
    uVar2 = *(undefined4 *)(param_2 + 8);
    puVar1 = (uint *)(lVar3 + 0x20);
    *puVar1 = *puVar1 & 0xffffffcf;
    e2fsck_write_inode(param_1,uVar2,lVar3,"pass1");
    return;
  }
  return;
}



// Function: check_size @ 0x1e720

void check_size(undefined8 *param_1,long param_2)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x18);
  if (*(int *)(lVar1 + 0x6c) != 0 || *(int *)(lVar1 + 4) != 0) {
    iVar2 = fix_problem(param_1,0x10032,param_2);
    if (iVar2 != 0) {
      ext2fs_inode_size_set(*param_1,lVar1,0);
      e2fsck_write_inode(param_1,*(undefined4 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x18),
                         "pass1");
      return;
    }
  }
  return;
}



// Function: process_inode_cmp @ 0x1e780

int process_inode_cmp(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1[0x1c] - param_2[0x1c] != 0) {
    return param_1[0x1c] - param_2[0x1c];
  }
  uVar3 = ext2fs_const_inode(param_1 + 6);
  iVar1 = ext2fs_file_acl_block(0,uVar3);
  uVar3 = ext2fs_const_inode(param_2 + 6);
  iVar2 = ext2fs_file_acl_block(0,uVar3);
  iVar1 = iVar1 - iVar2;
  if (iVar1 == 0) {
    iVar1 = *param_1 - *param_2;
  }
  return iVar1;
}



// Function: mark_table_blocks @ 0x1e7e0

void mark_table_blocks(long *param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  int *piVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  long in_FS_OFFSET;
  undefined1 local_a8 [40];
  long local_80;
  int local_68;
  long local_40;
  
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context();
  if (*(int *)(lVar1 + 0x30) != 0) {
    uVar7 = 0;
    do {
      while( true ) {
        iVar6 = (int)uVar7;
        local_68 = iVar6;
        ext2fs_reserve_super_and_bgd(lVar1,uVar7,param_1[0x34]);
        ext2fs_reserve_super_and_bgd(lVar1,uVar7,param_1[0x72]);
        lVar3 = ext2fs_inode_table_loc(lVar1,uVar7);
        if ((lVar3 != 0) &&
           (lVar3 = ext2fs_inode_table_loc(lVar1,uVar7), *(int *)(lVar1 + 0x48) != 0)) {
          uVar8 = 0;
          do {
            iVar2 = ext2fs_test_block_bitmap2(param_1[0x34],lVar3);
            if (iVar2 == 0) {
              ext2fs_mark_block_bitmap2(param_1[0x34],lVar3);
              ext2fs_mark_block_bitmap2(param_1[0x72],lVar3);
            }
            else {
              local_80 = lVar3;
              if ((*(int *)(param_1[0x40] + uVar7 * 4) == 0) &&
                 (iVar2 = fix_problem(param_1,0x10009,local_a8), iVar2 != 0)) {
                piVar5 = (int *)(param_1[0x40] + uVar7 * 4);
                *piVar5 = *piVar5 + 1;
                *(int *)(param_1 + 0x41) = (int)param_1[0x41] + 1;
              }
            }
            uVar8 = uVar8 + 1;
            lVar3 = lVar3 + 1;
          } while (uVar8 < *(uint *)(lVar1 + 0x48));
        }
        lVar3 = ext2fs_block_bitmap_loc(lVar1,uVar7);
        if (lVar3 == 0) break;
        uVar4 = ext2fs_block_bitmap_loc(lVar1,uVar7);
        iVar2 = ext2fs_test_block_bitmap2(param_1[0x34],uVar4);
        if (iVar2 == 0) {
          uVar4 = ext2fs_block_bitmap_loc(lVar1,uVar7);
          ext2fs_mark_block_bitmap2(param_1[0x34],uVar4);
          uVar4 = ext2fs_block_bitmap_loc(lVar1,uVar7);
          ext2fs_mark_block_bitmap2(param_1[0x72],uVar4);
          break;
        }
        local_80 = ext2fs_block_bitmap_loc(lVar1,uVar7);
        iVar2 = fix_problem(param_1,0x10007,local_a8);
        if (iVar2 == 0) break;
        piVar5 = (int *)(param_1[0x3f] + uVar7 * 4);
        *piVar5 = *piVar5 + 1;
        *(int *)(param_1 + 0x41) = (int)param_1[0x41] + 1;
        lVar3 = ext2fs_inode_bitmap_loc(lVar1,uVar7);
        if (lVar3 != 0) goto LAB_0011e910;
LAB_0011e83b:
        uVar7 = (ulong)(iVar6 + 1U);
        if (*(uint *)(lVar1 + 0x30) <= iVar6 + 1U) goto LAB_0011e980;
      }
      lVar3 = ext2fs_inode_bitmap_loc(lVar1,uVar7);
      if (lVar3 == 0) goto LAB_0011e83b;
LAB_0011e910:
      uVar4 = ext2fs_inode_bitmap_loc(lVar1,uVar7);
      iVar2 = ext2fs_test_block_bitmap2(param_1[0x34],uVar4);
      if (iVar2 == 0) {
        uVar4 = ext2fs_inode_bitmap_loc(lVar1,uVar7);
        ext2fs_mark_block_bitmap2(param_1[0x72],uVar4);
        uVar4 = ext2fs_inode_bitmap_loc(lVar1,uVar7);
        ext2fs_mark_block_bitmap2(param_1[0x34],uVar4);
        goto LAB_0011e83b;
      }
      local_80 = ext2fs_inode_bitmap_loc(lVar1,uVar7);
      iVar2 = fix_problem(param_1,0x10008,local_a8);
      if (iVar2 == 0) goto LAB_0011e83b;
      piVar5 = (int *)(param_1[0x3e] + uVar7 * 4);
      *piVar5 = *piVar5 + 1;
      *(int *)(param_1 + 0x41) = (int)param_1[0x41] + 1;
      uVar7 = (ulong)(iVar6 + 1U);
    } while (iVar6 + 1U < *(uint *)(lVar1 + 0x30));
  }
LAB_0011e980:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: pass1_readahead @ 0x1eae0

void pass1_readahead(long *param_1,uint *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  
  uVar1 = *param_2;
  lVar6 = *param_1;
  lVar7 = *(long *)(lVar6 + 0x20);
  if (param_1[0x73] == 0) {
LAB_0011ec33:
    *param_2 = *(uint *)(lVar6 + 0x30);
    iVar5 = **(int **)(lVar6 + 0x20);
  }
  else {
    uVar8 = 0x80;
    if (*(int *)(lVar7 + 0x4c) != 0) {
      uVar8 = (uint)*(ushort *)(lVar7 + 0x58);
    }
    uVar3 = (long)(0x400 << ((byte)*(undefined4 *)(lVar7 + 0x18) & 0x1f)) / (long)(int)uVar8;
    uVar8 = uVar1;
    if (uVar1 < *(uint *)(lVar6 + 0x30)) {
      lVar7 = 0;
      iVar5 = 0;
      do {
        iVar2 = ext2fs_bg_flags_test(lVar6,uVar8,1);
        lVar6 = *param_1;
        if (iVar2 == 0) {
          iVar5 = *(int *)(*(long *)(lVar6 + 0x20) + 0x28);
          iVar2 = ext2fs_bg_itable_unused(lVar6,uVar8);
          lVar6 = *param_1;
          iVar5 = iVar5 - iVar2;
          lVar7 = lVar7 + (ulong)(uint)((int)uVar3 + -1 + iVar5) / (uVar3 & 0xffffffff);
          uVar4 = (ulong)*(uint *)(lVar6 + 0x28) * lVar7;
          if ((ulong)(param_1[0x73] * 0x400) <= uVar4 && uVar4 + param_1[0x73] * -0x400 != 0) break;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(lVar6 + 0x30));
      iVar2 = (1 - uVar1) + uVar8;
    }
    else {
      iVar2 = 1;
      iVar5 = 0;
    }
    lVar7 = e2fsck_readahead(lVar6,0x10,uVar1,iVar2);
    if (lVar7 == 0xb) {
      param_1[0x73] = (ulong)param_1[0x73] >> 1;
    }
    else if (lVar7 != 0) {
      lVar6 = *param_1;
      goto LAB_0011ec33;
    }
    *param_2 = uVar8 + 1;
    iVar2 = *(int *)((long)param_1 + 0x25c);
    uVar3 = 0x80;
    if (iVar2 == 0) {
      iVar2 = 8;
    }
    lVar7 = *(long *)(*param_1 + 0x20);
    if (*(int *)(lVar7 + 0x4c) != 0) {
      uVar3 = (ulong)*(ushort *)(lVar7 + 0x58);
    }
    iVar5 = (iVar5 + *(int *)(lVar7 + 0x28) * uVar8) -
            (int)((ulong)(iVar5 - 1) % ((uint)(iVar2 * *(int *)(*param_1 + 0x28)) / uVar3));
  }
  *param_3 = iVar5;
  return;
}



// Function: quota_inum_is_reserved @ 0x1ec90

undefined8 quota_inum_is_reserved(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = quota_type2inum(iVar2,*(undefined8 *)(param_1 + 0x20));
    if (iVar1 == param_2) {
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 3);
  return 0;
}



// Function: inc_ea_inode_refs @ 0x1ecd0

void inc_ea_inode_refs(long param_1,long *param_2,byte *param_3,byte *param_4)

{
  int iVar1;
  long lVar2;
  
  if (param_4 <= param_3) {
    return;
  }
  do {
    if (*(int *)param_3 == 0) {
      return;
    }
    iVar1 = *(int *)(param_3 + 4);
    if (iVar1 != 0) {
      lVar2 = *(long *)(param_1 + 0x1e8);
      if (lVar2 == 0) {
        lVar2 = ea_refcount_create(0,param_1 + 0x1e8);
        *param_2 = lVar2;
        if (lVar2 != 0) {
          param_2[10] = 4;
          fix_problem(param_1,0x10038,param_2);
          *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1;
          return;
        }
        iVar1 = *(int *)(param_3 + 4);
        lVar2 = *(long *)(param_1 + 0x1e8);
      }
      ea_refcount_increment(lVar2,iVar1,0);
    }
    param_3 = param_3 + (*param_3 + 0x13 & 0x1fc);
  } while (param_3 < param_4);
  return;
}



// Function: add_casefolded_dir @ 0x1ed80

void add_casefolded_dir(long param_1,undefined4 param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  long local_88 [13];
  long local_20;
  
  lVar1 = *(long *)(param_1 + 0x370);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (lVar1 == 0) {
    local_88[0] = ext2fs_u32_list_create(param_1 + 0x370,0);
    if (local_88[0] == 0) {
      lVar1 = *(long *)(param_1 + 0x370);
      local_88[0] = 0;
      goto LAB_0011eda8;
    }
  }
  else {
LAB_0011eda8:
    local_88[0] = ext2fs_u32_list_add(lVar1,param_2);
    if (local_88[0] == 0) goto LAB_0011edcc;
  }
  fix_problem(param_1,0x1008c,local_88);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1;
LAB_0011edcc:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_blocks_inline_data @ 0x1ee10

void check_blocks_inline_data(long *param_1,long *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long in_FS_OFFSET;
  ulong local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_38 = 0;
  if ((*(byte *)(param_3 + 1) & 1) == 0) {
LAB_0011ee3b:
    *param_2 = 0;
  }
  else {
    lVar3 = ext2fs_add_dir_block2(*(undefined8 *)(*param_1 + 0x90),*param_3,0,0);
    *param_2 = lVar3;
    if (lVar3 == 0) {
      lVar3 = *param_1;
      uVar1 = *param_3;
      uVar2 = *(uint *)(lVar3 + 0x10);
      *(uint *)(lVar3 + 0x10) = uVar2 | 0x200000;
      lVar4 = ext2fs_inline_data_size(lVar3,uVar1,&local_38);
      lVar3 = *param_1;
      *param_2 = lVar4;
      *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) & 0xffdfffff | uVar2 & 0x200000;
      if (lVar4 != 0) goto LAB_0011ee3b;
      if (local_38 < 0x3d) goto LAB_0011ee43;
      lVar3 = ext2fs_add_dir_block2(*(undefined8 *)(lVar3 + 0x90),*param_3,0,1);
      *param_2 = lVar3;
      if (lVar3 == 0) goto LAB_0011ee43;
    }
    param_2[5] = 0;
    param_2[10] = 0;
    fix_problem(param_1,0x1002b,param_2);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  }
LAB_0011ee43:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: recheck_bad_inode_checksum @ 0x1ef30

long recheck_bad_inode_checksum(undefined8 param_1,ulong param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long in_FS_OFFSET;
  undefined1 auStack_d8 [168];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined4 *)(param_3 + 0x218) = 0;
  lVar2 = ext2fs_read_inode_full(param_1,param_2,auStack_d8,0xa0);
  if (lVar2 != 0) {
    if (lVar2 != 0x7f2bb792) goto LAB_0011ef86;
    iVar1 = fix_problem(param_3,0x10068,param_4);
    if (iVar1 != 0) {
      lVar2 = ext2fs_write_inode_full(param_1,param_2 & 0xffffffff,auStack_d8,0xa0);
      goto LAB_0011ef86;
    }
  }
  lVar2 = 0;
LAB_0011ef86:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar2;
}



// Function: finish_processing_inode @ 0x1eff0

void finish_processing_inode(undefined8 *param_1,undefined8 param_2,long *param_3,int param_4)

{
  long lVar1;
  
  if (param_4 == 0) {
    return;
  }
  lVar1 = FUN_0011ef30(*param_1,param_2,param_1,param_3);
  *param_3 = lVar1;
  if (lVar1 != 0) {
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  }
  return;
}



// Function: reserve_block_for_root_repair @ 0x1f030

void reserve_block_for_root_repair(undefined8 *param_1)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  long in_FS_OFFSET;
  undefined8 local_28;
  long local_20;
  
  uVar1 = *param_1;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = 0;
  param_1[0x6f] = 0;
  iVar2 = ext2fs_test_inode_bitmap2(param_1[0x2d],2);
  if (iVar2 == 0) {
    lVar3 = ext2fs_new_block2(uVar1,0,param_1[0x34],&local_28);
    if (lVar3 == 0) {
      ext2fs_mark_block_bitmap2(param_1[0x34],local_28);
      param_1[0x6f] = local_28;
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: reserve_block_for_lnf_repair @ 0x1f0d0

void reserve_block_for_lnf_repair(undefined8 *param_1)

{
  undefined8 uVar1;
  long lVar2;
  long in_FS_OFFSET;
  undefined1 local_2c [4];
  undefined8 local_28;
  long local_20;
  
  uVar1 = *param_1;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  param_1[0x70] = 0;
  local_28 = 0;
  lVar2 = ext2fs_lookup(uVar1,2,"lost+found",10,0,local_2c);
  if (lVar2 != 0) {
    lVar2 = ext2fs_new_block2(uVar1,0,param_1[0x34],&local_28);
    if (lVar2 == 0) {
      ext2fs_mark_block_bitmap2(param_1[0x34],local_28);
      param_1[0x70] = local_28;
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: adjust_extattr_refcount @ 0x1f180

void adjust_extattr_refcount(undefined8 *param_1,undefined8 param_2,long param_3,int param_4)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  long in_FS_OFFSET;
  int local_b0 [2];
  long local_a8;
  undefined4 local_a0;
  long local_80;
  ulong local_70;
  ulong local_58;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = *param_1;
  clear_problem_context(&local_a8);
  ea_refcount_intr_begin(param_2);
  do {
    lVar3 = ea_refcount_intr_next(param_2,local_b0);
    if (lVar3 == 0) {
LAB_0011f24a:
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    local_80 = lVar3;
    local_a8 = ext2fs_read_ext_attr3(uVar1,lVar3,param_3,local_a0);
    if (local_a8 != 0) {
      fix_problem(param_1,0x1003b,&local_a8);
      goto LAB_0011f24a;
    }
    local_70 = (ulong)*(uint *)(param_3 + 4);
    uVar4 = param_4 * local_b0[0] + *(int *)(param_3 + 4);
    local_58 = (ulong)uVar4;
    iVar2 = fix_problem(param_1,0x1003c,&local_a8);
    if (iVar2 != 0) {
      *(uint *)(param_3 + 4) = uVar4;
      local_a8 = ext2fs_write_ext_attr3(uVar1,lVar3,param_3,local_a0);
      if (local_a8 != 0) {
        fix_problem(param_1,0x1003d,&local_a8);
      }
    }
  } while( true );
}



// Function: e2fsck_block_alloc_stats_range @ 0x1f2d0

void e2fsck_block_alloc_stats_range(long param_1,undefined8 param_2,ulong param_3,int param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  lVar3 = *(long *)(lVar1 + 0x1a0);
  if (lVar3 == 0) {
    return;
  }
  if ((param_4 < 0) && (*(long *)(lVar1 + 0x390) != 0)) {
    iVar2 = ext2fs_test_block_bitmap_range2(*(long *)(lVar1 + 0x390));
    param_3 = param_3 & 0xffffffff;
    if (iVar2 != 0) {
      return;
    }
    lVar3 = *(long *)(lVar1 + 0x1a0);
    if (lVar3 == 0) {
      return;
    }
  }
  else if (0 < param_4) {
    ext2fs_mark_block_bitmap_range2();
    return;
  }
  ext2fs_unmark_block_bitmap_range2(lVar3,param_2,param_3);
  return;
}



// Function: e2fsck_new_range @ 0x1f350

void e2fsck_new_range(long param_1,ulong param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0xe0) + 0x1a0);
  if ((lVar1 == 0) && (lVar1 = *(long *)(param_1 + 0x58), lVar1 == 0)) {
    lVar1 = ext2fs_read_block_bitmap();
    if (lVar1 != 0) {
      return;
    }
    param_2 = param_2 & 0xffffffff;
    lVar1 = *(long *)(param_1 + 0x58);
  }
  ext2fs_new_range(param_1,param_2,param_3,param_4,lVar1,param_5,param_6);
  return;
}



// Function: e2fsck_get_alloc_block @ 0x1f3d0

long e2fsck_get_alloc_block(long param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined8 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(long *)(*(long *)(param_1 + 0xe0) + 0x1a0) == 0) {
    lVar1 = *(long *)(param_1 + 0x58);
    if (lVar1 == 0) {
      lVar1 = ext2fs_read_block_bitmap();
      if (lVar1 != 0) goto LAB_0011f435;
      lVar1 = *(long *)(param_1 + 0x58);
    }
    lVar1 = ext2fs_new_block2(param_1,param_2,lVar1,&local_28);
    if (lVar1 == 0) {
      lVar1 = 0;
      *param_3 = local_28;
    }
  }
  else {
    lVar1 = ext2fs_new_block2();
    if (lVar1 == 0) {
      if (*(long *)(param_1 + 0x58) != 0) {
        ext2fs_mark_block_bitmap2();
        ext2fs_mark_bb_dirty(param_1);
      }
      *param_3 = local_28;
      lVar1 = 0;
    }
  }
LAB_0011f435:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_large_ea_inode @ 0x1f600

undefined4 check_large_ea_inode(long *param_1,long param_2,long param_3,undefined8 *param_4)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  long in_FS_OFFSET;
  uint local_cc;
  undefined1 local_c8 [16];
  int local_b8;
  uint local_a8;
  int local_64;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = *(uint *)(param_2 + 4);
  puVar2 = *(uint **)(*param_1 + 0x20);
  if (puVar2[0x13] == 0) {
    if (10 < uVar1) goto LAB_0011f648;
  }
  else if (puVar2[0x15] <= uVar1) {
LAB_0011f648:
    if (uVar1 <= *puVar2) {
      e2fsck_read_inode(param_1,uVar1,local_c8,"pass1");
      lVar4 = ext2fs_ext_attr_hash_entry2(*param_1,param_2,0,&local_cc);
      if (lVar4 != 0) {
        uVar6 = *(undefined4 *)(param_2 + 4);
        uVar5 = dcgettext(0,"while hashing entry with e_value_inum = %u",5);
        com_err("check_large_ea_inode",lVar4,uVar5,uVar6);
                    /* WARNING: Subroutine does not return */
        fatal_error(param_1,0);
      }
      if (*(uint *)(param_2 + 0xc) == local_cc) {
        uVar5 = FUN_0011f5e0(*(undefined4 *)(*param_1 + 0x28),*(undefined4 *)(*param_1 + 0xc0),
                             *(undefined4 *)(param_2 + 8));
      }
      else {
        if ((local_b8 != *(int *)(param_3 + 8)) ||
           (local_64 != *(int *)(*(long *)(param_3 + 0x18) + 100))) {
          if ((local_a8 & 0x200000) == 0) {
            uVar6 = 0x10083;
            *(ulong *)(param_3 + 0x50) = (ulong)*(uint *)(param_2 + 4);
          }
          else {
            *(ulong *)(param_3 + 0x50) = (ulong)*(uint *)(param_2 + 0xc);
            uVar6 = 0x10054;
          }
          goto LAB_0011f6ce;
        }
        uVar5 = 0;
      }
      *param_4 = uVar5;
      if ((local_a8 & 0x200000) == 0) {
        *(ulong *)(param_3 + 0x50) = (ulong)*(uint *)(param_2 + 4);
        iVar3 = fix_problem(param_1,0x10086,param_3);
        if (iVar3 == 0) {
          uVar6 = 0x10085;
        }
        else {
          local_a8 = local_a8 | 0x200000;
          ext2fs_write_inode(*param_1,*(undefined4 *)(param_2 + 4),local_c8);
          uVar6 = 0;
        }
      }
      else {
        uVar6 = 0;
      }
      goto LAB_0011f6ce;
    }
  }
  *(ulong *)(param_3 + 0x50) = (ulong)uVar1;
  uVar6 = 0x10083;
LAB_0011f6ce:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_ea_in_inode @ 0x1f800

void check_ea_in_inode(long *param_1,long param_2,long *param_3)

{
  undefined4 *puVar1;
  ushort uVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  long lVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  long lVar12;
  byte *pbVar13;
  long in_FS_OFFSET;
  long local_48;
  long local_40;
  
  lVar7 = *(long *)(param_2 + 0x18);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = *(long *)(*param_1 + 0x20);
  *param_3 = 0;
  param_3[1] = 0;
  iVar9 = 0;
  if (*(int *)(lVar3 + 0x4c) != 0) {
    iVar9 = *(ushort *)(lVar3 + 0x58) - 0x80;
  }
  uVar2 = *(ushort *)(lVar7 + 0x80);
  puVar1 = (undefined4 *)(lVar7 + 0x80 + (ulong)uVar2);
  uVar10 = iVar9 - (uint)uVar2;
  pbVar6 = (byte *)(puVar1 + 1);
  lVar7 = region_create(0);
  if (lVar7 == 0) {
    fix_problem(param_1,0x1003f,param_2);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
LAB_0011fa32:
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else {
    iVar9 = region_allocate(lVar7,0,4);
    if (iVar9 == 0) {
      uVar11 = uVar10 - 4;
      if (uVar11 < 0x10) {
        lVar12 = 4;
      }
      else {
        pbVar13 = pbVar6;
        do {
          lVar12 = (long)pbVar13 - (long)puVar1;
          if (*(int *)pbVar13 == 0) goto LAB_0011fa60;
          iVar9 = region_allocate(lVar7,lVar12,*pbVar13 + 0x13 & 0xfffffffc);
          if (iVar9 != 0) {
LAB_0011faf0:
            iVar9 = 0x10069;
LAB_0011faf5:
            region_free(lVar7);
            goto LAB_0011f9d5;
          }
          uVar5 = *pbVar13 + 3 & 0xfffffffc;
          if (uVar11 - 0x10 < uVar5) {
            *(ulong *)(param_2 + 0x50) = (ulong)*pbVar13;
            region_free(lVar7);
            iVar9 = 0x10050;
            goto LAB_0011f9d5;
          }
          uVar11 = (uVar11 - 0x10) - uVar5;
          if (*(int *)(pbVar13 + 4) == 0) {
            uVar5 = *(uint *)(pbVar13 + 8);
            if (uVar11 < uVar5) {
              *(ulong *)(param_2 + 0x50) = (ulong)uVar5;
              region_free(lVar7);
              iVar9 = 0x10053;
              goto LAB_0011f9d5;
            }
            if (uVar5 != 0) {
              iVar9 = region_allocate(lVar7,(ulong)*(ushort *)(pbVar13 + 2) + 4,
                                      uVar5 + 3 & 0xfffffffc);
              if (iVar9 != 0) goto LAB_0011faf0;
            }
            uVar4 = ext2fs_ext_attr_hash_entry(pbVar13,pbVar6 + *(ushort *)(pbVar13 + 2));
            uVar5 = *(uint *)(pbVar13 + 0xc);
            if ((uVar5 != 0) && (uVar5 != uVar4)) {
              *(ulong *)(param_2 + 0x50) = (ulong)uVar5;
              region_free(lVar7);
              iVar9 = 0x10054;
              goto LAB_0011f9d5;
            }
          }
          else {
            iVar9 = FUN_0011f600(param_1,pbVar13,param_2,&local_48);
            if (iVar9 != 0) goto LAB_0011faf5;
            param_3[1] = param_3[1] + 1;
            *param_3 = *param_3 + local_48;
          }
          if (*(int *)(pbVar13 + 4) == 0) {
            uVar11 = uVar11 - *(int *)(pbVar13 + 8);
          }
          pbVar13 = pbVar13 + (*pbVar13 + 0x13 & 0x1fc);
        } while (0xf < uVar11);
        lVar12 = (long)pbVar13 - (long)puVar1;
      }
LAB_0011fa60:
      iVar9 = region_allocate(lVar7,lVar12,4);
      if (iVar9 != 0) {
        region_free(lVar7);
        iVar9 = 0x10069;
        goto LAB_0011f9d5;
      }
      region_free(lVar7);
    }
    else {
      region_free(lVar7);
      iVar9 = 0x10069;
LAB_0011f9d5:
      iVar9 = fix_problem(param_1,iVar9,param_2);
      if (iVar9 != 0) {
        uVar8 = 0x80;
        *puVar1 = 0;
        if (*(int *)(lVar3 + 0x4c) != 0) {
          uVar8 = *(undefined2 *)(lVar3 + 0x58);
        }
        e2fsck_write_inode_full
                  (param_1,*(undefined4 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x18),uVar8,
                   "pass1");
        *param_3 = 0;
        param_3[1] = 0;
        goto LAB_0011fa32;
      }
    }
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      FUN_0011ecd0(param_1,param_2,pbVar6,(long)puVar1 + (ulong)uVar10);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_inode_extra_space @ 0x1fb80

void check_inode_extra_space(long *param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  long lVar2;
  ushort uVar3;
  int iVar4;
  ulong uVar5;
  undefined2 uVar6;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  uint extraout_EDX_02;
  int iVar7;
  
  lVar1 = *(long *)(param_2 + 0x18);
  lVar2 = *(long *)(*param_1 + 0x20);
  *param_3 = 0;
  param_3[1] = 0;
  if ((*(int *)(lVar2 + 0x4c) != 0) && (*(ushort *)(lVar2 + 0x58) != 0x80)) {
    uVar3 = *(ushort *)(lVar1 + 0x80);
    uVar5 = (ulong)uVar3;
    iVar7 = *(ushort *)(lVar2 + 0x58) - 0x80;
    if ((uVar3 != 0) && (((iVar7 < (int)(uint)uVar3 || (uVar3 < 4)) || ((uVar3 & 3) != 0)))) {
      iVar4 = fix_problem(param_1,0x1004f,param_2);
      if (iVar4 == 0) {
        return;
      }
      uVar3 = *(ushort *)(lVar1 + 0x80);
      if ((uVar3 < 4) || (iVar7 < (int)(uint)uVar3)) {
        uVar3 = *(ushort *)(lVar2 + 0x15e);
      }
      else {
        uVar3 = uVar3 + 3 & 0xfffc;
      }
      iVar4 = *(int *)(lVar2 + 0x4c);
      *(ushort *)(lVar1 + 0x80) = uVar3;
      uVar6 = 0x80;
      if (iVar4 != 0) {
        uVar6 = *(undefined2 *)(lVar2 + 0x58);
      }
      e2fsck_write_inode_full
                (param_1,*(undefined4 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x18),uVar6,"pass1")
      ;
      uVar5 = (ulong)*(ushort *)(lVar1 + 0x80);
    }
    if (uVar5 < (long)iVar7 - 4U) {
      if (*(int *)(lVar1 + 0x80 + uVar5) == -0x15fe0000) {
        FUN_0011f800(param_1,param_2,param_3);
      }
      if ((param_1[0x69] < 0x200000000) &&
         ((((iVar7 = FUN_0011e170(*(undefined4 *)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x8c)),
            iVar7 != 0 ||
            (iVar7 = FUN_0011e170(*(undefined4 *)(lVar1 + 0xc),*(undefined4 *)(lVar1 + 0x84)),
            iVar7 != 0)) ||
           ((iVar7 = FUN_0011e170(*(undefined4 *)(lVar1 + 0x90),*(undefined4 *)(lVar1 + 0x94)),
            iVar7 != 0 ||
            (iVar7 = FUN_0011e170(*(undefined4 *)(lVar1 + 0x10),*(undefined4 *)(lVar1 + 0x88)),
            iVar7 != 0)))) && (iVar7 = fix_problem(param_1,0x10082,param_2), iVar7 != 0)))) {
        iVar7 = FUN_0011e170(*(undefined4 *)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x8c));
        if (iVar7 != 0) {
          *(uint *)(lVar1 + 0x8c) = extraout_EDX & 0xfffffffc;
        }
        iVar7 = FUN_0011e170(*(undefined4 *)(lVar1 + 0xc),*(undefined4 *)(lVar1 + 0x84));
        if (iVar7 != 0) {
          *(uint *)(lVar1 + 0x84) = extraout_EDX_00 & 0xfffffffc;
        }
        iVar7 = FUN_0011e170(*(undefined4 *)(lVar1 + 0x90),*(undefined4 *)(lVar1 + 0x94));
        if (iVar7 != 0) {
          *(uint *)(lVar1 + 0x94) = extraout_EDX_01 & 0xfffffffc;
        }
        iVar7 = FUN_0011e170(*(undefined4 *)(lVar1 + 0x10),*(undefined4 *)(lVar1 + 0x88));
        if (iVar7 != 0) {
          *(uint *)(lVar1 + 0x88) = extraout_EDX_02 & 0xfffffffc;
        }
        uVar6 = 0x80;
        if (*(int *)(lVar2 + 0x4c) != 0) {
          uVar6 = *(undefined2 *)(lVar2 + 0x58);
        }
        e2fsck_write_inode_full
                  (param_1,*(undefined4 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x18),uVar6,
                   "pass1");
        return;
      }
    }
  }
  return;
}



// Function: new_table_block @ 0x1fe80

void new_table_block(long *param_1,undefined8 param_2,uint param_3,undefined8 param_4,int param_5,
                 long *param_6)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long extraout_RDX;
  long lVar7;
  long in_FS_OFFSET;
  undefined8 local_b0;
  long local_a8 [5];
  long local_80;
  long local_78;
  uint local_68;
  long local_58;
  undefined8 local_48;
  long local_40;
  
  lVar2 = *param_1;
  lVar3 = *param_6;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_a8);
  local_80 = lVar3;
  local_68 = param_3;
  local_48 = param_4;
  iVar4 = FUN_0011fe70(*(undefined4 *)(*(long *)(lVar2 + 0x20) + 0x60));
  if (iVar4 == 0) {
    uVar5 = ext2fs_group_last_block2(lVar2,param_3);
    local_a8[0] = ext2fs_get_free_blocks2(lVar2,param_2,uVar5,param_5,param_1[0x34],param_6);
    if (local_a8[0] == 0) goto LAB_0011ff76;
LAB_00120160:
    local_58 = (long)param_5;
    uVar5 = 0x1001e;
  }
  else {
    bVar1 = *(byte *)(extraout_RDX + 0x174);
    uVar5 = ext2fs_group_first_block2(lVar2,(param_3 >> (bVar1 & 0x1f)) << (bVar1 & 0x1f));
    param_3 = (1 << (bVar1 & 0x1f)) - 1U | param_3;
    if (*(uint *)(lVar2 + 0x30) <= param_3) {
      param_3 = *(uint *)(lVar2 + 0x30) - 1;
    }
    uVar6 = ext2fs_group_last_block2(lVar2,param_3);
    local_a8[0] = ext2fs_get_free_blocks2(lVar2,uVar5,uVar6,param_5,param_1[0x34],param_6);
    if (local_a8[0] == 0x7f2bb748) {
      lVar7 = param_1[0x34];
      uVar5 = ext2fs_blocks_count(*(undefined8 *)(lVar2 + 0x20));
      local_a8[0] = ext2fs_get_free_blocks2
                              (lVar2,*(undefined4 *)(*(long *)(lVar2 + 0x20) + 0x14),uVar5,param_5,
                               lVar7,param_6);
    }
    if (local_a8[0] != 0) goto LAB_00120160;
LAB_0011ff76:
    local_a8[0] = ext2fs_get_mem(*(undefined4 *)(lVar2 + 0x28),&local_b0);
    if (local_a8[0] == 0) {
      ext2fs_mark_super_dirty(lVar2);
      local_78 = *param_6;
      *(uint *)(lVar2 + 0x10) = *(uint *)(lVar2 + 0x10) & 0xfffffdff;
      lVar7 = 0;
      fix_problem(param_1,(lVar3 == 0) + 0x10020,local_a8);
      local_78 = 0;
      if (0 < param_5) {
        do {
          while (local_80 = lVar7, ext2fs_mark_block_bitmap2(param_1[0x34],*param_6 + lVar7),
                lVar3 == 0) {
            local_80 = *param_6 + lVar7;
            local_a8[0] = ext2fs_zero_blocks2(lVar2,local_80,1,0,0);
            if (local_a8[0] == 0) goto LAB_0012003e;
LAB_0012008d:
            lVar7 = lVar7 + 1;
            fix_problem(param_1,0x10023,local_a8);
            if (param_5 == lVar7) goto LAB_001200a8;
          }
          local_a8[0] = io_channel_read_blk64(*(undefined8 *)(lVar2 + 8),lVar3 + lVar7,1,local_b0);
          if (local_a8[0] != 0) {
            fix_problem(param_1,0x10022,local_a8);
          }
          local_80 = *param_6 + lVar7;
          local_a8[0] = io_channel_write_blk64(*(undefined8 *)(lVar2 + 8),local_80,1,local_b0);
          if (local_a8[0] != 0) goto LAB_0012008d;
LAB_0012003e:
          lVar7 = lVar7 + 1;
        } while (param_5 != lVar7);
      }
LAB_001200a8:
      ext2fs_free_mem(&local_b0);
      goto LAB_001200dd;
    }
    uVar5 = 0x1001f;
  }
  fix_problem(param_1,uVar5,local_a8);
  ext2fs_unmark_valid(lVar2);
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
LAB_001200dd:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: handle_fs_bad_blocks @ 0x201c0

void handle_fs_bad_blocks(long *param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  long in_FS_OFFSET;
  undefined8 local_48;
  long local_40;
  
  lVar2 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(int *)(lVar2 + 0x30) != 0) {
    uVar5 = 0;
    do {
      while( true ) {
        uVar7 = (ulong)uVar5;
        uVar3 = ext2fs_group_first_block2(lVar2,uVar5);
        if (*(int *)(param_1[0x3f] + uVar7 * 4) == 0) break;
        local_48 = ext2fs_block_bitmap_loc(lVar2,uVar5);
        uVar4 = dcgettext(0,"block bitmap",5);
        FUN_0011fe80(param_1,uVar3,uVar5,uVar4,1,&local_48);
        ext2fs_block_bitmap_loc_set(lVar2,uVar5,local_48);
        if (*(int *)(param_1[0x3e] + uVar7 * 4) != 0) goto LAB_001202ae;
LAB_00120213:
        if (*(int *)(param_1[0x40] + uVar7 * 4) == 0) goto LAB_00120226;
LAB_0012030b:
        local_48 = ext2fs_inode_table_loc(lVar2,uVar5);
        uVar1 = *(undefined4 *)(lVar2 + 0x48);
        uVar4 = dcgettext(0,"inode table",5);
        FUN_0011fe80(param_1,uVar3,uVar5,uVar4,uVar1,&local_48);
        uVar6 = uVar5 + 1;
        ext2fs_inode_table_loc_set(lVar2,uVar5,local_48);
        *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 4;
        uVar5 = uVar6;
        if (*(uint *)(lVar2 + 0x30) <= uVar6) goto LAB_0012036e;
      }
      if (*(int *)(param_1[0x3e] + uVar7 * 4) == 0) goto LAB_00120213;
LAB_001202ae:
      local_48 = ext2fs_inode_bitmap_loc(lVar2,uVar5);
      uVar4 = dcgettext(0,"inode bitmap",5);
      FUN_0011fe80(param_1,uVar3,uVar5,uVar4,1,&local_48);
      ext2fs_inode_bitmap_loc_set(lVar2,uVar5,local_48);
      if (*(int *)(param_1[0x40] + uVar7 * 4) != 0) goto LAB_0012030b;
LAB_00120226:
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(lVar2 + 0x30));
  }
LAB_0012036e:
  *(undefined4 *)(param_1 + 0x41) = 0;
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_is_really_dir @ 0x203d0

void check_is_really_dir(long *param_1,long param_2,int *param_3)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  uint uVar8;
  ulong extraout_RDX;
  uint *puVar9;
  uint uVar10;
  long lVar11;
  ulong uVar12;
  long in_FS_OFFSET;
  uint local_154;
  ulong local_150;
  uint local_148 [66];
  long local_40;
  
  puVar1 = *(ushort **)(param_2 + 0x18);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((((*puVar1 & 0xf000) == 0x4000) || ((*puVar1 & 0xd000) == 0x8000)) ||
     (*(int *)(puVar1 + 0x14) == 0)) goto LAB_00120470;
  lVar4 = *param_1;
  lVar11 = param_2;
  iVar2 = FUN_001203c0(*(undefined4 *)(*(long *)(lVar4 + 0x20) + 0x60));
  iVar3 = FUN_0011fe30();
  if ((iVar3 == 0) || ((*(byte *)((long)puVar1 + 0x23) & 0x10) == 0)) {
    uVar12 = 0;
    uVar5 = extraout_RDX;
    if (iVar2 == 0) {
      uVar10 = 0;
LAB_001204b5:
      while( true ) {
        local_150 = uVar5 & 0xffffffff;
        if ((local_150 != 0) &&
           (((uVar10 = (uVar10 + 1) - (uint)(uVar12 < 4),
             local_150 < *(uint *)(*(long *)(*param_1 + 0x20) + 0x14) ||
             (uVar5 = ext2fs_blocks_count(), uVar5 <= local_150)) ||
            (iVar2 = ext2fs_fast_test_block_bitmap2(param_1[0x34]), iVar2 != 0))))
        goto LAB_00120470;
        uVar12 = uVar12 + 1;
        if (uVar12 == 0xf) break;
        uVar5 = (ulong)*(uint *)(puVar1 + uVar12 * 2 + 0x14);
      }
      local_150 = (ulong)*(uint *)(puVar1 + 0x14);
      if ((((*puVar1 & 0xb000) == 0x2000) && (puVar1[0xd] == 1)) && (uVar10 == 0))
      goto LAB_00120470;
    }
    else {
      uVar10 = *(uint *)(puVar1 + 0x10) & 0x80000;
      if (uVar10 == 0) goto LAB_001204b5;
      lVar4 = ext2fs_bmap2(lVar4,*(undefined4 *)(param_2 + 8),puVar1,0,0,0,0,&local_150);
      if (lVar4 != 0) goto LAB_00120470;
    }
    uVar6 = dcgettext(0,"reading directory block",5);
    ehandler_operation(uVar6);
    lVar4 = ext2fs_read_dir_block4(*param_1,local_150,param_3,0,*(undefined4 *)(param_2 + 8));
    ehandler_operation(0);
    if (lVar4 != 0) goto LAB_00120470;
    lVar4 = ext2fs_get_rec_len(*param_1,param_3,&local_154);
    if (((lVar4 != 0) || (iVar2 = ext2fs_dirent_name_len(param_3), iVar2 != 1)) ||
       (((((char)param_3[2] != '.' || ((*param_3 != *(int *)(param_2 + 8) || (local_154 < 0xc)))) ||
         ((local_154 & 3) != 0)) || (*(int *)(*param_1 + 0x28) - 0xcU <= local_154))))
    goto LAB_00120470;
    lVar11 = (long)param_3 + (ulong)local_154;
    lVar4 = ext2fs_get_rec_len(*param_1,lVar11,&local_154);
    if ((((lVar4 != 0) || (iVar2 = ext2fs_dirent_name_len(lVar11), iVar2 != 2)) ||
        (*(short *)(lVar11 + 8) != 0x2e2e)) || ((local_154 < 0xc || ((local_154 & 3) != 0))))
    goto LAB_00120470;
  }
  else {
    lVar4 = ext2fs_inline_data_size(lVar4,*(undefined4 *)(lVar11 + 8),&local_150);
    if ((local_150 & 3) != 0 || lVar4 != 0) goto LAB_00120470;
    puVar9 = local_148;
    uVar10 = *(uint *)(puVar1 + 0x14);
    FUN_0011f560();
    uVar6 = __memcpy_chk(puVar9);
    ext2fs_get_rec_len(*param_1,uVar6,&local_154);
    puVar9 = *(uint **)(*param_1 + 0x20);
    if (*puVar9 <= uVar10) goto LAB_00120470;
    uVar8 = 0xb;
    if (puVar9[0x13] != 0) {
      uVar8 = puVar9[0x15];
    }
    if (((uVar10 != 2) && (uVar10 < uVar8)) ||
       ((*puVar9 <= local_148[0] ||
        (((local_148[0] < uVar8 && (local_148[0] != 0)) || (0x38 < local_154))))))
    goto LAB_00120470;
  }
  iVar2 = fix_problem(param_1,0x10055,param_2);
  if (iVar2 != 0) {
    uVar7 = 0x80;
    *puVar1 = *puVar1 & 0xfff | 0x4000;
    if (*(int *)(*(long *)(*param_1 + 0x20) + 0x4c) != 0) {
      uVar7 = *(undefined2 *)(*(long *)(*param_1 + 0x20) + 0x58);
    }
    e2fsck_write_inode_full(param_1,*(undefined4 *)(param_2 + 8),puVar1,uVar7,"check_is_really_dir")
    ;
  }
LAB_00120470:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: mark_block_used @ 0x20780

void mark_block_used(long *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long in_FS_OFFSET;
  long local_88 [10];
  undefined8 local_38;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_88);
  iVar1 = ext2fs_fast_test_block_bitmap2(param_1[0x34],param_2);
  if (iVar1 == 0) {
    lVar3 = param_1[0x34];
  }
  else {
    iVar1 = FUN_00120770(*(undefined4 *)(*(long *)(*param_1 + 0x20) + 100));
    if ((iVar1 != 0) && ((*(byte *)((long)param_1 + 0x4e) & 4) == 0)) goto LAB_001207e9;
    lVar3 = param_1[0x35];
    if (lVar3 == 0) {
      uVar2 = dcgettext(0,"multiply claimed block map",5);
      local_88[0] = e2fsck_allocate_block_bitmap(*param_1,uVar2,2,"block_dup_map",param_1 + 0x35);
      if (local_88[0] != 0) {
        local_38 = 3;
        fix_problem(param_1,0x10025,local_88);
        *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
        goto LAB_001207e9;
      }
      lVar3 = param_1[0x35];
    }
  }
  ext2fs_fast_mark_block_bitmap2(lVar3,param_2);
LAB_001207e9:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: process_bad_block @ 0x20890

char process_bad_block(long param_1,ulong *param_2,long param_3,undefined8 param_4,undefined8 param_5,
                 long param_6)

{
  int *piVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  char cVar9;
  uint uVar10;
  
  uVar2 = *param_2;
  if (uVar2 == 0) {
LAB_00120940:
    cVar9 = '\0';
  }
  else {
    lVar3 = *(long *)(param_6 + 0x58);
    lVar4 = *(long *)(param_6 + 0x48);
    uVar10 = *(uint *)(*(long *)(param_1 + 0x20) + 0x14);
    *(undefined4 *)(lVar4 + 8) = 1;
    *(ulong *)(lVar4 + 0x28) = uVar2;
    *(long *)(lVar4 + 0x38) = param_3;
    if ((uVar2 < uVar10) || (uVar6 = ext2fs_blocks_count(), uVar6 <= uVar2)) {
      iVar5 = fix_problem(lVar3,0x10012,lVar4);
joined_r0x00120c36:
      if (iVar5 == 0) goto LAB_00120940;
    }
    else if (param_3 < 0) {
      iVar5 = ext2fs_test_block_bitmap2(*(undefined8 *)(param_6 + 0x50),uVar2);
      if (iVar5 != 0) {
        *(byte *)(param_6 + 4) = *(byte *)(param_6 + 4) | 0x40;
        iVar5 = fix_problem(lVar3,0x1004d,lVar4);
        goto joined_r0x00120c36;
      }
      iVar5 = ext2fs_test_block_bitmap2(*(undefined8 *)(lVar3 + 0x1a0),uVar2);
      if (iVar5 == 0) {
        FUN_00120780(lVar3,uVar2);
        return '\0';
      }
      *(byte *)(param_6 + 4) = *(byte *)(param_6 + 4) | 0x40;
      iVar5 = fix_problem(lVar3,0x10015,lVar4);
      if (iVar5 == 0) {
        return ((*(byte *)(lVar3 + 0x48) & 3) != 0) * '\x02';
      }
    }
    else {
      *(int *)(lVar3 + 0x304) = *(int *)(lVar3 + 0x304) + 1;
      iVar5 = ext2fs_test_block_bitmap2(*(undefined8 *)(lVar3 + 0x1a0),uVar2);
      if (iVar5 == 0) {
        ext2fs_mark_block_bitmap2(*(undefined8 *)(lVar3 + 0x1a0),uVar2);
        return '\0';
      }
      uVar6 = (ulong)*(uint *)(*(long *)(param_1 + 0x20) + 0x14);
      if (*(int *)(param_1 + 0x30) != 0) {
        uVar10 = 0;
        do {
          *(uint *)(lVar4 + 0x40) = uVar10;
          *(ulong *)(lVar4 + 0x28) = uVar2;
          iVar5 = ext2fs_bg_has_super(param_1,uVar10);
          if (iVar5 != 0) {
            if (uVar2 == uVar6) {
              if (uVar10 != 0) {
                fix_problem(lVar3,0x1001b,lVar4);
                return '\0';
              }
              iVar5 = fix_problem(lVar3,0x10019,lVar4);
              goto joined_r0x00120c36;
            }
            if ((uVar6 < uVar2) && (uVar2 <= *(long *)(param_1 + 0x38) + uVar6)) {
              if (uVar10 != 0) {
                fix_problem(lVar3,0x1001c,lVar4);
                return '\0';
              }
              *(ulong *)(lVar4 + 0x28) = *param_2;
              iVar5 = fix_problem(lVar3,0x1001a,lVar4);
              goto joined_r0x00120c36;
            }
          }
          uVar7 = ext2fs_block_bitmap_loc(param_1,uVar10);
          if (uVar7 == uVar2) {
            iVar5 = fix_problem(lVar3,0x1000a,lVar4);
            if (iVar5 != 0) {
              piVar1 = (int *)(*(long *)(lVar3 + 0x1f8) + (ulong)uVar10 * 4);
              *piVar1 = *piVar1 + 1;
              *(int *)(lVar3 + 0x208) = *(int *)(lVar3 + 0x208) + 1;
              return '\0';
            }
            goto LAB_00120940;
          }
          uVar7 = ext2fs_inode_bitmap_loc(param_1,uVar10);
          if (uVar7 == uVar2) {
            iVar5 = fix_problem(lVar3,0x1000b,lVar4);
            if (iVar5 != 0) {
              piVar1 = (int *)(*(long *)(lVar3 + 0x1f0) + (ulong)uVar10 * 4);
              *piVar1 = *piVar1 + 1;
              *(int *)(lVar3 + 0x208) = *(int *)(lVar3 + 0x208) + 1;
              return '\0';
            }
            goto LAB_00120940;
          }
          uVar7 = ext2fs_inode_table_loc(param_1,uVar10);
          if ((uVar7 <= uVar2) &&
             (lVar8 = ext2fs_inode_table_loc(param_1,uVar10),
             uVar2 < (ulong)*(uint *)(param_1 + 0x48) + lVar8)) goto LAB_00120940;
          uVar10 = uVar10 + 1;
          uVar6 = uVar6 + *(uint *)(*(long *)(param_1 + 0x20) + 0x20);
        } while (uVar10 < *(uint *)(param_1 + 0x30));
      }
      lVar8 = *(long *)(param_6 + 0x40);
      if (((*(uint *)(lVar8 + 0x58) != uVar2) && (*(uint *)(lVar8 + 0x5c) != uVar2)) &&
         (*(uint *)(lVar8 + 0x60) != uVar2)) {
        *(undefined4 *)(lVar4 + 0x40) = 0xffffffff;
        fix_problem(lVar3,0x1001d,lVar4);
        goto LAB_00120940;
      }
      *(byte *)(param_6 + 4) = *(byte *)(param_6 + 4) | 0x40;
      iVar5 = fix_problem(lVar3,0x10015,lVar4);
      if (iVar5 == 0) {
        return ((*(byte *)(lVar3 + 0x48) & 3) != 0) * '\x02';
      }
    }
    cVar9 = '\x01';
    *param_2 = 0;
  }
  return cVar9;
}



// Function: process_block @ 0x20c70

undefined8
process_block(long param_1,ulong *param_2,long param_3,long param_4,undefined8 param_5,int *param_6)

{
  long *plVar1;
  long *plVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  byte bVar9;
  uint uVar10;
  ulong extraout_RDX;
  ulong uVar11;
  ulong uVar12;
  
  bVar9 = *(byte *)(param_6 + 1);
  uVar7 = (ulong)bVar9;
  uVar12 = *param_2;
  plVar1 = *(long **)(param_6 + 0x12);
  plVar2 = *(long **)(param_6 + 0x16);
  bVar3 = bVar9 & 1;
  if (((bVar9 & 1) != 0) && (uVar12 == 0 && param_3 == 0)) {
    lVar8 = ext2fs_add_dir_block2(*(undefined8 *)(param_1 + 0x90),*param_6,0,0);
    *plVar1 = lVar8;
    if (lVar8 == 0) {
      *(long *)(param_6 + 10) = *(long *)(param_6 + 10) + 1;
      return 0;
    }
    plVar1[5] = 0;
    param_3 = 0;
    goto LAB_0012111c;
  }
  if (uVar12 == 0) {
    return 0;
  }
  if (((*(long *)(param_6 + 0xe) != 0) && (*param_6 != 7)) &&
     (uVar11 = *(long *)(param_6 + 0xe) + 1, uVar11 != uVar12)) {
    if ((*(byte *)((long)plVar2 + 0x4d) & 8) != 0) {
      iVar5 = 100;
      if (bVar3 == 0) {
        iVar5 = (-(uint)((bVar9 & 2) == 0) & 0xffffffd9) + 0x66;
      }
      lVar8 = plVar1[1];
      uVar6 = dcgettext(0,"%6lu(%c): expecting %6lu got phys %6lu (blkcnt %lld)\n",5);
      __printf_chk(1,uVar6,(int)lVar8,iVar5,uVar11,uVar12,param_3);
    }
    bVar3 = *(byte *)(param_6 + 1);
    uVar10 = bVar3 | 0x10;
    uVar7 = (ulong)uVar10;
    *(char *)(param_6 + 1) = (char)uVar10;
    bVar3 = bVar3 & 1;
  }
  lVar8 = *(long *)(param_1 + 0x20);
  if (bVar3 == 0) {
    iVar5 = 0;
LAB_00120d5c:
    uVar10 = (uint)uVar7;
    if (((uVar7 & 2) != 0) && (*(ulong *)(param_6 + 4) <= *(long *)(param_6 + 2) + 1U)) {
      iVar5 = 0x10045;
    }
  }
  else {
    iVar5 = 0;
    iVar4 = FUN_0011fe40(*(undefined4 *)(lVar8 + 0x60));
    uVar10 = (uint)extraout_RDX;
    if (iVar4 == 0) {
      if (*(int *)(plVar1[3] + 0x6c) == 0) {
        iVar5 = 0;
        if (1 << (0x15U - (char)*(undefined4 *)(lVar8 + 0x18) & 0x1f) < param_3) {
          iVar5 = 0x10044;
        }
      }
      else {
        iVar5 = 0;
      }
    }
    if (*(ulong *)(param_6 + 4) <= *(long *)(param_6 + 2) + 1U) {
      iVar5 = 0x10044;
      uVar7 = extraout_RDX;
      goto LAB_00120d5c;
    }
  }
  if (((uVar10 & 3) == 0) && (0 < param_3)) {
    iVar5 = 0x10046;
    if (uVar12 < *(uint *)(lVar8 + 0x14)) {
LAB_00120f70:
      iVar4 = *param_6;
      iVar5 = 0x1000e;
      goto LAB_00120f79;
    }
LAB_00120d9b:
    uVar7 = ext2fs_blocks_count(lVar8);
    if (uVar7 <= uVar12) goto LAB_00120e91;
    if (-1 < param_3) {
LAB_00120dbf:
      iVar4 = *param_6;
      if (iVar5 == 0) {
        if (iVar4 == 7) goto LAB_001210f0;
        lVar8 = *plVar2;
LAB_00120dd7:
        if ((((*(int *)(lVar8 + 0xc0) == 0) || (uVar7 = *(ulong *)(param_6 + 0xe), uVar7 == 0)) ||
            (bVar9 = (byte)*(int *)(lVar8 + 0xc0),
            uVar12 >> (bVar9 & 0x3f) != uVar7 >> (bVar9 & 0x3f))) ||
           (uVar10 = (1 << (bVar9 & 0x1f)) - 1,
           ((long)(int)uVar10 & uVar12) != (ulong)(uVar10 & (uint)param_3))) goto LAB_00120dff;
        iVar5 = FUN_0011f570(lVar8,uVar7,*(undefined8 *)(param_6 + 6),uVar12,param_3);
        if (iVar5 != 0) {
          plVar1[5] = param_3;
          plVar1[6] = uVar12;
          fix_problem(plVar2,0x10074,plVar1);
          FUN_00120780(plVar2,uVar12);
          FUN_00120780(plVar2,uVar12);
        }
        goto LAB_00120e0f;
      }
      goto LAB_00120f79;
    }
    iVar4 = *param_6;
    if (iVar4 != 7) {
      lVar8 = *plVar2;
      if (uVar12 < *(uint *)(*(long *)(lVar8 + 0x20) + 4)) {
        iVar4 = ext2fs_test_block_bitmap2(plVar2[0x72],uVar12);
        if (iVar4 == 0) goto LAB_00120dbf;
        goto LAB_00120ed2;
      }
      if (iVar5 == 0) goto LAB_00120dd7;
      goto LAB_00120f79;
    }
    if (iVar5 != 0) goto LAB_00120f0e;
LAB_001210f0:
    if (param_3 == -2) {
LAB_00120dff:
      FUN_00120780(plVar2,uVar12);
    }
    *(long *)(param_6 + 2) = *(long *)(param_6 + 2) + 1;
LAB_00120e0f:
    if (-1 < param_3) {
      *(long *)(param_6 + 6) = param_3;
    }
    *(ulong *)(param_6 + 0xe) = uVar12;
    uVar6 = 0;
  }
  else {
    if (*(uint *)(lVar8 + 0x14) <= uVar12) goto LAB_00120d9b;
LAB_00120e91:
    iVar4 = *param_6;
    if (param_3 < 0) {
      if (iVar4 != 7) {
        if (uVar12 < *(uint *)(*(long *)(*plVar2 + 0x20) + 4)) {
          iVar5 = ext2fs_test_block_bitmap2(plVar2[0x72],uVar12);
          if (iVar5 != 0) {
            iVar5 = 0x1000e;
LAB_00120ed2:
            plVar1[5] = uVar12;
            fix_problem(plVar2,0x10071,plVar1);
            if ((*(byte *)((long)plVar2 + 0x4c) & 8) == 0) {
              *(uint *)(plVar2 + 9) = *(uint *)(plVar2 + 9) | 8;
            }
            goto LAB_00120dbf;
          }
          goto LAB_00120f70;
        }
        goto LAB_00121140;
      }
      iVar5 = 0x1000e;
LAB_00120f0e:
      param_6[0xc] = param_6[0xc] + 1;
    }
    else {
LAB_00121140:
      iVar5 = 0x1000e;
LAB_00120f79:
      param_6[0xc] = param_6[0xc] + 1;
      if (((param_4 != 0) && (iVar4 != 7)) &&
         (iVar4 = ext2fs_test_block_bitmap2(plVar2[0x72]), iVar4 != 0)) {
        *param_2 = 0;
        return 0;
      }
    }
    if (((*(byte *)(param_6 + 1) & 8) == 0) &&
       ((param_6[0xc] * -0x55555555 + 0x2aaaaaa8U >> 2 | param_6[0xc] * -0x40000000) < 0x15555555))
    {
      iVar4 = fix_problem(plVar2,0x10011,plVar1);
      if (iVar4 != 0) {
        *(byte *)(param_6 + 1) = *(byte *)(param_6 + 1) | 4;
        return 2;
      }
      iVar4 = fix_problem(plVar2,0x1002d,plVar1);
      if (iVar4 != 0) {
        *(byte *)(param_6 + 1) = *(byte *)(param_6 + 1) | 8;
        set_latch_flags(0x10,8,0);
      }
    }
    plVar1[5] = uVar12;
    plVar1[7] = param_3;
    iVar4 = fix_problem(plVar2,iVar5,plVar1);
    if (iVar4 == 0) {
      return 0;
    }
    *param_2 = 0;
    uVar12 = 0;
    uVar6 = 1;
    *(byte *)(param_6 + 1) = *(byte *)(param_6 + 1) | 0x80;
    if (iVar5 == 0x10044) {
      return 1;
    }
  }
  if (param_3 < 0) {
    return uVar6;
  }
  if ((*(byte *)(param_6 + 1) & 1) == 0) {
    return uVar6;
  }
  do {
    lVar8 = *(long *)(param_6 + 10);
    *(long *)(param_6 + 10) = lVar8 + 1;
    if (param_3 <= lVar8 + 1) {
      lVar8 = ext2fs_add_dir_block2(*(undefined8 *)(param_1 + 0x90),*param_6,uVar12,param_3);
      *plVar1 = lVar8;
      if (lVar8 == 0) {
        return uVar6;
      }
      plVar1[5] = uVar12;
      goto LAB_0012111c;
    }
    lVar8 = ext2fs_add_dir_block2(*(undefined8 *)(param_1 + 0x90),*param_6,0);
    *plVar1 = lVar8;
  } while (lVar8 == 0);
  plVar1[5] = 0;
  param_3 = *(long *)(param_6 + 10);
LAB_0012111c:
  plVar1[10] = param_3;
  fix_problem(plVar2,0x1002b,plVar1);
  *(uint *)(plVar2 + 9) = *(uint *)(plVar2 + 9) | 1;
  return 2;
}



// Function: mark_blocks_used @ 0x21240

void mark_blocks_used(long *param_1,long param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = ext2fs_test_block_bitmap_range2(param_1[0x34]);
  if (iVar1 == 0) {
    uVar2 = 0;
    if (param_3 != 0) {
      do {
        FUN_00120780(param_1,(ulong)uVar2 + param_2);
        uVar2 = uVar2 + (1 << ((byte)*(undefined4 *)(*param_1 + 0xc0) & 0x1f));
      } while (uVar2 < param_3);
    }
    return;
  }
  ext2fs_mark_block_bitmap_range2(param_1[0x34],param_2,param_3);
  return;
}



// Function: scan_extent_node @ 0x212c0

void scan_extent_node(long *param_1,long *param_2,int *param_3,ulong param_4,ulong param_5,ulong param_6
                 ,undefined8 param_7,uint param_8)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  char *pcVar7;
  ulong uVar8;
  bool bVar9;
  ulong extraout_RDX;
  ulong uVar10;
  undefined8 uVar11;
  uint uVar12;
  ulong uVar13;
  byte bVar14;
  byte bVar15;
  long in_FS_OFFSET;
  bool bVar16;
  bool bVar17;
  uint local_104;
  ulong local_f8;
  ulong local_f0;
  ulong local_c8;
  ulong local_c0;
  uint local_b8;
  uint local_b4;
  undefined1 local_a8 [4];
  int local_a4;
  int local_a0;
  int local_9c;
  undefined1 local_78 [4];
  int local_74;
  long local_40;
  
  lVar5 = *param_2;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar4 = ext2fs_extent_get_info(param_7,local_a8);
  *param_2 = lVar4;
  if (lVar4 == 0) {
    if (((*(byte *)((long)param_1 + 0x4d) & 0x80) == 0) && (param_3[0x1b] == 0)) {
      piVar1 = param_3 + (long)local_a4 * 2 + 0x1c;
      *piVar1 = *piVar1 + local_a0;
      iVar3 = piVar1[1] + local_9c;
      if ((local_a0 < local_9c) && (local_a4 != 0)) {
        iVar3 = iVar3 + -1;
      }
      piVar1[1] = iVar3;
    }
    bVar16 = lVar5 == 0x7f2bb794;
    lVar5 = ext2fs_extent_get(param_7,3);
    *param_2 = lVar5;
    bVar9 = lVar5 == 0x7f2bb794 || lVar5 == 0;
    local_f0 = param_4;
    if (lVar5 == 0x7f2bb794 || lVar5 == 0) {
      do {
        uVar13 = local_c8;
        iVar3 = local_a0 + -1;
        bVar17 = local_a0 < 1;
        local_a0 = iVar3;
        if (bVar17) break;
        uVar2 = *(ushort *)param_2[3];
        param_2[6] = local_c0;
        uVar12 = local_b4 & 1;
        param_2[10] = (ulong)local_b8;
        uVar2 = uVar2 & 0xf000;
        param_2[5] = local_c8;
        bVar17 = uVar2 == 0x4000;
        lVar5 = local_c0 + local_b8;
        local_f8 = lVar5 - 1;
        param_2[7] = lVar5;
        bVar14 = (byte)param_8 & 1;
        local_104 = uVar12;
        if (((local_c8 == 0) || (local_c8 < *(uint *)(*(long *)(*param_1 + 0x20) + 0x14))) ||
           (uVar8 = ext2fs_blocks_count(), uVar8 <= uVar13)) {
          uVar11 = 0x10058;
          bVar15 = bVar14 & bVar17;
          bVar14 = 0;
          if (bVar15 == 0) {
LAB_001213fd:
            if (param_8 == 0) goto LAB_0012140f;
          }
LAB_0012147f:
          iVar3 = fix_problem(param_1,uVar11,param_2);
          if (iVar3 == 0) goto LAB_00121686;
          if ((int)param_1[0x41] == 0) {
            e2fsck_read_bitmaps(param_1);
            *(byte *)(param_3 + 1) = *(byte *)(param_3 + 1) | 0x80;
            lVar5 = ext2fs_extent_delete(param_7,0);
            *param_2 = lVar5;
            if (lVar5 != 0) {
              param_2[0xc] = (long)"ext2fs_extent_delete";
              goto LAB_001216e8;
            }
            lVar5 = ext2fs_extent_fix_parents(param_7);
            *param_2 = lVar5;
            if ((lVar5 != 0) && (lVar5 != 0x7f2bb780)) {
LAB_00121b47:
              pcVar7 = "ext2fs_extent_fix_parents";
LAB_00121afc:
              param_2[0xc] = (long)pcVar7;
              goto LAB_001216e8;
            }
            lVar5 = ext2fs_extent_get(param_7,0,&local_c8);
            *param_2 = lVar5;
            if (lVar5 == 0x7f2bb780) goto LAB_0012198e;
            bVar16 = false;
          }
          else {
            lVar5 = ext2fs_extent_get(param_7,5,&local_c8);
            *param_2 = lVar5;
            *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 8;
            if (lVar5 == 0x7f2bb780) {
LAB_0012198e:
              *param_2 = 0;
              if (bVar16) goto LAB_001216b9;
              goto LAB_001216e8;
            }
          }
        }
        else {
          if (local_c0 < local_f0) {
            uVar11 = 0x1005e;
            if ((bVar14 & bVar17) == 0) {
              bVar14 = 0;
              goto LAB_001213fd;
            }
            goto LAB_0012147f;
          }
          if (((param_5 != 0) && (param_5 < local_f8)) &&
             ((local_f8 <= param_6 ||
              (((local_b4 & 2) == 0 && ((*(byte *)(param_2[3] + 0x22) & 0x10) == 0)))))) {
            uVar11 = 0x1006e;
            if ((bVar14 & bVar17) == 0) {
              bVar14 = 0;
              goto LAB_001213fd;
            }
            goto LAB_0012147f;
          }
          if (uVar12 != 0) {
            if (local_b8 == 0) {
              if ((!bVar17) || (uVar11 = 0x10066, (param_8 & 1) == 0)) {
                uVar11 = 0x10066;
LAB_00121f25:
                if (param_8 == 0) {
                  lVar5 = *(long *)(param_3 + 0xe);
                  if (lVar5 != 0) {
                    bVar14 = 0;
                    goto LAB_00121721;
                  }
                  goto LAB_001217fd;
                }
              }
            }
            else {
              uVar13 = local_b8 + local_c8;
              uVar8 = ext2fs_blocks_count(*(undefined8 *)(*param_1 + 0x20));
              if (uVar13 <= uVar8) goto LAB_00121c19;
              if ((!bVar17) || (uVar11 = 0x10059, (param_8 & 1) == 0)) {
                uVar11 = 0x10059;
                goto LAB_00121f25;
              }
            }
            goto LAB_0012147f;
          }
LAB_00121c19:
          bVar15 = (byte)uVar12 & bVar17;
          if (bVar15 == 0) {
            if ((byte)uVar12 == 0) {
              if ((bVar17 & bVar14) != 0) goto LAB_00121dd9;
              bVar15 = 0;
LAB_00121fa5:
              local_104 = (uint)bVar15;
              bVar14 = 0;
            }
            else {
              uVar13 = (ulong)local_b8;
              bVar14 = bVar14 & bVar17;
              if (local_b8 != 0) goto LAB_00121d96;
LAB_00121e08:
              local_104 = (uint)bVar9;
              bVar14 = 0;
            }
          }
          else {
            uVar13 = (ulong)local_b8;
            if (*(int *)(param_2[3] + 0x6c) == 0) {
              lVar5 = *(long *)(*param_1 + 0x20);
              iVar3 = FUN_0011fe40(*(undefined4 *)(lVar5 + 0x60));
              uVar13 = extraout_RDX;
              if ((iVar3 == 0) &&
                 ((ulong)(uint)(1 << (0x15U - (char)*(undefined4 *)(lVar5 + 0x18) & 0x1f)) <
                  (extraout_RDX & 0xffffffff) + local_c0)) {
                if (param_8 == 0) goto LAB_00121fa5;
                uVar11 = 0x10044;
                goto LAB_0012147f;
              }
            }
            if ((int)uVar13 == 0) {
              if (bVar14 == 0) goto LAB_00121e08;
            }
            else {
LAB_00121d96:
              if (local_c0 < *(ulong *)(param_3 + 0x18)) {
                uVar11 = 0x1007d;
                local_104 = (uint)bVar9;
                goto LAB_001213fd;
              }
              if (*(ulong *)(param_3 + 0x18) < uVar13 + local_c0) {
                *(ulong *)(param_3 + 0x18) = uVar13 + local_c0;
              }
              if (bVar14 == 0) {
                local_104 = (uint)bVar9;
                goto LAB_0012140f;
              }
            }
            local_104 = (uint)bVar9;
LAB_00121dd9:
            bVar14 = bVar9;
            if (((local_b4 & 2) != 0) && (iVar3 = fix_problem(param_1,0x10073,param_2), iVar3 != 0))
            {
              *(byte *)(param_3 + 1) = *(byte *)(param_3 + 1) | 0x80;
              local_b4 = local_b4 & 0xfffffffd;
              lVar5 = ext2fs_extent_replace(param_7,0,&local_c8);
              *param_2 = lVar5;
              if (lVar5 != 0) goto LAB_001216e8;
              bVar16 = false;
            }
          }
LAB_0012140f:
          uVar8 = local_c0;
          uVar13 = local_c8;
          if (uVar12 == 0) {
            if (((*param_3 != 7) && (local_c8 < *(uint *)(*(long *)(*param_1 + 0x20) + 4))) &&
               (iVar3 = ext2fs_test_block_bitmap2(param_1[0x72],local_c8), iVar3 != 0)) {
              param_2[5] = uVar13;
              fix_problem(param_1,0x10071,param_2);
              if ((*(byte *)((long)param_1 + 0x4c) & 8) == 0) {
                *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 8;
              }
              lVar5 = ext2fs_extent_get(param_7,0xc,&local_c8);
              uVar11 = 0;
              *param_2 = lVar5;
              if ((lVar5 == 0) || (lVar5 == 0x7f2bb794)) goto LAB_001215be;
              pcVar7 = "EXT2_EXTENT_DOWN";
              goto LAB_00121afc;
            }
            lVar5 = ext2fs_extent_get(param_7,0xc,&local_c8);
            *param_2 = lVar5;
            if ((lVar5 == 0) || (lVar5 == 0x7f2bb794)) {
              uVar11 = 1;
LAB_001215be:
              if (local_c0 == uVar8) goto LAB_00121629;
              lVar5 = ext2fs_extent_get_info(param_7,local_78);
              *param_2 = lVar5;
              if (lVar5 != 0) {
                pcVar7 = "ext2fs_extent_get_info";
                goto LAB_00121afc;
              }
              param_2[5] = uVar8;
              param_2[6] = local_c0;
              param_2[10] = (long)(local_74 + -1);
              iVar3 = fix_problem(param_1,0x1006d,param_2);
              uVar8 = local_c0;
              if (iVar3 != 0) {
                *(byte *)(param_3 + 1) = *(byte *)(param_3 + 1) | 0x80;
                lVar5 = ext2fs_extent_fix_parents(param_7);
                *param_2 = lVar5;
                uVar8 = local_c0;
                if (lVar5 == 0) goto LAB_00121629;
                goto LAB_00121b47;
              }
LAB_00121629:
              scan_extent_node(param_1,param_2,param_3,uVar8,local_f8,param_6,param_7,uVar11);
              if (*param_2 == 0) {
                lVar5 = ext2fs_extent_get(param_7,0xb,&local_c8);
                *param_2 = lVar5;
                if (lVar5 == 0) {
                  FUN_00120780(param_1,uVar13);
                  *(long *)(param_3 + 2) = *(long *)(param_3 + 2) + 1;
                  goto LAB_00121686;
                }
                param_2[0xc] = (long)"EXT2_EXTENT_UP";
              }
            }
            else {
              param_2[0xc] = (long)"EXT2_EXTENT_DOWN";
              if (lVar5 == 0x7f2bb777) {
                uVar11 = 0x1005f;
                goto LAB_0012147f;
              }
            }
            goto LAB_001216e8;
          }
          lVar5 = *(long *)(param_3 + 0xe);
          if (lVar5 != 0) {
LAB_00121721:
            if (lVar5 + 1U != local_c8) {
              if ((*(byte *)((long)param_1 + 0x4d) & 8) != 0) {
                iVar3 = 100;
                if ((*(byte *)(param_3 + 1) & 1) == 0) {
                  iVar3 = (-(uint)((*(byte *)(param_3 + 1) & 2) == 0) & 0xffffffd9) + 0x66;
                }
                __printf_chk(1,"%6lu(%c): expecting %6lu actual extent phys %6lu log %lu len %lu\n",
                             (int)param_2[1],iVar3,lVar5 + 1U,local_c8,local_c0,local_b8);
              }
              *(byte *)(param_3 + 1) = *(byte *)(param_3 + 1) | 0x10;
            }
          }
          if (bVar14 != 0) {
            uVar13 = *(long *)(param_3 + 6) + 1;
            if (uVar13 < local_c0) {
              iVar3 = 1 << ((byte)*(undefined4 *)(*param_1 + 0xc0) & 0x1f);
              if (1 < iVar3) {
                uVar13 = (long)iVar3 + *(long *)(param_3 + 6) & (long)-iVar3 |
                         (long)(iVar3 + -1) & local_c8;
              }
              param_2[6] = uVar13;
              param_2[5] = local_c0;
              iVar3 = fix_problem(param_1,0x10072,param_2);
              if (iVar3 != 0) {
                *(byte *)(param_3 + 1) = *(byte *)(param_3 + 1) | 0x80;
                local_c0 = uVar13;
                lVar5 = ext2fs_extent_replace(param_7,0,&local_c8);
                *param_2 = lVar5;
                if (lVar5 == 0) {
                  lVar5 = ext2fs_extent_fix_parents(param_7);
                  *param_2 = lVar5;
                  if (lVar5 == 0) {
                    lVar5 = ext2fs_extent_goto(param_7,local_c0);
                    *param_2 = lVar5;
                    if (lVar5 == 0) {
                      bVar16 = false;
                      local_f8 = (local_c0 - 1) + (ulong)local_b8;
                      goto LAB_001217fd;
                    }
                  }
LAB_00121ca2:
                  fix_problem(param_1,0x1002b,param_2);
                  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
                  goto LAB_001216e8;
                }
                *param_2 = 0;
              }
            }
          }
LAB_001217fd:
          uVar12 = local_b8;
          uVar13 = local_c0;
          if (uVar2 == 0x4000) {
            while( true ) {
              lVar5 = *(long *)(param_3 + 10);
              lVar4 = *param_1;
              *(long *)(param_3 + 10) = lVar5 + 1;
              if ((long)local_c0 <= lVar5 + 1) break;
              lVar5 = ext2fs_add_dir_block2(*(undefined8 *)(lVar4 + 0x90),*param_3,0);
              *param_2 = lVar5;
              if (lVar5 != 0) {
                param_2[5] = 0;
                param_2[10] = *(long *)(param_3 + 10);
                goto LAB_00121ca2;
              }
            }
            if (local_b8 == 0) {
LAB_00121e9e:
              lVar5 = *param_1;
              uVar8 = local_c8;
LAB_00121ea7:
              uVar10 = 0;
            }
            else {
              uVar12 = 0;
              while( true ) {
                uVar8 = (ulong)uVar12;
                lVar5 = ext2fs_add_dir_block2
                                  (*(undefined8 *)(lVar4 + 0x90),(int)param_2[1],local_c8 + uVar8,
                                   uVar8 + local_c0);
                uVar13 = local_c0;
                *param_2 = lVar5;
                if (lVar5 != 0) {
                  param_2[5] = local_c8 + uVar8;
                  param_2[10] = uVar8 + local_c0;
                  goto LAB_00121ca2;
                }
                uVar12 = uVar12 + 1;
                if (local_b8 <= uVar12) break;
                lVar4 = *param_1;
              }
              if (local_b8 == 0) goto LAB_00121e9e;
              uVar10 = (ulong)local_b8;
              lVar5 = *param_1;
              *(ulong *)(param_3 + 10) = (local_c0 - 1) + uVar10;
              uVar8 = local_c8;
              iVar3 = FUN_0011f570(lVar5,*(undefined8 *)(param_3 + 0xe),*(undefined8 *)(param_3 + 6)
                                   ,local_c8);
              if (iVar3 != 0) goto LAB_00121b91;
            }
          }
          else {
            lVar5 = *param_1;
            uVar8 = local_c8;
            iVar3 = FUN_0011f570(lVar5,*(undefined8 *)(param_3 + 0xe),*(undefined8 *)(param_3 + 6),
                                 local_c8);
            if (iVar3 != 0) {
              if (uVar12 == 0) goto LAB_00121ea7;
LAB_00121b91:
              uVar12 = 0;
              do {
                uVar10 = (ulong)uVar12;
                uVar12 = uVar12 + 1;
                param_2[6] = uVar8 + uVar10;
                param_2[5] = uVar13 + uVar10;
                fix_problem(param_1,0x10074,param_2);
                FUN_00120780(param_1,local_c8 + uVar10);
                FUN_00120780(param_1,uVar10 + local_c8);
                uVar13 = local_c0;
                uVar8 = local_c8;
              } while (uVar12 < local_b8);
              lVar5 = *param_1;
              uVar12 = local_b8;
            }
            uVar10 = (ulong)uVar12;
          }
          bVar14 = (byte)*(int *)(lVar5 + 0xc0);
          uVar13 = uVar8 >> (bVar14 & 0x3f);
          if (((*(int *)(lVar5 + 0xc0) == 0) || (*(ulong *)(param_3 + 0xe) == 0)) ||
             (uVar6 = *(ulong *)(param_3 + 0xe) >> (bVar14 & 0x3f), uVar6 != uVar13)) {
            uVar13 = uVar13 << (bVar14 & 0x3f);
          }
          else {
            uVar13 = uVar6 + 1 << (bVar14 & 0x3f);
          }
          lVar5 = (uVar8 - 1) + uVar10;
          if (uVar13 < uVar10 + uVar8) {
            FUN_00121240(param_1,uVar13,((int)uVar10 + (int)uVar8) - (int)uVar13);
            lVar5 = (local_c8 - 1) + (ulong)local_b8;
            uVar8 = (ulong)(1 << ((byte)*(undefined4 *)(*param_1 + 0xc0) & 0x1f));
            *(ulong *)(param_3 + 2) =
                 *(long *)(param_3 + 2) + (((uVar8 + lVar5) - uVar13) / uVar8 & 0xffffffff);
          }
          local_f0 = local_f8;
          *(long *)(param_3 + 0xe) = lVar5;
          *(ulong *)(param_3 + 6) = local_f8;
          if ((uVar2 == 0x4000) || ((char)local_104 == '\0')) {
          }
          else if ((local_b4 & 2) == 0) {
            *(ulong *)(param_3 + 8) = local_f8;
          }
LAB_00121686:
          lVar5 = ext2fs_extent_get(param_7,5,&local_c8);
          *param_2 = lVar5;
        }
      } while ((lVar5 == 0) || (lVar5 == 0x7f2bb794));
    }
    if (bVar16) {
LAB_001216b9:
      iVar3 = fix_problem(param_1,0x1006a,param_2);
      if (iVar3 != 0) {
        *(byte *)(param_3 + 1) = *(byte *)(param_3 + 1) | 0x80;
        lVar5 = ext2fs_extent_replace(param_7,0,&local_c8);
        *param_2 = lVar5;
        goto LAB_001216e8;
      }
    }
    if (*param_2 == 0x7f2bb77c) {
      *param_2 = 0;
    }
  }
LAB_001216e8:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: handle_htree @ 0x22000

ulong handle_htree(long *param_1,long *param_2,undefined4 param_3,ushort *param_4,long param_5)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  byte extraout_DL;
  byte extraout_DL_00;
  byte bVar8;
  uint uVar9;
  long in_FS_OFFSET;
  ulong local_48;
  
  lVar7 = *param_1;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if ((((*param_4 & 0xf000) == 0x4000) || (iVar3 = fix_problem(param_1,0x10048,param_2), iVar3 == 0)
      ) && ((iVar3 = FUN_00121ff0(*(undefined4 *)(*(long *)(lVar7 + 0x20) + 0x5c)), iVar3 != 0 ||
            (iVar3 = fix_problem(param_1,0x10047,param_2), iVar3 == 0)))) {
    lVar5 = ext2fs_bmap2(lVar7,param_3,param_4,0,0,0,0);
    *param_2 = lVar5;
    if ((((lVar5 != 0) || (local_48 == 0)) || (local_48 < *(uint *)(*(long *)(lVar7 + 0x20) + 0x14))
        ) || (uVar6 = ext2fs_blocks_count(), uVar6 <= local_48)) {
      iVar3 = fix_problem(param_1,0x10049,param_2);
      uVar6 = (ulong)(iVar3 != 0);
      goto LAB_001220bd;
    }
    lVar5 = io_channel_read_blk64(*(undefined8 *)(lVar7 + 8),local_48,1,param_5);
    if (((lVar5 == 0) || (iVar3 = fix_problem(param_1,0x10049,param_2), iVar3 == 0)) &&
       (((*(int *)(param_5 + 0x18) == 0 && (7 < *(byte *)(param_5 + 0x1d))) ||
        (iVar3 = fix_problem(param_1,0x10049,param_2), iVar3 == 0)))) {
      bVar8 = *(byte *)(param_5 + 0x1c);
      param_2[10] = (ulong)bVar8;
      if (((bVar8 < 3) || (bVar8 == 6)) ||
         (iVar3 = fix_problem(param_1,0x1004a,param_2), iVar3 == 0)) {
        iVar3 = FUN_0011e110(param_4);
        if (iVar3 == 0) {
          if (*(char *)(param_5 + 0x1c) == '\x06') {
            iVar3 = fix_problem(param_1,0x1008e,param_2);
            goto joined_r0x00122297;
          }
        }
        else if (*(char *)(param_5 + 0x1c) != '\x06') {
          iVar3 = fix_problem(param_1,0x1008d,param_2);
joined_r0x00122297:
          if (iVar3 != 0) goto LAB_001220f5;
        }
        if (((*(byte *)(param_5 + 0x1f) & 1) == 0) ||
           (iVar3 = fix_problem(param_1,0x1004b,param_2), iVar3 == 0)) {
          bVar8 = *(byte *)(param_5 + 0x1e);
          uVar6 = (ulong)bVar8;
          param_2[10] = uVar6;
          if (3 < bVar8) {
            iVar3 = fix_problem(param_1,0x1004c,param_2);
            if (iVar3 != 0) goto LAB_001220f5;
            uVar6 = (ulong)*(byte *)(param_5 + 0x1e);
          }
          lVar7 = *(long *)(lVar7 + 0x20);
          uVar9 = (uint)uVar6;
          uVar4 = FUN_0011fe50(lVar7);
          bVar8 = extraout_DL;
          if ((uVar4 < uVar9) &&
             (iVar3 = FUN_0011fe40(*(undefined4 *)(lVar7 + 0x60)), bVar8 = extraout_DL_00,
             iVar3 == 0)) {
            lVar5 = param_2[3];
            cVar2 = (char)*(undefined4 *)(lVar7 + 0x18);
            iVar3 = 1 << (cVar2 + 0x11U & 0x1f);
            iVar3 = (iVar3 + -1) * (iVar3 + -2);
            if ((CONCAT44(*(undefined4 *)(lVar5 + 0x6c),*(undefined4 *)(lVar5 + 4)) <
                 (ulong)(uint)(iVar3 << (cVar2 + 0x14U & 0x1f))) &&
               (*(uint *)(lVar5 + 0x1c) < (uint)(iVar3 << (cVar2 + 0xbU & 0x1f)))) {
              iVar3 = fix_problem(param_1,0x1004c,param_2);
              if (iVar3 != 0) goto LAB_001220f5;
              bVar8 = *(byte *)(param_5 + 0x1e);
            }
          }
          if ((2 < bVar8) ||
             (uVar6 = FUN_0011e130(CONCAT44(*(undefined4 *)(param_4 + 0x36),
                                            *(undefined4 *)(param_4 + 2))), (int)uVar6 != 0)) {
            *(int *)((long)param_1 + 0x324) = *(int *)((long)param_1 + 0x324) + 1;
            uVar6 = 0;
          }
          goto LAB_001220bd;
        }
      }
    }
  }
LAB_001220f5:
  uVar6 = 1;
LAB_001220bd:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_pass1_check_device_inode @ 0x22d20

undefined8 e2fsck_pass1_check_device_inode(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  int *piVar2;
  
  uVar1 = 0;
  if (((*(uint *)(param_2 + 0x20) & 0x81000) == 0) &&
     (uVar1 = 1, (*(uint *)(param_2 + 0x20) & 0x30) != 0)) {
    piVar2 = (int *)(param_2 + 0x38);
    while (*piVar2 == 0) {
      piVar2 = piVar2 + 1;
      if (piVar2 == (int *)(param_2 + 100)) {
        return 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



// Function: e2fsck_pass1_check_symlink @ 0x22d70

bool e2fsck_pass1_check_symlink(long param_1,ulong param_2,long param_3,ushort *param_4)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  int *piVar4;
  ulong uVar5;
  size_t sVar6;
  uint uVar7;
  ulong uVar8;
  long in_FS_OFFSET;
  bool bVar9;
  undefined8 local_90;
  ulong local_88;
  long local_80;
  int local_78;
  ulong local_68;
  int local_60;
  int local_58;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (((*(int *)(param_3 + 0x6c) == 0) && (*(int *)(param_3 + 4) != 0)) &&
     (uVar2 = *(uint *)(param_3 + 0x20), (uVar2 & 0x1000) == 0)) {
    if ((uVar2 & 0x10000000) == 0) {
      iVar1 = ext2fs_is_fast_symlink(param_3);
      if (iVar1 == 0) {
        bVar9 = false;
        if ((*(byte *)(param_3 + 0x22) & 8) != 0) {
          lVar3 = ext2fs_extent_open2(param_1,param_2 & 0xffffffff,param_3,&local_90);
          if (lVar3 != 0) goto LAB_00122de3;
          lVar3 = ext2fs_extent_get_info(local_90,&local_68);
          if (((lVar3 == 0) && (local_60 == 1)) && (local_58 == 0)) {
            lVar3 = ext2fs_extent_get(local_90,1,&local_88);
            if ((lVar3 == 0 && local_80 == 0) && (local_78 == 1)) {
              ext2fs_extent_free(local_90);
              uVar8 = local_88;
              goto LAB_00122e93;
            }
          }
          ext2fs_extent_free(local_90);
          goto LAB_00122de3;
        }
        piVar4 = (int *)(param_3 + 0x2c);
        do {
          if (*piVar4 != 0) goto LAB_00122de3;
          piVar4 = piVar4 + 1;
          uVar8 = (ulong)*(uint *)(param_3 + 0x28);
        } while ((int *)(param_3 + 100) != piVar4);
LAB_00122e93:
        if (uVar8 < *(uint *)(*(long *)(param_1 + 0x20) + 0x14)) goto LAB_00122de3;
        uVar5 = ext2fs_blocks_count();
        if (uVar5 <= uVar8) goto LAB_00122de3;
        lVar3 = io_channel_read_blk64(*(undefined8 *)(param_1 + 8),uVar8,1,param_4);
        if (lVar3 != 0) goto LAB_00122de3;
        uVar7 = *(uint *)(param_1 + 0x28);
        uVar2 = *(uint *)(param_3 + 0x20);
      }
      else {
        uVar2 = *(uint *)(param_3 + 0x20);
        if ((uVar2 & 0x80000) != 0) goto LAB_00122de0;
        param_4 = (ushort *)(param_3 + 0x28);
        uVar7 = 0x3c;
      }
      if ((uVar2 & 0x800) == 0) {
        sVar6 = strnlen((char *)param_4,(ulong)uVar7);
        uVar2 = (uint)sVar6;
      }
      else {
        uVar2 = *param_4 + 2;
      }
      if (uVar2 < uVar7) {
        bVar9 = *(uint *)(param_3 + 4) == uVar2;
        goto LAB_00122de3;
      }
    }
    else if ((uVar2 & 0x80000) == 0) {
      lVar3 = ext2fs_inline_data_size(param_1,param_2,&local_68);
      if (lVar3 == 0) {
        bVar9 = *(uint *)(param_3 + 4) == local_68;
        goto LAB_00122de3;
      }
    }
  }
LAB_00122de0:
  bVar9 = false;
LAB_00122de3:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_setup_icount @ 0x22f80

void e2fsck_setup_icount(long *param_1,undefined8 param_2,uint param_3,undefined8 param_4,
                        undefined8 *param_5)

{
  int iVar1;
  long lVar2;
  long in_FS_OFFSET;
  uint local_58;
  undefined2 local_54 [2];
  uint local_50;
  int local_4c;
  char *local_48;
  long local_40;
  
  lVar2 = param_1[0x6c];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  *param_5 = 0;
  profile_get_string(lVar2,"scratch_files","directory",0,0,&local_48);
  profile_get_uint(param_1[0x6c],"scratch_files","numdirs_threshold",0,0,&local_58);
  profile_get_boolean(param_1[0x6c],"scratch_files","icount",0,1,&local_4c);
  lVar2 = ext2fs_get_num_dirs(*param_1,&local_50);
  if (lVar2 != 0) {
    local_50 = 0x400;
  }
  if ((local_4c != 0) && (local_48 != (char *)0x0)) {
    iVar1 = access(local_48,2);
    if ((iVar1 == 0) && ((local_58 == 0 || (local_58 < local_50)))) {
      lVar2 = ext2fs_create_icount_tdb(*param_1,local_48,param_3,param_5);
      if (lVar2 == 0) goto LAB_001230c1;
    }
  }
  e2fsck_set_bitmap_type(*param_1,2,param_2,local_54);
  if ((*(byte *)((long)param_1 + 0x4e) & 2) != 0) {
    param_3 = param_3 | 2;
  }
  ext2fs_create_icount2(*param_1,param_3,0,param_4,param_5);
  *(undefined2 *)(*param_1 + 0xc4) = local_54[0];
LAB_001230c1:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_clear_inode @ 0x230f0

void e2fsck_clear_inode(long *param_1,ulong param_2,undefined8 *param_3,uint param_4,
                       undefined8 param_5)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  lVar1 = param_1[0x38];
  *(undefined4 *)(param_3 + 4) = 0;
  *(undefined2 *)((long)param_3 + 0x1a) = 0;
  ext2fs_icount_store(lVar1,param_2,0);
  *(int *)((long)param_3 + 0x14) = (int)param_1[0x69];
  uVar2 = 0xb;
  if (*(int *)(*(long *)(*param_1 + 0x20) + 0x4c) != 0) {
    uVar2 = *(uint *)(*(long *)(*param_1 + 0x20) + 0x54);
  }
  if ((uint)param_2 < uVar2) {
    param_3[0xb] = 0;
    *(undefined4 *)(param_3 + 0xc) = 0;
    *(undefined1 (*) [16])(param_3 + 5) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(param_3 + 7) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(param_3 + 9) = (undefined1  [16])0x0;
  }
  ext2fs_unmark_inode_bitmap2(param_1[0x2f],param_2 & 0xffffffff);
  ext2fs_unmark_inode_bitmap2(param_1[0x2d],param_2 & 0xffffffff);
  if (param_1[0x32] != 0) {
    ext2fs_unmark_inode_bitmap2(param_1[0x32],param_2 & 0xffffffff);
  }
  if (param_1[0x2e] != 0) {
    ext2fs_unmark_inode_bitmap2(param_1[0x2e],param_2 & 0xffffffff);
  }
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | param_4;
  if ((uint)param_2 == 1) {
    *param_3 = 0;
    param_3[0xf] = 0;
    puVar4 = (undefined8 *)((ulong)(param_3 + 1) & 0xfffffffffffffff8);
    for (uVar3 = (ulong)(((int)param_3 -
                         (int)(undefined8 *)((ulong)(param_3 + 1) & 0xfffffffffffffff8)) + 0x80U >>
                        3); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
    }
  }
  e2fsck_write_inode(param_1,param_2 & 0xffffffff,param_3,param_5);
  return;
}



// Function: fix_inline_data_extents_file @ 0x23210

undefined8
fix_inline_data_extents_file(long *param_1,undefined4 param_2,ushort *param_3,int param_4,undefined8 param_5)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ushort uVar5;
  ulong uVar6;
  
  lVar1 = *param_1;
  iVar2 = FUN_001203c0(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x60));
  if ((iVar2 != 0) || (iVar2 = FUN_0011fe30(), iVar2 != 0)) {
    uVar5 = *param_3 & 0xf000;
    if (((*param_3 & 0xb000) == 0x2000 || uVar5 == 0x1000) || (uVar5 == 0xc000)) {
      FUN_0011e660(param_1,param_5);
      return 0;
    }
    lVar4 = ext2fs_extent_header_verify(param_3 + 0x14,0x3c);
    if ((lVar4 == 0) && (iVar2 = fix_problem(param_1,0x10077,param_5), iVar2 != 0)) {
      uVar3 = *(uint *)(param_3 + 0x10) & 0xefffffff;
    }
    else {
      uVar6 = 0x3c;
      if (0x80 < param_4) {
        uVar6 = (ulong)(int)((param_4 - (uint)param_3[0x40]) + -0x44);
      }
      if ((CONCAT44(*(undefined4 *)(param_3 + 0x36),*(undefined4 *)(param_3 + 2)) < uVar6) &&
         (iVar2 = fix_problem(param_1,0x10078,param_5), iVar2 != 0)) {
        uVar3 = *(uint *)(param_3 + 0x10) & 0xfff7ffff;
      }
      else {
        iVar2 = FUN_0011e3d0(lVar1,param_3);
        if ((iVar2 == 0) || (iVar2 = fix_problem(param_1,0x10079,param_5), iVar2 == 0)) {
          iVar2 = fix_problem(param_1,0x1007a,param_5);
          if (iVar2 == 0) {
            return 0;
          }
          e2fsck_clear_inode(param_1,param_2,param_3,0,"pass1");
          return 0xffffffff;
        }
        uVar3 = *(uint *)(param_3 + 0x10) & 0xeff7ffff;
      }
    }
    *(uint *)(param_3 + 0x10) = uVar3;
    e2fsck_write_inode(param_1,param_2,param_3,"pass1");
  }
  return 0;
}



// Function: check_blocks_extents @ 0x233d0

void check_blocks_extents(long *param_1,long *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  long lVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  long in_FS_OFFSET;
  undefined8 local_80;
  undefined1 local_78 [16];
  int local_68;
  long local_40;
  
  puVar5 = (ushort *)param_2[3];
  lVar6 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = (undefined4)param_2[1];
  lVar8 = ext2fs_extent_header_verify(puVar5 + 0x14,0x3c);
  if (lVar8 == 0) {
    lVar8 = ext2fs_extent_open2(lVar6,uVar2,puVar5,&local_80);
    *param_2 = lVar8;
    if (lVar8 == 0) {
      lVar8 = ext2fs_extent_get_info(local_80,local_78);
      if (lVar8 == 0) {
        lVar8 = 4;
        if (local_68 < 5) {
          lVar8 = (long)local_68;
        }
        piVar1 = (int *)((long)param_1 + lVar8 * 4 + 0x330);
        *piVar1 = *piVar1 + 1;
      }
      param_2[5] = (long)local_68;
      uVar9 = ext2fs_max_extent_depth(local_80);
      param_2[6] = uVar9;
      if (uVar9 < (ulong)param_2[5]) {
        iVar7 = fix_problem(param_1,0x1007f,param_2);
        if (iVar7 != 0) {
          param_3[0x1b] = 1;
        }
        uVar9 = param_2[6];
      }
      param_2[5] = 5;
      if (5 < uVar9) {
        fix_problem(param_1,0x14005,param_2);
      }
      *(undefined8 *)(param_3 + 0x24) = 0;
      *(undefined1 (*) [16])(param_3 + 0x1c) = (undefined1  [16])0x0;
      *(undefined1 (*) [16])(param_3 + 0x20) = (undefined1  [16])0x0;
      uVar3 = *(undefined4 *)(puVar5 + 2);
      param_3[0x1a] = *param_3;
      uVar4 = *(undefined4 *)(puVar5 + 0x36);
      *(undefined8 *)(param_3 + 0x18) = 0;
      FUN_001212c0(param_1,param_2,param_3,0,0,
                   (CONCAT44(uVar4,uVar3) + -1 + (ulong)*(uint *)(lVar6 + 0x28) >>
                   ((char)*(undefined4 *)(*(long *)(lVar6 + 0x20) + 0x18) + 10U & 0x3f)) - 1,
                   local_80);
      if ((*param_2 != 0) && (iVar7 = fix_problem(param_1,0x10057,param_2), iVar7 != 0)) {
        *(undefined8 *)(param_3 + 2) = 0;
        puVar5[0xe] = 0;
        puVar5[0xf] = 0;
        e2fsck_clear_inode(param_1,uVar2,puVar5,4,"check_blocks_extents");
        *param_2 = 0;
      }
      ext2fs_extent_free(local_80);
      if (((*puVar5 & 0xf000) != 0x4000) ||
         (iVar7 = e2fsck_dir_will_be_rehashed(param_1,uVar2), iVar7 == 0)) {
        if ((*(byte *)((long)param_1 + 0x4d) & 0x40) == 0) {
          e2fsck_should_rebuild_extents(param_1,param_2,param_3 + 0x1a,local_78);
        }
        else {
          e2fsck_rebuild_extents_later(param_1,uVar2);
        }
      }
      goto LAB_00123546;
    }
    iVar7 = fix_problem(param_1,0x10056,param_2);
  }
  else {
    iVar7 = fix_problem(param_1,0x10081,param_2);
  }
  if (iVar7 == 0) {
    *param_2 = 0;
  }
  else {
    e2fsck_clear_inode(param_1,uVar2,puVar5,0,"check_blocks_extents");
    *param_2 = 0;
  }
LAB_00123546:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_blocks @ 0x236a0

void check_blocks(long *param_1,long *param_2,undefined8 param_3,ulong *param_4)

{
  uint uVar1;
  long lVar2;
  ushort *puVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  long lVar10;
  ulong uVar11;
  long extraout_RDX;
  long lVar12;
  long extraout_RDX_00;
  ushort uVar13;
  ulong uVar14;
  ulong uVar15;
  long in_FS_OFFSET;
  int local_108;
  ulong local_f0;
  ulong local_e8;
  int local_e0;
  uint local_d8;
  byte local_d4;
  ulong local_d0;
  ulong local_c8;
  long local_c0;
  long local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  ushort *local_98;
  long *local_90;
  long *local_80;
  undefined4 local_6c;
  long local_40;
  
  uVar1 = *(uint *)(param_2 + 1);
  lVar2 = *param_1;
  puVar3 = (ushort *)param_2[3];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_d0 = 0;
  if (param_4 != (ulong *)0x0) {
    local_d0 = *param_4;
  }
  lVar10 = *(long *)(lVar2 + 0x20);
  uVar4 = *puVar3;
  local_c0 = -1;
  local_a8 = 0;
  local_b8 = -1;
  local_b0 = 0xffffffffffffffff;
  local_d0 = local_d0 >> ((byte)*(undefined4 *)(lVar2 + 0xc0) & 0x3f);
  local_c8 = (ulong)(0x80000000 >> ((byte)*(undefined4 *)(lVar10 + 0x18) & 0x1f));
  *param_2 = 0;
  local_6c = 0;
  local_a0 = 0;
  local_d4 = ((uVar4 & 0xf000) == 0x8000) * '\x02' | (uVar4 & 0xf000) == 0x4000 | local_d4 & 0x40;
  local_d8 = uVar1;
  local_98 = puVar3;
  local_90 = param_2;
  local_80 = param_1;
  iVar5 = FUN_001203c0(*(undefined4 *)(lVar10 + 0x60),param_2,param_3,&local_e8);
  iVar6 = FUN_0011fe30();
  iVar7 = FUN_00122320(param_1);
  if (iVar7 != 0) {
    if ((*(byte *)(param_1 + 9) & 3) != 0) goto LAB_00123b88;
    local_d0 = local_d0 + (local_e8 >> ((byte)*(undefined4 *)(*param_1 + 0xc0) & 0x3f));
  }
  if ((iVar6 == 0) || ((*(byte *)((long)puVar3 + 0x23) & 0x10) == 0)) {
    iVar6 = ext2fs_inode_has_valid_blocks2(lVar2,puVar3);
    if (iVar6 != 0) {
      if ((iVar5 == 0) || ((puVar3[0x11] & 8) == 0)) {
        uVar8 = *(uint *)(lVar2 + 0x10);
        *(uint *)(lVar2 + 0x10) = uVar8 | 0x200000;
        lVar10 = ext2fs_block_iterate3(lVar2,uVar1,local_d4 & 1,param_3,FUN_00120c70,&local_d8);
        *param_2 = lVar10;
        local_b8 = local_c0;
        if ((char)local_d4 < '\0') {
          e2fsck_read_inode(param_1,uVar1,puVar3,"check_blocks");
        }
        *(uint *)(lVar2 + 0x10) = *(uint *)(lVar2 + 0x10) & 0xffdfffff | uVar8 & 0x200000;
        if (((*(byte *)((long)param_1 + 0x4d) & 0x40) != 0) &&
           (((*puVar3 & 0xf000) != 0x4000 ||
            (iVar6 = e2fsck_dir_will_be_rehashed(param_1,uVar1), iVar6 == 0)))) {
          e2fsck_rebuild_extents_later(param_1,uVar1);
        }
      }
      else {
        FUN_001233d0(param_1,param_2,&local_d8);
      }
    }
  }
  else {
    FUN_0011ee10(param_1,param_2,&local_d8);
  }
  end_problem_latch(param_1,0x10);
  end_problem_latch(param_1,0x80);
  if ((*(uint *)(param_1 + 9) & 3) != 0) goto LAB_00123b88;
  if (*param_2 != 0) {
    fix_problem(param_1,0x10029,param_2);
  }
  if (((local_d4 & 0x10) != 0) && (local_d0 < *(uint *)(*(long *)(lVar2 + 0x20) + 0x20))) {
    if ((*puVar3 & 0xf000) == 0x4000) {
      *(int *)((long)param_1 + 0x31c) = *(int *)((long)param_1 + 0x31c) + 1;
    }
    else {
      *(int *)(param_1 + 99) = (int)param_1[99] + 1;
    }
  }
  if ((local_d4 & 4) != 0) {
    e2fsck_clear_inode(param_1,uVar1,puVar3,4,"check_blocks");
    goto LAB_00123b88;
  }
  local_108 = 0;
  if ((*(byte *)((long)puVar3 + 0x21) & 0x10) != 0) {
    iVar6 = FUN_00122000(param_1,param_2,uVar1,puVar3,param_3);
    if (iVar6 == 0) {
      e2fsck_add_dx_dir(param_1,uVar1,puVar3,(int)local_c0 + 1);
      local_108 = 0;
    }
    else {
      *(uint *)(puVar3 + 0x10) = *(uint *)(puVar3 + 0x10) & 0xffffefff;
      local_108 = 1;
    }
  }
  if ((((local_d0 == 0) && ((local_d4 & 1) != 0)) && ((*(byte *)((long)puVar3 + 0x23) & 0x10) == 0))
     && (iVar6 = fix_problem(param_1,0x10006,param_2), iVar6 != 0)) {
    e2fsck_clear_inode(param_1,uVar1,puVar3,0,"check_blocks");
    *(int *)(param_1 + 0x5c) = (int)param_1[0x5c] + -1;
    goto LAB_00123b88;
  }
  uVar8 = quota_type2inum(2,*(undefined8 *)(lVar2 + 0x20));
  if (uVar8 != uVar1) {
    if (uVar1 != 2) {
      uVar8 = 0xb;
      if (*(int *)(*(long *)(*param_1 + 0x20) + 0x4c) != 0) {
        uVar8 = *(uint *)(*(long *)(*param_1 + 0x20) + 0x54);
      }
      if (uVar1 < uVar8) goto LAB_001239d8;
    }
    if ((*(uint *)(puVar3 + 0x10) & 0x200000) == 0) {
      quota_data_add(param_1[0x4f],puVar3,uVar1,
                     (long)(0x400 << ((byte)*(undefined4 *)(*(long *)(lVar2 + 0x20) + 0x1c) & 0x1f))
                     * local_d0);
      iVar6 = 0;
      if (param_4 != (ulong *)0x0) {
        iVar6 = (int)param_4[1];
      }
      quota_data_inodes(param_1[0x4f],puVar3,uVar1,iVar6 + 1 + local_e0);
    }
  }
LAB_001239d8:
  lVar10 = *(long *)(lVar2 + 0x20);
  iVar6 = FUN_00121fe0(*(undefined4 *)(lVar10 + 100));
  if ((iVar6 == 0) || ((puVar3[0x11] & 4) == 0)) {
    local_d0 = local_d0 * (*(uint *)(lVar2 + 0x28) >> 9);
  }
  local_d0 = (long)(1 << ((byte)*(undefined4 *)(lVar2 + 0xc0) & 0x1f)) * local_d0;
  uVar14 = CONCAT44(*(undefined4 *)(puVar3 + 0x36),*(uint *)(puVar3 + 2));
  lVar12 = extraout_RDX;
  if ((local_d4 & 1) == 0) {
    uVar4 = *puVar3;
    uVar13 = uVar4 & 0xf000;
    if (((local_b8 < 0) ||
        (uVar11 = (ulong)*(uint *)(lVar2 + 0x28),
        local_b8 * uVar11 < uVar14 || local_b8 * uVar11 - uVar14 == 0)) ||
       ((puVar3[0x11] & 0x10) != 0)) {
      if ((iVar5 == 0) || ((puVar3[0x11] & 8) == 0)) {
        if (uVar14 <= (ulong)(&DAT_001b7140)[*(uint *)(extraout_RDX + 0x18)]) goto LAB_00123aea;
        lVar12 = lVar10;
        if (uVar13 != 0xa000) {
          uVar11 = (ulong)*(uint *)(lVar2 + 0x28);
          uVar9 = 4;
          goto LAB_00123ab6;
        }
      }
      else if ((1L << ((char)*(uint *)(extraout_RDX + 0x18) + 0x2aU & 0x3f)) - 1U < uVar14) {
        lVar12 = lVar10;
        if (uVar13 != 0xa000) {
          uVar11 = (ulong)*(uint *)(lVar2 + 0x28);
          uVar9 = 6;
          goto LAB_00123ab6;
        }
      }
      else {
LAB_00123aea:
        if (((uVar4 & 0xf000) == 0x8000) &&
           (iVar5 = FUN_0011e130(CONCAT44(*(undefined4 *)(puVar3 + 0x36),*(undefined4 *)(puVar3 + 2)
                                         )), lVar12 = extraout_RDX_00, iVar5 != 0)) {
          *(int *)(param_1 + 100) = (int)param_1[100] + 1;
        }
      }
    }
    else {
      lVar12 = lVar10;
      if (uVar13 != 0xa000) {
        uVar9 = 3;
        goto LAB_00123ab6;
      }
    }
  }
  else {
    if ((*(byte *)((long)puVar3 + 0x23) & 0x10) != 0) {
      lVar10 = *param_1;
      lVar12 = param_2[1];
      local_f0 = 0;
      uVar8 = *(uint *)(lVar10 + 0x10);
      *(uint *)(lVar10 + 0x10) = uVar8 | 0x200000;
      lVar10 = ext2fs_inline_data_size(lVar10,(int)lVar12,&local_f0);
      *(uint *)(*param_1 + 0x10) = *(uint *)(*param_1 + 0x10) & 0xffdfffff | uVar8 & 0x200000;
      if ((lVar10 != 0) || (local_f0 != uVar14)) {
        uVar4 = *puVar3;
        param_2[10] = local_f0;
        uVar9 = 7;
        if ((uVar4 & 0xf000) == 0xa000) {
          lVar12 = *(long *)(lVar2 + 0x20);
          goto LAB_00123afb;
        }
LAB_00123abe:
        *(undefined4 *)(param_2 + 8) = uVar9;
        iVar5 = fix_problem(param_1,0x1000c,param_2);
        if (iVar5 != 0) {
          ext2fs_inode_size_set(lVar2,puVar3,param_2[10]);
          if ((*(int *)(puVar3 + 0x36) == 0 && *(int *)(puVar3 + 2) == 0) &&
             ((*(uint *)(puVar3 + 0x10) & 0x10000000) != 0)) {
            puVar3[0x2c] = 0;
            puVar3[0x2d] = 0;
            puVar3[0x2e] = 0;
            puVar3[0x2f] = 0;
            puVar3[0x30] = 0;
            puVar3[0x31] = 0;
            *(uint *)(puVar3 + 0x10) = *(uint *)(puVar3 + 0x10) & 0xefffffff;
            *(undefined1 (*) [16])(puVar3 + 0x14) = (undefined1  [16])0x0;
            *(undefined1 (*) [16])(puVar3 + 0x1c) = (undefined1  [16])0x0;
            *(undefined1 (*) [16])(puVar3 + 0x24) = (undefined1  [16])0x0;
          }
          local_108 = local_108 + 1;
        }
        param_2[10] = 0;
      }
      uVar4 = *puVar3;
      lVar12 = *(long *)(lVar2 + 0x20);
      goto LAB_00123aea;
    }
    uVar11 = (ulong)*(uint *)(lVar2 + 0x28);
    uVar4 = *puVar3;
    if ((*(uint *)(lVar2 + 0x28) - 1 & *(uint *)(puVar3 + 2)) == 0) {
      uVar15 = uVar14 >> ((char)*(undefined4 *)(extraout_RDX + 0x18) + 10U & 0x3f) & 0xffffffff;
      uVar14 = local_c0 + 1;
      if (uVar14 < uVar15) {
        uVar9 = 1;
      }
      else {
        if ((uVar14 <= uVar15) || (uVar14 - uVar15 <= (ulong)*(byte *)(extraout_RDX + 0xcd)))
        goto LAB_00123aea;
        uVar9 = 2;
      }
      lVar12 = lVar10;
      if ((uVar4 & 0xf000) != 0xa000) {
LAB_00123ab6:
        param_2[10] = (local_c0 + 1) * uVar11;
        goto LAB_00123abe;
      }
    }
    else {
      lVar12 = lVar10;
      if ((uVar4 & 0xf000) != 0xa000) {
        uVar9 = 5;
        goto LAB_00123ab6;
      }
    }
  }
LAB_00123afb:
  uVar14 = local_d0;
  if ((*(int *)(lVar12 + 0x48) != 1) &&
     ((uVar11 = ext2fs_inode_i_blocks(lVar2,puVar3), uVar14 != uVar11 ||
      (((iVar5 = FUN_00121fe0(*(undefined4 *)(*(long *)(lVar2 + 0x20) + 100)), iVar5 != 0 &&
        ((puVar3[0x11] & 4) != 0)) && (puVar3[0x3a] != 0)))))) {
    param_2[10] = local_d0;
    iVar5 = fix_problem(param_1,0x1000d,param_2);
    if (iVar5 != 0) {
      local_108 = local_108 + 1;
      *(int *)(puVar3 + 0xe) = (int)local_d0;
      puVar3[0x3a] = (ushort)(local_d0 >> 0x20);
    }
    param_2[10] = 0;
  }
  iVar5 = FUN_00121fc0();
  if (((iVar5 == 0) || (((*puVar3 & 0xf000) + 0xc000 & 0xb000) != 0)) ||
     (lVar10 = ext2fs_inode_data_blocks2(lVar2,puVar3), lVar10 == 0)) {
LAB_00123b27:
    if (((param_1[0x49] != 0) && ((local_d4 & 1) != 0)) &&
       (((*(uint *)(param_1 + 0x45) == 0 || (*(uint *)(param_1 + 0x45) != uVar1)) &&
        (((*(byte *)((long)puVar3 + 0x21) & 0x10) == 0 &&
         (2 < *(uint *)(puVar3 + 2) / *(uint *)(lVar2 + 0x28))))))) {
      e2fsck_rehash_dir_later
                (param_1,uVar1,(ulong)*(uint *)(puVar3 + 2) % (ulong)*(uint *)(lVar2 + 0x28));
    }
  }
  else {
    if (uVar1 != 2) {
      uVar8 = 0xb;
      if (*(int *)(*(long *)(lVar2 + 0x20) + 0x4c) != 0) {
        uVar8 = *(uint *)(*(long *)(lVar2 + 0x20) + 0x54);
      }
      if (uVar1 < uVar8) goto LAB_00123b27;
    }
    if (((*(uint *)(puVar3 + 0x10) & 0x10080000) != 0) ||
       (iVar5 = fix_problem(param_1,0x10080,param_2), iVar5 == 0)) goto LAB_00123b27;
    lVar10 = e2fsck_rebuild_extents_later(param_1,uVar1);
    *param_2 = lVar10;
    if (lVar10 == 0) goto LAB_00123b27;
  }
  if (local_108 != 0) {
    e2fsck_write_inode(param_1,uVar1,puVar3,"check_blocks");
  }
LAB_00123b88:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: process_inodes @ 0x240b0

void process_inodes(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  int iVar7;
  long in_FS_OFFSET;
  undefined1 local_108 [8];
  undefined4 local_100;
  undefined4 *local_f0;
  undefined1 local_98 [88];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (DAT_001b7178 != 0) {
    uVar4 = ehandler_operation(0);
    uVar3 = *(undefined8 *)(param_1 + 0x220);
    uVar1 = *(undefined4 *)(param_1 + 0x218);
    qsort(DAT_001b7180,(long)DAT_001b7178,0xb8,FUN_0011e780);
    clear_problem_context(local_108);
    if (0 < DAT_001b7178) {
      lVar6 = 0;
      iVar7 = 0;
      do {
        uVar2 = *(undefined4 *)((long)DAT_001b7180 + lVar6);
        local_f0 = (undefined4 *)((long)DAT_001b7180 + lVar6) + 6;
        *(undefined4 **)(param_1 + 0x220) = local_f0;
        *(undefined4 *)(param_1 + 0x218) = uVar2;
        local_100 = uVar2;
        uVar5 = dcgettext(0,"reading indirect blocks of inode %u",5);
        __sprintf_chk(local_98,1,0x50,uVar5,uVar2);
        ehandler_operation(local_98);
        FUN_001236a0(param_1,local_108,param_2,(long)DAT_001b7180 + lVar6 + 8);
        if ((*(byte *)(param_1 + 0x48) & 3) != 0) break;
        iVar7 = iVar7 + 1;
        lVar6 = lVar6 + 0xb8;
      } while (iVar7 < DAT_001b7178);
    }
    DAT_001b7178 = 0;
    *(undefined8 *)(param_1 + 0x220) = uVar3;
    *(undefined4 *)(param_1 + 0x218) = uVar1;
    ehandler_operation(uVar4);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: scan_callback @ 0x24270

undefined8 scan_callback(long param_1,undefined8 param_2,int param_3,long *param_4)

{
  long *plVar1;
  int iVar2;
  
  plVar1 = (long *)*param_4;
  FUN_001240b0(*(undefined8 *)(param_1 + 0xe0),param_4[1]);
  if ((code *)plVar1[0x2c] != (code *)0x0) {
    iVar2 = (*(code *)plVar1[0x2c])(plVar1,1,param_3 + 1,*(undefined4 *)(*plVar1 + 0x30));
    if (iVar2 != 0) {
      return 0x7f2bb751;
    }
  }
  return 0;
}



// Function: e2fsck_use_inode_shortcuts @ 0x242d0

void e2fsck_use_inode_shortcuts(long *param_1,int param_2)

{
  long lVar1;
  
  lVar1 = *param_1;
  if (param_2 != 0) {
    *(code **)(lVar1 + 0x60) = FUN_0011e1c0;
    *(code **)(lVar1 + 0x68) = FUN_0011e310;
    *(code **)(lVar1 + 0x78) = FUN_0011e210;
    *(code **)(lVar1 + 0x80) = FUN_0011e290;
    *(undefined4 *)(param_1 + 0x43) = 0;
    return;
  }
  *(undefined8 *)(lVar1 + 0x60) = 0;
  *(undefined8 *)(lVar1 + 0x68) = 0;
  *(undefined8 *)(lVar1 + 0x78) = 0;
  *(undefined8 *)(lVar1 + 0x80) = 0;
  return;
}



// Function: e2fsck_intercept_block_allocations @ 0x24340

void e2fsck_intercept_block_allocations(undefined8 *param_1)

{
  ext2fs_set_alloc_block_callback(*param_1,FUN_0011f3d0,0);
  ext2fs_set_block_alloc_stats_callback(*param_1,FUN_0011e350,0);
  ext2fs_set_new_range_callback(*param_1,FUN_0011f350,0);
  ext2fs_set_block_alloc_stats_range_callback(*param_1,FUN_0011f2d0,0);
  return;
}



// Function: e2fsck_pass1 @ 0x24390

void e2fsck_pass1(long *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  byte bVar14;
  ulong uVar15;
  uint uVar16;
  long lVar17;
  ushort *extraout_RDX;
  long extraout_RDX_00;
  uint *extraout_RDX_01;
  uint *puVar18;
  uint *extraout_RDX_02;
  undefined8 *puVar19;
  undefined8 *puVar20;
  long lVar21;
  bool bVar22;
  long in_FS_OFFSET;
  bool bVar23;
  bool bVar24;
  byte bVar25;
  ulong local_240;
  int local_224;
  int local_218;
  uint local_1e4;
  uint local_1e0;
  undefined4 local_1dc;
  uint *local_1d8;
  long local_1d0;
  long local_1c8;
  undefined8 local_1c0;
  long *local_1b8;
  long local_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined1 local_198 [80];
  long local_148;
  uint local_140;
  uint *local_130;
  ulong local_f8;
  undefined4 local_d8;
  byte local_d4;
  undefined8 local_d0;
  undefined8 local_c0;
  undefined8 local_b0;
  undefined4 local_a8;
  uint *local_98;
  long *local_90;
  undefined8 local_88;
  long *local_80;
  long local_40;
  
  bVar25 = 0;
  lVar12 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_1e4 = 0;
  local_1d8 = (uint *)0x0;
  lVar3 = *(long *)(lVar12 + 0x20);
  local_1d0 = 0;
  local_1c8 = 0;
  uVar9 = dcgettext(0,"getting next inode from scan",5);
  local_240 = 0x80;
  if (*(int *)(*(long *)(lVar12 + 0x20) + 0x4c) != 0) {
    local_240 = (ulong)*(ushort *)(*(long *)(lVar12 + 0x20) + 0x58);
  }
  local_1e0 = 0;
  local_1dc = 0;
  init_resource_track(local_198,*(undefined8 *)(*param_1 + 8));
  clear_problem_context(&local_148);
  iVar5 = e2fsck_can_readahead(*param_1);
  if (iVar5 == 0) {
    param_1[0x73] = 0;
  }
  else if (param_1[0x73] == -1) {
    lVar17 = e2fsck_guess_readahead(*param_1);
    param_1[0x73] = lVar17;
  }
  FUN_0011eae0(param_1,&local_1dc,&local_1e0);
  if ((*(byte *)((long)param_1 + 0x4c) & 2) == 0) {
    fix_problem(param_1,0x10000,&local_148);
  }
  iVar5 = FUN_00121ff0(*(undefined4 *)(*(long *)(lVar12 + 0x20) + 0x5c));
  if (((iVar5 != 0) && ((*(byte *)((long)param_1 + 0x4c) & 8) == 0)) &&
     (lVar17 = ext2fs_u32_list_create(param_1 + 0x49,0x32), lVar17 != 0)) {
    param_1[0x49] = 0;
  }
  lVar17 = 10;
  do {
    bVar14 = (byte)lVar17 - 2;
    lVar21 = 1L << (bVar14 & 0x3f);
    lVar10 = lVar21 << (bVar14 & 0x3f);
    *(long *)(&DAT_001b70f0 + lVar17 * 8) =
         (lVar10 << (bVar14 & 0x3f)) + lVar21 + 0xc + lVar10 << ((byte)lVar17 & 0x3f);
    lVar17 = lVar17 + 1;
  } while (lVar17 != 0x11);
  uVar1 = *(undefined4 *)(lVar3 + 0x5c);
  uVar2 = *(undefined4 *)(lVar3 + 0x60);
  uVar11 = dcgettext(0,"in-use inode map",5);
  local_148 = e2fsck_allocate_inode_bitmap(lVar12,uVar11,2,"inode_used_map",param_1 + 0x2d);
  if (local_148 == 0) {
    uVar11 = dcgettext(0,"directory inode map",5);
    local_148 = e2fsck_allocate_inode_bitmap(lVar12,uVar11,3,"inode_dir_map",param_1 + 0x2f);
    if (local_148 == 0) {
      uVar11 = dcgettext(0,"regular file inode map",5);
      local_148 = e2fsck_allocate_inode_bitmap(lVar12,uVar11,2,"inode_reg_map",param_1 + 0x32);
      if (local_148 == 0) {
        uVar11 = dcgettext(0,"in-use block map",5);
        local_148 = e2fsck_allocate_subcluster_bitmap
                              (lVar12,uVar11,2,"block_found_map",param_1 + 0x34);
        if (local_148 == 0) {
          uVar11 = dcgettext(0,"metadata block map",5);
          local_148 = e2fsck_allocate_block_bitmap
                                (lVar12,uVar11,2,"block_metadata_map",param_1 + 0x72);
          if (local_148 == 0) {
            iVar5 = FUN_0011fe20(uVar2);
            if (iVar5 != 0) {
              uVar11 = dcgettext(0,"inode casefold map",5);
              local_148 = e2fsck_allocate_inode_bitmap
                                    (lVar12,uVar11,2,"inode_casefold_map",param_1 + 0x33);
              if (local_148 != 0) goto LAB_00124f18;
            }
            local_148 = e2fsck_setup_icount(param_1,"inode_link_info",0,0,param_1 + 0x38);
            if (local_148 == 0) {
              uVar8 = 0xa0;
              if (0x9f < (uint)local_240) {
                uVar8 = (uint)local_240;
              }
              local_1d8 = (uint *)e2fsck_allocate_memory(param_1,uVar8,"scratch inode");
              DAT_001b7180 = e2fsck_allocate_memory
                                       (param_1,(long)(int)param_1[0x4b] * 0xb8,
                                        "array of inodes to process");
              DAT_001b7178 = 0;
              local_148 = ext2fs_init_dblist(lVar12,0);
              if (local_148 == 0) {
                if (((*(byte *)((long)param_1 + 0x4c) & 1) == 0) &&
                   (*(int *)(*(long *)(lVar12 + 0x20) + 0xe8) != 0)) {
                  *(undefined4 *)(*(long *)(lVar12 + 0x20) + 0xe8) = 0;
                  ext2fs_mark_super_dirty(lVar12);
                }
                FUN_0011e7e0(param_1);
                local_148 = ext2fs_convert_subcluster_bitmap(lVar12,param_1 + 0x34);
                if (local_148 == 0) {
                  local_1c8 = e2fsck_allocate_memory
                                        (param_1,*(int *)(lVar12 + 0x28) * 3,"block interate buffer"
                                        );
                  if ((*(int *)(*(long *)(lVar12 + 0x20) + 0x4c) == 0) ||
                     (*(short *)(*(long *)(lVar12 + 0x20) + 0x58) == 0x80)) {
                    e2fsck_use_inode_shortcuts(param_1,1);
                  }
                  e2fsck_intercept_block_allocations(param_1);
                  uVar11 = dcgettext(0,"opening inode scan",5);
                  uVar11 = ehandler_operation(uVar11);
                  local_148 = ext2fs_open_inode_scan
                                        (lVar12,*(undefined4 *)((long)param_1 + 0x25c),&local_1d0);
                  ehandler_operation(uVar11);
                  if (local_148 == 0) {
                    ext2fs_inode_scan_flags(local_1d0,0x28,0);
                    param_1[0x44] = (long)local_1d8;
                    local_1b0 = local_1c8;
                    local_1b8 = param_1;
                    ext2fs_set_inode_callback(local_1d0,FUN_00124270,&local_1b8);
                    if (((code *)param_1[0x2c] == (code *)0x0) ||
                       (iVar6 = (*(code *)param_1[0x2c])
                                          (param_1,1,0,*(undefined4 *)(*param_1 + 0x30)), iVar6 == 0
                       )) {
                      puVar18 = *(uint **)(lVar12 + 0x20);
                      if (((puVar18[0xc] == 0) || (bVar23 = false, *puVar18 <= puVar18[0xc])) &&
                         ((puVar18[0xb] == 0 || (bVar23 = false, *puVar18 <= puVar18[0xb])))) {
                        bVar23 = true;
                        if (puVar18[0x42] != 0) {
                          bVar23 = *puVar18 <= puVar18[0x42];
                        }
                      }
                      iVar6 = FUN_001203a0(puVar18[0x18]);
                      if (((iVar6 != 0) &&
                          (uVar15 = *(ulong *)(puVar18 + 0x5a), puVar18[5] < uVar15)) &&
                         (uVar13 = ext2fs_blocks_count(puVar18), uVar15 < uVar13)) {
                        ext2fs_mark_block_bitmap2
                                  (param_1[0x34],*(undefined8 *)(*(long *)(lVar12 + 0x20) + 0x168));
                      }
                      iVar6 = FUN_00122d10(uVar1,0);
                      local_224 = FUN_001203c0(uVar2);
                      local_218 = FUN_0011fe30();
                      e2fsck_get_lost_and_found(param_1);
LAB_00124974:
                      while( true ) {
                        if ((local_1e4 % (uint)(*(int *)(*(long *)(lVar12 + 0x20) + 0x28) << 2) == 1
                            ) && (lVar17 = e2fsck_mmp_update(lVar12), lVar17 != 0)) {
                    /* WARNING: Subroutine does not return */
                          fatal_error(param_1,0);
                        }
                        uVar11 = ehandler_operation(uVar9);
                        local_148 = ext2fs_get_next_inode_full
                                              (local_1d0,&local_1e4,local_1d8,local_240);
                        if (local_1e0 < local_1e4) {
                          FUN_0011eae0(param_1,&local_1dc,&local_1e0);
                        }
                        ehandler_operation(uVar11);
                        if ((*(byte *)(param_1 + 9) & 3) != 0) goto LAB_00124fc5;
                        if (local_148 != 0x7f2bb742) break;
                        if ((local_1e4 == 1) &&
                           (iVar7 = fix_problem(param_1,0x1007b,&local_148), iVar7 != 0)) {
                          e2fsck_clear_inode(param_1,local_1e4,local_1d8,0,"pass1");
                          ext2fs_badblocks_list_free(*(undefined8 *)(*param_1 + 0x88));
                          lVar12 = *param_1;
                          *(undefined8 *)(lVar12 + 0x88) = 0;
                          lVar12 = ext2fs_read_bb_inode(lVar12,lVar12 + 0x88);
                          if (lVar12 != 0) goto LAB_0012532e;
                          *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 4;
                          goto LAB_00124fc5;
                        }
                        lVar17 = param_1[0x30];
                        if (lVar17 == 0) {
                          FUN_0011e430(param_1);
                          lVar17 = param_1[0x30];
                        }
                        ext2fs_mark_inode_bitmap2(lVar17,local_1e4);
                        ext2fs_mark_inode_bitmap2(param_1[0x2d]);
                      }
                      bVar24 = local_148 != 0;
                      if ((local_148 != 0x7f2bb792 && bVar24) && (local_148 != 0x7f2bb7a9))
                      goto LAB_0012532e;
                      if (local_1e4 == 0) {
                        FUN_001240b0(param_1,local_1c8);
                        ext2fs_close_inode_scan(local_1d0);
                        local_1d0 = 0;
                        FUN_0011f030(param_1);
                        FUN_0011f0d0(param_1);
                        if (param_1[0x39] != 0) {
                          FUN_0011f180(param_1,param_1[0x39],local_1c8,0xffffffff);
                          ea_refcount_free(param_1[0x39]);
                          param_1[0x39] = 0;
                        }
                        if (param_1[0x3a] != 0) {
                          FUN_0011f180(param_1,param_1[0x3a],local_1c8,1);
                          ea_refcount_free(param_1[0x3a]);
                          param_1[0x3a] = 0;
                        }
                        if (param_1[0x3b] != 0) {
                          ea_refcount_free();
                          param_1[0x3b] = 0;
                        }
                        if (param_1[0x3c] != 0) {
                          ea_refcount_free();
                          param_1[0x3c] = 0;
                        }
                        if ((int)param_1[0x41] != 0) {
                          FUN_001201c0(param_1);
                        }
                        if (param_1[0x36] != 0) {
                          ext2fs_free_block_bitmap();
                          param_1[0x36] = 0;
                        }
                        destroy_encryption_policy_map(param_1);
                        uVar8 = *(uint *)(param_1 + 9);
                        if ((uVar8 & 0x400) != 0) {
                          clear_problem_context(&local_148);
                          local_148 = ext2fs_create_resize_inode(lVar12);
                          if (local_148 != 0) {
                            iVar5 = fix_problem(param_1,0x1004e,&local_148);
                            if (iVar5 == 0) goto LAB_0012533e;
                            local_148 = 0;
                          }
                          e2fsck_read_inode(param_1,7,local_1d8,"recreate inode");
                          local_1d8[4] = (uint)param_1[0x69];
                          e2fsck_write_inode(param_1,7,local_1d8,"recreate inode");
                          *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) & 0xfffffbff;
                          uVar8 = *(uint *)(param_1 + 9);
                        }
                        if ((uVar8 & 4) == 0) {
                          if ((*(int *)((long)param_1 + 0x324) != 0) &&
                             (iVar5 = FUN_0011fe40(*(undefined4 *)(*(long *)(lVar12 + 0x20) + 0x60))
                             , iVar5 == 0)) {
                            iVar5 = fix_problem(param_1,0x20039,&local_148);
                            if (iVar5 != 0) {
                              FUN_0011e0f0(*(undefined8 *)(lVar12 + 0x20));
                              *(uint *)(lVar12 + 0x10) = *(uint *)(lVar12 + 0x10) & 0xfffffdff;
                              ext2fs_mark_super_dirty(lVar12);
                            }
                            if ((*(int *)(*(long *)(lVar12 + 0x20) + 0x4c) == 0) &&
                               (iVar5 = fix_problem(param_1,0x10033,&local_148), iVar5 != 0)) {
                              ext2fs_update_dynamic_rev(lVar12);
                              ext2fs_mark_super_dirty(lVar12);
                            }
                          }
                          if (param_1[0x35] != 0) {
                            if ((*(byte *)((long)param_1 + 0x4c) & 2) != 0) {
                              clear_problem_context(&local_148);
                              fix_problem(param_1,0x10014,&local_148);
                            }
                            e2fsck_pass1_dupblocks(param_1,local_1c8);
                          }
                          *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 0x8000;
                        }
                        else {
                          param_1[0xb] = 0;
                        }
                        goto LAB_00124fc5;
                      }
                      local_140 = local_1e4;
                      *(uint *)(param_1 + 0x43) = local_1e4;
                      local_130 = local_1d8;
                      if ((local_148 == 0x7f2bb7a9) &&
                         (bVar24 = true, *(ushort *)((long)local_1d8 + 0x1a) != 0)) {
                        iVar7 = fix_problem(param_1,0x10067,&local_148);
                        if (iVar7 != 0) {
                          local_148 = 0;
                          e2fsck_clear_inode(param_1,local_1e4,local_1d8,0,"pass1");
                        }
                        bVar24 = local_148 != 0;
                      }
                      if ((((local_1d8[5] != 0) && (bVar23)) &&
                          (local_1d8[5] < **(uint **)(*param_1 + 0x20))) &&
                         (iVar7 = fix_problem(param_1,0x10036,&local_148), iVar7 != 0)) {
                        uVar8 = 0;
                        if (*(ushort *)((long)local_1d8 + 0x1a) == 0) {
                          uVar8 = *(uint *)(param_1 + 0x69);
                        }
                        local_1d8[5] = uVar8;
                        bVar24 = false;
                        e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
                      }
                      if (*(ushort *)((long)local_1d8 + 0x1a) == 0) {
                        uVar8 = 0xb;
                        if (*(int *)(*(long *)(lVar12 + 0x20) + 0x4c) != 0) {
                          uVar8 = *(uint *)(*(long *)(lVar12 + 0x20) + 0x54);
                        }
                        if ((local_1e4 < uVar8) || (iVar7 = FUN_0011ec90(lVar12), iVar7 != 0))
                        goto LAB_00124a8b;
                        if ((local_1d8[5] == 0) &&
                           (((ushort)*local_1d8 != 0 &&
                            (iVar7 = fix_problem(param_1,0x10004,&local_148), iVar7 != 0)))) {
                          bVar24 = false;
                          local_1d8[5] = (uint)param_1[0x69];
                          e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
                        }
                        goto LAB_001251aa;
                      }
                      local_148 = ext2fs_icount_store(param_1[0x38],local_1e4,
                                                      *(ushort *)((long)local_1d8 + 0x1a));
                      if (local_148 != 0) {
                        local_f8 = (ulong)*(ushort *)((long)local_1d8 + 0x1a);
                        fix_problem(param_1,0x1002a,&local_148);
                        *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
                        goto LAB_00124fc5;
                      }
LAB_00124a8b:
                      uVar8 = local_1d8[8];
                      if ((uVar8 & 0x40000000) != 0) {
                        if ((((*local_1d8 & 0xf000) != 0x4000) &&
                            (iVar7 = fix_problem(param_1,0x10088,&local_148), iVar7 != 0)) ||
                           ((iVar5 == 0 &&
                            (iVar7 = fix_problem(param_1,0x10089,&local_148), iVar7 != 0)))) {
                          local_1d8[8] = local_1d8[8] & 0xbfffffff;
                          e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
                        }
                        uVar8 = local_1d8[8];
                      }
                      if ((uVar8 & 0x10080000) == 0x10080000) {
                        iVar7 = FUN_00123210(param_1,local_1e4,local_1d8,local_240,&local_148);
                        if (iVar7 < 0) goto LAB_00124974;
                        uVar8 = local_1d8[8];
                      }
                      if ((uVar8 & 0x10000000) != 0) {
                        lVar17 = *(long *)(lVar12 + 0x20);
                        if (local_218 != 0) {
LAB_00125506:
                          uVar8 = 0xb;
                          if (*(int *)(lVar17 + 0x4c) != 0) {
                            uVar8 = *(uint *)(lVar17 + 0x54);
                          }
                          if (local_1e4 < uVar8) {
                            uVar8 = local_1d8[8];
                            goto LAB_00124b31;
                          }
                          local_1c0 = 0;
                          uVar8 = *(uint *)(lVar12 + 0x10);
                          if (bVar24 != false) {
                            *(uint *)(lVar12 + 0x10) = uVar8 | 0x200000;
                          }
                          lVar17 = FUN_0011f4a0(lVar12,local_1e4,&local_1c0);
                          *(uint *)(lVar12 + 0x10) =
                               *(uint *)(lVar12 + 0x10) & 0xffdfffff | uVar8 & 0x200000;
                          if (lVar17 == 0x7f2bb75a) {
LAB_001257cc:
                            iVar7 = fix_problem(param_1,0x10075,&local_148);
                            if (iVar7 != 0) {
                              lVar17 = ext2fs_inode_size_set(lVar12,local_1d8,0);
                              if (lVar17 != 0) {
                                uVar8 = *(uint *)(param_1 + 9) | 1;
                                local_148 = lVar17;
                                goto LAB_00125842;
                              }
                              bVar24 = false;
                              local_1d8[8] = local_1d8[8] & 0xefffffff;
                              puVar18 = local_1d8 + 10;
                              for (lVar17 = 0xf; lVar17 != 0; lVar17 = lVar17 + -1) {
                                *puVar18 = 0;
                                puVar18 = puVar18 + (ulong)bVar25 * -2 + 1;
                              }
                              e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
                            }
LAB_001257a7:
                            uVar8 = local_1d8[8];
                            goto LAB_00124b31;
                          }
                          if (lVar17 < 0x7f2bb75b) {
                            if (lVar17 == 0) goto LAB_001257a7;
                          }
                          else if ((lVar17 - 0x7f2bb797U < 0x1c) &&
                                  ((0x809ffc1UL >> (lVar17 - 0x7f2bb797U & 0x3f) & 1) != 0))
                          goto LAB_001257cc;
                          uVar8 = *(uint *)(param_1 + 9) | 1;
                          local_148 = lVar17;
LAB_00125842:
                          *(uint *)(param_1 + 9) = uVar8;
                          goto LAB_00124fc5;
                        }
                        uVar16 = 0xb;
                        if (*(int *)(lVar17 + 0x4c) != 0) {
                          uVar16 = *(uint *)(lVar17 + 0x54);
                        }
                        if (local_1e4 < uVar16) goto LAB_00124b31;
                        local_1c0 = 0;
                        local_148 = FUN_0011f4a0(lVar12,local_1e4,&local_1c0);
                        if ((local_148 == 0) &&
                           (iVar7 = fix_problem(param_1,0x1006f,&local_148), iVar7 != 0)) {
                          FUN_0011e100(lVar3);
                          ext2fs_mark_super_dirty(lVar12);
                          local_218 = 1;
                          uVar8 = local_1d8[8];
                          if ((uVar8 & 0x10000000) != 0) {
                            lVar17 = *(long *)(lVar12 + 0x20);
                            goto LAB_00125506;
                          }
                        }
                        else {
                          iVar7 = fix_problem(param_1,0x10070,&local_148);
                          if (iVar7 != 0) {
                            e2fsck_clear_inode(param_1,local_1e4,local_1d8,0,"pass1");
                            goto LAB_00124974;
                          }
                          local_218 = 0;
                          uVar8 = local_1d8[8];
                        }
                      }
LAB_00124b31:
                      if ((uVar8 & 0x80000) == 0) {
                        if (local_224 == 0) goto LAB_00124bb1;
LAB_00125273:
                        if (((*(ushort *)((long)local_1d8 + 0x1a) != 0) || (local_1e4 - 1 < 2)) ||
                           (local_1e4 == 8)) {
                          if ((((((ushort)*local_1d8 & 0xf000) + 0xc000 & 0xb000) != 0) ||
                              (lVar17 = ext2fs_extent_header_verify(local_1d8 + 10,0x3c),
                              lVar17 != 0)) ||
                             (iVar7 = fix_problem(param_1,0x1005c,&local_148), iVar7 == 0))
                          goto LAB_00124bb1;
                          local_1d8[8] = local_1d8[8] | 0x80000;
                          e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
                          if (local_1e4 != 1) {
                            bVar24 = false;
                            goto LAB_00124bba;
                          }
LAB_0012505d:
                          bVar24 = false;
                          bVar22 = bVar24;
                          if (((*local_1d8 != 0) || (local_1d8[6] != 0)) ||
                             (((*(byte *)((long)local_1d8 + 0x23) & 0x10) != 0 ||
                              (bVar22 = false, local_1d8[0x1a] != 0)))) {
LAB_00125081:
                            iVar7 = fix_problem(param_1,0x10065,&local_148);
                            bVar24 = bVar22;
                            if (iVar7 != 0) {
                              bVar24 = false;
                              local_1d8[0] = 0;
                              local_1d8[1] = 0;
                              local_1d8[0x1e] = 0;
                              local_1d8[0x1f] = 0;
                              puVar19 = (undefined8 *)((ulong)(local_1d8 + 2) & 0xfffffffffffffff8);
                              for (uVar15 = (ulong)(((int)local_1d8 -
                                                    (int)(undefined8 *)
                                                         ((ulong)(local_1d8 + 2) &
                                                         0xfffffffffffffff8)) + 0x80U >> 3);
                                  uVar15 != 0; uVar15 = uVar15 - 1) {
                                *puVar19 = 0;
                                puVar19 = puVar19 + (ulong)bVar25 * -2 + 1;
                              }
                              e2fsck_write_inode(param_1,local_1e4,local_1d8,"clear bad inode");
                            }
                          }
                          local_148 = ext2fs_copy_bitmap(param_1[0x34],&local_88);
                          if (local_148 == 0) {
                            local_d4 = local_d4 & 0xa0;
                            local_c0 = 0;
                            local_d0 = 0;
                            local_b0 = 0xffffffffffffffff;
                            local_a8 = 0;
                            local_d8 = 1;
                            local_98 = local_1d8;
                            local_90 = &local_148;
                            local_80 = param_1;
                            local_148 = ext2fs_block_iterate3
                                                  (lVar12,local_1e4,0,local_1c8,FUN_00120890);
                            ext2fs_free_block_bitmap(local_88);
                            if (local_148 == 0) {
                              if (((local_d4 & 0x40) == 0) ||
                                 (iVar7 = fix_problem(param_1,0x10016,&local_148), iVar7 != 0)) {
                                ext2fs_mark_inode_bitmap2(param_1[0x2d],local_1e4);
                                clear_problem_context(&local_148);
                                goto LAB_001251aa;
                              }
                              uVar8 = *(uint *)(param_1 + 9) | 1;
                            }
                            else {
                              fix_problem(param_1,0x10029,&local_148);
                              uVar8 = *(uint *)(param_1 + 9) | 1;
                            }
                          }
                          else {
                            local_f8 = 4;
                            fix_problem(param_1,0x10025,&local_148);
                            uVar8 = *(uint *)(param_1 + 9) | 1;
                          }
                          goto LAB_00125842;
                        }
LAB_00124bba:
                        if (local_1e4 != 2) {
                          if (local_1e4 == 8) {
                            ext2fs_mark_inode_bitmap2(param_1[0x2d]);
                            if (*(int *)(*(long *)(lVar12 + 0x20) + 0xe0) == 8) {
                              if (((*local_1d8 & 0xf000) == 0x8000) ||
                                 (iVar7 = fix_problem(param_1,0x10035,&local_148), iVar7 == 0))
                              goto LAB_00125ca4;
LAB_00125cdf:
                              *(ushort *)local_1d8 = 0x8000;
LAB_00125ce9:
                              bVar24 = false;
                              e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
LAB_00125ca4:
                              FUN_001236a0(param_1,&local_148,local_1c8,0);
                            }
                            else if ((*(ushort *)((long)local_1d8 + 0x1a) != 0) ||
                                    ((local_1d8[7] != 0 || (local_1d8[10] != 0)))) {
                              iVar7 = fix_problem(param_1,0x10034,&local_148);
joined_r0x001256fa:
                              if (iVar7 != 0) {
                                bVar24 = false;
                                memset(local_1d8,0,local_240);
                                ext2fs_icount_store(param_1[0x38],local_1e4,0);
                                e2fsck_write_inode_full
                                          (param_1,local_1e4,local_1d8,local_240,"pass1");
                              }
                              goto LAB_00124bfe;
                            }
                          }
                          else {
                            iVar7 = FUN_0011ec90(lVar12);
                            if (iVar7 == 0) {
                              uVar8 = 0xb;
                              if (*(int *)(*(long *)(lVar12 + 0x20) + 0x4c) != 0) {
                                uVar8 = *(uint *)(*(long *)(lVar12 + 0x20) + 0x54);
                              }
                              if (local_1e4 < uVar8) {
                                ext2fs_mark_inode_bitmap2(param_1[0x2d]);
                                uVar4 = (ushort)*local_1d8;
                                if (local_1e4 == 5) {
                                  if ((uVar4 & 0xf000) == 0x4000) goto LAB_00125c8c;
                                }
                                else if (local_1e4 == 7) {
                                  if ((uVar4 != 0) && ((uVar4 & 0xf000) != 0x8000))
                                  goto LAB_00125c8c;
                                }
                                else if (uVar4 != 0) {
LAB_00125c8c:
                                  iVar7 = fix_problem(param_1,0x10003,&local_148);
                                  if (iVar7 != 0) {
                                    *(ushort *)local_1d8 = 0;
                                    goto LAB_00125ce9;
                                  }
                                }
                                goto LAB_00125ca4;
                              }
LAB_00124bfe:
                              if (*(ushort *)((long)local_1d8 + 0x1a) != 0) {
                                if ((local_1d8[5] != 0) &&
                                   (iVar7 = fix_problem(param_1,0x10005,&local_148), iVar7 != 0)) {
                                  bVar24 = false;
                                  local_1d8[5] = 0;
                                  e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
                                }
                                goto LAB_00124c1b;
                              }
                            }
                            else {
                              ext2fs_mark_inode_bitmap2(param_1[0x2d],local_1e4);
                              lVar17 = *(long *)(lVar12 + 0x20);
                              iVar7 = FUN_00121fd0(*(undefined4 *)(lVar17 + 100));
                              if ((iVar7 != 0) &&
                                 (iVar7 = FUN_0011e190(lVar17,local_1e4), iVar7 != 0)) {
                                if (((*local_1d8 & 0xf000) != 0x8000) &&
                                   (iVar7 = fix_problem(param_1,0x10062,&local_148), iVar7 != 0))
                                goto LAB_00125cdf;
                                goto LAB_00125ca4;
                              }
                              if (((*(ushort *)((long)local_1d8 + 0x1a) != 0) || (local_1d8[7] != 0)
                                  ) || (local_1d8[10] != 0)) {
                                iVar7 = fix_problem(param_1,0x10063,&local_148);
                                goto joined_r0x001256fa;
                              }
                            }
                          }
                          goto LAB_001251aa;
                        }
                        if (((*local_1d8 & 0xf000) != 0x4000) &&
                           (iVar7 = fix_problem(param_1,0x10001,&local_148), iVar7 != 0))
                        goto LAB_00125b08;
                        if (local_1d8[5] == 0) {
                          if (*(ushort *)((long)local_1d8 + 0x1a) == 0) goto LAB_001251aa;
LAB_00124c1b:
                          ext2fs_mark_inode_bitmap2(param_1[0x2d],local_1e4);
                          lVar17 = *(long *)(lVar12 + 0x20);
                          if (*(int *)(lVar17 + 0x48) == 1) {
                            if (((local_1d8[0x1c] != 0) ||
                                ((char)local_1d8[0x1d] != '\0' ||
                                 *(char *)((long)local_1d8 + 0x75) != '\0')) ||
                               ((iVar7 = FUN_0011fe40(*(undefined4 *)(lVar17 + 0x60)),
                                puVar18 = extraout_RDX_02, iVar7 == 0 &&
                                ((puVar18 = extraout_RDX_02, (*extraout_RDX_02 & 0xf000) == 0x4000
                                 && (puVar18 = extraout_RDX_02, extraout_RDX_02[0x1b] != 0))))))
                            goto LAB_00125561;
                          }
                          else {
                            if ((local_1d8[0x1c] != 0) ||
                               (((iVar7 = FUN_0011fe40(*(undefined4 *)(lVar17 + 0x60)), iVar7 == 0
                                 && ((*extraout_RDX & 0xf000) == 0x4000)) &&
                                (*(int *)(extraout_RDX + 0x36) != 0)))) {
LAB_00125561:
                              FUN_0011e590(param_1,local_1e4);
                              lVar17 = *(long *)(lVar12 + 0x20);
                              puVar18 = local_1d8;
                              if (*(int *)(lVar17 + 0x48) == 1) goto LAB_00124c95;
                            }
                            iVar7 = FUN_001203b0();
                            if ((iVar7 == 0) && (*(short *)(extraout_RDX_00 + 0x76) != 0)) {
                              FUN_0011e590(param_1,local_1e4);
                              lVar17 = *(long *)(lVar12 + 0x20);
                              puVar18 = local_1d8;
                              if (*(int *)(lVar17 + 0x48) == 1) goto LAB_00124c95;
                            }
                            iVar7 = FUN_00121fe0(*(undefined4 *)(lVar17 + 100));
                            puVar18 = extraout_RDX_01;
                            if ((iVar7 == 0) &&
                               (puVar18 = extraout_RDX_01, (ushort)extraout_RDX_01[0x1d] != 0)) {
                              FUN_0011e590(param_1,local_1e4);
                              puVar18 = local_1d8;
                            }
                          }
LAB_00124c95:
                          if ((*(byte *)((long)puVar18 + 0x21) & 0x20) != 0) {
                            if (iVar6 == 0) {
                              iVar7 = fix_problem(param_1,0x1002f,&local_148);
                              if (iVar7 != 0) {
                                bVar24 = false;
                                local_1d8[8] = local_1d8[8] & 0xffffdfff;
                                e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
                              }
                            }
                            else {
                              lVar17 = param_1[0x31];
                              if (lVar17 == 0) {
                                FUN_0011e4e0(param_1);
                                lVar17 = param_1[0x31];
                              }
                              ext2fs_mark_inode_bitmap2(lVar17,local_1e4);
                            }
                          }
                          FUN_0011fb80(param_1,&local_148,&local_1a8);
                          FUN_001203d0(param_1,&local_148,local_1c8);
                          uVar8 = local_1d8[8];
                          if (((local_224 != 0) && ((uVar8 & 0x80000) != 0)) &&
                             ((*local_1d8 & 0xf000) == 0xa000)) {
                            iVar7 = ext2fs_inode_has_valid_blocks2(lVar12);
                            if ((iVar7 == 0) &&
                               (iVar7 = fix_problem(param_1,0x1005d,&local_148), iVar7 != 0)) {
                              bVar24 = false;
                              local_1d8[8] = local_1d8[8] & 0xfff7ffff;
                              e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
                              uVar8 = local_1d8[8];
                            }
                            else {
                              uVar8 = local_1d8[8];
                            }
                          }
                          if (((uVar8 & 0x800) != 0) &&
                             (iVar7 = add_encrypted_file(param_1,&local_148), iVar7 < 0))
                          goto LAB_00125b08;
                          if ((iVar5 != 0) && ((*(byte *)((long)local_1d8 + 0x23) & 0x40) != 0)) {
                            ext2fs_mark_inode_bitmap2(param_1[0x33],local_1e4);
                          }
                          uVar4 = (ushort)*local_1d8 & 0xf000;
                          if (uVar4 == 0x4000) {
                            ext2fs_mark_inode_bitmap2(param_1[0x2f],local_1e4);
                            e2fsck_add_dir_info(param_1,local_1e4,0);
                            *(int *)(param_1 + 0x5c) = (int)param_1[0x5c] + 1;
                            uVar8 = local_1d8[8];
                            if ((uVar8 & 0x40000000) != 0) {
                              FUN_0011ed80(param_1,local_1e4);
                              uVar8 = local_1d8[8];
                            }
                          }
                          else if (uVar4 == 0x8000) {
                            ext2fs_mark_inode_bitmap2(param_1[0x32],local_1e4);
                            *(int *)((long)param_1 + 0x2e4) = *(int *)((long)param_1 + 0x2e4) + 1;
                            uVar8 = local_1d8[8];
                          }
                          else {
                            if (uVar4 == 0x2000) {
                              iVar7 = e2fsck_pass1_check_device_inode(lVar12);
                              if (iVar7 != 0) {
                                FUN_0011e660(param_1,&local_148);
                                FUN_0011e6c0(param_1,&local_148);
                                FUN_0011e720(param_1,&local_148);
                                *(int *)((long)param_1 + 0x2ec) =
                                     *(int *)((long)param_1 + 0x2ec) + 1;
                                uVar8 = local_1d8[8];
                                goto LAB_00124d99;
                              }
                              goto LAB_00124d85;
                            }
                            if (uVar4 == 0x6000) {
                              iVar7 = e2fsck_pass1_check_device_inode(lVar12);
                              if (iVar7 == 0) goto LAB_00124d85;
                              FUN_0011e660(param_1,&local_148);
                              FUN_0011e6c0(param_1,&local_148);
                              FUN_0011e720(param_1,&local_148);
                              *(int *)(param_1 + 0x5d) = (int)param_1[0x5d] + 1;
                              uVar8 = local_1d8[8];
                              goto LAB_00124d99;
                            }
                            if (uVar4 == 0xa000) {
                              iVar7 = e2fsck_pass1_check_symlink
                                                (lVar12,local_1e4,local_1d8,local_1c8);
                              if (iVar7 == 0) {
                                uVar4 = (ushort)*local_1d8 & 0xf000;
                                goto LAB_00124d65;
                              }
                              FUN_0011e6c0(param_1,&local_148);
                              *(int *)((long)param_1 + 0x2f4) = *(int *)((long)param_1 + 0x2f4) + 1;
                              if ((*(byte *)((long)local_1d8 + 0x23) & 0x10) != 0)
                              goto LAB_001251aa;
                              iVar7 = ext2fs_is_fast_symlink();
                              if (iVar7 != 0) {
                                *(int *)(param_1 + 0x5f) = (int)param_1[0x5f] + 1;
                                FUN_001236a0(param_1,&local_148,local_1c8,&local_1a8);
                                goto LAB_001251aa;
                              }
LAB_00124d91:
                              uVar8 = local_1d8[8];
                            }
                            else {
LAB_00124d65:
                              if (uVar4 == 0x1000) {
                                iVar7 = e2fsck_pass1_check_device_inode(lVar12);
                                if (iVar7 == 0) goto LAB_00124d85;
                                FUN_0011e660(param_1,&local_148);
                                FUN_0011e6c0(param_1,&local_148);
                                FUN_0011e720(param_1,&local_148);
                                *(int *)((long)param_1 + 0x2fc) =
                                     *(int *)((long)param_1 + 0x2fc) + 1;
                                uVar8 = local_1d8[8];
                              }
                              else {
                                if ((uVar4 != 0xc000) ||
                                   (iVar7 = e2fsck_pass1_check_device_inode(lVar12), iVar7 == 0)) {
LAB_00124d85:
                                  FUN_0011e590(param_1,local_1e4);
                                  goto LAB_00124d91;
                                }
                                FUN_0011e660(param_1,&local_148);
                                FUN_0011e6c0(param_1,&local_148);
                                FUN_0011e720(param_1,&local_148);
                                *(int *)(param_1 + 0x61) = (int)param_1[0x61] + 1;
                                uVar8 = local_1d8[8];
                              }
                            }
                          }
LAB_00124d99:
                          if ((uVar8 & 0x10080000) == 0) {
                            uVar8 = local_1d8[0x16];
                            if (uVar8 != 0) {
                              *(int *)((long)param_1 + 0x30c) = *(int *)((long)param_1 + 0x30c) + 1;
                            }
                            if (local_1d8[0x17] == 0) {
                              if (local_1d8[0x18] != 0) goto LAB_00124dcf;
                              if ((uVar8 == 0) &&
                                 (lVar17 = ext2fs_file_acl_block(lVar12), lVar17 == 0))
                              goto LAB_00125688;
                            }
                            else {
                              uVar8 = local_1d8[0x18];
                              *(int *)(param_1 + 0x62) = (int)param_1[0x62] + 1;
                              if (uVar8 != 0) {
LAB_00124dcf:
                                *(int *)((long)param_1 + 0x314) =
                                     *(int *)((long)param_1 + 0x314) + 1;
                              }
                            }
                            puVar18 = (uint *)((long)DAT_001b7178 * 0xb8 + DAT_001b7180);
                            *puVar18 = local_1e4;
                            *(undefined8 *)(puVar18 + 2) = local_1a8;
                            *(undefined8 *)(puVar18 + 4) = uStack_1a0;
                            if ((uint)local_240 < 0xa0) {
                              if ((uint)local_240 < 8) {
                                if ((local_240 & 4) == 0) {
                                  if (((uint)local_240 != 0) &&
                                     (*(char *)(puVar18 + 6) = (char)*local_1d8,
                                     (local_240 & 2) != 0)) {
                                    *(undefined2 *)((long)puVar18 + local_240 + 0x16) =
                                         *(undefined2 *)((long)local_1d8 + (local_240 - 2));
                                  }
                                }
                                else {
                                  puVar18[6] = *local_1d8;
                                  *(undefined4 *)((long)puVar18 + local_240 + 0x14) =
                                       *(undefined4 *)((long)local_1d8 + (local_240 - 4));
                                }
                              }
                              else {
                                *(undefined8 *)(puVar18 + 6) = *(undefined8 *)local_1d8;
                                *(undefined8 *)((long)puVar18 + local_240 + 0x10) =
                                     *(undefined8 *)((long)local_1d8 + (local_240 - 8));
                                lVar17 = (long)puVar18 +
                                         (0x18 - (long)((ulong)(puVar18 + 8) & 0xfffffffffffffff8));
                                puVar19 = (undefined8 *)((long)local_1d8 - lVar17);
                                puVar20 = (undefined8 *)((ulong)(puVar18 + 8) & 0xfffffffffffffff8);
                                for (uVar15 = (ulong)((int)lVar17 + (uint)local_240 >> 3);
                                    uVar15 != 0; uVar15 = uVar15 - 1) {
                                  *puVar20 = *puVar19;
                                  puVar19 = puVar19 + (ulong)bVar25 * -2 + 1;
                                  puVar20 = puVar20 + (ulong)bVar25 * -2 + 1;
                                }
                              }
                            }
                            else {
                              uVar11 = *(undefined8 *)(local_1d8 + 2);
                              *(undefined8 *)(puVar18 + 6) = *(undefined8 *)local_1d8;
                              *(undefined8 *)(puVar18 + 8) = uVar11;
                              uVar11 = *(undefined8 *)(local_1d8 + 6);
                              *(undefined8 *)(puVar18 + 10) = *(undefined8 *)(local_1d8 + 4);
                              *(undefined8 *)(puVar18 + 0xc) = uVar11;
                              uVar11 = *(undefined8 *)(local_1d8 + 10);
                              *(undefined8 *)(puVar18 + 0xe) = *(undefined8 *)(local_1d8 + 8);
                              *(undefined8 *)(puVar18 + 0x10) = uVar11;
                              uVar11 = *(undefined8 *)(local_1d8 + 0xe);
                              *(undefined8 *)(puVar18 + 0x12) = *(undefined8 *)(local_1d8 + 0xc);
                              *(undefined8 *)(puVar18 + 0x14) = uVar11;
                              uVar11 = *(undefined8 *)(local_1d8 + 0x12);
                              *(undefined8 *)(puVar18 + 0x16) = *(undefined8 *)(local_1d8 + 0x10);
                              *(undefined8 *)(puVar18 + 0x18) = uVar11;
                              uVar11 = *(undefined8 *)(local_1d8 + 0x16);
                              *(undefined8 *)(puVar18 + 0x1a) = *(undefined8 *)(local_1d8 + 0x14);
                              *(undefined8 *)(puVar18 + 0x1c) = uVar11;
                              uVar11 = *(undefined8 *)(local_1d8 + 0x1a);
                              *(undefined8 *)(puVar18 + 0x1e) = *(undefined8 *)(local_1d8 + 0x18);
                              *(undefined8 *)(puVar18 + 0x20) = uVar11;
                              uVar11 = *(undefined8 *)(local_1d8 + 0x1e);
                              *(undefined8 *)(puVar18 + 0x22) = *(undefined8 *)(local_1d8 + 0x1c);
                              *(undefined8 *)(puVar18 + 0x24) = uVar11;
                              uVar11 = *(undefined8 *)(local_1d8 + 0x22);
                              *(undefined8 *)(puVar18 + 0x26) = *(undefined8 *)(local_1d8 + 0x20);
                              *(undefined8 *)(puVar18 + 0x28) = uVar11;
                              uVar11 = *(undefined8 *)(local_1d8 + 0x26);
                              *(undefined8 *)(puVar18 + 0x2a) = *(undefined8 *)(local_1d8 + 0x24);
                              *(undefined8 *)(puVar18 + 0x2c) = uVar11;
                            }
                            DAT_001b7178 = DAT_001b7178 + 1;
                          }
                          else {
LAB_00125688:
                            FUN_001236a0(param_1,&local_148,local_1c8,&local_1a8);
                          }
                          FUN_0011eff0(param_1,local_1e4,&local_148,bVar24);
                          if ((*(uint *)(param_1 + 9) & 1) != 0) goto LAB_00124ee8;
                          if (((*(uint *)(param_1 + 9) & 3) != 0) ||
                             (((int)param_1[0x4b] <= DAT_001b7178 &&
                              (FUN_001240b0(param_1), (*(byte *)(param_1 + 9) & 3) != 0))))
                          goto LAB_00124fc5;
                        }
                        else {
                          if (*(ushort *)((long)local_1d8 + 0x1a) != 0) {
                            iVar7 = fix_problem(param_1,0x10002,&local_148);
                            if (iVar7 != 0) {
                              bVar24 = false;
                              local_1d8[5] = 0;
                              e2fsck_write_inode(param_1,local_1e4,local_1d8,"pass1");
                            }
                            goto LAB_00124bfe;
                          }
LAB_001251aa:
                          FUN_0011eff0(param_1,local_1e4,&local_148,bVar24);
                          if ((*(byte *)(param_1 + 9) & 1) != 0) goto LAB_00124ee8;
                        }
                      }
                      else {
                        if (local_224 != 0) goto LAB_00124bb1;
                        if (((*(ushort *)((long)local_1d8 + 0x1a) == 0) && (1 < local_1e4 - 1)) &&
                           (local_1e4 != 8)) goto LAB_00124bba;
                        lVar17 = ext2fs_extent_header_verify(local_1d8 + 10,0x3c);
                        if ((lVar17 == 0) &&
                           (iVar7 = fix_problem(param_1,0x1005b,&local_148), iVar7 != 0)) {
                          FUN_0011e0e0(lVar3);
                          ext2fs_mark_super_dirty(lVar12);
                          if ((*(byte *)((long)local_1d8 + 0x22) & 8) == 0) {
                            local_224 = 1;
                            goto LAB_00125273;
                          }
                          local_224 = 1;
LAB_00124bb1:
                          if (local_1e4 == 1) {
                            bVar22 = bVar24;
                            if (bVar24 == false) goto LAB_0012505d;
                            goto LAB_00125081;
                          }
                          goto LAB_00124bba;
                        }
                        iVar7 = fix_problem(param_1,0x1005a,&local_148);
                        if (iVar7 == 0) {
                          local_224 = 0;
                          goto LAB_00124bb1;
                        }
LAB_00125b08:
                        e2fsck_clear_inode(param_1,local_1e4,local_1d8,0,"pass1");
                        if (local_1e4 == 1) {
                          ext2fs_mark_inode_bitmap2(param_1[0x2d]);
                        }
                      }
                      goto LAB_00124974;
                    }
                  }
                  else {
LAB_0012532e:
                    fix_problem(param_1,0x10028,&local_148);
LAB_0012533e:
                    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
                  }
                }
                else {
                  fix_problem(param_1,0x10061,&local_148);
                  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
                }
              }
              else {
                fix_problem(param_1,0x10027,&local_148);
                *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
              }
LAB_00124fc5:
              e2fsck_use_inode_shortcuts(param_1,0);
              ext2fs_free_mem(&DAT_001b7180);
              DAT_001b7180 = 0;
              if (local_1d0 != 0) {
                ext2fs_close_inode_scan();
              }
              if (local_1c8 != 0) {
                ext2fs_free_mem(&local_1c8);
              }
              if (local_1d8 != (uint *)0x0) {
                ext2fs_free_mem(&local_1d8);
              }
              *(undefined4 *)(param_1 + 0x45) = 0;
              if ((*(byte *)(param_1 + 9) & 3) == 0) {
                uVar9 = *(undefined8 *)(*param_1 + 8);
                uVar11 = dcgettext(0,"Pass 1",5);
                print_resource_track(param_1,uVar11,local_198,uVar9);
              }
              else {
                *(int *)(param_1 + 0x41) = (int)param_1[0x41] + 1;
              }
            }
            else {
              fix_problem(param_1,0x10026,&local_148);
              *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
            }
            goto LAB_00124ee8;
          }
        }
        local_f8 = 1;
        fix_problem(param_1,0x10025,&local_148);
        *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
        goto LAB_00124ee8;
      }
      local_f8 = 6;
    }
    else {
      local_f8 = 2;
    }
  }
  else {
LAB_00124f18:
    local_f8 = 1;
  }
  fix_problem(param_1,0x10024,&local_148);
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
LAB_00124ee8:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: dict_int_cmp @ 0x263c0

int dict_int_cmp(undefined8 param_1,int param_2,int param_3)

{
  return param_2 - param_3;
}



// Function: inode_dnode_free @ 0x263d0

void inode_dnode_free(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 extraout_RDX;
  long in_FS_OFFSET;
  long local_40 [2];
  long local_30;
  long local_28;
  long local_20;
  
  local_30 = *(long *)(param_1 + 0x28);
  local_28 = *(long *)(local_30 + 0xa8);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = 0;
  local_40[0] = param_1;
  if (local_28 != 0) {
    do {
      lVar1 = *(long *)(local_28 + 8);
      ext2fs_free_mem(&local_28,param_2,uVar2);
      uVar2 = extraout_RDX;
      local_28 = lVar1;
    } while (lVar1 != 0);
  }
  ext2fs_free_mem(&local_30,param_2,uVar2);
  ext2fs_free_mem(local_40);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: cluster_dnode_free @ 0x26460

void cluster_dnode_free(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 extraout_RDX;
  long in_FS_OFFSET;
  long local_40 [2];
  long local_30;
  long local_28;
  long local_20;
  
  local_30 = *(long *)(param_1 + 0x28);
  local_28 = *(long *)(local_30 + 8);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = 0;
  local_40[0] = param_1;
  if (local_28 != 0) {
    do {
      lVar1 = *(long *)(local_28 + 8);
      ext2fs_free_mem(&local_28,param_2,uVar2);
      uVar2 = extraout_RDX;
      local_28 = lVar1;
    } while (lVar1 != 0);
  }
  ext2fs_free_mem(&local_30,param_2,uVar2);
  ext2fs_free_mem(local_40);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: search_dirent_proc @ 0x264f0

char search_dirent_proc(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  int *in_stack_00000008;
  
  uVar1 = *param_3;
  if (((((uint)in_stack_00000008[2] < uVar1) || (uVar1 < (uint)in_stack_00000008[1])) ||
      (param_2 < 3)) ||
     ((iVar3 = ext2fs_test_inode_bitmap2(DAT_001b71a0,uVar1), iVar3 == 0 ||
      (lVar4 = dict_lookup(&DAT_001b71c0,*param_3), lVar4 == 0)))) {
    cVar2 = '\0';
  }
  else {
    iVar3 = *in_stack_00000008;
    if (**(int **)(lVar4 + 0x28) == 0) {
      iVar3 = iVar3 + -1;
      **(int **)(lVar4 + 0x28) = param_1;
      *in_stack_00000008 = iVar3;
    }
    cVar2 = (iVar3 == 0) * '\x02';
  }
  return cVar2;
}



// Function: add_dupe @ 0x26580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void add_dupe(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  int *piVar4;
  undefined8 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  lVar3 = dict_lookup(&DAT_001b7240,param_3);
  if (lVar3 == 0) {
    piVar6 = (int *)e2fsck_allocate_memory(param_1,0x10,"duplicate cluster header");
    *piVar6 = 0;
    piVar6[2] = 0;
    piVar6[3] = 0;
    dict_alloc_insert(&DAT_001b7240,param_3,piVar6);
  }
  else {
    piVar6 = *(int **)(lVar3 + 0x28);
  }
  piVar4 = (int *)e2fsck_allocate_memory(param_1,0x10,"inode element");
  uVar1 = *(undefined8 *)(piVar6 + 2);
  *piVar4 = param_2;
  *(undefined8 *)(piVar4 + 2) = uVar1;
  *piVar6 = *piVar6 + 1;
  *(int **)(piVar6 + 2) = piVar4;
  lVar3 = dict_lookup(&DAT_001b71c0,param_2);
  if (lVar3 == 0) {
    puVar7 = (undefined4 *)e2fsck_allocate_memory(param_1,0xb0,"duplicate inode header");
    if (param_2 == 2) {
      _DAT_001b72b0 = _DAT_001b72b0 + 1;
      *puVar7 = 2;
    }
    else {
      *puVar7 = 0;
    }
    uVar1 = *param_4;
    uVar2 = param_4[1];
    puVar7[1] = 0;
    *(undefined8 *)(puVar7 + 2) = uVar1;
    *(undefined8 *)(puVar7 + 4) = uVar2;
    uVar1 = param_4[2];
    uVar2 = param_4[3];
    *(undefined8 *)(puVar7 + 0x2a) = 0;
    *(undefined8 *)(puVar7 + 6) = uVar1;
    *(undefined8 *)(puVar7 + 8) = uVar2;
    uVar1 = param_4[5];
    *(undefined8 *)(puVar7 + 10) = param_4[4];
    *(undefined8 *)(puVar7 + 0xc) = uVar1;
    uVar1 = param_4[7];
    *(undefined8 *)(puVar7 + 0xe) = param_4[6];
    *(undefined8 *)(puVar7 + 0x10) = uVar1;
    uVar1 = param_4[9];
    *(undefined8 *)(puVar7 + 0x12) = param_4[8];
    *(undefined8 *)(puVar7 + 0x14) = uVar1;
    uVar1 = param_4[0xb];
    *(undefined8 *)(puVar7 + 0x16) = param_4[10];
    *(undefined8 *)(puVar7 + 0x18) = uVar1;
    uVar1 = param_4[0xd];
    *(undefined8 *)(puVar7 + 0x1a) = param_4[0xc];
    *(undefined8 *)(puVar7 + 0x1c) = uVar1;
    uVar1 = param_4[0xf];
    *(undefined8 *)(puVar7 + 0x1e) = param_4[0xe];
    *(undefined8 *)(puVar7 + 0x20) = uVar1;
    uVar1 = param_4[0x11];
    *(undefined8 *)(puVar7 + 0x22) = param_4[0x10];
    *(undefined8 *)(puVar7 + 0x24) = uVar1;
    uVar1 = param_4[0x13];
    *(undefined8 *)(puVar7 + 0x26) = param_4[0x12];
    *(undefined8 *)(puVar7 + 0x28) = uVar1;
    dict_alloc_insert(&DAT_001b71c0,param_2,puVar7);
  }
  else {
    puVar7 = *(undefined4 **)(lVar3 + 0x28);
  }
  puVar5 = (undefined8 *)e2fsck_allocate_memory(param_1,0x10,"cluster element");
  uVar1 = *(undefined8 *)(puVar7 + 0x2a);
  *puVar5 = param_3;
  puVar5[1] = uVar1;
  puVar7[1] = puVar7[1] + 1;
  *(undefined8 **)(puVar7 + 0x2a) = puVar5;
  return;
}



// Function: process_pass1b_block @ 0x26760

undefined8
process_pass1b_block(long param_1,ulong *param_2,long param_3,undefined8 param_4,undefined8 param_5,
            long *param_6)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  byte bVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  
  if (*param_2 != 0) {
    lVar1 = *param_6;
    bVar5 = (byte)*(undefined4 *)(param_1 + 0xc0);
    uVar3 = *param_2 >> (bVar5 & 0x3f);
    lVar8 = param_3 >> (bVar5 & 0x3f);
    iVar2 = ext2fs_test_block_bitmap2(*(undefined8 *)(lVar1 + 0x1a8));
    if (iVar2 != 0) {
      iVar2 = (int)param_6[1];
      if (iVar2 != 1) {
        uVar4 = *param_2;
        lVar6 = param_6[6];
        if (param_6[4] + 1U != uVar4) {
          if (param_6[4] != 0) {
            uVar7 = 0x11002;
            if (*(long *)(lVar6 + 0x28) != *(long *)(lVar6 + 0x30)) {
              uVar7 = 0x11008;
            }
            fix_problem(lVar1,uVar7);
            uVar4 = *param_2;
            iVar2 = (int)param_6[1];
            lVar6 = param_6[6];
          }
          *(ulong *)(lVar6 + 0x28) = uVar4;
          uVar4 = *param_2;
        }
        *(ulong *)(lVar6 + 0x30) = uVar4;
        param_6[4] = uVar4;
      }
      *(int *)((long)param_6 + 0xc) = *(int *)((long)param_6 + 0xc) + 1;
      ext2fs_mark_inode_bitmap2(DAT_001b71a0,iVar2);
      if (((param_3 < 0) || (param_6[2] != lVar8)) || (param_6[3] != uVar3)) {
        FUN_00126580(lVar1,(int)param_6[1],
                     *param_2 >> ((byte)*(undefined4 *)(param_1 + 0xc0) & 0x3f),param_6[5]);
      }
    }
    param_6[2] = lVar8;
    param_6[3] = uVar3;
  }
  return 0;
}



// Function: pass1c @ 0x26880

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pass1c(long *param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long in_FS_OFFSET;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 local_98 [104];
  long local_30;
  
  lVar1 = *param_1;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_98);
  if ((*(byte *)((long)param_1 + 0x4c) & 2) == 0) {
    fix_problem(param_1,0x12000,local_98);
  }
  local_a4 = DAT_001b72b4 - _DAT_001b72b0;
  local_a0 = 0xb;
  puVar2 = *(undefined4 **)(lVar1 + 0x20);
  if (puVar2[0x13] != 0) {
    local_a0 = puVar2[0x15];
  }
  local_9c = *puVar2;
  ext2fs_dblist_dir_iterate(*(undefined8 *)(lVar1 + 0x90),0,param_2,FUN_001264f0,&local_a4);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: decrement_badcount @ 0x26b50

void decrement_badcount(long *param_1,ulong param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *param_3 + -1;
  *param_3 = iVar1;
  if (0 < iVar1) {
    if (iVar1 != 1) {
      return;
    }
    iVar1 = FUN_00126a70(*param_1);
    if (iVar1 != 0) {
      return;
    }
  }
  iVar1 = FUN_00126950(*param_1,param_2 >> ((byte)*(undefined4 *)(*param_1 + 0xc0) & 0x3f));
  if (iVar1 != 0) {
    return;
  }
  ext2fs_unmark_block_bitmap2(param_1[0x35],param_2);
  return;
}



// Function: deferred_dec_badcount @ 0x26bc0

void deferred_dec_badcount(long param_1)

{
  if (*(long *)(param_1 + 0x38) != 0) {
    FUN_00126b50(*(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x40));
    *(undefined8 *)(param_1 + 0x38) = 0;
    return;
  }
  return;
}



// Function: delete_file_block @ 0x26bf0

undefined8
delete_file_block(long param_1,ulong *param_2,long param_3,undefined8 param_4,undefined8 param_5,
            long *param_6)

{
  ulong uVar1;
  long *plVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  byte bVar6;
  
  uVar1 = *param_2;
  if (uVar1 != 0) {
    plVar2 = (long *)*param_6;
    bVar6 = (byte)*(undefined4 *)(param_1 + 0xc0);
    param_3 = param_3 >> (bVar6 & 0x3f);
    iVar3 = ext2fs_test_block_bitmap2(plVar2[0x35],uVar1);
    if (iVar3 == 0) {
      if (*param_2 % (ulong)(long)(1 << ((byte)*(undefined4 *)(*plVar2 + 0xc0) & 0x1f)) == 0) {
        ext2fs_block_alloc_stats2(param_1,*param_2,0xffffffff);
      }
      *(int *)((long)param_6 + 0xc) = *(int *)((long)param_6 + 0xc) + 1;
    }
    else {
      lVar4 = dict_lookup(&DAT_001b7240,uVar1 >> (bVar6 & 0x3f));
      if (lVar4 == 0) {
        uVar1 = *param_2;
        uVar5 = dcgettext(0,"internal error: can\'t find dup_blk for %llu\n",5);
        com_err("delete_file_block",0,uVar5,uVar1);
      }
      else if (param_6[2] != param_3) {
        FUN_00126b50(plVar2,*param_2,*(undefined8 *)(lVar4 + 0x28));
        *(int *)((long)param_6 + 0xc) = *(int *)((long)param_6 + 0xc) + 1;
      }
    }
    param_6[2] = param_3;
  }
  return 0;
}



// Function: clone_file_block @ 0x26d20

char clone_file_block(long param_1,ulong *param_2,ulong param_3,undefined8 param_4,undefined8 param_5,
                 long *param_6)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  byte bVar7;
  ulong uVar8;
  ulong *puVar9;
  long in_FS_OFFSET;
  char cVar10;
  long local_50;
  ulong local_48;
  long local_40;
  
  plVar1 = (long *)param_6[5];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00126bc0(param_6);
  uVar8 = *param_2;
  if (uVar8 == 0) goto LAB_00126ddf;
  lVar5 = *plVar1;
  cVar10 = true;
  iVar2 = FUN_00126d10(*(undefined4 *)(*(long *)(lVar5 + 0x20) + 100));
  if (iVar2 != 0) {
    cVar10 = (*(uint *)((long)plVar1 + 0x4c) & 0x40008) != 0x40008;
  }
  bVar7 = (byte)*(undefined4 *)(param_1 + 0xc0);
  lVar4 = (long)param_3 >> (bVar7 & 0x3f);
  iVar2 = FUN_00126950(lVar5,uVar8 >> (bVar7 & 0x3f));
  if ((param_6[1] != lVar4) || (uVar8 = param_6[2], uVar8 == 0)) {
    iVar3 = ext2fs_test_block_bitmap2(plVar1[0x35],*param_2);
    if (iVar3 != 0) {
      lVar5 = dict_lookup(&DAT_001b7240,*param_2 >> ((byte)*(undefined4 *)(param_1 + 0xc0) & 0x3f));
      if (lVar5 != 0) {
        local_50 = *(long *)(lVar5 + 0x28);
        puVar9 = &local_48;
        local_48 = 0;
        param_6[1] = lVar4;
        uVar6 = FUN_001263a0(param_6[6]);
        lVar5 = ext2fs_map_cluster_block(param_1,*(undefined4 *)((long)param_6 + 0x1c),uVar6);
        if (((lVar5 == 0) && (local_48 != 0)) &&
           (bVar7 = (byte)*(undefined4 *)(*plVar1 + 0xc0),
           local_48 >> (bVar7 & 0x3f) != *param_2 >> (bVar7 & 0x3f))) {
LAB_00126ec2:
          param_6[2] = local_48;
          uVar8 = local_48;
          goto LAB_00126ed9;
        }
        lVar5 = ext2fs_new_block2(param_1,0,plVar1[0x34],puVar9);
        if (lVar5 == 0) {
          iVar3 = FUN_00126d10(*(undefined4 *)(*(long *)(param_1 + 0x20) + 100));
          if (iVar3 != 0) {
            ext2fs_block_alloc_stats2(param_1,local_48,1);
          }
          goto LAB_00126ec2;
        }
        goto LAB_00126f90;
      }
      uVar8 = *param_2;
      uVar6 = dcgettext(0,"internal error: can\'t find dup_blk for %llu\n",5);
      com_err("clone_file_block",0,uVar6,uVar8);
    }
LAB_00126ddf:
    cVar10 = '\0';
    goto LAB_00126de2;
  }
  local_50 = 0;
LAB_00126ed9:
  iVar3 = 1 << ((byte)*(undefined4 *)(param_1 + 0xc0) & 0x1f);
  local_48 = ((long)-iVar3 & uVar8) + ((long)(iVar3 + -1) & param_3);
  if (((((long)param_3 < 0) || ((int)param_6[3] == 0)) ||
      (lVar5 = ext2fs_set_dir_block2
                         (*(undefined8 *)(param_1 + 0x90),(int)param_6[3],local_48,param_3),
      lVar5 == 0)) &&
     (lVar5 = io_channel_read_blk64(*(undefined8 *)(param_1 + 8),*param_2,1,param_6[4]), lVar5 == 0)
     ) {
    if ((bool)cVar10 == false) {
      uVar8 = *param_2;
      lVar5 = plVar1[0x34];
    }
    else {
      lVar5 = io_channel_write_blk64(*(undefined8 *)(param_1 + 8),local_48,1,param_6[4]);
      if (lVar5 != 0) goto LAB_00126f90;
      uVar8 = *param_2;
      lVar5 = plVar1[0x34];
    }
    if (iVar2 == 0) {
      param_6[7] = local_50;
    }
    else {
      param_6[7] = 0;
    }
    param_6[8] = uVar8;
    *param_2 = local_48;
    ext2fs_mark_block_bitmap2(lVar5);
    ext2fs_mark_block_bitmap2(*(undefined8 *)(param_1 + 0x58),local_48);
  }
  else {
LAB_00126f90:
    *param_6 = lVar5;
    cVar10 = '\x02';
  }
LAB_00126de2:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return cVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: clone_file @ 0x27070

long clone_file(long *param_1,int param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  undefined8 uVar11;
  long in_FS_OFFSET;
  ulong local_100;
  long local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  int local_e0;
  int local_dc;
  undefined1 local_d8 [8];
  long *local_d0;
  long local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  long local_a8;
  int local_a0;
  char *local_48;
  long local_40;
  
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(&local_a8);
  local_f8 = 0;
  local_e0 = 0;
  local_f0 = 0xffffffffffffffff;
  local_e8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_dc = param_2;
  local_d0 = param_1;
  local_c8 = param_3 + 8;
  lVar4 = ext2fs_get_mem(*(undefined4 *)(lVar1 + 0x28),local_d8);
  if (lVar4 == 0) {
    iVar3 = ext2fs_test_inode_bitmap2(param_1[0x2f],param_2);
    if (iVar3 != 0) {
      local_e0 = param_2;
    }
    local_48 = "clone_file";
    local_a0 = param_2;
    uVar5 = FUN_001263a0(param_3 + 8);
    iVar3 = ext2fs_inode_has_valid_blocks2(lVar1,uVar5);
    if (iVar3 != 0) {
      local_a8 = ext2fs_block_iterate3(lVar1,param_2,0,param_4,FUN_00126d20);
    }
    FUN_00126bc0(&local_f8);
    ext2fs_mark_bb_dirty(lVar1);
    lVar4 = local_f8;
    if (local_a8 == 0) {
      if (local_f8 != 0) {
        uVar5 = dcgettext(0,"returned from clone_file_block",5);
        com_err("clone_file",local_f8,&DAT_00178907,uVar5);
        lVar4 = local_f8;
        ext2fs_free_mem(local_d8);
        goto LAB_00127113;
      }
      e2fsck_read_inode_full(param_1,param_2,uVar5,0xa0,"clone file EA");
      uVar6 = ext2fs_file_acl_block(lVar1,uVar5);
      local_100 = uVar6;
      if ((uVar6 != 0) &&
         (iVar3 = FUN_00126d20(lVar1,&local_100,0xfffffffffffffffb,0,0,&local_f8), iVar3 == 1)) {
        ext2fs_file_acl_block_set(lVar1,uVar5,local_100);
        e2fsck_write_inode_full(param_1,param_2,uVar5,0xa0,"clone file EA");
        lVar7 = dict_lookup(&DAT_001b7240,uVar6 >> ((byte)*(undefined4 *)(lVar1 + 0xc0) & 0x3f));
        if (lVar7 == 0) {
          uVar5 = dcgettext(0,"internal error: couldn\'t lookup EA block record for %llu",5);
          com_err("clone_file",0,uVar5,uVar6);
        }
        else {
          lVar7 = *(long *)(lVar7 + 0x28);
          for (piVar2 = *(int **)(lVar7 + 8); piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 2))
          {
            if (*piVar2 != param_2) {
              lVar8 = dict_lookup(&DAT_001b71c0);
              if (lVar8 == 0) {
                iVar3 = *piVar2;
                uVar5 = dcgettext(0,"internal error: couldn\'t lookup EA inode record for %u",5);
                com_err("clone_file",0,uVar5,iVar3);
                break;
              }
              uVar9 = FUN_001263a0(*(long *)(lVar8 + 0x28) + 8);
              uVar10 = ext2fs_file_acl_block(lVar1,uVar9);
              if (uVar10 == uVar6) {
                uVar11 = ext2fs_file_acl_block(lVar1,uVar5);
                ext2fs_file_acl_block_set(lVar1,uVar9,uVar11);
                e2fsck_write_inode_full(param_1,*piVar2,uVar9,0xa0,"clone file EA");
                FUN_00126b50(param_1,uVar6,lVar7);
              }
            }
          }
        }
      }
    }
    else {
      fix_problem(param_1,0x11006,&local_a8);
      lVar4 = local_a8;
    }
    ext2fs_free_mem(local_d8);
  }
LAB_00127113:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: delete_file @ 0x274a0

void delete_file(long *param_1,undefined4 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  long in_FS_OFFSET;
  int local_f4;
  undefined8 local_f0;
  long *local_e8;
  undefined4 local_e0;
  int local_dc;
  undefined8 local_d8;
  long local_a8;
  undefined4 local_a0;
  undefined8 local_80;
  char *local_48;
  long local_40;
  
  lVar6 = param_3 + 8;
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(&local_a8);
  local_dc = 0;
  local_48 = "delete_file";
  local_d8 = 0xffffffffffffffff;
  local_e8 = param_1;
  local_e0 = param_2;
  local_a0 = param_2;
  uVar3 = FUN_001263a0(lVar6);
  iVar2 = ext2fs_inode_has_valid_blocks2(lVar1,uVar3);
  if (iVar2 != 0) {
    local_a8 = ext2fs_block_iterate3(lVar1,param_2,8,param_4,FUN_00126bf0,&local_e8);
  }
  if (local_a8 != 0) {
    fix_problem(param_1,0x11006,&local_a8);
  }
  if (param_1[0x2e] != 0) {
    ext2fs_unmark_inode_bitmap2(param_1[0x2e],param_2);
  }
  if (param_1[0x32] != 0) {
    ext2fs_unmark_inode_bitmap2(param_1[0x32],param_2);
  }
  ext2fs_unmark_inode_bitmap2(param_1[0x2f],param_2);
  ext2fs_unmark_inode_bitmap2(param_1[0x2d],param_2);
  ext2fs_inode_alloc_stats2(lVar1,param_2,0xffffffff,(*(ushort *)(param_3 + 8) & 0xf000) == 0x4000);
  quota_data_sub(param_1[0x4f],lVar6,param_2,local_dc * *(int *)(lVar1 + 0x28));
  quota_data_inodes(param_1[0x4f],lVar6,param_2,0xffffffff);
  e2fsck_read_inode_full(param_1,param_2,uVar3,0xa0,"delete_file");
  e2fsck_clear_inode(param_1,param_2,uVar3,0,"delete_file");
  lVar4 = ext2fs_file_acl_block(lVar1,uVar3);
  if ((lVar4 == 0) ||
     (iVar2 = FUN_00127490(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x5c)), iVar2 == 0))
  goto LAB_00127633;
  uVar5 = ext2fs_file_acl_block(lVar1,uVar3);
  local_f4 = 1;
  local_f0 = uVar5;
  local_a8 = ext2fs_adjust_ea_refcount3(lVar1,uVar5,param_4,0xffffffff,&local_f4,param_2);
  if (local_a8 == 0x7f2bb75a) {
    local_a8 = 0;
    local_f4 = 1;
LAB_00127761:
    iVar2 = ext2fs_test_block_bitmap2(param_1[0x35],uVar5);
    if (iVar2 == 0) goto LAB_00127633;
  }
  else {
    if (local_a8 != 0) {
      local_80 = uVar5;
      fix_problem(param_1,0x11007,&local_a8);
    }
    if (local_f4 != 0) goto LAB_00127761;
  }
  FUN_00126bf0(lVar1,&local_f0,0xfffffffffffffffb,0,0,&local_e8);
  ext2fs_file_acl_block_set(lVar1,uVar3,local_f0);
  quota_data_sub(param_1[0x4f],lVar6,param_2,*(undefined4 *)(lVar1 + 0x28));
LAB_00127633:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: pass1d @ 0x277b0

void pass1d(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  undefined4 *puVar12;
  bool bVar13;
  ulong uVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  long in_FS_OFFSET;
  undefined1 auVar18 [16];
  long local_b0;
  long local_a8;
  int local_a0;
  undefined4 local_98;
  undefined8 local_90;
  long local_70;
  long local_58;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = *param_1;
  clear_problem_context(&local_a8);
  if ((*(byte *)((long)param_1 + 0x4c) & 2) == 0) {
    fix_problem(param_1,0x13000,&local_a8);
  }
  e2fsck_read_bitmaps(param_1);
  local_58 = (long)DAT_001b72b4;
  fix_problem(param_1,0x13004,&local_a8);
  local_b0 = e2fsck_allocate_memory(param_1,DAT_001b71f0 * 4,"Shared inode list");
  lVar8 = dict_first(&DAT_001b71c0);
  bVar4 = false;
  do {
    if (lVar8 == 0) {
      ext2fs_free_mem(&local_b0);
      if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    iVar7 = (int)*(ulong *)(lVar8 + 0x20);
    uVar14 = *(ulong *)(lVar8 + 0x20) & 0xffffffff;
    if ((iVar7 != 1) && (iVar7 != 7)) {
      puVar2 = *(undefined4 **)(lVar8 + 0x28);
      iVar17 = 0;
      bVar13 = true;
      for (puVar3 = *(undefined8 **)(puVar2 + 0x2a); puVar3 != (undefined8 *)0x0;
          puVar3 = (undefined8 *)puVar3[1]) {
        lVar9 = dict_lookup(&DAT_001b7240,*puVar3);
        if (lVar9 != 0) {
          piVar16 = *(int **)(lVar9 + 0x28);
          if (1 < *piVar16) {
            bVar13 = false;
          }
          iVar6 = FUN_00126950(*param_1,*puVar3);
          piVar16 = *(int **)(piVar16 + 2);
          bVar5 = true;
          if (iVar6 == 0) {
            bVar5 = bVar4;
          }
          bVar4 = bVar5;
          if (iVar6 != 0) {
            bVar13 = false;
          }
joined_r0x0012791e:
          if (piVar16 != (int *)0x0) {
            do {
              iVar6 = *piVar16;
              if (iVar6 != iVar7) {
                if (iVar17 < 1) {
                  iVar15 = 0;
                }
                else {
                  uVar10 = 1;
                  do {
                    if (iVar6 == *(int *)(local_b0 + -4 + uVar10 * 4)) goto LAB_0012795d;
                    iVar15 = (int)uVar10;
                    uVar10 = uVar10 + 1;
                  } while (iVar17 + 1 != uVar10);
                }
                if (iVar15 == iVar17) goto code_r0x00127b39;
              }
LAB_0012795d:
              piVar16 = *(int **)(piVar16 + 2);
              if (piVar16 == (int *)0x0) break;
            } while( true );
          }
        }
      }
      puVar12 = puVar2;
      local_90 = FUN_001263a0(puVar2 + 2);
      local_98 = *puVar12;
      local_70 = (long)(int)puVar12[1];
      local_a0 = iVar7;
      if (bVar4) {
        local_58 = (long)(iVar17 + 1);
        fix_problem(param_1,0x13001,&local_a8);
        local_70 = 0;
        local_58 = 0;
        fix_problem(param_1,0x13003,&local_a8);
      }
      else {
        local_58 = (long)iVar17;
        fix_problem(param_1,0x13001,&local_a8);
        local_70 = 0;
        local_58 = 0;
      }
      lVar9 = 0;
      if (iVar17 < 1) {
        if ((bVar13) && (iVar17 != 0 || bVar4)) goto LAB_00127bdb;
      }
      else {
        do {
          lVar11 = dict_lookup(&DAT_001b71c0,*(undefined4 *)(local_b0 + lVar9));
          if (lVar11 != 0) {
            auVar18 = FUN_001263a0(*(long *)(lVar11 + 0x28) + 8,0x13002);
            local_90 = auVar18._0_8_;
            local_a0 = *(int *)(local_b0 + lVar9);
            local_98 = *auVar18._8_8_;
            fix_problem(param_1);
          }
          lVar9 = lVar9 + 4;
        } while ((long)iVar17 * 4 - lVar9 != 0);
        if (bVar13) {
LAB_00127bdb:
          fix_problem(param_1,0x13005,&local_a8);
          goto LAB_00127ad8;
        }
      }
      if (((*(byte *)((long)param_1 + 0x4e) & 4) != 0) ||
         (iVar7 = fix_problem(param_1,0x13006,&local_a8), iVar7 != 0)) {
        local_a8 = FUN_00127070(param_1,uVar14,puVar2,param_2);
        if (local_a8 == 0) goto LAB_00127ad8;
        fix_problem(param_1,0x13008,&local_a8);
      }
      if (((*(byte *)((long)param_1 + 0x4e) & 4) == 0) &&
         (iVar7 = fix_problem(param_1,0x13007,&local_a8), iVar7 != 0)) {
        FUN_001274a0(param_1,uVar14,puVar2,param_2);
      }
      else {
        ext2fs_unmark_valid(uVar1);
      }
    }
LAB_00127ad8:
    lVar8 = dict_next(&DAT_001b71c0,lVar8);
  } while( true );
code_r0x00127b39:
  piVar16 = *(int **)(piVar16 + 2);
  lVar9 = (long)iVar17;
  iVar17 = iVar17 + 1;
  *(int *)(local_b0 + lVar9 * 4) = iVar6;
  goto joined_r0x0012791e;
}



// Function: pass1b @ 0x27c30

void pass1b(long *param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  undefined8 uVar6;
  long in_FS_OFFSET;
  uint local_1ac;
  undefined8 local_1a8;
  undefined8 local_1a0;
  long *local_198;
  uint local_190;
  int local_18c;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined1 *local_170;
  long *local_168;
  long local_158;
  uint local_150;
  long local_130;
  long local_128;
  char *local_f8;
  undefined1 local_e8 [168];
  long local_40;
  
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_1ac = 0;
  clear_problem_context(&local_158);
  if ((*(byte *)((long)param_1 + 0x4c) & 2) == 0) {
    fix_problem(param_1,0x11000,&local_158);
  }
  local_158 = ext2fs_open_inode_scan(lVar1,*(undefined4 *)((long)param_1 + 0x25c),&local_1a8);
  if (local_158 == 0) {
    lVar3 = FUN_001263a0(local_e8);
    param_1[0x44] = lVar3;
    local_f8 = "pass1b";
    local_198 = param_1;
    local_168 = &local_158;
    while( true ) {
      do {
        if ((local_1ac % (uint)(*(int *)(*(long *)(lVar1 + 0x20) + 0x28) << 2) == 1) &&
           (lVar4 = e2fsck_mmp_update(lVar1), lVar4 != 0)) {
                    /* WARNING: Subroutine does not return */
          fatal_error(param_1,0);
        }
        local_158 = ext2fs_get_next_inode_full(local_1a8,&local_1ac,lVar3,0xa0);
      } while (local_158 == 0x7f2bb742);
      if (local_158 != 0) break;
      if (local_1ac == 0) {
        ext2fs_close_inode_scan(local_1a8);
        e2fsck_use_inode_shortcuts(param_1,0);
        goto LAB_00127f2d;
      }
      *(uint *)(param_1 + 0x43) = local_1ac;
      local_150 = local_1ac;
      if ((local_1ac == 1) || (iVar2 = ext2fs_test_inode_bitmap2(param_1[0x2d]), iVar2 != 0)) {
        local_190 = local_1ac;
        local_168[6] = 0;
        local_168[5] = 0;
        local_18c = 0;
        local_188 = 0xffffffffffffffff;
        local_180 = 0xffffffffffffffff;
        local_178 = 0;
        local_170 = local_e8;
        iVar2 = ext2fs_inode_has_valid_blocks2(lVar1,lVar3);
        if ((iVar2 == 0) && (local_1ac != 1)) {
          iVar2 = FUN_00127490(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x5c));
        }
        else {
          local_158 = ext2fs_block_iterate3(lVar1,local_1ac,8,param_2,FUN_00126760,&local_198);
          iVar2 = FUN_00127490(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x5c));
        }
        if ((iVar2 != 0) && (lVar4 = ext2fs_file_acl_block(lVar1,lVar3), lVar4 != 0)) {
          local_1a0 = ext2fs_file_acl_block(lVar1,lVar3);
          FUN_00126760(lVar1,&local_1a0,0xfffffffffffffffb,0,0,&local_198);
          ext2fs_file_acl_block_set(lVar1,lVar3,local_1a0);
        }
        if (local_18c != 0) {
          if (local_1ac != 1) {
            uVar6 = 0x11002;
            if (local_130 != local_128) {
              uVar6 = 0x11008;
            }
            fix_problem(param_1,uVar6,local_168);
          }
          end_problem_latch(param_1);
          uVar5 = 0xb;
          if (*(int *)(*(long *)(lVar1 + 0x20) + 0x4c) != 0) {
            uVar5 = *(uint *)(*(long *)(lVar1 + 0x20) + 0x54);
          }
          if ((local_1ac == 2) || (uVar5 <= local_1ac)) {
            DAT_001b72b4 = DAT_001b72b4 + 1;
          }
        }
        if (local_158 != 0) {
          fix_problem(param_1,0x11006,&local_158);
        }
      }
    }
    local_150 = local_1ac;
  }
  fix_problem(param_1,0x11004,&local_158);
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
LAB_00127f2d:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_pass1_dupblocks @ 0x27f90

void e2fsck_pass1_dupblocks(long *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long in_FS_OFFSET;
  undefined1 local_f0 [8];
  undefined1 local_e8 [80];
  long local_98 [13];
  long local_30;
  
  lVar3 = *param_1;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_98);
  uVar2 = dcgettext(0,"multiply claimed inode map",5);
  local_98[0] = e2fsck_allocate_inode_bitmap(lVar3,uVar2,2,"inode_dup_map",&DAT_001b71a0);
  if (local_98[0] == 0) {
    dict_init(&DAT_001b71c0,0xffffffffffffffff,FUN_001263c0);
    dict_init(&DAT_001b7240,0xffffffffffffffff,FUN_001263c0);
    dict_set_allocator(&DAT_001b71c0,0,FUN_001263d0,0);
    dict_set_allocator(&DAT_001b7240,0,FUN_00126460,0);
    init_resource_track(local_e8,*(undefined8 *)(*param_1 + 8));
    FUN_00127c30(param_1,param_2);
    print_resource_track(param_1,"Pass 1b",local_e8,*(undefined8 *)(*param_1 + 8));
    init_resource_track(local_e8,*(undefined8 *)(*param_1 + 8));
    FUN_00126880(param_1,param_2);
    print_resource_track(param_1,"Pass 1c",local_e8,*(undefined8 *)(*param_1 + 8));
    init_resource_track(local_e8,*(undefined8 *)(*param_1 + 8));
    FUN_001277b0(param_1,param_2);
    print_resource_track(param_1,"Pass 1d",local_e8,*(undefined8 *)(*param_1 + 8));
    lVar3 = *(long *)(*param_1 + 0x20);
    iVar1 = FUN_00126d10(*(undefined4 *)(lVar3 + 100));
    if ((iVar1 != 0) && ((*(byte *)((long)param_1 + 0x4e) & 4) != 0)) {
      lVar3 = ext2fs_blocks_count(lVar3);
      iVar1 = ext2fs_find_first_set_block_bitmap2
                        (param_1[0x35],*(undefined4 *)(*(long *)(*param_1 + 0x20) + 0x14),lVar3 + -1
                         ,local_f0);
      if ((iVar1 == 2) && ((*(byte *)((long)param_1 + 0x4c) & 8) == 0)) {
        lVar3 = *param_1;
        FUN_001263b0(*(undefined8 *)(lVar3 + 0x20));
        ext2fs_mark_super_dirty(lVar3);
      }
    }
    dict_free_nodes(&DAT_001b71c0);
    dict_free_nodes(&DAT_001b7240);
    ext2fs_free_inode_bitmap(DAT_001b71a0);
  }
  else {
    fix_problem(param_1,0x11005,local_98);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: htree_depth @ 0x28220

int htree_depth(long param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 == 1) {
    return 0;
  }
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    param_2 = (int *)(*(long *)(param_2 + 4) * 0x30 + *(long *)(param_1 + 0x10));
    if (*param_2 == 1) {
      return iVar1;
    }
  } while ((short)iVar1 != 32000);
  return iVar1;
}



// Function: special_dir_block_cmp @ 0x28260

int special_dir_block_cmp(int *param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 4);
  if (*(long *)(param_1 + 4) == 0) {
    if (lVar1 != 0) {
      return -1;
    }
  }
  else if (lVar1 == 0) {
    return 1;
  }
  if (*(long *)(param_1 + 2) != *(long *)(param_2 + 2)) {
    return (int)*(long *)(param_1 + 2) - (int)*(long *)(param_2 + 2);
  }
  iVar2 = *param_1 - *param_2;
  if (*param_1 == *param_2) {
    iVar2 = (int)*(long *)(param_1 + 4) - (int)lVar1;
  }
  return iVar2;
}



// Function: encrypted_check_name @ 0x282c0

undefined4 encrypted_check_name(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = ext2fs_dirent_name_len(param_2);
  if (0xf < iVar1) {
    return 0;
  }
  iVar1 = fix_problem(param_1,0x20050,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  ext2fs_unmark_valid(*param_1);
  return 0;
}



// Function: check_name @ 0x28330

undefined8 check_name(undefined8 param_1,long param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  iVar3 = -1;
  lVar4 = 0;
  do {
    iVar2 = ext2fs_dirent_name_len(param_2);
    if (iVar2 <= (int)lVar4) {
      return uVar5;
    }
    cVar1 = *(char *)(param_2 + 8 + lVar4);
    if ((cVar1 == '/') || (cVar1 == '\0')) {
      if ((iVar3 < 0) && (iVar3 = fix_problem(param_1,0x20008,param_3), iVar3 == 0)) {
        return 0;
      }
      *(undefined1 *)(param_2 + 8 + lVar4) = 0x2e;
      uVar5 = 1;
    }
    lVar4 = lVar4 + 1;
  } while( true );
}



// Function: dict_de_cmp @ 0x283c0

int dict_de_cmp(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ext2fs_dirent_name_len(param_2);
  iVar2 = ext2fs_dirent_name_len(param_3);
  if (iVar1 == iVar2) {
    iVar1 = memcmp((void *)(param_2 + 8),(void *)(param_3 + 8),(long)iVar1);
    return iVar1;
  }
  return iVar1 - iVar2;
}



// Function: dict_de_cf_cmp @ 0x28410

void dict_de_cf_cmp(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ext2fs_dirent_name_len(param_2);
  iVar2 = ext2fs_dirent_name_len(param_3);
  ext2fs_casefold_cmp(param_1,param_2 + 8,(long)iVar1,param_3 + 8,(long)iVar2);
  return;
}



// Function: needs_encryption @ 0x28460

bool needs_encryption(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  long in_FS_OFFSET;
  ushort local_a8 [68];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = ext2fs_dirent_file_type(param_2);
  if (iVar3 == 0) {
    uVar1 = *param_2;
    iVar3 = ext2fs_test_inode_bitmap2(*(undefined8 *)(param_1 + 400),uVar1);
    if (iVar3 == 0) {
      iVar3 = ext2fs_test_inode_bitmap2(*(undefined8 *)(param_1 + 0x178),uVar1);
      if (iVar3 == 0) {
        e2fsck_read_inode(param_1,uVar1,local_a8,"check_encryption_policy");
        bVar2 = (local_a8[0] & 0xf000) == 0x4000 || (local_a8[0] & 0xd000) == 0x8000;
        goto LAB_001284a2;
      }
    }
    bVar2 = true;
  }
  else {
    bVar2 = iVar3 == 7 || iVar3 - 1U < 2;
  }
LAB_001284a2:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_encryption_policy @ 0x28540

undefined8 check_encryption_policy(undefined8 param_1,undefined4 *param_2,int param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = find_encryption_policy(param_1,*param_2);
  if (iVar1 == param_3) {
    return 0;
  }
  uVar2 = 0x20052;
  if (iVar1 == -1) {
    iVar1 = FUN_00128460(param_1,param_2,param_4);
    uVar2 = 0x20051;
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar2 = fix_problem(param_1,uVar2,param_4);
  return uVar2;
}



// Function: check_encrypted_dirent @ 0x285b0

bool check_encrypted_dirent(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_001282c0(param_1,param_2,param_4);
  bVar2 = true;
  if (iVar1 == 0) {
    iVar1 = FUN_00128540(param_1,param_2,param_3,param_4);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}



// Function: fix_inline_dir_size @ 0x28610

long fix_inline_dir_size(undefined8 *param_1,undefined4 param_2,ulong *param_3,undefined8 param_4,
                 long param_5)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  size_t __n;
  ulong uVar6;
  long in_FS_OFFSET;
  undefined1 local_c8 [32];
  uint local_a8;
  long local_40;
  
  uVar1 = *param_1;
  uVar5 = *param_3;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((uVar5 < 0x3d) || (uVar2 = FUN_001281f0(1), (ulong)uVar2 + 0x3c <= uVar5)) {
    uVar6 = (uVar5 & 0xfffffffffffffffc) + 4;
    __n = uVar6 - uVar5;
  }
  else {
    __n = 0;
    uVar5 = 0x3c;
    uVar6 = 0x3c;
  }
  memset((void *)(param_5 + uVar5),0,__n);
  lVar4 = ext2fs_inline_data_set(uVar1,param_2,0,param_5,uVar6);
  if (lVar4 == 0x7f2bb7a7) {
    uVar6 = uVar6 - 4;
    lVar4 = ext2fs_inline_data_set(uVar1,param_2,0,param_5,uVar6);
    if (lVar4 != 0) {
      iVar3 = fix_problem(param_1,0x2004f,param_4);
      if (iVar3 == 0) goto LAB_001286c7;
      uVar6 = 0;
    }
  }
  else if (lVar4 != 0) {
    iVar3 = fix_problem(param_1,0x2004f,param_4);
    if (iVar3 == 0) goto LAB_001286c7;
    uVar6 = 0;
  }
  lVar4 = ext2fs_read_inode(uVar1,param_2,local_c8);
  if ((lVar4 == 0) && (lVar4 = ext2fs_inode_size_set(uVar1,local_c8,uVar6), lVar4 == 0)) {
    if (uVar6 == 0) {
      local_a8 = local_a8 & 0xefffffff;
    }
    lVar4 = ext2fs_write_inode(uVar1,param_2,local_c8);
    if (lVar4 == 0) {
      *param_3 = uVar6;
    }
  }
LAB_001286c7:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



// Function: salvage_directory @ 0x287e0

void salvage_directory(long param_1,uint *param_2,long param_3,int *param_4,uint param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  long in_FS_OFFSET;
  uint local_48;
  int local_44;
  long local_40;
  
  iVar5 = *param_4;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar10 = param_5 - iVar5;
  uVar6 = uVar10;
  uVar1 = uVar10;
  if (7 < uVar10) {
    uVar2 = ext2fs_dirent_name_len(param_2);
    ext2fs_get_rec_len(param_1,param_2,&local_48);
    uVar6 = local_48;
    iVar5 = *param_4;
    uVar8 = (ulong)param_6;
    uVar10 = param_5 - iVar5;
    iVar7 = uVar10 - local_48;
    iVar3 = FUN_001281f0(1,uVar8);
    if ((uVar6 == 8) && (iVar3 <= iVar7)) {
      memmove(param_2,param_2 + 2,(long)iVar7);
      *(undefined8 *)((long)param_2 + (long)iVar7) = 0;
      goto LAB_00128864;
    }
    uVar1 = local_48;
    if ((iVar7 < 0) && (8 < (int)uVar10)) {
      uVar9 = (ulong)uVar2;
      iVar3 = FUN_001281f0(uVar9 & 0xff,uVar8 & 0xffffffff);
      uVar1 = local_48;
      if ((iVar3 <= (int)uVar10) &&
         ((*param_2 <= **(uint **)(param_1 + 0x20) &&
          (sVar4 = strnlen((char *)(param_2 + 2),uVar9 & 0xffffffff), uVar1 = local_48,
          (uVar9 & 0xffffffff) == sVar4)))) {
        ext2fs_set_rec_len(param_1,uVar10,param_2);
        goto LAB_00128864;
      }
    }
  }
  local_48 = uVar1;
  if (param_3 == 0) {
    local_48 = uVar10;
    ext2fs_set_rec_len(param_1,uVar10,param_2);
    ext2fs_dirent_set_name_len(param_2,0);
    ext2fs_dirent_set_file_type(param_2,0);
    *param_2 = 0;
  }
  else if (((uVar6 == 0) || ((uVar6 & 3) != 0)) || (param_5 < uVar6 + iVar5)) {
    ext2fs_get_rec_len(param_1,param_3,&local_44);
    local_44 = (param_5 + local_44) - *param_4;
    ext2fs_set_rec_len(param_1,local_44,param_3);
    *param_4 = *(int *)(param_1 + 0x28);
  }
  else {
    ext2fs_get_rec_len(param_1,param_3,&local_44);
    local_44 = local_48 + local_44;
    ext2fs_set_rec_len(param_1,local_44,param_3);
    *param_4 = *param_4 + local_48;
  }
LAB_00128864:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: encoded_check_name @ 0x28a10

bool encoded_check_name(long *param_1,long param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long in_FS_OFFSET;
  bool bVar5;
  char *local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = ext2fs_dirent_name_len(param_2);
  iVar3 = ext2fs_check_encoded_name
                    (*(undefined8 *)(*param_1 + 0x168),param_2 + 8,(long)iVar2,&local_38);
  if (iVar3 < 0) {
    uVar4 = dcgettext(0,"NLS is broken.",5);
                    /* WARNING: Subroutine does not return */
    fatal_error(param_1,uVar4);
  }
  if ((iVar3 == 0) || (iVar3 = fix_problem(param_1,0x20053,param_3), iVar3 == 0)) {
    iVar2 = FUN_00128330(param_1,param_2,param_3);
    bVar5 = iVar2 != 0;
  }
  else {
    cVar1 = *local_38;
    for (; (cVar1 != '\0' && ((char *)(param_2 + 8 + (long)iVar2) != local_38));
        local_38 = local_38 + 1) {
      *local_38 = '.';
      cVar1 = local_38[1];
    }
    bVar5 = true;
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: insert_dirent_tail @ 0x28b30

undefined8 insert_dirent_tail(long param_1,int *param_2)

{
  int *piVar1;
  ushort uVar2;
  int *piVar3;
  undefined1 uVar4;
  uint uVar5;
  long lVar6;
  int *piVar7;
  
  piVar1 = (int *)((long)param_2 + ((ulong)*(uint *)(param_1 + 0x28) - 0xc));
  piVar3 = param_2;
  do {
    piVar7 = piVar3;
    uVar2 = *(ushort *)(piVar7 + 1);
    if ((uVar2 == 0) || ((uVar2 & 3) != 0)) break;
    piVar3 = (int *)((ulong)uVar2 + (long)piVar7);
  } while ((int *)((ulong)uVar2 + (long)piVar7) <= piVar1);
  if (piVar7 != piVar1) {
    uVar4 = ext2fs_dirent_name_len(param_2);
    lVar6 = (long)piVar1 - (long)piVar7;
    uVar5 = FUN_001281f0(uVar4,0);
    if (lVar6 < (long)(ulong)uVar5) {
      return 0x7f2bb795;
    }
    *(short *)(piVar7 + 1) = (short)lVar6;
  }
  if ((*piVar1 != 0) || (piVar1[1] != -0x21fffff4)) {
    ext2fs_initialize_dirent_tail(param_1,piVar1);
  }
  return 0;
}



// Function: clear_htree @ 0x28bc0

void clear_htree(long param_1,undefined4 param_2)

{
  long in_FS_OFFSET;
  undefined1 auStack_b8 [32];
  uint local_98;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  e2fsck_read_inode(param_1,param_2,auStack_b8,"clear_htree");
  local_98 = local_98 & 0xffffefff;
  e2fsck_write_inode(param_1,param_2,auStack_b8,"clear_htree");
  if (*(long *)(param_1 + 0x248) != 0) {
    ext2fs_u32_list_add(*(long *)(param_1 + 0x248),param_2);
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: deallocate_inode_block @ 0x28c60

undefined8 deallocate_inode_block(long param_1,ulong *param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  long in_R9;
  
  if (*param_2 == 0) {
    return 0;
  }
  uVar2 = *param_2 >> ((byte)*(undefined4 *)(param_1 + 0xc0) & 0x3f);
  if (*(ulong *)(in_R9 + 0x10) != uVar2) {
    lVar1 = *(long *)(param_1 + 0x20);
    *(ulong *)(in_R9 + 0x10) = uVar2;
    uVar2 = *param_2;
    if (*(uint *)(lVar1 + 0x14) <= uVar2) {
      uVar3 = ext2fs_blocks_count();
      if (uVar2 < uVar3) {
        ext2fs_block_alloc_stats2(param_1,*param_2,0xffffffff);
        *(long *)(in_R9 + 8) = *(long *)(in_R9 + 8) + 1;
        return 0;
      }
    }
  }
  return 0;
}



// Function: check_dotdot @ 0x29200

undefined8 check_dotdot(long *param_1,int *param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  long in_FS_OFFSET;
  uint local_34;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (*param_2 == 0) {
    ext2fs_get_rec_len(*param_1,param_2,&local_34);
    uVar4 = 0x2000a;
LAB_0012923b:
    uVar1 = *(undefined4 *)(*(long *)(*param_1 + 0x20) + 0x60);
    iVar3 = fix_problem(param_1,uVar4,param_4);
    if (iVar3 != 0) {
      if (local_34 < 0xc) {
        *(undefined2 *)(param_2 + 1) = 0xc;
      }
      *param_2 = 2;
      ext2fs_dirent_set_name_len(param_2,2);
      uVar4 = 0;
      iVar3 = FUN_00129080(uVar1,0);
      ext2fs_dirent_set_file_type(param_2,(int)CONCAT71((int7)((ulong)uVar4 >> 8),iVar3 != 0) * 2);
      *(undefined1 *)((long)param_2 + 10) = 0;
      *(undefined2 *)(param_2 + 2) = 0x2e2e;
      uVar4 = 1;
      goto LAB_00129258;
    }
  }
  else {
    iVar3 = ext2fs_dirent_name_len(param_2);
    if (iVar3 != 2) {
      ext2fs_get_rec_len(*param_1,param_2,&local_34);
      uVar4 = 0x2000c;
      goto LAB_0012923b;
    }
    lVar2 = *param_1;
    if ((short)param_2[2] != 0x2e2e) {
      ext2fs_get_rec_len(lVar2,param_2,&local_34);
      uVar4 = 0x2000c;
      goto LAB_0012923b;
    }
    if (*(char *)((long)param_2 + 10) != '\0') {
      ext2fs_get_rec_len(lVar2,param_2,&local_34);
      uVar4 = 0x20017;
      goto LAB_0012923b;
    }
    ext2fs_get_rec_len(lVar2,param_2,&local_34);
    iVar3 = e2fsck_dir_info_set_dotdot(param_1,param_3,*param_2);
    if (iVar3 != 0) {
      fix_problem(param_1,0x2001c,param_4);
      uVar4 = 0xffffffff;
      goto LAB_00129258;
    }
  }
  uVar4 = 0;
LAB_00129258:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_dot @ 0x29390

int check_dot(long *param_1,int *param_2,int param_3,undefined8 param_4)

{
  uint uVar1;
  int *piVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  long in_FS_OFFSET;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (*param_2 == 0) {
    ext2fs_get_rec_len(*param_1,param_2,&local_44);
    uVar6 = 0x20009;
LAB_001293d9:
    iVar5 = FUN_00129080(*(undefined4 *)(*(long *)(*param_1 + 0x20) + 0x60),uVar6,param_4);
    cVar4 = (iVar5 != 0) * '\x02';
    iVar5 = fix_problem(param_1);
    if (iVar5 != 0) {
      if (local_44 < 0xc) {
        local_44 = 0xc;
        *(undefined2 *)(param_2 + 1) = 0xc;
      }
      *param_2 = param_3;
      iVar7 = 1;
      ext2fs_dirent_set_name_len(param_2,1);
      ext2fs_dirent_set_file_type(param_2,cVar4);
      *(undefined2 *)(param_2 + 2) = 0x2e;
      iVar5 = *param_2;
      goto joined_r0x001294e1;
    }
  }
  else {
    iVar5 = ext2fs_dirent_name_len(param_2);
    if (iVar5 != 1) {
      ext2fs_get_rec_len(*param_1,param_2,&local_44);
      uVar6 = 0x2000b;
      goto LAB_001293d9;
    }
    lVar3 = *param_1;
    if ((char)param_2[2] != '.') {
      ext2fs_get_rec_len(lVar3,param_2,&local_44);
      uVar6 = 0x2000b;
      goto LAB_001293d9;
    }
    if (*(char *)((long)param_2 + 9) != '\0') {
      ext2fs_get_rec_len(lVar3,param_2,&local_44);
      uVar6 = 0x20016;
      goto LAB_001293d9;
    }
    ext2fs_get_rec_len(lVar3,param_2,&local_44);
    cVar4 = '\x02';
  }
  iVar7 = 0;
  iVar5 = *param_2;
joined_r0x001294e1:
  iVar8 = iVar7;
  if ((iVar5 != param_3) && (iVar5 = fix_problem(param_1,0x20001,param_4), iVar5 != 0)) {
    *param_2 = param_3;
    iVar8 = 1;
  }
  if (((0xc < local_44) && (uVar1 = local_44 - 0xc, 0xc < uVar1)) &&
     ((iVar7 != 0 || (iVar5 = fix_problem(param_1,0x20024,param_4), iVar5 != 0)))) {
    *(undefined2 *)(param_2 + 1) = 0xc;
    piVar2 = param_2 + 3;
    iVar5 = strncmp((char *)(param_2 + 5),"..",3);
    if (iVar5 != 0) {
      ext2fs_set_rec_len(*param_1,uVar1,piVar2);
      param_2[3] = 0;
      ext2fs_dirent_set_name_len(piVar2,0);
      ext2fs_dirent_set_file_type(piVar2,cVar4);
    }
    iVar8 = 1;
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: parse_int_node @ 0x29610

void parse_int_node(long param_1,long param_2,long param_3,long param_4,long param_5,int param_6)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 extraout_RDX;
  uint uVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ushort *puVar13;
  uint uVar14;
  
  if (*(long *)(param_2 + 0x10) == 0) {
    lVar9 = (ulong)*(byte *)(param_5 + 0x1d) + 0x18;
    puVar13 = (ushort *)(param_5 + lVar9);
    if (param_6 != 0) {
      iVar4 = e2fsck_dir_will_be_rehashed
                        (*(undefined8 *)(param_3 + 0x78),*(undefined4 *)(param_3 + 0x10));
      if (iVar4 != 0) goto LAB_001297e0;
      iVar4 = fix_problem(*(undefined8 *)(param_3 + 0x78),0x20049,param_3 + 8);
joined_r0x0012989a:
      if (iVar4 != 0) goto LAB_001297e0;
    }
  }
  else {
    puVar13 = (ushort *)(param_5 + 8);
    lVar9 = 8;
    if (param_6 != 0) {
      iVar4 = e2fsck_dir_will_be_rehashed
                        (*(undefined8 *)(param_3 + 0x78),*(undefined4 *)(param_3 + 0x10));
      if (iVar4 != 0) goto LAB_001297e0;
      iVar4 = fix_problem(*(undefined8 *)(param_3 + 0x78),0x2004a,param_3 + 8);
      goto joined_r0x0012989a;
    }
  }
  uVar1 = puVar13[1];
  iVar4 = FUN_00129600(*(undefined4 *)(*(long *)(param_1 + 0x20) + 100));
  uVar7 = (uint)((ulong)*(uint *)(param_1 + 0x28) -
                 (lVar9 + CONCAT71((int7)((ulong)extraout_RDX >> 8),iVar4 != 0) * 8) >> 3);
  if (*puVar13 != uVar7) {
    *(ulong *)(param_3 + 0x58) = (ulong)*puVar13;
    iVar4 = fix_problem(*(undefined8 *)(param_3 + 0x78),0x2003d,param_3 + 8);
    if (iVar4 != 0) goto LAB_001297e0;
  }
  uVar14 = (uint)uVar1;
  if ((int)uVar7 < (int)(uint)uVar1) {
    *(ulong *)(param_3 + 0x58) = (ulong)uVar1;
    iVar4 = fix_problem(*(undefined8 *)(param_3 + 0x78),0x2003e,param_3 + 8);
    uVar14 = uVar7;
    if (iVar4 != 0) {
LAB_001297e0:
      FUN_00128bc0(*(undefined8 *)(param_3 + 0x78),*(undefined4 *)(param_3 + 0x10));
      uVar2 = *(undefined4 *)(param_3 + 0x10);
      uVar3 = *(undefined8 *)(param_3 + 0x78);
      *(undefined4 *)(param_4 + 8) = 0;
      e2fsck_rehash_dir_later(uVar3,uVar2);
      return;
    }
  }
  if (0 < (int)uVar14) {
    lVar9 = 0;
    uVar7 = 0;
    uVar12 = 0xffffffff;
    uVar11 = 0;
    uVar10 = 0;
    do {
      uVar8 = *(uint *)(puVar13 + lVar9 * 4 + 2) & 0xfffffff;
      if (uVar8 < *(uint *)(param_4 + 8)) {
        if ((uVar10 < uVar11) &&
           (iVar4 = fix_problem(*(undefined8 *)(param_3 + 0x78),0x2003f), iVar4 != 0))
        goto LAB_001297e0;
        lVar6 = *(long *)(param_4 + 0x10);
        lVar5 = (ulong)uVar8 * 0x30 + lVar6;
        uVar11 = *(uint *)(lVar5 + 4);
        if ((uVar11 & 1) == 0) {
          *(uint *)(lVar5 + 4) = uVar11 | 1;
          *(undefined8 *)(lVar5 + 0x10) = *(undefined8 *)(param_2 + 0x10);
        }
        else {
          *(uint *)(lVar5 + 4) = uVar11 | 2;
        }
        if (lVar9 == 0) {
          *(uint *)(lVar5 + 0x28) = uVar10;
          iVar4 = 1;
          if (uVar10 < uVar12) {
            uVar12 = uVar10;
          }
          *(undefined8 *)(lVar5 + 0x18) = 0;
          if (uVar7 < uVar10) {
            uVar7 = uVar10;
          }
          if ((int)uVar14 < 2) {
            *(undefined4 *)(lVar5 + 0x2c) = 0xfffffffe;
            uVar11 = *(uint *)(lVar5 + 4) | 8;
          }
          else {
            *(uint *)(lVar5 + 0x2c) = *(uint *)(puVar13 + 4) & 0xfffffffe;
            uVar11 = *(uint *)(lVar5 + 4);
          }
          *(uint *)(lVar5 + 4) = uVar11 | 4;
          goto LAB_0012979a;
        }
        uVar11 = *(uint *)(puVar13 + lVar9 * 4 + -2);
        *(uint *)(lVar5 + 0x28) = uVar10;
        if (uVar10 < uVar12) {
          uVar12 = uVar10;
        }
        iVar4 = (int)lVar9 + 1;
        *(ulong *)(lVar5 + 0x18) = (ulong)(uVar11 & 0xfffffff);
        if (uVar7 < uVar10) {
          uVar7 = uVar10;
        }
        if ((int)uVar14 <= iVar4) {
          *(uint *)(lVar5 + 4) = *(uint *)(lVar5 + 4) | 8;
          *(undefined4 *)(lVar5 + 0x2c) = 0xfffffffe;
          goto LAB_00129963;
        }
        *(uint *)(lVar5 + 0x2c) = *(uint *)(puVar13 + lVar9 * 4 + 4) & 0xfffffffe;
      }
      else {
        *(ulong *)(param_3 + 0x30) = (ulong)uVar8;
        iVar4 = fix_problem(*(undefined8 *)(param_3 + 0x78),0x2003a);
        if (iVar4 != 0) goto LAB_001297e0;
        iVar4 = (int)lVar9 + 1;
LAB_0012979a:
        if ((int)uVar14 <= iVar4) goto code_r0x0012979f;
      }
      lVar9 = lVar9 + 1;
      uVar11 = uVar10;
      uVar10 = *(uint *)(puVar13 + (long)iVar4 * 4) & 0xfffffffe;
    } while( true );
  }
  lVar6 = *(long *)(param_4 + 0x10);
  uVar7 = 0;
  uVar12 = 0xffffffff;
LAB_00129963:
  lVar6 = *(long *)(param_2 + 0x10) * 0x30 + lVar6;
  *(uint *)(lVar6 + 0x20) = uVar12;
  *(uint *)(lVar6 + 0x24) = uVar7;
  return;
code_r0x0012979f:
  lVar6 = *(long *)(param_4 + 0x10);
  goto LAB_00129963;
}



// Function: e2fsck_pass2 @ 0x29cb0

void e2fsck_pass2(long *param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  uint uVar9;
  int *piVar10;
  code *pcVar11;
  int iVar12;
  ulong uVar13;
  long in_FS_OFFSET;
  undefined4 local_1a4;
  undefined8 local_1a0;
  undefined1 local_198 [80];
  undefined1 local_148 [16];
  undefined4 local_138;
  ulong local_120;
  ulong local_118;
  ulong local_110;
  undefined4 local_108;
  long local_f8;
  undefined8 local_d8;
  long local_d0 [13];
  undefined4 local_68;
  int local_64;
  long *local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  long local_40;
  
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_1a0 = 0;
  lVar2 = *(long *)(lVar1 + 0x20);
  init_resource_track(local_198,*(undefined8 *)(lVar1 + 8));
  clear_problem_context(local_d0);
  if ((*(byte *)((long)param_1 + 0x4c) & 2) == 0) {
    fix_problem(param_1,0x20000,local_d0);
  }
  local_d0[0] = e2fsck_setup_icount(param_1,"inode_count",1,param_1[0x38],param_1 + 0x37);
  if (local_d0[0] == 0) {
    local_1a0 = e2fsck_allocate_memory(param_1,*(int *)(lVar1 + 0x28) * 2,"directory scan buffer");
    e2fsck_dir_info_set_parent(param_1,2,2);
    local_68 = 1;
    local_d8 = local_1a0;
    local_60 = param_1;
    local_64 = ext2fs_dblist_count2(*(undefined8 *)(lVar1 + 0x90));
    local_58 = 0;
    local_48 = 0;
    local_50 = (ulong)(param_1[0x73] << 10) / (ulong)*(uint *)(*param_1 + 0x28);
    if ((code *)param_1[0x2c] != (code *)0x0) {
      (*(code *)param_1[0x2c])(param_1,2,0,(long)local_64);
    }
    iVar6 = FUN_001299e0(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x5c));
    if (iVar6 != 0) {
      ext2fs_dblist_sort2(*(undefined8 *)(lVar1 + 0x90),FUN_00128260);
    }
    pcVar11 = FUN_0012c070;
    if (local_50 == 0) {
      pcVar11 = FUN_0012a9c0;
    }
    local_d0[0] = ext2fs_dblist_iterate2(*(undefined8 *)(lVar1 + 0x90),pcVar11,&local_d8);
    uVar9 = *(uint *)(param_1 + 9);
    if ((uVar9 & 8) != 0) {
      uVar9 = uVar9 & 0xfffffff7 | 4;
      *(uint *)(param_1 + 9) = uVar9;
    }
    if ((uVar9 & 7) == 0) {
      if (local_d0[0] == 0) {
        local_1a4 = 0;
        while (puVar7 = (undefined4 *)e2fsck_dx_dir_info_iter(param_1,&local_1a4),
              puVar7 != (undefined4 *)0x0) {
          if ((*(byte *)(param_1 + 9) & 3) != 0) goto LAB_0012a005;
          iVar6 = e2fsck_dir_will_be_rehashed(param_1,*puVar7);
          if ((iVar6 == 0) && (puVar7[2] != 0)) {
            clear_problem_context(local_148);
            piVar10 = *(int **)(puVar7 + 4);
            local_138 = *puVar7;
            uVar9 = piVar10[1];
            uVar4 = uVar9 | 1;
            if ((uVar9 & 1) != 0) {
              uVar4 = uVar9 | 2;
            }
            piVar10[1] = uVar4;
            FUN_00128fc0(puVar7[2],piVar10,2);
            iVar6 = puVar7[2];
            FUN_00128fc0(iVar6,piVar10,3);
            if (iVar6 != 0) {
              uVar13 = 0;
              iVar6 = 0;
              do {
                while( true ) {
                  iVar12 = (int)uVar13;
                  local_108 = (undefined4)*(undefined8 *)(piVar10 + 4);
                  local_110 = uVar13;
                  if ((*(byte *)(piVar10 + 1) & 4) == 0) {
                    if ((uint)piVar10[8] < (uint)piVar10[10]) {
                      local_120 = (ulong)(uint)piVar10[8];
                      iVar6 = iVar6 + 1;
                      local_118 = (ulong)(uint)piVar10[10];
                      fix_problem(param_1,0x20036,local_148);
                    }
                  }
                  if (*piVar10 == 2) {
                    sVar5 = FUN_00128220(puVar7,piVar10);
                    if (*(short *)(puVar7 + 1) != sVar5) {
                      iVar6 = iVar6 + 1;
                      local_f8 = (long)*(short *)(puVar7 + 1);
                      fix_problem(param_1,0x20040,local_148);
                    }
                  }
                  if (iVar12 != 0) {
                    if ((uint)piVar10[0xb] < (uint)piVar10[9]) {
                      local_120 = (ulong)(uint)piVar10[9];
                      iVar6 = iVar6 + 1;
                      local_118 = (ulong)(uint)piVar10[0xb];
                      fix_problem(param_1,0x20037,local_148);
                    }
                  }
                  if ((piVar10[1] & 1U) == 0) break;
                  if ((piVar10[1] & 2U) != 0) {
                    iVar6 = iVar6 + 1;
                    fix_problem(param_1,0x20035,local_148);
                  }
                  uVar13 = (ulong)(iVar12 + 1U);
                  piVar10 = piVar10 + 0xc;
                  if ((uint)puVar7[2] <= iVar12 + 1U) goto LAB_0012a087;
                }
                iVar6 = iVar6 + 1;
                uVar13 = (ulong)(iVar12 + 1U);
                piVar10 = piVar10 + 0xc;
                fix_problem(param_1,0x20034,local_148);
              } while (iVar12 + 1U < (uint)puVar7[2]);
LAB_0012a087:
              if ((iVar6 != 0) && (iVar6 = fix_problem(param_1,0x20038,local_148), iVar6 != 0)) {
                FUN_00128bc0(param_1,*puVar7);
                puVar7[2] = 0;
              }
            }
          }
        }
        e2fsck_free_dx_dir_info(param_1);
        ext2fs_free_mem(&local_1a0);
        ext2fs_free_dblist(*(undefined8 *)(lVar1 + 0x90));
        if (param_1[0x2e] != 0) {
          ext2fs_free_inode_bitmap();
          param_1[0x2e] = 0;
        }
        if (param_1[0x32] != 0) {
          ext2fs_free_inode_bitmap();
          param_1[0x32] = 0;
        }
        if (param_1[0x33] != 0) {
          ext2fs_free_inode_bitmap();
          param_1[0x33] = 0;
        }
        destroy_encrypted_file_info(param_1);
        if (param_1[0x6e] != 0) {
          ext2fs_u32_list_free();
          param_1[0x6e] = 0;
        }
        clear_problem_context(local_148);
        if ((int)param_1[100] != 0) {
          iVar6 = FUN_001299d0(*(undefined4 *)(lVar2 + 100));
          if ((iVar6 == 0) && (iVar6 = fix_problem(param_1,0x20033,local_148), iVar6 != 0)) {
            FUN_001281e0(lVar2);
            *(uint *)(lVar1 + 0x10) = *(uint *)(lVar1 + 0x10) & 0xfffffdff;
            ext2fs_mark_super_dirty(lVar1);
          }
          if ((*(int *)(lVar2 + 0x4c) == 0) &&
             (iVar6 = fix_problem(param_1,0x10033,local_148), iVar6 != 0)) {
            ext2fs_update_dynamic_rev(lVar1);
            ext2fs_mark_super_dirty(lVar1);
          }
        }
        uVar3 = *(undefined8 *)(lVar1 + 8);
        uVar8 = dcgettext(0,"Pass 2",5);
        print_resource_track(param_1,uVar8,local_198,uVar3);
      }
      else {
        fix_problem(param_1,0x2001f,local_d0);
        *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
      }
    }
  }
  else {
    fix_problem(param_1,0x2001e,local_d0);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  }
LAB_0012a005:
  ext2fs_free_mem(&local_1a0);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: e2fsck_process_bad_inode @ 0x2a2f0

bool e2fsck_process_bad_inode
               (long *param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ushort uVar7;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  undefined8 uVar8;
  long in_FS_OFFSET;
  bool bVar9;
  int local_14c;
  undefined1 local_138 [8];
  undefined4 local_130;
  undefined4 local_128;
  ushort *local_120;
  ulong local_e8;
  ushort local_c8 [14];
  uint local_ac;
  int local_5c;
  int local_58;
  undefined2 local_54;
  ushort local_52;
  long local_40;
  
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  e2fsck_read_inode(param_1,param_3,local_c8,"process_bad_inode");
  clear_problem_context(local_138);
  local_130 = param_3;
  local_128 = param_2;
  local_120 = local_c8;
  lVar4 = ext2fs_file_acl_block(lVar1,local_c8);
  if ((lVar4 == 0) ||
     (iVar2 = FUN_001299f0(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x5c)), iVar2 != 0)) {
    local_14c = 0;
    iVar2 = 0;
  }
  else {
    iVar2 = fix_problem(param_1,0x2000e,local_138);
    if (iVar2 == 0) {
      iVar2 = 1;
      local_14c = 0;
    }
    else {
      ext2fs_file_acl_block_set(lVar1,local_c8,0);
      local_14c = 1;
      iVar2 = 0;
    }
  }
  uVar7 = local_c8[0] & 0xf000;
  if ((((local_c8[0] & 0xd000) == 0x8000 || (local_c8[0] & 0x7000) == 0x4000) ||
       (local_c8[0] & 0xb000) == 0x2000) || (uVar7 == 0x1000)) {
    if (uVar7 == 0x2000) {
      iVar3 = e2fsck_pass1_check_device_inode(lVar1,local_c8);
      if (iVar3 == 0) {
        uVar8 = 0x20018;
        goto LAB_0012a6d0;
      }
      uVar7 = local_c8[0] & 0xf000;
    }
    if (uVar7 == 0x6000) {
      iVar3 = e2fsck_pass1_check_device_inode(lVar1,local_c8);
      if (iVar3 == 0) {
        uVar8 = 0x20019;
        goto LAB_0012a6d0;
      }
      uVar7 = local_c8[0] & 0xf000;
    }
    if (uVar7 == 0x1000) {
      iVar3 = e2fsck_pass1_check_device_inode(lVar1,local_c8);
      if (iVar3 == 0) {
        uVar8 = 0x20025;
        goto LAB_0012a6d0;
      }
      uVar7 = local_c8[0] & 0xf000;
    }
    if (uVar7 == 0xc000) {
      iVar3 = e2fsck_pass1_check_device_inode(lVar1,local_c8);
      if (iVar3 == 0) {
        uVar8 = 0x20026;
        goto LAB_0012a6d0;
      }
      uVar7 = local_c8[0] & 0xf000;
    }
    if (uVar7 == 0xa000) {
      iVar3 = e2fsck_pass1_check_symlink(lVar1,param_3,local_c8,param_4);
      uVar8 = 0x20031;
      if (iVar3 == 0) goto LAB_0012a6d0;
    }
  }
  else {
    uVar8 = 0x20012;
LAB_0012a6d0:
    iVar2 = iVar2 + 1;
    iVar3 = fix_problem(param_1,uVar8,local_138);
    if (iVar3 != 0) {
      FUN_00129a00(param_1,param_3);
      bVar9 = (*(byte *)(param_1 + 9) & 3) == 0;
      goto LAB_0012a4e3;
    }
  }
  if (local_58 != 0) {
    iVar3 = fix_problem(param_1,0x2000d,local_138);
    if (iVar3 == 0) {
      iVar2 = iVar2 + 1;
    }
    else {
      local_14c = local_14c + 1;
      local_58 = 0;
    }
  }
  lVar4 = *(long *)(lVar1 + 0x20);
  iVar3 = *(int *)(lVar4 + 0x48);
  if (iVar3 == 1) {
    if ((byte)local_54 != 0) {
      local_e8 = (ulong)(byte)local_54;
      iVar3 = fix_problem(param_1,0x20010,local_138);
      if (iVar3 == 0) {
        iVar2 = iVar2 + 1;
      }
      else {
        local_14c = local_14c + 1;
        local_54 = local_54 & 0xff00;
      }
      local_e8 = 0;
    }
    if (local_54._1_1_ != 0) {
      local_e8 = (ulong)local_54._1_1_;
      iVar3 = fix_problem(param_1,0x20011,local_138);
      if (iVar3 == 0) {
        iVar2 = iVar2 + 1;
      }
      else {
        local_14c = local_14c + 1;
        local_54 = local_54 & 0xff;
      }
      local_e8 = 0;
    }
    lVar4 = *(long *)(lVar1 + 0x20);
    iVar3 = *(int *)(lVar4 + 0x48);
  }
  if (iVar3 == 0) {
    iVar3 = FUN_001299c0(*(undefined4 *)(lVar4 + 100));
    lVar4 = extraout_RDX;
    if ((iVar3 == 0) && (local_54 != 0)) {
      local_e8 = (ulong)local_54;
      iVar3 = fix_problem(param_1,0x20044,local_138);
      if (iVar3 != 0) {
        local_14c = local_14c + 1;
        local_54 = 0;
      }
      lVar4 = *(long *)(lVar1 + 0x20);
      if (*(int *)(lVar4 + 0x48) != 0) goto LAB_0012a480;
    }
    iVar3 = FUN_00129070(*(undefined4 *)(lVar4 + 0x60));
    if ((iVar3 == 0) && (local_52 != 0)) {
      local_e8 = (ulong)local_52;
      iVar3 = fix_problem(param_1,0x20048,local_138);
      if (iVar3 == 0) {
        iVar2 = iVar2 + 1;
      }
      else {
        local_14c = local_14c + 1;
        local_52 = 0;
      }
    }
  }
LAB_0012a480:
  lVar4 = ext2fs_file_acl_block(lVar1,local_c8);
  if (lVar4 == 0) {
LAB_0012a494:
    if (((local_5c != 0) &&
        (iVar3 = FUN_00129040(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x60)), iVar3 == 0)) &&
       ((local_ac >> (0x13U - (char)*(undefined4 *)(extraout_RDX_00 + 0x18) & 0x3f) == 0 &&
        ((local_c8[0] & 0xf000) == 0x4000)))) goto LAB_0012a988;
    if (local_14c != 0) goto LAB_0012a620;
LAB_0012a4ab:
    if ((iVar2 == 0) && (param_1[0x2e] != 0)) {
      ext2fs_unmark_inode_bitmap2(param_1[0x2e],param_3);
      bVar9 = false;
      goto LAB_0012a4e3;
    }
  }
  else {
    uVar5 = ext2fs_file_acl_block(lVar1,local_c8);
    if (*(uint *)(*(long *)(lVar1 + 0x20) + 0x14) <= uVar5) {
      uVar5 = ext2fs_file_acl_block(lVar1,local_c8);
      uVar6 = ext2fs_blocks_count(*(undefined8 *)(lVar1 + 0x20));
      if (uVar5 < uVar6) goto LAB_0012a494;
    }
    iVar3 = fix_problem(param_1,0x20032,local_138);
    if (iVar3 == 0) {
      iVar2 = iVar2 + 1;
      goto LAB_0012a494;
    }
    ext2fs_file_acl_block_set(lVar1,local_c8,0);
    if ((((local_5c == 0) ||
         (iVar3 = FUN_00129040(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x60)), iVar3 != 0)) ||
        (local_14c = local_14c + 1,
        local_ac >> (0x13U - (char)*(undefined4 *)(extraout_RDX_01 + 0x18) & 0x3f) != 0)) ||
       ((local_c8[0] & 0xf000) != 0x4000)) goto LAB_0012a620;
LAB_0012a988:
    iVar3 = fix_problem(param_1,0x2000f,local_138);
    if (iVar3 != 0) {
      local_5c = 0;
LAB_0012a620:
      e2fsck_write_inode(param_1,param_3,local_c8,"process_bad_inode");
      goto LAB_0012a4ab;
    }
    iVar2 = iVar2 + 1;
    if (local_14c != 0) goto LAB_0012a620;
  }
  bVar9 = false;
LAB_0012a4e3:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar9;
}



// Function: check_dir_block @ 0x2a9c0

undefined4 check_dir_block(long param_1,uint *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  long *plVar5;
  uint *__s;
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  undefined1 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined8 uVar20;
  long lVar21;
  char cVar22;
  ushort extraout_DX;
  ushort uVar23;
  long extraout_RDX;
  uint *puVar24;
  uint *puVar25;
  ulong uVar26;
  ulong uVar27;
  long in_FS_OFFSET;
  bool bVar28;
  byte bVar29;
  int local_380;
  ulong local_378;
  undefined4 local_370;
  uint local_36c;
  undefined8 local_368;
  int local_358;
  bool local_351;
  uint *local_350;
  long local_348;
  uint *local_338;
  int local_330;
  uint *local_320;
  uint local_314;
  ushort local_300;
  undefined4 local_2fc;
  uint local_2f0;
  uint local_2ec;
  ushort local_2e6;
  uint local_2e4;
  uint local_2e0;
  uint local_2dc;
  ulong local_2d8;
  int local_2d0;
  undefined4 uStack_2cc;
  undefined1 local_2c8 [8];
  uint local_2c0;
  uint local_2b8;
  uint *local_2a8;
  ulong local_278;
  uint local_258;
  undefined2 local_254;
  ushort local_252;
  undefined1 local_250;
  uint local_148;
  undefined2 local_144;
  ushort local_142;
  undefined2 local_140;
  long local_40;
  
  bVar29 = 0;
  plVar5 = (long *)param_3[0xf];
  uVar4 = *param_2;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_368 = *(undefined8 *)(param_2 + 2);
  local_2e0 = 0;
  local_2d8 = 0;
  __s = (uint *)*param_3;
  local_36c = ext2fs_test_inode_bitmap2(plVar5[0x33],uVar4);
  if ((local_36c == 0) || (local_36c = 1, (*(byte *)(*(long *)(*plVar5 + 0x20) + 0x27e) & 1) != 0))
  {
    uVar11 = *(uint *)(plVar5 + 9);
  }
  else {
    local_36c = *(uint *)((long)plVar5 + 0x4c) >> 0x14 & 1;
    uVar11 = *(uint *)(plVar5 + 9);
  }
  if ((uVar11 & 7) != 0) {
LAB_0012b328:
    local_370 = 2;
    goto LAB_0012b330;
  }
  pcVar6 = (code *)plVar5[0x2c];
  if (pcVar6 != (code *)0x0) {
    iVar10 = *(int *)(param_3 + 0xe);
    *(int *)(param_3 + 0xe) = iVar10 + 1;
    iVar10 = (*pcVar6)(plVar5,2,(long)iVar10,(long)*(int *)((long)param_3 + 0x74));
    if (iVar10 != 0) goto LAB_0012b328;
  }
  iVar10 = FUN_00129600(*(undefined4 *)(*(long *)(param_1 + 0x20) + 100));
  if (iVar10 == 0) {
    local_378._0_4_ = 0;
    local_380 = 0;
  }
  else {
    local_378._0_4_ = 0xc;
    local_380 = 8;
  }
  uVar18 = *(undefined4 *)(extraout_RDX + 0x60);
  iVar10 = ext2fs_test_inode_bitmap2(plVar5[0x2d]);
  local_370 = 0;
  if (iVar10 == 0) goto LAB_0012b330;
  *(uint *)(param_3 + 2) = uVar4;
  param_3[6] = local_368;
  uVar20 = *(undefined8 *)(param_2 + 4);
  *(undefined4 *)((long)param_3 + 0x14) = 0;
  param_3[8] = uVar20;
  lVar21 = *(long *)(param_1 + 0x20);
  param_3[5] = 0;
  param_3[0xb] = 0;
  iVar10 = FUN_00129030(*(undefined4 *)(lVar21 + 0x60));
  if (((iVar10 != 0) && (lVar21 = ext2fs_inline_data_size(param_1,uVar4,&local_2d8), lVar21 != 0))
     && (lVar21 != 0x7f2bb7a5)) goto LAB_0012b328;
  if (*(long *)(param_2 + 2) == 0) {
    iVar10 = FUN_00129040(*(undefined4 *)(*(long *)(param_1 + 0x20) + 0x60));
    if ((iVar10 != 0) && (iVar10 = FUN_00129030(), iVar10 == 0)) goto LAB_0012b330;
    if (local_2d8 == 0) {
      iVar10 = FUN_00128cf0(plVar5,param_2,param_3 + 1);
      if (iVar10 != 0) goto LAB_0012b330;
      local_368 = *(undefined8 *)(param_2 + 2);
    }
  }
  bVar28 = false;
  local_358 = (uint)(*(long *)(param_2 + 4) != 0) * 2;
  if (plVar5[0x49] != 0) {
    iVar10 = ext2fs_u32_list_test();
    bVar28 = iVar10 != 0;
  }
  if (DAT_001b7330 == 0) {
    DAT_001b7330 = dcgettext(0,"reading directory block",5);
  }
  ehandler_operation(DAT_001b7330);
  if (local_2d8 == 0) {
    uVar20 = ext2fs_read_dir_block4(param_1,local_368,__s,0,uVar4);
  }
  else {
    memset(__s,0,*(uint *)(param_1 + 0x28) - local_2d8);
    uVar20 = ext2fs_inline_data_get(param_1,uVar4,0,__s,0);
  }
  param_3[1] = uVar20;
  local_278 = local_2d8;
  local_2c0 = uVar4;
  if (((local_2d8 & 3) != 0) ||
     ((0x3c < local_2d8 &&
      (uVar27 = local_2d8, uVar11 = FUN_001281f0(1,0), uVar27 < (ulong)uVar11 + 0x3c)))) {
    iVar10 = fix_problem(plVar5,0x2004e,local_2c8);
    if ((iVar10 != 0) && (lVar21 = FUN_00128610(plVar5,uVar4,&local_2d8,local_2c8,__s), lVar21 != 0)
       ) goto LAB_0012b328;
  }
  ehandler_operation(0);
  lVar21 = param_3[1];
  local_350 = __s;
  if (lVar21 == 0x7f2bb723) {
    local_314 = 0;
LAB_0012b3d8:
    param_3[1] = 0;
    local_348 = e2fsck_get_dx_dir_info(plVar5,uVar4);
    if ((local_348 == 0) || (uVar11 = *(uint *)(local_348 + 8), uVar11 == 0)) {
      local_320 = (uint *)0x0;
LAB_0012b571:
      if ((local_2d8 == 0) && (local_314 != 0)) {
        iVar10 = ext2fs_dirent_has_tail(param_1,__s);
        if (iVar10 == 0) {
          iVar10 = e2fsck_dir_will_be_rehashed(plVar5,uVar4);
          if (iVar10 == 0) {
            local_378._0_4_ = fix_problem(param_3[0xf],0x2004c,param_3 + 1);
            if ((int)local_378 == 0) goto LAB_0012b5a0;
            e2fsck_rehash_dir_later(plVar5,uVar4);
          }
          local_378._0_4_ = 0;
          local_2f0 = 1;
          local_314 = 0;
        }
        else {
LAB_0012b5a0:
          local_314 = 1;
          local_2f0 = 1;
        }
      }
      else {
        local_2f0 = 1;
      }
      goto LAB_0012ad0b;
    }
LAB_0012b409:
    if ((long)(ulong)uVar11 <= *(long *)(param_2 + 4)) {
      local_2b8 = uVar4;
      iVar10 = fix_problem(plVar5,0x20045,local_2c8);
      if (iVar10 == 0) {
        uVar20 = dcgettext(0,"Can not continue.",5);
                    /* WARNING: Subroutine does not return */
        fatal_error(plVar5,uVar20);
      }
      FUN_00128bc0(plVar5,uVar4);
      local_320 = (uint *)0x0;
      *(undefined4 *)(local_348 + 8) = 0;
      goto LAB_0012b571;
    }
    local_320 = (uint *)(*(long *)(param_2 + 4) * 0x30 + *(long *)(local_348 + 0x10));
    *local_320 = 2;
    *(undefined8 *)(local_320 + 2) = local_368;
    local_320[8] = 0xffffffff;
    local_320[9] = 0;
    ext2fs_get_rec_len(param_1,__s,&local_2dc);
    if (*(long *)(param_2 + 4) == 0) {
      local_320[1] = local_320[1] | 0xc;
      *local_320 = 1;
      if ((__s[6] == 0) && (7 < *(byte *)((long)__s + 0x1d))) {
        uVar13 = (uint)*(byte *)((long)__s + 0x1e);
        uVar11 = FUN_00129050(*(undefined8 *)(param_1 + 0x20));
        uVar23 = extraout_DX;
        if (uVar11 <= uVar13) goto LAB_0012ba00;
      }
      else {
LAB_0012ba00:
        iVar10 = fix_problem(plVar5,0x2003c,param_3 + 1);
        if (iVar10 != 0) {
          FUN_00128bc0(plVar5,uVar4);
          *(undefined4 *)(local_348 + 8) = 0;
          bVar2 = (byte)__s[7];
          *(byte *)(local_348 + 6) = bVar2;
          if (bVar2 < 3) {
            bVar3 = *(byte *)((long)__s + 0x1e);
            if ((*(byte *)(*(long *)(param_1 + 0x20) + 0x160) & 2) != 0) {
              local_2f0 = 0;
              local_378._0_4_ = 0;
              *(byte *)(local_348 + 6) = bVar2 + 3;
              *(ushort *)(local_348 + 4) = bVar3 + 1;
              local_320 = (uint *)0x0;
              goto LAB_0012ad0b;
            }
          }
          else {
            bVar3 = *(byte *)((long)__s + 0x1e);
          }
          local_2f0 = 0;
          local_378._0_4_ = 0;
          *(ushort *)(local_348 + 4) = bVar3 + 1;
          local_320 = (uint *)0x0;
          goto LAB_0012ad0b;
        }
        uVar23 = (ushort)*(byte *)((long)__s + 0x1e);
      }
      bVar2 = (byte)__s[7];
      *(byte *)(local_348 + 6) = bVar2;
      if ((bVar2 < 3) && ((*(byte *)(*(long *)(param_1 + 0x20) + 0x160) & 2) != 0)) {
        *(byte *)(local_348 + 6) = bVar2 + 3;
        *(ushort *)(local_348 + 4) = (uVar23 & 0xff) + 1;
      }
      else {
        *(ushort *)(local_348 + 4) = (uVar23 & 0xff) + 1;
      }
LAB_0012b530:
      if (*local_320 != 2) {
        local_2f0 = 0;
        local_378._0_4_ = 0;
        goto LAB_0012ad0b;
      }
      goto LAB_0012b571;
    }
    if ((((*__s != 0) || (uVar11 = *(uint *)(param_1 + 0x28), uVar11 != local_2dc)) ||
        (iVar10 = ext2fs_dirent_name_len(__s), iVar10 != 0)) ||
       ((uint)(ushort)__s[2] != (uVar11 - 8) - local_380 >> 3)) goto LAB_0012b530;
    *local_320 = 3;
    local_2f0 = 0;
    if (local_2d8 != 0) goto LAB_0012b7a4;
    local_378._0_4_ = 0;
    local_2f0 = 0;
LAB_0012ad18:
    local_378 = (ulong)(uVar11 - (int)local_378);
  }
  else {
    if (lVar21 == 0x7f2bb796) {
      local_314 = 1;
      goto LAB_0012b3d8;
    }
    if (lVar21 != 0) {
      iVar10 = fix_problem(plVar5,0x20020,param_3 + 1);
      if (iVar10 == 0) {
        *(uint *)(plVar5 + 9) = *(uint *)(plVar5 + 9) | 1;
        goto LAB_0012b328;
      }
      uVar11 = 0;
      if (*(long *)(param_2 + 4) == 0) {
        uVar11 = uVar4;
      }
      ext2fs_new_dir_block(param_1,uVar11,2,&local_2d0);
      memcpy(__s,(void *)CONCAT44(uStack_2cc,local_2d0),(ulong)*(uint *)(param_1 + 0x28));
      ext2fs_free_mem(&local_2d0);
    }
    local_348 = e2fsck_get_dx_dir_info(plVar5,uVar4);
    if (local_348 != 0) {
      uVar11 = *(uint *)(local_348 + 8);
      if (uVar11 == 0) {
        local_314 = 0;
        local_2f0 = 1;
        local_320 = (uint *)0x0;
        goto LAB_0012ad0b;
      }
      local_314 = 0;
      goto LAB_0012b409;
    }
    local_314 = 0;
    local_320 = (uint *)0x0;
    local_2f0 = 1;
LAB_0012ad0b:
    if (local_2d8 == 0) {
      uVar11 = *(uint *)(param_1 + 0x28);
      goto LAB_0012ad18;
    }
    if (*(long *)(param_2 + 4) == 0) {
      local_378 = 0x3c;
    }
    else {
LAB_0012b7a4:
      local_378 = local_2d8 - 0x3c;
      if (local_378 == 0) goto LAB_0012b330;
      local_350 = __s + 0xf;
    }
  }
  iVar10 = find_encryption_policy(plVar5,uVar4);
  if (local_36c == 0) {
    dict_init(&DAT_001b72c0,0xffffffffffffffff,FUN_001283c0);
    lVar21 = plVar5[0x6e];
    if (lVar21 == 0) goto LAB_0012b87a;
LAB_0012ad8e:
    iVar12 = ext2fs_u32_list_test(lVar21,uVar4);
    local_351 = iVar12 != 0 && iVar10 != -1;
  }
  else {
    dict_init(&DAT_001b72c0,0xffffffffffffffff,FUN_00128410);
    dict_set_cmp_context(&DAT_001b72c0,*(undefined8 *)(*plVar5 + 0x168));
    lVar21 = plVar5[0x6e];
    if (lVar21 != 0) goto LAB_0012ad8e;
LAB_0012b87a:
    local_351 = false;
  }
  iVar12 = FUN_00129080(uVar18);
  local_330 = 0;
  uVar27 = 0;
  local_2fc = 0;
  local_300 = (ushort)(iVar12 != 0) << 9;
  local_338 = (uint *)0x0;
  do {
    bVar8 = 1 < local_358;
    uVar26 = uVar27;
    cVar22 = bVar8;
    uVar11 = FUN_001281f0(1,local_351 & bVar8);
    if ((local_2d8 == 0) || (cVar22 != '\0')) {
      puVar24 = (uint *)((long)local_350 + uVar26);
      if (local_378 - uVar26 < 8) {
        bVar7 = false;
        local_2dc = uVar11;
      }
      else {
        ext2fs_get_rec_len(param_1,puVar24,&local_2dc);
        bVar7 = local_2dc < uVar11;
      }
      uVar11 = local_2dc;
      param_3[5] = puVar24;
      param_3[0xb] = uVar26;
      if (((local_2dc + (int)uVar27 <= local_378) && (!bVar7)) && ((local_2dc & 3) == 0)) {
        uVar9 = ext2fs_dirent_name_len(puVar24);
        uVar13 = FUN_001281f0(uVar9,local_351 & bVar8);
        if (uVar13 <= uVar11) goto LAB_0012aebb;
      }
      iVar12 = fix_problem(plVar5,0x20013,param_3 + 1);
      if (iVar12 == 0) goto LAB_0012b705;
      FUN_001287e0(param_1,puVar24,local_338,&local_2e0,local_378 & 0xffffffff,local_351);
      uVar27 = (ulong)local_2e0;
      local_330 = local_330 + 1;
    }
    else {
      if (local_358 == 0) {
        puVar24 = &local_258;
        puVar25 = puVar24;
        for (lVar21 = 0x21; lVar21 != 0; lVar21 = lVar21 + -1) {
          puVar25[0] = 0;
          puVar25[1] = 0;
          puVar25 = puVar25 + (ulong)bVar29 * -4 + 2;
        }
        local_258 = uVar4;
        local_254 = FUN_001281f0(1,0);
        local_250 = 0x2e;
        local_252 = local_300 | 1;
      }
      else {
        puVar24 = &local_148;
        for (lVar21 = 0x21; lVar21 != 0; lVar21 = lVar21 + -1) {
          puVar24[0] = 0;
          puVar24[1] = 0;
          puVar24 = puVar24 + (ulong)bVar29 * -4 + 2;
        }
        local_148 = *local_350;
        local_144 = FUN_001281f0(2,0);
        local_140 = 0x2e2e;
        local_142 = local_300 | 2;
        puVar24 = &local_148;
      }
      param_3[5] = puVar24;
      param_3[0xb] = uVar26;
LAB_0012aebb:
      if (local_358 == 0) {
        iVar12 = FUN_00129390(plVar5,puVar24,uVar4,param_3 + 1);
        if (iVar12 == 0) {
          iVar12 = 0;
          uVar11 = *puVar24;
          goto LAB_0012aeea;
        }
        uVar11 = *puVar24;
LAB_0012b923:
        local_330 = local_330 + 1;
        if (uVar11 != 0) {
          iVar12 = 0;
          goto LAB_0012aef3;
        }
LAB_0012b89c:
        ext2fs_get_rec_len(param_1,puVar24,&local_2dc);
      }
      else {
        if (local_358 != 1) {
          iVar12 = 0;
          uVar11 = *puVar24;
          if (uVar11 != uVar4) goto LAB_0012aeea;
          iVar12 = fix_problem(plVar5,0x20004,param_3 + 1);
          if (iVar12 == 0) {
            iVar12 = 0x20004;
            uVar11 = *puVar24;
            goto LAB_0012aeea;
          }
LAB_0012b890:
          local_330 = local_330 + 1;
          *puVar24 = 0;
          goto LAB_0012b89c;
        }
        iVar12 = FUN_00129200(plVar5,puVar24,uVar4,param_3 + 1);
        if (iVar12 < 0) goto LAB_0012b705;
        uVar11 = *puVar24;
        if (iVar12 != 0) goto LAB_0012b923;
        iVar12 = 0;
LAB_0012aeea:
        if (uVar11 != 0) {
LAB_0012aef3:
          iVar14 = ext2fs_dirent_name_len(puVar24);
          puVar25 = *(uint **)(param_1 + 0x20);
          if (uVar11 == 2) {
LAB_0012af27:
            if (((uVar11 <= *puVar25) && (puVar25[0x90] != uVar11)) &&
               ((puVar25[0x91] != uVar11 && (puVar25[0x9b] != uVar11)))) {
              if ((plVar5[0x30] == 0) ||
                 (iVar15 = ext2fs_test_inode_bitmap2(plVar5[0x30],uVar11), iVar15 == 0)) {
                if ((iVar14 == 1) && (bVar8)) {
                  if ((char)puVar24[2] == '.') {
                    iVar14 = 0x2001a;
                  }
                  else {
LAB_0012bdf9:
                    if (*puVar24 != 2) goto LAB_0012bf2a;
LAB_0012be03:
                    iVar14 = 0x20007;
                  }
                  goto LAB_0012af7f;
                }
                if ((iVar14 == 2) && (bVar8)) {
                  if ((short)puVar24[2] != 0x2e2e) goto LAB_0012bdf9;
                  iVar14 = 0x2001b;
                  goto LAB_0012af7f;
                }
                if (1 < local_358) {
                  if (*puVar24 == 2) goto LAB_0012be03;
                  if (iVar14 == 0) {
                    iVar14 = 0x20030;
                    goto LAB_0012af7f;
                  }
                }
LAB_0012bf2a:
                iVar14 = 0;
                if (iVar12 != 0) {
                  iVar14 = 0x20004;
                  goto LAB_0012af7f;
                }
              }
              else {
                iVar14 = 0x20005;
LAB_0012af7f:
                iVar12 = fix_problem(plVar5,iVar14,param_3 + 1);
                if (iVar12 != 0) goto LAB_0012b890;
                ext2fs_unmark_valid(param_1);
              }
              if ((plVar5[0x2e] != 0) &&
                 (iVar12 = ext2fs_test_inode_bitmap2(plVar5[0x2e],*puVar24), iVar12 != 0)) {
                iVar12 = e2fsck_process_bad_inode
                                   (plVar5,uVar4,*puVar24,
                                    (ulong)*(uint *)(param_1 + 0x28) + (long)local_350);
                if (iVar12 != 0) goto LAB_0012b890;
                if ((*(byte *)(plVar5 + 9) & 3) != 0) goto LAB_0012b328;
              }
              iVar15 = ext2fs_group_of_ino(param_1,*puVar24);
              iVar12 = *(int *)(*(long *)(param_1 + 0x20) + 0x28);
              iVar16 = ext2fs_bg_itable_unused(param_1,iVar15);
              *(int *)(param_3 + 9) = iVar15;
              puVar1 = param_3 + 1;
              iVar17 = ext2fs_bg_flags_test(param_1,iVar15,1);
              if (iVar17 == 0) {
                if (*puVar24 < ((iVar15 + 1) * iVar12 - iVar16) + 1U) goto LAB_0012b022;
                local_278 = (ulong)*puVar24;
                iVar12 = fix_problem(plVar5,0x20047,puVar1);
                if (iVar12 == 0) goto LAB_0012bbd8;
                ext2fs_bg_itable_unused_set(param_1,iVar15,0);
LAB_0012ba68:
                ext2fs_group_desc_csum_set(param_1,iVar15);
                ext2fs_mark_super_dirty(param_1);
                *(uint *)(plVar5 + 9) = *(uint *)(plVar5 + 9) | 8;
LAB_0012ba7f:
                if (iVar14 != 0) goto LAB_0012b04f;
              }
              else {
                local_278 = (ulong)*puVar24;
                iVar12 = fix_problem(plVar5,0x20046,puVar1);
                if (iVar12 != 0) {
                  ext2fs_bg_flags_clear(param_1,iVar15,1);
                  goto LAB_0012ba68;
                }
LAB_0012bbd8:
                ext2fs_unmark_valid(param_1);
LAB_0012b022:
                if (((*(uint *)(plVar5 + 9) & 8) != 0) ||
                   (iVar12 = ext2fs_test_inode_bitmap2(plVar5[0x2d],*puVar24), iVar12 != 0))
                goto LAB_0012ba7f;
                iVar14 = 0x20003;
LAB_0012b04f:
                iVar12 = fix_problem(plVar5,iVar14,puVar1);
                if (iVar12 != 0) goto LAB_0012b890;
                ext2fs_unmark_valid(param_1);
              }
              iVar12 = FUN_00129090(plVar5,puVar24,puVar1);
              local_330 = (local_330 + 1) - (uint)(iVar12 == 0);
              if (iVar10 == -1) {
                if (local_36c == 0) {
                  iVar12 = FUN_00128330(plVar5,puVar24,puVar1);
                  local_330 = (local_330 + 1) - (uint)(iVar12 == 0);
                }
                else {
                  iVar12 = FUN_00128a10();
                  local_330 = (local_330 + 1) - (uint)(iVar12 == 0);
                }
                if (local_320 != (uint *)0x0) {
LAB_0012b0a6:
                  cVar22 = *(char *)(local_348 + 6);
                  uVar18 = 0x40000000;
                  if ((*(byte *)(local_348 + 7) & 1) == 0) {
                    uVar18 = local_2fc;
                  }
                  if (cVar22 == '\x06') {
                    if (1 < local_358) {
                      iVar12 = ext2fs_dirent_name_len(puVar24);
                      local_2e4 = *(uint *)((long)puVar24 +
                                           (long)(int)(iVar12 + 3U & 0xfffffffc) + 8);
                    }
                  }
                  else {
                    uVar19 = ext2fs_dirent_name_len(puVar24);
                    ext2fs_dirhash2(cVar22,puVar24 + 2,uVar19,*(undefined8 *)(param_1 + 0x168),
                                    uVar18,*(long *)(param_1 + 0x20) + 0xec,&local_2e4,0);
                  }
                  if (local_2e4 < local_320[8]) {
                    local_320[8] = local_2e4;
                  }
                  local_2fc = uVar18;
                  if (local_320[9] < local_2e4) {
                    local_320[9] = local_2e4;
                  }
                }
                if (1 < local_358) {
LAB_0012bc10:
                  iVar12 = ext2fs_test_inode_bitmap2(plVar5[0x2f],*puVar24);
                  if (iVar12 != 0) {
                    iVar12 = e2fsck_dir_info_get_parent(plVar5,*puVar24,&local_2d0);
                    if (iVar12 != 0) {
                      *(uint *)(param_3 + 2) = *puVar24;
                      fix_problem(plVar5,0x2001c,puVar1);
                      goto LAB_0012b705;
                    }
                    if (local_2d0 == 0) {
                      e2fsck_dir_info_set_parent(plVar5,*puVar24,uVar4);
                    }
                    else {
                      *(int *)((long)param_3 + 0x14) = local_2d0;
                      iVar12 = fix_problem(plVar5,0x20006,puVar1);
                      if (iVar12 != 0) goto LAB_0012b890;
                      *(undefined4 *)((long)param_3 + 0x14) = 0;
                    }
                  }
                }
              }
              else {
                if (1 < local_358) {
                  iVar12 = FUN_001285b0(plVar5,puVar24,iVar10,puVar1);
                  if (iVar12 != 0) goto LAB_0012b890;
                  if (local_320 != (uint *)0x0) goto LAB_0012b0a6;
                  goto LAB_0012bc10;
                }
                if (local_320 != (uint *)0x0) goto LAB_0012b0a6;
              }
              if (!bVar28) {
                lVar21 = dict_lookup(&DAT_001b72c0,puVar24);
                if (lVar21 == 0) {
                  dict_alloc_insert(&DAT_001b72c0,puVar24,puVar24);
                }
                else {
                  clear_problem_context(local_2c8);
                  local_2c0 = uVar4;
                  local_2a8 = puVar24;
                  fix_problem(plVar5,0x20043,local_2c8);
                  e2fsck_rehash_dir_later(plVar5,uVar4);
                  bVar28 = true;
                }
              }
              ext2fs_icount_increment(plVar5[0x37],*puVar24,&local_2e6);
              if (1 < local_2e6) {
                *(int *)(plVar5 + 0x5e) = (int)plVar5[0x5e] + 1;
              }
              *(int *)(plVar5 + 0x60) = (int)plVar5[0x60] + 1;
              goto LAB_0012b15d;
            }
          }
          else {
            uVar13 = 0xb;
            if (puVar25[0x13] != 0) {
              uVar13 = puVar25[0x15];
            }
            if (uVar13 <= uVar11) goto LAB_0012af27;
          }
          iVar12 = fix_problem(plVar5,0x20002,param_3 + 1);
          if (iVar12 != 0) goto LAB_0012b890;
          ext2fs_unmark_valid(param_1);
        }
LAB_0012b15d:
        if (local_330 != 0) goto LAB_0012b89c;
      }
      local_338 = puVar24;
      if ((local_2d8 == 0) || (bVar8)) {
        local_2e0 = local_2dc + local_2e0;
        uVar27 = (ulong)local_2e0;
      }
      else if (local_358 == 1) {
        local_338 = (uint *)0x0;
        uVar27 = 4;
        local_2e0 = 4;
      }
      else {
        uVar27 = (ulong)local_2e0;
      }
      local_358 = local_358 + 1;
    }
  } while (uVar27 < local_378);
  if ((local_320 != (uint *)0x0) &&
     (*(undefined4 *)(param_3 + 3) = *(undefined4 *)(param_3 + 2), (*local_320 & 0xfffffffd) == 1))
  {
    FUN_00129610(param_1,param_2,param_3,local_348,local_350,local_314);
  }
  if (uVar27 == local_378) {
LAB_0012be68:
    if (local_330 != 0) goto LAB_0012b226;
    if (((local_2f0 & local_314) != 0) &&
       (iVar10 = fix_problem(plVar5,0x2004d,param_3 + 1), iVar10 != 0)) goto LAB_0012b244;
  }
  else {
    param_3[0xb] = ((int)uVar27 + local_2dc) - local_378;
    iVar10 = fix_problem(plVar5,0x2001d,param_3 + 1);
    if (iVar10 == 0) goto LAB_0012be68;
    *(short *)(puVar24 + 1) = (short)param_3[0xb];
LAB_0012b226:
    iVar10 = FUN_00129600(*(undefined4 *)(*(long *)(param_1 + 0x20) + 100));
    if ((((iVar10 != 0) && (local_2f0 != 0)) && (local_2d8 == 0)) &&
       ((iVar10 = ext2fs_dirent_has_tail(param_1,local_350), iVar10 == 0 &&
        (lVar21 = FUN_00128b30(param_1,local_350), lVar21 != 0)))) {
      e2fsck_rehash_dir_later(plVar5,uVar4);
    }
LAB_0012b244:
    iVar10 = e2fsck_dir_will_be_rehashed(plVar5,uVar4);
    if (iVar10 != 0) {
      local_2ec = *(uint *)(*plVar5 + 0x10);
      *(uint *)(*plVar5 + 0x10) = local_2ec | 0x200000;
    }
    if (local_2d8 == 0) {
      lVar21 = ext2fs_write_dir_block4(param_1,local_368,local_350,0,uVar4);
    }
    else {
      lVar21 = ext2fs_inline_data_set(param_1,uVar4,0,__s);
    }
    param_3[1] = lVar21;
    if (iVar10 != 0) {
      *(uint *)(*plVar5 + 0x10) = *(uint *)(*plVar5 + 0x10) & 0xffdfffff | local_2ec & 0x200000;
    }
    if ((lVar21 != 0) && (iVar10 = fix_problem(plVar5,0x20021,param_3 + 1), iVar10 == 0)) {
LAB_0012b705:
      *(uint *)(plVar5 + 9) = *(uint *)(plVar5 + 9) | 1;
      dict_free_nodes(&DAT_001b72c0);
      local_370 = 2;
      goto LAB_0012b330;
    }
    ext2fs_mark_changed(param_1);
  }
  dict_free_nodes(&DAT_001b72c0);
LAB_0012b330:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_370;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_dir_block2 @ 0x2c070

void check_dir_block2(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  ulong uVar2;
  
  if ((*(ulong *)(param_3 + 0x88) != 0) &&
     (*(ulong *)(param_3 + 0x90) <= *(ulong *)(param_3 + 0x80))) {
    iVar1 = e2fsck_readahead_dblist
                      (param_1,1,*(undefined8 *)(param_1 + 0x90),
                       (*(ulong *)(param_3 + 0x88) >> 3) + *(ulong *)(param_3 + 0x80));
    if (iVar1 == 0) {
      uVar2 = (ulong)(*(long *)(param_3 + 0x88) * 7) >> 3;
    }
    else {
      *(undefined8 *)(param_3 + 0x88) = 0;
      uVar2 = 0;
    }
    *(ulong *)(param_3 + 0x90) = uVar2 + *(long *)(param_3 + 0x80);
  }
  FUN_0012a9c0(param_1,param_2,param_3);
  *(long *)(param_3 + 0x80) = *(long *)(param_3 + 0x80) + 1;
  return;
}



// Function: fix_dotdot @ 0x2c130

void fix_dotdot(long *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long in_FS_OFFSET;
  long local_c8;
  undefined4 local_c0;
  int local_bc;
  long *local_b8;
  long local_a8;
  undefined4 local_a0;
  long local_40;
  
  lVar2 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_bc = 0;
  local_c8 = lVar2;
  local_c0 = param_3;
  local_b8 = param_1;
  clear_problem_context(&local_a8);
  local_a0 = param_2;
  iVar3 = e2fsck_dir_will_be_rehashed(param_1,param_2);
  if (iVar3 == 0) {
    lVar4 = ext2fs_dir_iterate(lVar2,param_2,1,0,FUN_0012c940,&local_c8);
  }
  else {
    uVar1 = *(uint *)(*param_1 + 0x10);
    *(uint *)(*param_1 + 0x10) = uVar1 | 0x200000;
    lVar4 = ext2fs_dir_iterate(lVar2,param_2,1,0,FUN_0012c940,&local_c8);
    *(uint *)(*param_1 + 0x10) = *(uint *)(*param_1 + 0x10) & 0xffdfffff | uVar1 & 0x200000;
  }
  if (lVar4 == 0) {
    uVar5 = 0x30010;
    if (local_bc != 0) goto LAB_0012c1f2;
  }
  else {
    uVar5 = 0x3000f;
  }
  local_a8 = lVar4;
  fix_problem(param_1,uVar5,&local_a8);
  ext2fs_unmark_valid(lVar2);
LAB_0012c1f2:
  e2fsck_dir_info_set_dotdot(param_1,param_2,param_3);
  iVar3 = e2fsck_dir_info_set_parent(param_1,param_2,(int)param_1[0x45]);
  if (iVar3 != 0) {
    fix_problem(param_1,0x30016,&local_a8);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: expand_dir_proc @ 0x2c2b0

char expand_dir_proc(long param_1,ulong *param_2,long param_3,undefined8 param_4,undefined8 param_5,
                 long *param_6)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  long lVar4;
  ulong uVar5;
  byte bVar6;
  long in_FS_OFFSET;
  ulong local_50;
  undefined8 local_48;
  long local_40;
  
  lVar1 = param_6[5];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_6[1] <= param_3) && (param_6[1] != 0)) {
    cVar3 = '\x02';
    goto LAB_0012c411;
  }
  if (param_3 < 1) {
    uVar5 = *param_2;
    if (uVar5 == 0) {
      bVar6 = (byte)*(undefined4 *)(param_1 + 0xc0);
      if (param_3 != 0) goto LAB_0012c31d;
LAB_0012c336:
      DAT_001b7338 = (long)(-1 << (bVar6 & 0x1f)) & DAT_001b7338;
      lVar4 = ext2fs_new_block2(param_1,DAT_001b7338,*(undefined8 *)(lVar1 + 0x1a0),&local_50);
      if (lVar4 == 0) {
        param_6[2] = param_6[2] + 1;
        ext2fs_block_alloc_stats2(param_1,local_50,1);
        uVar5 = local_50;
        goto LAB_0012c383;
      }
LAB_0012c438:
      param_6[4] = lVar4;
      cVar3 = '\x02';
      goto LAB_0012c411;
    }
  }
  else {
    param_6[3] = param_3;
    uVar5 = *param_2;
    if (uVar5 == 0) {
      bVar6 = (byte)*(undefined4 *)(param_1 + 0xc0);
LAB_0012c31d:
      uVar5 = DAT_001b7338 + 1;
      if (DAT_001b7338 >> (bVar6 & 0x3f) != DAT_001b7338 + 1 >> (bVar6 & 0x3f)) goto LAB_0012c336;
LAB_0012c383:
      local_50 = uVar5;
      DAT_001b7338 = local_50;
      if (param_3 < 1) {
        lVar4 = ext2fs_zero_blocks2(param_1,local_50,1,0,0);
      }
      else {
        lVar4 = ext2fs_new_dir_block(param_1,0,0,&local_48);
        if (lVar4 != 0) goto LAB_0012c438;
        *param_6 = *param_6 + -1;
        lVar4 = ext2fs_write_dir_block4(param_1,local_50,local_48,0,(int)param_6[6]);
        ext2fs_free_mem(&local_48);
      }
      if (lVar4 == 0) {
        uVar2 = *(undefined8 *)(lVar1 + 0x1a0);
        *param_2 = local_50;
        ext2fs_mark_block_bitmap2(uVar2);
        cVar3 = (-(*param_6 == 0) & 2U) + 1;
      }
      else {
        param_6[4] = lVar4;
        cVar3 = '\x02';
      }
      goto LAB_0012c411;
    }
  }
  cVar3 = '\0';
  DAT_001b7338 = uVar5;
LAB_0012c411:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return cVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_root @ 0x2c4c0

void check_root(long *param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long in_FS_OFFSET;
  byte bVar5;
  long local_158;
  undefined8 local_150;
  long local_148 [12];
  char *local_e8;
  undefined2 local_d8 [2];
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined2 local_be;
  undefined4 local_b0;
  undefined2 local_58;
  long local_30;
  
  bVar5 = 0;
  lVar1 = *param_1;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_148);
  iVar2 = ext2fs_test_inode_bitmap2(param_1[0x2d],2);
  if (iVar2 != 0) {
    iVar2 = ext2fs_test_inode_bitmap2(param_1[0x2f],2);
    if (iVar2 == 0) {
      fix_problem(param_1,0x30014,local_148);
      *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
    }
    goto LAB_0012c724;
  }
  iVar2 = fix_problem(param_1,0x30001,local_148);
  if (iVar2 == 0) {
    fix_problem(param_1,0x30015,local_148);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
    goto LAB_0012c724;
  }
  e2fsck_read_bitmaps(param_1);
  lVar3 = param_1[0x6f];
  if (lVar3 == 0) {
    local_148[0] = ext2fs_new_block2(lVar1,0,param_1[0x34],&local_158);
    if (local_148[0] == 0) {
      ext2fs_mark_block_bitmap2(param_1[0x34],local_158);
      goto LAB_0012c54d;
    }
    local_e8 = "ext2fs_new_block";
  }
  else {
    param_1[0x6f] = 0;
    local_158 = lVar3;
LAB_0012c54d:
    ext2fs_mark_block_bitmap2(*(undefined8 *)(lVar1 + 0x58),local_158);
    ext2fs_mark_bb_dirty(lVar1);
    puVar4 = (undefined8 *)local_d8;
    for (lVar3 = 0x14; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
    }
    local_d8[0] = 0x41ed;
    local_d4 = *(undefined4 *)(lVar1 + 0x28);
    local_be = 2;
    local_d0 = (undefined4)param_1[0x69];
    local_cc = local_d0;
    local_c8 = local_d0;
    ext2fs_iblk_set(lVar1,local_d8,1);
    local_b0 = (undefined4)local_158;
    local_58 = 0x20;
    local_148[0] = ext2fs_write_new_inode(lVar1,2,local_d8);
    if (local_148[0] == 0) {
      local_148[0] = ext2fs_new_dir_block(lVar1,2,2,&local_150);
      if (local_148[0] == 0) {
        local_148[0] = ext2fs_write_dir_block4(lVar1,local_158,local_150,0,2);
        ext2fs_free_mem(&local_150);
        if (local_148[0] == 0) {
          e2fsck_add_dir_info(param_1,2,2);
          ext2fs_icount_store(param_1[0x37],2,2);
          ext2fs_icount_store(param_1[0x38],2,2);
          ext2fs_mark_inode_bitmap2(param_1[0x2d],2);
          ext2fs_mark_inode_bitmap2(param_1[0x2f],2);
          ext2fs_mark_inode_bitmap2(*(undefined8 *)(lVar1 + 0x50),2);
          ext2fs_mark_ib_dirty(lVar1);
          quota_data_add(param_1[0x4f],local_d8,2,
                         (long)(0x400 << ((byte)*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x1c) &
                                         0x1f)));
          quota_data_inodes(param_1[0x4f],local_d8,2,1);
          goto LAB_0012c724;
        }
        local_e8 = "ext2fs_write_dir_block4";
      }
      else {
        local_e8 = "ext2fs_new_dir_block";
      }
    }
    else {
      local_e8 = "ext2fs_write_inode";
    }
  }
  fix_problem(param_1,0x30012,local_148);
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
LAB_0012c724:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_adjust_inode_count @ 0x2c830

long e2fsck_adjust_inode_count(undefined8 *param_1,ulong param_2,int param_3)

{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  undefined1 auStack_b8 [26];
  short local_9e;
  long local_30;
  
  uVar1 = *param_1;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((int)param_2 == 0) {
LAB_0012c85d:
    lVar2 = 0;
  }
  else {
    uVar3 = param_2 & 0xffffffff;
    lVar2 = ext2fs_read_inode(uVar1,param_2,auStack_b8);
    if (lVar2 != 0) goto LAB_0012c85f;
    if (param_3 == 1) {
      ext2fs_icount_increment(param_1[0x37],uVar3,0);
      if (local_9e == -1) goto LAB_0012c85d;
      ext2fs_icount_increment(param_1[0x38],uVar3,0);
      local_9e = local_9e + 1;
    }
    else if (param_3 == -1) {
      ext2fs_icount_decrement(param_1[0x37],uVar3,0);
      if (local_9e == 0) goto LAB_0012c85d;
      ext2fs_icount_decrement(param_1[0x38],uVar3,0);
      local_9e = local_9e + -1;
    }
    lVar2 = ext2fs_write_inode(uVar1,param_2 & 0xffffffff,auStack_b8);
  }
LAB_0012c85f:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: fix_dotdot_proc @ 0x2c940

undefined8 fix_dotdot_proc(undefined4 *param_1)

{
  int iVar1;
  long lVar2;
  long in_R8;
  undefined8 uVar3;
  long in_FS_OFFSET;
  long local_88 [13];
  long local_20;
  
  uVar3 = 0;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = ext2fs_dirent_name_len();
  if (iVar1 == 2) {
    iVar1 = strncmp((char *)(param_1 + 2),"..",2);
    if (iVar1 == 0) {
      clear_problem_context(local_88);
      lVar2 = e2fsck_adjust_inode_count(*(undefined8 *)(in_R8 + 0x10),*param_1,0xffffffff);
      if (lVar2 != 0) {
        local_88[0] = lVar2;
        fix_problem(*(undefined8 *)(in_R8 + 0x10),0x3000e,local_88);
      }
      lVar2 = e2fsck_adjust_inode_count(*(undefined8 *)(in_R8 + 0x10),*(undefined4 *)(in_R8 + 8),1);
      if (lVar2 != 0) {
        local_88[0] = lVar2;
        fix_problem(*(undefined8 *)(in_R8 + 0x10),0x3000e,local_88);
      }
      *param_1 = *(undefined4 *)(in_R8 + 8);
      iVar1 = FUN_0012c820(*(undefined4 *)(*(long *)(**(long **)(in_R8 + 0x10) + 0x20) + 0x60));
      if (iVar1 == 0) {
        ext2fs_dirent_set_file_type(param_1,0);
      }
      else {
        ext2fs_dirent_set_file_type(param_1,2);
      }
      *(int *)(in_R8 + 0xc) = *(int *)(in_R8 + 0xc) + 1;
      uVar3 = 3;
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_get_lost_and_found @ 0x2ca70

int e2fsck_get_lost_and_found(long *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  ushort *puVar7;
  int iVar8;
  long in_FS_OFFSET;
  byte bVar9;
  int local_16c;
  long local_168;
  undefined8 local_160;
  long local_158;
  int local_150;
  char *local_f8;
  ushort local_e8 [2];
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined2 local_ce;
  uint local_c8;
  undefined4 local_c0;
  long local_40;
  
  bVar9 = 0;
  iVar8 = (int)param_1[0x45];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (iVar8 != 0) goto LAB_0012caa4;
  lVar6 = *param_1;
  clear_problem_context(&local_158);
  iVar3 = e2fsck_dir_will_be_rehashed(param_1,2);
  if (iVar3 == 0) {
    lVar4 = ext2fs_lookup(lVar6,2,"lost+found",10,0,&local_16c);
    if (lVar4 != 0) goto LAB_0012cb65;
LAB_0012ce44:
    uVar5 = FUN_0012c120(local_e8);
    lVar4 = ext2fs_read_inode_full(lVar6,local_16c,uVar5);
    if (param_2 == 0) {
LAB_0012d000:
      lVar6 = ext2fs_check_directory(lVar6,local_16c);
      if (lVar6 != 0) goto LAB_0012caa4;
LAB_0012d015:
      *(int *)(param_1 + 0x45) = local_16c;
      iVar8 = local_16c;
      goto LAB_0012caa4;
    }
    if (lVar4 != 0) goto LAB_0012caa4;
    if (param_2 == 0) goto LAB_0012d000;
    if ((local_c8 & 0x10000000) == 0) {
      if ((local_c8 & 0x800) == 0) {
        lVar4 = ext2fs_check_directory(lVar6,local_16c);
        if (lVar4 == 0) goto LAB_0012d015;
        local_150 = local_16c;
        iVar3 = fix_problem(param_1,0x30017,&local_158);
      }
      else {
        iVar3 = fix_problem(param_1,0x3001b,&local_158);
      }
    }
    else {
      iVar3 = fix_problem(param_1,0x30018,&local_158);
    }
    if (iVar3 == 0) goto LAB_0012caa4;
    local_158 = ext2fs_unlink(lVar6,2,"lost+found",local_16c,0);
    if (local_158 == 0) {
      e2fsck_dir_info_set_parent(param_1,local_16c,0);
      e2fsck_adjust_inode_count(param_1,local_16c,0xffffffff);
      if ((local_e8[0] & 0xf000) == 0x4000) {
        *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 4;
      }
      goto LAB_0012cb93;
    }
    local_f8 = "ext2fs_unlink";
LAB_0012cf87:
    fix_problem(param_1,0x30013,&local_158);
  }
  else {
    uVar1 = *(uint *)(*param_1 + 0x10);
    *(uint *)(*param_1 + 0x10) = uVar1 | 0x200000;
    lVar4 = ext2fs_lookup(lVar6,2,"lost+found",10,0,&local_16c);
    *(uint *)(*param_1 + 0x10) = uVar1 & 0x200000 | *(uint *)(*param_1 + 0x10) & 0xffdfffff;
    if (lVar4 == 0) goto LAB_0012ce44;
LAB_0012cb65:
    if (param_2 == 0) goto LAB_0012caa4;
    if (lVar4 == 0) goto LAB_0012ce44;
    if (lVar4 != 0x7f2bb74c) {
      local_158 = lVar4;
      fix_problem(param_1,0x30009,&local_158);
    }
LAB_0012cb93:
    iVar3 = fix_problem(param_1,0x30004,0);
    if (iVar3 == 0) goto LAB_0012caa4;
    e2fsck_read_bitmaps(param_1);
    lVar4 = param_1[0x70];
    if (lVar4 == 0) {
      lVar4 = ext2fs_new_block2(lVar6,0,param_1[0x34],&local_168);
      if (lVar4 != 0x7f2bb748) {
        if (lVar4 != 0) goto LAB_0012cfc0;
        ext2fs_mark_block_bitmap2(param_1[0x34],local_168);
        goto LAB_0012cbd2;
      }
      iVar3 = fix_problem(param_1,0x30019,&local_158);
      if (iVar3 == 0) {
LAB_0012cfc0:
        local_158 = lVar4;
        fix_problem(param_1,0x3000a,&local_158);
        goto LAB_0012caa4;
      }
LAB_0012d044:
      fix_problem(param_1,0x3001a,&local_158);
      *(undefined4 *)(param_1 + 0x45) = 2;
      goto LAB_0012caa4;
    }
    param_1[0x70] = 0;
    local_168 = lVar4;
LAB_0012cbd2:
    ext2fs_block_alloc_stats2(lVar6,local_168,1);
    lVar4 = ext2fs_new_inode(lVar6,2,0x41c0,param_1[0x2d],&local_16c);
    if (lVar4 == 0x7f2bb749) {
      iVar3 = fix_problem(param_1,0x30019,&local_158);
      if (iVar3 != 0) goto LAB_0012d044;
    }
    else if (lVar4 == 0) {
      ext2fs_mark_inode_bitmap2(param_1[0x2d],local_16c);
      ext2fs_mark_inode_bitmap2(param_1[0x2f],local_16c);
      ext2fs_inode_alloc_stats2(lVar6,local_16c,1,1);
      puVar7 = local_e8;
      for (lVar4 = 0x14; lVar4 != 0; lVar4 = lVar4 + -1) {
        puVar7[0] = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7 = puVar7 + ((ulong)bVar9 * -2 + 1) * 4;
      }
      local_e8[0] = 0x41c0;
      local_e4 = *(undefined4 *)(lVar6 + 0x28);
      local_ce = 2;
      local_e0 = (undefined4)param_1[0x69];
      local_dc = local_e0;
      local_d8 = local_e0;
      uVar5 = FUN_0012c120(local_e8);
      ext2fs_iblk_set(lVar6,uVar5);
      local_c0 = (undefined4)local_168;
      local_158 = ext2fs_write_new_inode(lVar6,local_16c,uVar5);
      if (local_158 != 0) {
        local_f8 = "ext2fs_write_inode";
        goto LAB_0012cf87;
      }
      lVar4 = ext2fs_new_dir_block(lVar6,local_16c,2,&local_160);
      if (lVar4 != 0) {
        local_158 = lVar4;
        fix_problem(param_1,0x3000c,&local_158);
        goto LAB_0012caa4;
      }
      lVar4 = ext2fs_write_dir_block4(lVar6,local_168,local_160,0,local_16c);
      ext2fs_free_mem(&local_160);
      if (lVar4 != 0) {
        local_158 = lVar4;
        fix_problem(param_1,0x3000d,&local_158);
        goto LAB_0012caa4;
      }
      local_158 = ext2fs_link(lVar6,2,"lost+found",local_16c,2);
      if (local_158 == 0x7f2bb726) {
        local_158 = ext2fs_expand_dir(lVar6,2);
        if (local_158 == 0) {
          local_158 = ext2fs_link(lVar6,2,"lost+found",local_16c,2);
          goto LAB_0012cd65;
        }
      }
      else {
LAB_0012cd65:
        if (local_158 == 0) {
          e2fsck_add_dir_info(param_1,local_16c,2);
          e2fsck_adjust_inode_count(param_1,2,1);
          ext2fs_icount_store(param_1[0x37],local_16c,2);
          ext2fs_icount_store(param_1[0x38],local_16c,2);
          uVar2 = *(undefined4 *)(*(long *)(lVar6 + 0x20) + 0x1c);
          *(int *)(param_1 + 0x45) = local_16c;
          quota_data_add(param_1[0x4f],local_e8,local_16c,(long)(0x400 << ((byte)uVar2 & 0x1f)));
          quota_data_inodes(param_1[0x4f],local_e8,local_16c,1);
          iVar8 = local_16c;
          goto LAB_0012caa4;
        }
      }
      local_f8 = "ext2fs_link";
      goto LAB_0012cf87;
    }
    local_158 = lVar4;
    fix_problem(param_1,0x3000b,&local_158);
  }
LAB_0012caa4:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_expand_directory @ 0x2d140

long e2fsck_expand_directory(long *param_1,undefined4 param_2,int param_3,int param_4)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 extraout_RDX;
  long in_FS_OFFSET;
  long local_128;
  long local_120;
  long local_118;
  long local_110;
  long local_108;
  long *local_100;
  undefined4 local_f8;
  undefined1 local_e8 [168];
  long local_40;
  
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = 0x7f2bb715;
  if ((*(byte *)(lVar1 + 0x10) & 1) != 0) {
    e2fsck_read_bitmaps();
    lVar2 = ext2fs_check_directory(lVar1,param_2);
    if (lVar2 == 0) {
      local_120 = (long)param_4;
      local_110 = 0;
      local_108 = 0;
      local_118 = 0;
      local_128 = (long)param_3;
      local_100 = param_1;
      local_f8 = param_2;
      ext2fs_block_iterate3(lVar1,param_2,1,0,FUN_0012c2b0,&local_128);
      lVar2 = local_108;
      if (local_108 == 0) {
        uVar3 = FUN_0012c120(local_e8,param_2,extraout_RDX,0xa0);
        lVar2 = ext2fs_read_inode_full(lVar1);
        if (lVar2 == 0) {
          lVar2 = ext2fs_inode_size_set
                            (lVar1,uVar3,(local_110 + 1) * (ulong)*(uint *)(lVar1 + 0x28));
          if (lVar2 == 0) {
            ext2fs_iblk_add_blocks(lVar1,uVar3,local_118);
            quota_data_add(param_1[0x4f],local_e8,param_2,
                           (0x400 << ((byte)*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x1c) & 0x1f))
                           * local_118);
            e2fsck_write_inode_full(param_1,param_2,uVar3,0xa0,"expand_directory");
          }
        }
      }
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_reconnect_file @ 0x2d2e0

undefined4 e2fsck_reconnect_file(undefined8 *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  long in_FS_OFFSET;
  long local_188;
  undefined4 local_180;
  undefined2 local_118 [64];
  undefined1 local_98 [88];
  long local_40;
  
  uVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(&local_188);
  local_180 = param_2;
  if (param_1[0x45] == 0) {
    iVar2 = e2fsck_get_lost_and_found(param_1,1);
    if (iVar2 != 0) goto LAB_0012d331;
    iVar2 = *(int *)((long)param_1 + 0x22c) + 1;
    *(int *)((long)param_1 + 0x22c) = iVar2;
  }
  else {
LAB_0012d331:
    iVar2 = *(int *)((long)param_1 + 0x22c);
  }
  if (iVar2 != 0) {
    uVar4 = 1;
    fix_problem(param_1,0x30006,&local_188);
    goto LAB_0012d3c0;
  }
  __sprintf_chk(local_98,1,0x50,&DAT_00179650);
  lVar3 = ext2fs_read_inode(uVar1,param_2,local_118);
  if (lVar3 == 0) {
    ext2_file_type(local_118[0]);
  }
  lVar3 = ext2fs_link(uVar1,*(undefined4 *)(param_1 + 0x45),local_98,param_2);
  if (lVar3 == 0x7f2bb726) {
    iVar2 = fix_problem(param_1,0x30002,&local_188);
    if (iVar2 == 0) {
      uVar4 = 1;
      goto LAB_0012d3c0;
    }
    lVar3 = e2fsck_expand_directory(param_1,*(undefined4 *)(param_1 + 0x45),1,0);
    if (lVar3 != 0) {
      local_188 = lVar3;
      fix_problem(param_1,0x30007,&local_188);
      uVar4 = 1;
      goto LAB_0012d3c0;
    }
    lVar3 = ext2fs_link(uVar1,*(undefined4 *)(param_1 + 0x45),local_98,param_2);
  }
  if (lVar3 == 0) {
    e2fsck_adjust_inode_count(param_1,param_2,1);
    uVar4 = 0;
  }
  else {
    local_188 = lVar3;
    fix_problem(param_1,0x30008,&local_188);
    uVar4 = 1;
  }
LAB_0012d3c0:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_directory @ 0x2d500

undefined4 check_directory(undefined8 *param_1,int param_2,long *param_3)

{
  undefined8 uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  int iVar9;
  undefined4 uVar10;
  long in_FS_OFFSET;
  int local_44;
  long local_40;
  
  bVar3 = false;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = *param_1;
  iVar6 = 0;
  iVar9 = param_2;
  do {
    iVar4 = ext2fs_mark_inode_bitmap2(DAT_001b7340,iVar9);
    if (iVar4 != 0) {
LAB_0012d657:
      *(int *)(param_3 + 1) = param_2;
      iVar6 = e2fsck_dir_info_get_dotdot(param_1,param_2,(long)param_3 + 0xc);
      if ((iVar6 == 0) &&
         (iVar6 = e2fsck_dir_info_get_parent(param_1,param_2,param_3 + 2), iVar6 == 0)) {
        uVar10 = 0;
        if ((*(int *)((long)param_3 + 0xc) != (int)param_3[2]) &&
           (iVar6 = fix_problem(param_1,0x30005,param_3), iVar6 != 0)) {
          FUN_0012c130(param_1,param_2,(int)param_3[2]);
        }
      }
      else {
LAB_0012d6c0:
        uVar10 = 0;
        fix_problem(param_1,0x30016,param_3);
      }
LAB_0012d6d4:
      if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return uVar10;
    }
    iVar4 = e2fsck_dir_info_get_parent(param_1,iVar9,&local_44);
    if (iVar4 != 0) goto LAB_0012d6c0;
    if (local_44 == 0) {
LAB_0012d638:
      *(int *)(param_3 + 1) = iVar9;
      iVar6 = fix_problem(param_1,0x30003,param_3);
      if (iVar6 != 0) {
        iVar6 = e2fsck_reconnect_file(param_1,(int)param_3[1]);
        if (iVar6 == 0) {
          FUN_0012c130(param_1,(int)param_3[1],*(undefined4 *)(param_1 + 0x45));
          local_44 = *(int *)(param_1 + 0x45);
        }
        else {
          ext2fs_unmark_valid(uVar1);
        }
      }
      goto LAB_0012d657;
    }
    if (bVar3) {
      iVar5 = ext2fs_test_inode_bitmap2(DAT_001b7348);
      iVar4 = local_44;
      if (iVar5 != 0) goto LAB_0012d638;
      ext2fs_mark_inode_bitmap2(DAT_001b7348,local_44);
      iVar9 = iVar4;
    }
    else {
      iVar9 = iVar6 + 1;
      bVar2 = 0x800 < iVar6;
      iVar6 = iVar9;
      iVar9 = local_44;
      if (bVar2) {
        if (DAT_001b7348 == 0) {
          uVar7 = dcgettext(0,"inode loop detection bitmap",5);
          lVar8 = e2fsck_allocate_inode_bitmap(uVar1,uVar7,3,"inode_loop_detect",&DAT_001b7348);
          *param_3 = lVar8;
          if (lVar8 != 0) {
            param_3[10] = 1;
            uVar10 = 0xffffffff;
            fix_problem(param_1,0x30011,param_3);
            *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
            goto LAB_0012d6d4;
          }
          bVar3 = true;
          iVar9 = param_2;
        }
        else {
          ext2fs_clear_inode_bitmap();
          bVar3 = true;
          iVar9 = param_2;
        }
      }
    }
  } while( true );
}



// Function: e2fsck_pass3 @ 0x2d780

void e2fsck_pass3(long *param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined4 *puVar6;
  long lVar7;
  long in_FS_OFFSET;
  undefined1 local_f8 [80];
  long local_a8 [10];
  undefined8 local_58;
  long local_40;
  
  lVar7 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  init_resource_track(local_f8,*(undefined8 *)(lVar7 + 8));
  clear_problem_context(local_a8);
  if ((*(byte *)((long)param_1 + 0x4c) & 2) == 0) {
    fix_problem(param_1,0x30000,local_a8);
  }
  uVar3 = dcgettext(0,"inode done bitmap",5);
  local_a8[0] = e2fsck_allocate_inode_bitmap(lVar7,uVar3,3,"inode_done_map",&DAT_001b7340);
  if (local_a8[0] == 0) {
    uVar3 = dcgettext(0,"Peak memory",5);
    print_resource_track(param_1,uVar3,param_1 + 0x50,0);
    FUN_0012c4c0(param_1);
    if ((*(byte *)(param_1 + 9) & 3) == 0) {
      ext2fs_mark_inode_bitmap2(DAT_001b7340,2);
      iVar1 = e2fsck_get_num_dirinfo(param_1);
      if (((code *)param_1[0x2c] == (code *)0x0) ||
         (iVar2 = (*(code *)param_1[0x2c])(param_1,3,0,(long)iVar1), iVar2 == 0)) {
        lVar7 = 1;
        lVar5 = e2fsck_dir_info_iter_begin(param_1);
        do {
          puVar6 = (undefined4 *)e2fsck_dir_info_iter(param_1,lVar5);
          if (puVar6 == (undefined4 *)0x0) {
            if ((*(byte *)((long)param_1 + 0x4c) & 1) == 0) {
              e2fsck_get_lost_and_found(param_1,1);
            }
            e2fsck_rehash_directories(param_1);
            break;
          }
          if ((*(byte *)(param_1 + 9) & 7) != 0) break;
          if ((code *)param_1[0x2c] != (code *)0x0) {
            iVar2 = (*(code *)param_1[0x2c])(param_1,3,lVar7,(long)iVar1);
            lVar7 = lVar7 + 1;
            if (iVar2 != 0) break;
          }
          iVar2 = ext2fs_test_inode_bitmap2(param_1[0x2f],*puVar6);
        } while ((iVar2 == 0) || (iVar2 = FUN_0012d500(param_1,*puVar6,local_a8), iVar2 == 0));
        if (lVar5 != 0) {
          e2fsck_dir_info_iter_end(param_1,lVar5);
        }
      }
    }
  }
  else {
    local_58 = 2;
    fix_problem(param_1,0x30011,local_a8);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  }
  e2fsck_free_dir_info(param_1);
  if (DAT_001b7348 != 0) {
    ext2fs_free_inode_bitmap();
    DAT_001b7348 = 0;
  }
  if (DAT_001b7340 != 0) {
    ext2fs_free_inode_bitmap();
    DAT_001b7340 = 0;
  }
  if (param_1[0x70] != 0) {
    ext2fs_unmark_block_bitmap2(param_1[0x34]);
    param_1[0x70] = 0;
  }
  if (param_1[0x6f] != 0) {
    ext2fs_unmark_block_bitmap2(param_1[0x34]);
    param_1[0x6f] = 0;
  }
  uVar3 = *(undefined8 *)(*param_1 + 8);
  uVar4 = dcgettext(0,"Pass 3",5);
  print_resource_track(param_1,uVar4,local_f8,uVar3);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: check_ea_inode @ 0x2dad0

void check_ea_inode(long *param_1,ulong param_2,long param_3,undefined2 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined2 uVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  long local_b0;
  undefined1 local_a8 [8];
  undefined4 local_a0;
  long local_58;
  long local_50;
  long local_40;
  
  uVar4 = 0x80;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_b0 = 0;
  iVar1 = *(int *)(*(long *)(*param_1 + 0x20) + 0x4c);
  if (iVar1 != 0) {
    uVar4 = *(undefined2 *)(*(long *)(*param_1 + 0x20) + 0x58);
  }
  uVar5 = param_2 & 0xffffffff;
  uVar2 = FUN_0012dab0(param_3,param_2,iVar1,uVar4,"pass4: check_ea_inode");
  e2fsck_read_inode_full(param_1,uVar5,uVar2);
  if ((*(byte *)(param_3 + 0x22) & 0x20) != 0) {
    if (param_1[0x3d] != 0) {
      ea_refcount_fetch(param_1[0x3d],uVar5,&local_b0);
    }
    if (local_b0 != 0) {
      *param_4 = 1;
      lVar3 = ext2fs_get_ea_inode_ref(uVar2);
      if ((local_b0 != lVar3) && (*(int *)(param_3 + 0xc) != *(int *)(param_3 + 8))) {
        clear_problem_context(local_a8);
        local_50 = local_b0;
        local_a0 = (int)param_2;
        local_58 = lVar3;
        iVar1 = fix_problem(param_1,0x40005,local_a8);
        if (iVar1 != 0) {
          ext2fs_set_ea_inode_ref(uVar2,local_b0);
          e2fsck_write_inode(param_1,uVar5,uVar2,"pass4");
        }
      }
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: disconnect_inode @ 0x2dc20

undefined8 disconnect_inode(long *param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  long lVar7;
  long in_FS_OFFSET;
  undefined1 local_a8 [8];
  undefined4 local_a0;
  undefined8 local_90;
  long local_40;
  
  uVar6 = 0x80;
  lVar2 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(int *)(*(long *)(lVar2 + 0x20) + 0x4c) != 0) {
    uVar6 = *(undefined2 *)(*(long *)(lVar2 + 0x20) + 0x58);
  }
  uVar5 = FUN_0012dab0(param_3,param_2,param_3,uVar6,"pass4: disconnect_inode");
  e2fsck_read_inode_full(param_1);
  local_a0 = param_2;
  local_90 = uVar5;
  if ((*(int *)(*(long *)(lVar2 + 0x20) + 0x4c) == 0) ||
     (*(ushort *)(*(long *)(lVar2 + 0x20) + 0x58) < 0x81)) {
    clear_problem_context(local_a8);
    lVar7 = *(long *)(lVar2 + 0x20);
    if (*(int *)(lVar7 + 0x4c) != 0) {
      uVar3 = 0;
      goto LAB_0012dcfc;
    }
LAB_0012dd70:
    iVar4 = *(int *)(param_3 + 0xe);
joined_r0x0012dd77:
    if (((iVar4 == 0) && (((*param_3 & 0xf000) + 0xc000 & 0xb000) == 0)) &&
       (iVar4 = fix_problem(param_1,0x40001,local_a8), iVar4 != 0)) {
      e2fsck_clear_inode(param_1,param_2,uVar5,0,"disconnect_inode");
      e2fsck_read_bitmaps(param_1);
      ext2fs_inode_alloc_stats2(lVar2,param_2,0xffffffff,(*param_3 & 0xf000) == 0x4000);
      quota_data_inodes(param_1[0x4f],param_3,param_2,0xffffffff);
      uVar5 = 0;
      goto LAB_0012dd4a;
    }
  }
  else {
    uVar1 = param_3[0x40];
    clear_problem_context(local_a8);
    lVar7 = *(long *)(lVar2 + 0x20);
    if (*(int *)(lVar7 + 0x4c) == 0) goto LAB_0012dd70;
    uVar3 = (uint)uVar1;
LAB_0012dcfc:
    iVar4 = *(int *)(param_3 + 0xe);
    if ((int)(*(ushort *)(lVar7 + 0x58) - 0x80) <= (int)uVar3) goto LAB_0012dd70;
    if (*(int *)((long)param_3 + (long)(int)(uVar3 + 0x80)) != -0x15fe0000) goto joined_r0x0012dd77;
  }
  iVar4 = fix_problem(param_1,0x40002,local_a8);
  if (iVar4 == 0) {
    ext2fs_unmark_valid(lVar2);
    uVar5 = 1;
  }
  else {
    uVar5 = e2fsck_reconnect_file(param_1,param_2);
    if ((int)uVar5 != 0) {
      ext2fs_unmark_valid(lVar2);
      uVar5 = 0;
    }
  }
LAB_0012dd4a:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_pass4 @ 0x2de50

void e2fsck_pass4(long *param_1)

{
  byte bVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined8 uVar12;
  uint *puVar13;
  uint *extraout_RDX;
  long in_FS_OFFSET;
  undefined1 auVar14 [16];
  int local_11c;
  ushort local_10c;
  ushort local_10a;
  long local_108;
  long local_100;
  undefined1 local_f8 [80];
  undefined1 local_a8 [8];
  uint local_a0;
  undefined8 local_90;
  ulong local_58;
  long local_40;
  
  lVar6 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = 0x80;
  if (*(int *)(*(long *)(lVar6 + 0x20) + 0x4c) != 0) {
    uVar2 = *(undefined2 *)(*(long *)(lVar6 + 0x20) + 0x58);
  }
  local_100 = 0;
  init_resource_track(local_f8,*(undefined8 *)(lVar6 + 8));
  if ((param_1[0x73] != 0) && ((*(long *)(lVar6 + 0x58) == 0 || (*(long *)(lVar6 + 0x50) == 0)))) {
    e2fsck_readahead(lVar6,0xc,0,*(undefined4 *)(lVar6 + 0x30));
  }
  clear_problem_context(local_a8);
  if ((*(byte *)((long)param_1 + 0x4c) & 2) == 0) {
    fix_problem(param_1,0x40000,local_a8);
  }
  uVar4 = *(undefined4 *)(*(long *)(lVar6 + 0x20) + 100);
  uVar5 = *(undefined4 *)(lVar6 + 0x30);
  if (((code *)param_1[0x2c] == (code *)0x0) ||
     (iVar9 = (*(code *)param_1[0x2c])(param_1,4,0), iVar9 == 0)) {
    local_108 = e2fsck_allocate_memory(param_1,uVar2,"scratch inode");
    if (**(int **)(lVar6 + 0x20) == 0) {
LAB_0012e2e3:
      ext2fs_free_icount(param_1[0x38]);
      param_1[0x38] = 0;
      ext2fs_free_icount(param_1[0x37]);
      param_1[0x37] = 0;
      ext2fs_free_inode_bitmap(param_1[0x30]);
      param_1[0x30] = 0;
      ea_refcount_free(param_1[0x3d]);
      param_1[0x3d] = 0;
      ext2fs_free_inode_bitmap(param_1[0x31]);
      param_1[0x31] = 0;
    }
    else {
      iVar9 = 0;
      local_11c = FUN_0012de40(uVar4);
      bVar1 = *(byte *)(param_1 + 9);
      uVar8 = 1;
      puVar13 = extraout_RDX;
      while ((bVar1 & 3) == 0) {
        if (uVar8 % puVar13[10] == 0) {
          iVar9 = iVar9 + 1;
          if (((code *)param_1[0x2c] != (code *)0x0) &&
             (iVar10 = (*(code *)param_1[0x2c])(param_1,4,iVar9,uVar5), iVar10 != 0)) break;
        }
        uVar11 = quota_type2inum(2,*(undefined8 *)(*param_1 + 0x20));
        if ((uVar11 == uVar8) || (uVar8 == 1)) goto LAB_0012e0d0;
        if (uVar8 == 2) {
LAB_0012dff9:
          iVar10 = ext2fs_test_inode_bitmap2(param_1[0x2d],uVar8);
          if (((iVar10 != 0) &&
              ((param_1[0x31] == 0 ||
               (iVar10 = ext2fs_test_inode_bitmap2(param_1[0x31],uVar8), iVar10 == 0)))) &&
             ((param_1[0x30] == 0 ||
              (iVar10 = ext2fs_test_inode_bitmap2(param_1[0x30],uVar8), iVar10 == 0)))) {
            ext2fs_icount_fetch(param_1[0x38],uVar8,&local_10c);
            ext2fs_icount_fetch(param_1[0x37],uVar8,&local_10a);
            if ((local_10a == 0) &&
               (FUN_0012dad0(param_1,uVar8,local_108,&local_10a), local_10a == 0)) {
              if (local_100 == 0) {
                local_100 = e2fsck_allocate_memory
                                      (param_1,*(undefined4 *)(lVar6 + 0x28),"bad_inode buffer");
              }
              iVar10 = e2fsck_process_bad_inode(param_1,0,uVar8,local_100);
              if ((iVar10 != 0) || (iVar10 = FUN_0012dc20(param_1,uVar8,local_108), iVar10 != 0))
              goto LAB_0012e0d0;
              ext2fs_icount_fetch(param_1[0x38],uVar8,&local_10c);
              ext2fs_icount_fetch(param_1[0x37],uVar8,&local_10a);
            }
            iVar10 = ext2fs_test_inode_bitmap2(param_1[0x2f],uVar8);
            if ((iVar10 != 0) && (65000 < local_10a)) {
              if ((local_11c == 0) &&
                 (local_11c = fix_problem(param_1,0x40006,local_a8), local_11c != 0)) {
                FUN_0012dac0(*(undefined8 *)(lVar6 + 0x20));
                ext2fs_mark_super_dirty(lVar6);
                local_11c = 1;
              }
              local_10a = 1;
            }
            if (local_10c != local_10a) {
              FUN_0012dab0(local_108,uVar8);
              e2fsck_read_inode_full(param_1);
              local_a0 = uVar8;
              auVar14 = FUN_0012dab0(local_108);
              local_90 = auVar14._0_8_;
              uVar3 = *(ushort *)(auVar14._8_8_ + 0x1a);
              local_58 = (ulong)local_10c;
              if (uVar3 == local_10c) {
                local_58 = (ulong)local_10a;
                if (iVar10 != 0) goto LAB_0012e25e;
LAB_0012e278:
                iVar10 = fix_problem(param_1,0x40003,local_a8);
              }
              else {
                if (iVar10 == 0) {
                  if (uVar3 < 0xfde9) {
                    fix_problem(param_1,0x40004,local_a8);
                  }
                  local_58 = (ulong)local_10a;
                  goto LAB_0012e278;
                }
LAB_0012e25e:
                local_58 = (ulong)local_10a;
                if (((local_10a < 2) || ((*(byte *)(auVar14._8_8_ + 0x21) & 0x10) == 0)) ||
                   (local_10c != 1)) goto LAB_0012e278;
                if ((*(byte *)((long)param_1 + 0x4c) & 1) != 0) goto LAB_0012e0d0;
                iVar10 = fix_problem(param_1,0x40007,local_a8);
              }
              if (iVar10 != 0) {
                *(ushort *)(local_108 + 0x1a) = local_10a;
                FUN_0012dab0(local_108,uVar8);
                e2fsck_write_inode_full(param_1);
              }
            }
          }
LAB_0012e0d0:
          puVar13 = *(uint **)(lVar6 + 0x20);
        }
        else {
          puVar13 = *(uint **)(lVar6 + 0x20);
          uVar11 = 0xb;
          if (puVar13[0x13] != 0) {
            uVar11 = puVar13[0x15];
          }
          if (uVar11 <= uVar8) goto LAB_0012dff9;
        }
        if (*puVar13 <= uVar8) goto LAB_0012e2e3;
        uVar8 = uVar8 + 1;
        bVar1 = *(byte *)(param_1 + 9);
      }
    }
    if (local_100 != 0) {
      ext2fs_free_mem(&local_100);
    }
    ext2fs_free_mem(&local_108);
    uVar7 = *(undefined8 *)(*param_1 + 8);
    uVar12 = dcgettext(0,"Pass 4",5);
    print_resource_track(param_1,uVar12,local_f8,uVar7);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: print_bitmap_problem @ 0x2e470

void print_bitmap_problem(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  
  uVar1 = (uint)param_2;
  if (uVar1 == 0x50008) {
    if (*(int *)(param_3 + 8) != *(int *)(param_3 + 0xc)) {
      param_2 = 0x50016;
      goto LAB_0012e49d;
    }
  }
  else {
    if (uVar1 < 0x50009) {
      if (uVar1 == 0x50004) {
        if (*(long *)(param_3 + 0x28) != *(long *)(param_3 + 0x30)) {
          param_2 = 0x50014;
          goto LAB_0012e49d;
        }
      }
      else {
        if (uVar1 != 0x50005) goto LAB_0012e49d;
        if (*(long *)(param_3 + 0x28) != *(long *)(param_3 + 0x30)) {
          param_2 = 0x50015;
          goto LAB_0012e49d;
        }
      }
      *(undefined8 *)(param_3 + 0x30) = 0;
      goto LAB_0012e49d;
    }
    if (uVar1 != 0x50009) goto LAB_0012e49d;
    if (*(int *)(param_3 + 8) != *(int *)(param_3 + 0xc)) {
      param_2 = 0x50017;
      goto LAB_0012e49d;
    }
  }
  *(undefined4 *)(param_3 + 0xc) = 0;
LAB_0012e49d:
  fix_problem(param_1,param_2,param_3);
  *(undefined8 *)(param_3 + 0x30) = 0xffffffffffffffff;
  *(undefined8 *)(param_3 + 0x28) = 0xffffffffffffffff;
  *(undefined8 *)(param_3 + 8) = 0;
  return;
}



// Function: e2fsck_discard_blocks @ 0x2e530

void e2fsck_discard_blocks(long *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *param_1;
  iVar2 = ext2fs_test_changed(lVar1);
  if (iVar2 == 0) {
    if ((*(byte *)((long)param_1 + 0x4d) & 0x20) == 0) {
      return;
    }
    lVar1 = io_channel_discard(*(undefined8 *)(lVar1 + 8),param_2,param_3);
    if (lVar1 == 0) {
      return;
    }
  }
  *(uint *)((long)param_1 + 0x4c) = *(uint *)((long)param_1 + 0x4c) & 0xffffdfff;
  return;
}



// Function: check_block_bitmaps @ 0x2e580

void check_block_bitmaps(long *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  void *pvVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  byte bVar12;
  int iVar13;
  long lVar14;
  uint uVar15;
  long in_FS_OFFSET;
  uint local_160;
  uint local_15c;
  int local_158;
  int local_154;
  long local_148;
  int local_140;
  void *local_130;
  void *local_128;
  void *local_120;
  undefined1 local_118 [8];
  undefined4 local_110;
  undefined4 local_10c;
  ulong local_f0;
  ulong local_e8;
  int local_d8;
  undefined8 local_c8;
  undefined1 local_a8 [40];
  ulong local_80;
  uint local_68;
  long local_40;
  
  lVar14 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar8 = ext2fs_blocks_count(*(undefined8 *)(lVar14 + 0x20));
  local_128 = (void *)e2fsck_allocate_memory
                                (param_1,*(undefined4 *)(lVar14 + 0x28),"actual bitmap buffer");
  local_120 = (void *)e2fsck_allocate_memory
                                (param_1,*(undefined4 *)(lVar14 + 0x28),"bitmap block buffer");
  clear_problem_context(local_118);
  local_130 = (void *)e2fsck_allocate_memory
                                (param_1,(ulong)*(uint *)(lVar14 + 0x30) << 2,
                                 "free block count array");
  uVar1 = *(undefined4 *)(lVar14 + 0xc0);
  uVar15 = *(uint *)(*(long *)(lVar14 + 0x20) + 0x14);
  uVar9 = ext2fs_get_block_bitmap_start2(param_1[0x34]);
  if (uVar15 >> ((byte)uVar1 & 0x1f) < uVar9) {
LAB_0012e661:
    local_c8 = 1;
    local_f0 = (ulong)(*(uint *)(*(long *)(lVar14 + 0x20) + 0x14) >>
                      ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x1f));
    lVar10 = ext2fs_blocks_count();
    local_e8 = lVar10 - 1U >> ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x3f);
    local_110 = ext2fs_get_block_bitmap_start2(param_1[0x34]);
    lVar14 = param_1[0x34];
  }
  else {
    lVar10 = ext2fs_blocks_count(*(undefined8 *)(lVar14 + 0x20));
    uVar1 = *(undefined4 *)(lVar14 + 0xc0);
    uVar9 = ext2fs_get_block_bitmap_end2(param_1[0x34]);
    if (uVar9 < lVar10 - 1U >> ((byte)uVar1 & 0x3f)) goto LAB_0012e661;
    uVar1 = *(undefined4 *)(lVar14 + 0xc0);
    uVar15 = *(uint *)(*(long *)(lVar14 + 0x20) + 0x14);
    uVar9 = ext2fs_get_block_bitmap_start2(*(undefined8 *)(lVar14 + 0x58));
    if (uVar9 <= uVar15 >> ((byte)uVar1 & 0x1f)) {
      lVar10 = ext2fs_blocks_count(*(undefined8 *)(lVar14 + 0x20));
      uVar1 = *(undefined4 *)(lVar14 + 0xc0);
      uVar9 = ext2fs_get_block_bitmap_end2(*(undefined8 *)(lVar14 + 0x58));
      if (lVar10 - 1U >> ((byte)uVar1 & 0x3f) <= uVar9) {
        local_154 = 0;
        do {
          lVar10 = *(long *)(lVar14 + 0x20);
          iVar13 = 0;
          local_e8 = 0xffffffffffffffff;
          local_140 = 0;
          local_f0 = 0xffffffffffffffff;
          local_158 = 0;
          local_15c = 0;
          local_148 = 0;
          local_160 = 0;
          for (uVar9 = (ulong)(*(uint *)(lVar10 + 0x14) >>
                              ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x1f));
              uVar11 = ext2fs_blocks_count(lVar10), uVar9 < uVar11;
              uVar9 = uVar9 + (long)(1 << (bVar12 & 0x1f))) {
            uVar15 = *(uint *)(*(long *)(lVar14 + 0x20) + 0x24);
            uVar2 = *(uint *)(*(long *)(lVar14 + 0x20) + 0x14);
            bVar12 = (byte)*(undefined4 *)(lVar14 + 0xc0);
            iVar5 = ext2fs_fast_test_block_bitmap2(param_1[0x34],uVar9);
            if ((((((uVar9 >> (bVar12 & 0x3f)) - (ulong)(uVar2 >> (bVar12 & 0x1f))) % (ulong)uVar15
                   == 0) && (*(int *)(lVar14 + 0x30) - 1U != local_160)) &&
                ((*(byte *)((long)param_1 + 0x4d) & 0x20) == 0)) &&
               ((lVar10 = ext2fs_get_block_bitmap_range2
                                    (param_1[0x34],
                                     uVar9 >> ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x3f),
                                     *(undefined4 *)(*(long *)(lVar14 + 0x20) + 0x24),local_128),
                lVar10 == 0 &&
                (lVar10 = ext2fs_get_block_bitmap_range2
                                    (*(undefined8 *)(lVar14 + 0x58),
                                     uVar9 >> ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x3f),
                                     *(undefined4 *)(*(long *)(lVar14 + 0x20) + 0x24),local_120),
                pvVar3 = local_128, lVar10 == 0)))) {
              uVar15 = uVar15 >> 3;
              iVar6 = memcmp(local_128,local_120,(ulong)uVar15);
              if (iVar6 != 0) goto LAB_0012e938;
              iVar13 = ext2fs_bitcount(pvVar3,uVar15);
              lVar10 = *(long *)(lVar14 + 0x20);
              local_15c = *(int *)(lVar10 + 0x24) - iVar13;
              uVar9 = uVar9 + (uint)(*(int *)(lVar10 + 0x24) + -1 <<
                                    ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x1f));
              local_148 = local_148 + (ulong)local_15c;
LAB_0012ea34:
              uVar8 = ext2fs_blocks_count(lVar10);
              *(uint *)((long)local_130 + (ulong)local_160 * 4) = local_15c;
              local_160 = local_160 + 1;
              if (((code *)param_1[0x2c] != (code *)0x0) &&
                 (iVar13 = (*(code *)param_1[0x2c])(param_1,5,local_160,*(int *)(lVar14 + 0x30) * 2)
                 , iVar13 != 0)) goto LAB_0012e6d4;
              local_15c = 0;
              bVar12 = (byte)*(undefined4 *)(lVar14 + 0xc0);
              iVar13 = 0;
            }
            else {
LAB_0012e938:
              iVar6 = iVar5;
              if (local_154 == 0) {
                iVar6 = ext2fs_fast_test_block_bitmap2(*(undefined8 *)(lVar14 + 0x58),uVar9);
              }
              if ((iVar5 != 0) == (iVar6 == 0)) {
                if ((iVar5 != 0) || (iVar5 = 0x50004, iVar6 == 0)) {
                  iVar7 = ext2fs_bg_flags_test(lVar14,local_160,2);
                  iVar5 = 0x50005;
                  if (iVar7 != 0) {
                    local_68 = local_160;
                    local_80 = uVar9;
                    iVar5 = fix_problem(param_1,0x50018,local_a8);
                    if (iVar5 != 0) {
                      ext2fs_bg_flags_clear(lVar14,local_160,2);
                    }
                    iVar5 = 0x50005;
                  }
                }
                uVar11 = uVar9;
                uVar4 = uVar9;
                if (local_f0 != 0xffffffffffffffff) {
                  if ((iVar5 == local_158) &&
                     (lVar10 = (long)(1 << ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x1f)),
                     local_e8 == uVar9 - lVar10)) {
                    iVar5 = local_158;
                    uVar11 = local_f0;
                    uVar4 = local_e8 + lVar10;
                  }
                  else {
                    FUN_0012e470(param_1,local_158,local_118);
                  }
                }
                local_e8 = uVar4;
                local_f0 = uVar11;
                local_158 = iVar5;
                *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 0x40;
                local_140 = local_140 + 1;
                *(uint *)((long)param_1 + 0x4c) = *(uint *)((long)param_1 + 0x4c) & 0xffffdfff;
              }
              iVar13 = iVar13 + 1;
              if (iVar6 == 0) {
                local_15c = local_15c + 1;
                local_148 = local_148 + 1;
                if (uVar9 < uVar8) {
                  uVar8 = uVar9;
                }
                if (*(int *)(*(long *)(lVar14 + 0x20) + 0x24) != iVar13) {
                  uVar1 = *(undefined4 *)(lVar14 + 0xc0);
                  lVar10 = ext2fs_blocks_count();
                  bVar12 = (byte)*(undefined4 *)(lVar14 + 0xc0);
                  if (uVar9 >> ((byte)uVar1 & 0x3f) != lVar10 - 1U >> (bVar12 & 0x3f))
                  goto LAB_0012e820;
                }
                if (uVar8 <= uVar9) {
                  FUN_0012e530(param_1,uVar8,(uVar9 + 1) - uVar8);
                }
LAB_0012ea30:
                lVar10 = *(long *)(lVar14 + 0x20);
                goto LAB_0012ea34;
              }
              if (uVar8 < uVar9) {
                FUN_0012e530(param_1,uVar8,uVar9 - uVar8);
                uVar8 = ext2fs_blocks_count(*(undefined8 *)(lVar14 + 0x20));
              }
              lVar10 = *(long *)(lVar14 + 0x20);
              if (*(int *)(lVar10 + 0x24) == iVar13) goto LAB_0012ea34;
              uVar1 = *(undefined4 *)(lVar14 + 0xc0);
              lVar10 = ext2fs_blocks_count();
              bVar12 = (byte)*(undefined4 *)(lVar14 + 0xc0);
              if (lVar10 - 1U >> (bVar12 & 0x3f) == uVar9 >> ((byte)uVar1 & 0x3f))
              goto LAB_0012ea30;
            }
LAB_0012e820:
            lVar10 = *(long *)(lVar14 + 0x20);
          }
          if (local_f0 != 0xffffffffffffffff) {
            FUN_0012e470(param_1,local_158,local_118);
          }
          if (local_140 == 0) {
            *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) & 0xffffffbf;
LAB_0012ec08:
            uVar8 = 0;
            if (*(int *)(lVar14 + 0x30) != 0) {
              do {
                iVar13 = *(int *)((long)local_130 + uVar8 * 4);
                iVar5 = ext2fs_bg_free_blocks_count(lVar14,uVar8);
                if (iVar13 != iVar5) {
                  local_d8 = (int)uVar8;
                  uVar15 = ext2fs_bg_free_blocks_count(lVar14,uVar8);
                  local_f0 = (ulong)uVar15;
                  local_e8 = (ulong)*(uint *)((long)local_130 + uVar8 * 4);
                  iVar13 = fix_problem(param_1,0x5000e,local_118);
                  if (iVar13 == 0) {
                    ext2fs_unmark_valid(lVar14);
                  }
                  else {
                    ext2fs_bg_free_blocks_count_set
                              (lVar14,uVar8,*(undefined4 *)((long)local_130 + uVar8 * 4));
                    ext2fs_mark_super_dirty(lVar14);
                  }
                }
                uVar15 = (int)uVar8 + 1;
                uVar8 = (ulong)uVar15;
              } while (uVar15 < *(uint *)(lVar14 + 0x30));
            }
            uVar9 = local_148 << ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x3f);
            uVar8 = ext2fs_free_blocks_count(*(undefined8 *)(lVar14 + 0x20));
            if (uVar8 != uVar9) {
              local_d8 = 0;
              local_f0 = ext2fs_free_blocks_count(*(undefined8 *)(lVar14 + 0x20));
              local_e8 = uVar9;
              iVar13 = fix_problem(param_1,0x5000f,local_118);
              if (iVar13 != 0) {
                ext2fs_free_blocks_count_set(*(undefined8 *)(lVar14 + 0x20),uVar9);
                ext2fs_mark_super_dirty(lVar14);
              }
            }
            goto LAB_0012e6d4;
          }
          iVar13 = end_problem_latch(param_1,0x40);
          *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) & 0xffffffbf;
          if (iVar13 != 1) {
            if (iVar13 == 0) {
              ext2fs_unmark_valid(lVar14);
            }
            goto LAB_0012ec08;
          }
          ext2fs_free_block_bitmap(*(undefined8 *)(lVar14 + 0x58));
          lVar10 = ext2fs_copy_bitmap(param_1[0x34]);
          if (lVar10 != 0) goto LAB_0012edf3;
          ext2fs_set_bitmap_padding(*(undefined8 *)(lVar14 + 0x58));
          ext2fs_mark_bb_dirty(lVar14);
          memset(local_130,0,(ulong)*(uint *)(lVar14 + 0x30) << 2);
          local_154 = local_154 + 1;
        } while( true );
      }
    }
    local_c8 = 2;
    local_f0 = (ulong)(*(uint *)(*(long *)(lVar14 + 0x20) + 0x14) >>
                      ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x1f));
    lVar10 = ext2fs_blocks_count();
    local_e8 = lVar10 - 1U >> ((byte)*(undefined4 *)(lVar14 + 0xc0) & 0x3f);
    local_110 = ext2fs_get_block_bitmap_start2(*(undefined8 *)(lVar14 + 0x58));
    lVar14 = *(long *)(lVar14 + 0x58);
  }
  local_10c = ext2fs_get_block_bitmap_end2(lVar14);
  fix_problem(param_1,0x50010,local_118);
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
LAB_0012e6d4:
  ext2fs_free_mem(&local_130);
  ext2fs_free_mem(&local_128);
  ext2fs_free_mem(&local_120);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_0012edf3:
  clear_problem_context(local_118);
  fix_problem(param_1,0x50013,local_118);
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  goto LAB_0012e6d4;
}



// Function: e2fsck_discard_inodes @ 0x2ee40

void e2fsck_discard_inodes(long *param_1,ulong param_2,uint param_3,int param_4)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  
  lVar1 = *param_1;
  if ((param_3 == 0) || (lVar5 = *(long *)(lVar1 + 0x20), *(uint *)(lVar5 + 0x28) < param_3)) {
    __printf_chk(1,"PROGRAMMING ERROR: Got start %d outside of group %d! Disabling discard\n",
                 param_3,param_2 & 0xffffffff);
    *(uint *)((long)param_1 + 0x4c) = *(uint *)((long)param_1 + 0x4c) & 0xffffdfff;
  }
  else if (((*(byte *)((long)param_1 + 0x4d) & 0x20) != 0) &&
          ((*(byte *)(*(long *)(lVar1 + 8) + 0x34) & 2) != 0)) {
    uVar6 = 0x80;
    if (*(int *)(lVar5 + 0x4c) != 0) {
      uVar6 = (uint)*(ushort *)(lVar5 + 0x58);
    }
    uVar3 = (long)(0x400 << ((byte)*(undefined4 *)(lVar5 + 0x18) & 0x1f)) / (long)(int)uVar6;
    uVar7 = uVar3 & 0xffffffff;
    iVar4 = (int)uVar3;
    uVar3 = (ulong)((param_3 - 2) + iVar4);
    uVar2 = uVar3 / uVar7;
    lVar5 = ext2fs_inode_table_loc(lVar1,param_2,uVar3 % uVar7);
    lVar1 = *(long *)(lVar1 + 0x20);
    uVar6 = 0x80;
    if (*(int *)(lVar1 + 0x4c) != 0) {
      uVar6 = (uint)*(ushort *)(lVar1 + 0x58);
    }
    if ((int)(((param_3 - 1) + param_4) - iVar4 * (int)uVar2) /
        ((0x400 << ((byte)*(undefined4 *)(lVar1 + 0x18) & 0x1f)) / (int)uVar6) != 0) {
      FUN_0012e530(param_1,uVar2 + lVar5);
      return;
    }
  }
  return;
}



// Function: check_inode_end @ 0x2ef40

void check_inode_end(long *param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  long in_FS_OFFSET;
  uint local_9c;
  long local_98 [10];
  undefined8 local_48;
  long local_30;
  
  lVar1 = *param_1;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_98);
  uVar5 = *(int *)(*(long *)(lVar1 + 0x20) + 0x28) * *(int *)(lVar1 + 0x30);
  local_98[0] = ext2fs_fudge_inode_bitmap_end(*(undefined8 *)(lVar1 + 0x50),uVar5,&local_9c);
  if (local_98[0] == 0) {
    if (local_9c != uVar5) {
      uVar3 = local_9c + 1;
      local_98[0] = 0;
      if (uVar3 <= uVar5) {
LAB_0012efcb:
        uVar4 = *(undefined8 *)(lVar1 + 0x50);
        if (local_9c < uVar3) {
          iVar2 = ext2fs_test_inode_bitmap(uVar4,uVar3);
          if (iVar2 != 0) goto code_r0x0012efbf;
          iVar2 = fix_problem(param_1,0x50001,local_98);
          if (iVar2 == 0) {
            ext2fs_unmark_valid(lVar1);
          }
          else {
            for (; uVar3 <= uVar5; uVar3 = uVar3 + 1) {
              ext2fs_mark_inode_bitmap(*(undefined8 *)(lVar1 + 0x50),uVar3);
            }
            ext2fs_mark_ib_dirty(lVar1);
          }
          local_98[0] = ext2fs_fudge_inode_bitmap_end(*(undefined8 *)(lVar1 + 0x50),local_9c,0);
          if (local_98[0] == 0) goto LAB_0012eff2;
          goto LAB_0012f0a0;
        }
        goto LAB_0012efd3;
      }
LAB_0012f018:
      uVar4 = *(undefined8 *)(lVar1 + 0x50);
LAB_0012efd3:
      local_98[0] = ext2fs_fudge_inode_bitmap_end(uVar4,local_9c,0);
      if (local_98[0] != 0) {
LAB_0012f0a0:
        local_48 = 2;
        goto LAB_0012f029;
      }
    }
    if ((*(byte *)(lVar1 + 0x13) & 2) != 0) {
      iVar2 = fix_problem(param_1,0x50001,local_98);
      if (iVar2 == 0) {
        ext2fs_unmark_valid(lVar1);
      }
      else {
        ext2fs_mark_ib_dirty();
      }
    }
  }
  else {
    local_48 = 1;
LAB_0012f029:
    fix_problem(param_1,0x50011,local_98);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  }
LAB_0012eff2:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
code_r0x0012efbf:
  uVar3 = uVar3 + 1;
  if (uVar5 < uVar3) goto LAB_0012f018;
  goto LAB_0012efcb;
}



// Function: check_block_end @ 0x2f0f0

void check_block_end(long *param_1)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  long in_FS_OFFSET;
  ulong local_a0;
  long local_98 [10];
  undefined8 local_48;
  long local_30;
  
  lVar2 = *param_1;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_98);
  lVar4 = ext2fs_get_block_bitmap_start2(*(undefined8 *)(lVar2 + 0x58));
  uVar1 = (ulong)*(uint *)(*(long *)(lVar2 + 0x20) + 0x24) * (ulong)*(uint *)(lVar2 + 0x30) + -1 +
          lVar4;
  local_98[0] = ext2fs_fudge_block_bitmap_end2(*(undefined8 *)(lVar2 + 0x58),uVar1,&local_a0);
  if (local_98[0] == 0) {
    if (local_a0 != uVar1) {
      uVar5 = local_a0 + 1;
      local_98[0] = 0;
      if (uVar5 <= uVar1) {
LAB_0012f19f:
        uVar6 = *(undefined8 *)(lVar2 + 0x58);
        if (local_a0 < uVar5) {
          iVar3 = ext2fs_test_block_bitmap2
                            (uVar6,uVar5 << ((byte)*(undefined4 *)(lVar2 + 0xc0) & 0x3f));
          if (iVar3 != 0) goto code_r0x0012f191;
          iVar3 = fix_problem(param_1,0x50002,local_98);
          if (iVar3 == 0) {
            ext2fs_unmark_valid(lVar2);
          }
          else {
            for (; uVar5 <= uVar1; uVar5 = uVar5 + 1) {
              ext2fs_mark_block_bitmap2
                        (*(undefined8 *)(lVar2 + 0x58),
                         uVar5 << ((byte)*(undefined4 *)(lVar2 + 0xc0) & 0x3f));
            }
            ext2fs_mark_bb_dirty(lVar2);
          }
          local_98[0] = ext2fs_fudge_block_bitmap_end2(*(undefined8 *)(lVar2 + 0x58),local_a0,0);
          if (local_98[0] == 0) goto LAB_0012f1c7;
          goto LAB_0012f288;
        }
        goto LAB_0012f1a8;
      }
LAB_0012f1f0:
      uVar6 = *(undefined8 *)(lVar2 + 0x58);
LAB_0012f1a8:
      local_98[0] = ext2fs_fudge_block_bitmap_end2(uVar6,local_a0,0);
      if (local_98[0] != 0) {
LAB_0012f288:
        local_48 = 4;
        goto LAB_0012f209;
      }
    }
    if ((*(byte *)(lVar2 + 0x13) & 1) != 0) {
      iVar3 = fix_problem(param_1,0x50002,local_98);
      if (iVar3 == 0) {
        ext2fs_unmark_valid(lVar2);
      }
      else {
        ext2fs_mark_bb_dirty();
      }
    }
  }
  else {
    local_48 = 3;
LAB_0012f209:
    fix_problem(param_1,0x50011,local_98);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  }
LAB_0012f1c7:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
code_r0x0012f191:
  uVar5 = uVar5 + 1;
  if (uVar1 < uVar5) goto LAB_0012f1f0;
  goto LAB_0012f19f;
}



// Function: check_block_bitmap_checksum @ 0x2f2f0

void check_block_bitmap_checksum(long *param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  uint uVar6;
  long in_FS_OFFSET;
  undefined8 local_b0;
  undefined1 local_a8 [64];
  uint local_68;
  long local_40;
  
  lVar3 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_b0 = 0;
  lVar5 = *(long *)(lVar3 + 0x20);
  iVar2 = FUN_0012f2e0(*(undefined4 *)(lVar5 + 100));
  if ((iVar2 != 0) && (iVar2 = ext2fs_test_bb_dirty(lVar3), iVar2 == 0)) {
    uVar1 = *(uint *)(lVar5 + 0x24);
    lVar3 = ext2fs_get_mem(*(undefined4 *)(lVar3 + 0x28),&local_b0);
    if (lVar3 != 0) {
      uVar4 = dcgettext(0,"check_block_bitmap_checksum: Memory allocation error",5);
      com_err(param_1[1],0,&DAT_00178907,uVar4);
                    /* WARNING: Subroutine does not return */
      fatal_error(param_1,0);
    }
    clear_problem_context(local_a8);
    lVar3 = *param_1;
    if (*(int *)(lVar3 + 0x30) != 0) {
      uVar6 = 0;
      do {
        iVar2 = ext2fs_bg_flags_test(lVar3,uVar6,2);
        if (iVar2 == 0) {
          lVar3 = *param_1;
          lVar5 = (long)(int)(uVar1 & 0xfffffff8);
          lVar3 = ext2fs_get_block_bitmap_range2
                            (*(undefined8 *)(lVar3 + 0x58),
                             (ulong)(*(uint *)(*(long *)(lVar3 + 0x20) + 0x14) >>
                                    ((byte)*(undefined4 *)(lVar3 + 0xc0) & 0x1f)) +
                             (ulong)uVar6 * lVar5,lVar5,local_b0);
          if (lVar3 != 0) break;
          iVar2 = ext2fs_block_bitmap_csum_verify(*param_1,uVar6,local_b0,uVar1 >> 3);
          if ((iVar2 == 0) &&
             (local_68 = uVar6, iVar2 = fix_problem(param_1,0x5001b,local_a8), iVar2 != 0)) {
            ext2fs_mark_bb_dirty(*param_1);
            break;
          }
        }
        lVar3 = *param_1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(lVar3 + 0x30));
    }
    ext2fs_free_mem(&local_b0);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: check_inode_bitmap_checksum @ 0x2f4a0

void check_inode_bitmap_checksum(long *param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  long in_FS_OFFSET;
  undefined8 local_b0;
  undefined1 local_a8 [64];
  uint local_68;
  long local_40;
  
  lVar4 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_b0 = 0;
  lVar2 = *(long *)(lVar4 + 0x20);
  iVar3 = FUN_0012f2e0(*(undefined4 *)(lVar2 + 100));
  if ((iVar3 != 0) && (iVar3 = ext2fs_test_ib_dirty(lVar4), iVar3 == 0)) {
    uVar1 = *(uint *)(lVar2 + 0x28);
    lVar4 = ext2fs_get_mem(*(undefined4 *)(lVar4 + 0x28),&local_b0);
    if (lVar4 != 0) {
      uVar5 = dcgettext(0,"check_inode_bitmap_checksum: Memory allocation error",5);
      com_err(param_1[1],0,&DAT_00178907,uVar5);
                    /* WARNING: Subroutine does not return */
      fatal_error(param_1,0);
    }
    clear_problem_context(local_a8);
    lVar4 = *param_1;
    if (*(int *)(lVar4 + 0x30) != 0) {
      uVar6 = 0;
      uVar7 = uVar1 & 0xfffffff8;
      do {
        iVar3 = ext2fs_bg_flags_test(lVar4,uVar6,1);
        if (iVar3 == 0) {
          lVar4 = ext2fs_get_inode_bitmap_range2
                            (*(undefined8 *)(*param_1 + 0x50),uVar7 * uVar6 + 1,(long)(int)uVar7,
                             local_b0);
          if (lVar4 != 0) break;
          iVar3 = ext2fs_inode_bitmap_csum_verify(*param_1,uVar6,local_b0,uVar1 >> 3);
          if ((iVar3 == 0) &&
             (local_68 = uVar6, iVar3 = fix_problem(param_1,0x5001a,local_a8), iVar3 != 0)) {
            ext2fs_mark_ib_dirty(*param_1);
            break;
          }
        }
        lVar4 = *param_1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(lVar4 + 0x30));
    }
    ext2fs_free_mem(&local_b0);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: check_inode_bitmaps @ 0x2f680

void check_inode_bitmaps(long *param_1)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  long lVar10;
  uint uVar11;
  ulong uVar12;
  long lVar13;
  uint uVar14;
  uint uVar15;
  long in_FS_OFFSET;
  bool bVar16;
  uint local_158;
  uint local_154;
  int local_150;
  int local_148;
  int local_144;
  int local_140;
  int local_130;
  void *local_128;
  void *local_120;
  undefined1 local_118 [8];
  undefined8 local_110;
  undefined8 local_f0;
  ulong local_e8;
  uint local_d8;
  undefined8 local_c8;
  undefined1 local_a8 [40];
  ulong local_80;
  int local_68;
  long local_40;
  
  lVar13 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar5 = *(int *)(*(long *)(lVar13 + 0x20) + 0x28);
  clear_problem_context(local_118);
  local_128 = (void *)e2fsck_allocate_memory
                                (param_1,(ulong)*(uint *)(lVar13 + 0x30) << 2,
                                 "free inode count array");
  local_120 = (void *)e2fsck_allocate_memory
                                (param_1,(ulong)*(uint *)(lVar13 + 0x30) << 2,
                                 "directory count array");
  uVar2 = ext2fs_get_inode_bitmap_start2(param_1[0x2d]);
  if ((uVar2 < 2) &&
     (uVar2 = **(uint **)(lVar13 + 0x20), uVar3 = ext2fs_get_inode_bitmap_end2(param_1[0x2d]),
     uVar2 <= uVar3)) {
    uVar2 = ext2fs_get_inode_bitmap_start2(*(undefined8 *)(lVar13 + 0x50));
    if ((uVar2 < 2) &&
       (uVar2 = **(uint **)(lVar13 + 0x20),
       uVar3 = ext2fs_get_inode_bitmap_end2(*(undefined8 *)(lVar13 + 0x50)), uVar2 <= uVar3)) {
      uVar2 = iVar5 + 1;
      iVar5 = FUN_0012f650(*(undefined8 *)(lVar13 + 0x20));
      local_148 = 0;
      local_158 = 0;
      do {
        local_110 = 0;
        if (iVar5 != 0) {
          iVar6 = ext2fs_bg_flags_test(lVar13,0,1);
          local_158 = (local_158 + 1) - (uint)(iVar6 == 0);
        }
        puVar9 = *(uint **)(lVar13 + 0x20);
        if (*puVar9 == 0) {
          local_140 = (int)local_110;
          if ((int)local_110 != 0) {
            FUN_0012e470(param_1,0,local_118);
            local_140 = 0;
          }
LAB_0012fc34:
          *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) & 0xffffffbf;
LAB_0012fc39:
          uVar2 = 0;
          if (*(int *)(lVar13 + 0x30) != 0) {
            do {
              uVar12 = (ulong)uVar2;
              iVar5 = *(int *)((long)local_128 + uVar12 * 4);
              iVar6 = ext2fs_bg_free_inodes_count(lVar13,uVar2);
              if (iVar5 != iVar6) {
                local_d8 = uVar2;
                uVar4 = ext2fs_bg_free_inodes_count(lVar13,uVar2);
                local_110 = CONCAT44(*(undefined4 *)((long)local_128 + uVar12 * 4),uVar4);
                iVar5 = fix_problem(param_1,0x5000b,local_118);
                if (iVar5 == 0) {
                  ext2fs_unmark_valid(lVar13);
                }
                else {
                  ext2fs_bg_free_inodes_count_set
                            (lVar13,uVar2,*(undefined4 *)((long)local_128 + uVar12 * 4));
                  ext2fs_mark_super_dirty(lVar13);
                }
              }
              iVar5 = *(int *)((long)local_120 + uVar12 * 4);
              iVar6 = ext2fs_bg_used_dirs_count(lVar13,uVar2);
              if (iVar5 != iVar6) {
                local_d8 = uVar2;
                uVar4 = ext2fs_bg_used_dirs_count(lVar13,uVar2);
                local_110 = CONCAT44(*(undefined4 *)((long)local_120 + uVar12 * 4),uVar4);
                iVar5 = fix_problem(param_1,0x5000c,local_118);
                if (iVar5 == 0) {
                  ext2fs_unmark_valid(lVar13);
                }
                else {
                  ext2fs_bg_used_dirs_count_set
                            (lVar13,uVar2,*(undefined4 *)((long)local_120 + uVar12 * 4));
                  ext2fs_mark_super_dirty(lVar13);
                }
              }
              uVar2 = uVar2 + 1;
            } while (uVar2 < *(uint *)(lVar13 + 0x30));
          }
          iVar5 = *(int *)(*(long *)(lVar13 + 0x20) + 0x10);
          if (iVar5 != local_140) {
            local_d8 = 0xffffffff;
            local_110 = CONCAT44(local_140,iVar5);
            iVar5 = fix_problem(param_1,0x5000d,local_118);
            if (iVar5 != 0) {
              *(int *)(*(long *)(lVar13 + 0x20) + 0x10) = local_140;
              ext2fs_mark_super_dirty(lVar13);
            }
          }
          goto LAB_0012f77e;
        }
        uVar12 = 0;
        uVar3 = 1;
        local_130 = 0;
        uVar11 = 0;
        local_144 = 0;
        local_150 = 0;
        local_154 = 0;
        local_140 = 0;
        do {
          lVar10 = param_1[0x2d];
          if (local_158 == 0) {
            iVar7 = ext2fs_fast_test_inode_bitmap2(lVar10,uVar3);
            iVar6 = iVar7;
            if (local_148 == 0) {
              iVar6 = ext2fs_fast_test_inode_bitmap2(*(undefined8 *)(lVar13 + 0x50),uVar3);
            }
LAB_0012f8f8:
            if ((iVar7 != 0) == (iVar6 == 0)) {
              if ((iVar7 == 0) && (iVar7 = 0x50008, iVar6 != 0)) {
                iVar8 = iVar7;
                if ((int)local_110 == 0) goto LAB_0012f929;
LAB_0012fb2e:
                if ((iVar8 == local_144) && (local_110._4_4_ == uVar3 - 1)) {
                  local_110 = CONCAT44(uVar3,(int)local_110);
                }
                else {
                  FUN_0012e470(param_1,local_144,local_118);
                  local_110 = CONCAT44(uVar3,uVar3);
                  local_144 = iVar8;
                }
              }
              else {
                if (local_158 != 0) goto LAB_0012fae4;
LAB_0012fb1d:
                iVar8 = 0x50009;
                iVar7 = 0x50009;
                if ((int)local_110 != 0) goto LAB_0012fb2e;
LAB_0012f929:
                local_110 = CONCAT44(uVar3,uVar3);
                local_144 = iVar7;
              }
              *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 0x40;
              local_130 = local_130 + 1;
              *(uint *)((long)param_1 + 0x4c) = *(uint *)((long)param_1 + 0x4c) & 0xffffdfff;
            }
            uVar15 = uVar11 + 1;
            if (iVar6 != 0) {
              iVar7 = ext2fs_test_inode_bitmap2(param_1[0x2f],uVar3);
              local_150 = (local_150 + 1) - (uint)(iVar7 == 0);
              if (uVar2 < uVar15) {
                FUN_0012ee40(param_1,uVar12,uVar2,uVar15 - uVar2);
                puVar9 = *(uint **)(lVar13 + 0x20);
                uVar14 = puVar9[10];
                uVar2 = uVar14 + 1;
              }
              else {
                puVar9 = *(uint **)(lVar13 + 0x20);
                uVar14 = puVar9[10];
              }
              if (uVar15 != uVar14) goto LAB_0012f89c;
              goto LAB_0012f998;
            }
            puVar9 = *(uint **)(lVar13 + 0x20);
            uVar15 = puVar9[10];
LAB_0012f87f:
            uVar14 = uVar11 + 1;
            local_154 = local_154 + 1;
            local_140 = local_140 + 1;
            if (uVar14 < uVar2) {
              uVar2 = uVar14;
            }
            if (uVar14 == uVar15) {
              bVar16 = true;
LAB_0012fbb1:
              if ((uVar2 <= uVar15) && (bVar16)) goto LAB_0012fbc2;
              goto LAB_0012f998;
            }
            iVar6 = 0;
LAB_0012f89c:
            uVar11 = uVar11 + 1;
            if (*puVar9 == uVar3) {
              bVar16 = iVar6 == 0;
              uVar15 = uVar11;
              goto LAB_0012fbb1;
            }
            uVar15 = *puVar9;
            uVar14 = uVar3;
          }
          else {
            if (uVar3 % puVar9[10] != 1) {
LAB_0012f8de:
              iVar6 = ext2fs_fast_test_inode_bitmap2(lVar10,uVar3);
              iVar7 = iVar6;
              if (local_148 != 0) goto LAB_0012f8f8;
              if (iVar6 != 0) {
                iVar6 = 0;
LAB_0012fae4:
                local_80 = (ulong)uVar3;
                local_68 = (int)uVar12;
                iVar7 = fix_problem(param_1,0x50019,local_a8);
                if (iVar7 != 0) {
                  ext2fs_bg_flags_clear(lVar13,uVar12,1);
                  local_158 = 0;
                }
                goto LAB_0012fb1d;
              }
              puVar9 = *(uint **)(lVar13 + 0x20);
              uVar15 = puVar9[10];
              goto LAB_0012f87f;
            }
            iVar6 = ext2fs_test_inode_bitmap_range(lVar10,uVar3,puVar9[10]);
            if (iVar6 == 0) {
              lVar10 = param_1[0x2d];
              goto LAB_0012f8de;
            }
            uVar15 = *(uint *)(*(long *)(lVar13 + 0x20) + 0x28);
            uVar3 = uVar3 + (uVar15 - 1);
            local_140 = uVar15 + local_140;
            uVar2 = (uint)(uVar15 != 0);
            local_154 = uVar15;
LAB_0012fbc2:
            FUN_0012ee40(param_1,uVar12,uVar2,(uVar15 + 1) - uVar2);
LAB_0012f998:
            if ((((*(byte *)((long)param_1 + 0x4d) & 0x20) != 0) &&
                ((*(byte *)(*(long *)(lVar13 + 8) + 0x34) & 2) != 0)) &&
               (iVar6 = ext2fs_bg_flags_test(lVar13,uVar12,4), iVar6 == 0)) {
              ext2fs_bg_flags_set(lVar13,uVar12,4);
              ext2fs_group_desc_csum_set(lVar13,uVar12);
            }
            puVar9 = *(uint **)(lVar13 + 0x20);
            uVar11 = (int)uVar12 + 1;
            pcVar1 = (code *)param_1[0x2c];
            uVar2 = puVar9[10] + 1;
            *(uint *)((long)local_128 + uVar12 * 4) = local_154;
            *(int *)((long)local_120 + uVar12 * 4) = local_150;
            if (pcVar1 != (code *)0x0) {
              iVar6 = (*pcVar1)(param_1,5,*(int *)(lVar13 + 0x30) + uVar11,
                                *(int *)(lVar13 + 0x30) * 2);
              if (iVar6 != 0) goto LAB_0012f77e;
              puVar9 = *(uint **)(lVar13 + 0x20);
            }
            uVar15 = *puVar9;
            uVar12 = (ulong)uVar11;
            uVar14 = uVar3;
            if (iVar5 == 0) {
              local_158 = 0;
              uVar11 = 0;
              local_150 = 0;
              local_154 = 0;
            }
            else {
              if (uVar3 == uVar15) {
                local_158 = 0;
                break;
              }
              iVar6 = ext2fs_bg_flags_test(lVar13,uVar11,1);
              local_150 = 0;
              local_154 = 0;
              uVar11 = 0;
              local_158 = (uint)(iVar6 != 0);
              puVar9 = *(uint **)(lVar13 + 0x20);
              uVar15 = *puVar9;
            }
          }
          uVar3 = uVar14 + 1;
        } while (uVar14 < uVar15);
        if ((int)local_110 != 0) {
          FUN_0012e470(param_1,local_144,local_118);
        }
        if (local_130 == 0) goto LAB_0012fc34;
        iVar6 = end_problem_latch(param_1,0x30);
        *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) & 0xffffffbf;
        if (iVar6 != 1) {
          if (iVar6 == 0) {
            ext2fs_unmark_valid(lVar13);
          }
          goto LAB_0012fc39;
        }
        ext2fs_free_inode_bitmap(*(undefined8 *)(lVar13 + 0x50));
        lVar10 = ext2fs_copy_bitmap(param_1[0x2d]);
        if (lVar10 != 0) goto LAB_0012ff7c;
        ext2fs_set_bitmap_padding(*(undefined8 *)(lVar13 + 0x50));
        ext2fs_mark_ib_dirty(lVar13);
        memset(local_128,0,(ulong)*(uint *)(lVar13 + 0x30) << 2);
        memset(local_120,0,(ulong)*(uint *)(lVar13 + 0x30) << 2);
        local_148 = local_148 + 1;
      } while( true );
    }
    local_c8 = 4;
    local_f0 = 1;
    local_e8 = (ulong)**(uint **)(lVar13 + 0x20);
    uVar4 = ext2fs_get_inode_bitmap_start2(*(undefined8 *)(lVar13 + 0x50));
    lVar13 = *(long *)(lVar13 + 0x50);
    local_110 = CONCAT44(local_110._4_4_,uVar4);
  }
  else {
    local_c8 = 3;
    local_f0 = 1;
    local_e8 = (ulong)**(uint **)(lVar13 + 0x20);
    uVar4 = ext2fs_get_inode_bitmap_start2(param_1[0x2d]);
    lVar13 = param_1[0x2d];
    local_110 = CONCAT44(local_110._4_4_,uVar4);
  }
  uVar4 = ext2fs_get_inode_bitmap_end2(lVar13);
  local_110 = CONCAT44(uVar4,(int)local_110);
  fix_problem(param_1,0x50010,local_118);
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
LAB_0012f77e:
  ext2fs_free_mem(&local_128);
  ext2fs_free_mem(&local_120);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0012ff7c:
  clear_problem_context(local_118);
  fix_problem(param_1,0x50012,local_118);
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  goto LAB_0012f77e;
}



// Function: e2fsck_pass5 @ 0x2ffd0

void e2fsck_pass5(long *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  undefined1 auStack_d8 [80];
  undefined1 local_88 [104];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  init_resource_track(auStack_d8,*(undefined8 *)(*param_1 + 8));
  clear_problem_context(local_88);
  if ((*(byte *)((long)param_1 + 0x4c) & 2) == 0) {
    fix_problem(param_1,0x50000,local_88);
  }
  if ((code *)param_1[0x2c] != (code *)0x0) {
    iVar2 = (*(code *)param_1[0x2c])(param_1,5,0,*(int *)(*param_1 + 0x30) * 2);
    if (iVar2 != 0) goto LAB_00130058;
  }
  e2fsck_read_bitmaps(param_1);
  FUN_0012e580(param_1);
  if ((*(byte *)(param_1 + 9) & 3) == 0) {
    FUN_0012f680(param_1);
    if ((*(byte *)(param_1 + 9) & 3) == 0) {
      FUN_0012ef40(param_1);
      if ((*(byte *)(param_1 + 9) & 3) == 0) {
        FUN_0012f0f0(param_1);
        if ((*(byte *)(param_1 + 9) & 3) == 0) {
          FUN_0012f4a0(param_1);
          FUN_0012f2f0(param_1);
          ext2fs_free_inode_bitmap(param_1[0x2d]);
          param_1[0x2d] = 0;
          ext2fs_free_inode_bitmap(param_1[0x2f]);
          param_1[0x2f] = 0;
          ext2fs_free_block_bitmap(param_1[0x34]);
          param_1[0x34] = 0;
          ext2fs_free_block_bitmap(param_1[0x72]);
          param_1[0x72] = 0;
          uVar1 = *(undefined8 *)(*param_1 + 8);
          uVar3 = dcgettext(0,"Pass 5",5);
          print_resource_track(param_1,uVar3,auStack_d8,uVar1);
        }
      }
    }
  }
LAB_00130058:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: mark_buffer_clean @ 0x301d0

void mark_buffer_clean(long param_1)

{
  *(byte *)(param_1 + 0x18) = *(byte *)(param_1 + 0x18) & 0xfe;
  return;
}



// Function: ex_compar @ 0x301e0

int ex_compar(long param_1,long param_2)

{
  int iVar1;
  
  if (*(ulong *)(param_1 + 8) < *(ulong *)(param_2 + 8)) {
    iVar1 = -1;
  }
  else {
    iVar1 = 1;
    if (*(ulong *)(param_1 + 8) == *(ulong *)(param_2 + 8)) {
      return *(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10);
    }
  }
  return iVar1;
}



// Function: ex_len_compar @ 0x30210

int ex_len_compar(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = 1;
  if (*(uint *)(param_2 + 0x10) <= *(uint *)(param_1 + 0x10)) {
    iVar1 = -(uint)(*(ulong *)(param_2 + 8) < *(ulong *)(param_1 + 8));
  }
  return iVar1;
}



// Function: e2fsck_journal_sb_csum @ 0x30240

void e2fsck_journal_sb_csum(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xfc);
  *(undefined4 *)(param_1 + 0xfc) = 0;
  ext2fs_crc32c_le(0xffffffff,param_1,0x400);
  *(undefined4 *)(param_1 + 0xfc) = uVar1;
  return;
}



// Function: process_journal_block @ 0x30280

undefined8
process_journal_block(long param_1,ulong *param_2,long param_3,undefined8 param_4,undefined8 param_5,
            long *param_6)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = *param_2;
  if (((uVar1 != 0) && (*(uint *)(*(long *)(param_1 + 0x20) + 0x14) <= uVar1)) &&
     (uVar2 = ext2fs_blocks_count(), uVar1 < uVar2)) {
    if (param_3 < 0) {
      return 0;
    }
    *param_6 = param_3;
    return 0;
  }
  return 2;
}



// Function: __errcode_to_errno @ 0x302d0

int __errcode_to_errno(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar2 = error_message();
  __fprintf_chk(stderr,1,"Error \"%s\" encountered in function %s at line %d\n",uVar2,param_2,
                param_3);
  iVar1 = -(int)param_1;
  if (0x100 < param_1) {
    iVar1 = -0xe;
  }
  return iVar1;
}



// Function: ext4_fc_read_extents @ 0x30330

undefined8 ext4_fc_read_extents(long param_1,ulong param_2)

{
  undefined8 uVar1;
  
  if (*(uint *)(param_1 + 0x3d8) != param_2) {
    *(int *)(param_1 + 0x3d8) = (int)param_2;
    uVar1 = e2fsck_read_extents(param_1,param_1 + 0x3b0);
    uVar1 = FUN_001302d0(uVar1,"ext4_fc_read_extents",0x24d);
    return uVar1;
  }
  return 0;
}



// Function: make_room @ 0x30380

undefined8 make_room(long param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == *(int *)(param_1 + 0x14)) {
    uVar2 = ext2fs_resize_mem(0,iVar1 * 0x18 + 0x1ff8,param_1 + 8);
    uVar2 = FUN_001302d0(uVar2,"make_room",0x198);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 0x155;
    iVar1 = *(int *)(param_1 + 0x10);
  }
  memmove((void *)(*(long *)(param_1 + 8) + 0x18 + (long)param_2 * 0x18),
          (void *)(*(long *)(param_1 + 8) + (long)param_2 * 0x18),
          (ulong)(uint)(iVar1 - param_2) * 0x18);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return 0;
}



// Function: ex_sort_and_merge @ 0x30410

void ex_sort_and_merge(long param_1)

{
  long *plVar1;
  long *plVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  int *piVar6;
  ulong uVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  int iVar11;
  size_t __nmemb;
  ulong uVar13;
  ulong uVar12;
  
  if (*(uint *)(param_1 + 0x10) < 2) {
    return;
  }
  qsort(*(void **)(param_1 + 8),(ulong)*(uint *)(param_1 + 0x10),0x18,FUN_00130210);
  if (*(uint *)(param_1 + 0x10) != 0) {
    __nmemb = 0;
    piVar6 = (int *)((long)*(void **)(param_1 + 8) + 0x10);
    do {
      if (*piVar6 == 0) {
        *(int *)(param_1 + 0x10) = (int)__nmemb;
        if ((int)__nmemb == 0) {
          return;
        }
        break;
      }
      __nmemb = __nmemb + 1;
      piVar6 = piVar6 + 6;
    } while (__nmemb != *(uint *)(param_1 + 0x10));
    qsort(*(void **)(param_1 + 8),__nmemb,0x18,FUN_001301e0);
    uVar8 = *(int *)(param_1 + 0x10) - 1;
    if (uVar8 != 0) {
      lVar4 = *(long *)(param_1 + 8);
      uVar12 = 0;
      do {
        iVar11 = (int)uVar12;
        plVar1 = (long *)(lVar4 + uVar12 * 0x18);
        uVar7 = (ulong)(iVar11 + 1U);
        uVar3 = *(uint *)(plVar1 + 2);
        plVar2 = (long *)(lVar4 + uVar7 * 0x18);
        if (((plVar1[1] + (ulong)uVar3 == plVar2[1]) && ((ulong)uVar3 + *plVar1 == *plVar2)) &&
           (((*(uint *)((long)plVar1 + 0x14) ^ *(uint *)((long)plVar2 + 0x14)) & 2) == 0)) {
          *(uint *)(plVar1 + 2) = uVar3 + (int)plVar2[2];
          if (iVar11 + 1U < uVar8) {
            uVar13 = (ulong)(iVar11 + 2);
            puVar9 = (undefined8 *)(lVar4 + uVar13 * 0x18);
            do {
              uVar5 = puVar9[1];
              puVar10 = puVar9 + 3;
              puVar9[uVar13 * -3 + uVar7 * 3] = *puVar9;
              (puVar9 + uVar13 * -3 + uVar7 * 3)[1] = uVar5;
              puVar9[uVar13 * -3 + uVar7 * 3 + 2] = puVar9[2];
              puVar9 = puVar10;
            } while ((undefined8 *)(lVar4 + 0x18 + (((uVar8 - 2) - iVar11) + uVar13) * 0x18) !=
                     puVar10);
          }
          *(uint *)(param_1 + 0x10) = uVar8;
          uVar7 = uVar12;
        }
        else {
          uVar8 = *(uint *)(param_1 + 0x10);
        }
        uVar8 = uVar8 - 1;
        uVar12 = uVar7;
      } while ((uint)uVar7 < uVar8);
    }
  }
  return;
}



// Function: ext4_modify_extent_list @ 0x30560

undefined8 ext4_modify_extent_list(long *param_1,long param_2,undefined8 *param_3,uint param_4)

{
  undefined8 *puVar1;
  ulong uVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  undefined8 uVar11;
  int iVar12;
  uint uVar13;
  ulong uVar14;
  int iVar15;
  long lVar16;
  uint uVar17;
  
  uVar7 = *param_3;
  uVar14 = param_3[1];
  uVar13 = *(uint *)(param_3 + 2);
  uVar8 = param_3[2];
  if (*(int *)(param_2 + 0x10) != 0) {
    lVar10 = *(long *)(param_2 + 8);
    uVar17 = 0;
    do {
      lVar5 = (ulong)uVar17 * 0x18;
      puVar1 = (undefined8 *)(lVar10 + lVar5);
      if (uVar14 <= (puVar1[1] - 1) + (ulong)*(uint *)(puVar1 + 2)) {
        uVar2 = (uVar14 - 1) + (ulong)uVar13;
        if (uVar2 < (ulong)puVar1[1]) break;
        ext2fs_unmark_block_bitmap_range2
                  (*(undefined8 *)(*param_1 + 0x58),*puVar1,(ulong)*(uint *)(puVar1 + 2));
        lVar10 = *(long *)(param_2 + 8);
        plVar3 = (long *)(lVar10 + lVar5);
        uVar9 = plVar3[1];
        uVar6 = *(uint *)(plVar3 + 2);
        iVar15 = (int)uVar9;
        iVar12 = (int)uVar14;
        if (uVar9 < uVar14) {
          if (uVar2 < (uVar9 - 1) + (ulong)uVar6) {
            uVar11 = FUN_00130380(param_2,uVar17 + 1);
            if ((int)uVar11 != 0) {
              return uVar11;
            }
            plVar3 = (long *)(*(long *)(param_2 + 8) + lVar5);
            plVar4 = (long *)(*(long *)(param_2 + 8) + (ulong)(uVar17 + 1) * 0x18);
            lVar10 = plVar3[1];
            *plVar4 = *plVar3;
            plVar4[1] = lVar10;
            lVar10 = plVar3[2];
            lVar5 = plVar3[1];
            plVar4[2] = lVar10;
            lVar16 = (long)(int)((uVar13 + iVar12) - (int)lVar5);
            plVar4[1] = plVar4[1] + lVar16;
            *plVar4 = *plVar4 + lVar16;
            *(uint *)(plVar4 + 2) = ((int)lVar10 + (int)lVar5) - (uVar13 + iVar12);
            *(int *)(plVar3 + 2) = iVar12 - (int)plVar3[1];
            break;
          }
          *(int *)(plVar3 + 2) = iVar12 - iVar15;
        }
        else {
          if (uVar2 < (uVar9 - 1) + (ulong)uVar6) {
            lVar10 = (long)(int)((uVar13 + iVar12) - iVar15);
            *plVar3 = *plVar3 + lVar10;
            *(uint *)(plVar3 + 2) = (uVar6 - (uVar13 + iVar12)) + iVar15;
            plVar3[1] = uVar9 + lVar10;
            break;
          }
          *(undefined4 *)(plVar3 + 2) = 0;
        }
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 < *(uint *)(param_2 + 0x10));
  }
  if (((param_4 & 1) == 0) && (uVar13 != 0)) {
    FUN_00130380(param_2,*(undefined4 *)(param_2 + 0x10));
    puVar1 = (undefined8 *)(*(long *)(param_2 + 8) + (ulong)(*(int *)(param_2 + 0x10) - 1) * 0x18);
    *puVar1 = uVar7;
    puVar1[1] = uVar14;
    puVar1[2] = uVar8;
  }
  uVar14 = 0;
  FUN_00130410(param_2);
  if (*(int *)(param_2 + 0x10) != 0) {
    do {
      uVar13 = (int)uVar14 + 1;
      puVar1 = (undefined8 *)(*(long *)(param_2 + 8) + uVar14 * 0x18);
      ext2fs_mark_block_bitmap_range2
                (*(undefined8 *)(*param_1 + 0x58),*puVar1,*(undefined4 *)(puVar1 + 2));
      uVar14 = (ulong)uVar13;
    } while (uVar13 < *(uint *)(param_2 + 0x10));
  }
  ext2fs_mark_bb_dirty(*param_1);
  return 0;
}



// Function: ext4_add_extent_to_list @ 0x30790

void ext4_add_extent_to_list(void)

{
  FUN_00130560();
  return;
}



// Function: ext4_del_extent_from_list @ 0x307a0

void ext4_del_extent_from_list(void)

{
  FUN_00130560();
  return;
}



// Function: ext4_fc_replay_fixup_iblocks @ 0x307c0

void ext4_fc_replay_fixup_iblocks(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((*(uint *)(param_1 + 0x20) & 0x80000) == 0) {
    if ((*(uint *)(param_1 + 0x20) & 0x10000000) != 0) {
      uVar1 = *(undefined8 *)(param_2 + 0x30);
      *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)(param_2 + 0x28);
      *(undefined8 *)(param_1 + 0x30) = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x40);
      *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)(param_2 + 0x38);
      *(undefined8 *)(param_1 + 0x40) = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x50);
      *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_2 + 0x48);
      *(undefined8 *)(param_1 + 0x50) = uVar1;
      *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)(param_2 + 0x58);
      *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
      return;
    }
  }
  else if (*(short *)(param_1 + 0x28) != -0xcf6) {
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined2 *)(param_1 + 0x28) = 0xf30a;
    *(undefined2 *)(param_1 + 0x2c) = 4;
    return;
  }
  return;
}



// Function: ext4_fc_flush_extents @ 0x30840

void ext4_fc_flush_extents(long param_1,ulong param_2)

{
  if ((*(uint *)(param_1 + 0x3d8) != 0) && (*(uint *)(param_1 + 0x3d8) != param_2)) {
    e2fsck_rewrite_extent_tree(param_1,param_1 + 0x3b0);
    ext2fs_free_mem(param_1 + 0x3b8);
    *(undefined1 (*) [16])(param_1 + 0x3b0) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(param_1 + 0x3c0) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(param_1 + 0x3d0) = (undefined1  [16])0x0;
    return;
  }
  return;
}



// Function: ext4_fc_handle_inode @ 0x308a0

void ext4_fc_handle_inode(long *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 uVar5;
  size_t __n;
  long in_FS_OFFSET;
  int local_5c;
  undefined8 *local_58;
  undefined8 *local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = *param_2;
  local_58 = (undefined8 *)0x0;
  local_50 = (undefined8 *)0x0;
  if ((*(int *)(*(long *)(*param_1 + 0x20) + 0x4c) == 0) ||
     (*(ushort *)(*(long *)(*param_1 + 0x20) + 0x58) < 0x81)) {
    local_5c = 0x80;
    __n = 0x80;
  }
  else {
    local_5c = *(ushort *)(param_2 + 0x21) + 0x80;
    __n = (size_t)local_5c;
  }
  lVar4 = ext2fs_get_mem(__n,&local_58);
  if (lVar4 == 0) {
    lVar4 = ext2fs_get_mem(__n,&local_50);
    if (lVar4 == 0) {
      FUN_00130840(param_1);
      lVar4 = ext2fs_read_inode_full(*param_1,uVar1,local_58,local_5c);
      if (lVar4 == 0) {
        memcpy(local_50,param_2 + 1,__n);
        puVar3 = local_50;
        puVar2 = local_58;
        uVar5 = local_50[1];
        *local_58 = *local_50;
        local_58[1] = uVar5;
        uVar5 = local_50[3];
        local_58[2] = local_50[2];
        local_58[3] = uVar5;
        local_58[4] = local_50[4];
        memcpy((void *)((long)local_58 + 100),(void *)((long)local_50 + 100),__n - 100);
        FUN_001307c0(puVar2,puVar3);
        uVar5 = FUN_00130170();
        lVar4 = ext2fs_count_blocks(*param_1,uVar1,uVar5);
        if (lVar4 == 0) {
          uVar5 = FUN_00130170(local_58);
          ext2fs_iblk_set(*param_1,uVar5,local_48);
          ext2fs_inode_csum_set(*param_1,uVar1,local_58);
          lVar4 = ext2fs_write_inode_full(*param_1,uVar1,local_58,local_5c);
          if (lVar4 == 0) {
            if (*(short *)((long)local_58 + 0x1a) == 0) {
              ext2fs_unmark_inode_bitmap2(*(undefined8 *)(*param_1 + 0x50),uVar1);
            }
            else {
              ext2fs_mark_inode_bitmap2(*(undefined8 *)(*param_1 + 0x50),uVar1);
            }
            ext2fs_mark_ib_dirty(*param_1);
          }
        }
      }
    }
  }
  ext2fs_free_mem(&local_58);
  ext2fs_free_mem(&local_50);
  FUN_001302d0(lVar4,"ext4_fc_handle_inode",0x319);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ext4_fc_handle_add_extent @ 0x30ad0

void ext4_fc_handle_add_extent(long param_1,ulong *param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  undefined1 local_58 [16];
  undefined8 local_48;
  undefined8 local_38;
  ulong local_30;
  long local_20;
  
  local_38 = *param_2;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_2[1];
  uVar3 = local_38 & 0xffffffff;
  FUN_00130840(param_1,uVar3);
  iVar1 = FUN_00130330(param_1,uVar3);
  if (iVar1 == 0) {
    local_58 = (undefined1  [16])0x0;
    local_48 = 0;
    uVar2 = ext2fs_decode_extent(local_58,(long)&local_38 + 4,0xc);
    iVar1 = FUN_001302d0(uVar2,"ext4_fc_handle_add_extent",0x32e);
    if (iVar1 == 0) {
      FUN_00130790(param_1,param_1 + 0x3b0,local_58);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ext4_fc_handle_del_range @ 0x30b90

void ext4_fc_handle_del_range(long param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  uint uStack_40;
  undefined1 local_38 [16];
  ulong local_28;
  long local_20;
  
  uVar2 = *param_2;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = *(uint *)(param_2 + 1);
  lVar4 = (long)(int)uVar2;
  FUN_00130840(param_1,lVar4);
  uStack_40 = (uint)((ulong)uVar2 >> 0x20);
  local_38 = ZEXT416(uStack_40) << 0x40;
  local_28 = (ulong)uVar1;
  iVar3 = FUN_00130330(param_1,lVar4);
  if (iVar3 == 0) {
    FUN_001307a0(param_1,param_1 + 0x3b0,local_38);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: tl_to_darg @ 0x30c70

undefined8 tl_to_darg(ulong *param_1,long param_2,ulong *param_3)

{
  ulong uVar1;
  int iVar2;
  void *pvVar3;
  undefined8 uVar4;
  
  uVar1 = *param_3;
  *param_1 = uVar1 & 0xffffffff;
  param_1[2] = uVar1 >> 0x20;
  iVar2 = FUN_00130c60(*(undefined2 *)(param_2 + 2));
  *(int *)(param_1 + 1) = iVar2 + -8;
  pvVar3 = malloc((long)(iVar2 + -7));
  param_1[3] = (ulong)pvVar3;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    uVar1 = param_1[1];
    pvVar3 = memcpy(pvVar3,param_3 + 1,(long)(int)uVar1);
    *(undefined1 *)((long)pvVar3 + (long)(int)uVar1) = 0;
    uVar4 = 0;
  }
  return uVar4;
}



// Function: ext4_fc_handle_link_and_create @ 0x30ce0

int ext4_fc_handle_link_and_create(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  long in_FS_OFFSET;
  undefined4 local_108 [4];
  undefined4 local_f8;
  void *local_f0;
  ushort local_e8 [84];
  long local_40;
  
  uVar3 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_00130c70(local_108);
  if (iVar1 != 0) goto LAB_00130d19;
  FUN_00130840(param_1,0);
  uVar2 = ext2fs_read_inode(uVar3,local_f8,local_e8);
  iVar1 = FUN_001302d0(uVar2,"ext4_fc_handle_link_and_create",0x2a2);
  if (iVar1 == 0) {
    local_e8[0] = local_e8[0] & 0xf000;
    if (local_e8[0] == 0x8000) {
      uVar4 = 1;
    }
    else if (local_e8[0] == 0x4000) {
      uVar4 = 2;
    }
    else if (local_e8[0] == 0x2000) {
      uVar4 = 3;
    }
    else if (local_e8[0] == 0x6000) {
      uVar4 = 4;
    }
    else {
      if (local_e8[0] == 0xa000) {
        iVar1 = 7;
        goto LAB_00130d19;
      }
      if (local_e8[0] == 0x1000) {
        uVar4 = 5;
      }
      else {
        if (local_e8[0] != 0xc000) {
          iVar1 = -0x16;
          goto LAB_00130de0;
        }
        uVar4 = 6;
      }
    }
    ext2fs_unlink(uVar3,local_108[0],local_f0,local_f8,1);
    uVar3 = ext2fs_link(uVar3,local_108[0],local_f0,local_f8,uVar4);
    iVar1 = FUN_001302d0(uVar3,"ext4_fc_handle_link_and_create",0x2c3);
    free(local_f0);
  }
  else {
LAB_00130de0:
    free(local_f0);
  }
LAB_00130d19:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ext4_fc_handle_unlink @ 0x30eb0

int ext4_fc_handle_unlink(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  undefined4 local_48 [4];
  ulong local_38;
  void *local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_00130c70(local_48);
  if (iVar1 == 0) {
    FUN_00130840(param_1,local_38);
    uVar2 = ext2fs_unlink(*param_1,local_48[0],local_30,local_38 & 0xffffffff,0);
    iVar1 = FUN_001302d0(uVar2,"ext4_fc_handle_unlink",0x28f);
    free(local_30);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_journal_fix_bad_inode @ 0x30fa0

undefined8
e2fsck_journal_fix_bad_inode(long *param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 extraout_XMM0_Qb;
  
  lVar1 = *(long *)(*param_1 + 0x20);
  uVar5 = (ulong)*(uint *)(lVar1 + 0x60);
  iVar3 = FUN_00130f90(*(undefined4 *)(lVar1 + 0x5c),param_2,param_2,param_4,param_5,uVar5);
  iVar4 = *(int *)(lVar1 + 0xe0);
  if (iVar3 == 0) {
    if (iVar4 == 0) {
      iVar4 = FUN_00130f60(uVar5 & 0xffffffff);
      uVar6 = 0;
      if (iVar4 != 0) {
        iVar4 = fix_problem(param_1,0x17);
        uVar6 = 0x7f2bb743;
        if (iVar4 != 0) {
          FUN_00130c30(*param_1,1);
          uVar6 = 0;
        }
      }
      return uVar6;
    }
    *(int *)(param_2 + 8) = iVar4;
    iVar4 = fix_problem(param_1,0xf);
    if (iVar4 == 0) {
      return 0x7f2bb7b0;
    }
  }
  else {
    *(int *)(param_2 + 8) = iVar4;
    iVar4 = fix_problem(param_1,0xf);
    if (iVar4 == 0) {
      return 0x7f2bb7b0;
    }
    if (*(int *)(lVar1 + 0xe0) != 0) {
      __printf_chk(1,"*** journal has been deleted ***\n\n");
    }
  }
  uVar6 = FUN_00130190(0,lVar1,1);
  *(undefined8 *)(lVar1 + 0x10c) = uVar6;
  *(undefined8 *)(lVar1 + 0x114) = extraout_XMM0_Qb;
  *(undefined4 *)(lVar1 + 0x14c) = 0;
  *(undefined8 *)(lVar1 + 0x11c) = uVar6;
  *(undefined8 *)(lVar1 + 0x124) = extraout_XMM0_Qb;
  *(undefined8 *)(lVar1 + 300) = uVar6;
  *(undefined8 *)(lVar1 + 0x134) = extraout_XMM0_Qb;
  *(undefined8 *)(lVar1 + 0x13c) = uVar6;
  *(undefined8 *)(lVar1 + 0x144) = extraout_XMM0_Qb;
  lVar2 = *param_1;
  *(undefined4 *)(lVar1 + 0xe0) = 0;
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 0x80;
  *(uint *)(lVar2 + 0x10) = *(uint *)(lVar2 + 0x10) & 0xfffffdff;
  FUN_00130c30();
  return 0;
}



// Function: e2fsck_journal_verify_csum_type @ 0x31500

bool e2fsck_journal_verify_csum_type(undefined8 param_1,long param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = jbd2_journal_has_csum_v2or3();
  bVar2 = true;
  if (iVar1 != 0) {
    bVar2 = *(char *)(param_2 + 0x50) == '\x04';
  }
  return bVar2;
}



// Function: e2fsck_journal_sb_csum_verify @ 0x31530

bool e2fsck_journal_sb_csum_verify(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = jbd2_journal_has_csum_v2or3();
  bVar3 = true;
  if (iVar1 != 0) {
    iVar1 = ext2fs_swab32(*(undefined4 *)(param_2 + 0xfc));
    iVar2 = FUN_00130240(param_2);
    bVar3 = iVar1 == iVar2;
  }
  return bVar3;
}



// Function: ext4_fc_replay_scan @ 0x31690

undefined8 ext4_fc_replay_scan(long param_1,long param_2,int param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  ushort uVar9;
  long in_FS_OFFSET;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_40;
  
  puVar1 = (uint *)(param_2 + 0x28);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar4 = **(long **)(param_1 + 0x70);
  iVar2 = *(int *)(param_1 + 0x78);
  local_78 = (undefined1  [16])0x0;
  local_68 = 0;
  iVar5 = *(int *)(lVar4 + 0x3e4);
  if (iVar5 == 0) {
    *(undefined8 *)(lVar4 + 0x3f0) = 0;
    *(undefined1 (*) [16])(lVar4 + 0x3b0) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(lVar4 + 0x3c0) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(lVar4 + 0x3d0) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(lVar4 + 0x3e0) = (undefined1  [16])0x0;
    if (*(short *)(param_2 + 0x28) != 9) {
LAB_0013173c:
      uVar8 = 0;
      goto LAB_0013173e;
    }
    iVar5 = *(int *)(lVar4 + 0x3e4);
  }
  if (param_3 == iVar5) {
    *(int *)(lVar4 + 0x3e4) = param_3 + 1;
    for (; puVar1 < (uint *)(param_2 + 0x27 + (long)iVar2);
        puVar1 = (uint *)((long)puVar1 + (ulong)(uVar3 >> 0x10) + 4)) {
      uVar3 = *puVar1;
      uVar9 = (ushort)uVar3;
      if (uVar9 == 8) {
        *(int *)(lVar4 + 0x3ec) = *(int *)(lVar4 + 0x3ec) + 1;
        uVar8 = *(undefined8 *)(puVar1 + 1);
        iVar5 = jbd2_chksum(param_1,*(undefined4 *)(lVar4 + 0x3f0),puVar1,8);
        if ((param_4 != (int)uVar8) || (iVar5 != (int)((ulong)uVar8 >> 0x20))) {
          uVar8 = 0x80d44851;
          *(undefined4 *)(lVar4 + 0x3f0) = 0;
          if (*(int *)(lVar4 + 0x3e0) != 0) goto LAB_0013173c;
          goto LAB_0013173e;
        }
        *(undefined4 *)(lVar4 + 0x3f0) = 0;
        *(undefined4 *)(lVar4 + 0x3e0) = *(undefined4 *)(lVar4 + 0x3ec);
      }
      else if (uVar9 < 9) {
        if (uVar9 != 1) {
          if ((ushort)(uVar9 - 2) < 6) goto LAB_00131787;
LAB_0013172d:
          if (*(int *)(lVar4 + 0x3e0) != 0) goto LAB_0013173c;
          uVar8 = 0xffffff83;
          goto LAB_0013173e;
        }
        local_58 = *(undefined8 *)(puVar1 + 1);
        uStack_50 = *(undefined8 *)(puVar1 + 3);
        iVar5 = ext2fs_decode_extent(local_78,(long)&local_58 + 4,0xc);
        *(int *)(lVar4 + 0x3ec) = *(int *)(lVar4 + 0x3ec) + 1;
        iVar7 = FUN_00130c60(uVar3 >> 0x10);
        uVar6 = jbd2_chksum(param_1,*(undefined4 *)(lVar4 + 0x3f0),extraout_RDX_00,iVar7 + 4);
        *(undefined4 *)(lVar4 + 0x3f0) = uVar6;
        if (iVar5 != 0) goto LAB_0013173c;
      }
      else {
        if (uVar9 != 9) goto LAB_0013172d;
        if ((int)*(undefined8 *)(puVar1 + 1) != 0) {
          uVar8 = 0xffffffa1;
          goto LAB_0013173e;
        }
        if (param_4 != (int)((ulong)*(undefined8 *)(puVar1 + 1) >> 0x20)) {
          uVar8 = 0xffffffea;
          goto LAB_0013173e;
        }
LAB_00131787:
        *(int *)(lVar4 + 0x3ec) = *(int *)(lVar4 + 0x3ec) + 1;
        iVar5 = FUN_00130c60(uVar3 >> 0x10);
        uVar6 = jbd2_chksum(param_1,*(undefined4 *)(lVar4 + 0x3f0),extraout_RDX,iVar5 + 4);
        *(undefined4 *)(lVar4 + 0x3f0) = uVar6;
      }
    }
    uVar8 = 1;
  }
  else {
    uVar8 = 0x80d44852;
  }
LAB_0013173e:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ext4_fc_replay @ 0x31940

ulong ext4_fc_replay(long param_1,long param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  uint *puVar1;
  ushort uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long in_FS_OFFSET;
  undefined4 local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  plVar4 = (long *)**(long **)(param_1 + 0x70);
  if (param_3 == 0) {
    *(undefined4 *)(plVar4 + 0x7d) = 0;
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      uVar9 = FUN_00131690(param_1,param_2,param_4,param_5);
      return uVar9;
    }
    goto LAB_00131bc2;
  }
  if ((int)plVar4[0x7c] == 0) {
LAB_00131b30:
    uVar9 = 0;
    if ((int)plVar4[0x7d] == param_3) {
      ext2fs_calculate_summary_stats(*plVar4,0);
      ext2fs_write_block_bitmap(*plVar4);
      ext2fs_write_inode_bitmap(*plVar4);
      lVar6 = *plVar4;
      ext2fs_mark_super_dirty(lVar6);
      ext2fs_set_gdt_csum(lVar6);
      *(undefined2 *)(*(long *)(*plVar4 + 0x20) + 0x3a) = *(undefined2 *)((long)plVar4 + 0x3f4);
      ext2fs_flush();
    }
  }
  else {
    uVar9 = 1;
    if (param_3 != (int)plVar4[0x7d]) {
      *(int *)(plVar4 + 0x7d) = param_3;
      *(uint *)(*plVar4 + 0x10) = *(uint *)(*plVar4 + 0x10) | 0x200000;
      uVar8 = ext2fs_read_bitmaps();
      uVar7 = FUN_001302d0(uVar8,"ext4_fc_replay",0x369);
      uVar9 = (ulong)uVar7;
      if (uVar7 != 0) goto LAB_00131a40;
      lVar6 = *plVar4;
      lVar5 = *(long *)(lVar6 + 0x20);
      uVar2 = *(ushort *)(lVar5 + 0x3a);
      *(ushort *)((long)plVar4 + 0x3f4) = uVar2;
      *(ushort *)(lVar5 + 0x3a) = uVar2 | 0x22;
      ext2fs_mark_super_dirty(lVar6);
      ext2fs_flush(lVar6);
    }
    iVar3 = *(int *)(param_1 + 0x78);
    for (puVar1 = (uint *)(param_2 + 0x28); puVar1 < (uint *)(param_2 + 0x27 + (long)iVar3);
        puVar1 = (uint *)((long)puVar1 + (ulong)local_44._2_2_ + 4)) {
      local_44 = *puVar1;
      if ((int)plVar4[0x7c] == 0) goto LAB_00131b30;
      *(int *)(plVar4 + 0x7c) = (int)plVar4[0x7c] + -1;
      switch(local_44 & 0xffff) {
      default:
        uVar9 = 0xffffff83;
        goto LAB_00131a40;
      case 1:
        uVar7 = FUN_00130ad0(plVar4);
        uVar9 = (ulong)uVar7;
        break;
      case 2:
        uVar7 = FUN_00130b90(plVar4);
        uVar9 = (ulong)uVar7;
        break;
      case 3:
      case 4:
        uVar7 = FUN_00130ce0(plVar4,&local_44,puVar1 + 1);
        uVar9 = (ulong)uVar7;
        break;
      case 5:
        uVar7 = FUN_00130eb0(plVar4,&local_44,puVar1 + 1);
        uVar9 = (ulong)uVar7;
        break;
      case 6:
        uVar7 = FUN_001308a0(plVar4);
        uVar9 = (ulong)uVar7;
        break;
      case 7:
      case 9:
        break;
      case 8:
        FUN_00130840(plVar4,0);
        goto LAB_00131a25;
      }
      if ((int)uVar9 < 0) break;
LAB_00131a25:
      uVar9 = 1;
    }
  }
LAB_00131a40:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar9;
  }
LAB_00131bc2:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: jbd2_journal_bmap @ 0x31c30

int jbd2_journal_bmap(long param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  long in_FS_OFFSET;
  undefined8 local_18;
  
  puVar1 = *(undefined8 **)(param_1 + 0x88);
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = 0;
  if (puVar1 != (undefined8 *)0x0) {
    iVar3 = ext2fs_bmap2(*(undefined8 *)*puVar1,*(undefined4 *)(puVar1 + 1),(long)puVar1 + 0xc,0,0,
                         param_2,0);
    iVar3 = -iVar3;
    param_2 = local_18;
  }
  *param_3 = param_2;
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: getblk @ 0x31cb0

void getblk(long *param_1,long param_2,undefined4 param_3)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  
  plVar2 = (long *)e2fsck_allocate_memory
                             ((long *)*param_1,(long)(*(int *)(*(long *)*param_1 + 0x28) + 0x28),
                              "block buffer");
  if (plVar2 != (long *)0x0) {
    plVar1 = (long *)*param_1;
    lVar3 = param_1[1];
    *plVar2 = (long)plVar1;
    if ((int)lVar3 == 1) {
      lVar3 = *(long *)(*plVar1 + 8);
    }
    else {
      lVar3 = plVar1[0x4d];
    }
    plVar2[1] = lVar3;
    *(undefined4 *)(plVar2 + 2) = param_3;
    plVar2[4] = param_2;
  }
  return;
}



// Function: sync_blockdev @ 0x31d20

uint sync_blockdev(long *param_1)

{
  long lVar1;
  
  if ((int)param_1[1] == 1) {
    lVar1 = *(long *)(*(long *)*param_1 + 8);
  }
  else {
    lVar1 = ((long *)*param_1)[0x4d];
  }
  lVar1 = (**(code **)(*(long *)(lVar1 + 8) + 0x38))();
  return -(uint)(lVar1 != 0) & 0xfffffffb;
}



// Function: ll_rw_block @ 0x31d60

void ll_rw_block(int param_1,undefined8 param_2,int param_3,long *param_4)

{
  long lVar1;
  long lVar2;
  char *pcVar3;
  long *plVar4;
  undefined8 uVar6;
  long *plVar5;
  
  if (param_3 < 1) {
    return;
  }
  plVar4 = param_4;
  do {
    plVar5 = plVar4 + 1;
    plVar4 = (long *)*plVar4;
    if (param_1 == 0) {
      if ((*(byte *)(plVar4 + 3) & 2) == 0) {
        lVar1 = io_channel_read_blk64(plVar4[1],plVar4[4],1,plVar4 + 5);
        if (lVar1 != 0) {
          lVar2 = plVar4[4];
          pcVar3 = "while reading block %llu\n";
          uVar6 = *(undefined8 *)(*plVar4 + 0x18);
          goto LAB_00131e3f;
        }
        *(byte *)(plVar4 + 3) = *(byte *)(plVar4 + 3) | 2;
      }
    }
    else if ((param_1 == 1) && ((*(byte *)(plVar4 + 3) & 1) != 0)) {
      lVar1 = io_channel_write_blk64(plVar4[1],plVar4[4],1,plVar4 + 5);
      if (lVar1 == 0) {
        *(byte *)(plVar4 + 3) = *(byte *)(plVar4 + 3) & 0xfc | 2;
      }
      else {
        lVar2 = plVar4[4];
        uVar6 = *(undefined8 *)(*plVar4 + 0x18);
        pcVar3 = "while writing block %llu\n";
LAB_00131e3f:
        com_err(uVar6,lVar1,pcVar3,lVar2);
        *(int *)((long)plVar4 + 0x14) = (int)lVar1;
      }
    }
    plVar4 = plVar5;
    if (plVar5 == param_4 + param_3) {
      return;
    }
  } while( true );
}



// Function: mark_buffer_dirty @ 0x31e80

void mark_buffer_dirty(long param_1)

{
  *(byte *)(param_1 + 0x18) = *(byte *)(param_1 + 0x18) | 1;
  return;
}



// Function: clear_v2_journal_fields @ 0x31e90

void clear_v2_journal_fields(long param_1)

{
  long *plVar1;
  int iVar2;
  long in_FS_OFFSET;
  undefined1 auStack_88 [104];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  plVar1 = (long *)**(long **)(param_1 + 0x68);
  clear_problem_context(auStack_88);
  iVar2 = fix_problem(plVar1,0x2a,auStack_88);
  if (iVar2 != 0) {
    *(uint *)(plVar1 + 9) = *(uint *)(plVar1 + 9) | 0x4000;
    memset((void *)(*(long *)(param_1 + 0x18) + 0x24),0,(ulong)(*(int *)(*plVar1 + 0x28) - 0x24));
    mark_buffer_dirty(*(undefined8 *)(param_1 + 0x10));
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_journal_load @ 0x31f20

long e2fsck_journal_load(long param_1)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  char *pcVar9;
  int *piVar10;
  long lVar11;
  long in_FS_OFFSET;
  long local_a0;
  undefined1 local_98 [104];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  plVar1 = (long *)**(long **)(param_1 + 0x68);
  local_a0 = *(long *)(param_1 + 0x10);
  clear_problem_context(local_98);
  ll_rw_block(0,0,1,&local_a0);
  if (*(int *)(local_a0 + 0x14) != 0) {
    uVar8 = dcgettext(0,"reading journal superblock\n",5);
    com_err(plVar1[3],(long)*(int *)(local_a0 + 0x14),&DAT_00178907,uVar8);
    lVar7 = (long)*(int *)(local_a0 + 0x14);
    goto LAB_00131ff8;
  }
  piVar2 = *(int **)(param_1 + 0x18);
  iVar3 = FUN_001307b0(0xc03b3998);
  if (*piVar2 != iVar3) {
    lVar7 = FUN_00130fa0(plVar1,local_98);
    goto LAB_00131ff8;
  }
  uVar4 = FUN_001307b0(piVar2[1]);
  if (uVar4 == 4) {
    *(undefined4 *)(param_1 + 0x20) = 2;
    uVar4 = FUN_001307b0(piVar2[0x10]);
    piVar10 = piVar2;
    if (1 < uVar4) {
      iVar3 = uuid_is_null(*(long *)(*plVar1 + 0x20) + 0xd0);
      if (iVar3 != 0) {
        FUN_00131e90(param_1);
      }
      uVar4 = FUN_001307b0(piVar2[0x10]);
      if (1 < uVar4) {
        fix_problem(plVar1,0x10,local_98);
        lVar7 = 0x7f2bb756;
        goto LAB_00131ff8;
      }
      iVar3 = *(int *)(param_1 + 0x20);
LAB_00131fd3:
      if (iVar3 < 2) goto LAB_001320da;
      piVar10 = *(int **)(param_1 + 0x18);
    }
    uVar4 = ext2fs_swab32(0xffffffc0);
    lVar7 = 0x7f2bb743;
    if ((uVar4 & piVar10[10]) != 0) goto LAB_00131ff8;
    uVar4 = ext2fs_swab32(0xffffffff);
    lVar7 = 0x7f2bb744;
    if ((uVar4 & piVar10[0xb]) != 0) goto LAB_00131ff8;
  }
  else {
    if (4 < uVar4) {
      lVar7 = 0x7f2bb756;
      if (uVar4 == 5) {
        lVar7 = 0x7f2bb7b0;
      }
      goto LAB_00131ff8;
    }
    if (uVar4 != 3) {
      lVar7 = (-(ulong)(uVar4 == 0) & 0xffffffffffffffa6) + 0x7f2bb7b0;
      goto LAB_00131ff8;
    }
    iVar3 = piVar2[9];
    *(undefined4 *)(param_1 + 0x20) = 1;
    if ((((iVar3 != 0) || (piVar2[10] != 0)) || (piVar2[0xb] != 0)) || (piVar2[0x10] != 0)) {
      FUN_00131e90(param_1);
      iVar3 = *(int *)(param_1 + 0x20);
      goto LAB_00131fd3;
    }
  }
LAB_001320da:
  iVar3 = jbd2_has_feature_csum2(param_1);
  if ((((iVar3 == 0) || (iVar3 = jbd2_has_feature_csum3(param_1), iVar3 == 0)) &&
      ((iVar3 = jbd2_journal_has_csum_v2or3(param_1), iVar3 == 0 ||
       (iVar3 = jbd2_has_feature_checksum(param_1), iVar3 == 0)))) &&
     ((iVar3 = FUN_00131500(param_1,piVar2), iVar3 != 0 &&
      (iVar3 = FUN_00131530(param_1,piVar2), iVar3 != 0)))) {
    iVar3 = jbd2_journal_has_csum_v2or3(param_1);
    if (iVar3 != 0) {
      uVar5 = jbd2_chksum(param_1,0xffffffff,piVar2 + 0xc,0x10);
      *(undefined4 *)(param_1 + 0xc4) = uVar5;
    }
    iVar3 = FUN_001307b0(*(undefined4 *)(param_1 + 0x78));
    if (piVar2[3] == iVar3) {
      uVar4 = FUN_001307b0(piVar2[4]);
      if (uVar4 < *(uint *)(param_1 + 0x80)) {
        *(uint *)(param_1 + 0x80) = uVar4;
      }
      else if (*(uint *)(param_1 + 0x80) < uVar4) {
        lVar7 = plVar1[3];
        pcVar9 = "%s: journal too short\n";
        goto LAB_00132211;
      }
      uVar5 = FUN_001307b0(piVar2[6]);
      iVar3 = piVar2[7];
      *(undefined4 *)(param_1 + 0x90) = uVar5;
      *(undefined4 *)(param_1 + 0x94) = uVar5;
      uVar6 = FUN_001307b0(iVar3);
      iVar3 = piVar2[5];
      *(ulong *)(param_1 + 0x30) = (ulong)uVar6;
      uVar6 = FUN_001307b0(iVar3);
      *(ulong *)(param_1 + 0x58) = (ulong)uVar6;
      iVar3 = jbd2_has_feature_fast_commit(param_1);
      if (iVar3 == 0) {
        *(ulong *)(param_1 + 0x60) = (ulong)uVar4;
        lVar7 = 0;
        goto LAB_00131ff8;
      }
      iVar3 = jbd2_journal_get_num_fc_blks(piVar2);
      if (0x3ff < uVar4 - iVar3) {
        *(ulong *)(param_1 + 0x48) = (ulong)uVar4;
        iVar3 = jbd2_journal_get_num_fc_blks(piVar2);
        lVar11 = (ulong)uVar4 - (long)iVar3;
        lVar7 = 0;
        *(long *)(param_1 + 0x60) = lVar11;
        *(long *)(param_1 + 0x38) = lVar11 + 1;
        goto LAB_00131ff8;
      }
      lVar7 = plVar1[3];
      pcVar9 = "%s: incorrect fast commit blocks\n";
    }
    else {
      lVar7 = plVar1[3];
      pcVar9 = "%s: no valid journal superblock found\n";
    }
LAB_00132211:
    uVar8 = dcgettext(0,pcVar9,5);
    com_err(plVar1[1],0x7f2bb7b0,uVar8,lVar7);
  }
  lVar7 = 0x7f2bb7b0;
LAB_00131ff8:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar7;
}



// Function: e2fsck_journal_reset_super @ 0x32340

void e2fsck_journal_reset_super(long *param_1,int *param_2,long param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int extraout_EDX;
  int *piVar4;
  long in_FS_OFFSET;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  piVar4 = param_2;
  iVar2 = FUN_001307b0(0xc03b3998);
  if ((*piVar4 != iVar2) || (iVar3 = FUN_001307b0(3), iVar2 = extraout_EDX, piVar4[1] != iVar3)) {
    *param_2 = iVar2;
    iVar2 = FUN_001307b0(4);
    param_2[1] = iVar2;
  }
  memset(param_2 + 3,0,(ulong)*(uint *)(*param_1 + 0x28) - 0xc);
  iVar2 = FUN_001307b0(*(undefined4 *)(*param_1 + 0x28));
  uVar1 = *(undefined4 *)(param_3 + 0x80);
  param_2[3] = iVar2;
  iVar2 = FUN_001307b0(uVar1);
  param_2[4] = iVar2;
  iVar2 = FUN_001307b0(1);
  param_2[5] = iVar2;
  uuid_generate(&local_38);
  iVar2 = FUN_001307b0(local_38 ^ local_34 ^ local_30 ^ local_2c,param_2);
  param_2[6] = iVar2;
  FUN_00131570(param_3);
  mark_buffer_dirty(*(undefined8 *)(param_3 + 0x10),0,1,param_3 + 0x10);
  ll_rw_block(1);
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: e2fsck_journal_fix_corrupt_super @ 0x32450

undefined8 e2fsck_journal_fix_corrupt_super(long *param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 extraout_RDX;
  
  uVar2 = *(undefined4 *)(*(long *)(*param_1 + 0x20) + 0x60);
  iVar1 = FUN_00130f90(*(undefined4 *)(*(long *)(*param_1 + 0x20) + 0x5c));
  if (iVar1 == 0) {
    lVar3 = FUN_00130fa0(param_1,extraout_RDX);
    if (lVar3 == 0) {
      return 0;
    }
  }
  else {
    iVar1 = fix_problem(param_1,0x15);
    if (iVar1 != 0) {
      FUN_00132340(param_1,*(undefined8 *)(param_2 + 0x18),param_2);
      *(undefined4 *)(param_2 + 0x94) = 1;
      uVar2 = FUN_00130f60(uVar2);
      FUN_00130c30(*param_1,uVar2);
      return 0;
    }
  }
  return 0x7f2bb7b0;
}



// Function: brelse @ 0x324e0

void brelse(long param_1)

{
  long local_10;
  
  local_10 = param_1;
  if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
    ext2fs_free_mem(&local_10);
    return;
  }
  ll_rw_block(1,0,1,&local_10);
  ext2fs_free_mem(&local_10);
  return;
}



// Function: e2fsck_get_journal @ 0x32540

undefined8 e2fsck_get_journal(long *param_1,long *param_2)

{
  undefined8 *puVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 auVar5 [16];
  int iVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  code *pcVar10;
  undefined8 uVar11;
  long lVar12;
  code *pcVar13;
  undefined8 extraout_RDX;
  ulong extraout_RDX_00;
  undefined8 extraout_RDX_01;
  long extraout_RDX_02;
  undefined8 extraout_RDX_03;
  undefined8 extraout_RDX_04;
  undefined8 extraout_RDX_05;
  char cVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  bool bVar18;
  long lVar19;
  undefined8 *puVar20;
  long in_FS_OFFSET;
  byte bVar21;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  long local_a78;
  long local_a70;
  undefined8 *local_a68;
  undefined8 *local_a60;
  long local_a58;
  long local_a50;
  undefined1 local_a48 [112];
  undefined8 local_9d8 [4];
  undefined8 *local_9b8;
  undefined8 local_868 [7];
  short local_830;
  undefined4 local_808;
  undefined4 local_804;
  undefined1 local_800 [920];
  undefined8 local_468 [128];
  undefined1 local_68 [40];
  long local_40;
  
  bVar21 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_a68 = (undefined8 *)0x0;
  local_a60 = (undefined8 *)0x0;
  local_a58 = 0;
  local_a50 = 0;
  lVar19 = *(long *)(*param_1 + 0x20);
  clear_problem_context(local_a48);
  local_a58 = e2fsck_allocate_memory(param_1,0xd0,"journal");
  if (local_a58 == 0) {
    uVar11 = 0x7f2bb746;
    goto LAB_001326d0;
  }
  auVar22 = e2fsck_allocate_memory(param_1,0x20,&DAT_00179a76);
  local_a60 = auVar22._0_8_;
  if (local_a60 == (undefined8 *)0x0) {
LAB_00132988:
    local_a60 = auVar22._0_8_;
    auVar23._8_8_ = auVar22._8_8_;
    auVar23._0_8_ = 0x7f2bb746;
  }
  else {
    local_a60[2] = param_1;
    puVar1 = local_a60 + 2;
    *local_a60 = param_1;
    *(undefined4 *)(local_a60 + 1) = 1;
    *(undefined4 *)(local_a60 + 3) = 2;
    *(undefined8 **)(local_a58 + 0x70) = local_a60;
    lVar12 = *param_1;
    *(undefined8 **)(local_a58 + 0x68) = puVar1;
    *(undefined8 *)(local_a58 + 0x88) = 0;
    *(undefined4 *)(local_a58 + 0x78) = *(undefined4 *)(lVar12 + 0x28);
    iVar6 = uuid_is_null(lVar19 + 0xd0);
    if (iVar6 == 0) {
      lVar12 = param_1[0x4e];
      if (lVar12 == 0) {
        uuid_unparse(lVar19 + 0xd0,local_68);
        lVar12 = blkid_get_devname(param_1[0x11],&DAT_00179a89,local_68);
        param_1[0x4e] = lVar12;
        if (lVar12 == 0) {
          lVar12 = blkid_devno_to_devname(*(undefined4 *)(lVar19 + 0xe4));
          param_1[0x4e] = lVar12;
          if (lVar12 == 0) {
            fix_problem(param_1,0x11,local_a48);
            auVar23._8_8_ = extraout_RDX_04;
            auVar23._0_8_ = 0x7f2bb757;
            goto LAB_00132690;
          }
        }
      }
      cVar14 = ((*(uint *)((long)param_1 + 0x7c) & 6) != 6) * '\x02' + '\x01';
      if (((*(uint *)((long)param_1 + 0x7c) & 4) != 0) &&
         ((*(byte *)((long)param_1 + 0x4d) & 1) != 0)) {
        cVar14 = '\x01';
      }
      auVar23 = (**(code **)(unix_io_manager + 0x10))(lVar12,cVar14,param_1 + 0x4d);
      if (auVar23._0_8_ == 0) {
        (**(code **)(*(long *)(param_1[0x4d] + 8) + 0x20))
                  (param_1[0x4d],*(undefined4 *)(*param_1 + 0x28));
        iVar6 = ext2fs_journal_sb_start(*(undefined4 *)(*param_1 + 0x28));
        lVar19 = (long)(iVar6 + -1);
        local_a50 = lVar19;
        auVar23 = getblk(puVar1,lVar19,*(undefined4 *)(*param_1 + 0x28));
        auVar22._8_8_ = auVar23._8_8_;
        auVar22._0_8_ = local_a60;
        local_a70 = auVar23._0_8_;
        if (local_a70 == 0) goto LAB_00132988;
        ll_rw_block(0,0,1,&local_a70);
        iVar7 = *(int *)(local_a70 + 0x14);
        if ((long)iVar7 == 0) {
          lVar12 = 0x80;
          puVar16 = (undefined8 *)(local_a70 + 0x428);
          puVar15 = local_868;
          puVar20 = (undefined8 *)(local_a70 + 0x428);
          if (lVar19 != 0) {
            puVar16 = (undefined8 *)(local_a70 + 0x28);
            puVar20 = (undefined8 *)(local_a70 + 0x28);
          }
          for (; lVar12 != 0; lVar12 = lVar12 + -1) {
            *puVar15 = *puVar16;
            puVar16 = puVar16 + (ulong)bVar21 * -2 + 1;
            puVar15 = puVar15 + (ulong)bVar21 * -2 + 1;
          }
          if ((local_830 == -0x10ad) &&
             (lVar19 = local_a70, iVar7 = FUN_00130f50(local_808), iVar7 != 0)) {
            puVar16 = (undefined8 *)*param_1;
            iVar7 = memcmp(local_800,(void *)(puVar16[4] + 0xd0),0x10);
            if (iVar7 == 0) {
              iVar7 = FUN_00130f70(local_804);
              if (iVar7 != 0) {
                puVar15 = puVar16;
                puVar17 = local_9d8;
                for (lVar19 = 0x2e; lVar19 != 0; lVar19 = lVar19 + -1) {
                  *puVar17 = *puVar15;
                  puVar15 = puVar15 + (ulong)bVar21 * -2 + 1;
                  puVar17 = puVar17 + (ulong)bVar21 * -2 + 1;
                }
                puVar16 = (undefined8 *)puVar16[4];
                puVar15 = local_468;
                for (lVar19 = 0x80; lVar19 != 0; lVar19 = lVar19 + -1) {
                  *puVar15 = *puVar16;
                  puVar16 = puVar16 + (ulong)bVar21 * -2 + 1;
                  puVar15 = puVar15 + (ulong)bVar21 * -2 + 1;
                }
                local_9b8 = local_468;
                uVar11 = FUN_001301a0(local_468,puVar20);
                iVar7 = ext2fs_superblock_csum_verify(uVar11);
                lVar19 = local_a70;
                if ((iVar7 == 0) &&
                   (iVar7 = fix_problem(param_1,0x4a,local_a48), lVar19 = local_a70, iVar7 != 0)) {
                  ext2fs_superblock_csum_set(local_9d8,puVar20);
                  mark_buffer_dirty(local_a70);
                  lVar19 = local_a70;
                }
              }
              brelse(lVar19);
              uVar9 = ext2fs_blocks_count(local_868);
              local_a50 = (long)iVar6;
              if (0xffffffff < uVar9) {
                uVar9 = 0xffffffff;
              }
              *(int *)(local_a58 + 0x80) = (int)uVar9;
LAB_00132ad1:
              auVar23 = getblk(puVar1,local_a50,*(undefined4 *)(local_a58 + 0x78));
              auVar22._8_8_ = auVar23._8_8_;
              auVar22._0_8_ = local_a60;
              local_a70 = auVar23._0_8_;
              if (local_a70 != 0) {
                pcVar13 = (code *)0x0;
                *(long *)(local_a58 + 0x10) = local_a70;
                *(long *)(local_a58 + 0x18) = local_a70 + 0x28;
                iVar6 = FUN_00130f80(*(undefined4 *)(*(long *)(*param_1 + 0x20) + 0x5c));
                pcVar10 = FUN_00131940;
                if (iVar6 == 0) {
                  pcVar10 = pcVar13;
                }
                uVar11 = 0;
                *(code **)(extraout_RDX_02 + 200) = pcVar10;
                *param_2 = extraout_RDX_02;
                e2fsck_use_inode_shortcuts(param_1,0);
                goto LAB_001326d0;
              }
              goto LAB_00132988;
            }
            uVar11 = 0x13;
          }
          else {
            uVar11 = 0x12;
          }
          fix_problem(param_1,uVar11,local_a48);
          brelse(local_a70);
          auVar23._8_8_ = extraout_RDX_05;
          auVar23._0_8_ = 0x7f2bb757;
        }
        else {
          brelse(local_a70);
          auVar23._8_8_ = extraout_RDX_03;
          auVar23._0_8_ = (long)iVar7;
        }
      }
    }
    else {
      auVar23._8_8_ = extraout_RDX;
      auVar23._0_8_ = 0x7f2bb729;
      if (*(int *)(lVar19 + 0xe0) != 0) {
        auVar23 = e2fsck_allocate_memory(param_1,0x90,"journal inode");
        auVar22._8_8_ = auVar23._8_8_;
        auVar22._0_8_ = local_a60;
        local_a68 = auVar23._0_8_;
        if (local_a68 == (undefined8 *)0x0) goto LAB_00132988;
        uVar3 = *(undefined4 *)(lVar19 + 0xe0);
        lVar12 = *param_1;
        *local_a68 = param_1;
        *(undefined4 *)(local_a68 + 1) = uVar3;
        auVar23 = ext2fs_read_inode(lVar12,uVar3,(long)local_a68 + 0xc);
        uVar9 = auVar23._8_8_;
        if (auVar23._0_8_ == 0) {
          if (*(short *)((long)local_a68 + 0x26) != 0) {
            bVar18 = false;
            if ((*(ushort *)((long)local_a68 + 0xc) & 0xf000) == 0x8000) goto LAB_00132881;
            goto LAB_00132781;
          }
          bVar18 = false;
          uVar11 = 0x7f2bb758;
          goto LAB_0013278b;
        }
        if (*(char *)(lVar19 + 0xfd) == '\x01') {
          do {
            *(undefined8 *)((long)local_a68 + 0xc) = 0;
            *(undefined8 *)((long)local_a68 + 0x84) = 0;
            puVar16 = (undefined8 *)((long)local_a68 + 0x14U & 0xfffffffffffffff8);
            uVar9 = (ulong)(((int)local_a68 - (int)puVar16) + 0x8cU >> 3);
            for (; uVar9 != 0; uVar9 = uVar9 - 1) {
              *puVar16 = 0;
              puVar16 = puVar16 + (ulong)bVar21 * -2 + 1;
            }
            uVar11 = *(undefined8 *)(lVar19 + 0x114);
            *(undefined8 *)((long)local_a68 + 0x34) = *(undefined8 *)(lVar19 + 0x10c);
            *(undefined8 *)((long)local_a68 + 0x3c) = uVar11;
            uVar11 = *(undefined8 *)(lVar19 + 0x124);
            *(undefined8 *)((long)local_a68 + 0x44) = *(undefined8 *)(lVar19 + 0x11c);
            *(undefined8 *)((long)local_a68 + 0x4c) = uVar11;
            uVar11 = *(undefined8 *)(lVar19 + 0x134);
            *(undefined8 *)((long)local_a68 + 0x54) = *(undefined8 *)(lVar19 + 300);
            *(undefined8 *)((long)local_a68 + 0x5c) = uVar11;
            *(undefined8 *)((long)local_a68 + 100) = *(undefined8 *)(lVar19 + 0x13c);
            *(undefined4 *)((long)local_a68 + 0x6c) = *(undefined4 *)(lVar19 + 0x144);
            *(undefined4 *)(local_a68 + 0xf) = *(undefined4 *)(lVar19 + 0x148);
            uVar3 = *(undefined4 *)(lVar19 + 0x14c);
            *(undefined2 *)((long)local_a68 + 0xc) = 0x8180;
            *(undefined4 *)(local_a68 + 2) = uVar3;
            *(undefined2 *)((long)local_a68 + 0x26) = 1;
            e2fsck_use_inode_shortcuts(param_1,1);
            sVar2 = *(short *)((long)local_a68 + 0x26);
            *(undefined4 *)(param_1 + 0x43) = *(undefined4 *)(local_a68 + 1);
            param_1[0x44] = (long)local_a68 + 0xc;
            if (sVar2 == 0) {
              auVar23._8_8_ = extraout_RDX_00;
              auVar23._0_8_ = 0x7f2bb758;
              break;
            }
            bVar18 = true;
            uVar9 = extraout_RDX_00;
            if ((*(ushort *)((long)local_a68 + 0xc) & 0xf000) == 0x8000) {
LAB_00132881:
              uVar9 = CONCAT44(*(undefined4 *)(local_a68 + 0xf),*(undefined4 *)(local_a68 + 2)) %
                      (ulong)(long)*(int *)(local_a58 + 0x78);
              if (0x3ff < CONCAT44(*(undefined4 *)(local_a68 + 0xf),*(undefined4 *)(local_a68 + 2))
                          / (ulong)(long)*(int *)(local_a58 + 0x78)) {
                local_a78 = -1;
                lVar8 = ext2fs_block_iterate3
                                  (*param_1,*(undefined4 *)(local_a68 + 1),1,0,FUN_00130280,
                                   &local_a78);
                lVar12 = *param_1;
                uVar9 = (ulong)*(uint *)(local_a68 + 2);
                if ((long)(int)*(uint *)(local_a68 + 2) <=
                    (long)((local_a78 + 1) * (ulong)*(uint *)(lVar12 + 0x28))) {
                  if ((bVar18) && ((*(byte *)((long)param_1 + 0x4c) & 1) == 0)) {
                    auVar23 = ext2fs_write_inode(lVar12,*(undefined4 *)(lVar19 + 0xe0),
                                                 (long)local_a68 + 0xc);
                    if (auVar23._0_8_ != 0) break;
                    lVar12 = *param_1;
                    uVar9 = (ulong)*(uint *)(local_a68 + 2);
                    lVar8 = 0;
                  }
                  uVar4 = *(uint *)(local_a68 + 0xf);
                  *(undefined8 **)(local_a58 + 0x88) = local_a68;
                  *(int *)(local_a58 + 0x80) =
                       (int)(((ulong)uVar4 << 0x20 | uVar9) /
                            (ulong)(long)*(int *)(local_a58 + 0x78));
                  param_1[0x4d] = *(long *)(lVar12 + 8);
                  iVar6 = jbd2_journal_bmap(local_a58,0,&local_a50);
                  auVar23._8_8_ = extraout_RDX_01;
                  auVar23._0_8_ = lVar8;
                  if (iVar6 == 0) {
                    if (lVar8 == 0) {
                      (**(code **)(*(long *)(param_1[0x4d] + 8) + 0x20))
                                (param_1[0x4d],*(undefined4 *)(*param_1 + 0x28));
                      goto LAB_00132ad1;
                    }
                  }
                  else {
                    auVar23._0_8_ = (long)-iVar6;
                  }
                  break;
                }
              }
              uVar11 = 0x7f2bb755;
            }
            else {
LAB_00132781:
              uVar11 = 0x7f2bb758;
            }
LAB_0013278b:
            auVar5._8_8_ = uVar9;
            auVar5._0_8_ = uVar11;
            auVar23._8_8_ = uVar9;
            auVar23._0_8_ = uVar11;
            if ((*(char *)(lVar19 + 0xfd) != '\x01') || (auVar23 = auVar5, bVar18)) break;
          } while( true );
        }
      }
    }
  }
LAB_00132690:
  uVar11 = auVar23._0_8_;
  e2fsck_use_inode_shortcuts(param_1,0,auVar23._8_8_);
  if (local_a60 != (undefined8 *)0x0) {
    ext2fs_free_mem(&local_a60);
  }
  if (local_a68 != (undefined8 *)0x0) {
    ext2fs_free_mem(&local_a68);
  }
  if (local_a58 != 0) {
    ext2fs_free_mem(&local_a58);
  }
LAB_001326d0:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}



// Function: e2fsck_journal_release @ 0x32d40

void e2fsck_journal_release(long *param_1,long param_2,undefined8 param_3,int param_4)

{
  undefined4 uVar1;
  int extraout_EDX;
  long lVar2;
  long local_10;
  
  local_10 = param_2;
  if (param_4 == 0) {
    if ((*(byte *)((long)param_1 + 0x4c) & 1) == 0) {
      lVar2 = *(long *)(param_2 + 0x18);
      uVar1 = FUN_001307b0(*(undefined4 *)(param_2 + 0x90));
      *(undefined4 *)(lVar2 + 0x18) = uVar1;
      if (extraout_EDX != 0) {
        *(undefined4 *)(lVar2 + 0x1c) = 0;
      }
      FUN_00131570(param_2);
      mark_buffer_dirty(*(undefined8 *)(local_10 + 0x10));
    }
  }
  else {
    FUN_001301d0(*(undefined8 *)(param_2 + 0x10));
  }
  brelse();
  lVar2 = param_1[0x4d];
  if (lVar2 != 0) {
    if ((*param_1 != 0) && (lVar2 != *(long *)(*param_1 + 8))) {
      (**(code **)(*(long *)(lVar2 + 8) + 0x18))();
    }
    param_1[0x4d] = 0;
  }
  if (*(long *)(local_10 + 0x88) != 0) {
    ext2fs_free_mem(local_10 + 0x88);
  }
  if (*(long *)(local_10 + 0x70) != 0) {
    ext2fs_free_mem(local_10 + 0x70);
  }
  ext2fs_free_mem(&local_10);
  return;
}



// Function: recover_ext3_journal @ 0x32e30

long recover_ext3_journal(undefined8 param_1)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  long in_FS_OFFSET;
  long local_a0;
  undefined1 local_98 [8];
  int local_90;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  clear_problem_context(local_98);
  iVar2 = jbd2_journal_init_revoke_record_cache();
  lVar3 = (long)iVar2;
  if (lVar3 == 0) {
    iVar2 = jbd2_journal_init_revoke_table_cache();
    lVar3 = (long)iVar2;
    if (lVar3 == 0) {
      lVar3 = FUN_00132540(param_1,&local_a0);
      if (lVar3 == 0) {
        lVar3 = FUN_00131f20(local_a0);
        if (lVar3 == 0) {
          iVar2 = jbd2_journal_init_revoke(local_a0,0x400);
          lVar3 = (long)iVar2;
          if (lVar3 == 0) {
            iVar2 = jbd2_journal_recover(local_a0);
            if (iVar2 == 0) {
              if (*(int *)(local_a0 + 0xc0) != 0) {
                local_90 = *(int *)(local_a0 + 0xc0);
                fix_problem(param_1,0x3a,local_98);
                uVar1 = *(undefined8 *)(local_a0 + 0x10);
                *(undefined4 *)(*(long *)(local_a0 + 0x18) + 0x20) = 0xffffffea;
                mark_buffer_dirty(uVar1);
              }
              *(undefined4 *)(local_a0 + 0x90) = *(undefined4 *)(local_a0 + 0x94);
            }
            else {
              lVar3 = (long)-iVar2;
            }
          }
        }
        jbd2_journal_destroy_revoke(local_a0);
        jbd2_journal_destroy_revoke_record_cache();
        jbd2_journal_destroy_revoke_table_cache();
        FUN_00132d40(param_1,local_a0,1,0);
      }
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: buffer_uptodate @ 0x32f70

byte buffer_uptodate(long param_1)

{
  return *(byte *)(param_1 + 0x18) >> 1 & 1;
}



// Function: mark_buffer_uptodate @ 0x32f80

void mark_buffer_uptodate(long param_1,byte param_2)

{
  *(byte *)(param_1 + 0x18) = *(byte *)(param_1 + 0x18) & 0xfd | (param_2 & 1) * '\x02';
  return;
}



// Function: wait_on_buffer @ 0x32fa0

void wait_on_buffer(long param_1)

{
  long local_10 [2];
  
  if ((*(byte *)(param_1 + 0x18) & 2) != 0) {
    return;
  }
  local_10[0] = param_1;
  ll_rw_block(0,0,1,local_10);
  return;
}



// Function: e2fsck_check_ext3_journal @ 0x32fe0

long e2fsck_check_ext3_journal(long *param_1)

{
  ushort *puVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int extraout_EDX;
  int extraout_EDX_00;
  uint uVar6;
  long lVar7;
  undefined4 uVar8;
  long in_FS_OFFSET;
  bool bVar9;
  long local_b0;
  undefined1 local_a8 [80];
  ulong local_58;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = *(long *)(*param_1 + 0x20);
  FUN_00130f60(*(undefined4 *)(lVar2 + 0x60));
  iVar3 = FUN_00130f90(*(undefined4 *)(lVar2 + 0x5c));
  if ((iVar3 == 0 && extraout_EDX == 0) && (*(long *)(lVar2 + 0xe0) == 0)) {
    lVar5 = 0;
    iVar3 = uuid_is_null(lVar2 + 0xd0);
    if (iVar3 != 0) goto LAB_00133078;
  }
  clear_problem_context(local_a8);
  local_58 = (ulong)*(uint *)(lVar2 + 0xe0);
  lVar5 = FUN_00132540(param_1,&local_b0);
  if (lVar5 != 0) {
    if ((lVar5 - 0x7f2bb729U < 0x30) && ((0x900000000003U >> (lVar5 - 0x7f2bb729U & 0x3f) & 1) != 0)
       ) {
      lVar5 = FUN_00130fa0(param_1,local_a8);
    }
    goto LAB_00133078;
  }
  lVar5 = FUN_00131f20(local_b0);
  if (lVar5 == 0) {
    do {
      FUN_00130f90(*(undefined4 *)(lVar2 + 0x5c));
      iVar3 = FUN_00130f60(*(undefined4 *)(lVar2 + 0x60));
      if (extraout_EDX_00 != 0) goto LAB_00133162;
      iVar4 = fix_problem(param_1,0x16,local_a8);
      if (iVar4 == 0) {
        if ((*(byte *)((long)param_1 + 0x4c) & 1) == 0) {
          FUN_00130180(lVar2);
          *(uint *)(*param_1 + 0x10) = *(uint *)(*param_1 + 0x10) & 0xfffffdff;
          ext2fs_mark_super_dirty();
        }
        goto LAB_001331ea;
      }
      if (iVar3 == 0) {
        if (*(int *)(lVar2 + 0x4c) == 0) {
          uVar6 = 0xb;
        }
        else {
          uVar6 = *(uint *)(lVar2 + 0x54);
        }
        bVar9 = *(uint *)(lVar2 + 0xe0) < uVar6;
        goto LAB_001332e5;
      }
      iVar3 = fix_problem(param_1,0x17,local_a8);
    } while (iVar3 == 0);
    bVar9 = true;
LAB_001332e5:
    *(undefined8 *)(lVar2 + 0xe0) = 0;
    *(undefined1 (*) [16])(lVar2 + 0xd0) = (undefined1  [16])0x0;
    FUN_00130c30(*param_1,bVar9);
LAB_001331ea:
    iVar3 = FUN_00130f90(*(undefined4 *)(lVar2 + 0x5c));
    if (iVar3 == 0) {
LAB_001331fa:
      uVar8 = 0;
LAB_001331fd:
      iVar3 = FUN_00130f60(*(undefined4 *)(lVar2 + 0x60));
      if (iVar3 == 0) {
        lVar7 = *(long *)(local_b0 + 0x18);
LAB_00133211:
        if (*(int *)(lVar7 + 0x20) != 0) {
          puVar1 = (ushort *)(*(long *)(*param_1 + 0x20) + 0x3a);
          *puVar1 = *puVar1 | 2;
          ext2fs_mark_super_dirty();
          *(undefined4 *)(lVar7 + 0x20) = 0;
          FUN_00131570(local_b0);
          mark_buffer_dirty(*(undefined8 *)(local_b0 + 0x10));
        }
      }
    }
    else {
LAB_00133162:
      iVar3 = FUN_00130f60();
      if (iVar3 == 0) {
        lVar7 = *(long *)(local_b0 + 0x18);
        uVar8 = 0;
        if (*(int *)(lVar7 + 0x1c) != 0) {
          fix_problem(param_1,0x18,local_a8);
          iVar3 = fix_problem(param_1,0x2c - (uint)(param_1[0xc] == 0),local_a8);
          if (iVar3 == 0) {
            iVar3 = fix_problem(param_1,0x19,local_a8);
            if (iVar3 == 0) goto LAB_001331fa;
            *(ushort *)(lVar2 + 0x3a) = *(ushort *)(lVar2 + 0x3a) & 0xfffe;
            uVar8 = 1;
            ext2fs_mark_super_dirty(*param_1);
          }
          else {
            *(uint *)((long)param_1 + 0x4c) = *(uint *)((long)param_1 + 0x4c) | 0x100;
            FUN_001301b0(lVar2);
            ext2fs_mark_super_dirty(*param_1);
          }
          goto LAB_001331fd;
        }
        goto LAB_00133211;
      }
      uVar8 = 0;
    }
    FUN_00132d40(param_1,local_b0,uVar8,0);
    goto LAB_00133078;
  }
  if (lVar5 == 0x7f2bb7b0) {
LAB_00133350:
    lVar5 = FUN_00132450(param_1,local_b0,local_a8);
  }
  else if (lVar5 == 0x7f2bb743) {
    iVar3 = fix_problem(param_1,0x26,local_a8);
joined_r0x00133378:
    if (iVar3 == 0) goto LAB_00133350;
  }
  else {
    if (lVar5 == 0x7f2bb744) {
      iVar3 = fix_problem(param_1,0x25,local_a8);
      goto joined_r0x00133378;
    }
    if (lVar5 == 0x7f2bb756) {
      iVar3 = fix_problem(param_1,0x27,local_a8);
      goto joined_r0x00133378;
    }
  }
  FUN_00132d40(param_1,local_b0,0,1);
LAB_00133078:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_run_ext3_journal @ 0x333d0

long e2fsck_run_ext3_journal(long *param_1)

{
  long *plVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  long in_FS_OFFSET;
  long local_38;
  long local_30;
  
  lVar8 = param_1[3];
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_38 = 0;
  uVar2 = *(undefined4 *)(*param_1 + 0x28);
  uVar9 = *(undefined8 *)(*(long *)(*param_1 + 8) + 8);
  uVar6 = dcgettext(0,"%s: recovering journal\n",5);
  __printf_chk(1,uVar6,lVar8);
  if ((*(byte *)((long)param_1 + 0x4c) & 1) == 0) {
    if ((*(byte *)(*param_1 + 0x10) & 4) != 0) {
      ext2fs_flush();
    }
    lVar7 = FUN_00132e30(param_1);
    lVar8 = *param_1;
    if (*(long *)(*(long *)(lVar8 + 0x20) + 0x178) != 0) {
      pcVar5 = *(code **)(*(long *)(*(long *)(lVar8 + 8) + 8) + 0x50);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(*(long *)(lVar8 + 8),&local_38);
        lVar8 = *param_1;
      }
    }
    uVar10 = 0;
    if (local_38 != 0) {
      uVar10 = *(ulong *)(local_38 + 0x10) >> 10;
    }
    ext2fs_mmp_stop(lVar8);
    ext2fs_free(*param_1);
    lVar8 = ext2fs_open(param_1[2],(int)param_1[0x10],(int)param_1[0xc],uVar2,uVar9,param_1);
    if (lVar8 != 0) {
      lVar7 = param_1[3];
      uVar9 = dcgettext(0,"while trying to re-open %s",5);
      com_err(param_1[1],lVar8,uVar9,lVar7);
                    /* WARNING: Subroutine does not return */
      fatal_error(param_1,0);
    }
    lVar8 = *param_1;
    lVar3 = param_1[0x69];
    *(uint *)(lVar8 + 0x10) = *(uint *)(lVar8 + 0x10) | 0x200;
    *(long **)(lVar8 + 0xe0) = param_1;
    lVar4 = *param_1;
    *(long *)(lVar8 + 0xb8) = lVar3;
    plVar1 = (long *)(*(long *)(lVar8 + 0x20) + 0x178);
    *plVar1 = *plVar1 + uVar10;
    FUN_00130c30(lVar4,lVar7 != 0);
    lVar8 = e2fsck_check_ext3_journal(param_1);
    if (lVar8 == 0) {
      lVar8 = lVar7;
    }
  }
  else {
    lVar8 = param_1[3];
    uVar9 = dcgettext(0,"%s: won\'t do journal recovery while read-only\n",5);
    __printf_chk(1,uVar9,lVar8);
    lVar8 = 0x7f2bb74d;
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_move_ext3_journal @ 0x335e0

void e2fsck_move_ext3_journal(long *param_1)

{
  int *piVar1;
  ushort *puVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  size_t sVar8;
  char *__s;
  undefined **ppuVar9;
  long in_FS_OFFSET;
  int local_140;
  byte local_13c [4];
  long local_138 [12];
  undefined *local_d8;
  undefined1 local_c8 [4];
  undefined4 local_c4;
  undefined4 local_b4;
  short local_ae;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_5c;
  long local_40;
  
  lVar3 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar4 = *(long *)(lVar3 + 0x20);
  clear_problem_context(local_138);
  if ((((*(byte *)((long)param_1 + 0x4c) & 1) == 0) && (*(int *)(lVar4 + 0xe0) != 0)) &&
     (iVar5 = FUN_00130f90(*(undefined4 *)(lVar4 + 0x5c)), iVar5 != 0)) {
    lVar7 = ext2fs_read_inode(lVar3);
    if (lVar7 == 0) {
      if (((*(char *)(lVar4 + 0xfd) == '\0') ||
          ((*(char *)(lVar4 + 0xfd) == '\x01' &&
           (iVar5 = memcmp(&local_a0,(void *)(lVar4 + 0x10c),0x3c), iVar5 != 0)))) &&
         (iVar5 = fix_problem(param_1,0x2d,local_138), iVar5 != 0)) {
        *(undefined1 *)(lVar4 + 0xfd) = 1;
        *(undefined8 *)(lVar4 + 0x13c) = local_70;
        *(undefined4 *)(lVar4 + 0x148) = local_5c;
        *(undefined8 *)(lVar4 + 0x10c) = local_a0;
        *(undefined8 *)(lVar4 + 0x114) = uStack_98;
        *(undefined4 *)(lVar4 + 0x144) = local_68;
        *(undefined4 *)(lVar4 + 0x14c) = local_c4;
        *(undefined8 *)(lVar4 + 0x11c) = local_90;
        *(undefined8 *)(lVar4 + 0x124) = uStack_88;
        *(undefined8 *)(lVar4 + 300) = local_80;
        *(undefined8 *)(lVar4 + 0x134) = uStack_78;
        ext2fs_mark_super_dirty(lVar3);
        *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) & 0xfffffdff;
      }
      if (((*(int *)(lVar4 + 0xe0) != 8) && (local_ae == 1)) &&
         ((lVar7 = ext2fs_check_if_mounted(param_1[2],local_13c), lVar7 == 0 &&
          ((local_13c[0] & 1) == 0)))) {
        ppuVar9 = &PTR_s__journal_00187033_1_001b0cc0;
        __s = ".journal";
        do {
          sVar8 = strlen(__s);
          lVar7 = ext2fs_lookup(lVar3,2,__s,sVar8 & 0xffffffff,0,&local_140);
          if ((lVar7 == 0) && (*(int *)(lVar4 + 0xe0) == local_140)) {
            if ((*ppuVar9 == (undefined *)0x0) || (lVar7 = ext2fs_read_bitmaps(lVar3), lVar7 != 0))
            break;
            local_d8 = *ppuVar9;
            iVar5 = fix_problem(param_1,0x28,local_138);
            if (iVar5 == 0) break;
            lVar7 = ext2fs_unlink(lVar3,2,*ppuVar9,local_140,0);
            if ((lVar7 == 0) && (lVar7 = ext2fs_write_inode(lVar3,8,local_c8), lVar7 == 0)) {
              *(undefined4 *)(lVar4 + 0xe0) = 8;
              ext2fs_mark_super_dirty(lVar3);
              *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) & 0xfffffdff;
              local_ae = 0;
              local_b4 = (undefined4)param_1[0x69];
              lVar7 = ext2fs_write_inode(lVar3,local_140,local_c8);
              if (lVar7 == 0) {
                uVar6 = ext2fs_group_of_ino(lVar3,local_140);
                ext2fs_unmark_inode_bitmap2(*(undefined8 *)(lVar3 + 0x50),local_140);
                ext2fs_mark_ib_dirty(lVar3);
                iVar5 = ext2fs_bg_free_inodes_count(lVar3,uVar6);
                ext2fs_bg_free_inodes_count_set(lVar3,uVar6,iVar5 + 1);
                ext2fs_group_desc_csum_set(lVar3,uVar6);
                piVar1 = (int *)(*(long *)(lVar3 + 0x20) + 0x10);
                *piVar1 = *piVar1 + 1;
                break;
              }
            }
            local_138[0] = lVar7;
            fix_problem(param_1,0x29,local_138);
            puVar2 = (ushort *)(*(long *)(lVar3 + 0x20) + 0x3a);
            *puVar2 = *puVar2 & 0xfffe;
            ext2fs_mark_super_dirty(lVar3);
            break;
          }
          __s = ppuVar9[1];
          ppuVar9 = ppuVar9 + 1;
        } while (__s != (char *)0x0);
      }
    }
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: e2fsck_fix_ext3_journal_hint @ 0x33940

undefined8 e2fsck_fix_ext3_journal_hint(long *param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  char *__file;
  long in_FS_OFFSET;
  undefined1 auStack_158 [80];
  ulong local_108;
  stat local_e8;
  undefined1 local_58 [40];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = *(long *)(*param_1 + 0x20);
  iVar3 = FUN_00130f90(*(undefined4 *)(lVar1 + 0x5c));
  if (iVar3 != 0) {
    iVar3 = uuid_is_null(lVar1 + 0xd0);
    if (iVar3 == 0) {
      uuid_unparse(lVar1 + 0xd0,local_58);
      __file = (char *)blkid_get_devname(param_1[0x11],&DAT_00179a89,local_58);
      if (__file != (char *)0x0) {
        iVar3 = stat(__file,&local_e8);
        if ((-1 < iVar3) && (local_e8.st_rdev != *(uint *)(lVar1 + 0xe4))) {
          clear_problem_context(auStack_158);
          local_108 = local_e8.st_rdev;
          iVar3 = fix_problem(param_1,0x33,auStack_158);
          if (iVar3 != 0) {
            lVar2 = *param_1;
            *(int *)(lVar1 + 0xe4) = (int)local_e8.st_rdev;
            ext2fs_mark_super_dirty(lVar2);
          }
        }
        free(__file);
      }
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: invalid_block @ 0x33a60

void invalid_block(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = dcgettext(0,"Bad block %u out of range; ignored.\n",5);
  __printf_chk(1,uVar1,param_2);
  return;
}



// Function: check_bb_inode_blocks @ 0x33a90

undefined8 check_bb_inode_blocks(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  uVar1 = *param_2;
  if (uVar1 != 0) {
    uVar3 = ext2fs_blocks_count(*(undefined8 *)(param_1 + 0x20));
    uVar2 = *param_2;
    if ((uVar3 <= uVar1) || (uVar2 < *(uint *)(*(long *)(param_1 + 0x20) + 0x14))) {
      uVar4 = dcgettext(0,"Warning: illegal block %u found in bad block inode.  Cleared.\n",5);
      __printf_chk(1,uVar4,uVar2);
      *param_2 = 0;
      return 1;
    }
  }
  return 0;
}



// Function: read_bad_blocks_file @ 0x33b10

void read_bad_blocks_file(long *param_1,char *param_2,int param_3)

{
  long lVar1;
  FILE *pFVar2;
  long lVar3;
  undefined8 uVar4;
  int *piVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined *puVar8;
  long in_FS_OFFSET;
  long local_440;
  char local_438 [1032];
  long local_30;
  
  lVar3 = *param_1;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_440 = 0;
  e2fsck_read_bitmaps();
  lVar1 = ext2fs_block_iterate(lVar3,1,0,0,FUN_00133a90,0);
  if (lVar1 == 0) {
    if (param_3 == 0) {
      lVar1 = ext2fs_read_bb_inode(lVar3,&local_440);
      if (lVar1 != 0) {
        uVar4 = dcgettext(0,"while reading the bad blocks inode",5);
        com_err("ext2fs_read_bb_inode",lVar1,&DAT_00178907,uVar4);
        goto LAB_00133c5e;
      }
    }
    if (param_2 == (char *)0x0) {
      param_2 = local_438;
      lVar1 = ext2fs_blocks_count(*(undefined8 *)(lVar3 + 0x20));
      puVar8 = &DAT_001782b4;
      puVar6 = &DAT_00179c1f;
      if ((*(uint *)((long)param_1 + 0x4c) & 0x200) == 0) {
        puVar6 = &DAT_001782b4;
      }
      if ((*(uint *)((long)param_1 + 0x4c) & 2) == 0) {
        puVar8 = &DAT_00179c23;
      }
      __sprintf_chk(param_2,1,0x400,"badblocks -b %d -X %s%s%s %llu",*(undefined4 *)(lVar3 + 0x28),
                    puVar8,puVar6,*(undefined8 *)(lVar3 + 0x18),lVar1 + -1);
      pFVar2 = popen(param_2,"r");
      if (pFVar2 == (FILE *)0x0) {
        pcVar7 = "while trying popen \'%s\'";
        goto LAB_00133df4;
      }
      lVar1 = ext2fs_read_bb_FILE(lVar3,pFVar2,&local_440,FUN_00133a60);
      pclose(pFVar2);
    }
    else {
      pFVar2 = fopen(param_2,"r");
      if (pFVar2 == (FILE *)0x0) {
        pcVar7 = "while trying to open %s";
LAB_00133df4:
        uVar4 = dcgettext(0,pcVar7,5);
        piVar5 = __errno_location();
        com_err("read_bad_blocks_file",(long)*piVar5,uVar4,param_2);
        goto LAB_00133c5e;
      }
      lVar1 = ext2fs_read_bb_FILE(lVar3,pFVar2,&local_440,FUN_00133a60);
      fclose(pFVar2);
    }
    if (lVar1 == 0) {
      __printf_chk(1,"%s: Updating bad block inode.\n",param_1[3]);
      lVar3 = ext2fs_update_bb_inode(lVar3,local_440);
      if (lVar3 == 0) {
        ext2fs_badblocks_list_free(local_440);
        goto LAB_00133c02;
      }
      uVar4 = dcgettext(0,"while updating bad block inode",5);
      com_err("ext2fs_update_bb_inode",lVar3,&DAT_00178907,uVar4);
    }
    else {
      uVar4 = dcgettext(0,"while reading in list of bad blocks from file",5);
      com_err("ext2fs_read_bb_FILE",lVar1,&DAT_00178907,uVar4);
    }
  }
  else {
    uVar4 = dcgettext(0,"while sanity checking the bad blocks inode",5);
    com_err("ext2fs_block_iterate",lVar1,&DAT_00178907,uVar4);
  }
LAB_00133c5e:
  *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
  if (local_440 != 0) {
    ext2fs_badblocks_list_free();
  }
LAB_00133c02:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: read_a_char @ 0x33e30

int read_a_char(void)

{
  int iVar1;
  ssize_t sVar2;
  long in_FS_OFFSET;
  char local_21;
  long local_20;
  
  iVar1 = 0x66;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  do {
    if ((e2fsck_global_ctx != 0) && ((*(byte *)(e2fsck_global_ctx + 0x48) & 2) != 0)) {
      iVar1 = 3;
      goto LAB_00133e88;
    }
    sVar2 = read(0,&local_21,1);
    if ((int)sVar2 == 1) {
      iVar1 = (int)local_21;
      goto LAB_00133e88;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = -1;
LAB_00133e88:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: log_out @ 0x33ef0

void log_out(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,long param_9
            ,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,
            undefined8 param_14)

{
  char in_AL;
  long in_FS_OFFSET;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 *local_e0;
  undefined1 *local_d8;
  long local_d0;
  undefined1 local_c8 [16];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_28;
  
  if (in_AL != '\0') {
    local_98 = param_1;
    local_88 = param_2;
    local_78 = param_3;
    local_68 = param_4;
    local_58 = param_5;
    local_48 = param_6;
    local_38 = param_7;
    local_28 = param_8;
  }
  local_d0 = *(long *)(in_FS_OFFSET + 0x28);
  local_e0 = &stack0x00000008;
  local_d8 = local_c8;
  local_e8 = 0x10;
  local_e4 = 0x30;
  local_b8 = param_11;
  local_b0 = param_12;
  local_a8 = param_13;
  local_a0 = param_14;
  __vprintf_chk(1,param_10,&local_e8);
  if (*(long *)(param_9 + 0x28) != 0) {
    local_e0 = &stack0x00000008;
    local_e8 = 0x10;
    local_d8 = local_c8;
    local_e4 = 0x30;
    __vfprintf_chk(*(undefined8 *)(param_9 + 0x28),1,param_10,&local_e8);
  }
  if (local_d0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: log_err @ 0x34010

void log_err(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,long param_9
            ,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,
            undefined8 param_14)

{
  char in_AL;
  long in_FS_OFFSET;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 *local_e0;
  undefined1 *local_d8;
  long local_d0;
  undefined1 local_c8 [16];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_28;
  
  if (in_AL != '\0') {
    local_98 = param_1;
    local_88 = param_2;
    local_78 = param_3;
    local_68 = param_4;
    local_58 = param_5;
    local_48 = param_6;
    local_38 = param_7;
    local_28 = param_8;
  }
  local_d0 = *(long *)(in_FS_OFFSET + 0x28);
  local_e0 = &stack0x00000008;
  local_e8 = 0x10;
  local_d8 = local_c8;
  local_e4 = 0x30;
  local_b8 = param_11;
  local_b0 = param_12;
  local_a8 = param_13;
  local_a0 = param_14;
  __vfprintf_chk(stderr,1,param_10,&local_e8);
  if (*(long *)(param_9 + 0x28) != 0) {
    local_e0 = &stack0x00000008;
    local_e8 = 0x10;
    local_d8 = local_c8;
    local_e4 = 0x30;
    __vfprintf_chk(*(undefined8 *)(param_9 + 0x28),1,param_10,&local_e8);
  }
  if (local_d0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: fatal_error @ 0x34130

void fatal_error(long *param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  uint __status;
  
  lVar2 = *param_1;
  if (param_2 != 0) {
    __fprintf_chk(stderr,1,"e2fsck: %s\n",param_2);
  }
  if (lVar2 == 0) {
    __status = 8;
  }
  else {
    if ((*(long *)(lVar2 + 8) != 0) && (*(long *)(lVar2 + 0x20) != 0)) {
      ext2fs_mmp_stop(*param_1);
      if (**(long **)(*param_1 + 8) == 0x7f2bb705) {
        (**(code **)((*(long **)(*param_1 + 8))[1] + 0x38))();
      }
      else {
        log_err(param_1,"e2fsck: io manager magic bad!\n");
      }
    }
    __status = 8;
    iVar4 = ext2fs_test_changed(lVar2);
    if (iVar4 != 0) {
      lVar3 = param_1[3];
      uVar5 = dcgettext(0,"\n%s: ***** FILE SYSTEM WAS MODIFIED *****\n",5);
      log_out(param_1,uVar5,lVar3);
      __status = (-(uint)((*(uint *)((long)param_1 + 0x7c) & 2) == 0) & 0xfffffffe) + 0xb;
    }
    iVar4 = ext2fs_test_valid(lVar2);
    if (iVar4 == 0) {
      lVar2 = param_1[3];
      __status = __status & 0xfffffffe | 4;
      uVar5 = dcgettext(0,"\n%s: ********** WARNING: Filesystem still has errors **********\n\n",5);
      log_out(param_1,uVar5,lVar2);
    }
  }
  uVar1 = *(uint *)(param_1 + 9);
  *(uint *)(param_1 + 9) = uVar1 | 1;
  if ((uVar1 & 0x10) == 0) {
    if (param_1[5] != 0) {
      __fprintf_chk(param_1[5],1,"Exit status: %d\n",__status);
    }
                    /* WARNING: Subroutine does not return */
    exit(__status);
  }
                    /* WARNING: Subroutine does not return */
  __longjmp_chk(param_1 + 0x12,1);
}



// Function: e2fsck_allocate_memory @ 0x342a0

undefined8 e2fsck_allocate_memory(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined8 local_140;
  undefined1 local_138 [264];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = ext2fs_get_memzero(param_2,&local_140);
  if (lVar1 != 0) {
    __sprintf_chk(local_138,1,0x100,"Can\'t allocate %lu bytes for %s\n",param_2,param_3);
                    /* WARNING: Subroutine does not return */
    fatal_error(param_1,local_138);
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_140;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: string_copy @ 0x34340

char * string_copy(undefined8 param_1,char *param_2,size_t param_3)

{
  char *__dest;
  char *pcVar1;
  
  if (param_2 != (char *)0x0) {
    if (param_3 == 0) {
      param_3 = strlen(param_2);
    }
    __dest = malloc(param_3 + 1);
    pcVar1 = (char *)0x0;
    if (__dest != (char *)0x0) {
      pcVar1 = strncpy(__dest,param_2,param_3);
      pcVar1[param_3] = '\0';
    }
    return pcVar1;
  }
  return (char *)0x0;
}



// Function: ask_yn @ 0x343b0

int ask_yn(long param_1,undefined8 param_2,int param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  int iVar4;
  uint uVar5;
  char *__s;
  char *__s_00;
  char *__s_01;
  undefined *puVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined *puVar9;
  long in_FS_OFFSET;
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined8 local_98;
  speed_t local_90;
  termios local_88;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  __s = (char *)dcgettext(0,&DAT_00179ca0,5);
  __s_00 = (char *)dcgettext(0,&DAT_00179ca3,5);
  __s_01 = (char *)dcgettext(0,&DAT_00179ca6,5);
  puVar6 = (undefined *)dcgettext(0," (\'a\' enables \'yes\' to all) ",5);
  iVar4 = tcgetattr(0,(termios *)local_c8);
  if (iVar4 < 0) {
    local_90 = 0;
    local_98._0_1_ = '\0';
    local_98._1_3_ = 0;
    local_98._4_4_ = 0;
    local_c8 = (undefined1  [16])0x0;
    local_b8 = (undefined1  [16])0x0;
    local_a8 = (undefined1  [16])0x0;
  }
  auVar3 = local_a8;
  auVar2 = local_b8;
  auVar1 = local_c8;
  local_88.c_cc[0x1f] = (cc_t)local_98;
  local_88._49_3_ = local_98._1_3_;
  local_88.c_ispeed = local_98._4_4_;
  local_88.c_iflag = local_c8._0_4_;
  local_88.c_oflag = local_c8._4_4_;
  local_88.c_cc[7] = local_b8[8];
  local_88.c_cc[8] = local_b8[9];
  local_88.c_cc[9] = local_b8[10];
  local_88.c_cc[10] = local_b8[0xb];
  local_88.c_cc[0xb] = local_b8[0xc];
  local_88.c_cc[0xc] = local_b8[0xd];
  local_88.c_cc[0xd] = local_b8[0xe];
  local_88.c_cc[0xe] = local_b8[0xf];
  local_88._8_8_ = local_c8._8_8_ & 0xfffffff5ffffffff;
  local_88.c_ospeed = local_90;
  local_88._16_6_ = auVar2._0_6_;
  local_88.c_cc[5] = '\0';
  local_88.c_cc[6] = '\x01';
  local_88.c_cc[0xf] = local_a8[0];
  local_88.c_cc[0x10] = local_a8[1];
  local_88.c_cc[0x11] = local_a8[2];
  local_88.c_cc[0x12] = local_a8[3];
  local_88.c_cc[0x13] = local_a8[4];
  local_88.c_cc[0x14] = local_a8[5];
  local_88.c_cc[0x15] = local_a8[6];
  local_88.c_cc[0x16] = local_a8[7];
  local_88.c_cc[0x17] = local_a8[8];
  local_88.c_cc[0x18] = local_a8[9];
  local_88.c_cc[0x19] = local_a8[10];
  local_88.c_cc[0x1a] = local_a8[0xb];
  local_88.c_cc[0x1b] = local_a8[0xc];
  local_88.c_cc[0x1c] = local_a8[0xd];
  local_88.c_cc[0x1d] = local_a8[0xe];
  local_88.c_cc[0x1e] = local_a8[0xf];
  local_c8 = auVar1;
  local_b8 = auVar2;
  local_a8 = auVar3;
  tcsetattr(0,0,&local_88);
  puVar9 = &DAT_00179cc6;
  if (param_3 != 1) {
    if (param_3 != 0) {
      uVar7 = dcgettext(0," (y/n)",5);
      goto LAB_0013451f;
    }
    puVar9 = &DAT_00179cca;
  }
  uVar7 = dcgettext(0,puVar9,5);
  uVar7 = dcgettext(0,uVar7,5);
LAB_0013451f:
  if (DAT_001b7350 < 0xd) {
    if (DAT_001b7350 < 9) {
      puVar6 = &DAT_001782b4;
    }
  }
  else {
    DAT_001b7350 = -1;
    puVar6 = &DAT_001782b4;
  }
  log_out(param_1,"%s%s%s? ",param_2,puVar6,uVar7);
  do {
    fflush(stdout);
    uVar5 = FUN_00133e30();
    if (uVar5 == 0xffffffff) goto LAB_0013462e;
    if (uVar5 == 3) {
      tcsetattr(0,0,(termios *)local_c8);
      if ((*(uint *)(param_1 + 0x48) & 0x10) != 0) {
        log_out(param_1,"\n");
                    /* WARNING: Subroutine does not return */
        __longjmp_chk(e2fsck_global_ctx + 0x90,1);
      }
      uVar7 = dcgettext(0,"cancelled!\n",5);
      log_out(param_1,&DAT_00178907,uVar7);
      DAT_001b7350 = 0;
      param_3 = 0;
      goto LAB_00134687;
    }
    iVar4 = (int)(char)uVar5;
    pcVar8 = strchr(__s,iVar4);
    if (pcVar8 != (char *)0x0) {
LAB_00134720:
      param_3 = 1;
      if (-1 < DAT_001b7350) {
        DAT_001b7350 = DAT_001b7350 + 1;
      }
      goto LAB_00134650;
    }
    pcVar8 = strchr(__s_00,iVar4);
    if (pcVar8 != (char *)0x0) {
LAB_00134748:
      DAT_001b7350 = -1;
      goto LAB_00134752;
    }
    pcVar8 = strchr(__s_01,iVar4);
    if (pcVar8 != (char *)0x0) {
LAB_00134788:
      DAT_001b7350 = -1;
      *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 4;
      goto LAB_0013479b;
    }
    pcVar8 = strchr("yY",iVar4);
    if (pcVar8 != (char *)0x0) goto LAB_00134720;
    pcVar8 = strchr("nN",iVar4);
    if (pcVar8 != (char *)0x0) goto LAB_00134748;
    pcVar8 = strchr("aA",iVar4);
    if (pcVar8 != (char *)0x0) goto LAB_00134788;
  } while (((0x20 < uVar5) || ((0x108000400U >> ((ulong)uVar5 & 0x3f) & 1) == 0)) || (param_3 == -1)
          );
  DAT_001b7350 = -1;
LAB_0013462e:
  if (param_3 == 2) {
LAB_0013479b:
    param_3 = 2;
    uVar7 = dcgettext(0,"yes to all\n",5);
    log_out(param_1,&DAT_00178907,uVar7);
  }
  else if (param_3 == 0) {
LAB_00134752:
    param_3 = 0;
    uVar7 = dcgettext(0,&DAT_00179cfb,5);
    log_out(param_1,&DAT_00178907,uVar7);
  }
  else {
LAB_00134650:
    uVar7 = dcgettext(0,&DAT_00179cf6,5);
    log_out(param_1,&DAT_00178907,uVar7);
  }
  tcsetattr(0,0,(termios *)local_c8);
LAB_00134687:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



// Function: ask @ 0x34860

ulong ask(long param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x4c);
  if ((uVar1 & 8) != 0) {
    uVar2 = dcgettext(0,"%s? no\n\n",5);
    log_out(param_1,uVar2,param_2);
    return 0;
  }
  if ((uVar1 & 4) == 0) {
    if ((uVar1 & 2) != 0) {
      if (param_3 == 0) {
        uVar2 = dcgettext(0,"no",5);
      }
      else {
        uVar2 = dcgettext(0,&DAT_00179d12,5);
      }
      log_out(param_1,"%s? %s\n\n",param_2,uVar2);
      return (ulong)param_3;
    }
    uVar3 = ask_yn();
    return uVar3;
  }
  uVar2 = dcgettext(0,"%s? yes\n\n",5);
  log_out(param_1,uVar2,param_2);
  return 1;
}



// Function: e2fsck_write_bitmaps @ 0x34950

void e2fsck_write_bitmaps(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar1 = *param_1;
  uVar2 = dcgettext(0,"writing block and inode bitmaps",5);
  uVar2 = ehandler_operation(uVar2);
  lVar3 = ext2fs_write_bitmaps(uVar1);
  ehandler_operation(uVar2);
  if (lVar3 == 0) {
    return;
  }
  uVar1 = param_1[3];
  uVar2 = dcgettext(0,"while rewriting block and inode bitmaps for %s",5);
  com_err(param_1[1],lVar3,uVar2,uVar1);
                    /* WARNING: Subroutine does not return */
  fatal_error(param_1,0);
}



// Function: preenhalt @ 0x349d0

void preenhalt(long *param_1)

{
  ushort *puVar1;
  long lVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  long local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = *param_1;
  if ((*(byte *)((long)param_1 + 0x4c) & 2) != 0) {
    lVar2 = param_1[3];
    uVar3 = dcgettext(0,
                      "\n\n%s: UNEXPECTED INCONSISTENCY; RUN fsck MANUALLY.\n\t(i.e., without -a or -p options)\n"
                      ,5);
    log_err(param_1,uVar3,lVar2);
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 0x1000;
    if (local_28 != 0) {
      puVar1 = (ushort *)(*(long *)(local_28 + 0x20) + 0x3a);
      *puVar1 = *puVar1 | 2;
      ext2fs_mark_super_dirty();
      ext2fs_close_free(&local_28);
    }
                    /* WARNING: Subroutine does not return */
    exit(4);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: init_resource_track @ 0x34a70

void init_resource_track(timeval *param_1,long param_2)

{
  code *pcVar1;
  __time_t _Var2;
  void *pvVar3;
  long in_FS_OFFSET;
  long local_c0;
  rusage local_b8;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_c0 = 0;
  pvVar3 = sbrk(0);
  param_1[3].tv_sec = (__time_t)pvVar3;
  gettimeofday(param_1,(__timezone_ptr_t)0x0);
  getrusage(RUSAGE_SELF,&local_b8);
  param_1[3].tv_usec = 0;
  param_1[4].tv_sec = 0;
  param_1[1].tv_sec = local_b8.ru_utime.tv_sec;
  param_1[1].tv_usec = local_b8.ru_utime.tv_usec;
  param_1[2].tv_sec = local_b8.ru_stime.tv_sec;
  param_1[2].tv_usec = local_b8.ru_stime.tv_usec;
  if (((param_2 != 0) && (*(long *)(param_2 + 8) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(param_2 + 8) + 0x50), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_2,&local_c0);
  }
  if (local_c0 != 0) {
    _Var2 = *(__time_t *)(local_c0 + 0x10);
    param_1[3].tv_usec = *(__suseconds_t *)(local_c0 + 8);
    param_1[4].tv_sec = _Var2;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: print_resource_track @ 0x34b50

void print_resource_track(long param_1,long param_2,undefined8 *param_3,long param_4)

{
  void *pvVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  long in_FS_OFFSET;
  float fVar9;
  float fVar10;
  float fVar11;
  double dVar12;
  long local_f0;
  timeval local_e8;
  rusage local_d8;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0) {
    if ((*(uint *)(param_1 + 0x4c) & 0x10) == 0) goto LAB_00134de0;
    e2fsck_clear_progbar();
    gettimeofday(&local_e8,(__timezone_ptr_t)0x0);
  }
  else {
    if ((*(uint *)(param_1 + 0x4c) & 0x20) == 0) goto LAB_00134de0;
    e2fsck_clear_progbar();
    gettimeofday(&local_e8,(__timezone_ptr_t)0x0);
    log_out(param_1,&DAT_001783f4,param_2);
  }
  pvVar1 = sbrk(0);
  if ((long)pvVar1 - param_3[6] < 0x80000000) {
    mallinfo(&local_d8);
    lVar4 = (long)local_d8.ru_stime.tv_usec._4_4_;
    lVar8 = (long)(int)local_d8.ru_stime.tv_sec;
    lVar7 = (long)(int)local_d8.ru_utime.tv_sec;
    uVar2 = dcgettext(0,"Memory used: %lluk/%lluk (%lluk/%lluk), ",5);
    log_out(param_1,uVar2,lVar7 + 0x3ffU >> 10,lVar8 + 0x3ffU >> 10,lVar4 + 0x3ffU >> 10,
            (long)(int)local_d8.ru_maxrss + 0x3ffU >> 10);
  }
  else {
    pvVar1 = sbrk(0);
    lVar4 = param_3[6];
    uVar2 = dcgettext(0,"Memory used: %lluk, ",5);
    log_out(param_1,uVar2,(ulong)((long)pvVar1 + (0x3ff - lVar4)) >> 10);
  }
  getrusage(RUSAGE_SELF,&local_d8);
  fVar9 = (float)FUN_00133ec0(CONCAT44(local_d8.ru_stime.tv_sec._4_4_,(int)local_d8.ru_stime.tv_sec)
                              ,CONCAT44(local_d8.ru_stime.tv_usec._4_4_,
                                        (undefined4)local_d8.ru_stime.tv_usec),param_3[4],param_3[5]
                             );
  fVar10 = (float)FUN_00133ec0(CONCAT44(local_d8.ru_utime.tv_sec._4_4_,(int)local_d8.ru_utime.tv_sec
                                       ),local_d8.ru_utime.tv_usec,param_3[2],param_3[3]);
  fVar11 = (float)FUN_00133ec0(local_e8.tv_sec,local_e8.tv_usec,*param_3,param_3[1]);
  uVar2 = dcgettext(0,"time: %5.2f/%5.2f/%5.2f\n",5);
  log_out((double)fVar11,(double)fVar10,(double)fVar9,param_1,uVar2);
  if (((param_4 != 0) && (*(long *)(param_4 + 8) != 0)) &&
     (pcVar3 = *(code **)(*(long *)(param_4 + 8) + 0x50), pcVar3 != (code *)0x0)) {
    local_f0 = 0;
    if (param_2 != 0) {
      log_out(param_1,&DAT_001783f4,param_2);
      pcVar3 = *(code **)(*(long *)(param_4 + 8) + 0x50);
    }
    (*pcVar3)(param_4,&local_f0);
    if (local_f0 == 0) {
      uVar5 = 0;
      uVar6 = 0;
      dVar12 = 0.0;
    }
    else {
      lVar4 = *(long *)(local_f0 + 8) - param_3[7];
      lVar7 = *(long *)(local_f0 + 0x10) - param_3[8];
      uVar6 = lVar7 + 0xfffffU >> 0x14;
      dVar12 = (double)((ulong)(lVar4 + 0xfffff + lVar7) >> 0x14);
      uVar5 = lVar4 + 0xfffffU >> 0x14;
    }
    fVar9 = (float)FUN_00133ec0(local_e8.tv_sec,local_e8.tv_usec,*param_3,param_3[1],uVar5,uVar6);
    log_out(dVar12 / (double)fVar9,param_1,"I/O read: %lluMB, write: %lluMB, rate: %.2fMB/s\n",uVar5
            ,uVar6);
  }
LAB_00134de0:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_read_inode @ 0x34ea0

void e2fsck_read_inode(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = ext2fs_read_inode(*param_1);
  if (lVar1 == 0) {
    return;
  }
  uVar2 = dcgettext(0,"while reading inode %lu in %s",5);
  com_err("ext2fs_read_inode",lVar1,uVar2,param_2,param_4);
                    /* WARNING: Subroutine does not return */
  fatal_error(param_1,0);
}



// Function: e2fsck_read_inode_full @ 0x34f10

void e2fsck_read_inode_full
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = ext2fs_read_inode_full(*param_1);
  if (lVar1 == 0) {
    return;
  }
  uVar2 = dcgettext(0,"while reading inode %lu in %s",5);
  com_err("ext2fs_read_inode_full",lVar1,uVar2,param_2,param_5);
                    /* WARNING: Subroutine does not return */
  fatal_error(param_1,0);
}



// Function: e2fsck_write_inode_full @ 0x34f80

void e2fsck_write_inode_full
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = ext2fs_write_inode_full(*param_1);
  if (lVar1 == 0) {
    return;
  }
  uVar2 = dcgettext(0,"while writing inode %lu in %s",5);
  com_err("ext2fs_write_inode",lVar1,uVar2,param_2,param_5);
                    /* WARNING: Subroutine does not return */
  fatal_error(param_1,0);
}



// Function: e2fsck_write_inode @ 0x34ff0

void e2fsck_write_inode(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                       )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = ext2fs_write_inode(*param_1);
  if (lVar1 == 0) {
    return;
  }
  uVar2 = dcgettext(0,"while writing inode %lu in %s",5);
  com_err("ext2fs_write_inode",lVar1,uVar2,param_2,param_4);
                    /* WARNING: Subroutine does not return */
  fatal_error(param_1,0);
}



// Function: get_backup_sb @ 0x35060

ulong get_backup_sb(long param_1,long param_2,long param_3,long param_4)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  long local_40;
  long local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_40 = 0;
  local_38 = 0;
  if ((param_2 == 0) || (lVar2 = *(long *)(param_2 + 0x20), lVar2 == 0)) {
    if (param_1 != 0) {
      iVar4 = *(int *)(param_1 + 0x50);
      if (iVar4 != 0) {
        uVar5 = (ulong)(uint)(iVar4 * 8) + (ulong)(iVar4 == 0x400);
        *(ulong *)(param_1 + 0x60) = uVar5;
        goto LAB_001350bd;
      }
      *(undefined8 *)(param_1 + 0x60) = 0x2001;
      *(undefined4 *)(param_1 + 0x50) = 0x400;
    }
    if ((param_3 == 0) || (param_4 == 0)) {
      uVar5 = 0x2001;
    }
    else {
      lVar2 = (**(code **)(param_4 + 0x10))(param_3,0,&local_40);
      if ((lVar2 == 0) && (lVar3 = ext2fs_get_mem(0x400,&local_38), lVar2 = local_38, lVar3 == 0)) {
        iVar4 = 0x400;
LAB_00135188:
        do {
          uVar5 = (ulong)(iVar4 * 8);
          if (iVar4 == 0x400) {
            uVar5 = 0x2001;
            (**(code **)(*(long *)(local_40 + 8) + 0x20))(local_40,0x400);
            lVar3 = io_channel_read_blk64(local_40,0x2001,0xfffffc00,local_38);
            if (lVar3 != 0) {
              (**(code **)(*(long *)(local_40 + 8) + 0x20))(local_40,0x800);
              lVar3 = io_channel_read_blk64(local_40,0x4000,0xfffffc00,local_38);
              if (lVar3 == 0) {
                iVar4 = 0x800;
                uVar5 = 0x4000;
                goto LAB_001351c5;
              }
              iVar4 = 0x1000;
              goto LAB_00135188;
            }
            if (*(short *)(lVar2 + 0x38) != -0x10ad) {
              iVar4 = 0x800;
              goto LAB_00135188;
            }
LAB_00135260:
            if (0x400 << ((byte)*(undefined4 *)(lVar2 + 0x18) & 0x1f) == iVar4) {
              if (param_1 != 0) {
                *(ulong *)(param_1 + 0x60) = uVar5;
                *(int *)(param_1 + 0x50) = iVar4;
              }
              goto LAB_0013512e;
            }
          }
          else {
            (**(code **)(*(long *)(local_40 + 8) + 0x20))(local_40,iVar4);
            lVar3 = io_channel_read_blk64(local_40,uVar5,0xfffffc00,local_38);
            if (lVar3 == 0) {
LAB_001351c5:
              if (*(short *)(lVar2 + 0x38) == -0x10ad) goto LAB_00135260;
            }
          }
          iVar4 = iVar4 * 2;
        } while (iVar4 < 0x10001);
      }
      uVar5 = 0x2001;
LAB_0013512e:
      if (local_40 != 0) {
        (**(code **)(*(long *)(local_40 + 8) + 0x18))();
      }
      if (local_38 != 0) {
        ext2fs_free_mem(&local_38);
      }
    }
  }
  else {
    uVar5 = (ulong)(uint)(*(int *)(lVar2 + 0x14) + *(int *)(lVar2 + 0x20));
    if (param_1 != 0) {
      uVar1 = *(undefined4 *)(param_2 + 0x28);
      *(ulong *)(param_1 + 0x60) = uVar5;
      *(undefined4 *)(param_1 + 0x50) = uVar1;
    }
  }
LAB_001350bd:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



// Function: ext2_file_type @ 0x352e0

undefined8 ext2_file_type(uint param_1)

{
  undefined8 uVar1;
  
  param_1 = param_1 & 0xf000;
  uVar1 = 1;
  if (param_1 != 0x8000) {
    if (param_1 == 0x4000) {
      return 2;
    }
    if (param_1 == 0x2000) {
      return 3;
    }
    if (param_1 == 0x6000) {
      return 4;
    }
    if (param_1 == 0xa000) {
      return 7;
    }
    if (param_1 != 0x1000) {
      uVar1 = 0;
      if (param_1 == 0xc000) {
        uVar1 = 6;
      }
      return uVar1;
    }
    uVar1 = 5;
  }
  return uVar1;
}



// Function: fs_proc_check @ 0x35380

undefined8 fs_proc_check(char *param_1)

{
  char *pcVar1;
  ushort *puVar2;
  int iVar3;
  FILE *__stream;
  char *pcVar4;
  ushort **ppuVar5;
  undefined8 uVar6;
  long lVar7;
  char *__s;
  long in_FS_OFFSET;
  char local_88;
  char local_87 [87];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen("/proc/filesystems","r");
  if (__stream == (FILE *)0x0) {
    uVar6 = 0;
  }
  else {
    do {
      iVar3 = feof(__stream);
      if ((iVar3 != 0) || (pcVar4 = fgets(&local_88,0x50,__stream), pcVar4 == (char *)0x0)) {
        fclose(__stream);
        uVar6 = 0;
        goto LAB_001354ca;
      }
      ppuVar5 = __ctype_b_loc();
      lVar7 = (long)local_88;
      puVar2 = *ppuVar5;
      if ((*(byte *)((long)puVar2 + lVar7 * 2 + 1) & 0x20) == 0) {
        pcVar4 = &local_88;
        __s = &local_88;
        if (local_88 != '\0') {
          do {
            pcVar1 = pcVar4 + 1;
            pcVar4 = pcVar4 + 1;
            __s = pcVar4;
            if (*pcVar1 == '\0') goto LAB_0013542f;
            lVar7 = (long)*pcVar1;
          } while ((*(byte *)((long)puVar2 + lVar7 * 2 + 1) & 0x20) == 0);
          goto LAB_00135428;
        }
      }
      else {
        pcVar4 = &local_88;
        __s = &local_88;
        if (local_88 != '\0') {
LAB_00135428:
          while (__s = pcVar4, (*(byte *)((long)puVar2 + lVar7 * 2 + 1) & 0x20) != 0) {
            pcVar1 = pcVar4 + 1;
            pcVar4 = pcVar4 + 1;
            __s = pcVar4;
            if (*pcVar1 == '\0') break;
            lVar7 = (long)*pcVar1;
          }
        }
      }
LAB_0013542f:
      pcVar4 = strchr(__s,10);
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
      }
      pcVar4 = strchr(__s,9);
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
      }
      pcVar4 = strchr(__s,0x20);
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
      }
      iVar3 = strcmp(param_1,__s);
    } while (iVar3 != 0);
    fclose(__stream);
    uVar6 = 1;
  }
LAB_001354ca:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



// Function: check_for_modules @ 0x354f0

undefined8 check_for_modules(char *param_1)

{
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  char *pcVar3;
  size_t sVar4;
  undefined8 uVar5;
  long in_FS_OFFSET;
  utsname uStack_5d8;
  char local_448 [1032];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = uname(&uStack_5d8);
  if (iVar1 == 0) {
    uVar5 = 0;
    __snprintf_chk(local_448,0x400,1,0x400,"/lib/modules/%s/modules.dep",uStack_5d8.release);
    __stream = fopen(local_448,"r");
    if (__stream != (FILE *)0x0) {
      do {
        do {
          iVar1 = feof(__stream);
          if (iVar1 != 0) {
LAB_00135660:
            fclose(__stream);
            goto LAB_0013552a;
          }
          pcVar2 = fgets(local_448,0x400,__stream);
          if (pcVar2 == (char *)0x0) goto LAB_00135660;
          pcVar2 = strchr(local_448,0x3a);
        } while (pcVar2 == (char *)0x0);
        *pcVar2 = '\0';
        pcVar3 = strrchr(local_448,0x2f);
        pcVar2 = pcVar3 + 1;
        if (pcVar3 == (char *)0x0) {
          pcVar2 = local_448;
        }
        sVar4 = strlen(pcVar2);
        if (3 < (int)sVar4) {
          iVar1 = strcmp(pcVar2 + (long)(int)sVar4 + -3,".ko");
          if (iVar1 == 0) {
            pcVar2[(long)(int)sVar4 + -3] = '\0';
          }
        }
        iVar1 = strcmp(pcVar2,param_1);
      } while (iVar1 != 0);
      uVar5 = 1;
      fclose(__stream);
      goto LAB_0013552a;
    }
  }
  uVar5 = 0;
LAB_0013552a:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: write_all @ 0x35680

int write_all(int param_1,void *param_2,size_t param_3)

{
  ssize_t sVar1;
  int *piVar2;
  int iVar3;
  
  if (param_3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    do {
      while( true ) {
        sVar1 = write(param_1,param_2,param_3);
        if (-1 < sVar1) break;
        piVar2 = __errno_location();
        if ((*piVar2 != 0xb) && (*piVar2 != 4)) {
          return -1;
        }
      }
      param_2 = (void *)((long)param_2 + sVar1);
      iVar3 = iVar3 + (int)sVar1;
      param_3 = param_3 - sVar1;
    } while (param_3 != 0);
  }
  return iVar3;
}



// Function: dump_mmp_msg @ 0x35700

void dump_mmp_msg(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 undefined4 *param_9,long param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  char *pcVar1;
  long in_FS_OFFSET;
  time_t local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 *local_e0;
  undefined1 *local_d8;
  long local_d0;
  undefined1 local_c8 [16];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_28;
  
  if (in_AL != '\0') {
    local_98 = param_1;
    local_88 = param_2;
    local_78 = param_3;
    local_68 = param_4;
    local_58 = param_5;
    local_48 = param_6;
    local_38 = param_7;
    local_28 = param_8;
  }
  local_d0 = *(long *)(in_FS_OFFSET + 0x28);
  local_b8 = param_11;
  local_b0 = param_12;
  local_a8 = param_13;
  local_a0 = param_14;
  if (param_10 != 0) {
    __printf_chk(1,"MMP check failed: ");
    local_e0 = &stack0x00000008;
    local_d8 = local_c8;
    local_e8 = 0x10;
    local_e4 = 0x30;
    __vprintf_chk(1,param_10,&local_e8);
  }
  if (param_9 != (undefined4 *)0x0) {
    local_f0 = *(time_t *)(param_9 + 2);
    __printf_chk(1,"MMP_block:\n");
    __printf_chk(1,"    mmp_magic: 0x%x\n",*param_9);
    __printf_chk(1,"    mmp_check_interval: %d\n",*(undefined2 *)(param_9 + 0x1c));
    __printf_chk(1,"    mmp_sequence: %08x\n",param_9[1]);
    pcVar1 = ctime(&local_f0);
    __printf_chk(1,"    mmp_update_date: %s",pcVar1);
    __printf_chk(1,"    mmp_update_time: %lld\n",*(undefined8 *)(param_9 + 2));
    __printf_chk(1,"    mmp_node_name: %.*s\n",0x40,param_9 + 4);
    __printf_chk(1,"    mmp_device_name: %.*s\n",0x20,param_9 + 0x14);
  }
  if (local_d0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_mmp_update @ 0x358c0

long e2fsck_mmp_update(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = ext2fs_mmp_update();
  if (lVar1 != 0x7f2bb78f) {
    return lVar1;
  }
  uVar2 = dcgettext(0,
                    "UNEXPECTED INCONSISTENCY: the filesystem is being modified while fsck is running.\n"
                    ,5);
  dump_mmp_msg(*(undefined8 *)(param_1 + 0x118),uVar2);
  return 0x7f2bb78f;
}



// Function: e2fsck_set_bitmap_type @ 0x35920

void e2fsck_set_bitmap_type(long param_1,undefined4 param_2,undefined8 param_3,uint *param_4)

{
  long lVar1;
  undefined2 uVar2;
  long in_FS_OFFSET;
  int local_34;
  long local_30;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_4 != (uint *)0x0) {
    *param_4 = (uint)*(ushort *)(param_1 + 0xc4);
  }
  profile_get_uint(*(undefined8 *)(lVar1 + 0x360),"bitmaps",param_3,0,param_2,&local_34);
  profile_get_uint(*(undefined8 *)(lVar1 + 0x360),"bitmaps",&DAT_00179eb3,0,local_34,&local_34);
  uVar2 = (undefined2)param_2;
  if (local_34 != 0) {
    uVar2 = (undefined2)local_34;
  }
  *(undefined2 *)(param_1 + 0xc4) = uVar2;
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_read_bitmaps @ 0x359d0

void e2fsck_read_bitmaps(long *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long in_FS_OFFSET;
  undefined2 local_34 [2];
  long local_30;
  
  lVar4 = *param_1;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((int)param_1[0x41] == 0) {
    uVar2 = dcgettext(0,"reading inode and block bitmaps",5);
    uVar2 = ehandler_operation(uVar2);
    e2fsck_set_bitmap_type(lVar4,2,"fs_bitmaps",local_34);
    uVar1 = *(uint *)(*param_1 + 0x10);
    *(uint *)(*param_1 + 0x10) = uVar1 | 0x200000;
    lVar3 = ext2fs_read_bitmaps(lVar4);
    *(uint *)(*param_1 + 0x10) = *(uint *)(*param_1 + 0x10) & 0xffdfffff | uVar1 & 0x200000;
    *(undefined2 *)(lVar4 + 0xc4) = local_34[0];
    ehandler_operation(uVar2);
    if (lVar3 == 0) {
      if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    lVar4 = param_1[3];
    uVar2 = dcgettext(0,"while retrying to read bitmaps for %s",5);
    lVar5 = param_1[1];
  }
  else {
    lVar4 = param_1[3];
    uVar2 = dcgettext(0,"e2fsck_read_bitmaps: illegal bitmap block(s) for %s",5);
    lVar5 = param_1[1];
    lVar3 = 0;
  }
  com_err(lVar5,lVar3,uVar2,lVar4);
                    /* WARNING: Subroutine does not return */
  fatal_error(param_1,0);
}



// Function: e2fsck_allocate_inode_bitmap @ 0x35b10

void e2fsck_allocate_inode_bitmap
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long in_FS_OFFSET;
  undefined2 local_24 [2];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  e2fsck_set_bitmap_type(param_1,param_3,param_4,local_24);
  ext2fs_allocate_inode_bitmap(param_1,param_2,param_5);
  *(undefined2 *)(param_1 + 0xc4) = local_24[0];
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_allocate_block_bitmap @ 0x35b80

void e2fsck_allocate_block_bitmap
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long in_FS_OFFSET;
  undefined2 local_24 [2];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  e2fsck_set_bitmap_type(param_1,param_3,param_4,local_24);
  ext2fs_allocate_block_bitmap(param_1,param_2,param_5);
  *(undefined2 *)(param_1 + 0xc4) = local_24[0];
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_allocate_subcluster_bitmap @ 0x35bf0

void e2fsck_allocate_subcluster_bitmap
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long in_FS_OFFSET;
  undefined2 local_24 [2];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  e2fsck_set_bitmap_type(param_1,param_3,param_4,local_24);
  ext2fs_allocate_subcluster_bitmap(param_1,param_2,param_5);
  *(undefined2 *)(param_1 + 0xc4) = local_24[0];
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: get_memory_size @ 0x35c60

long get_memory_size(void)

{
  long lVar1;
  long lVar2;
  
  lVar1 = sysconf(0x55);
  lVar2 = sysconf(0x1e);
  return lVar2 * lVar1;
}



// Function: setup_tdb @ 0x35c90

void setup_tdb(long *param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  __mode_t __mask;
  uint uVar3;
  size_t sVar4;
  long lVar5;
  undefined8 uVar6;
  long in_FS_OFFSET;
  uint local_68;
  int local_64;
  char *local_60;
  undefined1 local_58 [40];
  long local_30;
  
  lVar1 = param_1[0x46];
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  profile_get_string(param_1[0x6c],"scratch_files","directory",0,0,&local_60);
  profile_get_uint(param_1[0x6c],"scratch_files","numdirs_threshold",0,0,&local_68);
  profile_get_boolean(param_1[0x6c],"scratch_files","dirinfo",0,1,&local_64);
  if ((local_64 != 0) && (local_60 != (char *)0x0)) {
    iVar2 = access(local_60,2);
    if ((iVar2 == 0) && ((local_68 < param_2 || (local_68 == 0)))) {
      sVar4 = strlen(local_60);
      lVar5 = ext2fs_get_mem(sVar4 + 0x40,lVar1 + 0x18);
      if (lVar5 == 0) {
        uuid_unparse(*(long *)(*param_1 + 0x20) + 0x68,local_58);
        __sprintf_chk(*(undefined8 *)(lVar1 + 0x18),1,0xffffffffffffffff,"%s/%s-dirinfo-XXXXXX",
                      local_60,local_58);
        __mask = umask(0x3f);
        iVar2 = mkstemp(*(char **)(lVar1 + 0x18));
        umask(__mask);
        if (iVar2 < 0) {
          *(undefined8 *)(lVar1 + 0x20) = 0;
        }
        else {
          uVar3 = 0x18697;
          if (0x18696 < param_2) {
            uVar3 = param_2;
          }
          uVar6 = ext2fs_tdb_open(*(undefined8 *)(lVar1 + 0x18),uVar3,0x44,0x242,0x180);
          *(undefined8 *)(lVar1 + 0x20) = uVar6;
          close(iVar2);
        }
      }
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: setup_db @ 0x35e50

void setup_db(undefined8 *param_1)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  int local_24;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  puVar1 = (undefined8 *)e2fsck_allocate_memory(param_1,0x28,"directory map db");
  uVar3 = *param_1;
  *puVar1 = 0;
  puVar1[1] = 0;
  param_1[0x46] = puVar1;
  lVar2 = ext2fs_get_num_dirs(uVar3,&local_24);
  if (lVar2 == 0) {
    FUN_00135c90(param_1,local_24);
    lVar2 = puVar1[4];
  }
  else {
    local_24 = 0x400;
    FUN_00135c90(param_1,0x400);
    lVar2 = puVar1[4];
  }
  if (lVar2 == 0) {
    *(uint *)((long)puVar1 + 4) = local_24 + 10U;
    uVar3 = e2fsck_allocate_memory(param_1,(ulong)(local_24 + 10U) * 0xc,"directory map");
    puVar1[1] = uVar3;
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: e2fsck_add_dir_info @ 0x36110

void e2fsck_add_dir_info(long param_1,uint param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  uint *puVar6;
  long lVar7;
  uint uVar8;
  uint *puVar10;
  ulong uVar11;
  uint *puVar12;
  ulong uVar13;
  long in_FS_OFFSET;
  uint local_3c;
  uint local_38;
  uint local_34;
  long local_30;
  ulong uVar9;
  
  puVar12 = *(uint **)(param_1 + 0x230);
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (puVar12 == (uint *)0x0) {
    FUN_00135e50(param_1);
    puVar12 = *(uint **)(param_1 + 0x230);
  }
  uVar1 = puVar12[1];
  if (uVar1 <= *puVar12) {
    lVar2 = *(long *)(puVar12 + 2);
    puVar12[1] = uVar1 + 10;
    lVar7 = ext2fs_resize_mem((ulong)uVar1 * 0xc,(ulong)(uVar1 + 10) * 0xc,puVar12 + 2);
    if (lVar7 != 0) {
      __fprintf_chk(stderr,1,"Couldn\'t reallocate dir_info structure to %u entries\n",
                    *(undefined4 *)(*(long *)(param_1 + 0x230) + 4));
                    /* WARNING: Subroutine does not return */
      fatal_error(param_1,0);
    }
    puVar12 = *(uint **)(param_1 + 0x230);
    if (*(long *)(puVar12 + 2) != lVar2) {
      puVar12[4] = 0;
      puVar12[5] = 0;
    }
  }
  if (*(long *)(puVar12 + 8) != 0) {
    local_3c = param_2;
    local_38 = param_3;
    local_34 = param_3;
    FUN_00135f20(puVar12,&local_3c);
    goto LAB_0013617a;
  }
  uVar1 = *puVar12;
  uVar11 = (ulong)uVar1;
  puVar6 = *(uint **)(puVar12 + 2);
  if (uVar1 == 0) {
LAB_00136165:
    *puVar12 = uVar1 + 1;
    puVar6 = puVar6 + uVar11 * 3;
  }
  else {
    uVar8 = uVar1 - 1;
    uVar9 = (ulong)uVar8;
    puVar10 = puVar6 + uVar9 * 3;
    uVar5 = (ulong)uVar8;
    if (*puVar10 < param_2) goto LAB_00136165;
    do {
      uVar4 = uVar5;
      uVar3 = (uint)uVar4;
      uVar13 = uVar9;
      if (uVar8 == 0) {
        if (param_2 == *puVar6) goto LAB_00136172;
        *puVar12 = uVar1 + 1;
        goto LAB_001361fc;
      }
      uVar8 = uVar3 - 1;
      uVar5 = (ulong)uVar8;
    } while (param_2 <= puVar6[(ulong)uVar8 * 3]);
    puVar6 = puVar6 + uVar4 * 3;
    if ((*puVar6 != param_2) && (*puVar12 = uVar1 + 1, uVar3 < uVar1)) {
LAB_001361fc:
      while( true ) {
        *(undefined8 *)(puVar10 + uVar9 * -3 + uVar11 * 3) = *(undefined8 *)puVar10;
        puVar10[uVar9 * -3 + uVar11 * 3 + 2] = puVar10[2];
        if ((uint)uVar13 <= uVar3) break;
        puVar10 = puVar10 + -3;
        uVar13 = (ulong)((uint)uVar13 - 1);
      }
    }
  }
LAB_00136172:
  *puVar6 = param_2;
  puVar6[1] = param_3;
  puVar6[2] = param_3;
LAB_0013617a:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: e2fsck_free_dir_info @ 0x36320

void e2fsck_free_dir_info(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x230);
  if (puVar4 != (undefined8 *)0x0) {
    if (puVar4[4] != 0) {
      ext2fs_tdb_close(puVar4[4]);
      puVar4 = *(undefined8 **)(param_1 + 0x230);
    }
    if ((char *)puVar4[3] != (char *)0x0) {
      iVar1 = unlink((char *)puVar4[3]);
      if (iVar1 < 0) {
        uVar2 = dcgettext(0,"while freeing dir_info tdb file",5);
        piVar3 = __errno_location();
        com_err("e2fsck_free_dir_info",(long)*piVar3,uVar2);
      }
      ext2fs_free_mem(*(long *)(param_1 + 0x230) + 0x18);
      puVar4 = *(undefined8 **)(param_1 + 0x230);
    }
    if (puVar4[1] != 0) {
      ext2fs_free_mem(puVar4 + 1);
      puVar4 = *(undefined8 **)(param_1 + 0x230);
    }
    *puVar4 = 0;
    puVar4[1] = 0;
    ext2fs_free_mem(param_1 + 0x230);
    *(undefined8 *)(param_1 + 0x230) = 0;
  }
  return;
}



// Function: e2fsck_get_num_dirinfo @ 0x36410

undefined4 e2fsck_get_num_dirinfo(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(undefined4 **)(param_1 + 0x230) != (undefined4 *)0x0) {
    uVar1 = **(undefined4 **)(param_1 + 0x230);
  }
  return uVar1;
}



// Function: e2fsck_dir_info_iter_begin @ 0x36430

long e2fsck_dir_info_iter_begin(long param_1)

{
  long lVar1;
  undefined1 auVar2 [16];
  
  lVar1 = e2fsck_allocate_memory(param_1,0x18,"dir_info iterator");
  if (*(long *)(*(long *)(param_1 + 0x230) + 0x20) != 0) {
    auVar2 = ext2fs_tdb_firstkey();
    *(undefined1 (*) [16])(lVar1 + 8) = auVar2;
  }
  return lVar1;
}



// Function: e2fsck_dir_info_iter_end @ 0x36480

void e2fsck_dir_info_iter_end(undefined8 param_1,long param_2)

{
  long local_10 [2];
  
  local_10[0] = param_2;
  free(*(void **)(param_2 + 8));
  ext2fs_free_mem(local_10);
  return;
}



// Function: e2fsck_dir_info_iter @ 0x364b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * e2fsck_dir_info_iter(long param_1,uint *param_2)

{
  undefined *puVar1;
  uint uVar2;
  uint *puVar3;
  void *__ptr;
  long lVar4;
  undefined4 *__ptr_00;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  
  puVar3 = *(uint **)(param_1 + 0x230);
  if ((param_2 != (uint *)0x0) && (puVar3 != (uint *)0x0)) {
    if (*(long *)(puVar3 + 8) != 0) {
      __ptr = *(void **)(param_2 + 2);
      if (__ptr == (void *)0x0) {
        return (undefined *)0x0;
      }
      uVar5 = *(undefined8 *)(param_2 + 4);
      __ptr_00 = (undefined4 *)ext2fs_tdb_fetch(*(long *)(puVar3 + 8),__ptr,uVar5);
      if (__ptr_00 != (undefined4 *)0x0) {
        _DAT_001b7368 = **(undefined4 **)(param_2 + 2);
        _DAT_001b736c = *__ptr_00;
        _DAT_001b7370 = __ptr_00[1];
        auVar6 = ext2fs_tdb_nextkey(*(undefined8 *)(*(long *)(param_1 + 0x230) + 0x20),__ptr,uVar5);
        *(undefined1 (*) [16])(param_2 + 2) = auVar6;
        free(__ptr);
        free(__ptr_00);
        return &DAT_001b7368;
      }
      uVar5 = ext2fs_tdb_errorstr(*(undefined8 *)(*(long *)(param_1 + 0x230) + 0x20));
      __printf_chk(1,"iter fetch failed: %s\n",uVar5);
      return (undefined *)0x0;
    }
    uVar2 = *param_2;
    if (uVar2 < *puVar3) {
      lVar4 = *(long *)(puVar3 + 2);
      *param_2 = uVar2 + 1;
      puVar1 = (undefined *)(lVar4 + (ulong)uVar2 * 0xc);
      *(undefined **)(puVar3 + 4) = puVar1;
      return puVar1;
    }
  }
  return (undefined *)0x0;
}



// Function: e2fsck_dir_info_set_parent @ 0x365e0

bool e2fsck_dir_info_set_parent(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = FUN_00135fb0(*(undefined8 *)(param_1 + 0x230));
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 8) = param_3;
    FUN_00135f20(*(undefined8 *)(param_1 + 0x230));
  }
  return lVar1 == 0;
}



// Function: e2fsck_dir_info_set_dotdot @ 0x36620

bool e2fsck_dir_info_set_dotdot(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = FUN_00135fb0(*(undefined8 *)(param_1 + 0x230));
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 4) = param_3;
    FUN_00135f20(*(undefined8 *)(param_1 + 0x230));
  }
  return lVar1 == 0;
}



// Function: e2fsck_dir_info_get_parent @ 0x36660

undefined8 e2fsck_dir_info_get_parent(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  
  lVar1 = FUN_00135fb0(*(undefined8 *)(param_1 + 0x230));
  if (lVar1 != 0) {
    *param_3 = *(undefined4 *)(lVar1 + 8);
    return 0;
  }
  return 1;
}



// Function: e2fsck_dir_info_get_dotdot @ 0x36690

undefined8 e2fsck_dir_info_get_dotdot(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  
  lVar1 = FUN_00135fb0(*(undefined8 *)(param_1 + 0x230));
  if (lVar1 != 0) {
    *param_3 = *(undefined4 *)(lVar1 + 4);
    return 0;
  }
  return 1;
}



// Function: e2fsck_add_dx_dir @ 0x366c0

void e2fsck_add_dx_dir(long param_1,uint param_2,long param_3,uint param_4)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  uint *puVar8;
  ulong uVar9;
  uint *puVar10;
  ulong uVar11;
  ulong uVar4;
  
  if (*(long *)(param_1 + 0x240) == 0) {
    *(undefined8 *)(param_1 + 0x238) = 0x6400000000;
    uVar5 = e2fsck_allocate_memory(param_1,0x960,"directory map");
    *(undefined8 *)(param_1 + 0x240) = uVar5;
  }
  uVar1 = *(uint *)(param_1 + 0x238);
  uVar3 = *(uint *)(param_1 + 0x23c);
  if (uVar3 <= uVar1) {
    *(uint *)(param_1 + 0x23c) = uVar3 + 10;
    lVar6 = ext2fs_resize_mem((ulong)uVar3 * 0x18,(ulong)(uVar3 + 10) * 0x18,param_1 + 0x240);
    if (lVar6 != 0) {
      __fprintf_chk(stderr,1,"Couldn\'t reallocate dx_dir_info structure to %u entries\n",
                    *(undefined4 *)(param_1 + 0x23c));
                    /* WARNING: Subroutine does not return */
      fatal_error(param_1,0);
    }
    uVar1 = *(uint *)(param_1 + 0x238);
  }
  uVar9 = (ulong)uVar1;
  puVar10 = *(uint **)(param_1 + 0x240);
  if (uVar1 != 0) {
    uVar7 = (ulong)(uVar1 - 1);
    puVar8 = puVar10 + uVar7 * 6;
    uVar2 = uVar7;
    if (param_2 <= *puVar8) {
      do {
        uVar4 = uVar2;
        uVar3 = (uint)uVar4;
        uVar11 = uVar7;
        if (uVar3 == 0) {
          if (param_2 == *puVar10) goto LAB_00136791;
          *(uint *)(param_1 + 0x238) = uVar1 + 1;
          goto LAB_0013675c;
        }
        uVar2 = (ulong)(uVar3 - 1);
      } while (param_2 <= puVar10[(ulong)(uVar3 - 1) * 6]);
      puVar10 = puVar10 + uVar4 * 6;
      if ((*puVar10 != param_2) && (*(uint *)(param_1 + 0x238) = uVar1 + 1, uVar3 < uVar1)) {
LAB_0013675c:
        while( true ) {
          uVar5 = *(undefined8 *)(puVar8 + 2);
          *(undefined8 *)(puVar8 + uVar7 * -6 + uVar9 * 6) = *(undefined8 *)puVar8;
          *(undefined8 *)(puVar8 + uVar7 * -6 + uVar9 * 6 + 2) = uVar5;
          *(undefined8 *)(puVar8 + uVar7 * -6 + uVar9 * 6 + 4) = *(undefined8 *)(puVar8 + 4);
          if ((uint)uVar11 <= uVar3) break;
          puVar8 = puVar8 + -6;
          uVar11 = (ulong)((uint)uVar11 - 1);
        }
      }
      goto LAB_00136791;
    }
  }
  *(uint *)(param_1 + 0x238) = uVar1 + 1;
  puVar10 = puVar10 + uVar9 * 6;
LAB_00136791:
  uVar3 = *(uint *)(param_3 + 0x20);
  *puVar10 = param_2;
  puVar10[2] = param_4;
  *(ushort *)((long)puVar10 + 6) =
       (ushort)((uVar3 >> 0x1e & 1) << 8) | *(ushort *)((long)puVar10 + 6) & 0xfe00;
  uVar5 = e2fsck_allocate_memory(param_1,(long)(int)param_4 * 0x30,"dx_block info array");
  *(undefined8 *)(puVar10 + 4) = uVar5;
  return;
}



// Function: e2fsck_get_dx_dir_info @ 0x368c0

uint * e2fsck_get_dx_dir_info(long param_1,uint param_2)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar5 = *(uint **)(param_1 + 0x240);
  if ((puVar5 != (uint *)0x0) && (*puVar5 != param_2)) {
    uVar2 = (ulong)(*(int *)(param_1 + 0x238) - 1);
    uVar1 = 0;
    if (puVar5[uVar2 * 6] == param_2) {
      return puVar5 + uVar2 * 6;
    }
    while (((uVar3 = uVar1, uVar4 = (uint)uVar2, uVar3 < uVar4 &&
            (uVar1 = uVar3 + uVar4 >> 1, uVar3 != uVar1)) && (uVar4 != uVar1))) {
      uVar4 = puVar5[(ulong)uVar1 * 6];
      if (uVar4 == param_2) {
        return puVar5 + (ulong)uVar1 * 6;
      }
      if (param_2 < uVar4) {
        uVar2 = (ulong)uVar1;
        uVar1 = uVar3;
      }
    }
    puVar5 = (uint *)0x0;
  }
  return puVar5;
}



// Function: e2fsck_free_dx_dir_info @ 0x36940

void e2fsck_free_dx_dir_info(long param_1)

{
  long *plVar1;
  uint uVar2;
  
  if (*(long *)(param_1 + 0x240) != 0) {
    if (*(int *)(param_1 + 0x238) != 0) {
      plVar1 = (long *)(*(long *)(param_1 + 0x240) + 0x10);
      uVar2 = 0;
      do {
        if (*plVar1 != 0) {
          ext2fs_free_mem(plVar1);
          *plVar1 = 0;
        }
        uVar2 = uVar2 + 1;
        plVar1 = plVar1 + 3;
      } while (uVar2 < *(uint *)(param_1 + 0x238));
    }
    ext2fs_free_mem(param_1 + 0x240);
    *(undefined8 *)(param_1 + 0x240) = 0;
  }
  *(undefined8 *)(param_1 + 0x238) = 0;
  return;
}



// Function: e2fsck_get_num_dx_dirinfo @ 0x369c0

undefined4 e2fsck_get_num_dx_dirinfo(long param_1)

{
  return *(undefined4 *)(param_1 + 0x238);
}



// Function: e2fsck_dx_dir_info_iter @ 0x369d0

long e2fsck_dx_dir_info_iter(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  
  uVar1 = *param_2;
  if (uVar1 < *(uint *)(param_1 + 0x238)) {
    lVar2 = *(long *)(param_1 + 0x240);
    *param_2 = uVar1 + 1;
    return lVar2 + (ulong)uVar1 * 0x18;
  }
  return 0;
}



// Function: e2fsck_handle_write_error @ 0x36a00

long e2fsck_handle_write_error(long param_1,long param_2,int param_3,long param_4,undefined8 param_5,
                 undefined8 param_6,long param_7)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar3 = DAT_001b7378;
  lVar1 = *(long *)(*(long *)(param_1 + 0xb0) + 0xe0);
  if ((*(byte *)(lVar1 + 0x49) & 0x10) == 0) {
    if (param_3 < 2) {
      if (DAT_001b7378 == 0) {
        uVar4 = error_message(param_7);
        uVar5 = dcgettext(0,"Error writing block %lu (%s).  ",5);
        __printf_chk(1,uVar5,param_2,uVar4);
      }
      else {
        uVar4 = error_message();
        uVar5 = dcgettext(0,"Error writing block %lu (%s) while %s.  ",5);
        __printf_chk(1,uVar5,param_2,uVar4,lVar3);
      }
      preenhalt(lVar1);
      uVar4 = dcgettext(0,"Ignore error",5);
      iVar2 = ask(lVar1,uVar4,1);
      if (iVar2 == 0) {
        return param_7;
      }
    }
    else {
      lVar1 = param_2 + 1;
      do {
        lVar3 = io_channel_write_blk64(param_1,param_2,1,param_4);
        if (lVar3 != 0) {
          return lVar3;
        }
        param_2 = param_2 + 1;
        param_4 = param_4 + *(int *)(param_1 + 0x18);
      } while (lVar1 + (ulong)(param_3 - 1) != param_2);
    }
  }
  return 0;
}



// Function: e2fsck_handle_read_error @ 0x36b40

long e2fsck_handle_read_error(long param_1,ulong param_2,int param_3,long param_4,undefined8 param_5,
                 undefined8 param_6,long param_7)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  
  lVar2 = DAT_001b7378;
  lVar1 = *(long *)(param_1 + 0xb0);
  lVar4 = *(long *)(lVar1 + 0xe0);
  if ((*(byte *)(lVar4 + 0x49) & 0x10) == 0) {
    if (param_3 < 2) {
      if (DAT_001b7378 == 0) {
        uVar5 = error_message(param_7);
        uVar6 = dcgettext(0,"Error reading block %lu (%s).  ",5);
        __printf_chk(1,uVar6,param_2,uVar5);
      }
      else {
        uVar5 = error_message();
        uVar6 = dcgettext(0,"Error reading block %lu (%s) while %s.  ",5);
        __printf_chk(1,uVar6,param_2,uVar5,lVar2);
      }
      preenhalt(lVar4);
      uVar7 = ext2fs_blocks_count(*(undefined8 *)(lVar1 + 0x20));
      if (param_2 < uVar7) {
        uVar5 = dcgettext(0,"Ignore error",5);
        iVar3 = ask(lVar4,uVar5,1);
        if (iVar3 == 0) {
          return param_7;
        }
        uVar5 = dcgettext(0,"Force rewrite",5);
        iVar3 = ask(lVar4,uVar5,1);
        if (iVar3 != 0) {
          io_channel_write_blk64(param_1,param_2,param_3,param_4);
        }
      }
    }
    else {
      lVar1 = param_2 + 1;
      do {
        lVar4 = io_channel_read_blk64(param_1,param_2,1,param_4);
        if (lVar4 != 0) {
          return lVar4;
        }
        param_2 = param_2 + 1;
        param_4 = param_4 + *(int *)(param_1 + 0x18);
      } while (lVar1 + (ulong)(param_3 - 1) != param_2);
    }
  }
  return 0;
}



// Function: ehandler_operation @ 0x36ce0

undefined8 ehandler_operation(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = DAT_001b7378;
  DAT_001b7378 = param_1;
  return uVar1;
}



// Function: ehandler_init @ 0x36d00

void ehandler_init(long param_1)

{
  *(code **)(param_1 + 0x20) = FUN_00136b40;
  *(code **)(param_1 + 0x28) = FUN_00136a00;
  return;
}



// Function: find_problem @ 0x36d20

undefined4 * find_problem(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_001b2180 != 0) {
    piVar3 = &DAT_001b21a8;
    iVar2 = 0;
    iVar1 = DAT_001b2180;
    do {
      if (param_1 == iVar1) {
        return &DAT_001b2180 + (long)iVar2 * 10;
      }
      iVar1 = *piVar3;
      piVar3 = piVar3 + 10;
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
  }
  return (undefined4 *)0x0;
}



// Function: find_latch @ 0x36d70

undefined4 * find_latch(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (-1 < DAT_001b20c0) {
    piVar3 = &DAT_001b20d0;
    iVar2 = 0;
    iVar1 = DAT_001b20c0;
    do {
      if (param_1 == iVar1) {
        return &DAT_001b20c0 + (long)iVar2 * 4;
      }
      iVar1 = *piVar3;
      piVar3 = piVar3 + 4;
      iVar2 = iVar2 + 1;
    } while (-1 < iVar1);
  }
  return (undefined4 *)0x0;
}



// Function: set_latch_flags @ 0x37160

undefined8 set_latch_flags(undefined8 param_1,uint param_2,uint param_3)

{
  long lVar1;
  
  lVar1 = FUN_00136d70();
  if (lVar1 != 0) {
    *(uint *)(lVar1 + 0xc) = (param_2 | *(uint *)(lVar1 + 0xc)) & ~param_3;
    return 0;
  }
  return 0xffffffff;
}



// Function: get_latch_flags @ 0x37190

undefined8 get_latch_flags(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  
  lVar1 = FUN_00136d70();
  if (lVar1 != 0) {
    *param_2 = *(undefined4 *)(lVar1 + 0xc);
    return 0;
  }
  return 0xffffffff;
}



// Function: clear_problem_context @ 0x371b0

void clear_problem_context(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 *puVar2;
  
  *param_1 = 0;
  param_1[0xc] = 0;
  puVar2 = (undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
  for (uVar1 = (ulong)(((int)param_1 -
                       (int)(undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8)) + 0x68U >> 3)
      ; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[7] = 0xffffffffffffffff;
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  return;
}



// Function: fix_problem @ 0x371f0

uint fix_problem(undefined8 *param_1,undefined4 param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  undefined *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  long in_FS_OFFSET;
  long local_70;
  long local_58;
  undefined1 local_49 [9];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = *param_1;
  puVar3 = (undefined4 *)FUN_00136d20(param_2);
  if (puVar3 == (undefined4 *)0x0) {
    uVar11 = 0;
    uVar5 = dcgettext(0,"Unhandled error code (0x%x)!\n",5);
    __printf_chk(1,uVar5,param_2);
    goto LAB_001373e3;
  }
  uVar10 = puVar3[5];
  if ((uVar10 & 0x80000) == 0) {
    local_58 = 0;
    __sprintf_chk(local_49,1,9,"0x%06x",param_2);
    profile_get_string(param_1[0x6c],"problems",local_49,"description",0,&local_58);
    if (local_58 != 0) {
      *(long *)(puVar3 + 2) = local_58;
    }
    FUN_001370f0(param_1[0x6c],puVar3,local_49,1,"preen_ok");
    FUN_001370f0(param_1[0x6c],puVar3,local_49,2,"no_ok");
    FUN_001370f0(param_1[0x6c],puVar3,local_49,4,"no_default");
    FUN_001370f0(param_1[0x6c],puVar3,local_49,8,"print_message_only");
    FUN_001370f0(param_1[0x6c],puVar3,local_49,0x4000,"preen_nomessage");
    FUN_001370f0(param_1[0x6c],puVar3,local_49,0x8000,"no_collate");
    FUN_001370f0(param_1[0x6c],puVar3,local_49,0x10000,"no_nomsg");
    FUN_001370f0(param_1[0x6c],puVar3,local_49,0x40000,"preen_noheader");
    FUN_001370f0(param_1[0x6c],puVar3,local_49,0x100000,"force_no");
    FUN_001370f0(param_1[0x6c],puVar3,local_49,0x200000,"not_a_fix");
    profile_get_integer(param_1[0x6c],"options","max_count_problems",0,0);
    profile_get_integer(param_1[0x6c],"problems",local_49,"max_count",puVar3[8],puVar3 + 8);
    uVar10 = puVar3[5] | 0x80000;
    puVar3[5] = uVar10;
  }
  uVar7 = (ulong)uVar10;
  puVar3[7] = puVar3[7] + 1;
  uVar11 = uVar10 & 4;
  if ((uVar10 & 4) == 0) {
    if (((uVar10 & 0x20000) == 0) || ((*(uint *)((long)param_1 + 0x4c) & 2) == 0)) {
      uVar11 = (uint)((*(uint *)((long)param_1 + 0x4c) & 8) == 0);
    }
  }
  else {
    uVar11 = 0;
  }
  local_70 = 0;
  uVar9 = 0;
  if ((uVar10 & 0xff0) != 0) {
    local_70 = FUN_00136d70(uVar10 & 0xff0);
    if (*(int *)(local_70 + 4) == 0) {
      uVar10 = *(uint *)(local_70 + 0xc);
    }
    else {
      uVar10 = *(uint *)(local_70 + 0xc);
      if ((uVar10 & 4) == 0) {
        iVar2 = fix_problem(param_1,*(int *)(local_70 + 4),param_3);
        if (iVar2 == 1) {
          uVar10 = *(uint *)(local_70 + 0xc) | 1;
        }
        else {
          uVar10 = *(uint *)(local_70 + 0xc);
          if (iVar2 == 0) {
            uVar10 = *(uint *)(local_70 + 0xc) | 2;
          }
        }
        uVar10 = uVar10 | 4;
        uVar7 = (ulong)(uint)puVar3[5];
        *(uint *)(local_70 + 0xc) = uVar10;
      }
    }
    uVar9 = uVar10 >> 3 & 1;
  }
  if ((uVar7 & 0x4000) != 0) {
    uVar9 = (uVar9 + 1) - (uint)((*(uint *)((long)param_1 + 0x4c) & 2) == 0);
  }
  if ((uVar7 & 0x10000) != 0) {
    uVar9 = (uVar9 + 1) -
            (uint)((*(uint *)((long)param_1 + 0x4c) & 8) == 0 && (uVar7 & 0x100000) == 0);
  }
  iVar2 = puVar3[8];
  if ((iVar2 != 0) && (iVar2 < (int)puVar3[7])) {
    uVar9 = (uVar9 + 1) - (uint)((*(uint *)((long)param_1 + 0x4c) & 0xc) == 0);
    if ((*(uint *)((long)param_1 + 0x4c) & 2) != 0) {
      uVar9 = (uVar9 + 1) - (uint)((uVar7 & 1) == 0);
    }
    if ((uVar7 & 0xff0) != 0) {
      uVar9 = (uVar9 + 1) - (uint)((*(uint *)(local_70 + 0xc) & 3) == 0);
    }
    if (puVar3[7] == iVar2 + 1) {
      if (param_1[7] != 0) {
        __fprintf_chk(param_1[7],1,"<suppressed code=\"0x%06x\"/>\n",param_2);
      }
      __printf_chk(1,"...problem 0x%06x suppressed\n",*puVar3);
      fflush(stdout);
    }
  }
  pcVar4 = *(char **)(puVar3 + 2);
  if (*pcVar4 != '\0') {
    pcVar4 = (char *)dcgettext(0,pcVar4,5);
  }
  if (uVar9 == 0) {
    if (((*(byte *)((long)param_1 + 0x4c) & 2) == 0) || ((*(byte *)((long)puVar3 + 0x16) & 4) != 0))
    {
      cVar1 = *pcVar4;
    }
    else {
      lVar6 = param_1[3];
      if (lVar6 == 0) {
        lVar6 = param_1[2];
      }
      __printf_chk(1,&DAT_001783f4,lVar6);
      cVar1 = *pcVar4;
    }
    if (cVar1 != '\0') {
      print_e2fsck_message(stdout,param_1,pcVar4,param_3,1,0);
    }
  }
  if ((pcVar4 != (char *)0x0) && (param_1[5] != 0)) {
    print_e2fsck_message(param_1[5],param_1,pcVar4,param_3,1,0);
  }
  uVar10 = puVar3[5];
  if ((uVar10 & 1) == 0) {
    if (*(char *)(puVar3 + 4) != '\0') {
      preenhalt(param_1);
      uVar10 = puVar3[5];
      goto LAB_001374db;
    }
    if ((uVar10 & 0x1000) != 0) goto LAB_00137530;
LAB_00137390:
    if ((uVar10 & 0x8000) == 0) {
      if ((uVar10 & 0x2000) != 0) goto LAB_001374a5;
LAB_001374b6:
      if (uVar11 != 0) goto LAB_001373a8;
LAB_001374bf:
      uVar11 = 0;
      uVar5 = 0;
    }
    else {
      uVar11 = 0xffffffff;
      if ((uVar10 & 0x2000) != 0) {
LAB_001374a5:
        uVar11 = fix_problem(param_1,puVar3[6],param_3);
        goto LAB_001374b6;
      }
LAB_001373a8:
      cVar1 = *(char *)(puVar3 + 4);
LAB_001373ac:
      uVar5 = 0;
      if (cVar1 != '\0') {
        uVar10 = puVar3[5];
        goto LAB_001373b5;
      }
    }
  }
  else {
LAB_001374db:
    if ((uVar10 & 0x1000) != 0) {
LAB_00137530:
                    /* WARNING: Subroutine does not return */
      fatal_error(param_1,0);
    }
    cVar1 = *(char *)(puVar3 + 4);
    lVar6 = (long)cVar1;
    if (cVar1 == '\0') goto LAB_00137390;
    if ((uVar10 & 0x100000) != 0) {
LAB_00137448:
      if ((uVar10 & 2) == 0) {
        ext2fs_unmark_valid(uVar5);
      }
      if (uVar9 == 0) {
        uVar5 = dcgettext(0,"IGNORED",5);
        __printf_chk(1,&DAT_0017a4b2,uVar5);
        if (param_1[5] != 0) {
LAB_001379d9:
          uVar5 = dcgettext(0,"IGNORED",5);
          __fprintf_chk(param_1[5],1,&DAT_0017a4b2,uVar5);
        }
        if (*(char *)(puVar3 + 4) == '\v') goto LAB_0013749d;
        if ((*(byte *)((long)puVar3 + 0x15) & 0x20) != 0) goto LAB_001374a5;
      }
      else {
        if (param_1[5] != 0) goto LAB_001379d9;
LAB_0013749d:
        uVar10 = puVar3[5];
LAB_001374a0:
        if ((uVar10 & 0x2000) != 0) goto LAB_001374a5;
      }
      goto LAB_001374bf;
    }
    if ((*(byte *)((long)param_1 + 0x4c) & 2) == 0) {
      if (((uVar10 & 0xff0) != 0) && ((*(uint *)(local_70 + 0xc) & 3) != 0)) {
        if ((*(uint *)(local_70 + 0xc) & 1) != 0) goto LAB_001377dd;
        goto LAB_00137448;
      }
      puVar8 = &DAT_001782b4;
      if (cVar1 != '\x16') {
        puVar8 = (undefined *)dcgettext(0,(&PTR_s__no_prompt__001b0dc0)[lVar6],5);
      }
      uVar11 = ask(param_1,puVar8,uVar11);
      if (uVar11 == 0) {
        uVar10 = puVar3[5];
        goto LAB_00137514;
      }
      cVar1 = *(char *)(puVar3 + 4);
      if (cVar1 == '\v') goto LAB_00137aa6;
      if ((*(byte *)((long)puVar3 + 0x15) & 0x20) != 0) goto LAB_001374a5;
      goto LAB_001373ac;
    }
    if ((uVar10 & 0x4000) == 0) {
      if (uVar11 == 0) goto LAB_00137448;
LAB_001377dd:
      if (uVar9 == 0) {
        uVar5 = dcgettext(0,(&PTR_s__NONE__001b0d00)[lVar6],5);
        __printf_chk(1,&DAT_0017a4b2,uVar5);
        if (param_1[5] != 0) {
          lVar6 = (long)*(char *)(puVar3 + 4);
          goto LAB_00137822;
        }
      }
      else {
        if (param_1[5] == 0) {
          if (cVar1 == '\v') goto LAB_00137aa6;
          uVar11 = 1;
          goto joined_r0x00137a6f;
        }
LAB_00137822:
        uVar5 = dcgettext(0,(&PTR_s__NONE__001b0d00)[lVar6],5);
        __fprintf_chk(param_1[5],1,&DAT_0017a4b2,uVar5);
      }
      if (*(char *)(puVar3 + 4) == '\v') {
LAB_00137aa6:
                    /* WARNING: Subroutine does not return */
        fatal_error(param_1,0);
      }
      uVar11 = 1;
      if ((*(byte *)((long)puVar3 + 0x15) & 0x20) != 0) goto LAB_001374a5;
      goto LAB_001373a8;
    }
    if (uVar11 == 0) {
LAB_00137514:
      if ((uVar10 & 2) == 0) {
        ext2fs_unmark_valid(uVar5);
        goto LAB_0013749d;
      }
      goto LAB_001374a0;
    }
    if (cVar1 == '\v') goto LAB_00137aa6;
joined_r0x00137a6f:
    if ((uVar10 & 0x2000) != 0) goto LAB_001374a5;
LAB_001373b5:
    uVar5 = 0;
    if ((uVar10 & 0x200000) == 0) {
      *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 0x4000;
      uVar5 = 1;
    }
  }
  if (param_1[7] != 0) {
    FUN_00136dc0(param_1[7],param_2,uVar11,uVar5,puVar3[5],param_3);
  }
LAB_001373e3:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar11;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: end_problem_latch @ 0x37ae0

undefined8 end_problem_latch(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  long in_FS_OFFSET;
  undefined1 auStack_78 [104];
  long local_10;
  
  puVar4 = auStack_78;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = FUN_00136d70(param_2);
  uVar3 = *(uint *)(lVar1 + 0xc);
  if ((*(int *)(lVar1 + 8) == 0) || ((uVar3 & 4) == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    clear_problem_context(auStack_78);
    uVar2 = fix_problem(param_1,*(undefined4 *)(lVar1 + 8),puVar4);
    uVar3 = *(uint *)(lVar1 + 0xc);
  }
  *(uint *)(lVar1 + 0xc) = uVar3 & 0xfffffff0;
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: safe_print @ 0x37b60

void safe_print(FILE *param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  size_t sVar2;
  byte bVar3;
  
  if ((int)param_3 < 0) {
    sVar2 = strlen((char *)param_2);
    param_3 = (uint)sVar2;
  }
  if (param_3 != 0) {
    pbVar1 = param_2 + param_3;
    do {
      while( true ) {
        bVar3 = *param_2;
        param_2 = param_2 + 1;
        if (0x80 < bVar3) break;
        if (0x1f < bVar3) goto LAB_00137b95;
LAB_00137bd0:
        fputc(0x5e,param_1);
        fputc((uint)(bVar3 ^ 0x40),param_1);
        if (param_2 == pbVar1) {
          return;
        }
      }
      bVar3 = bVar3 + 0x80;
      fputs("M-",param_1);
      if (bVar3 < 0x20) goto LAB_00137bd0;
LAB_00137b95:
      if (bVar3 == 0x7f) goto LAB_00137bd0;
      fputc((uint)bVar3,param_1);
    } while (param_2 != pbVar1);
  }
  return;
}



// Function: print_pathname @ 0x37c00

void print_pathname(FILE *param_1,long param_2,int param_3,uint param_4)

{
  long lVar1;
  char *__s;
  long in_FS_OFFSET;
  undefined8 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_3 == 0) && (param_4 < 0xb)) {
    __s = (char *)dcgettext(0,(&PTR_s_<The_NULL_inode>_001b0e80)[param_4],5);
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      fputs(__s,param_1);
      return;
    }
    goto LAB_00137cc1;
  }
  if (param_2 == 0) {
LAB_00137c70:
    fputs("???",param_1);
  }
  else {
    lVar1 = ext2fs_get_pathname();
    if (lVar1 != 0) goto LAB_00137c70;
    FUN_00137b60(param_1,local_28,0xffffffff);
    ext2fs_free_mem(&local_28);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_00137cc1:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: print_time @ 0x37cd0

void print_time(undefined8 param_1,time_t param_2)

{
  tm *__tp;
  char *pcVar1;
  time_t local_10;
  
  local_10 = param_2;
  __tp = localtime(&local_10);
  pcVar1 = asctime(__tp);
  __fprintf_chk(param_1,1,"%.24s",pcVar1);
  return;
}



// Function: expand_dirent_expression @ 0x37d10

void expand_dirent_expression(undefined8 param_1,undefined8 param_2,char param_3,long param_4)

{
  int *piVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  long in_FS_OFFSET;
  uint local_34;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_4 == 0) || (piVar1 = *(int **)(param_4 + 0x20), piVar1 == (int *)0x0)) {
switchD_00137d57_caseD_6a:
    if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00137e7e;
    iVar4 = (int)param_3;
    pcVar5 = "%%D%c";
    goto LAB_00137d7e;
  }
  switch(param_3) {
  case 'i':
    if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00137e7e;
    iVar4 = *piVar1;
    pcVar5 = "%u";
    goto LAB_00137d7e;
  default:
    goto switchD_00137d57_caseD_6a;
  case 'l':
    iVar4 = ext2fs_dirent_name_len(piVar1);
    if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00137e7e;
    break;
  case 'n':
    uVar2 = ext2fs_dirent_name_len(piVar1);
    lVar3 = ext2fs_get_rec_len(param_2,piVar1,&local_34);
    if ((lVar3 == 0) && (local_34 < uVar2)) {
      uVar2 = local_34;
    }
    FUN_00137b60(param_1,piVar1 + 2,uVar2);
    goto LAB_00137dfa;
  case 'r':
    ext2fs_get_rec_len(param_2,piVar1,&local_34);
    __fprintf_chk(param_1,1,&DAT_00179651,local_34);
LAB_00137dfa:
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
LAB_00137e7e:
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  case 't':
    iVar4 = ext2fs_dirent_file_type(piVar1);
    if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00137e7e;
  }
  pcVar5 = "%u";
LAB_00137d7e:
  __fprintf_chk(param_1,1,pcVar5,iVar4);
  return;
}



// Function: expand_percent_expression @ 0x3d030

void expand_percent_expression(long param_1,int param_2,undefined8 param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  __pid_t _Var3;
  __uid_t __uid;
  tm *ptVar4;
  char *pcVar5;
  undefined *puVar6;
  char *pcVar7;
  int iVar8;
  long lVar9;
  long in_FS_OFFSET;
  passwd *local_1b0;
  passwd local_1a8;
  tm local_178;
  char local_138 [255];
  undefined1 local_39;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_1b0 = (passwd *)0x0;
  if (((byte)param_2 & 0xdf) == 0x44) {
LAB_0013d0e8:
    tzset();
    if ((*param_4 & 1) == 0) {
      ptVar4 = localtime_r((time_t *)(param_1 + 0x348),&local_178);
    }
    else {
      ptVar4 = gmtime_r((time_t *)(param_1 + 0x348),&local_178);
    }
  }
  else {
    ptVar4 = (tm *)0x0;
    if (((byte)(param_2 - 0x48U) < 0x32) &&
       ((0x2002000021821U >> ((ulong)(param_2 - 0x48U) & 0x3f) & 1) != 0)) goto LAB_0013d0e8;
  }
  switch(param_2 - 0x25U & 0xff) {
  case 0:
    FUN_0013cfa0(param_3,&DAT_0017f54b,1);
    goto LAB_0013d0bd;
  default:
    goto LAB_0013d0b0;
  case 0x1f:
    iVar2 = ptVar4->tm_mday;
    iVar8 = ptVar4->tm_mon + 1;
    iVar1 = ptVar4->tm_year + 0x76c;
    pcVar7 = "%d%02d%02d";
    goto LAB_0013d1b8;
  case 0x23:
    iVar8 = ptVar4->tm_hour;
    puVar6 = &DAT_0017f553;
    break;
  case 0x28:
    iVar8 = ptVar4->tm_min;
    puVar6 = &DAT_0017f553;
    break;
  case 0x29:
    pcVar7 = *(char **)(param_1 + 0x10);
    pcVar5 = strrchr(pcVar7,0x2f);
    if (pcVar5 != (char *)0x0) {
      pcVar7 = pcVar5 + 1;
    }
    FUN_0013cfa0(param_3,pcVar7,0);
    goto LAB_0013d0bd;
  case 0x2e:
    iVar8 = ptVar4->tm_sec;
    puVar6 = &DAT_0017f553;
    break;
  case 0x2f:
    iVar8 = ptVar4->tm_min;
    iVar1 = ptVar4->tm_hour;
    iVar2 = ptVar4->tm_sec;
    pcVar7 = "%02d%02d%02d";
LAB_0013d1b8:
    __sprintf_chk(local_138,1,0x100,pcVar7,iVar1,iVar8,iVar2);
    goto LAB_0013d0b0;
  case 0x30:
    *param_4 = *param_4 | 1;
    goto LAB_0013d0bd;
  case 0x34:
    puVar6 = &DAT_0017adb6;
    iVar8 = ptVar4->tm_year + 0x76c;
    break;
  case 0x3f:
    iVar8 = ptVar4->tm_mday;
    puVar6 = &DAT_0017f553;
    break;
  case 0x43:
    local_138[0] = '\0';
    gethostname(local_138,0x100);
    local_39 = 0;
    goto LAB_0013d0b0;
  case 0x48:
    puVar6 = &DAT_0017f553;
    iVar8 = ptVar4->tm_mon + 1;
    break;
  case 0x4b:
    _Var3 = getpid();
    lVar9 = (long)_Var3;
    goto LAB_0013d340;
  case 0x4e:
    lVar9 = *(long *)(param_1 + 0x348);
LAB_0013d340:
    __sprintf_chk(local_138,1,0x100,"%lu",lVar9);
    goto LAB_0013d0b0;
  case 0x50:
    __uid = getuid();
    getpwuid_r(__uid,&local_1a8,local_138,0x100,&local_1b0);
    if (local_1b0 != (passwd *)0x0) {
      FUN_0013cfa0(param_3,local_1b0->pw_name,0);
    }
    goto LAB_0013d0bd;
  case 0x54:
    puVar6 = &DAT_0017f553;
    iVar8 = ptVar4->tm_year % 100;
  }
  __sprintf_chk(local_138,1,0x100,puVar6,iVar8);
LAB_0013d0b0:
  FUN_0013cfa0(param_3,local_138,0);
LAB_0013d0bd:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: expand_inode_expression @ 0x382d0

void expand_inode_expression(FILE *param_1,long param_2,char param_3,long param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  char *pcVar6;
  ushort *puVar7;
  
  if ((param_4 == 0) || (puVar7 = *(ushort **)(param_4 + 0x18), puVar7 == (ushort *)0x0)) {
switchD_00138302_caseD_47:
    uVar4 = (uint)param_3;
    pcVar6 = "%%I%c";
    goto LAB_00138312;
  }
  switch(param_3) {
  case 'F':
    uVar4 = *(uint *)(puVar7 + 0x38);
    pcVar6 = "%u";
    break;
  default:
    goto switchD_00138302_caseD_47;
  case 'M':
    FUN_00137cd0(param_1,*(undefined4 *)(puVar7 + 8));
    return;
  case 'S':
    uVar4 = (uint)puVar7[0x40];
    pcVar6 = "%u";
    break;
  case 'b':
    iVar3 = FUN_001382c0(*(undefined4 *)(*(long *)(param_2 + 0x20) + 100));
    uVar4 = *(uint *)(puVar7 + 0xe);
    if (iVar3 != 0) {
      uVar5 = (ulong)CONCAT24(puVar7[0x3a],uVar4);
      goto LAB_001383fd;
    }
    goto LAB_00138483;
  case 'd':
    uVar4 = 0;
    if ((*puVar7 & 0xf000) == 0x4000) {
      uVar4 = *(uint *)(puVar7 + 0x36);
    }
LAB_00138483:
    pcVar6 = "%u";
    break;
  case 'f':
    uVar5 = ext2fs_file_acl_block();
    goto LAB_001383fd;
  case 'g':
    pcVar6 = "%d";
    uVar4 = CONCAT22(puVar7[0x3d],puVar7[0xc]);
    break;
  case 'l':
    uVar4 = (uint)puVar7[0xd];
    pcVar6 = "%d";
    break;
  case 'm':
    uVar4 = (uint)*puVar7;
    pcVar6 = "0%o";
    break;
  case 's':
    uVar5 = CONCAT44(*(undefined4 *)(puVar7 + 0x36),*(undefined4 *)(puVar7 + 2));
LAB_001383fd:
    __fprintf_chk(param_1,1,&DAT_00186df0,uVar5);
    return;
  case 't':
    uVar1 = *puVar7;
    pcVar6 = "regular file";
    uVar2 = uVar1 & 0xf000;
    if ((((uVar2 != 0x8000) && (pcVar6 = "directory", uVar2 != 0x4000)) &&
        (pcVar6 = "character device", uVar2 != 0x2000)) &&
       (((pcVar6 = "block device", uVar2 != 0x6000 && (pcVar6 = "named pipe", uVar2 != 0x1000)) &&
        (pcVar6 = "symbolic link", uVar2 != 0xa000)))) {
      if (uVar2 != 0xc000) {
        pcVar6 = (char *)dcgettext(0,"unknown file type with mode 0%o",5);
        uVar4 = (uint)uVar1;
        break;
      }
      pcVar6 = "socket";
    }
    pcVar6 = (char *)dcgettext(0,pcVar6,5);
    fputs(pcVar6,param_1);
    return;
  case 'u':
    pcVar6 = "%d";
    uVar4 = CONCAT22(puVar7[0x3c],puVar7[1]);
  }
LAB_00138312:
  __fprintf_chk(param_1,1,pcVar6,uVar4);
  return;
}



// Function: print_e2fsck_message @ 0x38530

void print_e2fsck_message
               (undefined8 param_1,undefined8 *param_2,char *param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6)

{
  char *pcVar1;
  undefined8 uVar2;
  ulong uVar3;
  char cVar4;
  ushort **ppuVar5;
  int iVar6;
  ulong uVar7;
  char *pcVar8;
  ulong uVar9;
  undefined4 local_3c [3];
  
  uVar2 = *param_2;
  local_3c[0] = param_5;
  e2fsck_clear_progbar(param_2);
  cVar4 = *param_3;
  do {
    if (cVar4 == '\0') {
      return;
    }
    if (cVar4 == '@') {
      pcVar1 = param_3 + 1;
      pcVar8 = param_3 + 1;
      param_3 = param_3 + 2;
      FUN_00138700(param_1,param_2,(int)*pcVar1,param_4,local_3c,param_6);
    }
    else if (cVar4 == '%') {
      ppuVar5 = __ctype_b_loc();
      iVar6 = 0;
      pcVar8 = param_3 + 1;
      while( true ) {
        cVar4 = *pcVar8;
        pcVar1 = pcVar8 + 1;
        if ((*(byte *)((long)*ppuVar5 + (long)cVar4 * 2 + 1) & 8) == 0) break;
        iVar6 = cVar4 + -0x30 + iVar6 * 10;
        pcVar8 = pcVar1;
      }
      if (cVar4 == 'I') {
        param_3 = pcVar8 + 2;
        FUN_001382d0(param_1,uVar2,(int)pcVar8[1],param_4);
        pcVar8 = pcVar1;
      }
      else if (cVar4 == 'D') {
        param_3 = pcVar8 + 2;
        FUN_00137d10(param_1,uVar2,(int)pcVar8[1],param_4);
        pcVar8 = pcVar1;
      }
      else {
        FUN_00137eb0(param_1,uVar2,(int)cVar4,iVar6,local_3c,param_4);
        param_3 = pcVar1;
      }
    }
    else {
      cVar4 = *param_3;
      uVar3 = 0;
      if (cVar4 == '\0') {
        uVar9 = 0xffffffffffffffff;
        uVar7 = 0;
      }
      else {
        do {
          uVar9 = uVar3;
          uVar7 = uVar9 & 0xffffffff;
          if ((cVar4 == '@') || (cVar4 == '%')) {
            uVar9 = uVar9 - 1;
            break;
          }
          cVar4 = param_3[uVar9 + 1];
          uVar7 = (ulong)((int)uVar9 + 1);
          uVar3 = uVar9 + 1;
        } while (cVar4 != '\0');
      }
      __fprintf_chk(param_1,1,&DAT_0017ec9c,uVar7,param_3);
      pcVar8 = param_3 + uVar9;
      param_3 = param_3 + uVar9 + 1;
    }
    cVar4 = pcVar8[1];
    local_3c[0] = 0;
  } while( true );
}



// Function: expand_at_expression @ 0x38700

void expand_at_expression(FILE *param_1,undefined8 param_2,char param_3,undefined8 param_4,int *param_5,
                 int param_6)

{
  undefined **ppuVar1;
  long lVar2;
  ushort **ppuVar3;
  __int32_t **pp_Var4;
  long lVar5;
  char *pcVar6;
  int iVar7;
  
  if (PTR_s_aextended_attribute_001b5f20 != (undefined *)0x0) {
    ppuVar1 = &PTR_s_aextended_attribute_001b5f20;
    pcVar6 = PTR_s_aextended_attribute_001b5f20;
    do {
      if (*pcVar6 == param_3) {
        if (param_6 < 10) {
          lVar2 = dcgettext(0,pcVar6,5);
          iVar7 = *param_5;
          lVar5 = lVar2 + 1;
          if (iVar7 != 0) {
            ppuVar3 = __ctype_b_loc();
            if ((*(byte *)((long)*ppuVar3 + (long)*(char *)(lVar2 + 1) * 2 + 1) & 2) != 0) {
              *param_5 = 0;
              pp_Var4 = __ctype_toupper_loc();
              lVar5 = lVar2 + 2;
              fputc((*pp_Var4)[*(char *)(lVar2 + 1)],param_1);
              iVar7 = *param_5;
            }
          }
          print_e2fsck_message(param_1,param_2,lVar5,param_4,iVar7,param_6 + 1);
          return;
        }
        break;
      }
      pcVar6 = ppuVar1[1];
      ppuVar1 = ppuVar1 + 1;
    } while (pcVar6 != (char *)0x0);
  }
  __fprintf_chk(param_1,1,&DAT_0017eca1,(int)param_3);
  return;
}



// Function: move_quota_inode @ 0x38860

long move_quota_inode(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  long in_FS_OFFSET;
  byte bVar6;
  undefined2 local_d8 [13];
  undefined2 local_be;
  int local_b8;
  undefined1 local_58 [24];
  long local_40;
  
  bVar6 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = ext2fs_read_bitmaps();
  if (lVar2 == 0) {
    lVar2 = ext2fs_read_inode(param_1,param_2,local_d8);
    if (lVar2 == 0) {
      local_be = 1;
      local_d8[0] = 0x8180;
      iVar1 = FUN_00138850(*(undefined4 *)(*(long *)(param_1 + 0x20) + 0x60),param_3,local_d8);
      local_b8 = (-(uint)(iVar1 == 0) & 0xfff80000) + 0x80010;
      lVar2 = ext2fs_write_new_inode(param_1);
      if (lVar2 == 0) {
        quota_get_qf_name(param_4,4,local_58);
        lVar2 = ext2fs_unlink(param_1,2,local_58,param_2,0);
        if (lVar2 == 0) {
          ext2fs_inode_alloc_stats(param_1,param_2,0xffffffff);
          puVar5 = (undefined8 *)local_d8;
          for (lVar4 = 0x10; lVar4 != 0; lVar4 = lVar4 + -1) {
            *puVar5 = 0;
            puVar5 = puVar5 + (ulong)bVar6 * -2 + 1;
          }
          ext2fs_write_inode(param_1,param_2,local_d8);
        }
        else {
          uVar3 = dcgettext(0,"in move_quota_inode",5);
          com_err("ext2fs_unlink",lVar2,&DAT_00178907,uVar3);
        }
      }
      else {
        uVar3 = dcgettext(0,"in move_quota_inode",5);
        com_err("ext2fs_write_new_inode",lVar2,&DAT_00178907,uVar3);
      }
    }
    else {
      uVar3 = dcgettext(0,"in move_quota_inode",5);
      com_err("ext2fs_read_inode",lVar2,&DAT_00178907,uVar3);
    }
  }
  else {
    uVar3 = dcgettext(0,"in move_quota_inode",5);
    com_err("ext2fs_read_bitmaps",lVar2,&DAT_00178907,uVar3);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_hide_quota @ 0x38a90

void e2fsck_hide_quota(long *param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  long lVar6;
  ulong uVar7;
  long in_FS_OFFSET;
  undefined1 local_a8 [8];
  int local_a0;
  undefined4 local_98;
  ulong local_58;
  long local_40;
  
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = *(long *)(lVar1 + 0x20);
  clear_problem_context();
  if ((*(byte *)((long)param_1 + 0x4c) & 1) == 0) {
    iVar3 = FUN_00138a80(*(undefined4 *)(lVar2 + 100));
    if (iVar3 != 0) {
      uVar7 = 0;
      do {
        local_98 = 2;
        piVar5 = (int *)FUN_00138820(lVar2,uVar7 & 0xffffffff);
        local_a0 = *piVar5;
        local_58 = uVar7;
        iVar3 = quota_type2inum(uVar7 & 0xffffffff,*(undefined8 *)(lVar1 + 0x20));
        if ((local_a0 != iVar3) && (local_a0 != 0)) {
          iVar4 = fix_problem(param_1,0x41,local_a8);
          if (iVar4 != 0) {
            lVar6 = FUN_00138860(lVar1,local_a0,iVar3,uVar7 & 0xffffffff);
            if (lVar6 == 0) {
              *piVar5 = iVar3;
              ext2fs_mark_super_dirty(lVar1);
            }
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 != 3);
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_validate_quota_inodes @ 0x38ba0

void e2fsck_validate_quota_inodes(long *param_1)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  uint *puVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  undefined1 auStack_a8 [8];
  uint local_a0;
  ulong local_58;
  long local_40;
  
  uVar5 = 0;
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = *(undefined8 *)(lVar1 + 0x20);
  clear_problem_context(auStack_a8);
  do {
    puVar4 = (uint *)FUN_00138820(uVar2,uVar5 & 0xffffffff);
    local_a0 = *puVar4;
    local_58 = uVar5;
    if (((local_a0 != 0) &&
        (((local_a0 - 1 < 2 || (local_a0 - 5 < 6)) || (**(uint **)(lVar1 + 0x20) < local_a0)))) &&
       (iVar3 = fix_problem(param_1,0x4f,auStack_a8), iVar3 != 0)) {
      *puVar4 = 0;
      ext2fs_mark_super_dirty(lVar1);
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 != 3);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: jbd2_descriptor_block_csum_verify @ 0x38c70

bool jbd2_descriptor_block_csum_verify(long param_1,long param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  iVar3 = jbd2_journal_has_csum_v2or3();
  bVar5 = true;
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 0x78);
    uVar4 = *(undefined4 *)(param_1 + 0xc4);
    piVar1 = (int *)(param_2 + -4 + (long)iVar3);
    iVar2 = *piVar1;
    *piVar1 = 0;
    uVar4 = jbd2_chksum(param_1,uVar4,param_2,(long)iVar3);
    *piVar1 = iVar2;
    iVar3 = ext2fs_swab32(uVar4);
    bVar5 = iVar3 == iVar2;
  }
  return bVar5;
}



// Function: read_tag_block @ 0x38ce0

ulong read_tag_block(undefined8 param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  
  uVar1 = ext2fs_swab32(*param_2);
  uVar4 = (ulong)uVar1;
  iVar2 = jbd2_has_feature_64bit(param_1);
  if (iVar2 != 0) {
    lVar3 = ext2fs_swab32(param_2[2]);
    uVar4 = uVar4 | lVar3 << 0x20;
  }
  return uVar4;
}



// Function: jbd2_commit_block_csum_verify @ 0x38d20

bool jbd2_commit_block_csum_verify(long param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  iVar1 = jbd2_journal_has_csum_v2or3();
  bVar4 = true;
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_2 + 0x10);
    uVar2 = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(param_2 + 0x10) = 0;
    uVar2 = jbd2_chksum(param_1,*(undefined4 *)(param_1 + 0xc4),param_2,uVar2);
    *(int *)(param_2 + 0x10) = iVar1;
    iVar3 = ext2fs_swab32(uVar2);
    bVar4 = iVar3 == iVar1;
  }
  return bVar4;
}



// Function: jbd2_block_tag_csum_verify @ 0x38d80

bool jbd2_block_tag_csum_verify(long param_1,long param_2,long param_3,undefined8 param_4,undefined4 param_5)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  long in_FS_OFFSET;
  bool bVar5;
  undefined4 local_34;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  iVar2 = jbd2_journal_has_csum_v2or3();
  bVar5 = true;
  if (iVar2 != 0) {
    local_34 = ext2fs_swab32(param_5);
    uVar3 = jbd2_chksum(param_1,*(undefined4 *)(param_1 + 0xc4),&local_34,4);
    uVar4 = jbd2_chksum(param_1,uVar3,param_4,*(undefined4 *)(param_1 + 0x78));
    iVar2 = jbd2_has_feature_csum3(param_1);
    if (iVar2 == 0) {
      sVar1 = ext2fs_swab16(uVar4 & 0xffff);
      bVar5 = *(short *)(param_2 + 4) == sVar1;
    }
    else {
      iVar2 = ext2fs_swab32(uVar4);
      bVar5 = *(int *)(param_3 + 0xc) == iVar2;
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: scan_revoke_records @ 0x38e60

undefined8 scan_revoke_records(long param_1,long param_2,undefined4 param_3,long param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  
  uVar3 = ext2fs_swab32(*(undefined4 *)(param_2 + 0x34));
  iVar4 = jbd2_journal_has_csum_v2or3(param_1);
  if (*(int *)(param_1 + 0x78) + (uint)(iVar4 != 0) * -4 < uVar3) {
    uVar7 = 0xffffffea;
  }
  else {
    iVar4 = jbd2_has_feature_64bit(param_1);
    uVar8 = -(uint)(iVar4 == 0) & 0xfffffffc;
    iVar9 = uVar8 + 8;
    iVar2 = uVar8 + 0x18;
    iVar4 = 0x10;
    while( true ) {
      iVar1 = iVar2;
      if ((int)uVar3 < iVar1) {
        return 0;
      }
      puVar6 = (undefined8 *)((long)iVar4 + param_2 + 0x28);
      if (iVar9 == 4) {
        uVar5 = ext2fs_swab32(*(undefined4 *)puVar6);
        uVar7 = jbd2_journal_set_revoke(param_1,uVar5,param_3);
        iVar4 = (int)uVar7;
      }
      else {
        uVar7 = ext2fs_swab64(*puVar6);
        uVar7 = jbd2_journal_set_revoke(param_1,uVar7,param_3);
        iVar4 = (int)uVar7;
      }
      if (iVar4 != 0) break;
      *(int *)(param_4 + 0xc) = *(int *)(param_4 + 0xc) + 1;
      iVar2 = iVar1 + iVar9;
      iVar4 = iVar1;
    }
  }
  return uVar7;
}



// Function: jread @ 0x38f60

int jread(long *param_1,long param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long in_FS_OFFSET;
  undefined8 local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  *param_1 = 0;
  if (param_3 < *(uint *)(param_2 + 0x80)) {
    iVar1 = jbd2_journal_bmap(param_2,param_3,&local_38);
    if (iVar1 == 0) {
      lVar3 = getblk(*(undefined8 *)(param_2 + 0x68),local_38,*(undefined4 *)(param_2 + 0x78));
      if (lVar3 == 0) {
        iVar1 = -0xc;
      }
      else {
        iVar2 = buffer_uptodate(lVar3);
        if (iVar2 == 0) {
          wait_on_buffer(lVar3);
        }
        iVar2 = buffer_uptodate(lVar3);
        if (iVar2 == 0) {
          iVar1 = -5;
          __printf_chk(1,"JBD2: Failed to read block at offset %u\n",param_3);
          brelse(lVar3);
        }
        else {
          *param_1 = lVar3;
        }
      }
    }
    else {
      __printf_chk(1,"JBD2: bad block at offset %u\n",param_3);
    }
  }
  else {
    iVar1 = -0x7f2bb7ae;
    __printf_chk(1,"JBD2: corrupted journal superblock\n");
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: count_tags @ 0x39090

int count_tags(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  undefined8 *puVar8;
  long in_FS_OFFSET;
  
  puVar8 = (undefined8 *)(param_2 + 0x34);
  iVar1 = *(int *)(param_1 + 0x78);
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  iVar5 = journal_tag_bytes();
  iVar6 = jbd2_journal_has_csum_v2or3(param_1);
  if (iVar6 != 0) {
    iVar1 = iVar1 + -4;
  }
  iVar6 = 0;
  do {
    if ((long)iVar1 < (long)puVar8 + ((long)iVar5 - (param_2 + 0x28))) break;
    uVar3 = *puVar8;
    iVar6 = iVar6 + 1;
    puVar8 = (undefined8 *)((long)puVar8 + (long)iVar5);
    uVar4 = ext2fs_swab16(2);
    uVar7 = (ushort)((ulong)uVar3 >> 0x30);
    if ((uVar7 & uVar4) == 0) {
      puVar8 = puVar8 + 2;
    }
    uVar4 = ext2fs_swab16(8);
  } while ((uVar7 & uVar4) == 0);
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: calc_chksums @ 0x39170

undefined8 calc_chksums(long param_1,long param_2,ulong *param_3,undefined4 *param_4)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  int iVar8;
  long in_FS_OFFSET;
  long local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = FUN_00139090();
  uVar4 = ext2fs_crc32_be(*param_4,param_2 + 0x28,(long)*(int *)(param_2 + 0x10));
  *param_4 = uVar4;
  if (0 < iVar3) {
    iVar8 = 0;
    do {
      uVar2 = *param_3;
      uVar1 = uVar2 + 1;
      *param_3 = uVar1;
      iVar5 = jbd2_has_feature_fast_commit(param_1);
      if (iVar5 == 0) {
        uVar6 = *(ulong *)(param_1 + 0x60);
      }
      else {
        uVar6 = *(ulong *)(param_1 + 0x48);
      }
      if (uVar6 <= uVar1) {
        *param_3 = (*(long *)(param_1 + 0x58) + uVar1) - uVar6;
      }
      iVar5 = FUN_00138f60(&local_48,param_1,uVar2 & 0xffffffff);
      if (iVar5 != 0) {
        __printf_chk(1,"JBD2: IO error %d recovering block %lu in log\n",iVar5,uVar2);
        uVar7 = 1;
        goto LAB_0013924a;
      }
      iVar8 = iVar8 + 1;
      uVar4 = ext2fs_crc32_be(*param_4,local_48 + 0x28,(long)*(int *)(local_48 + 0x10));
      *param_4 = uVar4;
      brelse(local_48);
    } while (iVar3 != iVar8);
  }
  uVar7 = 0;
LAB_0013924a:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: do_one_pass @ 0x39340

int do_one_pass(long param_1,int *param_2,int param_3)

{
  long lVar1;
  bool bVar2;
  bool bVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined8 uVar13;
  long lVar14;
  ulong uVar15;
  undefined8 *puVar16;
  long in_FS_OFFSET;
  int local_c0;
  ulong local_b8;
  int local_b0;
  int local_6c;
  ulong local_68;
  long local_60;
  long local_58;
  undefined8 local_4c;
  undefined4 local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar5 = journal_tag_bytes();
  lVar1 = *(long *)(param_1 + 0x18);
  local_6c = -1;
  iVar6 = ext2fs_swab32(*(undefined4 *)(lVar1 + 0x18));
  uVar7 = ext2fs_swab32(*(undefined4 *)(lVar1 + 0x1c));
  local_68 = (ulong)uVar7;
  if (param_3 == 0) {
    *param_2 = iVar6;
  }
  local_b8 = 0;
  bVar3 = false;
  bVar2 = false;
  local_b0 = 0;
  local_c0 = 0;
LAB_001393ce:
  if (param_3 == 0) goto LAB_001393e8;
LAB_001393d3:
  iVar9 = param_2[1];
  iVar8 = tid_geq(iVar6,iVar9);
  if (iVar8 == 0) {
LAB_001393e8:
    do {
      uVar15 = local_68;
      iVar9 = FUN_00138f60(&local_60,param_1,local_68 & 0xffffffff);
      if (iVar9 != 0) goto LAB_001394d5;
      uVar15 = uVar15 + 1;
      local_68 = uVar15;
      iVar9 = jbd2_has_feature_fast_commit(param_1);
      lVar1 = local_60;
      if (iVar9 == 0) {
        uVar11 = *(ulong *)(param_1 + 0x60);
      }
      else {
        uVar11 = *(ulong *)(param_1 + 0x48);
      }
      if (uVar11 <= uVar15) {
        local_68 = (uVar15 + *(long *)(param_1 + 0x58)) - uVar11;
      }
      iVar9 = ext2fs_swab32(0xc03b3998);
      if (*(int *)(lVar1 + 0x28) != iVar9) {
LAB_001397f8:
        brelse(lVar1);
        iVar9 = param_2[1];
        break;
      }
      iVar9 = ext2fs_swab32(*(undefined4 *)(lVar1 + 0x2c));
      iVar8 = ext2fs_swab32(*(undefined4 *)(lVar1 + 0x30));
      if (iVar6 != iVar8) goto LAB_001397f8;
      if (iVar9 != 2) {
        if (iVar9 == 5) {
          if (param_3 == 0) {
            iVar9 = FUN_00138c70(param_1,lVar1 + 0x28);
            if (iVar9 == 0) {
              bVar3 = true;
            }
          }
          else if (param_3 == 1) {
            iVar9 = FUN_00138e60(param_1,lVar1,iVar6,param_2);
            brelse(lVar1);
            if (iVar9 == 0) goto LAB_001393d3;
            goto LAB_001394d5;
          }
        }
        else {
          if (iVar9 != 1) goto LAB_0013948e;
          iVar9 = jbd2_journal_has_csum_v2or3(param_1);
          if (iVar9 == 0) {
            if ((local_b0 == 0) || (iVar9 = FUN_00138c70(param_1,lVar1 + 0x28), iVar9 != 0))
            goto LAB_0013970c;
LAB_00139548:
            if (param_3 != 0) {
              brelse(lVar1);
              iVar9 = -0x7f2bb7af;
              goto LAB_001394d5;
            }
            bVar3 = true;
          }
          else {
            local_b0 = 4;
            iVar9 = FUN_00138c70(param_1,lVar1 + 0x28);
            if (iVar9 == 0) goto LAB_00139548;
LAB_0013970c:
            if (param_3 == 2) goto LAB_00139818;
            if ((param_3 == 0) && (iVar9 = jbd2_has_feature_checksum(param_1), iVar9 != 0 && !bVar3)
               ) {
              if (param_2[1] == 0) {
                iVar9 = FUN_00139170(param_1,lVar1,&local_68,&local_6c);
                if (iVar9 != 0) goto LAB_00139761;
                brelse(lVar1);
                bVar3 = false;
                goto LAB_001393e8;
              }
              bVar3 = false;
            }
          }
          iVar9 = FUN_00139090(param_1,lVar1);
          uVar15 = (long)iVar9 + local_68;
          local_68 = uVar15;
          iVar9 = jbd2_has_feature_fast_commit(param_1);
          if (iVar9 == 0) {
            uVar11 = *(ulong *)(param_1 + 0x60);
          }
          else {
            uVar11 = *(ulong *)(param_1 + 0x48);
          }
          if (uVar11 <= uVar15) {
            local_68 = (uVar15 + *(long *)(param_1 + 0x58)) - uVar11;
          }
        }
        brelse(lVar1);
        goto LAB_001393ce;
      }
      uVar15 = ext2fs_swab64(*(undefined8 *)(lVar1 + 0x58));
      if (bVar3) {
        if (uVar15 < local_b8) {
LAB_0013948e:
          brelse(lVar1);
          iVar9 = param_2[1];
          break;
        }
        brelse(lVar1);
        iVar9 = -0x7f2bb7af;
        goto LAB_001394d5;
      }
      uVar11 = local_b8;
      if (param_3 != 0) {
LAB_001396dd:
        local_b8 = uVar11;
        iVar6 = iVar6 + 1;
        brelse(lVar1);
        goto LAB_001393ce;
      }
      iVar9 = jbd2_has_feature_checksum(param_1);
      uVar11 = uVar15;
      if (iVar9 == 0) {
LAB_00139648:
        iVar9 = FUN_00138d20(param_1,lVar1 + 0x28);
        if (iVar9 != 0) goto LAB_001396dd;
LAB_0013965c:
        if (uVar15 < local_b8) goto LAB_0013948e;
        param_2[1] = iVar6;
        iVar9 = jbd2_has_feature_async_commit(param_1);
        if (iVar9 != 0) goto LAB_001396dd;
        *(int *)(param_1 + 0xc0) = iVar6;
        brelse(lVar1);
      }
      else {
        iVar9 = ext2fs_swab32(*(undefined4 *)(lVar1 + 0x38));
        if (param_2[1] == 0) {
          if (((local_6c == iVar9) && (*(short *)(lVar1 + 0x34) == 0x401)) ||
             ((*(short *)(lVar1 + 0x34) == 0 && (iVar9 == 0)))) {
            local_6c = -1;
            goto LAB_00139648;
          }
          goto LAB_0013965c;
        }
        *(int *)(param_1 + 0xc0) = param_2[1];
LAB_00139761:
        brelse(lVar1);
      }
      bVar3 = false;
    } while( true );
  }
  if (param_3 == 0) {
    if (iVar9 == 0) {
      param_2[1] = iVar6;
    }
    iVar5 = jbd2_has_feature_fast_commit(param_1);
    if (iVar5 != 0) goto LAB_001396b8;
  }
  else {
    if (iVar6 == iVar9) {
      iVar5 = jbd2_has_feature_fast_commit(param_1);
      if ((iVar5 == 0) || (param_3 == 1)) goto LAB_001394bb;
    }
    else {
      __printf_chk(1,"JBD2: recovery pass %d ended at transaction %u, expected %u\n",param_3,iVar6,
                   iVar9);
      iVar9 = -5;
      if (local_c0 != 0) {
        iVar9 = local_c0;
      }
      iVar5 = jbd2_has_feature_fast_commit(param_1);
      if ((iVar5 == 0) || (local_c0 = iVar9, param_3 == 1)) goto LAB_001394d5;
    }
LAB_001396b8:
    iVar9 = FUN_001392a0(param_1,param_2[1],param_3);
    if (iVar9 != 0) goto LAB_001394d5;
  }
LAB_001394bb:
  iVar9 = local_c0;
  if ((local_c0 == 0) && (iVar9 = -5, !bVar2)) {
    iVar9 = local_c0;
  }
LAB_001394d5:
  local_c0 = iVar9;
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_c0;
LAB_00139818:
  puVar16 = (undefined8 *)(lVar1 + 0x34);
  do {
    if ((long)(*(int *)(param_1 + 0x78) - local_b0) < (long)puVar16 + ((long)iVar5 - (lVar1 + 0x28))
       ) break;
    local_44 = *(undefined4 *)(puVar16 + 1);
    local_4c._6_2_ = (undefined2)((ulong)*puVar16 >> 0x30);
    uVar4 = local_4c._6_2_;
    local_4c = *puVar16;
    uVar7 = ext2fs_swab16(uVar4);
    uVar11 = local_68;
    uVar15 = local_68 + 1;
    local_68 = uVar15;
    iVar9 = jbd2_has_feature_fast_commit(param_1);
    if (iVar9 == 0) {
      uVar12 = *(ulong *)(param_1 + 0x60);
    }
    else {
      uVar12 = *(ulong *)(param_1 + 0x48);
    }
    if (uVar12 <= uVar15) {
      local_68 = (uVar15 + *(long *)(param_1 + 0x58)) - uVar12;
    }
    iVar9 = FUN_00138f60(&local_58,param_1,uVar11 & 0xffffffff);
    if (iVar9 == 0) {
      if (local_58 == 0) {
        __printf_chk(1,"Assertion failure in %s() at %s line %d: \"%s\"\n","do_one_pass",
                     "recovery.c",0x279,"obh != NULL");
                    /* WARNING: Subroutine does not return */
        fatal_error(e2fsck_global_ctx,0);
      }
      uVar13 = FUN_00138ce0(param_1,&local_4c);
      iVar9 = jbd2_journal_test_revoke(param_1,uVar13,iVar6);
      if (iVar9 == 0) {
        uVar10 = ext2fs_swab32(*(undefined4 *)(lVar1 + 0x30));
        iVar9 = FUN_00138d80(param_1,&local_4c,puVar16,local_58 + 0x28,uVar10);
        if (iVar9 == 0) {
          brelse(local_58);
          __printf_chk(1,"JBD2: Invalid checksum recovering data block %llu in log\n",uVar13);
          bVar2 = true;
          local_c0 = -0x7f2bb7af;
        }
        else {
          lVar14 = getblk(*(undefined8 *)(param_1 + 0x70),uVar13,*(undefined4 *)(param_1 + 0x78));
          if (lVar14 == 0) {
            __printf_chk(1,"JBD2: Out of memory during recovery.\n");
            brelse(lVar1);
            brelse(local_58);
            iVar9 = -0xc;
            goto LAB_001394d5;
          }
          memcpy((void *)(lVar14 + 0x28),(void *)(local_58 + 0x28),(long)*(int *)(param_1 + 0x78));
          if ((uVar7 & 1) != 0) {
            uVar10 = ext2fs_swab32(0xc03b3998);
            *(undefined4 *)(lVar14 + 0x28) = uVar10;
          }
          mark_buffer_uptodate(lVar14,1);
          mark_buffer_dirty(lVar14);
          param_2[2] = param_2[2] + 1;
          brelse(local_58);
          brelse(lVar14);
        }
      }
      else {
        brelse(local_58);
        param_2[4] = param_2[4] + 1;
      }
    }
    else {
      __printf_chk(1,"JBD2: IO error %d recovering block %ld in log\n",iVar9,uVar11);
      local_c0 = iVar9;
    }
    puVar16 = (undefined8 *)((long)puVar16 + (long)iVar5);
    if ((uVar7 & 2) == 0) {
      puVar16 = puVar16 + 2;
    }
  } while ((uVar7 & 8) == 0);
  brelse(lVar1);
  goto LAB_001393d3;
}



// Function: jbd2_journal_recover @ 0x39b80

int jbd2_journal_recover(long param_1)

{
  int iVar1;
  int iVar2;
  long in_FS_OFFSET;
  undefined1 local_38 [16];
  undefined4 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = 0;
  local_38 = (undefined1  [16])0x0;
  if (*(int *)(*(long *)(param_1 + 0x18) + 0x1c) == 0) {
    iVar1 = ext2fs_swab32(*(undefined4 *)(*(long *)(param_1 + 0x18) + 0x18));
    *(int *)(param_1 + 0x94) = iVar1 + 1;
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00139340(param_1,local_38,0);
    if ((iVar1 == 0) && (iVar1 = FUN_00139340(param_1,local_38,1), iVar1 == 0)) {
      iVar1 = FUN_00139340(param_1,local_38,2);
      *(int *)(param_1 + 0x94) = local_38._4_4_ + 1;
      jbd2_journal_clear_revoke(param_1);
      iVar2 = sync_blockdev(*(undefined8 *)(param_1 + 0x70));
      if (iVar1 == 0) {
        iVar1 = iVar2;
      }
    }
    else {
      *(int *)(param_1 + 0x94) = local_38._4_4_ + 1;
      jbd2_journal_clear_revoke(param_1);
      sync_blockdev(*(undefined8 *)(param_1 + 0x70));
    }
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



// Function: jbd2_journal_skip_recovery @ 0x39c90

int jbd2_journal_skip_recovery(long param_1)

{
  int iVar1;
  int iVar2;
  long in_FS_OFFSET;
  undefined1 local_38 [16];
  undefined4 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = 0;
  local_38 = (undefined1  [16])0x0;
  iVar2 = FUN_00139340(param_1,local_38,0);
  if (iVar2 == 0) {
    iVar1 = local_38._4_4_;
  }
  else {
    __printf_chk(1,"JBD2: error %d scanning journal\n",iVar2);
    iVar1 = *(int *)(param_1 + 0x94);
  }
  *(int *)(param_1 + 0x94) = iVar1 + 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: region_create @ 0x39d30

undefined8 * region_create(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined8 *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = ext2fs_get_memzero(0x20,&local_28);
  if (lVar1 == 0) {
    *local_28 = param_1;
    local_28[1] = param_2;
    local_28[3] = 0;
  }
  else {
    local_28 = (undefined8 *)0x0;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_28;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: region_free @ 0x39da0

void region_free(undefined1 (*param_1) [16],undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 extraout_RDX;
  long in_FS_OFFSET;
  undefined1 (*local_30) [16];
  long local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = 0;
  local_30 = param_1;
  if (*(long *)param_1[1] != 0) {
    local_28 = *(long *)param_1[1];
    do {
      lVar1 = *(long *)(local_28 + 0x10);
      ext2fs_free_mem(&local_28,param_2,uVar2);
      uVar2 = extraout_RDX;
      local_28 = lVar1;
    } while (lVar1 != 0);
  }
  local_28 = 0;
  *local_30 = (undefined1  [16])0x0;
  local_30[1] = (undefined1  [16])0x0;
  ext2fs_free_mem(&local_30,param_2,uVar2);
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: region_allocate @ 0x39e30

undefined8 region_allocate(ulong *param_1,ulong param_2,int param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong *puVar3;
  long lVar4;
  undefined8 uVar5;
  ulong *puVar6;
  ulong uVar7;
  ulong *puVar8;
  long in_FS_OFFSET;
  ulong *local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((*param_1 <= param_2) && (uVar7 = (long)param_3 + param_2, uVar7 <= param_1[1])) {
    if (param_3 == 0) {
LAB_00139efc:
      uVar5 = 1;
      goto LAB_00139f25;
    }
    puVar6 = (ulong *)param_1[3];
    if (puVar6 == (ulong *)0x0) {
LAB_00139e93:
      puVar6 = (ulong *)param_1[2];
      if (puVar6 != (ulong *)0x0) {
        puVar3 = puVar6;
        puVar8 = (ulong *)0x0;
        do {
          puVar6 = puVar3;
          uVar1 = *puVar6;
          uVar2 = puVar6[1];
          if (param_2 < uVar1) {
            if (uVar1 < uVar7) goto LAB_00139efc;
LAB_00139f59:
            if (uVar2 <= uVar7) goto LAB_00139efc;
          }
          else {
            if (param_2 < uVar2) goto LAB_00139efc;
            if (uVar1 < uVar7) {
              if ((uVar7 <= uVar2) || (param_2 <= uVar1)) goto LAB_00139efc;
            }
            else if (uVar1 == param_2) goto LAB_00139f59;
          }
          if (uVar1 == uVar7) {
            *puVar6 = param_2;
            uVar5 = 0;
            goto LAB_00139f25;
          }
          if (param_2 == uVar2) {
            local_38 = (ulong *)puVar6[2];
            if (local_38 == (ulong *)0x0) goto LAB_00139f73;
            if (*local_38 < uVar7) goto LAB_00139efc;
            if (*local_38 != uVar7) goto LAB_00139f73;
            uVar7 = local_38[2];
            puVar6[1] = local_38[1];
            puVar6[2] = uVar7;
            ext2fs_free_mem(&local_38);
            uVar5 = 0;
            if (puVar6[2] == 0) {
              param_1[3] = (ulong)puVar6;
              uVar5 = 0;
            }
            goto LAB_00139f25;
          }
          if (param_2 < uVar1) {
            lVar4 = ext2fs_get_mem(0x18,&local_38);
            if (lVar4 != 0) goto LAB_00139f20;
            *local_38 = param_2;
            local_38[1] = uVar7;
            local_38[2] = (ulong)puVar6;
            goto LAB_00139f95;
          }
          puVar3 = (ulong *)puVar6[2];
          puVar8 = puVar6;
        } while ((ulong *)puVar6[2] != (ulong *)0x0);
      }
    }
    else {
      if (puVar6[1] == param_2) {
        if (puVar6[2] == 0) {
LAB_00139f73:
          puVar6[1] = uVar7;
          uVar5 = 0;
          goto LAB_00139f25;
        }
        goto LAB_00139e93;
      }
      if ((param_2 <= puVar6[1]) || (puVar6[2] != 0)) goto LAB_00139e93;
    }
    lVar4 = ext2fs_get_mem(0x18,&local_38);
    if (lVar4 == 0) {
      *local_38 = param_2;
      local_38[1] = uVar7;
      local_38[2] = 0;
      param_1[3] = (ulong)local_38;
      puVar8 = puVar6;
LAB_00139f95:
      if (puVar8 == (ulong *)0x0) {
        param_1[2] = (ulong)local_38;
        uVar5 = 0;
      }
      else {
        puVar8[2] = (ulong)local_38;
        uVar5 = 0;
      }
      goto LAB_00139f25;
    }
  }
LAB_00139f20:
  uVar5 = 0xffffffff;
LAB_00139f25:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



// Function: jbd2_journal_destroy_revoke_table @ 0x3a090

void jbd2_journal_destroy_revoke_table(int *param_1)

{
  int iVar1;
  long lVar2;
  void *__ptr;
  
  __ptr = *(void **)(param_1 + 2);
  if (0 < *param_1) {
    lVar2 = 0;
    do {
      iVar1 = FUN_0013a080((void *)(lVar2 * 0x10 + (long)__ptr));
      if (iVar1 == 0) {
        __printf_chk(1,"Assertion failure in %s() at %s line %d: \"%s\"\n",
                     "jbd2_journal_destroy_revoke_table","revoke.c",0xff,"list_empty(hash_list)");
                    /* WARNING: Subroutine does not return */
        fatal_error(e2fsck_global_ctx,0);
      }
      lVar2 = lVar2 + 1;
    } while ((int)lVar2 < *param_1);
  }
  free(__ptr);
  free(param_1);
  return;
}



// Function: jbd2_journal_init_revoke_table @ 0x3a130

int * jbd2_journal_init_revoke_table(int param_1)

{
  int iVar1;
  int *__ptr;
  long lVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  
  __ptr = malloc((long)*DAT_001b7380);
  piVar5 = __ptr;
  if (__ptr != (int *)0x0) {
    iVar3 = 0;
    iVar1 = param_1;
    while (iVar1 = iVar1 >> 1, iVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
    __ptr[1] = iVar3;
    *__ptr = param_1;
    lVar2 = kmalloc_array(param_1,0x10,0);
    *(long *)(__ptr + 2) = lVar2;
    if (lVar2 == 0) {
      piVar5 = (int *)0x0;
      free(__ptr);
    }
    else if (0 < param_1) {
      lVar4 = ((ulong)(param_1 - 1) + 1) * 0x10 + lVar2;
      do {
        *(long *)lVar2 = lVar2;
        *(long *)(lVar2 + 8) = lVar2;
        lVar2 = lVar2 + 0x10;
      } while (lVar2 != lVar4);
    }
  }
  return piVar5;
}



// Function: insert_revoke_hash @ 0x3a240

undefined8 insert_revoke_hash(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  void *pvVar3;
  undefined8 uVar4;
  
  pvVar3 = malloc((long)*DAT_001b7388);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    lVar1 = *(long *)(param_1 + 0xa8);
    *(undefined4 *)((long)pvVar3 + 0x10) = param_3;
    *(undefined8 *)((long)pvVar3 + 0x18) = param_2;
    iVar2 = FUN_0013a1d0(lVar1,param_2);
    uVar4 = FUN_0013a060(pvVar3,(long)iVar2 * 0x10 + *(long *)(lVar1 + 8));
  }
  return uVar4;
}



// Function: jbd2_journal_destroy_revoke_record_cache @ 0x3a2c0

void jbd2_journal_destroy_revoke_record_cache(void)

{
  do_cache_destroy(DAT_001b7388);
  DAT_001b7388 = (void *)0x0;
  return;
}



// Function: jbd2_journal_destroy_revoke_table_cache @ 0x3a2f0

void jbd2_journal_destroy_revoke_table_cache(void)

{
  do_cache_destroy(DAT_001b7380);
  DAT_001b7380 = (void *)0x0;
  return;
}



// Function: jbd2_journal_init_revoke_record_cache @ 0x3a320

uint jbd2_journal_init_revoke_record_cache(void)

{
  if (DAT_001b7388 != 0) {
    __printf_chk(1,"Assertion failure in %s() at %s line %d: \"%s\"\n",
                 "jbd2_journal_init_revoke_record_cache","revoke.c",0xc3,"!jbd2_revoke_record_cache"
                );
                    /* WARNING: Subroutine does not return */
    fatal_error(e2fsck_global_ctx,0);
  }
  DAT_001b7388 = do_cache_create(0x20);
  return -(uint)(DAT_001b7388 == 0) & 0xfffffff4;
}



// Function: jbd2_journal_init_revoke_table_cache @ 0x3a390

uint jbd2_journal_init_revoke_table_cache(void)

{
  if (DAT_001b7380 != 0) {
    __printf_chk(1,"Assertion failure in %s() at %s line %d: \"%s\"\n",
                 "jbd2_journal_init_revoke_table_cache","revoke.c",0xd0,"!jbd2_revoke_table_cache");
                    /* WARNING: Subroutine does not return */
    fatal_error(e2fsck_global_ctx,0);
  }
  DAT_001b7380 = do_cache_create(0x10);
  return -(uint)(DAT_001b7380 == 0) & 0xfffffff4;
}



// Function: jbd2_journal_init_revoke @ 0x3a400

undefined8 jbd2_journal_init_revoke(long param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0xb0) != 0) {
    __printf_chk(1,"Assertion failure in %s() at %s line %d: \"%s\"\n","jbd2_journal_init_revoke",
                 "revoke.c",0x109,"journal->j_revoke_table[0] == NULL");
                    /* WARNING: Subroutine does not return */
    fatal_error(e2fsck_global_ctx,0);
  }
  if ((param_2 != 0) && ((param_2 - 1 & param_2) == 0)) {
    lVar1 = FUN_0013a130(param_2);
    *(long *)(param_1 + 0xb0) = lVar1;
    if (lVar1 == 0) {
      uVar2 = 0xfffffff4;
    }
    else {
      lVar1 = FUN_0013a130(param_2);
      *(long *)(param_1 + 0xb8) = lVar1;
      if (lVar1 == 0) {
        FUN_0013a090(*(undefined8 *)(param_1 + 0xb0));
        uVar2 = 0xfffffff4;
        *(undefined8 *)(param_1 + 0xb0) = 0;
      }
      else {
        *(long *)(param_1 + 0xa8) = lVar1;
        uVar2 = 0;
      }
    }
    return uVar2;
  }
  __printf_chk(1,"Assertion failure in %s() at %s line %d: \"%s\"\n","jbd2_journal_init_revoke",
               "revoke.c",0x10a,"is_power_of_2(hash_size)");
                    /* WARNING: Subroutine does not return */
  fatal_error(e2fsck_global_ctx,0);
}



// Function: jbd2_journal_destroy_revoke @ 0x3a510

void jbd2_journal_destroy_revoke(long param_1)

{
  *(undefined8 *)(param_1 + 0xa8) = 0;
  if (*(long *)(param_1 + 0xb0) != 0) {
    FUN_0013a090();
  }
  if (*(long *)(param_1 + 0xb8) != 0) {
    FUN_0013a090();
    return;
  }
  return;
}



// Function: jbd2_journal_set_revoke @ 0x3a560

undefined8 jbd2_journal_set_revoke(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = FUN_0013a1e0(*(undefined8 *)(param_1 + 0xa8));
  if (lVar2 != 0) {
    iVar1 = tid_gt(param_3,*(undefined4 *)(lVar2 + 0x10));
    if (iVar1 != 0) {
      *(undefined4 *)(lVar2 + 0x10) = param_3;
    }
    return 0;
  }
  uVar3 = FUN_0013a240(param_1,param_2,param_3);
  return uVar3;
}



// Function: jbd2_journal_test_revoke @ 0x3a5d0

bool jbd2_journal_test_revoke(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_0013a1e0(*(undefined8 *)(param_1 + 0xa8));
  if (lVar2 != 0) {
    iVar1 = tid_gt(param_3,*(undefined4 *)(lVar2 + 0x10));
    return iVar1 == 0;
  }
  return false;
}



// Function: jbd2_journal_clear_revoke @ 0x3a610

void jbd2_journal_clear_revoke(long param_1)

{
  int *piVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  undefined8 *__ptr;
  
  piVar1 = *(int **)(param_1 + 0xa8);
  if (0 < *piVar1) {
    lVar4 = 0;
    do {
      plVar3 = (long *)(lVar4 * 0x10 + *(long *)(piVar1 + 2));
      while( true ) {
        iVar2 = FUN_0013a080(plVar3);
        if (iVar2 != 0) break;
        __ptr = (undefined8 *)*plVar3;
        FUN_0013a2b0(*__ptr,__ptr[1]);
        free(__ptr);
      }
      lVar4 = lVar4 + 1;
    } while ((int)lVar4 < *piVar1);
  }
  return;
}



// Function: refcount_collapse @ 0x3a680

void refcount_collapse(ulong *param_1)

{
  undefined8 *puVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  uint uVar7;
  
  uVar2 = *param_1;
  uVar3 = param_1[3];
  uVar6 = 0;
  if (uVar2 != 0) {
    uVar7 = 0;
    uVar6 = 0;
    do {
      puVar5 = (undefined8 *)(uVar6 * 0x10 + uVar3);
      if (puVar5[1] != 0) {
        if ((uint)uVar6 != uVar7) {
          uVar4 = puVar5[1];
          puVar1 = (undefined8 *)(uVar3 + (ulong)uVar7 * 0x10);
          *puVar1 = *puVar5;
          puVar1[1] = uVar4;
        }
        uVar7 = uVar7 + 1;
      }
      uVar6 = (ulong)((uint)uVar6 + 1);
    } while (uVar6 < uVar2);
    uVar6 = (ulong)uVar7;
  }
  *param_1 = uVar6;
  return;
}



// Function: insert_refcount_el @ 0x3a6d0

undefined8 * insert_refcount_el(ulong *param_1,undefined8 param_2,int param_3)

{
  ulong uVar1;
  long lVar2;
  undefined8 *puVar3;
  ulong uVar4;
  int iVar5;
  
  uVar4 = *param_1;
  if (uVar4 < param_1[1]) {
    iVar5 = (int)uVar4 - param_3;
  }
  else {
    uVar1 = param_1[1] + 100;
    lVar2 = uVar1 * 0x10;
    lVar2 = ext2fs_resize_mem(lVar2 + -0x640,lVar2,param_1 + 3);
    if (lVar2 != 0) {
      return (undefined8 *)0x0;
    }
    uVar4 = *param_1;
    param_1[1] = uVar1;
    iVar5 = (int)uVar4 - param_3;
  }
  if (iVar5 < 0) {
    return (undefined8 *)0x0;
  }
  lVar2 = (long)param_3 * 0x10;
  if (iVar5 != 0) {
    memmove((void *)(param_1[3] + 0x10 + lVar2),(void *)(param_1[3] + lVar2),(long)iVar5 << 4);
    uVar4 = *param_1;
  }
  *param_1 = uVar4 + 1;
  puVar3 = (undefined8 *)(param_1[3] + lVar2);
  *puVar3 = param_2;
  puVar3[1] = 0;
  return puVar3;
}



// Function: get_refcount_el @ 0x3a7a0

ulong * get_refcount_el(ulong *param_1,ulong param_2,int param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  int iVar7;
  
  if (param_1 == (ulong *)0x0) {
    return (ulong *)0x0;
  }
  puVar2 = (ulong *)param_1[3];
  if (puVar2 == (ulong *)0x0) {
    return (ulong *)0x0;
  }
  uVar6 = *param_1;
  do {
    iVar3 = (int)uVar6 + -1;
    if (param_3 == 0) {
      if (uVar6 == 0) {
        return (ulong *)0x0;
      }
    }
    else if ((uVar6 == 0) || (puVar2[(long)iVar3 * 2] < param_2)) {
      if (param_1[1] <= uVar6) {
        FUN_0013a680();
      }
      break;
    }
    uVar5 = param_1[2];
    if (uVar5 < uVar6) {
      puVar1 = puVar2 + uVar5 * 2;
    }
    else {
      param_1[2] = 0;
      uVar5 = 0;
      puVar1 = puVar2;
    }
    if (*puVar1 == param_2) {
      param_1[2] = uVar5 + 1;
      return puVar1;
    }
    iVar7 = 0;
    if (-1 < iVar3) {
      do {
        while( true ) {
          iVar4 = iVar7 + iVar3 >> 1;
          uVar5 = puVar2[(long)iVar4 * 2];
          if (uVar5 == param_2) {
            param_1[2] = (long)(iVar4 + 1);
            return puVar2 + (long)iVar4 * 2;
          }
          if (param_2 < uVar5) break;
          iVar7 = iVar4 + 1;
          if (iVar3 < iVar7) goto LAB_0013a840;
        }
        iVar3 = iVar4 + -1;
      } while (iVar7 <= iVar3);
    }
LAB_0013a840:
    if (param_3 == 0) {
      return (ulong *)0x0;
    }
    uVar5 = param_1[1];
    if (uVar6 < uVar5) break;
    FUN_0013a680();
    uVar6 = *param_1;
  } while (uVar6 < uVar5);
  puVar2 = (ulong *)FUN_0013a6d0();
  return puVar2;
}



// Function: ea_refcount_free @ 0x3a8d0

void ea_refcount_free(long param_1)

{
  long local_10 [2];
  
  if (param_1 != 0) {
    local_10[0] = param_1;
    if (*(long *)(param_1 + 0x18) != 0) {
      ext2fs_free_mem(param_1 + 0x18);
    }
    ext2fs_free_mem(local_10);
  }
  return;
}



// Function: ea_refcount_create @ 0x3a910

long ea_refcount_create(long param_1,undefined8 *param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined8 *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = ext2fs_get_memzero(0x20,&local_28);
  if (lVar1 == 0) {
    if (param_1 == 0) {
      lVar1 = 8000;
      param_1 = 500;
    }
    else {
      lVar1 = param_1 << 4;
    }
    local_28[1] = param_1;
    lVar1 = ext2fs_get_memzero(lVar1,local_28 + 3);
    if (lVar1 == 0) {
      *local_28 = 0;
      local_28[2] = 0;
      *param_2 = local_28;
    }
    else {
      ea_refcount_free(local_28);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ea_refcount_fetch @ 0x3a9d0

undefined8 ea_refcount_fetch(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  
  lVar1 = FUN_0013a7a0(param_1,param_2,0);
  if (lVar1 != 0) {
    *param_3 = *(undefined8 *)(lVar1 + 8);
    return 0;
  }
  *param_3 = 0;
  return 0;
}



// Function: ea_refcount_increment @ 0x3aa00

undefined8 ea_refcount_increment(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  long lVar2;
  
  lVar2 = FUN_0013a7a0(param_1,param_2,1);
  if (lVar2 != 0) {
    lVar1 = *(long *)(lVar2 + 8) + 1;
    *(long *)(lVar2 + 8) = lVar1;
    if (param_3 != (long *)0x0) {
      *param_3 = lVar1;
    }
    return 0;
  }
  return 0x7f2bb746;
}



// Function: ea_refcount_decrement @ 0x3aa40

undefined8 ea_refcount_decrement(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = FUN_0013a7a0(param_1,param_2,0);
  if (lVar1 != 0) {
    uVar3 = 0x7f2bb747;
    if (*(long *)(lVar1 + 8) != 0) {
      lVar2 = *(long *)(lVar1 + 8) + -1;
      uVar3 = 0;
      *(long *)(lVar1 + 8) = lVar2;
      if (param_3 != (long *)0x0) {
        *param_3 = lVar2;
      }
    }
    return uVar3;
  }
  return 0x7f2bb747;
}



// Function: ea_refcount_store @ 0x3aa90

uint ea_refcount_store(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  
  lVar1 = FUN_0013a7a0(param_1,param_2,param_3 != 0);
  if (lVar1 != 0) {
    *(long *)(lVar1 + 8) = param_3;
    return 0;
  }
  return -(uint)(param_3 != 0) & 0x7f2bb746;
}



// Function: ext2fs_get_refcount_size @ 0x3aad0

undefined8 ext2fs_get_refcount_size(long param_1)

{
  if (param_1 != 0) {
    return *(undefined8 *)(param_1 + 8);
  }
  return 0;
}



// Function: ea_refcount_intr_begin @ 0x3aaf0

void ea_refcount_intr_begin(long param_1)

{
  *(undefined8 *)(param_1 + 0x10) = 0;
  return;
}



// Function: ea_refcount_intr_next @ 0x3ab00

undefined8 ea_refcount_intr_next(ulong *param_1,long *param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  
  uVar1 = param_1[2];
  if (uVar1 < *param_1) {
    puVar2 = (undefined8 *)(uVar1 * 0x10 + param_1[3]);
    do {
      uVar1 = uVar1 + 1;
      if (puVar2[1] != 0) {
        if (param_2 != (long *)0x0) {
          *param_2 = puVar2[1];
        }
        param_1[2] = uVar1;
        return *puVar2;
      }
      param_1[2] = uVar1;
      puVar2 = puVar2 + 2;
    } while (*param_1 != uVar1);
  }
  return 0;
}



// Function: ino_cmp @ 0x3ac10

int ino_cmp(long param_1,long param_2)

{
  return (int)*(undefined8 *)(param_1 + 8) - *(int *)(param_2 + 8);
}



// Function: free_out_dir @ 0x3ac20

void free_out_dir(undefined8 *param_1)

{
  free((void *)param_1[1]);
  free((void *)param_1[2]);
  *param_1 = 0;
  return;
}



// Function: name_cmp @ 0x3ac40

int name_cmp(long param_1,long param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  piVar1 = *(int **)(param_1 + 0x10);
  uVar3 = ext2fs_dirent_name_len(piVar1);
  piVar2 = *(int **)(param_2 + 0x10);
  uVar4 = ext2fs_dirent_name_len(piVar2);
  uVar6 = uVar4;
  if (uVar3 <= uVar4) {
    uVar6 = uVar3;
  }
  iVar5 = memcmp(piVar1 + 2,piVar2 + 2,(ulong)uVar6);
  if (iVar5 == 0) {
    iVar5 = 1;
    if (uVar3 <= uVar4) {
      if (uVar3 < uVar4) {
        iVar5 = -1;
      }
      else {
        iVar5 = *piVar2 - *piVar1;
      }
    }
  }
  return iVar5;
}



// Function: same_name @ 0x3acb0

bool same_name(int *param_1,void *param_2,int param_3,void *param_4,int param_5)

{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = ext2fs_casefold_cmp(*(undefined8 *)(param_1 + 2),param_2,(long)param_3,param_4,
                                (long)param_5);
    return iVar1 == 0;
  }
  if (param_5 != param_3) {
    return false;
  }
  iVar1 = memcmp(param_2,param_4,(long)param_5);
  return iVar1 == 0;
}



// Function: mutate_name @ 0x3ad10

void mutate_name(char *param_1,uint *param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  ushort **ppuVar4;
  char *pcVar5;
  uint uVar6;
  long lVar7;
  
  uVar1 = *param_2;
  uVar6 = uVar1 - 1;
  uVar3 = uVar6;
  if (0 < (int)uVar6) {
    ppuVar4 = __ctype_b_loc();
    pcVar5 = param_1 + (int)uVar6;
    do {
      if ((*(byte *)((long)*ppuVar4 + (long)*pcVar5 * 2 + 1) & 8) == 0) break;
      pcVar5 = pcVar5 + -1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  if ((uVar6 == uVar3) || (param_1[(int)uVar3] != '~')) {
    uVar3 = uVar1 + 2;
    if ((uVar6 & 2) != 0) {
      uVar3 = uVar1 + 3 & 0xfffffffc;
      uVar1 = uVar3 - 2;
    }
    param_1[uVar1] = '~';
    param_1[uVar3 - 1] = '0';
    *param_2 = uVar3;
  }
  else if (-1 < (int)uVar6) {
    ppuVar4 = __ctype_b_loc();
    lVar7 = (long)(int)uVar6;
    pcVar5 = param_1 + lVar7;
    do {
      cVar2 = *pcVar5;
      if ((*(byte *)((long)*ppuVar4 + (long)cVar2 * 2 + 1) & 8) == 0) {
        if ((int)lVar7 != 1) {
          if ((int)lVar7 != 0) {
            *pcVar5 = '1';
            param_1[lVar7 + -1] = '~';
            return;
          }
          cVar2 = 'a';
          if (*param_1 != '~') {
            cVar2 = *param_1 + '\x01';
          }
          *param_1 = cVar2;
          return;
        }
        cVar2 = *param_1;
        if (cVar2 == 'z') {
          *param_1 = 'A';
          return;
        }
        if (cVar2 != 'Z') {
          *param_1 = cVar2 + '\x01';
          return;
        }
        param_1[0] = '~';
        param_1[1] = '0';
        return;
      }
      if (cVar2 != '9') {
        *pcVar5 = cVar2 + '\x01';
        return;
      }
      lVar7 = lVar7 + -1;
      *pcVar5 = '0';
      pcVar5 = pcVar5 + -1;
    } while ((int)lVar7 != -1);
  }
  return;
}



// Function: duplicate_search_and_fix @ 0x3ae50

int duplicate_search_and_fix(undefined8 param_1,long param_2,undefined4 param_3,long param_4,undefined8 param_5)

{
  long lVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  long lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  long in_FS_OFFSET;
  int local_1dc;
  uint local_1d0;
  uint local_1bc;
  undefined1 local_1b8 [8];
  undefined4 local_1b0;
  int *local_198;
  undefined1 *local_158;
  undefined1 local_148 [264];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar3 = *(uint *)(*(long *)(param_4 + 8) + 0x20);
  clear_problem_context(local_1b8);
  bVar2 = *(byte *)(*(long *)(param_2 + 0x20) + 0xfc);
  local_1d0 = (uint)bVar2;
  if (bVar2 < 3) {
    local_1d0 = bVar2 + 3;
    if ((*(byte *)(*(long *)(param_2 + 0x20) + 0x160) & 2) == 0) {
      local_1d0 = (uint)bVar2;
    }
  }
  local_1dc = 0;
  local_1b0 = param_3;
  if (1 < *(uint *)(param_4 + 0x34)) {
    uVar9 = 1;
    do {
      while( true ) {
        lVar1 = *(long *)(param_4 + 0x28) + (ulong)uVar9 * 0x18;
        piVar4 = *(int **)(lVar1 + 0x10);
        if (*piVar4 != 0) break;
LAB_0013af10:
        uVar9 = uVar9 + 1;
        if (*(uint *)(param_4 + 0x34) <= uVar9) goto LAB_0013b0e8;
      }
      lVar5 = *(long *)(lVar1 + -8);
      uVar6 = ext2fs_dirent_name_len(lVar5);
      uVar7 = ext2fs_dirent_name_len(piVar4);
      iVar8 = FUN_0013acb0(param_5,piVar4 + 2,uVar7,lVar5 + 8,uVar6);
      if (iVar8 == 0) goto LAB_0013af10;
      local_198 = *(int **)(lVar1 + 0x10);
      if (((*local_198 == **(int **)(lVar1 + -8)) &&
          (iVar8 = fix_problem(param_1,0x20041,local_1b8), iVar8 != 0)) ||
         (((*(byte *)(*(long *)(param_4 + 8) + 0x21) & 8) != 0 &&
          (iVar8 = fix_problem(param_1,0x20054,local_1b8), iVar8 != 0)))) {
        e2fsck_adjust_inode_count(param_1,**(undefined4 **)(lVar1 + 0x10),0xffffffff);
        **(undefined4 **)(lVar1 + 0x10) = 0;
        local_1dc = local_1dc + 1;
        goto LAB_0013af10;
      }
      lVar5 = *(long *)(lVar1 + 0x10);
      local_1bc = ext2fs_dirent_name_len(lVar5);
      if (local_1bc == 0) {
        ext2fs_unmark_valid(param_2);
        goto LAB_0013af10;
      }
      __memcpy_chk(local_148,lVar5 + 8,local_1bc,0x100);
      FUN_0013ad10(local_148,&local_1bc);
      uVar11 = local_1bc;
      if (*(int *)(param_4 + 0x34) != 0) {
        uVar10 = 0;
LAB_0013b03e:
        do {
          if (uVar10 != uVar9) {
            lVar5 = *(long *)(*(long *)(param_4 + 0x28) + (ulong)uVar10 * 0x18 + 0x10);
            uVar6 = ext2fs_dirent_name_len(lVar5);
            iVar8 = FUN_0013acb0(param_5,local_148,uVar11,lVar5 + 8,uVar6);
            if (iVar8 != 0) {
              uVar10 = 0;
              FUN_0013ad10(local_148,&local_1bc);
              uVar11 = local_1bc;
              if (*(int *)(param_4 + 0x34) == 0) break;
              goto LAB_0013b03e;
            }
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *(uint *)(param_4 + 0x34));
      }
      local_148[uVar11] = 0;
      local_158 = local_148;
      iVar8 = fix_problem(param_1,0x20042,local_1b8);
      if (iVar8 == 0) goto LAB_0013af10;
      uVar9 = uVar9 + 1;
      memcpy((void *)(*(long *)(lVar1 + 0x10) + 8),local_148,(ulong)uVar11);
      ext2fs_dirent_set_name_len(*(undefined8 *)(lVar1 + 0x10),uVar11);
      ext2fs_dirhash2(local_1d0,local_148,uVar11,*(undefined8 *)(param_2 + 0x168),uVar3 & 0x40000000
                      ,*(long *)(param_2 + 0x20) + 0xec,lVar1);
      local_1dc = local_1dc + 1;
    } while (uVar9 < *(uint *)(param_4 + 0x34));
  }
LAB_0013b0e8:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1dc;
}



// Function: write_directory @ 0x3b190

void write_directory(undefined8 param_1,long param_2,uint *param_3,undefined4 param_4,long param_5,
                 int param_6)

{
  uint uVar1;
  long lVar2;
  long in_FS_OFFSET;
  uint *local_68;
  long local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = e2fsck_expand_directory(param_1,param_4,0xffffffff,*param_3);
  if (lVar2 == 0) {
    local_60 = 0;
    local_68 = param_3;
    local_58 = param_4;
    local_50 = param_1;
    local_48 = param_4;
    lVar2 = ext2fs_block_iterate3(param_2,param_4,0,0,FUN_0013b2c0,&local_68);
    if ((lVar2 == 0) && (local_60 == 0)) {
      e2fsck_read_inode(param_1,param_4,param_5,"rehash_dir");
      if (param_6 == 0) {
        uVar1 = *(uint *)(param_5 + 0x20) | 0x1000;
      }
      else {
        uVar1 = *(uint *)(param_5 + 0x20) & 0xffffefff;
      }
      *(uint *)(param_5 + 0x20) = uVar1;
      lVar2 = ext2fs_inode_size_set
                        (param_2,param_5,(ulong)*param_3 * (ulong)*(uint *)(param_2 + 0x28));
      if (lVar2 == 0) {
        ext2fs_punch(param_2,param_4,param_5,0,*param_3,0xffffffffffffffff);
      }
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: write_dir_block @ 0x3b2c0

char write_dir_block(long param_1,long *param_2,long param_3,undefined8 param_4,undefined8 param_5,
                 undefined8 *param_6)

{
  char cVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  long in_FS_OFFSET;
  long local_28;
  long local_20;
  
  lVar2 = *param_2;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = 0;
  if ((param_3 < 0) || (lVar2 == 0)) {
    cVar1 = '\0';
    goto LAB_0013b342;
  }
  iVar4 = *(int *)(param_6 + 4);
  if (param_3 < (long)(ulong)*(uint *)*param_6) {
    lVar3 = param_3 * (ulong)*(uint *)(param_1 + 0x28) + *(long *)((uint *)*param_6 + 2);
  }
  else {
    cVar1 = '\0';
    if (*(int *)(param_6[3] + 0x228) != iVar4) goto LAB_0013b342;
    lVar2 = ext2fs_new_dir_block(param_1,0,0,&local_28);
    param_6[1] = lVar2;
    cVar1 = '\x02';
    if (lVar2 != 0) goto LAB_0013b342;
    lVar2 = *param_2;
    iVar4 = *(int *)(param_6 + 4);
    *(int *)*param_6 = *(int *)*param_6 + 1;
    lVar3 = local_28;
  }
  lVar2 = ext2fs_write_dir_block4(param_1,lVar2,lVar3,0,iVar4);
  param_6[1] = lVar2;
  if (local_28 != 0) {
    ext2fs_free_mem(&local_28);
    lVar2 = param_6[1];
  }
  cVar1 = (lVar2 != 0) * '\x02';
LAB_0013b342:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return cVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: get_next_block @ 0x3b450

long get_next_block(long param_1,uint *param_2,undefined8 *param_3)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  void *__s;
  
  uVar3 = *param_2;
  uVar1 = param_2[1];
  if (uVar1 <= uVar3) {
    uVar3 = uVar1 / 10;
    if (uVar3 < 0x32) {
      uVar3 = 0x32;
    }
    lVar2 = FUN_0013b3c0(*(undefined4 *)(param_1 + 0x28),param_2,uVar3 + uVar1);
    if (lVar2 != 0) {
      return lVar2;
    }
    uVar3 = *param_2;
  }
  uVar1 = *(uint *)(param_1 + 0x28);
  *param_2 = uVar3 + 1;
  __s = (void *)((ulong)uVar3 * (ulong)uVar1 + *(long *)(param_2 + 2));
  *param_3 = __s;
  memset(__s,0,(ulong)uVar1);
  return 0;
}



// Function: hash_cmp @ 0x3b550

undefined8 hash_cmp(uint *param_1,uint *param_2,int *param_3)

{
  undefined8 uVar1;
  
  if (*param_2 < *param_1) {
    return 1;
  }
  if (*param_2 <= *param_1) {
    if (param_2[1] < param_1[1]) {
      return 1;
    }
    if (param_2[1] <= param_1[1]) {
      if (*param_3 != 0) {
        uVar1 = FUN_0013b4c0(*(undefined8 *)(param_3 + 2),param_1,param_2);
        return uVar1;
      }
      uVar1 = FUN_0013ac40();
      return uVar1;
    }
  }
  return 0xffffffff;
}



// Function: copy_dir_entries @ 0x3b910

long copy_dir_entries(long *param_1,long param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  long lVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  long lVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  uint uVar15;
  long in_FS_OFFSET;
  uint local_8c;
  uint local_7c;
  uint local_60;
  uint local_5c;
  long local_58;
  int *local_48;
  long local_40;
  
  lVar3 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar5 = FUN_0013ab60(*(undefined8 *)(param_2 + 8));
  if (((int)param_1[0x4c] == 0xff) &&
     (profile_get_uint(param_1[0x6c],"options","indexed_dir_slack_percentage",0,0x14,param_1 + 0x4c)
     , 100 < *(uint *)(param_1 + 0x4c))) {
    *(undefined4 *)(param_1 + 0x4c) = 0x14;
  }
  iVar6 = FUN_0013b900(*(undefined4 *)(*(long *)(lVar3 + 0x20) + 100));
  iVar7 = 0xc;
  if (iVar6 == 0) {
    iVar7 = 0;
  }
  uVar8 = *(uint *)(lVar3 + 0x28);
  param_3[1] = 0;
  local_58 = FUN_0013b3c0(*(undefined4 *)(lVar3 + 0x28),param_3,
                          (int)(*(long *)(param_2 + 0x38) / (long)(ulong)uVar8) + 2);
  if (local_58 == 0) {
    *param_3 = (uint)(*(int *)(param_2 + 0x40) == 0);
    **(undefined4 **)(param_3 + 4) = 0;
    lVar11 = FUN_0013b450(lVar3,param_3);
    local_58 = lVar11;
    if (lVar11 == 0) {
      uVar8 = FUN_0013ab80(1,iVar5);
      uVar12 = *(int *)(lVar3 + 0x28) - iVar7;
      local_5c = uVar8;
      if ((*(int *)(param_2 + 0x40) == 0) &&
         (local_5c = (uVar12 * (int)param_1[0x4c]) / 100, local_5c <= uVar8)) {
        local_5c = uVar8;
      }
      uVar8 = 0;
      piVar14 = local_48;
      if (*(int *)(param_2 + 0x34) != 0) {
        local_60 = 1;
        uVar15 = 0;
        uVar8 = 0;
        local_7c = 0;
        local_8c = 0;
        do {
          puVar2 = (uint *)(*(long *)(param_2 + 0x28) + (ulong)uVar15 * 0x18);
          piVar13 = *(int **)(puVar2 + 4);
          iVar6 = *piVar13;
          if (iVar6 != 0) {
            uVar4 = ext2fs_dirent_name_len(piVar13);
            uVar8 = FUN_0013ab80(uVar4,iVar5);
            if (uVar12 < uVar8) {
              if ((uVar12 != 0) &&
                 (local_58 = ext2fs_set_rec_len(lVar3,local_8c + uVar12,piVar14), local_58 != 0))
              goto LAB_0013b9aa;
              if (iVar7 != 0) {
                ext2fs_initialize_dirent_tail
                          (lVar3,(long)local_48 + ((ulong)*(uint *)(lVar3 + 0x28) - 0xc));
              }
              local_58 = FUN_0013b450(lVar3,param_3,&local_48);
              if (local_58 != 0) goto LAB_0013b9aa;
              local_8c = *(int *)(lVar3 + 0x28) - iVar7;
              piVar13 = *(int **)(puVar2 + 4);
              piVar14 = local_48;
              uVar10 = local_8c;
LAB_0013bab8:
              puVar1 = (uint *)(*(long *)(param_3 + 4) + (ulong)(*param_3 - 1) * 4);
              if (*puVar2 == local_60) {
                *puVar1 = local_60 | 1;
                iVar6 = *piVar13;
                local_7c = 0;
              }
              else {
                *puVar1 = *puVar2;
                iVar6 = *piVar13;
                local_7c = 0;
              }
            }
            else {
              uVar10 = *(int *)(lVar3 + 0x28) - iVar7;
              local_8c = uVar10 - local_7c;
              piVar14 = (int *)((ulong)local_7c + (long)local_48);
              if (local_7c == 0) goto LAB_0013bab8;
            }
            *piVar14 = iVar6;
            uVar9 = ext2fs_dirent_name_len(piVar13);
            ext2fs_dirent_set_name_len(piVar14,uVar9);
            uVar9 = ext2fs_dirent_file_type(piVar13);
            ext2fs_dirent_set_file_type(piVar14,uVar9);
            local_58 = ext2fs_set_rec_len(lVar3,uVar8,piVar14);
            if (local_58 != 0) goto LAB_0013b9aa;
            iVar6 = ext2fs_dirent_name_len(piVar14);
            memcpy(piVar14 + 2,(void *)(*(long *)(puVar2 + 4) + 8),(long)iVar6);
            if (iVar5 != 0) {
              iVar6 = ext2fs_dirent_name_len(piVar14);
              *(uint *)((long)piVar14 + (long)(int)(iVar6 + 3U & 0xfffffffc) + 8) = *puVar2;
              iVar6 = ext2fs_dirent_name_len(piVar14);
              *(uint *)((long)piVar14 + (long)(int)(iVar6 + 3U & 0xfffffffc) + 0xc) = puVar2[1];
            }
            uVar12 = local_8c - uVar8;
            if (uVar12 < local_5c) {
              local_58 = ext2fs_set_rec_len(lVar3,local_8c,piVar14);
              if (local_58 != 0) goto LAB_0013b9aa;
              uVar12 = 0;
              local_7c = uVar10;
            }
            else {
              local_8c = uVar8;
              local_7c = local_7c + uVar8;
            }
            local_60 = *puVar2;
          }
          uVar15 = uVar15 + 1;
        } while (uVar15 < *(uint *)(param_2 + 0x34));
      }
      local_58 = lVar11;
      if (uVar12 != 0) {
        local_58 = ext2fs_set_rec_len(lVar3,uVar12 + uVar8,piVar14);
      }
      if (iVar7 != 0) {
        ext2fs_initialize_dirent_tail(lVar3,(long)local_48 + ((ulong)*(uint *)(lVar3 + 0x28) - 0xc))
        ;
      }
    }
  }
LAB_0013b9aa:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_58;
}



// Function: set_int_node @ 0x3bd80

undefined4 * set_int_node(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 extraout_RDX;
  
  memset(param_2,0,(ulong)*(uint *)(param_1 + 0x28));
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  *param_2 = 0;
  ext2fs_set_rec_len(param_1,uVar1,param_2);
  iVar2 = FUN_0013b900(*(undefined4 *)(*(long *)(param_1 + 0x20) + 100));
  *(short *)(param_2 + 2) =
       (short)((uint)(*(int *)(param_1 + 0x28) + -8 +
                     (int)CONCAT71((int7)((ulong)extraout_RDX >> 8),iVar2 != 0) * -8) >> 3);
  *(undefined2 *)((long)param_2 + 10) = 0;
  return param_2 + 2;
}



// Function: alloc_blocks @ 0x3bdf0

long alloc_blocks(undefined8 param_1,undefined8 *param_2,long *param_3,undefined8 *param_4,
                 int *param_5,int *param_6,undefined4 *param_7,int param_8,int *param_9,
                 uint *param_10)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  long lVar4;
  ushort *puVar5;
  long in_FS_OFFSET;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  puVar2 = (undefined2 *)*param_2;
  if (puVar2 != (undefined2 *)0x0) {
    puVar2[1] = *puVar2;
  }
  uVar1 = *param_7;
  puVar3 = (undefined4 *)((long)*param_5 + *(long *)(param_7 + 2));
  *param_3 = (long)puVar3;
  puVar3[1] = uVar1;
  if (param_8 != 1) {
    *puVar3 = *(undefined4 *)(*(long *)(param_7 + 4) + (long)param_8 * 4);
  }
  lVar4 = FUN_0013b450(param_1,param_7,&local_48);
  if (lVar4 == 0) {
    *param_3 = (long)*param_5 + *(long *)(param_7 + 2);
    puVar5 = (ushort *)FUN_0013bd80(param_1,local_48);
    *param_4 = puVar5;
    *param_2 = puVar5;
    if (param_6 != (int *)0x0) {
      *param_6 = (int)puVar5 - (int)*(undefined8 *)(param_7 + 2);
    }
    *param_10 = (uint)*puVar5;
    lVar4 = 0;
    *param_5 = *param_5 + 8;
    *param_9 = *param_9 + -1;
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: set_root_node @ 0x3bf00

undefined4 *
set_root_node(long param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined8 param_5)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined1 uVar4;
  int extraout_EDX;
  undefined4 *puVar5;
  
  iVar3 = FUN_0013b8f0(*(undefined4 *)(*(long *)(param_1 + 0x20) + 0x60));
  memset(param_2,0,(ulong)*(uint *)(param_1 + 0x28));
  *param_2 = param_3;
  *(undefined1 *)(param_2 + 2) = 0x2e;
  ext2fs_dirent_set_name_len(param_2,1);
  ext2fs_dirent_set_file_type(param_2,(iVar3 != 0) * '\x02');
  param_2[3] = param_4;
  *(undefined2 *)(param_2 + 5) = 0x2e2e;
  *(undefined2 *)(param_2 + 1) = 0xc;
  ext2fs_dirent_set_name_len(param_2 + 3,2);
  ext2fs_dirent_set_file_type(param_2 + 3);
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  puVar5 = param_2 + 6;
  param_2[6] = 0;
  uVar4 = 6;
  *(short *)(param_2 + 4) = (short)uVar1 + -0xc;
  iVar3 = FUN_0013ab60(param_5);
  lVar2 = *(long *)(param_1 + 0x20);
  if (iVar3 == 0) {
    uVar4 = *(undefined1 *)(lVar2 + 0xfc);
  }
  *(undefined1 *)(param_2 + 7) = uVar4;
  *(undefined1 *)((long)param_2 + 0x1d) = 8;
  *(undefined2 *)((long)param_2 + 0x1e) = 0;
  iVar3 = FUN_0013b900(*(undefined4 *)(lVar2 + 100));
  *(undefined2 *)((long)param_2 + 0x22) = 0;
  *(short *)(param_2 + 8) = (short)(extraout_EDX + (uint)(iVar3 != 0) * -8 >> 3);
  return puVar5;
}



// Function: calculate_tree @ 0x3c010

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long calculate_tree(undefined8 param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  ushort uVar11;
  int iVar12;
  ushort *puVar13;
  uint uVar14;
  ushort uVar15;
  long in_FS_OFFSET;
  uint local_7c;
  uint local_78;
  uint local_74;
  undefined1 local_70 [4];
  int local_6c;
  ushort *local_68;
  undefined1 local_60 [8];
  undefined4 *local_58;
  ushort *local_50;
  ushort *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = (undefined4 *)0x0;
  lVar8 = FUN_0013bf00(param_1,*(undefined8 *)(param_2 + 2));
  iVar1 = *param_2;
  local_6c = (uint)*(byte *)(lVar8 + 5) + ((int)lVar8 - (int)*(undefined8 *)(param_2 + 2));
  lVar9 = (long)local_6c;
  puVar13 = (ushort *)(*(long *)(param_2 + 2) + lVar9);
  uVar5 = *puVar13;
  local_7c = (uint)uVar5;
  uVar14 = (uint)uVar5;
  if ((int)uVar14 < iVar1 + -1) {
    iVar12 = ext2fs_htree_intnode_maxrecs(param_1);
    local_78 = 0;
    if (iVar12 < iVar1 + -1) {
      local_74 = 0;
      local_48 = (ushort *)0x0;
      local_50 = (ushort *)0x0;
      *(undefined1 *)(lVar8 + 6) = 2;
      uVar15 = _DAT_00000000;
      uVar11 = _DAT_00000000;
      if (1 < iVar1) {
        uVar14 = 0;
        lVar8 = 4;
        iVar12 = 1;
        do {
          if (local_74 == 0) {
            if (uVar14 == 0) {
              if (local_7c == 0) goto LAB_0013c388;
              iVar7 = FUN_0013bdf0(param_1,&local_50,&local_68,local_60,&local_6c,local_70,param_2,
                                   iVar12,&local_7c,&local_78);
              lVar10 = (long)iVar7;
              if (lVar10 != 0) goto LAB_0013c0d4;
            }
            uVar2 = *(undefined8 *)(param_2 + 2);
            iVar7 = (int)local_50;
            uVar3 = *(undefined8 *)(param_2 + 2);
            iVar4 = (int)local_68;
            iVar6 = FUN_0013bdf0(param_1,&local_48,local_60,&local_58,local_70,0,param_2,iVar12,
                                 &local_78,&local_74);
            lVar10 = (long)iVar6;
            if (lVar10 != 0) goto LAB_0013c0d4;
            local_50 = (ushort *)((long)(iVar7 - (int)uVar2) + *(long *)(param_2 + 2));
            local_68 = (ushort *)((long)(iVar4 - (int)uVar3) + *(long *)(param_2 + 2));
            uVar14 = local_78;
          }
          uVar11 = *local_48;
          local_58[1] = iVar12;
          if (uVar11 != local_74) {
            *local_58 = *(undefined4 *)(*(long *)(param_2 + 4) + lVar8);
          }
          local_58 = local_58 + 2;
          local_74 = local_74 - 1;
          iVar12 = iVar12 + 1;
          lVar8 = lVar8 + 4;
        } while (iVar1 != iVar12);
        uVar5 = (ushort)local_7c;
        puVar13 = (ushort *)(lVar9 + *(long *)(param_2 + 2));
        uVar15 = uVar11 - (short)uVar14;
      }
      *local_50 = uVar11;
      local_50[1] = uVar15;
      local_48[1] = *local_48 - (short)local_74;
      uVar5 = *puVar13 - uVar5;
    }
    else {
      local_48 = (ushort *)0x0;
      *(undefined1 *)(lVar8 + 6) = 1;
      if (iVar1 < 2) {
        uVar5 = 0;
        uVar11 = _DAT_00000000;
      }
      else {
        lVar8 = 4;
        iVar12 = 1;
        do {
          if (local_78 == 0 && uVar14 == 0) goto LAB_0013c388;
          if (local_78 == 0) {
            iVar7 = FUN_0013bdf0(param_1,&local_48,&local_68,&local_58,&local_6c,0,param_2,iVar12,
                                 &local_7c,&local_78);
            lVar10 = (long)iVar7;
            uVar14 = local_7c;
            if (lVar10 != 0) goto LAB_0013c0d4;
          }
          uVar11 = *local_48;
          local_58[1] = iVar12;
          if (uVar11 != local_78) {
            *local_58 = *(undefined4 *)(*(long *)(param_2 + 4) + lVar8);
          }
          local_58 = local_58 + 2;
          local_78 = local_78 - 1;
          iVar12 = iVar12 + 1;
          lVar8 = lVar8 + 4;
        } while (iVar1 != iVar12);
        puVar13 = (ushort *)(lVar9 + *(long *)(param_2 + 2));
        uVar5 = *puVar13 - (short)uVar14;
        uVar11 = uVar11 - (short)local_78;
      }
      local_48[1] = uVar11;
    }
  }
  else {
    uVar5 = 0;
    local_68 = puVar13;
    if (1 < iVar1) {
      puVar13[2] = 1;
      puVar13[3] = 0;
      lVar8 = 8;
      iVar12 = 1;
      while (iVar12 = iVar12 + 1, iVar1 != iVar12) {
        lVar9 = *(long *)(param_2 + 4);
        *(int *)(puVar13 + lVar8 + -2) = iVar12;
        *(undefined4 *)(puVar13 + lVar8 + -4) = *(undefined4 *)(lVar9 + lVar8);
        lVar8 = lVar8 + 4;
      }
      uVar5 = (short)iVar1 - 1;
    }
  }
  puVar13[1] = uVar5;
  lVar10 = 0;
LAB_0013c0d4:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar10;
LAB_0013c388:
  lVar10 = 0x1c;
  goto LAB_0013c0d4;
}



// Function: is_fake_entry @ 0x3c410

ulong is_fake_entry(long param_1,int param_2,uint param_3)

{
  ulong uVar1;
  undefined1 auVar2 [12];
  
  if ((param_2 != 0) || (uVar1 = 1, 0xc < param_3)) {
    auVar2 = FUN_0013b900(*(undefined4 *)(*(long *)(param_1 + 0x20) + 100));
    uVar1 = auVar2._0_8_;
    if (auVar2._0_4_ != 0) {
      return (ulong)((ulong)(auVar2._8_4_ & *(uint *)(param_1 + 0x28) - 1) ==
                    (ulong)*(uint *)(param_1 + 0x28) - 0xc);
    }
  }
  return uVar1;
}



// Function: fill_dir_block @ 0x3c450

undefined8
fill_dir_block(long param_1,long *param_2,long param_3,undefined8 param_4,undefined8 param_5,
            long *param_6)

{
  uint *puVar1;
  undefined8 *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  void *__s;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
  uint uVar13;
  uint uVar14;
  ulong uVar15;
  uint uVar16;
  long in_FS_OFFSET;
  uint local_6c;
  uint local_50;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (-1 < param_3) {
    uVar4 = *(uint *)(param_1 + 0x28);
    uVar16 = uVar4 * (int)param_3;
    if (*(uint *)(param_6[1] + 4) < uVar4 + uVar16) {
LAB_0013c6c3:
      param_6[3] = 0x7f2bb723;
      uVar11 = 2;
      goto LAB_0013c6d0;
    }
    lVar10 = *param_2;
    __s = (void *)(*param_6 + (ulong)uVar16);
    if (lVar10 == 0) {
      memset(__s,0,(ulong)uVar4);
      ext2fs_set_rec_len(param_1,*(undefined4 *)(param_1 + 0x28),__s);
    }
    else {
      uVar4 = *(uint *)(param_1 + 0x10);
      lVar6 = param_6[9];
      *(uint *)(param_1 + 0x10) = uVar4 | 0x200000;
      lVar10 = ext2fs_read_dir_block4(param_1,lVar10,__s,0,(int)lVar6);
      uVar16 = *(uint *)(param_1 + 0x10);
      param_6[3] = lVar10;
      *(uint *)(param_1 + 0x10) = uVar16 & 0xffdfffff | uVar4 & 0x200000;
      if (lVar10 != 0) {
LAB_0013c7f8:
        uVar11 = 2;
        goto LAB_0013c6d0;
      }
    }
    uVar4 = *(uint *)(param_6[1] + 0x20);
    iVar7 = FUN_0013ab60();
    bVar3 = *(byte *)(*(long *)(param_1 + 0x20) + 0xfc);
    local_50 = (uint)bVar3;
    if ((local_50 < 3) &&
       (local_50 = bVar3 + 3, (*(byte *)(*(long *)(param_1 + 0x20) + 0x160) & 2) == 0)) {
      local_50 = (uint)bVar3;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      uVar15 = 0;
      do {
        if (iVar7 == 0) {
          local_6c = 0;
          uVar16 = 8;
        }
        else {
          iVar9 = FUN_0013c410(param_1,(int)param_3,uVar15);
          local_6c = (uint)(iVar9 == 0);
          uVar16 = (-(uint)(iVar9 == 0) & 8) + 8;
        }
        puVar1 = (uint *)((long)__s + uVar15);
        ext2fs_get_rec_len(param_1,puVar1,&local_44);
        uVar8 = ext2fs_dirent_name_len(puVar1);
        uVar13 = *(uint *)(param_1 + 0x28);
        uVar14 = (int)uVar15 + local_44;
        uVar15 = (ulong)uVar14;
        if ((((local_44 < uVar16) || (uVar13 < uVar14)) || ((local_44 & 3) != 0)) ||
           (local_44 < uVar16 + uVar8)) goto LAB_0013c6c3;
        uVar16 = *puVar1;
        if (uVar16 == 0) goto LAB_0013c68f;
        if (uVar8 == 0) goto LAB_0013c6c3;
        if ((int)param_6[8] == 0) {
          if (uVar8 == 1) {
            if ((char)puVar1[2] != '.') goto LAB_0013c610;
          }
          else {
            if ((uVar8 != 2) || ((short)puVar1[2] != 0x2e2e)) goto LAB_0013c610;
            *(uint *)((long)param_6 + 0x44) = uVar16;
          }
        }
        else {
LAB_0013c610:
          uVar5 = *(uint *)((long)param_6 + 0x34);
          uVar13 = *(uint *)(param_6 + 6);
          if (uVar13 <= uVar5) {
            lVar10 = ext2fs_resize_array(0x18,uVar13,uVar13 + 500,param_6 + 5);
            if (lVar10 != 0) {
              param_6[3] = lVar10;
              goto LAB_0013c7f8;
            }
            *(int *)(param_6 + 6) = (int)param_6[6] + 500;
            uVar5 = *(uint *)((long)param_6 + 0x34);
            uVar16 = *puVar1;
          }
          uVar12 = (ulong)uVar16;
          *(uint *)((long)param_6 + 0x34) = uVar5 + 1;
          puVar2 = (undefined8 *)(param_6[5] + (ulong)uVar5 * 0x18);
          puVar2[2] = puVar1;
          uVar16 = FUN_0013ab80(uVar8 & 0xff);
          param_6[7] = param_6[7] + (ulong)uVar16;
          puVar2[1] = uVar12 & 0xffffffff;
          if (local_6c == 0) {
            if ((int)param_6[8] == 0) {
              lVar10 = ext2fs_dirhash2(local_50,puVar1 + 2,uVar8,*(undefined8 *)(param_1 + 0x168),
                                       uVar4 & 0x40000000,*(long *)(param_1 + 0x20) + 0xec,puVar2,
                                       (long)puVar2 + 4);
              param_6[3] = lVar10;
              if (lVar10 != 0) goto LAB_0013c7f8;
              uVar13 = *(uint *)(param_1 + 0x28);
            }
            else {
              *puVar2 = 0;
              uVar13 = *(uint *)(param_1 + 0x28);
            }
          }
          else {
            iVar9 = ext2fs_dirent_name_len(puVar1);
            *(undefined4 *)puVar2 =
                 *(undefined4 *)((long)puVar1 + (long)(int)(iVar9 + 3U & 0xfffffffc) + 8);
            iVar9 = ext2fs_dirent_name_len(puVar1);
            uVar13 = *(uint *)(param_1 + 0x28);
            *(undefined4 *)((long)puVar2 + 4) =
                 *(undefined4 *)((long)puVar1 + (long)(int)(iVar9 + 3U & 0xfffffffc) + 0xc);
          }
        }
LAB_0013c68f:
      } while (uVar14 < uVar13);
    }
  }
  uVar11 = 0;
LAB_0013c6d0:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}



// Function: e2fsck_rehash_dir_later @ 0x3c820

void e2fsck_rehash_dir_later(long param_1,undefined4 param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x248);
  if (lVar1 == 0) {
    ext2fs_u32_list_create(param_1 + 0x248,0x32);
    lVar1 = *(long *)(param_1 + 0x248);
    if (lVar1 == 0) {
      return;
    }
  }
  ext2fs_u32_list_add(lVar1,param_2);
  return;
}



// Function: e2fsck_dir_will_be_rehashed @ 0x3c880

undefined8 e2fsck_dir_will_be_rehashed(long param_1)

{
  undefined8 uVar1;
  
  if ((*(uint *)(param_1 + 0x4c) & 0x400) == 0) {
    uVar1 = 0;
    if (*(long *)(param_1 + 0x248) != 0) {
      uVar1 = ext2fs_u32_list_test();
      return uVar1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// Function: e2fsck_rehash_dir @ 0x3c8b0

long e2fsck_rehash_dir(long *param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long in_FS_OFFSET;
  undefined1 *local_170;
  void *local_150;
  undefined4 local_148 [2];
  long local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  uint local_e8;
  uint uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  int iStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined1 local_c8 [4];
  uint local_c4;
  byte local_a5;
  long local_40;
  
  lVar1 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_148[0] = 0;
  local_150 = (void *)0x0;
  local_138 = 0;
  local_130 = 0;
  local_128 = 0;
  local_140 = 0;
  local_118 = (undefined1  [16])0x0;
  local_108 = (undefined1  [16])0x0;
  local_f8 = (undefined1  [16])0x0;
  local_e8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  iStack_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_cc = 0;
  e2fsck_read_inode(param_1,param_2,local_c8,"rehash_dir");
  iVar2 = FUN_0013b8e0(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x60));
  if ((iVar2 == 0) || (lVar3 = 0, (local_a5 & 0x10) == 0)) {
    lVar3 = ext2fs_get_mem(local_c4,&local_150);
    if (lVar3 == 0) {
      local_e8 = local_c4 >> 5;
      lVar3 = ext2fs_get_array(0x18);
      if (lVar3 == 0) {
        local_108._0_4_ = param_2;
        local_f8._0_8_ = param_1;
        local_118._8_8_ = local_c8;
        local_118._0_8_ = local_150;
        uStack_d0 = param_2;
        iVar2 = FUN_0013c810(*(undefined4 *)(*(long *)(lVar1 + 0x20) + 0x5c));
        if ((iVar2 == 0) || (local_c4 / *(uint *)(lVar1 + 0x28) < 2)) {
          iStack_d8 = 1;
        }
        uStack_d4 = 0;
        if ((*(long *)(lVar1 + 0x168) != 0) && ((local_a5 & 0x40) != 0)) {
          local_148[0] = 1;
          local_140 = *(long *)(lVar1 + 0x168);
        }
LAB_0013cae7:
        ext2fs_block_iterate3(lVar1,param_2,0,0,FUN_0013c450,local_118);
        lVar3 = local_108._8_8_;
        if (local_108._8_8_ == 0) {
          if ((iStack_d8 == 0) &&
             (CONCAT44(uStack_dc,uStack_e0) < (long)(ulong)(*(int *)(lVar1 + 0x28) - 0x18)))
          goto code_r0x0013cad3;
          do {
            if ((iStack_d8 == 0) || (uStack_e4 < 2)) {
              FUN_0013b5f0(local_f8._8_8_,uStack_e4,local_148);
            }
            else {
              FUN_0013b5f0(local_f8._8_8_ + 0x30,uStack_e4 - 2,local_148);
            }
            iVar2 = FUN_0013ae50(param_1,lVar1,param_2,local_118,local_148);
          } while (iVar2 != 0);
          if ((*(byte *)((long)param_1 + 0x4c) & 8) == 0) {
            if ((iStack_d8 != 0) && (1 < uStack_e4)) {
              qsort((void *)(local_f8._8_8_ + 0x30),(ulong)(uStack_e4 - 2),0x18,FUN_0013ac10);
            }
            lVar3 = FUN_0013b910(param_1,local_118,&local_138);
            if (lVar3 == 0) {
              free(local_150);
              local_150 = (void *)0x0;
              if (iStack_d8 == 0) {
                lVar3 = FUN_0013c010(lVar1,&local_138,param_2,uStack_d4,local_118._8_8_);
                if (lVar3 != 0) goto LAB_0013c9ae;
              }
              lVar3 = FUN_0013b190(param_1,lVar1,&local_138,param_2,local_c8,iStack_d8);
              if (lVar3 == 0) {
                if ((*(byte *)((long)param_1 + 0x4d) & 0x40) == 0) {
                  lVar3 = e2fsck_check_rebuild_extents(param_1,param_2,local_c8,param_3);
                }
                else {
                  lVar3 = e2fsck_rebuild_extents_later(param_1,param_2);
                }
              }
            }
          }
        }
      }
    }
LAB_0013c9ae:
    local_170 = local_f8 + 8;
    ext2fs_free_mem(&local_150);
    ext2fs_free_mem(local_170);
    FUN_0013ac20(&local_138);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
code_r0x0013cad3:
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  iStack_d8 = 1;
  goto LAB_0013cae7;
}



// Function: e2fsck_rehash_directories @ 0x3ccc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void e2fsck_rehash_directories(long *param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  uint uVar6;
  long in_FS_OFFSET;
  double dVar7;
  int local_118;
  int local_114;
  undefined4 local_104;
  undefined8 local_100;
  undefined1 local_f8 [80];
  long local_a8 [2];
  undefined4 local_98;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  init_resource_track(local_f8,*(undefined8 *)(*param_1 + 8));
  uVar6 = *(uint *)((long)param_1 + 0x4c) & 0x400;
  if (param_1[0x49] == 0) {
    if (uVar6 == 0) goto LAB_0013cf37;
    e2fsck_get_lost_and_found(param_1,0);
    clear_problem_context(local_a8);
LAB_0013ce7f:
    uVar5 = e2fsck_dir_info_iter_begin(param_1);
    local_114 = e2fsck_get_num_dirinfo(param_1);
  }
  else {
    e2fsck_get_lost_and_found(param_1,0);
    clear_problem_context(local_a8);
    if (uVar6 != 0) goto LAB_0013ce7f;
    lVar3 = ext2fs_u32_list_iterate_begin(param_1[0x49],&local_100);
    if (lVar3 != 0) {
      local_a8[0] = lVar3;
      fix_problem(param_1,0x31001,local_a8);
      goto LAB_0013cf37;
    }
    uVar5 = 0;
    local_114 = ext2fs_u32_list_count(param_1[0x49]);
  }
  local_118 = 0;
  bVar1 = true;
LAB_0013cd80:
  if (uVar6 == 0) goto LAB_0013cdf5;
  while (puVar4 = (undefined4 *)e2fsck_dir_info_iter(param_1,uVar5), puVar4 != (undefined4 *)0x0) {
    local_104 = *puVar4;
    while( true ) {
      iVar2 = ext2fs_test_inode_bitmap2(param_1[0x2f],local_104);
      if (iVar2 == 0) goto LAB_0013cd80;
      local_98 = local_104;
      if (bVar1) {
        fix_problem(param_1,0x31000,local_a8);
      }
      local_a8[0] = e2fsck_rehash_dir(param_1,local_104,local_a8);
      if (local_a8[0] != 0) {
        end_problem_latch(param_1,0x90);
        fix_problem(param_1,0x31002,local_a8);
      }
      if ((param_1[0x2c] != 0) && ((int)param_1[0x59] == 0)) {
        local_118 = local_118 + 1;
        dVar7 = ((double)local_118 * _DAT_00178cd0) / (double)local_114;
        e2fsck_simple_progress
                  (CONCAT44((int)((ulong)dVar7 >> 0x20),(float)dVar7),param_1,"Rebuilding directory"
                   ,local_104);
      }
      bVar1 = false;
      if (uVar6 != 0) break;
LAB_0013cdf5:
      iVar2 = ext2fs_u32_list_iterate(local_100,&local_104);
      if (iVar2 == 0) {
        end_problem_latch(param_1,0x90);
        ext2fs_u32_list_iterate_end(local_100);
        goto LAB_0013cf00;
      }
    }
  }
  end_problem_latch(param_1,0x90);
  e2fsck_dir_info_iter_end(param_1,uVar5);
LAB_0013cf00:
  if (param_1[0x49] != 0) {
    ext2fs_u32_list_free();
  }
  param_1[0x49] = 0;
  print_resource_track(param_1,"Pass 3A",local_f8,*(undefined8 *)(*param_1 + 8));
LAB_0013cf37:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: append_string @ 0x3cfa0

void append_string(long *param_1,char *param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  void *__ptr;
  int iVar3;
  
  if (param_3 == 0) {
    sVar2 = strlen(param_2);
    param_3 = (int)sVar2;
  }
  iVar1 = *(int *)((long)param_1 + 0xc);
  __ptr = (void *)*param_1;
  iVar3 = iVar1 + 1 + param_3;
  if ((int)param_1[1] < iVar3) {
    iVar1 = (int)param_1[1] * 2;
    if (iVar3 <= iVar1) {
      iVar3 = iVar1;
    }
    __ptr = realloc(__ptr,(long)iVar3);
    if (__ptr == (void *)0x0) {
      return;
    }
    *param_1 = (long)__ptr;
    iVar1 = *(int *)((long)param_1 + 0xc);
    *(int *)(param_1 + 1) = iVar3;
  }
  memcpy((void *)((long)__ptr + (long)iVar1),param_2,(long)param_3);
  param_3 = param_3 + *(int *)((long)param_1 + 0xc);
  *(int *)((long)param_1 + 0xc) = param_3;
  *(undefined1 *)(*param_1 + (long)param_3) = 0;
  return;
}



// Function: do_read @ 0x3d3c0

ulong do_read(int param_1)

{
  int iVar1;
  ulong uVar2;
  void *pvVar3;
  int iVar4;
  long lVar5;
  long in_FS_OFFSET;
  undefined1 auStack_1038 [4104];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = read(param_1,auStack_1038,0xfff);
  iVar1 = (int)uVar2;
  if (0 < iVar1) {
    lVar5 = (long)DAT_001b7398;
    iVar4 = DAT_001b7398 + iVar1;
    pvVar3 = realloc(DAT_001b7390,(long)iVar4);
    if (pvVar3 != (void *)0x0) {
      DAT_001b7390 = pvVar3;
      memcpy((void *)((long)pvVar3 + lVar5),auStack_1038,(long)iVar1);
      DAT_001b7398 = iVar4;
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2 & 0xffffffff;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: save_output @ 0x3d470

FILE * save_output(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  __pid_t _Var3;
  int iVar4;
  ssize_t sVar5;
  int *piVar6;
  FILE *pFVar7;
  void *__buf;
  long in_FS_OFFSET;
  int local_48;
  int local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 == (char *)0x0) {
    if ((param_2 != (char *)0x0) && (*param_2 != '\0')) goto LAB_0013d5ea;
LAB_0013d4b7:
    pFVar7 = (FILE *)0x0;
    if (param_3 == (char *)0x0) goto LAB_0013d610;
    if (*param_3 == '\0') {
      pFVar7 = (FILE *)0x0;
      goto LAB_0013d610;
    }
    param_1 = (char *)0x0;
LAB_0013d4cd:
    param_2 = (char *)0x0;
  }
  else {
    if (*param_1 == '\0') {
      if ((param_2 == (char *)0x0) || (*param_2 == '\0')) goto LAB_0013d4b7;
      param_1 = (char *)0x0;
LAB_0013d5ea:
      if (param_3 == (char *)0x0) goto LAB_0013d4d0;
    }
    else {
      if ((param_2 != (char *)0x0) && (*param_2 != '\0')) goto LAB_0013d5ea;
      if (param_3 == (char *)0x0) goto LAB_0013d4cd;
      param_2 = (char *)0x0;
    }
    if (*param_3 == '\0') {
      if (param_1 == (char *)0x0 && param_2 == (char *)0x0) {
        pFVar7 = (FILE *)0x0;
        goto LAB_0013d610;
      }
      param_3 = (char *)0x0;
    }
  }
LAB_0013d4d0:
  iVar2 = pipe(&local_48);
  if (iVar2 < 0) {
    perror("pipe");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  _Var3 = fork();
  if (_Var3 < 0) {
    perror("fork");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (_Var3 == 0) {
    if ((e2fsck_global_ctx != 0) && (*(int *)(e2fsck_global_ctx + 0x2c8) != 0)) {
      close(*(int *)(e2fsck_global_ctx + 0x2c8));
    }
    iVar2 = daemon(0,0);
    if (iVar2 < 0) {
      perror("daemon");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    close(local_44);
    do {
      iVar2 = FUN_0013d3c0(local_48);
    } while (0 < iVar2);
    iVar2 = -1;
    close(local_48);
    while( true ) {
      if (param_1 != (char *)0x0) {
        iVar2 = open(param_1,0x241,0x1a4);
      }
      cVar1 = (char)((uint)iVar2 >> 0x18);
      if (iVar2 < 0) {
        if (param_2 != (char *)0x0) {
          iVar2 = open(param_2,0x241,0x1a4);
          cVar1 = (char)((uint)iVar2 >> 0x18);
        }
        if ((cVar1 < '\0') && (param_3 != (char *)0x0)) {
          iVar2 = open(param_3,0x241,0x1a4);
        }
      }
      __buf = DAT_001b7390;
      if (-1 < iVar2) break;
      sleep(1);
    }
    while (0 < DAT_001b7398) {
      while( true ) {
        sVar5 = write(iVar2,__buf,(long)DAT_001b7398);
        iVar4 = (int)sVar5;
        if (iVar4 < 0) break;
        DAT_001b7398 = DAT_001b7398 - iVar4;
        __buf = (void *)((long)__buf + (long)iVar4);
        if (DAT_001b7398 < 1) goto LAB_0013d689;
      }
      piVar6 = __errno_location();
      if ((*piVar6 != 0xb) && (*piVar6 != 4)) {
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
    }
LAB_0013d689:
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  close(local_48);
  pFVar7 = fdopen(local_44,"w");
  if (pFVar7 == (FILE *)0x0) {
    close(local_44);
  }
LAB_0013d610:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pFVar7;
}



// Function: set_up_log_file @ 0x3d8d0

FILE * set_up_log_file(long param_1,undefined8 param_2,long param_3)

{
  size_t sVar1;
  size_t sVar2;
  FILE *pFVar3;
  char *__filename;
  char *__s;
  char *__filename_00;
  char *pcVar4;
  long in_FS_OFFSET;
  int local_8c;
  char *local_88;
  char *local_80;
  char *local_78 [2];
  char *local_68 [2];
  char *local_58 [3];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_8c = 0;
  local_88 = (char *)0x0;
  local_80 = (char *)0x0;
  local_58[0] = (char *)0x0;
  local_68[0] = (char *)0x0;
  local_78[0] = (char *)0x0;
  profile_get_boolean(*(undefined8 *)(param_1 + 0x360),"options","log_dir_wait",0,0,&local_8c);
  if (param_3 == 0) {
    profile_get_string(*(undefined8 *)(param_1 + 0x360),"options",param_2,0,0,&local_80);
  }
  else {
    local_80 = (char *)string_copy(param_1,param_3,0);
  }
  profile_get_string(*(undefined8 *)(param_1 + 0x360),"options","log_dir",0,0,&local_88);
  if (local_80 == (char *)0x0) {
    __filename = (char *)0x0;
    __filename_00 = (char *)0x0;
    __s = (char *)0x0;
    pFVar3 = (FILE *)0x0;
    goto LAB_0013dab3;
  }
  if (*local_80 == '\0') {
    __filename = (char *)0x0;
    __filename_00 = (char *)0x0;
    __s = (char *)0x0;
  }
  else {
    FUN_0013d7c0(param_1,local_80,local_78);
    __s = local_78[0];
    pcVar4 = local_78[0];
    if (*local_80 == '/') {
      if (local_88 == (char *)0x0) goto LAB_0013dbb5;
LAB_0013da4e:
      if (*local_88 != '\0') goto LAB_0013d9e1;
      __filename_00 = (char *)0x0;
    }
    else if (local_88 == (char *)0x0) {
LAB_0013dbb5:
      __filename_00 = (char *)0x0;
    }
    else {
      if (*local_88 == '\0') goto LAB_0013da4e;
      pcVar4 = (char *)0x0;
LAB_0013d9e1:
      sVar1 = strlen(local_88);
      sVar2 = strlen(__s);
      FUN_0013d790(local_68,(int)sVar1 + 2 + (int)sVar2);
      FUN_0013cfa0(local_68,local_88,0);
      FUN_0013cfa0(local_68,&DAT_0017eccd,1);
      FUN_0013cfa0(local_68,__s,0);
      __filename_00 = local_68[0];
    }
    free(local_88);
    profile_get_string(*(undefined8 *)(param_1 + 0x360),"options","log_dir_fallback",0,0,&local_88);
    __filename = (char *)0x0;
    if (local_88 != (char *)0x0) {
      if (*local_88 == '\0') {
        __filename = (char *)0x0;
      }
      else {
        sVar1 = strlen(local_88);
        sVar2 = strlen(__s);
        FUN_0013d790(local_58,(int)sVar1 + 2 + (int)sVar2);
        FUN_0013cfa0(local_58,local_88,0);
        FUN_0013cfa0(local_58,&DAT_0017eccd,1);
        FUN_0013cfa0(local_58,__s,0);
        __filename = local_58[0];
        __printf_chk(1,"%s\n",local_58[0]);
      }
    }
    if ((((pcVar4 != (char *)0x0) && (pFVar3 = fopen(pcVar4,"w"), pFVar3 != (FILE *)0x0)) ||
        ((__filename_00 != (char *)0x0 && (pFVar3 = fopen(__filename_00,"w"), pFVar3 != (FILE *)0x0)
         ))) || ((__filename != (char *)0x0 &&
                 (pFVar3 = fopen(__filename,"w"), pFVar3 != (FILE *)0x0)))) goto LAB_0013dab3;
    if (local_8c != 0) {
      pFVar3 = (FILE *)FUN_0013d470(pcVar4,__filename_00,__filename);
      goto LAB_0013dab3;
    }
  }
  pFVar3 = (FILE *)0x0;
LAB_0013dab3:
  free(__s);
  free(__filename_00);
  free(__filename);
  free(local_80);
  free(local_88);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pFVar3;
}



// Function: set_up_logging @ 0x3dc50

void set_up_logging(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_0013d8d0(param_1,"log_filename",*(undefined8 *)(param_1 + 0x30));
  *(undefined8 *)(param_1 + 0x28) = uVar1;
  uVar1 = FUN_0013d8d0(param_1,"problem_log_filename",*(undefined8 *)(param_1 + 0x40));
  *(undefined8 *)(param_1 + 0x38) = uVar1;
  return;
}



// Function: lookup_table_fallback @ 0x3dcb0

undefined * lookup_table_fallback(ulong param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)thunk_FUN_0013dca0();
  if (puVar1 != (undefined *)0x0) {
    return puVar1;
  }
  __snprintf_chk(&DAT_001b73a0,0x20,1,0x20,&DAT_0017adb6,param_1 & 0xffffffff);
  DAT_001b73bf = 0;
  return &DAT_001b73a0;
}



// Function: die_signal_handler @ 0x3dd00

void die_signal_handler(ulong param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  undefined1 auStack_128 [264];
  undefined8 local_20;
  
  local_20 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  uVar3 = FUN_0013dcb0(param_1,&DAT_001b6340);
  __fprintf_chk(stderr,1,"Signal (%d) %s ",param_1 & 0xffffffff,uVar3);
  uVar1 = *(uint *)(param_2 + 8);
  if (uVar1 == 0) {
    __fprintf_chk(stderr,1,"(sent from pid %u) ",*(undefined4 *)(param_2 + 0x10));
    uVar1 = *(uint *)(param_2 + 8);
  }
  uVar5 = (ulong)uVar1;
  lVar4 = thunk_FUN_0013dca0(uVar5,&DAT_001b62a0);
  if (lVar4 == 0) {
    switch((uint)param_1) {
    case 4:
      break;
    default:
      __fprintf_chk(stderr,1,"si code=%d ",uVar5 & 0xffffffff);
      goto LAB_0013dd90;
    case 7:
      break;
    case 8:
      break;
    case 0xb:
      break;
    case 0x11:
      uVar3 = FUN_0013dcb0();
      __fprintf_chk(stderr,1,"si_code=%s ",uVar3);
      goto LAB_0013ddb0;
    }
    uVar3 = FUN_0013dcb0();
    __fprintf_chk(stderr,1,"si_code=%s ",uVar3);
    if (*(int *)(param_2 + 8) == 0) goto LAB_0013ddb0;
  }
  else {
    __fprintf_chk(stderr,1,"si_code=%s ");
LAB_0013dd90:
    if (((*(int *)(param_2 + 8) == 0) || (0xb < (uint)param_1)) ||
       ((0x990UL >> ((byte)(param_1 & 0xffffffff) & 0x3f) & 1) == 0)) goto LAB_0013ddb0;
  }
  __fprintf_chk(stderr,1,"fault addr=%p",*(undefined8 *)(param_2 + 0x10));
LAB_0013ddb0:
  __fprintf_chk(stderr,1,"\n");
  uVar2 = backtrace(auStack_128,0x20);
  backtrace_symbols_fd(auStack_128,uVar2,2);
                    /* WARNING: Subroutine does not return */
  exit(8);
}



// Function: sigcatcher_setup @ 0x3df00

void sigcatcher_setup(void)

{
  sigaction *psVar1;
  long lVar2;
  __sigset_t *p_Var3;
  long in_FS_OFFSET;
  sigaction local_a8;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  psVar1 = &local_a8;
  for (lVar2 = 0x12; p_Var3 = &psVar1->sa_mask, lVar2 != 0; lVar2 = lVar2 + -1) {
    psVar1 = (sigaction *)p_Var3->__val;
    p_Var3->__val[0] = 0;
  }
  local_a8.sa_flags = 4;
  local_a8.__sigaction_handler.sa_handler = FUN_0013dd00;
  sigaction(8,&local_a8,(sigaction *)0x0);
  sigaction(4,&local_a8,(sigaction *)0x0);
  sigaction(7,&local_a8,(sigaction *)0x0);
  sigaction(0xb,&local_a8,(sigaction *)0x0);
  sigaction(6,&local_a8,(sigaction *)0x0);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: readahead_dir_block @ 0x3dfc0

bool readahead_dir_block(long param_1,long param_2,long *param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = 1;
  if ((*(byte *)(param_3 + 3) & 1) == 0) {
    lVar4 = *(long *)(param_2 + 0x10);
  }
  lVar1 = param_3[2];
  lVar3 = *(long *)(param_2 + 8);
  if (lVar1 == 0) {
    lVar2 = *param_3;
  }
  else {
    if (lVar1 + param_3[1] == lVar3) {
      lVar2 = *param_3;
      lVar4 = lVar4 + lVar1;
      goto LAB_0013dff2;
    }
    lVar2 = io_channel_cache_readahead(*(undefined8 *)(param_1 + 8));
    lVar3 = *(long *)(param_2 + 8);
    *param_3 = lVar2;
  }
  param_3[1] = lVar3;
LAB_0013dff2:
  param_3[2] = lVar4;
  return lVar2 != 0;
}



// Function: mark_bmap @ 0x3e040

undefined8 mark_bmap(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = ext2fs_get_generic_bmap_start();
  if (uVar1 <= param_2) {
    uVar1 = ext2fs_get_generic_bmap_end(param_1);
    if (param_2 <= uVar1) {
      ext2fs_mark_block_bitmap2(param_1,param_2);
      return 0;
    }
  }
  return 0x7f2bb747;
}



// Function: mark_bmap_range @ 0x3e090

undefined8 mark_bmap_range(undefined8 param_1,ulong param_2,uint param_3)

{
  ulong uVar1;
  
  uVar1 = ext2fs_get_generic_bmap_start();
  if (uVar1 <= param_2) {
    uVar1 = ext2fs_get_generic_bmap_end(param_1);
    if (param_3 + param_2 <= uVar1) {
      ext2fs_mark_block_bitmap_range2(param_1,param_2,param_3);
      return 0;
    }
  }
  return 0x7f2bb747;
}



// Function: e2fsck_readahead_bitmap @ 0x3e0f0

long e2fsck_readahead_bitmap(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long in_FS_OFFSET;
  long local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = ext2fs_blocks_count(*(undefined8 *)(param_1 + 0x20));
  lVar3 = lVar3 + -1;
  lVar4 = ext2fs_find_first_set_block_bitmap2(param_2,1,lVar3,&local_48);
  lVar1 = local_48;
  while (local_48 = lVar1, lVar4 == 0) {
    lVar4 = ext2fs_find_first_zero_block_bitmap2(param_2,lVar1,lVar3,&local_48);
    if (lVar4 == 2) {
      local_48 = lVar3;
      if (lVar3 == lVar1) goto LAB_0013e1a6;
    }
    else if (lVar4 != 0) goto LAB_0013e1a8;
    lVar2 = local_48;
    lVar4 = io_channel_cache_readahead(*(undefined8 *)(param_1 + 8),lVar1,local_48 - lVar1);
    if (lVar4 != 0) break;
    lVar4 = ext2fs_find_first_set_block_bitmap2(param_2,lVar2,lVar3,&local_48);
    lVar1 = local_48;
  }
  if (lVar4 == 2) {
LAB_0013e1a6:
    lVar4 = 0;
  }
LAB_0013e1a8:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_readahead_dblist @ 0x3e1d0

long e2fsck_readahead_dblist
               (long param_1,uint param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  long lVar1;
  long lVar2;
  long in_FS_OFFSET;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = 0x7f2bb747;
  if ((param_2 & 0xfffffffe) == 0) {
    local_28 = ZEXT416(param_2) << 0x40;
    local_38 = (undefined1  [16])0x0;
    lVar1 = ext2fs_dblist_iterate3(param_3,FUN_0013dfc0,param_4,param_5,local_38);
    lVar2 = local_38._0_8_;
    if (((local_38._0_8_ == 0) && (lVar2 = lVar1, lVar1 == 0)) && (local_28._0_8_ != 0)) {
      lVar2 = io_channel_cache_readahead(*(undefined8 *)(param_1 + 8),local_38._8_8_);
    }
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar2;
}



// Function: e2fsck_readahead @ 0x3e280

long e2fsck_readahead(long param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  long in_FS_OFFSET;
  int local_64;
  undefined8 local_60;
  long local_58;
  long local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar4 = 0x7f2bb747;
  local_48 = 0;
  if (((param_2 & 0xffffffe0) == 0) && (lVar4 = 0, param_2 != 0)) {
    uVar5 = *(uint *)(param_1 + 0x30);
    lVar4 = ext2fs_allocate_block_bitmap(param_1,"readahead bitmap",&local_48);
    if (lVar4 == 0) {
      if (param_3 + param_4 <= uVar5) {
        uVar5 = param_3 + param_4;
      }
      if (param_3 < uVar5) {
        do {
          lVar4 = ext2fs_super_and_bgd_loc2(param_1,param_3,&local_60,&local_58,&local_50,&local_64)
          ;
          if ((lVar4 != 0) ||
             (((param_2 & 1) != 0 && (lVar4 = FUN_0013e040(local_48,local_60), lVar4 != 0))))
          goto LAB_0013e3e0;
          if ((param_2 & 2) != 0) {
            lVar4 = local_58;
            if (local_58 == 0) {
              lVar4 = local_50;
            }
            lVar4 = FUN_0013e090(local_48,lVar4,local_64);
            if (lVar4 != 0) goto LAB_0013e3e0;
          }
          if ((((param_2 & 4) != 0) && (iVar1 = ext2fs_bg_flags_test(param_1,param_3,2), iVar1 == 0)
              ) && (uVar2 = ext2fs_bg_free_blocks_count(param_1,param_3),
                   uVar2 < *(uint *)(*(long *)(param_1 + 0x20) + 0x20))) {
            local_60 = ext2fs_block_bitmap_loc(param_1,param_3);
            lVar4 = FUN_0013e040(local_48,local_60);
            if (lVar4 != 0) goto LAB_0013e3e0;
          }
          if ((((param_2 & 8) != 0) && (iVar1 = ext2fs_bg_flags_test(param_1,param_3,1), iVar1 == 0)
              ) && (uVar2 = ext2fs_bg_free_inodes_count(param_1,param_3),
                   uVar2 < *(uint *)(*(long *)(param_1 + 0x20) + 0x28))) {
            local_60 = ext2fs_inode_bitmap_loc(param_1,param_3);
            lVar4 = FUN_0013e040(local_48,local_60);
            if (lVar4 != 0) goto LAB_0013e3e0;
          }
          if (((param_2 & 0x10) != 0) &&
             (uVar2 = ext2fs_bg_free_inodes_count(param_1,param_3),
             uVar2 < *(uint *)(*(long *)(param_1 + 0x20) + 0x28))) {
            local_60 = ext2fs_inode_table_loc(param_1,param_3);
            iVar1 = *(int *)(param_1 + 0x48);
            iVar3 = ext2fs_bg_itable_unused(param_1,param_3);
            uVar2 = 0x80;
            if (*(int *)(*(long *)(param_1 + 0x20) + 0x4c) != 0) {
              uVar2 = (uint)*(ushort *)(*(long *)(param_1 + 0x20) + 0x58);
            }
            local_64 = iVar1 - (iVar3 * uVar2) / *(uint *)(param_1 + 0x28);
            lVar4 = FUN_0013e090(local_48,local_60);
            if (lVar4 != 0) goto LAB_0013e3e0;
          }
          param_3 = param_3 + 1;
        } while (uVar5 != param_3);
      }
      lVar4 = FUN_0013e0f0(param_1,local_48);
LAB_0013e3e0:
      ext2fs_free_block_bitmap(local_48);
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_can_readahead @ 0x3e560

bool e2fsck_can_readahead(long param_1)

{
  long lVar1;
  
  lVar1 = io_channel_cache_readahead(*(undefined8 *)(param_1 + 8),0,1);
  return lVar1 != 0x7f2bb781;
}



// Function: e2fsck_guess_readahead @ 0x3e590

ulong e2fsck_guess_readahead(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar3 = (ulong)*(uint *)(param_1 + 0x28) * (ulong)*(uint *)(param_1 + 0x48);
  uVar1 = get_memory_size();
  uVar2 = 0;
  if (uVar3 * 100 < uVar1) {
    uVar2 = (uVar3 & 0x7fffffffffffffff) >> 9;
  }
  return uVar2;
}



// Function: find_blocks @ 0x3e5e0

undefined8
find_blocks(undefined8 param_1,long *param_2,long param_3,undefined8 param_4,undefined8 param_5,
            long *param_6)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  
  if (param_3 < 0) {
    *param_6 = *param_6 + 1;
    ext2fs_block_alloc_stats2(param_1,*param_2,0xffffffff);
    return 0;
  }
  uVar3 = *(uint *)(param_6 + 2);
  if (uVar3 != 0) {
    plVar1 = (long *)(param_6[1] + -0x18 + (ulong)uVar3 * 0x18);
    uVar2 = *(uint *)(plVar1 + 2);
    if ((plVar1[1] + (ulong)uVar2 == param_3) && ((ulong)uVar2 + *plVar1 == *param_2)) {
      *(uint *)(plVar1 + 2) = uVar2 + 1;
      return 0;
    }
  }
  if (uVar3 == *(uint *)((long)param_6 + 0x14)) {
    lVar4 = ext2fs_resize_mem(0,uVar3 * 0x18 + 0x1ff8,param_6 + 1);
    param_6[4] = lVar4;
    if (lVar4 != 0) {
      return 2;
    }
    *(int *)((long)param_6 + 0x14) = *(int *)((long)param_6 + 0x14) + 0x155;
    uVar3 = *(uint *)(param_6 + 2);
  }
  plVar1 = (long *)(param_6[1] + (ulong)uVar3 * 0x18);
  lVar4 = *param_2;
  plVar1[1] = param_3;
  *plVar1 = lVar4;
  plVar1[2] = 1;
  *(uint *)(param_6 + 2) = uVar3 + 1;
  return 0;
}



// Function: rewrite_extent_replay @ 0x3e6e0

long rewrite_extent_replay(long *param_1,long *param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  uint uVar7;
  long in_FS_OFFSET;
  long local_80;
  undefined8 local_60;
  long local_58;
  long lStack_50;
  ulong local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined1 (*) [16])(param_3 + 0x28) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_3 + 0x38) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(param_3 + 0x48) = (undefined1  [16])0x0;
  *(undefined8 *)(param_3 + 0x58) = 0;
  *(undefined4 *)(param_3 + 0x60) = 0;
  lVar3 = *param_1;
  *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) & 0xfff7ffff;
  quota_data_sub(param_1[0x4f],param_3,(int)param_2[5],(ulong)*(uint *)(lVar3 + 0x28) * *param_2);
  uVar2 = FUN_0013e5d0(param_3);
  local_80 = ext2fs_iblk_sub_blocks(*param_1,uVar2,*param_2);
  if ((local_80 == 0) &&
     (lVar3 = ext2fs_extent_open2(*param_1,(int)param_2[5],uVar2,&local_60), local_80 = lVar3,
     lVar3 == 0)) {
    lVar4 = ext2fs_get_stat_i_blocks(*param_1,uVar2);
    plVar6 = (long *)param_2[1];
    if ((int)param_2[2] != 0) {
      uVar7 = 0;
      do {
        uVar1 = *(uint *)(plVar6 + 2);
        if (uVar1 != 0) {
          local_58 = *plVar6;
          lStack_50 = plVar6[1];
          local_48 = plVar6[2] & 0x2ffffffff;
          if ((plVar6[2] & 0x200000000U) == 0) {
            if (0x8000 < uVar1) {
              local_48 = CONCAT44(local_48._4_4_,0x8000);
              uVar7 = uVar7 - 1;
              *plVar6 = *plVar6 + 0x8000;
              plVar6[1] = plVar6[1] + 0x8000;
              *(int *)(plVar6 + 2) = (int)plVar6[2] + -0x8000;
              plVar6 = plVar6 + -3;
            }
          }
          else if (0x7fff < uVar1) {
            local_48 = CONCAT44(local_48._4_4_,0x7fff);
            uVar7 = uVar7 - 1;
            *plVar6 = *plVar6 + 0x7fff;
            plVar6[1] = plVar6[1] + 0x7fff;
            *(int *)(plVar6 + 2) = (int)plVar6[2] + -0x7fff;
            plVar6 = plVar6 + -3;
          }
          local_80 = ext2fs_extent_insert(local_60,1,&local_58);
          if ((local_80 != 0) || (local_80 = ext2fs_extent_fix_parents(local_60), local_80 != 0))
          goto LAB_0013e8fc;
        }
        uVar7 = uVar7 + 1;
        plVar6 = plVar6 + 3;
      } while (uVar7 < *(uint *)(param_2 + 2));
    }
    lVar5 = ext2fs_get_stat_i_blocks(*param_1,uVar2);
    if (lVar5 - lVar4 != 0) {
      quota_data_add(param_1[0x4f],param_3,(int)param_2[5],(lVar5 - lVar4) * 0x200);
    }
    e2fsck_write_inode(param_1,(int)param_2[5],uVar2,"rebuild_extents");
    local_80 = lVar3;
LAB_0013e8fc:
    ext2fs_extent_free(local_60);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_80;
}



// Function: rebuild_extent_tree @ 0x3eb00

ulong rebuild_extent_tree(undefined8 *param_1,undefined8 *param_2,ulong param_3)

{
  ulong uVar1;
  long lVar2;
  long in_FS_OFFSET;
  undefined1 auStack_d8 [26];
  short local_be;
  uint local_b8;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  *(int *)(param_2 + 5) = (int)param_3;
  *(undefined4 *)(param_2 + 2) = 0;
  *param_2 = 0;
  *(undefined4 *)(param_2 + 3) = 0;
  FUN_0013e5d0(auStack_d8,param_3 & 0xffffffff,param_3,0xa0,"rebuild_extents");
  e2fsck_read_inode_full(param_1);
  uVar1 = 0;
  if ((local_be != 0) && ((local_b8 & 0x10000000) == 0)) {
    if ((local_b8 & 0x80000) == 0) {
      lVar2 = ext2fs_block_iterate3(*param_1,param_3 & 0xffffffff,8,0,FUN_0013e5e0,param_2);
      uVar1 = 1;
      if ((lVar2 == 0) && (param_2[4] == 0)) {
        lVar2 = FUN_0013e6e0(param_1,param_2,auStack_d8);
        uVar1 = (ulong)(lVar2 != 0);
      }
    }
    else {
      uVar1 = FUN_0013e940(*param_1,param_2);
      if (uVar1 == 0) {
        uVar1 = FUN_0013e6e0(param_1,param_2,auStack_d8);
      }
    }
  }
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}



// Function: e2fsck_rebuild_extents @ 0x3eee0

long e2fsck_rebuild_extents(long *param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  long extraout_RDX;
  long in_FS_OFFSET;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  long local_30;
  
  lVar2 = 0;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  iVar1 = FUN_0013ec30(*(undefined4 *)(*(long *)(*param_1 + 0x20) + 0x60));
  if ((iVar1 != 0) && ((*(byte *)((long)param_1 + 0x4c) & 8) == 0)) {
    if (((uint)param_2 == 2) || (*(uint *)(extraout_RDX + 0x54) <= (uint)param_2)) {
      e2fsck_read_bitmaps(param_1);
      lVar2 = ext2fs_get_array(0x155,0x18,local_68 + 8);
      if (lVar2 == 0) {
        local_58._4_4_ = 0x155;
        lVar2 = FUN_0013eb00(param_1,local_68,param_2 & 0xffffffff);
        ext2fs_free_mem(local_68 + 8);
      }
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_rebuild_extents_later @ 0x3efc0

long e2fsck_rebuild_extents_later(long *param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long extraout_RDX;
  
  iVar1 = FUN_0013ec30(*(undefined4 *)(*(long *)(*param_1 + 0x20) + 0x60));
  if ((iVar1 != 0) && ((*(byte *)((long)param_1 + 0x4c) & 8) == 0)) {
    if (((uint)param_2 == 2) || (*(uint *)(extraout_RDX + 0x54) <= (uint)param_2)) {
      if ((*(byte *)((long)param_1 + 0x49) & 0x80) != 0) {
        lVar3 = FUN_0013eee0(param_1,param_2 & 0xffffffff);
        return lVar3;
      }
      lVar3 = param_1[0x74];
      if (lVar3 == 0) {
        uVar2 = dcgettext(0,"extent rebuild inode map",5);
        lVar3 = e2fsck_allocate_inode_bitmap(*param_1,uVar2,2,"inodes_to_rebuild",param_1 + 0x74);
        if (lVar3 != 0) {
          return lVar3;
        }
        lVar3 = param_1[0x74];
      }
      ext2fs_mark_inode_bitmap2(lVar3,param_2 & 0xffffffff);
      return 0;
    }
  }
  return 0;
}



// Function: e2fsck_ino_will_be_rebuilt @ 0x3f090

undefined8 e2fsck_ino_will_be_rebuilt(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x3a0) != 0) {
    uVar1 = ext2fs_test_inode_bitmap2();
    return uVar1;
  }
  return 0;
}



// Function: e2fsck_rewrite_extent_tree @ 0x3f0b0

void e2fsck_rewrite_extent_tree(undefined8 *param_1,long param_2,undefined8 param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 *puVar3;
  long in_FS_OFFSET;
  undefined8 local_e0;
  undefined8 local_d8 [4];
  byte local_b5;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  puVar3 = local_d8;
  for (lVar2 = 0x14; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  lVar2 = param_2;
  uVar1 = FUN_0013e5d0(local_d8,param_2,param_3,0xa0);
  lVar2 = ext2fs_read_inode_full(*param_1,*(undefined4 *)(lVar2 + 0x28),uVar1);
  if ((lVar2 == 0) && ((local_b5 & 0x10) == 0)) {
    lVar2 = FUN_0013e6e0(param_1,param_2,local_d8);
    if (lVar2 == 0) {
      lVar2 = ext2fs_count_blocks(*param_1,*(undefined4 *)(param_2 + 0x28),uVar1,&local_e0);
      if (lVar2 == 0) {
        lVar2 = ext2fs_iblk_set(*param_1,uVar1,local_e0);
        if (lVar2 == 0) {
          ext2fs_write_inode_full(*param_1,*(undefined4 *)(param_2 + 0x28),uVar1,0xa0);
        }
      }
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: e2fsck_read_extents @ 0x3f1a0

long e2fsck_read_extents(undefined8 *param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  long in_FS_OFFSET;
  undefined1 auStack_d8 [168];
  long local_30;
  
  lVar3 = 0xc;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0x15500000000;
  *(undefined4 *)(param_2 + 3) = 0;
  lVar1 = ext2fs_get_array(0x155,0x18,param_2 + 1);
  if (lVar1 == 0) {
    uVar2 = FUN_0013e5d0(auStack_d8);
    lVar3 = ext2fs_read_inode(*param_1,*(undefined4 *)(param_2 + 5),uVar2);
    if ((lVar3 != 0) || (lVar3 = FUN_0013e940(*param_1,param_2), lVar3 != 0)) {
      ext2fs_free_mem(param_2 + 1);
      param_2[2] = 0;
    }
  }
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



// Function: e2fsck_should_rebuild_extents @ 0x3f290

undefined8
e2fsck_should_rebuild_extents(long *param_1,long param_2,undefined4 *param_3,long param_4)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (param_3[1] != 0) {
LAB_0013f330:
    uVar3 = e2fsck_rebuild_extents_later(param_1,*param_3);
    return uVar3;
  }
  if ((*(byte *)((long)param_1 + 0x4e) & 1) == 0) {
    if (-1 < *(int *)(param_4 + 0x10)) {
      lVar4 = 0;
      do {
        if ((uint)(((ulong)*(uint *)(*param_1 + 0x28) - 0xc) / 0xc) <
            (uint)(param_3[lVar4 * 2 + 3] - param_3[lVar4 * 2 + 2])) {
          uVar3 = 0x14007;
LAB_0013f313:
          *(long *)(param_2 + 0x28) = (long)(int)lVar4;
          iVar1 = fix_problem(param_1,uVar3,param_2);
          if (iVar1 == 0) {
            return 0;
          }
          goto LAB_0013f330;
        }
        lVar2 = 0;
        if (lVar4 != 0) {
          do {
            if ((uint)param_3[lVar4 * 2 + 2] < (uint)param_3[lVar2 * 2 + 3]) {
              uVar3 = 0x14006;
              goto LAB_0013f313;
            }
            lVar2 = lVar2 + 1;
          } while ((int)lVar2 < (int)lVar4);
        }
        lVar4 = lVar4 + 1;
      } while ((int)lVar4 <= *(int *)(param_4 + 0x10));
    }
  }
  return 0;
}



// Function: e2fsck_check_rebuild_extents @ 0x3f360

undefined8
e2fsck_check_rebuild_extents(undefined8 *param_1,undefined4 param_2,long param_3,long param_4)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  int iVar4;
  long in_FS_OFFSET;
  undefined8 local_100;
  undefined1 local_f8 [20];
  uint local_e4;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  undefined1 local_a8 [16];
  int local_98;
  undefined4 local_78;
  undefined1 auStack_74 [12];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (((*(uint *)(param_3 + 0x20) & 0x10080000) == 0) &&
     ((*(byte *)((long)param_1 + 0x4d) & 0x40) != 0)) {
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      uVar2 = e2fsck_rebuild_extents_later(param_1);
      return uVar2;
    }
    goto LAB_0013f5d8;
  }
  if ((*(uint *)(param_3 + 0x20) & 0x80000) == 0) {
LAB_0013f3af:
    uVar2 = 0;
  }
  else {
    local_68 = (undefined1  [16])0x0;
    auStack_74 = SUB1612((undefined1  [16])0x0,4);
    local_78 = param_2;
    local_58 = (undefined1  [16])0x0;
    lVar1 = ext2fs_extent_open2(*param_1,param_2,param_3,&local_100);
    if (lVar1 != 0) goto LAB_0013f3af;
    lVar1 = ext2fs_extent_get_info(local_100,local_a8);
    if (lVar1 == 0) {
      *(undefined4 *)(param_4 + 8) = param_2;
      *(long *)(param_4 + 0x28) = (long)local_98;
      uVar3 = ext2fs_max_extent_depth(local_100);
      *(ulong *)(param_4 + 0x30) = uVar3;
      if (uVar3 < *(ulong *)(param_4 + 0x28)) {
        iVar4 = fix_problem(param_1,0x1007f,param_4);
        if (iVar4 != 0) {
          auStack_74._0_4_ = 1;
        }
        uVar3 = *(ulong *)(param_4 + 0x30);
      }
      *(undefined8 *)(param_4 + 0x28) = 5;
      if (5 < uVar3) {
        fix_problem(param_1,0x14005,param_4);
      }
      if ((*(byte *)((long)param_1 + 0x4d) & 0x80) == 0) {
        lVar1 = ext2fs_extent_get(local_100,1,local_f8);
        if (lVar1 == 0) {
          while (lVar1 = ext2fs_extent_get_info(local_100,&local_d8), lVar1 == 0) {
            if ((local_d8 == 1) && ((local_e4 & 4) == 0 && auStack_74._0_4_ == 0)) {
              lVar1 = (long)local_d4 * 8;
              *(int *)(auStack_74 + lVar1 + 4) = *(int *)(auStack_74 + lVar1 + 4) + local_d0;
              iVar4 = *(int *)(auStack_74 + lVar1 + 8) + local_cc;
              if ((local_d4 != 0) && (local_d0 < local_cc)) {
                iVar4 = iVar4 + -1;
              }
              *(int *)(auStack_74 + lVar1 + 8) = iVar4;
            }
            if ((((local_e4 & 1) != 0) &&
                (lVar1 = ext2fs_extent_get(local_100,4,local_f8), lVar1 != 0)) ||
               (lVar1 = ext2fs_extent_get(local_100,9,local_f8), lVar1 != 0)) break;
          }
        }
      }
    }
    ext2fs_extent_free(local_100);
    uVar2 = e2fsck_should_rebuild_extents(param_1,param_4,&local_78,local_a8);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
LAB_0013f5d8:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: handle_nomem @ 0x3f610

undefined8 handle_nomem(long param_1,long param_2,undefined8 param_3)

{
  *(undefined8 *)(param_2 + 0x50) = param_3;
  fix_problem(param_1,0x1007e,param_2);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1;
  return 0;
}



// Function: fscrypt_context_to_policy @ 0x3f630

int fscrypt_context_to_policy(char *param_1,long param_2,undefined1 *param_3)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  
  iVar3 = -2;
  if (param_2 != 0) {
    cVar1 = *param_1;
    if (cVar1 == '\x01') {
      if (param_2 == 0x1c) {
        *param_3 = 1;
        param_3[1] = param_1[1];
        param_3[2] = param_1[2];
        param_3[3] = param_1[3];
        *(undefined8 *)(param_3 + 4) = *(undefined8 *)(param_1 + 4);
        return 0;
      }
    }
    else {
      if (cVar1 != '\x02') {
        return (cVar1 == '\0') - 3;
      }
      if (param_2 == 0x28) {
        *param_3 = 2;
        param_3[1] = param_1[1];
        param_3[2] = param_1[2];
        param_3[3] = param_1[3];
        *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_1 + 4);
        uVar2 = *(undefined8 *)(param_1 + 0x10);
        iVar3 = 0;
        *(undefined8 *)(param_3 + 8) = *(undefined8 *)(param_1 + 8);
        *(undefined8 *)(param_3 + 0x10) = uVar2;
      }
    }
  }
  return iVar3;
}



// Function: cmp_fscrypt_policies @ 0x3f6c0

int cmp_fscrypt_policies(undefined8 param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_2;
  if (bVar1 != *param_3) {
    return (uint)bVar1 - (uint)*param_3;
  }
  if (bVar1 != 1) {
    if (bVar1 == 2) {
      iVar2 = memcmp(param_2,param_3,0x18);
      return iVar2;
    }
                    /* WARNING: Subroutine does not return */
    fatal_error(param_1,"Unhandled encryption policy version");
  }
  iVar2 = memcmp(param_2,param_3,0xc);
  return iVar2;
}



// Function: append_ino_and_policy_id @ 0x3f730

undefined8 append_ino_and_policy_id(long *param_1,undefined8 param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  
  plVar2 = (long *)param_1[0x4a];
  lVar3 = 0;
  if (plVar2[1] != 0) {
    lVar3 = *plVar2 + -0xc + plVar2[1] * 0xc;
    if (param_3 <= *(uint *)(lVar3 + 4)) {
                    /* WARNING: Subroutine does not return */
      fatal_error(param_1,"Encrypted inodes processed out of order");
    }
    if ((*(uint *)(lVar3 + 4) + 1 == param_3) && (*(uint *)(lVar3 + 8) == param_4)) {
      *(uint *)(lVar3 + 4) = param_3;
      return 0;
    }
    lVar3 = plVar2[1];
  }
  if (plVar2[2] == lVar3) {
    uVar5 = lVar3 * 2;
    if (uVar5 < 0x80) {
      uVar5 = 0x80;
    }
    uVar6 = (ulong)**(uint **)(*param_1 + 0x20);
    if (uVar5 < **(uint **)(*param_1 + 0x20)) {
      uVar6 = uVar5;
    }
    if (uVar6 < lVar3 + 1U) {
      uVar6 = lVar3 + 1U;
    }
    lVar3 = ext2fs_resize_mem(lVar3 * 0xc,uVar6 * 0xc,plVar2);
    if (lVar3 != 0) {
      uVar4 = FUN_0013f610(param_1,param_2,uVar6 * 0xc);
      return uVar4;
    }
    plVar2[2] = uVar6;
    lVar3 = plVar2[1];
  }
  plVar2[1] = lVar3 + 1;
  puVar1 = (uint *)(*plVar2 + lVar3 * 0xc);
  *puVar1 = param_3;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  return 0;
}



// Function: get_encryption_policy_id @ 0x3f900

long get_encryption_policy_id(undefined8 *param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  long in_FS_OFFSET;
  int local_8c;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  long local_40;
  
  lVar1 = param_1[0x4a];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar6 = FUN_0013f860(*param_1,param_2,&local_70,&local_68);
  if (lVar6 != 0x7f2bb746) {
    if (lVar6 == 0) {
      local_8c = FUN_0013f630(local_70,local_68,&local_58);
      ext2fs_free_mem(&local_70);
      if (local_8c == 0) {
        plVar7 = (long *)(lVar1 + 0x18);
        lVar4 = *(long *)(lVar1 + 0x18);
        lVar3 = *(long *)(lVar1 + 0x18);
        while (lVar2 = lVar4, lVar2 != 0) {
          local_60 = (undefined8 *)(lVar2 + -0x20);
          iVar5 = FUN_0013f6c0(param_1,&local_58);
          plVar7 = (long *)(lVar2 + 0x10);
          if (-1 < iVar5) {
            if (iVar5 == 0) {
              *param_3 = *(int *)(local_60 + 3);
              goto LAB_0013f95b;
            }
            plVar7 = (long *)(lVar2 + 8);
          }
          lVar3 = lVar2;
          lVar4 = *plVar7;
        }
        lVar6 = ext2fs_get_mem(0x38,&local_60);
        if (lVar6 == 0) {
          local_8c = *(int *)(lVar1 + 0x20);
          *(int *)(lVar1 + 0x20) = local_8c + 1;
          *(int *)(local_60 + 3) = local_8c;
          local_60[2] = local_48;
          *local_60 = local_58;
          local_60[1] = uStack_50;
          FUN_0013f5f0(local_60 + 4,lVar3,plVar7);
          ext2fs_rb_insert_color();
        }
      }
      *param_3 = local_8c;
    }
    else {
      *param_3 = -1;
      lVar6 = 0;
    }
  }
LAB_0013f95b:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: add_encrypted_file @ 0x3fab0

ulong add_encrypted_file(long param_1,long param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  int local_2c;
  long local_28;
  long local_20;
  
  uVar2 = *(undefined4 *)(param_2 + 8);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = *(long *)(param_1 + 0x250);
  if (local_28 == 0) {
    lVar4 = ext2fs_get_memzero(0x28,&local_28);
    if (lVar4 != 0) {
      uVar5 = FUN_0013f610(param_1,param_2,0x28);
      goto LAB_0013fb1f;
    }
    *(long *)(param_1 + 0x250) = local_28;
  }
  lVar4 = FUN_0013f900(param_1,uVar2,&local_2c);
  if (lVar4 == 0) {
    if (local_2c == -1) {
      uVar5 = fix_problem(param_1,0x1008a,param_2);
      if ((int)uVar5 != 0) {
        lVar4 = *(long *)(param_2 + 0x18);
        puVar1 = (uint *)(lVar4 + 0x20);
        *puVar1 = *puVar1 & 0xfffff7ff;
        e2fsck_write_inode(param_1,uVar2,lVar4,"pass1");
        uVar5 = 0;
      }
    }
    else if (local_2c == -2) {
      iVar3 = fix_problem(param_1,0x1008b,param_2);
      uVar5 = (ulong)-(uint)(iVar3 != 0);
    }
    else {
      uVar5 = FUN_0013f730(param_1,param_2,uVar2);
    }
  }
  else {
    uVar5 = FUN_0013f610(param_1,param_2,0);
  }
LAB_0013fb1f:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: find_encryption_policy @ 0x3fc00

uint find_encryption_policy(long param_1,uint param_2)

{
  uint *puVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  plVar2 = *(long **)(param_1 + 0x250);
  if (plVar2 != (long *)0x0) {
    uVar5 = 0;
    uVar3 = plVar2[1];
    while (uVar4 = uVar3, uVar5 < uVar4) {
      uVar3 = (uVar4 - uVar5 >> 1) + uVar5;
      puVar1 = (uint *)(*plVar2 + uVar3 * 0xc);
      if (*puVar1 <= param_2) {
        if (param_2 <= puVar1[1]) {
          return puVar1[2];
        }
        uVar5 = uVar3 + 1;
        uVar3 = uVar4;
      }
    }
  }
  return 0xffffffff;
}



// Function: destroy_encryption_policy_map @ 0x3fc60

void destroy_encryption_policy_map(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long in_FS_OFFSET;
  long local_28;
  long local_20;
  
  lVar1 = *(long *)(param_1 + 0x250);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (lVar1 != 0) {
    while( true ) {
      lVar3 = *(long *)(lVar1 + 0x18);
      iVar2 = FUN_0013faa0();
      if (iVar2 != 0) break;
      local_28 = lVar3 + -0x20;
      ext2fs_rb_erase();
      ext2fs_free_mem(&local_28);
    }
    *(undefined4 *)(lVar1 + 0x20) = 0;
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: destroy_encrypted_file_info @ 0x3fcf0

void destroy_encrypted_file_info(long param_1)

{
  long in_FS_OFFSET;
  long local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = *(long *)(param_1 + 0x250);
  if (local_18 != 0) {
    destroy_encryption_policy_map();
    ext2fs_free_mem(local_18);
    ext2fs_free_mem(&local_18);
    *(undefined8 *)(param_1 + 0x250) = 0;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: make_u32_list @ 0x48b20

long make_u32_list(int param_1,undefined4 param_2,void *param_3,undefined8 *param_4)

{
  long lVar1;
  size_t __n;
  long in_FS_OFFSET;
  undefined1 (*local_48) [16];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = ext2fs_get_mem(0x20,&local_48);
  if (lVar1 == 0) {
    lVar1 = (long)param_1;
    *local_48 = (undefined1  [16])0x0;
    local_48[1] = (undefined1  [16])0x0;
    *(undefined4 *)*local_48 = 0x7f2bb702;
    if (param_1 == 0) {
      lVar1 = 10;
      param_1 = 10;
    }
    *(int *)(*local_48 + 8) = param_1;
    *(undefined4 *)(*local_48 + 4) = param_2;
    lVar1 = ext2fs_get_array(lVar1);
    if (lVar1 == 0) {
      __n = (long)*(int *)(*local_48 + 8) << 2;
      if (param_3 == (void *)0x0) {
        memset(*(void **)local_48[1],0,__n);
      }
      else {
        memcpy(*(void **)local_48[1],param_3,__n);
      }
      *param_4 = local_48;
    }
    else {
      ext2fs_free_mem(&local_48);
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ext2fs_u32_list_create @ 0x48c30

void ext2fs_u32_list_create(undefined8 param_1,undefined4 param_2)

{
  FUN_00148b20(param_2,0,0,param_1);
  return;
}



// Function: ext2fs_u32_copy @ 0x48c60

void ext2fs_u32_copy(long param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = FUN_00148b20(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4),
                       *(undefined8 *)(param_1 + 0x10),param_2);
  if (lVar1 == 0) {
    *(undefined4 *)(*param_2 + 0x18) = *(undefined4 *)(param_1 + 0x18);
  }
  return;
}



// Function: ext2fs_u32_list_add @ 0x48cb0

long ext2fs_u32_list_add(int *param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  long lVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  
  if (*param_1 != 0x7f2bb702) {
    return 0x7f2bb702;
  }
  iVar1 = param_1[1];
  iVar8 = param_1[2];
  if (iVar1 < iVar8) {
    puVar2 = *(uint **)(param_1 + 4);
  }
  else {
    param_1[2] = iVar8 + 100;
    lVar4 = ext2fs_resize_mem((long)iVar8 * 4,(long)iVar8 * 4 + 400,param_1 + 4);
    if (lVar4 != 0) {
      param_1[2] = param_1[2] + -100;
      return lVar4;
    }
    iVar1 = param_1[1];
    puVar2 = *(uint **)(param_1 + 4);
  }
  if (iVar1 != 0) {
    iVar8 = iVar1 + -1;
    if (puVar2[iVar8] == param_2) {
      return 0;
    }
    if (param_2 <= puVar2[iVar8]) {
      iVar5 = 0;
      puVar3 = puVar2;
      if (0 < iVar1) {
        do {
          if (*puVar3 == param_2) {
            return 0;
          }
          if (param_2 < *puVar3) {
            if (iVar5 < iVar1) {
              puVar6 = puVar2 + (long)iVar8 + 1;
              do {
                puVar7 = puVar6 + -1;
                *puVar6 = puVar6[-1];
                puVar6 = puVar7;
              } while (puVar2 + ((long)iVar8 - (ulong)(uint)(iVar8 - iVar5)) != puVar7);
            }
            goto LAB_00148d95;
          }
          iVar5 = iVar5 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar5 != iVar1);
      }
      puVar3 = puVar2 + (long)iVar8 + 1;
LAB_00148d95:
      *puVar3 = param_2;
      param_1[1] = param_1[1] + 1;
      return 0;
    }
  }
  param_1[1] = iVar1 + 1;
  puVar2[iVar1] = param_2;
  return 0;
}



// Function: ext2fs_u32_list_find @ 0x48df0

uint ext2fs_u32_list_find(int *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((*param_1 == 0x7f2bb702) && (param_1[1] != 0)) {
    puVar1 = *(uint **)(param_1 + 4);
    uVar4 = param_1[1] - 1;
    if (*puVar1 == param_2) {
      return 0;
    }
    uVar2 = 0;
    if (puVar1[(int)uVar4] == param_2) {
      return uVar4;
    }
    while (((uVar3 = uVar2, (int)uVar3 < (int)uVar4 && (uVar2 = uVar3 + uVar4 >> 1, uVar3 != uVar2))
           && (uVar4 != uVar2))) {
      if (puVar1[uVar2] == param_2) {
        return uVar2;
      }
      if (param_2 < puVar1[uVar2]) {
        uVar4 = uVar2;
        uVar2 = uVar3;
      }
    }
  }
  return 0xffffffff;
}



// Function: ext2fs_u32_list_test @ 0x48e60

uint ext2fs_u32_list_test(void)

{
  uint uVar1;
  
  uVar1 = ext2fs_u32_list_find();
  return ~uVar1 >> 0x1f;
}



// Function: ext2fs_u32_list_del @ 0x48e80

undefined8 ext2fs_u32_list_del(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 != 0) {
    iVar2 = ext2fs_u32_list_find();
    if (-1 < iVar2) {
      iVar4 = iVar4 + -1;
      if (iVar2 < iVar4) {
        lVar1 = *(long *)(param_1 + 0x10);
        lVar3 = (long)iVar2;
        do {
          *(undefined4 *)(lVar1 + lVar3 * 4) = *(undefined4 *)(lVar1 + 4 + lVar3 * 4);
          lVar3 = lVar3 + 1;
          iVar4 = *(int *)(param_1 + 4) + -1;
        } while ((int)lVar3 < iVar4);
      }
      *(int *)(param_1 + 4) = iVar4;
      return 0;
    }
  }
  return 0xffffffff;
}



// Function: ext2fs_u32_list_iterate_begin @ 0x48ef0

long ext2fs_u32_list_iterate_begin(int *param_1,undefined8 *param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined4 *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = 0x7f2bb702;
  if (*param_1 == 0x7f2bb702) {
    lVar1 = ext2fs_get_mem(0x18,&local_28);
    if (lVar1 == 0) {
      *local_28 = 0x7f2bb703;
      *(int **)(local_28 + 2) = param_1;
      local_28[4] = 0;
      *param_2 = local_28;
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ext2fs_u32_list_iterate @ 0x48f80

undefined8 ext2fs_u32_list_iterate(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  
  if ((*param_1 == 0x7f2bb703) && (piVar2 = *(int **)(param_1 + 2), *piVar2 == 0x7f2bb702)) {
    iVar1 = param_1[4];
    if (piVar2[1] <= iVar1) {
      *param_2 = 0;
      return 0;
    }
    lVar3 = *(long *)(piVar2 + 4);
    param_1[4] = iVar1 + 1;
    *param_2 = *(undefined4 *)(lVar3 + (long)iVar1 * 4);
    return 1;
  }
  return 0;
}



// Function: ext2fs_u32_list_iterate_end @ 0x48fe0

void ext2fs_u32_list_iterate_end(int *param_1)

{
  int *local_10 [2];
  
  if ((param_1 != (int *)0x0) && (*param_1 == 0x7f2bb703)) {
    param_1[2] = 0;
    param_1[3] = 0;
    local_10[0] = param_1;
    ext2fs_free_mem(local_10);
    return;
  }
  return;
}



// Function: ext2fs_u32_list_equal @ 0x49030

uint ext2fs_u32_list_equal(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 != 0x7f2bb702) {
    return 0x7f2bb702;
  }
  uVar2 = 0x7f2bb702;
  if (*param_2 == 0x7f2bb702) {
    uVar2 = 0;
    if (param_1[1] == param_2[1]) {
      iVar1 = memcmp(*(void **)(param_1 + 4),*(void **)(param_2 + 4),(long)param_1[1] << 2);
      return (uint)(iVar1 == 0);
    }
  }
  return uVar2;
}



// Function: ext2fs_u32_list_count @ 0x490a0

undefined4 ext2fs_u32_list_count(long param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



