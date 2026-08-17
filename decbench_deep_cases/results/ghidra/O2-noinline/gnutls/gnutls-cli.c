// Function: main @ 0x9640

undefined8 main(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  FILE *pFVar5;
  FILE *pFVar6;
  char *pcVar7;
  long lVar8;
  char *pcVar9;
  char cVar10;
  uint uVar11;
  ulong uVar12;
  undefined8 uVar13;
  long in_FS_OFFSET;
  byte bVar14;
  FILE *local_1258;
  undefined8 local_1248;
  undefined8 local_1240;
  undefined1 local_1238 [16];
  undefined1 local_1228 [16];
  undefined1 local_1218 [16];
  undefined1 local_1208 [16];
  _union_1457 local_11f8;
  sigset_t local_11f0;
  undefined4 local_1170;
  undefined1 local_1158 [8];
  undefined8 local_1150;
  int local_1148;
  int local_1110;
  char local_1048 [4104];
  long local_40;
  
  bVar14 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_0010c460();
  if (DAT_0019575e == '\0') {
    local_1258 = (FILE *)0x0;
  }
  else {
    local_1258 = fopen(DAT_00195848,"w+");
    if (local_1258 == (FILE *)0x0) {
      FUN_0010dc90(stderr,"Unable to open \'%s\'!\n",DAT_00195848);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    FUN_001102d0(local_1258);
  }
  gnutls_global_set_log_function(FUN_0010a220);
  gnutls_global_set_log_level(DAT_00195868);
  iVar2 = gnutls_global_init();
  if (iVar2 < 0) {
    uVar13 = gnutls_strerror(iVar2);
    __fprintf_chk(stderr,1,"global_init: %s\n",uVar13);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (DAT_001223a0 == 0) {
    __fprintf_chk(stderr,1,"No hostname given\n");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  FUN_0010dc70();
  FUN_0010b730();
  FUN_00111180(DAT_001223a0,&DAT_00122380,0x20);
  uVar11 = 0x41 - (DAT_001223b8 == 0);
  if (DAT_00122370 != 0) {
    uVar11 = uVar11 | 2;
  }
  if (DAT_0012236c != 0) {
    uVar11 = uVar11 | 0x10;
  }
  if (DAT_001223c8 == 0) {
    if (DAT_0019572e != '\0') {
      uVar11 = uVar11 | 4;
    }
  }
  else {
    uVar11 = uVar11 | 8;
  }
  pFVar6 = (FILE *)0x0;
  if (DAT_00195738 != '\0') {
    pFVar6 = fopen(DAT_001957b0,"wb");
  }
  pFVar5 = (FILE *)0x0;
  if (DAT_00195739 != '\0') {
    pFVar5 = fopen(DAT_001957b8,"wb");
  }
  FUN_00111250(local_1158,DAT_001223a0,&DAT_00122380,DAT_00195788,uVar11,"Connecting to",0,0,pFVar6,
               pFVar5);
  local_1110 = DAT_0012236c;
  if (local_1148 != 0) {
    FUN_0010dc90(stdout,"- Handshake was completed\n");
    if ((DAT_001223cc != 0) && (iVar2 = FUN_0010ba70(local_1158), iVar2 != 0)) {
LAB_001099b0:
      uVar13 = 1;
LAB_001099b6:
      FUN_00111040(local_1158,0);
      if (local_1258 != (FILE *)0x0) {
        fclose(local_1258);
      }
      if (DAT_00123720 != 0) {
        gnutls_srp_free_client_credentials();
      }
      if (DAT_00123718 != 0) {
        gnutls_psk_free_client_credentials();
      }
      gnutls_certificate_free_credentials(DAT_00123708);
      gnutls_anon_free_client_credentials(DAT_00123710);
      gnutls_global_deinit();
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return uVar13;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    FUN_0010bcd0(local_1150);
  }
  FUN_0010dc90(stdout,"\n- Simple Client Mode:\n\n");
  if ((DAT_001223bc == 0) || (iVar2 = FUN_0010d320(local_1158), iVar2 == 0)) {
    local_11f8.sa_handler = FUN_00109e70;
    sigemptyset(&local_11f0);
    local_1170 = 0;
    sigaction(0xe,(sigaction *)&local_11f8,(sigaction *)0x0);
    fflush(stdout);
    fflush(stderr);
    setbuf(stdin,(char *)0x0);
    setbuf(stdout,(char *)0x0);
    setbuf(stderr,(char *)0x0);
    local_1238 = (undefined1  [16])0x0;
    local_1228 = (undefined1  [16])0x0;
    local_1218 = (undefined1  [16])0x0;
    local_1208 = (undefined1  [16])0x0;
    if (DAT_001223b0 != 0) {
      local_1228 = ZEXT816(0x100000000);
    }
LAB_001098cf:
    do {
      cVar10 = '\0';
      while( true ) {
        do {
          while( true ) {
            if ((DAT_00122300 == 0) || (local_1148 != 0)) {
              iVar2 = FUN_0010be50(local_1158,cVar10);
            }
            else {
              __fprintf_chk(stderr,1,"*** Starting TLS handshake\n");
              iVar2 = FUN_0010d200(local_1158);
              if (iVar2 < 0) goto LAB_00109996;
              iVar2 = FUN_0010be50(local_1158,cVar10);
            }
            if (iVar2 == 3) {
              uVar13 = 0;
              goto LAB_001099b6;
            }
            if (iVar2 != 2) break;
            pcVar9 = local_1048;
            pcVar7 = pcVar9;
            for (lVar8 = 0x200; lVar8 != 0; lVar8 = lVar8 + -1) {
              pcVar7[0] = '\0';
              pcVar7[1] = '\0';
              pcVar7[2] = '\0';
              pcVar7[3] = '\0';
              pcVar7[4] = '\0';
              pcVar7[5] = '\0';
              pcVar7[6] = '\0';
              pcVar7[7] = '\0';
              pcVar7 = pcVar7 + (ulong)bVar14 * -0x10 + 8;
            }
            *pcVar7 = '\0';
            iVar2 = FUN_00110d90(local_1158,pcVar9,0x1000);
            if ((iVar2 == 0) || ((iVar2 == -0x6e && (cVar10 != '\0')))) {
              uVar13 = 0;
              FUN_0010dc90(stdout,"- Peer has closed the GnuTLS connection\n");
              goto LAB_001099b6;
            }
            iVar3 = FUN_0010d570(local_1158,iVar2);
            if (iVar3 < 0) {
              pcVar9 = "*** Server has terminated the connection abnormally.\n";
              goto LAB_0010999d;
            }
            if (0 < iVar2) {
              if (DAT_0012236c != 0) {
                FUN_0010dc90(stdout,"- Received[%d]: ",iVar2);
              }
              do {
                cVar1 = *pcVar9;
                pcVar9 = pcVar9 + 1;
                fputc((int)cVar1,stdout);
              } while (local_1048 + (ulong)(iVar2 - 1) + 1 != pcVar9);
              fflush(stdout);
            }
          }
        } while ((iVar2 != 1) || (cVar10 == '\x01'));
        iVar2 = fileno(stdin);
        uVar4 = read(iVar2,local_1048,0xfff);
        if (0 < (long)uVar4) {
          local_1048[uVar4] = '\0';
          pcVar9 = local_1048;
          uVar12 = uVar4;
          if ((DAT_00122374 != 0) && (pcVar7 = strchr(local_1048,10), pcVar7 != (char *)0x0)) {
            pcVar7[0] = '\r';
            pcVar7[1] = '\n';
            uVar4 = uVar4 + 1;
            pcVar7[2] = '\0';
            uVar12 = uVar4;
          }
          goto LAB_00109c6b;
        }
        if (local_1148 == 0) break;
        do {
          do {
            iVar2 = gnutls_bye(local_1150,1);
          } while (iVar2 == -0x34);
        } while (iVar2 == -0x1c);
        cVar10 = '\x01';
      }
      __fprintf_chk(stderr,1,"*** Starting TLS handshake\n");
      iVar2 = FUN_0010d200(local_1158);
      clearerr(stdin);
    } while (-1 < iVar2);
LAB_00109996:
    pcVar9 = "*** Handshake has failed\n";
LAB_0010999d:
    __fprintf_chk(stderr,1,pcVar9);
  }
  goto LAB_001099b0;
LAB_00109c6b:
  if (DAT_001223b0 != 0) {
    iVar2 = FUN_0010d3e0(pcVar9,uVar4,local_1158,local_1238);
    uVar4 = (ulong)iVar2;
    if (uVar4 == 0) goto LAB_001098cf;
    if ((long)uVar4 < 0) goto LAB_001099b0;
    pcVar9 = (char *)local_1238._0_8_;
  }
  if ((DAT_001223c0 == 0) || (iVar2 = gnutls_record_can_use_length_hiding(local_1150), iVar2 == 0))
  {
    iVar2 = FUN_00110f90(local_1158,pcVar9,uVar4 & 0xffffffff);
  }
  else {
    local_1248 = 0;
    local_1240 = 0x1000;
    iVar2 = FUN_00110e90(local_1158,pcVar9,uVar4 & 0xffffffff,&local_1248);
  }
  if (iVar2 < 1) {
    FUN_0010d570(local_1158,iVar2);
  }
  else if (DAT_0012236c != 0) {
    FUN_0010dc90(stdout,"- Sent: %d bytes\n",iVar2);
  }
  if (DAT_001223b0 == 0) goto LAB_001098cf;
  pcVar9 = local_1048 + uVar12;
  if (pcVar9 <= (ulong)local_1238._8_8_) goto LAB_001098cf;
  uVar4 = (long)pcVar9 - local_1238._8_8_;
  pcVar9 = (char *)local_1238._8_8_;
  goto LAB_00109c6b;
}



// Function: starttls_alarm @ 0x9e70

void starttls_alarm(void)

{
  DAT_00122300 = 1;
  return;
}



// Function: srp_username_callback @ 0x9e80

undefined8 srp_username_callback(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  if ((DAT_00122358 != 0) && (DAT_00122360 != 0)) {
    uVar1 = (*gnutls_strdup)();
    *param_2 = uVar1;
    uVar1 = (*gnutls_strdup)(DAT_00122360);
    *param_3 = uVar1;
    return 0;
  }
  return 0xffffffff;
}



// Function: read_yesno @ 0x9ed0

bool read_yesno(char *param_1)

{
  char *pcVar1;
  long in_FS_OFFSET;
  bool bVar2;
  byte local_98 [136];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  fputs(param_1,stderr);
  pcVar1 = fgets((char *)local_98,0x80,stdin);
  if (((pcVar1 == (char *)0x0) || (local_98[0] == 10)) || (local_98[0] == 0xd)) {
    bVar2 = false;
  }
  else {
    bVar2 = (local_98[0] & 0xdf) == 0x59;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: cert_callback @ 0x9f60

undefined8
cert_callback(undefined8 param_1,long param_2,int param_3,undefined8 param_4,undefined8 param_5,
            undefined8 *param_6,int *param_7,long *param_8)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  long in_FS_OFFSET;
  undefined8 local_150;
  undefined1 local_148 [264];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (DAT_0012236c != 0) {
    if (param_3 < 1) {
      FUN_0010dc90(stdout,"- Server did not send us any trusted authorities names.\n");
    }
    else {
      iVar3 = 0;
      FUN_0010dc90(stdout,"- Server\'s trusted authorities:\n");
      do {
        local_150 = 0x100;
        iVar1 = gnutls_x509_rdn_get(param_2,local_148,&local_150);
        if (-1 < iVar1) {
          FUN_0010dc90(stdout,"   [%d]: ",iVar3);
          FUN_0010dc90(stdout,"%s\n",local_148);
        }
        iVar3 = iVar3 + 1;
        param_2 = param_2 + 0x10;
      } while (param_3 != iVar3);
    }
  }
  iVar1 = gnutls_certificate_type_get2(param_1,0);
  *param_7 = 0;
  iVar3 = DAT_00123700;
  uVar2 = stdout;
  if (iVar1 == 1) {
    if (DAT_00123700 != 0) {
      if (DAT_00123620 == 0) {
        FUN_0010dc90(stdout,"- Could not find a suitable key to send to server\n");
        uVar2 = 0xffffffff;
        goto LAB_0010a08c;
      }
      *param_8 = DAT_00123620;
      *param_7 = iVar3;
      *param_6 = &DAT_00123640;
    }
    FUN_0010dc90(uVar2,"- Successfully sent %u certificate(s) to server.\n");
    uVar2 = 0;
  }
  else if (iVar1 == 3) {
    if ((DAT_001235e8 == 0) || (DAT_00123618 != 3)) {
      FUN_0010dc90(stdout,"- Could not find a suitable key to send to server\n");
      uVar2 = 0xffffffff;
    }
    else {
      *param_8 = DAT_001235e8;
      *param_6 = &DAT_00123600;
      *param_7 = 1;
      FUN_0010dc90(uVar2,"- Successfully sent %u certificate(s) to server.\n",1);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = gnutls_certificate_type_get_name(iVar1);
    FUN_0010dc90(stdout,"- Could not retrieve unsupported certificate type %s.\n",uVar2);
    uVar2 = 0xffffffff;
  }
LAB_0010a08c:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: tls_log_func @ 0x12990

void tls_log_func(undefined4 param_1,undefined8 param_2)

{
  __fprintf_chk(stderr,1,&DAT_001183d0,PTR_DAT_00122298,param_1,param_2);
  return;
}



// Function: try_save_cert @ 0xa250

void try_save_cert(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  FILE *__s;
  undefined8 uVar3;
  uint uVar4;
  long in_FS_OFFSET;
  uint local_4c;
  void *local_48;
  uint local_40;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_4c = 0;
  lVar2 = gnutls_certificate_get_peers(param_1,&local_4c);
  if (local_4c == 0) {
    __fprintf_chk(stderr,1,"no certificates sent by server!\n");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __s = fopen(DAT_00195798,"w");
  if (__s == (FILE *)0x0) {
    __fprintf_chk(stderr,1,"could not open %s\n",DAT_00195798);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  uVar4 = 0;
  if (local_4c != 0) {
    do {
      iVar1 = gnutls_pem_base64_encode2("CERTIFICATE",(ulong)uVar4 * 0x10 + lVar2,&local_48);
      if (iVar1 < 0) {
        uVar3 = gnutls_strerror(iVar1);
        __fprintf_chk(stderr,1,"error[%d]: %s\n",0x167,uVar3);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      uVar4 = uVar4 + 1;
      fwrite(local_48,(ulong)local_40,1,__s);
      (*gnutls_free)(local_48);
      local_48 = (void *)0x0;
    } while (uVar4 < local_4c);
  }
  fclose(__s);
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: try_save_ocsp_status @ 0xa3d0

void try_save_ocsp_status(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  FILE *__s;
  size_t sVar3;
  undefined8 uVar4;
  char *__filename;
  char *pcVar5;
  int iVar6;
  long in_FS_OFFSET;
  bool bVar7;
  int local_6c;
  void *local_68;
  uint local_60;
  void *local_58;
  uint local_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_6c = 0;
  gnutls_certificate_get_peers(param_1,&local_6c);
  if (local_6c == 0) {
    __fprintf_chk(stderr,1,"no certificates sent by server, so can\'t get OCSP status!\n");
  }
  else {
    __filename = DAT_001957a8;
    if (DAT_00195736 != '\0') {
      __filename = DAT_001957a0;
    }
    bVar7 = DAT_00195736 == '\0';
    iVar2 = local_6c;
    if (DAT_00195736 != '\0') {
      iVar2 = 1;
    }
    __s = fopen(__filename,"w");
    if (__s == (FILE *)0x0) {
      pcVar5 = "could not open %s for writing\n";
LAB_0010a5a8:
      __fprintf_chk(stderr,1,pcVar5,__filename);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar6 = 0;
LAB_0010a4a9:
    do {
      iVar1 = gnutls_ocsp_status_request_get2(param_1,iVar6,&local_68);
      if (iVar1 != -0x38) {
        if (iVar1 < 0) {
          uVar4 = gnutls_strerror(iVar1);
          __fprintf_chk(stderr,1,"error getting OCSP response %u: %s\n",iVar6,uVar4);
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        if (bVar7) {
          iVar1 = gnutls_pem_base64_encode2("OCSP RESPONSE",&local_68,&local_58);
          if (iVar1 < 0) {
            __filename = (char *)gnutls_strerror(iVar1);
            pcVar5 = "error allocating PEM OCSP response: %s\n";
            goto LAB_0010a5a8;
          }
          sVar3 = fwrite(local_58,(ulong)local_50,1,__s);
          if (sVar3 == 1) {
            iVar6 = iVar6 + 1;
            (*gnutls_free)(local_58);
            if (iVar2 == iVar6) break;
            goto LAB_0010a4a9;
          }
        }
        else {
          sVar3 = fwrite(local_68,(ulong)local_60,1,__s);
          if (sVar3 == 1) goto LAB_0010a4a0;
        }
        pcVar5 = "writing to %s failed\n";
        goto LAB_0010a5a8;
      }
      __fprintf_chk(stderr,1,"no OCSP response for certificate %u\n",iVar6);
LAB_0010a4a0:
      iVar6 = iVar6 + 1;
    } while (iVar2 != iVar6);
    iVar2 = fclose(__s);
    if (iVar2 != 0) {
      perror("failed to close OCSP save file");
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: cert_verify_ocsp @ 0xa620

int cert_verify_ocsp(undefined8 param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  uint uVar7;
  long in_FS_OFFSET;
  bool bVar8;
  int local_9c;
  uint local_8c;
  undefined8 local_88;
  undefined8 local_80;
  void *local_78 [2];
  undefined1 *local_68;
  undefined4 local_60;
  undefined1 local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_68 = local_58;
  local_8c = 0;
  local_60 = 0x17;
  lVar4 = gnutls_certificate_get_peers(param_1,&local_8c);
  if (local_8c == 0) {
    __fprintf_chk(stderr,1,"No certificates found!\n");
    iVar3 = 0;
  }
  else {
    local_9c = 0;
    uVar7 = 0;
    bVar2 = false;
    bVar1 = false;
    while (iVar3 = gnutls_x509_crt_init(&local_88), -1 < iVar3) {
      iVar3 = gnutls_x509_crt_import(local_88,(ulong)uVar7 * 0x10 + lVar4,0);
      if (iVar3 < 0) {
        uVar5 = gnutls_strerror(iVar3);
        pcVar6 = "Decoding error: %s\n";
LAB_0010a8f1:
        __fprintf_chk(stderr,1,pcVar6,uVar5);
        bVar8 = local_9c != 0;
LAB_0010a90e:
        if (bVar1) {
          gnutls_x509_crt_deinit(local_80);
        }
        goto LAB_0010a7b0;
      }
      if (bVar1) {
        gnutls_x509_crt_deinit(local_80);
      }
      bVar1 = false;
      iVar3 = gnutls_certificate_get_issuer(DAT_00123708,local_88,&local_80,0);
      if (iVar3 < 0) {
        if (local_8c - uVar7 < 2) {
          bVar8 = local_9c != 0;
          if (uVar7 == 0) {
            uVar5 = gnutls_strerror(iVar3);
            __fprintf_chk(stderr,1,"Cannot find issuer: %s\n",uVar5);
          }
          goto LAB_0010a7b0;
        }
        iVar3 = gnutls_x509_crt_init(&local_80);
        if (iVar3 < 0) {
          uVar5 = gnutls_strerror(iVar3);
          __fprintf_chk(stderr,1,"Memory error: %s\n",uVar5);
          bVar8 = local_9c != 0;
          goto LAB_0010a7b0;
        }
        iVar3 = gnutls_x509_crt_import(local_80,(ulong)(uVar7 + 1) * 0x10 + lVar4,0);
        if (iVar3 < 0) {
          uVar5 = gnutls_strerror(iVar3);
          __fprintf_chk(stderr,1,"Decoding error: %s\n",uVar5);
          gnutls_x509_crt_deinit(local_80);
          bVar8 = local_9c != 0;
          goto LAB_0010a7b0;
        }
        bVar1 = true;
      }
      iVar3 = gnutls_rnd(0,local_68,local_60);
      if (iVar3 < 0) {
        uVar5 = gnutls_strerror(iVar3);
        pcVar6 = "gnutls_rnd: %s";
        goto LAB_0010a8f1;
      }
      iVar3 = FUN_00113d10(0,local_88,local_80,local_78,&local_68);
      if (iVar3 != -0x38) {
        if (iVar3 < 0) {
          __fprintf_chk(stderr,1,"Cannot contact OCSP server\n");
          bVar8 = local_9c != 0;
        }
        else {
          iVar3 = FUN_00114280(local_88,local_80,local_78,&local_68,DAT_0012236c);
          free(local_78[0]);
          if (iVar3 == 1) {
            local_9c = local_9c + 1;
            if (local_8c <= uVar7 + 1) goto LAB_0010a812;
            goto LAB_0010a727;
          }
          if (iVar3 != 0) goto LAB_0010a71a;
          bVar8 = false;
        }
        goto LAB_0010a90e;
      }
LAB_0010a71a:
      if (local_8c <= uVar7 + 1) {
LAB_0010a812:
        if (bVar1) {
          gnutls_x509_crt_deinit(local_80);
          bVar8 = local_9c != 0;
        }
        else {
          bVar8 = local_9c != 0;
        }
        goto LAB_0010a7b0;
      }
LAB_0010a727:
      uVar7 = uVar7 + 1;
      bVar2 = true;
      gnutls_x509_crt_deinit(local_88);
    }
    uVar5 = gnutls_strerror(iVar3);
    __fprintf_chk(stderr,1,"Memory error: %s\n",uVar5);
    if (bVar1) {
      gnutls_x509_crt_deinit(local_80);
    }
    bVar8 = local_9c != 0;
    if (bVar2) {
LAB_0010a7b0:
      gnutls_x509_crt_deinit(local_88);
    }
    iVar3 = -1;
    if (bVar8) {
      iVar3 = local_9c;
    }
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



// Function: cert_verify_callback @ 0xaa30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 cert_verify_callback(undefined8 param_1)

{
  char cVar1;
  undefined8 uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined *puVar9;
  undefined4 uVar10;
  long in_FS_OFFSET;
  undefined1 local_44 [4];
  long local_40;
  
  cVar5 = DAT_001958a6;
  cVar4 = DAT_001958a4;
  cVar3 = DAT_001958a3;
  uVar8 = DAT_00195780;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  cVar1 = DAT_001958a2;
  if (DAT_001958a3 != '\0') {
    cVar1 = DAT_001958a3;
  }
  uVar2 = DAT_001223a0;
  if (DAT_0019572c != '\0') {
    FUN_00111180(DAT_00195780,0,0);
    uVar2 = uVar8;
  }
  if (DAT_00195735 != '\0') {
    FUN_0010a250(param_1);
  }
  if (_DAT_00195736 != 0) {
    FUN_0010a3d0(param_1);
  }
  FUN_0010fc00(param_1,DAT_0012236c,DAT_00122368);
  if (cVar5 == '\0') {
LAB_0010aac2:
    if ((cVar4 == '\0') ||
       (__fprintf_chk(stderr,1,"*** DANE error: GnuTLS is not compiled with DANE support.\n"),
       cVar1 != '\0' || DAT_001223c4 != 0)) {
      uVar10 = 0;
      if (cVar1 == '\0') goto LAB_0010aad4;
      lVar7 = gnutls_certificate_get_peers(param_1,local_44);
      if (lVar7 == 0) {
        __fprintf_chk(stderr,1,"Cannot obtain peer\'s certificate!\n");
      }
      else {
        puVar9 = &DAT_00116bb5;
        if (DAT_001223b8 == 0) {
          puVar9 = &DAT_00116bb9;
        }
        uVar8 = FUN_00111920(&DAT_00122380,puVar9);
        iVar6 = gnutls_verify_stored_pubkey(0,0,uVar2,uVar8,1,lVar7,0);
        if (iVar6 == -0x31) {
          __fprintf_chk(stderr,1,"Host %s (%s) has never been contacted before.\n",uVar2,uVar8);
          __fprintf_chk(stderr,1,"Its certificate is valid for %s.\n",uVar2);
          if (cVar3 == '\0') {
            iVar6 = FUN_00109ed0("Are you sure you want to trust it? (y/N): ");
joined_r0x0010accb:
            if (iVar6 != 0) {
LAB_0010acd1:
              iVar6 = gnutls_store_pubkey(0,0,uVar2,uVar8,1,lVar7);
              if (iVar6 < 0) {
                uVar8 = gnutls_strerror(iVar6);
                __fprintf_chk(stderr,1,"Could not store key: %s\n",uVar8);
              }
              goto LAB_0010ac6b;
            }
          }
        }
        else if (iVar6 == -0x3c) {
          __fprintf_chk(stderr,1,
                        "Warning: host %s is known and it is associated with a different key.\n",
                        uVar2,0x10ac2f);
          __fprintf_chk(stderr,1,
                        "It might be that the server has multiple keys, or an attacker replaced the key to eavesdrop this connection .\n"
                       );
          __fprintf_chk(stderr,1,"Its certificate is valid for %s.\n",uVar2);
          if (cVar3 == '\0') {
            iVar6 = FUN_00109ed0("Do you trust the received key? (y/N): ");
            goto joined_r0x0010accb;
          }
        }
        else {
          if (-1 < iVar6) {
            if (iVar6 != 0) goto LAB_0010acd1;
LAB_0010ac6b:
            uVar10 = 0;
            goto LAB_0010aad4;
          }
          uVar8 = gnutls_strerror(iVar6);
          __fprintf_chk(stderr,1,"gnutls_verify_stored_pubkey: %s\n",uVar8);
        }
      }
    }
  }
  else {
    iVar6 = FUN_0010dd70(param_1,uVar2,"1.3.6.1.5.5.7.3.1");
    if (iVar6 != 0) {
      if ((DAT_001958a7 != '\0') &&
         (iVar6 = gnutls_ocsp_status_request_is_checked(param_1,0), iVar6 == 0)) {
        iVar6 = FUN_0010a620(param_1);
        if (iVar6 == -1) {
          FUN_0010dc90(stdout,"*** Verifying (with OCSP) server certificate chain failed...\n");
          if (cVar1 == '\0' && DAT_001223c4 == 0) goto LAB_0010abe1;
        }
        else if (iVar6 == 0) {
          FUN_0010dc90(stdout,"*** OCSP: nothing to check.\n");
        }
        else {
          FUN_0010dc90(stdout,"*** OCSP: verified %d certificate(s).\n",iVar6);
        }
      }
      goto LAB_0010aac2;
    }
    FUN_0010dc90(stdout,"*** PKI verification of server certificate failed...\n");
    if (cVar1 != '\0' || DAT_001223c4 != 0) goto LAB_0010aac2;
  }
LAB_0010abe1:
  uVar10 = 0xffffffff;
LAB_0010aad4:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



// Function: print_priority_list @ 0xae60

void print_priority_list(void)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0;
  uVar5 = 0;
  uVar2 = gnutls_check_version(0);
  FUN_0010dc90(stdout,"Priority strings in GnuTLS %s:\n",uVar2);
  fputs("\t",stdout);
  while( true ) {
    lVar3 = gnutls_priority_string_list(iVar6,1);
    if (lVar3 == 0) break;
    iVar1 = FUN_0010dc90(stdout,&DAT_00116c1e,lVar3);
    uVar5 = uVar5 + iVar1;
    if (0x40 < uVar5) {
      uVar5 = 0;
      FUN_0010dc90(stdout,&DAT_00116c05);
    }
    iVar6 = iVar6 + 1;
  }
  uVar5 = 0;
  iVar6 = 0;
  FUN_0010dc90(stdout,"\n\nSpecial strings:\n",0);
  fputs("\t",stdout);
  while( true ) {
    pcVar4 = (char *)gnutls_priority_string_list(iVar6,2);
    if (pcVar4 == (char *)0x0) break;
    if (*pcVar4 != '\0') {
      iVar1 = FUN_0010dc90(stdout,&DAT_00116c1c,pcVar4);
      uVar5 = uVar5 + iVar1;
      if (0x40 < uVar5) {
        uVar5 = 0;
        FUN_0010dc90(stdout,&DAT_00116c05);
      }
    }
    iVar6 = iVar6 + 1;
  }
  FUN_0010dc90(stdout,"\n",0);
  return;
}



// Function: psk_callback @ 0xafb0

int psk_callback(undefined8 param_1,long *param_2,long *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  size_t sVar7;
  __ssize_t _Var8;
  char *pcVar9;
  undefined8 uVar10;
  long in_FS_OFFSET;
  bool bVar11;
  char *local_90;
  char *local_88;
  uint local_80;
  undefined1 local_78 [56];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar4 = gnutls_psk_client_get_hint();
  FUN_0010dc90(stdout,"- PSK client callback. ");
  if (lVar4 == 0) {
    FUN_0010dc90(stdout,"No PSK hint\n");
  }
  else {
    FUN_0010dc90(stdout,"PSK hint \'%s\'\n",lVar4);
  }
  if (DAT_00195744 == '\0') {
    local_90 = (char *)0x0;
    FUN_0010dc90(stdout,"Enter PSK identity: ");
    fflush(stdout);
    _Var8 = getline(&local_90,(size_t *)&local_88,stdin);
    pcVar6 = local_90;
    if (((int)_Var8 != -1) && (local_90 != (char *)0x0)) {
      sVar7 = strlen(local_90);
      pcVar1 = local_90;
      pcVar9 = pcVar6 + (sVar7 - 1);
      if (*pcVar9 == '\n') {
        *pcVar9 = '\0';
        sVar7 = strlen(local_90);
        pcVar9 = pcVar1 + (sVar7 - 1);
        pcVar6 = pcVar1;
      }
      if (*pcVar9 == '\r') {
        *pcVar9 = '\0';
        pcVar6 = local_90;
      }
      lVar5 = (*gnutls_strdup)(pcVar6);
      *param_2 = lVar5;
      free(local_90);
      lVar5 = *param_2;
      goto LAB_0010b033;
    }
    pcVar6 = "No username given, aborting...\n";
LAB_0010b28a:
    iVar2 = -0x20;
    __fprintf_chk(stderr,1,pcVar6);
  }
  else {
    lVar5 = (*gnutls_strdup)(DAT_00195810);
    *param_2 = lVar5;
LAB_0010b033:
    if (lVar5 != 0) {
      pcVar6 = getpass("Enter key: ");
      if (pcVar6 == (char *)0x0) {
        pcVar6 = "No key given, aborting...\n";
        goto LAB_0010b28a;
      }
      local_88 = pcVar6;
      sVar7 = strlen(pcVar6);
      local_80 = (uint)sVar7;
      local_90 = (char *)(ulong)((local_80 >> 1) + 1);
      lVar5 = (*gnutls_malloc)();
      if (lVar5 != 0) {
        iVar2 = gnutls_hex_decode(&local_88,lVar5,&local_90);
        if (iVar2 < 0) {
          uVar10 = gnutls_strerror(iVar2);
          __fprintf_chk(stderr,1,"Error deriving password: %s\n",uVar10);
          (*gnutls_free)(lVar5);
          (*gnutls_free)(*param_2);
          *param_2 = 0;
        }
        else {
          iVar2 = 0;
          bVar11 = DAT_00195720 != '\0';
          *param_3 = lVar5;
          *(int *)(param_3 + 1) = (int)local_90;
          if (bVar11) {
            local_90 = (char *)0x29;
            iVar3 = gnutls_hex_encode(param_3,local_78,&local_90);
            if (iVar3 < 0) {
              uVar10 = gnutls_strerror(iVar3);
              __fprintf_chk(stderr,1,"Error in hex encoding: %s\n",uVar10);
                    /* WARNING: Subroutine does not return */
              exit(1);
            }
            __fprintf_chk(stderr,1,"PSK username: %s\n",*param_2);
            __fprintf_chk(stderr,1,"PSK hint: %s\n",lVar4);
            __fprintf_chk(stderr,1,"PSK key: %s\n",local_78);
          }
        }
        goto LAB_0010b0ba;
      }
    }
    iVar2 = -0x19;
  }
LAB_0010b0ba:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: load_priv_key @ 0xb2f0

void load_priv_key(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  long in_FS_OFFSET;
  undefined8 local_38;
  undefined4 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_38 = 0;
  local_30 = 0;
  iVar1 = gnutls_privkey_init();
  if (iVar1 < 0) {
    uVar2 = gnutls_strerror(iVar1);
    pcVar3 = "*** Error initializing key: %s\n";
LAB_0010b3c1:
    __fprintf_chk(stderr,1,pcVar3,uVar2);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  gnutls_privkey_set_pin_function(*param_1,FUN_0010f410,0);
  iVar1 = gnutls_url_is_supported(param_2);
  if (iVar1 == 0) {
    iVar1 = gnutls_load_file(param_2,&local_38);
    if (iVar1 < 0) {
      __fprintf_chk(stderr,1,"*** Error loading key file.\n");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar1 = gnutls_privkey_import_x509_raw(*param_1,&local_38,DAT_00123740,0,0);
    if (iVar1 < 0) {
      uVar2 = gnutls_strerror(iVar1);
      pcVar3 = "*** Error importing key: %s\n";
      goto LAB_0010b3c1;
    }
    (*gnutls_free)(local_38);
  }
  else {
    iVar1 = gnutls_privkey_import_url(*param_1,param_2,0);
    if (iVar1 < 0) {
      uVar2 = gnutls_strerror(iVar1);
      pcVar3 = "*** Error loading url: %s\n";
      goto LAB_0010b3c1;
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: load_x509_keys @ 0xb430

void load_x509_keys(void)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined *puVar7;
  long in_FS_OFFSET;
  undefined4 local_7c;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_68 [7];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_70 = 0;
  local_78 = 0;
  if ((DAT_00122348 != 0) && (DAT_00122350 != 0)) {
    iVar2 = gnutls_load_file(DAT_00122348,&local_78);
    if (iVar2 < 0) {
      __fprintf_chk(stderr,1,"*** Error loading cert file.\n");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    local_7c = 6;
    uVar3 = gnutls_x509_crt_list_import(local_68,&local_7c,&local_78,DAT_00123740,1);
    uVar4 = stderr;
    if ((int)uVar3 < 0) {
      if (uVar3 == 0xffffffcd) {
        __fprintf_chk(stderr,1,"*** Error loading cert file: Too many certs %d\n",local_7c);
      }
      else {
        uVar5 = gnutls_strerror(uVar3);
        __fprintf_chk(uVar4,1,"*** Error loading cert file: %s\n",uVar5);
      }
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    puVar7 = &DAT_00123640;
    lVar6 = 0;
    DAT_00123700 = uVar3;
    if (uVar3 != 0) {
      do {
        iVar2 = gnutls_pcert_import_x509(puVar7,local_68[lVar6],0);
        if (iVar2 < 0) {
          uVar4 = gnutls_strerror(iVar2);
          __fprintf_chk(stderr,1,"*** Error importing crt to pcert: %s\n",uVar4);
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        puVar1 = local_68 + lVar6;
        puVar7 = puVar7 + 0x20;
        lVar6 = lVar6 + 1;
        gnutls_x509_crt_deinit(*puVar1);
      } while ((uint)lVar6 < DAT_00123700);
    }
    (*gnutls_free)(local_78);
    local_78 = 0;
    FUN_0010b2f0(&DAT_00123620,DAT_00122350);
    FUN_0010dc90(stdout,"Processed %d client X.509 certificates...\n",DAT_00123700);
  }
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: load_rawpk_keys @ 0xb610

void load_rawpk_keys(void)

{
  int iVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  undefined8 local_28;
  undefined4 local_20;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = 0;
  local_20 = 0;
  if ((DAT_00122328 != 0) && (DAT_00122330 != 0)) {
    iVar1 = gnutls_load_file(DAT_00122328,&local_28);
    if (iVar1 < 0) {
      __fprintf_chk(stderr,1,"*** Error loading cert file.\n");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar1 = gnutls_pcert_import_rawpk_raw(&DAT_00123600,&local_28,DAT_00123740,0,0);
    if (iVar1 < 0) {
      uVar2 = gnutls_strerror(iVar1);
      __fprintf_chk(stderr,1,"*** Error importing rawpk to pcert: %s\n",uVar2);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    (*gnutls_free)(local_28);
    local_28 = 0;
    FUN_0010b2f0(&DAT_001235e8,DAT_00122330);
    FUN_0010dc90(stdout,"Processed %d client raw public key pair...\n",1);
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: init_global_tls_stuff @ 0xb730

void init_global_tls_stuff(void)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  long in_FS_OFFSET;
  undefined8 local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = gnutls_certificate_allocate_credentials(&DAT_00123708);
  if (iVar1 < 0) {
    pcVar3 = "Certificate allocation memory error\n";
LAB_0010b9fa:
    __fprintf_chk(stderr,1,pcVar3);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  gnutls_certificate_set_pin_function(DAT_00123708,FUN_0010f410,0);
  gnutls_certificate_set_verify_flags(DAT_00123708,DAT_001223a8);
  gnutls_certificate_set_flags(DAT_00123708,8);
  iVar1 = gnutls_x509_trust_list_init(&local_18,0);
  if (iVar1 < 0) {
    pcVar3 = "Trust list allocation memory error\n";
    goto LAB_0010b9fa;
  }
  gnutls_certificate_set_trust_list(DAT_00123708,local_18,0);
  if (DAT_00122340 == 0) {
    iVar1 = 0;
    if (DAT_001223c4 == 0) {
      iVar1 = gnutls_x509_trust_list_add_system_trust(local_18,2,0);
      if (iVar1 != -0x4e2) goto LAB_0010b7e0;
      __fprintf_chk(stderr,1,"Warning: this system doesn\'t support a default trust store\n");
      iVar1 = 0;
    }
  }
  else {
    iVar1 = gnutls_x509_trust_list_add_trust_file(local_18,DAT_00122340,0,DAT_00123740,2,0);
LAB_0010b7e0:
    if (iVar1 < 0) {
      uVar2 = gnutls_strerror(iVar1);
      pcVar3 = "Error setting the x509 trust file: %s\n";
      goto LAB_0010ba31;
    }
  }
  FUN_0010dc90(stdout,"Processed %d CA certificate(s).\n",iVar1);
  if (DAT_001958e2 != '\0') {
    gnutls_x509_trust_list_set_getissuer_function(local_18,FUN_0010c970);
  }
  if (DAT_00122338 != 0) {
    iVar1 = gnutls_certificate_set_x509_crl_file(DAT_00123708,DAT_00122338,DAT_00123740);
    if (iVar1 < 0) {
      uVar2 = gnutls_strerror(iVar1);
      pcVar3 = "Error setting the x509 CRL file: %s\n";
LAB_0010ba31:
      __fprintf_chk(stderr,1,pcVar3,uVar2);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    FUN_0010dc90(stdout,"Processed %d CRL(s).\n");
  }
  FUN_0010b430();
  FUN_0010b610();
  if ((DAT_00122358 != 0) && (DAT_00122360 != 0)) {
    iVar1 = gnutls_srp_allocate_client_credentials(&DAT_00123720);
    if (iVar1 < 0) {
      __fprintf_chk(stderr,1,"SRP authentication error\n");
    }
    gnutls_srp_set_client_credentials_function(DAT_00123720,FUN_00109e80);
  }
  iVar1 = gnutls_psk_allocate_client_credentials(&DAT_00123718);
  if (iVar1 < 0) {
    __fprintf_chk(stderr,1,"PSK authentication error\n");
  }
  if ((DAT_00122320 == 0) || (DAT_00122310 == 0)) {
    gnutls_psk_set_client_credentials_function(DAT_00123718,FUN_0010afb0);
  }
  else {
    iVar1 = gnutls_psk_set_client_credentials(DAT_00123718,DAT_00122320,&DAT_00122310,1);
    if (iVar1 < 0) {
      uVar2 = gnutls_strerror(iVar1);
      __fprintf_chk(stderr,1,"Error setting the PSK credentials: %s\n",uVar2);
    }
  }
  iVar1 = gnutls_anon_allocate_client_credentials(&DAT_00123710);
  if (iVar1 < 0) {
    __fprintf_chk(stderr,1,"Anonymous authentication error\n");
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: try_resume @ 0xba70

undefined8 try_resume(long param_1)

{
  int iVar1;
  ulong uVar2;
  FILE *__stream;
  uint uVar3;
  long in_FS_OFFSET;
  undefined4 local_60 [2];
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_50 = 0;
  local_58 = 0;
  local_48 = 0;
  local_40 = 0;
  iVar1 = gnutls_session_is_resumed(*(undefined8 *)(param_1 + 8));
  if (iVar1 == 0) {
    while( true ) {
      iVar1 = gnutls_session_get_data2(*(undefined8 *)(param_1 + 8),&local_58);
      if (iVar1 < 0) {
        local_58 = 0;
      }
      iVar1 = gnutls_protocol_get_version(*(undefined8 *)(param_1 + 8));
      if (iVar1 != 5) break;
      uVar2 = gnutls_session_get_flags(*(undefined8 *)(param_1 + 8));
      if (((uVar2 & 0x80) != 0) || (DAT_001223ac == 0)) break;
    }
  }
  else {
    local_58 = *(undefined8 *)(param_1 + 0xe8);
    *(undefined8 *)(param_1 + 0xe8) = 0;
    local_50 = *(undefined4 *)(param_1 + 0xf0);
  }
  uVar3 = 0x44;
  FUN_0010dc90(stdout,"- Disconnecting\n");
  FUN_00111040(param_1,1);
  FUN_00111180(DAT_001223a0,&DAT_00122380,0x20);
  FUN_0010dc90(stdout,"\n\n- Connecting again- trying to resume previous session\n");
  if (DAT_0019572e == '\0') {
    uVar3 = (-(uint)(DAT_00122370 == 0) & 0xfffffffe) + 0x42;
  }
  if (DAT_001223b8 != 0) {
    uVar3 = uVar3 | 1;
  }
  if (DAT_00195729 != '\0') {
    __stream = fopen(DAT_00195770,"r");
    if (__stream == (FILE *)0x0) {
      __fprintf_chk(stderr,1,"could not open %s\n",DAT_00195770);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    local_48 = FUN_00115860(__stream,0,local_60);
    local_40 = local_60[0];
    fclose(__stream);
  }
  FUN_00111250(param_1,DAT_001223a0,&DAT_00122380,DAT_00195788,uVar3,"Connecting to",&local_58,
               &local_48,0,0);
  FUN_0010dc90(stdout,"- Resume Handshake was completed\n");
  iVar1 = gnutls_session_is_resumed(*(undefined8 *)(param_1 + 8));
  if (iVar1 != 0) {
    FUN_0010dc90(stdout,"*** This is a resumed session\n");
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: print_other_info @ 0xbcd0

void print_other_info(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  long in_FS_OFFSET;
  uint local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_48 [3];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = gnutls_certificate_get_peers(param_1,&local_64);
  if (((DAT_001958a1 == '\x01') && (lVar2 != 0)) && (local_64 != 0)) {
    uVar4 = 0;
    do {
      while( true ) {
        iVar1 = gnutls_ocsp_status_request_get2(param_1,uVar4,&local_58);
        if (-1 < iVar1) break;
        local_58 = 0;
        uVar4 = uVar4 + 1;
        local_50 = 0;
        if (local_64 <= uVar4) goto LAB_0010bde0;
      }
      iVar1 = gnutls_ocsp_resp_init(&local_60);
      if (iVar1 < 0) {
        uVar3 = gnutls_strerror(iVar1);
        __fprintf_chk(stderr,1,"ocsp_resp_init: %s\n",uVar3);
        break;
      }
      iVar1 = gnutls_ocsp_resp_import(local_60,&local_58);
      if (iVar1 < 0) {
        uVar3 = gnutls_strerror(iVar1);
        __fprintf_chk(stderr,1,"importing response: %s\n",uVar3);
        break;
      }
      iVar1 = gnutls_ocsp_resp_print(local_60,DAT_00122368 == 0,local_48);
      gnutls_ocsp_resp_deinit(local_60);
      if (-1 < iVar1) {
        FUN_0010dc90(stdout,"%s",local_48[0]);
        (*gnutls_free)(local_48[0]);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < local_64);
  }
LAB_0010bde0:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: check_net_or_keyboard_input @ 0xbe50

undefined8 check_net_or_keyboard_input(int *param_1,int param_2)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  __fd_mask *p_Var4;
  long lVar5;
  undefined8 uVar6;
  long in_FS_OFFSET;
  timeval local_d8;
  ulong local_c8 [16];
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  p_Var4 = (__fd_mask *)local_c8;
  do {
    do {
      *p_Var4 = 0;
      p_Var4 = p_Var4 + 1;
    } while (&local_48 != p_Var4);
    lVar5 = __fdelt_chk((long)*param_1);
    iVar2 = *param_1;
    local_c8[lVar5] = local_c8[lVar5] | 1L << ((byte)iVar2 & 0x3f);
    if (param_2 == 0) {
      iVar2 = fileno(stdin);
      iVar3 = fileno(stdin);
      lVar5 = __fdelt_chk((long)iVar3);
      local_c8[lVar5] = local_c8[lVar5] | 1L << ((byte)iVar2 & 0x3f);
      iVar3 = fileno(stdin);
      iVar2 = *param_1;
      if (iVar2 < iVar3) {
        iVar2 = fileno(stdin);
      }
    }
    local_d8.tv_sec = 2;
    local_d8.tv_usec = 0;
    if ((param_1[4] == 1) &&
       (lVar5 = gnutls_record_check_pending(*(undefined8 *)(param_1 + 2)), lVar5 != 0)) {
LAB_0010bf7a:
      uVar6 = 2;
      goto LAB_0010bf06;
    }
    iVar2 = select(iVar2 + 1,(fd_set *)local_c8,(fd_set *)0x0,(fd_set *)0x0,&local_d8);
    if (iVar2 < 0) goto LAB_0010bf04;
    lVar5 = __fdelt_chk((long)*param_1);
    if ((1L << ((byte)*param_1 & 0x3f) & local_c8[lVar5]) != 0) goto LAB_0010bf7a;
    if (param_2 != 0) {
      if (iVar2 == 0) {
        uVar6 = 3;
        goto LAB_0010bf06;
      }
      goto LAB_0010bf04;
    }
    iVar3 = fileno(stdin);
    lVar5 = __fdelt_chk((long)iVar3);
    uVar1 = local_c8[lVar5];
    iVar3 = fileno(stdin);
    if ((uVar1 & 1L << ((byte)iVar3 & 0x3f)) != 0) {
      uVar6 = 1;
      goto LAB_0010bf06;
    }
    p_Var4 = (__fd_mask *)local_c8;
    if (iVar2 != 0) {
LAB_0010bf04:
      uVar6 = 0;
LAB_0010bf06:
      if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return uVar6;
    }
  } while( true );
}



// Function: parse_for_inline_commands_in_buffer @ 0xc050

undefined8 parse_for_inline_commands_in_buffer(char *param_1,size_t param_2,undefined8 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  char *pcVar4;
  size_t sVar5;
  int iVar6;
  size_t sVar7;
  undefined8 uVar8;
  size_t sVar9;
  char *pcVar10;
  size_t sVar11;
  char *__s;
  char *__s2;
  uint uVar12;
  size_t sVar13;
  long in_FS_OFFSET;
  undefined8 local_60;
  char local_58 [24];
  long local_40;
  
  lVar3 = param_3[4];
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined4 *)(param_3 + 3) = 0;
  *(undefined4 *)(param_3 + 2) = 0;
  if (lVar3 == 0) {
    param_3[1] = param_1 + param_2;
    if (param_1 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("local_buffer_ptr != NULL","cli.c",0x456,"parse_for_inline_commands_in_buffer");
    }
    sVar13 = 0;
    sVar11 = param_2;
    __s2 = param_1;
  }
  else {
    sVar11 = param_2;
    if (0x14 < lVar3 + param_2) {
      sVar11 = 0x14 - lVar3;
    }
    memcpy((void *)((long)param_3 + lVar3 + 0x28),param_1,sVar11);
    sVar13 = param_3[4];
    param_3[1] = param_1 + sVar11;
    param_3[4] = sVar11 + sVar13;
    sVar11 = sVar11 + sVar13;
    __s2 = (char *)(param_3 + 5);
  }
  pcVar4 = DAT_00123728;
  *param_3 = __s2;
  cVar1 = *pcVar4;
  if ((*__s2 == cVar1) && (*(int *)((long)param_3 + 0x14) != 0)) {
    uVar12 = 0;
    pcVar10 = s__resume__00120044;
    local_60 = param_2;
    do {
      __s = pcVar10;
      if (cVar1 != '^') {
        __strcpy_chk(local_58,pcVar10,0x14);
        sVar7 = strlen(pcVar10);
        local_58[sVar7] = '\0';
        local_58[0] = cVar1;
        sVar7 = strlen(pcVar10);
        local_58[sVar7 - 2] = cVar1;
        __s = local_58;
      }
      sVar9 = strlen(__s);
      sVar7 = sVar11;
      if ((long)sVar9 <= (long)sVar11) {
        sVar7 = sVar9;
      }
      iVar6 = strncmp(__s,__s2,sVar7);
      sVar5 = local_60;
      if (iVar6 == 0) {
        if (sVar9 == sVar7) {
          param_3[1] = param_1 + (sVar9 - sVar13);
          uVar2 = *(undefined4 *)(&DAT_00120040 + (ulong)uVar12 * 0x18);
          param_3[4] = 0;
          *(undefined4 *)(param_3 + 2) = uVar2;
          uVar8 = 1;
        }
        else {
          memcpy((void *)((long)param_3 + param_3[4] + 0x28),param_1,local_60);
          uVar8 = 1;
          param_3[4] = param_3[4] + sVar5;
        }
        goto LAB_0010c18a;
      }
      uVar12 = uVar12 + 1;
      pcVar10 = pcVar10 + 0x18;
    } while (uVar12 != 4);
  }
  sVar7 = sVar13;
  if ((long)sVar13 < (long)sVar11) {
    do {
      pcVar10 = __s2 + sVar7;
      if (((sVar7 != 0) && (*pcVar4 == *pcVar10)) && (*(int *)((long)param_3 + 0x14) != 0)) {
        *(int *)(param_3 + 3) = (int)sVar7;
        uVar8 = 1;
        *(undefined4 *)((long)param_3 + 0x14) = 1;
        param_3[1] = param_1 + (sVar7 - sVar13);
        goto LAB_0010c18a;
      }
      sVar7 = sVar7 + 1;
      *(uint *)((long)param_3 + 0x14) = (uint)(*pcVar10 == '\n');
    } while (sVar7 != sVar11);
  }
  param_3[4] = 0;
  uVar8 = 0;
LAB_0010c18a:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



// Function: try_rekey @ 0xc330

int try_rekey(long param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  do {
    do {
      iVar1 = gnutls_session_key_update(*(undefined8 *)(param_1 + 8),param_2);
    } while (iVar1 == -0x1c);
  } while (iVar1 == -0x34);
  if (-1 < iVar1) {
    FUN_0010dc90(stdout,"- Rekey was completed\n");
    return 0;
  }
  uVar2 = gnutls_strerror(iVar1);
  __fprintf_chk(stderr,1,"*** Rekey has failed: %s\n",uVar2);
  return iVar1;
}



// Function: host_from_url @ 0x13ae0

char * host_from_url(char *param_1,int *param_2,undefined8 *param_3)

{
  int iVar1;
  char *pcVar2;
  
  *param_2 = 0;
  *param_3 = &DAT_00116c07;
  pcVar2 = strstr(param_1,"http://");
  if (pcVar2 != (char *)0x0) {
    snprintf(&DAT_00194500,0x200,"%s",pcVar2 + 7);
    pcVar2 = strchr(&DAT_00194500,0x2f);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
      *param_3 = pcVar2 + 1;
    }
    param_1 = &DAT_00194500;
    pcVar2 = strchr(&DAT_00194500,0x3a);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
      iVar1 = atoi(pcVar2 + 1);
      *param_2 = iVar1;
    }
  }
  return param_1;
}



// Function: cmd_parser @ 0xc460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cmd_parser(int param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  size_t sVar4;
  long *plVar5;
  char *pcVar6;
  long lVar7;
  
  lVar7 = 0;
  iVar1 = FUN_001148c0();
  pcVar6 = DAT_00195838;
  if (iVar1 < param_1) {
    lVar7 = *(long *)(param_2 + (long)iVar1 * 8);
  }
  if (DAT_0019575c != '\0') {
    iVar1 = gnutls_fips140_mode_enabled();
    if (iVar1 != 0) {
      __fprintf_chk(stderr,1,"library is in FIPS140-2 mode\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    pcVar6 = "library is NOT in FIPS140-2 mode\n";
    goto LAB_0010c7dd;
  }
  if (DAT_0019575d != '\0') {
    for (plVar5 = (long *)gnutls_get_library_config(); *plVar5 != 0; plVar5 = plVar5 + 2) {
      FUN_0010dc90(stdout,"%s: %s\n",*plVar5,plVar5[1]);
    }
    uVar3 = gnutls_get_system_config_file();
    FUN_0010dc90(stdout,"system-config: %s\n",uVar3);
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  if (DAT_0019574a != '\0') {
    FUN_00112480();
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  if (DAT_0019574c != '\0') {
    FUN_00113860(DAT_00195868,1);
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  if (DAT_0019574b != '\0') {
    FUN_00113860(DAT_00195868,0);
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  if (DAT_0019573b != '\0') {
    DAT_00123730 = DAT_001957c8;
  }
  DAT_0012236c = (uint)DAT_00195721;
  DAT_00122368 = 1;
  if (DAT_00195721 == 0) {
    DAT_00122368 = (uint)DAT_00195734;
  }
  if (DAT_0019574d != '\0') {
    FUN_0010e5e0();
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  if (DAT_0019574e != '\0') {
    FUN_0010ae60();
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  _DAT_00123738 = (uint)DAT_00195755;
  DAT_0012373c = (uint)DAT_00195756;
  if (DAT_00195756 != 0) {
    DAT_00120020 = DAT_00120020 | 0x10;
  }
  if (DAT_00195757 != '\0') {
    DAT_00120020 = DAT_00120020 | 0x800;
  }
  if (DAT_00195758 != '\0') {
    DAT_00120020 = DAT_00120020 | 0x4000;
  }
  DAT_001223b0 = (uint)DAT_00195759;
  if (DAT_0019575a == '\0') {
    DAT_00123728 = "^";
  }
  else {
    sVar4 = strlen(DAT_00195838);
    if ((1 < sVar4) || (DAT_00123728 = pcVar6, *pcVar6 < '\0')) {
      pcVar6 = "inline-commands-prefix value is a single US-ASCII character (octets 0 - 127)\n";
      goto LAB_0010c7dd;
    }
  }
  DAT_001223c8 = (uint)DAT_0019572d;
  DAT_001223c4 = (uint)DAT_00195747;
  DAT_001223cc = (uint)DAT_00195728;
  DAT_001223bc = (uint)DAT_0019572a;
  DAT_001223c0 = (uint)DAT_00195749;
  DAT_001223ac = (uint)DAT_00195761;
  if ((DAT_00195747 != 0) || (DAT_00195748 != '\0')) {
    DAT_001223a8 = DAT_001223a8 | 0x30;
  }
  DAT_001223b8 = (uint)DAT_0019572f;
  DAT_001223b4 = DAT_0019586c;
  uVar3 = DAT_00195820;
  if (DAT_00195746 == '\0') {
    if (DAT_0019572e != '\0') {
      uVar3 = FUN_00110ff0(DAT_00195788);
      goto LAB_0010c62c;
    }
    _DAT_00122380 = 0x333434;
  }
  else {
LAB_0010c62c:
    snprintf(&DAT_00122380,0x20,"%s",uVar3);
  }
  DAT_00122378 = DAT_00195874;
  DAT_00123740 = DAT_00195733 ^ 1;
  if (DAT_00195742 != '\0') {
    DAT_00122358 = DAT_00195800;
  }
  if (DAT_00195743 != '\0') {
    DAT_00122360 = DAT_00195808;
  }
  if (DAT_0019573c != '\0') {
    DAT_00122340 = DAT_001957d0;
  }
  if (DAT_0019573d != '\0') {
    DAT_00122338 = DAT_001957d8;
  }
  if (DAT_0019573e != '\0') {
    DAT_00122350 = DAT_001957e0;
  }
  if (DAT_0019573f != '\0') {
    DAT_00122348 = DAT_001957e8;
  }
  if (DAT_00195740 != '\0') {
    DAT_00122330 = DAT_001957f0;
  }
  if (DAT_00195741 != '\0') {
    DAT_00122328 = DAT_001957f8;
  }
  if (DAT_00195744 != '\0') {
    DAT_00122320 = DAT_00195810;
  }
  uVar2 = 0;
  if (DAT_00195745 != '\0') {
    DAT_00122310 = DAT_00195818;
    sVar4 = strlen(DAT_00195818);
    uVar2 = (undefined4)sVar4;
  }
  _DAT_00122318 = uVar2;
  DAT_00122374 = (uint)DAT_00195731;
  DAT_00122370 = (uint)DAT_00195732;
  if ((lVar7 != 0) || (pcVar6 = "No hostname specified\n", lVar7 = DAT_001223a0, DAT_001223a0 != 0))
  {
    DAT_001223a0 = lVar7;
    return;
  }
LAB_0010c7dd:
  __fprintf_chk(stderr,1,pcVar6);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: getissuer_callback @ 0xc970

undefined4 getissuer_callback(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auVar1 [16];
  int iVar2;
  int iVar3;
  void *__dest;
  undefined8 uVar4;
  size_t sVar5;
  void *pvVar6;
  undefined8 uVar7;
  ulong __n;
  undefined4 uVar8;
  long in_FS_OFFSET;
  int local_5ac;
  undefined *local_5a8;
  undefined1 local_5a0 [8];
  undefined1 local_598 [16];
  long local_588;
  int local_580;
  void *local_578;
  uint local_570;
  undefined1 local_568 [272];
  undefined2 local_458;
  undefined1 local_456;
  char local_448 [1032];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_570 = 0;
  local_578 = (void *)0x0;
  local_5a8 = &DAT_00116c07;
  FUN_0010dc70();
  iVar3 = 0;
  do {
    iVar2 = gnutls_x509_crt_get_authority_info_access(param_2,iVar3,0x277a,&local_578,0);
    iVar3 = iVar3 + 1;
  } while (iVar2 == -0x69);
  if (iVar2 < 0) {
    uVar8 = 0;
    uVar4 = gnutls_strerror(iVar2);
    __fprintf_chk(stderr,1,"*** Cannot find caIssuer URI in certificate: %s\n",uVar4);
  }
  else {
    __dest = malloc((ulong)(local_570 + 1));
    pvVar6 = local_578;
    if (__dest == (void *)0x0) {
      uVar8 = 0xffffffff;
    }
    else {
      __n = (ulong)local_570;
      memcpy(__dest,local_578,__n);
      *(undefined1 *)((long)__dest + __n) = 0;
      (*gnutls_free)(pvVar6);
      local_578 = (void *)0x0;
      uVar4 = FUN_0010c3b0(__dest,&local_5ac,&local_5a8);
      if (local_5ac == 0) {
        local_456 = 0;
        local_458 = 0x3038;
      }
      else {
        __snprintf_chk(&local_458,0x10,1,0x10,&DAT_00116ea1);
      }
      __fprintf_chk(stderr,1,"Connecting to caIssuer server: %s...\n",uVar4);
      local_598 = (undefined1  [16])0x0;
      __snprintf_chk(local_448,0x400,1,0x400,
                     "GET /%s HTTP/1.0\r\nHost: %s\r\nAccept: */*\r\nConnection: close\r\n\r\n",
                     local_5a8,uVar4);
      sVar5 = strlen(local_448);
      FUN_00111250(local_568,uVar4,&local_458,0,0x28,"Connecting to",0,0,0,0);
      FUN_00110f90(local_568,local_448,sVar5 & 0xffffffff);
      while( true ) {
        iVar3 = FUN_00110d90(local_568,&DAT_001225e0,0x1001);
        auVar1 = local_598;
        if (iVar3 < 1) break;
        FUN_0010c900((long)iVar3,local_598);
      }
      uVar4 = local_598._0_8_;
      if ((iVar3 == 0) && (uVar8 = local_598._8_4_, local_598._8_4_ != 0)) {
        FUN_00111040(local_568,0);
        pvVar6 = memmem((void *)uVar4,(ulong)(uint)uVar8,&DAT_00116ea9,4);
        if (pvVar6 == (void *)0x0) {
          uVar8 = 0xffffffff;
          __fprintf_chk(stderr,1,"Cannot interpret HTTP response\n");
        }
        else {
          local_588 = (long)pvVar6 + 4;
          local_580 = uVar8 - ((int)local_588 - auVar1._0_4_);
          iVar3 = gnutls_x509_crt_init(local_5a0);
          if (iVar3 < 0) {
            uVar8 = 0xffffffff;
            __fprintf_chk(stderr,1,"Memory error\n");
          }
          else {
            iVar3 = gnutls_x509_crt_list_import2(param_3,param_4,&local_588,0,0);
            uVar8 = 0;
            if (iVar3 < 0) {
              uVar8 = 0xffffffff;
              uVar7 = gnutls_strerror(iVar3);
              __fprintf_chk(stderr,1,"Decoding error: %s\n",uVar7);
            }
          }
        }
      }
      else {
        uVar8 = 0xffffffff;
        perror("recv");
        FUN_00111040(local_568,0);
      }
      (*gnutls_free)(local_578);
      local_578 = (void *)0x0;
      free((void *)uVar4);
      free(__dest);
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: init_tls_session @ 0xcd30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 init_tls_session(char *param_1)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  size_t sVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  undefined8 *puVar13;
  long in_FS_OFFSET;
  undefined1 local_4028 [16384];
  
  puVar4 = &stack0xffffffffffffffd8;
  do {
    puVar12 = puVar4;
    *(undefined8 *)(puVar12 + -0x1000) = *(undefined8 *)(puVar12 + -0x1000);
    puVar4 = puVar12 + -0x1000;
  } while (puVar12 + -0x1000 != local_4028);
  *(undefined8 *)(puVar12 + 0x2ff8) = *(undefined8 *)(in_FS_OFFSET + 0x28);
  if (DAT_001223b8 == 0) {
    *(undefined8 *)(puVar12 + -0x1028) = 0x10d03a;
    gnutls_init(puVar12 + -0x1018,DAT_00120020);
  }
  else {
    *(undefined8 *)(puVar12 + -0x1028) = 0x10cd90;
    gnutls_init(puVar12 + -0x1018,DAT_00120020 | 4);
    if (DAT_001223b4 != 0) {
      *(undefined8 *)(puVar12 + -0x1028) = 0x10d0a2;
      gnutls_dtls_set_mtu(*(undefined8 *)(puVar12 + -0x1018));
    }
  }
  if (DAT_00123730 == 0) {
    *(undefined8 *)(puVar12 + -0x1028) = 0x10d05d;
    iVar5 = gnutls_set_default_priority(*(undefined8 *)(puVar12 + -0x1018));
    if (iVar5 < 0) {
      *(undefined8 *)(puVar12 + -0x1028) = 0x10d06c;
      uVar9 = gnutls_strerror(iVar5);
      *(undefined8 *)(puVar12 + -0x1028) = 0x10d089;
      __fprintf_chk(stderr,1,"Error in setting priorities: %s\n",uVar9);
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar12 + -0x1028) = &UNK_0010d093;
      exit(1);
    }
  }
  else {
    *(undefined8 *)(puVar12 + -0x1028) = 0x10cdbb;
    iVar5 = gnutls_priority_set_direct
                      (*(undefined8 *)(puVar12 + -0x1018),DAT_00123730,puVar12 + -0x1020);
    uVar9 = stderr;
    if (iVar5 < 0) {
      if (iVar5 == -0x32) {
        *(undefined8 *)(puVar12 + -0x1028) = 0x10d1f1;
        __fprintf_chk(stderr,1,"Syntax error at: %s\n",*(undefined8 *)(puVar12 + -0x1020));
      }
      else {
        *(undefined8 *)(puVar12 + -0x1028) = 0x10d1b9;
        uVar8 = gnutls_strerror(iVar5);
        *(undefined8 *)(puVar12 + -0x1028) = 0x10d1d2;
        __fprintf_chk(uVar9,1,"Error in priorities: %s\n",uVar8);
      }
      goto LAB_0010cff3;
    }
  }
  pcVar2 = DAT_00195778;
  if (DAT_0012373c == 0 && _DAT_00123738 == 0) {
    if (DAT_0019572b == '\0') {
      if (param_1 != (char *)0x0) {
        *(undefined8 *)(puVar12 + -0x1028) = 0x10d01e;
        iVar5 = FUN_0010a1c0(param_1);
        if (iVar5 == 0) goto LAB_0010d0f3;
      }
    }
    else {
      *(undefined8 *)(puVar12 + -0x1028) = 0x10d0f3;
      FUN_00111180(DAT_00195778,0,0);
      param_1 = pcVar2;
LAB_0010d0f3:
      *(undefined8 *)(puVar12 + -0x1028) = 0x10d0fb;
      sVar6 = strlen(param_1);
      *(undefined8 *)(puVar12 + -0x1028) = 0x10d110;
      gnutls_server_name_set(*(undefined8 *)(puVar12 + -0x1018),1,param_1,sVar6);
    }
  }
  if (DAT_0019573a != '\0') {
    *(undefined8 *)(puVar12 + -0x1028) = 0x10d050;
    gnutls_dh_set_prime_bits(*(undefined8 *)(puVar12 + -0x1018),DAT_00195870);
  }
  uVar3 = DAT_00195888;
  if (DAT_00195751 != '\0') {
    if (0x400 < DAT_00195888) {
      *(undefined8 *)(puVar12 + -0x1028) = 0x10d1a1;
      __fprintf_chk(stderr,1,"Number of ALPN protocols too large (%d)\n",DAT_00195888);
      goto LAB_0010cff3;
    }
    if (DAT_00195888 != 0) {
      uVar1 = DAT_00195888 - 1;
      puVar10 = (undefined8 *)(puVar12 + -0x1010);
      puVar13 = DAT_00195880;
      do {
        pcVar2 = (char *)*puVar13;
        puVar11 = puVar10 + 2;
        puVar13 = puVar13 + 1;
        *puVar10 = pcVar2;
        *(undefined8 *)(puVar12 + -0x1028) = 0x10ce35;
        sVar6 = strlen(pcVar2);
        *(int *)(puVar10 + 1) = (int)sVar6;
        puVar10 = puVar11;
      } while ((undefined8 *)(puVar12 + (ulong)uVar1 * 0x10 + -0x1000) != puVar11);
    }
    *(undefined8 *)(puVar12 + -0x1028) = 0x10ce4f;
    gnutls_alpn_set_protocols(*(undefined8 *)(puVar12 + -0x1018),puVar12 + -0x1010,uVar3,0);
  }
  *(undefined8 *)(puVar12 + -0x1028) = 0x10ce65;
  gnutls_credentials_set(*(undefined8 *)(puVar12 + -0x1018),2,DAT_00123710);
  if (DAT_00123720 != 0) {
    *(undefined8 *)(puVar12 + -0x1028) = 0x10ce80;
    gnutls_credentials_set(*(undefined8 *)(puVar12 + -0x1018),3);
  }
  if (DAT_00123718 != 0) {
    *(undefined8 *)(puVar12 + -0x1028) = 0x10ce9b;
    gnutls_credentials_set(*(undefined8 *)(puVar12 + -0x1018),4);
  }
  *(undefined8 *)(puVar12 + -0x1028) = 0x10ceb1;
  gnutls_credentials_set(*(undefined8 *)(puVar12 + -0x1018),1,DAT_00123708);
  *(undefined8 *)(puVar12 + -0x1028) = 0x10cec4;
  gnutls_certificate_set_retrieve_function2(DAT_00123708,FUN_00109f60);
  *(undefined8 *)(puVar12 + -0x1028) = 0x10ced7;
  gnutls_certificate_set_verify_function(DAT_00123708,FUN_0010aa30);
  if (DAT_00122378 < 1) {
LAB_0010cf46:
    uVar9 = *(undefined8 *)(puVar12 + -0x1018);
    if ((DAT_00195752 != '\0') && (DAT_0012373c == 0)) {
      *(undefined8 *)(puVar12 + -0x1028) = 0x10cf70;
      iVar5 = FUN_0010d870(uVar9,DAT_00195890,DAT_00195898);
      if (iVar5 < 0) goto LAB_0010cff3;
      uVar9 = *(undefined8 *)(puVar12 + -0x1018);
    }
  }
  else {
    uVar9 = *(undefined8 *)(puVar12 + -0x1018);
    if (DAT_0012373c == 0) {
      *(undefined8 *)(puVar12 + -0x1028) = 0x10cf3d;
      lVar7 = gnutls_record_set_max_size();
      if (lVar7 < 0) {
        *(undefined8 *)(puVar12 + -0x1028) = 0x10d160;
        __fprintf_chk(stderr,1,"Cannot set the maximum record size to %d.\n",DAT_00122378);
        *(undefined8 *)(puVar12 + -0x1028) = 0x10d17a;
        __fprintf_chk(stderr,1,"Possible values: 512, 1024, 2048, 4096.\n");
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar12 + -0x1028) = 0x10d184;
        exit(1);
      }
      goto LAB_0010cf46;
    }
  }
  if (DAT_00195753 != '\0') {
    *(undefined8 *)(puVar12 + -0x1028) = 0x10cf9a;
    gnutls_heartbeat_enable(uVar9,1);
    uVar9 = *(undefined8 *)(puVar12 + -0x1018);
  }
  if (DAT_00195750 == '\0') {
LAB_0010cf0b:
    if (*(long *)(puVar12 + 0x2ff8) == *(long *)(in_FS_OFFSET + 0x28)) {
      return uVar9;
    }
                    /* WARNING: Subroutine does not return */
    *(undefined8 *)(puVar12 + -0x1028) = 0x10d140;
    __stack_chk_fail();
  }
  *(undefined8 *)(puVar12 + -0x1028) = 0x10cfbb;
  iVar5 = gnutls_srtp_set_profile_direct(uVar9,DAT_00195828,puVar12 + -0x1020);
  uVar9 = stderr;
  if (iVar5 == -0x32) {
    *(undefined8 *)(puVar12 + -0x1028) = 0x10d136;
    __fprintf_chk(stderr,1,"Syntax error at: %s\n",*(undefined8 *)(puVar12 + -0x1020));
  }
  else {
    if (iVar5 == 0) {
      *(undefined8 *)(puVar12 + -0x1028) = 0x10d0cd;
      __fprintf_chk(stderr,1,"DTLS profile set to %s\n",DAT_00195828);
      uVar9 = *(undefined8 *)(puVar12 + -0x1018);
      goto LAB_0010cf0b;
    }
    *(undefined8 *)(puVar12 + -0x1028) = 0x10cfda;
    uVar8 = gnutls_strerror(iVar5);
    *(undefined8 *)(puVar12 + -0x1028) = 0x10cff3;
    __fprintf_chk(uVar9,1,"Error in profiles: %s\n",uVar8);
  }
LAB_0010cff3:
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar12 + -0x1028) = &UNK_0010cffd;
  exit(1);
}



// Function: do_handshake @ 0xd200

int do_handshake(int *param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  if ((DAT_00122370 != 0) && (param_1[0x34] != 0)) {
    gnutls_transport_set_fastopen
              (*(undefined8 *)(param_1 + 2),*param_1,param_1 + 0x14,param_1[0x34],0);
    param_1[0x34] = 0;
  }
  do {
    gnutls_handshake_set_timeout(*(undefined8 *)(param_1 + 2),0xffffffff);
    iVar1 = gnutls_handshake(*(undefined8 *)(param_1 + 2));
    if (-1 < iVar1) {
      uVar4 = *(undefined8 *)(param_1 + 2);
      if (iVar1 == 0) {
        FUN_0010fc20(uVar4,DAT_0012236c,(uint)DAT_0019573f * 2);
        if (DAT_0019575f != '\0') {
          lVar3 = 0x14;
          if (DAT_00195760 != '\0') {
            lVar3 = (long)DAT_00195878;
          }
          FUN_0010f270(*(undefined8 *)(param_1 + 2),DAT_00195850,lVar3);
        }
        param_1[4] = 1;
        return 0;
      }
      goto LAB_0010d2a2;
    }
    FUN_0010d570(param_1,iVar1);
    iVar2 = gnutls_error_is_fatal(iVar1);
  } while (iVar2 == 0);
  uVar4 = *(undefined8 *)(param_1 + 2);
LAB_0010d2a2:
  gnutls_alert_send_appropriate(uVar4,iVar1);
  shutdown(*param_1,2);
  return iVar1;
}



// Function: try_rehandshake @ 0xd320

int try_rehandshake(void)

{
  int iVar1;
  
  iVar1 = FUN_0010d200();
  if (-1 < iVar1) {
    FUN_0010dc90(stdout,"- ReHandshake was completed\n");
    return 0;
  }
  __fprintf_chk(stderr,1,"*** ReHandshake has failed\n");
  gnutls_perror(iVar1);
  return iVar1;
}



// Function: do_inline_command_processing @ 0xd3e0

int do_inline_command_processing(undefined8 param_1,int param_2,undefined8 param_3,long param_4)

{
  char cVar1;
  int iVar2;
  
  while( true ) {
    cVar1 = FUN_0010c050(param_1,(long)param_2,param_4);
    iVar2 = param_2;
    if (((cVar1 == '\0') || (iVar2 = *(int *)(param_4 + 0x18), iVar2 != 0)) ||
       (*(int *)(param_4 + 0x10) == 0)) {
      return iVar2;
    }
    iVar2 = FUN_0010d380(*(int *)(param_4 + 0x10),param_3);
    if (iVar2 != 0) {
      return -1;
    }
    *(undefined4 *)(param_4 + 0x10) = 0;
    iVar2 = (int)*(undefined8 *)(param_4 + 8) - (int)param_1;
    if (param_2 <= iVar2) break;
    param_2 = param_2 - iVar2;
    param_1 = *(undefined8 *)(param_4 + 8);
  }
  return 0;
}



// Function: check_server_cmd @ 0xd470

void check_server_cmd(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    return;
  }
  if (param_2 == -0x25) {
    FUN_0010dc90(stdout,"*** Received rehandshake request\n");
    iVar2 = FUN_0010d200(param_1);
    if (iVar2 == 0) {
      pcVar4 = "*** Rehandshake was performed.\n";
LAB_0010d509:
      FUN_0010dc90(stdout,pcVar4);
      return;
    }
    uVar3 = gnutls_strerror(iVar2);
    pcVar4 = "*** Rehandshake Failed: %s\n";
    uVar5 = stdout;
  }
  else {
    if (param_2 != -0x1a8) {
      return;
    }
    do {
      iVar2 = gnutls_reauth(*(undefined8 *)(param_1 + 8),0);
      if (-1 < iVar2) {
        if (iVar2 == 0) {
          pcVar4 = "*** Re-auth was performed.\n";
          goto LAB_0010d509;
        }
        break;
      }
      iVar1 = gnutls_error_is_fatal(iVar2);
    } while (iVar1 == 0);
    uVar5 = stdout;
    uVar3 = gnutls_strerror(iVar2);
    pcVar4 = "*** Re-auth failed: %s\n";
  }
  FUN_0010dc90(uVar5,pcVar4,uVar3);
  return;
}



// Function: handle_error @ 0xd570

ulong handle_error(long param_1,ulong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  char *pcVar7;
  
  uVar5 = (uint)param_2;
  if ((uVar5 != 0xffffffe4 && (char)(param_2 >> 0x18) < '\0') &&
     (uVar4 = param_2 & 0xffffffff, uVar5 != 0xffffffcc)) {
    pcVar7 = "Non fatal";
    uVar1 = gnutls_error_is_fatal(param_2 & 0xffffffff);
    uVar6 = (ulong)uVar1;
    if (uVar1 != 0) {
      pcVar7 = "Fatal";
      uVar6 = uVar4;
    }
    pcVar3 = (char *)gnutls_strerror(uVar4);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "(unknown)";
    }
    __fprintf_chk(stderr,1,"*** %s error: %s\n",pcVar7,pcVar3);
    if ((uVar5 & 0xfffffffb) == 0xfffffff0) {
      uVar2 = gnutls_alert_get(*(undefined8 *)(param_1 + 8));
      pcVar7 = (char *)gnutls_alert_get_name(uVar2);
      if (pcVar7 == (char *)0x0) {
        pcVar7 = "(unknown)";
      }
      FUN_0010dc90(stdout,"*** Received alert [%d]: %s\n",uVar2,pcVar7);
    }
    FUN_0010d470(param_1,uVar4);
    return uVar6;
  }
  return 0;
}



// Function: raw_to_string @ 0xd670

char * raw_to_string(long param_1,long param_2)

{
  undefined1 *puVar1;
  char *pcVar2;
  long lVar3;
  undefined *puVar4;
  
  if (param_2 != 0) {
    pcVar2 = "(too large)";
    if (param_2 * 3 + 1U < 0x400) {
      lVar3 = 0;
      puVar4 = &DAT_00124080;
      do {
        pcVar2 = ":";
        puVar1 = (undefined1 *)(param_1 + lVar3);
        if (param_2 + -1 == lVar3) {
          pcVar2 = "";
        }
        lVar3 = lVar3 + 1;
        __sprintf_chk(puVar4,1,0xffffffffffffffff,"%02X%s",*puVar1,pcVar2);
        puVar4 = puVar4 + 3;
      } while (param_2 != lVar3);
      DAT_0012447f = 0;
      pcVar2 = &DAT_00124080;
    }
    return pcVar2;
  }
  return "(empty)";
}



// Function: raw_to_hex @ 0xd740

char * raw_to_hex(undefined1 *param_1,long param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  char *pcVar3;
  undefined *puVar4;
  
  pcVar3 = "(empty)";
  if ((param_2 != 0) && (pcVar3 = "(too large)", param_2 * 2 + 1U < 0x400)) {
    puVar1 = param_1 + param_2;
    puVar4 = &DAT_00123c80;
    do {
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      __sprintf_chk(puVar4,1,0xffffffffffffffff,&DAT_001170ff,uVar2);
      puVar4 = puVar4 + 2;
    } while (param_1 != puVar1);
    DAT_0012407f = 0;
    return &DAT_00123c80;
  }
  return pcVar3;
}



// Function: raw_to_base64 @ 0xd7e0

char * raw_to_base64(undefined8 param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  long in_FS_OFFSET;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_20 = (undefined4)param_2;
  pcVar2 = "(empty)";
  local_28 = param_1;
  if (param_2 != 0) {
    local_30 = 0x400;
    iVar1 = gnutls_pem_base64_encode(0,&local_28,&DAT_00123880,&local_30);
    pcVar2 = "(error)";
    if (-1 < iVar1) {
      DAT_00123c7f = 0;
      pcVar2 = &DAT_00123880;
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: compress_cert_set_methods @ 0xd870

int compress_cert_set_methods(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  void *__ptr;
  undefined8 uVar2;
  long lVar3;
  
  iVar1 = 0;
  if (param_3 != 0) {
    __ptr = (void *)reallocarray(0,param_3,4);
    if (__ptr == (void *)0x0) {
      iVar1 = -0x19;
      uVar2 = gnutls_strerror(0);
      __fprintf_chk(stderr,1,"Could not set certificate compression methods: %s\n",uVar2);
    }
    else {
      lVar3 = 0;
      do {
        uVar2 = *(undefined8 *)(param_2 + lVar3 * 8);
        iVar1 = gnutls_compression_get_id(uVar2);
        *(int *)((long)__ptr + lVar3 * 4) = iVar1;
        if (iVar1 == 0) {
          iVar1 = 0;
          __fprintf_chk(stderr,1,"Unknown compression method: %s\n",uVar2);
          goto LAB_0010d903;
        }
        lVar3 = lVar3 + 1;
      } while (param_3 != lVar3);
      iVar1 = gnutls_compress_certificate_set_methods(param_1,__ptr,param_3);
      if (iVar1 < 0) {
        uVar2 = gnutls_strerror(iVar1);
        __fprintf_chk(stderr,1,"Could not set certificate compression methods: %s\n",uVar2);
      }
LAB_0010d903:
      free(__ptr);
    }
  }
  return iVar1;
}



// Function: check_command @ 0xd990

int check_command(undefined8 param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  sVar3 = strnlen(param_2,0x80);
  __fprintf_chk(stderr,1,"*** Processing %u bytes command: %s\n",sVar3 & 0xffffffff,param_2);
  iVar1 = 0;
  if (2 < sVar3) {
    if ((param_2[1] == *param_2) && (*param_2 == '*')) {
      iVar1 = strncmp(param_2,"**REHANDSHAKE**",0xf);
      if (iVar1 == 0) {
        iVar1 = 1;
        __fprintf_chk(stderr,1,"*** Sending rehandshake request\n");
        gnutls_rehandshake(param_1);
      }
      else {
        iVar1 = strncmp(param_2,"**REAUTH**",10);
        if (iVar1 == 0) {
          if (param_3 != 0) {
            gnutls_certificate_server_set_request(param_1,2);
          }
          __fprintf_chk(stderr,1,"*** Sending re-auth request\n");
          do {
            do {
              iVar1 = gnutls_reauth(param_1,0);
            } while (iVar1 == -0x1c);
          } while (iVar1 == -0x34);
          if (iVar1 < 0) {
            uVar5 = gnutls_strerror(iVar1);
            __fprintf_chk(stderr,1,"reauth: %s\n",uVar5);
          }
          else {
            iVar1 = 1;
          }
        }
        else {
          iVar2 = strncmp(param_2,"**HEARTBEAT**",0xd);
          iVar1 = 0;
          if (iVar2 == 0) {
            iVar1 = gnutls_heartbeat_ping(param_1,300,5,1);
            uVar5 = stderr;
            if (iVar1 < 0) {
              if (iVar1 == -0x32) {
                iVar1 = 2;
                __fprintf_chk(stderr,1,"No heartbeat in this session\n");
              }
              else {
                uVar4 = gnutls_strerror(iVar1);
                __fprintf_chk(uVar5,1,"ping: %s\n",uVar4);
              }
            }
            else {
              iVar1 = 2;
            }
          }
        }
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



// Function: getpass_copy @ 0xdba0

void getpass_copy(char *param_1,ulong param_2,char *param_3)

{
  char *__s;
  size_t sVar1;
  
  __s = getpass(param_3);
  if (__s != (char *)0x0) {
    sVar1 = strlen(__s);
    if (sVar1 < param_2) {
      strcpy(param_1,__s);
      gnutls_memset(__s,0,sVar1);
      return;
    }
    gnutls_memset(__s,0,sVar1);
  }
  *param_1 = '\0';
  return;
}



// Function: getenv_copy @ 0xdc20

void getenv_copy(char *param_1,ulong param_2,char *param_3)

{
  char *__s;
  size_t sVar1;
  
  __s = getenv(param_3);
  if (__s != (char *)0x0) {
    sVar1 = strlen(__s);
    if (sVar1 < param_2) {
      strcpy(param_1,__s);
      return;
    }
  }
  *param_1 = '\0';
  return;
}



// Function: sockets_init @ 0xdc70

void sockets_init(void)

{
  signal(0xd,(__sighandler_t)0x1);
  return;
}



// Function: log_msg @ 0xdc90

void log_msg(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 long param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  long lVar1;
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
  lVar1 = DAT_00124480;
  if (DAT_00124480 == 0) {
    lVar1 = param_9;
  }
  local_d4 = 0x30;
  local_a8 = param_11;
  local_a0 = param_12;
  local_98 = param_13;
  local_90 = param_14;
  __vfprintf_chk(lVar1,1,param_10,&local_d8);
  if (local_c0 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: cert_verify @ 0xdd70

undefined8 cert_verify(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  bool bVar6;
  uint local_5c;
  undefined8 local_58 [2];
  undefined1 local_48 [8];
  long lStack_40;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_5c = 0;
  _local_48 = (undefined1  [16])0x0;
  local_38 = (undefined1  [16])0x0;
  local_28 = (undefined1  [16])0x0;
  bVar6 = param_2 != 0;
  if (bVar6) {
    stack0xffffffffffffffbc = SUB1612((undefined1  [16])0x0,4);
    local_48._0_4_ = 1;
    lStack_40 = param_2;
  }
  uVar5 = (ulong)bVar6;
  if (param_3 != 0) {
    uVar5 = (ulong)(bVar6 + 1);
    lVar4 = (ulong)bVar6 * 0x18;
    *(undefined4 *)(local_48 + lVar4) = 2;
    *(long *)(local_38 + lVar4 + -8) = param_3;
  }
  iVar1 = gnutls_certificate_verify_peers(param_1,local_48,uVar5,&local_5c);
  if (iVar1 == -0x31) {
    FUN_0010dc90(stdout,"- Peer did not send any certificate.\n");
    uVar3 = 0;
  }
  else if (iVar1 < 0) {
    uVar3 = gnutls_strerror(iVar1);
    FUN_0010dc90(stdout,"- Could not verify certificate (err: %s)\n",uVar3);
    uVar3 = 0;
  }
  else {
    uVar2 = gnutls_certificate_type_get(param_1);
    iVar1 = gnutls_certificate_verification_status_print(local_5c,uVar2,local_58,0);
    if (iVar1 < 0) {
      uVar3 = gnutls_strerror(iVar1);
      FUN_0010dc90(stdout,"- Could not print verification flags (err: %s)\n",uVar3);
      uVar3 = 0;
    }
    else {
      FUN_0010dc90(stdout,"- Status: %s\n",local_58[0]);
      (*gnutls_free)(local_58[0]);
      local_58[0] = 0;
      if (local_5c == 0) {
        uVar3 = 1;
      }
      else {
        if ((local_5c & 2) == 0) {
                    /* WARNING: Subroutine does not return */
          abort();
        }
        uVar3 = 0;
      }
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: print_dh_info @ 0xdf10

void print_dh_info(undefined8 param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  char *pcVar4;
  long in_FS_OFFSET;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined4 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_40 = 0;
  local_48 = 0;
  local_38 = 0;
  local_30 = 0;
  local_58 = 0;
  local_50 = 0;
  if (param_3 == 0) goto LAB_0010df60;
  iVar1 = gnutls_group_get();
  if (iVar1 != 0) goto LAB_0010df60;
  FUN_0010dc90(stdout,"- %sDiffie-Hellman parameters\n",param_2);
  uVar2 = gnutls_dh_get_prime_bits(param_1);
  FUN_0010dc90(stdout," - Using prime: %d bits\n",uVar2);
  uVar2 = gnutls_dh_get_secret_bits(param_1);
  FUN_0010dc90(stdout," - Secret key: %d bits\n",uVar2);
  uVar2 = gnutls_dh_get_peers_public_bits(param_1);
  FUN_0010dc90(stdout," - Peer\'s public key: %d bits\n",uVar2);
  iVar1 = gnutls_dh_get_group(param_1,&local_48,&local_38);
  pcVar4 = "gnutls_dh_get_group %d\n";
  if (iVar1 == 0) {
    iVar1 = gnutls_dh_params_init(&local_58);
    if (iVar1 != 0) {
      pcVar4 = "gnutls_dh_params_init %d\n";
      goto LAB_0010e0e1;
    }
    iVar1 = gnutls_dh_params_import_raw(local_58,&local_38,&local_48);
    pcVar4 = "gnutls_dh_params_import_raw %d\n";
    if (iVar1 != 0) goto LAB_0010e0e1;
    iVar1 = gnutls_dh_params_export_pkcs3(local_58,1,0,&local_50);
    pcVar4 = "gnutls_dh_params_export_pkcs3 %d\n";
    if (iVar1 != -0x33) goto LAB_0010e0e1;
    lVar3 = (*gnutls_malloc)(local_50);
    if (lVar3 == 0) {
      __fprintf_chk(stderr,1,"gnutls_malloc %d\n",0xffffffcd);
    }
    else {
      iVar1 = gnutls_dh_params_export_pkcs3(local_58,1,lVar3,&local_50);
      if (iVar1 == 0) {
        FUN_0010dc90(stdout," - PKCS#3 format:\n\n%.*s\n",local_50 & 0xffffffff,lVar3);
      }
      else {
        __fprintf_chk(stderr,1,"gnutls_dh_params_export_pkcs3-2 %d\n",iVar1);
      }
    }
  }
  else {
LAB_0010e0e1:
    lVar3 = 0;
    __fprintf_chk(stderr,1,pcVar4,iVar1);
  }
  (*gnutls_free)(lVar3);
  (*gnutls_free)(local_38);
  local_38 = 0;
  (*gnutls_free)(local_48);
  local_48 = 0;
  gnutls_dh_params_deinit(local_58);
LAB_0010df60:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: print_ecdh_info @ 0xe180

void print_ecdh_info(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_3 == 0) {
    return;
  }
  FUN_0010dc90(stdout,"- %sEC Diffie-Hellman parameters\n",param_2);
  uVar1 = gnutls_ecc_curve_get(param_1);
  uVar3 = gnutls_ecc_curve_get_name(uVar1);
  FUN_0010dc90(stdout," - Using curve: %s\n",uVar3);
  iVar2 = gnutls_ecc_curve_get_size(uVar1);
  FUN_0010dc90(stdout," - Curve size: %d bits\n",iVar2 * 8);
  return;
}



// Function: print_channel_bindings @ 0xe200

void print_channel_bindings(undefined8 param_1,int param_2)

{
  undefined1 *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  undefined4 uVar6;
  ulong uVar7;
  long in_FS_OFFSET;
  long local_58;
  uint local_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 != 0) {
    ppuVar5 = (undefined **)&DAT_0011e960;
    FUN_0010dc90(stdout,"- Channel bindings\n");
    uVar6 = 0;
    while( true ) {
      iVar3 = gnutls_session_channel_binding(param_1,uVar6,&local_58);
      if (iVar3 == -0xd5) {
        FUN_0010dc90(stdout," - \'%s\': not available\n",ppuVar5[1]);
      }
      else {
        puVar2 = ppuVar5[1];
        if (iVar3 < 0) {
          uVar4 = gnutls_strerror(iVar3);
          __fprintf_chk(stderr,1," - \'%s\': error: %s\n",puVar2,uVar4);
        }
        else {
          uVar7 = 0;
          FUN_0010dc90(stdout," - \'%s\': ",puVar2);
          if (local_50 != 0) {
            do {
              puVar1 = (undefined1 *)(local_58 + uVar7);
              uVar7 = uVar7 + 1;
              FUN_0010dc90(stdout,&DAT_001170ff,*puVar1);
            } while (uVar7 < local_50);
          }
          FUN_0010dc90(stdout,"\n");
          (*gnutls_free)(local_58);
        }
      }
      ppuVar5 = ppuVar5 + 2;
      if (ppuVar5 == &PTR_s______BEGIN_PRIVATE_KEY______MC4C_0011e990) break;
      uVar6 = *(undefined4 *)ppuVar5;
    }
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: print_x509_info @ 0xe380

void print_x509_info(undefined8 param_1,undefined8 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  long in_FS_OFFSET;
  uint local_74;
  undefined8 local_70;
  undefined8 local_68 [2];
  undefined8 local_58 [3];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_74 = 0;
  lVar2 = gnutls_certificate_get_peers(param_1,&local_74);
  if (local_74 == 0) {
    if (param_5 != 0) {
      __fprintf_chk(stderr,1,"No certificates found!\n");
    }
  }
  else {
    FUN_0010dc90(param_2,"- Certificate type: X.509\n");
    FUN_0010dc90(param_2,"- Got a certificate list of %d certificates.\n",local_74);
    if (local_74 != 0) {
      uVar4 = 0;
      do {
        iVar1 = gnutls_x509_crt_init(&local_70);
        if (iVar1 < 0) {
          __fprintf_chk(stderr,1,"Memory error\n");
          break;
        }
        iVar1 = gnutls_x509_crt_import(local_70,(ulong)uVar4 * 0x10 + lVar2,0);
        if (iVar1 < 0) {
          uVar3 = gnutls_strerror(iVar1);
          __fprintf_chk(stderr,1,"Decoding error: %s\n",uVar3);
          break;
        }
        FUN_0010dc90(param_2,"- Certificate[%d] info:\n - ",uVar4);
        if ((param_3 == 3) && (uVar4 != 0)) {
          param_3 = 1;
        }
        iVar1 = gnutls_x509_crt_print(local_70,param_3,local_68);
        if (iVar1 == 0) {
          FUN_0010dc90(param_2,"%s\n",local_68[0]);
          (*gnutls_free)(local_68[0]);
          local_68[0] = 0;
        }
        if (param_4 != 0) {
          iVar1 = gnutls_x509_crt_export2(local_70,1,local_58);
          if (iVar1 < 0) {
            uVar3 = gnutls_strerror(iVar1);
            __fprintf_chk(stderr,1,"Encoding error: %s\n",uVar3);
            break;
          }
          FUN_0010dc90(param_2,&DAT_001172e3,local_58[0]);
          (*gnutls_free)(local_58[0]);
        }
        gnutls_x509_crt_deinit(local_70);
        uVar4 = uVar4 + 1;
      } while (uVar4 < local_74);
    }
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: print_list @ 0xe5e0

void print_list(long param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  int *piVar9;
  undefined8 uVar10;
  ulong uVar11;
  long in_FS_OFFSET;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined1 local_42;
  undefined1 local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 == 0) {
    lVar5 = 0;
    FUN_0010dc90(stdout,"Cipher suites:\n");
    while (lVar7 = gnutls_cipher_suite_info(lVar5,&local_42,&local_60,&local_58,&local_50,&local_64)
          , lVar7 != 0) {
      uVar6 = gnutls_protocol_get_name(local_64);
      FUN_0010dc90(stdout,"%-50s\t0x%02x, 0x%02x\t%s\n",lVar7,local_42,local_41,uVar6);
      if (param_2 != 0) {
        uVar6 = gnutls_mac_get_name(local_50);
        uVar10 = gnutls_cipher_get_name(local_58);
        uVar8 = gnutls_kx_get_name(local_60);
        FUN_0010dc90(stdout,"\tKey exchange: %s\n\tCipher: %s\n\tMAC: %s\n\n",uVar8,uVar10,uVar6);
      }
      lVar5 = lVar5 + 1;
    }
    FUN_0010dc90(stdout,"\n");
    piVar9 = (int *)gnutls_certificate_type_list();
    FUN_0010dc90(stdout,"Certificate types: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      while( true ) {
        uVar6 = gnutls_certificate_type_get_name();
        FUN_0010dc90(stdout,"CTYPE-%s",uVar6);
        if (piVar9[1] != 0) break;
        piVar9 = piVar9 + 1;
        FUN_0010dc90(stdout,"\n");
        if (*piVar9 == 0) goto LAB_0010ed00;
      }
      piVar9 = piVar9 + 1;
      FUN_0010dc90(stdout,&DAT_00117331);
      iVar2 = *piVar9;
    }
LAB_0010ed00:
    piVar9 = (int *)gnutls_protocol_list();
    FUN_0010dc90(stdout,"Protocols: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      while( true ) {
        uVar6 = gnutls_protocol_get_name();
        FUN_0010dc90(stdout,"VERS-%s",uVar6);
        if (piVar9[1] != 0) break;
        piVar9 = piVar9 + 1;
        FUN_0010dc90(stdout,"\n");
        if (*piVar9 == 0) goto LAB_0010ed90;
      }
      piVar9 = piVar9 + 1;
      FUN_0010dc90(stdout,&DAT_00117331);
      iVar2 = *piVar9;
    }
LAB_0010ed90:
    piVar9 = (int *)gnutls_cipher_list();
    FUN_0010dc90(stdout,"Ciphers: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      while( true ) {
        uVar6 = gnutls_cipher_get_name();
        FUN_0010dc90(stdout,"%s",uVar6);
        if (piVar9[1] != 0) break;
        piVar9 = piVar9 + 1;
        FUN_0010dc90(stdout,"\n");
        if (*piVar9 == 0) goto LAB_0010ee22;
      }
      piVar9 = piVar9 + 1;
      FUN_0010dc90(stdout,&DAT_00117331);
      iVar2 = *piVar9;
    }
LAB_0010ee22:
    piVar9 = (int *)gnutls_mac_list();
    FUN_0010dc90(stdout,"MACs: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      while( true ) {
        uVar6 = gnutls_mac_get_name();
        FUN_0010dc90(stdout,"%s",uVar6);
        if (piVar9[1] != 0) break;
        piVar9 = piVar9 + 1;
        FUN_0010dc90(stdout,"\n");
        if (*piVar9 == 0) goto LAB_0010eeba;
      }
      piVar9 = piVar9 + 1;
      FUN_0010dc90(stdout,&DAT_00117331);
      iVar2 = *piVar9;
    }
LAB_0010eeba:
    piVar9 = (int *)gnutls_digest_list();
    FUN_0010dc90(stdout,"Digests: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      while( true ) {
        uVar6 = gnutls_digest_get_name();
        FUN_0010dc90(stdout,"%s",uVar6);
        if (piVar9[1] != 0) break;
        piVar9 = piVar9 + 1;
        FUN_0010dc90(stdout,"\n");
        if (*piVar9 == 0) goto LAB_0010ef4a;
      }
      piVar9 = piVar9 + 1;
      FUN_0010dc90(stdout,&DAT_00117331);
      iVar2 = *piVar9;
    }
LAB_0010ef4a:
    piVar9 = (int *)gnutls_kx_list();
    FUN_0010dc90(stdout,"Key exchange algorithms: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      while( true ) {
        uVar6 = gnutls_kx_get_name();
        FUN_0010dc90(stdout,"%s",uVar6);
        if (piVar9[1] != 0) break;
        piVar9 = piVar9 + 1;
        FUN_0010dc90(stdout,"\n");
        if (*piVar9 == 0) goto LAB_0010efd8;
      }
      piVar9 = piVar9 + 1;
      FUN_0010dc90(stdout,&DAT_00117331);
      iVar2 = *piVar9;
    }
LAB_0010efd8:
    piVar9 = (int *)gnutls_compression_list();
    FUN_0010dc90(stdout,"Compression: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      while( true ) {
        uVar6 = gnutls_compression_get_name();
        FUN_0010dc90(stdout,"COMP-%s",uVar6);
        if (piVar9[1] != 0) break;
        piVar9 = piVar9 + 1;
        FUN_0010dc90(stdout,"\n");
        if (*piVar9 == 0) goto LAB_0010f066;
      }
      piVar9 = piVar9 + 1;
      FUN_0010dc90(stdout,&DAT_00117331);
      iVar2 = *piVar9;
    }
LAB_0010f066:
    piVar9 = (int *)gnutls_group_list();
    FUN_0010dc90(stdout,"Groups: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      while( true ) {
        uVar6 = gnutls_group_get_name();
        FUN_0010dc90(stdout,"GROUP-%s",uVar6);
        if (piVar9[1] != 0) break;
        piVar9 = piVar9 + 1;
        FUN_0010dc90(stdout,"\n");
        if (*piVar9 == 0) goto LAB_0010f0f6;
      }
      piVar9 = piVar9 + 1;
      FUN_0010dc90(stdout,&DAT_00117331);
      iVar2 = *piVar9;
    }
LAB_0010f0f6:
    piVar9 = (int *)gnutls_pk_list();
    FUN_0010dc90(stdout,"Public Key Systems: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      while( true ) {
        uVar6 = gnutls_pk_algorithm_get_name();
        FUN_0010dc90(stdout,"%s",uVar6);
        if (piVar9[1] != 0) break;
        piVar9 = piVar9 + 1;
        FUN_0010dc90(stdout,"\n");
        if (*piVar9 == 0) goto LAB_0010f188;
      }
      piVar9 = piVar9 + 1;
      FUN_0010dc90(stdout,&DAT_00117331);
      iVar2 = *piVar9;
    }
LAB_0010f188:
    piVar9 = (int *)gnutls_sign_list();
    FUN_0010dc90(stdout,"PK-signatures: ");
    iVar2 = *piVar9;
    while (iVar2 != 0) {
      uVar6 = gnutls_sign_get_name();
      FUN_0010dc90(stdout,"SIGN-%s",uVar6);
      if (piVar9[1] == 0) {
        FUN_0010dc90(stdout,"\n");
      }
      else {
        FUN_0010dc90(stdout,&DAT_00117331);
      }
      piVar1 = piVar9 + 1;
      piVar9 = piVar9 + 1;
      iVar2 = *piVar1;
    }
  }
  else {
    FUN_0010dc90(stdout,"Cipher suites for %s\n",param_1);
    iVar2 = gnutls_priority_init(&local_58,param_1,&local_60);
    uVar6 = stderr;
    if (iVar2 < 0) {
      if (iVar2 == -0x32) {
        __fprintf_chk(stderr,1,"Syntax error at: %s\n",CONCAT44(uStack_5c,local_60));
      }
      else {
        uVar10 = gnutls_strerror(iVar2);
        __fprintf_chk(uVar6,1,"Error in priorities: %s\n",uVar10);
      }
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar2 = 0;
    while (iVar3 = gnutls_priority_get_cipher_suite_index
                             (CONCAT44(uStack_54,local_58),iVar2,&local_68), iVar3 != -0x38) {
      if ((iVar3 != -0x15) &&
         (lVar5 = gnutls_cipher_suite_info(local_68,&local_42,0,0,0,&local_64), lVar5 != 0)) {
        uVar6 = gnutls_protocol_get_name(local_64);
        FUN_0010dc90(stdout,"%-50s\t0x%02x, 0x%02x\t%s\n",lVar5,local_42,local_41,uVar6);
      }
      iVar2 = iVar2 + 1;
    }
    uVar11 = 0;
    FUN_0010dc90(stdout,"\n");
    uVar4 = gnutls_priority_protocol_list(CONCAT44(uStack_54,local_58),&local_50);
    FUN_0010dc90(stdout,"Protocols: ");
    if (uVar4 == 0) {
      FUN_0010dc90(stdout,"none\n");
    }
    else {
      while( true ) {
        lVar5 = uVar11 * 4;
        uVar11 = uVar11 + 1;
        uVar6 = gnutls_protocol_get_name(*(undefined4 *)(CONCAT44(uStack_4c,local_50) + lVar5));
        FUN_0010dc90(stdout,"VERS-%s",uVar6);
        if (uVar11 == uVar4) break;
        FUN_0010dc90(stdout,&DAT_00117331);
      }
      FUN_0010dc90(stdout,"\n");
    }
    uVar11 = 0;
    uVar4 = gnutls_priority_cipher_list(CONCAT44(uStack_54,local_58),&local_50);
    FUN_0010dc90(stdout,"Ciphers: ");
    if (uVar4 == 0) {
      FUN_0010dc90(stdout,"none\n");
    }
    else {
      while( true ) {
        lVar5 = uVar11 * 4;
        uVar11 = uVar11 + 1;
        uVar6 = gnutls_cipher_get_name(*(undefined4 *)(CONCAT44(uStack_4c,local_50) + lVar5));
        FUN_0010dc90(stdout,"%s",uVar6);
        if (uVar11 == uVar4) break;
        FUN_0010dc90(stdout,&DAT_00117331);
      }
      FUN_0010dc90(stdout,"\n");
    }
    uVar11 = 0;
    uVar4 = gnutls_priority_mac_list(CONCAT44(uStack_54,local_58),&local_50);
    FUN_0010dc90(stdout,"MACs: ");
    if (uVar4 == 0) {
      FUN_0010dc90(stdout,"none\n");
    }
    else {
      while( true ) {
        lVar5 = uVar11 * 4;
        uVar11 = uVar11 + 1;
        uVar6 = gnutls_mac_get_name(*(undefined4 *)(CONCAT44(uStack_4c,local_50) + lVar5));
        FUN_0010dc90(stdout,"%s",uVar6);
        if (uVar11 == uVar4) break;
        FUN_0010dc90(stdout,&DAT_00117331);
      }
      FUN_0010dc90(stdout,"\n");
    }
    uVar11 = 0;
    uVar4 = gnutls_priority_kx_list(CONCAT44(uStack_54,local_58),&local_50);
    FUN_0010dc90(stdout,"Key Exchange Algorithms: ");
    if (uVar4 == 0) {
      FUN_0010dc90(stdout,"none\n");
    }
    else {
      while( true ) {
        lVar5 = uVar11 * 4;
        uVar11 = uVar11 + 1;
        uVar6 = gnutls_kx_get_name(*(undefined4 *)(CONCAT44(uStack_4c,local_50) + lVar5));
        FUN_0010dc90(stdout,"%s",uVar6);
        if (uVar11 == uVar4) break;
        FUN_0010dc90(stdout,&DAT_00117331);
      }
      FUN_0010dc90(stdout,"\n");
    }
    uVar11 = 0;
    uVar4 = gnutls_priority_group_list(CONCAT44(uStack_54,local_58),&local_50);
    FUN_0010dc90(stdout,"Groups: ");
    if (uVar4 == 0) {
      FUN_0010dc90(stdout,"none\n");
    }
    else {
      while( true ) {
        lVar5 = uVar11 * 4;
        uVar11 = uVar11 + 1;
        uVar6 = gnutls_group_get_name(*(undefined4 *)(CONCAT44(uStack_4c,local_50) + lVar5));
        FUN_0010dc90(stdout,"GROUP-%s",uVar6);
        if (uVar11 == uVar4) break;
        FUN_0010dc90(stdout,&DAT_00117331);
      }
      FUN_0010dc90(stdout,"\n");
    }
    uVar11 = 0;
    uVar4 = gnutls_priority_sign_list(CONCAT44(uStack_54,local_58),&local_50);
    FUN_0010dc90(stdout,"PK-signatures: ");
    if (uVar4 == 0) {
      FUN_0010dc90(stdout,"none\n");
    }
    else {
      while( true ) {
        lVar5 = uVar11 * 4;
        uVar11 = uVar11 + 1;
        uVar6 = gnutls_sign_get_name(*(undefined4 *)(CONCAT44(uStack_4c,local_50) + lVar5));
        FUN_0010dc90(stdout,"SIGN-%s",uVar6);
        if (uVar11 == uVar4) break;
        FUN_0010dc90(stdout,&DAT_00117331);
      }
      FUN_0010dc90(stdout,"\n");
    }
    gnutls_priority_deinit(CONCAT44(uStack_54,local_58));
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: print_key_material @ 0xf270

void print_key_material(undefined8 param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  size_t sVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  long local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_58 = (*gnutls_malloc)(param_3);
  if (local_58 == 0) {
    uVar3 = gnutls_strerror(0xffffffe7);
    __fprintf_chk(stderr,1,"Error in gnutls_malloc: %s\n",uVar3);
  }
  else {
    local_50 = (undefined4)param_3;
    sVar2 = strlen(param_2);
    iVar1 = gnutls_prf_rfc5705(param_1,sVar2,param_2,0,0,param_3);
    if (iVar1 < 0) {
      uVar3 = gnutls_strerror(iVar1);
      __fprintf_chk(stderr,1,"Error in gnutls_prf_rfc5705: %s\n",uVar3);
    }
    else {
      iVar1 = gnutls_hex_encode2(&local_58,&local_48);
      if (iVar1 < 0) {
        uVar3 = gnutls_strerror(iVar1);
        __fprintf_chk(stderr,1,"Error in hex encoding: %s\n",uVar3);
      }
      else {
        FUN_0010dc90(stdout,"- Key material: %s\n",local_48);
        fflush(stdout);
      }
    }
  }
  (*gnutls_free)(local_58);
  local_58 = 0;
  (*gnutls_free)(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: pin_callback @ 0xf410

undefined8
pin_callback(long param_1,undefined8 param_2,char *param_3,char *param_4,uint param_5,char *param_6,
            ulong param_7)

{
  int iVar1;
  size_t sVar2;
  long lVar3;
  char *pcVar4;
  undefined8 *puVar5;
  ulong __n;
  uint uVar6;
  long in_FS_OFFSET;
  byte bVar7;
  char *local_160;
  char *local_158;
  undefined1 local_148 [16];
  undefined1 local_138 [16];
  undefined1 local_128 [16];
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  long local_40;
  
  bVar7 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_148 = (undefined1  [16])0x0;
  local_138 = (undefined1  [16])0x0;
  local_128 = (undefined1  [16])0x0;
  local_118 = (undefined1  [16])0x0;
  local_108 = (undefined1  [16])0x0;
  local_f8 = (undefined1  [16])0x0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_c8 = (undefined1  [16])0x0;
  local_b8 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_98 = (undefined1  [16])0x0;
  local_88 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  if ((param_5 & 2) == 0) {
    local_160 = "GNUTLS_PIN";
    local_158 = "user";
    if (param_1 != 0) {
      lVar3 = *(long *)(param_1 + 0xa0);
      goto joined_r0x0010f5cb;
    }
  }
  else {
    local_160 = "GNUTLS_SO_PIN";
    local_158 = "security officer";
    if (param_1 != 0) {
      lVar3 = *(long *)(param_1 + 0xa8);
joined_r0x0010f5cb:
      if (lVar3 != 0) {
        snprintf(local_148,0x100,"%s");
      }
    }
  }
  uVar6 = param_5 & 0x20;
  if ((param_5 & 4) == 0) {
    if ((param_5 & 8) != 0) {
LAB_0010f5fa:
      FUN_0010dc90(stdout,"*** Only few tries left before locking!\n");
      goto LAB_0010f60f;
    }
    if ((param_5 & 0x20) != 0) goto LAB_0010f6f8;
    if (((param_3 == (char *)0x0) || (DAT_00123860 == (char *)0x0)) ||
       (iVar1 = strcmp(DAT_00123860,param_3), iVar1 != 0)) goto LAB_0010f618;
    sVar2 = strlen(&DAT_00123760);
    if (sVar2 < param_7) {
      if ((param_1 != 0) && (*(int *)(param_1 + 0xc4) != 0)) {
        __fprintf_chk(stderr,1,"Re-using cached PIN for token \'%s\'\n",param_4);
      }
      strcpy(param_6,&DAT_00123760);
      goto LAB_0010f6b9;
    }
    pcVar4 = "Too long PIN given\n";
  }
  else {
    FUN_0010dc90(stdout,"*** This is the final try before locking!\n");
    if ((param_5 & 8) != 0) goto LAB_0010f5fa;
LAB_0010f60f:
    if ((param_5 & 0x20) == 0) {
LAB_0010f618:
      uVar6 = 0;
      if (local_148[0] != '\0') goto LAB_0010f626;
LAB_0010f718:
      FUN_0010dc20(local_148,0x100,local_160);
      if (local_148[0] != '\0') goto LAB_0010f626;
      FUN_0010dc20(local_148,0x100,"GNUTLS_PIN");
      if (local_148[0] != '\0') goto LAB_0010f626;
      if (param_1 != 0) {
        pcVar4 = *(char **)(param_1 + 0x70);
        if (pcVar4 == (char *)0x0) {
          if ((*(int *)(param_1 + 0xbc) != 0) && (*(int *)(param_1 + 0x80) == 0)) goto LAB_0010f626;
        }
        else if (*(int *)(param_1 + 0x80) == 0) {
          sVar2 = strlen(pcVar4);
          if (sVar2 < 0x100) {
            __strcpy_chk(local_148,pcVar4,0x100);
          }
          else {
            puVar5 = (undefined8 *)local_148;
            for (lVar3 = 0x1f; lVar3 != 0; lVar3 = lVar3 + -1) {
              *puVar5 = *(undefined8 *)pcVar4;
              pcVar4 = pcVar4 + (ulong)bVar7 * -0x10 + 8;
              puVar5 = puVar5 + (ulong)bVar7 * -2 + 1;
            }
            *(undefined4 *)puVar5 = *(undefined4 *)pcVar4;
            *(undefined2 *)((long)puVar5 + 4) = *(undefined2 *)(pcVar4 + 4);
            *(char *)((long)puVar5 + 6) = pcVar4[6];
            local_58[0xf] = 0;
          }
          if ((local_148[0] != '\0') || (*(int *)(param_1 + 0xbc) != 0)) goto LAB_0010f626;
        }
      }
      if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
        FUN_0010dba0(local_148,0x100,"Enter password: ");
      }
      else {
        __fprintf_chk(stderr,1,"Token \'%s\' with URL \'%s\' ",param_4,param_3);
        __fprintf_chk(stderr,1,"requires %s PIN\n",local_158);
        FUN_0010dba0(local_148,0x100,"Enter PIN: ");
      }
    }
    else {
LAB_0010f6f8:
      FUN_0010dc90(stdout,"*** Wrong PIN has been provided!\n");
      if (local_148[0] == '\0') goto LAB_0010f718;
LAB_0010f626:
      if (uVar6 != 0) {
        if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {
          __fprintf_chk(stderr,1,"Token \'%s\' with URL \'%s\' ",param_4,param_3);
          __fprintf_chk(stderr,1,"requires %s PIN\n",local_158);
        }
        pcVar4 = "Cannot continue with a wrong password in the environment.\n";
        goto LAB_0010f92c;
      }
    }
    if ((local_148[0] != '\0') && (local_148[0] != '\n')) {
      sVar2 = strlen(local_148);
      uVar6 = (int)param_7 - 1;
      if (sVar2 <= param_7 - 1) {
        uVar6 = (uint)sVar2;
      }
      __n = (ulong)uVar6;
      memcpy(param_6,local_148,__n);
      param_6[__n] = '\0';
      if (uVar6 < 0x100) {
        lVar3 = __memcpy_chk(&DAT_00123760,param_6,__n,0x100);
        *(undefined1 *)(lVar3 + __n) = 0;
      }
      else {
        DAT_00123760 = 0;
      }
      free(DAT_00123860);
      if (param_3 == (char *)0x0) {
        DAT_00123860 = (char *)0x0;
      }
      else {
        DAT_00123860 = strdup(param_3);
      }
LAB_0010f6b9:
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    __fprintf_chk(stderr,1,"No PIN given.\n");
    if ((param_1 == 0) || (*(int *)(param_1 + 0xbc) == 0)) goto LAB_0010f90a;
    pcVar4 = 
    "note: when operating in batch mode, set the GNUTLS_PIN or GNUTLS_SO_PIN environment variables\n"
    ;
  }
LAB_0010f92c:
  __fprintf_chk(stderr,1,pcVar4);
LAB_0010f90a:
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: print_cert_info2 @ 0xfb50

void print_cert_info2(undefined8 param_1,int param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = gnutls_certificate_client_get_request_status();
  bVar2 = iVar1 != 0;
  if (bVar2) {
    FUN_0010dc90(stdout,"- Server has requested a certificate.\n");
  }
  iVar1 = gnutls_certificate_type_get2(param_1,3);
  if (iVar1 != 1) {
    if (iVar1 != 3) {
      return;
    }
    FUN_0010f9a0(param_1,param_3,param_4,bVar2);
    return;
  }
  FUN_0010e380(param_1,param_3,-(param_2 == 0) & 3,param_4,bVar2);
  return;
}



// Function: print_cert_info @ 0xfc00

void print_cert_info(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_0010fb50(param_1,param_2,stdout,param_3);
  return;
}



// Function: print_info @ 0xfc20

undefined8 print_info(undefined8 param_1,int param_2,ulong param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  long in_FS_OFFSET;
  undefined4 local_194;
  long local_190;
  undefined8 local_188;
  undefined4 local_180;
  undefined1 local_178 [48];
  undefined1 local_148 [264];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_190 = 0x21;
  uVar5 = gnutls_session_get_desc();
  FUN_0010dc90(stdout,"- Description: %s\n",uVar5);
  (*gnutls_free)(uVar5);
  gnutls_session_get_id(param_1,local_178,&local_190);
  if (local_190 != 0) {
    uVar5 = FUN_0010d670(local_178);
    FUN_0010dc90(stdout,"- Session ID: %s\n",uVar5);
  }
  iVar1 = gnutls_kx_get(param_1);
  uVar2 = gnutls_auth_get_type(param_1);
  switch(uVar2) {
  case 1:
    local_188 = 0x100;
    iVar4 = gnutls_server_name_get(param_1,local_148,&local_188,&local_194,0);
    if (iVar4 == 0) {
      FUN_0010dc90(stdout,"- Given server name[%d]: %s\n",local_194,local_148);
    }
    if (((param_3 & 2) != 0) && (lVar6 = gnutls_certificate_get_ours(param_1), lVar6 == 0)) {
      FUN_0010dc90(stdout,"- No certificate was sent to peer\n");
    }
    if ((param_3 & 1) != 0) {
      FUN_0010fc00(param_1,param_2,1);
    }
    if (iVar1 - 2U < 2) {
LAB_00110230:
      FUN_0010df10(param_1,"Ephemeral ",param_2);
    }
    else if (iVar1 - 0xcU < 2) {
LAB_0011004a:
      FUN_0010e180(param_1,"Ephemeral ",param_2);
    }
    break;
  case 2:
    if (iVar1 == 0xb) {
      FUN_0010e180(param_1,"Anonymous ",param_2);
      goto switchD_0010fcc9_caseD_0;
    }
    FUN_0010df10();
    break;
  case 3:
    lVar6 = gnutls_srp_server_get_username(param_1);
    if (lVar6 == 0) goto switchD_0010fcc9_caseD_0;
    uVar5 = gnutls_srp_server_get_username(param_1);
    FUN_0010dc90(stdout,"- SRP authentication. Connected as \'%s\'\n",uVar5);
    break;
  case 4:
    lVar6 = gnutls_psk_client_get_hint(param_1);
    if (lVar6 != 0) {
      uVar5 = gnutls_psk_client_get_hint(param_1);
      FUN_0010dc90(stdout,"- PSK authentication. PSK hint \'%s\'\n",uVar5);
    }
    lVar6 = gnutls_psk_server_get_username(param_1);
    if (lVar6 != 0) {
      uVar5 = gnutls_psk_server_get_username(param_1);
      FUN_0010dc90(stdout,"- PSK authentication. Connected as \'%s\'\n",uVar5);
    }
    if (iVar1 == 10) goto LAB_00110230;
    if (iVar1 == 0xe) goto LAB_0011004a;
    break;
  case 5:
    FUN_0010dc90(stdout,"- TLS/IA authentication\n");
  default:
switchD_0010fcc9_caseD_0:
  }
  if (param_2 == 0) goto LAB_0010fd20;
  uVar3 = gnutls_protocol_get_version(param_1);
  pcVar7 = (char *)gnutls_protocol_get_name(uVar3);
  if (pcVar7 == (char *)0x0) {
    pcVar7 = "Unknown";
  }
  FUN_0010dc90(stdout,"- Version: %s\n",pcVar7);
  if (uVar3 < 5) {
    pcVar7 = (char *)gnutls_kx_get_name(iVar1);
    if (pcVar7 == (char *)0x0) {
      pcVar7 = "Unknown";
    }
    FUN_0010dc90(stdout,"- Key Exchange: %s\n",pcVar7);
    iVar1 = gnutls_sign_algorithm_get(param_1);
    if (iVar1 == 0) goto LAB_0010fe56;
LAB_00110197:
    uVar2 = gnutls_sign_algorithm_get(param_1);
    lVar6 = gnutls_sign_get_name(uVar2);
    pcVar7 = "Unknown";
    if (lVar6 != 0) {
      uVar2 = gnutls_sign_algorithm_get(param_1);
      pcVar7 = (char *)gnutls_sign_get_name(uVar2);
    }
    FUN_0010dc90(stdout,"- Server Signature: %s\n",pcVar7);
    iVar1 = gnutls_sign_algorithm_get_client(param_1);
  }
  else {
    iVar1 = gnutls_sign_algorithm_get(param_1);
    if (iVar1 != 0) goto LAB_00110197;
LAB_0010fe56:
    iVar1 = gnutls_sign_algorithm_get_client(param_1);
  }
  if (iVar1 != 0) {
    uVar2 = gnutls_sign_algorithm_get_client(param_1);
    lVar6 = gnutls_sign_get_name(uVar2);
    pcVar7 = "Unknown";
    if (lVar6 != 0) {
      uVar2 = gnutls_sign_algorithm_get_client(param_1);
      pcVar7 = (char *)gnutls_sign_get_name(uVar2);
    }
    FUN_0010dc90(stdout,"- Client Signature: %s\n",pcVar7);
  }
  uVar2 = gnutls_cipher_get(param_1);
  lVar6 = gnutls_cipher_get_name(uVar2);
  pcVar7 = "Unknown";
  if (lVar6 != 0) {
    uVar2 = gnutls_cipher_get(param_1);
    pcVar7 = (char *)gnutls_cipher_get_name(uVar2);
  }
  FUN_0010dc90(stdout,"- Cipher: %s\n",pcVar7);
  uVar2 = gnutls_mac_get(param_1);
  lVar6 = gnutls_mac_get_name(uVar2);
  pcVar7 = "Unknown";
  if (lVar6 != 0) {
    uVar2 = gnutls_mac_get(param_1);
    pcVar7 = (char *)gnutls_mac_get_name(uVar2);
  }
  FUN_0010dc90(stdout,"- MAC: %s\n",pcVar7);
LAB_0010fd20:
  FUN_0010dc90(stdout,"- Options:");
  iVar1 = gnutls_session_ext_master_secret_status(param_1);
  if (iVar1 != 0) {
    FUN_0010dc90(stdout," extended master secret,");
  }
  iVar1 = gnutls_safe_renegotiation_status(param_1);
  if (iVar1 != 0) {
    FUN_0010dc90(stdout," safe renegotiation,");
  }
  iVar1 = gnutls_session_etm_status(param_1);
  if (iVar1 != 0) {
    FUN_0010dc90(stdout," EtM,");
  }
  iVar1 = gnutls_ocsp_status_request_is_checked(param_1,1);
  if (iVar1 != 0) {
    iVar1 = gnutls_ocsp_status_request_is_checked(param_1,0);
    pcVar7 = "";
    if (iVar1 == 0) {
      pcVar7 = "[ignored]";
    }
    FUN_0010dc90(stdout," OCSP status request%s,",pcVar7);
  }
  FUN_0010dc90(stdout,"\n");
  iVar1 = gnutls_srtp_get_selected_profile(param_1,&local_194);
  if (iVar1 == 0) {
    uVar5 = gnutls_srtp_get_profile_name(local_194);
    FUN_0010dc90(stdout,"- SRTP profile: %s\n",uVar5);
  }
  iVar1 = gnutls_alpn_get_selected_protocol(param_1,&local_188);
  if (iVar1 == 0) {
    FUN_0010dc90(stdout,"- Application protocol: %.*s\n",local_180,local_188);
  }
  FUN_0010e200(param_1,param_2);
  fflush(stdout);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



// Function: log_set @ 0x102d0

void log_set(undefined8 param_1)

{
  DAT_00124480 = param_1;
  return;
}



// Function: simple_ctime @ 0x102e0

char * simple_ctime(time_t *param_1,char *param_2)

{
  tm *ptVar1;
  size_t sVar2;
  long in_FS_OFFSET;
  tm tStack_58;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  ptVar1 = localtime_r(param_1,&tStack_58);
  if (ptVar1 != (tm *)0x0) {
    sVar2 = strftime(param_2,0x40,"%c",&tStack_58);
    if (sVar2 != 0) goto LAB_0011032b;
  }
  builtin_strncpy(param_2,"[error]",8);
LAB_0011032b:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: wrap_pull_timeout_func @ 0x10380

void wrap_pull_timeout_func(int *param_1)

{
  gnutls_system_recv_timeout((long)*param_1);
  return;
}



// Function: wrap_pull @ 0x10390

size_t wrap_pull(int *param_1,void *param_2,size_t param_3)

{
  size_t __n;
  
  __n = recv(*param_1,param_2,param_3,0);
  if ((0 < (long)__n) && (*(FILE **)(param_1 + 0x36) != (FILE *)0x0)) {
    fwrite(param_2,1,__n,*(FILE **)(param_1 + 0x36));
  }
  return __n;
}



// Function: wrap_push @ 0x103e0

void wrap_push(int *param_1,void *param_2,size_t param_3)

{
  if (*(FILE **)(param_1 + 0x38) != (FILE *)0x0) {
    fwrite(param_2,1,param_3,*(FILE **)(param_1 + 0x38));
  }
  send(*param_1,param_2,param_3,0);
  return;
}



// Function: socket_starttls @ 0x10720

void socket_starttls(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined *puVar5;
  long in_FS_OFFSET;
  undefined1 auStack_228 [520];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if (((param_1[4] == 0) && (pcVar4 = *(char **)(param_1 + 8), pcVar4 != (char *)0x0)) &&
     (iVar2 = strcasecmp(pcVar4,"https"), iVar2 != 0)) {
    iVar2 = strcasecmp(pcVar4,"smtp");
    if ((iVar2 == 0) || (iVar2 = strcasecmp(pcVar4,"submission"), iVar2 == 0)) {
      if (param_1[0x12] != 0) {
        FUN_0010dc90(stdout,"Negotiating SMTP STARTTLS\n");
      }
      FUN_00110420(param_1,&DAT_00117e84,4);
      uVar3 = *(undefined8 *)(param_1 + 6);
      pcVar4 = "EHLO %s\r\n";
    }
    else {
      iVar2 = strcasecmp(pcVar4,"imap");
      if ((iVar2 == 0) || (iVar2 = strcasecmp(pcVar4,"imap2"), iVar2 == 0)) {
        if (param_1[0x12] != 0) {
          FUN_0010dc90(stdout,"Negotiating IMAP STARTTLS\n");
        }
        FUN_00110690(param_1,"a CAPABILITY\r\n");
        FUN_00110420(param_1,&DAT_00117ecd,4);
        FUN_00110690(param_1,"a STARTTLS\r\n");
        if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00110c0a;
        uVar3 = 4;
        puVar5 = &DAT_00117ecd;
        goto LAB_00110993;
      }
      iVar2 = strcasecmp(pcVar4,"xmpp");
      if (iVar2 == 0) {
        if (param_1[0x12] != 0) {
          FUN_0010dc90(stdout,"Negotiating XMPP STARTTLS\n");
        }
        __snprintf_chk(auStack_228,0x200,1,0x200,
                       "<stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\' xmlns=\'jabber:client\' to=\'%s\' version=\'1.0\'>\n"
                       ,*(undefined8 *)(param_1 + 6));
        FUN_00110690(param_1,auStack_228);
        FUN_00110420(param_1,&DAT_00117eff,2);
        FUN_00110690(param_1,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'/>");
        FUN_00110420(param_1,"<proceed",8);
        goto LAB_00110860;
      }
      iVar2 = strcasecmp(pcVar4,"ldap");
      if (iVar2 == 0) {
        if (param_1[0x12] != 0) {
          FUN_0010dc90(stdout,"Negotiating LDAP STARTTLS\n");
        }
        send(*param_1,&DAT_00117ca8,0x1f,0);
        if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00110c0a;
LAB_00110a1b:
        uVar3 = 0;
        puVar5 = (undefined *)0x0;
LAB_00110993:
        FUN_00110420(param_1,puVar5,uVar3);
        return;
      }
      iVar2 = strcasecmp(pcVar4,"ftp");
      if ((iVar2 == 0) || (iVar2 = strcasecmp(pcVar4,"ftps"), iVar2 == 0)) {
        if (param_1[0x12] != 0) {
          FUN_0010dc90(stdout,"Negotiating FTP STARTTLS\n");
        }
        FUN_00110690(param_1,"FEAT\r\n");
        FUN_00110420(param_1,&DAT_00117f55,4);
        FUN_00110690(param_1,"AUTH TLS\r\n");
        if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
          uVar3 = 3;
          puVar5 = &DAT_00117f65;
          goto LAB_00110993;
        }
        goto LAB_00110c0a;
      }
      iVar2 = strcasecmp(pcVar4,"lmtp");
      if (iVar2 != 0) {
        iVar2 = strcasecmp(pcVar4,"pop3");
        if (iVar2 == 0) {
          if (param_1[0x12] != 0) {
            FUN_0010dc90(stdout,"Negotiating POP3 STARTTLS\n");
          }
          puVar5 = &DAT_00117fb3;
          FUN_00110420(param_1,&DAT_00117fb3,3);
          FUN_00110690(param_1,"STLS\r\n");
          if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00110c0a;
        }
        else {
          iVar2 = strcasecmp(pcVar4,"nntp");
          if (iVar2 == 0) {
            if (param_1[0x12] != 0) {
              FUN_0010dc90(stdout,"Negotiating NNTP STARTTLS\n");
            }
            FUN_00110420(param_1,&DAT_00117fde,4);
            FUN_00110690(param_1,"STARTTLS\r\n");
            uVar3 = 4;
            puVar5 = &DAT_00117fe3;
            if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00110993;
            goto LAB_00110c0a;
          }
          iVar2 = strcasecmp(pcVar4,"sieve");
          if (iVar2 != 0) {
            iVar2 = strcasecmp(pcVar4,"postgres");
            if ((iVar2 != 0) && (iVar2 = strcasecmp(pcVar4,"postgresql"), iVar2 != 0)) {
              cVar1 = FUN_00115730((int)*pcVar4);
              if ((cVar1 == '\0') && (DAT_00124488 == 0)) {
                __fprintf_chk(stderr,1,"unknown protocol \'%s\'\n",pcVar4);
                DAT_00124488 = 1;
              }
              goto LAB_00110860;
            }
            if (param_1[0x12] != 0) {
              FUN_0010dc90(stdout,"Negotiating PostgreSQL STARTTLS\n");
            }
            send(*param_1,&DAT_00118139,8,0);
            if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00110c0a;
            goto LAB_00110a1b;
          }
          if (param_1[0x12] != 0) {
            FUN_0010dc90(stdout,"Negotiating Sieve STARTTLS\n");
          }
          puVar5 = &DAT_0011800a;
          FUN_00110420(param_1,&DAT_0011800a,3);
          FUN_00110690(param_1,"STARTTLS\r\n");
          if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) goto LAB_00110c0a;
        }
        uVar3 = 3;
        goto LAB_00110993;
      }
      if (param_1[0x12] != 0) {
        FUN_0010dc90(stdout,"Negotiating LMTP STARTTLS\n");
      }
      FUN_00110420(param_1,&DAT_00117e84,4);
      uVar3 = *(undefined8 *)(param_1 + 6);
      pcVar4 = "LHLO %s\r\n";
    }
    __snprintf_chk(auStack_228,0x200,1,0x200,pcVar4,uVar3);
    FUN_00110690(param_1,auStack_228);
    FUN_00110420(param_1,&DAT_00117e93,4);
    FUN_00110690(param_1,"STARTTLS\r\n");
    FUN_00110420(param_1,&DAT_00117e84,4);
  }
LAB_00110860:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_00110c0a:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: socket_recv @ 0x10d90

long socket_recv(int *param_1,void *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  ssize_t sVar3;
  
  if (param_1[4] == 0) {
    while( true ) {
      sVar3 = recv(*param_1,param_2,(long)param_3,0);
      iVar1 = (int)sVar3;
      if (iVar1 != -1) break;
      piVar2 = __errno_location();
      if (*piVar2 != 4) {
        return -1;
      }
    }
  }
  else {
    do {
      while (iVar1 = gnutls_record_recv(*(undefined8 *)(param_1 + 2),param_2,(long)param_3),
            iVar1 == -0x125) {
        gnutls_heartbeat_pong(*(undefined8 *)(param_1 + 2),0);
      }
    } while (iVar1 == -0x34);
  }
  return (long)iVar1;
}



// Function: socket_recv_timeout @ 0x10e20

long socket_recv_timeout(long param_1,undefined8 param_2,ulong param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    gnutls_record_set_timeout(*(undefined8 *)(param_1 + 8),param_4);
    param_3 = param_3 & 0xffffffff;
  }
  iVar1 = FUN_00110d90(param_1,param_2,param_3);
  if (*(int *)(param_1 + 0x10) == 0) {
    return (long)iVar1;
  }
  gnutls_record_set_timeout(*(undefined8 *)(param_1 + 8),0);
  return (long)iVar1;
}



// Function: socket_send_range @ 0x10e90

long socket_send_range(int *param_1,void *param_2,int param_3,long param_4)

{
  uint uVar1;
  int *piVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  size_t __n;
  
  __n = (size_t)param_3;
  if (param_1[4] == 0) {
    while( true ) {
      uVar3 = send(*param_1,param_2,__n,0);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 != -1) break;
      piVar2 = __errno_location();
      if (*piVar2 != 4) {
        return -1;
      }
    }
  }
  else {
    do {
      if (param_4 == 0) {
        uVar1 = gnutls_record_send(*(undefined8 *)(param_1 + 2),param_2,__n);
      }
      else {
        uVar1 = gnutls_record_send_range(*(undefined8 *)(param_1 + 2),param_2,__n,param_4);
      }
      uVar5 = (ulong)uVar1;
    } while ((uVar1 == 0xffffffe4) || (uVar1 == 0xffffffcc));
  }
  iVar4 = (int)uVar5;
  if ((0 < iVar4) && ((iVar4 != param_3 && (param_1[0x12] != 0)))) {
    __fprintf_chk(stderr,1,"*** Only sent %d bytes instead of %d.\n",uVar5,param_3);
    return (long)iVar4;
  }
  return (long)iVar4;
}



// Function: socket_send @ 0x10f90

void socket_send(void)

{
  FUN_00110e90();
  return;
}



// Function: starttls_proto_to_port @ 0x10fa0

undefined2 starttls_proto_to_port(char *param_1)

{
  undefined2 uVar1;
  int iVar2;
  servent *psVar3;
  
  iVar2 = strcasecmp(param_1,"xmpp");
  if (iVar2 == 0) {
    param_1 = "xmpp-server";
  }
  psVar3 = getservbyname(param_1,(char *)0x0);
  if (psVar3 != (servent *)0x0) {
    uVar1 = FUN_00110370((short)psVar3->s_port);
    return uVar1;
  }
  endservent();
  return 0x1bb;
}



// Function: starttls_proto_to_service @ 0x10ff0

char * starttls_proto_to_service(char *param_1)

{
  int iVar1;
  servent *psVar2;
  
  iVar1 = strcasecmp(param_1,"xmpp");
  if (iVar1 == 0) {
    param_1 = "xmpp-server";
  }
  psVar2 = getservbyname(param_1,(char *)0x0);
  if (psVar2 != (servent *)0x0) {
    return psVar2->s_name;
  }
  endservent();
  return "443";
}



// Function: socket_bye @ 0x11040

void socket_bye(int *param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 2);
  if ((param_1[4] != 0) && (param_2 != 0)) {
    if (lVar3 == 0) goto LAB_001110ad;
    iVar1 = gnutls_bye(lVar3,1);
    if (iVar1 != -0x34) goto LAB_00111083;
    do {
      do {
        iVar1 = gnutls_bye(*(undefined8 *)(param_1 + 2),1);
      } while (iVar1 == -0x34);
LAB_00111083:
    } while (iVar1 == -0x1c);
    if ((param_1[0x12] != 0) && (iVar1 < 0)) {
      uVar2 = gnutls_strerror(iVar1);
      __fprintf_chk(stderr,1,"*** gnutls_bye() error: %s\n",uVar2);
    }
    lVar3 = *(long *)(param_1 + 2);
  }
  if (lVar3 != 0) {
    gnutls_deinit();
    param_1[2] = 0;
    param_1[3] = 0;
  }
LAB_001110ad:
  freeaddrinfo(*(addrinfo **)(param_1 + 0x10));
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x34] = 0;
  free(*(void **)(param_1 + 10));
  free(*(void **)(param_1 + 6));
  free(*(void **)(param_1 + 0xc));
  shutdown(*param_1,2);
  close(*param_1);
  (*gnutls_free)(*(undefined8 *)(param_1 + 0x3a));
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  if (*(FILE **)(param_1 + 0x36) != (FILE *)0x0) {
    fclose(*(FILE **)(param_1 + 0x36));
  }
  if (*(FILE **)(param_1 + 0x38) != (FILE *)0x0) {
    fclose(*(FILE **)(param_1 + 0x38));
  }
  *param_1 = -1;
  param_1[4] = 0;
  return;
}



// Function: canonicalize_host @ 0x11180

void canonicalize_host(char *param_1,char *param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long in_FS_OFFSET;
  undefined1 auStack_78 [72];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar2 = strchr(param_1,0x3a);
  if (pcVar2 == (char *)0x0) {
    sVar3 = strlen(param_1);
    pcVar2 = param_1 + sVar3;
  }
  else {
    iVar1 = inet_pton(10,param_1,auStack_78);
    if (iVar1 == 1) goto LAB_001111eb;
    *pcVar2 = '\0';
    if ((param_2 != (char *)0x0) && (param_3 != 0)) {
      snprintf(param_2,(ulong)param_3,"%s",pcVar2 + 1);
    }
  }
  if ((param_1 < pcVar2) && (pcVar2[-1] == '.')) {
    pcVar2[-1] = '\0';
  }
LAB_001111eb:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



// Function: socket_open2 @ 0x11250

void socket_open2(int *param_1,char *param_2,char *param_3,undefined8 param_4,uint param_5,
                 long param_6,undefined8 *param_7,undefined8 *param_8,long param_9,long param_10)

{
  int iVar1;
  int __fd;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  long lVar6;
  int *piVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  addrinfo *paVar11;
  long in_FS_OFFSET;
  uint local_10c4;
  undefined4 local_10a4;
  addrinfo *local_10a0;
  char *local_1098 [2];
  undefined1 local_1088 [16];
  undefined1 local_1078 [16];
  undefined1 local_1068 [16];
  undefined1 local_1058 [16];
  char local_1048 [4104];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_1058 = (undefined1  [16])0x0;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  puVar10 = (undefined8 *)((ulong)(param_1 + 2) & 0xfffffffffffffff8);
  for (uVar9 = (ulong)(((int)param_1 -
                       (int)(undefined8 *)((ulong)(param_1 + 2) & 0xfffffffffffffff8)) + 0x108U >> 3
                      ); uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  if ((param_5 & 0x10) != 0) {
    param_1[0x12] = 1;
  }
  if (param_7 != (undefined8 *)0x0) {
    *(undefined8 *)(param_1 + 0x3a) = *param_7;
    param_1[0x3c] = *(int *)(param_7 + 1);
  }
  if (param_8 != (undefined8 *)0x0) {
    *(undefined8 *)(param_1 + 0x3e) = *param_8;
    param_1[0x40] = *(int *)(param_8 + 1);
  }
  sVar3 = strlen(param_2);
  iVar1 = gnutls_idna_map(param_2,sVar3 & 0xffffffff,local_1098,0);
  if (iVar1 < 0) {
    uVar8 = gnutls_strerror(iVar1);
    __fprintf_chk(stderr,1,"Cannot convert %s to IDNA: %s\n",param_2,uVar8);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  pcVar4 = strdup(param_2);
  pcVar5 = local_1098[0];
  *(char **)(param_1 + 6) = pcVar4;
  if (param_6 != 0) {
    FUN_0010dc90(stdout,"Resolving \'%s:%s\'...\n",local_1098[0],param_3);
  }
  local_1078 = (undefined1  [16])0x0;
  local_1088 = ZEXT416((param_5 & 1) + 1) << 0x40;
  local_1068 = (undefined1  [16])0x0;
  iVar1 = getaddrinfo(pcVar5,param_3,(addrinfo *)local_1088,&local_10a0);
  if (iVar1 != 0) {
    pcVar5 = gai_strerror(iVar1);
    pcVar4 = "Cannot resolve %s:%s: %s\n";
LAB_00111875:
    __fprintf_chk(stderr,1,pcVar4,param_2,param_3,pcVar5);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar1 = 0;
  paVar11 = local_10a0;
  if (local_10a0 != (addrinfo *)0x0) {
    do {
      while (__fd = socket(paVar11->ai_family,paVar11->ai_socktype,paVar11->ai_protocol), __fd == -1
            ) {
LAB_0011167b:
        paVar11 = paVar11->ai_next;
        if (paVar11 == (addrinfo *)0x0) goto LAB_00111689;
      }
      iVar1 = getnameinfo(paVar11->ai_addr,paVar11->ai_addrlen,local_1048,0x1000,local_1058,0x10,3);
      if (iVar1 != 0) {
        pcVar5 = gai_strerror(iVar1);
        __fprintf_chk(stderr,1,"getnameinfo(): %s\n",pcVar5);
        close(__fd);
        goto LAB_0011167b;
      }
      if (local_1088._8_4_ == 2) {
        local_10a4 = 2;
        iVar1 = setsockopt(__fd,0,10,&local_10a4,4);
        if (iVar1 < 0) {
          perror("setsockopt(IP_DF) failed");
        }
      }
      if ((((param_5 & 2) != 0) && (paVar11->ai_socktype == 1)) &&
         ((paVar11->ai_family & 0xfffffff7U) == 2)) {
        memcpy(param_1 + 0x14,paVar11->ai_addr,(ulong)paVar11->ai_addrlen);
        param_1[0x34] = paVar11->ai_addrlen;
        iVar1 = 0;
        if (param_6 != 0) {
          FUN_0010dc90(stdout,"%s \'%s:%s\' (TFO)...\n",param_6,local_1048,local_1058);
        }
LAB_001114bf:
        *param_1 = __fd;
        if ((param_5 & 4) != 0) {
          *(undefined8 *)(param_1 + 8) = param_4;
          FUN_00110720(param_1);
          param_1[8] = 0;
          param_1[9] = 0;
        }
        if ((param_5 & 0x20) == 0) {
          lVar6 = FUN_0010cd30(param_2);
          *(long *)(param_1 + 2) = lVar6;
          if (lVar6 != 0) goto LAB_001114e4;
          pcVar5 = "error initializing session\n";
LAB_00111751:
          __fprintf_chk(stderr,1,pcVar5);
LAB_00111764:
          close(__fd);
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        lVar6 = *(long *)(param_1 + 2);
        if (lVar6 != 0) {
LAB_001114e4:
          if ((*(long *)(param_1 + 0x3e) != 0) &&
             (iVar2 = gnutls_record_send_early_data(lVar6,*(long *)(param_1 + 0x3e),param_1[0x40]),
             iVar2 < 0)) {
            pcVar5 = "error sending early data\n";
            goto LAB_00111751;
          }
          if (*(long *)(param_1 + 0x3a) != 0) {
            gnutls_session_set_data
                      (*(undefined8 *)(param_1 + 2),*(long *)(param_1 + 0x3a),param_1[0x3c]);
          }
          if (param_10 == 0 && param_9 == 0) {
            gnutls_transport_set_int2(*(undefined8 *)(param_1 + 2),*param_1,*param_1);
          }
          else {
            *(long *)(param_1 + 0x36) = param_9;
            *(long *)(param_1 + 0x38) = param_10;
            gnutls_transport_set_push_function(*(undefined8 *)(param_1 + 2),FUN_001103e0);
            gnutls_transport_set_pull_function(*(undefined8 *)(param_1 + 2),FUN_00110390);
            gnutls_transport_set_pull_timeout_function(*(undefined8 *)(param_1 + 2),FUN_00110380);
            gnutls_transport_set_ptr(*(undefined8 *)(param_1 + 2),param_1);
          }
        }
        if ((param_5 & 0x28) == 0) {
          iVar1 = FUN_0010d200(param_1);
          if (iVar1 == -0x35) {
            gnutls_deinit(*(undefined8 *)(param_1 + 2));
            param_1[2] = 0;
            param_1[3] = 0;
            iVar1 = -0x35;
            goto LAB_001117b1;
          }
          if (iVar1 < 0) {
            if ((param_5 & 0x40) == 0) {
              uVar8 = gnutls_strerror(iVar1);
              __fprintf_chk(stderr,1,"*** handshake has failed: %s\n",uVar8);
            }
            goto LAB_00111764;
          }
        }
        if (iVar1 != 0) goto LAB_00111859;
        goto LAB_001115b0;
      }
      if (param_6 != 0) {
        FUN_0010dc90(stdout,"%s \'%s:%s\'...\n",param_6,local_1048,local_1058);
      }
      iVar1 = connect(__fd,paVar11->ai_addr,paVar11->ai_addrlen);
      if (-1 < iVar1) goto LAB_001114bf;
LAB_001117b1:
      close(__fd);
      paVar11 = paVar11->ai_next;
    } while (paVar11 != (addrinfo *)0x0);
LAB_00111689:
    if (iVar1 != 0) {
LAB_00111859:
      param_2 = local_1048;
      param_3 = local_1058;
      piVar7 = __errno_location();
      pcVar5 = strerror(*piVar7);
      pcVar4 = "Could not connect to %s:%s: %s\n";
      goto LAB_00111875;
    }
    if (__fd != -1) {
LAB_001115b0:
      local_10c4 = param_5 & 0x28;
      *param_1 = __fd;
      param_1[4] = (uint)(local_10c4 == 0);
      pcVar5 = strdup(local_1048);
      *(char **)(param_1 + 10) = pcVar5;
      pcVar5 = strdup(local_1058);
      *(addrinfo **)(param_1 + 0xe) = paVar11;
      *(char **)(param_1 + 0xc) = pcVar5;
      *(addrinfo **)(param_1 + 0x10) = local_10a0;
      (*gnutls_free)(*(undefined8 *)(param_1 + 0x3a));
      param_1[0x3a] = 0;
      param_1[0x3b] = 0;
      (*gnutls_free)(*(undefined8 *)(param_1 + 0x3e));
      param_1[0x3e] = 0;
      param_1[0x3f] = 0;
      (*gnutls_free)(local_1098[0]);
      if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
  __fprintf_chk(stderr,1,"Could not find a supported socket\n");
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: port_to_service @ 0x11920

char * port_to_service(char *param_1,char *param_2)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  servent *psVar4;
  
  cVar1 = FUN_00115730((int)*param_1);
  if (cVar1 != '\0') {
    uVar3 = atoi(param_1);
    if (uVar3 != 0) {
      uVar2 = FUN_00110370(uVar3 & 0xffff);
      psVar4 = getservbyport((uint)uVar2,param_2);
      if (psVar4 != (servent *)0x0) {
        return psVar4->s_name;
      }
      __fprintf_chk(stderr,1,"Warning: getservbyport(%s) failed. Using port number as service.\n",
                    param_1);
    }
  }
  return param_1;
}



// Function: service_to_port @ 0x119a0

uint service_to_port(char *param_1,char *param_2)

{
  ushort uVar1;
  uint uVar2;
  servent *psVar3;
  
  uVar2 = atoi(param_1);
  if (uVar2 != 0) {
    return uVar2;
  }
  psVar3 = getservbyname(param_1,param_2);
  if (psVar3 != (servent *)0x0) {
    uVar1 = FUN_00110370((short)psVar3->s_port);
    return (uint)uVar1;
  }
  __fprintf_chk(stderr,1,"Warning: getservbyname() failed for \'%s/%s\'.\n",param_1,param_2);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: force_memcpy @ 0x11a50

void force_memcpy(char *param_1,char *param_2,size_t param_3)

{
  if (param_3 != 0) {
    do {
      param_1 = memcpy(param_1,param_2,param_3);
    } while (*param_1 != *param_2);
  }
  return;
}



// Function: benchmark_cipher @ 0x12480

void benchmark_cipher(undefined4 param_1)

{
  long lVar1;
  
  gnutls_global_set_log_function(FUN_00111a20);
  gnutls_global_set_log_level(param_1);
  lVar1 = sysconf(0x1e);
  DAT_001200a0 = (undefined4)lVar1;
  __printf_chk(1,"Checking AEAD ciphers, payload size: %u\n",0x4000);
  FUN_00111c70(10,1);
  FUN_00111c70(0x13,1);
  FUN_00111c70(0x17,1);
  __printf_chk(1,"\nChecking cipher-MAC combinations, payload size: %u\n",0x4000);
  FUN_00112150(0xd,3);
  FUN_00112150(4,3);
  FUN_00112150(4,6);
  FUN_00112150(0x22,0xd0);
  __printf_chk(1,"\nChecking MAC algorithms, payload size: %u\n",0x4000);
  FUN_00111aa0(3);
  FUN_00111aa0(6);
  FUN_00111aa0(8);
  FUN_00111aa0(0xd0);
  FUN_00111aa0(0xf);
  FUN_00111aa0(0x11);
  __printf_chk(1,"\nChecking ciphers, payload size: %u\n",0x4000);
  FUN_00111c70(3,0);
  FUN_00111c70(4,0);
  FUN_00111c70(0x20,0);
  FUN_00111c70(0x21,0);
  FUN_00111c70(0xd,0);
  FUN_00111c70(1,1);
  FUN_00111c70(0x22,0);
  gnutls_global_deinit();
  return;
}



// Function: alarm_handler @ 0x12610

void alarm_handler(void)

{
  DAT_0012448c = 1;
  return;
}



// Function: value2human @ 0x12620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void value2human(double param_1,ulong param_2,double *param_3,double *param_4,undefined4 *param_5)

{
  double dVar1;
  
  if (param_2 - 0x3e9 < 0xf3e57) {
    dVar1 = (double)(long)param_2 / DAT_001183b8;
    *param_3 = dVar1;
    *param_4 = dVar1 / param_1;
    *(undefined2 *)param_5 = 0x424b;
    *(undefined1 *)((long)param_5 + 2) = 0;
    return;
  }
  if (998999999 < param_2 - 1000000) {
    if (999999999 < param_2) {
      dVar1 = (double)param_2 / _DAT_001183c8;
      *param_3 = dVar1;
      *param_4 = dVar1 / param_1;
      *(undefined2 *)param_5 = 0x4247;
      *(undefined1 *)((long)param_5 + 2) = 0;
      return;
    }
    *param_3 = (double)(long)param_2;
    *param_4 = (double)(long)param_2 / param_1;
    *param_5 = 0x65747962;
    *(undefined2 *)(param_5 + 1) = 0x73;
    return;
  }
  dVar1 = (double)(long)param_2 / DAT_001183c0;
  *param_3 = dVar1;
  *param_4 = dVar1 / param_1;
  *(undefined2 *)param_5 = 0x424d;
  *(undefined1 *)((long)param_5 + 2) = 0;
  return;
}



// Function: start_benchmark @ 0x12770

void start_benchmark(timespec *param_1)

{
  __sighandler_t p_Var1;
  
  param_1->tv_sec = 0;
  param_1->tv_nsec = 0;
  param_1[1].tv_sec = 0;
  param_1[1].tv_nsec = 0;
  p_Var1 = signal(0xe,FUN_00112610);
  param_1[1].tv_nsec = (long)p_Var1;
  clock_gettime(2,param_1);
  DAT_0012448c = 0;
  alarm(5);
  return;
}



// Function: stop_benchmark @ 0x127c0

double stop_benchmark(undefined8 *param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  long in_FS_OFFSET;
  double dVar2;
  undefined1 local_58 [8];
  undefined8 local_50;
  timespec local_48;
  undefined1 local_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  signal(0xe,(__sighandler_t)param_1[3]);
  clock_gettime(2,&local_48);
  uVar1 = FUN_00112740(local_48.tv_sec,local_48.tv_nsec,*param_1,param_1[1]);
  dVar2 = (double)uVar1 / DAT_001183b8;
  if (param_2 == (undefined1 *)0x0) {
    param_2 = local_38;
    FUN_00112620(dVar2,param_1[2],&local_50,local_58,param_2);
    if (param_3 == 0) {
      __printf_chk(local_50,1,"  Processed %.2f %s in %.2f secs: ",param_2);
    }
  }
  else if (param_3 == 0) {
    __printf_chk(1,"  Processed %.2f %s in %.2f secs: ",param_2);
  }
  __printf_chk(1,"%.2f %s/sec\n",param_2);
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return dVar2;
}



// Function: test_ciphersuite @ 0x129c0

void test_ciphersuite(undefined8 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char *pcVar7;
  uint uVar8;
  long in_FS_OFFSET;
  bool bVar9;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 local_58 [16];
  long local_48;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  gnutls_anon_allocate_server_credentials(&local_98);
  gnutls_certificate_allocate_credentials(&local_88);
  gnutls_certificate_set_x509_key_mem(local_88,&PTR_DAT_0011e9f0,&PTR_DAT_0011e9d0,1);
  gnutls_certificate_set_x509_key_mem
            (local_88,&PTR_s______BEGIN_CERTIFICATE______MIIB_0011e9c0,
             &PTR_s______BEGIN_EC_PRIVATE_KEY______M_0011e9b0,1);
  gnutls_certificate_set_x509_key_mem
            (local_88,&PTR_s______BEGIN_CERTIFICATE______MIIC_0011ea00,
             &PTR_s______BEGIN_PRIVATE_KEY______MEgC_0011ea10,1);
  gnutls_init(&local_80,1);
  iVar1 = gnutls_priority_set_direct(local_80,param_1,&local_78);
  if (-1 < iVar1) {
    gnutls_credentials_set(local_80,2,local_98);
    gnutls_credentials_set(local_80,1,local_88);
    gnutls_transport_set_push_function(local_80,FUN_00112ed0);
    gnutls_transport_set_pull_function(local_80,FUN_00112fa0);
    gnutls_transport_set_ptr(local_80,local_80);
    FUN_00112970(&local_70);
    gnutls_anon_allocate_client_credentials();
    gnutls_certificate_allocate_credentials(&local_90);
    gnutls_init(&local_68,2);
    iVar1 = gnutls_priority_set_direct(local_68,param_1,&local_78);
    if (-1 < iVar1) {
      gnutls_credentials_set(local_68,2,local_70);
      gnutls_credentials_set(local_68,1,local_90);
      gnutls_transport_set_push_function(local_68,FUN_00112e80);
      gnutls_transport_set_pull_function(local_68,FUN_00112f20);
      gnutls_transport_set_ptr(local_68,local_68);
LAB_00112b72:
      iVar1 = -0x1c;
      do {
        PTR_DAT_00122298 = s_client_001183e9;
        uVar2 = gnutls_handshake(local_68);
        if (uVar2 == 0xffffffcc) {
          if (iVar1 == -0x1c) {
            PTR_DAT_00122298 = "server";
            uVar3 = gnutls_handshake(local_80);
            if (uVar3 == 0xffffffcc) goto LAB_00112b72;
LAB_00112bce:
            if (uVar3 == 0xffffffe4) goto LAB_00112b72;
            if (uVar3 != 0) {
              uVar8 = 0xffffffe4;
              goto LAB_00112bdf;
            }
          }
        }
        else {
          if (iVar1 == -0x1c) {
            PTR_DAT_00122298 = "server";
            uVar3 = gnutls_handshake(local_80);
            if (uVar3 != 0xffffffcc) {
              if (uVar2 == 0xffffffe4) goto LAB_00112bce;
              bVar9 = uVar2 == 0 && uVar3 == 0xffffffe4;
              goto LAB_00112e2f;
            }
            if (uVar2 != 0xffffffe4) goto LAB_00112e70;
            goto LAB_00112b72;
          }
          if (uVar2 != 0xffffffe4) {
            uVar3 = 0;
            uVar8 = uVar2;
            goto LAB_00112c43;
          }
        }
        iVar1 = 0;
      } while( true );
    }
  }
LAB_00112d96:
  pcVar7 = "Error in %s\n";
LAB_00112da2:
  __fprintf_chk(stderr,1,pcVar7,local_78);
                    /* WARNING: Subroutine does not return */
  exit(1);
LAB_00112e2f:
  uVar8 = uVar2;
  if (!bVar9) goto LAB_00112e59;
  while( true ) {
    PTR_DAT_00122298 = "server";
    uVar2 = 0;
    uVar3 = gnutls_handshake(local_80);
    if (uVar3 == 0xffffffcc) break;
    uVar8 = uVar2;
    if (uVar3 != 0xffffffe4) goto LAB_00112e59;
  }
LAB_00112e70:
  bVar9 = uVar2 == 0;
  uVar3 = 0xffffffe4;
  goto LAB_00112e2f;
LAB_00112e59:
  uVar2 = uVar3 | uVar8;
LAB_00112c43:
  if (uVar2 == 0) {
    uVar4 = gnutls_cipher_get(local_80);
    uVar5 = gnutls_cipher_get_name(uVar4);
    uVar4 = gnutls_protocol_get_version(local_80);
    uVar6 = gnutls_protocol_get_name(uVar4);
    __fprintf_chk(stdout,1,"%30s - %s  ",uVar5,uVar6);
    fflush(stdout);
    iVar1 = gnutls_rnd(0,&DAT_001644c0,0x10000);
    if (iVar1 < 0) goto LAB_00112d96;
    FUN_00112770(local_58);
    while( true ) {
      do {
        iVar1 = gnutls_record_send(local_68,&DAT_001644c0,(long)param_2);
      } while (iVar1 == -0x1c);
      if (iVar1 < 0) break;
      do {
        iVar1 = gnutls_record_recv_packet(local_80,&local_60);
      } while (iVar1 == -0x1c);
      if (iVar1 < 0) {
        local_78 = gnutls_strerror(iVar1);
        pcVar7 = "Failed receiving from client: %s\n";
        goto LAB_00112da2;
      }
      local_48 = local_48 + param_2;
      gnutls_packet_deinit(local_60);
      if (DAT_0012448c != 0) {
        FUN_001127c0(local_58,0,1);
        gnutls_bye(local_68,1);
        gnutls_bye(local_80,1);
        gnutls_deinit(local_68);
        gnutls_deinit(local_80);
        gnutls_anon_free_client_credentials(local_70);
        gnutls_anon_free_server_credentials(local_98);
        if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
    }
    pcVar7 = "Failed sending to server\n";
  }
  else {
LAB_00112bdf:
    uVar5 = gnutls_strerror(uVar8);
    __fprintf_chk(stderr,1,"client[%d]: %s\n",uVar8,uVar5);
    uVar5 = gnutls_strerror(uVar3);
    __fprintf_chk(stderr,1,"server[%d]: %s\n",uVar3,uVar5);
    pcVar7 = "Handshake failed\n";
  }
  __fprintf_chk(stderr,1,pcVar7);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: test_ciphersuite_kx @ 0x13160

void test_ciphersuite_kx(undefined8 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong *puVar7;
  ulong *puVar8;
  ulong uVar9;
  char *pcVar10;
  long in_FS_OFFSET;
  bool bVar11;
  double dVar12;
  double dVar13;
  long local_e0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  timespec local_88;
  timespec local_78;
  undefined1 local_68 [16];
  long local_58;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  DAT_001244a0 = 0;
  gnutls_certificate_allocate_credentials(&local_a0);
  gnutls_anon_allocate_server_credentials(&local_c8);
  if (param_2 == 6) {
    iVar1 = gnutls_certificate_set_x509_key_mem(local_a0,&PTR_DAT_0011e9e0,&PTR_DAT_0011e9d0,1);
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 4) {
        iVar1 = gnutls_certificate_set_x509_key_mem
                          (local_a0,&PTR_s______BEGIN_CERTIFICATE______MIIB_0011e9c0,
                           &PTR_s______BEGIN_EC_PRIVATE_KEY______M_0011e9b0,1);
      }
      else if (param_2 == 7) {
        iVar1 = gnutls_certificate_set_x509_key_mem
                          (local_a0,&PTR_s______BEGIN_CERTIFICATE______MIIB_0011e9a0,
                           &PTR_s______BEGIN_PRIVATE_KEY______MC4C_0011e990,1);
      }
      else {
        if (param_2 != 9) goto LAB_00113210;
        iVar1 = gnutls_certificate_set_x509_key_mem
                          (local_a0,&PTR_s______BEGIN_CERTIFICATE______MIIC_0011ea00,
                           &PTR_s______BEGIN_PRIVATE_KEY______MEgC_0011ea10,1);
      }
      if (iVar1 < 0) {
        uVar4 = gnutls_strerror(iVar1);
        uVar6 = 0x1f0;
        goto LAB_0011379a;
      }
      goto LAB_00113210;
    }
    iVar1 = gnutls_certificate_set_x509_key_mem(local_a0,&PTR_DAT_0011e9f0,&PTR_DAT_0011e9d0,1);
  }
  if (iVar1 < 0) {
    uVar4 = gnutls_strerror();
    uVar6 = 0x1db;
LAB_0011379a:
    __fprintf_chk(stderr,1,"Error in %d: %s\n",uVar6,uVar4);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
LAB_00113210:
  gnutls_anon_allocate_client_credentials(&local_b0);
  gnutls_certificate_allocate_credentials(&local_a8);
  FUN_00112770(local_68);
  iVar1 = gnutls_priority_init(&local_90,param_1,&local_b8);
  if (iVar1 < 0) {
    pcVar10 = "Error in %s\n";
LAB_00113764:
    __fprintf_chk(stderr,1,pcVar10,local_b8);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  local_e0 = 0;
LAB_00113280:
  gnutls_init(&local_c0,1);
  iVar1 = gnutls_priority_set(local_c0,local_90);
  if (-1 < iVar1) {
    gnutls_credentials_set(local_c0,2,local_c8);
    gnutls_credentials_set(local_c0,1,local_a0);
    gnutls_transport_set_push_function(local_c0,FUN_00112ed0);
    gnutls_transport_set_pull_function(local_c0,FUN_00112fa0);
    gnutls_transport_set_ptr(local_c0,local_c0);
    FUN_00112970(&local_98,2);
    gnutls_init();
    iVar1 = gnutls_priority_set(local_98,local_90);
    if (-1 < iVar1) {
      gnutls_credentials_set(local_98,2,local_b0);
      gnutls_credentials_set(local_98,1,local_a8);
      gnutls_transport_set_push_function(local_98,FUN_00112e80);
      gnutls_transport_set_pull_function(local_98,FUN_00112f20);
      gnutls_transport_set_ptr(local_98,local_98);
      clock_gettime(2,&local_88);
LAB_0011338b:
      iVar1 = -0x1c;
      do {
        PTR_DAT_00122298 = s_client_001183e9;
        uVar2 = gnutls_handshake(local_98);
        if (uVar2 == 0xffffffcc) {
          if (iVar1 == -0x1c) {
            PTR_DAT_00122298 = "server";
            uVar3 = gnutls_handshake(local_c0);
            if (uVar3 == 0xffffffcc) goto LAB_0011338b;
LAB_001133e5:
            if (uVar3 == 0xffffffe4) goto LAB_0011338b;
            if (uVar3 != 0) {
              uVar2 = 0xffffffe4;
              goto LAB_001133f5;
            }
          }
        }
        else {
          uVar5 = uVar2;
          if (iVar1 == -0x1c) {
            PTR_DAT_00122298 = "server";
            uVar3 = gnutls_handshake(local_c0);
            if (uVar3 != 0xffffffcc) {
              if (uVar2 == 0xffffffe4) goto LAB_001133e5;
              bVar11 = uVar2 == 0;
              if (uVar3 == 0xffffffe4) goto LAB_00113808;
              goto LAB_00113832;
            }
            if (uVar2 != 0xffffffe4) {
              if (uVar2 == 0) goto LAB_0011380c;
              uVar3 = 0xffffffe4;
              goto LAB_001133f5;
            }
            goto LAB_0011338b;
          }
          if (uVar2 != 0xffffffe4) {
            uVar3 = 0;
            goto LAB_00113483;
          }
        }
        iVar1 = 0;
      } while( true );
    }
  }
  local_b8 = gnutls_strerror(iVar1);
  pcVar10 = "Error in setting priority: %s\n";
  goto LAB_00113764;
LAB_0011380c:
  while( true ) {
    do {
      PTR_DAT_00122298 = "server";
      uVar3 = gnutls_handshake(local_c0);
    } while (uVar3 == 0xffffffcc);
    bVar11 = true;
    uVar2 = 0;
    uVar5 = uVar2;
    if (uVar3 != 0xffffffe4) break;
LAB_00113808:
    uVar5 = uVar2;
    if (!bVar11) break;
  }
LAB_00113832:
  uVar2 = uVar3 | uVar5;
LAB_00113483:
  bVar11 = uVar2 != 0;
  uVar2 = uVar5;
  if (bVar11) {
LAB_001133f5:
    uVar4 = gnutls_strerror(uVar2);
    __fprintf_chk(stderr,1,"client[%d]: %s\n",uVar2,uVar4);
    uVar4 = gnutls_strerror(uVar3);
    __fprintf_chk(stderr,1,"server[%d]: %s\n",uVar3,uVar4);
    __fprintf_chk(stderr,1,"Handshake failed\n");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  clock_gettime(2,&local_78);
  if (local_e0 == 0) {
    local_e0 = gnutls_session_get_desc(local_c0);
  }
  gnutls_deinit(local_98);
  gnutls_deinit(local_c0);
  uVar9 = (ulong)DAT_001244a0;
  DAT_001244a0 = DAT_001244a0 + 1;
  uVar2 = DAT_001244a0;
  uVar4 = FUN_00113140(local_78.tv_sec,local_78.tv_nsec,local_88.tv_sec,local_88.tv_nsec);
  (&DAT_001244c0)[uVar9] = uVar4;
  if (0x8000 < uVar2) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  local_58 = local_58 + 1;
  if (DAT_0012448c != 0) {
    pcVar10 = "ns";
    __fprintf_chk(stdout,1,"%s\n - ",local_e0);
    (*gnutls_free)(local_e0);
    FUN_001127c0(local_68,"transactions",1);
    gnutls_priority_deinit(local_90);
    uVar9 = (ulong)DAT_001244a0;
    dVar12 = (double)FUN_001130b0(uVar9);
    if (DAT_001183b8 <= dVar12) {
      iVar1 = (int)uVar9;
      if (DAT_001183c0 <= dVar12) {
        dVar12 = dVar12 / DAT_001183c0;
        pcVar10 = "ms";
        if (iVar1 != 0) {
          puVar8 = &DAT_001244c0;
          do {
            puVar7 = puVar8 + 1;
            *puVar8 = *puVar8 / 1000000;
            puVar8 = puVar7;
          } while (&DAT_001244c8 + (iVar1 - 1) != puVar7);
          pcVar10 = "ms";
        }
      }
      else {
        dVar12 = dVar12 / DAT_001183b8;
        pcVar10 = &DAT_00118448;
        if (iVar1 != 0) {
          puVar8 = &DAT_001244c0;
          do {
            puVar7 = puVar8 + 1;
            *puVar8 = *puVar8 / 1000;
            puVar8 = puVar7;
          } while (puVar7 != &DAT_001244c8 + (iVar1 - 1));
          pcVar10 = &DAT_00118448;
        }
      }
    }
    dVar13 = (double)FUN_00113020(dVar12,uVar9 & 0xffffffff);
    dVar13 = sqrt(dVar13);
    __printf_chk(dVar12,dVar13,1,
                 " - avg. handshake time: %.2f %s\n - standard deviation: %.2f %s\n\n",pcVar10,
                 pcVar10);
    gnutls_anon_free_client_credentials(local_b0);
    gnutls_anon_free_server_credentials(local_c8);
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  goto LAB_00113280;
}



// Function: benchmark_tls @ 0x13860

void benchmark_tls(undefined4 param_1,int param_2)

{
  gnutls_global_set_log_function(FUN_00112990);
  gnutls_global_set_log_level(param_1);
  gnutls_global_init();
  if (param_2 == 0) {
    __printf_chk(1,"Testing key exchanges (RSA/DH bits: %d, EC bits: %d)\n\n",0xc00,0x100);
    FUN_00113160("NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+DHE-RSA:+GROUP-FFDHE3072"
                 ,1);
    FUN_00113160("NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-RSA-PSS-SHA256:+COMP-NULL:+ECDHE-RSA:+CURVE-SECP256R1"
                 ,6);
    FUN_00113160("NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-SECP256R1"
                 ,1);
    FUN_00113160("NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-X25519"
                 ,1);
    FUN_00113160("NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-ECDSA:+CURVE-SECP256R1"
                 ,4);
    FUN_00113160("NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-ECDSA:+CURVE-X25519"
                 ,4);
    FUN_00113160("NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-EDDSA-ED25519:+COMP-NULL:+ECDHE-ECDSA:+CURVE-X25519"
                 ,7);
    FUN_00113160("NONE:+VERS-TLS1.2:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA",1);
    FUN_00113160("NONE:+VERS-TLS1.2:+GOST28147-TC26Z-CNT:+GOST28147-TC26Z-IMIT:+SIGN-ALL:+SIGN-GOSTR341012-256:+COMP-NULL:+VKO-GOST-12:+GROUP-GOST-ALL"
                 ,9);
  }
  else {
    __printf_chk(1,"Testing throughput in cipher/MAC combinations (payload: %d bytes)\n",0x578);
    FUN_001129c0("NONE:+VERS-TLS1.2:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA",0x578);
    FUN_001129c0("NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+GROUP-ALL",0x578);
    FUN_001129c0("NONE:+VERS-TLS1.2:+AES-128-CCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA",0x578);
    FUN_001129c0("NONE:+VERS-TLS1.3:+AES-128-CCM:+AEAD:+SIGN-ALL:+COMP-NULL:+GROUP-ALL",0x578);
    FUN_001129c0("NONE:+VERS-TLS1.2:+CHACHA20-POLY1305:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-ALL"
                 ,0x578);
    FUN_001129c0("NONE:+VERS-TLS1.3:+CHACHA20-POLY1305:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-ALL"
                 ,0x578);
    FUN_001129c0("NONE:+VERS-TLS1.0:+AES-128-CBC:+SHA1:+SIGN-ALL:+COMP-NULL:+RSA",0x578);
    FUN_001129c0("NONE:+VERS-TLS1.0:+CAMELLIA-128-CBC:+SHA1:+SIGN-ALL:+COMP-NULL:+RSA",0x578);
    FUN_001129c0("NONE:+VERS-TLS1.2:+GOST28147-TC26Z-CNT:+GOST28147-TC26Z-IMIT:+SIGN-ALL:+SIGN-GOSTR341012-256:+COMP-NULL:+VKO-GOST-12:+GROUP-GOST-ALL"
                 ,0x578);
    __printf_chk(1,"\nTesting throughput in cipher/MAC combinations (payload: %d bytes)\n",0x4000);
    FUN_001129c0("NONE:+VERS-TLS1.2:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA",0x4000);
    FUN_001129c0("NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+GROUP-ALL",0x4000);
    FUN_001129c0("NONE:+VERS-TLS1.2:+AES-128-CCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA",0x4000);
    FUN_001129c0("NONE:+VERS-TLS1.3:+AES-128-CCM:+AEAD:+SIGN-ALL:+COMP-NULL:+GROUP-ALL",0x4000);
    FUN_001129c0("NONE:+VERS-TLS1.2:+CHACHA20-POLY1305:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-ALL"
                 ,0x4000);
    FUN_001129c0("NONE:+VERS-TLS1.3:+CHACHA20-POLY1305:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-ALL"
                 ,0x4000);
    FUN_001129c0("NONE:+VERS-TLS1.0:+AES-128-CBC:+SHA1:+SIGN-ALL:+COMP-NULL:+RSA",0x4000);
    FUN_001129c0("NONE:+VERS-TLS1.0:+CAMELLIA-128-CBC:+SHA1:+SIGN-ALL:+COMP-NULL:+RSA",0x4000);
    FUN_001129c0("NONE:+VERS-TLS1.2:+GOST28147-TC26Z-CNT:+GOST28147-TC26Z-IMIT:+SIGN-ALL:+SIGN-GOSTR341012-256:+COMP-NULL:+VKO-GOST-12:+GROUP-GOST-ALL"
                 ,0x4000);
  }
  gnutls_global_deinit();
  return;
}



// Function: _generate_request @ 0x13c00

void _generate_request(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  long in_FS_OFFSET;
  undefined8 local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = gnutls_ocsp_req_init(&local_38);
  if (iVar1 < 0) {
    uVar2 = gnutls_strerror(iVar1);
    pcVar3 = "ocsp_req_init: %s";
  }
  else {
    iVar1 = gnutls_ocsp_req_add_cert(local_38,3,param_2,param_1);
    if (iVar1 < 0) {
      uVar2 = gnutls_strerror(iVar1);
      pcVar3 = "ocsp_req_add_cert: %s";
    }
    else if ((param_4 == 0) || (iVar1 = gnutls_ocsp_req_set_nonce(local_38,0,param_4), -1 < iVar1))
    {
      iVar1 = gnutls_ocsp_req_export(local_38,param_3);
      if (iVar1 == 0) {
        gnutls_ocsp_req_deinit(local_38);
        if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return;
      }
      uVar2 = gnutls_strerror(iVar1);
      pcVar3 = "ocsp_req_export: %s";
    }
    else {
      uVar2 = gnutls_strerror(iVar1);
      pcVar3 = "ocsp_req_set_nonce: %s";
    }
  }
  __fprintf_chk(stderr,1,pcVar3,uVar2);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: send_ocsp_request @ 0x13d10

int send_ocsp_request(void *param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                undefined8 param_5)

{
  undefined1 auVar1 [16];
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  size_t sVar6;
  void *pvVar7;
  void *__dest;
  void *__dest_00;
  ulong __n;
  uint uVar8;
  long in_FS_OFFSET;
  int local_594;
  undefined *local_590;
  undefined1 local_588 [16];
  void *local_578;
  uint local_570;
  undefined1 local_568 [272];
  undefined2 local_458;
  undefined1 local_456;
  char local_448 [1032];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_590 = &DAT_00116c07;
  FUN_0010dc70();
  __dest_00 = param_1;
  if (param_1 == (void *)0x0) {
    iVar3 = 0;
    do {
      iVar4 = gnutls_x509_crt_get_authority_info_access(param_2,iVar3,0x2716,&local_578,0);
      iVar3 = iVar3 + 1;
    } while (iVar4 == -0x69);
    if (iVar4 < 0) {
      iVar3 = 0;
      do {
        iVar4 = gnutls_x509_crt_get_authority_info_access(param_3,iVar3,0x2716,&local_578,0);
        iVar3 = iVar3 + 1;
      } while (iVar4 == -0x69);
      if (iVar4 < 0) {
        uVar5 = gnutls_strerror(iVar4);
        __fprintf_chk(stderr,1,"*** Cannot find OCSP server URI in certificate: %s\n",uVar5);
        goto LAB_00113f49;
      }
    }
    __dest_00 = malloc((ulong)(local_570 + 1));
    pvVar7 = local_578;
    if (__dest_00 == (void *)0x0) {
      iVar4 = -1;
      goto LAB_00113f49;
    }
    __n = (ulong)local_570;
    memcpy(__dest_00,local_578,__n);
    *(undefined1 *)((long)__dest_00 + __n) = 0;
    (*gnutls_free)(pvVar7);
  }
  uVar5 = FUN_00113ae0(__dest_00,&local_594,&local_590);
  if (local_594 == 0) {
    local_456 = 0;
    local_458 = 0x3038;
  }
  else {
    __snprintf_chk(&local_458,0x10,1,0x10,&DAT_00116ea1);
  }
  __fprintf_chk(stderr,1,"Connecting to OCSP server: %s...\n",uVar5);
  local_588 = (undefined1  [16])0x0;
  FUN_00113c00(param_2,param_3,&local_578,param_5);
  __snprintf_chk(local_448,0x400,1,0x400,
                 "POST /%s HTTP/1.0\r\nHost: %s\r\nAccept: */*\r\nContent-Type: application/ocsp-request\r\nContent-Length: %u\r\nConnection: close\r\n\r\n"
                 ,local_590,uVar5,local_570);
  sVar6 = strlen(local_448);
  FUN_00111250(local_568,uVar5,&local_458,0,0x28,"Connecting to",0,0,0,0);
  FUN_00110f90(local_568,local_448,sVar6 & 0xffffffff);
  FUN_00110f90(local_568,local_578,local_570);
  (*gnutls_free)(local_578);
  local_578 = (void *)0x0;
  while (iVar3 = FUN_00110d90(local_568,&DAT_00194700,0x1001), auVar1 = local_588, 0 < iVar3) {
    FUN_00113b90((long)iVar3,local_588);
  }
  uVar5 = local_588._0_8_;
  if ((iVar3 == 0) && (uVar2 = local_588._8_4_, local_588._8_4_ != 0)) {
    FUN_00111040(local_568,0);
    pvVar7 = memmem((void *)uVar5,(ulong)(uint)uVar2,&DAT_00116ea9,4);
    if (pvVar7 == (void *)0x0) {
      iVar4 = -1;
      __fprintf_chk(stderr,1,"Cannot interpret HTTP response\n");
    }
    else {
      uVar8 = uVar2 - ((int)(void *)((long)pvVar7 + 4) - auVar1._0_4_);
      *(uint *)(param_4 + 1) = uVar8;
      __dest = malloc((ulong)uVar8);
      *param_4 = __dest;
      if (__dest == (void *)0x0) goto LAB_00113fc0;
      memcpy(__dest,(void *)((long)pvVar7 + 4),(ulong)*(uint *)(param_4 + 1));
      iVar4 = 0;
    }
  }
  else {
LAB_00113fc0:
    iVar4 = -1;
    perror("recv");
  }
  free((void *)uVar5);
  if (__dest_00 != param_1) {
    free(__dest_00);
  }
LAB_00113f49:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



// Function: print_ocsp_verify_res @ 0x140f0

void print_ocsp_verify_res(uint param_1)

{
  if (param_1 == 0) {
    __printf_chk(1,"Success");
  }
  else {
    __printf_chk(1,"Failure");
    if ((param_1 & 1) != 0) {
      __printf_chk(1,&DAT_00117331);
      __printf_chk(1,"Signer cert not found");
    }
    if ((param_1 & 2) != 0) {
      __printf_chk(1,&DAT_00117331);
      __printf_chk(1,"Signer cert keyusage error");
    }
    if ((param_1 & 4) != 0) {
      __printf_chk(1,&DAT_00117331);
      __printf_chk(1,"Signer cert is not trusted");
    }
    if ((param_1 & 8) != 0) {
      __printf_chk(1,&DAT_00117331);
      __printf_chk(1,"Insecure algorithm");
    }
  }
  if ((param_1 & 0x10) != 0) {
    __printf_chk(1,&DAT_00117331);
    __printf_chk(1,"Signature failure");
  }
  if ((param_1 & 0x20) != 0) {
    __printf_chk(1,&DAT_00117331);
    __printf_chk(1,"Signer cert not yet activated");
  }
  if ((param_1 & 0x40) != 0) {
    __printf_chk(1,&DAT_00117331);
    __printf_chk(1,"Signer cert expired");
    return;
  }
  return;
}



// Function: check_ocsp_response @ 0x14280

undefined8
check_ocsp_response(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
            int param_5)

{
  int iVar1;
  time_t tVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 uVar6;
  long in_FS_OFFSET;
  int local_100;
  int local_fc;
  undefined8 local_f8;
  undefined1 local_f0 [8];
  long local_e8;
  long local_e0;
  void *local_d8;
  uint local_d0;
  undefined1 local_c8 [64];
  undefined1 local_88 [72];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  tVar2 = time((time_t *)0x0);
  iVar1 = gnutls_ocsp_resp_init(&local_f8);
  if (iVar1 < 0) {
    uVar6 = gnutls_strerror(iVar1);
    pcVar5 = "ocsp_resp_init: %s";
  }
  else {
    iVar1 = gnutls_ocsp_resp_import(local_f8,param_3);
    if (iVar1 < 0) {
      uVar6 = gnutls_strerror(iVar1);
      pcVar5 = "importing response: %s";
    }
    else {
      iVar1 = gnutls_ocsp_resp_check_crt(local_f8,0,param_1);
      if (iVar1 < 0) {
        if (iVar1 == -0x38) {
          uVar6 = 0xffffffff;
          __printf_chk(1,"*** Got OCSP response with no data (ignoring)\n");
        }
        else {
          uVar6 = 0xffffffff;
          __printf_chk(1,"*** Got OCSP response on an unrelated certificate (ignoring)\n");
        }
        goto LAB_00114451;
      }
      iVar1 = gnutls_ocsp_resp_verify_direct(local_f8,param_2,&local_100,0);
      if (iVar1 < 0) {
        uVar6 = gnutls_strerror(iVar1);
        pcVar5 = "OCSP verification: %s\n";
      }
      else {
        if (local_100 != 0) {
          __printf_chk(1,"*** Verifying OCSP Response: ");
          FUN_001140f0(local_100);
          __printf_chk(1,".\n");
          if (local_100 != 0) {
            uVar6 = 0xffffffff;
            goto LAB_00114451;
          }
        }
        iVar1 = gnutls_ocsp_resp_get_single
                          (local_f8,0,0,0,0,0,&local_fc,&local_e8,&local_e0,local_f0,0);
        if (-1 < iVar1) {
          if (local_fc == 1) {
            uVar6 = 0;
            uVar3 = FUN_001102e0(local_f0,local_c8);
            __printf_chk(1,"*** Certificate was revoked at %s\n",uVar3);
          }
          else {
            if (local_e0 == -1) {
              if (0x3f480 < tVar2 - local_e8) {
                uVar6 = 0xffffffff;
                uVar3 = FUN_001102e0(&local_e8,local_c8);
                __printf_chk(1,"*** The OCSP response is old (was issued at: %s) ignoring\n",uVar3);
                goto LAB_00114451;
              }
            }
            else if (local_e0 < tVar2) {
              uVar3 = FUN_001102e0(&local_e0,local_88);
              uVar4 = FUN_001102e0(&local_e8,local_c8);
              uVar6 = 0xffffffff;
              __printf_chk(1,
                           "*** The OCSP response was issued at: %s but there is a newer issue at %s\n"
                           ,uVar4,uVar3);
              goto LAB_00114451;
            }
            if (param_4 != (undefined8 *)0x0) {
              iVar1 = gnutls_ocsp_resp_get_nonce(local_f8,0,&local_d8);
              if (iVar1 == -0x38) {
                if (param_5 != 0) {
                  __fprintf_chk(stderr,1,"*** The OCSP reply did not include the requested nonce.\n"
                               );
                }
              }
              else {
                if (iVar1 < 0) {
                  uVar6 = gnutls_strerror(iVar1);
                  pcVar5 = "could not read response\'s nonce: %s\n";
                  goto LAB_001145c6;
                }
                if (local_d0 != *(uint *)(param_4 + 1)) {
LAB_0011461c:
                  __fprintf_chk(stderr,1,"nonce in the response doesn\'t match\n");
                    /* WARNING: Subroutine does not return */
                  exit(1);
                }
                iVar1 = memcmp((void *)*param_4,local_d8,(ulong)*(uint *)(param_4 + 1));
                if (iVar1 != 0) goto LAB_0011461c;
                (*gnutls_free)(local_d8);
              }
            }
            uVar6 = 1;
            uVar3 = FUN_001102e0(&local_e8,local_c8);
            __printf_chk(1,"- OCSP server flags certificate not revoked as of %s\n",uVar3);
          }
LAB_00114451:
          gnutls_ocsp_resp_deinit(local_f8);
          if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
            return uVar6;
          }
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        uVar6 = gnutls_strerror(iVar1);
        pcVar5 = "reading response: %s\n";
      }
    }
  }
LAB_001145c6:
  __fprintf_chk(stderr,1,pcVar5,uVar6);
                    /* WARNING: Subroutine does not return */
  exit(1);
}



// Function: parse_number @ 0x14660

long parse_number(char *param_1)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  size_t sVar4;
  long lVar5;
  long in_FS_OFFSET;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = (char *)0x0;
  piVar2 = __errno_location();
  *piVar2 = 0;
  iVar1 = strncmp(param_1,"0x",2);
  if (iVar1 == 0) {
    lVar5 = strtol(param_1 + 2,&local_28,0x10);
  }
  else {
    iVar1 = strncmp(param_1,"0",1);
    if (iVar1 == 0) {
      sVar3 = strspn(param_1,"012345678");
      sVar4 = strlen(*(char **)PTR_optarg_0011ffd0);
      if (sVar3 == sVar4) {
        lVar5 = strtol(param_1 + 1,&local_28,8);
        goto LAB_00114703;
      }
    }
    lVar5 = strtol(param_1,&local_28,10);
  }
LAB_00114703:
  if ((*piVar2 != 0) || ((local_28 != (char *)0x0 && (*local_28 != '\0')))) {
    error(1,*piVar2,"\'%s\' is not a recognizable number.",param_1);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



// Function: usage @ 0x14840

void usage(undefined8 param_1,int param_2)

{
  long lVar1;
  char *pcVar2;
  undefined8 *puVar3;
  long in_FS_OFFSET;
  undefined8 uStack_1778;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  pcVar2 = 
  "gnutls-cli - GnuTLS client\nUsage:  gnutls-cli [ -<flag> [<val>] | --<name>[{=| }<val>] ]... [hostname]\n\nNone:\n\n   -d, --debug=num            Enable debugging\n\t\t\t\t- it must be in the range:\n\t\t\t\t  0 to 9999\n   -V, --verbose              More verbose output\n       --tofu                 Enable trust on first use authentication\n       --strict-tofu          Fail to connect if a certificate is unknown or a known certificate has changed\n       --dane                 Enable DANE certificate verification (DNSSEC)\n       --local-dns            Use the local DNS server for DNSSEC resolving\n       --ca-verification      Enable CA certificate verification\n\t\t\t\t- enabled by default\n\t\t\t\t- disabled as \'--no-ca-verification\'\n       --ocsp                 Enable OCSP certificate verification\n   -r, --resume               Establish a session and resume\n       --earlydata=str        Send early data on resumption from the specified file\n   -e, --rehandshake          Establish a session and rehandshake\n       --sni-hostname=str     Server\'s hostname for server name indication extension\n       --verify-hostname=str  Server\'s hostname to use for validation\n   -s, --starttls             Connect, establish a plain session and start TLS\n       --app-proto            an alias for the \'starttls-proto\' option\n       --starttls-proto=str   The application protocol to be used to obtain the server\'s certificate (https, ftp, smtp, imap, ldap, xmpp, lmtp, pop3, nntp, sieve, postgres)\n\t\t\t\t- prohibits the option \'starttls\'\n   -u, --udp                  Use DTLS (datagram TLS) over UDP\n       --mtu=num              Set MTU for datagram TLS\n\t\t\t\t- it must be in the range:\n\t\t\t\t  0 to 17000\n       --crlf                 Send CR LF instead of LF\n       --fastopen             Enable TCP Fast Open\n       --x509fmtder           Use DER format for certificates to read from\n       --print-cert           Print peer\'s certificate in PEM format\n       --save-cert=str        Save the peer\'s certificate chain in the specified file in PEM format\n       --save-ocsp=s..." /* TRUNCATED STRING LITERAL */
  ;
  puVar3 = &uStack_1778;
  for (lVar1 = 0x2ec; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *(undefined8 *)pcVar2;
    pcVar2 = pcVar2 + 8;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)pcVar2;
  *(char *)((long)puVar3 + 2) = s_gnutls_cli___GnuTLS_client_Usage_00119360[0x1762];
  __fprintf_chk(param_1,1,"%s",&uStack_1778);
                    /* WARNING: Subroutine does not return */
  exit(param_2);
}



// Function: process_options @ 0x148c0

undefined4 process_options(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  __pid_t _Var2;
  int *piVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  long in_FS_OFFSET;
  byte bVar7;
  int local_400;
  int local_3fc;
  char *local_3f8;
  undefined8 local_3f0;
  char local_3e8 [8];
  char acStack_3e0 [8];
  undefined2 local_3d8;
  long local_40;
  
  bVar7 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  DAT_001958a6 = 1;
switchD_00114945_caseD_0:
  iVar1 = getopt_long(param_1,param_2,"!Vbd:ehlp:rsuv:",&PTR_s_debug_0011ea20,0);
  if (iVar1 != -1) {
    switch(iVar1) {
    case 0:
      break;
    default:
      FUN_00114840(*(undefined8 *)PTR_stderr_0011ffd8,1);
      break;
    case 0x21:
      DAT_00195765 = '\x01';
      DAT_001958e5 = 1;
      break;
    case 0x56:
      DAT_00195721 = 1;
      DAT_001958a1 = 1;
      break;
    case 0x62:
      DAT_00195753 = 1;
      DAT_001958d3 = 1;
      break;
    case 100:
      DAT_00195720 = '\x01';
      DAT_00195768 = *(undefined8 *)PTR_optarg_0011ffd0;
      DAT_00195868 = FUN_00114660();
      DAT_001958a0 = 1;
      break;
    case 0x65:
      DAT_0019572a = 1;
      DAT_001958aa = 1;
      break;
    case 0x68:
      DAT_00195764 = '\x01';
      DAT_001958e4 = 1;
      break;
    case 0x6c:
      DAT_0019574d = '\x01';
      DAT_001958cd = 1;
      break;
    case 0x70:
      DAT_00195746 = '\x01';
      DAT_001958c6 = 1;
      DAT_00195820 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x72:
      DAT_00195728 = 1;
      DAT_001958a8 = 1;
      break;
    case 0x73:
      DAT_0019572d = '\x01';
      DAT_001958ad = 1;
      break;
    case 0x75:
      DAT_0019572f = 1;
      DAT_001958af = 1;
      break;
    case 0x76:
      DAT_00195763 = '\x01';
      DAT_001958e3 = 1;
      DAT_00195860 = *(char **)PTR_optarg_0011ffd0;
      break;
    case 0x80:
      DAT_00195722 = 1;
      DAT_001958a2 = 1;
      break;
    case 0x81:
      DAT_00195722 = 1;
      DAT_001958a2 = 0;
      break;
    case 0x82:
      DAT_00195723 = 1;
      DAT_001958a3 = 1;
      break;
    case 0x83:
      DAT_00195723 = 1;
      DAT_001958a3 = 0;
      break;
    case 0x84:
      DAT_00195724 = 1;
      DAT_001958a4 = 1;
      break;
    case 0x85:
      DAT_00195724 = 1;
      DAT_001958a4 = 0;
      break;
    case 0x86:
      DAT_00195725 = 1;
      DAT_001958a5 = 1;
      break;
    case 0x87:
      DAT_00195725 = 1;
      DAT_001958a5 = 0;
      break;
    case 0x88:
      DAT_00195726 = 1;
      DAT_001958a6 = 1;
      break;
    case 0x89:
      DAT_00195726 = 1;
      DAT_001958a6 = 0;
      break;
    case 0x8a:
      DAT_00195727 = 1;
      DAT_001958a7 = 1;
      break;
    case 0x8b:
      DAT_00195727 = 1;
      DAT_001958a7 = 0;
      break;
    case 0x8c:
      DAT_00195729 = 1;
      DAT_001958a9 = 1;
      DAT_00195770 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x8d:
      DAT_0019572b = 1;
      DAT_001958ab = 1;
      DAT_00195778 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x8e:
      DAT_0019572c = 1;
      DAT_001958ac = 1;
      DAT_00195780 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x8f:
    case 0x90:
      DAT_0019572e = '\x01';
      DAT_001958ae = 1;
      DAT_00195788 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x91:
      DAT_00195730 = '\x01';
      DAT_00195790 = *(undefined8 *)PTR_optarg_0011ffd0;
      DAT_0019586c = FUN_00114660();
      DAT_001958b0 = 1;
      break;
    case 0x92:
      DAT_00195731 = 1;
      DAT_001958b1 = 1;
      break;
    case 0x93:
      DAT_00195732 = 1;
      DAT_001958b2 = 1;
      break;
    case 0x94:
      DAT_00195733 = 1;
      DAT_001958b3 = 1;
      break;
    case 0x95:
      DAT_00195734 = 1;
      DAT_001958b4 = 1;
      break;
    case 0x96:
      DAT_00195735 = 1;
      DAT_001958b5 = 1;
      DAT_00195798 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x97:
      DAT_00195736 = '\x01';
      DAT_001958b6 = 1;
      DAT_001957a0 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x98:
      DAT_00195737 = '\x01';
      DAT_001958b7 = 1;
      DAT_001957a8 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x99:
      DAT_00195738 = 1;
      DAT_001958b8 = 1;
      DAT_001957b0 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x9a:
      DAT_00195739 = 1;
      DAT_001958b9 = 1;
      DAT_001957b8 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x9b:
      DAT_0019573a = 1;
      DAT_001957c0 = *(undefined8 *)PTR_optarg_0011ffd0;
      DAT_00195870 = FUN_00114660();
      DAT_001958ba = 1;
      break;
    case 0x9c:
      DAT_0019573b = 1;
      DAT_001958bb = 1;
      DAT_001957c8 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x9d:
      DAT_0019573c = 1;
      DAT_001958bc = 1;
      DAT_001957d0 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x9e:
      DAT_0019573d = 1;
      DAT_001958bd = 1;
      DAT_001957d8 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0x9f:
      DAT_0019573e = '\x01';
      DAT_001958be = 1;
      DAT_001957e0 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xa0:
      DAT_0019573f = '\x01';
      DAT_001958bf = 1;
      DAT_001957e8 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xa1:
      DAT_00195740 = '\x01';
      DAT_001958c0 = 1;
      DAT_001957f0 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xa2:
      DAT_00195741 = '\x01';
      DAT_001958c1 = 1;
      DAT_001957f8 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xa3:
      DAT_00195742 = 1;
      DAT_001958c2 = 1;
      DAT_00195800 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xa4:
      DAT_00195743 = 1;
      DAT_001958c3 = 1;
      DAT_00195808 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xa5:
      DAT_00195744 = 1;
      DAT_001958c4 = 1;
      DAT_00195810 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xa6:
      DAT_00195745 = 1;
      DAT_001958c5 = 1;
      DAT_00195818 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xa7:
      DAT_00195747 = 1;
      DAT_001958c7 = 1;
      break;
    case 0xa8:
      DAT_00195748 = 1;
      DAT_001958c8 = 1;
      break;
    case 0xa9:
      DAT_00195749 = 1;
      DAT_001958c9 = 1;
      break;
    case 0xaa:
      DAT_0019574a = 1;
      DAT_001958ca = 1;
      break;
    case 0xab:
      DAT_0019574b = 1;
      DAT_001958cb = 1;
      break;
    case 0xac:
      DAT_0019574c = 1;
      DAT_001958cc = 1;
      break;
    case 0xad:
      DAT_0019574e = 1;
      DAT_001958ce = 1;
      break;
    case 0xae:
      DAT_0019574f = 1;
      DAT_001958cf = 1;
      break;
    case 0xaf:
      DAT_00195750 = 1;
      DAT_001958d0 = 1;
      DAT_00195828 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xb0:
      DAT_00195751 = 1;
      FUN_001147a0(&DAT_00195880,&DAT_00118f9c);
      DAT_001958d1 = 1;
      break;
    case 0xb1:
      DAT_00195752 = 1;
      FUN_001147a0(&DAT_00195890,"compress-cert");
      DAT_001958d2 = 1;
      break;
    case 0xb2:
      DAT_00195754 = '\x01';
      DAT_00195830 = *(undefined8 *)PTR_optarg_0011ffd0;
      DAT_00195874 = FUN_00114660();
      DAT_001958d4 = 1;
      break;
    case 0xb3:
      DAT_00195755 = 1;
      DAT_001958d5 = 1;
      break;
    case 0xb4:
      DAT_00195756 = 1;
      DAT_001958d6 = 1;
      break;
    case 0xb5:
      DAT_00195757 = 1;
      DAT_001958d7 = 1;
      break;
    case 0xb6:
      DAT_00195758 = 1;
      DAT_001958d8 = 1;
      break;
    case 0xb7:
      DAT_00195759 = 1;
      DAT_001958d9 = 1;
      break;
    case 0xb8:
      DAT_0019575a = 1;
      DAT_001958da = 1;
      DAT_00195838 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xb9:
      DAT_0019575b = 1;
      DAT_001958db = 1;
      DAT_00195840 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xba:
      DAT_0019575c = 1;
      DAT_001958dc = 1;
      break;
    case 0xbb:
      DAT_0019575d = 1;
      DAT_001958dd = 1;
      break;
    case 0xbc:
      DAT_0019575e = 1;
      DAT_001958de = 1;
      DAT_00195848 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xbd:
      DAT_0019575f = 1;
      DAT_001958df = 1;
      DAT_00195850 = *(undefined8 *)PTR_optarg_0011ffd0;
      break;
    case 0xbe:
      DAT_00195760 = 1;
      DAT_00195858 = *(undefined8 *)PTR_optarg_0011ffd0;
      DAT_00195878 = FUN_00114660();
      DAT_001958e0 = 1;
      break;
    case 0xbf:
      DAT_00195761 = 1;
      DAT_001958e1 = 1;
      break;
    case 0xc0:
      DAT_00195762 = 1;
      DAT_001958e2 = 1;
      break;
    case 0xc1:
      DAT_00195762 = 1;
      DAT_001958e2 = 0;
    }
    goto switchD_00114945_caseD_0;
  }
  if ((DAT_00195720 != '\0') &&
     (((-1 < DAT_00195868 ||
       (error(1,0,"%s option value %d is out of range.","debug"), DAT_00195720 != '\0')) &&
      (9999 < DAT_00195868)))) {
    error(1,0,"%s option value %d is out of range","debug");
  }
  if ((DAT_0019572e != '\0') && (DAT_0019572d != '\0')) {
    error(1,0,"the \'%s\' and \'%s\' options conflict","starttls-proto","starttls");
  }
  if (((DAT_00195730 != '\0') &&
      ((-1 < DAT_0019586c ||
       (error(1,0,"%s option value %d is out of range.",&DAT_00118fdd), DAT_00195730 != '\0')))) &&
     (17000 < DAT_0019586c)) {
    error(1,0,"%s option value %d is out of range",&DAT_00118fdd);
  }
  if ((((DAT_00195736 != '\0') && (DAT_00195737 != '\0')) &&
      (error(1,0,"the \'%s\' and \'%s\' options conflict","save-ocsp","save_ocsp_multi"),
      DAT_00195737 != '\0')) && (DAT_00195736 != '\0')) {
    error(1,0,"the \'%s\' and \'%s\' options conflict","save-ocsp-multi","save_ocsp");
  }
  if ((DAT_0019573f != '\0') && (DAT_0019573e == '\0')) {
    error(1,0,"%s option requires the %s options","x509certfile","x509keyfile");
  }
  if ((DAT_00195741 != '\0') && (DAT_00195740 == '\0')) {
    error(1,0,"%s option requires the %s options","rawpkfile","rawpkkeyfile");
  }
  if ((DAT_0019574d != '\0') && (DAT_00195746 != '\0')) {
    error(1,0,"the \'%s\' and \'%s\' options conflict","list","port");
  }
  if ((DAT_00195754 != '\0') &&
     (((-1 < DAT_00195874 ||
       (error(1,0,"%s option value %d is out of range.","recordsize"), DAT_00195754 != '\0')) &&
      (0x1000 < DAT_00195874)))) {
    error(1,0,"%s option value %d is out of range","recordsize");
  }
  if (DAT_00195764 != '\0') {
    FUN_00114840(*(undefined8 *)PTR_stdout_0011ffe8);
  }
  if (DAT_00195765 != '\0') {
    iVar1 = pipe(&local_400);
    if (iVar1 < 0) {
      piVar3 = __errno_location();
      error(1,*piVar3,&DAT_00119050);
    }
    _Var2 = fork();
    if (_Var2 < 0) {
      piVar3 = __errno_location();
      error(1,*piVar3,&DAT_00119055);
LAB_00115575:
      close(local_3fc);
      dup2(local_400,0);
      close(local_400);
      local_3f8 = (char *)secure_getenv("PAGER");
      if ((local_3f8 == (char *)0x0) || (*local_3f8 == '\0')) {
        local_3f8 = "more";
      }
      local_3f0 = 0;
      execvp(local_3f8,&local_3f8);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (_Var2 != 0) goto LAB_00115575;
    close(local_400);
    dup2(local_3fc,1);
    close(local_3fc);
    FUN_00114840(*(undefined8 *)PTR_stdout_0011ffe8,0);
  }
  pcVar5 = DAT_00195860;
  if (DAT_00195763 != '\0') {
    if ((DAT_00195860 == (char *)0x0) || (iVar1 = strcmp(DAT_00195860,"c"), iVar1 == 0)) {
      pcVar5 = 
      "gnutls-cli 3.7.8\nCopyright (C) 2000-2021 Free Software Foundation, and others\nThis is free software. It is licensed for use, modification and\nredistribution under the terms of the GNU General Public License,\nversion 3 or later <http://gnu.org/licenses/gpl.html>\n\nPlease send bug reports to:  <bugs@gnutls.org>            \n"
      ;
      pcVar6 = local_3e8;
      for (lVar4 = 0x28; lVar4 != 0; lVar4 = lVar4 + -1) {
        *(undefined8 *)pcVar6 = *(undefined8 *)pcVar5;
        pcVar5 = pcVar5 + ((ulong)bVar7 * -2 + 1) * 8;
        pcVar6 = pcVar6 + ((ulong)bVar7 * -2 + 1) * 8;
      }
      *(undefined2 *)pcVar6 = *(undefined2 *)pcVar5;
      pcVar6[2] = s_gnutls_cli_3_7_8_Copyright__C__2_0011abf0[0x142];
    }
    else {
      iVar1 = strcmp(pcVar5,"v");
      if (iVar1 == 0) {
        local_3e8[0] = s_gnutls_cli_3_7_8rbe_0011b3e0[0];
        local_3e8[1] = s_gnutls_cli_3_7_8rbe_0011b3e0[1];
        local_3e8[2] = s_gnutls_cli_3_7_8rbe_0011b3e0[2];
        local_3e8[3] = s_gnutls_cli_3_7_8rbe_0011b3e0[3];
        local_3e8[4] = s_gnutls_cli_3_7_8rbe_0011b3e0[4];
        local_3e8[5] = s_gnutls_cli_3_7_8rbe_0011b3e0[5];
        local_3e8[6] = s_gnutls_cli_3_7_8rbe_0011b3e0[6];
        local_3e8[7] = s_gnutls_cli_3_7_8rbe_0011b3e0[7];
        acStack_3e0[0] = s_gnutls_cli_3_7_8rbe_0011b3e0[8];
        acStack_3e0[1] = s_gnutls_cli_3_7_8rbe_0011b3e0[9];
        acStack_3e0[2] = s_gnutls_cli_3_7_8rbe_0011b3e0[10];
        acStack_3e0[3] = s_gnutls_cli_3_7_8rbe_0011b3e0[0xb];
        acStack_3e0[4] = s_gnutls_cli_3_7_8rbe_0011b3e0[0xc];
        acStack_3e0[5] = s_gnutls_cli_3_7_8rbe_0011b3e0[0xd];
        acStack_3e0[6] = s_gnutls_cli_3_7_8rbe_0011b3e0[0xe];
        acStack_3e0[7] = s_gnutls_cli_3_7_8rbe_0011b3e0[0xf];
        local_3d8 = 10;
      }
      else {
        iVar1 = strcmp(pcVar5,"n");
        if (iVar1 != 0) {
          error(1,0,
                "version option argument \'a\' invalid.  Use:\n\t\'v\' - version only\n\t\'c\' - version and copyright\n\t\'n\' - version and full copyright notice"
               );
          goto LAB_00115296;
        }
        pcVar5 = 
        "gnutls-cli 3.7.8\nCopyright (C) 2000-2021 Free Software Foundation, and others\nThis is free software. It is licensed for use, modification and\nredistribution under the terms of the GNU General Public License,\nversion 3 or later <http://gnu.org/licenses/gpl.html>\n\ngnutls is free software: you can redistribute it and/or\nmodify it under the terms of the GNU General Public License\nas published by the Free Software Foundation,\neither version 3 of the License, or (at your option) any later version.\n\ngnutls is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty\nof MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\nSee the GNU General Public License for more details.\n\nYou should have received a copy of the GNU General Public License\nalong with this program.  If not, see <http://www.gnu.org/licenses/>.\n\nPlease send bug reports to:  <bugs@gnutls.org>            \n"
        ;
        pcVar6 = local_3e8;
        for (lVar4 = 0x73; lVar4 != 0; lVar4 = lVar4 + -1) {
          *(undefined8 *)pcVar6 = *(undefined8 *)pcVar5;
          pcVar5 = pcVar5 + ((ulong)bVar7 * -2 + 1) * 8;
          pcVar6 = pcVar6 + ((ulong)bVar7 * -2 + 1) * 8;
        }
        *(undefined2 *)pcVar6 = *(undefined2 *)pcVar5;
        pcVar6[2] = s_gnutls_cli_3_7_8_Copyright__C__2_0011ad38[0x39a];
      }
    }
    __fprintf_chk(*(undefined8 *)PTR_stdout_0011ffe8,1,"%s",local_3e8);
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
LAB_00115296:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return *(undefined4 *)PTR_optind_0011ffb8;
}



// Function: _gnutls_fread_file @ 0x15860

void * _gnutls_fread_file(FILE *param_1,uint param_2,ulong *param_3)

{
  int iVar1;
  int iVar2;
  void *__dest;
  size_t sVar3;
  int *piVar4;
  __off_t _Var5;
  void *pvVar6;
  ulong __n;
  size_t __size;
  size_t __n_00;
  long in_FS_OFFSET;
  stat local_d8;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = fileno(param_1);
  iVar1 = fstat(iVar1,&local_d8);
  if ((((iVar1 < 0) || ((local_d8.st_mode & 0xf000) != 0x8000)) ||
      (_Var5 = ftello(param_1), _Var5 < 0)) || (local_d8.st_size <= _Var5)) {
    __size = 0x2000;
  }
  else {
    __size = (local_d8.st_size - _Var5) + 1;
    if (local_d8.st_size - _Var5 == 0x7fffffffffffffff) {
      piVar4 = __errno_location();
      __dest = (void *)0x0;
      *piVar4 = 0xc;
      goto LAB_001159c6;
    }
  }
  __dest = malloc(__size);
  if (__dest != (void *)0x0) {
    __n = 0;
LAB_00115932:
    do {
      pvVar6 = __dest;
      __n_00 = __size - __n;
      sVar3 = fread((void *)((long)pvVar6 + __n),1,__n_00,param_1);
      __n = __n + sVar3;
      if (__n_00 != sVar3) {
        piVar4 = __errno_location();
        iVar1 = *piVar4;
        iVar2 = ferror(param_1);
        if (iVar2 != 0) {
LAB_001159ae:
          if ((param_2 & 2) != 0) {
LAB_00115a90:
            __explicit_bzero_chk(pvVar6,__size,0xffffffffffffffff);
          }
          goto LAB_001159b9;
        }
        __dest = pvVar6;
        if (__n < __size - 1) {
          if ((param_2 & 2) == 0) {
            pvVar6 = realloc(pvVar6,__n + 1);
            if (pvVar6 != (void *)0x0) {
              __dest = pvVar6;
            }
          }
          else {
            __dest = malloc(__n + 1);
            if (__dest == (void *)0x0) {
              __explicit_bzero_chk((long)pvVar6 + __n,__size - __n,0xffffffffffffffff);
              __dest = pvVar6;
            }
            else {
              memcpy(__dest,pvVar6,__n);
              __explicit_bzero_chk(pvVar6,__size,0xffffffffffffffff);
              free(pvVar6);
            }
          }
        }
        *(undefined1 *)((long)__dest + __n) = 0;
        *param_3 = __n;
        goto LAB_001159c6;
      }
      if (__size == 0x7fffffffffffffff) {
        piVar4 = __errno_location();
        iVar1 = 0xc;
        goto LAB_001159ae;
      }
      sVar3 = (__size >> 1) + __size;
      if (0x7fffffffffffffff - (__size >> 1) <= __size) {
        sVar3 = 0x7fffffffffffffff;
      }
      if ((param_2 & 2) != 0) {
        __dest = malloc(sVar3);
        if (__dest == (void *)0x0) {
          piVar4 = __errno_location();
          iVar1 = *piVar4;
          __size = sVar3;
          goto LAB_00115a90;
        }
        memcpy(__dest,pvVar6,__size);
        __explicit_bzero_chk(pvVar6,__size,0xffffffffffffffff);
        free(pvVar6);
        __size = sVar3;
        goto LAB_00115932;
      }
      __dest = realloc(pvVar6,sVar3);
      __size = sVar3;
    } while (__dest != (void *)0x0);
    piVar4 = __errno_location();
    iVar1 = *piVar4;
LAB_001159b9:
    __dest = (void *)0x0;
    free(pvVar6);
    *piVar4 = iVar1;
  }
LAB_001159c6:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __dest;
}



// Function: _gnutls_read_file @ 0x15b50

void * _gnutls_read_file(char *param_1,uint param_2,undefined8 *param_3)

{
  int iVar1;
  FILE *__stream;
  void *__ptr;
  char *__modes;
  
  __modes = "rbe";
  if ((param_2 & 1) == 0) {
    __modes = "re";
  }
  __stream = fopen(param_1,__modes);
  if (__stream != (FILE *)0x0) {
    if ((param_2 & 2) != 0) {
      setvbuf(__stream,(char *)0x0,2,0);
    }
    __ptr = (void *)FUN_00115860(__stream,param_2,param_3);
    iVar1 = fclose(__stream);
    if (iVar1 == 0) {
      return __ptr;
    }
    if (__ptr != (void *)0x0) {
      if ((param_2 & 2) != 0) {
        __explicit_bzero_chk(__ptr,*param_3,0xffffffffffffffff);
      }
      free(__ptr);
    }
  }
  return (void *)0x0;
}



