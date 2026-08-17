// Function: main @ 0x9640
long long main(long long a1, char **a2, char **a3)
{
  int v3; // ecx
  int v4; // r8d
  int v5; // r9d
  int v6; // eax
  unsigned int v7; // ebx
  FILE *v8; // rbp
  FILE *v9; // rax
  int v10; // edx
  int v11; // ecx
  int v12; // r8d
  int v13; // r9d
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // eax
  ssize_t v17; // rax
  ssize_t v18; // rbx
  int v19; // ebx
  unsigned int v20; // r13d
  int v22; // eax
  unsigned int v23; // eax
  int v24; // edx
  int v25; // ecx
  int v26; // r8d
  int v27; // r9d
  int v28; // r15d
  unsigned int v29; // r14d
  int v30; // ecx
  int v31; // r8d
  int v32; // r9d
  long long *v33; // r14
  int v34; // edi
  bool v35; // zf
  char *v36; // rax
  char *v37; // rsi
  long long *v38; // r8
  int can_use_length_hiding; // eax
  int v40; // eax
  int v41; // ecx
  int v42; // r8d
  int v43; // r9d
  int v44; // eax
  const char *v45; // rax
  FILE *stream; // [rsp+0h] [rbp-1258h]
  long long *v47; // [rsp+8h] [rbp-1250h]
  long long v48[2]; // [rsp+10h] [rbp-1248h] BYREF
  __int128 v49; // [rsp+20h] [rbp-1238h]
  __int128 v50; // [rsp+30h] [rbp-1228h]
  __int128 v51; // [rsp+40h] [rbp-1218h]
  __int128 v52; // [rsp+50h] [rbp-1208h]
  struct sigaction act; // [rsp+60h] [rbp-11F8h] BYREF
  char v54[8]; // [rsp+100h] [rbp-1158h] BYREF
  long long v55; // [rsp+108h] [rbp-1150h]
  int v56; // [rsp+110h] [rbp-1148h]
  int v57; // [rsp+148h] [rbp-1110h]
  long long buf[512]; // [rsp+210h] [rbp-1048h] BYREF
  char v59; // [rsp+1210h] [rbp-48h]
  unsigned long long v60; // [rsp+1218h] [rbp-40h]

  v60 = __readfsqword(0x28u);
  sub_C460(a1, a2, a3);
  if ( byte_9575E )
  {
    stream = fopen(filename, "w+");
    if ( !stream )
    {
      sub_DC90((int)stderr, (unsigned int)"Unable to open '%s'!\n", (int)filename, v3, v4, v5, 0);
      exit(1);
    }
    sub_102D0(stream);
  }
  else
  {
    LOBYTE(stream) = 0;
  }
  gnutls_global_set_log_function(sub_A220);
  gnutls_global_set_log_level((unsigned int)dword_95868);
  v6 = gnutls_global_init();
  if ( v6 < 0 )
  {
    v45 = (const char *)gnutls_strerror((unsigned int)v6);
    __fprintf_chk(stderr, 1, "global_init: %s\n", v45);
    exit(1);
  }
  if ( !qword_223A0 )
  {
    __fprintf_chk(stderr, 1, "No hostname given\n");
    exit(1);
  }
  sub_DC70();
  sub_B730();
  sub_11180(qword_223A0, nptr, 0x20u);
  v7 = 64 - ((dword_223B8 == 0) - 1);
  if ( dword_22370 )
    v7 |= 2u;
  if ( dword_2236C )
    v7 |= 0x10u;
  if ( dword_223C8 )
  {
    v7 |= 8u;
  }
  else if ( byte_9572E )
  {
    v7 |= 4u;
  }
  v8 = 0;
  if ( byte_95738 )
    v8 = fopen(qword_957B0, "wb");
  v9 = 0;
  if ( byte_95739 )
    v9 = fopen(qword_957B8, "wb");
  sub_11250(v54, qword_223A0, nptr, qword_95788, v7, "Connecting to", 0, 0, v8, v9);
  v57 = dword_2236C;
  if ( v56 )
  {
    sub_DC90((int)stdout, (unsigned int)"- Handshake was completed\n", v10, v11, v12, v13, (char)stream);
    if ( dword_223CC && (unsigned int)sub_BA70(v54) )
      goto LABEL_37;
    sub_BCD0(v55);
  }
  sub_DC90((int)stdout, (unsigned int)"\n- Simple Client Mode:\n\n", v10, v11, v12, v13, (char)stream);
  if ( !dword_223BC || !(unsigned int)sub_D320(v54) )
  {
    act.sa_handler = (__sighandler_t)sub_9E70;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(14, &act, 0);
    fflush(stdout);
    fflush(stderr);
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    setbuf(stderr, 0);
    v49 = 0;
    v50 = 0;
    v51 = 0;
    v52 = 0;
    if ( dword_223B0 )
      DWORD1(v50) = 1;
LABEL_26:
    v14 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( dword_22300 && !v56 )
        {
          __fprintf_chk(stderr, 1, "*** Starting TLS handshake\n");
          if ( (int)sub_D200(v54) < 0 )
            goto LABEL_36;
          v15 = sub_BE50(v54, v14);
          if ( v15 == 3 )
          {
LABEL_51:
            v20 = 0;
            goto LABEL_38;
          }
        }
        else
        {
          v15 = sub_BE50(v54, v14);
          if ( v15 == 3 )
            goto LABEL_51;
        }
        if ( v15 == 2 )
          break;
        if ( v15 == 1 && (unsigned char)v14 != 1 )
        {
          v16 = fileno(stdin);
          v17 = read(v16, buf, 0xFFFu);
          v18 = v17;
          if ( v17 > 0 )
          {
            v35 = dword_22374 == 0;
            *((char *)buf + v17) = 0;
            if ( !v35 )
            {
              v36 = strchr((const char *)buf, 10);
              if ( v36 )
              {
                strcpy(v36, "\r\n");
                ++v18;
              }
            }
            LODWORD(v37) = v18;
            v38 = buf;
            while ( 1 )
            {
              if ( dword_223B0 )
              {
                v44 = sub_D3E0(v38);
                LODWORD(v37) = v44;
                if ( !v44 )
                  goto LABEL_26;
                if ( v44 < 0LL )
                  goto LABEL_37;
                v38 = (long long *)v49;
              }
              if ( dword_223C0
                && (v47 = v38,
                    can_use_length_hiding = gnutls_record_can_use_length_hiding(v55),
                    v38 = v47,
                    can_use_length_hiding) )
              {
                v48[0] = 0;
                v48[1] = 4096;
                v40 = sub_10E90(v54, v47, (unsigned int)v37, v48);
              }
              else
              {
                v40 = sub_10F90(v54, v38, (unsigned int)v37);
              }
              if ( v40 <= 0 )
              {
                sub_D570(v54, (unsigned int)v40);
              }
              else if ( dword_2236C )
              {
                sub_DC90((int)stdout, (unsigned int)"- Sent: %d bytes\n", v40, v41, v42, v43, (char)stream);
              }
              if ( !dword_223B0 )
                goto LABEL_26;
              v38 = (long long *)*((long long *)&v49 + 1);
              if ( *((long long *)&v49 + 1) >= (unsigned long long)buf + v18 )
                goto LABEL_26;
              v37 = (char *)buf + v18 - *((long long *)&v49 + 1);
            }
          }
          if ( !v56 )
          {
            __fprintf_chk(stderr, 1, "*** Starting TLS handshake\n");
            v19 = sub_D200(v54);
            clearerr(stdin);
            if ( v19 >= 0 )
              goto LABEL_26;
LABEL_36:
            __fprintf_chk(stderr, 1, "*** Handshake has failed\n");
            goto LABEL_37;
          }
          do
          {
            do
              v22 = gnutls_bye(v55, 1);
            while ( v22 == -52 );
          }
          while ( v22 == -28 );
          v14 = 1;
        }
      }
      memset(buf, 0, sizeof(buf));
      v59 = 0;
      v23 = sub_10D90(v54, buf, 4096);
      v28 = v23;
      v29 = v23;
      if ( !v23 || v23 == -110 && v14 )
      {
        v20 = 0;
        sub_DC90(
          (int)stdout,
          (unsigned int)"- Peer has closed the GnuTLS connection\n",
          v24,
          v25,
          v26,
          v27,
          (char)stream);
        goto LABEL_38;
      }
      if ( (int)sub_D570(v54, v23) < 0 )
        break;
      if ( v28 > 0 )
      {
        if ( dword_2236C )
          sub_DC90((int)stdout, (unsigned int)"- Received[%d]: ", v29, v30, v31, v32, (char)stream);
        v33 = buf;
        do
        {
          v34 = *(char *)v33;
          v33 = (long long *)((char *)v33 + 1);
          fputc(v34, stdout);
        }
        while ( (long long *)((char *)buf + (unsigned int)(v28 - 1) + 1) != v33 );
        fflush(stdout);
      }
    }
    __fprintf_chk(stderr, 1, "*** Server has terminated the connection abnormally.\n");
  }
LABEL_37:
  v20 = 1;
LABEL_38:
  sub_11040(v54, 0);
  if ( stream )
    fclose(stream);
  if ( qword_23720 )
    gnutls_srp_free_client_credentials();
  if ( qword_23718 )
    gnutls_psk_free_client_credentials();
  gnutls_certificate_free_credentials(qword_23708);
  gnutls_anon_free_client_credentials(qword_23710);
  gnutls_global_deinit();
  return v20;
}


// Function: starttls_alarm @ 0x9e70
void starttls_alarm()
{
  dword_22300 = 1;
}


// Function: srp_username_callback @ 0x9e80
long long srp_username_callback(long long a1, long long *a2, long long *a3)
{
  if ( !qword_22358 || !qword_22360 )
    return 0xFFFFFFFFLL;
  *a2 = ((long long (*)(void))gnutls_strdup)();
  *a3 = gnutls_strdup(qword_22360);
  return 0;
}


// Function: read_yesno @ 0x9ed0
long long read_yesno(const char *a1)
{
  char v2[136]; // [rsp+0h] [rbp-98h] BYREF
  unsigned long long v3; // [rsp+88h] [rbp-10h]

  v3 = __readfsqword(0x28u);
  fputs(a1, stderr);
  return fgets(v2, 128, stdin) && v2[0] != 10 && v2[0] != 13 && (v2[0] & 0xDF) == 89;
}


// Function: cert_callback @ 0x9f60
long long cert_callback(long long a1, long long a2, int a3, long long a4, int a5, long long *a6, int *a7, long long *a8)
{
  int v10; // r13d
  int v11; // ecx
  int v12; // r8d
  int v13; // r9d
  int v14; // ecx
  int v15; // r8d
  int v16; // r9d
  unsigned int v17; // eax
  int v18; // edx
  int v19; // r8d
  int v20; // r9d
  void *v21; // rcx
  int name; // eax
  int v23; // ecx
  int v24; // r8d
  int v25; // r9d
  int v27; // edx
  int v28; // edi
  int v29; // edi
  int *v30; // [rsp+0h] [rbp-178h]
  char v31; // [rsp+0h] [rbp-178h]
  long long v33; // [rsp+28h] [rbp-150h] BYREF
  char v34[264]; // [rsp+30h] [rbp-148h] BYREF
  unsigned long long v35; // [rsp+138h] [rbp-40h]

  v30 = a7;
  v35 = __readfsqword(0x28u);
  if ( dword_2236C )
  {
    if ( a3 <= 0 )
    {
      sub_DC90(
        (int)stdout,
        (unsigned int)"- Server did not send us any trusted authorities names.\n",
        a3,
        dword_2236C,
        a5,
        (int)a6,
        (char)a7);
    }
    else
    {
      v10 = 0;
      sub_DC90(
        (int)stdout,
        (unsigned int)"- Server's trusted authorities:\n",
        a3,
        dword_2236C,
        a5,
        (int)a6,
        (char)a7);
      do
      {
        v33 = 256;
        if ( (int)gnutls_x509_rdn_get(a2, v34, &v33) >= 0 )
        {
          sub_DC90((int)stdout, (unsigned int)"   [%d]: ", v10, v11, v12, v13, (char)v30);
          sub_DC90((int)stdout, (unsigned int)"%s\n", (unsigned int)v34, v14, v15, v16, v31);
        }
        ++v10;
        a2 += 16;
      }
      while ( a3 != v10 );
    }
  }
  v17 = gnutls_certificate_type_get2(a1, 0);
  LODWORD(v21) = (int)v30;
  *v30 = 0;
  if ( v17 == 1 )
  {
    v27 = dword_23700;
    v28 = (int)stdout;
    if ( dword_23700 )
    {
      if ( !qword_23620 )
      {
        sub_DC90(
          (int)stdout,
          (unsigned int)"- Could not find a suitable key to send to server\n",
          dword_23700,
          (int)v30,
          v19,
          v20,
          (char)v30);
        return 0xFFFFFFFFLL;
      }
      *a8 = qword_23620;
      v21 = &unk_23640;
      *v30 = v27;
      *a6 = &unk_23640;
    }
    sub_DC90(
      v28,
      (unsigned int)"- Successfully sent %u certificate(s) to server.\n",
      v27,
      (int)v21,
      v19,
      v20,
      (char)v30);
    return 0;
  }
  if ( v17 == 3 )
  {
    if ( qword_235E8 && dword_23618 == 3 )
    {
      v29 = (int)stdout;
      *a8 = qword_235E8;
      *a6 = &unk_23600;
      *v30 = 1;
      sub_DC90(
        v29,
        (unsigned int)"- Successfully sent %u certificate(s) to server.\n",
        1,
        (unsigned int)&unk_23600,
        v19,
        v20,
        (char)v30);
      return 0;
    }
    else
    {
      sub_DC90(
        (int)stdout,
        (unsigned int)"- Could not find a suitable key to send to server\n",
        v18,
        (int)v30,
        v19,
        v20,
        (char)v30);
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    name = gnutls_certificate_type_get_name(v17);
    sub_DC90(
      (int)stdout,
      (unsigned int)"- Could not retrieve unsupported certificate type %s.\n",
      name,
      v23,
      v24,
      v25,
      (char)v30);
    return 0xFFFFFFFFLL;
  }
}


// Function: tls_log_func @ 0x12990
long long tls_log_func(int a1, const char *a2)
{
  return __fprintf_chk(stderr, 1, "%s|<%d>| %s", (const char *)off_22298, a1, a2);
}


// Function: try_save_cert @ 0xa250
unsigned long long try_save_cert(long long a1)
{
  long long peers; // rax
  long long v2; // r12
  FILE *v3; // rbp
  unsigned int i; // ebx
  int v5; // eax
  const char *v7; // rax
  unsigned int v8; // [rsp+Ch] [rbp-4Ch] BYREF
  void *ptr; // [rsp+10h] [rbp-48h] BYREF
  size_t size; // [rsp+18h] [rbp-40h]
  unsigned long long v11; // [rsp+28h] [rbp-30h]

  v11 = __readfsqword(0x28u);
  v8 = 0;
  peers = gnutls_certificate_get_peers(a1, &v8);
  if ( !v8 )
  {
    __fprintf_chk(stderr, 1, "no certificates sent by server!\n");
    exit(1);
  }
  v2 = peers;
  v3 = fopen(qword_95798, "w");
  if ( !v3 )
  {
    __fprintf_chk(stderr, 1, "could not open %s\n", qword_95798);
    exit(1);
  }
  for ( i = 0; v8 > i; ptr = 0 )
  {
    v5 = gnutls_pem_base64_encode2("CERTIFICATE", v2 + 16LL * i, &ptr);
    if ( v5 < 0 )
    {
      v7 = (const char *)gnutls_strerror((unsigned int)v5);
      __fprintf_chk(stderr, 1, "error[%d]: %s\n", 359, v7);
      exit(1);
    }
    ++i;
    fwrite(ptr, (unsigned int)size, 1u, v3);
    gnutls_free(ptr);
  }
  fclose(v3);
  return v11 - __readfsqword(0x28u);
}


// Function: try_save_ocsp_status @ 0xa3d0
unsigned long long try_save_ocsp_status(long long a1)
{
  int v1; // r13d
  const char *v2; // rax
  int v3; // r15d
  FILE *v4; // r14
  unsigned int v5; // r12d
  int v6; // eax
  int v7; // eax
  const char *v9; // rax
  long long v10; // rax
  const char *v11; // [rsp+8h] [rbp-80h]
  int v12; // [rsp+1Ch] [rbp-6Ch] BYREF
  void *ptr; // [rsp+20h] [rbp-68h] BYREF
  size_t size; // [rsp+28h] [rbp-60h]
  void *v15; // [rsp+30h] [rbp-58h] BYREF
  size_t v16; // [rsp+38h] [rbp-50h]
  unsigned long long v17; // [rsp+48h] [rbp-40h]

  v17 = __readfsqword(0x28u);
  v12 = 0;
  gnutls_certificate_get_peers(a1, &v12);
  v1 = v12;
  if ( !v12 )
  {
    __fprintf_chk(stderr, 1, "no certificates sent by server, so can't get OCSP status!\n");
    return v17 - __readfsqword(0x28u);
  }
  v2 = (const char *)qword_957A8;
  if ( (char)word_95736 )
    v2 = qword_957A0;
  v3 = (char)word_95736 == 0;
  v11 = v2;
  if ( (char)word_95736 )
    v1 = 1;
  v4 = fopen(v2, "w");
  if ( !v4 )
  {
    __fprintf_chk(stderr, 1, "could not open %s for writing\n", v11);
LABEL_22:
    exit(1);
  }
  v5 = 0;
  do
  {
    while ( 1 )
    {
      v6 = gnutls_ocsp_status_request_get2(a1, v5, &ptr);
      if ( v6 != -56 )
        break;
      __fprintf_chk(stderr, 1, "no OCSP response for certificate %u\n", v5);
LABEL_9:
      if ( v1 == ++v5 )
        goto LABEL_16;
    }
    if ( v6 < 0 )
    {
      v9 = (const char *)gnutls_strerror((unsigned int)v6);
      __fprintf_chk(stderr, 1, "error getting OCSP response %u: %s\n", v5, v9);
      exit(1);
    }
    if ( !v3 )
    {
      if ( fwrite(ptr, (unsigned int)size, 1u, v4) != 1 )
        goto LABEL_21;
      goto LABEL_9;
    }
    v7 = gnutls_pem_base64_encode2("OCSP RESPONSE", &ptr, &v15);
    if ( v7 < 0 )
    {
      v10 = gnutls_strerror((unsigned int)v7);
      __fprintf_chk(stderr, 1, "error allocating PEM OCSP response: %s\n", v10);
      goto LABEL_22;
    }
    if ( fwrite(v15, (unsigned int)v16, 1u, v4) != 1 )
    {
LABEL_21:
      __fprintf_chk(stderr, 1, "writing to %s failed\n", v11);
      goto LABEL_22;
    }
    ++v5;
    gnutls_free(v15);
  }
  while ( v1 != v5 );
LABEL_16:
  if ( fclose(v4) )
    perror("failed to close OCSP save file");
  return v17 - __readfsqword(0x28u);
}


// Function: cert_verify_ocsp @ 0xa620
long long cert_verify_ocsp(long long a1)
{
  unsigned int v1; // ebx
  int v2; // r15d
  int v3; // ebp
  int v4; // eax
  int v5; // eax
  int v6; // r15d
  int v7; // eax
  int v8; // eax
  int issuer; // eax
  bool v10; // r12
  long long result; // rax
  int v12; // eax
  int v13; // eax
  const char *v14; // rax
  long long v15; // rax
  long long v16; // rax
  const char *v17; // rax
  const char *v18; // rax
  const char *v19; // rax
  long long peers; // [rsp+0h] [rbp-A8h]
  unsigned int v21; // [rsp+Ch] [rbp-9Ch]
  unsigned int v22; // [rsp+1Ch] [rbp-8Ch] BYREF
  long long v23; // [rsp+20h] [rbp-88h] BYREF
  long long v24; // [rsp+28h] [rbp-80h] BYREF
  void *ptr; // [rsp+30h] [rbp-78h] BYREF
  char *v26; // [rsp+40h] [rbp-68h] BYREF
  unsigned int v27; // [rsp+48h] [rbp-60h]
  char v28; // [rsp+50h] [rbp-58h] BYREF
  unsigned long long v29; // [rsp+68h] [rbp-40h]

  v29 = __readfsqword(0x28u);
  v22 = 0;
  v26 = &v28;
  v27 = 23;
  peers = gnutls_certificate_get_peers(a1, &v22);
  if ( !v22 )
  {
    __fprintf_chk(stderr, 1, "No certificates found!\n");
    return 0;
  }
  v21 = 0;
  v1 = 0;
  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v7 = gnutls_x509_crt_init(&v23);
    if ( v7 < 0 )
      break;
    v8 = gnutls_x509_crt_import(v23, peers + 16LL * v1, 0);
    if ( v8 < 0 )
    {
      v15 = gnutls_strerror((unsigned int)v8);
      __fprintf_chk(stderr, 1, "Decoding error: %s\n", v15);
      goto LABEL_35;
    }
    if ( v3 )
      gnutls_x509_crt_deinit(v24);
    v3 = 0;
    issuer = gnutls_certificate_get_issuer(qword_23708, v23, &v24, 0);
    if ( issuer < 0 )
    {
      if ( v22 - v1 <= 1 )
      {
        v10 = v21 != 0;
        if ( !v1 )
        {
          v17 = (const char *)gnutls_strerror((unsigned int)issuer);
          __fprintf_chk(stderr, 1, "Cannot find issuer: %s\n", v17);
        }
        goto LABEL_18;
      }
      v12 = gnutls_x509_crt_init(&v24);
      if ( v12 < 0 )
      {
        v18 = (const char *)gnutls_strerror((unsigned int)v12);
        __fprintf_chk(stderr, 1, "Memory error: %s\n", v18);
        v10 = v21 != 0;
LABEL_18:
        gnutls_x509_crt_deinit(v23);
        goto LABEL_19;
      }
      v13 = gnutls_x509_crt_import(v24, peers + 16LL * (v1 + 1), 0);
      if ( v13 < 0 )
      {
        v19 = (const char *)gnutls_strerror((unsigned int)v13);
        __fprintf_chk(stderr, 1, "Decoding error: %s\n", v19);
        gnutls_x509_crt_deinit(v24);
        v10 = v21 != 0;
        goto LABEL_18;
      }
      v3 = 1;
    }
    v4 = gnutls_rnd(0, v26, v27);
    if ( v4 < 0 )
    {
      v16 = gnutls_strerror((unsigned int)v4);
      __fprintf_chk(stderr, 1, "gnutls_rnd: %s", v16);
LABEL_35:
      v10 = v21 != 0;
LABEL_36:
      if ( v3 )
        gnutls_x509_crt_deinit(v24);
      goto LABEL_18;
    }
    v5 = sub_13D10(0);
    if ( v5 == -56 )
      goto LABEL_8;
    if ( v5 < 0 )
    {
      __fprintf_chk(stderr, 1, "Cannot contact OCSP server\n");
      v10 = v21 != 0;
      goto LABEL_36;
    }
    v6 = sub_14280(v23, v24, &ptr, &v26, (unsigned int)dword_2236C);
    free(ptr);
    if ( v6 != 1 )
    {
      if ( !v6 )
      {
        v10 = 0;
        goto LABEL_36;
      }
LABEL_8:
      if ( v22 <= ++v1 )
        goto LABEL_23;
      goto LABEL_9;
    }
    ++v21;
    if ( v22 <= ++v1 )
    {
LABEL_23:
      if ( v3 )
        gnutls_x509_crt_deinit(v24);
      v10 = v21 != 0;
      goto LABEL_18;
    }
LABEL_9:
    v2 = 1;
    gnutls_x509_crt_deinit(v23);
  }
  v14 = (const char *)gnutls_strerror((unsigned int)v7);
  __fprintf_chk(stderr, 1, "Memory error: %s\n", v14);
  if ( v3 )
    gnutls_x509_crt_deinit(v24);
  v10 = v21 != 0;
  if ( v2 )
    goto LABEL_18;
LABEL_19:
  result = 0xFFFFFFFFLL;
  if ( v10 )
    return v21;
  return result;
}


// Function: cert_verify_callback @ 0xaa30
long long cert_verify_callback(long long a1)
{
  char v1; // bl
  unsigned int v2; // r12d
  char v3; // r14
  char v4; // r13
  const char *v5; // r15
  int v7; // edx
  int v8; // ecx
  int v9; // r8d
  int v10; // r9d
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // r8d
  int v15; // r9d
  long long peers; // rbp
  char *v17; // rsi
  const char *v18; // r12
  int v19; // eax
  int v20; // eax
  const char *v21; // rax
  const char *v22; // rax
  char v23[4]; // [rsp+4h] [rbp-44h] BYREF
  unsigned long long v24; // [rsp+8h] [rbp-40h]

  v1 = byte_958A3;
  v2 = (unsigned char)byte_958A2;
  v24 = __readfsqword(0x28u);
  v3 = byte_958A4;
  v4 = byte_958A6;
  v5 = qword_223A0;
  if ( byte_958A3 )
    v2 = (unsigned char)byte_958A3;
  if ( !byte_9572C )
  {
    if ( !byte_95735 )
      goto LABEL_5;
LABEL_11:
    sub_A250(a1);
    if ( !word_95736 )
      goto LABEL_6;
    goto LABEL_12;
  }
  v5 = qword_95780;
  sub_11180(qword_95780, 0, 0);
  if ( byte_95735 )
    goto LABEL_11;
LABEL_5:
  if ( !word_95736 )
    goto LABEL_6;
LABEL_12:
  sub_A3D0(a1);
LABEL_6:
  sub_FC00(a1, (unsigned int)dword_2236C, (unsigned int)dword_22368);
  if ( v4 )
  {
    if ( (unsigned int)sub_DD70(a1, v5, "1.3.6.1.5.5.7.3.1") )
    {
      if ( byte_958A7 && !(unsigned int)gnutls_ocsp_status_request_is_checked(a1, 0) )
      {
        v11 = sub_A620(a1);
        if ( v11 == -1 )
        {
          sub_DC90(
            (int)stdout,
            (unsigned int)"*** Verifying (with OCSP) server certificate chain failed...\n",
            v12,
            v13,
            v14,
            v15);
          if ( !(dword_223C4 | v2) )
            return (unsigned int)-1;
        }
        else if ( v11 )
        {
          sub_DC90((int)stdout, (unsigned int)"*** OCSP: verified %d certificate(s).\n", v11, v13, v14, v15);
        }
        else
        {
          sub_DC90((int)stdout, (unsigned int)"*** OCSP: nothing to check.\n", v12, v13, v14, v15);
        }
      }
    }
    else
    {
      sub_DC90((int)stdout, (unsigned int)"*** PKI verification of server certificate failed...\n", v7, v8, v9, v10);
      if ( !(dword_223C4 | v2) )
        return (unsigned int)-1;
    }
  }
  if ( v3 )
  {
    __fprintf_chk(stderr, 1, "*** DANE error: GnuTLS is not compiled with DANE support.\n");
    if ( !(dword_223C4 | v2) )
      return (unsigned int)-1;
  }
  if ( v2 )
  {
    peers = gnutls_certificate_get_peers(a1, v23);
    if ( peers )
    {
      v17 = "udp";
      if ( !dword_223B8 )
        v17 = "tcp";
      v18 = (const char *)sub_11920(nptr, v17);
      v19 = gnutls_verify_stored_pubkey(0, 0, v5, v18, 1, peers, 0);
      if ( v19 == -49 )
      {
        __fprintf_chk(stderr, 1, "Host %s (%s) has never been contacted before.\n", v5, v18);
        __fprintf_chk(stderr, 1, "Its certificate is valid for %s.\n", v5);
        if ( !v1 && sub_9ED0("Are you sure you want to trust it? (y/N): ") )
          goto LABEL_31;
      }
      else if ( v19 == -60 )
      {
        __fprintf_chk(stderr, 1, "Warning: host %s is known and it is associated with a different key.\n", v5);
        __fprintf_chk(
          stderr,
          1,
          "It might be that the server has multiple keys, or an attacker replaced the key to eavesdrop this connection .\n");
        __fprintf_chk(stderr, 1, "Its certificate is valid for %s.\n", v5);
        if ( !v1 && sub_9ED0("Do you trust the received key? (y/N): ") )
          goto LABEL_31;
      }
      else
      {
        if ( v19 >= 0 )
        {
          if ( !v19 )
            return 0;
LABEL_31:
          v20 = gnutls_store_pubkey(0, 0, v5, v18, 1, peers, 0, 0);
          if ( v20 < 0 )
          {
            v21 = (const char *)gnutls_strerror((unsigned int)v20);
            __fprintf_chk(stderr, 1, "Could not store key: %s\n", v21);
          }
          return 0;
        }
        v22 = (const char *)gnutls_strerror((unsigned int)v19);
        __fprintf_chk(stderr, 1, "gnutls_verify_stored_pubkey: %s\n", v22);
      }
    }
    else
    {
      __fprintf_chk(stderr, 1, "Cannot obtain peer's certificate!\n");
    }
    return (unsigned int)-1;
  }
  return v2;
}


