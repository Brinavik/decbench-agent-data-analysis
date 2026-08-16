// Function: main @ 0x4f60

undefined8 main(undefined4 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_001192b0 = FUN_00106670(*param_2);
  FUN_0010a490(DAT_001192b0);
  FUN_0010a4b0(stderr);
  setlocale(6,"");
  bindtextdomain("shadow","/usr/share/locale");
  textdomain("shadow");
  FUN_00108680(&DAT_001105be,param_1,param_2);
  FUN_00107b30(&DAT_001105c1,param_1,param_2);
  openlog("groupmod",1,0x50);
  iVar2 = FUN_0010fc30(FUN_00106810);
  uVar1 = DAT_001192b0;
  if (iVar2 != 0) {
    uVar5 = dcgettext(0,"%s: Cannot setup cleanup service.\n",5);
    __fprintf_chk(stderr,1,uVar5,uVar1);
                    /* WARNING: Subroutine does not return */
    exit(0xb);
  }
  FUN_00105380(param_1,param_2);
  DAT_00119350 = FUN_0010cae0();
  lVar3 = FUN_00107fb0(DAT_00119348);
  uVar5 = DAT_00119348;
  uVar1 = DAT_001192b0;
  if (lVar3 != 0) {
    DAT_00119334 = *(undefined4 *)(lVar3 + 0x10);
    if (DAT_001192c2 != '\0') {
      FUN_00105520();
    }
    if (DAT_001192c1 != '\0') {
      FUN_001055a0();
    }
    FUN_00105680();
    FUN_00105760();
    FUN_00105c30();
    FUN_001062e0();
    FUN_00105fe0();
    FUN_0010a2d0("group");
    FUN_0010a510(2);
    return 0;
  }
  uVar4 = dcgettext(0,"%s: group \'%s\' does not exist\n",5);
  __fprintf_chk(stderr,1,uVar4,uVar1,uVar5);
                    /* WARNING: Subroutine does not return */
  exit(6);
}



// Function: usage @ 0x5210

void usage(int param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char *pcVar3;
  FILE *__stream;
  
  uVar1 = DAT_001192b0;
  __stream = stderr;
  if (param_1 == 0) {
    __stream = stdout;
  }
  uVar2 = dcgettext(0,"Usage: %s [options] GROUP\n\nOptions:\n",5);
  __fprintf_chk(__stream,1,uVar2,uVar1);
  pcVar3 = (char *)dcgettext(0,
                             "  -a, --append                  append the users mentioned by -U option to the group \n                                without removing existing user members\n"
                             ,5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,"  -g, --gid GID                 change the group ID to GID\n",5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,
                             "  -h, --help                    display this help message and exit\n",
                             5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,"  -n, --new-name NEW_GROUP      change the name to NEW_GROUP\n",5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,
                             "  -o, --non-unique              allow to use a duplicate (non-unique) GID\n"
                             ,5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,
                             "  -p, --password PASSWORD       change the password to this (encrypted)\n                                PASSWORD\n"
                             ,5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,"  -R, --root CHROOT_DIR         directory to chroot into\n",5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,
                             "  -P, --prefix PREFIX_DIR       prefix directory where are located the /etc/* files\n"
                             ,5);
  fputs(pcVar3,__stream);
  pcVar3 = (char *)dcgettext(0,
                             "  -U, --users USERS             list of user members of this group\n",
                             5);
  fputs(pcVar3,__stream);
  fputs("\n",__stream);
                    /* WARNING: Subroutine does not return */
  exit(param_1);
}



// Function: process_flags @ 0x5380

void process_flags(int param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  do {
    iVar3 = getopt_long(param_1,param_2,"ag:hn:op:R:P:U:",&PTR_s_append_00117020,0);
    if (iVar3 == -1) {
      if (((DAT_001192c3 == '\0') || (DAT_001192c2 != '\0')) && (param_1 + -1 == optind)) {
        DAT_00119348 = *(undefined8 *)(param_2 + -8 + (long)param_1 * 8);
        return;
      }
      goto switchD_001053df_caseD_51;
    }
    switch(iVar3) {
    case 0x50:
    case 0x52:
      break;
    default:
switchD_001053df_caseD_51:
                    /* WARNING: Subroutine does not return */
      FUN_00105210(2);
    case 0x55:
      DAT_00119328 = optarg;
      break;
    case 0x61:
      DAT_001192c4 = 1;
      break;
    case 0x67:
      DAT_001192c2 = '\x01';
      iVar3 = FUN_00109570(optarg,&DAT_00119330);
      uVar2 = DAT_001192b0;
      uVar1 = optarg;
      if ((iVar3 == 0) || (DAT_00119330 == -1)) {
        uVar4 = dcgettext(0,"%s: invalid group ID \'%s\'\n",5);
        __fprintf_chk(stderr,1,uVar4,uVar2,uVar1);
                    /* WARNING: Subroutine does not return */
        exit(3);
      }
      break;
    case 0x68:
                    /* WARNING: Subroutine does not return */
      FUN_00105210(0);
    case 0x6e:
      DAT_00119340 = optarg;
      DAT_001192c1 = 1;
      break;
    case 0x6f:
      DAT_001192c3 = '\x01';
      break;
    case 0x70:
      DAT_00119338 = optarg;
      DAT_001192c0 = 1;
    }
  } while( true );
}



