// Function: main @ 0x3d60

undefined8 main(int param_1,undefined8 *param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  bool bVar8;
  
  DAT_00111950 = (char *)FUN_00104ee0(*param_2);
  FUN_00105fd0(DAT_00111950);
  FUN_00105ff0(stderr);
  setlocale(6,"");
  bindtextdomain("shadow","/usr/share/locale");
  textdomain("shadow");
  FUN_001050d0(&DAT_0010b377,param_1,param_2);
  iVar3 = strcmp(DAT_00111950,"vigr");
  bVar8 = iVar3 != 0;
  pcVar4 = "vipw";
  if (!bVar8) {
    pcVar4 = "vigr";
  }
  bVar1 = false;
  openlog(pcVar4,1,0x50);
  do {
    iVar3 = getopt_long(param_1,param_2,"ghpqR:s",&PTR_s_group_00110020,0);
    if (iVar3 == -1) {
      if (optind == param_1) {
        if (bVar8) {
          if (bVar1) {
            uVar5 = FUN_001073b0();
            FUN_00104630(uVar5,FUN_001073f0,FUN_001074b0);
            uVar5 = FUN_00106600();
            uVar6 = FUN_001073b0();
            uVar7 = dcgettext(0,
                              "You have modified %s.\nYou may need to modify %s for consistency.\nPlease use the command \'%s\' to do so.\n"
                              ,5);
            pcVar4 = "vipw";
          }
          else {
            uVar5 = FUN_00106600();
            FUN_00104630(uVar5,FUN_00106610,FUN_00106700);
            cVar2 = FUN_001073c0();
            if (cVar2 == '\0') goto LAB_00103f1a;
            uVar5 = FUN_001073b0();
            uVar6 = FUN_00106600();
            uVar7 = dcgettext(0,
                              "You have modified %s.\nYou may need to modify %s for consistency.\nPlease use the command \'%s\' to do so.\n"
                              ,5);
            pcVar4 = "vipw -s";
          }
        }
        else if (bVar1) {
          uVar5 = FUN_00107140();
          FUN_00104630(uVar5,FUN_00107180,FUN_00107240);
          uVar5 = FUN_001059c0();
          uVar6 = FUN_00107140();
          uVar7 = dcgettext(0,
                            "You have modified %s.\nYou may need to modify %s for consistency.\nPlease use the command \'%s\' to do so.\n"
                            ,5);
          pcVar4 = "vigr";
        }
        else {
          uVar5 = FUN_001059c0();
          FUN_00104630(uVar5,FUN_001059d0,FUN_00105ac0);
          cVar2 = FUN_00107150();
          if (cVar2 == '\0') goto LAB_00103f1a;
          uVar5 = FUN_00107140();
          uVar6 = FUN_001059c0();
          uVar7 = dcgettext(0,
                            "You have modified %s.\nYou may need to modify %s for consistency.\nPlease use the command \'%s\' to do so.\n"
                            ,5);
          pcVar4 = "vigr -s";
        }
        __printf_chk(1,uVar7,uVar6,uVar5,pcVar4);
LAB_00103f1a:
        FUN_00105e10("passwd");
        FUN_00105e10("group");
        FUN_00106050(3);
        return 0;
      }
      goto switchD_00103e5b_caseD_53;
    }
    switch(iVar3) {
    case 0x52:
      break;
    default:
switchD_00103e5b_caseD_53:
                    /* WARNING: Subroutine does not return */
      FUN_00104160(2);
    case 0x67:
      bVar8 = false;
      break;
    case 0x68:
                    /* WARNING: Subroutine does not return */
      FUN_00104160(0);
    case 0x70:
      bVar8 = true;
      break;
    case 0x71:
      DAT_00111958 = 1;
      break;
    case 0x73:
      bVar1 = true;
    }
  } while( true );
}



// Function: usage @ 0x4160