// Function: print_priority_list @ 0xae60
long long print_priority_list()
{
  unsigned int v0; // ebp
  unsigned int v1; // ebx
  int v2; // eax
  int v3; // ecx
  int v4; // r8d
  int v5; // r9d
  long long v6; // rax
  int v7; // ecx
  int v8; // r8d
  int v9; // r9d
  int v10; // edx
  int v11; // ecx
  int v12; // r8d
  int v13; // r9d
  unsigned int v14; // ebp
  unsigned int v15; // ebx
  char *v16; // rax
  int v17; // ecx
  int v18; // r8d
  int v19; // r9d
  int v20; // edx
  int v21; // ecx
  int v22; // r8d
  int v23; // r9d

  v0 = 0;
  v1 = 0;
  v2 = gnutls_check_version(0);
  sub_DC90((int)stdout, (unsigned int)"Priority strings in GnuTLS %s:\n", v2, v3, v4, v5);
  fputs("\t", stdout);
  while ( 1 )
  {
    v6 = gnutls_priority_string_list(v0, 1);
    if ( !v6 )
      break;
    v1 += sub_DC90((int)stdout, (unsigned int)"%s ", v6, v7, v8, v9);
    if ( v1 > 0x40 )
    {
      v1 = 0;
      sub_DC90((int)stdout, (unsigned int)"\n\t", v10, v11, v12, v13);
    }
    ++v0;
  }
  v14 = 0;
  v15 = 0;
  sub_DC90((int)stdout, (unsigned int)"\n\nSpecial strings:\n", 0, v7, v8, v9);
  fputs("\t", stdout);
  while ( 1 )
  {
    v16 = (char *)gnutls_priority_string_list(v15, 2);
    if ( !v16 )
      break;
    if ( *v16 )
    {
      v14 += sub_DC90((int)stdout, (unsigned int)"%%%s ", (int)v16, v17, v18, v19);
      if ( v14 > 0x40 )
      {
        v14 = 0;
        sub_DC90((int)stdout, (unsigned int)"\n\t", v20, v21, v22, v23);
      }
    }
    ++v15;
  }
  return sub_DC90((int)stdout, (unsigned int)"\n", 0, v17, v18, v19);
}


// Function: psk_callback @ 0xafb0
long long psk_callback(long long a1, const char **a2, long long a3)
{
  const char *hint; // r12
  int v5; // edx
  int v6; // ecx
  int v7; // r8d
  int v8; // r9d
  int v9; // edx
  int v10; // ecx
  int v11; // r8d
  int v12; // r9d
  int v13; // edx
  int v14; // ecx
  int v15; // r8d
  int v16; // r9d
  long long v17; // rax
  char *v18; // rax
  long long v19; // rax
  long long v20; // r14
  int v21; // eax
  unsigned int v22; // r13d
  int v23; // eax
  bool v24; // zf
  char *v26; // r13
  char *v27; // rax
  long long v28; // rax
  char *v29; // rdi
  int v30; // eax
  const char *v31; // rax
  const char *v32; // rdx
  const char *v33; // rax
  char *lineptr; // [rsp+8h] [rbp-90h] BYREF
  size_t n; // [rsp+10h] [rbp-88h] BYREF
  unsigned int v36; // [rsp+18h] [rbp-80h]
  char v37[56]; // [rsp+20h] [rbp-78h] BYREF
  unsigned long long v38; // [rsp+58h] [rbp-40h]

  v38 = __readfsqword(0x28u);
  hint = (const char *)gnutls_psk_client_get_hint();
  sub_DC90((int)stdout, (unsigned int)"- PSK client callback. ", v5, v6, v7, v8);
  if ( hint )
    sub_DC90((int)stdout, (unsigned int)"PSK hint '%s'\n", (int)hint, v10, v11, v12);
  else
    sub_DC90((int)stdout, (unsigned int)"No PSK hint\n", v9, v10, v11, v12);
  if ( byte_95744 )
  {
    v17 = gnutls_strdup(qword_95810);
    *a2 = (const char *)v17;
  }
  else
  {
    lineptr = 0;
    sub_DC90((int)stdout, (unsigned int)"Enter PSK identity: ", v13, v14, v15, v16);
    fflush(stdout);
    if ( (unsigned int)getline(&lineptr, &n, stdin) == -1 || (v26 = lineptr) == 0 )
    {
      v32 = "No username given, aborting...\n";
LABEL_24:
      v22 = -32;
      __fprintf_chk(stderr, 1, v32);
      return v22;
    }
    v27 = &v26[strlen(lineptr) - 1];
    if ( *v27 == 10 )
    {
      *v27 = 0;
      v26 = lineptr;
      v27 = &v26[strlen(lineptr) - 1];
    }
    if ( *v27 == 13 )
    {
      *v27 = 0;
      v26 = lineptr;
    }
    v28 = gnutls_strdup(v26);
    v29 = lineptr;
    *a2 = (const char *)v28;
    free(v29);
    v17 = (long long)*a2;
  }
  if ( !v17 )
    return (unsigned int)-25;
  v18 = getpass("Enter key: ");
  if ( !v18 )
  {
    v32 = "No key given, aborting...\n";
    goto LABEL_24;
  }
  n = (size_t)v18;
  v36 = strlen(v18);
  lineptr = (char *)((v36 >> 1) + 1);
  v19 = gnutls_malloc();
  v20 = v19;
  if ( !v19 )
    return (unsigned int)-25;
  v21 = gnutls_hex_decode(&n, v19, &lineptr);
  v22 = v21;
  if ( v21 < 0 )
  {
    v31 = (const char *)gnutls_strerror((unsigned int)v21);
    __fprintf_chk(stderr, 1, "Error deriving password: %s\n", v31);
    gnutls_free(v20);
    gnutls_free(*a2);
    *a2 = 0;
  }
  else
  {
    v23 = (int)lineptr;
    v22 = 0;
    v24 = byte_95720 == 0;
    *(long long *)a3 = v20;
    *(int *)(a3 + 8) = v23;
    if ( !v24 )
    {
      lineptr = (char *)(&qword_28 + 1);
      v30 = gnutls_hex_encode(a3, v37, &lineptr);
      if ( v30 < 0 )
      {
        v33 = (const char *)gnutls_strerror((unsigned int)v30);
        __fprintf_chk(stderr, 1, "Error in hex encoding: %s\n", v33);
        exit(1);
      }
      __fprintf_chk(stderr, 1, "PSK username: %s\n", *a2);
      __fprintf_chk(stderr, 1, "PSK hint: %s\n", hint);
      __fprintf_chk(stderr, 1, "PSK key: %s\n", v37);
    }
  }
  return v22;
}


// Function: load_priv_key @ 0xb2f0
unsigned long long load_priv_key(long long *a1, long long a2)
{
  int v2; // eax
  int v3; // eax
  int v5; // eax
  long long v6; // rax
  long long v7; // rax
  long long v8; // rax
  long long v9; // [rsp+0h] [rbp-38h] BYREF
  int v10; // [rsp+8h] [rbp-30h]
  unsigned long long v11; // [rsp+18h] [rbp-20h]

  v11 = __readfsqword(0x28u);
  v9 = 0;
  v10 = 0;
  v2 = gnutls_privkey_init();
  if ( v2 < 0 )
  {
    v7 = gnutls_strerror((unsigned int)v2);
    __fprintf_chk(stderr, 1, "*** Error initializing key: %s\n", v7);
    goto LABEL_9;
  }
  gnutls_privkey_set_pin_function(*a1, &sub_F410, 0);
  if ( (unsigned int)gnutls_url_is_supported(a2) )
  {
    v5 = gnutls_privkey_import_url(*a1, a2, 0);
    if ( v5 >= 0 )
      return v11 - __readfsqword(0x28u);
    v6 = gnutls_strerror((unsigned int)v5);
    __fprintf_chk(stderr, 1, "*** Error loading url: %s\n", v6);
LABEL_9:
    exit(1);
  }
  if ( (int)gnutls_load_file(a2, &v9) < 0 )
  {
    __fprintf_chk(stderr, 1, "*** Error loading key file.\n");
    exit(1);
  }
  v3 = gnutls_privkey_import_x509_raw(*a1, &v9, (unsigned int)dword_23740, 0, 0);
  if ( v3 < 0 )
  {
    v8 = gnutls_strerror((unsigned int)v3);
    __fprintf_chk(stderr, 1, "*** Error importing key: %s\n", v8);
    goto LABEL_9;
  }
  gnutls_free(v9);
  return v11 - __readfsqword(0x28u);
}


// Function: load_x509_keys @ 0xb430
unsigned long long load_x509_keys()
{
  int v0; // eax
  char *v1; // rbp
  long long i; // rbx
  int v3; // eax
  long long v4; // rdi
  int v5; // ecx
  int v6; // r8d
  int v7; // r9d
  const char *v9; // rax
  FILE *v10; // rbp
  const char *v11; // rax
  int v12; // [rsp+Ch] [rbp-7Ch] BYREF
  long long v13; // [rsp+10h] [rbp-78h] BYREF
  int v14; // [rsp+18h] [rbp-70h]
  long long v15[7]; // [rsp+20h] [rbp-68h] BYREF
  unsigned long long v16; // [rsp+58h] [rbp-30h]

  v16 = __readfsqword(0x28u);
  v14 = 0;
  v13 = 0;
  if ( qword_22348 && qword_22350 )
  {
    if ( (int)gnutls_load_file(qword_22348, &v13) < 0 )
    {
      __fprintf_chk(stderr, 1, "*** Error loading cert file.\n");
      exit(1);
    }
    v12 = 6;
    v0 = gnutls_x509_crt_list_import(v15, &v12, &v13, (unsigned int)dword_23740, 1);
    if ( v0 < 0 )
    {
      v10 = stderr;
      if ( v0 == -51 )
      {
        __fprintf_chk(stderr, 1, "*** Error loading cert file: Too many certs %d\n", v12);
      }
      else
      {
        v11 = (const char *)gnutls_strerror((unsigned int)v0);
        __fprintf_chk(v10, 1, "*** Error loading cert file: %s\n", v11);
      }
      exit(1);
    }
    dword_23700 = v0;
    v1 = (char *)&unk_23640;
    for ( i = 0; dword_23700 > (unsigned int)i; ++i )
    {
      v3 = gnutls_pcert_import_x509(v1, v15[i], 0);
      if ( v3 < 0 )
      {
        v9 = (const char *)gnutls_strerror((unsigned int)v3);
        __fprintf_chk(stderr, 1, "*** Error importing crt to pcert: %s\n", v9);
        exit(1);
      }
      v4 = v15[i];
      v1 += 32;
      gnutls_x509_crt_deinit(v4);
    }
    gnutls_free(v13);
    v13 = 0;
    sub_B2F0(&qword_23620, qword_22350);
    sub_DC90((int)stdout, (unsigned int)"Processed %d client X.509 certificates...\n", dword_23700, v5, v6, v7);
  }
  return v16 - __readfsqword(0x28u);
}


// Function: load_rawpk_keys @ 0xb610
unsigned long long load_rawpk_keys()
{
  int v0; // eax
  int v1; // ecx
  int v2; // r8d
  int v3; // r9d
  const char *v5; // rax
  long long v6; // [rsp+0h] [rbp-28h] BYREF
  int v7; // [rsp+8h] [rbp-20h]
  unsigned long long v8; // [rsp+18h] [rbp-10h]

  v8 = __readfsqword(0x28u);
  v6 = 0;
  v7 = 0;
  if ( qword_22328 && qword_22330 )
  {
    if ( (int)gnutls_load_file(qword_22328, &v6) < 0 )
    {
      __fprintf_chk(stderr, 1, "*** Error loading cert file.\n");
      exit(1);
    }
    v0 = gnutls_pcert_import_rawpk_raw(&unk_23600, &v6, (unsigned int)dword_23740, 0, 0);
    if ( v0 < 0 )
    {
      v5 = (const char *)gnutls_strerror((unsigned int)v0);
      __fprintf_chk(stderr, 1, "*** Error importing rawpk to pcert: %s\n", v5);
      exit(1);
    }
    gnutls_free(v6);
    v6 = 0;
    sub_B2F0(&qword_235E8, qword_22330);
    sub_DC90((int)stdout, (unsigned int)"Processed %d client raw public key pair...\n", 1, v1, v2, v3);
  }
  return v8 - __readfsqword(0x28u);
}


// Function: init_global_tls_stuff @ 0xb730
unsigned long long init_global_tls_stuff()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // r9d
  int v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // r8d
  int v7; // r9d
  int v8; // eax
  const char *v9; // rax
  long long v11; // rax
  long long v12; // rax
  long long v13; // [rsp+0h] [rbp-18h] BYREF
  unsigned long long v14; // [rsp+8h] [rbp-10h]

  v14 = __readfsqword(0x28u);
  if ( (int)gnutls_certificate_allocate_credentials(&qword_23708) < 0 )
  {
    __fprintf_chk(stderr, 1, "Certificate allocation memory error\n");
LABEL_30:
    exit(1);
  }
  gnutls_certificate_set_pin_function(qword_23708, &sub_F410, 0);
  gnutls_certificate_set_verify_flags(qword_23708, (unsigned int)dword_223A8);
  gnutls_certificate_set_flags(qword_23708, 8);
  if ( (int)gnutls_x509_trust_list_init(&v13, 0) < 0 )
  {
    __fprintf_chk(stderr, 1, "Trust list allocation memory error\n");
    goto LABEL_30;
  }
  gnutls_certificate_set_trust_list(qword_23708, v13, 0);
  if ( qword_22340 )
  {
    v3 = gnutls_x509_trust_list_add_trust_file(v13, qword_22340, 0, (unsigned int)dword_23740, 2, 0);
  }
  else
  {
    v3 = 0;
    if ( dword_223C4 )
      goto LABEL_6;
    v3 = gnutls_x509_trust_list_add_system_trust(v13, 2, 0);
    if ( v3 == -1250 )
    {
      __fprintf_chk(stderr, 1, "Warning: this system doesn't support a default trust store\n");
      v3 = 0;
      goto LABEL_6;
    }
  }
  if ( v3 < 0 )
  {
    v12 = gnutls_strerror((unsigned int)v3);
    __fprintf_chk(stderr, 1, "Error setting the x509 trust file: %s\n", v12);
    goto LABEL_33;
  }
LABEL_6:
  sub_DC90((int)stdout, (unsigned int)"Processed %d CA certificate(s).\n", v3, v0, v1, v2);
  if ( byte_958E2 )
    gnutls_x509_trust_list_set_getissuer_function(v13, sub_C970);
  if ( qword_22338 )
  {
    v4 = gnutls_certificate_set_x509_crl_file(qword_23708, qword_22338, (unsigned int)dword_23740);
    if ( v4 >= 0 )
    {
      sub_DC90((int)stdout, (unsigned int)"Processed %d CRL(s).\n", v4, v5, v6, v7);
      goto LABEL_11;
    }
    v11 = gnutls_strerror((unsigned int)v4);
    __fprintf_chk(stderr, 1, "Error setting the x509 CRL file: %s\n", v11);
LABEL_33:
    exit(1);
  }
LABEL_11:
  sub_B430();
  sub_B610();
  if ( qword_22358 && qword_22360 )
  {
    if ( (int)gnutls_srp_allocate_client_credentials(&qword_23720) < 0 )
      __fprintf_chk(stderr, 1, "SRP authentication error\n");
    gnutls_srp_set_client_credentials_function(qword_23720, sub_9E80);
  }
  if ( (int)gnutls_psk_allocate_client_credentials(&qword_23718) < 0 )
    __fprintf_chk(stderr, 1, "PSK authentication error\n");
  if ( qword_22320 && qword_22310 )
  {
    v8 = gnutls_psk_set_client_credentials(qword_23718, qword_22320, &qword_22310, 1);
    if ( v8 < 0 )
    {
      v9 = (const char *)gnutls_strerror((unsigned int)v8);
      __fprintf_chk(stderr, 1, "Error setting the PSK credentials: %s\n", v9);
    }
  }
  else
  {
    gnutls_psk_set_client_credentials_function(qword_23718, sub_AFB0);
  }
  if ( (int)gnutls_anon_allocate_client_credentials(&qword_23710) < 0 )
    __fprintf_chk(stderr, 1, "Anonymous authentication error\n");
  return v14 - __readfsqword(0x28u);
}


// Function: try_resume @ 0xba70
long long try_resume(long long a1)
{
  long long v2; // rdi
  int v3; // edx
  int v4; // ecx
  int v5; // r8d
  int v6; // r9d
  unsigned int v7; // ebp
  int v8; // edx
  int v9; // ecx
  int v10; // r8d
  int v11; // r9d
  FILE *v12; // rax
  FILE *v13; // r13
  int v14; // edx
  int v15; // ecx
  int v16; // r8d
  int v17; // r9d
  int v18; // edx
  int v19; // ecx
  int v20; // r8d
  int v21; // r9d
  long long v23; // rax
  long long v24; // [rsp+8h] [rbp-60h] BYREF
  long long v25; // [rsp+10h] [rbp-58h] BYREF
  int v26; // [rsp+18h] [rbp-50h]
  long long v27; // [rsp+20h] [rbp-48h] BYREF
  int v28; // [rsp+28h] [rbp-40h]
  unsigned long long v29; // [rsp+38h] [rbp-30h]

  v2 = *(long long *)(a1 + 8);
  v29 = __readfsqword(0x28u);
  v26 = 0;
  v25 = 0;
  v27 = 0;
  v28 = 0;
  if ( (unsigned int)gnutls_session_is_resumed(v2) )
  {
    v23 = *(long long *)(a1 + 232);
    *(long long *)(a1 + 232) = 0;
    v25 = v23;
    v26 = *(int *)(a1 + 240);
  }
  else
  {
    do
    {
      if ( (int)gnutls_session_get_data2(*(long long *)(a1 + 8), &v25) < 0 )
        v25 = 0;
      if ( (unsigned int)gnutls_protocol_get_version(*(long long *)(a1 + 8)) != 5 )
        break;
      if ( (gnutls_session_get_flags(*(long long *)(a1 + 8)) & 0x80u) != 0LL )
        break;
      v3 = dword_223AC;
    }
    while ( dword_223AC );
  }
  v7 = 68;
  sub_DC90((int)stdout, (unsigned int)"- Disconnecting\n", v3, v4, v5, v6);
  sub_11040(a1, 1);
  sub_11180(qword_223A0, nptr, 0x20u);
  sub_DC90(
    (int)stdout,
    (unsigned int)"\n\n- Connecting again- trying to resume previous session\n",
    v8,
    v9,
    v10,
    v11);
  if ( !byte_9572E )
    v7 = dword_22370 == 0 ? 64 : 66;
  if ( dword_223B8 )
    v7 |= 1u;
  if ( byte_95729 )
  {
    v12 = fopen(qword_95770, "r");
    v13 = v12;
    if ( !v12 )
    {
      __fprintf_chk(stderr, 1, "could not open %s\n", qword_95770);
      exit(1);
    }
    v27 = sub_15860(v12, 0, &v24);
    v28 = v24;
    fclose(v13);
  }
  sub_11250(a1, qword_223A0, nptr, qword_95788, v7, "Connecting to", &v25, &v27, 0, 0);
  sub_DC90((int)stdout, (unsigned int)"- Resume Handshake was completed\n", v14, v15, v16, v17);
  if ( (unsigned int)gnutls_session_is_resumed(*(long long *)(a1 + 8)) )
    sub_DC90((int)stdout, (unsigned int)"*** This is a resumed session\n", v18, v19, v20, v21);
  return 0;
}


// Function: print_other_info @ 0xbcd0
unsigned long long print_other_info(long long a1)
{
  long long peers; // rax
  unsigned int v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // r14d
  int v6; // ecx
  int v7; // r8d
  int v8; // r9d
  const char *v10; // rax
  const char *v11; // rax
  unsigned int v12; // [rsp+4h] [rbp-64h] BYREF
  long long v13; // [rsp+8h] [rbp-60h] BYREF
  long long v14; // [rsp+10h] [rbp-58h] BYREF
  int v15; // [rsp+18h] [rbp-50h]
  long long v16[3]; // [rsp+20h] [rbp-48h] BYREF
  unsigned long long v17; // [rsp+38h] [rbp-30h]

  v17 = __readfsqword(0x28u);
  peers = gnutls_certificate_get_peers(a1, &v12);
  if ( byte_958A1 == 1 && peers && v12 )
  {
    v2 = 0;
    while ( 1 )
    {
      while ( (int)gnutls_ocsp_status_request_get2(a1, v2, &v14) < 0 )
      {
        v14 = 0;
        ++v2;
        v15 = 0;
        if ( v12 <= v2 )
          return v17 - __readfsqword(0x28u);
      }
      v3 = gnutls_ocsp_resp_init(&v13);
      if ( v3 < 0 )
      {
        v10 = (const char *)gnutls_strerror((unsigned int)v3);
        __fprintf_chk(stderr, 1, "ocsp_resp_init: %s\n", v10);
        return v17 - __readfsqword(0x28u);
      }
      v4 = gnutls_ocsp_resp_import(v13, &v14);
      if ( v4 < 0 )
        break;
      v5 = gnutls_ocsp_resp_print(v13, dword_22368 == 0, v16);
      gnutls_ocsp_resp_deinit(v13);
      if ( v5 >= 0 )
      {
        sub_DC90((int)stdout, (unsigned int)"%s", v16[0], v6, v7, v8);
        gnutls_free(v16[0]);
      }
      if ( v12 <= ++v2 )
        return v17 - __readfsqword(0x28u);
    }
    v11 = (const char *)gnutls_strerror((unsigned int)v4);
    __fprintf_chk(stderr, 1, "importing response: %s\n", v11);
  }
  return v17 - __readfsqword(0x28u);
}


// Function: check_net_or_keyboard_input @ 0xbe50
long long check_net_or_keyboard_input(int *a1, int a2)
{
  fd_set *p_readfds; // rax
  long long v4; // rax
  int v5; // r15d
  bool v6; // zf
  int v7; // r15d
  char v9; // r15
  int v10; // eax
  long long v11; // rax
  FILE *v12; // rdi
  int v13; // eax
  int v14; // eax
  __fd_mask v15; // [rsp+8h] [rbp-E0h]
  struct timeval timeout; // [rsp+10h] [rbp-D8h] BYREF
  fd_set readfds; // [rsp+20h] [rbp-C8h] BYREF
  char v18; // [rsp+A0h] [rbp-48h] BYREF
  unsigned long long v19; // [rsp+A8h] [rbp-40h]

  v19 = __readfsqword(0x28u);
  while ( 1 )
  {
    p_readfds = &readfds;
    do
    {
      p_readfds->fds_bits[0] = 0;
      p_readfds = (fd_set *)((char *)p_readfds + 8);
    }
    while ( &v18 != (char *)p_readfds );
    v4 = __fdelt_chk(*a1);
    v5 = *a1;
    readfds.fds_bits[v4] |= 1LL << *a1;
    if ( !a2 )
    {
      v9 = fileno(stdin);
      v10 = fileno(stdin);
      v11 = __fdelt_chk(v10);
      v12 = stdin;
      readfds.fds_bits[v11] |= 1LL << v9;
      v13 = fileno(v12);
      v5 = *a1;
      if ( v13 > *a1 )
        v5 = fileno(stdin);
    }
    timeout.tv_sec = 2;
    v6 = a1[4] == 1;
    timeout.tv_usec = 0;
    if ( v6 && gnutls_record_check_pending(*((long long *)a1 + 1)) )
      return 2;
    v7 = select(v5 + 1, &readfds, 0, 0, &timeout);
    if ( v7 < 0 )
      return 0;
    if ( (readfds.fds_bits[__fdelt_chk(*a1)] & (1LL << *a1)) != 0 )
      return 2;
    if ( a2 )
      break;
    v14 = fileno(stdin);
    v15 = readfds.fds_bits[__fdelt_chk(v14)];
    if ( ((1LL << fileno(stdin)) & v15) != 0 )
      return 1;
    if ( v7 )
      return 0;
  }
  if ( v7 )
    return 0;
  return 3;
}