// Function: check_new_gid @ 0x5520

undefined8 check_new_gid(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  __gid_t _Var2;
  undefined8 in_RAX;
  group *pgVar3;
  undefined8 uVar4;
  
  if (DAT_00119334 == DAT_00119330) {
    DAT_001192c2 = 0;
    return in_RAX;
  }
  if (DAT_001192c3 != '\0') {
    return in_RAX;
  }
  pgVar3 = getgrgid(DAT_00119330);
  _Var2 = DAT_00119330;
  uVar1 = DAT_001192b0;
  if (pgVar3 == (group *)0x0) {
    return param_3;
  }
  uVar4 = dcgettext(0,"%s: GID \'%lu\' already exists\n",5);
  __fprintf_chk(stderr,1,uVar4,uVar1,_Var2);
                    /* WARNING: Subroutine does not return */
  exit(4);
}



// Function: check_new_name @ 0x55a0

void check_new_name(void)

{
  undefined8 uVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  
  pcVar2 = DAT_00119340;
  iVar4 = strcmp(DAT_00119348,DAT_00119340);
  if (iVar4 == 0) {
    DAT_001192c1 = 0;
  }
  else {
    cVar3 = thunk_FUN_001067d0(pcVar2);
    pcVar2 = DAT_00119340;
    uVar1 = DAT_001192b0;
    if (cVar3 == '\0') {
      uVar6 = dcgettext(0,"%s: invalid group name \'%s\'\n",5);
      __fprintf_chk(stderr,1,uVar6,uVar1,pcVar2);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
    lVar5 = FUN_00107fb0(DAT_00119340);
    pcVar2 = DAT_00119340;
    uVar1 = DAT_001192b0;
    if (lVar5 != 0) {
      uVar6 = dcgettext(0,"%s: group \'%s\' already exists\n",5);
      __fprintf_chk(stderr,1,uVar6,uVar1,pcVar2);
                    /* WARNING: Subroutine does not return */
      exit(9);
    }
  }
  return;
}



// Function: lock_files @ 0x5680

void lock_files(void)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  iVar2 = FUN_00109e90();
  if (iVar2 == 0) {
    uVar4 = FUN_00109e80();
  }
  else {
    FUN_00106890(FUN_00107000,0);
    if ((DAT_00119350 != '\0') && ((DAT_001192c0 != '\0' || (DAT_001192c1 != '\0')))) {
      iVar2 = FUN_0010cb10();
      if (iVar2 == 0) {
        uVar4 = FUN_0010cad0();
        goto LAB_00105705;
      }
      FUN_00106890(FUN_00107100,0);
    }
    if (DAT_001192c2 == '\0') {
      return;
    }
    iVar2 = FUN_0010aad0();
    if (iVar2 != 0) {
      FUN_00106890(FUN_001074d0,0);
      return;
    }
    uVar4 = FUN_0010aac0();
  }
LAB_00105705:
  uVar1 = DAT_001192b0;
  uVar3 = dcgettext(0,"%s: cannot lock %s; try again later.\n",5);
  __fprintf_chk(stderr,1,uVar3,uVar1,uVar4);
                    /* WARNING: Subroutine does not return */
  exit(10);
}



// Function: prepare_failure_reports @ 0x5760

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void prepare_failure_reports(void)

