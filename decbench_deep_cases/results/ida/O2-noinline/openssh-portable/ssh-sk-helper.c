// Function: main @ 0x6e20
long long main(long long a1, char **a2, char **a3)
{
  unsigned int v3; // r14d
  unsigned int v4; // r12d
  int v5; // eax
  long long v6; // rsi
  unsigned int v7; // r14d
  unsigned int v8; // r13d
  long long v9; // rdx
  long long v10; // rax
  void *v11; // rbp
  long long v12; // r10
  long long v13; // rax
  unsigned int v14; // eax
  long long v15; // rdx
  long long v16; // rcx
  int *v17; // rsi
  unsigned int v18; // eax
  long long v19; // rdx
  long long v20; // rcx
  long long v21; // r8
  long long v22; // r9
  void *v23; // r12
  long long v24; // rax
  long long v25; // rax
  const char *v27; // rbx
  int v28; // eax
  int *v29; // rax
  char *v30; // rax
  const char *v31; // rbx
  int v32; // eax
  long long v33; // [rsp-10h] [rbp-68h]
  long long v34; // [rsp-8h] [rbp-60h]
  unsigned char v35; // [rsp+Eh] [rbp-4Ah] BYREF
  unsigned char v36; // [rsp+Fh] [rbp-49h] BYREF
  int v37; // [rsp+10h] [rbp-48h] BYREF
  unsigned int v38; // [rsp+14h] [rbp-44h] BYREF
  unsigned long long v39; // [rsp+18h] [rbp-40h]

  v3 = 2;
  v4 = 0;
  v39 = __readfsqword(0x28u);
  v38 = 0;
  v36 = 0;
  sub_262A0(a1, a2, a3);
  sub_1FC40(_progname, 2, 2, 0);
  while ( 1 )
  {
    v5 = sub_3BA40((unsigned int)a1, a2, "v");
    if ( v5 == -1 )
      break;
    if ( v5 != 118 )
    {
      __fprintf_chk(stderr, 1, "usage: %s [-v]\n", _progname);
      exit(1);
    }
    if ( v3 == 2 )
    {
      v3 = 5;
    }
    else if ( (int)v3 <= 6 )
    {
      v3 = sub_3DA20(v3, 1);
    }
    v4 = 1;
  }
  v6 = v3;
  sub_1FC40(_progname, v3, 2, v4);
  closefrom(3);
  v7 = dup(0);
  if ( v7 == -1 || (v8 = dup(1), v8 == -1) )
  {
    v29 = __errno_location();
    v30 = strerror(*v29);
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"main",
      309,
      0,
      1,
      0,
      (long long)"%s: dup: %s",
      _progname,
      v30);
  }
  close(0);
  close(1);
  sub_262A0(1, v6, v9);
  v10 = sub_B880();
  v11 = (void *)v10;
  if ( !v10 )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"main",
      315,
      0,
      1,
      0,
      (long long)"%s: sshbuf_new failed",
      _progname);
  if ( (int)sub_2EF90(v7, v10) < 0 )
    sub_1EE30((unsigned int)"ssh-sk-helper.c", (unsigned int)"main", 317, 0, 1, 0, (long long)"ssh_msg_recv failed", v12);
  close(v7);
  v13 = sub_C3D0(v11);
  sub_203A0((unsigned int)"ssh-sk-helper.c", (unsigned int)"main", 319, 1, 5, 0, "received message len %zu", v13);
  v14 = sub_19E50(v11, &v35);
  if ( v14 )
  {
    v31 = _progname;
    v32 = sub_B050(v14, &v35, v15, v16, v33, v34);
    sub_1EE30((unsigned int)"ssh-sk-helper.c", (unsigned int)"main", 322, 0, 1, v32, (long long)"%s: parse version", v31);
  }
  if ( v35 != 5 )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"main",
      324,
      0,
      1,
      0,
      (long long)"unsupported version: received %d, expected %d",
      v35,
      5);
  v17 = &v37;
  v18 = sub_19CD0(v11, &v37, v15, v16, v33, v34);
  if ( v18
    || (v17 = &v36, (v18 = sub_19E50(v11, &v36)) != 0)
    || (v17 = &v38, (v18 = sub_19CD0(v11, &v38, v19, v20, v21, v22)) != 0) )
  {
    v27 = _progname;
    v28 = sub_B050(v18, v17, v19, v20, v21, v22);
    sub_1EE30((unsigned int)"ssh-sk-helper.c", (unsigned int)"main", 331, 0, 1, v28, (long long)"%s: parse", v27);
  }
  if ( !v4 && sub_1F810(v38) )
    sub_1FC40(_progname, v38, 2, v36);
  switch ( v37 )
  {
    case 2:
      v23 = (void *)sub_7BB0(v11);
      break;
    case 3:
      v23 = (void *)sub_8050(v11);
      break;
    case 1:
      v23 = (void *)sub_7760(v11);
      break;
    default:
      sub_1EE30(
        (unsigned int)"ssh-sk-helper.c",
        (unsigned int)"main",
        347,
        0,
        1,
        0,
        (long long)"%s: unsupported request type %u",
        _progname,
        v37);
  }
  sub_BCE0(v11);
  v24 = sub_C3D0(v23);
  sub_203A0((unsigned int)"ssh-sk-helper.c", (unsigned int)"main", 350, 1, 5, 0, "reply len %zu", v24);
  v25 = sub_2EDA0(v8, 5, v23);
  if ( (int)v25 == -1 )
    sub_1EE30((unsigned int)"ssh-sk-helper.c", (unsigned int)"main", 353, 0, 1, 0, (long long)"ssh_msg_send failed", v25);
  sub_BCE0(v23);
  close(v8);
  return 0;
}


// Function: null_empty @ 0x73c0
double null_empty(char **a1)
{
  char *v2; // rdi

  v2 = *a1;
  if ( !v2 || *v2 )
    return 0.0;
  free(v2);
  *a1 = 0;
  return 0.0;
}


// Function: reply_error @ 0x74f0
double reply_error(int a1, long long a2, ...)
{
  long long v2; // rax
  long long v3; // r12
  unsigned int v4; // eax
  void *ptr; // [rsp+8h] [rbp-100h] BYREF
  gcc_va_list va; // [rsp+10h] [rbp-F8h] BYREF
  unsigned long long v8; // [rsp+28h] [rbp-E0h]

  va_start(va, a2);
  v8 = __readfsqword(0x28u);
  sub_21880(&ptr, a2, va);
  sub_203A0(
    (unsigned int)"ssh-sk-helper.c",
    (unsigned int)"reply_error",
    66,
    0,
    5,
    0,
    "%s: %s",
    _progname,
    (const char *)ptr);
  free(ptr);
  if ( a1 >= 0 )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"reply_error",
      70,
      1,
      1,
      0,
      (long long)"invalid error code %d",
      a1);
  v2 = sub_B880();
  v3 = v2;
  if ( !v2 )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"reply_error",
      73,
      0,
      1,
      0,
      (long long)"%s: sshbuf_new failed",
      _progname);
  if ( (unsigned int)sub_1AFB0(v2, 0) || (v4 = sub_3DAE0((unsigned int)a1), (unsigned int)sub_1AFB0(v3, v4)) )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"reply_error",
      76,
      0,
      1,
      0,
      (long long)"%s: buffer error",
      _progname);
  return 0.0;
}


// Function: process_sign @ 0x7760
double process_sign(long long a1)
{
  long long *p_ptr; // rsi
  unsigned int v2; // eax
  long long v3; // rdx
  long long v4; // rcx
  long long v5; // r8
  long long v6; // r9
  unsigned int v7; // eax
  long long v8; // rdx
  long long v9; // rcx
  long long v10; // r8
  long long v11; // r9
  long long v12; // r13
  const char *v13; // rbp
  long long v14; // rbx
  const char *v15; // rax
  double v16; // xmm0_8
  void *v17; // rsi
  void *v18; // rdi
  long long v19; // rcx
  long long v20; // r8
  long long v21; // r9
  unsigned int v22; // r12d
  long long v23; // rax
  long long v24; // r12
  void *v25; // rsi
  unsigned int v26; // eax
  long long v27; // rdx
  long long v28; // rcx
  long long v29; // r8
  long long v30; // r9
  char *v31; // rbp
  const char *v33; // rax
  const char *v34; // rbx
  int v35; // eax
  const char *v36; // rbx
  int v37; // eax
  const char *v38; // rbx
  int v39; // eax
  const char *v40; // rax
  long long v41; // [rsp-8h] [rbp-80h]
  int v42; // [rsp+4h] [rbp-74h] BYREF
  void *v43; // [rsp+8h] [rbp-70h] BYREF
  void *v44; // [rsp+10h] [rbp-68h] BYREF
  long long v45; // [rsp+18h] [rbp-60h] BYREF
  void *v46; // [rsp+20h] [rbp-58h]
  long long v47; // [rsp+28h] [rbp-50h] BYREF
  long long v48; // [rsp+30h] [rbp-48h]
  void *ptr; // [rsp+38h] [rbp-40h] BYREF
  char *s[7]; // [rsp+40h] [rbp-38h] BYREF

  s[1] = (char *)__readfsqword(0x28u);
  p_ptr = (long long *)&v43;
  v44 = 0;
  v46 = 0;
  v48 = 0;
  ptr = 0;
  s[0] = 0;
  v2 = sub_1B8A0(a1, &v43);
  if ( v2 )
    goto LABEL_20;
  p_ptr = (long long *)&ptr;
  v2 = sub_1A6F0(a1, &ptr, 0);
  if ( v2 )
    goto LABEL_20;
  p_ptr = &v45;
  v2 = sub_1A460(a1, &v45, &v47);
  if ( v2
    || (p_ptr = 0, (v2 = sub_1A6F0(a1, 0, 0)) != 0)
    || (p_ptr = (long long *)&v42, (v2 = sub_19CD0(a1, &v42, v3, v4, v5, v6)) != 0)
    || (p_ptr = (long long *)s, (v2 = sub_1A6F0(a1, s, 0)) != 0) )
  {
LABEL_20:
    v34 = _progname;
    v35 = sub_B050(v2, p_ptr, v3, v4, v5, v6);
    sub_1EE30((unsigned int)"ssh-sk-helper.c", (unsigned int)"process_sign", 109, 0, 1, v35, (long long)"%s: parse", v34);
  }
  if ( sub_C3D0(a1) )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_sign",
      111,
      0,
      1,
      0,
      (long long)"%s: trailing data in request",
      _progname);
  v7 = sub_16380(v43, &v44);
  if ( v7 )
  {
    v38 = _progname;
    v39 = sub_B050(v7, &v44, v8, v9, v10, v11);
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_sign",
      114,
      0,
      1,
      v39,
      (long long)"%s: Unable to parse private key",
      v38);
  }
  if ( !(unsigned int)sub_F8D0(v44) )
  {
    v40 = (const char *)sub_EAF0(v44);
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_sign",
      116,
      0,
      1,
      0,
      (long long)"%s: Unsupported key type %s",
      _progname,
      v40);
  }
  v12 = v47;
  v13 = (const char *)ptr;
  v14 = (unsigned int)v42;
  v15 = (const char *)sub_E880(v44);
  sub_203A0(
    (unsigned int)"ssh-sk-helper.c",
    (unsigned int)"process_sign",
    120,
    1,
    5,
    0,
    "ready to sign with key %s, provider %s: msg len %zu, compat 0x%lx",
    v15,
    v13,
    v12,
    v14);
  v16 = sub_73C0(s);
  v17 = v44;
  v18 = ptr;
  v22 = sub_A4D0((char *)ptr, v42, (long long)s[0]);
  if ( v22 )
  {
    v33 = (const char *)sub_B050(v22, v17, v41, v19, v20, v21);
    sub_74F0(v22, (long long)"Signing failed: %s", v33);
  }
  else
  {
    v23 = sub_B880(v18, v17, v41, v16);
    v24 = v23;
    if ( !v23 )
      sub_1EE30(
        (unsigned int)"ssh-sk-helper.c",
        (unsigned int)"process_sign",
        133,
        0,
        1,
        0,
        (long long)"%s: sshbuf_new failed",
        _progname);
    v25 = &dword_0 + 1;
    v26 = sub_1AFB0(v23, 1);
    if ( v26 || (v25 = v46, (v26 = sub_1B6C0(v24, v46, v48)) != 0) )
    {
      v36 = _progname;
      v37 = sub_B050(v26, v25, v27, v28, v29, v30);
      sub_1EE30(
        (unsigned int)"ssh-sk-helper.c",
        (unsigned int)"process_sign",
        137,
        0,
        1,
        v37,
        (long long)"%s: compose",
        v36);
    }
  }
  sub_10A60(v44);
  sub_BCE0(v43);
  free(ptr);
  if ( v46 )
    sub_3B0D0(v46);
  v31 = s[0];
  if ( s[0] )
  {
    strlen(s[0]);
    sub_3B0D0(v31);
  }
  return 0.0;
}


// Function: process_enroll @ 0x7bb0
double process_enroll(long long a1, long long a2, long long a3, double a4)
{
  long long v4; // rax
  long long v5; // rdx
  void *v6; // r12
  long long v7; // rdx
  long long v8; // rcx
  long long v9; // r8
  long long v10; // r9
  void *v11; // r13
  int *p_ptr; // rsi
  unsigned int v13; // eax
  long long v14; // rdx
  long long v15; // rcx
  long long v16; // r8
  long long v17; // r9
  double v18; // xmm0_8
  void *v19; // rsi
  long long v20; // rdi
  unsigned int v21; // eax
  long long v22; // rdx
  long long v23; // rcx
  long long v24; // r8
  long long v25; // r9
  int v26; // ebp
  long long v27; // r14
  unsigned int v28; // eax
  long long v29; // rdx
  long long v30; // rcx
  long long v31; // r8
  long long v32; // r9
  long long v33; // rsi
  unsigned int v34; // eax
  long long v35; // rdx
  long long v36; // rcx
  long long v37; // r8
  long long v38; // r9
  char *v39; // rbp
  const char *v41; // rax
  const char *v42; // rbx
  int v43; // eax
  const char *v44; // rbx
  int v45; // eax
  const char *v46; // rbx
  int v47; // eax
  unsigned char v48; // [rsp+Bh] [rbp-7Dh] BYREF
  int v49; // [rsp+Ch] [rbp-7Ch] BYREF
  void *ptr; // [rsp+10h] [rbp-78h] BYREF
  void *v51; // [rsp+18h] [rbp-70h] BYREF
  char *s; // [rsp+20h] [rbp-68h] BYREF
  char *v53; // [rsp+28h] [rbp-60h] BYREF
  char *v54; // [rsp+30h] [rbp-58h] BYREF
  void *v55; // [rsp+38h] [rbp-50h] BYREF
  void *v56[9]; // [rsp+40h] [rbp-48h] BYREF

  v56[1] = (void *)__readfsqword(0x28u);
  v4 = sub_B880(a1, a2, a3, a4);
  if ( !v4 || (v6 = (void *)v4, (v11 = (void *)sub_B880(a1, a2, v5, a4)) == 0) )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_enroll",
      161,
      0,
      1,
      0,
      (long long)"%s: sshbuf_new failed",
      _progname);
  p_ptr = &v49;
  v13 = sub_19CD0(a1, &v49, v7, v8, v9, v10);
  if ( v13 )
    goto LABEL_25;
  p_ptr = (int *)&ptr;
  v13 = sub_1A6F0(a1, &ptr, 0);
  if ( v13 )
    goto LABEL_25;
  p_ptr = (int *)&v53;
  v13 = sub_1A6F0(a1, &v53, 0);
  if ( v13 )
    goto LABEL_25;
  p_ptr = (int *)&v51;
  v13 = sub_1A6F0(a1, &v51, 0);
  if ( v13 )
    goto LABEL_25;
  p_ptr = (int *)&v54;
  v13 = sub_1A6F0(a1, &v54, 0);
  if ( v13
    || (p_ptr = (int *)&v48, (v13 = sub_19E50(a1, &v48)) != 0)
    || (p_ptr = (int *)&s, (v13 = sub_1A6F0(a1, &s, 0)) != 0)
    || (p_ptr = (int *)&v55, (v13 = sub_1B8A0(a1, &v55)) != 0) )
  {
LABEL_25:
    v42 = _progname;
    v43 = sub_B050(v13, p_ptr, v14, v15, v16, v17);
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_enroll",
      171,
      0,
      1,
      v43,
      (long long)"%s: parse",
      v42);
  }
  if ( sub_C3D0(a1) )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_enroll",
      173,
      0,
      1,
      0,
      (long long)"%s: trailing data in request",
      _progname);
  if ( v49 < 0 )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_enroll",
      176,
      0,
      1,
      0,
      (long long)"%s: bad type %u",
      _progname,
      v49);
  if ( !sub_C3D0(v55) )
  {
    sub_BCE0(v55);
    v55 = 0;
  }
  sub_73C0(&v53);
  sub_73C0(&v54);
  v18 = sub_73C0(&s);
  v19 = ptr;
  v20 = (unsigned int)v49;
  v21 = sub_9FB0((unsigned int)v49, ptr, v53, v51, v54, v48, v18, s, v55, v56, v6);
  v26 = v21;
  if ( v21 )
  {
    v41 = (const char *)sub_B050(v21, v19, v22, v23, v24, v25);
    sub_74F0(v26, (long long)"Enrollment failed: %s", v41);
  }
  else
  {
    v27 = sub_B880(v20, v19, v22, v18);
    if ( !v27 )
      sub_1EE30(
        (unsigned int)"ssh-sk-helper.c",
        (unsigned int)"process_enroll",
        192,
        0,
        1,
        0,
        (long long)"%s: sshbuf_new failed",
        _progname);
    v28 = sub_17D00(v56[0], v11);
    if ( v28 )
    {
      v46 = _progname;
      v47 = sub_B050(v28, v11, v29, v30, v31, v32);
      sub_1EE30(
        (unsigned int)"ssh-sk-helper.c",
        (unsigned int)"process_enroll",
        194,
        0,
        1,
        v47,
        (long long)"%s: encode key",
        v46);
    }
    v33 = 2;
    v34 = sub_1AFB0(v27, 2);
    if ( v34
      || (v33 = (long long)v11, (v34 = sub_1B840(v27, v11)) != 0)
      || (v33 = (long long)v6, (v34 = sub_1B840(v27, v6)) != 0) )
    {
      v44 = _progname;
      v45 = sub_B050(v34, v33, v35, v36, v37, v38);
      sub_1EE30(
        (unsigned int)"ssh-sk-helper.c",
        (unsigned int)"process_enroll",
        198,
        0,
        1,
        v45,
        (long long)"%s: compose",
        v44);
    }
  }
  sub_10A60(v56[0]);
  sub_BCE0(v11);
  sub_BCE0(v6);
  sub_BCE0(v55);
  free(ptr);
  free(v51);
  v39 = s;
  if ( s )
  {
    strlen(s);
    sub_3B0D0(v39);
  }
  return 0.0;
}


// Function: process_load_resident @ 0x8050
double process_load_resident(long long a1, long long a2, long long a3, double a4)
{
  long long v4; // rax
  int *p_ptr; // rsi
  char *v6; // rbp
  unsigned int v7; // eax
  long long v8; // rdx
  long long v9; // rcx
  long long v10; // r8
  long long v11; // r9
  unsigned long long v12; // rbx
  double v13; // xmm0_8
  void *v14; // rsi
  void *v15; // rdi
  unsigned int v16; // eax
  long long v17; // rdx
  long long v18; // rcx
  long long v19; // r8
  long long v20; // r9
  int v21; // r12d
  long long v22; // rax
  long long v23; // r12
  unsigned int v24; // eax
  long long v25; // rdx
  long long v26; // rcx
  long long v27; // r8
  long long v28; // r9
  long long *v29; // rax
  const char *v30; // r13
  const char *v31; // rax
  unsigned int v32; // eax
  long long v33; // rdx
  long long v34; // rcx
  long long v35; // r8
  long long v36; // r9
  const char *v37; // rsi
  unsigned int v38; // eax
  long long v39; // rdx
  long long v40; // rcx
  long long v41; // r8
  long long v42; // r9
  long long v43; // rax
  char *v44; // rbp
  const char *v46; // rax
  const char *v47; // rbx
  int v48; // eax
  const char *v49; // rbx
  int v50; // eax
  const char *v51; // rbx
  int v52; // eax
  const char *v53; // rbx
  int v54; // eax
  long long v55; // [rsp+0h] [rbp-88h]
  int v56; // [rsp+1Ch] [rbp-6Ch] BYREF
  void *ptr; // [rsp+20h] [rbp-68h] BYREF
  char *s; // [rsp+28h] [rbp-60h] BYREF
  void *v59; // [rsp+30h] [rbp-58h] BYREF
  void *v60; // [rsp+38h] [rbp-50h]
  unsigned long long v61; // [rsp+40h] [rbp-48h]
  unsigned long long v62; // [rsp+48h] [rbp-40h]

  v62 = __readfsqword(0x28u);
  v60 = 0;
  v61 = 0;
  v4 = sub_B880(a1, a2, a3, a4);
  if ( !v4 )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_load_resident",
      224,
      0,
      1,
      0,
      (long long)"%s: sshbuf_new failed",
      _progname);
  p_ptr = (int *)&ptr;
  v6 = (char *)v4;
  v7 = sub_1A6F0(a1, &ptr, 0);
  if ( v7
    || (p_ptr = (int *)&v59, (v7 = sub_1A6F0(a1, &v59, 0)) != 0)
    || (p_ptr = (int *)&s, (v7 = sub_1A6F0(a1, &s, 0)) != 0)
    || (p_ptr = &v56, (v7 = sub_19CD0(a1, &v56, v8, v9, v10, v11)) != 0) )
  {
    v51 = _progname;
    v52 = sub_B050(v7, p_ptr, v8, v9, v10, v11);
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_load_resident",
      230,
      0,
      1,
      v52,
      (long long)"%s: parse",
      v51);
  }
  v12 = sub_C3D0(a1);
  if ( v12 )
    sub_1EE30(
      (unsigned int)"ssh-sk-helper.c",
      (unsigned int)"process_load_resident",
      232,
      0,
      1,
      0,
      (long long)"%s: trailing data in request",
      _progname);
  sub_73C0((char **)&v59);
  v13 = sub_73C0(&s);
  v14 = v59;
  v15 = ptr;
  v16 = sub_AAE0((char *)ptr);
  v21 = v16;
  if ( v16 )
  {
    v46 = (const char *)sub_B050(v16, v14, v17, v18, v19, v20);
    sub_74F0(v21, (long long)"sshsk_load_resident failed: %s", v46);
  }
  else
  {
    v22 = sub_B880(v15, v14, v17, v13);
    v23 = v22;
    if ( !v22 )
      sub_1EE30(
        (unsigned int)"ssh-sk-helper.c",
        (unsigned int)"process_load_resident",
        245,
        0,
        1,
        0,
        (long long)"%s: sshbuf_new failed",
        _progname);
    v24 = sub_1AFB0(v22, 3);
    if ( v24 )
    {
      v53 = _progname;
      v54 = sub_B050(v24, 3, v25, v26, v27, v28);
      sub_1EE30(
        (unsigned int)"ssh-sk-helper.c",
        (unsigned int)"process_load_resident",
        248,
        0,
        1,
        v54,
        (long long)"%s: compose",
        v53);
    }
    if ( v61 )
    {
      do
      {
        v29 = (long long *)*((long long *)v60 + v12);
        v55 = v29[2];
        v30 = *(const char **)(*v29 + 96LL);
        v31 = (const char *)sub_E880(*v29);
        sub_203A0(
          (unsigned int)"ssh-sk-helper.c",
          (unsigned int)"process_load_resident",
          251,
          1,
          5,
          0,
          "key %zu %s %s uidlen %zu",
          v12,
          v31,
          v30,
          v55);
        sub_BE60(v6);
        v32 = sub_17D00(**((long long **)v60 + v12), v6);
        if ( v32 )
        {
          v49 = _progname;
          v50 = sub_B050(v32, v6, v33, v34, v35, v36);
          sub_1EE30(
            (unsigned int)"ssh-sk-helper.c",
            (unsigned int)"process_load_resident",
            256,
            0,
            1,
            v50,
            (long long)"%s: encode key",
            v49);
        }
        v37 = v6;
        v38 = sub_1B840(v23, v6);
        if ( v38
          || (v37 = "", (v38 = sub_1B800(v23, "")) != 0)
          || (v43 = *((long long *)v60 + v12),
              v37 = *(const char **)(v43 + 8),
              (v38 = sub_1B6C0(v23, v37, *(long long *)(v43 + 16))) != 0) )
        {
          v47 = _progname;
          v48 = sub_B050(v38, v37, v39, v40, v41, v42);
          sub_1EE30(
            (unsigned int)"ssh-sk-helper.c",
            (unsigned int)"process_load_resident",
            261,
            0,
            1,
            v48,
            (long long)"%s: compose key",
            v47);
        }
        ++v12;
      }
      while ( v61 > v12 );
    }
  }
  sub_A990(v60);
  sub_BCE0(v6);
  free(ptr);
  free(v59);
  v44 = s;
  if ( s )
  {
    strlen(s);
    sub_3B0D0(v44);
  }
  return 0.0;
}


// Function: skerr_to_ssherr @ 0x8500
double skerr_to_ssherr()
{
  return 0.0;
}


// Function: fill_attestation_blob @ 0x85a0
double fill_attestation_blob(long long *a1, long long a2)
{
  const char *v3; // rsi
  long long v4; // rdx
  long long v5; // rcx
  long long v6; // r8
  long long v7; // r9
  unsigned int v8; // r12d
  int v9; // eax

  if ( !a2 )
    return 0.0;
  v3 = "ssh-sk-attest-v01";
  v8 = sub_1B800(a2, "ssh-sk-attest-v01");
  if ( !v8 )
  {
    v3 = (const char *)a1[7];
    v8 = sub_1B6C0(a2, v3, a1[8]);
    if ( !v8 )
    {
      v3 = (const char *)a1[5];
      v8 = sub_1B6C0(a2, v3, a1[6]);
      if ( !v8 )
      {
        v3 = (const char *)a1[9];
        v8 = sub_1B6C0(a2, v3, a1[10]);
        if ( !v8 )
        {
          v3 = 0;
          v8 = sub_1AFB0(a2, 0);
          if ( !v8 )
          {
            v3 = 0;
            v8 = sub_1B6C0(a2, 0, 0);
            if ( !v8 )
              return 0.0;
          }
        }
      }
    }
  }
  v9 = sub_B050(v8, v3, v4, v5, v6, v7);
  sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"fill_attestation_blob", 453, 1, 2, v9, "compose");
  return 0.0;
}


// Function: sshsk_free_options @ 0x8790
double sshsk_free_options(void ***ptr)
{
  void **v1; // rax
  void ***v2; // rbx
  double result; // xmm0_8

  if ( !ptr )
    return 0.0;
  v1 = *ptr;
  if ( *ptr )
  {
    v2 = ptr;
    do
    {
      ++v2;
      free(*v1);
      free((*(v2 - 1))[1]);
      free(*(v2 - 1));
      v1 = *v2;
    }
    while ( *v2 );
  }
  free(ptr);
  return result;
}


// Function: sshsk_free @ 0x8870
double sshsk_free(void **ptr)
{
  void *v2; // rdi
  double result; // xmm0_8

  if ( !ptr )
    return 0.0;
  free(*ptr);
  v2 = ptr[1];
  if ( v2 )
    dlclose(v2);
  free(ptr);
  return result;
}


// Function: sshsk_open @ 0x8920
double sshsk_open(char *file)
{
  const char **v1; // r12
  char *v2; // rax
  char *v3; // rax
  unsigned int (*v4)(void); // rax
  long long v5; // r15
  int v6; // ebp
  const char *v7; // rax
  const char *v8; // rax
  const char *v9; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  char *v14; // rax
  char *v15; // rax

  if ( !file || !*file )
  {
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_open",
      113,
      0,
      2,
      0,
      "No FIDO SecurityKeyProvider specified");
    return 0.0;
  }
  v1 = (const char **)calloc(1u, 0x30u);
  if ( !v1 )
  {
    sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_open", 117, 1, 2, 0, "calloc failed", 48);
    return 0.0;
  }
  v2 = strdup(file);
  *v1 = v2;
  if ( !v2 )
  {
    sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_open", 121, 1, 2, 0, "strdup failed");
    goto LABEL_15;
  }
  if ( !strcasecmp(v2, "internal") )
  {
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_open",
      132,
      0,
      2,
      0,
      "internal security key support not enabled");
    goto LABEL_15;
  }
  v3 = (char *)dlopen(file, 2);
  v1[1] = v3;
  if ( !v3 )
  {
    v12 = dlerror();
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_open",
      137,
      0,
      2,
      0,
      "Provider \"%s\" dlopen failed: %s",
      file,
      v12);
    goto LABEL_15;
  }
  v4 = (unsigned int (*)(void))dlsym(v3, "sk_api_version");
  v1[2] = (const char *)v4;
  if ( !v4 )
  {
    v11 = dlerror();
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_open",
      142,
      0,
      2,
      0,
      "Provider \"%s\" dlsym(sk_api_version) failed: %s",
      file,
      v11);
    goto LABEL_15;
  }
  v5 = v4();
  HIWORD(v6) = WORD1(v5);
  LOWORD(v6) = 0;
  sub_203A0(
    (unsigned int)"ssh-sk.c",
    (unsigned int)"sshsk_open",
    147,
    1,
    5,
    0,
    "provider %s implements version 0x%08lx",
    *v1,
    v5);
  if ( v6 != 655360 )
  {
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_open",
      150,
      0,
      2,
      0,
      "Provider \"%s\" implements unsupported version 0x%08lx (supported: 0x%08lx)",
      file,
      v5,
      655360);
LABEL_15:
    sub_8870((void **)v1);
    return 0.0;
  }
  v7 = (const char *)dlsym((void *)v1[1], "sk_enroll");
  v1[3] = v7;
  if ( !v7 )
  {
    v13 = dlerror();
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_open",
      156,
      0,
      2,
      0,
      "Provider %s dlsym(sk_enroll) failed: %s",
      file,
      v13);
    goto LABEL_15;
  }
  v8 = (const char *)dlsym((void *)v1[1], "sk_sign");
  v1[4] = v8;
  if ( !v8 )
  {
    v14 = dlerror();
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_open",
      161,
      0,
      2,
      0,
      "Provider \"%s\" dlsym(sk_sign) failed: %s",
      file,
      v14);
    goto LABEL_15;
  }
  v9 = (const char *)dlsym((void *)v1[1], "sk_load_resident_keys");
  v1[5] = v9;
  if ( !v9 )
  {
    v15 = dlerror();
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_open",
      167,
      0,
      2,
      0,
      "Provider \"%s\" dlsym(sk_load_resident_keys) failed: %s",
      file,
      v15);
    goto LABEL_15;
  }
  return 0.0;
}


// Function: sshsk_free_enroll_response @ 0x8d30
double sshsk_free_enroll_response(void **ptr)
{
  double result; // xmm0_8

  if ( !ptr )
    return 0.0;
  sub_3B0D0(ptr[3]);
  sub_3B0D0(ptr[1]);
  sub_3B0D0(ptr[5]);
  sub_3B0D0(ptr[7]);
  sub_3B0D0(ptr[9]);
  sub_3B0D0(ptr);
  return result;
}


// Function: sshsk_free_sign_response @ 0x8e10
double sshsk_free_sign_response(void **ptr)
{
  double result; // xmm0_8

  if ( !ptr )
    return 0.0;
  sub_3B0D0(ptr[1]);
  sub_3B0D0(ptr[3]);
  sub_3B0D0(ptr);
  return result;
}


// Function: sshsk_free_resident_key @ 0x8ed0
double sshsk_free_resident_key(void **ptr)
{
  double result; // xmm0_8

  if ( !ptr )
    return 0.0;
  sub_10A60(*ptr);
  sub_3B0D0(ptr[1]);
  free(ptr);
  return result;
}


// Function: sshsk_free_sk_resident_keys @ 0x8f80
double sshsk_free_sk_resident_keys(long long *ptr, unsigned long long a2)
{
  long long *v2; // rbx
  unsigned long long v3; // rbp
  long long v4; // rax
  double result; // xmm0_8

  if ( !a2 )
    return 0.0;
  if ( !ptr )
    return 0.0;
  v2 = ptr;
  v3 = 0;
  do
  {
    v4 = *v2;
    ++v3;
    ++v2;
    free(*(void **)(v4 + 16));
    sub_3B0D0(*(void **)(*(v2 - 1) + 120));
    sub_3B0D0(*(void **)(*(v2 - 1) + 48));
    sub_3B0D0(*(void **)(*(v2 - 1) + 32));
    sub_3B0D0(*(void **)(*(v2 - 1) + 64));
    sub_3B0D0(*(void **)(*(v2 - 1) + 80));
    sub_3B0D0((void *)*(v2 - 1));
  }
  while ( a2 > v3 );
  free(ptr);
  return result;
}


// Function: sshsk_ecdsa_sig @ 0x9160
double sshsk_ecdsa_sig(unsigned char *a1, long long a2, long long a3, double a4)
{
  long long v5; // rax
  void *v6; // rbp
  long long v7; // rsi
  long long v8; // rdx
  long long v9; // rcx
  long long v10; // r8
  long long v11; // r9
  unsigned int v12; // r12d
  int v13; // eax
  unsigned long long v15; // rsi
  long long v16; // rdx
  long long v17; // rcx
  long long v18; // r8
  long long v19; // r9
  unsigned int v20; // r12d
  int v21; // eax

  if ( *((long long *)a1 + 1) && *((long long *)a1 + 3) )
  {
    v5 = sub_B880(a1, a2, a3, a4);
    v6 = (void *)v5;
    if ( v5 )
    {
      v7 = *((long long *)a1 + 1);
      v12 = sub_1BA10(v5, v7, *((long long *)a1 + 2));
      if ( v12 || (v7 = *((long long *)a1 + 3), (v12 = sub_1BA10(v6, v7, *((long long *)a1 + 4))) != 0) )
      {
        v13 = sub_B050(v12, v7, v8, v9, v10, v11);
        sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_ecdsa_sig", 583, 1, 2, v13, "compose inner");
      }
      else
      {
        v15 = (unsigned long long)v6;
        v20 = sub_1B840(a2, v6);
        if ( v20
          || (v15 = *a1, (v20 = sub_1B180(a2, v15)) != 0)
          || (v15 = *((unsigned int *)a1 + 1), (v20 = sub_1AFB0(a2, v15)) != 0) )
        {
          v21 = sub_B050(v20, v15, v16, v17, v18, v19);
          sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_ecdsa_sig", 589, 1, 2, v21, "compose");
        }
      }
    }
  }
  else
  {
    v6 = 0;
    sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_ecdsa_sig", 570, 1, 2, 0, "sk_sign response invalid");
  }
  sub_BCE0(v6);
  return 0.0;
}


// Function: sshsk_ed25519_sig @ 0x9360
double sshsk_ed25519_sig(unsigned char *a1, long long a2)
{
  long long v3; // rsi
  long long v4; // rdx
  long long v5; // rcx
  long long v6; // r8
  long long v7; // r9
  unsigned int v8; // r12d
  int v9; // eax

  v3 = *((long long *)a1 + 1);
  if ( v3 )
  {
    v8 = sub_1B6C0(a2, v3, *((long long *)a1 + 2));
    if ( v8
      || (v3 = *a1, (v8 = sub_1B180(a2, v3)) != 0)
      || (v3 = *((unsigned int *)a1 + 1), (v8 = sub_1AFB0(a2, v3)) != 0) )
    {
      v9 = sub_B050(v8, v3, v4, v5, v6, v7);
      sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_ed25519_sig", 622, 1, 2, v9, "compose");
    }
  }
  else
  {
    sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_ed25519_sig", 614, 1, 2, 0, "sk_sign response invalid");
  }
  return 0.0;
}


// Function: sshsk_key_from_response @ 0x9d20
double sshsk_key_from_response(int a1, const char *a2, char a3, long long *a4, long long *a5, double a6)
{
  bool v6; // zf
  long long v11; // rdx
  long long *v12; // rbp
  long long v13; // rax
  long long v14; // rdx
  long long v15; // rax
  char *v16; // rax
  long long v17; // rsi
  unsigned int v18; // eax
  long long v19; // rdx
  long long v20; // rcx
  long long v21; // r8
  long long v22; // r9
  int v24; // eax
  int v25; // edx
  const char *v26; // [rsp-10h] [rbp-58h]
  long long v27[9]; // [rsp+0h] [rbp-48h] BYREF

  v27[1] = __readfsqword(0x28u);
  *a5 = 0;
  v6 = a4[1] == 0;
  v27[0] = 0;
  if ( v6 || !a4[3] )
  {
    v12 = 0;
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_key_from_response",
      301,
      1,
      2,
      0,
      "sk_enroll response invalid");
    goto LABEL_10;
  }
  v6 = a1 == 1;
  if ( v6 )
  {
    if ( !(unsigned int)sub_9840(a4, v27) )
      goto LABEL_5;
LABEL_12:
    v12 = (long long *)v27[0];
    goto LABEL_10;
  }
  if ( (unsigned int)sub_99E0(a4, v27) )
    goto LABEL_12;
LABEL_5:
  v12 = (long long *)v27[0];
  *(char *)(v27[0] + 104LL) = a3;
  v13 = sub_B880(a4, v27, v11, a6);
  v12[14] = v13;
  if ( !v13 || (v15 = sub_B880(a4, v27, v14, a6), (v12[15] = v15) == 0) )
  {
    v26 = "allocation failed";
    v25 = 324;
LABEL_16:
    sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_key_from_response", v25, 1, 2, 0, v26);
    goto LABEL_10;
  }
  v16 = strdup(a2);
  v12[12] = v16;
  if ( !v16 )
  {
    v26 = "strdup application failed";
    v25 = 329;
    goto LABEL_16;
  }
  v17 = a4[3];
  v18 = sub_1A9D0(v12[14], v17, a4[4]);
  if ( v18 )
  {
    v24 = sub_B050(v18, v17, v19, v20, v21, v22);
    sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_key_from_response", 335, 1, 2, v24, "put key handle");
  }
  else
  {
    *a5 = v12;
    v12 = 0;
  }
LABEL_10:
  sub_10A60(v12);
  return 0.0;
}


// Function: sshsk_enroll @ 0x9fb0
double sshsk_enroll(
        int a1,
        char *a2,
        const char *a3,
        const char *a4,
        const char *a5,
        unsigned char a6,
        char *a7,
        long long a8,
        void **a9,
        long long a10)
{
  const char *v13; // rdx
  void *v14; // rbp
  long long v15; // rax
  long long v16; // r11
  unsigned int v17; // r12d
  long long v18; // rax
  double v19; // xmm0_8
  void **v20; // r13
  int v21; // ebx
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  double v25; // xmm0_8
  int v27; // eax
  const char *v28; // [rsp-10h] [rbp-D8h]
  const char *ptra; // [rsp+10h] [rbp-B8h]
  void ***ptr; // [rsp+10h] [rbp-B8h]
  char *v32; // [rsp+28h] [rbp-A0h]
  long long v33; // [rsp+38h] [rbp-90h]
  void *v34; // [rsp+48h] [rbp-80h] BYREF
  void *v35; // [rsp+50h] [rbp-78h] BYREF
  void ***v36; // [rsp+58h] [rbp-70h] BYREF
  char dest[40]; // [rsp+60h] [rbp-68h] BYREF
  unsigned long long v38; // [rsp+88h] [rbp-40h]

  v13 = "";
  v14 = a2;
  v38 = __readfsqword(0x28u);
  v34 = 0;
  v35 = 0;
  v36 = 0;
  if ( a7 && *a7 )
    v13 = " with-pin";
  v15 = 0;
  if ( a8 )
  {
    ptra = v13;
    v15 = sub_C3D0(a8);
    v13 = ptra;
  }
  sub_203A0(
    (unsigned int)"ssh-sk.c",
    (unsigned int)"sshsk_enroll",
    476,
    1,
    5,
    0,
    "provider \"%s\", device \"%s\", application \"%s\", userid \"%s\", flags 0x%02x, challenge len %zu%s",
    a2,
    a3,
    a4,
    a5,
    a6,
    v15,
    v13);
  *a9 = 0;
  if ( a10 )
    sub_BE60(a10);
  v17 = sub_96F0(a3, a5, &v36);
  ptr = v36;
  if ( v17 )
  {
    v14 = 0;
    v20 = 0;
    goto LABEL_24;
  }
  if ( a1 != 10 )
  {
    if ( a1 != 12 )
    {
      v28 = "unsupported key type";
      v23 = 1;
      v24 = 499;
      goto LABEL_23;
    }
    v17 = 1;
  }
  if ( !a2 )
  {
    v20 = 0;
    sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_enroll", 504, 1, 2, 0, "missing provider", v16);
    goto LABEL_24;
  }
  if ( !a4 || !*a4 )
  {
    v28 = "missing application";
    v23 = 1;
    v24 = 509;
    goto LABEL_23;
  }
  if ( a8 )
  {
    if ( sub_C3D0(a8) )
    {
      v32 = (char *)sub_C520(a8);
      v33 = sub_C3D0(a8);
      sub_203A0(
        (unsigned int)"ssh-sk.c",
        (unsigned int)"sshsk_enroll",
        525,
        1,
        7,
        0,
        "using explicit challenge len=%zd",
        v33);
      goto LABEL_18;
    }
    v23 = 0;
    v28 = "Missing enrollment challenge";
    v24 = 519;
LABEL_23:
    v14 = 0;
    sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_enroll", v24, v23, 2, 0, v28);
    v20 = 0;
    goto LABEL_24;
  }
  sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_enroll", 514, 1, 5, 0, "using random challenge");
  sub_38B20(dest);
  v33 = 32;
  v32 = dest;
LABEL_18:
  v19 = sub_8920(a2);
  v20 = (void **)v18;
  if ( v18 )
  {
    v21 = (*(long long (**)(long long, char *, long long, const char *, long long, char *, double, void ***, void **))(v18 + 24))(
            v17,
            v32,
            v33,
            a4,
            a6,
            a7,
            v19,
            ptr,
            &v35);
    if ( v21 )
    {
      v14 = 0;
      sub_203A0(
        (unsigned int)"ssh-sk.c",
        (unsigned int)"sshsk_enroll",
        535,
        1,
        5,
        0,
        "provider \"%s\" failure %d",
        a2,
        v21);
      sub_8500();
    }
    else
    {
      sub_9D20(v17, a4, *(char *)v35, v35, &v34, v19);
      if ( v22 )
      {
        v14 = v34;
      }
      else
      {
        sub_85A0(v35, a10);
        v14 = v34;
        if ( !v27 )
        {
          *a9 = v34;
          v14 = 0;
        }
      }
    }
  }
  else
  {
    v14 = 0;
  }
LABEL_24:
  sub_8790(ptr);
  sub_8870(v20);
  sub_10A60(v14);
  v25 = sub_8D30((void **)v35);
  __explicit_bzero_chk(dest, 32, 32, v25);
  return 0.0;
}


// Function: sshsk_sign @ 0xa4d0
double sshsk_sign(
        void **file,
        unsigned int *a2,
        void **a3,
        long long *a4,
        long long a5,
        long long a6,
        int a7,
        char *a8)
{
  void **v9; // r12
  const char *v10; // rbx
  int v11; // r15d
  const char *v12; // rax
  int v13; // eax
  int v14; // ebx
  char *v15; // r10
  long long v17; // rax
  double v18; // xmm0_8
  long long v19; // rax
  int v20; // eax
  long long v21; // rdx
  long long v22; // rax
  long long v23; // rsi
  unsigned int v24; // eax
  long long v25; // rdx
  long long v26; // rcx
  long long v27; // r8
  long long v28; // r9
  int v29; // eax
  size_t v30; // rax
  void *v31; // rax
  size_t v32; // r14
  const void *v33; // rax
  long long *v34; // rbx
  long long v35; // rax
  int v36; // eax
  int v37; // eax
  void *v39; // [rsp+0h] [rbp-78h]
  char *v40; // [rsp+0h] [rbp-78h]
  long long v42; // [rsp+8h] [rbp-70h]
  char *v43; // [rsp+8h] [rbp-70h]
  long long v45; // [rsp+18h] [rbp-60h]
  unsigned int v46; // [rsp+20h] [rbp-58h]
  unsigned int v47; // [rsp+24h] [rbp-54h]
  long long (*v48)(long long, long long, long long, long long, long long, long long, double, long long, char *, long long, void **); // [rsp+28h] [rbp-50h]
  void *ptr[9]; // [rsp+30h] [rbp-48h] BYREF

  v9 = file;
  v10 = "";
  ptr[1] = (void *)__readfsqword(0x28u);
  ptr[0] = 0;
  if ( a8 && *a8 )
    v10 = " with-pin";
  v11 = *((unsigned char *)a2 + 104);
  v12 = (const char *)sub_E880(a2);
  sub_203A0(
    (unsigned int)"ssh-sk.c",
    (unsigned int)"sshsk_sign",
    646,
    1,
    5,
    0,
    "provider \"%s\", key %s, flags 0x%02x%s",
    (const char *)file,
    v12,
    v11,
    v10);
  if ( a3 )
    *a3 = 0;
  if ( a4 )
    *a4 = 0;
  v13 = sub_F440(*a2);
  v14 = v13;
  if ( v13 == 10 )
  {
    v46 = 0;
    if ( file )
      goto LABEL_11;
    goto LABEL_18;
  }
  if ( v13 == 12 )
  {
    v46 = 1;
    if ( file )
    {
LABEL_11:
      v15 = (char *)*((long long *)a2 + 14);
      if ( v15 && (v15 = (char *)*((long long *)a2 + 12)) != 0 )
      {
        if ( *v15 )
        {
          v18 = sub_8920((char *)file);
          v9 = (void **)v17;
          if ( v17 )
          {
            v48 = *(long long (**)(long long, long long, long long, long long, long long, long long, double, long long, char *, long long, void **))(v17 + 32);
            v47 = *((unsigned char *)a2 + 104);
            v45 = sub_C3D0(*((long long *)a2 + 14));
            v19 = sub_C520(*((long long *)a2 + 14));
            v20 = v48(v46, a5, a6, *((long long *)a2 + 12), v19, v45, v18, v47, a8, 0, ptr);
            if ( v20 )
            {
              sub_203A0(
                (unsigned int)"ssh-sk.c",
                (unsigned int)"sshsk_sign",
                686,
                1,
                5,
                0,
                "sk_sign failed with code %d",
                v20);
              sub_8500();
              v15 = 0;
            }
            else
            {
              v22 = sub_B880(v46, a5, v21, v18);
              v15 = (char *)v22;
              if ( v22 )
              {
                v42 = v22;
                v23 = sub_F8B0(a2);
                v24 = sub_1B800(v42, v23);
                v15 = (char *)v42;
                if ( !v24 )
                {
                  if ( v14 == 10 )
                  {
                    sub_9160((unsigned char *)ptr[0], v42, v25, v18);
                    v15 = (char *)v42;
                    if ( v37 )
                      goto LABEL_15;
                  }
                  else if ( v14 == 12 )
                  {
                    sub_9360((unsigned char *)ptr[0], v42);
                    v15 = (char *)v42;
                    if ( v29 )
                      goto LABEL_15;
                  }
                  if ( a3 )
                  {
                    v43 = v15;
                    v30 = sub_C3D0(v15);
                    v31 = malloc(v30);
                    v15 = v43;
                    *a3 = v31;
                    if ( !v31 )
                      goto LABEL_15;
                    v32 = sub_C3D0(v43);
                    v33 = (const void *)sub_C520(v43);
                    memcpy(*a3, v33, v32);
                    v15 = v43;
                  }
                  v34 = a4;
                  if ( a4 )
                  {
                    v40 = v15;
                    v35 = sub_C3D0(v15);
                    v15 = v40;
                    *v34 = v35;
                  }
                  goto LABEL_15;
                }
                v36 = sub_B050(v24, v23, v25, v26, v27, v28);
                sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_sign", 696, 1, 2, v36, "compose outer");
                v15 = (char *)v42;
              }
            }
          }
          else
          {
            v15 = 0;
          }
        }
        else
        {
          v15 = 0;
          v9 = 0;
        }
      }
      else
      {
        v9 = 0;
      }
LABEL_15:
      v39 = v15;
      sub_8790(0);
      sub_8870(v9);
      sub_8E10((void **)ptr[0]);
      sub_BCE0(v39);
      sub_BCE0(0);
      return 0.0;
    }
LABEL_18:
    v15 = 0;
    goto LABEL_15;
  }
  return 0.0;
}


// Function: sshsk_free_resident_keys @ 0xa990
double sshsk_free_resident_keys(long long *ptr, unsigned long long a2)
{
  unsigned long long i; // rbx
  void **v4; // rdi
  double result; // xmm0_8

  if ( !ptr )
    return 0.0;
  if ( !a2 )
    return 0.0;
  for ( i = 0; i < a2; ++i )
  {
    v4 = (void **)ptr[i];
    result = sub_8ED0(v4);
  }
  free(ptr);
  return result;
}


// Function: sshsk_load_resident @ 0xaae0
double sshsk_load_resident(char *file, long long a2, char *a3, long long a4, long long *a5, unsigned long long *a6)
{
  const char *v7; // rax
  void *v8; // r10
  void **v9; // r15
  unsigned long long v10; // r12
  long long v12; // rax
  double v13; // xmm0_8
  unsigned long long v14; // r12
  long long v15; // rbx
  long long v16; // r12
  const char *v17; // r15
  int v18; // eax
  void **v19; // rax
  void *v20; // rax
  char *v21; // rbp
  long long v22; // rdi
  char *v23; // rax
  long long *v24; // rcx
  void *v25; // [rsp+0h] [rbp-A8h]
  char *v26; // [rsp+0h] [rbp-A8h]
  void *v27; // [rsp+0h] [rbp-A8h]
  long long *src; // [rsp+8h] [rbp-A0h]
  int v29; // [rsp+1Ch] [rbp-8Ch]
  void **v32; // [rsp+30h] [rbp-78h]
  void ***ptr; // [rsp+38h] [rbp-70h]
  void *v34; // [rsp+48h] [rbp-60h] BYREF
  unsigned long long v35; // [rsp+50h] [rbp-58h] BYREF
  void *v36; // [rsp+58h] [rbp-50h] BYREF
  long long v37[9]; // [rsp+60h] [rbp-48h] BYREF

  v37[1] = __readfsqword(0x28u);
  v7 = "";
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37[0] = 0;
  if ( a3 && *a3 )
    v7 = ", have-pin";
  sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_load_resident", 797, 1, 5, 0, "provider \"%s\"%s", file, v7);
  if ( !a5 || !a6 )
    return 0.0;
  *a5 = 0;
  *a6 = 0;
  if ( (unsigned int)sub_96F0(a2, 0, v37) )
  {
    v8 = 0;
    v9 = 0;
    v10 = 0;
    src = 0;
    ptr = (void ***)v37[0];
    v32 = 0;
    goto LABEL_8;
  }
  v13 = sub_8920(file);
  v32 = (void **)v12;
  ptr = (void ***)v37[0];
  if ( !v12 )
  {
    src = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    goto LABEL_8;
  }
  v29 = (*(long long (**)(char *, long long, void **, unsigned long long *, double))(v12 + 40))(
          a3,
          v37[0],
          &v34,
          &v35,
          v13);
  if ( v29 )
  {
    v10 = 0;
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_load_resident",
      812,
      0,
      2,
      0,
      "Provider \"%s\" returned failure %d",
      file,
      v29);
    v9 = 0;
    sub_8500();
    v8 = 0;
    src = 0;
    goto LABEL_8;
  }
  v14 = v35;
  if ( !v35 )
  {
    src = 0;
    v8 = 0;
LABEL_23:
    v24 = src;
    v9 = 0;
    src = 0;
    *a5 = v24;
    *a6 = v14;
    v10 = 0;
    goto LABEL_8;
  }
  v15 = 0;
  src = 0;
  v26 = 0;
  while ( 1 )
  {
    sub_203A0(
      (unsigned int)"ssh-sk.c",
      (unsigned int)"sshsk_load_resident",
      817,
      1,
      7,
      0,
      "rk %zu: slot %zu, alg %d, app \"%s\", uidlen %zu",
      v15,
      *(long long *)(*((long long *)v34 + v15) + 8LL),
      **((int **)v34 + v15),
      *(const char **)(*((long long *)v34 + v15) + 16LL),
      *(long long *)(*((long long *)v34 + v15) + 128LL));
    v16 = *((long long *)v34 + v15);
    v17 = *(const char **)(v16 + 16);
    if ( strncmp(v17, "ssh:", 4u) || *(int *)v16 > 1u )
      goto LABEL_21;
    v13 = sub_9D20(*(int *)v16, v17, (*(char *)(v16 + 112) & 4) == 0 ? 33 : 37, (long long *)(v16 + 24), &v36, v13);
    if ( v18 )
    {
      v10 = (unsigned long long)v26;
      v8 = v36;
      v9 = 0;
      goto LABEL_8;
    }
    v19 = (void **)calloc(1u, 0x18u);
    v9 = v19;
    if ( !v19 )
    {
      v10 = (unsigned long long)v26;
      v27 = v36;
      sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_load_resident", 837, 1, 2, 0, "calloc failed", v13);
      goto LABEL_28;
    }
    *v19 = v36;
    v36 = 0;
    v20 = calloc(1u, *(long long *)(*((long long *)v34 + v15) + 128LL));
    v9[1] = v20;
    if ( !v20 )
      break;
    v21 = (char *)v34 + 8 * v15;
    memcpy(v20, *(const void **)(*(long long *)v21 + 120LL), *(long long *)(*(long long *)v21 + 128LL));
    v9[2] = *(void **)(*(long long *)v21 + 128LL);
    v22 = sub_3BA50(src);
    if ( !v22 )
    {
      v10 = (unsigned long long)v26;
      v27 = 0;
      sub_203A0(
        (unsigned int)"ssh-sk.c",
        (unsigned int)"sshsk_load_resident",
        852,
        1,
        2,
        0,
        "recallocarray failed",
        v13);
      goto LABEL_28;
    }
    v23 = v26;
    src = (long long *)v22;
    ++v26;
    *(long long *)(v22 + 8LL * (long long)v23) = v9;
LABEL_21:
    if ( v35 <= ++v15 )
    {
      v14 = (unsigned long long)v26;
      v8 = v36;
      goto LABEL_23;
    }
  }
  v10 = (unsigned long long)v26;
  v27 = 0;
  sub_203A0((unsigned int)"ssh-sk.c", (unsigned int)"sshsk_load_resident", 844, 1, 2, 0, "calloc failed", v13);
LABEL_28:
  v8 = v27;
LABEL_8:
  v25 = v8;
  sub_8790(ptr);
  sub_8870(v32);
  sub_8F80((long long *)v34, v35);
  sub_10A60(v25);
  sub_8ED0(v9);
  sub_A990(src, v10);
  return 0.0;
}


// Function: ssh_err @ 0xb050
char *ssh_err(long long a1)
{
  char *result; // rax
  int *v2; // rax

  switch ( (unsigned int)sub_3DA20(a1, 60) )
  {
    case 0u:
      result = "device not found";
      break;
    case 1u:
      result = "requested feature not supported";
      break;
    case 2u:
      result = "signature algorithm not supported";
      break;
    case 3u:
      result = "number is too large";
      break;
    case 4u:
      result = "Invalid key length";
      break;
    case 5u:
      result = "Protocol error";
      break;
    case 6u:
      result = "Connection corrupted";
      break;
    case 7u:
      result = "Connection timed out";
      break;
    case 8u:
      result = "Connection closed";
      break;
    case 9u:
      result = "Key is revoked";
      break;
    case 0xAu:
      result = "KRL file has invalid magic number";
      break;
    case 0xBu:
      result = "internal error: buffer is read-only";
      break;
    case 0xCu:
      result = "agent contains no identities";
      break;
    case 0xDu:
      result = "agent not present";
      break;
    case 0xEu:
      result = "key not found";
      break;
    case 0xFu:
      result = "certificate does not match key";
      break;
    case 0x10u:
      result = "bad permissions";
      break;
    case 0x11u:
      result = "incorrect passphrase supplied to decrypt private key";
      break;
    case 0x12u:
      result = "key encrypted using unsupported cipher";
      break;
    case 0x13u:
      result = "file changed while reading";
      break;
    case 0x14u:
      result = "passphrase is too short (minimum five characters)";
      break;
    case 0x15u:
      result = "rekeying not supported by peer";
      break;
    case 0x16u:
      result = "could not read protocol version";
      break;
    case 0x17u:
      result = "protocol version mismatch";
      break;
    case 0x18u:
      result = "could not load host key";
      break;
    case 0x19u:
      result = "no matching host key type found";
      break;
    case 0x1Au:
      result = "no matching key exchange method found";
      break;
    case 0x1Bu:
      result = "no matching compression method found";
      break;
    case 0x1Cu:
      result = "no matching MAC found";
      break;
    case 0x1Du:
      result = "no matching cipher found";
      break;
    case 0x1Eu:
      result = "message authentication code incorrect";
      break;
    case 0x1Fu:
      result = "disconnected";
      break;
    case 0x20u:
      result = "DH GEX group out of range";
      break;
    case 0x21u:
      result = "agent refused operation";
      break;
    case 0x22u:
      result = "communication with agent failed";
      break;
    case 0x23u:
      result = "invalid certificate";
      break;
    case 0x24u:
      v2 = __errno_location();
      result = strerror(*v2);
      break;
    case 0x25u:
      result = "unexpected bytes remain after decoding";
      break;
    case 0x26u:
      result = "error in libcrypto";
      break;
    case 0x27u:
      result = "incorrect signature";
      break;
    case 0x28u:
      result = "invalid elliptic curve value";
      break;
    case 0x29u:
      result = "invalid certificate signing key";
      break;
    case 0x2Au:
      result = "unknown/unsupported certificate type";
      break;
    case 0x2Bu:
      result = "key lacks certificate data";
      break;
    case 0x2Cu:
      result = "plain key provided where certificate required";
      break;
    case 0x2Du:
      result = "elliptic curve does not match";
      break;
    case 0x2Eu:
      result = "unknown or unsupported key type";
      break;
    case 0x2Fu:
      result = "key type does not match";
      break;
    case 0x30u:
      result = "invalid elliptic curve";
      break;
    case 0x31u:
      result = "key bits do not match";
      break;
    case 0x32u:
      result = "invalid argument";
      break;
    case 0x33u:
      result = "insufficient buffer space";
      break;
    case 0x34u:
      result = "elliptic curve point is too large";
      break;
    case 0x35u:
      result = "bignum is too large";
      break;
    case 0x36u:
      result = "string is too large";
      break;
    case 0x37u:
      result = "bignum is negative";
      break;
    case 0x38u:
      result = "invalid format";
      break;
    case 0x39u:
      result = "incomplete message";
      break;
    case 0x3Au:
      result = "memory allocation failed";
      break;
    case 0x3Bu:
      result = "unexpected internal error";
      break;
    case 0x3Cu:
      result = "success";
      break;
    default:
      result = "unknown error";
      break;
  }
  return result;
}


// Function: sshbuf_check_sanity @ 0xb4e0
double sshbuf_check_sanity(long long a1)
{
  unsigned long long v2; // rax
  unsigned long long v3; // rdx
  unsigned long long v4; // rax

  if ( a1
    && (*(int *)(a1 + 48) || *(long long *)a1 == *(long long *)(a1 + 8))
    && (unsigned int)(*(int *)(a1 + 56) - 1) <= 0xFFFFF )
  {
    if ( *(long long *)(a1 + 8) )
    {
      v2 = *(long long *)(a1 + 32);
      if ( v2 <= 0x8000000 )
      {
        v3 = *(long long *)(a1 + 40);
        if ( v2 >= v3 )
        {
          v4 = *(long long *)(a1 + 24);
          if ( v3 >= v4 && v4 >= *(long long *)(a1 + 16) )
            return 0.0;
        }
      }
    }
  }
  sub_2AD90(11);
  raise(11);
  return 0.0;
}


// Function: sshbuf_maybe_pack @ 0xb680
double sshbuf_maybe_pack(long long a1, int a2)
{
  unsigned long long v2; // rax
  unsigned long long v3; // rdx

  v2 = *(long long *)(a1 + 16);
  if ( !v2 )
    return 0.0;
  if ( *(int *)(a1 + 48) || *(int *)(a1 + 56) > 1u )
    return 0.0;
  if ( a2 )
  {
    v3 = *(long long *)(a1 + 24);
  }
  else
  {
    if ( v2 <= 0x1FFF )
      return 0.0;
    v3 = *(long long *)(a1 + 24);
    if ( v2 < v3 >> 1 )
      return 0.0;
  }
  memmove(*(void **)a1, (const void *)(*(long long *)a1 + v2), v3 - v2);
  *(long long *)(a1 + 24) -= *(long long *)(a1 + 16);
  *(long long *)(a1 + 16) = 0;
  return 0.0;
}


// Function: sshbuf_new @ 0xb880
double sshbuf_new()
{
  long long *v0; // rax
  long long *v1; // r12
  void *v2; // rax

  v0 = calloc(0x48u, 1u);
  v1 = v0;
  if ( v0 )
  {
    v0[5] = 256;
    v0[4] = 0x8000000;
    *((int *)v0 + 12) = 0;
    *((int *)v0 + 14) = 1;
    v0[8] = 0;
    v2 = calloc(1u, 0x100u);
    *v1 = v2;
    v1[1] = v2;
    if ( !v2 )
      free(v1);
  }
  return 0.0;
}


// Function: sshbuf_from @ 0xb980
double sshbuf_from(long long a1, unsigned long long a2)
{
  long long *v2; // rax

  if ( !a1 )
    return 0.0;
  if ( a2 > 0x8000000 )
    return 0.0;
  v2 = calloc(0x48u, 1u);
  if ( v2 )
  {
    v2[4] = a2;
    v2[3] = a2;
    v2[5] = a2;
    *((int *)v2 + 12) = 1;
    *((int *)v2 + 14) = 1;
    v2[8] = 0;
    v2[1] = a1;
    *v2 = 0;
  }
  return 0.0;
}


// Function: sshbuf_set_parent @ 0xbb80
double sshbuf_set_parent(long long a1, long long a2)
{
  int v2; // eax
  int v4; // eax
  long long v5; // rdx

  sub_B4E0(a1);
  if ( v2 )
    return 0.0;
  sub_B4E0(a2);
  if ( v4 )
    return 0.0;
  v5 = *(long long *)(a1 + 64);
  if ( v5 )
  {
    if ( v5 != a2 )
      return 0.0;
  }
  *(long long *)(a1 + 64) = a2;
  ++*(int *)(a2 + 56);
  return 0.0;
}


// Function: sshbuf_free @ 0xbce0
double sshbuf_free(long long *ptr)
{
  double result; // xmm0_8
  int v2; // eax
  int v4; // eax

  if ( !ptr )
    return 0.0;
  result = sub_B4E0((long long)ptr);
  if ( v2 )
    return 0.0;
  if ( (*((int *)ptr + 14))-- != 1 )
    return 0.0;
  sshbuf_free((void *)ptr[8]);
  v4 = *((int *)ptr + 12);
  ptr[8] = 0;
  if ( !v4 )
  {
    __explicit_bzero_chk(*ptr, ptr[5], -1, result);
    free((void *)*ptr);
  }
  sub_3B0D0(ptr);
  return result;
}


// Function: sshbuf_reset @ 0xbe60
long long sshbuf_reset(long long a1)
{
  double v3; // xmm0_8
  int v4; // eax
  long long v5; // rsi
  void *v6; // rdi
  long long v7; // rax

  if ( *(int *)(a1 + 48) || *(int *)(a1 + 56) > 1u )
  {
    *(long long *)(a1 + 16) = *(long long *)(a1 + 24);
    return 0;
  }
  v3 = sub_B4E0(a1);
  if ( v4 )
    return 0;
  v5 = *(long long *)(a1 + 40);
  v6 = *(void **)a1;
  *(long long *)(a1 + 24) = 0;
  *(long long *)(a1 + 16) = 0;
  if ( v5 != 256 )
  {
    v7 = sub_3BA50(v6);
    v6 = (void *)v7;
    if ( v7 )
    {
      *(long long *)a1 = v7;
      v5 = 256;
      *(long long *)(a1 + 8) = v7;
      *(long long *)(a1 + 40) = 256;
    }
    else
    {
      v5 = *(long long *)(a1 + 40);
      v6 = *(void **)a1;
    }
  }
  return __explicit_bzero_chk(v6, v5, -1, v3);
}


// Function: sshbuf_max_size @ 0xbf80
double sshbuf_max_size()
{
  return 0.0;
}


// Function: sshbuf_set_max_size @ 0xc1c0
double sshbuf_set_max_size(long long a1, unsigned long long a2)
{
  int v3; // eax
  unsigned long long v4; // rax
  void *v5; // rdi
  unsigned long long v6; // r13
  long long v7; // rax

  sub_B4E0(a1);
  if ( v3 || *(long long *)(a1 + 32) == a2 || *(int *)(a1 + 48) || *(int *)(a1 + 56) > 1u )
    return 0.0;
  if ( a2 <= 0x8000000 )
  {
    sub_B680(a1, *(long long *)(a1 + 24) > a2);
    if ( *(long long *)(a1 + 40) <= a2 )
      goto LABEL_14;
    v4 = *(long long *)(a1 + 24);
    if ( v4 < a2 )
    {
      v6 = v4 + 255;
      v5 = *(void **)a1;
      LOBYTE(v6) = 0;
      if ( v4 <= 0xFF )
        v6 = 256;
      if ( v6 > a2 )
        v6 = a2;
      v7 = sub_3BA50(v5);
      if ( !v7 )
        return 0.0;
      *(long long *)a1 = v7;
      *(long long *)(a1 + 8) = v7;
      *(long long *)(a1 + 40) = v6;
      if ( v6 <= a2 )
      {
LABEL_14:
        *(long long *)(a1 + 32) = a2;
        return 0.0;
      }
    }
  }
  return 0.0;
}


// Function: sshbuf_len @ 0xc3d0
double sshbuf_len(long long a1)
{
  sub_B4E0(a1);
  return 0.0;
}


// Function: sshbuf_ptr @ 0xc520
double sshbuf_ptr(long long a1)
{
  sub_B4E0(a1);
  return 0.0;
}


// Function: sshbuf_fromb @ 0xc640
double sshbuf_fromb(long long a1)
{
  int v1; // eax
  unsigned long long v2; // rax
  unsigned long long v3; // r12
  long long v4; // rax
  long long v5; // rax
  long long *v6; // r12
  int v7; // eax

  sub_B4E0(a1);
  if ( !v1 )
  {
    sub_C3D0(a1);
    v3 = v2;
    sub_C520(a1);
    sub_B980(v4, v3);
    v6 = (long long *)v5;
    if ( v5 )
    {
      sub_BB80(v5, a1);
      if ( !v7 )
        return 0.0;
      sub_BCE0(v6);
    }
  }
  return 0.0;
}


// Function: sshbuf_mutable_ptr @ 0xc7c0
double sshbuf_mutable_ptr(long long a1)
{
  sub_B4E0(a1);
  return 0.0;
}


// Function: sshbuf_check_reserve @ 0xc870
double sshbuf_check_reserve(long long a1)
{
  sub_B4E0(a1);
  return 0.0;
}


// Function: sshbuf_allocate @ 0xc960
double sshbuf_allocate(long long *a1, long long a2)
{
  int v3; // eax
  unsigned long long v5; // rax
  void *v6; // rdi
  unsigned long long v7; // r12
  long long v8; // rax

  sub_C870((long long)a1);
  if ( v3 )
    return 0.0;
  sub_B680((long long)a1, a2 + a1[3] > (unsigned long long)a1[4]);
  v5 = a2 + a1[3];
  if ( v5 <= a1[5] )
    return 0.0;
  v7 = v5 + 255;
  v6 = (void *)*a1;
  LOBYTE(v7) = 0;
  if ( a1[4] < v7 )
    v7 = a2 + a1[3];
  v8 = sub_3BA50(v6);
  if ( !v8 )
    return 0.0;
  a1[5] = v7;
  *a1 = v8;
  a1[1] = v8;
  sub_C870((long long)a1);
  return 0.0;
}


// Function: sshbuf_reserve @ 0xcb20
double sshbuf_reserve(long long *a1, long long a2, long long *a3)
{
  int v4; // eax
  long long v5; // rdx
  long long v6; // rcx
  int v8; // eax

  if ( a3 )
  {
    *a3 = 0;
    sub_C960(a1, a2);
    if ( !v4 )
    {
      v5 = a1[3];
      v6 = v5 + *a1;
      a1[3] = v5 + a2;
      *a3 = v6;
    }
    return 0.0;
  }
  sub_C960(a1, a2);
  if ( v8 )
    return 0.0;
  a1[3] += a2;
  return 0.0;
}


// Function: sshbuf_consume @ 0xcc80
double sshbuf_consume(long long a1, unsigned long long a2)
{
  int v2; // eax
  unsigned long long v4; // rax
  unsigned long long v5; // rbp

  sub_B4E0(a1);
  if ( v2 )
    return 0.0;
  if ( !a2 )
    return 0.0;
  sub_C3D0(a1);
  if ( v4 < a2 )
    return 0.0;
  v5 = *(long long *)(a1 + 16) + a2;
  *(long long *)(a1 + 16) = v5;
  if ( v5 != *(long long *)(a1 + 24) )
    return 0.0;
  *(long long *)(a1 + 24) = 0;
  *(long long *)(a1 + 16) = 0;
  return 0.0;
}


// Function: sshbuf_consume_end @ 0xce00
double sshbuf_consume_end(long long a1, unsigned long long a2)
{
  int v2; // eax
  unsigned long long v4; // rax

  sub_B4E0(a1);
  if ( v2 )
    return 0.0;
  if ( !a2 )
    return 0.0;
  sub_C3D0(a1);
  if ( v4 < a2 )
    return 0.0;
  *(long long *)(a1 + 24) -= a2;
  return 0.0;
}


// Function: sshkey_ssh_name_from_type_nid @ 0xd0a0
double sshkey_ssh_name_from_type_nid(int a1, int a2)
{
  char **v2; // rax
  int v3; // edx
  int v4; // edx

  v2 = off_66CC0;
  v3 = 3;
  do
  {
    if ( a1 == v3 )
    {
      v4 = *((int *)v2 + 7);
      if ( v4 == a2 || !v4 )
        return 0.0;
    }
    v3 = *((int *)v2 + 16);
    v2 += 5;
  }
  while ( v3 != -1 );
  return 0.0;
}


// Function: key_type_is_ecdsa_variant @ 0xd1e0
double key_type_is_ecdsa_variant()
{
  return 0.0;
}


// Function: sshkey_type_is_valid_ca @ 0xd300
double sshkey_type_is_valid_ca()
{
  return 0.0;
}


// Function: translate_libcrypto_error @ 0xd420
double translate_libcrypto_error(long long a1)
{
  int v1; // ebx
  int v2; // eax

  v1 = sub_D000();
  v2 = sub_CF60(a1);
  if ( v2 == 9 )
  {
    if ( (unsigned int)(v1 - 101) <= 8 )
      return 0.0;
    return 0.0;
  }
  if ( v2 != 6 || v1 == 114 || v1 == 145 )
    return 0.0;
  return 0.0;
}


// Function: pem_passphrase_cb @ 0xd650
double pem_passphrase_cb(void *dest, int a2, long long a3, const char *a4)
{
  unsigned long long v5; // rax

  if ( !a4 )
    return 0.0;
  v5 = strlen(a4);
  if ( a2 >= 0 && v5 && a2 >= v5 )
    memcpy(dest, a4, v5);
  return 0.0;
}


// Function: fingerprint_bubblebabble @ 0xd7c0
double fingerprint_bubblebabble(long long a1, unsigned long long a2)
{
  int v3; // r12d
  unsigned int v4; // ebx
  char *v5; // rax
  char *v6; // r8
  unsigned int v7; // r14d
  unsigned int v8; // r13d
  unsigned int v9; // eax
  unsigned int v10; // r11d
  unsigned int v11; // edx
  int v12; // edi
  long long v13; // r9
  long long v14; // rcx
  long long v15; // r9
  long long v16; // rsi
  long long v17; // rdx
  long long v18; // rax
  long long v20; // [rsp+8h] [rbp-70h]
  char v21[6]; // [rsp+1Ah] [rbp-5Eh] BYREF
  __m128i si128; // [rsp+20h] [rbp-58h]
  char v23; // [rsp+30h] [rbp-48h]
  unsigned long long v24; // [rsp+38h] [rbp-40h]

  v3 = a2 >> 1;
  v4 = v3 + 1;
  v24 = __readfsqword(0x28u);
  qmemcpy(v21, "aeiouy", sizeof(v21));
  v23 = 120;
  si128 = _mm_load_si128((const __m128i *)&xmmword_3F920);
  v5 = calloc((unsigned int)(v3 + 1), 6u);
  v6 = v5;
  if ( v5 )
  {
    *v5 = 120;
    if ( (unsigned int)(a2 >> 1) == -1 )
    {
      v18 = 2;
      v17 = 1;
    }
    else
    {
      v7 = 0;
      v8 = 1;
      v9 = 1;
      v10 = 1;
      v20 = a2 & 1;
      v11 = 1;
      if ( v4 <= 1 )
        goto LABEL_6;
      while ( 1 )
      {
        v12 = *(unsigned char *)(a1 + v8 - 1);
        v6[v11] = v21[((*(char *)(a1 + v8 - 1) >> 6) + v9) % 6];
        v13 = v11 + 3;
        v6[v11 + 1] = si128.m128i_i8[((unsigned char)v12 >> 2) & 0xF];
        v6[v11 + 2] = v21[((v12 & 3) + v9 / 6) % 6];
        if ( v3 == v7 )
          break;
        v14 = v8;
        v7 = v10;
        v8 += 2;
        LODWORD(v14) = *(unsigned char *)(a1 + v14);
        ++v10;
        v6[v13] = si128.m128i_i8[(unsigned char)v14 >> 4];
        v15 = v11 + 4;
        v16 = v11 + 5;
        v11 += 6;
        v6[v15] = 45;
        v6[v16] = si128.m128i_i8[v14 & 0xF];
        v9 = ((unsigned int)v14 + 5 * v9 + 8 * v12 - v12) % 0x24;
        if ( v10 >= v4 )
        {
LABEL_6:
          if ( !v20 )
          {
            LODWORD(v13) = v11 + 3;
            v6[v11] = v21[v9 % 6];
            v6[v11 + 1] = 120;
            v6[v11 + 2] = v21[v9 / 6];
            break;
          }
        }
      }
      v17 = (unsigned int)v13;
      v18 = (unsigned int)(v13 + 1);
    }
    v6[v17] = 120;
    v6[v18] = 0;
  }
  return 0.0;
}


// Function: cert_compare @ 0xda80
double cert_compare(__int128 a1)
{
  long long v1; // rax
  long long v2; // r12
  long long v3; // rax
  long long v5; // rax
  long long v6; // r12
  long long v7; // rax
  long long v8; // rbp
  double v9; // xmm0_8
  long long v10; // rax

  if ( a1 == 0 )
    return 0.0;
  if ( !(long long)a1 )
    return 0.0;
  if ( !*((long long *)&a1 + 1) )
    return 0.0;
  sub_C3D0(*(long long *)a1);
  v2 = v1;
  sub_C3D0(**((long long **)&a1 + 1));
  if ( v2 != v3 )
    return 0.0;
  sub_C3D0(*(long long *)a1);
  v6 = v5;
  sub_C520(**((long long **)&a1 + 1));
  v8 = v7;
  v9 = sub_C520(*(long long *)a1);
  sub_3C1C0(v10, v8, v6, v9);
  return 0.0;
}


// Function: fingerprint_hex @ 0xdc80
double fingerprint_hex(const char *a1, long long a2, unsigned long long a3)
{
  size_t v4; // rax
  size_t v5; // r14
  void *v6; // rax
  void *v7; // r12
  long long v8; // rbx
  const char *v9; // r9
  char v11[5]; // [rsp+3h] [rbp-45h] BYREF
  unsigned long long v12; // [rsp+8h] [rbp-40h]

  v12 = __readfsqword(0x28u);
  v4 = strlen(a1);
  if ( a3 <= (unsigned long long)&loc_10000 )
  {
    v5 = v4 + 3 * a3 + 2;
    v6 = calloc(1u, v5);
    v7 = v6;
    if ( v6 )
    {
      sub_3BEE0(v6, a1, v5);
      sub_3BCF0(v7, ":", v5);
      if ( a3 )
      {
        v8 = a2 + 1;
        v9 = "";
        while ( 1 )
        {
          __snprintf_chk(v11, 5, 1, 5, "%s%02x", v9);
          sub_3BCF0(v7, v11, v5);
          if ( v8 == a3 + a2 )
            break;
          v9 = ":";
          ++v8;
        }
      }
    }
  }
  return 0.0;
}


// Function: fingerprint_b64 @ 0xde20
double fingerprint_b64(const char *a1, long long a2, unsigned long long a3)
{
  size_t v4; // rax
  size_t v5; // rbx
  unsigned long long v6; // r15
  char *v7; // rax
  char *v8; // r12
  size_t v10; // [rsp+8h] [rbp-40h]

  v4 = strlen(a1);
  if ( a3 <= (unsigned long long)&loc_10000 )
  {
    v5 = v4;
    v10 = v4 + 1;
    v6 = v4 + 1 + 4 * ((a3 + 2) / 3);
    v7 = (char *)calloc(1u, v6 + 1);
    v8 = v7;
    if ( v7 )
    {
      sub_3BEE0(v7, a1, v6 + 1);
      sub_3BCF0(v8, ":", v6 + 1);
      if ( a3 )
      {
        if ( (unsigned int)sub_38B30(a2, a3, &v8[v10], v6 - v5) == -1 )
          sub_3B0D0(v8);
        else
          v8[strcspn(v8, "=")] = 0;
      }
    }
  }
  return 0.0;
}


// Function: dsa_generate_private_key @ 0xdfa0
double dsa_generate_private_key(int a1, long long *a2)
{
  long long v2; // rax
  long long v3; // rbp

  if ( a1 == 1024 )
  {
    v2 = DSA_new();
    v3 = v2;
    if ( v2 )
    {
      *a2 = 0;
      if ( (unsigned int)DSA_generate_parameters_ex(v2, 1024, 0, 0, 0, 0, 0) )
      {
        if ( (unsigned int)DSA_generate_key(v3) )
        {
          *a2 = v3;
          v3 = 0;
        }
      }
    }
    DSA_free(v3);
  }
  return 0.0;
}


// Function: rsa_generate_private_key @ 0xe0c0
double rsa_generate_private_key(unsigned int a1, long long *a2)
{
  long long v2; // rbp
  long long v3; // rax
  long long v4; // r12

  if ( a1 - 1024 <= 0x3C00 )
  {
    *a2 = 0;
    v2 = RSA_new();
    if ( v2 )
    {
      v3 = BN_new();
      v4 = v3;
      if ( v3 && (unsigned int)BN_set_word(v3, 65537) && (unsigned int)RSA_generate_key_ex(v2, a1, v4, 0) )
      {
        *a2 = v2;
        v2 = 0;
      }
    }
    else
    {
      v4 = 0;
    }
    RSA_free(v2);
    BN_free(v4);
  }
  return 0.0;
}


// Function: private2_check_padding @ 0xe200
double private2_check_padding(long long a1)
{
  double v1; // xmm0_8
  long long v2; // rax
  char v4; // [rsp+1Fh] [rbp-29h] BYREF
  long long v5[5]; // [rsp+20h] [rbp-28h] BYREF

  v5[1] = __readfsqword(0x28u);
  v5[0] = 0;
  do
  {
    v1 = sub_C3D0(a1);
    if ( !v2 )
      break;
    if ( (unsigned int)sub_19E50(a1, &v4) )
      break;
    ++v5[0];
  }
  while ( v4 == LOBYTE(v5[0]) );
  __explicit_bzero_chk(&v4, 1, 1, v1);
  __explicit_bzero_chk(v5, 8, 8, v1);
  return 0.0;
}


// Function: clear_libcrypto_errors @ 0xe340
double clear_libcrypto_errors()
{
  while ( ERR_get_error() )
    ;
  return 0.0;
}


// Function: convert_libcrypto_error @ 0xe3e0
double convert_libcrypto_error()
{
  long long v0; // rdi
  double v1; // xmm0_8
  int v2; // eax
  long long error; // rax

  v0 = ERR_peek_error();
  v1 = sub_D420(v0);
  if ( v2 == -43 )
    return 0.0;
  error = ERR_peek_last_error(v1);
  return sub_D420(error);
}


// Function: sshkey_type @ 0xe880
double sshkey_type(int *a1)
{
  char **v1; // rax
  int v2; // edx

  v1 = off_66CC0;
  v2 = 3;
  do
  {
    if ( *a1 == v2 )
      return 0.0;
    v2 = *((int *)v1 + 16);
    v1 += 5;
  }
  while ( v2 != -1 );
  return 0.0;
}


// Function: sshkey_type_is_cert @ 0xe9c0
double sshkey_type_is_cert(int a1)
{
  char **v1; // rax
  int v2; // edx

  v1 = off_66CC0;
  v2 = 3;
  do
  {
    if ( a1 == v2 )
      return 0.0;
    v2 = *((int *)v1 + 16);
    v1 += 5;
  }
  while ( v2 != -1 );
  return 0.0;
}


// Function: sshkey_ssh_name @ 0xeaf0
double sshkey_ssh_name(int *a1)
{
  return sub_D0A0(*a1, a1[6]);
}


// Function: sshkey_type_from_name @ 0xeb00
double sshkey_type_from_name(char *s2)
{
  const char *v1; // rsi
  char **i; // rbx
  int v3; // r12d

  v1 = "ssh-ed25519";
  for ( i = off_66CC0; !v1 || strcmp(s2, v1); v1 = *i )
  {
    if ( !*((int *)i + 8) && !strcasecmp(i[1], s2) )
      break;
    v3 = *((int *)i + 16);
    i += 5;
    if ( v3 == -1 )
      break;
  }
  return 0.0;
}


// Function: sshkey_ecdsa_nid_from_name @ 0xebf0
double sshkey_ecdsa_nid_from_name(char *s1)
{
  char **i; // rbx
  int v3; // eax
  int v4; // edi

  for ( i = off_66CC0; ; i += 5 )
  {
    sub_D1E0();
    if ( v3 )
    {
      if ( *i && !strcmp(s1, *i) )
        break;
    }
    v4 = *((int *)i + 16);
    if ( v4 == -1 )
      return 0.0;
  }
  return 0.0;
}


// Function: sshkey_match_keyname_to_sigalgs @ 0xed50
double sshkey_match_keyname_to_sigalgs(char *a1, char *a2)
{
  int v3; // eax
  double v4; // xmm0_8

  if ( !a2 )
    return 0.0;
  if ( !*a2 )
    return 0.0;
  v4 = sub_EB00(a1);
  if ( v3 == 14 )
    return 0.0;
  if ( v3 )
  {
    if ( v3 != 4 )
    {
      sub_20960(a1, a2, 0, v4);
      return 0.0;
    }
    if ( (unsigned int)sub_20960("ssh-rsa-cert-v01@openssh.com", a2, 0, v4) != 1
      && (unsigned int)sub_20960("rsa-sha2-256-cert-v01@openssh.com", a2, 0, v4) != 1 )
    {
      sub_20960("rsa-sha2-512-cert-v01@openssh.com", a2, 0, v4);
      return 0.0;
    }
  }
  else if ( (unsigned int)sub_20960("ssh-rsa", a2, 0, v4) != 1
         && (unsigned int)sub_20960("rsa-sha2-256", a2, 0, v4) != 1 )
  {
    sub_20960("rsa-sha2-512", a2, 0, v4);
    return 0.0;
  }
  return 0.0;
}


// Function: sshkey_alg_list @ 0xf080
double sshkey_alg_list(int a1, int a2, int a3, char a4)
{
  char *v4; // r15
  char **v5; // r14
  size_t v6; // rbp
  const char *i; // rdi
  size_t v8; // rbx
  size_t v9; // rax
  size_t v10; // r12
  char *v11; // rax

  v4 = 0;
  v5 = off_66CC0;
  v6 = 0;
  for ( i = "ssh-ed25519"; ; i = *v5 )
  {
    if ( !i || !a3 && *((int *)v5 + 9) )
      goto LABEL_8;
    if ( a1 )
      break;
    if ( !a2 || !*((int *)v5 + 8) )
      goto LABEL_4;
LABEL_8:
    v5 += 5;
    if ( *((int *)v5 + 6) == -1 )
      return 0.0;
  }
  if ( !*((int *)v5 + 8) || a2 )
    goto LABEL_8;
LABEL_4:
  v8 = v6;
  if ( v4 )
  {
    v8 = v6 + 1;
    v4[v6] = a4;
    i = *v5;
  }
  v9 = strlen(i);
  v6 = v8 + v9;
  v10 = v9;
  v11 = (char *)realloc(v4, v8 + v9 + 2);
  if ( v11 )
  {
    v4 = v11;
    memcpy(&v11[v8], *v5, v10 + 1);
    goto LABEL_8;
  }
  free(v4);
  return 0.0;
}


// Function: sshkey_names_valid2 @ 0xf210
double sshkey_names_valid2(char *s, int a2)
{
  char *v3; // r14
  char *v4; // rax
  char *v5; // r15
  double v6; // xmm0_8
  int v7; // eax
  const char *v8; // rdi
  char **v9; // rbx
  char *v10[9]; // [rsp+0h] [rbp-48h] BYREF

  v10[1] = (char *)__readfsqword(0x28u);
  if ( s )
  {
    if ( strcmp(s, "") )
    {
      v10[0] = strdup(s);
      v3 = v10[0];
      if ( v10[0] )
      {
        while ( 1 )
        {
          v4 = strsep(v10, ",");
          v5 = v4;
          if ( !v4 || !*v4 )
            break;
          v6 = sub_EB00(v4);
          if ( v7 == 14 )
          {
            if ( !a2 )
              break;
            v8 = "ssh-ed25519";
            v9 = off_66CC0;
            while ( !(unsigned int)sub_20960(v8, v5, 0, v6) )
            {
              v9 += 5;
              if ( *((int *)v9 + 6) == -1 )
                goto LABEL_14;
              v8 = *v9;
            }
            if ( *((int *)v9 + 6) == -1 )
              break;
          }
        }
LABEL_14:
        free(v3);
      }
    }
  }
  return 0.0;
}


// Function: sshkey_is_cert @ 0xf3b0
double sshkey_is_cert(int *a1)
{
  if ( a1 )
    return sub_E9C0(*a1);
  else
    return 0.0;
}


// Function: sshkey_type_plain @ 0xf440
double sshkey_type_plain(long long a1)
{
  double result; // xmm0_8

  switch ( (unsigned int)sub_3DA20(a1, 4294967292LL) )
  {
    case 0u:
      result = 0.0;
      break;
    case 1u:
      result = 0.0;
      break;
    case 2u:
      result = 0.0;
      break;
    case 3u:
      result = 0.0;
      break;
    case 5u:
      result = 0.0;
      break;
    case 7u:
      result = 0.0;
      break;
    case 9u:
      result = 0.0;
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}


// Function: sshkey_ssh_name_plain @ 0xf8b0
double sshkey_ssh_name_plain(unsigned int *a1)
{
  int v1; // eax

  sub_F440(*a1);
  return sub_D0A0(v1, a1[6]);
}


// Function: sshkey_is_sk @ 0xf8d0
double sshkey_is_sk(unsigned int *a1)
{
  if ( a1 )
    sub_F440(*a1);
  return 0.0;
}


// Function: sshkey_curve_name_to_nid @ 0xfa00
double sshkey_curve_name_to_nid(char *s1)
{
  if ( strcmp(s1, "nistp256") && strcmp(s1, "nistp384") )
    strcmp(s1, "nistp521");
  return 0.0;
}


// Function: sshkey_curve_nid_to_bits @ 0xfae0
double sshkey_curve_nid_to_bits()
{
  return 0.0;
}


// Function: sshkey_size @ 0xfb90
double sshkey_size(long long a1)
{
  long long v2; // rdi
  long long v3; // rdi
  long long v4[3]; // [rsp+0h] [rbp-18h] BYREF

  v4[1] = __readfsqword(0x28u);
  switch ( *(int *)a1 )
  {
    case 0:
    case 4:
      v3 = *(long long *)(a1 + 8);
      if ( v3 )
      {
        RSA_get0_key(v3, v4, 0, 0);
        BN_num_bits(v4[0]);
      }
      return 0.0;
    case 1:
    case 5:
      v2 = *(long long *)(a1 + 16);
      if ( v2 )
      {
        DSA_get0_pqg(v2, v4, 0, 0);
        BN_num_bits(v4[0]);
      }
      return 0.0;
    case 2:
    case 6:
    case 0xA:
    case 0xB:
      return sub_FAE0();
    default:
      return 0.0;
  }
}


// Function: fingerprint_randomart @ 0xfcf0
double fingerprint_randomart(const char *a1, unsigned char *a2, long long a3, int *a4)
{
  size_t v6; // r13
  size_t v7; // r15
  size_t v8; // rax
  int v9; // r13d
  long long v10; // rsi
  int v11; // eax
  int v12; // ebx
  unsigned char *v13; // r13
  int v14; // ebp
  unsigned int v15; // r12d
  long long v16; // rdi
  int v17; // r15d
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // r8d
  long long v22; // rdx
  int v23; // eax
  long long v24; // rcx
  char *v25; // rax
  size_t v26; // r9
  int v27; // eax
  int *v28; // rbp
  int *v29; // rdi
  double v30; // xmm0_8
  long long v31; // rax
  int v32; // eax
  char *v33; // r12
  size_t v34; // rbx
  int v35; // eax
  size_t v36; // rdx
  size_t v37; // rax
  size_t v38; // r9
  unsigned long long v39; // r10
  char *v40; // rcx
  size_t i; // rax
  int *v42; // r8
  size_t v43; // rdx
  char *v44; // rbx
  size_t v45; // r9
  unsigned char *v46; // r10
  long long v47; // rdi
  unsigned char *v48; // r8
  char *v49; // rsi
  char *v50; // rdx
  unsigned char *v51; // rcx
  size_t v52; // rax
  char *v53; // rcx
  unsigned char *v54; // rax
  unsigned long long v55; // r14
  char *v56; // rax
  char *v57; // rax
  char *v58; // rdx
  int v60; // eax
  const char *v61; // rax
  char v62[8]; // [rsp+0h] [rbp-158h] BYREF
  size_t n; // [rsp+8h] [rbp-150h]
  unsigned char *v64; // [rsp+10h] [rbp-148h]
  char *v65; // [rsp+18h] [rbp-140h]
  int *v66; // [rsp+20h] [rbp-138h]
  unsigned char *v67; // [rsp+28h] [rbp-130h]
  const char *v68; // [rsp+30h] [rbp-128h]
  size_t v69; // [rsp+38h] [rbp-120h]
  char v70[160]; // [rsp+40h] [rbp-118h] BYREF
  char s[32]; // [rsp+E0h] [rbp-78h] BYREF
  char src[24]; // [rsp+100h] [rbp-58h] BYREF
  unsigned long long v73; // [rsp+118h] [rbp-40h]

  v68 = a1;
  v66 = a4;
  v73 = __readfsqword(0x28u);
  v6 = strlen(" .o+=*BOX@%&#/^SE");
  v7 = v6 - 1;
  v65 = calloc(0x14u, 0xBu);
  if ( !v65 )
    return 0.0;
  v67 = v70;
  memset(v70, 0, 153);
  if ( a3 )
  {
    v8 = v6 - 3;
    v69 = v6 - 1;
    v9 = 4;
    n = v8;
    v10 = 8;
    v64 = &a2[a3];
    do
    {
      v11 = v9;
      v12 = *a2;
      v13 = a2;
      v14 = 4;
      v15 = v11;
      do
      {
        v16 = v12 & 1;
        if ( (v12 & 1) == 0 )
          v16 = 0xFFFFFFFFLL;
        v17 = sub_3DA20(v16, v10);
        v18 = sub_3DA20((v12 & 2) == 0 ? -1 : 1, v15);
        v19 = 0;
        if ( v17 < 0 )
          v17 = 0;
        if ( v18 >= 0 )
          v19 = v18;
        v20 = 16;
        if ( v17 <= 16 )
          v20 = v17;
        v21 = v19;
        v22 = v20;
        v23 = 8;
        v10 = v22;
        if ( v21 <= 8 )
          v23 = v21;
        v24 = v23;
        v15 = v23;
        v25 = &v62[9 * v22 + 288 + v23];
        v26 = (unsigned char)*(v25 - 224);
        if ( v26 < n )
          *(v25 - 224) = v26 + 1;
        v12 >>= 2;
        --v14;
      }
      while ( v14 );
      v27 = v15;
      a2 = v13 + 1;
      v9 = v27;
    }
    while ( v64 != a2 );
    v7 = v69;
  }
  else
  {
    v24 = 4;
    v22 = 8;
  }
  v28 = v66;
  v70[76] = v7 - 1;
  v29 = v66;
  v62[9 * v22 + 64 + v24] = v7;
  sub_FB90((long long)v29);
  v30 = sub_E880(v28);
  v32 = __snprintf_chk(s, 17, 1, 17, "[%s %u]", v31);
  if ( (unsigned int)v32 > 0x11 )
  {
    v30 = sub_E880(v66);
    v32 = __snprintf_chk(s, 17, 1, 17, "[%s]", v61);
  }
  v33 = v65 + 1;
  if ( v32 > 0 )
  {
    v34 = strlen(s);
    v35 = __snprintf_chk(src, 17, 1, 17, "[%s]", v68);
    v36 = (17 - v34) >> 1;
    if ( v35 > 0 )
      goto LABEL_24;
    v39 = 8;
    v38 = 0;
    *v65 = 43;
    if ( !v36 )
      goto LABEL_47;
LABEL_25:
    v40 = v65;
    for ( i = 0; i < v36; ++i )
      v40[i + 1] = 45;
    v33 += v36;
    v42 = (int *)(v34 + v36);
    goto LABEL_28;
  }
  v34 = 0;
  v60 = __snprintf_chk(src, 17, 1, 17, "[%s]", v68);
  v36 = 8;
  if ( v60 <= 0 )
  {
    v39 = 8;
    v38 = 0;
    *v65 = 43;
    goto LABEL_25;
  }
LABEL_24:
  n = v36;
  v37 = strlen(src);
  v36 = n;
  v38 = v37;
  v39 = (17 - v37) >> 1;
  *v65 = 43;
  if ( v36 )
    goto LABEL_25;
LABEL_47:
  v42 = (int *)v34;
LABEL_28:
  v43 = v34;
  v66 = v42;
  v44 = &v33[v34];
  v64 = (unsigned char *)v39;
  n = v38;
  __memcpy_chk(v33, s, v43, 219, v30);
  v45 = n;
  v46 = v64;
  if ( (unsigned long long)v66 > 0x10 )
  {
    v47 = (long long)v44;
  }
  else
  {
    v47 = v44 - (char *)v66 + 17;
    do
      *v44++ = 45;
    while ( (char *)v47 != v44 );
  }
  v48 = v67;
  v49 = (char *)(v47 + 20);
  *(short *)v47 = 2603;
  do
  {
    *(v49 - 18) = 124;
    v50 = v49 - 17;
    v51 = v48;
    do
    {
      v52 = *v51;
      ++v50;
      if ( v52 > v7 )
        v52 = v7;
      v51 += 9;
      *(v50 - 1) = aOBoxSe[v52];
    }
    while ( v50 != v49 );
    ++v48;
    *v50 = 124;
    v49 = v50 + 20;
    v50[1] = 10;
  }
  while ( &v70[9] != v48 );
  *(char *)(v47 + 182) = 43;
  v53 = (char *)(v47 + 183);
  if ( v46 )
  {
    v54 = (unsigned char *)(v47 + 183);
    do
      *v54++ = 45;
    while ( v54 != &v46[v47 + 183] );
    v53 = &v53[(long long)v46];
    v55 = (unsigned long long)&v46[v45];
  }
  else
  {
    v55 = v45;
  }
  n = v45;
  v56 = (char *)memcpy(v53, src, v45);
  v57 = &v56[n];
  v58 = v57;
  if ( v55 <= 0x10 )
  {
    v58 = &v57[-v55 + 17];
    do
      *v57++ = 45;
    while ( v57 != v58 );
  }
  *v58 = 43;
  return 0.0;
}


// Function: sshkey_ecdsa_bits_to_nid @ 0x10240
double sshkey_ecdsa_bits_to_nid()
{
  return 0.0;
}


// Function: ecdsa_generate_private_key @ 0x102f0
double ecdsa_generate_private_key(long long a1, int *a2, long long *a3)
{
  double v4; // xmm0_8
  int v5; // eax
  long long v6; // rax
  long long v7; // rbp

  v4 = sub_10240();
  *a2 = v5;
  if ( v5 != -1 )
  {
    *a3 = 0;
    v6 = EC_KEY_new_by_curve_name((unsigned int)*a2, v4);
    v7 = v6;
    if ( v6 && (unsigned int)EC_KEY_generate_key(v6) == 1 )
    {
      EC_KEY_set_asn1_flag(v7, 1);
      *a3 = v7;
      v7 = 0;
    }
    EC_KEY_free(v7);
  }
  return 0.0;
}


// Function: sshkey_curve_nid_to_name @ 0x10400
double sshkey_curve_nid_to_name()
{
  return 0.0;
}


// Function: sshkey_ec_nid_to_hash_alg @ 0x109a0
double sshkey_ec_nid_to_hash_alg()
{
  sub_FAE0();
  return 0.0;
}


// Function: sshkey_free @ 0x10a60
double sshkey_free(void *ptr)
{
  void *v2; // rdi
  double result; // xmm0_8
  int v4; // eax
  int v5; // eax

  if ( !ptr )
    return 0.0;
  switch ( *(int *)ptr )
  {
    case 0:
    case 4:
      RSA_free(*((long long *)ptr + 1));
      *((long long *)ptr + 1) = 0;
      goto LABEL_5;
    case 1:
    case 5:
      DSA_free(*((long long *)ptr + 2));
      *((long long *)ptr + 2) = 0;
      goto LABEL_5;
    case 2:
    case 6:
      goto LABEL_8;
    case 3:
    case 7:
      goto LABEL_4;
    case 0xA:
    case 0xB:
      free(*((void **)ptr + 12));
      sub_BCE0(*((long long **)ptr + 14));
      sub_BCE0(*((long long **)ptr + 15));
LABEL_8:
      EC_KEY_free(*((long long *)ptr + 4));
      *((long long *)ptr + 4) = 0;
      result = sub_F3B0((int *)ptr);
      if ( v5 )
        goto LABEL_9;
      goto LABEL_6;
    case 0xC:
    case 0xD:
      free(*((void **)ptr + 12));
      sub_BCE0(*((long long **)ptr + 14));
      sub_BCE0(*((long long **)ptr + 15));
LABEL_4:
      sub_3B0D0(*((void **)ptr + 6));
      v2 = (void *)*((long long *)ptr + 5);
      *((long long *)ptr + 6) = 0;
      sub_3B0D0(v2);
      *((long long *)ptr + 5) = 0;
      goto LABEL_5;
    default:
LABEL_5:
      result = sub_F3B0((int *)ptr);
      if ( v4 )
LABEL_9:
        sub_10C30(*((void **)ptr + 16));
LABEL_6:
      sub_3B0D0(*((void **)ptr + 17));
      sub_3B0D0(*((void **)ptr + 19));
      sub_3B0D0(ptr);
      break;
  }
  return result;
}


// Function: cert_free @ 0x10c30
double cert_free(long long **ptr)
{
  unsigned int v1; // ebx
  long long v2; // rdx
  double result; // xmm0_8

  if ( !ptr )
    return 0.0;
  sub_BCE0(*ptr);
  sub_BCE0(ptr[8]);
  sub_BCE0(ptr[9]);
  free(ptr[3]);
  if ( *((int *)ptr + 8) )
  {
    v1 = 0;
    do
    {
      v2 = v1++;
      free((void *)ptr[5][v2]);
    }
    while ( *((int *)ptr + 8) > v1 );
  }
  free(ptr[5]);
  result = sub_10A60(ptr[10]);
  free(ptr[11]);
  sub_3B0D0(ptr);
  return result;
}


// Function: cert_new @ 0x10d40
double cert_new()
{
  long long *v0; // r12
  long long v1; // rax
  long long v2; // rax
  long long v3; // rax

  v0 = calloc(1u, 0x60u);
  if ( !v0 )
    return 0.0;
  sub_B880();
  *v0 = v1;
  if ( v1 )
  {
    sub_B880();
    v0[8] = v2;
    if ( v2 )
    {
      sub_B880();
      v0[9] = v3;
      if ( v3 )
      {
        v0[3] = 0;
        v0[5] = 0;
        v0[10] = 0;
        v0[11] = 0;
        return 0.0;
      }
    }
  }
  sub_10C30((long long **)v0);
  return 0.0;
}


// Function: sshkey_new @ 0x10ed0
double sshkey_new(unsigned int a1)
{
  int *v1; // rax
  int *v2; // r12
  long long v3; // rax
  int v4; // eax
  long long v6; // rax
  long long v7; // rax
  long long v8; // rax

  v1 = (int *)calloc(1u, 0xA8u);
  v2 = v1;
  if ( !v1 )
    return 0.0;
  *v1 = a1;
  *((long long *)v1 + 4) = 0;
  v1[6] = -1;
  *((long long *)v1 + 2) = 0;
  *((long long *)v1 + 1) = 0;
  *((long long *)v1 + 16) = 0;
  *((long long *)v1 + 5) = 0;
  *((long long *)v1 + 6) = 0;
  *((long long *)v1 + 10) = 0;
  *((long long *)v1 + 11) = 0;
  if ( a1 <= 0xE )
  {
    v3 = 1LL << a1;
    if ( ((1LL << a1) & 0x7FCC) != 0 )
      goto LABEL_4;
    if ( (v3 & 0x22) != 0 )
    {
      v8 = DSA_new();
      if ( v8 )
      {
        *((long long *)v2 + 2) = v8;
LABEL_4:
        sub_F3B0(v2);
        if ( v4 )
        {
          sub_10D40();
          *((long long *)v2 + 16) = v6;
          if ( !v6 )
            sub_10A60(v2);
        }
        return 0.0;
      }
    }
    else if ( (v3 & 0x11) != 0 )
    {
      v7 = RSA_new();
      if ( v7 )
      {
        *((long long *)v2 + 1) = v7;
        goto LABEL_4;
      }
    }
  }
  free(v2);
  return 0.0;
}


// Function: sshkey_equal_public @ 0x11100
double sshkey_equal_public(unsigned int *a1, long long *a2)
{
  int v3; // r12d
  int v5; // eax
  int v6; // ebp
  double v7; // xmm0_8
  int v8; // eax
  const char *v10; // rdi
  const char *v11; // rsi
  const void *v12; // rdi
  const void *v13; // rsi
  const char *v14; // rdi
  const char *v15; // rsi
  long long v16; // rbp
  long long v17; // rax
  long long v18; // r12
  long long v19; // rbp
  long long v20; // rax
  long long v21; // rdi
  long long v22; // rdi
  long long v23; // [rsp+8h] [rbp-70h] BYREF
  long long v24; // [rsp+10h] [rbp-68h] BYREF
  long long v25; // [rsp+18h] [rbp-60h] BYREF
  long long v26; // [rsp+20h] [rbp-58h] BYREF
  long long v27; // [rsp+28h] [rbp-50h] BYREF
  long long v28; // [rsp+30h] [rbp-48h] BYREF
  long long v29; // [rsp+38h] [rbp-40h] BYREF
  long long v30[7]; // [rsp+40h] [rbp-38h] BYREF

  v30[1] = __readfsqword(0x28u);
  if ( a1 )
  {
    if ( a2 )
    {
      v3 = *a1;
      sub_F440(*a1);
      v6 = v5;
      v7 = sub_F440(*(unsigned int *)a2);
      if ( v6 == v8 )
      {
        switch ( v3 )
        {
          case 0:
          case 4:
            v21 = *((long long *)a1 + 1);
            if ( v21 )
            {
              if ( a2[1] )
              {
                RSA_get0_key(v21, &v28, &v27, 0);
                RSA_get0_key(a2[1], v30, &v29, 0);
                if ( !(unsigned int)BN_cmp(v27, v29) )
                  BN_cmp(v28, v30[0]);
              }
            }
            return 0.0;
          case 1:
          case 5:
            v22 = *((long long *)a1 + 2);
            if ( v22 )
            {
              if ( a2[2] )
              {
                DSA_get0_pqg(v22, &v23, &v24, &v25);
                DSA_get0_pqg(a2[2], &v27, &v28, &v29);
                DSA_get0_key(*((long long *)a1 + 2), &v26, 0, v7);
                DSA_get0_key(a2[2], v30, 0, v7);
                if ( !(unsigned int)BN_cmp(v23, v27)
                  && !(unsigned int)BN_cmp(v24, v28)
                  && !(unsigned int)BN_cmp(v25, v29) )
                {
                  BN_cmp(v26, v30[0]);
                }
              }
            }
            return 0.0;
          case 2:
          case 6:
            goto LABEL_15;
          case 3:
          case 7:
            goto LABEL_9;
          case 10:
          case 11:
            v14 = (const char *)*((long long *)a1 + 12);
            if ( v14 )
            {
              v15 = (const char *)a2[12];
              if ( v15 )
              {
                if ( !strcmp(v14, v15) )
                {
LABEL_15:
                  if ( *((long long *)a1 + 4) )
                  {
                    if ( a2[4] )
                    {
                      if ( EC_KEY_get0_public_key(v7) )
                      {
                        if ( EC_KEY_get0_public_key(v7) )
                        {
                          v16 = EC_KEY_get0_group(a2[4]);
                          v17 = EC_KEY_get0_group(*((long long *)a1 + 4));
                          if ( !(unsigned int)EC_GROUP_cmp(v17, v16, 0) )
                          {
                            v18 = EC_KEY_get0_public_key(v7);
                            v19 = EC_KEY_get0_public_key(v7);
                            v20 = EC_KEY_get0_group(*((long long *)a1 + 4));
                            EC_POINT_cmp(v20, v19, v18, 0);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            return 0.0;
          case 12:
          case 13:
            v10 = (const char *)*((long long *)a1 + 12);
            if ( v10 )
            {
              v11 = (const char *)a2[12];
              if ( v11 )
              {
                if ( !strcmp(v10, v11) )
                {
LABEL_9:
                  v12 = (const void *)*((long long *)a1 + 6);
                  if ( v12 )
                  {
                    v13 = (const void *)a2[6];
                    if ( v13 )
                      memcmp(v12, v13, 0x20u);
                  }
                }
              }
            }
            break;
          default:
            return 0.0;
        }
      }
    }
  }
  return 0.0;
}


// Function: sshkey_equal @ 0x11490
double sshkey_equal(long long a1, long long *a2)
{
  int v5; // eax
  __int128 v6; // rdi
  int v7; // eax

  if ( !a1 )
    return 0.0;
  if ( a2 )
  {
    if ( *(int *)a1 == *(int *)a2 )
    {
      sub_F3B0((int *)a1);
      if ( !v5 )
        return sub_11100((unsigned int *)a1, a2);
      *((long long *)&v6 + 1) = a2[16];
      *(long long *)&v6 = *(long long *)(a1 + 128);
      sub_DA80(v6);
      if ( v7 )
        return sub_11100((unsigned int *)a1, a2);
    }
  }
  return 0.0;
}


// Function: sshkey_putb @ 0x11600
long long sshkey_putb(long long a1, long long a2)
{
  return sub_104C0(a1, a2, 0);
}


// Function: sshkey_puts_opts @ 0x11610
double sshkey_puts_opts(long long a1, long long a2)
{
  long long *v2; // rax
  long long *v3; // rbp

  sub_B880();
  if ( v2 )
  {
    v3 = v2;
    if ( !(unsigned int)sub_104C0(a1, v2, 0) )
      sub_1B840(a2, v3);
    sub_BCE0(v3);
  }
  return 0.0;
}


// Function: sshkey_to_blob @ 0x11720
long long sshkey_to_blob(long long a1, long long a2, long long a3)
{
  return sub_10850(a1, a2, a3, 0);
}


// Function: sshkey_fingerprint_raw @ 0x11740
double sshkey_fingerprint_raw(long long a1, unsigned int a2, long long *a3, long long *a4)
{
  void *v6; // r15
  void *v7; // r14
  void *v9; // rax
  void *ptr; // [rsp+8h] [rbp-50h] BYREF
  long long v11[9]; // [rsp+10h] [rbp-48h] BYREF

  v11[1] = __readfsqword(0x28u);
  ptr = 0;
  v11[0] = 0;
  if ( a3 )
    *a3 = 0;
  if ( a4 )
    *a4 = 0;
  if ( sub_30050(a2) )
  {
    if ( (unsigned int)sub_10850(a1, &ptr, v11, 1) )
    {
      v6 = ptr;
      v7 = 0;
    }
    else
    {
      v9 = calloc(1u, 0x40u);
      v6 = ptr;
      v7 = v9;
      if ( v9 && !(unsigned int)sub_30740(a2, ptr, v11[0], v9, 64) )
      {
        if ( a3 )
        {
          *a3 = v7;
          v7 = 0;
        }
        if ( a4 )
          *a4 = sub_30050(a2);
      }
    }
    free(v7);
    if ( v6 )
      sub_3B0D0(v6);
  }
  else
  {
    free(0);
  }
  return 0.0;
}


// Function: sshkey_fingerprint @ 0x11920
double sshkey_fingerprint(int *a1, unsigned int a2, int a3)
{
  double v4; // xmm0_8
  int v5; // eax
  unsigned long long v6; // r14
  unsigned char *v7; // r13
  long long v8; // rdi
  const char *v9; // rax
  const char *v11; // rax
  const char *v12; // rax
  void *ptr; // [rsp+8h] [rbp-40h] BYREF
  unsigned long long v14[7]; // [rsp+10h] [rbp-38h] BYREF

  v14[1] = __readfsqword(0x28u);
  v4 = sub_11740((long long)a1, a2, &ptr, v14);
  if ( !v5 )
  {
    v6 = v14[0];
    v7 = (unsigned char *)ptr;
    switch ( a3 )
    {
      case 0:
        v8 = 0;
        if ( !a2 )
          goto LABEL_8;
        goto LABEL_4;
      case 1:
        v8 = a2;
LABEL_8:
        v11 = (const char *)sub_2FFC0(v8, v4);
        sub_DC80(v11, (long long)v7, v6);
        goto LABEL_5;
      case 2:
LABEL_4:
        v9 = (const char *)sub_2FFC0(a2, v4);
        sub_DE20(v9, (long long)v7, v6);
        goto LABEL_5;
      case 3:
        sub_D7C0((long long)ptr, v14[0]);
        goto LABEL_5;
      case 4:
        v12 = (const char *)sub_2FFC0(a2, v4);
        sub_FCF0(v12, v7, v6, a1);
LABEL_5:
        sub_3B0D0(v7);
        break;
      default:
        sub_3B0D0(ptr);
        break;
    }
  }
  return 0.0;
}


// Function: sshkey_to_base64 @ 0x11ad0
double sshkey_to_base64(long long a1, long long *a2)
{
  long long v2; // rax
  double v3; // xmm0_8
  long long *v4; // rbp
  void *v5; // r13
  long long v7; // rax

  if ( a2 )
    *a2 = 0;
  v3 = sub_B880();
  v4 = (long long *)v2;
  if ( v2 )
  {
    v5 = 0;
    if ( !(unsigned int)sub_11600(a1, v2) )
    {
      v7 = sub_1C950(v4, 0, v3);
      v5 = (void *)v7;
      if ( v7 )
      {
        if ( a2 )
        {
          *a2 = v7;
          v5 = 0;
        }
      }
    }
    sub_BCE0(v4);
    free(v5);
  }
  return 0.0;
}


// Function: sshkey_format_text @ 0x11c00
double sshkey_format_text(int *a1, int a2)
{
  int v2; // eax
  void *v3; // r13
  int v5; // eax
  int v6; // r8d
  int v7; // r9d
  void *ptr[7]; // [rsp+0h] [rbp-38h] BYREF

  ptr[1] = (void *)__readfsqword(0x28u);
  ptr[0] = 0;
  sub_11AD0((long long)a1, (long long *)ptr);
  v3 = ptr[0];
  if ( !v2 )
  {
    sub_EAF0(a1);
    sub_1AD40(a2, (unsigned int)"%s %s", v5, (int)v3, v6, v7, (char)ptr[0]);
  }
  free(v3);
  return 0.0;
}


// Function: sshkey_write @ 0x11d20
double sshkey_write(int *a1, FILE *a2)
{
  long long *v2; // rax
  long long *v3; // rbp
  int v4; // eax
  size_t v6; // rax
  size_t v7; // r14
  const void *v8; // rax

  sub_B880();
  if ( v2 )
  {
    v3 = v2;
    sub_11C00(a1, (int)v2);
    if ( !v4 )
    {
      sub_C3D0((long long)v3);
      v7 = v6;
      sub_C520((long long)v3);
      if ( fwrite(v8, v7, 1u, a2) != 1 )
      {
        if ( feof(a2) )
          *__errno_location() = 32;
      }
    }
    sub_BCE0(v3);
  }
  return 0.0;
}


// Function: sshkey_ecdsa_key_to_nid @ 0x11f10
double sshkey_ecdsa_key_to_nid(long long a1)
{
  long long v1; // rbx
  unsigned int *v2; // r14
  unsigned int v3; // r12d
  long long v4; // rax
  long long v5; // rbp
  int v7[2]; // [rsp+0h] [rbp-48h] BYREF
  long long v8; // [rsp+8h] [rbp-40h]
  unsigned long long v9; // [rsp+18h] [rbp-30h]

  v9 = __readfsqword(0x28u);
  v7[1] = 715;
  v8 = -4294966580LL;
  v1 = EC_KEY_get0_group(a1);
  if ( (int)EC_GROUP_get_curve_name(v1) <= 0 )
  {
    v2 = v7;
    v3 = 415;
    do
    {
      v4 = EC_GROUP_new_by_curve_name(v3);
      v5 = v4;
      if ( !v4 )
        break;
      if ( !(unsigned int)EC_GROUP_cmp(v1, v4, 0) )
      {
        EC_GROUP_set_asn1_flag(v5, 1);
        if ( (unsigned int)EC_KEY_set_group(a1, v5) != 1 )
          EC_GROUP_free(v5);
        return 0.0;
      }
      ++v2;
      EC_GROUP_free(v5);
      v3 = *v2;
    }
    while ( *v2 != -1 );
  }
  return 0.0;
}


// Function: sshkey_generate @ 0x12090
double sshkey_generate(int a1, unsigned int a2, long long *a3)
{
  long long v4; // rax
  double v5; // xmm0_8
  long long *v6; // rbp
  int v7; // eax
  void *v9; // rax
  void *v10; // rax
  int v11; // eax
  int v12; // eax

  if ( !a3 )
    return 0.0;
  *a3 = 0;
  v5 = sub_10ED0(0xEu);
  v6 = (long long *)v4;
  if ( !v4 )
    return 0.0;
  if ( a1 == 2 )
  {
    sub_102F0(a2, (int *)(v4 + 24), (long long *)(v4 + 32));
    if ( !v12 )
      goto LABEL_14;
    goto LABEL_8;
  }
  if ( a1 > 2 )
  {
    if ( a1 != 3 )
      goto LABEL_8;
    v9 = malloc(0x20u);
    v6[6] = v9;
    if ( !v9 )
      goto LABEL_8;
    v10 = malloc(0x40u);
    v6[5] = v10;
    if ( !v10 )
      goto LABEL_8;
    sub_30930(v6[6], v10, v5);
    goto LABEL_14;
  }
  if ( !a1 )
  {
    sub_E0C0(a2, (long long *)(v4 + 8));
    if ( !v11 )
      goto LABEL_14;
LABEL_8:
    sub_10A60(v6);
    return 0.0;
  }
  if ( a1 != 1 )
    goto LABEL_8;
  sub_DFA0(a2, (long long *)(v4 + 16));
  if ( v7 )
    goto LABEL_8;
LABEL_14:
  *(int *)v6 = a1;
  *a3 = v6;
  return 0.0;
}


// Function: sshkey_from_private @ 0x12300
double sshkey_from_private(long long a1, long long *a2)
{
  long long v3; // rax
  double v4; // xmm0_8
  long long *v5; // rbp
  unsigned int v6; // edx
  __m128i *v7; // rax
  __m128i *v8; // r13
  const __m128i *v9; // rax
  double v10; // xmm0_8
  int v11; // eax
  long long v12; // r10
  long long v13; // r9
  long long v14; // rbx
  long long v15; // r14
  long long v16; // r15
  double v17; // xmm0_8
  long long v19; // rdi
  long long v20; // rax
  long long v21; // rax
  char *v22; // rax
  long long v23; // rax
  long long v24; // rax
  int v25; // eax
  long long v26; // rcx
  long long v27; // r8
  int v28; // eax
  long long v29; // rax
  long long v30; // [rsp+8h] [rbp-90h]
  long long v31; // [rsp+10h] [rbp-88h]
  long long v32; // [rsp+10h] [rbp-88h]
  long long v33; // [rsp+18h] [rbp-80h]
  long long v34; // [rsp+28h] [rbp-70h] BYREF
  long long v35; // [rsp+30h] [rbp-68h] BYREF
  long long v36; // [rsp+38h] [rbp-60h] BYREF
  long long v37; // [rsp+40h] [rbp-58h] BYREF
  long long v38; // [rsp+48h] [rbp-50h] BYREF
  long long v39[9]; // [rsp+50h] [rbp-48h] BYREF

  v39[1] = __readfsqword(0x28u);
  *a2 = 0;
  v4 = sub_10ED0(*(int *)a1);
  v5 = (long long *)v3;
  if ( v3 )
  {
    v6 = *(int *)a1;
    switch ( *(int *)a1 )
    {
      case 0:
      case 4:
        RSA_get0_key(*(long long *)(a1 + 8), &v34, &v35, 0);
        v8 = (__m128i *)BN_dup(v34, v4);
        if ( !v8 )
          goto LABEL_31;
        v29 = BN_dup(v35, v4);
        v16 = v29;
        if ( v29 )
        {
          if ( (unsigned int)RSA_set0_key(v5[1], v8, v29, 0) )
            goto LABEL_7;
          v12 = 0;
          v13 = 0;
          v14 = 0;
          v15 = 0;
        }
        else
        {
          v12 = 0;
          v13 = 0;
          v14 = 0;
          v15 = 0;
        }
        goto LABEL_9;
      case 1:
      case 5:
        DSA_get0_pqg(*(long long *)(a1 + 16), &v36, &v37, &v38);
        DSA_get0_key(*(long long *)(a1 + 16), v39, 0, v4);
        v15 = BN_dup(v36, v4);
        if ( !v15 )
        {
          v12 = 0;
          v13 = 0;
          v14 = 0;
          v16 = 0;
          v8 = 0;
          goto LABEL_9;
        }
        v14 = BN_dup(v37, v4);
        if ( !v14 )
        {
          v12 = 0;
          v13 = 0;
          v16 = 0;
          v8 = 0;
          goto LABEL_9;
        }
        v23 = BN_dup(v38, v4);
        v13 = v23;
        if ( !v23 )
        {
          v12 = 0;
          v16 = 0;
          v8 = 0;
          goto LABEL_9;
        }
        v32 = v23;
        v24 = BN_dup(v39[0], v4);
        v13 = v32;
        v12 = v24;
        if ( !v24 )
        {
          v16 = 0;
          v8 = 0;
          goto LABEL_9;
        }
        v33 = v24;
        v25 = DSA_set0_pqg(v5[2], v15, v14, v32);
        v13 = v32;
        v12 = v33;
        if ( !v25 )
          goto LABEL_22;
        v28 = DSA_set0_key(v5[2], v33, 0, v26, v27, v32);
        v12 = v33;
        if ( !v28 )
          goto LABEL_21;
        goto LABEL_7;
      case 2:
      case 6:
      case 0xA:
      case 0xB:
        v19 = *(unsigned int *)(a1 + 24);
        *(int *)(v3 + 24) = v19;
        v20 = EC_KEY_new_by_curve_name(v19, v4);
        v5[4] = v20;
        v8 = (__m128i *)v20;
        if ( !v20 )
          goto LABEL_31;
        v21 = EC_KEY_get0_public_key(v4);
        if ( (unsigned int)EC_KEY_set_public_key(v5[4], v21) != 1 )
        {
          v12 = 0;
LABEL_21:
          v13 = 0;
          v14 = 0;
          v15 = 0;
LABEL_22:
          v16 = 0;
          v8 = 0;
          goto LABEL_9;
        }
        if ( (unsigned int)(*(int *)a1 - 10) > 1 )
          goto LABEL_7;
        goto LABEL_13;
      case 3:
      case 7:
      case 0xC:
      case 0xD:
        if ( !*(long long *)(a1 + 48) )
          goto LABEL_6;
        v7 = (__m128i *)malloc(0x20u);
        v5[6] = v7;
        v8 = v7;
        if ( !v7 )
        {
LABEL_31:
          v12 = 0;
          v13 = 0;
          v14 = 0;
          v15 = 0;
          v16 = 0;
          goto LABEL_9;
        }
        v9 = *(const __m128i **)(a1 + 48);
        v6 = *(int *)a1;
        *v8 = _mm_loadu_si128(v9);
        v8[1] = _mm_loadu_si128(v9 + 1);
LABEL_6:
        if ( v6 - 12 <= 1 )
        {
LABEL_13:
          v22 = strdup(*(const char **)(a1 + 96));
          v5[12] = v22;
          v8 = (__m128i *)v22;
          if ( !v22 )
          {
            v12 = 0;
            v13 = 0;
            v14 = 0;
            v15 = 0;
            v16 = 0;
            goto LABEL_9;
          }
        }
LABEL_7:
        v10 = sub_F3B0((int *)a1);
        if ( !v11 || !(unsigned int)sub_127C0(a1, v5, v10) )
        {
          v12 = 0;
          v13 = 0;
          v14 = 0;
          v15 = 0;
          v16 = 0;
          v8 = 0;
          *a2 = v5;
          v5 = 0;
          goto LABEL_9;
        }
        break;
      default:
        break;
    }
  }
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v8 = 0;
LABEL_9:
  v31 = v12;
  v30 = v13;
  v17 = sub_10A60(v5);
  BN_clear_free(v8, v17);
  BN_clear_free(v16, v17);
  BN_clear_free(v15, v17);
  BN_clear_free(v14, v17);
  BN_clear_free(v30, v17);
  BN_clear_free(v31, v17);
  return 0.0;
}


// Function: sshkey_cert_copy @ 0x127c0
double sshkey_cert_copy(long long a1, long long a2)
{
  long long v2; // r13
  long long *v3; // rax
  double v4; // xmm0_8
  long long *v5; // rbp
  const char *v7; // rdi
  char *v8; // rax
  long long v9; // rdi
  int v10; // eax
  const char *v11; // rdi
  char *v12; // rax
  size_t v13; // rdi
  long long *v14; // rax
  unsigned int v15; // r15d

  if ( a2 )
  {
    v2 = *(long long *)(a1 + 128);
    if ( v2 )
    {
      v4 = sub_10D40();
      v5 = v3;
      if ( v3 )
      {
        if ( (unsigned int)sub_1AAD0(*v3, *(long long *)v2, v4)
          || (unsigned int)sub_1AAD0(v5[8], *(long long *)(v2 + 64), v4)
          || (unsigned int)sub_1AAD0(v5[9], *(long long *)(v2 + 72), v4) )
        {
          goto LABEL_5;
        }
        v5[2] = *(long long *)(v2 + 16);
        *((int *)v5 + 2) = *(int *)(v2 + 8);
        v7 = *(const char **)(v2 + 24);
        if ( v7 )
        {
          v8 = strdup(v7);
          v5[3] = v8;
          if ( !v8 )
            goto LABEL_5;
        }
        else
        {
          v5[3] = 0;
        }
        v5[6] = *(long long *)(v2 + 48);
        v5[7] = *(long long *)(v2 + 56);
        v9 = *(long long *)(v2 + 80);
        if ( v9 )
        {
          sub_12300(v9, v5 + 10);
          if ( v10 )
            goto LABEL_5;
        }
        else
        {
          v5[10] = 0;
        }
        v11 = *(const char **)(v2 + 88);
        if ( v11 )
        {
          v12 = strdup(v11);
          v5[11] = v12;
          if ( !v12 )
            goto LABEL_5;
        }
        v13 = *(unsigned int *)(v2 + 32);
        if ( (unsigned int)v13 > 0x100 )
          goto LABEL_5;
        if ( (int)v13 )
        {
          v14 = calloc(v13, 8u);
          v5[5] = v14;
          if ( !v14 )
            goto LABEL_5;
          LODWORD(v13) = *(int *)(v2 + 32);
          if ( (int)v13 )
          {
            v15 = 0;
            while ( 1 )
            {
              v14[v15] = strdup(*(const char **)(*(long long *)(v2 + 40) + 8LL * v15));
              v14 = (long long *)v5[5];
              if ( !v14[v15] )
                break;
              LODWORD(v13) = *(int *)(v2 + 32);
              if ( (unsigned int)v13 <= ++v15 )
                goto LABEL_23;
            }
            *((int *)v5 + 8) = v15;
            goto LABEL_5;
          }
        }
LABEL_23:
        *((int *)v5 + 8) = v13;
        sub_10C30(*(long long ***)(a2 + 128));
        *(long long *)(a2 + 128) = v5;
        v5 = 0;
LABEL_5:
        sub_10C30((long long **)v5);
      }
    }
  }
  return 0.0;
}


// Function: sshkey_is_shielded @ 0x12a70
double sshkey_is_shielded()
{
  return 0.0;
}


// Function: sshkey_check_rsa_length @ 0x12b10
double sshkey_check_rsa_length(long long a1)
{
  long long v2[3]; // [rsp+0h] [rbp-18h] BYREF

  v2[1] = __readfsqword(0x28u);
  if ( a1 && *(long long *)(a1 + 8) && (*(int *)a1 & 0xFFFFFFFB) == 0 )
  {
    RSA_get0_key(*(long long *)(a1 + 8), v2, 0, 0);
    BN_num_bits(v2[0]);
  }
  return 0.0;
}


// Function: sshkey_get_sigtype @ 0x12c20
double sshkey_get_sigtype(long long a1, unsigned long long a2, long long *a3)
{
  long long *v4; // rax
  long long *v5; // rbp
  int v6; // eax
  void *v7; // rdi
  long long v9[5]; // [rsp+0h] [rbp-28h] BYREF

  v9[1] = __readfsqword(0x28u);
  v9[0] = 0;
  if ( a3 )
    *a3 = 0;
  sub_B980(a1, a2);
  v5 = v4;
  if ( v4 )
  {
    v6 = sub_1A6F0(v4, v9, 0);
    v7 = (void *)v9[0];
    if ( !v6 && a3 )
    {
      v9[0] = 0;
      *a3 = v7;
      v7 = 0;
    }
    free(v7);
    sub_BCE0(v5);
  }
  return 0.0;
}


// Function: sshkey_check_cert_sigtype @ 0x12d50
double sshkey_check_cert_sigtype(long long a1, long long a2)
{
  double v2; // xmm0_8
  int v3; // eax
  long long v4; // rax
  long long v5; // rdi

  if ( !a1 )
    return 0.0;
  if ( a2 )
  {
    v2 = sub_E9C0(*(int *)a1);
    if ( v3 )
    {
      v4 = *(long long *)(a1 + 128);
      if ( v4 )
      {
        v5 = *(long long *)(v4 + 88);
        if ( v5 )
          sub_20960(v5, a2, 0, v2);
      }
    }
  }
  return 0.0;
}


// Function: sshkey_sigalg_by_name @ 0x12ee0
double sshkey_sigalg_by_name(char *s2)
{
  unsigned int v1; // r13d
  const char *v2; // r12
  char **v3; // rbp
  int v5; // eax

  v1 = 3;
  v2 = "ssh-ed25519";
  v3 = off_66CC0;
  while ( strcmp(v2, s2) )
  {
    v1 = *((int *)v3 + 16);
    v3 += 5;
    if ( v1 == -1 )
      return 0.0;
    v2 = *v3;
  }
  if ( v3[2] || !*((int *)v3 + 8) )
    return 0.0;
  sub_F440(v1);
  return sub_D0A0(v5, *((int *)v3 + 7));
}


// Function: sshkey_check_sigtype @ 0x13010
double sshkey_check_sigtype(long long a1, unsigned long long a2, char *a3)
{
  const char *v3; // rax
  const char *v4; // r13
  int v5; // eax
  char *v7; // r12
  char *s2[5]; // [rsp+0h] [rbp-28h] BYREF

  s2[1] = (char *)__readfsqword(0x28u);
  s2[0] = 0;
  if ( a3 )
  {
    sub_12EE0(a3);
    v4 = v3;
    if ( v3 )
    {
      sub_12C20(a1, a2, s2);
      if ( !v5 )
      {
        v7 = s2[0];
        strcmp(v4, s2[0]);
        free(v7);
      }
    }
  }
  return 0.0;
}


// Function: sshkey_verify @ 0x13150
double sshkey_verify(
        int *a1,
        long long a2,
        long long a3,
        long long a4,
        unsigned long long a5,
        long long a6,
        long long a7,
        long long *a8)
{
  double result; // xmm0_8

  if ( a8 )
    *a8 = 0;
  if ( !a3 || a5 > 0x100000 )
    return 0.0;
  switch ( *a1 )
  {
    case 0:
    case 4:
      sub_2E980(a1, a2, a3, a4);
      break;
    case 1:
    case 5:
      sub_2C0E0(a1, a2, a3, a4, a5, (unsigned int)a7);
      break;
    case 2:
    case 6:
      sub_2C810(a1, a2, a3, a4, a5, (unsigned int)a7);
      break;
    case 3:
    case 7:
      sub_2FA90(a1, a2, a3, a4, a5, (unsigned int)a7);
      break;
    case 0xA:
    case 0xB:
      sub_2CE10((int)a1, a2, a3, a4, a5, a7, (long long)a8);
      break;
    case 0xC:
    case 0xD:
      sub_2D610((int)a1, a2, a3, a4, a5, a7, (long long)a8);
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}


// Function: sshkey_certify_custom @ 0x136c0
double sshkey_certify_custom(
        unsigned int *a1,
        int *a2,
        const char *a3,
        long long a4,
        long long a5,
        unsigned int (*a6)(int *, void **, unsigned long long *, long long, long long, const char *, double, long long, long long, long long, long long),
        long long a7)
{
  long long *v7; // r13
  int v10; // eax
  int v11; // r14d
  int v12; // eax
  const char *v13; // rsi
  long long v14; // r13
  double v15; // xmm0_8
  long long v16; // rax
  char *v17; // r15
  long long *v18; // r14
  double v20; // xmm0_8
  long long *v21; // rax
  long long v22; // rax
  unsigned long long i; // r15
  long long v24; // rax
  long long v25; // r14
  long long v26; // rax
  int v27; // eax
  long long v28; // rax
  double v29; // xmm0_8
  long long v30; // rax
  int v31; // eax
  long long v32; // rax
  int v33; // eax
  void *v37; // [rsp+28h] [rbp-D0h]
  long long v38; // [rsp+28h] [rbp-D0h]
  void *v39; // [rsp+38h] [rbp-C0h] BYREF
  void *ptr; // [rsp+40h] [rbp-B8h] BYREF
  long long v41; // [rsp+48h] [rbp-B0h] BYREF
  unsigned long long v42; // [rsp+50h] [rbp-A8h] BYREF
  char *s2; // [rsp+58h] [rbp-A0h] BYREF
  long long v44; // [rsp+60h] [rbp-98h] BYREF
  long long v45; // [rsp+68h] [rbp-90h] BYREF
  long long v46; // [rsp+70h] [rbp-88h] BYREF
  long long v47; // [rsp+78h] [rbp-80h] BYREF
  long long v48; // [rsp+80h] [rbp-78h] BYREF
  long long v49; // [rsp+88h] [rbp-70h] BYREF
  char dest[40]; // [rsp+90h] [rbp-68h] BYREF
  unsigned long long v51; // [rsp+B8h] [rbp-40h]

  v51 = __readfsqword(0x28u);
  v39 = 0;
  ptr = 0;
  s2 = 0;
  if ( a1 )
  {
    v7 = (long long *)*((long long *)a1 + 16);
    if ( v7 )
    {
      if ( *v7 )
      {
        if ( a2 )
        {
          sub_F3B0((int *)a1);
          if ( v10 )
          {
            v11 = *a2;
            sub_D300();
            if ( v12 )
            {
              v13 = (const char *)v7[11];
              if ( a3 )
              {
                if ( v13 && strcmp(a3, v13) )
                  return 0.0;
              }
              else if ( v13 )
              {
                a3 = (const char *)v7[11];
              }
              else if ( !v11 )
              {
                a3 = "rsa-sha2-512";
              }
              if ( !(unsigned int)sub_11720((long long)a2, (long long)&v39, (long long)&v41) )
              {
                v14 = **((long long **)a1 + 16);
                sub_BE60(v14);
                v15 = sub_EAF0((int *)a1);
                if ( !(unsigned int)sub_1B800(v14, v16) )
                {
                  sub_38B20(dest);
                  if ( !(unsigned int)sub_1B6C0(v14, dest, 32) )
                  {
                    switch ( (unsigned int)sub_3DA20(*a1, 4294967292LL) )
                    {
                      case 0u:
                        RSA_get0_key(*((long long *)a1 + 1), &v44, &v45, 0);
                        if ( (unsigned int)sub_1D610(v14, v45, v15) || (unsigned int)sub_1D610(v14, v44, v15) )
                          break;
                        goto LABEL_25;
                      case 1u:
                        DSA_get0_pqg(*((long long *)a1 + 2), &v46, &v47, &v48);
                        DSA_get0_key(*((long long *)a1 + 2), &v49, 0, v15);
                        if ( (unsigned int)sub_1D610(v14, v46, v15)
                          || (unsigned int)sub_1D610(v14, v47, v15)
                          || (unsigned int)sub_1D610(v14, v48, v15)
                          || (unsigned int)sub_1D610(v14, v49, v15) )
                        {
                          break;
                        }
                        goto LABEL_25;
                      case 2u:
                      case 7u:
                        v15 = sub_10400();
                        if ( (unsigned int)sub_1B800(v14, v24) )
                          break;
                        v25 = EC_KEY_get0_group(*((long long *)a1 + 4));
                        v26 = EC_KEY_get0_public_key(v15);
                        if ( (unsigned int)sub_1D7D0(v14, v26, v25) )
                          break;
                        if ( *a1 == 11 )
                          goto LABEL_37;
                        goto LABEL_25;
                      case 3u:
                      case 9u:
                        if ( (unsigned int)sub_1B6C0(v14, *((long long *)a1 + 6), 32) )
                          break;
                        if ( *a1 != 13 )
                          goto LABEL_25;
LABEL_37:
                        if ( (unsigned int)sub_1B800(v14, *((long long *)a1 + 12)) )
                          break;
LABEL_25:
                        if ( (unsigned int)sub_1AE80(v14, *(long long *)(*((long long *)a1 + 16) + 16LL), v15)
                          || (unsigned int)sub_1AFB0(v14, *(unsigned int *)(*((long long *)a1 + 16) + 8LL))
                          || (unsigned int)sub_1B800(v14, *(long long *)(*((long long *)a1 + 16) + 24LL)) )
                        {
                          break;
                        }
                        v20 = sub_B880();
                        v18 = v21;
                        if ( !v21 )
                        {
                          v17 = 0;
                          goto LABEL_13;
                        }
                        v22 = *((long long *)a1 + 16);
                        for ( i = 0; *(unsigned int *)(v22 + 32) > i; ++i )
                        {
                          if ( (unsigned int)sub_1B800(v18, *(long long *)(*(long long *)(v22 + 40) + 8 * i)) )
                          {
                            v17 = 0;
                            goto LABEL_13;
                          }
                          v22 = *((long long *)a1 + 16);
                        }
                        v17 = 0;
                        v27 = sub_1B840(v14, v18);
                        v37 = v39;
                        if ( v27 )
                          goto LABEL_13;
                        if ( (unsigned int)sub_1AE80(v14, *(long long *)(*((long long *)a1 + 16) + 48LL), v20) )
                          goto LABEL_13;
                        if ( (unsigned int)sub_1AE80(v14, *(long long *)(*((long long *)a1 + 16) + 56LL), v20) )
                          goto LABEL_13;
                        if ( (unsigned int)sub_1B840(v14, *(long long *)(*((long long *)a1 + 16) + 64LL)) )
                          goto LABEL_13;
                        if ( (unsigned int)sub_1B840(v14, *(long long *)(*((long long *)a1 + 16) + 72LL)) )
                          goto LABEL_13;
                        if ( (unsigned int)sub_1B6C0(v14, 0, 0) )
                          goto LABEL_13;
                        if ( (unsigned int)sub_1B6C0(v14, v37, v41) )
                          goto LABEL_13;
                        sub_C3D0(v14);
                        v38 = v28;
                        v29 = sub_C520(v14);
                        if ( a6(a2, &ptr, &v42, v30, v38, a3, v29, a4, a5, 0, a7) )
                          goto LABEL_13;
                        sub_12C20((long long)ptr, v42, &s2);
                        v17 = s2;
                        if ( v31 || a3 && strcmp(a3, s2) )
                          goto LABEL_13;
                        v32 = *((long long *)a1 + 16);
                        if ( !*(long long *)(v32 + 88) )
                        {
                          *(long long *)(v32 + 88) = v17;
                          s2 = 0;
                        }
                        v33 = sub_1B6C0(v14, ptr, v42);
                        v17 = s2;
                        if ( v33 )
                          goto LABEL_13;
                        goto LABEL_14;
                      default:
                        v17 = 0;
                        v18 = 0;
                        goto LABEL_13;
                    }
                  }
                }
                v17 = 0;
                v18 = 0;
LABEL_13:
                sub_BE60(v14);
LABEL_14:
                free(ptr);
                free(v39);
                free(v17);
                sub_BCE0(v18);
              }
            }
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: sshkey_certify @ 0x13d50
double sshkey_certify(unsigned int *a1, int *a2, const char *a3, long long a4, long long a5)
{
  sub_136C0(
    a1,
    a2,
    a3,
    a4,
    a5,
    (unsigned int (*)(int *, void **, unsigned long long *, long long, long long, const char *, double, long long, long long, long long, long long))sub_185E0,
    0);
  return 0.0;
}


// Function: sshkey_cert_check_authority @ 0x13df0
double sshkey_cert_check_authority(long long a1, int a2, int a3, int a4, unsigned long long a5, const char *a6, long long *a7)
{
  double v10; // xmm0_8
  int v11; // eax
  long long v12; // r13
  int v13; // eax
  unsigned int v15; // r14d
  long long v16; // rcx

  if ( a7 )
  {
    v10 = sub_F3B0((int *)a1);
    if ( !v11 )
    {
      *a7 = "Key is not a certificate";
      return 0.0;
    }
    v12 = *(long long *)(a1 + 128);
    v13 = *(int *)(v12 + 8);
    if ( a2 )
    {
      if ( v13 != 2 )
      {
        *a7 = "Certificate invalid: not a host certificate";
        return 0.0;
      }
    }
    else if ( v13 != 1 )
    {
      *a7 = "Certificate invalid: not a user certificate";
      return 0.0;
    }
    if ( *(long long *)(v12 + 48) > a5 )
    {
      *a7 = "Certificate invalid: not yet valid";
    }
    else if ( *(long long *)(v12 + 56) <= a5 )
    {
      *a7 = "Certificate invalid: expired";
    }
    else if ( *(int *)(v12 + 32) )
    {
      if ( a6 )
      {
        v15 = 0;
        do
        {
          while ( 1 )
          {
            v16 = *(long long *)(v12 + 40);
            if ( a4 )
              break;
            if ( !strcmp(a6, *(const char **)(v16 + 8LL * v15)) )
              return 0.0;
            if ( *(int *)(v12 + 32) <= ++v15 )
              goto LABEL_20;
          }
          if ( (unsigned int)sub_20770(*(long long *)(v16 + 8LL * v15), a6, v10) )
            return 0.0;
          v12 = *(long long *)(a1 + 128);
          ++v15;
        }
        while ( *(int *)(v12 + 32) > v15 );
LABEL_20:
        *a7 = "Certificate invalid: name is not a listed principal";
      }
    }
    else if ( a3 )
    {
      *a7 = "Certificate lacks principal list";
    }
  }
  return 0.0;
}


// Function: sshkey_cert_check_authority_now @ 0x14040
double sshkey_cert_check_authority_now(long long a1, int a2, int a3, int a4, const char *a5, long long *a6)
{
  time_t v10; // rax

  v10 = time(0);
  if ( v10 < 0 )
    *a6 = "Certificate invalid: not yet valid";
  else
    sub_13DF0(a1, a2, a3, a4, v10, a5, a6);
  return 0.0;
}


// Function: sshkey_cert_check_host @ 0x14140
double sshkey_cert_check_host(long long a1, const char *a2, int a3, long long a4, long long *a5)
{
  int v7; // eax
  long long v9; // rax
  int v10; // eax

  sub_14040(a1, 1, 0, a3, a2, a5);
  if ( !v7 )
  {
    sub_C3D0(*(long long *)(*(long long *)(a1 + 128) + 64LL));
    if ( v9 )
    {
      *a5 = "Certificate contains unsupported critical options";
    }
    else if ( a4 )
    {
      sub_12D50(a1, a4);
      if ( v10 )
        *a5 = "Certificate signed with disallowed algorithm";
    }
  }
  return 0.0;
}


// Function: sshkey_format_cert_validity @ 0x14260
double sshkey_format_cert_validity(long long a1, long long a2, long long a3)
{
  long long v5; // rdi
  long long v6; // rdi
  char v8[32]; // [rsp+0h] [rbp-108h] BYREF
  char v9[32]; // [rsp+20h] [rbp-E8h] BYREF
  char v10[136]; // [rsp+40h] [rbp-C8h] BYREF
  unsigned long long v11; // [rsp+C8h] [rbp-40h]

  v5 = *(long long *)(a1 + 48);
  v11 = __readfsqword(0x28u);
  v9[0] = 0;
  v8[0] = 0;
  if ( v5 )
  {
    sub_2A450(v5, v8, 32);
    v6 = *(long long *)(a1 + 56);
    if ( v6 == -1 )
    {
      if ( *(long long *)(a1 + 48) )
        goto LABEL_11;
LABEL_8:
      __snprintf_chk(v10, 128, 1, 128, "before %s", v9);
      goto LABEL_9;
    }
  }
  else
  {
    v6 = *(long long *)(a1 + 56);
    if ( v6 == -1 )
    {
      sub_3BEE0(a2, "forever", a3);
      return 0.0;
    }
  }
  sub_2A450(v6, v9, 32);
  if ( !*(long long *)(a1 + 48) )
    goto LABEL_8;
  if ( *(long long *)(a1 + 56) == -1 )
  {
LABEL_11:
    __snprintf_chk(v10, 128, 1, 128, "after %s", v8);
    goto LABEL_9;
  }
  __snprintf_chk(v10, 128, 1, 128, "from %s to %s", v8, v9);
LABEL_9:
  sub_3BEE0(a2, v10, a3);
  return 0.0;
}


// Function: sshkey_ec_validate_public @ 0x14460
double sshkey_ec_validate_public(long long a1, long long a2, double a3)
{
  long long v3; // rax
  long long v4; // r13
  long long v5; // r14
  long long v6; // r12
  long long v7; // r15
  int v8; // ebx
  int v9; // ebx
  long long v10; // rax
  long long v11; // rbx
  long long v12; // rax

  v3 = EC_GROUP_method_of();
  if ( (unsigned int)EC_METHOD_get_field_type(v3) != 406 || (unsigned int)EC_POINT_is_at_infinity(a1, a2) )
  {
    v7 = 0;
    v5 = 0;
    v11 = 0;
    v4 = 0;
    v6 = 0;
  }
  else
  {
    v4 = BN_new();
    if ( v4 )
    {
      v5 = BN_new();
      if ( v5 )
      {
        v6 = BN_new();
        if ( v6 )
        {
          v7 = BN_new();
          if ( v7 )
          {
            if ( (unsigned int)EC_GROUP_get_order(a1, v6, 0) == 1
              && (unsigned int)EC_POINT_get_affine_coordinates_GFp(a1, a2, v4, v5, 0) == 1 )
            {
              v8 = BN_num_bits(v4);
              if ( v8 <= (int)BN_num_bits(v6) / 2 || (v9 = BN_num_bits(v5), v9 <= (int)BN_num_bits(v6) / 2) )
              {
                v11 = 0;
              }
              else
              {
                v10 = EC_POINT_new(a1);
                v11 = v10;
                if ( v10 )
                {
                  if ( (unsigned int)EC_POINT_mul(a1, v10, 0, a2, v6, 0) == 1
                    && (unsigned int)EC_POINT_is_at_infinity(a1, v11) == 1 )
                  {
                    v12 = BN_value_one();
                    if ( (unsigned int)BN_sub(v7, v6, v12) )
                    {
                      if ( (int)BN_cmp(v4, v7) < 0 )
                        BN_cmp(v5, v7);
                    }
                  }
                }
              }
            }
            else
            {
              v11 = 0;
            }
          }
          else
          {
            v11 = 0;
          }
        }
        else
        {
          v7 = 0;
          v11 = 0;
        }
      }
      else
      {
        v7 = 0;
        v6 = 0;
        v11 = 0;
      }
    }
    else
    {
      v7 = 0;
      v5 = 0;
      v11 = 0;
      v6 = 0;
    }
  }
  BN_clear_free(v4, a3);
  BN_clear_free(v5, a3);
  BN_clear_free(v6, a3);
  BN_clear_free(v7, a3);
  EC_POINT_free(v11);
  return 0.0;
}


// Function: sshkey_from_blob_internal @ 0x14780
double sshkey_from_blob_internal(long long a1, long long *a2, int a3)
{
  long long *v5; // rax
  long long *v6; // r15
  int v7; // eax
  double v8; // xmm0_8
  unsigned int v9; // r13d
  long long v10; // rax
  long long v11; // rbp
  void *v12; // rax
  long long v13; // rbx
  long long v14; // rax
  int v15; // eax
  double v16; // xmm0_8
  int v17; // eax
  long long v18; // rax
  long long v19; // rax
  long long v20; // rax
  long long v21; // rax
  int v22; // eax
  double v23; // xmm0_8
  int v24; // eax
  long long v25; // rax
  double v26; // xmm0_8
  double v28; // xmm0_8
  long long v29; // rax
  long long v30; // rcx
  long long v31; // r8
  long long v32; // r9
  long long v33; // rdi
  double v34; // xmm0_8
  long long v35; // rax
  int v36; // eax
  int v37; // eax
  void *ptr; // [rsp+18h] [rbp-90h] BYREF
  char *s1; // [rsp+20h] [rbp-88h] BYREF
  long long v40; // [rsp+28h] [rbp-80h] BYREF
  void *v41; // [rsp+30h] [rbp-78h] BYREF
  long long v42; // [rsp+38h] [rbp-70h] BYREF
  long long v43; // [rsp+40h] [rbp-68h] BYREF
  long long v44; // [rsp+48h] [rbp-60h] BYREF
  long long v45; // [rsp+50h] [rbp-58h] BYREF
  long long v46; // [rsp+58h] [rbp-50h] BYREF
  long long v47[9]; // [rsp+60h] [rbp-48h] BYREF

  v47[1] = __readfsqword(0x28u);
  ptr = 0;
  s1 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47[0] = 0;
  if ( a2 )
    *a2 = 0;
  sub_C640(a1);
  v6 = v5;
  if ( v5 )
  {
    if ( (unsigned int)sub_1A6F0(a1, &ptr, 0) )
    {
LABEL_56:
      v13 = 0;
      v11 = 0;
    }
    else
    {
      v8 = sub_EB00((char *)ptr);
      v9 = v7;
      if ( a3 || (v8 = sub_E9C0(v7), !v37) )
      {
        switch ( v9 )
        {
          case 0u:
            goto LABEL_40;
          case 1u:
            goto LABEL_30;
          case 2u:
          case 0xAu:
            goto LABEL_14;
          case 3u:
          case 0xCu:
            goto LABEL_8;
          case 4u:
            if ( (unsigned int)sub_1A460(a1, 0, 0) )
              goto LABEL_56;
LABEL_40:
            v34 = sub_10ED0(v9);
            v11 = v35;
            if ( !v35 )
              goto LABEL_59;
            if ( (unsigned int)sub_1D220(a1, &v43, v34) || (unsigned int)sub_1D220(a1, &v42, v34) )
              goto LABEL_52;
            if ( !(unsigned int)RSA_set0_key(*(long long *)(v11 + 8), v42, v43, 0) )
              goto LABEL_54;
            v43 = 0;
            v42 = 0;
            sub_12B10(v11);
            if ( !v36 )
              goto LABEL_38;
            v13 = 0;
            break;
          case 5u:
            if ( (unsigned int)sub_1A460(a1, 0, 0) )
              goto LABEL_56;
LABEL_30:
            v28 = sub_10ED0(v9);
            v11 = v29;
            if ( !v29 )
              goto LABEL_59;
            if ( (unsigned int)sub_1D220(a1, &v44, v28)
              || (unsigned int)sub_1D220(a1, &v45, v28)
              || (unsigned int)sub_1D220(a1, &v46, v28)
              || (unsigned int)sub_1D220(a1, v47, v28) )
            {
              goto LABEL_52;
            }
            if ( !(unsigned int)DSA_set0_pqg(*(long long *)(v11 + 16), v44, v45, v46)
              || (v33 = *(long long *)(v11 + 16),
                  v46 = 0,
                  v45 = 0,
                  v44 = 0,
                  !(unsigned int)DSA_set0_key(v33, v47[0], 0, v30, v31, v32)) )
            {
LABEL_54:
              v13 = 0;
              break;
            }
            v47[0] = 0;
LABEL_38:
            v13 = 0;
            goto LABEL_23;
          case 6u:
          case 0xBu:
            if ( (unsigned int)sub_1A460(a1, 0, 0) )
              goto LABEL_56;
LABEL_14:
            sub_10ED0(v9);
            v11 = v14;
            if ( !v14 )
              goto LABEL_59;
            sub_EBF0((char *)ptr);
            *(int *)(v11 + 24) = v15;
            if ( (unsigned int)sub_1A6F0(a1, &s1, 0) )
              goto LABEL_52;
            v16 = sub_FA00(s1);
            if ( *(int *)(v11 + 24) != v17 )
            {
              v13 = 0;
              break;
            }
            EC_KEY_free(*(long long *)(v11 + 32));
            v18 = EC_KEY_new_by_curve_name(*(unsigned int *)(v11 + 24), v16);
            *(long long *)(v11 + 32) = v18;
            v13 = v18;
            if ( !v18 )
              break;
            v19 = EC_KEY_get0_group(v18);
            v13 = EC_POINT_new(v19);
            if ( !v13 )
              break;
            v20 = EC_KEY_get0_group(*(long long *)(v11 + 32));
            if ( (unsigned int)sub_1D360(a1, v13, v20) )
              break;
            v21 = EC_KEY_get0_group(*(long long *)(v11 + 32));
            sub_14460(v21, v13, v16);
            if ( v22
              || (unsigned int)EC_KEY_set_public_key(*(long long *)(v11 + 32), v13) != 1
              || v9 - 10 <= 1 && (unsigned int)sub_1A6F0(a1, v11 + 96, 0) )
            {
              break;
            }
            goto LABEL_23;
          case 7u:
          case 0xDu:
            if ( (unsigned int)sub_1A460(a1, 0, 0) )
              goto LABEL_56;
LABEL_8:
            if ( (unsigned int)sub_1A590(a1, &v41, &v40, v8) )
            {
              v13 = 0;
              v11 = 0;
            }
            else
            {
              if ( v40 != 32 )
                goto LABEL_56;
              sub_10ED0(v9);
              v11 = v10;
              if ( v10 )
              {
                if ( v9 - 12 <= 1 && (unsigned int)sub_1A6F0(a1, v10 + 96, 0) )
                {
LABEL_52:
                  v13 = 0;
                }
                else
                {
                  v12 = v41;
                  v13 = 0;
                  v41 = 0;
                  *(long long *)(v11 + 48) = v12;
LABEL_23:
                  v23 = sub_F3B0((int *)v11);
                  if ( !v24 || !(unsigned int)sub_14EA0(a1, v11, v6, v23) )
                  {
                    sub_C3D0(a1);
                    if ( !v25 && a2 )
                    {
                      *a2 = v11;
                      v11 = 0;
                    }
                  }
                }
              }
              else
              {
                v13 = 0;
              }
            }
            break;
          default:
            v13 = 0;
            v11 = 0;
            break;
        }
      }
      else
      {
        v13 = 0;
        v11 = 0;
      }
    }
  }
  else
  {
LABEL_59:
    v13 = 0;
    v11 = 0;
  }
  sub_BCE0(v6);
  v26 = sub_10A60((void *)v11);
  free(0);
  free(ptr);
  free(s1);
  free(v41);
  BN_clear_free(v42, v26);
  BN_clear_free(v43, v26);
  BN_clear_free(v44, v26);
  BN_clear_free(v45, v26);
  BN_clear_free(v46, v26);
  BN_clear_free(v47[0], v26);
  EC_POINT_free(v13);
  return 0.0;
}


// Function: sshkey_from_blob @ 0x14dd0
double sshkey_from_blob(long long a1, unsigned long long a2, long long *a3)
{
  long long v4; // rax
  long long *v5; // rbp

  sub_B980(a1, a2);
  if ( v4 )
  {
    v5 = (long long *)v4;
    sub_14780(v4, a3, 1);
    sub_BCE0(v5);
  }
  return 0.0;
}


// Function: cert_parse @ 0x14ea0
double cert_parse(long long a1, long long a2, long long a3, double a4)
{
  long long *v4; // rax
  long long v6; // rdx
  long long v7; // rcx
  long long v8; // r8
  long long v9; // r9
  long long v10; // rax
  long long v11; // r13
  double v12; // xmm0_8
  long long v13; // rax
  long long v14; // rbp
  long long v15; // r15
  void *v16; // r14
  long long v17; // rdx
  long long v18; // rcx
  long long v19; // rax
  double v20; // xmm0_8
  long long v21; // rax
  long long v22; // rax
  long long v23; // rax
  int v24; // eax
  long long *v25; // r14
  int v26; // eax
  long long v27; // rax
  int v28; // eax
  void *v29; // [rsp+8h] [rbp-80h] BYREF
  void *v30; // [rsp+10h] [rbp-78h] BYREF
  void *v31; // [rsp+18h] [rbp-70h] BYREF
  void *v32; // [rsp+20h] [rbp-68h] BYREF
  void *ptr; // [rsp+28h] [rbp-60h] BYREF
  unsigned long long v34; // [rsp+30h] [rbp-58h] BYREF
  long long v35; // [rsp+38h] [rbp-50h] BYREF
  void *v36[9]; // [rsp+40h] [rbp-48h] BYREF

  v36[1] = (void *)__readfsqword(0x28u);
  v4 = *(long long **)(a2 + 128);
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  ptr = 0;
  v34 = 0;
  v35 = 0;
  if ( !(unsigned int)sub_1AAD0(*v4, a3, a4) )
  {
    if ( !(unsigned int)sub_19C10(a1, *(long long *)(a2 + 128) + 16LL)
      && !(unsigned int)sub_19CD0(a1, *(long long *)(a2 + 128) + 8LL, v6, v7, v8, v9)
      && !(unsigned int)sub_1A6F0(a1, *(long long *)(a2 + 128) + 24LL, &v35)
      && !(unsigned int)sub_1B8A0(a1, &v29)
      && !(unsigned int)sub_19C10(a1, *(long long *)(a2 + 128) + 48LL)
      && !(unsigned int)sub_19C10(a1, *(long long *)(a2 + 128) + 56LL)
      && !(unsigned int)sub_1B8A0(a1, &v30)
      && !(unsigned int)sub_1B8A0(a1, &v31)
      && !(unsigned int)sub_1A460(a1, 0, 0)
      && !(unsigned int)sub_1B8A0(a1, &v32) )
    {
      sub_C3D0(**(long long **)(a2 + 128));
      v11 = v10;
      v12 = sub_C3D0(a1);
      v14 = v13;
      if ( !(unsigned int)sub_1A590(a1, &ptr, &v34, v12)
        && (unsigned int)(*(int *)(*(long long *)(a2 + 128) + 8LL) - 1) <= 1 )
      {
        while ( 1 )
        {
          v20 = sub_C3D0((long long)v29);
          if ( !v21 )
            break;
          v36[0] = 0;
          if ( *(int *)(*(long long *)(a2 + 128) + 32LL) > 0xFFu || (unsigned int)sub_1A6F0(v29, v36, 0) )
            goto LABEL_5;
          v15 = *(long long *)(a2 + 128);
          v16 = *(void **)(v15 + 40);
          *(long long *)(v15 + 40) = sub_3BA50(v16);
          v17 = *(long long *)(a2 + 128);
          v18 = *(long long *)(v17 + 40);
          if ( !v18 )
          {
            free(v36[0]);
            *(long long *)(*(long long *)(a2 + 128) + 40LL) = v16;
            goto LABEL_5;
          }
          v19 = *(unsigned int *)(v17 + 32);
          *(int *)(v17 + 32) = v19 + 1;
          *(void **)(v18 + 8 * v19) = v36[0];
        }
        if ( !(unsigned int)sub_1AAD0(*(long long *)(*(long long *)(a2 + 128) + 64LL), v30, v20)
          && (!v31 || !(unsigned int)sub_1AAD0(*(long long *)(*(long long *)(a2 + 128) + 72LL), v31, v20)) )
        {
          while ( 1 )
          {
            sub_C3D0((long long)v30);
            if ( !v22 )
              break;
            if ( (unsigned int)sub_1A460(v30, 0, 0) || (unsigned int)sub_1A460(v30, 0, 0) )
            {
              sub_BE60(*(long long *)(*(long long *)(a2 + 128) + 64LL));
              goto LABEL_5;
            }
          }
          while ( v31 )
          {
            sub_C3D0((long long)v31);
            if ( !v23 )
              break;
            if ( (unsigned int)sub_1A460(v31, 0, 0) || (unsigned int)sub_1A460(v31, 0, 0) )
            {
              sub_BE60(*(long long *)(*(long long *)(a2 + 128) + 72LL));
              goto LABEL_5;
            }
          }
          sub_14780((long long)v32, (long long *)(*(long long *)(a2 + 128) + 80LL), 0);
          if ( !v24 )
          {
            v25 = *(long long **)(a2 + 128);
            sub_D300();
            if ( v26 )
            {
              sub_C520(*v25);
              sub_13150(*(int **)(*(long long *)(a2 + 128) + 80LL), (long long)ptr, v34, v27, v11 - v14, 0, 0, 0);
              if ( !v28 )
                sub_12C20((long long)ptr, v34, (long long *)(*(long long *)(a2 + 128) + 88LL));
            }
          }
        }
      }
    }
LABEL_5:
    sub_BCE0(v32);
    sub_BCE0(v30);
    sub_BCE0(v31);
    sub_BCE0(v29);
    free(ptr);
  }
  return 0.0;
}


// Function: sshkey_fromb @ 0x153a0
double sshkey_fromb(long long a1, long long *a2)
{
  return sub_14780(a1, a2, 1);
}


// Function: sshkey_read @ 0x153b0
double sshkey_read(long long a1, const char **a2)
{
  int v2; // ecx
  char *v4; // r15
  size_t v5; // r14
  unsigned int v6; // ebp
  const char *v7; // r14
  char v8; // al
  double v9; // xmm0_8
  long long *v10; // rax
  long long *v11; // r13
  size_t v12; // r15
  char *v13; // rax
  char *v14; // rdi
  int v15; // eax
  const char *v16; // r13
  char v17; // al
  long long *v18; // r15
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v23; // eax
  long long **v24; // rdi
  int ptr; // [rsp+8h] [rbp-60h]
  void *v26[9]; // [rsp+20h] [rbp-48h] BYREF

  v26[1] = (void *)__readfsqword(0x28u);
  if ( a1 )
  {
    v2 = *(int *)a1;
    if ( *(int *)a1 <= 7 )
    {
      if ( v2 < 0 )
        return 0.0;
    }
    else if ( (unsigned int)(v2 - 10) > 4 )
    {
      return 0.0;
    }
    ptr = *(int *)a1;
    v4 = (char *)*a2;
    v5 = strcspn(*a2, " \t");
    if ( strlen(v4) != v5 )
    {
      v6 = sub_E6E0(v4, v5);
      if ( v6 != 14 )
      {
        v7 = &v4[v5];
        v8 = *v7;
        if ( *v7 == 9 || v8 == 32 )
        {
          do
          {
            do
              v8 = *++v7;
            while ( v8 == 32 );
          }
          while ( v8 == 9 );
        }
        if ( v8 && (ptr == v6 || ptr == 14) )
        {
          v9 = sub_B880();
          v11 = v10;
          if ( v10 )
          {
            v12 = strcspn(v7, " \t");
            v13 = strndup(v7, v12);
            if ( !v13 )
            {
              sub_BCE0(v11);
              return 0.0;
            }
            v14 = v13;
            if ( (unsigned int)sub_1C390(v11, v13, v9) )
            {
              free(v14);
              sub_BCE0(v11);
              return 0.0;
            }
            free(v14);
            sub_153A0((long long)v11, (long long *)v26);
            if ( v15 )
            {
              sub_BCE0(v11);
              return 0.0;
            }
            sub_BCE0(v11);
            v16 = &v7[v12];
            v17 = v7[v12];
            if ( v17 != 32 )
              goto LABEL_19;
            do
            {
              do
                v17 = *++v16;
              while ( v17 == 32 );
LABEL_19:
              ;
            }
            while ( v17 == 9 );
            v18 = v26[0];
            if ( *(int *)v26[0] != v6 )
            {
              sub_10A60(v26[0]);
              return 0.0;
            }
            sub_D1E0();
            if ( !v19 || *((int *)v18 + 6) == -1 )
            {
              *(int *)a1 = v6;
              sub_F3B0((int *)a1);
              if ( !v20 )
              {
LABEL_24:
                sub_F440(v6);
                switch ( v21 )
                {
                  case 0:
                    RSA_free(*(long long *)(a1 + 8));
                    *(long long *)(a1 + 8) = v18[1];
                    v18[1] = 0;
                    break;
                  case 1:
                    DSA_free(*(long long *)(a1 + 16));
                    *(long long *)(a1 + 16) = v18[2];
                    v18[2] = 0;
                    break;
                  case 2:
                    EC_KEY_free(*(long long *)(a1 + 32));
                    *(long long *)(a1 + 32) = v18[4];
                    *(int *)(a1 + 24) = *((int *)v18 + 6);
                    v18[4] = 0;
                    *((int *)v18 + 6) = -1;
                    break;
                  case 3:
                    sub_3B0D0(*(void **)(a1 + 48));
                    *(long long *)(a1 + 48) = v18[6];
                    v18[6] = 0;
                    break;
                  case 10:
                    EC_KEY_free(*(long long *)(a1 + 32));
                    *(long long *)(a1 + 32) = v18[4];
                    *(int *)(a1 + 24) = *((int *)v18 + 6);
                    *(long long *)(a1 + 96) = v18[12];
                    v18[4] = 0;
                    *((int *)v18 + 6) = -1;
                    v18[12] = 0;
                    break;
                  case 12:
                    sub_3B0D0(*(void **)(a1 + 48));
                    *(long long *)(a1 + 48) = v18[6];
                    *(long long *)(a1 + 96) = v18[12];
                    v18[6] = 0;
                    v18[12] = 0;
                    break;
                  default:
                    goto LABEL_44;
                }
                sub_10A60(v18);
                *a2 = v16;
                return 0.0;
              }
              sub_F3B0((int *)v18);
              if ( v23 )
              {
                v24 = *(long long ***)(a1 + 128);
                if ( v24 )
                  sub_10C30(v24);
                *(long long *)(a1 + 128) = v18[16];
                v18[16] = 0;
                v6 = *(int *)a1;
                goto LABEL_24;
              }
            }
LABEL_44:
            sub_10A60(v18);
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: sshkey_froms @ 0x15840
double sshkey_froms(long long a1, long long *a2)
{
  void *ptr[5]; // [rsp+0h] [rbp-28h] BYREF

  ptr[1] = (void *)__readfsqword(0x28u);
  if ( !(unsigned int)sub_1B8A0(a1, ptr) )
  {
    sub_14780((long long)ptr[0], a2, 1);
    sub_BCE0((long long *)ptr[0]);
  }
  return 0.0;
}


// Function: sshkey_parse_private2_pubkey @ 0x15930
double sshkey_parse_private2_pubkey(long long a1, unsigned int a2, long long *a3)
{
  int v4; // eax
  long long *v5; // r14
  unsigned int *v6; // r13
  int v8; // eax
  long long v9; // rdx
  long long v10; // rcx
  long long v11; // r8
  long long v12; // r9
  int v13; // eax
  int v14; // eax
  int v15; // ebp
  int v16; // eax
  int v17; // [rsp+4h] [rbp-44h] BYREF
  void *ptr; // [rsp+8h] [rbp-40h] BYREF
  long long v19[7]; // [rsp+10h] [rbp-38h] BYREF

  v19[1] = __readfsqword(0x28u);
  v17 = 0;
  ptr = 0;
  v19[0] = 0;
  if ( a3 )
    *a3 = 0;
  v4 = sub_E4A0(a1, &ptr);
  v5 = ptr;
  if ( v4 )
    goto LABEL_4;
  v6 = 0;
  sub_CC80((long long)ptr, 0xFu);
  if ( !v8
    && !(unsigned int)sub_1A460(v5, 0, 0)
    && !(unsigned int)sub_1A460(v5, 0, 0)
    && !(unsigned int)sub_1A460(v5, 0, 0)
    && !(unsigned int)sub_19CD0(v5, &v17, v9, v10, v11, v12)
    && v17 == 1 )
  {
    sub_15840((long long)v5, v19);
    v6 = (unsigned int *)v19[0];
    if ( !v13 )
    {
      if ( a2 == 14 || (sub_F440(a2), v15 = v14, sub_F440(*v6), v15 == v16) )
      {
        if ( a3 )
        {
          *a3 = v6;
LABEL_4:
          v6 = 0;
        }
      }
    }
  }
  sub_BCE0(v5);
  sub_10A60(v6);
  return 0.0;
}


// Function: sshkey_ec_validate_private @ 0x161f0
double sshkey_ec_validate_private(long long a1, double a2)
{
  long long v2; // rbp
  long long v3; // r13
  long long v4; // rax
  long long v5; // rax
  int v6; // ebx
  long long v7; // rax
  long long v8; // rax

  v2 = BN_new();
  if ( v2 && (v3 = BN_new()) != 0 )
  {
    v4 = EC_KEY_get0_group(a1);
    if ( (unsigned int)EC_GROUP_get_order(v4, v2, 0) == 1 )
    {
      v5 = EC_KEY_get0_private_key(a1);
      v6 = BN_num_bits(v5);
      if ( v6 > (int)BN_num_bits(v2) / 2 )
      {
        v7 = BN_value_one();
        if ( (unsigned int)BN_sub(v3, v2, v7) )
        {
          v8 = EC_KEY_get0_private_key(a1);
          BN_cmp(v8, v3);
        }
      }
    }
  }
  else
  {
    v3 = 0;
  }
  BN_clear_free(v2, a2);
  BN_clear_free(v3, a2);
  return 0.0;
}


// Function: sshkey_private_deserialize @ 0x16380
double sshkey_private_deserialize(long long a1, long long *a2, double a3)
{
  unsigned int *v5; // r13
  void *v6; // r15
  char *v7; // r14
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // eax
  unsigned int *v13; // rax
  unsigned int v14; // eax
  int v15; // eax
  long long v16; // rax
  long long v17; // rax
  long long v18; // rax
  void *v19; // rax
  const char *v20; // rsi
  const void *v21; // rsi
  void *v22; // rax
  void *v23; // rax
  long long v24; // rdi
  int v25; // eax
  long long v26; // rcx
  long long v27; // r8
  long long v28; // r9
  long long v29; // rdi
  long long v30; // rcx
  long long v31; // r8
  long long v32; // r9
  long long v33; // rax
  long long v34; // rax
  long long v35; // rbp
  long long v36; // rax
  int v37; // eax
  unsigned int v38; // eax
  int v39; // eax
  long long v40; // rax
  long long v41; // rax
  long long v42; // rax
  long long v43; // rbp
  long long v44; // rax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  unsigned int v48; // [rsp+Ch] [rbp-DCh]
  unsigned int v49; // [rsp+Ch] [rbp-DCh]
  void *ptr; // [rsp+10h] [rbp-D8h] BYREF
  char *s1; // [rsp+18h] [rbp-D0h] BYREF
  unsigned int *v52; // [rsp+20h] [rbp-C8h] BYREF
  long long v53; // [rsp+28h] [rbp-C0h] BYREF
  long long v54; // [rsp+30h] [rbp-B8h] BYREF
  void *v55; // [rsp+38h] [rbp-B0h] BYREF
  void *v56; // [rsp+40h] [rbp-A8h] BYREF
  long long v57; // [rsp+48h] [rbp-A0h] BYREF
  long long v58; // [rsp+50h] [rbp-98h] BYREF
  long long v59; // [rsp+58h] [rbp-90h] BYREF
  long long v60; // [rsp+60h] [rbp-88h] BYREF
  long long v61; // [rsp+68h] [rbp-80h] BYREF
  long long v62; // [rsp+70h] [rbp-78h] BYREF
  long long v63; // [rsp+78h] [rbp-70h] BYREF
  long long v64; // [rsp+80h] [rbp-68h] BYREF
  long long v65; // [rsp+88h] [rbp-60h] BYREF
  long long v66; // [rsp+90h] [rbp-58h] BYREF
  long long v67; // [rsp+98h] [rbp-50h] BYREF
  long long v68[9]; // [rsp+A0h] [rbp-48h] BYREF

  v68[1] = __readfsqword(0x28u);
  ptr = 0;
  s1 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  v62 = 0;
  v63 = 0;
  v64 = 0;
  v65 = 0;
  v66 = 0;
  v67 = 0;
  v68[0] = 0;
  if ( a2 )
    *a2 = 0;
  if ( (unsigned int)sub_1A6F0(a1, &ptr, 0) )
  {
    v5 = 0;
    v6 = 0;
    v7 = 0;
  }
  else
  {
    sub_EB00((char *)ptr);
    v48 = v9;
    sub_E9C0(v9);
    if ( v10 )
    {
      a3 = sub_15840(a1, (long long *)&v52);
      v5 = v52;
      v11 = v48;
      if ( v12 )
      {
        v6 = 0;
        v7 = 0;
        goto LABEL_5;
      }
      if ( *v52 != v48 || v48 == 2 && (a3 = sub_EBF0((char *)ptr), v11 = 2, v5[6] != v47) )
      {
        v6 = 0;
        v7 = 0;
        goto LABEL_5;
      }
      v7 = (char *)*((long long *)v5 + 12);
      v6 = (void *)*((long long *)v5 + 6);
      *((long long *)v5 + 12) = 0;
      *((long long *)v5 + 6) = 0;
    }
    else
    {
      v6 = 0;
      v7 = 0;
      a3 = sub_10ED0(v48);
      v52 = v13;
      v5 = v13;
      if ( !v13 )
        goto LABEL_5;
      v11 = v48;
    }
    switch ( v11 )
    {
      case 0:
        if ( !(unsigned int)sub_1D220(a1, &v58, a3)
          && !(unsigned int)sub_1D220(a1, &v59, a3)
          && (unsigned int)RSA_set0_key(*((long long *)v5 + 1), v58, v59, 0) )
        {
          v59 = 0;
          v58 = 0;
          goto LABEL_49;
        }
        break;
      case 1:
        if ( !(unsigned int)sub_1D220(a1, &v64, a3)
          && !(unsigned int)sub_1D220(a1, &v65, a3)
          && !(unsigned int)sub_1D220(a1, &v66, a3)
          && !(unsigned int)sub_1D220(a1, &v67, a3) )
        {
          if ( (unsigned int)DSA_set0_pqg(*((long long *)v5 + 2), v64, v65, v66) )
          {
            v29 = *((long long *)v5 + 2);
            v66 = 0;
            v65 = 0;
            v64 = 0;
            if ( (unsigned int)DSA_set0_key(v29, v67, 0, v26, v27, v28) )
            {
              v67 = 0;
              goto LABEL_65;
            }
          }
        }
        break;
      case 2:
        a3 = sub_EBF0((char *)ptr);
        v5[6] = v14;
        if ( v14 != -1 && !(unsigned int)sub_1A6F0(a1, &s1, 0) )
        {
          v49 = v5[6];
          a3 = sub_FA00(s1);
          if ( v49 == v15 )
          {
            v16 = EC_KEY_new_by_curve_name(v49, a3);
            *((long long *)v5 + 4) = v16;
            if ( v16 )
            {
              if ( !(unsigned int)sub_1D480(a1, v16) )
                goto LABEL_20;
            }
          }
        }
        break;
      case 3:
      case 7:
        if ( !(unsigned int)sub_1A590(a1, &v55, &v53, a3)
          && !(unsigned int)sub_1A590(a1, &v56, &v54, a3)
          && v53 == 32
          && v54 == 64 )
        {
          v22 = v55;
          v55 = 0;
          *((long long *)v5 + 6) = v22;
          v23 = v56;
          v56 = 0;
          *((long long *)v5 + 5) = v23;
          goto LABEL_31;
        }
        break;
      case 4:
LABEL_49:
        if ( !(unsigned int)sub_1D220(a1, &v60, a3)
          && !(unsigned int)sub_1D220(a1, &v61, a3)
          && !(unsigned int)sub_1D220(a1, &v62, a3)
          && !(unsigned int)sub_1D220(a1, &v63, a3) )
        {
          if ( (unsigned int)RSA_set0_key(*((long long *)v5 + 1), 0, 0, v60) )
          {
            v24 = *((long long *)v5 + 1);
            v60 = 0;
            if ( (unsigned int)RSA_set0_factors(v24, v62, v63) )
            {
              v63 = 0;
              v62 = 0;
              a3 = sub_12B10((long long)v5);
              if ( !v25 && !(unsigned int)sub_2E2E0(v5, v61, a3) )
                goto LABEL_31;
            }
          }
        }
        break;
      case 5:
LABEL_65:
        if ( !(unsigned int)sub_1D220(a1, v68, a3)
          && (unsigned int)DSA_set0_key(*((long long *)v5 + 2), 0, v68[0], v30, v31, v32) )
        {
          v68[0] = 0;
          goto LABEL_31;
        }
        break;
      case 6:
LABEL_20:
        if ( !(unsigned int)sub_1D220(a1, &v57, a3)
          && (unsigned int)EC_KEY_set_private_key(*((long long *)v5 + 4), v57) == 1 )
        {
          v43 = EC_KEY_get0_public_key(a3);
          v44 = EC_KEY_get0_group(*((long long *)v5 + 4));
          a3 = sub_14460(v44, v43, a3);
          if ( !v45 )
          {
            a3 = sub_161F0(*((long long *)v5 + 4), a3);
            if ( !v46 )
              goto LABEL_31;
          }
        }
        break;
      case 10:
        a3 = sub_EBF0((char *)ptr);
        v5[6] = v38;
        if ( v38 != -1 && !(unsigned int)sub_1A6F0(a1, &s1, 0) )
        {
          a3 = sub_FA00(s1);
          if ( v5[6] == v39 )
          {
            a3 = sub_B880();
            *((long long *)v5 + 14) = v40;
            if ( v40 )
            {
              a3 = sub_B880();
              *((long long *)v5 + 15) = v41;
              if ( v41 )
              {
                v42 = EC_KEY_new_by_curve_name(v5[6], a3);
                *((long long *)v5 + 4) = v42;
                if ( v42 )
                {
                  if ( !(unsigned int)sub_1D480(a1, v42) )
                    goto LABEL_70;
                }
              }
            }
          }
        }
        break;
      case 11:
        a3 = sub_B880();
        *((long long *)v5 + 14) = v33;
        if ( v33 )
        {
          a3 = sub_B880();
          *((long long *)v5 + 15) = v34;
          if ( v34 )
          {
LABEL_70:
            if ( !(unsigned int)sub_1A6F0(a1, v5 + 24, 0)
              && !(unsigned int)sub_19E50(a1, v5 + 26)
              && !(unsigned int)sub_1A8B0(a1, *((long long *)v5 + 14), a3)
              && !(unsigned int)sub_1A8B0(a1, *((long long *)v5 + 15), a3) )
            {
              v35 = EC_KEY_get0_public_key(a3);
              v36 = EC_KEY_get0_group(*((long long *)v5 + 4));
              a3 = sub_14460(v36, v35, a3);
              if ( !v37 )
                goto LABEL_31;
            }
          }
        }
        break;
      case 12:
      case 13:
        if ( !(unsigned int)sub_1A590(a1, &v55, &v53, a3) && v53 == 32 )
        {
          a3 = sub_B880();
          *((long long *)v5 + 14) = v17;
          if ( v17 )
          {
            a3 = sub_B880();
            *((long long *)v5 + 15) = v18;
            if ( v18 )
            {
              if ( !(unsigned int)sub_1A6F0(a1, v5 + 24, 0)
                && !(unsigned int)sub_19E50(a1, v5 + 26)
                && !(unsigned int)sub_1A8B0(a1, *((long long *)v5 + 14), a3)
                && !(unsigned int)sub_1A8B0(a1, *((long long *)v5 + 15), a3) )
              {
                v19 = v55;
                v55 = 0;
                *((long long *)v5 + 6) = v19;
LABEL_31:
                if ( ((*v5 & 0xFFFFFFFB) != 0 || (unsigned int)RSA_blinding_on(*((long long *)v5 + 1), 0) == 1)
                  && (!v7 || (v20 = (const char *)*((long long *)v5 + 12)) != 0 && !strcmp(v7, v20))
                  && (!v6 || (v21 = (const void *)*((long long *)v5 + 6)) != 0 && !memcmp(v6, v21, 0x20u)) )
                {
                  if ( a2 )
                  {
                    *a2 = v5;
                    v5 = 0;
                  }
                }
              }
            }
          }
        }
        break;
      default:
        break;
    }
  }
LABEL_5:
  free(ptr);
  free(s1);
  BN_clear_free(v57, a3);
  BN_clear_free(v64, a3);
  BN_clear_free(v65, a3);
  BN_clear_free(v66, a3);
  BN_clear_free(v67, a3);
  BN_clear_free(v68[0], a3);
  BN_clear_free(v58, a3);
  BN_clear_free(v59, a3);
  BN_clear_free(v60, a3);
  BN_clear_free(v62, a3);
  BN_clear_free(v63, a3);
  BN_clear_free(v61, a3);
  sub_10A60(v5);
  sub_3B0D0(v55);
  sub_3B0D0(v56);
  free(0);
  sub_3B0D0(0);
  sub_3B0D0(0);
  free(v7);
  free(v6);
  return 0.0;
}


// Function: sshkey_unshield_private @ 0x16d90
double sshkey_unshield_private(long long *a1)
{
  double v2; // xmm0_8
  int v3; // eax
  long long v5; // rax
  long long *v6; // r13
  int v7; // ebx
  int v8; // r12d
  int *v9; // r14
  unsigned long long v10; // rbx
  unsigned long long v11; // rbx
  int v12; // r14d
  long long v13; // r12
  int v14; // eax
  long long *v15; // rax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int *v19; // rdi
  long long v20; // rcx
  int *v21; // rsi
  long long v22; // rcx
  int *v23; // rdi
  int *v24; // rsi
  long long v25; // rcx
  int *v26; // rdi
  int *v27; // rsi
  long long v28; // [rsp+8h] [rbp-150h] BYREF
  void *ptr; // [rsp+10h] [rbp-148h] BYREF
  int *v30; // [rsp+18h] [rbp-140h] BYREF
  char v31[176]; // [rsp+20h] [rbp-138h] BYREF
  char v32[72]; // [rsp+D0h] [rbp-88h] BYREF
  unsigned long long v33; // [rsp+118h] [rbp-40h]

  v33 = __readfsqword(0x28u);
  ptr = 0;
  v30 = 0;
  v2 = sub_12A70();
  if ( v3 )
  {
    v5 = sub_1DFF0("aes256-ctr");
    v6 = (long long *)v5;
    if ( v5 )
    {
      v7 = sub_1DBF0(v5, v2);
      v8 = sub_1DDC0(v6);
      if ( (unsigned int)(v7 + v8) <= (unsigned long long)sub_30050(4) )
      {
        v10 = a1[18];
        if ( v10 < (unsigned int)sub_1DB60(v6) || (v11 = a1[18], v11 % (unsigned int)sub_1DB60(v6)) )
        {
          v9 = 0;
          v6 = 0;
        }
        else if ( (unsigned int)sub_30740(4, a1[19], a1[20], v32, 64)
               || (v12 = sub_1DDC0(v6),
                   v13 = (unsigned int)sub_1DBF0(v6, v2),
                   v14 = sub_1DBF0(v6, v2),
                   (unsigned int)sub_1E340(
                                   (unsigned int)&ptr,
                                   (int)v6,
                                   (unsigned int)v32,
                                   v14,
                                   (unsigned int)&v32[v13],
                                   v12,
                                   0)) )
        {
          v9 = 0;
          v6 = 0;
        }
        else
        {
          v2 = sub_B880();
          v6 = v15;
          if ( v15 )
          {
            v2 = sub_CB20(v15, a1[18], &v28);
            if ( v16 || (unsigned int)sub_1E5A0(ptr, 0, v28, a1[17], *((unsigned int *)a1 + 36), 0, v2, 0) )
            {
              v9 = 0;
            }
            else
            {
              v2 = sub_16380((long long)v6, &v30, v2);
              if ( v17 )
              {
                v9 = v30;
              }
              else
              {
                v2 = sub_E200((long long)v6);
                v9 = v30;
                if ( !v18 )
                {
                  v19 = v31;
                  v20 = 42;
                  v21 = v30;
                  while ( v20 )
                  {
                    *v19++ = *v21++;
                    --v20;
                  }
                  v22 = 42;
                  v23 = v9;
                  v24 = a1;
                  while ( v22 )
                  {
                    *v23++ = *v24++;
                    --v22;
                  }
                  v25 = 42;
                  v26 = a1;
                  v27 = v31;
                  while ( v25 )
                  {
                    *v26++ = *v27++;
                    --v25;
                  }
                }
              }
            }
          }
          else
          {
            v9 = 0;
          }
        }
      }
      else
      {
        v9 = 0;
        v6 = 0;
      }
    }
    else
    {
      v9 = 0;
    }
    sub_1E970(ptr);
    __explicit_bzero_chk(v32, 64, 64, v2);
    __explicit_bzero_chk(v31, 168, 168, v2);
    sub_10A60(v9);
    sub_BCE0(v6);
  }
  return 0.0;
}


// Function: sshkey_private_serialize_opt @ 0x17120
double sshkey_private_serialize_opt(long long a1, long long a2)
{
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  long long *v7; // rax
  long long *v8; // r14
  double v9; // xmm0_8
  long long v10; // rax
  long long *v11; // rax
  long long v12; // rax
  long long *v13; // rax
  long long v14; // rax
  long long *v15; // rax
  long long v16; // rax
  long long v17; // rsi
  long long *v18; // rax
  long long v19; // rax
  long long *v20; // rax
  long long v21; // rax
  long long *v22; // rax
  long long v23; // rax
  long long v24; // rax
  long long v25; // rax
  long long v26; // [rsp+0h] [rbp-88h] BYREF
  long long v27; // [rsp+8h] [rbp-80h] BYREF
  long long v28; // [rsp+10h] [rbp-78h] BYREF
  long long v29; // [rsp+18h] [rbp-70h] BYREF
  long long v30; // [rsp+20h] [rbp-68h] BYREF
  long long v31; // [rsp+28h] [rbp-60h] BYREF
  long long v32; // [rsp+30h] [rbp-58h] BYREF
  long long v33; // [rsp+38h] [rbp-50h] BYREF
  long long v34; // [rsp+40h] [rbp-48h] BYREF
  long long v35; // [rsp+48h] [rbp-40h] BYREF
  long long v36[7]; // [rsp+50h] [rbp-38h] BYREF

  v36[1] = __readfsqword(0x28u);
  sub_12A70();
  v4 = v3;
  sub_16D90((long long *)a1);
  if ( !v5 )
  {
    sub_B880();
    v8 = v7;
    if ( v7 )
    {
      v9 = sub_EAF0((int *)a1);
      if ( !(unsigned int)sub_1B800(v8, v10) )
      {
        switch ( *(int *)a1 )
        {
          case 0:
            RSA_get0_key(*(long long *)(a1 + 8), &v26, &v27, &v28);
            RSA_get0_factors(*(long long *)(a1 + 8), &v30, &v31, v9);
            v9 = RSA_get0_crt_params(*(long long *)(a1 + 8), 0, 0, &v29);
            if ( (unsigned int)sub_1D610(v8, v26, v9) || (unsigned int)sub_1D610(v8, v27, v9) )
              break;
            goto LABEL_32;
          case 1:
            DSA_get0_pqg(*(long long *)(a1 + 16), &v32, &v33, &v34);
            DSA_get0_key(*(long long *)(a1 + 16), &v35, v36, v9);
            if ( (unsigned int)sub_1D610(v8, v32, v9)
              || (unsigned int)sub_1D610(v8, v33, v9)
              || (unsigned int)sub_1D610(v8, v34, v9)
              || (unsigned int)sub_1D610(v8, v35, v9) )
            {
              break;
            }
            goto LABEL_41;
          case 2:
            v9 = sub_10400();
            if ( (unsigned int)sub_1B800(v8, v25) || (unsigned int)sub_1D940(v8, *(long long *)(a1 + 32), v9) )
              break;
            goto LABEL_45;
          case 3:
            goto LABEL_26;
          case 4:
            v15 = *(long long **)(a1 + 128);
            if ( !v15 )
              goto LABEL_10;
            v9 = sub_C3D0(*v15);
            if ( !v16 )
              goto LABEL_10;
            RSA_get0_key(*(long long *)(a1 + 8), 0, 0, &v28);
            RSA_get0_factors(*(long long *)(a1 + 8), &v30, &v31, v9);
            RSA_get0_crt_params(*(long long *)(a1 + 8), 0, 0, &v29);
            if ( (unsigned int)sub_1B840(v8, **(long long **)(a1 + 128)) )
              break;
LABEL_32:
            if ( (unsigned int)sub_1D610(v8, v28, v9)
              || (unsigned int)sub_1D610(v8, v29, v9)
              || (unsigned int)sub_1D610(v8, v30, v9) )
            {
              break;
            }
            v17 = v31;
LABEL_36:
            if ( (unsigned int)sub_1D610(v8, v17, v9) )
              break;
            goto LABEL_21;
          case 5:
            v18 = *(long long **)(a1 + 128);
            if ( !v18 )
              goto LABEL_10;
            v9 = sub_C3D0(*v18);
            if ( !v19 )
              goto LABEL_10;
            DSA_get0_key(*(long long *)(a1 + 16), 0, v36, v9);
            if ( (unsigned int)sub_1B840(v8, **(long long **)(a1 + 128)) )
              break;
LABEL_41:
            v17 = v36[0];
            goto LABEL_36;
          case 6:
            v20 = *(long long **)(a1 + 128);
            if ( !v20 )
              goto LABEL_10;
            v9 = sub_C3D0(*v20);
            if ( !v21 )
              goto LABEL_10;
            if ( (unsigned int)sub_1B840(v8, **(long long **)(a1 + 128)) )
              break;
LABEL_45:
            v17 = EC_KEY_get0_private_key(*(long long *)(a1 + 32));
            goto LABEL_36;
          case 7:
            v13 = *(long long **)(a1 + 128);
            if ( !v13 )
              goto LABEL_10;
            v9 = sub_C3D0(*v13);
            if ( !v14 )
              goto LABEL_10;
            if ( (unsigned int)sub_1B840(v8, **(long long **)(a1 + 128)) )
              break;
LABEL_26:
            if ( (unsigned int)sub_1B6C0(v8, *(long long *)(a1 + 48), 32)
              || (unsigned int)sub_1B6C0(v8, *(long long *)(a1 + 40), 64) )
            {
              break;
            }
            goto LABEL_21;
          case 0xA:
            v9 = sub_10400();
            if ( (unsigned int)sub_1B800(v8, v24) || (unsigned int)sub_1D940(v8, *(long long *)(a1 + 32), v9) )
              break;
            goto LABEL_17;
          case 0xB:
            v22 = *(long long **)(a1 + 128);
            if ( !v22 )
              goto LABEL_10;
            v9 = sub_C3D0(*v22);
            if ( !v23 )
              goto LABEL_10;
            if ( !(unsigned int)sub_1B840(v8, **(long long **)(a1 + 128)) )
              goto LABEL_17;
            break;
          case 0xC:
            goto LABEL_16;
          case 0xD:
            v11 = *(long long **)(a1 + 128);
            if ( !v11 )
              goto LABEL_10;
            v9 = sub_C3D0(*v11);
            if ( !v12 )
              goto LABEL_10;
            if ( (unsigned int)sub_1B840(v8, **(long long **)(a1 + 128)) )
              break;
LABEL_16:
            if ( (unsigned int)sub_1B6C0(v8, *(long long *)(a1 + 48), 32) )
              break;
LABEL_17:
            if ( (unsigned int)sub_1B800(v8, *(long long *)(a1 + 96))
              || (unsigned int)sub_1B180(v8, *(unsigned char *)(a1 + 104))
              || (unsigned int)sub_1B840(v8, *(long long *)(a1 + 112))
              || (unsigned int)sub_1B840(v8, *(long long *)(a1 + 120)) )
            {
              break;
            }
LABEL_21:
            if ( v4 )
              goto LABEL_11;
            goto LABEL_12;
          default:
LABEL_10:
            if ( v4 )
              goto LABEL_11;
            goto LABEL_9;
        }
      }
      if ( v4 )
      {
LABEL_11:
        if ( !(unsigned int)sub_17750(a1, v9) )
LABEL_12:
          sub_1AAD0(a2, v8, v9);
      }
LABEL_9:
      sub_BCE0(v8);
    }
  }
  return 0.0;
}


// Function: sshkey_shield_private @ 0x17750
double sshkey_shield_private(__m128i *a1, __m128i a2)
{
  long long v2; // rax
  void *v3; // rbp
  int v4; // r13d
  int v5; // r12d
  void *v6; // rax
  void *v7; // r13
  __m128i *v8; // r15
  long long *v9; // rbx
  int v11; // r15d
  long long v12; // r12
  int v13; // eax
  long long *v14; // rax
  int v15; // eax
  int v16; // eax
  unsigned long long v17; // rax
  size_t v18; // rax
  unsigned int v19; // eax
  unsigned int v20; // r12d
  long long v21; // rax
  int v22; // eax
  __m128i v23; // xmm2
  __m128i v24; // xmm7
  __m128i v25; // xmm1
  __m128i v26; // xmm2
  __m128i v27; // xmm3
  __m128i v28; // xmm4
  __m128i v29; // xmm5
  __m128i si128; // xmm6
  int v31; // eax
  size_t v32; // [rsp+18h] [rbp-150h]
  void *ptr; // [rsp+20h] [rbp-148h] BYREF
  __m128i *v34; // [rsp+28h] [rbp-140h] BYREF
  __m128i v35; // [rsp+30h] [rbp-138h] BYREF
  __m128i v36; // [rsp+40h] [rbp-128h] BYREF
  __m128i v37; // [rsp+50h] [rbp-118h] BYREF
  __m128i v38; // [rsp+60h] [rbp-108h] BYREF
  __m128i v39; // [rsp+70h] [rbp-F8h] BYREF
  __m128i v40; // [rsp+80h] [rbp-E8h] BYREF
  __m128i v41; // [rsp+90h] [rbp-D8h] BYREF
  __m128i v42; // [rsp+A0h] [rbp-C8h] BYREF
  __m128i v43[2]; // [rsp+B0h] [rbp-B8h] BYREF
  long long v44; // [rsp+D0h] [rbp-98h]
  char v45[72]; // [rsp+E0h] [rbp-88h] BYREF
  unsigned long long v46; // [rsp+128h] [rbp-40h]

  v46 = __readfsqword(0x28u);
  ptr = 0;
  v34 = 0;
  v2 = sub_1DFF0("aes256-ctr");
  v3 = (void *)v2;
  if ( !v2 )
  {
    v8 = 0;
    v7 = 0;
    v9 = 0;
    goto LABEL_6;
  }
  v4 = sub_1DBF0(v2, *(double *)a2.m128i_i64);
  v5 = sub_1DDC0(v3);
  if ( (unsigned int)(v4 + v5) > (unsigned long long)sub_30050(4) )
  {
    v8 = 0;
    v3 = 0;
    v7 = 0;
    v9 = 0;
    goto LABEL_6;
  }
  v6 = malloc(0x4000u);
  v7 = v6;
  if ( !v6 )
  {
    v8 = 0;
    v3 = 0;
    v9 = 0;
    goto LABEL_6;
  }
  sub_38B20(v6);
  if ( (unsigned int)sub_30740(4, v7, 0x4000, v45, 64)
    || (v11 = sub_1DDC0(v3),
        v12 = (unsigned int)sub_1DBF0(v3, *(double *)a2.m128i_i64),
        v13 = sub_1DBF0(v3, *(double *)a2.m128i_i64),
        (unsigned int)sub_1E340((unsigned int)&ptr, (int)v3, (unsigned int)v45, v13, (unsigned int)&v45[v12], v11, 1)) )
  {
    v8 = 0;
    v3 = 0;
    v9 = 0;
  }
  else
  {
    *(double *)a2.m128i_i64 = sub_B880();
    v9 = v14;
    if ( !v14 )
    {
      v8 = 0;
      v3 = 0;
      goto LABEL_6;
    }
    sub_12A70();
    if ( v15 )
    {
      *(double *)a2.m128i_i64 = sub_16D90(a1);
      if ( v31 )
      {
LABEL_19:
        v8 = 0;
LABEL_20:
        v3 = 0;
        goto LABEL_6;
      }
    }
    v8 = 0;
    *(double *)a2.m128i_i64 = sub_17120((long long)a1, (long long)v9);
    if ( v16 )
      goto LABEL_20;
    while ( 1 )
    {
      *(double *)a2.m128i_i64 = sub_C3D0((long long)v9);
      if ( !(v17 % (unsigned int)sub_1DB60(v3)) )
        break;
      v8 = (__m128i *)((char *)v8 + 1);
      if ( (unsigned int)sub_1B180(v9, (unsigned char)v8) )
        goto LABEL_19;
    }
    *(double *)a2.m128i_i64 = sub_C3D0((long long)v9);
    v32 = v18;
    v3 = malloc(v18);
    if ( v3 )
    {
      v8 = 0;
      sub_C3D0((long long)v9);
      v20 = v19;
      *(double *)a2.m128i_i64 = sub_C520((long long)v9);
      if ( !(unsigned int)sub_1E5A0(ptr, 0, v3, v21, v20, 0, *(double *)a2.m128i_i64, 0) )
      {
        *(double *)a2.m128i_i64 = sub_12300((long long)a1, &v34);
        v8 = v34;
        if ( !v22 )
        {
          v35 = _mm_loadu_si128(v34);
          v36 = _mm_loadu_si128(v34 + 1);
          v37 = _mm_loadu_si128(v34 + 2);
          v23 = _mm_loadu_si128(a1);
          v38 = _mm_loadu_si128(v34 + 3);
          v39 = _mm_loadu_si128(v34 + 4);
          v40 = _mm_loadu_si128(v34 + 5);
          v41 = _mm_loadu_si128(v34 + 6);
          v42 = _mm_loadu_si128(v34 + 7);
          v43[0] = _mm_loadu_si128(v34 + 8);
          v43[1] = _mm_loadu_si128(v34 + 9);
          v44 = v34[10].m128i_i64[0];
          *v34 = v23;
          v8[1] = _mm_loadu_si128(a1 + 1);
          v8[2] = _mm_loadu_si128(a1 + 2);
          v8[3] = _mm_loadu_si128(a1 + 3);
          v8[4] = _mm_loadu_si128(a1 + 4);
          v8[5] = _mm_loadu_si128(a1 + 5);
          v8[6] = _mm_loadu_si128(a1 + 6);
          v8[7] = _mm_loadu_si128(a1 + 7);
          v8[8] = _mm_loadu_si128(a1 + 8);
          v8[9] = _mm_loadu_si128(a1 + 9);
          v8[10].m128i_i64[0] = a1[10].m128i_i64[0];
          v24 = _mm_load_si128(&v36);
          a2 = _mm_load_si128(&v37);
          v25 = _mm_load_si128(&v38);
          v26 = _mm_load_si128(&v39);
          *a1 = _mm_load_si128(&v35);
          v27 = _mm_load_si128(&v40);
          a1[1] = v24;
          v28 = _mm_load_si128(&v41);
          v29 = _mm_load_si128(&v42);
          a1[2] = a2;
          si128 = _mm_load_si128(v43);
          a1[3] = v25;
          a1[8] = si128;
          a1[4] = v26;
          a1[8].m128i_i64[1] = (long long)v3;
          v3 = 0;
          a1[5] = v27;
          a1[6] = v28;
          a1[7] = v29;
          a1[9].m128i_i64[0] = v32;
          a1[9].m128i_i64[1] = (long long)v7;
          v7 = 0;
          a1[10].m128i_i64[0] = 0x4000;
          a1[6].m128i_i8[8] = v8[6].m128i_i8[8];
        }
      }
    }
    else
    {
      v8 = 0;
    }
  }
LABEL_6:
  sub_1E970(ptr);
  __explicit_bzero_chk(v45, 64, 64, *(double *)a2.m128i_i64);
  __explicit_bzero_chk(&v35, 168, 168, *(double *)a2.m128i_i64);
  sub_3B0D0(v3);
  sub_3B0D0(v7);
  sub_10A60(v8);
  sub_BCE0(v9);
  return 0.0;
}


// Function: sshkey_private_serialize @ 0x17d00
double sshkey_private_serialize(long long a1, long long a2)
{
  return sub_17120(a1, a2);
}


// Function: sshkey_private_to_blob2 @ 0x17d10
double sshkey_private_to_blob2(long long a1, long long a2, const char *a3, long long a4, char *a5, int a6)
{
  long long v7; // r14
  long long *v9; // rbp
  long long *v10; // rax
  long long *v11; // rax
  long long *v12; // rbx
  double v13; // xmm0_8
  long long *v14; // rax
  unsigned int v15; // eax
  long long v16; // r13
  void *v17; // r13
  double v18; // xmm0_8
  int v20; // eax
  void *v21; // r14
  unsigned int v22; // ebp
  int v23; // eax
  long long v24; // rbx
  long long *v25; // rbp
  unsigned long long v26; // rax
  unsigned int v27; // eax
  long long v28; // rax
  int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // ebp
  double v32; // xmm0_8
  long long v33; // rax
  double v34; // xmm0_8
  size_t v35; // rax
  double v36; // xmm0_8
  char *s1; // [rsp+8h] [rbp-D0h]
  long long *v38; // [rsp+18h] [rbp-C0h]
  size_t v39; // [rsp+20h] [rbp-B8h]
  long long *v40; // [rsp+28h] [rbp-B0h]
  unsigned int v41; // [rsp+30h] [rbp-A8h]
  unsigned int v42; // [rsp+34h] [rbp-A4h]
  unsigned int v43; // [rsp+38h] [rbp-A0h]
  unsigned int v45; // [rsp+58h] [rbp-80h]
  unsigned int v46; // [rsp+5Ch] [rbp-7Ch]
  long long v47; // [rsp+60h] [rbp-78h] BYREF
  void *ptr; // [rsp+68h] [rbp-70h] BYREF
  long long v49; // [rsp+70h] [rbp-68h] BYREF
  void *v50; // [rsp+78h] [rbp-60h] BYREF
  char dest[24]; // [rsp+80h] [rbp-58h] BYREF
  unsigned long long v52; // [rsp+98h] [rbp-40h]

  v7 = (unsigned int)a6;
  v52 = __readfsqword(0x28u);
  ptr = 0;
  v50 = 0;
  if ( a6 <= 0 )
    v7 = 16;
  if ( a3 && strlen(a3) )
  {
    s1 = "bcrypt";
    if ( !a5 )
      a5 = "aes256-ctr";
  }
  else
  {
    a5 = "none";
    s1 = "none";
  }
  v9 = (long long *)sub_1DFF0(a5);
  if ( !v9 )
  {
    v12 = 0;
    sub_BCE0(0);
    goto LABEL_47;
  }
  sub_B880();
  v38 = v10;
  if ( !v10 )
  {
    v9 = 0;
    v12 = 0;
    goto LABEL_46;
  }
  sub_B880();
  v12 = v11;
  if ( !v11 || (v13 = sub_B880(), (v40 = v14) == 0) )
  {
    v9 = 0;
LABEL_46:
    sub_BCE0(v38);
LABEL_47:
    sub_BCE0(v12);
    v36 = sub_BCE0(v9);
    sub_1E970(v50);
    __explicit_bzero_chk(dest, 16, 16, v36);
    return 0.0;
  }
  v45 = sub_1DB60(v9);
  v15 = sub_1DBF0(v9, v13);
  v16 = v15;
  v42 = v15;
  v43 = v15;
  v41 = sub_1DDC0(v9);
  v46 = sub_1DD30(v9);
  v39 = v16 + v41;
  v17 = calloc(1u, v39);
  if ( !v17 )
  {
    v9 = v40;
    goto LABEL_46;
  }
  if ( !strcmp(s1, "bcrypt") )
  {
    sub_38B20(dest);
    v35 = strlen(a3);
    if ( (int)sub_39530(a3, v35, dest, 16, v17, v39, v7) < 0
      || (unsigned int)sub_1B6C0(v38, dest, 16)
      || (unsigned int)sub_1AFB0(v38, (unsigned int)v7) )
    {
      goto LABEL_14;
    }
  }
  else if ( strcmp(s1, "none") )
  {
LABEL_14:
    sub_BCE0(v38);
    sub_BCE0(v12);
    v18 = sub_BCE0(v40);
    sub_1E970(v50);
    __explicit_bzero_chk(dest, 16, 16, v18);
    sub_3B0D0(v17);
    return 0.0;
  }
  if ( (unsigned int)sub_1E340((unsigned int)&v50, (int)v9, (int)v17, v42, (unsigned int)v17 + v43, v41, 1)
    || (unsigned int)sub_1A9D0(v12, "openssh-key-v1", 15)
    || (unsigned int)sub_1B800(v12, a5)
    || (unsigned int)sub_1B800(v12, s1)
    || (unsigned int)sub_1B840(v12, v38)
    || (unsigned int)sub_1AFB0(v12, 1) )
  {
    goto LABEL_14;
  }
  v20 = sub_11720(a1, (long long)&ptr, (long long)&v49);
  v21 = ptr;
  if ( !v20 && !(unsigned int)sub_1B6C0(v12, ptr, v49) )
  {
    v22 = sub_38A60();
    if ( !(unsigned int)sub_1AFB0(v40, v22) && !(unsigned int)sub_1AFB0(v40, v22) )
    {
      sub_17120(a1, (long long)v40);
      if ( !v23 && !(unsigned int)sub_1B800(v40, a4) )
      {
        v25 = v12;
        v24 = 0;
        while ( 1 )
        {
          sub_C3D0((long long)v40);
          if ( !(v26 % v45) )
            break;
          if ( (unsigned int)sub_1B180(v40, (unsigned char)++v24) )
          {
            v12 = v25;
            goto LABEL_36;
          }
        }
        v12 = v25;
        sub_C3D0((long long)v40);
        if ( !(unsigned int)sub_1AFB0(v25, v27) )
        {
          sub_C3D0((long long)v40);
          sub_CB20(v25, v28 + v46, &v47);
          if ( !v29 )
          {
            sub_C3D0((long long)v40);
            v31 = v30;
            v32 = sub_C520((long long)v40);
            if ( !(unsigned int)sub_1E5A0(v50, 0, v47, v33, v31, 0, v32, v46) )
            {
              sub_BE60(a2);
              if ( !(unsigned int)sub_1A9D0(a2, "-----BEGIN OPENSSH PRIVATE KEY-----\n", 36)
                && !(unsigned int)sub_1C140(v12, a2, 1) )
              {
                sub_1A9D0(a2, "-----END OPENSSH PRIVATE KEY-----\n", 34);
              }
            }
          }
        }
      }
    }
  }
LABEL_36:
  sub_BCE0(v38);
  sub_BCE0(v12);
  v34 = sub_BCE0(v40);
  sub_1E970(v50);
  __explicit_bzero_chk(dest, 16, 16, v34);
  sub_3B0D0(v17);
  if ( v21 )
    sub_3B0D0(v21);
  return 0.0;
}


// Function: sshkey_sign @ 0x183c0
double sshkey_sign(
        __m128i *a1,
        void **a2,
        long long *a3,
        long long a4,
        unsigned long long a5,
        long long a6,
        __m128i a7,
        char *file,
        char *a9,
        unsigned int a10)
{
  int v13; // eax
  int v14; // r13d
  int v15; // eax

  sub_12A70();
  v14 = v13;
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  if ( a5 <= 0x100000 )
  {
    *(double *)a7.m128i_i64 = sub_16D90(a1);
    if ( !v15 )
    {
      switch ( a1->m128i_i32[0] )
      {
        case 0:
        case 4:
          sub_2E5C0(a1, a2, a3, a4, a5, a6, *(double *)a7.m128i_i64);
          break;
        case 1:
        case 5:
          sub_2BD90(a1, a2, a3, a4, a5, a10, *(double *)a7.m128i_i64);
          break;
        case 2:
        case 6:
          sub_2C4E0(a1, a2, a3, a4, a5, a10, *(double *)a7.m128i_i64);
          break;
        case 3:
        case 7:
          sub_2F820(a1, a2, a3, a4, a5, a10, *(double *)a7.m128i_i64);
          break;
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
          *(double *)a7.m128i_i64 = sub_A4D0((void **)file, (unsigned int *)a1, a2, a3, a4, a5, a10, a9);
          break;
        default:
          break;
      }
      if ( v14 )
        sub_17750(a1, a7);
    }
  }
  return 0.0;
}


// Function: default_key_sign @ 0x185e0
double default_key_sign(
        __m128i *a1,
        void **a2,
        long long *a3,
        long long a4,
        unsigned long long a5,
        long long a6,
        __m128i a7,
        char *a8,
        char *a9,
        unsigned int a10,
        long long a11)
{
  if ( a11 )
    return 0.0;
  else
    return sub_183C0(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}


// Function: sshkey_parse_private2 @ 0x18a30
double sshkey_parse_private2(long long a1, unsigned int a2, long long a3, long long *a4, void **a5, double a6)
{
  int v9; // eax
  long long *v10; // r14
  void *v11; // rdi
  unsigned int *v12; // r15
  long long *v13; // r12
  long long *v14; // r13
  int v16; // eax
  int v17; // r12d
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  void *ptr; // [rsp+10h] [rbp-68h] BYREF
  void *v24; // [rsp+18h] [rbp-60h] BYREF
  long long *v25; // [rsp+20h] [rbp-58h] BYREF
  long long *v26; // [rsp+28h] [rbp-50h] BYREF
  long long v27[9]; // [rsp+30h] [rbp-48h] BYREF

  v27[1] = __readfsqword(0x28u);
  ptr = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27[0] = 0;
  if ( a4 )
    *a4 = 0;
  if ( a5 )
    *a5 = 0;
  v9 = sub_E4A0(a1, &v24);
  v10 = v24;
  if ( v9 )
  {
    v11 = ptr;
    v12 = 0;
    v13 = 0;
    v14 = 0;
  }
  else if ( (unsigned int)sub_15B30(v24, a3, &v25, v27, 0) )
  {
    v11 = ptr;
    v14 = v25;
    v13 = 0;
    v12 = (unsigned int *)v27[0];
  }
  else
  {
    v12 = (unsigned int *)v27[0];
    v14 = v25;
    if ( a2 == 14 || (sub_F440(a2), v17 = v16, a6 = sub_F440(*v12), v17 == v18) )
    {
      sub_16380((long long)v14, &v26, a6);
      if ( v19 )
      {
        v11 = ptr;
        v13 = v26;
      }
      else
      {
        v20 = sub_1A6F0(v14, &ptr, 0);
        v13 = v26;
        if ( v20 || (sub_E200((long long)v14), v21) )
        {
          v11 = ptr;
        }
        else
        {
          sub_11490((long long)v12, v13);
          if ( v22 )
          {
            if ( a4 )
            {
              *a4 = v13;
              v26 = 0;
            }
            v11 = ptr;
            v13 = v26;
            if ( a5 )
            {
              *a5 = ptr;
              v13 = v26;
              v11 = 0;
              ptr = 0;
            }
          }
          else
          {
            v11 = ptr;
          }
        }
      }
    }
    else
    {
      v11 = ptr;
      v13 = 0;
    }
  }
  free(v11);
  sub_BCE0(v10);
  sub_BCE0(v14);
  sub_10A60(v13);
  sub_10A60(v12);
  return 0.0;
}


// Function: sshkey_parse_private_pem_fileblob @ 0x18ce0
double sshkey_parse_private_pem_fileblob(long long a1, int a2, char *a3, long long **a4)
{
  long long v6; // rax
  long long v7; // r12
  unsigned long long v8; // rax
  unsigned int v9; // eax
  unsigned int v10; // ebx
  double v11; // xmm0_8
  long long v12; // rax
  int v13; // ebx
  double v14; // xmm0_8
  int v15; // eax
  long long *v16; // r15
  long long v17; // rbp
  long long bio_PrivateKey; // rax
  long long *v20; // rax
  long long v21; // rax
  int v22; // eax
  long long v23; // rax
  long long v24; // r14
  long long v25; // rax
  int v26; // eax
  int v27; // eax
  long long *v28; // rax
  long long v29; // rax
  int v30; // eax
  long long *v31; // rax
  long long v32; // rax

  if ( a4 )
    *a4 = 0;
  v6 = BIO_s_mem();
  v7 = BIO_new(v6);
  if ( v7 )
  {
    sub_C3D0(a1);
    if ( v8 <= 0x7FFFFFFF )
    {
      sub_C3D0(a1);
      v10 = v9;
      v11 = sub_C520(a1);
      v13 = BIO_write(v7, v12, v10, v11);
      v14 = sub_C3D0(a1);
      if ( v13 != v15 )
      {
        v16 = 0;
        v17 = 0;
LABEL_7:
        BIO_free(v7, v14);
        EVP_PKEY_free(v17);
        sub_10A60(v16);
        return 0.0;
      }
      v14 = sub_E340();
      bio_PrivateKey = PEM_read_bio_PrivateKey(v7, 0, sub_D650, a3, v14);
      v17 = bio_PrivateKey;
      if ( !bio_PrivateKey )
      {
        if ( a3 && *a3 )
        {
          v16 = 0;
        }
        else
        {
          v14 = sub_E3E0();
          v16 = 0;
        }
        goto LABEL_7;
      }
      if ( (unsigned int)EVP_PKEY_get_base_id(bio_PrivateKey) == 6 && (a2 == 14 || !a2) )
      {
        v14 = sub_10ED0(0xEu);
        v16 = v28;
        if ( !v28 )
          goto LABEL_7;
        v29 = EVP_PKEY_get1_RSA(v17, v14);
        *(int *)v16 = 0;
        v16[1] = v29;
        if ( (unsigned int)RSA_blinding_on(v29, 0) != 1 )
          goto LABEL_7;
        v14 = sub_12B10((long long)v16);
        if ( v30 )
          goto LABEL_7;
      }
      else if ( (unsigned int)EVP_PKEY_get_base_id(v17) == 116 && (a2 == 14 || a2 == 1) )
      {
        v14 = sub_10ED0(0xEu);
        v16 = v31;
        if ( !v31 )
          goto LABEL_7;
        v32 = EVP_PKEY_get1_DSA(v17, v14);
        *(int *)v16 = 1;
        v16[2] = v32;
      }
      else
      {
        if ( (unsigned int)EVP_PKEY_get_base_id(v17) != 408 )
        {
          v16 = 0;
          goto LABEL_7;
        }
        if ( a2 != 14 )
        {
          v16 = 0;
          if ( a2 != 2 )
            goto LABEL_7;
        }
        v14 = sub_10ED0(0xEu);
        v16 = v20;
        if ( !v20 )
          goto LABEL_7;
        v21 = EVP_PKEY_get1_EC_KEY(v17, v14);
        *(int *)v16 = 2;
        v16[4] = v21;
        v14 = sub_11F10(v21);
        *((int *)v16 + 6) = v22;
        if ( v22 == -1 )
          goto LABEL_7;
        v14 = sub_10400();
        if ( !v23 )
          goto LABEL_7;
        v24 = EC_KEY_get0_public_key(v14);
        v25 = EC_KEY_get0_group(v16[4]);
        v14 = sub_14460(v25, v24, v14);
        if ( v26 )
          goto LABEL_7;
        v14 = sub_161F0(v16[4], v14);
        if ( v27 )
          goto LABEL_7;
      }
      if ( a4 )
      {
        *a4 = v16;
        v16 = 0;
      }
      goto LABEL_7;
    }
  }
  return 0.0;
}


// Function: sshkey_dump_ec_point @ 0x19050
int sshkey_dump_ec_point(long long a1, long long a2, double a3)
{
  long long v3; // rbp
  long long v4; // r13
  long long v5; // rax

  if ( !a2 )
    return fputs("point=(NULL)\n", stderr);
  v3 = BN_new();
  if ( v3 && (v4 = BN_new()) != 0 )
  {
    v5 = EC_GROUP_method_of(a1);
    if ( (unsigned int)EC_METHOD_get_field_type(v5) == 406 )
    {
      if ( (unsigned int)EC_POINT_get_affine_coordinates_GFp(a1, a2, v3, v4, 0) == 1 )
      {
        fputs("x=", stderr);
        BN_print_fp(stderr, v3);
        fputs("\ny=", stderr);
        BN_print_fp(stderr, v4);
        fputs("\n", stderr);
      }
      else
      {
        __fprintf_chk(stderr, 1, "%s: EC_POINT_get_affine_coordinates_GFp\n", "sshkey_dump_ec_point");
      }
    }
    else
    {
      a3 = __fprintf_chk(stderr, 1, "%s: group is not a prime field\n", "sshkey_dump_ec_point");
    }
  }
  else
  {
    v4 = 0;
    __fprintf_chk(stderr, 1, "%s: BN_new failed\n", "sshkey_dump_ec_point");
  }
  BN_clear_free(v3, a3);
  return BN_clear_free(v4, a3);
}


// Function: sshkey_dump_ec_key @ 0x191d0
int sshkey_dump_ec_key(long long a1, double a2)
{
  long long v2; // r12
  long long v3; // rax
  long long v4; // rax

  v2 = EC_KEY_get0_public_key(a2);
  v3 = EC_KEY_get0_group(a1);
  sub_19050(v3, v2, a2);
  fputs("exponent=", stderr);
  if ( EC_KEY_get0_private_key(a1) )
  {
    v4 = EC_KEY_get0_private_key(a1);
    BN_print_fp(stderr, v4);
  }
  else
  {
    fputs("(NULL)", stderr);
  }
  return fputs("\n", stderr);
}


// Function: sshkey_parse_private_fileblob_type @ 0x19400
double sshkey_parse_private_fileblob_type(long long a1, unsigned int a2, char *a3, long long **a4, void **a5, double a6)
{
  int v8; // eax

  if ( a4 )
    *a4 = 0;
  if ( a5 )
    *a5 = 0;
  if ( a2 == 3 || a2 == 8 )
    return sub_18A30(a1, a2, (long long)a3, a4, a5, a6);
  sub_18A30(a1, a2, (long long)a3, a4, a5, a6);
  if ( v8 == -4 )
    return sub_18CE0(a1, a2, a3, a4);
  else
    return 0.0;
}


// Function: sshkey_sig_details_free @ 0x19560
long long sshkey_sig_details_free(void *a1)
{
  return sub_3B0D0(a1);
}


// Function: check_offset @ 0x19750
double check_offset(long long a1, long long a2, unsigned long long a3, long long a4)
{
  long long v6; // rax

  sub_C520(a1);
  if ( v6 && ~a4 > a3 )
    sub_C3D0(a1);
  return 0.0;
}


// Function: sshbuf_get @ 0x19aa0
double sshbuf_get(long long a1, void *a2, unsigned long long a3)
{
  const void *v4; // rax
  const void *v5; // r14
  int v6; // eax

  sub_C520(a1);
  v5 = v4;
  sub_CC80(a1, a3);
  if ( v6 < 0 )
    return 0.0;
  if ( a2 && a3 )
  {
    memcpy(a2, v5, a3);
    return 0.0;
  }
  return 0.0;
}


// Function: sshbuf_get_u64 @ 0x19c10
double sshbuf_get_u64(long long a1, long long *a2)
{
  unsigned long long *v2; // rax
  unsigned long long *v3; // r12
  int v4; // eax

  sub_C520(a1);
  v3 = v2;
  sub_CC80(a1, 8u);
  if ( v4 >= 0 && a2 )
    *a2 = _byteswap_uint64(*v3);
  return 0.0;
}


// Function: sshbuf_get_u32 @ 0x19cd0
double sshbuf_get_u32(long long a1, int *a2)
{
  unsigned int *v2; // rax
  unsigned int *v3; // r12
  int v4; // eax

  sub_C520(a1);
  v3 = v2;
  sub_CC80(a1, 4u);
  if ( v4 >= 0 && a2 )
    *a2 = _byteswap_ulong(*v3);
  return 0.0;
}


// Function: sshbuf_get_u16 @ 0x19d90
double sshbuf_get_u16(long long a1, short *a2)
{
  short *v2; // rax
  short *v3; // r12
  int v4; // eax

  sub_C520(a1);
  v3 = v2;
  sub_CC80(a1, 2u);
  if ( v4 >= 0 && a2 )
    *a2 = __ROL2__(*v3, 8);
  return 0.0;
}


// Function: sshbuf_get_u8 @ 0x19e50
double sshbuf_get_u8(long long a1, char *a2)
{
  char *v2; // rax
  char *v3; // r12
  int v4; // eax

  sub_C520(a1);
  v3 = v2;
  sub_CC80(a1, 1u);
  if ( v4 >= 0 && a2 )
    *a2 = *v3;
  return 0.0;
}


// Function: sshbuf_peek_u64 @ 0x19f10
double sshbuf_peek_u64(long long a1, long long a2, long long *a3)
{
  long long v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[1] = __readfsqword(0x28u);
  v5[0] = 0;
  if ( a3 )
  {
    *a3 = 0;
    if ( !(unsigned int)sub_199D0(a1, a2, 8, v5) )
      *a3 = _byteswap_uint64(*(long long *)v5[0]);
  }
  else
  {
    sub_199D0(a1, a2, 8, v5);
  }
  return 0.0;
}


// Function: sshbuf_peek_u32 @ 0x1a020
double sshbuf_peek_u32(long long a1, long long a2, int *a3)
{
  long long v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[1] = __readfsqword(0x28u);
  v5[0] = 0;
  if ( a3 )
  {
    *a3 = 0;
    if ( !(unsigned int)sub_199D0(a1, a2, 4, v5) )
      *a3 = _byteswap_ulong(*(int *)v5[0]);
  }
  else
  {
    sub_199D0(a1, a2, 4, v5);
  }
  return 0.0;
}


// Function: sshbuf_peek_u16 @ 0x1a120
double sshbuf_peek_u16(long long a1, long long a2, short *a3)
{
  long long v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[1] = __readfsqword(0x28u);
  v5[0] = 0;
  if ( a3 )
  {
    *a3 = 0;
    if ( !(unsigned int)sub_199D0(a1, a2, 2, v5) )
      *a3 = __ROL2__(*(short *)v5[0], 8);
  }
  else
  {
    sub_199D0(a1, a2, 2, v5);
  }
  return 0.0;
}


// Function: sshbuf_peek_u8 @ 0x1a230
double sshbuf_peek_u8(long long a1, long long a2, char *a3)
{
  long long v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[1] = __readfsqword(0x28u);
  v5[0] = 0;
  if ( a3 )
  {
    *a3 = 0;
    if ( !(unsigned int)sub_199D0(a1, a2, 1, v5) )
      *a3 = *(char *)v5[0];
  }
  else
  {
    sub_199D0(a1, a2, 1, v5);
  }
  return 0.0;
}


// Function: sshbuf_peek_string_direct @ 0x1a330
double sshbuf_peek_string_direct(long long a1, long long *a2, long long *a3)
{
  unsigned int *v4; // rax
  unsigned int *v5; // r13
  unsigned long long v6; // rax
  unsigned int v7; // ebx
  long long v8; // rax

  sub_C520(a1);
  v5 = v4;
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  sub_C3D0(a1);
  if ( v6 > 3 )
  {
    v7 = _byteswap_ulong(*v5);
    if ( v7 <= 0x7FFFFFC )
    {
      sub_C3D0(a1);
      if ( v8 - 4 >= (unsigned long long)v7 )
      {
        if ( a2 )
          *a2 = v5 + 1;
        if ( a3 )
          *a3 = v7;
      }
    }
  }
  return 0.0;
}


// Function: sshbuf_get_string_direct @ 0x1a460
double sshbuf_get_string_direct(long long a1, long long *a2, long long *a3)
{
  int v4; // eax
  long long v5; // rsi
  int v6; // eax
  long long v8; // [rsp+8h] [rbp-30h] BYREF
  long long v9[5]; // [rsp+10h] [rbp-28h] BYREF

  v9[1] = __readfsqword(0x28u);
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  sub_1A330(a1, v9, &v8);
  if ( v4 >= 0 )
  {
    if ( a2 )
      *a2 = v9[0];
    v5 = v8;
    if ( a3 )
      *a3 = v8;
    sub_CC80(a1, v5 + 4);
    sub_3DAE0(v6 != 0);
  }
  return 0.0;
}


// Function: sshbuf_get_string @ 0x1a590
double sshbuf_get_string(long long a1, long long *a2, long long *a3)
{
  int v4; // eax
  size_t v5; // r12
  char *v6; // rax
  char *v7; // rcx
  void *src; // [rsp+8h] [rbp-30h] BYREF
  size_t n[5]; // [rsp+10h] [rbp-28h] BYREF

  n[1] = __readfsqword(0x28u);
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  sub_1A460(a1, &src, n);
  if ( v4 >= 0 )
  {
    if ( a2 )
    {
      v5 = n[0];
      v6 = malloc(n[0] + 1);
      *a2 = v6;
      v7 = v6;
      if ( !v6 )
        return 0.0;
      if ( v5 )
        v7 = memcpy(v6, src, v5);
      v7[v5] = 0;
    }
    if ( a3 )
      *a3 = n[0];
  }
  return 0.0;
}


// Function: sshbuf_get_cstring @ 0x1a6f0
double sshbuf_get_cstring(long long a1, long long *a2, size_t *a3)
{
  int v4; // eax
  size_t v5; // r14
  char *v6; // r12
  char *v7; // rax
  int v8; // eax
  char *v9; // rax
  char *v10; // rcx
  size_t n; // [rsp+8h] [rbp-40h] BYREF
  void *s[7]; // [rsp+10h] [rbp-38h] BYREF

  s[1] = (void *)__readfsqword(0x28u);
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  sub_1A330(a1, s, &n);
  if ( !v4 )
  {
    v5 = n;
    if ( !n || (v6 = (char *)s[0], (v7 = (char *)memchr(s[0], 0, n)) == 0) || v7 >= &v6[v5 - 1] )
    {
      sub_1A460(a1, 0, 0);
      if ( !v8 )
      {
        if ( a2 )
        {
          v9 = malloc(v5 + 1);
          *a2 = v9;
          v10 = v9;
          if ( !v9 )
            return 0.0;
          if ( v5 )
            v10 = memcpy(v9, s[0], v5);
          v10[v5] = 0;
        }
        if ( a3 )
          *a3 = v5;
      }
    }
  }
  return 0.0;
}


// Function: sshbuf_get_stringb @ 0x1a8b0
double sshbuf_get_stringb(long long a1, long long *a2)
{
  int v2; // eax
  int v4; // eax
  unsigned long long v5; // r13
  int v6; // eax
  unsigned int v7; // [rsp+Ch] [rbp-2Ch] BYREF
  void *v8[5]; // [rsp+10h] [rbp-28h] BYREF

  v8[1] = (void *)__readfsqword(0x28u);
  sub_1A330(a1, 0, 0);
  if ( !v2 )
  {
    sub_19CD0(a1, &v7);
    if ( !v4 )
    {
      v5 = v7;
      sub_CB20(a2, v7, (long long *)v8);
      if ( !v6 )
        sub_19AA0(a1, v8[0], v5);
    }
  }
  return 0.0;
}


// Function: sshbuf_put @ 0x1a9d0
double sshbuf_put(long long *a1, const void *a2, size_t a3)
{
  int v4; // eax
  void *dest[5]; // [rsp+0h] [rbp-28h] BYREF

  dest[1] = (void *)__readfsqword(0x28u);
  sub_CB20(a1, a3, (long long *)dest);
  if ( v4 >= 0 && a3 )
    memcpy(dest[0], a2, a3);
  return 0.0;
}


// Function: sshbuf_putb @ 0x1aad0
double sshbuf_putb(long long *a1, long long a2)
{
  size_t v2; // rax
  size_t v3; // r13
  const void *v4; // rax

  if ( !a2 )
    return 0.0;
  sub_C3D0(a2);
  v3 = v2;
  sub_C520(a2);
  return sub_1A9D0(a1, v4, v3);
}


// Function: sshbuf_putfv @ 0x1ab90
double sshbuf_putfv(long long *a1, long long a2, const __m128i *a3)
{
  int v4; // eax
  unsigned int v5; // r12d
  __m128i v7; // xmm1
  int v8; // eax
  int v9; // eax
  long long v10; // [rsp+8h] [rbp-50h] BYREF
  __m128i v11; // [rsp+10h] [rbp-48h] BYREF
  long long v12; // [rsp+20h] [rbp-38h]
  unsigned long long v13; // [rsp+28h] [rbp-30h]

  v13 = __readfsqword(0x28u);
  v11 = _mm_loadu_si128(a3);
  v12 = a3[1].m128i_i64[0];
  v4 = __vsnprintf_chk(0, 0, 1, -1, a2, &v11);
  if ( v4 >= 0 )
  {
    v5 = v4;
    if ( v4 )
    {
      v7 = _mm_loadu_si128(a3);
      v12 = a3[1].m128i_i64[0];
      v11 = v7;
      sub_CB20(a1, v4 + 1LL, &v10);
      if ( v8 >= 0 )
      {
        v9 = sub_3DA20(v5, 1);
        if ( v5 == (unsigned int)__vsnprintf_chk(v10, v9, 1, -1, a2, &v11) )
          sub_CE00((long long)a1, 1u);
      }
    }
  }
  return 0.0;
}


// Function: sshbuf_putf @ 0x1ad40
double sshbuf_putf(long long *a1, long long a2, ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-D8h] BYREF
  unsigned long long v4; // [rsp+18h] [rbp-C0h]

  va_start(va, a2);
  v4 = __readfsqword(0x28u);
  sub_1AB90(a1, a2, (const __m128i *)va);
  return 0.0;
}


// Function: sshbuf_put_u64 @ 0x1ae80
double sshbuf_put_u64(long long *a1, long long a2)
{
  int v2; // eax
  long long v4[3]; // [rsp+0h] [rbp-18h] BYREF

  v4[1] = __readfsqword(0x28u);
  sub_CB20(a1, 8, v4);
  if ( v2 >= 0 )
  {
    *(char *)v4[0] = HIBYTE(a2);
    *(char *)(v4[0] + 1) = BYTE6(a2);
    *(char *)(v4[0] + 2) = BYTE5(a2);
    *(char *)(v4[0] + 3) = BYTE4(a2);
    *(char *)(v4[0] + 4) = BYTE3(a2);
    *(char *)(v4[0] + 5) = BYTE2(a2);
    *(char *)(v4[0] + 6) = BYTE1(a2);
    *(char *)(v4[0] + 7) = a2;
  }
  return 0.0;
}


// Function: sshbuf_put_u32 @ 0x1afb0
double sshbuf_put_u32(long long *a1, int a2)
{
  int v2; // eax
  long long v4[3]; // [rsp+0h] [rbp-18h] BYREF

  v4[1] = __readfsqword(0x28u);
  sub_CB20(a1, 4, v4);
  if ( v2 >= 0 )
  {
    *(char *)v4[0] = HIBYTE(a2);
    *(char *)(v4[0] + 1) = BYTE2(a2);
    *(char *)(v4[0] + 2) = BYTE1(a2);
    *(char *)(v4[0] + 3) = a2;
  }
  return 0.0;
}


// Function: sshbuf_put_u16 @ 0x1b0a0
double sshbuf_put_u16(long long *a1, short a2)
{
  int v2; // eax
  long long v4[3]; // [rsp+0h] [rbp-18h] BYREF

  v4[1] = __readfsqword(0x28u);
  sub_CB20(a1, 2, v4);
  if ( v2 >= 0 )
  {
    *(char *)v4[0] = HIBYTE(a2);
    *(char *)(v4[0] + 1) = a2;
  }
  return 0.0;
}


// Function: sshbuf_put_u8 @ 0x1b180
double sshbuf_put_u8(long long *a1, char a2)
{
  int v2; // eax
  long long v4[3]; // [rsp+0h] [rbp-18h] BYREF

  v4[1] = __readfsqword(0x28u);
  sub_CB20(a1, 1, v4);
  if ( v2 >= 0 )
    *(char *)v4[0] = a2;
  return 0.0;
}


// Function: sshbuf_poke_u64 @ 0x1b250
double sshbuf_poke_u64(long long a1, long long a2, unsigned long long a3)
{
  long long v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[1] = __readfsqword(0x28u);
  v5[0] = 0;
  if ( !(unsigned int)sub_19850(a1, a2, 8, v5) )
    *(long long *)v5[0] = _byteswap_uint64(a3);
  return 0.0;
}


// Function: sshbuf_poke_u32 @ 0x1b330
double sshbuf_poke_u32(long long a1, long long a2, unsigned int a3)
{
  long long v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[1] = __readfsqword(0x28u);
  v5[0] = 0;
  if ( !(unsigned int)sub_19850(a1, a2, 4, v5) )
    *(int *)v5[0] = _byteswap_ulong(a3);
  return 0.0;
}


// Function: sshbuf_poke_u16 @ 0x1b410
double sshbuf_poke_u16(long long a1, long long a2, short a3)
{
  long long v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[1] = __readfsqword(0x28u);
  v5[0] = 0;
  if ( !(unsigned int)sub_19850(a1, a2, 2, v5) )
    *(short *)v5[0] = __ROL2__(a3, 8);
  return 0.0;
}


// Function: sshbuf_poke_u8 @ 0x1b4f0
double sshbuf_poke_u8(long long a1, long long a2, char a3)
{
  long long v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[1] = __readfsqword(0x28u);
  v5[0] = 0;
  if ( !(unsigned int)sub_19850(a1, a2, 1, v5) )
    *(char *)v5[0] = a3;
  return 0.0;
}


// Function: sshbuf_poke @ 0x1b5d0
double sshbuf_poke(long long a1, long long a2, const void *a3, size_t a4)
{
  void *dest[5]; // [rsp+0h] [rbp-28h] BYREF

  dest[1] = (void *)__readfsqword(0x28u);
  dest[0] = 0;
  if ( !(unsigned int)sub_19850(a1, a2, a4, dest) )
    memcpy(dest[0], a3, a4);
  return 0.0;
}


// Function: sshbuf_put_string @ 0x1b6c0
double sshbuf_put_string(long long *a1, const void *a2, size_t a3)
{
  int v4; // eax
  long long v6[5]; // [rsp+0h] [rbp-28h] BYREF

  v6[1] = __readfsqword(0x28u);
  if ( a3 <= 0x7FFFFFC )
  {
    sub_CB20(a1, a3 + 4, v6);
    if ( v4 >= 0 )
    {
      *(char *)v6[0] = BYTE3(a3);
      *(char *)(v6[0] + 1) = BYTE2(a3);
      *(char *)(v6[0] + 2) = BYTE1(a3);
      *(char *)(v6[0] + 3) = a3;
      if ( a3 )
        memcpy((void *)(v6[0] + 4), a2, a3);
    }
  }
  return 0.0;
}


// Function: sshbuf_put_cstring @ 0x1b800
double sshbuf_put_cstring(long long *a1, const char *a2)
{
  size_t v2; // rdx

  v2 = 0;
  if ( a2 )
    v2 = strlen(a2);
  return sub_1B6C0(a1, a2, v2);
}


// Function: sshbuf_put_stringb @ 0x1b840
double sshbuf_put_stringb(long long *a1, long long a2)
{
  size_t v2; // rax
  size_t v3; // r13
  const void *v4; // rax

  if ( !a2 )
    return sub_1B6C0(a1, 0, 0);
  sub_C3D0(a2);
  v3 = v2;
  sub_C520(a2);
  return sub_1B6C0(a1, v4, v3);
}


// Function: sshbuf_froms @ 0x1b8a0
double sshbuf_froms(long long a1, long long *a2)
{
  int v2; // eax
  unsigned long long v4; // r13
  long long *v5; // rax
  long long *v6; // r12
  int v7; // eax
  int v8; // eax
  long long v9; // [rsp+18h] [rbp-40h] BYREF
  unsigned long long v10[7]; // [rsp+20h] [rbp-38h] BYREF

  v10[1] = __readfsqword(0x28u);
  if ( a1 )
  {
    if ( a2 )
    {
      *a2 = 0;
      sub_1A330(a1, &v9, v10);
      if ( !v2 )
      {
        v4 = v10[0];
        sub_B980(v9, v10[0]);
        v6 = v5;
        if ( v5 )
        {
          sub_CC80(a1, v4 + 4);
          if ( v7 || (sub_BB80((long long)v6, a1), v8) )
            sub_BCE0(v6);
          else
            *a2 = v6;
        }
      }
    }
  }
  return 0.0;
}


// Function: sshbuf_put_bignum2_bytes @ 0x1ba10
double sshbuf_put_bignum2_bytes(long long *a1, unsigned char *a2, unsigned long long a3)
{
  size_t v4; // r12
  unsigned char v5; // al
  long long v6; // rbx
  int v7; // ebp
  int v8; // eax
  int v10; // eax
  long long v11[7]; // [rsp+0h] [rbp-38h] BYREF

  v11[1] = __readfsqword(0x28u);
  if ( a3 > 0x7FFFFFB )
    return 0.0;
  v4 = a3;
  if ( !a3 )
  {
LABEL_8:
    v6 = 0;
    v7 = 0;
    sub_CB20(a1, 4, v11);
    if ( v10 < 0 )
      return 0.0;
    goto LABEL_9;
  }
  while ( 1 )
  {
    v5 = *a2;
    if ( *a2 )
      break;
    ++a2;
    if ( !--v4 )
      goto LABEL_8;
  }
  v6 = v5 >> 7;
  v7 = v5 >> 7;
  sub_CB20(a1, v6 + v4 + 4, v11);
  if ( v8 >= 0 )
  {
LABEL_9:
    *(char *)v11[0] = (unsigned int)(v7 + v4) >> 24;
    *(char *)(v11[0] + 1) = (unsigned int)(v7 + v4) >> 16;
    *(char *)(v11[0] + 2) = (unsigned short)(v7 + v4) >> 8;
    *(char *)(v11[0] + 3) = v7 + v4;
    if ( v7 )
      *(char *)(v11[0] + 4) = 0;
    if ( v4 )
      memcpy((void *)(v11[0] + v6 + 4), a2, v4);
  }
  return 0.0;
}


// Function: sshbuf_get_bignum2_bytes_direct @ 0x1bbc0
double sshbuf_get_bignum2_bytes_direct(long long a1, char **a2, long long *a3)
{
  int v6; // eax
  long long v7; // rsi
  long long v8; // rax
  int v9; // eax
  char *v11; // rdx
  char v12; // cl
  char v13; // di
  char *v14; // [rsp+8h] [rbp-30h] BYREF
  long long v15[5]; // [rsp+10h] [rbp-28h] BYREF

  v15[1] = __readfsqword(0x28u);
  sub_1A330(a1, &v14, v15);
  if ( v6 >= 0 )
  {
    v7 = v15[0];
    if ( v15[0] )
    {
      v11 = v14;
      v12 = *v14;
      if ( *v14 < 0 || v15[0] > 0x801u )
        return 0.0;
      v8 = v15[0];
      if ( v15[0] == 2049 )
      {
        if ( v12 )
          return 0.0;
        v8 = 2049;
      }
      v13 = 0;
      while ( !v12 )
      {
        ++v11;
        if ( !--v8 )
          goto LABEL_20;
        v12 = *v11;
        v13 = 1;
      }
      if ( !v13 )
        goto LABEL_4;
LABEL_20:
      v14 = v11;
    }
    else
    {
      v8 = 0;
    }
LABEL_4:
    if ( a2 )
      *a2 = v14;
    if ( a3 )
      *a3 = v8;
    sub_CC80(a1, v7 + 4);
    sub_3DAE0(v9 != 0);
  }
  return 0.0;
}


// Function: sshbuf_dump_data @ 0x1bd50
double sshbuf_dump_data(long long a1, unsigned long long a2, long long a3)
{
  unsigned long long v4; // rbp
  long long v5; // rcx
  unsigned long long v6; // rbx
  double v7; // xmm0_8
  int v8; // ecx
  unsigned long long v9; // rbx
  double v10; // xmm0_8
  unsigned int v11; // r15d
  unsigned long long v13; // [rsp+0h] [rbp-48h]
  unsigned char v14; // [rsp+0h] [rbp-48h]

  if ( a2 )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = v4;
      v6 = v4;
      v4 += 16LL;
      v7 = __fprintf_chk(a3, 1, "%.4zu: ", v5);
      if ( v6 < v4 )
        break;
      v10 = __fprintf_chk(a3, 1, " ", v7);
LABEL_15:
      __fprintf_chk(a3, 1, "\n", v10);
      if ( a2 <= v4 )
        return 0.0;
    }
    v13 = v6;
    do
    {
      while ( a2 > v6 )
      {
        v8 = *(unsigned char *)(a1 + v6++);
        v7 = __fprintf_chk(a3, 1, "%02x ", v8);
        if ( v6 == v4 )
          goto LABEL_8;
      }
      v7 = __fprintf_chk(a3, 1, "   ", v7);
      ++v6;
    }
    while ( v6 != v4 );
LABEL_8:
    v9 = v13;
    v10 = __fprintf_chk(a3, 1, " ", v7);
    while ( 1 )
    {
      if ( a2 <= v9 )
        goto LABEL_10;
      v11 = *(unsigned char *)(a1 + v9);
      if ( (v11 & 0x80u) == 0 && (v14 = *(char *)(a1 + v9), ((*__ctype_b_loc())[v14] & 0x4000) != 0) )
      {
        ++v9;
        v10 = __fprintf_chk(a3, 1, "%c", v11);
        if ( v9 == v4 )
          goto LABEL_15;
      }
      else
      {
        v10 = __fprintf_chk(a3, 1, ".");
LABEL_10:
        if ( ++v9 == v4 )
          goto LABEL_15;
      }
    }
  }
  return 0.0;
}


// Function: sshbuf_dump @ 0x1bf60
double sshbuf_dump(long long a1, long long a2)
{
  size_t v2; // rax
  unsigned long long v3; // rax
  unsigned long long v4; // r13
  long long v5; // rax

  sub_C3D0(a1);
  __fprintf_chk(a2, 1, "buffer len = %zu\n", v2);
  sub_C3D0(a1);
  v4 = v3;
  sub_C520(a1);
  return sub_1BD50(v5, v4, a2);
}


// Function: sshbuf_dtob16 @ 0x1bfc0
char *sshbuf_dtob16(long long a1)
{
  unsigned long long v1; // rax
  unsigned long long v2; // rbp
  long long v3; // rax
  long long v4; // rbx
  char *result; // rax
  long long i; // rdx
  __m128i si128; // [rsp+0h] [rbp-38h]
  char v8; // [rsp+10h] [rbp-28h]
  unsigned long long v9; // [rsp+18h] [rbp-20h]

  v9 = __readfsqword(0x28u);
  sub_C3D0(a1);
  v2 = v1;
  sub_C520(a1);
  v8 = 0;
  si128 = _mm_load_si128((const __m128i *)&xmmword_3F960);
  if ( !v2 )
    return strdup("");
  v4 = v3;
  if ( v2 > 0x7FFFFFFFFFFFFFFELL )
    return 0;
  result = (char *)malloc(2 * v2 + 1);
  if ( !result )
    return 0;
  for ( i = 0; i != v2; ++i )
  {
    result[2 * i] = si128.m128i_i8[(*(char *)(v4 + i) >> 4) & 0xF];
    result[2 * i + 1] = si128.m128i_i8[*(char *)(v4 + i) & 0xF];
  }
  result[2 * v2] = 0;
  return result;
}


// Function: sshbuf_dtob64 @ 0x1c140
double sshbuf_dtob64(long long a1, long long *a2, int a3)
{
  unsigned long long v5; // rax
  long long v6; // rax
  long long v8; // rax
  size_t v9; // r14
  char *v10; // r12
  long long v11; // rax
  long long v12; // r15
  long long v13; // rax
  char v14; // si
  unsigned long long v15; // r13
  int v16; // eax
  unsigned long long v17; // rbx
  int v18; // eax
  size_t v19; // rax

  if ( a1 )
  {
    if ( a2 )
    {
      sub_C3D0(a1);
      if ( v5 <= 0x7FFFFFFFFFFFFFFELL )
      {
        sub_C3D0(a1);
        if ( v6 )
        {
          sub_C3D0(a1);
          v9 = 4 * ((v8 + 2) / 3uLL) + 1;
          v10 = (char *)malloc(v9);
          if ( v10 )
          {
            sub_C3D0(a1);
            v12 = v11;
            sub_C520(a1);
            if ( (unsigned int)sub_38B30(v13, v12, v10, v9) != -1 )
            {
              if ( !a3 )
              {
                v19 = strlen(v10);
                sub_1A9D0(a2, v10, v19);
                sub_3B0D0(v10);
                return 0.0;
              }
              v14 = *v10;
              v15 = 0;
              if ( *v10 )
              {
                while ( 1 )
                {
                  sub_1B180(a2, v14);
                  if ( v16 )
                    break;
                  v17 = v15 % 0x46;
                  if ( v15 % 0x46 == 69 )
                  {
                    sub_1B180(a2, 10);
                    if ( v18 )
                      break;
                  }
                  v14 = v10[++v15];
                  if ( !v14 )
                  {
                    if ( v17 == 69 )
                      break;
                    goto LABEL_18;
                  }
                }
              }
              else
              {
LABEL_18:
                sub_1B180(a2, 10);
              }
            }
            sub_3B0D0(v10);
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: sshbuf_b64tod @ 0x1c390
double sshbuf_b64tod(long long *a1, const char *a2)
{
  size_t v2; // rbp
  void *v3; // rax
  void *v4; // r14
  int v5; // eax

  v2 = strlen(a2);
  if ( v2 )
  {
    v3 = malloc(v2);
    v4 = v3;
    if ( v3 )
    {
      v5 = sub_38DE0(a2, v3, v2);
      if ( v5 >= 0 )
        sub_1A9D0(a1, v4, v5);
      sub_3B0D0(v4);
    }
  }
  return 0.0;
}


// Function: sshbuf_dtourlb64 @ 0x1c5e0
double sshbuf_dtourlb64(long long a1, long long *a2, int a3)
{
  long long *v4; // rax
  long long *v5; // rbp
  int v6; // eax
  long long v7; // rax
  long long v8; // rax
  int v9; // eax
  unsigned long long v10; // rax
  unsigned long long v11; // rbx
  long long v13; // rax
  long long v14; // rbx
  char *v15; // rax
  char *v16; // rcx

  sub_B880();
  if ( v4 )
  {
    v5 = v4;
    sub_1C140(a1, v4, a3);
    if ( !v6 )
    {
      do
      {
        sub_C3D0((long long)v5);
        v11 = v10;
        if ( v10 <= 1 )
          break;
        sub_C520((long long)v5);
        if ( !v7 )
          break;
        sub_C520((long long)v5);
        if ( *(char *)(v11 + v8 - 1) != 61 )
        {
          sub_C3D0((long long)v5);
          v14 = v13;
          sub_C7C0((long long)v5);
          if ( v15 )
          {
            if ( v14 )
            {
              v16 = &v15[v14];
              do
              {
                while ( *v15 == 43 )
                {
                  *v15++ = 45;
                  if ( v15 == v16 )
                    goto LABEL_18;
                }
                if ( *v15 == 47 )
                  *v15 = 95;
                ++v15;
              }
              while ( v15 != v16 );
            }
LABEL_18:
            sub_1AAD0(a2, (long long)v5);
          }
          break;
        }
        sub_CE00((long long)v5, 1u);
      }
      while ( !v9 );
    }
    sub_BCE0(v5);
  }
  return 0.0;
}


// Function: sshbuf_dup_string @ 0x1c770
double sshbuf_dup_string(long long a1)
{
  char *v1; // rax
  char *v2; // r12
  size_t v3; // rax
  size_t v4; // rbp
  char *v5; // rax
  size_t v6; // rbx
  void *v7; // r8
  char *v8; // rbx

  sub_C520(a1);
  v2 = v1;
  sub_C3D0(a1);
  if ( v2 )
  {
    v4 = v3;
    if ( v3 )
    {
      v5 = (char *)memchr(v2, 0, v3);
      if ( v5 )
      {
        v6 = v4 - 1;
        if ( v5 == &v2[v4 - 1] )
        {
          v7 = malloc(v4);
          if ( v7 )
          {
            if ( v4 != 1 )
            {
LABEL_7:
              v8 = (char *)memcpy(v7, v2, v6) + v6;
LABEL_8:
              *v8 = 0;
              return 0.0;
            }
LABEL_10:
            v8 = v7;
            goto LABEL_8;
          }
        }
      }
      else
      {
        v7 = malloc(v4 + 1);
        if ( v7 )
        {
          v6 = v4;
          goto LABEL_7;
        }
      }
    }
    else
    {
      v7 = malloc(1u);
      if ( v7 )
        goto LABEL_10;
    }
  }
  return 0.0;
}


// Function: sshbuf_dtob64_string @ 0x1c950
double sshbuf_dtob64_string(long long a1, int a2)
{
  long long *v2; // rax
  long long *v3; // rbp
  int v4; // eax

  sub_B880();
  if ( !v2 )
    return 0.0;
  v3 = v2;
  sub_1C140(a1, v2, a2);
  if ( !v4 )
    sub_1C770((long long)v3);
  sub_BCE0(v3);
  return 0.0;
}


// Function: sshbuf_cmp @ 0x1cb40
double sshbuf_cmp(long long a1, unsigned long long a2, long long a3, long long a4)
{
  long long v6; // rax
  unsigned long long v7; // rax
  double v8; // xmm0_8
  long long v9; // rax

  sub_C520(a1);
  if ( v6 )
  {
    if ( (unsigned long long)(a4 - 1) <= 0x7FFFFFF && a2 <= 0x8000000 )
    {
      sub_C3D0(a1);
      if ( a2 + a4 <= v7 )
      {
        v8 = sub_C520(a1);
        sub_3C1C0(v9 + a2, a3, a4, v8);
      }
    }
  }
  return 0.0;
}


// Function: sshbuf_find @ 0x1cc70
double sshbuf_find(long long a1, unsigned long long a2, const void *a3, size_t a4, long long *a5)
{
  long long v8; // rax
  unsigned long long v9; // rax
  unsigned long long v10; // rax
  long long v11; // rax
  size_t v12; // r15
  long long v13; // rax
  void *v14; // r13
  double v15; // xmm0_8
  long long v16; // rax

  if ( a5 )
    *a5 = 0;
  sub_C520(a1);
  if ( v8 )
  {
    if ( a4 - 1 <= 0x7FFFFFF && a2 <= 0x8000000 )
    {
      sub_C3D0(a1);
      if ( v9 >= a2 )
      {
        sub_C3D0(a1);
        if ( a2 + a4 <= v10 )
        {
          sub_C3D0(a1);
          v12 = v11 - a2;
          sub_C520(a1);
          v14 = memmem((const void *)(v13 + a2), v12, a3, a4);
          if ( v14 )
          {
            if ( a5 )
            {
              v15 = sub_C520(a1);
              *a5 = sub_3DA40(v14, v16, v15);
            }
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: sshbuf_read @ 0x1ce10
double sshbuf_read(int fd, long long *a2, size_t a3, ssize_t *a4)
{
  int v6; // eax
  ssize_t v7; // r13
  int *v8; // rax
  ssize_t v9; // rdx
  int v10; // ecx
  int *v11; // r15
  size_t v12; // rbx
  int v14; // eax
  int v15; // [rsp+Ch] [rbp-4Ch]
  void *buf[9]; // [rsp+10h] [rbp-48h] BYREF

  buf[1] = (void *)__readfsqword(0x28u);
  if ( a4 )
    *a4 = 0;
  sub_CB20(a2, a3, (long long *)buf);
  if ( !v6 )
  {
    v7 = read(fd, buf[0], a3);
    v8 = __errno_location();
    v9 = 0;
    if ( v7 >= 0 )
      v9 = v7;
    v10 = *v8;
    v11 = v8;
    v12 = a3 - v9;
    if ( v12 && (v15 = *v8, sub_CE00((long long)a2, v12), v10 = v15, v14) )
    {
      memset((char *)buf[0] + v7, 0, v12);
    }
    else if ( v7 < 0 )
    {
      *v11 = v10;
    }
    else if ( v7 )
    {
      if ( a4 )
        *a4 = v7;
    }
    else
    {
      *v11 = 32;
    }
  }
  return 0.0;
}


// Function: get_ec @ 0x1cfb0
double get_ec(char *a1, long long a2, long long a3, long long a4)
{
  if ( (unsigned long long)(a2 - 1) > 0x84 )
    return 0.0;
  if ( *a1 != 4 )
    return 0.0;
  if ( a3 )
    EC_POINT_oct2point(a4, a3, a1, a2, 0);
  return 0.0;
}


// Function: sshbuf_get_bignum2 @ 0x1d220
double sshbuf_get_bignum2(long long a1, long long *a2)
{
  double v2; // xmm0_8
  int v3; // eax
  long long v4; // rax
  long long v5; // rbp
  char *v7; // [rsp+8h] [rbp-30h] BYREF
  long long v8[5]; // [rsp+10h] [rbp-28h] BYREF

  v8[1] = __readfsqword(0x28u);
  if ( a2 )
  {
    *a2 = 0;
    v2 = sub_1BBC0(a1, &v7, v8);
    if ( !v3 )
    {
      v4 = BN_new(v2);
      v5 = v4;
      if ( v4 && BN_bin2bn(v7, LODWORD(v8[0]), v4) )
        *a2 = v5;
      else
        BN_clear_free(v5, v2);
    }
  }
  else
  {
    sub_1BBC0(a1, &v7, v8);
  }
  return 0.0;
}


// Function: sshbuf_get_ec @ 0x1d360
double sshbuf_get_ec(long long a1, long long a2, long long a3)
{
  int v4; // eax
  int v5; // eax
  int v7; // eax
  char *v8; // [rsp+8h] [rbp-30h] BYREF
  long long v9[5]; // [rsp+10h] [rbp-28h] BYREF

  v9[1] = __readfsqword(0x28u);
  sub_1A330(a1, &v8, v9);
  if ( v4 >= 0 )
  {
    sub_1CFB0(v8, v9[0], a2, a3);
    if ( !v5 )
    {
      sub_1A460(a1, 0, 0);
      sub_3DAE0(v7 != 0);
    }
  }
  return 0.0;
}


// Function: sshbuf_get_eckey @ 0x1d480
double sshbuf_get_eckey(long long a1, long long a2)
{
  long long v2; // rax
  long long v3; // rax
  long long v4; // rbp
  int v5; // eax
  long long v6; // rax
  int v7; // eax
  int v8; // eax
  char *v10; // [rsp+8h] [rbp-40h] BYREF
  long long v11[7]; // [rsp+10h] [rbp-38h] BYREF

  v11[1] = __readfsqword(0x28u);
  v2 = EC_KEY_get0_group(a2);
  v3 = EC_POINT_new(v2);
  if ( v3 )
  {
    v4 = v3;
    sub_1A330(a1, &v10, v11);
    if ( v5 < 0
      || (v6 = EC_KEY_get0_group(a2), sub_1CFB0(v10, v11[0], v4, v6), v7)
      || (unsigned int)EC_KEY_set_public_key(a2, v4) != 1 )
    {
      EC_POINT_free(v4);
    }
    else
    {
      EC_POINT_free(v4);
      sub_1A460(a1, 0, 0);
      sub_3DAE0(v8 != 0);
    }
  }
  return 0.0;
}


// Function: sshbuf_put_bignum2 @ 0x1d610
double sshbuf_put_bignum2(long long *a1, long long a2)
{
  unsigned int v2; // eax
  int v3; // ebx
  int v4; // ebp
  unsigned int v5; // eax
  long long v6; // r13
  double v7; // xmm0_8
  char v9; // [rsp+10h] [rbp-838h] BYREF
  char v10[2055]; // [rsp+11h] [rbp-837h] BYREF
  unsigned long long v11; // [rsp+818h] [rbp-30h]

  v11 = __readfsqword(0x28u);
  v2 = BN_num_bits(a2);
  v3 = sub_3DA20(v2, 7);
  v4 = v3 / 8;
  if ( v5 <= 0x4007 )
  {
    v9 = 0;
    if ( (unsigned int)BN_bn2bin(a2, v10) == v4 )
    {
      v6 = 1;
      if ( v3 > 7 )
      {
        v6 = 1LL - (v10[0] >> 7);
        v4 = sub_3DA20((unsigned int)v4, v10[0] >> 7);
      }
      v7 = sub_1B6C0(a1, &v10[v6 - 1], v4);
      __explicit_bzero_chk(&v9, 2049, 2049, v7);
    }
  }
  return 0.0;
}


// Function: sshbuf_put_ec @ 0x1d7d0
double sshbuf_put_ec(long long *a1, long long a2, long long a3)
{
  unsigned long long v4; // rax
  unsigned long long v5; // rbx
  size_t v6; // rax
  size_t v7; // rbp
  double v8; // xmm0_8
  long long v10[23]; // [rsp+0h] [rbp-B8h] BYREF

  v10[17] = __readfsqword(0x28u);
  v4 = EC_POINT_point2oct(a3, a2, 4, 0, 0, 0);
  if ( v4 <= 0x85 )
  {
    v5 = v4;
    v6 = EC_POINT_point2oct(a3, a2, 4, v10, v4, 0);
    v7 = v6;
    if ( v6 == v5 )
    {
      v8 = sub_1B6C0(a1, v10, v6);
      __explicit_bzero_chk(v10, v7, 133, v8);
    }
  }
  return 0.0;
}


// Function: sshbuf_put_eckey @ 0x1d940
double sshbuf_put_eckey(long long *a1, long long a2, double a3)
{
  long long v3; // r13
  long long v4; // rax

  v3 = EC_KEY_get0_group(a2);
  v4 = EC_KEY_get0_public_key(a3);
  return sub_1D7D0(a1, v4, v3);
}


// Function: cipher_alg_list @ 0x1d980
double cipher_alg_list(char a1, int a2)
{
  int v2; // eax
  size_t v3; // r15
  char *v4; // r14
  char **i; // rbx
  size_t v6; // r12
  size_t v7; // rax
  size_t v8; // rbp
  char *v9; // rax

  LOBYTE(v2) = 1;
  v3 = 0;
  v4 = 0;
  for ( i = &off_67380; (v2 & 8) != 0 || a2 && !*((int *)i + 5); v2 = *((int *)i + 6) )
  {
LABEL_10:
    i += 5;
    if ( !*i )
      return 0.0;
  }
  v6 = v3;
  if ( v4 )
  {
    v6 = v3 + 1;
    v4[v3] = a1;
  }
  v7 = strlen(*i);
  v3 = v6 + v7;
  v8 = v7;
  v9 = (char *)realloc(v4, v6 + v7 + 2);
  if ( v9 )
  {
    v4 = v9;
    memcpy(&v9[v6], *i, v8 + 1);
    goto LABEL_10;
  }
  free(v4);
  return 0.0;
}


// Function: cipher_blocksize @ 0x1db60
double cipher_blocksize()
{
  return 0.0;
}


// Function: cipher_keylen @ 0x1dbf0
double cipher_keylen()
{
  return 0.0;
}


// Function: cipher_authlen @ 0x1dd30
double cipher_authlen()
{
  return 0.0;
}


// Function: cipher_ivlen @ 0x1ddc0
double cipher_ivlen(long long a1)
{
  if ( *(int *)(a1 + 16) || (*(char *)(a1 + 24) & 2) != 0 )
    return 0.0;
  else
    return 0.0;
}


// Function: cipher_by_name @ 0x1dff0
double cipher_by_name(char *s2)
{
  char **v1; // r12
  const char *v3; // rdi

  v1 = &off_67380;
  v3 = "3des-cbc";
  do
  {
    if ( !strcmp(v3, s2) )
      return 0.0;
    v3 = v1[5];
    v1 += 5;
  }
  while ( v3 );
  return 0.0;
}


// Function: ciphers_valid @ 0x1e150
double ciphers_valid(char *s)
{
  char *v2; // r12
  long long v3; // rax
  char *v4; // rax
  char *v5[5]; // [rsp+0h] [rbp-28h] BYREF

  v5[1] = (char *)__readfsqword(0x28u);
  if ( s )
  {
    if ( strcmp(s, "") )
    {
      v5[0] = strdup(s);
      v2 = v5[0];
      if ( v5[0] )
      {
        do
        {
          v4 = strsep(v5, ",");
          if ( !v4 )
            break;
          if ( !*v4 )
            break;
          sub_1DFF0(v4);
          if ( !v3 )
            break;
        }
        while ( (*(char *)(v3 + 24) & 8) == 0 );
        free(v2);
      }
    }
  }
  return 0.0;
}


// Function: cipher_init @ 0x1e340
double cipher_init(long long *a1, long long a2, long long a3, unsigned int a4, long long a5, unsigned int a6, int a7)
{
  long long v8; // rsi
  long long v13; // rdi
  int *v14; // rax
  long long v15; // rdx
  long long *v16; // r15
  long long v17; // rcx
  unsigned int v18; // eax
  long long v19; // rdx
  long long v20; // r13
  long long v21; // rax
  long long v22; // rdi
  double v23; // xmm0_8
  int v24; // eax
  int key_length; // eax
  long long v26; // rax
  unsigned int v29; // [rsp+8h] [rbp-40h]
  unsigned int v30; // [rsp+Ch] [rbp-3Ch]

  v8 = 1;
  *a1 = 0;
  v13 = 296;
  v14 = calloc(0x128u, 1u);
  if ( v14 )
  {
    v15 = *(unsigned int *)(a2 + 24);
    v16 = v14;
    v17 = *(int *)(a2 + 24) & 8;
    *v14 = (*(int *)(a2 + 24) & 8) != 0;
    v14[1] = a7;
    if ( *(int *)(a2 + 12) <= a4 )
    {
      if ( !a5 || (v13 = a2, v30 = v17, v29 = v15, sub_1DDC0(a2), v15 = v29, v17 = v30, v18 <= a6) )
      {
        v19 = v15 & 2;
        v16[36] = a2;
        if ( !(int)v19 )
        {
          if ( !(int)v17 )
          {
            v20 = (*(long long (**)(long long, long long, long long))(a2 + 32))(v13, 1, v19);
            v21 = EVP_CIPHER_CTX_new();
            v16[1] = v21;
            v22 = v21;
            if ( v21 )
            {
              v8 = v20;
              if ( (unsigned int)EVP_CipherInit(v21, v20, 0, a5, a7 == 1) )
              {
                v23 = sub_1DD30();
                if ( !v24 || (v8 = 18, (unsigned int)EVP_CIPHER_CTX_ctrl(v16[1], 18, 0xFFFFFFFFLL, a5, v23)) )
                {
                  key_length = EVP_CIPHER_CTX_get_key_length(v16[1], v23);
                  if ( key_length <= 0
                    || key_length == a4
                    || (v8 = a4, (unsigned int)EVP_CIPHER_CTX_set_key_length(v16[1], a4)) )
                  {
                    v8 = 0;
                    if ( (unsigned int)EVP_CipherInit(v16[1], 0, a3, 0, 0xFFFFFFFFLL) )
                      goto LABEL_15;
                  }
                }
              }
              v22 = v16[1];
            }
LABEL_18:
            EVP_CIPHER_CTX_free(v22, v8, v15, v17);
            sub_3B0D0(v16);
            return 0.0;
          }
LABEL_15:
          *a1 = v16;
          return 0.0;
        }
        v8 = a4;
        v26 = sub_2F2A0(a3, a4, v19, v17);
        v16[2] = v26;
        if ( v26 )
          goto LABEL_15;
      }
    }
    v22 = v16[1];
    goto LABEL_18;
  }
  return 0.0;
}


// Function: cipher_crypt @ 0x1e5a0
double cipher_crypt(
        long long a1,
        int a2,
        char *a3,
        char *a4,
        unsigned int a5,
        unsigned int a6,
        double a7,
        unsigned int a8)
{
  long long v12; // rbx
  long long v13; // rdi
  int v14; // eax
  int v15; // eax
  char v17; // [rsp+7h] [rbp-41h] BYREF
  unsigned long long v18; // [rsp+8h] [rbp-40h]

  v12 = a6;
  v13 = *(long long *)(a1 + 288);
  v18 = __readfsqword(0x28u);
  v14 = *(int *)(v13 + 24);
  if ( (v14 & 2) != 0 )
  {
    sub_2F3E0(*(long long *)(a1 + 16), a2, (int)a3, (int)a4, a5, a6, a8, *(int *)(a1 + 4));
    return 0.0;
  }
  if ( (v14 & 8) != 0 )
  {
    memcpy(a3, a4, a6 + a5);
    return 0.0;
  }
  if ( a8 )
  {
    a7 = sub_1DD30();
    if ( v15 != a8
      || !(unsigned int)EVP_CIPHER_CTX_ctrl(*(long long *)(a1 + 8), 19, 1, &v17, a7)
      || !*(int *)(a1 + 4)
      && !(unsigned int)EVP_CIPHER_CTX_ctrl(
                          *(long long *)(a1 + 8),
                          17,
                          a8,
                          &a4[a5 + (unsigned long long)(unsigned int)v12],
                          a7) )
    {
      return 0.0;
    }
    if ( !(int)v12 )
      goto LABEL_21;
    if ( (int)EVP_Cipher(*(long long *)(a1 + 8), 0, a4, (unsigned int)v12) < 0 )
      return 0.0;
LABEL_20:
    memcpy(a3, a4, (unsigned int)v12);
LABEL_21:
    v13 = *(long long *)(a1 + 288);
    goto LABEL_5;
  }
  if ( a6 )
    goto LABEL_20;
LABEL_5:
  if ( !(a5 % *(int *)(v13 + 8))
    && (int)EVP_Cipher(*(long long *)(a1 + 8), &a3[v12], &a4[v12], a5) >= 0
    && a8
    && (int)EVP_Cipher(*(long long *)(a1 + 8), 0, 0, 0) >= 0
    && *(int *)(a1 + 4) )
  {
    EVP_CIPHER_CTX_ctrl(*(long long *)(a1 + 8), 16, a8, &a3[v12 + a5], a7);
  }
  return 0.0;
}


// Function: cipher_free @ 0x1e970
double cipher_free(char *ptr, long long a2, long long a3, long long a4, double result)
{
  int v5; // eax

  if ( !ptr )
    return 0.0;
  v5 = *(int *)(*((long long *)ptr + 36) + 24LL);
  if ( (v5 & 2) != 0 )
  {
    sub_2F1F0(*((void **)ptr + 2));
    *((long long *)ptr + 2) = 0;
  }
  else if ( (v5 & 4) != 0 )
  {
    a2 = 260;
    __explicit_bzero_chk(ptr + 24, 260, -1, result);
  }
  EVP_CIPHER_CTX_free(*((long long *)ptr + 1), a2, a3, a4);
  *((long long *)ptr + 1) = 0;
  sub_3B0D0(ptr);
  return result;
}


// Function: cipher_get_keyiv @ 0x1eb90
double cipher_get_keyiv(long long a1, __m128i *a2, long long a3)
{
  int v3; // eax
  int iv_length; // eax
  unsigned int v6; // r13d
  long long v7; // r14
  double v8; // xmm0_8
  long long v9; // rdi
  int v10; // eax

  v3 = *(int *)(*(long long *)(a1 + 288) + 24LL);
  if ( (v3 & 2) == 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      if ( a3 == 16 )
        *a2 = _mm_loadu_si128((const __m128i *)(a1 + 268));
    }
    else if ( (v3 & 8) == 0 )
    {
      iv_length = EVP_CIPHER_CTX_get_iv_length(*(long long *)(a1 + 8));
      v6 = iv_length;
      if ( iv_length > 0 )
      {
        v7 = iv_length;
        if ( iv_length == a3 )
        {
          v8 = sub_1DD30();
          v9 = *(long long *)(a1 + 8);
          if ( v10 )
            EVP_CIPHER_CTX_ctrl(v9, 19, v6, a2, v8);
          else
            EVP_CIPHER_CTX_get_updated_iv(v9, a2, v7, v8);
        }
      }
    }
  }
  return 0.0;
}


// Function: cipher_set_keyiv @ 0x1ed10
double cipher_set_keyiv(long long a1, long long a2, long long a3)
{
  int iv_length; // eax
  long long v6; // r13
  double v7; // xmm0_8
  long long v8; // rdi
  int v9; // eax

  if ( (*(char *)(*(long long *)(a1 + 288) + 24LL) & 0xA) == 0 )
  {
    iv_length = EVP_CIPHER_CTX_get_iv_length(*(long long *)(a1 + 8));
    if ( iv_length > 0 )
    {
      v6 = iv_length;
      if ( iv_length == a3 )
      {
        v7 = sub_1DD30();
        v8 = *(long long *)(a1 + 8);
        if ( v9 )
          EVP_CIPHER_CTX_ctrl(v8, 18, 0xFFFFFFFFLL, a2, v7);
        else
          sub_37A90(v8, a2, v6, v7);
      }
    }
  }
  return 0.0;
}


// Function: sshfatal @ 0x1ee30
void sshfatal(char *a1, long long a2, long long a3, long long a4, long long a5, long long a6, long long a7, ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-D8h] BYREF
  unsigned long long v8; // [rsp+18h] [rbp-C0h]

  v8 = __readfsqword(0x28u);
  va_start(va, a7);
  sub_20120(a1, a7, (long long)va);
  sub_31220(255);
}


// Function: do_log @ 0x1eed0
double do_log(int a1, unsigned int a2, const char *a3, const char *a4, long long a5)
{
  int *v6; // rax
  long long v7; // r10
  const char *v8; // rdx
  const char *v9; // r13
  int *v10; // rbx
  int v11; // eax
  void (*v12)(long long, long long, char *, long long); // r14
  const char *v14; // rax
  size_t v15; // rax
  const char *v16; // r9
  unsigned int v18; // [rsp+8h] [rbp-860h]
  long long v20; // [rsp+10h] [rbp-858h]
  int v21; // [rsp+18h] [rbp-850h]
  char s[1024]; // [rsp+20h] [rbp-848h] BYREF
  char dest[1032]; // [rsp+420h] [rbp-448h] BYREF
  unsigned long long v24; // [rsp+828h] [rbp-40h]

  v24 = __readfsqword(0x28u);
  v6 = __errno_location();
  v7 = a5;
  v8 = a4;
  v9 = (const char *)qword_68090;
  v10 = v6;
  v11 = *v6;
  if ( !qword_68090 )
    v9 = _progname;
  v21 = v11;
  if ( a2 || dword_6801C >= a1 )
  {
    switch ( a1 )
    {
      case 1:
        v18 = 2;
        if ( dword_68018 )
          goto LABEL_7;
        v16 = "fatal";
        goto LABEL_19;
      case 2:
        v18 = 3;
        if ( dword_68018 )
          goto LABEL_7;
        v16 = "error";
LABEL_19:
        if ( qword_68088 )
        {
LABEL_7:
          __vsnprintf_chk(s, 1024, 1, 1024, a4, v7);
        }
        else
        {
          v20 = v7;
          __snprintf_chk(dest, 1024, 1, 1024, "%s: %s", v16, v8);
          __vsnprintf_chk(s, 1024, 1, 1024, dest, v20);
        }
        if ( a3 )
        {
          __snprintf_chk(dest, 1024, 1, 1024, "%s: %s", s, a3);
          sub_3BEE0(s, dest, 1024);
        }
        sub_3C8F0(dest);
        v12 = (void (*)(long long, long long, char *, long long))qword_68088;
        if ( qword_68088 )
        {
          qword_68088 = 0;
          v12((unsigned int)a1, a2, dest, qword_68080);
          qword_68088 = (long long)v12;
        }
        else if ( dword_68018 )
        {
          if ( dword_68018 <= 1 )
          {
            v9 = "";
            v14 = "";
          }
          else
          {
            v14 = ": ";
          }
          __snprintf_chk(s, 1024, 1, 1024, "%s%s%.*s\r\n", v9, v14, 1021, dest);
          v15 = strlen(s);
          write(fd, s, v15);
        }
        else
        {
          openlog(v9, 1, facility);
          __syslog_chk(v18, 1, "%.500s", dest);
          closelog();
        }
        *v10 = v21;
        break;
      case 3:
      case 4:
        v18 = 6;
        goto LABEL_7;
      case 5:
        v18 = 7;
        v16 = "debug1";
        goto LABEL_19;
      case 6:
        v18 = 7;
        v16 = "debug2";
        goto LABEL_19;
      case 7:
        v18 = a1;
        v16 = "debug3";
        goto LABEL_19;
      default:
        v18 = 3;
        v16 = "internal error";
        goto LABEL_19;
    }
  }
  return 0.0;
}


// Function: log_level_name @ 0x1f810
double log_level_name(int a1)
{
  char **v1; // rax
  int i; // edx
  char *v3; // r8

  v1 = &off_67050;
  for ( i = 0; a1 != i; i = *((int *)v1 - 2) )
  {
    v3 = *v1;
    v1 += 2;
    if ( !v3 )
      break;
  }
  return 0.0;
}


// Function: log_verbose_add @ 0x1f8d0
double log_verbose_add(char *s)
{
  char *v1; // rax
  long long v2; // rbx
  char **v3; // r12
  char *v4; // rax

  v1 = (char *)sub_3BA50(src);
  if ( v1 )
  {
    v2 = qword_68070;
    src = v1;
    v3 = (char **)&v1[8 * qword_68070];
    v4 = strdup(s);
    *v3 = v4;
    if ( v4 )
      qword_68070 = v2 + 1;
  }
  return 0.0;
}


// Function: log_verbose_reset @ 0x1f9b0
double log_verbose_reset()
{
  long long v0; // r12
  long long *v1; // rbp
  long long v2; // rbx
  void *v3; // rdi

  v0 = qword_68070;
  v1 = src;
  v2 = 0;
  if ( qword_68070 )
  {
    do
    {
      v3 = (void *)v1[v2++];
      free(v3);
    }
    while ( v2 != v0 );
  }
  free(v1);
  src = 0;
  qword_68070 = 0;
  return 0.0;
}


// Function: log_change_level @ 0x1fa90
double log_change_level(unsigned int a1)
{
  if ( !qword_68090 )
    return 0.0;
  if ( a1 <= 7 )
    dword_6801C = a1;
  return 0.0;
}


// Function: log_init @ 0x1fc40
void log_init(long long a1, unsigned int a2, unsigned int a3, int a4)
{
  const char *v5; // rbp
  double v7; // xmm0_8
  int v8; // eax
  int v9; // edx

  v5 = (const char *)a1;
  qword_68090 = a1;
  v7 = sub_1FA90(a2);
  if ( v8 )
  {
    __fprintf_chk(stderr, 1, "Unrecognized internal syslog level code %d\n", a2, v7);
LABEL_21:
    exit(1);
  }
  qword_68088 = 0;
  qword_68080 = 0;
  dword_68018 = a4;
  if ( !a4 )
  {
    switch ( a3 )
    {
      case 0u:
        v9 = 24;
        goto LABEL_6;
      case 1u:
        v9 = 8;
        goto LABEL_6;
      case 2u:
        v9 = 32;
        goto LABEL_6;
      case 3u:
        v9 = 80;
        goto LABEL_6;
      case 4u:
        v9 = 128;
        goto LABEL_6;
      case 5u:
        v9 = 136;
        goto LABEL_6;
      case 6u:
        v9 = 144;
        goto LABEL_6;
      case 7u:
        v9 = 152;
        goto LABEL_6;
      case 8u:
        v9 = 160;
        goto LABEL_6;
      case 9u:
        v9 = 168;
        goto LABEL_6;
      case 0xAu:
        v9 = 176;
        goto LABEL_6;
      case 0xBu:
        v9 = 184;
LABEL_6:
        if ( !a1 )
          v5 = _progname;
        facility = v9;
        openlog(v5, 1, v9);
        closelog();
        return;
      default:
        __fprintf_chk(stderr, 1, "Unrecognized internal syslog facility code %d\n", a3, v7);
        goto LABEL_21;
    }
  }
}


// Function: sshlogv @ 0x20120
double sshlogv(
        char *s,
        const char *a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        const char *a6,
        double a7,
        const char *a8,
        long long a9)
{
  char *v12; // rbx
  char *v13; // rax
  long long v14; // rbx
  long long v16; // [rsp+8h] [rbp-560h]
  char v18[128]; // [rsp+20h] [rbp-548h] BYREF
  char v19[1160]; // [rsp+A0h] [rbp-4C8h] BYREF
  unsigned long long v20; // [rsp+528h] [rbp-40h]

  v12 = s;
  v20 = __readfsqword(0x28u);
  v16 = getpid();
  v13 = strrchr(s, 47);
  if ( v13 )
    v12 = v13 + 1;
  __snprintf_chk(v18, 128, 1, 128, "%.48s:%.48s():%d (pid=%ld)", v12, a2, a3, v16);
  if ( qword_68070 )
  {
    v14 = 0;
    while ( (unsigned int)sub_20960(v18, *((long long *)src + v14), 0, a7) != 1 )
    {
      if ( qword_68070 <= (unsigned long long)++v14 )
        goto LABEL_9;
    }
    a4 = 1;
    __snprintf_chk(v19, 1152, 1, 1152, "%s: %s", v18, a8);
  }
  else
  {
LABEL_9:
    if ( a4 )
    {
      a4 = 0;
      __snprintf_chk(v19, 1152, 1, 1152, "%s: %s", a2, a8);
    }
    else
    {
      sub_3BEE0(v19, a8, 1152);
    }
  }
  sub_1EED0(a5, a4, a6, v19, a9);
  return 0.0;
}


// Function: sshlog @ 0x203a0
double sshlog(
        char *a1,
        const char *a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        const char *a6,
        const char *a7,
        ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-D8h] BYREF
  unsigned long long v9; // [rsp+18h] [rbp-C0h]
  __int128 v10; // [rsp+50h] [rbp-88h]

  va_start(va, a7);
  *(double *)&v10 = va_arg(va, double);
  va_end(va);
  va_start(va, a7);
  v9 = __readfsqword(0x28u);
  sub_20120(a1, a2, a3, a4, a5, a6, *(double *)&v10, a7, (long long)va);
  return 0.0;
}


// Function: sshlogdirect @ 0x20630
double sshlogdirect(int a1, unsigned int a2, const char *a3, ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-D8h] BYREF
  unsigned long long v5; // [rsp+18h] [rbp-C0h]

  va_start(va, a3);
  v5 = __readfsqword(0x28u);
  sub_1EED0(a1, a2, 0, a3, (long long)va);
  return 0.0;
}


// Function: match_pattern @ 0x20770
double match_pattern(char *a1, char *a2, double a3)
{
  char v4; // al
  char *v5; // rbx
  char v6; // r12
  char v7; // al
  char *v9; // rbx

  v4 = *a2;
  v5 = a2;
  if ( !*a2 )
    return 0.0;
  while ( v4 != 42 )
  {
    if ( !*a1 || v4 != 63 && *a1 != v4 )
      return 0.0;
    v4 = *++v5;
    ++a1;
    if ( !v4 )
      return 0.0;
  }
  while ( 1 )
  {
    v6 = *v5;
    if ( *v5 != 42 )
      break;
    ++v5;
  }
  if ( v6 )
  {
    v7 = *a1;
    if ( v6 == 63 )
    {
      if ( v7 )
      {
        do
        {
          if ( (unsigned int)match_pattern(a1, v5, a3) )
            break;
          ++a1;
        }
        while ( *a1 );
      }
    }
    else if ( v7 )
    {
      v9 = v5 + 1;
      do
      {
        ++a1;
        if ( v6 == v7 && (unsigned int)match_pattern(a1, v9, a3) )
          break;
        v7 = *a1;
      }
      while ( *a1 );
    }
  }
  return 0.0;
}


// Function: match_pattern_list @ 0x20960
double match_pattern_list(char *a1, const char *a2, int a3, double a4)
{
  unsigned int v6; // eax
  unsigned int v8; // r12d
  unsigned int v9; // r14d
  long long i; // r8
  bool v11; // zf
  long long v12; // r13
  long long v13; // rax
  char v14; // si
  unsigned int v15; // r15d
  int v16; // eax
  int v17; // eax
  int v18; // eax
  long long v19; // [rsp+8h] [rbp-460h]
  int v20; // [rsp+1Ch] [rbp-44Ch]
  char v21[1032]; // [rsp+20h] [rbp-448h] BYREF
  unsigned long long v22; // [rsp+428h] [rbp-40h]

  v22 = __readfsqword(0x28u);
  v6 = strlen(a2);
  if ( v6 )
  {
    v8 = v6;
    v9 = 0;
    for ( i = 0; ; i = v9 )
    {
LABEL_4:
      v11 = a2[i] == 33;
      v20 = 0;
      if ( v11 )
      {
        v20 = 1;
        ++v9;
      }
      v12 = 1;
      v13 = 0;
      if ( v8 > v9 )
        break;
LABEL_15:
      v21[v13] = 0;
      a4 = sub_20770(a1, v21, a4);
      if ( !v16 )
        return 0.0;
LABEL_16:
      if ( v20 )
        return 0.0;
LABEL_17:
      if ( v8 <= v9 )
        return 0.0;
    }
    while ( 1 )
    {
      v15 = v12;
      v13 = (unsigned int)(v12 - 1);
      v14 = a2[v9];
      if ( v14 == 44 )
        break;
      if ( a3 )
      {
        v19 = (unsigned char)a2[v9];
        v14 = v19;
        if ( ((*__ctype_b_loc())[(unsigned char)v19] & 0x100) != 0 )
          v14 = (*__ctype_tolower_loc())[v19];
      }
      ++v9;
      v21[v12++ - 1] = v14;
      if ( v8 <= v9 || v15 > 0x3FE )
      {
        if ( v15 == 1023 )
          return 0.0;
        if ( v8 <= v9 )
        {
          v13 = v15;
          goto LABEL_15;
        }
        if ( a2[v9] != 44 )
        {
          v21[v15] = 0;
          a4 = sub_20770(a1, v21, a4);
          i = v9;
          if ( v17 && v20 )
            return 0.0;
          goto LABEL_4;
        }
        v13 = v15;
LABEL_26:
        ++v9;
        v21[v13] = 0;
        a4 = sub_20770(a1, v21, a4);
        if ( !v18 )
          goto LABEL_17;
        goto LABEL_16;
      }
    }
    if ( v8 <= v9 )
      goto LABEL_15;
    goto LABEL_26;
  }
  return 0.0;
}


// Function: filter_list @ 0x20c10
double filter_list(char *s, const char *a2, char a3, double a4)
{
  char *v5; // r14
  char *v6; // rax
  char v7; // bl
  int v8; // eax
  char *v9; // rax
  char *v10; // r15
  char *ptr; // [rsp+0h] [rbp-58h]
  size_t v13; // [rsp+8h] [rbp-50h]
  char *stringp[9]; // [rsp+10h] [rbp-48h] BYREF

  stringp[1] = (char *)__readfsqword(0x28u);
  v13 = strlen(s) + 1;
  v5 = malloc(v13);
  v6 = strdup(s);
  ptr = v6;
  if ( v5 && v6 )
  {
    *v5 = 0;
    v7 = a3 & 1;
    stringp[0] = v6;
    while ( 1 )
    {
      v9 = strsep(stringp, ",");
      v10 = v9;
      if ( !v9 )
        break;
      a4 = sub_20960(v9, a2, 0, a4);
      if ( v7 != (v8 == 1) )
      {
        if ( *v5 )
          sub_3BCF0(v5, ",", v13);
        sub_3BCF0(v5, v10, v13);
      }
    }
    free(ptr);
  }
  else
  {
    free(v6);
    free(v5);
  }
  return 0.0;
}


// Function: match_hostname @ 0x20dd0
double match_hostname(void *a1, const char *a2)
{
  char *v2; // rbp
  double v3; // xmm0_8

  v2 = (char *)sub_21840(a1);
  v3 = sub_27D90(v2);
  sub_20960(v2, a2, 1, v3);
  free(v2);
  return 0.0;
}


// Function: match_host_and_ip @ 0x20e90
double match_host_and_ip(void *a1, long long a2, const char *a3)
{
  int v4; // ebx
  int v5; // eax

  v4 = sub_21AA0(a2, a3);
  if ( v4 == -2 )
    return 0.0;
  if ( a2 == 0 || a1 == 0 )
    return 0.0;
  if ( v4 == -1 )
    return 0.0;
  sub_20DD0(a1, a3);
  if ( v5 == -1 )
    return 0.0;
  else
    return 0.0;
}


// Function: match_user @ 0x21020
double match_user(char *a1, unsigned long long a2, long long a3, char *a4, double a5)
{
  unsigned long long v7; // rbx
  char *v8; // rax
  char *v9; // r15
  char *v10; // rax
  char *v11; // rbx
  int v12; // eax
  unsigned int v14; // eax

  v7 = (unsigned long long)a1 | a3 | a2;
  v8 = strchr(a4, 64);
  if ( !v7 )
  {
    if ( v8 )
    {
      sub_20E90(0, 0, v8 + 1);
      sub_3DAE0(v14 >> 31);
    }
    return 0.0;
  }
  if ( v8 )
  {
    v9 = (char *)sub_21840(a4);
    v10 = strchr(v9, 64);
    *v10 = 0;
    v11 = v10;
    sub_20770(a1, v9, a5);
    if ( v12 == 1 )
      sub_20E90((void *)a2, a3, v11 + 1);
    free(v9);
    return 0.0;
  }
  return sub_20770(a1, a4, a5);
}


// Function: match_list @ 0x211a0
double match_list(void *a1, void *a2, int *a3, double a4)
{
  int v4; // ebx
  char *v5; // r13
  char *v6; // rax
  long long v7; // r15
  char *v8; // r14
  const char **v9; // r15
  int v10; // eax
  char *ptr; // [rsp+10h] [rbp-1A8h]
  char *v14; // [rsp+20h] [rbp-198h] BYREF
  char *stringp; // [rsp+28h] [rbp-190h] BYREF
  long long v16[49]; // [rsp+30h] [rbp-188h] BYREF

  v4 = 0;
  v16[41] = __readfsqword(0x28u);
  v14 = (char *)sub_21840(a1);
  v5 = v14;
  ptr = (char *)sub_21840(a2);
  stringp = ptr;
  v6 = strsep(&stringp, ",");
  if ( v6 )
  {
    v7 = 0;
    do
    {
      v4 = v7;
      if ( !*v6 )
        break;
      if ( v7 == 40 )
      {
        v4 = 40;
        break;
      }
      v16[v7] = v6;
      v4 = v7 + 1;
      v6 = strsep(&stringp, ",");
      ++v7;
    }
    while ( v6 );
  }
  v8 = strsep(&v14, ",");
  if ( v8 )
  {
    while ( *v8 )
    {
      v9 = (const char **)v16;
      if ( v4 )
      {
        while ( strcmp(v8, *v9) )
        {
          if ( ++v9 == &v16[(unsigned int)(v4 - 1) + 1] )
            goto LABEL_17;
        }
        sub_21840(v8);
        if ( a3 )
        {
          if ( v14 )
            v10 = sub_3DA40(v14, v5, a4);
          else
            v10 = strlen(v5);
          *a3 = v10;
        }
        goto LABEL_16;
      }
LABEL_17:
      v8 = strsep(&v14, ",");
      if ( !v8 )
        break;
    }
  }
  if ( a3 )
    *a3 = strlen(v5);
LABEL_16:
  free(v5);
  free(ptr);
  return 0.0;
}


// Function: xmalloc @ 0x21440
double xmalloc(size_t a1)
{
  long long v1; // rax

  if ( !a1 )
    sub_1EE30("xmalloc.c", (long long)"xmalloc", 39, 0, 1, 0, (long long)"xmalloc: zero size", v1);
  if ( !malloc(a1) )
    sub_1EE30(
      "xmalloc.c",
      (long long)"xmalloc",
      42,
      0,
      1,
      0,
      (long long)"xmalloc: out of memory (allocating %zu bytes)",
      a1);
  return 0.0;
}


// Function: xcalloc @ 0x21540
double xcalloc(unsigned long long a1, unsigned long long a2, long long a3)
{
  if ( !a2 || !a1 )
    sub_1EE30("xmalloc.c", (long long)"xcalloc", 52, 0, 1, 0, (long long)"xcalloc: zero size", a3);
  if ( !is_mul_ok(a1, a2) )
    sub_1EE30("xmalloc.c", (long long)"xcalloc", 54, 0, 1, 0, (long long)"xcalloc: nmemb * size > SIZE_MAX", a1 * a2);
  if ( !calloc(a1, a2) )
    sub_1EE30(
      "xmalloc.c",
      (long long)"xcalloc",
      57,
      0,
      1,
      0,
      (long long)"xcalloc: out of memory (allocating %zu bytes)",
      a1 * a2);
  return 0.0;
}


// Function: xreallocarray @ 0x21680
double xreallocarray(long long a1, long long a2, long long a3)
{
  if ( !reallocarray() )
    sub_1EE30(
      "xmalloc.c",
      (long long)"xreallocarray",
      69,
      0,
      1,
      0,
      (long long)"xreallocarray: out of memory (%zu elements of %zu bytes)",
      a2,
      a3);
  return 0.0;
}


// Function: xrecallocarray @ 0x21760
double xrecallocarray(void *a1, long long a2, long long a3, long long a4)
{
  if ( !sub_3BA50(a1) )
    sub_1EE30(
      "xmalloc.c",
      (long long)"xrecallocarray",
      81,
      0,
      1,
      0,
      (long long)"xrecallocarray: out of memory (%zu elements of %zu bytes)",
      a3,
      a4);
  return 0.0;
}


// Function: xstrdup @ 0x21840
void *xstrdup(const char *src)
{
  size_t v1; // r12
  void *v2; // rax

  v1 = strlen(src) + 1;
  sub_21440(v1);
  return memcpy(v2, src, v1);
}


// Function: xvasprintf @ 0x21880
double xvasprintf(long long *a1, long long a2, long long a3)
{
  long long v3; // rax

  v3 = __vasprintf_chk(a1, 1, a2, a3);
  if ( (int)v3 < 0 || !*a1 )
    sub_1EE30("xmalloc.c", (long long)"xvasprintf", 104, 0, 1, 0, (long long)"xvasprintf: could not allocate memory", v3);
  return 0.0;
}


// Function: xasprintf @ 0x21960
double xasprintf(long long *a1, long long a2, ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-D8h] BYREF
  unsigned long long v4; // [rsp+18h] [rbp-C0h]

  va_start(va, a2);
  v4 = __readfsqword(0x28u);
  sub_21880(a1, a2, (long long)va);
  return 0.0;
}


// Function: addr_match_list @ 0x21aa0
double addr_match_list(char *a1, const char *a2, double a3)
{
  char *v3; // rax
  char *v4; // r12
  char v5; // bl
  char v6; // al
  int v7; // eax
  int v8; // eax
  char *ptr; // [rsp+18h] [rbp-90h]
  unsigned int v11; // [rsp+24h] [rbp-84h] BYREF
  char *stringp; // [rsp+28h] [rbp-80h] BYREF
  char v13[32]; // [rsp+30h] [rbp-78h] BYREF
  char v14[24]; // [rsp+50h] [rbp-58h] BYREF
  unsigned long long v15; // [rsp+68h] [rbp-40h]

  v15 = __readfsqword(0x28u);
  if ( a1 && (unsigned int)sub_325D0(a1, v13) )
  {
    sub_203A0("addrmatch.c", "addr_match_list", 0x39u, 1u, 6, 0, "couldn't parse address %.100s", a1);
    return 0.0;
  }
  ptr = strdup(a2);
  stringp = ptr;
  if ( !ptr )
    return 0.0;
  while ( 1 )
  {
    v3 = strsep(&stringp, ",");
    v4 = v3;
    if ( !v3 )
      break;
    v6 = *v3;
    v5 = v6;
    if ( v6 == 33 )
      v6 = *++v4;
    if ( !v6 )
      break;
    v7 = sub_329D0(v4, v14, &v11);
    if ( v7 == -2 )
    {
      sub_203A0(
        "addrmatch.c",
        "addr_match_list",
        0x49u,
        1u,
        6,
        0,
        "inconsistent mask length for match network \"%.100s\"",
        v4);
      break;
    }
    if ( v7 )
    {
      if ( a1 )
      {
        a3 = sub_20770(a1, v4, a3);
        if ( v8 == 1 )
          goto LABEL_12;
      }
    }
    else if ( a1 && !(unsigned int)sub_32BD0(v13, v14, v11) )
    {
LABEL_12:
      if ( v5 == 33 )
        break;
    }
  }
  free(ptr);
  return 0.0;
}


// Function: addr_match_cidr_list @ 0x21d30
double addr_match_cidr_list(const char *a1, const char *a2)
{
  char *v2; // rax
  const char *v3; // r13
  size_t v4; // r12
  int v5; // eax
  bool v6; // zf
  int v7; // eax
  unsigned int v9; // ecx
  unsigned int v10; // edx
  const char *v11; // [rsp-10h] [rbp-B8h]
  int v12; // [rsp+Ch] [rbp-9Ch]
  char *ptr; // [rsp+18h] [rbp-90h]
  unsigned int v14; // [rsp+24h] [rbp-84h] BYREF
  char *stringp; // [rsp+28h] [rbp-80h] BYREF
  char v16[32]; // [rsp+30h] [rbp-78h] BYREF
  char v17[24]; // [rsp+50h] [rbp-58h] BYREF
  unsigned long long v18; // [rsp+68h] [rbp-40h]

  v18 = __readfsqword(0x28u);
  if ( a1 && (unsigned int)sub_325D0(a1, v16) )
  {
    sub_203A0("addrmatch.c", "addr_match_cidr_list", 0x75u, 1u, 6, 0, "couldn't parse address %.100s", a1);
  }
  else
  {
    ptr = strdup(a2);
    stringp = ptr;
    if ( ptr )
    {
      v12 = 0;
      while ( 1 )
      {
        v2 = strsep(&stringp, ",");
        v3 = v2;
        if ( !v2 )
          break;
        if ( !*v2 )
        {
          v11 = "empty entry in list \"%.100s\"";
          v9 = 1;
          v10 = 124;
LABEL_20:
          sub_203A0("addrmatch.c", "addr_match_cidr_list", v10, v9, 2, 0, v11);
          break;
        }
        v4 = strlen(v2);
        if ( v4 > 0x31 )
        {
          v9 = 1;
          v10 = 137;
          v11 = "list entry \"%.100s\" too long";
          goto LABEL_20;
        }
        if ( v4 != strspn(v3, "0123456789abcdefABCDEF.:/") )
        {
          sub_203A0(
            "addrmatch.c",
            "addr_match_cidr_list",
            0x8Fu,
            1u,
            2,
            0,
            "list entry \"%.100s\" contains invalid characters",
            v3);
          v12 = -1;
        }
        v5 = sub_329D0(v3, v17, &v14);
        if ( v5 == -1 )
        {
          v9 = 0;
          v11 = "Invalid network entry \"%.100s\"";
          v10 = 151;
          goto LABEL_20;
        }
        if ( v5 == -2 )
        {
          v9 = 0;
          v11 = "Inconsistent mask length for network \"%.100s\"";
          v10 = 155;
          goto LABEL_20;
        }
        if ( !v5 && a1 )
        {
          v6 = (unsigned int)sub_32BD0(v16, v17, v14) == 0;
          v7 = 1;
          if ( !v6 )
            v7 = v12;
          v12 = v7;
        }
      }
      free(ptr);
    }
  }
  return 0.0;
}


// Function: hexchar @ 0x22040
double hexchar(char *a1)
{
  char v1; // dl
  char v2; // cl

  v1 = *a1;
  if ( (unsigned char)(*a1 - 48) > 9u )
  {
    if ( (unsigned char)(v1 - 97) <= 5u )
    {
      v2 = a1[1];
      if ( (unsigned char)(v2 - 48) <= 9u )
        return 0.0;
      goto LABEL_5;
    }
    if ( (unsigned char)(v1 - 65) > 5u )
      return 0.0;
  }
  v2 = a1[1];
  if ( (unsigned char)(v2 - 48) <= 9u )
    return 0.0;
LABEL_5:
  if ( (unsigned char)(v2 - 97) <= 5u )
    return 0.0;
  if ( (unsigned char)(v2 - 65) <= 5u )
    return 0.0;
  return 0.0;
}


// Function: strdelim_internal @ 0x22250
double strdelim_internal(const char **a1, int a2)
{
  bool v2; // zf
  const char *v5; // rsi
  const char *v6; // rdi
  char *v7; // rax
  char *v8; // rbp
  char v9; // r14
  const char *v10; // rbp
  const char *v11; // rdi
  size_t v12; // rbp
  size_t v14; // rax
  char *v15; // rax
  const char *v16; // rbp

  if ( !*a1 )
    return 0.0;
  v2 = a2 == 0;
  v5 = " \t\r\n\"=";
  v6 = *a1;
  if ( v2 )
    v5 = " \t\r\n\"";
  v7 = strpbrk(v6, v5);
  *a1 = v7;
  v8 = v7;
  if ( !v7 )
    return 0.0;
  v9 = *v7;
  if ( *v7 == 34 )
  {
    v14 = strlen(v7);
    memmove(v8, v8 + 1, v14);
    v15 = strpbrk(*a1, "\"");
    *a1 = v15;
    if ( v15 )
    {
      *v15 = 0;
      v16 = *a1;
      *a1 = &v16[strspn(*a1 + 1, " \t\r\n") + 1];
      return 0.0;
    }
    return 0.0;
  }
  *v7 = 0;
  v10 = *a1;
  v11 = *a1 + 1;
  if ( a2 )
  {
    v12 = (size_t)&v10[strspn(v11, " \t\r\n") + 1];
    *a1 = (const char *)v12;
    if ( *(char *)v12 == 61 && v9 != 61 )
      *a1 = (const char *)(v12 + strspn((const char *)(v12 + 1), " \t\r\n") + 1);
    return 0.0;
  }
  *a1 = &v10[strspn(v11, " \t\r\n") + 1];
  return 0.0;
}


// Function: urldecode @ 0x22610
double urldecode(const char *a1)
{
  const char *v1; // rbp
  size_t v2; // rax
  char *v3; // r12
  char *v4; // rax
  char *v5; // rbx
  char *v6; // rcx
  const char *v7; // rdx
  const unsigned short *v8; // rax

  v1 = a1;
  v2 = strlen(a1);
  sub_21440(v2 + 1);
  v3 = v4;
  LOBYTE(v4) = *a1;
  if ( *a1 )
  {
    v5 = v3 + 1;
    while ( 1 )
    {
      if ( (char)v4 == 37 )
      {
        v8 = *__ctype_b_loc();
        if ( (v8[*((unsigned char *)v1 + 1)] & 0x1000) == 0
          || (v8[*((unsigned char *)v1 + 2)] & 0x1000) == 0
          || (sub_22040((char *)v1 + 1), (int)v4 == -1) )
        {
          free(v3);
          return 0.0;
        }
        v6 = v5;
        v7 = v1 + 2;
      }
      else
      {
        v6 = v5;
        v7 = v1;
        if ( (char)v4 == 43 )
          LOBYTE(v4) = 32;
      }
      *(v5 - 1) = (char)v4;
      LOBYTE(v4) = v7[1];
      v1 = v7 + 1;
      ++v5;
      if ( !(char)v4 )
        goto LABEL_12;
    }
  }
  v6 = v3;
LABEL_12:
  *v6 = 0;
  return 0.0;
}


// Function: vdollar_percent_expand @ 0x227d0
double vdollar_percent_expand(int *a1, char a2, int a3, char *a4, int *a5)
{
  long long *v9; // rax
  double v10; // xmm0_8
  long long *v11; // r15
  char v12; // al
  char v13; // si
  char *v14; // r12
  unsigned int v15; // eax
  long long v16; // r14
  const char *v17; // r13
  size_t v18; // rax
  unsigned int v19; // eax
  unsigned int v20; // edx
  const char **v21; // rdx
  unsigned int i; // esi
  const char **v23; // rcx
  const char *v24; // rdi
  unsigned int v25; // eax
  const char **v26; // rcx
  const char *v27; // rax
  unsigned int v28; // eax
  const char **v29; // rcx
  const char *v30; // r14
  char *v31; // rax
  char *v32; // r12
  long long v33; // rax
  long long v34; // r13
  char *v35; // rax
  char *v36; // rbx
  char *v37; // rax
  const char *v38; // rbp
  size_t v39; // rax
  unsigned int v40; // eax
  unsigned int v42; // eax
  long long v43; // rdx
  unsigned long long v44; // rax
  long long *v45; // rdx
  long long v46; // rdx
  double v47; // xmm0_8
  long long v48; // rax
  char *v49; // rax
  char *v50; // rax
  long long v51; // r10
  char *v52; // rax
  const char *v53; // [rsp-10h] [rbp-188h]
  char v54; // [rsp+Eh] [rbp-16Ah]
  char v55; // [rsp+Fh] [rbp-169h]
  char *v56; // [rsp+10h] [rbp-168h]
  unsigned int v58; // [rsp+28h] [rbp-150h]
  int v59; // [rsp+2Ch] [rbp-14Ch]
  char v60[8]; // [rsp+30h] [rbp-148h] BYREF
  long long s[32]; // [rsp+38h] [rbp-140h]
  unsigned long long v62; // [rsp+138h] [rbp-40h]

  v62 = __readfsqword(0x28u);
  v10 = sub_B880();
  if ( !v9 )
    sub_1EE30("misc.c", (long long)"vdollar_percent_expand", 1235, 1, 1, 0, (long long)"sshbuf_new failed", v10, 0);
  v11 = v9;
  *a1 = 1;
  if ( a3 )
  {
    v21 = (const char **)v60;
    for ( i = 0; i != 16; ++i )
    {
      v28 = *a5;
      if ( (unsigned int)*a5 <= 0x2F )
      {
        v23 = (const char **)(*((long long *)a5 + 2) + v28);
        *a5 = v28 + 8;
        v24 = *v23;
        *v21 = *v23;
        if ( !v24 )
          goto LABEL_30;
      }
      else
      {
        v29 = (const char **)*((long long *)a5 + 1);
        *((long long *)a5 + 1) = v29 + 1;
        v24 = *v29;
        *v21 = *v29;
        if ( !v24 )
        {
LABEL_30:
          v58 = i;
          if ( !i )
            sub_1EE30(
              "misc.c",
              (long long)"vdollar_percent_expand",
              1255,
              1,
              1,
              0,
              (long long)"percent expansion without token list",
              v10,
              v11);
          goto LABEL_4;
        }
      }
      v25 = *a5;
      if ( (unsigned int)*a5 > 0x2F )
      {
        v26 = (const char **)*((long long *)a5 + 1);
        *((long long *)a5 + 1) = v26 + 1;
      }
      else
      {
        v26 = (const char **)(*((long long *)a5 + 2) + v25);
        *a5 = v25 + 8;
      }
      v27 = *v26;
      v21[1] = *v26;
      if ( !v27 )
        sub_1EE30(
          "misc.c",
          (long long)"vdollar_percent_expand",
          1248,
          1,
          1,
          0,
          (long long)"NULL replacement for token %s",
          v24);
      v21 += 2;
    }
    v42 = *a5;
    v58 = 16;
    if ( (unsigned int)*a5 > 0x2F )
    {
      v45 = (long long *)*((long long *)a5 + 1);
      v44 = (unsigned long long)(v45 + 1);
      *((long long *)a5 + 1) = v45 + 1;
    }
    else
    {
      v43 = v42;
      v44 = v42 + 8;
      v45 = (long long *)(*((long long *)a5 + 2) + v43);
      *a5 = v44;
    }
    if ( *v45 )
      sub_1EE30("misc.c", (long long)"vdollar_percent_expand", 1253, 1, 1, 0, (long long)"too many keys", v10, v44);
  }
  else
  {
    v58 = 0;
  }
LABEL_4:
  v12 = *a4;
  if ( !*a4 )
  {
LABEL_47:
    v47 = sub_1C770((long long)v11);
    if ( !v48 )
      sub_1EE30(
        "misc.c",
        (long long)"vdollar_percent_expand",
        1321,
        1,
        1,
        0,
        (long long)"sshbuf_dup_string failed",
        v47,
        v46);
    goto LABEL_39;
  }
  v59 = 0;
  v54 = a2 & 1;
  v55 = (a3 ^ 1) & 1;
  do
  {
    while ( v12 != 36 || !v54 )
    {
      if ( v12 != 37 || v55 )
      {
LABEL_6:
        v13 = *a4;
        v14 = a4;
LABEL_7:
        v10 = sub_1B180(v11, v13);
        if ( v15 )
        {
          v49 = sub_B050(v15);
          sub_1EE30(
            "misc.c",
            (long long)"vdollar_percent_expand",
            1296,
            1,
            1,
            (long long)v49,
            (long long)"sshbuf_put_u8 %%",
            v10);
        }
        goto LABEL_8;
      }
      v13 = a4[1];
      v14 = a4 + 1;
      if ( v13 == 37 )
        goto LABEL_7;
      if ( !v13 )
      {
        v53 = "invalid format";
        v20 = 1304;
        goto LABEL_51;
      }
      if ( !v58 )
        goto LABEL_21;
      v56 = a4 + 1;
      v16 = 0;
      while ( !strchr(*(const char **)&v60[16 * v16], v13) )
      {
        if ( ++v16 == v58 )
          goto LABEL_21;
      }
      v14 = v56;
      v17 = (const char *)s[2 * (unsigned int)v16];
      v18 = strlen(v17);
      v10 = sub_1A9D0(v11, v17, v18);
      if ( v19 )
      {
        v52 = sub_B050(v19);
        sub_1EE30(
          "misc.c",
          (long long)"vdollar_percent_expand",
          1311,
          1,
          1,
          (long long)v52,
          (long long)"sshbuf_put %%-repl",
          v10,
          v17);
      }
      if ( (unsigned int)v16 >= v58 )
      {
LABEL_21:
        v53 = "unknown key %%%c";
        v20 = 1316;
LABEL_51:
        sub_203A0("misc.c", "vdollar_percent_expand", v20, 1u, 2, 0, v53, v10);
        goto LABEL_40;
      }
LABEL_8:
      v12 = v14[1];
      a4 = v14 + 1;
      if ( !v12 )
        goto LABEL_38;
    }
    if ( a4[1] != 123 )
      goto LABEL_6;
    v30 = a4 + 2;
    v31 = strchr(v30, 125);
    v32 = v31;
    if ( !v31 )
    {
      sub_203A0(
        "misc.c",
        "vdollar_percent_expand",
        0x4F0u,
        1u,
        2,
        0,
        "environment variable '%s' missing closing '}'",
        v30);
      goto LABEL_40;
    }
    v33 = sub_3DA40(v31, v30, v10);
    if ( !v33 )
    {
      v53 = "zero-length environment variable";
      v20 = 1270;
      goto LABEL_51;
    }
    v34 = v33 + 1;
    sub_21440(v33 + 1);
    v36 = v35;
    sub_3BEE0(v35, v30, v34);
    v37 = getenv(v36);
    v38 = v37;
    if ( v37 )
    {
      sub_203A0("misc.c", "vdollar_percent_expand", 0x4FFu, 1u, 7, 0, "expand ${%s} -> '%s'", v36, v37);
      v39 = strlen(v38);
      v10 = sub_1A9D0(v11, v38, v39);
      if ( v40 )
      {
        v50 = sub_B050(v40);
        sub_1EE30(
          "misc.c",
          (long long)"vdollar_percent_expand",
          1281,
          1,
          1,
          (long long)v50,
          (long long)"sshbuf_put ${}",
          v10,
          v51);
      }
    }
    else
    {
      v10 = sub_203A0("misc.c", "vdollar_percent_expand", 0x4FCu, 1u, 2, 0, "env var ${%s} has no value", v36);
      v59 = 1;
    }
    a4 = v32 + 1;
    free(v36);
    v12 = v32[1];
  }
  while ( v12 );
LABEL_38:
  if ( !v59 )
    goto LABEL_47;
LABEL_39:
  *a1 = 0;
LABEL_40:
  sub_BCE0(v11);
  return 0.0;
}


// Function: strcmp_maybe_null @ 0x22ec0
double strcmp_maybe_null(const char *a1, const char *a2)
{
  if ( (a1 == 0) != (a2 == 0) || !a1 )
    return 0.0;
  strcmp(a1, a2);
  return 0.0;
}


// Function: rtrim @ 0x231c0
double rtrim(const char *a1)
{
  size_t v1; // rax
  size_t v2; // rbp
  const unsigned short **v3; // rax
  const char *v4; // rdx

  v1 = strlen(a1);
  if ( v1 > 1 )
  {
    v2 = v1;
    v3 = __ctype_b_loc();
    v4 = &a1[v2 - 1];
    do
    {
      if ( ((*v3)[*v4] & 0x2000) != 0 )
        *v4 = 0;
      --v4;
    }
    while ( a1 != v4 );
  }
  return 0.0;
}


// Function: set_nonblock @ 0x23290
double set_nonblock(int fd)
{
  int v1; // eax
  unsigned int v2; // ebx
  double v3; // xmm0_8
  long long v4; // rdx
  int *v6; // rax
  char *v7; // rax
  int *v8; // rax
  char *v9; // rax

  v1 = fcntl(fd, 3);
  if ( v1 == -1 )
  {
    v6 = __errno_location();
    v7 = strerror(*v6);
    sub_203A0("misc.c", "set_nonblock", 0x6Fu, 0, 2, 0, "fcntl(%d, F_GETFL): %s", fd, v7);
    return 0.0;
  }
  v2 = v1;
  if ( (v1 & 0x800) == 0 )
  {
    v3 = sub_203A0("misc.c", "set_nonblock", 0x76u, 0, 6, 0, "fd %d setting O_NONBLOCK", fd);
    v4 = v2;
    BYTE1(v4) = BYTE1(v2) | 8;
    if ( fcntl(fd, 4, v4, v3) == -1 )
    {
      v8 = __errno_location();
      v9 = strerror(*v8);
      sub_203A0("misc.c", "set_nonblock", 0x79u, 0, 5, 0, "fcntl(%d, F_SETFL, O_NONBLOCK): %s", fd, v9);
    }
    return 0.0;
  }
  sub_203A0("misc.c", "set_nonblock", 0x73u, 0, 7, 0, "fd %d is O_NONBLOCK", fd);
  return 0.0;
}


// Function: unset_nonblock @ 0x234f0
double unset_nonblock(int fd)
{
  int v1; // eax
  unsigned int v2; // ebx
  double v3; // xmm0_8
  long long v4; // rdx
  int *v6; // rax
  char *v7; // rax
  int *v8; // rax
  char *v9; // rax

  v1 = fcntl(fd, 3);
  if ( v1 == -1 )
  {
    v6 = __errno_location();
    v7 = strerror(*v6);
    sub_203A0("misc.c", "unset_nonblock", 0x87u, 0, 2, 0, "fcntl(%d, F_GETFL): %s", fd, v7);
    return 0.0;
  }
  v2 = v1;
  if ( (v1 & 0x800) != 0 )
  {
    v3 = sub_203A0("misc.c", "unset_nonblock", 0x8Eu, 0, 5, 0, "fd %d clearing O_NONBLOCK", fd);
    v4 = v2;
    BYTE1(v4) = BYTE1(v2) & 0xF7;
    if ( fcntl(fd, 4, v4, v3) == -1 )
    {
      v8 = __errno_location();
      v9 = strerror(*v8);
      sub_203A0("misc.c", "unset_nonblock", 0x91u, 0, 5, 0, "fcntl(%d, F_SETFL, ~O_NONBLOCK): %s", fd, v9);
    }
    return 0.0;
  }
  sub_203A0("misc.c", "unset_nonblock", 0x8Bu, 0, 7, 0, "fd %d is not O_NONBLOCK", fd);
  return 0.0;
}


// Function: set_nodelay @ 0x23790
double set_nodelay(int fd)
{
  int *v2; // rax
  char *v3; // rax
  int *v4; // rax
  char *v5; // rax
  int v6; // [rsp+0h] [rbp-38h] BYREF
  socklen_t optlen; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v8; // [rsp+8h] [rbp-30h]

  v8 = __readfsqword(0x28u);
  optlen = 4;
  if ( getsockopt(fd, 6, 1, &v6, &optlen) == -1 )
  {
    v4 = __errno_location();
    v5 = strerror(*v4);
    sub_203A0("misc.c", "set_nodelay", 0xA9u, 0, 5, 0, "getsockopt TCP_NODELAY: %.100s", v5);
  }
  else if ( v6 == 1 )
  {
    sub_203A0("misc.c", "set_nodelay", 0xADu, 0, 6, 0, "fd %d is TCP_NODELAY", fd);
  }
  else
  {
    v6 = 1;
    sub_203A0("misc.c", "set_nodelay", 0xB1u, 0, 6, 0, "fd %d setting TCP_NODELAY", fd);
    if ( setsockopt(fd, 6, 1, &v6, 4u) == -1 )
    {
      v2 = __errno_location();
      v3 = strerror(*v2);
      sub_203A0("misc.c", "set_nodelay", 0xB3u, 0, 2, 0, "setsockopt TCP_NODELAY: %.100s", v3);
    }
  }
  return 0.0;
}


// Function: set_reuseaddr @ 0x239b0
double set_reuseaddr(int a1)
{
  int *v2; // rax
  char *v3; // rax
  int optval; // [rsp+4h] [rbp-24h] BYREF
  unsigned long long v5; // [rsp+8h] [rbp-20h]

  v5 = __readfsqword(0x28u);
  optval = 1;
  if ( setsockopt(a1, 1, 2, &optval, 4u) == -1 )
  {
    v2 = __errno_location();
    v3 = strerror(*v2);
    sub_203A0("misc.c", "set_reuseaddr", 0xBDu, 0, 2, 0, "setsockopt SO_REUSEADDR fd %d: %s", a1, v3);
  }
  return 0.0;
}


// Function: get_sock_af @ 0x23b10
double get_sock_af(int fd)
{
  socklen_t len; // [rsp+Ch] [rbp-9Ch] BYREF
  struct sockaddr addr[8]; // [rsp+10h] [rbp-98h] BYREF
  unsigned long long v4; // [rsp+98h] [rbp-10h]

  v4 = __readfsqword(0x28u);
  len = 128;
  memset(addr, 0, sizeof(addr));
  if ( getsockname(fd, addr, &len) != -1 && addr[0].sa_family == 10 && !*(long long *)&addr[0].sa_data[6] )
    sub_22FF0();
  return 0.0;
}


// Function: set_sock_tos @ 0x23c40
double set_sock_tos(unsigned int fd, int a2)
{
  int v2; // eax
  double v4; // xmm0_8
  int *v5; // rax
  char *v6; // rax
  double v7; // xmm0_8
  int *v8; // rax
  char *v9; // rax
  int optval[7]; // [rsp+Ch] [rbp-1Ch] BYREF

  optval[0] = a2;
  sub_23B10(fd);
  if ( v2 != 2 )
  {
    if ( v2 != 10 )
    {
      if ( v2 != -1 )
        sub_203A0("misc.c", "set_sock_tos", 0x129u, 1u, 6, 0, "unsupported socket family %d", v2);
      return 0.0;
    }
    v7 = sub_203A0("misc.c", "set_sock_tos", 0x120u, 1u, 7, 0, "set socket %d IPV6_TCLASS 0x%02x", fd, optval[0]);
    if ( setsockopt(fd, 41, 67, optval, 4u) == -1 )
    {
      v8 = __errno_location();
      v9 = strerror(*v8);
      sub_203A0(
        "misc.c",
        "set_sock_tos",
        0x123u,
        0,
        2,
        0,
        "setsockopt socket %d IPV6_TCLASS %d: %.100s:",
        v7,
        fd,
        optval[0],
        v9);
      return 0.0;
    }
    return 0.0;
  }
  v4 = sub_203A0("misc.c", "set_sock_tos", 0x116u, 1u, 7, 0, "set socket %d IP_TOS 0x%02x", fd, optval[0]);
  if ( setsockopt(fd, 0, 1, optval, 4u) != -1 )
    return 0.0;
  v5 = __errno_location();
  v6 = strerror(*v5);
  sub_203A0("misc.c", "set_sock_tos", 0x119u, 0, 2, 0, "setsockopt socket %d IP_TOS %d: %s:", v4, fd, optval[0], v6);
  return 0.0;
}


// Function: pwcopy @ 0x23f20
double pwcopy(long long a1, long long a2, long long a3)
{
  void **v4; // rax
  void **v5; // r12
  const char *v6; // rdi

  sub_21540(1u, 0x30u, a3);
  v5 = v4;
  *v4 = sub_21840(*(const char **)a1);
  v6 = *(const char **)(a1 + 8);
  if ( !v6 )
    v6 = "*";
  v5[1] = sub_21840(v6);
  v5[3] = sub_21840(*(const char **)(a1 + 24));
  *((int *)v5 + 4) = *(int *)(a1 + 16);
  *((int *)v5 + 5) = *(int *)(a1 + 20);
  v5[4] = sub_21840(*(const char **)(a1 + 32));
  v5[5] = sub_21840(*(const char **)(a1 + 40));
  return 0.0;
}


// Function: a2port @ 0x24030
double a2port(char *name)
{
  struct servent *v1; // rax
  long long v3; // [rsp+0h] [rbp-18h]

  sub_3BFE0(name);
  if ( v3 )
  {
    v1 = getservbyname(name, "tcp");
    if ( v1 )
      sub_22580(LOWORD(v1->s_port));
  }
  return 0.0;
}


// Function: a2tun @ 0x24130
double a2tun(char *a1, int *a2)
{
  char *v2; // r13
  char *v3; // rax

  if ( a2 )
  {
    *a2 = 0x7FFFFFFF;
    v2 = (char *)sub_21840(a1);
    v3 = strchr(v2, 58);
    if ( v3 )
    {
      *v3 = 0;
      *a2 = a2tun(v3 + 1, 0);
      a2tun(v2, 0);
      free(v2);
    }
    else
    {
      free(v2);
      a2tun(a1, 0);
    }
  }
  else if ( strcasecmp(a1, "any") )
  {
    sub_3BFE0(a1);
  }
  return 0.0;
}


// Function: convtime @ 0x242d0
double convtime(char *nptr, double a2)
{
  const char *v2; // r15
  int *v3; // rax
  int *v4; // rbx
  long long v5; // r12
  long long v6; // rbp
  char *v7; // rax
  long long v9; // rax
  long long v10; // rdi
  long long v11; // rbp
  long long v12; // rax
  char *v13[9]; // [rsp+0h] [rbp-48h] BYREF

  v2 = nptr;
  v13[1] = (char *)__readfsqword(0x28u);
  v3 = __errno_location();
  *v3 = 0;
  if ( nptr && *nptr )
  {
    v4 = v3;
    v5 = 0;
    while ( 1 )
    {
      v6 = strtol(v2, v13, 10);
      v7 = v13[0];
      if ( v13[0] == v2 || *v4 == 34 && (v6 == 0xFFFFFFFF80000000LL || v6 == 0x7FFFFFFF) )
        break;
      if ( v6 < 0 )
        break;
      ++v13[0];
      if ( *v7 )
      {
        if ( (unsigned char)(*v7 - 68) <= 0x33u )
        {
          switch ( (unsigned char)sub_3DA20((unsigned int)*v7, 4294967228LL) )
          {
            case 0u:
            case 0x20u:
              v9 = 24855;
              v10 = 86400;
              goto LABEL_14;
            case 4u:
            case 0x24u:
              v9 = 596523;
              v10 = 3600;
              goto LABEL_14;
            case 9u:
            case 0x29u:
              v9 = 35791394;
              v10 = 60;
              goto LABEL_14;
            case 0xFu:
            case 0x2Fu:
              v9 = 0x7FFFFFFF;
              v10 = 1;
              goto LABEL_14;
            case 0x13u:
            case 0x33u:
              v9 = 3550;
              v10 = 604800;
              goto LABEL_14;
            default:
              return 0.0;
          }
        }
        return 0.0;
      }
      v13[0] = v7;
      v10 = 1;
      v9 = 0x7FFFFFFF;
LABEL_14:
      if ( v6 <= v9 )
      {
        v11 = sub_3DA80(v10, v6);
        if ( sub_3DA40(0x7FFFFFFF, v11, a2) >= v5 )
        {
          v12 = sub_3DA00(v5, v11);
          v2 = v13[0];
          v5 = v12;
          if ( *v13[0] )
            continue;
        }
      }
      return 0.0;
    }
  }
  return 0.0;
}


// Function: fmt_timeframe @ 0x24500
double fmt_timeframe(unsigned long long a1)
{
  long long v2; // r12
  int v3; // eax
  char *v4; // r12
  unsigned long long v5; // r8
  unsigned long long v6; // rdi
  long long v7; // rdx
  unsigned long long v8; // rcx

  v2 = 9LL * dword_68208;
  v3 = sub_3DA20((unsigned int)dword_68208, 1);
  v4 = (char *)&unk_681C0 + v2;
  if ( v3 == 8 )
    v3 = 0;
  dword_68208 = v3;
  v5 = a1 / 0x3C;
  v6 = a1 / 0x3C / 0x3C;
  v7 = (0x2492492492492493LL * (unsigned __int128)(v6 / 0x18)) >> 64;
  v8 = v6 / 0x18 - 7 * ((v7 + ((v6 / 0x18 - v7) >> 1)) >> 2);
  if ( a1 > 0x93A7F )
  {
    __snprintf_chk(
      v4,
      9,
      1,
      -1,
      "%02lluw%01ud%02uh",
      (long long)((unsigned __int128)(0x4924924924924925LL * (__int128)(v6 / 0x18)) >> 64) >> 1,
      v8,
      v6 % 0x18);
    return 0.0;
  }
  else
  {
    if ( v8 )
      __snprintf_chk(v4, 9, 1, -1, "%01ud%02uh%02um", (unsigned int)v8, v6 % 0x18, v5 - 60 * v6);
    else
      __snprintf_chk(v4, 9, 1, -1, "%02u:%02u:%02u", v6 % 0x18, v5 - 60 * v6, a1 % 0x3C);
    return 0.0;
  }
}


// Function: put_host_port @ 0x24790
const char *put_host_port(const char *src, unsigned short a2)
{
  int *v3; // rax
  char *v4; // rax
  const char *v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[1] = (const char *)__readfsqword(0x28u);
  if ( !a2 || a2 == 22 )
    return (const char *)sub_21840(src);
  if ( (unsigned int)__asprintf_chk(v5, 1, "[%s]:%d", src, a2) == -1 )
  {
    v3 = __errno_location();
    v4 = strerror(*v3);
    sub_1EE30("misc.c", (long long)"put_host_port", 672, 0, 1, 0, (long long)"put_host_port: asprintf: %s", v4);
  }
  sub_203A0("misc.c", "put_host_port", 0x2A1u, 0, 7, 0, "put_host_port: %s", v5[0]);
  return v5[0];
}


// Function: hpdelim2 @ 0x24910
double hpdelim2(const char **a1, char *a2)
{
  const char *v2; // r12
  char *v3; // rax
  char v4; // dl
  char *v6; // rax

  if ( !a1 )
    return 0.0;
  v2 = *a1;
  if ( !*a1 )
    return 0.0;
  if ( *v2 == 91 )
  {
    v6 = strchr(*a1, 93);
    if ( !v6 )
      return 0.0;
    v4 = v6[1];
    v3 = v6 + 1;
    if ( v4 == 47 )
      goto LABEL_13;
  }
  else
  {
    v3 = strpbrk(*a1, ":/");
    if ( !v3 )
      v3 = (char *)&v2[strlen(v2)];
    v4 = *v3;
    if ( *v3 == 47 )
      goto LABEL_13;
  }
  if ( v4 == 58 )
  {
LABEL_13:
    if ( a2 )
      *a2 = v4;
    *v3 = 0;
    *a1 = v3 + 1;
    return 0.0;
  }
  if ( v4 )
    return 0.0;
  *a1 = 0;
  return 0.0;
}


// Function: hpdelim @ 0x24b60
double hpdelim(const char **a1)
{
  char v2; // [rsp+7h] [rbp-11h] BYREF
  unsigned long long v3; // [rsp+8h] [rbp-10h]

  v3 = __readfsqword(0x28u);
  v2 = 0;
  sub_24910(a1, &v2);
  return 0.0;
}


// Function: cleanhostname @ 0x24c30
double cleanhostname(const char *a1)
{
  const char *v1; // rax

  if ( *a1 != 91 )
    return 0.0;
  v1 = &a1[strlen(a1) - 1];
  if ( *v1 != 93 )
    return 0.0;
  *v1 = 0;
  return 0.0;
}


// Function: colon @ 0x24d70
double colon(char *a1)
{
  char v1; // al
  int v2; // edx

  v1 = *a1;
  if ( *a1 == 58 )
    return 0.0;
  v2 = v1 == 91;
  if ( !v1 )
    return 0.0;
  while ( 1 )
  {
    while ( v1 == 64 )
    {
      if ( a1[1] != 91 )
        goto LABEL_6;
      v1 = a1[2];
      v2 = 1;
      a1 += 2;
      if ( !v1 )
        return 0.0;
    }
    if ( v1 != 93 )
      break;
    if ( a1[1] == 58 && v2 )
      return 0.0;
LABEL_6:
    v1 = *++a1;
    if ( !v1 )
      return 0.0;
  }
  if ( v1 == 58 )
  {
    if ( !v2 )
      return 0.0;
    goto LABEL_6;
  }
  if ( v1 != 47 )
    goto LABEL_6;
  return 0.0;
}


// Function: parse_user_host_path @ 0x25000
double parse_user_host_path(const char *a1, char **a2, long long *a3, long long *a4)
{
  char *v6; // r12
  const char *v7; // rax
  char *v8; // rbp
  bool v9; // zf
  const char *v10; // rdi
  void *v11; // r15
  char *v12; // rax
  const char *v13; // rax
  void *v14; // rax
  void *v15; // r8
  char *v17; // rax
  const char *v18; // rax
  void *ptra; // [rsp+8h] [rbp-40h]
  void *ptr; // [rsp+8h] [rbp-40h]

  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  if ( a4 )
    *a4 = 0;
  v6 = (char *)sub_21840(a1);
  sub_24D70(v6);
  v8 = (char *)v7;
  if ( v7 )
  {
    v9 = v7[1] == 0;
    *v7 = 0;
    v10 = ".";
    if ( !v9 )
      v10 = v7 + 1;
    v11 = sub_21840(v10);
    v12 = strrchr(v6, 64);
    v8 = v12;
    if ( v12 )
    {
      *v12 = 0;
      v8 = 0;
      sub_24C30(v12 + 1);
      v14 = sub_21840(v13);
      v15 = v14;
      if ( *v6 )
      {
        ptr = v14;
        v17 = (char *)sub_21840(v6);
        v15 = ptr;
        v8 = v17;
      }
    }
    else
    {
      sub_24C30(v6);
      v15 = sub_21840(v18);
    }
    if ( a2 )
    {
      *a2 = v8;
      v8 = 0;
    }
    if ( a3 )
    {
      *a3 = v15;
      v15 = 0;
    }
    if ( a4 )
    {
      *a4 = v11;
      v11 = 0;
    }
  }
  else
  {
    v11 = 0;
    v15 = 0;
  }
  ptra = v15;
  free(v6);
  free(v8);
  free(ptra);
  free(v11);
  return 0.0;
}


// Function: parse_user_host_port @ 0x251f0
double parse_user_host_port(const char *a1, char **a2, char **a3, int *a4)
{
  char *v6; // rax
  char *v7; // rbp
  char *v8; // rax
  char *v9; // rbx
  char *v10; // rbx
  char *v11; // r15
  const char *v13; // rax
  const char *v14; // rax
  char *v15; // rax
  int v16; // edx
  int v17; // eax
  char *s[9]; // [rsp+10h] [rbp-48h] BYREF

  s[1] = (char *)__readfsqword(0x28u);
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  if ( a4 )
    *a4 = -1;
  v6 = strdup(a1);
  s[0] = v6;
  v7 = v6;
  if ( v6 )
  {
    v8 = strrchr(v6, 64);
    v9 = v8;
    if ( v8 )
    {
      *v8 = 0;
      if ( !*s[0] || (v11 = strdup(s[0])) == 0 )
      {
        v10 = 0;
        v11 = 0;
LABEL_11:
        free(v7);
        free(v11);
        free(v10);
        return 0.0;
      }
      s[0] = v9 + 1;
    }
    else
    {
      v11 = 0;
    }
    sub_24B60((const char **)s);
    v10 = (char *)v13;
    if ( v13 )
    {
      if ( *v13 )
      {
        sub_24C30(v13);
        v15 = (char *)sub_21840(v14);
        v16 = -1;
        v10 = v15;
        if ( !s[0] || !*s[0] || (sub_24030(s[0]), v16 = v17, v17 > 0) )
        {
          if ( a2 )
          {
            *a2 = v11;
            v11 = 0;
          }
          if ( a3 )
          {
            *a3 = v10;
            v10 = 0;
          }
          if ( a4 )
            *a4 = v16;
        }
      }
      else
      {
        v10 = 0;
      }
    }
    goto LABEL_11;
  }
  return 0.0;
}


// Function: addargs @ 0x25430
double addargs(long long a1, long long a2, ...)
{
  long long v3; // rdx
  long long v4; // rcx
  void *v5; // rdi
  unsigned int v6; // ebp
  unsigned int v7; // eax
  long long v8; // rsi
  long long v9; // rdx
  long long v10; // rdx
  long long v11; // rax
  long long v13; // [rsp+8h] [rbp-F0h] BYREF
  gcc_va_list va; // [rsp+10h] [rbp-E8h] BYREF
  unsigned long long v15; // [rsp+28h] [rbp-D0h]
  long long v16; // [rsp+40h] [rbp-B8h]
  long long v17; // [rsp+48h] [rbp-B0h]

  va_start(va, a2);
  v16 = va_arg(va, long long);
  v17 = va_arg(va, long long);
  va_end(va);
  va_start(va, a2);
  v15 = __readfsqword(0x28u);
  if ( (unsigned int)__vasprintf_chk(&v13, 1, a2, va) == -1 )
    sub_1EE30("misc.c", (long long)"addargs", 1072, 1, 1, 0, (long long)"argument too long", v4);
  v5 = *(void **)a1;
  v6 = *(int *)(a1 + 12);
  if ( *(long long *)a1 )
  {
    v7 = *(int *)(a1 + 8);
    if ( v7 > 0x40000 )
      sub_1EE30("misc.c", (long long)"addargs", 1079, 1, 1, 0, (long long)"too many arguments", v3);
    if ( v7 >= v6 )
      sub_1EE30("misc.c", (long long)"addargs", 1081, 1, 1, 0, (long long)"arglist corrupt", *(unsigned int *)(a1 + 8));
    v8 = v6;
    v9 = v6;
    if ( v7 + 2 >= v6 )
    {
      v9 = 2 * v6;
      v6 *= 2;
    }
  }
  else
  {
    v8 = v6;
    *(int *)(a1 + 8) = 0;
    v9 = 32;
    v6 = 32;
  }
  sub_21760(v5, v8, v9, 8);
  v10 = *(unsigned int *)(a1 + 8);
  *(int *)(a1 + 12) = v6;
  *(long long *)a1 = v11;
  *(int *)(a1 + 8) = v10 + 1;
  *(long long *)(v11 + 8 * v10) = v13;
  *(long long *)(*(long long *)a1 + 8LL * *(unsigned int *)(a1 + 8)) = 0;
  return 0.0;
}


// Function: replacearg @ 0x256b0
double replacearg(long long a1, unsigned int a2, long long a3, ...)
{
  long long v3; // rcx
  unsigned int v4; // eax
  long long v6; // [rsp+8h] [rbp-F0h] BYREF
  gcc_va_list va; // [rsp+10h] [rbp-E8h] BYREF
  unsigned long long v8; // [rsp+28h] [rbp-D0h]
  long long v9; // [rsp+48h] [rbp-B0h]

  va_start(va, a3);
  v9 = va_arg(va, long long);
  va_end(va);
  va_start(va, a3);
  v8 = __readfsqword(0x28u);
  if ( (unsigned int)__vasprintf_chk(&v6, 1, a3, va) == -1 )
    sub_1EE30("misc.c", (long long)"replacearg", 1103, 1, 1, 0, (long long)"argument too long", 1);
  if ( !*(long long *)a1 || (v4 = *(int *)(a1 + 8), v4 >= *(int *)(a1 + 12)) )
    sub_1EE30("misc.c", (long long)"replacearg", 1105, 1, 1, 0, (long long)"arglist corrupt", v3);
  if ( v4 <= a2 )
    sub_1EE30("misc.c", (long long)"replacearg", 1108, 1, 1, 0, (long long)"tried to replace invalid arg %d >= %d", a2, v4);
  free(*(void **)(*(long long *)a1 + 8LL * a2));
  *(long long *)(*(long long *)a1 + 8LL * a2) = v6;
  return 0.0;
}


// Function: tilde_expand @ 0x25a30
double tilde_expand(const char *a1, __uid_t a2, void **a3)
{
  bool v4; // zf
  char *v6; // r13
  char *v7; // rax
  const char *v8; // rbp
  struct passwd *v9; // rax
  const char *pw_dir; // r12
  size_t v11; // rax
  const char *v12; // rcx
  int v13; // eax
  void *v14; // rax
  void *v15; // rdi
  unsigned int v16; // edx
  const char *v17; // [rsp-10h] [rbp-48h]
  long long v18[7]; // [rsp+0h] [rbp-38h] BYREF

  v18[1] = __readfsqword(0x28u);
  *a3 = 0;
  v4 = *a1 == 126;
  v18[0] = 0;
  if ( v4 )
  {
    v6 = (char *)sub_21840(a1 + 1);
    if ( *v6 )
    {
      if ( *v6 != 47 )
      {
        v7 = strchr(v6, 47);
        if ( !v7 || (*v7 = 0, v8 = &v7[strspn(v7 + 1, "/") + 1], !*v8) )
          v8 = 0;
        v9 = getpwnam(v6);
        if ( !v9 )
        {
          v16 = 1172;
          v17 = "No such user %s";
          goto LABEL_28;
        }
        goto LABEL_9;
      }
      v8 = &v6[strspn(v6, "/")];
      if ( !*v8 )
        v8 = 0;
    }
    else
    {
      v8 = 0;
    }
    v9 = getpwuid(a2);
    if ( !v9 )
    {
      v16 = 1176;
      v17 = "No such uid %ld";
      goto LABEL_28;
    }
LABEL_9:
    pw_dir = v9->pw_dir;
    v11 = strlen(pw_dir);
    if ( v11 )
    {
      v12 = "";
      if ( !v8 )
        v8 = "";
      if ( pw_dir[v11 - 1] == 47 )
      {
LABEL_13:
        sub_21960(v18, (long long)"%s%s%s", pw_dir, v12, v8);
        if ( v13 <= 0 )
        {
          v17 = "xasprintf failed";
          v16 = 1185;
        }
        else
        {
          if ( v13 <= 4095 )
          {
            v14 = (void *)v18[0];
            v18[0] = 0;
            v15 = 0;
            *a3 = v14;
LABEL_16:
            free(v15);
            free(v6);
            return 0.0;
          }
          v17 = "Path too long";
          v16 = 1189;
        }
LABEL_28:
        sub_203A0("misc.c", "tilde_expand", v16, 1u, 2, 0, v17);
        v15 = (void *)v18[0];
        goto LABEL_16;
      }
    }
    else
    {
      v12 = "/";
      if ( v8 )
        goto LABEL_13;
      v8 = "";
    }
    v12 = "/";
    goto LABEL_13;
  }
  *a3 = sub_21840(a1);
  return 0.0;
}


// Function: tilde_expand_filename @ 0x25d30
double tilde_expand_filename(const char *a1, __uid_t a2)
{
  int v2; // eax
  void *v4[3]; // [rsp+0h] [rbp-18h] BYREF

  v4[1] = (void *)__readfsqword(0x28u);
  sub_25A30(a1, a2, v4);
  if ( v2 )
    sub_31220(255);
  return 0.0;
}


// Function: dollar_expand @ 0x25e00
double dollar_expand(int *a1, char *a2, ...)
{
  int v3; // [rsp+Ch] [rbp-DCh] BYREF
  gcc_va_list va; // [rsp+10h] [rbp-D8h] BYREF
  unsigned long long v5; // [rsp+28h] [rbp-C0h]

  va_start(va, a2);
  v5 = __readfsqword(0x28u);
  sub_227D0(&v3, 1, 0, a2, (int *)va);
  if ( a1 )
    *a1 = v3;
  return 0.0;
}


// Function: percent_expand @ 0x25f60
double percent_expand(char *a1, ...)
{
  long long v1; // rax
  double v2; // xmm0_8
  int v4; // [rsp+Ch] [rbp-DCh] BYREF
  gcc_va_list va; // [rsp+10h] [rbp-D8h] BYREF
  unsigned long long v6; // [rsp+28h] [rbp-C0h]

  va_start(va, a1);
  v6 = __readfsqword(0x28u);
  v2 = sub_227D0(&v4, 0, 1, a1, (int *)va);
  if ( v4 )
    sub_1EE30("misc.c", (long long)"percent_expand", 1365, 1, 1, 0, (long long)"failed", v2, v1);
  return 0.0;
}


// Function: percent_dollar_expand @ 0x260f0
double percent_dollar_expand(char *a1, ...)
{
  long long v1; // rax
  double v2; // xmm0_8
  int v4; // [rsp+Ch] [rbp-DCh] BYREF
  gcc_va_list va; // [rsp+10h] [rbp-D8h] BYREF
  unsigned long long v6; // [rsp+28h] [rbp-C0h]

  va_start(va, a1);
  v6 = __readfsqword(0x28u);
  v2 = sub_227D0(&v4, 1, 1, a1, (int *)va);
  if ( v4 )
    sub_1EE30("misc.c", (long long)"percent_dollar_expand", 1384, 1, 1, 0, (long long)"failed", v2, v1);
  return 0.0;
}


// Function: sanitise_stdfd @ 0x262a0
int sanitise_stdfd()
{
  unsigned int v0; // eax
  int v1; // r12d
  int v2; // ebp
  int *v3; // rbx
  char *v4; // rax
  int *v6; // rax
  char *v7; // rax

  v0 = open("/dev/null", 2);
  if ( v0 == -1 )
  {
    v6 = __errno_location();
    v7 = strerror(*v6);
    __fprintf_chk(stderr, 1, "Couldn't open /dev/null: %s\n", v7);
    goto LABEL_9;
  }
  v1 = v0;
  v2 = sub_3DA20(v0, 1);
  if ( v2 <= 2 )
  {
    while ( 1 )
    {
      if ( fcntl(v2, 3) == -1 )
      {
        v3 = __errno_location();
        if ( *v3 == 9 && dup2(v1, v2) == -1 )
          break;
      }
      v2 = sub_3DA20((unsigned int)v2, 1);
      if ( v2 == 3 )
        goto LABEL_10;
    }
    v4 = strerror(*v3);
    __fprintf_chk(stderr, 1, "dup2: %s\n", v4);
LABEL_9:
    exit(1);
  }
LABEL_10:
  if ( v1 > 2 )
    return close(v1);
  else
    return 0;
}


// Function: tohex @ 0x26410
void *tohex(unsigned char *a1, unsigned long long a2, long long a3)
{
  unsigned char *v3; // rbx
  long long v4; // rax
  long long v5; // r12
  int v6; // r9d
  char v8[3]; // [rsp+5h] [rbp-43h] BYREF
  unsigned long long v9; // [rsp+8h] [rbp-40h]

  v9 = __readfsqword(0x28u);
  if ( a2 > (unsigned long long)&loc_10000 )
    return sub_21840("tohex: length > 65536");
  v3 = a1;
  sub_21540(1u, 2 * a2 + 1, a3);
  v5 = v4;
  if ( a2 )
  {
    do
    {
      v6 = *v3++;
      __snprintf_chk(v8, 3, 1, 3, "%02x", v6);
      sub_3BCF0(v5, v8, 2 * a2 + 1);
    }
    while ( v3 != &a1[a2] );
  }
  return (void *)v5;
}


// Function: xextendf @ 0x26580
double xextendf(void **a1, const char *a2, long long a3, ...)
{
  const char *v3; // r12
  double v4; // xmm0_8
  char *v5; // rdx
  void *v6; // rax
  void *ptr; // [rsp+0h] [rbp-F8h] BYREF
  void *v9; // [rsp+8h] [rbp-F0h] BYREF
  gcc_va_list va; // [rsp+10h] [rbp-E8h] BYREF
  unsigned long long v11; // [rsp+28h] [rbp-D0h]

  va_start(va, a3);
  v3 = a2;
  v11 = __readfsqword(0x28u);
  v4 = sub_21880(&ptr, a3, (long long)va);
  v5 = *a1;
  if ( *a1 && *v5 )
  {
    if ( !a2 )
      v3 = "";
    sub_21960(&v9, (long long)"%s%s%s", v5, v3, ptr, v4);
    free(ptr);
    free(*a1);
    v6 = v9;
  }
  else
  {
    free(*a1);
    v6 = ptr;
  }
  *a1 = v6;
  return 0.0;
}


// Function: get_u32 @ 0x267d0
double get_u32()
{
  return 0.0;
}


// Function: put_u32 @ 0x26a10
double put_u32(int *a1, unsigned int a2)
{
  *a1 = _byteswap_ulong(a2);
  return 0.0;
}


// Function: monotime_ts @ 0x26c80
double monotime_ts(struct timespec *tp)
{
  int *v3; // rax
  char *v4; // rax
  __suseconds_t tv_usec; // rdi
  struct timeval v6; // [rsp+0h] [rbp-28h] BYREF
  unsigned long long v7; // [rsp+18h] [rbp-10h]

  v7 = __readfsqword(0x28u);
  if ( dword_681A8 )
    goto LABEL_7;
  if ( clock_gettime(7, tp) && clock_gettime(1, tp) && clock_gettime(0, tp) )
  {
    v3 = __errno_location();
    v4 = strerror(*v3);
    sub_203A0("misc.c", "monotime_ts", 0x690u, 0, 7, 0, "clock_gettime: %s", v4);
    dword_681A8 = 1;
LABEL_7:
    gettimeofday(&v6, 0);
    tv_usec = v6.tv_usec;
    tp->tv_sec = v6.tv_sec;
    tp->tv_nsec = sub_3DA80(tv_usec, 1000);
  }
  return 0.0;
}


// Function: monotime_tv @ 0x26e00
double monotime_tv(__time_t *a1)
{
  __syscall_slong_t tv_nsec; // rcx
  struct timespec v3; // [rsp+0h] [rbp-28h] BYREF
  unsigned long long v4; // [rsp+18h] [rbp-10h]

  v4 = __readfsqword(0x28u);
  sub_26C80(&v3);
  tv_nsec = v3.tv_nsec;
  *a1 = v3.tv_sec;
  a1[1] = tv_nsec / 1000;
  return 0.0;
}


// Function: ms_subtract_diff @ 0x26ef0
double ms_subtract_diff(long long *a1, int *a2)
{
  double v2; // xmm0_8
  long long v3; // rbp
  long long v4; // r12
  __time_t v6[7]; // [rsp+0h] [rbp-38h] BYREF

  v6[3] = __readfsqword(0x28u);
  v2 = sub_26E00(v6);
  v3 = sub_3DA40(v6[0], *a1, v2);
  v4 = sub_3DA40(v6[1], a1[1], v2);
  if ( v4 < 0 )
  {
    LODWORD(v3) = sub_3DA00(v3, -1);
    v4 = sub_3DA00(v4, 1000000);
  }
  *a2 -= v4 / 1000 + 1000 * v3;
  return 0.0;
}


// Function: waitfd @ 0x27030
double waitfd(int a1, int *a2, short a3)
{
  int *v3; // r13
  int v4; // eax
  int v5; // ebp
  int v6; // ebx
  struct pollfd fds; // [rsp+8h] [rbp-50h] BYREF
  __time_t v9[9]; // [rsp+10h] [rbp-48h] BYREF

  v9[3] = __readfsqword(0x28u);
  fds.fd = a1;
  fds.events = a3;
  v3 = __errno_location();
  do
  {
    if ( *a2 < 0 )
      break;
    sub_26E00(v9);
    v4 = poll(&fds, 1u, *a2);
    v5 = *v3;
    v6 = v4;
    sub_26EF0(v9, a2);
    *v3 = v5;
    if ( v6 > 0 || v5 != 4 && v5 != 11 && v6 == -1 )
      return 0.0;
  }
  while ( v6 );
  *v3 = 110;
  return 0.0;
}


// Function: timeout_connect @ 0x271b0
double timeout_connect(int fd, struct sockaddr *addr, socklen_t len, int *a4)
{
  int *v6; // rbx
  int v7; // eax
  char *v9; // rax
  int v10; // [rsp+0h] [rbp-38h] BYREF
  socklen_t optlen; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v12; // [rsp+8h] [rbp-30h]

  v12 = __readfsqword(0x28u);
  v10 = 0;
  optlen = 4;
  if ( a4 && *a4 > 0 )
  {
    sub_23290(fd);
    do
    {
      if ( !connect(fd, addr, len) )
        goto LABEL_10;
      v6 = __errno_location();
    }
    while ( *v6 == 4 );
    if ( *v6 == 115 )
    {
      sub_27030(fd, a4, 5);
      if ( v7 != -1 )
      {
        if ( getsockopt(fd, 1, 4, &v10, &optlen) == -1 )
        {
          v9 = strerror(*v6);
          sub_203A0("misc.c", "timeout_connect", 0x17Du, 0, 5, 0, "getsockopt: %s", v9);
        }
        else
        {
          if ( !v10 )
          {
LABEL_10:
            sub_234F0(fd);
            return 0.0;
          }
          *v6 = v10;
        }
      }
    }
  }
  else
  {
    connect(fd, addr, len);
  }
  return 0.0;
}


// Function: monotime @ 0x27390
double monotime()
{
  struct timespec v1; // [rsp+0h] [rbp-28h] BYREF
  unsigned long long v2; // [rsp+18h] [rbp-10h]

  v2 = __readfsqword(0x28u);
  sub_26C80(&v1);
  return 0.0;
}


// Function: monotime_double @ 0x27450
long long monotime_double()
{
  struct timespec v1; // [rsp+0h] [rbp-28h] BYREF
  unsigned long long v2; // [rsp+18h] [rbp-10h]

  v2 = __readfsqword(0x28u);
  sub_26C80(&v1);
  return 0;
}


// Function: bandwidth_limit @ 0x275f0
double bandwidth_limit(long long *a1, long long a2)
{
  unsigned long long v3; // rsi
  bool v4; // zf
  double v6; // xmm0_8
  long long v7; // rax
  long long v8; // rdi
  long long v9; // rsi
  signed long long v10; // rbp
  long long v11; // rax
  long long v12; // r12
  long long v13; // rax
  long long v14; // rax
  double v15; // xmm0_8
  long long v16; // rax
  double v17; // xmm0_8
  double v18; // xmm1_8
  double v19; // xmm0_8
  unsigned long long v20; // rcx
  signed long long v21; // rdx
  signed long long v22; // rcx
  signed long long v23; // r12
  long long v24; // r14
  long long v25; // rax
  __time_t v26; // r13
  long long v27; // rax
  long long v28; // rbp
  unsigned long long v29; // rax
  long long v30; // rdx
  signed long long v31; // rsi
  long long v32; // rax
  unsigned long long v33; // rax
  long long v34; // rax
  long long v35; // rax
  __m128i si128; // [rsp+0h] [rbp-58h] BYREF
  struct timespec remaining; // [rsp+10h] [rbp-48h] BYREF
  unsigned long long v38; // [rsp+28h] [rbp-30h]

  v3 = a1[3] + a2;
  v38 = __readfsqword(0x28u);
  v4 = a1[4] == 0;
  a1[3] = v3;
  if ( !v4 || a1[5] )
  {
    if ( v3 < a1[2] )
      return 0.0;
    v6 = sub_26E00(a1 + 6);
    v7 = sub_3DA40(a1[6], a1[4], v6);
    v8 = a1[7];
    v9 = a1[5];
    a1[6] = v7;
    v10 = v7;
    v11 = sub_3DA40(v8, v9, v6);
    a1[7] = v11;
    v12 = v11;
    if ( v11 < 0 )
    {
      v13 = sub_3DA00(v10, -1);
      a1[6] = v13;
      v10 = v13;
      a1[7] = sub_3DA00(v12, 1000000);
    }
    if ( !v10 && !a1[7] )
      return 0.0;
    v14 = 8LL * a1[3];
    a1[3] = v14;
    if ( v14 < 0 )
      v15 = (double)(int)((unsigned long long)v14 >> 1) + (double)(int)((unsigned long long)v14 >> 1);
    else
      v15 = (double)(int)v14;
    v16 = a1[1];
    v17 = v15 * 1000000.0;
    if ( v16 < 0 )
    {
      v30 = a1[1] & 1LL | (a1[1] >> 1);
      v18 = (double)(int)v30 + (double)(int)v30;
    }
    else
    {
      v18 = (double)(int)v16;
    }
    v19 = v17 / v18;
    if ( v19 >= 9.223372036854776e18 )
    {
      v19 = v19 - 9.223372036854776e18;
      v20 = (unsigned int)(int)v19 ^ 0x8000000000000000LL;
    }
    else
    {
      v20 = (unsigned int)(int)v19;
    }
    v21 = v20 / 0xF4240;
    a1[4] = v20 / 0xF4240;
    v22 = v20 % 0xF4240;
    a1[5] = v22;
    v23 = v22;
    if ( v21 == v10 )
    {
      v31 = a1[7];
      if ( v22 > v31 )
      {
        a1[6] = 0;
        v32 = sub_3DA40(v22, v31, v19);
        a1[7] = v32;
        v28 = v32;
        goto LABEL_32;
      }
    }
    else if ( v21 > v10 )
    {
      v24 = a1[7];
      v25 = sub_3DA40(v21, v10, v19);
      a1[6] = v25;
      v26 = v25;
      v27 = sub_3DA40(v23, v24, v19);
      a1[7] = v27;
      v28 = v27;
      if ( v27 >= 0
        || (v34 = sub_3DA00(v26, -1), a1[6] = v34, v26 = v34, v35 = sub_3DA00(v28, 1000000), a1[7] = v35, v28 = v35, v26) )
      {
        v29 = *a1 >> 2;
        if ( v29 < a1[2] >> 1 )
          v29 = a1[2] >> 1;
        a1[2] = v29;
LABEL_21:
        si128.m128i_i64[0] = v26;
        si128.m128i_i64[1] = sub_3DA80(v28, 1000);
        while ( nanosleep((const struct timespec *)&si128, &remaining) == -1 && *__errno_location() == 4 )
          si128 = _mm_load_si128((const __m128i *)&remaining);
        goto LABEL_25;
      }
LABEL_32:
      v26 = 0;
      if ( v28 <= 9999 )
      {
        v33 = 8LL * *a1;
        if ( v33 > 2LL * a1[2] )
          v33 = 2LL * a1[2];
        a1[2] = v33;
      }
      goto LABEL_21;
    }
LABEL_25:
    a1[3] = 0;
    sub_26E00(a1 + 4);
    return 0.0;
  }
  return sub_26E00(a1 + 4);
}


// Function: mktemp_proto @ 0x279a0
double mktemp_proto(char *s, size_t maxlen)
{
  char *v2; // rax
  int v3; // eax
  long long v4; // rax

  v2 = getenv("TMPDIR");
  if ( !v2 || (v3 = __snprintf_chk(s, maxlen, 1, -1, "%s/ssh-XXXXXXXXXXXX", v2), v3 <= 0) || v3 >= maxlen )
  {
    LODWORD(v4) = snprintf(s, maxlen, "/tmp/ssh-XXXXXXXXXXXX");
    if ( (int)v4 < 0 || (v4 = (int)v4, (int)v4 >= maxlen) )
      sub_1EE30("misc.c", (long long)"mktemp_proto", 1794, 1, 1, 0, (long long)"template string too short", v4);
  }
  return 0.0;
}


// Function: parse_ipqos @ 0x27ad0
double parse_ipqos(char *nptr)
{
  const char **v1; // rbx
  int v2; // ebp
  const char *v3; // rsi
  char *v5[5]; // [rsp+0h] [rbp-28h] BYREF

  v5[1] = (char *)__readfsqword(0x28u);
  if ( nptr )
  {
    v1 = (const char **)&off_671D0;
    v2 = 0;
    v3 = "none";
    while ( strcasecmp(nptr, v3) )
    {
      v3 = *v1;
      v1 += 2;
      ++v2;
      if ( !v3 )
      {
        strtol(nptr, v5, 0);
        return 0.0;
      }
    }
  }
  return 0.0;
}


// Function: lowercase @ 0x27d90
double lowercase(unsigned char *a1)
{
  long long v1; // rbx
  unsigned char *v2; // rbp
  const int_t **v3; // rax

  v1 = *a1;
  if ( (char)v1 )
  {
    v2 = a1;
    v3 = __ctype_tolower_loc();
    do
    {
      *v2++ = (*v3)[v1];
      v1 = *v2;
    }
    while ( (char)v1 );
  }
  return 0.0;
}


// Function: unix_listener @ 0x27e50
double unix_listener(char *name, int n, int a3)
{
  int v5; // r12d
  int v7; // edi
  char *v8; // rax
  int *v9; // rax
  int v10; // r13d
  int *v11; // rbx
  char *v12; // rax
  int *v13; // rax
  int v14; // r13d
  int *v15; // rbx
  char *v16; // rax
  int *v17; // rax
  int v18; // ebp
  int *v19; // rbx
  char *v20; // rax
  char v21[104]; // [rsp+0h] [rbp-A8h] BYREF
  int v22; // [rsp+68h] [rbp-40h]
  short v23; // [rsp+6Ch] [rbp-3Ch]
  unsigned long long v24; // [rsp+78h] [rbp-30h]

  v24 = __readfsqword(0x28u);
  memset(v21, 0, sizeof(v21));
  *(short *)v21 = 1;
  v22 = 0;
  v23 = 0;
  if ( (unsigned long long)sub_3BEE0(&v21[2], name, 108) > 0x6B )
  {
    sub_203A0("misc.c", "unix_listener", 0x759u, 1u, 2, 0, "path \"%s\" too long for Unix domain socket", name);
    *__errno_location() = 36;
  }
  else
  {
    v5 = socket(1, 1, 0);
    if ( v5 == -1 )
    {
      v17 = __errno_location();
      v18 = *v17;
      v19 = v17;
      v20 = strerror(*v17);
      sub_203A0("misc.c", "unix_listener", 0x761u, 1u, 2, 0, "socket: %.100s", v20);
      *v19 = v18;
    }
    else
    {
      if ( a3 == 1 )
      {
        if ( unlink(name) )
        {
          v7 = *__errno_location();
          if ( v7 != 2 )
          {
            v8 = strerror(v7);
            sub_203A0("misc.c", "unix_listener", 0x767u, 0, 2, 0, "unlink(%s): %.100s", name, v8);
          }
        }
      }
      if ( bind(v5, (const struct sockaddr *)v21, 0x6Eu) == -1 )
      {
        v9 = __errno_location();
        v10 = *v9;
        v11 = v9;
        v12 = strerror(*v9);
        sub_203A0("misc.c", "unix_listener", 0x76Bu, 1u, 2, 0, "cannot bind to path %s: %s", name, v12);
        close(v5);
        *v11 = v10;
      }
      else if ( listen(v5, n) == -1 )
      {
        v13 = __errno_location();
        v14 = *v13;
        v15 = v13;
        v16 = strerror(*v13);
        sub_203A0("misc.c", "unix_listener", 0x772u, 1u, 2, 0, "cannot listen on path %s: %s", name, v16);
        close(v5);
        unlink(name);
        *v15 = v14;
      }
    }
  }
  return 0.0;
}


// Function: sock_set_v6only @ 0x28180
double sock_set_v6only(int fd)
{
  int *v2; // rax
  char *v3; // rax
  int v4; // [rsp+0h] [rbp-38h]
  int optval; // [rsp+14h] [rbp-24h] BYREF
  unsigned long long v6; // [rsp+18h] [rbp-20h]

  v6 = __readfsqword(0x28u);
  optval = 1;
  sub_203A0("misc.c", "sock_set_v6only", 0x781u, 0, 7, 0, "%s: set socket %d IPV6_V6ONLY", "sock_set_v6only", v4);
  if ( setsockopt(fd, 41, 26, &optval, 4u) == -1 )
  {
    v2 = __errno_location();
    v3 = strerror(*v2);
    sub_203A0("misc.c", "sock_set_v6only", 0x783u, 0, 2, 0, "setsockopt IPV6_V6ONLY: %s", v3);
  }
  return 0.0;
}


// Function: forward_equals @ 0x282f0
double forward_equals(long long a1, long long a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  sub_22EC0(*(const char **)a1, *(const char **)a2);
  if ( v2 )
  {
    if ( *(int *)(a1 + 8) == *(int *)(a2 + 8) )
    {
      sub_22EC0(*(const char **)(a1 + 16), *(const char **)(a2 + 16));
      if ( v3 )
      {
        sub_22EC0(*(const char **)(a1 + 24), *(const char **)(a2 + 24));
        if ( v4 )
        {
          if ( *(int *)(a1 + 32) == *(int *)(a2 + 32) )
            sub_22EC0(*(const char **)(a1 + 40), *(const char **)(a2 + 40));
        }
      }
    }
  }
  return 0.0;
}


// Function: daemonized @ 0x283e0
double daemonized()
{
  int v0; // eax
  __pid_t v2; // ebx

  v0 = open("/dev/tty", 256);
  if ( v0 >= 0 )
  {
    close(v0);
    return 0.0;
  }
  else
  {
    if ( getppid() == 1 )
    {
      v2 = getsid(0);
      if ( v2 == getpid() )
        sub_203A0("misc.c", "daemonized", 0x7BAu, 0, 7, 0, "already daemonized");
    }
    return 0.0;
  }
}


// Function: argv_split @ 0x28590
double argv_split(char *s, int *a2, void ***a3, int a4)
{
  void **v5; // rax
  char v6; // al
  char *v7; // r12
  unsigned int v8; // r15d
  long long v9; // rbp
  int v10; // eax
  void **v11; // rax
  void **v12; // r14
  size_t v13; // r12
  void **v14; // r13
  long long v15; // rdx
  void *v16; // rax
  char v17; // r13
  long long v18; // rbp
  int v19; // eax
  unsigned int v20; // r14d
  char *v21; // r12
  char *v22; // r13
  char v23; // cl
  void **v24; // rbx
  void *v25; // rdi
  int v27; // eax
  unsigned long long v28; // rax
  char *v29; // [rsp+0h] [rbp-68h]
  int v30; // [rsp+8h] [rbp-60h]
  char v31; // [rsp+Eh] [rbp-5Ah]
  char v32; // [rsp+Eh] [rbp-5Ah]
  unsigned char v33; // [rsp+Fh] [rbp-59h]
  void **ptr; // [rsp+10h] [rbp-58h]
  int v35; // [rsp+18h] [rbp-50h]

  sub_21540(1u, 8u, (long long)a3);
  *a3 = 0;
  ptr = v5;
  *a2 = 0;
  v6 = *s;
  if ( !*s )
  {
    v35 = 0;
    goto LABEL_33;
  }
  v7 = s;
  v8 = 0;
  v9 = 0;
  while ( v6 == 32 || v6 == 9 )
  {
LABEL_31:
    v8 = sub_3DA20(v8, 1);
    v7 = &s[v8];
    v6 = *v7;
    if ( !*v7 )
      goto LABEL_32;
  }
  if ( a4 && v6 == 35 )
  {
LABEL_32:
    v35 = v9;
    goto LABEL_33;
  }
  v10 = sub_3DA20((unsigned int)v9, 2);
  sub_21680((long long)ptr, v10, 8);
  v12 = v11;
  ptr = v11;
  v13 = strlen(v7);
  v14 = &v12[v9];
  v35 = sub_3DA20((unsigned int)v9, 1);
  sub_21540(1u, v13 + 1, v15);
  *v14 = v16;
  v29 = v16;
  v14[1] = 0;
  v17 = s[v8];
  if ( !v17 )
  {
LABEL_33:
    *a2 = v35;
    *a3 = ptr;
    return 0.0;
  }
  v30 = 0;
  v18 = 0;
  do
  {
    while ( 1 )
    {
      v20 = sub_3DA20(v8, 1);
      v21 = &s[v20];
      if ( v17 == 92 )
        break;
      if ( v30 )
      {
        if ( v30 == v17 )
        {
          v30 = 0;
          v8 = v20;
          goto LABEL_12;
        }
      }
      else
      {
        if ( v17 == 32 || v17 == 9 )
        {
          v9 = v35;
          goto LABEL_31;
        }
        if ( v17 == 34 || v17 == 39 )
        {
          v8 = v20;
          v30 = v17;
          goto LABEL_12;
        }
      }
      v8 = v20;
      v19 = sub_3DA20((unsigned int)v18, 1);
      v29[v18] = v17;
      v18 = v19;
LABEL_12:
      v17 = *v21;
      if ( !*v21 )
        goto LABEL_18;
    }
    if ( (unsigned char)(*v21 - 34) <= 0x3Au )
    {
      v33 = *v21 - 34;
      v32 = *v21;
      v22 = &v29[(int)v18];
      v27 = sub_3DA20((unsigned int)v18, 1);
      v23 = v32;
      v18 = v27;
      v28 = 0xFBFFFFFFFFFFFFDELL;
      if ( _bittest64((const long long *)&v28, v33) )
        goto LABEL_17;
LABEL_29:
      *v22 = v23;
      v8 = sub_3DA20(v8, 2);
      v21 = &s[v8];
      goto LABEL_12;
    }
    v31 = *v21;
    v22 = &v29[(int)v18];
    v18 = (int)sub_3DA20((unsigned int)v18, 1);
    if ( !v30 )
    {
      v23 = v31;
      if ( v31 == 32 )
        goto LABEL_29;
    }
LABEL_17:
    *v22 = 92;
    v17 = *v21;
    v8 = v20;
  }
  while ( *v21 );
LABEL_18:
  if ( !v30 )
    goto LABEL_33;
  if ( !ptr )
    return 0.0;
  v24 = ptr;
  do
  {
    v25 = *v24++;
    free(v25);
  }
  while ( &ptr[v35] != v24 );
  free(ptr);
  return 0.0;
}


// Function: argv_assemble @ 0x289c0
double argv_assemble(int a1, long long *a2)
{
  long long *v2; // rbx
  double v3; // xmm0_8
  long long *v4; // rax
  long long *v5; // rax
  long long *v6; // rbp
  unsigned long long v7; // r12
  int v8; // r15d
  int v9; // r13d
  unsigned int v10; // r14d
  unsigned int v11; // eax
  double v12; // xmm0_8
  char *v13; // rax
  unsigned int v14; // eax
  double v15; // xmm0_8
  double v16; // xmm0_8
  long long v17; // rax
  long long v18; // rdx
  void *v19; // r12
  size_t v20; // rax
  size_t v21; // r13
  const void *v22; // rax
  long long v23; // rax
  char *v25; // rax
  long long *ptr; // [rsp+0h] [rbp-48h]
  unsigned int v27; // [rsp+8h] [rbp-40h]

  v2 = a2;
  v3 = sub_B880();
  ptr = v4;
  if ( !v4 || (v3 = sub_B880(), (v6 = v5) == 0) )
    sub_1EE30("misc.c", (long long)"argv_assemble", 2068, 1, 1, 0, (long long)"sshbuf_new failed", v3, a2);
  if ( a1 <= 0 )
    goto LABEL_23;
  v27 = 0;
  v7 = 0xFBFFFFFFFFFFFFDELL;
  do
  {
    sub_BE60((long long)v6);
    v8 = *(unsigned char *)*v2;
    if ( !(char)v8 )
    {
      if ( v27 )
      {
        v15 = sub_1B180(ptr, 32);
        if ( v14 )
        {
LABEL_29:
          v25 = sub_B050(v14);
          sub_1EE30("misc.c", (long long)"argv_assemble", 2099, 1, 1, (long long)v25, (long long)"assemble", v15);
        }
      }
LABEL_28:
      v15 = sub_1AAD0(ptr, (long long)v6);
      if ( v14 )
        goto LABEL_29;
      goto LABEL_22;
    }
    v9 = 0;
    v10 = 0;
    do
    {
      if ( (char)v8 == 32 )
      {
LABEL_14:
        v9 = 1;
        v12 = sub_1B180(v6, v8);
        goto LABEL_15;
      }
      if ( (char)v8 <= 32 )
      {
        if ( (char)v8 == 9 )
          goto LABEL_14;
      }
      else if ( (unsigned char)(v8 - 34) <= 0x3Au && !_bittest64((const long long *)&v7, (unsigned int)(v8 - 34)) )
      {
        v12 = sub_1B180(v6, 92);
        if ( v11 )
        {
LABEL_12:
          v13 = sub_B050(v11);
          sub_1EE30("misc.c", (long long)"argv_assemble", 2093, 1, 1, (long long)v13, (long long)"sshbuf_put_u8", v12);
        }
      }
      v12 = sub_1B180(v6, v8);
LABEL_15:
      if ( v11 )
        goto LABEL_12;
      v10 = sub_3DA20(v10, 1);
      v8 = *(unsigned char *)(*v2 + (int)v10);
    }
    while ( (char)v8 );
    if ( v27 )
    {
      v15 = sub_1B180(ptr, 32);
      if ( v14 )
        goto LABEL_29;
    }
    if ( !v9 )
      goto LABEL_28;
    v15 = sub_1B180(ptr, 34);
    if ( v14 )
      goto LABEL_29;
    v15 = sub_1AAD0(ptr, (long long)v6);
    if ( v14 )
      goto LABEL_29;
    v15 = sub_1B180(ptr, 34);
    if ( v14 )
      goto LABEL_29;
LABEL_22:
    ++v2;
    v27 = sub_3DA20(v27, 1);
  }
  while ( a1 != v27 );
LABEL_23:
  v16 = sub_C3D0((long long)ptr);
  v19 = malloc(v17 + 1);
  if ( !v19 )
    sub_1EE30("misc.c", (long long)"argv_assemble", 2102, 1, 1, 0, (long long)"malloc failed", v16, v18);
  sub_C3D0((long long)ptr);
  v21 = v20;
  sub_C520((long long)ptr);
  memcpy(v19, v22, v21);
  sub_C3D0((long long)ptr);
  *((char *)v19 + v23) = 0;
  sub_BCE0(ptr);
  sub_BCE0(v6);
  return 0.0;
}


// Function: argv_next @ 0x28d60
double argv_next(int *a1, long long *a2)
{
  long long v3; // rdi

  v3 = (unsigned int)*a1;
  if ( *(long long *)*a2 && (int)v3 > 0 )
  {
    *a1 = sub_3DA20(v3, 0xFFFFFFFFLL);
    *a2 += 8LL;
  }
  return 0.0;
}


// Function: exited_cleanly @ 0x28f70
double exited_cleanly(__pid_t pid, const char *a2, long long a3, int a4)
{
  int v7; // edi
  char *v9; // rax
  unsigned int v10; // edx
  int v11; // r8d
  const char *v12; // [rsp-20h] [rbp-68h]
  const char *v13; // [rsp-18h] [rbp-60h]
  long long v14; // [rsp-10h] [rbp-58h]
  long long v15; // [rsp-8h] [rbp-50h]
  int stat_loc; // [rsp+4h] [rbp-44h] BYREF
  unsigned long long v17; // [rsp+8h] [rbp-40h]

  v17 = __readfsqword(0x28u);
  while ( waitpid(pid, &stat_loc, 0) == -1 )
  {
    v7 = *__errno_location();
    if ( v7 != 4 )
    {
      v9 = strerror(v7);
      sub_203A0("misc.c", "exited_cleanly", 0x864u, 0, 2, 0, "%s waitpid: %s", a2, v9);
      return 0.0;
    }
  }
  if ( __OFSUB__((stat_loc & 0x7F) + 1, 1) || (stat_loc & 0x7F) == 0 )
  {
    if ( !BYTE1(stat_loc) )
      return 0.0;
    v15 = BYTE1(stat_loc);
    v10 = 2156;
    v14 = a3;
    v13 = a2;
    v11 = a4 == 0 ? 3 : 5;
    v12 = "%s %s failed, status %d";
  }
  else
  {
    v11 = 2;
    v15 = stat_loc & 0x7F;
    v10 = 2153;
    v14 = a3;
    v13 = a2;
    v12 = "%s %s exited on signal %d";
  }
  sub_203A0("misc.c", "exited_cleanly", v10, 0, v11, 0, v12, v13, v14, v15);
  return 0.0;
}


// Function: safe_path @ 0x29150
double safe_path(const char *a1, long long a2, long long a3, int a4, char *a5, size_t a6)
{
  long long v7; // rbp
  char *v8; // rsi
  int *v10; // rax
  char *v11; // rax
  struct stat buf; // [rsp+20h] [rbp-20D8h] BYREF
  char file[24]; // [rsp+B0h] [rbp-2048h] BYREF
  char s1[24]; // [rsp+10B0h] [rbp-1048h] BYREF
  unsigned long long v18; // [rsp+20B8h] [rbp-40h]

  v18 = __readfsqword(0x28u);
  if ( __realpath_chk(a1, file, 4096) )
  {
    LODWORD(v7) = 0;
    if ( a3 )
      v7 = __realpath_chk(a3, s1, 4096) != 0;
    if ( (*(int *)(a2 + 24) & 0xF000) == 0x8000 )
    {
      if ( ((unsigned int)sub_31190(*(unsigned int *)(a2 + 28)) || *(int *)(a2 + 28) == a4)
        && (*(char *)(a2 + 24) & 0x12) == 0 )
      {
        while ( 1 )
        {
          v8 = dirname(file);
          if ( !v8 )
          {
            snprintf(a5, a6, "dirname() failed");
            return 0.0;
          }
          sub_3BEE0(file, v8, 4096);
          if ( stat(file, &buf) == -1 || !(unsigned int)sub_31190(buf.st_uid) && buf.st_uid != a4 )
            break;
          if ( (buf.st_mode & 0x12) != 0 )
            break;
          if ( v7 && !strcmp(s1, file) || !strcmp("/", file) || !strcmp(".", file) )
            return 0.0;
        }
        __snprintf_chk(a5, a6, 1, -1, "bad ownership or modes for directory %s", file);
      }
      else
      {
        __snprintf_chk(a5, a6, 1, -1, "bad ownership or modes for file %s", file);
      }
    }
    else
    {
      __snprintf_chk(a5, a6, 1, -1, "%s is not a regular file", file);
    }
  }
  else
  {
    v10 = __errno_location();
    v11 = strerror(*v10);
    __snprintf_chk(a5, a6, 1, -1, "realpath %s failed: %s", a1, v11);
  }
  return 0.0;
}


// Function: safe_path_fd @ 0x29440
double safe_path_fd(int a1, const char *a2, long long a3, char *a4, size_t a5)
{
  int *v9; // rax
  char *v10; // rax
  struct stat v11; // [rsp+0h] [rbp-D8h] BYREF
  unsigned long long v12; // [rsp+98h] [rbp-40h]

  v12 = __readfsqword(0x28u);
  if ( fstat(a1, &v11) == -1 )
  {
    v9 = __errno_location();
    v10 = strerror(*v9);
    __snprintf_chk(a4, a5, 1, -1, "cannot stat file %s: %s", a2, v10);
  }
  else
  {
    sub_29150(a2, (long long)&v11, *(long long *)(a3 + 32), *(int *)(a3 + 16), a4, a5);
  }
  return 0.0;
}


// Function: child_set_env @ 0x29590
double child_set_env(char ***a1, int *a2, const char *a3, const char *a4)
{
  char **v5; // r12
  unsigned int v6; // eax
  long long v7; // rcx
  char *v8; // rbp
  size_t v9; // r13
  unsigned int v10; // r14d
  long long v11; // rbx
  long long v12; // rax
  unsigned int v13; // eax
  long long v14; // rcx
  size_t v16; // rbp
  size_t v17; // rax
  char *v18; // rax
  char *v19; // rbp
  size_t v20; // rbx
  size_t v21; // rax
  char **v22; // rax
  long long v23; // rcx
  long long v24; // rsi
  int v25; // ebp
  char **v26; // rax
  long long v29; // [rsp+18h] [rbp-40h]

  if ( strchr(a3, 61) )
  {
    sub_203A0("misc.c", "child_set_env", 0x8DCu, 0, 2, 0, "Invalid environment variable \"%.100s\"", a3);
    return 0.0;
  }
  v5 = *a1;
  if ( !*a1 && !*a2 )
  {
    sub_21440(8u);
    *a1 = v22;
    *v22 = 0;
    *a2 = 1;
    v5 = *a1;
    v6 = strlen(a3);
    v8 = *v5;
    if ( !*v5 )
    {
      v23 = 8;
      v24 = 51;
      v25 = 51;
      v11 = 0;
LABEL_19:
      v29 = v23;
      sub_21680((long long)v5, v24, 8);
      v14 = v29;
      v5 = v26;
      *a1 = v26;
      *a2 = v25;
      goto LABEL_10;
    }
LABEL_4:
    v9 = v6;
    v10 = 0;
    v11 = 0;
    while ( strncmp(v8, a3, v9) || v8[v9] != 61 )
    {
      v12 = v10 + 1;
      v8 = v5[v12];
      ++v10;
      v11 = v12;
      if ( !v8 )
        goto LABEL_8;
    }
    free(v8);
    goto LABEL_13;
  }
  v6 = strlen(a3);
  v8 = *v5;
  if ( *v5 )
    goto LABEL_4;
  v10 = 0;
  v11 = 0;
LABEL_8:
  v13 = *a2;
  if ( v10 >= *a2 - 1 )
  {
    if ( v13 > 0x3E7 )
      sub_1EE30("misc.c", (long long)"child_set_env", 2300, 0, 1, 0, (long long)"child_set_env: too many env vars", v7);
    v24 = v13 + 50;
    v25 = v13 + 50;
    v23 = 8LL * (v10 + 1);
    goto LABEL_19;
  }
  v14 = 8LL * (v10 + 1);
LABEL_10:
  *(char **)((char *)v5 + v14) = 0;
LABEL_13:
  v16 = strlen(a3);
  v17 = strlen(a4);
  sub_21440(v16 + v17 + 2);
  v5[v11] = v18;
  v19 = v18;
  v20 = strlen(a3);
  v21 = strlen(a4);
  __snprintf_chk(v19, v20 + v21 + 2, 1, -1, "%s=%s", a3, a4);
  return 0.0;
}


// Function: valid_domain @ 0x29910
double valid_domain(const char *a1, int a2, long long *a3)
{
  size_t v6; // rax
  size_t v7; // r15
  const unsigned short **v8; // rax
  long long v9; // rbx
  const char *v10; // r9
  const char *v11; // r8
  const unsigned short **v12; // r14
  const int_t **v13; // rax
  char *v14; // rdx
  const char *v15; // rdi
  char v16; // cl
  const int_t **v17; // rsi
  int_t v18; // eax
  const char *v19; // rax

  v6 = strlen(a1);
  if ( !v6 )
  {
    sub_3BEE0(&unk_680A0, "empty domain name", 256);
LABEL_19:
    if ( a3 )
      *a3 = &unk_680A0;
    return 0.0;
  }
  v7 = v6;
  v8 = __ctype_b_loc();
  v9 = *(unsigned char *)a1;
  v10 = a1;
  v11 = "domain name \"%.100s\" starts with invalid character";
  v12 = v8;
  if ( ((*v8)[v9] & 0xC00) == 0 )
  {
LABEL_18:
    __snprintf_chk(&unk_680A0, 256, 1, 256, v11, v10);
    goto LABEL_19;
  }
  v13 = __ctype_tolower_loc();
  v14 = (char *)a1;
  v15 = &a1[v7];
  v16 = 0;
  v17 = v13;
  while ( 1 )
  {
    v18 = (*v17)[v9];
    if ( a2 )
      *v14 = v18;
    if ( v16 == 46 && (char)v18 == 46 )
    {
      v10 = a1;
      v11 = "domain name \"%.100s\" contains consecutive separators";
      goto LABEL_18;
    }
    if ( (unsigned char)(v18 - 45) > 1u && ((*v12)[(unsigned char)v18] & 8) == 0 && (char)v18 != 95 )
    {
      v10 = a1;
      v11 = "domain name \"%.100s\" contains invalid characters";
      goto LABEL_18;
    }
    if ( v15 == ++v14 )
      break;
    v9 = (unsigned char)*v14;
    v16 = v18;
  }
  v19 = &a1[v7 - 1];
  if ( *v19 == 46 )
    *v19 = 0;
  if ( a3 )
  {
    *a3 = 0;
    return 0.0;
  }
  return 0.0;
}


// Function: parse_uri @ 0x29b70
double parse_uri(char *s2, char *s1, char **a3, const char **a4, int *a5, const char **a6)
{
  size_t v9; // r15
  char *v10; // r15
  char *v11; // rax
  char *v12; // r14
  char *v13; // rax
  char *v14; // rdi
  const char *v15; // r10
  const char *v16; // r9
  char *v18; // rax
  const char *v19; // rax
  const char *v20; // rax
  int v21; // eax
  int v22; // edx
  const char *v23; // rax
  char *v24; // rax
  int v25; // eax
  int v26; // eax
  char *v28; // [rsp+8h] [rbp-70h]
  char *ptrc; // [rsp+10h] [rbp-68h]
  const char *ptr; // [rsp+10h] [rbp-68h]
  const char *ptrd; // [rsp+10h] [rbp-68h]
  char *ptra; // [rsp+10h] [rbp-68h]
  char *ptrb; // [rsp+10h] [rbp-68h]
  int v34; // [rsp+18h] [rbp-60h]
  const char *v35; // [rsp+18h] [rbp-60h]
  char v36; // [rsp+2Fh] [rbp-49h] BYREF
  char *s[9]; // [rsp+30h] [rbp-48h] BYREF

  s[1] = (char *)__readfsqword(0x28u);
  v9 = strlen(s2);
  if ( !strncmp(s1, s2, v9) && !strncmp(&s1[v9], "://", 3u) )
  {
    if ( a3 )
      *a3 = 0;
    if ( a4 )
      *a4 = 0;
    if ( a5 )
      *a5 = -1;
    if ( a6 )
      *a6 = 0;
    s[0] = (char *)sub_21840(&s1[v9 + 3]);
    v10 = s[0];
    v11 = strchr(s[0], 64);
    v12 = v11;
    if ( v11 )
    {
      *v11 = 0;
      v13 = strchr(s[0], 59);
      v14 = s[0];
      if ( v13 )
      {
        *v13 = 0;
        v14 = s[0];
      }
      if ( !*v14 || (sub_22610(v14), !v18) )
      {
        v15 = 0;
        v16 = 0;
        v12 = 0;
        goto LABEL_16;
      }
      s[0] = v12 + 1;
      v12 = v18;
    }
    sub_24910((const char **)s, &v36);
    v16 = v19;
    if ( !v19 )
    {
LABEL_42:
      v15 = 0;
      goto LABEL_16;
    }
    if ( *v19 )
    {
      sub_24C30(v19);
      ptr = (const char *)sub_21840(v20);
      sub_29910(ptr, 0, 0);
      v16 = ptr;
      if ( !v21 )
      {
LABEL_43:
        v15 = 0;
        goto LABEL_16;
      }
      v15 = s[0];
      v22 = -1;
      if ( !s[0] )
        goto LABEL_33;
      if ( !*s[0] )
        goto LABEL_32;
      if ( v36 != 58 )
        goto LABEL_27;
      v35 = ptr;
      ptra = s[0];
      v24 = strchr(s[0], 47);
      if ( v24 )
      {
        *v24 = 0;
        ptrb = v24;
        sub_24030(s[0]);
        v16 = v35;
        v22 = v25;
        if ( v25 > 0 )
        {
          v15 = ptrb + 1;
          s[0] = ptrb + 1;
          if ( ptrb[1] )
          {
LABEL_27:
            v34 = v22;
            ptrd = v16;
            sub_22610(v15);
            v16 = ptrd;
            v22 = v34;
            v15 = v23;
            if ( !v23 )
              goto LABEL_16;
LABEL_33:
            if ( a3 )
            {
              *a3 = v12;
              v12 = 0;
            }
            if ( a4 )
            {
              *a4 = v16;
              v16 = 0;
            }
            if ( a5 )
              *a5 = v22;
            if ( a6 )
            {
              *a6 = v15;
              v15 = 0;
            }
            goto LABEL_16;
          }
LABEL_32:
          v15 = 0;
          goto LABEL_33;
        }
        goto LABEL_43;
      }
      sub_24030(ptra);
      v16 = v35;
      v22 = v26;
      if ( v26 > 0 )
      {
        s[0] = 0;
        v15 = 0;
        goto LABEL_33;
      }
      goto LABEL_42;
    }
    v15 = 0;
    v16 = 0;
LABEL_16:
    ptrc = (char *)v16;
    v28 = (char *)v15;
    free(v10);
    free(v12);
    free(ptrc);
    free(v28);
  }
  return 0.0;
}


// Function: valid_env_name @ 0x29f30
double valid_env_name(unsigned char *a1)
{
  unsigned char v1; // bl
  unsigned char *v2; // rbp
  const unsigned short *v3; // rdx

  v1 = *a1;
  if ( !*a1 )
    return 0.0;
  v2 = a1;
  v3 = *__ctype_b_loc();
  while ( (v3[v1] & 8) != 0 || v1 == 95 )
  {
    v1 = *++v2;
    if ( !v1 )
      return 0.0;
  }
  return 0.0;
}


// Function: atoi_err @ 0x2a090
double atoi_err(char *a1, int *a2)
{
  int v3; // edx

  if ( a1 && *a1 )
  {
    v3 = sub_3BFE0(a1);
    *a2 = v3;
  }
  return 0.0;
}


// Function: parse_absolute_time @ 0x2a190
double parse_absolute_time(const char *a1, time_t *a2)
{
  size_t v3; // rax
  unsigned long long v4; // r12
  unsigned long long v5; // rbp
  int v6; // eax
  long long v7; // r14
  const char *v8; // rsi
  char *v9; // rax
  time_t v10; // rax
  struct tm v12; // [rsp+0h] [rbp-98h] BYREF
  char s[40]; // [rsp+40h] [rbp-58h] BYREF
  unsigned long long v14; // [rsp+68h] [rbp-30h]

  v14 = __readfsqword(0x28u);
  *a2 = 0;
  v3 = strlen(a1);
  if ( v3 <= 1 )
    return 0.0;
  v4 = v3 - 1;
  v5 = v3;
  if ( !strcasecmp(&a1[v3 - 1], "Z") )
  {
    LODWORD(v7) = 1;
    if ( v4 != 12 )
      goto LABEL_7;
  }
  else
  {
    if ( v5 <= 3 )
      return 0.0;
    v4 = v5 - 3;
    v6 = strcasecmp(&a1[v5 - 3], "UTC");
    v7 = v6 == 0;
    if ( v6 )
      v4 = v5;
    if ( v4 != 12 )
    {
LABEL_7:
      if ( v4 == 14 )
      {
        __snprintf_chk(s, 32, 1, 32, "%.4s-%.2s-%.2sT%.2s:%.2s:%.2s", a1, a1 + 4, a1 + 6, a1 + 8, a1 + 10, a1 + 12);
        v8 = "%Y-%m-%dT%H:%M:%S";
      }
      else
      {
        if ( v4 != 8 )
          return 0.0;
        __snprintf_chk(s, 32, 1, 32, "%.4s-%.2s-%.2s", a1, a1 + 4, a1 + 6);
        v8 = "%Y-%m-%d";
      }
      goto LABEL_9;
    }
  }
  __snprintf_chk(s, 32, 1, 32, "%.4s-%.2s-%.2sT%.2s:%.2s", a1, a1 + 4, a1 + 6, a1 + 8, a1 + 10);
  v8 = "%Y-%m-%dT%H:%M";
LABEL_9:
  memset(&v12, 0, sizeof(v12));
  v9 = strptime(s, v8, &v12);
  if ( v9 && !*v9 )
  {
    if ( v7 )
    {
      v10 = timegm(&v12);
      if ( v10 < 0 )
        return 0.0;
    }
    else
    {
      v10 = mktime(&v12);
      if ( v10 < 0 )
        return 0.0;
    }
    *a2 = v10;
  }
  return 0.0;
}


// Function: format_absolute_time @ 0x2a450
double format_absolute_time(time_t a1, char *a2, size_t a3)
{
  time_t timer; // [rsp+8h] [rbp-60h] BYREF
  struct tm tp; // [rsp+10h] [rbp-58h] BYREF
  unsigned long long v7; // [rsp+48h] [rbp-20h]

  v7 = __readfsqword(0x28u);
  if ( a1 < 0 )
    a1 = 0x7FFFFFFFFFFFFFFFLL;
  timer = a1;
  localtime_r(&timer, &tp);
  strftime(a2, a3, "%Y-%m-%dT%H:%M:%S", &tp);
  return 0.0;
}


// Function: path_absolute @ 0x2a560
double path_absolute()
{
  return 0.0;
}


// Function: opt_flag @ 0x2a6a0
double opt_flag(char *s2, int a2, const char **a3)
{
  size_t v4; // rax
  const char *v5; // rbp
  size_t v6; // r14

  v4 = strlen(s2);
  v5 = *a3;
  v6 = v4;
  if ( a2 && !strncasecmp(*a3, "no-", 3u) )
    v5 += 3;
  if ( !strncasecmp(v5, s2, v6) )
    *a3 = &v5[v6];
  return 0.0;
}


// Function: opt_dequote @ 0x2a7b0
double opt_dequote(long long *a1, long long *a2)
{
  char *v2; // r13
  char *v3; // rbx
  size_t v5; // rax
  char *v6; // rax
  char v7; // dl
  long long v8; // rcx
  char v10; // di
  char *v11; // rdx

  v2 = (char *)*a1;
  *a2 = 0;
  if ( *v2 == 34 )
  {
    v3 = v2 + 1;
    v5 = strlen(v2 + 1);
    v6 = malloc(v5 + 1);
    if ( v6 )
    {
      v7 = v2[1];
      if ( v7 != 34 && (v8 = 0, v7) )
      {
        while ( 1 )
        {
          if ( v7 != 92 || (v10 = v3[1], v11 = v3 + 1, v10 != 34) )
          {
            v10 = *v3;
            v11 = v3;
          }
          ++v8;
          v3 = v11 + 1;
          v6[v8 - 1] = v10;
          v7 = v11[1];
          if ( !v7 )
            break;
          if ( v7 == 34 )
            goto LABEL_6;
        }
      }
      else
      {
        v8 = 0;
LABEL_6:
        if ( v7 )
        {
          v6[v8] = 0;
          *a1 = v3 + 1;
          return 0.0;
        }
      }
      *a2 = "missing end quote";
      free(v6);
    }
    else
    {
      *a2 = "memory allocation failed";
    }
  }
  else
  {
    *a2 = "missing start quote";
  }
  return 0.0;
}


// Function: opt_match @ 0x2a9c0
double opt_match(const char **a1, const char *a2)
{
  size_t v2; // rax
  const char *v3; // r13
  size_t v4; // rbx

  v2 = strlen(a2);
  v3 = *a1;
  v4 = v2;
  if ( strncasecmp(*a1, a2, v2) )
    return 0.0;
  if ( v3[v4] == 61 )
    *a1 = &v3[v4 + 1];
  return 0.0;
}


// Function: opt_array_append2 @ 0x2abc0
double opt_array_append2(
        const char *a1,
        int a2,
        const char *a3,
        void **a4,
        void **a5,
        unsigned int *a6,
        const char *src,
        int a8)
{
  unsigned int v8; // eax
  void *v12; // rax
  char *v13; // rax
  void **v14; // rbp

  v8 = *a6;
  if ( *a6 > 0x7FFFFFFE )
    sub_1EE30(
      "misc.c",
      (long long)"opt_array_append2",
      2562,
      0,
      1,
      0,
      (long long)"%s line %d: Too many %s entries",
      a1,
      a2,
      a3);
  if ( a5 )
  {
    sub_21760(*a5, v8, v8 + 1, 4);
    *a5 = v12;
    *((int *)v12 + *a6) = a8;
    v8 = *a6;
  }
  sub_21760(*a4, v8, v8 + 1, 8);
  *a4 = v13;
  v14 = (void **)&v13[8 * *a6];
  *v14 = sub_21840(src);
  ++*a6;
  return 0.0;
}


// Function: opt_array_append @ 0x2acf0
double opt_array_append(const char *a1, int a2, const char *a3, void **a4, unsigned int *a5, const char *a6)
{
  sub_2ABC0(a1, a2, a3, a4, 0, a5, a6, 0);
  return 0.0;
}


// Function: ssh_signal @ 0x2ad90
double ssh_signal(int sig, void (*a2)(int))
{
  int *v3; // rax
  char *v4; // rbx
  char *v5; // rax
  struct sigaction v6; // [rsp+0h] [rbp-158h] BYREF
  struct sigaction oact; // [rsp+A0h] [rbp-B8h] BYREF
  unsigned long long v8; // [rsp+138h] [rbp-20h]

  v8 = __readfsqword(0x28u);
  v6.sa_handler = a2;
  memset(&v6.sa_mask, 0, 0x90u);
  sigfillset(&v6.sa_mask);
  if ( sig != 14 )
    v6.sa_flags = 0x10000000;
  if ( sigaction(sig, &v6, &oact) == -1 )
  {
    v3 = __errno_location();
    v4 = strerror(*v3);
    v5 = strsignal(sig);
    sub_203A0("misc.c", "ssh_signal", 0xA24u, 0, 7, 0, "sigaction(%s): %s", v5, v4);
  }
  return 0.0;
}


// Function: stdfd_devnull @ 0x2af10
double stdfd_devnull(int a1, int a2, int a3)
{
  int v4; // eax
  int v5; // ebp
  int *v7; // rax
  char *v8; // rax
  int *v9; // rax
  char *v10; // rax

  v4 = open("/dev/null", 2);
  if ( v4 == -1 )
  {
    v9 = __errno_location();
    v10 = strerror(*v9);
    sub_203A0("misc.c", "stdfd_devnull", 0xA30u, 1u, 2, 0, "open %s: %s", "/dev/null", v10);
    return 0.0;
  }
  v5 = v4;
  if ( a1 && dup2(v4, 0) == -1 )
    goto LABEL_8;
  if ( !a2 )
  {
    if ( !a3 )
      goto LABEL_5;
LABEL_12:
    if ( dup2(v5, 2) == -1 )
    {
LABEL_8:
      v7 = __errno_location();
      v8 = strerror(*v7);
      sub_203A0("misc.c", "stdfd_devnull", 0xA37u, 1u, 2, 0, "dup2: %s", v8);
      if ( v5 > 2 )
        goto LABEL_9;
      return 0.0;
    }
    goto LABEL_5;
  }
  if ( dup2(v5, 1) == -1 )
    goto LABEL_8;
  if ( a3 )
    goto LABEL_12;
LABEL_5:
  if ( v5 <= 2 )
    return 0.0;
LABEL_9:
  close(v5);
  return 0.0;
}


// Function: subprocess @ 0x2b180
double subprocess(
        const char *a1,
        const char *a2,
        long long a3,
        const char **a4,
        FILE **a5,
        int a6,
        struct passwd *a7,
        void (*a8)(struct passwd *, double),
        void (*a9)(double))
{
  struct passwd *v11; // r12
  double v12; // xmm0_8
  double v13; // xmm0_8
  const char *v14; // rdi
  int v15; // eax
  __pid_t v16; // eax
  long long v17; // rdx
  FILE *v18; // rbx
  __pid_t v19; // r10d
  __uid_t v21; // eax
  int v22; // eax
  double v23; // xmm0_8
  unsigned int i; // ebp
  double v25; // xmm0_8
  int v26; // r13d
  int *v27; // rax
  int *v28; // rbp
  const char *v29; // rdi
  char *v30; // rax
  const char *v31; // rdx
  int *v32; // rax
  char *v33; // rax
  char *v34; // rax
  FILE *v35; // rax
  int *v36; // rbx
  char *v37; // rax
  int *v38; // rax
  char *v39; // rax
  char **v40; // rax
  char *v41; // rcx
  int *v42; // rax
  char *v43; // rax
  char *v44; // rax
  char *v45; // rax
  char *v46; // rax
  char *v47; // rax
  char *v48; // rax
  char *v49; // rax
  __pid_t argva; // [rsp+8h] [rbp-320h]
  const char *v53; // [rsp+20h] [rbp-308h]
  int v54; // [rsp+3Ch] [rbp-2ECh] BYREF
  char **envp; // [rsp+40h] [rbp-2E8h] BYREF
  int pipedes[2]; // [rsp+48h] [rbp-2E0h] BYREF
  struct stat buf; // [rsp+50h] [rbp-2D8h] BYREF
  char v58[520]; // [rsp+E0h] [rbp-248h] BYREF
  unsigned long long v59; // [rsp+2E8h] [rbp-40h]

  v11 = a7;
  v59 = __readfsqword(0x28u);
  v54 = 0;
  envp = 0;
  if ( a8 )
  {
    if ( !a7 || !a9 )
    {
      sub_203A0("misc.c", "subprocess", 0xA57u, 0, 2, 0, "%s: inconsistent arguments");
      return 0.0;
    }
  }
  else if ( !a7 )
  {
    v21 = getuid();
    v11 = getpwuid(v21);
    if ( !v11 )
    {
      sub_203A0("misc.c", "subprocess", 0xA5Bu, 0, 2, 0, "%s: no user for current uid");
      return 0.0;
    }
  }
  if ( a5 )
    *a5 = 0;
  v12 = sub_203A0(
          "misc.c",
          "subprocess",
          0xA61u,
          1u,
          7,
          0,
          "%s command \"%s\" running as %s (flags 0x%x)",
          a1,
          a2,
          v11->pw_name,
          a6);
  if ( (a6 & 3) == 3 )
  {
    sub_203A0("misc.c", "subprocess", 0xA67u, 1u, 2, 0, "inconsistent flags", v12);
    return 0.0;
  }
  if ( ((a6 & 2) == 0) != (a5 == 0) )
  {
    sub_203A0("misc.c", "subprocess", 0xA6Bu, 1u, 2, 0, "inconsistent flags/output", v12);
    return 0.0;
  }
  v53 = *a4;
  v13 = sub_2A560();
  v14 = v53;
  if ( !v15 )
  {
    sub_203A0("misc.c", "subprocess", 0xA74u, 0, 2, 0, "%s path is not absolute", a1);
    return 0.0;
  }
  if ( a8 )
  {
    a8(v11, v13);
    v14 = *a4;
  }
  if ( stat(v14, &buf) == -1 )
  {
    v42 = __errno_location();
    v43 = strerror(*v42);
    v23 = sub_203A0("misc.c", "subprocess", 0xA7Au, 0, 2, 0, "Could not stat %s \"%s\": %s", a1, *a4, v43);
LABEL_29:
    if ( a9 )
      a9(v23);
    return 0.0;
  }
  if ( (a6 & 8) == 0 )
  {
    v13 = sub_29150(*a4, (long long)&buf, 0, 0, v58, 0x200u);
    if ( v22 )
    {
      v23 = sub_203A0("misc.c", "subprocess", 0xA80u, 0, 2, 0, "Unsafe %s \"%s\": %s", a1, *a4, v58);
      goto LABEL_29;
    }
  }
  if ( pipe(pipedes) == -1 )
  {
    v38 = __errno_location();
    v39 = strerror(*v38);
    v23 = sub_203A0("misc.c", "subprocess", 0xA85u, 0, 2, 0, "%s: pipe: %s", a1, v39);
    goto LABEL_29;
  }
  if ( a9 )
    a9(v13);
  v16 = fork();
  if ( v16 == -1 )
  {
    v32 = __errno_location();
    v33 = strerror(*v32);
    sub_203A0("misc.c", "subprocess", 0xA90u, 0, 2, 0, "%s: fork: %s", a1, v33);
    close(pipedes[0]);
    close(pipedes[1]);
    return 0.0;
  }
  if ( !v16 )
  {
    if ( (a6 & 0x10) == 0 )
    {
      v54 = 5;
      sub_21540(8u, 5u, v17);
      envp = v40;
      sub_29590(&envp, &v54, "PATH", "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin");
      sub_29590(&envp, &v54, "USER", v11->pw_name);
      sub_29590(&envp, &v54, "LOGNAME", v11->pw_name);
      sub_29590(&envp, &v54, "HOME", v11->pw_dir);
      v41 = getenv("LANG");
      if ( v41 )
        sub_29590(&envp, &v54, "LANG", v41);
    }
    for ( i = 1; i != 65; i = sub_3DA20(i, 1) )
      v25 = sub_2AD90(i, 0);
    v26 = open("/dev/null", 2, v25);
    v27 = __errno_location();
    v28 = v27;
    if ( v26 == -1 )
    {
      v49 = strerror(*v27);
      sub_203A0("misc.c", "subprocess", 0xAA5u, 0, 2, 0, "%s: open %s: %s", a1, "/dev/null", v49);
      goto LABEL_55;
    }
    if ( dup2(v26, 0) == -1 )
    {
      v48 = strerror(*v28);
      sub_203A0("misc.c", "subprocess", 0xAAAu, 0, 2, 0, "%s: dup2: %s", a1, v48);
      goto LABEL_55;
    }
    if ( (a6 & 2) != 0 )
    {
      v26 = pipedes[1];
      if ( pipedes[1] == -1 )
        goto LABEL_38;
    }
    else if ( (a6 & 1) == 0 )
    {
LABEL_38:
      closefrom(3);
      if ( !geteuid() && initgroups(v11->pw_name, v11->pw_gid) == -1 )
      {
        v46 = strerror(*v28);
        sub_203A0(
          "misc.c",
          "subprocess",
          0xABCu,
          0,
          2,
          0,
          "%s: initgroups(%s, %u): %s",
          a1,
          v11->pw_name,
          v11->pw_gid,
          v46);
        _exit(1);
      }
      if ( setresgid(v11->pw_gid, v11->pw_gid, v11->pw_gid) == -1 )
      {
        v45 = strerror(*v28);
        sub_203A0("misc.c", "subprocess", 0xAC1u, 0, 2, 0, "%s: setresgid %u: %s", a1, v11->pw_gid, v45);
      }
      else if ( setresuid(v11->pw_uid, v11->pw_uid, v11->pw_uid) == -1 )
      {
        v47 = strerror(*v28);
        sub_203A0("misc.c", "subprocess", 0xAC6u, 0, 2, 0, "%s: setresuid %u: %s", a1, v11->pw_uid, v47);
      }
      else
      {
        if ( (a6 & 1) == 0 || dup2(0, 2) != -1 )
        {
          v29 = *a4;
          if ( envp )
          {
            execve(v29, (char *const *)a4, envp);
            v30 = strerror(*v28);
            v31 = "execve";
          }
          else
          {
            execv(v29, (char *const *)a4);
            v30 = strerror(*v28);
            v31 = "execv";
          }
          sub_203A0("misc.c", "subprocess", 0xAD4u, 0, 2, 0, "%s %s \"%s\": %s", a1, v31, a2, v30);
          _exit(127);
        }
        v44 = strerror(*v28);
        sub_203A0("misc.c", "subprocess", 0xACDu, 0, 2, 0, "%s: dup2: %s", a1, v44);
      }
LABEL_55:
      _exit(1);
    }
    if ( dup2(v26, 1) == -1 )
    {
      v34 = strerror(*v28);
      sub_203A0("misc.c", "subprocess", 0xAB5u, 0, 2, 0, "%s: dup2: %s", a1, v34);
      goto LABEL_55;
    }
    goto LABEL_38;
  }
  argva = v16;
  close(pipedes[1]);
  if ( (a6 & 2) != 0 )
  {
    v35 = fdopen(pipedes[0], "r");
    v19 = argva;
    v18 = v35;
    if ( !v35 )
    {
      v36 = __errno_location();
      v37 = strerror(*v36);
      sub_203A0("misc.c", "subprocess", 0xADFu, 0, 2, 0, "%s: fdopen: %s", a1, v37);
      close(pipedes[0]);
      kill(argva, 15);
      while ( waitpid(argva, 0, 0) == -1 && *v36 == 4 )
        ;
      return 0.0;
    }
  }
  else
  {
    v18 = 0;
    close(pipedes[0]);
    v19 = argva;
  }
  sub_203A0("misc.c", "subprocess", 0xAE8u, 1u, 7, 0, "%s pid %ld", a1, v19);
  if ( a5 )
    *a5 = v18;
  return 0.0;
}


// Function: lookup_env_in_list @ 0x2bb30
double lookup_env_in_list(char *s2, long long a2, long long a3)
{
  size_t v4; // rax
  size_t v5; // r15
  long long v6; // rbx
  const char *v7; // rbp

  v4 = strlen(s2);
  if ( !a3 )
    return 0.0;
  v5 = v4;
  v6 = 0;
  while ( 1 )
  {
    v7 = *(const char **)(a2 + 8 * v6);
    if ( !strncmp(v7, s2, v5) && v7[v5] == 61 )
      break;
    if ( a3 == ++v6 )
      return 0.0;
  }
  return 0.0;
}


// Function: lookup_setenv_in_list @ 0x2bcb0
double lookup_setenv_in_list(const char *a1, long long a2, long long a3)
{
  char *v4; // rbp
  char *v5; // rax

  v4 = (char *)sub_21840(a1);
  v5 = strchr(v4, 61);
  if ( v5 )
  {
    *v5 = 0;
    sub_2BB30(v4, a2, a3);
  }
  free(v4);
  return 0.0;
}


// Function: ssh_dss_sign @ 0x2bd90
double ssh_dss_sign(unsigned int *a1, void **a2, size_t *a3, long long a4, long long a5)
{
  long long v8; // rbp
  double v9; // xmm0_8
  int v10; // eax
  long long *v11; // rbx
  long long v12; // rbp
  long long v14; // rax
  unsigned int v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // eax
  int v19; // ebx
  unsigned long long v20; // r12
  long long *v21; // rax
  int v22; // eax
  int v23; // eax
  size_t v24; // rax
  size_t v25; // r15
  void *v26; // rax
  const void *v27; // rax
  long long v29; // [rsp+10h] [rbp-C8h] BYREF
  long long v30; // [rsp+18h] [rbp-C0h] BYREF
  char v31[48]; // [rsp+20h] [rbp-B8h] BYREF
  char v32[72]; // [rsp+50h] [rbp-88h] BYREF
  unsigned long long v33; // [rsp+98h] [rbp-40h]

  v33 = __readfsqword(0x28u);
  v8 = sub_30050(1);
  if ( a3 )
    *a3 = 0;
  if ( a2 )
    *a2 = 0;
  if ( a1 )
  {
    if ( *((long long *)a1 + 2) )
    {
      v9 = sub_F440(*a1);
      if ( v10 == 1 )
      {
        if ( v8 )
        {
          if ( (unsigned int)sub_30740(1, a4, a5, v32, 64) )
          {
            v11 = 0;
            v12 = 0;
          }
          else
          {
            v14 = DSA_do_sign(v32, (unsigned int)v8, *((long long *)a1 + 2), v9);
            v12 = v14;
            if ( v14 )
            {
              DSA_SIG_get0(v14, &v29, &v30);
              v15 = BN_num_bits(v29);
              v16 = sub_3DA20(v15, 7);
              v17 = v16 + 7;
              if ( v16 >= 0 )
                v17 = v16;
              v18 = BN_num_bits(v30);
              v19 = v17 >> 3;
              v20 = (int)sub_3DA20(v18, 7) / 8;
              if ( (unsigned long long)v19 <= 0x14 && v20 <= 0x14 )
              {
                __explicit_bzero_chk(v31, 40, 40, v9);
                BN_bn2bin(v29, &v31[-v19 + 20]);
                BN_bn2bin(v30, &v31[-v20 + 40]);
                v9 = sub_B880();
                v11 = v21;
                if ( !v21 )
                  goto LABEL_11;
                v9 = sub_1B800(v21, "ssh-dss");
                if ( v22 )
                  goto LABEL_11;
                v9 = sub_1B6C0(v11, v31, 0x28u);
                if ( v23 )
                  goto LABEL_11;
                v9 = sub_C3D0((long long)v11);
                v25 = v24;
                if ( a2 )
                {
                  v26 = malloc(v24);
                  *a2 = v26;
                  if ( !v26 )
                    goto LABEL_11;
                  v9 = sub_C520((long long)v11);
                  memcpy(*a2, v27, v25);
                }
                if ( a3 )
                  *a3 = v25;
                goto LABEL_11;
              }
              v11 = 0;
            }
            else
            {
              v11 = 0;
            }
          }
LABEL_11:
          __explicit_bzero_chk(v32, 64, 64, v9);
          DSA_SIG_free(v12);
          sub_BCE0(v11);
        }
      }
    }
  }
  return 0.0;
}


// Function: ssh_dss_verify @ 0x2c0e0
double ssh_dss_verify(unsigned int *a1, long long a2, unsigned long long a3, long long a4, long long a5)
{
  long long v7; // rax
  long long v8; // r12
  int v9; // eax
  long long v10; // rax
  long long *v11; // rbp
  double v12; // xmm0_8
  int v13; // eax
  long long v14; // r14
  long long v15; // r8
  long long v16; // r15
  int v18; // eax
  long long v19; // rax
  long long v20; // rax
  long long v21; // rax
  long long v22; // rax
  long long v23; // rax
  int v24; // eax
  int v25; // eax
  long long v27; // [rsp+0h] [rbp-B8h]
  long long v28; // [rsp+8h] [rbp-B0h]
  void *v29; // [rsp+18h] [rbp-A0h] BYREF
  long long v30; // [rsp+20h] [rbp-98h] BYREF
  void *ptr; // [rsp+28h] [rbp-90h] BYREF
  char v32[72]; // [rsp+30h] [rbp-88h] BYREF
  unsigned long long v33; // [rsp+78h] [rbp-40h]

  v33 = __readfsqword(0x28u);
  v29 = 0;
  v7 = sub_30050(1);
  ptr = 0;
  if ( !a1 )
    return 0.0;
  if ( !*((long long *)a1 + 2) )
    return 0.0;
  v8 = v7;
  sub_F440(*a1);
  if ( v9 != 1 )
    return 0.0;
  if ( !a2 )
    return 0.0;
  if ( !a3 )
    return 0.0;
  if ( !v8 )
    return 0.0;
  sub_B980(a2, a3);
  v11 = (long long *)v10;
  if ( !v10 )
    return 0.0;
  v12 = sub_1A6F0(v10, &ptr, 0);
  if ( v13 || (v12 = sub_1A590((long long)v11, &v29, &v30), v18) )
  {
LABEL_9:
    v14 = 0;
    v15 = 0;
    v16 = 0;
    goto LABEL_10;
  }
  if ( strcmp("ssh-dss", (const char *)ptr) )
  {
    v14 = 0;
    v15 = 0;
    v16 = 0;
    goto LABEL_10;
  }
  v12 = sub_C3D0((long long)v11);
  if ( !v19 )
  {
    if ( v30 == 40 )
    {
      v16 = DSA_SIG_new(v12);
      if ( v16 )
      {
        v20 = BN_new(v12);
        v15 = v20;
        if ( v20 )
        {
          v28 = v20;
          v21 = BN_new(v12);
          v15 = v28;
          v14 = v21;
          if ( v21 )
          {
            v22 = BN_bin2bn(v29, 20, v28);
            v15 = v28;
            if ( v22 )
            {
              v23 = BN_bin2bn((char *)v29 + 20, 20, v14);
              v15 = v28;
              if ( v23 )
              {
                v24 = DSA_SIG_set0(v16, v28, v14);
                v15 = v28;
                if ( v24 )
                {
                  if ( (unsigned int)sub_30740(1, a4, a5, v32, 64)
                    || (v25 = DSA_do_verify(v32, (unsigned int)v8, v16, *((long long *)a1 + 2))) == 0 )
                  {
                    v14 = 0;
                    v15 = 0;
                  }
                  else
                  {
                    v14 = 0;
                    v15 = 0;
                  }
                }
              }
            }
          }
        }
        else
        {
          v14 = 0;
        }
      }
      else
      {
        v14 = 0;
        v15 = 0;
      }
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  v14 = 0;
  v15 = 0;
  v16 = 0;
LABEL_10:
  v27 = v15;
  __explicit_bzero_chk(v32, 64, 64, v12);
  DSA_SIG_free(v16);
  BN_clear_free(v27, v12);
  BN_clear_free(v14, v12);
  sub_BCE0(v11);
  free(ptr);
  if ( v29 )
    sub_3B0D0(v29);
  return 0.0;
}


// Function: ssh_ecdsa_sign @ 0x2c4e0
double ssh_ecdsa_sign(unsigned int *a1, void **a2, size_t *a3, long long a4, long long a5)
{
  int v7; // eax
  unsigned int v8; // eax
  double v9; // xmm0_8
  unsigned int v10; // r12d
  long long *v11; // r15
  long long *v12; // r8
  long long v13; // r14
  double v14; // xmm0_8
  long long *v16; // rax
  long long *v17; // rax
  long long v18; // rcx
  int v19; // eax
  int v20; // eax
  const char *v21; // rax
  int v22; // eax
  int v23; // eax
  size_t v24; // rax
  size_t v25; // rbp
  void *v26; // rax
  const void *v27; // rax
  void *ptr; // [rsp+0h] [rbp-A8h]
  long long *ptrb; // [rsp+0h] [rbp-A8h]
  long long *ptra; // [rsp+0h] [rbp-A8h]
  long long v32; // [rsp+10h] [rbp-98h] BYREF
  long long v33; // [rsp+18h] [rbp-90h] BYREF
  char v34[72]; // [rsp+20h] [rbp-88h] BYREF
  unsigned long long v35; // [rsp+68h] [rbp-40h]

  v35 = __readfsqword(0x28u);
  if ( a3 )
    *a3 = 0;
  if ( a2 )
    *a2 = 0;
  if ( a1 )
  {
    if ( *((long long *)a1 + 4) )
    {
      sub_F440(*a1);
      if ( v7 == 2 )
      {
        v9 = sub_109A0();
        v10 = v8;
        if ( v8 != -1 )
        {
          ptr = (void *)sub_30050(v8);
          if ( ptr )
          {
            if ( (unsigned int)sub_30740(v10, a4, a5, v34, 64) )
            {
              v11 = 0;
              v12 = 0;
              v13 = 0;
            }
            else
            {
              v13 = ECDSA_do_sign(v34, (unsigned int)ptr, *((long long *)a1 + 4), v9);
              if ( v13 )
              {
                v9 = sub_B880();
                v11 = v16;
                if ( v16 )
                {
                  v9 = sub_B880();
                  v12 = v17;
                  if ( !v17 )
                    goto LABEL_12;
                  ptra = v17;
                  ECDSA_SIG_get0(v13, &v32, &v33, v18, v17, v9);
                  v9 = sub_1D610(v11, v32);
                  v12 = ptra;
                  if ( v19 )
                    goto LABEL_12;
                  v9 = sub_1D610(v11, v33);
                  v12 = ptra;
                  if ( v20 )
                    goto LABEL_12;
                  sub_F8B0(a1);
                  v9 = sub_1B800(ptra, v21);
                  v12 = ptra;
                  if ( v22 )
                    goto LABEL_12;
                  v9 = sub_1B840(ptra, (long long)v11);
                  v12 = ptra;
                  if ( v23 )
                    goto LABEL_12;
                  v9 = sub_C3D0((long long)ptra);
                  v12 = ptra;
                  v25 = v24;
                  if ( a2 )
                  {
                    v26 = malloc(v24);
                    v12 = ptra;
                    *a2 = v26;
                    if ( !v26 )
                      goto LABEL_12;
                    v9 = sub_C520((long long)ptra);
                    memcpy(*a2, v27, v25);
                    v12 = ptra;
                  }
                  if ( a3 )
                    *a3 = v25;
                  goto LABEL_12;
                }
                v12 = 0;
              }
              else
              {
                v11 = 0;
                v12 = 0;
              }
            }
LABEL_12:
            ptrb = v12;
            __explicit_bzero_chk(v34, 64, 64, v9);
            sub_BCE0(ptrb);
            v14 = sub_BCE0(v11);
            ECDSA_SIG_free(v13, v14);
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: ssh_ecdsa_verify @ 0x2c810
double ssh_ecdsa_verify(unsigned int *a1, long long a2, unsigned long long a3, long long a4, long long a5)
{
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // r13d
  long long v9; // r14
  long long v10; // rax
  long long *v11; // rbp
  double v12; // xmm0_8
  int v13; // eax
  long long v14; // r15
  double v15; // xmm0_8
  int v17; // eax
  const char *v18; // r12
  const char *v19; // rax
  long long v20; // rax
  int v21; // eax
  int v22; // eax
  long long v23; // rax
  long long v24; // rax
  long long v27; // [rsp+20h] [rbp-A8h] BYREF
  long long v28; // [rsp+28h] [rbp-A0h] BYREF
  void *v29; // [rsp+30h] [rbp-98h] BYREF
  void *ptr; // [rsp+38h] [rbp-90h] BYREF
  char v31[72]; // [rsp+40h] [rbp-88h] BYREF
  unsigned long long v32; // [rsp+88h] [rbp-40h]

  v32 = __readfsqword(0x28u);
  v27 = 0;
  v28 = 0;
  v29 = 0;
  ptr = 0;
  if ( a1 )
  {
    if ( *((long long *)a1 + 4) )
    {
      sub_F440(*a1);
      if ( v6 == 2 )
      {
        if ( a2 )
        {
          if ( a3 )
          {
            sub_109A0();
            v8 = v7;
            if ( v7 != -1 )
            {
              v9 = sub_30050(v7);
              if ( v9 )
              {
                sub_B980(a2, a3);
                v11 = (long long *)v10;
                if ( v10 )
                {
                  v12 = sub_1A6F0(v10, &ptr, 0);
                  if ( !v13 )
                  {
                    v12 = sub_1B8A0((long long)v11, &v29);
                    if ( !v17 )
                    {
                      v18 = (const char *)ptr;
                      v12 = sub_F8B0(a1);
                      if ( strcmp(v19, v18) )
                      {
                        v14 = 0;
                        goto LABEL_11;
                      }
                      v12 = sub_C3D0((long long)v11);
                      if ( v20 )
                      {
                        v14 = 0;
                        goto LABEL_11;
                      }
                      v12 = sub_1D220((long long)v29, &v27);
                      if ( !v21 )
                      {
                        v12 = sub_1D220((long long)v29, &v28);
                        if ( !v22 )
                        {
                          v23 = ECDSA_SIG_new(v12);
                          v14 = v23;
                          if ( v23 )
                          {
                            if ( (unsigned int)ECDSA_SIG_set0(v23, v27, v28) )
                            {
                              v28 = 0;
                              v27 = 0;
                              v12 = sub_C3D0((long long)v29);
                              if ( !v24 && !(unsigned int)sub_30740(v8, a4, a5, v31, 64) )
                                ECDSA_do_verify(v31, (unsigned int)v9, v14, *((long long *)a1 + 4), v12);
                            }
                          }
                          goto LABEL_11;
                        }
                      }
                    }
                  }
                  v14 = 0;
LABEL_11:
                  __explicit_bzero_chk(v31, 64, 64, v12);
                  sub_BCE0(v29);
                  v15 = sub_BCE0(v11);
                  ECDSA_SIG_free(v14, v15);
                  BN_clear_free(v27, v15);
                  BN_clear_free(v28, v15);
                  free(ptr);
                }
              }
            }
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: ssh_ecdsa_sk_verify @ 0x2ce10
double ssh_ecdsa_sk_verify(
        unsigned int *a1,
        long long a2,
        unsigned long long a3,
        long long a4,
        long long a5,
        long long a6,
        long long *a7)
{
  int v8; // eax
  double v9; // xmm0_8
  long long *v10; // rax
  long long *v11; // rbp
  char *v12; // r12
  int v13; // eax
  char *v14; // r14
  int v15; // eax
  int v16; // eax
  long long *v17; // r10
  double v18; // xmm0_8
  int v20; // eax
  long long v21; // rax
  int v22; // eax
  int v23; // eax
  long long v24; // rax
  long long v25; // rax
  long long *v26; // rax
  int v27; // eax
  size_t v28; // rax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  long long v36; // rcx
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  long long *v43; // [rsp+0h] [rbp-118h]
  const char *v45; // [rsp+8h] [rbp-110h]
  int v46; // [rsp+10h] [rbp-108h]
  long long *v47; // [rsp+10h] [rbp-108h]
  long long *v48; // [rsp+18h] [rbp-100h]
  long long v49; // [rsp+20h] [rbp-F8h]
  unsigned char v50; // [rsp+33h] [rbp-E5h] BYREF
  int v51; // [rsp+34h] [rbp-E4h] BYREF
  long long v52; // [rsp+38h] [rbp-E0h] BYREF
  long long v53; // [rsp+40h] [rbp-D8h] BYREF
  void *v54; // [rsp+48h] [rbp-D0h] BYREF
  void *v55; // [rsp+50h] [rbp-C8h] BYREF
  void *v56; // [rsp+58h] [rbp-C0h] BYREF
  char *s1; // [rsp+60h] [rbp-B8h] BYREF
  void *ptr; // [rsp+68h] [rbp-B0h] BYREF
  char v59[32]; // [rsp+70h] [rbp-A8h] BYREF
  char v60[32]; // [rsp+90h] [rbp-88h] BYREF
  char v61[40]; // [rsp+B0h] [rbp-68h] BYREF
  unsigned long long v62; // [rsp+D8h] [rbp-40h]

  v62 = __readfsqword(0x28u);
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  s1 = 0;
  ptr = 0;
  if ( a7 )
    *a7 = 0;
  if ( a1 )
  {
    if ( *((long long *)a1 + 4) )
    {
      sub_F440(*a1);
      if ( v8 == 10 )
      {
        if ( a2 )
        {
          if ( a3 )
          {
            if ( a1[6] == 415 )
            {
              v9 = sub_B980(a2, a3);
              v11 = v10;
              if ( v10 )
              {
                v12 = calloc(1u, 8u);
                if ( !v12 )
                {
                  v17 = 0;
                  v49 = 0;
                  goto LABEL_18;
                }
                v9 = sub_1A6F0((long long)v11, &s1, 0);
                if ( v13 )
                  goto LABEL_17;
                v14 = s1;
                if ( !strcmp(s1, "webauthn-sk-ecdsa-sha2-nistp256@openssh.com") )
                {
                  v46 = 1;
                }
                else
                {
                  v46 = strcmp(v14, "sk-ecdsa-sha2-nistp256@openssh.com");
                  if ( v46 )
                    goto LABEL_17;
                }
                v9 = sub_1B8A0((long long)v11, &v54);
                if ( !v15 )
                {
                  v9 = sub_19E50((long long)v11, &v50);
                  if ( v16 )
                  {
                    v17 = 0;
                    v49 = 0;
                    goto LABEL_18;
                  }
                  v9 = sub_19CD0((long long)v11, &v51);
                  if ( v20
                    || v46
                    && ((v9 = sub_1A6F0((long long)v11, &ptr, 0), v38)
                     || (v9 = sub_1B8A0((long long)v11, &v55), v39)
                     || (v9 = sub_1B8A0((long long)v11, &v56), v40)) )
                  {
LABEL_45:
                    v17 = 0;
                    v49 = 0;
                    goto LABEL_18;
                  }
                  v9 = sub_C3D0((long long)v11);
                  if ( !v21 )
                  {
                    v9 = sub_1D220((long long)v54, &v52);
                    if ( v22 )
                      goto LABEL_45;
                    v9 = sub_1D220((long long)v54, &v53);
                    if ( v23 )
                      goto LABEL_45;
                    v9 = sub_C3D0((long long)v54);
                    if ( !v24 )
                    {
                      v25 = ECDSA_SIG_new(v9);
                      v49 = v25;
                      if ( v25 )
                      {
                        if ( (unsigned int)ECDSA_SIG_set0(v25, v52, v53) )
                        {
                          v53 = 0;
                          v52 = 0;
                          v9 = sub_B880();
                          v17 = v26;
                          if ( !v26 )
                            goto LABEL_18;
                          v48 = v26;
                          if ( v46 )
                          {
                            v27 = sub_2CBD0(a4, a5, ptr, v55, v50, v56, v9, v59, v26);
                            v17 = v48;
                            if ( v27 )
                              goto LABEL_18;
                          }
                          else
                          {
                            v41 = sub_30740(2, a4, a5, v59, 32);
                            v17 = v48;
                            if ( v41 )
                              goto LABEL_18;
                          }
                          v47 = v17;
                          v45 = (const char *)*((long long *)a1 + 12);
                          v28 = strlen(v45);
                          v29 = sub_30740(2, v45, v28, v60, 32);
                          v17 = v47;
                          if ( !v29 )
                          {
                            v9 = sub_1A9D0(v47, v60, 0x20u);
                            v17 = v47;
                            if ( !v30 )
                            {
                              v9 = sub_1B180(v47, v50);
                              v17 = v47;
                              if ( !v31 )
                              {
                                v9 = sub_1AFB0(v47, v51);
                                v17 = v47;
                                if ( !v32 )
                                {
                                  v9 = sub_1AAD0(v47, (long long)v56);
                                  v17 = v47;
                                  if ( !v33 )
                                  {
                                    v9 = sub_1A9D0(v47, v59, 0x20u);
                                    v17 = v47;
                                    if ( !v34 )
                                    {
                                      v35 = sub_30870(2, v47, v61, 32, 0, v60, v9);
                                      v17 = v47;
                                      if ( !v35 )
                                      {
                                        v36 = *((long long *)a1 + 4);
                                        *(int *)v12 = v51;
                                        v12[4] = v50;
                                        v37 = ECDSA_do_verify(v61, 32, v49, v36, v9);
                                        v17 = v47;
                                        if ( v37 == 1 )
                                        {
                                          if ( a7 )
                                          {
                                            *a7 = v12;
                                            v12 = 0;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          goto LABEL_18;
                        }
                        v17 = 0;
                      }
                      else
                      {
                        v17 = 0;
                      }
LABEL_18:
                      v43 = v17;
                      __explicit_bzero_chk(&v50, 1, 1, v9);
                      __explicit_bzero_chk(&v51, 4, 4, v9);
                      __explicit_bzero_chk(v59, 32, 32, v9);
                      __explicit_bzero_chk(v61, 32, 32, v9);
                      __explicit_bzero_chk(v60, 32, 32, v9);
                      sub_19560(v12);
                      sub_BCE0(v55);
                      sub_BCE0(v56);
                      free(ptr);
                      sub_BCE0(v43);
                      sub_BCE0(v54);
                      v18 = sub_BCE0(v11);
                      ECDSA_SIG_free(v49, v18);
                      BN_clear_free(v52, v18);
                      BN_clear_free(v53, v18);
                      free(s1);
                      return 0.0;
                    }
                  }
                  v17 = 0;
                  v49 = 0;
                  goto LABEL_18;
                }
LABEL_17:
                v17 = 0;
                v49 = 0;
                goto LABEL_18;
              }
            }
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: ssh_ed25519_sk_verify @ 0x2d610
double ssh_ed25519_sk_verify(
        unsigned int *a1,
        long long a2,
        unsigned long long a3,
        long long a4,
        long long a5,
        long long a6,
        long long *a7)
{
  int v10; // eax
  long long v11; // rax
  long long *v12; // rbp
  int v13; // eax
  void *v14; // r15
  long long *v15; // r13
  int v17; // eax
  int v18; // eax
  int v19; // eax
  const char *v20; // r15
  const char *v21; // rax
  long long v22; // rax
  const char *v23; // r15
  size_t v24; // rax
  int *v25; // rax
  long long *v26; // rax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  long long v32; // rax
  double v33; // xmm0_8
  size_t v34; // rax
  void *v35; // rax
  char *v36; // r10
  int v37; // eax
  void *v38; // r11
  char *v39; // [rsp+8h] [rbp-D0h]
  void *v40; // [rsp+8h] [rbp-D0h]
  char *v41; // [rsp+10h] [rbp-C8h]
  long long v42; // [rsp+18h] [rbp-C0h]
  char v43; // [rsp+2Bh] [rbp-ADh] BYREF
  int v44; // [rsp+2Ch] [rbp-ACh] BYREF
  void *ptr; // [rsp+30h] [rbp-A8h] BYREF
  const void *v46; // [rsp+38h] [rbp-A0h] BYREF
  size_t v47; // [rsp+40h] [rbp-98h] BYREF
  size_t v48; // [rsp+48h] [rbp-90h] BYREF
  char v49[32]; // [rsp+50h] [rbp-88h] BYREF
  char v50[40]; // [rsp+70h] [rbp-68h] BYREF
  unsigned long long v51; // [rsp+98h] [rbp-40h]

  v51 = __readfsqword(0x28u);
  ptr = 0;
  v48 = 0;
  if ( a7 )
    *a7 = 0;
  if ( a1 )
  {
    sub_F440(*a1);
    if ( v10 == 12 )
    {
      if ( *((long long *)a1 + 6) )
      {
        if ( a2 )
        {
          if ( a3 )
          {
            sub_B980(a2, a3);
            v12 = (long long *)v11;
            if ( v11 )
            {
              sub_1A6F0(v11, &ptr, 0);
              if ( !v13 )
              {
                sub_1A460((long long)v12, &v46, &v47);
                if ( !v17 )
                {
                  sub_19E50((long long)v12, &v43);
                  if ( !v18 )
                  {
                    sub_19CD0((long long)v12, &v44);
                    if ( !v19 )
                    {
                      v20 = (const char *)ptr;
                      sub_F8B0(a1);
                      if ( strcmp(v21, v20) )
                      {
                        v14 = 0;
                        v15 = 0;
                        goto LABEL_11;
                      }
                      sub_C3D0((long long)v12);
                      if ( v22 )
                      {
                        v14 = 0;
                        v15 = 0;
                        goto LABEL_11;
                      }
                      if ( v47 <= 0x40 )
                      {
                        v23 = (const char *)*((long long *)a1 + 12);
                        v24 = strlen(v23);
                        if ( (unsigned int)sub_30740(2, v23, v24, v49, 32)
                          || (unsigned int)sub_30740(2, a4, a5, v50, 32) )
                        {
                          v14 = 0;
                          v15 = 0;
                        }
                        else
                        {
                          v25 = calloc(1u, 8u);
                          v14 = v25;
                          if ( v25 )
                          {
                            *v25 = v44;
                            *((char *)v25 + 4) = v43;
                            sub_B880();
                            v15 = v26;
                            if ( v26 )
                            {
                              sub_1A9D0(v26, v46, v47);
                              if ( !v27 )
                              {
                                sub_1A9D0(v15, v49, 0x20u);
                                if ( !v28 )
                                {
                                  sub_1B180(v15, v43);
                                  if ( !v29 )
                                  {
                                    sub_1AFB0(v15, v44);
                                    if ( !v30 )
                                    {
                                      sub_1A9D0(v15, v50, 0x20u);
                                      if ( !v31 )
                                      {
                                        sub_C520((long long)v15);
                                        v42 = v32;
                                        v33 = sub_C3D0((long long)v15);
                                        v48 = v34;
                                        v39 = (char *)v34;
                                        v35 = malloc(v34);
                                        if ( v35 )
                                        {
                                          v36 = v39;
                                          v40 = v35;
                                          v41 = v36;
                                          v37 = sub_30CF0(v35, &v48, v42, v36, *((long long *)a1 + 6), v33);
                                          v38 = v40;
                                          if ( v37 )
                                          {
                                            sub_203A0(
                                              "ssh-ed25519-sk.c",
                                              "ssh_ed25519_sk_verify",
                                              0x8Eu,
                                              1u,
                                              6,
                                              0,
                                              "crypto_sign_ed25519_open failed: %d",
                                              v37);
                                            v38 = v40;
                                          }
                                          else if ( &v41[-v47] == (char *)v48 && a7 )
                                          {
                                            *a7 = v14;
                                            v14 = 0;
                                          }
                                          sub_3B0D0(v38);
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else
                          {
                            v15 = 0;
                          }
                        }
                        goto LABEL_11;
                      }
                    }
                  }
                }
              }
              v14 = 0;
              v15 = 0;
LABEL_11:
              sub_19560(v14);
              sub_BCE0(v12);
              sub_BCE0(v15);
              free(ptr);
            }
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: rsa_hash_alg_ident @ 0x2daa0
double rsa_hash_alg_ident()
{
  return 0.0;
}


// Function: rsa_hash_alg_nid @ 0x2db50
double rsa_hash_alg_nid()
{
  return 0.0;
}


// Function: rsa_hash_id_from_ident @ 0x2dbf0
double rsa_hash_id_from_ident(char *s1)
{
  if ( strcmp(s1, "ssh-rsa") && strcmp(s1, "rsa-sha2-256") )
    strcmp(s1, "rsa-sha2-512");
  return 0.0;
}


// Function: rsa_hash_id_from_keyname @ 0x2dcd0
double rsa_hash_id_from_keyname(char *s1)
{
  int v1; // eax

  sub_2DBF0(s1);
  if ( v1 != -1 )
    return 0.0;
  if ( strcmp(s1, "ssh-rsa-cert-v01@openssh.com") )
  {
    if ( strcmp(s1, "rsa-sha2-256-cert-v01@openssh.com") )
      strcmp(s1, "rsa-sha2-512-cert-v01@openssh.com");
    return 0.0;
  }
  return 0.0;
}


// Function: openssh_RSA_verify @ 0x2e0b0
double openssh_RSA_verify(long long a1, long long a2, long long a3, long long a4, long long a5, long long a6, double a7)
{
  long long v12; // rax
  char *v13; // r10
  size_t v14; // rbx
  char *v15; // rax
  int v16; // eax
  long long v17; // rbp
  char *v18; // rdi
  long long v19; // [rsp+10h] [rbp-68h]
  char *v20; // [rsp+10h] [rbp-68h]
  char *v21; // [rsp+18h] [rbp-60h]
  long long v22; // [rsp+18h] [rbp-60h]
  long long v23; // [rsp+28h] [rbp-50h] BYREF
  long long v24[9]; // [rsp+30h] [rbp-48h] BYREF

  v24[1] = __readfsqword(0x28u);
  v23 = 0;
  v24[0] = 0;
  if ( !(unsigned int)sub_2DE60(a1, v24, &v23) )
  {
    v12 = sub_30050((unsigned int)a1);
    if ( v12 == a3 )
    {
      v19 = v12;
      v14 = (int)RSA_size(a6);
      if ( v14 - 1 > 0x7FF || a5 - 1 >= v14 )
      {
        v13 = 0;
      }
      else
      {
        v15 = (char *)malloc(v14);
        v13 = v15;
        if ( v15 )
        {
          v21 = v15;
          v16 = RSA_public_decrypt((unsigned int)a5, a4, v15, a6, 1);
          v13 = v21;
          if ( v16 >= 0 )
          {
            v17 = v23;
            if ( v16 == v23 + v19 )
            {
              v18 = v21;
              v22 = v19;
              v20 = v13;
              sub_3C1C0(v18, v24[0], v23, a7);
              sub_3C1C0(&v20[v17], a2, v22, a7);
              v13 = v20;
            }
          }
        }
      }
    }
    else
    {
      v13 = 0;
    }
    sub_3B0D0(v13);
  }
  return 0.0;
}


// Function: ssh_rsa_complete_crt_parameters @ 0x2e2e0
double ssh_rsa_complete_crt_parameters(unsigned int *a1, long long a2)
{
  double v2; // xmm0_8
  int v3; // eax
  long long v4; // r14
  long long v5; // rbp
  long long v6; // r15
  long long v7; // r13
  long long v8; // rax
  long long v10; // rax
  long long v11; // rbx
  int v12; // eax
  long long v13; // rcx
  long long v14; // [rsp+0h] [rbp-68h]
  long long v15; // [rsp+8h] [rbp-60h]
  long long v16; // [rsp+10h] [rbp-58h] BYREF
  long long v17; // [rsp+18h] [rbp-50h] BYREF
  long long v18[9]; // [rsp+20h] [rbp-48h] BYREF

  v18[1] = __readfsqword(0x28u);
  if ( a1 )
  {
    if ( *((long long *)a1 + 1) )
    {
      v2 = sub_F440(*a1);
      if ( !v3 )
      {
        RSA_get0_key(*((long long *)a1 + 1), 0, 0, v18);
        RSA_get0_factors(*((long long *)a1 + 1), &v16, &v17, v2);
        v4 = BN_CTX_new();
        if ( v4 )
        {
          v5 = BN_new(v2);
          if ( v5 )
          {
            v6 = BN_new(v2);
            if ( v6 )
            {
              v14 = BN_new(v2);
              if ( v14 )
              {
                v7 = BN_dup(v18[0], v2);
                if ( v7 )
                {
                  v15 = BN_dup(a2, v2);
                  if ( v15 )
                  {
                    BN_set_flags(v5, 4);
                    BN_set_flags(v7, 4);
                    v8 = BN_value_one();
                    if ( (unsigned int)BN_sub(v5, v17, v8) )
                    {
                      if ( (unsigned int)BN_div(0, v6, v7, v5, v4) )
                      {
                        v10 = BN_value_one();
                        if ( (unsigned int)BN_sub(v5, v16, v10) )
                        {
                          if ( (unsigned int)BN_div(0, v14, v7, v5, v4) )
                          {
                            v11 = v14;
                            v12 = RSA_set0_crt_params(*((long long *)a1 + 1), v14, v6, v15);
                            v13 = v15;
                            if ( v12 )
                            {
                              v13 = 0;
                              v11 = 0;
                              v6 = 0;
                            }
                            v15 = v13;
                            v14 = v11;
                          }
                        }
                      }
                    }
                  }
                }
                else
                {
                  v15 = 0;
                }
                BN_clear_free(v5, v2);
                BN_clear_free(v7, v2);
                BN_clear_free(v14, v2);
                BN_clear_free(v6, v2);
                BN_clear_free(v15, v2);
                BN_CTX_free(v4);
              }
            }
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: ssh_rsa_sign @ 0x2e5c0
double ssh_rsa_sign(unsigned int *a1, void **a2, long long *a3, long long a4, long long a5, char *a6)
{
  unsigned int v8; // r13d
  double v9; // xmm0_8
  int v10; // eax
  size_t v11; // rbp
  long long *v12; // rbx
  char *v13; // r14
  unsigned int v15; // eax
  long long *v16; // rax
  const char *v17; // rax
  int v18; // eax
  int v19; // eax
  unsigned int v20; // eax
  void *v21; // rax
  size_t v22; // r13
  const void *v23; // rax
  unsigned int v24; // eax
  size_t v25; // rbx
  unsigned int v27; // [rsp+14h] [rbp-A4h]
  int n[3]; // [rsp+24h] [rbp-94h] BYREF
  char v30[72]; // [rsp+30h] [rbp-88h] BYREF
  unsigned long long v31; // [rsp+78h] [rbp-40h]

  v31 = __readfsqword(0x28u);
  if ( a3 )
    *a3 = 0;
  if ( a2 )
    *a2 = 0;
  if ( a6 && strlen(a6) )
  {
    sub_2DCD0(a6);
    v8 = v24;
    if ( !a1 || !*((long long *)a1 + 1) || v24 == -1 )
      return 0.0;
  }
  else
  {
    if ( !a1 || !*((long long *)a1 + 1) )
      return 0.0;
    v8 = 1;
  }
  v9 = sub_F440(*a1);
  if ( !v10 )
  {
    RSA_get0_key(*((long long *)a1 + 1), &n[1], 0, 0);
    if ( (int)BN_num_bits(*(long long *)&n[1]) > 1023 )
    {
      v11 = (int)RSA_size(*((long long *)a1 + 1));
      if ( v11 - 1 <= 0x7FF )
      {
        v27 = sub_30050(v8);
        if ( v27 )
        {
          if ( (unsigned int)sub_30740(v8, a4, a5, v30, 64) )
          {
            v12 = 0;
            v13 = 0;
          }
          else
          {
            v13 = (char *)malloc(v11);
            if ( !v13 )
            {
              v12 = 0;
              goto LABEL_16;
            }
            v9 = sub_2DB50();
            if ( (unsigned int)RSA_sign(v15, v30, v27, v13, n, *((long long *)a1 + 1), v9) == 1 )
            {
              if ( n[0] < v11 )
              {
                v25 = v11 - n[0];
                memmove(&v13[v25], v13, n[0]);
                __explicit_bzero_chk(v13, v25, -1, v9);
              }
              else if ( n[0] > v11 )
              {
                v12 = 0;
                goto LABEL_16;
              }
              v9 = sub_B880();
              v12 = v16;
              if ( !v16 )
                goto LABEL_16;
              sub_2DAA0();
              v9 = sub_1B800(v12, v17);
              if ( v18 )
                goto LABEL_16;
              v9 = sub_1B6C0(v12, v13, v11);
              if ( v19 )
                goto LABEL_16;
              v9 = sub_C3D0((long long)v12);
              n[0] = v20;
              if ( a2 )
              {
                v21 = malloc(v20);
                *a2 = v21;
                if ( !v21 )
                  goto LABEL_16;
                v22 = n[0];
                v9 = sub_C520((long long)v12);
                memcpy(*a2, v23, v22);
              }
              if ( a3 )
                *a3 = n[0];
              goto LABEL_16;
            }
            v12 = 0;
          }
LABEL_16:
          __explicit_bzero_chk(v30, 64, 64, v9);
          sub_3B0D0(v13);
          sub_BCE0(v12);
        }
      }
    }
  }
  return 0.0;
}


// Function: ssh_rsa_verify @ 0x2e980
double ssh_rsa_verify(unsigned int *a1, long long a2, unsigned long long a3, long long a4, long long a5, char *a6)
{
  int v10; // eax
  long long v11; // rax
  long long *v12; // rbp
  int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // r15d
  int v16; // eax
  void *v17; // rdi
  int v18; // eax
  double v19; // xmm0_8
  double v21; // xmm0_8
  long long v22; // rax
  int v23; // eax
  size_t v24; // r12
  char *v25; // rax
  long long v26; // rax
  size_t v28; // [rsp+10h] [rbp-B8h]
  long long v29; // [rsp+10h] [rbp-B8h]
  void *v30; // [rsp+18h] [rbp-B0h]
  long long v31; // [rsp+20h] [rbp-A8h] BYREF
  void *ptr; // [rsp+28h] [rbp-A0h] BYREF
  size_t n; // [rsp+30h] [rbp-98h] BYREF
  void *v34; // [rsp+38h] [rbp-90h] BYREF
  char v35[72]; // [rsp+40h] [rbp-88h] BYREF
  unsigned long long v36; // [rsp+88h] [rbp-40h]

  v36 = __readfsqword(0x28u);
  ptr = 0;
  n = 0;
  v34 = 0;
  if ( a1 )
  {
    if ( *((long long *)a1 + 1) )
    {
      sub_F440(*a1);
      if ( !v10 )
      {
        if ( a2 )
        {
          if ( a3 )
          {
            RSA_get0_key(*((long long *)a1 + 1), &v31, 0, 0);
            if ( (int)BN_num_bits(v31) > 1023 )
            {
              sub_B980(a2, a3);
              v12 = (long long *)v11;
              if ( v11 )
              {
                sub_1A6F0(v11, &ptr, 0);
                if ( !v13 )
                {
                  sub_2DBF0((char *)ptr);
                  v15 = v14;
                  if ( v14 == -1 )
                  {
                    v17 = v34;
                    goto LABEL_17;
                  }
                  if ( a6 && strcmp(a6, "ssh-rsa-cert-v01@openssh.com") )
                  {
                    sub_2DCD0(a6);
                    if ( v16 == -1 )
                    {
                      v17 = v34;
                      goto LABEL_17;
                    }
                    if ( v15 != v16 )
                    {
                      v17 = v34;
                      goto LABEL_17;
                    }
                  }
                  sub_1A590((long long)v12, &v34, &n);
                  if ( !v18 )
                  {
                    v21 = sub_C3D0((long long)v12);
                    if ( v22 )
                    {
                      v17 = v34;
                    }
                    else
                    {
                      v23 = RSA_size(*((long long *)a1 + 1));
                      v24 = v23;
                      if ( n <= v23 )
                      {
                        v28 = n;
                        if ( n < v23 )
                        {
                          v30 = v34;
                          v25 = (char *)realloc(v34, v23);
                          v17 = v30;
                          v34 = v25;
                          if ( !v25 )
                          {
                            v34 = v30;
                            goto LABEL_17;
                          }
                          memmove(&v25[v24 - v28], v25, n);
                          __explicit_bzero_chk(v34, v24 - v28, -1, v21);
                          n = v24;
                        }
                        v26 = sub_30050(v15);
                        if ( v26 )
                        {
                          v29 = v26;
                          if ( !(unsigned int)sub_30740(v15, a4, a5, v35, 64) )
                            sub_2E0B0(v15, (long long)v35, v29, (long long)v34, n, *((long long *)a1 + 1), v21);
                          v17 = v34;
                        }
                        else
                        {
                          v17 = v34;
                        }
                        goto LABEL_17;
                      }
                      v17 = v34;
                    }
LABEL_17:
                    sub_3B0D0(v17);
                    free(ptr);
                    v19 = sub_BCE0(v12);
                    __explicit_bzero_chk(v35, 64, 64, v19);
                    return 0.0;
                  }
                }
                v17 = v34;
                goto LABEL_17;
              }
            }
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: ssh_msg_send @ 0x2eda0
double ssh_msg_send(unsigned int a1, unsigned char a2, long long a3)
{
  unsigned int v4; // eax
  unsigned int v5; // ebx
  double v6; // xmm0_8
  double v7; // xmm0_8
  long long v8; // rax
  int *v10; // rax
  int *v11; // rax
  int v12; // [rsp+13h] [rbp-45h] BYREF
  unsigned char v13; // [rsp+17h] [rbp-41h]
  unsigned long long v14; // [rsp+18h] [rbp-40h]

  v14 = __readfsqword(0x28u);
  sub_C3D0(a3);
  v5 = v4;
  sub_203A0("msg.c", "ssh_msg_send", 0x32u, 1u, 7, 0, "type %u", a2);
  v6 = sub_26A10(&v12, v5 + 1);
  v13 = a2;
  if ( sub_32EF0(&write, a1, &v12, 5, v6) == 5 )
  {
    v7 = sub_C7C0(a3);
    if ( sub_32EF0(&write, a1, v8, v5, v7) != v5 )
    {
      v11 = __errno_location();
      strerror(*v11);
      sub_203A0("msg.c", "ssh_msg_send", 0x3Bu, 1u, 2, 0, "write: %s");
    }
  }
  else
  {
    v10 = __errno_location();
    strerror(*v10);
    sub_203A0("msg.c", "ssh_msg_send", 0x37u, 1u, 2, 0, "write: %s");
  }
  return 0.0;
}


// Function: ssh_msg_recv @ 0x2ef90
double ssh_msg_recv(unsigned int a1, long long *a2)
{
  double v2; // xmm0_8
  unsigned int v3; // eax
  unsigned long long v4; // rbx
  double v5; // xmm0_8
  unsigned long long v6; // rax
  unsigned int v7; // eax
  int v9; // edi
  char *v10; // rax
  char *v11; // r9
  unsigned int v12; // edx
  int *v13; // rax
  const char *v14; // [rsp-8h] [rbp-68h]
  long long v15; // [rsp+10h] [rbp-50h] BYREF
  char v16[4]; // [rsp+1Ch] [rbp-44h] BYREF
  unsigned long long v17; // [rsp+20h] [rbp-40h]

  v17 = __readfsqword(0x28u);
  v2 = sub_203A0("msg.c", "ssh_msg_recv", 0x48u, 0, 7, 0, "ssh_msg_recv entering");
  if ( sub_32EF0(&read, a1, v16, 4, v2) == 4 )
  {
    sub_267D0();
    v4 = v3;
    v5 = sub_BF80();
    if ( v4 > v6 )
    {
      v11 = 0;
      v14 = "read: bad msg_len %u";
      v12 = 81;
    }
    else
    {
      sub_BE60((long long)a2);
      v5 = sub_CB20(a2, v4, &v15);
      if ( v7 )
      {
        v11 = sub_B050(v7);
        v12 = 86;
        v14 = "reserve";
      }
      else
      {
        if ( v4 == sub_32EF0(&read, a1, v15, v4, v5) )
          return 0.0;
        v13 = __errno_location();
        strerror(*v13);
        v11 = 0;
        v12 = 90;
        v14 = "read: %s";
      }
    }
    sub_203A0("msg.c", "ssh_msg_recv", v12, 1u, 2, v11, v14, v5);
    return 0.0;
  }
  v9 = *__errno_location();
  if ( v9 != 32 )
  {
    v10 = strerror(v9);
    sub_203A0("msg.c", "ssh_msg_recv", 0x4Cu, 1u, 2, 0, "read header: %s", v10);
  }
  return 0.0;
}


// Function: chachapoly_free @ 0x2f1f0
double chachapoly_free(long long *ptr, long long a2, long long a3, long long a4)
{
  long long v4; // rdx
  long long v5; // rcx
  double result; // xmm0_8

  if ( !ptr )
    return 0.0;
  EVP_CIPHER_CTX_free(*ptr, a2, a3, a4);
  EVP_CIPHER_CTX_free(ptr[1], a2, v4, v5);
  sub_3B0D0(ptr);
  return result;
}


// Function: chachapoly_new @ 0x2f2a0
double chachapoly_new(long long a1, int a2)
{
  long long v2; // rsi
  long long *v3; // r12
  long long v4; // rax
  long long v5; // rdx
  long long v6; // rcx
  long long v7; // rax

  if ( a2 == 64 )
  {
    v2 = 16;
    v3 = calloc(1u, 0x10u);
    if ( v3 )
    {
      v4 = EVP_CIPHER_CTX_new();
      *v3 = v4;
      if ( !v4
        || (v7 = EVP_CIPHER_CTX_new(), (v3[1] = v7) == 0)
        || (v2 = EVP_chacha20(), !(unsigned int)EVP_CipherInit(*v3, v2, a1, 0, 1))
        || (v2 = EVP_chacha20(), !(unsigned int)EVP_CipherInit(v3[1], v2, a1 + 32, 0, 1))
        || (unsigned int)EVP_CIPHER_CTX_get_iv_length(v3[1]) != 16 )
      {
        sub_2F1F0(v3, v2, v5, v6);
      }
    }
  }
  return 0.0;
}


// Function: chachapoly_crypt @ 0x2f3e0
double chachapoly_crypt(
        long long *a1,
        unsigned int a2,
        long long a3,
        long long a4,
        unsigned int a5,
        unsigned int a6,
        int a7,
        int a8)
{
  double v8; // xmm0_8
  long long v12; // rdi
  long long v13; // rdi
  long long v17; // [rsp+18h] [rbp-88h] BYREF
  int v18; // [rsp+20h] [rbp-80h]
  unsigned int v19; // [rsp+24h] [rbp-7Ch]
  char v20[16]; // [rsp+28h] [rbp-78h] BYREF
  _OWORD v21[2]; // [rsp+38h] [rbp-68h] BYREF
  unsigned long long v22; // [rsp+60h] [rbp-40h]

  v8 = 0.0;
  v12 = *a1;
  v22 = __readfsqword(0x28u);
  v19 = _byteswap_ulong(a2);
  v17 = 0;
  v18 = 0;
  memset(v21, 0, sizeof(v21));
  if ( (unsigned int)EVP_CipherInit(v12, 0, 0, &v17, 1) )
  {
    if ( (int)EVP_Cipher(*a1, v21, v21, 32) >= 0 )
    {
      if ( a8
        || (v8 = sub_331F0(v20, a4, a6 + a5, v21), !(unsigned int)sub_3C1C0(v20, a4 + a5 + (unsigned long long)a6, 16, v8)) )
      {
        if ( !a6 || (unsigned int)EVP_CipherInit(a1[1], 0, 0, &v17, 1) && (int)EVP_Cipher(a1[1], a3, a4, a6) >= 0 )
        {
          v13 = *a1;
          LOBYTE(v17) = 1;
          if ( (unsigned int)EVP_CipherInit(v13, 0, 0, &v17, 1) && (int)EVP_Cipher(*a1, a3 + a6, a6 + a4, a5) >= 0 && a8 )
            v8 = sub_331F0(a3 + a6 + (unsigned long long)a5, a3, a6 + a5, v21);
        }
      }
    }
  }
  __explicit_bzero_chk(v20, 16, 16, v8);
  __explicit_bzero_chk(&v17, 16, 16, v8);
  __explicit_bzero_chk(v21, 32, 32, v8);
  return 0.0;
}


// Function: chachapoly_get_length @ 0x2f6d0
double chachapoly_get_length(long long a1, int *a2, unsigned int a3, long long a4, unsigned int a5)
{
  long long v6; // rdi
  unsigned int v9; // [rsp+Ch] [rbp-3Ch] BYREF
  long long v10; // [rsp+10h] [rbp-38h] BYREF
  int v11; // [rsp+18h] [rbp-30h]
  unsigned int v12; // [rsp+1Ch] [rbp-2Ch]
  unsigned long long v13; // [rsp+28h] [rbp-20h]

  v13 = __readfsqword(0x28u);
  if ( a5 > 3 )
  {
    v6 = *(long long *)(a1 + 8);
    v12 = _byteswap_ulong(a3);
    v10 = 0;
    v11 = 0;
    if ( (unsigned int)EVP_CipherInit(v6, 0, 0, &v10, 0) )
    {
      if ( (int)EVP_Cipher(*(long long *)(a1 + 8), &v9, a4, 4) >= 0 )
        *a2 = _byteswap_ulong(v9);
    }
  }
  return 0.0;
}


// Function: ssh_ed25519_sign @ 0x2f820
double ssh_ed25519_sign(unsigned int *a1, void **a2, size_t *a3, long long a4, unsigned long long a5)
{
  double v7; // xmm0_8
  int v8; // eax
  void *v9; // rax
  void *v10; // rbp
  long long *v11; // r8
  long long *v13; // rax
  int v14; // eax
  int v15; // eax
  size_t v16; // rax
  size_t v17; // rbx
  void *v18; // rax
  const void *v19; // rax
  long long *v21; // [rsp+8h] [rbp-50h]
  long long v22[9]; // [rsp+10h] [rbp-48h] BYREF

  v22[1] = __readfsqword(0x28u);
  if ( a3 )
    *a3 = 0;
  if ( a2 )
    *a2 = 0;
  if ( a1 )
  {
    v7 = sub_F440(*a1);
    if ( v8 == 3 )
    {
      if ( *((long long *)a1 + 5) )
      {
        if ( a5 <= 0x7FFFFFBE )
        {
          v22[0] = a5 + 64;
          v9 = malloc(a5 + 64);
          v10 = v9;
          if ( v9 )
          {
            if ( (unsigned int)sub_30A90(v9, v22, a4, a5, *((long long *)a1 + 5), v7) || v22[0] <= a5 )
            {
              v11 = 0;
LABEL_13:
              sub_BCE0(v11);
              sub_3B0D0(v10);
              return 0.0;
            }
            sub_B880();
            v11 = v13;
            if ( !v13 )
              goto LABEL_13;
            v21 = v13;
            sub_1B800(v13, "ssh-ed25519");
            v11 = v21;
            if ( v14 )
              goto LABEL_13;
            sub_1B6C0(v21, v10, v22[0] - a5);
            v11 = v21;
            if ( v15 )
              goto LABEL_13;
            sub_C3D0((long long)v21);
            v11 = v21;
            v17 = v16;
            if ( a2 )
            {
              v18 = malloc(v16);
              v11 = v21;
              *a2 = v18;
              if ( !v18 )
                goto LABEL_13;
              sub_C520((long long)v21);
              memcpy(*a2, v19, v17);
              v11 = v21;
            }
            if ( a3 )
              *a3 = v17;
            goto LABEL_13;
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: ssh_ed25519_verify @ 0x2fa90
double ssh_ed25519_verify(unsigned int *a1, long long a2, unsigned long long a3, const void *a4, unsigned long long a5)
{
  int v8; // eax
  long long v9; // rax
  long long *v10; // r14
  int v11; // eax
  int v13; // eax
  double v14; // xmm0_8
  long long v15; // rax
  size_t v16; // r15
  size_t v17; // r12
  int v18; // eax
  void *v19; // r11
  void *v20; // [rsp+0h] [rbp-78h]
  void *dest; // [rsp+8h] [rbp-70h]
  char *desta; // [rsp+8h] [rbp-70h]
  void *ptr; // [rsp+18h] [rbp-60h] BYREF
  void *src; // [rsp+20h] [rbp-58h] BYREF
  size_t n; // [rsp+28h] [rbp-50h] BYREF
  size_t size[9]; // [rsp+30h] [rbp-48h] BYREF

  size[1] = __readfsqword(0x28u);
  ptr = 0;
  size[0] = 0;
  if ( a1 )
  {
    sub_F440(*a1);
    if ( v8 == 3 )
    {
      if ( *((long long *)a1 + 6) )
      {
        if ( a2 != 0 && a5 <= 0x7FFFFFBE )
        {
          if ( a3 )
          {
            sub_B980(a2, a3);
            v10 = (long long *)v9;
            if ( v9 )
            {
              sub_1A6F0(v9, &ptr, 0);
              if ( !v11 )
              {
                sub_1A460((long long)v10, &src, &n);
                if ( !v13 && !strcmp("ssh-ed25519", (const char *)ptr) )
                {
                  v14 = sub_C3D0((long long)v10);
                  if ( !v15 && n <= 0x40 )
                  {
                    v16 = n + a5;
                    size[0] = n + a5;
                    dest = malloc(n + a5);
                    if ( dest )
                    {
                      v20 = malloc(size[0]);
                      if ( v20 )
                      {
                        v17 = n;
                        desta = (char *)memcpy(dest, src, n);
                        memcpy(&desta[v17], a4, a5);
                        v18 = sub_30CF0(v20, size, desta, v16, *((long long *)a1 + 6), v14);
                        v19 = desta;
                        if ( v18 )
                        {
                          sub_203A0(
                            "ssh-ed25519.c",
                            "ssh_ed25519_verify",
                            0x8Fu,
                            1u,
                            6,
                            0,
                            "crypto_sign_ed25519_open failed: %d",
                            v18);
                          v19 = desta;
                        }
                        sub_3B0D0(v19);
                        sub_3B0D0(v20);
                      }
                      else
                      {
                        sub_3B0D0(dest);
                      }
                    }
                  }
                }
              }
              sub_BCE0(v10);
              free(ptr);
            }
          }
        }
      }
    }
  }
  return 0.0;
}


// Function: ssh_digest_by_alg @ 0x2fdb0
double ssh_digest_by_alg()
{
  return 0.0;
}


// Function: ssh_digest_alg_by_name @ 0x2fef0
double ssh_digest_alg_by_name(char *s1)
{
  const char *v1; // rsi
  char *i; // rbx
  int v3; // r12d

  v1 = "MD5";
  for ( i = (char *)&unk_67560; strcasecmp(s1, v1); v1 = (const char *)*((long long *)i + 1) )
  {
    v3 = *((int *)i + 8);
    i += 32;
    if ( v3 == -1 )
      break;
  }
  return 0.0;
}


// Function: ssh_digest_alg_name @ 0x2ffc0
double ssh_digest_alg_name()
{
  sub_2FDB0();
  return 0.0;
}


// Function: ssh_digest_bytes @ 0x30050
double ssh_digest_bytes()
{
  sub_2FDB0();
  return 0.0;
}


// Function: ssh_digest_blocksize @ 0x300f0
double ssh_digest_blocksize(long long a1)
{
  long long v1; // rax

  v1 = EVP_MD_CTX_get0_md(*(long long *)(a1 + 8));
  EVP_MD_get_block_size(v1);
  return 0.0;
}


// Function: ssh_digest_update @ 0x302d0
double ssh_digest_update(long long a1)
{
  EVP_DigestUpdate(*(long long *)(a1 + 8));
  return 0.0;
}


// Function: ssh_digest_update_buffer @ 0x30380
double ssh_digest_update_buffer(long long a1, long long a2)
{
  sub_C3D0(a2);
  sub_C520(a2);
  return sub_302D0(a1);
}


// Function: ssh_digest_final @ 0x303c0
double ssh_digest_final(long long a1, long long a2, unsigned long long a3)
{
  long long v4; // rax
  double v5; // xmm0_8
  long long v6; // rbp
  int v8; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v9; // [rsp+8h] [rbp-30h]

  v9 = __readfsqword(0x28u);
  v5 = sub_2FDB0();
  v8 = a3;
  if ( v4 )
  {
    v6 = v4;
    if ( !HIDWORD(a3)
      && *(long long *)(v4 + 16) <= a3
      && (unsigned int)EVP_DigestFinal_ex(*(long long *)(a1 + 8), a2, &v8, v5) == 1 )
    {
      sub_3DAE0(v8 != *(long long *)(v6 + 16));
    }
  }
  return 0.0;
}


// Function: ssh_digest_free @ 0x30500
double ssh_digest_free(long long *ptr)
{
  double result; // xmm0_8

  if ( !ptr )
    return 0.0;
  EVP_MD_CTX_free(ptr[1]);
  sub_3B0D0(ptr);
  return result;
}


// Function: ssh_digest_start @ 0x305b0
double ssh_digest_start(int a1)
{
  long long v1; // rax
  double v2; // xmm0_8
  long long v3; // rbp
  int *v4; // rax
  long long *v5; // r12
  long long v6; // rax
  long long v7; // rax

  v2 = sub_2FDB0();
  if ( v1 )
  {
    v3 = v1;
    v4 = calloc(1u, 0x10u);
    v5 = v4;
    if ( v4 )
    {
      *v4 = a1;
      v6 = EVP_MD_CTX_new(v2);
      v5[1] = v6;
      if ( !v6 )
      {
        free(v5);
        return 0.0;
      }
      v7 = (*(long long (**)(void))(v3 + 24))();
      if ( (unsigned int)EVP_DigestInit_ex(v5[1], v7, 0) == 1 )
        return 0.0;
      sub_30500(v5);
    }
  }
  return 0.0;
}


// Function: ssh_digest_memory @ 0x30740
double ssh_digest_memory(long long a1, long long a2, long long a3, long long a4, unsigned long long a5)
{
  long long v8; // rax
  double v9; // xmm0_8
  long long v10; // rax
  int v12; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v13; // [rsp+8h] [rbp-30h]

  v13 = __readfsqword(0x28u);
  v9 = sub_2FDB0();
  if ( v8 && !HIDWORD(a5) && *(long long *)(v8 + 16) <= a5 )
  {
    v12 = a5;
    v10 = (*(long long (**)(long long, long long, double))(v8 + 24))(a1, 0, v9);
    EVP_Digest(a2, a3, a4, &v12, v10, 0);
  }
  return 0.0;
}


// Function: ssh_digest_buffer @ 0x30870
double ssh_digest_buffer(unsigned int a1, long long a2, long long a3, unsigned long long a4)
{
  long long v6; // rax
  long long v7; // r13
  long long v8; // rax

  sub_C3D0(a2);
  v7 = v6;
  sub_C520(a2);
  return sub_30740(a1, v8, v7, a3, a4);
}


// Function: get_hram @ 0x308c0
long long get_hram(long long a1, long long a2, long long a3, long long a4, unsigned long long a5)
{
  long long i; // rax

  for ( i = 0; i != 32; ++i )
    *(char *)(a4 + i) = *(char *)(a2 + i);
  do
  {
    *(char *)(a4 + i) = *(char *)(a3 + i - 32);
    ++i;
  }
  while ( i != 64 );
  if ( a5 > 0x40 )
  {
    do
    {
      *(char *)(a4 + i) = *(char *)(a2 + i);
      ++i;
    }
    while ( a5 != i );
  }
  return sub_310D0(a1, a4, a5);
}


// Function: crypto_sign_ed25519_keypair @ 0x30930
double crypto_sign_ed25519_keypair(long long a1, void *a2)
{
  long long i; // rax
  char v4[128]; // [rsp+0h] [rbp-2F8h] BYREF
  char v5[512]; // [rsp+80h] [rbp-278h] BYREF
  char v6[31]; // [rsp+280h] [rbp-78h] BYREF
  char v7; // [rsp+29Fh] [rbp-59h]
  unsigned long long v8; // [rsp+2C8h] [rbp-30h]

  v8 = __readfsqword(0x28u);
  sub_38B20(a2);
  sub_310D0(v6, a2, 32);
  v6[0] &= 0xF8u;
  v7 = v7 & 0x3F | 0x40;
  sub_33B20(v4, v6);
  sub_35EB0(v5, v4);
  sub_358B0(a1, v5);
  for ( i = 0; i != 32; ++i )
    *((char *)a2 + i + 32) = *(char *)(a1 + i);
  return 0.0;
}


// Function: crypto_sign_ed25519 @ 0x30a90
double crypto_sign_ed25519(long long a1, unsigned long long *a2, long long a3, long long a4, long long a5)
{
  unsigned long long v7; // r14
  char v9; // al
  long long v10; // rax
  long long i; // rax
  long long j; // rax
  long long k; // rax
  char v15[128]; // [rsp+10h] [rbp-4C8h] BYREF
  char v16[128]; // [rsp+90h] [rbp-448h] BYREF
  char v17[128]; // [rsp+110h] [rbp-3C8h] BYREF
  char v18[512]; // [rsp+190h] [rbp-348h] BYREF
  char v19[32]; // [rsp+390h] [rbp-148h] BYREF
  char v20[32]; // [rsp+3B0h] [rbp-128h] BYREF
  char v21[31]; // [rsp+3D0h] [rbp-108h] BYREF
  char v22; // [rsp+3EFh] [rbp-E9h]
  char v23[32]; // [rsp+3F0h] [rbp-E8h]
  char v24[64]; // [rsp+410h] [rbp-C8h] BYREF
  char v25[72]; // [rsp+450h] [rbp-88h] BYREF
  unsigned long long v26; // [rsp+498h] [rbp-40h]

  v7 = a4 + 64;
  v26 = __readfsqword(0x28u);
  sub_310D0(v21, a5, 32);
  v21[0] &= 0xF8u;
  v9 = v22 & 0x7F;
  *a2 = v7;
  v22 = v9 | 0x40;
  if ( a4 )
  {
    v10 = 0;
    do
    {
      *(char *)(a1 + v10 + 64) = *(char *)(a3 + v10);
      ++v10;
    }
    while ( a4 != v10 );
  }
  for ( i = 0; i != 32; ++i )
    *(char *)(a1 + i + 32) = v23[i];
  sub_310D0(v24, a1 + 32, a4 + 32);
  sub_33CD0(v15, v24);
  sub_35EB0(v18, v15);
  sub_358B0(v19, v18);
  for ( j = 0; j != 32; ++j )
    *(char *)(a1 + j) = v19[j];
  sub_308C0((long long)v25, a1, a5 + 32, a1, v7);
  sub_33CD0(v16, v25);
  sub_33B20(v17, v21);
  sub_343C0(v16, v16, v17);
  sub_342B0(v16, v16, v15);
  sub_33E80(v20, v16);
  for ( k = 0; k != 32; ++k )
    *(char *)(a1 + k + 32) = v20[k];
  return 0.0;
}


// Function: crypto_sign_ed25519_open @ 0x30cf0
double crypto_sign_ed25519_open(long long a1, unsigned long long *a2, long long a3, unsigned long long a4, long long a5)
{
  int v8; // eax
  unsigned long long v9; // r8
  unsigned int v10; // edx
  long long v11; // rcx
  unsigned int v13; // ecx
  long long v14; // rdx
  char v15[128]; // [rsp+10h] [rbp-5A8h] BYREF
  char v16[128]; // [rsp+90h] [rbp-528h] BYREF
  char v17[512]; // [rsp+110h] [rbp-4A8h] BYREF
  char v18[512]; // [rsp+310h] [rbp-2A8h] BYREF
  char v19[32]; // [rsp+510h] [rbp-A8h] BYREF
  char v20[72]; // [rsp+530h] [rbp-88h] BYREF
  unsigned long long v21; // [rsp+578h] [rbp-40h]

  v21 = __readfsqword(0x28u);
  *a2 = -1;
  if ( a4 > 0x3F && !(unsigned int)sub_355F0(v17, a5) )
  {
    sub_308C0((long long)v20, a3, a5, a1, a4);
    sub_33CD0(v15, v20);
    sub_33B20(v16, a3 + 32);
    sub_35AB0(v18, v17, v15, &unk_5B8C0, v16);
    sub_358B0(v19, v18);
    v8 = sub_30F00(a3, v19);
    v9 = a4 - 64;
    if ( v8 )
    {
      v13 = 0;
      v14 = 0;
      if ( a4 != 64 )
      {
        do
        {
          *(char *)(a1 + v14) = 0;
          v14 = ++v13;
        }
        while ( v13 < v9 );
      }
    }
    else
    {
      if ( a4 != 64 )
      {
        v10 = 0;
        v11 = 0;
        do
        {
          *(char *)(a1 + v11) = *(char *)(a3 + v10 + 64);
          v11 = ++v10;
        }
        while ( v10 < v9 );
      }
      *a2 = v9;
    }
  }
  return 0.0;
}


// Function: crypto_verify_32 @ 0x30f00
double crypto_verify_32()
{
  return 0.0;
}


// Function: crypto_hash_sha512 @ 0x310d0
double crypto_hash_sha512(long long a1, long long a2, long long a3)
{
  long long v4; // rax
  int v5; // eax

  v4 = EVP_sha512();
  v5 = EVP_Digest(a2, a3, a1, 0, v4, 0);
  sub_3DAE0(v5 == 0);
  return 0.0;
}


// Function: platform_sys_dir_uid @ 0x31190
double platform_sys_dir_uid()
{
  return 0.0;
}


// Function: cleanup_exit @ 0x31220
void cleanup_exit(int a1)
{
  _exit(a1);
}


// Function: masklen_valid @ 0x31230
double masklen_valid(int a1, unsigned int a2)
{
  if ( a1 == 2 )
  {
    sub_3DAE0(a2 > 0x20);
    return 0.0;
  }
  else
  {
    if ( a1 == 10 )
      sub_3DAE0(a2 > 0x80);
    return 0.0;
  }
}


// Function: addr_unicast_masklen @ 0x31490
double addr_unicast_masklen()
{
  return 0.0;
}


// Function: addr_xaddr_to_sa @ 0x31530
double addr_xaddr_to_sa(long long a1, long long a2, int *a3, unsigned short a4)
{
  if ( a3 == 0 || a1 == 0 || !a2 )
    return 0.0;
  if ( *(short *)a1 != 2 )
  {
    if ( *(short *)a1 == 10 && *a3 > 0x1Bu )
    {
      *(long long *)(a2 + 16) = 0;
      *(_OWORD *)a2 = 0;
      *(int *)(a2 + 24) = 0;
      *a3 = 28;
      *(short *)a2 = 10;
      *(short *)(a2 + 2) = sub_31370(a4);
      *(__m128i *)(a2 + 8) = _mm_loadu_si128((const __m128i *)(a1 + 4));
      *(int *)(a2 + 24) = *(int *)(a1 + 20);
      return 0.0;
    }
    return 0.0;
  }
  if ( *a3 <= 0xFu )
    return 0.0;
  *(_OWORD *)a2 = 0;
  *a3 = 16;
  *(short *)a2 = 2;
  *(short *)(a2 + 2) = sub_31370(a4);
  *(int *)(a2 + 4) = *(int *)(a1 + 4);
  return 0.0;
}


// Function: addr_sa_to_xaddr @ 0x31790
double addr_sa_to_xaddr(long long a1, unsigned int a2, long long a3)
{
  *(long long *)(a3 + 16) = 0;
  *(_OWORD *)a3 = 0;
  if ( *(short *)a1 != 2 )
  {
    if ( *(short *)a1 == 10 && a2 > 0x1B )
    {
      *(short *)a3 = 10;
      *(__m128i *)(a3 + 4) = _mm_loadu_si128((const __m128i *)(a1 + 8));
      *(int *)(a3 + 20) = *(int *)(a1 + 24);
      return 0.0;
    }
    return 0.0;
  }
  if ( a2 <= 0xF )
    return 0.0;
  *(short *)a3 = 2;
  *(int *)(a3 + 4) = *(int *)(a1 + 4);
  return 0.0;
}


// Function: addr_invert @ 0x31980
double addr_invert(long long a1)
{
  int *v1; // rax
  int *v2; // rdi

  if ( !a1 )
    return 0.0;
  if ( *(short *)a1 == 2 )
  {
    *(int *)(a1 + 4) = ~*(int *)(a1 + 4);
    return 0.0;
  }
  if ( *(short *)a1 != 10 )
    return 0.0;
  v1 = (int *)(a1 + 4);
  v2 = (int *)(a1 + 20);
  do
  {
    *v1 = ~*v1;
    ++v1;
  }
  while ( v1 != v2 );
  return 0.0;
}


// Function: addr_netmask @ 0x31b50
double addr_netmask(int a1, unsigned int a2, long long a3)
{
  unsigned int v4; // ebx
  int v5; // eax
  long long v6; // rax
  long long v7; // rbp
  bool v8; // dl

  v4 = a2;
  sub_31230(a1, a2);
  if ( !a3 || v5 )
    return 0.0;
  *(long long *)(a3 + 16) = 0;
  *(_OWORD *)a3 = 0;
  if ( a1 != 2 )
  {
    if ( a1 == 10 )
    {
      *(short *)a3 = 10;
      if ( a2 <= 0x1F )
      {
        v7 = 0;
        v8 = 1;
      }
      else
      {
        v6 = 1;
        do
        {
          v4 -= 32;
          *(int *)(a3 + 4 * v6) = -1;
          v7 = (int)v6;
          v8 = (int)v6++ <= 3;
        }
        while ( v4 > 0x1F && v8 );
      }
      if ( v4 && v8 )
      {
        *(int *)(a3 + 4 * v7 + 4) = sub_31400((unsigned int)(-1 << (32 - v4)));
        return 0.0;
      }
      return 0.0;
    }
    return 0.0;
  }
  *(short *)a3 = 2;
  if ( a2 )
    *(int *)(a3 + 4) = sub_31400((unsigned int)(-1 << (32 - a2)));
  return 0.0;
}


// Function: addr_hostmask @ 0x31dd0
double addr_hostmask(int a1, unsigned int a2, long long a3)
{
  int v4; // eax
  int v5; // eax

  sub_31B50(a1, a2, a3);
  if ( v4 != -1 )
  {
    sub_31980(a3);
    sub_3DAE0(v5 == -1);
  }
  return 0.0;
}


// Function: addr_and @ 0x31e80
double addr_and(__m128i *a1, const __m128i *a2, long long a3)
{
  long long i; // rcx

  if ( a3 == 0 || a2 == 0 || !a1 || a2->m128i_i16[0] != *(short *)a3 )
    return 0.0;
  *a1 = _mm_loadu_si128(a2);
  a1[1].m128i_i64[0] = a2[1].m128i_i64[0];
  if ( a2->m128i_i16[0] == 2 )
  {
    a1->m128i_i32[1] &= *(int *)(a3 + 4);
    return 0.0;
  }
  if ( a2->m128i_i16[0] != 10 )
    return 0.0;
  a1[1].m128i_i32[1] = a2[1].m128i_i32[1];
  for ( i = 1; i != 5; ++i )
    a1->m128i_i32[i] &= *(int *)(a3 + i * 4);
  return 0.0;
}


// Function: addr_cmp @ 0x32090
double addr_cmp(short *a1, long long a2)
{
  short v2; // ax
  long long v4; // rax
  unsigned char v5; // dl
  unsigned char v6; // cl
  long long v7; // rdi
  unsigned int v8; // ebp

  v2 = *a1;
  if ( *a1 != *(short *)a2 )
    return 0.0;
  if ( v2 != 2 )
  {
    if ( v2 == 10 )
    {
      v4 = 4;
      while ( 1 )
      {
        v5 = *((char *)a1 + v4);
        v6 = *(char *)(a2 + v4);
        if ( v5 != v6 )
          break;
        if ( ++v4 == 20 )
          return 0.0;
      }
      sub_3DA60(v5, v6);
    }
    return 0.0;
  }
  v7 = *((unsigned int *)a1 + 1);
  v8 = *(int *)(a2 + 4);
  if ( (int)v7 == v8 )
    return 0.0;
  sub_31400(v7);
  sub_31400(v8);
  return 0.0;
}


// Function: addr_is_all0s @ 0x322d0
double addr_is_all0s(long long a1)
{
  int *v1; // rax
  int *v2; // rdi

  if ( *(short *)a1 == 2 )
  {
    sub_3DAE0(*(int *)(a1 + 4) != 0);
    return 0.0;
  }
  else
  {
    if ( *(short *)a1 == 10 )
    {
      v1 = (int *)(a1 + 4);
      v2 = (int *)(a1 + 20);
      while ( !*v1 )
      {
        if ( ++v1 == v2 )
          return 0.0;
      }
    }
    return 0.0;
  }
}


// Function: addr_host_is_all0s @ 0x324b0
double addr_host_is_all0s(const __m128i *a1, unsigned int a2)
{
  __m128i v2; // xmm0
  long long v3; // rax
  int v4; // edi
  int v5; // eax
  int v6; // eax
  __m128i v8; // [rsp+0h] [rbp-78h] BYREF
  long long v9; // [rsp+10h] [rbp-68h]
  char v10[32]; // [rsp+20h] [rbp-58h] BYREF
  __m128i v11; // [rsp+40h] [rbp-38h] BYREF
  unsigned long long v12; // [rsp+58h] [rbp-20h]

  v2 = _mm_loadu_si128(a1);
  v12 = __readfsqword(0x28u);
  v3 = a1[1].m128i_i64[0];
  v4 = a1->m128i_u16[0];
  v8 = v2;
  v9 = v3;
  sub_31DD0(v4, a2, (long long)v10);
  if ( v5 != -1 )
  {
    sub_31E80(&v11, &v8, (long long)v10);
    if ( v6 != -1 )
      sub_322D0((long long)&v11);
  }
  return 0.0;
}


// Function: addr_pton @ 0x325d0
double addr_pton(const char *a1, long long a2)
{
  struct addrinfo *v2; // rbp
  struct sockaddr *ai_addr; // rdi
  int v4; // eax
  struct addrinfo *pai; // [rsp+0h] [rbp-60h] BYREF
  struct addrinfo req; // [rsp+8h] [rbp-58h] BYREF
  unsigned long long v8; // [rsp+40h] [rbp-20h]

  v8 = __readfsqword(0x28u);
  memset(&req, 0, sizeof(req));
  req.ai_flags = 4;
  if ( a1 )
  {
    if ( !getaddrinfo(a1, 0, &req, &pai) )
    {
      v2 = pai;
      if ( pai )
      {
        ai_addr = pai->ai_addr;
        if ( !ai_addr || a2 && (sub_31790((long long)ai_addr, pai->ai_addrlen, a2), v4 == -1) )
          freeaddrinfo(v2);
        else
          freeaddrinfo(v2);
      }
    }
  }
  return 0.0;
}


// Function: addr_sa_pton @ 0x32730
double addr_sa_pton(const char *a1, const char *a2, void *a3, unsigned int a4)
{
  struct addrinfo *v6; // rbp
  size_t ai_addrlen; // rdx
  struct addrinfo *pai; // [rsp+0h] [rbp-70h] BYREF
  struct addrinfo req; // [rsp+8h] [rbp-68h] BYREF
  unsigned long long v11; // [rsp+40h] [rbp-30h]

  v11 = __readfsqword(0x28u);
  memset(&req, 0, sizeof(req));
  req.ai_flags = 4;
  if ( a1 )
  {
    if ( !getaddrinfo(a1, a2, &req, &pai) )
    {
      v6 = pai;
      if ( pai )
      {
        if ( pai->ai_addr )
        {
          if ( !a3 )
          {
LABEL_8:
            freeaddrinfo(v6);
            return 0.0;
          }
          ai_addrlen = pai->ai_addrlen;
          if ( (unsigned int)ai_addrlen <= a4 )
          {
            memcpy(a3, &pai->ai_addr, ai_addrlen);
            goto LABEL_8;
          }
        }
        freeaddrinfo(pai);
      }
    }
  }
  return 0.0;
}


// Function: addr_ntop @ 0x32890
double addr_ntop(long long a1, char *a2, long long a3)
{
  int v4; // eax
  int v5; // eax
  socklen_t salen; // [rsp+Ch] [rbp-ACh] BYREF
  struct sockaddr sa; // [rsp+10h] [rbp-A8h] BYREF
  unsigned long long v9; // [rsp+98h] [rbp-20h]

  v9 = __readfsqword(0x28u);
  salen = 128;
  sub_31530(a1, (long long)&sa, &salen, 0);
  if ( v4 != -1 && a2 && a3 )
  {
    v5 = getnameinfo(&sa, salen, a2, a3, 0, 0, 1);
    sub_3DAE0(v5 == -1);
  }
  return 0.0;
}


// Function: addr_pton_cidr @ 0x329d0
double addr_pton_cidr(long long a1, __m128i *a2, int *a3)
{
  char *v4; // rax
  char *v5; // r13
  unsigned long long v6; // rbx
  int v7; // eax
  int v8; // r14d
  int v9; // eax
  int v10; // eax
  __m128i v11; // xmm0
  int v13; // eax
  int v14; // eax
  char *endptr; // [rsp+8h] [rbp-A0h] BYREF
  __m128i v16; // [rsp+10h] [rbp-98h] BYREF
  long long v17; // [rsp+20h] [rbp-88h]
  char s[72]; // [rsp+30h] [rbp-78h] BYREF
  unsigned long long v19; // [rsp+78h] [rbp-30h]

  v19 = __readfsqword(0x28u);
  if ( a1 && (unsigned long long)sub_3BEE0(s, a1, 64) <= 0x3F )
  {
    v4 = strchr(s, 47);
    v5 = v4;
    if ( v4 )
    {
      *v4 = 0;
      v6 = strtoul(v4 + 1, &endptr, 10);
      if ( (unsigned char)(v5[1] - 48) > 9u )
        return 0.0;
      if ( *endptr )
        return 0.0;
      if ( v6 > 0x80 )
        return 0.0;
      sub_325D0(s, (long long)&v16);
      if ( v7 == -1 )
        return 0.0;
      v8 = v16.m128i_u16[0];
    }
    else
    {
      sub_325D0(s, (long long)&v16);
      if ( v13 == -1 )
        return 0.0;
      v8 = v16.m128i_u16[0];
      sub_31490();
      LODWORD(v6) = v14;
    }
    sub_31230(v8, v6);
    if ( v9 != -1 )
    {
      sub_324B0(&v16, v6);
      if ( !v10 )
      {
        if ( a2 )
        {
          v11 = _mm_load_si128(&v16);
          a2[1].m128i_i64[0] = v17;
          *a2 = v11;
        }
        if ( a3 )
          *a3 = v6;
      }
    }
  }
  return 0.0;
}


// Function: addr_netmatch @ 0x32bd0
double addr_netmatch(const __m128i *a1, short *a2, unsigned int a3)
{
  int v4; // edi
  int v5; // eax
  int v6; // eax
  char v8[32]; // [rsp+0h] [rbp-68h] BYREF
  __m128i v9; // [rsp+20h] [rbp-48h] BYREF
  unsigned long long v10; // [rsp+38h] [rbp-30h]

  v4 = a1->m128i_u16[0];
  v10 = __readfsqword(0x28u);
  if ( (short)v4 == *a2 )
  {
    sub_31B50(v4, a3, (long long)v8);
    if ( v5 != -1 )
    {
      sub_31E80(&v9, a1, (long long)v8);
      if ( v6 != -1 )
        sub_32090(v9.m128i_i16, (long long)a2);
    }
  }
  return 0.0;
}


// Function: atomicio6 @ 0x32cf0
double atomicio6(
        ssize_t (**a1)(int fd, void *buf, size_t nbytes),
        unsigned int a2,
        long long a3,
        unsigned long long a4,
        unsigned int (*a5)(long long, long long),
        long long a6)
{
  unsigned long long v9; // r15
  long long v10; // rax
  int *v12; // rdx
  int *v14; // [rsp+18h] [rbp-50h]
  struct pollfd v15[9]; // [rsp+20h] [rbp-48h] BYREF

  v15[1] = (struct pollfd)__readfsqword(0x28u);
  v15[0].fd = a2;
  v15[0].events = 3 * (a1 != &read) + 1;
  if ( a4 )
  {
    v9 = 0;
    do
    {
      v10 = ((long long (*)(long long, unsigned long long, unsigned long long))a1)(a2, a3 + v9, a4 - v9);
      if ( v10 == -1 )
      {
        v12 = __errno_location();
        if ( *v12 == 4 )
        {
          v14 = v12;
          if ( a5 && a5(a6, 0) == -1 )
          {
            *v14 = 4;
            return 0.0;
          }
        }
        else
        {
          if ( *v12 != 11 )
            return 0.0;
          poll(v15, 1u, -1);
        }
      }
      else
      {
        if ( !v10 )
        {
          *__errno_location() = 32;
          return 0.0;
        }
        v9 += v10;
        if ( a5 && a5(a6, v10) == -1 )
        {
          *__errno_location() = 4;
          return 0.0;
        }
      }
    }
    while ( v9 < a4 );
  }
  return 0.0;
}


// Function: atomicio @ 0x32ef0
double atomicio(
        ssize_t (**a1)(int fd, void *buf, size_t nbytes),
        unsigned int a2,
        long long a3,
        unsigned long long a4)
{
  return sub_32CF0(a1, a2, a3, a4, 0, 0);
}


// Function: atomiciov6 @ 0x32f00
// positive sp value has been detected, the output may be wrong!
double atomiciov6(
        ssize_t (**a1)(int fd, const struct iovec *iovec, int count),
        unsigned int a2,
        long long a3,
        unsigned int a4,
        unsigned int (*a5)(long long, long long),
        long long a6,
        double a7)
{
  unsigned int v9; // r12d
  long long v10; // rdi
  long long *v11; // r13
  long long v12; // r15
  long long v13; // rax
  long long v14; // rbp
  unsigned long long v15; // r14
  unsigned long long v16; // rax
  int *v17; // rbp
  unsigned int (*v18)(long long, long long); // [rsp-40h] [rbp-4070h]
  long long v19; // [rsp-38h] [rbp-4068h]
  struct pollfd v20; // [rsp-20h] [rbp-4050h] BYREF
  long long v21; // [rsp-18h] [rbp-4048h] BYREF
  char v22; // [rsp+0h] [rbp-4030h] BYREF
  long long v23; // [rsp+1000h] [rbp-3030h] BYREF
  unsigned long long v24; // [rsp+3FF0h] [rbp-40h]

  while ( &v22 != (char *)(&v23 - 2048) )
    ;
  v18 = a5;
  v19 = a6;
  v24 = __readfsqword(0x28u);
  if ( a4 <= 0x400 )
  {
    v9 = a4;
    v10 = __memcpy_chk(&v21, a3, 16LL * (int)a4, 0x4000, a7);
    v20.fd = a2;
    v20.events = 3 * (a1 != &readv) + 1;
    if ( v9 )
    {
      v11 = (long long *)v10;
      v12 = 0;
LABEL_7:
      while ( v11[1] )
      {
        v13 = ((long long (*)(long long, long long *, long long))a1)(a2, v11, v9);
        v14 = v13;
        if ( v13 != -1 )
        {
          if ( v13 )
          {
            v12 += v13;
            v15 = v13;
            do
            {
              v16 = v11[1];
              if ( v16 > v15 )
              {
                if ( v15 )
                {
                  *v11 += v15;
                  v11[1] = v16 - v15;
                }
                if ( v18 && v18(v19, v14) == -1 )
                  goto LABEL_16;
                goto LABEL_7;
              }
              v15 -= v16;
              v11 += 2;
              v9 = sub_3DA20(v9, 0xFFFFFFFFLL);
            }
            while ( v9 );
            if ( v15 )
            {
              *__errno_location() = 14;
            }
            else if ( v18 && v18(v19, v14) == -1 )
            {
LABEL_16:
              *__errno_location() = 4;
              return 0.0;
            }
          }
          else
          {
            *__errno_location() = 32;
          }
          return 0.0;
        }
        v17 = __errno_location();
        if ( *v17 == 4 )
        {
          if ( v18 && v18(v19, 0) == -1 )
          {
            *v17 = 4;
            return 0.0;
          }
        }
        else
        {
          if ( *v17 != 11 )
            return 0.0;
          poll(&v20, 1u, -1);
        }
      }
    }
  }
  else
  {
    *__errno_location() = 22;
  }
  return 0.0;
}


// Function: poly1305_auth @ 0x331f0
double poly1305_auth(int *a1, long long a2, unsigned long long a3, __int128 *a4)
{
  int v6; // r9d
  int v7; // r11d
  int v8; // ebp
  int v9; // ebx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // eax
  long long v13; // rdi
  long long v14; // rsi
  long long v15; // rcx
  long long v16; // r9
  long long v17; // rax
  long long v18; // r13
  long long v19; // r14
  long long v20; // r12
  long long v21; // r10
  long long v22; // rbx
  unsigned long long v23; // r12
  unsigned long long v24; // rbp
  unsigned long long v25; // r10
  unsigned long long v26; // r10
  unsigned int v27; // ecx
  int v28; // r12d
  unsigned int v29; // ebp
  unsigned int v30; // r10d
  int v31; // r13d
  unsigned int v32; // ebx
  unsigned int v33; // r9d
  unsigned int v34; // r9d
  unsigned int v35; // edx
  unsigned int v36; // esi
  int v37; // r11d
  int v38; // r10d
  unsigned int v39; // ecx
  unsigned int v40; // r9d
  int v41; // ebp
  unsigned long long v42; // rax
  unsigned int v43; // edi
  unsigned int v44; // edx
  unsigned long long v45; // rcx
  unsigned int v46; // edi
  unsigned long long v47; // rax
  unsigned long long v48; // rax
  long long i; // rsi
  _OWORD *v51; // rcx
  unsigned int v52; // [rsp+0h] [rbp-98h]
  unsigned int v53; // [rsp+4h] [rbp-94h]
  unsigned int v54; // [rsp+8h] [rbp-90h]
  int v55; // [rsp+Ch] [rbp-8Ch]
  __int128 v56; // [rsp+10h] [rbp-88h]
  long long v57; // [rsp+20h] [rbp-78h]
  long long v58; // [rsp+28h] [rbp-70h]
  long long v59; // [rsp+30h] [rbp-68h]
  int v60; // [rsp+3Ch] [rbp-5Ch]
  __int128 v61; // [rsp+40h] [rbp-58h] BYREF
  unsigned long long v62; // [rsp+58h] [rbp-40h]

  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = *((int *)a4 + 4);
  v62 = __readfsqword(0x28u);
  v52 = v10;
  v56 = *a4;
  v11 = 0;
  if ( a3 > 0xF )
  {
    v53 = *((int *)a4 + 5);
    v54 = *((int *)a4 + 6);
    v55 = *((int *)a4 + 7);
    while ( 1 )
    {
      a3 -= 16LL;
      v57 = a2 + 16;
      v12 = (*(int *)a2 & 0x3FFFFFF) + v11;
      v13 = v7 + ((unsigned int)(*(long long *)a2 >> 26) & 0x3FFFFFF);
      v14 = v9 + ((unsigned int)(*(long long *)(a2 + 4) >> 20) & 0x3FFFFFF);
      v15 = v8 + ((unsigned int)(*(long long *)(a2 + 8) >> 14) & 0x3FFFFFF);
      v16 = ((*(int *)(a2 + 12) >> 8) | 0x1000000u) + v6;
      while ( 1 )
      {
        v58 = v12;
        v17 = v56 & 0x3FFFFFF;
        v18 = ((long long)v56 >> 26) & 0x3FFFF03;
        v19 = (*(long long *)((char *)&v56 + 4) >> 20) & 0x3FFC0FF;
        v20 = (unsigned int)(5 * v19);
        v21 = 5 * ((HIDWORD(v56) >> 8) & 0xFFFFF);
        v22 = 5 * ((unsigned int)(*((long long *)&v56 + 1) >> 14) & 0x3F03FFF);
        v59 = (*((long long *)&v56 + 1) >> 14) & 0x3F03FFF;
        v60 = (v16 * 5 * v18 + v22 * v14 + v17 * v58 + v21 * v13 + v20 * v15) & 0x3FFFFFF;
        v23 = ((v16 * (unsigned long long)(unsigned int)(5 * v18) + v22 * v14 + v17 * v58 + v21 * v13 + v20 * v15) >> 26)
            + v18 * v58
            + v13 * v17
            + v22 * v15
            + v14 * v21
            + v16 * v20;
        v7 = v23 & 0x3FFFFFF;
        v24 = v19 * v58 + v18 * v13 + v15 * v21 + v14 * v17 + v16 * v22 + (unsigned int)(v23 >> 26);
        v9 = v24 & 0x3FFFFFF;
        v25 = (unsigned int)(v24 >> 26) + v59 * v58 + v19 * v13 + v15 * v17 + v18 * v14 + v16 * v21;
        v8 = v25 & 0x3FFFFFF;
        v26 = v19 * v14
            + v18 * v15
            + v59 * v13
            + v58 * ((HIDWORD(v56) >> 8) & 0xFFFFF)
            + v16 * v17
            + (unsigned int)(v25 >> 26);
        LODWORD(v17) = 5 * (v26 >> 26);
        v6 = v26 & 0x3FFFFFF;
        a2 = v57;
        v11 = v60 + v17;
        if ( a3 > 0xF )
          break;
        if ( !a3 )
          goto LABEL_6;
LABEL_8:
        for ( i = 0; i != a3; ++i )
          *((char *)&v61 + i) = *(char *)(a2 + i);
        *((char *)&v61 + a3) = 1;
        v51 = (__int128 *)((char *)&v61 + a3);
        if ( a3 != 15 )
        {
          do
          {
            *((char *)v51 + 1) = 0;
            v51 = (_OWORD *)((char *)v51 + 1);
          }
          while ( v51 != (__int128 *)((char *)&v61 + 15) );
        }
        v57 = a2;
        v12 = (v61 & 0x3FFFFFF) + v11;
        v13 = v7 + ((unsigned int)((unsigned long long)v61 >> 26) & 0x3FFFFFF);
        v14 = v9 + ((unsigned int)(*(long long *)((char *)&v61 + 4) >> 20) & 0x3FFFFFF);
        v15 = v8 + ((unsigned int)(*((long long *)&v61 + 1) >> 14) & 0x3FFFFFF);
        v16 = (unsigned int)((HIDWORD(v61) >> 8) + v6);
        a3 = 0;
      }
    }
  }
  v53 = *((int *)a4 + 5);
  v54 = *((int *)a4 + 6);
  v55 = *((int *)a4 + 7);
  if ( a3 )
    goto LABEL_8;
LABEL_6:
  v27 = (v11 >> 26) + v7;
  v28 = (v9 + (v27 >> 26)) & 0x3FFFFFF;
  v29 = v8 + ((v9 + (v27 >> 26)) >> 26);
  v30 = v6 + (v29 >> 26);
  v29 &= 0x3FFFFFFu;
  v31 = v30 & 0x3FFFFFF;
  v32 = (v11 & 0x3FFFFFF) + 5 * (v30 >> 26);
  v33 = v32 >> 26;
  v32 &= 0x3FFFFFFu;
  v34 = (v27 & 0x3FFFFFF) + v33;
  v35 = v28 + ((v34 + ((v32 + 5) >> 26)) >> 26);
  v36 = (v30 | 0xFC000000) + ((v29 + (v35 >> 26)) >> 26);
  v37 = (v36 >> 31) - 1;
  v38 = -(v36 >> 31);
  v39 = v38 & v34 | v37 & (v34 + ((v32 + 5) >> 26)) & 0x3FFFFFF;
  v40 = v29;
  v41 = v37 & (v29 + (v35 >> 26));
  v42 = v52 + (unsigned long long)((v39 << 26) | v38 & v32 | v37 & (v32 + 5) & 0x3FFFFFF);
  v43 = v38 & v28 | v37 & v35 & 0x3FFFFFF;
  v44 = v43 >> 12;
  *a1 = v42;
  v45 = v53 + (unsigned long long)((v43 << 20) | (v39 >> 6));
  v46 = v38 & v40 | v41 & 0x3FFFFFF;
  v47 = v45 + HIDWORD(v42);
  a1[1] = v47;
  v48 = v54 + (unsigned long long)((v46 << 14) | v44) + HIDWORD(v47);
  a1[2] = v48;
  a1[3] = v55 + ((v46 >> 18) | ((v31 & v38 | v37 & v36) << 8)) + HIDWORD(v48);
  return 0.0;
}


// Function: lt @ 0x33750
double lt()
{
  return 0.0;
}


// Function: reduce_add_sub @ 0x361b0
double reduce_add_sub(unsigned int *a1)
{
  int v1; // ebp
  int v2; // eax
  unsigned int v3; // eax
  unsigned int *v4; // rdx

  v1 = 4;
  do
  {
    a1[31] &= 0x7Fu;
    sub_36090();
    v3 = *a1 + v2;
    v4 = a1;
    *a1 = v3;
    while ( 1 )
    {
      *v4 = (unsigned char)*v4;
      v4[1] += v3 >> 8;
      if ( a1 + 31 == ++v4 )
        break;
      v3 = *v4;
    }
    --v1;
  }
  while ( v1 );
  return 0.0;
}


// Function: barrett_reduce @ 0x33920
double barrett_reduce(long long a1, long long a2)
{
  unsigned long long *v3; // rax
  unsigned int *v4; // rdi
  long long *v5; // rax
  const char *v6; // r9
  int v7; // r8d
  int v8; // eax
  int *v9; // rdx
  long long i; // rax
  int *v11; // r9
  int v12; // r8d
  int v13; // eax
  int *v14; // rdx
  unsigned int v15; // edx
  long long v16; // r13
  int v17; // eax
  int v18; // r15d
  int v19; // r14d
  char v21[144]; // [rsp+0h] [rbp-268h]
  int v22[32]; // [rsp+90h] [rbp-1D8h] BYREF
  long long v23; // [rsp+110h] [rbp-158h] BYREF
  int v24[32]; // [rsp+120h] [rbp-148h] BYREF
  unsigned int v25; // [rsp+1A0h] [rbp-C8h]
  int v26; // [rsp+1A4h] [rbp-C4h] BYREF
  unsigned long long v27; // [rsp+228h] [rbp-40h] BYREF

  v27 = __readfsqword(0x28u);
  v3 = (unsigned long long *)v24;
  do
  {
    *(int *)v3 = 0;
    v3 = (unsigned long long *)((char *)v3 + 4);
  }
  while ( v3 != &v27 );
  v4 = v22;
  v5 = v22;
  do
  {
    *(int *)v5 = 0;
    v5 = (long long *)((char *)v5 + 4);
  }
  while ( v5 != (long long *)((char *)&v23 + 4) );
  v6 = "\x1B";
  v7 = 33;
  do
  {
    v8 = v7 - 33;
    v9 = (int *)(a2 + 124);
    do
    {
      if ( v8 > 30 )
        v24[v8] += *v9 * *(int *)v6;
      ++v8;
      ++v9;
    }
    while ( v8 != v7 );
    v7 = v8 + 1;
    v6 += 4;
  }
  while ( v8 != 65 );
  v25 += v24[31] >> 8;
  v26 += v25 >> 8;
  for ( i = 0; i != 132; i += 4 )
    *(int *)&v21[i] = *(int *)(a2 + i);
  v11 = dword_40F40;
  v12 = 33;
  do
  {
    v13 = v12 - 33;
    v14 = &v26;
    do
    {
      if ( v13 <= 32 )
        v22[v13] += *v14 * *v11;
      ++v13;
      ++v14;
    }
    while ( v13 != v12 );
    v12 = v13 + 1;
    ++v11;
  }
  while ( v13 != 64 );
  do
  {
    v15 = *v4;
    *v4 = (unsigned char)*v4;
    v4[1] += v15 >> 8;
    ++v4;
  }
  while ( &v23 != (long long *)v4 );
  v16 = 0;
  v17 = 0;
  do
  {
    v18 = *(int *)&v21[v16 * 4];
    v19 = v22[v16] + v17;
    sub_33750();
    *(int *)(a1 + v16 * 4) = v18 + (v17 << 8) - v19;
    ++v16;
  }
  while ( v16 != 32 );
  sub_337E0(a1);
  return sub_337E0(a1);
}


// Function: crypto_sign_ed25519_ref_sc25519_from32bytes @ 0x33b20
double crypto_sign_ed25519_ref_sc25519_from32bytes(long long a1, long long a2)
{
  long long i; // rax
  char *v3; // rax
  int v5[32]; // [rsp+0h] [rbp-118h] BYREF
  char v6; // [rsp+80h] [rbp-98h] BYREF
  char v7; // [rsp+100h] [rbp-18h] BYREF
  unsigned long long v8; // [rsp+108h] [rbp-10h]

  v8 = __readfsqword(0x28u);
  for ( i = 0; i != 32; ++i )
    v5[i] = *(unsigned char *)(a2 + i);
  v3 = &v6;
  do
  {
    *(int *)v3 = 0;
    v3 += 4;
  }
  while ( v3 != &v7 );
  sub_33920(a1, (long long)v5);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_sc25519_from64bytes @ 0x33cd0
double crypto_sign_ed25519_ref_sc25519_from64bytes(long long a1, long long a2)
{
  long long i; // rax
  int v4[66]; // [rsp+0h] [rbp-118h] BYREF
  unsigned long long v5; // [rsp+108h] [rbp-10h]

  v5 = __readfsqword(0x28u);
  for ( i = 0; i != 64; ++i )
    v4[i] = *(unsigned char *)(a2 + i);
  sub_33920(a1, (long long)v4);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_sc25519_from_shortsc @ 0x33dc0
double crypto_sign_ed25519_ref_sc25519_from_shortsc(long long a1, long long a2)
{
  long long i; // rax
  int *v3; // rax
  int *v4; // rdi

  for ( i = 0; i != 64; i += 4 )
    *(int *)(a1 + i) = *(int *)(a2 + i);
  v3 = (int *)(a1 + 64);
  v4 = (int *)(a1 + 128);
  do
    *v3++ = 0;
  while ( v3 != v4 );
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_sc25519_to32bytes @ 0x33e80
double crypto_sign_ed25519_ref_sc25519_to32bytes(long long a1, long long a2)
{
  long long i; // rax

  for ( i = 0; i != 32; ++i )
    *(char *)(a1 + i) = *(int *)(a2 + 4 * i);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_sc25519_add @ 0x342b0
double crypto_sign_ed25519_ref_sc25519_add(long long a1, long long a2, long long a3)
{
  long long i; // rax
  unsigned int *v4; // rax
  unsigned int v5; // ecx

  for ( i = 0; i != 128; i += 4 )
    *(int *)(a1 + i) = *(int *)(a2 + i) + *(int *)(a3 + i);
  v4 = (unsigned int *)a1;
  do
  {
    v5 = *v4;
    *v4 = (unsigned char)*v4;
    v4[1] += v5 >> 8;
    ++v4;
  }
  while ( v4 != (unsigned int *)(a1 + 124) );
  return sub_337E0(a1);
}


// Function: crypto_sign_ed25519_ref_sc25519_mul @ 0x343c0
double crypto_sign_ed25519_ref_sc25519_mul(long long a1, long long a2, long long a3)
{
  unsigned int *v6; // r9
  char *v7; // rax
  long long i; // rsi
  int v9; // edi
  long long j; // rax
  int v11; // ecx
  int v12; // edx
  unsigned int v13; // edx
  int v15[63]; // [rsp+0h] [rbp-118h] BYREF
  int v16; // [rsp+FCh] [rbp-1Ch] BYREF
  char v17; // [rsp+100h] [rbp-18h] BYREF
  unsigned long long v18; // [rsp+108h] [rbp-10h]

  v18 = __readfsqword(0x28u);
  v6 = v15;
  v7 = (char *)v15;
  do
  {
    *(int *)v7 = 0;
    v7 += 4;
  }
  while ( v7 != &v17 );
  for ( i = 0; i != 32; ++i )
  {
    v9 = *(int *)(a2 + 4 * i);
    for ( j = 0; j != 32; ++j )
    {
      v11 = *(int *)(a3 + 4 * j);
      v12 = j + i;
      v15[v12] += v9 * v11;
    }
  }
  do
  {
    v13 = *v6;
    *v6 = (unsigned char)*v6;
    v6[1] += v13 >> 8;
    ++v6;
  }
  while ( &v16 != (int *)v6 );
  sub_33920(a1, (long long)v15);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_sc25519_mul_shortsc @ 0x34520
double crypto_sign_ed25519_ref_sc25519_mul_shortsc(long long a1, long long a2, long long a3)
{
  long long v4[21]; // [rsp+0h] [rbp-A8h] BYREF

  v4[17] = __readfsqword(0x28u);
  sub_33DC0((long long)v4, a3);
  sub_343C0(a1, a2, (long long)v4);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_sc25519_window3 @ 0x34610
double crypto_sign_ed25519_ref_sc25519_window3(char *a1, char *a2)
{
  char *v4; // rdx
  char *v5; // rax
  char *v6; // r9
  char *v7; // rcx
  char v8; // si
  char v9; // di
  int v10; // edi
  int v11; // ecx
  char v12; // dl
  char v13; // dl
  char v14; // cl

  v4 = a2;
  v5 = a1;
  v6 = a2 + 120;
  v7 = a1;
  do
  {
    v8 = *v4;
    v4 += 12;
    v7 += 8;
    *(v7 - 8) = v8 & 7;
    *(v7 - 7) = (*((int *)v4 - 3) >> 3) & 7;
    v9 = (*((int *)v4 - 3) >> 6) & 7;
    *(v7 - 6) = v9;
    *(v7 - 6) = v9 ^ (4 * *(v4 - 8)) & 7;
    *(v7 - 5) = (*((int *)v4 - 2) >> 1) & 7;
    *(v7 - 4) = (*((int *)v4 - 2) >> 4) & 7;
    v10 = (*((int *)v4 - 2) >> 7) & 7;
    *(v7 - 3) = (*((int *)v4 - 2) >> 7) & 7;
    *(v7 - 3) = v10 ^ (2 * *(v4 - 4)) & 7;
    *(v7 - 2) = (*((int *)v4 - 1) >> 2) & 7;
    *(v7 - 1) = *(v4 - 4) >> 5;
  }
  while ( v4 != v6 );
  a1[80] = a2[120] & 7;
  a1[81] = (*((int *)a2 + 30) >> 3) & 7;
  v11 = (*((int *)a2 + 30) >> 6) & 7;
  a1[82] = (*((int *)a2 + 30) >> 6) & 7;
  a1[82] = v11 ^ (4 * a2[124]) & 7;
  a1[83] = (*((int *)a2 + 31) >> 1) & 7;
  a1[84] = (*((int *)a2 + 31) >> 4) & 7;
  v12 = 0;
  do
  {
    v13 = *v5 + v12;
    v5[1] += v13 >> 3;
    v14 = v13 & 7;
    v12 = (v13 & 7) >> 2;
    *v5++ = v14 - 8 * v12;
  }
  while ( a1 + 84 != v5 );
  a1[84] += v12;
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_sc25519_2interleave2 @ 0x349b0
double crypto_sign_ed25519_ref_sc25519_2interleave2(char *a1, char *a2, char *a3)
{
  char *v5; // rdx
  char *v6; // rcx
  char *v7; // rsi
  char v8; // al
  char v9; // r11

  v5 = a2;
  v6 = a1;
  v7 = a3;
  do
  {
    v8 = *v7;
    v9 = *v5;
    v5 += 4;
    v7 += 4;
    v6 += 4;
    *(v6 - 4) = v9 & 3 | (4 * v8) & 0xC;
    *(v6 - 3) = *(v7 - 4) & 0xC | (*((int *)v5 - 1) >> 2) & 3;
    *(v6 - 2) = (*((int *)v5 - 1) >> 4) & 3 | (4 * (*((int *)v7 - 1) >> 4)) & 0xC;
    *(v6 - 1) = (*(v5 - 4) >> 6) | (4 * (*((int *)v7 - 1) >> 6)) & 0xC;
  }
  while ( v5 != a2 + 124 );
  a1[124] = a2[124] & 3 | (4 * a3[124]) & 0xC;
  a1[125] = a3[124] & 0xC | (*((int *)a2 + 31) >> 2) & 3;
  a1[126] = (*((int *)a2 + 31) >> 4) & 3 | (4 * (*((int *)a3 + 31) >> 4)) & 0xC;
  return 0.0;
}


// Function: equal @ 0x36000
double equal()
{
  return 0.0;
}


// Function: negative @ 0x34bb0
double negative()
{
  return 0.0;
}


// Function: p1p1_to_p2 @ 0x34c40
long long p1p1_to_p2(long long a1, long long a2)
{
  sub_36F20(a1, a2, a2 + 384);
  sub_36F20(a1 + 128, a2 + 256, a2 + 128);
  return sub_36F20(a1 + 256, a2 + 128, a2 + 384);
}


// Function: p1p1_to_p3 @ 0x34ca0
long long p1p1_to_p3(long long a1, long long a2)
{
  sub_34C40(a1, a2);
  return sub_36F20(a1 + 384, a2, a2 + 256);
}


// Function: add_p1p1 @ 0x34cd0
double add_p1p1(long long a1, long long a2, long long a3)
{
  char v5[128]; // [rsp+10h] [rbp-2C8h] BYREF
  char v6[128]; // [rsp+90h] [rbp-248h] BYREF
  char v7[128]; // [rsp+110h] [rbp-1C8h] BYREF
  char v8[128]; // [rsp+190h] [rbp-148h] BYREF
  char v9[136]; // [rsp+210h] [rbp-C8h] BYREF
  unsigned long long v10; // [rsp+298h] [rbp-40h]

  v10 = __readfsqword(0x28u);
  sub_36D80(v5, a2 + 128, a2);
  sub_36D80(v9, a3 + 128, a3);
  sub_36F20(v5, v5, v9);
  sub_36D50(v6, a2, a2 + 128);
  sub_36D50(v9, a3, a3 + 128);
  sub_36F20(v6, v6, v9);
  sub_36F20(v7, a2 + 384, a3 + 384);
  sub_36F20(v7, v7, &unk_5BB40);
  sub_36F20(v8, a2 + 256, a3 + 256);
  sub_36D50(v8, v8, v8);
  sub_36D80(a1, v6, v5);
  sub_36D80(a1 + 384, v8, v7);
  sub_36D50(a1 + 128, v8, v7);
  sub_36D50(a1 + 256, v6, v5);
  return 0.0;
}


// Function: ge25519_mixadd2 @ 0x34ed0
double ge25519_mixadd2(long long a1, long long a2)
{
  char v4[128]; // [rsp+20h] [rbp-5C8h] BYREF
  char v5[128]; // [rsp+A0h] [rbp-548h] BYREF
  char v6[128]; // [rsp+120h] [rbp-4C8h] BYREF
  char v7[128]; // [rsp+1A0h] [rbp-448h] BYREF
  char v8[128]; // [rsp+220h] [rbp-3C8h] BYREF
  char v9[128]; // [rsp+2A0h] [rbp-348h] BYREF
  char v10[128]; // [rsp+320h] [rbp-2C8h] BYREF
  char v11[128]; // [rsp+3A0h] [rbp-248h] BYREF
  char v12[128]; // [rsp+420h] [rbp-1C8h] BYREF
  char v13[128]; // [rsp+4A0h] [rbp-148h] BYREF
  char v14[136]; // [rsp+520h] [rbp-C8h] BYREF
  unsigned long long v15; // [rsp+5A8h] [rbp-40h]

  v15 = __readfsqword(0x28u);
  sub_36F20(v14, a2, a2 + 128);
  sub_36D80(v4, a1 + 128, a1);
  sub_36D50(v5, a1 + 128, a1);
  sub_36D80(v6, a2 + 128, a2);
  sub_36D50(v7, a2 + 128, a2);
  sub_36F20(v4, v4, v6);
  sub_36F20(v5, v5, v7);
  sub_36D80(v10, v5, v4);
  sub_36D50(v13, v5, v4);
  sub_36F20(v8, a1 + 384, v14);
  sub_36F20(v8, v8, &unk_5BB40);
  sub_36D50(v9, a1 + 256, a1 + 256);
  sub_36D80(v11, v9, v8);
  sub_36D50(v12, v9, v8);
  sub_36F20(a1, v10, v11);
  sub_36F20(a1 + 128, v13, v12);
  sub_36F20(a1 + 256, v12, v11);
  sub_36F20(a1 + 384, v10, v13);
  return 0.0;
}


// Function: dbl_p1p1 @ 0x35150
double dbl_p1p1(long long a1, long long a2)
{
  char v4[128]; // [rsp+10h] [rbp-248h] BYREF
  char v5[128]; // [rsp+90h] [rbp-1C8h] BYREF
  char v6[128]; // [rsp+110h] [rbp-148h] BYREF
  char v7[136]; // [rsp+190h] [rbp-C8h] BYREF
  unsigned long long v8; // [rsp+218h] [rbp-40h]

  v8 = __readfsqword(0x28u);
  sub_37010(v4);
  sub_37010(v5);
  sub_37010(v6);
  sub_36D50(v6, v6, v6);
  sub_36E20(v7, v4);
  sub_36D50(a1, a2, a2 + 128);
  sub_37010(a1);
  sub_36D80(a1, a1, v4);
  sub_36D80(a1, a1, v5);
  sub_36D50(a1 + 128, v7, v5);
  sub_36D80(a1 + 384, a1 + 128, v6);
  sub_36D80(a1 + 256, v7, v5);
  return 0.0;
}


// Function: setneutral @ 0x35300
long long setneutral(long long a1)
{
  ((void (*)(void))sub_36CB0)();
  sub_36C00(a1 + 128);
  sub_36C00(a1 + 256);
  return sub_36CB0(a1 + 384);
}


// Function: cmov_aff @ 0x35330
long long cmov_aff(long long a1, long long a2, unsigned char a3)
{
  unsigned int v3; // r12d

  v3 = a3;
  sub_36A30(a1, a2, a3);
  return sub_36A30(a1 + 128, a2 + 128, v3);
}


// Function: choose_t @ 0x35360
double choose_t(long long a1, long long a2)
{
  long long v2; // rbx
  const __m128i *v3; // rax
  __m128i si128; // xmm1
  __m128i v5; // xmm2
  __m128i v6; // xmm3
  __m128i v7; // xmm5
  __m128i v8; // xmm6
  __m128i v9; // xmm7
  __m128i v10; // xmm0
  __m128i v11; // xmm4
  __m128i v12; // xmm1
  __m128i v13; // xmm2
  __m128i v14; // xmm3
  __m128i v15; // xmm5
  __m128i v16; // xmm6
  __m128i v17; // xmm7
  char v18; // al
  char v19; // r14
  char v20; // al
  char v21; // al
  char v22; // r14
  char v23; // al
  char v24; // al
  char v25; // r14
  char v26; // al
  unsigned char v27; // al
  unsigned char v28; // al
  long long v30[23]; // [rsp+0h] [rbp-B8h] BYREF

  v30[17] = __readfsqword(0x28u);
  v2 = (5 * a2 + 1) << 8;
  v3 = (const __m128i *)((char *)&unk_40FC0 + 1280 * a2);
  si128 = _mm_load_si128(v3 + 1);
  v5 = _mm_load_si128(v3 + 2);
  v6 = _mm_load_si128(v3 + 3);
  v7 = _mm_load_si128(v3 + 5);
  v8 = _mm_load_si128(v3 + 6);
  *(__m128i *)a1 = _mm_load_si128(v3);
  v9 = _mm_load_si128(v3 + 7);
  v10 = _mm_load_si128(v3 + 8);
  *(__m128i *)(a1 + 16) = si128;
  v11 = _mm_load_si128(v3 + 4);
  v12 = _mm_load_si128(v3 + 9);
  *(__m128i *)(a1 + 32) = v5;
  *(__m128i *)(a1 + 48) = v6;
  v13 = _mm_load_si128(v3 + 10);
  v14 = _mm_load_si128(v3 + 11);
  *(__m128i *)(a1 + 128) = v10;
  *(__m128i *)(a1 + 144) = v12;
  *(__m128i *)(a1 + 160) = v13;
  *(__m128i *)(a1 + 176) = v14;
  *(__m128i *)(a1 + 80) = v7;
  *(__m128i *)(a1 + 96) = v8;
  *(__m128i *)(a1 + 112) = v9;
  *(__m128i *)(a1 + 64) = v11;
  v15 = _mm_load_si128(v3 + 13);
  v16 = _mm_load_si128(v3 + 14);
  v17 = _mm_load_si128(v3 + 15);
  *(__m128i *)(a1 + 192) = _mm_load_si128(v3 + 12);
  *(__m128i *)(a1 + 208) = v15;
  *(__m128i *)(a1 + 224) = v16;
  *(__m128i *)(a1 + 240) = v17;
  sub_34B20();
  v19 = v18;
  sub_34B20();
  sub_35330(a1, (long long)&unk_40FC0 + v2, v20 | v19);
  sub_34B20();
  v22 = v21;
  sub_34B20();
  sub_35330(a1, (long long)&unk_40FC0 + v2 + 256, v23 | v22);
  sub_34B20();
  v25 = v24;
  sub_34B20();
  sub_35330(a1, (long long)&unk_40FC0 + v2 + 512, v26 | v25);
  sub_34B20();
  sub_35330(a1, (long long)&unk_40FC0 + v2 + 768, v27);
  sub_36E20(v30, a1);
  sub_34BB0();
  sub_36A30(a1, v30, v28);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_unpackneg_vartime @ 0x355f0
double crypto_sign_ed25519_ref_unpackneg_vartime(long long a1, long long a2)
{
  char v3; // [rsp+Fh] [rbp-3C9h]
  char v4[128]; // [rsp+10h] [rbp-3C8h] BYREF
  char v5[128]; // [rsp+90h] [rbp-348h] BYREF
  char v6[128]; // [rsp+110h] [rbp-2C8h] BYREF
  char v7[128]; // [rsp+190h] [rbp-248h] BYREF
  char v8[128]; // [rsp+210h] [rbp-1C8h] BYREF
  char v9[128]; // [rsp+290h] [rbp-148h] BYREF
  char v10[136]; // [rsp+310h] [rbp-C8h] BYREF
  unsigned long long v11; // [rsp+398h] [rbp-40h]

  v11 = __readfsqword(0x28u);
  sub_36C00(a1 + 256);
  v3 = *(char *)(a2 + 31) >> 7;
  sub_36520(a1 + 128, a2);
  sub_37010(v6);
  sub_36F20(v7, v6, &unk_5BBC0);
  sub_36D80(v6, v6, a1 + 256);
  sub_36D50(v7, a1 + 256, v7);
  sub_37010(v8);
  sub_37010(v9);
  sub_36F20(v10, v9, v8);
  sub_36F20(v4, v10, v6);
  sub_36F20(v4, v4, v7);
  sub_373E0(v4, v4);
  sub_36F20(v4, v4, v6);
  sub_36F20(v4, v4, v7);
  sub_36F20(v4, v4, v7);
  sub_36F20(a1, v4, v7);
  sub_37010(v5);
  sub_36F20(v5, v5, v7);
  if ( !(unsigned int)sub_36870(v5, v6) )
    sub_36F20(a1, a1, &unk_5BAC0);
  sub_37010(v5);
  sub_36F20(v5, v5, v7);
  if ( (unsigned int)sub_36870(v5, v6) )
  {
    if ( (unsigned char)sub_36AE0(a1) != (v3 == 0) )
      sub_36E20(a1, a1);
    sub_36F20(a1 + 384, a1, a1 + 128);
  }
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_pack @ 0x358b0
double crypto_sign_ed25519_ref_pack(long long a1, long long a2)
{
  char v3[128]; // [rsp+0h] [rbp-1B8h] BYREF
  char v4[128]; // [rsp+80h] [rbp-138h] BYREF
  char v5[136]; // [rsp+100h] [rbp-B8h] BYREF
  unsigned long long v6; // [rsp+188h] [rbp-30h]

  v6 = __readfsqword(0x28u);
  sub_37020(v5, a2 + 256);
  sub_36F20(v3, a2, v5);
  sub_36F20(v4, a2 + 128, v5);
  sub_365D0(a1, v4);
  *(char *)(a1 + 31) ^= (unsigned char)sub_36AE0(v3) << 7;
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_isneutral_vartime @ 0x359f0
double crypto_sign_ed25519_ref_isneutral_vartime(long long a1)
{
  sub_36710();
  sub_36870(a1 + 128, a1 + 256);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_double_scalarmult_vartime @ 0x35ab0
double crypto_sign_ed25519_ref_double_scalarmult_vartime(long long *a1, const void *a2, char *a3, const void *a4, char *a5)
{
  char *v6; // rbx
  unsigned long long v7; // rcx
  long long v9[4]; // [rsp+0h] [rbp-22F8h] BYREF
  char *v10; // [rsp+20h] [rbp-22D8h]
  char *v11; // [rsp+28h] [rbp-22D0h]
  char v12[512]; // [rsp+30h] [rbp-22C8h] BYREF
  long long v13[19]; // [rsp+230h] [rbp-20C8h] BYREF
  char v14[512]; // [rsp+430h] [rbp-1EC8h] BYREF
  char v15[512]; // [rsp+630h] [rbp-1CC8h] BYREF
  char v16[512]; // [rsp+830h] [rbp-1AC8h] BYREF
  char v17[512]; // [rsp+A30h] [rbp-18C8h] BYREF
  char v18[512]; // [rsp+C30h] [rbp-16C8h] BYREF
  char v19[512]; // [rsp+E30h] [rbp-14C8h] BYREF
  char v20[512]; // [rsp+1030h] [rbp-12C8h] BYREF
  char v21[152]; // [rsp+1230h] [rbp-10C8h] BYREF
  char v22[512]; // [rsp+1430h] [rbp-EC8h] BYREF
  char v23[512]; // [rsp+1630h] [rbp-CC8h] BYREF
  char v24[512]; // [rsp+1830h] [rbp-AC8h] BYREF
  char v25[512]; // [rsp+1A30h] [rbp-8C8h] BYREF
  char v26[512]; // [rsp+1C30h] [rbp-6C8h] BYREF
  char v27[512]; // [rsp+1E30h] [rbp-4C8h] BYREF
  char v28[512]; // [rsp+2030h] [rbp-2C8h] BYREF
  char v29[125]; // [rsp+2230h] [rbp-C8h] BYREF
  char v30; // [rsp+22ADh] [rbp-4Bh] BYREF
  unsigned char v31; // [rsp+22AEh] [rbp-4Ah]
  unsigned long long v32; // [rsp+22B8h] [rbp-40h]

  v10 = a5;
  v11 = a3;
  v32 = __readfsqword(0x28u);
  sub_35300((long long)v13);
  qmemcpy(v14, a2, sizeof(v14));
  sub_35150((long long)v12, (long long)a2);
  sub_34CA0((long long)v15, (long long)v12);
  sub_34CD0((long long)v12, (long long)v14, (long long)v15);
  sub_34CA0((long long)v16, (long long)v12);
  qmemcpy(v17, a4, sizeof(v17));
  v9[3] = v14;
  sub_34CD0((long long)v12, (long long)v14, (long long)v17);
  v9[2] = v18;
  sub_34CA0((long long)v18, (long long)v12);
  sub_34CD0((long long)v12, (long long)v15, (long long)v17);
  sub_34CA0((long long)v19, (long long)v12);
  v9[1] = v17;
  sub_34CD0((long long)v12, (long long)v16, (long long)v17);
  sub_34CA0((long long)v20, (long long)v12);
  sub_35150((long long)v12, (long long)a4);
  sub_34CA0((long long)v21, (long long)v12);
  v9[0] = v14;
  sub_34CD0((long long)v12, (long long)v14, (long long)v21);
  sub_34CA0((long long)v22, (long long)v12);
  sub_35150((long long)v12, (long long)v18);
  sub_34CA0((long long)v23, (long long)v12);
  sub_34CD0((long long)v12, (long long)v16, (long long)v21);
  sub_34CA0((long long)v24, (long long)v12);
  sub_34CD0((long long)v12, (long long)v17, (long long)v21);
  sub_34CA0((long long)v25, (long long)v12);
  sub_34CD0((long long)v12, (long long)v14, (long long)v25);
  sub_34CA0((long long)v26, (long long)v12);
  sub_34CD0((long long)v12, (long long)v15, (long long)v25);
  v6 = &v30;
  sub_34CA0((long long)v27, (long long)v12);
  sub_34CD0((long long)v12, (long long)v16, (long long)v25);
  sub_34CA0((long long)v28, (long long)v12);
  sub_349B0(v29, v11, v10);
  v7 = ((unsigned long long)v31 << 9) + 8896;
  *a1 = v13[64 * (unsigned long long)v31];
  a1[63] = *(long long *)((char *)&v9[-979] + v7);
  qmemcpy(
    (void *)((unsigned long long)(a1 + 1) & 0xFFFFFFFFFFFFFFF8LL),
    (const void *)((char *)&v9[-1042] + v7 - ((char *)a1 - ((unsigned long long)(a1 + 1) & 0xFFFFFFFFFFFFFFF8LL))),
    8LL * (((unsigned int)a1 - (((int)a1 + 8) & 0xFFFFFFF8) + 512) >> 3));
  while ( 1 )
  {
    sub_35150((long long)v12, (long long)a1);
    sub_34C40((long long)a1, (long long)v12);
    sub_35150((long long)v12, (long long)a1);
    if ( *v6 )
    {
      sub_34CA0((long long)a1, (long long)v12);
      sub_34CD0((long long)v12, (long long)a1, (long long)&v13[64 * (unsigned long long)(unsigned char)*v6]);
    }
    if ( v6 == v29 )
      break;
    sub_34C40((long long)a1, (long long)v12);
    --v6;
  }
  sub_34CA0((long long)a1, (long long)v12);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_scalarmult_base @ 0x35eb0
double crypto_sign_ed25519_ref_scalarmult_base(long long a1, char *a2)
{
  long long v2; // rbx
  long long v3; // rsi
  char _0[256]; // [rsp+0h] [rbp+0h] BYREF
  char vars100; // [rsp+100h] [rbp+100h] BYREF
  unsigned long long vars158; // [rsp+158h] [rbp+158h]

  v2 = 1;
  vars158 = __readfsqword(0x28u);
  sub_34610(&vars100, a2);
  sub_35360(a1, 0);
  sub_36C00(a1 + 256);
  sub_36F20(a1 + 384, a1, a1 + 128);
  do
  {
    v3 = v2++;
    sub_35360((long long)_0, v3);
    sub_34ED0(a1, (long long)_0);
  }
  while ( v2 != 85 );
  return 0.0;
}


// Function: times19 @ 0x36090
double times19()
{
  return 0.0;
}


// Function: times38 @ 0x36120
double times38()
{
  return 0.0;
}


// Function: reduce_mul @ 0x36290
double reduce_mul(unsigned int *a1)
{
  int i; // ebp
  int v2; // eax
  unsigned int v3; // eax
  unsigned int *v4; // rdx

  for ( i = 2; ; i = 1 )
  {
    a1[31] &= 0x7Fu;
    sub_36090();
    v3 = *a1 + v2;
    v4 = a1;
    *a1 = v3;
    while ( 1 )
    {
      *v4 = (unsigned char)*v4;
      v4[1] += v3 >> 8;
      if ( a1 + 31 == ++v4 )
        break;
      v3 = *v4;
    }
    if ( i == 1 )
      break;
  }
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_freeze @ 0x36410
double crypto_sign_ed25519_ref_fe25519_freeze(unsigned int *a1)
{
  unsigned int v1; // r14d
  unsigned int *v2; // rbx
  unsigned int *v3; // rbp
  int v4; // eax
  int v5; // r13d
  double v6; // xmm0_8
  int v7; // eax
  int v8; // eax

  v1 = a1[31];
  v2 = a1 + 30;
  v3 = a1 + 30;
  sub_36000();
  v5 = v4;
  do
  {
    --v3;
    v6 = sub_36000();
    v5 &= v7;
  }
  while ( v3 != a1 );
  v8 = -(v5 & sub_36380(*a1, 255, v6));
  a1[31] = v1 - (v8 & 0x7F);
  do
    *v2-- -= (unsigned char)v8;
  while ( v2 != a1 );
  *v2 -= v8 & 0xED;
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_unpack @ 0x36520
double crypto_sign_ed25519_ref_fe25519_unpack(long long a1, long long a2)
{
  long long i; // rax

  for ( i = 0; i != 32; ++i )
    *(int *)(a1 + 4 * i) = *(unsigned char *)(a2 + i);
  *(int *)(a1 + 124) &= 0x7Fu;
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_pack @ 0x365d0
double crypto_sign_ed25519_ref_fe25519_pack(long long a1, const __m128i *a2)
{
  __m128i v2; // xmm0
  __m128i v3; // xmm1
  __m128i v4; // xmm2
  __m128i v5; // xmm3
  __m128i v6; // xmm4
  __m128i v7; // xmm5
  __m128i v8; // xmm6
  __m128i v9; // xmm7
  long long i; // rax
  _OWORD v12[8]; // [rsp+0h] [rbp-A8h] BYREF
  unsigned long long v13; // [rsp+88h] [rbp-20h]

  v2 = _mm_loadu_si128(a2);
  v3 = _mm_loadu_si128(a2 + 1);
  v4 = _mm_loadu_si128(a2 + 2);
  v5 = _mm_loadu_si128(a2 + 3);
  v6 = _mm_loadu_si128(a2 + 4);
  v7 = _mm_loadu_si128(a2 + 5);
  v13 = __readfsqword(0x28u);
  v8 = _mm_loadu_si128(a2 + 6);
  v9 = _mm_loadu_si128(a2 + 7);
  v12[0] = v2;
  v12[1] = v3;
  v12[2] = v4;
  v12[3] = v5;
  v12[4] = v6;
  v12[5] = v7;
  v12[6] = v8;
  v12[7] = v9;
  sub_36410((unsigned int *)v12);
  for ( i = 0; i != 32; ++i )
    *(char *)(a1 + i) = *((int *)v12 + i);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_iszero @ 0x36710
double crypto_sign_ed25519_ref_fe25519_iszero(const __m128i *a1)
{
  __m128i v1; // xmm0
  __m128i v2; // xmm1
  __m128i v3; // xmm2
  __m128i v4; // xmm3
  char *v5; // rbx
  __m128i v6; // xmm4
  __m128i v7; // xmm5
  __m128i v8; // xmm6
  __m128i v9; // xmm7
  int v10; // eax
  int v11; // r12d
  int v12; // eax
  _OWORD v14[8]; // [rsp+0h] [rbp-A8h] BYREF
  char v15; // [rsp+80h] [rbp-28h] BYREF
  unsigned long long v16; // [rsp+88h] [rbp-20h]

  v1 = _mm_loadu_si128(a1);
  v2 = _mm_loadu_si128(a1 + 1);
  v3 = _mm_loadu_si128(a1 + 2);
  v4 = _mm_loadu_si128(a1 + 3);
  v5 = (char *)v14 + 4;
  v6 = _mm_loadu_si128(a1 + 4);
  v7 = _mm_loadu_si128(a1 + 5);
  v16 = __readfsqword(0x28u);
  v8 = _mm_loadu_si128(a1 + 6);
  v9 = _mm_loadu_si128(a1 + 7);
  v14[0] = v1;
  v14[1] = v2;
  v14[2] = v3;
  v14[3] = v4;
  v14[4] = v6;
  v14[5] = v7;
  v14[6] = v8;
  v14[7] = v9;
  sub_36410((unsigned int *)v14);
  sub_36000();
  v11 = v10;
  do
  {
    v5 += 4;
    sub_36000();
    v11 &= v12;
  }
  while ( v5 != &v15 );
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_iseq_vartime @ 0x36870
double crypto_sign_ed25519_ref_fe25519_iseq_vartime(const __m128i *a1, const __m128i *a2)
{
  __m128i v2; // xmm0
  __m128i v3; // xmm1
  __m128i v4; // xmm2
  __m128i v5; // xmm3
  __m128i v6; // xmm4
  __m128i v7; // xmm5
  __m128i v8; // xmm6
  __m128i v9; // xmm7
  __m128i v10; // xmm0
  __m128i v11; // xmm1
  __m128i v12; // xmm2
  __m128i v13; // xmm3
  __m128i v14; // xmm4
  __m128i v15; // xmm5
  __m128i v16; // xmm7
  long long i; // rax
  _OWORD v19[8]; // [rsp+0h] [rbp-128h] BYREF
  _OWORD v20[8]; // [rsp+80h] [rbp-A8h] BYREF
  unsigned long long v21; // [rsp+108h] [rbp-20h]

  v2 = _mm_loadu_si128(a1);
  v3 = _mm_loadu_si128(a1 + 1);
  v4 = _mm_loadu_si128(a1 + 2);
  v5 = _mm_loadu_si128(a1 + 3);
  v21 = __readfsqword(0x28u);
  v6 = _mm_loadu_si128(a1 + 4);
  v7 = _mm_loadu_si128(a1 + 5);
  v19[0] = v2;
  v8 = _mm_loadu_si128(a1 + 6);
  v9 = _mm_loadu_si128(a1 + 7);
  v19[1] = v3;
  v10 = _mm_loadu_si128(a2);
  v11 = _mm_loadu_si128(a2 + 1);
  v19[2] = v4;
  v19[3] = v5;
  v12 = _mm_loadu_si128(a2 + 2);
  v13 = _mm_loadu_si128(a2 + 3);
  v19[4] = v6;
  v14 = _mm_loadu_si128(a2 + 4);
  v19[5] = v7;
  v15 = _mm_loadu_si128(a2 + 5);
  v20[0] = v10;
  v20[1] = v11;
  v20[2] = v12;
  v20[3] = v13;
  v20[4] = v14;
  v19[6] = v8;
  v19[7] = v9;
  v20[5] = v15;
  v16 = _mm_loadu_si128(a2 + 7);
  v20[6] = _mm_loadu_si128(a2 + 6);
  v20[7] = v16;
  sub_36410((unsigned int *)v19);
  sub_36410((unsigned int *)v20);
  for ( i = 0; i != 128; i += 4 )
  {
    if ( *(int *)((char *)v19 + i) != *(int *)((char *)v20 + i) )
      break;
  }
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_cmov @ 0x36a30
double crypto_sign_ed25519_ref_fe25519_cmov(long long a1, long long a2, unsigned char a3)
{
  long long v3; // rax
  int v4; // edx

  v3 = 0;
  v4 = -a3;
  do
  {
    *(int *)(a1 + v3) ^= v4 & (*(int *)(a1 + v3) ^ *(int *)(a2 + v3));
    v3 += 4;
  }
  while ( v3 != 128 );
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_getparity @ 0x36ae0
double crypto_sign_ed25519_ref_fe25519_getparity(const __m128i *a1)
{
  __m128i v1; // xmm0
  __m128i v2; // xmm1
  __m128i v3; // xmm2
  __m128i v4; // xmm3
  __m128i v5; // xmm4
  __m128i v6; // xmm5
  __m128i v7; // xmm6
  __m128i v8; // xmm7
  _OWORD v10[8]; // [rsp+0h] [rbp-98h] BYREF
  unsigned long long v11; // [rsp+88h] [rbp-10h]

  v1 = _mm_loadu_si128(a1);
  v2 = _mm_loadu_si128(a1 + 1);
  v3 = _mm_loadu_si128(a1 + 2);
  v4 = _mm_loadu_si128(a1 + 3);
  v5 = _mm_loadu_si128(a1 + 4);
  v6 = _mm_loadu_si128(a1 + 5);
  v11 = __readfsqword(0x28u);
  v7 = _mm_loadu_si128(a1 + 6);
  v8 = _mm_loadu_si128(a1 + 7);
  v10[0] = v1;
  v10[1] = v2;
  v10[2] = v3;
  v10[3] = v4;
  v10[4] = v5;
  v10[5] = v6;
  v10[6] = v7;
  v10[7] = v8;
  sub_36410((unsigned int *)v10);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_setone @ 0x36c00
double crypto_sign_ed25519_ref_fe25519_setone(int *a1)
{
  int *v1; // rax

  *a1 = 1;
  v1 = a1 + 1;
  do
    *v1++ = 0;
  while ( v1 != a1 + 32 );
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_setzero @ 0x36cb0
double crypto_sign_ed25519_ref_fe25519_setzero(int *a1)
{
  int *v1; // rax

  v1 = a1 + 32;
  do
    *a1++ = 0;
  while ( a1 != v1 );
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_add @ 0x36d50
double crypto_sign_ed25519_ref_fe25519_add(unsigned int *a1, long long a2, long long a3)
{
  long long i; // rax

  for ( i = 0; i != 32; ++i )
    a1[i] = *(int *)(a2 + i * 4) + *(int *)(a3 + i * 4);
  return sub_361B0(a1);
}


// Function: crypto_sign_ed25519_ref_fe25519_sub @ 0x36d80
double crypto_sign_ed25519_ref_fe25519_sub(unsigned int *a1, int *a2, long long a3)
{
  int v3; // ecx
  long long i; // rax
  long long j; // rax
  char v7[124]; // [rsp+0h] [rbp-98h]
  int v8; // [rsp+7Ch] [rbp-1Ch]
  unsigned long long v9; // [rsp+88h] [rbp-10h]

  v9 = __readfsqword(0x28u);
  v3 = *a2 + 474;
  v8 = a2[31] + 254;
  for ( i = 1; i != 31; ++i )
    *(int *)&v7[i * 4] = a2[i] + 510;
  for ( j = 0; ; v3 = *(int *)&v7[j * 4] )
  {
    a1[j] = v3 - *(int *)(a3 + j * 4);
    if ( ++j == 32 )
      break;
  }
  return sub_361B0(a1);
}


// Function: crypto_sign_ed25519_ref_fe25519_neg @ 0x36e20
double crypto_sign_ed25519_ref_fe25519_neg(unsigned int *a1, long long a2)
{
  long long i; // rax
  char v4[136]; // [rsp+0h] [rbp-A8h] BYREF
  unsigned long long v5; // [rsp+88h] [rbp-20h]

  v5 = __readfsqword(0x28u);
  for ( i = 0; i != 128; i += 4 )
    *(int *)&v4[i] = *(int *)(a2 + i);
  sub_36CB0(a1);
  sub_36D80(a1, a1, (long long)v4);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_mul @ 0x36f20
double crypto_sign_ed25519_ref_fe25519_mul(unsigned int *a1, long long a2, long long a3)
{
  char *v6; // rax
  long long i; // rsi
  int v8; // edi
  long long j; // rax
  int v10; // ecx
  int v11; // edx
  unsigned int *v12; // r13
  char *v13; // rbx
  int v14; // eax
  int v16[32]; // [rsp+0h] [rbp-138h] BYREF
  char v17; // [rsp+80h] [rbp-B8h] BYREF
  char v18[12]; // [rsp+FCh] [rbp-3Ch] BYREF
  unsigned long long v19; // [rsp+108h] [rbp-30h]

  v19 = __readfsqword(0x28u);
  v6 = v16;
  do
  {
    *(int *)v6 = 0;
    v6 += 4;
  }
  while ( v6 != v18 );
  for ( i = 0; i != 32; ++i )
  {
    v8 = *(int *)(a2 + 4 * i);
    for ( j = 0; j != 32; ++j )
    {
      v10 = *(int *)(a3 + 4 * j);
      v11 = j + i;
      v16[v11] += v8 * v10;
    }
  }
  v12 = a1;
  v13 = &v17;
  do
  {
    v13 += 4;
    ++v12;
    sub_36120();
    *(v12 - 1) = *((int *)v13 - 33) + v14;
  }
  while ( v13 != v18 );
  a1[31] = v16[31];
  return sub_36290(a1);
}


// Function: crypto_sign_ed25519_ref_fe25519_square @ 0x37010
double crypto_sign_ed25519_ref_fe25519_square(unsigned int *a1, long long a2)
{
  return sub_36F20(a1, a2, a2);
}


// Function: crypto_sign_ed25519_ref_fe25519_invert @ 0x37020
double crypto_sign_ed25519_ref_fe25519_invert(unsigned int *a1, long long a2)
{
  int v2; // ebx
  int v3; // ebx
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  int v7; // ebx
  unsigned int v9[32]; // [rsp+10h] [rbp-548h] BYREF
  unsigned int v10[32]; // [rsp+90h] [rbp-4C8h] BYREF
  unsigned int v11[32]; // [rsp+110h] [rbp-448h] BYREF
  unsigned int v12[32]; // [rsp+190h] [rbp-3C8h] BYREF
  unsigned int v13[32]; // [rsp+210h] [rbp-348h] BYREF
  unsigned int v14[32]; // [rsp+290h] [rbp-2C8h] BYREF
  unsigned int v15[32]; // [rsp+310h] [rbp-248h] BYREF
  unsigned int v16[32]; // [rsp+390h] [rbp-1C8h] BYREF
  unsigned int v17[32]; // [rsp+410h] [rbp-148h] BYREF
  unsigned int v18[34]; // [rsp+490h] [rbp-C8h] BYREF
  unsigned long long v19; // [rsp+518h] [rbp-40h]

  v19 = __readfsqword(0x28u);
  sub_37010(v9, a2);
  sub_37010(v18, (long long)v9);
  sub_37010(v17, (long long)v18);
  sub_36F20(v10, (long long)v17, a2);
  sub_36F20(v11, (long long)v10, (long long)v9);
  v2 = 4;
  sub_37010(v17, (long long)v11);
  sub_36F20(v12, (long long)v17, (long long)v10);
  sub_37010(v17, (long long)v12);
  sub_37010(v18, (long long)v17);
  sub_37010(v17, (long long)v18);
  sub_37010(v18, (long long)v17);
  sub_37010(v17, (long long)v18);
  sub_36F20(v13, (long long)v17, (long long)v12);
  sub_37010(v17, (long long)v13);
  sub_37010(v18, (long long)v17);
  do
  {
    sub_37010(v17, (long long)v18);
    sub_37010(v18, (long long)v17);
    --v2;
  }
  while ( v2 );
  v3 = 9;
  sub_36F20(v14, (long long)v18, (long long)v13);
  sub_37010(v17, (long long)v14);
  sub_37010(v18, (long long)v17);
  do
  {
    sub_37010(v17, (long long)v18);
    sub_37010(v18, (long long)v17);
    --v3;
  }
  while ( v3 );
  v4 = 4;
  sub_36F20(v17, (long long)v18, (long long)v14);
  sub_37010(v18, (long long)v17);
  sub_37010(v17, (long long)v18);
  do
  {
    sub_37010(v18, (long long)v17);
    sub_37010(v17, (long long)v18);
    --v4;
  }
  while ( v4 );
  v5 = 24;
  sub_36F20(v15, (long long)v17, (long long)v13);
  sub_37010(v17, (long long)v15);
  sub_37010(v18, (long long)v17);
  do
  {
    sub_37010(v17, (long long)v18);
    sub_37010(v18, (long long)v17);
    --v5;
  }
  while ( v5 );
  v6 = 49;
  sub_36F20(v16, (long long)v18, (long long)v15);
  sub_37010(v18, (long long)v16);
  sub_37010(v17, (long long)v18);
  do
  {
    sub_37010(v18, (long long)v17);
    sub_37010(v17, (long long)v18);
    --v6;
  }
  while ( v6 );
  v7 = 24;
  sub_36F20(v18, (long long)v17, (long long)v16);
  sub_37010(v17, (long long)v18);
  sub_37010(v18, (long long)v17);
  do
  {
    sub_37010(v17, (long long)v18);
    sub_37010(v18, (long long)v17);
    --v7;
  }
  while ( v7 );
  sub_36F20(v17, (long long)v18, (long long)v15);
  sub_37010(v18, (long long)v17);
  sub_37010(v17, (long long)v18);
  sub_37010(v18, (long long)v17);
  sub_37010(v17, (long long)v18);
  sub_37010(v18, (long long)v17);
  sub_36F20(a1, (long long)v18, (long long)v11);
  return 0.0;
}


// Function: crypto_sign_ed25519_ref_fe25519_pow2523 @ 0x373e0
double crypto_sign_ed25519_ref_fe25519_pow2523(unsigned int *a1, long long a2)
{
  int v2; // ebx
  int v3; // ebx
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  int v7; // ebx
  int v8; // ebx
  unsigned int v10[32]; // [rsp+0h] [rbp-4C8h] BYREF
  unsigned int v11[32]; // [rsp+80h] [rbp-448h] BYREF
  unsigned int v12[32]; // [rsp+100h] [rbp-3C8h] BYREF
  unsigned int v13[32]; // [rsp+180h] [rbp-348h] BYREF
  unsigned int v14[32]; // [rsp+200h] [rbp-2C8h] BYREF
  unsigned int v15[32]; // [rsp+280h] [rbp-248h] BYREF
  unsigned int v16[32]; // [rsp+300h] [rbp-1C8h] BYREF
  unsigned int v17[32]; // [rsp+380h] [rbp-148h] BYREF
  unsigned int v18[34]; // [rsp+400h] [rbp-C8h] BYREF
  unsigned long long v19; // [rsp+488h] [rbp-40h]

  v19 = __readfsqword(0x28u);
  sub_37010(v10, a2);
  sub_37010(v18, (long long)v10);
  sub_37010(v18, (long long)v18);
  sub_36F20(v11, (long long)v18, a2);
  sub_36F20(v12, (long long)v11, (long long)v10);
  sub_37010(v18, (long long)v12);
  sub_36F20(v13, (long long)v18, (long long)v11);
  v2 = 4;
  sub_37010(v18, (long long)v13);
  do
  {
    sub_37010(v18, (long long)v18);
    --v2;
  }
  while ( v2 );
  v3 = 9;
  sub_36F20(v14, (long long)v18, (long long)v13);
  sub_37010(v18, (long long)v14);
  do
  {
    sub_37010(v18, (long long)v18);
    --v3;
  }
  while ( v3 );
  v4 = 19;
  sub_36F20(v15, (long long)v18, (long long)v14);
  sub_37010(v18, (long long)v15);
  do
  {
    sub_37010(v18, (long long)v18);
    --v4;
  }
  while ( v4 );
  v5 = 9;
  sub_36F20(v18, (long long)v18, (long long)v15);
  sub_37010(v18, (long long)v18);
  do
  {
    sub_37010(v18, (long long)v18);
    --v5;
  }
  while ( v5 );
  v6 = 49;
  sub_36F20(v16, (long long)v18, (long long)v14);
  sub_37010(v18, (long long)v16);
  do
  {
    sub_37010(v18, (long long)v18);
    --v6;
  }
  while ( v6 );
  v7 = 99;
  sub_36F20(v17, (long long)v18, (long long)v16);
  sub_37010(v18, (long long)v17);
  do
  {
    sub_37010(v18, (long long)v18);
    --v7;
  }
  while ( v7 );
  v8 = 49;
  sub_36F20(v18, (long long)v18, (long long)v17);
  sub_37010(v18, (long long)v18);
  do
  {
    sub_37010(v18, (long long)v18);
    --v8;
  }
  while ( v8 );
  sub_36F20(v18, (long long)v18, (long long)v16);
  sub_37010(v18, (long long)v18);
  sub_37010(v18, (long long)v18);
  sub_36F20(a1, (long long)v18, a2);
  return 0.0;
}


// Function: closefrom_fallback @ 0x376e0
double closefrom_fallback(int a1)
{
  long long v1; // rbp
  long long v2; // rbx

  v1 = a1;
  v2 = sysconf(4);
  if ( v2 < 0 )
    v2 = 256;
  if ( v2 > a1 )
  {
    do
    {
      close(v1);
      v1 = sub_3DA00(v1, 1);
    }
    while ( v2 > v1 );
  }
  return 0.0;
}


// Function: EVP_CIPHER_CTX_get_iv @ 0x37980
double EVP_CIPHER_CTX_get_iv(long long a1, void *a2, size_t a3)
{
  int iv_length; // eax
  const void *v6; // rax

  if ( a1 )
  {
    if ( (int)EVP_CIPHER_CTX_get_iv_length(a1) >= 0 )
    {
      iv_length = EVP_CIPHER_CTX_get_iv_length(a1);
      if ( a3 <= 0x10 && iv_length == a3 && a3 && a2 )
      {
        v6 = (const void *)EVP_CIPHER_CTX_iv(a1);
        memcpy(a2, v6, a3);
      }
    }
  }
  return 0.0;
}


// Function: EVP_CIPHER_CTX_set_iv @ 0x37a90
double EVP_CIPHER_CTX_set_iv(long long a1, const void *a2, size_t a3)
{
  int iv_length; // eax
  void *v6; // rax

  if ( a1 )
  {
    if ( (int)EVP_CIPHER_CTX_get_iv_length(a1) >= 0 )
    {
      iv_length = EVP_CIPHER_CTX_get_iv_length(a1);
      if ( a3 <= 0x10 && iv_length == a3 && a3 && a2 )
      {
        v6 = (void *)EVP_CIPHER_CTX_iv_noconst(a1);
        memcpy(v6, a2, a3);
      }
    }
  }
  return 0.0;
}


// Function: _rs_rekey @ 0x38440
double _rs_rekey(long long a1, long long a2)
{
  long long v3; // rdi
  long long i; // rax
  long long v5; // rdx
  long long *v6; // rax

  sub_37C40(qword_68218, qword_68218 + 64, qword_68218 + 64, 1024);
  v3 = qword_68218;
  if ( a1 && a2 )
  {
    for ( i = 0; i != a2; ++i )
      *(char *)(v3 + i + 64) ^= *(char *)(a1 + i);
  }
  sub_383F0(v3 + 64);
  v5 = qword_68218;
  v6 = addr;
  *(long long *)(qword_68218 + 96) = 0;
  *(_OWORD *)(v5 + 64) = 0;
  *(_OWORD *)(v5 + 80) = 0;
  *v6 = 984;
  return 0.0;
}


// Function: _rs_stir @ 0x38550
double _rs_stir(double a1)
{
  long long v1; // r8
  long long v2; // rdi
  int v3; // eax
  int v5; // [rsp+Ch] [rbp-3Ch] BYREF
  char v6[40]; // [rsp+10h] [rbp-38h] BYREF
  unsigned long long v7; // [rsp+38h] [rbp-10h]

  v7 = __readfsqword(0x28u);
  v5 = 0;
  if ( (unsigned int)getentropy(v6, 40) == -1 )
    sub_380E0();
  if ( addr )
    a1 = sub_38440((long long)v6, 40);
  else
    sub_383F0(v6);
  __explicit_bzero_chk(v6, 40, 40, a1);
  *(long long *)addr = 0;
  v1 = qword_68218;
  v2 = qword_68218 + 72;
  v3 = qword_68218;
  *(long long *)(qword_68218 + 64) = 0;
  *(long long *)(v1 + 1080) = 0;
  memset((void *)(v2 & 0xFFFFFFFFFFFFFFF8LL), 0, 8LL * ((v3 - ((unsigned int)v2 & 0xFFFFFFF8) + 1088) >> 3));
  sub_37C40(v1, &v5, &v5, 4);
  *((long long *)addr + 1) = (v5 & 0xFFFFFu) + 0x100000;
  return 0.0;
}


// Function: _rs_stir_if_needed @ 0x386e0
double _rs_stir_if_needed(unsigned long long a1, double a2)
{
  long long *v2; // rax
  unsigned long long v3; // rdx

  sub_38120();
  v2 = addr;
  if ( addr && (v3 = *((long long *)addr + 1), v3 > a1) || (sub_38550(a2), v2 = addr, v3 = *((long long *)addr + 1), v3 > a1) )
  {
    v2[1] = v3 - a1;
    return 0.0;
  }
  else
  {
    *((long long *)addr + 1) = 0;
    return 0.0;
  }
}


// Function: _rs_random_u32 @ 0x38840
double _rs_random_u32(int *a1, double a2)
{
  long long v2; // rdx
  long long v3; // rax

  sub_386E0(4u, a2);
  v2 = *(long long *)addr;
  if ( *(long long *)addr <= 3u )
  {
    sub_38440(0, 0);
    v2 = *(long long *)addr;
  }
  v3 = qword_68218 - v2;
  *a1 = *(int *)(qword_68218 - v2 + 1088);
  *(int *)(v3 + 1088) = 0;
  *(long long *)addr -= 4LL;
  return 0.0;
}


// Function: _rs_random_buf @ 0x38930
double _rs_random_buf(char *dest, unsigned long long a2, double a3)
{
  size_t v4; // rbx
  size_t v5; // rax
  size_t v6; // rbp
  void *v7; // rdi
  void *v8; // r14

  v4 = a2;
  sub_386E0(a2, a3);
  if ( a2 )
  {
    do
    {
      while ( 1 )
      {
        v5 = *(long long *)addr;
        if ( *(long long *)addr )
        {
          v6 = v4;
          v7 = dest;
          if ( v5 <= v4 )
            v6 = *(long long *)addr;
          v8 = (void *)(qword_68218 + 1024 - v5 + 64);
          dest += v6;
          v4 -= v6;
          memcpy(v7, v8, v6);
          memset(v8, 0, v6);
          *(long long *)addr -= v6;
          if ( *(long long *)addr )
            break;
        }
        sub_38440(0, 0);
        if ( !v4 )
          return 0.0;
      }
    }
    while ( v4 );
  }
  return 0.0;
}


// Function: arc4random @ 0x38a60
double arc4random(double a1)
{
  int v2; // [rsp+4h] [rbp-14h] BYREF
  unsigned long long v3; // [rsp+8h] [rbp-10h]

  v3 = __readfsqword(0x28u);
  sub_38840(&v2, a1);
  return 0.0;
}


// Function: __b64_ntop @ 0x38b30
double __b64_ntop(unsigned char *a1, unsigned long long a2, long long a3, unsigned long long a4)
{
  unsigned long long v4; // r9
  unsigned char v7; // al
  unsigned char *v8; // rsi
  unsigned char v9; // r11
  char v10; // cl
  char v11; // bl
  char v12; // dl
  char v13; // r11
  char v14; // dl
  unsigned long long v15; // rax
  unsigned char v16; // cl
  unsigned char v17; // dl
  unsigned char v18; // bl
  char v19; // bl
  char v20; // cl
  char v21; // dl
  unsigned char v23; // dl
  unsigned char v24; // di
  char v25; // cl
  char v26; // di
  unsigned char v27; // cl
  unsigned long long v28; // r11
  char v29; // si
  char v30; // dl
  char v31; // dl
  char *v32; // rsi
  unsigned long long v33; // rax
  char v34; // dl

  v4 = a2;
  if ( a2 <= 2 )
  {
    v8 = a1;
    v15 = 0;
  }
  else
  {
    v7 = a1[1];
    v8 = a1 + 3;
    v4 -= 3LL;
    v9 = a1[2];
    v10 = (v7 >> 4) + ((16 * *a1) & 0x30);
    v11 = *a1 >> 2;
    v12 = v9 >> 6;
    v13 = v9 & 0x3F;
    v14 = ((4 * v7) & 0x3C) + v12;
    v15 = 4;
    if ( a4 <= 3 )
      return 0.0;
    while ( 1 )
    {
      v19 = aAbcdefghijklmn[v11 & 0x3F];
      *(char *)(a3 + v15 - 3) = aAbcdefghijklmn[v10 & 0x7F];
      v20 = aAbcdefghijklmn[v14 & 0x7F];
      *(char *)(a3 + v15 - 4) = v19;
      v21 = aAbcdefghijklmn[v13 & 0x3F];
      *(char *)(a3 + v15 - 2) = v20;
      *(char *)(a3 + v15 - 1) = v21;
      if ( v4 <= 2 )
        break;
      v16 = *v8;
      v17 = v8[1];
      v15 += 4LL;
      v8 += 3;
      v4 -= 3LL;
      v18 = v16;
      v10 = (v17 >> 4) + ((16 * v16) & 0x30);
      v11 = v18 >> 2;
      v13 = *(v8 - 1) & 0x3F;
      v14 = (*(v8 - 1) >> 6) + ((4 * v17) & 0x3C);
      if ( a4 < v15 )
        return 0.0;
    }
  }
  if ( v4 )
  {
    v23 = *v8;
    if ( v4 == 2 )
    {
      v24 = v8[1];
      v25 = 4 * v24;
      v26 = v24 >> 4;
      v27 = v25 & 0x3C;
    }
    else
    {
      v27 = 0;
      v26 = 0;
    }
    v28 = v15 + 4;
    v29 = v23 >> 2;
    v30 = v26 + ((16 * v23) & 0x30);
    if ( v15 + 4 > a4 )
      return 0.0;
    v31 = aAbcdefghijklmn[v30 & 0x7F];
    *(char *)(a3 + v15) = aAbcdefghijklmn[v29 & 0x3F];
    v32 = (char *)(a3 + v15 + 2);
    *(char *)(a3 + v15 + 1) = v31;
    v33 = v15 + 3;
    v34 = 61;
    if ( v4 != 1 )
      v34 = aAbcdefghijklmn[v27];
    *v32 = v34;
    *(char *)(a3 + v33) = 61;
    v15 = v28;
  }
  if ( v15 < a4 )
  {
    *(char *)(a3 + v15) = 0;
    return 0.0;
  }
  return 0.0;
}


// Function: __b64_pton @ 0x38de0
double __b64_pton(char *a1, long long a2, unsigned long long a3, double a4)
{
  int v5; // r13d
  int v7; // esi
  char *v8; // rbp
  char v9; // dl
  const unsigned short **v10; // rax
  const unsigned short *v11; // rcx
  const unsigned short **v12; // rbx
  char *v13; // rdi
  const unsigned short *v14; // rcx
  char *v15; // r13
  unsigned long long v16; // r12
  unsigned long long v17; // rbp
  long long v18; // rax
  long long v19; // rsi
  unsigned int v20; // eax
  long long v21; // r13
  long long v22; // rax
  long long v23; // rsi
  long long v24; // rsi
  long long v25; // rsi
  long long v27; // rsi
  long long v28; // rax
  char *v29; // rdx
  char *v30; // rsi
  char v31; // [rsp+8h] [rbp-50h]
  const unsigned short *v32; // [rsp+8h] [rbp-50h]
  const unsigned short *v33; // [rsp+8h] [rbp-50h]
  unsigned int v34; // [rsp+14h] [rbp-44h]

  v5 = 0;
  v34 = 0;
LABEL_2:
  v7 = *a1;
  v8 = a1 + 1;
  v9 = *a1;
  if ( *a1 )
  {
    while ( 1 )
    {
      v31 = v9;
      v10 = __ctype_b_loc();
      v11 = *v10;
      v12 = v10;
      if ( ((*v10)[v31] & 0x2000) == 0 )
        break;
      a1 = v8;
      v7 = *v8++;
      v9 = v7;
      if ( !v7 )
        goto LABEL_39;
    }
    if ( v7 == 61 )
    {
      v28 = *v8;
      v29 = a1 + 2;
      if ( v5 == 2 )
      {
LABEL_54:
        v30 = v29;
        if ( (int)v28 )
        {
          while ( (v11[(int)v28] & 0x2000) != 0 )
          {
            LODWORD(v28) = *v30++;
            if ( !(int)v28 )
              return 0.0;
          }
          if ( (int)v28 == 61 )
          {
            v28 = *v30;
            v29 = v30 + 1;
            goto LABEL_64;
          }
        }
      }
      else if ( v5 == 3 )
      {
        goto LABEL_64;
      }
    }
    else
    {
      v32 = *v10;
      v13 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", v7);
      if ( v13 )
      {
        if ( v5 == 2 )
        {
          a1 = v8;
          v17 = v34;
          while ( 1 )
          {
            v20 = v17 + 1;
            v34 = v17 + 1;
            if ( a2 )
            {
              v21 = v20;
              if ( v20 >= a3 )
                return 0.0;
              v22 = sub_3DA40(v13, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", a4);
              *(char *)(a2 + v17) |= v22 >> 2;
              *(char *)(a2 + v21) = (char)v22 << 6;
            }
            v23 = *a1;
            v8 = a1 + 1;
            if ( !*a1 )
              break;
            v11 = *v12;
            if ( ((*v12)[v23] & 0x2000) != 0 )
            {
              ++a1;
              v5 = 3;
              goto LABEL_2;
            }
            if ( (int)v23 == 61 )
            {
              v28 = a1[1];
              v29 = a1 + 2;
LABEL_64:
              while ( (int)v28 )
              {
                if ( (v11[v28] & 0x2000) == 0 )
                  return 0.0;
                v28 = *v29++;
              }
              if ( !a2 || !*(char *)(a2 + v34) )
                return 0.0;
              return 0.0;
            }
            v13 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", v23);
            if ( !v13 )
              return 0.0;
LABEL_23:
            if ( a2 )
            {
              if ( v34 >= a3 )
                return 0.0;
              *(char *)(a2 + v34) |= sub_3DA40(
                                        v13,
                                        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
                                        a4);
            }
            v24 = *v8;
            ++v34;
            a1 = v8 + 1;
            if ( !*v8 )
              return 0.0;
            v33 = *v12;
            if ( ((*v12)[v24] & 0x2000) != 0 )
            {
              v5 = 0;
              goto LABEL_2;
            }
            if ( (int)v24 == 61 )
              return 0.0;
            v13 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", v24);
            if ( !v13 )
              return 0.0;
            v14 = v33;
            ++v8;
LABEL_31:
            if ( a2 )
            {
              if ( v34 < a3 )
              {
                v15 = v8 + 1;
                *(char *)(a2 + v34) = 4
                                     * sub_3DA40(
                                         v13,
                                         "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
                                         a4);
                v25 = *v8;
                if ( *v8 )
                {
                  if ( ((*v12)[v25] & 0x2000) != 0 )
                  {
                    a1 = v8 + 1;
LABEL_51:
                    v5 = 1;
                    goto LABEL_2;
                  }
                  if ( (int)v25 != 61 )
                  {
                    v13 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", v25);
                    if ( v13 )
                      goto LABEL_10;
                  }
                }
              }
              return 0.0;
            }
            v27 = *v8;
            a1 = v8 + 1;
            if ( !*v8 )
              return 0.0;
            if ( (v14[v27] & 0x2000) != 0 )
              goto LABEL_51;
            if ( (int)v27 == 61 || !strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", v27) )
              return 0.0;
            v15 = v8 + 1;
            v17 = v34 + 1;
LABEL_12:
            v19 = *v15;
            a1 = v15 + 1;
            if ( !*v15 )
              return 0.0;
            v11 = *v12;
            if ( ((*v12)[v19] & 0x2000) != 0 )
            {
              v34 = v17;
              v5 = 2;
              goto LABEL_2;
            }
            if ( (int)v19 == 61 )
            {
              v34 = v17;
              LODWORD(v28) = v15[1];
              v29 = v15 + 2;
              goto LABEL_54;
            }
            v13 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", v19);
            if ( !v13 )
              return 0.0;
          }
        }
        else
        {
          if ( v5 == 3 )
            goto LABEL_23;
          v14 = v32;
          if ( v5 != 1 )
            goto LABEL_31;
          v15 = v8;
          if ( !a2 )
          {
            v17 = v34 + 1;
            goto LABEL_12;
          }
LABEL_10:
          v16 = v34 + 1;
          v17 = v16;
          if ( v16 < a3 )
          {
            v18 = sub_3DA40(v13, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", a4);
            *(char *)(a2 + v34) |= v18 >> 4;
            *(char *)(a2 + v16) = 16 * v18;
            goto LABEL_12;
          }
        }
      }
    }
    return 0.0;
  }
LABEL_39:
  if ( v5 )
    return 0.0;
  return 0.0;
}


// Function: bcrypt_hash @ 0x39300
double bcrypt_hash(long long a1, long long a2, long long a3)
{
  int v3; // ebp
  __m128i si128; // xmm0
  char *v5; // r14
  char *v6; // r13
  int v7; // ebp
  long long v8; // r13
  int v9; // eax
  short v12; // [rsp+1Eh] [rbp-10DAh] BYREF
  char v13[32]; // [rsp+20h] [rbp-10D8h] BYREF
  char v14[136]; // [rsp+40h] [rbp-10B8h] BYREF
  _OWORD v15[2]; // [rsp+1090h] [rbp-68h] BYREF
  unsigned long long v16; // [rsp+10B8h] [rbp-40h]

  v3 = 64;
  v16 = __readfsqword(0x28u);
  v15[0] = _mm_load_si128((const __m128i *)&xmmword_5BCF0);
  si128 = _mm_load_si128((const __m128i *)&xmmword_5BD00);
  v15[1] = si128;
  sub_3A290(v14);
  sub_3A5D0(v14, a2, 64, a1, 64);
  do
  {
    sub_3A420(v14, a2, 64);
    sub_3A420(v14, a1, 64);
    --v3;
  }
  while ( v3 );
  v12 = 0;
  v5 = v13;
  v6 = v13;
  do
  {
    v6 += 4;
    *((int *)v6 - 1) = sub_3A350(v15, 32, &v12);
  }
  while ( v6 != v14 );
  v7 = 64;
  do
  {
    sub_3A840(v14, v13, 4);
    --v7;
  }
  while ( v7 );
  v8 = a3;
  do
  {
    v9 = *(int *)v5;
    v5 += 4;
    v8 += 4;
    *(int *)(v8 - 4) = v9;
  }
  while ( v5 != v14 );
  __explicit_bzero_chk(v15, 32, 32, *(double *)si128.m128i_i64);
  __explicit_bzero_chk(v13, 32, 32, *(double *)si128.m128i_i64);
  __explicit_bzero_chk(v5, 4168, 4168, *(double *)si128.m128i_i64);
  return 0.0;
}


// Function: bcrypt_pbkdf @ 0x39530
double bcrypt_pbkdf(long long a1, long long a2, const void *a3, size_t a4, char *a5, unsigned long long a6, int a7)
{
  unsigned long long v8; // rbx
  unsigned long long v11; // rbx
  __m128i v12; // xmm0
  __m128i v13; // xmm1
  long long i; // rbx
  __m128i *v15; // rax
  __m128i *v16; // rdx
  unsigned long long v17; // rdx
  long long v18; // rax
  char v19; // cl
  int v21; // [rsp+Ch] [rbp-16Ch]
  unsigned long long v22; // [rsp+10h] [rbp-168h]
  unsigned long long v23; // [rsp+20h] [rbp-158h]
  long long v24; // [rsp+28h] [rbp-150h]
  void *ptr; // [rsp+30h] [rbp-148h]
  unsigned long long v27; // [rsp+50h] [rbp-128h]
  _OWORD v28[2]; // [rsp+70h] [rbp-108h] BYREF
  __m128i v29; // [rsp+90h] [rbp-E8h] BYREF
  __m128i v30; // [rsp+A0h] [rbp-D8h] BYREF
  char v31[64]; // [rsp+B0h] [rbp-C8h] BYREF
  char v32[72]; // [rsp+F0h] [rbp-88h] BYREF
  unsigned long long v33; // [rsp+138h] [rbp-40h]

  v33 = __readfsqword(0x28u);
  if ( a7
    && a4 - 1 <= 0xFFFFF
    && a2
    && (v8 = a6 - 1, a6 - 1 <= 0x3FF)
    && (v24 = a4 + 4, (ptr = calloc(1u, a4 + 4)) != 0) )
  {
    v27 = (a6 + 31) >> 5;
    v11 = (v27 + v8) / v27;
    memcpy(ptr, a3, a4);
    sub_310D0((long long)v31, a1, a2);
    v21 = 1;
    v22 = a6;
    do
    {
      while ( 1 )
      {
        *((char *)ptr + a4) = HIBYTE(v21);
        *((char *)ptr + a4 + 1) = BYTE2(v21);
        *((char *)ptr + a4 + 2) = BYTE1(v21);
        *((char *)ptr + a4 + 3) = v21;
        sub_310D0((long long)v32, (long long)ptr, v24);
        sub_39300((long long)v31, (long long)v32, (long long)&v29);
        v12 = _mm_load_si128(&v29);
        v13 = _mm_load_si128(&v30);
        v28[0] = v12;
        v28[1] = v13;
        if ( a7 != 1 )
        {
          v23 = v11;
          for ( i = 1; i != a7; ++i )
          {
            sub_310D0((long long)v32, (long long)&v29, 32);
            *(double *)v12.m128i_i64 = sub_39300((long long)v31, (long long)v32, (long long)&v29);
            v15 = (__m128i *)v28;
            v16 = &v29;
            do
            {
              v15->m128i_i8[0] ^= v16->m128i_i8[0];
              v15 = (__m128i *)((char *)v15 + 1);
              v16 = (__m128i *)((char *)v16 + 1);
            }
            while ( &v29 != v15 );
          }
          v11 = v23;
        }
        if ( v11 > v22 )
          v11 = v22;
        if ( v11 )
        {
          v17 = (unsigned int)(v21 - 1);
          if ( v17 < a6 )
            break;
        }
        ++v21;
      }
      v18 = 0;
      do
      {
        v19 = *((char *)v28 + v18++);
        a5[v17] = v19;
        if ( v11 == v18 )
        {
          v22 -= v11;
          goto LABEL_21;
        }
        v17 += v27;
      }
      while ( a6 > v17 );
      v22 -= v18;
LABEL_21:
      ++v21;
    }
    while ( v22 );
    sub_3B0D0(ptr);
    __explicit_bzero_chk(v28, 32, 32, *(double *)v12.m128i_i64);
    __explicit_bzero_chk(&v29, 32, 32, *(double *)v12.m128i_i64);
  }
  else
  {
    sub_38B20(a5);
  }
  return 0.0;
}


// Function: Blowfish_encipher @ 0x398d0
double Blowfish_encipher(int *a1, unsigned int *a2, int *a3)
{
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // ecx
  unsigned int v19; // ebx
  unsigned int v20; // edx
  int v21; // ecx

  v5 = a1[1024] ^ *a2;
  v6 = *a3 ^ a1[1025] ^ (a1[(unsigned char)v5 + 768] + (a1[BYTE1(v5) + 512] ^ (a1[BYTE2(v5) + 256] + a1[HIBYTE(v5)])));
  v7 = a1[1026] ^ v5 ^ (a1[(unsigned char)v6 + 768] + (a1[BYTE1(v6) + 512] ^ (a1[BYTE2(v6) + 256] + a1[HIBYTE(v6)])));
  v8 = a1[1027] ^ v6 ^ (a1[(unsigned char)v7 + 768] + (a1[BYTE1(v7) + 512] ^ (a1[BYTE2(v7) + 256] + a1[HIBYTE(v7)])));
  v9 = a1[1028] ^ v7 ^ (a1[(unsigned char)v8 + 768] + (a1[BYTE1(v8) + 512] ^ (a1[BYTE2(v8) + 256] + a1[HIBYTE(v8)])));
  v10 = a1[1029] ^ v8 ^ (a1[(unsigned char)v9 + 768] + (a1[BYTE1(v9) + 512] ^ (a1[BYTE2(v9) + 256] + a1[HIBYTE(v9)])));
  v11 = a1[1030]
      ^ v9
      ^ (a1[(unsigned char)v10 + 768] + (a1[BYTE1(v10) + 512] ^ (a1[BYTE2(v10) + 256] + a1[HIBYTE(v10)])));
  v12 = a1[1031]
      ^ v10
      ^ (a1[(unsigned char)v11 + 768] + (a1[BYTE1(v11) + 512] ^ (a1[BYTE2(v11) + 256] + a1[HIBYTE(v11)])));
  v13 = a1[1032]
      ^ v11
      ^ (a1[(unsigned char)v12 + 768] + (a1[BYTE1(v12) + 512] ^ (a1[BYTE2(v12) + 256] + a1[HIBYTE(v12)])));
  v14 = a1[1033]
      ^ v12
      ^ (a1[(unsigned char)v13 + 768] + (a1[BYTE1(v13) + 512] ^ (a1[BYTE2(v13) + 256] + a1[HIBYTE(v13)])));
  v15 = a1[1034]
      ^ v13
      ^ (a1[(unsigned char)v14 + 768] + (a1[BYTE1(v14) + 512] ^ (a1[BYTE2(v14) + 256] + a1[HIBYTE(v14)])));
  v16 = a1[1035]
      ^ v14
      ^ (a1[(unsigned char)v15 + 768] + (a1[BYTE1(v15) + 512] ^ (a1[BYTE2(v15) + 256] + a1[HIBYTE(v15)])));
  v17 = a1[1036]
      ^ v15
      ^ (a1[(unsigned char)v16 + 768] + (a1[BYTE1(v16) + 512] ^ (a1[BYTE2(v16) + 256] + a1[HIBYTE(v16)])));
  v18 = a1[1037]
      ^ v16
      ^ (a1[(unsigned char)v17 + 768] + (a1[BYTE1(v17) + 512] ^ (a1[BYTE2(v17) + 256] + a1[HIBYTE(v17)])));
  v19 = a1[1038]
      ^ v17
      ^ (a1[(unsigned char)v18 + 768] + (a1[BYTE1(v18) + 512] ^ (a1[BYTE2(v18) + 256] + a1[HIBYTE(v18)])));
  v20 = a1[1039]
      ^ v18
      ^ (a1[(unsigned char)v19 + 768] + (a1[BYTE1(v19) + 512] ^ (a1[BYTE2(v19) + 256] + a1[HIBYTE(v19)])));
  v21 = a1[1040]
      ^ v19
      ^ (a1[(unsigned char)v20 + 768] + (a1[BYTE1(v20) + 512] ^ (a1[BYTE2(v20) + 256] + a1[HIBYTE(v20)])));
  *a2 = a1[1041] ^ v20;
  *a3 = v21;
  return 0.0;
}


// Function: Blowfish_decipher @ 0x39db0
double Blowfish_decipher(int *a1, unsigned int *a2, int *a3)
{
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // ecx
  unsigned int v19; // ebx
  unsigned int v20; // edx
  int v21; // ecx

  v5 = a1[1041] ^ *a2;
  v6 = *a3 ^ a1[1040] ^ (a1[(unsigned char)v5 + 768] + (a1[BYTE1(v5) + 512] ^ (a1[BYTE2(v5) + 256] + a1[HIBYTE(v5)])));
  v7 = a1[1039] ^ v5 ^ (a1[(unsigned char)v6 + 768] + (a1[BYTE1(v6) + 512] ^ (a1[BYTE2(v6) + 256] + a1[HIBYTE(v6)])));
  v8 = a1[1038] ^ v6 ^ (a1[(unsigned char)v7 + 768] + (a1[BYTE1(v7) + 512] ^ (a1[BYTE2(v7) + 256] + a1[HIBYTE(v7)])));
  v9 = a1[1037] ^ v7 ^ (a1[(unsigned char)v8 + 768] + (a1[BYTE1(v8) + 512] ^ (a1[BYTE2(v8) + 256] + a1[HIBYTE(v8)])));
  v10 = a1[1036] ^ v8 ^ (a1[(unsigned char)v9 + 768] + (a1[BYTE1(v9) + 512] ^ (a1[BYTE2(v9) + 256] + a1[HIBYTE(v9)])));
  v11 = a1[1035]
      ^ v9
      ^ (a1[(unsigned char)v10 + 768] + (a1[BYTE1(v10) + 512] ^ (a1[BYTE2(v10) + 256] + a1[HIBYTE(v10)])));
  v12 = a1[1034]
      ^ v10
      ^ (a1[(unsigned char)v11 + 768] + (a1[BYTE1(v11) + 512] ^ (a1[BYTE2(v11) + 256] + a1[HIBYTE(v11)])));
  v13 = a1[1033]
      ^ v11
      ^ (a1[(unsigned char)v12 + 768] + (a1[BYTE1(v12) + 512] ^ (a1[BYTE2(v12) + 256] + a1[HIBYTE(v12)])));
  v14 = a1[1032]
      ^ v12
      ^ (a1[(unsigned char)v13 + 768] + (a1[BYTE1(v13) + 512] ^ (a1[BYTE2(v13) + 256] + a1[HIBYTE(v13)])));
  v15 = a1[1031]
      ^ v13
      ^ (a1[(unsigned char)v14 + 768] + (a1[BYTE1(v14) + 512] ^ (a1[BYTE2(v14) + 256] + a1[HIBYTE(v14)])));
  v16 = a1[1030]
      ^ v14
      ^ (a1[(unsigned char)v15 + 768] + (a1[BYTE1(v15) + 512] ^ (a1[BYTE2(v15) + 256] + a1[HIBYTE(v15)])));
  v17 = a1[1029]
      ^ v15
      ^ (a1[(unsigned char)v16 + 768] + (a1[BYTE1(v16) + 512] ^ (a1[BYTE2(v16) + 256] + a1[HIBYTE(v16)])));
  v18 = a1[1028]
      ^ v16
      ^ (a1[(unsigned char)v17 + 768] + (a1[BYTE1(v17) + 512] ^ (a1[BYTE2(v17) + 256] + a1[HIBYTE(v17)])));
  v19 = a1[1027]
      ^ v17
      ^ (a1[(unsigned char)v18 + 768] + (a1[BYTE1(v18) + 512] ^ (a1[BYTE2(v18) + 256] + a1[HIBYTE(v18)])));
  v20 = a1[1026]
      ^ v18
      ^ (a1[(unsigned char)v19 + 768] + (a1[BYTE1(v19) + 512] ^ (a1[BYTE2(v19) + 256] + a1[HIBYTE(v19)])));
  v21 = a1[1025]
      ^ v19
      ^ (a1[(unsigned char)v20 + 768] + (a1[BYTE1(v20) + 512] ^ (a1[BYTE2(v20) + 256] + a1[HIBYTE(v20)])));
  *a2 = a1[1024] ^ v20;
  *a3 = v21;
  return 0.0;
}


// Function: Blowfish_initstate @ 0x3a290
double Blowfish_initstate(long long a1)
{
  long long v2; // rdi

  v2 = a1 + 8;
  *(long long *)(v2 - 8) = 0x98DFB5ACD1310BA6LL;
  *(long long *)(v2 + 4152) = 0x8979FB1B9216D5D9LL;
  qmemcpy(
    (void *)(v2 & 0xFFFFFFFFFFFFFFF8LL),
    (char *)&qword_5BD20 - (a1 - (v2 & 0xFFFFFFFFFFFFFFF8LL)),
    8 * ((unsigned long long)((unsigned int)a1 - (v2 & 0xFFFFFFF8) + 4168) >> 3));
  return 0.0;
}


// Function: Blowfish_stream2word @ 0x3a350
double Blowfish_stream2word(unsigned char *a1, unsigned short a2, unsigned short *a3)
{
  unsigned short v3; // cx
  char v4; // r8
  int v5; // eax
  long long v6; // r9
  unsigned char *v7; // r9

  v3 = *a3;
  v4 = 4;
  v5 = 0;
  do
  {
    if ( a2 <= v3 )
    {
      v7 = a1;
      v3 = 1;
    }
    else
    {
      v6 = v3++;
      v7 = &a1[v6];
    }
    v5 = *v7 | (v5 << 8);
    --v4;
  }
  while ( v4 );
  *a3 = v3;
  return 0.0;
}


// Function: Blowfish_expand0state @ 0x3a420
double Blowfish_expand0state(int *a1, unsigned char *a2, unsigned short a3)
{
  int *v4; // rbx
  int *v5; // r12
  int v6; // eax
  int *v7; // r12
  int *v8; // rbx
  int *v10; // [rsp+8h] [rbp-60h]
  unsigned short v11; // [rsp+1Eh] [rbp-4Ah] BYREF
  unsigned int v12; // [rsp+20h] [rbp-48h] BYREF
  int v13; // [rsp+24h] [rbp-44h] BYREF
  unsigned long long v14; // [rsp+28h] [rbp-40h]

  v4 = a1 + 1024;
  v5 = a1 + 1024;
  v14 = __readfsqword(0x28u);
  v11 = 0;
  v10 = a1 + 1042;
  do
  {
    sub_3A350(a2, a3, &v11);
    *v5++ ^= v6;
  }
  while ( v5 != v10 );
  v12 = 0;
  v11 = 0;
  v13 = 0;
  do
  {
    v4 += 2;
    sub_398D0(a1, &v12, &v13);
    *(v4 - 2) = v12;
    *(v4 - 1) = v13;
  }
  while ( v4 != v10 );
  v7 = a1 + 256;
  do
  {
    v8 = v7 - 256;
    do
    {
      v8 += 2;
      sub_398D0(a1, &v12, &v13);
      *(v8 - 2) = v12;
      *(v8 - 1) = v13;
    }
    while ( v8 != v7 );
    v7 = v8 + 256;
  }
  while ( v8 + 256 != a1 + 1280 );
  return 0.0;
}


// Function: Blowfish_expandstate @ 0x3a5d0
double Blowfish_expandstate(
        int *a1,
        unsigned char *a2,
        unsigned short a3,
        unsigned char *a4,
        unsigned short a5)
{
  int *v5; // r15
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int *v11; // r14
  int v12; // eax
  int v13; // eax
  int *v16; // [rsp+10h] [rbp-68h]
  int *v17; // [rsp+10h] [rbp-68h]
  int *v18; // [rsp+18h] [rbp-60h]
  unsigned short v19; // [rsp+2Eh] [rbp-4Ah] BYREF
  unsigned int v20; // [rsp+30h] [rbp-48h] BYREF
  int v21; // [rsp+34h] [rbp-44h] BYREF
  unsigned long long v22; // [rsp+38h] [rbp-40h]

  v5 = a1 + 1024;
  v22 = __readfsqword(0x28u);
  v19 = 0;
  v18 = a1 + 1024;
  v16 = a1 + 1042;
  do
  {
    sub_3A350(a4, a5, &v19);
    *v5++ ^= v8;
  }
  while ( v5 != v16 );
  v20 = 0;
  v19 = 0;
  v21 = 0;
  do
  {
    sub_3A350(a2, a3, &v19);
    v20 ^= v9;
    sub_3A350(a2, a3, &v19);
    v21 ^= v10;
    sub_398D0(a1, &v20, &v21);
    *v18 = v20;
    v18[1] = v21;
    v18 += 2;
  }
  while ( v18 != v16 );
  v17 = a1 + 256;
  do
  {
    v11 = v17 - 256;
    do
    {
      v11 += 2;
      sub_3A350(a2, a3, &v19);
      v20 ^= v12;
      sub_3A350(a2, a3, &v19);
      v21 ^= v13;
      sub_398D0(a1, &v20, &v21);
      *(v11 - 2) = v20;
      *(v11 - 1) = v21;
    }
    while ( v11 != v17 );
    v17 = v11 + 256;
  }
  while ( v11 + 256 != a1 + 1280 );
  return 0.0;
}


// Function: blf_key @ 0x3a810
double blf_key(int *a1, unsigned char *a2, unsigned short a3)
{
  sub_3A290((long long)a1);
  return sub_3A420(a1, a2, a3);
}


// Function: blf_enc @ 0x3a840
double blf_enc(int *a1, long long a2, unsigned short a3)
{
  long long v3; // r12
  long long v4; // rbx
  int *v5; // rdx
  unsigned int *v6; // rsi

  if ( !a3 )
    return 0.0;
  v3 = a2 + 8LL * a3;
  v4 = a2;
  do
  {
    v5 = (int *)(v4 + 4);
    v6 = (unsigned int *)v4;
    v4 += 8;
    sub_398D0(a1, v6, v5);
  }
  while ( v4 != v3 );
  return 0.0;
}


// Function: blf_ecb_encrypt @ 0x3aac0
double blf_ecb_encrypt(int *a1, unsigned int *a2, unsigned int a3)
{
  unsigned int v5; // r15d
  unsigned int v6; // eax
  unsigned int v7; // eax
  char v8; // edx^3
  char v9; // edx^2
  unsigned int v10; // eax
  unsigned int v12; // [rsp+0h] [rbp-48h] BYREF
  unsigned int v13; // [rsp+4h] [rbp-44h] BYREF
  unsigned long long v14; // [rsp+8h] [rbp-40h]

  v14 = __readfsqword(0x28u);
  if ( a3 )
  {
    v5 = 0;
    do
    {
      v6 = *a2;
      v5 += 8;
      a2 += 2;
      v12 = _byteswap_ulong(v6);
      v13 = _byteswap_ulong(*(a2 - 1));
      sub_398D0(a1, &v12, (int *)&v13);
      v7 = v12;
      v8 = HIBYTE(v12);
      *((char *)a2 - 6) = BYTE1(v12);
      *((char *)a2 - 5) = v7;
      *((char *)a2 - 8) = v8;
      v9 = BYTE2(v7);
      v10 = v13;
      *((char *)a2 - 7) = v9;
      *((char *)a2 - 2) = BYTE1(v10);
      *((char *)a2 - 4) = HIBYTE(v10);
      *((char *)a2 - 1) = v10;
      *((char *)a2 - 3) = BYTE2(v10);
    }
    while ( a3 > v5 );
  }
  return 0.0;
}


// Function: blf_ecb_decrypt @ 0x3ac10
double blf_ecb_decrypt(int *a1, unsigned int *a2, unsigned int a3)
{
  unsigned int v5; // r15d
  unsigned int v6; // eax
  unsigned int v7; // eax
  char v8; // edx^3
  char v9; // edx^2
  unsigned int v10; // eax
  unsigned int v12; // [rsp+0h] [rbp-48h] BYREF
  unsigned int v13; // [rsp+4h] [rbp-44h] BYREF
  unsigned long long v14; // [rsp+8h] [rbp-40h]

  v14 = __readfsqword(0x28u);
  if ( a3 )
  {
    v5 = 0;
    do
    {
      v6 = *a2;
      v5 += 8;
      a2 += 2;
      v12 = _byteswap_ulong(v6);
      v13 = _byteswap_ulong(*(a2 - 1));
      sub_39DB0(a1, &v12, (int *)&v13);
      v7 = v12;
      v8 = HIBYTE(v12);
      *((char *)a2 - 6) = BYTE1(v12);
      *((char *)a2 - 5) = v7;
      *((char *)a2 - 8) = v8;
      v9 = BYTE2(v7);
      v10 = v13;
      *((char *)a2 - 7) = v9;
      *((char *)a2 - 2) = BYTE1(v10);
      *((char *)a2 - 4) = HIBYTE(v10);
      *((char *)a2 - 1) = v10;
      *((char *)a2 - 3) = BYTE2(v10);
    }
    while ( a3 > v5 );
  }
  return 0.0;
}


// Function: blf_cbc_encrypt @ 0x3ad60
double blf_cbc_encrypt(int *a1, char *a2, long long a3, unsigned int a4)
{
  char v5; // dl
  unsigned int v7; // r15d
  long long i; // rax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v13; // [rsp+0h] [rbp-48h] BYREF
  unsigned int v14; // [rsp+4h] [rbp-44h] BYREF
  unsigned long long v15; // [rsp+8h] [rbp-40h]

  v15 = __readfsqword(0x28u);
  if ( a4 )
  {
    v5 = *a2;
    v7 = 0;
    while ( 1 )
    {
      for ( i = 0; ; v5 = a2[i] )
      {
        *(char *)(a3 + i++) ^= v5;
        if ( i == 8 )
          break;
      }
      v7 += 8;
      v13 = _byteswap_ulong(*(int *)a3);
      v14 = _byteswap_ulong(*(int *)(a3 + 4));
      sub_398D0(a1, &v13, (int *)&v14);
      v9 = v13;
      a2 = (char *)a3;
      v10 = v13;
      *(char *)(a3 + 2) = BYTE1(v13);
      v10 >>= 24;
      *(char *)(a3 + 3) = v9;
      *(char *)a3 = v10;
      v5 = v10;
      BYTE2(v10) = BYTE2(v9);
      v11 = v14;
      *(char *)(a3 + 1) = BYTE2(v10);
      *(char *)(a3 + 6) = BYTE1(v11);
      *(char *)(a3 + 4) = HIBYTE(v11);
      *(char *)(a3 + 7) = v11;
      *(char *)(a3 + 5) = BYTE2(v11);
      if ( a4 <= v7 )
        break;
      a3 += 8;
    }
  }
  return 0.0;
}


// Function: blf_cbc_decrypt @ 0x3aed0
double blf_cbc_decrypt(int *a1, long long a2, long long a3, unsigned int a4)
{
  long long v4; // rbp
  long long v5; // rbx
  unsigned int *v6; // r13
  unsigned int v7; // eax
  unsigned int v8; // ecx
  char v9; // dl
  unsigned int v10; // eax
  unsigned int v11; // ecx
  long long v12; // rax
  unsigned int v13; // edx
  long long i; // rax
  unsigned int v16; // [rsp+10h] [rbp-48h] BYREF
  unsigned int v17; // [rsp+14h] [rbp-44h] BYREF
  unsigned long long v18; // [rsp+18h] [rbp-40h]

  v18 = __readfsqword(0x28u);
  v4 = a3 + a4 - 16;
  v5 = a3 + a4 - 8;
  if ( a4 - 8 <= 7 )
  {
    v6 = (unsigned int *)(a3 + a4 - 8);
  }
  else
  {
    v6 = (unsigned int *)(v5 - 8LL * (((a4 - 16) >> 3) + 1));
    do
    {
      v16 = _byteswap_ulong(*(int *)v5);
      v17 = _byteswap_ulong(*(int *)(v5 + 4));
      sub_39DB0(a1, &v16, (int *)&v17);
      v7 = v16;
      v8 = v16;
      *(char *)(v5 + 2) = BYTE1(v16);
      v8 >>= 24;
      *(char *)(v5 + 3) = v7;
      *(char *)v5 = v8;
      v9 = v8;
      BYTE2(v8) = BYTE2(v7);
      v10 = v17;
      *(char *)(v5 + 1) = BYTE2(v8);
      *(char *)(v5 + 6) = BYTE1(v10);
      *(char *)(v5 + 4) = HIBYTE(v10);
      v11 = HIWORD(v10);
      *(char *)(v5 + 7) = v10;
      v12 = 0;
      *(char *)(v5 + 5) = v11;
      while ( 1 )
      {
        *(char *)(v5 + v12) = *(char *)(v4 + v12) ^ v9;
        if ( ++v12 == 8 )
          break;
        v9 = *(char *)(v5 + v12);
      }
      v5 -= 8;
      v4 -= 8;
    }
    while ( v6 != (unsigned int *)v5 );
  }
  v16 = _byteswap_ulong(*v6);
  v17 = _byteswap_ulong(v6[1]);
  sub_39DB0(a1, &v16, (int *)&v17);
  v13 = HIBYTE(v16);
  *v6 = _byteswap_ulong(v16);
  v6[1] = _byteswap_ulong(v17);
  for ( i = 0; ; LOBYTE(v13) = *((char *)v6 + i) )
  {
    *((char *)v6 + i) = *(char *)(a2 + i) ^ v13;
    if ( ++i == 8 )
      break;
  }
  return 0.0;
}


// Function: freezero @ 0x3b0d0
double freezero(void *ptr, long long a2, double result)
{
  if ( !ptr )
    return 0.0;
  __explicit_bzero_chk(ptr, a2, -1, result);
  free(ptr);
  return result;
}


// Function: gcd @ 0x3b180
double gcd(int a1, int a2)
{
  int v2; // edx
  int v3; // r8d
  int v4; // eax
  int v5; // edx

  v2 = a1 % a2;
  if ( !(a1 % a2) )
    return 0.0;
  do
  {
    v3 = v2;
    v4 = a2;
    v5 = a2 >> 31;
    a2 = v3;
    v2 = __SPAIR64__(v5, v4) % v3;
  }
  while ( v2 );
  return 0.0;
}


// Function: permute_args @ 0x3b2b0
double permute_args(unsigned int a1, unsigned int a2, unsigned int a3, long long a4)
{
  int v6; // eax
  int v7; // ebx
  unsigned int v8; // r14d
  unsigned int v9; // r15d
  long long *v10; // rbp
  long long i; // rbx
  long long *v12; // rax
  long long v13; // r12
  int v15; // [rsp+8h] [rbp-50h]
  unsigned int v16; // [rsp+10h] [rbp-48h]
  unsigned int v17; // [rsp+14h] [rbp-44h]
  unsigned int v18; // [rsp+18h] [rbp-40h]
  unsigned int v19; // [rsp+1Ch] [rbp-3Ch]

  v17 = sub_3DA60(a2, a1);
  v18 = sub_3DA60(a3, a2);
  sub_3B180(v17, v18);
  v7 = v6;
  v16 = a2;
  v15 = (int)sub_3DA60(a3, a1) / v6;
  v19 = v7 + a2;
  if ( v7 > 0 )
  {
    do
    {
      v8 = v16;
      if ( v15 > 0 )
      {
        v9 = 0;
        v10 = (long long *)(a4 + 8LL * (int)v16);
        for ( i = *v10; ; i = v13 )
        {
          v8 = (int)a2 <= (int)v8 ? sub_3DA60(v8, v17) : sub_3DA20(v8, v18);
          v12 = (long long *)(a4 + 8LL * (int)v8);
          v13 = *v12;
          *v12 = i;
          *v10 = v13;
          v9 = sub_3DA20(v9, 1);
          if ( v15 == v9 )
            break;
        }
      }
      ++v16;
    }
    while ( v19 != v16 );
  }
  return 0.0;
}


// Function: recallocarray @ 0x3ba50
char *recallocarray(char *src, unsigned long long a2, size_t a3, size_t a4, double a5)
{
  bool v6; // cl
  size_t v7; // r12
  size_t v8; // rbp
  char *v9; // rax
  char *v10; // r14
  char *v12; // rax

  if ( !src )
    return (char *)calloc(a3, a4);
  v6 = (a2 | a4) > 0xFFFFFFFF;
  if ( (a4 | a3) > 0xFFFFFFFF && a3 && !is_mul_ok(a3, a4) )
  {
    v10 = 0;
    *__errno_location() = 12;
    return v10;
  }
  v7 = a4 * a3;
  if ( a2 && v6 && !is_mul_ok(a2, a4) )
  {
    v10 = 0;
    *__errno_location() = 22;
    return v10;
  }
  v8 = a2 * a4;
  if ( v7 > v8 )
  {
    v12 = (char *)malloc(v7);
    v10 = v12;
    if ( v12 )
    {
      memcpy(v12, src, v8);
      memset(&v10[v8], 0, v7 - v8);
      goto LABEL_10;
    }
  }
  else
  {
    if ( v8 >> 1 > v8 - v7 && getpagesize() > v8 - v7 )
    {
      v10 = src;
      memset(&src[v7], 0, v8 - v7);
      return v10;
    }
    v9 = (char *)malloc(v7);
    v10 = v9;
    if ( v9 )
    {
      memcpy(v9, src, v7);
LABEL_10:
      __explicit_bzero_chk(src, v8, -1, a5);
      free(src);
      return v10;
    }
  }
  return 0;
}


// Function: strlcat @ 0x3bcf0
double strlcat(char *a1, const char *a2, long long a3, double a4)
{
  char *v5; // rbx
  long long v6; // r12
  long long v7; // rdx
  char v8; // al
  const char *v9; // r8
  const char *v10; // rdi

  if ( !a3 )
    goto LABEL_15;
  v5 = a1;
  do
  {
    if ( !*v5 )
      break;
    ++v5;
  }
  while ( v5 != &a1[a3] );
  v6 = sub_3DA40(v5, a1, a4);
  v7 = a3 - v6;
  if ( a3 == v6 )
  {
LABEL_15:
    strlen(a2);
    return 0.0;
  }
  else
  {
    v8 = *a2;
    v9 = a2;
    if ( *a2 )
    {
      do
      {
        if ( v7 == 1 )
        {
          v10 = v9 + 1;
          if ( !v9[1] )
          {
            sub_3DA40(v10, a2, a4);
            goto LABEL_13;
          }
        }
        else
        {
          *v5 = v8;
          --v7;
          v10 = v9;
          ++v5;
        }
        v8 = v10[1];
        v9 = v10 + 1;
      }
      while ( v8 );
      sub_3DA40(v10 + 1, a2, a4);
    }
LABEL_13:
    *v5 = 0;
    return 0.0;
  }
}


// Function: strlcpy @ 0x3bee0
double strlcpy(char *a1, char *a2, long long a3, double a4)
{
  char *v4; // rax
  long long v5; // rcx
  char *v6; // rdi
  char v7; // dl
  char *v8; // rdx
  long long v9; // rax

  if ( !a3 )
  {
    v6 = a2;
    do
LABEL_8:
      ++v6;
    while ( *(v6 - 1) );
    goto LABEL_6;
  }
  v4 = a1;
  v5 = (long long)&a1[a3 - 1];
  v6 = a2;
  while ( 1 )
  {
    v8 = v6++;
    if ( v4 == (char *)v5 )
      break;
    v7 = *(v6 - 1);
    *v4++ = v7;
    if ( !v7 )
      goto LABEL_6;
  }
  *v4 = 0;
  v6 = v8 + 1;
  if ( *v8 )
    goto LABEL_8;
LABEL_6:
  v9 = sub_3DA40(v6, a2, a4);
  sub_3DA00(v9, -1);
  return 0.0;
}


// Function: strtonum @ 0x3bfe0
double strtonum(char *nptr, long long a2, long long a3, long long *a4)
{
  int *v6; // rax
  int v7; // r15d
  int *v8; // rbx
  long long v9; // rax
  long long v11; // rax
  char *endptr[18]; // [rsp+8h] [rbp-90h] BYREF

  endptr[10] = (char *)__readfsqword(0x28u);
  endptr[3] = "invalid";
  endptr[5] = "too small";
  endptr[7] = "too large";
  v6 = __errno_location();
  v7 = *v6;
  v8 = v6;
  *v6 = 0;
  if ( a2 > a3 || (v11 = strtoll(nptr, endptr, 10), endptr[0] == nptr) || *endptr[0] )
  {
    v7 = 22;
    v9 = 1;
    goto LABEL_3;
  }
  if ( v11 == 0x8000000000000000LL )
  {
    if ( *v8 != 34 && a2 == 0x8000000000000000LL )
      goto LABEL_16;
LABEL_13:
    v7 = 34;
    v9 = 2;
LABEL_3:
    if ( a4 )
      *a4 = endptr[2 * v9 + 1];
    goto LABEL_5;
  }
  if ( a2 > v11 )
    goto LABEL_13;
  if ( v11 == 0x7FFFFFFFFFFFFFFFLL && *v8 == 34 || a3 < v11 )
  {
    v7 = 34;
    v9 = 3;
    goto LABEL_3;
  }
LABEL_16:
  if ( a4 )
    *a4 = 0;
LABEL_5:
  *v8 = v7;
  return 0.0;
}


// Function: timingsafe_bcmp @ 0x3c1c0
double timingsafe_bcmp(long long a1, long long a2, long long a3)
{
  long long v3; // rcx
  int v4; // r8d
  unsigned char v5; // al

  if ( !a3 )
    return 0.0;
  v3 = 0;
  v4 = 0;
  do
  {
    v5 = *(char *)(a2 + v3) ^ *(char *)(a1 + v3);
    ++v3;
    v4 |= v5;
  }
  while ( a3 != v3 );
  return 0.0;
}


// Function: vis @ 0x3c300
double vis(char *a1, unsigned int a2, short a3, char a4)
{
  char *v4; // r13
  int v7; // ebx
  int v8; // r14d
  unsigned long long v9; // rdx
  long long v10; // rcx
  const unsigned short **v11; // r8
  char *v12; // rax
  char v13; // dl
  unsigned long long v15; // rax
  unsigned long long v16; // rdx

  v4 = a1;
  v7 = a2;
  if ( a2 == 92 )
  {
    v8 = 92;
    goto LABEL_29;
  }
  if ( (a3 & 0x400) != 0 )
    goto LABEL_14;
  v8 = a2;
  if ( a2 > 0xFF || (a2 & 0x80u) != 0 )
    goto LABEL_4;
  v15 = a2 - 35;
  if ( (unsigned int)v15 > 0x38 )
  {
LABEL_29:
    if ( ((*__ctype_b_loc())[a2] & 0x8000u) != 0 )
      goto LABEL_30;
    goto LABEL_4;
  }
  v16 = 0xFEFFFFFFEFFFFF7ELL;
  if ( !_bittest64((const long long *)&v16, v15) && (a3 & 0x100) != 0 )
    goto LABEL_6;
  if ( ((*__ctype_b_loc())[a2] & 0x8000u) != 0 )
    goto LABEL_33;
LABEL_4:
  if ( (a3 & 4) == 0 && a2 == 32 )
    goto LABEL_33;
LABEL_6:
  if ( (a3 & 8) == 0 && a2 == 9 || (a3 & 0x10) == 0 && a2 == 10 )
    goto LABEL_33;
  if ( (a3 & 0x20) == 0
    || (unsigned int)(v8 - 7) > 1 && a2 != 13 && ((*__ctype_b_loc())[(unsigned char)a2] & 0x8000u) == 0 )
  {
LABEL_14:
    if ( (a3 & 2) != 0 )
    {
      switch ( a2 )
      {
        case 0u:
          v12 = a1 + 2;
          *(short *)a1 = 12380;
          if ( (unsigned char)(a4 - 48) <= 7u )
          {
            v12 = a1 + 4;
            *((short *)a1 + 1) = 12336;
          }
          break;
        case 7u:
          v12 = a1 + 2;
          *(short *)a1 = 24924;
          break;
        case 8u:
          v12 = a1 + 2;
          *(short *)a1 = 25180;
          break;
        case 9u:
          v12 = a1 + 2;
          *(short *)a1 = 29788;
          break;
        case 0xAu:
          v12 = a1 + 2;
          *(short *)a1 = 28252;
          break;
        case 0xBu:
          v12 = a1 + 2;
          *(short *)a1 = 30300;
          break;
        case 0xCu:
          v12 = a1 + 2;
          *(short *)a1 = 26204;
          break;
        case 0xDu:
          v12 = a1 + 2;
          *(short *)a1 = 29276;
          break;
        case 0x20u:
          v12 = a1 + 2;
          *(short *)a1 = 29532;
          break;
        default:
          goto LABEL_16;
      }
      goto LABEL_27;
    }
LABEL_16:
    if ( (a2 & 0x7F) != 0x20 && (a3 & 1) == 0 )
    {
      if ( (a3 & 0x100) == 0 || (v9 = a2 - 35, (unsigned int)v9 > 0x38) )
      {
        if ( (a3 & 0x40) != 0 )
          goto LABEL_36;
        goto LABEL_35;
      }
      v10 = 0x100000010000081LL;
      if ( !_bittest64(&v10, v9) )
      {
        if ( (a3 & 0x40) != 0 )
        {
LABEL_22:
          v11 = __ctype_b_loc();
          v12 = v4 + 2;
          if ( ((*v11)[(unsigned char)v7] & 2) != 0 )
          {
            v13 = 63;
            *v4 = 94;
            if ( v7 != 127 )
              v13 = v7 + 64;
            v4[1] = v13;
          }
          else
          {
            *v4 = 45;
            v4[1] = v7;
          }
          goto LABEL_27;
        }
LABEL_35:
        *a1 = 92;
        v4 = a1 + 1;
LABEL_36:
        if ( (a2 & 0x80u) != 0 )
        {
          *v4 = 77;
          v7 = a2 & 0x7F;
          ++v4;
        }
        goto LABEL_22;
      }
    }
    *a1 = 92;
    a1[1] = ((unsigned char)a2 >> 6) + 48;
    a1[3] = (a2 & 7) + 48;
    a1[2] = (((unsigned char)a2 >> 3) & 7) + 48;
    v12 = a1 + 4;
LABEL_27:
    *v12 = 0;
    return 0.0;
  }
LABEL_30:
  if ( a2 != 34 )
  {
    if ( a2 != 92 || (a3 & 0x40) != 0 )
      goto LABEL_33;
    goto LABEL_32;
  }
  if ( (a3 & 0x200) != 0 )
  {
LABEL_32:
    *a1 = 92;
    v4 = a1 + 1;
  }
LABEL_33:
  *(short *)v4 = (unsigned char)a2;
  return 0.0;
}


// Function: strvis @ 0x3c780
double strvis(char *a1, char *a2, short a3)
{
  char *v3; // rbp
  char *v4; // rbx
  unsigned int v5; // esi
  char v7; // cl
  char *v8; // rax
  double v9; // xmm0_8
  char *v11; // [rsp+8h] [rbp-20h]

  v3 = a1;
  v4 = a2;
  v5 = *a2;
  if ( (char)v5 )
  {
    do
    {
      v7 = *++v4;
      v9 = sub_3C300(a1, v5, a3, v7);
      v5 = (char)*v4;
      a1 = v8;
    }
    while ( *v4 );
    v11 = v8;
    sub_3DA40(v8, v3, v9);
    *v11 = 0;
    return 0.0;
  }
  else
  {
    *a1 = 0;
    return 0.0;
  }
}


// Function: strnvis @ 0x3c8f0
double strnvis(char *dest, char *a2, long long a3, unsigned int a4, double a5)
{
  short v5; // r14
  char *v6; // rbp
  char *v7; // rbx
  unsigned int v8; // esi
  char v9; // dl
  char *v10; // r13
  char *v11; // r15
  const unsigned short **v12; // rax
  long long v13; // rax
  int v14; // eax
  char *v15; // rcx
  const unsigned short **v16; // rax
  unsigned int i; // esi
  char v19; // cl
  long long v20; // rax
  long long v21; // rax
  char *v22; // [rsp+8h] [rbp-70h]
  unsigned char v23; // [rsp+14h] [rbp-64h]
  int v24; // [rsp+14h] [rbp-64h]
  unsigned char v25; // [rsp+14h] [rbp-64h]
  char v26; // [rsp+1Bh] [rbp-5Dh]
  char src[5]; // [rsp+33h] [rbp-45h] BYREF
  unsigned long long v29; // [rsp+38h] [rbp-40h]

  v5 = a4;
  v6 = &dest[a3 - 1];
  v7 = a2;
  v8 = *a2;
  v29 = __readfsqword(0x28u);
  if ( v8 && dest < v6 )
  {
    v9 = v8;
    v10 = v7 + 1;
    v11 = dest;
    v26 = ((a4 >> 4) ^ 1) & 1;
    while ( 1 )
    {
      if ( v8 == 92 )
        goto LABEL_21;
      if ( (v5 & 0x400) != 0 )
        goto LABEL_12;
      if ( v8 <= 0xFF && (v8 != 42 && v8 != 63 && v8 != 91 && v8 != 35 || (v5 & 0x100) == 0) )
      {
LABEL_21:
        v25 = v9;
        v16 = __ctype_b_loc();
        v9 = v25;
        if ( ((*v16)[v25] & 0x8000u) != 0 )
          goto LABEL_29;
      }
      if ( (v5 & 4) == 0 && v8 == 32 || (v5 & 8) == 0 && v8 == 9 || v26 && v8 == 10 )
        goto LABEL_24;
      if ( (v5 & 0x20) != 0 )
      {
        if ( v8 - 7 <= 1 || v8 == 13 || (v23 = v9, v12 = __ctype_b_loc(), v9 = v23, ((*v12)[v23] & 0x8000u) != 0) )
        {
LABEL_29:
          if ( v8 == 34 )
          {
            if ( (v5 & 0x200) != 0 )
              goto LABEL_31;
          }
          else if ( v8 == 92 && (v5 & 0x40) == 0 )
          {
LABEL_31:
            if ( v11 + 1 >= v6 )
            {
              v7 = v10 - 1;
              v15 = v11 + 2;
              goto LABEL_26;
            }
            *v11++ = 92;
          }
LABEL_24:
          *v11 = v9;
          v8 = *v10;
          ++v11;
          v7 = v10;
          v24 = 1;
          ++v10;
          v9 = v8;
          if ( v11 >= v6 )
          {
LABEL_25:
            v15 = &v11[v24];
            goto LABEL_26;
          }
          goto LABEL_14;
        }
      }
LABEL_12:
      v7 = v10;
      a5 = sub_3C300(src, v8, v5, *v10);
      v14 = sub_3DA40(v13, src, a5);
      v24 = v14;
      v15 = &v11[v14];
      if ( v15 > v6 )
      {
        v7 = v10 - 1;
        if ( !a3 )
          goto LABEL_41;
        goto LABEL_40;
      }
      v22 = &v11[v14];
      ++v10;
      memcpy(v11, src, v14);
      v8 = *(v10 - 1);
      v11 = v22;
      v9 = *(v10 - 1);
      if ( v22 >= v6 )
        goto LABEL_25;
LABEL_14:
      if ( !v8 )
        goto LABEL_25;
    }
  }
  v11 = dest;
  v15 = dest;
LABEL_26:
  if ( a3 )
  {
LABEL_40:
    *v11 = 0;
    if ( v6 >= v15 )
      goto LABEL_28;
  }
  else if ( v6 >= v15 )
  {
    goto LABEL_28;
  }
LABEL_41:
  for ( i = *v7; *v7; v11 += v21 )
  {
    v19 = *++v7;
    a5 = sub_3C300(src, i, v5, v19);
    v21 = sub_3DA40(v20, src, a5);
    i = *v7;
  }
LABEL_28:
  sub_3DA40(v11, dest, a5);
  return 0.0;
}


// Function: stravis @ 0x3cc70
double stravis(long long *a1, char *a2, short a3)
{
  size_t v4; // rax
  char *v5; // rax
  void *v6; // rbx
  unsigned int v7; // eax
  unsigned int v8; // r12d
  int *v9; // rax
  int v10; // ebp
  int *v11; // r14
  int v12; // eax
  void *v13; // rax

  v4 = strlen(a2);
  v5 = (char *)reallocarray(0, 4, v4 + 1);
  if ( !v5 )
    return 0.0;
  v6 = v5;
  sub_3C780(v5, a2, a3);
  v8 = v7;
  v9 = __errno_location();
  v10 = *v9;
  v11 = v9;
  v12 = sub_3DA20(v8, 1);
  v13 = realloc(v6, v12);
  if ( v13 )
  {
    *a1 = v13;
    return 0.0;
  }
  *a1 = v6;
  *v11 = v10;
  return 0.0;
}


// Function: strvisx @ 0x3ce20
double strvisx(char *a1, char *a2, unsigned long long a3, short a4)
{
  char *v5; // r12
  char *v6; // rbx
  char *v7; // rbp
  unsigned int v8; // esi
  char v9; // cl
  char *v10; // rax
  double v11; // xmm0_8
  char *v12; // rax
  char *v13; // rbx

  v5 = a1;
  v6 = a2;
  if ( a3 > 1 )
  {
    v7 = &a2[a3 - 1];
    do
    {
      v8 = *v6;
      v9 = *++v6;
      sub_3C300(a1, v8, a4, v9);
      a1 = v10;
    }
    while ( v7 != v6 );
    goto LABEL_4;
  }
  if ( a3 )
  {
    v7 = a2;
LABEL_4:
    v11 = sub_3C300(a1, *v7, a4, 0);
    v13 = v12;
    sub_3DA40(v12, v5, v11);
    *v13 = 0;
    return 0.0;
  }
  *a1 = 0;
  return 0.0;
}


// Function: sys_get_rdomain @ 0x3cfc0
double sys_get_rdomain(int a1)
{
  int *v2; // rax
  char *v3; // rax
  socklen_t optlen; // [rsp+Ch] [rbp-3Ch] BYREF
  char optval[24]; // [rsp+10h] [rbp-38h] BYREF
  unsigned long long v6; // [rsp+28h] [rbp-20h]

  v6 = __readfsqword(0x28u);
  optlen = 16;
  if ( getsockopt(a1, 1, 25, optval, &optlen) == -1 )
  {
    v2 = __errno_location();
    v3 = strerror(*v2);
    sub_203A0(
      "port-net.c",
      "sys_get_rdomain",
      0x39u,
      0,
      2,
      0,
      "%s: cannot determine VRF for fd=%d : %s",
      "sys_get_rdomain",
      a1,
      v3);
  }
  else
  {
    optval[optlen] = 0;
    strdup(optval);
  }
  return 0.0;
}


// Function: sys_set_rdomain @ 0x3d110
double sys_set_rdomain(int fd, const char *optval)
{
  socklen_t v2; // eax
  int *v4; // rax
  char *v5; // rax

  v2 = strlen(optval);
  if ( setsockopt(fd, 1, 25, optval, v2) == -1 )
  {
    v4 = __errno_location();
    v5 = strerror(*v4);
    sub_203A0(
      "port-net.c",
      "sys_set_rdomain",
      0x46u,
      0,
      2,
      0,
      "%s: setsockopt(%d, SO_BINDTODEVICE, %s): %s",
      "sys_set_rdomain",
      fd,
      optval,
      v5);
  }
  return 0.0;
}


// Function: sys_valid_rdomain @ 0x3d220
double sys_valid_rdomain(const char *optval)
{
  int v1; // eax
  int v2; // ebp
  socklen_t v3; // eax

  v1 = socket(2, 1, 0);
  if ( v1 == -1 )
    return 0.0;
  v2 = v1;
  v3 = strlen(optval);
  if ( setsockopt(v2, 1, 25, optval, v3) != -1 )
  {
    close(v2);
    return 0.0;
  }
  close(v2);
  return 0.0;
}


// Function: sys_tun_open @ 0x3d3a0
double sys_tun_open(unsigned int a1, int a2, char **a3)
{
  long long v4; // rcx
  long long v5; // r9
  int v6; // r12d
  const char *v7; // r8
  long long v8; // rcx
  long long v9; // r8
  long long v10; // r9
  char *v11; // rax
  int *v13; // rax
  char *v14; // rax
  int *v15; // rax
  char *v16; // rax
  int *v17; // rax
  char *v18; // rax
  __int128 v19; // [rsp+0h] [rbp-58h] BYREF
  __int128 v20; // [rsp+10h] [rbp-48h]
  long long v21; // [rsp+20h] [rbp-38h]
  unsigned long long v22; // [rsp+28h] [rbp-30h]

  v22 = __readfsqword(0x28u);
  if ( a3 )
    *a3 = 0;
  v6 = open("/dev/net/tun", 2);
  if ( v6 == -1 )
  {
    v15 = __errno_location();
    v16 = strerror(*v15);
    sub_203A0(
      "port-net.c",
      "sys_tun_open",
      0x99u,
      0,
      5,
      0,
      "%s: failed to open tunnel control device \"%s\": %s",
      "sys_tun_open",
      "/dev/net/tun",
      v16);
    return 0.0;
  }
  v21 = 0;
  v7 = "tun%d";
  v20 = 0;
  v19 = 0;
  LOWORD(v20) = (a2 == 2) + 4097;
  if ( a2 == 2 )
    v7 = "tap%d";
  if ( a1 == 0x7FFFFFFF )
  {
    if ( ioctl(v6, 0x400454CAu, &v19, v4, v7, v5) != -1 )
    {
      sub_203A0("port-net.c", "sys_tun_open", 0xB9u, 0, 5, 0, "%s: tunnel mode %d fd %d", "sys_tun_open", a2, v6);
      goto LABEL_10;
    }
    goto LABEL_15;
  }
  if ( a1 == 2147483646 )
  {
    v17 = __errno_location();
    v18 = strerror(*v17);
    sub_203A0(
      "port-net.c",
      "sys_tun_open",
      0xABu,
      0,
      5,
      0,
      "%s: invalid tunnel id %x: %s",
      "sys_tun_open",
      2147483646,
      v18);
    goto LABEL_16;
  }
  __snprintf_chk(&v19, 16, 1, 16, v7, a1);
  if ( ioctl(v6, 0x400454CAu, &v19, v8, v9, v10) == -1 )
  {
LABEL_15:
    v13 = __errno_location();
    v14 = strerror(*v13);
    sub_203A0(
      "port-net.c",
      "sys_tun_open",
      0xB3u,
      0,
      5,
      0,
      "%s: failed to configure tunnel (mode %d): %s",
      "sys_tun_open",
      a2,
      v14);
LABEL_16:
    close(v6);
    return 0.0;
  }
  sub_203A0(
    "port-net.c",
    "sys_tun_open",
    0xBBu,
    0,
    5,
    0,
    "%s: %s mode %d fd %d",
    "sys_tun_open",
    (const char *)&v19,
    a2,
    v6);
LABEL_10:
  if ( a3 )
  {
    v11 = strdup((const char *)&v19);
    *a3 = v11;
    if ( !v11 )
      goto LABEL_16;
  }
  return 0.0;
}


// Function: sys_tun_infilter @ 0x3d6c0
// positive sp value has been detected, the output may be wrong!
double sys_tun_infilter(long long a1, long long a2, const __m128i *a3, int a4)
{
  long long v4; // rbx
  double v5; // xmm0_8
  char v6; // r12
  long long *v7; // rdi
  unsigned int v8; // eax
  char *v10; // rax
  short v11; // [rsp-18h] [rbp-4038h] BYREF
  char v12; // [rsp-16h] [rbp-4036h]
  char v13; // [rsp-15h] [rbp-4035h]
  int v14; // [rsp-14h] [rbp-4034h] BYREF
  char v15; // [rsp+0h] [rbp-4020h] BYREF
  long long v16[1540]; // [rsp+1000h] [rbp-3020h] BYREF

  while ( &v15 != (char *)&v16[-2048] )
    ;
  v16[1534] = __readfsqword(0x28u);
  if ( a4 >= 0 )
  {
    v4 = a4;
    if ( (unsigned long long)(a4 - 21LL) <= 0x3FE7 )
    {
      *(long long *)&v5 = _mm_loadu_si128(a3).m128i_u64[0];
      v6 = 24;
      if ( (a3->m128i_i8[0] & 0xF0) != 0x60 )
        v6 = 2;
      __memcpy_chk(&v14, a3, a4, 16380, v5);
      v7 = *(long long **)(a2 + 104);
      v11 = 0;
      v12 = 0;
      v13 = v6;
      sub_1B6C0(v7, &v11, v4 + 4);
      if ( v8 )
      {
        v10 = sub_B050(v8);
        sub_1EE30(
          "port-net.c",
          (long long)"sys_tun_infilter",
          348,
          0,
          1,
          0,
          (long long)"%s: buffer error: %s",
          "sys_tun_infilter",
          v10);
      }
    }
  }
  return 0.0;
}


// Function: sys_tun_outfilter @ 0x3d870
double sys_tun_outfilter(long long a1, long long a2, long long *a3, long long *a4)
{
  unsigned int v5; // eax
  char *v7; // rax

  sub_1A590(*(long long *)(a2 + 112), a3, a4);
  if ( v5 )
  {
    v7 = sub_B050(v5);
    sub_1EE30(
      "port-net.c",
      (long long)"sys_tun_outfilter",
      362,
      0,
      1,
      0,
      (long long)"%s: buffer error: %s",
      "sys_tun_outfilter",
      v7);
  }
  if ( *a4 > 3u )
    *a4 -= 4LL;
  return 0.0;
}