// Function: parse_for_inline_commands_in_buffer @ 0xc050
long long parse_for_inline_commands_in_buffer(char *src, size_t a2, long long a3)
{
  size_t v3; // rcx
  char *v4; // r15
  long long v5; // rbx
  signed long long v6; // r14
  size_t v7; // rbp
  size_t v8; // r12
  const char *v9; // r12
  signed long long v10; // rbp
  char *v11; // r13
  char v12; // r9
  signed long long v13; // rax
  char v14; // dl
  char v16; // r14
  unsigned int v17; // r13d
  const char *v18; // rbx
  const char *v19; // rdi
  signed long long v20; // rax
  size_t v21; // rdx
  signed long long v22; // r15
  int v23; // eax
  size_t v24; // [rsp+0h] [rbp-98h]
  size_t v25; // [rsp+0h] [rbp-98h]
  signed long long v26; // [rsp+18h] [rbp-80h]
  long long v28; // [rsp+28h] [rbp-70h]
  char *v29; // [rsp+30h] [rbp-68h]
  size_t n; // [rsp+38h] [rbp-60h]
  char v31[24]; // [rsp+40h] [rbp-58h] BYREF
  unsigned long long v32; // [rsp+58h] [rbp-40h]

  v3 = a2;
  v4 = src;
  v5 = a3;
  v6 = *(long long *)(a3 + 32);
  v32 = __readfsqword(0x28u);
  *(int *)(a3 + 24) = 0;
  *(int *)(a3 + 16) = 0;
  if ( v6 )
  {
    if ( v6 + a2 <= 0x14 )
    {
      v7 = a2;
      v8 = a2;
    }
    else
    {
      v7 = 20 - v6;
      v8 = 20 - v6;
    }
    memcpy((void *)(a3 + v6 + 40), src, v8);
    v6 = *(long long *)(v5 + 32);
    *(long long *)(v5 + 8) = &src[v8];
    v9 = (const char *)(v5 + 40);
    v3 = a2;
    v10 = v6 + v7;
    *(long long *)(v5 + 32) = v10;
  }
  else
  {
    v10 = a2;
    *(long long *)(a3 + 8) = &src[a2];
    if ( !src )
      __assert_fail("local_buffer_ptr != NULL", "cli.c", 0x456u, "parse_for_inline_commands_in_buffer");
    v9 = src;
  }
  v11 = (char *)qword_23728;
  *(long long *)v5 = v9;
  v12 = *v11;
  if ( *v9 == *v11 && *(int *)(v5 + 20) )
  {
    n = v3;
    v26 = v6;
    v16 = v12;
    v29 = v11;
    v17 = 0;
    v28 = v5;
    v18 = aResume;
    while ( 1 )
    {
      v19 = v18;
      if ( v16 != 94 )
      {
        __strcpy_chk(v31, v18, 20);
        v31[strlen(v18)] = 0;
        v31[0] = v16;
        v19 = v31;
        v31[strlen(v18) - 2] = v16;
      }
      v20 = strlen(v19);
      v21 = v10;
      v22 = v20;
      if ( v20 <= v10 )
        v21 = v20;
      v24 = v21;
      if ( !strncmp(v19, v9, v21) )
        break;
      ++v17;
      v18 += 24;
      if ( v17 == 4 )
      {
        v6 = v26;
        v11 = v29;
        v4 = src;
        v5 = v28;
        goto LABEL_8;
      }
    }
    if ( v22 == v24 )
    {
      *(long long *)(v28 + 8) = &src[v22 - v26];
      v23 = *((int *)&unk_20040 + 6 * v17);
      *(long long *)(v28 + 32) = 0;
      *(int *)(v28 + 16) = v23;
    }
    else
    {
      v25 = n;
      memcpy((void *)(v28 + *(long long *)(v28 + 32) + 40), src, n);
      *(long long *)(v28 + 32) += v25;
    }
    return 1;
  }
  else
  {
LABEL_8:
    v13 = v6;
    if ( v10 > v6 )
    {
      while ( 1 )
      {
        v14 = v9[v13];
        if ( v13 )
        {
          if ( *v11 == v14 && *(int *)(v5 + 20) )
            break;
        }
        ++v13;
        *(int *)(v5 + 20) = v14 == 10;
        if ( v13 == v10 )
          goto LABEL_16;
      }
      *(int *)(v5 + 24) = v13;
      *(int *)(v5 + 20) = 1;
      *(long long *)(v5 + 8) = &v4[v13 - v6];
      return 1;
    }
    else
    {
LABEL_16:
      *(long long *)(v5 + 32) = 0;
      return 0;
    }
  }
}


// Function: try_rekey @ 0xc330
long long try_rekey(long long a1, unsigned int a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // r8d
  int v6; // r9d
  unsigned int v7; // r12d
  const char *v9; // rax

  do
  {
    do
    {
      v2 = gnutls_session_key_update(*(long long *)(a1 + 8), a2);
      v7 = v2;
    }
    while ( v2 == -28 );
  }
  while ( v2 == -52 );
  if ( v2 < 0 )
  {
    v9 = (const char *)gnutls_strerror((unsigned int)v2);
    __fprintf_chk(stderr, 1, "*** Rekey has failed: %s\n", v9);
    return v7;
  }
  else
  {
    sub_DC90((int)stdout, (unsigned int)"- Rekey was completed\n", v3, v4, v5, v6);
    return 0;
  }
}


// Function: host_from_url @ 0x13ae0
char *host_from_url(const char *a1, int *a2, long long *a3)
{
  char *v4; // rbx
  char *v5; // rax
  char *v6; // rax
  char *v7; // rax

  v4 = (char *)a1;
  *a2 = 0;
  *a3 = "";
  v5 = strstr(a1, "http://");
  if ( v5 )
  {
    snprintf(byte_94500, 0x200u, "%s", v5 + 7);
    v6 = strchr(byte_94500, 47);
    if ( v6 )
    {
      *v6 = 0;
      *a3 = v6 + 1;
    }
    v4 = byte_94500;
    v7 = strchr(byte_94500, 58);
    if ( v7 )
    {
      *v7 = 0;
      *a2 = atoi(v7 + 1);
    }
  }
  return v4;
}


// Function: cmd_parser @ 0xc460
long long cmd_parser(int a1, char **a2)
{
  char *v2; // r12
  int v3; // eax
  long long v4; // rsi
  int v5; // edx
  const char *v6; // rcx
  int v7; // eax
  long long result; // rax
  char *v9; // rbx
  bool v10; // sf
  const char *v11; // rdx
  long long *i; // rbx
  int v13; // r8d
  int v14; // r9d
  long long v15; // rcx
  long long v16; // rdx
  int system_config_file; // eax
  int v18; // ecx
  int v19; // r8d
  int v20; // r9d

  v2 = 0;
  v3 = sub_148C0(a1, a2);
  if ( a1 > v3 )
    v2 = a2[v3];
  if ( byte_9575C )
  {
    if ( (unsigned int)gnutls_fips140_mode_enabled() )
    {
      __fprintf_chk(stderr, 1, "library is in FIPS140-2 mode\n");
      exit(0);
    }
    v11 = "library is NOT in FIPS140-2 mode\n";
LABEL_57:
    __fprintf_chk(stderr, 1, v11);
LABEL_58:
    exit(1);
  }
  if ( byte_9575D )
  {
    for ( i = (long long *)gnutls_get_library_config(); ; i += 2 )
    {
      v16 = *i;
      if ( !*i )
        break;
      v15 = i[1];
      sub_DC90((int)stdout, (unsigned int)"%s: %s\n", v16, v15, v13, v14);
    }
    system_config_file = gnutls_get_system_config_file();
    sub_DC90((int)stdout, (unsigned int)"system-config: %s\n", system_config_file, v18, v19, v20);
    exit(0);
  }
  if ( byte_9574A )
  {
    sub_12480((unsigned int)dword_95868);
    exit(0);
  }
  if ( byte_9574C )
  {
    sub_13860((unsigned int)dword_95868, 1);
    exit(0);
  }
  if ( byte_9574B )
  {
    sub_13860((unsigned int)dword_95868, 0);
    exit(0);
  }
  if ( byte_9573B )
    qword_23730 = qword_957C8;
  v4 = (unsigned char)byte_95721;
  v5 = 1;
  dword_2236C = (unsigned char)byte_95721;
  if ( !byte_95721 )
    v5 = (unsigned char)byte_95734;
  dword_22368 = v5;
  if ( byte_9574D )
  {
    sub_E5E0(qword_23730);
    exit(0);
  }
  if ( byte_9574E )
  {
    sub_AE60();
    exit(0);
  }
  dword_23738 = (unsigned char)byte_95755;
  dword_2373C = (unsigned char)byte_95756;
  if ( byte_95756 )
    dword_20020 |= 0x10u;
  if ( byte_95757 )
    dword_20020 |= 0x800u;
  if ( byte_95758 )
    dword_20020 |= 0x4000u;
  dword_223B0 = (unsigned char)byte_95759;
  if ( byte_9575A )
  {
    v9 = qword_95838;
    if ( strlen(qword_95838) > 1 || (v10 = *v9 < 0, qword_23728 = (long long)v9, v10) )
    {
      __fprintf_chk(stderr, 1, "inline-commands-prefix value is a single US-ASCII character (octets 0 - 127)\n");
      goto LABEL_58;
    }
  }
  else
  {
    qword_23728 = (long long)"^";
  }
  dword_223C8 = (unsigned char)byte_9572D;
  dword_223C4 = (unsigned char)byte_95747;
  dword_223CC = (unsigned char)byte_95728;
  dword_223BC = (unsigned char)byte_9572A;
  dword_223C0 = (unsigned char)byte_95749;
  dword_223AC = (unsigned char)byte_95761;
  if ( byte_95747 || byte_95748 )
    dword_223A8 |= 0x30u;
  v6 = (const char *)qword_95820;
  dword_223B8 = (unsigned char)byte_9572F;
  dword_223B4 = dword_9586C;
  if ( byte_95746 )
    goto LABEL_27;
  if ( byte_9572E )
  {
    v6 = (const char *)sub_10FF0(qword_95788, v4, (unsigned char)byte_95761, qword_95820);
LABEL_27:
    snprintf(nptr, 0x20u, "%s", v6);
    goto LABEL_28;
  }
  strcpy(nptr, "443");
LABEL_28:
  dword_22378 = dword_95874;
  dword_23740 = (unsigned char)byte_95733 ^ 1;
  if ( byte_95742 )
    qword_22358 = qword_95800;
  if ( byte_95743 )
    qword_22360 = qword_95808;
  if ( byte_9573C )
    qword_22340 = qword_957D0;
  if ( byte_9573D )
    qword_22338 = qword_957D8;
  if ( byte_9573E )
    qword_22350 = qword_957E0;
  if ( byte_9573F )
    qword_22348 = qword_957E8;
  if ( byte_95740 )
    qword_22330 = qword_957F0;
  if ( byte_95741 )
    qword_22328 = qword_957F8;
  if ( byte_95744 )
    qword_22320 = qword_95810;
  v7 = 0;
  if ( byte_95745 )
  {
    qword_22310 = (long long)qword_95818;
    v7 = strlen(qword_95818);
  }
  dword_22318 = v7;
  dword_22374 = (unsigned char)byte_95731;
  result = (unsigned char)byte_95732;
  dword_22370 = (unsigned char)byte_95732;
  if ( v2 )
  {
    qword_223A0 = v2;
    return result;
  }
  v11 = "No hostname specified\n";
  if ( !qword_223A0 )
    goto LABEL_57;
  return result;
}


// Function: getissuer_callback @ 0xc970
long long getissuer_callback(long long a1, long long a2, long long a3, long long a4)
{
  unsigned int v4; // r12d
  long long v6; // rsi
  int authority_info_access; // eax
  char *v8; // rax
  char *v9; // r12
  long long v10; // rbx
  void *v11; // rbp
  char *v12; // r13
  unsigned int v13; // ebx
  int v14; // eax
  unsigned int v15; // r14d
  void *v16; // r13
  unsigned int v17; // ebx
  char *v18; // rax
  int v19; // eax
  const char *v20; // rax
  const char *v22; // rax
  int v25; // [rsp+1Ch] [rbp-5ACh] BYREF
  char *v26; // [rsp+20h] [rbp-5A8h] BYREF
  char v27[8]; // [rsp+28h] [rbp-5A0h] BYREF
  void *haystack[2]; // [rsp+30h] [rbp-598h]
  char *v29; // [rsp+40h] [rbp-588h] BYREF
  unsigned int v30; // [rsp+48h] [rbp-580h]
  void *src; // [rsp+50h] [rbp-578h] BYREF
  size_t n; // [rsp+58h] [rbp-570h]
  char v33[272]; // [rsp+60h] [rbp-568h] BYREF
  char v34[16]; // [rsp+170h] [rbp-458h] BYREF
  char s[1032]; // [rsp+180h] [rbp-448h] BYREF
  unsigned long long v36; // [rsp+588h] [rbp-40h]

  v4 = 0;
  v36 = __readfsqword(0x28u);
  LODWORD(n) = 0;
  src = 0;
  v26 = "";
  sub_DC70();
  do
  {
    v6 = v4++;
    authority_info_access = gnutls_x509_crt_get_authority_info_access(a2, v6, 10106, &src, 0);
  }
  while ( authority_info_access == -105 );
  if ( authority_info_access < 0 )
  {
    v15 = 0;
    v22 = (const char *)gnutls_strerror((unsigned int)authority_info_access);
    __fprintf_chk(stderr, 1, "*** Cannot find caIssuer URI in certificate: %s\n", v22);
  }
  else
  {
    v8 = (char *)malloc((unsigned int)(n + 1));
    v9 = v8;
    if ( v8 )
    {
      v10 = (unsigned int)n;
      v11 = src;
      memcpy(v8, src, (unsigned int)n);
      v9[v10] = 0;
      gnutls_free(v11);
      src = 0;
      v12 = sub_C3B0(v9, &v25, &v26);
      if ( v25 )
        __snprintf_chk(v34, 16, 1, 16, "%u", v25);
      else
        strcpy(v34, "80");
      __fprintf_chk(stderr, 1, "Connecting to caIssuer server: %s...\n", v12);
      *(_OWORD *)haystack = 0;
      __snprintf_chk(
        s,
        1024,
        1,
        1024,
        "GET /%s HTTP/1.0\r\nHost: %s\r\nAccept: */*\r\nConnection: close\r\n\r\n",
        v26,
        v12);
      v13 = strlen(s);
      sub_11250(v33, v12, v34, 0, 40, "Connecting to", 0, 0, 0, 0);
      sub_10F90(v33, s, v13);
      while ( 1 )
      {
        v14 = sub_10D90(v33, &unk_225E0, 4097);
        v15 = v14;
        if ( v14 <= 0 )
          break;
        sub_C900(v14);
      }
      v16 = haystack[0];
      if ( v14 || (v17 = (unsigned int)haystack[1]) == 0 )
      {
        v15 = -1;
        perror("recv");
        sub_11040(v33, 0);
      }
      else
      {
        sub_11040(v33, 0);
        v18 = (char *)memmem(v16, v17, "\r\n\r\n", 4u);
        if ( v18 )
        {
          v29 = v18 + 4;
          v30 = v17 - ((int)v18 + 4 - (int)v16);
          if ( (int)gnutls_x509_crt_init(v27) < 0 )
          {
            v15 = -1;
            __fprintf_chk(stderr, 1, "Memory error\n");
          }
          else
          {
            v19 = gnutls_x509_crt_list_import2(a3, a4, &v29, 0, 0);
            if ( v19 < 0 )
            {
              v15 = -1;
              v20 = (const char *)gnutls_strerror((unsigned int)v19);
              __fprintf_chk(stderr, 1, "Decoding error: %s\n", v20);
            }
          }
        }
        else
        {
          v15 = -1;
          __fprintf_chk(stderr, 1, "Cannot interpret HTTP response\n");
        }
      }
      gnutls_free(src);
      src = 0;
      free(v16);
      free(v9);
    }
    else
    {
      return (unsigned int)-1;
    }
  }
  return v15;
}


// Function: init_tls_session @ 0xcd30
// positive sp value has been detected, the output may be wrong!
long long init_tls_session(char *a1)
{
  const char *v1; // r12
  int v2; // eax
  unsigned int v3; // r13d
  const char **v4; // rbp
  _OWORD *v5; // rbx
  const char *v6; // rdi
  long long v7; // rdi
  unsigned int v9; // eax
  FILE *v10; // rbp
  const char *v11; // rax
  int v12; // eax
  const char *v13; // rax
  size_t v14; // rax
  FILE *v15; // rbp
  const char *v16; // rax
  const char *v17; // [rsp-20h] [rbp-4048h] BYREF
  long long v18; // [rsp-18h] [rbp-4040h] BYREF
  char v19[16]; // [rsp-10h] [rbp-4038h] BYREF
  _OWORD v20[256]; // [rsp+0h] [rbp-4028h] BYREF
  long long v21[1541]; // [rsp+1000h] [rbp-3028h] BYREF

  while ( v20 != (_OWORD *)&v21[-2048] )
    ;
  v21[1535] = __readfsqword(0x28u);
  v1 = a1;
  if ( dword_223B8 )
  {
    ((void (*)(long long *, long long))gnutls_init)(&v18, dword_20020 | 4u);
    if ( dword_223B4 )
      ((void (*)(long long))gnutls_dtls_set_mtu)(v18);
  }
  else
  {
    ((void (*)(long long *, long long))gnutls_init)(&v18, (unsigned int)dword_20020);
  }
  if ( qword_23730 )
  {
    v2 = ((long long (*)(long long, long long, const char **))gnutls_priority_set_direct)(v18, qword_23730, &v17);
    if ( v2 < 0 )
    {
      v15 = stderr;
      if ( v2 != -50 )
      {
        v16 = (const char *)gnutls_strerror((unsigned int)v2);
        __fprintf_chk(v15, 1, "Error in priorities: %s\n", v16);
        goto LABEL_34;
      }
LABEL_45:
      __fprintf_chk(stderr, 1, "Syntax error at: %s\n", v17);
      goto LABEL_34;
    }
  }
  else
  {
    v12 = ((long long (*)(long long))gnutls_set_default_priority)(v18);
    if ( v12 < 0 )
    {
      v13 = (const char *)gnutls_strerror((unsigned int)v12);
      __fprintf_chk(stderr, 1, "Error in setting priorities: %s\n", v13);
      exit(1);
    }
  }
  if ( !qword_23738 )
  {
    if ( byte_9572B )
    {
      v1 = qword_95778;
      sub_11180(qword_95778, 0, 0);
    }
    else if ( !a1 || (unsigned int)sub_A1C0(a1) )
    {
      goto LABEL_8;
    }
    v14 = strlen(v1);
    ((void (*)(long long, long long, const char *, size_t))gnutls_server_name_set)(v18, 1, v1, v14);
  }
LABEL_8:
  if ( byte_9573A )
    ((void (*)(long long, long long))gnutls_dh_set_prime_bits)(v18, (unsigned int)dword_95870);
  if ( byte_95751 )
  {
    v3 = dword_95888;
    v4 = (const char **)qword_95880;
    if ( (unsigned int)dword_95888 > 0x400 )
    {
      __fprintf_chk(stderr, 1, "Number of ALPN protocols too large (%d)\n", dword_95888);
      goto LABEL_34;
    }
    if ( dword_95888 )
    {
      v5 = v19;
      do
      {
        v6 = *v4;
        ++v5;
        ++v4;
        *((long long *)v5 - 2) = v6;
        *((int *)v5 - 2) = strlen(v6);
      }
      while ( &v20[v3 - 1] != v5 );
    }
    ((void (*)(long long, char *, long long, long long))gnutls_alpn_set_protocols)(v18, v19, v3, 0);
  }
  ((void (*)(long long, long long, long long))gnutls_credentials_set)(v18, 2, qword_23710);
  if ( qword_23720 )
    ((void (*)(long long, long long))gnutls_credentials_set)(v18, 3);
  if ( qword_23718 )
    ((void (*)(long long, long long))gnutls_credentials_set)(v18, 4);
  ((void (*)(long long, long long, long long))gnutls_credentials_set)(v18, 1, qword_23708);
  ((void (*)(long long, long long (*)(long long, long long, int, long long, int, long long *, int *, long long *)))gnutls_certificate_set_retrieve_function2)(
    qword_23708,
    sub_9F60);
  ((void (*)(long long, long long (*)(long long)))gnutls_certificate_set_verify_function)(
    qword_23708,
    sub_AA30);
  if ( dword_22378 > 0 )
  {
    v7 = v18;
    if ( HIDWORD(qword_23738) )
      goto LABEL_22;
    if ( ((long long (*)(long long))gnutls_record_set_max_size)(v18) < 0 )
    {
      __fprintf_chk(stderr, 1, "Cannot set the maximum record size to %d.\n", dword_22378);
      __fprintf_chk(stderr, 1, "Possible values: 512, 1024, 2048, 4096.\n");
      exit(1);
    }
  }
  v7 = v18;
  if ( !byte_95752 || HIDWORD(qword_23738) )
  {
LABEL_22:
    if ( !byte_95753 )
      goto LABEL_23;
LABEL_30:
    ((void (*)(long long, long long))gnutls_heartbeat_enable)(v7, 1);
    v7 = v18;
    if ( !byte_95750 )
      return v7;
LABEL_31:
    v9 = ((long long (*)(long long, long long, const char **))gnutls_srtp_set_profile_direct)(
           v7,
           qword_95828,
           &v17);
    if ( v9 != -50 )
    {
      v10 = stderr;
      if ( !v9 )
      {
        __fprintf_chk(stderr, 1, "DTLS profile set to %s\n", (const char *)qword_95828);
        return v18;
      }
      v11 = (const char *)gnutls_strerror(v9);
      __fprintf_chk(v10, 1, "Error in profiles: %s\n", v11);
LABEL_34:
      exit(1);
    }
    goto LABEL_45;
  }
  if ( (int)((long long (*)(long long, long long, long long))sub_D870)(v18, qword_95890, (unsigned int)dword_95898) < 0 )
    goto LABEL_34;
  v7 = v18;
  if ( byte_95753 )
    goto LABEL_30;
LABEL_23:
  if ( byte_95750 )
    goto LABEL_31;
  return v7;
}


// Function: do_handshake @ 0xd200
long long do_handshake(unsigned int *a1)
{
  long long v2; // rcx
  int v3; // eax
  unsigned int v4; // r12d
  long long v5; // rdi
  long long v7; // rdx

  if ( dword_22370 )
  {
    v2 = a1[52];
    if ( (int)v2 )
    {
      gnutls_transport_set_fastopen(*((long long *)a1 + 1), *a1, a1 + 20, v2, 0);
      a1[52] = 0;
    }
  }
  while ( 1 )
  {
    gnutls_handshake_set_timeout(*((long long *)a1 + 1), 0xFFFFFFFFLL);
    v3 = gnutls_handshake(*((long long *)a1 + 1));
    v4 = v3;
    if ( v3 >= 0 )
      break;
    sub_D570(a1, (unsigned int)v3);
    if ( (unsigned int)gnutls_error_is_fatal(v4) )
    {
      v5 = *((long long *)a1 + 1);
      goto LABEL_10;
    }
  }
  v5 = *((long long *)a1 + 1);
  if ( v3 )
  {
LABEL_10:
    gnutls_alert_send_appropriate(v5, v4);
    shutdown(*a1, 2);
    return v4;
  }
  sub_FC20(v5, (unsigned int)dword_2236C, 2 * (unsigned int)(unsigned char)byte_9573F);
  if ( byte_9575F )
  {
    v7 = 20;
    if ( byte_95760 )
      v7 = dword_95878;
    sub_F270(*((long long *)a1 + 1), qword_95850, v7);
  }
  a1[4] = 1;
  return v4;
}


// Function: try_rehandshake @ 0xd320
long long try_rehandshake(unsigned int *a1)
{
  int v1; // eax
  int v2; // edx
  int v3; // ecx
  int v4; // r8d
  int v5; // r9d
  unsigned int v7; // r12d

  v1 = sub_D200(a1);
  if ( v1 < 0 )
  {
    v7 = v1;
    __fprintf_chk(stderr, 1, "*** ReHandshake has failed\n");
    gnutls_perror(v7);
    return v7;
  }
  else
  {
    sub_DC90((int)stdout, (unsigned int)"- ReHandshake was completed\n", v2, v3, v4, v5);
    return 0;
  }
}


// Function: do_inline_command_processing @ 0xd3e0
long long do_inline_command_processing(char *src, int a2, long long a3, long long a4)
{
  unsigned int v8; // r14d
  long long v9; // rdi
  char *v10; // rax

  while ( 1 )
  {
    if ( !(unsigned char)sub_C050(src, a2, a4) )
      return (unsigned int)a2;
    v8 = *(int *)(a4 + 24);
    if ( v8 )
      return v8;
    v9 = *(unsigned int *)(a4 + 16);
    if ( !(int)v9 )
      return v8;
    if ( (unsigned int)sub_D380(v9, a3) )
      break;
    v10 = *(char **)(a4 + 8);
    *(int *)(a4 + 16) = 0;
    if ( a2 <= (int)v10 - (int)src )
      return v8;
    a2 -= (int)v10 - (int)src;
    src = v10;
  }
  return 0xFFFFFFFFLL;
}


// Function: check_server_cmd @ 0xd470
long long check_server_cmd(long long a1, int a2, int a3, int a4, int a5, int a6)
{
  long long result; // rax
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // r8d
  int v11; // r9d
  unsigned int v12; // ebp
  int v13; // r12d
  const char *v14; // rsi
  int v15; // edi
  unsigned int v16; // eax
  int v17; // eax

  result = *(unsigned int *)(a1 + 16);
  if ( (int)result )
  {
    if ( a2 == -37 )
    {
      sub_DC90((int)stdout, (unsigned int)"*** Received rehandshake request\n", a3, a4, a5, a6);
      v16 = sub_D200((unsigned int *)a1);
      if ( v16 )
      {
        v17 = gnutls_strerror(v16);
        v15 = (int)stdout;
        v14 = "*** Rehandshake Failed: %s\n";
        v8 = v17;
      }
      else
      {
        v15 = (int)stdout;
        v14 = "*** Rehandshake was performed.\n";
      }
    }
    else
    {
      if ( a2 != -424 )
        return result;
      while ( 1 )
      {
        v7 = gnutls_reauth(*(long long *)(a1 + 8), 0);
        v12 = v7;
        if ( v7 >= 0 )
          break;
        if ( (unsigned int)gnutls_error_is_fatal((unsigned int)v7) )
        {
          v13 = (int)stdout;
          goto LABEL_13;
        }
      }
      v13 = (int)stdout;
      if ( !v7 )
      {
        v14 = "*** Re-auth was performed.\n";
        v15 = (int)stdout;
        return sub_DC90(v15, (int)v14, v8, v9, v10, v11);
      }
LABEL_13:
      v14 = "*** Re-auth failed: %s\n";
      v15 = v13;
      v8 = gnutls_strerror(v12);
    }
    return sub_DC90(v15, (int)v14, v8, v9, v10, v11);
  }
  return result;
}


// Function: handle_error @ 0xd570
long long handle_error(long long a1, unsigned int a2)
{
  const char *v2; // r14
  unsigned int is_fatal; // r12d
  const char *v4; // rax
  int v5; // edx
  int v6; // ecx
  int v7; // r8d
  int v8; // r9d
  long long v10; // r14
  long long name; // rax
  int v12; // r8d
  int v13; // r9d
  const char *v14; // rcx

  if ( (a2 & 0x80000000) == 0 || a2 == -28 || a2 == -52 )
    return 0;
  v2 = "Non fatal";
  is_fatal = gnutls_error_is_fatal(a2);
  if ( is_fatal )
  {
    is_fatal = a2;
    v2 = "Fatal";
  }
  v4 = (const char *)gnutls_strerror(a2);
  if ( !v4 )
    v4 = "(unknown)";
  __fprintf_chk(stderr, 1, "*** %s error: %s\n", v2, v4);
  if ( (a2 & 0xFFFFFFFB) == 0xFFFFFFF0 )
  {
    v10 = (unsigned int)gnutls_alert_get(*(long long *)(a1 + 8));
    name = gnutls_alert_get_name(v10);
    LODWORD(v14) = name;
    if ( !name )
      v14 = "(unknown)";
    sub_DC90((int)stdout, (unsigned int)"*** Received alert [%d]: %s\n", v10, (int)v14, v12, v13);
  }
  sub_D470(a1, a2, v5, v6, v7, v8);
  return is_fatal;
}