{
  char *pcVar1;
  char *pcVar2;
  char *__s;
  char *pcVar3;
  undefined8 uVar4;
  size_t sVar5;
  size_t sVar6;
  
  _DAT_00119300 = DAT_00119348;
  _DAT_001192e0 = DAT_00119348;
  _DAT_00119320 = DAT_00119348;
  DAT_001192f0 = (char *)FUN_00108800(0x200);
  DAT_001192d0 = (char *)FUN_00108800(0x200);
  DAT_00119310 = (char *)FUN_00108800(0x200);
  uVar4 = FUN_00109e80();
  __snprintf_chk(DAT_001192f0,0x1ff,1,0xffffffffffffffff,"changing %s; ",uVar4);
  uVar4 = FUN_0010cad0();
  __snprintf_chk(DAT_001192d0,0x1ff,1,0xffffffffffffffff,"changing %s; ",uVar4);
  uVar4 = FUN_0010aac0();
  __snprintf_chk(DAT_00119310,0x1ff,1,0xffffffffffffffff,"changing %s; ",uVar4);
  __s = DAT_001192f0;
  sVar5 = strlen(DAT_001192f0);
  pcVar2 = DAT_001192d0;
  pcVar1 = __s + sVar5;
  DAT_001192f8 = pcVar1;
  sVar5 = strlen(DAT_001192d0);
  pcVar3 = DAT_00119310;
  DAT_001192d8 = pcVar2 + sVar5;
  sVar5 = strlen(DAT_00119310);
  DAT_00119318 = pcVar3 + sVar5;
  sVar5 = strlen(__s);
  __snprintf_chk(pcVar1,0x1ff - sVar5,1,0xffffffffffffffff,"group %s/%lu",DAT_00119348,DAT_00119334)
  ;
  sVar5 = strlen(DAT_001192f0);
  __snprintf_chk(DAT_001192d8,0x1ff - sVar5,1,0xffffffffffffffff,"group %s",DAT_00119348);
  sVar5 = strlen(DAT_001192f0);
  __snprintf_chk(DAT_00119318,0x1ff - sVar5,1,0xffffffffffffffff,"group %s/%lu",DAT_00119348,
                 DAT_00119334);
  if (DAT_001192c1 != '\0') {
    sVar5 = strlen(DAT_001192f0);
    strncat(DAT_001192f8,", new name: ",0x1ff - sVar5);
    sVar5 = strlen(DAT_001192f0);
    pcVar1 = DAT_00119340;
    strncat(DAT_001192f8,DAT_00119340,0x1ff - sVar5);
    sVar5 = strlen(DAT_001192d0);
    strncat(DAT_001192d8,", new name: ",0x1ff - sVar5);
    sVar5 = strlen(DAT_001192d0);
    strncat(DAT_001192d8,pcVar1,0x1ff - sVar5);
    sVar5 = strlen(DAT_00119310);
    strncat(DAT_00119318,", new name: ",0x1ff - sVar5);
    sVar5 = strlen(DAT_00119310);
    strncat(DAT_00119318,pcVar1,0x1ff - sVar5);
  }
  if (DAT_001192c0 != '\0') {
    sVar5 = strlen(DAT_001192f0);
    strncat(DAT_001192f8,", new password",0x1ff - sVar5);
    sVar5 = strlen(DAT_001192d0);
    strncat(DAT_001192d8,", new password",0x1ff - sVar5);
  }
  if (DAT_001192c2 != '\0') {
    sVar5 = strlen(DAT_001192f0);
    strncat(DAT_001192f8,", new gid: ",0x1ff - sVar5);
    sVar5 = strlen(DAT_001192f0);
    pcVar1 = DAT_001192f8;
    sVar6 = strlen(DAT_001192f8);
    __snprintf_chk(pcVar1 + sVar6,0x1ff - sVar5,1,0xffffffffffffffff,&DAT_00111410,DAT_00119330);
    sVar5 = strlen(DAT_00119310);
    strncat(DAT_00119318,", new gid: ",0x1ff - sVar5);
    sVar5 = strlen(DAT_00119310);
    pcVar1 = DAT_00119318;
    sVar6 = strlen(DAT_00119318);
    __snprintf_chk(pcVar1 + sVar6,0x1ff - sVar5,1,0xffffffffffffffff,&DAT_00111410,DAT_00119330);
  }
  DAT_001192f0[0x1ff] = '\0';
  DAT_001192d0[0x1ff] = '\0';
  DAT_00119310[0x1ff] = '\0';
  FUN_00106890(FUN_00106bc0,&DAT_001192f0);
  if ((DAT_00119350 != '\0') && ((DAT_001192c0 != '\0' || (DAT_001192c1 != '\0')))) {
    FUN_00106890(FUN_00106c80,&DAT_001192d0);
  }
  if (DAT_001192c2 == '\0') {
    return;
  }
  FUN_00106890(FUN_001072b0,&DAT_00119310);
  return;
}