void usage(int param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char *pcVar3;
  FILE *__stream;
  
  uVar1 = DAT_00111950;
  __stream = stderr;
  if (param_1 == 0) {
    __stream = stdout;
  }
  uVar2 = dcgettext(0,"Usage: %s [options]\n\nOptions:\n",5);
  __fprintf_chk(stderr,1,uVar2,uVar1);
  pcVar3 = (char *)dcgettext(0,"  -g, --group                   edit group database\n",5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,
                             "  -h, --help                    display this help message and exit\n",
                             5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,"  -p, --passwd                  edit passwd database\n",5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,"  -q, --quiet                   quiet mode\n",5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,"  -R, --root CHROOT_DIR         directory to chroot into\n",5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,"  -s, --shadow                  edit shadow or gshadow database\n",5
                            );
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,"\n",5);
  fputs(pcVar3,__stream);
                    /* WARNING: Subroutine does not return */
  exit(param_1);
}



// Function: create_backup_file @ 0x4290

undefined4 create_backup_file(FILE *param_1,char *param_2,long param_3)

{
  __mode_t __mask;
  int iVar1;
  undefined4 uVar2;
  FILE *__stream;
  long in_FS_OFFSET;
  utimbuf local_48;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  __mask = umask(0x3f);
  __stream = fopen(param_2,"w");
  umask(__mask);
  if (__stream == (FILE *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = fseeko(param_1,0,0);
    if (iVar1 == 0) {
      do {
        iVar1 = getc(param_1);
        if (iVar1 == -1) {
          iVar1 = ferror(param_1);
          if ((iVar1 == 0) && (iVar1 = fflush(__stream), iVar1 == 0)) {
            iVar1 = fileno(__stream);
            iVar1 = fsync(iVar1);
            if (iVar1 != 0) {
              fclose(__stream);
              unlink(param_2);
              uVar2 = 0xffffffff;
              goto LAB_001043a4;
            }
            iVar1 = fclose(__stream);
            if (iVar1 == 0) {
              local_48.actime = *(__time_t *)(param_3 + 0x48);
              local_48.modtime = *(__time_t *)(param_3 + 0x58);
              iVar1 = utime(param_2,&local_48);
              if ((iVar1 == 0) && (iVar1 = chmod(param_2,*(__mode_t *)(param_3 + 0x18)), iVar1 == 0)
                 ) {
                iVar1 = chown(param_2,*(__uid_t *)(param_3 + 0x1c),*(__gid_t *)(param_3 + 0x20));
                uVar2 = 0;
                if (iVar1 == 0) goto LAB_001043a4;
              }
            }
            unlink(param_2);
            uVar2 = 0xffffffff;
            goto LAB_001043a4;
          }
          break;
        }
        iVar1 = putc(iVar1,__stream);
      } while (iVar1 != -1);
    }
    fclose(__stream);
    unlink(param_2);
    uVar2 = 0xffffffff;
  }
LAB_001043a4:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



// Function: vipwexit @ 0x4400

void vipwexit(long param_1,int param_2,int param_3)

{
  int __errnum;
  undefined8 uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char *__locale;
  
  piVar3 = __errno_location();
  pcVar4 = DAT_00111970;
  __errnum = *piVar3;
  if ((DAT_00111968 != '\0') && (iVar2 = unlink(DAT_00111970), uVar1 = DAT_00111950, iVar2 != 0)) {
    uVar6 = dcgettext(0,"%s: failed to remove %s\n",5);
    __fprintf_chk(stderr,1,uVar6,uVar1,pcVar4);
  }
  if ((DAT_00111969 != '\0') &&
     (iVar2 = (*DAT_00111960)(), pcVar4 = DAT_00111970, uVar1 = DAT_00111950, iVar2 == 0)) {
    uVar6 = dcgettext(0,"%s: failed to unlock %s\n",5);
    __fprintf_chk(stderr,1,uVar6,uVar1,pcVar4);
    pcVar4 = setlocale(6,(char *)0x0);
    if ((pcVar4 == (char *)0x0) ||
       (__locale = strdup(pcVar4), pcVar4 = DAT_00111970, __locale == (char *)0x0)) {
      __syslog_chk(3,1,"failed to unlock %s",DAT_00111970);
    }
    else {
      setlocale(6,"C");
      __syslog_chk(3,1,"failed to unlock %s",pcVar4);
      setlocale(6,__locale);
      free(__locale);
    }
  }
  if (param_1 == 0) {
    if (param_2 == 0) goto LAB_001044a8;
LAB_00104470:
    pcVar4 = strerror(__errnum);
    __fprintf_chk(stderr,1,": %s",pcVar4);
  }
  else {
    __fprintf_chk(stderr,1,"%s: %s",DAT_00111950,param_1);
    if (param_2 != 0) goto LAB_00104470;
  }
  fputs("\n",stderr);
LAB_001044a8:
  uVar6 = DAT_00111978;
  uVar1 = DAT_00111950;
  if (DAT_00111958 == '\0') {
    uVar5 = dcgettext(0,"%s: %s is unchanged\n",5);
    __fprintf_chk(stdout,1,uVar5,uVar1,uVar6);
  }
                    /* WARNING: Subroutine does not return */
  exit(param_3);
}



// Function: vipwedit @ 0x4630

void vipwedit(char *param_1,code *param_2,code *param_3)

{
  uint uVar1;
  char cVar14;
  int iVar2;
  __pid_t _Var3;
  __pid_t _Var4;
  __pid_t __pgrp_id;
  __pid_t _Var5;
  uint uVar6;
  FILE *__stream;
  int *piVar7;
  char *pcVar8;
  size_t sVar9;
  size_t sVar10;
  char *pcVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 extraout_RDX;
  char **ppcVar15;
  undefined1 *puVar16;
  long in_FS_OFFSET;
  char *pcStack_aa8;
  undefined8 local_aa0;
  undefined1 auStack_a98 [8];
  char *local_a90;
  code *local_a88;
  char *local_a80;
  uint local_a6c;
  sigset_t local_a68;
  sigset_t local_9e8;
  stat local_968;
  stat local_8d8;
  char local_848 [1024];
  char local_448 [1032];
  long local_40;
  
  puVar16 = auStack_a98;
  ppcVar15 = (char **)auStack_a98;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_a80 = local_848;
  local_aa0 = 0x10469a;
  local_a88 = param_3;
  __snprintf_chk(local_a80,0x400,1,0x400,&DAT_0010b2b8,param_1);
  local_aa0 = 0x1046bd;
  __snprintf_chk(local_448,0x400,1,0x400,"%s.edit",param_1);
  local_aa0 = 0x1046dc;
  DAT_00111960 = param_3;
  DAT_00111970 = local_448;
  DAT_00111978 = param_1;
  iVar2 = access(param_1,0);
  if (iVar2 != 0) goto LAB_00104cdf;
  local_aa0 = 0x1046e6;
  iVar2 = (*param_2)();
  if (iVar2 == 0) {
LAB_00104d1a:
    local_aa0 = 0x104d1f;
    piVar7 = __errno_location();
    iVar2 = *piVar7;
    local_aa0 = 0x104d34;
    uVar13 = dcgettext(0,"Couldn\'t lock file",5);
    local_aa0 = 0x104d43;
    FUN_00104400(uVar13,iVar2,5);
LAB_00104d43:
    local_aa0 = 0x104d59;
    FUN_00104400(&DAT_0010b2fa,1,1);
LAB_00104d59:
    uVar13 = DAT_00111950;
    local_aa0 = 0x104d73;
    uVar12 = dcgettext(0,"%s: %s killed by signal %d\n",5);
    local_aa0 = 0x104d94;
    __fprintf_chk(stderr,1,uVar12,uVar13,local_a90,(ulong)param_2 & 0xffffffff);
    cVar14 = '\x01';
  }
  else {
    DAT_00111969 = 1;
    local_aa0 = 0x104708;
    iVar2 = stat(param_1,&local_968);
    if (iVar2 != 0) {
LAB_00104cdf:
      local_aa0 = 0x104cf1;
      FUN_00104400(param_1,1,1);
LAB_00104cf1:
      local_aa0 = 0x104cf6;
      piVar7 = __errno_location();
      iVar2 = *piVar7;
      local_aa0 = 0x104d0b;
      uVar13 = dcgettext(0,"Couldn\'t make backup",5);
      local_aa0 = 0x104d1a;
      FUN_00104400(uVar13,iVar2,1);
      goto LAB_00104d1a;
    }
    local_aa0 = 0x10471f;
    __stream = fopen(param_1,"r");
    if (__stream == (FILE *)0x0) goto LAB_00104cdf;
    local_aa0 = 0x104739;
    iVar2 = FUN_00104290(__stream,local_448,&local_968);
    if (iVar2 != 0) goto LAB_00104cf1;
    local_aa0 = 0x104749;
    fclose(__stream);
    DAT_00111968 = 1;
    local_aa0 = 0x10475c;
    local_a90 = getenv("VISUAL");
    if (local_a90 == (char *)0x0) {
      local_aa0 = 0x104a6f;
      local_a90 = getenv("EDITOR");
      if (local_a90 == (char *)0x0) {
        local_a90 = "vi";
      }
    }
    local_aa0 = 0x104771;
    _Var3 = tcgetpgrp(0);
    local_aa0 = 0x104779;
    _Var4 = fork();
    if (_Var4 == -1) goto LAB_00104d43;
    if (_Var4 == 0) {
      if (_Var3 != -1) {
        local_aa0 = 0x1048d7;
        _Var3 = getpid();
        local_aa0 = 0x1048e2;
        setpgid(0,0);
        do {
          local_aa0 = 0x1048e9;
          _Var4 = tcgetpgrp(0);
        } while (_Var4 != _Var3);
      }
      pcVar8 = local_a90;
      local_aa0 = 0x1048fa;
      sVar9 = strlen(local_a90);
      local_aa0 = 0x104905;
      sVar10 = strlen(local_448);
      local_aa0 = 0x10490f;
      pcVar11 = malloc(sVar9 + 2 + sVar10);
      local_aa0 = 0x10491a;
      sVar9 = strlen(pcVar8);
      local_aa0 = 0x104925;
      sVar10 = strlen(local_448);
      pcStack_aa8 = local_448;
      local_aa0 = extraout_RDX;
      __snprintf_chk(pcVar11,sVar9 + 2 + sVar10,1,0xffffffffffffffff,"%s %s",pcVar8);
      local_a6c = system(pcVar11);
      uVar13 = DAT_00111950;
      if (local_a6c != 0xffffffff) {
        uVar6 = local_a6c & 0x7f;
        if ((uVar6 == 0) && (uVar1 = local_a6c >> 8, (char)(local_a6c >> 8) != '\0')) {
          local_aa0 = 0x104e8b;
          uVar12 = dcgettext(0,"%s: %s returned with status %d\n",5,pcStack_aa8);
          local_aa0 = 0x104eac;
          __fprintf_chk(stderr,1,uVar12,uVar13,local_a90,uVar1 & 0xff);
                    /* WARNING: Subroutine does not return */
          local_aa0 = 0x104eb8;
          exit(local_a6c >> 8 & 0xff);
        }
        if ((local_a6c & 0x7f) != 0 && '\0' < (char)(((byte)local_a6c & 0x7f) + 1)) {
          local_aa0 = 0x10499c;
          uVar12 = dcgettext(0,"%s: %s killed by signal %d\n",5,pcStack_aa8);
          local_aa0 = 0x1049bd;
          __fprintf_chk(stderr,1,uVar12,uVar13,local_a90,uVar6);
                    /* WARNING: Subroutine does not return */
          local_aa0 = 0x1049c7;
          exit(1);
        }
                    /* WARNING: Subroutine does not return */
        local_aa0 = 0x104c0d;
        exit(0);
      }
      goto LAB_00104e1d;
    }
    if (_Var3 != -1) {
      local_aa0 = 0x1047a0;
      setpgid(_Var4,_Var4);
      local_aa0 = 0x1047a9;
      tcsetpgrp(0,_Var4);
      local_aa0 = 0x1047b1;
      sigemptyset(&local_a68);
      local_aa0 = 0x1047be;
      sigaddset(&local_a68,0x16);
      local_aa0 = 0x1047d0;
      sigprocmask(0,&local_a68,&local_9e8);
    }
    __pgrp_id = -1;
    local_aa0 = 0x1047e4;
    signal(0x11,(__sighandler_t)0x0);
    while( true ) {
      local_aa0 = 0x10484f;
      _Var4 = waitpid(_Var4,(int *)&local_a6c,2);
      if (_Var4 == -1) break;
      uVar6 = local_a6c;
      if ((char)local_a6c != '\x7f') goto LAB_00104abc;
      if (_Var3 == -1) {
LAB_0010486c:
        local_aa0 = 0x104871;
        _Var5 = getpid();
        local_aa0 = 0x10487d;
        kill(_Var5,0x13);
        if (__pgrp_id != -1) {
          local_aa0 = 0x10488b;
          iVar2 = tcsetpgrp(0,__pgrp_id);
          if (iVar2 == -1) goto LAB_00104890;
        }
      }
      else {
        local_aa0 = 0x1047f7;
        __pgrp_id = tcgetpgrp(0);
        if (__pgrp_id == -1) {
          local_aa0 = 0x104a08;
          piVar7 = __errno_location();
          local_aa0 = 0x104a0f;
          pcVar8 = strerror(*piVar7);
          local_aa0 = 0x104a3a;
          __fprintf_chk(stderr,1,"%s: %s: %s",DAT_00111950,"tcgetpgrp",pcVar8);
          local_aa0 = 0x104a44;
          iVar2 = tcsetpgrp(0,_Var3);
          if (iVar2 == -1) goto LAB_001049c7;
          local_aa0 = 0x104a52;
          _Var5 = getpid();
          local_aa0 = 0x104a5e;
          kill(_Var5,0x13);
        }
        else {
          local_aa0 = 0x10480c;
          iVar2 = tcsetpgrp(0,_Var3);
          if (iVar2 == -1) {
LAB_001049c7:
            local_aa0 = 0x1049cc;
            piVar7 = __errno_location();
            local_aa0 = 0x1049d3;
            pcVar8 = strerror(*piVar7);
            local_aa0 = 0x1049fe;
            __fprintf_chk(stderr,1,"%s: %s: %s",DAT_00111950,"tcsetpgrp",pcVar8);
            goto LAB_0010486c;
          }
          local_aa0 = 0x10481a;
          _Var5 = getpid();
          local_aa0 = 0x104826;
          kill(_Var5,0x13);
          local_aa0 = 0x10482f;
          iVar2 = tcsetpgrp(0,__pgrp_id);
          if (iVar2 != -1) goto LAB_00104834;
LAB_00104890:
          local_aa0 = 0x104895;
          piVar7 = __errno_location();
          local_aa0 = 0x10489c;
          pcVar8 = strerror(*piVar7);
          local_aa0 = 0x1048c7;
          __fprintf_chk(stderr,1,"%s: %s: %s",DAT_00111950,"tcsetpgrp",pcVar8);
        }
      }
LAB_00104834:
      local_aa0 = 0x104840;
      killpg(_Var4,0x12);
    }
    _Var3 = _Var3 + 1;
    if (_Var3 != 0) {
      local_aa0 = 0x104aa8;
      sigprocmask(2,&local_9e8,(sigset_t *)0x0);
    }
    local_aa0 = 0x104abc;
    uVar6 = FUN_00104400(local_a90,1,1);
LAB_00104abc:
    if (_Var3 != -1) {
      local_aa0 = 0x104ecc;
      sigprocmask(2,&local_9e8,(sigset_t *)0x0);
      uVar6 = local_a6c;
    }
    param_2 = (code *)(ulong)(uVar6 & 0x7f);
    if (((uVar6 & 0x7f) != 0) || (cVar14 = (char)(uVar6 >> 8), cVar14 == '\0')) {
      if ((uVar6 & 0x7f) == 0 || (char)(((byte)uVar6 & 0x7f) + 1) < '\x01') {
        local_aa0 = 0x104af7;
        iVar2 = stat(local_448,&local_8d8);
        pcVar8 = local_a80;
        if (iVar2 == 0) {
          puVar16 = auStack_a98;
          if (local_968.st_mtim.tv_sec != local_8d8.st_mtim.tv_sec) {
            DAT_00111968 = 0;
            local_aa0 = 0x104b29;
            unlink(local_a80);
            local_aa0 = 0x104b34;
            link(param_1,pcVar8);
            local_aa0 = 0x104b3f;
            iVar2 = rename(local_448,param_1);
            if (iVar2 == -1) {
              local_aa0 = 0x104dac;
              piVar7 = __errno_location();
              local_aa0 = 0x104db3;
              pcVar8 = strerror(*piVar7);
              uVar13 = DAT_00111950;
              local_aa0 = 0x104dd0;
              local_aa0 = dcgettext(0,"%s: can\'t restore %s: %s (your changes are in %s)\n",5);
              ppcVar15 = &pcStack_aa8;
              pcStack_aa8 = local_448;
              __fprintf_chk(stderr,1,local_aa0,uVar13,param_1,pcVar8);
              FUN_00104400(0,0,1);
              goto LAB_00104e00;
            }
            local_aa0 = 0x104b4f;
            iVar2 = (*local_a88)();
            pcVar8 = DAT_00111970;
            uVar13 = DAT_00111950;
            if (iVar2 == 0) {
              local_aa0 = 0x104c2e;
              uVar12 = dcgettext(0,"%s: failed to unlock %s\n",5);
              local_aa0 = 0x104c4a;
              __fprintf_chk(stderr,1,uVar12,uVar13,pcVar8);
              local_aa0 = 0x104c56;
              pcVar8 = setlocale(6,(char *)0x0);
              if (pcVar8 != (char *)0x0) {
                local_aa0 = 0x104c6a;
                pcVar11 = strdup(pcVar8);
                pcVar8 = DAT_00111970;
                if (pcVar11 != (char *)0x0) {
                  local_aa0 = 0x104c8a;
                  setlocale(6,"C");
                  local_aa0 = 0x104ca5;
                  __syslog_chk(3,1,"failed to unlock %s",pcVar8);
                  local_aa0 = 0x104cb2;
                  setlocale(6,pcVar11);
                  local_aa0 = 0x104cba;
                  free(pcVar11);
                  goto LAB_00104b57;
                }
              }
              local_aa0 = 0x104cda;
              __syslog_chk(3,1,"failed to unlock %s",DAT_00111970);
            }
LAB_00104b57:
            local_aa0 = 0x104b63;
            pcVar11 = setlocale(6,(char *)0x0);
            pcVar8 = DAT_00111970;
            if (pcVar11 == (char *)0x0) {
LAB_00104be9:
              local_aa0 = 0x104c04;
              __syslog_chk(6,1,"file %s edited",pcVar8);
            }
            else {
              local_aa0 = 0x104b77;
              pcVar11 = strdup(pcVar11);
              if (pcVar11 == (char *)0x0) goto LAB_00104be9;
              local_aa0 = 0x104b90;
              setlocale(6,"C");
              local_aa0 = 0x104bab;
              __syslog_chk(6,1,"file %s edited",pcVar8);
              local_aa0 = 0x104bb8;
              setlocale(6,pcVar11);
              local_aa0 = 0x104bc0;
              free(pcVar11);
            }
            if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
              return;
            }
            goto LAB_00104da2;
          }
        }
        else {
LAB_00104e00:
          *(undefined8 *)((long)ppcVar15 + -8) = 0x104e12;
          FUN_00104400(local_448,1,1);
          puVar16 = (undefined1 *)ppcVar15;
        }
        *(undefined8 *)(puVar16 + -8) = 0x104e1d;
        FUN_00104400(0,0,0);
LAB_00104e1d:
        *(undefined8 *)(puVar16 + -8) = 0x104e22;
        piVar7 = __errno_location();
        iVar2 = *piVar7;
        *(undefined8 *)(puVar16 + -8) = 0x104e29;
        pcVar8 = strerror(iVar2);
        uVar13 = DAT_00111950;
        *(undefined8 *)(puVar16 + -8) = 0x104e46;
        uVar12 = dcgettext(0,"%s: %s: %s\n",5);
        *(undefined8 *)(puVar16 + -8) = 0x104e67;
        __fprintf_chk(stderr,1,uVar12,uVar13,*(undefined8 *)(puVar16 + 8),pcVar8);
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar16 + -8) = 0x104e71;
        exit(1);
      }
      goto LAB_00104d59;
    }
  }
  local_aa0 = 0x104da2;
  FUN_00104400(0,0,cVar14);
LAB_00104da2:
                    /* WARNING: Subroutine does not return */
  local_aa0 = 0x104da7;
  __stack_chk_fail();
}