// Function: raw_to_string @ 0xd670
const char *raw_to_string(long long a1, long long a2)
{
  const char *result; // rax
  long long v4; // r12
  char *v5; // r13
  char *v6; // rdi
  char *v7; // r9
  long long v8; // r8

  result = "(empty)";
  if ( a2 )
  {
    result = "(too large)";
    if ( (unsigned long long)(3 * a2 + 1) <= 0x3FF )
    {
      v4 = 0;
      v5 = (char *)&unk_24080;
      do
      {
        v6 = v5;
        v7 = ":";
        v8 = *(unsigned char *)(a1 + v4);
        if ( a2 - 1 == v4 )
          v7 = "";
        ++v4;
        v5 += 3;
        __sprintf_chk(v6, 1, -1, "%02X%s", v8, v7);
      }
      while ( a2 != v4 );
      byte_2447F = 0;
      return (const char *)&unk_24080;
    }
  }
  return result;
}


// Function: raw_to_base64 @ 0xd7e0
const char *raw_to_base64(long long a1, long long a2)
{
  const char *result; // rax
  int v3; // r8d
  long long v4; // [rsp+8h] [rbp-30h] BYREF
  long long v5; // [rsp+10h] [rbp-28h] BYREF
  int v6; // [rsp+18h] [rbp-20h]
  unsigned long long v7; // [rsp+28h] [rbp-10h]

  v7 = __readfsqword(0x28u);
  v5 = a1;
  result = "(empty)";
  v6 = a2;
  if ( a2 )
  {
    v4 = 1024;
    v3 = gnutls_pem_base64_encode(0, &v5, &unk_23880, &v4);
    result = "(error)";
    if ( v3 >= 0 )
    {
      byte_23C7F = 0;
      return (const char *)&unk_23880;
    }
  }
  return result;
}


// Function: compress_cert_set_methods @ 0xd870
long long compress_cert_set_methods(long long a1, long long a2, long long a3)
{
  unsigned int v3; // r14d
  int *v6; // rbp
  long long v7; // r14
  const char *v8; // r15
  int id; // eax
  int v10; // eax
  const char *v11; // rax
  const char *v12; // rax

  v3 = 0;
  if ( a3 )
  {
    v6 = (int *)reallocarray(0, a3, 4);
    if ( v6 )
    {
      v7 = 0;
      do
      {
        v8 = *(const char **)(a2 + 8 * v7);
        id = gnutls_compression_get_id(v8);
        v6[v7] = id;
        if ( !id )
        {
          v3 = 0;
          __fprintf_chk(stderr, 1, "Unknown compression method: %s\n", v8);
          goto LABEL_9;
        }
        ++v7;
      }
      while ( a3 != v7 );
      v10 = gnutls_compress_certificate_set_methods(a1, v6, a3);
      v3 = v10;
      if ( v10 < 0 )
      {
        v11 = (const char *)gnutls_strerror((unsigned int)v10);
        __fprintf_chk(stderr, 1, "Could not set certificate compression methods: %s\n", v11);
      }
LABEL_9:
      free(v6);
    }
    else
    {
      v3 = -25;
      v12 = (const char *)gnutls_strerror(0);
      __fprintf_chk(stderr, 1, "Could not set certificate compression methods: %s\n", v12);
    }
  }
  return v3;
}


// Function: check_command @ 0xd990
long long check_command(long long a1, long long a2, int a3)
{
  unsigned int v4; // r12d
  size_t v5; // rbx
  int v7; // eax
  int v8; // eax
  FILE *v9; // rbp
  const char *v10; // rax
  const char *v11; // rax

  v4 = 0;
  v5 = strnlen((const char *)a2, 0x80u);
  __fprintf_chk(stderr, 1, "*** Processing %u bytes command: %s\n", v5, (const char *)a2);
  if ( v5 > 2 )
  {
    if ( *(char *)(a2 + 1) == *(char *)a2 && *(char *)a2 == 42 )
    {
      if ( !strncmp((const char *)a2, "**REHANDSHAKE**", 0xFu) )
      {
        v4 = 1;
        __fprintf_chk(stderr, 1, "*** Sending rehandshake request\n");
        gnutls_rehandshake(a1);
      }
      else if ( !strncmp((const char *)a2, "**REAUTH**", 0xAu) )
      {
        if ( a3 )
          gnutls_certificate_server_set_request(a1, 2);
        __fprintf_chk(stderr, 1, "*** Sending re-auth request\n");
        do
        {
          do
          {
            v7 = gnutls_reauth(a1, 0);
            v4 = v7;
          }
          while ( v7 == -28 );
        }
        while ( v7 == -52 );
        if ( v7 < 0 )
        {
          v11 = (const char *)gnutls_strerror((unsigned int)v7);
          __fprintf_chk(stderr, 1, "reauth: %s\n", v11);
        }
        else
        {
          return 1;
        }
      }
      else if ( !strncmp((const char *)a2, "**HEARTBEAT**", 0xDu) )
      {
        v8 = gnutls_heartbeat_ping(a1, 300, 5, 1);
        v4 = v8;
        if ( v8 >= 0 )
        {
          return 2;
        }
        else
        {
          v9 = stderr;
          if ( v8 == -50 )
          {
            v4 = 2;
            __fprintf_chk(stderr, 1, "No heartbeat in this session\n");
          }
          else
          {
            v10 = (const char *)gnutls_strerror((unsigned int)v8);
            __fprintf_chk(v9, 1, "ping: %s\n", v10);
          }
        }
      }
    }
    else
    {
      return 0;
    }
  }
  return v4;
}


// Function: getpass_copy @ 0xdba0
char *getpass_copy(char *dest, size_t a2, const char *a3)
{
  char *result; // rax
  const char *v4; // rbp
  size_t v5; // rax
  size_t v6; // r12

  result = getpass(a3);
  if ( result )
  {
    v4 = result;
    v5 = strlen(result);
    v6 = v5;
    if ( v5 < a2 )
    {
      strcpy(dest, v4);
      return (char *)gnutls_memset(v4, 0, v6);
    }
    result = (char *)gnutls_memset(v4, 0, v5);
  }
  *dest = 0;
  return result;
}


// Function: getenv_copy @ 0xdc20
char *getenv_copy(char *dest, unsigned long long a2, const char *a3)
{
  char *result; // rax
  const char *v4; // rbp

  result = getenv(a3);
  if ( result )
  {
    v4 = result;
    result = (char *)strlen(result);
    if ( (unsigned long long)result < a2 )
      return strcpy(dest, v4);
  }
  *dest = 0;
  return result;
}


// Function: sockets_init @ 0xdc70
__sighandler_t sockets_init()
{
  return signal(13, (__sighandler_t)((char *)&dword_0 + 1));
}


// Function: log_msg @ 0xdc90
long long log_msg(long long a1, long long a2, ...)
{
  long long v3; // rdi
  gcc_va_list va; // [rsp+0h] [rbp-D8h] BYREF
  unsigned long long v6; // [rsp+18h] [rbp-C0h]
  char v7[16]; // [rsp+20h] [rbp-B8h] BYREF
  long long v8; // [rsp+30h] [rbp-A8h]
  long long v9; // [rsp+38h] [rbp-A0h]
  long long v10; // [rsp+40h] [rbp-98h]
  long long v11; // [rsp+48h] [rbp-90h]

  va_start(va, a2);
  v8 = va_arg(va, long long);
  v9 = va_arg(va, long long);
  v10 = va_arg(va, long long);
  v11 = va_arg(va, long long);
  va_end(va);
  va_start(va, a2);
  v6 = __readfsqword(0x28u);
  v3 = qword_24480;
  if ( !qword_24480 )
    v3 = a1;
  va[0].fp_offset = 48;
  return __vfprintf_chk(v3, 1, a2, va, v10, v11, *(long long *)&va[0].gp_offset, va[0].overflow_arg_area, v7, v6);
}


// Function: cert_verify @ 0xdd70
long long cert_verify(long long a1, long long a2, long long a3)
{
  long long v4; // rdx
  long long v5; // rcx
  int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  const char *v10; // rax
  const char *v11; // rax
  unsigned int v12; // [rsp+Ch] [rbp-5Ch] BYREF
  const char *v13; // [rsp+10h] [rbp-58h] BYREF
  _OWORD v14[3]; // [rsp+20h] [rbp-48h] BYREF
  unsigned long long v15; // [rsp+58h] [rbp-10h]

  v15 = __readfsqword(0x28u);
  v4 = 0;
  v12 = 0;
  memset(v14, 0, sizeof(v14));
  if ( a2 )
  {
    LODWORD(v14[0]) = 1;
    v4 = 1;
    *((long long *)&v14[0] + 1) = a2;
  }
  if ( a3 )
  {
    v5 = (unsigned int)v4;
    v4 = (unsigned int)(v4 + 1);
    v5 *= 24;
    *(int *)((char *)v14 + v5) = 2;
    *(long long *)((char *)v14 + v5 + 8) = a3;
  }
  v6 = gnutls_certificate_verify_peers(a1, v14, v4, &v12);
  if ( v6 == -49 )
  {
    sub_DC90((long long)stdout, (long long)"- Peer did not send any certificate.\n");
    return 0;
  }
  else if ( v6 < 0 )
  {
    v10 = (const char *)gnutls_strerror((unsigned int)v6);
    sub_DC90((long long)stdout, (long long)"- Could not verify certificate (err: %s)\n", v10);
    return 0;
  }
  else
  {
    v7 = gnutls_certificate_type_get(a1);
    v8 = gnutls_certificate_verification_status_print(v12, v7, &v13, 0);
    if ( v8 < 0 )
    {
      v11 = (const char *)gnutls_strerror((unsigned int)v8);
      sub_DC90((long long)stdout, (long long)"- Could not print verification flags (err: %s)\n", v11);
      return 0;
    }
    else
    {
      sub_DC90((long long)stdout, (long long)"- Status: %s\n", v13);
      gnutls_free(v13);
      v13 = 0;
      if ( v12 )
      {
        if ( (v12 & 2) == 0 )
          abort();
        return 0;
      }
      else
      {
        return 1;
      }
    }
  }
}


// Function: print_dh_info @ 0xdf10
unsigned long long print_dh_info(long long a1, const char *a2, int a3)
{
  int prime_bits; // eax
  int secret_bits; // eax
  int peers_public_bits; // eax
  unsigned int group; // eax
  const char *v8; // rdx
  long long v9; // rcx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  long long v13; // rax
  const char *v14; // rbp
  int v15; // eax
  long long v16; // [rsp+0h] [rbp-58h] BYREF
  long long v17; // [rsp+8h] [rbp-50h] BYREF
  long long v18; // [rsp+10h] [rbp-48h] BYREF
  int v19; // [rsp+18h] [rbp-40h]
  long long v20; // [rsp+20h] [rbp-38h] BYREF
  int v21; // [rsp+28h] [rbp-30h]
  unsigned long long v22; // [rsp+38h] [rbp-20h]

  v22 = __readfsqword(0x28u);
  v19 = 0;
  v18 = 0;
  v20 = 0;
  v21 = 0;
  v16 = 0;
  v17 = 0;
  if ( a3 && !(unsigned int)gnutls_group_get() )
  {
    sub_DC90((long long)stdout, (long long)"- %sDiffie-Hellman parameters\n", a2);
    prime_bits = gnutls_dh_get_prime_bits(a1);
    sub_DC90((long long)stdout, (long long)" - Using prime: %d bits\n", prime_bits);
    secret_bits = gnutls_dh_get_secret_bits(a1);
    sub_DC90((long long)stdout, (long long)" - Secret key: %d bits\n", secret_bits);
    peers_public_bits = gnutls_dh_get_peers_public_bits(a1);
    sub_DC90((long long)stdout, (long long)" - Peer's public key: %d bits\n", peers_public_bits);
    group = gnutls_dh_get_group(a1, &v18, &v20);
    v8 = "gnutls_dh_get_group %d\n";
    v9 = group;
    if ( !group )
    {
      v10 = gnutls_dh_params_init(&v16, &v18, "gnutls_dh_get_group %d\n", 0);
      if ( v10 )
      {
        v9 = v10;
        v8 = "gnutls_dh_params_init %d\n";
      }
      else
      {
        v11 = gnutls_dh_params_import_raw(v16, &v20, &v18);
        v8 = "gnutls_dh_params_import_raw %d\n";
        v9 = v11;
        if ( !v11 )
        {
          v12 = gnutls_dh_params_export_pkcs3(v16, 1, 0, &v17);
          v8 = "gnutls_dh_params_export_pkcs3 %d\n";
          v9 = v12;
          if ( v12 == -51 )
          {
            v13 = gnutls_malloc(v17, 1, "gnutls_dh_params_export_pkcs3 %d\n", -51);
            v14 = (const char *)v13;
            if ( v13 )
            {
              v15 = gnutls_dh_params_export_pkcs3(v16, 1, v13, &v17);
              if ( v15 )
                __fprintf_chk(stderr, 1, "gnutls_dh_params_export_pkcs3-2 %d\n", v15);
              else
                sub_DC90((long long)stdout, (long long)" - PKCS#3 format:\n\n%.*s\n", v17, v14);
            }
            else
            {
              __fprintf_chk(stderr, 1, "gnutls_malloc %d\n", -51);
            }
            goto LABEL_13;
          }
        }
      }
    }
    v14 = 0;
    __fprintf_chk(stderr, 1, v8, v9);
LABEL_13:
    gnutls_free(v14);
    gnutls_free(v20);
    v20 = 0;
    gnutls_free(v18);
    v18 = 0;
    gnutls_dh_params_deinit(v16);
  }
  return v22 - __readfsqword(0x28u);
}


// Function: print_ecdh_info @ 0xe180
void print_ecdh_info(long long a1, const char *a2, int a3)
{
  long long v3; // rbp
  const char *name; // rax
  int size; // eax

  if ( a3 )
  {
    sub_DC90((long long)stdout, (long long)"- %sEC Diffie-Hellman parameters\n", a2);
    v3 = (unsigned int)gnutls_ecc_curve_get(a1);
    name = (const char *)gnutls_ecc_curve_get_name(v3);
    sub_DC90((long long)stdout, (long long)" - Using curve: %s\n", name);
    size = gnutls_ecc_curve_get_size((unsigned int)v3);
    sub_DC90((long long)stdout, (long long)" - Curve size: %d bits\n", 8 * size);
  }
}


// Function: print_channel_bindings @ 0xe200
unsigned long long print_channel_bindings(long long a1, int a2)
{
  const char **v3; // rbx
  long long i; // rsi
  int v5; // eax
  const char *v6; // r14
  const char *v7; // rax
  unsigned long long v8; // r14
  int v9; // edx
  long long v10; // [rsp+0h] [rbp-58h] BYREF
  unsigned int v11; // [rsp+8h] [rbp-50h]
  unsigned long long v12; // [rsp+18h] [rbp-40h]

  v12 = __readfsqword(0x28u);
  if ( a2 )
  {
    v3 = (const char **)&unk_1E960;
    sub_DC90((long long)stdout, (long long)"- Channel bindings\n");
    for ( i = 0; ; i = *(unsigned int *)v3 )
    {
      v5 = gnutls_session_channel_binding(a1, i, &v10);
      if ( v5 == -213 )
      {
        sub_DC90((long long)stdout, (long long)" - '%s': not available\n", v3[1]);
      }
      else
      {
        v6 = v3[1];
        if ( v5 >= 0 )
        {
          v8 = 0;
          sub_DC90((long long)stdout, (long long)" - '%s': ", v3[1]);
          if ( v11 )
          {
            do
            {
              v9 = *(unsigned char *)(v10 + v8++);
              sub_DC90((long long)stdout, (long long)"%02x", v9);
            }
            while ( v11 > v8 );
          }
          sub_DC90((long long)stdout, (long long)"\n");
          gnutls_free(v10);
        }
        else
        {
          v7 = (const char *)gnutls_strerror((unsigned int)v5);
          __fprintf_chk(stderr, 1, " - '%s': error: %s\n", v6, v7);
        }
      }
      v3 += 2;
      if ( &off_1E990 == (char **)v3 )
        break;
    }
  }
  return v12 - __readfsqword(0x28u);
}


// Function: print_x509_info @ 0xe380
unsigned long long print_x509_info(long long a1, long long a2, unsigned int a3, int a4, int a5)
{
  long long peers; // rax
  long long v10; // r13
  unsigned int i; // ebx
  long long v12; // rdi
  int v13; // eax
  int v14; // eax
  long long v15; // rsi
  const char *v16; // rax
  const char *v17; // rax
  unsigned int v19; // [rsp+14h] [rbp-74h] BYREF
  long long v20; // [rsp+18h] [rbp-70h] BYREF
  const char *v21; // [rsp+20h] [rbp-68h] BYREF
  const char *v22; // [rsp+30h] [rbp-58h] BYREF
  unsigned long long v23; // [rsp+48h] [rbp-40h]

  v23 = __readfsqword(0x28u);
  v19 = 0;
  peers = gnutls_certificate_get_peers(a1, &v19);
  if ( v19 )
  {
    v10 = peers;
    sub_DC90(a2, (long long)"- Certificate type: X.509\n");
    sub_DC90(a2, (long long)"- Got a certificate list of %d certificates.\n", v19);
    if ( v19 )
    {
      for ( i = 0; v19 > i; ++i )
      {
        if ( (int)gnutls_x509_crt_init(&v20) < 0 )
        {
          __fprintf_chk(stderr, 1, "Memory error\n");
          return v23 - __readfsqword(0x28u);
        }
        v14 = gnutls_x509_crt_import(v20, v10 + 16LL * i, 0);
        if ( v14 < 0 )
        {
          v16 = (const char *)gnutls_strerror((unsigned int)v14);
          __fprintf_chk(stderr, 1, "Decoding error: %s\n", v16);
          return v23 - __readfsqword(0x28u);
        }
        sub_DC90(a2, (long long)"- Certificate[%d] info:\n - ", i);
        if ( a3 == 3 && i )
        {
          v15 = 1;
          a3 = 1;
        }
        else
        {
          v15 = a3;
        }
        if ( !(unsigned int)gnutls_x509_crt_print(v20, v15, &v21) )
        {
          sub_DC90(a2, (long long)"%s\n", v21);
          gnutls_free(v21);
          v21 = 0;
        }
        v12 = v20;
        if ( a4 )
        {
          v13 = gnutls_x509_crt_export2(v20, 1, &v22);
          if ( v13 < 0 )
          {
            v17 = (const char *)gnutls_strerror((unsigned int)v13);
            __fprintf_chk(stderr, 1, "Encoding error: %s\n", v17);
            return v23 - __readfsqword(0x28u);
          }
          sub_DC90(a2, (long long)"\n%s\n", v22);
          gnutls_free(v22);
          v12 = v20;
        }
        gnutls_x509_crt_deinit(v12);
      }
    }
  }
  else if ( a5 )
  {
    __fprintf_chk(stderr, 1, "No certificates found!\n");
  }
  return v23 - __readfsqword(0x28u);
}


// Function: print_list @ 0xe5e0
unsigned long long print_list(const char *a1, int a2)
{
  int v2; // eax
  unsigned int i; // ebx
  const char *v4; // r12
  const char *name; // rax
  int cipher_suite_index; // eax
  long long v7; // rbx
  long long v8; // rdi
  const char *v9; // rax
  long long v10; // r13
  long long v11; // rdi
  const char *v12; // rax
  long long v13; // r13
  long long v14; // rdi
  const char *v15; // rax
  long long v16; // r13
  long long v17; // rdi
  const char *v18; // rax
  long long v19; // rbx
  long long v20; // rdi
  const char *v21; // rax
  long long v22; // rbx
  long long v23; // r13
  long long v24; // rdi
  const char *v25; // rax
  long long v27; // rbx
  long long v28; // rax
  const char *v29; // rax
  const char *v30; // rax
  unsigned int *v31; // rbx
  long long j; // rdi
  const char *v33; // rax
  int *v34; // rbx
  const char *v35; // rax
  int *v36; // rbp
  const char *v37; // rax
  int *v38; // rbp
  const char *v39; // rax
  int *v40; // rbp
  const char *v41; // rax
  int *v42; // rbp
  const char *v43; // rax
  int *v44; // rbx
  const char *v45; // rax
  int *v46; // rbx
  const char *v47; // rax
  int *v48; // rbp
  const char *v49; // rax
  int *v50; // rbx
  int v51; // edi
  const char *v52; // rax
  FILE *v53; // rbp
  const char *v54; // rax
  int v55; // [rsp+8h] [rbp-80h]
  int v56; // [rsp+8h] [rbp-80h]
  int v57; // [rsp+8h] [rbp-80h]
  int v58; // [rsp+8h] [rbp-80h]
  int v59; // [rsp+8h] [rbp-80h]
  const char *v60; // [rsp+8h] [rbp-80h]
  const char *v61; // [rsp+8h] [rbp-80h]
  const char *v62; // [rsp+18h] [rbp-70h]
  unsigned int v63; // [rsp+20h] [rbp-68h] BYREF
  unsigned int v64; // [rsp+24h] [rbp-64h] BYREF
  const char *v65; // [rsp+28h] [rbp-60h] BYREF
  long long v66; // [rsp+30h] [rbp-58h] BYREF
  long long v67; // [rsp+38h] [rbp-50h] BYREF
  unsigned char v68; // [rsp+46h] [rbp-42h] BYREF
  unsigned char v69; // [rsp+47h] [rbp-41h]
  unsigned long long v70; // [rsp+48h] [rbp-40h]

  v70 = __readfsqword(0x28u);
  if ( a1 )
  {
    sub_DC90((long long)stdout, (long long)"Cipher suites for %s\n", a1);
    v2 = gnutls_priority_init(&v66, a1, &v65);
    if ( v2 < 0 )
    {
      v53 = stderr;
      if ( v2 == -50 )
      {
        __fprintf_chk(stderr, 1, "Syntax error at: %s\n", v65);
      }
      else
      {
        v54 = (const char *)gnutls_strerror((unsigned int)v2);
        __fprintf_chk(v53, 1, "Error in priorities: %s\n", v54);
      }
      exit(1);
    }
    for ( i = 0; ; ++i )
    {
      cipher_suite_index = gnutls_priority_get_cipher_suite_index(v66, i, &v63);
      if ( cipher_suite_index == -56 )
        break;
      if ( cipher_suite_index != -21 )
      {
        v4 = (const char *)gnutls_cipher_suite_info(v63, &v68, 0, 0, 0, &v64);
        if ( v4 )
        {
          name = (const char *)gnutls_protocol_get_name(v64);
          sub_DC90((long long)stdout, (long long)"%-50s\t0x%02x, 0x%02x\t%s\n", v4, v68, v69, name);
        }
      }
    }
    v7 = 0;
    sub_DC90((long long)stdout, (long long)"\n");
    v55 = gnutls_priority_protocol_list(v66, &v67);
    sub_DC90((long long)stdout, (long long)"Protocols: ");
    if ( v55 )
    {
      while ( 1 )
      {
        v8 = *(unsigned int *)(v67 + 4 * v7++);
        v9 = (const char *)gnutls_protocol_get_name(v8);
        sub_DC90((long long)stdout, (long long)"VERS-%s", v9);
        if ( v7 == v55 )
          break;
        sub_DC90((long long)stdout, (long long)", ");
      }
      sub_DC90((long long)stdout, (long long)"\n");
    }
    else
    {
      sub_DC90((long long)stdout, (long long)"none\n");
    }
    v10 = 0;
    v56 = gnutls_priority_cipher_list(v66, &v67);
    sub_DC90((long long)stdout, (long long)"Ciphers: ");
    if ( v56 )
    {
      while ( 1 )
      {
        v11 = *(unsigned int *)(v67 + 4 * v10++);
        v12 = (const char *)gnutls_cipher_get_name(v11);
        sub_DC90((long long)stdout, (long long)"%s", v12);
        if ( v10 == v56 )
          break;
        sub_DC90((long long)stdout, (long long)", ");
      }
      sub_DC90((long long)stdout, (long long)"\n");
    }
    else
    {
      sub_DC90((long long)stdout, (long long)"none\n");
    }
    v13 = 0;
    v57 = gnutls_priority_mac_list(v66, &v67);
    sub_DC90((long long)stdout, (long long)"MACs: ");
    if ( v57 )
    {
      while ( 1 )
      {
        v14 = *(unsigned int *)(v67 + 4 * v13++);
        v15 = (const char *)gnutls_mac_get_name(v14);
        sub_DC90((long long)stdout, (long long)"%s", v15);
        if ( v13 == v57 )
          break;
        sub_DC90((long long)stdout, (long long)", ");
      }
      sub_DC90((long long)stdout, (long long)"\n");
    }
    else
    {
      sub_DC90((long long)stdout, (long long)"none\n");
    }
    v16 = 0;
    v58 = gnutls_priority_kx_list(v66, &v67);
    sub_DC90((long long)stdout, (long long)"Key Exchange Algorithms: ");
    if ( v58 )
    {
      while ( 1 )
      {
        v17 = *(unsigned int *)(v67 + 4 * v16++);
        v18 = (const char *)gnutls_kx_get_name(v17);
        sub_DC90((long long)stdout, (long long)"%s", v18);
        if ( v16 == v58 )
          break;
        sub_DC90((long long)stdout, (long long)", ");
      }
      sub_DC90((long long)stdout, (long long)"\n");
    }
    else
    {
      sub_DC90((long long)stdout, (long long)"none\n");
    }
    v19 = 0;
    v59 = gnutls_priority_group_list(v66, &v67);
    sub_DC90((long long)stdout, (long long)"Groups: ");
    if ( v59 )
    {
      while ( 1 )
      {
        v20 = *(unsigned int *)(v67 + 4 * v19++);
        v21 = (const char *)gnutls_group_get_name(v20);
        sub_DC90((long long)stdout, (long long)"GROUP-%s", v21);
        if ( v19 == v59 )
          break;
        sub_DC90((long long)stdout, (long long)", ");
      }
      sub_DC90((long long)stdout, (long long)"\n");
    }
    else
    {
      sub_DC90((long long)stdout, (long long)"none\n");
    }
    v22 = 0;
    v23 = (unsigned int)gnutls_priority_sign_list(v66, &v67);
    sub_DC90((long long)stdout, (long long)"PK-signatures: ");
    if ( (int)v23 )
    {
      while ( 1 )
      {
        v24 = *(unsigned int *)(v67 + 4 * v22++);
        v25 = (const char *)gnutls_sign_get_name(v24);
        sub_DC90((long long)stdout, (long long)"SIGN-%s", v25);
        if ( v22 == v23 )
          break;
        sub_DC90((long long)stdout, (long long)", ");
      }
      sub_DC90((long long)stdout, (long long)"\n");
    }
    else
    {
      sub_DC90((long long)stdout, (long long)"none\n");
    }
    gnutls_priority_deinit(v66);
  }
  else
  {
    v27 = 0;
    sub_DC90((long long)stdout, (long long)"Cipher suites:\n");
    while ( 1 )
    {
      v28 = gnutls_cipher_suite_info(v27, &v68, &v65, &v66, &v67, &v64);
      if ( !v28 )
        break;
      v60 = (const char *)v28;
      v29 = (const char *)gnutls_protocol_get_name(v64);
      sub_DC90((long long)stdout, (long long)"%-50s\t0x%02x, 0x%02x\t%s\n", v60, v68, v69, v29);
      if ( a2 )
      {
        v62 = (const char *)gnutls_mac_get_name((unsigned int)v67);
        v61 = (const char *)gnutls_cipher_get_name((unsigned int)v66);
        v30 = (const char *)gnutls_kx_get_name((unsigned int)v65);
        sub_DC90((long long)stdout, (long long)"\tKey exchange: %s\n\tCipher: %s\n\tMAC: %s\n\n", v30, v61, v62);
      }
      ++v27;
    }
    sub_DC90((long long)stdout, (long long)"\n");
    v31 = (unsigned int *)gnutls_certificate_type_list();
    sub_DC90((long long)stdout, (long long)"Certificate types: ");
    for ( j = *v31; (int)j; j = *v31 )
    {
      while ( 1 )
      {
        v33 = (const char *)gnutls_certificate_type_get_name(j);
        sub_DC90((long long)stdout, (long long)"CTYPE-%s", v33);
        if ( !v31[1] )
          break;
        ++v31;
        sub_DC90((long long)stdout, (long long)", ");
        j = *v31;
        if ( !(int)j )
          goto LABEL_51;
      }
      ++v31;
      sub_DC90((long long)stdout, (long long)"\n");
    }
LABEL_51:
    v34 = (int *)gnutls_protocol_list();
    sub_DC90((long long)stdout, (long long)"Protocols: ");
    while ( *v34 )
    {
      while ( 1 )
      {
        v35 = (const char *)((long long (*)(void))gnutls_protocol_get_name)();
        sub_DC90((long long)stdout, (long long)"VERS-%s", v35);
        if ( !v34[1] )
          break;
        ++v34;
        sub_DC90((long long)stdout, (long long)", ");
        if ( !*v34 )
          goto LABEL_56;
      }
      ++v34;
      sub_DC90((long long)stdout, (long long)"\n");
    }
LABEL_56:
    v36 = (int *)gnutls_cipher_list();
    sub_DC90((long long)stdout, (long long)"Ciphers: ");
    while ( *v36 )
    {
      while ( 1 )
      {
        v37 = (const char *)((long long (*)(void))gnutls_cipher_get_name)();
        sub_DC90((long long)stdout, (long long)"%s", v37);
        if ( !v36[1] )
          break;
        ++v36;
        sub_DC90((long long)stdout, (long long)", ");
        if ( !*v36 )
          goto LABEL_61;
      }
      ++v36;
      sub_DC90((long long)stdout, (long long)"\n");
    }
LABEL_61:
    v38 = (int *)gnutls_mac_list();
    sub_DC90((long long)stdout, (long long)"MACs: ");
    while ( *v38 )
    {
      while ( 1 )
      {
        v39 = (const char *)((long long (*)(void))gnutls_mac_get_name)();
        sub_DC90((long long)stdout, (long long)"%s", v39);
        if ( !v38[1] )
          break;
        ++v38;
        sub_DC90((long long)stdout, (long long)", ");
        if ( !*v38 )
          goto LABEL_66;
      }
      ++v38;
      sub_DC90((long long)stdout, (long long)"\n");
    }
LABEL_66:
    v40 = (int *)gnutls_digest_list();
    sub_DC90((long long)stdout, (long long)"Digests: ");
    while ( *v40 )
    {
      while ( 1 )
      {
        v41 = (const char *)gnutls_digest_get_name();
        sub_DC90((long long)stdout, (long long)"%s", v41);
        if ( !v40[1] )
          break;
        ++v40;
        sub_DC90((long long)stdout, (long long)", ");
        if ( !*v40 )
          goto LABEL_71;
      }
      ++v40;
      sub_DC90((long long)stdout, (long long)"\n");
    }
LABEL_71:
    v42 = (int *)gnutls_kx_list();
    sub_DC90((long long)stdout, (long long)"Key exchange algorithms: ");
    while ( *v42 )
    {
      while ( 1 )
      {
        v43 = (const char *)((long long (*)(void))gnutls_kx_get_name)();
        sub_DC90((long long)stdout, (long long)"%s", v43);
        if ( !v42[1] )
          break;
        ++v42;
        sub_DC90((long long)stdout, (long long)", ");
        if ( !*v42 )
          goto LABEL_76;
      }
      ++v42;
      sub_DC90((long long)stdout, (long long)"\n");
    }
LABEL_76:
    v44 = (int *)gnutls_compression_list();
    sub_DC90((long long)stdout, (long long)"Compression: ");
    while ( *v44 )
    {
      while ( 1 )
      {
        v45 = (const char *)gnutls_compression_get_name();
        sub_DC90((long long)stdout, (long long)"COMP-%s", v45);
        if ( !v44[1] )
          break;
        ++v44;
        sub_DC90((long long)stdout, (long long)", ");
        if ( !*v44 )
          goto LABEL_81;
      }
      ++v44;
      sub_DC90((long long)stdout, (long long)"\n");
    }
LABEL_81:
    v46 = (int *)gnutls_group_list();
    sub_DC90((long long)stdout, (long long)"Groups: ");
    while ( *v46 )
    {
      while ( 1 )
      {
        v47 = (const char *)((long long (*)(void))gnutls_group_get_name)();
        sub_DC90((long long)stdout, (long long)"GROUP-%s", v47);
        if ( !v46[1] )
          break;
        ++v46;
        sub_DC90((long long)stdout, (long long)", ");
        if ( !*v46 )
          goto LABEL_86;
      }
      ++v46;
      sub_DC90((long long)stdout, (long long)"\n");
    }
LABEL_86:
    v48 = (int *)gnutls_pk_list();
    sub_DC90((long long)stdout, (long long)"Public Key Systems: ");
    while ( *v48 )
    {
      while ( 1 )
      {
        v49 = (const char *)gnutls_pk_algorithm_get_name();
        sub_DC90((long long)stdout, (long long)"%s", v49);
        if ( !v48[1] )
          break;
        ++v48;
        sub_DC90((long long)stdout, (long long)", ");
        if ( !*v48 )
          goto LABEL_91;
      }
      ++v48;
      sub_DC90((long long)stdout, (long long)"\n");
    }
LABEL_91:
    v50 = (int *)gnutls_sign_list();
    sub_DC90((long long)stdout, (long long)"PK-signatures: ");
    if ( *v50 )
    {
      do
      {
        v52 = (const char *)((long long (*)(void))gnutls_sign_get_name)();
        sub_DC90((long long)stdout, (long long)"SIGN-%s", v52);
        if ( v50[1] )
          sub_DC90((long long)stdout, (long long)", ");
        else
          sub_DC90((long long)stdout, (long long)"\n");
        v51 = v50[1];
        ++v50;
      }
      while ( v51 );
    }
  }
  return v70 - __readfsqword(0x28u);
}