// Function: open_files @ 0x5c30

void open_files(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  iVar1 = FUN_00109ea0(0x42);
  if (iVar1 == 0) {
    uVar3 = FUN_00109e80();
LAB_00105d24:
    uVar2 = DAT_001192b0;
    uVar4 = dcgettext(0,"%s: cannot open %s\n",5);
    __fprintf_chk(stderr,1,uVar4,uVar2,uVar3);
    pcVar5 = setlocale(6,(char *)0x0);
    if ((pcVar5 != (char *)0x0) && (pcVar5 = strdup(pcVar5), pcVar5 != (char *)0x0)) {
      setlocale(6,"C");
      uVar3 = FUN_00109e80();
LAB_00105d94:
      __syslog_chk(4,1,"cannot open %s",uVar3);
      setlocale(6,pcVar5);
      free(pcVar5);
      goto LAB_00105dc4;
    }
    uVar3 = FUN_00109e80();
  }
  else {
    if ((DAT_00119350 == '\0') ||
       (((DAT_001192c0 == '\0' && (DAT_001192c1 == '\0')) ||
        (iVar1 = FUN_0010cb20(0x42), iVar1 != 0)))) {
      if (DAT_001192c2 == '\0') {
        return;
      }
      iVar1 = FUN_0010aae0(0x42);
      if (iVar1 != 0) {
        return;
      }
      uVar3 = FUN_0010aac0();
      goto LAB_00105d24;
    }
    uVar2 = FUN_0010cad0();
    uVar3 = DAT_001192b0;
    uVar4 = dcgettext(0,"%s: cannot open %s\n",5);
    __fprintf_chk(stderr,1,uVar4,uVar3,uVar2);
    pcVar5 = setlocale(6,(char *)0x0);
    if ((pcVar5 != (char *)0x0) && (pcVar5 = strdup(pcVar5), pcVar5 != (char *)0x0)) {
      setlocale(6,"C");
      uVar3 = FUN_0010cad0();
      goto LAB_00105d94;
    }
    uVar3 = FUN_0010cad0();
  }
  __syslog_chk(4,1,"cannot open %s",uVar3);
LAB_00105dc4:
                    /* WARNING: Subroutine does not return */
  exit(10);
}



// Function: new_grent @ 0x5e10

void new_grent(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (DAT_001192c1 != '\0') {
    uVar2 = FUN_00108870(DAT_00119340);
    *param_1 = uVar2;
  }
  if (DAT_001192c2 != '\0') {
    *(undefined4 *)(param_1 + 2) = DAT_00119330;
  }
  if ((DAT_001192c0 != '\0') &&
     ((DAT_00119350 == '\0' || (iVar1 = strcmp((char *)param_1[1],"x"), iVar1 != 0)))) {
    param_1[1] = DAT_00119338;
  }
  return;
}



// Function: new_sgent @ 0x5e80

void new_sgent(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (DAT_001192c1 != '\0') {
    uVar1 = FUN_00108870(DAT_00119340);
    *param_1 = uVar1;
  }
  if (DAT_001192c0 != '\0') {
    param_1[1] = DAT_00119338;
  }
  return;
}



// Function: update_primary_groups @ 0x5ec0

