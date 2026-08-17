// Function: main @ 0x3be0

void main(undefined4 param_1,long *param_2)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = strrchr((char *)*param_2,0x2f);
  DAT_0014e300 = pcVar2 + 1;
  if (pcVar2 == (char *)0x0) {
    DAT_0014e300 = (char *)*param_2;
  }
  DAT_00151580 = getpid();
  DAT_0012e2e0 = 0;
  DAT_0010e2e0 = 0;
  setlocale(6,"");
  FUN_001049c0(param_1,param_2);
  FUN_00108430();
  iVar1 = FUN_001064b0(&DAT_00151380,"/usr/local/etc/cron.allow","/usr/local/etc/cron.deny");
  if (iVar1 == 0) {
    __fprintf_chk(stderr,1,"You (%s) are not allowed to use this program (%s)\n",&DAT_00151480,
                  DAT_0014e300);
    __fprintf_chk(stderr,1,"See crontab(1) for more information\n");
    FUN_00108720(&DAT_00151380,DAT_00151580,&DAT_0010a473,"crontab command not allowed",0);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  switch(DAT_0014f328) {
  case 0:
    break;
  case 1:
    FUN_001040d0();
    iVar1 = 0;
    goto LAB_00103cab;
  case 2:
    FUN_00104380();
    iVar1 = 0;
    goto LAB_00103cab;
  case 3:
    FUN_00105820();
    iVar1 = 0;
    goto LAB_00103cab;
  case 4:
    iVar1 = FUN_001053d0();
    goto joined_r0x00103ca0;
  case 5:
    iVar1 = FUN_001050e0();
    if (-1 < iVar1) {
      iVar1 = 0;
      goto LAB_00103cab;
    }
    break;
  case 6:
    iVar1 = FUN_00104820();
    if (-1 < iVar1) {
      iVar1 = 0;
      goto LAB_00103cab;
    }
    break;
  case 7:
    iVar1 = FUN_001047c0();
joined_r0x00103ca0:
    if (-1 < iVar1) {
      iVar1 = 0;
      goto LAB_00103cab;
    }
    break;
  default:
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar1 = 1;
LAB_00103cab:
                    /* WARNING: Subroutine does not return */
  exit(iVar1);
}



// Function: check_error @ 0x3e80

void check_error(undefined8 param_1)

{
  DAT_0014f334 = DAT_0014f334 + 1;
  __fprintf_chk(stderr,1,"\"%s\":%d: %s\n",&DAT_00150380,DAT_0014e2fc + -1,param_1);
  return;
}



// Function: usage @ 0x3ec0

void usage(undefined8 param_1)

{
  __fprintf_chk(stderr,1,"%s: usage error: %s\n",DAT_0014e300,param_1);
  __fprintf_chk(stderr,1,"Usage:\n");
  __fprintf_chk(stderr,1," %s [options] file\n",DAT_0014e300);
  __fprintf_chk(stderr,1," %s [options]\n",DAT_0014e300);
  __fprintf_chk(stderr,1," %s -n [hostname]\n",DAT_0014e300);
  __fprintf_chk(stderr,1,&DAT_0010af6f);
  __fprintf_chk(stderr,1,"Options:\n");
  __fprintf_chk(stderr,1," -u <user>  define user\n");
  __fprintf_chk(stderr,1," -e         edit user\'s crontab\n");
  __fprintf_chk(stderr,1," -l         list user\'s crontab\n");
  __fprintf_chk(stderr,1," -r         delete user\'s crontab\n");
  __fprintf_chk(stderr,1," -i         prompt before deleting\n");
  __fprintf_chk(stderr,1," -n <host>  set host in cluster to run users\' crontabs\n");
  __fprintf_chk(stderr,1," -c         get host in cluster to run users\' crontabs\n");
  __fprintf_chk(stderr,1," -T <file>  test a crontab file syntax\n");
  __fprintf_chk(stderr,1," -V         print version and exit\n");
  __fprintf_chk(stderr,1," -x <mask>  enable debugging\n");
  __fprintf_chk(stderr,1,"\nDefault operation is replace, per 1003.2\n");
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: list_cmd @ 0x40d0

void list_cmd(void)

{
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  int *piVar3;
  bool bVar4;
  long in_FS_OFFSET;
  bool bVar5;
  bool bVar6;
  char acStack_1048 [4104];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = isatty(1);
  bVar6 = false;
  if (iVar1 != 0) {
    pcVar2 = getenv("NO_COLOR");
    bVar6 = pcVar2 == (char *)0x0;
  }
  FUN_00108720(&DAT_00151380,DAT_00151580,&DAT_0010a0ae,&DAT_00151480,0);
  iVar1 = FUN_00108130(acStack_1048,0x1000,"/usr/local/var/spool/cron",&DAT_00151480,0x2f);
  if (iVar1 == 0) {
    __fprintf_chk(stderr,1,"path too long\n");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __stream = fopen(acStack_1048,"r");
  if (__stream == (FILE *)0x0) {
    piVar3 = __errno_location();
    if (*piVar3 == 2) {
      __fprintf_chk(stderr,1,"no crontab for %s\n",&DAT_00151480);
    }
    else {
      perror(acStack_1048);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (((byte)DAT_0010e2c0 & 9) != 0) {
    __printf_chk(1,"linenum=%d\n",1);
  }
  bVar4 = false;
  bVar5 = true;
  DAT_0014e2fc = 1;
  while( true ) {
    iVar1 = FUN_00108570(__stream);
    if (iVar1 == -1) break;
    if (bVar6) {
      if ((bool)(bVar5 & (bVar4 ^ 1U))) {
        bVar4 = false;
        if (iVar1 == 0x23) {
          fputs("\x1b[34;1m",stdout);
          bVar4 = true;
        }
      }
      else if ((iVar1 == 10) && (bVar4)) {
        bVar4 = false;
        fputs("\x1b[0m",stdout);
      }
    }
    putchar(iVar1);
    bVar5 = iVar1 == 10;
  }
  if ((bool)((bVar5 ^ 1U) & bVar6)) {
    putchar(10);
    fputs("\x1b[31;1mNo end-of-line character at the end of file\x1b[0m",stdout);
    putchar(10);
  }
  fclose(__stream);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: poke_daemon @ 0x4330

void poke_daemon(void)

{
  int iVar1;
  
  iVar1 = utime("/usr/local/var/spool/cron",(utimbuf *)0x0);
  if (-1 < iVar1) {
    return;
  }
  __fprintf_chk(stderr,1,"crontab: can\'t update mtime on spooldir\n");
  perror("/usr/local/var/spool/cron");
  return;
}



// Function: delete_cmd @ 0x4380

void delete_cmd(void)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  long lVar4;
  undefined8 *puVar5;
  long in_FS_OFFSET;
  undefined1 local_1028 [16];
  undefined8 local_1018 [511];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_1028 = (undefined1  [16])0x0;
  puVar5 = local_1018;
  for (lVar4 = 0x1fe; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  if (DAT_0014f330 == 1) {
    __printf_chk(1,"crontab: really delete %s\'s crontab? ",&DAT_00151480);
    fflush(stdout);
    pcVar2 = fgets(local_1028,0xfff,stdin);
    if ((pcVar2 == (char *)0x0) || ((local_1028[0] & 0xdf) != 0x59)) {
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  }
  FUN_00108720(&DAT_00151380,DAT_00151580,"DELETE",&DAT_00151480,0);
  iVar1 = FUN_00108130(local_1028,0x1000,"/usr/local/var/spool/cron",&DAT_00151480,0x2f);
  if (iVar1 == 0) {
    __fprintf_chk(stderr,1,"path too long\n");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar1 = unlink(local_1028);
  if (iVar1 == 0) {
    FUN_00104330();
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  piVar3 = __errno_location();
  if (*piVar3 == 2) {
    __fprintf_chk(stderr,1,"no crontab for %s\n",&DAT_00151480);
  }
  else {
    perror(local_1028);
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: tmp_path @ 0x4500

char * tmp_path(void)

{
  __uid_t _Var1;
  __uid_t _Var2;
  __gid_t _Var3;
  __gid_t _Var4;
  char *pcVar5;
  
  _Var1 = getuid();
  _Var2 = geteuid();
  if (_Var1 == _Var2) {
    _Var3 = getgid();
    _Var4 = getegid();
    if (_Var3 == _Var4) {
      pcVar5 = getenv("TMPDIR");
      if (pcVar5 != (char *)0x0) {
        return pcVar5;
      }
    }
  }
  return "/tmp";
}



// Function: die @ 0x4540

void die(void)

{
  if (DAT_0014f380 != '\0') {
    unlink(&DAT_0014f380);
  }
                    /* WARNING: Subroutine does not return */
  _exit(1);
}



// Function: check_syntax @ 0x4570

int check_syntax(undefined8 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  long in_FS_OFFSET;
  undefined1 auStack_20028 [131072];
  
  puVar1 = &stack0xffffffffffffffd8;
  do {
    puVar7 = puVar1;
    *(undefined8 *)(puVar7 + -0x1000) = *(undefined8 *)(puVar7 + -0x1000);
    puVar1 = puVar7 + -0x1000;
  } while (puVar7 + -0x1000 != auStack_20028);
  *(undefined8 *)(puVar7 + 0x1eff8) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(puVar7 + -0x1018) = 0x1045b0;
  lVar3 = FUN_00107800();
  DAT_0014f334 = 0;
  if (((byte)DAT_0010e2c0 & 9) != 0) {
    *(undefined8 *)(puVar7 + -0x1018) = 0x104740;
    __printf_chk(1,"linenum=%d\n",1);
  }
  DAT_0014e2fc = 1;
  if (lVar3 == 0) {
    *(undefined8 *)(puVar7 + -0x1018) = 0x1047aa;
    __fprintf_chk(stderr,1,"%s: Cannot allocate memory.\n",DAT_0014e300);
    iVar8 = -2;
    goto LAB_001046c1;
  }
  iVar9 = 0;
  iVar8 = DAT_0014f334;
  if (DAT_0014f334 == 0) {
    do {
      *(undefined8 *)(puVar7 + -0x1018) = 0x10461b;
      iVar2 = FUN_00108690(param_1);
      if (iVar2 == 0) {
        *(undefined8 *)(puVar7 + -0x1018) = 0x1046fc;
        FUN_00103e80("too much non-parseable content (comments, empty lines, spaces)");
        break;
      }
      *(undefined8 *)(puVar7 + -0x1018) = 0x10462e;
      iVar2 = FUN_00107b20(puVar7 + -0x1010,param_1);
      if (iVar2 == 0) {
        *(undefined8 *)(puVar7 + -0x1018) = 0x104655;
        lVar4 = FUN_00106d50(param_1,FUN_00103e80,DAT_0014f320,lVar3);
        if (lVar4 != 0) {
          iVar9 = iVar9 + 1;
          *(undefined8 *)(puVar7 + -0x1018) = 0x104666;
          FUN_00106d20(lVar4);
        }
      }
      else if (iVar2 == 1) {
        iVar8 = iVar8 + 1;
      }
      else if (iVar2 == -1) {
        if (puVar7[-0x1010] != '\0') {
          if (((byte)DAT_0010e2c0 & 9) != 0) {
            *(undefined8 *)(puVar7 + -0x1018) = 0x10471c;
            __printf_chk(1,"linenum=%d\n",DAT_0014e2fc + 1);
          }
          DAT_0014e2fc = DAT_0014e2fc + 1;
          *(undefined8 *)(puVar7 + -0x1018) = 0x104696;
          FUN_00103e80("premature EOF");
        }
        break;
      }
    } while (DAT_0014f334 == 0);
    *(undefined8 *)(puVar7 + -0x1018) = 0x10469e;
    FUN_00107830(lVar3);
    if (iVar8 < 0x3e9) {
      if (iVar9 < 0x2711) goto LAB_001046b7;
      uVar5 = 10000;
      pcVar6 = "There are too many entries in the crontab file. Limit: %d\n";
    }
    else {
      uVar5 = 1000;
      pcVar6 = "There are too many environment variables in the crontab file. Limit: %d\n";
    }
    *(undefined8 *)(puVar7 + -0x1018) = 0x104771;
    __fprintf_chk(stderr,1,pcVar6,uVar5);
    iVar8 = -1;
  }
  else {
    *(undefined8 *)(puVar7 + -0x1018) = 0x10474d;
    FUN_00107830(lVar3);
LAB_001046b7:
    iVar8 = -(uint)(DAT_0014f334 != 0);
  }
LAB_001046c1:
  if (*(long *)(puVar7 + 0x1eff8) == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar8;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar7 + -0x1018) = &UNK_001047b9;
  __stack_chk_fail();
}



// Function: test_cmd @ 0x47c0

undefined8 test_cmd(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00104570(DAT_0014f338);
  if (iVar1 < 0) {
    __fprintf_chk(stderr,1,"Invalid crontab file. Syntax issues were found.\n");
    uVar2 = 0xfffffffe;
  }
  else {
    __fprintf_chk(stderr,1,"No syntax issues were found in the crontab file.\n");
    uVar2 = 0;
  }
  return uVar2;
}



// Function: hostget_cmd @ 0x4820

undefined8 hostget_cmd(void)

{
  int iVar1;
  FILE *__stream;
  undefined8 uVar2;
  int *piVar3;
  long in_FS_OFFSET;
  char acStack_1028 [4104];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_00108130(acStack_1028,0x1000,"/usr/local/var/spool/cron",".cron.hostname",0x2f);
  if (iVar1 == 0) {
    __fprintf_chk(stderr,1,"path too long\n");
    uVar2 = 0xfffffffe;
  }
  else {
    __stream = fopen(acStack_1028,"r");
    if (__stream == (FILE *)0x0) {
      piVar3 = __errno_location();
      if (*piVar3 == 2) {
        __fprintf_chk(stderr,1,"File %s not found\n",acStack_1028);
        uVar2 = 0xfffffffe;
      }
      else {
        perror(acStack_1028);
        uVar2 = 0xfffffffe;
      }
    }
    else {
      iVar1 = FUN_00108620(&DAT_0014f340,0x40,__stream,&DAT_0010af6f);
      if (iVar1 == -1) {
        __fprintf_chk(stderr,1,"Error reading from %s\n",acStack_1028);
        fclose(__stream);
        uVar2 = 0xfffffffe;
      }
      else {
        fclose(__stream);
        __printf_chk(1,"%s\n",&DAT_0014f340);
        fflush(stdout);
        FUN_00108720(&DAT_00151380,DAT_00151580,"GET HOST",&DAT_0014f340,0);
        uVar2 = 0;
      }
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: parse_args @ 0x49c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void parse_args(int param_1,char **param_2)

{
  __uid_t _Var1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  long in_FS_OFFSET;
  stat local_d8;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  _Var1 = getuid();
  DAT_0014f320 = getpwuid(_Var1);
  if (DAT_0014f320 == (passwd *)0x0) {
    __fprintf_chk(stderr,1,"%s: your UID isn\'t in the passwd file.\n",DAT_0014e300);
    pcVar4 = "bailing out.\n";
    goto LAB_00104ec9;
  }
  pcVar4 = DAT_0014f320->pw_name;
  sVar3 = strlen(pcVar4);
  if (0xff < sVar3) {
    pcVar4 = "username too long\n";
    goto LAB_00104ec9;
  }
  __strcpy_chk(&DAT_00151480,pcVar4,0x100);
  __strcpy_chk(&DAT_00151380,&DAT_00151480,0x100);
  _DAT_00150380 = _DAT_00150380 & 0xff00;
  DAT_0014f328 = 0;
  DAT_0014f330 = 0;
  DAT_0014f32c = 0;
LAB_00104a80:
  iVar2 = getopt(param_1,param_2,"u:lerincx:VT");
  if (iVar2 != -1) {
    switch(iVar2) {
    case 0x54:
      if (DAT_0014f328 == 0) {
        DAT_0014f328 = 7;
        goto LAB_00104a80;
      }
      break;
    default:
      FUN_00103ec0("unrecognized option");
    case 0x56:
      puts("cronie 1.6.1");
                    /* WARNING: Subroutine does not return */
      exit(0);
    case 99:
      if (DAT_0014f328 != 0) break;
      iVar2 = strcmp(&DAT_00151480,&DAT_00151380);
      if (iVar2 != 0) goto LAB_00104ec2;
      DAT_0014f328 = 6;
      goto LAB_00104a80;
    case 0x65:
      if (DAT_0014f328 == 0) {
        DAT_0014f328 = 3;
        goto LAB_00104a80;
      }
      break;
    case 0x69:
      DAT_0014f330 = 1;
      goto LAB_00104a80;
    case 0x6c:
      if (DAT_0014f328 == 0) {
        DAT_0014f328 = 1;
        goto LAB_00104a80;
      }
      break;
    case 0x6e:
      _Var1 = getuid();
      if (_Var1 != 0) {
        pcVar4 = "must be privileged to set host with -n\n";
        goto LAB_00104ec9;
      }
      if (DAT_0014f328 == 0) {
        iVar2 = strcmp(&DAT_00151480,&DAT_00151380);
        if (iVar2 != 0) goto LAB_00104ec2;
        DAT_0014f328 = 5;
        goto LAB_00104a80;
      }
      break;
    case 0x72:
      if (DAT_0014f328 == 0) {
        DAT_0014f328 = 2;
        goto LAB_00104a80;
      }
      break;
    case 0x75:
      goto switchD_00104aaa_caseD_75;
    case 0x78:
      goto switchD_00104aaa_caseD_78;
    }
    FUN_00103ec0("only one operation permitted");
LAB_00104ec2:
    pcVar4 = "cannot use -u with -n or -c\n";
    goto LAB_00104ec9;
  }
  endpwent();
  iVar2 = optind;
  if (DAT_0014f328 == 5) {
    pcVar4 = param_2[optind];
    if (pcVar4 != (char *)0x0) {
      DAT_0014f32c = 1;
      sVar3 = strlen(pcVar4);
      if (0x3f < sVar3) {
        FUN_00103ec0("hostname too long");
        goto LAB_00104fd8;
      }
      __strcpy_chk(&DAT_0014f340,pcVar4,0x40);
      optind = iVar2 + 1;
    }
LAB_00104cbf:
    if (param_2[optind] == (char *)0x0) {
      if (DAT_00150380 != '\0') {
        iVar2 = strcmp(&DAT_00150380,"-");
        if (iVar2 == 0) {
          DAT_0014f338 = stdin;
        }
        else {
          iVar2 = FUN_00108d30();
          if (iVar2 < 0) {
            perror("swapping uids");
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
          DAT_0014f338 = fopen(&DAT_00150380,"r");
          if (DAT_0014f338 == (FILE *)0x0) {
LAB_00104f2f:
            perror(&DAT_00150380);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
          iVar2 = fileno(DAT_0014f338);
          iVar2 = fstat(iVar2,&local_d8);
          if (iVar2 < 0) goto LAB_00104f2f;
          if ((local_d8.st_mode & 0xf000) == 0x4000) {
            __fprintf_chk(stderr,1,"invalid crontab file: \'%s\' is a directory\n",&DAT_00150380);
            fclose(DAT_0014f338);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
          iVar2 = FUN_00108d80();
          if (iVar2 < 0) {
            perror("swapping uids back");
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
        }
      }
      if (((byte)DAT_0010e2c0 & 0x20) == 0) {
        if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
      }
      else if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        __printf_chk(1,"user=%s, file=%s, option=%s\n",&DAT_00151480,&DAT_00150380,
                     (&PTR_DAT_0010da40)[DAT_0014f328]);
        return;
      }
LAB_00104fd8:
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  }
  else {
    if (DAT_0014f328 == 0) {
      DAT_0014f328 = 4;
    }
    else if ((DAT_0014f328 != 4) && (DAT_0014f328 != 7)) goto LAB_00104cbf;
    pcVar4 = param_2[optind];
    if (pcVar4 == (char *)0x0) {
      iVar2 = isatty(0);
      if (iVar2 != 0) {
        FUN_00103ec0("file name or - (for stdin) must be specified");
LAB_00104f4d:
        FUN_00103ec0("username too long");
LAB_00104f59:
        __fprintf_chk(stderr,1,"%s:  user `%s\' unknown\n",DAT_0014e300,optarg);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      _DAT_00150380 = 0x2d;
      goto LAB_00104cbf;
    }
    sVar3 = strlen(pcVar4);
    if (sVar3 < 0x1000) {
      __strcpy_chk(&DAT_00150380,pcVar4,0x1000);
      optind = iVar2 + 1;
      goto LAB_00104cbf;
    }
    FUN_00103ec0("filename too long");
  }
  FUN_00103ec0("no arguments permitted after this option");
LAB_00104ff5:
  pcVar4 = "cannot use -u with -n, -c or -T\n";
LAB_00104ec9:
  __fprintf_chk(stderr,1,pcVar4);
                    /* WARNING: Subroutine does not return */
  exit(1);
switchD_00104aaa_caseD_78:
  iVar2 = FUN_00108280(optarg);
  if (iVar2 == 0) {
    FUN_00103ec0("bad debug option");
switchD_00104aaa_caseD_75:
    _Var1 = getuid();
    if (_Var1 != 0) {
      pcVar4 = "must be privileged to use -u\n";
      goto LAB_00104ec9;
    }
    if (DAT_0014f328 - 5U < 3) goto LAB_00104ff5;
    DAT_0014f320 = getpwnam(optarg);
    pcVar4 = optarg;
    if (DAT_0014f320 == (passwd *)0x0) goto LAB_00104f59;
    sVar3 = strlen(optarg);
    if (0xff < sVar3) goto LAB_00104f4d;
    __strcpy_chk(&DAT_00151480,pcVar4,0x100);
  }
  goto LAB_00104a80;
}



// Function: hostset_cmd @ 0x50e0

undefined4 hostset_cmd(void)

{
  int iVar1;
  long lVar2;
  FILE *__stream;
  undefined4 uVar3;
  long in_FS_OFFSET;
  char acStack_1038 [4104];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (DAT_0014f32c == 0) {
    gethostname(&DAT_0014f340,0x40);
  }
  lVar2 = FUN_00105010();
  if (lVar2 != 0) {
    iVar1 = FUN_00108130(&DAT_0014f380,0x1000,"/usr/local/var/spool/cron",lVar2,0x2f);
    if (iVar1 != 0) {
      iVar1 = mkstemp(&DAT_0014f380);
      if (iVar1 == -1) {
        perror(&DAT_0014f380);
      }
      else {
        __stream = fdopen(iVar1,"w");
        if (__stream != (FILE *)0x0) {
          signal(1,FUN_00104540);
          signal(2,FUN_00104540);
          signal(3,FUN_00104540);
          fchmod(iVar1,0x180);
          iVar1 = __fprintf_chk(__stream,1,"%s\n",&DAT_0014f340);
          if (iVar1 < 0) {
LAB_0010525a:
            uVar3 = 0xfffffffe;
            __fprintf_chk(stderr,1,"%s: error while writing to %s\n",DAT_0014e300,&DAT_0014f380);
          }
          else {
            iVar1 = fclose(__stream);
            if (iVar1 == -1) goto LAB_0010525a;
            iVar1 = FUN_00108130(acStack_1038,0x1000,"/usr/local/var/spool/cron",".cron.hostname",
                                 0x2f);
            if (iVar1 == 0) {
              uVar3 = 0xfffffffe;
              __fprintf_chk(stderr,1,"path too long\n");
            }
            else {
              iVar1 = rename(&DAT_0014f380,acStack_1038);
              if (iVar1 == 0) {
                DAT_0014f380 = '\0';
                FUN_00108720(&DAT_00151380,DAT_00151580,"SET HOST",&DAT_0014f340,0);
                FUN_00104330();
                uVar3 = 0;
              }
              else {
                uVar3 = 0xfffffffe;
                __fprintf_chk(stderr,1,"%s: error renaming %s to %s\n",DAT_0014e300,&DAT_0014f380,
                              acStack_1038);
                perror("rename");
              }
            }
          }
          signal(1,(__sighandler_t)0x0);
          signal(2,(__sighandler_t)0x0);
          signal(3,(__sighandler_t)0x0);
          if (DAT_0014f380 != '\0') {
            unlink(&DAT_0014f380);
            DAT_0014f380 = '\0';
          }
          goto LAB_001052b5;
        }
        perror(&DAT_0014f380);
        close(iVar1);
        unlink(&DAT_0014f380);
      }
      DAT_0014f380 = '\0';
      uVar3 = 0xfffffffe;
      goto LAB_001052b5;
    }
  }
  DAT_0014f380 = '\0';
  uVar3 = 0xfffffffe;
  __fprintf_chk(stderr,1,"path too long\n");
LAB_001052b5:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: replace_cmd @ 0x53d0

int replace_cmd(void)

{
  int iVar1;
  __gid_t _Var2;
  __uid_t _Var3;
  int iVar4;
  __gid_t _Var5;
  long lVar6;
  FILE *__stream;
  long in_FS_OFFSET;
  char acStack_1048 [4104];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar6 = FUN_00105010();
  if (lVar6 != 0) {
    iVar1 = FUN_00108130(&DAT_0014f380,0x1000,"/usr/local/var/spool/cron",lVar6,0x2f);
    if (iVar1 != 0) {
      iVar1 = mkstemp(&DAT_0014f380);
      if (iVar1 == -1) {
        perror(&DAT_0014f380);
      }
      else {
        __stream = fdopen(iVar1,"w+");
        if (__stream != (FILE *)0x0) {
          signal(1,FUN_00104540);
          signal(2,FUN_00104540);
          signal(3,FUN_00104540);
          rewind(DAT_0014f338);
          if (((byte)DAT_0010e2c0 & 9) != 0) {
            __printf_chk(1,"linenum=%d\n",1);
          }
          DAT_0014e2fc = 1;
          while( true ) {
            iVar1 = FUN_00108570(DAT_0014f338);
            if (iVar1 == -1) break;
            putc(iVar1,__stream);
          }
          lVar6 = ftell(__stream);
          iVar1 = fileno(__stream);
          iVar1 = ftruncate(iVar1,lVar6);
          if (iVar1 == -1) {
LAB_00105519:
            iVar1 = -2;
            __fprintf_chk(stderr,1,"%s: error while writing new crontab to %s\n",DAT_0014e300,
                          &DAT_0014f380);
            fclose(__stream);
          }
          else {
            iVar1 = ferror(__stream);
            if (iVar1 != 0) goto LAB_00105519;
            iVar1 = fflush(__stream);
            if (iVar1 != 0) goto LAB_00105519;
            iVar1 = fileno(__stream);
            iVar1 = fsync(iVar1);
            if (iVar1 != 0) goto LAB_00105519;
            rewind(__stream);
            iVar1 = FUN_00104570(__stream);
            if (iVar1 < 0) {
              __fprintf_chk(stderr,1,"Invalid crontab file, can\'t install.\n");
              fclose(__stream);
            }
            else {
              _Var2 = getgid();
              _Var3 = geteuid();
              if (_Var2 == _Var3) {
                _Var2 = getgid();
                _Var5 = getegid();
                if (_Var2 != _Var5) goto LAB_001055f6;
                _Var3 = 0;
              }
              else {
LAB_001055f6:
                _Var3 = *(__uid_t *)(DAT_0014f320 + 0x10);
              }
              iVar4 = fileno(__stream);
              iVar4 = fchown(iVar4,_Var3,0xffffffff);
              if (iVar4 < 0) {
                iVar1 = -2;
                perror("fchown");
                fclose(__stream);
              }
              else {
                iVar4 = fclose(__stream);
                if (iVar4 == -1) {
                  iVar1 = -2;
                  perror("fclose");
                }
                else {
                  iVar4 = FUN_00108130(acStack_1048,0x1000,"/usr/local/var/spool/cron",&DAT_00151480
                                       ,0x2f);
                  if (iVar4 == 0) {
                    iVar1 = -2;
                    __fprintf_chk(stderr,1,"path too long\n");
                  }
                  else {
                    iVar4 = rename(&DAT_0014f380,acStack_1048);
                    if (iVar4 == 0) {
                      DAT_0014f380 = '\0';
                      FUN_00108720(&DAT_00151380,DAT_00151580,"REPLACE",&DAT_00151480,0);
                      FUN_00104330();
                    }
                    else {
                      iVar1 = -2;
                      __fprintf_chk(stderr,1,"%s: error renaming %s to %s\n",DAT_0014e300,
                                    &DAT_0014f380,acStack_1048);
                      perror("rename");
                    }
                  }
                }
              }
            }
          }
          signal(1,(__sighandler_t)0x0);
          signal(2,(__sighandler_t)0x0);
          signal(3,(__sighandler_t)0x0);
          if (DAT_0014f380 != '\0') {
            unlink(&DAT_0014f380);
            DAT_0014f380 = '\0';
          }
          goto LAB_00105580;
        }
        perror(&DAT_0014f380);
        close(iVar1);
        unlink(&DAT_0014f380);
      }
      DAT_0014f380 = '\0';
      iVar1 = -2;
      goto LAB_00105580;
    }
  }
  DAT_0014f380 = '\0';
  iVar1 = -2;
  __fprintf_chk(stderr,1,"path too long\n");
LAB_00105580:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: edit_cmd @ 0x5820

void edit_cmd(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  __gid_t __gid;
  __uid_t __uid;
  FILE *__stream;
  undefined8 uVar7;
  char *pcVar8;
  int *piVar9;
  char *pcVar10;
  undefined *puVar11;
  undefined1 *puVar12;
  ulong uVar13;
  undefined8 in_R10;
  long in_FS_OFFSET;
  undefined1 auStack_21030 [135168];
  
  puVar2 = &stack0xffffffffffffffd0;
  do {
    puVar12 = puVar2;
    *(undefined8 *)(puVar12 + -0x1000) = *(undefined8 *)(puVar12 + -0x1000);
    puVar2 = puVar12 + -0x1000;
  } while (puVar12 + -0x1000 != auStack_21030);
  *(undefined8 *)(puVar12 + 0x1fff0) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  pcVar8 = puVar12 + -0x1018;
  *(undefined8 *)(puVar12 + -0x10e0) = 0x10588b;
  FUN_00108720(&DAT_00151380,DAT_00151580,"BEGIN EDIT",&DAT_00151480,0);
  *(undefined8 *)(puVar12 + -0x10e0) = 0x1058a8;
  iVar3 = FUN_00108130(pcVar8,0x1000,"/usr/local/var/spool/cron",&DAT_00151480,0x2f);
  if (iVar3 != 0) {
    *(undefined8 *)(puVar12 + -0x10e0) = 0x1058c2;
    __stream = fopen(pcVar8,"r");
    if (__stream == (FILE *)0x0) {
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105ee2;
      piVar9 = __errno_location();
      if (*piVar9 != 2) {
LAB_00105c7f:
        *(undefined8 *)(puVar12 + -0x10e0) = 0x105c87;
        perror(pcVar8);
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar12 + -0x10e0) = 0x105c91;
        exit(1);
      }
      pcVar8 = "/dev/null";
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105f0f;
      __fprintf_chk(stderr,1,"no crontab for %s - using an empty one\n",&DAT_00151480);
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105f1a;
      __stream = fopen("/dev/null","r");
      if (__stream == (FILE *)0x0) goto LAB_00105c7f;
    }
    *(undefined8 *)(puVar12 + -0x10e0) = 0x1058e4;
    signal(1,(__sighandler_t)0x1);
    *(undefined8 *)(puVar12 + -0x10e0) = 0x1058f3;
    signal(2,(__sighandler_t)0x1);
    *(undefined8 *)(puVar12 + -0x10e0) = 0x105902;
    signal(3,(__sighandler_t)0x1);
    *(undefined8 *)(puVar12 + -0x10e0) = 0x105907;
    uVar7 = FUN_00104500();
    *(undefined8 *)(puVar12 + -0x10e0) = 0x105924;
    iVar3 = FUN_00108130(&DAT_00150380,0x1000,uVar7,"crontab.XXXXXX",0x2f);
    if (iVar3 != 0) {
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105931;
      iVar3 = FUN_00108d30();
      if (iVar3 == -1) goto LAB_00105ec7;
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105942;
      iVar3 = mkstemp(&DAT_00150380);
      if (iVar3 == -1) {
        *(undefined8 *)(puVar12 + -0x10e0) = 0x106080;
        perror(&DAT_00150380);
      }
      else {
        *(undefined8 *)(puVar12 + -0x10e0) = 0x105953;
        iVar4 = FUN_00108d80();
        if (iVar4 == -1) {
          *(undefined8 *)(puVar12 + -0x10e0) = 0x105fd1;
          perror("swapping uids back");
        }
        else {
          *(undefined8 *)(puVar12 + -0x10e0) = 0x10596e;
          DAT_0014f338 = fdopen(iVar3,"r+");
          if (DAT_0014f338 != (FILE *)0x0) {
            if (((byte)DAT_0010e2c0 & 9) != 0) {
              *(undefined8 *)(puVar12 + -0x10e0) = 0x105dd0;
              __printf_chk(1,"linenum=%d\n",1);
            }
            DAT_0014e2fc = 1;
            while( true ) {
              *(undefined8 *)(puVar12 + -0x10e0) = 0x1059b4;
              iVar3 = FUN_00108570(__stream);
              if (iVar3 == -1) break;
              *(undefined8 *)(puVar12 + -0x10e0) = 0x1059ac;
              putc(iVar3,DAT_0014f338);
            }
            *(undefined8 *)(puVar12 + -0x10e0) = 0x1059c3;
            fclose(__stream);
            *(undefined8 *)(puVar12 + -0x10e0) = 0x1059cf;
            iVar3 = fflush(DAT_0014f338);
            if (iVar3 < 0) {
              *(undefined8 *)(puVar12 + -0x10e0) = 0x105faa;
              perror(&DAT_00150380);
                    /* WARNING: Subroutine does not return */
              *(undefined8 *)(puVar12 + -0x10e0) = 0x105fb4;
              exit(1);
            }
            *(undefined8 *)(puVar12 + -0x10e0) = 0x1059dc;
            iVar3 = FUN_00108d30();
            if (iVar3 != -1) {
              *(undefined8 *)(puVar12 + -0x10b8) = 0;
              *(undefined8 *)(puVar12 + -0x10b0) = 0;
              *(undefined8 *)(puVar12 + -0x10e0) = 0x105a04;
              utime(&DAT_00150380,(utimbuf *)(puVar12 + -0x10b8));
              *(undefined8 *)(puVar12 + -0x10e0) = 0x105a09;
              iVar3 = FUN_00108d80();
              if (iVar3 != -1) {
LAB_00105a12:
                *(undefined8 *)(puVar12 + -0x10e0) = 0x105a1e;
                rewind(DAT_0014f338);
                *(undefined8 *)(puVar12 + -0x10e0) = 0x105a2a;
                iVar3 = ferror(DAT_0014f338);
                if (iVar3 == 0) {
                  *(undefined8 *)(puVar12 + -0x10e0) = 0x105a3e;
                  pcVar8 = getenv("VISUAL");
                  if ((pcVar8 == (char *)0x0) || (*pcVar8 == '\0')) {
                    *(undefined8 *)(puVar12 + -0x10e0) = 0x105bf3;
                    pcVar8 = getenv("EDITOR");
                    if ((pcVar8 == (char *)0x0) || (*pcVar8 == '\0')) {
                      pcVar8 = "/usr/bin/vi";
                    }
                  }
                  *(undefined8 *)(puVar12 + -0x10e0) = 0x105a58;
                  uVar5 = fork();
                  if (uVar5 == 0xffffffff) {
                    *(undefined8 *)(puVar12 + -0x10e0) = 0x105ec2;
                    perror("fork");
                    goto LAB_00105bd5;
                  }
                  if (uVar5 != 0) {
                    *(long *)(puVar12 + -0x10d0) = (long)(int)uVar5;
                    while( true ) {
                      uVar13 = (ulong)uVar5;
                      *(undefined8 *)(puVar12 + -0x10e0) = 0x105a9c;
                      uVar6 = waitpid(uVar5,(int *)(puVar12 + -0x10bc),0);
                      if (uVar6 != 0xffffffff) break;
                      *(undefined8 *)(puVar12 + -0x10e0) = 0x105a85;
                      piVar9 = __errno_location();
                      iVar3 = *piVar9;
                      if (iVar3 != 4) {
                        *(undefined8 *)(puVar12 + -0x10e0) = 0x105c96;
                        pcVar10 = strerror(iVar3);
                        *(undefined8 *)(puVar12 + -0x10e0) = in_R10;
                        *(char **)(puVar12 + -0x10e8) = pcVar10;
                        *(undefined8 *)(puVar12 + -0x10f0) = 0x105cc2;
                        __fprintf_chk(stderr,1,
                                      "%s: waitpid() failed waiting for PID %ld from \"%s\": %s\n",
                                      DAT_0014e300,*(undefined8 *)(puVar12 + -0x10d0),pcVar8);
                      }
                    }
                    if (uVar5 == uVar6) {
                      uVar5 = *(uint *)(puVar12 + -0x10bc);
                      if (((uVar5 & 0x7f) == 0) && ((char)(uVar5 >> 8) != '\0')) {
                        *(undefined8 *)(puVar12 + -0x10e0) = 0x105cfd;
                        __fprintf_chk(stderr,1,"%s: \"%s\" exited with status %d\n",DAT_0014e300,
                                      pcVar8,uVar5 >> 8 & 0xff);
                      }
                      else if ((uVar5 & 0x7f) == 0 || (char)(((byte)uVar5 & 0x7f) + 1) < '\x01') {
                        *(undefined8 *)(puVar12 + -0x10e0) = 0x105ad5;
                        signal(1,(__sighandler_t)0x0);
                        *(undefined8 *)(puVar12 + -0x10e0) = 0x105ae1;
                        signal(2,(__sighandler_t)0x0);
                        *(undefined8 *)(puVar12 + -0x10e0) = 0x105aed;
                        signal(3,(__sighandler_t)0x0);
                        *(undefined8 *)(puVar12 + -0x10e0) = 0x105afa;
                        iVar3 = lstat(&DAT_00150380,(stat *)(puVar12 + -0x10a8));
                        if (iVar3 < 0) {
                          *(undefined8 *)(puVar12 + -0x10e0) = 0x106073;
                          perror("lstat");
                        }
                        else {
                          if ((*(uint *)(puVar12 + -0x1090) & 0xf000) != 0x8000) {
                            *(undefined8 *)(puVar12 + -0x10e0) = 0x105dae;
                            __fprintf_chk(stderr,1,"%s: illegal crontab\n",DAT_0014e300);
                            goto LAB_00105dae;
                          }
                          if (*(long *)(puVar12 + -0x1050) == 0) {
                            *(undefined8 *)(puVar12 + -0x10e0) = 0x105e7e;
                            __fprintf_chk(stderr,1,"%s: no changes made to crontab\n",DAT_0014e300);
                            goto LAB_00105dae;
                          }
                          *(undefined8 *)(puVar12 + -0x10e0) = 0x105b46;
                          __fprintf_chk(stderr,1,"%s: installing new crontab\n",DAT_0014e300);
                          *(undefined8 *)(puVar12 + -0x10e0) = 0x105b52;
                          fclose(DAT_0014f338);
                          *(undefined8 *)(puVar12 + -0x10e0) = 0x105b57;
                          iVar3 = FUN_00108d30();
                          if (iVar3 < 0) {
                            *(undefined8 *)(puVar12 + -0x10e0) = 0x105e8f;
                            perror("swapping uids");
                            goto LAB_00105dae;
                          }
                          *(undefined8 *)(puVar12 + -0x10e0) = 0x105b6a;
                          DAT_0014f338 = fopen(&DAT_00150380,"r+");
                          if (DAT_0014f338 == (FILE *)0x0) {
                            *(undefined8 *)(puVar12 + -0x10e0) = 0x105fe2;
                            perror("cannot read new crontab");
                            goto LAB_00105dae;
                          }
                          *(undefined8 *)(puVar12 + -0x10e0) = 0x105b7f;
                          iVar3 = FUN_00108d80();
                          if (iVar3 < 0) {
                            *(undefined8 *)(puVar12 + -0x10e0) = 0x10605d;
                            perror("swapping uids back");
                    /* WARNING: Subroutine does not return */
                            *(undefined8 *)(puVar12 + -0x10e0) = 0x106067;
                            exit(1);
                          }
                          if (DAT_0014f338 != (FILE *)0x0) goto code_r0x00105b95;
                          *(undefined8 *)(puVar12 + -0x10e0) = 0x10604c;
                          perror("fopen");
                        }
                      }
                      else {
                        puVar11 = &DAT_0010af70;
                        if ((uVar5 & 0x80) == 0) {
                          puVar11 = &DAT_0010a330;
                        }
                        *(undefined **)(puVar12 + -0x10e0) = &DAT_0010a330;
                        *(undefined **)(puVar12 + -0x10e8) = puVar11;
                        *(undefined8 *)(puVar12 + -0x10f0) = 0x105f9b;
                        __fprintf_chk(stderr,1,"%s: \"%s\" killed; signal %d (%score dumped)\n",
                                      DAT_0014e300,pcVar8,uVar5 & 0x7f);
                      }
                    }
                    else {
                      *(ulong *)(puVar12 + -0x10e0) = uVar13;
                      *(char **)(puVar12 + -0x10e8) = pcVar8;
                      *(undefined8 *)(puVar12 + -0x10f0) = 0x105f55;
                      __fprintf_chk(stderr,1,"%s: wrong PID (%ld != %ld) from \"%s\"\n",DAT_0014e300
                                    ,(long)(int)uVar6,(long)(int)uVar5);
                    }
                    goto LAB_00105bd5;
                  }
                  *(undefined8 *)(puVar12 + -0x10e0) = 0x105c15;
                  __gid = getgid();
                  *(undefined8 *)(puVar12 + -0x10e0) = 0x105c1c;
                  iVar3 = setgid(__gid);
                  if (iVar3 < 0) {
                    *(undefined8 *)(puVar12 + -0x10e0) = 0x106036;
                    perror("setgid(getgid())");
                    /* WARNING: Subroutine does not return */
                    *(undefined8 *)(puVar12 + -0x10e0) = 0x106040;
                    exit(1);
                  }
                  *(undefined8 *)(puVar12 + -0x10e0) = 0x105c29;
                  __uid = getuid();
                  *(undefined8 *)(puVar12 + -0x10e0) = 0x105c30;
                  iVar3 = setuid(__uid);
                  if (iVar3 < 0) {
                    *(undefined8 *)(puVar12 + -0x10e0) = 0x106020;
                    perror("setuid(getuid())");
                    /* WARNING: Subroutine does not return */
                    *(undefined8 *)(puVar12 + -0x10e0) = 0x10602a;
                    exit(1);
                  }
                  *(undefined8 *)(puVar12 + -0x10e0) = 0x105c59;
                  iVar3 = FUN_00108130(puVar12 + -0x18,0x20000,pcVar8,&DAT_00150380,0x20);
                  if (iVar3 == 0) {
                    *(undefined8 *)(puVar12 + -0x10e0) = 0x105d21;
                    __fprintf_chk(stderr,1,"%s: editor command line too long\n",DAT_0014e300);
                    /* WARNING: Subroutine does not return */
                    *(undefined8 *)(puVar12 + -0x10e0) = 0x105d2b;
                    exit(1);
                  }
                  *(undefined8 *)(puVar12 + -0x10e0) = 0x105c7f;
                  execlp("/bin/sh","/bin/sh",&DAT_0010a397,puVar12 + -0x18,0);
                  goto LAB_00105c7f;
                }
                *(undefined8 *)(puVar12 + -0x10e0) = 0x10600f;
                __fprintf_chk(stderr,1,"%s: error while writing new crontab to %s\n",DAT_0014e300,
                              &DAT_00150380);
                goto LAB_00105bd5;
              }
            }
LAB_00105ec7:
            *(undefined8 *)(puVar12 + -0x10e0) = 0x105ed3;
            perror("swapping uids");
                    /* WARNING: Subroutine does not return */
            *(undefined8 *)(puVar12 + -0x10e0) = 0x105edd;
            exit(1);
          }
          *(undefined8 *)(puVar12 + -0x10e0) = 0x105fc0;
          perror("fdopen");
        }
      }
LAB_00105bd5:
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105bdd;
      unlink(&DAT_00150380);
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105be7;
      exit(1);
    }
  }
  *(undefined8 *)(puVar12 + -0x10e0) = 0x105eac;
  __fprintf_chk(stderr,1,"path too long\n");
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar12 + -0x10e0) = 0x105eb6;
  exit(1);
code_r0x00105b95:
  *(undefined8 *)(puVar12 + -0x10e0) = 0x105b9a;
  iVar3 = FUN_001053d0();
  if (iVar3 == -1) {
LAB_00105deb:
    do {
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105dfa;
      __printf_chk(1,"Do you want to retry the same edit? (Y/N) ");
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105e06;
      fflush(stdout);
      puVar12[-0x18] = 0;
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105e22;
      pcVar8 = fgets(puVar12 + -0x18,0x20000,stdin);
    } while (pcVar8 == (char *)0x0);
    cVar1 = puVar12[-0x18];
    if (cVar1 == 'n') goto LAB_00105d2b;
    if (cVar1 < 'o') {
      if (cVar1 == 'N') goto LAB_00105d2b;
      if (cVar1 == 'Y') goto LAB_00105a12;
    }
    else if (cVar1 == 'y') goto LAB_00105a12;
    *(undefined8 *)(puVar12 + -0x10e0) = 0x105e69;
    __fprintf_chk(stderr,1,"Enter Y or N\n");
    goto LAB_00105deb;
  }
  if (iVar3 == 0) {
LAB_00105dae:
    *(undefined8 *)(puVar12 + -0x10e0) = 0x105db6;
    unlink(&DAT_00150380);
  }
  else {
    if (iVar3 != -2) {
      *(undefined8 *)(puVar12 + -0x10e0) = 0x105bd5;
      __fprintf_chk(stderr,1,"%s: panic: bad switch() in replace_cmd()\n",DAT_0014e300);
      goto LAB_00105bd5;
    }
LAB_00105d2b:
    *(undefined8 *)(puVar12 + -0x10e0) = 0x105d53;
    __fprintf_chk(stderr,1,"%s: edits left in %s\n",DAT_0014e300,&DAT_00150380);
  }
  *(undefined8 *)(puVar12 + -0x10e0) = 0x105d72;
  FUN_00108720(&DAT_00151380,DAT_00151580,"END EDIT",&DAT_00151480,0);
  if (*(long *)(puVar12 + 0x1fff0) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar12 + -0x10e0) = &UNK_0010608a;
    __stack_chk_fail();
  }
  return;
}



// Function: build_env @ 0x6090

long build_env(void)

{
  __pid_t _Var1;
  long lVar2;
  
  lVar2 = FUN_00107870();
  if (lVar2 != 0) {
    return lVar2;
  }
  _Var1 = getpid();
  FUN_00108720(&DAT_0010aea4,_Var1,"ERROR","Initialization of cron environment variables failed",0);
  return 0;
}



// Function: cron_restore_default_security_context @ 0x61c0

void cron_restore_default_security_context(void)

{
  return;
}



// Function: cron_change_groups @ 0x61e0

undefined4 cron_change_groups(undefined8 *param_1)

{
  __pid_t _Var1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  
  _Var1 = getpid();
  iVar2 = setgid(*(__gid_t *)((long)param_1 + 0x14));
  if (iVar2 == 0) {
    iVar2 = initgroups((char *)*param_1,*(__gid_t *)((long)param_1 + 0x14));
    if (iVar2 == 0) {
      return 0;
    }
    piVar3 = __errno_location();
    pcVar4 = "initgroups failed";
    iVar2 = *piVar3;
  }
  else {
    piVar3 = __errno_location();
    pcVar4 = "setgid failed";
    iVar2 = *piVar3;
  }
  FUN_00108720(&DAT_0010aea4,_Var1,"ERROR",pcVar4,iVar2);
  return 0xffffffff;
}



// Function: cron_set_job_security_context @ 0x6260

undefined4 cron_set_job_security_context(long param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  __pid_t _Var2;
  undefined8 uVar3;
  undefined4 uVar4;
  long in_FS_OFFSET;
  time_t local_1b8;
  time_t local_1b0;
  tm local_1a8;
  tm local_168;
  undefined1 local_128 [264];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_1b8 = 0;
  if ((*(byte *)(param_1 + 0x34) & 1) != 0) {
    local_1b8 = time((time_t *)0x0);
    if (((byte)DAT_0010e2c0 & 2) != 0) {
      __printf_chk(1,"Minute-ly job. Recording time %lld\n",local_1b8);
    }
  }
  iVar1 = FUN_001061e0(*(undefined8 *)(param_1 + 8));
  if (iVar1 == 0) {
    uVar3 = FUN_00106090();
    *param_3 = uVar3;
    local_1b0 = time((time_t *)0x0);
    uVar4 = 0;
    if ((0 < local_1b8) && (local_1b0 / 0x3c != local_1b8 / 0x3c)) {
      localtime_r(&local_1b0,&local_168);
      localtime_r(&local_1b8,&local_1a8);
      __snprintf_chk(local_128,0x100,1,0x100,
                     "Job execution of per-minute job scheduled for %.2u:%.2u delayed into subsequent minute %.2u:%.2u. Skipping job run."
                     ,local_1a8.tm_hour,local_1a8.tm_min,local_168.tm_hour,local_168.tm_min);
      _Var2 = getpid();
      uVar4 = 0xffffffff;
      FUN_00108720(**(undefined8 **)(param_1 + 8),_Var2,&DAT_0010aec9,local_128,0);
    }
  }
  else {
    uVar4 = 0xffffffff;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: cron_change_user_permanently @ 0x6400

undefined4 cron_change_user_permanently(long param_1,char *param_2)

{
  int iVar1;
  __pid_t _Var2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar1 = setreuid(*(__uid_t *)(param_1 + 0x10),*(__uid_t *)(param_1 + 0x10));
  if (iVar1 == 0) {
    iVar1 = chdir(param_2);
    if (iVar1 == -1) {
      piVar3 = __errno_location();
      iVar1 = *piVar3;
      _Var2 = getpid();
      uVar4 = 0xffffffff;
      FUN_00108720(&DAT_0010aea4,_Var2,"ERROR chdir failed",param_2,iVar1);
    }
    else {
      FUN_00108be0();
      uVar4 = 0;
    }
  }
  else {
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    _Var2 = getpid();
    uVar4 = 0xffffffff;
    FUN_00108720(&DAT_0010aea4,_Var2,"ERROR","setreuid failed",iVar1);
  }
  return uVar4;
}



// Function: allowed @ 0x64b0

uint allowed(undefined8 param_1,char *param_2,char *param_3)

{
  __uid_t _Var1;
  uint uVar2;
  __pid_t _Var3;
  int iVar4;
  FILE *pFVar5;
  char *pcVar6;
  long in_FS_OFFSET;
  undefined1 auStack_b8 [136];
  long local_30;
  
  uVar2 = 1;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  _Var1 = getuid();
  if (_Var1 == 0) goto LAB_001064ec;
  pFVar5 = fopen(param_2,"r");
  if (pFVar5 == (FILE *)0x0) {
    pFVar5 = fopen(param_3,"r");
    if (pFVar5 == (FILE *)0x0) {
      uVar2 = 0;
      goto LAB_001064ec;
    }
    iVar4 = FUN_001060e0(param_1,pFVar5);
    uVar2 = (uint)(iVar4 == 0);
    fclose(pFVar5);
    _Var1 = getuid();
    if ((iVar4 == 0) || (_Var1 != 0)) goto LAB_001064ec;
    pcVar6 = "root used -u for user %s in cron.deny";
  }
  else {
    uVar2 = FUN_001060e0(param_1,pFVar5);
    fclose(pFVar5);
    _Var1 = getuid();
    if (_Var1 != 0 || uVar2 != 0) goto LAB_001064ec;
    pcVar6 = "root used -u for user %s not in cron.allow";
  }
  __snprintf_chk(auStack_b8,0x80,1,0x80,pcVar6,param_1);
  _Var3 = getpid();
  uVar2 = 1;
  FUN_00108720("crontab",_Var3,"warning",auStack_b8,0);
LAB_001064ec:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: is_separator @ 0x6620

uint is_separator(uint param_1)

{
  if (param_1 < 0x2d) {
    return (uint)(0x100100000600 >> ((byte)param_1 & 0x3f)) & 1;
  }
  return 0;
}



// Function: set_element @ 0x6650

undefined8 set_element(long param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  undefined8 uVar2;
  
  if (((byte)DAT_0010e2c0 & 9) != 0) {
    __printf_chk(1,"set_element(?,%d,%d,%d)\n",param_2,param_3,param_4);
  }
  if ((param_4 < param_2) || (param_3 < param_4)) {
    uVar2 = 0xffffffff;
  }
  else {
    pbVar1 = (byte *)(param_1 + (param_4 - param_2 >> 3));
    *pbVar1 = *pbVar1 | (byte)(1 << ((byte)(param_4 - param_2) & 7));
    uVar2 = 0;
  }
  return uVar2;
}



// Function: get_number @ 0x66d0

undefined4 get_number(undefined8 param_1,undefined4 param_2,long *param_3,undefined8 param_4)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ushort **ppuVar6;
  long lVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  long lVar10;
  long in_FS_OFFSET;
  undefined1 auStack_20030 [131072];
  
  puVar9 = &stack0xffffffffffffffd0;
  do {
    puVar8 = puVar9;
    *(undefined8 *)(puVar8 + -0x1000) = *(undefined8 *)(puVar8 + -0x1000);
    puVar9 = puVar8 + -0x1000;
  } while (puVar8 + -0x1000 != auStack_20030);
  iVar4 = 0;
  *(undefined8 *)(puVar8 + -0x1038) = param_1;
  *(undefined4 *)(puVar8 + -0x102c) = param_2;
  *(undefined8 *)(puVar8 + 0x1eff0) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(puVar8 + -0x1060) = 0x106720;
  ppuVar6 = __ctype_b_loc();
  *(ushort ***)(puVar8 + -0x1050) = ppuVar6;
  puVar9 = puVar8 + -0x1018;
  *(undefined1 **)(puVar8 + -0x1040) = puVar9;
  *(undefined1 **)(puVar8 + -0x1048) = puVar8 + 0x1efe7;
  while( true ) {
    lVar7 = **(long **)(puVar8 + -0x1050);
    *(undefined8 *)(puVar8 + -0x1060) = 0x10676e;
    iVar3 = FUN_00108570(param_4);
    if ((*(byte *)(lVar7 + (long)iVar3 * 2) & 8) == 0) break;
    iVar4 = iVar4 + 1;
    if (puVar9 == *(undefined1 **)(puVar8 + -0x1048)) goto LAB_00106828;
    *puVar9 = (char)iVar3;
    puVar9 = puVar9 + 1;
  }
  *puVar9 = 0;
  if (iVar4 != 0) {
    *(undefined8 *)(puVar8 + -0x1060) = 0x106792;
    FUN_001085d0(iVar3,param_4);
    pcVar1 = *(char **)(puVar8 + -0x1040);
    *(undefined8 *)(puVar8 + -0x1060) = 0x1067a9;
    lVar7 = strtol(pcVar1,(char **)(puVar8 + -0x1020),10);
    pcVar2 = *(char **)(puVar8 + -0x1020);
    **(undefined4 **)(puVar8 + -0x1038) = (int)lVar7;
    if ((*pcVar2 == '\0') && (uVar5 = 0, pcVar2 != pcVar1)) goto LAB_00106838;
    if ((param_3 != (long *)0x0) && (lVar7 = *param_3, lVar7 != 0)) {
      lVar10 = 0;
      do {
        if (((byte)DAT_0010e2c0 & 9) != 0) {
          *(undefined8 *)(puVar8 + -0x1060) = 0x10681f;
          __printf_chk(1,"get_num, compare(%s,%s)\n",lVar7,*(undefined8 *)(puVar8 + -0x1040));
        }
        pcVar1 = (char *)param_3[lVar10];
        *(undefined8 *)(puVar8 + -0x1060) = 0x1067ee;
        iVar4 = strcasecmp(pcVar1,*(char **)(puVar8 + -0x1040));
        if (iVar4 == 0) {
          **(int **)(puVar8 + -0x1038) = *(int *)(puVar8 + -0x102c) + (int)lVar10;
          uVar5 = 0;
          goto LAB_00106838;
        }
        lVar10 = lVar10 + 1;
        lVar7 = param_3[lVar10];
      } while (lVar7 != 0);
    }
  }
LAB_00106828:
  *(undefined8 *)(puVar8 + -0x1060) = 0x106833;
  FUN_001085d0(iVar3,param_4);
  uVar5 = 0xffffffff;
LAB_00106838:
  if (*(long *)(puVar8 + 0x1eff0) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar8 + -0x1060) = &UNK_00106874;
  __stack_chk_fail();
}



// Function: get_range @ 0x6880

int get_range(undefined8 param_1,int param_2,int param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  int local_5c;
  int local_4c;
  int local_48;
  int local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_44 = 1;
  iVar1 = FUN_00108570(param_5);
  if (iVar1 != -1) {
    if (iVar1 == 0x2a) {
      local_4c = param_2;
      local_48 = param_3;
      iVar1 = FUN_00108570(param_5);
      if (iVar1 != -1) {
        if (iVar1 == 0x2f) {
LAB_001069b2:
          iVar1 = FUN_00108570(param_5);
          if (iVar1 != -1) {
            FUN_001085d0(iVar1,param_5);
            iVar1 = FUN_001066d0(&local_44,0,0,param_5);
            if (((iVar1 != -1) && (local_44 != 0)) && (iVar1 = FUN_00108570(param_5), iVar1 != -1))
            {
LAB_00106a03:
              iVar2 = FUN_00106620(iVar1);
              if (iVar2 != 0) {
                local_5c = local_48;
                iVar2 = local_4c;
                if (local_48 < local_4c) goto LAB_00106962;
                goto LAB_0010693c;
              }
            }
          }
        }
        else {
          iVar3 = FUN_00106620(iVar1);
          iVar2 = param_2;
          local_5c = param_3;
joined_r0x00106b93:
          if (iVar3 != 0) {
LAB_0010693c:
            do {
              iVar3 = FUN_00106650(param_1,param_2,param_3,iVar2);
              if (iVar3 == -1) {
                FUN_001085d0(iVar1,param_5);
                goto LAB_0010695c;
              }
              iVar2 = iVar2 + local_44;
            } while (iVar2 <= local_5c);
            goto LAB_00106962;
          }
        }
      }
    }
    else {
      iVar2 = param_2;
      if (iVar1 == 0x7e) {
LAB_001068dc:
        local_4c = iVar2;
        iVar1 = FUN_00108570(param_5);
        if (iVar1 != -1) {
          iVar2 = FUN_00106620(iVar1);
          local_5c = local_4c;
          if (iVar2 == 0) {
            FUN_001085d0();
            iVar1 = FUN_001066d0(&local_48,param_2,param_4,param_5);
            iVar2 = local_4c;
            if ((iVar1 != -1) && (local_4c <= local_48)) {
              lVar4 = random();
              iVar2 = iVar2 + (int)(lVar4 % (long)((local_48 - iVar2) + 1));
              local_4c = iVar2;
              local_48 = iVar2;
              iVar1 = FUN_00108570(param_5);
              if (iVar1 != -1) {
                iVar3 = FUN_00106620(iVar1);
                local_5c = iVar2;
                goto joined_r0x00106b93;
              }
            }
          }
          else {
            local_48 = param_3;
            if (local_4c <= param_3) {
              lVar4 = random();
              local_5c = local_5c + (int)(lVar4 % (long)((param_3 - local_5c) + 1));
              iVar2 = local_5c;
              goto LAB_0010693c;
            }
          }
        }
      }
      else {
        FUN_001085d0(iVar1,param_5);
        iVar1 = FUN_001066d0(&local_4c,param_2,param_4,param_5);
        if ((iVar1 != -1) && (iVar1 = FUN_00108570(param_5), iVar1 != -1)) {
          if (iVar1 == 0x2d) {
            iVar1 = FUN_00108570(param_5);
            if (iVar1 != -1) {
              FUN_001085d0(iVar1,param_5);
              iVar1 = FUN_001066d0(&local_48,param_2,param_4,param_5);
              if ((iVar1 != -1) && (iVar1 = FUN_00108570(param_5), iVar1 != -1)) {
                if (iVar1 == 0x2f) goto LAB_001069b2;
                goto LAB_00106a03;
              }
            }
          }
          else {
            iVar2 = local_4c;
            if (iVar1 == 0x7e) goto LAB_001068dc;
            iVar2 = FUN_00106620(iVar1);
            if (iVar2 != 0) {
              local_5c = local_4c;
              iVar2 = local_4c;
              goto LAB_0010693c;
            }
          }
        }
      }
    }
  }
LAB_0010695c:
  iVar1 = -1;
LAB_00106962:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: get_list @ 0x6bb0

int get_list(byte *param_1,int param_2,int param_3,undefined8 param_4,undefined4 param_5,
                undefined8 param_6)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  if (((byte)DAT_0010e2c0 & 9) != 0) {
    __printf_chk(1,"get_list()...entered\n");
  }
  iVar3 = param_3 - param_2 >> 3;
  bVar1 = (byte)(param_3 - param_2);
  if (iVar3 == 0) {
    *param_1 = *param_1 & (byte)(0xff << (bVar1 + 1 & 0x1f));
  }
  else {
    *param_1 = 0;
    if (iVar3 != 1) {
      pbVar2 = param_1 + 1;
      do {
        *pbVar2 = 0;
        pbVar2 = pbVar2 + 1;
      } while (param_1 + (ulong)(iVar3 - 2) + 2 != pbVar2);
    }
    param_1[iVar3] = param_1[iVar3] & (byte)(0xff << (bVar1 & 7) + 1);
  }
  FUN_001085d0(param_5,param_6);
  do {
    iVar3 = FUN_00106880(param_1,param_2,param_3,param_4,param_6);
    if (iVar3 == -1) {
      return -1;
    }
  } while (iVar3 == 0x2c);
  if (iVar3 == 9) {
LAB_00106c5f:
    if ((iVar3 != 0x20) && (iVar3 != 9)) goto LAB_00106c85;
  }
  else if (iVar3 != 0x20) {
    if (iVar3 != 10) {
      do {
        iVar3 = FUN_00108570(param_6);
        if (iVar3 == 9) goto LAB_00106c5f;
        if (iVar3 == 0x20) goto LAB_00106c70;
      } while ((iVar3 != 10) && (iVar3 != -1));
    }
    goto LAB_00106c85;
  }
LAB_00106c70:
  do {
    do {
      iVar3 = FUN_00108570(param_6);
    } while (iVar3 == 9);
  } while (iVar3 == 0x20);
LAB_00106c85:
  if (((byte)DAT_0010e2c0 & 9) != 0) {
    __printf_chk(1,"get_list()...exiting w/ %02x\n",iVar3);
  }
  return iVar3;
}



// Function: free_entry @ 0x6d20

void free_entry(void *param_1)

{
  free(*(void **)((long)param_1 + 0x18));
  free(*(void **)((long)param_1 + 8));
  FUN_00107830(*(undefined8 *)((long)param_1 + 0x10));
  free(param_1);
  return;
}



// Function: load_entry @ 0x6d50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * load_entry(FILE *param_1,code *param_2,passwd *param_3,undefined8 param_4)

{
  byte bVar1;
  __gid_t _Var2;
  __uid_t _Var3;
  undefined8 uVar4;
  void *pvVar5;
  undefined *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  __pid_t _Var10;
  void *__ptr;
  size_t __n;
  char *pcVar11;
  int *piVar12;
  ulong uVar13;
  undefined1 *puVar14;
  long lVar15;
  undefined1 *puVar16;
  long in_FS_OFFSET;
  undefined1 auStack_40030 [262144];
  
  puVar16 = &stack0xffffffffffffffd0;
  do {
    puVar14 = puVar16;
    *(undefined8 *)(puVar14 + -0x1000) = *(undefined8 *)(puVar14 + -0x1000);
    puVar16 = puVar14 + -0x1000;
  } while (puVar14 + -0x1000 != auStack_40030);
  *(undefined8 *)(puVar14 + -0x1068) = param_4;
  *(undefined8 *)(puVar14 + 0x3eff0) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  if (((byte)DAT_0010e2c0 & 8) != 0) {
    *(undefined8 *)(puVar14 + -0x1070) = 0x1071c1;
    __printf_chk(1,"load_entry()...about to eat comments\n");
  }
  *(undefined8 *)(puVar14 + -0x1070) = 0x106db0;
  uVar7 = FUN_00108570(param_1);
  if (uVar7 != 0xffffffff) {
    *(undefined8 *)(puVar14 + -0x1070) = 0x106dca;
    __ptr = calloc(0x40,1);
    if (__ptr == (void *)0x0) {
      lVar15 = 10;
    }
    else {
      if (uVar7 == 0x2d) {
        if ((param_3 == (passwd *)0x0) || (param_3->pw_uid == 0)) {
          *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 0x20;
          *(undefined8 *)(puVar14 + -0x1070) = 0x10712f;
          uVar7 = FUN_00108570(param_1);
          if (uVar7 == 0xffffffff) {
            *(undefined8 *)(puVar14 + -0x1070) = 0x107142;
            free(__ptr);
            goto LAB_00107148;
          }
          goto LAB_00106ddf;
        }
        *(undefined8 *)(puVar14 + -0x1070) = 0x10745a;
        _Var10 = getpid();
        lVar15 = 9;
        *(undefined8 *)(puVar14 + -0x1070) = 0x10747f;
        FUN_00108720(&DAT_0010aea4,_Var10,"ERROR","Only privileged user can disable logging",0);
        goto LAB_001071e0;
      }
LAB_00106ddf:
      if (uVar7 == 0x40) {
        pcVar11 = puVar14 + -0x1018;
        *(undefined8 *)(puVar14 + -0x1070) = 0x10729c;
        uVar7 = FUN_00108620(pcVar11,0x20000,param_1,&DAT_0010af6d);
        *(undefined8 *)(puVar14 + -0x1070) = 0x1072ad;
        iVar8 = strcmp("reboot",pcVar11);
        if (iVar8 == 0) {
          *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 0x10;
          goto LAB_001072b6;
        }
        *(undefined8 *)(puVar14 + -0x1070) = 0x10731f;
        iVar8 = strcmp("yearly",pcVar11);
        if (iVar8 == 0) {
LAB_00107375:
          *(byte *)((long)__ptr + 0x20) = *(byte *)((long)__ptr + 0x20) | 1;
          *(byte *)((long)__ptr + 0x28) = *(byte *)((long)__ptr + 0x28) | 1;
          *(byte *)((long)__ptr + 0x2b) = *(byte *)((long)__ptr + 0x2b) | 1;
          *(byte *)((long)__ptr + 0x2f) = *(byte *)((long)__ptr + 0x2f) | 1;
          *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 8;
          *(undefined1 *)((long)__ptr + 0x31) = 0xff;
        }
        else {
          *(undefined8 *)(puVar14 + -0x1070) = 0x107332;
          iVar8 = strcmp("annually",pcVar11);
          if (iVar8 == 0) goto LAB_00107375;
          *(undefined8 *)(puVar14 + -0x1070) = 0x107345;
          iVar8 = strcmp("monthly",pcVar11);
          if (iVar8 == 0) {
            *(byte *)((long)__ptr + 0x20) = *(byte *)((long)__ptr + 0x20) | 1;
            *(byte *)((long)__ptr + 0x28) = *(byte *)((long)__ptr + 0x28) | 1;
            *(byte *)((long)__ptr + 0x2b) = *(byte *)((long)__ptr + 0x2b) | 1;
            *(byte *)((long)__ptr + 0x30) = *(byte *)((long)__ptr + 0x30) | 0xf;
            *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 8;
            *(undefined1 *)((long)__ptr + 0x2f) = 0xff;
            *(undefined1 *)((long)__ptr + 0x31) = 0xff;
          }
          else {
            *(undefined8 *)(puVar14 + -0x1070) = 0x10760a;
            iVar8 = strcmp("weekly",pcVar11);
            if (iVar8 == 0) {
              *(byte *)((long)__ptr + 0x20) = *(byte *)((long)__ptr + 0x20) | 1;
              *(byte *)((long)__ptr + 0x28) = *(byte *)((long)__ptr + 0x28) | 1;
              *(byte *)((long)__ptr + 0x2e) = *(byte *)((long)__ptr + 0x2e) | 0x7f;
              *(ushort *)((long)__ptr + 0x30) = *(ushort *)((long)__ptr + 0x30) | 0x10f;
              *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 4;
              *(undefined2 *)((long)__ptr + 0x2b) = 0xffff;
              *(undefined1 *)((long)__ptr + 0x2d) = 0xff;
              *(undefined1 *)((long)__ptr + 0x2f) = 0xff;
            }
            else {
              *(undefined8 *)(puVar14 + -0x1070) = 0x107713;
              iVar8 = strcmp("daily",pcVar11);
              if (iVar8 != 0) {
                *(undefined8 *)(puVar14 + -0x1070) = 0x107726;
                iVar8 = strcmp("midnight",pcVar11);
                if (iVar8 != 0) {
                  *(undefined8 *)(puVar14 + -0x1070) = 0x107739;
                  iVar8 = strcmp("hourly",pcVar11);
                  if (iVar8 != 0) {
                    lVar15 = 7;
                    goto LAB_001071e0;
                  }
                  *(byte *)((long)__ptr + 0x20) = *(byte *)((long)__ptr + 0x20) | 1;
                  *(byte *)((long)__ptr + 0x2e) = *(byte *)((long)__ptr + 0x2e) | 0x7f;
                  *(byte *)((long)__ptr + 0x30) = *(byte *)((long)__ptr + 0x30) | 0xf;
                  *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 2;
                  *(undefined4 *)((long)__ptr + 0x28) = 0xffffffff;
                  *(undefined2 *)((long)__ptr + 0x2c) = 0xffff;
                  *(undefined1 *)((long)__ptr + 0x2f) = 0xff;
                  *(undefined1 *)((long)__ptr + 0x31) = 0xff;
                  goto LAB_001072b6;
                }
              }
              *(byte *)((long)__ptr + 0x20) = *(byte *)((long)__ptr + 0x20) | 1;
              *(byte *)((long)__ptr + 0x28) = *(byte *)((long)__ptr + 0x28) | 1;
              *(byte *)((long)__ptr + 0x2e) = *(byte *)((long)__ptr + 0x2e) | 0x7f;
              *(byte *)((long)__ptr + 0x30) = *(byte *)((long)__ptr + 0x30) | 0xf;
              *(undefined2 *)((long)__ptr + 0x2b) = 0xffff;
              *(undefined1 *)((long)__ptr + 0x2d) = 0xff;
              *(undefined1 *)((long)__ptr + 0x2f) = 0xff;
              *(undefined1 *)((long)__ptr + 0x31) = 0xff;
            }
          }
        }
LAB_001072b6:
        if ((uVar7 == 0x20) || (uVar7 == 9)) {
          do {
            do {
              *(undefined8 *)(puVar14 + -0x1070) = 0x1072c8;
              uVar7 = FUN_00108570(param_1);
            } while (uVar7 == 9);
          } while (uVar7 == 0x20);
        }
        if ((uVar7 == 0xffffffff) || (uVar7 == 10)) goto LAB_001072e2;
LAB_00106edb:
        bVar1 = *(byte *)((long)__ptr + 0x31);
        if (((bVar1 & 1) != 0) || ((char)bVar1 < '\0')) {
          *(byte *)((long)__ptr + 0x31) = bVar1 | 0x81;
        }
        lVar15 = 6;
        if ((uVar7 & 0xffffffdf) == 10) goto LAB_001071e0;
        *(undefined8 *)(puVar14 + -0x1070) = 0x106f0e;
        FUN_001085d0(uVar7);
        if (param_3 == (passwd *)0x0) {
          if (((byte)DAT_0010e2c0 & 8) != 0) {
            *(undefined8 *)(puVar14 + -0x1070) = 0x1074b2;
            __printf_chk(1,"load_entry()...about to parse username\n");
          }
          pcVar11 = puVar14 + -0x1018;
          *(undefined8 *)(puVar14 + -0x1070) = 0x1073c1;
          uVar7 = FUN_00108620(pcVar11,0x20000,param_1,&DAT_0010af6d);
          if (((byte)DAT_0010e2c0 & 8) != 0) {
            *(undefined8 *)(puVar14 + -0x1070) = 0x10749a;
            __printf_chk(1,"load_entry()...got %s\n",pcVar11);
          }
          if (((uVar7 != 0xffffffff) && (uVar7 != 10)) && (uVar7 != 0x2a)) {
            *(undefined8 *)(puVar14 + -0x1070) = 0x1073f3;
            param_3 = getpwnam(pcVar11);
            if (param_3 == (passwd *)0x0) {
              if (((byte)DAT_0010e2c0 & 8) != 0) {
                *(undefined8 *)(puVar14 + -0x1070) = 0x1077d8;
                __printf_chk(1,"load_entry()...unknown user entry\n");
              }
              *(char **)(puVar14 + -0x1048) = pcVar11;
              param_3 = (passwd *)(puVar14 + -0x1048);
              *(undefined **)(puVar14 + -0x1040) = &DAT_0010af70;
              *(undefined1 (*) [16])(puVar14 + -0x1038) = (undefined1  [16])0x0;
              *(undefined1 (*) [16])(puVar14 + -0x1028) = (undefined1  [16])0x0;
            }
            else if (((byte)DAT_0010e2c0 & 8) != 0) {
              _Var2 = param_3->pw_gid;
              _Var3 = param_3->pw_uid;
              *(undefined8 *)(puVar14 + -0x1070) = 0x1076ff;
              __printf_chk(1,"load_entry()...uid %ld, gid %ld\n",_Var3,_Var2);
            }
            if ((uVar7 == 0x20) || (uVar7 == 9)) {
              do {
                do {
                  *(undefined8 *)(puVar14 + -0x1070) = 0x107428;
                  uVar7 = FUN_00108570(param_1);
                } while (uVar7 == 9);
              } while (uVar7 == 0x20);
              if ((uVar7 == 0xffffffff) || (uVar7 == 10)) goto LAB_001072e2;
            }
            *(undefined8 *)(puVar14 + -0x1070) = 0x107450;
            FUN_001085d0(uVar7);
            goto LAB_00106f17;
          }
LAB_001072e2:
          lVar15 = 6;
          goto LAB_001071e0;
        }
LAB_00106f17:
        *(undefined8 *)(puVar14 + -0x1070) = 0x106f1f;
        lVar15 = FUN_00108e90(param_3);
        *(long *)((long)__ptr + 8) = lVar15;
        if (lVar15 == 0) {
LAB_001074c2:
          lVar15 = 10;
          goto LAB_001071e0;
        }
        pcVar11 = *(char **)(lVar15 + 8);
        *(undefined8 *)(puVar14 + -0x1070) = 0x106f38;
        __n = strlen(pcVar11);
        *(undefined8 *)(puVar14 + -0x1070) = 0x106f45;
        memset(pcVar11,0,__n);
        *(undefined8 *)(puVar14 + -0x1070) = 0x106f55;
        pcVar11 = (char *)FUN_00107f10("RANDOM_DELAY",*(undefined8 *)(puVar14 + -0x1068));
        if (pcVar11 != (char *)0x0) {
          *(undefined8 *)(puVar14 + -0x1070) = 0x106f62;
          piVar12 = __errno_location();
          *piVar12 = 0;
          *(int **)(puVar14 + -0x1060) = piVar12;
          *(undefined8 *)(puVar14 + -0x1070) = 0x106f7f;
          uVar13 = strtol(pcVar11,(char **)(puVar14 + -0x1050),10);
          if ((**(int **)(puVar14 + -0x1060) == 0) && (uVar13 < 0x5a1)) {
            *(int *)((long)__ptr + 0x38) = (int)((double)(long)uVar13 * _DAT_0010e2c8);
          }
          else {
            *(undefined8 *)(puVar14 + -0x1070) = 0x1074dd;
            _Var10 = getpid();
            *(undefined8 *)(puVar14 + -0x1070) = 0x1074fc;
            FUN_00108720(&DAT_0010aea4,_Var10,"ERROR","bad value of RANDOM_DELAY",0);
          }
        }
        *(undefined8 *)(puVar14 + -0x1070) = 0x106fbc;
        lVar15 = FUN_00107870(*(undefined8 *)(puVar14 + -0x1068));
        *(long *)((long)__ptr + 0x10) = lVar15;
        if (lVar15 != 0) {
          *(undefined8 *)(puVar14 + -0x1070) = 0x106fdb;
          lVar15 = FUN_00107f10("SHELL",lVar15);
          if (lVar15 == 0) {
            *(undefined8 *)(puVar14 + -0x1070) = 0x1075d2;
            iVar8 = FUN_00108130(puVar14 + 0x1efe8,0x20000,"SHELL","/bin/sh",0x3d);
            if (iVar8 == 0) {
              *(undefined8 *)(puVar14 + -0x1070) = 0x1076c2;
              _Var10 = getpid();
              *(undefined8 *)(puVar14 + -0x1070) = 0x1076e1;
              FUN_00108720(&DAT_0010aea4,_Var10,"ERROR","can\'t set SHELL",0);
              goto LAB_00106feb;
            }
            uVar4 = *(undefined8 *)((long)__ptr + 0x10);
            *(undefined8 *)(puVar14 + -0x1070) = 0x1075e6;
            lVar15 = FUN_00107940(uVar4,puVar14 + 0x1efe8);
            if (lVar15 == 0) goto LAB_001074c2;
            *(long *)((long)__ptr + 0x10) = lVar15;
          }
          else {
LAB_00106feb:
            lVar15 = *(long *)((long)__ptr + 0x10);
          }
          pcVar11 = param_3->pw_dir;
          *(undefined8 *)(puVar14 + -0x1070) = 0x106ff9;
          lVar15 = FUN_00107f90(lVar15,pcVar11);
          if (lVar15 == 0) goto LAB_001074c2;
          *(long *)((long)__ptr + 0x10) = lVar15;
          *(undefined8 *)(puVar14 + -0x1070) = 0x107020;
          lVar15 = FUN_00107f10("PATH",lVar15);
          if (lVar15 == 0) {
            if (DAT_0010e2d0 == 0) {
              *(undefined8 *)(puVar14 + -0x1070) = 0x10777b;
              pcVar11 = getenv("PATH");
              if (pcVar11 == (char *)0x0) goto LAB_0010753f;
            }
            else {
LAB_0010753f:
              pcVar11 = "/usr/bin:/bin";
            }
            *(undefined8 *)(puVar14 + -0x1070) = 0x107561;
            iVar8 = FUN_00108130(puVar14 + 0x1efe8,0x20000,"PATH",pcVar11,0x3d);
            if (iVar8 == 0) {
              *(undefined8 *)(puVar14 + -0x1070) = 0x107699;
              _Var10 = getpid();
              *(undefined8 *)(puVar14 + -0x1070) = 0x1076b8;
              FUN_00108720(&DAT_0010aea4,_Var10,"ERROR","can\'t set PATH",0);
            }
            else {
              uVar4 = *(undefined8 *)((long)__ptr + 0x10);
              *(undefined8 *)(puVar14 + -0x1070) = 0x107575;
              lVar15 = FUN_00107940(uVar4,puVar14 + 0x1efe8);
              if (lVar15 == 0) goto LAB_001074c2;
              *(long *)((long)__ptr + 0x10) = lVar15;
            }
          }
          puVar16 = puVar14 + 0x1efe8;
          pcVar11 = param_3->pw_name;
          *(undefined8 *)(puVar14 + -0x1070) = 0x107047;
          iVar8 = FUN_00108130(puVar16,0x20000,"LOGNAME",pcVar11,0x3d);
          if (iVar8 == 0) {
            *(undefined8 *)(puVar14 + -0x1070) = 0x107506;
            _Var10 = getpid();
            *(undefined8 *)(puVar14 + -0x1070) = 0x107525;
            FUN_00108720(&DAT_0010aea4,_Var10,"ERROR","can\'t set LOGNAME",0);
          }
          else {
            uVar4 = *(undefined8 *)((long)__ptr + 0x10);
            *(undefined8 *)(puVar14 + -0x1070) = 0x10705b;
            lVar15 = FUN_00107940(uVar4,puVar16);
            if (lVar15 == 0) goto LAB_001074c2;
            *(long *)((long)__ptr + 0x10) = lVar15;
          }
          pcVar11 = param_3->pw_name;
          *(undefined8 *)(puVar14 + -0x1070) = 0x107086;
          iVar8 = FUN_00108130(puVar16,0x20000,"USER",pcVar11,0x3d);
          if (iVar8 == 0) {
            *(undefined8 *)(puVar14 + -0x1070) = 0x10758c;
            _Var10 = getpid();
            *(undefined8 *)(puVar14 + -0x1070) = 0x1075ab;
            FUN_00108720(&DAT_0010aea4,_Var10,"ERROR","can\'t set USER",0);
          }
          else {
            uVar4 = *(undefined8 *)((long)__ptr + 0x10);
            *(undefined8 *)(puVar14 + -0x1070) = 0x10709a;
            lVar15 = FUN_00107940(uVar4,puVar16);
            if (lVar15 == 0) goto LAB_001074c2;
            *(long *)((long)__ptr + 0x10) = lVar15;
          }
          if (((byte)DAT_0010e2c0 & 8) != 0) {
            *(undefined8 *)(puVar14 + -0x1070) = 0x10768f;
            __printf_chk(1,"load_entry()...about to parse command\n");
          }
          *(undefined8 *)(puVar14 + -0x1070) = 0x1070d0;
          uVar7 = FUN_00108620(puVar14 + -0x1018,0x20000,param_1,&DAT_0010af6f);
          if (uVar7 == 0xffffffff) goto LAB_001072e2;
          *(undefined8 *)(puVar14 + -0x1070) = 0x1070e3;
          pcVar11 = strdup(puVar14 + -0x1018);
          *(char **)((long)__ptr + 0x18) = pcVar11;
          if (pcVar11 != (char *)0x0) {
            if (((byte)DAT_0010e2c0 & 8) != 0) {
              *(undefined8 *)(puVar14 + -0x1070) = 0x10710c;
              __printf_chk(1,"load_entry()...returning successfully\n");
            }
            goto LAB_0010714b;
          }
          goto LAB_001074c2;
        }
        lVar15 = 10;
      }
      else {
        if (((byte)DAT_0010e2c0 & 8) != 0) {
          *(undefined8 *)(puVar14 + -0x1070) = 0x1071a3;
          __printf_chk(1,"load_entry()...about to parse numerics\n");
        }
        if (uVar7 == 0x2a) {
          *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 1;
        }
        *(undefined8 *)(puVar14 + -0x1070) = 0x106e16;
        iVar8 = FUN_00106bb0((long)__ptr + 0x20,0,0x3b,0,uVar7,param_1);
        if (iVar8 == -1) {
          lVar15 = 1;
          uVar7 = 0xffffffff;
        }
        else {
          if (iVar8 == 0x2a) {
            *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 2;
          }
          *(undefined8 *)(puVar14 + -0x1070) = 0x106e43;
          iVar8 = FUN_00106bb0((long)__ptr + 0x28,0,0x17,0,iVar8,param_1);
          if (iVar8 == -1) {
            lVar15 = 2;
            uVar7 = 0xffffffff;
          }
          else {
            if (iVar8 == 0x2a) {
              *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 4;
            }
            *(undefined8 *)(puVar14 + -0x1070) = 0x106e73;
            iVar8 = FUN_00106bb0((long)__ptr + 0x2b,1,0x1f,0,iVar8,param_1);
            if (iVar8 != -1) {
              *(undefined8 *)(puVar14 + -0x1070) = 0x106e9e;
              iVar8 = FUN_00106bb0((long)__ptr + 0x2f,1,0xc,&PTR_DAT_0010e0e0,iVar8,param_1);
              if (iVar8 == -1) {
                lVar15 = 4;
                uVar7 = 0xffffffff;
                goto LAB_001071e0;
              }
              if (iVar8 == 0x2a) {
                *(uint *)((long)__ptr + 0x34) = *(uint *)((long)__ptr + 0x34) | 8;
              }
              *(undefined8 *)(puVar14 + -0x1070) = 0x106ed0;
              uVar7 = FUN_00106bb0((long)__ptr + 0x31,0,7,&PTR_DAT_0010e080,iVar8,param_1);
              if (uVar7 == 0xffffffff) {
                lVar15 = 5;
                goto LAB_001071e0;
              }
              goto LAB_00106edb;
            }
            lVar15 = 3;
            uVar7 = 0xffffffff;
          }
        }
LAB_001071e0:
        if (*(long *)((long)__ptr + 0x10) != 0) {
          *(undefined8 *)(puVar14 + -0x1070) = 0x1071ee;
          FUN_00107830();
        }
      }
      pvVar5 = *(void **)((long)__ptr + 8);
      *(undefined8 *)(puVar14 + -0x1070) = 0x1071f7;
      free(pvVar5);
      pvVar5 = *(void **)((long)__ptr + 0x18);
      *(undefined8 *)(puVar14 + -0x1070) = 0x107200;
      free(pvVar5);
      *(undefined8 *)(puVar14 + -0x1070) = 0x107208;
      free(__ptr);
    }
    iVar8 = 0;
    if (uVar7 != 10) {
      while( true ) {
        *(undefined8 *)(puVar14 + -0x1070) = 0x10723a;
        iVar9 = feof(param_1);
        if (iVar9 != 0) break;
        iVar8 = iVar8 + 1;
        *(undefined8 *)(puVar14 + -0x1070) = 0x107224;
        iVar9 = FUN_00108570(param_1);
        if ((0x1ffff < iVar8) || (iVar9 == 10)) break;
      }
    }
    if (param_2 != (code *)0x0) {
      __ptr = (void *)0x0;
      puVar6 = (&PTR_s_no_error_0010da80)[lVar15];
      *(undefined8 *)(puVar14 + -0x1070) = 0x10725a;
      (*param_2)(puVar6);
      goto LAB_0010714b;
    }
  }
LAB_00107148:
  __ptr = (void *)0x0;
LAB_0010714b:
  if (*(long *)(puVar14 + 0x3eff0) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined8 *)(puVar14 + -0x1070) = 0x1077ed;
    __stack_chk_fail();
  }
  return __ptr;
}



// Function: env_init @ 0x7800

void env_init(void)

{
  undefined8 *puVar1;
  
  puVar1 = malloc(8);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = 0;
  }
  return;
}



// Function: env_free @ 0x7830

void env_free(undefined8 *param_1)

{
  undefined8 *puVar1;
  void *__ptr;
  undefined8 *puVar2;
  
  __ptr = (void *)*param_1;
  puVar2 = param_1;
  while (__ptr != (void *)0x0) {
    free(__ptr);
    puVar1 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    __ptr = (void *)*puVar1;
  }
  free(param_1);
  return;
}



// Function: env_copy @ 0x7870

undefined8 * env_copy(long *param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 *__ptr;
  char *pcVar4;
  int *piVar5;
  long lVar6;
  undefined8 *puVar7;
  bool bVar8;
  
  if (*param_1 == 0) {
    __ptr = malloc(8);
    puVar7 = __ptr;
    if (__ptr != (undefined8 *)0x0) goto LAB_001078e1;
  }
  else {
    lVar1 = 0;
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_1[lVar1] != 0);
    __ptr = malloc(lVar1 * 8 + 8);
    if (__ptr != (undefined8 *)0x0) {
      lVar6 = 0;
      do {
        pcVar4 = strdup((char *)param_1[lVar6]);
        __ptr[lVar6] = pcVar4;
        if (pcVar4 == (char *)0x0) {
          piVar5 = __errno_location();
          iVar2 = *piVar5;
          while (lVar6 != 0) {
            lVar6 = lVar6 + -1;
            free((void *)__ptr[lVar6]);
          }
          free(__ptr);
          *piVar5 = iVar2;
          return (undefined8 *)0x0;
        }
        bVar8 = lVar3 != lVar6;
        lVar6 = lVar6 + 1;
      } while (bVar8);
      puVar7 = __ptr + lVar1;
LAB_001078e1:
      *puVar7 = 0;
      return __ptr;
    }
  }
  return (undefined8 *)0x0;
}



// Function: env_set @ 0x7940

long * env_set(long *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *param_1;
  if (lVar6 == 0) {
    lVar5 = 0;
    lVar4 = 1;
  }
  else {
    lVar7 = -1;
    lVar5 = 0;
    do {
      lVar4 = lVar5;
      lVar5 = lVar4 + 1;
      iVar1 = FUN_001081d0(lVar6,param_2,0x3d);
      lVar6 = param_1[lVar5];
      if (iVar1 == 0) {
        lVar7 = lVar4;
      }
    } while (lVar6 != 0);
    if (lVar7 != -1) {
      pcVar2 = strdup(param_2);
      if (pcVar2 == (char *)0x0) {
        return (long *)0x0;
      }
      free((void *)param_1[lVar7]);
      param_1[lVar7] = (long)pcVar2;
      return param_1;
    }
    lVar4 = lVar4 + 2;
  }
  pcVar2 = strdup(param_2);
  if (pcVar2 == (char *)0x0) {
    return (long *)0x0;
  }
  plVar3 = realloc(param_1,lVar5 * 8 + 0x10);
  if (plVar3 != (long *)0x0) {
    plVar3[lVar4] = plVar3[lVar4 + -1];
    plVar3[lVar4 + -1] = (long)pcVar2;
    return plVar3;
  }
  free(pcVar2);
  return (long *)0x0;
}



// Function: env_set_from_environ @ 0x7a40

undefined4 env_set_from_environ(long *param_1)

{
  undefined **ppuVar1;
  char *__s2;
  int iVar2;
  size_t __n;
  long lVar3;
  char *__s;
  long *plVar4;
  undefined **ppuVar5;
  
  lVar3 = *environ;
  plVar4 = environ;
  do {
    if (lVar3 == 0) {
      return 1;
    }
    ppuVar5 = &PTR_DAT_0010e1a0;
    __s = PTR_DAT_0010e1a0;
    while (__s != (char *)0x0) {
      while( true ) {
        __n = strlen(__s);
        __s2 = (char *)*plVar4;
        iVar2 = strncmp(__s,__s2,__n);
        if ((iVar2 != 0) || (__s2[__n] != '=')) break;
        lVar3 = FUN_00107940(*param_1,__s2);
        if (lVar3 == 0) {
          return 0;
        }
        __s = ppuVar5[1];
        ppuVar5 = ppuVar5 + 1;
        *param_1 = lVar3;
        if (__s == (char *)0x0) goto LAB_00107af0;
      }
      ppuVar1 = ppuVar5 + 1;
      ppuVar5 = ppuVar5 + 1;
      __s = *ppuVar1;
    }
LAB_00107af0:
    plVar4 = plVar4 + 1;
    lVar3 = *plVar4;
  } while( true );
}



// Function: load_env @ 0x7b20

/* WARNING: Type propagation algorithm not settling */

undefined4 load_env(byte *param_1,FILE *param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  long __off;
  ushort **ppuVar4;
  byte bVar5;
  ulong uVar6;
  byte *pbVar7;
  byte bVar8;
  ulong uVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *local_50;
  
  __off = ftell(param_2);
  uVar1 = DAT_0014e2fc;
  iVar3 = FUN_00108620(param_1,0x20000,param_2,&DAT_0010af6f);
  if (iVar3 == -1) {
    return 0xffffffff;
  }
  if (((byte)DAT_0010e2c0 & 8) != 0) {
    __printf_chk(1,"load_env, read <%s>\n",param_1);
  }
  uVar9 = 0;
  iVar3 = 0;
  pbVar11 = param_1;
  local_50 = param_1;
LAB_00107b90:
  bVar8 = (byte)uVar9;
  bVar5 = *param_1;
  if (bVar5 != 0) {
LAB_00107b9c:
    uVar6 = (ulong)bVar5;
    bVar8 = (byte)uVar9;
    switch(iVar3) {
    default:
      if ((bVar5 == 0x27) || (uVar2 = uVar6, bVar5 == 0x22)) {
        pbVar7 = param_1 + 1;
        param_1 = param_1 + 1;
        uVar2 = (ulong)*pbVar7;
        uVar9 = uVar6;
      }
      uVar6 = uVar2;
      iVar3 = iVar3 + 1;
    case 1:
    case 5:
      do {
        bVar5 = (byte)uVar6;
        if ((byte)uVar9 == 0) {
          if (iVar3 != 1) {
LAB_00107d02:
            *pbVar11 = bVar5;
            param_1 = param_1 + 1;
            pbVar11 = pbVar11 + 1;
            goto LAB_00107b90;
          }
          ppuVar4 = __ctype_b_loc();
          if ((*(byte *)((long)*ppuVar4 + uVar6 * 2 + 1) & 0x20) != 0) {
            bVar5 = param_1[1];
            goto joined_r0x00107d22;
          }
          pbVar7 = param_1;
          pbVar10 = pbVar11;
          if (bVar5 == 0x3d) goto LAB_00107bf0;
        }
        else {
          if ((byte)uVar9 == bVar5) {
            iVar3 = iVar3 + 1;
            param_1 = param_1 + 1;
            goto LAB_00107b90;
          }
          if (iVar3 != 1) goto LAB_00107d02;
          if (bVar5 == 0x3d) goto LAB_00107d80;
        }
        *pbVar11 = bVar5;
        pbVar7 = param_1 + 1;
        uVar6 = (ulong)*pbVar7;
        param_1 = param_1 + 1;
        pbVar11 = pbVar11 + 1;
        if (*pbVar7 == 0) {
          iVar3 = 1;
          goto LAB_00107d86;
        }
        iVar3 = 1;
      } while( true );
    case 2:
      goto switchD_00107bb1_caseD_2;
    case 3:
    case 6:
      goto switchD_00107bb1_caseD_3;
    }
  }
LAB_00107ca0:
  if ((iVar3 == 6) || (iVar3 == 3)) {
LAB_00107caa:
    *pbVar11 = 0;
    if (iVar3 != 5) {
      return 1;
    }
  }
  else {
    if ((iVar3 != 5) || (bVar8 != 0)) goto LAB_00107d86;
    *pbVar11 = 0;
  }
  if (pbVar11 <= local_50) {
    return 1;
  }
  ppuVar4 = __ctype_b_loc();
  do {
    if ((*(byte *)((long)*ppuVar4 + (ulong)pbVar11[-1] * 2 + 1) & 0x20) == 0) {
      return 1;
    }
    pbVar11 = pbVar11 + -1;
    *pbVar11 = 0;
  } while (pbVar11 != local_50);
  return 1;
joined_r0x00107d22:
  uVar6 = (ulong)bVar5;
  param_1 = param_1 + 1;
  if (bVar5 == 0) {
    iVar3 = 2;
    goto LAB_00107d86;
  }
switchD_00107bb1_caseD_2:
  pbVar7 = param_1;
  pbVar10 = pbVar11;
  if ((char)uVar6 == '=') goto LAB_00107bf0;
  ppuVar4 = __ctype_b_loc();
  if ((*(byte *)((long)*ppuVar4 + uVar6 * 2 + 1) & 0x20) == 0) goto LAB_00107d80;
  bVar5 = param_1[1];
  goto joined_r0x00107d22;
LAB_00107bf0:
  *pbVar10 = 0x3d;
  bVar5 = pbVar7[1];
  pbVar11 = pbVar10 + 1;
  param_1 = pbVar7 + 1;
  if (bVar5 == 0) {
LAB_00107eca:
    pbVar10[1] = 0;
    return 1;
  }
  ppuVar4 = __ctype_b_loc();
  local_50 = pbVar11;
  if ((*(byte *)((long)*ppuVar4 + (ulong)bVar5 * 2 + 1) & 0x20) != 0) {
    bVar5 = pbVar7[2];
    param_1 = pbVar7 + 2;
    if (bVar5 == 0) goto LAB_00107eca;
    ppuVar4 = __ctype_b_loc();
    if ((*(byte *)((long)*ppuVar4 + (ulong)bVar5 * 2 + 1) & 0x20) != 0) {
      uVar6 = (ulong)pbVar7[3];
      param_1 = pbVar7 + 3;
      if (pbVar7[3] == 0) {
        iVar3 = 3;
        goto LAB_00107caa;
      }
      bVar8 = 0;
      iVar3 = 3;
switchD_00107bb1_caseD_3:
      ppuVar4 = __ctype_b_loc();
      uVar9 = (ulong)bVar8;
      if ((*(byte *)((long)*ppuVar4 + uVar6 * 2 + 1) & 0x20) == 0) goto LAB_00107d70;
      bVar5 = param_1[1];
      param_1 = param_1 + 1;
      if (bVar5 == 0) goto LAB_00107ca0;
      goto LAB_00107b9c;
    }
  }
  uVar9 = 0;
  iVar3 = 3;
LAB_00107d70:
  iVar3 = iVar3 + 1;
  if (iVar3 == 7) {
LAB_00107d80:
    iVar3 = 7;
LAB_00107d86:
    if (((byte)DAT_0010e2c0 & 8) != 0) {
      __printf_chk(1,"load_env, not an env var, state = %d\n",iVar3);
    }
    iVar3 = fseek(param_2,__off,0);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    if (((byte)DAT_0010e2c0 & 9) != 0) {
      __printf_chk(1,"linenum=%d\n",uVar1);
    }
    DAT_0014e2fc = uVar1;
    return 0;
  }
  goto LAB_00107b90;
}



// Function: env_get @ 0x7f10

char * env_get(char *param_1,undefined8 *param_2)

{
  char *__s;
  int iVar1;
  size_t __n;
  char *pcVar2;
  
  __n = strlen(param_1);
  __s = (char *)*param_2;
  while( true ) {
    if (__s == (char *)0x0) {
      return (char *)0x0;
    }
    param_2 = param_2 + 1;
    pcVar2 = strchr(__s,0x3d);
    if (((pcVar2 != (char *)0x0) && ((long)pcVar2 - (long)__s == __n)) &&
       (iVar1 = strncmp(__s,param_1,__n), iVar1 == 0)) break;
    __s = (char *)*param_2;
  }
  return pcVar2 + 1;
}



// Function: env_update_home @ 0x7f90

undefined8 env_update_home(undefined8 param_1,char *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  __pid_t _Var3;
  long lVar4;
  undefined1 *puVar5;
  long in_FS_OFFSET;
  undefined1 auStack_20020 [131072];
  
  puVar1 = &stack0xffffffffffffffe0;
  do {
    puVar5 = puVar1;
    *(undefined8 *)(puVar5 + -0x1000) = *(undefined8 *)(puVar5 + -0x1000);
    puVar1 = puVar5 + -0x1000;
  } while (puVar5 + -0x1000 != auStack_20020);
  *(undefined8 *)(puVar5 + 0x1eff0) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    *(undefined8 *)(puVar5 + -0x1020) = 0x10801a;
    lVar4 = FUN_00107f10("HOME",param_1);
    if (lVar4 == 0) {
      *(undefined8 *)(puVar5 + -0x1020) = 0x10803b;
      iVar2 = FUN_00108130(puVar5 + -0x1018,0x20000,"HOME",param_2,0x3d);
      if (iVar2 == 0) {
        *(undefined8 *)(puVar5 + -0x1020) = 0x108055;
        _Var3 = getpid();
        *(undefined8 *)(puVar5 + -0x1020) = 0x108074;
        FUN_00108720(&DAT_0010aea4,_Var3,"ERROR","can\'t set HOME",0);
      }
      else {
        *(undefined8 *)(puVar5 + -0x1020) = 0x10804a;
        param_1 = FUN_00107940(param_1,puVar5 + -0x1018);
      }
    }
  }
  if (*(long *)(puVar5 + 0x1eff0) == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar5 + -0x1020) = &UNK_0010807e;
  __stack_chk_fail();
}



// Function: mkprint @ 0x8080

void mkprint(byte *param_1,byte *param_2,long param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  
  if (param_3 != 0) {
    pbVar1 = param_2 + param_3;
    pbVar3 = param_1;
LAB_001080bd:
    do {
      bVar2 = *param_2;
      param_2 = param_2 + 1;
      if (bVar2 < 0x20) {
        *pbVar3 = 0x5e;
        param_1 = pbVar3 + 2;
        pbVar3[1] = bVar2 + 0x40;
      }
      else {
        if (bVar2 < 0x7f) {
          *pbVar3 = bVar2;
          param_1 = pbVar3 + 1;
          pbVar3 = param_1;
          if (pbVar1 == param_2) break;
          goto LAB_001080bd;
        }
        if (bVar2 == 0x7f) {
          param_1 = pbVar3 + 2;
          pbVar3[0] = 0x5e;
          pbVar3[1] = 0x3f;
        }
        else {
          param_1 = pbVar3 + 4;
          __sprintf_chk(pbVar3,1,0xffffffffffffffff,"\\%03o");
        }
      }
      pbVar3 = param_1;
    } while (pbVar1 != param_2);
  }
  *param_1 = 0;
  return;
}



// Function: glue_strings @ 0x8130

undefined8 glue_strings(char *param_1,long param_2,char *param_3,char *param_4,char param_5)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (param_2 == 0) {
    return 0;
  }
  pcVar1 = param_1 + param_2;
  pcVar3 = param_1;
  if (param_1 < pcVar1) {
    pcVar4 = param_3 + param_2;
    do {
      cVar2 = *param_3;
      if (cVar2 == '\0') goto LAB_00108170;
      param_3 = param_3 + 1;
      *pcVar3 = cVar2;
      pcVar3 = pcVar3 + 1;
    } while (pcVar4 != param_3);
    if (pcVar1 == pcVar3) {
      return 0;
    }
LAB_00108170:
    if (((param_5 == '/') && (param_1 != pcVar3)) && (pcVar3[-1] == '/')) goto LAB_0010818b;
  }
  else if (param_1 == pcVar1) {
    return 0;
  }
  *pcVar3 = param_5;
  pcVar3 = pcVar3 + 1;
LAB_0010818b:
  if (pcVar3 != pcVar1) {
    if (pcVar1 <= pcVar3) {
LAB_001081b3:
      *pcVar3 = '\0';
      return 1;
    }
    do {
      if (*param_4 == '\0') {
        if (pcVar1 == pcVar3) {
          return 0;
        }
        goto LAB_001081b3;
      }
      *pcVar3 = *param_4;
      pcVar3 = pcVar3 + 1;
      param_4 = param_4 + 1;
    } while (pcVar1 != pcVar3);
  }
  return 0;
}



// Function: strcmp_until @ 0x81d0

int strcmp_until(char *param_1,char *param_2,char param_3)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = *param_1;
  while ((cVar2 != '\0' && (cVar3 = *param_2, cVar2 != param_3))) {
    if (cVar2 != cVar3) goto LAB_00108207;
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    cVar2 = *pcVar1;
  }
  cVar3 = *param_2;
  if ((cVar3 == param_3) || (cVar3 == '\0')) {
    return 0;
  }
LAB_00108207:
  return (int)cVar2 - (int)cVar3;
}



// Function: strdtb @ 0x8220

long strdtb(byte *param_1)

{
  ushort **ppuVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = param_1;
  pbVar3 = param_1;
  if (*param_1 == 0) goto LAB_00108262;
  do {
    pbVar3 = pbVar2;
    pbVar2 = pbVar3 + 1;
  } while (*pbVar2 != 0);
  while ((param_1 <= pbVar3 &&
         (ppuVar1 = __ctype_b_loc(),
         (*(byte *)((long)*ppuVar1 + (ulong)*pbVar3 * 2 + 1) & 0x20) != 0))) {
LAB_00108262:
    pbVar2 = pbVar3;
    pbVar3 = pbVar3 + -1;
  }
  pbVar3[1] = 0;
  return (long)pbVar2 - (long)param_1;
}



// Function: set_debug_flags @ 0x8280

undefined8 set_debug_flags(char *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined *puVar3;
  int iVar4;
  long lVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined **ppuVar8;
  uint uVar9;
  
  puVar3 = PTR_DAT_0010e020;
  DAT_0010e2c0 = 0;
  pcVar7 = param_1;
  if (*param_1 != '\0') {
    do {
      if (puVar3 == (undefined *)0x0) {
LAB_00108348:
        __fprintf_chk(stderr,1,"unrecognized debug flag <%s> <%s>\n",param_1,pcVar7);
        return 0;
      }
      uVar9 = 1;
      ppuVar8 = &PTR_DAT_0010e020;
      puVar6 = puVar3;
      while (iVar4 = FUN_001081d0(puVar6,pcVar7,0x2c), iVar4 != 0) {
        puVar6 = ppuVar8[1];
        ppuVar8 = ppuVar8 + 1;
        uVar9 = uVar9 * 2;
        if (puVar6 == (undefined *)0x0) goto LAB_00108348;
      }
      DAT_0010e2c0 = uVar9 | DAT_0010e2c0;
      cVar2 = *pcVar7;
      while ((cVar2 != '\0' && (cVar2 != ','))) {
        pcVar1 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
        cVar2 = *pcVar1;
      }
      pcVar7 = pcVar7 + (cVar2 == ',');
    } while (*pcVar7 != '\0');
    if (DAT_0010e2c0 != 0) {
      lVar5 = 0;
      __fprintf_chk(stderr,1,"debug flags enabled:");
      puVar3 = PTR_DAT_0010e020;
      while (puVar3 != (undefined *)0x0) {
        while ((DAT_0010e2c0 >> ((uint)lVar5 & 0x1f) & 1) != 0) {
          lVar5 = lVar5 + 1;
          __fprintf_chk(stderr,1," %s");
          if ((&PTR_DAT_0010e020)[lVar5] == (undefined *)0x0) goto LAB_001083db;
        }
        lVar5 = lVar5 + 1;
        puVar3 = (&PTR_DAT_0010e020)[lVar5];
      }
LAB_001083db:
      __fprintf_chk(stderr,1,&DAT_0010af6f);
    }
  }
  return 1;
}



// Function: set_cron_uid @ 0x8400

void set_cron_uid(void)

{
  int iVar1;
  
  iVar1 = setuid(0);
  if (-1 < iVar1) {
    return;
  }
  perror("setuid");
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: check_spool_dir @ 0x8430

void check_spool_dir(void)

{
  int iVar1;
  int *piVar2;
  long in_FS_OFFSET;
  stat sStack_b8;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = stat("/usr/local/var/spool/cron",&sStack_b8);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    if (*piVar2 == 2) {
      perror("/usr/local/var/spool/cron");
      iVar1 = mkdir("/usr/local/var/spool/cron",0x1c0);
      if (iVar1 != 0) {
        __fprintf_chk(stderr,1,&DAT_0010b33e,"/usr/local/var/spool/cron");
        perror("mkdir");
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      __fprintf_chk(stderr,1,"%s: created\n","/usr/local/var/spool/cron");
      iVar1 = stat("/usr/local/var/spool/cron",&sStack_b8);
      if (iVar1 < 0) {
        perror("stat retry");
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
    }
  }
  if ((sStack_b8.st_mode & 0xf000) != 0x4000) {
    __fprintf_chk(stderr,1,"\'%s\' is not a directory, bailing out.\n","/usr/local/var/spool/cron");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: get_char @ 0x8570

int get_char(FILE *param_1)

{
  int iVar1;
  
  iVar1 = getc(param_1);
  if (iVar1 != 10) {
    return iVar1;
  }
  if (((byte)DAT_0010e2c0 & 9) != 0) {
    __printf_chk(1,"linenum=%d\n",DAT_0014e2fc + 1);
  }
  DAT_0014e2fc = DAT_0014e2fc + 1;
  return 10;
}



// Function: unget_char @ 0x85d0

void unget_char(int param_1,FILE *param_2)

{
  ungetc(param_1,param_2);
  if (param_1 != 10) {
    return;
  }
  if (((byte)DAT_0010e2c0 & 9) != 0) {
    __printf_chk(1,"linenum=%d\n",DAT_0014e2fc + -1);
  }
  DAT_0014e2fc = DAT_0014e2fc + -1;
  return;
}



// Function: get_string @ 0x8620

int get_string(undefined1 *param_1,int param_2,undefined8 param_3,char *param_4)

{
  int __c;
  char *pcVar1;
  
  while( true ) {
    __c = FUN_00108570(param_3);
    if (__c == -1) break;
    pcVar1 = strchr(param_4,__c);
    if (pcVar1 != (char *)0x0) break;
    if (1 < param_2) {
      param_2 = param_2 + -1;
      *param_1 = (char)__c;
      param_1 = param_1 + 1;
    }
  }
  if (0 < param_2) {
    *param_1 = 0;
  }
  return __c;
}



// Function: skip_comments @ 0x8690

undefined8 skip_comments(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = FUN_00108570(param_1);
    if (iVar1 == -1) {
      return 1;
    }
    while( true ) {
      iVar2 = iVar2 + 1;
      if (iVar2 == 0x8001) {
        return 0;
      }
      if ((iVar1 != 0x20) && (iVar1 != 9)) break;
      iVar1 = FUN_00108570(param_1);
    }
    if (iVar1 == -1) break;
    if (iVar1 != 10) {
      if (iVar1 != 0x23) {
        FUN_001085d0(iVar1,param_1);
        return 1;
      }
      while ((iVar1 != 10 && (iVar1 != -1))) {
        iVar2 = iVar2 + 1;
        iVar1 = FUN_00108570(param_1);
        if (iVar2 == 0x8001) {
          return 0;
        }
      }
    }
  }
  return 1;
}



// Function: log_it @ 0x8720

void log_it(undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4,int param_5)

{
  char *pcVar1;
  undefined *puVar2;
  
  if (DAT_001915b0 == 0) {
    openlog(DAT_0014e300,1,0x48);
    DAT_001915b0 = 1;
  }
  if (param_5 == 0) {
    puVar2 = &DAT_0010af70;
    __syslog_chk(6,1,"(%s) %s (%s)%s%s",param_1,param_3,param_4,&DAT_0010af70,&DAT_0010af70);
    pcVar1 = "";
    if (DAT_0010e2c0 == 0) {
      return;
    }
  }
  else {
    puVar2 = &DAT_0010b340;
    pcVar1 = strerror(param_5);
    __syslog_chk(3,1,"(%s) %s (%s)%s%s",param_1,param_3,param_4,&DAT_0010b340,pcVar1);
    if (DAT_0010e2c0 == 0) {
      return;
    }
    pcVar1 = strerror(param_5);
  }
  __fprintf_chk(stderr,1,"log_it: (%s %ld) %s (%s)%s%s\n",param_1,(long)param_2,param_3,param_4,
                puVar2,pcVar1);
  return;
}



// Function: acquire_daemonlock @ 0x8850

void acquire_daemonlock(int param_1)

{
  __pid_t _Var1;
  int iVar2;
  int iVar3;
  size_t __n;
  size_t sVar4;
  int *piVar5;
  ssize_t sVar6;
  long lVar7;
  char *pcVar8;
  long in_FS_OFFSET;
  char *local_3040;
  char local_3038 [12296];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  _Var1 = getpid();
  if (param_1 != 0) {
    if (DAT_0010e228 != -1) {
      close(DAT_0010e228);
      DAT_0010e228 = -1;
    }
    signal(2,(__sighandler_t)0x0);
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      signal(0xf,(__sighandler_t)0x0);
      return;
    }
    goto LAB_00108a61;
  }
  if (DAT_0010e228 != -1) {
LAB_001088b7:
    __sprintf_chk(local_3038,1,0x3000,&DAT_0010b3bf,(long)_Var1);
    iVar3 = DAT_0010e228;
    lseek(DAT_0010e228,0,0);
    __n = strlen(local_3038);
    sVar4 = write(iVar3,local_3038,__n);
    if (__n == sVar4) {
      iVar3 = ftruncate(DAT_0010e228,__n);
      if (iVar3 == -1) {
        piVar5 = __errno_location();
        FUN_00108720(&DAT_0010aea4,_Var1,"ERROR","ftruncate() failed",*piVar5);
      }
    }
    else {
      piVar5 = __errno_location();
      FUN_00108720(&DAT_0010aea4,_Var1,"ERROR","write() failed",*piVar5);
    }
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
LAB_00108a61:
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  iVar3 = open("/usr/local/var/run/crond.pid",0x42,0x180);
  DAT_0010e228 = iVar3;
  if (iVar3 == -1) {
    piVar5 = __errno_location();
    iVar2 = *piVar5;
    __sprintf_chk(local_3038,1,0x3000,"can\'t open or create %s","/usr/local/var/run/crond.pid");
    pcVar8 = strerror(iVar2);
    __fprintf_chk(stderr,1,"%s: %s: %s\n",DAT_0014e300,local_3038,pcVar8);
    goto LAB_00108ac6;
  }
  iVar2 = flock(iVar3);
  if (-1 < iVar2) {
    fchmod(iVar3,0x1a4);
    fcntl(iVar3,2,1);
    goto LAB_001088b7;
  }
  piVar5 = __errno_location();
  iVar2 = *piVar5;
  memset(local_3038,0,0x3000);
  sVar6 = read(iVar3,local_3038,0x2fff);
  if (sVar6 < 1) {
LAB_00108b4b:
    __snprintf_chk(local_3038,0x3000,1,0x3000,"can\'t lock %s, otherpid unknown",
                   "/usr/local/var/run/crond.pid");
  }
  else {
    lVar7 = strtol(local_3038,&local_3040,10);
    if ((((lVar7 < 1) || (local_3040 == local_3038)) || (*local_3040 != '\n')) ||
       (lVar7 == 0x7fffffffffffffff)) goto LAB_00108b4b;
    __snprintf_chk(local_3038,0x3000,1,0x3000,"can\'t lock %s, otherpid may be %ld",
                   "/usr/local/var/run/crond.pid",lVar7,0x7fffffffffffffff);
  }
  pcVar8 = strerror(iVar2);
  __fprintf_chk(stderr,1,"%s: %s: %s\n",DAT_0014e300,local_3038,pcVar8);
LAB_00108ac6:
  FUN_00108720(&DAT_0010aea4,_Var1,"DEATH",local_3038,iVar2);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: log_close @ 0x8be0

void log_close(void)

{
  if (DAT_0010e22c != -1) {
    close(DAT_0010e22c);
    DAT_0010e22c = -1;
  }
  closelog();
  DAT_001915b0 = 0;
  return;
}



// Function: first_word @ 0x8c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * first_word(char *param_1,char *param_2)

{
  long lVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  
  _DAT_001915a4 = 1 - _DAT_001915a4;
  lVar1 = (long)_DAT_001915a4;
  pcVar4 = &DAT_001515a0 + lVar1 * 0x20001;
  cVar5 = *param_1;
  while (pcVar3 = pcVar4, cVar5 != '\0') {
    pcVar2 = strchr(param_2,(int)cVar5);
    if (pcVar2 == (char *)0x0) {
      cVar5 = *param_1;
      if (cVar5 != '\0') {
        goto LAB_00108cba;
      }
      break;
    }
    pcVar3 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar5 = *pcVar3;
  }
  goto LAB_00108ccb;
  while( true ) {
    param_1 = param_1 + 1;
    *pcVar3 = cVar5;
    pcVar3 = pcVar3 + 1;
    cVar5 = *param_1;
    if (cVar5 == '\0') break;
LAB_00108cba:
    pcVar2 = strchr(param_2,(int)cVar5);
    if ((pcVar2 != (char *)0x0) || ((char *)(lVar1 * 0x20001 + 0x1715a0) == pcVar3)) break;
  }
LAB_00108ccb:
  *pcVar3 = '\0';
  return pcVar4;
}



// Function: mkprints @ 0x8cf0

void * mkprints(undefined8 param_1,long param_2)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_2 * 4 + 1);
  if (pvVar1 != (void *)0x0) {
    FUN_00108080(pvVar1,param_1,param_2);
  }
  return pvVar1;
}



// Function: swap_uids @ 0x8d30

int swap_uids(void)

{
  __gid_t __gid;
  int iVar1;
  __uid_t __uid;
  
  DAT_001915a8 = getegid();
  DAT_001915ac = geteuid();
  __gid = getgid();
  iVar1 = setegid(__gid);
  if (iVar1 == 0) {
    __uid = getuid();
    iVar1 = seteuid(__uid);
    iVar1 = -(uint)(iVar1 != 0);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



// Function: swap_uids_back @ 0x8d80

int swap_uids_back(void)

{
  int iVar1;
  
  iVar1 = setegid(DAT_001915a8);
  if (iVar1 == 0) {
    iVar1 = seteuid(DAT_001915ac);
    iVar1 = -(uint)(iVar1 != 0);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



// Function: strlens @ 0x8dc0

long strlens(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  size_t sVar2;
  ulong uVar3;
  long lVar4;
  long in_FS_OFFSET;
  uint local_68;
  long *local_60;
  long local_48 [4];
  undefined8 local_28;
  undefined8 local_20;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  local_60 = (long *)&stack0x00000008;
  local_68 = 8;
  local_48[1] = param_2;
  local_48[2] = param_3;
  local_48[3] = param_4;
  local_28 = param_5;
  local_20 = param_6;
  if (param_1 == (char *)0x0) {
    lVar4 = 0;
  }
  else {
    lVar4 = 0;
    do {
      while( true ) {
        sVar2 = strlen(param_1);
        lVar4 = lVar4 + sVar2;
        uVar3 = (ulong)local_68;
        if (local_68 < 0x30) break;
        param_1 = (char *)*local_60;
        local_60 = local_60 + 1;
        if (param_1 == (char *)0x0) goto LAB_00108e59;
      }
      local_68 = local_68 + 8;
      param_1 = *(char **)((long)local_48 + uVar3);
    } while (param_1 != (char *)0x0);
  }
LAB_00108e59:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: pw_dup @ 0x8e90

undefined8 * pw_dup(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  size_t sVar6;
  size_t sVar7;
  size_t sVar8;
  size_t sVar9;
  size_t sVar10;
  undefined8 *puVar11;
  void *pvVar12;
  undefined8 *__dest;
  size_t local_40;
  
  if ((char *)*param_1 == (char *)0x0) {
    local_40 = 0;
    sVar6 = 0x30;
  }
  else {
    sVar6 = strlen((char *)*param_1);
    local_40 = sVar6 + 1;
    sVar6 = sVar6 + 0x31;
  }
  sVar7 = 0;
  if ((char *)param_1[1] != (char *)0x0) {
    sVar7 = strlen((char *)param_1[1]);
    sVar7 = sVar7 + 1;
    sVar6 = sVar6 + sVar7;
  }
  sVar8 = 0;
  if ((char *)param_1[3] != (char *)0x0) {
    sVar8 = strlen((char *)param_1[3]);
    sVar8 = sVar8 + 1;
    sVar6 = sVar6 + sVar8;
  }
  sVar9 = 0;
  if ((char *)param_1[4] != (char *)0x0) {
    sVar9 = strlen((char *)param_1[4]);
    sVar9 = sVar9 + 1;
    sVar6 = sVar6 + sVar9;
  }
  sVar10 = 0;
  if ((char *)param_1[5] != (char *)0x0) {
    sVar10 = strlen((char *)param_1[5]);
    sVar10 = sVar10 + 1;
    sVar6 = sVar6 + sVar10;
  }
  puVar11 = malloc(sVar6);
  if (puVar11 != (undefined8 *)0x0) {
    uVar1 = param_1[1];
    uVar2 = param_1[2];
    uVar3 = param_1[3];
    __dest = puVar11 + 6;
    uVar4 = param_1[4];
    uVar5 = param_1[5];
    pvVar12 = (void *)*param_1;
    *puVar11 = *param_1;
    puVar11[1] = uVar1;
    puVar11[2] = uVar2;
    puVar11[3] = uVar3;
    puVar11[4] = uVar4;
    puVar11[5] = uVar5;
    if (pvVar12 != (void *)0x0) {
      pvVar12 = memcpy(__dest,pvVar12,local_40);
      *puVar11 = pvVar12;
      __dest = (undefined8 *)((long)pvVar12 + local_40);
    }
    if ((void *)param_1[1] != (void *)0x0) {
      pvVar12 = memcpy(__dest,(void *)param_1[1],sVar7);
      puVar11[1] = pvVar12;
      __dest = (undefined8 *)((long)pvVar12 + sVar7);
    }
    if ((void *)param_1[3] != (void *)0x0) {
      pvVar12 = memcpy(__dest,(void *)param_1[3],sVar8);
      puVar11[3] = pvVar12;
      __dest = (undefined8 *)((long)pvVar12 + sVar8);
    }
    if ((void *)param_1[4] != (void *)0x0) {
      pvVar12 = memcpy(__dest,(void *)param_1[4],sVar9);
      puVar11[4] = pvVar12;
      __dest = (undefined8 *)((long)pvVar12 + sVar9);
    }
    if ((void *)param_1[5] != (void *)0x0) {
      pvVar12 = memcpy(__dest,(void *)param_1[5],sVar10);
      puVar11[5] = pvVar12;
    }
  }
  return puVar11;
}