// Function: print_key_material @ 0xf270
unsigned long long print_key_material(long long a1, const char *a2, const char *a3)
{
  long long v4; // rax
  long long v5; // rbx
  size_t v6; // rax
  int v7; // eax
  int v8; // eax
  const char *v10; // rax
  const char *v11; // rax
  const char *v12; // rax
  long long v13; // [rsp+0h] [rbp-58h] BYREF
  int v14; // [rsp+8h] [rbp-50h]
  const char *v15; // [rsp+10h] [rbp-48h] BYREF
  int v16; // [rsp+18h] [rbp-40h]
  unsigned long long v17; // [rsp+28h] [rbp-30h]

  v17 = __readfsqword(0x28u);
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v4 = gnutls_malloc(a3, a2, a3);
  v13 = v4;
  if ( v4 )
  {
    v14 = (int)a3;
    v5 = v4;
    v6 = strlen(a2);
    v7 = gnutls_prf_rfc5705(a1, v6, a2, 0, 0, a3, v5);
    if ( v7 < 0 )
    {
      v10 = (const char *)gnutls_strerror((unsigned int)v7);
      __fprintf_chk(stderr, 1, "Error in gnutls_prf_rfc5705: %s\n", v10);
    }
    else
    {
      v8 = gnutls_hex_encode2(&v13, &v15);
      if ( v8 < 0 )
      {
        v11 = (const char *)gnutls_strerror((unsigned int)v8);
        __fprintf_chk(stderr, 1, "Error in hex encoding: %s\n", v11);
      }
      else
      {
        sub_DC90((long long)stdout, (long long)"- Key material: %s\n", v15);
        fflush(stdout);
      }
    }
  }
  else
  {
    v12 = (const char *)gnutls_strerror(4294967271LL);
    __fprintf_chk(stderr, 1, "Error in gnutls_malloc: %s\n", v12);
  }
  gnutls_free(v13);
  v13 = 0;
  gnutls_free(v15);
  return v17 - __readfsqword(0x28u);
}


// Function: pin_callback @ 0xf410
long long pin_callback(long long a1, long long a2, const char *a3, const char *a4, char a5, char *a6, size_t a7)
{
  const char *v10; // rcx
  int v11; // r15d
  int v12; // r14d
  size_t v13; // rax
  unsigned int v14; // ebx
  const char *v16; // [rsp+0h] [rbp-160h]
  unsigned char *v17; // [rsp+0h] [rbp-160h]
  const char *v18; // [rsp+8h] [rbp-158h]
  char v19; // [rsp+14h] [rbp-14Ch]
  char s[264]; // [rsp+18h] [rbp-148h] BYREF
  unsigned long long v21; // [rsp+120h] [rbp-40h]

  v21 = __readfsqword(0x28u);
  memset(s, 0, 256);
  if ( (a5 & 2) != 0 )
  {
    v16 = "GNUTLS_SO_PIN";
    v18 = "security officer";
    if ( a1 )
    {
      v10 = *(const char **)(a1 + 168);
      if ( v10 )
      {
LABEL_4:
        v19 = a5;
        snprintf(s, 0x100u, "%s", v10);
        a5 = v19;
      }
    }
  }
  else
  {
    v16 = "GNUTLS_PIN";
    v18 = "user";
    if ( a1 )
    {
      v10 = *(const char **)(a1 + 160);
      if ( v10 )
        goto LABEL_4;
    }
  }
  v11 = a5 & 8;
  v12 = a5 & 0x20;
  if ( (a5 & 4) != 0 )
  {
    sub_DC90((long long)stdout, (long long)"*** This is the final try before locking!\n");
    if ( !v11 )
      goto LABEL_21;
    goto LABEL_20;
  }
  if ( (a5 & 8) != 0 )
  {
LABEL_20:
    sub_DC90((long long)stdout, (long long)"*** Only few tries left before locking!\n");
LABEL_21:
    if ( !v12 )
      goto LABEL_22;
    goto LABEL_34;
  }
  if ( (a5 & 0x20) == 0 )
  {
    if ( a3 && ptr && !strcmp(ptr, a3) )
    {
      if ( strlen(&src) < a7 )
      {
        if ( a1 && *(int *)(a1 + 196) )
          __fprintf_chk(stderr, 1, "Re-using cached PIN for token '%s'\n", a4);
        strcpy(a6, &src);
        return 0;
      }
      __fprintf_chk(stderr, 1, "Too long PIN given\n");
LABEL_56:
      exit(1);
    }
LABEL_22:
    v12 = 0;
    if ( s[0] )
      goto LABEL_23;
    goto LABEL_35;
  }
LABEL_34:
  sub_DC90((long long)stdout, (long long)"*** Wrong PIN has been provided!\n");
  if ( s[0] )
    goto LABEL_23;
LABEL_35:
  sub_DC20(s, 0x100u, v16);
  if ( s[0] )
    goto LABEL_23;
  sub_DC20(s, 0x100u, "GNUTLS_PIN");
  if ( s[0] )
    goto LABEL_23;
  if ( !a1 )
  {
LABEL_44:
    if ( a4 && *a4 )
    {
      __fprintf_chk(stderr, 1, "Token '%s' with URL '%s' ", a4, a3);
      __fprintf_chk(stderr, 1, "requires %s PIN\n", v18);
      sub_DBA0(s, 0x100u, "Enter PIN: ");
    }
    else
    {
      sub_DBA0(s, 0x100u, "Enter password: ");
    }
    goto LABEL_24;
  }
  if ( !*(long long *)(a1 + 112) )
  {
    if ( *(int *)(a1 + 188) && !*(int *)(a1 + 128) )
      goto LABEL_23;
    goto LABEL_44;
  }
  if ( *(int *)(a1 + 128) )
    goto LABEL_44;
  v17 = *(unsigned char **)(a1 + 112);
  if ( strlen((const char *)v17) > 0xFF )
  {
    qmemcpy(s, v17, 0xFEu);
    *(short *)&s[254] = v17[254];
  }
  else
  {
    __strcpy_chk(s, v17, 256);
  }
  if ( !s[0] && !*(int *)(a1 + 188) )
    goto LABEL_44;
LABEL_23:
  if ( v12 )
  {
    if ( a4 && *a4 )
    {
      __fprintf_chk(stderr, 1, "Token '%s' with URL '%s' ", a4, a3);
      __fprintf_chk(stderr, 1, "requires %s PIN\n", v18);
    }
    __fprintf_chk(stderr, 1, "Cannot continue with a wrong password in the environment.\n");
    goto LABEL_56;
  }
LABEL_24:
  if ( !s[0] || s[0] == 10 )
  {
    __fprintf_chk(stderr, 1, "No PIN given.\n");
    if ( a1 && *(int *)(a1 + 188) )
      __fprintf_chk(
        stderr,
        1,
        "note: when operating in batch mode, set the GNUTLS_PIN or GNUTLS_SO_PIN environment variables\n");
    goto LABEL_56;
  }
  v13 = strlen(s);
  v14 = a7 - 1;
  if ( a7 - 1 >= v13 )
    v14 = v13;
  memcpy(a6, s, v14);
  a6[v14] = 0;
  if ( v14 <= 0xFF )
    *(char *)(__memcpy_chk(&src, a6, v14, 256) + v14) = 0;
  else
    src = 0;
  free(ptr);
  if ( a3 )
    ptr = strdup(a3);
  else
    ptr = 0;
  return 0;
}


// Function: print_cert_info2 @ 0xfb50
unsigned long long print_cert_info2(long long a1, int a2, long long a3, unsigned int a4)
{
  unsigned int v4; // r15d
  unsigned long long result; // rax

  v4 = 0;
  if ( (unsigned int)gnutls_certificate_client_get_request_status() )
  {
    v4 = 1;
    sub_DC90((long long)stdout, (long long)"- Server has requested a certificate.\n");
  }
  result = gnutls_certificate_type_get2(a1, 3);
  if ( (int)result == 1 )
    return sub_E380(a1, a3, a2 == 0 ? 3 : 0, a4, v4);
  if ( (int)result == 3 )
    return sub_F9A0(a1, a3, a4, v4);
  return result;
}


// Function: print_cert_info @ 0xfc00
unsigned long long print_cert_info(long long a1, int a2, unsigned int a3)
{
  return sub_FB50(a1, a2, (long long)stdout, a3);
}


// Function: print_info @ 0xfc20
long long print_info(long long a1, int a2, char a3)
{
  const char *desc; // r13
  unsigned int v6; // r13d
  const char *v7; // rax
  const char *name; // rdx
  unsigned int v10; // eax
  long long v11; // rax
  const char *v12; // rdx
  unsigned int v13; // eax
  unsigned int v14; // eax
  long long v15; // rax
  const char *v16; // rdx
  unsigned int v17; // eax
  const char *profile_name; // rax
  int is_checked; // eax
  char *v20; // rdx
  const char *v21; // rsi
  int v22; // eax
  long long v23; // rdx
  long long v24; // rcx
  long long v25; // r8
  char *v26; // r9
  const char *username; // rax
  const char *hint; // rax
  const char *v29; // rax
  const char *v30; // rdx
  unsigned int v31; // eax
  long long v32; // rax
  const char *v33; // rdx
  unsigned int v34; // eax
  unsigned int client; // eax
  long long v36; // rax
  const char *v37; // rdx
  unsigned int v38; // eax
  unsigned int version; // [rsp+8h] [rbp-1A0h]
  unsigned int v40; // [rsp+14h] [rbp-194h] BYREF
  long long v41; // [rsp+18h] [rbp-190h] BYREF
  const char *v42; // [rsp+20h] [rbp-188h] BYREF
  int v43; // [rsp+28h] [rbp-180h]
  char v44[48]; // [rsp+30h] [rbp-178h] BYREF
  char v45[264]; // [rsp+60h] [rbp-148h] BYREF
  unsigned long long v46; // [rsp+168h] [rbp-40h]

  v46 = __readfsqword(0x28u);
  v41 = 33;
  desc = (const char *)gnutls_session_get_desc();
  sub_DC90((long long)stdout, (long long)"- Description: %s\n", desc);
  gnutls_free(desc);
  gnutls_session_get_id(a1, v44, &v41);
  if ( v41 )
  {
    v7 = sub_D670((long long)v44, v41);
    sub_DC90((long long)stdout, (long long)"- Session ID: %s\n", v7);
  }
  v6 = gnutls_kx_get(a1);
  switch ( (unsigned int)gnutls_auth_get_type(a1) )
  {
    case 1u:
      v21 = v45;
      v42 = (const char *)&qword_100;
      v22 = gnutls_server_name_get(a1, v45, &v42, &v40, 0);
      v26 = v45;
      if ( !v22 )
      {
        v21 = "- Given server name[%d]: %s\n";
        sub_DC90((long long)stdout, (long long)"- Given server name[%d]: %s\n", v40, v45);
      }
      if ( (a3 & 2) != 0 && !gnutls_certificate_get_ours(a1, v21, v23, v24, v25, v26) )
        sub_DC90((long long)stdout, (long long)"- No certificate was sent to peer\n");
      if ( (a3 & 1) != 0 )
        sub_FC00(a1, a2, 1u);
      if ( v6 - 2 <= 1 )
        goto LABEL_59;
      if ( v6 - 12 <= 1 )
        goto LABEL_38;
      break;
    case 2u:
      if ( v6 == 11 )
        sub_E180(a1, "Anonymous ", a2);
      else
        sub_DF10(a1, "Anonymous ", a2);
      break;
    case 3u:
      if ( gnutls_srp_server_get_username(a1) )
      {
        username = (const char *)gnutls_srp_server_get_username(a1);
        sub_DC90((long long)stdout, (long long)"- SRP authentication. Connected as '%s'\n", username);
      }
      break;
    case 4u:
      if ( gnutls_psk_client_get_hint(a1) )
      {
        hint = (const char *)gnutls_psk_client_get_hint(a1);
        sub_DC90((long long)stdout, (long long)"- PSK authentication. PSK hint '%s'\n", hint);
      }
      if ( gnutls_psk_server_get_username(a1) )
      {
        v29 = (const char *)gnutls_psk_server_get_username(a1);
        sub_DC90((long long)stdout, (long long)"- PSK authentication. Connected as '%s'\n", v29);
      }
      if ( v6 == 10 )
      {
LABEL_59:
        sub_DF10(a1, "Ephemeral ", a2);
      }
      else if ( v6 == 14 )
      {
LABEL_38:
        sub_E180(a1, "Ephemeral ", a2);
      }
      break;
    case 5u:
      sub_DC90((long long)stdout, (long long)"- TLS/IA authentication\n");
      break;
    default:
      break;
  }
  if ( a2 )
  {
    version = gnutls_protocol_get_version(a1);
    name = (const char *)gnutls_protocol_get_name(version);
    if ( !name )
      name = "Unknown";
    sub_DC90((long long)stdout, (long long)"- Version: %s\n", name);
    if ( version <= 4 )
    {
      v30 = (const char *)gnutls_kx_get_name(v6);
      if ( !v30 )
        v30 = "Unknown";
      sub_DC90((long long)stdout, (long long)"- Key Exchange: %s\n", v30);
      if ( !(unsigned int)gnutls_sign_algorithm_get(a1) )
      {
LABEL_22:
        if ( !(unsigned int)gnutls_sign_algorithm_get_client(a1) )
        {
LABEL_23:
          v10 = gnutls_cipher_get(a1);
          v11 = gnutls_cipher_get_name(v10);
          v12 = "Unknown";
          if ( v11 )
          {
            v13 = gnutls_cipher_get(a1);
            v12 = (const char *)gnutls_cipher_get_name(v13);
          }
          sub_DC90((long long)stdout, (long long)"- Cipher: %s\n", v12);
          v14 = gnutls_mac_get(a1);
          v15 = gnutls_mac_get_name(v14);
          v16 = "Unknown";
          if ( v15 )
          {
            v17 = gnutls_mac_get(a1);
            v16 = (const char *)gnutls_mac_get_name(v17);
          }
          sub_DC90((long long)stdout, (long long)"- MAC: %s\n", v16);
          goto LABEL_6;
        }
LABEL_56:
        client = gnutls_sign_algorithm_get_client(a1);
        v36 = gnutls_sign_get_name(client);
        v37 = "Unknown";
        if ( v36 )
        {
          v38 = gnutls_sign_algorithm_get_client(a1);
          v37 = (const char *)gnutls_sign_get_name(v38);
        }
        sub_DC90((long long)stdout, (long long)"- Client Signature: %s\n", v37);
        goto LABEL_23;
      }
    }
    else if ( !(unsigned int)gnutls_sign_algorithm_get(a1) )
    {
      goto LABEL_22;
    }
    v31 = gnutls_sign_algorithm_get(a1);
    v32 = gnutls_sign_get_name(v31);
    v33 = "Unknown";
    if ( v32 )
    {
      v34 = gnutls_sign_algorithm_get(a1);
      v33 = (const char *)gnutls_sign_get_name(v34);
    }
    sub_DC90((long long)stdout, (long long)"- Server Signature: %s\n", v33);
    if ( !(unsigned int)gnutls_sign_algorithm_get_client(a1) )
      goto LABEL_23;
    goto LABEL_56;
  }
LABEL_6:
  sub_DC90((long long)stdout, (long long)"- Options:");
  if ( (unsigned int)gnutls_session_ext_master_secret_status(a1) )
    sub_DC90((long long)stdout, (long long)" extended master secret,");
  if ( (unsigned int)gnutls_safe_renegotiation_status(a1) )
    sub_DC90((long long)stdout, (long long)" safe renegotiation,");
  if ( (unsigned int)gnutls_session_etm_status(a1) )
    sub_DC90((long long)stdout, (long long)" EtM,");
  if ( (unsigned int)gnutls_ocsp_status_request_is_checked(a1, 1) )
  {
    is_checked = gnutls_ocsp_status_request_is_checked(a1, 0);
    v20 = "";
    if ( !is_checked )
      v20 = "[ignored]";
    sub_DC90((long long)stdout, (long long)" OCSP status request%s,", v20);
  }
  sub_DC90((long long)stdout, (long long)"\n");
  if ( !(unsigned int)gnutls_srtp_get_selected_profile(a1, &v40) )
  {
    profile_name = (const char *)gnutls_srtp_get_profile_name(v40);
    sub_DC90((long long)stdout, (long long)"- SRTP profile: %s\n", profile_name);
  }
  if ( !(unsigned int)gnutls_alpn_get_selected_protocol(a1, &v42) )
    sub_DC90((long long)stdout, (long long)"- Application protocol: %.*s\n", v43, v42);
  sub_E200(a1, a2);
  fflush(stdout);
  return 0;
}


// Function: log_set @ 0x102d0
void log_set(long long a1)
{
  qword_24480 = a1;
}


// Function: simple_ctime @ 0x102e0
char *simple_ctime(const time_t *a1, char *a2)
{
  struct tm v3; // [rsp+0h] [rbp-58h] BYREF
  unsigned long long v4; // [rsp+38h] [rbp-20h]

  v4 = __readfsqword(0x28u);
  if ( !localtime_r(a1, &v3) || !strftime(a2, 0x40u, "%c", &v3) )
    *(long long *)a2 = 0x5D726F7272655BLL;
  return a2;
}


// Function: wrap_pull_timeout_func @ 0x10380
long long wrap_pull_timeout_func(int *a1)
{
  return gnutls_system_recv_timeout(*a1);
}


// Function: wrap_pull @ 0x10390
ssize_t wrap_pull(long long a1, void *a2, size_t a3)
{
  ssize_t v3; // rax
  ssize_t v4; // r12
  FILE *v5; // rcx

  v3 = recv(*(int *)a1, a2, a3, 0);
  v4 = v3;
  if ( v3 > 0 )
  {
    v5 = *(FILE **)(a1 + 216);
    if ( v5 )
      fwrite(a2, 1u, v3, v5);
  }
  return v4;
}


// Function: wrap_push @ 0x103e0
ssize_t wrap_push(long long a1, const void *a2, size_t a3)
{
  FILE *v4; // rcx

  v4 = *(FILE **)(a1 + 224);
  if ( v4 )
    fwrite(a2, 1u, a3, v4);
  return send(*(int *)a1, a2, a3, 0);
}