void update_primary_groups(int param_1,undefined4 param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char *pcVar8;
  long in_FS_OFFSET;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00108230();
  while( true ) {
    do {
      puVar3 = (undefined8 *)FUN_00108290();
      if (puVar3 == (undefined8 *)0x0) {
        if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
          FUN_001082c0();
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
    } while (*(int *)((long)puVar3 + 0x14) != param_1);
    puVar4 = (undefined8 *)FUN_0010ab00(*puVar3);
    if (puVar4 == (undefined8 *)0x0) break;
    local_68 = *puVar4;
    uStack_60 = puVar4[1];
    uStack_50 = puVar4[3];
    local_48 = puVar4[4];
    uStack_40 = puVar4[5];
    _local_58 = CONCAT44(param_2,(int)puVar4[2]);
    iVar2 = FUN_0010ab20(&local_68);
    uVar7 = local_68;
    if (iVar2 == 0) {
      uVar5 = FUN_0010aac0();
      pcVar8 = "%s: failed to prepare the new %s entry \'%s\'\n";
LAB_00105f85:
      uVar1 = DAT_001192b0;
      uVar6 = dcgettext(0,pcVar8,5);
      __fprintf_chk(stderr,1,uVar6,uVar1,uVar5,uVar7);
                    /* WARNING: Subroutine does not return */
      exit(10);
    }
  }
  uVar7 = FUN_0010aac0();
  uVar5 = *puVar3;
  pcVar8 = "%s: user \'%s\' does not exist in %s\n";
  goto LAB_00105f85;
}



// Function: close_files @ 0x5fe0

void close_files(void)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  iVar1 = FUN_00109f70();
  if (iVar1 == 0) {
    uVar5 = FUN_00109e80();
    goto LAB_0010628d;
  }
  pcVar2 = setlocale(6,(char *)0x0);
  if (pcVar2 == (char *)0x0) {
LAB_0010615e:
    uVar5 = DAT_001192f8;
    uVar3 = FUN_00109e80();
    __syslog_chk(6,1,"group changed in %s (%s)",uVar3,uVar5);
  }
  else {
    pcVar2 = strdup(pcVar2);
    if (pcVar2 == (char *)0x0) goto LAB_0010615e;
    setlocale(6,"C");
    uVar5 = DAT_001192f8;
    uVar3 = FUN_00109e80();
    __syslog_chk(6,1,"group changed in %s (%s)",uVar3,uVar5);
    setlocale(6,pcVar2);
    free(pcVar2);
  }
  FUN_00106970(FUN_00106bc0);
  FUN_00107000(0);
  FUN_00106970(FUN_00107000);
  if ((DAT_00119350 != '\0') && ((DAT_001192c0 != '\0' || (DAT_001192c1 != '\0')))) {
    iVar1 = FUN_0010cbc0();
    if (iVar1 == 0) {
      uVar5 = FUN_0010cad0();
      goto LAB_0010628d;
    }
    pcVar2 = setlocale(6,(char *)0x0);
    if (pcVar2 == (char *)0x0) {
LAB_00106235:
      uVar5 = DAT_001192d8;
      uVar3 = FUN_0010cad0();
      __syslog_chk(6,1,"group changed in %s (%s)",uVar3,uVar5);
    }
    else {
      pcVar2 = strdup(pcVar2);
      if (pcVar2 == (char *)0x0) goto LAB_00106235;
      setlocale(6,"C");
      uVar5 = DAT_001192d8;
      uVar3 = FUN_0010cad0();
      __syslog_chk(6,1,"group changed in %s (%s)",uVar3,uVar5);
      setlocale(6,pcVar2);
      free(pcVar2);
    }
    FUN_00106970(FUN_00106c80);
    FUN_00107100(0);
    FUN_00106970(FUN_00107100);
  }
  if (DAT_001192c2 == '\0') {
    return;
  }
  iVar1 = FUN_0010abb0();
  if (iVar1 == 0) {
    uVar5 = FUN_0010aac0();
LAB_0010628d:
    uVar3 = DAT_001192b0;
    uVar4 = dcgettext(0,"%s: failure while writing changes to %s\n",5);
    __fprintf_chk(stderr,1,uVar4,uVar3,uVar5);
                    /* WARNING: Subroutine does not return */
    exit(10);
  }
  pcVar2 = setlocale(6,(char *)0x0);
  if (pcVar2 != (char *)0x0) {
    pcVar2 = strdup(pcVar2);
    if (pcVar2 != (char *)0x0) {
      setlocale(6,"C");
      uVar5 = DAT_00119318;
      uVar3 = FUN_0010aac0();
      __syslog_chk(6,1,"group changed in %s (%s)",uVar3,uVar5);
      setlocale(6,pcVar2);
      free(pcVar2);
      goto LAB_00106212;
    }
  }
  uVar5 = DAT_00119318;
  uVar3 = FUN_0010aac0();
  __syslog_chk(6,1,"group changed in %s (%s)",uVar3,uVar5);
LAB_00106212:
  FUN_00106970(FUN_001072b0);
  FUN_001074d0(0);
  FUN_00106970(FUN_001074d0);
  return;
}



// Function: grp_update @ 0x62e0

void grp_update(void)

