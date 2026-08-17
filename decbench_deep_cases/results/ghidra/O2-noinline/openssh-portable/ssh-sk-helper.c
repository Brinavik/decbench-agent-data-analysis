// Function: main @ 0x6e20

undefined8 main(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  int *piVar8;
  char *pcVar9;
  uint *puVar10;
  undefined8 in_R10;
  undefined8 in_R11;
  int iVar11;
  long in_FS_OFFSET;
  char local_4a;
  undefined1 local_49;
  int local_48;
  uint local_44;
  long local_40;
  
  iVar1 = 2;
  iVar11 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_44 = 0;
  local_49 = 0;
  FUN_001262a0();
  FUN_0011fc40(program_invocation_short_name,2,2,local_49);
  while( true ) {
    iVar2 = thunk_FUN_0013b460(param_1,param_2,&DAT_00140470);
    if (iVar2 == -1) break;
    if (iVar2 != 0x76) {
      __fprintf_chk(stderr,1,"usage: %s [-v]\n",program_invocation_short_name);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (iVar1 == 2) {
      iVar1 = 5;
    }
    else if (iVar1 < 7) {
      iVar1 = FUN_0013da20(iVar1,1);
    }
    iVar11 = 1;
  }
  FUN_0011fc40(program_invocation_short_name,iVar1,2,iVar11);
  closefrom();
  iVar1 = dup(0);
  if (iVar1 != -1) {
    iVar2 = dup(1);
    if (iVar2 != -1) {
      close(0);
      close(1);
      FUN_001262a0();
      lVar4 = FUN_0010b880();
      if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0011ee30("ssh-sk-helper.c",&DAT_0013e2b5,0x13b,0,1,0,"%s: sshbuf_new failed",
                     program_invocation_short_name);
      }
      iVar3 = FUN_0012ef90(iVar1,lVar4);
      if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0011ee30("ssh-sk-helper.c",&DAT_0013e2b5,0x13d,0,1,0,"ssh_msg_recv failed",in_R10);
      }
      close(iVar1);
      uVar5 = FUN_0010c3d0(lVar4);
      FUN_001203a0("ssh-sk-helper.c",&DAT_0013e2b5,0x13f,1,5,0,"received message len %zu",uVar5);
      lVar7 = lVar4;
      iVar1 = FUN_00119e50(lVar4,&local_4a);
      uVar5 = program_invocation_short_name;
      if (iVar1 != 0) {
        uVar6 = FUN_0010b050(iVar1);
                    /* WARNING: Subroutine does not return */
        FUN_0011ee30("ssh-sk-helper.c",&DAT_0013e2b5,0x142,0,1,uVar6,"%s: parse version",uVar5);
      }
      if (local_4a == '\x05') {
        iVar1 = FUN_00119cd0(lVar4,&local_48);
        if (iVar1 == 0) {
          iVar1 = FUN_00119e50(lVar4,&local_49);
          if (iVar1 == 0) {
            puVar10 = &local_44;
            iVar1 = FUN_00119cd0(lVar4);
            if (iVar1 == 0) {
              if (iVar11 == 0) {
                lVar7 = FUN_0011f810(local_44);
                if (lVar7 != 0) {
                  puVar10 = (uint *)(ulong)local_44;
                  FUN_0011fc40(program_invocation_short_name,puVar10,2,local_49);
                }
              }
              if (local_48 == 2) {
                uVar5 = FUN_00107bb0(lVar4);
              }
              else if (local_48 == 3) {
                uVar5 = FUN_00108050(lVar4);
              }
              else {
                if (local_48 != 1) {
                    /* WARNING: Subroutine does not return */
                  FUN_0011ee30("ssh-sk-helper.c",&DAT_0013e2b5,0x15b,0,1,0,
                               "%s: unsupported request type %u",program_invocation_short_name,
                               local_48,puVar10);
                }
                uVar5 = FUN_00107760(lVar4);
              }
              FUN_0010bce0(lVar4);
              uVar6 = FUN_0010c3d0(uVar5);
              FUN_001203a0("ssh-sk-helper.c",&DAT_0013e2b5,0x15e,1,5,0,"reply len %zu",uVar6);
              uVar6 = FUN_0012eda0(iVar2,5,uVar5);
              if ((int)uVar6 != -1) {
                FUN_0010bce0(uVar5);
                close(iVar2);
                if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
                  return 0;
                }
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail();
              }
                    /* WARNING: Subroutine does not return */
              FUN_0011ee30("ssh-sk-helper.c",&DAT_0013e2b5,0x161,0,1,0,"ssh_msg_send failed",uVar6);
            }
          }
        }
        uVar5 = program_invocation_short_name;
        uVar6 = FUN_0010b050(iVar1);
                    /* WARNING: Subroutine does not return */
        FUN_0011ee30("ssh-sk-helper.c",&DAT_0013e2b5,0x14b,0,1,uVar6,"%s: parse",uVar5);
      }
                    /* WARNING: Subroutine does not return */
      FUN_0011ee30("ssh-sk-helper.c",&DAT_0013e2b5,0x144,0,1,0,
                   "unsupported version: received %d, expected %d",local_4a,5,lVar7);
    }
  }
  piVar8 = __errno_location();
  pcVar9 = strerror(*piVar8);
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("ssh-sk-helper.c",&DAT_0013e2b5,0x135,0,1,0,"%s: dup: %s",
               program_invocation_short_name,pcVar9,in_R11);
}



// Function: null_empty @ 0x73c0

undefined8 null_empty(undefined8 *param_1)

{
  char *__ptr;
  
  __ptr = (char *)*param_1;
  if ((__ptr != (char *)0x0) && (*__ptr == '\0')) {
    free(__ptr);
    *param_1 = 0;
    return 0;
  }
  return 0;
}



// Function: reply_error @ 0x74f0

long reply_error(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 int param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long in_FS_OFFSET;
  void *local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined1 *local_f0;
  undefined1 *local_e8;
  long local_e0;
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  
  if (in_AL != '\0') {
    local_a8 = param_1;
    local_98 = param_2;
    local_88 = param_3;
    local_78 = param_4;
    local_68 = param_5;
    local_58 = param_6;
    local_48 = param_7;
    local_38 = param_8;
  }
  local_e0 = *(long *)(in_FS_OFFSET + 0x28);
  local_f0 = &stack0x00000008;
  local_f8 = 0x10;
  local_e8 = local_d8;
  local_f4 = 0x30;
  local_c8 = param_11;
  local_c0 = param_12;
  local_b8 = param_13;
  local_b0 = param_14;
  FUN_00121880(&local_100,param_10,&local_f8);
  FUN_001203a0("ssh-sk-helper.c","reply_error",0x42,0,5,0,"%s: %s",program_invocation_short_name,
               local_100);
  free(local_100);
  if (param_9 < 0) {
    lVar3 = FUN_0010b880();
    if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0011ee30("ssh-sk-helper.c","reply_error",0x49,0,1,0,"%s: sshbuf_new failed",
                   program_invocation_short_name);
    }
    iVar1 = FUN_0011afb0(lVar3,0);
    if (iVar1 == 0) {
      uVar2 = FUN_0013dae0(param_9);
      iVar1 = FUN_0011afb0(lVar3,uVar2);
      if (iVar1 == 0) {
        if (local_e0 == *(long *)(in_FS_OFFSET + 0x28)) {
          return lVar3;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("ssh-sk-helper.c","reply_error",0x4c,0,1,0,"%s: buffer error",
                 program_invocation_short_name);
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("ssh-sk-helper.c","reply_error",0x46,1,1,0,"invalid error code %d",param_9);
}



// Function: process_sign @ 0x7760

long process_sign(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  void *pvVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  size_t sVar7;
  undefined8 uVar8;
  long in_FS_OFFSET;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  void *local_40;
  char *local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_68 = 0;
  local_58 = 0;
  local_48 = 0;
  local_40 = (void *)0x0;
  local_38 = (char *)0x0;
  iVar4 = FUN_0011b8a0(param_1,&local_70);
  if (iVar4 == 0) {
    iVar4 = FUN_0011a6f0(param_1,&local_40,0);
    if (iVar4 == 0) {
      iVar4 = FUN_0011a460(param_1,&local_60,&local_50);
      if (iVar4 == 0) {
        iVar4 = FUN_0011a6f0(param_1,0,0);
        if (iVar4 == 0) {
          iVar4 = FUN_00119cd0(param_1,&local_74);
          if (iVar4 == 0) {
            iVar4 = FUN_0011a6f0(param_1,&local_38,0);
            if (iVar4 == 0) {
              lVar5 = FUN_0010c3d0(param_1);
              if (lVar5 != 0) {
                    /* WARNING: Subroutine does not return */
                FUN_0011ee30("ssh-sk-helper.c","process_sign",0x6f,0,1,0,
                             "%s: trailing data in request",program_invocation_short_name);
              }
              iVar4 = FUN_00116380(local_70,&local_68);
              uVar8 = program_invocation_short_name;
              if (iVar4 != 0) {
                uVar6 = FUN_0010b050(iVar4);
                    /* WARNING: Subroutine does not return */
                FUN_0011ee30("ssh-sk-helper.c","process_sign",0x72,0,1,uVar6,
                             "%s: Unable to parse private key",uVar8);
              }
              iVar4 = FUN_0010f8d0(local_68);
              pvVar2 = local_40;
              uVar8 = local_50;
              uVar1 = local_74;
              if (iVar4 == 0) {
                uVar8 = FUN_0010eaf0(local_68);
                    /* WARNING: Subroutine does not return */
                FUN_0011ee30("ssh-sk-helper.c","process_sign",0x74,0,1,0,
                             "%s: Unsupported key type %s",program_invocation_short_name,uVar8,
                             param_4);
              }
              uVar6 = FUN_0010e880(local_68);
              FUN_001203a0("ssh-sk-helper.c","process_sign",0x78,1,5,0,
                           "ready to sign with key %s, provider %s: msg len %zu, compat 0x%lx",uVar6
                           ,pvVar2,uVar8,uVar1);
              FUN_001073c0(&local_38);
              iVar4 = FUN_0010a4d0(local_40,local_68,&local_58,&local_48,local_60,local_50,local_74)
              ;
              if (iVar4 == 0) {
                lVar5 = FUN_0010b880();
                if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_0011ee30("ssh-sk-helper.c","process_sign",0x85,0,1,0,"%s: sshbuf_new failed",
                               program_invocation_short_name);
                }
                iVar4 = FUN_0011afb0(lVar5,1);
                if (iVar4 == 0) {
                  iVar4 = FUN_0011b6c0(lVar5,local_58,local_48);
                  if (iVar4 == 0) goto LAB_00107947;
                }
                uVar8 = program_invocation_short_name;
                uVar6 = FUN_0010b050(iVar4);
                    /* WARNING: Subroutine does not return */
                FUN_0011ee30("ssh-sk-helper.c","process_sign",0x89,0,1,uVar6,"%s: compose",uVar8);
              }
              uVar8 = FUN_0010b050(iVar4);
              lVar5 = FUN_001074f0(iVar4,"Signing failed: %s",uVar8);
LAB_00107947:
              FUN_00110a60(local_68);
              FUN_0010bce0(local_70);
              free(local_40);
              if (local_58 != 0) {
                FUN_0013b0d0(local_58,local_48);
              }
              pcVar3 = local_38;
              if (local_38 != (char *)0x0) {
                sVar7 = strlen(local_38);
                FUN_0013b0d0(pcVar3,sVar7);
              }
              if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
                return lVar5;
              }
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail();
            }
          }
        }
      }
    }
  }
  uVar8 = program_invocation_short_name;
  uVar6 = FUN_0010b050(iVar4);
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("ssh-sk-helper.c","process_sign",0x6d,0,1,uVar6,"%s: parse",uVar8);
}



// Function: process_enroll @ 0x7bb0

long process_enroll(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  size_t sVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long in_FS_OFFSET;
  undefined1 auVar8 [16];
  undefined1 local_7d;
  int local_7c;
  void *local_78;
  void *local_70;
  char *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = FUN_0010b880();
  if (lVar2 != 0) {
    lVar3 = FUN_0010b880();
    if (lVar3 != 0) {
      iVar1 = FUN_00119cd0(param_1,&local_7c);
      if (iVar1 == 0) {
        iVar1 = FUN_0011a6f0(param_1,&local_78,0);
        if (iVar1 == 0) {
          iVar1 = FUN_0011a6f0(param_1,&local_60,0);
          if (iVar1 == 0) {
            iVar1 = FUN_0011a6f0(param_1,&local_70,0);
            if (iVar1 == 0) {
              iVar1 = FUN_0011a6f0(param_1,&local_58,0);
              if (iVar1 == 0) {
                iVar1 = FUN_00119e50(param_1,&local_7d);
                if (iVar1 == 0) {
                  iVar1 = FUN_0011a6f0(param_1,&local_68,0);
                  if (iVar1 == 0) {
                    iVar1 = FUN_0011b8a0(param_1,&local_50);
                    if (iVar1 == 0) {
                      auVar8 = FUN_0010c3d0(param_1);
                      if (auVar8._0_8_ != 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_0011ee30("ssh-sk-helper.c","process_enroll",0xad,0,1,0,
                                     "%s: trailing data in request",program_invocation_short_name);
                      }
                      if (local_7c < 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_0011ee30("ssh-sk-helper.c","process_enroll",0xb0,0,1,0,"%s: bad type %u"
                                     ,program_invocation_short_name,local_7c,auVar8._8_8_);
                      }
                      lVar4 = FUN_0010c3d0(local_50);
                      if (lVar4 == 0) {
                        FUN_0010bce0(local_50);
                        local_50 = 0;
                      }
                      FUN_001073c0(&local_60);
                      FUN_001073c0(&local_58);
                      FUN_001073c0(&local_68);
                      iVar1 = FUN_00109fb0(local_7c,local_78,local_60,local_70,local_58,local_7d,
                                           local_68,local_50,&local_48,lVar2);
                      if (iVar1 == 0) {
                        lVar4 = FUN_0010b880();
                        if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                          FUN_0011ee30("ssh-sk-helper.c","process_enroll",0xc0,0,1,0,
                                       "%s: sshbuf_new failed",program_invocation_short_name);
                        }
                        iVar1 = FUN_00117d00(local_48,lVar3);
                        uVar6 = program_invocation_short_name;
                        if (iVar1 != 0) {
                          uVar7 = FUN_0010b050(iVar1);
                    /* WARNING: Subroutine does not return */
                          FUN_0011ee30("ssh-sk-helper.c","process_enroll",0xc2,0,1,uVar7,
                                       "%s: encode key",uVar6);
                        }
                        iVar1 = FUN_0011afb0(lVar4,2);
                        if (iVar1 == 0) {
                          iVar1 = FUN_0011b840(lVar4,lVar3);
                          if (iVar1 == 0) {
                            iVar1 = FUN_0011b840(lVar4,lVar2);
                            if (iVar1 == 0) goto LAB_00107d98;
                          }
                        }
                        uVar6 = program_invocation_short_name;
                        uVar7 = FUN_0010b050(iVar1);
                    /* WARNING: Subroutine does not return */
                        FUN_0011ee30("ssh-sk-helper.c","process_enroll",0xc6,0,1,uVar7,"%s: compose"
                                     ,uVar6);
                      }
                      uVar6 = FUN_0010b050(iVar1);
                      lVar4 = FUN_001074f0(iVar1,"Enrollment failed: %s",uVar6);
LAB_00107d98:
                      FUN_00110a60(local_48);
                      FUN_0010bce0(lVar3);
                      FUN_0010bce0(lVar2);
                      FUN_0010bce0(local_50);
                      free(local_78);
                      free(local_70);
                      if (local_68 != (char *)0x0) {
                        sVar5 = strlen(local_68);
                        FUN_0013b0d0(local_68,sVar5);
                      }
                      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
                        return lVar4;
                      }
                    /* WARNING: Subroutine does not return */
                      __stack_chk_fail();
                    }
                  }
                }
              }
            }
          }
        }
      }
      uVar6 = program_invocation_short_name;
      uVar7 = FUN_0010b050(iVar1);
                    /* WARNING: Subroutine does not return */
      FUN_0011ee30("ssh-sk-helper.c","process_enroll",0xab,0,1,uVar7,"%s: parse",uVar6);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("ssh-sk-helper.c","process_enroll",0xa1,0,1,0,"%s: sshbuf_new failed",
               program_invocation_short_name);
}



// Function: process_load_resident @ 0x8050

long process_load_resident(undefined8 param_1)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  size_t sVar7;
  undefined8 uVar8;
  ulong uVar9;
  long in_FS_OFFSET;
  undefined4 local_6c;
  void *local_68;
  char *local_60;
  void *local_58;
  long local_50;
  ulong local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_50 = 0;
  local_48 = 0;
  lVar4 = FUN_0010b880();
  if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("ssh-sk-helper.c","process_load_resident",0xe0,0,1,0,"%s: sshbuf_new failed",
                 program_invocation_short_name);
  }
  iVar3 = FUN_0011a6f0(param_1,&local_68,0);
  if (iVar3 == 0) {
    iVar3 = FUN_0011a6f0(param_1,&local_58,0);
    if (iVar3 == 0) {
      iVar3 = FUN_0011a6f0(param_1,&local_60,0);
      if (iVar3 == 0) {
        iVar3 = FUN_00119cd0(param_1,&local_6c);
        if (iVar3 == 0) {
          lVar5 = FUN_0010c3d0(param_1);
          if (lVar5 != 0) {
                    /* WARNING: Subroutine does not return */
            FUN_0011ee30("ssh-sk-helper.c","process_load_resident",0xe8,0,1,0,
                         "%s: trailing data in request",program_invocation_short_name);
          }
          FUN_001073c0(&local_58);
          FUN_001073c0(&local_60);
          iVar3 = FUN_0010aae0(local_68,local_58,local_60,local_6c,&local_50,&local_48);
          if (iVar3 == 0) {
            lVar5 = FUN_0010b880();
            if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_0011ee30("ssh-sk-helper.c","process_load_resident",0xf5,0,1,0,
                           "%s: sshbuf_new failed",program_invocation_short_name);
            }
            iVar3 = FUN_0011afb0(lVar5,3);
            uVar8 = program_invocation_short_name;
            if (iVar3 != 0) {
              uVar6 = FUN_0010b050(iVar3);
                    /* WARNING: Subroutine does not return */
              FUN_0011ee30("ssh-sk-helper.c","process_load_resident",0xf8,0,1,uVar6,"%s: compose",
                           uVar8);
            }
            uVar9 = 0;
            if (local_48 != 0) {
              do {
                plVar1 = *(long **)(local_50 + uVar9 * 8);
                lVar2 = plVar1[2];
                uVar8 = *(undefined8 *)(*plVar1 + 0x60);
                uVar6 = FUN_0010e880();
                FUN_001203a0("ssh-sk-helper.c","process_load_resident",0xfb,1,5,0,
                             "key %zu %s %s uidlen %zu",uVar9,uVar6,uVar8,lVar2);
                FUN_0010be60(lVar4);
                iVar3 = FUN_00117d00(**(undefined8 **)(local_50 + uVar9 * 8),lVar4);
                uVar8 = program_invocation_short_name;
                if (iVar3 != 0) {
                  uVar6 = FUN_0010b050(iVar3);
                    /* WARNING: Subroutine does not return */
                  FUN_0011ee30("ssh-sk-helper.c","process_load_resident",0x100,0,1,uVar6,
                               "%s: encode key",uVar8);
                }
                iVar3 = FUN_0011b840(lVar5,lVar4);
                if (iVar3 != 0) {
LAB_0010837c:
                  uVar8 = program_invocation_short_name;
                  uVar6 = FUN_0010b050(iVar3);
                    /* WARNING: Subroutine does not return */
                  FUN_0011ee30("ssh-sk-helper.c","process_load_resident",0x105,0,1,uVar6,
                               "%s: compose key",uVar8);
                }
                iVar3 = FUN_0011b800(lVar5,&DAT_0013f156);
                if (iVar3 != 0) goto LAB_0010837c;
                lVar2 = *(long *)(local_50 + uVar9 * 8);
                iVar3 = FUN_0011b6c0(lVar5,*(undefined8 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10))
                ;
                if (iVar3 != 0) goto LAB_0010837c;
                uVar9 = uVar9 + 1;
              } while (uVar9 < local_48);
            }
          }
          else {
            uVar8 = FUN_0010b050(iVar3);
            lVar5 = FUN_001074f0(iVar3,"sshsk_load_resident failed: %s",uVar8);
          }
          FUN_0010a990(local_50,local_48);
          FUN_0010bce0(lVar4);
          free(local_68);
          free(local_58);
          if (local_60 != (char *)0x0) {
            sVar7 = strlen(local_60);
            FUN_0013b0d0(local_60,sVar7);
          }
          if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
            return lVar5;
          }
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
      }
    }
  }
  uVar8 = program_invocation_short_name;
  uVar6 = FUN_0010b050(iVar3);
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("ssh-sk-helper.c","process_load_resident",0xe6,0,1,uVar6,"%s: parse",uVar8);
}



// Function: skerr_to_ssherr @ 0x8500

undefined4 skerr_to_ssherr(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xfffffffc;
  if (param_1 + 5U < 4) {
    uVar1 = *(undefined4 *)(&DAT_0013e7d0 + (ulong)(param_1 + 5U) * 4);
  }
  return uVar1;
}



// Function: fill_attestation_blob @ 0x85a0

int fill_attestation_blob(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = FUN_0011b800(param_2,"ssh-sk-attest-v01");
  if ((((iVar1 == 0) &&
       (iVar1 = FUN_0011b6c0(param_2,*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x40)
                            ), iVar1 == 0)) &&
      (iVar1 = FUN_0011b6c0(param_2,*(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x30))
      , iVar1 == 0)) &&
     (((iVar1 = FUN_0011b6c0(param_2,*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x50)
                            ), iVar1 == 0 && (iVar1 = FUN_0011afb0(param_2,0), iVar1 == 0)) &&
      (iVar1 = FUN_0011b6c0(param_2,0,0), iVar1 == 0)))) {
    return 0;
  }
  uVar2 = FUN_0010b050(iVar1);
  FUN_001203a0("ssh-sk.c","fill_attestation_blob",0x1c5,1,2,uVar2,"compose");
  return iVar1;
}



// Function: sshsk_free_options @ 0x8790

undefined8 sshsk_free_options(long *param_1)

{
  undefined8 *puVar1;
  long *plVar2;
  undefined8 extraout_RAX;
  
  if (param_1 != (long *)0x0) {
    puVar1 = (undefined8 *)*param_1;
    plVar2 = param_1;
    while (puVar1 != (undefined8 *)0x0) {
      free((void *)*puVar1);
      free(*(void **)(*plVar2 + 8));
      free((void *)*plVar2);
      puVar1 = (undefined8 *)plVar2[1];
      plVar2 = plVar2 + 1;
    }
    free(param_1);
    return extraout_RAX;
  }
  return 0;
}



// Function: sshsk_free @ 0x8870

undefined8 sshsk_free(undefined8 *param_1)

{
  undefined8 extraout_RAX;
  
  if (param_1 != (undefined8 *)0x0) {
    free((void *)*param_1);
    if (param_1[1] != 0) {
      dlclose();
    }
    free(param_1);
    return extraout_RAX;
  }
  return 0;
}



// Function: sshsk_open @ 0x8920

undefined8 * sshsk_open(char *param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  char *pcVar4;
  long lVar5;
  code *pcVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    FUN_001203a0("ssh-sk.c","sshsk_open",0x71,0,2,0,"No FIDO SecurityKeyProvider specified");
    return (undefined8 *)0x0;
  }
  uVar9 = 0x30;
  puVar3 = calloc(1,0x30);
  if (puVar3 == (undefined8 *)0x0) {
    FUN_001203a0("ssh-sk.c","sshsk_open",0x75,1,2,0,"calloc failed",uVar9);
    return (undefined8 *)0x0;
  }
  pcVar4 = strdup(param_1);
  *puVar3 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "strdup failed";
    uVar9 = 1;
    uVar8 = 0x79;
  }
  else {
    iVar1 = strcasecmp(pcVar4,"internal");
    if (iVar1 != 0) {
      lVar5 = dlopen(param_1,2);
      puVar3[1] = lVar5;
      if (lVar5 == 0) {
        uVar9 = dlerror(0);
        uVar8 = 0x89;
        pcVar4 = "Provider \"%s\" dlopen failed: %s";
      }
      else {
        pcVar6 = (code *)dlsym(lVar5,"sk_api_version");
        puVar3[2] = pcVar6;
        if (pcVar6 != (code *)0x0) {
          uVar2 = (*pcVar6)();
          uVar7 = (ulong)uVar2;
          FUN_001203a0("ssh-sk.c","sshsk_open",0x93,1,5,0,"provider %s implements version 0x%08lx",
                       *puVar3,uVar7);
          if (uVar2 >> 0x10 == 10) {
            lVar5 = dlsym(puVar3[1],"sk_enroll");
            puVar3[3] = lVar5;
            if (lVar5 == 0) {
              uVar7 = dlerror();
              uVar9 = 0x9c;
              pcVar4 = "Provider %s dlsym(sk_enroll) failed: %s";
            }
            else {
              lVar5 = dlsym(puVar3[1],"sk_sign");
              puVar3[4] = lVar5;
              if (lVar5 == 0) {
                uVar7 = dlerror();
                uVar9 = 0xa1;
                pcVar4 = "Provider \"%s\" dlsym(sk_sign) failed: %s";
              }
              else {
                lVar5 = dlsym(puVar3[1],"sk_load_resident_keys");
                puVar3[5] = lVar5;
                if (lVar5 != 0) {
                  return puVar3;
                }
                uVar7 = dlerror();
                uVar9 = 0xa7;
                pcVar4 = "Provider \"%s\" dlsym(sk_load_resident_keys) failed: %s";
              }
            }
          }
          else {
            uVar9 = 0x96;
            pcVar4 = "Provider \"%s\" implements unsupported version 0x%08lx (supported: 0x%08lx)";
          }
          FUN_001203a0("ssh-sk.c","sshsk_open",uVar9,0,2,0,pcVar4,param_1,uVar7);
          goto LAB_00108b81;
        }
        uVar9 = dlerror();
        uVar8 = 0x8e;
        pcVar4 = "Provider \"%s\" dlsym(sk_api_version) failed: %s";
      }
      FUN_001203a0("ssh-sk.c","sshsk_open",uVar8,0,2,0,pcVar4,param_1,uVar9);
      goto LAB_00108b81;
    }
    uVar9 = 0;
    pcVar4 = "internal security key support not enabled";
    uVar8 = 0x84;
  }
  FUN_001203a0("ssh-sk.c","sshsk_open",uVar8,uVar9,2,0,pcVar4);
LAB_00108b81:
  FUN_00108870(puVar3);
  return (undefined8 *)0x0;
}



// Function: sshsk_free_enroll_response @ 0x8d30

undefined8 sshsk_free_enroll_response(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    FUN_0013b0d0(*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20));
    FUN_0013b0d0(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x10));
    FUN_0013b0d0(*(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x30));
    FUN_0013b0d0(*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x40));
    FUN_0013b0d0(*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x50));
    uVar1 = FUN_0013b0d0(param_1,0x58);
    return uVar1;
  }
  return 0;
}



// Function: sshsk_free_sign_response @ 0x8e10

undefined8 sshsk_free_sign_response(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    FUN_0013b0d0(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x10));
    FUN_0013b0d0(*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20));
    uVar1 = FUN_0013b0d0(param_1,0x28);
    return uVar1;
  }
  return 0;
}



// Function: sshsk_free_resident_key @ 0x8ed0

undefined8 sshsk_free_resident_key(undefined8 *param_1)

{
  undefined8 extraout_RAX;
  
  if (param_1 != (undefined8 *)0x0) {
    FUN_00110a60(*param_1);
    FUN_0013b0d0(param_1[1],param_1[2]);
    free(param_1);
    return extraout_RAX;
  }
  return 0;
}



// Function: sshsk_free_sk_resident_keys @ 0x8f80

undefined8 sshsk_free_sk_resident_keys(long *param_1,ulong param_2)

{
  undefined8 extraout_RAX;
  long *plVar1;
  ulong uVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  if (param_1 != (long *)0x0) {
    uVar2 = 0;
    plVar1 = param_1;
    do {
      uVar2 = uVar2 + 1;
      free(*(void **)(*plVar1 + 0x10));
      FUN_0013b0d0(*(undefined8 *)(*plVar1 + 0x78),*(undefined8 *)(*plVar1 + 0x80));
      FUN_0013b0d0(*(undefined8 *)(*plVar1 + 0x30),*(undefined8 *)(*plVar1 + 0x38));
      FUN_0013b0d0(*(undefined8 *)(*plVar1 + 0x20),*(undefined8 *)(*plVar1 + 0x28));
      FUN_0013b0d0(*(undefined8 *)(*plVar1 + 0x40),*(undefined8 *)(*plVar1 + 0x48));
      FUN_0013b0d0(*(undefined8 *)(*plVar1 + 0x50),*(undefined8 *)(*plVar1 + 0x58));
      FUN_0013b0d0(*plVar1,0x88);
      plVar1 = plVar1 + 1;
    } while (uVar2 < param_2);
    free(param_1);
    return extraout_RAX;
  }
  return 0;
}



// Function: sshsk_ecdsa_sig @ 0x9160

int sshsk_ecdsa_sig(undefined1 *param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if ((*(long *)(param_1 + 8) == 0) || (*(long *)(param_1 + 0x18) == 0)) {
    lVar2 = 0;
    iVar1 = -4;
    FUN_001203a0("ssh-sk.c","sshsk_ecdsa_sig",0x23a,1,2,0,"sk_sign response invalid");
  }
  else {
    lVar2 = FUN_0010b880();
    if (lVar2 == 0) {
      iVar1 = -2;
    }
    else {
      iVar1 = FUN_0011ba10(lVar2,*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x10));
      if ((iVar1 == 0) &&
         (iVar1 = FUN_0011ba10(lVar2,*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20)
                              ), iVar1 == 0)) {
        iVar1 = FUN_0011b840(param_2,lVar2);
        if (((iVar1 == 0) && (iVar1 = FUN_0011b180(param_2,*param_1), iVar1 == 0)) &&
           (iVar1 = FUN_0011afb0(param_2,*(undefined4 *)(param_1 + 4)), iVar1 == 0))
        goto LAB_00109207;
        uVar3 = FUN_0010b050(iVar1);
        uVar4 = 0x24d;
        pcVar5 = "compose";
      }
      else {
        uVar3 = FUN_0010b050(iVar1);
        uVar4 = 0x247;
        pcVar5 = "compose inner";
      }
      FUN_001203a0("ssh-sk.c","sshsk_ecdsa_sig",uVar4,1,2,uVar3,pcVar5);
    }
  }
LAB_00109207:
  FUN_0010bce0(lVar2);
  return iVar1;
}



// Function: sshsk_ed25519_sig @ 0x9360

int sshsk_ed25519_sig(undefined1 *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 8) == 0) {
    iVar1 = -4;
    FUN_001203a0("ssh-sk.c","sshsk_ed25519_sig",0x266,1,2,0,"sk_sign response invalid");
  }
  else {
    iVar1 = FUN_0011b6c0(param_2,*(long *)(param_1 + 8),*(undefined8 *)(param_1 + 0x10));
    if (iVar1 == 0) {
      iVar1 = FUN_0011b180(param_2,*param_1);
      if (iVar1 == 0) {
        iVar1 = FUN_0011afb0(param_2,*(undefined4 *)(param_1 + 4));
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    uVar2 = FUN_0010b050(iVar1);
    FUN_001203a0("ssh-sk.c","sshsk_ed25519_sig",0x26e,1,2,uVar2,"compose");
  }
  return iVar1;
}



// Function: sshsk_key_from_response @ 0x9d20

int sshsk_key_from_response(int param_1,char *param_2,undefined1 param_3,long param_4,long *param_5)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  long lVar5;
  long in_FS_OFFSET;
  long local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  *param_5 = 0;
  local_48 = 0;
  if ((*(long *)(param_4 + 8) == 0) || (*(long *)(param_4 + 0x18) == 0)) {
    lVar5 = 0;
    iVar1 = -4;
    FUN_001203a0("ssh-sk.c","sshsk_key_from_response",0x12d,1,2,0,"sk_enroll response invalid");
    goto LAB_00109df1;
  }
  if (param_1 == 1) {
    iVar1 = FUN_00109840(param_4,&local_48);
    lVar5 = local_48;
  }
  else {
    iVar1 = FUN_001099e0();
    lVar5 = local_48;
  }
  local_48 = lVar5;
  if (iVar1 != 0) goto LAB_00109df1;
  *(undefined1 *)(lVar5 + 0x68) = param_3;
  lVar2 = FUN_0010b880();
  *(long *)(lVar5 + 0x70) = lVar2;
  if (lVar2 == 0) {
LAB_00109f47:
    pcVar3 = "allocation failed";
    uVar4 = 0x144;
  }
  else {
    lVar2 = FUN_0010b880();
    *(long *)(lVar5 + 0x78) = lVar2;
    if (lVar2 == 0) goto LAB_00109f47;
    pcVar3 = strdup(param_2);
    *(char **)(lVar5 + 0x60) = pcVar3;
    if (pcVar3 != (char *)0x0) {
      iVar1 = FUN_0011a9d0(*(undefined8 *)(lVar5 + 0x70),*(undefined8 *)(param_4 + 0x18),
                           *(undefined8 *)(param_4 + 0x20));
      if (iVar1 == 0) {
        *param_5 = lVar5;
        lVar5 = 0;
      }
      else {
        uVar4 = FUN_0010b050(iVar1);
        FUN_001203a0("ssh-sk.c","sshsk_key_from_response",0x14f,1,2,uVar4,"put key handle");
      }
      goto LAB_00109df1;
    }
    pcVar3 = "strdup application failed";
    uVar4 = 0x149;
  }
  iVar1 = -2;
  FUN_001203a0("ssh-sk.c","sshsk_key_from_response",uVar4,1,2,0,pcVar3);
LAB_00109df1:
  FUN_00110a60(lVar5);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshsk_enroll @ 0x9fb0

int sshsk_enroll(int param_1,long param_2,undefined8 param_3,char *param_4,undefined8 param_5,
                undefined1 param_6,char *param_7,long param_8,undefined8 *param_9,long param_10)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined8 in_R11;
  undefined4 uVar7;
  long in_FS_OFFSET;
  undefined1 *local_a0;
  undefined8 local_90;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 local_68 [40];
  long local_40;
  
  pcVar5 = "";
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_80 = 0;
  local_78 = (undefined1 *)0x0;
  local_70 = 0;
  if ((param_7 != (char *)0x0) && (*param_7 != '\0')) {
    pcVar5 = " with-pin";
  }
  uVar2 = 0;
  if (param_8 != 0) {
    uVar2 = FUN_0010c3d0(param_8);
  }
  FUN_001203a0("ssh-sk.c","sshsk_enroll",0x1dc,1,5,0,
               "provider \"%s\", device \"%s\", application \"%s\", userid \"%s\", flags 0x%02x, challenge len %zu%s"
               ,param_2,param_3,param_4,param_5,param_6,uVar2,pcVar5);
  *param_9 = 0;
  if (param_10 != 0) {
    FUN_0010be60(param_10);
  }
  iVar1 = FUN_001096f0(param_3,param_5,&local_70);
  uVar2 = local_70;
  if (iVar1 != 0) {
    lVar3 = 0;
    uVar4 = 0;
    goto LAB_0010a254;
  }
  uVar7 = 0;
  if (param_1 == 10) {
LAB_0010a10c:
    if (param_2 == 0) {
      lVar3 = 0;
      FUN_001203a0("ssh-sk.c","sshsk_enroll",0x1f8,1,2,0,"missing provider",in_R11);
      iVar1 = -10;
      uVar4 = 0;
      goto LAB_0010a254;
    }
    if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {
      if (param_8 == 0) {
        FUN_001203a0("ssh-sk.c","sshsk_enroll",0x202,1,5,0,"using random challenge");
        local_a0 = local_68;
        thunk_FUN_00138930(local_a0,0x20);
        local_90 = 0x20;
      }
      else {
        lVar3 = FUN_0010c3d0(param_8);
        if (lVar3 == 0) {
          uVar4 = 0;
          pcVar5 = "Missing enrollment challenge";
          uVar6 = 0x207;
          goto LAB_0010a22f;
        }
        local_a0 = (undefined1 *)FUN_0010c520(param_8);
        local_90 = FUN_0010c3d0(param_8);
        FUN_001203a0("ssh-sk.c","sshsk_enroll",0x20d,1,7,0,"using explicit challenge len=%zd",
                     local_90);
      }
      lVar3 = FUN_00108920(param_2);
      if (lVar3 == 0) {
        iVar1 = -4;
        uVar4 = 0;
      }
      else {
        iVar1 = (**(code **)(lVar3 + 0x18))
                          (uVar7,local_a0,local_90,param_4,param_6,param_7,uVar2,&local_78);
        if (iVar1 == 0) {
          iVar1 = FUN_00109d20(uVar7,param_4,*local_78,local_78,&local_80);
          uVar4 = local_80;
          if ((iVar1 == 0) &&
             (iVar1 = FUN_001085a0(local_78,param_10), uVar4 = local_80, iVar1 == 0)) {
            *param_9 = local_80;
            uVar4 = 0;
          }
        }
        else {
          FUN_001203a0("ssh-sk.c","sshsk_enroll",0x217,1,5,0,"provider \"%s\" failure %d",param_2,
                       iVar1);
          iVar1 = FUN_00108500(iVar1);
          uVar4 = 0;
        }
      }
      goto LAB_0010a254;
    }
    pcVar5 = "missing application";
    uVar4 = 1;
    uVar6 = 0x1fd;
  }
  else {
    if (param_1 == 0xc) {
      uVar7 = 1;
      goto LAB_0010a10c;
    }
    pcVar5 = "unsupported key type";
    uVar4 = 1;
    uVar6 = 499;
  }
LAB_0010a22f:
  FUN_001203a0("ssh-sk.c","sshsk_enroll",uVar6,uVar4,2,0,pcVar5);
  iVar1 = -10;
  lVar3 = 0;
  uVar4 = 0;
LAB_0010a254:
  FUN_00108790(uVar2);
  FUN_00108870(lVar3);
  FUN_00110a60(uVar4);
  FUN_00108d30(local_78);
  __explicit_bzero_chk(local_68,0x20,0x20);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



// Function: sshsk_sign @ 0xa4d0

int sshsk_sign(long param_1,undefined4 *param_2,undefined8 *param_3,undefined8 *param_4,
                undefined8 param_5,undefined8 param_6,undefined8 param_7,char *param_8)

{
  undefined1 uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  size_t sVar10;
  void *pvVar11;
  char *pcVar12;
  long in_FS_OFFSET;
  undefined4 local_58;
  undefined8 local_48;
  long local_40;
  
  pcVar12 = "";
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = 0;
  if ((param_8 != (char *)0x0) && (*param_8 != '\0')) {
    pcVar12 = " with-pin";
  }
  uVar1 = *(undefined1 *)(param_2 + 0x1a);
  uVar6 = FUN_0010e880(param_2);
  FUN_001203a0("ssh-sk.c","sshsk_sign",0x286,1,5,0,"provider \"%s\", key %s, flags 0x%02x%s",param_1
               ,uVar6,uVar1,pcVar12);
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  iVar3 = FUN_0010f440(*param_2);
  if (iVar3 == 10) {
    local_58 = 0;
    if (param_1 != 0) goto LAB_0010a5d2;
LAB_0010a6f1:
    lVar9 = 0;
    iVar5 = -10;
  }
  else {
    iVar5 = -10;
    if (iVar3 != 0xc) goto LAB_0010a639;
    local_58 = 1;
    if (param_1 == 0) goto LAB_0010a6f1;
LAB_0010a5d2:
    if ((*(long *)(param_2 + 0x1c) == 0) || (*(char **)(param_2 + 0x18) == (char *)0x0)) {
      lVar9 = 0;
      param_1 = 0;
      iVar5 = -10;
    }
    else if (**(char **)(param_2 + 0x18) == '\0') {
      lVar9 = 0;
      param_1 = 0;
      iVar5 = -10;
    }
    else {
      param_1 = FUN_00108920(param_1);
      if (param_1 == 0) {
        lVar9 = 0;
        iVar5 = -4;
      }
      else {
        pcVar2 = *(code **)(param_1 + 0x20);
        uVar1 = *(undefined1 *)(param_2 + 0x1a);
        uVar6 = FUN_0010c3d0(*(undefined8 *)(param_2 + 0x1c));
        uVar7 = FUN_0010c520(*(undefined8 *)(param_2 + 0x1c));
        uVar8 = (*pcVar2)(local_58,param_5,param_6,*(undefined8 *)(param_2 + 0x18),uVar7,uVar6,uVar1
                          ,param_8,0,&local_48);
        if ((int)uVar8 == 0) {
          lVar9 = FUN_0010b880();
          iVar5 = -2;
          if (lVar9 != 0) {
            uVar6 = FUN_0010f8b0(param_2);
            iVar4 = FUN_0011b800(lVar9,uVar6);
            if (iVar4 == 0) {
              if (iVar3 == 10) {
                iVar5 = FUN_00109160(local_48,lVar9);
joined_r0x0010a96a:
                if (iVar5 != 0) goto LAB_0010a602;
              }
              else if (iVar3 == 0xc) {
                iVar5 = FUN_00109360(local_48,lVar9);
                goto joined_r0x0010a96a;
              }
              if (param_3 != (undefined8 *)0x0) {
                sVar10 = FUN_0010c3d0(lVar9);
                pvVar11 = malloc(sVar10);
                *param_3 = pvVar11;
                if (pvVar11 == (void *)0x0) {
                  iVar5 = -2;
                  goto LAB_0010a602;
                }
                sVar10 = FUN_0010c3d0(lVar9);
                pvVar11 = (void *)FUN_0010c520(lVar9);
                memcpy((void *)*param_3,pvVar11,sVar10);
              }
              iVar5 = iVar4;
              if (param_4 != (undefined8 *)0x0) {
                uVar6 = FUN_0010c3d0(lVar9);
                *param_4 = uVar6;
              }
            }
            else {
              uVar6 = FUN_0010b050(iVar4);
              FUN_001203a0("ssh-sk.c","sshsk_sign",0x2b8,1,2,uVar6,"compose outer");
              iVar5 = iVar4;
            }
          }
        }
        else {
          FUN_001203a0("ssh-sk.c","sshsk_sign",0x2ae,1,5,0,"sk_sign failed with code %d",uVar8);
          iVar5 = FUN_00108500(uVar8 & 0xffffffff);
          lVar9 = 0;
        }
      }
    }
  }
LAB_0010a602:
  FUN_00108790(0);
  FUN_00108870(param_1);
  FUN_00108e10(local_48);
  FUN_0010bce0(lVar9);
  FUN_0010bce0(0);
LAB_0010a639:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshsk_free_resident_keys @ 0xa990

undefined8 sshsk_free_resident_keys(void *param_1,ulong param_2)

{
  long lVar1;
  undefined8 extraout_RAX;
  ulong uVar2;
  
  if (param_1 == (void *)0x0) {
    return 0;
  }
  if (param_2 != 0) {
    uVar2 = 0;
    do {
      lVar1 = uVar2 * 8;
      uVar2 = uVar2 + 1;
      FUN_00108ed0(*(undefined8 *)((long)param_1 + lVar1));
    } while (uVar2 < param_2);
    free(param_1);
    return extraout_RAX;
  }
  return 0;
}



// Function: sshsk_load_resident @ 0xaae0

int sshsk_load_resident(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4,
                long *param_5,long *param_6)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  char *pcVar4;
  undefined8 *puVar5;
  void *__dest;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  long *plVar9;
  long lVar10;
  long in_FS_OFFSET;
  long local_a8;
  long local_a0;
  int local_8c;
  long local_78;
  undefined8 local_70;
  long local_60;
  ulong local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar4 = "";
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    pcVar4 = ", have-pin";
  }
  FUN_001203a0("ssh-sk.c","sshsk_load_resident",0x31d,1,5,0,"provider \"%s\"%s",param_1,pcVar4);
  if ((param_5 == (long *)0x0) || (param_6 == (long *)0x0)) {
    local_8c = -10;
  }
  else {
    *param_5 = 0;
    *param_6 = 0;
    local_8c = FUN_001096f0(param_2,0,&local_48);
    if (local_8c == 0) {
      local_78 = FUN_00108920(param_1);
      local_70 = local_48;
      if (local_78 == 0) {
        local_a0 = 0;
        local_a8 = 0;
        puVar5 = (undefined8 *)0x0;
        lVar10 = 0;
        local_8c = -4;
      }
      else {
        iVar3 = (**(code **)(local_78 + 0x28))(param_3,local_48,&local_60,&local_58);
        if (iVar3 == 0) {
          if (local_58 == 0) {
            local_a0 = 0;
            uVar7 = 0;
            lVar10 = 0;
          }
          else {
            uVar8 = 0;
            local_a0 = 0;
            local_a8 = 0;
            do {
              lVar10 = local_a8;
              puVar1 = *(undefined4 **)(local_60 + uVar8 * 8);
              FUN_001203a0("ssh-sk.c","sshsk_load_resident",0x331,1,7,0,
                           "rk %zu: slot %zu, alg %d, app \"%s\", uidlen %zu",uVar8,
                           *(undefined8 *)(puVar1 + 2),*puVar1,*(undefined8 *)(puVar1 + 4),
                           *(undefined8 *)(puVar1 + 0x20));
              puVar2 = *(uint **)(local_60 + uVar8 * 8);
              pcVar4 = *(char **)(puVar2 + 4);
              iVar3 = strncmp(pcVar4,"ssh:",4);
              if ((iVar3 == 0) && (*puVar2 < 2)) {
                local_8c = FUN_00109d20(*puVar2,pcVar4,
                                        (-(uint)((puVar2[0x1c] & 4) == 0) & 0xfffffffc) + 0x25,
                                        puVar2 + 6,&local_50);
                if (local_8c == 0) {
                  puVar5 = calloc(1,0x18);
                  if (puVar5 == (undefined8 *)0x0) {
                    local_a8 = local_50;
                    uVar7 = 0x345;
                    pcVar4 = "calloc failed";
                  }
                  else {
                    *puVar5 = local_50;
                    local_50 = 0;
                    __dest = calloc(1,*(size_t *)(*(long *)(local_60 + uVar8 * 8) + 0x80));
                    puVar5[1] = __dest;
                    if (__dest == (void *)0x0) {
                      uVar7 = 0x34c;
                      pcVar4 = "calloc failed";
                      local_a8 = 0;
                    }
                    else {
                      plVar9 = (long *)(uVar8 * 8 + local_60);
                      lVar6 = *plVar9;
                      memcpy(__dest,*(void **)(lVar6 + 0x78),*(size_t *)(lVar6 + 0x80));
                      puVar5[2] = *(undefined8 *)(*plVar9 + 0x80);
                      lVar6 = FUN_0013ba50(local_a0,local_a8,local_a8 + 1,8);
                      if (lVar6 != 0) {
                        *(undefined8 **)(lVar6 + local_a8 * 8) = puVar5;
                        local_a8 = local_a8 + 1;
                        local_a0 = lVar6;
                        goto LAB_0010aeb6;
                      }
                      uVar7 = 0x354;
                      pcVar4 = "recallocarray failed";
                      local_a8 = 0;
                    }
                  }
                  FUN_001203a0("ssh-sk.c","sshsk_load_resident",uVar7,1,2,0,pcVar4);
                  local_8c = -2;
                }
                else {
                  puVar5 = (undefined8 *)0x0;
                  local_a8 = local_50;
                }
                goto LAB_0010abfd;
              }
LAB_0010aeb6:
              uVar8 = uVar8 + 1;
              uVar7 = local_50;
              lVar10 = local_a8;
            } while (uVar8 < local_58);
          }
          local_a8 = uVar7;
          lVar6 = local_a0;
          puVar5 = (undefined8 *)0x0;
          local_a0 = 0;
          *param_5 = lVar6;
          *param_6 = lVar10;
          lVar10 = 0;
          local_8c = 0;
        }
        else {
          lVar10 = 0;
          FUN_001203a0("ssh-sk.c","sshsk_load_resident",0x32c,0,2,0,
                       "Provider \"%s\" returned failure %d",param_1,iVar3);
          puVar5 = (undefined8 *)0x0;
          local_8c = FUN_00108500(iVar3);
          local_a8 = 0;
          local_a0 = 0;
        }
      }
    }
    else {
      local_a8 = 0;
      puVar5 = (undefined8 *)0x0;
      lVar10 = 0;
      local_a0 = 0;
      local_70 = local_48;
      local_78 = 0;
    }
LAB_0010abfd:
    FUN_00108790(local_70);
    FUN_00108870(local_78);
    FUN_00108f80(local_60,local_58);
    FUN_00110a60(local_a8);
    FUN_00108ed0(puVar5);
    FUN_0010a990(local_a0,lVar10);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_8c;
}



// Function: ssh_err @ 0xb050

char * ssh_err(undefined8 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  char *pcVar3;
  
  uVar1 = FUN_0013da20(param_1,0x3c);
  switch(uVar1) {
  case 0:
    pcVar3 = "device not found";
    break;
  case 1:
    pcVar3 = "requested feature not supported";
    break;
  case 2:
    pcVar3 = "signature algorithm not supported";
    break;
  case 3:
    pcVar3 = "number is too large";
    break;
  case 4:
    pcVar3 = "Invalid key length";
    break;
  case 5:
    pcVar3 = "Protocol error";
    break;
  case 6:
    pcVar3 = "Connection corrupted";
    break;
  case 7:
    pcVar3 = "Connection timed out";
    break;
  case 8:
    pcVar3 = "Connection closed";
    break;
  case 9:
    pcVar3 = "Key is revoked";
    break;
  case 10:
    pcVar3 = "KRL file has invalid magic number";
    break;
  case 0xb:
    pcVar3 = "internal error: buffer is read-only";
    break;
  case 0xc:
    pcVar3 = "agent contains no identities";
    break;
  case 0xd:
    pcVar3 = "agent not present";
    break;
  case 0xe:
    pcVar3 = "key not found";
    break;
  case 0xf:
    pcVar3 = "certificate does not match key";
    break;
  case 0x10:
    pcVar3 = "bad permissions";
    break;
  case 0x11:
    pcVar3 = "incorrect passphrase supplied to decrypt private key";
    break;
  case 0x12:
    pcVar3 = "key encrypted using unsupported cipher";
    break;
  case 0x13:
    pcVar3 = "file changed while reading";
    break;
  case 0x14:
    pcVar3 = "passphrase is too short (minimum five characters)";
    break;
  case 0x15:
    pcVar3 = "rekeying not supported by peer";
    break;
  case 0x16:
    pcVar3 = "could not read protocol version";
    break;
  case 0x17:
    pcVar3 = "protocol version mismatch";
    break;
  case 0x18:
    pcVar3 = "could not load host key";
    break;
  case 0x19:
    pcVar3 = "no matching host key type found";
    break;
  case 0x1a:
    pcVar3 = "no matching key exchange method found";
    break;
  case 0x1b:
    pcVar3 = "no matching compression method found";
    break;
  case 0x1c:
    pcVar3 = "no matching MAC found";
    break;
  case 0x1d:
    pcVar3 = "no matching cipher found";
    break;
  case 0x1e:
    pcVar3 = "message authentication code incorrect";
    break;
  case 0x1f:
    pcVar3 = "disconnected";
    break;
  case 0x20:
    pcVar3 = "DH GEX group out of range";
    break;
  case 0x21:
    pcVar3 = "agent refused operation";
    break;
  case 0x22:
    pcVar3 = "communication with agent failed";
    break;
  case 0x23:
    pcVar3 = "invalid certificate";
    break;
  case 0x24:
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    return pcVar3;
  case 0x25:
    pcVar3 = "unexpected bytes remain after decoding";
    break;
  case 0x26:
    pcVar3 = "error in libcrypto";
    break;
  case 0x27:
    pcVar3 = "incorrect signature";
    break;
  case 0x28:
    pcVar3 = "invalid elliptic curve value";
    break;
  case 0x29:
    pcVar3 = "invalid certificate signing key";
    break;
  case 0x2a:
    pcVar3 = "unknown/unsupported certificate type";
    break;
  case 0x2b:
    pcVar3 = "key lacks certificate data";
    break;
  case 0x2c:
    pcVar3 = "plain key provided where certificate required";
    break;
  case 0x2d:
    pcVar3 = "elliptic curve does not match";
    break;
  case 0x2e:
    pcVar3 = "unknown or unsupported key type";
    break;
  case 0x2f:
    pcVar3 = "key type does not match";
    break;
  case 0x30:
    pcVar3 = "invalid elliptic curve";
    break;
  case 0x31:
    pcVar3 = "key bits do not match";
    break;
  case 0x32:
    pcVar3 = "invalid argument";
    break;
  case 0x33:
    pcVar3 = "insufficient buffer space";
    break;
  case 0x34:
    pcVar3 = "elliptic curve point is too large";
    break;
  case 0x35:
    pcVar3 = "bignum is too large";
    break;
  case 0x36:
    pcVar3 = "string is too large";
    break;
  case 0x37:
    pcVar3 = "bignum is negative";
    break;
  case 0x38:
    pcVar3 = "invalid format";
    break;
  case 0x39:
    pcVar3 = "incomplete message";
    break;
  case 0x3a:
    pcVar3 = "memory allocation failed";
    break;
  case 0x3b:
    pcVar3 = "unexpected internal error";
    break;
  case 0x3c:
    pcVar3 = "success";
    break;
  default:
    pcVar3 = "unknown error";
  }
  return pcVar3;
}



// Function: sshbuf_check_sanity @ 0xb4e0

undefined8 sshbuf_check_sanity(long *param_1)

{
  if ((((param_1 != (long *)0x0) &&
       (((((int)param_1[6] != 0 || (*param_1 == param_1[1])) && ((int)param_1[7] - 1U < 0x100000))
        && ((param_1[1] != 0 && ((ulong)param_1[4] < 0x8000001)))))) &&
      ((ulong)param_1[5] <= (ulong)param_1[4])) &&
     (((ulong)param_1[3] <= (ulong)param_1[5] && ((ulong)param_1[2] <= (ulong)param_1[3])))) {
    return 0;
  }
  FUN_0012ad90(0xb,0);
  raise(0xb);
  return 0xffffffff;
}



// Function: sshbuf_maybe_pack @ 0xb680

undefined8 sshbuf_maybe_pack(undefined8 *param_1,int param_2)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = param_1[2];
  if (uVar1 == 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 6) != 0) || (1 < *(uint *)(param_1 + 7))) {
    return 0;
  }
  if (param_2 == 0) {
    if (uVar1 < 0x2000) {
      return 0;
    }
    uVar2 = param_1[3];
    if (uVar1 < uVar2 >> 1) {
      return 0;
    }
  }
  else {
    uVar2 = param_1[3];
  }
  memmove((void *)*param_1,(void *)((long)*param_1 + uVar1),uVar2 - uVar1);
  param_1[3] = param_1[3] - param_1[2];
  param_1[2] = 0;
  return 0;
}



// Function: sshbuf_new @ 0xb880

undefined8 * sshbuf_new(void)

{
  undefined8 *__ptr;
  void *pvVar1;
  undefined8 *puVar2;
  
  __ptr = calloc(0x48,1);
  puVar2 = __ptr;
  if (__ptr != (undefined8 *)0x0) {
    __ptr[5] = 0x100;
    __ptr[4] = 0x8000000;
    *(undefined4 *)(__ptr + 6) = 0;
    *(undefined4 *)(__ptr + 7) = 1;
    __ptr[8] = 0;
    pvVar1 = calloc(1,0x100);
    *__ptr = pvVar1;
    __ptr[1] = pvVar1;
    if (pvVar1 == (void *)0x0) {
      puVar2 = (undefined8 *)0x0;
      free(__ptr);
    }
  }
  return puVar2;
}



// Function: sshbuf_from @ 0xb980

undefined8 * sshbuf_from(long param_1,ulong param_2)

{
  undefined8 *puVar1;
  
  if (param_1 == 0) {
    return (undefined8 *)0x0;
  }
  if (param_2 < 0x8000001) {
    puVar1 = calloc(0x48,1);
    if (puVar1 != (undefined8 *)0x0) {
      puVar1[4] = param_2;
      puVar1[3] = param_2;
      puVar1[5] = param_2;
      *(undefined4 *)(puVar1 + 6) = 1;
      *(undefined4 *)(puVar1 + 7) = 1;
      puVar1[8] = 0;
      puVar1[1] = param_1;
      *puVar1 = 0;
    }
    return puVar1;
  }
  return (undefined8 *)0x0;
}



// Function: sshbuf_set_parent @ 0xbb80

undefined8 sshbuf_set_parent(long param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_0010b4e0();
  if ((int)uVar1 == 0) {
    uVar1 = FUN_0010b4e0(param_2);
    if ((int)uVar1 == 0) {
      if ((*(long *)(param_1 + 0x40) == 0) || (*(long *)(param_1 + 0x40) == param_2)) {
        *(long *)(param_1 + 0x40) = param_2;
        *(int *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) + 1;
        return uVar1;
      }
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}



// Function: sshbuf_free @ 0xbce0

undefined8 sshbuf_free(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (undefined8 *)0x0) {
    return 0;
  }
  iVar2 = FUN_0010b4e0();
  if (iVar2 == 0) {
    piVar1 = (int *)(param_1 + 7);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      sshbuf_free(param_1[8]);
      param_1[8] = 0;
      if (*(int *)(param_1 + 6) == 0) {
        __explicit_bzero_chk(*param_1,param_1[5],0xffffffffffffffff);
        free((void *)*param_1);
      }
      uVar3 = FUN_0013b0d0(param_1,0x48);
      return uVar3;
    }
  }
  return 0;
}



// Function: sshbuf_reset @ 0xbe60

undefined8 sshbuf_reset(long *param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (((int)param_1[6] == 0) && (*(uint *)(param_1 + 7) < 2)) {
    iVar1 = FUN_0010b4e0();
    if (iVar1 == 0) {
      lVar4 = param_1[5];
      lVar2 = *param_1;
      param_1[3] = 0;
      param_1[2] = 0;
      if (lVar4 != 0x100) {
        lVar2 = FUN_0013ba50(lVar2,lVar4,0x100,1);
        if (lVar2 == 0) {
          lVar4 = param_1[5];
          lVar2 = *param_1;
        }
        else {
          *param_1 = lVar2;
          lVar4 = 0x100;
          param_1[1] = lVar2;
          param_1[5] = 0x100;
        }
      }
      uVar3 = __explicit_bzero_chk(lVar2,lVar4,0xffffffffffffffff);
      return uVar3;
    }
  }
  else {
    param_1[2] = param_1[3];
  }
  return 0;
}



// Function: sshbuf_max_size @ 0xbf80

undefined8 sshbuf_max_size(long param_1)

{
  return *(undefined8 *)(param_1 + 0x20);
}



// Function: sshbuf_alloc @ 0xc010

undefined8 sshbuf_alloc(long param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}



// Function: sshbuf_parent @ 0xc0a0

undefined8 sshbuf_parent(long param_1)

{
  return *(undefined8 *)(param_1 + 0x40);
}



// Function: sshbuf_refcount @ 0xc130

undefined4 sshbuf_refcount(long param_1)

{
  return *(undefined4 *)(param_1 + 0x38);
}



// Function: sshbuf_set_max_size @ 0xc1c0

int sshbuf_set_max_size(long *param_1,ulong param_2)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  
  iVar2 = FUN_0010b4e0();
  if ((iVar2 == 0) && (param_1[4] != param_2)) {
    if (((int)param_1[6] == 0) && (*(uint *)(param_1 + 7) < 2)) {
      if (0x8000000 < param_2) {
        return -9;
      }
      FUN_0010b680(param_1,param_2 < (ulong)param_1[3]);
      if (param_2 < (ulong)param_1[5]) {
        uVar1 = param_1[3];
        if (param_2 <= uVar1) {
          return -9;
        }
        uVar4 = uVar1 + 0xff & 0xffffffffffffff00;
        if (uVar1 < 0x100) {
          uVar4 = 0x100;
        }
        if (param_2 < uVar4) {
          uVar4 = param_2;
        }
        lVar3 = FUN_0013ba50(*param_1,param_1[5],uVar4,1);
        if (lVar3 == 0) {
          return -2;
        }
        *param_1 = lVar3;
        param_1[1] = lVar3;
        param_1[5] = uVar4;
        if (param_2 < uVar4) {
          return -9;
        }
      }
      param_1[4] = param_2;
      iVar2 = 0;
    }
    else {
      iVar2 = -0x31;
    }
  }
  return iVar2;
}



// Function: sshbuf_len @ 0xc3d0

long sshbuf_len(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = FUN_0010b4e0();
  lVar2 = 0;
  if (iVar1 == 0) {
    lVar2 = *(long *)(param_1 + 0x18) - *(long *)(param_1 + 0x10);
  }
  return lVar2;
}



// Function: sshbuf_avail @ 0xc470

long sshbuf_avail(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = FUN_0010b4e0();
  lVar2 = 0;
  if (((iVar1 == 0) && (*(int *)(param_1 + 0x30) == 0)) && (*(uint *)(param_1 + 0x38) < 2)) {
    lVar2 = (*(long *)(param_1 + 0x10) + *(long *)(param_1 + 0x20)) - *(long *)(param_1 + 0x18);
  }
  return lVar2;
}



// Function: sshbuf_ptr @ 0xc520

long sshbuf_ptr(long param_1)

{
  int iVar1;
  
  iVar1 = FUN_0010b4e0();
  if (iVar1 == 0) {
    return *(long *)(param_1 + 0x10) + *(long *)(param_1 + 8);
  }
  return 0;
}



// Function: sshbuf_fromb @ 0xc640

long sshbuf_fromb(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  iVar1 = FUN_0010b4e0();
  if (iVar1 == 0) {
    uVar2 = FUN_0010c3d0(param_1);
    uVar3 = FUN_0010c520(param_1);
    lVar4 = FUN_0010b980(uVar3,uVar2);
    if (lVar4 != 0) {
      iVar1 = FUN_0010bb80(lVar4,param_1);
      if (iVar1 == 0) {
        return lVar4;
      }
      FUN_0010bce0(lVar4);
    }
  }
  return 0;
}



// Function: sshbuf_mutable_ptr @ 0xc7c0

long sshbuf_mutable_ptr(long *param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = FUN_0010b4e0();
  lVar2 = 0;
  if (((iVar1 == 0) && ((int)param_1[6] == 0)) && (*(uint *)(param_1 + 7) < 2)) {
    lVar2 = param_1[2] + *param_1;
  }
  return lVar2;
}



// Function: sshbuf_check_reserve @ 0xc870

undefined8 sshbuf_check_reserve(long param_1,ulong param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_0010b4e0();
  if ((int)uVar1 == 0) {
    if ((*(int *)(param_1 + 0x30) == 0) && (*(uint *)(param_1 + 0x38) < 2)) {
      if (*(ulong *)(param_1 + 0x20) < param_2) {
        uVar1 = 0xfffffff7;
      }
      else {
        uVar1 = 0;
        if (*(ulong *)(param_1 + 0x20) - param_2 <
            (ulong)(*(long *)(param_1 + 0x18) - *(long *)(param_1 + 0x10))) {
          uVar1 = 0xfffffff7;
        }
      }
    }
    else {
      uVar1 = 0xffffffcf;
    }
  }
  return uVar1;
}



// Function: sshbuf_allocate @ 0xc960

int sshbuf_allocate(long *param_1,long param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  
  iVar1 = FUN_0010c870();
  if (iVar1 == 0) {
    FUN_0010b680(param_1,(ulong)param_1[4] < (ulong)(param_1[3] + param_2));
    uVar3 = param_1[3] + param_2;
    if ((ulong)param_1[5] < uVar3) {
      uVar5 = uVar3 + 0xff & 0xffffffffffffff00;
      if ((ulong)param_1[4] < uVar5) {
        uVar5 = uVar3;
      }
      lVar4 = FUN_0013ba50(*param_1,param_1[5],uVar5,1);
      if (lVar4 != 0) {
        param_1[5] = uVar5;
        *param_1 = lVar4;
        param_1[1] = lVar4;
        iVar2 = FUN_0010c870(param_1,param_2);
        iVar1 = 0;
        if (iVar2 < 1) {
          iVar1 = iVar2;
        }
        return iVar1;
      }
      iVar1 = -2;
    }
  }
  return iVar1;
}



// Function: sshbuf_reserve @ 0xcb20

undefined8 sshbuf_reserve(long *param_1,long param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  
  if (param_3 == (long *)0x0) {
    iVar2 = FUN_0010c960();
    if (iVar2 == 0) {
      param_1[3] = param_1[3] + param_2;
      return 0;
    }
  }
  else {
    *param_3 = 0;
    iVar2 = FUN_0010c960();
    if (iVar2 == 0) {
      lVar1 = param_1[3];
      param_1[3] = param_2 + lVar1;
      *param_3 = *param_1 + lVar1;
    }
  }
  return 0;
}



// Function: sshbuf_consume @ 0xcc80

int sshbuf_consume(long param_1,ulong param_2)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  iVar1 = FUN_0010b4e0();
  if ((iVar1 == 0) && (param_2 != 0)) {
    uVar2 = FUN_0010c3d0(param_1);
    if (uVar2 < param_2) {
      iVar1 = -3;
    }
    else {
      lVar3 = param_2 + *(long *)(param_1 + 0x10);
      *(long *)(param_1 + 0x10) = lVar3;
      if (lVar3 == *(long *)(param_1 + 0x18)) {
        *(undefined8 *)(param_1 + 0x18) = 0;
        *(undefined8 *)(param_1 + 0x10) = 0;
        return 0;
      }
    }
  }
  return iVar1;
}



// Function: sshbuf_consume_end @ 0xce00

int sshbuf_consume_end(long param_1,ulong param_2)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = FUN_0010b4e0();
  if ((iVar1 == 0) && (param_2 != 0)) {
    uVar2 = FUN_0010c3d0(param_1);
    if (param_2 <= uVar2) {
      *(long *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) - param_2;
      return 0;
    }
    iVar1 = -3;
  }
  return iVar1;
}



// Function: sshkey_ssh_name_from_type_nid @ 0xd0a0

char * sshkey_ssh_name_from_type_nid(int param_1,int param_2)

{
  undefined **ppuVar1;
  int iVar2;
  
  ppuVar1 = &PTR_s_ssh_ed25519_00166cc0;
  iVar2 = 3;
  while ((param_1 != iVar2 ||
         ((*(int *)((long)ppuVar1 + 0x1c) != param_2 && (*(int *)((long)ppuVar1 + 0x1c) != 0))))) {
    iVar2 = *(int *)(ppuVar1 + 8);
    ppuVar1 = ppuVar1 + 5;
    if (iVar2 == -1) {
      return "ssh-unknown";
    }
  }
  return *ppuVar1;
}



// Function: key_type_is_ecdsa_variant @ 0xd1e0

uint key_type_is_ecdsa_variant(uint param_1)

{
  if (param_1 < 0xc) {
    return (uint)(0xc44L >> ((byte)param_1 & 0x3f)) & 1;
  }
  return 0;
}



// Function: sshkey_type_is_valid_ca @ 0xd300

uint sshkey_type_is_valid_ca(uint param_1)

{
  if (param_1 < 0xd) {
    return (uint)(0x150fL >> ((byte)param_1 & 0x3f)) & 1;
  }
  return 0;
}



// Function: translate_libcrypto_error @ 0xd420

int translate_libcrypto_error(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_0010d000();
  iVar2 = FUN_0010cf60(param_1);
  if (iVar2 == 9) {
    if (iVar1 - 0x65U < 9) {
      return (-(uint)((0x109UL >> ((byte)(iVar1 - 0x65U) & 0x3f) & 1) == 0) & 0x27) - 0x2b;
    }
    iVar3 = -4;
  }
  else {
    iVar3 = -4;
    if (iVar2 != 0xd) {
      if (iVar2 == 6) {
        if ((iVar1 != 0x72) && (iVar1 != 0x91)) {
          iVar2 = -0x16;
          if (iVar1 == 100) {
            iVar2 = -0x2b;
          }
          return iVar2;
        }
      }
      else {
        iVar3 = -0x16;
      }
    }
  }
  return iVar3;
}



// Function: pem_passphrase_cb @ 0xd650

ulong pem_passphrase_cb(void *param_1,int param_2,undefined8 param_3,char *param_4)

{
  size_t __n;
  ulong uVar1;
  
  if (param_4 != (char *)0x0) {
    __n = strlen(param_4);
    if (((param_2 < 0) || (__n == 0)) || ((ulong)(long)param_2 < __n)) {
      uVar1 = 0xffffffff;
    }
    else {
      memcpy(param_1,param_4,__n);
      uVar1 = __n & 0xffffffff;
    }
    return uVar1;
  }
  return 0xffffffff;
}



// Function: fingerprint_bubblebabble @ 0xd7c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * fingerprint_bubblebabble(long param_1,ulong param_2)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  long in_FS_OFFSET;
  undefined4 local_5e;
  undefined2 local_5a;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined1 local_48;
  long local_40;
  
  uVar4 = (uint)(param_2 >> 1);
  uVar10 = uVar4 + 1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_5e = 0x6f696561;
  local_5a = 0x7975;
  local_48 = 0x78;
  local_58 = _DAT_0013f920;
  uStack_50 = _UNK_0013f928;
  puVar6 = calloc((ulong)uVar10,6);
  if (puVar6 != (undefined1 *)0x0) {
    *puVar6 = 0x78;
    if (uVar10 == 0) {
      uVar7 = 2;
      uVar9 = 1;
    }
    else {
      uVar13 = 0;
      uVar12 = 1;
      uVar5 = 1;
      uVar11 = 1;
      uVar8 = 1;
      uVar14 = uVar13;
      if (uVar10 < 2) goto LAB_0010d962;
      do {
        do {
          uVar13 = uVar11;
          bVar2 = *(byte *)(param_1 + (ulong)(uVar12 - 1));
          puVar6[uVar8] = *(undefined1 *)((long)&local_5e + (ulong)(((bVar2 >> 6) + uVar5) % 6));
          uVar9 = (ulong)(uVar8 + 3);
          puVar6[uVar8 + 1] = *(undefined1 *)((long)&local_58 + (ulong)(bVar2 >> 2 & 0xf));
          puVar6[uVar8 + 2] =
               *(undefined1 *)((long)&local_5e + (ulong)((uVar5 / 6 + (bVar2 & 3)) % 6));
          if (uVar4 == uVar14) goto LAB_0010d9a9;
          uVar7 = (ulong)uVar12;
          uVar12 = uVar12 + 2;
          bVar3 = *(byte *)(param_1 + uVar7);
          uVar11 = uVar13 + 1;
          puVar6[uVar9] = *(undefined1 *)((long)&local_58 + (ulong)(bVar3 >> 4));
          uVar14 = uVar8 + 4;
          uVar1 = uVar8 + 5;
          uVar8 = uVar8 + 6;
          puVar6[uVar14] = 0x2d;
          puVar6[uVar1] = *(undefined1 *)((long)&local_58 + (ulong)(bVar3 & 0xf));
          uVar5 = ((uVar5 * 5 + (uint)bVar3 + (uint)bVar2 * 8) - (uint)bVar2) % 0x24;
          uVar14 = uVar13;
        } while (uVar11 < uVar10);
LAB_0010d962:
        uVar14 = uVar13;
      } while ((param_2 & 1) != 0);
      uVar9 = (ulong)(uVar8 + 3);
      puVar6[uVar8] = *(undefined1 *)((long)&local_5e + (ulong)(uVar5 % 6));
      puVar6[uVar8 + 1] = 0x78;
      puVar6[uVar8 + 2] = *(undefined1 *)((long)&local_5e + (ulong)uVar5 / 6);
LAB_0010d9a9:
      uVar7 = (ulong)((int)uVar9 + 1);
    }
    puVar6[uVar9] = 0x78;
    puVar6[uVar7] = 0;
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar6;
}



// Function: cert_compare @ 0xda80

bool cert_compare(undefined8 *param_1,undefined8 *param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  if (param_1 == (undefined8 *)0x0 && param_2 == (undefined8 *)0x0) {
    return true;
  }
  if ((param_1 != (undefined8 *)0x0) && (param_2 != (undefined8 *)0x0)) {
    lVar2 = FUN_0010c3d0(*param_1);
    lVar3 = FUN_0010c3d0(*param_2);
    if (lVar2 == lVar3) {
      uVar4 = FUN_0010c3d0(*param_1);
      uVar5 = FUN_0010c520(*param_2);
      uVar6 = FUN_0010c520(*param_1);
      iVar1 = FUN_0013c1c0(uVar6,uVar5,uVar4);
      return iVar1 == 0;
    }
  }
  return false;
}



// Function: fingerprint_hex @ 0xdc80

void * fingerprint_hex(char *param_1,undefined1 *param_2,ulong param_3)

{
  undefined1 uVar1;
  size_t sVar2;
  void *pvVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  long in_FS_OFFSET;
  undefined1 local_45 [5];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sVar2 = strlen(param_1);
  if (param_3 < 0x10001) {
    sVar2 = param_3 * 3 + 2 + sVar2;
    pvVar3 = calloc(1,sVar2);
    if (pvVar3 != (void *)0x0) {
      FUN_0013bee0(pvVar3,param_1,sVar2);
      FUN_0013bcf0(pvVar3,&DAT_0013e4d8,sVar2);
      if (param_3 != 0) {
        uVar1 = *param_2;
        puVar4 = &DAT_0013f156;
        puVar5 = param_2 + param_3;
        while( true ) {
          param_2 = param_2 + 1;
          __snprintf_chk(local_45,5,1,5,&DAT_0013f068,puVar4,uVar1);
          FUN_0013bcf0(pvVar3,local_45,sVar2);
          if (param_2 == puVar5) break;
          uVar1 = *param_2;
          puVar4 = &DAT_0013e4d8;
        }
      }
      goto LAB_0010dd64;
    }
  }
  pvVar3 = (void *)0x0;
LAB_0010dd64:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pvVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: fingerprint_b64 @ 0xde20

char * fingerprint_b64(char *param_1,undefined8 param_2,ulong param_3)

{
  size_t __size;
  long lVar1;
  int iVar2;
  size_t sVar3;
  char *__s;
  
  sVar3 = strlen(param_1);
  if (param_3 < 0x10001) {
    lVar1 = sVar3 + 1 + ((param_3 + 2) / 3) * 4;
    __size = lVar1 + 1;
    __s = calloc(1,__size);
    if (__s != (char *)0x0) {
      FUN_0013bee0(__s,param_1,__size);
      FUN_0013bcf0(__s,&DAT_0013e4d8,__size);
      if (param_3 == 0) {
        return __s;
      }
      iVar2 = FUN_00138b30(param_2,param_3,__s + sVar3 + 1,lVar1 - sVar3);
      if (iVar2 != -1) {
        sVar3 = strcspn(__s,"=");
        __s[sVar3] = '\0';
        return __s;
      }
      FUN_0013b0d0(__s,__size);
    }
  }
  return (char *)0x0;
}



// Function: dsa_generate_private_key @ 0xdfa0

undefined8 dsa_generate_private_key(int param_1,undefined8 *param_2)

{
  int iVar1;
  DSA *dsa;
  undefined8 uVar2;
  
  if (param_1 == 0x400) {
    uVar2 = 0xfffffffe;
    dsa = DSA_new();
    if (dsa != (DSA *)0x0) {
      *param_2 = 0;
      uVar2 = 0xffffffea;
      iVar1 = DSA_generate_parameters_ex
                        (dsa,0x400,(uchar *)0x0,0,(int *)0x0,(ulong *)0x0,(BN_GENCB *)0x0);
      if (iVar1 != 0) {
        iVar1 = DSA_generate_key(dsa);
        if (iVar1 != 0) {
          *param_2 = dsa;
          uVar2 = 0;
          dsa = (DSA *)0x0;
        }
      }
    }
    DSA_free(dsa);
  }
  else {
    uVar2 = 0xffffffc8;
  }
  return uVar2;
}



// Function: rsa_generate_private_key @ 0xe0c0

undefined8 rsa_generate_private_key(int param_1,undefined8 *param_2)

{
  int iVar1;
  RSA *rsa;
  BIGNUM *a;
  undefined8 uVar2;
  
  if (param_1 - 0x400U < 0x3c01) {
    *param_2 = 0;
    rsa = RSA_new();
    if (rsa == (RSA *)0x0) {
      a = (BIGNUM *)0x0;
      uVar2 = 0xfffffffe;
    }
    else {
      a = BN_new();
      uVar2 = 0xfffffffe;
      if (a != (BIGNUM *)0x0) {
        uVar2 = 0xffffffea;
        iVar1 = BN_set_word(a,0x10001);
        if (iVar1 != 0) {
          iVar1 = RSA_generate_key_ex(rsa,param_1,a,(BN_GENCB *)0x0);
          if (iVar1 != 0) {
            *param_2 = rsa;
            uVar2 = 0;
            rsa = (RSA *)0x0;
          }
        }
      }
    }
    RSA_free(rsa);
    BN_free(a);
  }
  else {
    uVar2 = 0xffffffc8;
  }
  return uVar2;
}



// Function: private2_check_padding @ 0xe200

int private2_check_padding(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  long in_FS_OFFSET;
  char local_29;
  long local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = 0;
  do {
    lVar2 = FUN_0010c3d0(param_1);
    iVar1 = 0;
    if (lVar2 == 0) goto LAB_0010e264;
    iVar1 = FUN_00119e50(param_1,&local_29);
    if (iVar1 != 0) goto LAB_0010e264;
    local_28 = local_28 + 1;
  } while (local_29 == (char)local_28);
  iVar1 = -4;
LAB_0010e264:
  __explicit_bzero_chk(&local_29,1,1);
  __explicit_bzero_chk(&local_28,8,8);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: clear_libcrypto_errors @ 0xe340

undefined8 clear_libcrypto_errors(void)

{
  ulong uVar1;
  
  do {
    uVar1 = ERR_get_error();
  } while (uVar1 != 0);
  return 0;
}



// Function: convert_libcrypto_error @ 0xe3e0

undefined8 convert_libcrypto_error(void)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  uVar2 = ERR_peek_error();
  iVar1 = FUN_0010d420(uVar2);
  if (iVar1 != -0x2b) {
    uVar2 = ERR_peek_last_error();
    uVar3 = FUN_0010d420(uVar2);
    return uVar3;
  }
  return 0xffffffd5;
}



// Function: sshkey_type @ 0xe880

char * sshkey_type(int *param_1)

{
  undefined **ppuVar1;
  int iVar2;
  
  ppuVar1 = &PTR_s_ssh_ed25519_00166cc0;
  iVar2 = 3;
  do {
    if (*param_1 == iVar2) {
      return ppuVar1[1];
    }
    iVar2 = *(int *)(ppuVar1 + 8);
    ppuVar1 = ppuVar1 + 5;
  } while (iVar2 != -1);
  return "unknown";
}



// Function: sshkey_type_is_cert @ 0xe9c0

undefined4 sshkey_type_is_cert(int param_1)

{
  undefined **ppuVar1;
  int iVar2;
  
  ppuVar1 = &PTR_s_ssh_ed25519_00166cc0;
  iVar2 = 3;
  do {
    if (param_1 == iVar2) {
      return *(undefined4 *)(ppuVar1 + 4);
    }
    iVar2 = *(int *)(ppuVar1 + 8);
    ppuVar1 = ppuVar1 + 5;
  } while (iVar2 != -1);
  return 0;
}



// Function: sshkey_ssh_name @ 0xeaf0

void sshkey_ssh_name(undefined4 *param_1)

{
  FUN_0010d0a0(*param_1,param_1[6]);
  return;
}



// Function: sshkey_type_from_name @ 0xeb00

int sshkey_type_from_name(char *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  char *__s2;
  int iVar3;
  
  __s2 = "ssh-ed25519";
  iVar3 = 3;
  ppuVar2 = &PTR_s_ssh_ed25519_00166cc0;
  while( true ) {
    if ((__s2 != (char *)0x0) && (iVar1 = strcmp(param_1,__s2), iVar1 == 0)) {
      return iVar3;
    }
    if ((*(int *)(ppuVar2 + 4) == 0) && (iVar1 = strcasecmp(ppuVar2[1],param_1), iVar1 == 0)) break;
    iVar3 = *(int *)(ppuVar2 + 8);
    ppuVar2 = ppuVar2 + 5;
    if (iVar3 == -1) {
      return 0xe;
    }
    __s2 = *ppuVar2;
  }
  return iVar3;
}



// Function: sshkey_ecdsa_nid_from_name @ 0xebf0

undefined4 sshkey_ecdsa_nid_from_name(char *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = 3;
  ppuVar2 = &PTR_s_ssh_ed25519_00166cc0;
  do {
    iVar1 = FUN_0010d1e0(iVar1);
    if ((iVar1 != 0) && (*ppuVar2 != (char *)0x0)) {
      iVar1 = strcmp(param_1,*ppuVar2);
      if (iVar1 == 0) {
        return *(undefined4 *)((long)ppuVar2 + 0x1c);
      }
    }
    iVar1 = *(int *)(ppuVar2 + 8);
    ppuVar2 = ppuVar2 + 5;
  } while (iVar1 != -1);
  return 0xffffffff;
}



// Function: sshkey_match_keyname_to_sigalgs @ 0xed50

bool sshkey_match_keyname_to_sigalgs(undefined8 param_1,char *param_2)

{
  int iVar1;
  
  if (param_2 == (char *)0x0) {
    return false;
  }
  if ((*param_2 == '\0') || (iVar1 = FUN_0010eb00(), iVar1 == 0xe)) {
    return false;
  }
  if (iVar1 == 0) {
    iVar1 = FUN_00120960("ssh-rsa",param_2,0);
    if ((iVar1 != 1) && (iVar1 = FUN_00120960("rsa-sha2-256",param_2,0), iVar1 != 1)) {
      iVar1 = FUN_00120960("rsa-sha2-512",param_2,0);
      return iVar1 == 1;
    }
  }
  else {
    if (iVar1 != 4) {
      iVar1 = FUN_00120960(param_1,param_2,0);
      return iVar1 == 1;
    }
    iVar1 = FUN_00120960("ssh-rsa-cert-v01@openssh.com",param_2,0);
    if ((iVar1 != 1) &&
       (iVar1 = FUN_00120960("rsa-sha2-256-cert-v01@openssh.com",param_2,0), iVar1 != 1)) {
      iVar1 = FUN_00120960("rsa-sha2-512-cert-v01@openssh.com",param_2,0);
      return iVar1 == 1;
    }
  }
  return true;
}



// Function: sshkey_alg_list @ 0xf080

void * sshkey_alg_list(int param_1,int param_2,int param_3,undefined1 param_4)

{
  int iVar1;
  size_t sVar2;
  void *pvVar3;
  long lVar4;
  long lVar5;
  char *__s;
  undefined **ppuVar6;
  void *__ptr;
  
  __ptr = (void *)0x0;
  lVar5 = 0;
  __s = "ssh-ed25519";
  ppuVar6 = &PTR_s_ssh_ed25519_00166cc0;
  do {
    if ((__s != (char *)0x0) && ((param_3 != 0 || (*(int *)((long)ppuVar6 + 0x24) == 0)))) {
      if (param_1 == 0) {
        if (param_2 != 0) {
          iVar1 = *(int *)(ppuVar6 + 4);
joined_r0x0010f0ce:
          if (iVar1 != 0) goto LAB_0010f11c;
        }
        lVar4 = lVar5;
        if (__ptr != (void *)0x0) {
          lVar4 = lVar5 + 1;
          *(undefined1 *)((long)__ptr + lVar5) = param_4;
          __s = *ppuVar6;
        }
        sVar2 = strlen(__s);
        lVar5 = lVar4 + sVar2;
        pvVar3 = realloc(__ptr,lVar5 + 2);
        if (pvVar3 == (void *)0x0) {
          free(__ptr);
          return (void *)0x0;
        }
        memcpy((void *)((long)pvVar3 + lVar4),*ppuVar6,sVar2 + 1);
        __ptr = pvVar3;
      }
      else {
        iVar1 = param_2;
        if (*(int *)(ppuVar6 + 4) != 0) goto joined_r0x0010f0ce;
      }
    }
LAB_0010f11c:
    if (*(int *)(ppuVar6 + 8) == -1) {
      return __ptr;
    }
    __s = ppuVar6[5];
    ppuVar6 = ppuVar6 + 5;
  } while( true );
}



// Function: sshkey_names_valid2 @ 0xf210

undefined8 sshkey_names_valid2(char *param_1,int param_2)

{
  int iVar1;
  char *__ptr;
  char *pcVar2;
  undefined8 uVar3;
  undefined **ppuVar4;
  char *pcVar5;
  long in_FS_OFFSET;
  char *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (((param_1 != (char *)0x0) && (iVar1 = strcmp(param_1,""), iVar1 != 0)) &&
     (__ptr = strdup(param_1), local_48 = __ptr, __ptr != (char *)0x0)) {
    do {
      do {
        pcVar2 = strsep(&local_48,",");
        if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
          free(__ptr);
          uVar3 = 1;
          goto LAB_0010f252;
        }
        iVar1 = FUN_0010eb00(pcVar2);
      } while (iVar1 != 0xe);
      if (param_2 == 0) break;
      pcVar5 = "ssh-ed25519";
      ppuVar4 = &PTR_s_ssh_ed25519_00166cc0;
      while (iVar1 = FUN_00120960(pcVar5,pcVar2,0), iVar1 == 0) {
        if (*(int *)(ppuVar4 + 8) == -1) goto LAB_0010f388;
        pcVar5 = ppuVar4[5];
        ppuVar4 = ppuVar4 + 5;
      }
    } while (*(int *)(ppuVar4 + 3) != -1);
LAB_0010f388:
    free(__ptr);
  }
  uVar3 = 0;
LAB_0010f252:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



// Function: sshkey_is_cert @ 0xf3b0

undefined8 sshkey_is_cert(undefined4 *param_1)

{
  undefined8 uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = FUN_0010e9c0(*param_1);
    return uVar1;
  }
  return 0;
}



// Function: sshkey_type_plain @ 0xf440

ulong sshkey_type_plain(ulong param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0013da20(param_1,0xfffffffc);
  switch(uVar1) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 3;
  default:
    return param_1 & 0xffffffff;
  case 5:
    return 8;
  case 7:
    return 10;
  case 9:
    return 0xc;
  }
}



// Function: sshkey_ssh_name_plain @ 0xf8b0

void sshkey_ssh_name_plain(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0010f440(*param_1);
  FUN_0010d0a0(uVar1,param_1[6]);
  return;
}



// Function: sshkey_is_sk @ 0xf8d0

bool sshkey_is_sk(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = FUN_0010f440(*param_1);
    return (iVar1 - 10U & 0xfffffffd) == 0;
  }
  return false;
}



// Function: sshkey_curve_name_to_nid @ 0xfa00

int sshkey_curve_name_to_nid(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = strcmp(param_1,"nistp256");
  iVar2 = 0x19f;
  if (iVar1 != 0) {
    iVar1 = strcmp(param_1,"nistp384");
    iVar2 = 0x2cb;
    if (iVar1 != 0) {
      iVar1 = strcmp(param_1,"nistp521");
      iVar2 = (-(uint)(iVar1 == 0) & 0x2cd) - 1;
    }
  }
  return iVar2;
}



// Function: sshkey_curve_nid_to_bits @ 0xfae0

long sshkey_curve_nid_to_bits(int param_1)

{
  long lVar1;
  
  lVar1 = 0x180;
  if ((param_1 != 0x2cb) && (lVar1 = 0x209, param_1 != 0x2cc)) {
    lVar1 = (ulong)(param_1 == 0x19f) << 8;
  }
  return lVar1;
}



// Function: sshkey_size @ 0xfb90

int sshkey_size(undefined4 *param_1)

{
  int iVar1;
  long in_FS_OFFSET;
  BIGNUM *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  switch(*param_1) {
  case 0:
  case 4:
    iVar1 = 0;
    if (*(long *)(param_1 + 2) != 0) {
      RSA_get0_key(*(long *)(param_1 + 2),&local_18,0,0);
      iVar1 = BN_num_bits(local_18);
    }
    break;
  case 1:
  case 5:
    iVar1 = 0;
    if (*(long *)(param_1 + 4) != 0) {
      DSA_get0_pqg(*(long *)(param_1 + 4),&local_18,0,0);
      iVar1 = BN_num_bits(local_18);
    }
    break;
  case 2:
  case 6:
  case 10:
  case 0xb:
    if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
      iVar1 = FUN_0010fae0(param_1[6]);
      return iVar1;
    }
    goto LAB_0010fce1;
  case 3:
  case 7:
  case 8:
  case 9:
  case 0xc:
  case 0xd:
    iVar1 = 0x100;
    break;
  default:
    iVar1 = 0;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
LAB_0010fce1:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: fingerprint_randomart @ 0xfcf0

undefined1 * fingerprint_randomart(undefined8 param_1,byte *param_2,long param_3,undefined8 param_4)

{
  undefined2 *puVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  size_t sVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  size_t __n;
  ulong uVar9;
  ulong uVar10;
  undefined1 *puVar11;
  void *pvVar12;
  long lVar13;
  ulong uVar14;
  uint uVar15;
  char *pcVar16;
  char *pcVar17;
  undefined1 *puVar18;
  uint uVar19;
  byte *pbVar20;
  undefined2 *puVar21;
  undefined2 *puVar22;
  int iVar24;
  char *pcVar25;
  byte *pbVar26;
  undefined1 *puVar27;
  ulong uVar28;
  long in_FS_OFFSET;
  byte bVar29;
  byte local_118 [9];
  byte local_10f [67];
  char local_cc;
  char local_78 [32];
  char local_58 [24];
  long local_40;
  undefined2 *puVar23;
  
  bVar29 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sVar6 = strlen(" .o+=*BOX@%&#/^SE");
  uVar28 = sVar6 - 1;
  puVar7 = calloc(0x14,0xb);
  if (puVar7 == (undefined1 *)0x0) goto LAB_001100c0;
  pbVar26 = local_118;
  pbVar20 = pbVar26;
  for (lVar13 = 0x13; lVar13 != 0; lVar13 = lVar13 + -1) {
    pbVar20[0] = 0;
    pbVar20[1] = 0;
    pbVar20[2] = 0;
    pbVar20[3] = 0;
    pbVar20[4] = 0;
    pbVar20[5] = 0;
    pbVar20[6] = 0;
    pbVar20[7] = 0;
    pbVar20 = pbVar20 + (ulong)bVar29 * -0x10 + 8;
  }
  *pbVar20 = 0;
  if (param_3 == 0) {
    uVar14 = 4;
    lVar13 = 8;
  }
  else {
    pbVar20 = param_2 + param_3;
    uVar4 = 4;
    lVar13 = 8;
    do {
      uVar19 = (uint)*param_2;
      iVar24 = 4;
      uVar14 = (ulong)uVar4;
      do {
        uVar4 = uVar19 & 1;
        if ((uVar19 & 1) == 0) {
          uVar4 = 0xffffffff;
        }
        iVar3 = FUN_0013da20(uVar4,lVar13);
        uVar4 = FUN_0013da20(-(uint)((uVar19 & 2) == 0) | 1,uVar14 & 0xffffffff);
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        uVar15 = 0;
        if (-1 < (int)uVar4) {
          uVar15 = uVar4;
        }
        iVar5 = 0x10;
        if (iVar3 < 0x11) {
          iVar5 = iVar3;
        }
        lVar13 = (long)iVar5;
        uVar4 = 8;
        if ((int)uVar15 < 9) {
          uVar4 = uVar15;
        }
        uVar14 = (ulong)(int)uVar4;
        lVar2 = uVar14 + lVar13 * 9 + -0x38;
        if ((ulong)local_118[lVar2 + 0x38] < sVar6 - 3) {
          local_118[lVar2 + 0x38] = local_118[lVar2 + 0x38] + 1;
        }
        uVar19 = (int)uVar19 >> 2;
        iVar24 = iVar24 + -1;
      } while (iVar24 != 0);
      param_2 = param_2 + 1;
    } while (pbVar20 != param_2);
  }
  local_cc = (byte)uVar28 - 1;
  local_118[uVar14 + lVar13 * 9] = (byte)uVar28;
  FUN_0010fb90(param_4);
  uVar8 = FUN_0010e880(param_4);
  uVar4 = __snprintf_chk(local_78,0x11,1,0x11,"[%s %u]",uVar8);
  if (0x11 < uVar4) {
    uVar8 = FUN_0010e880(param_4);
    uVar4 = __snprintf_chk(local_78,0x11,1,0x11,&DAT_0013f0e5,uVar8);
  }
  puVar27 = puVar7 + 1;
  if ((int)uVar4 < 1) {
    sVar6 = 0;
    iVar24 = __snprintf_chk(local_58,0x11,1,0x11,&DAT_0013f0e5);
    uVar14 = 8;
    if (0 < iVar24) goto LAB_0010ff35;
    uVar9 = 8;
    __n = 0;
    *puVar7 = 0x2b;
LAB_0010ff69:
    uVar10 = 0;
    do {
      puVar7[uVar10 + 1] = 0x2d;
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar14);
    uVar10 = 1;
    if (uVar14 != 0) {
      uVar10 = uVar14;
    }
    puVar27 = puVar27 + uVar10;
    uVar10 = uVar10 + sVar6;
  }
  else {
    sVar6 = strlen(local_78);
    iVar24 = __snprintf_chk(local_58,0x11,1,0x11,&DAT_0013f0e5);
    uVar14 = 0x11 - sVar6 >> 1;
    if (iVar24 < 1) {
      uVar9 = 8;
      __n = 0;
      *puVar7 = 0x2b;
    }
    else {
LAB_0010ff35:
      __n = strlen(local_58);
      uVar9 = 0x11 - __n >> 1;
      *puVar7 = 0x2b;
    }
    uVar10 = sVar6;
    if (uVar14 != 0) goto LAB_0010ff69;
  }
  puVar21 = (undefined2 *)(puVar27 + sVar6);
  __memcpy_chk(puVar27,local_78,sVar6,0xdb);
  if (uVar10 < 0x11) {
    puVar1 = (undefined2 *)((long)puVar21 + (0x11 - uVar10));
    puVar23 = puVar21;
    do {
      puVar22 = (undefined2 *)((long)puVar23 + 1);
      *(undefined1 *)puVar23 = 0x2d;
      puVar23 = puVar22;
      puVar21 = puVar1;
    } while (puVar1 != puVar22);
  }
  pcVar25 = (char *)(puVar21 + 10);
  *puVar21 = 0xa2b;
  do {
    pcVar25[-0x12] = '|';
    pbVar20 = pbVar26;
    pcVar17 = pcVar25 + -0x11;
    do {
      pcVar16 = pcVar17;
      pcVar17 = pcVar16 + 1;
      uVar14 = (ulong)*pbVar20;
      if (uVar28 < *pbVar20) {
        uVar14 = uVar28;
      }
      pbVar20 = pbVar20 + 9;
      *pcVar16 = " .o+=*BOX@%&#/^SE"[uVar14];
    } while (pcVar17 != pcVar25);
    pbVar26 = pbVar26 + 1;
    *pcVar17 = '|';
    pcVar25 = pcVar16 + 0x15;
    pcVar16[2] = '\n';
  } while (local_10f != pbVar26);
  *(undefined1 *)(puVar21 + 0x5b) = 0x2b;
  puVar27 = (undefined1 *)((long)puVar21 + 0xb7);
  uVar28 = __n;
  if (uVar9 != 0) {
    puVar18 = puVar27;
    do {
      puVar11 = puVar18 + 1;
      *puVar18 = 0x2d;
      puVar18 = puVar11;
    } while (puVar11 != (undefined1 *)((long)puVar21 + uVar9 + 0xb7));
    puVar27 = puVar27 + uVar9;
    uVar28 = __n + uVar9;
  }
  pvVar12 = memcpy(puVar27,local_58,__n);
  puVar27 = (undefined1 *)((long)pvVar12 + __n);
  puVar18 = puVar27;
  if (uVar28 < 0x11) {
    puVar18 = puVar27 + (0x11 - uVar28);
    do {
      puVar11 = puVar27 + 1;
      *puVar27 = 0x2d;
      puVar27 = puVar11;
    } while (puVar11 != puVar18);
  }
  *puVar18 = 0x2b;
LAB_001100c0:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return puVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_ecdsa_bits_to_nid @ 0x10240

undefined8 sshkey_ecdsa_bits_to_nid(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x2cb;
  if (((param_1 != 0x180) && (uVar1 = 0x2cc, param_1 != 0x209)) &&
     (uVar1 = 0xffffffff, param_1 == 0x100)) {
    uVar1 = 0x19f;
  }
  return uVar1;
}



// Function: ecdsa_generate_private_key @ 0x102f0

undefined8 ecdsa_generate_private_key(undefined8 param_1,int *param_2,undefined8 *param_3)

{
  int iVar1;
  EC_KEY *key;
  undefined8 uVar2;
  
  iVar1 = FUN_00110240();
  *param_2 = iVar1;
  if (iVar1 == -1) {
    uVar2 = 0xffffffc8;
  }
  else {
    *param_3 = 0;
    uVar2 = 0xfffffffe;
    key = EC_KEY_new_by_curve_name(*param_2);
    if (key != (EC_KEY *)0x0) {
      uVar2 = 0xffffffea;
      iVar1 = EC_KEY_generate_key(key);
      if (iVar1 == 1) {
        uVar2 = 0;
        EC_KEY_set_asn1_flag(key,1);
        *param_3 = key;
        key = (EC_KEY *)0x0;
      }
    }
    EC_KEY_free(key);
  }
  return uVar2;
}



// Function: sshkey_curve_nid_to_name @ 0x10400

char * sshkey_curve_nid_to_name(int param_1)

{
  char *pcVar1;
  
  pcVar1 = "nistp384";
  if (((param_1 != 0x2cb) && (pcVar1 = "nistp521", param_1 != 0x2cc)) &&
     (pcVar1 = "nistp256", param_1 != 0x19f)) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}



// Function: sshkey_ec_nid_to_hash_alg @ 0x109a0

int sshkey_ec_nid_to_hash_alg(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0010fae0();
  if (iVar1 < 1) {
    iVar2 = -1;
  }
  else {
    iVar2 = 2;
    if (0x100 < iVar1) {
      iVar2 = (0x180 < iVar1) + 3;
    }
  }
  return iVar2;
}



// Function: sshkey_free @ 0x10a60

undefined8 sshkey_free(undefined4 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  switch(*param_1) {
  case 0:
  case 4:
    RSA_free(*(RSA **)(param_1 + 2));
    *(undefined8 *)(param_1 + 2) = 0;
    break;
  case 1:
  case 5:
    DSA_free(*(DSA **)(param_1 + 4));
    *(undefined8 *)(param_1 + 4) = 0;
    break;
  case 2:
  case 6:
    goto switchD_00110a86_caseD_2;
  case 3:
  case 7:
    goto switchD_00110a86_caseD_3;
  case 10:
  case 0xb:
    free(*(void **)(param_1 + 0x18));
    FUN_0010bce0(*(undefined8 *)(param_1 + 0x1c));
    FUN_0010bce0(*(undefined8 *)(param_1 + 0x1e));
switchD_00110a86_caseD_2:
    EC_KEY_free(*(EC_KEY **)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
    iVar1 = FUN_0010f3b0(param_1);
    if (iVar1 == 0) goto LAB_00110ae3;
    goto LAB_00110b58;
  case 0xc:
  case 0xd:
    free(*(void **)(param_1 + 0x18));
    FUN_0010bce0(*(undefined8 *)(param_1 + 0x1c));
    FUN_0010bce0(*(undefined8 *)(param_1 + 0x1e));
switchD_00110a86_caseD_3:
    FUN_0013b0d0(*(undefined8 *)(param_1 + 0xc),0x20);
    *(undefined8 *)(param_1 + 0xc) = 0;
    FUN_0013b0d0(*(undefined8 *)(param_1 + 10),0x40);
    *(undefined8 *)(param_1 + 10) = 0;
  }
  iVar1 = FUN_0010f3b0(param_1);
  if (iVar1 != 0) {
LAB_00110b58:
    FUN_00110c30(*(undefined8 *)(param_1 + 0x20));
  }
LAB_00110ae3:
  FUN_0013b0d0(*(undefined8 *)(param_1 + 0x22),*(undefined8 *)(param_1 + 0x24));
  FUN_0013b0d0(*(undefined8 *)(param_1 + 0x26),*(undefined8 *)(param_1 + 0x28));
  uVar2 = FUN_0013b0d0(param_1,0xa8);
  return uVar2;
}



// Function: cert_free @ 0x10c30

undefined8 cert_free(undefined8 *param_1)

{
  undefined8 uVar1;
  uint uVar2;
  ulong uVar3;
  
  if (param_1 != (undefined8 *)0x0) {
    FUN_0010bce0(*param_1);
    FUN_0010bce0(param_1[8]);
    FUN_0010bce0(param_1[9]);
    free((void *)param_1[3]);
    if (*(int *)(param_1 + 4) != 0) {
      uVar3 = 0;
      do {
        uVar2 = (int)uVar3 + 1;
        free(*(void **)(param_1[5] + uVar3 * 8));
        uVar3 = (ulong)uVar2;
      } while (uVar2 < *(uint *)(param_1 + 4));
    }
    free((void *)param_1[5]);
    FUN_00110a60(param_1[10]);
    free((void *)param_1[0xb]);
    uVar1 = FUN_0013b0d0(param_1,0x60);
    return uVar1;
  }
  return 0;
}



// Function: cert_new @ 0x10d40

long * cert_new(void)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = calloc(1,0x60);
  if (plVar1 == (long *)0x0) {
    return (long *)0x0;
  }
  lVar2 = FUN_0010b880();
  *plVar1 = lVar2;
  if (lVar2 != 0) {
    lVar2 = FUN_0010b880();
    plVar1[8] = lVar2;
    if (lVar2 != 0) {
      lVar2 = FUN_0010b880();
      plVar1[9] = lVar2;
      if (lVar2 != 0) {
        plVar1[3] = 0;
        plVar1[5] = 0;
        plVar1[10] = 0;
        plVar1[0xb] = 0;
        return plVar1;
      }
    }
  }
  FUN_00110c30(plVar1);
  return (long *)0x0;
}



// Function: sshkey_new @ 0x10ed0

uint * sshkey_new(uint param_1)

{
  int iVar1;
  uint *__ptr;
  ulong uVar2;
  long lVar3;
  RSA *pRVar4;
  DSA *pDVar5;
  uint *puVar6;
  
  __ptr = calloc(1,0xa8);
  puVar6 = __ptr;
  if (__ptr != (uint *)0x0) {
    *__ptr = param_1;
    __ptr[8] = 0;
    __ptr[9] = 0;
    __ptr[6] = 0xffffffff;
    __ptr[4] = 0;
    __ptr[5] = 0;
    __ptr[2] = 0;
    __ptr[3] = 0;
    __ptr[0x20] = 0;
    __ptr[0x21] = 0;
    __ptr[10] = 0;
    __ptr[0xb] = 0;
    __ptr[0xc] = 0;
    __ptr[0xd] = 0;
    __ptr[0x14] = 0;
    __ptr[0x15] = 0;
    __ptr[0x16] = 0;
    __ptr[0x17] = 0;
    if (0xe < param_1) goto LAB_00111020;
    uVar2 = 1L << ((byte)param_1 & 0x3f);
    if ((uVar2 & 0x7fcc) == 0) {
      if ((uVar2 & 0x22) == 0) {
        if ((uVar2 & 0x11) == 0) {
LAB_00111020:
          free(__ptr);
          return (uint *)0x0;
        }
        pRVar4 = RSA_new();
        if (pRVar4 == (RSA *)0x0) goto LAB_00111020;
        *(RSA **)(__ptr + 2) = pRVar4;
      }
      else {
        pDVar5 = DSA_new();
        if (pDVar5 == (DSA *)0x0) goto LAB_00111020;
        *(DSA **)(__ptr + 4) = pDVar5;
      }
    }
    iVar1 = FUN_0010f3b0(__ptr);
    if (iVar1 != 0) {
      lVar3 = FUN_00110d40();
      *(long *)(__ptr + 0x20) = lVar3;
      if (lVar3 == 0) {
        puVar6 = (uint *)0x0;
        FUN_00110a60(__ptr);
      }
    }
  }
  return puVar6;
}



// Function: sshkey_equal_public @ 0x11100

bool sshkey_equal_public(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  EC_POINT *pEVar4;
  EC_GROUP *pEVar5;
  EC_GROUP *a;
  EC_POINT *a_00;
  long in_FS_OFFSET;
  bool bVar6;
  BIGNUM *local_70;
  BIGNUM *local_68;
  BIGNUM *local_60;
  BIGNUM *local_58;
  BIGNUM *local_50;
  BIGNUM *local_48;
  BIGNUM *local_40;
  BIGNUM *local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    uVar1 = *param_1;
    iVar2 = FUN_0010f440(uVar1);
    iVar3 = FUN_0010f440(*param_2);
    if (iVar2 == iVar3) {
      switch(uVar1) {
      case 0:
      case 4:
        if ((*(long *)(param_1 + 2) != 0) && (*(long *)(param_2 + 2) != 0)) {
          RSA_get0_key(*(long *)(param_1 + 2),&local_48,&local_50,0);
          RSA_get0_key(*(undefined8 *)(param_2 + 2),&local_38,&local_40,0);
          iVar2 = BN_cmp(local_50,local_40);
          if (iVar2 == 0) {
            iVar2 = BN_cmp(local_48,local_38);
            bVar6 = iVar2 == 0;
            goto LAB_0011114e;
          }
        }
        break;
      case 1:
      case 5:
        if ((*(long *)(param_1 + 4) != 0) && (*(long *)(param_2 + 4) != 0)) {
          DSA_get0_pqg(*(long *)(param_1 + 4),&local_70,&local_68,&local_60);
          DSA_get0_pqg(*(undefined8 *)(param_2 + 4),&local_50,&local_48,&local_40);
          DSA_get0_key(*(undefined8 *)(param_1 + 4),&local_58,0);
          DSA_get0_key(*(undefined8 *)(param_2 + 4),&local_38,0);
          iVar2 = BN_cmp(local_70,local_50);
          if ((iVar2 == 0) &&
             ((iVar2 = BN_cmp(local_68,local_48), iVar2 == 0 &&
              (iVar2 = BN_cmp(local_60,local_40), iVar2 == 0)))) {
            iVar2 = BN_cmp(local_58,local_38);
            bVar6 = iVar2 == 0;
            goto LAB_0011114e;
          }
        }
        break;
      case 2:
      case 6:
switchD_00111208_caseD_2:
        if ((((*(EC_KEY **)(param_1 + 8) != (EC_KEY *)0x0) && (*(long *)(param_2 + 8) != 0)) &&
            (pEVar4 = EC_KEY_get0_public_key(*(EC_KEY **)(param_1 + 8)), pEVar4 != (EC_POINT *)0x0))
           && (pEVar4 = EC_KEY_get0_public_key(*(EC_KEY **)(param_2 + 8)), pEVar4 != (EC_POINT *)0x0
              )) {
          pEVar5 = EC_KEY_get0_group(*(EC_KEY **)(param_2 + 8));
          a = EC_KEY_get0_group(*(EC_KEY **)(param_1 + 8));
          iVar2 = EC_GROUP_cmp(a,pEVar5,(BN_CTX *)0x0);
          if (iVar2 == 0) {
            pEVar4 = EC_KEY_get0_public_key(*(EC_KEY **)(param_2 + 8));
            a_00 = EC_KEY_get0_public_key(*(EC_KEY **)(param_1 + 8));
            pEVar5 = EC_KEY_get0_group(*(EC_KEY **)(param_1 + 8));
            iVar2 = EC_POINT_cmp(pEVar5,a_00,pEVar4,(BN_CTX *)0x0);
            bVar6 = iVar2 == 0;
            goto LAB_0011114e;
          }
        }
        break;
      case 3:
      case 7:
switchD_00111208_caseD_3:
        if ((*(void **)(param_1 + 0xc) != (void *)0x0) && (*(void **)(param_2 + 0xc) != (void *)0x0)
           ) {
          iVar2 = memcmp(*(void **)(param_1 + 0xc),*(void **)(param_2 + 0xc),0x20);
          bVar6 = true;
          if (iVar2 == 0) goto LAB_0011114e;
        }
        break;
      case 10:
      case 0xb:
        if (((*(char **)(param_1 + 0x18) != (char *)0x0) &&
            (*(char **)(param_2 + 0x18) != (char *)0x0)) &&
           (iVar2 = strcmp(*(char **)(param_1 + 0x18),*(char **)(param_2 + 0x18)), iVar2 == 0))
        goto switchD_00111208_caseD_2;
        break;
      case 0xc:
      case 0xd:
        if (((*(char **)(param_1 + 0x18) != (char *)0x0) &&
            (*(char **)(param_2 + 0x18) != (char *)0x0)) &&
           (iVar2 = strcmp(*(char **)(param_1 + 0x18),*(char **)(param_2 + 0x18)), iVar2 == 0))
        goto switchD_00111208_caseD_3;
      }
    }
  }
  bVar6 = false;
LAB_0011114e:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_equal @ 0x11490

undefined8 sshkey_equal(int *param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if ((param_2 != (int *)0x0) && (*param_1 == *param_2)) {
    iVar1 = FUN_0010f3b0();
    if ((iVar1 != 0) &&
       (iVar1 = FUN_0010da80(*(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_2 + 0x20)),
       iVar1 == 0)) {
      return 0;
    }
    uVar2 = FUN_00111100(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// Function: sshkey_putb @ 0x11600

void sshkey_putb(undefined8 param_1,undefined8 param_2)

{
  FUN_001104c0(param_1,param_2,0);
  return;
}



// Function: sshkey_puts_opts @ 0x11610

int sshkey_puts_opts(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_0010b880();
  if (lVar2 == 0) {
    iVar1 = -2;
  }
  else {
    iVar1 = FUN_001104c0(param_1,lVar2,0);
    if (iVar1 == 0) {
      iVar1 = FUN_0011b840(param_2,lVar2);
    }
    FUN_0010bce0(lVar2);
  }
  return iVar1;
}



// Function: sshkey_puts @ 0x11700

void sshkey_puts(undefined8 param_1,undefined8 param_2)

{
  FUN_00111610(param_1,param_2,0);
  return;
}



// Function: sshkey_putb_plain @ 0x11710

void sshkey_putb_plain(undefined8 param_1,undefined8 param_2)

{
  FUN_001104c0(param_1,param_2,1);
  return;
}



// Function: sshkey_to_blob @ 0x11720

void sshkey_to_blob(void)

{
  FUN_00110850();
  return;
}



// Function: sshkey_plain_to_blob @ 0x11730

void sshkey_plain_to_blob(void)

{
  FUN_00110850();
  return;
}



// Function: sshkey_fingerprint_raw @ 0x11740

int sshkey_fingerprint_raw(undefined8 param_1,undefined4 param_2,undefined8 *param_3,undefined8 *param_4)

{
  int iVar1;
  long lVar2;
  void *__ptr;
  undefined8 uVar3;
  long in_FS_OFFSET;
  long local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_50 = 0;
  local_48 = 0;
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  lVar2 = FUN_00130050();
  if (lVar2 == 0) {
    iVar1 = -10;
    free((void *)0x0);
  }
  else {
    iVar1 = FUN_00110850(param_1,&local_50,&local_48,1);
    if (iVar1 == 0) {
      __ptr = calloc(1,0x40);
      lVar2 = local_50;
      if (__ptr == (void *)0x0) {
        iVar1 = -2;
      }
      else {
        iVar1 = FUN_00130740(param_2,local_50,local_48,__ptr,0x40);
        if (iVar1 == 0) {
          if (param_3 != (undefined8 *)0x0) {
            *param_3 = __ptr;
            __ptr = (void *)0x0;
          }
          if (param_4 != (undefined8 *)0x0) {
            uVar3 = FUN_00130050(param_2);
            *param_4 = uVar3;
          }
        }
      }
    }
    else {
      __ptr = (void *)0x0;
      lVar2 = local_50;
    }
    free(__ptr);
    if (lVar2 != 0) {
      FUN_0013b0d0(lVar2,local_48);
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_fingerprint @ 0x11920

undefined8 sshkey_fingerprint(undefined8 param_1,ulong param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  long in_FS_OFFSET;
  undefined8 local_40;
  undefined8 local_38;
  long local_30;
  
  uVar3 = param_2 & 0xffffffff;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_00111740(param_1,param_2,&local_40,&local_38);
  if (iVar1 != 0) {
    uVar2 = 0;
    goto LAB_001119b5;
  }
  switch(param_3) {
  case 0:
    uVar4 = 0;
    if ((int)param_2 == 0) goto LAB_00111a5a;
  case 2:
    uVar2 = FUN_0012ffc0(uVar3);
    uVar2 = FUN_0010de20(uVar2,local_40,local_38);
    break;
  case 1:
    uVar4 = uVar3;
LAB_00111a5a:
    uVar2 = FUN_0012ffc0(uVar4);
    uVar2 = FUN_0010dc80(uVar2,local_40,local_38);
    break;
  case 3:
    uVar2 = FUN_0010d7c0(local_40,local_38);
    break;
  case 4:
    uVar2 = FUN_0012ffc0(uVar3);
    uVar2 = FUN_0010fcf0(uVar2,local_40,local_38,param_1);
    break;
  default:
    uVar2 = 0;
    FUN_0013b0d0(local_40,local_38);
    goto LAB_001119b5;
  }
  FUN_0013b0d0(local_40,local_38);
LAB_001119b5:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



// Function: sshkey_to_base64 @ 0x11ad0

int sshkey_to_base64(undefined8 param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  void *__ptr;
  
  if (param_2 != (long *)0x0) {
    *param_2 = 0;
  }
  lVar2 = FUN_0010b880();
  if (lVar2 == 0) {
    iVar1 = -2;
  }
  else {
    __ptr = (void *)0x0;
    iVar1 = FUN_00111600(param_1,lVar2);
    if (iVar1 == 0) {
      __ptr = (void *)FUN_0011c950(lVar2,0);
      if (__ptr == (void *)0x0) {
        iVar1 = -2;
      }
      else if (param_2 != (long *)0x0) {
        *param_2 = (long)__ptr;
        __ptr = (void *)0x0;
      }
    }
    FUN_0010bce0(lVar2);
    free(__ptr);
  }
  return iVar1;
}



// Function: sshkey_format_text @ 0x11c00

int sshkey_format_text(undefined8 param_1,undefined8 param_2)

{
  void *__ptr;
  int iVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  void *local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_38 = (void *)0x0;
  iVar1 = FUN_00111ad0(param_1,&local_38);
  __ptr = local_38;
  if (iVar1 == 0) {
    uVar2 = FUN_0010eaf0(param_1);
    iVar1 = FUN_0011ad40(param_2,"%s %s",uVar2,__ptr);
  }
  free(__ptr);
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



// Function: sshkey_write @ 0x11d20

int sshkey_write(undefined8 param_1,FILE *param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  void *__ptr;
  int *piVar5;
  
  lVar3 = FUN_0010b880();
  if (lVar3 == 0) {
    iVar1 = -2;
  }
  else {
    iVar1 = FUN_00111c00(param_1,lVar3);
    if (iVar1 == 0) {
      sVar4 = FUN_0010c3d0(lVar3);
      __ptr = (void *)FUN_0010c520(lVar3);
      sVar4 = fwrite(__ptr,sVar4,1,param_2);
      if (sVar4 != 1) {
        iVar1 = -0x18;
        iVar2 = feof(param_2);
        if (iVar2 != 0) {
          piVar5 = __errno_location();
          *piVar5 = 0x20;
        }
      }
    }
    FUN_0010bce0(lVar3);
  }
  return iVar1;
}



// Function: sshkey_cert_type @ 0x11e60

char * sshkey_cert_type(long param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = *(int *)(*(long *)(param_1 + 0x80) + 8);
  pcVar2 = "user";
  if ((iVar1 != 1) && (pcVar2 = "unknown", iVar1 == 2)) {
    pcVar2 = "host";
  }
  return pcVar2;
}



// Function: sshkey_ecdsa_key_to_nid @ 0x11f10

int sshkey_ecdsa_key_to_nid(EC_KEY *param_1)

{
  int nid;
  int iVar1;
  EC_GROUP *group;
  EC_GROUP *b;
  int *piVar2;
  long in_FS_OFFSET;
  int aiStack_48 [6];
  long local_30;
  
  piVar2 = aiStack_48;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  aiStack_48[1] = 0x2cb;
  aiStack_48[2] = 0x2cc;
  aiStack_48[3] = -1;
  group = EC_KEY_get0_group(param_1);
  nid = EC_GROUP_get_curve_name(group);
  if (nid < 1) {
    nid = 0x19f;
    do {
      b = EC_GROUP_new_by_curve_name(nid);
      if (b == (EC_GROUP *)0x0) break;
      iVar1 = EC_GROUP_cmp(group,b,(BN_CTX *)0x0);
      if (iVar1 == 0) {
        EC_GROUP_set_asn1_flag(b,1);
        iVar1 = EC_KEY_set_group(param_1,b);
        if (iVar1 == 1) goto LAB_00111fb0;
        EC_GROUP_free(b);
        break;
      }
      piVar2 = piVar2 + 1;
      EC_GROUP_free(b);
      nid = *piVar2;
    } while (nid != -1);
    nid = -1;
  }
LAB_00111fb0:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return nid;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_generate @ 0x12090

int sshkey_generate(int param_1,undefined4 param_2,long *param_3)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  
  if (param_3 == (long *)0x0) {
    return -10;
  }
  *param_3 = 0;
  piVar2 = (int *)FUN_00110ed0(0xe);
  if (piVar2 == (int *)0x0) {
    return -2;
  }
  if (param_1 == 2) {
    iVar1 = FUN_001102f0(param_2,piVar2 + 6,piVar2 + 8);
  }
  else {
    if (2 < param_1) {
      if (param_1 == 3) {
        pvVar3 = malloc(0x20);
        *(void **)(piVar2 + 0xc) = pvVar3;
        if (pvVar3 != (void *)0x0) {
          pvVar3 = malloc(0x40);
          *(void **)(piVar2 + 10) = pvVar3;
          if (pvVar3 != (void *)0x0) {
            FUN_00130930(*(undefined8 *)(piVar2 + 0xc),pvVar3);
            goto LAB_001121e3;
          }
        }
        iVar1 = -2;
        goto LAB_00112108;
      }
LAB_00112280:
      iVar1 = -10;
      goto LAB_00112108;
    }
    if (param_1 == 0) {
      iVar1 = FUN_0010e0c0(param_2,piVar2 + 2);
    }
    else {
      if (param_1 != 1) goto LAB_00112280;
      iVar1 = FUN_0010dfa0(param_2,piVar2 + 4);
    }
  }
  if (iVar1 == 0) {
LAB_001121e3:
    *piVar2 = param_1;
    *param_3 = (long)piVar2;
    return 0;
  }
LAB_00112108:
  FUN_00110a60(piVar2);
  return iVar1;
}



// Function: sshkey_from_private @ 0x12300

int sshkey_from_private(int *param_1,long *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  EC_KEY *pEVar6;
  EC_POINT *pub;
  char *pcVar7;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *a_03;
  BIGNUM *a_04;
  long in_FS_OFFSET;
  BIGNUM *local_70;
  BIGNUM *local_68;
  BIGNUM *local_60;
  BIGNUM *local_58;
  BIGNUM *local_50;
  BIGNUM *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  *param_2 = 0;
  lVar4 = FUN_00110ed0(*param_1);
  if (lVar4 == 0) {
    a_01 = (BIGNUM *)0x0;
    a_00 = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    a_03 = (BIGNUM *)0x0;
    a_04 = (BIGNUM *)0x0;
    a_02 = (BIGNUM *)0x0;
    iVar3 = -2;
    goto LAB_001123e6;
  }
  iVar3 = *param_1;
  switch(iVar3) {
  case 0:
  case 4:
    RSA_get0_key(*(undefined8 *)(param_1 + 2),&local_70,&local_68,0);
    a_02 = BN_dup(local_70);
    if (a_02 == (BIGNUM *)0x0) {
LAB_00112728:
      a_01 = (BIGNUM *)0x0;
      a_00 = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      a_03 = (BIGNUM *)0x0;
      a_04 = (BIGNUM *)0x0;
      iVar3 = -2;
      goto LAB_001123e6;
    }
    a_04 = BN_dup(local_68);
    if (a_04 == (BIGNUM *)0x0) {
      a_01 = (BIGNUM *)0x0;
      a_00 = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      a_03 = (BIGNUM *)0x0;
      iVar3 = -2;
      goto LAB_001123e6;
    }
    iVar3 = RSA_set0_key(*(undefined8 *)(lVar4 + 8),a_02,a_04,0);
    if (iVar3 == 0) {
      a_01 = (BIGNUM *)0x0;
      a_00 = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      a_03 = (BIGNUM *)0x0;
      iVar3 = -0x16;
      goto LAB_001123e6;
    }
    break;
  case 1:
  case 5:
    DSA_get0_pqg(*(undefined8 *)(param_1 + 4),&local_60,&local_58,&local_50);
    DSA_get0_key(*(undefined8 *)(param_1 + 4),&local_48,0);
    a_03 = BN_dup(local_60);
    if (a_03 == (BIGNUM *)0x0) {
      a_01 = (BIGNUM *)0x0;
      a_00 = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      a_04 = (BIGNUM *)0x0;
      a_02 = (BIGNUM *)0x0;
      iVar3 = -2;
      goto LAB_001123e6;
    }
    a = BN_dup(local_58);
    if (a == (BIGNUM *)0x0) {
      a_01 = (BIGNUM *)0x0;
      a_00 = (BIGNUM *)0x0;
      a_04 = (BIGNUM *)0x0;
      a_02 = (BIGNUM *)0x0;
      iVar3 = -2;
      goto LAB_001123e6;
    }
    a_00 = BN_dup(local_50);
    if (a_00 == (BIGNUM *)0x0) {
      a_01 = (BIGNUM *)0x0;
      a_04 = (BIGNUM *)0x0;
      a_02 = (BIGNUM *)0x0;
      iVar3 = -2;
      goto LAB_001123e6;
    }
    a_01 = BN_dup(local_48);
    if (a_01 == (BIGNUM *)0x0) {
      a_04 = (BIGNUM *)0x0;
      a_02 = (BIGNUM *)0x0;
      iVar3 = -2;
      goto LAB_001123e6;
    }
    iVar3 = DSA_set0_pqg(*(undefined8 *)(lVar4 + 0x10),a_03,a,a_00);
    if (iVar3 == 0) goto LAB_00112629;
    iVar3 = DSA_set0_key(*(undefined8 *)(lVar4 + 0x10),a_01,0);
    if (iVar3 == 0) goto LAB_00112621;
    break;
  case 2:
  case 6:
  case 10:
  case 0xb:
    iVar3 = param_1[6];
    *(int *)(lVar4 + 0x18) = iVar3;
    pEVar6 = EC_KEY_new_by_curve_name(iVar3);
    *(EC_KEY **)(lVar4 + 0x20) = pEVar6;
    a_02 = (BIGNUM *)0x0;
    if (pEVar6 == (EC_KEY *)0x0) goto LAB_00112728;
    pub = EC_KEY_get0_public_key(*(EC_KEY **)(param_1 + 8));
    iVar3 = EC_KEY_set_public_key(*(EC_KEY **)(lVar4 + 0x20),pub);
    if (iVar3 != 1) {
      a_01 = (BIGNUM *)0x0;
LAB_00112621:
      a_00 = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      a_03 = (BIGNUM *)0x0;
LAB_00112629:
      a_04 = (BIGNUM *)0x0;
      a_02 = (BIGNUM *)0x0;
      iVar3 = -0x16;
      goto LAB_001123e6;
    }
    if (1 < *param_1 - 10U) break;
LAB_0011251c:
    pcVar7 = strdup(*(char **)(param_1 + 0x18));
    *(char **)(lVar4 + 0x60) = pcVar7;
    if (pcVar7 == (char *)0x0) {
      a_01 = (BIGNUM *)0x0;
      a_00 = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      a_03 = (BIGNUM *)0x0;
      a_04 = (BIGNUM *)0x0;
      iVar3 = -1;
      a_02 = (BIGNUM *)0x0;
      goto LAB_001123e6;
    }
    break;
  case 3:
  case 7:
  case 0xc:
  case 0xd:
    if (*(long *)(param_1 + 0xc) != 0) {
      puVar5 = malloc(0x20);
      *(undefined8 **)(lVar4 + 0x30) = puVar5;
      a_02 = (BIGNUM *)0x0;
      if (puVar5 == (undefined8 *)0x0) goto LAB_00112728;
      puVar1 = *(undefined8 **)(param_1 + 0xc);
      iVar3 = *param_1;
      uVar2 = puVar1[1];
      *puVar5 = *puVar1;
      puVar5[1] = uVar2;
      uVar2 = puVar1[3];
      puVar5[2] = puVar1[2];
      puVar5[3] = uVar2;
    }
    if (iVar3 - 0xcU < 2) goto LAB_0011251c;
    break;
  default:
    a_01 = (BIGNUM *)0x0;
    a_00 = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    a_03 = (BIGNUM *)0x0;
    a_04 = (BIGNUM *)0x0;
    a_02 = (BIGNUM *)0x0;
    iVar3 = -0xe;
    goto LAB_001123e6;
  }
  iVar3 = FUN_0010f3b0(param_1);
  if ((iVar3 == 0) || (iVar3 = FUN_001127c0(param_1,lVar4), iVar3 == 0)) {
    a_01 = (BIGNUM *)0x0;
    a_00 = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    a_03 = (BIGNUM *)0x0;
    a_04 = (BIGNUM *)0x0;
    a_02 = (BIGNUM *)0x0;
    iVar3 = 0;
    *param_2 = lVar4;
    lVar4 = 0;
  }
  else {
    a_01 = (BIGNUM *)0x0;
    a_00 = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    a_03 = (BIGNUM *)0x0;
    a_04 = (BIGNUM *)0x0;
    a_02 = (BIGNUM *)0x0;
  }
LAB_001123e6:
  FUN_00110a60(lVar4);
  BN_clear_free(a_02);
  BN_clear_free(a_04);
  BN_clear_free(a_03);
  BN_clear_free(a);
  BN_clear_free(a_00);
  BN_clear_free(a_01);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_cert_copy @ 0x127c0

int sshkey_cert_copy(long param_1,long param_2)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  char *pcVar5;
  void *pvVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  
  if ((param_2 == 0) || (puVar1 = *(undefined8 **)(param_1 + 0x80), puVar1 == (undefined8 *)0x0)) {
    return -10;
  }
  puVar4 = (undefined8 *)FUN_00110d40();
  if (puVar4 == (undefined8 *)0x0) {
    return -2;
  }
  iVar2 = FUN_0011aad0(*puVar4,*puVar1);
  if (((iVar2 != 0) || (iVar2 = FUN_0011aad0(puVar4[8],puVar1[8]), iVar2 != 0)) ||
     (iVar3 = FUN_0011aad0(puVar4[9],puVar1[9]), iVar2 = iVar3, iVar3 != 0)) goto LAB_00112816;
  puVar4[2] = puVar1[2];
  *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(puVar1 + 1);
  if ((char *)puVar1[3] == (char *)0x0) {
    puVar4[3] = 0;
LAB_0011290e:
    puVar4[6] = puVar1[6];
    puVar4[7] = puVar1[7];
    if (puVar1[10] == 0) {
      puVar4[10] = 0;
    }
    else {
      iVar2 = FUN_00112300(puVar1[10],puVar4 + 10);
      if (iVar2 != 0) goto LAB_00112816;
    }
    if ((char *)puVar1[0xb] != (char *)0x0) {
      pcVar5 = strdup((char *)puVar1[0xb]);
      puVar4[0xb] = pcVar5;
      if (pcVar5 == (char *)0x0) goto LAB_00112a56;
    }
    uVar9 = *(uint *)(puVar1 + 4);
    if (0x100 < uVar9) {
      iVar2 = -10;
      goto LAB_00112816;
    }
    uVar7 = 0;
    if (uVar9 != 0) {
      pvVar6 = calloc((ulong)uVar9,8);
      puVar4[5] = pvVar6;
      if (pvVar6 == (void *)0x0) goto LAB_00112a56;
      uVar7 = 0;
      if (*(int *)(puVar1 + 4) != 0) {
        uVar9 = 0;
        do {
          uVar8 = (ulong)uVar9;
          pcVar5 = strdup(*(char **)(puVar1[5] + uVar8 * 8));
          *(char **)((long)pvVar6 + uVar8 * 8) = pcVar5;
          pvVar6 = (void *)puVar4[5];
          if (*(long *)((long)pvVar6 + uVar8 * 8) == 0) {
            *(uint *)(puVar4 + 4) = uVar9;
            iVar2 = -2;
            goto LAB_00112816;
          }
          uVar7 = *(uint *)(puVar1 + 4);
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar7);
      }
    }
    *(uint *)(puVar4 + 4) = uVar7;
    FUN_00110c30(*(undefined8 *)(param_2 + 0x80));
    *(undefined8 **)(param_2 + 0x80) = puVar4;
    puVar4 = (undefined8 *)0x0;
    iVar2 = iVar3;
  }
  else {
    pcVar5 = strdup((char *)puVar1[3]);
    puVar4[3] = pcVar5;
    if (pcVar5 != (char *)0x0) goto LAB_0011290e;
LAB_00112a56:
    iVar2 = -2;
  }
LAB_00112816:
  FUN_00110c30(puVar4);
  return iVar2;
}



// Function: sshkey_is_shielded @ 0x12a70

bool sshkey_is_shielded(long param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_1 != 0) {
    bVar1 = *(long *)(param_1 + 0x88) != 0;
  }
  return bVar1;
}



// Function: sshkey_check_rsa_length @ 0x12b10

undefined8 sshkey_check_rsa_length(uint *param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  BIGNUM *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (((param_1 != (uint *)0x0) && (*(long *)(param_1 + 2) != 0)) && ((*param_1 & 0xfffffffb) == 0))
  {
    RSA_get0_key(*(long *)(param_1 + 2),&local_18,0,0);
    iVar1 = BN_num_bits(local_18);
    if ((iVar1 < 0x400) || (iVar1 < param_2)) {
      uVar2 = 0xffffffc8;
      goto LAB_00112b45;
    }
  }
  uVar2 = 0;
LAB_00112b45:
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_get_sigtype @ 0x12c20

int sshkey_get_sigtype(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  void *pvVar1;
  int iVar2;
  long lVar3;
  long in_FS_OFFSET;
  void *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = (void *)0x0;
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  lVar3 = FUN_0010b980();
  if (lVar3 == 0) {
    iVar2 = -2;
  }
  else {
    iVar2 = FUN_0011a6f0(lVar3,&local_28,0);
    pvVar1 = local_28;
    if ((iVar2 == 0) && (param_3 != (undefined8 *)0x0)) {
      local_28 = (void *)0x0;
      *param_3 = pvVar1;
    }
    free(local_28);
    FUN_0010bce0(lVar3);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_check_cert_sigtype @ 0x12d50

undefined8 sshkey_check_cert_sigtype(undefined4 *param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xfffffff6;
  }
  if (param_2 == 0) {
LAB_00112e48:
    uVar3 = 0xfffffff6;
  }
  else {
    iVar2 = FUN_0010e9c0(*param_1);
    if (iVar2 != 0) {
      if ((*(long *)(param_1 + 0x20) == 0) ||
         (lVar1 = *(long *)(*(long *)(param_1 + 0x20) + 0x58), lVar1 == 0)) goto LAB_00112e48;
      iVar2 = FUN_00120960(lVar1,param_2,0);
      if (iVar2 != 1) {
        return 0xffffffc6;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



// Function: sshkey_sigalg_by_name @ 0x12ee0

char * sshkey_sigalg_by_name(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined **ppuVar4;
  char *pcVar5;
  int iVar6;
  
  iVar6 = 3;
  pcVar5 = "ssh-ed25519";
  ppuVar4 = &PTR_s_ssh_ed25519_00166cc0;
  while (iVar1 = strcmp(pcVar5,param_1), iVar1 != 0) {
    iVar6 = *(int *)(ppuVar4 + 8);
    ppuVar4 = ppuVar4 + 5;
    if (iVar6 == -1) {
      return (char *)0x0;
    }
    pcVar5 = *ppuVar4;
  }
  pcVar3 = ppuVar4[2];
  if ((ppuVar4[2] == (char *)0x0) && (pcVar3 = pcVar5, *(int *)(ppuVar4 + 4) != 0)) {
    uVar2 = FUN_0010f440(iVar6);
    pcVar5 = (char *)FUN_0010d0a0(uVar2,*(undefined4 *)((long)ppuVar4 + 0x1c));
    return pcVar5;
  }
  return pcVar3;
}



// Function: sshkey_check_sigtype @ 0x13010

undefined8 sshkey_check_sigtype(undefined8 param_1,undefined8 param_2,long param_3)

{
  char *__ptr;
  int iVar1;
  char *__s1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = (char *)0x0;
  if (param_3 != 0) {
    __s1 = (char *)FUN_00112ee0(param_3);
    if (__s1 == (char *)0x0) {
      uVar2 = 0xfffffff6;
      goto LAB_0011306e;
    }
    uVar2 = FUN_00112c20(param_1,param_2,&local_28);
    __ptr = local_28;
    if ((int)uVar2 != 0) goto LAB_0011306e;
    iVar1 = strcmp(__s1,local_28);
    free(__ptr);
    if (iVar1 != 0) {
      uVar2 = 0xffffffc6;
      goto LAB_0011306e;
    }
  }
  uVar2 = 0;
LAB_0011306e:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_verify @ 0x13150

undefined8
sshkey_verify(undefined4 *param_1,undefined8 param_2,long param_3,undefined8 param_4,ulong param_5,
            undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  undefined8 uVar1;
  
  if (param_8 != (undefined8 *)0x0) {
    *param_8 = 0;
  }
  if ((param_3 != 0) && (param_5 < 0x100001)) {
    switch(*param_1) {
    case 0:
    case 4:
      uVar1 = FUN_0012e980();
      return uVar1;
    case 1:
    case 5:
      uVar1 = FUN_0012c0e0();
      return uVar1;
    case 2:
    case 6:
      uVar1 = FUN_0012c810();
      return uVar1;
    case 3:
    case 7:
      uVar1 = FUN_0012fa90();
      return uVar1;
    default:
      return 0xfffffff2;
    case 10:
    case 0xb:
      uVar1 = FUN_0012ce10();
      return uVar1;
    case 0xc:
    case 0xd:
      uVar1 = FUN_0012d610();
      return uVar1;
    }
  }
  return 0xfffffff6;
}



// Function: sshkey_to_certified @ 0x13320

undefined8 sshkey_to_certified(undefined4 *param_1)

{
  long lVar1;
  undefined4 uVar2;
  
  switch(*param_1) {
  case 0:
    uVar2 = 4;
    break;
  case 1:
    uVar2 = 5;
    break;
  case 2:
    uVar2 = 6;
    break;
  case 3:
    uVar2 = 7;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 0xb:
    return 0xfffffff6;
  case 10:
    uVar2 = 0xb;
    break;
  case 0xc:
    uVar2 = 0xd;
    break;
  default:
    return 0xfffffff6;
  }
  lVar1 = FUN_00110d40();
  *(long *)(param_1 + 0x20) = lVar1;
  if (lVar1 == 0) {
    return 0xfffffffe;
  }
  *param_1 = uVar2;
  return 0;
}



// Function: sshkey_drop_cert @ 0x13570

undefined8 sshkey_drop_cert(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0010e9c0(*param_1);
  if (iVar1 != 0) {
    FUN_00110c30(*(undefined8 *)(param_1 + 0x20));
    *(undefined8 *)(param_1 + 0x20) = 0;
    uVar2 = FUN_0010f440(*param_1);
    *param_1 = uVar2;
    return 0;
  }
  return 0xfffffff2;
}



// Function: sshkey_certify_custom @ 0x136c0

int sshkey_certify_custom(int *param_1,int *param_2,char *param_3,undefined8 param_4,undefined8 param_5,
                code *param_6,undefined8 param_7)

{
  long *plVar1;
  undefined8 uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  EC_GROUP *pEVar10;
  EC_POINT *pEVar11;
  undefined8 uVar12;
  char *pcVar13;
  char *pcVar14;
  ulong uVar15;
  char *pcVar16;
  long in_FS_OFFSET;
  void *local_c0;
  void *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  char *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 local_68 [40];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_c0 = (void *)0x0;
  local_b8 = (void *)0x0;
  local_a0 = (char *)0x0;
  if ((((param_1 == (int *)0x0) || (plVar1 = *(long **)(param_1 + 0x20), plVar1 == (long *)0x0)) ||
      (*plVar1 == 0)) || (param_2 == (int *)0x0)) {
LAB_00113b78:
    iVar4 = -10;
    goto LAB_00113821;
  }
  iVar4 = FUN_0010f3b0();
  if (iVar4 == 0) {
    iVar4 = -0xe;
    goto LAB_00113821;
  }
  iVar4 = *param_2;
  iVar5 = FUN_0010d300(iVar4);
  if (iVar5 == 0) {
LAB_00113b88:
    iVar4 = -0x13;
    goto LAB_00113821;
  }
  pcVar14 = (char *)plVar1[0xb];
  pcVar13 = param_3;
  if (param_3 == (char *)0x0) {
    pcVar13 = pcVar14;
    if ((pcVar14 == (char *)0x0) && (pcVar13 = param_3, iVar4 == 0)) {
      pcVar13 = "rsa-sha2-512";
    }
  }
  else if ((pcVar14 != (char *)0x0) && (iVar4 = strcmp(param_3,pcVar14), iVar4 != 0))
  goto LAB_00113b78;
  iVar4 = FUN_00111720(param_2,&local_c0,&local_b0);
  if (iVar4 != 0) goto LAB_00113b88;
  uVar2 = **(undefined8 **)(param_1 + 0x20);
  FUN_0010be60(uVar2);
  uVar7 = FUN_0010eaf0(param_1);
  iVar4 = FUN_0011b800(uVar2,uVar7);
  if (iVar4 != 0) goto LAB_001137df;
  thunk_FUN_00138930(local_68,0x20);
  iVar4 = FUN_0011b6c0(uVar2,local_68,0x20);
  if (iVar4 != 0) goto LAB_001137df;
  uVar6 = FUN_0013da20(*param_1,0xfffffffc);
  switch(uVar6) {
  case 0:
    RSA_get0_key(*(undefined8 *)(param_1 + 2),&local_98,&local_90,0);
    iVar4 = FUN_0011d610(uVar2,local_90);
    if (iVar4 == 0) {
      iVar4 = FUN_0011d610(uVar2,local_98);
joined_r0x00113a95:
      if (iVar4 == 0) goto LAB_00113982;
    }
    break;
  case 1:
    DSA_get0_pqg(*(undefined8 *)(param_1 + 4),&local_88,&local_80,&local_78);
    DSA_get0_key(*(undefined8 *)(param_1 + 4),&local_70,0);
    iVar4 = FUN_0011d610(uVar2,local_88);
    if ((((iVar4 != 0) || (iVar4 = FUN_0011d610(uVar2,local_80), iVar4 != 0)) ||
        (iVar4 = FUN_0011d610(uVar2,local_78), iVar4 != 0)) ||
       (iVar4 = FUN_0011d610(uVar2,local_70), iVar4 != 0)) break;
LAB_00113982:
    iVar4 = FUN_0011ae80(uVar2,*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x10));
    if (((iVar4 != 0) ||
        (iVar4 = FUN_0011afb0(uVar2,*(undefined4 *)(*(long *)(param_1 + 0x20) + 8)), iVar4 != 0)) ||
       (iVar4 = FUN_0011b800(uVar2,*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x18)), iVar4 != 0))
    break;
    lVar8 = FUN_0010b880();
    if (lVar8 == 0) {
      iVar4 = -2;
      pcVar14 = (char *)0x0;
      goto LAB_001137e5;
    }
    lVar9 = *(long *)(param_1 + 0x20);
    uVar15 = 0;
    if (*(int *)(lVar9 + 0x20) != 0) {
      do {
        iVar4 = FUN_0011b800(lVar8,*(undefined8 *)(*(long *)(lVar9 + 0x28) + uVar15 * 8));
        if (iVar4 != 0) {
          pcVar14 = (char *)0x0;
          goto LAB_001137e5;
        }
        lVar9 = *(long *)(param_1 + 0x20);
        uVar15 = uVar15 + 1;
      } while (uVar15 < *(uint *)(lVar9 + 0x20));
    }
    pcVar16 = (char *)0x0;
    iVar4 = FUN_0011b840(uVar2,lVar8);
    pvVar3 = local_c0;
    pcVar14 = (char *)0x0;
    if ((((iVar4 != 0) ||
         (iVar4 = FUN_0011ae80(uVar2,*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x30)), iVar4 != 0)
         ) || ((iVar4 = FUN_0011ae80(uVar2,*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x38)),
               pcVar14 = pcVar16, iVar4 != 0 ||
               (((iVar4 = FUN_0011b840(uVar2,*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x40)),
                 iVar4 != 0 ||
                 (iVar4 = FUN_0011b840(uVar2,*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x48)),
                 iVar4 != 0)) || (iVar4 = FUN_0011b6c0(uVar2,0,0), iVar4 != 0)))))) ||
       (iVar4 = FUN_0011b6c0(uVar2,pvVar3,local_b0), iVar4 != 0)) goto LAB_001137e5;
    uVar7 = FUN_0010c3d0(uVar2);
    uVar12 = FUN_0010c520(uVar2);
    iVar4 = (*param_6)(param_2,&local_b8,&local_a8,uVar12,uVar7,pcVar13,param_4,param_5,0,param_7);
    if ((iVar4 != 0) ||
       (iVar4 = FUN_00112c20(local_b8,local_a8,&local_a0), pcVar14 = local_a0, iVar4 != 0))
    goto LAB_001137e5;
    if ((pcVar13 != (char *)0x0) && (iVar4 = strcmp(pcVar13,local_a0), iVar4 != 0)) {
      iVar4 = -0x3a;
      goto LAB_001137e5;
    }
    if (*(long *)(*(long *)(param_1 + 0x20) + 0x58) == 0) {
      *(char **)(*(long *)(param_1 + 0x20) + 0x58) = pcVar14;
      local_a0 = (char *)0x0;
    }
    iVar4 = FUN_0011b6c0(uVar2,local_b8,local_a8);
    pcVar14 = local_a0;
    if (iVar4 != 0) goto LAB_001137e5;
    goto LAB_001137f5;
  case 2:
  case 7:
    uVar7 = FUN_00110400(param_1[6]);
    iVar4 = FUN_0011b800(uVar2,uVar7);
    if (iVar4 == 0) {
      pEVar10 = EC_KEY_get0_group(*(EC_KEY **)(param_1 + 8));
      pEVar11 = EC_KEY_get0_public_key(*(EC_KEY **)(param_1 + 8));
      iVar4 = FUN_0011d7d0(uVar2,pEVar11,pEVar10);
      if (iVar4 == 0) {
        if (*param_1 == 0xb) goto LAB_00113a87;
        goto LAB_00113982;
      }
    }
    break;
  case 3:
  case 9:
    iVar4 = FUN_0011b6c0(uVar2,*(undefined8 *)(param_1 + 0xc),0x20);
    if (iVar4 == 0) {
      if (*param_1 == 0xd) {
LAB_00113a87:
        iVar4 = FUN_0011b800(uVar2,*(undefined8 *)(param_1 + 0x18));
        goto joined_r0x00113a95;
      }
      goto LAB_00113982;
    }
    break;
  default:
    iVar4 = -10;
    lVar8 = 0;
    pcVar14 = (char *)0x0;
    goto LAB_001137e5;
  }
LAB_001137df:
  lVar8 = 0;
  pcVar14 = (char *)0x0;
LAB_001137e5:
  FUN_0010be60(uVar2);
LAB_001137f5:
  free(local_b8);
  free(local_c0);
  free(pcVar14);
  FUN_0010bce0(lVar8);
LAB_00113821:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



// Function: sshkey_certify @ 0x13d50

undefined8 sshkey_certify(void)

{
  FUN_001136c0();
  return 0;
}



// Function: sshkey_cert_check_authority @ 0x13df0

undefined8
sshkey_cert_check_authority(long param_1,int param_2,int param_3,int param_4,ulong param_5,char *param_6,
            undefined8 *param_7)

{
  char *__s2;
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  uint uVar4;
  
  if (param_7 == (undefined8 *)0x0) {
    uVar2 = 0xfffffff6;
  }
  else {
    iVar1 = FUN_0010f3b0();
    if (iVar1 == 0) {
      *param_7 = "Key is not a certificate";
      uVar2 = 0xffffffe7;
    }
    else {
      lVar3 = *(long *)(param_1 + 0x80);
      if (param_2 == 0) {
        if (*(int *)(lVar3 + 8) != 1) {
          *param_7 = "Certificate invalid: not a user certificate";
          return 0xffffffe7;
        }
      }
      else if (*(int *)(lVar3 + 8) != 2) {
        *param_7 = "Certificate invalid: not a host certificate";
        return 0xffffffe7;
      }
      if (param_5 < *(ulong *)(lVar3 + 0x30)) {
        *param_7 = "Certificate invalid: not yet valid";
        uVar2 = 0xffffffe7;
      }
      else if (param_5 < *(ulong *)(lVar3 + 0x38)) {
        if (*(int *)(lVar3 + 0x20) == 0) {
          if (param_3 != 0) {
            *param_7 = "Certificate lacks principal list";
            return 0xffffffe7;
          }
        }
        else if (param_6 != (char *)0x0) {
          uVar4 = 0;
          do {
            while (__s2 = *(char **)(*(long *)(lVar3 + 0x28) + (ulong)uVar4 * 8), param_4 != 0) {
              iVar1 = FUN_00120770(__s2,param_6);
              if (iVar1 != 0) goto LAB_00113e77;
              lVar3 = *(long *)(param_1 + 0x80);
              uVar4 = uVar4 + 1;
              if (*(uint *)(lVar3 + 0x20) <= uVar4) goto LAB_00113f91;
            }
            iVar1 = strcmp(param_6,__s2);
            if (iVar1 == 0) goto LAB_00113e77;
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(lVar3 + 0x20));
LAB_00113f91:
          *param_7 = "Certificate invalid: name is not a listed principal";
          return 0xffffffe7;
        }
LAB_00113e77:
        uVar2 = 0;
      }
      else {
        *param_7 = "Certificate invalid: expired";
        uVar2 = 0xffffffe7;
      }
    }
  }
  return uVar2;
}



// Function: sshkey_cert_check_authority_now @ 0x14040

undefined8
sshkey_cert_check_authority_now(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined8 param_5,undefined8 *param_6)

{
  time_t tVar1;
  undefined8 uVar2;
  
  tVar1 = time((time_t *)0x0);
  if (tVar1 < 0) {
    *param_6 = "Certificate invalid: not yet valid";
    uVar2 = 0xffffffe7;
  }
  else {
    uVar2 = FUN_00113df0(param_1,param_2,param_3,param_4,tVar1,param_5,param_6);
  }
  return uVar2;
}



// Function: sshkey_cert_check_host @ 0x14140

int sshkey_cert_check_host(long param_1,undefined8 param_2,undefined4 param_3,long param_4,undefined8 *param_5
                )

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar1 = FUN_00114040(param_1,1,0,param_3,param_2,param_5);
  if (iVar1 == 0) {
    lVar3 = FUN_0010c3d0(*(undefined8 *)(*(long *)(param_1 + 0x80) + 0x40));
    if (lVar3 == 0) {
      if (param_4 != 0) {
        iVar2 = FUN_00112d50(param_1,param_4);
        if (iVar2 != 0) {
          iVar1 = -0x19;
          *param_5 = "Certificate signed with disallowed algorithm";
        }
      }
    }
    else {
      iVar1 = -0x19;
      *param_5 = "Certificate contains unsupported critical options";
    }
  }
  return iVar1;
}



// Function: sshkey_format_cert_validity @ 0x14260

undefined8 sshkey_format_cert_validity(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  char *pcVar2;
  undefined1 *puVar3;
  long in_FS_OFFSET;
  undefined1 local_108 [32];
  undefined1 local_e8 [32];
  undefined1 local_c8 [136];
  long local_40;
  
  puVar3 = local_108;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_e8[0] = 0;
  local_108[0] = 0;
  if (*(long *)(param_1 + 0x30) == 0) {
    lVar1 = *(long *)(param_1 + 0x38);
    if (lVar1 == -1) {
      FUN_0013bee0(param_2,"forever");
      goto LAB_00114370;
    }
LAB_001142b1:
    FUN_0012a450(lVar1,local_e8,0x20);
    if (*(long *)(param_1 + 0x30) == 0) goto LAB_0011433a;
    if (*(long *)(param_1 + 0x38) == -1) {
LAB_00114420:
      pcVar2 = "after %s";
      goto LAB_00114349;
    }
    __snprintf_chk(local_c8,0x80,1,0x80,"from %s to %s",local_108,local_e8);
  }
  else {
    FUN_0012a450(*(long *)(param_1 + 0x30),local_108,0x20);
    lVar1 = *(long *)(param_1 + 0x38);
    if (lVar1 != -1) goto LAB_001142b1;
    if (*(long *)(param_1 + 0x30) != 0) goto LAB_00114420;
LAB_0011433a:
    puVar3 = local_e8;
    pcVar2 = "before %s";
LAB_00114349:
    __snprintf_chk(local_c8,0x80,1,0x80,pcVar2,puVar3);
  }
  FUN_0013bee0(param_2,local_c8,param_3);
LAB_00114370:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// Function: sshkey_ec_validate_public @ 0x14460

undefined4 sshkey_ec_validate_public(EC_GROUP *param_1,EC_POINT *param_2)

{
  int iVar1;
  int iVar2;
  EC_METHOD *meth;
  BIGNUM *x;
  BIGNUM *y;
  BIGNUM *order;
  BIGNUM *r;
  EC_POINT *r_00;
  BIGNUM *b;
  undefined4 local_44;
  
  meth = EC_GROUP_method_of(param_1);
  iVar1 = EC_METHOD_get_field_type(meth);
  if ((iVar1 != 0x196) || (iVar1 = EC_POINT_is_at_infinity(param_1,param_2), iVar1 != 0)) {
    local_44 = 0xffffffec;
    r = (BIGNUM *)0x0;
    y = (BIGNUM *)0x0;
    r_00 = (EC_POINT *)0x0;
    x = (BIGNUM *)0x0;
    order = (BIGNUM *)0x0;
    goto LAB_00114602;
  }
  x = BN_new();
  if (x == (BIGNUM *)0x0) {
    local_44 = 0xfffffffe;
    r = (BIGNUM *)0x0;
    y = (BIGNUM *)0x0;
    r_00 = (EC_POINT *)0x0;
    order = (BIGNUM *)0x0;
    goto LAB_00114602;
  }
  y = BN_new();
  if (y == (BIGNUM *)0x0) {
    local_44 = 0xfffffffe;
    r = (BIGNUM *)0x0;
    order = (BIGNUM *)0x0;
    r_00 = (EC_POINT *)0x0;
    goto LAB_00114602;
  }
  order = BN_new();
  if (order == (BIGNUM *)0x0) {
    local_44 = 0xfffffffe;
    r = (BIGNUM *)0x0;
    r_00 = (EC_POINT *)0x0;
    goto LAB_00114602;
  }
  r = BN_new();
  if (r == (BIGNUM *)0x0) {
    local_44 = 0xfffffffe;
    r_00 = (EC_POINT *)0x0;
    goto LAB_00114602;
  }
  iVar1 = EC_GROUP_get_order(param_1,order,(BN_CTX *)0x0);
  if ((iVar1 != 1) ||
     (iVar1 = EC_POINT_get_affine_coordinates_GFp(param_1,param_2,x,y,(BN_CTX *)0x0), iVar1 != 1)) {
    local_44 = 0xffffffea;
    r_00 = (EC_POINT *)0x0;
    goto LAB_00114602;
  }
  iVar1 = BN_num_bits(x);
  iVar2 = BN_num_bits(order);
  if (iVar2 / 2 < iVar1) {
    iVar1 = BN_num_bits(y);
    iVar2 = BN_num_bits(order);
    if (iVar2 / 2 < iVar1) {
      r_00 = EC_POINT_new(param_1);
      if (r_00 == (EC_POINT *)0x0) {
        local_44 = 0xfffffffe;
        goto LAB_00114602;
      }
      iVar1 = EC_POINT_mul(param_1,r_00,(BIGNUM *)0x0,param_2,order,(BN_CTX *)0x0);
      if (iVar1 == 1) {
        iVar1 = EC_POINT_is_at_infinity(param_1,r_00);
        if (iVar1 == 1) {
          b = BN_value_one();
          iVar1 = BN_sub(r,order,b);
          if (iVar1 == 0) goto LAB_00114700;
          iVar1 = BN_cmp(x,r);
          if (iVar1 < 0) {
            iVar1 = BN_cmp(y,r);
            local_44 = 0xffffffec;
            if (iVar1 < 0) {
              local_44 = 0;
            }
            goto LAB_00114602;
          }
        }
        local_44 = 0xffffffec;
      }
      else {
LAB_00114700:
        local_44 = 0xffffffea;
      }
      goto LAB_00114602;
    }
  }
  local_44 = 0xffffffec;
  r_00 = (EC_POINT *)0x0;
LAB_00114602:
  BN_clear_free(x);
  BN_clear_free(y);
  BN_clear_free(order);
  BN_clear_free(r);
  EC_POINT_free(r_00);
  return local_44;
}



// Function: sshkey_from_blob_internal @ 0x14780

int sshkey_from_blob_internal(undefined8 param_1,long *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  EC_KEY *key;
  EC_GROUP *pEVar7;
  long lVar8;
  EC_POINT *pub;
  long in_FS_OFFSET;
  void *local_90;
  void *local_88;
  long local_80;
  void *local_78;
  BIGNUM *local_70;
  BIGNUM *local_68;
  BIGNUM *local_60;
  BIGNUM *local_58;
  BIGNUM *local_50;
  BIGNUM *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_90 = (void *)0x0;
  local_88 = (void *)0x0;
  local_78 = (void *)0x0;
  local_70 = (BIGNUM *)0x0;
  local_68 = (BIGNUM *)0x0;
  local_60 = (BIGNUM *)0x0;
  local_58 = (BIGNUM *)0x0;
  local_50 = (BIGNUM *)0x0;
  local_48 = (BIGNUM *)0x0;
  if (param_2 != (long *)0x0) {
    *param_2 = 0;
  }
  lVar5 = FUN_0010c640(param_1);
  if (lVar5 == 0) goto LAB_00114d90;
  iVar2 = FUN_0011a6f0(param_1,&local_90,0);
  if (iVar2 != 0) goto LAB_00114d60;
  iVar2 = FUN_0010eb00(local_90);
  if ((param_3 == 0) && (iVar4 = FUN_0010e9c0(iVar2), iVar4 != 0)) {
    pub = (EC_POINT *)0x0;
    iVar4 = -0x13;
    goto LAB_00114a24;
  }
  switch(iVar2) {
  case 0:
switchD_00114863_caseD_0:
    lVar6 = FUN_00110ed0(iVar2);
    if (lVar6 == 0) goto LAB_00114d90;
    iVar2 = FUN_0011d220(param_1,&local_68);
    if ((iVar2 != 0) || (iVar2 = FUN_0011d220(param_1,&local_70), iVar2 != 0)) goto LAB_00114d30;
    iVar2 = RSA_set0_key(*(undefined8 *)(lVar6 + 8),local_70,local_68,0);
    if (iVar2 == 0) goto LAB_00114d40;
    local_68 = (BIGNUM *)0x0;
    local_70 = (BIGNUM *)0x0;
    iVar4 = FUN_00112b10(lVar6,0);
    if (iVar4 != 0) {
      pub = (EC_POINT *)0x0;
      goto LAB_00114a24;
    }
    goto LAB_00114c18;
  case 1:
    goto switchD_00114863_caseD_1;
  case 2:
  case 10:
    goto switchD_00114863_caseD_2;
  case 3:
  case 0xc:
    goto switchD_00114863_caseD_3;
  case 4:
    iVar4 = FUN_0011a460(param_1,0,0);
    if (iVar4 == 0) goto switchD_00114863_caseD_0;
    goto LAB_00114d60;
  case 5:
    break;
  case 6:
  case 0xb:
    iVar4 = FUN_0011a460(param_1,0,0);
    if (iVar4 != 0) goto LAB_00114d60;
switchD_00114863_caseD_2:
    lVar6 = FUN_00110ed0(iVar2);
    if (lVar6 == 0) goto LAB_00114d90;
    uVar3 = FUN_0010ebf0(local_90);
    *(undefined4 *)(lVar6 + 0x18) = uVar3;
    iVar4 = FUN_0011a6f0(param_1,&local_88,0);
    if (iVar4 != 0) goto LAB_00114d30;
    iVar4 = FUN_0010fa00(local_88);
    if (*(int *)(lVar6 + 0x18) != iVar4) {
      pub = (EC_POINT *)0x0;
      iVar4 = -0xf;
      goto LAB_00114a24;
    }
    EC_KEY_free(*(EC_KEY **)(lVar6 + 0x20));
    key = EC_KEY_new_by_curve_name(*(int *)(lVar6 + 0x18));
    *(EC_KEY **)(lVar6 + 0x20) = key;
    if (key == (EC_KEY *)0x0) {
      iVar4 = -0xc;
      pub = (EC_POINT *)0x0;
      goto LAB_00114a24;
    }
    pEVar7 = EC_KEY_get0_group(key);
    pub = EC_POINT_new(pEVar7);
    if (pub == (EC_POINT *)0x0) {
LAB_00114dae:
      iVar4 = -2;
      goto LAB_00114a24;
    }
    pEVar7 = EC_KEY_get0_group(*(EC_KEY **)(lVar6 + 0x20));
    iVar4 = FUN_0011d360(param_1,pub,pEVar7);
    if (iVar4 == 0) {
      pEVar7 = EC_KEY_get0_group(*(EC_KEY **)(lVar6 + 0x20));
      iVar4 = FUN_00114460(pEVar7,pub);
      if (iVar4 != 0) {
        iVar4 = -0x14;
        goto LAB_00114a24;
      }
      iVar4 = EC_KEY_set_public_key(*(EC_KEY **)(lVar6 + 0x20),pub);
      if (iVar4 != 1) goto LAB_00114dae;
      if ((iVar2 - 10U < 2) && (iVar2 = FUN_0011a6f0(param_1,lVar6 + 0x60,0), iVar2 != 0))
      goto LAB_00114d32;
      goto LAB_001149e2;
    }
    goto LAB_00114d32;
  case 7:
  case 0xd:
    iVar4 = FUN_0011a460(param_1,0,0);
    if (iVar4 != 0) goto LAB_00114d60;
switchD_00114863_caseD_3:
    iVar4 = FUN_0011a590(param_1,&local_78,&local_80);
    if (iVar4 != 0) {
      pub = (EC_POINT *)0x0;
      goto LAB_00114a24;
    }
    if (local_80 != 0x20) {
LAB_00114d60:
      pub = (EC_POINT *)0x0;
      iVar4 = -4;
      goto LAB_00114a24;
    }
    lVar6 = FUN_00110ed0(iVar2);
    if (lVar6 == 0) {
      pub = (EC_POINT *)0x0;
      goto LAB_00114dae;
    }
    if ((iVar2 - 0xcU < 2) && (iVar2 = FUN_0011a6f0(param_1,lVar6 + 0x60,0), iVar2 != 0))
    goto LAB_00114d30;
    pvVar1 = local_78;
    pub = (EC_POINT *)0x0;
    local_78 = (void *)0x0;
    *(void **)(lVar6 + 0x30) = pvVar1;
    goto LAB_001149e2;
  default:
    pub = (EC_POINT *)0x0;
    iVar4 = -0xe;
    goto LAB_00114a24;
  }
  iVar4 = FUN_0011a460(param_1,0,0);
  if (iVar4 != 0) goto LAB_00114d60;
switchD_00114863_caseD_1:
  lVar6 = FUN_00110ed0(iVar2);
  if (lVar6 == 0) {
LAB_00114d90:
    pub = (EC_POINT *)0x0;
    iVar4 = -2;
    goto LAB_00114a24;
  }
  iVar2 = FUN_0011d220(param_1,&local_60);
  if ((((iVar2 == 0) && (iVar2 = FUN_0011d220(param_1,&local_58), iVar2 == 0)) &&
      (iVar2 = FUN_0011d220(param_1,&local_50), iVar2 == 0)) &&
     (iVar2 = FUN_0011d220(param_1,&local_48), iVar2 == 0)) {
    iVar2 = DSA_set0_pqg(*(undefined8 *)(lVar6 + 0x10),local_60,local_58,local_50);
    if (iVar2 != 0) {
      local_50 = (BIGNUM *)0x0;
      local_58 = (BIGNUM *)0x0;
      local_60 = (BIGNUM *)0x0;
      iVar2 = DSA_set0_key(*(undefined8 *)(lVar6 + 0x10),local_48,0);
      if (iVar2 != 0) {
        local_48 = (BIGNUM *)0x0;
LAB_00114c18:
        pub = (EC_POINT *)0x0;
LAB_001149e2:
        iVar2 = FUN_0010f3b0(lVar6);
        if ((iVar2 != 0) && (iVar4 = FUN_00114ea0(param_1,lVar6,lVar5), iVar4 != 0))
        goto LAB_00114a24;
        lVar8 = FUN_0010c3d0(param_1);
        if (lVar8 == 0) {
          iVar4 = 0;
          if (param_2 != (long *)0x0) {
            *param_2 = lVar6;
          }
          goto LAB_00114a24;
        }
        goto LAB_00114d32;
      }
    }
LAB_00114d40:
    pub = (EC_POINT *)0x0;
    iVar4 = -0x16;
  }
  else {
LAB_00114d30:
    pub = (EC_POINT *)0x0;
LAB_00114d32:
    iVar4 = -4;
  }
LAB_00114a24:
  FUN_0010bce0(lVar5);
  FUN_00110a60();
  free((void *)0x0);
  free(local_90);
  free(local_88);
  free(local_78);
  BN_clear_free(local_70);
  BN_clear_free(local_68);
  BN_clear_free(local_60);
  BN_clear_free(local_58);
  BN_clear_free(local_50);
  BN_clear_free(local_48);
  EC_POINT_free(pub);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_from_blob @ 0x14dd0

undefined4 sshkey_from_blob(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_0010b980();
  if (lVar2 == 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    uVar1 = FUN_00114780(lVar2,param_3,1);
    FUN_0010bce0(lVar2);
  }
  return uVar1;
}



// Function: cert_parse @ 0x14ea0

int cert_parse(undefined8 param_1,long param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  long in_FS_OFFSET;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  undefined8 local_68;
  void *local_60;
  undefined8 local_58;
  undefined8 local_50;
  void *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = (void *)0x0;
  local_58 = 0;
  local_50 = 0;
  iVar3 = FUN_0011aad0(**(undefined8 **)(param_2 + 0x80),param_3);
  if (iVar3 != 0) goto LAB_00114f20;
  iVar3 = FUN_00119c10(param_1,*(long *)(param_2 + 0x80) + 0x10);
  if (((((((iVar3 == 0) && (iVar3 = FUN_00119cd0(param_1,*(long *)(param_2 + 0x80) + 8), iVar3 == 0)
          ) && (iVar3 = FUN_0011a6f0(param_1,*(long *)(param_2 + 0x80) + 0x18,&local_50), iVar3 == 0
               )) &&
        ((iVar3 = FUN_0011b8a0(param_1,&local_80), iVar3 == 0 &&
         (iVar3 = FUN_00119c10(param_1,*(long *)(param_2 + 0x80) + 0x30), iVar3 == 0)))) &&
       ((iVar3 = FUN_00119c10(param_1,*(long *)(param_2 + 0x80) + 0x38), iVar3 == 0 &&
        ((iVar3 = FUN_0011b8a0(param_1,&local_78), iVar3 == 0 &&
         (iVar3 = FUN_0011b8a0(param_1,&local_70), iVar3 == 0)))))) &&
      (iVar3 = FUN_0011a460(param_1,0,0), iVar3 == 0)) &&
     (iVar3 = FUN_0011b8a0(param_1,&local_68), iVar3 == 0)) {
    lVar5 = FUN_0010c3d0(**(undefined8 **)(param_2 + 0x80));
    lVar6 = FUN_0010c3d0(param_1);
    iVar3 = FUN_0011a590(param_1,&local_60,&local_58);
    if (iVar3 != 0) goto LAB_00114ff6;
    iVar3 = -0x12;
    if (*(int *)(*(long *)(param_2 + 0x80) + 8) - 1U < 2) {
      while (lVar8 = FUN_0010c3d0(local_80), lVar8 != 0) {
        local_48 = (void *)0x0;
        if ((0xff < *(uint *)(*(long *)(param_2 + 0x80) + 0x20)) ||
           (iVar3 = FUN_0011a6f0(local_80,&local_48,0), iVar3 != 0)) goto LAB_00114ff6;
        lVar8 = *(long *)(param_2 + 0x80);
        uVar9 = *(undefined8 *)(lVar8 + 0x28);
        uVar7 = FUN_0013ba50(uVar9,*(int *)(lVar8 + 0x20),*(int *)(lVar8 + 0x20) + 1,8);
        *(undefined8 *)(lVar8 + 0x28) = uVar7;
        lVar8 = *(long *)(param_2 + 0x80);
        if (*(long *)(lVar8 + 0x28) == 0) {
          iVar3 = -2;
          free(local_48);
          *(undefined8 *)(*(long *)(param_2 + 0x80) + 0x28) = uVar9;
          goto LAB_00114ffc;
        }
        uVar1 = *(uint *)(lVar8 + 0x20);
        *(uint *)(lVar8 + 0x20) = uVar1 + 1;
        *(void **)(*(long *)(lVar8 + 0x28) + (ulong)uVar1 * 8) = local_48;
      }
      iVar3 = FUN_0011aad0(*(undefined8 *)(*(long *)(param_2 + 0x80) + 0x40),local_78);
      if ((iVar3 == 0) &&
         ((local_70 == 0 ||
          (iVar3 = FUN_0011aad0(*(undefined8 *)(*(long *)(param_2 + 0x80) + 0x48)), iVar3 == 0)))) {
        do {
          lVar8 = FUN_0010c3d0(local_78);
          if (lVar8 == 0) goto LAB_001152b6;
          iVar3 = FUN_0011a460(local_78,0,0);
        } while ((iVar3 == 0) && (iVar3 = FUN_0011a460(local_78,0,0), iVar3 == 0));
        iVar3 = -4;
        FUN_0010be60(*(undefined8 *)(*(long *)(param_2 + 0x80) + 0x40));
      }
    }
  }
  else {
LAB_00114ff6:
    iVar3 = -4;
  }
LAB_00114ffc:
  FUN_0010bce0(local_68);
  FUN_0010bce0(local_78);
  FUN_0010bce0(local_70);
  FUN_0010bce0(local_80);
  free(local_60);
LAB_00114f20:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
  while ((iVar3 = FUN_0011a460(local_70,0,0), iVar3 == 0 &&
         (iVar3 = FUN_0011a460(local_70,0,0), iVar3 == 0))) {
LAB_001152b6:
    if ((local_70 == 0) || (lVar8 = FUN_0010c3d0(), lVar8 == 0)) {
      iVar3 = FUN_00114780(local_68,*(long *)(param_2 + 0x80) + 0x50,0);
      if (iVar3 == 0) {
        puVar2 = *(undefined8 **)(param_2 + 0x80);
        iVar3 = -0x13;
        iVar4 = FUN_0010d300(*(undefined4 *)puVar2[10]);
        if (iVar4 != 0) {
          uVar9 = FUN_0010c520(*puVar2);
          iVar3 = FUN_00113150(*(undefined8 *)(*(long *)(param_2 + 0x80) + 0x50),local_60,local_58,
                               uVar9,lVar5 - lVar6,0,0,0);
          if (iVar3 == 0) {
            iVar3 = FUN_00112c20(local_60,local_58,*(long *)(param_2 + 0x80) + 0x58);
          }
        }
      }
      else {
        iVar3 = -0x13;
      }
      goto LAB_00114ffc;
    }
  }
  FUN_0010be60(*(undefined8 *)(*(long *)(param_2 + 0x80) + 0x48));
  goto LAB_00114ff6;
}



// Function: sshkey_fromb @ 0x153a0

void sshkey_fromb(undefined8 param_1,undefined8 param_2)

{
  FUN_00114780(param_1,param_2,1);
  return;
}



// Function: sshkey_read @ 0x153b0

int sshkey_read(int *param_1,long *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  size_t sVar7;
  size_t sVar8;
  long lVar9;
  char *__ptr;
  char *pcVar10;
  long in_FS_OFFSET;
  int local_4c;
  int *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_4c = -1;
  if (param_1 == (int *)0x0) {
LAB_00115598:
    iVar4 = -10;
    goto LAB_0011559e;
  }
  iVar4 = *param_1;
  if (iVar4 < 8) {
    if (iVar4 < 0) goto LAB_00115598;
  }
  else if (4 < iVar4 - 10U) goto LAB_00115598;
  pcVar10 = (char *)*param_2;
  sVar7 = strcspn(pcVar10," \t");
  sVar8 = strlen(pcVar10);
  if ((sVar8 != sVar7) && (iVar3 = FUN_0010e6e0(pcVar10,sVar7,&local_4c), iVar3 != 0xe)) {
    pcVar10 = pcVar10 + sVar7;
    cVar2 = *pcVar10;
    if ((cVar2 == '\t') || (cVar2 == ' ')) {
      do {
        do {
          cVar2 = pcVar10[1];
          pcVar10 = pcVar10 + 1;
        } while (cVar2 == ' ');
      } while (cVar2 == '\t');
    }
    if (cVar2 != '\0') {
      if ((iVar4 == iVar3) || (iVar4 == 0xe)) {
        lVar9 = FUN_0010b880();
        if (lVar9 == 0) {
          iVar4 = -2;
        }
        else {
          sVar7 = strcspn(pcVar10," \t");
          __ptr = strndup(pcVar10,sVar7);
          if (__ptr == (char *)0x0) {
            iVar4 = -2;
            FUN_0010bce0(lVar9);
          }
          else {
            iVar4 = FUN_0011c390(lVar9,__ptr);
            if (iVar4 == 0) {
              free(__ptr);
              iVar4 = FUN_001153a0(lVar9,&local_48);
              if (iVar4 == 0) {
                FUN_0010bce0(lVar9);
                pcVar10 = pcVar10 + sVar7;
                cVar2 = *pcVar10;
                if (cVar2 != ' ') goto LAB_0011552d;
                do {
                  do {
                    cVar2 = pcVar10[1];
                    pcVar10 = pcVar10 + 1;
                  } while (cVar2 == ' ');
LAB_0011552d:
                } while (cVar2 == '\t');
                if (*local_48 == iVar3) {
                  iVar5 = FUN_0010d1e0(iVar3);
                  if ((iVar5 == 0) || (local_48[6] == local_4c)) {
                    *param_1 = iVar3;
                    iVar5 = FUN_0010f3b0(param_1);
                    piVar1 = local_48;
                    if (iVar5 != 0) {
                      iVar3 = FUN_0010f3b0(local_48);
                      if (iVar3 == 0) {
                        iVar4 = -0x10;
                        FUN_00110a60(local_48);
                        goto LAB_0011559e;
                      }
                      if (*(long *)(param_1 + 0x20) != 0) {
                        FUN_00110c30();
                      }
                      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(local_48 + 0x20);
                      piVar1[0x20] = 0;
                      piVar1[0x21] = 0;
                      iVar3 = *param_1;
                    }
                    uVar6 = FUN_0010f440(iVar3);
                    switch(uVar6) {
                    case 0:
                      RSA_free(*(RSA **)(param_1 + 2));
                      *(undefined8 *)(param_1 + 2) = *(undefined8 *)(local_48 + 2);
                      piVar1[2] = 0;
                      piVar1[3] = 0;
                      break;
                    case 1:
                      DSA_free(*(DSA **)(param_1 + 4));
                      *(undefined8 *)(param_1 + 4) = *(undefined8 *)(local_48 + 4);
                      piVar1[4] = 0;
                      piVar1[5] = 0;
                      break;
                    case 2:
                      EC_KEY_free(*(EC_KEY **)(param_1 + 8));
                      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(local_48 + 8);
                      param_1[6] = local_48[6];
                      piVar1[8] = 0;
                      piVar1[9] = 0;
                      local_48[6] = -1;
                      break;
                    case 3:
                      FUN_0013b0d0(*(undefined8 *)(param_1 + 0xc),0x20);
                      *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(local_48 + 0xc);
                      piVar1[0xc] = 0;
                      piVar1[0xd] = 0;
                      break;
                    default:
                      iVar4 = -1;
                      FUN_00110a60(local_48);
                      goto LAB_0011559e;
                    case 10:
                      EC_KEY_free(*(EC_KEY **)(param_1 + 8));
                      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(local_48 + 8);
                      param_1[6] = local_48[6];
                      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(local_48 + 0x18);
                      piVar1[8] = 0;
                      piVar1[9] = 0;
                      local_48[6] = -1;
                      piVar1[0x18] = 0;
                      piVar1[0x19] = 0;
                      break;
                    case 0xc:
                      FUN_0013b0d0(*(undefined8 *)(param_1 + 0xc),0x20);
                      *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(local_48 + 0xc);
                      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(local_48 + 0x18);
                      piVar1[0xc] = 0;
                      piVar1[0xd] = 0;
                      piVar1[0x18] = 0;
                      piVar1[0x19] = 0;
                    }
                    FUN_00110a60(local_48);
                    *param_2 = (long)pcVar10;
                  }
                  else {
                    iVar4 = -0xf;
                    FUN_00110a60(local_48);
                  }
                }
                else {
                  iVar4 = -0xd;
                  FUN_00110a60(local_48);
                }
              }
              else {
                FUN_0010bce0(lVar9);
              }
            }
            else {
              free(__ptr);
              FUN_0010bce0(lVar9);
            }
          }
        }
      }
      else {
        iVar4 = -0xd;
      }
      goto LAB_0011559e;
    }
  }
  iVar4 = -4;
LAB_0011559e:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_froms @ 0x15840

int sshkey_froms(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined8 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_0011b8a0(param_1,&local_28);
  if (iVar1 == 0) {
    iVar1 = FUN_00114780(local_28,param_2,1);
    FUN_0010bce0(local_28);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_parse_private2_pubkey @ 0x15930

int sshkey_parse_private2_pubkey(undefined8 param_1,int param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  long in_FS_OFFSET;
  int local_44;
  undefined8 local_40;
  undefined4 *local_38;
  long local_30;
  undefined4 *puVar6;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_44 = 0;
  local_40 = 0;
  local_38 = (undefined4 *)0x0;
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  iVar2 = FUN_0010e4a0(param_1,&local_40);
  uVar1 = local_40;
  if (iVar2 == 0) {
    puVar6 = (undefined4 *)0x0;
    puVar5 = (undefined4 *)0x0;
    iVar2 = FUN_0010cc80(local_40,0xf);
    if (iVar2 != 0) goto LAB_00115994;
    iVar2 = FUN_0011a460(uVar1,0,0);
    if (iVar2 != 0) goto LAB_00115994;
    iVar2 = FUN_0011a460(uVar1,0,0);
    if (iVar2 != 0) goto LAB_00115994;
    iVar2 = FUN_0011a460(uVar1,0,0);
    puVar6 = puVar5;
    if (iVar2 != 0) goto LAB_00115994;
    iVar2 = FUN_00119cd0(uVar1,&local_44);
    if (iVar2 != 0) goto LAB_00115994;
    if (local_44 != 1) {
      iVar2 = -4;
      goto LAB_00115994;
    }
    iVar2 = FUN_00115840(uVar1,&local_38);
    puVar6 = local_38;
    if (iVar2 != 0) goto LAB_00115994;
    if (param_2 != 0xe) {
      iVar3 = FUN_0010f440(param_2);
      iVar4 = FUN_0010f440(*puVar6);
      if (iVar3 != iVar4) {
        iVar2 = -0xd;
        goto LAB_00115994;
      }
    }
    if (param_3 == (undefined8 *)0x0) goto LAB_00115994;
    *param_3 = puVar6;
  }
  puVar6 = (undefined4 *)0x0;
LAB_00115994:
  FUN_0010bce0(uVar1);
  FUN_00110a60(puVar6);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_ec_validate_private @ 0x161f0

uint sshkey_ec_validate_private(EC_KEY *param_1)

{
  int iVar1;
  int iVar2;
  BIGNUM *order;
  BIGNUM *r;
  EC_GROUP *group;
  BIGNUM *pBVar3;
  uint uVar4;
  
  order = BN_new();
  if (order != (BIGNUM *)0x0) {
    r = BN_new();
    if (r != (BIGNUM *)0x0) {
      group = EC_KEY_get0_group(param_1);
      iVar1 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
      if (iVar1 == 1) {
        pBVar3 = EC_KEY_get0_private_key(param_1);
        iVar1 = BN_num_bits(pBVar3);
        iVar2 = BN_num_bits(order);
        if (iVar1 <= iVar2 / 2) {
          uVar4 = 0xffffffec;
          goto LAB_001162a7;
        }
        pBVar3 = BN_value_one();
        iVar1 = BN_sub(r,order,pBVar3);
        if (iVar1 != 0) {
          pBVar3 = EC_KEY_get0_private_key(param_1);
          iVar1 = BN_cmp(pBVar3,r);
          uVar4 = ~(iVar1 >> 0x1f) & 0xffffffec;
          goto LAB_001162a7;
        }
      }
      uVar4 = 0xffffffea;
      goto LAB_001162a7;
    }
  }
  uVar4 = 0xfffffffe;
  r = (BIGNUM *)0x0;
LAB_001162a7:
  BN_clear_free(order);
  BN_clear_free(r);
  return uVar4;
}



// Function: sshkey_private_deserialize @ 0x16380

int sshkey_private_deserialize(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  long lVar8;
  EC_GROUP *pEVar9;
  EC_KEY *pEVar10;
  char *__s1;
  void *__s1_00;
  long in_FS_OFFSET;
  void *local_d8;
  void *local_d0;
  uint *local_c8;
  long local_c0;
  long local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  BIGNUM *local_a0;
  BIGNUM *local_98;
  BIGNUM *local_90;
  BIGNUM *local_88;
  BIGNUM *local_80;
  BIGNUM *local_78;
  BIGNUM *local_70;
  BIGNUM *local_68;
  BIGNUM *local_60;
  BIGNUM *local_58;
  BIGNUM *local_50;
  BIGNUM *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_d8 = (void *)0x0;
  local_d0 = (void *)0x0;
  local_c8 = (uint *)0x0;
  local_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = (BIGNUM *)0x0;
  local_98 = (BIGNUM *)0x0;
  local_90 = (BIGNUM *)0x0;
  local_88 = (BIGNUM *)0x0;
  local_80 = (BIGNUM *)0x0;
  local_78 = (BIGNUM *)0x0;
  local_70 = (BIGNUM *)0x0;
  local_68 = (BIGNUM *)0x0;
  local_60 = (BIGNUM *)0x0;
  local_58 = (BIGNUM *)0x0;
  local_50 = (BIGNUM *)0x0;
  local_48 = (BIGNUM *)0x0;
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  iVar3 = FUN_0011a6f0(param_1,&local_d8,0);
  if (iVar3 != 0) {
    puVar7 = (uint *)0x0;
    __s1_00 = (void *)0x0;
    __s1 = (char *)0x0;
    iVar5 = iVar3;
    goto LAB_00116497;
  }
  uVar4 = FUN_0010eb00(local_d8);
  iVar5 = FUN_0010e9c0(uVar4);
  if (iVar5 == 0) {
    __s1_00 = (void *)0x0;
    __s1 = (char *)0x0;
    puVar7 = (uint *)FUN_00110ed0(uVar4);
    local_c8 = puVar7;
    if (puVar7 != (uint *)0x0) goto LAB_001166be;
    goto LAB_00116d4c;
  }
  iVar5 = FUN_00115840(param_1,&local_c8);
  puVar7 = local_c8;
  if (iVar5 != 0) {
    __s1_00 = (void *)0x0;
    __s1 = (char *)0x0;
    goto LAB_00116497;
  }
  if ((*local_c8 != uVar4) || ((uVar4 == 2 && (uVar6 = FUN_0010ebf0(local_d8), puVar7[6] != uVar6)))
     ) {
    __s1_00 = (void *)0x0;
    __s1 = (char *)0x0;
    iVar5 = -0x2d;
    goto LAB_00116497;
  }
  __s1 = *(char **)(puVar7 + 0x18);
  __s1_00 = *(void **)(puVar7 + 0xc);
  puVar7[0x18] = 0;
  puVar7[0x19] = 0;
  puVar7[0xc] = 0;
  puVar7[0xd] = 0;
LAB_001166be:
  switch(uVar4) {
  case 0:
    iVar5 = FUN_0011d220(param_1,&local_98);
    if ((iVar5 != 0) || (iVar5 = FUN_0011d220(param_1,&local_90), iVar5 != 0)) goto LAB_00116497;
    iVar5 = RSA_set0_key(*(undefined8 *)(puVar7 + 2),local_98,local_90,0);
    if (iVar5 == 0) break;
    local_90 = (BIGNUM *)0x0;
    local_98 = (BIGNUM *)0x0;
  case 4:
    iVar5 = FUN_0011d220(param_1,&local_88);
    if (((iVar5 != 0) || (iVar5 = FUN_0011d220(param_1,&local_80), iVar5 != 0)) ||
       ((iVar5 = FUN_0011d220(param_1,&local_78), iVar5 != 0 ||
        (iVar5 = FUN_0011d220(param_1,&local_70), iVar5 != 0)))) goto LAB_00116497;
    iVar5 = RSA_set0_key(*(undefined8 *)(puVar7 + 2),0,0,local_88);
    if (iVar5 != 0) {
      local_88 = (BIGNUM *)0x0;
      iVar5 = RSA_set0_factors(*(undefined8 *)(puVar7 + 2),local_78,local_70);
      if (iVar5 != 0) {
        local_70 = (BIGNUM *)0x0;
        local_78 = (BIGNUM *)0x0;
        iVar5 = FUN_00112b10(puVar7,0);
        if (iVar5 != 0) goto LAB_00116497;
        iVar5 = FUN_0012e2e0(puVar7);
joined_r0x00116bf0:
        if (iVar5 != 0) goto LAB_00116497;
LAB_00116820:
        if (((*puVar7 & 0xfffffffb) != 0) ||
           (iVar5 = RSA_blinding_on(*(RSA **)(puVar7 + 2),(BN_CTX *)0x0), iVar5 == 1)) {
          if (((__s1 == (char *)0x0) ||
              ((*(char **)(puVar7 + 0x18) != (char *)0x0 &&
               (iVar5 = strcmp(__s1,*(char **)(puVar7 + 0x18)), iVar5 == 0)))) &&
             ((__s1_00 == (void *)0x0 ||
              ((*(void **)(puVar7 + 0xc) != (void *)0x0 &&
               (iVar5 = memcmp(__s1_00,*(void **)(puVar7 + 0xc),0x20), iVar5 == 0)))))) {
            iVar5 = iVar3;
            if (param_2 != (undefined8 *)0x0) {
              *param_2 = puVar7;
              puVar7 = (uint *)0x0;
            }
          }
          else {
            iVar5 = -0x2d;
          }
          goto LAB_00116497;
        }
      }
    }
    break;
  case 1:
    iVar5 = FUN_0011d220(param_1,&local_68);
    if ((((iVar5 != 0) || (iVar5 = FUN_0011d220(param_1,&local_60), iVar5 != 0)) ||
        (iVar5 = FUN_0011d220(param_1,&local_58), iVar5 != 0)) ||
       (iVar5 = FUN_0011d220(param_1,&local_50), iVar5 != 0)) goto LAB_00116497;
    iVar5 = DSA_set0_pqg(*(undefined8 *)(puVar7 + 4),local_68,local_60,local_58);
    if (iVar5 != 0) {
      local_58 = (BIGNUM *)0x0;
      local_60 = (BIGNUM *)0x0;
      local_68 = (BIGNUM *)0x0;
      iVar5 = DSA_set0_key(*(undefined8 *)(puVar7 + 4),local_50,0);
      if (iVar5 != 0) {
        local_50 = (BIGNUM *)0x0;
        goto switchD_001166d5_caseD_5;
      }
    }
    break;
  case 2:
    uVar4 = FUN_0010ebf0(local_d8);
    puVar7[6] = uVar4;
    if (uVar4 == 0xffffffff) {
LAB_00116d78:
      iVar5 = -10;
      goto LAB_00116497;
    }
    iVar5 = FUN_0011a6f0(param_1,&local_d0,0);
    if (iVar5 != 0) goto LAB_00116497;
    uVar4 = puVar7[6];
    uVar6 = FUN_0010fa00(local_d0);
    if (uVar4 != uVar6) {
LAB_00116d57:
      iVar5 = -0xf;
      goto LAB_00116497;
    }
    pEVar10 = EC_KEY_new_by_curve_name(uVar4);
    *(EC_KEY **)(puVar7 + 8) = pEVar10;
    if (pEVar10 == (EC_KEY *)0x0) break;
    iVar5 = FUN_0011d480(param_1,pEVar10);
    if (iVar5 != 0) goto LAB_00116497;
  case 6:
    iVar5 = FUN_0011d220(param_1,&local_a0);
    if (iVar5 != 0) goto LAB_00116497;
    iVar5 = EC_KEY_set_private_key(*(EC_KEY **)(puVar7 + 8),local_a0);
    if (iVar5 != 1) break;
    EC_KEY_get0_public_key(*(EC_KEY **)(puVar7 + 8));
    pEVar9 = EC_KEY_get0_group(*(EC_KEY **)(puVar7 + 8));
    iVar5 = FUN_00114460(pEVar9);
    if (iVar5 != 0) goto LAB_00116497;
    iVar5 = FUN_001161f0(*(undefined8 *)(puVar7 + 8));
    goto joined_r0x00116bf0;
  case 3:
  case 7:
    iVar5 = FUN_0011a590(param_1,&local_b0,&local_c0);
    if ((iVar5 != 0) ||
       (iVar5 = FUN_0011a590(param_1,&local_a8,&local_b8), uVar2 = local_a8, uVar1 = local_b0,
       iVar5 != 0)) goto LAB_00116497;
    if ((local_c0 != 0x20) || (local_b8 != 0x40)) {
LAB_00116d62:
      iVar5 = -4;
      goto LAB_00116497;
    }
    local_b0 = 0;
    *(undefined8 *)(puVar7 + 0xc) = uVar1;
    local_a8 = 0;
    *(undefined8 *)(puVar7 + 10) = uVar2;
    goto LAB_00116820;
  case 5:
switchD_001166d5_caseD_5:
    iVar5 = FUN_0011d220(param_1);
    if (iVar5 != 0) goto LAB_00116497;
    iVar5 = DSA_set0_key(*(undefined8 *)(puVar7 + 4),0,local_48);
    if (iVar5 != 0) {
      local_48 = (BIGNUM *)0x0;
      goto LAB_00116820;
    }
    break;
  default:
    iVar5 = -0xe;
    goto LAB_00116497;
  case 10:
    uVar4 = FUN_0010ebf0(local_d8);
    puVar7[6] = uVar4;
    if (uVar4 == 0xffffffff) goto LAB_00116d78;
    iVar5 = FUN_0011a6f0(param_1,&local_d0,0);
    if (iVar5 != 0) goto LAB_00116497;
    uVar4 = FUN_0010fa00(local_d0);
    if (puVar7[6] != uVar4) goto LAB_00116d57;
    lVar8 = FUN_0010b880();
    *(long *)(puVar7 + 0x1c) = lVar8;
    if (lVar8 != 0) {
      lVar8 = FUN_0010b880();
      *(long *)(puVar7 + 0x1e) = lVar8;
      if (lVar8 != 0) {
        pEVar10 = EC_KEY_new_by_curve_name(puVar7[6]);
        *(EC_KEY **)(puVar7 + 8) = pEVar10;
        if (pEVar10 != (EC_KEY *)0x0) {
          iVar5 = FUN_0011d480(param_1,pEVar10);
          if (iVar5 != 0) goto LAB_00116497;
          goto LAB_00116b7c;
        }
        break;
      }
    }
    goto LAB_00116d4c;
  case 0xb:
    lVar8 = FUN_0010b880();
    *(long *)(puVar7 + 0x1c) = lVar8;
    if (lVar8 == 0) goto LAB_00116d4c;
    lVar8 = FUN_0010b880();
    *(long *)(puVar7 + 0x1e) = lVar8;
    if (lVar8 == 0) goto LAB_00116d4c;
LAB_00116b7c:
    iVar5 = FUN_0011a6f0(param_1,puVar7 + 0x18,0);
    if (((iVar5 != 0) || (iVar5 = FUN_00119e50(param_1,puVar7 + 0x1a), iVar5 != 0)) ||
       ((iVar5 = FUN_0011a8b0(param_1,*(undefined8 *)(puVar7 + 0x1c)), iVar5 != 0 ||
        (iVar5 = FUN_0011a8b0(param_1,*(undefined8 *)(puVar7 + 0x1e)), iVar5 != 0))))
    goto LAB_00116497;
    EC_KEY_get0_public_key(*(EC_KEY **)(puVar7 + 8));
    pEVar9 = EC_KEY_get0_group(*(EC_KEY **)(puVar7 + 8));
    iVar5 = FUN_00114460(pEVar9);
    goto joined_r0x00116bf0;
  case 0xc:
  case 0xd:
    iVar5 = FUN_0011a590(param_1,&local_b0,&local_c0);
    if (iVar5 != 0) goto LAB_00116497;
    if (local_c0 != 0x20) goto LAB_00116d62;
    lVar8 = FUN_0010b880();
    *(long *)(puVar7 + 0x1c) = lVar8;
    if (lVar8 != 0) {
      lVar8 = FUN_0010b880();
      *(long *)(puVar7 + 0x1e) = lVar8;
      if (lVar8 != 0) {
        iVar5 = FUN_0011a6f0(param_1,puVar7 + 0x18,0);
        if ((((iVar5 != 0) || (iVar5 = FUN_00119e50(param_1,puVar7 + 0x1a), iVar5 != 0)) ||
            (iVar5 = FUN_0011a8b0(param_1,*(undefined8 *)(puVar7 + 0x1c)), iVar5 != 0)) ||
           (iVar5 = FUN_0011a8b0(param_1), uVar1 = local_b0, iVar5 != 0)) goto LAB_00116497;
        local_b0 = 0;
        *(undefined8 *)(puVar7 + 0xc) = uVar1;
        goto LAB_00116820;
      }
    }
LAB_00116d4c:
    iVar5 = -2;
    goto LAB_00116497;
  }
  iVar5 = -0x16;
LAB_00116497:
  free(local_d8);
  free(local_d0);
  BN_clear_free(local_a0);
  BN_clear_free(local_68);
  BN_clear_free(local_60);
  BN_clear_free(local_58);
  BN_clear_free(local_50);
  BN_clear_free(local_48);
  BN_clear_free(local_98);
  BN_clear_free(local_90);
  BN_clear_free(local_88);
  BN_clear_free(local_78);
  BN_clear_free(local_70);
  BN_clear_free(local_80);
  FUN_00110a60(puVar7);
  FUN_0013b0d0(local_b0,local_c0);
  FUN_0013b0d0(local_a8,local_b8);
  free((void *)0x0);
  FUN_0013b0d0(0,local_c0);
  FUN_0013b0d0(0,local_b8);
  free(__s1);
  free(__s1_00);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



// Function: sshkey_unshield_private @ 0x16d90

int sshkey_unshield_private(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  long in_FS_OFFSET;
  byte bVar12;
  undefined8 local_150;
  undefined8 local_148;
  undefined4 *local_140;
  undefined4 local_138 [44];
  undefined1 local_88 [72];
  long local_40;
  
  bVar12 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_148 = 0;
  local_140 = (undefined4 *)0x0;
  iVar1 = FUN_00112a70();
  iVar2 = 0;
  if (iVar1 == 0) goto LAB_00116ddd;
  lVar6 = FUN_0011dff0("aes256-ctr");
  if (lVar6 == 0) {
    iVar2 = -10;
    lVar6 = 0;
    puVar11 = (undefined4 *)0x0;
  }
  else {
    iVar2 = FUN_0011dbf0(lVar6);
    iVar1 = FUN_0011ddc0(lVar6);
    uVar7 = FUN_00130050(4);
    if (uVar7 < (uint)(iVar2 + iVar1)) {
      lVar6 = 0;
      iVar2 = -1;
      puVar11 = (undefined4 *)0x0;
    }
    else {
      uVar7 = *(ulong *)(param_1 + 0x24);
      uVar3 = FUN_0011db60(lVar6);
      if ((uVar7 < uVar3) ||
         (uVar7 = *(ulong *)(param_1 + 0x24), uVar3 = FUN_0011db60(lVar6), uVar7 % (ulong)uVar3 != 0
         )) {
        lVar6 = 0;
        iVar2 = -4;
        puVar11 = (undefined4 *)0x0;
      }
      else {
        iVar2 = FUN_00130740(4,*(undefined8 *)(param_1 + 0x26),*(undefined8 *)(param_1 + 0x28),
                             local_88,0x40);
        if (iVar2 == 0) {
          uVar4 = FUN_0011ddc0(lVar6);
          uVar3 = FUN_0011dbf0(lVar6);
          uVar5 = FUN_0011dbf0(lVar6);
          iVar2 = FUN_0011e340(&local_148,lVar6,local_88,uVar5,local_88 + uVar3,uVar4);
          if (iVar2 == 0) {
            lVar6 = FUN_0010b880();
            if (lVar6 == 0) {
              iVar2 = -2;
              puVar11 = (undefined4 *)0x0;
            }
            else {
              iVar2 = FUN_0010cb20(lVar6,*(undefined8 *)(param_1 + 0x24),&local_150);
              if ((iVar2 == 0) &&
                 (iVar2 = FUN_0011e5a0(local_148,0,local_150,*(undefined8 *)(param_1 + 0x22),
                                       param_1[0x24],0,0), iVar2 == 0)) {
                iVar2 = FUN_00116380(lVar6,&local_140,0x117043);
                puVar11 = local_140;
                if ((iVar2 == 0) && (iVar2 = FUN_0010e200(lVar6), puVar11 = local_140, iVar2 == 0))
                {
                  puVar9 = local_140;
                  puVar10 = local_138;
                  for (lVar8 = 0x2a; lVar8 != 0; lVar8 = lVar8 + -1) {
                    *puVar10 = *puVar9;
                    puVar9 = puVar9 + (ulong)bVar12 * -2 + 1;
                    puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
                  }
                  puVar9 = param_1;
                  puVar10 = local_140;
                  for (lVar8 = 0x2a; lVar8 != 0; lVar8 = lVar8 + -1) {
                    *puVar10 = *puVar9;
                    puVar9 = puVar9 + (ulong)bVar12 * -2 + 1;
                    puVar10 = puVar10 + (ulong)bVar12 * -2 + 1;
                  }
                  puVar9 = local_138;
                  for (lVar8 = 0x2a; lVar8 != 0; lVar8 = lVar8 + -1) {
                    *param_1 = *puVar9;
                    puVar9 = puVar9 + (ulong)bVar12 * -2 + 1;
                    param_1 = param_1 + (ulong)bVar12 * -2 + 1;
                  }
                }
              }
              else {
                puVar11 = (undefined4 *)0x0;
              }
            }
            goto LAB_00116ee1;
          }
        }
        lVar6 = 0;
        puVar11 = (undefined4 *)0x0;
      }
    }
  }
LAB_00116ee1:
  FUN_0011e970(local_148);
  __explicit_bzero_chk(local_88,0x40,0x40);
  __explicit_bzero_chk(local_138,0xa8,0xa8);
  FUN_00110a60(puVar11);
  FUN_0010bce0(lVar6);
LAB_00116ddd:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



// Function: sshkey_private_serialize_opt @ 0x17120

int sshkey_private_serialize_opt(undefined4 *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  long in_FS_OFFSET;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  BIGNUM *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  BIGNUM *local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_00112a70();
  iVar2 = FUN_00116d90(param_1);
  if (iVar2 != 0) goto LAB_00117160;
  lVar3 = FUN_0010b880();
  if (lVar3 == 0) {
    iVar2 = -2;
    goto LAB_00117160;
  }
  uVar4 = FUN_0010eaf0(param_1);
  iVar2 = FUN_0011b800(lVar3,uVar4);
  if (iVar2 != 0) goto joined_r0x001172e0;
  switch(*param_1) {
  case 0:
    RSA_get0_key(*(undefined8 *)(param_1 + 2),&local_88,&local_80,&local_78);
    RSA_get0_factors(*(undefined8 *)(param_1 + 2),&local_68,&local_60);
    RSA_get0_crt_params(*(undefined8 *)(param_1 + 2),0,0,&local_70);
    iVar2 = FUN_0011d610(lVar3,local_88);
    if (iVar2 == 0) {
      iVar2 = FUN_0011d610(lVar3,local_80);
joined_r0x001174bf:
      if (((iVar2 == 0) && (iVar2 = FUN_0011d610(lVar3,local_78), iVar2 == 0)) &&
         (iVar2 = FUN_0011d610(lVar3,local_70), iVar2 == 0)) {
        iVar2 = FUN_0011d610(lVar3,local_68);
        local_38 = local_60;
        goto joined_r0x00117578;
      }
    }
    break;
  case 1:
    DSA_get0_pqg(*(undefined8 *)(param_1 + 4),&local_58,&local_50,&local_48);
    DSA_get0_key(*(undefined8 *)(param_1 + 4),&local_40,&local_38);
    iVar2 = FUN_0011d610(lVar3,local_58);
    if ((((iVar2 != 0) || (iVar2 = FUN_0011d610(lVar3,local_50), iVar2 != 0)) ||
        (iVar2 = FUN_0011d610(lVar3,local_48), iVar2 != 0)) ||
       (iVar2 = FUN_0011d610(lVar3,local_40), iVar2 != 0)) break;
LAB_00117518:
    iVar2 = FUN_0011d610(lVar3,local_38);
    goto joined_r0x001173b2;
  case 2:
    uVar4 = FUN_00110400(param_1[6]);
    iVar2 = FUN_0011b800(lVar3,uVar4);
    if (iVar2 == 0) {
      iVar2 = FUN_0011d940(lVar3,*(undefined8 *)(param_1 + 8));
joined_r0x001175c0:
      if (iVar2 == 0) {
        local_38 = EC_KEY_get0_private_key(*(EC_KEY **)(param_1 + 8));
        goto LAB_00117518;
      }
    }
    break;
  case 3:
    goto switchD_0011724a_caseD_3;
  case 4:
    if ((*(undefined8 **)(param_1 + 0x20) != (undefined8 *)0x0) &&
       (lVar5 = FUN_0010c3d0(**(undefined8 **)(param_1 + 0x20)), lVar5 != 0)) {
      RSA_get0_key(*(undefined8 *)(param_1 + 2),0,0,&local_78);
      RSA_get0_factors(*(undefined8 *)(param_1 + 2),&local_68,&local_60);
      RSA_get0_crt_params(*(undefined8 *)(param_1 + 2),0,0,&local_70);
      iVar2 = FUN_0011b840(lVar3,**(undefined8 **)(param_1 + 0x20));
      goto joined_r0x001174bf;
    }
    goto switchD_0011724a_caseD_8;
  case 5:
    if ((*(undefined8 **)(param_1 + 0x20) == (undefined8 *)0x0) ||
       (lVar5 = FUN_0010c3d0(**(undefined8 **)(param_1 + 0x20)), lVar5 == 0))
    goto switchD_0011724a_caseD_8;
    DSA_get0_key(*(undefined8 *)(param_1 + 4),0,&local_38);
    iVar2 = FUN_0011b840(lVar3,**(undefined8 **)(param_1 + 0x20));
joined_r0x00117578:
    if (iVar2 == 0) goto LAB_00117518;
    break;
  case 6:
    if ((*(undefined8 **)(param_1 + 0x20) != (undefined8 *)0x0) &&
       (lVar5 = FUN_0010c3d0(**(undefined8 **)(param_1 + 0x20)), lVar5 != 0)) {
      iVar2 = FUN_0011b840(lVar3,**(undefined8 **)(param_1 + 0x20));
      goto joined_r0x001175c0;
    }
    goto switchD_0011724a_caseD_8;
  case 7:
    if ((*(undefined8 **)(param_1 + 0x20) == (undefined8 *)0x0) ||
       (lVar5 = FUN_0010c3d0(**(undefined8 **)(param_1 + 0x20)), lVar5 == 0))
    goto switchD_0011724a_caseD_8;
    iVar2 = FUN_0011b840(lVar3,**(undefined8 **)(param_1 + 0x20));
    if (iVar2 != 0) break;
switchD_0011724a_caseD_3:
    iVar2 = FUN_0011b6c0(lVar3,*(undefined8 *)(param_1 + 0xc),0x20);
    if (iVar2 != 0) break;
    iVar2 = FUN_0011b6c0(lVar3,*(undefined8 *)(param_1 + 10),0x40);
joined_r0x001173b2:
    if (iVar2 != 0) break;
    if (iVar1 != 0) goto LAB_001172e2;
    goto LAB_001172f1;
  default:
    goto switchD_0011724a_caseD_8;
  case 10:
    uVar4 = FUN_00110400(param_1[6]);
    iVar2 = FUN_0011b800(lVar3,uVar4);
    if (iVar2 == 0) {
      iVar2 = FUN_0011d940(lVar3,*(undefined8 *)(param_1 + 8));
      goto joined_r0x00117356;
    }
    break;
  case 0xb:
    if ((*(undefined8 **)(param_1 + 0x20) != (undefined8 *)0x0) &&
       (lVar5 = FUN_0010c3d0(**(undefined8 **)(param_1 + 0x20)), lVar5 != 0)) {
      iVar2 = FUN_0011b840(lVar3,**(undefined8 **)(param_1 + 0x20));
      goto joined_r0x00117356;
    }
    goto switchD_0011724a_caseD_8;
  case 0xc:
switchD_0011724a_caseD_c:
    iVar2 = FUN_0011b6c0(lVar3,*(undefined8 *)(param_1 + 0xc),0x20);
joined_r0x00117356:
    if ((((iVar2 == 0) && (iVar2 = FUN_0011b800(lVar3,*(undefined8 *)(param_1 + 0x18)), iVar2 == 0))
        && (iVar2 = FUN_0011b180(lVar3,*(undefined1 *)(param_1 + 0x1a)), iVar2 == 0)) &&
       (iVar2 = FUN_0011b840(lVar3,*(undefined8 *)(param_1 + 0x1c)), iVar2 == 0)) {
      iVar2 = FUN_0011b840(lVar3,*(undefined8 *)(param_1 + 0x1e));
      goto joined_r0x001173b2;
    }
    break;
  case 0xd:
    if ((*(undefined8 **)(param_1 + 0x20) != (undefined8 *)0x0) &&
       (lVar5 = FUN_0010c3d0(**(undefined8 **)(param_1 + 0x20)), lVar5 != 0)) {
      iVar2 = FUN_0011b840(lVar3,**(undefined8 **)(param_1 + 0x20));
      if (iVar2 != 0) break;
      goto switchD_0011724a_caseD_c;
    }
switchD_0011724a_caseD_8:
    iVar2 = -10;
  }
joined_r0x001172e0:
  if (iVar1 != 0) {
LAB_001172e2:
    iVar2 = FUN_00117750(param_1);
    if (iVar2 == 0) {
LAB_001172f1:
      iVar2 = FUN_0011aad0(param_2,lVar3);
    }
  }
  FUN_0010bce0(lVar3);
LAB_00117160:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



// Function: sshkey_shield_private @ 0x17750

int sshkey_shield_private(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  long lVar6;
  ulong uVar7;
  void *pvVar8;
  long lVar9;
  size_t __size;
  void *pvVar10;
  undefined8 uVar11;
  char cVar12;
  undefined8 *puVar13;
  long in_FS_OFFSET;
  undefined8 local_148;
  undefined8 *local_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined1 local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_148 = 0;
  local_140 = (undefined8 *)0x0;
  lVar6 = FUN_0011dff0("aes256-ctr");
  if (lVar6 == 0) {
    puVar13 = (undefined8 *)0x0;
    pvVar8 = (void *)0x0;
    lVar9 = 0;
    iVar1 = -10;
    __size = 0;
    pvVar10 = (void *)0x0;
  }
  else {
    iVar1 = FUN_0011dbf0(lVar6);
    iVar2 = FUN_0011ddc0(lVar6);
    uVar7 = FUN_00130050(4);
    if (uVar7 < (uint)(iVar1 + iVar2)) {
      puVar13 = (undefined8 *)0x0;
      iVar1 = -1;
      __size = 0;
      pvVar10 = (void *)0x0;
      pvVar8 = (void *)0x0;
      lVar9 = 0;
    }
    else {
      pvVar8 = malloc(0x4000);
      if (pvVar8 == (void *)0x0) {
        puVar13 = (undefined8 *)0x0;
        pvVar10 = (void *)0x0;
        lVar9 = 0;
        iVar1 = -2;
        __size = 0;
      }
      else {
        thunk_FUN_00138930(pvVar8,0x4000);
        iVar1 = FUN_00130740(4,pvVar8,0x4000,local_88,0x40);
        if (iVar1 == 0) {
          uVar3 = FUN_0011ddc0(lVar6);
          uVar4 = FUN_0011dbf0(lVar6);
          uVar5 = FUN_0011dbf0(lVar6);
          iVar1 = FUN_0011e340(&local_148,lVar6,local_88,uVar5,local_88 + uVar4,uVar3);
          if (iVar1 == 0) {
            lVar9 = FUN_0010b880();
            if (lVar9 == 0) {
              puVar13 = (undefined8 *)0x0;
              pvVar10 = (void *)0x0;
              iVar1 = -2;
              __size = 0;
            }
            else {
              iVar1 = FUN_00112a70(param_1);
              if ((iVar1 == 0) || (iVar1 = FUN_00116d90(param_1), iVar1 == 0)) {
                cVar12 = '\0';
                iVar1 = FUN_00117120(param_1,lVar9,3);
                while (iVar1 == 0) {
                  uVar7 = FUN_0010c3d0(lVar9);
                  uVar4 = FUN_0011db60(lVar6);
                  if (uVar7 % (ulong)uVar4 == 0) {
                    __size = FUN_0010c3d0(lVar9);
                    pvVar10 = malloc(__size);
                    if (pvVar10 == (void *)0x0) {
                      puVar13 = (undefined8 *)0x0;
                      iVar1 = -2;
                    }
                    else {
                      uVar3 = FUN_0010c3d0(lVar9);
                      uVar11 = FUN_0010c520(lVar9);
                      iVar1 = FUN_0011e5a0(local_148,0,pvVar10,uVar11,uVar3,0,0);
                      puVar13 = (undefined8 *)0x0;
                      if ((iVar1 == 0) &&
                         (iVar1 = FUN_00112300(param_1,&local_140,0x117a41), puVar13 = local_140,
                         iVar1 == 0)) {
                        local_138 = *local_140;
                        uStack_130 = local_140[1];
                        local_128 = local_140[2];
                        uStack_120 = local_140[3];
                        local_118 = local_140[4];
                        uStack_110 = local_140[5];
                        local_108 = local_140[6];
                        uStack_100 = local_140[7];
                        uVar11 = param_1[1];
                        local_f8 = local_140[8];
                        uStack_f0 = local_140[9];
                        local_e8 = local_140[10];
                        uStack_e0 = local_140[0xb];
                        local_d8 = local_140[0xc];
                        uStack_d0 = local_140[0xd];
                        local_c8 = local_140[0xe];
                        uStack_c0 = local_140[0xf];
                        local_b8 = local_140[0x10];
                        uStack_b0 = local_140[0x11];
                        local_a8 = local_140[0x12];
                        uStack_a0 = local_140[0x13];
                        local_98 = local_140[0x14];
                        *local_140 = *param_1;
                        local_140[1] = uVar11;
                        uVar11 = param_1[3];
                        local_140[2] = param_1[2];
                        local_140[3] = uVar11;
                        uVar11 = param_1[5];
                        local_140[4] = param_1[4];
                        local_140[5] = uVar11;
                        uVar11 = param_1[7];
                        local_140[6] = param_1[6];
                        local_140[7] = uVar11;
                        uVar11 = param_1[9];
                        local_140[8] = param_1[8];
                        local_140[9] = uVar11;
                        uVar11 = param_1[0xb];
                        local_140[10] = param_1[10];
                        local_140[0xb] = uVar11;
                        uVar11 = param_1[0xd];
                        local_140[0xc] = param_1[0xc];
                        local_140[0xd] = uVar11;
                        uVar11 = param_1[0xf];
                        local_140[0xe] = param_1[0xe];
                        local_140[0xf] = uVar11;
                        uVar11 = param_1[0x11];
                        local_140[0x10] = param_1[0x10];
                        local_140[0x11] = uVar11;
                        uVar11 = param_1[0x13];
                        local_140[0x12] = param_1[0x12];
                        local_140[0x13] = uVar11;
                        local_140[0x14] = param_1[0x14];
                        *param_1 = local_138;
                        param_1[1] = uStack_130;
                        param_1[2] = local_128;
                        param_1[3] = uStack_120;
                        param_1[4] = local_118;
                        param_1[5] = uStack_110;
                        param_1[6] = local_108;
                        param_1[7] = uStack_100;
                        param_1[0x10] = local_b8;
                        param_1[0x11] = uStack_b0;
                        param_1[8] = local_f8;
                        param_1[9] = uStack_f0;
                        param_1[0x11] = pvVar10;
                        pvVar10 = (void *)0x0;
                        param_1[10] = local_e8;
                        param_1[0xb] = uStack_e0;
                        param_1[0xc] = local_d8;
                        param_1[0xd] = uStack_d0;
                        param_1[0xe] = local_c8;
                        param_1[0xf] = uStack_c0;
                        param_1[0x12] = __size;
                        __size = 0;
                        param_1[0x13] = pvVar8;
                        pvVar8 = (void *)0x0;
                        param_1[0x14] = 0x4000;
                        *(undefined1 *)(param_1 + 0xd) = *(undefined1 *)(local_140 + 0xd);
                      }
                    }
                    goto LAB_0011782f;
                  }
                  cVar12 = cVar12 + '\x01';
                  iVar1 = FUN_0011b180(lVar9,cVar12);
                }
              }
              __size = 0;
              pvVar10 = (void *)0x0;
              puVar13 = (undefined8 *)0x0;
            }
            goto LAB_0011782f;
          }
        }
        __size = 0;
        pvVar10 = (void *)0x0;
        lVar9 = 0;
        puVar13 = (undefined8 *)0x0;
      }
    }
  }
LAB_0011782f:
  FUN_0011e970(local_148);
  __explicit_bzero_chk(local_88,0x40,0x40);
  __explicit_bzero_chk(&local_138,0xa8,0xa8);
  FUN_0013b0d0(pvVar10,__size);
  FUN_0013b0d0(pvVar8,0x4000);
  FUN_00110a60(puVar13);
  FUN_0010bce0(lVar9);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshkey_private_serialize @ 0x17d00

void sshkey_private_serialize(undefined8 param_1,undefined8 param_2)

{
  FUN_00117120(param_1,param_2,0);
  return;
}



// Function: sshkey_private_to_blob2 @ 0x17d10

int sshkey_private_to_blob2(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4,
                char *param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  size_t sVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  void *pvVar11;
  ulong uVar12;
  long lVar13;
  undefined8 uVar14;
  size_t sVar15;
  char cVar16;
  long in_FS_OFFSET;
  char *local_d0;
  undefined1 *local_c8;
  long local_c0;
  undefined8 local_78;
  long local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_70 = 0;
  local_60 = 0;
  if (param_6 < 1) {
    param_6 = 0x10;
  }
  if ((param_3 == (char *)0x0) || (sVar7 = strlen(param_3), sVar7 == 0)) {
    param_5 = "none";
    local_d0 = "none";
  }
  else {
    local_d0 = "bcrypt";
    if (param_5 == (char *)0x0) {
      param_5 = "aes256-ctr";
    }
  }
  lVar8 = FUN_0011dff0(param_5);
  if (lVar8 == 0) {
    local_c0 = 0;
    lVar9 = 0;
    iVar5 = -10;
    lVar10 = 0;
  }
  else {
    local_c0 = FUN_0010b880();
    if (local_c0 == 0) {
      lVar10 = 0;
      lVar9 = 0;
      iVar5 = -2;
    }
    else {
      lVar9 = FUN_0010b880();
      if ((lVar9 == 0) || (lVar10 = FUN_0010b880(), lVar10 == 0)) {
        lVar10 = 0;
        iVar5 = -2;
      }
      else {
        uVar1 = FUN_0011db60(lVar8);
        uVar2 = FUN_0011dbf0(lVar8);
        uVar3 = FUN_0011ddc0(lVar8);
        uVar4 = FUN_0011dd30(lVar8);
        sVar7 = (ulong)uVar3 + (ulong)uVar2;
        pvVar11 = calloc(1,sVar7);
        if (pvVar11 != (void *)0x0) {
          iVar5 = strcmp(local_d0,"bcrypt");
          if (iVar5 == 0) {
            thunk_FUN_00138930(local_58,0x10);
            sVar15 = strlen(param_3);
            iVar5 = FUN_00139530(param_3,sVar15,local_58,0x10,pvVar11,sVar7);
            if (iVar5 < 0) {
              iVar5 = -10;
            }
            else {
              iVar5 = FUN_0011b6c0(local_c0,local_58,0x10);
              if ((iVar5 == 0) && (iVar5 = FUN_0011afb0(local_c0,param_6), iVar5 == 0))
              goto LAB_00117e73;
            }
          }
          else {
            iVar5 = strcmp(local_d0,"none");
            if (iVar5 == 0) {
LAB_00117e73:
              local_c8 = local_58;
              iVar5 = FUN_0011e340(&local_60,lVar8,pvVar11,uVar2,(long)pvVar11 + (ulong)uVar2,uVar3,
                                   1);
              if ((((iVar5 == 0) && (iVar5 = FUN_0011a9d0(lVar9,"openssh-key-v1",0xf), iVar5 == 0))
                  && (iVar5 = FUN_0011b800(lVar9,param_5), iVar5 == 0)) &&
                 (((iVar5 = FUN_0011b800(lVar9,local_d0), iVar5 == 0 &&
                   (iVar5 = FUN_0011b840(lVar9,local_c0), iVar5 == 0)) &&
                  (iVar5 = FUN_0011afb0(lVar9,1), iVar5 == 0)))) {
                iVar5 = FUN_00111720(param_1,&local_70,&local_68);
                lVar8 = local_70;
                if ((iVar5 == 0) && (iVar5 = FUN_0011b6c0(lVar9,local_70,local_68), iVar5 == 0)) {
                  uVar6 = FUN_00138a60();
                  iVar5 = FUN_0011afb0(lVar10,uVar6);
                  if ((iVar5 == 0) &&
                     (((iVar5 = FUN_0011afb0(lVar10,uVar6), iVar5 == 0 &&
                       (iVar5 = FUN_00117120(param_1,lVar10,2), iVar5 == 0)) &&
                      (iVar5 = FUN_0011b800(lVar10,param_4), iVar5 == 0)))) {
                    cVar16 = '\0';
                    do {
                      uVar12 = FUN_0010c3d0(lVar10);
                      if (uVar12 % (ulong)uVar1 == 0) {
                        uVar6 = FUN_0010c3d0(lVar10);
                        iVar5 = FUN_0011afb0(lVar9,uVar6);
                        if (iVar5 == 0) {
                          lVar13 = FUN_0010c3d0(lVar10);
                          iVar5 = FUN_0010cb20(lVar9,(ulong)uVar4 + lVar13,&local_78);
                          if (iVar5 == 0) {
                            uVar6 = FUN_0010c3d0(lVar10);
                            uVar14 = FUN_0010c520(lVar10);
                            iVar5 = FUN_0011e5a0(local_60,0,local_78,uVar14,uVar6,0);
                            if (iVar5 == 0) {
                              FUN_0010be60(param_2);
                              iVar5 = FUN_0011a9d0(param_2,"-----BEGIN OPENSSH PRIVATE KEY-----\n",
                                                   0x24);
                              if ((iVar5 == 0) &&
                                 (iVar5 = FUN_0011c140(lVar9,param_2,1), iVar5 == 0)) {
                                iVar5 = FUN_0011a9d0(param_2,"-----END OPENSSH PRIVATE KEY-----\n",
                                                     0x22);
                              }
                            }
                          }
                        }
                        break;
                      }
                      cVar16 = cVar16 + '\x01';
                      iVar5 = FUN_0011b180(lVar10,cVar16);
                    } while (iVar5 == 0);
                  }
                }
                FUN_0010bce0(local_c0);
                FUN_0010bce0(lVar9);
                FUN_0010bce0(lVar10);
                FUN_0011e970(local_60);
                __explicit_bzero_chk(local_c8,0x10,0x10);
                FUN_0013b0d0(pvVar11,sVar7);
                if (lVar8 != 0) {
                  FUN_0013b0d0(lVar8,local_68);
                }
                goto LAB_00117ef0;
              }
            }
            else {
              iVar5 = -0x2a;
            }
          }
          local_c8 = local_58;
          FUN_0010bce0(local_c0);
          FUN_0010bce0(lVar9);
          FUN_0010bce0(lVar10);
          FUN_0011e970(local_60);
          __explicit_bzero_chk(local_c8,0x10,0x10);
          FUN_0013b0d0(pvVar11,sVar7);
          goto LAB_00117ef0;
        }
        iVar5 = -2;
      }
    }
  }
  FUN_0010bce0(local_c0);
  FUN_0010bce0(lVar9);
  FUN_0010bce0(lVar10);
  FUN_0011e970(local_60);
  __explicit_bzero_chk(local_58,0x10,0x10);
LAB_00117ef0:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



// Function: sshkey_sign @ 0x183c0

int sshkey_sign(undefined4 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4,
                ulong param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                undefined4 param_9)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00112a70();
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_5 < 0x100001) {
    iVar2 = FUN_00116d90(param_1);
    if (iVar2 == 0) {
      switch(*param_1) {
      case 0:
      case 4:
        iVar2 = FUN_0012e5c0(param_1,param_2,param_3,param_4,param_5,param_6);
        break;
      case 1:
      case 5:
        iVar2 = FUN_0012bd90(param_1,param_2,param_3,param_4,param_5,param_9);
        break;
      case 2:
      case 6:
        iVar2 = FUN_0012c4e0(param_1,param_2,param_3,param_4,param_5,param_9);
        break;
      case 3:
      case 7:
        iVar2 = FUN_0012f820(param_1,param_2,param_3,param_4,param_5,param_9);
        break;
      default:
        iVar2 = -0xe;
        break;
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
        iVar2 = FUN_0010a4d0(param_7,param_1,param_2,param_3,param_4,param_5,param_9,param_8);
      }
      if ((iVar1 != 0) && (iVar1 = FUN_00117750(param_1), iVar1 != 0)) {
        iVar2 = iVar1;
      }
    }
  }
  else {
    iVar2 = -10;
  }
  return iVar2;
}



// Function: default_key_sign @ 0x185e0

undefined8 default_key_sign(void)

{
  undefined8 uVar1;
  long in_stack_00000020;
  
  if (in_stack_00000020 == 0) {
    uVar1 = FUN_001183c0();
    return uVar1;
  }
  return 0xfffffff6;
}



// Function: sshkey_parse_private2 @ 0x18a30

int sshkey_parse_private2(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4,
                undefined8 *param_5)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  long in_FS_OFFSET;
  void *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_68 = (void *)0x0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = (undefined4 *)0x0;
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = 0;
  }
  iVar2 = FUN_0010e4a0(param_1,&local_60);
  uVar1 = local_60;
  if (iVar2 == 0) {
    iVar2 = FUN_00115b30(local_60,param_3,&local_58,&local_48);
    puVar6 = local_48;
    uVar5 = local_58;
    if (iVar2 == 0) {
      if (param_2 != 0xe) {
        iVar2 = FUN_0010f440(param_2);
        iVar3 = FUN_0010f440(*puVar6);
        if (iVar2 != iVar3) {
          iVar2 = -0xd;
          uVar4 = 0;
          goto LAB_00118ac7;
        }
      }
      iVar2 = FUN_00116380(uVar5,&local_50);
      uVar4 = local_50;
      if (((iVar2 == 0) && (iVar2 = FUN_0011a6f0(uVar5,&local_68,0), uVar4 = local_50, iVar2 == 0))
         && (iVar2 = FUN_0010e200(uVar5), iVar2 == 0)) {
        iVar3 = FUN_00111490(puVar6,uVar4);
        if (iVar3 == 0) {
          iVar2 = -4;
        }
        else {
          if (param_4 != (undefined8 *)0x0) {
            *param_4 = uVar4;
            local_50 = 0;
          }
          uVar4 = local_50;
          if (param_5 != (undefined8 *)0x0) {
            *param_5 = local_68;
            local_68 = (void *)0x0;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    puVar6 = (undefined4 *)0x0;
    uVar5 = 0;
    uVar4 = 0;
  }
LAB_00118ac7:
  free(local_68);
  FUN_0010bce0(uVar1);
  FUN_0010bce0(uVar5);
  FUN_00110a60(uVar4);
  FUN_00110a60(puVar6);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



// Function: sshkey_parse_private_pem_fileblob @ 0x18ce0

int sshkey_parse_private_pem_fileblob(undefined8 param_1,int param_2,char *param_3,undefined8 *param_4)

{
  int iVar1;
  int iVar2;
  BIO_METHOD *type;
  BIO *b;
  ulong uVar3;
  void *data;
  EVP_PKEY *pkey;
  undefined4 *puVar4;
  ec_key_st *peVar5;
  long lVar6;
  EC_POINT *pEVar7;
  EC_GROUP *pEVar8;
  rsa_st *rsa;
  dsa_st *pdVar9;
  
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  type = BIO_s_mem();
  b = BIO_new(type);
  if ((b == (BIO *)0x0) || (uVar3 = FUN_0010c3d0(param_1), 0x7fffffff < uVar3)) {
    return -2;
  }
  iVar1 = FUN_0010c3d0(param_1);
  data = (void *)FUN_0010c520(param_1);
  iVar1 = BIO_write(b,data,iVar1);
  iVar2 = FUN_0010c3d0(param_1);
  if (iVar1 != iVar2) {
    iVar1 = -2;
    puVar4 = (undefined4 *)0x0;
    pkey = (EVP_PKEY *)0x0;
    goto LAB_00118d6f;
  }
  FUN_0010e340();
  pkey = PEM_read_bio_PrivateKey(b,(EVP_PKEY **)0x0,FUN_0010d650,param_3);
  if (pkey == (EVP_PKEY *)0x0) {
    if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
      iVar1 = FUN_0010e3e0();
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)0x0;
      iVar1 = -0x2b;
    }
    goto LAB_00118d6f;
  }
  iVar1 = EVP_PKEY_get_base_id(pkey);
  if ((iVar1 == 6) && ((param_2 == 0xe || (param_2 == 0)))) {
    iVar1 = -2;
    puVar4 = (undefined4 *)FUN_00110ed0(0xe);
    if (puVar4 == (undefined4 *)0x0) goto LAB_00118d6f;
    iVar1 = -0x16;
    rsa = EVP_PKEY_get1_RSA(pkey);
    *puVar4 = 0;
    *(rsa_st **)(puVar4 + 2) = rsa;
    iVar2 = RSA_blinding_on(rsa,(BN_CTX *)0x0);
    if (iVar2 != 1) goto LAB_00118d6f;
    iVar1 = FUN_00112b10(puVar4,0);
    iVar2 = iVar1;
joined_r0x00118f34:
    if (iVar2 != 0) goto LAB_00118d6f;
  }
  else {
    iVar1 = EVP_PKEY_get_base_id(pkey);
    if ((iVar1 != 0x74) || ((param_2 != 0xe && (param_2 != 1)))) {
      iVar1 = EVP_PKEY_get_base_id(pkey);
      if (iVar1 != 0x198) {
        iVar1 = -4;
        puVar4 = (undefined4 *)0x0;
        goto LAB_00118d6f;
      }
      if (param_2 != 0xe) {
        iVar1 = -4;
        puVar4 = (undefined4 *)0x0;
        if (param_2 != 2) goto LAB_00118d6f;
      }
      iVar1 = -2;
      puVar4 = (undefined4 *)FUN_00110ed0(0xe);
      if (puVar4 == (undefined4 *)0x0) goto LAB_00118d6f;
      iVar1 = -4;
      peVar5 = EVP_PKEY_get1_EC_KEY(pkey);
      *puVar4 = 2;
      *(ec_key_st **)(puVar4 + 8) = peVar5;
      iVar2 = FUN_00111f10(peVar5);
      puVar4[6] = iVar2;
      if ((iVar2 == -1) || (lVar6 = FUN_00110400(iVar2), lVar6 == 0)) goto LAB_00118d6f;
      pEVar7 = EC_KEY_get0_public_key(*(EC_KEY **)(puVar4 + 8));
      pEVar8 = EC_KEY_get0_group(*(EC_KEY **)(puVar4 + 8));
      iVar2 = FUN_00114460(pEVar8,pEVar7);
      if (iVar2 != 0) goto LAB_00118d6f;
      iVar2 = FUN_001161f0(*(undefined8 *)(puVar4 + 8));
      goto joined_r0x00118f34;
    }
    iVar1 = -2;
    puVar4 = (undefined4 *)FUN_00110ed0(0xe);
    if (puVar4 == (undefined4 *)0x0) goto LAB_00118d6f;
    pdVar9 = EVP_PKEY_get1_DSA(pkey);
    *puVar4 = 1;
    *(dsa_st **)(puVar4 + 4) = pdVar9;
  }
  iVar1 = 0;
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = puVar4;
    puVar4 = (undefined4 *)0x0;
  }
LAB_00118d6f:
  BIO_free(b);
  EVP_PKEY_free(pkey);
  FUN_00110a60(puVar4);
  return iVar1;
}



// Function: sshkey_dump_ec_point @ 0x19050

void sshkey_dump_ec_point(EC_GROUP *param_1,EC_POINT *param_2)

{
  int iVar1;
  BIGNUM *x;
  BIGNUM *y;
  EC_METHOD *meth;
  
  if (param_2 == (EC_POINT *)0x0) {
    fputs("point=(NULL)\n",stderr);
    return;
  }
  x = BN_new();
  if (x != (BIGNUM *)0x0) {
    y = BN_new();
    if (y != (BIGNUM *)0x0) {
      meth = EC_GROUP_method_of(param_1);
      iVar1 = EC_METHOD_get_field_type(meth);
      if (iVar1 == 0x196) {
        iVar1 = EC_POINT_get_affine_coordinates_GFp(param_1,param_2,x,y,(BN_CTX *)0x0);
        if (iVar1 == 1) {
          fputs("x=",stderr);
          BN_print_fp(stderr,x);
          fputs("\ny=",stderr);
          BN_print_fp(stderr,y);
          fputs("\n",stderr);
        }
        else {
          __fprintf_chk(stderr,1,"%s: EC_POINT_get_affine_coordinates_GFp\n","sshkey_dump_ec_point")
          ;
        }
      }
      else {
        __fprintf_chk(stderr,1,"%s: group is not a prime field\n","sshkey_dump_ec_point");
      }
      goto LAB_001190c0;
    }
  }
  y = (BIGNUM *)0x0;
  __fprintf_chk(stderr,1,"%s: BN_new failed\n","sshkey_dump_ec_point");
LAB_001190c0:
  BN_clear_free(x);
  BN_clear_free(y);
  return;
}



// Function: sshkey_dump_ec_key @ 0x191d0

void sshkey_dump_ec_key(EC_KEY *param_1)

{
  EC_POINT *pEVar1;
  EC_GROUP *pEVar2;
  BIGNUM *pBVar3;
  
  pEVar1 = EC_KEY_get0_public_key(param_1);
  pEVar2 = EC_KEY_get0_group(param_1);
  FUN_00119050(pEVar2,pEVar1);
  fputs("exponent=",stderr);
  pBVar3 = EC_KEY_get0_private_key(param_1);
  if (pBVar3 == (BIGNUM *)0x0) {
    fputs("(NULL)",stderr);
  }
  else {
    pBVar3 = EC_KEY_get0_private_key(param_1);
    BN_print_fp(stderr,pBVar3);
  }
  fputs("\n",stderr);
  return;
}



// Function: sshkey_private_to_fileblob @ 0x19270

undefined8
sshkey_private_to_fileblob(uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,int param_5,
            undefined8 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *param_1;
  if (uVar1 != 3) {
    if ((int)uVar1 < 4) {
      if (2 < uVar1) {
        return 0xfffffff2;
      }
      if (param_5 == 0) goto LAB_00119350;
      if (param_5 - 1U < 2) {
        uVar2 = FUN_00118680();
        return uVar2;
      }
      uVar2 = 0xfffffff6;
    }
    else {
      uVar2 = 0xfffffff2;
      if ((uVar1 - 10 & 0xfffffffd) == 0) goto LAB_00119350;
    }
    return uVar2;
  }
LAB_00119350:
  uVar2 = FUN_00117d10(param_1,param_2,param_3,param_4,param_6,param_7);
  return uVar2;
}



// Function: sshkey_parse_private_fileblob_type @ 0x19400

undefined8
sshkey_parse_private_fileblob_type(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4,
            undefined8 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = 0;
  }
  if ((param_2 != 3) && (param_2 != 8)) {
    iVar1 = FUN_00118a30(param_1,param_2,param_3,param_4);
    if (iVar1 != -4) {
      return 0;
    }
    uVar2 = FUN_00118ce0(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  uVar2 = FUN_00118a30(param_1,param_2,param_3,param_4);
  return uVar2;
}



// Function: sshkey_parse_private_fileblob @ 0x19520

void sshkey_parse_private_fileblob(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4)

{
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  FUN_00119400(param_1,0xe,param_2,param_3);
  return;
}



// Function: sshkey_sig_details_free @ 0x19560

void sshkey_sig_details_free(undefined8 param_1)

{
  FUN_0013b0d0(param_1,8);
  return;
}



// Function: sshkey_parse_pubkey_from_private_fileblob_type @ 0x19570

void sshkey_parse_pubkey_from_private_fileblob_type(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  FUN_00115930();
  return;
}



// Function: sshkey_private_serialize_maxsign @ 0x19590

void sshkey_private_serialize_maxsign(undefined8 param_1,undefined8 param_2)

{
  FUN_00117120(param_1,param_2,0);
  return;
}



// Function: sshkey_signatures_left @ 0x195a0

undefined8 sshkey_signatures_left(void)

{
  return 0;
}



// Function: sshkey_enable_maxsign @ 0x19630

undefined8 sshkey_enable_maxsign(void)

{
  return 0xfffffff6;
}



// Function: sshkey_set_filename @ 0x196c0

uint sshkey_set_filename(long param_1)

{
  return -(uint)(param_1 == 0) & 0xfffffff6;
}



// Function: check_offset @ 0x19750

int check_offset(undefined8 param_1,int param_2,ulong param_3,ulong param_4)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = FUN_0010c520();
  if (lVar2 == 0) {
    iVar1 = -1;
  }
  else if (param_3 < ~param_4) {
    uVar3 = FUN_0010c3d0(param_1);
    iVar1 = 0;
    if (uVar3 < param_4 + param_3) {
      iVar1 = (-(uint)(param_2 == 0) & 6) - 9;
    }
  }
  else {
    iVar1 = -10;
  }
  return iVar1;
}



// Function: sshbuf_get @ 0x19aa0

undefined8 sshbuf_get(undefined8 param_1,void *param_2,size_t param_3)

{
  void *__src;
  undefined8 uVar1;
  
  __src = (void *)FUN_0010c520();
  uVar1 = FUN_0010cc80(param_1,param_3);
  if (-1 < (int)uVar1) {
    if ((param_2 == (void *)0x0) || (param_3 == 0)) {
      return 0;
    }
    memcpy(param_2,__src,param_3);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: sshbuf_get_u64 @ 0x19c10

undefined8 sshbuf_get_u64(undefined8 param_1,ulong *param_2)

{
  ulong uVar1;
  ulong *puVar2;
  undefined8 uVar3;
  
  puVar2 = (ulong *)FUN_0010c520();
  uVar3 = FUN_0010cc80(param_1,8);
  if ((-1 < (int)uVar3) && (uVar3 = 0, param_2 != (ulong *)0x0)) {
    uVar1 = *puVar2;
    *param_2 = uVar1 >> 0x38 | (uVar1 & 0xff000000000000) >> 0x28 | (uVar1 & 0xff0000000000) >> 0x18
               | (uVar1 & 0xff00000000) >> 8 | (uVar1 & 0xff000000) << 8 |
               (uVar1 & 0xff0000) << 0x18 | (uVar1 & 0xff00) << 0x28 | uVar1 << 0x38;
  }
  return uVar3;
}



// Function: sshbuf_get_u32 @ 0x19cd0

undefined8 sshbuf_get_u32(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  
  puVar2 = (uint *)FUN_0010c520();
  uVar3 = FUN_0010cc80(param_1,4);
  if ((-1 < (int)uVar3) && (uVar3 = 0, param_2 != (uint *)0x0)) {
    uVar1 = *puVar2;
    *param_2 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  }
  return uVar3;
}



// Function: sshbuf_get_u16 @ 0x19d90

undefined8 sshbuf_get_u16(undefined8 param_1,ushort *param_2)

{
  ushort *puVar1;
  undefined8 uVar2;
  
  puVar1 = (ushort *)FUN_0010c520();
  uVar2 = FUN_0010cc80(param_1,2);
  if ((-1 < (int)uVar2) && (uVar2 = 0, param_2 != (ushort *)0x0)) {
    *param_2 = *puVar1 << 8 | *puVar1 >> 8;
  }
  return uVar2;
}



// Function: sshbuf_get_u8 @ 0x19e50

undefined8 sshbuf_get_u8(undefined8 param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined1 *)FUN_0010c520();
  uVar2 = FUN_0010cc80(param_1,1);
  if ((-1 < (int)uVar2) && (uVar2 = 0, param_2 != (undefined1 *)0x0)) {
    *param_2 = *puVar1;
  }
  return uVar2;
}



// Function: sshbuf_peek_u64 @ 0x19f10

undefined8 sshbuf_peek_u64(undefined8 param_1,undefined8 param_2,ulong *param_3)

{
  ulong uVar1;
  int iVar2;
  long in_FS_OFFSET;
  ulong *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = (ulong *)0x0;
  if (param_3 == (ulong *)0x0) {
    FUN_001199d0(param_1,param_2,8,&local_18);
  }
  else {
    *param_3 = 0;
    iVar2 = FUN_001199d0(param_1,param_2,8,&local_18);
    if (iVar2 == 0) {
      uVar1 = *local_18;
      *param_3 = uVar1 >> 0x38 | (uVar1 & 0xff000000000000) >> 0x28 |
                 (uVar1 & 0xff0000000000) >> 0x18 | (uVar1 & 0xff00000000) >> 8 |
                 (uVar1 & 0xff000000) << 8 | (uVar1 & 0xff0000) << 0x18 | (uVar1 & 0xff00) << 0x28 |
                 uVar1 << 0x38;
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_peek_u32 @ 0x1a020

undefined8 sshbuf_peek_u32(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  long in_FS_OFFSET;
  uint *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = (uint *)0x0;
  if (param_3 == (uint *)0x0) {
    FUN_001199d0(param_1,param_2,4,&local_18);
  }
  else {
    *param_3 = 0;
    iVar2 = FUN_001199d0(param_1,param_2,4,&local_18);
    if (iVar2 == 0) {
      uVar1 = *local_18;
      *param_3 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_peek_u16 @ 0x1a120

undefined8 sshbuf_peek_u16(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  ushort *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = (ushort *)0x0;
  if (param_3 == (ushort *)0x0) {
    FUN_001199d0(param_1,param_2,2,&local_18);
  }
  else {
    *param_3 = 0;
    iVar1 = FUN_001199d0(param_1,param_2,2,&local_18);
    if (iVar1 == 0) {
      *param_3 = *local_18 << 8 | *local_18 >> 8;
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_peek_u8 @ 0x1a230

undefined8 sshbuf_peek_u8(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined1 *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = (undefined1 *)0x0;
  if (param_3 == (undefined1 *)0x0) {
    FUN_001199d0(param_1,param_2,1,&local_18);
  }
  else {
    *param_3 = 0;
    iVar1 = FUN_001199d0(param_1,param_2,1,&local_18);
    if (iVar1 == 0) {
      *param_3 = *local_18;
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_peek_string_direct @ 0x1a330

undefined8 sshbuf_peek_string_direct(undefined8 param_1,undefined8 *param_2,ulong *param_3)

{
  uint *puVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  
  puVar1 = (uint *)FUN_0010c520();
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (ulong *)0x0) {
    *param_3 = 0;
  }
  uVar2 = FUN_0010c3d0(param_1);
  if (3 < uVar2) {
    uVar4 = *puVar1;
    uVar4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    if (0x7fffffc < uVar4) {
      return 0xfffffffa;
    }
    lVar3 = FUN_0010c3d0(param_1);
    if ((ulong)uVar4 <= lVar3 - 4U) {
      if (param_2 != (undefined8 *)0x0) {
        *param_2 = puVar1 + 1;
      }
      if (param_3 == (ulong *)0x0) {
        return 0;
      }
      *param_3 = (ulong)uVar4;
      return 0;
    }
  }
  return 0xfffffffd;
}



// Function: sshbuf_get_string_direct @ 0x1a460

undefined8 sshbuf_get_string_direct(undefined8 param_1,undefined8 *param_2,long *param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  long local_30;
  undefined8 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (long *)0x0) {
    *param_3 = 0;
  }
  iVar1 = FUN_0011a330(param_1,&local_28,&local_30);
  if (-1 < iVar1) {
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = local_28;
    }
    if (param_3 != (long *)0x0) {
      *param_3 = local_30;
    }
    iVar1 = FUN_0010cc80(param_1,local_30 + 4);
    FUN_0013dae0(iVar1 != 0);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_get_string @ 0x1a590

undefined8 sshbuf_get_string(undefined8 param_1,undefined8 *param_2,size_t *param_3)

{
  size_t __n;
  undefined8 uVar1;
  void *__dest;
  long in_FS_OFFSET;
  void *local_30;
  size_t local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (size_t *)0x0) {
    *param_3 = 0;
  }
  uVar1 = FUN_0011a460(param_1,&local_30,&local_28);
  __n = local_28;
  if (-1 < (int)uVar1) {
    if (param_2 != (undefined8 *)0x0) {
      __dest = malloc(local_28 + 1);
      *param_2 = __dest;
      if (__dest == (void *)0x0) {
        uVar1 = 0xfffffffe;
        goto LAB_0011a61e;
      }
      if (__n != 0) {
        __dest = memcpy(__dest,local_30,__n);
      }
      *(undefined1 *)((long)__dest + __n) = 0;
    }
    uVar1 = 0;
    if (param_3 != (size_t *)0x0) {
      *param_3 = local_28;
    }
  }
LAB_0011a61e:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_get_cstring @ 0x1a6f0

int sshbuf_get_cstring(undefined8 param_1,undefined8 *param_2,size_t *param_3)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  size_t local_40;
  void *local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (size_t *)0x0) {
    *param_3 = 0;
  }
  iVar1 = FUN_0011a330(param_1,&local_38,&local_40);
  pvVar3 = local_38;
  if (iVar1 == 0) {
    if (local_40 != 0) {
      pvVar2 = memchr(local_38,0,local_40);
      if ((pvVar2 != (void *)0x0) && (pvVar2 < (void *)((long)pvVar3 + (local_40 - 1)))) {
        iVar1 = -4;
        goto LAB_0011a7c4;
      }
    }
    iVar1 = FUN_0011a460(param_1,0,0);
    if (iVar1 == 0) {
      if (param_2 != (undefined8 *)0x0) {
        pvVar3 = malloc(local_40 + 1);
        *param_2 = pvVar3;
        if (pvVar3 == (void *)0x0) {
          iVar1 = -2;
          goto LAB_0011a7c4;
        }
        if (local_40 != 0) {
          pvVar3 = memcpy(pvVar3,local_38,local_40);
        }
        *(undefined1 *)((long)pvVar3 + local_40) = 0;
      }
      iVar1 = 0;
      if (param_3 != (size_t *)0x0) {
        *param_3 = local_40;
      }
    }
    else {
      iVar1 = -1;
    }
  }
LAB_0011a7c4:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_get_stringb @ 0x1a8b0

undefined8 sshbuf_get_stringb(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined4 local_2c;
  undefined8 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_0011a330(param_1,0,0);
  if (iVar1 == 0) {
    iVar1 = FUN_00119cd0(param_1,&local_2c);
    if (iVar1 == 0) {
      iVar1 = FUN_0010cb20(param_2,local_2c,&local_28);
      if (iVar1 == 0) {
        FUN_00119aa0(param_1,local_28,local_2c);
      }
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put @ 0x1a9d0

int sshbuf_put(undefined8 param_1,void *param_2,size_t param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  void *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_0010cb20(param_1,param_3,&local_28);
  if ((-1 < iVar1) && (iVar1 = 0, param_3 != 0)) {
    memcpy(local_28,param_2,param_3);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_putb @ 0x1aad0

undefined8 sshbuf_putb(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (param_2 != 0) {
    uVar1 = FUN_0010c3d0(param_2);
    uVar2 = FUN_0010c520(param_2);
    uVar1 = FUN_0011a9d0(param_1,uVar2,uVar1);
    return uVar1;
  }
  return 0;
}



// Function: sshbuf_putfv @ 0x1ab90

int sshbuf_putfv(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  int iVar2;
  long in_FS_OFFSET;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = *param_3;
  uStack_40 = param_3[1];
  local_38 = param_3[2];
  iVar1 = __vsnprintf_chk(0,0,1,0xffffffffffffffff,param_2,&local_48);
  if (iVar1 < 0) {
    iVar2 = -10;
  }
  else {
    iVar2 = 0;
    if (iVar1 != 0) {
      local_48 = *param_3;
      uStack_40 = param_3[1];
      local_38 = param_3[2];
      iVar2 = FUN_0010cb20(param_1,(long)iVar1 + 1,&local_50);
      if (-1 < iVar2) {
        iVar2 = FUN_0013da20(iVar1,1);
        iVar2 = __vsnprintf_chk(local_50,(long)iVar2,1,0xffffffffffffffff,param_2,&local_48);
        if (iVar1 == iVar2) {
          iVar2 = FUN_0010ce00(param_1,1);
        }
        else {
          iVar2 = -1;
        }
      }
    }
  }
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



// Function: sshbuf_putf @ 0x1ad40

undefined8
sshbuf_putf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
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
  FUN_0011ab90(param_9,param_10,&local_d8);
  if (local_c0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_u64 @ 0x1ae80

undefined8 sshbuf_put_u64(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  undefined1 *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = FUN_0010cb20(param_1,8,&local_18);
  if (-1 < (int)uVar1) {
    *local_18 = (char)((ulong)param_2 >> 0x38);
    local_18[1] = (char)((ulong)param_2 >> 0x30);
    local_18[2] = (char)((ulong)param_2 >> 0x28);
    local_18[3] = (char)((ulong)param_2 >> 0x20);
    local_18[4] = (char)((ulong)param_2 >> 0x18);
    local_18[5] = (char)((ulong)param_2 >> 0x10);
    local_18[6] = (char)((ulong)param_2 >> 8);
    local_18[7] = (char)param_2;
    uVar1 = 0;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_u32 @ 0x1afb0

undefined8 sshbuf_put_u32(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  undefined1 *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = FUN_0010cb20(param_1,4,&local_18);
  if (-1 < (int)uVar1) {
    *local_18 = (char)((uint)param_2 >> 0x18);
    local_18[1] = (char)((uint)param_2 >> 0x10);
    local_18[2] = (char)((uint)param_2 >> 8);
    local_18[3] = (char)param_2;
    uVar1 = 0;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_u16 @ 0x1b0a0

undefined8 sshbuf_put_u16(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  undefined1 *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = FUN_0010cb20(param_1,2,&local_18);
  if (-1 < (int)uVar1) {
    *local_18 = (char)((uint)param_2 >> 8);
    local_18[1] = (char)param_2;
    uVar1 = 0;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_u8 @ 0x1b180

undefined8 sshbuf_put_u8(undefined8 param_1,undefined1 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  undefined1 *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = FUN_0010cb20(param_1,1,&local_18);
  if (-1 < (int)uVar1) {
    *local_18 = param_2;
    uVar1 = 0;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_poke_u64 @ 0x1b250

undefined8 sshbuf_poke_u64(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  ulong *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = (ulong *)0x0;
  iVar1 = FUN_00119850(param_1,param_2,8,&local_18);
  if (iVar1 == 0) {
    *local_18 = param_3 >> 0x38 | (param_3 & 0xff000000000000) >> 0x28 |
                (param_3 & 0xff0000000000) >> 0x18 | (param_3 & 0xff00000000) >> 8 |
                (param_3 & 0xff000000) << 8 | (param_3 & 0xff0000) << 0x18 |
                (param_3 & 0xff00) << 0x28 | param_3 << 0x38;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_poke_u32 @ 0x1b330

undefined8 sshbuf_poke_u32(undefined8 param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  uint *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = (uint *)0x0;
  iVar1 = FUN_00119850(param_1,param_2,4,&local_18);
  if (iVar1 == 0) {
    *local_18 = param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 |
                param_3 << 0x18;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_poke_u16 @ 0x1b410

undefined8 sshbuf_poke_u16(undefined8 param_1,undefined8 param_2,ushort param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  ushort *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = (ushort *)0x0;
  iVar1 = FUN_00119850(param_1,param_2,2,&local_18);
  if (iVar1 == 0) {
    *local_18 = param_3 << 8 | param_3 >> 8;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_poke_u8 @ 0x1b4f0

undefined8 sshbuf_poke_u8(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined1 *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = (undefined1 *)0x0;
  iVar1 = FUN_00119850(param_1,param_2,1,&local_18);
  if (iVar1 == 0) {
    *local_18 = param_3;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_poke @ 0x1b5d0

int sshbuf_poke(undefined8 param_1,undefined8 param_2,void *param_3,size_t param_4)

{
  int iVar1;
  long in_FS_OFFSET;
  void *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = (void *)0x0;
  iVar1 = FUN_00119850(param_1,param_2,param_4,&local_28);
  if (iVar1 == 0) {
    memcpy(local_28,param_3,param_4);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_string @ 0x1b6c0

int sshbuf_put_string(undefined8 param_1,void *param_2,ulong param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined1 *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 < 0x7fffffd) {
    iVar1 = FUN_0010cb20(param_1,param_3 + 4,&local_28);
    if (-1 < iVar1) {
      iVar1 = 0;
      *local_28 = (char)(param_3 >> 0x18);
      local_28[1] = (char)(param_3 >> 0x10);
      local_28[2] = (char)(param_3 >> 8);
      local_28[3] = (char)param_3;
      if (param_3 != 0) {
        memcpy(local_28 + 4,param_2,param_3);
      }
    }
  }
  else {
    iVar1 = -9;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_cstring @ 0x1b800

void sshbuf_put_cstring(undefined8 param_1,char *param_2)

{
  size_t sVar1;
  
  sVar1 = 0;
  if (param_2 != (char *)0x0) {
    sVar1 = strlen(param_2);
  }
  FUN_0011b6c0(param_1,param_2,sVar1);
  return;
}



// Function: sshbuf_put_stringb @ 0x1b840

void sshbuf_put_stringb(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (param_2 != 0) {
    uVar1 = FUN_0010c3d0(param_2);
    uVar2 = FUN_0010c520(param_2);
    FUN_0011b6c0(param_1,uVar2,uVar1);
    return;
  }
  FUN_0011b6c0(param_1,0,0);
  return;
}



// Function: sshbuf_froms @ 0x1b8a0

ulong sshbuf_froms(long param_1,long *param_2)

{
  ulong uVar1;
  long lVar2;
  long in_FS_OFFSET;
  undefined8 local_40;
  long local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 == 0) || (param_2 == (long *)0x0)) {
    uVar1 = 0xfffffff6;
  }
  else {
    *param_2 = 0;
    uVar1 = FUN_0011a330(param_1,&local_40,&local_38);
    if ((int)uVar1 == 0) {
      lVar2 = FUN_0010b980(local_40,local_38);
      if (lVar2 == 0) {
        uVar1 = 0xfffffffe;
      }
      else {
        uVar1 = FUN_0010cc80(param_1,local_38 + 4);
        if ((int)uVar1 == 0) {
          uVar1 = FUN_0010bb80(lVar2,param_1);
          if ((int)uVar1 == 0) {
            *param_2 = lVar2;
            goto LAB_0011b8f4;
          }
        }
        FUN_0010bce0(lVar2);
        uVar1 = uVar1 & 0xffffffff;
      }
    }
  }
LAB_0011b8f4:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_bignum2_bytes @ 0x1ba10

int sshbuf_put_bignum2_bytes(undefined8 param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  long in_FS_OFFSET;
  undefined1 *local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 < 0x7fffffc) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      if (*param_2 != 0) {
        bVar1 = *param_2 >> 7;
        uVar3 = (ulong)bVar1;
        uVar4 = (uint)bVar1;
        iVar2 = FUN_0010cb20(param_1,uVar3 + 4 + param_3,&local_38);
        goto joined_r0x0011ba81;
      }
      param_2 = param_2 + 1;
    }
    uVar3 = 0;
    uVar4 = 0;
    iVar2 = FUN_0010cb20(param_1,4,&local_38);
joined_r0x0011ba81:
    if (-1 < iVar2) {
      iVar2 = uVar4 + (int)param_3;
      *local_38 = (char)((uint)iVar2 >> 0x18);
      local_38[1] = (char)((uint)iVar2 >> 0x10);
      local_38[2] = (char)((uint)iVar2 >> 8);
      local_38[3] = (char)iVar2;
      if (uVar4 != 0) {
        local_38[4] = 0;
      }
      iVar2 = 0;
      if (param_3 != 0) {
        memcpy(local_38 + uVar3 + 4,param_2,param_3);
      }
    }
  }
  else {
    iVar2 = -9;
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_get_bignum2_bytes_direct @ 0x1bbc0

undefined8 sshbuf_get_bignum2_bytes_direct(undefined8 param_1,undefined8 *param_2,ulong *param_3)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  char cVar5;
  char *pcVar6;
  long in_FS_OFFSET;
  char *local_30;
  ulong local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar3 = FUN_0011a330(param_1,&local_30,&local_28);
  if ((int)uVar3 < 0) goto LAB_0011bc37;
  if (local_28 == 0) {
    uVar4 = 0;
  }
  else {
    cVar5 = *local_30;
    if (cVar5 < '\0') {
      uVar3 = 0xfffffffb;
      goto LAB_0011bc37;
    }
    if (0x801 < local_28) {
LAB_0011bd29:
      uVar3 = 0xfffffff9;
      goto LAB_0011bc37;
    }
    uVar4 = local_28;
    if (local_28 == 0x801) {
      if (cVar5 != '\0') goto LAB_0011bd29;
      uVar4 = 0x801;
    }
    bVar1 = false;
    pcVar6 = local_30;
    while (cVar5 == '\0') {
      pcVar6 = pcVar6 + 1;
      uVar4 = uVar4 - 1;
      if (uVar4 == 0) goto LAB_0011bd1f;
      bVar1 = true;
      cVar5 = *pcVar6;
    }
    if (bVar1) {
LAB_0011bd1f:
      local_30 = pcVar6;
    }
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = local_30;
  }
  if (param_3 != (ulong *)0x0) {
    *param_3 = uVar4;
  }
  iVar2 = FUN_0010cc80(param_1,local_28 + 4);
  uVar3 = FUN_0013dae0(iVar2 != 0);
LAB_0011bc37:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_dump_data @ 0x1bd50

undefined8 sshbuf_dump_data(long param_1,ulong param_2,undefined8 param_3)

{
  byte bVar1;
  ushort **ppuVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  
  if (param_2 != 0) {
    uVar5 = 0;
    do {
      uVar6 = uVar5 + 0x10;
      __fprintf_chk(param_3,1,&DAT_0013f930,uVar5);
      uVar4 = uVar5;
      if (uVar5 < uVar6) {
        do {
          while (uVar4 < param_2) {
            uVar3 = uVar4 + 1;
            __fprintf_chk(param_3,1,"%02x ",*(undefined1 *)(param_1 + uVar4));
            uVar4 = uVar3;
            if (uVar3 == uVar6) goto LAB_0011bdfc;
          }
          __fprintf_chk(param_3,1,&DAT_0013f93e);
          uVar4 = uVar4 + 1;
        } while (uVar4 != uVar6);
LAB_0011bdfc:
        __fprintf_chk(param_3,1,&DAT_0013f940);
        do {
          while (param_2 <= uVar5) {
LAB_0011be36:
            uVar5 = uVar5 + 1;
            if (uVar5 == uVar6) goto LAB_0011be90;
          }
          bVar1 = *(byte *)(param_1 + uVar5);
          if (((bVar1 & 0x80) != 0) ||
             (ppuVar2 = __ctype_b_loc(),
             (*(byte *)((long)*ppuVar2 + (ulong)bVar1 * 2 + 1) & 0x40) == 0)) {
            __fprintf_chk(param_3,1,&DAT_0013f942);
            goto LAB_0011be36;
          }
          uVar5 = uVar5 + 1;
          __fprintf_chk(param_3,1,"%c",bVar1);
        } while (uVar5 != uVar6);
      }
      else {
        __fprintf_chk(param_3,1,&DAT_0013f940);
      }
LAB_0011be90:
      __fprintf_chk(param_3,1,&DAT_0013fef0);
      uVar5 = uVar6;
    } while (uVar6 < param_2);
  }
  return 0;
}



// Function: sshbuf_dump @ 0x1bf60

void sshbuf_dump(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_0010c3d0();
  __fprintf_chk(param_2,1,"buffer len = %zu\n",uVar1);
  uVar1 = FUN_0010c3d0(param_1);
  uVar2 = FUN_0010c520(param_1);
  FUN_0011bd50(uVar2,uVar1,param_2);
  return;
}



// Function: sshbuf_dtob16 @ 0x1bfc0

char * sshbuf_dtob16(undefined8 param_1)

{
  ulong uVar1;
  long lVar2;
  char *pcVar3;
  ulong uVar4;
  long in_FS_OFFSET;
  char local_38 [8];
  char acStack_30 [8];
  undefined1 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar1 = FUN_0010c3d0();
  lVar2 = FUN_0010c520(param_1);
  local_28 = 0;
  local_38[0] = s_0123456789abcdefzlib_openssh_com_0013f960[0];
  local_38[1] = s_0123456789abcdefzlib_openssh_com_0013f960[1];
  local_38[2] = s_0123456789abcdefzlib_openssh_com_0013f960[2];
  local_38[3] = s_0123456789abcdefzlib_openssh_com_0013f960[3];
  local_38[4] = s_0123456789abcdefzlib_openssh_com_0013f960[4];
  local_38[5] = s_0123456789abcdefzlib_openssh_com_0013f960[5];
  local_38[6] = s_0123456789abcdefzlib_openssh_com_0013f960[6];
  local_38[7] = s_0123456789abcdefzlib_openssh_com_0013f960[7];
  acStack_30[0] = s_0123456789abcdefzlib_openssh_com_0013f960[8];
  acStack_30[1] = s_0123456789abcdefzlib_openssh_com_0013f960[9];
  acStack_30[2] = s_0123456789abcdefzlib_openssh_com_0013f960[10];
  acStack_30[3] = s_0123456789abcdefzlib_openssh_com_0013f960[0xb];
  acStack_30[4] = s_0123456789abcdefzlib_openssh_com_0013f960[0xc];
  acStack_30[5] = s_0123456789abcdefzlib_openssh_com_0013f960[0xd];
  acStack_30[6] = s_0123456789abcdefzlib_openssh_com_0013f960[0xe];
  acStack_30[7] = s_0123456789abcdefzlib_openssh_com_0013f960[0xf];
  if (uVar1 == 0) {
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      pcVar3 = strdup("");
      return pcVar3;
    }
    goto LAB_0011c134;
  }
  if (uVar1 < 0x7fffffffffffffff) {
    pcVar3 = malloc(uVar1 * 2 + 1);
    if (pcVar3 == (char *)0x0) goto LAB_0011c100;
    uVar4 = 0;
    do {
      pcVar3[uVar4 * 2] = local_38[*(byte *)(lVar2 + uVar4) >> 4];
      pcVar3[uVar4 * 2 + 1] = local_38[*(byte *)(lVar2 + uVar4) & 0xf];
      uVar4 = uVar4 + 1;
    } while (uVar1 != uVar4);
    pcVar3[uVar1 * 2] = '\0';
  }
  else {
LAB_0011c100:
    pcVar3 = (char *)0x0;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar3;
  }
LAB_0011c134:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_dtob64 @ 0x1c140

int sshbuf_dtob64(long param_1,long param_2,int param_3)

{
  size_t __size;
  int iVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  char *__s;
  undefined8 uVar5;
  undefined8 uVar6;
  size_t sVar7;
  ulong uVar8;
  
  if (((param_1 == 0) || (param_2 == 0)) || (uVar3 = FUN_0010c3d0(), 0x7ffffffffffffffe < uVar3)) {
    return -10;
  }
  lVar4 = FUN_0010c3d0(param_1);
  if (lVar4 == 0) {
    return 0;
  }
  lVar4 = FUN_0010c3d0(param_1);
  __size = ((lVar4 + 2U) / 3) * 4 + 1;
  __s = malloc(__size);
  if (__s == (char *)0x0) {
    return -2;
  }
  uVar5 = FUN_0010c3d0(param_1);
  uVar6 = FUN_0010c520(param_1);
  iVar1 = FUN_00138b30(uVar6,uVar5,__s,__size);
  if (iVar1 != -1) {
    if (param_3 == 0) {
      sVar7 = strlen(__s);
      iVar1 = FUN_0011a9d0(param_2,__s,sVar7);
      FUN_0013b0d0(__s,__size);
      return iVar1;
    }
    uVar3 = 0;
    if (*__s != '\0') {
      do {
        iVar2 = FUN_0011b180(param_2);
        iVar1 = iVar2;
        if ((iVar2 != 0) ||
           ((uVar8 = uVar3 % 0x46, uVar8 == 0x45 && (iVar1 = FUN_0011b180(param_2,10), iVar1 != 0)))
           ) goto LAB_0011c310;
        uVar3 = uVar3 + 1;
      } while (__s[uVar3] != '\0');
      iVar1 = iVar2;
      if (uVar8 == 0x45) goto LAB_0011c310;
    }
    iVar1 = FUN_0011b180(param_2,10);
  }
LAB_0011c310:
  FUN_0013b0d0(__s,__size);
  return iVar1;
}



// Function: sshbuf_b64tod @ 0x1c390

int sshbuf_b64tod(undefined8 param_1,char *param_2)

{
  int iVar1;
  size_t __size;
  void *pvVar2;
  
  __size = strlen(param_2);
  iVar1 = 0;
  if (__size != 0) {
    pvVar2 = malloc(__size);
    if (pvVar2 == (void *)0x0) {
      iVar1 = -2;
    }
    else {
      iVar1 = FUN_00138de0(param_2,pvVar2,__size);
      if (-1 < iVar1) {
        iVar1 = FUN_0011a9d0(param_1,pvVar2,(long)iVar1);
        if (-1 < iVar1) {
          FUN_0013b0d0(pvVar2,__size);
          return 0;
        }
        FUN_0013b0d0(pvVar2,__size);
        return iVar1;
      }
      FUN_0013b0d0(pvVar2,__size);
      iVar1 = -4;
    }
  }
  return iVar1;
}



// Function: sshbuf_dtourlb64 @ 0x1c5e0

int sshbuf_dtourlb64(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  
  lVar3 = FUN_0010b880();
  if (lVar3 == 0) {
    iVar2 = -2;
  }
  else {
    iVar2 = FUN_0011c140(param_1,lVar3,param_3);
    if (iVar2 == 0) {
LAB_0011c651:
      uVar5 = FUN_0010c3d0(lVar3);
      if ((uVar5 < 2) || (lVar4 = FUN_0010c520(lVar3), lVar4 == 0)) {
LAB_0011c662:
        iVar2 = -1;
      }
      else {
        lVar4 = FUN_0010c520(lVar3);
        if (*(char *)((uVar5 - 1) + lVar4) == '=') goto code_r0x0011c640;
        lVar4 = FUN_0010c3d0(lVar3);
        pcVar6 = (char *)FUN_0010c7c0(lVar3);
        if (pcVar6 == (char *)0x0) goto LAB_0011c662;
        if (lVar4 != 0) {
          pcVar1 = pcVar6 + lVar4;
          do {
            if (*pcVar6 == '+') {
              *pcVar6 = '-';
            }
            else if (*pcVar6 == '/') {
              *pcVar6 = '_';
            }
            pcVar6 = pcVar6 + 1;
          } while (pcVar6 != pcVar1);
        }
        iVar2 = FUN_0011aad0(param_2,lVar3);
      }
    }
LAB_0011c667:
    FUN_0010bce0(lVar3);
  }
  return iVar2;
code_r0x0011c640:
  iVar2 = FUN_0010ce00(lVar3,1);
  if (iVar2 != 0) goto LAB_0011c667;
  goto LAB_0011c651;
}



// Function: sshbuf_dup_string @ 0x1c770

undefined1 * sshbuf_dup_string(undefined8 param_1)

{
  size_t sVar1;
  void *__s;
  size_t __n;
  void *pvVar2;
  undefined1 *__dest;
  undefined1 *puVar3;
  
  __s = (void *)FUN_0010c520();
  __n = FUN_0010c3d0(param_1);
  if (__s == (void *)0x0) {
    return (undefined1 *)0x0;
  }
  if (__n == 0) {
    __dest = malloc(1);
    puVar3 = __dest;
    if (__dest == (undefined1 *)0x0) {
      return (undefined1 *)0x0;
    }
  }
  else {
    pvVar2 = memchr(__s,0,__n);
    if (pvVar2 == (void *)0x0) {
      __dest = malloc(__n + 1);
      if (__dest == (undefined1 *)0x0) {
        return (undefined1 *)0x0;
      }
    }
    else {
      sVar1 = __n - 1;
      if (pvVar2 != (void *)((long)__s + sVar1)) {
        return (undefined1 *)0x0;
      }
      __dest = malloc(__n);
      if (__dest == (undefined1 *)0x0) {
        return (undefined1 *)0x0;
      }
      __n = sVar1;
      puVar3 = __dest;
      if (sVar1 == 0) goto LAB_0011c7f8;
    }
    puVar3 = memcpy(__dest,__s,__n);
    __dest = puVar3 + __n;
  }
LAB_0011c7f8:
  *__dest = 0;
  return puVar3;
}



// Function: sshbuf_dtob64_string @ 0x1c950

undefined8 sshbuf_dtob64_string(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = FUN_0010b880();
  if (lVar2 == 0) {
    return 0;
  }
  iVar1 = FUN_0011c140(param_1,lVar2,param_2);
  if (iVar1 == 0) {
    uVar3 = FUN_0011c770();
    FUN_0010bce0(lVar2);
    return uVar3;
  }
  FUN_0010bce0(lVar2);
  return 0;
}



// Function: sshbuf_cmp @ 0x1cb40

undefined8 sshbuf_cmp(undefined8 param_1,ulong param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  lVar1 = FUN_0010c520();
  if (lVar1 == 0) {
    uVar3 = 0xffffffff;
  }
  else if ((param_4 - 1U < 0x8000000) && (param_2 < 0x8000001)) {
    uVar2 = FUN_0010c3d0(param_1);
    if (uVar2 < param_2 + param_4) {
      uVar3 = 0xfffffffd;
    }
    else {
      lVar1 = FUN_0010c520(param_1);
      uVar3 = FUN_0013c1c0(lVar1 + param_2,param_3,param_4);
      if ((int)uVar3 != 0) {
        uVar3 = 0xfffffffc;
      }
    }
  }
  else {
    uVar3 = 0xfffffff6;
  }
  return uVar3;
}



// Function: sshbuf_find @ 0x1cc70

undefined8
sshbuf_find(undefined8 param_1,ulong param_2,void *param_3,size_t param_4,undefined8 *param_5)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  void *pvVar4;
  undefined8 uVar5;
  
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = 0;
  }
  lVar1 = FUN_0010c520(param_1);
  if (lVar1 == 0) {
    uVar5 = 0xffffffff;
  }
  else if ((param_4 - 1 < 0x8000000) && (param_2 < 0x8000001)) {
    uVar2 = FUN_0010c3d0(param_1);
    if ((param_2 <= uVar2) && (uVar2 = FUN_0010c3d0(param_1), param_2 + param_4 <= uVar2)) {
      lVar1 = FUN_0010c3d0(param_1);
      lVar3 = FUN_0010c520(param_1);
      pvVar4 = memmem((void *)(lVar3 + param_2),lVar1 - param_2,param_3,param_4);
      if (pvVar4 == (void *)0x0) {
        return 0xfffffffc;
      }
      if (param_5 == (undefined8 *)0x0) {
        return 0;
      }
      uVar5 = FUN_0010c520(param_1);
      uVar5 = FUN_0013da40(pvVar4,uVar5);
      *param_5 = uVar5;
      return 0;
    }
    uVar5 = 0xfffffffd;
  }
  else {
    uVar5 = 0xfffffff6;
  }
  return uVar5;
}



// Function: sshbuf_read @ 0x1ce10

int sshbuf_read(int param_1,undefined8 param_2,size_t param_3,ssize_t *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ssize_t sVar4;
  int *piVar5;
  long lVar6;
  long in_FS_OFFSET;
  void *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_4 != (ssize_t *)0x0) {
    *param_4 = 0;
  }
  iVar2 = FUN_0010cb20(param_2,param_3,&local_48);
  if (iVar2 == 0) {
    sVar4 = read(param_1,local_48,param_3);
    piVar5 = __errno_location();
    lVar6 = 0;
    if (-1 < sVar4) {
      lVar6 = sVar4;
    }
    iVar1 = *piVar5;
    if (param_3 - lVar6 != 0) {
      iVar3 = FUN_0010ce00(param_2);
      if (iVar3 != 0) {
        iVar2 = -1;
        memset((void *)((long)local_48 + sVar4),0,param_3 - lVar6);
        goto LAB_0011cea8;
      }
    }
    if (sVar4 < 0) {
      *piVar5 = iVar1;
      iVar2 = -0x18;
    }
    else if (sVar4 == 0) {
      *piVar5 = 0x20;
      iVar2 = -0x18;
    }
    else if (param_4 != (ssize_t *)0x0) {
      *param_4 = sVar4;
    }
  }
LAB_0011cea8:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: get_ec @ 0x1cfb0

undefined8 get_ec(uchar *param_1,size_t param_2,EC_POINT *param_3,EC_GROUP *param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  if (0x84 < param_2 - 1) {
    return 0xfffffff8;
  }
  if (*param_1 == '\x04') {
    if (param_3 != (EC_POINT *)0x0) {
      iVar1 = EC_POINT_oct2point(param_4,param_3,param_1,param_2,(BN_CTX *)0x0);
      if (iVar1 == 1) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0xfffffffc;
      }
      return uVar2;
    }
    return 0;
  }
  return 0xfffffffc;
}



// Function: sshbuf_get_bignum2 @ 0x1d220

int sshbuf_get_bignum2(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  BIGNUM *ret;
  BIGNUM *pBVar2;
  long in_FS_OFFSET;
  uchar *local_30;
  int local_28 [2];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == (undefined8 *)0x0) {
    iVar1 = FUN_0011bbc0(param_1,&local_30,local_28);
  }
  else {
    *param_2 = 0;
    iVar1 = FUN_0011bbc0(param_1,&local_30,local_28);
    if (iVar1 == 0) {
      ret = BN_new();
      if (ret != (BIGNUM *)0x0) {
        pBVar2 = BN_bin2bn(local_30,local_28[0],ret);
        if (pBVar2 != (BIGNUM *)0x0) {
          *param_2 = ret;
          goto LAB_0011d293;
        }
      }
      iVar1 = -2;
      BN_clear_free(ret);
    }
  }
LAB_0011d293:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_get_ec @ 0x1d360

undefined8 sshbuf_get_ec(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined8 local_30;
  undefined8 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_0011a330(param_1,&local_30,&local_28);
  if (-1 < iVar1) {
    iVar1 = FUN_0011cfb0(local_30,local_28,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_0011a460(param_1,0,0);
      FUN_0013dae0(iVar1 != 0);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_get_eckey @ 0x1d480

int sshbuf_get_eckey(undefined8 param_1,EC_KEY *param_2)

{
  int iVar1;
  EC_GROUP *pEVar2;
  EC_POINT *point;
  long in_FS_OFFSET;
  undefined8 local_40;
  undefined8 local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  pEVar2 = EC_KEY_get0_group(param_2);
  point = EC_POINT_new(pEVar2);
  if (point == (EC_POINT *)0x0) {
    iVar1 = -2;
  }
  else {
    iVar1 = FUN_0011a330(param_1,&local_40,&local_38);
    if (-1 < iVar1) {
      pEVar2 = EC_KEY_get0_group(param_2);
      iVar1 = FUN_0011cfb0(local_40,local_38,point,pEVar2);
      if (iVar1 == 0) {
        iVar1 = EC_KEY_set_public_key(param_2,point);
        if (iVar1 == 1) {
          EC_POINT_free(point);
          iVar1 = FUN_0011a460(param_1,0,0);
          iVar1 = FUN_0013dae0(iVar1 != 0);
        }
        else {
          EC_POINT_free(point);
          iVar1 = -2;
        }
        goto LAB_0011d548;
      }
    }
    EC_POINT_free(point);
  }
LAB_0011d548:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_bignum2 @ 0x1d610

int sshbuf_put_bignum2(undefined8 param_1,BIGNUM *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long in_FS_OFFSET;
  byte local_838 [2056];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = BN_num_bits(param_2);
  uVar2 = FUN_0013da20(iVar1,7);
  uVar3 = uVar2 + 7;
  if (-1 < (int)uVar2) {
    uVar3 = uVar2;
  }
  iVar1 = (int)uVar3 >> 3;
  if (uVar3 < 0x4008) {
    local_838[0] = 0;
    iVar4 = BN_bn2bin(param_2,local_838 + 1);
    if (iVar4 == iVar1) {
      lVar5 = 1;
      if (7 < (int)uVar2) {
        iVar1 = FUN_0013da20(iVar1,local_838[1] >> 7);
        lVar5 = 1 - (ulong)(local_838[1] >> 7);
      }
      iVar1 = FUN_0011b6c0(param_1,local_838 + lVar5,(long)iVar1);
      if (iVar1 < 0) {
        __explicit_bzero_chk(local_838,0x801,0x801);
      }
      else {
        __explicit_bzero_chk(local_838,0x801,0x801);
        iVar1 = 0;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = -10;
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_ec @ 0x1d7d0

undefined4 sshbuf_put_ec(undefined8 param_1,EC_POINT *param_2,EC_GROUP *param_3)

{
  undefined4 uVar1;
  size_t len;
  size_t sVar2;
  long in_FS_OFFSET;
  uchar auStack_b8 [136];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  len = EC_POINT_point2oct(param_3,param_2,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                           (BN_CTX *)0x0);
  if (len < 0x86) {
    sVar2 = EC_POINT_point2oct(param_3,param_2,POINT_CONVERSION_UNCOMPRESSED,auStack_b8,len,
                               (BN_CTX *)0x0);
    if (sVar2 == len) {
      uVar1 = FUN_0011b6c0(param_1,auStack_b8,sVar2);
      __explicit_bzero_chk(auStack_b8,sVar2,0x85);
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0xfffffff6;
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshbuf_put_eckey @ 0x1d940

void sshbuf_put_eckey(undefined8 param_1,EC_KEY *param_2)

{
  EC_GROUP *pEVar1;
  EC_POINT *pEVar2;
  
  pEVar1 = EC_KEY_get0_group(param_2);
  pEVar2 = EC_KEY_get0_public_key(param_2);
  FUN_0011d7d0(param_1,pEVar2,pEVar1);
  return;
}



// Function: cipher_alg_list @ 0x1d980

void * cipher_alg_list(undefined1 param_1,int param_2)

{
  uint uVar1;
  size_t sVar2;
  void *pvVar3;
  undefined **ppuVar4;
  long lVar5;
  void *__ptr;
  long lVar6;
  
  uVar1 = 0;
  lVar6 = 0;
  ppuVar4 = &PTR_s_3des_cbc_00167380;
  __ptr = (void *)0x0;
  do {
    pvVar3 = __ptr;
    if (((uVar1 & 8) == 0) && ((param_2 == 0 || (*(int *)((long)ppuVar4 + 0x14) != 0)))) {
      lVar5 = lVar6;
      if (__ptr != (void *)0x0) {
        lVar5 = lVar6 + 1;
        *(undefined1 *)((long)__ptr + lVar6) = param_1;
      }
      sVar2 = strlen(*ppuVar4);
      lVar6 = lVar5 + sVar2;
      pvVar3 = realloc(__ptr,lVar6 + 2);
      if (pvVar3 == (void *)0x0) {
        free(__ptr);
        return (void *)0x0;
      }
      memcpy((void *)((long)pvVar3 + lVar5),*ppuVar4,sVar2 + 1);
    }
    if (ppuVar4[5] == (undefined *)0x0) {
      return pvVar3;
    }
    uVar1 = *(uint *)(ppuVar4 + 8);
    ppuVar4 = ppuVar4 + 5;
    __ptr = pvVar3;
  } while( true );
}



// Function: compression_alg_list @ 0x1dac0

char * compression_alg_list(int param_1)

{
  char *pcVar1;
  
  pcVar1 = "zlib@openssh.com,zlib,none";
  if (param_1 == 0) {
    pcVar1 = "none,zlib@openssh.com,zlib";
  }
  return pcVar1;
}



// Function: cipher_blocksize @ 0x1db60

undefined4 cipher_blocksize(long param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: cipher_keylen @ 0x1dbf0

undefined4 cipher_keylen(long param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



// Function: cipher_seclen @ 0x1dc80

undefined8 cipher_seclen(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = strcmp("3des-cbc",(char *)*param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_0011dbf0(param_1);
    return uVar2;
  }
  return 0xe;
}



// Function: cipher_authlen @ 0x1dd30

undefined4 cipher_authlen(long param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



// Function: cipher_ivlen @ 0x1ddc0

int cipher_ivlen(long param_1)

{
  if ((*(int *)(param_1 + 0x10) == 0) && ((*(byte *)(param_1 + 0x18) & 2) == 0)) {
    return *(int *)(param_1 + 8);
  }
  return *(int *)(param_1 + 0x10);
}



// Function: cipher_is_cbc @ 0x1ded0

uint cipher_is_cbc(long param_1)

{
  return *(uint *)(param_1 + 0x18) & 1;
}



// Function: cipher_ctx_is_plaintext @ 0x1df60

undefined4 cipher_ctx_is_plaintext(undefined4 *param_1)

{
  return *param_1;
}



// Function: cipher_by_name @ 0x1dff0

undefined ** cipher_by_name(char *param_1)

{
  int iVar1;
  char *__s1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_s_3des_cbc_00167380;
  __s1 = "3des-cbc";
  do {
    iVar1 = strcmp(__s1,param_1);
    if (iVar1 == 0) {
      return ppuVar2;
    }
    __s1 = ppuVar2[5];
    ppuVar2 = ppuVar2 + 5;
  } while (__s1 != (char *)0x0);
  return (undefined **)0x0;
}



// Function: ciphers_valid @ 0x1e150

undefined8 ciphers_valid(char *param_1)

{
  int iVar1;
  char *__ptr;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  long in_FS_OFFSET;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (((param_1 != (char *)0x0) && (iVar1 = strcmp(param_1,""), iVar1 != 0)) &&
     (__ptr = strdup(param_1), local_28 = __ptr, __ptr != (char *)0x0)) {
    do {
      pcVar3 = strsep(&local_28,",");
      if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
        free(__ptr);
        uVar4 = 1;
        goto LAB_0011e18a;
      }
      lVar2 = FUN_0011dff0(pcVar3);
    } while ((lVar2 != 0) && ((*(byte *)(lVar2 + 0x18) & 8) == 0));
    free(__ptr);
  }
  uVar4 = 0;
LAB_0011e18a:
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



// Function: cipher_warning_message @ 0x1e2b0

undefined8 cipher_warning_message(void)

{
  return 0;
}



// Function: cipher_init @ 0x1e340

undefined8
cipher_init(undefined8 *param_1,long param_2,uchar *param_3,uint param_4,uchar *param_5,
            uint param_6,uint param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  EVP_CIPHER *cipher;
  EVP_CIPHER_CTX *pEVar5;
  long lVar6;
  uint uVar7;
  undefined8 uVar8;
  
  *param_1 = 0;
  puVar4 = calloc(0x128,1);
  if (puVar4 == (uint *)0x0) {
    return 0xfffffffe;
  }
  uVar3 = *(uint *)(param_2 + 0x18);
  uVar7 = uVar3 & 8;
  *puVar4 = (uint)(uVar7 != 0);
  puVar4[1] = param_7;
  if ((param_4 < *(uint *)(param_2 + 0xc)) ||
     ((param_5 != (uchar *)0x0 && (uVar1 = FUN_0011ddc0(param_2), param_6 < uVar1)))) {
LAB_0011e4b8:
    pEVar5 = *(EVP_CIPHER_CTX **)(puVar4 + 2);
    uVar8 = 0xfffffff6;
LAB_0011e4c2:
    EVP_CIPHER_CTX_free(pEVar5);
    FUN_0013b0d0(puVar4,0x128);
  }
  else {
    *(long *)(puVar4 + 0x48) = param_2;
    if ((uVar3 & 2) == 0) {
      if (uVar7 == 0) {
        cipher = (EVP_CIPHER *)(**(code **)(param_2 + 0x20))();
        pEVar5 = EVP_CIPHER_CTX_new();
        *(EVP_CIPHER_CTX **)(puVar4 + 2) = pEVar5;
        if (pEVar5 == (EVP_CIPHER_CTX *)0x0) {
          uVar8 = 0xfffffffe;
          pEVar5 = (EVP_CIPHER_CTX *)0x0;
        }
        else {
          iVar2 = EVP_CipherInit(pEVar5,cipher,(uchar *)0x0,param_5,(uint)(param_7 == 1));
          if ((((iVar2 != 0) &&
               ((iVar2 = FUN_0011dd30(param_2), iVar2 == 0 ||
                (iVar2 = EVP_CIPHER_CTX_ctrl(*(EVP_CIPHER_CTX **)(puVar4 + 2),0x12,-1,param_5),
                iVar2 != 0)))) &&
              ((uVar3 = EVP_CIPHER_CTX_get_key_length(*(undefined8 *)(puVar4 + 2)), (int)uVar3 < 1
               || ((uVar3 == param_4 ||
                   (iVar2 = EVP_CIPHER_CTX_set_key_length(*(EVP_CIPHER_CTX **)(puVar4 + 2),param_4),
                   iVar2 != 0)))))) &&
             (iVar2 = EVP_CipherInit(*(EVP_CIPHER_CTX **)(puVar4 + 2),(EVP_CIPHER *)0x0,param_3,
                                     (uchar *)0x0,-1), iVar2 != 0)) goto LAB_0011e498;
          pEVar5 = *(EVP_CIPHER_CTX **)(puVar4 + 2);
          uVar8 = 0xffffffea;
        }
        goto LAB_0011e4c2;
      }
    }
    else {
      lVar6 = FUN_0012f2a0(param_3,param_4);
      *(long *)(puVar4 + 4) = lVar6;
      if (lVar6 == 0) goto LAB_0011e4b8;
    }
LAB_0011e498:
    *param_1 = puVar4;
    uVar8 = 0;
  }
  return uVar8;
}



// Function: cipher_crypt @ 0x1e5a0

undefined8
cipher_crypt(long param_1,undefined8 param_2,void *param_3,uchar *param_4,uint param_5,uint param_6,
            int param_7)

{
  int iVar1;
  undefined8 uVar2;
  ulong __n;
  long lVar3;
  long in_FS_OFFSET;
  undefined1 local_41;
  long local_40;
  
  __n = (ulong)param_6;
  lVar3 = *(long *)(param_1 + 0x120);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((*(uint *)(lVar3 + 0x18) & 2) != 0) {
    uVar2 = FUN_0012f3e0(*(undefined8 *)(param_1 + 0x10));
    goto LAB_0011e656;
  }
  if ((*(uint *)(lVar3 + 0x18) & 8) != 0) {
    memcpy(param_3,param_4,(ulong)(param_6 + param_5));
    uVar2 = 0;
    goto LAB_0011e656;
  }
  if (param_7 == 0) {
    if (param_6 != 0) {
LAB_0011e7ab:
      memcpy(param_3,param_4,__n);
LAB_0011e7b8:
      lVar3 = *(long *)(param_1 + 0x120);
    }
    if (param_5 % *(uint *)(lVar3 + 8) != 0) {
      uVar2 = 0xfffffff6;
      goto LAB_0011e656;
    }
    iVar1 = EVP_Cipher(*(EVP_CIPHER_CTX **)(param_1 + 8),(uchar *)((long)param_3 + __n),
                       param_4 + __n,param_5);
    if (-1 < iVar1) {
      if (param_7 == 0) {
LAB_0011e632:
        uVar2 = 0;
        goto LAB_0011e656;
      }
      iVar1 = EVP_Cipher(*(EVP_CIPHER_CTX **)(param_1 + 8),(uchar *)0x0,(uchar *)0x0,0);
      if (iVar1 < 0) {
        uVar2 = 0xffffffe2;
        if (*(int *)(param_1 + 4) == 0) goto LAB_0011e656;
      }
      else if ((*(int *)(param_1 + 4) == 0) ||
              (iVar1 = EVP_CIPHER_CTX_ctrl(*(EVP_CIPHER_CTX **)(param_1 + 8),0x10,param_7,
                                           (void *)(param_5 + __n + (long)param_3)), iVar1 != 0))
      goto LAB_0011e632;
    }
  }
  else {
    iVar1 = FUN_0011dd30();
    uVar2 = 0xfffffff6;
    if (iVar1 != param_7) goto LAB_0011e656;
    iVar1 = EVP_CIPHER_CTX_ctrl(*(EVP_CIPHER_CTX **)(param_1 + 8),0x13,1,&local_41);
    if ((iVar1 != 0) &&
       ((*(int *)(param_1 + 4) != 0 ||
        (iVar1 = EVP_CIPHER_CTX_ctrl(*(EVP_CIPHER_CTX **)(param_1 + 8),0x11,param_7,
                                     param_4 + __n + param_5), iVar1 != 0)))) {
      if (param_6 == 0) goto LAB_0011e7b8;
      iVar1 = EVP_Cipher(*(EVP_CIPHER_CTX **)(param_1 + 8),(uchar *)0x0,param_4,param_6);
      if (-1 < iVar1) goto LAB_0011e7ab;
    }
  }
  uVar2 = 0xffffffea;
LAB_0011e656:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



// Function: cipher_get_length @ 0x1e830

undefined8 cipher_get_length(long param_1,uint *param_2,undefined8 param_3,uint *param_4,uint param_5)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((*(byte *)(*(long *)(param_1 + 0x120) + 0x18) & 2) != 0) {
    uVar2 = FUN_0012f6d0(*(undefined8 *)(param_1 + 0x10));
    return uVar2;
  }
  if (3 < param_5) {
    uVar1 = *param_4;
    *param_2 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    return 0;
  }
  return 0xfffffffd;
}



// Function: cipher_free @ 0x1e970

undefined8 cipher_free(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(*(long *)(param_1 + 0x120) + 0x18);
    if ((uVar1 & 2) == 0) {
      if ((uVar1 & 4) != 0) {
        __explicit_bzero_chk(param_1 + 0x18,0x104,0xffffffffffffffff);
      }
    }
    else {
      FUN_0012f1f0(*(undefined8 *)(param_1 + 0x10));
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
    EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
    uVar2 = FUN_0013b0d0(param_1,0x128);
    return uVar2;
  }
  return 0;
}



// Function: cipher_get_keyiv_len @ 0x1ea60

undefined8 cipher_get_keyiv_len(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x120) + 0x18);
  if ((uVar1 & 2) != 0) {
    return 0;
  }
  if ((uVar1 & 4) == 0) {
    uVar2 = EVP_CIPHER_CTX_get_iv_length(*(undefined8 *)(param_1 + 8));
    return uVar2;
  }
  return 0x10;
}



// Function: cipher_get_keyiv @ 0x1eb90

undefined8 cipher_get_keyiv(long param_1,undefined8 *param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  
  lVar2 = *(long *)(param_1 + 0x120);
  uVar1 = *(uint *)(lVar2 + 0x18);
  if ((uVar1 & 2) == 0) {
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 8) == 0) {
        iVar4 = EVP_CIPHER_CTX_get_iv_length(*(undefined8 *)(param_1 + 8));
        if (iVar4 != 0) {
          if (-1 < iVar4) {
            if (iVar4 != param_3) {
              return 0xfffffff6;
            }
            iVar5 = FUN_0011dd30(lVar2);
            if (iVar5 == 0) {
              iVar4 = EVP_CIPHER_CTX_get_updated_iv
                                (*(EVP_CIPHER_CTX **)(param_1 + 8),param_2,(long)iVar4);
            }
            else {
              iVar4 = EVP_CIPHER_CTX_ctrl(*(EVP_CIPHER_CTX **)(param_1 + 8),0x13,iVar4,param_2);
            }
            if (iVar4 != 0) {
              return 0;
            }
          }
          return 0xffffffea;
        }
      }
    }
    else {
      if (param_3 != 0x10) {
        return 0xfffffff6;
      }
      uVar3 = *(undefined8 *)(param_1 + 0x114);
      *param_2 = *(undefined8 *)(param_1 + 0x10c);
      param_2[1] = uVar3;
    }
  }
  else if (param_3 != 0) {
    return 0xfffffff6;
  }
  return 0;
}



// Function: cipher_set_keyiv @ 0x1ed10

undefined8 cipher_set_keyiv(long param_1,void *param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(param_1 + 0x120);
  if ((*(byte *)(lVar1 + 0x18) & 10) == 0) {
    iVar2 = EVP_CIPHER_CTX_get_iv_length(*(undefined8 *)(param_1 + 8));
    if (0 < iVar2) {
      if (iVar2 != param_3) {
        return 0xfffffff6;
      }
      iVar3 = FUN_0011dd30(lVar1);
      if (iVar3 == 0) {
        iVar2 = FUN_00137a90(*(EVP_CIPHER_CTX **)(param_1 + 8),param_2,(long)iVar2);
      }
      else {
        iVar2 = EVP_CIPHER_CTX_ctrl(*(EVP_CIPHER_CTX **)(param_1 + 8),0x12,-1,param_2);
      }
      if (iVar2 != 0) goto LAB_0011ed2e;
    }
    uVar4 = 0xffffffea;
  }
  else {
LAB_0011ed2e:
    uVar4 = 0;
  }
  return uVar4;
}



// Function: sshfatal @ 0x1ee30

void sshfatal(void)

{
  FUN_00120120();
                    /* WARNING: Subroutine does not return */
  FUN_00131220(0xff);
}



// Function: do_log @ 0x1eed0

undefined8 do_log(int param_1,int param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  size_t __n;
  char *pcVar5;
  char *__ident;
  long in_FS_OFFSET;
  char local_848 [1024];
  undefined1 local_448 [1032];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  piVar4 = __errno_location();
  iVar1 = *piVar4;
  __ident = DAT_00168090;
  if (DAT_00168090 == (char *)0x0) {
    __ident = program_invocation_short_name;
  }
  if ((param_2 == 0) && (DAT_0016801c < param_1)) goto LAB_0011f034;
  switch(param_1) {
  default:
    pcVar5 = "internal error";
    iVar2 = 3;
    break;
  case 1:
    iVar2 = 2;
    if (DAT_00168018 == 0) {
      pcVar5 = "fatal";
      break;
    }
    goto LAB_0011ef70;
  case 2:
    iVar2 = 3;
    if (DAT_00168018 == 0) {
      pcVar5 = "error";
      break;
    }
    goto LAB_0011ef70;
  case 3:
  case 4:
    iVar2 = 6;
    goto LAB_0011ef70;
  case 5:
    iVar2 = 7;
    pcVar5 = "debug1";
    break;
  case 6:
    iVar2 = 7;
    pcVar5 = "debug2";
    break;
  case 7:
    pcVar5 = "debug3";
    iVar2 = param_1;
  }
  if (DAT_00168088 == (code *)0x0) {
    __snprintf_chk(local_448,0x400,1,0x400,"%s: %s",pcVar5,param_4);
    __vsnprintf_chk(local_848,0x400,1,0x400,local_448,param_5);
  }
  else {
LAB_0011ef70:
    __vsnprintf_chk(local_848,0x400,1,0x400,param_4,param_5);
  }
  if (param_3 != 0) {
    __snprintf_chk(local_448,0x400,1,0x400,"%s: %s",local_848,param_3);
    FUN_0013bee0(local_848,local_448,0x400);
  }
  FUN_0013c8f0(local_448,local_848,0x400,(-(uint)(DAT_00168018 == 0) & 0xfffffffa) + 0x21);
  pcVar3 = DAT_00168088;
  if (DAT_00168088 == (code *)0x0) {
    if (DAT_00168018 == 0) {
      openlog(__ident,1,DAT_00168010);
      __syslog_chk(iVar2,1,"%.500s",local_448);
      closelog();
    }
    else {
      if (DAT_00168018 < 2) {
        pcVar5 = "";
        __ident = pcVar5;
      }
      else {
        pcVar5 = ": ";
      }
      __snprintf_chk(local_848,0x400,1,0x400,"%s%s%.*s\r\n",__ident,pcVar5,0x3fd,local_448);
      __n = strlen(local_848);
      write(DAT_00168014,local_848,__n);
    }
  }
  else {
    DAT_00168088 = (code *)0x0;
    (*pcVar3)(param_1,param_2,local_448,DAT_00168080);
    DAT_00168088 = pcVar3;
  }
  *piVar4 = iVar1;
LAB_0011f034:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: log_level_get @ 0x1f2c0

undefined4 log_level_get(void)

{
  return DAT_0016801c;
}



// Function: log_facility_number @ 0x1f350

undefined4 log_facility_number(char *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  ulong uVar3;
  char *__s1;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  __s1 = "DAEMON";
  uVar3 = 0;
  ppuVar2 = &PTR_DAT_001670f0;
  do {
    iVar1 = strcasecmp(__s1,param_1);
    if (iVar1 == 0) {
      return (&DAT_001670e8)[uVar3 * 4];
    }
    iVar1 = FUN_0013da20(uVar3 & 0xffffffff,1);
    __s1 = *ppuVar2;
    uVar3 = (ulong)iVar1;
    ppuVar2 = ppuVar2 + 2;
  } while (__s1 != (char *)0x0);
  return 0xffffffff;
}



// Function: log_facility_name @ 0x1f550

char * log_facility_name(int param_1)

{
  undefined **ppuVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  pcVar3 = "DAEMON";
  ppuVar1 = &PTR_DAT_001670f0;
  while( true ) {
    if (param_1 == iVar2) {
      return pcVar3;
    }
    pcVar3 = *ppuVar1;
    if (pcVar3 == (char *)0x0) break;
    iVar2 = *(int *)(ppuVar1 + 1);
    ppuVar1 = ppuVar1 + 2;
  }
  return (char *)0x0;
}



// Function: log_level_number @ 0x1f610

undefined4 log_level_number(char *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  ulong uVar3;
  char *__s1;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  __s1 = "QUIET";
  uVar3 = 0;
  ppuVar2 = &PTR_s_FATAL_00167050;
  do {
    iVar1 = strcasecmp(__s1,param_1);
    if (iVar1 == 0) {
      return (&DAT_00167048)[uVar3 * 4];
    }
    iVar1 = FUN_0013da20(uVar3 & 0xffffffff,1);
    __s1 = *ppuVar2;
    uVar3 = (ulong)iVar1;
    ppuVar2 = ppuVar2 + 2;
  } while (__s1 != (char *)0x0);
  return 0xffffffff;
}



// Function: log_level_name @ 0x1f810

char * log_level_name(int param_1)

{
  undefined **ppuVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  pcVar3 = "QUIET";
  ppuVar1 = &PTR_s_FATAL_00167050;
  while( true ) {
    if (param_1 == iVar2) {
      return pcVar3;
    }
    pcVar3 = *ppuVar1;
    if (pcVar3 == (char *)0x0) break;
    iVar2 = *(int *)(ppuVar1 + 1);
    ppuVar1 = ppuVar1 + 2;
  }
  return (char *)0x0;
}



// Function: log_verbose_add @ 0x1f8d0

undefined8 log_verbose_add(char *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char *pcVar4;
  
  lVar3 = FUN_0013ba50(DAT_00168078,DAT_00168070,DAT_00168070 + 1,8);
  lVar2 = DAT_00168070;
  if (lVar3 != 0) {
    lVar1 = DAT_00168070 * 8;
    DAT_00168078 = lVar3;
    pcVar4 = strdup(param_1);
    *(char **)(lVar3 + lVar1) = pcVar4;
    if (pcVar4 != (char *)0x0) {
      DAT_00168070 = lVar2 + 1;
    }
  }
  return 0;
}



// Function: log_verbose_reset @ 0x1f9b0

undefined8 log_verbose_reset(void)

{
  long lVar1;
  long lVar2;
  void *__ptr;
  long lVar3;
  
  __ptr = DAT_00168078;
  lVar2 = DAT_00168070;
  lVar3 = 0;
  if (DAT_00168070 != 0) {
    do {
      lVar1 = lVar3 * 8;
      lVar3 = lVar3 + 1;
      free(*(void **)((long)__ptr + lVar1));
    } while (lVar3 != lVar2);
  }
  free(__ptr);
  DAT_00168078 = (void *)0x0;
  DAT_00168070 = 0;
  return 0;
}



// Function: log_change_level @ 0x1fa90

undefined8 log_change_level(uint param_1)

{
  if (DAT_00168090 == 0) {
    return 0;
  }
  if (param_1 < 8) {
    DAT_0016801c = param_1;
    return 0;
  }
  return 0xffffffff;
}



// Function: log_init @ 0x1fc40

undefined8 log_init(char *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined8 extraout_RAX;
  char *pcVar2;
  
  DAT_00168090 = param_1;
  iVar1 = FUN_0011fa90(param_2);
  if (iVar1 == 0) {
    DAT_00168088 = 0;
    DAT_00168080 = 0;
    DAT_00168018 = param_4;
    if (param_4 != 0) {
      return 0;
    }
    switch(param_3) {
    case 0:
      DAT_00168010 = 0x18;
      break;
    case 1:
      DAT_00168010 = 8;
      break;
    case 2:
      DAT_00168010 = 0x20;
      break;
    case 3:
      DAT_00168010 = 0x50;
      break;
    case 4:
      DAT_00168010 = 0x80;
      break;
    case 5:
      DAT_00168010 = 0x88;
      break;
    case 6:
      DAT_00168010 = 0x90;
      break;
    case 7:
      DAT_00168010 = 0x98;
      break;
    case 8:
      DAT_00168010 = 0xa0;
      break;
    case 9:
      DAT_00168010 = 0xa8;
      break;
    case 10:
      DAT_00168010 = 0xb0;
      break;
    case 0xb:
      DAT_00168010 = 0xb8;
      break;
    default:
      pcVar2 = "Unrecognized internal syslog facility code %d\n";
      DAT_00168018 = 0;
      param_2 = param_3;
      goto LAB_0011fe24;
    }
    if (param_1 == (char *)0x0) {
      param_1 = program_invocation_short_name;
    }
    openlog(param_1,1,DAT_00168010);
    closelog();
    return extraout_RAX;
  }
  pcVar2 = "Unrecognized internal syslog level code %d\n";
LAB_0011fe24:
  __fprintf_chk(stderr,1,pcVar2,param_2);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: log_is_on_stderr @ 0x1fe50

bool log_is_on_stderr(void)

{
  return DAT_00168018 != 0 && DAT_00168014 == 2;
}



// Function: log_redirect_stderr_to @ 0x1fef0

undefined8 log_redirect_stderr_to(char *param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  
  if (param_1 == (char *)0x0) {
    iVar1 = DAT_00168014;
    if (DAT_00168014 != 2) {
      close(DAT_00168014);
      DAT_00168014 = 2;
      return 0;
    }
  }
  else {
    iVar1 = open(param_1,0x441,0x180);
    if (iVar1 == -1) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      __fprintf_chk(stderr,1,"Couldn\'t open logfile %s: %s\n",param_1,pcVar3);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
  DAT_00168014 = iVar1;
  return 0;
}



// Function: set_log_handler @ 0x20080

undefined8 set_log_handler(undefined8 param_1,undefined8 param_2)

{
  DAT_00168088 = param_1;
  DAT_00168080 = param_2;
  return 0;
}



// Function: sshlogv @ 0x20120

undefined8
sshlogv(char *param_1,undefined8 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  __pid_t _Var1;
  int iVar2;
  char *pcVar3;
  ulong uVar4;
  undefined4 uVar5;
  long in_FS_OFFSET;
  undefined1 local_548 [128];
  undefined1 local_4c8 [1160];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  _Var1 = getpid();
  pcVar3 = strrchr(param_1,0x2f);
  if (pcVar3 != (char *)0x0) {
    param_1 = pcVar3 + 1;
  }
  __snprintf_chk(local_548,0x80,1,0x80,"%.48s:%.48s():%d (pid=%ld)",param_1,param_2,param_3,
                 (long)_Var1);
  if (DAT_00168070 != 0) {
    uVar4 = 0;
    do {
      iVar2 = FUN_00120960(local_548,*(undefined8 *)(DAT_00168078 + uVar4 * 8),0);
      if (iVar2 == 1) {
        uVar5 = 1;
        __snprintf_chk(local_4c8,0x480,1,0x480,"%s: %s",local_548,param_7);
        goto LAB_0012025e;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < DAT_00168070);
  }
  if (param_4 == 0) {
    FUN_0013bee0(local_4c8,param_7,0x480);
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    __snprintf_chk(local_4c8,0x480,1,0x480,"%s: %s",param_2,param_7);
  }
LAB_0012025e:
  FUN_0011eed0(param_5,uVar5,param_6,local_4c8,param_8);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshlog @ 0x203a0

undefined8 sshlog(void)

{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00120120();
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sshlogdie @ 0x204d0

void sshlogdie(void)

{
  FUN_00120120();
                    /* WARNING: Subroutine does not return */
  FUN_00131220(0xff);
}



// Function: sshsigdie @ 0x20580

void sshsigdie(void)

{
  FUN_00120120();
                    /* WARNING: Subroutine does not return */
  _exit(1);
}



// Function: sshlogdirect @ 0x20630

undefined8
sshlogdirect(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
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
  undefined1 local_b8 [24];
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
  local_c8 = local_b8;
  local_d8 = 0x18;
  local_d4 = 0x30;
  local_a0 = param_12;
  local_98 = param_13;
  local_90 = param_14;
  FUN_0011eed0(param_9,param_10,0,param_11,&local_d8);
  if (local_c0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: match_pattern @ 0x20770

ulong match_pattern(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  
  cVar1 = *param_2;
  while( true ) {
    if (cVar1 == '\0') {
      return (ulong)(*param_1 == '\0');
    }
    if (cVar1 == '*') break;
    if ((*param_1 == '\0') || ((cVar1 != '?' && (*param_1 != cVar1)))) goto LAB_00120810;
    cVar1 = param_2[1];
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  for (; cVar1 = *param_2, cVar1 == '*'; param_2 = param_2 + 1) {
  }
  uVar4 = 1;
  if (cVar1 != '\0') {
    cVar2 = *param_1;
    if (cVar1 == '?') {
      if (cVar2 != '\0') {
        do {
          uVar4 = match_pattern(param_1,param_2);
          if ((int)uVar4 != 0) {
            return 1;
          }
          param_1 = param_1 + 1;
        } while (*param_1 != '\0');
        return uVar4;
      }
    }
    else if (cVar2 != '\0') {
      do {
        param_1 = param_1 + 1;
        if ((cVar1 == cVar2) && (iVar3 = match_pattern(param_1,param_2 + 1), iVar3 != 0)) {
          return 1;
        }
        cVar2 = *param_1;
      } while (cVar2 != '\0');
    }
LAB_00120810:
    uVar4 = 0;
  }
  return uVar4;
}



// Function: match_pattern_list @ 0x20960

undefined4 match_pattern_list(undefined8 param_1,char *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  ulong uVar5;
  ushort **ppuVar6;
  __int32_t **pp_Var7;
  byte bVar8;
  ulong uVar9;
  uint uVar10;
  long in_FS_OFFSET;
  undefined4 local_450;
  undefined4 local_44c;
  undefined1 local_448 [1032];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sVar4 = strlen(param_2);
  uVar2 = (uint)sVar4;
  if (uVar2 == 0) {
LAB_001209a2:
    local_450 = 0;
  }
  else {
    uVar10 = 0;
    uVar9 = 0;
    local_450 = 0;
LAB_00120a72:
    do {
      while( true ) {
        if (param_2[uVar9] == '!') {
          uVar10 = uVar10 + 1;
        }
        local_44c = (uint)(param_2[uVar9] == '!');
        uVar9 = 1;
        uVar5 = 0;
        if (uVar10 < uVar2) break;
LAB_00120b15:
        local_448[uVar5] = 0;
        iVar3 = FUN_00120770(param_1,local_448);
        if (iVar3 == 0) goto LAB_001209aa;
LAB_00120b31:
        if (local_44c != 0) goto LAB_00120bf0;
        local_450 = 1;
LAB_00120b45:
        if (uVar2 <= uVar10) goto LAB_001209aa;
        uVar9 = (ulong)uVar10;
      }
      do {
        uVar5 = uVar9 & 0xffffffff;
        uVar1 = (uint)uVar9;
        bVar8 = param_2[uVar10];
        if (bVar8 == 0x2c) {
          uVar5 = (ulong)(uVar1 - 1);
          if (uVar10 < uVar2) goto LAB_00120bc0;
          goto LAB_00120b15;
        }
        if (param_3 != 0) {
          ppuVar6 = __ctype_b_loc();
          if ((*(byte *)((long)*ppuVar6 + (ulong)bVar8 * 2 + 1) & 1) != 0) {
            pp_Var7 = __ctype_tolower_loc();
            bVar8 = *(byte *)(*pp_Var7 + bVar8);
          }
        }
        uVar10 = uVar10 + 1;
        local_448[uVar9 - 1] = bVar8;
        uVar9 = uVar9 + 1;
      } while ((uVar10 < uVar2) && (uVar1 < 0x3ff));
      if (uVar1 == 0x3ff) goto LAB_001209a2;
      if (uVar2 <= uVar10) goto LAB_00120b15;
      uVar9 = (ulong)uVar10;
      if (param_2[uVar9] == ',') {
LAB_00120bc0:
        uVar10 = uVar10 + 1;
        local_448[uVar5] = 0;
        iVar3 = FUN_00120770(param_1,local_448);
        if (iVar3 != 0) goto LAB_00120b31;
        goto LAB_00120b45;
      }
      local_448[uVar5] = 0;
      iVar3 = FUN_00120770(param_1,local_448);
    } while (iVar3 == 0);
    if (local_44c == 0) {
      local_450 = 1;
      goto LAB_00120a72;
    }
LAB_00120bf0:
    local_450 = 0xffffffff;
  }
LAB_001209aa:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_450;
}



// Function: filter_list @ 0x20c10

char * filter_list(char *param_1,undefined8 param_2,byte param_3)

{
  int iVar1;
  size_t sVar2;
  char *__ptr;
  char *pcVar3;
  char *pcVar4;
  long in_FS_OFFSET;
  char *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sVar2 = strlen(param_1);
  sVar2 = sVar2 + 1;
  __ptr = malloc(sVar2);
  pcVar3 = strdup(param_1);
  if ((__ptr == (char *)0x0) || (pcVar3 == (char *)0x0)) {
    free(pcVar3);
    pcVar3 = (char *)0x0;
    free(__ptr);
  }
  else {
    *__ptr = '\0';
    local_48 = pcVar3;
    while( true ) {
      pcVar4 = strsep(&local_48,",");
      if (pcVar4 == (char *)0x0) break;
      iVar1 = FUN_00120960(pcVar4,param_2,0);
      if ((bool)(param_3 & 1) != (iVar1 == 1)) {
        if (*__ptr != '\0') {
          FUN_0013bcf0(__ptr,&DAT_0013f0c9,sVar2);
        }
        FUN_0013bcf0(__ptr,pcVar4,sVar2);
      }
    }
    free(pcVar3);
    pcVar3 = __ptr;
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: match_usergroup_pattern_list @ 0x20dc0

void match_usergroup_pattern_list(undefined8 param_1,undefined8 param_2)

{
  FUN_00120960(param_1,param_2,0);
  return;
}



// Function: match_hostname @ 0x20dd0

undefined4 match_hostname(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  void *__ptr;
  
  __ptr = (void *)FUN_00121840();
  FUN_00127d90(__ptr);
  uVar1 = FUN_00120960(__ptr,param_2,1);
  free(__ptr);
  return uVar1;
}



// Function: match_host_and_ip @ 0x20e90

ulong match_host_and_ip(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = FUN_00121aa0(param_2,param_3);
  uVar3 = 0xffffffff;
  if (iVar1 != -2) {
    if ((param_1 != 0 && param_2 != 0) && (iVar1 != -1)) {
      iVar2 = FUN_00120dd0(param_1,param_3);
      if (iVar2 != -1) {
        return (ulong)(iVar1 != 0 || iVar2 != 0);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



// Function: match_user @ 0x21020

ulong match_user(long param_1,long param_2,long param_3,char *param_4)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  
  pcVar2 = strchr(param_4,0x40);
  if ((param_2 == 0 && param_3 == 0) && param_1 == 0) {
    uVar4 = 0;
    if (pcVar2 != (char *)0x0) {
      uVar1 = FUN_00120e90(0,0,pcVar2 + 1);
      uVar1 = FUN_0013dae0(uVar1 >> 0x1f);
      uVar4 = (ulong)uVar1;
    }
  }
  else {
    if (pcVar2 == (char *)0x0) {
      uVar4 = FUN_00120770(param_1,param_4);
      return uVar4;
    }
    pcVar2 = (char *)FUN_00121840(param_4);
    pcVar3 = strchr(pcVar2,0x40);
    *pcVar3 = '\0';
    uVar1 = FUN_00120770(param_1,pcVar2);
    if (uVar1 == 1) {
      uVar1 = FUN_00120e90(param_2,param_3,pcVar3 + 1);
    }
    uVar4 = (ulong)uVar1;
    free(pcVar2);
  }
  return uVar4;
}



// Function: match_list @ 0x211a0

undefined8 match_list(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *__s;
  char *__ptr;
  char *pcVar3;
  undefined8 uVar4;
  size_t sVar5;
  int iVar6;
  long lVar7;
  undefined8 *puVar8;
  long in_FS_OFFSET;
  char *local_198;
  char *local_190;
  undefined8 local_188 [41];
  long local_40;
  
  iVar6 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  __s = (char *)FUN_00121840();
  local_198 = __s;
  __ptr = (char *)FUN_00121840(param_2);
  local_190 = __ptr;
  pcVar3 = strsep(&local_190,",");
  if (pcVar3 != (char *)0x0) {
    lVar7 = 0;
    do {
      iVar6 = (int)lVar7;
      if (*pcVar3 == '\0') break;
      if (lVar7 == 0x28) {
        iVar6 = 0x28;
        break;
      }
      local_188[lVar7] = pcVar3;
      iVar6 = iVar6 + 1;
      pcVar3 = strsep(&local_190,",");
      lVar7 = lVar7 + 1;
    } while (pcVar3 != (char *)0x0);
  }
  pcVar3 = strsep(&local_198,",");
  if (pcVar3 != (char *)0x0) {
    while (*pcVar3 != '\0') {
      puVar8 = local_188;
      if (iVar6 != 0) {
        do {
          iVar1 = strcmp(pcVar3,(char *)*puVar8);
          if (iVar1 == 0) {
            uVar4 = FUN_00121840(pcVar3);
            if (param_3 != (undefined4 *)0x0) {
              if (local_198 == (char *)0x0) {
                sVar5 = strlen(__s);
                uVar2 = (undefined4)sVar5;
              }
              else {
                uVar2 = FUN_0013da40(local_198,__s);
              }
              *param_3 = uVar2;
            }
            free(__s);
            free(__ptr);
            goto LAB_001212ee;
          }
          puVar8 = puVar8 + 1;
        } while (puVar8 != local_188 + (ulong)(iVar6 - 1) + 1);
      }
      pcVar3 = strsep(&local_198,",");
      if (pcVar3 == (char *)0x0) break;
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    sVar5 = strlen(__s);
    *param_3 = (int)sVar5;
  }
  uVar4 = 0;
  free(__s);
  free(__ptr);
LAB_001212ee:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



// Function: match_filter_denylist @ 0x21420

void match_filter_denylist(undefined8 param_1,undefined8 param_2)

{
  FUN_00120c10(param_1,param_2,1);
  return;
}



// Function: match_filter_allowlist @ 0x21430

void match_filter_allowlist(undefined8 param_1,undefined8 param_2)

{
  FUN_00120c10(param_1,param_2,0);
  return;
}



// Function: xmalloc @ 0x21440

undefined8 xmalloc(size_t param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("xmalloc.c","xmalloc",0x27,0,1,0,"xmalloc: zero size");
  }
  pvVar1 = malloc(param_1);
  if (pvVar1 != (void *)0x0) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("xmalloc.c","xmalloc",0x2a,0,1,0,"xmalloc: out of memory (allocating %zu bytes)",
               param_1);
}



// Function: xcalloc @ 0x21540

undefined8 xcalloc(ulong param_1,size_t param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 uVar3;
  void *pvVar4;
  
  if ((param_2 == 0) || (param_1 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("xmalloc.c","xcalloc",0x34,0,1,0,"xcalloc: zero size",param_3);
  }
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_2;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_1;
  uVar3 = SUB168(auVar1 * auVar2,0);
  if (SUB168(auVar1 * auVar2,8) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("xmalloc.c","xcalloc",0x36,0,1,0,"xcalloc: nmemb * size > SIZE_MAX",uVar3);
  }
  pvVar4 = calloc(param_1,param_2);
  if (pvVar4 != (void *)0x0) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("xmalloc.c","xcalloc",0x39,0,1,0,"xcalloc: out of memory (allocating %zu bytes)",
               uVar3);
}



// Function: xreallocarray @ 0x21680

undefined8 xreallocarray(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = reallocarray();
  if (lVar1 != 0) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("xmalloc.c","xreallocarray",0x45,0,1,0,
               "xreallocarray: out of memory (%zu elements of %zu bytes)",param_2,param_3,0);
}



// Function: xrecallocarray @ 0x21760

undefined8 xrecallocarray(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = FUN_0013ba50();
  if (lVar1 != 0) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("xmalloc.c","xrecallocarray",0x51,0,1,0,
               "xrecallocarray: out of memory (%zu elements of %zu bytes)",param_3,param_4,0);
}



// Function: xstrdup @ 0x21840

void xstrdup(char *param_1)

{
  size_t sVar1;
  void *__dest;
  
  sVar1 = strlen(param_1);
  __dest = (void *)FUN_00121440(sVar1 + 1);
  memcpy(__dest,param_1,sVar1 + 1);
  return;
}



// Function: xvasprintf @ 0x21880

undefined8 xvasprintf(long *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = __vasprintf_chk(param_1,1,param_2,param_3);
  if ((-1 < (int)uVar1) && (*param_1 != 0)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("xmalloc.c","xvasprintf",0x68,0,1,0,"xvasprintf: could not allocate memory",uVar1);
}



// Function: xasprintf @ 0x21960

undefined8
xasprintf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
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
  FUN_00121880(param_9,param_10,&local_d8);
  if (local_c0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: addr_match_list @ 0x21aa0

undefined4 addr_match_list(long param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *__ptr;
  char *pcVar4;
  long in_FS_OFFSET;
  undefined4 local_94;
  undefined4 local_84;
  char *local_80;
  undefined1 local_78 [32];
  undefined1 local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 == 0) || (iVar3 = FUN_001325d0(param_1,local_78), iVar3 == 0)) {
    __ptr = strdup(param_2);
    local_80 = __ptr;
    if (__ptr == (char *)0x0) {
      local_94 = 0xffffffff;
    }
    else {
      local_94 = 0;
LAB_00121b13:
      while (pcVar4 = strsep(&local_80,","), pcVar4 != (char *)0x0) {
        cVar1 = *pcVar4;
        cVar2 = cVar1;
        if (cVar1 == '!') {
          cVar2 = pcVar4[1];
          pcVar4 = pcVar4 + 1;
        }
        if (cVar2 == '\0') {
          local_94 = 0xfffffffe;
          break;
        }
        iVar3 = FUN_001329d0(pcVar4,local_58,&local_84);
        if (iVar3 == -2) {
          FUN_001203a0("addrmatch.c","addr_match_list",0x49,1,6,0,
                       "inconsistent mask length for match network \"%.100s\"",pcVar4);
          local_94 = 0xfffffffe;
          break;
        }
        if (iVar3 != 0) goto LAB_00121ba0;
        if ((param_1 != 0) && (iVar3 = FUN_00132bd0(local_78,local_58,local_84), iVar3 == 0))
        goto LAB_00121b86;
      }
LAB_00121bc8:
      free(__ptr);
    }
  }
  else {
    FUN_001203a0("addrmatch.c","addr_match_list",0x39,1,6,0,"couldn\'t parse address %.100s",param_1
                );
    local_94 = 0;
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_94;
LAB_00121ba0:
  if ((param_1 != 0) && (iVar3 = FUN_00120770(param_1,pcVar4), iVar3 == 1)) {
LAB_00121b86:
    if (cVar1 == '!') {
      local_94 = 0xffffffff;
      goto LAB_00121bc8;
    }
    local_94 = 1;
  }
  goto LAB_00121b13;
}



// Function: addr_match_cidr_list @ 0x21d30

undefined4 addr_match_cidr_list(long param_1,char *param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *__ptr;
  char *__s;
  size_t sVar3;
  size_t sVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long in_FS_OFFSET;
  char *pcVar7;
  undefined4 local_9c;
  undefined4 local_84;
  char *local_80;
  undefined1 local_78 [32];
  undefined1 local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 == 0) || (iVar2 = FUN_001325d0(param_1,local_78), iVar2 == 0)) {
    __ptr = strdup(param_2);
    local_80 = __ptr;
    if (__ptr == (char *)0x0) {
      local_9c = 0xffffffff;
    }
    else {
      local_9c = 0;
      uVar1 = local_9c;
      while (local_9c = uVar1, __s = strsep(&local_80,","), __s != (char *)0x0) {
        if (*__s == '\0') {
          pcVar7 = "empty entry in list \"%.100s\"";
          uVar5 = 1;
          uVar6 = 0x7c;
          __s = __ptr;
LAB_00121f67:
          local_9c = 0xffffffff;
          FUN_001203a0("addrmatch.c","addr_match_cidr_list",uVar6,uVar5,2,0,pcVar7,__s);
          break;
        }
        sVar3 = strlen(__s);
        if (0x31 < sVar3) {
          uVar5 = 1;
          uVar6 = 0x89;
          pcVar7 = "list entry \"%.100s\" too long";
          goto LAB_00121f67;
        }
        sVar4 = strspn(__s,"0123456789abcdefABCDEF.:/");
        if (sVar3 != sVar4) {
          FUN_001203a0("addrmatch.c","addr_match_cidr_list",0x8f,1,2,0,
                       "list entry \"%.100s\" contains invalid characters",__s);
          local_9c = 0xffffffff;
        }
        iVar2 = FUN_001329d0(__s,local_58,&local_84);
        if (iVar2 == -1) {
          uVar5 = 0;
          pcVar7 = "Invalid network entry \"%.100s\"";
          uVar6 = 0x97;
          goto LAB_00121f67;
        }
        if (iVar2 == -2) {
          uVar5 = 0;
          pcVar7 = "Inconsistent mask length for network \"%.100s\"";
          uVar6 = 0x9b;
          goto LAB_00121f67;
        }
        uVar1 = local_9c;
        if ((iVar2 == 0) && (param_1 != 0)) {
          iVar2 = FUN_00132bd0(local_78,local_58,local_84);
          uVar1 = 1;
          if (iVar2 != 0) {
            uVar1 = local_9c;
          }
        }
      }
      free(__ptr);
    }
  }
  else {
    local_9c = 0;
    FUN_001203a0("addrmatch.c","addr_match_cidr_list",0x75,1,6,0,"couldn\'t parse address %.100s",
                 param_1);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_9c;
}



// Function: hexchar @ 0x22040

uint hexchar(char *param_1)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  
  cVar1 = *param_1;
  bVar3 = cVar1 - 0x30;
  if (9 < bVar3) {
    if ((byte)(cVar1 + 0x9fU) < 6) {
      cVar2 = param_1[1];
      bVar3 = cVar1 + 0xa9;
      goto joined_r0x0012206d;
    }
    if (5 < (byte)(cVar1 + 0xbfU)) {
      return 0xffffffff;
    }
    bVar3 = cVar1 - 0x37;
  }
  cVar2 = param_1[1];
joined_r0x0012206d:
  bVar4 = cVar2 - 0x30;
  if (9 < bVar4) {
    if (5 < (byte)(cVar2 + 0x9fU)) {
      if (5 < (byte)(cVar2 + 0xbfU)) {
        return 0xffffffff;
      }
      return (uint)bVar3 << 4 | (uint)(byte)(cVar2 - 0x37);
    }
    bVar4 = cVar2 + 0xa9;
  }
  return (uint)bVar3 << 4 | (uint)bVar4;
}



// Function: strdelim_internal @ 0x22250

char * strdelim_internal(long *param_1,int param_2)

{
  char cVar1;
  char *__s;
  long lVar2;
  size_t sVar3;
  char *pcVar4;
  
  __s = (char *)*param_1;
  if (__s == (char *)0x0) {
    return (char *)0x0;
  }
  pcVar4 = " \t\r\n\"=";
  if (param_2 == 0) {
    pcVar4 = " \t\r\n\"";
  }
  pcVar4 = strpbrk(__s,pcVar4);
  *param_1 = (long)pcVar4;
  if (pcVar4 != (char *)0x0) {
    cVar1 = *pcVar4;
    if (cVar1 == '\"') {
      sVar3 = strlen(pcVar4);
      memmove(pcVar4,pcVar4 + 1,sVar3);
      pcVar4 = strpbrk((char *)*param_1,"\"");
      *param_1 = (long)pcVar4;
      if (pcVar4 == (char *)0x0) {
        return (char *)0x0;
      }
      *pcVar4 = '\0';
      lVar2 = *param_1;
      sVar3 = strspn((char *)(lVar2 + 1)," \t\r\n");
      *param_1 = lVar2 + 1 + sVar3;
      return __s;
    }
    *pcVar4 = '\0';
    lVar2 = *param_1;
    if (param_2 == 0) {
      sVar3 = strspn((char *)(lVar2 + 1)," \t\r\n");
      *param_1 = lVar2 + 1 + sVar3;
      return __s;
    }
    sVar3 = strspn((char *)(lVar2 + 1)," \t\r\n");
    pcVar4 = (char *)(lVar2 + 1 + sVar3);
    *param_1 = (long)pcVar4;
    if ((*pcVar4 == '=') && (cVar1 != '=')) {
      sVar3 = strspn(pcVar4 + 1," \t\r\n");
      *param_1 = (long)(pcVar4 + sVar3 + 1);
    }
  }
  return __s;
}



// Function: urldecode @ 0x22610

undefined1 * urldecode(byte *param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  size_t sVar4;
  undefined1 *__ptr;
  ushort **ppuVar5;
  
  sVar4 = strlen((char *)param_1);
  __ptr = (undefined1 *)FUN_00121440(sVar4 + 1);
  bVar1 = *param_1;
  puVar2 = __ptr;
  do {
    if (bVar1 == 0) {
      *puVar2 = 0;
      return __ptr;
    }
    uVar3 = (uint)bVar1;
    if (bVar1 == 0x25) {
      ppuVar5 = __ctype_b_loc();
      if ((((*(byte *)((long)*ppuVar5 + (ulong)param_1[1] * 2 + 1) & 0x10) == 0) ||
          ((*(byte *)((long)*ppuVar5 + (ulong)param_1[2] * 2 + 1) & 0x10) == 0)) ||
         (uVar3 = FUN_00122040(param_1 + 1), uVar3 == 0xffffffff)) {
        free(__ptr);
        return (undefined1 *)0x0;
      }
      param_1 = param_1 + 2;
    }
    else if (bVar1 == 0x2b) {
      uVar3 = 0x20;
    }
    *puVar2 = (char)uVar3;
    bVar1 = param_1[1];
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  } while( true );
}



// Function: vdollar_percent_expand @ 0x227d0

long vdollar_percent_expand(int *param_1,byte param_2,int param_3,char *param_4,uint *param_5)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  size_t sVar8;
  char *__name;
  char *__s;
  long *plVar9;
  long *plVar10;
  undefined8 uVar11;
  undefined8 in_R10;
  long lVar12;
  ulong uVar13;
  long in_FS_OFFSET;
  undefined1 auVar14 [16];
  uint local_150;
  long local_148 [33];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar6 = FUN_0010b880();
  if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("misc.c","vdollar_percent_expand",0x4d3,1,1,0,"sshbuf_new failed",0);
  }
  *param_1 = 1;
  if (param_3 == 0) {
    local_150 = 0;
  }
  else {
    plVar9 = local_148;
    local_150 = 0;
    do {
      uVar1 = *param_5;
      if (uVar1 < 0x30) {
        *param_5 = uVar1 + 8;
        lVar12 = *(long *)((ulong)uVar1 + *(long *)(param_5 + 4));
        *plVar9 = lVar12;
      }
      else {
        plVar10 = *(long **)(param_5 + 2);
        *(long **)(param_5 + 2) = plVar10 + 1;
        lVar12 = *plVar10;
        *plVar9 = lVar12;
      }
      if (lVar12 == 0) {
        if (local_150 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0011ee30("misc.c","vdollar_percent_expand",0x4e7,1,1,0,
                       "percent expansion without token list",lVar6);
        }
        goto LAB_00122831;
      }
      uVar1 = *param_5;
      if (uVar1 < 0x30) {
        plVar10 = (long *)((ulong)uVar1 + *(long *)(param_5 + 4));
        *param_5 = uVar1 + 8;
      }
      else {
        plVar10 = *(long **)(param_5 + 2);
        *(long **)(param_5 + 2) = plVar10 + 1;
      }
      lVar2 = *plVar10;
      plVar9[1] = lVar2;
      if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0011ee30("misc.c","vdollar_percent_expand",0x4e0,1,1,0,"NULL replacement for token %s",
                     lVar12);
      }
      local_150 = local_150 + 1;
      plVar9 = plVar9 + 2;
    } while (local_150 != 0x10);
    uVar1 = *param_5;
    if (uVar1 < 0x30) {
      plVar9 = (long *)(ulong)(uVar1 + 8);
      plVar10 = (long *)((ulong)uVar1 + *(long *)(param_5 + 4));
      *param_5 = uVar1 + 8;
    }
    else {
      plVar10 = *(long **)(param_5 + 2);
      plVar9 = plVar10 + 1;
      *(long **)(param_5 + 2) = plVar9;
    }
    if (*plVar10 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0011ee30("misc.c","vdollar_percent_expand",0x4e5,1,1,0,"too many keys",plVar9);
    }
  }
LAB_00122831:
  cVar4 = *param_4;
  if (cVar4 != '\0') {
    bVar3 = false;
LAB_0012288a:
    do {
      if ((cVar4 != '$') || ((param_2 & 1) == 0)) {
        if ((cVar4 != '%') || ((((byte)param_3 ^ 1) & 1) != 0)) goto LAB_00122860;
        cVar4 = param_4[1];
        param_4 = param_4 + 1;
        if (cVar4 == '%') goto LAB_00122867;
        if (cVar4 == '\0') {
          pcVar7 = "invalid format";
          uVar11 = 0x518;
          goto LAB_00122d30;
        }
        if (local_150 != 0) {
          uVar13 = 0;
          while( true ) {
            pcVar7 = strchr((char *)local_148[uVar13 * 2],(int)cVar4);
            if (pcVar7 != (char *)0x0) break;
            uVar13 = uVar13 + 1;
            if (uVar13 == local_150) goto LAB_00122958;
          }
          pcVar7 = (char *)local_148[(uVar13 & 0xffffffff) * 2 + 1];
          sVar8 = strlen(pcVar7);
          iVar5 = FUN_0011a9d0(lVar6,pcVar7,sVar8);
          if (iVar5 != 0) {
            uVar11 = FUN_0010b050(iVar5);
                    /* WARNING: Subroutine does not return */
            FUN_0011ee30("misc.c","vdollar_percent_expand",0x51f,1,1,uVar11,"sshbuf_put %%-repl",
                         pcVar7);
          }
          if ((uint)uVar13 < local_150) goto LAB_00122877;
        }
LAB_00122958:
        pcVar7 = "unknown key %%%c";
        uVar11 = 0x524;
LAB_00122d30:
        lVar12 = 0;
        FUN_001203a0("misc.c","vdollar_percent_expand",uVar11,1,2,0,pcVar7);
        goto LAB_00122b42;
      }
      if (param_4[1] != '{') {
LAB_00122860:
        cVar4 = *param_4;
LAB_00122867:
        iVar5 = FUN_0011b180(lVar6,cVar4);
        if (iVar5 != 0) {
          uVar11 = FUN_0010b050(iVar5);
                    /* WARNING: Subroutine does not return */
          FUN_0011ee30("misc.c","vdollar_percent_expand",0x510,1,1,uVar11,"sshbuf_put_u8 %%");
        }
LAB_00122877:
        cVar4 = param_4[1];
        param_4 = param_4 + 1;
        if (cVar4 == '\0') break;
        goto LAB_0012288a;
      }
      param_4 = param_4 + 2;
      pcVar7 = strchr(param_4,0x7d);
      if (pcVar7 == (char *)0x0) {
        FUN_001203a0("misc.c","vdollar_percent_expand",0x4f0,1,2,0,
                     "environment variable \'%s\' missing closing \'}\'",param_4);
        lVar12 = 0;
        goto LAB_00122b42;
      }
      lVar12 = FUN_0013da40(pcVar7,param_4);
      if (lVar12 == 0) {
        pcVar7 = "zero-length environment variable";
        uVar11 = 0x4f6;
        goto LAB_00122d30;
      }
      __name = (char *)FUN_00121440(lVar12 + 1);
      FUN_0013bee0(__name,param_4,lVar12 + 1);
      __s = getenv(__name);
      if (__s == (char *)0x0) {
        FUN_001203a0("misc.c","vdollar_percent_expand",0x4fc,1,2,0,"env var ${%s} has no value",
                     __name);
        bVar3 = true;
      }
      else {
        FUN_001203a0("misc.c","vdollar_percent_expand",0x4ff,1,7,0,"expand ${%s} -> \'%s\'",__name,
                     __s);
        sVar8 = strlen(__s);
        iVar5 = FUN_0011a9d0(lVar6,__s,sVar8);
        if (iVar5 != 0) {
          uVar11 = FUN_0010b050(iVar5);
                    /* WARNING: Subroutine does not return */
          FUN_0011ee30("misc.c","vdollar_percent_expand",0x501,1,1,uVar11,"sshbuf_put ${}",in_R10);
        }
      }
      param_4 = pcVar7 + 1;
      free(__name);
      cVar4 = pcVar7[1];
    } while (cVar4 != '\0');
    lVar12 = 0;
    if (bVar3) goto LAB_00122b37;
  }
  auVar14 = FUN_0011c770(lVar6);
  lVar12 = auVar14._0_8_;
  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("misc.c","vdollar_percent_expand",0x529,1,1,0,"sshbuf_dup_string failed",
                 auVar14._8_8_);
  }
LAB_00122b37:
  *param_1 = 0;
LAB_00122b42:
  FUN_0010bce0(lVar6);
  if (*param_1 != 0) {
    lVar12 = 0;
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: strcmp_maybe_null @ 0x22ec0

bool strcmp_maybe_null(char *param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (((param_1 == (char *)0x0) == (param_2 == (char *)0x0)) &&
     (bVar1 = true, param_1 != (char *)0x0)) {
    iVar2 = strcmp(param_1,param_2);
    return iVar2 == 0;
  }
  return bVar1;
}



// Function: chop @ 0x23080

char * chop(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = *param_1;
  pcVar2 = param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return pcVar2;
    }
    if ((cVar1 == '\n') || (cVar1 == '\r')) break;
    cVar1 = param_1[1];
    param_1 = param_1 + 1;
  }
  *param_1 = '\0';
  return pcVar2;
}



// Function: rtrim @ 0x231c0

undefined8 rtrim(char *param_1)

{
  size_t sVar1;
  ushort **ppuVar2;
  char *pcVar3;
  
  sVar1 = strlen(param_1);
  if (1 < sVar1) {
    ppuVar2 = __ctype_b_loc();
    pcVar3 = param_1 + (sVar1 - 1);
    do {
      if ((*(byte *)((long)*ppuVar2 + (long)*pcVar3 * 2 + 1) & 0x20) != 0) {
        *pcVar3 = '\0';
      }
      pcVar3 = pcVar3 + -1;
    } while (param_1 != pcVar3);
  }
  return 0;
}



// Function: set_nonblock @ 0x23290

undefined4 set_nonblock(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  uVar1 = fcntl(param_1,3);
  if (uVar1 == 0xffffffff) {
    piVar3 = __errno_location();
    uVar5 = 0xffffffff;
    pcVar4 = strerror(*piVar3);
    FUN_001203a0("misc.c","set_nonblock",0x6f,0,2,0,"fcntl(%d, F_GETFL): %s",param_1,pcVar4);
  }
  else {
    if ((uVar1 & 0x800) != 0) {
      FUN_001203a0("misc.c","set_nonblock",0x73,0,7,0,"fd %d is O_NONBLOCK",param_1);
      return 0;
    }
    FUN_001203a0("misc.c","set_nonblock",0x76,0,6,0,"fd %d setting O_NONBLOCK",param_1);
    iVar2 = fcntl(param_1,4,(ulong)uVar1 | 0x800);
    uVar5 = 0;
    if (iVar2 == -1) {
      piVar3 = __errno_location();
      uVar5 = 0xffffffff;
      pcVar4 = strerror(*piVar3);
      FUN_001203a0("misc.c","set_nonblock",0x79,0,5,0,"fcntl(%d, F_SETFL, O_NONBLOCK): %s",param_1,
                   pcVar4);
    }
  }
  return uVar5;
}



// Function: unset_nonblock @ 0x234f0

undefined4 unset_nonblock(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  uVar1 = fcntl(param_1,3);
  if (uVar1 == 0xffffffff) {
    piVar3 = __errno_location();
    uVar5 = 0xffffffff;
    pcVar4 = strerror(*piVar3);
    FUN_001203a0("misc.c","unset_nonblock",0x87,0,2,0,"fcntl(%d, F_GETFL): %s",param_1,pcVar4);
  }
  else {
    if ((uVar1 & 0x800) == 0) {
      FUN_001203a0("misc.c","unset_nonblock",0x8b,0,7,0,"fd %d is not O_NONBLOCK",param_1);
      return 0;
    }
    FUN_001203a0("misc.c","unset_nonblock",0x8e,0,5,0,"fd %d clearing O_NONBLOCK",param_1);
    iVar2 = fcntl(param_1,4,(ulong)uVar1 & 0xfffffffffffff7ff);
    if (iVar2 == -1) {
      piVar3 = __errno_location();
      pcVar4 = strerror(*piVar3);
      FUN_001203a0("misc.c","unset_nonblock",0x91,0,5,0,"fcntl(%d, F_SETFL, ~O_NONBLOCK): %s",
                   param_1,pcVar4);
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 0;
    }
  }
  return uVar5;
}



// Function: ssh_gai_strerror @ 0x23760

void ssh_gai_strerror(int param_1)

{
  int *piVar1;
  
  if (param_1 == -0xb) {
    piVar1 = __errno_location();
    if (*piVar1 != 0) {
      strerror(*piVar1);
      return;
    }
  }
  gai_strerror(param_1);
  return;
}



// Function: set_nodelay @ 0x23790

undefined8 set_nodelay(int param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  long in_FS_OFFSET;
  int local_38 [2];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_38[1] = 4;
  iVar1 = getsockopt(param_1,6,1,local_38,(socklen_t *)(local_38 + 1));
  if (iVar1 == -1) {
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    FUN_001203a0("misc.c","set_nodelay",0xa9,0,5,0,"getsockopt TCP_NODELAY: %.100s",pcVar3);
  }
  else if (local_38[0] == 1) {
    FUN_001203a0("misc.c","set_nodelay",0xad,0,6,0,"fd %d is TCP_NODELAY",param_1);
  }
  else {
    local_38[0] = 1;
    FUN_001203a0("misc.c","set_nodelay",0xb1,0,6,0,"fd %d setting TCP_NODELAY",param_1);
    iVar1 = setsockopt(param_1,6,1,local_38,4);
    if (iVar1 == -1) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      FUN_001203a0("misc.c","set_nodelay",0xb3,0,2,0,"setsockopt TCP_NODELAY: %.100s",pcVar3);
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: set_reuseaddr @ 0x239b0

undefined8 set_reuseaddr(int param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined8 uVar4;
  long in_FS_OFFSET;
  undefined4 local_24;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_24 = 1;
  iVar1 = setsockopt(param_1,1,2,&local_24,4);
  if (iVar1 == -1) {
    uVar4 = 0xffffffff;
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    FUN_001203a0("misc.c","set_reuseaddr",0xbd,0,2,0,"setsockopt SO_REUSEADDR fd %d: %s",param_1,
                 pcVar3);
  }
  else {
    uVar4 = 0;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: get_sock_af @ 0x23b10

uint get_sock_af(int param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  sockaddr *psVar4;
  long in_FS_OFFSET;
  socklen_t local_9c;
  sockaddr local_98;
  int local_88;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_9c = 0x80;
  psVar4 = &local_98;
  for (lVar3 = 0x10; lVar3 != 0; lVar3 = lVar3 + -1) {
    psVar4->sa_family = 0;
    psVar4->sa_data[0] = '\0';
    psVar4->sa_data[1] = '\0';
    psVar4->sa_data[2] = '\0';
    psVar4->sa_data[3] = '\0';
    psVar4->sa_data[4] = '\0';
    psVar4->sa_data[5] = '\0';
    psVar4 = (sockaddr *)(psVar4->sa_data + 6);
  }
  uVar1 = getsockname(param_1,&local_98,&local_9c);
  if (uVar1 != 0xffffffff) {
    if ((local_98.sa_family == 10) && (local_98.sa_data._6_4_ == 0 && local_98.sa_data._10_4_ == 0))
    {
      iVar2 = FUN_00122ff0();
      if (local_88 == iVar2) {
        uVar1 = 2;
        goto LAB_00123b6e;
      }
    }
    uVar1 = (uint)local_98.sa_family;
  }
LAB_00123b6e:
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: set_sock_tos @ 0x23c40

undefined8 set_sock_tos(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 local_1c;
  
  local_1c = param_2;
  uVar2 = FUN_00123b10();
  iVar1 = (int)uVar2;
  if (iVar1 == 2) {
    FUN_001203a0("misc.c","set_sock_tos",0x116,1,7,0,"set socket %d IP_TOS 0x%02x",param_1,local_1c)
    ;
    iVar1 = setsockopt(param_1,0,1,&local_1c,4);
    if (iVar1 == -1) {
      piVar3 = __errno_location();
      pcVar4 = strerror(*piVar3);
      uVar2 = 0x119;
      pcVar5 = "setsockopt socket %d IP_TOS %d: %s:";
LAB_00123e64:
      FUN_001203a0("misc.c","set_sock_tos",uVar2,0,2,0,pcVar5,param_1,local_1c,pcVar4);
      return 0;
    }
  }
  else if (iVar1 == 10) {
    FUN_001203a0("misc.c","set_sock_tos",0x120,1,7,0,"set socket %d IPV6_TCLASS 0x%02x",param_1,
                 local_1c);
    iVar1 = setsockopt(param_1,0x29,0x43,&local_1c,4);
    if (iVar1 == -1) {
      piVar3 = __errno_location();
      pcVar4 = strerror(*piVar3);
      uVar2 = 0x123;
      pcVar5 = "setsockopt socket %d IPV6_TCLASS %d: %.100s:";
      goto LAB_00123e64;
    }
  }
  else if (iVar1 != -1) {
    FUN_001203a0("misc.c","set_sock_tos",0x129,1,6,0,"unsupported socket family %d",uVar2);
  }
  return 0;
}



// Function: strdelim @ 0x23f00

void strdelim(undefined8 param_1)

{
  FUN_00122250(param_1,1);
  return;
}



// Function: strdelimw @ 0x23f10

void strdelimw(undefined8 param_1)

{
  FUN_00122250(param_1,0);
  return;
}



// Function: pwcopy @ 0x23f20

undefined8 * pwcopy(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined *puVar3;
  
  puVar1 = (undefined8 *)FUN_00121540(1,0x30);
  uVar2 = FUN_00121840(*param_1);
  *puVar1 = uVar2;
  puVar3 = (undefined *)param_1[1];
  if (puVar3 == (undefined *)0x0) {
    puVar3 = &DAT_00140090;
  }
  uVar2 = FUN_00121840(puVar3);
  puVar1[1] = uVar2;
  uVar2 = FUN_00121840(param_1[3]);
  puVar1[3] = uVar2;
  *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)((long)puVar1 + 0x14) = *(undefined4 *)((long)param_1 + 0x14);
  uVar2 = FUN_00121840(param_1[4]);
  puVar1[4] = uVar2;
  uVar2 = FUN_00121840(param_1[5]);
  puVar1[5] = uVar2;
  return puVar1;
}



// Function: a2port @ 0x24030

ulong a2port(char *param_1)

{
  ushort uVar1;
  ulong uVar2;
  servent *psVar3;
  long in_FS_OFFSET;
  long local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = FUN_0013bfe0(param_1,0,0xffff,&local_18);
  if (local_18 != 0) {
    psVar3 = getservbyname(param_1,"tcp");
    if (psVar3 == (servent *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar1 = FUN_00122580((short)psVar3->s_port);
      uVar2 = (ulong)uVar1;
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: a2tun @ 0x24130

undefined4 a2tun(char *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *__s;
  char *pcVar3;
  long in_FS_OFFSET;
  long local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_38 = 0;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x7fffffff;
    iVar1 = strcasecmp(param_1,"any");
    if ((iVar1 == 0) || (uVar2 = FUN_0013bfe0(param_1,0,0x7ffffffd,&local_38), local_38 == 0))
    goto LAB_001241ba;
  }
  else {
    *param_2 = 0x7fffffff;
    __s = (char *)FUN_00121840();
    pcVar3 = strchr(__s,0x3a);
    if (pcVar3 == (char *)0x0) {
      free(__s);
      uVar2 = a2tun(param_1,0);
      goto LAB_001241ba;
    }
    *pcVar3 = '\0';
    iVar1 = a2tun(pcVar3 + 1,0);
    *param_2 = iVar1;
    uVar2 = a2tun(__s,0);
    free(__s);
    if (*param_2 != 0x7ffffffe) goto LAB_001241ba;
  }
  uVar2 = 0x7ffffffe;
LAB_001241ba:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



// Function: convtime @ 0x242d0

long convtime(char *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long in_FS_OFFSET;
  char *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  piVar4 = __errno_location();
  *piVar4 = 0;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
switchD_0012437d_caseD_1:
    lVar6 = 0xffffffff;
  }
  else {
    lVar6 = 0;
    do {
      lVar5 = strtol(param_1,&local_48,10);
      if ((local_48 == param_1) ||
         (((*piVar4 == 0x22 && ((lVar5 == -0x80000000 || (lVar5 == 0x7fffffff)))) || (lVar5 < 0))))
      goto switchD_0012437d_caseD_1;
      pcVar1 = local_48 + 1;
      cVar2 = *local_48;
      if (cVar2 == '\0') {
        uVar8 = 1;
        lVar7 = 0x7fffffff;
      }
      else {
        local_48 = pcVar1;
        if (0x33 < (byte)(cVar2 + 0xbcU)) goto switchD_0012437d_caseD_1;
        uVar3 = FUN_0013da20((int)cVar2,0xffffffbc);
        switch(uVar3) {
        case 0:
        case 0x20:
          lVar7 = 0x6117;
          uVar8 = 0x15180;
          break;
        default:
          goto switchD_0012437d_caseD_1;
        case 4:
        case 0x24:
          lVar7 = 0x91a2b;
          uVar8 = 0xe10;
          break;
        case 9:
        case 0x29:
          lVar7 = 0x2222222;
          uVar8 = 0x3c;
          break;
        case 0xf:
        case 0x2f:
          lVar7 = 0x7fffffff;
          uVar8 = 1;
          break;
        case 0x13:
        case 0x33:
          lVar7 = 0xdde;
          uVar8 = 0x93a80;
        }
      }
      if (lVar7 < lVar5) goto switchD_0012437d_caseD_1;
      uVar8 = FUN_0013da80(uVar8,lVar5);
      lVar5 = FUN_0013da40(0x7fffffff,uVar8);
      if (lVar5 < lVar6) goto switchD_0012437d_caseD_1;
      lVar6 = FUN_0013da00(lVar6,uVar8);
      param_1 = local_48;
    } while (*local_48 != '\0');
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: fmt_timeframe @ 0x24500

undefined * fmt_timeframe(ulong param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  char *pcVar4;
  long lVar5;
  undefined *puVar6;
  
  lVar5 = (long)DAT_00168208;
  DAT_00168208 = FUN_0013da20(DAT_00168208,1);
  puVar6 = &DAT_001681c0 + lVar5 * 9;
  if (DAT_00168208 == 8) {
    DAT_00168208 = 0;
  }
  uVar3 = (param_1 / 0x3c) / 0x3c;
  uVar2 = uVar3 / 0x18;
  uVar3 = uVar3 % 0x18;
  uVar1 = uVar2 % 7;
  if (param_1 < 0x93a80) {
    uVar2 = (param_1 / 0x3c) % 0x3c;
    if (uVar1 == 0) {
      pcVar4 = "%02u:%02u:%02u";
      uVar1 = uVar3;
      uVar3 = uVar2;
      uVar2 = param_1 % 0x3c;
    }
    else {
      pcVar4 = "%01ud%02uh%02um";
    }
    __snprintf_chk(puVar6,9,1,0xffffffffffffffff,pcVar4,uVar1,uVar3,uVar2);
    return puVar6;
  }
  __snprintf_chk(puVar6,9,1,0xffffffffffffffff,"%02lluw%01ud%02uh",uVar2 / 7,uVar1,uVar3);
  return puVar6;
}



// Function: put_host_port @ 0x24790

undefined8 put_host_port(undefined8 param_1,short param_2)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  char *pcVar4;
  long in_FS_OFFSET;
  undefined8 local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_2 == 0) || (param_2 == 0x16)) {
    if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
      uVar2 = FUN_00121840(param_1);
      return uVar2;
    }
  }
  else {
    iVar1 = __asprintf_chk(&local_18,1,"[%s]:%d",param_1,param_2);
    if (iVar1 == -1) {
      piVar3 = __errno_location();
      pcVar4 = strerror(*piVar3);
                    /* WARNING: Subroutine does not return */
      FUN_0011ee30("misc.c","put_host_port",0x2a0,0,1,0,"put_host_port: asprintf: %s",pcVar4);
    }
    FUN_001203a0("misc.c","put_host_port",0x2a1,0,7,0,"put_host_port: %s");
    if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
      return local_18;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: hpdelim2 @ 0x24910

char * hpdelim2(undefined8 *param_1,char *param_2)

{
  char cVar1;
  char *__s;
  char *pcVar2;
  size_t sVar3;
  
  if ((param_1 != (undefined8 *)0x0) && (__s = (char *)*param_1, __s != (char *)0x0)) {
    if (*__s == '[') {
      pcVar2 = strchr(__s,0x5d);
      if (pcVar2 == (char *)0x0) {
        return (char *)0x0;
      }
      cVar1 = pcVar2[1];
      pcVar2 = pcVar2 + 1;
    }
    else {
      pcVar2 = strpbrk(__s,":/");
      if (pcVar2 == (char *)0x0) {
        sVar3 = strlen(__s);
        pcVar2 = __s + sVar3;
      }
      cVar1 = *pcVar2;
    }
    if ((cVar1 == '/') || (cVar1 == ':')) {
      if (param_2 != (char *)0x0) {
        *param_2 = cVar1;
      }
      *pcVar2 = '\0';
      *param_1 = pcVar2 + 1;
      return __s;
    }
    if (cVar1 == '\0') {
      *param_1 = 0;
      return __s;
    }
  }
  return (char *)0x0;
}



// Function: hpdelim @ 0x24b60

undefined8 hpdelim(undefined8 param_1)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  char local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_11 = '\0';
  uVar1 = FUN_00124910(param_1,&local_11);
  if (local_11 == '/') {
    uVar1 = 0;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: cleanhostname @ 0x24c30

char * cleanhostname(char *param_1)

{
  size_t sVar1;
  
  if (*param_1 == '[') {
    sVar1 = strlen(param_1);
    if (param_1[sVar1 - 1] == ']') {
      param_1[sVar1 - 1] = '\0';
      return param_1 + 1;
    }
  }
  return param_1;
}



// Function: colon @ 0x24d70

char * colon(char *param_1)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = *param_1;
  if (cVar1 == ':') {
    return (char *)0x0;
  }
  bVar2 = cVar1 == '[';
joined_r0x00124d84:
  if (cVar1 == '\0') {
    return (char *)0x0;
  }
  do {
    if (cVar1 == '@') {
      if (param_1[1] == '[') break;
    }
    else if (cVar1 == ']') {
      if ((param_1[1] == ':') && (bVar2)) {
        return param_1 + 1;
      }
    }
    else if (cVar1 == ':') {
      if (!bVar2) {
        return param_1;
      }
    }
    else if (cVar1 == '/') {
      return (char *)0x0;
    }
    cVar1 = param_1[1];
    param_1 = param_1 + 1;
    if (cVar1 == '\0') {
      return (char *)0x0;
    }
  } while( true );
  cVar1 = param_1[2];
  bVar2 = true;
  param_1 = param_1 + 2;
  goto joined_r0x00124d84;
}



// Function: parse_user_host_path @ 0x25000

undefined8
parse_user_host_path(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  char *__s;
  undefined1 *puVar1;
  void *__ptr;
  char *pcVar2;
  undefined8 uVar3;
  void *__ptr_00;
  void *__ptr_01;
  undefined1 *puVar4;
  
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  __s = (char *)FUN_00121840();
  puVar1 = (undefined1 *)FUN_00124d70(__s);
  if (puVar1 == (undefined1 *)0x0) {
    __ptr = (void *)0x0;
    __ptr_00 = (void *)0x0;
    uVar3 = 0xffffffff;
    __ptr_01 = (void *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar4 = &DAT_0013f942;
    if (puVar1[1] != '\0') {
      puVar4 = puVar1 + 1;
    }
    __ptr = (void *)FUN_00121840(puVar4);
    pcVar2 = strrchr(__s,0x40);
    if (pcVar2 == (char *)0x0) {
      uVar3 = FUN_00124c30(__s);
      __ptr_00 = (void *)FUN_00121840(uVar3);
      __ptr_01 = (void *)0x0;
    }
    else {
      *pcVar2 = '\0';
      __ptr_01 = (void *)0x0;
      uVar3 = FUN_00124c30(pcVar2 + 1);
      __ptr_00 = (void *)FUN_00121840(uVar3);
      if (*__s != '\0') {
        __ptr_01 = (void *)FUN_00121840(__s);
      }
    }
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = __ptr_01;
      __ptr_01 = (void *)0x0;
    }
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = __ptr_00;
      __ptr_00 = (void *)0x0;
    }
    uVar3 = 0;
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = __ptr;
      __ptr = (void *)0x0;
    }
  }
  free(__s);
  free(__ptr_01);
  free(__ptr_00);
  free(__ptr);
  return uVar3;
}



// Function: parse_user_host_port @ 0x251f0

undefined4 parse_user_host_port(char *param_1,undefined8 *param_2,undefined8 *param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *__s;
  char *pcVar3;
  char *__ptr;
  undefined8 uVar4;
  void *__ptr_00;
  long in_FS_OFFSET;
  char *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = -1;
  }
  __s = strdup(param_1);
  local_48 = __s;
  if (__s == (char *)0x0) {
    uVar1 = 0xffffffff;
    goto LAB_001252ab;
  }
  pcVar3 = strrchr(__s,0x40);
  if (pcVar3 == (char *)0x0) {
    __ptr = (char *)0x0;
LAB_0012536a:
    pcVar3 = (char *)FUN_00124b60(&local_48);
    if (pcVar3 == (char *)0x0) {
      uVar1 = 0xffffffff;
      __ptr_00 = (void *)0x0;
    }
    else if (*pcVar3 == '\0') {
      uVar1 = 0xffffffff;
      __ptr_00 = (void *)0x0;
    }
    else {
      uVar4 = FUN_00124c30(pcVar3);
      __ptr_00 = (void *)FUN_00121840(uVar4);
      iVar2 = -1;
      if ((local_48 != (char *)0x0) && (*local_48 != '\0')) {
        iVar2 = FUN_00124030();
        uVar1 = 0xffffffff;
        if (iVar2 < 1) goto LAB_0012528b;
      }
      if (param_2 != (undefined8 *)0x0) {
        *param_2 = __ptr;
        __ptr = (char *)0x0;
      }
      if (param_3 != (undefined8 *)0x0) {
        *param_3 = __ptr_00;
        __ptr_00 = (void *)0x0;
      }
      uVar1 = 0;
      if (param_4 != (int *)0x0) {
        *param_4 = iVar2;
      }
    }
  }
  else {
    *pcVar3 = '\0';
    if (*local_48 != '\0') {
      __ptr = strdup(local_48);
      if (__ptr != (char *)0x0) {
        local_48 = pcVar3 + 1;
        goto LAB_0012536a;
      }
    }
    uVar1 = 0xffffffff;
    __ptr_00 = (void *)0x0;
    __ptr = (char *)0x0;
  }
LAB_0012528b:
  free(__s);
  free(__ptr);
  free(__ptr_00);
LAB_001252ab:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: addargs @ 0x25430

undefined8
addargs(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
            long *param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
            undefined8 param_13,undefined8 param_14)

{
  uint uVar1;
  uint uVar2;
  char in_AL;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined8 extraout_RDX;
  uint uVar6;
  long in_FS_OFFSET;
  undefined8 local_f0;
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
  puVar5 = &local_e8;
  local_e0 = &stack0x00000008;
  local_e8 = 0x10;
  local_d8 = local_c8;
  local_e4 = 0x30;
  local_b8 = param_11;
  local_b0 = param_12;
  local_a8 = param_13;
  local_a0 = param_14;
  iVar3 = __vasprintf_chk(&local_f0,1,param_10);
  if (iVar3 == -1) {
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("misc.c","addargs",0x430,1,1,0,"argument too long",puVar5);
  }
  uVar1 = *(uint *)((long)param_9 + 0xc);
  if (*param_9 == 0) {
    *(undefined4 *)(param_9 + 1) = 0;
    uVar6 = 0x20;
  }
  else {
    uVar2 = *(uint *)(param_9 + 1);
    if (0x40000 < uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_0011ee30("misc.c","addargs",0x437,1,1,0,"too many arguments",extraout_RDX);
    }
    if (uVar1 <= uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_0011ee30("misc.c","addargs",0x439,1,1,0,"arglist corrupt",uVar2);
    }
    uVar6 = uVar1;
    if (uVar1 <= uVar2 + 2) {
      uVar6 = uVar1 * 2;
    }
  }
  lVar4 = FUN_00121760(*param_9,uVar1,uVar6,8);
  uVar1 = *(uint *)(param_9 + 1);
  *(uint *)((long)param_9 + 0xc) = uVar6;
  *param_9 = lVar4;
  *(uint *)(param_9 + 1) = uVar1 + 1;
  *(undefined8 *)(lVar4 + (ulong)uVar1 * 8) = local_f0;
  *(undefined8 *)(*param_9 + (ulong)*(uint *)(param_9 + 1) * 8) = 0;
  if (local_d0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: replacearg @ 0x256b0

undefined8
replacearg(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
            long *param_9,uint param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,
            undefined8 param_14)

{
  uint uVar1;
  long lVar2;
  char in_AL;
  int iVar3;
  undefined4 *puVar4;
  ulong uVar5;
  undefined8 uVar6;
  long in_FS_OFFSET;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 *local_e0;
  undefined1 *local_d8;
  long local_d0;
  undefined1 local_c8 [24];
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
  
  uVar5 = (ulong)param_10;
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
  puVar4 = &local_e8;
  uVar6 = 1;
  local_e0 = &stack0x00000008;
  local_e8 = 0x18;
  local_d8 = local_c8;
  local_e4 = 0x30;
  local_b0 = param_12;
  local_a8 = param_13;
  local_a0 = param_14;
  iVar3 = __vasprintf_chk(&local_f0);
  if (iVar3 == -1) {
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("misc.c","replacearg",0x44f,1,1,0,"argument too long",uVar6);
  }
  lVar2 = *param_9;
  if (lVar2 != 0) {
    uVar1 = *(uint *)(param_9 + 1);
    if (uVar1 < *(uint *)((long)param_9 + 0xc)) {
      if (uVar1 <= param_10) {
                    /* WARNING: Subroutine does not return */
        FUN_0011ee30("misc.c","replacearg",0x454,1,1,0,"tried to replace invalid arg %d >= %d",uVar5
                     ,uVar1,lVar2);
      }
      free(*(void **)(lVar2 + uVar5 * 8));
      *(undefined8 *)(*param_9 + uVar5 * 8) = local_f0;
      if (local_d0 == *(long *)(in_FS_OFFSET + 0x28)) {
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("misc.c","replacearg",0x451,1,1,0,"arglist corrupt",puVar4);
}



// Function: freeargs @ 0x258d0

undefined8 freeargs(long *param_1)

{
  uint uVar1;
  ulong uVar2;
  void *__ptr;
  
  if (param_1 != (long *)0x0) {
    __ptr = (void *)*param_1;
    if ((__ptr != (void *)0x0) && (*(uint *)(param_1 + 1) < *(uint *)((long)param_1 + 0xc))) {
      if (*(uint *)(param_1 + 1) != 0) {
        uVar2 = 0;
        do {
          uVar1 = (int)uVar2 + 1;
          free(*(void **)((long)__ptr + uVar2 * 8));
          __ptr = (void *)*param_1;
          uVar2 = (ulong)uVar1;
        } while (uVar1 < *(uint *)(param_1 + 1));
      }
      free(__ptr);
    }
    *param_1 = 0;
    param_1[1] = 0;
    return 0;
  }
  return 0;
}



// Function: tilde_expand @ 0x25a30

undefined8 tilde_expand(char *param_1,__uid_t param_2,undefined8 *param_3)

{
  char *__s;
  void *pvVar1;
  int iVar2;
  undefined8 uVar3;
  char *__s_00;
  char *pcVar4;
  size_t sVar5;
  passwd *ppVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  long in_FS_OFFSET;
  void *local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  *param_3 = 0;
  local_38 = (void *)0x0;
  if (*param_1 != '~') {
    uVar3 = FUN_00121840();
    uVar8 = 0;
    *param_3 = uVar3;
    goto LAB_00125a74;
  }
  __s_00 = (char *)FUN_00121840(param_1 + 1);
  if (*__s_00 == '\0') {
    pcVar4 = (char *)0x0;
LAB_00125c32:
    ppVar6 = getpwuid(param_2);
    if (ppVar6 == (passwd *)0x0) {
      uVar3 = 0x498;
      pcVar4 = "No such uid %ld";
      goto LAB_00125caf;
    }
LAB_00125b84:
    __s = ppVar6->pw_dir;
    sVar5 = strlen(__s);
    if (sVar5 == 0) {
      puVar7 = &DAT_001403a9;
      if (pcVar4 == (char *)0x0) {
        pcVar4 = "";
        goto LAB_00125c23;
      }
    }
    else {
      puVar7 = &DAT_0013f156;
      if (pcVar4 == (char *)0x0) {
        pcVar4 = "";
      }
      if (__s[sVar5 - 1] != '/') {
LAB_00125c23:
        puVar7 = &DAT_001403a9;
      }
    }
    iVar2 = FUN_00121960(&local_38,"%s%s%s",__s,puVar7,pcVar4);
    pvVar1 = local_38;
    if (iVar2 < 1) {
      pcVar4 = "xasprintf failed";
      uVar3 = 0x4a1;
      goto LAB_00125caf;
    }
    if (0xfff < iVar2) {
      pcVar4 = "Path too long";
      uVar3 = 0x4a5;
      goto LAB_00125caf;
    }
    local_38 = (void *)0x0;
    uVar8 = 0;
    *param_3 = pvVar1;
  }
  else {
    if (*__s_00 == '/') {
      sVar5 = strspn(__s_00,"/");
      pcVar4 = __s_00 + sVar5;
      if (__s_00[sVar5] == '\0') {
        pcVar4 = (char *)0x0;
      }
      goto LAB_00125c32;
    }
    pcVar4 = strchr(__s_00,0x2f);
    if (pcVar4 == (char *)0x0) {
LAB_00125c00:
      pcVar4 = (char *)0x0;
    }
    else {
      *pcVar4 = '\0';
      sVar5 = strspn(pcVar4 + 1,"/");
      pcVar4 = pcVar4 + 1 + sVar5;
      if (*pcVar4 == '\0') goto LAB_00125c00;
    }
    ppVar6 = getpwnam(__s_00);
    if (ppVar6 != (passwd *)0x0) goto LAB_00125b84;
    uVar3 = 0x494;
    pcVar4 = "No such user %s";
LAB_00125caf:
    uVar8 = 0xffffffff;
    FUN_001203a0("misc.c","tilde_expand",uVar3,1,2,0,pcVar4);
  }
  free(local_38);
  free(__s_00);
LAB_00125a74:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



// Function: tilde_expand_filename @ 0x25d30

undefined8 tilde_expand_filename(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined8 local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = FUN_00125a30(param_1,param_2,&local_18);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00131220(0xff);
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_18;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: dollar_expand @ 0x25e00

undefined8
dollar_expand(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
            undefined4 *param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
            undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  long in_FS_OFFSET;
  undefined4 local_dc;
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
  local_c8 = local_b8;
  local_d8 = 0x10;
  local_d4 = 0x30;
  local_a8 = param_11;
  local_a0 = param_12;
  local_98 = param_13;
  local_90 = param_14;
  FUN_001227d0(&local_dc,1,0,param_10,&local_d8);
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = local_dc;
  }
  if (local_c0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: percent_expand @ 0x25f60

/* WARNING: Type propagation algorithm not settling */

undefined8
percent_expand(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
            undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
            undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  undefined8 uVar1;
  long in_FS_OFFSET;
  int local_dc [3];
  undefined1 *local_d0;
  undefined1 *local_c8;
  long local_c0;
  undefined1 local_b8 [8];
  undefined8 local_b0;
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
  local_c8 = local_b8;
  local_dc[1] = 8;
  local_dc[2] = 0x30;
  local_b0 = param_10;
  local_a8 = param_11;
  local_a0 = param_12;
  local_98 = param_13;
  local_90 = param_14;
  uVar1 = FUN_001227d0(local_dc,0,1,param_9,local_dc + 1);
  if (local_dc[0] == 0) {
    if (local_c0 == *(long *)(in_FS_OFFSET + 0x28)) {
      return 0;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("misc.c","percent_expand",0x555,1,1,0,"failed",uVar1);
}



// Function: percent_dollar_expand @ 0x260f0

/* WARNING: Type propagation algorithm not settling */

undefined8
percent_dollar_expand(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
            undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
            undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  undefined8 uVar1;
  long in_FS_OFFSET;
  int local_dc [3];
  undefined1 *local_d0;
  undefined1 *local_c8;
  long local_c0;
  undefined1 local_b8 [8];
  undefined8 local_b0;
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
  local_dc[1] = 8;
  local_c8 = local_b8;
  local_dc[2] = 0x30;
  local_b0 = param_10;
  local_a8 = param_11;
  local_a0 = param_12;
  local_98 = param_13;
  local_90 = param_14;
  uVar1 = FUN_001227d0(local_dc,1,1,param_9,local_dc + 1);
  if (local_dc[0] == 0) {
    if (local_c0 == *(long *)(in_FS_OFFSET + 0x28)) {
      return 0;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("misc.c","percent_dollar_expand",0x568,1,1,0,"failed",uVar1);
}



// Function: sanitise_stdfd @ 0x262a0

int sanitise_stdfd(void)

{
  int iVar1;
  int __fd;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  char *pcVar5;
  
  iVar1 = open("/dev/null",2);
  if (iVar1 == -1) {
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    pcVar5 = "Couldn\'t open /dev/null: %s\n";
LAB_00126333:
    __fprintf_chk(stderr,1,pcVar5,pcVar4);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __fd = FUN_0013da20(iVar1,1);
  if (__fd < 3) {
    do {
      iVar2 = fcntl(__fd,3);
      if (((iVar2 == -1) && (piVar3 = __errno_location(), *piVar3 == 9)) &&
         (iVar2 = dup2(iVar1,__fd), iVar2 == -1)) {
        pcVar4 = strerror(*piVar3);
        pcVar5 = "dup2: %s\n";
        goto LAB_00126333;
      }
      __fd = FUN_0013da20(__fd,1);
    } while (__fd != 3);
  }
  if (2 < iVar1) {
    iVar1 = close(iVar1);
    return iVar1;
  }
  return 0;
}



// Function: tohex @ 0x26410

undefined8 tohex(undefined1 *param_1,ulong param_2)

{
  long lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  long in_FS_OFFSET;
  undefined1 local_43 [3];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 < 0x10001) {
    lVar1 = param_2 * 2 + 1;
    uVar3 = FUN_00121540(1,lVar1);
    if (param_2 != 0) {
      puVar4 = param_1 + param_2;
      do {
        uVar2 = *param_1;
        param_1 = param_1 + 1;
        __snprintf_chk(local_43,3,1,3,&DAT_0013f06a,uVar2);
        FUN_0013bcf0(uVar3,local_43,lVar1);
      } while (param_1 != puVar4);
    }
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return uVar3;
    }
  }
  else if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    uVar3 = FUN_00121840("tohex: length > 65536");
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: xextendf @ 0x26580

undefined8
xextendf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
            undefined8 *param_9,undefined1 *param_10,undefined8 param_11,undefined8 param_12,
            undefined8 param_13,undefined8 param_14)

{
  char *__ptr;
  char in_AL;
  long in_FS_OFFSET;
  void *local_f8;
  void *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 *local_e0;
  undefined1 *local_d8;
  long local_d0;
  undefined1 local_c8 [24];
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
  local_e8 = 0x18;
  local_e4 = 0x30;
  local_b0 = param_12;
  local_a8 = param_13;
  local_a0 = param_14;
  FUN_00121880(&local_f8,param_11,&local_e8);
  __ptr = (char *)*param_9;
  if ((__ptr == (char *)0x0) || (*__ptr == '\0')) {
    free(__ptr);
    local_f0 = local_f8;
  }
  else {
    if (param_10 == (undefined1 *)0x0) {
      param_10 = &DAT_0013f156;
    }
    FUN_00121960(&local_f0,"%s%s%s",__ptr,param_10,local_f8);
    free(local_f8);
    free((void *)*param_9);
  }
  *param_9 = local_f0;
  if (local_d0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: get_u64 @ 0x26740

ulong get_u64(ulong *param_1)

{
  ulong uVar1;
  
  uVar1 = *param_1;
  return uVar1 >> 0x38 | (uVar1 & 0xff000000000000) >> 0x28 | (uVar1 & 0xff0000000000) >> 0x18 |
         (uVar1 & 0xff00000000) >> 8 | (uVar1 & 0xff000000) << 8 | (uVar1 & 0xff0000) << 0x18 |
         (uVar1 & 0xff00) << 0x28 | uVar1 << 0x38;
}



// Function: get_u32 @ 0x267d0

uint get_u32(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  return uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
}



// Function: get_u32_le @ 0x26860

undefined4 get_u32_le(undefined4 *param_1)

{
  return *param_1;
}



// Function: get_u16 @ 0x268f0

ushort get_u16(ushort *param_1)

{
  return *param_1 << 8 | *param_1 >> 8;
}



// Function: put_u64 @ 0x26980

undefined8 put_u64(ulong *param_1,ulong param_2)

{
  *param_1 = param_2 >> 0x38 | (param_2 & 0xff000000000000) >> 0x28 |
             (param_2 & 0xff0000000000) >> 0x18 | (param_2 & 0xff00000000) >> 8 |
             (param_2 & 0xff000000) << 8 | (param_2 & 0xff0000) << 0x18 | (param_2 & 0xff00) << 0x28
             | param_2 << 0x38;
  return 0;
}



// Function: put_u32 @ 0x26a10

undefined8 put_u32(uint *param_1,uint param_2)

{
  *param_1 = param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 | param_2 << 0x18
  ;
  return 0;
}



// Function: put_u32_le @ 0x26aa0

undefined8 put_u32_le(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return 0;
}



// Function: put_u16 @ 0x26b30

undefined8 put_u16(ushort *param_1,ushort param_2)

{
  *param_1 = param_2 << 8 | param_2 >> 8;
  return 0;
}



// Function: ms_to_timespec @ 0x26bc0

undefined8 ms_to_timespec(long *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (-1 < (int)param_2) {
    uVar1 = param_2;
  }
  *param_1 = (long)(int)(uVar1 / 1000);
  iVar2 = FUN_0013daa0(uVar1 % 1000,1000000);
  param_1[1] = (long)iVar2;
  return 0;
}



// Function: monotime_ts @ 0x26c80

undefined8 monotime_ts(timespec *param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  long lVar4;
  long in_FS_OFFSET;
  timeval local_28;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (DAT_001681a8 == 0) {
    iVar1 = clock_gettime(7,param_1);
    if (iVar1 == 0) goto LAB_00126cbf;
    iVar1 = clock_gettime(1,param_1);
    if (iVar1 == 0) goto LAB_00126cbf;
    iVar1 = clock_gettime(0,param_1);
    if (iVar1 == 0) goto LAB_00126cbf;
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    FUN_001203a0("misc.c","monotime_ts",0x690,0,7,0,"clock_gettime: %s",pcVar3);
    DAT_001681a8 = 1;
  }
  gettimeofday(&local_28,(__timezone_ptr_t)0x0);
  param_1->tv_sec = local_28.tv_sec;
  lVar4 = FUN_0013da80(local_28.tv_usec,1000);
  param_1->tv_nsec = lVar4;
LAB_00126cbf:
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: monotime_tv @ 0x26e00

undefined8 monotime_tv(undefined8 *param_1)

{
  long in_FS_OFFSET;
  undefined8 local_28;
  long local_20;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00126c80(&local_28);
  *param_1 = local_28;
  param_1[1] = local_20 / 1000;
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ms_subtract_diff @ 0x26ef0

undefined8 ms_subtract_diff(undefined8 *param_1,int *param_2)

{
  undefined8 uVar1;
  long lVar2;
  long in_FS_OFFSET;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00126e00(&local_38);
  uVar1 = FUN_0013da40(local_38,*param_1);
  lVar2 = FUN_0013da40(local_30,param_1[1]);
  if (lVar2 < 0) {
    uVar1 = FUN_0013da00(uVar1,0xffffffffffffffff);
    lVar2 = FUN_0013da00(lVar2,1000000);
  }
  *param_2 = *param_2 - ((int)uVar1 * 1000 + (int)(lVar2 / 1000));
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: waitfd @ 0x27030

undefined8 waitfd(int param_1,int *param_2,short param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  long in_FS_OFFSET;
  pollfd local_50;
  undefined1 local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_50.fd = param_1;
  local_50.events = param_3;
  piVar3 = __errno_location();
  do {
    if (*param_2 < 0) break;
    FUN_00126e00(local_48);
    iVar2 = poll(&local_50,1,*param_2);
    iVar1 = *piVar3;
    FUN_00126ef0(local_48,param_2);
    *piVar3 = iVar1;
    if (0 < iVar2) {
      uVar4 = 0;
      goto LAB_001270da;
    }
    if ((iVar1 != 0xb && iVar1 != 4) && (iVar2 == -1)) {
      uVar4 = 0xffffffff;
      goto LAB_001270da;
    }
  } while (iVar2 != 0);
  *piVar3 = 0x6e;
  uVar4 = 0xffffffff;
LAB_001270da:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: waitrfd @ 0x271a0

void waitrfd(undefined8 param_1,undefined8 param_2)

{
  FUN_00127030(param_1,param_2,1);
  return;
}



// Function: timeout_connect @ 0x271b0

int timeout_connect(int param_1,sockaddr *param_2,socklen_t param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  long in_FS_OFFSET;
  int local_38 [2];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_38[0] = 0;
  local_38[1] = 4;
  if ((param_4 == (int *)0x0) || (*param_4 < 1)) {
    iVar1 = connect(param_1,param_2,param_3);
    goto LAB_0012727d;
  }
  FUN_00123290();
  do {
    iVar1 = connect(param_1,param_2,param_3);
    if (iVar1 == 0) goto LAB_00127273;
    piVar2 = __errno_location();
  } while (*piVar2 == 4);
  if (*piVar2 == 0x73) {
    iVar1 = FUN_00127030(param_1,param_4,5);
    if (iVar1 != -1) {
      iVar1 = getsockopt(param_1,1,4,local_38,(socklen_t *)(local_38 + 1));
      if (iVar1 == -1) {
        pcVar3 = strerror(*piVar2);
        FUN_001203a0("misc.c","timeout_connect",0x17d,0,5,0,"getsockopt: %s",pcVar3);
        iVar1 = -1;
        goto LAB_0012727d;
      }
      if (local_38[0] == 0) {
LAB_00127273:
        iVar1 = 0;
        FUN_001234f0(param_1);
        goto LAB_0012727d;
      }
      *piVar2 = local_38[0];
    }
  }
  iVar1 = -1;
LAB_0012727d:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: monotime @ 0x27390

undefined8 monotime(void)

{
  long in_FS_OFFSET;
  undefined8 local_28 [3];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00126c80(local_28);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_28[0];
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: monotime_double @ 0x27450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 monotime_double(void)

{
  long in_FS_OFFSET;
  undefined1 local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00126c80(local_28);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: bandwidth_limit_init @ 0x27530

undefined8 bandwidth_limit_init(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_3;
  param_1[1] = param_2;
  param_1[2] = param_3;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  return 0;
}



// Function: bandwidth_limit @ 0x275f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 bandwidth_limit(ulong *param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  int *piVar6;
  undefined8 uVar7;
  long in_FS_OFFSET;
  double dVar8;
  timespec local_58;
  timespec local_48;
  long local_30;
  
  uVar3 = param_1[3];
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  param_1[3] = param_2 + uVar3;
  if ((param_1[4] == 0) && (param_1[5] == 0)) {
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      uVar7 = FUN_00126e00(param_1 + 4);
      return uVar7;
    }
    goto LAB_00127994;
  }
  if (param_1[2] <= param_2 + uVar3) {
    FUN_00126e00(param_1 + 6);
    uVar3 = FUN_0013da40(param_1[6],param_1[4]);
    param_1[6] = uVar3;
    uVar4 = FUN_0013da40(param_1[7],param_1[5]);
    param_1[7] = uVar4;
    if ((long)uVar4 < 0) {
      uVar3 = FUN_0013da00(uVar3,0xffffffffffffffff);
      param_1[6] = uVar3;
      uVar4 = FUN_0013da00(uVar4,1000000);
      param_1[7] = uVar4;
    }
    if ((uVar3 != 0) || (param_1[7] != 0)) {
      uVar4 = param_1[3];
      uVar5 = uVar4 << 3;
      param_1[3] = uVar5;
      if ((long)uVar5 < 0) {
        dVar8 = (double)((uVar4 & 0x1fffffffffffffff) << 2);
        dVar8 = dVar8 + dVar8;
      }
      else {
        dVar8 = (double)(long)uVar5;
      }
      dVar8 = (dVar8 * _DAT_00140cb8) / (double)param_1[1];
      if (_DAT_00140cc0 <= dVar8) {
        uVar4 = (long)(dVar8 - _DAT_00140cc0) ^ 0x8000000000000000;
      }
      else {
        uVar4 = (ulong)dVar8;
      }
      uVar5 = uVar4 / 1000000;
      param_1[4] = uVar5;
      uVar4 = uVar4 % 1000000;
      param_1[5] = uVar4;
      if (uVar5 == uVar3) {
        if ((long)param_1[7] < (long)uVar4) {
          param_1[6] = 0;
          uVar3 = FUN_0013da40(uVar4);
          param_1[7] = uVar3;
LAB_0012792c:
          uVar5 = 0;
          if ((long)uVar3 < 10000) {
            uVar4 = *param_1 << 3;
            if (param_1[2] * 2 < *param_1 << 3) {
              uVar4 = param_1[2] * 2;
            }
            param_1[2] = uVar4;
          }
          goto LAB_00127823;
        }
      }
      else if ((long)uVar3 < (long)uVar5) {
        uVar1 = param_1[7];
        uVar5 = FUN_0013da40(uVar5,uVar3);
        param_1[6] = uVar5;
        uVar3 = FUN_0013da40(uVar4,uVar1);
        param_1[7] = uVar3;
        if ((long)uVar3 < 0) {
          uVar5 = FUN_0013da00(uVar5,0xffffffffffffffff);
          param_1[6] = uVar5;
          uVar3 = FUN_0013da00(uVar3,1000000);
          param_1[7] = uVar3;
          if (uVar5 == 0) goto LAB_0012792c;
        }
        uVar4 = *param_1 >> 2;
        if (*param_1 >> 2 < param_1[2] >> 1) {
          uVar4 = param_1[2] >> 1;
        }
        param_1[2] = uVar4;
LAB_00127823:
        local_58.tv_sec = uVar5;
        local_58.tv_nsec = FUN_0013da80(uVar3,1000);
        while ((iVar2 = nanosleep(&local_58,&local_48), iVar2 == -1 &&
               (piVar6 = __errno_location(), *piVar6 == 4))) {
          local_58.tv_sec = local_48.tv_sec;
          local_58.tv_nsec = local_48.tv_nsec;
        }
      }
      param_1[3] = 0;
      FUN_00126e00(param_1 + 4);
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
LAB_00127994:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: mktemp_proto @ 0x279a0

undefined8 mktemp_proto(char *param_1,ulong param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  ulong uVar4;
  
  pcVar3 = getenv("TMPDIR");
  if (((pcVar3 != (char *)0x0) &&
      (iVar1 = __snprintf_chk(param_1,param_2,1,0xffffffffffffffff,"%s/ssh-XXXXXXXXXXXX",pcVar3),
      0 < iVar1)) && ((ulong)(long)iVar1 < param_2)) {
    return 0;
  }
  uVar2 = snprintf(param_1,param_2,"/tmp/ssh-XXXXXXXXXXXX");
  uVar4 = (ulong)uVar2;
  if ((-1 < (int)uVar2) && (uVar4 = (ulong)(int)uVar2, uVar4 < param_2)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("misc.c","mktemp_proto",0x702,1,1,0,"template string too short",uVar4);
}



// Function: parse_ipqos @ 0x27ad0

ulong parse_ipqos(char *param_1)

{
  int iVar1;
  ulong uVar2;
  undefined **ppuVar3;
  char *__s2;
  long in_FS_OFFSET;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 != (char *)0x0) {
    ppuVar3 = &PTR_DAT_001671d0;
    uVar2 = 0;
    __s2 = "none";
    do {
      iVar1 = strcasecmp(param_1,__s2);
      if (iVar1 == 0) {
        uVar2 = (ulong)(uint)(&DAT_001671c8)[uVar2 * 4];
        goto LAB_00127b3e;
      }
      __s2 = *ppuVar3;
      ppuVar3 = ppuVar3 + 2;
      uVar2 = (ulong)((int)uVar2 + 1);
    } while (__s2 != (char *)0x0);
    uVar2 = strtol(param_1,&local_28,0);
    if (((*param_1 != '\0') && (*local_28 == '\0')) && (uVar2 < 0x100)) goto LAB_00127b3e;
  }
  uVar2 = 0xffffffff;
LAB_00127b3e:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: iptos2str @ 0x27c20

char * iptos2str(int param_1)

{
  char *pcVar1;
  int iVar2;
  undefined **ppuVar3;
  
  iVar2 = 0x7fffffff;
  pcVar1 = "none";
  ppuVar3 = &PTR_DAT_001671d0;
  while( true ) {
    if (param_1 == iVar2) {
      return pcVar1;
    }
    pcVar1 = *ppuVar3;
    if (pcVar1 == (char *)0x0) break;
    iVar2 = *(int *)(ppuVar3 + 1);
    ppuVar3 = ppuVar3 + 2;
  }
  __snprintf_chk(&DAT_001681a0,5,1,5,"0x%02x");
  return &DAT_001681a0;
}



// Function: lowercase @ 0x27d90

undefined8 lowercase(byte *param_1)

{
  byte bVar1;
  __int32_t **pp_Var2;
  
  bVar1 = *param_1;
  if (bVar1 != 0) {
    pp_Var2 = __ctype_tolower_loc();
    do {
      *param_1 = (byte)(*pp_Var2)[bVar1];
      bVar1 = param_1[1];
      param_1 = param_1 + 1;
    } while (bVar1 != 0);
  }
  return 0;
}



// Function: unix_listener @ 0x27e50

int unix_listener(char *param_1,int param_2,int param_3)

{
  int __fd;
  int iVar1;
  ulong uVar2;
  int *piVar3;
  char *pcVar4;
  long lVar5;
  sockaddr *psVar6;
  long in_FS_OFFSET;
  sockaddr local_a8 [7];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  psVar6 = local_a8;
  for (lVar5 = 0xd; lVar5 != 0; lVar5 = lVar5 + -1) {
    *(undefined8 *)psVar6 = 0;
    psVar6 = (sockaddr *)((long)psVar6 + 8);
  }
  local_a8[0].sa_family = 1;
  *(undefined4 *)psVar6 = 0;
  *(undefined2 *)((long)psVar6 + 4) = 0;
  uVar2 = FUN_0013bee0(local_a8[0].sa_data,param_1,0x6c);
  if (uVar2 < 0x6c) {
    __fd = socket(1,1,0);
    if (__fd == -1) {
      piVar3 = __errno_location();
      iVar1 = *piVar3;
      pcVar4 = strerror(iVar1);
      FUN_001203a0("misc.c","unix_listener",0x761,1,2,0,"socket: %.100s",pcVar4);
      *piVar3 = iVar1;
    }
    else {
      if (param_3 == 1) {
        iVar1 = unlink(param_1);
        if (iVar1 != 0) {
          piVar3 = __errno_location();
          if (*piVar3 != 2) {
            pcVar4 = strerror(*piVar3);
            FUN_001203a0("misc.c","unix_listener",0x767,0,2,0,"unlink(%s): %.100s",param_1,pcVar4);
          }
        }
      }
      iVar1 = bind(__fd,local_a8,0x6e);
      if (iVar1 == -1) {
        piVar3 = __errno_location();
        iVar1 = *piVar3;
        pcVar4 = strerror(iVar1);
        FUN_001203a0("misc.c","unix_listener",0x76b,1,2,0,"cannot bind to path %s: %s",param_1,
                     pcVar4);
        close(__fd);
        *piVar3 = iVar1;
        __fd = -1;
      }
      else {
        iVar1 = listen(__fd,param_2);
        if (iVar1 == -1) {
          piVar3 = __errno_location();
          iVar1 = *piVar3;
          pcVar4 = strerror(iVar1);
          FUN_001203a0("misc.c","unix_listener",0x772,1,2,0,"cannot listen on path %s: %s",param_1,
                       pcVar4);
          close(__fd);
          unlink(param_1);
          *piVar3 = iVar1;
          __fd = -1;
        }
      }
    }
  }
  else {
    __fd = -1;
    FUN_001203a0("misc.c","unix_listener",0x759,1,2,0,"path \"%s\" too long for Unix domain socket",
                 param_1);
    piVar3 = __errno_location();
    *piVar3 = 0x24;
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return __fd;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sock_set_v6only @ 0x28180

undefined8 sock_set_v6only(undefined8 param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  long in_FS_OFFSET;
  undefined4 local_24;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_24 = 1;
  FUN_001203a0("misc.c","sock_set_v6only",0x781,0,7,0,"%s: set socket %d IPV6_V6ONLY",
               "sock_set_v6only",param_1);
  iVar1 = setsockopt((int)param_1,0x29,0x1a,&local_24,4);
  if (iVar1 == -1) {
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    FUN_001203a0("misc.c","sock_set_v6only",0x783,0,2,0,"setsockopt IPV6_V6ONLY: %s",pcVar3);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: forward_equals @ 0x282f0

ulong forward_equals(undefined8 *param_1,undefined8 *param_2)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_00122ec0(*param_1,*param_2);
  if ((int)uVar2 != 0) {
    uVar2 = 0;
    if (*(int *)(param_1 + 1) == *(int *)(param_2 + 1)) {
      uVar2 = FUN_00122ec0(param_1[2],param_2[2]);
      if ((int)uVar2 != 0) {
        uVar2 = FUN_00122ec0(param_1[3],param_2[3]);
        if ((int)uVar2 != 0) {
          uVar2 = 0;
          if (*(int *)(param_1 + 4) == *(int *)(param_2 + 4)) {
            iVar1 = FUN_00122ec0(param_1[5],param_2[5]);
            uVar2 = (ulong)(iVar1 != 0);
          }
        }
      }
    }
  }
  return uVar2;
}



// Function: daemonized @ 0x283e0

undefined4 daemonized(void)

{
  int __fd;
  __pid_t _Var1;
  __pid_t _Var2;
  
  __fd = open("/dev/tty",0x100);
  if (-1 < __fd) {
    close(__fd);
    return 0;
  }
  _Var1 = getppid();
  if (_Var1 == 1) {
    _Var1 = getsid(0);
    _Var2 = getpid();
    if (_Var1 == _Var2) {
      FUN_001203a0("misc.c","daemonized",0x7ba,0,7,0,"already daemonized");
      return 1;
    }
  }
  return 0;
}



// Function: argv_split @ 0x28590

undefined8 argv_split(char *param_1,uint *param_2,undefined8 *param_3,int param_4)

{
  void *__ptr;
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  size_t sVar5;
  long lVar6;
  undefined8 *puVar7;
  ulong uVar8;
  char *pcVar9;
  ulong uVar10;
  char *pcVar11;
  undefined8 *local_58;
  uint local_50;
  
  local_58 = (undefined8 *)FUN_00121540(1,8);
  *param_3 = 0;
  *param_2 = 0;
  cVar2 = *param_1;
  if (cVar2 != '\0') {
    uVar10 = 0;
    uVar8 = 0;
    pcVar9 = param_1;
LAB_001285f0:
    if ((cVar2 == ' ') || (cVar2 == '\t')) goto LAB_001288c5;
    if ((param_4 == 0) || (cVar2 != '#')) {
      iVar3 = FUN_0013da20(uVar8 & 0xffffffff,2);
      local_58 = (undefined8 *)FUN_00121680(local_58,(long)iVar3,8);
      sVar5 = strlen(pcVar9);
      local_50 = FUN_0013da20(uVar8 & 0xffffffff,1);
      lVar6 = FUN_00121540(1,sVar5 + 1);
      local_58[uVar8] = lVar6;
      local_58[uVar8 + 1] = 0;
      cVar2 = param_1[(int)uVar10];
      if (cVar2 != '\0') {
        cVar1 = '\0';
        uVar8 = 0;
        do {
          uVar4 = FUN_0013da20(uVar10 & 0xffffffff,1);
          pcVar9 = param_1 + (int)uVar4;
          if (cVar2 == '\\') {
            cVar2 = *pcVar9;
            if ((byte)(cVar2 - 0x22U) < 0x3b) {
              pcVar11 = (char *)((int)uVar8 + lVar6);
              iVar3 = FUN_0013da20(uVar8 & 0xffffffff,1);
              uVar8 = (ulong)iVar3;
              if ((0xfbffffffffffffdeU >> ((ulong)(byte)(cVar2 - 0x22U) & 0x3f) & 1) == 0)
              goto LAB_0012889e;
            }
            else {
              iVar3 = FUN_0013da20(uVar8 & 0xffffffff,1);
              pcVar11 = (char *)((int)uVar8 + lVar6);
              uVar8 = (ulong)iVar3;
              if ((cVar1 == '\0') && (cVar2 == ' ')) {
LAB_0012889e:
                *pcVar11 = cVar2;
                iVar3 = FUN_0013da20(uVar10 & 0xffffffff,2);
                uVar10 = (ulong)iVar3;
                pcVar9 = param_1 + uVar10;
                goto LAB_001286d4;
              }
            }
            *pcVar11 = '\\';
            cVar2 = *pcVar9;
            uVar10 = (ulong)uVar4;
          }
          else {
            if (cVar1 == '\0') {
              if ((cVar2 == ' ') || (cVar2 == '\t')) goto LAB_001288c0;
              if ((cVar2 == '\"') || (cVar2 == '\'')) {
                uVar10 = (ulong)uVar4;
                cVar1 = cVar2;
              }
              else {
LAB_001286ba:
                uVar10 = (ulong)uVar4;
                iVar3 = FUN_0013da20(uVar8 & 0xffffffff,1);
                *(char *)(lVar6 + uVar8) = cVar2;
                uVar8 = (ulong)iVar3;
              }
            }
            else {
              if (cVar1 != cVar2) goto LAB_001286ba;
              uVar10 = (ulong)uVar4;
              cVar1 = '\0';
            }
LAB_001286d4:
            cVar2 = *pcVar9;
          }
          if (cVar2 == '\0') {
            if (cVar1 != '\0') {
              if (local_58 == (undefined8 *)0x0) {
                return 0xfffffffc;
              }
              puVar7 = local_58;
              do {
                __ptr = (void *)*puVar7;
                puVar7 = puVar7 + 1;
                free(__ptr);
              } while (local_58 + local_50 != puVar7);
              free(local_58);
              return 0xfffffffc;
            }
            break;
          }
        } while( true );
      }
      goto LAB_001288ec;
    }
    goto LAB_001288e8;
  }
  local_50 = 0;
LAB_001288ec:
  *param_2 = local_50;
  *param_3 = local_58;
  return 0;
LAB_001288c0:
  uVar8 = (ulong)(int)local_50;
LAB_001288c5:
  iVar3 = FUN_0013da20(uVar10 & 0xffffffff,1);
  uVar10 = (ulong)iVar3;
  pcVar9 = param_1 + uVar10;
  cVar2 = *pcVar9;
  if (cVar2 == '\0') goto LAB_001288e8;
  goto LAB_001285f0;
LAB_001288e8:
  local_50 = (uint)uVar8;
  goto LAB_001288ec;
}



// Function: argv_assemble @ 0x289c0

void * argv_assemble(int param_1,long *param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  void *__dest;
  size_t __n;
  void *__src;
  undefined8 extraout_RDX;
  long *plVar10;
  int local_40;
  
  plVar10 = param_2;
  lVar6 = FUN_0010b880();
  if ((lVar6 == 0) || (lVar7 = FUN_0010b880(), lVar7 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("misc.c","argv_assemble",0x814,1,1,0,"sshbuf_new failed",plVar10);
  }
  if (0 < param_1) {
    local_40 = 0;
    do {
      FUN_0010be60(lVar7);
      bVar1 = *(byte *)*param_2;
      if (bVar1 == 0) {
        if ((local_40 != 0) && (iVar5 = FUN_0011b180(lVar6,0x20), iVar5 != 0)) goto LAB_00128ca4;
LAB_00128c90:
        iVar5 = FUN_0011aad0(lVar6,lVar7);
      }
      else {
        bVar2 = false;
        iVar5 = 0;
        do {
          if (bVar1 == 0x20) {
LAB_00128aba:
            bVar2 = true;
            iVar4 = FUN_0011b180(lVar7,(int)(char)bVar1);
          }
          else {
            if ((char)bVar1 < '!') {
              if (bVar1 == 9) goto LAB_00128aba;
            }
            else {
              uVar3 = bVar1 - 0x22;
              if ((((byte)uVar3 < 0x3b) && ((0xfbffffffffffffdeU >> ((ulong)uVar3 & 0x3f) & 1) == 0)
                  ) && (iVar4 = FUN_0011b180(lVar7,0x5c), iVar4 != 0)) goto LAB_00128a73;
            }
            iVar4 = FUN_0011b180(lVar7,(uint)bVar1);
          }
          if (iVar4 != 0) {
LAB_00128a73:
            uVar8 = FUN_0010b050(iVar4);
                    /* WARNING: Subroutine does not return */
            FUN_0011ee30("misc.c","argv_assemble",0x82d,1,1,uVar8,"sshbuf_put_u8");
          }
          iVar5 = FUN_0013da20(iVar5,1);
          bVar1 = *(byte *)(*param_2 + (long)iVar5);
        } while (bVar1 != 0);
        if ((local_40 != 0) && (iVar5 = FUN_0011b180(lVar6,0x20), iVar5 != 0)) goto LAB_00128ca4;
        if (!bVar2) goto LAB_00128c90;
        iVar5 = FUN_0011b180(lVar6,0x22);
        if ((iVar5 != 0) || (iVar5 = FUN_0011aad0(lVar6,lVar7), iVar5 != 0)) goto LAB_00128ca4;
        iVar5 = FUN_0011b180(lVar6,0x22);
      }
      if (iVar5 != 0) {
LAB_00128ca4:
        uVar8 = FUN_0010b050(iVar5);
                    /* WARNING: Subroutine does not return */
        FUN_0011ee30("misc.c","argv_assemble",0x833,1,1,uVar8,"assemble");
      }
      param_2 = param_2 + 1;
      local_40 = FUN_0013da20(local_40,1);
    } while (param_1 != local_40);
  }
  lVar9 = FUN_0010c3d0(lVar6);
  __dest = malloc(lVar9 + 1);
  if (__dest != (void *)0x0) {
    __n = FUN_0010c3d0(lVar6);
    __src = (void *)FUN_0010c520(lVar6);
    memcpy(__dest,__src,__n);
    lVar9 = FUN_0010c3d0(lVar6);
    *(undefined1 *)((long)__dest + lVar9) = 0;
    FUN_0010bce0(lVar6);
    FUN_0010bce0(lVar7);
    return __dest;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("misc.c","argv_assemble",0x836,1,1,0,"malloc failed",extraout_RDX);
}



// Function: argv_next @ 0x28d60

long argv_next(int *param_1,long *param_2)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)*param_2;
  if ((lVar1 != 0) && (0 < *param_1)) {
    iVar2 = FUN_0013da20(*param_1,0xffffffff);
    *param_1 = iVar2;
    *param_2 = *param_2 + 8;
  }
  return lVar1;
}



// Function: argv_consume @ 0x28e20

undefined8 argv_consume(undefined4 *param_1)

{
  *param_1 = 0;
  return 0;
}



// Function: argv_free @ 0x28eb0

undefined8 argv_free(undefined8 *param_1,int param_2)

{
  void *__ptr;
  undefined8 extraout_RAX;
  undefined8 *puVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    if (0 < param_2) {
      puVar1 = param_1;
      do {
        __ptr = (void *)*puVar1;
        puVar1 = puVar1 + 1;
        free(__ptr);
      } while (puVar1 != param_1 + (ulong)(param_2 - 1) + 1);
    }
    free(param_1);
    return extraout_RAX;
  }
  return 0;
}



// Function: exited_cleanly @ 0x28f70

uint exited_cleanly(__pid_t param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  __pid_t _Var1;
  int *piVar2;
  uint uVar3;
  undefined8 uVar4;
  int iVar5;
  long in_FS_OFFSET;
  char *pcVar6;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  do {
    _Var1 = waitpid(param_1,(int *)&local_44,0);
    if (_Var1 != -1) {
      if ((char)(((byte)local_44 & 0x7f) + 1) < '\x02') {
        uVar3 = local_44 >> 8 & 0xff;
        if ((char)(local_44 >> 8) == '\0') goto LAB_00128ff0;
        uVar4 = 0x86c;
        iVar5 = (-(uint)(param_4 == 0) & 0xfffffffe) + 5;
        pcVar6 = "%s %s failed, status %d";
        local_44 = uVar3;
      }
      else {
        local_44 = local_44 & 0x7f;
        iVar5 = 2;
        uVar4 = 0x869;
        pcVar6 = "%s %s exited on signal %d";
      }
      uVar3 = 0xffffffff;
      FUN_001203a0("misc.c","exited_cleanly",uVar4,0,iVar5,0,pcVar6,param_2,param_3,local_44);
      goto LAB_00128ff0;
    }
    piVar2 = __errno_location();
  } while (*piVar2 == 4);
  pcVar6 = strerror(*piVar2);
  FUN_001203a0("misc.c","exited_cleanly",0x864,0,2,0,"%s waitpid: %s",param_2,pcVar6);
  uVar3 = 0xffffffff;
LAB_00128ff0:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: safe_path @ 0x29150

undefined4
safe_path(undefined8 param_1,long param_2,long param_3,__uid_t param_4,char *param_5,
            size_t param_6)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  char *pcVar4;
  int *piVar5;
  long in_FS_OFFSET;
  bool bVar6;
  stat local_20d8;
  char local_2048 [4096];
  char local_1048 [4104];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = __realpath_chk(param_1,local_2048,0x1000);
  if (lVar3 == 0) {
    piVar5 = __errno_location();
    pcVar4 = strerror(*piVar5);
    __snprintf_chk(param_5,param_6,1,0xffffffffffffffff,"realpath %s failed: %s",param_1,pcVar4);
    uVar2 = 0xffffffff;
  }
  else {
    bVar6 = false;
    if (param_3 != 0) {
      lVar3 = __realpath_chk(param_3,local_1048,0x1000);
      bVar6 = lVar3 != 0;
    }
    if ((*(uint *)(param_2 + 0x18) & 0xf000) == 0x8000) {
      iVar1 = FUN_00131190(*(undefined4 *)(param_2 + 0x1c));
      if (((iVar1 != 0) || (*(__uid_t *)(param_2 + 0x1c) == param_4)) &&
         ((*(byte *)(param_2 + 0x18) & 0x12) == 0)) {
        do {
          pcVar4 = dirname(local_2048);
          if (pcVar4 == (char *)0x0) {
            snprintf(param_5,param_6,"dirname() failed");
            uVar2 = 0xffffffff;
            break;
          }
          FUN_0013bee0(local_2048,pcVar4,0x1000);
          iVar1 = stat(local_2048,&local_20d8);
          if (iVar1 == -1) {
LAB_001293b8:
            pcVar4 = "bad ownership or modes for directory %s";
            goto LAB_001293c2;
          }
          iVar1 = FUN_00131190(local_20d8.st_uid);
          if (((iVar1 == 0) && (local_20d8.st_uid != param_4)) ||
             (((byte)local_20d8.st_mode & 0x12) != 0)) goto LAB_001293b8;
          if (bVar6) {
            iVar1 = strcmp(local_1048,local_2048);
            uVar2 = 0;
            if (iVar1 == 0) break;
          }
          iVar1 = strcmp("/",local_2048);
          uVar2 = 0;
          if (iVar1 == 0) break;
          iVar1 = strcmp(".",local_2048);
          uVar2 = 0;
        } while (iVar1 != 0);
        goto LAB_001292f0;
      }
      pcVar4 = "bad ownership or modes for file %s";
    }
    else {
      pcVar4 = "%s is not a regular file";
    }
LAB_001293c2:
    __snprintf_chk(param_5,param_6,1,0xffffffffffffffff,pcVar4,local_2048);
    uVar2 = 0xffffffff;
  }
LAB_001292f0:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: safe_path_fd @ 0x29440

undefined4
safe_path_fd(int param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  long in_FS_OFFSET;
  stat sStack_d8;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = fstat(param_1,&sStack_d8);
  if (iVar1 == -1) {
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    __snprintf_chk(param_4,param_5,1,0xffffffffffffffff,"cannot stat file %s: %s",param_2,pcVar4);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00129150(param_2,&sStack_d8,*(undefined8 *)(param_3 + 0x20),
                         *(undefined4 *)(param_3 + 0x10),param_4,param_5);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: child_set_env @ 0x29590

undefined8 child_set_env(long *param_1,uint *param_2,char *param_3,long *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  size_t sVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  long *plVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  size_t sVar5;
  ulong uVar6;
  
  plVar11 = param_4;
  pcVar4 = strchr(param_3,0x3d);
  if (pcVar4 != (char *)0x0) {
    FUN_001203a0("misc.c","child_set_env",0x8dc,0,2,0,"Invalid environment variable \"%.100s\"",
                 param_3);
    return 0;
  }
  plVar10 = (long *)*param_1;
  if ((plVar10 == (long *)0x0) && (*param_2 == 0)) {
    puVar9 = (undefined8 *)FUN_00121440(8);
    *param_1 = (long)puVar9;
    *puVar9 = 0;
    *param_2 = 1;
    plVar10 = (long *)*param_1;
    plVar11 = param_1;
    sVar5 = strlen(param_3);
    uVar1 = (uint)sVar5;
    pcVar4 = (char *)*plVar10;
    if (pcVar4 != (char *)0x0) goto LAB_001295ee;
    lVar12 = 8;
    uVar1 = 0x33;
    lVar13 = 0;
  }
  else {
    sVar5 = strlen(param_3);
    uVar1 = (uint)sVar5;
    pcVar4 = (char *)*plVar10;
    if (pcVar4 == (char *)0x0) {
      uVar3 = 0;
      lVar13 = 0;
    }
    else {
LAB_001295ee:
      uVar6 = 0;
      lVar13 = 0;
      do {
        iVar2 = strncmp(pcVar4,param_3,(ulong)uVar1);
        if ((iVar2 == 0) && (pcVar4[uVar1] == '=')) {
          free(pcVar4);
          goto LAB_00129728;
        }
        uVar3 = (int)uVar6 + 1;
        uVar6 = (ulong)uVar3;
        pcVar4 = (char *)plVar10[uVar6];
        lVar13 = uVar6 * 8;
      } while (pcVar4 != (char *)0x0);
    }
    uVar1 = *param_2;
    if (uVar3 < uVar1 - 1) {
      lVar12 = (ulong)(uVar3 + 1) << 3;
      goto LAB_00129651;
    }
    if (999 < uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0011ee30("misc.c","child_set_env",0x8fc,0,1,0,"child_set_env: too many env vars",plVar11);
    }
    uVar1 = uVar1 + 0x32;
    lVar12 = (ulong)(uVar3 + 1) << 3;
  }
  plVar10 = (long *)FUN_00121680(plVar10,uVar1,8);
  *param_1 = (long)plVar10;
  *param_2 = uVar1;
LAB_00129651:
  *(undefined8 *)((long)plVar10 + lVar12) = 0;
LAB_00129728:
  sVar5 = strlen(param_3);
  sVar7 = strlen((char *)param_4);
  uVar8 = FUN_00121440(sVar5 + 2 + sVar7);
  *(undefined8 *)((long)plVar10 + lVar13) = uVar8;
  sVar5 = strlen(param_3);
  sVar7 = strlen((char *)param_4);
  __snprintf_chk(uVar8,sVar5 + 2 + sVar7,1,0xffffffffffffffff,"%s=%s",param_3,param_4);
  return 0;
}



// Function: valid_domain @ 0x29910

undefined8 valid_domain(byte *param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  byte bVar2;
  size_t sVar3;
  ushort **ppuVar4;
  __int32_t **pp_Var5;
  uint uVar6;
  byte *pbVar7;
  ulong uVar8;
  char *pcVar9;
  
  sVar3 = strlen((char *)param_1);
  if (sVar3 == 0) {
    FUN_0013bee0(&DAT_001680a0,"empty domain name",0x100);
  }
  else {
    ppuVar4 = __ctype_b_loc();
    uVar8 = (ulong)*param_1;
    pcVar9 = "domain name \"%.100s\" starts with invalid character";
    if (((*ppuVar4)[uVar8] & 0xc00) != 0) {
      pp_Var5 = __ctype_tolower_loc();
      pbVar7 = param_1;
      uVar6 = 0;
      while( true ) {
        uVar1 = (*pp_Var5)[uVar8];
        bVar2 = (byte)uVar1;
        if (param_2 != 0) {
          *pbVar7 = bVar2;
        }
        if (((char)uVar6 == '.') && (bVar2 == 0x2e)) break;
        if (((1 < (byte)(bVar2 - 0x2d)) && (((*ppuVar4)[uVar1 & 0xff] & 8) == 0)) && (bVar2 != 0x5f)
           ) {
          pcVar9 = "domain name \"%.100s\" contains invalid characters";
          goto LAB_00129a7a;
        }
        pbVar7 = pbVar7 + 1;
        if (param_1 + sVar3 == pbVar7) {
          if (param_1[sVar3 - 1] == 0x2e) {
            param_1[sVar3 - 1] = 0;
          }
          if (param_3 == (undefined8 *)0x0) {
            return 1;
          }
          *param_3 = 0;
          return 1;
        }
        uVar8 = (ulong)*pbVar7;
        uVar6 = uVar1;
      }
      pcVar9 = "domain name \"%.100s\" contains consecutive separators";
    }
LAB_00129a7a:
    __snprintf_chk(&DAT_001680a0,0x100,1,0x100,pcVar9,param_1);
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = &DAT_001680a0;
  }
  return 0;
}



// Function: parse_uri @ 0x29b70

undefined4
parse_uri(char *param_1,char *param_2,long *param_3,undefined8 *param_4,int *param_5,
            long *param_6)

{
  int iVar1;
  int iVar2;
  size_t __n;
  char *__s;
  char *pcVar3;
  char *pcVar4;
  void *__ptr;
  char *pcVar5;
  undefined8 uVar6;
  void *__ptr_00;
  void *__ptr_01;
  undefined4 uVar7;
  long in_FS_OFFSET;
  char local_49;
  char *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  __n = strlen(param_1);
  uVar7 = 1;
  iVar2 = strncmp(param_2,param_1,__n);
  if (iVar2 != 0) goto LAB_00129cba;
  iVar2 = strncmp(param_2 + __n,"://",3);
  if (iVar2 != 0) {
    uVar7 = 1;
    goto LAB_00129cba;
  }
  if (param_3 != (long *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = -1;
  }
  if (param_6 != (long *)0x0) {
    *param_6 = 0;
  }
  __s = (char *)FUN_00121840(param_2 + __n + 3);
  local_48 = __s;
  pcVar3 = strchr(__s,0x40);
  pcVar5 = local_48;
  __ptr = (void *)0x0;
  if (pcVar3 == (char *)0x0) {
LAB_00129d8a:
    pcVar5 = (char *)FUN_00124910(&local_48,&local_49);
    __ptr_00 = (void *)0x0;
    if (pcVar5 == (char *)0x0) {
LAB_00129ee8:
      __ptr_01 = (void *)0x0;
LAB_00129e28:
      uVar7 = 0xffffffff;
    }
    else if (*pcVar5 == '\0') {
      uVar7 = 0xffffffff;
      __ptr_01 = (void *)0x0;
      __ptr_00 = (void *)0x0;
    }
    else {
      uVar6 = FUN_00124c30(pcVar5);
      __ptr_00 = (void *)FUN_00121840(uVar6);
      iVar2 = FUN_00129910(__ptr_00,0,0);
      pcVar5 = local_48;
      if (iVar2 == 0) {
LAB_00129ef0:
        uVar7 = 0xffffffff;
        __ptr_01 = (void *)0x0;
      }
      else {
        iVar2 = -1;
        __ptr_01 = (void *)0x0;
        if (local_48 != (char *)0x0) {
          iVar1 = -1;
          if (*local_48 == '\0') {
LAB_00129e92:
            iVar2 = iVar1;
            __ptr_01 = (void *)0x0;
          }
          else {
            if (local_49 == ':') {
              pcVar3 = strchr(local_48,0x2f);
              if (pcVar3 == (char *)0x0) {
                iVar2 = FUN_00124030(pcVar5);
                if (iVar2 < 1) goto LAB_00129ee8;
                local_48 = (char *)0x0;
                __ptr_01 = (void *)0x0;
                goto LAB_00129e95;
              }
              *pcVar3 = '\0';
              iVar2 = FUN_00124030(local_48);
              if (iVar2 < 1) goto LAB_00129ef0;
              local_48 = pcVar3 + 1;
              iVar1 = iVar2;
              if (pcVar3[1] == '\0') goto LAB_00129e92;
            }
            __ptr_01 = (void *)FUN_00122610(local_48);
            if (__ptr_01 == (void *)0x0) goto LAB_00129e28;
          }
        }
LAB_00129e95:
        if (param_3 != (long *)0x0) {
          *param_3 = (long)__ptr;
          __ptr = (void *)0x0;
        }
        if (param_4 != (undefined8 *)0x0) {
          *param_4 = __ptr_00;
          __ptr_00 = (void *)0x0;
        }
        if (param_5 != (int *)0x0) {
          *param_5 = iVar2;
        }
        uVar7 = 0;
        if (param_6 != (long *)0x0) {
          *param_6 = (long)__ptr_01;
          __ptr_01 = (void *)0x0;
        }
      }
    }
  }
  else {
    *pcVar3 = '\0';
    pcVar4 = strchr(local_48,0x3b);
    if (pcVar4 != (char *)0x0) {
      *pcVar4 = '\0';
      pcVar5 = local_48;
    }
    if ((*pcVar5 != '\0') && (__ptr = (void *)FUN_00122610(), __ptr != (void *)0x0)) {
      local_48 = pcVar3 + 1;
      goto LAB_00129d8a;
    }
    uVar7 = 0xffffffff;
    __ptr_01 = (void *)0x0;
    __ptr_00 = (void *)0x0;
    __ptr = (void *)0x0;
  }
  free(__s);
  free(__ptr);
  free(__ptr_00);
  free(__ptr_01);
LAB_00129cba:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



// Function: valid_env_name @ 0x29f30

undefined8 valid_env_name(byte *param_1)

{
  ushort **ppuVar1;
  undefined8 uVar2;
  byte bVar3;
  
  uVar2 = 0;
  bVar3 = *param_1;
  if (bVar3 != 0) {
    ppuVar1 = __ctype_b_loc();
    do {
      if ((((*ppuVar1)[bVar3] & 8) == 0) && (bVar3 != 0x5f)) {
        return 0;
      }
      bVar3 = param_1[1];
      param_1 = param_1 + 1;
    } while (bVar3 != 0);
    uVar2 = 1;
  }
  return uVar2;
}



// Function: atoi_err @ 0x2a090

char * atoi_err(char *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  long in_FS_OFFSET;
  char *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_18 = (char *)0x0;
  pcVar2 = "missing";
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    uVar1 = FUN_0013bfe0(param_1,0,0x7fffffff,&local_18);
    pcVar2 = local_18;
    if (local_18 == (char *)0x0) {
      *param_2 = uVar1;
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: parse_absolute_time @ 0x2a190

undefined8 parse_absolute_time(char *param_1,long *param_2)

{
  int iVar1;
  size_t sVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  size_t sVar6;
  long in_FS_OFFSET;
  bool bVar7;
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  char *local_68;
  char local_58 [40];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  *param_2 = 0;
  sVar2 = strlen(param_1);
  if (1 < sVar2) {
    sVar6 = sVar2 - 1;
    iVar1 = strcasecmp(param_1 + sVar6,"Z");
    if (iVar1 == 0) {
      bVar7 = true;
      if (sVar6 != 0xc) goto LAB_0012a223;
LAB_0012a388:
      __snprintf_chk(local_58,0x20,1,0x20,"%.4s-%.2s-%.2sT%.2s:%.2s",param_1,param_1 + 4,param_1 + 6
                     ,param_1 + 8,param_1 + 10);
      pcVar5 = "%Y-%m-%dT%H:%M";
    }
    else {
      if (sVar2 < 4) goto LAB_0012a440;
      iVar1 = strcasecmp(param_1 + (sVar2 - 3),"UTC");
      bVar7 = iVar1 == 0;
      sVar6 = sVar2 - 3;
      if (iVar1 != 0) {
        sVar6 = sVar2;
      }
      if (sVar6 == 0xc) goto LAB_0012a388;
LAB_0012a223:
      if (sVar6 == 0xe) {
        __snprintf_chk(local_58,0x20,1,0x20,"%.4s-%.2s-%.2sT%.2s:%.2s:%.2s",param_1,param_1 + 4,
                       param_1 + 6,param_1 + 8,param_1 + 10,param_1 + 0xc);
        pcVar5 = "%Y-%m-%dT%H:%M:%S";
      }
      else {
        uVar4 = 0xfffffffc;
        if (sVar6 != 8) goto LAB_0012a2d8;
        __snprintf_chk(local_58,0x20,1,0x20,"%.4s-%.2s-%.2s",param_1,param_1 + 4,param_1 + 6);
        pcVar5 = "%Y-%m-%d";
      }
    }
    local_68 = (char *)0x0;
    local_98 = (undefined1  [16])0x0;
    local_88 = (undefined1  [16])0x0;
    local_78 = (undefined1  [16])0x0;
    pcVar5 = strptime(local_58,pcVar5,(tm *)local_98);
    if ((pcVar5 != (char *)0x0) && (*pcVar5 == '\0')) {
      if (bVar7) {
        lVar3 = timegm((tm *)local_98);
      }
      else {
        lVar3 = mktime((tm *)local_98);
      }
      if (-1 < lVar3) {
        *param_2 = lVar3;
        uVar4 = 0;
        goto LAB_0012a2d8;
      }
    }
  }
LAB_0012a440:
  uVar4 = 0xfffffffc;
LAB_0012a2d8:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



// Function: format_absolute_time @ 0x2a450

undefined8 format_absolute_time(long param_1,char *param_2,size_t param_3)

{
  long in_FS_OFFSET;
  long local_60;
  tm local_58;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 < 0) {
    param_1 = 0x7fffffffffffffff;
  }
  local_60 = param_1;
  localtime_r(&local_60,&local_58);
  strftime(param_2,param_3,"%Y-%m-%dT%H:%M:%S",&local_58);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: path_absolute @ 0x2a560

bool path_absolute(char *param_1)

{
  return *param_1 == '/';
}



// Function: skip_space @ 0x2a5f0

undefined8 skip_space(undefined8 *param_1)

{
  char *pcVar1;
  char cVar2;
  
  pcVar1 = (char *)*param_1;
  cVar2 = *pcVar1;
  if (cVar2 != ' ') goto LAB_0012a60d;
  do {
    do {
      cVar2 = pcVar1[1];
      pcVar1 = pcVar1 + 1;
    } while (cVar2 == ' ');
LAB_0012a60d:
  } while (cVar2 == '\t');
  *param_1 = pcVar1;
  return 0;
}



// Function: opt_flag @ 0x2a6a0

uint opt_flag(char *param_1,int param_2,undefined8 *param_3)

{
  int iVar1;
  size_t __n;
  uint uVar2;
  char *__s1;
  
  __n = strlen(param_1);
  __s1 = (char *)*param_3;
  uVar2 = 0;
  if (param_2 != 0) {
    uVar2 = 0;
    iVar1 = strncasecmp(__s1,"no-",3);
    if (iVar1 == 0) {
      __s1 = __s1 + 3;
      uVar2 = 1;
    }
  }
  iVar1 = strncasecmp(__s1,param_1,__n);
  if (iVar1 == 0) {
    *param_3 = __s1 + __n;
    uVar2 = uVar2 ^ 1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



// Function: opt_dequote @ 0x2a7b0

void * opt_dequote(undefined8 *param_1,undefined8 *param_2)

{
  size_t sVar1;
  void *__ptr;
  long lVar2;
  long lVar3;
  char cVar4;
  char *pcVar5;
  char *__s;
  
  pcVar5 = (char *)*param_1;
  *param_2 = 0;
  if (*pcVar5 == '\"') {
    __s = pcVar5 + 1;
    sVar1 = strlen(__s);
    __ptr = malloc(sVar1 + 1);
    if (__ptr == (void *)0x0) {
      *param_2 = "memory allocation failed";
    }
    else {
      cVar4 = pcVar5[1];
      if ((cVar4 == '\"') || (lVar3 = 0, cVar4 == '\0')) {
        lVar2 = 0;
      }
      else {
        do {
          if (cVar4 == '\\') {
            cVar4 = __s[1];
            pcVar5 = __s + 1;
            if (cVar4 != '\"') goto LAB_0012a8be;
          }
          else {
LAB_0012a8be:
            cVar4 = *__s;
            pcVar5 = __s;
          }
          lVar2 = lVar3 + 1;
          __s = pcVar5 + 1;
          *(char *)((long)__ptr + lVar3) = cVar4;
          cVar4 = pcVar5[1];
          if (cVar4 == '\0') goto LAB_0012a988;
          lVar3 = lVar2;
        } while (cVar4 != '\"');
      }
      if (cVar4 != '\0') {
        *(undefined1 *)((long)__ptr + lVar2) = 0;
        *param_1 = __s + 1;
        return __ptr;
      }
LAB_0012a988:
      *param_2 = "missing end quote";
      free(__ptr);
    }
  }
  else {
    *param_2 = "missing start quote";
  }
  return (void *)0x0;
}



// Function: opt_match @ 0x2a9c0

undefined4 opt_match(long *param_1,char *param_2)

{
  char *__s1;
  int iVar1;
  size_t __n;
  
  __n = strlen(param_2);
  __s1 = (char *)*param_1;
  iVar1 = strncasecmp(__s1,param_2,__n);
  if (iVar1 != 0) {
    return 0;
  }
  if (__s1[__n] != '=') {
    return 0;
  }
  *param_1 = (long)(__s1 + __n + 1);
  return 1;
}



// Function: opt_array_append2 @ 0x2abc0

undefined8
opt_array_append2(undefined8 param_1,undefined8 param_2,undefined8 param_3,long *param_4,long *param_5,
            uint *param_6,undefined8 param_7,undefined4 param_8)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar1 = *param_6;
  if (uVar1 < 0x7fffffff) {
    if (param_5 != (long *)0x0) {
      lVar2 = FUN_00121760(*param_5,uVar1,uVar1 + 1,4);
      *param_5 = lVar2;
      *(undefined4 *)(lVar2 + (ulong)*param_6 * 4) = param_8;
      uVar1 = *param_6;
    }
    lVar2 = FUN_00121760(*param_4,uVar1,uVar1 + 1,8);
    *param_4 = lVar2;
    uVar1 = *param_6;
    uVar3 = FUN_00121840(param_7);
    *(undefined8 *)(lVar2 + (ulong)uVar1 * 8) = uVar3;
    *param_6 = *param_6 + 1;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0011ee30("misc.c","opt_array_append2",0xa02,0,1,0,"%s line %d: Too many %s entries",param_1,
               param_2,param_3);
}



// Function: opt_array_append @ 0x2acf0

undefined8 opt_array_append(void)

{
  FUN_0012abc0();
  return 0;
}



// Function: ssh_signal @ 0x2ad90

_union_1457 ssh_signal(int param_1,_union_1457 param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char *pcVar4;
  long lVar5;
  ulong *puVar6;
  long in_FS_OFFSET;
  _union_1457 local_158;
  ulong local_150 [16];
  undefined4 local_d0;
  _union_1457 local_b8 [19];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  puVar6 = local_150;
  for (lVar5 = 0x12; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_158 = param_2;
  sigfillset((sigset_t *)local_150);
  if (param_1 != 0xe) {
    local_d0 = 0x10000000;
  }
  iVar1 = sigaction(param_1,(sigaction *)&local_158,(sigaction *)local_b8);
  if (iVar1 == -1) {
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    pcVar4 = strsignal(param_1);
    FUN_001203a0("misc.c","ssh_signal",0xa24,0,7,0,"sigaction(%s): %s",pcVar4,pcVar3);
    local_b8[0] = (_union_1457)0xffffffffffffffff;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return (_union_1457)local_b8[0].sa_handler;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: stdfd_devnull @ 0x2af10

undefined8 stdfd_devnull(int param_1,int param_2,int param_3)

{
  int __fd;
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  __fd = open("/dev/null",2);
  if (__fd == -1) {
    piVar2 = __errno_location();
    uVar4 = 0xffffffff;
    pcVar3 = strerror(*piVar2);
    FUN_001203a0("misc.c","stdfd_devnull",0xa30,1,2,0,"open %s: %s","/dev/null",pcVar3);
  }
  else {
    if ((((param_1 == 0) || (iVar1 = dup2(__fd,0), iVar1 != -1)) &&
        ((param_2 == 0 || (iVar1 = dup2(__fd,1), iVar1 != -1)))) &&
       ((param_3 == 0 || (iVar1 = dup2(__fd,2), iVar1 != -1)))) {
      uVar4 = 0;
    }
    else {
      piVar2 = __errno_location();
      uVar4 = 0xffffffff;
      pcVar3 = strerror(*piVar2);
      FUN_001203a0("misc.c","stdfd_devnull",0xa37,1,2,0,"dup2: %s",pcVar3);
    }
    if (2 < __fd) {
      close(__fd);
      return uVar4;
    }
  }
  return uVar4;
}



// Function: subprocess @ 0x2b180

__pid_t subprocess(undefined8 param_1,undefined8 param_2,undefined8 param_3,char **param_4,
                    undefined8 *param_5,uint param_6,passwd *param_7,code *param_8,code *param_9)

{
  __gid_t __rgid;
  int iVar1;
  __pid_t __pid;
  int iVar2;
  __uid_t _Var3;
  __pid_t _Var4;
  FILE *pFVar5;
  int *piVar6;
  char *pcVar7;
  char *pcVar8;
  undefined8 extraout_RDX;
  undefined8 uVar9;
  ulong uVar10;
  long in_FS_OFFSET;
  undefined4 local_2ec;
  char **local_2e8;
  int local_2e0;
  int local_2dc;
  stat local_2d8 [4];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_2ec = 0;
  local_2e8 = (char **)0x0;
  if (param_8 == (code *)0x0) {
    if (param_7 == (passwd *)0x0) {
      _Var3 = getuid();
      param_7 = getpwuid(_Var3);
      if (param_7 == (passwd *)0x0) {
        pcVar7 = "%s: no user for current uid";
        uVar9 = 0xa5b;
        goto LAB_0012b6c3;
      }
    }
  }
  else if ((param_7 == (passwd *)0x0) || (param_9 == (code *)0x0)) {
    pcVar7 = "%s: inconsistent arguments";
    uVar9 = 0xa57;
LAB_0012b6c3:
    FUN_001203a0("misc.c","subprocess",uVar9,0,2,0,pcVar7,param_1);
    __pid = 0;
    goto LAB_0012b3c1;
  }
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = 0;
  }
  FUN_001203a0("misc.c","subprocess",0xa61,1,7,0,"%s command \"%s\" running as %s (flags 0x%x)",
               param_1,param_2,param_7->pw_name,param_6);
  if ((param_6 & 3) == 3) {
    pcVar7 = "inconsistent flags";
    uVar9 = 0xa67;
  }
  else {
    if (((param_6 & 2) == 0) == (param_5 == (undefined8 *)0x0)) {
      pcVar7 = *param_4;
      iVar1 = FUN_0012a560();
      if (iVar1 == 0) {
        FUN_001203a0("misc.c","subprocess",0xa74,0,2,0,"%s path is not absolute",param_1);
        __pid = 0;
        goto LAB_0012b3c1;
      }
      if (param_8 != (code *)0x0) {
        (*param_8)(param_7);
        pcVar7 = *param_4;
      }
      iVar1 = stat(pcVar7,local_2d8);
      if (iVar1 == -1) {
        piVar6 = __errno_location();
        strerror(*piVar6);
        uVar9 = 0xa7a;
        pcVar7 = *param_4;
        pcVar8 = "Could not stat %s \"%s\": %s";
LAB_0012b511:
        FUN_001203a0("misc.c","subprocess",uVar9,0,2,0,pcVar8,param_1,pcVar7);
        if (param_9 != (code *)0x0) {
          (*param_9)();
          __pid = 0;
          goto LAB_0012b3c1;
        }
      }
      else {
        if (((param_6 & 8) == 0) && (iVar1 = FUN_00129150(*param_4,local_2d8,0,0), iVar1 != 0)) {
          uVar9 = 0xa80;
          pcVar7 = *param_4;
          pcVar8 = "Unsafe %s \"%s\": %s";
          goto LAB_0012b511;
        }
        iVar1 = pipe(&local_2e0);
        if (iVar1 == -1) {
          piVar6 = __errno_location();
          pcVar7 = strerror(*piVar6);
          uVar9 = 0xa85;
          pcVar8 = "%s: pipe: %s";
          goto LAB_0012b511;
        }
        if (param_9 != (code *)0x0) {
          (*param_9)();
        }
        __pid = fork();
        if (__pid != -1) {
          if (__pid != 0) {
            close(local_2dc);
            if ((param_6 & 2) == 0) {
              pFVar5 = (FILE *)0x0;
              close(local_2e0);
            }
            else {
              pFVar5 = fdopen(local_2e0,"r");
              if (pFVar5 == (FILE *)0x0) {
                piVar6 = __errno_location();
                pcVar7 = strerror(*piVar6);
                FUN_001203a0("misc.c","subprocess",0xadf,0,2,0,"%s: fdopen: %s",param_1,pcVar7,
                             extraout_RDX);
                close(local_2e0);
                kill(__pid,0xf);
                do {
                  _Var4 = waitpid(__pid,(int *)0x0,0);
                  if (_Var4 != -1) break;
                } while (*piVar6 == 4);
                goto LAB_0012b738;
              }
            }
            FUN_001203a0("misc.c","subprocess",0xae8,1,7,0,"%s pid %ld",param_1,(long)__pid);
            if (param_5 != (undefined8 *)0x0) {
              *param_5 = pFVar5;
            }
            goto LAB_0012b3c1;
          }
          if ((param_6 & 0x10) == 0) {
            local_2ec = 5;
            local_2e8 = (char **)FUN_00121540(8,5);
            FUN_00129590(&local_2e8,&local_2ec,&DAT_00140536,
                         "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin");
            FUN_00129590(&local_2e8,&local_2ec,&DAT_0013fad9,param_7->pw_name);
            FUN_00129590(&local_2e8,&local_2ec,"LOGNAME",param_7->pw_name);
            FUN_00129590(&local_2e8,&local_2ec,&DAT_00140543,param_7->pw_dir);
            pcVar7 = getenv("LANG");
            if (pcVar7 != (char *)0x0) {
              FUN_00129590(&local_2e8,&local_2ec,&DAT_00140548,pcVar7);
            }
          }
          iVar1 = 1;
          do {
            FUN_0012ad90(iVar1,0);
            iVar1 = FUN_0013da20(iVar1);
          } while (iVar1 != 0x41);
          iVar1 = open("/dev/null",2);
          piVar6 = __errno_location();
          if (iVar1 == -1) {
            strerror(*piVar6);
            pcVar7 = "/dev/null";
            uVar9 = 0xaa5;
            pcVar8 = "%s: open %s: %s";
            goto LAB_0012b7e9;
          }
          iVar2 = dup2(iVar1,0);
          if (iVar2 == -1) {
            pcVar7 = strerror(*piVar6);
            uVar9 = 0xaaa;
            pcVar8 = "%s: dup2: %s";
            goto LAB_0012b7e9;
          }
          if ((param_6 & 2) == 0) {
            if ((param_6 & 1) != 0) goto LAB_0012b7ad;
          }
          else {
            iVar1 = local_2dc;
            if (local_2dc != -1) {
LAB_0012b7ad:
              iVar1 = dup2(iVar1,1);
              if (iVar1 == -1) {
                pcVar7 = strerror(*piVar6);
                uVar9 = 0xab5;
                pcVar8 = "%s: dup2: %s";
                goto LAB_0012b7e9;
              }
            }
          }
          closefrom(3);
          _Var3 = geteuid();
          if (_Var3 == 0) {
            uVar10 = (ulong)param_7->pw_gid;
            iVar1 = initgroups(param_7->pw_name,param_7->pw_gid);
            if (iVar1 == -1) {
              pcVar7 = strerror(*piVar6);
              FUN_001203a0("misc.c","subprocess",0xabc,0,2,0,"%s: initgroups(%s, %u): %s",param_1,
                           param_7->pw_name,param_7->pw_gid,pcVar7,uVar10);
                    /* WARNING: Subroutine does not return */
              _exit(1);
            }
          }
          __rgid = param_7->pw_gid;
          iVar1 = setresgid(__rgid,__rgid,__rgid);
          if (iVar1 == -1) {
            strerror(*piVar6);
            pcVar7 = (char *)(ulong)param_7->pw_gid;
            uVar9 = 0xac1;
            pcVar8 = "%s: setresgid %u: %s";
          }
          else {
            _Var3 = param_7->pw_uid;
            iVar1 = setresuid(_Var3,_Var3,_Var3);
            if (iVar1 == -1) {
              strerror(*piVar6);
              pcVar7 = (char *)(ulong)param_7->pw_uid;
              uVar9 = 0xac6;
              pcVar8 = "%s: setresuid %u: %s";
            }
            else {
              if (((param_6 & 1) == 0) || (iVar1 = dup2(0,2), iVar1 != -1)) {
                if (local_2e8 == (char **)0x0) {
                  execv(*param_4,param_4);
                  pcVar7 = strerror(*piVar6);
                  pcVar8 = "execv";
                }
                else {
                  execve(*param_4,param_4,local_2e8);
                  pcVar7 = strerror(*piVar6);
                  pcVar8 = "execve";
                }
                FUN_001203a0("misc.c","subprocess",0xad4,0,2,0,"%s %s \"%s\": %s",param_1,pcVar8,
                             param_2,pcVar7);
                    /* WARNING: Subroutine does not return */
                _exit(0x7f);
              }
              pcVar7 = strerror(*piVar6);
              uVar9 = 0xacd;
              pcVar8 = "%s: dup2: %s";
            }
          }
LAB_0012b7e9:
          FUN_001203a0("misc.c","subprocess",uVar9,0,2,0,pcVar8,param_1,pcVar7);
                    /* WARNING: Subroutine does not return */
          _exit(1);
        }
        piVar6 = __errno_location();
        pcVar7 = strerror(*piVar6);
        FUN_001203a0("misc.c","subprocess",0xa90,0,2,0,"%s: fork: %s",param_1,pcVar7);
        close(local_2e0);
        close(local_2dc);
      }
LAB_0012b738:
      __pid = 0;
      goto LAB_0012b3c1;
    }
    pcVar7 = "inconsistent flags/output";
    uVar9 = 0xa6b;
  }
  FUN_001203a0("misc.c","subprocess",uVar9,1,2,0,pcVar7);
  __pid = 0;
LAB_0012b3c1:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __pid;
}



// Function: lookup_env_in_list @ 0x2bb30

char * lookup_env_in_list(char *param_1,long param_2,long param_3)

{
  char *__s1;
  int iVar1;
  size_t __n;
  long lVar2;
  
  __n = strlen(param_1);
  if (param_3 != 0) {
    lVar2 = 0;
    do {
      __s1 = *(char **)(param_2 + lVar2 * 8);
      iVar1 = strncmp(__s1,param_1,__n);
      if ((iVar1 == 0) && (__s1[__n] == '=')) {
        return __s1 + __n + 1;
      }
      lVar2 = lVar2 + 1;
    } while (param_3 != lVar2);
  }
  return (char *)0x0;
}



// Function: lookup_setenv_in_list @ 0x2bcb0

undefined8 lookup_setenv_in_list(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char *__s;
  char *pcVar1;
  undefined8 uVar2;
  
  __s = (char *)FUN_00121840();
  pcVar1 = strchr(__s,0x3d);
  uVar2 = 0;
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
    uVar2 = FUN_0012bb30(__s,param_2,param_3);
  }
  free(__s);
  return uVar2;
}



// Function: ssh_dss_sign @ 0x2bd90

int ssh_dss_sign(undefined4 *param_1,undefined8 *param_2,size_t *param_3,undefined8 param_4,
                undefined8 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  DSA_SIG *a;
  size_t __size;
  void *pvVar5;
  long in_FS_OFFSET;
  BIGNUM *local_c8;
  BIGNUM *local_c0;
  undefined1 local_b8 [20];
  uchar auStack_a4 [20];
  uchar auStack_90 [8];
  uchar local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar4 = FUN_00130050(1);
  if (param_3 != (size_t *)0x0) {
    *param_3 = 0;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if ((param_1 != (undefined4 *)0x0) && (*(long *)(param_1 + 4) != 0)) {
    iVar1 = FUN_0010f440(*param_1);
    if (iVar1 == 1) {
      if (lVar4 == 0) {
        iVar1 = -1;
        goto LAB_0012be6e;
      }
      iVar1 = FUN_00130740(1,param_4,param_5,local_88,0x40);
      if (iVar1 == 0) {
        a = DSA_do_sign(local_88,(int)lVar4,*(DSA **)(param_1 + 4));
        if (a == (DSA_SIG *)0x0) {
          lVar4 = 0;
          iVar1 = -0x16;
        }
        else {
          DSA_SIG_get0(a,&local_c8,&local_c0);
          iVar1 = BN_num_bits(local_c8);
          iVar2 = FUN_0013da20(iVar1,7);
          iVar1 = iVar2 + 7;
          if (-1 < iVar2) {
            iVar1 = iVar2;
          }
          iVar2 = BN_num_bits(local_c0);
          iVar3 = FUN_0013da20(iVar2,7);
          iVar2 = iVar3 + 7;
          if (-1 < iVar3) {
            iVar2 = iVar3;
          }
          if (((ulong)(long)(iVar1 >> 3) < 0x15) && ((ulong)(long)(iVar2 >> 3) < 0x15)) {
            __explicit_bzero_chk(local_b8,0x28,0x28);
            BN_bn2bin(local_c8,auStack_a4 + -(long)(iVar1 >> 3));
            iVar1 = -2;
            BN_bn2bin(local_c0,auStack_90 + -(long)(iVar2 >> 3));
            lVar4 = FUN_0010b880();
            if (lVar4 != 0) {
              iVar1 = FUN_0011b800(lVar4,"ssh-dss");
              if (iVar1 == 0) {
                iVar1 = FUN_0011b6c0(lVar4,local_b8,0x28);
                if (iVar1 == 0) {
                  __size = FUN_0010c3d0(lVar4);
                  if (param_2 != (undefined8 *)0x0) {
                    pvVar5 = malloc(__size);
                    *param_2 = pvVar5;
                    if (pvVar5 == (void *)0x0) {
                      iVar1 = -2;
                      goto LAB_0012be4c;
                    }
                    pvVar5 = (void *)FUN_0010c520(lVar4);
                    memcpy((void *)*param_2,pvVar5,__size);
                  }
                  if (param_3 != (size_t *)0x0) {
                    *param_3 = __size;
                  }
                }
              }
            }
          }
          else {
            iVar1 = -1;
            lVar4 = 0;
          }
        }
      }
      else {
        lVar4 = 0;
        a = (DSA_SIG *)0x0;
      }
LAB_0012be4c:
      __explicit_bzero_chk(local_88,0x40,0x40);
      DSA_SIG_free(a);
      FUN_0010bce0(lVar4);
      goto LAB_0012be6e;
    }
  }
  iVar1 = -10;
LAB_0012be6e:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_dss_verify @ 0x2c0e0

int ssh_dss_verify(undefined4 *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5
                )

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  DSA_SIG *sig;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *pBVar6;
  long in_FS_OFFSET;
  uchar *local_a0;
  long local_98;
  char *local_90;
  uchar local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_a0 = (uchar *)0x0;
  lVar3 = FUN_00130050(1);
  local_90 = (char *)0x0;
  if ((((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 4) == 0)) ||
      (iVar1 = FUN_0010f440(*param_1), iVar1 != 1)) || ((param_2 == 0 || (param_3 == 0)))) {
    iVar1 = -10;
    goto LAB_0012c20a;
  }
  if (lVar3 == 0) {
    iVar1 = -1;
    goto LAB_0012c20a;
  }
  lVar4 = FUN_0010b980(param_2,param_3);
  if (lVar4 == 0) {
    iVar1 = -2;
    goto LAB_0012c20a;
  }
  iVar1 = FUN_0011a6f0(lVar4,&local_90,0);
  if ((iVar1 == 0) && (iVar1 = FUN_0011a590(lVar4,&local_a0,&local_98), iVar1 == 0)) {
    iVar1 = strcmp("ssh-dss",local_90);
    if (iVar1 == 0) {
      lVar5 = FUN_0010c3d0(lVar4);
      if (lVar5 == 0) {
        if (local_98 != 0x28) goto LAB_0012c1a1;
        sig = DSA_SIG_new();
        if (sig == (DSA_SIG *)0x0) {
          ret_00 = (BIGNUM *)0x0;
          ret = (BIGNUM *)0x0;
          iVar1 = -2;
        }
        else {
          ret = BN_new();
          if (ret == (BIGNUM *)0x0) {
            ret_00 = (BIGNUM *)0x0;
            iVar1 = -2;
          }
          else {
            ret_00 = BN_new();
            if (ret_00 == (BIGNUM *)0x0) {
              iVar1 = -2;
            }
            else {
              pBVar6 = BN_bin2bn(local_a0,0x14,ret);
              if (((pBVar6 == (BIGNUM *)0x0) ||
                  (pBVar6 = BN_bin2bn(local_a0 + 0x14,0x14,ret_00), pBVar6 == (BIGNUM *)0x0)) ||
                 (iVar1 = DSA_SIG_set0(sig,ret,ret_00), iVar1 == 0)) {
                iVar1 = -0x16;
              }
              else {
                iVar1 = FUN_00130740(1,param_4,param_5,local_88);
                if (iVar1 == 0) {
                  iVar2 = DSA_do_verify(local_88,(int)lVar3,sig,*(DSA **)(param_1 + 4));
                  if (iVar2 != 0) {
                    ret_00 = (BIGNUM *)0x0;
                    ret = (BIGNUM *)0x0;
                    if (iVar2 != 1) {
                      iVar1 = -0x16;
                    }
                    goto LAB_0012c1b5;
                  }
                  iVar1 = -0x15;
                }
                ret_00 = (BIGNUM *)0x0;
                ret = (BIGNUM *)0x0;
              }
            }
          }
        }
      }
      else {
        iVar1 = -0x17;
        ret_00 = (BIGNUM *)0x0;
        ret = (BIGNUM *)0x0;
        sig = (DSA_SIG *)0x0;
      }
    }
    else {
      iVar1 = -0xd;
      ret_00 = (BIGNUM *)0x0;
      ret = (BIGNUM *)0x0;
      sig = (DSA_SIG *)0x0;
    }
  }
  else {
LAB_0012c1a1:
    iVar1 = -4;
    ret_00 = (BIGNUM *)0x0;
    ret = (BIGNUM *)0x0;
    sig = (DSA_SIG *)0x0;
  }
LAB_0012c1b5:
  __explicit_bzero_chk(local_88,0x40,0x40);
  DSA_SIG_free(sig);
  BN_clear_free(ret);
  BN_clear_free(ret_00);
  FUN_0010bce0(lVar4);
  free(local_90);
  if (local_a0 != (uchar *)0x0) {
    FUN_0013b0d0(local_a0,local_98);
  }
LAB_0012c20a:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



// Function: ssh_ecdsa_sign @ 0x2c4e0

int ssh_ecdsa_sign(undefined4 *param_1,undefined8 *param_2,size_t *param_3,undefined8 param_4,
                undefined8 param_5)

{
  int iVar1;
  long lVar2;
  ECDSA_SIG *sig;
  long lVar3;
  undefined8 uVar4;
  size_t __size;
  void *pvVar5;
  long in_FS_OFFSET;
  undefined8 local_98;
  undefined8 local_90;
  uchar local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 != (size_t *)0x0) {
    *param_3 = 0;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if ((param_1 != (undefined4 *)0x0) && (*(long *)(param_1 + 8) != 0)) {
    iVar1 = FUN_0010f440(*param_1);
    if (iVar1 == 2) {
      iVar1 = FUN_001109a0(param_1[6]);
      if (iVar1 != -1) {
        lVar2 = FUN_00130050(iVar1);
        if (lVar2 != 0) {
          iVar1 = FUN_00130740(iVar1,param_4,param_5,local_88);
          if (iVar1 == 0) {
            sig = ECDSA_do_sign(local_88,(int)lVar2,*(EC_KEY **)(param_1 + 8));
            if (sig == (ECDSA_SIG *)0x0) {
              lVar2 = 0;
              lVar3 = 0;
              iVar1 = -0x16;
            }
            else {
              lVar2 = FUN_0010b880();
              if (lVar2 == 0) {
                lVar3 = 0;
                iVar1 = -2;
              }
              else {
                lVar3 = FUN_0010b880();
                iVar1 = -2;
                if (lVar3 != 0) {
                  ECDSA_SIG_get0(sig,&local_98,&local_90);
                  iVar1 = FUN_0011d610(lVar2,local_98);
                  if (iVar1 == 0) {
                    iVar1 = FUN_0011d610(lVar2,local_90);
                    if (iVar1 == 0) {
                      uVar4 = FUN_0010f8b0(param_1);
                      iVar1 = FUN_0011b800(lVar3,uVar4);
                      if (iVar1 == 0) {
                        iVar1 = FUN_0011b840(lVar3,lVar2);
                        if (iVar1 == 0) {
                          __size = FUN_0010c3d0(lVar3);
                          if (param_2 != (undefined8 *)0x0) {
                            pvVar5 = malloc(__size);
                            *param_2 = pvVar5;
                            if (pvVar5 == (void *)0x0) {
                              iVar1 = -2;
                              goto LAB_0012c5a8;
                            }
                            pvVar5 = (void *)FUN_0010c520(lVar3);
                            memcpy((void *)*param_2,pvVar5,__size);
                          }
                          if (param_3 != (size_t *)0x0) {
                            *param_3 = __size;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            lVar2 = 0;
            lVar3 = 0;
            sig = (ECDSA_SIG *)0x0;
          }
LAB_0012c5a8:
          __explicit_bzero_chk(local_88,0x40,0x40);
          FUN_0010bce0(lVar3);
          FUN_0010bce0(lVar2);
          ECDSA_SIG_free(sig);
          goto LAB_0012c5d7;
        }
      }
      iVar1 = -1;
      goto LAB_0012c5d7;
    }
  }
  iVar1 = -10;
LAB_0012c5d7:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_ecdsa_verify @ 0x2c810

int ssh_ecdsa_verify(undefined4 *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5
                )

{
  char *__s2;
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char *__s1;
  long lVar5;
  ECDSA_SIG *sig;
  long in_FS_OFFSET;
  BIGNUM *local_a8;
  BIGNUM *local_a0;
  undefined8 local_98;
  char *local_90;
  uchar local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_a8 = (BIGNUM *)0x0;
  local_a0 = (BIGNUM *)0x0;
  local_98 = 0;
  local_90 = (char *)0x0;
  if ((((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 8) == 0)) ||
      (iVar1 = FUN_0010f440(*param_1), iVar1 != 2)) || ((param_2 == 0 || (param_3 == 0)))) {
    iVar1 = -10;
    goto LAB_0012c952;
  }
  iVar1 = FUN_001109a0(param_1[6]);
  if ((iVar1 == -1) || (lVar3 = FUN_00130050(iVar1), lVar3 == 0)) {
    iVar1 = -1;
    goto LAB_0012c952;
  }
  lVar4 = FUN_0010b980(param_2,param_3);
  if (lVar4 == 0) {
    iVar1 = -2;
    goto LAB_0012c952;
  }
  iVar2 = FUN_0011a6f0(lVar4,&local_90,0);
  if ((iVar2 == 0) && (iVar2 = FUN_0011b8a0(lVar4,&local_98), __s2 = local_90, iVar2 == 0)) {
    __s1 = (char *)FUN_0010f8b0(param_1);
    iVar2 = strcmp(__s1,__s2);
    if (iVar2 == 0) {
      lVar5 = FUN_0010c3d0(lVar4);
      if (lVar5 == 0) {
        iVar2 = FUN_0011d220(local_98,&local_a8);
        if ((iVar2 != 0) || (iVar2 = FUN_0011d220(local_98,&local_a0), iVar2 != 0))
        goto LAB_0012c8fa;
        sig = ECDSA_SIG_new();
        if (sig == (ECDSA_SIG *)0x0) {
          iVar1 = -2;
        }
        else {
          iVar2 = ECDSA_SIG_set0(sig,local_a8,local_a0);
          if (iVar2 == 0) {
            iVar1 = -0x16;
          }
          else {
            local_a0 = (BIGNUM *)0x0;
            local_a8 = (BIGNUM *)0x0;
            lVar5 = FUN_0010c3d0(local_98);
            if (lVar5 == 0) {
              iVar1 = FUN_00130740(iVar1,param_4,param_5,local_88,0x40);
              if (iVar1 == 0) {
                iVar2 = ECDSA_do_verify(local_88,(int)lVar3,sig,*(EC_KEY **)(param_1 + 8));
                if (iVar2 == 0) {
                  iVar1 = -0x15;
                }
                else if (iVar2 != 1) {
                  iVar1 = -0x16;
                }
              }
            }
            else {
              iVar1 = -0x17;
            }
          }
        }
      }
      else {
        iVar1 = -0x17;
        sig = (ECDSA_SIG *)0x0;
      }
    }
    else {
      iVar1 = -0xd;
      sig = (ECDSA_SIG *)0x0;
    }
  }
  else {
LAB_0012c8fa:
    iVar1 = -4;
    sig = (ECDSA_SIG *)0x0;
  }
  __explicit_bzero_chk(local_88,0x40,0x40);
  FUN_0010bce0(local_98);
  FUN_0010bce0(lVar4);
  ECDSA_SIG_free(sig);
  BN_clear_free(local_a8);
  BN_clear_free(local_a0);
  free(local_90);
LAB_0012c952:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



// Function: ssh_ecdsa_sk_verify @ 0x2ce10

int ssh_ecdsa_sk_verify(undefined4 *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5
                ,undefined8 param_6,undefined8 *param_7)

{
  char *pcVar1;
  EC_KEY *eckey;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined4 *puVar7;
  long lVar8;
  size_t sVar9;
  long in_FS_OFFSET;
  ECDSA_SIG *local_f8;
  undefined1 local_e5;
  undefined4 local_e4;
  BIGNUM *local_e0;
  BIGNUM *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  char *local_b8;
  void *local_b0;
  undefined1 local_a8 [32];
  undefined1 local_88 [32];
  uchar local_68 [40];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_e0 = (BIGNUM *)0x0;
  local_d8 = (BIGNUM *)0x0;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = (char *)0x0;
  local_b0 = (void *)0x0;
  if (param_7 != (undefined8 *)0x0) {
    *param_7 = 0;
  }
  if ((((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 8) == 0)) ||
      (iVar3 = FUN_0010f440(*param_1), iVar3 != 10)) || ((param_2 == 0 || (param_3 == 0)))) {
    iVar3 = -10;
    goto LAB_0012d0bd;
  }
  if (param_1[6] != 0x19f) {
    iVar3 = -1;
    goto LAB_0012d0bd;
  }
  lVar6 = FUN_0010b980(param_2,param_3);
  if (lVar6 == 0) {
    iVar3 = -2;
    goto LAB_0012d0bd;
  }
  puVar7 = calloc(1,8);
  if (puVar7 == (undefined4 *)0x0) {
    lVar8 = 0;
    iVar3 = -2;
    local_f8 = (ECDSA_SIG *)0x0;
  }
  else {
    iVar3 = FUN_0011a6f0(lVar6,&local_b8,0);
    pcVar1 = local_b8;
    if (iVar3 == 0) {
      iVar3 = strcmp(local_b8,"webauthn-sk-ecdsa-sha2-nistp256@openssh.com");
      if (iVar3 == 0) {
        bVar2 = true;
      }
      else {
        iVar3 = strcmp(pcVar1,"sk-ecdsa-sha2-nistp256@openssh.com");
        bVar2 = false;
        if (iVar3 != 0) goto LAB_0012cfb0;
      }
      iVar3 = FUN_0011b8a0(lVar6,&local_d0);
      if (iVar3 == 0) {
        iVar3 = FUN_00119e50(lVar6,&local_e5);
        if (iVar3 != 0) {
          lVar8 = 0;
          local_f8 = (ECDSA_SIG *)0x0;
          iVar3 = -4;
          goto LAB_0012cfd9;
        }
        iVar3 = FUN_00119cd0(lVar6,&local_e4);
        if ((iVar3 != 0) ||
           ((bVar2 && (((iVar3 = FUN_0011a6f0(lVar6,&local_b0,0), iVar3 != 0 ||
                        (iVar3 = FUN_0011b8a0(lVar6,&local_c8), iVar3 != 0)) ||
                       (iVar3 = FUN_0011b8a0(lVar6,&local_c0), iVar3 != 0)))))) {
LAB_0012d4d0:
          lVar8 = 0;
          iVar3 = -4;
          local_f8 = (ECDSA_SIG *)0x0;
        }
        else {
          lVar8 = FUN_0010c3d0(lVar6);
          if (lVar8 == 0) {
            iVar3 = FUN_0011d220(local_d0,&local_e0);
            if ((iVar3 != 0) || (iVar3 = FUN_0011d220(local_d0,&local_d8), iVar3 != 0))
            goto LAB_0012d4d0;
            lVar8 = FUN_0010c3d0(local_d0);
            if (lVar8 == 0) {
              local_f8 = ECDSA_SIG_new();
              if (local_f8 == (ECDSA_SIG *)0x0) {
                lVar8 = 0;
                iVar3 = -2;
              }
              else {
                iVar3 = ECDSA_SIG_set0(local_f8,local_e0,local_d8);
                if (iVar3 == 0) {
                  lVar8 = 0;
                  iVar3 = -0x16;
                }
                else {
                  local_d8 = (BIGNUM *)0x0;
                  local_e0 = (BIGNUM *)0x0;
                  lVar8 = FUN_0010b880();
                  if (lVar8 == 0) {
                    iVar3 = -2;
                  }
                  else {
                    if (bVar2) {
                      iVar3 = FUN_0012cbd0(param_4,param_5,local_b0,local_c8,local_e5,local_c0,
                                           local_a8,lVar8);
                    }
                    else {
                      iVar3 = FUN_00130740(2,param_4,param_5,local_a8,0x20);
                    }
                    if (iVar3 == 0) {
                      pcVar1 = *(char **)(param_1 + 0x18);
                      sVar9 = strlen(pcVar1);
                      iVar3 = FUN_00130740(2,pcVar1,sVar9,local_88,0x20);
                      if (((((iVar3 == 0) && (iVar3 = FUN_0011a9d0(lVar8,local_88,0x20), iVar3 == 0)
                            ) && (iVar3 = FUN_0011b180(lVar8,local_e5), iVar3 == 0)) &&
                          ((iVar3 = FUN_0011afb0(lVar8,local_e4), iVar3 == 0 &&
                           (iVar3 = FUN_0011aad0(lVar8,local_c0), iVar3 == 0)))) &&
                         (iVar3 = FUN_0011a9d0(lVar8,local_a8,0x20), iVar3 == 0)) {
                        iVar4 = FUN_00130870(2,lVar8,local_68,0x20);
                        iVar3 = iVar4;
                        if (iVar4 == 0) {
                          eckey = *(EC_KEY **)(param_1 + 8);
                          *puVar7 = local_e4;
                          *(undefined1 *)(puVar7 + 1) = local_e5;
                          iVar5 = ECDSA_do_verify(local_68,0x20,local_f8,eckey);
                          if (iVar5 == 0) {
                            iVar3 = -0x15;
                          }
                          else {
                            iVar3 = -0x16;
                            if ((iVar5 == 1) && (iVar3 = iVar4, param_7 != (undefined8 *)0x0)) {
                              *param_7 = puVar7;
                              puVar7 = (undefined4 *)0x0;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              goto LAB_0012cfd9;
            }
          }
          lVar8 = 0;
          iVar3 = -0x17;
          local_f8 = (ECDSA_SIG *)0x0;
        }
        goto LAB_0012cfd9;
      }
    }
LAB_0012cfb0:
    lVar8 = 0;
    iVar3 = -4;
    local_f8 = (ECDSA_SIG *)0x0;
  }
LAB_0012cfd9:
  __explicit_bzero_chk(&local_e5,1,1);
  __explicit_bzero_chk(&local_e4,4,4);
  __explicit_bzero_chk(local_a8,0x20,0x20);
  __explicit_bzero_chk(local_68,0x20,0x20);
  __explicit_bzero_chk(local_88,0x20,0x20);
  FUN_00119560(puVar7);
  FUN_0010bce0(local_c8);
  FUN_0010bce0(local_c0);
  free(local_b0);
  FUN_0010bce0(lVar8);
  FUN_0010bce0(local_d0);
  FUN_0010bce0(lVar6);
  ECDSA_SIG_free(local_f8);
  BN_clear_free(local_e0);
  BN_clear_free(local_d8);
  free(local_b8);
LAB_0012d0bd:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_ed25519_sk_verify @ 0x2d610

ulong ssh_ed25519_sk_verify(undefined4 *param_1,long param_2,long param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6,undefined8 *param_7)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  char *__s1;
  long lVar4;
  size_t sVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  void *pvVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  long in_FS_OFFSET;
  undefined1 auVar12 [16];
  undefined1 local_ad;
  undefined4 local_ac;
  char *local_a8;
  undefined8 local_a0;
  ulong local_98;
  size_t local_90;
  undefined1 local_88 [32];
  undefined1 local_68 [40];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_a8 = (char *)0x0;
  local_90 = 0;
  if (param_7 != (undefined8 *)0x0) {
    *param_7 = 0;
  }
  if (param_1 != (undefined4 *)0x0) {
    iVar2 = FUN_0010f440(*param_1);
    if ((((iVar2 == 0xc) && (*(long *)(param_1 + 0xc) != 0)) && (param_2 != 0)) && (param_3 != 0)) {
      lVar3 = FUN_0010b980(param_2,param_3);
      if (lVar3 == 0) {
        uVar11 = 0xfffffffe;
        goto LAB_0012d6ff;
      }
      iVar2 = FUN_0011a6f0(lVar3,&local_a8,0);
      if (iVar2 == 0) {
        iVar2 = FUN_0011a460(lVar3,&local_a0,&local_98);
        if (iVar2 != 0) goto LAB_0012d6d1;
        iVar2 = FUN_00119e50(lVar3,&local_ad);
        if (iVar2 != 0) goto LAB_0012d6d1;
        iVar2 = FUN_00119cd0(lVar3,&local_ac);
        pcVar1 = local_a8;
        if (iVar2 != 0) goto LAB_0012d6d1;
        __s1 = (char *)FUN_0010f8b0(param_1);
        iVar2 = strcmp(__s1,pcVar1);
        if (iVar2 == 0) {
          lVar4 = FUN_0010c3d0(lVar3);
          if (lVar4 == 0) {
            if (0x40 < local_98) goto LAB_0012d6d1;
            pcVar1 = *(char **)(param_1 + 0x18);
            sVar5 = strlen(pcVar1);
            iVar2 = FUN_00130740(2,pcVar1,sVar5,local_88,0x20);
            if (iVar2 == 0) {
              iVar2 = FUN_00130740(2,param_4,param_5,local_68,0x20);
              if (iVar2 == 0) {
                puVar6 = calloc(1,8);
                if (puVar6 == (undefined4 *)0x0) {
                  lVar4 = 0;
                  uVar11 = 0xfffffffe;
                }
                else {
                  uVar11 = 0xfffffffe;
                  *puVar6 = local_ac;
                  *(undefined1 *)(puVar6 + 1) = local_ad;
                  lVar4 = FUN_0010b880();
                  if (lVar4 != 0) {
                    iVar2 = FUN_0011a9d0(lVar4,local_a0,local_98);
                    if (iVar2 == 0) {
                      iVar2 = FUN_0011a9d0(lVar4,local_88,0x20);
                      if (iVar2 == 0) {
                        iVar2 = FUN_0011b180(lVar4,local_ad);
                        if (iVar2 == 0) {
                          iVar2 = FUN_0011afb0(lVar4,local_ac);
                          if (iVar2 == 0) {
                            iVar2 = FUN_0011a9d0(lVar4,local_68,0x20);
                            if (iVar2 == 0) {
                              uVar7 = FUN_0010c520(lVar4);
                              sVar5 = FUN_0010c3d0(lVar4);
                              local_90 = sVar5;
                              pvVar8 = malloc(sVar5);
                              if (pvVar8 != (void *)0x0) {
                                auVar12 = FUN_00130cf0(pvVar8,&local_90,uVar7,sVar5,
                                                       *(undefined8 *)(param_1 + 0xc));
                                uVar9 = auVar12._8_8_;
                                uVar10 = auVar12._0_8_;
                                uVar11 = uVar10 & 0xffffffff;
                                if (auVar12._0_4_ == 0) {
                                  uVar10 = uVar9;
                                  if (sVar5 - local_98 == local_90) {
                                    if (param_7 != (undefined8 *)0x0) {
                                      *param_7 = puVar6;
                                      puVar6 = (undefined4 *)0x0;
                                    }
                                  }
                                  else {
                                    uVar11 = 0xffffffeb;
                                  }
                                }
                                else {
                                  uVar11 = 0xffffffeb;
                                  FUN_001203a0("ssh-ed25519-sk.c","ssh_ed25519_sk_verify",0x8e,1,6,0
                                               ,"crypto_sign_ed25519_open failed: %d");
                                }
                                FUN_0013b0d0(pvVar8,sVar5,uVar10);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                goto LAB_0012d6dd;
              }
            }
            puVar6 = (undefined4 *)0x0;
            uVar11 = 0xfffffff6;
            lVar4 = 0;
          }
          else {
            puVar6 = (undefined4 *)0x0;
            uVar11 = 0xffffffe9;
            lVar4 = 0;
          }
        }
        else {
          puVar6 = (undefined4 *)0x0;
          uVar11 = 0xfffffff3;
          lVar4 = 0;
        }
      }
      else {
LAB_0012d6d1:
        puVar6 = (undefined4 *)0x0;
        uVar11 = 0xfffffffc;
        lVar4 = 0;
      }
LAB_0012d6dd:
      FUN_00119560(puVar6);
      FUN_0010bce0(lVar3);
      FUN_0010bce0(lVar4);
      free(local_a8);
      goto LAB_0012d6ff;
    }
  }
  uVar11 = 0xfffffff6;
LAB_0012d6ff:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar11;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: rsa_hash_alg_ident @ 0x2daa0

char * rsa_hash_alg_ident(int param_1)

{
  char *pcVar1;
  
  pcVar1 = "rsa-sha2-256";
  if (((param_1 != 2) && (pcVar1 = "rsa-sha2-512", param_1 != 4)) &&
     (pcVar1 = "ssh-rsa", param_1 != 1)) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}



// Function: rsa_hash_alg_nid @ 0x2db50

undefined4 rsa_hash_alg_nid(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 - 1U < 4) {
    uVar1 = *(undefined4 *)(&DAT_00140d60 + (ulong)(param_1 - 1U) * 4);
  }
  return uVar1;
}



// Function: rsa_hash_id_from_ident @ 0x2dbf0

int rsa_hash_id_from_ident(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = strcmp(param_1,"ssh-rsa");
  iVar2 = 1;
  if (iVar1 != 0) {
    iVar1 = strcmp(param_1,"rsa-sha2-256");
    iVar2 = 2;
    if (iVar1 != 0) {
      iVar1 = strcmp(param_1,"rsa-sha2-512");
      iVar2 = (-(uint)(iVar1 == 0) & 5) - 1;
    }
  }
  return iVar2;
}



// Function: rsa_hash_id_from_keyname @ 0x2dcd0

int rsa_hash_id_from_keyname(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0012dbf0();
  if (iVar1 == -1) {
    iVar2 = strcmp(param_1,"ssh-rsa-cert-v01@openssh.com");
    if (iVar2 == 0) {
      return 1;
    }
    iVar2 = strcmp(param_1,"rsa-sha2-256-cert-v01@openssh.com");
    if (iVar2 == 0) {
      iVar1 = 2;
    }
    else {
      iVar2 = strcmp(param_1,"rsa-sha2-512-cert-v01@openssh.com");
      if (iVar2 == 0) {
        iVar1 = 4;
      }
    }
  }
  return iVar1;
}



// Function: openssh_RSA_verify @ 0x2e0b0

int openssh_RSA_verify(ulong param_1,undefined8 param_2,long param_3,uchar *param_4,long param_5,
                RSA *param_6)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  uchar *to;
  ulong __size;
  long in_FS_OFFSET;
  long local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_50 = 0;
  local_48 = 0;
  iVar2 = FUN_0012de60(param_1,&local_48,&local_50);
  if (iVar2 == 0) {
    lVar5 = FUN_00130050(param_1 & 0xffffffff);
    if (lVar5 == param_3) {
      iVar2 = RSA_size(param_6);
      __size = (ulong)iVar2;
      if ((__size - 1 < 0x800) && (param_5 - 1U < __size)) {
        to = malloc(__size);
        if (to == (uchar *)0x0) {
          iVar2 = -2;
        }
        else {
          iVar3 = RSA_public_decrypt((int)param_5,param_4,to,param_6,1);
          lVar1 = local_50;
          iVar2 = -0x16;
          if ((-1 < iVar3) && (iVar2 = -4, (long)iVar3 == local_50 + lVar5)) {
            iVar3 = FUN_0013c1c0(to,local_48,local_50);
            iVar4 = FUN_0013c1c0(to + lVar1,param_2,lVar5);
            iVar2 = 0;
            if (iVar3 != 0 || iVar4 != 0) {
              iVar2 = -0x15;
            }
          }
        }
      }
      else {
        to = (uchar *)0x0;
        iVar2 = -10;
      }
    }
    else {
      to = (uchar *)0x0;
      __size = 0;
      iVar2 = -10;
    }
    FUN_0013b0d0(to,__size);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



// Function: ssh_rsa_complete_crt_parameters @ 0x2e2e0

undefined4 ssh_rsa_complete_crt_parameters(undefined4 *param_1,BIGNUM *param_2)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *rem;
  BIGNUM *m;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  long in_FS_OFFSET;
  BIGNUM *local_68;
  BIGNUM *local_60;
  BIGNUM *local_58;
  BIGNUM *local_50;
  BIGNUM *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 2) == 0)) ||
     (iVar1 = FUN_0010f440(*param_1), iVar1 != 0)) {
    uVar3 = 0xfffffff6;
    goto LAB_0012e44f;
  }
  RSA_get0_key(*(undefined8 *)(param_1 + 2),0,0,&local_48);
  RSA_get0_factors(*(undefined8 *)(param_1 + 2),&local_58,&local_50);
  ctx = BN_CTX_new();
  if (((ctx == (BN_CTX *)0x0) || (r = BN_new(), r == (BIGNUM *)0x0)) ||
     ((rem = BN_new(), rem == (BIGNUM *)0x0 || (local_68 = BN_new(), local_68 == (BIGNUM *)0x0)))) {
    uVar3 = 0xfffffffe;
    goto LAB_0012e44f;
  }
  m = BN_dup(local_48);
  if (m == (BIGNUM *)0x0) {
    local_60 = (BIGNUM *)0x0;
    uVar3 = 0xfffffffe;
  }
  else {
    local_60 = BN_dup(param_2);
    if (local_60 == (BIGNUM *)0x0) {
      uVar3 = 0xfffffffe;
    }
    else {
      BN_set_flags(r,4);
      BN_set_flags(m,4);
      pBVar2 = BN_value_one();
      iVar1 = BN_sub(r,local_50,pBVar2);
      if ((iVar1 != 0) && (iVar1 = BN_div((BIGNUM *)0x0,rem,m,r,ctx), iVar1 != 0)) {
        pBVar2 = BN_value_one();
        iVar1 = BN_sub(r,local_58,pBVar2);
        if ((iVar1 != 0) && (iVar1 = BN_div((BIGNUM *)0x0,local_68,m,r,ctx), iVar1 != 0)) {
          iVar1 = RSA_set0_crt_params(*(undefined8 *)(param_1 + 2),local_68,rem,local_60);
          if (iVar1 == 0) {
            uVar3 = 0xffffffea;
          }
          else {
            local_60 = (BIGNUM *)0x0;
            local_68 = (BIGNUM *)0x0;
            rem = (BIGNUM *)0x0;
            uVar3 = 0;
          }
          goto LAB_0012e41c;
        }
      }
      uVar3 = 0xffffffea;
    }
  }
LAB_0012e41c:
  BN_clear_free(r);
  BN_clear_free(m);
  BN_clear_free(local_68);
  BN_clear_free(rem);
  BN_clear_free(local_60);
  BN_CTX_free(ctx);
LAB_0012e44f:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_rsa_sign @ 0x2e5c0

int ssh_rsa_sign(undefined4 *param_1,undefined8 *param_2,ulong *param_3,undefined8 param_4,
                undefined8 param_5,char *param_6)

{
  int iVar1;
  uint m_length;
  int iVar2;
  size_t sVar3;
  uchar *sigret;
  long lVar4;
  undefined8 uVar5;
  void *pvVar6;
  ulong uVar7;
  ulong __size;
  long in_FS_OFFSET;
  uint local_94;
  BIGNUM *local_90;
  uchar local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 != (ulong *)0x0) {
    *param_3 = 0;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_6 == (char *)0x0) {
LAB_0012e62a:
    if ((param_1 != (undefined4 *)0x0) && (*(long *)(param_1 + 2) != 0)) {
      iVar2 = 1;
LAB_0012e644:
      iVar1 = FUN_0010f440(*param_1);
      if (iVar1 == 0) {
        RSA_get0_key(*(undefined8 *)(param_1 + 2),&local_90,0,0);
        iVar1 = BN_num_bits(local_90);
        if (iVar1 < 0x400) {
          iVar1 = -0x38;
          goto LAB_0012e707;
        }
        iVar1 = RSA_size(*(RSA **)(param_1 + 2));
        __size = (ulong)iVar1;
        if (__size - 1 < 0x800) {
          m_length = FUN_00130050(iVar2);
          if (m_length == 0) {
            iVar1 = -1;
            goto LAB_0012e707;
          }
          iVar1 = FUN_00130740(iVar2,param_4,param_5,local_88,0x40);
          if (iVar1 == 0) {
            sigret = malloc(__size);
            if (sigret == (uchar *)0x0) {
              lVar4 = 0;
              iVar1 = -2;
            }
            else {
              iVar1 = FUN_0012db50(iVar2);
              iVar1 = RSA_sign(iVar1,local_88,m_length,sigret,&local_94,*(RSA **)(param_1 + 2));
              if (iVar1 == 1) {
                uVar7 = (ulong)local_94;
                if (uVar7 < __size) {
                  memmove(sigret + (__size - uVar7),sigret,uVar7);
                  __explicit_bzero_chk(sigret,__size - uVar7,0xffffffffffffffff);
                }
                else if (__size < uVar7) {
                  lVar4 = 0;
                  iVar1 = -1;
                  goto LAB_0012e6d8;
                }
                lVar4 = FUN_0010b880();
                iVar1 = -2;
                if (lVar4 != 0) {
                  uVar5 = FUN_0012daa0(iVar2);
                  iVar1 = FUN_0011b800(lVar4,uVar5);
                  if (iVar1 == 0) {
                    iVar1 = FUN_0011b6c0(lVar4,sigret,__size);
                    if (iVar1 == 0) {
                      local_94 = FUN_0010c3d0(lVar4);
                      if (param_2 != (undefined8 *)0x0) {
                        pvVar6 = malloc((ulong)local_94);
                        *param_2 = pvVar6;
                        if (pvVar6 == (void *)0x0) {
                          iVar1 = -2;
                          goto LAB_0012e6d8;
                        }
                        uVar7 = (ulong)local_94;
                        pvVar6 = (void *)FUN_0010c520(lVar4);
                        memcpy((void *)*param_2,pvVar6,uVar7);
                      }
                      if (param_3 != (ulong *)0x0) {
                        *param_3 = (ulong)local_94;
                      }
                    }
                  }
                }
              }
              else {
                lVar4 = 0;
                iVar1 = -0x16;
              }
            }
          }
          else {
            lVar4 = 0;
            sigret = (uchar *)0x0;
          }
LAB_0012e6d8:
          __explicit_bzero_chk(local_88,0x40,0x40);
          FUN_0013b0d0(sigret,__size);
          FUN_0010bce0(lVar4);
          goto LAB_0012e707;
        }
      }
    }
  }
  else {
    sVar3 = strlen(param_6);
    if (sVar3 == 0) goto LAB_0012e62a;
    iVar2 = FUN_0012dcd0(param_6);
    if (((param_1 != (undefined4 *)0x0) && (*(long *)(param_1 + 2) != 0)) && (iVar2 != -1))
    goto LAB_0012e644;
  }
  iVar1 = -10;
LAB_0012e707:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_rsa_verify @ 0x2e980

int ssh_rsa_verify(undefined4 *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5
                ,char *param_6)

{
  ulong uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong __size;
  long in_FS_OFFSET;
  BIGNUM *local_a8;
  void *local_a0;
  ulong local_98;
  void *local_90;
  undefined1 local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_a0 = (void *)0x0;
  local_98 = 0;
  local_90 = (void *)0x0;
  if ((((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 2) == 0)) ||
      (iVar3 = FUN_0010f440(*param_1), iVar3 != 0)) || ((param_2 == 0 || (param_3 == 0)))) {
    iVar3 = -10;
    goto LAB_0012eb1b;
  }
  RSA_get0_key(*(undefined8 *)(param_1 + 2),&local_a8,0,0);
  iVar3 = BN_num_bits(local_a8);
  if (iVar3 < 0x400) {
    iVar3 = -0x38;
    goto LAB_0012eb1b;
  }
  lVar5 = FUN_0010b980(param_2,param_3);
  if (lVar5 == 0) {
    iVar3 = -2;
    goto LAB_0012eb1b;
  }
  iVar3 = FUN_0011a6f0(lVar5,&local_a0,0);
  if (iVar3 == 0) {
    iVar4 = FUN_0012dbf0(local_a0);
    if (iVar4 == -1) {
      iVar3 = -0xd;
    }
    else if ((param_6 == (char *)0x0) ||
            (iVar3 = strcmp(param_6,"ssh-rsa-cert-v01@openssh.com"), iVar3 == 0)) {
LAB_0012eac0:
      iVar3 = FUN_0011a590(lVar5,&local_90,&local_98);
      if (iVar3 != 0) goto LAB_0012eada;
      lVar6 = FUN_0010c3d0(lVar5);
      if (lVar6 == 0) {
        iVar3 = RSA_size(*(RSA **)(param_1 + 2));
        pvVar2 = local_90;
        uVar1 = local_98;
        __size = (ulong)iVar3;
        if (__size < local_98) {
          iVar3 = -0xb;
          local_90 = pvVar2;
        }
        else {
          if (local_98 < __size) {
            local_90 = realloc(local_90,__size);
            if (local_90 == (void *)0x0) {
              iVar3 = -2;
              local_90 = pvVar2;
              goto LAB_0012eaef;
            }
            memmove((void *)((long)local_90 + (__size - uVar1)),local_90,local_98);
            __explicit_bzero_chk(local_90,__size - uVar1,0xffffffffffffffff);
            local_98 = __size;
          }
          lVar6 = FUN_00130050(iVar4);
          if (lVar6 == 0) {
            iVar3 = -1;
          }
          else {
            iVar3 = FUN_00130740(iVar4,param_4,param_5,local_88,0x40);
            if (iVar3 == 0) {
              iVar3 = FUN_0012e0b0(iVar4,local_88,lVar6,local_90,local_98,
                                   *(undefined8 *)(param_1 + 2));
            }
          }
        }
      }
      else {
        iVar3 = -0x17;
      }
    }
    else {
      iVar3 = FUN_0012dcd0(param_6);
      if (iVar3 == -1) {
        iVar3 = -10;
      }
      else {
        if (iVar4 == iVar3) goto LAB_0012eac0;
        iVar3 = -0x15;
      }
    }
  }
  else {
LAB_0012eada:
    iVar3 = -4;
  }
LAB_0012eaef:
  FUN_0013b0d0(local_90,local_98);
  free(local_a0);
  FUN_0010bce0(lVar5);
  __explicit_bzero_chk(local_88,0x40,0x40);
LAB_0012eb1b:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



// Function: ssh_msg_send @ 0x2eda0

undefined8 ssh_msg_send(undefined4 param_1,byte param_2,undefined8 param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  int *piVar5;
  long in_FS_OFFSET;
  undefined1 auVar6 [16];
  char *pcVar7;
  undefined1 local_45 [4];
  byte local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = FUN_0010c3d0(param_3);
  uVar4 = (ulong)param_2;
  pcVar7 = "type %u";
  FUN_001203a0("msg.c","ssh_msg_send",0x32,1,7,0);
  FUN_00126a10(local_45,uVar2 + 1);
  puVar1 = PTR_write_00167fd8;
  local_41 = param_2;
  auVar6 = FUN_00132ef0(PTR_write_00167fd8,param_1,local_45,5);
  if (auVar6._0_8_ == 5) {
    uVar3 = FUN_0010c7c0(param_3,uVar4,auVar6._8_8_,pcVar7);
    uVar4 = FUN_00132ef0(puVar1,param_1,uVar3,(ulong)uVar2);
    if (uVar4 == uVar2) {
      uVar3 = 0;
      goto LAB_0012ee78;
    }
    piVar5 = __errno_location();
    pcVar7 = strerror(*piVar5);
    uVar3 = 0x3b;
  }
  else {
    piVar5 = __errno_location();
    pcVar7 = strerror(*piVar5);
    uVar3 = 0x37;
  }
  FUN_001203a0("msg.c","ssh_msg_send",uVar3,1,2,0,"write: %s",pcVar7);
  uVar3 = 0xffffffff;
LAB_0012ee78:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_msg_recv @ 0x2ef90

undefined4 ssh_msg_recv(undefined4 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  int *piVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined4 uVar9;
  long in_FS_OFFSET;
  char *pcVar10;
  undefined8 local_50;
  undefined1 local_44 [4];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_001203a0("msg.c","ssh_msg_recv",0x48,0,7,0,"ssh_msg_recv entering");
  lVar3 = FUN_00132ef0(PTR_read_00167fb0,param_1,local_44,4);
  if (lVar3 == 4) {
    uVar1 = FUN_001267d0(local_44);
    uVar8 = (ulong)uVar1;
    uVar4 = FUN_0010bf80(param_2);
    if (uVar4 < uVar8) {
      uVar5 = 0;
      pcVar10 = "read: bad msg_len %u";
      uVar7 = 0x51;
    }
    else {
      FUN_0010be60(param_2);
      iVar2 = FUN_0010cb20(param_2,uVar8,&local_50);
      if (iVar2 == 0) {
        uVar4 = FUN_00132ef0(PTR_read_00167fb0,param_1,local_50,uVar8);
        uVar9 = 0;
        if (uVar8 == uVar4) goto LAB_0012f070;
        piVar6 = __errno_location();
        strerror(*piVar6);
        uVar5 = 0;
        uVar7 = 0x5a;
        pcVar10 = "read: %s";
      }
      else {
        uVar5 = FUN_0010b050(iVar2);
        uVar7 = 0x56;
        pcVar10 = "reserve";
      }
    }
    uVar9 = 0xffffffff;
    FUN_001203a0("msg.c","ssh_msg_recv",uVar7,1,2,uVar5,pcVar10);
  }
  else {
    piVar6 = __errno_location();
    uVar9 = 0xffffffff;
    if (*piVar6 != 0x20) {
      pcVar10 = strerror(*piVar6);
      FUN_001203a0("msg.c","ssh_msg_recv",0x4c,1,2,0,"read header: %s",pcVar10);
    }
  }
LAB_0012f070:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: chachapoly_free @ 0x2f1f0

undefined8 chachapoly_free(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)*param_1);
    EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)param_1[1]);
    uVar1 = FUN_0013b0d0(param_1,0x10);
    return uVar1;
  }
  return 0;
}



// Function: chachapoly_new @ 0x2f2a0

undefined8 * chachapoly_new(uchar *param_1,int param_2)

{
  int iVar1;
  undefined8 *puVar2;
  EVP_CIPHER_CTX *pEVar3;
  EVP_CIPHER *pEVar4;
  
  if ((param_2 == 0x40) && (puVar2 = calloc(1,0x10), puVar2 != (undefined8 *)0x0)) {
    pEVar3 = EVP_CIPHER_CTX_new();
    *puVar2 = pEVar3;
    if (pEVar3 != (EVP_CIPHER_CTX *)0x0) {
      pEVar3 = EVP_CIPHER_CTX_new();
      puVar2[1] = pEVar3;
      if (pEVar3 != (EVP_CIPHER_CTX *)0x0) {
        pEVar4 = (EVP_CIPHER *)EVP_chacha20();
        iVar1 = EVP_CipherInit((EVP_CIPHER_CTX *)*puVar2,pEVar4,param_1,(uchar *)0x0,1);
        if (iVar1 != 0) {
          pEVar4 = (EVP_CIPHER *)EVP_chacha20();
          iVar1 = EVP_CipherInit((EVP_CIPHER_CTX *)puVar2[1],pEVar4,param_1 + 0x20,(uchar *)0x0,1);
          if ((iVar1 != 0) && (iVar1 = EVP_CIPHER_CTX_get_iv_length(puVar2[1]), iVar1 == 0x10)) {
            return puVar2;
          }
        }
      }
    }
    FUN_0012f1f0(puVar2);
  }
  return (undefined8 *)0x0;
}



// Function: chachapoly_crypt @ 0x2f3e0

int chachapoly_crypt(undefined8 *param_1,uint param_2,uchar *param_3,uchar *param_4,uint param_5,
                uint param_6,undefined8 param_7,int param_8)

{
  int iVar1;
  long in_FS_OFFSET;
  uchar local_88 [12];
  uint local_7c;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  long local_40;
  
  local_7c = param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 | param_2 << 0x18
  ;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_88[0] = '\0';
  local_88[1] = '\0';
  local_88[2] = '\0';
  local_88[3] = '\0';
  local_88[4] = '\0';
  local_88[5] = '\0';
  local_88[6] = '\0';
  local_88[7] = '\0';
  local_88[8] = '\0';
  local_88[9] = '\0';
  local_88[10] = '\0';
  local_88[0xb] = '\0';
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  iVar1 = EVP_CipherInit((EVP_CIPHER_CTX *)*param_1,(EVP_CIPHER *)0x0,(uchar *)0x0,local_88,1);
  if ((iVar1 != 0) &&
     (iVar1 = EVP_Cipher((EVP_CIPHER_CTX *)*param_1,local_68,local_68,0x20), -1 < iVar1)) {
    if (param_8 == 0) {
      FUN_001331f0(local_78,param_4,param_6 + param_5,local_68);
      iVar1 = FUN_0013c1c0(local_78,param_4 + (ulong)param_6 + (ulong)param_5,0x10);
      if (iVar1 != 0) {
        param_8 = -0x1e;
        goto LAB_0012f4fa;
      }
    }
    if ((param_6 == 0) ||
       ((iVar1 = EVP_CipherInit((EVP_CIPHER_CTX *)param_1[1],(EVP_CIPHER *)0x0,(uchar *)0x0,local_88
                                ,1), iVar1 != 0 &&
        (iVar1 = EVP_Cipher((EVP_CIPHER_CTX *)param_1[1],param_3,param_4,param_6), -1 < iVar1)))) {
      local_88[0] = 1;
      iVar1 = EVP_CipherInit((EVP_CIPHER_CTX *)*param_1,(EVP_CIPHER *)0x0,(uchar *)0x0,local_88,1);
      if (iVar1 != 0) {
        iVar1 = EVP_Cipher((EVP_CIPHER_CTX *)*param_1,param_3 + param_6,param_4 + param_6,param_5);
        if (-1 < iVar1) {
          if (param_8 != 0) {
            FUN_001331f0(param_3 + (ulong)param_5 + (ulong)param_6,param_3,param_6 + param_5,
                         local_68);
            param_8 = 0;
          }
          goto LAB_0012f4fa;
        }
      }
    }
  }
  param_8 = -0x16;
LAB_0012f4fa:
  __explicit_bzero_chk(local_78,0x10,0x10);
  __explicit_bzero_chk(local_88,0x10,0x10);
  __explicit_bzero_chk(local_68,0x20,0x20);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_8;
}



// Function: chachapoly_get_length @ 0x2f6d0

undefined8 chachapoly_get_length(long param_1,uint *param_2,uint param_3,uchar *param_4,uint param_5)

{
  int iVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  uint local_3c;
  uchar local_38 [12];
  uint local_2c;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_5 < 4) {
    uVar2 = 0xfffffffd;
  }
  else {
    local_2c = param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 |
               param_3 << 0x18;
    local_38[0] = '\0';
    local_38[1] = '\0';
    local_38[2] = '\0';
    local_38[3] = '\0';
    local_38[4] = '\0';
    local_38[5] = '\0';
    local_38[6] = '\0';
    local_38[7] = '\0';
    local_38[8] = '\0';
    local_38[9] = '\0';
    local_38[10] = '\0';
    local_38[0xb] = '\0';
    iVar1 = EVP_CipherInit(*(EVP_CIPHER_CTX **)(param_1 + 8),(EVP_CIPHER *)0x0,(uchar *)0x0,local_38
                           ,0);
    if (iVar1 != 0) {
      iVar1 = EVP_Cipher(*(EVP_CIPHER_CTX **)(param_1 + 8),(uchar *)&local_3c,param_4,4);
      if (-1 < iVar1) {
        *param_2 = local_3c >> 0x18 | (local_3c & 0xff0000) >> 8 | (local_3c & 0xff00) << 8 |
                   local_3c << 0x18;
        uVar2 = 0;
        goto LAB_0012f75c;
      }
    }
    uVar2 = 0xffffffea;
  }
LAB_0012f75c:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_ed25519_sign @ 0x2f820

int ssh_ed25519_sign(undefined4 *param_1,undefined8 *param_2,size_t *param_3,undefined8 param_4,
                ulong param_5)

{
  size_t __size;
  int iVar1;
  void *pvVar2;
  long lVar3;
  size_t __size_00;
  void *pvVar4;
  long in_FS_OFFSET;
  size_t local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 != (size_t *)0x0) {
    *param_3 = 0;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = FUN_0010f440(*param_1);
    if (((iVar1 == 3) && (*(long *)(param_1 + 10) != 0)) && (param_5 < 0x7fffffbf)) {
      __size = param_5 + 0x40;
      local_48 = __size;
      pvVar2 = malloc(__size);
      if (pvVar2 == (void *)0x0) {
        iVar1 = -2;
        goto LAB_0012f8ff;
      }
      iVar1 = FUN_00130a90(pvVar2,&local_48,param_4,param_5,*(undefined8 *)(param_1 + 10));
      if ((iVar1 == 0) && (param_5 < local_48)) {
        lVar3 = FUN_0010b880();
        iVar1 = -2;
        if (lVar3 != 0) {
          iVar1 = FUN_0011b800(lVar3,"ssh-ed25519");
          if (iVar1 == 0) {
            iVar1 = FUN_0011b6c0(lVar3,pvVar2,local_48 - param_5);
            if (iVar1 == 0) {
              __size_00 = FUN_0010c3d0(lVar3);
              if (param_2 != (undefined8 *)0x0) {
                pvVar4 = malloc(__size_00);
                *param_2 = pvVar4;
                if (pvVar4 == (void *)0x0) {
                  iVar1 = -2;
                  goto LAB_0012f8ec;
                }
                pvVar4 = (void *)FUN_0010c520(lVar3);
                memcpy((void *)*param_2,pvVar4,__size_00);
              }
              if (param_3 != (size_t *)0x0) {
                *param_3 = __size_00;
              }
            }
          }
        }
      }
      else {
        lVar3 = 0;
        iVar1 = -10;
      }
LAB_0012f8ec:
      FUN_0010bce0(lVar3);
      FUN_0013b0d0(pvVar2,__size);
      goto LAB_0012f8ff;
    }
  }
  iVar1 = -10;
LAB_0012f8ff:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_ed25519_verify @ 0x2fa90

ulong ssh_ed25519_verify(undefined4 *param_1,long param_2,long param_3,void *param_4,ulong param_5)

{
  size_t __size;
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  void *pvVar5;
  void *pvVar6;
  ulong uVar7;
  ulong uVar8;
  long in_FS_OFFSET;
  undefined1 auVar9 [16];
  char *local_60;
  void *local_58;
  ulong local_50;
  ulong local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_60 = (char *)0x0;
  local_48 = 0;
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = FUN_0010f440(*param_1);
    if ((((iVar1 == 3) && (*(long *)(param_1 + 0xc) != 0)) && (param_5 < 0x7fffffbf && param_2 != 0)
        ) && (param_3 != 0)) {
      lVar3 = FUN_0010b980(param_2,param_3);
      if (lVar3 == 0) {
        uVar8 = 0xfffffffe;
      }
      else {
        uVar2 = FUN_0011a6f0(lVar3,&local_60,0);
        uVar8 = (ulong)uVar2;
        if (uVar2 == 0) {
          uVar2 = FUN_0011a460(lVar3,&local_58,&local_50);
          uVar8 = (ulong)uVar2;
          if (uVar2 == 0) {
            uVar8 = 0xfffffff3;
            iVar1 = strcmp("ssh-ed25519",local_60);
            if (iVar1 == 0) {
              uVar8 = 0xffffffe9;
              lVar4 = FUN_0010c3d0(lVar3);
              if (lVar4 == 0) {
                uVar8 = 0xfffffffc;
                if (local_50 < 0x41) {
                  __size = local_50 + param_5;
                  local_48 = __size;
                  pvVar5 = malloc(__size);
                  if (pvVar5 == (void *)0x0) {
                    uVar8 = 0xfffffffe;
                  }
                  else {
                    pvVar6 = malloc(local_48);
                    if (pvVar6 == (void *)0x0) {
                      uVar8 = 0xfffffffe;
                      FUN_0013b0d0(pvVar5,__size);
                    }
                    else {
                      pvVar5 = memcpy(pvVar5,local_58,local_50);
                      memcpy((void *)((long)pvVar5 + local_50),param_4,param_5);
                      auVar9 = FUN_00130cf0(pvVar6,&local_48,pvVar5,__size,
                                            *(undefined8 *)(param_1 + 0xc));
                      uVar7 = auVar9._0_8_;
                      uVar8 = uVar7 & 0xffffffff;
                      if (auVar9._0_4_ == 0) {
                        uVar7 = auVar9._8_8_;
                        if (local_48 != param_5) {
                          uVar8 = 0xffffffeb;
                        }
                      }
                      else {
                        uVar8 = 0xffffffeb;
                        FUN_001203a0("ssh-ed25519.c","ssh_ed25519_verify",0x8f,1,6,0,
                                     "crypto_sign_ed25519_open failed: %d");
                      }
                      FUN_0013b0d0(pvVar5,__size,uVar7);
                      FUN_0013b0d0(pvVar6,__size);
                    }
                  }
                }
              }
            }
          }
        }
        FUN_0010bce0(lVar3);
        free(local_60);
      }
      goto LAB_0012fb5b;
    }
  }
  uVar8 = 0xfffffff6;
LAB_0012fb5b:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_digest_by_alg @ 0x2fdb0

uint * ssh_digest_by_alg(uint param_1)

{
  uint *puVar1;
  
  if (param_1 < 5) {
    puVar1 = (uint *)0x0;
    if ((*(uint *)(&DAT_00167560 + (long)(int)param_1 * 0x20) == param_1) &&
       ((&PTR_EVP_md5_00167578)[(long)(int)param_1 * 4] != (undefined *)0x0)) {
      puVar1 = (uint *)(&DAT_00167560 + (long)(int)param_1 * 0x20);
    }
    return puVar1;
  }
  return (uint *)0x0;
}



// Function: ssh_digest_alg_by_name @ 0x2fef0

int ssh_digest_alg_by_name(char *param_1)

{
  int iVar1;
  undefined *puVar2;
  char *__s2;
  int iVar3;
  
  __s2 = "MD5";
  iVar3 = 0;
  puVar2 = &DAT_00167560;
  while( true ) {
    iVar1 = strcasecmp(param_1,__s2);
    if (iVar1 == 0) {
      return iVar3;
    }
    iVar3 = *(int *)(puVar2 + 0x20);
    if (iVar3 == -1) break;
    __s2 = *(char **)(puVar2 + 0x28);
    puVar2 = puVar2 + 0x20;
  }
  return -1;
}



// Function: ssh_digest_alg_name @ 0x2ffc0

undefined8 ssh_digest_alg_name(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_0012fdb0();
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 8);
  }
  return uVar2;
}



// Function: ssh_digest_bytes @ 0x30050

undefined8 ssh_digest_bytes(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_0012fdb0();
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0x10);
  }
  return uVar2;
}



// Function: ssh_digest_blocksize @ 0x300f0

long ssh_digest_blocksize(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = EVP_MD_CTX_get0_md(*(undefined8 *)(param_1 + 8));
  iVar1 = EVP_MD_get_block_size(uVar2);
  return (long)iVar1;
}



// Function: ssh_digest_copy_state @ 0x30190

uint ssh_digest_copy_state(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 == *param_2) {
    iVar1 = EVP_MD_CTX_copy_ex(*(EVP_MD_CTX **)(param_2 + 2),*(EVP_MD_CTX **)(param_1 + 2));
    return -(uint)(iVar1 == 0) & 0xffffffea;
  }
  return 0xfffffff6;
}



// Function: ssh_digest_update @ 0x302d0

undefined8 ssh_digest_update(long param_1,void *param_2,size_t param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = EVP_DigestUpdate(*(EVP_MD_CTX **)(param_1 + 8),param_2,param_3);
  uVar2 = 0;
  if (iVar1 != 1) {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



// Function: ssh_digest_update_buffer @ 0x30380

void ssh_digest_update_buffer(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_0010c3d0(param_2);
  uVar2 = FUN_0010c520(param_2);
  FUN_001302d0(param_1,uVar2,uVar1);
  return;
}



// Function: ssh_digest_final @ 0x303c0

undefined8 ssh_digest_final(undefined4 *param_1,uchar *param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  uint local_34;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = FUN_0012fdb0(*param_1);
  local_34 = (uint)param_3;
  if (((lVar2 == 0) || (param_3 >> 0x20 != 0)) || (param_3 < *(ulong *)(lVar2 + 0x10))) {
    uVar3 = 0xfffffff6;
  }
  else {
    iVar1 = EVP_DigestFinal_ex(*(EVP_MD_CTX **)(param_1 + 2),param_2,&local_34);
    if (iVar1 == 1) {
      uVar3 = FUN_0013dae0((ulong)local_34 != *(ulong *)(lVar2 + 0x10));
    }
    else {
      uVar3 = 0xffffffea;
    }
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_digest_free @ 0x30500

undefined8 ssh_digest_free(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    EVP_MD_CTX_free(*(undefined8 *)(param_1 + 8));
    uVar1 = FUN_0013b0d0(param_1,0x10);
    return uVar1;
  }
  return 0;
}



// Function: ssh_digest_start @ 0x305b0

undefined4 * ssh_digest_start(undefined4 param_1)

{
  int iVar1;
  long lVar2;
  undefined4 *__ptr;
  long lVar3;
  EVP_MD *type;
  undefined4 *puVar4;
  
  lVar2 = FUN_0012fdb0();
  if ((lVar2 != 0) && (__ptr = calloc(1,0x10), __ptr != (undefined4 *)0x0)) {
    *__ptr = param_1;
    lVar3 = EVP_MD_CTX_new();
    *(long *)(__ptr + 2) = lVar3;
    if (lVar3 == 0) {
      puVar4 = (undefined4 *)0x0;
      free(__ptr);
    }
    else {
      type = (EVP_MD *)(**(code **)(lVar2 + 0x18))();
      iVar1 = EVP_DigestInit_ex(*(EVP_MD_CTX **)(__ptr + 2),type,(ENGINE *)0x0);
      puVar4 = __ptr;
      if (iVar1 != 1) {
        FUN_00130500(__ptr);
        return (undefined4 *)0x0;
      }
    }
    return puVar4;
  }
  return (undefined4 *)0x0;
}



// Function: ssh_digest_memory @ 0x30740

uint ssh_digest_memory(undefined8 param_1,void *param_2,size_t param_3,uchar *param_4,ulong param_5)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  EVP_MD *type;
  long in_FS_OFFSET;
  uint local_34;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = FUN_0012fdb0();
  if (((lVar3 == 0) || (param_5 >> 0x20 != 0)) || (param_5 < *(ulong *)(lVar3 + 0x10))) {
    uVar2 = 0xfffffff6;
  }
  else {
    local_34 = (uint)param_5;
    type = (EVP_MD *)(**(code **)(lVar3 + 0x18))();
    iVar1 = EVP_Digest(param_2,param_3,param_4,&local_34,type,(ENGINE *)0x0);
    uVar2 = -(uint)(iVar1 == 0) & 0xffffffea;
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ssh_digest_buffer @ 0x30870

void ssh_digest_buffer(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_0010c3d0(param_2);
  uVar2 = FUN_0010c520(param_2);
  FUN_00130740(param_1,uVar2,uVar1,param_3,param_4);
  return;
}



// Function: get_hram @ 0x308c0

void get_hram(undefined8 param_1,long param_2,long param_3,long param_4,ulong param_5)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = 0;
  do {
    *(undefined1 *)(param_4 + lVar1) = *(undefined1 *)(param_2 + lVar1);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  do {
    *(undefined1 *)(param_4 + lVar1) = *(undefined1 *)(param_3 + -0x20 + lVar1);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x40);
  uVar2 = 0x40;
  if (0x40 < param_5) {
    do {
      *(undefined1 *)(param_4 + uVar2) = *(undefined1 *)(param_2 + uVar2);
      uVar2 = uVar2 + 1;
    } while (param_5 != uVar2);
  }
  FUN_001310d0(param_1);
  return;
}



// Function: crypto_sign_ed25519_keypair @ 0x30930

undefined8 crypto_sign_ed25519_keypair(long param_1,long param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined1 auStack_2f8 [128];
  undefined1 local_278 [512];
  byte local_78 [31];
  byte local_59;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  thunk_FUN_00138930(param_2,0x20);
  FUN_001310d0(local_78,param_2,0x20);
  local_78[0] = local_78[0] & 0xf8;
  local_59 = local_59 & 0x7f | 0x40;
  FUN_00133b20(auStack_2f8,local_78);
  FUN_00135eb0(local_278,auStack_2f8);
  FUN_001358b0(param_1,local_278);
  lVar1 = 0;
  do {
    *(undefined1 *)(param_2 + 0x20 + lVar1) = *(undefined1 *)(param_1 + lVar1);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519 @ 0x30a90

undefined8 crypto_sign_ed25519(long param_1,long *param_2,long param_3,long param_4,long param_5)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined1 local_4c8 [128];
  undefined1 local_448 [128];
  undefined1 local_3c8 [128];
  undefined1 local_348 [512];
  undefined1 local_148 [32];
  undefined1 local_128 [32];
  byte local_108 [31];
  byte local_e9;
  undefined1 local_e8 [32];
  undefined1 local_c8 [64];
  undefined1 local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_001310d0(local_108,param_5,0x20);
  local_108[0] = local_108[0] & 0xf8;
  *param_2 = param_4 + 0x40;
  local_e9 = local_e9 & 0x7f | 0x40;
  if (param_4 != 0) {
    lVar1 = 0;
    do {
      *(undefined1 *)(param_1 + 0x40 + lVar1) = *(undefined1 *)(param_3 + lVar1);
      lVar1 = lVar1 + 1;
    } while (param_4 != lVar1);
  }
  lVar1 = 0;
  do {
    *(undefined1 *)(param_1 + 0x20 + lVar1) = local_e8[lVar1];
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  FUN_001310d0(local_c8,param_1 + 0x20,param_4 + 0x20);
  FUN_00133cd0(local_4c8,local_c8);
  FUN_00135eb0(local_348,local_4c8);
  FUN_001358b0(local_148,local_348);
  lVar1 = 0;
  do {
    *(undefined1 *)(param_1 + lVar1) = local_148[lVar1];
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  FUN_001308c0(local_88,param_1,param_5 + 0x20,param_1,param_4 + 0x40);
  FUN_00133cd0(local_448,local_88);
  FUN_00133b20(local_3c8,local_108);
  FUN_001343c0(local_448,local_448,local_3c8);
  FUN_001342b0(local_448,local_448,local_4c8);
  FUN_00133e80(local_128,local_448);
  lVar1 = 0;
  do {
    *(undefined1 *)(param_1 + 0x20 + lVar1) = local_128[lVar1];
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_open @ 0x30cf0

undefined8 crypto_sign_ed25519_open(long param_1,ulong *param_2,long param_3,ulong param_4,undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  undefined1 local_5a8 [128];
  undefined1 local_528 [128];
  undefined1 local_4a8 [512];
  undefined1 local_2a8 [512];
  undefined1 local_a8 [32];
  undefined1 local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  *param_2 = 0xffffffffffffffff;
  if (0x3f < param_4) {
    iVar1 = FUN_001355f0(local_4a8,param_5);
    if (iVar1 == 0) {
      FUN_001308c0(local_88,param_3,param_5,param_1,param_4);
      FUN_00133cd0(local_5a8,local_88);
      FUN_00133b20(local_528,param_3 + 0x20);
      FUN_00135ab0(local_2a8,local_4a8,local_5a8,&DAT_0015b8c0,local_528);
      FUN_001358b0(local_a8,local_2a8);
      uVar2 = FUN_00130f00(param_3,local_a8);
      param_4 = param_4 - 0x40;
      if ((int)uVar2 == 0) {
        if (param_4 != 0) {
          uVar3 = 0;
          do {
            *(undefined1 *)(param_1 + uVar3) = *(undefined1 *)(param_3 + (ulong)((int)uVar3 + 0x40))
            ;
            uVar3 = (ulong)((int)uVar3 + 1);
          } while (uVar3 < param_4);
        }
        *param_2 = param_4;
      }
      else {
        uVar3 = 0;
        if (param_4 != 0) {
          do {
            *(undefined1 *)(param_1 + uVar3) = 0;
            uVar3 = (ulong)((int)uVar3 + 1);
          } while (uVar3 < param_4);
        }
      }
      goto LAB_00130e1d;
    }
  }
  uVar2 = 0xffffffff;
LAB_00130e1d:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



// Function: crypto_verify_32 @ 0x30f00

int crypto_verify_32(byte *param_1,byte *param_2)

{
  return -1 - ((int)((byte)(*param_1 ^ *param_2 | param_1[1] ^ param_2[1] | param_1[2] ^ param_2[2]
                            | param_1[3] ^ param_2[3] | param_1[4] ^ param_2[4] |
                            param_1[5] ^ param_2[5] | param_1[6] ^ param_2[6] |
                            param_1[7] ^ param_2[7] | param_1[8] ^ param_2[8] |
                            param_1[9] ^ param_2[9] | param_1[10] ^ param_2[10] |
                            param_1[0xb] ^ param_2[0xb] | param_1[0xc] ^ param_2[0xc] |
                            param_1[0xd] ^ param_2[0xd] | param_1[0xe] ^ param_2[0xe] |
                            param_1[0xf] ^ param_2[0xf] | param_1[0x10] ^ param_2[0x10] |
                            param_1[0x11] ^ param_2[0x11] | param_1[0x12] ^ param_2[0x12] |
                            param_1[0x13] ^ param_2[0x13] | param_1[0x14] ^ param_2[0x14] |
                            param_1[0x15] ^ param_2[0x15] | param_1[0x16] ^ param_2[0x16] |
                            param_1[0x17] ^ param_2[0x17] | param_1[0x18] ^ param_2[0x18] |
                            param_1[0x19] ^ param_2[0x19] | param_1[0x1a] ^ param_2[0x1a] |
                            param_1[0x1b] ^ param_2[0x1b] | param_1[0x1c] ^ param_2[0x1c] |
                            param_1[0x1d] ^ param_2[0x1d] | param_1[0x1e] ^ param_2[0x1e] |
                           param_1[0x1f] ^ param_2[0x1f]) - 1) >> 0x1f);
}



// Function: crypto_hash_sha512 @ 0x310d0

undefined8 crypto_hash_sha512(uchar *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  EVP_MD *type;
  
  type = EVP_sha512();
  iVar1 = EVP_Digest(param_2,param_3,param_1,(uint *)0x0,type,(ENGINE *)0x0);
  FUN_0013dae0(iVar1 == 0);
  return 0;
}



// Function: platform_sys_dir_uid @ 0x31190

bool platform_sys_dir_uid(int param_1)

{
  return param_1 == 0;
}



// Function: cleanup_exit @ 0x31220

void cleanup_exit(int param_1)

{
                    /* WARNING: Subroutine does not return */
  _exit(param_1);
}



// Function: masklen_valid @ 0x31230

undefined8 masklen_valid(int param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (param_1 != 2) {
    uVar1 = 0xffffffff;
    if (param_1 == 10) {
      uVar1 = FUN_0013dae0(0x80 < param_2);
    }
    return uVar1;
  }
  uVar1 = FUN_0013dae0(0x20 < param_2);
  return uVar1;
}



// Function: addr_unicast_masklen @ 0x31490

undefined8 addr_unicast_masklen(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x20;
  if ((param_1 != 2) && (uVar1 = 0xffffffff, param_1 == 10)) {
    uVar1 = 0x80;
  }
  return uVar1;
}



// Function: addr_xaddr_to_sa @ 0x31530

undefined8 addr_xaddr_to_sa(short *param_1,undefined1 (*param_2) [16],uint *param_3,undefined2 param_4)

{
  undefined8 uVar1;
  undefined2 uVar2;
  
  if ((param_1 != (short *)0x0 && param_3 != (uint *)0x0) && (param_2 != (undefined1 (*) [16])0x0))
  {
    if (*param_1 == 2) {
      if (0xf < *param_3) {
        *param_2 = (undefined1  [16])0x0;
        *param_3 = 0x10;
        *(undefined2 *)*param_2 = 2;
        uVar2 = FUN_00131370(param_4);
        *(undefined2 *)(*param_2 + 2) = uVar2;
        *(undefined4 *)(*param_2 + 4) = *(undefined4 *)(param_1 + 2);
        return 0;
      }
    }
    else if ((*param_1 == 10) && (0x1b < *param_3)) {
      *(undefined8 *)param_2[1] = 0;
      *param_2 = (undefined1  [16])0x0;
      *(undefined4 *)(param_2[1] + 8) = 0;
      *param_3 = 0x1c;
      *(undefined2 *)*param_2 = 10;
      uVar2 = FUN_00131370(param_4);
      *(undefined2 *)(*param_2 + 2) = uVar2;
      uVar1 = *(undefined8 *)(param_1 + 6);
      *(undefined8 *)(*param_2 + 8) = *(undefined8 *)(param_1 + 2);
      *(undefined8 *)param_2[1] = uVar1;
      *(undefined4 *)(param_2[1] + 8) = *(undefined4 *)(param_1 + 10);
      return 0;
    }
  }
  return 0xffffffff;
}



// Function: addr_sa_to_xaddr @ 0x31790

undefined8 addr_sa_to_xaddr(short *param_1,uint param_2,undefined1 (*param_3) [16])

{
  undefined8 uVar1;
  
  *(undefined8 *)param_3[1] = 0;
  *param_3 = (undefined1  [16])0x0;
  if (*param_1 == 2) {
    if (0xf < param_2) {
      *(undefined2 *)*param_3 = 2;
      *(undefined4 *)(*param_3 + 4) = *(undefined4 *)(param_1 + 2);
      return 0;
    }
  }
  else if ((*param_1 == 10) && (0x1b < param_2)) {
    *(undefined2 *)*param_3 = 10;
    uVar1 = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)(*param_3 + 4) = *(undefined8 *)(param_1 + 4);
    *(undefined8 *)(*param_3 + 0xc) = uVar1;
    *(undefined4 *)(param_3[1] + 4) = *(undefined4 *)(param_1 + 0xc);
    return 0;
  }
  return 0xffffffff;
}



// Function: addr_invert @ 0x31980

undefined8 addr_invert(short *param_1)

{
  uint *puVar1;
  
  if (param_1 != (short *)0x0) {
    if (*param_1 == 2) {
      *(uint *)(param_1 + 2) = ~*(uint *)(param_1 + 2);
      return 0;
    }
    if (*param_1 == 10) {
      puVar1 = (uint *)(param_1 + 2);
      do {
        *puVar1 = ~*puVar1;
        puVar1 = puVar1 + 1;
      } while (puVar1 != (uint *)(param_1 + 10));
      return 0;
    }
  }
  return 0xffffffff;
}



// Function: addr_netmask @ 0x31b50

undefined8 addr_netmask(int param_1,uint param_2,undefined1 (*param_3) [16])

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  
  iVar2 = FUN_00131230();
  if ((param_3 == (undefined1 (*) [16])0x0) || (iVar2 != 0)) {
    return 0xffffffff;
  }
  *(undefined8 *)param_3[1] = 0;
  *param_3 = (undefined1  [16])0x0;
  if (param_1 == 2) {
    *(undefined2 *)*param_3 = 2;
    if (param_2 != 0) {
      uVar3 = FUN_00131400(-1 << (0x20U - (char)param_2 & 0x1f));
      *(undefined4 *)(*param_3 + 4) = uVar3;
    }
  }
  else {
    if (param_1 != 10) {
      return 0xffffffff;
    }
    *(undefined2 *)*param_3 = 10;
    if (param_2 < 0x20) {
      lVar5 = 0;
      bVar1 = true;
    }
    else {
      lVar4 = 1;
      do {
        param_2 = param_2 - 0x20;
        *(undefined4 *)(*param_3 + lVar4 * 4) = 0xffffffff;
        lVar5 = (long)(int)lVar4;
        bVar1 = (int)lVar4 < 4;
        lVar4 = lVar4 + 1;
        if (param_2 < 0x20) break;
      } while (bVar1);
    }
    if ((param_2 != 0) && (bVar1)) {
      uVar3 = FUN_00131400(-1 << (0x20U - (char)param_2 & 0x1f));
      *(undefined4 *)(*param_3 + lVar5 * 4 + 4) = uVar3;
      return 0;
    }
  }
  return 0;
}



// Function: addr_hostmask @ 0x31dd0

undefined8 addr_hostmask(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = FUN_00131b50();
  if (iVar1 != -1) {
    iVar1 = FUN_00131980(param_3);
    FUN_0013dae0(iVar1 == -1);
  }
  return 0;
}



// Function: addr_and @ 0x31e80

undefined8 addr_and(undefined8 *param_1,short *param_2,short *param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  if (((param_2 != (short *)0x0 && param_3 != (short *)0x0) && (param_1 != (undefined8 *)0x0)) &&
     (*param_2 == *param_3)) {
    uVar1 = *(undefined8 *)(param_2 + 4);
    *param_1 = *(undefined8 *)param_2;
    param_1[1] = uVar1;
    param_1[2] = *(undefined8 *)(param_2 + 8);
    if (*param_2 == 2) {
      *(uint *)((long)param_1 + 4) = *(uint *)((long)param_1 + 4) & *(uint *)(param_3 + 2);
      return 0;
    }
    if (*param_2 == 10) {
      *(undefined4 *)((long)param_1 + 0x14) = *(undefined4 *)(param_2 + 10);
      lVar2 = 4;
      do {
        *(uint *)((long)param_1 + lVar2) =
             *(uint *)((long)param_1 + lVar2) & *(uint *)((long)param_3 + lVar2);
        lVar2 = lVar2 + 4;
      } while (lVar2 != 0x14);
      return 0;
    }
  }
  return 0xffffffff;
}



// Function: addr_cmp @ 0x32090

ulong addr_cmp(short *param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  
  sVar1 = *param_1;
  if (sVar1 != *param_2) {
    return (ulong)(((sVar1 == 10) - 1) + (uint)(sVar1 == 10));
  }
  if (sVar1 == 2) {
    iVar2 = *(int *)(param_2 + 2);
    uVar6 = 0;
    if (*(int *)(param_1 + 2) != iVar2) {
      uVar3 = FUN_00131400();
      uVar4 = FUN_00131400(iVar2);
      return (ulong)((-(uint)(uVar4 < uVar3) & 2) - 1);
    }
  }
  else if (sVar1 == 10) {
    lVar5 = 4;
    do {
      if (*(char *)((long)param_1 + lVar5) != *(char *)((long)param_2 + lVar5)) {
        uVar6 = FUN_0013da60(*(char *)((long)param_1 + lVar5),*(char *)((long)param_2 + lVar5));
        return uVar6;
      }
      lVar5 = lVar5 + 1;
    } while (lVar5 != 0x14);
    uVar6 = 0;
    if (*(uint *)(param_1 + 10) != *(uint *)(param_2 + 10)) {
      uVar6 = (ulong)((-(uint)(*(uint *)(param_2 + 10) < *(uint *)(param_1 + 10)) & 2) - 1);
    }
  }
  else {
    uVar6 = 0xffffffff;
  }
  return uVar6;
}



// Function: addr_is_all0s @ 0x322d0

undefined8 addr_is_all0s(short *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  
  if (*param_1 == 2) {
    uVar2 = FUN_0013dae0(*(int *)(param_1 + 2) != 0);
    return uVar2;
  }
  if (*param_1 == 10) {
    piVar1 = (int *)(param_1 + 2);
    while (*piVar1 == 0) {
      piVar1 = piVar1 + 1;
      if (piVar1 == (int *)(param_1 + 10)) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}



// Function: addr_host_is_all0s @ 0x324b0

undefined8 addr_host_is_all0s(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined1 local_58 [32];
  undefined1 local_38 [24];
  long local_20;
  
  local_78 = *param_1;
  uStack_70 = param_1[1];
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_68 = param_1[2];
  iVar1 = FUN_00131dd0(*(undefined2 *)param_1,param_2,local_58);
  if (iVar1 != -1) {
    iVar1 = FUN_00131e80(local_38,&local_78,local_58);
    if (iVar1 != -1) {
      uVar2 = FUN_001322d0(local_38);
      goto LAB_0013251e;
    }
  }
  uVar2 = 0xffffffff;
LAB_0013251e:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: addr_pton @ 0x325d0

undefined4 addr_pton(char *param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  long in_FS_OFFSET;
  addrinfo *local_60;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = (undefined1  [16])0x0;
  local_58._4_12_ = SUB1612((undefined1  [16])0x0,4);
  local_58._0_4_ = 4;
  local_38 = (undefined1  [16])0x0;
  if (param_1 != (char *)0x0) {
    iVar1 = getaddrinfo(param_1,(char *)0x0,(addrinfo *)local_58,&local_60);
    if ((iVar1 == 0) && (local_60 != (addrinfo *)0x0)) {
      if (local_60->ai_addr != (sockaddr *)0x0) {
        if (param_2 != 0) {
          iVar1 = FUN_00131790(local_60->ai_addr,local_60->ai_addrlen,param_2);
          if (iVar1 == -1) goto LAB_00132709;
        }
        freeaddrinfo(local_60);
        uVar2 = 0;
        goto LAB_0013266c;
      }
LAB_00132709:
      freeaddrinfo(local_60);
    }
  }
  uVar2 = 0xffffffff;
LAB_0013266c:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: addr_sa_pton @ 0x32730

undefined4 addr_sa_pton(char *param_1,char *param_2,void *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  long in_FS_OFFSET;
  addrinfo *local_70;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = (undefined1  [16])0x0;
  local_68._4_12_ = SUB1612((undefined1  [16])0x0,4);
  local_68._0_4_ = 4;
  local_48 = (undefined1  [16])0x0;
  if (param_1 != (char *)0x0) {
    iVar1 = getaddrinfo(param_1,param_2,(addrinfo *)local_68,&local_70);
    if ((iVar1 == 0) && (local_70 != (addrinfo *)0x0)) {
      if (local_70->ai_addr != (sockaddr *)0x0) {
        if (param_3 != (void *)0x0) {
          if (param_4 < local_70->ai_addrlen) goto LAB_00132870;
          memcpy(param_3,&local_70->ai_addr,(ulong)local_70->ai_addrlen);
        }
        freeaddrinfo(local_70);
        uVar2 = 0;
        goto LAB_001327ce;
      }
LAB_00132870:
      freeaddrinfo(local_70);
    }
  }
  uVar2 = 0xffffffff;
LAB_001327ce:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: addr_ntop @ 0x32890

undefined8 addr_ntop(undefined8 param_1,char *param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  socklen_t local_ac;
  sockaddr local_a8 [8];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_ac = 0x80;
  uVar2 = FUN_00131530(param_1,local_a8,&local_ac,0);
  if ((int)uVar2 != -1) {
    if ((param_2 == (char *)0x0) || (param_3 == 0)) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar1 = getnameinfo(local_a8,local_ac,param_2,(socklen_t)param_3,(char *)0x0,0,1);
      uVar2 = FUN_0013dae0(iVar1 == -1);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: addr_pton_cidr @ 0x329d0

undefined8 addr_pton_cidr(long param_1,undefined8 *param_2,undefined4 *param_3)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  long in_FS_OFFSET;
  char *local_a0;
  undefined2 local_98;
  undefined6 uStack_96;
  undefined8 uStack_90;
  undefined8 local_88;
  char local_78 [72];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 != 0) {
    uVar2 = FUN_0013bee0(local_78,param_1,0x40);
    if (uVar2 < 0x40) {
      pcVar3 = strchr(local_78,0x2f);
      if (pcVar3 == (char *)0x0) {
        iVar1 = FUN_001325d0(local_78,&local_98);
        uVar5 = local_98;
        if (iVar1 != -1) {
          iVar1 = FUN_00131490(local_98);
          uVar2 = (ulong)iVar1;
          goto LAB_00132a9a;
        }
      }
      else {
        *pcVar3 = '\0';
        uVar2 = strtoul(pcVar3 + 1,&local_a0,10);
        if (((((byte)(pcVar3[1] - 0x30U) < 10) && (*local_a0 == '\0')) && (uVar2 < 0x81)) &&
           (iVar1 = FUN_001325d0(local_78,&local_98), uVar5 = local_98, iVar1 != -1)) {
LAB_00132a9a:
          iVar1 = FUN_00131230(uVar5,uVar2 & 0xffffffff);
          if ((iVar1 == -1) || (uVar4 = FUN_001324b0(&local_98,uVar2 & 0xffffffff), (int)uVar4 != 0)
             ) {
            uVar4 = 0xfffffffe;
          }
          else {
            if (param_2 != (undefined8 *)0x0) {
              param_2[2] = local_88;
              *param_2 = CONCAT62(uStack_96,local_98);
              param_2[1] = uStack_90;
            }
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = (int)uVar2;
            }
          }
          goto LAB_00132ae0;
        }
      }
    }
  }
  uVar4 = 0xffffffff;
LAB_00132ae0:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



// Function: addr_netmatch @ 0x32bd0

undefined8 addr_netmatch(short *param_1,short *param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  undefined1 auStack_68 [32];
  undefined1 local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (*param_1 == *param_2) {
    iVar1 = FUN_00131b50(*param_1,param_3,auStack_68);
    if (iVar1 != -1) {
      iVar1 = FUN_00131e80(local_48,param_1,auStack_68);
      if (iVar1 != -1) {
        uVar2 = FUN_00132090(local_48,param_2);
        goto LAB_00132c3e;
      }
    }
  }
  uVar2 = 0xffffffff;
LAB_00132c3e:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: atomicio6 @ 0x32cf0

ulong atomicio6(code *param_1,int param_2,long param_3,ulong param_4,code *param_5,
                  undefined8 param_6)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  ulong uVar4;
  long in_FS_OFFSET;
  pollfd local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_48.events = (ushort)(param_1 != (code *)PTR_read_00167fb0) * 3 + 1;
  local_48.fd = param_2;
  if (param_4 == 0) {
LAB_00132e74:
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    do {
      lVar2 = (*param_1)(param_2,param_3 + uVar4,param_4 - uVar4);
      if (lVar2 == -1) {
        piVar3 = __errno_location();
        if (*piVar3 == 4) {
          if (param_5 != (code *)0x0) {
            iVar1 = (*param_5)(param_6,0);
            if (iVar1 == -1) {
              *piVar3 = 4;
              break;
            }
          }
        }
        else {
          if (*piVar3 != 0xb) goto LAB_00132e74;
          poll(&local_48,1,-1);
        }
      }
      else {
        if (lVar2 == 0) {
          piVar3 = __errno_location();
          *piVar3 = 0x20;
          break;
        }
        uVar4 = uVar4 + lVar2;
        if (param_5 != (code *)0x0) {
          iVar1 = (*param_5)(param_6,lVar2);
          if (iVar1 == -1) {
            piVar3 = __errno_location();
            *piVar3 = 4;
            break;
          }
        }
      }
    } while (uVar4 < param_4);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: atomicio @ 0x32ef0

void atomicio(void)

{
  FUN_00132cf0();
  return;
}



// Function: atomiciov6 @ 0x32f00

long atomiciov6(code *param_1,undefined4 param_2,undefined8 param_3,uint param_4,
                 undefined8 param_5,undefined8 param_6)

{
  ulong uVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  long *plVar5;
  ulong uVar6;
  undefined1 *puVar7;
  ulong uVar8;
  long lVar9;
  long in_FS_OFFSET;
  undefined1 local_4030 [16384];
  
  puVar2 = &stack0xffffffffffffffd0;
  do {
    puVar7 = puVar2;
    *(undefined8 *)(puVar7 + -0x1000) = *(undefined8 *)(puVar7 + -0x1000);
    puVar2 = puVar7 + -0x1000;
  } while (puVar7 + -0x1000 != local_4030);
  *(undefined4 *)(puVar7 + -0x1044) = param_2;
  *(undefined8 *)(puVar7 + -0x1040) = param_5;
  *(undefined8 *)(puVar7 + -0x1038) = param_6;
  *(undefined8 *)(puVar7 + 0x2ff0) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  if (param_4 < 0x401) {
    *(undefined8 *)(puVar7 + -0x1050) = 0x13302f;
    plVar5 = (long *)__memcpy_chk(puVar7 + -0x1018,param_3,(long)(int)param_4 << 4,0x4000);
    *(undefined4 *)(puVar7 + -0x1020) = *(undefined4 *)(puVar7 + -0x1044);
    *(ushort *)(puVar7 + -0x101c) = (ushort)(param_1 != (code *)PTR_readv_00167fe0) * 3 + 1;
    if (param_4 == 0) {
LAB_00133120:
      lVar9 = 0;
    }
    else {
      lVar9 = 0;
      *(undefined1 **)(puVar7 + -0x1030) = puVar7 + -0x1020;
LAB_00133068:
      do {
        do {
          while( true ) {
            if (plVar5[1] == 0) goto LAB_00132f66;
            *(undefined8 *)(puVar7 + -0x1050) = 0x13307f;
            uVar6 = (*param_1)(*(undefined4 *)(puVar7 + -0x1044),plVar5,param_4);
            if (uVar6 == 0xffffffffffffffff) break;
            if (uVar6 == 0) {
              *(undefined8 *)(puVar7 + -0x1050) = 0x133135;
              piVar4 = __errno_location();
              *piVar4 = 0x20;
              goto LAB_00132f66;
            }
            lVar9 = lVar9 + uVar6;
            uVar8 = uVar6;
            while (uVar1 = plVar5[1], uVar1 <= uVar8) {
              uVar8 = uVar8 - uVar1;
              plVar5 = plVar5 + 2;
              *(undefined8 *)(puVar7 + -0x1050) = 0x1330c1;
              param_4 = FUN_0013da20(param_4,0xffffffff);
              if (param_4 == 0) {
                if (uVar8 != 0) {
                  *(undefined8 *)(puVar7 + -0x1050) = 0x1331ce;
                  piVar4 = __errno_location();
                  *piVar4 = 0xe;
                  goto LAB_00133120;
                }
                if (*(code **)(puVar7 + -0x1040) == (code *)0x0) goto LAB_00132f66;
                *(undefined8 *)(puVar7 + -0x1050) = 0x1330e9;
                iVar3 = (**(code **)(puVar7 + -0x1040))(*(undefined8 *)(puVar7 + -0x1038),uVar6);
                if (iVar3 != -1) goto LAB_00132f66;
                goto LAB_001330f2;
              }
            }
            if (uVar8 != 0) {
              *plVar5 = *plVar5 + uVar8;
              plVar5[1] = uVar1 - uVar8;
            }
            if (*(long *)(puVar7 + -0x1040) != 0) {
              *(undefined8 *)(puVar7 + -0x1050) = 0x13319b;
              iVar3 = (**(code **)(puVar7 + -0x1040))(*(undefined8 *)(puVar7 + -0x1038),uVar6);
              if (iVar3 == -1) {
LAB_001330f2:
                *(undefined8 *)(puVar7 + -0x1050) = 0x1330f7;
                piVar4 = __errno_location();
                *piVar4 = 4;
                goto LAB_00132f66;
              }
            }
          }
          *(undefined8 *)(puVar7 + -0x1050) = 0x13310d;
          piVar4 = __errno_location();
          if (*piVar4 != 4) {
            if (*piVar4 != 0xb) goto LAB_00133120;
            *(undefined8 *)(puVar7 + -0x1050) = 0x1331c4;
            poll(*(pollfd **)(puVar7 + -0x1030),1,-1);
            goto LAB_00133068;
          }
        } while (*(code **)(puVar7 + -0x1040) == (code *)0x0);
        *(undefined8 *)(puVar7 + -0x1050) = 0x133157;
        iVar3 = (**(code **)(puVar7 + -0x1040))(*(undefined8 *)(puVar7 + -0x1038),0);
      } while (iVar3 != -1);
      *piVar4 = 4;
    }
  }
  else {
    *(undefined8 *)(puVar7 + -0x1050) = 0x132f5d;
    piVar4 = __errno_location();
    lVar9 = 0;
    *piVar4 = 0x16;
  }
LAB_00132f66:
  if (*(long *)(puVar7 + 0x2ff0) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar7 + -0x1050) = &UNK_001331de;
    __stack_chk_fail();
  }
  return lVar9;
}



// Function: atomiciov @ 0x331e0

void atomiciov(void)

{
  FUN_00132f00();
  return;
}



// Function: poly1305_auth @ 0x331f0

undefined8 poly1305_auth(undefined4 *param_1,ulong *param_2,ulong param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar15;
  uint uVar16;
  uint uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  ulong uVar22;
  uint uVar23;
  uint uVar25;
  ulong uVar27;
  long in_FS_OFFSET;
  uint local_94;
  uint local_90;
  uint local_8c;
  ulong *local_78;
  uint local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_40;
  ulong uVar8;
  ulong uVar12;
  ulong uVar14;
  ulong uVar17;
  ulong uVar24;
  ulong uVar26;
  
  uVar15 = 0;
  uVar18 = 0;
  uVar13 = 0;
  uVar25 = 0;
  uVar6 = 0;
  uVar23 = 0;
  uVar11 = 0;
  uVar10 = 0;
  uVar1 = param_4[4];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar16 = *param_4;
  uVar2 = param_4[1];
  uVar7 = param_4[2];
  uVar9 = param_4[3];
  uVar3 = 0;
  if (0xf < param_3) {
    local_94 = param_4[5];
    local_90 = param_4[6];
    local_8c = param_4[7];
    do {
      local_78 = param_2 + 2;
      param_3 = param_3 - 0x10;
      uVar3 = uVar3 + ((uint)*param_2 & 0x3ffffff);
      uVar13 = ((uint)(*param_2 >> 0x1a) & 0x3ffffff) + uVar13;
      uVar11 = ((uint)(*(ulong *)((long)param_2 + 4) >> 0x14) & 0x3ffffff) + uVar11;
      uVar6 = ((uint)(param_2[1] >> 0xe) & 0x3ffffff) + uVar6;
      uVar15 = uVar15 + (*(uint *)((long)param_2 + 0xc) >> 8 | 0x1000000);
      while( true ) {
        uVar17 = (ulong)uVar15;
        uVar14 = (ulong)uVar13;
        uVar12 = (ulong)uVar11;
        uVar8 = (ulong)uVar6;
        uVar27 = (ulong)uVar3;
        uVar4 = (ulong)(uVar16 & 0x3ffffff);
        uVar23 = (uVar2 << 6 | uVar16 >> 0x1a) & 0x3ffff03;
        uVar24 = (ulong)uVar23;
        uVar25 = (uVar7 << 0xc | uVar2 >> 0x14) & 0x3ffc0ff;
        uVar26 = (ulong)uVar25;
        uVar22 = (ulong)(uVar25 * 5);
        uVar25 = uVar9 >> 8 & 0xfffff;
        uVar19 = (ulong)(uVar25 * 5);
        uVar10 = (uVar9 << 0x12 | uVar7 >> 0xe) & 0x3f03fff;
        uVar20 = (ulong)(uVar10 * 5);
        uVar21 = uVar8 * uVar22 + uVar14 * uVar19 + uVar27 * uVar4 + uVar12 * uVar20 +
                 (uVar23 * 5) * uVar17;
        uVar22 = uVar22 * uVar17 +
                 uVar19 * uVar12 + uVar8 * uVar20 + uVar4 * uVar14 + uVar27 * uVar24 +
                 (uVar21 >> 0x1a);
        uVar13 = (uint)uVar22 & 0x3ffffff;
        uVar20 = uVar20 * uVar17 +
                 uVar4 * uVar12 + uVar19 * uVar8 + uVar14 * uVar24 + uVar27 * uVar26 +
                 (uVar22 >> 0x1a & 0xffffffff);
        uVar11 = (uint)uVar20 & 0x3ffffff;
        uVar20 = uVar19 * uVar17 +
                 uVar12 * uVar24 + uVar4 * uVar8 + uVar14 * uVar26 + uVar27 * uVar10 +
                 (uVar20 >> 0x1a & 0xffffffff);
        uVar6 = (uint)uVar20 & 0x3ffffff;
        uVar20 = (uVar20 >> 0x1a & 0xffffffff) +
                 uVar4 * uVar17 +
                 uVar25 * uVar27 + uVar14 * uVar10 + uVar8 * uVar24 + uVar12 * uVar26;
        uVar15 = (uint)uVar20 & 0x3ffffff;
        uVar3 = (int)(uVar20 >> 0x1a) * 5 + ((uint)uVar21 & 0x3ffffff);
        param_2 = local_78;
        if (0xf < param_3) break;
        uVar25 = uVar13;
        uVar10 = uVar11;
        uVar23 = uVar6;
        uVar18 = uVar15;
        if (param_3 == 0) goto LAB_001334a0;
LAB_001336ae:
        uVar20 = 0;
        do {
          *(undefined1 *)((long)&local_58 + uVar20) = *(undefined1 *)((long)local_78 + uVar20);
          uVar20 = uVar20 + 1;
        } while (param_3 != uVar20);
        *(undefined1 *)((long)&local_58 + param_3) = 1;
        lVar5 = (long)&local_58 + param_3;
        if (param_3 != 0xf) {
          do {
            *(undefined1 *)(lVar5 + 1) = 0;
            lVar5 = lVar5 + 1;
          } while (lVar5 != (long)&uStack_4c + 3);
        }
        uVar3 = uVar3 + (local_58 & 0x3ffffff);
        uVar13 = ((uint)(CONCAT44(uStack_54,local_58) >> 0x1a) & 0x3ffffff) + uVar25;
        uVar11 = ((uint)(CONCAT44(local_50,uStack_54) >> 0x14) & 0x3ffffff) + uVar10;
        uVar6 = ((uint)(CONCAT44(uStack_4c,local_50) >> 0xe) & 0x3ffffff) + uVar23;
        uVar15 = uVar18 + (uStack_4c >> 8);
        param_3 = 0;
      }
    } while( true );
  }
  local_94 = param_4[5];
  local_90 = param_4[6];
  local_8c = param_4[7];
  local_78 = param_2;
  if (param_3 != 0) goto LAB_001336ae;
LAB_001334a0:
  uVar25 = (uVar3 >> 0x1a) + uVar25;
  uVar10 = (uVar25 >> 0x1a) + uVar10;
  uVar23 = (uVar10 >> 0x1a) + uVar23;
  uVar10 = uVar10 & 0x3ffffff;
  uVar18 = (uVar23 >> 0x1a) + uVar18;
  uVar23 = uVar23 & 0x3ffffff;
  uVar16 = (uVar18 >> 0x1a) * 5 + (uVar3 & 0x3ffffff);
  uVar3 = uVar16 & 0x3ffffff;
  uVar13 = (uVar16 >> 0x1a) + (uVar25 & 0x3ffffff);
  uVar25 = uVar3 + 5;
  uVar7 = (uVar25 >> 0x1a) + uVar13;
  uVar9 = (uVar7 >> 0x1a) + uVar10;
  uVar11 = (uVar9 >> 0x1a) + uVar23;
  uVar6 = (uVar11 >> 0x1a) + (uVar18 | 0xfc000000);
  uVar2 = (int)uVar6 >> 0x1f;
  uVar16 = 0xffffffff - uVar2;
  uVar7 = uVar7 & uVar16 & 0x3ffffff | uVar13 & uVar2;
  uVar9 = uVar9 & uVar16 & 0x3ffffff | uVar10 & uVar2;
  uVar20 = (ulong)(uVar25 & uVar16 & 0x3ffffff | uVar3 & uVar2 | uVar7 << 0x1a) + (ulong)uVar1;
  uVar25 = uVar11 & uVar16 & 0x3ffffff | uVar23 & uVar2;
  *param_1 = (int)uVar20;
  uVar20 = (uVar20 >> 0x20) + (ulong)(uVar7 >> 6 | uVar9 << 0x14) + (ulong)local_94;
  param_1[1] = (int)uVar20;
  lVar5 = (uVar20 >> 0x20) + (ulong)(uVar9 >> 0xc | uVar25 << 0xe) + (ulong)local_90;
  param_1[2] = (int)lVar5;
  param_1[3] = (int)((ulong)lVar5 >> 0x20) +
               ((uVar6 & uVar16 | uVar2 & uVar18 & 0x3ffffff) << 8 | uVar25 >> 0x12) + local_8c;
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: lt @ 0x33750

uint lt(int param_1,int param_2)

{
  return (uint)(param_1 - param_2) >> 0x1f;
}



// Function: reduce_add_sub @ 0x361b0

undefined8 reduce_add_sub(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = 4;
  do {
    uVar2 = param_1[0x1f];
    param_1[0x1f] = uVar2 & 0x7f;
    iVar1 = FUN_00136090(uVar2 >> 7);
    uVar2 = iVar1 + *param_1;
    *param_1 = uVar2;
    puVar3 = param_1;
    while( true ) {
      *puVar3 = *puVar3 & 0xff;
      puVar3[1] = puVar3[1] + (uVar2 >> 8);
      puVar3 = puVar3 + 1;
      if (param_1 + 0x1f == puVar3) break;
      uVar2 = *puVar3;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return 0;
}



// Function: barrett_reduce @ 0x33920

void barrett_reduce(long param_1,long param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  uint *puVar7;
  long lVar8;
  int *piVar9;
  int *piVar10;
  long in_FS_OFFSET;
  int local_268 [36];
  uint local_1d8 [33];
  uint local_154 [3];
  long local_148 [15];
  uint local_cc;
  uint local_c8;
  int local_c4 [33];
  long local_40 [2];
  
  local_40[0] = *(long *)(in_FS_OFFSET + 0x28);
  plVar6 = local_148;
  do {
    *(undefined4 *)plVar6 = 0;
    plVar6 = (long *)((long)plVar6 + 4);
  } while (plVar6 != local_40);
  puVar7 = local_1d8;
  do {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  } while (puVar7 != local_154);
  piVar10 = (int *)&DAT_00140ea0;
  iVar5 = 0x21;
  do {
    piVar9 = (int *)(param_2 + 0x7c);
    iVar3 = iVar5 + -0x21;
    do {
      iVar4 = iVar3;
      if (0x1e < iVar4) {
        piVar1 = (int *)((long)local_148 + (long)iVar4 * 4);
        *piVar1 = *piVar1 + *piVar10 * *piVar9;
      }
      iVar3 = iVar4 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar3 != iVar5);
    iVar5 = iVar4 + 2;
    piVar10 = piVar10 + 1;
  } while (iVar3 != 0x41);
  local_c8 = (local_cc >> 8) + local_c8;
  local_c4[0] = local_c4[0] + (local_c8 >> 8);
  lVar8 = 0;
  do {
    *(undefined4 *)((long)local_268 + lVar8) = *(undefined4 *)(param_2 + lVar8);
    lVar8 = lVar8 + 4;
  } while (lVar8 != 0x84);
  piVar10 = &DAT_00140f40;
  iVar5 = 0x21;
  do {
    piVar9 = (int *)((long)local_148 + 0x84);
    iVar3 = iVar5 + -0x21;
    do {
      iVar4 = iVar3;
      if (iVar4 < 0x21) {
        local_1d8[iVar4] = local_1d8[iVar4] + *piVar10 * *piVar9;
      }
      iVar3 = iVar4 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar3 != iVar5);
    iVar5 = iVar4 + 2;
    piVar10 = piVar10 + 1;
  } while (iVar3 != 0x40);
  puVar7 = local_1d8;
  do {
    uVar2 = *puVar7;
    *puVar7 = uVar2 & 0xff;
    puVar7[1] = puVar7[1] + (uVar2 >> 8);
    puVar7 = puVar7 + 1;
  } while (local_1d8 + 0x20 != puVar7);
  lVar8 = 0;
  iVar5 = 0;
  do {
    iVar3 = *(int *)((long)local_268 + lVar8);
    iVar4 = iVar5 + *(int *)((long)local_1d8 + lVar8);
    iVar5 = FUN_00133750(iVar3,iVar4);
    *(int *)(param_1 + lVar8) = (iVar5 * 0x100 + iVar3) - iVar4;
    lVar8 = lVar8 + 4;
  } while (lVar8 != 0x80);
  FUN_001337e0(param_1);
  if (local_40[0] == *(long *)(in_FS_OFFSET + 0x28)) {
    FUN_001337e0(param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_sc25519_from32bytes @ 0x33b20

undefined8 crypto_sign_ed25519_ref_sc25519_from32bytes(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long in_FS_OFFSET;
  uint local_118 [32];
  undefined4 local_98 [32];
  undefined4 local_18 [2];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = 0;
  do {
    local_118[lVar1] = (uint)*(byte *)(param_2 + lVar1);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  puVar2 = local_98;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (puVar2 != local_18);
  FUN_00133920(param_1,local_118);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_shortsc25519_from16bytes @ 0x33c30

undefined8 crypto_sign_ed25519_ref_shortsc25519_from16bytes(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    *(uint *)(param_1 + lVar1 * 4) = (uint)*(byte *)(param_2 + lVar1);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x10);
  return 0;
}



// Function: crypto_sign_ed25519_ref_sc25519_from64bytes @ 0x33cd0

undefined8 crypto_sign_ed25519_ref_sc25519_from64bytes(undefined8 param_1,long param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  uint local_118 [66];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = 0;
  do {
    local_118[lVar1] = (uint)*(byte *)(param_2 + lVar1);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x40);
  FUN_00133920(param_1,local_118);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_sc25519_from_shortsc @ 0x33dc0

undefined8 crypto_sign_ed25519_ref_sc25519_from_shortsc(long param_1,long param_2)

{
  long lVar1;
  undefined4 *puVar2;
  
  lVar1 = 0;
  do {
    *(undefined4 *)(param_1 + lVar1) = *(undefined4 *)(param_2 + lVar1);
    lVar1 = lVar1 + 4;
  } while (lVar1 != 0x40);
  puVar2 = (undefined4 *)(param_1 + 0x40);
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (puVar2 != (undefined4 *)(param_1 + 0x80));
  return 0;
}



// Function: crypto_sign_ed25519_ref_sc25519_to32bytes @ 0x33e80

undefined8 crypto_sign_ed25519_ref_sc25519_to32bytes(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    *(char *)(param_1 + lVar1) = (char)*(undefined4 *)(param_2 + lVar1 * 4);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  return 0;
}



// Function: crypto_sign_ed25519_ref_sc25519_iszero_vartime @ 0x33f20

undefined8 crypto_sign_ed25519_ref_sc25519_iszero_vartime(int *param_1)

{
  int *piVar1;
  
  piVar1 = param_1 + 0x20;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    param_1 = param_1 + 1;
  } while (param_1 != piVar1);
  return 1;
}



// Function: crypto_sign_ed25519_ref_sc25519_isshort_vartime @ 0x34050

undefined8 crypto_sign_ed25519_ref_sc25519_isshort_vartime(long param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x7c);
  do {
    if (*piVar1 != 0) {
      return 0;
    }
    piVar1 = piVar1 + -1;
  } while (piVar1 != (int *)(param_1 + 0x3c));
  return 1;
}



// Function: crypto_sign_ed25519_ref_sc25519_lt_vartime @ 0x34180

undefined8 crypto_sign_ed25519_ref_sc25519_lt_vartime(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0x7c;
  do {
    if (*(uint *)(param_1 + lVar1) < *(uint *)(param_2 + lVar1)) {
      return 1;
    }
  } while ((*(uint *)(param_1 + lVar1) <= *(uint *)(param_2 + lVar1)) &&
          (lVar1 = lVar1 + -4, lVar1 != -4));
  return 0;
}



// Function: crypto_sign_ed25519_ref_sc25519_add @ 0x342b0

void crypto_sign_ed25519_ref_sc25519_add(uint *param_1,long param_2,long param_3)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = 0;
  do {
    *(int *)((long)param_1 + lVar3) = *(int *)(param_3 + lVar3) + *(int *)(param_2 + lVar3);
    lVar3 = lVar3 + 4;
  } while (lVar3 != 0x80);
  puVar1 = param_1 + 0x1f;
  do {
    uVar2 = *param_1;
    *param_1 = uVar2 & 0xff;
    param_1[1] = param_1[1] + (uVar2 >> 8);
    param_1 = param_1 + 1;
  } while (param_1 != puVar1);
  FUN_001337e0();
  return;
}



// Function: crypto_sign_ed25519_ref_sc25519_sub_nored @ 0x34300

undefined8 crypto_sign_ed25519_ref_sc25519_sub_nored(long param_1,long param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = 0;
  uVar1 = 0;
  do {
    uVar1 = (*(int *)(param_2 + lVar2) - uVar1) - *(int *)(param_3 + lVar2);
    *(uint *)(param_1 + lVar2) = uVar1 & 0xff;
    uVar1 = uVar1 >> 8 & 1;
    lVar2 = lVar2 + 4;
  } while (lVar2 != 0x80);
  return 0;
}



// Function: crypto_sign_ed25519_ref_sc25519_mul @ 0x343c0

undefined8 crypto_sign_ed25519_ref_sc25519_mul(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  long lVar6;
  long lVar7;
  uint *puVar8;
  long in_FS_OFFSET;
  uint local_118 [64];
  undefined4 local_18 [2];
  long local_10;
  
  puVar5 = local_118;
  puVar8 = local_118;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  } while (puVar5 != local_18);
  lVar7 = 0;
  do {
    iVar2 = *(int *)(param_2 + lVar7 * 4);
    lVar6 = 0;
    do {
      lVar1 = lVar6 * 4;
      iVar4 = (int)lVar6;
      lVar6 = lVar6 + 1;
      local_118[iVar4 + (int)lVar7] =
           local_118[iVar4 + (int)lVar7] + *(int *)(param_3 + lVar1) * iVar2;
    } while (lVar6 != 0x20);
    lVar7 = lVar7 + 1;
  } while (lVar7 != 0x20);
  do {
    uVar3 = *puVar8;
    *puVar8 = uVar3 & 0xff;
    puVar8[1] = puVar8[1] + (uVar3 >> 8);
    puVar8 = puVar8 + 1;
  } while (local_118 + 0x3f != puVar8);
  FUN_00133920(param_1,local_118);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_sc25519_mul_shortsc @ 0x34520

undefined8 crypto_sign_ed25519_ref_sc25519_mul_shortsc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long in_FS_OFFSET;
  undefined1 auStack_a8 [136];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00133dc0(auStack_a8,param_3);
  FUN_001343c0(param_1,param_2,auStack_a8);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_sc25519_window3 @ 0x34610

undefined8 crypto_sign_ed25519_ref_sc25519_window3(byte *param_1,uint *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  char cVar3;
  uint *puVar4;
  uint *puVar5;
  byte bVar6;
  
  pbVar1 = param_1;
  puVar4 = param_2;
  do {
    puVar5 = puVar4 + 3;
    *pbVar1 = (byte)*puVar4 & 7;
    pbVar1[1] = (byte)(*puVar4 >> 3) & 7;
    bVar6 = (byte)(*puVar4 >> 6) & 7;
    pbVar1[2] = bVar6;
    pbVar1[2] = ((byte)puVar4[1] & 1) << 2 ^ bVar6;
    pbVar1[3] = (byte)(puVar4[1] >> 1) & 7;
    pbVar1[4] = (byte)(puVar4[1] >> 4) & 7;
    bVar6 = (byte)(puVar4[1] >> 7) & 7;
    pbVar1[5] = bVar6;
    pbVar1[5] = (byte)puVar4[2] * '\x02' & 7 ^ bVar6;
    pbVar1[6] = (byte)(puVar4[2] >> 2) & 7;
    pbVar1[7] = (byte)puVar4[2] >> 5;
    pbVar1 = pbVar1 + 8;
    puVar4 = puVar5;
  } while (puVar5 != param_2 + 0x1e);
  param_1[0x50] = (byte)param_2[0x1e] & 7;
  param_1[0x51] = (byte)(param_2[0x1e] >> 3) & 7;
  bVar6 = (byte)(param_2[0x1e] >> 6) & 7;
  param_1[0x52] = bVar6;
  param_1[0x52] = (byte)param_2[0x1f] * '\x04' & 7 ^ bVar6;
  param_1[0x53] = (byte)(param_2[0x1f] >> 1) & 7;
  param_1[0x54] = (byte)(param_2[0x1f] >> 4) & 7;
  cVar3 = '\0';
  pbVar1 = param_1;
  do {
    bVar6 = cVar3 + *pbVar1 & 7;
    pbVar1[1] = pbVar1[1] + ((char)(cVar3 + *pbVar1) >> 3);
    cVar3 = (char)bVar6 >> 2;
    pbVar2 = pbVar1 + 1;
    *pbVar1 = bVar6 + cVar3 * -8;
    pbVar1 = pbVar2;
  } while (param_1 + 0x54 != pbVar2);
  param_1[0x54] = param_1[0x54] + cVar3;
  return 0;
}



// Function: crypto_sign_ed25519_ref_sc25519_window5 @ 0x347e0

undefined8 crypto_sign_ed25519_ref_sc25519_window5(byte *param_1,uint *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  char cVar3;
  uint *puVar4;
  uint *puVar5;
  byte bVar6;
  
  pbVar1 = param_1;
  puVar4 = param_2;
  do {
    puVar5 = puVar4 + 5;
    *pbVar1 = (byte)*puVar4 & 0x1f;
    bVar6 = (byte)(*puVar4 >> 5) & 0x1f;
    pbVar1[1] = bVar6;
    pbVar1[1] = ((byte)puVar4[1] & 3) << 3 ^ bVar6;
    pbVar1[2] = (byte)(puVar4[1] >> 2) & 0x1f;
    bVar6 = (byte)(puVar4[1] >> 7) & 0x1f;
    pbVar1[3] = bVar6;
    pbVar1[3] = (byte)puVar4[2] * '\x02' & 0x1f ^ bVar6;
    bVar6 = (byte)(puVar4[2] >> 4) & 0x1f;
    pbVar1[4] = bVar6;
    pbVar1[4] = ((byte)puVar4[3] & 1) << 4 ^ bVar6;
    pbVar1[5] = (byte)(puVar4[3] >> 1) & 0x1f;
    bVar6 = (byte)(puVar4[3] >> 6) & 0x1f;
    pbVar1[6] = bVar6;
    pbVar1[6] = ((byte)puVar4[4] & 7) << 2 ^ bVar6;
    pbVar1[7] = (byte)puVar4[4] >> 3;
    pbVar1 = pbVar1 + 8;
    puVar4 = puVar5;
  } while (puVar5 != param_2 + 0x1e);
  param_1[0x30] = (byte)param_2[0x1e] & 0x1f;
  bVar6 = (byte)(param_2[0x1e] >> 5) & 0x1f;
  param_1[0x31] = bVar6;
  param_1[0x31] = (byte)param_2[0x1f] * '\b' & 0x1f ^ bVar6;
  param_1[0x32] = (byte)(param_2[0x1f] >> 2) & 0x1f;
  cVar3 = '\0';
  pbVar1 = param_1;
  do {
    bVar6 = cVar3 + *pbVar1 & 0x1f;
    pbVar1[1] = pbVar1[1] + ((char)(cVar3 + *pbVar1) >> 5);
    cVar3 = (char)bVar6 >> 4;
    pbVar2 = pbVar1 + 1;
    *pbVar1 = bVar6 + cVar3 * -0x20;
    pbVar1 = pbVar2;
  } while (param_1 + 0x32 != pbVar2);
  param_1[0x32] = param_1[0x32] + cVar3;
  return 0;
}



// Function: crypto_sign_ed25519_ref_sc25519_2interleave2 @ 0x349b0

undefined8 crypto_sign_ed25519_ref_sc25519_2interleave2(byte *param_1,uint *param_2,uint *param_3)

{
  byte *pbVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  
  pbVar1 = param_1;
  puVar2 = param_2;
  puVar4 = param_3;
  do {
    puVar3 = puVar2 + 1;
    *pbVar1 = ((byte)*puVar4 & 3) << 2 | (byte)*puVar2 & 3;
    pbVar1[1] = (byte)(*puVar2 >> 2) & 3 | (byte)*puVar4 & 0xc;
    pbVar1[2] = (byte)((*puVar4 >> 4 & 3) << 2) | (byte)(*puVar2 >> 4) & 3;
    pbVar1[3] = (byte)((*puVar4 >> 6 & 3) << 2) | (byte)*puVar2 >> 6;
    pbVar1 = pbVar1 + 4;
    puVar2 = puVar3;
    puVar4 = puVar4 + 1;
  } while (puVar3 != param_2 + 0x1f);
  param_1[0x7c] = ((byte)param_3[0x1f] & 3) << 2 | (byte)param_2[0x1f] & 3;
  param_1[0x7d] = (byte)(param_2[0x1f] >> 2) & 3 | (byte)param_3[0x1f] & 0xc;
  param_1[0x7e] = (byte)((param_3[0x1f] >> 4 & 3) << 2) | (byte)(param_2[0x1f] >> 4) & 3;
  return 0;
}



// Function: equal @ 0x36000

uint equal(uint param_1,uint param_2)

{
  return (param_1 ^ param_2) - 1 >> 0x1f;
}



// Function: negative @ 0x34bb0

ulong negative(char param_1)

{
  return (ulong)(long)param_1 >> 0x3f;
}



// Function: p1p1_to_p2 @ 0x34c40

void p1p1_to_p2(long param_1,long param_2)

{
  FUN_00136f20(param_1,param_2,param_2 + 0x180);
  FUN_00136f20(param_1 + 0x80,param_2 + 0x100,param_2 + 0x80);
  FUN_00136f20(param_1 + 0x100,param_2 + 0x80,param_2 + 0x180);
  return;
}



// Function: p1p1_to_p3 @ 0x34ca0

void p1p1_to_p3(long param_1,long param_2)

{
  FUN_00134c40();
  FUN_00136f20(param_1 + 0x180,param_2,param_2 + 0x100);
  return;
}



// Function: add_p1p1 @ 0x34cd0

undefined8 add_p1p1(long param_1,long param_2,long param_3)

{
  long in_FS_OFFSET;
  undefined1 local_2c8 [128];
  undefined1 local_248 [128];
  undefined1 local_1c8 [128];
  undefined1 local_148 [128];
  undefined1 local_c8 [136];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00136d80(local_2c8,param_2 + 0x80,param_2);
  FUN_00136d80(local_c8,param_3 + 0x80,param_3);
  FUN_00136f20(local_2c8,local_2c8,local_c8);
  FUN_00136d50(local_248,param_2,param_2 + 0x80);
  FUN_00136d50(local_c8,param_3,param_3 + 0x80);
  FUN_00136f20(local_248,local_248,local_c8);
  FUN_00136f20(local_1c8,param_2 + 0x180,param_3 + 0x180);
  FUN_00136f20(local_1c8,local_1c8,&DAT_0015bb40);
  FUN_00136f20(local_148,param_2 + 0x100,param_3 + 0x100);
  FUN_00136d50(local_148,local_148,local_148);
  FUN_00136d80(param_1,local_248,local_2c8);
  FUN_00136d80(param_1 + 0x180,local_148,local_1c8);
  FUN_00136d50(param_1 + 0x80,local_148,local_1c8);
  FUN_00136d50(param_1 + 0x100,local_248,local_2c8);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: ge25519_mixadd2 @ 0x34ed0

undefined8 ge25519_mixadd2(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long in_FS_OFFSET;
  undefined1 local_5c8 [128];
  undefined1 local_548 [128];
  undefined1 local_4c8 [128];
  undefined1 local_448 [128];
  undefined1 local_3c8 [128];
  undefined1 local_348 [128];
  undefined1 local_2c8 [128];
  undefined1 local_248 [128];
  undefined1 local_1c8 [128];
  undefined1 local_148 [128];
  undefined1 local_c8 [136];
  long local_40;
  
  lVar1 = param_2 + 0x80;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00136f20(local_c8,param_2,lVar1);
  lVar2 = param_1 + 0x80;
  FUN_00136d80(local_5c8,lVar2,param_1);
  FUN_00136d50(local_548,lVar2,param_1);
  FUN_00136d80(local_4c8,lVar1,param_2);
  FUN_00136d50(local_448,lVar1,param_2);
  FUN_00136f20(local_5c8,local_5c8,local_4c8);
  FUN_00136f20(local_548,local_548,local_448);
  FUN_00136d80(local_2c8,local_548,local_5c8);
  lVar1 = param_1 + 0x100;
  FUN_00136d50(local_148,local_548,local_5c8);
  FUN_00136f20(local_3c8,param_1 + 0x180,local_c8);
  FUN_00136f20(local_3c8,local_3c8,&DAT_0015bb40);
  FUN_00136d50(local_348,lVar1,lVar1);
  FUN_00136d80(local_248,local_348,local_3c8);
  FUN_00136d50(local_1c8,local_348,local_3c8);
  FUN_00136f20(param_1,local_2c8,local_248);
  FUN_00136f20(lVar2,local_148,local_1c8);
  FUN_00136f20(lVar1,local_1c8,local_248);
  FUN_00136f20(param_1 + 0x180,local_2c8,local_148);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: dbl_p1p1 @ 0x35150

undefined8 dbl_p1p1(long param_1,long param_2)

{
  long in_FS_OFFSET;
  undefined1 local_248 [128];
  undefined1 local_1c8 [128];
  undefined1 local_148 [128];
  undefined1 local_c8 [136];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00137010(local_248);
  FUN_00137010(local_1c8,param_2 + 0x80);
  FUN_00137010(local_148,param_2 + 0x100);
  FUN_00136d50(local_148,local_148,local_148);
  FUN_00136e20(local_c8,local_248);
  FUN_00136d50(param_1,param_2,param_2 + 0x80);
  FUN_00137010(param_1,param_1);
  FUN_00136d80(param_1,param_1,local_248);
  FUN_00136d80(param_1,param_1,local_1c8);
  FUN_00136d50(param_1 + 0x80,local_c8,local_1c8);
  FUN_00136d80(param_1 + 0x180,param_1 + 0x80,local_148);
  FUN_00136d80(param_1 + 0x100,local_c8,local_1c8);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: setneutral @ 0x35300

void setneutral(long param_1)

{
  FUN_00136cb0();
  FUN_00136c00(param_1 + 0x80);
  FUN_00136c00(param_1 + 0x100);
  FUN_00136cb0(param_1 + 0x180);
  return;
}



// Function: cmov_aff @ 0x35330

void cmov_aff(long param_1,long param_2,undefined1 param_3)

{
  FUN_00136a30(param_1,param_2,param_3);
  FUN_00136a30(param_1 + 0x80,param_2 + 0x80,param_3);
  return;
}



// Function: choose_t @ 0x35360

undefined8 choose_t(undefined8 *param_1,long param_2,char param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  byte bVar17;
  byte bVar18;
  undefined1 uVar19;
  long lVar20;
  long lVar21;
  int iVar22;
  long in_FS_OFFSET;
  undefined1 auStack_b8 [136];
  long local_30;
  
  iVar22 = (int)param_3;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  lVar20 = param_2 * 0x500;
  lVar21 = (param_2 * 5 + 1) * 0x100;
  uVar1 = *(undefined8 *)(&UNK_00140fc8 + lVar20);
  uVar3 = *(undefined8 *)(&DAT_00140fd0 + lVar20);
  uVar4 = *(undefined8 *)(&UNK_00140fd8 + lVar20);
  uVar5 = *(undefined8 *)(&DAT_00140fe0 + lVar20);
  uVar6 = *(undefined8 *)(&UNK_00140fe8 + lVar20);
  uVar7 = *(undefined8 *)(&DAT_00140ff0 + lVar20);
  uVar8 = *(undefined8 *)(&UNK_00140ff8 + lVar20);
  uVar9 = *(undefined8 *)(&DAT_00141010 + lVar20);
  uVar10 = *(undefined8 *)(&UNK_00141018 + lVar20);
  uVar11 = *(undefined8 *)(&DAT_00141020 + lVar20);
  uVar12 = *(undefined8 *)(&UNK_00141028 + lVar20);
  *param_1 = *(undefined8 *)(&DAT_00140fc0 + lVar20);
  param_1[1] = uVar1;
  uVar13 = *(undefined8 *)(&DAT_00141030 + lVar20);
  uVar14 = *(undefined8 *)(&UNK_00141038 + lVar20);
  uVar1 = *(undefined8 *)(&DAT_00141040 + lVar20);
  uVar2 = *(undefined8 *)(&UNK_00141048 + lVar20);
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  uVar15 = *(undefined8 *)(&DAT_00141000 + lVar20);
  uVar16 = *(undefined8 *)(&UNK_00141008 + lVar20);
  uVar3 = *(undefined8 *)(&DAT_00141050 + lVar20);
  uVar4 = *(undefined8 *)(&UNK_00141058 + lVar20);
  param_1[4] = uVar5;
  param_1[5] = uVar6;
  param_1[6] = uVar7;
  param_1[7] = uVar8;
  uVar5 = *(undefined8 *)(&DAT_00141060 + lVar20);
  uVar6 = *(undefined8 *)(&UNK_00141068 + lVar20);
  uVar7 = *(undefined8 *)(&DAT_00141070 + lVar20);
  uVar8 = *(undefined8 *)(&UNK_00141078 + lVar20);
  param_1[0x10] = uVar1;
  param_1[0x11] = uVar2;
  param_1[0x12] = uVar3;
  param_1[0x13] = uVar4;
  param_1[0x14] = uVar5;
  param_1[0x15] = uVar6;
  param_1[0x16] = uVar7;
  param_1[0x17] = uVar8;
  param_1[10] = uVar9;
  param_1[0xb] = uVar10;
  param_1[0xc] = uVar11;
  param_1[0xd] = uVar12;
  param_1[0xe] = uVar13;
  param_1[0xf] = uVar14;
  param_1[8] = uVar15;
  param_1[9] = uVar16;
  uVar1 = *(undefined8 *)(&UNK_00141088 + lVar20);
  uVar2 = *(undefined8 *)(&DAT_00141090 + lVar20);
  uVar3 = *(undefined8 *)(&UNK_00141098 + lVar20);
  uVar4 = *(undefined8 *)(&DAT_001410a0 + lVar20);
  uVar5 = *(undefined8 *)(&UNK_001410a8 + lVar20);
  uVar6 = *(undefined8 *)(&DAT_001410b0 + lVar20);
  uVar7 = *(undefined8 *)(&UNK_001410b8 + lVar20);
  param_1[0x18] = *(undefined8 *)(&DAT_00141080 + lVar20);
  param_1[0x19] = uVar1;
  param_1[0x1a] = uVar2;
  param_1[0x1b] = uVar3;
  param_1[0x1c] = uVar4;
  param_1[0x1d] = uVar5;
  param_1[0x1e] = uVar6;
  param_1[0x1f] = uVar7;
  bVar17 = FUN_00134b20(iVar22,1);
  bVar18 = FUN_00134b20(iVar22,0xffffffff);
  FUN_00135330(param_1,&DAT_00140fc0 + lVar21,bVar17 | bVar18);
  bVar17 = FUN_00134b20(iVar22,2);
  bVar18 = FUN_00134b20(iVar22,0xfffffffe);
  FUN_00135330(param_1,&UNK_001410c0 + lVar21,bVar17 | bVar18);
  bVar17 = FUN_00134b20(iVar22,3);
  bVar18 = FUN_00134b20(iVar22,0xfffffffd);
  FUN_00135330(param_1,&UNK_001411c0 + lVar21,bVar17 | bVar18);
  uVar19 = FUN_00134b20(iVar22,0xfffffffc);
  FUN_00135330(param_1,&UNK_001412c0 + lVar21,uVar19);
  FUN_00136e20(auStack_b8,param_1);
  uVar19 = FUN_00134bb0(iVar22);
  FUN_00136a30(param_1,auStack_b8,uVar19);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_unpackneg_vartime @ 0x355f0

undefined8 crypto_sign_ed25519_ref_unpackneg_vartime(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  long in_FS_OFFSET;
  undefined1 local_3c8 [128];
  undefined1 local_348 [128];
  undefined1 local_2c8 [128];
  undefined1 local_248 [128];
  undefined1 local_1c8 [128];
  undefined1 local_148 [128];
  undefined1 local_c8 [136];
  long local_40;
  
  lVar2 = param_1 + 0x80;
  lVar1 = param_1 + 0x100;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00136c00(lVar1);
  cVar3 = *(char *)(param_2 + 0x1f);
  FUN_00136520(lVar2,param_2);
  FUN_00137010(local_2c8,lVar2);
  FUN_00136f20(local_248,local_2c8,&DAT_0015bbc0);
  FUN_00136d80(local_2c8,local_2c8,lVar1);
  FUN_00136d50(local_248,lVar1,local_248);
  FUN_00137010(local_1c8,local_248);
  FUN_00137010(local_148,local_1c8);
  FUN_00136f20(local_c8,local_148,local_1c8);
  FUN_00136f20(local_3c8,local_c8,local_2c8);
  FUN_00136f20(local_3c8,local_3c8,local_248);
  FUN_001373e0(local_3c8,local_3c8);
  FUN_00136f20(local_3c8,local_3c8,local_2c8);
  FUN_00136f20(local_3c8,local_3c8,local_248);
  FUN_00136f20(local_3c8,local_3c8,local_248);
  FUN_00136f20(param_1,local_3c8,local_248);
  FUN_00137010(local_348,param_1);
  FUN_00136f20(local_348,local_348,local_248);
  iVar5 = FUN_00136870(local_348,local_2c8);
  if (iVar5 == 0) {
    FUN_00136f20(param_1,param_1,&DAT_0015bac0);
  }
  FUN_00137010(local_348,param_1);
  FUN_00136f20(local_348,local_348,local_248);
  iVar5 = FUN_00136870(local_348,local_2c8);
  if (iVar5 == 0) {
    uVar6 = 0xffffffff;
  }
  else {
    cVar4 = FUN_00136ae0(param_1);
    if ((bool)cVar4 != -1 < cVar3) {
      FUN_00136e20(param_1,param_1);
    }
    FUN_00136f20(param_1 + 0x180,param_1,lVar2);
    uVar6 = 0;
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_pack @ 0x358b0

undefined8 crypto_sign_ed25519_ref_pack(long param_1,long param_2)

{
  char cVar1;
  long in_FS_OFFSET;
  undefined1 auStack_1b8 [128];
  undefined1 local_138 [128];
  undefined1 local_b8 [136];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00137020(local_b8,param_2 + 0x100);
  FUN_00136f20(auStack_1b8,param_2,local_b8);
  FUN_00136f20(local_138,param_2 + 0x80,local_b8);
  FUN_001365d0(param_1,local_138);
  cVar1 = FUN_00136ae0(auStack_1b8);
  *(byte *)(param_1 + 0x1f) = *(byte *)(param_1 + 0x1f) ^ cVar1 << 7;
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_isneutral_vartime @ 0x359f0

ulong crypto_sign_ed25519_ref_isneutral_vartime(long param_1)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = FUN_00136710();
  uVar2 = FUN_00136870(param_1 + 0x80,param_1 + 0x100);
  if ((int)uVar2 != 0) {
    uVar2 = (ulong)(iVar1 != 0);
  }
  return uVar2;
}



// Function: crypto_sign_ed25519_ref_double_scalarmult_vartime @ 0x35ab0

/* WARNING: Type propagation algorithm not settling */

undefined8
crypto_sign_ed25519_ref_double_scalarmult_vartime(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 *param_4,
            undefined8 param_5)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  byte *pbVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  long in_FS_OFFSET;
  byte bVar7;
  undefined1 local_22c8 [512];
  undefined8 local_20c8 [63];
  undefined8 uStack_1ed0;
  undefined8 local_1ec8 [64];
  undefined1 local_1cc8 [512];
  undefined1 local_1ac8 [512];
  undefined8 local_18c8 [64];
  undefined1 local_16c8 [512];
  undefined1 local_14c8 [512];
  undefined1 local_12c8 [512];
  undefined1 local_10c8 [512];
  undefined1 local_ec8 [512];
  undefined1 local_cc8 [512];
  undefined1 local_ac8 [512];
  undefined1 local_8c8 [512];
  undefined1 local_6c8 [512];
  undefined1 local_4c8 [512];
  undefined1 local_2c8 [512];
  byte local_c8 [126];
  byte local_4a;
  long local_40;
  
  bVar7 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00135300(local_20c8);
  puVar5 = param_2;
  puVar6 = local_1ec8;
  for (lVar2 = 0x40; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + (ulong)bVar7 * -2 + 1;
    puVar6 = puVar6 + (ulong)bVar7 * -2 + 1;
  }
  FUN_00135150(local_22c8,param_2);
  FUN_00134ca0(local_1cc8,local_22c8);
  FUN_00134cd0(local_22c8,local_1ec8,local_1cc8);
  FUN_00134ca0(local_1ac8,local_22c8);
  puVar5 = param_4;
  puVar6 = local_18c8;
  for (lVar2 = 0x40; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + (ulong)bVar7 * -2 + 1;
    puVar6 = puVar6 + (ulong)bVar7 * -2 + 1;
  }
  FUN_00134cd0(local_22c8,local_1ec8,local_18c8);
  FUN_00134ca0(local_16c8,local_22c8);
  FUN_00134cd0(local_22c8,local_1cc8,local_18c8);
  FUN_00134ca0(local_14c8,local_22c8);
  FUN_00134cd0(local_22c8,local_1ac8,local_18c8);
  FUN_00134ca0(local_12c8,local_22c8);
  FUN_00135150(local_22c8,param_4);
  FUN_00134ca0(local_10c8,local_22c8);
  FUN_00134cd0(local_22c8,local_1ec8,local_10c8);
  FUN_00134ca0(local_ec8,local_22c8);
  FUN_00135150(local_22c8,local_16c8);
  FUN_00134ca0(local_cc8,local_22c8);
  FUN_00134cd0(local_22c8,local_1ac8,local_10c8);
  FUN_00134ca0(local_ac8,local_22c8);
  FUN_00134cd0(local_22c8,local_18c8,local_10c8);
  FUN_00134ca0(local_8c8,local_22c8);
  FUN_00134cd0(local_22c8,local_1ec8,local_8c8);
  FUN_00134ca0(local_6c8,local_22c8);
  FUN_00134cd0(local_22c8,local_1cc8,local_8c8);
  pbVar4 = local_c8 + 0x7d;
  FUN_00134ca0(local_4c8,local_22c8);
  FUN_00134cd0(local_22c8,local_1ac8,local_8c8);
  FUN_00134ca0(local_2c8,local_22c8);
  FUN_001349b0(local_c8,param_3,param_5);
  uVar1 = (ulong)local_4a;
  *param_1 = local_20c8[uVar1 * 0x40];
  param_1[0x3f] = local_1ec8[uVar1 * 0x40 + -1];
  lVar2 = (long)param_1 - (long)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
  puVar5 = (undefined8 *)((long)local_20c8 + (uVar1 * 0x200 - lVar2));
  puVar6 = (undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
  for (uVar3 = (ulong)((int)lVar2 + 0x200U >> 3); uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + (ulong)bVar7 * -2 + 1;
    puVar6 = puVar6 + (ulong)bVar7 * -2 + 1;
  }
  while( true ) {
    FUN_00135150(local_22c8,param_1);
    FUN_00134c40(param_1,local_22c8);
    FUN_00135150(local_22c8,param_1);
    if (*pbVar4 != 0) {
      FUN_00134ca0(param_1,local_22c8);
      FUN_00134cd0(local_22c8,param_1,local_20c8 + (ulong)*pbVar4 * 0x40);
    }
    if (pbVar4 == local_c8) break;
    FUN_00134c40(param_1,local_22c8);
    pbVar4 = pbVar4 + -1;
  }
  FUN_00134ca0();
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// Function: crypto_sign_ed25519_ref_scalarmult_base @ 0x35eb0

undefined8 crypto_sign_ed25519_ref_scalarmult_base(long param_1)

{
  long lVar1;
  long lVar2;
  long in_FS_OFFSET;
  undefined1 auStack_188 [256];
  char local_88 [88];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00134610(local_88);
  FUN_00135360(param_1,0,(int)local_88[0]);
  FUN_00136c00(param_1 + 0x100);
  FUN_00136f20(param_1 + 0x180,param_1,param_1 + 0x80);
  lVar1 = 1;
  do {
    lVar2 = lVar1 + 1;
    FUN_00135360(auStack_188,lVar1,(int)local_88[lVar1]);
    FUN_00134ed0(param_1,auStack_188);
    lVar1 = lVar2;
  } while (lVar2 != 0x55);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: times19 @ 0x36090

int times19(int param_1)

{
  return param_1 * 0x13;
}



// Function: times38 @ 0x36120

int times38(int param_1)

{
  return param_1 * 0x26;
}



// Function: reduce_mul @ 0x36290

undefined8 reduce_mul(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = 2;
  while( true ) {
    uVar2 = param_1[0x1f];
    param_1[0x1f] = uVar2 & 0x7f;
    iVar1 = FUN_00136090(uVar2 >> 7);
    uVar2 = iVar1 + *param_1;
    *param_1 = uVar2;
    puVar3 = param_1;
    while( true ) {
      *puVar3 = *puVar3 & 0xff;
      puVar3[1] = puVar3[1] + (uVar2 >> 8);
      puVar3 = puVar3 + 1;
      if (param_1 + 0x1f == puVar3) break;
      uVar2 = *puVar3;
    }
    if (iVar4 == 1) break;
    iVar4 = 1;
  }
  return 0;
}



// Function: crypto_sign_ed25519_ref_fe25519_freeze @ 0x36410

undefined8 crypto_sign_ed25519_ref_fe25519_freeze(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  iVar1 = param_1[0x1f];
  piVar5 = param_1 + 0x1e;
  uVar3 = FUN_00136000(iVar1,0x7f);
  piVar6 = piVar5;
  do {
    iVar2 = *piVar6;
    piVar6 = piVar6 + -1;
    uVar4 = FUN_00136000(iVar2,0xff);
    uVar3 = uVar3 & uVar4;
  } while (piVar6 != param_1);
  uVar4 = FUN_00136380(*param_1);
  uVar3 = -(uVar4 & uVar3);
  param_1[0x1f] = iVar1 - (uVar3 & 0x7f);
  do {
    *piVar5 = *piVar5 - (uVar3 & 0xff);
    piVar5 = piVar5 + -1;
  } while (piVar5 != param_1);
  *piVar5 = *piVar5 - (uVar3 & 0xed);
  return 0;
}



// Function: crypto_sign_ed25519_ref_fe25519_unpack @ 0x36520

undefined8 crypto_sign_ed25519_ref_fe25519_unpack(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    *(uint *)(param_1 + lVar1 * 4) = (uint)*(byte *)(param_2 + lVar1);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0x7f;
  return 0;
}



// Function: crypto_sign_ed25519_ref_fe25519_pack @ 0x365d0

undefined8 crypto_sign_ed25519_ref_fe25519_pack(long param_1,undefined8 *param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_20;
  
  local_a8 = *param_2;
  uStack_a0 = param_2[1];
  local_98 = param_2[2];
  uStack_90 = param_2[3];
  local_88 = param_2[4];
  uStack_80 = param_2[5];
  local_78 = param_2[6];
  uStack_70 = param_2[7];
  local_68 = param_2[8];
  uStack_60 = param_2[9];
  local_58 = param_2[10];
  uStack_50 = param_2[0xb];
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = param_2[0xc];
  uStack_40 = param_2[0xd];
  local_38 = param_2[0xe];
  uStack_30 = param_2[0xf];
  FUN_00136410(&local_a8);
  lVar1 = 0;
  do {
    *(char *)(param_1 + lVar1) = (char)*(undefined4 *)((long)&local_a8 + lVar1 * 4);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_fe25519_iszero @ 0x36710

uint crypto_sign_ed25519_ref_fe25519_iszero(ulong *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  long in_FS_OFFSET;
  undefined8 local_a8;
  ulong uStack_a0;
  ulong local_98;
  ulong uStack_90;
  ulong local_88;
  ulong uStack_80;
  ulong local_78;
  ulong uStack_70;
  ulong local_68;
  ulong uStack_60;
  ulong local_58;
  ulong uStack_50;
  ulong local_48;
  ulong uStack_40;
  ulong local_38;
  ulong uStack_30;
  undefined4 local_28 [2];
  long local_20;
  
  local_a8 = *param_1;
  uStack_a0 = param_1[1];
  local_98 = param_1[2];
  uStack_90 = param_1[3];
  local_88 = param_1[4];
  uStack_80 = param_1[5];
  local_78 = param_1[6];
  uStack_70 = param_1[7];
  puVar4 = (undefined4 *)((long)&local_a8 + 4);
  local_68 = param_1[8];
  uStack_60 = param_1[9];
  local_58 = param_1[10];
  uStack_50 = param_1[0xb];
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = param_1[0xc];
  uStack_40 = param_1[0xd];
  local_38 = param_1[0xe];
  uStack_30 = param_1[0xf];
  FUN_00136410(&local_a8);
  uVar2 = FUN_00136000(local_a8 & 0xffffffff,0);
  do {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    uVar3 = FUN_00136000(uVar1,0);
    uVar2 = uVar2 & uVar3;
  } while (puVar4 != local_28);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_fe25519_iseq_vartime @ 0x36870

undefined8 crypto_sign_ed25519_ref_fe25519_iseq_vartime(undefined8 *param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8 [4];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_20;
  
  local_128 = *param_1;
  uStack_120 = param_1[1];
  local_118 = param_1[2];
  uStack_110 = param_1[3];
  local_108 = param_1[4];
  uStack_100 = param_1[5];
  local_f8 = param_1[6];
  uStack_f0 = param_1[7];
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_e8 = param_1[8];
  uStack_e0 = param_1[9];
  local_d8 = param_1[10];
  uStack_d0 = param_1[0xb];
  local_c8 = param_1[0xc];
  uStack_c0 = param_1[0xd];
  local_b8 = param_1[0xe];
  uStack_b0 = param_1[0xf];
  local_a8[0] = *param_2;
  local_a8[1] = param_2[1];
  local_a8[2] = param_2[2];
  local_a8[3] = param_2[3];
  local_88 = param_2[4];
  uStack_80 = param_2[5];
  local_78 = param_2[6];
  uStack_70 = param_2[7];
  local_68 = param_2[8];
  uStack_60 = param_2[9];
  local_58 = param_2[10];
  uStack_50 = param_2[0xb];
  local_48 = param_2[0xc];
  uStack_40 = param_2[0xd];
  local_38 = param_2[0xe];
  uStack_30 = param_2[0xf];
  FUN_00136410(&local_128);
  FUN_00136410(local_a8);
  lVar1 = 0;
  do {
    if (*(int *)((long)&local_128 + lVar1) != *(int *)((long)local_a8 + lVar1)) {
      uVar2 = 0;
      goto LAB_00136983;
    }
    lVar1 = lVar1 + 4;
  } while (lVar1 != 0x80);
  uVar2 = 1;
LAB_00136983:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_fe25519_cmov @ 0x36a30

undefined8 crypto_sign_ed25519_ref_fe25519_cmov(long param_1,long param_2,byte param_3)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    *(uint *)(param_1 + lVar1) =
         (*(uint *)(param_2 + lVar1) ^ *(uint *)(param_1 + lVar1)) & -(uint)param_3 ^
         *(uint *)(param_1 + lVar1);
    lVar1 = lVar1 + 4;
  } while (lVar1 != 0x80);
  return 0;
}



// Function: crypto_sign_ed25519_ref_fe25519_getparity @ 0x36ae0

byte crypto_sign_ed25519_ref_fe25519_getparity(undefined8 *param_1)

{
  long in_FS_OFFSET;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_10;
  
  local_98 = *param_1;
  uStack_90 = param_1[1];
  local_88 = param_1[2];
  uStack_80 = param_1[3];
  local_78 = param_1[4];
  uStack_70 = param_1[5];
  local_68 = param_1[6];
  uStack_60 = param_1[7];
  local_58 = param_1[8];
  uStack_50 = param_1[9];
  local_48 = param_1[10];
  uStack_40 = param_1[0xb];
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_38 = param_1[0xc];
  uStack_30 = param_1[0xd];
  local_28 = param_1[0xe];
  uStack_20 = param_1[0xf];
  FUN_00136410(&local_98);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return (byte)local_98 & 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_fe25519_setone @ 0x36c00

undefined8 crypto_sign_ed25519_ref_fe25519_setone(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = 1;
  puVar1 = param_1 + 1;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x20);
  return 0;
}



// Function: crypto_sign_ed25519_ref_fe25519_setzero @ 0x36cb0

undefined8 crypto_sign_ed25519_ref_fe25519_setzero(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 0x20;
  do {
    *param_1 = 0;
    param_1 = param_1 + 1;
  } while (param_1 != puVar1);
  return 0;
}



// Function: crypto_sign_ed25519_ref_fe25519_add @ 0x36d50

void crypto_sign_ed25519_ref_fe25519_add(long param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    *(int *)(param_1 + lVar1) = *(int *)(param_3 + lVar1) + *(int *)(param_2 + lVar1);
    lVar1 = lVar1 + 4;
  } while (lVar1 != 0x80);
  FUN_001361b0();
  return;
}



// Function: crypto_sign_ed25519_ref_fe25519_sub @ 0x36d80

void crypto_sign_ed25519_ref_fe25519_sub(long param_1,int *param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long in_FS_OFFSET;
  int aiStack_98 [34];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = *param_2 + 0x1da;
  aiStack_98[0x1f] = param_2[0x1f] + 0xfe;
  lVar2 = 4;
  do {
    *(int *)((long)aiStack_98 + lVar2) = *(int *)((long)param_2 + lVar2) + 0x1fe;
    lVar2 = lVar2 + 4;
  } while (lVar2 != 0x7c);
  lVar2 = 0;
  while( true ) {
    *(int *)(param_1 + lVar2) = iVar1 - *(int *)(param_3 + lVar2);
    if (lVar2 + 4 == 0x80) break;
    iVar1 = *(int *)((long)aiStack_98 + lVar2 + 4);
    lVar2 = lVar2 + 4;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    FUN_001361b0(param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_fe25519_neg @ 0x36e20

undefined8 crypto_sign_ed25519_ref_fe25519_neg(undefined8 param_1,long param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined4 local_a8 [34];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = 0;
  do {
    *(undefined4 *)((long)local_a8 + lVar1) = *(undefined4 *)(param_2 + lVar1);
    lVar1 = lVar1 + 4;
  } while (lVar1 != 0x80);
  FUN_00136cb0(param_1);
  FUN_00136d80(param_1,param_1,local_a8);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_fe25519_mul @ 0x36f20

void crypto_sign_ed25519_ref_fe25519_mul(int *param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  int *piVar6;
  long lVar7;
  int *piVar8;
  long in_FS_OFFSET;
  int local_138 [63];
  int local_3c [3];
  long local_30;
  
  piVar4 = local_138;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  do {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  } while (piVar4 != local_3c);
  lVar7 = 0;
  do {
    iVar3 = *(int *)(param_2 + lVar7 * 4);
    lVar5 = 0;
    do {
      lVar1 = lVar5 * 4;
      iVar2 = (int)lVar5;
      lVar5 = lVar5 + 1;
      local_138[iVar2 + (int)lVar7] =
           local_138[iVar2 + (int)lVar7] + *(int *)(param_3 + lVar1) * iVar3;
    } while (lVar5 != 0x20);
    lVar7 = lVar7 + 1;
  } while (lVar7 != 0x20);
  piVar4 = local_138 + 0x20;
  piVar8 = param_1;
  do {
    piVar6 = piVar4 + 1;
    iVar3 = FUN_00136120(*piVar4);
    *piVar8 = iVar3 + piVar4[-0x20];
    piVar4 = piVar6;
    piVar8 = piVar8 + 1;
  } while (piVar6 != local_3c);
  param_1[0x1f] = local_138[0x1f];
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    FUN_00136290(param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_fe25519_square @ 0x37010

void crypto_sign_ed25519_ref_fe25519_square(undefined8 param_1,undefined8 param_2)

{
  FUN_00136f20(param_1,param_2,param_2);
  return;
}



// Function: crypto_sign_ed25519_ref_fe25519_invert @ 0x37020

undefined8 crypto_sign_ed25519_ref_fe25519_invert(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined1 local_548 [128];
  undefined1 local_4c8 [128];
  undefined1 local_448 [128];
  undefined1 local_3c8 [128];
  undefined1 local_348 [128];
  undefined1 local_2c8 [128];
  undefined1 local_248 [128];
  undefined1 local_1c8 [128];
  undefined1 local_148 [128];
  undefined1 local_c8 [136];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00137010(local_548);
  FUN_00137010(local_c8,local_548);
  FUN_00137010(local_148,local_c8);
  FUN_00136f20(local_4c8,local_148,param_2);
  FUN_00136f20(local_448,local_4c8,local_548);
  iVar1 = 4;
  FUN_00137010(local_148,local_448);
  FUN_00136f20(local_3c8,local_148,local_4c8);
  FUN_00137010(local_148,local_3c8);
  FUN_00137010(local_c8,local_148);
  FUN_00137010(local_148,local_c8);
  FUN_00137010(local_c8,local_148);
  FUN_00137010(local_148,local_c8);
  FUN_00136f20(local_348,local_148,local_3c8);
  FUN_00137010(local_148,local_348);
  FUN_00137010(local_c8,local_148);
  do {
    FUN_00137010(local_148,local_c8);
    FUN_00137010(local_c8,local_148);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 9;
  FUN_00136f20(local_2c8,local_c8,local_348);
  FUN_00137010(local_148,local_2c8);
  FUN_00137010(local_c8,local_148);
  do {
    FUN_00137010(local_148,local_c8);
    FUN_00137010(local_c8,local_148);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 4;
  FUN_00136f20(local_148,local_c8,local_2c8);
  FUN_00137010(local_c8,local_148);
  FUN_00137010(local_148,local_c8);
  do {
    FUN_00137010(local_c8,local_148);
    FUN_00137010(local_148,local_c8);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x18;
  FUN_00136f20(local_248,local_148,local_348);
  FUN_00137010(local_148,local_248);
  FUN_00137010(local_c8,local_148);
  do {
    FUN_00137010(local_148,local_c8);
    FUN_00137010(local_c8,local_148);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x31;
  FUN_00136f20(local_1c8,local_c8,local_248);
  FUN_00137010(local_c8,local_1c8);
  FUN_00137010(local_148,local_c8);
  do {
    FUN_00137010(local_c8,local_148);
    FUN_00137010(local_148,local_c8);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x18;
  FUN_00136f20(local_c8,local_148,local_1c8);
  FUN_00137010(local_148,local_c8);
  FUN_00137010(local_c8,local_148);
  do {
    FUN_00137010(local_148,local_c8);
    FUN_00137010(local_c8,local_148);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00136f20(local_148,local_c8,local_248);
  FUN_00137010(local_c8,local_148);
  FUN_00137010(local_148,local_c8);
  FUN_00137010(local_c8,local_148);
  FUN_00137010(local_148,local_c8);
  FUN_00137010(local_c8,local_148);
  FUN_00136f20(param_1,local_c8,local_448);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: crypto_sign_ed25519_ref_fe25519_pow2523 @ 0x373e0

undefined8 crypto_sign_ed25519_ref_fe25519_pow2523(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined1 auStack_4c8 [128];
  undefined1 local_448 [128];
  undefined1 local_3c8 [128];
  undefined1 local_348 [128];
  undefined1 local_2c8 [128];
  undefined1 local_248 [128];
  undefined1 local_1c8 [128];
  undefined1 local_148 [128];
  undefined1 local_c8 [136];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00137010(auStack_4c8);
  FUN_00137010(local_c8,auStack_4c8);
  FUN_00137010(local_c8,local_c8);
  FUN_00136f20(local_448,local_c8,param_2);
  FUN_00136f20(local_3c8,local_448,auStack_4c8);
  FUN_00137010(local_c8,local_3c8);
  FUN_00136f20(local_348,local_c8,local_448);
  iVar1 = 4;
  FUN_00137010(local_c8,local_348);
  do {
    FUN_00137010(local_c8,local_c8);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 9;
  FUN_00136f20(local_2c8,local_c8,local_348);
  FUN_00137010(local_c8,local_2c8);
  do {
    FUN_00137010(local_c8,local_c8);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x13;
  FUN_00136f20(local_248,local_c8,local_2c8);
  FUN_00137010(local_c8,local_248);
  do {
    FUN_00137010(local_c8,local_c8);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 9;
  FUN_00136f20(local_c8,local_c8,local_248);
  FUN_00137010(local_c8,local_c8);
  do {
    FUN_00137010(local_c8,local_c8);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x31;
  FUN_00136f20(local_1c8,local_c8,local_2c8);
  FUN_00137010(local_c8,local_1c8);
  do {
    FUN_00137010(local_c8,local_c8);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 99;
  FUN_00136f20(local_148,local_c8,local_1c8);
  FUN_00137010(local_c8,local_148);
  do {
    FUN_00137010(local_c8,local_c8);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x31;
  FUN_00136f20(local_c8,local_c8,local_148);
  FUN_00137010(local_c8,local_c8);
  do {
    FUN_00137010(local_c8,local_c8);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00136f20(local_c8,local_c8,local_1c8);
  FUN_00137010(local_c8,local_c8);
  FUN_00137010(local_c8,local_c8);
  FUN_00136f20(param_1,local_c8,param_2);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: closefrom_fallback @ 0x376e0

undefined8 closefrom_fallback(int param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = (long)param_1;
  lVar1 = sysconf(4);
  if (lVar1 < 0) {
    lVar1 = 0x100;
  }
  for (; lVar2 < lVar1; lVar2 = FUN_0013da00(lVar2,1)) {
    close((int)lVar2);
  }
  return 0;
}



// Function: EVP_CIPHER_CTX_get_iv @ 0x37980

undefined8 EVP_CIPHER_CTX_get_iv(long param_1,void *param_2,ulong param_3)

{
  int iVar1;
  void *__src;
  
  if ((((param_1 != 0) && (iVar1 = EVP_CIPHER_CTX_get_iv_length(), -1 < iVar1)) &&
      (iVar1 = EVP_CIPHER_CTX_get_iv_length(param_1), param_3 < 0x11)) && ((long)iVar1 == param_3))
  {
    if (param_3 == 0) {
      return 1;
    }
    if (param_2 != (void *)0x0) {
      __src = (void *)EVP_CIPHER_CTX_iv(param_1);
      memcpy(param_2,__src,param_3);
      return 1;
    }
  }
  return 0;
}



// Function: EVP_CIPHER_CTX_set_iv @ 0x37a90

undefined8 EVP_CIPHER_CTX_set_iv(long param_1,void *param_2,ulong param_3)

{
  int iVar1;
  void *__dest;
  
  if ((((param_1 != 0) && (iVar1 = EVP_CIPHER_CTX_get_iv_length(), -1 < iVar1)) &&
      (iVar1 = EVP_CIPHER_CTX_get_iv_length(param_1), param_3 < 0x11)) && ((long)iVar1 == param_3))
  {
    if (param_3 == 0) {
      return 1;
    }
    if (param_2 != (void *)0x0) {
      __dest = (void *)EVP_CIPHER_CTX_iv_noconst(param_1);
      memcpy(__dest,param_2,param_3);
      return 1;
    }
  }
  return 0;
}



// Function: _rs_rekey @ 0x38440

undefined8 _rs_rekey(long param_1,long param_2)

{
  byte *pbVar1;
  long lVar2;
  undefined8 *puVar3;
  long lVar4;
  
  FUN_00137c40(DAT_00168218,DAT_00168218 + 0x40,DAT_00168218 + 0x40,0x400);
  lVar2 = DAT_00168218;
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar4 = 0;
    do {
      pbVar1 = (byte *)(lVar2 + 0x40 + lVar4);
      *pbVar1 = *pbVar1 ^ *(byte *)(param_1 + lVar4);
      lVar4 = lVar4 + 1;
    } while (param_2 != lVar4);
  }
  FUN_001383f0(lVar2 + 0x40);
  puVar3 = DAT_00168220;
  lVar2 = DAT_00168218;
  *(undefined8 *)(DAT_00168218 + 0x60) = 0;
  *(undefined1 (*) [16])(lVar2 + 0x40) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(lVar2 + 0x50) = (undefined1  [16])0x0;
  *puVar3 = 0x3d8;
  return 0;
}



// Function: _rs_stir @ 0x38550

undefined8 _rs_stir(void)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 *puVar4;
  long in_FS_OFFSET;
  byte bVar5;
  uint local_3c;
  undefined1 local_38 [40];
  long local_10;
  
  bVar5 = 0;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_3c = 0;
  iVar2 = getentropy(local_38,0x28);
  if (iVar2 == -1) {
    FUN_001380e0();
  }
  else {
    if (DAT_00168220 == (undefined8 *)0x0) {
      FUN_001383f0(local_38);
    }
    else {
      FUN_00138440(local_38,0x28);
    }
    __explicit_bzero_chk(local_38,0x28,0x28);
    *DAT_00168220 = 0;
    lVar1 = DAT_00168218;
    uVar3 = DAT_00168218 + 0x48;
    *(undefined8 *)(DAT_00168218 + 0x40) = 0;
    *(undefined8 *)(lVar1 + 0x438) = 0;
    puVar4 = (undefined8 *)(uVar3 & 0xfffffffffffffff8);
    uVar3 = (ulong)(((int)lVar1 - (int)puVar4) + 0x440U >> 3);
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
    }
    FUN_00137c40(lVar1,&local_3c,&local_3c,4);
    DAT_00168220[1] = (ulong)((local_3c & 0xfffff) + 0x100000);
    if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
      return 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: _rs_stir_if_needed @ 0x386e0

undefined8 _rs_stir_if_needed(ulong param_1)

{
  ulong uVar1;
  
  FUN_00138120();
  if ((DAT_00168220 == 0) || (uVar1 = *(ulong *)(DAT_00168220 + 8), uVar1 <= param_1)) {
    FUN_00138550();
    uVar1 = *(ulong *)(DAT_00168220 + 8);
    if (uVar1 <= param_1) {
      *(undefined8 *)(DAT_00168220 + 8) = 0;
      return 0;
    }
  }
  *(ulong *)(DAT_00168220 + 8) = uVar1 - param_1;
  return 0;
}



// Function: _rs_random_u32 @ 0x38840

undefined8 _rs_random_u32(undefined4 *param_1)

{
  long lVar1;
  ulong uVar2;
  
  FUN_001386e0(4);
  uVar2 = *DAT_00168220;
  if (uVar2 < 4) {
    FUN_00138440(0,0);
    uVar2 = *DAT_00168220;
  }
  lVar1 = DAT_00168218 - uVar2;
  *param_1 = *(undefined4 *)(lVar1 + 0x440);
  *(undefined4 *)(lVar1 + 0x440) = 0;
  *DAT_00168220 = *DAT_00168220 - 4;
  return 0;
}



// Function: _rs_random_buf @ 0x38930

undefined8 _rs_random_buf(void *param_1,ulong param_2)

{
  void *__src;
  ulong uVar1;
  ulong __n;
  void *pvVar2;
  
  FUN_001386e0(param_2);
joined_r0x00138949:
  if (param_2 == 0) {
    return 0;
  }
  uVar1 = *DAT_00168220;
  pvVar2 = param_1;
  if (uVar1 != 0) goto code_r0x0013897d;
  goto LAB_00138960;
code_r0x0013897d:
  __n = param_2;
  if (uVar1 <= param_2) {
    __n = uVar1;
  }
  __src = (void *)(DAT_00168218 + (0x440 - uVar1));
  pvVar2 = (void *)((long)param_1 + __n);
  param_2 = param_2 - __n;
  memcpy(param_1,__src,__n);
  memset(__src,0,__n);
  *DAT_00168220 = *DAT_00168220 - __n;
  param_1 = pvVar2;
  if (*DAT_00168220 == 0) {
LAB_00138960:
    FUN_00138440(0,0);
    param_1 = pvVar2;
  }
  goto joined_r0x00138949;
}



// Function: arc4random @ 0x38a60

undefined4 arc4random(void)

{
  long in_FS_OFFSET;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00138840(&local_14);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_14;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: __b64_ntop @ 0x38b30

ulong __b64_ntop(byte *param_1,ulong param_2,long param_3,ulong param_4)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  char cVar7;
  uint uVar8;
  byte bVar9;
  
  if (param_2 < 3) {
    uVar4 = 0;
LAB_00138c20:
    uVar5 = uVar4;
    if (param_2 != 0) {
      if (param_2 == 2) {
        uVar8 = (uint)(param_1[1] >> 4);
        uVar6 = (param_1[1] & 0xf) << 2;
      }
      else {
        uVar6 = 0;
        uVar8 = 0;
      }
      uVar5 = uVar4 + 4;
      if (param_4 < uVar5) {
        return 0xffffffff;
      }
      cVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [(*param_1 & 3) * 0x10 + uVar8];
      *(char *)(param_3 + uVar4) =
           "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[*param_1 >> 2];
      *(char *)(param_3 + 1 + uVar4) = cVar7;
      cVar7 = '=';
      if (param_2 != 1) {
        cVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar6];
      }
      *(char *)(param_3 + 2 + uVar4) = cVar7;
      *(undefined1 *)(param_3 + uVar4 + 3) = 0x3d;
    }
    if (uVar5 < param_4) {
      *(undefined1 *)(param_3 + uVar5) = 0;
      return uVar5;
    }
  }
  else {
    bVar9 = *param_1;
    bVar1 = param_1[2];
    uVar6 = (bVar9 & 3) * 0x10 + (uint)(param_1[1] >> 4);
    uVar8 = (uint)(bVar1 >> 6) + (param_1[1] & 0xf) * 4;
    uVar4 = 4;
    pbVar3 = param_1;
    if (3 < param_4) {
      do {
        param_2 = param_2 - 3;
        param_1 = pbVar3 + 3;
        cVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[bVar9 >> 2];
        *(char *)(param_3 + -3 + uVar4) =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar6];
        cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar8];
        *(char *)(param_3 + -4 + uVar4) = cVar7;
        cVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[bVar1 & 0x3f];
        *(char *)(param_3 + -2 + uVar4) = cVar2;
        *(char *)(param_3 + -1 + uVar4) = cVar7;
        if (param_2 < 3) goto LAB_00138c20;
        bVar9 = *param_1;
        uVar4 = uVar4 + 4;
        bVar1 = pbVar3[5];
        uVar6 = (bVar9 & 3) * 0x10 + (uint)(pbVar3[4] >> 4);
        uVar8 = (pbVar3[4] & 0xf) * 4 + (uint)(bVar1 >> 6);
        pbVar3 = param_1;
      } while (uVar4 <= param_4);
    }
  }
  return 0xffffffff;
}



// Function: __b64_pton @ 0x38de0

uint __b64_pton(char *param_1,long param_2,ulong param_3)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  ushort **ppuVar5;
  char *pcVar6;
  long lVar7;
  char *pcVar8;
  ulong uVar9;
  int iVar10;
  ushort *local_50;
  uint local_44;
  
  iVar10 = 0;
  local_44 = 0;
LAB_00138e0f:
  do {
    cVar3 = *param_1;
    pcVar8 = param_1;
    while( true ) {
      if (cVar3 == '\0') {
        if (iVar10 == 0) {
          return local_44;
        }
        return 0xffffffff;
      }
      param_1 = pcVar8 + 1;
      ppuVar5 = __ctype_b_loc();
      local_50 = *ppuVar5;
      if ((*(byte *)((long)local_50 + (long)cVar3 * 2 + 1) & 0x20) == 0) break;
      cVar3 = *param_1;
      pcVar8 = param_1;
    }
    if (cVar3 == 0x3d) {
      uVar9 = (ulong)*param_1;
      pcVar8 = pcVar8 + 2;
      if (iVar10 == 2) {
LAB_0013924c:
        uVar4 = (uint)uVar9;
        while( true ) {
          if (uVar4 == 0) {
            return 0xffffffff;
          }
          if ((*(byte *)((long)local_50 + (long)(int)uVar9 * 2 + 1) & 0x20) == 0) break;
          uVar4 = (uint)*pcVar8;
          uVar9 = (ulong)uVar4;
          pcVar8 = pcVar8 + 1;
        }
        if ((int)uVar9 != 0x3d) {
          return 0xffffffff;
        }
        uVar9 = (ulong)*pcVar8;
        pcVar8 = pcVar8 + 1;
      }
      else if (iVar10 != 3) {
        return 0xffffffff;
      }
LAB_001392b3:
      while ((int)uVar9 != 0) {
        if ((*(byte *)((long)local_50 + uVar9 * 2 + 1) & 0x20) == 0) {
          return 0xffffffff;
        }
        cVar3 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        uVar9 = (ulong)cVar3;
      }
      if ((param_2 != 0) && (*(char *)(param_2 + (ulong)local_44) != '\0')) {
        return 0xffffffff;
      }
      return local_44;
    }
    pcVar6 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",(int)cVar3);
    if (pcVar6 == (char *)0x0) {
      return 0xffffffff;
    }
    if (iVar10 == 2) {
      uVar9 = (ulong)local_44;
      pcVar8 = param_1;
      goto LAB_00138f16;
    }
    if (iVar10 == 3) goto LAB_00138f8a;
    if (iVar10 != 1) goto LAB_00138ff4;
    pcVar8 = param_1;
    if (param_2 == 0) {
      uVar9 = (ulong)(local_44 + 1);
      goto LAB_00138eda;
    }
    while( true ) {
      uVar9 = (ulong)(local_44 + 1);
      if (param_3 <= uVar9) {
        return 0xffffffff;
      }
      lVar7 = FUN_0013da40(pcVar6,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                          );
      *(byte *)((ulong)local_44 + param_2) =
           *(byte *)((ulong)local_44 + param_2) | (byte)(lVar7 >> 4);
      *(char *)(param_2 + uVar9) = (char)(lVar7 << 4);
LAB_00138eda:
      while( true ) {
        cVar3 = *pcVar8;
        param_1 = pcVar8 + 1;
        if (cVar3 == '\0') {
          return 0xffffffff;
        }
        local_50 = *ppuVar5;
        local_44 = (uint)uVar9;
        if ((*(byte *)((long)local_50 + (long)cVar3 * 2 + 1) & 0x20) != 0) {
          iVar10 = 2;
          goto LAB_00138e0f;
        }
        if (cVar3 == 0x3d) {
          uVar9 = (ulong)(uint)(int)pcVar8[1];
          pcVar8 = pcVar8 + 2;
          goto LAB_0013924c;
        }
        pcVar6 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
                        (int)cVar3);
        pcVar8 = param_1;
        if (pcVar6 == (char *)0x0) {
          return 0xffffffff;
        }
LAB_00138f16:
        local_44 = (int)uVar9 + 1;
        if (param_2 != 0) {
          if (param_3 <= local_44) {
            return 0xffffffff;
          }
          lVar7 = FUN_0013da40(pcVar6,
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
          *(byte *)(uVar9 + param_2) = *(byte *)(uVar9 + param_2) | (byte)(lVar7 >> 2);
          *(char *)(param_2 + (ulong)local_44) = (char)(lVar7 << 6);
        }
        cVar3 = *pcVar8;
        param_1 = pcVar8 + 1;
        if (cVar3 == '\0') {
          return 0xffffffff;
        }
        local_50 = *ppuVar5;
        if ((*(byte *)((long)local_50 + (long)cVar3 * 2 + 1) & 0x20) != 0) {
          iVar10 = 3;
          goto LAB_00138e0f;
        }
        if (cVar3 == 0x3d) {
          uVar9 = (ulong)pcVar8[1];
          pcVar8 = pcVar8 + 2;
          goto LAB_001392b3;
        }
        pcVar6 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
                        (int)cVar3);
        if (pcVar6 == (char *)0x0) {
          return 0xffffffff;
        }
LAB_00138f8a:
        if (param_2 != 0) {
          if (param_3 <= local_44) {
            return 0xffffffff;
          }
          pbVar1 = (byte *)(param_2 + (ulong)local_44);
          bVar2 = FUN_0013da40(pcVar6,
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
          *pbVar1 = *pbVar1 | bVar2;
        }
        cVar3 = *param_1;
        local_44 = local_44 + 1;
        param_1 = param_1 + 1;
        if (cVar3 == '\0') {
          return local_44;
        }
        local_50 = *ppuVar5;
        if ((*(byte *)((long)local_50 + (long)cVar3 * 2 + 1) & 0x20) != 0) {
          iVar10 = 0;
          goto LAB_00138e0f;
        }
        if (cVar3 == 0x3d) {
          return 0xffffffff;
        }
        pcVar6 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
                        (int)cVar3);
        if (pcVar6 == (char *)0x0) {
          return 0xffffffff;
        }
LAB_00138ff4:
        if (param_2 != 0) break;
        cVar3 = *param_1;
        if (cVar3 == '\0') {
          return 0xffffffff;
        }
        if ((*(byte *)((long)local_50 + (long)cVar3 * 2 + 1) & 0x20) != 0) goto LAB_0013921b;
        if (cVar3 == 0x3d) {
          return 0xffffffff;
        }
        pcVar8 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
                        (int)cVar3);
        if (pcVar8 == (char *)0x0) {
          return 0xffffffff;
        }
        uVar9 = (ulong)(local_44 + 1);
        pcVar8 = param_1 + 1;
      }
      if (param_3 <= local_44) {
        return 0xffffffff;
      }
      pcVar8 = param_1 + 1;
      cVar3 = FUN_0013da40(pcVar6,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                          );
      *(char *)(param_2 + (ulong)local_44) = cVar3 << 2;
      cVar3 = *param_1;
      if (cVar3 == '\0') {
        return 0xffffffff;
      }
      if ((*(byte *)((long)*ppuVar5 + (long)cVar3 * 2 + 1) & 0x20) != 0) break;
      if (cVar3 == 0x3d) {
        return 0xffffffff;
      }
      pcVar6 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",(int)cVar3)
      ;
      if (pcVar6 == (char *)0x0) {
        return 0xffffffff;
      }
    }
LAB_0013921b:
    param_1 = param_1 + 1;
    iVar10 = 1;
  } while( true );
}



// Function: bcrypt_hash @ 0x39300

undefined8 bcrypt_hash(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  long in_FS_OFFSET;
  undefined2 local_10da;
  undefined4 local_10d8 [8];
  undefined4 local_10b8 [1044];
  char local_68 [8];
  char acStack_60 [8];
  char local_58 [8];
  char acStack_50 [16];
  long local_40;
  
  iVar2 = 0x40;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_68 = (char  [8])s_OxychromaticBlowfishSwatDynamite_0015bcf0._0_8_;
  acStack_60 = (char  [8])s_OxychromaticBlowfishSwatDynamite_0015bcf0._8_8_;
  local_58 = (char  [8])s_OxychromaticBlowfishSwatDynamite_0015bcf0._16_8_;
  acStack_50._0_8_ = s_OxychromaticBlowfishSwatDynamite_0015bcf0._24_8_;
  FUN_0013a290(local_10b8);
  FUN_0013a5d0(local_10b8,param_2,0x40,param_1,0x40);
  do {
    FUN_0013a420(local_10b8,param_2,0x40);
    FUN_0013a420(local_10b8,param_1,0x40);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_10da = 0;
  puVar3 = local_10d8;
  do {
    puVar4 = puVar3 + 1;
    uVar1 = FUN_0013a350(local_68,0x20,&local_10da);
    *puVar3 = uVar1;
    puVar3 = puVar4;
  } while (puVar4 != local_10b8);
  iVar2 = 0x40;
  do {
    FUN_0013a840(local_10b8,local_10d8,4);
    iVar2 = iVar2 + -1;
    puVar3 = local_10d8;
  } while (iVar2 != 0);
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *param_3 = (char)uVar1;
    param_3[1] = (char)((uint)uVar1 >> 8);
    param_3[3] = (char)((uint)uVar1 >> 0x18);
    param_3[2] = (char)((uint)uVar1 >> 0x10);
    param_3 = param_3 + 4;
  } while (puVar3 != local_10b8);
  __explicit_bzero_chk(local_68,0x20,0x20);
  __explicit_bzero_chk(local_10d8,0x20,0x20);
  __explicit_bzero_chk(puVar3,0x1048,0x1048);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// Function: bcrypt_pbkdf @ 0x39530

undefined8
bcrypt_pbkdf(undefined8 param_1,long param_2,void *param_3,size_t param_4,long param_5,ulong param_6
            ,uint param_7)

{
  size_t __size;
  ulong uVar1;
  void *__dest;
  ulong uVar2;
  ulong uVar3;
  byte *pbVar4;
  ulong uVar5;
  undefined8 uVar6;
  byte *pbVar7;
  ulong uVar8;
  long in_FS_OFFSET;
  int local_16c;
  ulong local_168;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined1 local_c8 [64];
  undefined1 local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if ((((param_7 != 0) && (param_4 - 1 < 0x100000)) && (param_2 != 0)) && (param_6 - 1 < 0x400)) {
    __size = param_4 + 4;
    __dest = calloc(1,__size);
    if (__dest != (void *)0x0) {
      uVar2 = param_6 + 0x1f >> 5;
      uVar3 = ((param_6 - 1) + uVar2) / uVar2;
      memcpy(__dest,param_3,param_4);
      FUN_001310d0(local_c8,param_1,param_2);
      local_16c = 1;
      local_168 = param_6;
      do {
        while( true ) {
          *(char *)((long)__dest + param_4) = (char)((uint)local_16c >> 0x18);
          *(char *)((long)__dest + param_4 + 1) = (char)((uint)local_16c >> 0x10);
          *(char *)((long)__dest + param_4 + 2) = (char)((uint)local_16c >> 8);
          *(char *)((long)__dest + param_4 + 3) = (char)local_16c;
          FUN_001310d0(local_88,__dest,__size);
          FUN_00139300(local_c8,local_88,&local_e8);
          local_108 = local_e8;
          uStack_100 = uStack_e0;
          local_f8 = local_d8;
          uStack_f0 = uStack_d0;
          if (param_7 != 1) {
            uVar8 = 1;
            do {
              FUN_001310d0(local_88,&local_e8,0x20);
              FUN_00139300(local_c8,local_88,&local_e8);
              pbVar4 = (byte *)&local_108;
              pbVar7 = (byte *)&local_e8;
              do {
                *pbVar4 = *pbVar4 ^ *pbVar7;
                pbVar4 = pbVar4 + 1;
                pbVar7 = pbVar7 + 1;
              } while ((byte *)&local_e8 != pbVar4);
              uVar8 = uVar8 + 1;
            } while (uVar8 != param_7);
          }
          if (local_168 < uVar3) {
            uVar3 = local_168;
          }
          if ((uVar3 != 0) && (uVar8 = (ulong)(local_16c - 1), uVar8 < param_6)) break;
          local_16c = local_16c + 1;
        }
        uVar5 = 0;
        do {
          pbVar4 = (byte *)((long)&local_108 + uVar5);
          uVar5 = uVar5 + 1;
          *(byte *)(param_5 + uVar8) = *pbVar4;
          uVar1 = uVar3;
          if (uVar3 == uVar5) break;
          uVar8 = uVar8 + uVar2;
          uVar1 = uVar5;
        } while (uVar8 < param_6);
        local_168 = local_168 - uVar1;
        local_16c = local_16c + 1;
      } while (local_168 != 0);
      FUN_0013b0d0(__dest,__size);
      __explicit_bzero_chk(&local_108,0x20,0x20);
      __explicit_bzero_chk(&local_e8,0x20,0x20);
      uVar6 = 0;
      goto LAB_001397f8;
    }
  }
  thunk_FUN_00138930(param_5,param_6);
  uVar6 = 0xffffffff;
LAB_001397f8:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



// Function: Blowfish_encipher @ 0x398d0

undefined8 Blowfish_encipher(long param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = *param_2 ^ *(uint *)(param_1 + 0x1000);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          *(uint *)(param_1 + 0x1004) ^ *param_3;
  uVar6 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x1008);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar6 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar6 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar6 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x100c);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar6 ^ *(uint *)(param_1 + 0x1010);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x1014);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x1018);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x101c);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x1020);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x1024);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x1028);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x102c);
  uVar6 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x1030);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar6 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar6 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar6 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x1034);
  uVar7 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar6 ^ *(uint *)(param_1 + 0x1038);
  uVar4 = *(uint *)(param_1 + 0x1040);
  uVar6 = (*(int *)(param_1 + (ulong)(uVar7 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar7 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar7 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x103c);
  iVar1 = *(int *)(param_1 + (ulong)(uVar6 >> 0x18) * 4);
  iVar2 = *(int *)(param_1 + 0x400 + (ulong)(uVar6 >> 0x10 & 0xff) * 4);
  uVar5 = *(uint *)(param_1 + (ulong)((uVar6 >> 8 & 0xff) + 0x200) * 4);
  iVar3 = *(int *)(param_1 + 0xc00 + (ulong)(uVar6 & 0xff) * 4);
  *param_2 = uVar6 ^ *(uint *)(param_1 + 0x1044);
  *param_3 = (iVar1 + iVar2 ^ uVar5) + iVar3 ^ uVar7 ^ uVar4;
  return 0;
}



// Function: Blowfish_decipher @ 0x39db0

undefined8 Blowfish_decipher(long param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = *param_2 ^ *(uint *)(param_1 + 0x1044);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          *(uint *)(param_1 + 0x1040) ^ *param_3;
  uVar6 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x103c);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar6 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar6 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar6 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x1038);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar6 ^ *(uint *)(param_1 + 0x1034);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x1030);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x102c);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x1028);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x1024);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x1020);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x101c);
  uVar4 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x1018);
  uVar6 = (*(int *)(param_1 + (ulong)(uVar4 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar4 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar4 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x1014);
  uVar5 = (*(int *)(param_1 + (ulong)(uVar6 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar6 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar6 & 0xff) * 4) ^
          uVar4 ^ *(uint *)(param_1 + 0x1010);
  uVar7 = (*(int *)(param_1 + (ulong)(uVar5 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar5 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar5 & 0xff) * 4) ^
          uVar6 ^ *(uint *)(param_1 + 0x100c);
  uVar4 = *(uint *)(param_1 + 0x1004);
  uVar6 = (*(int *)(param_1 + (ulong)(uVar7 >> 0x18) * 4) +
           *(int *)(param_1 + 0x400 + (ulong)(uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(param_1 + (ulong)((uVar7 >> 8 & 0xff) + 0x200) * 4)) +
          *(int *)(param_1 + 0xc00 + (ulong)(uVar7 & 0xff) * 4) ^
          uVar5 ^ *(uint *)(param_1 + 0x1008);
  iVar1 = *(int *)(param_1 + (ulong)(uVar6 >> 0x18) * 4);
  iVar2 = *(int *)(param_1 + 0x400 + (ulong)(uVar6 >> 0x10 & 0xff) * 4);
  uVar5 = *(uint *)(param_1 + (ulong)((uVar6 >> 8 & 0xff) + 0x200) * 4);
  iVar3 = *(int *)(param_1 + 0xc00 + (ulong)(uVar6 & 0xff) * 4);
  *param_2 = uVar6 ^ *(uint *)(param_1 + 0x1000);
  *param_3 = (iVar1 + iVar2 ^ uVar5) + iVar3 ^ uVar7 ^ uVar4;
  return 0;
}



// Function: Blowfish_initstate @ 0x3a290

undefined8 Blowfish_initstate(undefined8 *param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  *param_1 = DAT_0015bd20;
  param_1[0x208] = DAT_0015cd60;
  lVar1 = (long)param_1 - (long)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
  puVar3 = (undefined8 *)((long)&DAT_0015bd20 - lVar1);
  puVar4 = (undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
  for (uVar2 = (ulong)((int)lVar1 + 0x1048U >> 3); uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return 0;
}



// Function: Blowfish_stream2word @ 0x3a350

uint Blowfish_stream2word(byte *param_1,ushort param_2,ushort *param_3)

{
  uint uVar1;
  ushort uVar2;
  char cVar3;
  ulong uVar4;
  byte *pbVar5;
  
  uVar2 = *param_3;
  cVar3 = '\x04';
  uVar1 = 0;
  do {
    if (uVar2 < param_2) {
      uVar4 = (ulong)uVar2;
      uVar2 = uVar2 + 1;
      pbVar5 = param_1 + uVar4;
    }
    else {
      uVar2 = 1;
      pbVar5 = param_1;
    }
    uVar1 = uVar1 << 8 | (uint)*pbVar5;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  *param_3 = uVar2;
  return uVar1;
}



// Function: Blowfish_expand0state @ 0x3a420

undefined8 Blowfish_expand0state(long param_1,undefined8 param_2,undefined2 param_3)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  long in_FS_OFFSET;
  undefined2 local_4a;
  uint local_48;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_4a = 0;
  puVar2 = (uint *)(param_1 + 0x1000);
  do {
    uVar1 = FUN_0013a350(param_2,param_3,&local_4a);
    *puVar2 = *puVar2 ^ uVar1;
    puVar2 = puVar2 + 1;
  } while (puVar2 != (uint *)(param_1 + 0x1048));
  local_48 = 0;
  local_4a = 0;
  local_44 = 0;
  puVar2 = (uint *)(param_1 + 0x1000);
  do {
    puVar3 = puVar2 + 2;
    FUN_001398d0(param_1,&local_48,&local_44);
    *puVar2 = local_48;
    puVar2[1] = local_44;
    puVar2 = puVar3;
  } while (puVar3 != (uint *)(param_1 + 0x1048));
  puVar2 = (uint *)(param_1 + 0x400);
  do {
    puVar3 = puVar2 + -0x100;
    do {
      puVar4 = puVar3;
      FUN_001398d0(param_1,&local_48,&local_44);
      *puVar4 = local_48;
      puVar4[1] = local_44;
      puVar3 = puVar4 + 2;
    } while (puVar4 + 2 != puVar2);
    puVar2 = puVar4 + 0x102;
  } while (puVar2 != (uint *)(param_1 + 0x1400));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: Blowfish_expandstate @ 0x3a5d0

undefined8
Blowfish_expandstate(long param_1,undefined8 param_2,undefined2 param_3,undefined8 param_4,
            undefined2 param_5)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  long in_FS_OFFSET;
  uint *local_68;
  uint *local_60;
  undefined2 local_4a;
  uint local_48;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_4a = 0;
  puVar3 = (uint *)(param_1 + 0x1000);
  do {
    uVar1 = FUN_0013a350(param_4,param_5,&local_4a);
    *puVar3 = *puVar3 ^ uVar1;
    puVar3 = puVar3 + 1;
  } while (puVar3 != (uint *)(param_1 + 0x1048));
  local_48 = 0;
  local_4a = 0;
  local_44 = 0;
  local_60 = (uint *)(param_1 + 0x1000);
  do {
    uVar1 = FUN_0013a350(param_2,param_3,&local_4a);
    local_48 = local_48 ^ uVar1;
    uVar1 = FUN_0013a350(param_2,param_3,&local_4a);
    local_44 = local_44 ^ uVar1;
    FUN_001398d0(param_1,&local_48,&local_44);
    *local_60 = local_48;
    puVar3 = local_60 + 2;
    local_60[1] = local_44;
    local_60 = puVar3;
  } while (puVar3 != (uint *)(param_1 + 0x1048));
  local_68 = (uint *)(param_1 + 0x400);
  do {
    puVar3 = local_68 + -0x100;
    do {
      puVar2 = puVar3;
      uVar1 = FUN_0013a350(param_2,param_3,&local_4a);
      local_48 = local_48 ^ uVar1;
      uVar1 = FUN_0013a350(param_2,param_3,&local_4a);
      local_44 = local_44 ^ uVar1;
      FUN_001398d0(param_1,&local_48,&local_44);
      *puVar2 = local_48;
      puVar2[1] = local_44;
      puVar3 = puVar2 + 2;
    } while (puVar2 + 2 != local_68);
    local_68 = puVar2 + 0x102;
  } while (local_68 != (uint *)(param_1 + 0x1400));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: blf_key @ 0x3a810

void blf_key(undefined8 param_1,undefined8 param_2,undefined2 param_3)

{
  FUN_0013a290();
  FUN_0013a420(param_1,param_2,param_3);
  return;
}



// Function: blf_enc @ 0x3a840

undefined8 blf_enc(undefined8 param_1,long param_2,ushort param_3)

{
  long lVar1;
  long lVar2;
  
  if (param_3 != 0) {
    lVar1 = param_2;
    do {
      lVar2 = lVar1 + 8;
      FUN_001398d0(param_1,lVar1,lVar1 + 4);
      lVar1 = lVar2;
    } while (lVar2 != param_2 + (ulong)param_3 * 8);
    return 0;
  }
  return 0;
}



// Function: blf_dec @ 0x3a980

undefined8 blf_dec(undefined8 param_1,long param_2,ushort param_3)

{
  long lVar1;
  long lVar2;
  
  if (param_3 != 0) {
    lVar1 = param_2;
    do {
      lVar2 = lVar1 + 8;
      FUN_00139db0(param_1,lVar1,lVar1 + 4);
      lVar1 = lVar2;
    } while (lVar2 != param_2 + (ulong)param_3 * 8);
    return 0;
  }
  return 0;
}



// Function: blf_ecb_encrypt @ 0x3aac0

undefined8 blf_ecb_encrypt(undefined8 param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  long in_FS_OFFSET;
  uint local_48;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 != 0) {
    uVar2 = 0;
    do {
      uVar1 = *param_2;
      uVar2 = uVar2 + 8;
      local_48 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[1];
      local_44 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      FUN_001398d0(param_1,&local_48,&local_44);
      *(char *)((long)param_2 + 2) = (char)(local_48 >> 8);
      *(char *)((long)param_2 + 3) = (char)local_48;
      *(char *)param_2 = (char)(local_48 >> 0x18);
      *(char *)((long)param_2 + 1) = (char)(local_48 >> 0x10);
      *(char *)((long)param_2 + 6) = (char)(local_44 >> 8);
      *(char *)(param_2 + 1) = (char)(local_44 >> 0x18);
      *(char *)((long)param_2 + 7) = (char)local_44;
      *(char *)((long)param_2 + 5) = (char)(local_44 >> 0x10);
      param_2 = param_2 + 2;
    } while (uVar2 < param_3);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: blf_ecb_decrypt @ 0x3ac10

undefined8 blf_ecb_decrypt(undefined8 param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  long in_FS_OFFSET;
  uint local_48;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 != 0) {
    uVar2 = 0;
    do {
      uVar1 = *param_2;
      uVar2 = uVar2 + 8;
      local_48 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[1];
      local_44 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      FUN_00139db0(param_1,&local_48,&local_44);
      *(char *)((long)param_2 + 2) = (char)(local_48 >> 8);
      *(char *)((long)param_2 + 3) = (char)local_48;
      *(char *)param_2 = (char)(local_48 >> 0x18);
      *(char *)((long)param_2 + 1) = (char)(local_48 >> 0x10);
      *(char *)((long)param_2 + 6) = (char)(local_44 >> 8);
      *(char *)(param_2 + 1) = (char)(local_44 >> 0x18);
      *(char *)((long)param_2 + 7) = (char)local_44;
      *(char *)((long)param_2 + 5) = (char)(local_44 >> 0x10);
      param_2 = param_2 + 2;
    } while (uVar2 < param_3);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: blf_cbc_encrypt @ 0x3ad60

undefined8 blf_cbc_encrypt(undefined8 param_1,uint *param_2,uint *param_3,uint param_4)

{
  long lVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  long in_FS_OFFSET;
  uint local_48;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_4 != 0) {
    uVar2 = (uint)(byte)*param_2;
    uVar4 = 0;
    do {
      puVar3 = param_3;
      lVar1 = 0;
      while( true ) {
        *(byte *)((long)puVar3 + lVar1) = *(byte *)((long)puVar3 + lVar1) ^ (byte)uVar2;
        lVar1 = lVar1 + 1;
        if (lVar1 == 8) break;
        uVar2 = (uint)*(byte *)((long)param_2 + lVar1);
      }
      uVar2 = *puVar3;
      uVar4 = uVar4 + 8;
      local_48 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar2 = puVar3[1];
      local_44 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      FUN_001398d0(param_1,&local_48,&local_44);
      *(byte *)((long)puVar3 + 2) = (byte)(local_48 >> 8);
      uVar2 = local_48 >> 0x18;
      *(byte *)((long)puVar3 + 3) = (byte)local_48;
      *(byte *)puVar3 = (byte)(local_48 >> 0x18);
      *(byte *)((long)puVar3 + 1) = (byte)(local_48 >> 0x10);
      *(byte *)((long)puVar3 + 6) = (byte)(local_44 >> 8);
      *(byte *)(puVar3 + 1) = (byte)(local_44 >> 0x18);
      *(byte *)((long)puVar3 + 7) = (byte)local_44;
      *(byte *)((long)puVar3 + 5) = (byte)(local_44 >> 0x10);
      param_3 = puVar3 + 2;
      param_2 = puVar3;
    } while (uVar4 < param_4);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// Function: blf_cbc_decrypt @ 0x3aed0

undefined8 blf_cbc_decrypt(undefined8 param_1,long param_2,long param_3,uint param_4)

{
  long lVar1;
  uint uVar2;
  uint *puVar3;
  long lVar4;
  uint *puVar5;
  long in_FS_OFFSET;
  uint local_48;
  uint local_44;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar4 = param_3 + -0x10 + (ulong)param_4;
  puVar3 = (uint *)(param_3 + -8 + (ulong)param_4);
  puVar5 = puVar3;
  if (7 < param_4 - 8) {
    puVar5 = puVar3 + (ulong)((param_4 - 0x10 >> 3) + 1) * -2;
    do {
      uVar2 = *puVar3;
      local_48 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar2 = puVar3[1];
      local_44 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      FUN_00139db0(param_1,&local_48,&local_44);
      *(char *)((long)puVar3 + 2) = (char)(local_48 >> 8);
      uVar2 = local_48 >> 0x18;
      *(char *)((long)puVar3 + 3) = (char)local_48;
      *(char *)puVar3 = (char)(local_48 >> 0x18);
      *(char *)((long)puVar3 + 1) = (char)(local_48 >> 0x10);
      *(char *)((long)puVar3 + 6) = (char)(local_44 >> 8);
      *(char *)(puVar3 + 1) = (char)(local_44 >> 0x18);
      *(char *)((long)puVar3 + 7) = (char)local_44;
      lVar1 = 0;
      *(char *)((long)puVar3 + 5) = (char)(local_44 >> 0x10);
      while( true ) {
        *(byte *)((long)puVar3 + lVar1) = (byte)uVar2 ^ *(byte *)(lVar4 + lVar1);
        lVar1 = lVar1 + 1;
        if (lVar1 == 8) break;
        uVar2 = (uint)*(byte *)((long)puVar3 + lVar1);
      }
      puVar3 = puVar3 + -2;
      lVar4 = lVar4 + -8;
    } while (puVar5 != puVar3);
  }
  uVar2 = *puVar5;
  local_48 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = puVar5[1];
  local_44 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  FUN_00139db0(param_1,&local_48,&local_44);
  uVar2 = local_48 >> 0x18;
  *puVar5 = local_48 >> 0x18 | (local_48 & 0xff0000) >> 8 | (local_48 & 0xff00) << 8 |
            local_48 << 0x18;
  puVar5[1] = local_44 >> 0x18 | (local_44 & 0xff0000) >> 8 | (local_44 & 0xff00) << 8 |
              local_44 << 0x18;
  lVar4 = 0;
  while( true ) {
    *(byte *)((long)puVar5 + lVar4) = (byte)uVar2 ^ *(byte *)(param_2 + lVar4);
    lVar4 = lVar4 + 1;
    if (lVar4 == 8) break;
    uVar2 = (uint)*(byte *)((long)puVar5 + lVar4);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// Function: freezero @ 0x3b0d0

undefined8 freezero(void *param_1,undefined8 param_2)

{
  undefined8 extraout_RAX;
  
  if (param_1 != (void *)0x0) {
    __explicit_bzero_chk(param_1,param_2,0xffffffffffffffff);
    free(param_1);
    return extraout_RAX;
  }
  return 0;
}



// Function: gcd @ 0x3b180

ulong gcd(int param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  uVar1 = (long)param_1 % (long)(int)param_2;
  if ((int)uVar1 != 0) {
    do {
      uVar2 = uVar1 & 0xffffffff;
      uVar3 = (uint)uVar1;
      uVar1 = (long)(int)param_2 % (long)(int)uVar3;
      param_2 = uVar3;
    } while ((int)uVar1 != 0);
    return uVar2;
  }
  return (ulong)param_2;
}



// Function: permute_args @ 0x3b2b0

undefined8 permute_args(undefined4 param_1,int param_2,undefined4 param_3,long param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  int local_48;
  
  uVar4 = FUN_0013da60(param_2,param_1);
  uVar5 = FUN_0013da60(param_3,param_2);
  iVar6 = FUN_0013b180(uVar4,uVar5);
  iVar7 = FUN_0013da60(param_3,param_1);
  local_48 = param_2;
  if (0 < iVar6) {
    do {
      if (0 < iVar7 / iVar6) {
        iVar8 = 0;
        puVar1 = (undefined8 *)(param_4 + (long)local_48 * 8);
        uVar10 = *puVar1;
        iVar9 = local_48;
        do {
          if (iVar9 < param_2) {
            iVar9 = FUN_0013da20(iVar9,uVar5);
          }
          else {
            iVar9 = FUN_0013da60(iVar9,uVar4);
          }
          puVar2 = (undefined8 *)(param_4 + (long)iVar9 * 8);
          uVar3 = *puVar2;
          *puVar2 = uVar10;
          *puVar1 = uVar3;
          iVar8 = FUN_0013da20(iVar8,1);
          uVar10 = uVar3;
        } while (iVar7 / iVar6 != iVar8);
      }
      local_48 = local_48 + 1;
    } while (iVar6 + param_2 != local_48);
  }
  return 0;
}



// Function: recallocarray @ 0x3ba50

void * recallocarray(void *param_1,ulong param_2,ulong param_3,ulong param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  int iVar5;
  void *pvVar6;
  int *piVar7;
  ulong __n;
  
  if (param_1 == (void *)0x0) {
    pvVar6 = calloc(param_3,param_4);
    return pvVar6;
  }
  if ((((param_3 | param_4) < 0x100000000) || (param_3 == 0)) ||
     (auVar1._8_8_ = 0, auVar1._0_8_ = param_4, auVar3._8_8_ = 0, auVar3._0_8_ = param_3,
     SUB168(auVar1 * auVar3,8) == 0)) {
    param_3 = param_3 * param_4;
    if (((param_2 == 0) || ((param_4 | param_2) < 0x100000000)) ||
       (auVar2._8_8_ = 0, auVar2._0_8_ = param_4, auVar4._8_8_ = 0, auVar4._0_8_ = param_2,
       SUB168(auVar2 * auVar4,8) == 0)) {
      param_4 = param_4 * param_2;
      if (param_3 < param_4 || param_3 - param_4 == 0) {
        __n = param_4 - param_3;
        if ((__n < param_4 >> 1) && (iVar5 = getpagesize(), __n < (ulong)(long)iVar5)) {
          memset((void *)((long)param_1 + param_3),0,__n);
          return param_1;
        }
        pvVar6 = malloc(param_3);
        if (pvVar6 == (void *)0x0) {
          return (void *)0x0;
        }
        memcpy(pvVar6,param_1,param_3);
      }
      else {
        pvVar6 = malloc(param_3);
        if (pvVar6 == (void *)0x0) {
          return (void *)0x0;
        }
        memcpy(pvVar6,param_1,param_4);
        memset((void *)((long)pvVar6 + param_4),0,param_3 - param_4);
      }
      __explicit_bzero_chk(param_1,param_4,0xffffffffffffffff);
      free(param_1);
    }
    else {
      piVar7 = __errno_location();
      pvVar6 = (void *)0x0;
      *piVar7 = 0x16;
    }
  }
  else {
    piVar7 = __errno_location();
    pvVar6 = (void *)0x0;
    *piVar7 = 0xc;
  }
  return pvVar6;
}



// Function: strlcat @ 0x3bcf0

long strlcat(char *param_1,char *param_2,long param_3)

{
  char *pcVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  
  if (param_3 == 0) {
    lVar3 = 0;
  }
  else {
    pcVar6 = param_1;
    do {
      if (*pcVar6 == '\0') break;
      pcVar6 = pcVar6 + 1;
    } while (pcVar6 != param_1 + param_3);
    lVar3 = FUN_0013da40(pcVar6,param_1);
    param_3 = param_3 - lVar3;
    if (param_3 != 0) {
      cVar2 = *param_2;
      pcVar7 = param_2;
      if (cVar2 != '\0') {
        do {
          if (param_3 == 1) {
            pcVar1 = pcVar7 + 1;
            pcVar7 = pcVar7 + 1;
            if (*pcVar1 == '\0') {
              lVar4 = FUN_0013da40(pcVar7,param_2);
              lVar3 = lVar3 + lVar4;
              goto LAB_0013bd99;
            }
          }
          else {
            *pcVar6 = cVar2;
            param_3 = param_3 + -1;
            pcVar6 = pcVar6 + 1;
          }
          cVar2 = pcVar7[1];
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        lVar4 = FUN_0013da40(pcVar7,param_2);
        lVar3 = lVar3 + lVar4;
      }
LAB_0013bd99:
      *pcVar6 = '\0';
      return lVar3;
    }
  }
  sVar5 = strlen(param_2);
  return lVar3 + sVar5;
}



// Function: strlcpy @ 0x3bee0

undefined8 strlcpy(char *param_1,char *param_2,long param_3)

{
  char cVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  if (param_3 == 0) goto LAB_0013bfd0;
  pcVar2 = param_1;
  while (pcVar2 != param_1 + param_3 + -1) {
    cVar1 = *param_2;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
    param_2 = param_2 + 1;
    if (cVar1 == '\0') goto LAB_0013bf2f;
  }
  *pcVar2 = '\0';
  cVar1 = *param_2;
  while (param_2 = param_2 + 1, cVar1 != '\0') {
LAB_0013bfd0:
    cVar1 = *param_2;
  }
LAB_0013bf2f:
  uVar3 = FUN_0013da40();
  FUN_0013da00(uVar3,0xffffffffffffffff);
  return 0;
}



// Function: strtonum @ 0x3bfe0

longlong strtonum(char *param_1,long param_2,long param_3,undefined8 *param_4)

{
  int *piVar1;
  long lVar2;
  longlong lVar3;
  int iVar4;
  long in_FS_OFFSET;
  char *local_90;
  char *apcStack_88 [9];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  apcStack_88[2] = "invalid";
  apcStack_88[4] = "too small";
  apcStack_88[6] = "too large";
  piVar1 = __errno_location();
  iVar4 = *piVar1;
  *piVar1 = 0;
  if (((param_3 < param_2) || (lVar3 = strtoll(param_1,&local_90,10), local_90 == param_1)) ||
     (*local_90 != '\0')) {
    iVar4 = 0x16;
    lVar2 = 1;
  }
  else {
    if (lVar3 == -0x8000000000000000) {
      if ((*piVar1 != 0x22) && (param_2 == -0x8000000000000000)) {
LAB_0013c19a:
        if (param_4 != (undefined8 *)0x0) {
          *param_4 = 0;
        }
        goto LAB_0013c068;
      }
    }
    else if (param_2 <= lVar3) {
      if (((lVar3 != 0x7fffffffffffffff) || (*piVar1 != 0x22)) && (lVar3 <= param_3))
      goto LAB_0013c19a;
      iVar4 = 0x22;
      lVar2 = 3;
      goto LAB_0013c055;
    }
    iVar4 = 0x22;
    lVar2 = 2;
  }
LAB_0013c055:
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = apcStack_88[lVar2 * 2];
  }
  lVar3 = 0;
LAB_0013c068:
  *piVar1 = iVar4;
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



// Function: timingsafe_bcmp @ 0x3c1c0

bool timingsafe_bcmp(long param_1,long param_2,long param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  long lVar3;
  byte bVar4;
  
  if (param_3 != 0) {
    lVar3 = 0;
    bVar4 = 0;
    do {
      pbVar1 = (byte *)(param_1 + lVar3);
      pbVar2 = (byte *)(param_2 + lVar3);
      lVar3 = lVar3 + 1;
      bVar4 = bVar4 | *pbVar1 ^ *pbVar2;
    } while (param_3 != lVar3);
    return bVar4 != 0;
  }
  return false;
}



// Function: vis @ 0x3c300

byte * vis(byte *param_1,uint param_2,uint param_3,char param_4)

{
  ushort **ppuVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  
  bVar3 = (byte)param_2;
  if (param_2 == 0x5c) {
    uVar4 = 0x5c;
LAB_0013c506:
    ppuVar1 = __ctype_b_loc();
    if (-1 < (short)(*ppuVar1)[(int)param_2]) goto LAB_0013c333;
LAB_0013c51f:
    if (param_2 == 0x22) {
      if ((param_3 & 0x200) == 0) goto LAB_0013c539;
    }
    else if ((param_2 != 0x5c) || ((param_3 & 0x40) != 0)) goto LAB_0013c539;
    *param_1 = 0x5c;
    param_1 = param_1 + 1;
LAB_0013c539:
    *param_1 = bVar3;
    param_1[1] = 0;
    return param_1 + 1;
  }
  if ((param_3 & 0x400) == 0) {
    uVar4 = param_2;
    if ((param_2 < 0x100) && ((param_2 & 0x80) == 0)) {
      if (0x38 < param_2 - 0x23) goto LAB_0013c506;
      if (((0xfeffffffefffff7eU >> ((ulong)(param_2 - 0x23) & 0x3f) & 1) != 0) ||
         ((param_3 & 0x100) == 0)) {
        ppuVar1 = __ctype_b_loc();
        if ((short)(*ppuVar1)[(int)param_2] < 0) goto LAB_0013c539;
        goto LAB_0013c333;
      }
    }
    else {
LAB_0013c333:
      if (((param_3 & 4) == 0) && (param_2 == 0x20)) goto LAB_0013c539;
    }
    if ((((param_3 & 8) == 0) && (param_2 == 9)) || (((param_3 & 0x10) == 0 && (param_2 == 10))))
    goto LAB_0013c539;
    if (((param_3 & 0x20) != 0) &&
       (((uVar4 - 7 < 2 || (param_2 == 0xd)) ||
        (ppuVar1 = __ctype_b_loc(), (short)(*ppuVar1)[param_2 & 0xff] < 0)))) goto LAB_0013c51f;
  }
  if ((param_3 & 2) != 0) {
    switch(param_2) {
    case 0:
      pbVar2 = param_1 + 2;
      param_1[0] = 0x5c;
      param_1[1] = 0x30;
      if ((byte)(param_4 - 0x30U) < 8) {
        pbVar2 = param_1 + 4;
        param_1[2] = 0x30;
        param_1[3] = 0x30;
      }
      break;
    default:
      goto switchD_0013c3bb_caseD_1;
    case 7:
      pbVar2 = param_1 + 2;
      param_1[0] = 0x5c;
      param_1[1] = 0x61;
      break;
    case 8:
      pbVar2 = param_1 + 2;
      param_1[0] = 0x5c;
      param_1[1] = 0x62;
      break;
    case 9:
      pbVar2 = param_1 + 2;
      param_1[0] = 0x5c;
      param_1[1] = 0x74;
      break;
    case 10:
      pbVar2 = param_1 + 2;
      param_1[0] = 0x5c;
      param_1[1] = 0x6e;
      break;
    case 0xb:
      pbVar2 = param_1 + 2;
      param_1[0] = 0x5c;
      param_1[1] = 0x76;
      break;
    case 0xc:
      pbVar2 = param_1 + 2;
      param_1[0] = 0x5c;
      param_1[1] = 0x66;
      break;
    case 0xd:
      pbVar2 = param_1 + 2;
      param_1[0] = 0x5c;
      param_1[1] = 0x72;
      break;
    case 0x20:
      pbVar2 = param_1 + 2;
      param_1[0] = 0x5c;
      param_1[1] = 0x73;
    }
    goto LAB_0013c46e;
  }
switchD_0013c3bb_caseD_1:
  if (((param_2 & 0x7f) == 0x20) || ((param_3 & 1) != 0)) {
LAB_0013c440:
    *param_1 = 0x5c;
    param_1[1] = (bVar3 >> 6) + 0x30;
    param_1[3] = (bVar3 & 7) + 0x30;
    param_1[2] = (bVar3 >> 3 & 7) + 0x30;
    pbVar2 = param_1 + 4;
  }
  else {
    if (((param_3 & 0x100) == 0) || (0x38 < param_2 - 0x23)) {
      if ((param_3 & 0x40) == 0) {
LAB_0013c5d5:
        *param_1 = 0x5c;
        param_1 = param_1 + 1;
      }
      if ((param_2 & 0x80) != 0) {
        *param_1 = 0x4d;
        param_1 = param_1 + 1;
        param_2 = param_2 & 0x7f;
      }
    }
    else {
      if ((0x100000010000081U >> ((ulong)(param_2 - 0x23) & 0x3f) & 1) != 0) goto LAB_0013c440;
      if ((param_3 & 0x40) == 0) goto LAB_0013c5d5;
    }
    ppuVar1 = __ctype_b_loc();
    pbVar2 = param_1 + 2;
    if (((*ppuVar1)[param_2 & 0xff] & 2) == 0) {
      *param_1 = 0x2d;
      param_1[1] = (byte)param_2;
    }
    else {
      *param_1 = 0x5e;
      bVar3 = 0x3f;
      if (param_2 != 0x7f) {
        bVar3 = (byte)param_2 + 0x40;
      }
      param_1[1] = bVar3;
    }
  }
LAB_0013c46e:
  *pbVar2 = 0;
  return pbVar2;
}



// Function: strvis @ 0x3c780

undefined8 strvis(undefined1 *param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  
  cVar2 = *param_2;
  puVar3 = param_1;
  if (cVar2 == '\0') {
    *param_1 = 0;
    return 0;
  }
  do {
    pcVar1 = param_2 + 1;
    param_2 = param_2 + 1;
    puVar3 = (undefined1 *)FUN_0013c300(puVar3,(int)cVar2,param_3,(int)*pcVar1);
    cVar2 = *param_2;
  } while (cVar2 != '\0');
  uVar4 = FUN_0013da40(puVar3,param_1);
  *puVar3 = 0;
  return uVar4;
}



// Function: strnvis @ 0x3c8f0

undefined8 strnvis(byte *param_1,char *param_2,long param_3,uint param_4)

{
  byte *pbVar1;
  char cVar2;
  ushort **ppuVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  char *pcVar12;
  byte *__dest;
  long in_FS_OFFSET;
  int local_64;
  undefined1 local_45 [5];
  long local_40;
  ulong uVar11;
  
  pbVar1 = param_1 + param_3 + -1;
  uVar9 = (uint)*param_2;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  pbVar7 = param_1;
  __dest = param_1;
  if ((uVar9 != 0) && (param_1 < pbVar1)) {
    do {
      uVar11 = (ulong)uVar9;
      pcVar12 = param_2 + 1;
      if (uVar9 == 0x5c) {
LAB_0013ca61:
        bVar8 = (byte)uVar9;
        ppuVar3 = __ctype_b_loc();
        uVar4 = (ulong)bVar8;
        if ((short)(*ppuVar3)[uVar4] < 0) {
LAB_0013cb90:
          if (uVar9 == 0x22) {
            if ((param_4 & 0x200) != 0) {
LAB_0013cba2:
              if (pbVar1 <= __dest + 1) {
                pbVar7 = __dest + 2;
                goto LAB_0013cacf;
              }
              *__dest = 0x5c;
              __dest = __dest + 1;
            }
          }
          else if ((uVar9 == 0x5c) && ((param_4 & 0x40) == 0)) goto LAB_0013cba2;
        }
        else {
LAB_0013ca8b:
          bVar8 = (byte)uVar4;
          if (((((param_4 & 4) != 0) || (uVar9 != 0x20)) && (((param_4 & 8) != 0 || (uVar9 != 9))))
             && (((((byte)(param_4 >> 4) ^ 1) & 1) == 0 || (uVar9 != 10)))) {
            if (((param_4 & 0x20) == 0) ||
               (((1 < uVar9 - 7 && (uVar9 != 0xd)) &&
                (ppuVar3 = __ctype_b_loc(), -1 < (short)(*ppuVar3)[uVar4 & 0xff]))))
            goto LAB_0013c9c8;
            goto LAB_0013cb90;
          }
        }
        *__dest = bVar8;
        cVar2 = *pcVar12;
        __dest = __dest + 1;
        local_64 = 1;
      }
      else {
        if ((param_4 & 0x400) == 0) {
          uVar4 = uVar11;
          if ((uVar9 < 0x100) &&
             (((((uVar9 != 0x2a && (uVar9 != 0x3f)) && (uVar9 != 0x5b)) && (uVar9 != 0x23)) ||
              ((param_4 & 0x100) == 0)))) goto LAB_0013ca61;
          goto LAB_0013ca8b;
        }
LAB_0013c9c8:
        uVar5 = FUN_0013c300(local_45,uVar11,param_4,(int)*pcVar12);
        local_64 = FUN_0013da40(uVar5,local_45);
        pbVar7 = __dest + local_64;
        if (pbVar1 < pbVar7) {
          if (param_3 != 0) goto LAB_0013cc00;
          goto LAB_0013cc0d;
        }
        memcpy(__dest,local_45,(long)local_64);
        cVar2 = *pcVar12;
        __dest = pbVar7;
      }
      param_2 = pcVar12;
    } while ((__dest < pbVar1) && (uVar9 = (uint)cVar2, uVar9 != 0));
    pbVar7 = __dest + local_64;
  }
LAB_0013cacf:
  if (param_3 != 0) {
LAB_0013cc00:
    *__dest = 0;
  }
  if (pbVar1 < pbVar7) {
LAB_0013cc0d:
    iVar10 = (int)*param_2;
    if (iVar10 != 0) {
      do {
        pcVar12 = param_2 + 1;
        param_2 = param_2 + 1;
        uVar5 = FUN_0013c300(local_45,iVar10,param_4,(int)*pcVar12);
        lVar6 = FUN_0013da40(uVar5,local_45);
        iVar10 = (int)*param_2;
        __dest = __dest + lVar6;
      } while (iVar10 != 0);
    }
  }
  FUN_0013da40(__dest,param_1);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: stravis @ 0x3cc70

undefined4 stravis(undefined8 *param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  size_t sVar4;
  void *__ptr;
  int *piVar5;
  void *pvVar6;
  
  sVar4 = strlen(param_2);
  __ptr = (void *)reallocarray(0,4,sVar4 + 1);
  if (__ptr == (void *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_0013c780(__ptr,param_2,param_3);
    piVar5 = __errno_location();
    iVar1 = *piVar5;
    iVar3 = FUN_0013da20(uVar2,1);
    pvVar6 = realloc(__ptr,(long)iVar3);
    if (pvVar6 == (void *)0x0) {
      *param_1 = __ptr;
      *piVar5 = iVar1;
      return uVar2;
    }
    *param_1 = pvVar6;
  }
  return uVar2;
}



// Function: strvisx @ 0x3ce20

undefined8 strvisx(undefined1 *param_1,char *param_2,ulong param_3,undefined4 param_4)

{
  char *pcVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  puVar3 = param_1;
  if (param_3 < 2) {
    pcVar5 = param_2;
    if (param_3 == 0) {
      *param_1 = 0;
      return 0;
    }
  }
  else {
    pcVar5 = param_2 + (param_3 - 1);
    do {
      cVar2 = *param_2;
      pcVar1 = param_2 + 1;
      param_2 = param_2 + 1;
      puVar3 = (undefined1 *)FUN_0013c300(puVar3,(int)cVar2,param_4,(int)*pcVar1);
    } while (pcVar5 != param_2);
  }
  puVar3 = (undefined1 *)FUN_0013c300(puVar3,(int)*pcVar5,param_4,0);
  uVar4 = FUN_0013da40(puVar3,param_1);
  *puVar3 = 0;
  return uVar4;
}



// Function: sys_get_rdomain @ 0x3cfc0

char * sys_get_rdomain(int param_1)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  long in_FS_OFFSET;
  socklen_t local_3c;
  char local_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_3c = 0x10;
  iVar1 = getsockopt(param_1,1,0x19,local_38,&local_3c);
  if (iVar1 == -1) {
    piVar3 = __errno_location();
    pcVar2 = strerror(*piVar3);
    FUN_001203a0("port-net.c","sys_get_rdomain",0x39,0,2,0,"%s: cannot determine VRF for fd=%d : %s"
                 ,"sys_get_rdomain",param_1,pcVar2);
    pcVar2 = (char *)0x0;
  }
  else {
    local_38[local_3c] = '\0';
    pcVar2 = strdup(local_38);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sys_set_rdomain @ 0x3d110

undefined8 sys_set_rdomain(int param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  int *piVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  sVar2 = strlen(param_2);
  iVar1 = setsockopt(param_1,1,0x19,param_2,(socklen_t)sVar2);
  if (iVar1 == -1) {
    uVar5 = 0xffffffff;
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    FUN_001203a0("port-net.c","sys_set_rdomain",0x46,0,2,0,
                 "%s: setsockopt(%d, SO_BINDTODEVICE, %s): %s","sys_set_rdomain",param_1,param_2,
                 pcVar4);
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



// Function: sys_valid_rdomain @ 0x3d220

undefined8 sys_valid_rdomain(char *param_1)

{
  int __fd;
  int iVar1;
  size_t sVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  __fd = socket(2,1,0);
  if (__fd != -1) {
    sVar2 = strlen(param_1);
    iVar1 = setsockopt(__fd,1,0x19,param_1,(socklen_t)sVar2);
    if (iVar1 == -1) {
      close(__fd);
      return 0;
    }
    close(__fd);
    uVar3 = 1;
  }
  return uVar3;
}



// Function: sys_tun_open @ 0x3d3a0

int sys_tun_open(int param_1,int param_2,undefined8 *param_3)

{
  int __fd;
  int iVar1;
  int *piVar2;
  char *pcVar3;
  long in_FS_OFFSET;
  undefined1 local_58 [16];
  short local_48;
  undefined1 auStack_46 [14];
  undefined8 local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  __fd = open("/dev/net/tun",2);
  if (__fd == -1) {
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    FUN_001203a0("port-net.c","sys_tun_open",0x99,0,5,0,
                 "%s: failed to open tunnel control device \"%s\": %s","sys_tun_open","/dev/net/tun"
                 ,pcVar3);
    goto LAB_0013d4da;
  }
  local_38 = 0;
  pcVar3 = "tun%d";
  local_58 = (undefined1  [16])0x0;
  auStack_46 = SUB1614((undefined1  [16])0x0,2);
  local_48 = (param_2 == 2) + 0x1001;
  if (param_2 == 2) {
    pcVar3 = "tap%d";
  }
  if (param_1 == 0x7fffffff) {
    iVar1 = ioctl(__fd,0x400454ca,local_58);
    if (iVar1 != -1) {
      FUN_001203a0("port-net.c","sys_tun_open",0xb9,0,5,0,"%s: tunnel mode %d fd %d","sys_tun_open",
                   param_2,__fd);
      goto LAB_0013d4c1;
    }
LAB_0013d5d8:
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    FUN_001203a0("port-net.c","sys_tun_open",0xb3,0,5,0,
                 "%s: failed to configure tunnel (mode %d): %s","sys_tun_open",param_2,pcVar3);
  }
  else if (param_1 == 0x7ffffffe) {
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    FUN_001203a0("port-net.c","sys_tun_open",0xab,0,5,0,"%s: invalid tunnel id %x: %s",
                 "sys_tun_open",0x7ffffffe,pcVar3);
  }
  else {
    __snprintf_chk(local_58,0x10,1,0x10,pcVar3,param_1);
    iVar1 = ioctl(__fd,0x400454ca,local_58);
    if (iVar1 == -1) goto LAB_0013d5d8;
    FUN_001203a0("port-net.c","sys_tun_open",0xbb,0,5,0,"%s: %s mode %d fd %d","sys_tun_open",
                 local_58,param_2,__fd);
LAB_0013d4c1:
    if (param_3 == (undefined8 *)0x0) goto LAB_0013d4da;
    pcVar3 = strdup(local_58);
    *param_3 = pcVar3;
    if (pcVar3 != (char *)0x0) goto LAB_0013d4da;
  }
  close(__fd);
  __fd = -1;
LAB_0013d4da:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return __fd;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: sys_tun_infilter @ 0x3d6c0

ulong sys_tun_infilter(undefined8 param_1,long param_2,byte *param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  ulong uVar5;
  long lVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  long in_FS_OFFSET;
  undefined1 auVar9 [16];
  undefined1 local_4020 [16384];
  
  puVar4 = &stack0xffffffffffffffe0;
  do {
    puVar7 = puVar4;
    *(undefined8 *)(puVar7 + -0x1000) = *(undefined8 *)(puVar7 + -0x1000);
    puVar4 = puVar7 + -0x1000;
  } while (puVar7 + -0x1000 != local_4020);
  *(undefined8 *)(puVar7 + 0x2ff0) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  if ((param_4 < 0) || (lVar6 = (long)param_4, 0x3fe7 < lVar6 - 0x15U)) {
    uVar5 = 0xffffffff;
  }
  else {
    bVar1 = *param_3;
    uVar3 = *(undefined8 *)(param_3 + 8);
    uVar2 = *(undefined4 *)(param_3 + 0x10);
    *(undefined8 *)(puVar7 + -0x1038) = *(undefined8 *)param_3;
    *(undefined8 *)(puVar7 + -0x1030) = uVar3;
    *(undefined4 *)(puVar7 + -0x1028) = uVar2;
    uVar8 = 0x18;
    if ((bVar1 & 0xf0) != 0x60) {
      uVar8 = 2;
    }
    *(undefined8 *)(puVar7 + -0x1040) = 0x13d758;
    __memcpy_chk(puVar7 + -0x1014,param_3,lVar6);
    uVar3 = *(undefined8 *)(param_2 + 0x68);
    *(undefined2 *)(puVar7 + -0x1018) = 0;
    puVar7[-0x1016] = 0;
    puVar7[-0x1015] = uVar8;
    *(undefined8 *)(puVar7 + -0x1040) = 0x13d779;
    uVar5 = FUN_0011b6c0(uVar3,puVar7 + -0x1018,lVar6 + 4);
    if ((int)uVar5 != 0) {
      *(undefined8 *)(puVar7 + -0x1040) = 0x13d83e;
      auVar9 = FUN_0010b050(uVar5 & 0xffffffff);
      *(undefined1 (*) [16])(puVar7 + -0x1048) = auVar9;
      *(char **)(puVar7 + -0x1050) = "sys_tun_infilter";
      *(char **)(puVar7 + -0x1058) = "%s: buffer error: %s";
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar7 + -0x1060) = &UNK_0013d86e;
      FUN_0011ee30("port-net.c","sys_tun_infilter",0x15c,0,1,0);
    }
  }
  if (*(long *)(puVar7 + 0x2ff0) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar7 + -0x1040) = 0x13d837;
  __stack_chk_fail();
}



// Function: sys_tun_outfilter @ 0x3d870

long sys_tun_outfilter(undefined8 param_1,long param_2,long *param_3,ulong *param_4)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  iVar1 = FUN_0011a590(*(undefined8 *)(param_2 + 0x70),param_3,param_4);
  if (iVar1 != 0) {
    auVar2 = FUN_0010b050(iVar1);
                    /* WARNING: Subroutine does not return */
    FUN_0011ee30("port-net.c","sys_tun_outfilter",0x16a,0,1,0,"%s: buffer error: %s",
                 "sys_tun_outfilter",auVar2);
  }
  if (3 < *param_4) {
    *param_4 = *param_4 - 4;
    return *param_3 + 4;
  }
  return 0;
}