// Function: socket_starttls @ 0x10720
long long socket_starttls(long long a1)
{
  int v1; // r8d
  const char *v2; // r12
  long long v4; // rdx
  const char *v5; // rsi
  const char *v6; // r12
  char v7[520]; // [rsp+0h] [rbp-228h] BYREF
  unsigned long long v8; // [rsp+208h] [rbp-20h]

  v1 = *(int *)(a1 + 16);
  v8 = __readfsqword(0x28u);
  if ( v1 )
    return v8 - __readfsqword(0x28u);
  v2 = *(const char **)(a1 + 32);
  if ( !v2 || !strcasecmp(*(const char **)(a1 + 32), "https") )
    return v8 - __readfsqword(0x28u);
  if ( !strcasecmp(v2, "smtp") || !strcasecmp(v2, "submission") )
  {
    if ( *(int *)(a1 + 72) )
      sub_DC90((long long)stdout, (long long)"Negotiating SMTP STARTTLS\n");
    sub_10420(a1, "220 ", 4);
    __snprintf_chk(v7, 512, 1, 512, "EHLO %s\r\n", *(long long *)(a1 + 24));
LABEL_16:
    sub_10690(a1, v7);
    sub_10420(a1, "250 ", 4);
    sub_10690(a1, "STARTTLS\r\n");
    sub_10420(a1, "220 ", 4);
    return v8 - __readfsqword(0x28u);
  }
  if ( !strcasecmp(v2, "imap") || !strcasecmp(v2, "imap2") )
  {
    if ( *(int *)(a1 + 72) )
      sub_DC90((long long)stdout, (long long)"Negotiating IMAP STARTTLS\n");
    sub_10690(a1, "a CAPABILITY\r\n");
    sub_10420(a1, "a OK", 4);
    sub_10690(a1, "a STARTTLS\r\n");
    v4 = 4;
    v5 = "a OK";
    return sub_10420(a1, v5, v4);
  }
  if ( !strcasecmp(v2, "xmpp") )
  {
    if ( *(int *)(a1 + 72) )
      sub_DC90((long long)stdout, (long long)"Negotiating XMPP STARTTLS\n");
    __snprintf_chk(
      v7,
      512,
      1,
      512,
      "<stream:stream xmlns:stream='http://etherx.jabber.org/streams' xmlns='jabber:client' to='%s' version='1.0'>\n",
      *(const char **)(a1 + 24));
    sub_10690(a1, v7);
    sub_10420(a1, "<?", 2);
    sub_10690(a1, "<starttls xmlns='urn:ietf:params:xml:ns:xmpp-tls'/>");
    sub_10420(a1, "<proceed", 8);
    return v8 - __readfsqword(0x28u);
  }
  if ( strcasecmp(v2, "ldap") )
  {
    if ( !strcasecmp(v2, "ftp") || !strcasecmp(v2, "ftps") )
    {
      if ( *(int *)(a1 + 72) )
        sub_DC90((long long)stdout, (long long)"Negotiating FTP STARTTLS\n");
      sub_10690(a1, "FEAT\r\n");
      sub_10420(a1, "211 ", 4);
      sub_10690(a1, "AUTH TLS\r\n");
      v4 = 3;
      v5 = "234";
      return sub_10420(a1, v5, v4);
    }
    if ( strcasecmp(v2, "lmtp") )
    {
      if ( !strcasecmp(v2, "pop3") )
      {
        if ( *(int *)(a1 + 72) )
          sub_DC90((long long)stdout, (long long)"Negotiating POP3 STARTTLS\n");
        v6 = "+OK";
        sub_10420(a1, "+OK", 3);
        sub_10690(a1, "STLS\r\n");
      }
      else
      {
        if ( !strcasecmp(v2, "nntp") )
        {
          if ( *(int *)(a1 + 72) )
            sub_DC90((long long)stdout, (long long)"Negotiating NNTP STARTTLS\n");
          sub_10420(a1, "200 ", 4);
          sub_10690(a1, "STARTTLS\r\n");
          v4 = 4;
          v5 = "382 ";
          return sub_10420(a1, v5, v4);
        }
        if ( strcasecmp(v2, "sieve") )
        {
          if ( strcasecmp(v2, "postgres") && strcasecmp(v2, "postgresql") )
          {
            if ( !(unsigned char)sub_15730((unsigned int)*v2) && !dword_24488 )
            {
              __fprintf_chk(stderr, 1, "unknown protocol '%s'\n", v2);
              dword_24488 = 1;
            }
            return v8 - __readfsqword(0x28u);
          }
          if ( *(int *)(a1 + 72) )
            sub_DC90((long long)stdout, (long long)"Negotiating PostgreSQL STARTTLS\n");
          send(*(int *)a1, &unk_18139, 8u, 0);
          goto LABEL_25;
        }
        if ( *(int *)(a1 + 72) )
          sub_DC90((long long)stdout, (long long)"Negotiating Sieve STARTTLS\n");
        v6 = "OK ";
        sub_10420(a1, "OK ", 3);
        sub_10690(a1, "STARTTLS\r\n");
      }
      v4 = 3;
      v5 = v6;
      return sub_10420(a1, v5, v4);
    }
    if ( *(int *)(a1 + 72) )
      sub_DC90((long long)stdout, (long long)"Negotiating LMTP STARTTLS\n");
    sub_10420(a1, "220 ", 4);
    __snprintf_chk(v7, 512, 1, 512, "LHLO %s\r\n", *(long long *)(a1 + 24));
    goto LABEL_16;
  }
  if ( *(int *)(a1 + 72) )
    sub_DC90((long long)stdout, (long long)"Negotiating LDAP STARTTLS\n");
  send(*(int *)a1, &unk_17CA8, 0x1Fu, 0);
LABEL_25:
  v4 = 0;
  v5 = 0;
  return sub_10420(a1, v5, v4);
}


// Function: socket_recv @ 0x10d90
long long socket_recv(long long a1, void *a2, int a3)
{
  size_t v3; // rbp
  int v4; // eax
  int v5; // edx

  v3 = a3;
  if ( *(int *)(a1 + 16) )
  {
    do
    {
      while ( 1 )
      {
        v4 = gnutls_record_recv(*(long long *)(a1 + 8), a2, v3);
        v5 = v4;
        if ( v4 != -293 )
          break;
        gnutls_heartbeat_pong(*(long long *)(a1 + 8), 0, 4294967003LL);
      }
    }
    while ( v4 == -52 );
  }
  else
  {
    while ( 1 )
    {
      v5 = recv(*(int *)a1, a2, v3, 0);
      if ( v5 != -1 )
        break;
      if ( *__errno_location() != 4 )
        return -1;
    }
  }
  return v5;
}


// Function: socket_recv_timeout @ 0x10e20
long long socket_recv_timeout(long long a1, void *a2, int a3, unsigned int a4)
{
  int v4; // ebp
  int v6; // [rsp+Ch] [rbp-1Ch]

  if ( *(int *)(a1 + 16) )
  {
    v6 = a3;
    gnutls_record_set_timeout(*(long long *)(a1 + 8), a4);
    a3 = v6;
  }
  v4 = sub_10D90(a1, a2, a3);
  if ( *(int *)(a1 + 16) )
    gnutls_record_set_timeout(*(long long *)(a1 + 8), 0);
  return v4;
}


// Function: socket_send_range @ 0x10e90
long long socket_send_range(long long a1, const void *a2, int a3, long long a4)
{
  size_t v5; // r12
  long long v8; // rdi
  int v9; // ecx
  long long v10; // r12

  v5 = a3;
  if ( *(int *)(a1 + 16) )
  {
    do
    {
      v8 = *(long long *)(a1 + 8);
      if ( a4 )
        v9 = gnutls_record_send_range(v8, a2, v5, a4);
      else
        v9 = gnutls_record_send(v8, a2, v5);
    }
    while ( v9 == -28 || v9 == -52 );
  }
  else
  {
    while ( 1 )
    {
      v9 = send(*(int *)a1, a2, v5, 0);
      if ( v9 != -1 )
        break;
      if ( *__errno_location() != 4 )
        return -1;
    }
  }
  v10 = v9;
  if ( v9 <= 0 || v9 == a3 || !*(int *)(a1 + 72) )
    return v9;
  __fprintf_chk(stderr, 1, "*** Only sent %d bytes instead of %d.\n", v9, a3);
  return v10;
}


// Function: socket_send @ 0x10f90
long long socket_send(long long a1, const void *a2, int a3)
{
  return sub_10E90(a1, a2, a3, 0);
}


// Function: starttls_proto_to_service @ 0x10ff0
const char *starttls_proto_to_service(const char *a1)
{
  const char *v1; // rbp
  struct servent *v2; // rax

  v1 = a1;
  if ( !strcasecmp(a1, "xmpp") )
    v1 = "xmpp-server";
  v2 = getservbyname(v1, 0);
  if ( v2 )
    return v2->s_name;
  endservent();
  return "443";
}


// Function: socket_bye @ 0x11040
int socket_bye(long long a1, int a2)
{
  long long v3; // rdi
  int v4; // eax
  void *v5; // rdi
  int result; // eax
  FILE *v7; // rdi
  FILE *v8; // rdi
  const char *v9; // rax

  v3 = *(long long *)(a1 + 8);
  if ( *(int *)(a1 + 16) && a2 )
  {
    if ( !v3 )
      goto LABEL_13;
    v4 = gnutls_bye(v3, 1);
    if ( v4 != -52 )
      goto LABEL_6;
    do
    {
      do
        v4 = gnutls_bye(*(long long *)(a1 + 8), 1);
      while ( v4 == -52 );
LABEL_6:
      ;
    }
    while ( v4 == -28 );
    if ( *(int *)(a1 + 72) && v4 < 0 )
    {
      v9 = (const char *)gnutls_strerror((unsigned int)v4);
      __fprintf_chk(stderr, 1, "*** gnutls_bye() error: %s\n", v9);
    }
    v3 = *(long long *)(a1 + 8);
  }
  if ( v3 )
  {
    gnutls_deinit();
    *(long long *)(a1 + 8) = 0;
  }
LABEL_13:
  freeaddrinfo(*(struct addrinfo **)(a1 + 64));
  *(long long *)(a1 + 56) = 0;
  v5 = *(void **)(a1 + 40);
  *(long long *)(a1 + 64) = 0;
  *(int *)(a1 + 208) = 0;
  free(v5);
  free(*(void **)(a1 + 24));
  free(*(void **)(a1 + 48));
  shutdown(*(int *)a1, 2);
  close(*(int *)a1);
  result = gnutls_free(*(long long *)(a1 + 232));
  v7 = *(FILE **)(a1 + 216);
  *(long long *)(a1 + 232) = 0;
  if ( v7 )
    result = fclose(v7);
  v8 = *(FILE **)(a1 + 224);
  if ( v8 )
    result = fclose(v8);
  *(int *)a1 = -1;
  *(int *)(a1 + 16) = 0;
  return result;
}


// Function: canonicalize_host @ 0x11180
unsigned long long canonicalize_host(char *s, char *a2, size_t maxlen)
{
  unsigned int v3; // r12d
  char *v4; // rax
  char *v5; // rbx
  long long v7; // [rsp+0h] [rbp-78h] BYREF
  unsigned long long v8; // [rsp+48h] [rbp-30h]

  v3 = maxlen;
  v8 = __readfsqword(0x28u);
  v4 = strchr(s, 58);
  if ( v4 )
  {
    v5 = v4;
    if ( inet_pton(10, s, &v7) == 1 )
      return v8 - __readfsqword(0x28u);
    *v5 = 0;
    if ( a2 && v3 )
      snprintf(a2, v3, "%s", v5 + 1);
  }
  else
  {
    v5 = &s[strlen(s)];
  }
  if ( v5 > s && *(v5 - 1) == 46 )
    *(v5 - 1) = 0;
  return v8 - __readfsqword(0x28u);
}


// Function: socket_open2 @ 0x11250
unsigned long long socket_open2(
        int *a1,
        char *a2,
        const char *a3,
        long long a4,
        char a5,
        const char *a6,
        long long a7,
        long long a8,
        __int128 a9)
{
  unsigned long long v11; // rdi
  int v12; // r13d
  unsigned int v13; // eax
  int v14; // eax
  char *v15; // rax
  char *v16; // r14
  int v17; // eax
  int v18; // r15d
  struct addrinfo *v19; // r12
  int v20; // ebp
  int v21; // eax
  long long v22; // rdi
  long long v23; // rsi
  long long v24; // rsi
  long long v25; // rdi
  int v26; // eax
  char *v27; // rax
  long long v28; // rdi
  long long v29; // rdi
  char *v30; // rdi
  const char *v32; // rax
  long long v33; // rax
  int *v34; // rax
  char *v35; // rax
  const char *v36; // rax
  const char *v37; // rax
  const char *v38; // rax
  int v42; // [rsp+20h] [rbp-10C8h]
  int v43; // [rsp+24h] [rbp-10C4h]
  int optval; // [rsp+44h] [rbp-10A4h] BYREF
  struct addrinfo *pai; // [rsp+48h] [rbp-10A0h] BYREF
  char *name; // [rsp+50h] [rbp-1098h] BYREF
  struct addrinfo req; // [rsp+60h] [rbp-1088h] BYREF
  char serv[16]; // [rsp+90h] [rbp-1058h] BYREF
  char host[24]; // [rsp+A0h] [rbp-1048h] BYREF
  unsigned long long v51; // [rsp+10A8h] [rbp-40h]

  v11 = (unsigned long long)(a1 + 2);
  v12 = a5 & 1;
  v51 = __readfsqword(0x28u);
  *(_OWORD *)serv = 0;
  v42 = a5 & 2;
  *(long long *)(v11 - 8) = 0;
  *(long long *)(v11 + 248) = 0;
  memset((void *)(v11 & 0xFFFFFFFFFFFFFFF8LL), 0, 8 * (((unsigned int)a1 - (v11 & 0xFFFFFFF8) + 264) >> 3));
  if ( (a5 & 0x10) != 0 )
    a1[18] = 1;
  if ( a7 )
  {
    *((long long *)a1 + 29) = *(long long *)a7;
    a1[60] = *(int *)(a7 + 8);
  }
  if ( a8 )
  {
    *((long long *)a1 + 31) = *(long long *)a8;
    a1[64] = *(int *)(a8 + 8);
  }
  v13 = strlen(a2);
  v14 = gnutls_idna_map(a2, v13, &name, 0);
  if ( v14 < 0 )
  {
    v36 = (const char *)gnutls_strerror((unsigned int)v14);
    __fprintf_chk(stderr, 1, "Cannot convert %s to IDNA: %s\n", a2, v36);
    exit(1);
  }
  v15 = strdup(a2);
  v16 = name;
  *((long long *)a1 + 3) = v15;
  if ( a6 )
    sub_DC90((long long)stdout, (long long)"Resolving '%s:%s'...\n", v16, a3);
  memset(&req, 0, sizeof(req));
  req.ai_socktype = v12 + 1;
  v17 = getaddrinfo(v16, a3, &req, &pai);
  v18 = v17;
  if ( v17 )
  {
    v38 = gai_strerror(v17);
    __fprintf_chk(stderr, 1, "Cannot resolve %s:%s: %s\n", a2, a3, v38);
LABEL_55:
    exit(1);
  }
  v19 = pai;
  if ( !pai )
    goto LABEL_53;
  while ( 1 )
  {
    while ( 1 )
    {
      v20 = socket(v19->ai_family, v19->ai_socktype, v19->ai_protocol);
      if ( v20 != -1 )
        break;
LABEL_36:
      v19 = v19->ai_next;
      if ( !v19 )
        goto LABEL_37;
    }
    v21 = getnameinfo(v19->ai_addr, v19->ai_addrlen, host, 0x1000u, serv, 0x10u, 3);
    v18 = v21;
    if ( v21 )
    {
      v32 = gai_strerror(v21);
      __fprintf_chk(stderr, 1, "getnameinfo(): %s\n", v32);
      close(v20);
      goto LABEL_36;
    }
    if ( req.ai_socktype == 2 )
    {
      optval = 2;
      if ( setsockopt(v20, 0, 10, &optval, 4u) < 0 )
        perror("setsockopt(IP_DF) failed");
    }
    if ( v42 && v19->ai_socktype == 1 && (v19->ai_family & 0xFFFFFFF7) == 2 )
    {
      memcpy(a1 + 20, v19->ai_addr, v19->ai_addrlen);
      a1[52] = v19->ai_addrlen;
      if ( a6 )
        sub_DC90((long long)stdout, (long long)"%s '%s:%s' (TFO)...\n", a6, host, serv);
    }
    else
    {
      if ( a6 )
        sub_DC90((long long)stdout, (long long)"%s '%s:%s'...\n", a6, host, serv);
      v18 = connect(v20, v19->ai_addr, v19->ai_addrlen);
      if ( v18 < 0 )
        goto LABEL_48;
    }
    *a1 = v20;
    if ( (a5 & 4) != 0 )
    {
      *((long long *)a1 + 4) = a4;
      sub_10720((long long)a1);
      *((long long *)a1 + 4) = 0;
    }
    if ( (a5 & 0x20) != 0 )
    {
      v22 = *((long long *)a1 + 1);
      if ( !v22 )
        goto LABEL_30;
    }
    else
    {
      v33 = sub_CD30(a2);
      *((long long *)a1 + 1) = v33;
      v22 = v33;
      if ( !v33 )
      {
        __fprintf_chk(stderr, 1, "error initializing session\n");
        goto LABEL_46;
      }
    }
    v23 = *((long long *)a1 + 31);
    if ( v23 && (int)gnutls_record_send_early_data(v22, v23, (unsigned int)a1[64]) < 0 )
    {
      __fprintf_chk(stderr, 1, "error sending early data\n");
      goto LABEL_46;
    }
    v24 = *((long long *)a1 + 29);
    if ( v24 )
      gnutls_session_set_data(*((long long *)a1 + 1), v24, (unsigned int)a1[60]);
    v25 = *((long long *)a1 + 1);
    if ( a9 == 0 )
    {
      gnutls_transport_set_int2(v25, (unsigned int)*a1, (unsigned int)*a1);
    }
    else
    {
      *(_OWORD *)(a1 + 54) = a9;
      gnutls_transport_set_push_function(v25, sub_103E0);
      gnutls_transport_set_pull_function(*((long long *)a1 + 1), sub_10390);
      gnutls_transport_set_pull_timeout_function(*((long long *)a1 + 1), sub_10380);
      gnutls_transport_set_ptr(*((long long *)a1 + 1), a1);
    }
LABEL_30:
    v43 = a5 & 0x28;
    if ( (a5 & 0x28) != 0 )
      goto LABEL_33;
    v26 = sub_D200((unsigned int *)a1);
    v18 = v26;
    if ( v26 != -53 )
      break;
    gnutls_deinit(*((long long *)a1 + 1));
    *((long long *)a1 + 1) = 0;
LABEL_48:
    close(v20);
    v19 = v19->ai_next;
    if ( !v19 )
    {
LABEL_37:
      if ( v18 )
        goto LABEL_54;
      if ( v20 != -1 )
      {
        v43 = a5 & 0x28;
        goto LABEL_34;
      }
LABEL_53:
      __fprintf_chk(stderr, 1, "Could not find a supported socket\n");
      exit(1);
    }
  }
  if ( v26 < 0 )
  {
    if ( (a5 & 0x40) == 0 )
    {
      v37 = (const char *)gnutls_strerror((unsigned int)v26);
      __fprintf_chk(stderr, 1, "*** handshake has failed: %s\n", v37);
    }
LABEL_46:
    close(v20);
    exit(1);
  }
LABEL_33:
  if ( v18 )
  {
LABEL_54:
    v34 = __errno_location();
    v35 = strerror(*v34);
    __fprintf_chk(stderr, 1, "Could not connect to %s:%s: %s\n", host, serv, v35);
    goto LABEL_55;
  }
LABEL_34:
  *a1 = v20;
  a1[4] = v43 == 0;
  *((long long *)a1 + 5) = strdup(host);
  v27 = strdup(serv);
  v28 = *((long long *)a1 + 29);
  *((long long *)a1 + 7) = v19;
  *((long long *)a1 + 6) = v27;
  *((long long *)a1 + 8) = pai;
  gnutls_free(v28);
  v29 = *((long long *)a1 + 31);
  *((long long *)a1 + 29) = 0;
  gnutls_free(v29);
  v30 = name;
  *((long long *)a1 + 31) = 0;
  gnutls_free(v30);
  return v51 - __readfsqword(0x28u);
}


// Function: port_to_service @ 0x11920
char *port_to_service(char *nptr, char *proto)
{
  int v2; // eax
  unsigned short v4; // ax
  struct servent *v5; // rax

  if ( !(unsigned char)sub_15730((unsigned int)*nptr) )
    return nptr;
  v2 = atoi(nptr);
  if ( !v2 )
    return nptr;
  v4 = sub_10370((unsigned short)v2, proto);
  v5 = getservbyport(v4, proto);
  if ( !v5 )
  {
    __fprintf_chk(stderr, 1, "Warning: getservbyport(%s) failed. Using port number as service.\n", nptr);
    return nptr;
  }
  return v5->s_name;
}


// Function: service_to_port @ 0x119a0
int service_to_port(char *name, char *proto)
{
  int result; // eax
  struct servent *v3; // rax

  result = atoi(name);
  if ( !result )
  {
    v3 = getservbyname(name, proto);
    if ( !v3 )
    {
      __fprintf_chk(stderr, 1, "Warning: getservbyname() failed for '%s/%s'.\n", name, proto);
      exit(1);
    }
    return (unsigned short)sub_10370(LOWORD(v3->s_port), proto);
  }
  return result;
}


// Function: force_memcpy @ 0x11a50
void force_memcpy(char *a1, char *a2, size_t a3)
{
  if ( a3 )
  {
    do
      a1 = memcpy(a1, a2, a3);
    while ( *a1 != *a2 );
  }
}


// Function: benchmark_cipher @ 0x12480
long long benchmark_cipher(unsigned int a1)
{
  gnutls_global_set_log_function(sub_11A20);
  gnutls_global_set_log_level(a1);
  dword_200A0 = sysconf(30);
  __printf_chk(1, "Checking AEAD ciphers, payload size: %u\n", 0x4000);
  sub_11C70(10, 1);
  sub_11C70(19, 1);
  sub_11C70(23, 1);
  __printf_chk(1, "\nChecking cipher-MAC combinations, payload size: %u\n", 0x4000);
  sub_12150(13, 3);
  sub_12150(4, 3);
  sub_12150(4, 6);
  sub_12150(34, 208);
  __printf_chk(1, "\nChecking MAC algorithms, payload size: %u\n", 0x4000);
  sub_11AA0(3);
  sub_11AA0(6);
  sub_11AA0(8);
  sub_11AA0(208);
  sub_11AA0(15);
  sub_11AA0(17);
  __printf_chk(1, "\nChecking ciphers, payload size: %u\n", 0x4000);
  sub_11C70(3, 0);
  sub_11C70(4, 0);
  sub_11C70(32, 0);
  sub_11C70(33, 0);
  sub_11C70(13, 0);
  sub_11C70(1, 1);
  sub_11C70(34, 0);
  return gnutls_global_deinit();
}


// Function: alarm_handler @ 0x12610
void alarm_handler()
{
  dword_2448C = 1;
}


// Function: value2human @ 0x12620
char *value2human(unsigned long long a1, double *a2, double *a3, char *a4, double a5)
{
  char *result; // rax
  double v6; // xmm1_8
  double v7; // xmm1_8
  double v8; // xmm1_8
  double v9; // xmm1_8

  result = a4;
  if ( a1 - 1001 <= 0xF3E56 )
  {
    v8 = (double)(int)a1 / 1000.0;
    *a2 = v8;
    *a3 = v8 / a5;
    strcpy(a4, "KB");
  }
  else if ( a1 - 1000000 <= 0x3B8B87BF )
  {
    v9 = (double)(int)a1 / 1000000.0;
    *a2 = v9;
    *a3 = v9 / a5;
    strcpy(a4, "MB");
  }
  else if ( a1 <= 0x3B9AC9FF )
  {
    *a2 = (double)(int)a1;
    *a3 = (double)(int)a1 / a5;
    strcpy(a4, "bytes");
  }
  else
  {
    if ( (a1 & 0x8000000000000000LL) != 0LL )
      v6 = (double)(int)(a1 & 1 | (a1 >> 1)) + (double)(int)(a1 & 1 | (a1 >> 1));
    else
      v6 = (double)(int)a1;
    v7 = v6 / 1000000000.0;
    *a2 = v7;
    *a3 = v7 / a5;
    strcpy(a4, "GB");
  }
  return result;
}


// Function: start_benchmark @ 0x12770
unsigned int start_benchmark(struct timespec *tp)
{
  *tp = 0;
  tp[1] = 0;
  tp[1].tv_nsec = (__syscall_slong_t)signal(14, (__sighandler_t)handler);
  clock_gettime(2, tp);
  dword_2448C = 0;
  return alarm(5u);
}


// Function: stop_benchmark @ 0x127c0
double stop_benchmark(long long *a1, const char *a2, int a3, double a4)
{
  void (*v6)(int); // rsi
  int v7; // eax
  double v8; // xmm1_8
  long long v9; // rax
  double v10; // xmm0_8
  double v11; // xmm2_8
  const char *v12; // rdx
  double v13; // xmm0_8
  long long v15; // rdx
  double v16; // xmm1_8
  double v17; // [rsp+0h] [rbp-68h]
  double v18; // [rsp+0h] [rbp-68h]
  double v19; // [rsp+10h] [rbp-58h] BYREF
  double v20; // [rsp+18h] [rbp-50h] BYREF
  struct timespec tp; // [rsp+20h] [rbp-48h] BYREF
  char v22[24]; // [rsp+30h] [rbp-38h] BYREF
  unsigned long long v23; // [rsp+48h] [rbp-20h]

  v6 = (void (*)(int))a1[3];
  v23 = __readfsqword(0x28u);
  signal(14, v6);
  clock_gettime(2, &tp);
  v7 = sub_12740(tp.tv_sec, tp.tv_nsec, *a1, a1[1], a4, 0.0);
  v8 = (double)v7 / 1000.0;
  if ( a2 )
  {
    v9 = a1[2];
    if ( v9 < 0 )
    {
      v15 = a1[2] & 1LL | (a1[2] >> 1);
      v10 = (double)(int)v15 + (double)(int)v15;
      v11 = v10 / v8;
      if ( a3 )
        goto LABEL_4;
    }
    else
    {
      v10 = (double)(int)v9;
      v11 = (double)(int)v9 / v8;
      if ( a3 )
      {
LABEL_4:
        v17 = v8;
        v12 = a2;
        v13 = v11;
        goto LABEL_5;
      }
    }
    __printf_chk(1, "  Processed %.2f %s in %.2f secs: ", v10, a2, v8);
    goto LABEL_4;
  }
  v18 = (double)v7 / 1000.0;
  sub_12620(a1[2], &v20, &v19, v22, v8);
  v16 = v18;
  if ( !a3 )
  {
    __printf_chk(1, "  Processed %.2f %s in %.2f secs: ", v20, v22, v18);
    v16 = v18;
  }
  v13 = v19;
  v17 = v16;
  v12 = v22;
LABEL_5:
  __printf_chk(1, "%.2f %s/sec\n", v13, v12);
  return v17;
}