{
  int iVar1;
  undefined8 *puVar2;
  char *pcVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  long in_FS_OFFSET;
  byte bVar11;
  undefined8 local_78;
  char *pcStack_70;
  undefined8 local_68;
  long *plStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined *local_48;
  undefined8 uStack_40;
  long local_30;
  
  bVar11 = 0;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  puVar2 = (undefined8 *)FUN_00109ec0(DAT_00119348);
  if (puVar2 == (undefined8 *)0x0) {
    uVar6 = FUN_00109e80();
    pcVar3 = "%s: group \'%s\' does not exist in %s\n";
    uVar8 = DAT_00119348;
  }
  else {
    local_78 = *puVar2;
    pcStack_70 = (char *)puVar2[1];
    local_68 = puVar2[2];
    plStack_60 = (long *)puVar2[3];
    FUN_00105e10(&local_78);
    if ((DAT_00119350 == '\0') || ((DAT_001192c0 == '\0' && (DAT_001192c1 == '\0')))) {
LAB_0010633c:
      puVar5 = (undefined8 *)0x0;
    }
    else {
      puVar5 = (undefined8 *)FUN_0010cb40(DAT_00119348);
      if (puVar5 == (undefined8 *)0x0) {
        if ((DAT_001192c0 == '\0') || (iVar1 = strcmp(pcStack_70,"x"), iVar1 != 0))
        goto LAB_0010633c;
        puVar5 = &local_58;
        puVar9 = puVar5;
        for (lVar4 = 8; lVar4 != 0; lVar4 = lVar4 + -1) {
          *(undefined4 *)puVar9 = 0;
          puVar9 = (undefined8 *)((long)puVar9 + (ulong)bVar11 * -8 + 4);
        }
        local_58 = FUN_00108870(local_78);
        uStack_50 = FUN_00108870(pcStack_70);
        local_48 = &DAT_001192b8;
        uStack_40 = FUN_00107910(plStack_60);
        FUN_00105e80(puVar5);
      }
      else {
        local_58 = *puVar5;
        uStack_50 = puVar5[1];
        local_48 = (undefined *)puVar5[2];
        uStack_40 = puVar5[3];
        FUN_00105e80(&local_58);
      }
    }
    if (DAT_001192c2 != '\0') {
      FUN_00105ec0(*(undefined4 *)(puVar2 + 2),DAT_00119330);
    }
    if (DAT_00119328 != (char *)0x0) {
      if (DAT_001192c4 == '\0') {
        if (*plStack_60 != 0) {
          FUN_0010a000(&local_78);
        }
        plStack_60 = (long *)FUN_00108800(8);
        *plStack_60 = 0;
      }
      else if (*plStack_60 != 0) {
        plStack_60 = (long *)FUN_00107910();
      }
      pcVar3 = strtok(DAT_00119328,",");
      while (pcVar3 != (char *)0x0) {
        lVar4 = FUN_00108130(pcVar3);
        if (lVar4 == 0) {
          uVar6 = dcgettext(0,"Invalid member username %s\n",5);
          __fprintf_chk(stderr,1,uVar6,pcVar3);
                    /* WARNING: Subroutine does not return */
          exit(10);
        }
        plStack_60 = (long *)FUN_001076d0(plStack_60,pcVar3);
        pcVar3 = strtok((char *)0x0,",");
      }
    }
    iVar1 = FUN_00109ee0(&local_78);
    uVar6 = local_78;
    if (iVar1 == 0) {
      uVar8 = FUN_00109e80();
LAB_00106629:
      uVar10 = DAT_001192b0;
      uVar7 = dcgettext(0,"%s: failed to prepare the new %s entry \'%s\'\n",5);
      goto LAB_001065ff;
    }
    if ((DAT_001192c1 == '\0') || (iVar1 = FUN_00109f00(DAT_00119348), iVar1 != 0)) {
      if (puVar5 == (undefined8 *)0x0) {
LAB_00106416:
        if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      iVar1 = FUN_0010cb60(&local_58);
      uVar6 = local_58;
      if (iVar1 == 0) {
        uVar8 = FUN_0010cad0();
        goto LAB_00106629;
      }
      if ((DAT_001192c1 == '\0') || (iVar1 = FUN_0010cb80(DAT_00119348), iVar1 != 0))
      goto LAB_00106416;
      uVar6 = FUN_0010cad0();
      uVar8 = DAT_00119348;
    }
    else {
      uVar6 = FUN_00109e80();
      uVar8 = local_78;
    }
    pcVar3 = "%s: cannot remove entry \'%s\' from %s\n";
  }
  uVar10 = DAT_001192b0;
  uVar7 = dcgettext(0,pcVar3,5);
LAB_001065ff:
  __fprintf_chk(stderr,1,uVar7,uVar10,uVar8,uVar6);
                    /* WARNING: Subroutine does not return */
  exit(10);
}



