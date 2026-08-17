// Function: main @ 0x2400

undefined8 main(int param_1,undefined8 *param_2)

{
  bool bVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  long lVar6;
  FILE *pFVar7;
  uint uVar8;
  char *pcVar9;
  long in_FS_OFFSET;
  bool bVar10;
  undefined4 local_58;
  undefined1 local_54;
  long local_40;
  
  pcVar9 = (char *)*param_2;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = 0x20366277;
  local_54 = 0;
  DAT_00117050 = pcVar9;
  pcVar5 = strrchr(pcVar9,0x2f);
  if (pcVar5 != (char *)0x0) {
    pcVar9 = pcVar5 + 1;
  }
  uVar8 = param_1 - 1;
  param_2 = param_2 + 1;
  iVar4 = strcmp(pcVar9,"gunzip");
  bVar10 = true;
  bVar1 = false;
  if (iVar4 != 0) {
    iVar4 = strcmp(pcVar9,"zcat");
    bVar10 = iVar4 == 0;
    bVar1 = bVar10;
  }
  puVar2 = param_2;
  uVar3 = uVar8;
  if ((int)uVar8 < 1) {
    if (local_58._3_1_ == ' ') goto LAB_00102631;
LAB_00102636:
    if (uVar8 != 0) {
LAB_0010263e:
      puVar2 = param_2 + uVar8;
      do {
        pcVar9 = (char *)*param_2;
        if (bVar10) {
          if (bVar1) {
            lVar6 = FUN_00103320(pcVar9,&DAT_0010f058);
            if (lVar6 == 0) {
              __fprintf_chk(stderr,1,"%s: can\'t gzopen %s\n",DAT_00117050,*param_2);
            }
            else {
              FUN_001029a0(lVar6,stdout);
            }
          }
          else {
            FUN_00102bf0();
          }
        }
        else if (bVar1) {
          pFVar7 = fopen64(pcVar9,"rb");
          if (pFVar7 == (FILE *)0x0) {
            perror((char *)*param_2);
          }
          else {
            iVar4 = fileno(stdout);
            lVar6 = FUN_00103350(iVar4,&local_58);
            if (lVar6 == 0) goto LAB_0010274a;
            FUN_001028a0(pFVar7,lVar6);
          }
        }
        else {
          FUN_00102aa0(pcVar9,&local_58);
        }
        param_2 = param_2 + 1;
      } while (param_2 != puVar2);
      goto LAB_00102557;
    }
  }
  else {
    do {
      while( true ) {
        uVar8 = uVar3;
        param_2 = puVar2;
        pcVar9 = (char *)*param_2;
        iVar4 = strcmp(pcVar9,"-c");
        if (iVar4 != 0) break;
        bVar1 = true;
        puVar2 = param_2 + 1;
        uVar3 = uVar8 - 1;
        if (uVar8 - 1 == 0) goto LAB_00102511;
      }
      iVar4 = strcmp(pcVar9,"-d");
      if (iVar4 == 0) {
        bVar10 = true;
      }
      else {
        iVar4 = strcmp(pcVar9,"-f");
        if (iVar4 == 0) {
          local_58 = CONCAT13(0x66,(undefined3)local_58);
        }
        else {
          iVar4 = strcmp(pcVar9,"-h");
          if (iVar4 == 0) {
            local_58 = CONCAT13(0x68,(undefined3)local_58);
          }
          else {
            iVar4 = strcmp(pcVar9,"-r");
            if (iVar4 == 0) {
              local_58 = CONCAT13(0x52,(undefined3)local_58);
            }
            else {
              if (((*pcVar9 != '-') || (8 < (byte)(pcVar9[1] - 0x31U))) || (pcVar9[2] != '\0')) {
                if (local_58._3_1_ != ' ') goto LAB_0010263e;
                goto LAB_00102631;
              }
              local_58._0_3_ = CONCAT12(pcVar9[1],(undefined2)local_58);
            }
          }
        }
      }
      puVar2 = param_2 + 1;
      uVar3 = uVar8 - 1;
    } while (uVar8 - 1 != 0);
LAB_00102511:
    uVar8 = uVar8 - 1;
    param_2 = param_2 + 1;
    if (local_58._3_1_ == ' ') {
LAB_00102631:
      local_58 = local_58 & 0xffffff;
      goto LAB_00102636;
    }
  }
  if (bVar10) {
    iVar4 = fileno(stdin);
    lVar6 = FUN_00103350(iVar4,&DAT_0010f058);
    if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      error("can\'t gzdopen stdin");
    }
    FUN_001029a0(lVar6,stdout);
  }
  else {
    iVar4 = fileno(stdout);
    lVar6 = FUN_00103350(iVar4,&local_58);
    if (lVar6 == 0) {
LAB_0010274a:
                    /* WARNING: Subroutine does not return */
      error("can\'t gzdopen stdout",0);
    }
    FUN_001028a0(stdin);
  }
LAB_00102557:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// Function: error @ 0x2860

void error(undefined8 param_1)

{
  __fprintf_chk(stderr,1,"%s: %s\n",DAT_00117050,param_1);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: gz_compress @ 0x28a0

void gz_compress(FILE *param_1,undefined8 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  size_t sVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  long in_FS_OFFSET;
  undefined1 local_4028 [16384];
  
  puVar1 = &stack0xffffffffffffffd8;
  do {
    puVar5 = puVar1;
    *(undefined8 *)(puVar5 + -0x1000) = *(undefined8 *)(puVar5 + -0x1000);
    puVar1 = puVar5 + -0x1000;
  } while (puVar5 + -0x1000 != local_4028);
  *(undefined8 *)(puVar5 + 0x2ff8) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  while( true ) {
    *(undefined8 *)(puVar5 + -0x1028) = 0x102916;
    sVar3 = fread(puVar5 + -0x1010,1,0x4000,param_1);
    *(undefined8 *)(puVar5 + -0x1028) = 0x102921;
    iVar2 = ferror(param_1);
    if (iVar2 != 0) {
      *(undefined8 *)(puVar5 + -0x1028) = 0x10296c;
      perror("fread");
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar5 + -0x1028) = 0x102976;
      exit(1);
    }
    if ((int)sVar3 == 0) break;
    *(undefined8 *)(puVar5 + -0x1028) = 0x1028fd;
    iVar2 = FUN_00104910(param_2,puVar5 + -0x1010,sVar3 & 0xffffffff);
    if (iVar2 != (int)sVar3) {
      *(undefined8 *)(puVar5 + -0x1028) = 0x102983;
      uVar4 = FUN_00102ef0(param_2,puVar5 + -0x1014);
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar5 + -0x1028) = 0x10298b;
      error(uVar4);
    }
  }
  *(undefined8 *)(puVar5 + -0x1028) = 0x102931;
  fclose(param_1);
  *(undefined8 *)(puVar5 + -0x1028) = 0x102939;
  iVar2 = FUN_00102d90(param_2);
  if (iVar2 == 0) {
    if (*(long *)(puVar5 + 0x2ff8) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    *(undefined8 *)(puVar5 + -0x1028) = 0x102990;
    __stack_chk_fail();
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar5 + -0x1028) = &UNK_0010299c;
  error("failed gzclose");
}



// Function: gz_uncompress @ 0x29a0

void gz_uncompress(undefined8 param_1,FILE *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  size_t sVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  long in_FS_OFFSET;
  undefined1 local_4020 [16384];
  
  puVar1 = &stack0xffffffffffffffe0;
  do {
    puVar5 = puVar1;
    *(undefined8 *)(puVar5 + -0x1000) = *(undefined8 *)(puVar5 + -0x1000);
    puVar1 = puVar5 + -0x1000;
  } while (puVar5 + -0x1000 != local_4020);
  *(undefined8 *)(puVar5 + 0x2ff0) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  while( true ) {
    *(undefined8 *)(puVar5 + -0x1030) = 0x102a17;
    iVar2 = FUN_00103e00(param_1,puVar5 + -0x1018,0x4000);
    if (iVar2 < 0) {
      *(undefined8 *)(puVar5 + -0x1030) = 0x102a65;
      uVar4 = FUN_00102ef0(param_1,puVar5 + -0x101c);
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar5 + -0x1030) = 0x102a6d;
      error(uVar4);
    }
    if (iVar2 == 0) break;
    *(undefined8 *)(puVar5 + -0x1030) = 0x102a03;
    sVar3 = fwrite(puVar5 + -0x1018,1,(long)iVar2,param_2);
    if (iVar2 != (int)sVar3) {
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar5 + -0x1030) = 0x102a79;
      error("failed fwrite");
    }
  }
  *(undefined8 *)(puVar5 + -0x1030) = 0x102a27;
  iVar2 = fclose(param_2);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    *(undefined8 *)(puVar5 + -0x1030) = 0x102a85;
    error("failed fclose");
  }
  *(undefined8 *)(puVar5 + -0x1030) = 0x102a33;
  iVar2 = FUN_00102d90(param_1);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar5 + -0x1030) = &UNK_00102a96;
    error("failed gzclose");
  }
  if (*(long *)(puVar5 + 0x2ff0) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar5 + -0x1030) = 0x102a8a;
  __stack_chk_fail();
}



// Function: file_compress @ 0x2aa0

void file_compress(char *param_1,undefined8 param_2)

{
  size_t sVar1;
  size_t sVar2;
  FILE *pFVar3;
  long lVar4;
  long in_FS_OFFSET;
  undefined1 auStack_438 [1032];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sVar1 = strlen(param_1);
  sVar2 = strlen(".gz");
  if (0x3ff < sVar1 + sVar2) {
    __fprintf_chk(stderr,1,"%s: filename too long\n",DAT_00117050);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __snprintf_chk(auStack_438,0x400,1,0x400,&DAT_0010f0c7,param_1,&DAT_0010f03d);
  pFVar3 = fopen64(param_1,"rb");
  if (pFVar3 == (FILE *)0x0) {
    perror(param_1);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  lVar4 = FUN_00103320(auStack_438,param_2);
  if (lVar4 == 0) {
    __fprintf_chk(stderr,1,"%s: can\'t gzopen %s\n",DAT_00117050,auStack_438);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  FUN_001028a0(pFVar3,lVar4);
  unlink(param_1);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: file_uncompress @ 0x2bf0

void file_uncompress(char *param_1)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  long lVar4;
  FILE *pFVar5;
  char *__name;
  char *__filename;
  long in_FS_OFFSET;
  undefined8 uStack_450;
  char acStack_448 [1032];
  long local_40;
  
  __filename = acStack_448;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uStack_450 = (undefined *)0x102c27;
  sVar2 = strlen(param_1);
  uStack_450 = (undefined *)0x102c32;
  sVar3 = strlen(".gz");
  if (0x3ff < sVar3 + sVar2) {
    uStack_450 = (undefined *)0x102d36;
    __fprintf_chk(stderr,1,"%s: filename too long\n",DAT_00117050);
                    /* WARNING: Subroutine does not return */
    uStack_450 = (undefined *)0x102d40;
    exit(1);
  }
  uStack_450 = (undefined *)0x102c60;
  snprintf(acStack_448,0x400,"%s",param_1);
  if (3 < sVar2) {
    uStack_450 = (undefined *)0x102c77;
    iVar1 = strcmp(param_1 + (sVar2 - 3),".gz");
    if (iVar1 == 0) {
      acStack_448[sVar2 - 3] = '\0';
      __name = param_1;
      goto LAB_00102c9e;
    }
  }
  uStack_450 = (undefined *)0x102c9e;
  snprintf(acStack_448 + sVar2,0x400 - sVar2,"%s",&DAT_0010f03d);
  __name = acStack_448;
  __filename = param_1;
LAB_00102c9e:
  uStack_450 = (undefined *)0x102cad;
  lVar4 = FUN_00103320(__name,&DAT_0010f058);
  if (lVar4 == 0) {
    uStack_450 = (undefined *)0x102d7b;
    __fprintf_chk(stderr,1,"%s: can\'t gzopen %s\n",DAT_00117050,__name);
                    /* WARNING: Subroutine does not return */
    uStack_450 = &UNK_00102d85;
    exit(1);
  }
  uStack_450 = (undefined *)0x102cc8;
  pFVar5 = fopen64(__filename,"wb");
  if (pFVar5 != (FILE *)0x0) {
    uStack_450 = (undefined *)0x102cd8;
    FUN_001029a0(lVar4,pFVar5);
    uStack_450 = (undefined *)0x102ce0;
    unlink(__name);
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    uStack_450 = (undefined *)0x102d45;
    __stack_chk_fail();
  }
  uStack_450 = (undefined *)0x102d4d;
  perror(param_1);
                    /* WARNING: Subroutine does not return */
  uStack_450 = (undefined *)0x102d57;
  exit(1);
}



// Function: gzclose @ 0x2d90

undefined8 gzclose(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0xfffffffe;
  }
  if (*(int *)(param_1 + 0x18) != 0x1c4f) {
    uVar1 = FUN_00104f30();
    return uVar1;
  }
  uVar1 = FUN_001042c0();
  return uVar1;
}



// Function: gzbuffer @ 0x2dc0

undefined8 gzbuffer(long param_1,uint param_2)

{
  if (((param_1 != 0) &&
      (((*(int *)(param_1 + 0x18) == 0x1c4f || (*(int *)(param_1 + 0x18) == 0x79b1)) &&
       (*(int *)(param_1 + 0x28) == 0)))) && (param_2 <= param_2 * 2)) {
    if (param_2 < 2) {
      param_2 = 2;
    }
    *(uint *)(param_1 + 0x2c) = param_2;
    return 0;
  }
  return 0xffffffff;
}



// Function: gztell64 @ 0x2e10

long gztell64(long param_1)

{
  long lVar1;
  
  if ((param_1 == 0) ||
     ((*(int *)(param_1 + 0x18) != 0x1c4f && (*(int *)(param_1 + 0x18) != 0x79b1)))) {
    lVar1 = -1;
  }
  else {
    lVar1 = *(long *)(param_1 + 0x10);
    if (*(int *)(param_1 + 0x70) != 0) {
      return lVar1 + *(long *)(param_1 + 0x68);
    }
  }
  return lVar1;
}



// Function: gzoffset64 @ 0x2e60

__off64_t gzoffset64(long param_1)

{
  __off64_t _Var1;
  
  if (param_1 == 0) {
    return -1;
  }
  if ((*(int *)(param_1 + 0x18) == 0x1c4f) || (*(int *)(param_1 + 0x18) == 0x79b1)) {
    _Var1 = lseek64(*(int *)(param_1 + 0x1c),0,1);
    if (_Var1 != -1) {
      if (*(int *)(param_1 + 0x18) != 0x1c4f) {
        return _Var1;
      }
      return _Var1 - (ulong)*(uint *)(param_1 + 0x88);
    }
  }
  return -1;
}



// Function: gzeof @ 0x2ed0

undefined4 gzeof(long param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0x1c4f)) {
    return *(undefined4 *)(param_1 + 0x54);
  }
  return 0;
}



// Function: gzerror @ 0x2ef0

char * gzerror(long param_1,undefined4 *param_2)

{
  char *pcVar1;
  
  if (param_1 == 0) {
    pcVar1 = (char *)0x0;
  }
  else if ((*(int *)(param_1 + 0x18) == 0x1c4f) ||
          (pcVar1 = (char *)0x0, *(int *)(param_1 + 0x18) == 0x79b1)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x74);
    }
    pcVar1 = "out of memory";
    if (*(int *)(param_1 + 0x74) != -4) {
      pcVar1 = *(char **)(param_1 + 0x78);
      if (pcVar1 == (char *)0x0) {
        pcVar1 = "";
      }
      return pcVar1;
    }
  }
  return pcVar1;
}



// Function: gz_error @ 0x2f50

void gz_error(undefined4 *param_1,int param_2,char *param_3)

{
  char *__s;
  size_t sVar1;
  size_t sVar2;
  void *pvVar3;
  
  if (*(void **)(param_1 + 0x1e) != (void *)0x0) {
    if (param_1[0x1d] != -4) {
      free(*(void **)(param_1 + 0x1e));
    }
    *(undefined8 *)(param_1 + 0x1e) = 0;
  }
  if ((param_2 != 0) && (param_2 != -5)) {
    *param_1 = 0;
  }
  param_1[0x1d] = param_2;
  if ((param_2 != -4) && (param_3 != (char *)0x0)) {
    sVar1 = strlen(*(char **)(param_1 + 8));
    sVar2 = strlen(param_3);
    pvVar3 = malloc(sVar1 + 3 + sVar2);
    *(void **)(param_1 + 0x1e) = pvVar3;
    if (pvVar3 == (void *)0x0) {
      param_1[0x1d] = 0xfffffffc;
    }
    else {
      __s = *(char **)(param_1 + 8);
      sVar1 = strlen(__s);
      sVar2 = strlen(param_3);
      __snprintf_chk(pvVar3,sVar1 + 3 + sVar2,1,0xffffffffffffffff,&DAT_0010f0c5,__s,&DAT_0010f0cc,
                     param_3);
    }
  }
  return;
}



// Function: gz_reset @ 0x3040

void gz_reset(undefined4 *param_1)

{
  *param_1 = 0;
  if (param_1[6] == 0x1c4f) {
    *(undefined8 *)(param_1 + 0x14) = 0;
    param_1[0x11] = 0;
  }
  else {
    param_1[0x18] = 0;
  }
  param_1[0x1c] = 0;
  FUN_00102f50(param_1,0,0);
  *(undefined8 *)(param_1 + 4) = 0;
  param_1[0x22] = 0;
  return;
}



// Function: gz_open @ 0x30a0

void * gz_open(char *param_1,int param_2,char *param_3)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  void *__ptr;
  size_t sVar5;
  char *__s;
  __off64_t _Var6;
  uint uVar7;
  int iVar8;
  uint __oflag;
  
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  __ptr = malloc(0xf0);
  if (__ptr == (void *)0x0) {
    return (void *)0x0;
  }
  iVar8 = 0;
  *(undefined8 *)((long)__ptr + 0x78) = 0;
  *(undefined8 *)((long)__ptr + 0x28) = 0x200000000000;
  *(undefined8 *)((long)__ptr + 0x58) = 0xffffffff;
  cVar3 = *param_3;
  *(undefined4 *)((long)__ptr + 0x18) = 0;
  *(undefined4 *)((long)__ptr + 0x40) = 0;
  bVar2 = false;
  if (cVar3 != '\0') {
LAB_00103134:
    do {
      bVar1 = bVar2;
      if ((byte)(cVar3 - 0x30U) < 10) {
        *(int *)((long)__ptr + 0x58) = (int)(char)(cVar3 - 0x30U);
        goto switchD_0010314d_caseD_2c;
      }
      switch(cVar3) {
      case '+':
        goto switchD_0010314d_caseD_2b;
      case 'F':
        *(undefined4 *)((long)__ptr + 0x5c) = 4;
        break;
      case 'R':
        *(undefined4 *)((long)__ptr + 0x5c) = 3;
        break;
      case 'T':
        *(undefined4 *)((long)__ptr + 0x40) = 1;
        break;
      case 'a':
        *(undefined4 *)((long)__ptr + 0x18) = 1;
        break;
      case 'e':
        iVar8 = 1;
        break;
      case 'f':
        *(undefined4 *)((long)__ptr + 0x5c) = 1;
        break;
      case 'h':
        *(undefined4 *)((long)__ptr + 0x5c) = 2;
        break;
      case 'r':
        *(undefined4 *)((long)__ptr + 0x18) = 0x1c4f;
        break;
      case 'w':
        *(undefined4 *)((long)__ptr + 0x18) = 0x79b1;
        break;
      case 'x':
        goto switchD_0010314d_caseD_78;
      }
switchD_0010314d_caseD_2c:
      cVar3 = param_3[1];
      param_3 = param_3 + 1;
      bVar2 = bVar1;
    } while (cVar3 != '\0');
    goto LAB_00103190;
  }
switchD_0010314d_caseD_2b:
  free(__ptr);
  return (void *)0x0;
switchD_0010314d_caseD_78:
  cVar3 = param_3[1];
  param_3 = param_3 + 1;
  bVar1 = true;
  bVar2 = true;
  if (cVar3 == '\0') goto LAB_00103190;
  goto LAB_00103134;
LAB_00103190:
  if (*(int *)((long)__ptr + 0x18) != 0) {
    if (*(int *)((long)__ptr + 0x18) == 0x1c4f) {
      if (*(int *)((long)__ptr + 0x40) != 0) goto switchD_0010314d_caseD_2b;
      *(undefined4 *)((long)__ptr + 0x40) = 1;
    }
    sVar5 = strlen(param_1);
    __s = malloc(sVar5 + 1);
    *(char **)((long)__ptr + 0x20) = __s;
    if (__s != (char *)0x0) {
      snprintf(__s,sVar5 + 1,"%s",param_1);
      iVar4 = *(int *)((long)__ptr + 0x18);
      __oflag = iVar8 << 0x13;
      if (iVar4 != 0x1c4f) {
        uVar7 = 0x400;
        if (iVar4 == 0x79b1) {
          uVar7 = 0x200;
        }
        __oflag = __oflag | (-(uint)!bVar1 & 0xffffff80) + 0xc1 | uVar7;
      }
      if (param_2 < 0) {
        param_2 = open(param_1,__oflag,0x1b6);
        *(int *)((long)__ptr + 0x1c) = param_2;
        if (param_2 == -1) {
          free(*(void **)((long)__ptr + 0x20));
          goto switchD_0010314d_caseD_2b;
        }
        iVar4 = *(int *)((long)__ptr + 0x18);
      }
      else {
        *(int *)((long)__ptr + 0x1c) = param_2;
      }
      if (iVar4 == 1) {
        lseek64(param_2,0,2);
        *(undefined4 *)((long)__ptr + 0x18) = 0x79b1;
      }
      else if (iVar4 == 0x1c4f) {
        _Var6 = lseek64(*(int *)((long)__ptr + 0x1c),0,1);
        if (_Var6 == -1) {
          _Var6 = 0;
        }
        *(__off64_t *)((long)__ptr + 0x48) = _Var6;
      }
      FUN_00103040(__ptr);
      return __ptr;
    }
  }
  goto switchD_0010314d_caseD_2b;
}



// Function: gzopen64 @ 0x3320

void gzopen64(undefined8 param_1,undefined8 param_2)

{
  FUN_001030a0(param_1,0xffffffff,param_2);
  return;
}



// Function: gzdopen @ 0x3350

undefined8 gzdopen(int param_1,undefined8 param_2)

{
  void *__ptr;
  undefined8 uVar1;
  
  if (param_1 != -1) {
    __ptr = malloc(0x13);
    if (__ptr != (void *)0x0) {
      __snprintf_chk(__ptr,0x13,1,0x13,"<fd:%d>",param_1);
      uVar1 = FUN_001030a0(__ptr,param_1,param_2);
      free(__ptr);
      return uVar1;
    }
  }
  return 0;
}



// Function: gzrewind @ 0x33d0

undefined8 gzrewind(long param_1)

{
  __off64_t _Var1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 0x18) == 0x1c4f) &&
     ((*(int *)(param_1 + 0x74) == 0 || (*(int *)(param_1 + 0x74) == -5)))) {
    _Var1 = lseek64(*(int *)(param_1 + 0x1c),*(__off64_t *)(param_1 + 0x48),0);
    if (_Var1 != -1) {
      FUN_00103040(param_1);
      return 0;
    }
  }
  return 0xffffffff;
}



// Function: gzseek64 @ 0x3430

long gzseek64(uint *param_1,ulong param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  __off64_t _Var4;
  ulong uVar5;
  uint uVar6;
  
  if (param_1 == (uint *)0x0) {
    return -1;
  }
  uVar6 = param_1[6];
  if ((uVar6 != 0x1c4f) && (uVar6 != 0x79b1)) {
    return -1;
  }
  if ((param_1[0x1d] != 0) && (param_1[0x1d] != 0xfffffffb)) {
    return -1;
  }
  if (1 < param_3) {
    return -1;
  }
  if (param_3 == 0) {
    param_1[0x1c] = 0;
    param_2 = param_2 - *(long *)(param_1 + 4);
  }
  else {
    if (param_1[0x1c] != 0) {
      param_2 = param_2 + *(long *)(param_1 + 0x1a);
    }
    param_1[0x1c] = 0;
  }
  if (uVar6 == 0x1c4f) {
    lVar2 = *(long *)(param_1 + 4);
    if (param_1[0x11] == 1) {
      if (-1 < (long)(param_2 + lVar2)) {
        _Var4 = lseek64(param_1[7],param_2 - *param_1,1);
        if (_Var4 == -1) {
          return -1;
        }
        *param_1 = 0;
        param_1[0x14] = 0;
        param_1[0x15] = 0;
        param_1[0x1c] = 0;
        FUN_00102f50(param_1,0,0);
        lVar2 = *(long *)(param_1 + 4);
        param_1[0x22] = 0;
        *(ulong *)(param_1 + 4) = lVar2 + param_2;
        return lVar2 + param_2;
      }
      if ((long)param_2 < 0) {
        return -1;
      }
    }
    else if ((long)param_2 < 0) {
      param_2 = param_2 + lVar2;
      if ((long)param_2 < 0) {
        return -1;
      }
      iVar1 = FUN_001033d0(param_1);
      if (iVar1 == -1) {
        return -1;
      }
      lVar2 = *(long *)(param_1 + 4);
      if (param_1[6] != 0x1c4f) goto LAB_001034a1;
    }
    uVar3 = (ulong)*param_1;
    uVar6 = 0;
    uVar5 = uVar3;
    if ((long)param_2 < (long)uVar3) {
      uVar3 = param_2 & 0xffffffff;
      uVar6 = *param_1 - (int)param_2;
      uVar5 = param_2;
    }
    *(ulong *)(param_1 + 2) = *(long *)(param_1 + 2) + uVar3;
    lVar2 = uVar5 + lVar2;
    param_2 = param_2 - uVar5;
    *param_1 = uVar6;
    *(long *)(param_1 + 4) = lVar2;
  }
  else {
    if ((long)param_2 < 0) {
      return -1;
    }
    lVar2 = *(long *)(param_1 + 4);
  }
LAB_001034a1:
  if (param_2 != 0) {
    param_1[0x1c] = 1;
    *(ulong *)(param_1 + 0x1a) = param_2;
  }
  return lVar2 + param_2;
}



// Function: gzclearerr @ 0x35c0

void gzclearerr(long param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x18) == 0x1c4f) {
      *(undefined8 *)(param_1 + 0x50) = 0;
      FUN_00102f50(param_1,0,0);
      return;
    }
    if (*(int *)(param_1 + 0x18) == 0x79b1) {
      FUN_00102f50(param_1,0,0);
      return;
    }
  }
  return;
}



// Function: gz_load @ 0x3610

ulong gz_load(long param_1,long param_2,uint param_3,uint *param_4)

{
  int iVar1;
  ulong uVar2;
  int *piVar3;
  char *pcVar4;
  uint uVar5;
  size_t __nbytes;
  
  uVar2 = 0;
  *param_4 = 0;
  while( true ) {
    uVar5 = param_3 - (int)uVar2;
    __nbytes = (size_t)uVar5;
    if (0x40000000 < uVar5) {
      __nbytes = 0x40000000;
    }
    uVar2 = read(*(int *)(param_1 + 0x1c),(void *)(param_2 + uVar2),__nbytes);
    iVar1 = (int)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if (iVar1 < 1) break;
    uVar5 = iVar1 + *param_4;
    uVar2 = (ulong)uVar5;
    *param_4 = uVar5;
    if (param_3 <= uVar5) {
      return 0;
    }
  }
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x50) = 1;
  }
  else {
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    FUN_00102f50(param_1,0xffffffff,pcVar4);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



// Function: gz_avail @ 0x36c0

undefined4 gz_avail(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  undefined4 uVar7;
  long in_FS_OFFSET;
  int local_24;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x74) == -5)) {
    if (*(int *)(param_1 + 0x50) != 0) {
      uVar7 = 0;
      goto LAB_00103763;
    }
    uVar1 = *(uint *)(param_1 + 0x88);
    uVar6 = 0;
    if (uVar1 != 0) {
      lVar2 = *(long *)(param_1 + 0x30);
      lVar3 = *(long *)(param_1 + 0x80);
      uVar5 = 0;
      do {
        *(undefined1 *)(lVar2 + uVar5) = *(undefined1 *)(lVar3 + uVar5);
        uVar5 = uVar5 + 1;
      } while (uVar1 != uVar5);
      uVar6 = *(uint *)(param_1 + 0x88);
    }
    iVar4 = FUN_00103610(param_1,(ulong)uVar6 + *(long *)(param_1 + 0x30),
                         *(int *)(param_1 + 0x28) - uVar6,&local_24);
    if (iVar4 != -1) {
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + local_24;
      *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_1 + 0x30);
      uVar7 = 0;
      goto LAB_00103763;
    }
  }
  uVar7 = 0xffffffff;
LAB_00103763:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: gz_look @ 0x3790

undefined8 gz_look(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined8 uVar5;
  size_t __n;
  
  if (param_1[10] == 0) {
    pvVar4 = malloc((ulong)(uint)param_1[0xb]);
    *(void **)(param_1 + 0xc) = pvVar4;
    pvVar4 = malloc((ulong)(uint)(param_1[0xb] * 2));
    *(void **)(param_1 + 0xe) = pvVar4;
    if ((*(long *)(param_1 + 0xc) == 0) || (pvVar4 == (void *)0x0)) {
      free(pvVar4);
      free(*(void **)(param_1 + 0xc));
LAB_001038e5:
      FUN_00102f50(param_1,0xfffffffc,"out of memory");
      return 0xffffffff;
    }
    *(undefined8 *)(param_1 + 0x30) = 0;
    param_1[10] = param_1[0xb];
    *(undefined8 *)(param_1 + 0x32) = 0;
    *(undefined8 *)(param_1 + 0x34) = 0;
    param_1[0x22] = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    iVar3 = FUN_00108b80(param_1 + 0x20,0x1f,"1.2.13",0x70);
    if (iVar3 != 0) {
      free(*(void **)(param_1 + 0xe));
      free(*(void **)(param_1 + 0xc));
      param_1[10] = 0;
      goto LAB_001038e5;
    }
  }
  __n = (size_t)(uint)param_1[0x22];
  if ((uint)param_1[0x22] < 2) {
    uVar5 = FUN_001036c0(param_1);
    if ((int)uVar5 == -1) {
      return uVar5;
    }
    uVar2 = param_1[0x22];
    __n = (size_t)uVar2;
    if (uVar2 == 0) {
      return 0;
    }
    if (uVar2 == 1) {
      iVar3 = param_1[0x10];
      goto joined_r0x00103937;
    }
  }
  if ((**(char **)(param_1 + 0x20) == '\x1f') && ((*(char **)(param_1 + 0x20))[1] == -0x75)) {
    FUN_00108ab0(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x10) = 0x200000000;
    return 0;
  }
  iVar3 = param_1[0x10];
joined_r0x00103937:
  if (iVar3 == 0) {
    param_1[0x22] = 0;
    param_1[0x14] = 1;
    *param_1 = 0;
    return 0;
  }
  *(void **)(param_1 + 2) = *(void **)(param_1 + 0xe);
  memcpy(*(void **)(param_1 + 0xe),*(void **)(param_1 + 0x20),__n);
  uVar1 = param_1[0x22];
  param_1[0x22] = 0;
  *param_1 = uVar1;
  *(undefined8 *)(param_1 + 0x10) = 0x100000001;
  return 0;
}



// Function: gz_decomp @ 0x3990

undefined4 gz_decomp(uint *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = param_1[0x28];
  while( true ) {
    if (param_1[0x22] == 0) {
      iVar1 = FUN_001036c0(param_1);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      if (param_1[0x22] == 0) {
        FUN_00102f50(param_1,0xfffffffb,"unexpected end of file");
        *param_1 = uVar3 - param_1[0x28];
        *(ulong *)(param_1 + 2) = *(long *)(param_1 + 0x26) - (ulong)(uVar3 - param_1[0x28]);
        return 0;
      }
    }
    iVar1 = FUN_00108d00(param_1 + 0x20,0);
    if ((iVar1 + 2U & 0xfffffffb) == 0) {
      FUN_00102f50(param_1,0xfffffffe,"internal error: inflate stream corrupt");
      return 0xffffffff;
    }
    if (iVar1 == -4) break;
    if (iVar1 == -3) {
      pcVar2 = *(char **)(param_1 + 0x2c);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = "compressed data error";
      }
      FUN_00102f50(param_1,0xfffffffd,pcVar2);
      return 0xffffffff;
    }
    if (param_1[0x28] == 0) {
      *param_1 = uVar3;
      *(ulong *)(param_1 + 2) = *(long *)(param_1 + 0x26) - (ulong)uVar3;
      if (iVar1 == 1) {
        param_1[0x11] = 0;
        return 0;
      }
      return 0;
    }
    if (iVar1 == 1) {
      uVar3 = uVar3 - param_1[0x28];
      param_1[0x11] = 0;
      *param_1 = uVar3;
      *(ulong *)(param_1 + 2) = *(long *)(param_1 + 0x26) - (ulong)uVar3;
      return 0;
    }
  }
  FUN_00102f50(param_1,0xfffffffc,"out of memory");
  return 0xffffffff;
}



// Function: gz_fetch @ 0x3b30

undefined8 gz_fetch(int *param_1)

{
  int iVar1;
  
  do {
    iVar1 = param_1[0x11];
    if (iVar1 == 1) {
      iVar1 = FUN_00103610(param_1,*(undefined8 *)(param_1 + 0xe),param_1[10] * 2,param_1);
      if (iVar1 != -1) {
        *(undefined8 *)(param_1 + 2) = *(undefined8 *)(param_1 + 0xe);
        return 0;
      }
      return 0xffffffff;
    }
    if (iVar1 == 2) {
      param_1[0x28] = param_1[10] * 2;
      *(undefined8 *)(param_1 + 0x26) = *(undefined8 *)(param_1 + 0xe);
      iVar1 = FUN_00103990(param_1);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
    }
    else if (iVar1 == 0) {
      iVar1 = FUN_00103790(param_1);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      if (param_1[0x11] == 0) {
        return 0;
      }
    }
    if (*param_1 != 0) {
      return 0;
    }
  } while ((param_1[0x14] == 0) || (param_1[0x22] != 0));
  return 0;
}



// Function: gz_read @ 0x3c60

long gz_read(uint *param_1,void *param_2,ulong param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong __n;
  long in_FS_OFFSET;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 == 0) {
LAB_00103d91:
    lVar4 = 0;
  }
  else {
    if (param_1[0x1c] != 0) {
      param_1[0x1c] = 0;
      iVar2 = FUN_00103be0(param_1,*(undefined8 *)(param_1 + 0x1a));
      if (iVar2 == -1) goto LAB_00103d91;
    }
    lVar4 = 0;
LAB_00103ca0:
    do {
      uVar1 = *param_1;
      local_44 = 0xffffffff;
      if (param_3 < 0xffffffff) {
        local_44 = (uint)param_3;
      }
      if (uVar1 == 0) {
        if ((param_1[0x14] != 0) && (param_1[0x22] == 0)) {
          param_1[0x15] = 1;
          break;
        }
        if ((param_1[0x11] == 0) || (local_44 < param_1[10] * 2)) {
          iVar2 = FUN_00103b30(param_1);
          if (iVar2 == -1) goto LAB_00103d91;
          goto LAB_00103ca0;
        }
        if (param_1[0x11] == 1) {
          iVar2 = FUN_00103610(param_1,param_2,local_44,&local_44);
          if (iVar2 == -1) goto LAB_00103d91;
          __n = (ulong)local_44;
        }
        else {
          param_1[0x28] = local_44;
          *(void **)(param_1 + 0x26) = param_2;
          iVar2 = FUN_00103990(param_1);
          if (iVar2 == -1) goto LAB_00103d91;
          local_44 = *param_1;
          __n = (ulong)local_44;
          *param_1 = 0;
        }
      }
      else {
        uVar3 = local_44;
        if (uVar1 < local_44) {
          uVar3 = uVar1;
        }
        __n = (ulong)uVar3;
        local_44 = uVar3;
        memcpy(param_2,*(void **)(param_1 + 2),__n);
        *(ulong *)(param_1 + 2) = *(long *)(param_1 + 2) + __n;
        *param_1 = *param_1 - uVar3;
      }
      *(ulong *)(param_1 + 4) = *(long *)(param_1 + 4) + __n;
      param_2 = (void *)((long)param_2 + __n);
      lVar4 = lVar4 + __n;
      param_3 = param_3 - __n;
    } while (param_3 != 0);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



// Function: gzread @ 0x3e00

undefined8 gzread(long param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 0x18) == 0x1c4f) &&
     ((*(int *)(param_1 + 0x74) == 0 || (*(int *)(param_1 + 0x74) == -5)))) {
    if (param_3 < 0) {
      FUN_00102f50(param_1,0xfffffffe,"request does not fit in an int");
    }
    else {
      uVar1 = FUN_00103c60(param_1,param_2,param_3);
      if ((((int)uVar1 != 0) || (*(int *)(param_1 + 0x74) == 0)) || (*(int *)(param_1 + 0x74) == -5)
         ) {
        return uVar1;
      }
    }
  }
  return 0xffffffff;
}



// Function: gzfread @ 0x3e70

ulong gzfread(undefined8 param_1,ulong param_2,ulong param_3,long param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  long lVar3;
  ulong uVar4;
  
  if (param_4 == 0) {
    return 0;
  }
  if (*(int *)(param_4 + 0x18) != 0x1c4f) {
    return 0;
  }
  if (((*(int *)(param_4 + 0x74) == 0) || (*(int *)(param_4 + 0x74) == -5)) && (param_2 != 0)) {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_3;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = param_2;
    lVar3 = SUB168(auVar1 * auVar2,0);
    if (SUB168(auVar1 * auVar2,8) != 0) {
      FUN_00102f50(param_4,0xfffffffe,"request does not fit in a size_t");
      return 0;
    }
    if (lVar3 != 0) {
      uVar4 = FUN_00103c60(param_4,param_1,lVar3);
      return uVar4 / param_2;
    }
  }
  return 0;
}



// Function: gzgetc @ 0x3f00

ulong gzgetc(int *param_1)

{
  byte *pbVar1;
  long lVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  byte local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (((param_1 != (int *)0x0) && (param_1[6] == 0x1c4f)) &&
     ((param_1[0x1d] == 0 || (param_1[0x1d] == -5)))) {
    if (*param_1 != 0) {
      *(long *)(param_1 + 4) = *(long *)(param_1 + 4) + 1;
      *param_1 = *param_1 + -1;
      pbVar1 = *(byte **)(param_1 + 2);
      *(byte **)(param_1 + 2) = pbVar1 + 1;
      uVar3 = (ulong)*pbVar1;
      goto LAB_00103f51;
    }
    lVar2 = FUN_00103c60(param_1,&local_11,1);
    if (lVar2 != 0) {
      uVar3 = (ulong)local_11;
      goto LAB_00103f51;
    }
  }
  uVar3 = 0xffffffff;
LAB_00103f51:
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: gzungetc @ 0x3fb0

int gzungetc(int param_1,uint *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  if (param_2 == (uint *)0x0) {
    return -1;
  }
  if ((param_2[6] == 0x1c4f) && ((param_2[0x1d] == 0 || (param_2[0x1d] == 0xfffffffb)))) {
    if (param_2[0x1c] != 0) {
      param_2[0x1c] = 0;
      iVar3 = FUN_00103be0(param_2,*(undefined8 *)(param_2 + 0x1a));
      if (iVar3 == -1) {
        return -1;
      }
    }
    if (-1 < param_1) {
      uVar6 = *param_2;
      uVar2 = param_2[10] * 2;
      if (uVar6 == 0) {
        *param_2 = 1;
        puVar4 = (undefined1 *)(*(long *)(param_2 + 0xe) + -1 + (ulong)uVar2);
        *(undefined1 **)(param_2 + 2) = puVar4;
        *puVar4 = (char)param_1;
        *(long *)(param_2 + 4) = *(long *)(param_2 + 4) + -1;
        param_2[0x15] = 0;
        return param_1;
      }
      if (uVar6 != uVar2) {
        puVar4 = *(undefined1 **)(param_2 + 2);
        if (puVar4 == *(undefined1 **)(param_2 + 0xe)) {
          puVar5 = puVar4 + uVar6;
          puVar4 = puVar4 + uVar2;
          if (*(undefined1 **)(param_2 + 0xe) < puVar5) {
            do {
              puVar1 = puVar5 + -1;
              puVar5 = puVar5 + -1;
              puVar4 = puVar4 + -1;
              *puVar4 = *puVar1;
            } while (*(undefined1 **)(param_2 + 0xe) < puVar5);
            uVar6 = *param_2;
          }
        }
        *param_2 = uVar6 + 1;
        *(undefined1 **)(param_2 + 2) = puVar4 + -1;
        puVar4[-1] = (char)param_1;
        *(long *)(param_2 + 4) = *(long *)(param_2 + 4) + -1;
        param_2[0x15] = 0;
        return param_1;
      }
      FUN_00102f50(param_2,0xfffffffd,"out of room to push characters");
    }
  }
  return -1;
}



// Function: gzgets @ 0x40f0

undefined1 * gzgets(uint *param_1,undefined1 *param_2,int param_3)

{
  void *__s;
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  undefined1 *__dest;
  undefined1 *puVar6;
  ulong uVar7;
  
  if ((((param_2 != (undefined1 *)0x0 && 0 < param_3) && (param_1 != (uint *)0x0)) &&
      (param_1[6] == 0x1c4f)) && ((param_1[0x1d] == 0 || (param_1[0x1d] == 0xfffffffb)))) {
    if (param_1[0x1c] != 0) {
      param_1[0x1c] = 0;
      iVar3 = FUN_00103be0(param_1,*(undefined8 *)(param_1 + 0x1a));
      if (iVar3 == -1) {
        return (undefined1 *)0x0;
      }
    }
    uVar5 = param_3 - 1;
    if (uVar5 != 0) {
      uVar2 = *param_1;
      __dest = param_2;
      puVar6 = param_2;
      if (uVar2 == 0) goto LAB_00104235;
      do {
        do {
          __s = *(void **)(param_1 + 2);
          uVar1 = uVar2;
          if (uVar5 <= uVar2) {
            uVar1 = uVar5;
          }
          uVar7 = (ulong)uVar1;
          pvVar4 = memchr(__s,10,uVar7);
          if (pvVar4 != (void *)0x0) {
            uVar5 = ((int)pvVar4 - (int)__s) + 1;
            uVar7 = (ulong)uVar5;
            puVar6 = __dest + uVar7;
            memcpy(__dest,__s,uVar7);
            *param_1 = *param_1 - uVar5;
            *(ulong *)(param_1 + 2) = *(long *)(param_1 + 2) + uVar7;
            *(ulong *)(param_1 + 4) = *(long *)(param_1 + 4) + uVar7;
            goto LAB_001041b4;
          }
          puVar6 = __dest + uVar7;
          memcpy(__dest,__s,uVar7);
          *(ulong *)(param_1 + 2) = *(long *)(param_1 + 2) + uVar7;
          *(ulong *)(param_1 + 4) = *(long *)(param_1 + 4) + uVar7;
          uVar2 = *param_1 - uVar1;
          *param_1 = uVar2;
          uVar5 = uVar5 - uVar1;
          if (uVar5 == 0) goto LAB_001041b4;
          __dest = puVar6;
        } while (uVar2 != 0);
LAB_00104235:
        iVar3 = FUN_00103b30(param_1);
        if (iVar3 == -1) {
          return (undefined1 *)0x0;
        }
        uVar2 = *param_1;
        __dest = puVar6;
      } while (uVar2 != 0);
      param_1[0x15] = 1;
LAB_001041b4:
      if (puVar6 != param_2) {
        *puVar6 = 0;
        return param_2;
      }
    }
  }
  return (undefined1 *)0x0;
}



// Function: gzdirect @ 0x4260

int gzdirect(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (((param_1[6] == 0x1c4f) && (param_1[0x11] == 0)) && (*param_1 == 0)) {
    FUN_00103790();
    return param_1[0x10];
  }
  return param_1[0x10];
}



// Function: gzclose_r @ 0x42c0

int gzclose_r(void *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == (void *)0x0) || (*(int *)((long)param_1 + 0x18) != 0x1c4f)) {
    iVar2 = -2;
  }
  else {
    if (*(int *)((long)param_1 + 0x28) != 0) {
      FUN_0010aa00((long)param_1 + 0x80);
      free(*(void **)((long)param_1 + 0x38));
      free(*(void **)((long)param_1 + 0x30));
    }
    iVar2 = *(int *)((long)param_1 + 0x74);
    if (iVar2 != -5) {
      iVar2 = 0;
    }
    FUN_00102f50(param_1,0,0);
    free(*(void **)((long)param_1 + 0x20));
    iVar1 = close(*(int *)((long)param_1 + 0x1c));
    free(param_1);
    if (iVar1 != 0) {
      iVar2 = -1;
    }
  }
  return iVar2;
}



// Function: gz_init @ 0x4360

undefined8 gz_init(long param_1)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = malloc((ulong)(uint)(*(int *)(param_1 + 0x2c) * 2));
  *(void **)(param_1 + 0x30) = pvVar2;
  if (pvVar2 != (void *)0x0) {
    if (*(int *)(param_1 + 0x40) != 0) {
      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x2c);
      return 0;
    }
    pvVar2 = malloc((ulong)*(uint *)(param_1 + 0x2c));
    *(void **)(param_1 + 0x38) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      *(undefined8 *)(param_1 + 0xc0) = 0;
      *(undefined8 *)(param_1 + 200) = 0;
      *(undefined8 *)(param_1 + 0xd0) = 0;
      iVar1 = FUN_001082b0(param_1 + 0x80,*(undefined4 *)(param_1 + 0x58),8,0x1f,8,
                           *(undefined4 *)(param_1 + 0x5c),"1.2.13",0x70);
      if (iVar1 == 0) {
        *(undefined8 *)(param_1 + 0x80) = 0;
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2c);
        if (*(int *)(param_1 + 0x40) != 0) {
          return 0;
        }
        *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x2c);
        *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(param_1 + 0x38);
        *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_1 + 0x38);
        return 0;
      }
      free(*(void **)(param_1 + 0x38));
    }
    free(*(void **)(param_1 + 0x30));
  }
  FUN_00102f50(param_1,0xfffffffc,"out of memory");
  return 0xffffffff;
}



// Function: gz_comp @ 0x4460

undefined4 gz_comp(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  ssize_t sVar3;
  int *piVar4;
  char *pcVar5;
  uint uVar6;
  size_t __n;
  ulong uVar7;
  void *pvVar8;
  void *__buf;
  int iVar9;
  
  if ((*(int *)(param_1 + 0x28) == 0) && (iVar2 = FUN_00104360(), iVar2 == -1)) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x40) == 0) {
    if (*(int *)(param_1 + 0x60) != 0) {
      if (*(int *)(param_1 + 0x88) == 0) {
        return 0;
      }
      FUN_00107150(param_1 + 0x80);
      *(undefined4 *)(param_1 + 0x60) = 0;
    }
    iVar2 = *(int *)(param_1 + 0xa0);
    iVar1 = 0;
    do {
      if (iVar2 == 0) {
        pvVar8 = *(void **)(param_1 + 0x98);
        __buf = *(void **)(param_1 + 8);
        if (__buf < pvVar8) {
LAB_001045df:
          do {
            uVar7 = (long)pvVar8 - (long)__buf;
            if (0x40000000 < (long)uVar7) {
              uVar7 = 0x40000000;
            }
            sVar3 = write(*(int *)(param_1 + 0x1c),__buf,uVar7 & 0xffffffff);
            if ((int)sVar3 < 0) goto LAB_001044dd;
            pvVar8 = *(void **)(param_1 + 0x98);
            __buf = (void *)((long)(int)sVar3 + *(long *)(param_1 + 8));
            *(void **)(param_1 + 8) = __buf;
          } while (__buf < pvVar8);
          iVar9 = *(int *)(param_1 + 0xa0);
          if (*(int *)(param_1 + 0xa0) != 0) goto LAB_00104576;
        }
        *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(param_1 + 0x38);
        *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0x28);
        *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_1 + 0x38);
        iVar9 = *(int *)(param_1 + 0x28);
      }
      else {
        iVar9 = iVar2;
        if ((param_2 != 0) && ((param_2 != 4 || (iVar1 == 1)))) {
          pvVar8 = *(void **)(param_1 + 0x98);
          __buf = *(void **)(param_1 + 8);
          if (__buf < pvVar8) goto LAB_001045df;
        }
      }
LAB_00104576:
      iVar1 = FUN_00107460(param_1 + 0x80,param_2);
      if (iVar1 == -2) {
        FUN_00102f50(param_1,0xfffffffe,"internal error: deflate stream corrupt");
        return 0xffffffff;
      }
      iVar2 = *(int *)(param_1 + 0xa0);
    } while (iVar2 != iVar9);
    if (param_2 == 4) {
      *(undefined4 *)(param_1 + 0x60) = 1;
      return 0;
    }
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x88);
    if (uVar6 != 0) {
      pvVar8 = *(void **)(param_1 + 0x80);
      do {
        __n = (size_t)uVar6;
        if (0x40000000 < uVar6) {
          __n = 0x40000000;
        }
        sVar3 = write(*(int *)(param_1 + 0x1c),pvVar8,__n);
        iVar2 = (int)sVar3;
        if (iVar2 < 0) {
LAB_001044dd:
          piVar4 = __errno_location();
          pcVar5 = strerror(*piVar4);
          FUN_00102f50(param_1,0xffffffff,pcVar5);
          return 0xffffffff;
        }
        pvVar8 = (void *)((long)iVar2 + *(long *)(param_1 + 0x80));
        *(void **)(param_1 + 0x80) = pvVar8;
        uVar6 = *(int *)(param_1 + 0x88) - iVar2;
        *(uint *)(param_1 + 0x88) = uVar6;
      } while (uVar6 != 0);
    }
  }
  return 0;
}



// Function: gz_write @ 0x4750

ulong gz_write(long param_1,void *param_2,ulong param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  ulong __n;
  
  if (param_3 != 0) {
    if (*(int *)(param_1 + 0x28) == 0) {
      iVar2 = FUN_00104360();
      if (iVar2 == -1) {
        return 0;
      }
      iVar2 = *(int *)(param_1 + 0x70);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x70);
    }
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x70) = 0;
      iVar2 = FUN_00104690(param_1,*(undefined8 *)(param_1 + 0x68));
      if (iVar2 == -1) {
        return 0;
      }
    }
    uVar4 = (ulong)*(uint *)(param_1 + 0x28);
    iVar2 = *(int *)(param_1 + 0x88);
    if (param_3 < uVar4) {
      lVar5 = *(long *)(param_1 + 0x30);
      lVar3 = lVar5;
      uVar7 = param_3;
      if (iVar2 == 0) goto LAB_0010481c;
      do {
        lVar3 = *(long *)(param_1 + 0x80);
        while( true ) {
          uVar1 = ((int)lVar3 + iVar2) - (int)lVar5;
          uVar6 = (int)uVar4 - uVar1;
          uVar4 = (ulong)uVar6;
          __n = uVar4;
          if (uVar7 < uVar4) {
            uVar4 = uVar7 & 0xffffffff;
            uVar6 = (uint)uVar7;
            __n = uVar7;
          }
          memcpy((void *)(lVar5 + (ulong)uVar1),param_2,__n);
          *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + uVar6;
          *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + uVar4;
          uVar7 = uVar7 - __n;
          if (uVar7 == 0) {
            return param_3;
          }
          iVar2 = FUN_00104460(param_1,0);
          if (iVar2 == -1) {
            return 0;
          }
          iVar2 = *(int *)(param_1 + 0x88);
          uVar4 = (ulong)*(uint *)(param_1 + 0x28);
          param_2 = (void *)((long)param_2 + __n);
          lVar5 = *(long *)(param_1 + 0x30);
          lVar3 = lVar5;
          if (iVar2 != 0) break;
LAB_0010481c:
          *(long *)(param_1 + 0x80) = lVar3;
          lVar5 = lVar3;
        }
      } while( true );
    }
    if ((iVar2 == 0) || (iVar2 = FUN_00104460(param_1,0), iVar2 != -1)) {
      *(void **)(param_1 + 0x80) = param_2;
      uVar4 = param_3;
      while (0xfffffffe < uVar4) {
        *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + 0xffffffff;
        *(undefined4 *)(param_1 + 0x88) = 0xffffffff;
        iVar2 = FUN_00104460(param_1,0);
        if (iVar2 == -1) {
          return 0;
        }
        uVar4 = uVar4 - 0xffffffff;
        if (uVar4 == 0) {
          return param_3;
        }
      }
      *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + uVar4;
      *(int *)(param_1 + 0x88) = (int)uVar4;
      iVar2 = FUN_00104460(param_1,0);
      if (iVar2 != -1) {
        return param_3;
      }
    }
  }
  return 0;
}



// Function: gzwrite @ 0x4910

undefined8 gzwrite(long param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x18) == 0x79b1) {
    if (*(int *)(param_1 + 0x74) == 0) {
      if (param_3 < 0) {
        FUN_00102f50(param_1,0xfffffffd,"requested length does not fit in int");
        uVar1 = 0;
      }
      else {
        uVar1 = FUN_00104750(param_1,param_2,param_3);
      }
      return uVar1;
    }
    return 0;
  }
  return 0;
}



// Function: gzfwrite @ 0x4980

ulong gzfwrite(undefined8 param_1,ulong param_2,ulong param_3,long param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  long lVar3;
  ulong uVar4;
  
  uVar4 = 0;
  if (param_4 == 0) {
    return 0;
  }
  if ((*(int *)(param_4 + 0x18) == 0x79b1) && (*(int *)(param_4 + 0x74) == 0)) {
    if (param_2 != 0) {
      auVar1._8_8_ = 0;
      auVar1._0_8_ = param_3;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = param_2;
      lVar3 = SUB168(auVar1 * auVar2,0);
      if (SUB168(auVar1 * auVar2,8) != 0) {
        FUN_00102f50(param_4,0xfffffffe,"request does not fit in a size_t");
        return 0;
      }
      uVar4 = 0;
      if (lVar3 != 0) {
        uVar4 = FUN_00104750(param_4,param_1,lVar3);
        uVar4 = uVar4 / param_2;
      }
    }
    return uVar4;
  }
  return 0;
}



// Function: gzputc @ 0x4a00

ulong gzputc(long param_1,byte param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  long in_FS_OFFSET;
  byte local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0x79b1)) && (*(int *)(param_1 + 0x74) == 0)) {
    if (*(int *)(param_1 + 0x70) != 0) {
      *(undefined4 *)(param_1 + 0x70) = 0;
      iVar1 = FUN_00104690(param_1,*(undefined8 *)(param_1 + 0x68));
      if (iVar1 == -1) goto LAB_00104ae8;
    }
    if (*(uint *)(param_1 + 0x28) != 0) {
      lVar2 = *(long *)(param_1 + 0x30);
      if (*(int *)(param_1 + 0x88) == 0) {
        *(long *)(param_1 + 0x80) = lVar2;
        uVar4 = 0;
      }
      else {
        uVar4 = (*(int *)(param_1 + 0x88) + (int)*(undefined8 *)(param_1 + 0x80)) - (int)lVar2;
        if (*(uint *)(param_1 + 0x28) <= uVar4) goto LAB_00104a8e;
      }
      uVar3 = (ulong)param_2;
      *(byte *)(lVar2 + (ulong)uVar4) = param_2;
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
      *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + 1;
      goto LAB_00104aaa;
    }
LAB_00104a8e:
    local_11 = param_2;
    lVar2 = FUN_00104750(param_1,&local_11,1);
    if (lVar2 == 1) {
      uVar3 = (ulong)param_2;
      goto LAB_00104aaa;
    }
  }
LAB_00104ae8:
  uVar3 = 0xffffffff;
LAB_00104aaa:
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



// Function: gzputs @ 0x4b00

ulong gzputs(long param_1,char *param_2)

{
  size_t sVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0x79b1)) && (*(int *)(param_1 + 0x74) == 0)) {
    sVar1 = strlen(param_2);
    if (((int)sVar1 < 0) || (uVar3 = sVar1 & 0xffffffff, uVar3 != sVar1)) {
      FUN_00102f50(param_1,0xfffffffe,"string length does not fit in int");
    }
    else {
      uVar2 = FUN_00104750(param_1,param_2,uVar3);
      if (uVar3 <= uVar2) {
        return sVar1 & 0xffffffff;
      }
    }
  }
  return 0xffffffff;
}



// Function: gzvprintf @ 0x4b80

uint gzvprintf(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0x18) != 0x79b1)) || (*(int *)(param_1 + 0x74) != 0)) {
    uVar2 = 0xfffffffe;
  }
  else {
    if ((*(int *)(param_1 + 0x28) == 0) && (iVar3 = FUN_00104360(), iVar3 == -1)) {
LAB_00104c6e:
      return *(uint *)(param_1 + 0x74);
    }
    if (*(int *)(param_1 + 0x70) != 0) {
      *(undefined4 *)(param_1 + 0x70) = 0;
      iVar3 = FUN_00104690(param_1,*(undefined8 *)(param_1 + 0x68));
      if (iVar3 == -1) goto LAB_00104c6e;
    }
    if (*(uint *)(param_1 + 0x88) == 0) {
      lVar4 = *(long *)(param_1 + 0x30);
      *(long *)(param_1 + 0x80) = lVar4;
    }
    else {
      lVar4 = *(long *)(param_1 + 0x80);
    }
    lVar4 = lVar4 + (ulong)*(uint *)(param_1 + 0x88);
    *(undefined1 *)(lVar4 + (ulong)(*(int *)(param_1 + 0x28) - 1)) = 0;
    uVar2 = __vsnprintf_chk(lVar4,*(undefined4 *)(param_1 + 0x28),1,0xffffffffffffffff,param_2,
                            param_3);
    if (uVar2 != 0) {
      uVar1 = *(uint *)(param_1 + 0x28);
      if ((uVar1 <= uVar2) || (*(char *)(lVar4 + (ulong)(uVar1 - 1)) != '\0')) {
        return 0;
      }
      *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + (long)(int)uVar2;
      uVar5 = *(int *)(param_1 + 0x88) + uVar2;
      *(uint *)(param_1 + 0x88) = uVar5;
      if (uVar1 <= uVar5) {
        *(uint *)(param_1 + 0x88) = uVar1;
        iVar3 = FUN_00104460(param_1,0);
        if (iVar3 == -1) goto LAB_00104c6e;
        memmove(*(void **)(param_1 + 0x30),
                (void *)((ulong)*(uint *)(param_1 + 0x28) + (long)*(void **)(param_1 + 0x30)),
                (ulong)(uVar5 - uVar1));
        *(uint *)(param_1 + 0x88) = uVar5 - uVar1;
        *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_1 + 0x30);
      }
    }
  }
  return uVar2;
}



// Function: gzprintf @ 0x4d20

void gzprintf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  long in_FS_OFFSET;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined1 *local_d0;
  undefined1 *local_c8;
  long local_c0;
  undefined1 local_b8 [16];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 local_18;
  
  if (in_AL != '\0') {
    local_88 = param_1;
    local_78 = param_2;
    local_68 = param_3;
    local_58 = param_4;
    local_48 = param_5;
    local_38 = param_6;
    local_28 = param_7;
    local_18 = param_8;
  }
  local_c0 = *(long *)(in_FS_OFFSET + 0x28);
  local_d0 = &stack0x00000008;
  local_d8 = 0x10;
  local_c8 = local_b8;
  local_d4 = 0x30;
  local_a8 = param_11;
  local_a0 = param_12;
  local_98 = param_13;
  local_90 = param_14;
  FUN_00104b80(param_9,param_10,&local_d8);
  if (local_c0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: gzflush @ 0x4de0

undefined4 gzflush(long param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0xfffffffe;
  }
  if (((*(int *)(param_1 + 0x18) != 0x79b1) || (*(int *)(param_1 + 0x74) != 0)) || (4 < param_2)) {
    return 0xfffffffe;
  }
  if (*(int *)(param_1 + 0x70) != 0) {
    *(undefined4 *)(param_1 + 0x70) = 0;
    iVar1 = FUN_00104690(param_1,*(undefined8 *)(param_1 + 0x68));
    if (iVar1 == -1) goto LAB_00104e1a;
  }
  FUN_00104460(param_1,param_2);
LAB_00104e1a:
  return *(undefined4 *)(param_1 + 0x74);
}



// Function: gzsetparams @ 0x4e50

undefined4 gzsetparams(long param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0x18) != 0x79b1)) || (*(int *)(param_1 + 0x74) != 0)) {
    uVar2 = 0xfffffffe;
  }
  else {
    uVar2 = 0;
    if (*(int *)(param_1 + 0x58) == param_2) {
      if (*(int *)(param_1 + 0x5c) == param_3) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0x70);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x70);
    }
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x70) = 0;
      iVar1 = FUN_00104690(param_1,*(undefined8 *)(param_1 + 0x68));
      if (iVar1 == -1) goto LAB_00104f04;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      if ((*(int *)(param_1 + 0x88) != 0) && (iVar1 = FUN_00104460(param_1,5), iVar1 == -1)) {
LAB_00104f04:
        return *(undefined4 *)(param_1 + 0x74);
      }
      FUN_00108030(param_1 + 0x80,param_2,param_3);
    }
    *(int *)(param_1 + 0x58) = param_2;
    *(int *)(param_1 + 0x5c) = param_3;
  }
  return uVar2;
}



// Function: gzclose_w @ 0x4f30

undefined4 gzclose_w(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (void *)0x0) || (*(int *)((long)param_1 + 0x18) != 0x79b1)) {
    return 0xfffffffe;
  }
  if (*(int *)((long)param_1 + 0x70) != 0) {
    *(undefined4 *)((long)param_1 + 0x70) = 0;
    iVar1 = FUN_00104690(param_1,*(undefined8 *)((long)param_1 + 0x68));
    if (iVar1 == -1) {
      uVar2 = *(undefined4 *)((long)param_1 + 0x74);
      goto LAB_00104f5e;
    }
  }
  uVar2 = 0;
LAB_00104f5e:
  iVar1 = FUN_00104460(param_1,4);
  if (iVar1 == -1) {
    uVar2 = *(undefined4 *)((long)param_1 + 0x74);
  }
  if (*(int *)((long)param_1 + 0x28) != 0) {
    if (*(int *)((long)param_1 + 0x40) == 0) {
      FUN_00108200((long)param_1 + 0x80);
      free(*(void **)((long)param_1 + 0x38));
    }
    free(*(void **)((long)param_1 + 0x30));
  }
  FUN_00102f50(param_1,0,0);
  free(*(void **)((long)param_1 + 0x20));
  iVar1 = close(*(int *)((long)param_1 + 0x1c));
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  free(param_1);
  return uVar2;
}



// Function: slide_hash @ 0x5020

void slide_hash(long param_1)

{
  short *psVar1;
  ushort uVar2;
  uint uVar3;
  short *psVar4;
  short sVar5;
  
  uVar3 = *(uint *)(param_1 + 0x50);
  psVar4 = (short *)(*(long *)(param_1 + 0x78) + (ulong)*(uint *)(param_1 + 0x84) * 2);
  psVar1 = psVar4 + ~(ulong)(*(uint *)(param_1 + 0x84) - 1);
  do {
    uVar2 = psVar4[-1];
    psVar4 = psVar4 + -1;
    sVar5 = uVar2 - (short)uVar3;
    if (uVar2 <= uVar3 && uVar3 != uVar2) {
      sVar5 = 0;
    }
    *psVar4 = sVar5;
  } while (psVar4 != psVar1);
  psVar4 = (short *)(*(long *)(param_1 + 0x70) + (ulong)uVar3 * 2);
  psVar1 = psVar4 + ~(ulong)(uVar3 - 1);
  do {
    uVar2 = psVar4[-1];
    psVar4 = psVar4 + -1;
    sVar5 = uVar2 - (short)uVar3;
    if (uVar2 <= uVar3 && uVar3 != uVar2) {
      sVar5 = 0;
    }
    *psVar4 = sVar5;
  } while (psVar4 != psVar1);
  return;
}



// Function: deflateStateCheck @ 0x50a0

uint deflateStateCheck(long param_1)

{
  int iVar1;
  long *plVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x40) == 0)) || (*(long *)(param_1 + 0x48) == 0)) {
    return 1;
  }
  plVar2 = *(long **)(param_1 + 0x38);
  if (plVar2 == (long *)0x0) {
    return 1;
  }
  if (*plVar2 == param_1) {
    iVar1 = (int)plVar2[1];
    if ((iVar1 == 0x2a) || (iVar1 == 0x39)) {
      return 0;
    }
    if (0x71 < iVar1) {
      return (uint)(iVar1 != 0x29a);
    }
    if (0x44 < iVar1) {
      return (uint)(0x100400400011 >> ((char)iVar1 + 0xbbU & 0x3f)) & 1 ^ 1;
    }
  }
  return 1;
}



// Function: putShortMSB @ 0x5130

void putShortMSB(long param_1,undefined4 param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x28);
  *(long *)(param_1 + 0x28) = lVar1 + 1;
  *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)((uint)param_2 >> 8);
  lVar1 = *(long *)(param_1 + 0x28);
  *(long *)(param_1 + 0x28) = lVar1 + 1;
  *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)param_2;
  return;
}



// Function: longest_match @ 0x5160

uint longest_match(long param_1,uint param_2)

{
  char *pcVar1;
  char *pcVar2;
  ushort uVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  char cVar12;
  char cVar13;
  uint uVar14;
  
  uVar6 = *(uint *)(param_1 + 0xb8);
  lVar5 = *(long *)(param_1 + 0x60);
  uVar8 = *(uint *)(param_1 + 0xbc);
  uVar4 = *(uint *)(param_1 + 0xac);
  pcVar1 = (char *)(lVar5 + (ulong)uVar4);
  uVar11 = (uVar4 + 0x106) - *(int *)(param_1 + 0x50);
  pcVar2 = (char *)(lVar5 + 0x102 + (ulong)uVar4);
  if (uVar4 <= *(int *)(param_1 + 0x50) - 0x106U) {
    uVar11 = 0;
  }
  cVar13 = pcVar1[(long)(int)uVar6 + -1];
  cVar12 = pcVar1[(int)uVar6];
  if (*(uint *)(param_1 + 0xcc) <= uVar6) {
    uVar8 = uVar8 >> 2;
  }
  uVar4 = *(uint *)(param_1 + 0xb4);
  uVar14 = *(uint *)(param_1 + 0xd0);
  if (uVar4 < *(uint *)(param_1 + 0xd0)) {
    uVar14 = uVar4;
  }
  do {
    pcVar7 = (char *)((ulong)param_2 + lVar5);
    if ((((pcVar7[(int)uVar6] == cVar12) && (pcVar7[(long)(int)uVar6 + -1] == cVar13)) &&
        (*pcVar7 == *pcVar1)) && (pcVar7[1] == pcVar1[1])) {
      pcVar10 = pcVar1 + 2;
      pcVar7 = pcVar7 + 2;
      while( true ) {
        if (pcVar10[1] != pcVar7[1]) {
          pcVar10 = pcVar10 + 1;
          goto LAB_001052c0;
        }
        if (pcVar10[2] != pcVar7[2]) break;
        if (pcVar10[3] != pcVar7[3]) {
          pcVar10 = pcVar10 + 3;
          goto LAB_001052c0;
        }
        if (pcVar10[4] != pcVar7[4]) {
          pcVar10 = pcVar10 + 4;
          goto LAB_001052c0;
        }
        if (pcVar10[5] != pcVar7[5]) {
          pcVar10 = pcVar10 + 5;
          goto LAB_001052c0;
        }
        if (pcVar10[6] != pcVar7[6]) {
          pcVar10 = pcVar10 + 6;
          goto LAB_001052c0;
        }
        if (pcVar10[7] != pcVar7[7]) {
          pcVar10 = pcVar10 + 7;
          goto LAB_001052c0;
        }
        pcVar10 = pcVar10 + 8;
        pcVar7 = pcVar7 + 8;
        if ((*pcVar10 != *pcVar7) || (pcVar2 <= pcVar10)) goto LAB_001052c0;
      }
      pcVar10 = pcVar10 + 2;
LAB_001052c0:
      uVar9 = 0x102 - ((int)pcVar2 - (int)pcVar10);
      if ((int)uVar9 <= (int)uVar6) goto LAB_001051f0;
      *(uint *)(param_1 + 0xb0) = param_2;
      if ((int)uVar14 <= (int)uVar9) {
LAB_00105301:
        if (uVar4 < uVar9) {
          uVar9 = uVar4;
        }
        return uVar9;
      }
      uVar3 = *(ushort *)
               (*(long *)(param_1 + 0x70) + (ulong)(param_2 & *(uint *)(param_1 + 0x58)) * 2);
      cVar13 = pcVar1[(long)(int)uVar9 + -1];
      cVar12 = pcVar1[(int)uVar9];
      uVar6 = uVar9;
    }
    else {
LAB_001051f0:
      uVar3 = *(ushort *)
               (*(long *)(param_1 + 0x70) + (ulong)(param_2 & *(uint *)(param_1 + 0x58)) * 2);
    }
    param_2 = (uint)uVar3;
    uVar9 = uVar6;
    if ((param_2 <= uVar11) || (uVar8 = uVar8 - 1, uVar8 == 0)) goto LAB_00105301;
  } while( true );
}



// Function: lm_init @ 0x5370

void lm_init(long param_1)

{
  ushort uVar1;
  void *__s;
  ulong uVar2;
  long lVar3;
  
  *(ulong *)(param_1 + 0x68) = (ulong)*(uint *)(param_1 + 0x50) * 2;
  __s = *(void **)(param_1 + 0x78);
  uVar2 = (ulong)(*(int *)(param_1 + 0x84) - 1);
  *(undefined2 *)((long)__s + uVar2 * 2) = 0;
  memset(__s,0,uVar2 * 2);
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x172c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 2;
  lVar3 = (long)*(int *)(param_1 + 0xc4) * 0x10;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(uint *)(param_1 + 0xc0) = (uint)*(ushort *)(&DAT_00116b82 + lVar3);
  *(uint *)(param_1 + 0xcc) = (uint)*(ushort *)(&DAT_00116b80 + lVar3);
  uVar1 = *(ushort *)(&DAT_00116b86 + lVar3);
  *(uint *)(param_1 + 0xd0) = (uint)*(ushort *)(&DAT_00116b84 + lVar3);
  *(uint *)(param_1 + 0xbc) = (uint)uVar1;
  *(undefined8 *)(param_1 + 0xb4) = 0x200000000;
  return;
}



// Function: read_buf @ 0x5420

uint read_buf(long *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  void *pvVar2;
  long lVar3;
  ulong __n;
  
  uVar1 = *(uint *)(param_1 + 1);
  if (uVar1 <= param_3) {
    param_3 = uVar1;
  }
  if (param_3 == 0) {
    return 0;
  }
  __n = (ulong)param_3;
  *(uint *)(param_1 + 1) = uVar1 - param_3;
  pvVar2 = memcpy(param_2,(void *)*param_1,__n);
  if (*(int *)(param_1[7] + 0x30) == 1) {
    lVar3 = FUN_0010d8e0(param_1[0xc],pvVar2,param_3);
    param_1[0xc] = lVar3;
  }
  else if (*(int *)(param_1[7] + 0x30) == 2) {
    lVar3 = FUN_0010dd50(param_1[0xc],pvVar2,param_3);
    param_1[0xc] = lVar3;
  }
  *param_1 = *param_1 + __n;
  param_1[2] = param_1[2] + __n;
  return param_3;
}



// Function: fill_window @ 0x54b0

void fill_window(long *param_1)

{
  undefined2 *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  byte bVar10;
  undefined8 *puVar11;
  ulong uVar12;
  uint uVar13;
  uint uVar14;
  ulong uVar15;
  int iVar16;
  byte bVar17;
  
  bVar17 = 0;
  uVar14 = *(uint *)(param_1 + 10);
  uVar9 = (ulong)uVar14;
  uVar7 = *(uint *)((long)param_1 + 0xb4);
  uVar12 = uVar9;
  while( true ) {
    uVar3 = *(uint *)((long)param_1 + 0xac);
    iVar16 = ((int)param_1[0xd] - uVar3) - uVar7;
    if (uVar3 < (int)uVar12 + (uVar14 - 0x106)) {
      lVar6 = *param_1;
      iVar4 = *(int *)(lVar6 + 8);
    }
    else {
      memcpy((void *)param_1[0xc],(void *)(param_1[0xc] + uVar9),
             (ulong)(((uVar3 + uVar14) - (int)param_1[0xd]) + uVar7));
      *(uint *)(param_1 + 0x16) = (int)param_1[0x16] - uVar14;
      param_1[0x13] = param_1[0x13] - uVar9;
      uVar7 = *(int *)((long)param_1 + 0xac) - uVar14;
      *(uint *)((long)param_1 + 0xac) = uVar7;
      if (uVar7 < *(uint *)((long)param_1 + 0x172c)) {
        *(uint *)((long)param_1 + 0x172c) = uVar7;
      }
      iVar16 = iVar16 + uVar14;
      FUN_00105020(param_1);
      lVar6 = *param_1;
      iVar4 = *(int *)(lVar6 + 8);
    }
    if (iVar4 == 0) break;
    iVar16 = FUN_00105420(lVar6,(ulong)*(uint *)((long)param_1 + 0xac) +
                                (ulong)*(uint *)((long)param_1 + 0xb4) + param_1[0xc],iVar16);
    uVar7 = iVar16 + *(int *)((long)param_1 + 0xb4);
    *(uint *)((long)param_1 + 0xb4) = uVar7;
    if (2 < uVar7 + *(int *)((long)param_1 + 0x172c)) {
      uVar3 = *(uint *)((long)param_1 + 0xac);
      lVar6 = param_1[0xc];
      uVar5 = *(uint *)((long)param_1 + 0x8c);
      uVar13 = uVar3 - *(int *)((long)param_1 + 0x172c);
      bVar2 = *(byte *)(lVar6 + (ulong)uVar13);
      *(uint *)(param_1 + 0x10) = (uint)bVar2;
      bVar10 = (byte)(int)param_1[0x12];
      *(uint *)(param_1 + 0x10) =
           ((uint)*(byte *)(lVar6 + (ulong)(uVar13 + 1)) ^ (uint)bVar2 << (bVar10 & 0x1f)) & uVar5;
      do {
        if (uVar13 == uVar3) break;
        uVar8 = ((uint)*(byte *)(lVar6 + (ulong)(uVar13 + 2)) ^
                (int)param_1[0x10] << (bVar10 & 0x1f)) & uVar5;
        *(uint *)(param_1 + 0x10) = uVar8;
        puVar1 = (undefined2 *)(param_1[0xf] + (ulong)uVar8 * 2);
        *(undefined2 *)(param_1[0xe] + (ulong)(uVar13 & *(uint *)(param_1 + 0xb)) * 2) = *puVar1;
        *puVar1 = (short)uVar13;
        uVar13 = uVar13 + 1;
        *(uint *)((long)param_1 + 0x172c) = uVar3 - uVar13;
      } while (2 < (uVar7 + uVar3) - uVar13);
    }
    if ((0x105 < uVar7) || (*(int *)(*param_1 + 8) == 0)) break;
    uVar12 = (ulong)*(uint *)(param_1 + 10);
  }
  uVar12 = param_1[0x2e7];
  uVar9 = param_1[0xd];
  if (uVar12 < uVar9) {
    uVar15 = (ulong)*(uint *)((long)param_1 + 0xac) + (ulong)*(uint *)((long)param_1 + 0xb4);
    if (uVar12 < uVar15) {
      uVar9 = uVar9 - uVar15;
      if (0x102 < uVar9) {
        uVar9 = 0x102;
      }
      puVar11 = (undefined8 *)(param_1[0xc] + uVar15);
      uVar14 = (uint)uVar9;
      if (uVar14 < 8) {
        if ((uVar9 & 4) == 0) {
          if ((uVar14 != 0) && (*(undefined1 *)puVar11 = 0, (uVar9 & 2) != 0)) {
            *(undefined2 *)((long)puVar11 + ((uVar9 & 0xffffffff) - 2)) = 0;
          }
        }
        else {
          *(undefined4 *)puVar11 = 0;
          *(undefined4 *)((long)puVar11 + ((uVar9 & 0xffffffff) - 4)) = 0;
        }
      }
      else {
        *puVar11 = 0;
        *(undefined8 *)((long)puVar11 + ((uVar9 & 0xffffffff) - 8)) = 0;
        uVar12 = (ulong)(uVar14 + ((int)puVar11 -
                                  (int)(undefined8 *)((ulong)(puVar11 + 1) & 0xfffffffffffffff8)) >>
                        3);
        puVar11 = (undefined8 *)((ulong)(puVar11 + 1) & 0xfffffffffffffff8);
        for (; uVar12 != 0; uVar12 = uVar12 - 1) {
          *puVar11 = 0;
          puVar11 = puVar11 + (ulong)bVar17 * -2 + 1;
        }
      }
      param_1[0x2e7] = uVar9 + uVar15;
      return;
    }
    if (uVar12 < uVar15 + 0x102) {
      uVar15 = (uVar15 - uVar12) + 0x102;
      if (uVar9 - uVar12 < uVar15) {
        uVar15 = uVar9 - uVar12;
      }
      memset((void *)(uVar12 + param_1[0xc]),0,uVar15 & 0xffffffff);
      param_1[0x2e7] = param_1[0x2e7] + uVar15;
      return;
    }
  }
  return;
}



// Function: flush_pending @ 0x5790

void flush_pending(long param_1)

{
  long *plVar1;
  long lVar2;
  uint uVar3;
  ulong __n;
  
  lVar2 = *(long *)(param_1 + 0x38);
  thunk_FUN_0010cc60(lVar2);
  uVar3 = *(uint *)(lVar2 + 0x28);
  if (*(uint *)(param_1 + 0x20) <= *(uint *)(lVar2 + 0x28)) {
    uVar3 = *(uint *)(param_1 + 0x20);
  }
  if (uVar3 != 0) {
    __n = (ulong)uVar3;
    memcpy(*(void **)(param_1 + 0x18),*(void **)(lVar2 + 0x20),__n);
    *(long *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) + __n;
    *(long *)(lVar2 + 0x20) = *(long *)(lVar2 + 0x20) + __n;
    *(long *)(param_1 + 0x28) = *(long *)(param_1 + 0x28) + __n;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - uVar3;
    plVar1 = (long *)(lVar2 + 0x28);
    *plVar1 = *plVar1 - __n;
    if (*plVar1 == 0) {
      *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(lVar2 + 0x10);
      return;
    }
  }
  return;
}



// Function: deflate_slow @ 0x5810

uint deflate_slow(long *param_1,int param_2)

{
  ushort *puVar1;
  undefined2 *puVar2;
  int iVar3;
  short *psVar4;
  byte bVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  
  uVar12 = *(uint *)((long)param_1 + 0xb4);
LAB_00105838:
  do {
    if (uVar12 < 0x106) goto LAB_001059ca;
LAB_00105844:
    uVar15 = *(uint *)((long)param_1 + 0xac);
    uVar9 = *(uint *)(param_1 + 0x14);
    iVar11 = (int)param_1[0x16];
    while( true ) {
      uVar8 = ((uint)*(byte *)(param_1[0xc] + (ulong)(uVar15 + 2)) ^
              (int)param_1[0x10] << ((byte)(int)param_1[0x12] & 0x1f)) &
              *(uint *)((long)param_1 + 0x8c);
      *(uint *)(param_1 + 0x10) = uVar8;
      puVar1 = (ushort *)(param_1[0xf] + (ulong)uVar8 * 2);
      uVar14 = *puVar1;
      *(ushort *)(param_1[0xe] + (ulong)(uVar15 & *(uint *)(param_1 + 0xb)) * 2) = uVar14;
      *puVar1 = (ushort)uVar15;
      *(uint *)(param_1 + 0x17) = uVar9;
      *(int *)((long)param_1 + 0xa4) = iVar11;
      *(undefined4 *)(param_1 + 0x14) = 2;
      if (((uVar14 != 0) && (uVar9 < *(uint *)(param_1 + 0x18))) &&
         (uVar15 - uVar14 <= (int)param_1[10] - 0x106U)) {
        uVar8 = FUN_00105160(param_1);
        *(uint *)(param_1 + 0x14) = uVar8;
        if ((uVar8 < 6) &&
           (((int)param_1[0x19] == 1 || ((uVar8 == 3 && (0x1000 < uVar15 - (int)param_1[0x16]))))))
        {
          *(undefined4 *)(param_1 + 0x14) = 2;
          goto LAB_00105a25;
        }
      }
      if ((2 < uVar9) && (*(uint *)(param_1 + 0x14) <= uVar9)) break;
      while( true ) {
        if ((int)param_1[0x15] != 0) {
          bVar5 = *(byte *)(param_1[0xc] + (ulong)(uVar15 - 1));
          uVar12 = *(uint *)((long)param_1 + 0x170c);
          *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
          *(undefined1 *)(param_1[0x2e0] + (ulong)uVar12) = 0;
          uVar12 = *(uint *)((long)param_1 + 0x170c);
          *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
          *(undefined1 *)(param_1[0x2e0] + (ulong)uVar12) = 0;
          uVar12 = *(uint *)((long)param_1 + 0x170c);
          *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
          *(byte *)(param_1[0x2e0] + (ulong)uVar12) = bVar5;
          psVar4 = (short *)((long)param_1 + (ulong)bVar5 * 4 + 0xd4);
          *psVar4 = *psVar4 + 1;
          if (*(int *)((long)param_1 + 0x170c) == (int)param_1[0x2e2]) {
            uVar7 = param_1[0x13];
            lVar13 = 0;
            if (-1 < (long)uVar7) {
              lVar13 = (uVar7 & 0xffffffff) + param_1[0xc];
            }
            FUN_0010cfd0(param_1,lVar13,*(uint *)((long)param_1 + 0xac) - uVar7,0);
            param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
            FUN_00105790(*param_1);
          }
          *(int *)((long)param_1 + 0xac) = *(int *)((long)param_1 + 0xac) + 1;
          uVar12 = *(int *)((long)param_1 + 0xb4) - 1;
          *(uint *)((long)param_1 + 0xb4) = uVar12;
          if (*(int *)(*param_1 + 0x20) == 0) {
            return 0;
          }
          goto LAB_00105838;
        }
        uVar12 = uVar12 - 1;
        *(undefined4 *)(param_1 + 0x15) = 1;
        *(uint *)((long)param_1 + 0xac) = uVar15 + 1;
        *(uint *)((long)param_1 + 0xb4) = uVar12;
        if (0x105 < uVar12) goto LAB_00105844;
LAB_001059ca:
        FUN_001054b0(param_1);
        uVar12 = *(uint *)((long)param_1 + 0xb4);
        if (0x105 < uVar12) goto LAB_00105844;
        if (param_2 == 0) {
          return 0;
        }
        if (uVar12 == 0) {
          if ((int)param_1[0x15] != 0) {
            bVar5 = *(byte *)(param_1[0xc] + (ulong)(*(int *)((long)param_1 + 0xac) - 1));
            uVar12 = *(uint *)((long)param_1 + 0x170c);
            *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
            *(undefined1 *)(param_1[0x2e0] + (ulong)uVar12) = 0;
            uVar12 = *(uint *)((long)param_1 + 0x170c);
            *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
            *(undefined1 *)(param_1[0x2e0] + (ulong)uVar12) = 0;
            uVar12 = *(uint *)((long)param_1 + 0x170c);
            *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
            *(byte *)(param_1[0x2e0] + (ulong)uVar12) = bVar5;
            psVar4 = (short *)((long)param_1 + (ulong)bVar5 * 4 + 0xd4);
            *psVar4 = *psVar4 + 1;
            *(undefined4 *)(param_1 + 0x15) = 0;
          }
          uVar12 = *(uint *)((long)param_1 + 0xac);
          uVar9 = 2;
          if (uVar12 < 3) {
            uVar9 = uVar12;
          }
          *(uint *)((long)param_1 + 0x172c) = uVar9;
          if (param_2 == 4) {
            uVar7 = param_1[0x13];
            lVar13 = 0;
            if (-1 < (long)uVar7) {
              lVar13 = (uVar7 & 0xffffffff) + param_1[0xc];
            }
            FUN_0010cfd0(param_1,lVar13,uVar12 - uVar7,1);
            param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
            FUN_00105790(*param_1);
            return 3 - (*(int *)(*param_1 + 0x20) == 0);
          }
          if (*(int *)((long)param_1 + 0x170c) != 0) {
            uVar7 = param_1[0x13];
            lVar13 = 0;
            if (-1 < (long)uVar7) {
              lVar13 = (uVar7 & 0xffffffff) + param_1[0xc];
            }
            FUN_0010cfd0(param_1,lVar13,uVar12 - uVar7,0);
            param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
            FUN_00105790(*param_1);
            return (uint)(*(int *)(*param_1 + 0x20) != 0);
          }
          return 1;
        }
        uVar15 = *(uint *)((long)param_1 + 0xac);
        uVar9 = *(uint *)(param_1 + 0x14);
        iVar11 = (int)param_1[0x16];
        if (2 < uVar12) break;
        *(uint *)(param_1 + 0x17) = uVar9;
        *(int *)((long)param_1 + 0xa4) = iVar11;
        *(undefined4 *)(param_1 + 0x14) = 2;
LAB_00105a25:
        if (2 < uVar9) goto LAB_00105a2e;
      }
    }
LAB_00105a2e:
    uVar8 = *(uint *)((long)param_1 + 0x170c);
    iVar3 = uVar12 - 3;
    iVar6 = (uVar15 - iVar11) + -1;
    uVar16 = (uVar15 - iVar11) - 2;
    *(uint *)((long)param_1 + 0x170c) = uVar8 + 1;
    *(char *)(param_1[0x2e0] + (ulong)uVar8) = (char)iVar6;
    uVar12 = *(uint *)((long)param_1 + 0x170c);
    *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
    *(char *)(param_1[0x2e0] + (ulong)uVar12) = (char)((uint)iVar6 >> 8);
    uVar12 = *(uint *)((long)param_1 + 0x170c);
    *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
    *(char *)(param_1[0x2e0] + (ulong)uVar12) = (char)(uVar9 - 3);
    psVar4 = (short *)((long)param_1 + (ulong)(byte)(&DAT_00110100)[uVar9 - 3 & 0xff] * 4 + 0x4d8);
    *psVar4 = *psVar4 + 1;
    uVar14 = (ushort)uVar16;
    if (uVar14 < 0x100) {
      bVar5 = (&DAT_00110200)[uVar16 & 0xffff];
    }
    else {
      bVar5 = (&DAT_00110200)[(ushort)((uVar14 >> 7) + 0x100)];
    }
    psVar4 = (short *)((long)param_1 + (ulong)bVar5 * 4 + 0x9c8);
    *psVar4 = *psVar4 + 1;
    iVar11 = (int)param_1[0x17];
    iVar6 = *(int *)((long)param_1 + 0x170c);
    lVar13 = param_1[0x2e2];
    uVar12 = (*(int *)((long)param_1 + 0xb4) + 1) - iVar11;
    iVar10 = iVar11 + *(int *)((long)param_1 + 0xac);
    *(uint *)((long)param_1 + 0xb4) = uVar12;
    uVar9 = iVar10 - 1;
    *(int *)(param_1 + 0x17) = iVar11 + -2;
    uVar8 = *(int *)((long)param_1 + 0xac) + 1;
    do {
      *(uint *)((long)param_1 + 0xac) = uVar8;
      if (uVar8 <= iVar3 + uVar15) {
        uVar16 = ((uint)*(byte *)(param_1[0xc] + (ulong)(uVar8 + 2)) ^
                 (int)param_1[0x10] << ((byte)(int)param_1[0x12] & 0x1f)) &
                 *(uint *)((long)param_1 + 0x8c);
        *(uint *)(param_1 + 0x10) = uVar16;
        puVar2 = (undefined2 *)(param_1[0xf] + (ulong)uVar16 * 2);
        *(undefined2 *)(param_1[0xe] + (ulong)(uVar8 & *(uint *)(param_1 + 0xb)) * 2) = *puVar2;
        *puVar2 = (short)uVar8;
      }
      iVar11 = (iVar10 + -2) - uVar8;
      uVar8 = uVar8 + 1;
      *(int *)(param_1 + 0x17) = iVar11;
    } while (uVar9 != uVar8);
    *(undefined4 *)(param_1 + 0x15) = 0;
    *(undefined4 *)(param_1 + 0x14) = 2;
    *(uint *)((long)param_1 + 0xac) = uVar9;
    if (iVar6 == (int)lVar13) {
      uVar7 = param_1[0x13];
      lVar13 = 0;
      if (-1 < (long)uVar7) {
        lVar13 = (uVar7 & 0xffffffff) + param_1[0xc];
      }
      FUN_0010cfd0(param_1,lVar13,uVar9 - uVar7,0);
      param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
      FUN_00105790(*param_1);
      if (*(int *)(*param_1 + 0x20) == 0) {
        return 0;
      }
      uVar12 = *(uint *)((long)param_1 + 0xb4);
    }
  } while( true );
}



// Function: deflate_fast @ 0x5e20

uint deflate_fast(long *param_1,int param_2)

{
  ushort *puVar1;
  undefined2 *puVar2;
  short *psVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  long lVar11;
  uint uVar12;
  byte bVar13;
  uint uVar14;
  undefined1 *puVar15;
  short sVar16;
  ushort uVar17;
  ulong uVar18;
  int iVar19;
  uint uVar20;
  long lVar21;
  int iVar22;
  uint uVar23;
  
  do {
    uVar23 = *(uint *)((long)param_1 + 0xb4);
    do {
      if (uVar23 < 0x106) goto LAB_001060bc;
LAB_00105e4d:
      uVar18 = (ulong)*(uint *)((long)param_1 + 0xac);
LAB_00105e53:
      uVar23 = (uint)uVar18;
      uVar12 = ((uint)*(byte *)(param_1[0xc] + (ulong)(uVar23 + 2)) ^
               (int)param_1[0x10] << ((byte)(int)param_1[0x12] & 0x1f)) &
               *(uint *)((long)param_1 + 0x8c);
      *(uint *)(param_1 + 0x10) = uVar12;
      puVar1 = (ushort *)(param_1[0xf] + (ulong)uVar12 * 2);
      uVar17 = *puVar1;
      *(ushort *)(param_1[0xe] + (ulong)(uVar23 & *(uint *)(param_1 + 0xb)) * 2) = uVar17;
      *puVar1 = (ushort)uVar18;
      if ((uVar17 != 0) && (uVar23 - uVar17 <= (int)param_1[10] - 0x106U)) {
        uVar23 = FUN_00105160(param_1);
        *(uint *)(param_1 + 0x14) = uVar23;
        goto LAB_00105eb6;
      }
      while( true ) {
        uVar23 = *(uint *)(param_1 + 0x14);
LAB_00105eb6:
        iVar19 = *(uint *)((long)param_1 + 0x170c) + 1;
        puVar15 = (undefined1 *)((ulong)*(uint *)((long)param_1 + 0x170c) + param_1[0x2e0]);
        if (2 < uVar23) break;
        bVar13 = *(byte *)(param_1[0xc] + uVar18);
        *(int *)((long)param_1 + 0x170c) = iVar19;
        *puVar15 = 0;
        uVar23 = *(uint *)((long)param_1 + 0x170c);
        *(uint *)((long)param_1 + 0x170c) = uVar23 + 1;
        *(undefined1 *)(param_1[0x2e0] + (ulong)uVar23) = 0;
        uVar23 = *(uint *)((long)param_1 + 0x170c);
        *(uint *)((long)param_1 + 0x170c) = uVar23 + 1;
        *(byte *)(param_1[0x2e0] + (ulong)uVar23) = bVar13;
        psVar3 = (short *)((long)param_1 + (ulong)bVar13 * 4 + 0xd4);
        *psVar3 = *psVar3 + 1;
        *(int *)((long)param_1 + 0xac) = *(int *)((long)param_1 + 0xac) + 1;
        uVar23 = *(int *)((long)param_1 + 0xb4) - 1;
        *(uint *)((long)param_1 + 0xb4) = uVar23;
        if (*(int *)((long)param_1 + 0x170c) == (int)param_1[0x2e2]) goto LAB_00105fe0;
        if (0x105 < uVar23) goto LAB_00105e4d;
LAB_001060bc:
        FUN_001054b0(param_1);
        uVar23 = *(uint *)((long)param_1 + 0xb4);
        if (0x105 < uVar23) goto LAB_00105e4d;
        if (param_2 == 0) {
          return 0;
        }
        if (uVar23 == 0) {
          uVar23 = *(uint *)((long)param_1 + 0xac);
          uVar12 = 2;
          if (uVar23 < 3) {
            uVar12 = uVar23;
          }
          *(uint *)((long)param_1 + 0x172c) = uVar12;
          if (param_2 == 4) {
            uVar18 = param_1[0x13];
            lVar21 = 0;
            if (-1 < (long)uVar18) {
              lVar21 = (uVar18 & 0xffffffff) + param_1[0xc];
            }
            FUN_0010cfd0(param_1,lVar21,uVar23 - uVar18,1);
            param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
            FUN_00105790(*param_1);
            return 3 - (*(int *)(*param_1 + 0x20) == 0);
          }
          if (*(int *)((long)param_1 + 0x170c) != 0) {
            uVar18 = param_1[0x13];
            lVar21 = 0;
            if (-1 < (long)uVar18) {
              lVar21 = (uVar18 & 0xffffffff) + param_1[0xc];
            }
            FUN_0010cfd0(param_1,lVar21,uVar23 - uVar18,0);
            param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
            FUN_00105790(*param_1);
            return (uint)(*(int *)(*param_1 + 0x20) != 0);
          }
          return 1;
        }
        uVar18 = (ulong)*(uint *)((long)param_1 + 0xac);
        if (2 < uVar23) goto LAB_00105e53;
      }
      sVar16 = (short)uVar18 - (short)param_1[0x16];
      *(int *)((long)param_1 + 0x170c) = iVar19;
      *puVar15 = (char)sVar16;
      uVar12 = *(uint *)((long)param_1 + 0x170c);
      uVar17 = sVar16 - 1;
      *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
      *(char *)(param_1[0x2e0] + (ulong)uVar12) = (char)((ushort)sVar16 >> 8);
      uVar12 = *(uint *)((long)param_1 + 0x170c);
      *(uint *)((long)param_1 + 0x170c) = uVar12 + 1;
      *(char *)(param_1[0x2e0] + (ulong)uVar12) = (char)(uVar23 - 3);
      psVar3 = (short *)((long)param_1 + (ulong)(byte)(&DAT_00110100)[uVar23 - 3 & 0xff] * 4 + 0x4d8
                        );
      *psVar3 = *psVar3 + 1;
      if (uVar17 < 0x100) {
        bVar13 = (&DAT_00110200)[uVar17];
      }
      else {
        bVar13 = (&DAT_00110200)[(uVar17 >> 7) + 0x100];
      }
      psVar3 = (short *)((long)param_1 + (ulong)bVar13 * 4 + 0x9c8);
      *psVar3 = *psVar3 + 1;
      uVar12 = *(uint *)(param_1 + 0x14);
      iVar19 = *(int *)((long)param_1 + 0x170c);
      lVar11 = param_1[0x2e2];
      uVar5 = *(uint *)((long)param_1 + 0xac);
      uVar23 = *(int *)((long)param_1 + 0xb4) - uVar12;
      lVar21 = param_1[0xc];
      *(uint *)((long)param_1 + 0xb4) = uVar23;
      uVar6 = *(uint *)((long)param_1 + 0x8c);
      bVar13 = (byte)(int)param_1[0x12];
      if ((*(uint *)(param_1 + 0x18) < uVar12) || (uVar23 < 3)) {
        *(undefined4 *)(param_1 + 0x14) = 0;
        uVar12 = uVar12 + uVar5;
        *(uint *)((long)param_1 + 0xac) = uVar12;
        bVar4 = *(byte *)(lVar21 + (ulong)uVar12);
        *(uint *)(param_1 + 0x10) = (uint)bVar4;
        *(uint *)(param_1 + 0x10) =
             ((uint)*(byte *)(lVar21 + (ulong)(uVar12 + 1)) ^ (uint)bVar4 << (bVar13 & 0x1f)) &
             uVar6;
      }
      else {
        iVar22 = uVar12 - 1;
        lVar8 = param_1[0xe];
        uVar7 = *(uint *)(param_1 + 0xb);
        *(int *)(param_1 + 0x14) = iVar22;
        lVar9 = param_1[0xf];
        uVar20 = *(uint *)(param_1 + 0x10);
        uVar10 = uVar5;
        do {
          uVar14 = uVar10 + 1;
          *(uint *)((long)param_1 + 0xac) = uVar14;
          iVar22 = iVar22 + -1;
          uVar20 = ((uint)*(byte *)(lVar21 + (ulong)(uVar10 + 3)) ^ uVar20 << (bVar13 & 0x1f)) &
                   uVar6;
          *(uint *)(param_1 + 0x10) = uVar20;
          puVar2 = (undefined2 *)(lVar9 + (ulong)uVar20 * 2);
          *(undefined2 *)(lVar8 + (ulong)(uVar14 & uVar7) * 2) = *puVar2;
          *puVar2 = (short)uVar14;
          *(int *)(param_1 + 0x14) = iVar22;
          uVar10 = uVar14;
        } while (iVar22 != 0);
        *(uint *)((long)param_1 + 0xac) = uVar5 + uVar12;
      }
    } while (iVar19 != (int)lVar11);
LAB_00105fe0:
    uVar18 = param_1[0x13];
    lVar21 = 0;
    if (-1 < (long)uVar18) {
      lVar21 = (uVar18 & 0xffffffff) + param_1[0xc];
    }
    FUN_0010cfd0(param_1,lVar21,*(uint *)((long)param_1 + 0xac) - uVar18,0);
    param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
    FUN_00105790(*param_1);
    if (*(int *)(*param_1 + 0x20) == 0) {
      return 0;
    }
  } while( true );
}



// Function: deflate_huff @ 0x62c0

uint deflate_huff(long *param_1,int param_2)

{
  short *psVar1;
  byte bVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  
  do {
    iVar4 = *(int *)((long)param_1 + 0xb4);
    do {
      if ((iVar4 == 0) && (FUN_001054b0(param_1), *(int *)((long)param_1 + 0xb4) == 0)) {
        if (param_2 == 0) {
          return 0;
        }
        *(undefined4 *)((long)param_1 + 0x172c) = 0;
        if (param_2 == 4) {
          uVar3 = param_1[0x13];
          lVar6 = 0;
          if (-1 < (long)uVar3) {
            lVar6 = (uVar3 & 0xffffffff) + param_1[0xc];
          }
          FUN_0010cfd0(param_1,lVar6,*(uint *)((long)param_1 + 0xac) - uVar3,1);
          param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
          FUN_00105790(*param_1);
          return 3 - (*(int *)(*param_1 + 0x20) == 0);
        }
        uVar5 = 1;
        if (*(int *)((long)param_1 + 0x170c) != 0) {
          uVar3 = param_1[0x13];
          lVar6 = 0;
          if (-1 < (long)uVar3) {
            lVar6 = (uVar3 & 0xffffffff) + param_1[0xc];
          }
          FUN_0010cfd0(param_1,lVar6,*(uint *)((long)param_1 + 0xac) - uVar3,0);
          param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
          FUN_00105790(*param_1);
          uVar5 = (uint)(*(int *)(*param_1 + 0x20) != 0);
        }
        return uVar5;
      }
      *(undefined4 *)(param_1 + 0x14) = 0;
      bVar2 = *(byte *)(param_1[0xc] + (ulong)*(uint *)((long)param_1 + 0xac));
      uVar5 = *(uint *)((long)param_1 + 0x170c);
      *(uint *)((long)param_1 + 0x170c) = uVar5 + 1;
      *(undefined1 *)(param_1[0x2e0] + (ulong)uVar5) = 0;
      uVar5 = *(uint *)((long)param_1 + 0x170c);
      *(uint *)((long)param_1 + 0x170c) = uVar5 + 1;
      *(undefined1 *)(param_1[0x2e0] + (ulong)uVar5) = 0;
      uVar5 = *(uint *)((long)param_1 + 0x170c);
      *(uint *)((long)param_1 + 0x170c) = uVar5 + 1;
      *(byte *)(param_1[0x2e0] + (ulong)uVar5) = bVar2;
      iVar4 = *(int *)((long)param_1 + 0xac);
      psVar1 = (short *)((long)param_1 + (ulong)bVar2 * 4 + 0xd4);
      *psVar1 = *psVar1 + 1;
      uVar5 = iVar4 + 1;
      iVar4 = *(int *)((long)param_1 + 0xb4) + -1;
      *(uint *)((long)param_1 + 0xac) = uVar5;
      *(int *)((long)param_1 + 0xb4) = iVar4;
    } while (*(int *)((long)param_1 + 0x170c) != (int)param_1[0x2e2]);
    uVar3 = param_1[0x13];
    lVar6 = 0;
    if (-1 < (long)uVar3) {
      lVar6 = (uVar3 & 0xffffffff) + param_1[0xc];
    }
    FUN_0010cfd0(param_1,lVar6,uVar5 - uVar3,0);
    param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
    FUN_00105790(*param_1);
    if (*(int *)(*param_1 + 0x20) == 0) {
      return 0;
    }
  } while( true );
}



// Function: deflate_rle @ 0x64d0

uint deflate_rle(long *param_1,int param_2)

{
  short *psVar1;
  char *pcVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  char *pcVar10;
  long lVar11;
  
  do {
    uVar7 = *(uint *)((long)param_1 + 0xb4);
    do {
      while (uVar7 < 0x103) {
        FUN_001054b0(param_1);
        uVar7 = *(uint *)((long)param_1 + 0xb4);
        if (0x102 < uVar7) break;
        if (param_2 == 0) {
          return 0;
        }
        if (uVar7 == 0) {
          *(undefined4 *)((long)param_1 + 0x172c) = 0;
          if (param_2 == 4) {
            uVar8 = param_1[0x13];
            lVar11 = 0;
            if (-1 < (long)uVar8) {
              lVar11 = (uVar8 & 0xffffffff) + param_1[0xc];
            }
            FUN_0010cfd0(param_1,lVar11,*(uint *)((long)param_1 + 0xac) - uVar8,1);
            param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
            FUN_00105790(*param_1);
            uVar7 = 3 - (*(int *)(*param_1 + 0x20) == 0);
          }
          else {
            uVar7 = 1;
            if (*(int *)((long)param_1 + 0x170c) != 0) {
              uVar8 = param_1[0x13];
              lVar11 = 0;
              if (-1 < (long)uVar8) {
                lVar11 = (uVar8 & 0xffffffff) + param_1[0xc];
              }
              FUN_0010cfd0(param_1,lVar11,*(uint *)((long)param_1 + 0xac) - uVar8,0);
              param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
              FUN_00105790(*param_1);
              return (uint)(*(int *)(*param_1 + 0x20) != 0);
            }
          }
          return uVar7;
        }
        uVar9 = *(uint *)((long)param_1 + 0xac);
        uVar8 = (ulong)uVar9;
        lVar11 = param_1[0xc];
        *(undefined4 *)(param_1 + 0x14) = 0;
        if (2 < uVar7) goto LAB_00106507;
LAB_00106520:
        uVar7 = *(uint *)((long)param_1 + 0x170c);
        bVar4 = *(byte *)(lVar11 + uVar8);
        *(uint *)((long)param_1 + 0x170c) = uVar7 + 1;
        *(undefined1 *)(param_1[0x2e0] + (ulong)uVar7) = 0;
        uVar7 = *(uint *)((long)param_1 + 0x170c);
        *(uint *)((long)param_1 + 0x170c) = uVar7 + 1;
        *(undefined1 *)(param_1[0x2e0] + (ulong)uVar7) = 0;
        uVar7 = *(uint *)((long)param_1 + 0x170c);
        *(uint *)((long)param_1 + 0x170c) = uVar7 + 1;
        *(byte *)(param_1[0x2e0] + (ulong)uVar7) = bVar4;
        iVar5 = *(int *)((long)param_1 + 0xac);
        psVar1 = (short *)((long)param_1 + (ulong)bVar4 * 4 + 0xd4);
        *psVar1 = *psVar1 + 1;
        uVar9 = iVar5 + 1;
        uVar7 = *(int *)((long)param_1 + 0xb4) - 1;
        *(uint *)((long)param_1 + 0xac) = uVar9;
        *(uint *)((long)param_1 + 0xb4) = uVar7;
        if (*(int *)((long)param_1 + 0x170c) == (int)param_1[0x2e2]) goto LAB_00106751;
      }
      uVar9 = *(uint *)((long)param_1 + 0xac);
      uVar8 = (ulong)uVar9;
      lVar11 = param_1[0xc];
      *(undefined4 *)(param_1 + 0x14) = 0;
LAB_00106507:
      if (uVar9 == 0) goto LAB_00106520;
      pcVar10 = (char *)(lVar11 + -1 + uVar8);
      cVar3 = *pcVar10;
      if (((cVar3 != pcVar10[1]) || (cVar3 != pcVar10[2])) || (cVar3 != pcVar10[3]))
      goto LAB_00106520;
      pcVar10 = pcVar10 + 3;
      pcVar2 = (char *)(lVar11 + 0x102 + uVar8);
      while( true ) {
        if (cVar3 != pcVar10[1]) {
          pcVar10 = pcVar10 + 1;
          goto LAB_00106684;
        }
        if (cVar3 != pcVar10[2]) break;
        if (cVar3 != pcVar10[3]) {
          pcVar10 = pcVar10 + 3;
          goto LAB_00106684;
        }
        if (cVar3 != pcVar10[4]) {
          pcVar10 = pcVar10 + 4;
          goto LAB_00106684;
        }
        if (cVar3 != pcVar10[5]) {
          pcVar10 = pcVar10 + 5;
          goto LAB_00106684;
        }
        if (cVar3 != pcVar10[6]) {
          pcVar10 = pcVar10 + 6;
          goto LAB_00106684;
        }
        if (cVar3 != pcVar10[7]) {
          pcVar10 = pcVar10 + 7;
          goto LAB_00106684;
        }
        pcVar10 = pcVar10 + 8;
        if ((*pcVar10 != cVar3) || (pcVar2 <= pcVar10)) goto LAB_00106684;
      }
      pcVar10 = pcVar10 + 2;
LAB_00106684:
      uVar9 = ((int)pcVar10 - (int)pcVar2) + 0x102;
      *(uint *)(param_1 + 0x14) = uVar9;
      if (uVar7 < uVar9) {
        *(uint *)(param_1 + 0x14) = uVar7;
      }
      else {
        uVar7 = uVar9;
        if (uVar9 < 3) goto LAB_00106520;
      }
      uVar9 = *(uint *)((long)param_1 + 0x170c);
      *(uint *)((long)param_1 + 0x170c) = uVar9 + 1;
      *(undefined1 *)(param_1[0x2e0] + (ulong)uVar9) = 1;
      uVar9 = *(uint *)((long)param_1 + 0x170c);
      *(uint *)((long)param_1 + 0x170c) = uVar9 + 1;
      *(undefined1 *)(param_1[0x2e0] + (ulong)uVar9) = 0;
      uVar9 = *(uint *)((long)param_1 + 0x170c);
      *(uint *)((long)param_1 + 0x170c) = uVar9 + 1;
      *(char *)(param_1[0x2e0] + (ulong)uVar9) = (char)(uVar7 - 3);
      lVar11 = param_1[0x14];
      lVar6 = param_1[0x2e2];
      psVar1 = (short *)((long)param_1 + (ulong)(byte)(&DAT_00110100)[uVar7 - 3 & 0xff] * 4 + 0x4d8)
      ;
      *psVar1 = *psVar1 + 1;
      psVar1 = (short *)((long)param_1 + (ulong)DAT_00110200 * 4 + 0x9c8);
      *psVar1 = *psVar1 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0;
      uVar7 = *(int *)((long)param_1 + 0xb4) - (int)lVar11;
      uVar9 = (int)lVar11 + *(int *)((long)param_1 + 0xac);
      *(uint *)((long)param_1 + 0xb4) = uVar7;
      *(uint *)((long)param_1 + 0xac) = uVar9;
    } while (*(int *)((long)param_1 + 0x170c) != (int)lVar6);
LAB_00106751:
    uVar8 = param_1[0x13];
    lVar11 = 0;
    if (-1 < (long)uVar8) {
      lVar11 = (uVar8 & 0xffffffff) + param_1[0xc];
    }
    FUN_0010cfd0(param_1,lVar11,uVar9 - uVar8,0);
    param_1[0x13] = (ulong)*(uint *)((long)param_1 + 0xac);
    FUN_00105790(*param_1);
    if (*(int *)(*param_1 + 0x20) == 0) {
      return 0;
    }
  } while( true );
}



// Function: deflate_stored @ 0x68b0

undefined4 deflate_stored(long *param_1,uint param_2)

{
  long lVar1;
  byte bVar5;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  long *plVar9;
  void *__dest;
  uint uVar10;
  bool bVar12;
  bool bVar13;
  ulong uVar11;
  
  plVar9 = (long *)*param_1;
  uVar8 = param_1[3] - 5U;
  if ((ulong)*(uint *)(param_1 + 10) < param_1[3] - 5U) {
    uVar8 = (ulong)*(uint *)(param_1 + 10);
  }
  uVar4 = *(uint *)(plVar9 + 1);
  uVar7 = (ulong)uVar4;
LAB_00106908:
  do {
    uVar2 = *(int *)((long)param_1 + 0x1734) + 0x2a >> 3;
    uVar6 = (uint)uVar7;
    if (*(uint *)(plVar9 + 4) < uVar2) {
LAB_00106b00:
      bVar12 = false;
      goto joined_r0x00106b0b;
    }
    uVar2 = *(uint *)(plVar9 + 4) - uVar2;
    uVar3 = *(int *)((long)param_1 + 0xac) - (int)param_1[0x13];
    uVar10 = 0xffff;
    if (uVar3 + uVar7 < 0xffff) {
      uVar10 = uVar3 + uVar6;
    }
    if (uVar2 < uVar10) {
      uVar10 = uVar2;
    }
    if ((uVar10 < (uint)uVar8) &&
       (((uVar10 == 0 && param_2 != 4 || (param_2 == 0)) || (uVar3 + uVar6 != uVar10))))
    goto LAB_00106b00;
    bVar12 = param_2 == 4;
    bVar13 = uVar6 + uVar3 == uVar10;
    FUN_0010cdd0(param_1,0,0,bVar12 && bVar13);
    *(byte *)(param_1[2] + -4 + param_1[5]) = (byte)uVar10;
    bVar5 = (byte)(uVar10 >> 8);
    *(byte *)(param_1[2] + -3 + param_1[5]) = bVar5;
    *(byte *)(param_1[2] + -2 + param_1[5]) = ~(byte)uVar10;
    *(byte *)(param_1[2] + -1 + param_1[5]) = ~bVar5;
    FUN_00105790(*param_1);
    if (uVar3 == 0) {
      plVar9 = (long *)*param_1;
      if (uVar10 != 0) goto LAB_00106a45;
LAB_001068fc:
      uVar6 = *(uint *)(plVar9 + 1);
      uVar7 = (ulong)uVar6;
      if (bVar12 && bVar13) break;
      goto LAB_00106908;
    }
    if (uVar10 < uVar3) {
      uVar3 = uVar10;
    }
    uVar7 = (ulong)uVar3;
    memcpy(*(void **)(*param_1 + 0x18),(void *)(param_1[0x13] + param_1[0xc]),uVar7);
    plVar9 = (long *)*param_1;
    uVar10 = uVar10 - uVar3;
    plVar9[3] = plVar9[3] + uVar7;
    *(uint *)(plVar9 + 4) = (int)plVar9[4] - uVar3;
    plVar9[5] = plVar9[5] + uVar7;
    param_1[0x13] = param_1[0x13] + uVar7;
    if (uVar10 == 0) goto LAB_001068fc;
LAB_00106a45:
    uVar11 = (ulong)uVar10;
    FUN_00105420(plVar9,plVar9[3],uVar11);
    plVar9 = (long *)*param_1;
    *(uint *)(plVar9 + 4) = (int)plVar9[4] - uVar10;
    uVar6 = *(uint *)(plVar9 + 1);
    uVar7 = (ulong)uVar6;
    plVar9[3] = plVar9[3] + uVar11;
    plVar9[5] = plVar9[5] + uVar11;
  } while (!bVar12 || !bVar13);
  bVar12 = true;
joined_r0x00106b0b:
  uVar4 = uVar4 - uVar6;
  if (uVar4 == 0) {
    uVar8 = (ulong)*(uint *)((long)param_1 + 0xac);
  }
  else {
    uVar6 = *(uint *)(param_1 + 10);
    __dest = (void *)param_1[0xc];
    if (uVar4 < uVar6) {
      uVar8 = (ulong)*(uint *)((long)param_1 + 0xac);
      uVar7 = (ulong)uVar4;
      if (param_1[0xd] - uVar8 <= uVar7) {
        uVar2 = *(uint *)((long)param_1 + 0xac) - uVar6;
        *(uint *)((long)param_1 + 0xac) = uVar2;
        memcpy(__dest,(void *)((long)__dest + (ulong)uVar6),(ulong)uVar2);
        if (*(uint *)(param_1 + 0x2e5) < 2) {
          *(uint *)(param_1 + 0x2e5) = *(uint *)(param_1 + 0x2e5) + 1;
        }
        uVar6 = *(uint *)((long)param_1 + 0xac);
        uVar8 = (ulong)uVar6;
        if (uVar6 < *(uint *)((long)param_1 + 0x172c)) {
          *(uint *)((long)param_1 + 0x172c) = uVar6;
        }
        plVar9 = (long *)*param_1;
        __dest = (void *)param_1[0xc];
      }
      memcpy((void *)((long)__dest + uVar8),(void *)(*plVar9 - uVar7),uVar7);
      uVar6 = (int)param_1[10] - *(int *)((long)param_1 + 0x172c);
      uVar2 = *(int *)((long)param_1 + 0xac) + uVar4;
      *(uint *)((long)param_1 + 0xac) = uVar2;
      if (uVar4 < uVar6) {
        uVar6 = uVar4;
      }
      uVar6 = uVar6 + *(int *)((long)param_1 + 0x172c);
    }
    else {
      *(undefined4 *)(param_1 + 0x2e5) = 2;
      memcpy(__dest,(void *)(*plVar9 - (ulong)uVar6),(ulong)uVar6);
      uVar6 = *(uint *)(param_1 + 10);
      *(uint *)((long)param_1 + 0xac) = uVar6;
      uVar2 = uVar6;
    }
    uVar8 = (ulong)uVar2;
    *(uint *)((long)param_1 + 0x172c) = uVar6;
    param_1[0x13] = uVar8;
  }
  uVar4 = (uint)uVar8;
  if ((ulong)param_1[0x2e7] < uVar8) {
    param_1[0x2e7] = uVar8;
  }
  if (bVar12) {
    return 3;
  }
  lVar1 = *param_1;
  uVar6 = *(uint *)(lVar1 + 8);
  if (((param_2 & 0xfffffffb) == 0) || (uVar6 != 0)) {
    uVar2 = (int)param_1[0xd] - uVar4;
    if (uVar2 < uVar6) {
      uVar7 = (ulong)*(uint *)(param_1 + 10);
      if (param_1[0x13] < (long)uVar7) goto LAB_00106bef;
      uVar4 = uVar4 - *(uint *)(param_1 + 10);
      param_1[0x13] = param_1[0x13] - uVar7;
      *(uint *)((long)param_1 + 0xac) = uVar4;
      memcpy((void *)param_1[0xc],(void *)(param_1[0xc] + uVar7),(ulong)uVar4);
      if (*(uint *)(param_1 + 0x2e5) < 2) {
        *(uint *)(param_1 + 0x2e5) = *(uint *)(param_1 + 0x2e5) + 1;
      }
      uVar4 = *(uint *)((long)param_1 + 0xac);
      uVar8 = (ulong)uVar4;
      uVar2 = uVar2 + (int)param_1[10];
      if (uVar4 < *(uint *)((long)param_1 + 0x172c)) {
        *(uint *)((long)param_1 + 0x172c) = uVar4;
      }
      lVar1 = *param_1;
      if (*(uint *)(lVar1 + 8) < uVar2) {
        uVar2 = *(uint *)(lVar1 + 8);
      }
    }
    else {
LAB_00106bef:
      if (uVar6 < uVar2) {
        uVar2 = uVar6;
      }
    }
    if (uVar2 == 0) goto LAB_00106b5c;
    FUN_00105420(lVar1,uVar8 + param_1[0xc],uVar2);
    uVar6 = *(uint *)(param_1 + 10);
    uVar10 = uVar6 - *(int *)((long)param_1 + 0x172c);
    uVar4 = *(int *)((long)param_1 + 0xac) + uVar2;
    *(uint *)((long)param_1 + 0xac) = uVar4;
    uVar8 = (ulong)uVar4;
    if (uVar2 < uVar10) {
      uVar10 = uVar2;
    }
    *(uint *)((long)param_1 + 0x172c) = uVar10 + *(int *)((long)param_1 + 0x172c);
  }
  else {
    if (uVar8 == param_1[0x13]) {
      return 1;
    }
LAB_00106b5c:
    uVar6 = *(uint *)(param_1 + 10);
  }
  if ((ulong)param_1[0x2e7] < uVar8) {
    param_1[0x2e7] = uVar8;
  }
  lVar1 = param_1[0x13];
  uVar8 = param_1[3] - (ulong)(uint)(*(int *)((long)param_1 + 0x1734) + 0x2a >> 3);
  if (0xffff < uVar8) {
    uVar8 = 0xffff;
  }
  uVar4 = uVar4 - (int)lVar1;
  uVar2 = (uint)uVar8;
  if (uVar2 < uVar6) {
    uVar6 = uVar2;
  }
  if (uVar4 < uVar6) {
    if (uVar4 == 0 && param_2 != 4) {
      return 0;
    }
    if (param_2 == 0) {
      return 0;
    }
    if (*(int *)(*param_1 + 8) != 0) {
      return 0;
    }
    if (uVar2 < uVar4) {
      return 0;
    }
    uVar6 = uVar4;
    if (uVar2 == uVar4) {
      uVar6 = uVar2;
    }
    if (param_2 != 4) {
LAB_00106c4e:
      FUN_0010cdd0(param_1,lVar1 + param_1[0xc],(ulong)uVar6,0);
      param_1[0x13] = param_1[0x13] + (ulong)uVar6;
      FUN_00105790(*param_1);
      return 0;
    }
  }
  else {
    uVar6 = uVar2;
    if (uVar4 <= uVar2) {
      uVar6 = uVar4;
    }
    if (((param_2 != 4) || (*(int *)(*param_1 + 8) != 0)) || (uVar2 < uVar4)) goto LAB_00106c4e;
  }
  FUN_0010cdd0(param_1,lVar1 + param_1[0xc],(ulong)uVar6,1);
  param_1[0x13] = param_1[0x13] + (ulong)uVar6;
  FUN_00105790(*param_1);
  return 2;
}



// Function: deflateSetDictionary @ 0x6df0

undefined8 deflateSetDictionary(long *param_1,long param_2,uint param_3)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  void *__s;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  long lVar14;
  uint uVar15;
  long *plVar16;
  
  plVar16 = param_1;
  iVar10 = FUN_001050a0();
  if ((param_2 == 0) || (iVar10 != 0)) {
    return 0xfffffffe;
  }
  lVar5 = plVar16[7];
  iVar10 = *(int *)(lVar5 + 0x30);
  if (iVar10 == 2) {
    return 0xfffffffe;
  }
  if (iVar10 == 1) {
    if (*(int *)(lVar5 + 8) != 0x2a) {
      return 0xfffffffe;
    }
    if (*(int *)(lVar5 + 0xb4) != 0) {
      return 0xfffffffe;
    }
    lVar14 = FUN_0010d8e0(param_1[0xc],param_2,param_3);
    param_1[0xc] = lVar14;
    uVar11 = *(uint *)(lVar5 + 0x50);
    *(undefined4 *)(lVar5 + 0x30) = 0;
    if (param_3 < uVar11) goto LAB_00106ef1;
  }
  else {
    if (*(int *)(lVar5 + 0xb4) != 0) {
      return 0xfffffffe;
    }
    uVar11 = *(uint *)(lVar5 + 0x50);
    *(undefined4 *)(lVar5 + 0x30) = 0;
    if (param_3 < uVar11) goto LAB_00106ef1;
    if (iVar10 == 0) {
      __s = *(void **)(lVar5 + 0x78);
      uVar13 = (ulong)(*(int *)(lVar5 + 0x84) - 1);
      *(undefined2 *)((long)__s + uVar13 * 2) = 0;
      memset(__s,0,uVar13 * 2);
      uVar11 = *(uint *)(lVar5 + 0x50);
      *(undefined4 *)(lVar5 + 0xac) = 0;
      *(undefined8 *)(lVar5 + 0x98) = 0;
      *(undefined4 *)(lVar5 + 0x172c) = 0;
    }
  }
  param_2 = param_2 + (ulong)(param_3 - uVar11);
  param_3 = uVar11;
LAB_00106ef1:
  lVar9 = param_1[1];
  lVar14 = *param_1;
  *(uint *)(param_1 + 1) = param_3;
  *param_1 = param_2;
  while( true ) {
    FUN_001054b0(lVar5);
    uVar11 = *(uint *)(lVar5 + 0xb4);
    if (uVar11 < 3) break;
    uVar12 = *(uint *)(lVar5 + 0xac);
    uVar2 = *(undefined4 *)(lVar5 + 0x90);
    lVar6 = *(long *)(lVar5 + 0x60);
    uVar3 = *(uint *)(lVar5 + 0x8c);
    lVar7 = *(long *)(lVar5 + 0x78);
    lVar8 = *(long *)(lVar5 + 0x70);
    uVar11 = (uVar11 - 2) + uVar12;
    uVar4 = *(uint *)(lVar5 + 0x58);
    uVar15 = *(uint *)(lVar5 + 0x80);
    do {
      uVar15 = ((uint)*(byte *)(lVar6 + (ulong)(uVar12 + 2)) ^ uVar15 << ((byte)uVar2 & 0x1f)) &
               uVar3;
      *(uint *)(lVar5 + 0x80) = uVar15;
      puVar1 = (undefined2 *)(lVar7 + (ulong)uVar15 * 2);
      *(undefined2 *)(lVar8 + (ulong)(uVar4 & uVar12) * 2) = *puVar1;
      *puVar1 = (short)uVar12;
      uVar12 = uVar12 + 1;
    } while (uVar12 != uVar11);
    *(uint *)(lVar5 + 0xac) = uVar12;
    *(undefined4 *)(lVar5 + 0xb4) = 2;
  }
  uVar12 = uVar11 + *(int *)(lVar5 + 0xac);
  *(uint *)(lVar5 + 0x172c) = uVar11;
  *(uint *)(lVar5 + 0xac) = uVar12;
  *(ulong *)(lVar5 + 0x98) = (ulong)uVar12;
  *(undefined8 *)(lVar5 + 0xb4) = 0x200000000;
  *(undefined4 *)(lVar5 + 0xa0) = 2;
  *(undefined4 *)(lVar5 + 0xa8) = 0;
  *(int *)(param_1 + 1) = (int)lVar9;
  *param_1 = lVar14;
  *(int *)(lVar5 + 0x30) = iVar10;
  return 0;
}



// Function: deflateGetDictionary @ 0x7020

undefined8 deflateGetDictionary(long param_1,void *param_2,uint *param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  iVar2 = FUN_001050a0();
  if (iVar2 == 0) {
    lVar1 = *(long *)(param_1 + 0x38);
    uVar5 = 0;
    uVar4 = *(uint *)(lVar1 + 0xac) + *(uint *)(lVar1 + 0xb4);
    uVar3 = *(uint *)(lVar1 + 0x50);
    if (uVar4 <= *(uint *)(lVar1 + 0x50)) {
      uVar3 = uVar4;
    }
    if ((param_2 != (void *)0x0) && (uVar3 != 0)) {
      memcpy(param_2,(void *)((((ulong)*(uint *)(lVar1 + 0xac) + (ulong)*(uint *)(lVar1 + 0xb4)) -
                              (ulong)uVar3) + *(long *)(lVar1 + 0x60)),(ulong)uVar3);
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = uVar3;
    }
  }
  else {
    uVar5 = 0xfffffffe;
  }
  return uVar5;
}



// Function: deflateResetKeep @ 0x70a0

undefined8 deflateResetKeep(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = param_1;
  iVar2 = FUN_001050a0();
  if (iVar2 == 0) {
    lVar1 = *(long *)(lVar4 + 0x38);
    uVar5 = 0;
    *(undefined8 *)(lVar4 + 0x28) = 0;
    *(undefined8 *)(lVar4 + 0x10) = 0;
    uVar3 = *(undefined8 *)(lVar1 + 0x10);
    *(undefined8 *)(lVar4 + 0x30) = 0;
    *(undefined4 *)(lVar4 + 0x58) = 2;
    *(undefined8 *)(lVar1 + 0x20) = uVar3;
    iVar2 = *(int *)(lVar1 + 0x30);
    *(undefined8 *)(lVar1 + 0x28) = 0;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
      *(int *)(lVar1 + 0x30) = iVar2;
    }
    if (iVar2 == 2) {
      *(undefined4 *)(lVar1 + 8) = 0x39;
      uVar3 = FUN_0010dd50(0,0,0);
    }
    else {
      *(undefined4 *)(lVar1 + 8) = 0x2a;
      uVar3 = FUN_0010d8e0(0,0,0);
    }
    *(undefined8 *)(param_1 + 0x60) = uVar3;
    *(undefined4 *)(lVar1 + 0x4c) = 0xfffffffe;
    FUN_0010cd60(lVar1);
  }
  else {
    uVar5 = 0xfffffffe;
  }
  return uVar5;
}



// Function: deflateReset @ 0x7150

ulong deflateReset(long param_1)

{
  ulong uVar1;
  
  uVar1 = FUN_001070a0();
  if ((int)uVar1 != 0) {
    return uVar1;
  }
  FUN_00105370(*(undefined8 *)(param_1 + 0x38));
  return uVar1 & 0xffffffff;
}



// Function: deflateSetHeader @ 0x7190

undefined8 deflateSetHeader(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_001050a0();
  if (((int)uVar1 == 0) && (*(int *)(*(long *)(param_1 + 0x38) + 0x30) == 2)) {
    *(undefined8 *)(*(long *)(param_1 + 0x38) + 0x38) = param_2;
    return uVar1;
  }
  return 0xfffffffe;
}



// Function: deflatePending @ 0x71c0

undefined8 deflatePending(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_001050a0();
  if ((int)uVar1 == 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = (int)*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x28);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(*(long *)(param_1 + 0x38) + 0x1734);
      return uVar1;
    }
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}



// Function: deflatePrime @ 0x7200

undefined4 deflatePrime(long param_1,uint param_2,uint param_3)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_001050a0();
  if (iVar3 == 0) {
    lVar1 = *(long *)(param_1 + 0x38);
    if ((param_2 < 0x11) && (*(long *)(lVar1 + 0x20) + 2U <= *(ulong *)(lVar1 + 0x1700))) {
      do {
        iVar3 = *(int *)(lVar1 + 0x1734);
        uVar2 = 0x10U - iVar3;
        if ((int)param_2 < (int)(0x10U - iVar3)) {
          uVar2 = param_2;
        }
        *(uint *)(lVar1 + 0x1734) = iVar3 + uVar2;
        *(ushort *)(lVar1 + 0x1730) =
             *(ushort *)(lVar1 + 0x1730) |
             (ushort)(((1 << ((byte)uVar2 & 0x1f)) - 1U & param_3) << ((byte)iVar3 & 0x1f));
        thunk_FUN_0010cc60(lVar1);
        param_3 = (int)param_3 >> ((byte)uVar2 & 0x1f);
        param_2 = param_2 - uVar2;
        uVar4 = 0;
      } while (param_2 != 0);
    }
    else {
      uVar4 = 0xfffffffb;
    }
  }
  else {
    uVar4 = 0xfffffffe;
  }
  return uVar4;
}



// Function: deflateTune @ 0x72b0

undefined8
deflateTune(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_001050a0();
  if ((int)uVar2 == 0) {
    lVar1 = *(long *)(param_1 + 0x38);
    *(undefined4 *)(lVar1 + 0xcc) = param_2;
    *(undefined4 *)(lVar1 + 0xc0) = param_3;
    *(undefined4 *)(lVar1 + 0xd0) = param_4;
    *(undefined4 *)(lVar1 + 0xbc) = param_5;
    return uVar2;
  }
  return 0xfffffffe;
}



// Function: deflateBound @ 0x7300

long deflateBound(long param_1,ulong param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  
  lVar8 = param_2 + 7;
  uVar7 = param_2 + 4 + (param_2 >> 3) + (param_2 >> 8) + (param_2 >> 9);
  uVar4 = (param_2 >> 5) + lVar8 + (param_2 >> 7) + (param_2 >> 0xb);
  iVar3 = FUN_001050a0();
  if (iVar3 != 0) {
    if (uVar4 <= uVar7) {
      uVar4 = uVar7;
    }
    return uVar4 + 6;
  }
  lVar1 = *(long *)(param_1 + 0x38);
  iVar3 = *(int *)(lVar1 + 0x30);
  if (iVar3 == 1) {
    uVar5 = (-(ulong)(*(int *)(lVar1 + 0xac) == 0) & 0xfffffffffffffffc) + 10;
  }
  else if (iVar3 == 2) {
    lVar2 = *(long *)(lVar1 + 0x38);
    uVar5 = 0x12;
    if (lVar2 != 0) {
      if (*(long *)(lVar2 + 0x18) != 0) {
        uVar5 = (ulong)(*(int *)(lVar2 + 0x20) + 2) + 0x12;
      }
      if (*(long *)(lVar2 + 0x28) != 0) {
        lVar6 = *(long *)(lVar2 + 0x28) - uVar5;
        do {
          uVar5 = uVar5 + 1;
        } while (*(char *)(lVar6 + -1 + uVar5) != '\0');
      }
      if (*(long *)(lVar2 + 0x38) != 0) {
        lVar6 = *(long *)(lVar2 + 0x38) - uVar5;
        do {
          uVar5 = uVar5 + 1;
        } while (*(char *)(lVar6 + -1 + uVar5) != '\0');
      }
      if (*(int *)(lVar2 + 0x44) != 0) {
        uVar5 = uVar5 + 2;
      }
    }
  }
  else {
    uVar5 = (ulong)(-(uint)(iVar3 != 0) & 6);
  }
  if ((*(uint *)(lVar1 + 0x54) == 0xf) && (*(uint *)(lVar1 + 0x88) == 0xf)) {
    return uVar5 + (param_2 >> 0xc) + lVar8 + (param_2 >> 0xe) + (param_2 >> 0x19);
  }
  if (*(uint *)(lVar1 + 0x88) < *(uint *)(lVar1 + 0x54)) {
    uVar7 = uVar4;
  }
  return uVar5 + uVar7;
}



// Function: deflate @ 0x7460

ulong deflate(long *param_1,uint param_2)

{
  undefined4 uVar1;
  long lVar2;
  int *piVar3;
  long lVar4;
  undefined8 uVar5;
  void *__s;
  int iVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  long lVar15;
  int iVar16;
  ulong uVar17;
  size_t __n;
  ulong uVar18;
  ulong uVar14;
  
  iVar8 = FUN_001050a0();
  if ((iVar8 != 0) || (5 < param_2)) {
    return 0xfffffffe;
  }
  lVar2 = param_1[7];
  if ((param_1[3] == 0) || ((lVar12 = param_1[1], (int)lVar12 != 0 && (*param_1 == 0)))) {
LAB_00107f61:
    param_1[6] = (long)PTR_s_stream_error_00116ca0;
    return 0xfffffffe;
  }
  iVar8 = *(int *)(lVar2 + 8);
  if ((iVar8 == 0x29a) && (param_2 != 4)) goto LAB_00107f61;
  if ((int)param_1[4] == 0) goto LAB_00107f77;
  iVar11 = *(int *)(lVar2 + 0x4c);
  *(uint *)(lVar2 + 0x4c) = param_2;
  if (*(long *)(lVar2 + 0x28) == 0) {
    if ((int)lVar12 == 0) {
      iVar16 = param_2 * 2;
      if (param_2 == 5) {
        iVar16 = 1;
      }
      iVar6 = iVar11 * 2;
      if (4 < iVar11) {
        iVar6 = iVar6 + -9;
      }
      if ((iVar16 <= iVar6) && (param_2 != 4)) goto LAB_00107f77;
      goto LAB_001075f1;
    }
    if (iVar8 == 0x29a) goto LAB_00107f77;
LAB_001074f9:
    if (iVar8 != 0x2a) {
LAB_001077d7:
      if (iVar8 == 0x39) {
        lVar13 = FUN_0010dd50(0,0,0);
        lVar12 = *(long *)(lVar2 + 0x10);
        param_1[0xc] = lVar13;
        lVar13 = *(long *)(lVar2 + 0x28);
        *(long *)(lVar2 + 0x28) = lVar13 + 1;
        *(undefined1 *)(lVar12 + lVar13) = 0x1f;
        lVar12 = *(long *)(lVar2 + 0x28);
        *(long *)(lVar2 + 0x28) = lVar12 + 1;
        *(undefined1 *)(*(long *)(lVar2 + 0x10) + lVar12) = 0x8b;
        lVar12 = *(long *)(lVar2 + 0x28);
        *(long *)(lVar2 + 0x28) = lVar12 + 1;
        *(undefined1 *)(*(long *)(lVar2 + 0x10) + lVar12) = 8;
        piVar3 = *(int **)(lVar2 + 0x38);
        if (piVar3 == (int *)0x0) {
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(undefined1 *)(*(long *)(lVar2 + 0x10) + lVar12) = 0;
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(undefined1 *)(*(long *)(lVar2 + 0x10) + lVar12) = 0;
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(undefined1 *)(*(long *)(lVar2 + 0x10) + lVar12) = 0;
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(undefined1 *)(*(long *)(lVar2 + 0x10) + lVar12) = 0;
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(undefined1 *)(*(long *)(lVar2 + 0x10) + lVar12) = 0;
          cVar7 = '\x02';
          if (*(int *)(lVar2 + 0xc4) != 9) {
            cVar7 = (1 < *(int *)(lVar2 + 200) || *(int *)(lVar2 + 0xc4) < 2) << 2;
          }
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = cVar7;
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(undefined1 *)(*(long *)(lVar2 + 0x10) + lVar12) = 3;
          *(undefined4 *)(lVar2 + 8) = 0x71;
          FUN_00105790(param_1);
          if (*(long *)(lVar2 + 0x28) != 0) goto LAB_001075a8;
          iVar8 = *(int *)(lVar2 + 8);
          goto LAB_00107b70;
        }
        iVar8 = piVar3[0x11];
        lVar12 = *(long *)(piVar3 + 6);
        iVar11 = *piVar3;
        lVar13 = *(long *)(piVar3 + 10);
        lVar15 = *(long *)(piVar3 + 0xe);
        lVar4 = *(long *)(lVar2 + 0x28);
        *(long *)(lVar2 + 0x28) = lVar4 + 1;
        *(char *)(*(long *)(lVar2 + 0x10) + lVar4) =
             (lVar15 != 0) * '\x10' +
             (((lVar12 != 0) * '\x04' + (iVar8 != 0) * '\x02' + '\x01') - (iVar11 == 0)) +
             (lVar13 != 0) * '\b';
        uVar5 = *(undefined8 *)(*(long *)(lVar2 + 0x38) + 8);
        lVar12 = *(long *)(lVar2 + 0x28);
        *(long *)(lVar2 + 0x28) = lVar12 + 1;
        *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)uVar5;
        uVar5 = *(undefined8 *)(*(long *)(lVar2 + 0x38) + 8);
        lVar12 = *(long *)(lVar2 + 0x28);
        *(long *)(lVar2 + 0x28) = lVar12 + 1;
        *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((ulong)uVar5 >> 8);
        lVar12 = *(long *)(lVar2 + 0x28);
        uVar5 = *(undefined8 *)(*(long *)(lVar2 + 0x38) + 8);
        *(long *)(lVar2 + 0x28) = lVar12 + 1;
        *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((ulong)uVar5 >> 0x10);
        lVar12 = *(long *)(lVar2 + 0x28);
        uVar5 = *(undefined8 *)(*(long *)(lVar2 + 0x38) + 8);
        *(long *)(lVar2 + 0x28) = lVar12 + 1;
        *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((ulong)uVar5 >> 0x18);
        cVar7 = '\x02';
        if (*(int *)(lVar2 + 0xc4) != 9) {
          cVar7 = (1 < *(int *)(lVar2 + 200) || *(int *)(lVar2 + 0xc4) < 2) << 2;
        }
        lVar12 = *(long *)(lVar2 + 0x28);
        *(long *)(lVar2 + 0x28) = lVar12 + 1;
        *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = cVar7;
        uVar1 = *(undefined4 *)(*(long *)(lVar2 + 0x38) + 0x14);
        lVar12 = *(long *)(lVar2 + 0x28);
        *(long *)(lVar2 + 0x28) = lVar12 + 1;
        *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)uVar1;
        lVar12 = *(long *)(lVar2 + 0x38);
        if (*(long *)(lVar12 + 0x18) != 0) {
          uVar1 = *(undefined4 *)(lVar12 + 0x20);
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)uVar1;
          uVar1 = *(undefined4 *)(*(long *)(lVar2 + 0x38) + 0x20);
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((uint)uVar1 >> 8);
          lVar12 = *(long *)(lVar2 + 0x38);
        }
        if (*(int *)(lVar12 + 0x44) != 0) {
          lVar12 = FUN_0010dd50(param_1[0xc],*(undefined8 *)(lVar2 + 0x10),
                                *(undefined4 *)(lVar2 + 0x28));
          param_1[0xc] = lVar12;
          lVar12 = *(long *)(lVar2 + 0x38);
        }
        *(undefined8 *)(lVar2 + 0x40) = 0;
        *(undefined4 *)(lVar2 + 8) = 0x45;
LAB_0010799e:
        lVar13 = *(long *)(lVar12 + 0x18);
        if (lVar13 != 0) {
          lVar15 = *(long *)(lVar2 + 0x40);
          uVar18 = *(ulong *)(lVar2 + 0x28);
          uVar14 = *(ulong *)(lVar2 + 0x18);
          __n = (size_t)((uint)*(ushort *)(lVar12 + 0x20) - (int)lVar15);
          uVar17 = uVar18;
          if (uVar14 < __n + uVar18) {
            do {
              iVar11 = (int)uVar14;
              iVar16 = (int)uVar18;
              uVar17 = (ulong)(uint)(iVar11 - iVar16);
              memcpy((void *)(uVar18 + *(long *)(lVar2 + 0x10)),(void *)(lVar13 + lVar15),uVar17);
              uVar14 = *(ulong *)(lVar2 + 0x18);
              iVar8 = *(int *)(*(long *)(lVar2 + 0x38) + 0x44);
              *(ulong *)(lVar2 + 0x28) = uVar14;
              if ((iVar8 != 0) && (uVar18 < uVar14)) {
                lVar12 = FUN_0010dd50(param_1[0xc],*(long *)(lVar2 + 0x10) + uVar18,
                                      (int)uVar14 - iVar16);
                param_1[0xc] = lVar12;
              }
              *(long *)(lVar2 + 0x40) = *(long *)(lVar2 + 0x40) + uVar17;
              FUN_00105790(param_1);
              if (*(long *)(lVar2 + 0x28) != 0) goto LAB_001075a8;
              uVar14 = *(ulong *)(lVar2 + 0x18);
              __n = (size_t)(uint)((iVar16 - iVar11) + (int)__n);
              lVar13 = *(long *)(*(long *)(lVar2 + 0x38) + 0x18);
              lVar15 = *(long *)(lVar2 + 0x40);
              uVar18 = 0;
              uVar17 = 0;
            } while (uVar14 < __n);
          }
          memcpy((void *)(uVar17 + *(long *)(lVar2 + 0x10)),(void *)(lVar13 + lVar15),__n);
          lVar12 = *(long *)(lVar2 + 0x38);
          uVar18 = __n + *(long *)(lVar2 + 0x28);
          *(ulong *)(lVar2 + 0x28) = uVar18;
          if ((*(int *)(lVar12 + 0x44) != 0) && (uVar17 < uVar18)) {
            lVar12 = FUN_0010dd50(param_1[0xc],*(long *)(lVar2 + 0x10) + uVar17,
                                  (int)uVar18 - (int)uVar17);
            param_1[0xc] = lVar12;
            lVar12 = *(long *)(lVar2 + 0x38);
          }
          *(undefined8 *)(lVar2 + 0x40) = 0;
        }
        *(undefined4 *)(lVar2 + 8) = 0x49;
LAB_00107c34:
        if (*(long *)(lVar12 + 0x28) != 0) {
          uVar18 = *(ulong *)(lVar2 + 0x28);
          uVar14 = uVar18;
          while( true ) {
            if (*(ulong *)(lVar2 + 0x18) == uVar18) {
              if ((*(int *)(lVar12 + 0x44) != 0) && (uVar14 < uVar18)) {
                lVar12 = FUN_0010dd50(param_1[0xc],uVar14 + *(long *)(lVar2 + 0x10),
                                      (int)uVar18 - (int)uVar14);
                param_1[0xc] = lVar12;
              }
              FUN_00105790(param_1);
              if (*(long *)(lVar2 + 0x28) != 0) goto LAB_001075a8;
              lVar12 = *(long *)(lVar2 + 0x38);
              uVar14 = 0;
              uVar18 = 0;
            }
            lVar12 = *(long *)(lVar12 + 0x28);
            lVar13 = *(long *)(lVar2 + 0x40);
            *(long *)(lVar2 + 0x40) = lVar13 + 1;
            cVar7 = *(char *)(lVar12 + lVar13);
            *(ulong *)(lVar2 + 0x28) = uVar18 + 1;
            *(char *)(*(long *)(lVar2 + 0x10) + uVar18) = cVar7;
            if (cVar7 == '\0') break;
            uVar18 = *(ulong *)(lVar2 + 0x28);
            lVar12 = *(long *)(lVar2 + 0x38);
          }
          lVar12 = *(long *)(lVar2 + 0x38);
          if ((*(int *)(lVar12 + 0x44) != 0) && (uVar14 < *(ulong *)(lVar2 + 0x28))) {
            lVar12 = FUN_0010dd50(param_1[0xc],uVar14 + *(long *)(lVar2 + 0x10),
                                  (int)*(ulong *)(lVar2 + 0x28) - (int)uVar14);
            param_1[0xc] = lVar12;
            lVar12 = *(long *)(lVar2 + 0x38);
          }
          *(undefined8 *)(lVar2 + 0x40) = 0;
        }
        *(undefined4 *)(lVar2 + 8) = 0x5b;
LAB_00107ce1:
        if (*(long *)(lVar12 + 0x38) == 0) {
LAB_00107e5d:
          iVar8 = *(int *)(lVar12 + 0x44);
LAB_00107dc0:
          *(undefined4 *)(lVar2 + 8) = 0x67;
          goto LAB_00107dc7;
        }
        uVar18 = *(ulong *)(lVar2 + 0x28);
        uVar14 = uVar18;
        while( true ) {
          if (*(ulong *)(lVar2 + 0x18) == uVar18) {
            if ((*(int *)(lVar12 + 0x44) != 0) && (uVar14 < uVar18)) {
              lVar12 = FUN_0010dd50(param_1[0xc],uVar14 + *(long *)(lVar2 + 0x10),
                                    (int)uVar18 - (int)uVar14);
              param_1[0xc] = lVar12;
            }
            FUN_00105790(param_1);
            if (*(long *)(lVar2 + 0x28) != 0) goto LAB_001075a8;
            lVar12 = *(long *)(lVar2 + 0x38);
            uVar14 = 0;
            uVar18 = 0;
          }
          lVar12 = *(long *)(lVar12 + 0x38);
          lVar13 = *(long *)(lVar2 + 0x40);
          *(long *)(lVar2 + 0x40) = lVar13 + 1;
          cVar7 = *(char *)(lVar12 + lVar13);
          *(ulong *)(lVar2 + 0x28) = uVar18 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + uVar18) = cVar7;
          if (cVar7 == '\0') break;
          uVar18 = *(ulong *)(lVar2 + 0x28);
          lVar12 = *(long *)(lVar2 + 0x38);
        }
        iVar8 = *(int *)(*(long *)(lVar2 + 0x38) + 0x44);
        if (iVar8 != 0) {
          if (uVar14 < *(ulong *)(lVar2 + 0x28)) {
            lVar12 = FUN_0010dd50(param_1[0xc],uVar14 + *(long *)(lVar2 + 0x10),
                                  (int)*(ulong *)(lVar2 + 0x28) - (int)uVar14);
            param_1[0xc] = lVar12;
            lVar12 = *(long *)(lVar2 + 0x38);
            goto LAB_00107e5d;
          }
          goto LAB_00107dc0;
        }
      }
      else {
LAB_00107b70:
        if (iVar8 == 0x45) {
          lVar12 = *(long *)(lVar2 + 0x38);
          goto LAB_0010799e;
        }
        if (iVar8 == 0x49) {
          lVar12 = *(long *)(lVar2 + 0x38);
          goto LAB_00107c34;
        }
        if (iVar8 == 0x5b) {
          lVar12 = *(long *)(lVar2 + 0x38);
          goto LAB_00107ce1;
        }
        if (iVar8 != 0x67) goto LAB_00107609;
        iVar8 = *(int *)(*(long *)(lVar2 + 0x38) + 0x44);
LAB_00107dc7:
        if (iVar8 != 0) {
          lVar12 = *(long *)(lVar2 + 0x28);
          if (*(ulong *)(lVar2 + 0x18) < lVar12 + 2U) {
            FUN_00105790(param_1);
            lVar12 = 0;
            if (*(long *)(lVar2 + 0x28) != 0) goto LAB_001075a8;
          }
          lVar13 = param_1[0xc];
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)lVar13;
          lVar12 = *(long *)(lVar2 + 0x28);
          lVar13 = param_1[0xc];
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((ulong)lVar13 >> 8);
          lVar12 = FUN_0010dd50(0,0,0);
          param_1[0xc] = lVar12;
        }
      }
      *(undefined4 *)(lVar2 + 8) = 0x71;
      FUN_00105790(param_1);
      if (*(long *)(lVar2 + 0x28) != 0) goto LAB_001075a8;
      goto LAB_00107609;
    }
    if (*(int *)(lVar2 + 0x30) != 0) {
      uVar10 = *(int *)(lVar2 + 0x54) * 0x1000 - 0x7800;
      uVar9 = uVar10;
      if ((*(int *)(lVar2 + 200) < 2) && (iVar8 = *(int *)(lVar2 + 0xc4), 1 < iVar8)) {
        if (iVar8 < 6) {
          uVar9 = uVar10 | 0x40;
        }
        else {
          uVar9 = uVar10 | 0xc0;
          if (iVar8 == 6) {
            uVar9 = uVar10 | 0x80;
          }
        }
      }
      if (*(int *)(lVar2 + 0xac) != 0) {
        uVar9 = uVar9 | 0x20;
      }
      FUN_00105130(lVar2,(uVar9 / 0x1f) * 0x1f + 0x1f);
      if (*(int *)(lVar2 + 0xac) != 0) {
        FUN_00105130();
        FUN_00105130();
      }
      lVar12 = FUN_0010d8e0(0,0,0);
      param_1[0xc] = lVar12;
      *(undefined4 *)(lVar2 + 8) = 0x71;
      FUN_00105790(param_1);
      if (*(long *)(lVar2 + 0x28) != 0) goto LAB_001075a8;
      iVar8 = *(int *)(lVar2 + 8);
      goto LAB_001077d7;
    }
    iVar8 = (int)param_1[1];
    *(undefined4 *)(lVar2 + 8) = 0x71;
  }
  else {
    FUN_00105790(param_1);
    if ((int)param_1[4] == 0) goto LAB_001075a8;
    iVar8 = *(int *)(lVar2 + 8);
LAB_001075f1:
    if (iVar8 != 0x29a) goto LAB_001074f9;
    if ((int)param_1[1] != 0) {
LAB_00107f77:
      param_1[6] = (long)PTR_s_buffer_error_00116cb8;
      return 0xfffffffb;
    }
LAB_00107609:
    iVar8 = (int)param_1[1];
  }
  if ((iVar8 == 0) && (*(int *)(lVar2 + 0xb4) == 0)) {
    if (param_2 == 0) {
      return 0;
    }
    if (*(int *)(lVar2 + 8) == 0x29a) goto LAB_00107638;
  }
  if (*(int *)(lVar2 + 0xc4) == 0) {
    uVar9 = FUN_001068b0(lVar2);
  }
  else if (*(int *)(lVar2 + 200) == 2) {
    uVar9 = FUN_001062c0(lVar2);
  }
  else if (*(int *)(lVar2 + 200) == 3) {
    uVar9 = FUN_001064d0(lVar2);
  }
  else {
    uVar9 = (*(code *)(&PTR_FUN_00116b88)[(long)*(int *)(lVar2 + 0xc4) * 2])(lVar2);
  }
  if (uVar9 - 2 < 2) {
    *(undefined4 *)(lVar2 + 8) = 0x29a;
    if ((uVar9 & 0xfffffffd) != 0) {
LAB_00107638:
      if (param_2 != 4) {
        return 0;
      }
      if (0 < *(int *)(lVar2 + 0x30)) {
        uVar18 = param_1[0xc];
        if (*(int *)(lVar2 + 0x30) == 2) {
          lVar12 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)uVar18;
          lVar12 = *(long *)(lVar2 + 0x28);
          lVar13 = param_1[0xc];
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((ulong)lVar13 >> 8);
          lVar12 = *(long *)(lVar2 + 0x28);
          lVar13 = param_1[0xc];
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((ulong)lVar13 >> 0x10);
          lVar12 = *(long *)(lVar2 + 0x28);
          lVar13 = param_1[0xc];
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((ulong)lVar13 >> 0x18);
          lVar12 = *(long *)(lVar2 + 0x28);
          lVar13 = param_1[2];
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)lVar13;
          lVar12 = *(long *)(lVar2 + 0x28);
          lVar13 = param_1[2];
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((ulong)lVar13 >> 8);
          lVar12 = *(long *)(lVar2 + 0x28);
          lVar13 = param_1[2];
          *(long *)(lVar2 + 0x28) = lVar12 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar12) = (char)((ulong)lVar13 >> 0x10);
          lVar12 = param_1[2];
          lVar13 = *(long *)(lVar2 + 0x28);
          *(long *)(lVar2 + 0x28) = lVar13 + 1;
          *(char *)(*(long *)(lVar2 + 0x10) + lVar13) = (char)((ulong)lVar12 >> 0x18);
        }
        else {
          FUN_00105130(lVar2,uVar18 >> 0x10);
          FUN_00105130();
        }
        FUN_00105790(param_1);
        if (0 < *(int *)(lVar2 + 0x30)) {
          *(int *)(lVar2 + 0x30) = -*(int *)(lVar2 + 0x30);
        }
        return (ulong)(*(long *)(lVar2 + 0x28) == 0);
      }
      return 1;
    }
  }
  else if ((uVar9 & 0xfffffffd) != 0) {
    if (uVar9 != 1) goto LAB_00107638;
    if (param_2 == 1) {
      FUN_0010cf00(lVar2);
    }
    else if (param_2 != 5) {
      FUN_0010cdd0(lVar2,0,0);
      if (param_2 != 3) {
        FUN_00105790(param_1);
        if ((int)param_1[4] != 0) goto LAB_00107638;
        goto LAB_001075a8;
      }
      __s = *(void **)(lVar2 + 0x78);
      uVar18 = (ulong)(*(int *)(lVar2 + 0x84) - 1);
      *(undefined2 *)((long)__s + uVar18 * 2) = 0;
      memset(__s,0,uVar18 * 2);
      if (*(int *)(lVar2 + 0xb4) == 0) {
        *(undefined4 *)(lVar2 + 0xac) = 0;
        *(undefined8 *)(lVar2 + 0x98) = 0;
        *(undefined4 *)(lVar2 + 0x172c) = 0;
      }
    }
    FUN_00105790(param_1);
  }
  if ((int)param_1[4] != 0) {
    return 0;
  }
LAB_001075a8:
  *(undefined4 *)(lVar2 + 0x4c) = 0xffffffff;
  return 0;
}



// Function: deflateParams @ 0x8030

undefined8 deflateParams(long param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  long lVar2;
  void *__s;
  int iVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  
  iVar3 = FUN_001050a0();
  if (iVar3 == 0) {
    lVar6 = (long)(int)param_2;
    lVar2 = *(long *)(param_1 + 0x38);
    if (param_2 == 0xffffffff) {
      lVar6 = 6;
    }
    if ((param_3 < 5) && (param_2 == 0xffffffff || param_2 < 10)) {
      iVar3 = *(int *)(lVar2 + 0xc4);
      iVar5 = (int)lVar6;
      if (((*(uint *)(lVar2 + 200) != param_3) ||
          ((&PTR_FUN_00116b88)[(long)iVar5 * 2] != (&PTR_FUN_00116b88)[(long)iVar3 * 2])) &&
         (*(int *)(lVar2 + 0x4c) != -2)) {
        iVar3 = FUN_00107460(param_1,5);
        if (iVar3 == -2) {
          return 0xfffffffe;
        }
        if ((*(int *)(param_1 + 8) != 0) ||
           (((ulong)*(uint *)(lVar2 + 0xac) - *(long *)(lVar2 + 0x98)) +
            (ulong)*(uint *)(lVar2 + 0xb4) != 0)) {
          return 0xfffffffb;
        }
        iVar3 = *(int *)(lVar2 + 0xc4);
      }
      if (iVar5 != iVar3) {
        if ((iVar3 == 0) && (*(int *)(lVar2 + 0x1728) != 0)) {
          if (*(int *)(lVar2 + 0x1728) == 1) {
            FUN_00105020(lVar2);
          }
          else {
            __s = *(void **)(lVar2 + 0x78);
            uVar4 = (ulong)(*(int *)(lVar2 + 0x84) - 1);
            *(undefined2 *)((long)__s + uVar4 * 2) = 0;
            memset(__s,0,uVar4 * 2);
          }
          *(undefined4 *)(lVar2 + 0x1728) = 0;
        }
        *(int *)(lVar2 + 0xc4) = iVar5;
        lVar6 = lVar6 * 0x10;
        *(uint *)(lVar2 + 0xc0) = (uint)*(ushort *)(&DAT_00116b82 + lVar6);
        *(uint *)(lVar2 + 0xcc) = (uint)*(ushort *)(&DAT_00116b80 + lVar6);
        uVar1 = *(ushort *)(&DAT_00116b86 + lVar6);
        *(uint *)(lVar2 + 0xd0) = (uint)*(ushort *)(&DAT_00116b84 + lVar6);
        *(uint *)(lVar2 + 0xbc) = (uint)uVar1;
      }
      *(uint *)(lVar2 + 200) = param_3;
      return 0;
    }
  }
  return 0xfffffffe;
}



// Function: deflateEnd @ 0x8200

undefined8 deflateEnd(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = param_1;
  iVar1 = FUN_001050a0();
  if (iVar1 == 0) {
    lVar2 = *(long *)(lVar3 + 0x38);
    uVar4 = 0;
    iVar1 = *(int *)(lVar2 + 8);
    if (*(long *)(lVar2 + 0x10) != 0) {
      (**(code **)(param_1 + 0x48))(*(undefined8 *)(lVar3 + 0x50),*(long *)(lVar2 + 0x10));
      lVar2 = *(long *)(param_1 + 0x38);
    }
    if (*(long *)(lVar2 + 0x78) != 0) {
      (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x50),*(long *)(lVar2 + 0x78));
      lVar2 = *(long *)(param_1 + 0x38);
    }
    if (*(long *)(lVar2 + 0x70) != 0) {
      (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x50),*(long *)(lVar2 + 0x70));
      lVar2 = *(long *)(param_1 + 0x38);
    }
    if (*(long *)(lVar2 + 0x60) != 0) {
      (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x50),*(long *)(lVar2 + 0x60));
      lVar2 = *(long *)(param_1 + 0x38);
    }
    (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x50),lVar2);
    *(undefined8 *)(param_1 + 0x38) = 0;
    if (iVar1 == 0x71) {
      uVar4 = 0xfffffffd;
    }
  }
  else {
    uVar4 = 0xfffffffe;
  }
  return uVar4;
}



// Function: deflateInit2_ @ 0x82b0

undefined8
deflateInit2_(long param_1,uint param_2,int param_3,int param_4,int param_5,uint param_6,
            char *param_7,int param_8)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  
  if (((param_7 == (char *)0x0) || (*param_7 != '1')) || (param_8 != 0x70)) {
    return 0xfffffffa;
  }
  if (param_1 != 0) {
    *(undefined8 *)(param_1 + 0x30) = 0;
    if (*(long *)(param_1 + 0x40) == 0) {
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(code **)(param_1 + 0x40) = FUN_0010d360;
    }
    if (*(long *)(param_1 + 0x48) == 0) {
      *(code **)(param_1 + 0x48) = FUN_0010d370;
    }
    if (param_2 == 0xffffffff) {
      param_2 = 6;
    }
    if (param_4 < 0) {
      if (param_4 < -0xf) {
        return 0xfffffffe;
      }
      param_4 = -param_4;
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
      if (0xf < param_4) {
        param_4 = param_4 + -0x10;
        iVar3 = 2;
      }
    }
    if ((((param_5 - 1U < 9) && (param_4 - 8U < 8)) &&
        ((param_3 == 8 && ((param_2 < 10 && (param_6 < 5)))))) && ((param_4 != 8 || (iVar3 == 1))))
    {
      if (param_4 == 8) {
        param_4 = 9;
      }
      plVar4 = (long *)(**(code **)(param_1 + 0x40))(*(undefined8 *)(param_1 + 0x50),1,0x1740);
      if (plVar4 == (long *)0x0) {
        return 0xfffffffc;
      }
      *(long **)(param_1 + 0x38) = plVar4;
      *plVar4 = param_1;
      uVar6 = *(undefined8 *)(param_1 + 0x50);
      *(int *)(plVar4 + 6) = iVar3;
      iVar7 = 1 << ((byte)param_4 & 0x1f);
      *(undefined4 *)(plVar4 + 1) = 0x2a;
      *(int *)(plVar4 + 10) = iVar7;
      plVar4[7] = 0;
      *(int *)((long)plVar4 + 0x54) = param_4;
      *(int *)(plVar4 + 0xb) = iVar7 + -1;
      iVar3 = 1 << ((byte)(param_5 + 7) & 0x1f);
      *(int *)(plVar4 + 0x11) = param_5 + 7;
      *(int *)((long)plVar4 + 0x84) = iVar3;
      *(int *)((long)plVar4 + 0x8c) = iVar3 + -1;
      *(uint *)(plVar4 + 0x12) = (param_5 + 9U) / 3;
      lVar5 = (**(code **)(param_1 + 0x40))(uVar6,iVar7,2);
      uVar6 = *(undefined8 *)(param_1 + 0x50);
      plVar4[0xc] = lVar5;
      lVar5 = (**(code **)(param_1 + 0x40))(uVar6,(int)plVar4[10],2);
      uVar6 = *(undefined8 *)(param_1 + 0x50);
      plVar4[0xe] = lVar5;
      lVar5 = (**(code **)(param_1 + 0x40))(uVar6,*(undefined4 *)((long)plVar4 + 0x84),2);
      uVar6 = *(undefined8 *)(param_1 + 0x50);
      iVar3 = 1 << ((char)param_5 + 6U & 0x1f);
      plVar4[0xf] = lVar5;
      *(int *)(plVar4 + 0x2e1) = iVar3;
      plVar4[0x2e7] = 0;
      lVar5 = (**(code **)(param_1 + 0x40))(uVar6,iVar3,4);
      uVar1 = *(uint *)(plVar4 + 0x2e1);
      plVar4[2] = lVar5;
      plVar4[3] = (ulong)uVar1 * 4;
      puVar2 = PTR_s_insufficient_memory_00116cb0;
      if ((((plVar4[0xc] != 0) && (plVar4[0xe] != 0)) && (plVar4[0xf] != 0)) && (lVar5 != 0)) {
        *(uint *)((long)plVar4 + 0xc4) = param_2;
        plVar4[0x2e0] = lVar5 + (ulong)uVar1;
        *(uint *)(plVar4 + 0x2e2) = uVar1 * 3 + -3;
        *(uint *)(plVar4 + 0x19) = param_6;
        *(undefined1 *)(plVar4 + 9) = 8;
        uVar6 = FUN_00107150(param_1);
        return uVar6;
      }
      *(undefined4 *)(plVar4 + 1) = 0x29a;
      *(undefined **)(param_1 + 0x30) = puVar2;
      FUN_00108200(param_1);
      return 0xfffffffc;
    }
  }
  return 0xfffffffe;
}



// Function: deflateInit_ @ 0x85a0

void deflateInit_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_001082b0(param_1,param_2,8,0xf,8,0,param_3,param_4);
  return;
}



// Function: deflateCopy @ 0x85d0

undefined8 deflateCopy(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  byte bVar10;
  
  bVar10 = 0;
  iVar2 = FUN_001050a0(param_2);
  if ((param_1 == (undefined8 *)0x0) || (iVar2 != 0)) {
    uVar5 = 0xfffffffe;
  }
  else {
    uVar5 = param_2[1];
    puVar1 = (undefined8 *)param_2[7];
    *param_1 = *param_2;
    param_1[1] = uVar5;
    uVar5 = param_2[3];
    param_1[2] = param_2[2];
    param_1[3] = uVar5;
    uVar5 = param_2[5];
    param_1[4] = param_2[4];
    param_1[5] = uVar5;
    uVar5 = param_2[7];
    param_1[6] = param_2[6];
    param_1[7] = uVar5;
    uVar5 = param_2[9];
    param_1[8] = param_2[8];
    param_1[9] = uVar5;
    uVar5 = param_2[0xb];
    param_1[10] = param_2[10];
    param_1[0xb] = uVar5;
    uVar5 = param_2[0xd];
    param_1[0xc] = param_2[0xc];
    param_1[0xd] = uVar5;
    puVar3 = (undefined8 *)(*(code *)param_1[8])(param_1[10],1,0x1740);
    if (puVar3 == (undefined8 *)0x0) {
      uVar5 = 0xfffffffc;
    }
    else {
      param_1[7] = puVar3;
      *puVar3 = *puVar1;
      lVar6 = (long)puVar3 - (long)((ulong)(puVar3 + 1) & 0xfffffffffffffff8);
      puVar3[0x2e7] = puVar1[0x2e7];
      puVar8 = (undefined8 *)((long)puVar1 - lVar6);
      puVar9 = (undefined8 *)((ulong)(puVar3 + 1) & 0xfffffffffffffff8);
      for (uVar7 = (ulong)((int)lVar6 + 0x1740U >> 3); uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + (ulong)bVar10 * -2 + 1;
        puVar9 = puVar9 + (ulong)bVar10 * -2 + 1;
      }
      *puVar3 = param_1;
      uVar4 = (*(code *)param_1[8])(param_1[10],*(undefined4 *)(puVar3 + 10),2);
      uVar5 = param_1[10];
      puVar3[0xc] = uVar4;
      uVar4 = (*(code *)param_1[8])(uVar5,*(undefined4 *)(puVar3 + 10),2);
      uVar5 = param_1[10];
      puVar3[0xe] = uVar4;
      uVar4 = (*(code *)param_1[8])(uVar5,*(undefined4 *)((long)puVar3 + 0x84),2);
      uVar5 = param_1[10];
      puVar3[0xf] = uVar4;
      lVar6 = (*(code *)param_1[8])(uVar5,*(undefined4 *)(puVar3 + 0x2e1),4);
      puVar3[2] = lVar6;
      if (((((void *)puVar3[0xc] == (void *)0x0) || (puVar3[0xe] == 0)) || (puVar3[0xf] == 0)) ||
         (lVar6 == 0)) {
        FUN_00108200(param_1);
        uVar5 = 0xfffffffc;
      }
      else {
        memcpy((void *)puVar3[0xc],(void *)puVar1[0xc],(ulong)(uint)(*(int *)(puVar3 + 10) * 2));
        memcpy((void *)puVar3[0xe],(void *)puVar1[0xe],(ulong)*(uint *)(puVar3 + 10) * 2);
        memcpy((void *)puVar3[0xf],(void *)puVar1[0xf],(ulong)*(uint *)((long)puVar3 + 0x84) * 2);
        memcpy((void *)puVar3[2],(void *)puVar1[2],(ulong)*(uint *)(puVar3 + 3));
        puVar3[4] = (puVar1[4] + puVar3[2]) - puVar1[2];
        puVar3[0x2e0] = puVar3[2] + (ulong)*(uint *)(puVar3 + 0x2e1);
        puVar3[0x16b] = (long)puVar3 + 0xd4;
        puVar3[0x16e] = puVar3 + 0x139;
        puVar3[0x171] = (long)puVar3 + 0xabc;
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}



// Function: inflateStateCheck @ 0x87d0

bool inflateStateCheck(long param_1)

{
  long *plVar1;
  
  if (((param_1 != 0) && (*(long *)(param_1 + 0x40) != 0)) && (*(long *)(param_1 + 0x48) != 0)) {
    plVar1 = *(long **)(param_1 + 0x38);
    if ((plVar1 != (long *)0x0) && (*plVar1 == param_1)) {
      return 0x1f < (int)plVar1[1] - 0x3f34U;
    }
    return true;
  }
  return true;
}



// Function: fixedtables @ 0x8820

void fixedtables(long param_1)

{
  *(undefined **)(param_1 + 0x68) = &DAT_0010f680;
  *(undefined **)(param_1 + 0x70) = &DAT_0010f600;
  *(undefined8 *)(param_1 + 0x78) = 0x500000009;
  return;
}



// Function: syncsearch @ 0x8850

void syncsearch(uint *param_1,long param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *param_1;
  bVar1 = uVar4 < 4;
  uVar3 = 0;
  if (param_3 != 0 && bVar1) {
    do {
      if (*(byte *)(param_2 + (ulong)uVar3) == (byte)~-(uVar4 < 2)) {
        uVar4 = uVar4 + 1;
        bVar2 = uVar4 < 4;
      }
      else if (*(byte *)(param_2 + (ulong)uVar3) == 0) {
        uVar4 = 4 - uVar4;
        bVar2 = uVar4 < 4;
      }
      else {
        uVar4 = 0;
        bVar2 = param_3 != 0 && bVar1;
      }
    } while ((uVar3 + 1 < param_3) && (uVar3 = uVar3 + 1, bVar2));
  }
  *param_1 = uVar4;
  return;
}



// Function: updatewindow @ 0x88d0

undefined8 updatewindow(long param_1,long param_2,uint param_3)

{
  long lVar1;
  uint uVar2;
  void *__dest;
  uint uVar3;
  
  lVar1 = *(long *)(param_1 + 0x38);
  __dest = *(void **)(lVar1 + 0x48);
  if (__dest == (void *)0x0) {
    __dest = (void *)(**(code **)(param_1 + 0x40))
                               (*(undefined8 *)(param_1 + 0x50),
                                1 << ((byte)*(undefined4 *)(lVar1 + 0x38) & 0x1f),1);
    *(void **)(lVar1 + 0x48) = __dest;
    if (__dest == (void *)0x0) {
      return 1;
    }
  }
  uVar3 = *(uint *)(lVar1 + 0x3c);
  if (uVar3 == 0) {
    *(undefined8 *)(lVar1 + 0x40) = 0;
    uVar3 = 1 << ((byte)*(undefined4 *)(lVar1 + 0x38) & 0x1f);
    *(uint *)(lVar1 + 0x3c) = uVar3;
  }
  if (param_3 < uVar3) {
    uVar3 = uVar3 - *(int *)(lVar1 + 0x44);
    if (param_3 < uVar3) {
      uVar3 = param_3;
    }
    memcpy((void *)((long)__dest + (ulong)*(uint *)(lVar1 + 0x44)),
           (void *)(param_2 - (ulong)param_3),(ulong)uVar3);
    param_3 = param_3 - uVar3;
    if (param_3 != 0) {
      memcpy(*(void **)(lVar1 + 0x48),(void *)(param_2 - (ulong)param_3),(ulong)param_3);
      *(uint *)(lVar1 + 0x44) = param_3;
      *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(lVar1 + 0x3c);
      return 0;
    }
    uVar2 = *(int *)(lVar1 + 0x44) + uVar3;
    if (uVar2 == *(uint *)(lVar1 + 0x3c)) {
      uVar2 = 0;
    }
    *(uint *)(lVar1 + 0x44) = uVar2;
    if (*(uint *)(lVar1 + 0x40) < *(uint *)(lVar1 + 0x3c)) {
      *(uint *)(lVar1 + 0x40) = *(uint *)(lVar1 + 0x40) + uVar3;
      return 0;
    }
  }
  else {
    memcpy(__dest,(void *)(param_2 - (ulong)uVar3),(ulong)uVar3);
    *(undefined4 *)(lVar1 + 0x44) = 0;
    *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(lVar1 + 0x3c);
  }
  return 0;
}



// Function: inflateResetKeep @ 0x8a00

undefined8 inflateResetKeep(long param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_001087d0();
  if ((int)uVar4 == 0) {
    lVar3 = *(long *)(param_1 + 0x38);
    uVar2 = *(uint *)(lVar3 + 0x10);
    *(undefined8 *)(lVar3 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x10) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    if (uVar2 != 0) {
      *(ulong *)(param_1 + 0x60) = (ulong)(uVar2 & 1);
    }
    lVar1 = lVar3 + 0x558;
    *(undefined8 *)(lVar3 + 8) = 0x3f34;
    *(undefined8 *)(lVar3 + 0x18) = 0x8000ffffffff;
    *(undefined4 *)(lVar3 + 0x14) = 0;
    *(undefined8 *)(lVar3 + 0x30) = 0;
    *(undefined8 *)(lVar3 + 0x50) = 0;
    *(undefined4 *)(lVar3 + 0x58) = 0;
    *(long *)(lVar3 + 0x90) = lVar1;
    *(long *)(lVar3 + 0x70) = lVar1;
    *(long *)(lVar3 + 0x68) = lVar1;
    *(undefined8 *)(lVar3 + 0x1be8) = 0xffffffff00000001;
    return uVar4;
  }
  return 0xfffffffe;
}



// Function: inflateReset @ 0x8ab0

undefined8 inflateReset(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = FUN_001087d0();
  if (iVar2 == 0) {
    lVar1 = *(long *)(param_1 + 0x38);
    *(undefined4 *)(lVar1 + 0x3c) = 0;
    *(undefined8 *)(lVar1 + 0x40) = 0;
    uVar3 = FUN_00108a00();
    return uVar3;
  }
  return 0xfffffffe;
}



// Function: inflateReset2 @ 0x8ae0

undefined8 inflateReset2(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = FUN_001087d0();
  if (iVar2 == 0) {
    lVar1 = *(long *)(param_1 + 0x38);
    if ((int)param_2 < 0) {
      if ((int)param_2 < -0xf) {
        return 0xfffffffe;
      }
      param_2 = -param_2;
      iVar2 = 0;
    }
    else {
      iVar2 = ((int)param_2 >> 4) + 5;
      if ((int)param_2 < 0x30) {
        param_2 = param_2 & 0xf;
      }
    }
    if ((param_2 - 8 < 8) || (param_2 == 0)) {
      if ((*(long *)(lVar1 + 0x48) != 0) && (param_2 != *(uint *)(lVar1 + 0x38))) {
        (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x50));
        *(undefined8 *)(lVar1 + 0x48) = 0;
      }
      *(int *)(lVar1 + 0x10) = iVar2;
      *(uint *)(lVar1 + 0x38) = param_2;
      uVar3 = FUN_00108ab0(param_1);
      return uVar3;
    }
  }
  return 0xfffffffe;
}



// Function: inflateInit2_ @ 0x8b80

int inflateInit2_(long param_1,undefined4 param_2,char *param_3,int param_4)

{
  int iVar1;
  long *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (((param_3 == (char *)0x0) || (*param_3 != '1')) || (param_4 != 0x70)) {
    iVar1 = -6;
  }
  else if (param_1 == 0) {
    iVar1 = -2;
  }
  else {
    pcVar3 = *(code **)(param_1 + 0x40);
    *(undefined8 *)(param_1 + 0x30) = 0;
    if (pcVar3 == (code *)0x0) {
      pcVar3 = FUN_0010d360;
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(code **)(param_1 + 0x40) = FUN_0010d360;
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined8 *)(param_1 + 0x50);
    }
    if (*(long *)(param_1 + 0x48) == 0) {
      *(code **)(param_1 + 0x48) = FUN_0010d370;
    }
    plVar2 = (long *)(*pcVar3)(uVar4,1,0x1bf8);
    if (plVar2 == (long *)0x0) {
      iVar1 = -4;
    }
    else {
      *(long **)(param_1 + 0x38) = plVar2;
      *plVar2 = param_1;
      plVar2[9] = 0;
      *(undefined4 *)(plVar2 + 1) = 0x3f34;
      iVar1 = FUN_00108ae0(param_1,param_2);
      if (iVar1 != 0) {
        (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x50),plVar2);
        *(undefined8 *)(param_1 + 0x38) = 0;
      }
    }
  }
  return iVar1;
}



// Function: inflateInit_ @ 0x8c70

void inflateInit_(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00108b80(param_1,0xf,param_2,param_3);
  return;
}



// Function: inflatePrime @ 0x8c90

undefined8 inflatePrime(long param_1,int param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  
  uVar3 = FUN_001087d0();
  if ((int)uVar3 == 0) {
    lVar2 = *(long *)(param_1 + 0x38);
    if (param_2 < 0) {
      *(undefined8 *)(lVar2 + 0x50) = 0;
      *(undefined4 *)(lVar2 + 0x58) = 0;
      return uVar3;
    }
    if (param_2 < 0x11) {
      iVar1 = *(int *)(lVar2 + 0x58);
      uVar4 = param_2 + iVar1;
      if (uVar4 < 0x21) {
        *(uint *)(lVar2 + 0x58) = uVar4;
        *(long *)(lVar2 + 0x50) =
             *(long *)(lVar2 + 0x50) +
             (ulong)(((int)(1L << ((byte)param_2 & 0x3f)) - 1U & param_3) << ((byte)iVar1 & 0x1f));
        return uVar3;
      }
    }
  }
  return 0xfffffffe;
}



// Function: inflate @ 0x8d00

/* WARNING: Type propagation algorithm not settling */

int inflate(long *param_1,int param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  void *pvVar12;
  long lVar13;
  undefined8 uVar14;
  ushort *puVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  byte *extraout_RDX;
  uint uVar23;
  byte *pbVar24;
  ushort uVar25;
  undefined2 uVar26;
  ulong uVar27;
  uint uVar28;
  uint uVar29;
  ulong uVar30;
  undefined1 *__dest;
  byte *pbVar31;
  uint uVar32;
  long in_FS_OFFSET;
  bool bVar33;
  uint local_80;
  int local_70;
  undefined4 local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar6 = FUN_001087d0();
  if ((iVar6 == 0) && (__dest = (undefined1 *)param_1[3], __dest != (undefined1 *)0x0)) {
    uVar2 = *(uint *)(param_1 + 1);
    pbVar31 = (byte *)*param_1;
    if ((pbVar31 != (byte *)0x0) || (uVar2 == 0)) {
      lVar4 = param_1[7];
      iVar6 = *(int *)(lVar4 + 8);
      if (iVar6 == 0x3f3f) {
        *(undefined4 *)(lVar4 + 8) = 0x3f40;
        iVar6 = 0x3f40;
      }
      uVar3 = *(uint *)(param_1 + 4);
      uVar30 = *(ulong *)(lVar4 + 0x50);
      uVar20 = *(uint *)(lVar4 + 0x58);
      uVar23 = uVar2;
      local_80 = uVar3;
LAB_00108d91:
      local_70 = 0;
      uVar32 = uVar3;
      switch(iVar6) {
      case 0x3f34:
        uVar19 = *(uint *)(lVar4 + 0x10);
        if (uVar19 != 0) {
          if (0xf < uVar20) goto LAB_0010a1a4;
          uVar28 = uVar23;
          if (uVar23 != 0) goto LAB_0010a188;
          goto LAB_00109b70;
        }
        *(undefined4 *)(lVar4 + 8) = 0x3f40;
      case 0x3f40:
switchD_00108dad_caseD_3f40:
        bVar18 = (byte)uVar20;
        if (*(int *)(lVar4 + 0xc) != 0) {
          *(undefined4 *)(lVar4 + 8) = 0x3f4e;
          uVar20 = uVar20 & 0xfffffff8;
          uVar30 = uVar30 >> (bVar18 & 7);
          goto LAB_00108e9a;
        }
        if (uVar20 < 3) {
          if (uVar23 != 0) {
            bVar16 = *pbVar31;
            uVar23 = uVar23 - 1;
            pbVar31 = pbVar31 + 1;
            uVar20 = uVar20 + 8;
            uVar30 = uVar30 + ((ulong)bVar16 << (bVar18 & 0x3f));
            goto LAB_00109069;
          }
LAB_0010a6fe:
          local_70 = 0;
          uVar32 = uVar3 - local_80;
          goto LAB_001091b0;
        }
LAB_00109069:
        *(uint *)(lVar4 + 0xc) = (uint)uVar30 & 1;
        uVar19 = (uint)(uVar30 >> 1) & 3;
        if (uVar19 == 2) {
          *(undefined4 *)(lVar4 + 8) = 0x3f44;
          uVar30 = uVar30 >> 3;
          uVar20 = uVar20 - 3;
switchD_00108dad_caseD_3f44:
          if (uVar20 < 0xe) {
            uVar28 = uVar23;
            if (uVar23 == 0) goto LAB_00109b70;
            while( true ) {
              bVar18 = *pbVar31;
              pbVar31 = pbVar31 + 1;
              uVar23 = uVar23 - 1;
              bVar16 = (byte)uVar20;
              uVar20 = uVar20 + 8;
              uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
              if (0xd < uVar20) break;
              uVar28 = uVar23;
              if (uVar23 == 0) goto LAB_00109b88;
            }
          }
          uVar20 = uVar20 - 0xe;
          uVar11 = uVar30 >> 5;
          uVar27 = uVar30 >> 10;
          uVar22 = ((uint)uVar30 & 0x1f) + 0x101;
          uVar30 = uVar30 >> 0xe;
          uVar28 = ((uint)uVar11 & 0x1f) + 1;
          uVar19 = ((uint)uVar27 & 0xf) + 4;
          *(uint *)(lVar4 + 0x84) = uVar22;
          *(uint *)(lVar4 + 0x88) = uVar28;
          *(uint *)(lVar4 + 0x80) = uVar19;
          if ((uVar28 < 0x1f) && (uVar22 < 0x11f)) {
            *(undefined4 *)(lVar4 + 0x8c) = 0;
            uVar11 = 0;
            *(undefined4 *)(lVar4 + 8) = 0x3f45;
joined_r0x0010955b:
            while( true ) {
              if (uVar20 < 3) {
                uVar28 = 0;
                if (uVar23 == 0) goto LAB_00109b88;
                bVar18 = *pbVar31;
                uVar23 = uVar23 - 1;
                pbVar31 = pbVar31 + 1;
                bVar16 = (byte)uVar20;
                uVar20 = uVar20 + 8;
                uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
              }
              uVar28 = (int)uVar11 + 1;
              uVar20 = uVar20 - 3;
              uVar25 = (&DAT_0010fe80)[uVar11];
              uVar5 = (ushort)uVar30;
              *(uint *)(lVar4 + 0x8c) = uVar28;
              uVar30 = uVar30 >> 3;
              *(ushort *)(lVar4 + 0x98 + (ulong)uVar25 * 2) = uVar5 & 7;
              if (uVar19 <= uVar28) break;
              uVar11 = (ulong)uVar28;
            }
            uVar11 = (ulong)uVar28;
LAB_0010a362:
            if ((uint)uVar11 < 0x13) {
              puVar15 = &DAT_0010fe80 + uVar11;
              do {
                uVar25 = *puVar15;
                puVar15 = puVar15 + 1;
                *(undefined2 *)(lVar4 + 0x98 + (ulong)uVar25 * 2) = 0;
              } while ((ushort *)(&DAT_0010fe82 + ((0x12 - (uint)uVar11) + uVar11) * 2) != puVar15);
              *(undefined4 *)(lVar4 + 0x8c) = 0x13;
            }
            *(undefined4 *)(lVar4 + 0x78) = 7;
            *(long *)(lVar4 + 0x90) = lVar4 + 0x558;
            *(long *)(lVar4 + 0x68) = lVar4 + 0x558;
            iVar6 = FUN_0010b130(0,lVar4 + 0x98,0x13,lVar4 + 0x90,lVar4 + 0x78,lVar4 + 0x318);
            if (iVar6 == 0) {
              *(undefined4 *)(lVar4 + 0x8c) = 0;
              uVar11 = 0;
              *(undefined4 *)(lVar4 + 8) = 0x3f46;
LAB_001095c7:
              iVar6 = *(int *)(lVar4 + 0x84);
              uVar19 = *(int *)(lVar4 + 0x88) + iVar6;
              if ((uint)uVar11 < uVar19) {
                lVar13 = *(long *)(lVar4 + 0x68);
                uVar22 = ~(-1 << ((byte)*(undefined4 *)(lVar4 + 0x78) & 0x1f));
                do {
                  lVar1 = lVar13 + (ulong)(uVar22 & (uint)uVar30) * 4;
                  bVar18 = *(byte *)(lVar1 + 1);
                  uVar8 = (uint)bVar18;
                  uVar25 = *(ushort *)(lVar1 + 2);
                  if (uVar20 < uVar8) {
                    uVar28 = uVar23;
                    if (uVar23 == 0) goto LAB_00109b70;
                    while( true ) {
                      bVar18 = *pbVar31;
                      pbVar31 = pbVar31 + 1;
                      uVar23 = uVar23 - 1;
                      bVar16 = (byte)uVar20;
                      uVar20 = uVar20 + 8;
                      uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
                      lVar1 = lVar13 + (ulong)(uVar22 & (uint)uVar30) * 4;
                      bVar18 = *(byte *)(lVar1 + 1);
                      uVar25 = *(ushort *)(lVar1 + 2);
                      uVar8 = (uint)bVar18;
                      if (uVar8 <= uVar20) break;
                      uVar28 = uVar23;
                      if (uVar23 == 0) goto LAB_00109b88;
                    }
                  }
                  iVar7 = (int)uVar11;
                  if (0xf < uVar25) {
                    bVar18 = (byte)uVar8;
                    uVar28 = uVar23;
                    if (uVar25 == 0x10) {
                      if (uVar20 < uVar8 + 2) {
                        if (uVar23 == 0) goto LAB_00109b70;
                        while( true ) {
                          bVar16 = *pbVar31;
                          pbVar31 = pbVar31 + 1;
                          uVar23 = uVar23 - 1;
                          bVar17 = (byte)uVar20;
                          uVar20 = uVar20 + 8;
                          uVar30 = uVar30 + ((ulong)bVar16 << (bVar17 & 0x3f));
                          if (uVar8 + 2 <= uVar20) break;
                          uVar28 = uVar23;
                          if (uVar23 == 0) goto LAB_00109b88;
                        }
                      }
                      uVar20 = uVar20 - uVar8;
                      uVar30 = uVar30 >> (bVar18 & 0x3f);
                      if (iVar7 != 0) {
                        uVar27 = uVar30 >> 2;
                        uVar20 = uVar20 - 2;
                        uVar26 = *(undefined2 *)(lVar4 + 0x98 + (ulong)(iVar7 - 1) * 2);
                        iVar21 = ((uint)uVar30 & 3) + 3;
                        goto LAB_001096d1;
                      }
                    }
                    else {
                      if (uVar25 == 0x11) {
                        if (uVar20 < uVar8 + 3) {
                          if (uVar23 == 0) goto LAB_00109b70;
                          while( true ) {
                            bVar16 = *pbVar31;
                            pbVar31 = pbVar31 + 1;
                            uVar23 = uVar23 - 1;
                            bVar17 = (byte)uVar20;
                            uVar20 = uVar20 + 8;
                            uVar30 = uVar30 + ((ulong)bVar16 << (bVar17 & 0x3f));
                            if (uVar8 + 3 <= uVar20) break;
                            uVar28 = uVar23;
                            if (uVar23 == 0) goto LAB_00109b88;
                          }
                        }
                        uVar30 = uVar30 >> (bVar18 & 0x3f);
                        uVar20 = uVar20 + (-3 - uVar8);
                        uVar27 = uVar30 >> 3;
                        uVar26 = 0;
                        iVar21 = ((uint)uVar30 & 7) + 3;
                      }
                      else {
                        if (uVar20 < uVar8 + 7) {
                          if (uVar23 == 0) goto LAB_00109b70;
                          while( true ) {
                            bVar16 = *pbVar31;
                            pbVar31 = pbVar31 + 1;
                            uVar23 = uVar23 - 1;
                            bVar17 = (byte)uVar20;
                            uVar20 = uVar20 + 8;
                            uVar30 = uVar30 + ((ulong)bVar16 << (bVar17 & 0x3f));
                            if (uVar8 + 7 <= uVar20) break;
                            uVar28 = uVar23;
                            if (uVar23 == 0) goto LAB_00109b88;
                          }
                        }
                        uVar30 = uVar30 >> (bVar18 & 0x3f);
                        uVar20 = uVar20 + (-7 - uVar8);
                        uVar27 = uVar30 >> 7;
                        uVar26 = 0;
                        iVar21 = ((uint)uVar30 & 0x7f) + 0xb;
                      }
LAB_001096d1:
                      uVar30 = uVar27;
                      if ((uint)(iVar7 + iVar21) <= uVar19) {
                        uVar8 = *(uint *)(lVar4 + 0x8c);
                        uVar28 = iVar21 + uVar8;
                        do {
                          uVar30 = (ulong)uVar8;
                          uVar8 = uVar8 + 1;
                          *(undefined2 *)(lVar4 + 0x98 + uVar30 * 2) = uVar26;
                        } while (uVar28 != uVar8);
                        *(uint *)(lVar4 + 0x8c) = uVar28;
                        goto LAB_00109f5c;
                      }
                    }
                    param_1[6] = (long)"invalid bit length repeat";
                    *(undefined4 *)(lVar4 + 8) = 0x3f51;
                    goto LAB_0010919a;
                  }
                  uVar20 = uVar20 - uVar8;
                  uVar28 = iVar7 + 1;
                  uVar27 = uVar30 >> (bVar18 & 0x3f);
                  *(uint *)(lVar4 + 0x8c) = uVar28;
                  *(ushort *)(lVar4 + 0x98 + uVar11 * 2) = uVar25;
LAB_00109f5c:
                  uVar11 = (ulong)uVar28;
                  uVar30 = uVar27;
                } while (uVar28 < uVar19);
              }
              if (*(int *)(lVar4 + 8) == 0x3f51) goto switchD_00108dad_caseD_3f51;
              if (*(short *)(lVar4 + 0x298) == 0) {
                param_1[6] = (long)"invalid code -- missing end-of-block";
                *(undefined4 *)(lVar4 + 8) = 0x3f51;
              }
              else {
                *(undefined4 *)(lVar4 + 0x78) = 9;
                *(long *)(lVar4 + 0x90) = lVar4 + 0x558;
                *(long *)(lVar4 + 0x68) = lVar4 + 0x558;
                iVar6 = FUN_0010b130(1,lVar4 + 0x98,iVar6,lVar4 + 0x90,lVar4 + 0x78);
                if (iVar6 == 0) {
                  *(undefined4 *)(lVar4 + 0x7c) = 6;
                  *(undefined8 *)(lVar4 + 0x70) = *(undefined8 *)(lVar4 + 0x90);
                  iVar6 = FUN_0010b130(2,lVar4 + 0x98 + (ulong)*(uint *)(lVar4 + 0x84) * 2,
                                       *(undefined4 *)(lVar4 + 0x88),lVar4 + 0x90,lVar4 + 0x7c,
                                       lVar4 + 0x318);
                  if (iVar6 == 0) {
                    *(undefined4 *)(lVar4 + 8) = 0x3f47;
                    if (param_2 != 6) goto switchD_00108dad_caseD_3f47;
                    goto LAB_0010a6fe;
                  }
                  param_1[6] = (long)"invalid distances set";
                  *(undefined4 *)(lVar4 + 8) = 0x3f51;
                }
                else {
                  param_1[6] = (long)"invalid literal/lengths set";
                  *(undefined4 *)(lVar4 + 8) = 0x3f51;
                }
              }
            }
            else {
              param_1[6] = (long)"invalid code lengths set";
              *(undefined4 *)(lVar4 + 8) = 0x3f51;
            }
          }
          else {
            param_1[6] = (long)"too many length or distance symbols";
            *(undefined4 *)(lVar4 + 8) = 0x3f51;
          }
          goto LAB_0010919a;
        }
        if (uVar19 == 3) {
          uVar20 = uVar20 - 3;
          param_1[6] = (long)"invalid block type";
          uVar30 = uVar30 >> 3;
          *(undefined4 *)(lVar4 + 8) = 0x3f51;
          goto LAB_0010919a;
        }
        if (uVar19 == 1) {
          FUN_00108820(lVar4);
          *(undefined4 *)(lVar4 + 8) = 0x3f47;
          pbVar31 = extraout_RDX;
          if (param_2 != 6) {
            uVar30 = uVar30 >> 3;
            uVar20 = uVar20 - 3;
switchD_00108dad_caseD_3f47:
            do {
              *(undefined4 *)(lVar4 + 8) = 0x3f48;
switchD_00108dad_caseD_3f48:
              if ((5 < uVar23) && (0x101 < local_80)) {
                param_1[3] = (long)__dest;
                *(uint *)(param_1 + 4) = local_80;
                *param_1 = (long)pbVar31;
                *(uint *)(param_1 + 1) = uVar23;
                *(ulong *)(lVar4 + 0x50) = uVar30;
                *(uint *)(lVar4 + 0x58) = uVar20;
                FUN_0010dde0();
                local_80 = *(uint *)(param_1 + 4);
                __dest = (undefined1 *)param_1[3];
                pbVar31 = (byte *)*param_1;
                uVar23 = *(uint *)(param_1 + 1);
                uVar30 = *(ulong *)(lVar4 + 0x50);
                uVar20 = *(uint *)(lVar4 + 0x58);
                iVar6 = *(int *)(lVar4 + 8);
                if (iVar6 != 0x3f3f) goto LAB_00108d91;
                *(undefined4 *)(lVar4 + 0x1bec) = 0xffffffff;
                goto switchD_00108dad_caseD_3f3f;
              }
              lVar13 = *(long *)(lVar4 + 0x68);
              *(undefined4 *)(lVar4 + 0x1bec) = 0;
              uVar8 = ~(-1 << ((byte)*(undefined4 *)(lVar4 + 0x78) & 0x1f));
              pbVar24 = (byte *)(lVar13 + (ulong)(uVar8 & (uint)uVar30) * 4);
              bVar18 = pbVar24[1];
              bVar16 = *pbVar24;
              uVar25 = *(ushort *)(pbVar24 + 2);
              uVar22 = (uint)bVar18;
              uVar19 = uVar20;
              if (uVar20 < uVar22) {
                uVar28 = uVar23;
                if (uVar23 == 0) goto LAB_00109b70;
                while( true ) {
                  bVar18 = *pbVar31;
                  pbVar31 = pbVar31 + 1;
                  uVar23 = uVar23 - 1;
                  uVar19 = uVar20 + 8;
                  uVar30 = uVar30 + ((ulong)bVar18 << ((byte)uVar20 & 0x3f));
                  pbVar24 = (byte *)(lVar13 + (ulong)(uVar8 & (uint)uVar30) * 4);
                  bVar18 = pbVar24[1];
                  bVar16 = *pbVar24;
                  uVar25 = *(ushort *)(pbVar24 + 2);
                  uVar22 = (uint)bVar18;
                  if (uVar22 <= uVar19) break;
                  uVar28 = uVar23;
                  uVar20 = uVar19;
                  if (uVar23 == 0) goto LAB_00109b88;
                }
              }
              uVar8 = (uint)uVar25;
              if (bVar16 == 0) {
                *(uint *)(lVar4 + 0x1bec) = uVar22;
                uVar30 = uVar30 >> (bVar18 & 0x3f);
                uVar20 = uVar19 - uVar22;
                *(uint *)(lVar4 + 0x5c) = uVar8;
LAB_00109b3a:
                *(undefined4 *)(lVar4 + 8) = 0x3f4d;
switchD_00108dad_caseD_3f4d:
                if (local_80 == 0) goto LAB_001091b0;
                local_80 = local_80 - 1;
                *__dest = (char)*(undefined4 *)(lVar4 + 0x5c);
                *(undefined4 *)(lVar4 + 8) = 0x3f48;
                __dest = __dest + 1;
                goto switchD_00108dad_caseD_3f48;
              }
              bVar18 = (byte)uVar22;
              if ((bVar16 & 0xf0) == 0) {
                uVar29 = ~(-1 << (bVar16 + bVar18 & 0x1f));
                pbVar24 = (byte *)(lVar13 + (ulong)(((uVar29 & (uint)uVar30) >> (bVar18 & 0x1f)) +
                                                   uVar8) * 4);
                uVar9 = (uint)pbVar24[1];
                bVar16 = *pbVar24;
                uVar25 = *(ushort *)(pbVar24 + 2);
                uVar28 = uVar9 + uVar22;
                uVar20 = uVar19;
                if (uVar19 < uVar28) {
                  do {
                    uVar28 = 0;
                    if (uVar23 == 0) goto LAB_00109b70;
                    bVar16 = *pbVar31;
                    uVar19 = uVar20 + 8;
                    pbVar31 = pbVar31 + 1;
                    uVar23 = uVar23 - 1;
                    uVar30 = uVar30 + ((ulong)bVar16 << ((byte)uVar20 & 0x3f));
                    pbVar24 = (byte *)(lVar13 + (ulong)(((uVar29 & (uint)uVar30) >> (bVar18 & 0x1f))
                                                       + uVar8) * 4);
                    bVar16 = *pbVar24;
                    uVar25 = *(ushort *)(pbVar24 + 2);
                    uVar9 = (uint)pbVar24[1];
                    uVar28 = uVar9 + uVar22;
                    uVar20 = uVar19;
                  } while (uVar19 < uVar28);
                }
                *(uint *)(lVar4 + 0x1bec) = uVar28;
                *(uint *)(lVar4 + 0x5c) = (uint)uVar25;
                uVar20 = (uVar19 - uVar22) - uVar9;
                uVar30 = (uVar30 >> (bVar18 & 0x3f)) >> ((byte)uVar9 & 0x3f);
                if (bVar16 != 0) goto LAB_00109d33;
                goto LAB_00109b3a;
              }
              *(uint *)(lVar4 + 0x1bec) = uVar22;
              uVar20 = uVar19 - uVar22;
              *(uint *)(lVar4 + 0x5c) = uVar8;
              uVar30 = uVar30 >> (bVar18 & 0x3f);
LAB_00109d33:
              if ((bVar16 & 0x20) != 0) goto code_r0x00109d3c;
              if ((bVar16 & 0x40) != 0) {
                param_1[6] = (long)"invalid literal/length code";
                *(undefined4 *)(lVar4 + 8) = 0x3f51;
                goto LAB_0010919a;
              }
              uVar19 = bVar16 & 0xf;
              *(undefined4 *)(lVar4 + 8) = 0x3f49;
              *(uint *)(lVar4 + 100) = uVar19;
LAB_001092cc:
              if (uVar19 == 0) {
                iVar6 = *(int *)(lVar4 + 0x5c);
              }
              else {
                if (uVar20 < uVar19) {
                  uVar28 = uVar23;
                  if (uVar23 == 0) goto LAB_00109b70;
                  while( true ) {
                    bVar18 = *pbVar31;
                    pbVar31 = pbVar31 + 1;
                    uVar23 = uVar23 - 1;
                    bVar16 = (byte)uVar20;
                    uVar20 = uVar20 + 8;
                    uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
                    if (uVar19 <= uVar20) break;
                    uVar28 = uVar23;
                    if (uVar23 == 0) goto LAB_00109b88;
                  }
                }
                *(int *)(lVar4 + 0x1bec) = *(int *)(lVar4 + 0x1bec) + uVar19;
                uVar20 = uVar20 - uVar19;
                iVar6 = (~(-1 << ((byte)uVar19 & 0x1f)) & (uint)uVar30) + *(int *)(lVar4 + 0x5c);
                uVar30 = uVar30 >> ((byte)uVar19 & 0x3f);
                *(int *)(lVar4 + 0x5c) = iVar6;
              }
              *(int *)(lVar4 + 0x1bf0) = iVar6;
              *(undefined4 *)(lVar4 + 8) = 0x3f4a;
switchD_00108dad_caseD_3f4a:
              lVar13 = *(long *)(lVar4 + 0x70);
              uVar22 = ~(-1 << ((byte)*(undefined4 *)(lVar4 + 0x7c) & 0x1f));
              pbVar24 = (byte *)(lVar13 + (ulong)(uVar22 & (uint)uVar30) * 4);
              bVar18 = pbVar24[1];
              bVar16 = *pbVar24;
              uVar25 = *(ushort *)(pbVar24 + 2);
              uVar19 = uVar20;
              if (uVar20 < bVar18) {
                uVar28 = uVar23;
                if (uVar23 == 0) goto LAB_00109b70;
                while( true ) {
                  bVar18 = *pbVar31;
                  pbVar31 = pbVar31 + 1;
                  uVar23 = uVar23 - 1;
                  uVar19 = uVar20 + 8;
                  uVar30 = uVar30 + ((ulong)bVar18 << ((byte)uVar20 & 0x3f));
                  pbVar24 = (byte *)(lVar13 + (ulong)(uVar22 & (uint)uVar30) * 4);
                  bVar18 = pbVar24[1];
                  bVar16 = *pbVar24;
                  uVar25 = *(ushort *)(pbVar24 + 2);
                  if (bVar18 <= uVar19) break;
                  uVar28 = uVar23;
                  uVar20 = uVar19;
                  if (uVar23 == 0) goto LAB_00109b88;
                }
              }
              uVar22 = (uint)bVar18;
              uVar8 = (uint)uVar25;
              if ((bVar16 & 0xf0) == 0) {
                uVar9 = ~(-1 << (bVar16 + bVar18 & 0x1f));
                pbVar24 = (byte *)(lVar13 + (ulong)(((uVar9 & (uint)uVar30) >> (bVar18 & 0x1f)) +
                                                   uVar8) * 4);
                bVar16 = *pbVar24;
                uVar25 = *(ushort *)(pbVar24 + 2);
                bVar17 = pbVar24[1];
                uVar20 = uVar19;
                if (uVar19 < bVar17 + uVar22) {
                  do {
                    uVar28 = 0;
                    if (uVar23 == 0) goto LAB_00109b70;
                    bVar16 = *pbVar31;
                    uVar19 = uVar20 + 8;
                    pbVar31 = pbVar31 + 1;
                    uVar23 = uVar23 - 1;
                    uVar30 = uVar30 + ((ulong)bVar16 << ((byte)uVar20 & 0x3f));
                    pbVar24 = (byte *)(lVar13 + (ulong)(((uVar9 & (uint)uVar30) >> (bVar18 & 0x1f))
                                                       + uVar8) * 4);
                    bVar16 = *pbVar24;
                    uVar25 = *(ushort *)(pbVar24 + 2);
                    bVar17 = pbVar24[1];
                    uVar20 = uVar19;
                  } while (uVar19 < bVar17 + uVar22);
                }
                uVar8 = (uint)uVar25;
                uVar28 = (uint)bVar17;
                uVar19 = uVar19 - bVar18;
                iVar6 = uVar22 + *(int *)(lVar4 + 0x1bec);
                uVar30 = uVar30 >> (bVar18 & 0x3f);
              }
              else {
                iVar6 = *(int *)(lVar4 + 0x1bec);
                uVar28 = uVar22;
              }
              uVar20 = uVar19 - uVar28;
              *(uint *)(lVar4 + 0x1bec) = uVar28 + iVar6;
              uVar30 = uVar30 >> ((byte)uVar28 & 0x3f);
              if ((bVar16 & 0x40) != 0) {
                param_1[6] = (long)"invalid distance code";
                *(undefined4 *)(lVar4 + 8) = 0x3f51;
                goto LAB_0010919a;
              }
              uVar19 = bVar16 & 0xf;
              *(uint *)(lVar4 + 0x60) = uVar8;
              *(uint *)(lVar4 + 100) = uVar19;
              *(undefined4 *)(lVar4 + 8) = 0x3f4b;
LAB_00109134:
              if (uVar19 != 0) {
                if (uVar20 < uVar19) {
                  uVar28 = uVar23;
                  if (uVar23 == 0) goto LAB_00109b70;
                  while( true ) {
                    bVar18 = *pbVar31;
                    pbVar31 = pbVar31 + 1;
                    uVar23 = uVar23 - 1;
                    bVar16 = (byte)uVar20;
                    uVar20 = uVar20 + 8;
                    uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
                    if (uVar19 <= uVar20) break;
                    uVar28 = uVar23;
                    if (uVar23 == 0) goto LAB_00109b88;
                  }
                }
                *(int *)(lVar4 + 0x1bec) = *(int *)(lVar4 + 0x1bec) + uVar19;
                uVar20 = uVar20 - uVar19;
                uVar28 = (uint)uVar30;
                uVar30 = uVar30 >> ((byte)uVar19 & 0x3f);
                *(int *)(lVar4 + 0x60) =
                     *(int *)(lVar4 + 0x60) + (~(-1 << ((byte)uVar19 & 0x1f)) & uVar28);
              }
              *(undefined4 *)(lVar4 + 8) = 0x3f4c;
switchD_00108dad_caseD_3f4c:
              if (local_80 == 0) goto LAB_001091b0;
              uVar19 = *(uint *)(lVar4 + 0x60);
              if (uVar3 - local_80 < uVar19) {
                uVar28 = (uVar19 + local_80) - uVar3;
                if ((*(uint *)(lVar4 + 0x40) < uVar28) && (*(int *)(lVar4 + 0x1be8) != 0)) {
                  param_1[6] = (long)"invalid distance too far back";
                  *(undefined4 *)(lVar4 + 8) = 0x3f51;
                  goto LAB_0010919a;
                }
                uVar22 = *(uint *)(lVar4 + 0x44);
                if (uVar22 < uVar28) {
                  uVar28 = uVar28 - uVar22;
                  uVar22 = uVar22 + *(int *)(lVar4 + 0x3c);
                }
                lVar13 = *(long *)(lVar4 + 0x48) + (ulong)(uVar22 + (uVar3 - (uVar19 + local_80)));
                uVar19 = *(uint *)(lVar4 + 0x5c);
                if (uVar19 <= uVar28) {
                  uVar28 = uVar19;
                }
              }
              else {
                lVar13 = (long)__dest - (ulong)uVar19;
                uVar19 = *(uint *)(lVar4 + 0x5c);
                uVar28 = uVar19;
              }
              if (local_80 < uVar28) {
                uVar28 = local_80;
              }
              local_80 = local_80 - uVar28;
              *(uint *)(lVar4 + 0x5c) = uVar19 - uVar28;
              uVar11 = 0;
              do {
                __dest[uVar11] = *(undefined1 *)(lVar13 + uVar11);
                bVar33 = uVar28 - 1 != uVar11;
                uVar11 = uVar11 + 1;
              } while (bVar33);
              __dest = __dest + (ulong)(uVar28 - 1) + 1;
              if (*(int *)(lVar4 + 0x5c) != 0) {
                iVar6 = *(int *)(lVar4 + 8);
                goto LAB_00108d91;
              }
            } while( true );
          }
          uVar20 = uVar20 - 3;
          local_70 = 0;
          uVar30 = uVar30 >> 3;
          uVar32 = uVar3 - local_80;
          goto LAB_001091b0;
        }
        *(undefined4 *)(lVar4 + 8) = 0x3f41;
        uVar30 = uVar30 >> 3;
        uVar20 = uVar20 - 3;
switchD_00108dad_caseD_3f41:
        uVar19 = uVar20 & 0xfffffff8;
        uVar30 = uVar30 >> ((byte)uVar20 & 7);
        uVar20 = uVar19;
        if (uVar19 < 0x20) {
          uVar28 = uVar23;
          if (uVar23 == 0) goto LAB_00109b70;
          while( true ) {
            bVar18 = *pbVar31;
            pbVar31 = pbVar31 + 1;
            uVar23 = uVar23 - 1;
            uVar20 = uVar19 + 8;
            uVar30 = uVar30 + ((ulong)bVar18 << ((byte)uVar19 & 0x3f));
            if (0x1f < uVar20) break;
            uVar28 = uVar23;
            uVar19 = uVar20;
            if (uVar23 == 0) goto LAB_00109b88;
          }
        }
        if ((uVar30 & 0xffff) != (uVar30 >> 0x10 ^ 0xffff)) {
          param_1[6] = (long)"invalid stored block lengths";
          *(undefined4 *)(lVar4 + 8) = 0x3f51;
          goto LAB_0010919a;
        }
        uVar19 = (uint)(ushort)uVar30;
        *(undefined4 *)(lVar4 + 8) = 0x3f42;
        *(uint *)(lVar4 + 0x5c) = uVar19;
        if (param_2 == 6) {
          uVar20 = 0;
          uVar30 = 0;
          uVar32 = uVar3 - local_80;
          goto LAB_001091b0;
        }
        uVar20 = 0;
        uVar30 = 0;
LAB_001094b4:
        *(undefined4 *)(lVar4 + 8) = 0x3f43;
LAB_001094bc:
        if (uVar19 == 0) goto LAB_00109d50;
        if (uVar23 <= uVar19) {
          uVar19 = uVar23;
        }
        if (local_80 < uVar19) {
          uVar19 = local_80;
        }
        if (uVar19 == 0) {
          uVar32 = uVar3 - local_80;
          goto LAB_001091b0;
        }
        uVar11 = (ulong)uVar19;
        pvVar12 = memcpy(__dest,pbVar31,uVar11);
        local_80 = local_80 - uVar19;
        iVar6 = *(int *)(lVar4 + 8);
        *(int *)(lVar4 + 0x5c) = *(int *)(lVar4 + 0x5c) - uVar19;
        uVar23 = uVar23 - uVar19;
        pbVar31 = pbVar31 + uVar11;
        __dest = (undefined1 *)((long)pvVar12 + uVar11);
        goto LAB_00108d91;
      case 0x3f35:
        goto switchD_00108dad_caseD_3f35;
      case 0x3f36:
        if (uVar20 < 0x20) goto LAB_001097bd;
        goto LAB_001097f2;
      case 0x3f37:
        if (uVar20 < 0x10) goto LAB_00109825;
        goto LAB_0010985a;
      case 0x3f38:
        uVar19 = *(uint *)(lVar4 + 0x18);
        if ((uVar19 & 0x400) == 0) goto LAB_001098dd;
        if (0xf < uVar20) goto LAB_0010a0aa;
        goto LAB_0010a077;
      case 0x3f39:
        uVar19 = *(uint *)(lVar4 + 0x18);
        goto LAB_001098f6;
      case 0x3f3a:
        uVar19 = *(uint *)(lVar4 + 0x18);
        goto LAB_001099be;
      case 0x3f3b:
        uVar19 = *(uint *)(lVar4 + 0x18);
        goto LAB_0010941c;
      case 0x3f3c:
        uVar19 = *(uint *)(lVar4 + 0x18);
        goto joined_r0x001093c7;
      case 0x3f3d:
        if (uVar20 < 0x20) goto LAB_00108db5;
        goto LAB_00108dea;
      case 0x3f3e:
        goto switchD_00108dad_caseD_3f3e;
      case 0x3f3f:
        goto switchD_00108dad_caseD_3f3f;
      case 0x3f41:
        goto switchD_00108dad_caseD_3f41;
      case 0x3f42:
        uVar19 = *(uint *)(lVar4 + 0x5c);
        goto LAB_001094b4;
      case 0x3f43:
        uVar19 = *(uint *)(lVar4 + 0x5c);
        goto LAB_001094bc;
      case 0x3f44:
        goto switchD_00108dad_caseD_3f44;
      case 0x3f45:
        uVar11 = (ulong)*(uint *)(lVar4 + 0x8c);
        uVar19 = *(uint *)(lVar4 + 0x80);
        if (uVar19 <= *(uint *)(lVar4 + 0x8c)) goto LAB_0010a362;
        goto joined_r0x0010955b;
      case 0x3f46:
        uVar11 = (ulong)*(uint *)(lVar4 + 0x8c);
        goto LAB_001095c7;
      case 0x3f47:
        goto switchD_00108dad_caseD_3f47;
      case 0x3f48:
        goto switchD_00108dad_caseD_3f48;
      case 0x3f49:
        uVar19 = *(uint *)(lVar4 + 100);
        goto LAB_001092cc;
      case 0x3f4a:
        goto switchD_00108dad_caseD_3f4a;
      case 0x3f4b:
        uVar19 = *(uint *)(lVar4 + 100);
        goto LAB_00109134;
      case 0x3f4c:
        goto switchD_00108dad_caseD_3f4c;
      case 0x3f4d:
        goto switchD_00108dad_caseD_3f4d;
      case 0x3f4e:
LAB_00108e9a:
        uVar32 = *(uint *)(lVar4 + 0x10);
        if (uVar32 != 0) goto joined_r0x00108ea9;
        goto LAB_00109f30;
      case 0x3f4f:
        uVar32 = *(uint *)(lVar4 + 0x10);
        goto LAB_00109717;
      case 0x3f50:
        local_70 = 1;
        uVar32 = uVar3 - local_80;
        goto LAB_001091b0;
      case 0x3f51:
switchD_00108dad_caseD_3f51:
        goto LAB_0010919a;
      case 0x3f52:
        local_70 = -4;
        goto LAB_0010929e;
      default:
        break;
      }
    }
  }
  local_70 = -2;
  goto LAB_0010929e;
switchD_00108dad_caseD_3f35:
  if (uVar20 < 0x10) goto LAB_00109a05;
LAB_00109a3c:
  *(int *)(lVar4 + 0x18) = (int)uVar30;
  if ((char)uVar30 == '\b') {
    if ((uVar30 & 0xe000) == 0) {
      if (*(uint **)(lVar4 + 0x30) != (uint *)0x0) {
        **(uint **)(lVar4 + 0x30) = (uint)(uVar30 >> 8) & 1;
      }
      if (((uVar30 & 0x200) != 0) && ((*(byte *)(lVar4 + 0x10) & 4) != 0)) {
        local_44 = CONCAT22(local_44._2_2_,(short)uVar30);
        uVar14 = FUN_0010dd50(*(undefined8 *)(lVar4 + 0x20),&local_44,2);
        *(undefined8 *)(lVar4 + 0x20) = uVar14;
      }
      *(undefined4 *)(lVar4 + 8) = 0x3f36;
      uVar20 = 0;
      uVar30 = 0;
LAB_001097bd:
      uVar28 = 0;
      if (uVar23 == 0) goto LAB_00109b70;
      do {
        bVar18 = *pbVar31;
        pbVar31 = pbVar31 + 1;
        uVar23 = uVar23 - 1;
        bVar16 = (byte)uVar20;
        uVar20 = uVar20 + 8;
        uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
        if (0x1f < uVar20) goto LAB_001097f2;
        uVar28 = 0;
      } while (uVar23 != 0);
      goto LAB_00109b88;
    }
    param_1[6] = (long)"unknown header flags set";
    *(undefined4 *)(lVar4 + 8) = 0x3f51;
  }
  else {
LAB_00109a4d:
    param_1[6] = (long)"unknown compression method";
    *(undefined4 *)(lVar4 + 8) = 0x3f51;
  }
  goto LAB_0010919a;
LAB_0010a1a4:
  if (((uVar19 & 2) != 0) && (uVar30 == 0x8b1f)) {
    if (*(int *)(lVar4 + 0x38) == 0) {
      *(undefined4 *)(lVar4 + 0x38) = 0xf;
    }
    uVar14 = FUN_0010dd50(0,0,0);
    uVar20 = 0;
    uVar30 = 0;
    *(undefined8 *)(lVar4 + 0x20) = uVar14;
    local_44 = CONCAT22(local_44._2_2_,0x8b1f);
    uVar14 = FUN_0010dd50(uVar14,&local_44,2);
    *(undefined4 *)(lVar4 + 8) = 0x3f35;
    *(undefined8 *)(lVar4 + 0x20) = uVar14;
LAB_00109a05:
    uVar28 = 0;
    if (uVar23 == 0) goto LAB_00109b70;
    do {
      bVar18 = *pbVar31;
      pbVar31 = pbVar31 + 1;
      uVar23 = uVar23 - 1;
      bVar16 = (byte)uVar20;
      uVar20 = uVar20 + 8;
      uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
      if (0xf < uVar20) goto LAB_00109a3c;
      uVar28 = uVar23;
    } while (uVar23 != 0);
    goto LAB_00109b88;
  }
  if (*(long *)(lVar4 + 0x30) != 0) {
    *(undefined4 *)(*(long *)(lVar4 + 0x30) + 0x48) = 0xffffffff;
  }
  if (((uVar19 & 1) == 0) ||
     (uVar11 = (ulong)(((uint)uVar30 & 0xff) << 8) + (uVar30 >> 8), uVar11 != (uVar11 / 0x1f) * 0x1f
     )) {
    param_1[6] = (long)"incorrect header check";
    *(undefined4 *)(lVar4 + 8) = 0x3f51;
    goto LAB_0010919a;
  }
  if (((uint)uVar30 & 0xf) != 8) goto LAB_00109a4d;
  uVar30 = uVar30 >> 4;
  uVar20 = uVar20 - 4;
  uVar19 = ((uint)uVar30 & 0xf) + 8;
  if (*(uint *)(lVar4 + 0x38) == 0) {
    *(uint *)(lVar4 + 0x38) = uVar19;
    if (uVar19 < 0x10) {
LAB_0010a8af:
      *(undefined4 *)(lVar4 + 0x18) = 0;
      *(int *)(lVar4 + 0x1c) = 1 << (sbyte)uVar19;
      lVar13 = FUN_0010d8e0(0,0,0);
      uVar11 = uVar30 & 0x200;
      uVar30 = (ulong)((uint)uVar30 & 0x200);
      *(long *)(lVar4 + 0x20) = lVar13;
      param_1[0xc] = lVar13;
      if (uVar11 == 0) {
        *(undefined4 *)(lVar4 + 8) = 0x3f3f;
        uVar20 = 0;
        goto switchD_00108dad_caseD_3f3f;
      }
      *(undefined4 *)(lVar4 + 8) = 0x3f3d;
      uVar30 = 0;
      uVar20 = 0;
LAB_00108db5:
      uVar28 = 0;
      if (uVar23 == 0) goto LAB_00109b70;
      do {
        bVar18 = *pbVar31;
        pbVar31 = pbVar31 + 1;
        uVar23 = uVar23 - 1;
        bVar16 = (byte)uVar20;
        uVar20 = uVar20 + 8;
        uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
        if (0x1f < uVar20) goto LAB_00108dea;
        uVar28 = uVar23;
      } while (uVar23 != 0);
      goto LAB_00109b88;
    }
  }
  else if ((uVar19 < 0x10) && (uVar19 <= *(uint *)(lVar4 + 0x38))) goto LAB_0010a8af;
  param_1[6] = (long)"invalid window size";
  *(undefined4 *)(lVar4 + 8) = 0x3f51;
LAB_0010919a:
  local_70 = -3;
  uVar32 = uVar3 - local_80;
  goto LAB_001091b0;
LAB_001097f2:
  if (*(long *)(lVar4 + 0x30) != 0) {
    *(ulong *)(*(long *)(lVar4 + 0x30) + 8) = uVar30;
  }
  if (((*(byte *)(lVar4 + 0x19) & 2) != 0) && ((*(byte *)(lVar4 + 0x10) & 4) != 0)) {
    local_44 = (undefined4)uVar30;
    uVar14 = FUN_0010dd50(*(undefined8 *)(lVar4 + 0x20),&local_44,4);
    *(undefined8 *)(lVar4 + 0x20) = uVar14;
  }
  *(undefined4 *)(lVar4 + 8) = 0x3f37;
  uVar30 = 0;
  uVar20 = 0;
LAB_00109825:
  uVar28 = 0;
  if (uVar23 == 0) goto LAB_00109b70;
  do {
    bVar18 = *pbVar31;
    pbVar31 = pbVar31 + 1;
    uVar23 = uVar23 - 1;
    bVar16 = (byte)uVar20;
    uVar20 = uVar20 + 8;
    uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
    if (0xf < uVar20) goto LAB_0010985a;
    uVar28 = uVar23;
  } while (uVar23 != 0);
  goto LAB_00109b88;
LAB_0010985a:
  lVar13 = *(long *)(lVar4 + 0x30);
  if (lVar13 != 0) {
    *(uint *)(lVar13 + 0x10) = (uint)uVar30 & 0xff;
    *(int *)(lVar13 + 0x14) = (int)(uVar30 >> 8);
  }
  uVar19 = *(uint *)(lVar4 + 0x18);
  if (((uVar19 & 0x200) != 0) && ((*(byte *)(lVar4 + 0x10) & 4) != 0)) {
    local_44 = CONCAT22(local_44._2_2_,(short)uVar30);
    uVar14 = FUN_0010dd50(*(undefined8 *)(lVar4 + 0x20),&local_44,2);
    uVar19 = *(uint *)(lVar4 + 0x18);
    *(undefined8 *)(lVar4 + 0x20) = uVar14;
  }
  *(undefined4 *)(lVar4 + 8) = 0x3f38;
  if ((uVar19 & 0x400) == 0) {
    uVar20 = 0;
    uVar30 = 0;
LAB_001098dd:
    if (*(long *)(lVar4 + 0x30) != 0) {
      *(undefined8 *)(*(long *)(lVar4 + 0x30) + 0x18) = 0;
    }
    goto LAB_001098ee;
  }
  uVar30 = 0;
  uVar20 = 0;
LAB_0010a077:
  uVar28 = 0;
  if (uVar23 == 0) goto LAB_00109b70;
  do {
    bVar18 = *pbVar31;
    pbVar31 = pbVar31 + 1;
    uVar23 = uVar23 - 1;
    bVar16 = (byte)uVar20;
    uVar20 = uVar20 + 8;
    uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
    if (0xf < uVar20) goto LAB_0010a0aa;
    uVar28 = uVar23;
  } while (uVar23 != 0);
  goto LAB_00109b88;
LAB_0010a0aa:
  *(int *)(lVar4 + 0x5c) = (int)uVar30;
  if (*(long *)(lVar4 + 0x30) != 0) {
    *(int *)(*(long *)(lVar4 + 0x30) + 0x20) = (int)uVar30;
  }
  if (((uVar19 & 0x200) == 0) || ((*(byte *)(lVar4 + 0x10) & 4) == 0)) {
    uVar20 = 0;
    uVar30 = 0;
  }
  else {
    uVar20 = 0;
    local_44 = CONCAT22(local_44._2_2_,(short)uVar30);
    uVar30 = 0;
    uVar14 = FUN_0010dd50(*(undefined8 *)(lVar4 + 0x20),&local_44,2);
    uVar19 = *(uint *)(lVar4 + 0x18);
    *(undefined8 *)(lVar4 + 0x20) = uVar14;
  }
LAB_001098ee:
  *(undefined4 *)(lVar4 + 8) = 0x3f39;
LAB_001098f6:
  if ((uVar19 & 0x400) != 0) {
    uVar22 = *(uint *)(lVar4 + 0x5c);
    uVar28 = uVar22;
    if (uVar23 <= uVar22) {
      uVar28 = uVar23;
    }
    if (uVar28 != 0) {
      lVar13 = *(long *)(lVar4 + 0x30);
      if ((lVar13 != 0) && (*(long *)(lVar13 + 0x18) != 0)) {
        uVar8 = *(uint *)(lVar13 + 0x24);
        uVar9 = *(int *)(lVar13 + 0x20) - uVar22;
        if (uVar9 < uVar8) {
          uVar11 = (ulong)uVar28;
          if (uVar8 < uVar28 + uVar9) {
            uVar11 = (ulong)((uVar8 + uVar22) - *(int *)(lVar13 + 0x20));
          }
          memcpy((void *)((ulong)uVar9 + *(long *)(lVar13 + 0x18)),pbVar31,uVar11);
          uVar19 = *(uint *)(lVar4 + 0x18);
        }
      }
      if (((uVar19 & 0x200) != 0) && ((*(byte *)(lVar4 + 0x10) & 4) != 0)) {
        uVar14 = FUN_0010dd50(*(undefined8 *)(lVar4 + 0x20),pbVar31,uVar28);
        *(undefined8 *)(lVar4 + 0x20) = uVar14;
      }
      uVar23 = uVar23 - uVar28;
      pbVar31 = pbVar31 + uVar28;
      uVar22 = *(int *)(lVar4 + 0x5c) - uVar28;
      *(uint *)(lVar4 + 0x5c) = uVar22;
    }
    uVar28 = uVar23;
    if (uVar22 != 0) goto LAB_00109b70;
    uVar19 = *(uint *)(lVar4 + 0x18);
  }
  *(undefined4 *)(lVar4 + 0x5c) = 0;
  *(undefined4 *)(lVar4 + 8) = 0x3f3a;
LAB_001099be:
  if ((uVar19 & 0x800) == 0) {
    if (*(long *)(lVar4 + 0x30) != 0) {
      *(undefined8 *)(*(long *)(lVar4 + 0x30) + 0x28) = 0;
    }
LAB_001099d8:
    *(undefined4 *)(lVar4 + 0x5c) = 0;
    *(undefined4 *)(lVar4 + 8) = 0x3f3b;
LAB_0010941c:
    if ((uVar19 & 0x1000) == 0) {
      if (*(long *)(lVar4 + 0x30) != 0) {
        *(undefined8 *)(*(long *)(lVar4 + 0x30) + 0x38) = 0;
      }
LAB_00109436:
      *(undefined4 *)(lVar4 + 8) = 0x3f3c;
joined_r0x001093c7:
      if ((uVar19 & 0x200) == 0) {
LAB_001093d0:
        lVar13 = *(long *)(lVar4 + 0x30);
        if (lVar13 != 0) {
          *(undefined4 *)(lVar13 + 0x48) = 1;
          *(uint *)(lVar13 + 0x44) = (int)uVar19 >> 9 & 1;
        }
        lVar13 = FUN_0010dd50(0,0,0);
        *(long *)(lVar4 + 0x20) = lVar13;
        param_1[0xc] = lVar13;
        *(undefined4 *)(lVar4 + 8) = 0x3f3f;
        goto switchD_00108dad_caseD_3f3f;
      }
      if (0xf < uVar20) {
LAB_0010947c:
        if (((*(byte *)(lVar4 + 0x10) & 4) == 0) || (*(ushort *)(lVar4 + 0x20) == uVar30)) {
          uVar20 = 0;
          uVar30 = 0;
          goto LAB_001093d0;
        }
        param_1[6] = (long)"header crc mismatch";
        *(undefined4 *)(lVar4 + 8) = 0x3f51;
        goto LAB_0010919a;
      }
      uVar28 = uVar23;
      if (uVar23 != 0) {
        do {
          bVar18 = *pbVar31;
          pbVar31 = pbVar31 + 1;
          uVar23 = uVar23 - 1;
          bVar16 = (byte)uVar20;
          uVar20 = uVar20 + 8;
          uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
          if (0xf < uVar20) goto LAB_0010947c;
          uVar28 = uVar23;
        } while (uVar23 != 0);
        goto LAB_00109b88;
      }
    }
    else {
      uVar28 = uVar23;
      if (uVar23 != 0) {
        uVar19 = 0;
        pbVar24 = pbVar31;
        do {
          lVar13 = *(long *)(lVar4 + 0x30);
          bVar18 = *pbVar24;
          uVar19 = uVar19 + 1;
          if ((lVar13 != 0) && (lVar1 = *(long *)(lVar13 + 0x38), lVar1 != 0)) {
            uVar28 = *(uint *)(lVar4 + 0x5c);
            if (uVar28 < *(uint *)(lVar13 + 0x40)) {
              *(uint *)(lVar4 + 0x5c) = uVar28 + 1;
              *(byte *)(lVar1 + (ulong)uVar28) = bVar18;
            }
          }
          pbVar24 = pbVar24 + 1;
        } while ((bVar18 != 0) && (uVar19 < uVar23));
        if (((*(byte *)(lVar4 + 0x19) & 2) != 0) && ((*(byte *)(lVar4 + 0x10) & 4) != 0)) {
          uVar14 = FUN_0010dd50(*(undefined8 *)(lVar4 + 0x20));
          *(undefined8 *)(lVar4 + 0x20) = uVar14;
        }
        uVar23 = uVar23 - uVar19;
        pbVar31 = pbVar31 + uVar19;
        uVar28 = uVar23;
        if (bVar18 == 0) {
          uVar19 = *(uint *)(lVar4 + 0x18);
          goto LAB_00109436;
        }
      }
    }
  }
  else {
    uVar28 = uVar23;
    if (uVar23 != 0) {
      uVar19 = 0;
      pbVar24 = pbVar31;
      do {
        lVar13 = *(long *)(lVar4 + 0x30);
        bVar18 = *pbVar24;
        uVar19 = uVar19 + 1;
        if ((lVar13 != 0) && (lVar1 = *(long *)(lVar13 + 0x28), lVar1 != 0)) {
          uVar28 = *(uint *)(lVar4 + 0x5c);
          if (uVar28 < *(uint *)(lVar13 + 0x30)) {
            *(uint *)(lVar4 + 0x5c) = uVar28 + 1;
            *(byte *)(lVar1 + (ulong)uVar28) = bVar18;
          }
        }
        pbVar24 = pbVar24 + 1;
      } while ((bVar18 != 0) && (uVar19 < uVar23));
      if (((*(byte *)(lVar4 + 0x19) & 2) != 0) && ((*(byte *)(lVar4 + 0x10) & 4) != 0)) {
        uVar14 = FUN_0010dd50(*(undefined8 *)(lVar4 + 0x20));
        *(undefined8 *)(lVar4 + 0x20) = uVar14;
      }
      uVar23 = uVar23 - uVar19;
      pbVar31 = pbVar31 + uVar19;
      uVar28 = uVar23;
      if (bVar18 == 0) {
        uVar19 = *(uint *)(lVar4 + 0x18);
        goto LAB_001099d8;
      }
    }
  }
LAB_00109b70:
  uVar23 = uVar28;
  uVar32 = uVar3 - local_80;
  goto LAB_001091b0;
LAB_00108dea:
  uVar20 = 0;
  uVar10 = uVar30 >> 0x18;
  uVar27 = uVar30 >> 8;
  lVar13 = uVar30 << 8;
  uVar11 = uVar30 & 0xff;
  uVar30 = 0;
  lVar13 = (uVar10 & 0xff | (ulong)((uint)uVar27 & 0xff00)) +
           (ulong)((uint)lVar13 & 0xff0000) + uVar11 * 0x1000000;
  *(long *)(lVar4 + 0x20) = lVar13;
  param_1[0xc] = lVar13;
  *(undefined4 *)(lVar4 + 8) = 0x3f3e;
switchD_00108dad_caseD_3f3e:
  if (*(int *)(lVar4 + 0x14) != 0) {
    lVar13 = FUN_0010d8e0(0,0,0);
    *(long *)(lVar4 + 0x20) = lVar13;
    param_1[0xc] = lVar13;
    *(undefined4 *)(lVar4 + 8) = 0x3f3f;
    goto switchD_00108dad_caseD_3f3f;
  }
  param_1[3] = (long)__dest;
  *param_1 = (long)pbVar31;
  *(uint *)(param_1 + 4) = local_80;
  *(uint *)(param_1 + 1) = uVar23;
  local_70 = 2;
  *(ulong *)(lVar4 + 0x50) = uVar30;
  *(uint *)(lVar4 + 0x58) = uVar20;
  goto LAB_0010929e;
joined_r0x00108ea9:
  if (0x1f < uVar20) goto LAB_00108ee4;
  if (uVar23 == 0) goto LAB_00109d62;
  bVar18 = *pbVar31;
  pbVar31 = pbVar31 + 1;
  uVar23 = uVar23 - 1;
  bVar16 = (byte)uVar20;
  uVar20 = uVar20 + 8;
  uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
  goto joined_r0x00108ea9;
LAB_00108ee4:
  uVar28 = uVar3 - local_80;
  uVar11 = (ulong)uVar28;
  param_1[5] = param_1[5] + uVar11;
  *(long *)(lVar4 + 0x28) = *(long *)(lVar4 + 0x28) + uVar11;
  uVar19 = uVar32 & 4;
  uVar3 = local_80;
  if (uVar19 != 0) {
    if (uVar28 != 0) {
      if (*(int *)(lVar4 + 0x18) == 0) {
        lVar13 = FUN_0010d8e0(*(undefined8 *)(lVar4 + 0x20),(long)__dest - uVar11,uVar28);
      }
      else {
        lVar13 = FUN_0010dd50();
      }
      uVar32 = *(uint *)(lVar4 + 0x10);
      *(long *)(lVar4 + 0x20) = lVar13;
      param_1[0xc] = lVar13;
      uVar19 = uVar32 & 4;
    }
    if (uVar19 != 0) {
      uVar11 = uVar30;
      if (*(int *)(lVar4 + 0x18) == 0) {
        uVar11 = (uVar30 >> 0x18 & 0xff | (ulong)((uint)(uVar30 >> 8) & 0xff00)) +
                 (ulong)((uint)(uVar30 << 8) & 0xff0000) + (uVar30 & 0xff) * 0x1000000;
      }
      if (*(ulong *)(lVar4 + 0x20) != uVar11) {
        param_1[6] = (long)"incorrect data check";
        *(undefined4 *)(lVar4 + 8) = 0x3f51;
        goto LAB_0010919a;
      }
    }
  }
  uVar20 = 0;
  uVar30 = 0;
LAB_00109f30:
  *(undefined4 *)(lVar4 + 8) = 0x3f4f;
LAB_00109717:
  if ((uVar32 != 0) && (*(int *)(lVar4 + 0x18) != 0)) {
    for (; uVar20 < 0x20; uVar20 = uVar20 + 8) {
      if (uVar23 == 0) goto LAB_00109d62;
      bVar18 = *pbVar31;
      pbVar31 = pbVar31 + 1;
      uVar23 = uVar23 - 1;
      uVar30 = uVar30 + ((ulong)bVar18 << ((byte)uVar20 & 0x3f));
    }
    if (((uVar32 & 4) != 0) && (*(uint *)(lVar4 + 0x28) != uVar30)) {
      param_1[6] = (long)"incorrect length check";
      *(undefined4 *)(lVar4 + 8) = 0x3f51;
      goto LAB_0010919a;
    }
    uVar20 = 0;
    uVar30 = 0;
  }
  *(undefined4 *)(lVar4 + 8) = 0x3f50;
  local_70 = 1;
  uVar32 = uVar3 - local_80;
  goto LAB_001091b0;
LAB_00109d62:
  uVar23 = 0;
  uVar32 = uVar3 - local_80;
  goto LAB_001091b0;
code_r0x00109d3c:
  *(undefined4 *)(lVar4 + 0x1bec) = 0xffffffff;
LAB_00109d50:
  *(undefined4 *)(lVar4 + 8) = 0x3f3f;
switchD_00108dad_caseD_3f3f:
  uVar28 = uVar23;
  if (param_2 - 5U < 2) goto LAB_00109b70;
  goto switchD_00108dad_caseD_3f40;
  while (uVar28 = uVar23, uVar23 != 0) {
LAB_0010a188:
    bVar18 = *pbVar31;
    pbVar31 = pbVar31 + 1;
    uVar23 = uVar23 - 1;
    bVar16 = (byte)uVar20;
    uVar20 = uVar20 + 8;
    uVar30 = uVar30 + ((ulong)bVar18 << (bVar16 & 0x3f));
    if (0xf < uVar20) goto LAB_0010a1a4;
  }
LAB_00109b88:
  uVar23 = uVar28;
  uVar32 = uVar3 - local_80;
LAB_001091b0:
  iVar6 = *(int *)(lVar4 + 0x3c);
  param_1[3] = (long)__dest;
  *param_1 = (long)pbVar31;
  *(uint *)(param_1 + 4) = local_80;
  *(uint *)(param_1 + 1) = uVar23;
  *(ulong *)(lVar4 + 0x50) = uVar30;
  *(uint *)(lVar4 + 0x58) = uVar20;
  if ((iVar6 != 0) ||
     (((uVar3 != local_80 && (*(uint *)(lVar4 + 8) < 0x3f51)) &&
      ((*(uint *)(lVar4 + 8) < 0x3f4e || (param_2 != 4)))))) {
    iVar6 = FUN_001088d0(param_1,__dest,uVar32);
    if (iVar6 != 0) {
      *(undefined4 *)(lVar4 + 8) = 0x3f52;
      local_70 = -4;
      goto LAB_0010929e;
    }
    uVar23 = *(uint *)(param_1 + 1);
    uVar32 = uVar3 - (int)param_1[4];
  }
  param_1[2] = param_1[2] + (ulong)(uVar2 - uVar23);
  uVar30 = (ulong)uVar32;
  param_1[5] = param_1[5] + uVar30;
  *(long *)(lVar4 + 0x28) = *(long *)(lVar4 + 0x28) + uVar30;
  if (((*(byte *)(lVar4 + 0x10) & 4) != 0) && (uVar32 != 0)) {
    if (*(int *)(lVar4 + 0x18) == 0) {
      lVar13 = FUN_0010d8e0(*(undefined8 *)(lVar4 + 0x20),param_1[3] - uVar30,uVar32);
    }
    else {
      lVar13 = FUN_0010dd50();
    }
    *(long *)(lVar4 + 0x20) = lVar13;
    param_1[0xc] = lVar13;
  }
  iVar6 = *(int *)(lVar4 + 8);
  iVar21 = (uint)(*(int *)(lVar4 + 0xc) != 0) * 0x40 + *(int *)(lVar4 + 0x58);
  iVar7 = iVar21 + 0x80;
  if (iVar6 != 0x3f3f) {
    iVar7 = (uint)(iVar6 == 0x3f47 || iVar6 == 0x3f42) * 0x100 + iVar21;
  }
  *(int *)(param_1 + 0xb) = iVar7;
  if (((uVar2 - uVar23 == 0 && uVar32 == 0) || (param_2 == 4)) && (local_70 == 0)) {
    local_70 = -5;
  }
LAB_0010929e:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_70;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: inflateEnd @ 0xaa00

undefined8 inflateEnd(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = param_1;
  iVar1 = FUN_001087d0();
  if (iVar1 == 0) {
    lVar2 = *(long *)(lVar3 + 0x38);
    uVar4 = 0;
    if (*(long *)(lVar2 + 0x48) != 0) {
      (**(code **)(param_1 + 0x48))(*(undefined8 *)(lVar3 + 0x50),*(long *)(lVar2 + 0x48));
      lVar2 = *(long *)(param_1 + 0x38);
    }
    (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x50),lVar2);
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  else {
    uVar4 = 0xfffffffe;
  }
  return uVar4;
}



// Function: inflateGetDictionary @ 0xaa60

undefined8 inflateGetDictionary(long param_1,void *param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = FUN_001087d0();
  if (iVar2 == 0) {
    lVar1 = *(long *)(param_1 + 0x38);
    uVar3 = 0;
    if ((*(int *)(lVar1 + 0x40) != 0) && (param_2 != (void *)0x0)) {
      memcpy(param_2,(void *)((ulong)*(uint *)(lVar1 + 0x44) + *(long *)(lVar1 + 0x48)),
             (ulong)(*(int *)(lVar1 + 0x40) - *(uint *)(lVar1 + 0x44)));
      memcpy((void *)((long)param_2 +
                     ((ulong)*(uint *)(lVar1 + 0x40) - (ulong)*(uint *)(lVar1 + 0x44))),
             *(void **)(lVar1 + 0x48),(ulong)*(uint *)(lVar1 + 0x44));
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(lVar1 + 0x40);
    }
  }
  else {
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}



// Function: inflateSetDictionary @ 0xaaf0

undefined8 inflateSetDictionary(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  param_3 = param_3 & 0xffffffff;
  iVar2 = FUN_001087d0();
  if (iVar2 != 0) {
    return 0xfffffffe;
  }
  lVar1 = *(long *)(param_1 + 0x38);
  if (*(int *)(lVar1 + 0x10) == 0) {
    if (*(int *)(lVar1 + 8) != 0x3f3e) goto LAB_0010ab27;
  }
  else if (*(int *)(lVar1 + 8) != 0x3f3e) {
    return 0xfffffffe;
  }
  uVar3 = FUN_0010d8e0(0,0,0);
  lVar4 = FUN_0010d8e0(uVar3,param_2,param_3);
  if (*(long *)(lVar1 + 0x20) != lVar4) {
    return 0xfffffffd;
  }
LAB_0010ab27:
  uVar3 = FUN_001088d0(param_1,param_3 + param_2,param_3);
  if ((int)uVar3 == 0) {
    *(undefined4 *)(lVar1 + 0x14) = 1;
  }
  else {
    *(undefined4 *)(lVar1 + 8) = 0x3f52;
    uVar3 = 0xfffffffc;
  }
  return uVar3;
}



// Function: inflateGetHeader @ 0xaba0

undefined8 inflateGetHeader(long param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_001087d0();
  if (((int)uVar1 == 0) && ((*(byte *)(*(long *)(param_1 + 0x38) + 0x10) & 2) != 0)) {
    *(long *)(*(long *)(param_1 + 0x38) + 0x30) = param_2;
    *(undefined4 *)(param_2 + 0x48) = 0;
    return uVar1;
  }
  return 0xfffffffe;
}



// Function: inflateSync @ 0xabd0

undefined8 inflateSync(long *param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long *plVar9;
  undefined8 uVar10;
  long in_FS_OFFSET;
  undefined1 local_34 [4];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  plVar9 = param_1;
  iVar2 = FUN_001087d0();
  if (iVar2 == 0) {
    iVar2 = (int)plVar9[1];
    lVar1 = plVar9[7];
    uVar10 = 0;
    if ((iVar2 == 0) && (*(uint *)(lVar1 + 0x58) < 8)) {
      uVar10 = 0xfffffffb;
    }
    else {
      if (*(int *)(lVar1 + 8) != 0x3f53) {
        uVar7 = *(uint *)(lVar1 + 0x58);
        *(undefined4 *)(lVar1 + 8) = 0x3f53;
        uVar6 = uVar7 & 0xfffffff8;
        *(uint *)(lVar1 + 0x58) = uVar6;
        uVar3 = *(long *)(lVar1 + 0x50) << ((byte)uVar7 & 7);
        *(ulong *)(lVar1 + 0x50) = uVar3;
        if (uVar6 < 8) {
          iVar2 = 0;
        }
        else {
          puVar5 = local_34;
          uVar7 = uVar6 - 8 >> 3;
          do {
            *puVar5 = (char)uVar3;
            puVar5 = puVar5 + 1;
            uVar3 = uVar3 >> 8;
          } while (puVar5 != local_34 + (ulong)uVar7 + 1);
          *(ulong *)(lVar1 + 0x50) = uVar3;
          iVar2 = uVar7 + 1;
          *(undefined4 *)(lVar1 + 0x58) = 0;
        }
        *(undefined4 *)(lVar1 + 0x8c) = 0;
        FUN_00108850(lVar1 + 0x8c,local_34,iVar2);
        iVar2 = (int)param_1[1];
      }
      lVar8 = *param_1;
      uVar7 = FUN_00108850(lVar1 + 0x8c,lVar8,iVar2);
      *(uint *)(param_1 + 1) = (int)param_1[1] - uVar7;
      lVar4 = (ulong)uVar7 + param_1[2];
      iVar2 = *(int *)(lVar1 + 0x8c);
      *param_1 = lVar8 + (ulong)uVar7;
      param_1[2] = lVar4;
      if (iVar2 == 4) {
        iVar2 = *(int *)(lVar1 + 0x18);
        uVar7 = 0;
        if (iVar2 != -1) {
          uVar7 = *(uint *)(lVar1 + 0x10) & 0xfffffffb;
        }
        *(uint *)(lVar1 + 0x10) = uVar7;
        lVar8 = param_1[5];
        FUN_00108ab0(param_1);
        param_1[2] = lVar4;
        param_1[5] = lVar8;
        *(int *)(lVar1 + 0x18) = iVar2;
        *(undefined4 *)(lVar1 + 8) = 0x3f3f;
      }
      else {
        uVar10 = 0xfffffffd;
      }
    }
  }
  else {
    uVar10 = 0xfffffffe;
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: inflateSyncPoint @ 0xad50

ulong inflateSyncPoint(long param_1)

{
  ulong uVar1;
  
  uVar1 = FUN_001087d0();
  if ((int)uVar1 != 0) {
    return 0xfffffffe;
  }
  if (*(int *)(*(long *)(param_1 + 0x38) + 8) != 0x3f41) {
    return uVar1;
  }
  return (ulong)(*(int *)(*(long *)(param_1 + 0x38) + 0x58) == 0);
}



// Function: inflateCopy @ 0xad90

undefined8 inflateCopy(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  void *__dest;
  undefined8 *puVar5;
  void *pvVar6;
  long lVar7;
  ulong uVar8;
  undefined8 *puVar9;
  byte bVar10;
  
  bVar10 = 0;
  iVar3 = FUN_001087d0(param_2);
  if ((iVar3 != 0) || (param_1 == (undefined8 *)0x0)) {
    return 0xfffffffe;
  }
  puVar1 = (undefined8 *)param_2[7];
  puVar4 = (undefined8 *)(*(code *)param_2[8])(param_2[10],1,0x1bf8);
  if (puVar4 == (undefined8 *)0x0) {
    return 0xfffffffc;
  }
  if (puVar1[9] == 0) {
    uVar2 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = uVar2;
    uVar2 = param_2[3];
    lVar7 = (long)puVar4 - (long)((ulong)(puVar4 + 1) & 0xfffffffffffffff8);
    param_1[2] = param_2[2];
    param_1[3] = uVar2;
    uVar2 = param_2[5];
    param_1[4] = param_2[4];
    param_1[5] = uVar2;
    uVar2 = param_2[7];
    param_1[6] = param_2[6];
    param_1[7] = uVar2;
    uVar2 = param_2[9];
    param_1[8] = param_2[8];
    param_1[9] = uVar2;
    uVar2 = param_2[0xb];
    param_1[10] = param_2[10];
    param_1[0xb] = uVar2;
    uVar2 = param_2[0xd];
    param_1[0xc] = param_2[0xc];
    param_1[0xd] = uVar2;
    *puVar4 = *puVar1;
    puVar4[0x37e] = puVar1[0x37e];
    puVar5 = (undefined8 *)((long)puVar1 - lVar7);
    puVar9 = (undefined8 *)((ulong)(puVar4 + 1) & 0xfffffffffffffff8);
    for (uVar8 = (ulong)((int)lVar7 + 0x1bf8U >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + (ulong)bVar10 * -2 + 1;
      puVar9 = puVar9 + (ulong)bVar10 * -2 + 1;
    }
    *puVar4 = param_1;
    puVar5 = (undefined8 *)puVar1[0xd];
    pvVar6 = (void *)0x0;
    __dest = pvVar6;
    if (puVar5 < puVar1 + 0xab) {
      puVar4[0x12] = (long)puVar4 + (puVar1[0x12] - (long)(puVar1 + 0xab)) + 0x558;
      goto LAB_0010aee4;
    }
LAB_0010aea3:
    puVar9 = puVar1 + 0xab;
    if (puVar5 <= (undefined8 *)((long)puVar1 + 0x1be4U)) {
      puVar4[0xd] = (long)puVar4 + (long)puVar5 + (0x558 - (long)puVar9);
      puVar4[0xe] = (long)puVar4 + ((puVar1[0xe] + 0x558) - (long)puVar9);
    }
    puVar4[0x12] = (long)puVar4 + ((puVar1[0x12] + 0x558) - (long)puVar9);
    pvVar6 = (void *)0x0;
    if (__dest == (void *)0x0) goto LAB_0010aee4;
  }
  else {
    __dest = (void *)(*(code *)param_2[8])
                               (param_2[10],1 << ((byte)*(undefined4 *)(puVar1 + 7) & 0x1f),1);
    if (__dest == (void *)0x0) {
      (*(code *)param_2[9])(param_2[10],puVar4);
      return 0xfffffffc;
    }
    uVar2 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = uVar2;
    uVar2 = param_2[3];
    lVar7 = (long)puVar4 - (long)((ulong)(puVar4 + 1) & 0xfffffffffffffff8);
    param_1[2] = param_2[2];
    param_1[3] = uVar2;
    uVar2 = param_2[5];
    param_1[4] = param_2[4];
    param_1[5] = uVar2;
    uVar2 = param_2[7];
    param_1[6] = param_2[6];
    param_1[7] = uVar2;
    uVar2 = param_2[9];
    param_1[8] = param_2[8];
    param_1[9] = uVar2;
    uVar2 = param_2[0xb];
    param_1[10] = param_2[10];
    param_1[0xb] = uVar2;
    uVar2 = param_2[0xd];
    param_1[0xc] = param_2[0xc];
    param_1[0xd] = uVar2;
    *puVar4 = *puVar1;
    puVar4[0x37e] = puVar1[0x37e];
    puVar5 = (undefined8 *)((long)puVar1 - lVar7);
    puVar9 = (undefined8 *)((ulong)(puVar4 + 1) & 0xfffffffffffffff8);
    for (uVar8 = (ulong)((int)lVar7 + 0x1bf8U >> 3); uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + (ulong)bVar10 * -2 + 1;
      puVar9 = puVar9 + (ulong)bVar10 * -2 + 1;
    }
    *puVar4 = param_1;
    puVar5 = (undefined8 *)puVar1[0xd];
    if (puVar1 + 0xab <= puVar5) goto LAB_0010aea3;
    puVar4[0x12] = (long)puVar4 + (puVar1[0x12] - (long)(puVar1 + 0xab)) + 0x558;
  }
  pvVar6 = memcpy(__dest,(void *)puVar1[9],
                  (ulong)(uint)(1 << ((byte)*(undefined4 *)(puVar1 + 7) & 0x1f)));
LAB_0010aee4:
  puVar4[9] = pvVar6;
  param_1[7] = puVar4;
  return 0;
}



// Function: inflateUndermine @ 0xb020

undefined8 inflateUndermine(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_001087d0();
  uVar2 = 0xfffffffe;
  if (iVar1 == 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x38) + 0x1be8) = 1;
    uVar2 = 0xfffffffd;
  }
  return uVar2;
}



// Function: inflateValidate @ 0xb050

undefined8 inflateValidate(long param_1,int param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_001087d0();
  if ((int)uVar3 != 0) {
    return 0xfffffffe;
  }
  lVar2 = *(long *)(param_1 + 0x38);
  uVar1 = *(uint *)(lVar2 + 0x10);
  if ((param_2 != 0) && (uVar1 != 0)) {
    *(uint *)(lVar2 + 0x10) = uVar1 | 4;
    return uVar3;
  }
  *(uint *)(lVar2 + 0x10) = uVar1 & 0xfffffffb;
  return uVar3;
}



// Function: inflateMark @ 0xb090

long inflateMark(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  iVar2 = FUN_001087d0();
  if (iVar2 != 0) {
    return -0x10000;
  }
  lVar1 = *(long *)(param_1 + 0x38);
  lVar3 = (long)*(int *)(lVar1 + 0x1bec) * 0x10000;
  if (*(int *)(lVar1 + 8) != 0x3f43) {
    if (*(int *)(lVar1 + 8) != 0x3f4c) {
      return lVar3;
    }
    return lVar3 + (ulong)(uint)(*(int *)(lVar1 + 0x1bf0) - *(int *)(lVar1 + 0x5c));
  }
  return lVar3 + (ulong)*(uint *)(lVar1 + 0x5c);
}



// Function: inflateCodesUsed @ 0xb0f0

long inflateCodesUsed(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = FUN_001087d0();
  lVar2 = -1;
  if (iVar1 == 0) {
    lVar2 = *(long *)(*(long *)(param_1 + 0x38) + 0x90) - (*(long *)(param_1 + 0x38) + 0x558) >> 2;
  }
  return lVar2;
}



// Function: inflate_table @ 0xb130

undefined8
inflate_table(int param_1,ushort *param_2,uint param_3,long *param_4,uint *param_5,undefined *param_6
            )

{
  byte *pbVar1;
  undefined1 *puVar2;
  ushort uVar3;
  undefined4 *puVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  undefined8 uVar8;
  ulong uVar9;
  short sVar10;
  int iVar11;
  uint uVar12;
  ushort *puVar13;
  ushort *puVar14;
  long lVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  long lVar20;
  ushort uVar21;
  ulong uVar22;
  undefined1 uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  ulong uVar27;
  long in_FS_OFFSET;
  bool bVar28;
  bool bVar29;
  uint local_d0;
  uint local_cc;
  uint local_c4;
  undefined *local_a0;
  undefined *local_98;
  ushort local_88 [36];
  long local_40;
  ulong uVar19;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  puVar13 = local_88;
  do {
    puVar14 = puVar13 + 1;
    *puVar13 = 0;
    puVar13 = puVar14;
  } while (local_88 + 0x10 != puVar14);
  if (param_3 != 0) {
    puVar13 = param_2;
    do {
      uVar21 = *puVar13;
      puVar13 = puVar13 + 1;
      local_88[uVar21] = local_88[uVar21] + 1;
    } while (param_2 + (ulong)(param_3 - 1) + 1 != puVar13);
  }
  puVar13 = local_88 + 0xf;
  uVar24 = 0xf;
  uVar17 = *param_5;
  do {
    if (*puVar13 != 0) {
      puVar13 = local_88 + 1;
      uVar22 = 1;
      puVar14 = puVar13;
      if (uVar24 == 1) goto LAB_0010b273;
      goto LAB_0010b26d;
    }
    puVar13 = puVar13 + -1;
    uVar24 = uVar24 - 1;
  } while (uVar24 != 0);
  puVar4 = (undefined4 *)*param_4;
  *puVar4 = 0x140;
  *param_4 = (long)(puVar4 + 2);
  puVar4[1] = 0x140;
  *param_5 = 1;
  uVar8 = 0;
  goto LAB_0010b211;
  while( true ) {
    uVar25 = (int)uVar22 + 1;
    uVar22 = (ulong)uVar25;
    puVar14 = puVar14 + 1;
    if (uVar25 == uVar24) break;
LAB_0010b26d:
    if (*puVar14 != 0) break;
  }
LAB_0010b273:
  iVar11 = 1;
  puVar14 = puVar13;
  do {
    iVar11 = iVar11 * 2 - (uint)*puVar14;
    if (iVar11 < 0) goto LAB_0010b390;
    puVar14 = puVar14 + 1;
  } while (local_88 + 0x10 != puVar14);
  if ((iVar11 != 0) && ((param_1 == 0 || (uVar24 != 1)))) {
LAB_0010b390:
    uVar8 = 0xffffffff;
    goto LAB_0010b211;
  }
  lVar15 = 0;
  local_88[0x11] = 0;
  sVar10 = 0;
  do {
    sVar10 = sVar10 + *(short *)((long)puVar13 + lVar15);
    *(short *)((long)local_88 + lVar15 + 0x24) = sVar10;
    lVar15 = lVar15 + 2;
  } while (lVar15 != 0x1c);
  uVar16 = 0;
  if (param_3 != 0) {
    do {
      uVar21 = param_2[uVar16];
      if (uVar21 != 0) {
        uVar3 = local_88[(ulong)uVar21 + 0x10];
        *(short *)(param_6 + (ulong)uVar3 * 2) = (short)uVar16;
        local_88[(ulong)uVar21 + 0x10] = uVar3 + 1;
      }
      uVar16 = uVar16 + 1;
    } while (param_3 != uVar16);
  }
  if (uVar24 < uVar17) {
    uVar17 = uVar24;
  }
  lVar15 = *param_4;
  uVar16 = (ulong)uVar17;
  if (uVar17 < (uint)uVar22) {
    uVar16 = uVar22;
  }
  uVar17 = (uint)uVar16;
  local_cc = 1 << ((byte)uVar16 & 0x1f);
  if (param_1 == 0) {
    local_d0 = 0x14;
    bVar28 = false;
    local_a0 = param_6;
    local_98 = param_6;
LAB_0010b3cd:
    bVar29 = param_1 == 1;
LAB_0010b3d5:
    uVar9 = 0;
    uVar26 = 0;
    local_c4 = 0xffffffff;
    uVar27 = 0;
    uVar7 = local_cc - 1;
    lVar20 = lVar15;
    uVar25 = uVar17;
    do {
      do {
        uVar23 = 0;
        bVar6 = (byte)uVar26;
        cVar5 = (char)uVar22;
        uVar21 = *(ushort *)(param_6 + uVar27 * 2);
        if (local_d0 <= uVar21 + 1) {
          if (uVar21 < local_d0) {
            uVar21 = 0;
            uVar23 = 0x60;
          }
          else {
            uVar23 = local_98[(ulong)(uVar21 - local_d0) * 2];
            uVar21 = *(ushort *)(local_a0 + (ulong)(uVar21 - local_d0) * 2);
          }
        }
        uVar12 = (uint)uVar9;
        uVar18 = 1 << ((byte)uVar25 & 0x1f);
        uVar19 = (ulong)uVar18;
        do {
          uVar18 = uVar18 - (1 << (cVar5 - bVar6 & 0x1f));
          puVar2 = (undefined1 *)(lVar20 + (ulong)((uVar12 >> (bVar6 & 0x1f)) + uVar18) * 4);
          *puVar2 = uVar23;
          puVar2[1] = cVar5 - bVar6;
          *(ushort *)(puVar2 + 2) = uVar21;
        } while (uVar18 != 0);
        uVar18 = 1 << (cVar5 - 1U & 0x1f);
        uVar9 = (ulong)uVar18;
        if ((uVar12 & uVar18) == 0) {
LAB_0010b5c8:
          uVar9 = (ulong)(uVar18 + (uVar18 - 1 & uVar12));
        }
        else {
          do {
            uVar9 = uVar9 >> 1;
            uVar18 = (uint)uVar9;
          } while ((uVar12 & uVar18) != 0);
          if (uVar18 != 0) goto LAB_0010b5c8;
        }
        uVar27 = (ulong)((int)uVar27 + 1);
        puVar13 = local_88 + uVar22;
        *puVar13 = *puVar13 - 1;
        if (*puVar13 == 0) {
          if ((uint)uVar22 == uVar24) {
            if ((uint)uVar9 != 0) {
              puVar2 = (undefined1 *)(lVar20 + uVar9 * 4);
              *puVar2 = 0x40;
              puVar2[1] = cVar5 - bVar6;
              *(undefined2 *)(puVar2 + 2) = 0;
            }
            *param_4 = lVar15 + (ulong)local_cc * 4;
            *param_5 = uVar17;
            uVar8 = 0;
            goto LAB_0010b211;
          }
          uVar22 = (ulong)param_2[*(ushort *)(param_6 + uVar27 * 2)];
        }
        uVar18 = (uint)uVar22;
      } while ((uVar18 <= uVar17) || (uVar12 = uVar7 & (uint)uVar9, uVar12 == local_c4));
      lVar20 = lVar20 + uVar19 * 4;
      if (uVar26 == 0) {
        uVar26 = uVar17;
      }
      uVar25 = uVar18 - uVar26;
      if ((uVar18 < uVar24) &&
         (iVar11 = (1 << ((byte)uVar25 & 0x1f)) - (uint)local_88[uVar22], 0 < iVar11)) {
        puVar13 = local_88 + (uVar18 + 1);
        do {
          uVar25 = uVar25 + 1;
          if (uVar24 <= uVar26 + uVar25) break;
          uVar21 = *puVar13;
          puVar13 = puVar13 + 1;
          iVar11 = iVar11 * 2 - (uint)uVar21;
        } while (0 < iVar11);
      }
      local_cc = local_cc + (1 << ((byte)uVar25 & 0x1f));
      if (((0x354 < local_cc) && (bVar29)) || ((0x250 < local_cc && (bVar28)))) goto LAB_0010b3a8;
      pbVar1 = (byte *)(lVar15 + (ulong)uVar12 * 4);
      *pbVar1 = (byte)uVar25;
      *(short *)(pbVar1 + 2) = (short)(lVar20 - lVar15 >> 2);
      pbVar1[1] = (byte)uVar16;
      local_c4 = uVar12;
    } while( true );
  }
  if (param_1 == 1) {
    if (local_cc < 0x355) {
      local_d0 = 0x101;
      local_98 = &DAT_0010ff40;
      local_a0 = &DAT_0010ff80;
      bVar29 = true;
      bVar28 = false;
      goto LAB_0010b3d5;
    }
  }
  else {
    bVar28 = param_1 == 2;
    if ((local_cc < 0x251) || (!bVar28)) {
      local_d0 = 0;
      local_98 = &DAT_0010fec0;
      local_a0 = &DAT_0010ff00;
      goto LAB_0010b3cd;
    }
  }
LAB_0010b3a8:
  uVar8 = 1;
LAB_0010b211:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



// Function: init_block @ 0xb660

void init_block(long param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)(param_1 + 0xd4);
  do {
    puVar1 = puVar2 + 2;
    *puVar2 = 0;
    puVar2 = puVar1;
  } while (puVar1 != (undefined2 *)(param_1 + 0x54c));
  puVar2 = (undefined2 *)(param_1 + 0x9c8);
  do {
    puVar1 = puVar2 + 2;
    *puVar2 = 0;
    puVar2 = puVar1;
  } while (puVar1 != (undefined2 *)(param_1 + 0xa40));
  puVar2 = (undefined2 *)(param_1 + 0xabc);
  do {
    puVar1 = puVar2 + 2;
    *puVar2 = 0;
    puVar2 = puVar1;
  } while (puVar1 != (undefined2 *)(param_1 + 0xb08));
  *(undefined8 *)(param_1 + 0x1720) = 0;
  *(undefined2 *)(param_1 + 0x4d4) = 1;
  *(undefined8 *)(param_1 + 0x1718) = 0;
  *(undefined4 *)(param_1 + 0x1728) = 0;
  *(undefined4 *)(param_1 + 0x170c) = 0;
  return;
}



// Function: pqdownheap @ 0xb700

void pqdownheap(long param_1,long param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  long lVar12;
  
  lVar12 = (long)param_3;
  param_3 = param_3 * 2;
  iVar4 = *(int *)(param_1 + 0x14b4);
  iVar5 = *(int *)(param_1 + 0xbc0 + lVar12 * 4);
  if (param_3 <= iVar4) {
    uVar1 = *(ushort *)(param_2 + (long)iVar5 * 4);
    do {
      iVar6 = *(int *)(param_1 + 0xbc0 + (long)param_3 * 4);
      uVar2 = *(ushort *)(param_2 + (long)iVar6 * 4);
      iVar9 = param_3;
      uVar11 = uVar2;
      iVar10 = iVar6;
      if (param_3 < iVar4) {
        iVar8 = param_3 + 1;
        iVar7 = *(int *)(param_1 + 0xbc0 + (long)iVar8 * 4);
        uVar3 = *(ushort *)(param_2 + (long)iVar7 * 4);
        iVar9 = iVar8;
        uVar11 = uVar3;
        iVar10 = iVar7;
        if (((uVar2 <= uVar3) && (iVar9 = param_3, uVar11 = uVar2, iVar10 = iVar6, uVar3 == uVar2))
           && (iVar9 = iVar8, iVar10 = iVar7,
              *(byte *)(param_1 + 0x14bc + (long)iVar6) < *(byte *)(param_1 + 0x14bc + (long)iVar7))
           ) {
          iVar9 = param_3;
          iVar10 = iVar6;
        }
      }
      if ((uVar1 < uVar11) ||
         ((uVar1 == uVar11 &&
          (*(byte *)(param_1 + 0x14bc + (long)iVar5) <= *(byte *)(param_1 + 0x14bc + (long)iVar10)))
         )) break;
      param_3 = iVar9 * 2;
      *(int *)(param_1 + 0xbc0 + lVar12 * 4) = iVar10;
      lVar12 = (long)iVar9;
    } while (param_3 <= iVar4);
  }
  *(int *)(param_1 + 0xbc0 + lVar12 * 4) = iVar5;
  return;
}



// Function: gen_bitlen @ 0xb7f0

void gen_bitlen(long param_1,long *param_2)

{
  ushort *puVar1;
  short *psVar2;
  ushort uVar3;
  short sVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  int iVar10;
  uint uVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  long lVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  long lVar18;
  long lVar19;
  int iVar20;
  
  plVar5 = (long *)param_2[2];
  lVar6 = *param_2;
  lVar9 = param_2[1];
  lVar14 = *plVar5;
  lVar7 = plVar5[1];
  lVar18 = plVar5[2];
  uVar16 = *(uint *)(plVar5 + 3);
  puVar12 = (undefined2 *)(param_1 + 0xba0);
  do {
    puVar13 = puVar12 + 1;
    *puVar12 = 0;
    puVar12 = puVar13;
  } while (puVar13 != (undefined2 *)(param_1 + 0xbc0));
  iVar17 = 0;
  iVar10 = *(int *)(param_1 + 0x14b8) + 1;
  *(undefined2 *)
   (lVar6 + 2 + (long)*(int *)(param_1 + 0xbc0 + (long)*(int *)(param_1 + 0x14b8) * 4) * 4) = 0;
  lVar19 = (long)iVar10;
  if (iVar10 < 0x23d) {
    do {
      iVar10 = *(int *)(param_1 + 0xbc0 + lVar19 * 4);
      puVar1 = (ushort *)(lVar6 + (long)iVar10 * 4);
      uVar11 = *(ushort *)(lVar6 + 2 + (ulong)puVar1[1] * 4) + 1;
      if ((int)uVar16 < (int)uVar11) {
        iVar17 = iVar17 + 1;
        uVar11 = uVar16;
      }
      puVar1[1] = (ushort)uVar11;
      if (iVar10 <= (int)lVar9) {
        psVar2 = (short *)(param_1 + 0xba0 + (long)(int)uVar11 * 2);
        *psVar2 = *psVar2 + 1;
        iVar20 = 0;
        if ((int)lVar18 <= iVar10) {
          iVar20 = *(int *)(lVar7 + (long)(iVar10 - (int)lVar18) * 4);
          uVar11 = uVar11 + iVar20;
        }
        uVar3 = *puVar1;
        *(long *)(param_1 + 0x1718) = *(long *)(param_1 + 0x1718) + (ulong)uVar11 * (ulong)uVar3;
        if (lVar14 != 0) {
          *(long *)(param_1 + 0x1720) =
               *(long *)(param_1 + 0x1720) +
               (ulong)((uint)*(ushort *)(lVar14 + 2 + (long)iVar10 * 4) + iVar20) * (ulong)uVar3;
        }
      }
      lVar19 = lVar19 + 1;
    } while ((int)lVar19 < 0x23d);
    if (iVar17 != 0) {
      iVar10 = iVar17 + -2;
      uVar11 = uVar16 - 1;
      iVar17 = iVar10 - (iVar17 - 1U & 0xfffffffe);
      lVar18 = (long)(int)uVar16;
      lVar14 = param_1 + lVar18 * 2;
      sVar4 = *(short *)(lVar14 + 0xb9e);
      uVar15 = uVar16;
      lVar7 = lVar14;
      uVar8 = uVar11;
      while( true ) {
        while (sVar4 == 0) {
          sVar4 = *(short *)(lVar7 + 0xb9c);
          uVar15 = uVar8;
          lVar7 = lVar7 + -2;
          uVar8 = uVar8 - 1;
        }
        *(short *)(param_1 + 0xba0 + (long)(int)uVar8 * 2) = sVar4 + -1;
        psVar2 = (short *)(param_1 + 0xba0 + (long)(int)uVar15 * 2);
        *psVar2 = *psVar2 + 2;
        *(short *)(lVar14 + 0xba0) = *(short *)(lVar14 + 0xba0) + -1;
        if (iVar10 == iVar17) break;
        sVar4 = *(short *)(lVar14 + 0xb9e);
        iVar10 = iVar10 + -2;
        uVar15 = uVar16;
        lVar7 = lVar14;
        uVar8 = uVar11;
      }
      if (uVar16 != 0) {
        iVar10 = 0x23d;
        while( true ) {
          uVar3 = *(ushort *)(param_1 + 0xba0 + lVar18 * 2);
          uVar15 = (uint)uVar3;
          if (uVar3 != 0) {
            lVar14 = (long)(iVar10 + -1);
            do {
              while( true ) {
                iVar17 = *(int *)(param_1 + 0xbc0 + lVar14 * 4);
                iVar10 = (int)lVar14;
                if (iVar17 <= (int)lVar9) break;
                lVar14 = lVar14 + -1;
              }
              puVar1 = (ushort *)(lVar6 + (long)iVar17 * 4);
              if (puVar1[1] != uVar16) {
                *(long *)(param_1 + 0x1718) =
                     *(long *)(param_1 + 0x1718) + (ulong)*puVar1 * (lVar18 - (ulong)puVar1[1]);
                puVar1[1] = (ushort)uVar16;
              }
              lVar14 = lVar14 + -1;
              uVar15 = uVar15 - 1;
            } while (uVar15 != 0);
          }
          lVar18 = lVar18 + -1;
          if (uVar11 == 0) break;
          uVar16 = uVar11;
          uVar11 = uVar11 - 1;
        }
      }
    }
  }
  return;
}



// Function: scan_tree @ 0xba40

void scan_tree(long param_1,long param_2,int param_3)

{
  ushort *puVar1;
  short *psVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  uVar3 = *(ushort *)(param_2 + 2);
  *(undefined2 *)(param_2 + 6 + (long)param_3 * 4) = 0xffff;
  iVar9 = 4 - (uint)(uVar3 == 0);
  iVar8 = (-(uint)(uVar3 == 0) & 0x83) + 7;
  if (-1 < param_3) {
    puVar1 = (ushort *)(param_2 + 10 + (long)param_3 * 4);
    puVar7 = (ushort *)(param_2 + 6);
    iVar4 = 0;
    uVar10 = 0xffffffff;
    uVar5 = (uint)uVar3;
    do {
      while( true ) {
        iVar4 = iVar4 + 1;
        uVar3 = *puVar7;
        uVar6 = (uint)uVar3;
        if (iVar4 < iVar8) break;
LAB_0010ba90:
        if (uVar5 == 0) {
          if (iVar4 < 0xb) {
            *(short *)(param_1 + 0xb00) = *(short *)(param_1 + 0xb00) + 1;
          }
          else {
            *(short *)(param_1 + 0xb04) = *(short *)(param_1 + 0xb04) + 1;
          }
        }
        else {
          if (uVar5 != uVar10) {
            psVar2 = (short *)(param_1 + 0xabc + (long)(int)uVar5 * 4);
            *psVar2 = *psVar2 + 1;
          }
          *(short *)(param_1 + 0xafc) = *(short *)(param_1 + 0xafc) + 1;
        }
        if (uVar6 == 0) {
LAB_0010bb18:
          iVar9 = 3;
          iVar8 = 0x8a;
          iVar4 = 0;
          uVar10 = uVar5;
          goto LAB_0010bacb;
        }
        if (uVar6 == uVar5) {
          iVar9 = 3;
          iVar8 = 6;
          iVar4 = 0;
          uVar10 = uVar6;
          goto LAB_0010bacb;
        }
LAB_0010baf9:
        puVar7 = puVar7 + 2;
        iVar9 = 4;
        iVar4 = 0;
        iVar8 = 7;
        uVar10 = uVar5;
        uVar5 = uVar6;
        if (puVar1 == puVar7) {
          return;
        }
      }
      if (uVar6 != uVar5) {
        if (iVar9 <= iVar4) goto LAB_0010ba90;
        psVar2 = (short *)(param_1 + 0xabc + (long)(int)uVar5 * 4);
        *psVar2 = *psVar2 + (short)iVar4;
        if (uVar3 != 0) goto LAB_0010baf9;
        goto LAB_0010bb18;
      }
LAB_0010bacb:
      puVar7 = puVar7 + 2;
      uVar5 = uVar6;
    } while (puVar1 != puVar7);
  }
  return;
}



// Function: send_tree @ 0xbb60

void send_tree(long param_1,long param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  long lVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  ushort *puVar14;
  
  uVar1 = *(ushort *)(param_2 + 2);
  iVar12 = 4 - (uint)(uVar1 == 0);
  iVar5 = (-(uint)(uVar1 == 0) & 0x83) + 7;
  if (-1 < param_3) {
    puVar14 = (ushort *)(param_2 + 6);
    uVar7 = 0xffffffff;
    iVar11 = 0;
    uVar8 = (uint)uVar1;
    do {
      iVar6 = iVar11 + 1;
      uVar1 = *puVar14;
      uVar9 = (uint)uVar1;
      if (iVar6 < iVar5) {
        if (uVar9 != uVar8) {
          if (iVar12 <= iVar6) goto LAB_0010bca0;
          do {
            uVar7 = (uint)*(ushort *)(param_1 + 0xe + ((long)(int)uVar8 + 0x2ac) * 4);
            uVar2 = *(ushort *)(param_1 + 0xc + ((long)(int)uVar8 + 0x2ac) * 4);
            iVar5 = *(int *)(param_1 + 0x1734);
            uVar10 = uVar2 << ((byte)iVar5 & 0x1f) | *(ushort *)(param_1 + 0x1730);
            if ((int)(0x10 - uVar7) < iVar5) {
              lVar3 = *(long *)(param_1 + 0x28);
              *(ushort *)(param_1 + 0x1730) = uVar10;
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(char *)(*(long *)(param_1 + 0x10) + lVar3) = (char)uVar10;
              lVar3 = *(long *)(param_1 + 0x28);
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar3) = *(undefined1 *)(param_1 + 0x1731)
              ;
              iVar5 = *(int *)(param_1 + 0x1734) + -0x10;
              uVar10 = (ushort)((int)(uint)uVar2 >>
                               (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f));
            }
            *(ushort *)(param_1 + 0x1730) = uVar10;
            *(uint *)(param_1 + 0x1734) = iVar5 + uVar7;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          if (uVar1 != 0) goto LAB_0010bc79;
          goto LAB_0010be48;
        }
      }
      else {
LAB_0010bca0:
        iVar5 = *(int *)(param_1 + 0x1734);
        uVar13 = (uint)*(ushort *)(param_1 + 0x1730);
        bVar4 = (byte)iVar5;
        if (uVar8 == 0) {
          if (iVar6 < 0xb) {
            uVar2 = *(ushort *)(param_1 + 0xb02);
            uVar7 = (uint)*(ushort *)(param_1 + 0xb00);
            if ((int)(0x10 - (uint)uVar2) < iVar5) {
              lVar3 = *(long *)(param_1 + 0x28);
              uVar13 = uVar7 << (bVar4 & 0x1f) | uVar13;
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(short *)(param_1 + 0x1730) = (short)uVar13;
              *(char *)(*(long *)(param_1 + 0x10) + lVar3) = (char)uVar13;
              lVar3 = *(long *)(param_1 + 0x28);
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar3) = *(undefined1 *)(param_1 + 0x1731)
              ;
              uVar7 = (int)uVar7 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
              iVar5 = *(int *)(param_1 + 0x1734) + -0x10 + (uint)uVar2;
            }
            else {
              iVar5 = (uint)uVar2 + iVar5;
              uVar7 = uVar13 | uVar7 << (bVar4 & 0x1f);
            }
            *(int *)(param_1 + 0x1734) = iVar5;
            if (iVar5 < 0xe) {
              *(int *)(param_1 + 0x1734) = iVar5 + 3;
              *(ushort *)(param_1 + 0x1730) =
                   (ushort)uVar7 | (ushort)((iVar11 - 2U & 0xffff) << ((byte)iVar5 & 0x1f));
            }
            else {
              uVar13 = iVar11 - 2U & 0xffff;
              lVar3 = *(long *)(param_1 + 0x28);
              uVar7 = uVar13 << ((byte)iVar5 & 0x1f) | uVar7;
              *(short *)(param_1 + 0x1730) = (short)uVar7;
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(char *)(*(long *)(param_1 + 0x10) + lVar3) = (char)uVar7;
              lVar3 = *(long *)(param_1 + 0x28);
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar3) = *(undefined1 *)(param_1 + 0x1731)
              ;
              iVar5 = *(int *)(param_1 + 0x1734);
              *(int *)(param_1 + 0x1734) = iVar5 + -0xd;
              *(short *)(param_1 + 0x1730) = (short)((int)uVar13 >> (0x10U - (char)iVar5 & 0x1f));
            }
          }
          else {
            uVar2 = *(ushort *)(param_1 + 0xb04);
            uVar10 = *(ushort *)(param_1 + 0xb06);
            iVar12 = (uint)uVar10 + iVar5;
            uVar13 = uVar13 | (uint)uVar2 << (bVar4 & 0x1f);
            if ((int)(0x10 - (uint)uVar10) < iVar5) {
              lVar3 = *(long *)(param_1 + 0x28);
              *(short *)(param_1 + 0x1730) = (short)uVar13;
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(char *)(*(long *)(param_1 + 0x10) + lVar3) = (char)uVar13;
              lVar3 = *(long *)(param_1 + 0x28);
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar3) = *(undefined1 *)(param_1 + 0x1731)
              ;
              uVar13 = (int)(uint)uVar2 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
              iVar12 = *(int *)(param_1 + 0x1734) + -0x10 + (uint)uVar10;
            }
            *(int *)(param_1 + 0x1734) = iVar12;
            if (iVar12 < 10) {
              *(ushort *)(param_1 + 0x1730) =
                   (ushort)uVar13 | (ushort)((iVar11 - 10U & 0xffff) << ((byte)iVar12 & 0x1f));
              *(int *)(param_1 + 0x1734) = iVar12 + 7;
            }
            else {
              uVar7 = iVar11 - 10U & 0xffff;
              lVar3 = *(long *)(param_1 + 0x28);
              uVar13 = uVar7 << ((byte)iVar12 & 0x1f) | uVar13;
              *(short *)(param_1 + 0x1730) = (short)uVar13;
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(char *)(*(long *)(param_1 + 0x10) + lVar3) = (char)uVar13;
              lVar3 = *(long *)(param_1 + 0x28);
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar3) = *(undefined1 *)(param_1 + 0x1731)
              ;
              iVar5 = *(int *)(param_1 + 0x1734);
              *(int *)(param_1 + 0x1734) = iVar5 + -9;
              *(short *)(param_1 + 0x1730) = (short)((int)uVar7 >> (0x10U - (char)iVar5 & 0x1f));
            }
          }
        }
        else {
          if (uVar7 != uVar8) {
            uVar2 = *(ushort *)(param_1 + 0xabc + (long)(int)uVar8 * 4);
            uVar10 = *(ushort *)(param_1 + 0xabe + (long)(int)uVar8 * 4);
            uVar13 = uVar13 | (uint)uVar2 << (bVar4 & 0x1f);
            iVar6 = iVar11;
            if ((int)(0x10 - (uint)uVar10) < iVar5) {
              lVar3 = *(long *)(param_1 + 0x28);
              *(short *)(param_1 + 0x1730) = (short)uVar13;
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(char *)(*(long *)(param_1 + 0x10) + lVar3) = (char)uVar13;
              lVar3 = *(long *)(param_1 + 0x28);
              *(long *)(param_1 + 0x28) = lVar3 + 1;
              *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar3) = *(undefined1 *)(param_1 + 0x1731)
              ;
              iVar12 = *(int *)(param_1 + 0x1734);
              iVar5 = iVar12 + -0x10 + (uint)uVar10;
              *(int *)(param_1 + 0x1734) = iVar5;
              uVar13 = (int)(uint)uVar2 >> (0x10U - (char)iVar12 & 0x1f);
            }
            else {
              iVar5 = iVar5 + (uint)uVar10;
              *(int *)(param_1 + 0x1734) = iVar5;
            }
          }
          uVar2 = *(ushort *)(param_1 + 0xafc);
          uVar10 = *(ushort *)(param_1 + 0xafe);
          iVar12 = (uint)uVar10 + iVar5;
          uVar13 = uVar13 | (uint)uVar2 << ((byte)iVar5 & 0x1f);
          if ((int)(0x10 - (uint)uVar10) < iVar5) {
            lVar3 = *(long *)(param_1 + 0x28);
            *(short *)(param_1 + 0x1730) = (short)uVar13;
            *(long *)(param_1 + 0x28) = lVar3 + 1;
            *(char *)(*(long *)(param_1 + 0x10) + lVar3) = (char)uVar13;
            lVar3 = *(long *)(param_1 + 0x28);
            *(long *)(param_1 + 0x28) = lVar3 + 1;
            *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar3) = *(undefined1 *)(param_1 + 0x1731);
            uVar13 = (int)(uint)uVar2 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
            iVar12 = *(int *)(param_1 + 0x1734) + -0x10 + (uint)uVar10;
          }
          *(int *)(param_1 + 0x1734) = iVar12;
          uVar7 = iVar6 - 3U & 0xffff;
          if (iVar12 < 0xf) {
            *(int *)(param_1 + 0x1734) = iVar12 + 2;
            *(ushort *)(param_1 + 0x1730) =
                 (ushort)uVar13 | (ushort)(uVar7 << ((byte)iVar12 & 0x1f));
          }
          else {
            lVar3 = *(long *)(param_1 + 0x28);
            uVar13 = uVar7 << ((byte)iVar12 & 0x1f) | uVar13;
            *(short *)(param_1 + 0x1730) = (short)uVar13;
            *(long *)(param_1 + 0x28) = lVar3 + 1;
            *(char *)(*(long *)(param_1 + 0x10) + lVar3) = (char)uVar13;
            lVar3 = *(long *)(param_1 + 0x28);
            *(long *)(param_1 + 0x28) = lVar3 + 1;
            *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar3) = *(undefined1 *)(param_1 + 0x1731);
            iVar5 = *(int *)(param_1 + 0x1734);
            *(int *)(param_1 + 0x1734) = iVar5 + -0xe;
            *(short *)(param_1 + 0x1730) = (short)((int)uVar7 >> (0x10U - (char)iVar5 & 0x1f));
          }
        }
        if (uVar1 == 0) {
LAB_0010be48:
          iVar12 = 3;
          iVar5 = 0x8a;
          iVar6 = 0;
          uVar7 = uVar8;
        }
        else if (uVar9 == uVar8) {
          iVar12 = 3;
          iVar5 = 6;
          iVar6 = 0;
          uVar7 = uVar9;
        }
        else {
LAB_0010bc79:
          iVar12 = 4;
          iVar5 = 7;
          iVar6 = 0;
          uVar7 = uVar8;
        }
      }
      iVar11 = iVar6;
      puVar14 = puVar14 + 2;
      uVar8 = uVar9;
    } while ((ushort *)(param_2 + 10 + (long)param_3 * 4) != puVar14);
  }
  return;
}



// Function: send_all_trees @ 0xc100

void send_all_trees(long param_1,int param_2,int param_3,int param_4)

{
  long lVar1;
  ushort uVar2;
  ulong uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  
  iVar4 = *(int *)(param_1 + 0x1734);
  if (iVar4 < 0xc) {
    iVar7 = iVar4 + 5;
    uVar9 = (uint)*(ushort *)(param_1 + 0x1730) |
            (param_2 - 0x101U & 0xffff) << ((byte)iVar4 & 0x1f);
  }
  else {
    uVar9 = param_2 - 0x101U & 0xffff;
    uVar6 = (uint)*(ushort *)(param_1 + 0x1730) | uVar9 << ((byte)iVar4 & 0x1f);
    lVar1 = *(long *)(param_1 + 0x28);
    *(short *)(param_1 + 0x1730) = (short)uVar6;
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)uVar6;
    lVar1 = *(long *)(param_1 + 0x28);
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar1) = *(undefined1 *)(param_1 + 0x1731);
    uVar9 = (int)uVar9 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
    iVar7 = *(int *)(param_1 + 0x1734) + -0xb;
  }
  *(int *)(param_1 + 0x1734) = iVar7;
  if (iVar7 < 0xc) {
    iVar4 = iVar7 + 5;
    uVar6 = uVar9 | (param_3 - 1U & 0xffff) << ((byte)iVar7 & 0x1f);
  }
  else {
    uVar6 = param_3 - 1U & 0xffff;
    uVar9 = uVar9 | uVar6 << ((byte)iVar7 & 0x1f);
    lVar1 = *(long *)(param_1 + 0x28);
    *(short *)(param_1 + 0x1730) = (short)uVar9;
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)uVar9;
    lVar1 = *(long *)(param_1 + 0x28);
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar1) = *(undefined1 *)(param_1 + 0x1731);
    uVar6 = (int)uVar6 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
    iVar4 = *(int *)(param_1 + 0x1734) + -0xb;
  }
  *(int *)(param_1 + 0x1734) = iVar4;
  if (iVar4 < 0xd) {
    iVar7 = iVar4 + 4;
    uVar5 = (ushort)uVar6 | (ushort)((param_4 - 4U & 0xffff) << ((byte)iVar4 & 0x1f));
  }
  else {
    uVar9 = param_4 - 4U & 0xffff;
    uVar6 = uVar6 | uVar9 << ((byte)iVar4 & 0x1f);
    lVar1 = *(long *)(param_1 + 0x28);
    *(short *)(param_1 + 0x1730) = (short)uVar6;
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)uVar6;
    lVar1 = *(long *)(param_1 + 0x28);
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar1) = *(undefined1 *)(param_1 + 0x1731);
    uVar5 = (ushort)((int)uVar9 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f));
    iVar7 = *(int *)(param_1 + 0x1734) + -0xc;
  }
  *(ushort *)(param_1 + 0x1730) = uVar5;
  *(int *)(param_1 + 0x1734) = iVar7;
  if (0 < param_4) {
    pbVar8 = &DAT_00110901;
    uVar3 = 0x10;
    while( true ) {
      uVar5 = *(ushort *)(param_1 + 0xabe + uVar3 * 4);
      iVar4 = *(int *)(param_1 + 0x1734);
      iVar7 = iVar4 + 3;
      uVar2 = uVar5 << ((byte)iVar4 & 0x1f) | *(ushort *)(param_1 + 0x1730);
      if (0xd < iVar4) {
        lVar1 = *(long *)(param_1 + 0x28);
        *(ushort *)(param_1 + 0x1730) = uVar2;
        *(long *)(param_1 + 0x28) = lVar1 + 1;
        *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)uVar2;
        lVar1 = *(long *)(param_1 + 0x28);
        *(long *)(param_1 + 0x28) = lVar1 + 1;
        *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar1) = *(undefined1 *)(param_1 + 0x1731);
        iVar7 = *(int *)(param_1 + 0x1734) + -0xd;
        uVar2 = (ushort)((int)(uint)uVar5 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f));
      }
      *(ushort *)(param_1 + 0x1730) = uVar2;
      *(int *)(param_1 + 0x1734) = iVar7;
      if (pbVar8 == &DAT_00110901 + (param_4 - 1)) break;
      uVar3 = (ulong)*pbVar8;
      pbVar8 = pbVar8 + 1;
    }
  }
  FUN_0010bb60(param_1,param_1 + 0xd4,param_2 + -1);
  FUN_0010bb60(param_1,param_1 + 0x9c8,param_3 - 1U);
  return;
}



// Function: compress_block @ 0xc380

void compress_block(long param_1,long param_2,long param_3)

{
  byte *pbVar1;
  ushort *puVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  ushort uVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined2 uVar12;
  int iVar13;
  uint uVar14;
  ulong uVar15;
  ulong uVar16;
  uint uVar17;
  
  uVar17 = (uint)*(ushort *)(param_1 + 0x1730);
  iVar13 = *(int *)(param_1 + 0x1734);
  if (*(int *)(param_1 + 0x170c) != 0) {
    uVar15 = 0;
    do {
      while( true ) {
        lVar7 = *(long *)(param_1 + 0x1700);
        iVar9 = (int)uVar15;
        pbVar1 = (byte *)(lVar7 + uVar15);
        bVar3 = *(byte *)(lVar7 + (ulong)(iVar9 + 2));
        uVar14 = iVar9 + 3;
        uVar15 = (ulong)uVar14;
        iVar9 = (uint)*(byte *)(lVar7 + (ulong)(iVar9 + 1)) * 0x100 + (uint)*pbVar1;
        if (iVar9 != 0) break;
        puVar2 = (ushort *)(param_2 + (ulong)bVar3 * 4);
        uVar5 = puVar2[1];
        uVar10 = (uint)*puVar2;
        uVar17 = uVar17 | uVar10 << ((byte)iVar13 & 0x1f);
        *(short *)(param_1 + 0x1730) = (short)uVar17;
        if ((int)(0x10 - (uint)uVar5) < iVar13) {
          lVar7 = *(long *)(param_1 + 0x28);
          *(long *)(param_1 + 0x28) = lVar7 + 1;
          *(char *)(*(long *)(param_1 + 0x10) + lVar7) = (char)uVar17;
          lVar7 = *(long *)(param_1 + 0x28);
          *(long *)(param_1 + 0x28) = lVar7 + 1;
          *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar7) = *(undefined1 *)(param_1 + 0x1731);
          iVar13 = *(int *)(param_1 + 0x1734) + -0x10 + (uint)uVar5;
          uVar17 = (int)uVar10 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
          *(int *)(param_1 + 0x1734) = iVar13;
          *(short *)(param_1 + 0x1730) = (short)uVar17;
        }
        else {
          iVar13 = iVar13 + (uint)uVar5;
          *(int *)(param_1 + 0x1734) = iVar13;
        }
LAB_0010c441:
        if (*(uint *)(param_1 + 0x170c) <= uVar14) goto LAB_0010c6c0;
      }
      bVar4 = (&DAT_00110100)[bVar3];
      puVar2 = (ushort *)(param_2 + (ulong)(bVar4 + 0x101) * 4);
      uVar10 = (uint)puVar2[1];
      uVar11 = (uint)*puVar2;
      uVar17 = uVar11 << ((byte)iVar13 & 0x1f) | uVar17;
      if ((int)(0x10 - uVar10) < iVar13) {
        lVar7 = *(long *)(param_1 + 0x28);
        *(short *)(param_1 + 0x1730) = (short)uVar17;
        *(long *)(param_1 + 0x28) = lVar7 + 1;
        *(char *)(*(long *)(param_1 + 0x10) + lVar7) = (char)uVar17;
        lVar7 = *(long *)(param_1 + 0x28);
        *(long *)(param_1 + 0x28) = lVar7 + 1;
        *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar7) = *(undefined1 *)(param_1 + 0x1731);
        uVar17 = (int)uVar11 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
        iVar13 = *(int *)(param_1 + 0x1734) + -0x10;
      }
      iVar8 = uVar10 + iVar13;
      *(int *)(param_1 + 0x1734) = iVar8;
      iVar13 = *(int *)(&DAT_00110a00 + (ulong)bVar4 * 4);
      if (iVar13 != 0) {
        uVar10 = (uint)bVar3 - *(int *)(&DAT_00110080 + (ulong)bVar4 * 4) & 0xffff;
        uVar17 = uVar17 | uVar10 << ((byte)iVar8 & 0x1f);
        if (0x10 - iVar13 < iVar8) {
          lVar7 = *(long *)(param_1 + 0x28);
          *(short *)(param_1 + 0x1730) = (short)uVar17;
          *(long *)(param_1 + 0x28) = lVar7 + 1;
          *(char *)(*(long *)(param_1 + 0x10) + lVar7) = (char)uVar17;
          lVar7 = *(long *)(param_1 + 0x28);
          *(long *)(param_1 + 0x28) = lVar7 + 1;
          *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar7) = *(undefined1 *)(param_1 + 0x1731);
          uVar17 = (int)uVar10 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
          iVar8 = *(int *)(param_1 + 0x1734) + -0x10 + iVar13;
          *(int *)(param_1 + 0x1734) = iVar8;
        }
        else {
          iVar8 = iVar8 + iVar13;
          *(int *)(param_1 + 0x1734) = iVar8;
        }
      }
      uVar10 = iVar9 - 1;
      if (uVar10 < 0x100) {
        bVar3 = (&DAT_00110200)[uVar10];
      }
      else {
        bVar3 = (&DAT_00110200)[(uVar10 >> 7) + 0x100];
      }
      uVar16 = (ulong)bVar3;
      puVar2 = (ushort *)(param_3 + uVar16 * 4);
      uVar5 = puVar2[1];
      uVar11 = (uint)*puVar2;
      iVar13 = (uint)uVar5 + iVar8;
      uVar17 = uVar11 << ((byte)iVar8 & 0x1f) | uVar17;
      if ((int)(0x10 - (uint)uVar5) < iVar8) {
        lVar7 = *(long *)(param_1 + 0x28);
        *(short *)(param_1 + 0x1730) = (short)uVar17;
        *(long *)(param_1 + 0x28) = lVar7 + 1;
        *(char *)(*(long *)(param_1 + 0x10) + lVar7) = (char)uVar17;
        lVar7 = *(long *)(param_1 + 0x28);
        *(long *)(param_1 + 0x28) = lVar7 + 1;
        *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar7) = *(undefined1 *)(param_1 + 0x1731);
        iVar13 = *(int *)(param_1 + 0x1734) + -0x10 + (uint)uVar5;
        uVar17 = (int)uVar11 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
      }
      *(short *)(param_1 + 0x1730) = (short)uVar17;
      iVar9 = *(int *)(&DAT_00110980 + uVar16 * 4);
      *(int *)(param_1 + 0x1734) = iVar13;
      if (iVar9 == 0) goto LAB_0010c441;
      uVar10 = uVar10 - *(int *)(&DAT_00110000 + uVar16 * 4) & 0xffff;
      uVar17 = uVar17 | uVar10 << ((byte)iVar13 & 0x1f);
      *(short *)(param_1 + 0x1730) = (short)uVar17;
      if (iVar13 <= 0x10 - iVar9) {
        iVar13 = iVar13 + iVar9;
        *(int *)(param_1 + 0x1734) = iVar13;
        goto LAB_0010c441;
      }
      lVar7 = *(long *)(param_1 + 0x28);
      *(long *)(param_1 + 0x28) = lVar7 + 1;
      *(char *)(*(long *)(param_1 + 0x10) + lVar7) = (char)uVar17;
      lVar7 = *(long *)(param_1 + 0x28);
      *(long *)(param_1 + 0x28) = lVar7 + 1;
      *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar7) = *(undefined1 *)(param_1 + 0x1731);
      iVar13 = *(int *)(param_1 + 0x1734) + -0x10 + iVar9;
      uVar17 = (int)uVar10 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f);
      *(int *)(param_1 + 0x1734) = iVar13;
      *(short *)(param_1 + 0x1730) = (short)uVar17;
    } while (uVar14 < *(uint *)(param_1 + 0x170c));
  }
LAB_0010c6c0:
  uVar5 = *(ushort *)(param_2 + 0x400);
  uVar6 = *(ushort *)(param_2 + 0x402);
  uVar17 = uVar17 | (uint)uVar5 << ((byte)iVar13 & 0x1f);
  uVar12 = (undefined2)uVar17;
  if ((int)(0x10 - (uint)uVar6) < iVar13) {
    lVar7 = *(long *)(param_1 + 0x28);
    *(undefined2 *)(param_1 + 0x1730) = uVar12;
    *(long *)(param_1 + 0x28) = lVar7 + 1;
    *(char *)(*(long *)(param_1 + 0x10) + lVar7) = (char)uVar17;
    lVar7 = *(long *)(param_1 + 0x28);
    *(long *)(param_1 + 0x28) = lVar7 + 1;
    *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar7) = *(undefined1 *)(param_1 + 0x1731);
    iVar13 = *(int *)(param_1 + 0x1734) + -0x10;
    uVar12 = (undefined2)((int)(uint)uVar5 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f));
  }
  *(undefined2 *)(param_1 + 0x1730) = uVar12;
  *(uint *)(param_1 + 0x1734) = (uint)uVar6 + iVar13;
  return;
}



// Function: detect_data_type @ 0xc7a0

undefined8 detect_data_type(long param_1)

{
  short *psVar1;
  ulong uVar2;
  
  psVar1 = (short *)(param_1 + 0xd4);
  uVar2 = 0xf3ffc07f;
  while (((uVar2 & 1) == 0 || (*psVar1 == 0))) {
    psVar1 = psVar1 + 2;
    uVar2 = uVar2 >> 1;
    if (psVar1 == (short *)(param_1 + 0x154)) {
      if (((*(ulong *)(param_1 + 0xf8) & 0xffff0000ffff) == 0) && (*(short *)(param_1 + 0x108) == 0)
         ) {
        while (*psVar1 == 0) {
          psVar1 = psVar1 + 2;
          if ((short *)(param_1 + 0x4d4) == psVar1) {
            return 0;
          }
        }
      }
      return 1;
    }
  }
  return 0;
}



// Function: bi_reverse @ 0xc830

uint bi_reverse(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  do {
    uVar3 = uVar1;
    param_2 = param_2 + -1;
    uVar2 = param_1 & 1;
    param_1 = param_1 >> 1;
    uVar1 = (uVar2 | uVar3) * 2;
  } while (0 < param_2);
  return uVar2 | uVar3 & 0x7fffffff;
}



// Function: gen_codes @ 0xc860

void gen_codes(undefined2 *param_1,int param_2,long param_3)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  long lVar4;
  undefined2 *puVar5;
  long in_FS_OFFSET;
  short asStack_38 [20];
  long local_10;
  
  lVar4 = 0;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  sVar2 = 0;
  do {
    sVar2 = (sVar2 + *(short *)(param_3 + lVar4)) * 2;
    *(short *)((long)asStack_38 + lVar4 + 2) = sVar2;
    lVar4 = lVar4 + 2;
  } while (lVar4 != 0x1e);
  if (-1 < param_2) {
    puVar5 = param_1 + (long)param_2 * 2 + 2;
    do {
      uVar1 = param_1[1];
      if (uVar1 != 0) {
        asStack_38[(int)(uint)uVar1] = asStack_38[(int)(uint)uVar1] + 1;
        uVar3 = FUN_0010c830();
        *param_1 = uVar3;
      }
      param_1 = param_1 + 2;
    } while (puVar5 != param_1);
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: build_tree @ 0xc900

void build_tree(long param_1,undefined8 *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined2 *puVar13;
  long lVar14;
  int local_4c;
  
  puVar5 = (undefined2 *)*param_2;
  iVar3 = *(int *)((long)param_2[2] + 0x14);
  lVar14 = *(long *)param_2[2];
  *(undefined8 *)(param_1 + 0x14b4) = 0x23d00000000;
  if (iVar3 < 1) {
    local_4c = -1;
    iVar6 = 0;
  }
  else {
    local_4c = -1;
    lVar10 = 0;
    iVar6 = 0;
    do {
      while (puVar5[lVar10 * 2] == 0) {
        puVar5[lVar10 * 2 + 1] = 0;
        lVar10 = lVar10 + 1;
        if (lVar10 == iVar3) goto LAB_0010c992;
      }
      iVar6 = iVar6 + 1;
      local_4c = (int)lVar10;
      *(int *)(param_1 + 0x14b4) = iVar6;
      *(int *)(param_1 + 0xbc0 + (long)iVar6 * 4) = local_4c;
      *(undefined1 *)(param_1 + 0x14bc + lVar10) = 0;
      lVar10 = lVar10 + 1;
    } while (lVar10 != iVar3);
LAB_0010c992:
    if (1 < iVar6) goto LAB_0010ca3e;
  }
  lVar10 = *(long *)(param_1 + 0x1718);
  lVar11 = (long)(iVar6 + 1);
  do {
    if (local_4c < 2) {
      iVar7 = local_4c + 1;
      lVar12 = (long)iVar7 * 4;
      puVar13 = puVar5 + (long)iVar7 * 2;
      local_4c = iVar7;
    }
    else {
      lVar12 = 0;
      iVar7 = 0;
      puVar13 = puVar5;
    }
    iVar9 = (int)lVar11;
    *(int *)(param_1 + 0x14b4) = iVar9;
    *(int *)(param_1 + 0xbc0 + lVar11 * 4) = iVar7;
    *puVar13 = 1;
    *(undefined1 *)(param_1 + 0x14bc + (long)iVar7) = 0;
    *(long *)(param_1 + 0x1718) = (iVar6 + lVar10) - lVar11;
    if (lVar14 != 0) {
      *(long *)(param_1 + 0x1720) =
           *(long *)(param_1 + 0x1720) - (ulong)*(ushort *)(lVar14 + 2 + lVar12);
    }
    lVar11 = lVar11 + 1;
  } while (iVar9 < 2);
  iVar7 = 1 - iVar6;
  if (1 < iVar6) {
    iVar7 = 0;
  }
  iVar6 = iVar7 + iVar6 + 1;
LAB_0010ca3e:
  lVar14 = (long)iVar3;
  iVar6 = iVar6 >> 1;
  *(int *)(param_2 + 1) = local_4c;
  do {
    FUN_0010b700(param_1,puVar5,iVar6);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = *(int *)(param_1 + 0x14b4) + -1;
  lVar10 = (long)iVar6;
  do {
    *(int *)(param_1 + 0x14b4) = (int)lVar10;
    iVar7 = *(int *)(param_1 + 0xbc4);
    *(undefined4 *)(param_1 + 0xbc4) = *(undefined4 *)(param_1 + 0xbc4 + lVar10 * 4);
    FUN_0010b700(param_1,puVar5,1);
    iVar9 = *(int *)(param_1 + 0x14b8);
    iVar4 = *(int *)(param_1 + 0xbc4);
    lVar11 = param_1 + (long)iVar9 * 4;
    *(int *)(lVar11 + 0xbbc) = iVar7;
    *(int *)(param_1 + 0x14b8) = iVar9 + -2;
    *(int *)(lVar11 + 3000) = iVar4;
    puVar5[lVar14 * 2] = puVar5[(long)iVar4 * 2] + puVar5[(long)iVar7 * 2];
    bVar1 = *(byte *)(param_1 + 0x14bc + (long)iVar7);
    bVar2 = *(byte *)(param_1 + 0x14bc + (long)iVar4);
    if (bVar2 <= bVar1) {
      bVar2 = bVar1;
    }
    *(byte *)(param_1 + 0x14bc + lVar14) = bVar2 + 1;
    sVar8 = ((short)iVar6 + (short)iVar3) - (short)lVar10;
    lVar10 = lVar10 + -1;
    (puVar5 + (long)iVar4 * 2)[1] = sVar8;
    (puVar5 + (long)iVar7 * 2)[1] = sVar8;
    *(int *)(param_1 + 0xbc4) = (int)lVar14;
    lVar14 = lVar14 + 1;
    FUN_0010b700(param_1,puVar5,1);
  } while (1 < (int)lVar10 + 1);
  *(int *)(param_1 + 0x14b8) = iVar9 + -3;
  *(undefined4 *)(lVar11 + 0xbb4) = *(undefined4 *)(param_1 + 0xbc4);
  FUN_0010b7f0(param_1,param_2);
  FUN_0010c860(puVar5,local_4c,param_1 + 0xba0);
  return;
}



// Function: build_bl_tree @ 0xcbc0

ulong build_bl_tree(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  
  FUN_0010ba40(param_1,param_1 + 0xd4,*(undefined4 *)(param_1 + 0xb60));
  FUN_0010ba40(param_1,param_1 + 0x9c8,*(undefined4 *)(param_1 + 0xb78));
  FUN_0010c900(param_1,param_1 + 0xb88);
  uVar2 = 0xf;
  uVar1 = 0x12;
  do {
    uVar4 = uVar1 & 0xffffffff;
    if (*(short *)(param_1 + 0xabe + uVar2 * 4) != 0) {
      lVar3 = (long)((int)uVar1 + 1) * 3;
LAB_0010cc37:
      *(long *)(param_1 + 0x1718) = lVar3 + 0xe + *(long *)(param_1 + 0x1718);
      return uVar4;
    }
    if (uVar1 - 1 == 2) {
      lVar3 = 9;
      uVar4 = 2;
      goto LAB_0010cc37;
    }
    uVar2 = (ulong)(byte)(&UNK_001108ff)[uVar1];
    uVar1 = uVar1 - 1;
  } while( true );
}



// Function: bi_flush @ 0xcc60

void bi_flush(long param_1)

{
  long lVar1;
  
  if (*(int *)(param_1 + 0x1734) != 0x10) {
    if (7 < *(int *)(param_1 + 0x1734)) {
      lVar1 = *(long *)(param_1 + 0x28);
      *(long *)(param_1 + 0x28) = lVar1 + 1;
      *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)*(undefined2 *)(param_1 + 0x1730);
      *(int *)(param_1 + 0x1734) = *(int *)(param_1 + 0x1734) + -8;
      *(ushort *)(param_1 + 0x1730) = *(ushort *)(param_1 + 0x1730) >> 8;
    }
    return;
  }
  lVar1 = *(long *)(param_1 + 0x28);
  *(long *)(param_1 + 0x28) = lVar1 + 1;
  *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)*(undefined2 *)(param_1 + 0x1730);
  lVar1 = *(long *)(param_1 + 0x28);
  *(long *)(param_1 + 0x28) = lVar1 + 1;
  *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar1) = *(undefined1 *)(param_1 + 0x1731);
  *(undefined2 *)(param_1 + 0x1730) = 0;
  *(undefined4 *)(param_1 + 0x1734) = 0;
  return;
}



// Function: bi_windup @ 0xccf0

void bi_windup(long param_1)

{
  long lVar1;
  undefined1 uVar2;
  
  if (*(int *)(param_1 + 0x1734) < 9) {
    if (*(int *)(param_1 + 0x1734) < 1) goto LAB_0010cd2f;
    uVar2 = (undefined1)*(undefined2 *)(param_1 + 0x1730);
  }
  else {
    lVar1 = *(long *)(param_1 + 0x28);
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)*(undefined2 *)(param_1 + 0x1730);
    uVar2 = *(undefined1 *)(param_1 + 0x1731);
  }
  lVar1 = *(long *)(param_1 + 0x28);
  *(long *)(param_1 + 0x28) = lVar1 + 1;
  *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar1) = uVar2;
LAB_0010cd2f:
  *(undefined4 *)(param_1 + 0x1734) = 0;
  *(undefined2 *)(param_1 + 0x1730) = 0;
  return;
}



// Function: _tr_init @ 0xcd60

void _tr_init(long param_1)

{
  *(undefined4 *)(param_1 + 0x1734) = 0;
  *(long *)(param_1 + 0xb58) = param_1 + 0xd4;
  *(undefined ***)(param_1 + 0xb68) = &PTR_DAT_00116c60;
  *(long *)(param_1 + 0xb70) = param_1 + 0x9c8;
  *(undefined ***)(param_1 + 0xb80) = &PTR_DAT_00116c40;
  *(long *)(param_1 + 0xb88) = param_1 + 0xabc;
  *(undefined **)(param_1 + 0xb98) = &DAT_00116c20;
  *(undefined2 *)(param_1 + 0x1730) = 0;
  FUN_0010b660();
  return;
}



// Function: _tr_stored_block @ 0xcdd0

void _tr_stored_block(long param_1,void *param_2,size_t param_3,uint param_4)

{
  int iVar1;
  long lVar2;
  ushort uVar3;
  byte bVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0x1734);
  iVar5 = iVar1 + 3;
  uVar3 = (ushort)((param_4 & 0xffff) << ((byte)iVar1 & 0x1f)) | *(ushort *)(param_1 + 0x1730);
  if (0xd < iVar1) {
    lVar2 = *(long *)(param_1 + 0x28);
    *(ushort *)(param_1 + 0x1730) = uVar3;
    *(long *)(param_1 + 0x28) = lVar2 + 1;
    *(char *)(*(long *)(param_1 + 0x10) + lVar2) = (char)uVar3;
    lVar2 = *(long *)(param_1 + 0x28);
    *(long *)(param_1 + 0x28) = lVar2 + 1;
    *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar2) = *(undefined1 *)(param_1 + 0x1731);
    iVar5 = *(int *)(param_1 + 0x1734) + -0xd;
    uVar3 = (ushort)((int)(param_4 & 0xffff) >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f));
  }
  *(ushort *)(param_1 + 0x1730) = uVar3;
  *(int *)(param_1 + 0x1734) = iVar5;
  FUN_0010ccf0(param_1);
  lVar2 = *(long *)(param_1 + 0x28);
  *(long *)(param_1 + 0x28) = lVar2 + 1;
  *(byte *)(*(long *)(param_1 + 0x10) + lVar2) = (byte)param_3;
  lVar2 = *(long *)(param_1 + 0x28);
  *(long *)(param_1 + 0x28) = lVar2 + 1;
  bVar4 = (byte)(param_3 >> 8);
  *(byte *)(*(long *)(param_1 + 0x10) + lVar2) = bVar4;
  lVar2 = *(long *)(param_1 + 0x28);
  *(long *)(param_1 + 0x28) = lVar2 + 1;
  *(byte *)(*(long *)(param_1 + 0x10) + lVar2) = ~(byte)param_3;
  lVar2 = *(long *)(param_1 + 0x28);
  *(long *)(param_1 + 0x28) = lVar2 + 1;
  *(byte *)(*(long *)(param_1 + 0x10) + lVar2) = ~bVar4;
  if (param_3 == 0) {
    *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)(param_1 + 0x28);
    return;
  }
  memcpy((void *)(*(long *)(param_1 + 0x28) + *(long *)(param_1 + 0x10)),param_2,param_3);
  *(long *)(param_1 + 0x28) = *(long *)(param_1 + 0x28) + param_3;
  return;
}



// Function: _tr_align @ 0xcf00

void _tr_align(long param_1)

{
  long lVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x1734);
  iVar4 = iVar3 + 3;
  uVar2 = (ushort)(2 << ((byte)iVar3 & 0x1f)) | *(ushort *)(param_1 + 0x1730);
  if (0xd < iVar3) {
    lVar1 = *(long *)(param_1 + 0x28);
    *(ushort *)(param_1 + 0x1730) = uVar2;
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)uVar2;
    lVar1 = *(long *)(param_1 + 0x28);
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar1) = *(undefined1 *)(param_1 + 0x1731);
    iVar4 = *(int *)(param_1 + 0x1734) + -0xd;
    uVar2 = (ushort)(2 >> (0x10U - (char)*(int *)(param_1 + 0x1734) & 0x1f));
  }
  *(ushort *)(param_1 + 0x1730) = uVar2;
  iVar3 = iVar4 + 7;
  *(int *)(param_1 + 0x1734) = iVar4;
  if (9 < iVar4) {
    lVar1 = *(long *)(param_1 + 0x28);
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(char *)(*(long *)(param_1 + 0x10) + lVar1) = (char)uVar2;
    lVar1 = *(long *)(param_1 + 0x28);
    *(long *)(param_1 + 0x28) = lVar1 + 1;
    *(undefined1 *)(*(long *)(param_1 + 0x10) + lVar1) = *(undefined1 *)(param_1 + 0x1731);
    *(undefined2 *)(param_1 + 0x1730) = 0;
    iVar3 = *(int *)(param_1 + 0x1734) + -9;
  }
  *(int *)(param_1 + 0x1734) = iVar3;
  FUN_0010cc60();
  return;
}



// Function: _tr_flush_block @ 0xcfd0

void _tr_flush_block(long *param_1,long param_2,long param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  
  if (*(int *)((long)param_1 + 0xc4) < 1) {
    if (param_3 + 4U <= param_3 + 5U) {
LAB_0010d05d:
      if (param_2 != 0) goto LAB_0010d066;
    }
LAB_0010d1a2:
    iVar1 = *(int *)((long)param_1 + 0x1734);
    uVar8 = param_4 + 2U & 0xffff;
    if (iVar1 < 0xe) {
      iVar5 = iVar1 + 3;
      uVar7 = (ushort)(uVar8 << ((byte)iVar1 & 0x1f)) | *(ushort *)(param_1 + 0x2e6);
    }
    else {
      lVar10 = param_1[5];
      uVar3 = (uint)*(ushort *)(param_1 + 0x2e6) | uVar8 << ((byte)iVar1 & 0x1f);
      *(short *)(param_1 + 0x2e6) = (short)uVar3;
      param_1[5] = lVar10 + 1;
      *(char *)(param_1[2] + lVar10) = (char)uVar3;
      lVar10 = param_1[5];
      param_1[5] = lVar10 + 1;
      *(undefined1 *)(param_1[2] + lVar10) = *(undefined1 *)((long)param_1 + 0x1731);
      uVar7 = (ushort)((int)uVar8 >> (0x10U - (char)*(int *)((long)param_1 + 0x1734) & 0x1f));
      iVar5 = *(int *)((long)param_1 + 0x1734) + -0xd;
    }
    *(int *)((long)param_1 + 0x1734) = iVar5;
    *(ushort *)(param_1 + 0x2e6) = uVar7;
    FUN_0010c380(param_1,&DAT_00110480,&DAT_00110400);
  }
  else {
    lVar10 = *param_1;
    if (*(int *)(lVar10 + 0x58) == 2) {
      uVar2 = FUN_0010c7a0();
      *(undefined4 *)(lVar10 + 0x58) = uVar2;
    }
    FUN_0010c900(param_1,param_1 + 0x16b);
    FUN_0010c900(param_1,param_1 + 0x16e);
    iVar1 = FUN_0010cbc0(param_1);
    uVar9 = param_1[0x2e3] + 10U >> 3;
    uVar4 = param_1[0x2e4] + 10U >> 3;
    if ((uVar4 <= uVar9) || ((int)param_1[0x19] == 4)) {
      if (param_3 + 4U <= uVar4) goto LAB_0010d05d;
      goto LAB_0010d1a2;
    }
    if ((uVar9 < param_3 + 4U) || (param_2 == 0)) {
      iVar5 = *(int *)((long)param_1 + 0x1734);
      uVar8 = param_4 + 4U & 0xffff;
      if (iVar5 < 0xe) {
        iVar6 = iVar5 + 3;
        uVar7 = (ushort)(uVar8 << ((byte)iVar5 & 0x1f)) | *(ushort *)(param_1 + 0x2e6);
      }
      else {
        lVar10 = param_1[5];
        uVar3 = (uint)*(ushort *)(param_1 + 0x2e6) | uVar8 << ((byte)iVar5 & 0x1f);
        *(short *)(param_1 + 0x2e6) = (short)uVar3;
        param_1[5] = lVar10 + 1;
        *(char *)(param_1[2] + lVar10) = (char)uVar3;
        lVar10 = param_1[5];
        param_1[5] = lVar10 + 1;
        *(undefined1 *)(param_1[2] + lVar10) = *(undefined1 *)((long)param_1 + 0x1731);
        uVar7 = (ushort)((int)uVar8 >> (0x10U - (char)*(int *)((long)param_1 + 0x1734) & 0x1f));
        iVar6 = *(int *)((long)param_1 + 0x1734) + -0xd;
      }
      *(ushort *)(param_1 + 0x2e6) = uVar7;
      *(int *)((long)param_1 + 0x1734) = iVar6;
      FUN_0010c100(param_1,(int)param_1[0x16c] + 1,(int)param_1[0x16f] + 1,iVar1 + 1);
      FUN_0010c380(param_1,(long)param_1 + 0xd4,param_1 + 0x139);
      FUN_0010b660(param_1);
      goto joined_r0x0010d163;
    }
LAB_0010d066:
    FUN_0010cdd0(param_1,param_2,param_3,param_4);
  }
  FUN_0010b660(param_1);
joined_r0x0010d163:
  if (param_4 == 0) {
    return;
  }
  FUN_0010ccf0();
  return;
}



// Function: _tr_tally @ 0xd250

bool _tr_tally(long param_1,int param_2,uint param_3)

{
  short *psVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x170c);
  *(uint *)(param_1 + 0x170c) = uVar2 + 1;
  *(char *)(*(long *)(param_1 + 0x1700) + (ulong)uVar2) = (char)param_2;
  uVar2 = *(uint *)(param_1 + 0x170c);
  *(uint *)(param_1 + 0x170c) = uVar2 + 1;
  *(char *)(*(long *)(param_1 + 0x1700) + (ulong)uVar2) = (char)((uint)param_2 >> 8);
  uVar2 = *(uint *)(param_1 + 0x170c);
  *(uint *)(param_1 + 0x170c) = uVar2 + 1;
  *(char *)(*(long *)(param_1 + 0x1700) + (ulong)uVar2) = (char)param_3;
  if (param_2 == 0) {
    psVar1 = (short *)(param_1 + 0xd4 + (ulong)param_3 * 4);
    *psVar1 = *psVar1 + 1;
  }
  else {
    uVar2 = param_2 - 1;
    *(int *)(param_1 + 0x1728) = *(int *)(param_1 + 0x1728) + 1;
    psVar1 = (short *)(param_1 + 0x4d8 + (ulong)(byte)(&DAT_00110100)[param_3] * 4);
    *psVar1 = *psVar1 + 1;
    if (0xff < uVar2) {
      uVar2 = (uVar2 >> 7) + 0x100;
    }
    psVar1 = (short *)(param_1 + 0x9c8 + (ulong)(byte)(&DAT_00110200)[uVar2] * 4);
    *psVar1 = *psVar1 + 1;
  }
  return *(int *)(param_1 + 0x170c) == *(int *)(param_1 + 0x1710);
}



// Function: zlibVersion @ 0xd320

char * zlibVersion(void)

{
  return "1.2.13";
}



// Function: zlibCompileFlags @ 0xd330

undefined8 zlibCompileFlags(void)

{
  return 0xa9;
}



// Function: zError @ 0xd340

undefined * zError(int param_1)

{
  return (&PTR_s_need_dictionary_00116c80)[2 - param_1];
}



// Function: zcalloc @ 0xd360

void zcalloc(undefined8 param_1,int param_2,int param_3)

{
  malloc((ulong)(uint)(param_2 * param_3));
  return;
}



// Function: zcfree @ 0xd370

void zcfree(undefined8 param_1,void *param_2)

{
  free(param_2);
  return;
}



// Function: adler32_combine_ @ 0xd380

ulong adler32_combine_(ulong param_1,ulong param_2,long param_3)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  
  uVar1 = 0xffffffff;
  if (-1 < param_3) {
    lVar3 = (((param_1 >> 0x10 & 0xffff) + (param_2 >> 0x10 & 0xffff)) - param_3 % 0xfff1) +
            ((param_3 % 0xfff1) * (param_1 & 0xffff)) % 0xfff1;
    uVar2 = lVar3 + 0xfff1;
    lVar4 = (param_2 & 0xffff) + (param_1 & 0xffff);
    uVar1 = 0xfff0;
    if (lVar4 != 0) {
      uVar1 = lVar4 - 1U;
      if (0xfff0 < lVar4 - 1U) {
        uVar1 = lVar4 - 0xfff2;
      }
    }
    if (0x1ffe1 < uVar2) {
      uVar2 = lVar3 - 0xfff1;
    }
    if (0xfff0 < uVar2) {
      uVar2 = uVar2 - 0xfff1;
    }
    uVar1 = uVar2 << 0x10 | uVar1;
  }
  return uVar1;
}



// Function: adler32_z @ 0xd470

ulong adler32_z(ulong param_1,byte *param_2,ulong param_3)

{
  byte bVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  ulong uVar4;
  long lVar5;
  long lVar6;
  byte *pbVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  byte *pbVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  ulong uVar22;
  ulong local_50;
  byte *local_48;
  ulong local_40;
  
  uVar22 = param_1 & 0xffff;
  local_50 = param_1 >> 0x10 & 0xffff;
  if (param_3 == 1) {
    uVar22 = *param_2 + uVar22;
    if (0xfff0 < uVar22) {
      uVar22 = uVar22 - 0xfff1;
    }
    local_50 = local_50 + uVar22;
    if (0xfff0 < local_50) {
      local_50 = local_50 - 0xfff1;
    }
    return local_50 << 0x10 | uVar22;
  }
  if (param_2 == (byte *)0x0) {
    return 1;
  }
  if (param_3 < 0x10) {
    if (param_3 != 0) {
      pbVar7 = param_2 + param_3;
      do {
        bVar1 = *param_2;
        param_2 = param_2 + 1;
        uVar22 = uVar22 + bVar1;
        local_50 = local_50 + uVar22;
      } while (param_2 != pbVar7);
    }
    if (0xfff0 < uVar22) {
      uVar22 = uVar22 - 0xfff1;
    }
    return (local_50 % 0xfff1) * 0x10000 | uVar22;
  }
  pbVar7 = param_2 + 0x15b0;
  uVar4 = param_3;
  if (param_3 < 0x15b0) {
LAB_0010d734:
    local_40 = uVar4;
    uVar4 = local_40 - 0x10 >> 4;
    pbVar13 = param_2 + (uVar4 + 1) * 0x10;
    do {
      pbVar7 = param_2 + 0x10;
      lVar5 = *param_2 + uVar22;
      lVar21 = (ulong)param_2[1] + lVar5;
      lVar20 = (ulong)param_2[2] + lVar21;
      lVar19 = (ulong)param_2[3] + lVar20;
      lVar11 = (ulong)param_2[4] + lVar19;
      lVar9 = (ulong)param_2[5] + lVar11;
      lVar18 = (ulong)param_2[6] + lVar9;
      lVar17 = (ulong)param_2[7] + lVar18;
      lVar16 = (ulong)param_2[8] + lVar17;
      lVar15 = (ulong)param_2[9] + lVar16;
      lVar10 = (ulong)param_2[10] + lVar15;
      lVar6 = (ulong)param_2[0xb] + lVar10;
      lVar14 = (ulong)param_2[0xc] + lVar6;
      lVar12 = (ulong)param_2[0xd] + lVar14;
      lVar8 = (ulong)param_2[0xe] + lVar12;
      uVar22 = (ulong)param_2[0xf] + lVar8;
      local_50 = local_50 +
                 lVar5 + lVar21 + lVar20 + lVar19 + lVar11 + lVar9 + lVar18 + lVar17 + lVar16 +
                 lVar15 + lVar10 + lVar6 + lVar14 + lVar12 + lVar8 + uVar22;
      param_2 = pbVar7;
    } while (pbVar7 != pbVar13);
    lVar10 = (local_40 - 0x11) + uVar4 * -0x10;
    if ((local_40 & 0xf) != 0) goto LAB_0010d83e;
  }
  else {
    do {
      local_40 = uVar4;
      local_48 = pbVar7;
      uVar4 = local_40 - 0x15b0;
      pbVar13 = local_48 + -0x15b0;
      do {
        pbVar7 = pbVar13;
        pbVar13 = pbVar7 + 0x10;
        lVar5 = *pbVar7 + uVar22;
        lVar21 = (ulong)pbVar7[1] + lVar5;
        lVar20 = (ulong)pbVar7[2] + lVar21;
        lVar19 = (ulong)pbVar7[3] + lVar20;
        lVar12 = (ulong)pbVar7[4] + lVar19;
        lVar11 = (ulong)pbVar7[5] + lVar12;
        lVar18 = (ulong)pbVar7[6] + lVar11;
        lVar10 = (ulong)pbVar7[7] + lVar18;
        lVar8 = (ulong)pbVar7[8] + lVar10;
        lVar17 = (ulong)pbVar7[9] + lVar8;
        lVar16 = (ulong)pbVar7[10] + lVar17;
        lVar15 = (ulong)pbVar7[0xb] + lVar16;
        lVar14 = (ulong)pbVar7[0xc] + lVar15;
        lVar6 = (ulong)pbVar7[0xd] + lVar14;
        lVar9 = (ulong)pbVar7[0xe] + lVar6;
        uVar22 = (ulong)pbVar7[0xf] + lVar9;
        local_50 = local_50 +
                   lVar5 + lVar21 + lVar20 + lVar19 + lVar12 + lVar11 + lVar18 + lVar10 + lVar8 +
                   lVar17 + lVar16 + lVar15 + lVar14 + lVar6 + lVar9 + uVar22;
      } while (pbVar13 != local_48);
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uVar22;
      lVar10 = SUB168(ZEXT816(0xf00e10d2fc5cd) * auVar2,8);
      uVar22 = uVar22 + (lVar10 + (uVar22 - lVar10 >> 1) >> 0xf) * -0xfff1;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = local_50;
      lVar10 = SUB168(ZEXT816(0xf00e10d2fc5cd) * auVar3,8);
      local_50 = local_50 + (lVar10 + (local_50 - lVar10 >> 1) >> 0xf) * -0xfff1;
      pbVar7 = pbVar7 + 0x15c0;
    } while (0x15af < uVar4);
    if (uVar4 == 0) goto LAB_0010d649;
    param_2 = local_48;
    if (0xf < uVar4) goto LAB_0010d734;
    lVar10 = local_40 - 0x15b1;
LAB_0010d83e:
    pbVar7 = pbVar13 + lVar10 + 1;
    do {
      bVar1 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      uVar22 = uVar22 + bVar1;
      local_50 = local_50 + uVar22;
    } while (pbVar13 != pbVar7);
  }
  uVar22 = uVar22 % 0xfff1;
  local_50 = local_50 % 0xfff1;
LAB_0010d649:
  return local_50 << 0x10 | uVar22;
}



// Function: adler32 @ 0xd8e0

void adler32(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_0010d470(param_1,param_2,param_3);
  return;
}



// Function: multmodp @ 0xd910

uint multmodp(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = 0x80000000;
  do {
    if ((uVar1 & param_1) != 0) {
      uVar4 = uVar4 ^ param_2;
      if ((uVar1 - 1 & param_1) == 0) {
        return uVar4;
      }
    }
    uVar3 = param_2 >> 1;
    uVar2 = param_2 & 1;
    uVar1 = uVar1 >> 1;
    param_2 = uVar3;
    if (uVar2 != 0) {
      param_2 = uVar3 ^ 0xedb88320;
    }
  } while( true );
}



// Function: crc_word @ 0xd950

void crc_word(void)

{
  int iVar1;
  
  iVar1 = 8;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}



// Function: get_crc_table @ 0xd9d0

undefined * get_crc_table(void)

{
  return &DAT_00112b60;
}



// Function: crc32_z @ 0xd9e0

ulong crc32_z(uint param_1,ulong *param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  byte bVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  ulong *puVar10;
  ulong uVar12;
  uint uVar13;
  ulong uVar14;
  uint uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  uint uVar19;
  ulong uVar20;
  ulong *local_58;
  long local_50;
  ulong local_48;
  long local_40;
  ulong *puVar11;
  
  if (param_2 == (ulong *)0x0) {
    return 0;
  }
  uVar2 = (ulong)~param_1;
  puVar11 = param_2;
  local_48 = param_3;
  if (0x2e < param_3) {
    do {
      if (((ulong)puVar11 & 7) == 0) {
        local_48 = param_3 % 0x28;
        local_40 = param_3 / 0x28 - 1;
        if (local_40 != 0) goto LAB_0010db82;
        uVar13 = 0;
        uVar15 = 0;
        uVar5 = 0;
        uVar19 = 0;
        goto LAB_0010dc9b;
      }
      puVar10 = (ulong *)((long)puVar11 + 1);
      uVar2 = (ulong)*(uint *)(&DAT_00112b60 + (ulong)(byte)((byte)uVar2 ^ (byte)*puVar11) * 4) ^
              uVar2 >> 8;
      param_3 = param_3 - 1;
      puVar11 = puVar10;
    } while (param_3 != 0);
    local_40 = -1;
    local_48 = 0;
LAB_0010db82:
    uVar14 = 0;
    uVar16 = 0;
    uVar6 = 0;
    uVar20 = 0;
    local_50 = local_40;
    local_58 = puVar11;
    do {
      iVar9 = 1;
      uVar7 = uVar6 ^ local_58[2];
      uVar8 = *local_58 ^ uVar2;
      uVar17 = local_58[1] ^ uVar20;
      uVar12 = local_58[3] ^ uVar16;
      uVar2 = (ulong)*(uint *)(&DAT_00110b60 + (uVar8 & 0xff) * 4);
      uVar18 = local_58[4] ^ uVar14;
      uVar20 = (ulong)*(uint *)(&DAT_00110b60 + (uVar17 & 0xff) * 4);
      uVar6 = (ulong)*(uint *)(&DAT_00110b60 + (uVar7 & 0xff) * 4);
      uVar16 = (ulong)*(uint *)(&DAT_00110b60 + (uVar12 & 0xff) * 4);
      uVar14 = (ulong)*(uint *)(&DAT_00110b60 + (uVar18 & 0xff) * 4);
      do {
        bVar4 = (char)iVar9 * '\b';
        lVar3 = (long)iVar9;
        iVar9 = iVar9 + 1;
        lVar3 = lVar3 * 0x100;
        uVar2 = (ulong)((uint)uVar2 ^
                       *(uint *)(&DAT_00110b60 + ((uVar8 >> (bVar4 & 0x3f) & 0xff) + lVar3) * 4));
        uVar19 = (uint)uVar20 ^
                 *(uint *)(&DAT_00110b60 + ((uVar17 >> (bVar4 & 0x3f) & 0xff) + lVar3) * 4);
        uVar20 = (ulong)uVar19;
        uVar5 = (uint)uVar6 ^
                *(uint *)(&DAT_00110b60 + ((uVar7 >> (bVar4 & 0x3f) & 0xff) + lVar3) * 4);
        uVar6 = (ulong)uVar5;
        uVar15 = (uint)uVar16 ^
                 *(uint *)(&DAT_00110b60 + ((uVar12 >> (bVar4 & 0x3f) & 0xff) + lVar3) * 4);
        uVar16 = (ulong)uVar15;
        uVar13 = (uint)uVar14 ^
                 *(uint *)(&DAT_00110b60 + (lVar3 + (uVar18 >> (bVar4 & 0x3f) & 0xff)) * 4);
        uVar14 = (ulong)uVar13;
      } while (iVar9 != 8);
      local_50 = local_50 + -1;
      local_58 = local_58 + 5;
    } while (local_50 != 0);
    puVar11 = puVar11 + local_40 * 5;
LAB_0010dc9b:
    param_2 = puVar11 + 5;
    uVar1 = FUN_0010d950(uVar2 ^ *puVar11);
    uVar19 = FUN_0010d950((ulong)(uVar1 ^ uVar19) ^ param_2[-4]);
    uVar5 = FUN_0010d950((ulong)(uVar19 ^ uVar5) ^ param_2[-3]);
    uVar5 = FUN_0010d950((ulong)(uVar5 ^ uVar15) ^ param_2[-2]);
    uVar5 = FUN_0010d950((ulong)(uVar5 ^ uVar13) ^ param_2[-1]);
    uVar2 = (ulong)uVar5;
  }
  if (7 < local_48) {
    puVar11 = (ulong *)((long)param_2 + (local_48 - 8 & 0xfffffffffffffff8) + 8);
    do {
      puVar10 = param_2 + 1;
      uVar2 = uVar2 >> 8 ^
              (ulong)*(uint *)(&DAT_00112b60 + (ulong)(byte)((byte)uVar2 ^ (byte)*param_2) * 4);
      uVar2 = uVar2 >> 8 ^
              (ulong)*(uint *)(&DAT_00112b60 +
                              (ulong)(byte)((byte)uVar2 ^ *(byte *)((long)param_2 + 1)) * 4);
      uVar2 = uVar2 >> 8 ^
              (ulong)*(uint *)(&DAT_00112b60 +
                              (ulong)(byte)((byte)uVar2 ^ *(byte *)((long)param_2 + 2)) * 4);
      uVar2 = uVar2 >> 8 ^
              (ulong)*(uint *)(&DAT_00112b60 +
                              (ulong)(byte)((byte)uVar2 ^ *(byte *)((long)param_2 + 3)) * 4);
      uVar2 = uVar2 >> 8 ^
              (ulong)*(uint *)(&DAT_00112b60 +
                              (ulong)(byte)((byte)uVar2 ^ *(byte *)((long)param_2 + 4)) * 4);
      uVar2 = uVar2 >> 8 ^
              (ulong)*(uint *)(&DAT_00112b60 +
                              (ulong)(byte)((byte)uVar2 ^ *(byte *)((long)param_2 + 5)) * 4);
      uVar2 = uVar2 >> 8 ^
              (ulong)*(uint *)(&DAT_00112b60 +
                              (ulong)(byte)((byte)uVar2 ^ *(byte *)((long)param_2 + 6)) * 4);
      uVar2 = uVar2 >> 8 ^
              (ulong)*(uint *)(&DAT_00112b60 +
                              (ulong)(byte)((byte)uVar2 ^ *(byte *)((long)param_2 + 7)) * 4);
      param_2 = puVar10;
    } while (puVar10 != puVar11);
    local_48 = local_48 & 7;
    param_2 = puVar11;
  }
  if (local_48 != 0) {
    puVar11 = param_2;
    do {
      puVar10 = (ulong *)((long)puVar11 + 1);
      uVar2 = (ulong)*(uint *)(&DAT_00112b60 + (ulong)(byte)((byte)uVar2 ^ (byte)*puVar11) * 4) ^
              uVar2 >> 8;
      puVar11 = puVar10;
    } while (puVar10 != (ulong *)(local_48 + (long)param_2));
  }
  return uVar2 ^ 0xffffffff;
}



// Function: crc32 @ 0xdd50

void crc32(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_0010d9e0(param_1,param_2,param_3);
  return;
}



// Function: crc32_combine64 @ 0xdd60

uint crc32_combine64(undefined4 param_1,uint param_2,undefined8 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_0010d980(param_3);
  uVar2 = FUN_0010d910(uVar1,param_1);
  return uVar2 ^ param_2;
}



// Function: crc32_combine_gen64 @ 0xdda0

undefined4 crc32_combine_gen64(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0010d980();
  return uVar1;
}



// Function: crc32_combine_op @ 0xddc0

uint crc32_combine_op(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = FUN_0010d910(param_3,param_1);
  return uVar1 ^ param_2;
}



// Function: inflate_fast @ 0xdde0

void inflate_fast(undefined8 *param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  byte bVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  undefined1 *puVar15;
  byte bVar16;
  int iVar17;
  ulong uVar18;
  ulong uVar19;
  undefined1 *puVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  ulong uVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  byte *pbVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  bool bVar32;
  
  pbVar28 = (byte *)*param_1;
  lVar12 = param_1[7];
  puVar25 = (undefined1 *)param_1[3];
  pbVar3 = pbVar28 + (*(int *)(param_1 + 1) - 5);
  iVar6 = *(int *)(param_1 + 4);
  uVar7 = *(undefined4 *)(lVar12 + 0x7c);
  uVar8 = *(uint *)(lVar12 + 0x44);
  iVar9 = *(int *)(lVar12 + 0x3c);
  lVar13 = *(long *)(lVar12 + 0x68);
  lVar14 = *(long *)(lVar12 + 0x70);
  iVar17 = (int)puVar25;
  puVar4 = puVar25 + (iVar6 - 0x101);
  uVar10 = *(uint *)(lVar12 + 0x40);
  uVar21 = *(uint *)(lVar12 + 0x58);
  uVar11 = *(undefined4 *)(lVar12 + 0x78);
  puVar15 = *(undefined1 **)(lVar12 + 0x48);
  uVar18 = *(ulong *)(lVar12 + 0x50);
LAB_0010de8f:
  if (uVar21 < 0xf) {
    pbVar1 = pbVar28 + 1;
    bVar16 = (byte)uVar21;
    bVar5 = *pbVar28;
    pbVar28 = pbVar28 + 2;
    uVar21 = uVar21 + 0x10;
    uVar18 = uVar18 + ((ulong)*pbVar1 << (bVar16 + 8 & 0x3f)) + ((ulong)bVar5 << (bVar16 & 0x3f));
  }
  uVar19 = (1 << ((byte)uVar11 & 0x1f)) - 1 & uVar18;
  while( true ) {
    pbVar1 = (byte *)(lVar13 + uVar19 * 4);
    uVar18 = uVar18 >> (pbVar1[1] & 0x3f);
    uVar21 = uVar21 - pbVar1[1];
    bVar5 = *pbVar1;
    if (bVar5 == 0) break;
    if ((bVar5 & 0x10) != 0) {
      uVar31 = (uint)*(ushort *)(pbVar1 + 2);
      uVar29 = bVar5 & 0xf;
      if ((bVar5 & 0xf) != 0) {
        uVar22 = uVar21;
        if (uVar21 < uVar29) {
          bVar5 = *pbVar28;
          pbVar28 = pbVar28 + 1;
          uVar22 = uVar21 + 8;
          uVar18 = uVar18 + ((ulong)bVar5 << ((byte)uVar21 & 0x3f));
        }
        uVar21 = uVar22 - uVar29;
        uVar31 = uVar31 + (~(-1 << (sbyte)uVar29) & (uint)uVar18);
        uVar18 = uVar18 >> (sbyte)uVar29;
      }
      if (uVar21 < 0xf) {
        pbVar1 = pbVar28 + 1;
        bVar16 = (byte)uVar21;
        bVar5 = *pbVar28;
        pbVar28 = pbVar28 + 2;
        uVar21 = uVar21 + 0x10;
        uVar18 = uVar18 + ((ulong)*pbVar1 << (bVar16 + 8 & 0x3f)) +
                          ((ulong)bVar5 << (bVar16 & 0x3f));
      }
      pbVar1 = (byte *)(lVar14 + ((1 << ((byte)uVar7 & 0x1f)) - 1 & uVar18) * 4);
      uVar18 = uVar18 >> (pbVar1[1] & 0x3f);
      uVar21 = uVar21 - pbVar1[1];
      bVar5 = *pbVar1;
      goto joined_r0x0010df99;
    }
    if ((bVar5 & 0x40) != 0) {
      if ((bVar5 & 0x20) == 0) {
        param_1[6] = "invalid literal/length code";
        *(undefined4 *)(lVar12 + 8) = 0x3f51;
      }
      else {
        *(undefined4 *)(lVar12 + 8) = 0x3f3f;
      }
      goto LAB_0010dff4;
    }
    uVar19 = ((1 << (bVar5 & 0x1f)) - 1 & uVar18) + (ulong)*(ushort *)(pbVar1 + 2);
  }
  *puVar25 = (char)*(undefined2 *)(pbVar1 + 2);
  puVar25 = puVar25 + 1;
  goto LAB_0010df07;
joined_r0x0010df99:
  if ((bVar5 & 0x10) != 0) goto LAB_0010e0f5;
  if ((bVar5 & 0x40) != 0) {
    param_1[6] = "invalid distance code";
    *(undefined4 *)(lVar12 + 8) = 0x3f51;
    goto LAB_0010dff4;
  }
  pbVar1 = (byte *)(lVar14 + (((1 << (bVar5 & 0x1f)) - 1 & uVar18) + (ulong)*(ushort *)(pbVar1 + 2))
                             * 4);
  uVar18 = uVar18 >> (pbVar1[1] & 0x3f);
  uVar21 = uVar21 - pbVar1[1];
  bVar5 = *pbVar1;
  goto joined_r0x0010df99;
LAB_0010e0f5:
  uVar29 = bVar5 & 0xf;
  if (uVar21 < uVar29) {
    uVar22 = uVar21 + 8;
    uVar18 = uVar18 + ((ulong)*pbVar28 << ((byte)uVar21 & 0x3f));
    if (uVar22 < uVar29) {
      pbVar2 = pbVar28 + 1;
      uVar21 = uVar21 + 0x10;
      pbVar28 = pbVar28 + 2;
      uVar18 = uVar18 + ((ulong)*pbVar2 << ((byte)uVar22 & 0x3f));
    }
    else {
      pbVar28 = pbVar28 + 1;
      uVar21 = uVar22;
    }
  }
  uVar21 = uVar21 - uVar29;
  uVar29 = (~(-1 << (bVar5 & 0xf)) & (uint)uVar18) + (uint)*(ushort *)(pbVar1 + 2);
  uVar18 = uVar18 >> (bVar5 & 0xf);
  uVar22 = (int)puVar25 - (iVar17 - (param_2 - iVar6));
  if (uVar22 < uVar29) {
    uVar30 = uVar29 - uVar22;
    if ((uVar10 < uVar30) && (*(int *)(lVar12 + 0x1be8) != 0)) {
      param_1[6] = "invalid distance too far back";
      *(undefined4 *)(lVar12 + 8) = 0x3f51;
LAB_0010dff4:
      param_1[3] = puVar25;
      *param_1 = pbVar28 + -(ulong)(uVar21 >> 3);
      *(int *)(param_1 + 1) = ((int)pbVar3 - (int)(pbVar28 + -(ulong)(uVar21 >> 3))) + 5;
      *(int *)(param_1 + 4) = ((int)puVar4 - (int)puVar25) + 0x101;
      *(ulong *)(lVar12 + 0x50) = (1 << (sbyte)(uVar21 & 7)) - 1 & uVar18;
      *(uint *)(lVar12 + 0x58) = uVar21 & 7;
      return;
    }
    iVar23 = uVar22 - uVar29;
    puVar26 = puVar25;
    if (uVar8 == 0) {
      puVar20 = puVar15 + (uint)(iVar9 + iVar23);
      if (uVar30 < uVar31) {
        uVar31 = uVar31 + iVar23;
        uVar19 = 0;
        do {
          puVar25[uVar19] = (puVar15 + (uint)(iVar9 + iVar23))[uVar19];
          uVar19 = uVar19 + 1;
        } while (uVar30 != uVar19);
        puVar20 = puVar25 + uVar30 + -(ulong)uVar29;
        puVar26 = puVar25 + uVar30;
      }
    }
    else if (uVar8 < uVar30) {
      puVar20 = puVar15 + (iVar9 + uVar8 + iVar23);
      if (uVar30 - uVar8 < uVar31) {
        uVar31 = iVar23 + uVar31 + uVar8;
        uVar24 = (ulong)((uVar30 - uVar8) - 1);
        uVar19 = 0;
        do {
          puVar25[uVar19] = (puVar15 + (iVar9 + uVar8 + iVar23))[uVar19];
          bVar32 = uVar24 != uVar19;
          uVar19 = uVar19 + 1;
        } while (bVar32);
        puVar26 = puVar25 + uVar24 + 1;
        puVar20 = puVar15;
        if (uVar8 < uVar31) {
          uVar31 = uVar31 - uVar8;
          uVar19 = 0;
          do {
            puVar26[uVar19] = puVar15[uVar19];
            uVar19 = uVar19 + 1;
          } while (uVar8 != uVar19);
          puVar20 = puVar26 + uVar8 + -(ulong)uVar29;
          puVar26 = puVar26 + uVar8;
        }
      }
    }
    else {
      puVar20 = puVar15 + (uVar8 + iVar23);
      if (uVar30 < uVar31) {
        uVar31 = uVar31 + iVar23;
        uVar19 = 0;
        do {
          puVar25[uVar19] = puVar20[uVar19];
          uVar19 = uVar19 + 1;
        } while (uVar30 != uVar19);
        puVar26 = puVar25 + uVar30;
        puVar20 = puVar26 + -(ulong)uVar29;
      }
    }
    for (; 2 < uVar31; uVar31 = uVar31 - 3) {
      *puVar26 = *puVar20;
      puVar26[1] = puVar20[1];
      puVar26[2] = puVar20[2];
      puVar20 = puVar20 + 3;
      puVar26 = puVar26 + 3;
    }
    puVar25 = puVar26;
    if (uVar31 != 0) {
      *puVar26 = *puVar20;
      if (uVar31 == 2) {
        puVar25 = puVar26 + 2;
        puVar26[1] = puVar20[1];
      }
      else {
        puVar25 = puVar26 + 1;
      }
    }
  }
  else {
    puVar26 = puVar25 + -(ulong)uVar29;
    do {
      puVar27 = puVar25;
      puVar20 = puVar26;
      uVar31 = uVar31 - 3;
      *puVar27 = *puVar20;
      puVar27[1] = puVar20[1];
      puVar25 = puVar27 + 3;
      puVar27[2] = puVar20[2];
      puVar26 = puVar20 + 3;
    } while (2 < uVar31);
    if (uVar31 != 0) {
      puVar25 = puVar27 + 4;
      puVar27[3] = puVar20[3];
      if (uVar31 == 2) {
        puVar25 = puVar27 + 5;
        puVar27[4] = puVar20[4];
      }
    }
  }
LAB_0010df07:
  if ((pbVar3 <= pbVar28) || (puVar4 <= puVar25)) goto LAB_0010dff4;
  goto LAB_0010de8f;
}