// Function: test_ciphersuite @ 0x129c0
unsigned long long test_ciphersuite(long long a1, int a2, double a3)
{
  int i; // r12d
  int v4; // eax
  unsigned int v5; // r13d
  unsigned int v6; // r12d
  const char *v7; // rax
  const char *v8; // rax
  unsigned int v9; // eax
  const char *name; // r12
  unsigned int version; // eax
  const char *v12; // rax
  int v13; // eax
  int v14; // eax
  double v15; // xmm0_8
  long long v17; // rax
  bool j; // al
  unsigned int v19; // eax
  long long v20; // [rsp+0h] [rbp-98h] BYREF
  long long v21; // [rsp+8h] [rbp-90h] BYREF
  long long v22; // [rsp+10h] [rbp-88h] BYREF
  long long v23; // [rsp+18h] [rbp-80h] BYREF
  long long v24; // [rsp+20h] [rbp-78h] BYREF
  long long v25; // [rsp+28h] [rbp-70h] BYREF
  long long v26; // [rsp+30h] [rbp-68h] BYREF
  long long v27; // [rsp+38h] [rbp-60h] BYREF
  struct timespec tp; // [rsp+40h] [rbp-58h] BYREF
  long long v29; // [rsp+50h] [rbp-48h]
  unsigned long long v30; // [rsp+68h] [rbp-30h]

  v30 = __readfsqword(0x28u);
  gnutls_anon_allocate_server_credentials(&v20);
  gnutls_certificate_allocate_credentials(&v22);
  gnutls_certificate_set_x509_key_mem(v22, &off_1E9F0, &off_1E9D0, 1);
  gnutls_certificate_set_x509_key_mem(v22, &off_1E9C0, &off_1E9B0, 1);
  gnutls_certificate_set_x509_key_mem(v22, &off_1EA00, &off_1EA10, 1);
  gnutls_init(&v23, 1);
  if ( (int)gnutls_priority_set_direct(v23, a1, &v24) < 0 )
    goto LABEL_25;
  gnutls_credentials_set(v23, 2, v20);
  gnutls_credentials_set(v23, 1, v22);
  gnutls_transport_set_push_function(v23, &sub_12ED0);
  gnutls_transport_set_pull_function(v23, &sub_12FA0);
  gnutls_transport_set_ptr(v23, v23);
  sub_12970(&v25);
  gnutls_anon_allocate_client_credentials(&v25);
  gnutls_certificate_allocate_credentials(&v21);
  gnutls_init(&v26, 2);
  if ( (int)gnutls_priority_set_direct(v26, a1, &v24) < 0 )
    goto LABEL_25;
  gnutls_credentials_set(v26, 2, v25);
  gnutls_credentials_set(v26, 1, v21);
  gnutls_transport_set_push_function(v26, &sub_12E80);
  gnutls_transport_set_pull_function(v26, &sub_12F20);
  gnutls_transport_set_ptr(v26, v26);
LABEL_4:
  while ( 2 )
  {
    while ( 2 )
    {
      for ( i = -28; ; i = 0 )
      {
        off_22298 = "client";
        v4 = gnutls_handshake(v26);
        v5 = v4;
        if ( v4 == -52 )
        {
          if ( i != -28 )
            continue;
          off_22298 = "server";
          v6 = gnutls_handshake(v23);
          if ( v6 == -52 )
            goto LABEL_4;
          goto LABEL_11;
        }
        if ( i == -28 )
          break;
        if ( v4 != -28 )
        {
          v6 = 0;
          goto LABEL_16;
        }
LABEL_7:
        ;
      }
      off_22298 = "server";
      v6 = gnutls_handshake(v23);
      if ( v6 == -52 )
      {
        if ( v5 != -28 )
          goto LABEL_38;
        continue;
      }
      break;
    }
    if ( v5 == -28 )
    {
LABEL_11:
      if ( v6 == -28 )
        continue;
      if ( v6 )
      {
        v5 = -28;
        goto LABEL_14;
      }
      goto LABEL_7;
    }
    break;
  }
  for ( j = v6 == -28 && v5 == 0; j; j = v5 == 0 )
  {
    while ( 1 )
    {
      off_22298 = "server";
      v5 = 0;
      v19 = gnutls_handshake(v23);
      v6 = v19;
      if ( v19 == -52 )
        break;
      if ( v19 != -28 )
        goto LABEL_36;
    }
LABEL_38:
    v6 = -28;
  }
LABEL_36:
  v4 = v5 | v6;
LABEL_16:
  if ( v4 )
  {
LABEL_14:
    v7 = (const char *)gnutls_strerror(v5);
    __fprintf_chk(stderr, 1, "client[%d]: %s\n", v5, v7);
    v8 = (const char *)gnutls_strerror(v6);
    __fprintf_chk(stderr, 1, "server[%d]: %s\n", v6, v8);
    __fprintf_chk(stderr, 1, "Handshake failed\n");
    goto LABEL_29;
  }
  v9 = gnutls_cipher_get(v23);
  name = (const char *)gnutls_cipher_get_name(v9);
  version = gnutls_protocol_get_version(v23);
  v12 = (const char *)gnutls_protocol_get_name(version);
  __fprintf_chk(stdout, 1, "%30s - %s  ", name, v12);
  fflush(stdout);
  if ( (int)gnutls_rnd(0, &unk_644C0, &loc_10000) < 0 )
  {
LABEL_25:
    __fprintf_chk(stderr, 1, "Error in %s\n", v24);
    goto LABEL_26;
  }
  sub_12770(&tp);
  do
  {
    do
      v13 = gnutls_record_send(v26, &unk_644C0, a2);
    while ( v13 == -28 );
    if ( v13 < 0 )
    {
      __fprintf_chk(stderr, 1, "Failed sending to server\n");
LABEL_29:
      exit(1);
    }
    do
      v14 = gnutls_record_recv_packet(v23, &v27);
    while ( v14 == -28 );
    if ( v14 < 0 )
    {
      v17 = gnutls_strerror((unsigned int)v14);
      __fprintf_chk(stderr, 1, "Failed receiving from client: %s\n", v17);
LABEL_26:
      exit(1);
    }
    v29 += a2;
    gnutls_packet_deinit(v27);
  }
  while ( !dword_2448C );
  v15 = sub_127C0(&tp, 0, 1, a3);
  gnutls_bye(v26, 1);
  gnutls_bye(v23, 1);
  gnutls_deinit(v26);
  gnutls_deinit(v23);
  gnutls_anon_free_client_credentials(v25);
  gnutls_anon_free_server_credentials(v20, v15);
  return v30 - __readfsqword(0x28u);
}


// Function: test_ciphersuite_kx @ 0x13160
unsigned long long test_ciphersuite_kx(long long a1, int a2, double a3)
{
  int v4; // eax
  int v5; // eax
  int i; // r12d
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // r9d
  const char *v10; // rax
  const char *v11; // rax
  unsigned long long *v12; // rbp
  long long v13; // rax
  long long v14; // r8
  unsigned int v15; // r9d
  const char *v16; // r12
  double v17; // xmm0_8
  unsigned int v18; // r8d
  double v19; // xmm0_8
  double v20; // xmm2_8
  unsigned long long v21; // rdx
  double v22; // xmm0_8
  double v23; // xmm0_8
  unsigned __int128 v25; // rax
  long long v26; // rdi
  long long v27; // rax
  int v28; // ecx
  const char *v29; // r8
  long long v30; // rax
  long long v31; // rax
  int v32; // eax
  bool v33; // al
  const char *desc; // [rsp+8h] [rbp-E0h]
  unsigned int v35; // [rsp+8h] [rbp-E0h]
  unsigned int v36; // [rsp+10h] [rbp-D8h]
  unsigned int v37; // [rsp+1Ch] [rbp-CCh]
  long long v38; // [rsp+20h] [rbp-C8h] BYREF
  long long v39; // [rsp+28h] [rbp-C0h] BYREF
  long long v40; // [rsp+30h] [rbp-B8h] BYREF
  long long v41; // [rsp+38h] [rbp-B0h] BYREF
  long long v42; // [rsp+40h] [rbp-A8h] BYREF
  long long v43; // [rsp+48h] [rbp-A0h] BYREF
  long long v44; // [rsp+50h] [rbp-98h] BYREF
  long long v45; // [rsp+58h] [rbp-90h] BYREF
  struct timespec tp; // [rsp+60h] [rbp-88h] BYREF
  struct timespec v47; // [rsp+70h] [rbp-78h] BYREF
  struct timespec v48; // [rsp+80h] [rbp-68h] BYREF
  long long v49; // [rsp+90h] [rbp-58h]
  unsigned long long v50; // [rsp+A8h] [rbp-40h]

  v50 = __readfsqword(0x28u);
  dword_244A0 = 0;
  gnutls_certificate_allocate_credentials(&v43);
  gnutls_anon_allocate_server_credentials(&v38);
  switch ( a2 )
  {
    case 6:
      v26 = (unsigned int)gnutls_certificate_set_x509_key_mem(v43, &off_1E9E0, &off_1E9D0, 1);
LABEL_41:
      if ( (int)v26 >= 0 )
        goto LABEL_9;
      v27 = gnutls_strerror(v26);
      v28 = 475;
      v29 = (const char *)v27;
LABEL_49:
      __fprintf_chk(stderr, 1, "Error in %d: %s\n", v28, v29);
      exit(1);
    case 1:
      v26 = (unsigned int)gnutls_certificate_set_x509_key_mem(v43, &off_1E9F0, &off_1E9D0, 1);
      goto LABEL_41;
    case 4:
      v4 = gnutls_certificate_set_x509_key_mem(v43, &off_1E9C0, &off_1E9B0, 1);
      break;
    case 7:
      v4 = gnutls_certificate_set_x509_key_mem(v43, &off_1E9A0, &off_1E990, 1);
      break;
    case 9:
      v4 = gnutls_certificate_set_x509_key_mem(v43, &off_1EA00, &off_1EA10, 1);
      break;
    default:
      goto LABEL_9;
  }
  if ( v4 < 0 )
  {
    v31 = gnutls_strerror((unsigned int)v4);
    v28 = 496;
    v29 = (const char *)v31;
    goto LABEL_49;
  }
LABEL_9:
  gnutls_anon_allocate_client_credentials(&v41);
  gnutls_certificate_allocate_credentials(&v42);
  sub_12770(&v48);
  if ( (int)gnutls_priority_init(&v45, a1, &v40) < 0 )
  {
    __fprintf_chk(stderr, 1, "Error in %s\n", v40);
LABEL_46:
    exit(1);
  }
  desc = 0;
  do
  {
    gnutls_init(&v39, 1);
    v5 = gnutls_priority_set(v39, v45);
    if ( v5 < 0 )
      goto LABEL_45;
    gnutls_credentials_set(v39, 2, v38);
    gnutls_credentials_set(v39, 1, v43);
    gnutls_transport_set_push_function(v39, &sub_12ED0);
    gnutls_transport_set_pull_function(v39, &sub_12FA0);
    gnutls_transport_set_ptr(v39, v39);
    sub_12970(&v44);
    gnutls_init(&v44, 2);
    v5 = gnutls_priority_set(v44, v45);
    if ( v5 < 0 )
    {
LABEL_45:
      v30 = gnutls_strerror((unsigned int)v5);
      __fprintf_chk(stderr, 1, "Error in setting priority: %s\n", v30);
      goto LABEL_46;
    }
    gnutls_credentials_set(v44, 2, v41);
    gnutls_credentials_set(v44, 1, v42);
    gnutls_transport_set_push_function(v44, &sub_12E80);
    gnutls_transport_set_pull_function(v44, &sub_12F20);
    gnutls_transport_set_ptr(v44, v44);
    clock_gettime(2, &tp);
    do
    {
LABEL_14:
      while ( 2 )
      {
        for ( i = -28; ; i = 0 )
        {
          off_22298 = "client";
          v7 = gnutls_handshake(v44);
          v8 = v7;
          if ( v7 == -52 )
          {
            if ( i != -28 )
              continue;
            off_22298 = "server";
            v9 = gnutls_handshake(v39);
            if ( v9 == -52 )
              goto LABEL_14;
            goto LABEL_21;
          }
          if ( i == -28 )
            break;
          if ( v7 != -28 )
          {
            v9 = 0;
            goto LABEL_26;
          }
LABEL_17:
          ;
        }
        v37 = v7;
        off_22298 = "server";
        v32 = gnutls_handshake(v39);
        v8 = v37;
        v9 = v32;
        if ( v32 != -52 )
        {
          if ( v37 != -28 )
          {
            v33 = v37 == 0;
            if ( v9 != -28 )
              goto LABEL_57;
            goto LABEL_54;
          }
LABEL_21:
          if ( v9 == -28 )
            continue;
          if ( v9 )
          {
            v8 = -28;
            goto LABEL_24;
          }
          goto LABEL_17;
        }
        break;
      }
    }
    while ( v37 == -28 );
    if ( v37 )
    {
      v9 = -28;
LABEL_24:
      v36 = v9;
      v35 = v8;
      v10 = (const char *)gnutls_strerror(v8);
      __fprintf_chk(stderr, 1, "client[%d]: %s\n", v35, v10);
      v11 = (const char *)gnutls_strerror(v36);
      __fprintf_chk(stderr, 1, "server[%d]: %s\n", v36, v11);
      __fprintf_chk(stderr, 1, "Handshake failed\n");
      exit(1);
    }
    do
    {
      do
      {
        off_22298 = "server";
        v9 = gnutls_handshake(v39);
      }
      while ( v9 == -52 );
      v33 = 1;
      v8 = 0;
      if ( v9 != -28 )
        break;
LABEL_54:
      ;
    }
    while ( v33 );
LABEL_57:
    v7 = v8 | v9;
LABEL_26:
    if ( v7 )
      goto LABEL_24;
    clock_gettime(2, &v47);
    if ( !desc )
      desc = (const char *)gnutls_session_get_desc(v39);
    v12 = qword_244C0;
    gnutls_deinit(v44);
    gnutls_deinit(v39);
    ++dword_244A0;
    v13 = sub_13140(v47.tv_sec, v47.tv_nsec, tp.tv_sec, tp.tv_nsec);
    qword_244C0[v14] = v13;
    if ( v15 > 0x8000 )
      abort();
    ++v49;
  }
  while ( !dword_2448C );
  v16 = "ns";
  __fprintf_chk(stdout, 1, "%s\n - ", desc);
  gnutls_free(desc);
  v17 = sub_127C0(&v48, "transactions", 1, a3);
  gnutls_priority_deinit(v45);
  v19 = sub_130B0((unsigned int)dword_244A0, v17);
  v20 = v19;
  if ( v19 >= 1000.0 )
  {
    if ( v19 >= 1000000.0 )
    {
      v20 = v19 / 1000000.0;
      v16 = (const char *)&unk_1844C;
      if ( v18 )
      {
        do
        {
          v25 = *v12++ * (unsigned __int128)0x431BDE82D7B634DBuLL;
          *(v12 - 1) = *((long long *)&v25 + 1) >> 18;
        }
        while ( (unsigned long long *)((char *)&unk_244C8 + 8 * v18 - 8) != v12 );
        v16 = (const char *)&unk_1844C;
      }
    }
    else
    {
      v20 = v19 / 1000.0;
      v16 = (const char *)&unk_18448;
      if ( v18 )
      {
        do
        {
          v21 = *v12++;
          *(v12 - 1) = v21 / 0x3E8;
        }
        while ( v12 != (unsigned long long *)((char *)&unk_244C8 + 8 * v18 - 8) );
        v16 = (const char *)&unk_18448;
      }
    }
  }
  v22 = sub_13020(v18, v20);
  v23 = sqrt(v22);
  __printf_chk(1, " - avg. handshake time: %.2f %s\n - standard deviation: %.2f %s\n\n", v20, v16, v23, v16);
  gnutls_anon_free_client_credentials(v41);
  gnutls_anon_free_server_credentials(v38, v20);
  return v50 - __readfsqword(0x28u);
}


// Function: benchmark_tls @ 0x13860
long long benchmark_tls(unsigned int a1, int a2)
{
  double v2; // xmm0_8
  double v3; // xmm0_8
  double v5; // xmm0_8

  gnutls_global_set_log_function(sub_12990);
  gnutls_global_set_log_level(a1);
  gnutls_global_init();
  if ( a2 )
  {
    v2 = __printf_chk(1, "Testing throughput in cipher/MAC combinations (payload: %d bytes)\n", 1400);
    sub_129C0((long long)"NONE:+VERS-TLS1.2:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA", 1400, v2);
    sub_129C0((long long)"NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+GROUP-ALL", 1400, v2);
    sub_129C0((long long)"NONE:+VERS-TLS1.2:+AES-128-CCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA", 1400, v2);
    sub_129C0((long long)"NONE:+VERS-TLS1.3:+AES-128-CCM:+AEAD:+SIGN-ALL:+COMP-NULL:+GROUP-ALL", 1400, v2);
    sub_129C0(
      (long long)"NONE:+VERS-TLS1.2:+CHACHA20-POLY1305:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-ALL",
      1400,
      v2);
    sub_129C0(
      (long long)"NONE:+VERS-TLS1.3:+CHACHA20-POLY1305:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-ALL",
      1400,
      v2);
    sub_129C0((long long)"NONE:+VERS-TLS1.0:+AES-128-CBC:+SHA1:+SIGN-ALL:+COMP-NULL:+RSA", 1400, v2);
    sub_129C0((long long)"NONE:+VERS-TLS1.0:+CAMELLIA-128-CBC:+SHA1:+SIGN-ALL:+COMP-NULL:+RSA", 1400, v2);
    sub_129C0(
      (long long)"NONE:+VERS-TLS1.2:+GOST28147-TC26Z-CNT:+GOST28147-TC26Z-IMIT:+SIGN-ALL:+SIGN-GOSTR341012-256:+COMP-NULL:+"
               "VKO-GOST-12:+GROUP-GOST-ALL",
      1400,
      v2);
    v3 = __printf_chk(1, "\nTesting throughput in cipher/MAC combinations (payload: %d bytes)\n", 0x4000);
    sub_129C0((long long)"NONE:+VERS-TLS1.2:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA", 0x4000, v3);
    sub_129C0((long long)"NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+GROUP-ALL", 0x4000, v3);
    sub_129C0((long long)"NONE:+VERS-TLS1.2:+AES-128-CCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA", 0x4000, v3);
    sub_129C0((long long)"NONE:+VERS-TLS1.3:+AES-128-CCM:+AEAD:+SIGN-ALL:+COMP-NULL:+GROUP-ALL", 0x4000, v3);
    sub_129C0(
      (long long)"NONE:+VERS-TLS1.2:+CHACHA20-POLY1305:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-ALL",
      0x4000,
      v3);
    sub_129C0(
      (long long)"NONE:+VERS-TLS1.3:+CHACHA20-POLY1305:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-ALL",
      0x4000,
      v3);
    sub_129C0((long long)"NONE:+VERS-TLS1.0:+AES-128-CBC:+SHA1:+SIGN-ALL:+COMP-NULL:+RSA", 0x4000, v3);
    sub_129C0((long long)"NONE:+VERS-TLS1.0:+CAMELLIA-128-CBC:+SHA1:+SIGN-ALL:+COMP-NULL:+RSA", 0x4000, v3);
    sub_129C0(
      (long long)"NONE:+VERS-TLS1.2:+GOST28147-TC26Z-CNT:+GOST28147-TC26Z-IMIT:+SIGN-ALL:+SIGN-GOSTR341012-256:+COMP-NULL:+"
               "VKO-GOST-12:+GROUP-GOST-ALL",
      0x4000,
      v3);
  }
  else
  {
    v5 = __printf_chk(1, "Testing key exchanges (RSA/DH bits: %d, EC bits: %d)\n\n", 3072, 256);
    sub_13160((long long)"NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+DHE-RSA:+GROUP-FFDHE3072", 1, v5);
    sub_13160(
      (long long)"NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-RSA-PSS-SHA256:+COMP-NULL:+ECDHE-RSA:+CURVE-SECP256R1",
      6,
      v5);
    sub_13160((long long)"NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-SECP256R1", 1, v5);
    sub_13160((long long)"NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-RSA:+CURVE-X25519", 1, v5);
    sub_13160((long long)"NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-ECDSA:+CURVE-SECP256R1", 4, v5);
    sub_13160((long long)"NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+ECDHE-ECDSA:+CURVE-X25519", 4, v5);
    sub_13160(
      (long long)"NONE:+VERS-TLS1.3:+AES-128-GCM:+AEAD:+SIGN-EDDSA-ED25519:+COMP-NULL:+ECDHE-ECDSA:+CURVE-X25519",
      7,
      v5);
    sub_13160((long long)"NONE:+VERS-TLS1.2:+AES-128-GCM:+AEAD:+SIGN-ALL:+COMP-NULL:+RSA", 1, v5);
    sub_13160(
      (long long)"NONE:+VERS-TLS1.2:+GOST28147-TC26Z-CNT:+GOST28147-TC26Z-IMIT:+SIGN-ALL:+SIGN-GOSTR341012-256:+COMP-NULL:+"
               "VKO-GOST-12:+GROUP-GOST-ALL",
      9,
      v5);
  }
  return gnutls_global_deinit();
}


// Function: _generate_request @ 0x13c00
unsigned long long _generate_request(long long a1, long long a2, long long a3, long long a4)
{
  int v6; // eax
  int v7; // eax
  long long v8; // rdi
  int v9; // eax
  unsigned int v10; // eax
  long long v12; // rax
  long long v13; // rax
  long long v14; // rax
  long long v15; // rax
  long long v16; // [rsp+0h] [rbp-38h] BYREF
  unsigned long long v17; // [rsp+8h] [rbp-30h]

  v17 = __readfsqword(0x28u);
  v6 = gnutls_ocsp_req_init(&v16);
  if ( v6 < 0 )
  {
    v12 = gnutls_strerror((unsigned int)v6);
    __fprintf_chk(stderr, 1, "ocsp_req_init: %s", v12);
    goto LABEL_9;
  }
  v7 = gnutls_ocsp_req_add_cert(v16, 3, a2, a1);
  if ( v7 < 0 )
  {
    v14 = gnutls_strerror((unsigned int)v7);
    __fprintf_chk(stderr, 1, "ocsp_req_add_cert: %s", v14);
    goto LABEL_9;
  }
  v8 = v16;
  if ( !a4 )
    goto LABEL_6;
  v9 = gnutls_ocsp_req_set_nonce(v16, 0, a4);
  if ( v9 < 0 )
  {
    v15 = gnutls_strerror((unsigned int)v9);
    __fprintf_chk(stderr, 1, "ocsp_req_set_nonce: %s", v15);
LABEL_9:
    exit(1);
  }
  v8 = v16;
LABEL_6:
  v10 = gnutls_ocsp_req_export(v8, a3);
  if ( v10 )
  {
    v13 = gnutls_strerror(v10);
    __fprintf_chk(stderr, 1, "ocsp_req_export: %s", v13);
    goto LABEL_9;
  }
  gnutls_ocsp_req_deinit(v16);
  return v17 - __readfsqword(0x28u);
}


// Function: send_ocsp_request @ 0x13d10
long long send_ocsp_request(char *ptr, long long a2, long long a3, long long a4, long long a5)
{
  char *v8; // r14
  char *v9; // r15
  int v10; // r12d
  int v11; // eax
  unsigned int v12; // r15d
  void *v13; // r12
  unsigned int v14; // r13d
  char *v15; // rax
  const void *v16; // rbp
  unsigned int v17; // r13d
  void *v18; // rdi
  unsigned int v20; // r14d
  long long v21; // rsi
  int authority_info_access; // eax
  char *v23; // rax
  void *v24; // r15
  unsigned int v25; // r14d
  long long v26; // rsi
  int v27; // eax
  const char *v28; // rax
  long long v30; // [rsp+10h] [rbp-5A8h]
  int v32; // [rsp+24h] [rbp-594h] BYREF
  char *v33; // [rsp+28h] [rbp-590h] BYREF
  void *haystack[2]; // [rsp+30h] [rbp-588h]
  void *src; // [rsp+40h] [rbp-578h] BYREF
  size_t n; // [rsp+48h] [rbp-570h]
  int v37[68]; // [rsp+50h] [rbp-568h] BYREF
  char v38[16]; // [rsp+160h] [rbp-458h] BYREF
  char s[1032]; // [rsp+170h] [rbp-448h] BYREF
  unsigned long long v40; // [rsp+578h] [rbp-40h]

  v40 = __readfsqword(0x28u);
  v33 = "";
  sub_DC70();
  if ( ptr )
  {
    v8 = ptr;
  }
  else
  {
    v20 = 0;
    do
    {
      v21 = v20++;
      authority_info_access = gnutls_x509_crt_get_authority_info_access(a2, v21, 10006, &src, 0);
    }
    while ( authority_info_access == -105 );
    if ( authority_info_access < 0 )
    {
      v25 = 0;
      do
      {
        v26 = v25++;
        v27 = gnutls_x509_crt_get_authority_info_access(a3, v26, 10006, &src, 0);
      }
      while ( v27 == -105 );
      v12 = v27;
      if ( v27 < 0 )
      {
        v28 = (const char *)gnutls_strerror((unsigned int)v27);
        __fprintf_chk(stderr, 1, "*** Cannot find OCSP server URI in certificate: %s\n", v28);
        return v12;
      }
    }
    v23 = (char *)malloc((unsigned int)(n + 1));
    v8 = v23;
    if ( !v23 )
      return (unsigned int)-1;
    v24 = src;
    v30 = (unsigned int)n;
    memcpy(v23, src, (unsigned int)n);
    v8[v30] = 0;
    gnutls_free(v24);
  }
  v9 = sub_13AE0(v8, &v32, &v33);
  if ( v32 )
    __snprintf_chk(v38, 16, 1, 16, "%u", v32);
  else
    strcpy(v38, "80");
  __fprintf_chk(stderr, 1, "Connecting to OCSP server: %s...\n", v9);
  *(_OWORD *)haystack = 0;
  sub_13C00(a2, a3, (long long)&src, a5);
  __snprintf_chk(
    s,
    1024,
    1,
    1024,
    "POST /%s HTTP/1.0\r\n"
    "Host: %s\r\n"
    "Accept: */*\r\n"
    "Content-Type: application/ocsp-request\r\n"
    "Content-Length: %u\r\n"
    "Connection: close\r\n"
    "\r\n",
    v33,
    v9,
    n);
  v10 = strlen(s);
  sub_11250(v37, v9, v38, 0, 40, "Connecting to", 0, 0, 0);
  sub_10F90((long long)v37, s, v10);
  sub_10F90((long long)v37, src, n);
  gnutls_free(src);
  src = 0;
  while ( 1 )
  {
    v11 = sub_10D90((long long)v37, &unk_94700, 4097);
    v12 = v11;
    if ( v11 <= 0 )
      break;
    sub_13B90(v11);
  }
  v13 = haystack[0];
  if ( v11 || (v14 = (unsigned int)haystack[1]) == 0 )
  {
LABEL_17:
    v12 = -1;
    perror("recv");
    goto LABEL_12;
  }
  sub_11040((long long)v37, 0);
  v15 = (char *)memmem(v13, v14, "\r\n\r\n", 4u);
  if ( v15 )
  {
    v16 = v15 + 4;
    v17 = v14 - ((int)v15 + 4 - (int)v13);
    *(int *)(a4 + 8) = v17;
    v18 = malloc(v17);
    *(long long *)a4 = v18;
    if ( v18 )
    {
      memcpy(v18, v16, *(unsigned int *)(a4 + 8));
      goto LABEL_12;
    }
    goto LABEL_17;
  }
  v12 = -1;
  __fprintf_chk(stderr, 1, "Cannot interpret HTTP response\n");
LABEL_12:
  free(v13);
  if ( v8 != ptr )
    free(v8);
  return v12;
}


// Function: print_ocsp_verify_res @ 0x140f0
double print_ocsp_verify_res(int a1)
{
  double result; // xmm0_8
  double v2; // xmm0_8
  double v3; // xmm0_8
  double v4; // xmm0_8
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  double v8; // xmm0_8

  if ( a1 )
  {
    result = __printf_chk(1, "Failure");
    if ( (a1 & 1) != 0 )
    {
      v2 = __printf_chk(1, ", ", result);
      result = __printf_chk(1, "Signer cert not found", v2);
    }
    if ( (a1 & 2) != 0 )
    {
      v3 = __printf_chk(1, ", ", result);
      result = __printf_chk(1, "Signer cert keyusage error", v3);
    }
    if ( (a1 & 4) != 0 )
    {
      v4 = __printf_chk(1, ", ", result);
      result = __printf_chk(1, "Signer cert is not trusted", v4);
    }
    if ( (a1 & 8) != 0 )
    {
      v5 = __printf_chk(1, ", ", result);
      result = __printf_chk(1, "Insecure algorithm", v5);
      if ( (a1 & 0x10) != 0 )
        goto LABEL_10;
      goto LABEL_15;
    }
  }
  else
  {
    result = __printf_chk(1, "Success");
  }
  if ( (a1 & 0x10) != 0 )
  {
LABEL_10:
    v6 = __printf_chk(1, ", ", result);
    result = __printf_chk(1, "Signature failure", v6);
    if ( (a1 & 0x20) != 0 )
      goto LABEL_11;
    goto LABEL_16;
  }
LABEL_15:
  if ( (a1 & 0x20) != 0 )
  {
LABEL_11:
    v7 = __printf_chk(1, ", ", result);
    result = __printf_chk(1, "Signer cert not yet activated", v7);
    if ( (a1 & 0x40) == 0 )
      return result;
    goto LABEL_12;
  }
LABEL_16:
  if ( (a1 & 0x40) != 0 )
  {
LABEL_12:
    v8 = __printf_chk(1, ", ", result);
    return __printf_chk(1, "Signer cert expired", v8);
  }
  return result;
}


