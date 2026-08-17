// Function: main @ 0x2a40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void main(int param_1,char **param_2)

{
  char cVar1;
  bool bVar2;
  __dev_t __dev;
  __uid_t _Var3;
  int iVar4;
  uint uVar5;
  __pid_t _Var6;
  int iVar7;
  int *piVar8;
  FILE *pFVar9;
  size_t sVar10;
  size_t sVar11;
  short *psVar12;
  char *pcVar13;
  tm *ptVar14;
  long lVar15;
  char *pcVar16;
  bool bVar17;
  __sigset_t *p_Var18;
  long in_FS_OFFSET;
  byte bVar19;
  undefined4 local_3b8;
  char *local_3b0;
  int local_37c;
  int local_378;
  int local_374;
  long local_370;
  stat local_368;
  sigaction local_2d8;
  undefined8 local_238 [32];
  char local_138 [48];
  char local_108 [64];
  char local_c8;
  char local_c7 [135];
  undefined8 local_40;
  
  bVar19 = 0;
  local_40 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  local_374 = 0;
  piVar8 = __errno_location();
  *piVar8 = 0;
  _Var3 = geteuid();
  iVar4 = setuid(_Var3);
  if (iVar4 == -1) goto LAB_00102b5c;
  _Var3 = getuid();
  pcVar16 = "shutdown: you must be root to do that!\n";
  if (_Var3 == 0) {
    _DAT_00108268 = 0x31;
    pcVar16 = local_108;
    for (lVar15 = 0x10; lVar15 != 0; lVar15 = lVar15 + -1) {
      pcVar16[0] = '\0';
      pcVar16[1] = '\0';
      pcVar16[2] = '\0';
      pcVar16[3] = '\0';
      pcVar16 = pcVar16 + (ulong)bVar19 * -8 + 4;
    }
    local_3b8 = 0;
    bVar17 = false;
    bVar2 = false;
    local_3b0 = (char *)0x0;
switchD_00102b21_caseD_79:
    iVar4 = getopt(param_1,param_2,"HPacqQkrhnfFyt:g:i:");
    if (iVar4 == -1) {
      if ((local_3b0 != (char *)0x0) && (DAT_00108268 != '0')) {
        pcVar16 = "shutdown: -H and -P flags can only be used along with -h flag.\n";
        goto LAB_00102b44;
      }
      if (bVar17) {
        lVar15 = 0;
        pFVar9 = fopen("/etc/shutdown.allow","r");
        if (pFVar9 != (FILE *)0x0) {
          do {
            iVar4 = (int)lVar15;
            do {
              pcVar16 = fgets(&local_c8,0x80,pFVar9);
              if (pcVar16 == (char *)0x0) {
                if (iVar4 != 0x20) {
                  local_238[iVar4] = 0;
                }
                fclose(pFVar9);
                goto LAB_00102fce;
              }
            } while ((local_c8 == '#' || local_c8 == '\n') || (0x1f < iVar4));
            pcVar16 = &local_c8;
            if (local_c8 != '\0') {
              while( true ) {
                pcVar13 = pcVar16 + 1;
                pcVar16 = pcVar16 + 1;
                if (*pcVar13 == '\0') break;
                if (*pcVar13 == '\n') {
                  *pcVar16 = '\0';
                }
              }
            }
            pcVar16 = strdup(&local_c8);
            local_238[lVar15] = pcVar16;
            lVar15 = lVar15 + 1;
          } while( true );
        }
      }
      goto LAB_00102d47;
    }
    switch(iVar4) {
    case 0x46:
      DAT_00108260 = 1;
      goto switchD_00102b21_caseD_79;
    default:
      goto switchD_00102b21_caseD_47;
    case 0x48:
      local_3b0 = "HALT";
      goto switchD_00102b21_caseD_79;
    case 0x50:
      local_3b0 = "POWEROFF";
      goto switchD_00102b21_caseD_79;
    case 0x51:
      local_3b8 = 2;
      goto switchD_00102b21_caseD_79;
    case 0x61:
      bVar17 = true;
      goto switchD_00102b21_caseD_79;
    case 99:
      bVar2 = true;
      goto switchD_00102b21_caseD_79;
    case 0x66:
      DAT_00108264 = 1;
      goto switchD_00102b21_caseD_79;
    case 0x67:
      strncpy(local_108,optarg,0x3f);
      goto switchD_00102b21_caseD_79;
    case 0x68:
      _DAT_00108268 = CONCAT11(DAT_00108268_1,0x30);
      goto switchD_00102b21_caseD_79;
    case 0x69:
      cVar1 = *optarg;
      pcVar16 = strchr("0156aAbBcCsS",(int)cVar1);
      if (pcVar16 == (char *)0x0) goto LAB_00103321;
      _DAT_00108268 = CONCAT11(DAT_00108268_1,cVar1);
      goto switchD_00102b21_caseD_79;
    case 0x6b:
      DAT_0010826c = 1;
      goto switchD_00102b21_caseD_79;
    case 0x6e:
      DAT_001080e4 = 1;
      goto switchD_00102b21_caseD_79;
    case 0x71:
      local_3b8 = 1;
      goto switchD_00102b21_caseD_79;
    case 0x72:
      _DAT_00108268 = CONCAT11(DAT_00108268_1,0x36);
      goto switchD_00102b21_caseD_79;
    case 0x74:
      DAT_00108140 = optarg;
    case 0x79:
      goto switchD_00102b21_caseD_79;
    }
  }
LAB_00102b44:
  __fprintf_chk(stderr,1,pcVar16);
  goto switchD_00102b21_caseD_47;
LAB_00102fce:
  do {
    do {
      psVar12 = (short *)getutent();
      if (psVar12 == (short *)0x0) {
        endutent();
        pFVar9 = fopen("/dev/console","w");
        if (pFVar9 != (FILE *)0x0) {
          __fprintf_chk(pFVar9,1,"\rshutdown: no authorized users logged in.\r\n");
          fclose(pFVar9);
        }
LAB_00102f03:
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
    } while (*psVar12 != 7);
    __sprintf_chk(local_138,1,0x26,"/dev/%.*s",0x20,psVar12 + 4);
    iVar4 = stat(local_138,&local_368);
    __dev = local_368.st_rdev;
  } while (((iVar4 < 0) || (uVar5 = gnu_dev_major(local_368.st_rdev), uVar5 != 4)) ||
          (uVar5 = gnu_dev_minor(__dev), 0x3f < uVar5));
  iVar4 = strcmp((char *)(psVar12 + 0x16),"root");
  if (iVar4 != 0) {
    lVar15 = 0;
    do {
      if ((char *)local_238[lVar15] == (char *)0x0) break;
      iVar4 = strncmp((char *)local_238[lVar15],(char *)(psVar12 + 0x16),0x20);
      if (iVar4 == 0) goto LAB_00102d42;
      lVar15 = lVar15 + 1;
    } while (lVar15 != 0x20);
    goto LAB_00102fce;
  }
LAB_00102d42:
  endutent();
LAB_00102d47:
  pFVar9 = fopen("/var/run/shutdown.pid","r");
  if (pFVar9 != (FILE *)0x0) {
    iVar4 = fscanf(pFVar9,"%d",&local_374);
    if (iVar4 != 1) {
      local_374 = 0;
    }
    fclose(pFVar9);
  }
  iVar4 = optind;
  uVar5 = 0;
  DAT_00108160 = '\0';
  if (!bVar2) {
    uVar5 = (uint)(local_108[0] == '\0');
  }
  lVar15 = (long)(int)(uVar5 + optind);
  while ((int)lVar15 < param_1) {
    sVar10 = strlen(&DAT_00108160);
    pcVar16 = param_2[lVar15];
    lVar15 = lVar15 + 1;
    sVar11 = strlen(pcVar16);
    if (0x100 < sVar10 + 4 + sVar11) break;
    __strcat_chk(&DAT_00108160,pcVar16,0x100);
    __strcat_chk(&DAT_00108160,&DAT_001059d7,0x100);
  }
  if (DAT_00108160 != '\0') {
    __strcat_chk(&DAT_00108160,&DAT_001059bd,0x100);
  }
  if (bVar2) {
    pcVar16 = "shutdown: cannot find pid of running shutdown.\n";
    if (0 < local_374) {
      FUN_00103800("INIT_HALT",0,"shutdown: cannot find pid of running shutdown.\n");
      iVar4 = kill(local_374,2);
      pcVar16 = "shutdown: not running.\n";
      if (-1 < iVar4) {
        if (DAT_00108160 != '\0') {
          FUN_00104540(&DAT_00108160,0,"shutdown: not running.\n");
        }
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
    }
    goto LAB_00102ef0;
  }
  if (local_108[0] == '\0') {
    if (iVar4 != param_1) {
      optind = iVar4 + 1;
      strncpy(local_108,param_2[iVar4],0x3f);
      goto LAB_00102e65;
    }
    goto switchD_00102b21_caseD_47;
  }
LAB_00102e65:
  if ((0 < local_374) && (iVar4 = kill(local_374,0), iVar4 == 0)) {
    __fprintf_chk(stderr,1,"\rshutdown: already running.\r\n");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (((DAT_001080e4 != 0) && (DAT_00108268 != '0')) &&
     (pcVar16 = "shutdown: can use \"-n\" for halt or reboot only.\r\n", DAT_00108268 != '6')) {
LAB_00102ef0:
    __fprintf_chk(stderr,1,pcVar16);
    goto LAB_00102f03;
  }
  if (DAT_00108268 == '1') {
    strncpy(&DAT_00108100,"to maintenance mode",0x40);
  }
  else if (DAT_00108268 == '6') {
    strncpy(&DAT_00108100,"for reboot",0x40);
  }
  else if (DAT_00108268 == '0') {
    strncpy(&DAT_00108100,"for system halt",0x40);
  }
  else {
    __snprintf_chk(&DAT_00108100,0x40,1,0x40,"to runlevel %s",&DAT_00108268);
  }
  iVar4 = chdir("/");
  if (iVar4 != 0) {
    pcVar16 = "shutdown: chdir(/): %m\n";
    goto LAB_00102ef0;
  }
  unlink("/var/run/shutdown.pid");
  umask(0x12);
  pFVar9 = fopen("/var/run/shutdown.pid","w");
  if (pFVar9 == (FILE *)0x0) {
    if (*piVar8 != 0x1e) {
      __fprintf_chk(stderr,1,"shutdown: warning: cannot open %s\n","/var/run/shutdown.pid");
    }
  }
  else {
    _Var6 = getpid();
    __fprintf_chk(pFVar9,1,&DAT_0010520d,_Var6);
    fclose(pFVar9);
  }
  signal(3,(__sighandler_t)0x1);
  signal(0x11,(__sighandler_t)0x1);
  signal(1,(__sighandler_t)0x1);
  signal(0x14,(__sighandler_t)0x1);
  signal(0x15,(__sighandler_t)0x1);
  signal(0x16,(__sighandler_t)0x1);
  p_Var18 = &local_2d8.sa_mask;
  for (lVar15 = 0x24; lVar15 != 0; lVar15 = lVar15 + -1) {
    *(undefined4 *)p_Var18->__val = 0;
    p_Var18 = (__sigset_t *)((long)p_Var18 + ((ulong)bVar19 * -2 + 1) * 4);
  }
  local_2d8.__sigaction_handler.sa_handler = FUN_001036f0;
  sigaction(2,&local_2d8,(sigaction *)0x0);
  if (DAT_00108264 != 0) {
    iVar4 = open("/fastboot",0x42,0x1a4);
    close(iVar4);
  }
  if (DAT_00108260 != 0) {
    iVar4 = open("/forcefsck",0x42,0x1a4);
    close(iVar4);
  }
  iVar4 = strcmp(local_108,"now");
  pcVar16 = local_108;
  if (iVar4 == 0) {
    local_108[0] = '0';
    local_108[1] = '\0';
  }
  for (; cVar1 = *pcVar16, cVar1 != '\0'; pcVar16 = pcVar16 + 1) {
    if ((cVar1 != '+') && (10 < (byte)(cVar1 - 0x30U))) goto switchD_00102b21_caseD_47;
  }
  pcVar16 = local_108;
  if (local_108[0] == '+') {
    pcVar16 = local_108 + 1;
  }
  pcVar13 = strchr(local_108,0x3a);
  if (pcVar13 != (char *)0x0) {
    iVar4 = sscanf(local_108,"%d:%2d",&local_37c,&local_378);
    if (iVar4 == 2) {
      if (local_108[0] == '+') {
        if (((local_37c < 100000) && (local_378 < 0x3c)) &&
           (iVar4 = local_37c * 0x3c + local_378, -1 < iVar4)) goto LAB_0010330e;
      }
      else if ((local_37c < 0x18) && (local_378 < 0x3c)) {
        time(&local_370);
        ptVar14 = localtime(&local_370);
        iVar4 = (local_37c * 0x3c + local_378) - (ptVar14->tm_hour * 0x3c + ptVar14->tm_min);
        if (iVar4 < 0) {
          iVar4 = iVar4 + 0x5a0;
        }
LAB_0010330e:
        if (iVar4 == 0) goto LAB_00103317;
        goto LAB_001033bc;
      }
    }
    goto switchD_00102b21_caseD_47;
  }
  iVar4 = atoi(pcVar16);
  if (iVar4 != 0) {
LAB_001033bc:
    time(&local_370);
    lVar15 = iVar4 * 0x3c + local_370;
    bVar17 = false;
    if ((iVar4 < 0xf) && (iVar7 = FUN_00103650(iVar4,local_3b8), iVar7 == 0)) {
      FUN_00103a30(iVar4);
    }
    while( true ) {
      if ((iVar4 < 6) && (!bVar17)) {
        bVar17 = true;
        FUN_00103b20(iVar4);
      }
      iVar7 = FUN_00103650(iVar4,local_3b8);
      if (iVar7 != 0) {
        FUN_00103a30(iVar4);
      }
      FUN_00103750(0x3c);
      time(&local_370);
      if (lVar15 <= local_370) goto LAB_00103317;
      iVar4 = (int)lVar15 - (int)local_370;
      if (lVar15 - local_370 < 0x3d) break;
      iVar4 = iVar4 / 0x3c;
      if (iVar4 == 0) {
LAB_00103317:
        FUN_00104030(local_3b0);
LAB_00103321:
        __fprintf_chk(stderr,1,"shutdown: `%s\': bad runlevel\n");
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
    }
    FUN_00103750(iVar4);
    goto LAB_00103317;
  }
  if (*pcVar16 == '0') goto LAB_00103317;
switchD_00102b21_caseD_47:
  FUN_001037d0();
LAB_00102b5c:
  pcVar16 = strerror(*piVar8);
  __fprintf_chk(stderr,1,"%s (%d): %s\n","shutdown.c",0x21d,pcVar16);
                    /* WARNING: Subroutine does not return */
  abort();
}



// Function: alrm_handler @ 0x3640

void alrm_handler(undefined4 param_1)

{
  DAT_001080e0 = param_1;
  return;
}



// Function: needwarning @ 0x3650

bool needwarning(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 2) {
    return false;
  }
  if (param_2 == 1) {
    if ((param_1 == 10) || (param_1 == 5)) {
      return true;
    }
  }
  else {
    if (param_1 < 10) {
      return true;
    }
    if (param_1 < 0x3c) {
      return param_1 * -0x11111111 + 0x8888888U < 0x11111111;
    }
    if (param_1 < 0xb4) {
      uVar1 = param_1 * -0x11111111 + 0x8888888;
      return (uVar1 >> 1 | (uint)((uVar1 & 1) != 0) << 0x1f) < 0x8888889;
    }
  }
  return (param_1 * -0x11111111 + 0x8888888U >> 2 | param_1 * -0x40000000) < 0x4444445;
}



// Function: stopit @ 0x36f0

void stopit(void)

{
  unlink("/etc/nologin");
  unlink("/fastboot");
  unlink("/forcefsck");
  unlink("/var/run/shutdown.pid");
  __printf_chk(1,"\r\nShutdown cancelled.\r\n");
                    /* WARNING: Subroutine does not return */
  exit(0);
}



// Function: hardsleep @ 0x3750

void hardsleep(int param_1)

{
  int iVar1;
  int *piVar2;
  long in_FS_OFFSET;
  timespec local_48;
  timespec local_38;
  long local_20;
  
  local_48.tv_sec = (__time_t)param_1;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_48.tv_nsec = 0;
  while( true ) {
    iVar1 = nanosleep(&local_48,&local_38);
    if (-1 < iVar1) break;
    piVar2 = __errno_location();
    if (*piVar2 != 4) break;
    local_48.tv_sec = local_38.tv_sec;
    local_48.tv_nsec = local_38.tv_nsec;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: usage @ 0x37d0

void usage(void)

{
  __fprintf_chk(stderr,1,
                "Usage:\t  shutdown [-akrhPHfFnc] [-t sec] time [warning message]\n\t\t  -a:      use /etc/shutdown.allow\n\t\t  -k:      don\'t really shutdown, only warn.\n\t\t  -r:      reboot after shutdown.\n\t\t  -h:      halt after shutdown.\n\t\t  -P:      halt action is to turn off power.\n\t\t           can only be used along with -h flag.\n\t\t  -H:      halt action is to just halt.\n\t\t           can only be used along with -h flag.\n\t\t  -f:      do a \'fast\' reboot (skip fsck).\n\t\t  -F:      Force fsck on reboot.\n\t\t  -n:      do not go through \"init\" but go down real fast.\n\t\t  -c:      cancel a running shutdown.\n\t\t  -q:      quiet mode - display fewer shutdown warnings.\n\t\t  -Q:      full quiet mode - display only final shutdown warning.\n\t\t  -t secs: delay between warning and kill signal.\n\t\t  ** the \"time\" argument is mandatory! (try \"now\") **\n"
               );
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: init_setenv @ 0x3800

undefined8 init_setenv(char *param_1,char *param_2)

{
  int __fd;
  size_t sVar1;
  size_t __n;
  undefined8 uVar2;
  ssize_t sVar3;
  int *piVar4;
  long lVar5;
  undefined8 *__buf;
  undefined8 *puVar6;
  __sigset_t *p_Var7;
  long in_FS_OFFSET;
  byte bVar8;
  sigaction local_258;
  undefined8 local_1b8 [2];
  undefined1 local_1a8 [376];
  long local_30;
  
  bVar8 = 0;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  __buf = local_1b8;
  puVar6 = __buf;
  for (lVar5 = 0x30; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_1b8[0] = 0x603091969;
  sVar1 = strlen(param_1);
  if (param_2 == (char *)0x0) {
    if (0x16f < sVar1 + 3) {
      uVar2 = 0xffffffff;
      goto LAB_00103948;
    }
    __memcpy_chk(local_1a8,param_1,sVar1,0x170);
  }
  else {
    __n = strlen(param_2);
    uVar2 = 0xffffffff;
    if (0x16f < sVar1 + 3 + __n) goto LAB_00103948;
    lVar5 = __memcpy_chk(local_1a8,param_1,sVar1,0x170);
    local_1a8[sVar1] = 0x3d;
    memcpy((void *)(lVar5 + 1 + sVar1),param_2,__n);
  }
  p_Var7 = &local_258.sa_mask;
  for (lVar5 = 0x12; lVar5 != 0; lVar5 = lVar5 + -1) {
    p_Var7->__val[0] = 0;
    p_Var7 = (__sigset_t *)((long)p_Var7 + ((ulong)bVar8 * -2 + 1) * 8);
  }
  local_258.__sigaction_handler.sa_handler = FUN_00103640;
  sigaction(0xe,&local_258,(sigaction *)0x0);
  DAT_001080e0 = 0;
  alarm(3);
  __fd = open("/run/initctl",1);
  if (__fd < 0) {
    __fprintf_chk(stderr,1,"shutdown: ");
    if (DAT_001080e0 == 0) {
      perror("/run/initctl");
      uVar2 = 0xffffffff;
    }
    else {
      __fprintf_chk(stderr,1,"timeout opening/writing control channel %s\n","/run/initctl");
      uVar2 = 0xffffffff;
    }
  }
  else {
    sVar1 = 0x180;
    do {
      while (sVar3 = write(__fd,__buf,sVar1), sVar3 < 0) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_00103938;
      }
      __buf = (undefined8 *)((long)__buf + sVar3);
      sVar1 = sVar1 - sVar3;
    } while (sVar1 != 0);
LAB_00103938:
    close(__fd);
    alarm(0);
    uVar2 = 0;
  }
LAB_00103948:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



// Function: issue_warn @ 0x3a30

void issue_warn(int param_1)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  char *extraout_RDX;
  long in_FS_OFFSET;
  char acStack_168 [328];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  strncpy(acStack_168,&DAT_00108160,0x100);
  sVar2 = strlen(acStack_168);
  iVar1 = (int)sVar2;
  if (param_1 == 0) {
    __snprintf_chk(acStack_168 + iVar1,0x141 - (long)iVar1,1,0xffffffffffffffff,
                   "\rThe system is going down %s NOW!\r\n",&DAT_00108100);
    pcVar3 = extraout_RDX;
  }
  else {
    pcVar3 = "";
    if (param_1 != 1) {
      pcVar3 = "s";
    }
    __snprintf_chk(acStack_168 + iVar1,0x141 - (long)iVar1,1,0xffffffffffffffff,
                   "\rThe system is going DOWN %s in %d minute%s!\r\n",&DAT_00108100,param_1);
  }
  FUN_00104540(acStack_168,0,pcVar3);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: donologin @ 0x3b20

void donologin(int param_1)

{
  FILE *__stream;
  char *pcVar1;
  long in_FS_OFFSET;
  long local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  time(&local_28);
  local_28 = local_28 + param_1 * 0x3c;
  __stream = fopen("/etc/nologin","w");
  if (__stream != (FILE *)0x0) {
    pcVar1 = ctime(&local_28);
    __fprintf_chk(__stream,1,"\rThe system is going down on %s\r\n",pcVar1);
    if (DAT_00108160 != '\0') {
      fputs(&DAT_00108160,__stream);
    }
    fclose(__stream);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: spawn @ 0x3be0

ulong spawn(int param_1,char *param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6)

{
  char *pcVar1;
  bool bVar2;
  __pid_t _Var3;
  int iVar4;
  int *piVar5;
  char **ppcVar6;
  ulong uVar7;
  undefined8 *puVar8;
  int unaff_R12D;
  long in_FS_OFFSET;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined1 *local_b8;
  undefined8 *local_b0;
  char *local_a8 [9];
  long local_60;
  undefined8 local_58 [6];
  
  local_60 = *(long *)(in_FS_OFFSET + 0x28);
  local_c4 = 0;
  local_58[2] = param_3;
  local_58[3] = param_4;
  local_58[4] = param_5;
  local_58[5] = param_6;
  while( true ) {
    _Var3 = fork();
    if (-1 < _Var3) break;
    if (9 < local_c4) goto LAB_00103d58;
    perror("fork");
    sleep(5);
    local_c4 = local_c4 + 1;
  }
  if (_Var3 != 0) {
    do {
      iVar4 = wait(&local_c4);
      while( true ) {
        if (_Var3 == iVar4) {
          local_c4._1_1_ = (byte)((uint)local_c4 >> 8);
          uVar7 = (ulong)local_c4._1_1_;
          goto LAB_00103d5d;
        }
        if (iVar4 < 0) break;
        iVar4 = wait(&local_c4);
      }
      piVar5 = __errno_location();
    } while (*piVar5 != 10);
LAB_00103d58:
    uVar7 = 0xffffffff;
LAB_00103d5d:
    if (local_60 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return uVar7;
  }
  if (param_1 != 0) {
    fclose(stderr);
  }
  local_b8 = &stack0x00000008;
  local_b0 = local_58;
  bVar2 = false;
  uVar7 = 0x10;
  puVar8 = (undefined8 *)&stack0x00000008;
  local_c0 = 0x10;
  iVar4 = 1;
  local_c4 = 1;
  ppcVar6 = local_a8;
  while( true ) {
    if ((uint)uVar7 < 0x30) {
      pcVar1 = *(char **)((long)local_b0 + uVar7);
      ppcVar6[1] = pcVar1;
      uVar7 = (ulong)((uint)uVar7 + 8);
    }
    else {
      pcVar1 = (char *)*puVar8;
      ppcVar6[1] = pcVar1;
      puVar8 = puVar8 + 1;
    }
    if (pcVar1 == (char *)0x0) break;
    iVar4 = iVar4 + 1;
    ppcVar6 = ppcVar6 + 1;
    bVar2 = true;
    unaff_R12D = iVar4;
    if (iVar4 == 7) {
      local_c4 = 7;
LAB_00103da0:
      local_a8[iVar4] = (char *)0x0;
      local_a8[0] = param_2;
      iVar4 = chdir("/");
      if (iVar4 == 0) {
        environ = &PTR_s_HOME___00108020;
        execvp(local_a8[0],local_a8);
        perror(local_a8[0]);
      }
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
  if (bVar2) {
    local_c4 = unaff_R12D;
  }
  goto LAB_00103da0;
}



// Function: fastdown @ 0x3df0

void fastdown(void)

{
  char cVar1;
  int iVar2;
  uint __seconds;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  
  cVar1 = DAT_00108268;
  iVar5 = 0;
  do {
    iVar2 = isatty(iVar5);
    if (iVar2 == 0) {
      close(iVar5);
      open("/dev/null",2);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 3);
  do {
    iVar2 = iVar5 + 1;
    close(iVar5);
    iVar5 = iVar2;
  } while (iVar2 != 0x14);
  close(0xff);
  iVar5 = kill(1,0x14);
  if (iVar5 < 0) {
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    __fprintf_chk(stderr,1,"shutdown: can\'t idle init: %s.\r\n",pcVar4);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __fprintf_chk(stderr,1,"shutdown: sending all processes the TERM signal...\r\n");
  kill(-1,0xf);
  if (DAT_00108140 == (char *)0x0) {
    __seconds = 3;
  }
  else {
    __seconds = atoi(DAT_00108140);
  }
  sleep(__seconds);
  __fprintf_chk(stderr,1,"shutdown: sending all processes the KILL signal.\r\n");
  kill(-1,9);
  FUN_00104ab0("shutdown",&DAT_0010507b,0,1);
  FUN_00103be0(1,"accton",0);
  FUN_00103be0(1,"quotaoff",&DAT_0010508e,0);
  sync();
  __fprintf_chk(stderr,1,"shutdown: turning off swap\r\n");
  FUN_00103be0(0,"swapoff",&DAT_0010508e,0);
  __fprintf_chk(stderr,1,"shutdown: unmounting all file systems\r\n");
  FUN_00103be0(0,"umount",&DAT_0010508e,0);
  if (cVar1 != '0') {
    __fprintf_chk(stderr,1,"Please stand by while rebooting the system.\r\n");
                    /* WARNING: Subroutine does not return */
    reboot(0x1234567);
  }
  __fprintf_chk(stderr,1,"The system is halted. Press CTRL-ALT-DEL or turn off power\r\n");
                    /* WARNING: Subroutine does not return */
  reboot(-0x3210fedd);
}



// Function: issue_shutdown @ 0x4030

void issue_shutdown(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  char *unaff_R13;
  long in_FS_OFFSET;
  char *local_78 [2];
  long local_68;
  undefined8 local_30;
  
  cVar1 = DAT_00108268;
  local_30 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  FUN_00103a30(0);
  if (DAT_0010826c != 0) {
    FUN_00103750(1);
    FUN_001036f0(0);
  }
  openlog("shutdown",1,8);
  if (cVar1 == '0') {
    __syslog_chk(5,1,"shutting down for system halt");
  }
  else {
    __syslog_chk(5,1,"shutting down for system reboot");
  }
  closelog();
  if (DAT_001080e4 == 0) {
    unaff_R13 = "/sbin/init";
    local_78[0] = "/sbin/init";
    if (DAT_00108140 != 0) {
      local_68 = DAT_00108140;
      iVar2 = 3;
      local_78[1] = "-t";
      goto LAB_001040f7;
    }
  }
  else {
    FUN_00103df0();
  }
  iVar2 = 1;
LAB_001040f7:
  local_78[iVar2] = &DAT_00108268;
  local_78[iVar2 + 1] = (char *)0x0;
  unlink("/var/run/shutdown.pid");
  unlink("/etc/nologin");
  sync();
  FUN_00103800("INIT_HALT",param_1);
  execv(unaff_R13,local_78);
  __fprintf_chk(stderr,1,"\rshutdown: cannot execute %s\r\n",unaff_R13);
  unlink("/fastboot");
  unlink("/forcefsck");
  FUN_00103800("INIT_HALT",0);
  openlog("shutdown",1,8);
  __syslog_chk(5,1,"shutdown failed");
  closelog();
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: handler @ 0x4200

void handler(void)

{
                    /* WARNING: Subroutine does not return */
  __longjmp_chk(&DAT_00108300,1);
}



// Function: file_isatty @ 0x4220

uint file_isatty(char *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long in_FS_OFFSET;
  stat local_a8;
  long local_10;
  
  uVar3 = 0;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = stat(param_1,&local_a8);
  if (((-1 < iVar1) && (local_a8.st_nlink == 1)) && ((local_a8.st_mode & 0xf000) == 0x2000)) {
    uVar2 = gnu_dev_major(local_a8.st_dev);
    if ((uVar2 - 1 < 2) || (uVar2 == 6)) {
      uVar3 = 0;
    }
    else if (uVar2 < 0x1c) {
      uVar3 = 1;
      if (8 < uVar2) {
        uVar3 = (uint)(0x8211200L >> ((byte)uVar2 & 0x3f)) & 1 ^ 1;
      }
    }
    else {
      uVar3 = 0;
      if (uVar2 != 0xce) {
        if (uVar2 < 0xcf) {
          if (uVar2 != 0x25) {
            uVar3 = (uint)(1 < uVar2 - 0x60);
          }
        }
        else {
          uVar3 = (uint)(uVar2 != 0xe6);
        }
      }
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: feputs @ 0x4330

void feputs(byte *param_1,FILE *param_2)

{
  char *pcVar1;
  byte bVar2;
  
  bVar2 = *param_1;
  while (bVar2 != 0) {
    while( true ) {
      pcVar1 = strchr("\t\r\n",(uint)bVar2);
      if (((pcVar1 != (char *)0x0) || ((byte)(bVar2 - 0x20) < 0x60)) || (0x9f < bVar2)) break;
      param_1 = param_1 + 1;
      __fprintf_chk(param_2,1,&DAT_001059c0,(bVar2 & 0x1f) + 0x40);
      bVar2 = *param_1;
      if (bVar2 == 0) goto LAB_001043be;
    }
    param_1 = param_1 + 1;
    fputc((uint)bVar2,param_2);
    bVar2 = *param_1;
  }
LAB_001043be:
  fflush(param_2);
  return;
}



// Function: getuidtty @ 0x43e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void getuidtty(undefined8 *param_1,undefined8 *param_2)

{
  __uid_t __uid;
  int iVar1;
  passwd *ppVar2;
  char *__s1;
  size_t __n;
  
  if (DAT_001082e0 == 0) {
    __uid = getuid();
    ppVar2 = getpwuid(__uid);
    if (ppVar2 == (passwd *)0x0) {
      if (__uid == 0) {
        _DAT_001082c0 = 0x746f6f72;
        DAT_001082c4 = 0;
      }
      else {
        __sprintf_chk(&DAT_001082c0,1,0x20,"uid %d",__uid);
      }
    }
    else {
      _DAT_001082c0 = _DAT_001082c0 & 0xffffff00;
      __strncat_chk(&DAT_001082c0,ppVar2->pw_name,0x1f,0x20);
    }
    __s1 = ttyname(0);
    if (__s1 == (char *)0x0) {
      DAT_00108280 = 0;
    }
    else {
      __n = strlen("/dev/");
      iVar1 = strncmp(__s1,"/dev/",__n);
      if (iVar1 == 0) {
        __s1 = __s1 + __n + (__s1[__n] == '/');
      }
      __snprintf_chk(&DAT_00108280,0x24,1,0x24,&DAT_001059d1,0x20,__s1);
    }
    DAT_001082e0 = DAT_001082e0 + 1;
  }
  *param_1 = &DAT_001082c0;
  *param_2 = &DAT_00108280;
  return;
}



// Function: wall @ 0x4540

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wall(undefined8 param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  long lVar3;
  FILE **ppFVar4;
  int iVar5;
  __pid_t _Var6;
  int iVar7;
  size_t sVar8;
  char *pcVar9;
  short *psVar10;
  undefined4 extraout_var;
  FILE *__stream;
  long lVar11;
  ulong uVar12;
  char *pcVar13;
  FILE **ppFVar14;
  __sigset_t *p_Var16;
  long in_FS_OFFSET;
  byte bVar17;
  FILE *local_268;
  int local_25c;
  char *local_258;
  undefined8 local_250;
  size_t local_248;
  long local_240;
  time_t local_230;
  undefined8 local_228;
  undefined8 local_220;
  sigaction local_218;
  char local_178 [8];
  undefined8 uStack_170;
  undefined1 local_168 [16];
  undefined1 local_158 [16];
  undefined1 local_148 [16];
  undefined1 local_138;
  char local_128 [264];
  long local_20;
  FILE **ppFVar15;
  
  bVar17 = 0;
  ppFVar14 = &local_268;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_250 = param_1;
  sVar8 = strlen("/dev/");
  local_240 = sVar8 + 0x21;
  local_248 = sVar8 + 0x20;
  ppFVar15 = &local_268;
  ppFVar4 = &local_268;
  while (ppFVar15 != (FILE **)((long)&local_268 - (sVar8 + 0x30 & 0xfffffffffffff000))) {
    ppFVar14 = (FILE **)((long)ppFVar4 + -0x1000);
    *(undefined8 *)((long)ppFVar4 + -8) = *(undefined8 *)((long)ppFVar4 + -8);
    ppFVar15 = (FILE **)((long)ppFVar4 + -0x1000);
    ppFVar4 = (FILE **)((long)ppFVar4 + -0x1000);
  }
  uVar12 = (ulong)((uint)(sVar8 + 0x30) & 0xff0);
  lVar3 = -uVar12;
  local_258 = (char *)((long)ppFVar14 + lVar3);
  if (uVar12 != 0) {
    *(undefined8 *)((long)ppFVar14 + -8) = *(undefined8 *)((long)ppFVar14 + -8);
  }
  *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1045e9;
  FUN_001043e0(&local_228,&local_220);
  *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1045fa;
  iVar5 = gethostname(local_178,0x41);
  if (iVar5 != 0) {
    local_178[0] = s__unknown__00105a40[0];
    local_178[1] = s__unknown__00105a40[1];
    local_178[2] = s__unknown__00105a40[2];
    local_178[3] = s__unknown__00105a40[3];
    local_178[4] = s__unknown__00105a40[4];
    local_178[5] = s__unknown__00105a40[5];
    local_178[6] = s__unknown__00105a40[6];
    local_178[7] = s__unknown__00105a40[7];
    uStack_170 = ram0x00105a48;
    local_168 = (undefined1  [16])0x0;
    local_158 = (undefined1  [16])0x0;
    local_148 = (undefined1  [16])0x0;
  }
  local_138 = 0;
  *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x10463c;
  time(&local_230);
  *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104644;
  pcVar9 = ctime(&local_230);
  cVar2 = *pcVar9;
  pcVar13 = pcVar9;
  while ((cVar2 != '\0' && (cVar2 != '\n'))) {
    pcVar1 = pcVar13 + 1;
    pcVar13 = pcVar13 + 1;
    cVar2 = *pcVar1;
  }
  *pcVar13 = '\0';
  if (param_2 == 0) {
    *(char **)((long)ppFVar14 + lVar3 + -0x10) = pcVar9;
    *(undefined8 *)((long)ppFVar14 + lVar3 + -0x18) = local_220;
    *(char **)((long)ppFVar14 + lVar3 + -0x20) = local_178;
    *(undefined8 *)((long)ppFVar14 + lVar3 + -0x28) = 0x1046f0;
    __snprintf_chk(local_128,0x100,1,0x100,"\r\nBroadcast message from %s@%s %s(%s):\r\n\r\n",
                   local_228);
  }
  else {
    *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104694;
    __snprintf_chk(local_128,0x100,1,0x100,"\r\nRemote broadcast message (%s):\r\n\r\n");
  }
  *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104699;
  _Var6 = fork();
  if (_Var6 != 0) {
    if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104710;
      __stack_chk_fail();
    }
    return;
  }
  p_Var16 = &local_218.sa_mask;
  for (lVar11 = 0x24; lVar11 != 0; lVar11 = lVar11 + -1) {
    *(undefined4 *)p_Var16->__val = 0;
    p_Var16 = (__sigset_t *)((long)p_Var16 + (ulong)bVar17 * -8 + 4);
  }
  local_218.__sigaction_handler.sa_handler = FUN_00104200;
  *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x10473e;
  sigemptyset(&local_218.sa_mask);
  *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x10474d;
  sigaction(0xe,&local_218,(sigaction *)0x0);
  *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104752;
  setutent();
  do {
    do {
      do {
        *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104757;
        psVar10 = (short *)getutent();
        if (psVar10 == (short *)0x0) {
          *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104835;
          endutent();
                    /* WARNING: Subroutine does not return */
          *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x10483c;
          exit(0);
        }
      } while ((*psVar10 != 7) || ((char)psVar10[0x16] == '\0'));
      psVar10 = psVar10 + 4;
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104783;
      sVar8 = strlen("/dev/");
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104795;
      iVar5 = strncmp((char *)psVar10,"/dev/",sVar8);
      if (iVar5 == 0) {
        *local_258 = '\0';
        *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1047b9;
        strncat(local_258,(char *)psVar10,local_248);
      }
      else {
        *(ulong *)((long)ppFVar14 + lVar3 + -8) = CONCAT44(extraout_var,iVar5);
        *(short **)((long)ppFVar14 + lVar3 + -0x10) = psVar10;
        *(undefined8 *)((long)ppFVar14 + lVar3 + -0x18) = 0x10486a;
        __snprintf_chk(local_258,local_240,1,0xffffffffffffffff,"/dev/%.*s",0x20);
      }
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1047cc;
      local_268 = (FILE *)strstr(local_258,"/../");
    } while (local_268 != (FILE *)0x0);
    local_25c = -1;
    *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1047f7;
    iVar5 = __sigsetjmp(&DAT_00108300,1);
    if (iVar5 == 0) {
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1048a3;
      alarm(2);
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1048af;
      iVar5 = FUN_00104220();
      if (iVar5 == 0) goto LAB_00104803;
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1048ca;
      iVar5 = open(local_258,0x901);
      local_25c = iVar5;
      if (-1 < iVar5) {
        *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104878;
        iVar7 = isatty(iVar5);
        if (iVar7 != 0) {
          *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1048f4;
          __stream = fdopen(local_25c,"w");
          local_268 = __stream;
          if (__stream != (FILE *)0x0) {
            *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104916;
            fputs(local_128,__stream);
            *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104925;
            FUN_00104330(local_250,__stream);
            *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x10492d;
            fflush(__stream);
            goto LAB_00104803;
          }
        }
        *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104883;
        alarm(0);
        local_25c = iVar5;
        goto LAB_00104889;
      }
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x1048dd;
      alarm(0);
    }
    else {
LAB_00104803:
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x10480a;
      alarm(0);
      if (-1 < local_25c) {
LAB_00104889:
        *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x104894;
        close(local_25c);
      }
    }
    if (local_268 != (FILE *)0x0) {
      *(undefined8 *)((long)ppFVar14 + lVar3 + -8) = 0x10482b;
      fclose(local_268);
    }
  } while( true );
}



// Function: write_wtmp @ 0x4ab0

void write_wtmp(char *param_1,char *param_2,undefined4 param_3,undefined2 param_4,char *param_5)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long in_FS_OFFSET;
  byte bVar5;
  timeval local_358;
  undefined2 local_348 [2];
  undefined4 local_344;
  char local_340 [32];
  char local_320 [4];
  char local_31c [32];
  char local_2fc [308];
  utsname local_1c8;
  long local_40;
  
  bVar5 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = access("/var/log/wtmp",2);
  if (-1 < iVar1) {
    iVar1 = open("/var/log/wtmp",0x401);
    if (-1 < iVar1) {
      puVar4 = (undefined8 *)local_348;
      for (lVar3 = 0x30; lVar3 != 0; lVar3 = lVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
      }
      gettimeofday(&local_358,(__timezone_ptr_t)0x0);
      local_348[0] = param_4;
      local_344 = param_3;
      strncpy(local_31c,param_1,0x20);
      strncpy(local_320,param_2,4);
      strncpy(local_340,param_5,0x20);
      iVar2 = uname(&local_1c8);
      if (iVar2 == 0) {
        strncpy(local_2fc,local_1c8.release,0x100);
      }
      updwtmp("/var/log/wtmp",local_348);
      close(iVar1);
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: write_utmp_wtmp @ 0x4c20

void write_utmp_wtmp(long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5)

{
  char *pcVar1;
  long in_FS_OFFSET;
  char local_68 [40];
  long local_40;
  
  pcVar1 = local_68;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 != 0) {
    local_68[0] = '\0';
    FUN_00104940();
    if ((param_5 != (char *)0x0) && (pcVar1 = param_5, *param_5 == '\0')) {
      pcVar1 = local_68;
    }
    FUN_00104ab0(param_1,param_2,param_3,param_4,pcVar1);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