// Function: check_ocsp_response @ 0x14280
long long check_ocsp_response(long long a1, long long a2, long long a3, long long a4, int a5)
{
  time_t v8; // rbx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int single; // eax
  int nonce; // eax
  size_t v15; // rdx
  void *v16; // r13
  unsigned int v17; // r12d
  char *v18; // rax
  double v19; // xmm0_8
  char *v21; // rax
  char *v22; // r12
  char *v23; // rax
  const char *v24; // rcx
  char *v25; // rax
  long long v26; // rax
  long long v27; // rax
  long long v28; // rax
  long long v29; // rax
  long long v30; // rax
  int v31; // [rsp+8h] [rbp-100h] BYREF
  int v32; // [rsp+Ch] [rbp-FCh] BYREF
  long long v33; // [rsp+10h] [rbp-F8h] BYREF
  time_t v34; // [rsp+18h] [rbp-F0h] BYREF
  time_t v35; // [rsp+20h] [rbp-E8h] BYREF
  time_t v36; // [rsp+28h] [rbp-E0h] BYREF
  void *s2; // [rsp+30h] [rbp-D8h] BYREF
  int v38; // [rsp+38h] [rbp-D0h]
  char v39[64]; // [rsp+40h] [rbp-C8h] BYREF
  char v40[72]; // [rsp+80h] [rbp-88h] BYREF
  unsigned long long v41; // [rsp+C8h] [rbp-40h]

  v41 = __readfsqword(0x28u);
  v8 = time(0);
  v9 = gnutls_ocsp_resp_init(&v33);
  if ( v9 < 0 )
  {
    v27 = gnutls_strerror((unsigned int)v9);
    __fprintf_chk(stderr, 1, "ocsp_resp_init: %s", v27);
    goto LABEL_30;
  }
  v10 = gnutls_ocsp_resp_import(v33, a3);
  if ( v10 < 0 )
  {
    v26 = gnutls_strerror((unsigned int)v10);
    __fprintf_chk(stderr, 1, "importing response: %s", v26);
    goto LABEL_30;
  }
  v11 = gnutls_ocsp_resp_check_crt(v33, 0, a1);
  if ( v11 >= 0 )
  {
    v12 = gnutls_ocsp_resp_verify_direct(v33, a2, &v31, 0);
    if ( v12 < 0 )
    {
      v28 = gnutls_strerror((unsigned int)v12);
      __fprintf_chk(stderr, 1, "OCSP verification: %s\n", v28);
    }
    else
    {
      if ( v31 )
      {
        __printf_chk(1, "*** Verifying OCSP Response: ");
        v19 = sub_140F0(v31);
        __printf_chk(1, ".\n", v19);
        if ( v31 )
        {
          v17 = -1;
          goto LABEL_19;
        }
      }
      single = gnutls_ocsp_resp_get_single(v33, 0, 0, 0, 0, 0, &v32, &v35, &v36, &v34, 0);
      if ( single < 0 )
      {
        v29 = gnutls_strerror((unsigned int)single);
        __fprintf_chk(stderr, 1, "reading response: %s\n", v29);
      }
      else
      {
        if ( v32 == 1 )
        {
          v17 = 0;
          v25 = sub_102E0(&v34, v39);
          __printf_chk(1, "*** Certificate was revoked at %s\n", v25);
          goto LABEL_19;
        }
        if ( v36 == -1 )
        {
          if ( v8 - v35 > (long long)&unk_3F480 )
          {
            v17 = -1;
            v21 = sub_102E0(&v35, v39);
            __printf_chk(1, "*** The OCSP response is old (was issued at: %s) ignoring\n", v21);
            goto LABEL_19;
          }
        }
        else if ( v36 < v8 )
        {
          v22 = sub_102E0(&v36, v40);
          v23 = sub_102E0(&v35, v39);
          v24 = v22;
          v17 = -1;
          __printf_chk(1, "*** The OCSP response was issued at: %s but there is a newer issue at %s\n", v23, v24);
          goto LABEL_19;
        }
        if ( !a4 )
          goto LABEL_16;
        nonce = gnutls_ocsp_resp_get_nonce(v33, 0, &s2);
        if ( nonce == -56 )
        {
          if ( a5 )
            __fprintf_chk(stderr, 1, "*** The OCSP reply did not include the requested nonce.\n");
          goto LABEL_16;
        }
        if ( nonce >= 0 )
        {
          v15 = *(unsigned int *)(a4 + 8);
          if ( v38 != (int)v15 || (v16 = s2, memcmp(*(const void **)a4, s2, v15)) )
          {
            __fprintf_chk(stderr, 1, "nonce in the response doesn't match\n");
            exit(1);
          }
          gnutls_free(v16);
LABEL_16:
          v17 = 1;
          v18 = sub_102E0(&v35, v39);
          __printf_chk(1, "- OCSP server flags certificate not revoked as of %s\n", v18);
          goto LABEL_19;
        }
        v30 = gnutls_strerror((unsigned int)nonce);
        __fprintf_chk(stderr, 1, "could not read response's nonce: %s\n", v30);
      }
    }
LABEL_30:
    exit(1);
  }
  v17 = -1;
  if ( v11 == -56 )
    __printf_chk(1, "*** Got OCSP response with no data (ignoring)\n");
  else
    __printf_chk(1, "*** Got OCSP response on an unrelated certificate (ignoring)\n");
LABEL_19:
  gnutls_ocsp_resp_deinit(v33);
  return v17;
}


// Function: parse_number @ 0x14660
long long parse_number(char *nptr)
{
  int *v1; // rax
  int *v2; // rbx
  size_t v3; // r13
  long long v4; // r13
  char *v6[5]; // [rsp+0h] [rbp-28h] BYREF

  v6[1] = (char *)__readfsqword(0x28u);
  v6[0] = 0;
  v1 = __errno_location();
  *v1 = 0;
  v2 = v1;
  if ( !strncmp(nptr, "0x", 2u) )
  {
    v4 = strtol(nptr + 2, v6, 16);
  }
  else if ( !strncmp(nptr, "0", 1u) && (v3 = strspn(nptr, "012345678"), v3 == strlen(optarg)) )
  {
    v4 = strtol(nptr + 1, v6, 8);
  }
  else
  {
    v4 = strtol(nptr, v6, 10);
  }
  if ( *v2 || v6[0] && *v6[0] )
    error(1, *v2, "'%s' is not a recognizable number.", nptr);
  return v4;
}


// Function: usage @ 0x14840
void usage(long long a1, int a2)
{
  char v2[5986]; // [rsp+0h] [rbp-1778h] BYREF
  char v3; // [rsp+1762h] [rbp-16h]
  unsigned long long v4; // [rsp+1768h] [rbp-10h]

  v4 = __readfsqword(0x28u);
  qmemcpy(v2, aGnutlsCliGnutl, sizeof(v2));
  v3 = aGnutlsCliGnutl[5986];
  __fprintf_chk(a1, 1, "%s", v2);
  exit(a2);
}


// Function: process_options @ 0x148c0
long long process_options(int argc, char **argv)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // r8d
  int v9; // r8d
  int v10; // r8d
  const char *v11; // rbp
  __pid_t v13; // eax
  int *v14; // rax
  char *v15; // rax
  char *v16; // rdi
  int *v17; // rax
  int pipedes[2]; // [rsp+8h] [rbp-400h] BYREF
  char *argva[2]; // [rsp+10h] [rbp-3F8h] BYREF
  _OWORD v20[58]; // [rsp+20h] [rbp-3E8h] BYREF
  unsigned long long v21; // [rsp+3C8h] [rbp-40h]

  v21 = __readfsqword(0x28u);
  byte_958A6 = 1;
  while ( 1 )
  {
    v2 = getopt_long(argc, argv, "!Vbd:ehlp:rsuv:", &longopts, 0);
    if ( v2 == -1 )
      break;
    switch ( v2 )
    {
      case 0:
        continue;
      case 33:
        algn_95762[3] = 1;
        algn_958E3[2] = 1;
        break;
      case 86:
        byte_95721 = 1;
        byte_958A1 = 1;
        break;
      case 98:
        byte_95753 = 1;
        unk_958D3 = 1;
        break;
      case 100:
        byte_95720 = 1;
        *(long long *)&algn_95762[6] = optarg;
        v5 = sub_14660(optarg);
        unk_958A0 = 1;
        dword_95868 = v5;
        break;
      case 101:
        byte_9572A = 1;
        unk_958AA = 1;
        break;
      case 104:
        algn_95762[2] = 1;
        algn_958E3[1] = 1;
        break;
      case 108:
        byte_9574D = 1;
        unk_958CD = 1;
        break;
      case 112:
        byte_95746 = 1;
        unk_958C6 = 1;
        qword_95820 = (long long)optarg;
        break;
      case 114:
        byte_95728 = 1;
        unk_958A8 = 1;
        break;
      case 115:
        byte_9572D = 1;
        unk_958AD = 1;
        break;
      case 117:
        byte_9572F = 1;
        unk_958AF = 1;
        break;
      case 118:
        algn_95762[1] = 1;
        algn_958E3[0] = 1;
        qword_95860 = optarg;
        break;
      case 128:
        algn_95722[0] = 1;
        byte_958A2 = 1;
        break;
      case 129:
        algn_95722[0] = 1;
        byte_958A2 = 0;
        break;
      case 130:
        algn_95722[1] = 1;
        byte_958A3 = 1;
        break;
      case 131:
        algn_95722[1] = 1;
        byte_958A3 = 0;
        break;
      case 132:
        algn_95722[2] = 1;
        byte_958A4 = 1;
        break;
      case 133:
        algn_95722[2] = 1;
        byte_958A4 = 0;
        break;
      case 134:
        algn_95722[3] = 1;
        algn_958A5 = 1;
        break;
      case 135:
        algn_95722[3] = 1;
        algn_958A5 = 0;
        break;
      case 136:
        algn_95722[4] = 1;
        byte_958A6 = 1;
        break;
      case 137:
        algn_95722[4] = 1;
        byte_958A6 = 0;
        break;
      case 138:
        algn_95722[5] = 1;
        byte_958A7 = 1;
        break;
      case 139:
        algn_95722[5] = 1;
        byte_958A7 = 0;
        break;
      case 140:
        byte_95729 = 1;
        unk_958A9 = 1;
        qword_95770 = optarg;
        break;
      case 141:
        byte_9572B = 1;
        unk_958AB = 1;
        qword_95778 = optarg;
        break;
      case 142:
        byte_9572C = 1;
        unk_958AC = 1;
        qword_95780 = optarg;
        break;
      case 143:
      case 144:
        byte_9572E = 1;
        unk_958AE = 1;
        qword_95788 = (long long)optarg;
        break;
      case 145:
        unk_95730 = 1;
        unk_95790 = optarg;
        v4 = sub_14660(optarg);
        unk_958B0 = 1;
        dword_9586C = v4;
        break;
      case 146:
        byte_95731 = 1;
        unk_958B1 = 1;
        break;
      case 147:
        byte_95732 = 1;
        unk_958B2 = 1;
        break;
      case 148:
        byte_95733 = 1;
        unk_958B3 = 1;
        break;
      case 149:
        byte_95734 = 1;
        unk_958B4 = 1;
        break;
      case 150:
        byte_95735 = 1;
        unk_958B5 = 1;
        qword_95798 = optarg;
        break;
      case 151:
        LOBYTE(word_95736) = 1;
        unk_958B6 = 1;
        qword_957A0 = optarg;
        break;
      case 152:
        HIBYTE(word_95736) = 1;
        unk_958B7 = 1;
        qword_957A8 = (long long)optarg;
        break;
      case 153:
        byte_95738 = 1;
        unk_958B8 = 1;
        qword_957B0 = optarg;
        break;
      case 154:
        byte_95739 = 1;
        unk_958B9 = 1;
        qword_957B8 = optarg;
        break;
      case 155:
        byte_9573A = 1;
        unk_957C0 = optarg;
        v7 = sub_14660(optarg);
        unk_958BA = 1;
        dword_95870 = v7;
        break;
      case 156:
        byte_9573B = 1;
        unk_958BB = 1;
        qword_957C8 = (long long)optarg;
        break;
      case 157:
        byte_9573C = 1;
        unk_958BC = 1;
        qword_957D0 = (long long)optarg;
        break;
      case 158:
        byte_9573D = 1;
        unk_958BD = 1;
        qword_957D8 = (long long)optarg;
        break;
      case 159:
        byte_9573E = 1;
        unk_958BE = 1;
        qword_957E0 = (long long)optarg;
        break;
      case 160:
        byte_9573F = 1;
        unk_958BF = 1;
        qword_957E8 = (long long)optarg;
        break;
      case 161:
        byte_95740 = 1;
        unk_958C0 = 1;
        qword_957F0 = (long long)optarg;
        break;
      case 162:
        byte_95741 = 1;
        unk_958C1 = 1;
        qword_957F8 = (long long)optarg;
        break;
      case 163:
        byte_95742 = 1;
        unk_958C2 = 1;
        qword_95800 = (long long)optarg;
        break;
      case 164:
        byte_95743 = 1;
        unk_958C3 = 1;
        qword_95808 = (long long)optarg;
        break;
      case 165:
        byte_95744 = 1;
        unk_958C4 = 1;
        qword_95810 = (long long)optarg;
        break;
      case 166:
        byte_95745 = 1;
        unk_958C5 = 1;
        qword_95818 = optarg;
        break;
      case 167:
        byte_95747 = 1;
        unk_958C7 = 1;
        break;
      case 168:
        byte_95748 = 1;
        unk_958C8 = 1;
        break;
      case 169:
        byte_95749 = 1;
        unk_958C9 = 1;
        break;
      case 170:
        byte_9574A = 1;
        unk_958CA = 1;
        break;
      case 171:
        byte_9574B = 1;
        unk_958CB = 1;
        break;
      case 172:
        byte_9574C = 1;
        unk_958CC = 1;
        break;
      case 173:
        byte_9574E = 1;
        unk_958CE = 1;
        break;
      case 174:
        algn_9574F = 1;
        unk_958CF = 1;
        break;
      case 175:
        byte_95750 = 1;
        unk_958D0 = 1;
        qword_95828 = (long long)optarg;
        break;
      case 176:
        byte_95751 = 1;
        sub_147A0(&qword_95880, "alpn");
        unk_958D1 = 1;
        break;
      case 177:
        byte_95752 = 1;
        sub_147A0(&qword_95890, "compress-cert");
        unk_958D2 = 1;
        break;
      case 178:
        unk_95754 = 1;
        unk_95830 = optarg;
        v6 = sub_14660(optarg);
        unk_958D4 = 1;
        dword_95874 = v6;
        break;
      case 179:
        byte_95755 = 1;
        unk_958D5 = 1;
        break;
      case 180:
        byte_95756 = 1;
        unk_958D6 = 1;
        break;
      case 181:
        byte_95757 = 1;
        unk_958D7 = 1;
        break;
      case 182:
        byte_95758 = 1;
        unk_958D8 = 1;
        break;
      case 183:
        byte_95759 = 1;
        unk_958D9 = 1;
        break;
      case 184:
        byte_9575A = 1;
        unk_958DA = 1;
        qword_95838 = optarg;
        break;
      case 185:
        algn_9575B = 1;
        unk_958DB = 1;
        unk_95840 = optarg;
        break;
      case 186:
        byte_9575C = 1;
        unk_958DC = 1;
        break;
      case 187:
        byte_9575D = 1;
        unk_958DD = 1;
        break;
      case 188:
        byte_9575E = 1;
        unk_958DE = 1;
        filename = optarg;
        break;
      case 189:
        byte_9575F = 1;
        unk_958DF = 1;
        qword_95850 = (long long)optarg;
        break;
      case 190:
        byte_95760 = 1;
        unk_95858 = optarg;
        v3 = sub_14660(optarg);
        unk_958E0 = 1;
        dword_95878 = v3;
        break;
      case 191:
        byte_95761 = 1;
        unk_958E1 = 1;
        break;
      case 192:
        algn_95762[0] = 1;
        byte_958E2 = 1;
        break;
      case 193:
        algn_95762[0] = 1;
        byte_958E2 = 0;
        break;
      default:
        sub_14840((long long)stderr, 1);
    }
  }
  if ( byte_95720 )
  {
    v8 = dword_95868;
    if ( dword_95868 >= 0 )
    {
      if ( dword_95868 <= 9999 )
        goto LABEL_85;
LABEL_121:
      error(1, 0, "%s option value %d is out of range", "debug", v8);
      goto LABEL_85;
    }
    error(1, 0, "%s option value %d is out of range.", "debug", dword_95868);
    if ( byte_95720 )
    {
      v8 = dword_95868;
      if ( dword_95868 > 9999 )
        goto LABEL_121;
    }
  }
LABEL_85:
  if ( byte_9572E && byte_9572D )
    error(1, 0, "the '%s' and '%s' options conflict", "starttls-proto", "starttls");
  if ( unk_95730 )
  {
    v9 = dword_9586C;
    if ( dword_9586C >= 0 )
    {
      if ( dword_9586C <= 17000 )
        goto LABEL_91;
LABEL_122:
      error(1, 0, "%s option value %d is out of range", "mtu", v9);
      goto LABEL_91;
    }
    error(1, 0, "%s option value %d is out of range.", "mtu", dword_9586C);
    if ( unk_95730 )
    {
      v9 = dword_9586C;
      if ( dword_9586C > 17000 )
        goto LABEL_122;
    }
  }
LABEL_91:
  if ( (char)word_95736 )
  {
    if ( HIBYTE(word_95736) )
    {
      error(1, 0, "the '%s' and '%s' options conflict", "save-ocsp", "save_ocsp_multi");
      if ( HIBYTE(word_95736) )
      {
        if ( (char)word_95736 )
          error(1, 0, "the '%s' and '%s' options conflict", "save-ocsp-multi", "save_ocsp");
      }
    }
  }
  if ( byte_9573F && !byte_9573E )
    error(1, 0, "%s option requires the %s options", "x509certfile", "x509keyfile");
  if ( byte_95741 && !byte_95740 )
    error(1, 0, "%s option requires the %s options", "rawpkfile", "rawpkkeyfile");
  if ( byte_9574D && byte_95746 )
    error(1, 0, "the '%s' and '%s' options conflict", "list", "port");
  if ( unk_95754 )
  {
    v10 = dword_95874;
    if ( dword_95874 >= 0 )
    {
      if ( dword_95874 <= 4096 )
        goto LABEL_105;
      goto LABEL_120;
    }
    error(1, 0, "%s option value %d is out of range.", "recordsize", dword_95874);
    if ( unk_95754 )
    {
      v10 = dword_95874;
      if ( dword_95874 > 4096 )
LABEL_120:
        error(1, 0, "%s option value %d is out of range", "recordsize", v10);
    }
  }
LABEL_105:
  if ( algn_95762[2] )
    sub_14840((long long)stdout, 0);
  if ( algn_95762[3] )
  {
    if ( pipe(pipedes) < 0 )
    {
      v17 = __errno_location();
      error(1, *v17, "pipe");
    }
    v13 = fork();
    if ( v13 < 0 )
    {
      v14 = __errno_location();
      error(1, *v14, "fork");
    }
    else if ( !v13 )
    {
      close(pipedes[0]);
      dup2(pipedes[1], 1);
      close(pipedes[1]);
      sub_14840((long long)stdout, 0);
    }
    close(pipedes[1]);
    dup2(pipedes[0], 0);
    close(pipedes[0]);
    v15 = secure_getenv("PAGER");
    v16 = v15;
    if ( !v15 || !*v15 )
      v16 = "more";
    argva[0] = v16;
    argva[1] = 0;
    execvp(v16, argva);
    exit(1);
  }
  if ( algn_95762[1] )
  {
    v11 = qword_95860;
    if ( !qword_95860 || !strcmp(qword_95860, "c") )
    {
      strcpy(
        (char *)v20,
        "gnutls-cli 3.7.8\n"
        "Copyright (C) 2000-2021 Free Software Foundation, and others\n"
        "This is free software. It is licensed for use, modification and\n"
        "redistribution under the terms of the GNU General Public License,\n"
        "version 3 or later <http://gnu.org/licenses/gpl.html>\n"
        "\n"
        "Please send bug reports to:  <bugs@gnutls.org>            \n");
    }
    else if ( !strcmp(v11, "v") )
    {
      strcpy((char *)&v20[1], "\n");
      v20[0] = _mm_load_si128((const __m128i *)&xmmword_1B3E0);
    }
    else
    {
      if ( strcmp(v11, "n") )
      {
        error(
          1,
          0,
          "version option argument 'a' invalid.  Use:\n"
          "\t'v' - version only\n"
          "\t'c' - version and copyright\n"
          "\t'n' - version and full copyright notice");
        return (unsigned int)optind;
      }
      strcpy(
        (char *)v20,
        "gnutls-cli 3.7.8\n"
        "Copyright (C) 2000-2021 Free Software Foundation, and others\n"
        "This is free software. It is licensed for use, modification and\n"
        "redistribution under the terms of the GNU General Public License,\n"
        "version 3 or later <http://gnu.org/licenses/gpl.html>\n"
        "\n"
        "gnutls is free software: you can redistribute it and/or\n"
        "modify it under the terms of the GNU General Public License\n"
        "as published by the Free Software Foundation,\n"
        "either version 3 of the License, or (at your option) any later version.\n"
        "\n"
        "gnutls is distributed in the hope that it will be useful,\n"
        "but WITHOUT ANY WARRANTY; without even the implied warranty\n"
        "of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
        "See the GNU General Public License for more details.\n"
        "\n"
        "You should have received a copy of the GNU General Public License\n"
        "along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
        "\n"
        "Please send bug reports to:  <bugs@gnutls.org>            \n");
    }
    __fprintf_chk(stdout, 1, "%s", (const char *)v20);
    exit(0);
  }
  return (unsigned int)optind;
}


// Function: _gnutls_fread_file @ 0x15860
char *_gnutls_fread_file(FILE *a1, char a2, size_t *a3)
{
  int v3; // eax
  size_t v4; // r13
  char *v5; // rbp
  size_t v6; // rbx
  char *v7; // rax
  char *v8; // r15
  void *v9; // rdi
  size_t v10; // r15
  size_t v11; // rax
  size_t v12; // rax
  size_t v13; // r12
  char *v14; // rax
  int v15; // r15d
  int *v16; // r14
  void *v17; // rdi
  int *v19; // rax
  char *v20; // rax
  char *v21; // r12
  void *v22; // rdi
  int *v23; // rax
  int *v24; // rax
  __off_t v25; // rax
  char *v26; // rax
  struct stat buf; // [rsp+20h] [rbp-D8h] BYREF
  unsigned long long v30; // [rsp+B8h] [rbp-40h]

  v30 = __readfsqword(0x28u);
  v3 = fileno(a1);
  if ( fstat(v3, &buf) >= 0 && (buf.st_mode & 0xF000) == 0x8000 && (v25 = ftello(a1), v25 >= 0) && buf.st_size > v25 )
  {
    v4 = buf.st_size - v25 + 1;
    if ( buf.st_size - v25 == 0x7FFFFFFFFFFFFFFFLL )
    {
      v5 = 0;
      *__errno_location() = 12;
      return v5;
    }
  }
  else
  {
    v4 = 0x2000;
  }
  v5 = (char *)malloc(v4);
  if ( v5 )
  {
    v6 = 0;
    while ( 1 )
    {
      v10 = v4 - v6;
      v11 = fread(&v5[v6], 1u, v4 - v6, a1);
      v6 += v11;
      if ( v10 != v11 )
        break;
      if ( v4 == 0x7FFFFFFFFFFFFFFFLL )
      {
        v15 = 12;
        v16 = __errno_location();
        goto LABEL_17;
      }
      v12 = v4 + (v4 >> 1);
      if ( 0x7FFFFFFFFFFFFFFFLL - (v4 >> 1) <= v4 )
        v12 = 0x7FFFFFFFFFFFFFFFLL;
      v13 = v12;
      if ( (a2 & 2) != 0 )
      {
        v7 = (char *)malloc(v12);
        v8 = v7;
        if ( !v7 )
        {
          v23 = __errno_location();
          v4 = v13;
          v15 = *v23;
          v16 = v23;
LABEL_27:
          __explicit_bzero_chk(v5, v4, -1);
LABEL_18:
          v17 = v5;
          v5 = 0;
          free(v17);
          *v16 = v15;
          return v5;
        }
        memcpy(v7, v5, v4);
        __explicit_bzero_chk(v5, v4, -1);
        v9 = v5;
        v5 = v8;
        free(v9);
      }
      else
      {
        v14 = (char *)realloc(v5, v12);
        if ( !v14 )
        {
          v24 = __errno_location();
          v15 = *v24;
          v16 = v24;
          goto LABEL_18;
        }
        v5 = v14;
      }
      v4 = v13;
    }
    v19 = __errno_location();
    v15 = *v19;
    v16 = v19;
    if ( ferror(a1) )
    {
LABEL_17:
      if ( (a2 & 2) != 0 )
        goto LABEL_27;
      goto LABEL_18;
    }
    if ( v4 - 1 > v6 )
    {
      if ( (a2 & 2) != 0 )
      {
        v20 = (char *)malloc(v6 + 1);
        v21 = v20;
        if ( v20 )
        {
          memcpy(v20, v5, v6);
          __explicit_bzero_chk(v5, v4, -1);
          v22 = v5;
          v5 = v21;
          free(v22);
        }
        else
        {
          __explicit_bzero_chk(&v5[v6], v4 - v6, -1);
        }
      }
      else
      {
        v26 = (char *)realloc(v5, v6 + 1);
        if ( v26 )
          v5 = v26;
      }
    }
    v5[v6] = 0;
    *a3 = v6;
  }
  return v5;
}


// Function: _gnutls_read_file @ 0x15b50
char *_gnutls_read_file(const char *a1, char a2, size_t *a3)
{
  bool v4; // zf
  const char *v5; // rsi
  FILE *v7; // rax
  FILE *v8; // r12
  char *v9; // r13

  v4 = (a2 & 1) == 0;
  v5 = (const char *)&unk_1B3F0;
  if ( v4 )
    v5 = "re";
  v7 = fopen(a1, v5);
  if ( v7 )
  {
    v8 = v7;
    if ( (a2 & 2) != 0 )
      setvbuf(v7, 0, 2, 0);
    v9 = sub_15860(v8, a2, a3);
    if ( !fclose(v8) )
      return v9;
    if ( v9 )
    {
      if ( (a2 & 2) != 0 )
        __explicit_bzero_chk(v9, *a3, -1);
      free(v9);
    }
  }
  return 0;
}


