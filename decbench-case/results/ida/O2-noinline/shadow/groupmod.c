// Function: main @ 0x4f60
long long main(unsigned int a1, char **a2, char **a3)
{
  long long v3; // rax
  long long v5; // r12
  char *v6; // rax
  long long v7; // r12
  char *v8; // rax

  qword_192B0 = sub_6670(*a2, a2, a3);
  sub_A490(qword_192B0);
  sub_A4B0(stderr);
  setlocale(6, "");
  bindtextdomain("shadow", "/usr/share/locale");
  textdomain("shadow");
  sub_8680("-R", a1, a2);
  sub_7B30("-P", a1, a2);
  openlog("groupmod", 1, 80);
  if ( (unsigned int)sub_FC30(sub_6810) )
  {
    v7 = qword_192B0;
    v8 = dcgettext(0, "%s: Cannot setup cleanup service.\n", 5);
    __fprintf_chk(stderr, 1, v8, v7);
    exit(11);
  }
  sub_5380(a1, a2);
  byte_19350 = sub_CAE0();
  v3 = sub_7FB0(s1);
  if ( !v3 )
  {
    v5 = qword_192B0;
    v6 = dcgettext(0, "%s: group '%s' does not exist\n", 5);
    __fprintf_chk(stderr, 1, v6, v5);
    exit(6);
  }
  dword_19334 = *(int *)(v3 + 16);
  if ( byte_192C2 )
    sub_5520();
  if ( byte_192C1 )
    sub_55A0();
  sub_5680();
  sub_5760();
  sub_5C30();
  sub_62E0();
  sub_5FE0();
  sub_A2D0("group");
  sub_A510(2);
  return 0;
}


// Function: usage @ 0x5210
void usage(int status)
{
  long long v1; // r13
  FILE *v2; // rbp
  char *v3; // rax
  char *v4; // rax
  char *v5; // rax
  char *v6; // rax
  char *v7; // rax
  char *v8; // rax
  char *v9; // rax
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax

  v1 = qword_192B0;
  v2 = (FILE *)stderr;
  if ( !status )
    v2 = stdout;
  v3 = dcgettext(0, "Usage: %s [options] GROUP\n\nOptions:\n", 5);
  __fprintf_chk(v2, 1, v3, v1);
  v4 = dcgettext(
         0,
         "  -a, --append                  append the users mentioned by -U option to the group \n"
         "                                without removing existing user members\n",
         5);
  fputs(v4, v2);
  v5 = dcgettext(0, "  -g, --gid GID                 change the group ID to GID\n", 5);
  fputs(v5, v2);
  v6 = dcgettext(0, "  -h, --help                    display this help message and exit\n", 5);
  fputs(v6, v2);
  v7 = dcgettext(0, "  -n, --new-name NEW_GROUP      change the name to NEW_GROUP\n", 5);
  fputs(v7, v2);
  v8 = dcgettext(0, "  -o, --non-unique              allow to use a duplicate (non-unique) GID\n", 5);
  fputs(v8, v2);
  v9 = dcgettext(
         0,
         "  -p, --password PASSWORD       change the password to this (encrypted)\n"
         "                                PASSWORD\n",
         5);
  fputs(v9, v2);
  v10 = dcgettext(0, "  -R, --root CHROOT_DIR         directory to chroot into\n", 5);
  fputs(v10, v2);
  v11 = dcgettext(0, "  -P, --prefix PREFIX_DIR       prefix directory where are located the /etc/* files\n", 5);
  fputs(v11, v2);
  v12 = dcgettext(0, "  -U, --users USERS             list of user members of this group\n", 5);
  fputs(v12, v2);
  fputs("\n", v2);
  exit(status);
}


// Function: process_flags @ 0x5380
char *process_flags(int a1, char *const *a2)
{
  int v2; // eax
  long long v3; // r12
  char *v4; // rax
  char *result; // rax

  while ( 2 )
  {
    v2 = getopt_long(a1, a2, "ag:hn:op:R:P:U:", &longopts, 0);
    if ( v2 != -1 )
    {
      switch ( v2 )
      {
        case 'P':
        case 'R':
          continue;
        case 'U':
          qword_19328 = optarg;
          continue;
        case 'a':
          byte_192C4 = 1;
          continue;
        case 'g':
          byte_192C2 = 1;
          if ( !(unsigned int)sub_9570(optarg) || gid == -1 )
          {
            v3 = qword_192B0;
            v4 = dcgettext(0, "%s: invalid group ID '%s'\n", 5);
            __fprintf_chk(stderr, 1, v4, v3);
            exit(3);
          }
          continue;
        case 'h':
          sub_5210(0);
        case 'n':
          byte_192C1 = 1;
          s2 = optarg;
          continue;
        case 'o':
          byte_192C3 = 1;
          continue;
        case 'p':
          byte_192C0 = 1;
          qword_19338 = (long long)optarg;
          continue;
        default:
          goto LABEL_15;
      }
    }
    break;
  }
  if ( byte_192C3 && !byte_192C2 || a1 - 1 != optind )
LABEL_15:
    sub_5210(2);
  result = a2[a1 - 1];
  s1 = result;
  return result;
}


// Function: check_new_gid @ 0x5520
void check_new_gid()
{
  long long v0; // r12
  char *v1; // rax

  if ( dword_19334 == gid )
  {
    byte_192C2 = 0;
  }
  else if ( !byte_192C3 )
  {
    if ( getgrgid(gid) )
    {
      v0 = qword_192B0;
      v1 = dcgettext(0, "%s: GID '%lu' already exists\n", 5);
      __fprintf_chk(stderr, 1, v1, v0);
      exit(4);
    }
  }
}


// Function: check_new_name @ 0x55a0
int check_new_name()
{
  char *v0; // rbp
  long long v1; // rax
  long long v2; // r12
  char *v3; // rax
  long long v4; // r12
  char *v5; // rax

  v0 = s2;
  LODWORD(v1) = strcmp(s1, s2);
  if ( (int)v1 )
  {
    if ( !(unsigned char)sub_6800(v0) )
    {
      v4 = qword_192B0;
      v5 = dcgettext(0, "%s: invalid group name '%s'\n", 5);
      __fprintf_chk(stderr, 1, v5, v4);
      exit(3);
    }
    v1 = sub_7FB0(s2);
    if ( v1 )
    {
      v2 = qword_192B0;
      v3 = dcgettext(0, "%s: group '%s' already exists\n", 5);
      __fprintf_chk(stderr, 1, v3, v2);
      exit(9);
    }
  }
  else
  {
    byte_192C1 = 0;
  }
  return v1;
}


// Function: lock_files @ 0x5680
long long lock_files()
{
  long long result; // rax
  long long v1; // r12
  char *v2; // rax

  if ( !(unsigned int)sub_9E90() )
  {
    sub_9E80();
    goto LABEL_11;
  }
  result = sub_6890(sub_7000, 0);
  if ( byte_19350 && (byte_192C0 || byte_192C1) )
  {
    if ( !(unsigned int)sub_CB10() )
    {
      sub_CAD0();
      goto LABEL_11;
    }
    result = sub_6890(sub_7100, 0);
  }
  if ( !byte_192C2 )
    return result;
  if ( !(unsigned int)sub_AAD0() )
  {
    sub_AAC0();
LABEL_11:
    v1 = qword_192B0;
    v2 = dcgettext(0, "%s: cannot lock %s; try again later.\n", 5);
    __fprintf_chk(stderr, 1, v2, v1);
    exit(10);
  }
  return sub_6890(sub_74D0, 0);
}


// Function: prepare_failure_reports @ 0x5760
long long prepare_failure_reports()
{
  const char *v0; // rax
  const char *v1; // rax
  const char *v2; // rax
  const char *v3; // r12
  size_t v4; // rax
  char *v5; // rbx
  const char *v6; // rbp
  char *v7; // rbx
  size_t v8; // rax
  size_t v9; // rax
  size_t v10; // rax
  long long result; // rax
  size_t v12; // rax
  size_t v13; // rax
  char *v14; // rbp
  size_t v15; // r12
  size_t v16; // rax
  size_t v17; // rax
  size_t v18; // rax
  char *v19; // rbp
  size_t v20; // rbx
  size_t v21; // rax
  size_t v22; // rax
  size_t v23; // rax
  size_t v24; // rax
  size_t v25; // rax
  const char *v26; // rbp
  size_t v27; // rax
  size_t v28; // rax
  size_t v29; // rax
  size_t v30; // rax

  qword_19300 = (long long)s1;
  qword_192E0 = (long long)s1;
  qword_19320 = (long long)s1;
  s = (char *)sub_8800(512);
  qword_192D0 = (char *)sub_8800(512);
  qword_19310 = (char *)sub_8800(512);
  v0 = (const char *)sub_9E80();
  __snprintf_chk(s, 511, 1, -1, "changing %s; ", v0);
  v1 = (const char *)sub_CAD0();
  __snprintf_chk(qword_192D0, 511, 1, -1, "changing %s; ", v1);
  v2 = (const char *)sub_AAC0();
  __snprintf_chk(qword_19310, 511, 1, -1, "changing %s; ", v2);
  v3 = s;
  v4 = strlen(s);
  v5 = qword_192D0;
  v6 = &v3[v4];
  dest = (char *)&v3[v4];
  qword_192D8 = &v5[strlen(qword_192D0)];
  v7 = qword_19310;
  qword_19318 = &v7[strlen(qword_19310)];
  v8 = strlen(v3);
  __snprintf_chk(v6, 511 - v8, 1, -1, "group %s/%lu", s1, (unsigned int)dword_19334);
  v9 = strlen(s);
  __snprintf_chk(qword_192D8, 511 - v9, 1, -1, "group %s", s1);
  v10 = strlen(s);
  __snprintf_chk(qword_19318, 511 - v10, 1, -1, "group %s/%lu", s1, (unsigned int)dword_19334);
  if ( byte_192C1 )
  {
    v24 = strlen(s);
    strncat(dest, ", new name: ", 511 - v24);
    v25 = strlen(s);
    v26 = s2;
    strncat(dest, s2, 511 - v25);
    v27 = strlen(qword_192D0);
    strncat(qword_192D8, ", new name: ", 511 - v27);
    v28 = strlen(qword_192D0);
    strncat(qword_192D8, v26, 511 - v28);
    v29 = strlen(qword_19310);
    strncat(qword_19318, ", new name: ", 511 - v29);
    v30 = strlen(qword_19310);
    strncat(qword_19318, v26, 511 - v30);
  }
  if ( byte_192C0 )
  {
    v22 = strlen(s);
    strncat(dest, ", new password", 511 - v22);
    v23 = strlen(qword_192D0);
    strncat(qword_192D8, ", new password", 511 - v23);
  }
  if ( byte_192C2 )
  {
    v12 = strlen(s);
    strncat(dest, ", new gid: ", 511 - v12);
    v13 = strlen(s);
    v14 = dest;
    v15 = v13;
    v16 = strlen(dest);
    __snprintf_chk(&v14[v16], 511 - v15, 1, -1, "%lu", gid);
    v17 = strlen(qword_19310);
    strncat(qword_19318, ", new gid: ", 511 - v17);
    v18 = strlen(qword_19310);
    v19 = qword_19318;
    v20 = 511 - v18;
    v21 = strlen(qword_19318);
    __snprintf_chk(&v19[v21], v20, 1, -1, "%lu", gid);
  }
  s[511] = 0;
  qword_192D0[511] = 0;
  qword_19310[511] = 0;
  result = sub_6890(sub_6BC0, &s);
  if ( byte_19350 && (byte_192C0 || byte_192C1) )
    result = sub_6890(sub_6C80, &qword_192D0);
  if ( byte_192C2 )
    return sub_6890(sub_72B0, &qword_19310);
  return result;
}


// Function: open_files @ 0x5c30
long long open_files()
{
  long long result; // rax
  long long v1; // r12
  char *v2; // rax
  char *v3; // rdi
  char *v4; // rbp
  const char *v5; // rax
  long long v6; // r12
  char *v7; // rax
  char *v8; // rdi
  const char *v9; // rax

  result = sub_9EA0(66);
  if ( !(int)result )
  {
    ((void (*)(void))sub_9E80)();
LABEL_13:
    v6 = qword_192B0;
    v7 = dcgettext(0, "%s: cannot open %s\n", 5);
    __fprintf_chk(stderr, 1, v7, v6);
    v8 = setlocale(6, 0);
    if ( v8 )
    {
      v4 = strdup(v8);
      if ( v4 )
      {
        setlocale(6, "C");
        v5 = (const char *)sub_9E80(6);
        goto LABEL_16;
      }
    }
    v9 = (const char *)sub_9E80(v8);
LABEL_20:
    __syslog_chk(4, 1, "cannot open %s", v9);
LABEL_17:
    exit(10);
  }
  if ( byte_19350 && (byte_192C0 || byte_192C1) )
  {
    result = sub_CB20(66);
    if ( !(int)result )
    {
      ((void (*)(void))sub_CAD0)();
      v1 = qword_192B0;
      v2 = dcgettext(0, "%s: cannot open %s\n", 5);
      __fprintf_chk(stderr, 1, v2, v1);
      v3 = setlocale(6, 0);
      if ( v3 )
      {
        v4 = strdup(v3);
        if ( v4 )
        {
          setlocale(6, "C");
          v5 = (const char *)sub_CAD0(6);
LABEL_16:
          __syslog_chk(4, 1, "cannot open %s", v5);
          setlocale(6, v4);
          free(v4);
          goto LABEL_17;
        }
      }
      v9 = (const char *)sub_CAD0(v3);
      goto LABEL_20;
    }
  }
  if ( byte_192C2 )
  {
    result = sub_AAE0(66);
    if ( !(int)result )
    {
      sub_AAC0();
      goto LABEL_13;
    }
  }
  return result;
}


// Function: new_grent @ 0x5e10
void new_grent(long long a1)
{
  if ( byte_192C1 )
    *(long long *)a1 = sub_8870(s2);
  if ( byte_192C2 )
    *(int *)(a1 + 16) = gid;
  if ( byte_192C0 && (!byte_19350 || strcmp(*(const char **)(a1 + 8), "x")) )
    *(long long *)(a1 + 8) = qword_19338;
}


// Function: new_sgent @ 0x5e80
void new_sgent(long long *a1)
{
  if ( byte_192C1 )
    *a1 = sub_8870(s2);
  if ( byte_192C0 )
    a1[1] = qword_19338;
}


// Function: update_primary_groups @ 0x5ec0
long long update_primary_groups(int a1, int a2)
{
  long long v2; // rax
  const __m128i *v4; // rax
  __m128i v5; // xmm2
  long long v6; // r12
  const char *v7; // rsi
  char *v8; // rax
  __m128i v9; // [rsp+0h] [rbp-68h] BYREF
  __m128i v10; // [rsp+10h] [rbp-58h]
  __m128i v11; // [rsp+20h] [rbp-48h]
  unsigned long long v12; // [rsp+38h] [rbp-30h]

  v12 = __readfsqword(0x28u);
  sub_8230();
  while ( 1 )
  {
    v2 = sub_8290();
    if ( !v2 )
      return sub_82C0();
    if ( *(int *)(v2 + 20) == a1 )
    {
      v4 = (const __m128i *)sub_AB00(*(long long *)v2);
      if ( !v4 )
      {
        sub_AAC0();
        v6 = qword_192B0;
        v7 = "%s: user '%s' does not exist in %s\n";
LABEL_8:
        v8 = dcgettext(0, v7, 5);
        __fprintf_chk(stderr, 1, v8, v6);
        exit(10);
      }
      v9 = _mm_loadu_si128(v4);
      v10 = _mm_loadu_si128(v4 + 1);
      v5 = _mm_loadu_si128(v4 + 2);
      v10.m128i_i32[1] = a2;
      v11 = v5;
      if ( !(unsigned int)sub_AB20(&v9) )
      {
        sub_AAC0();
        v6 = qword_192B0;
        v7 = "%s: failed to prepare the new %s entry '%s'\n";
        goto LABEL_8;
      }
    }
  }
}


// Function: close_files @ 0x5fe0
long long close_files(long long a1)
{
  char *v1; // rdi
  char *v2; // rbp
  const char *v3; // r12
  const char *v4; // rax
  long long result; // rax
  char *v6; // rdi
  char *v7; // rbp
  const char *v8; // rbx
  const char *v9; // rax
  const char *v10; // rbp
  const char *v11; // rax
  char *v12; // rdi
  char *v13; // rbp
  const char *v14; // rbx
  const char *v15; // rax
  const char *v16; // rbx
  const char *v17; // rax
  const char *v18; // rbx
  const char *v19; // rax
  long long v20; // r12
  char *v21; // rax

  if ( !(unsigned int)sub_9F70() )
  {
    sub_9E80(a1);
    goto LABEL_24;
  }
  v1 = setlocale(6, 0);
  if ( v1 && (v2 = strdup(v1)) != 0 )
  {
    setlocale(6, "C");
    v3 = dest;
    v4 = (const char *)sub_9E80(6);
    __syslog_chk(6, 1, "group changed in %s (%s)", v4, v3);
    setlocale(6, v2);
    free(v2);
  }
  else
  {
    v10 = dest;
    v11 = (const char *)sub_9E80(v1);
    __syslog_chk(6, 1, "group changed in %s (%s)", v11, v10);
  }
  sub_6970(sub_6BC0);
  sub_7000(0);
  result = sub_6970(sub_7000);
  if ( byte_19350 && (byte_192C0 || byte_192C1) )
  {
    if ( !(unsigned int)sub_CBC0() )
    {
      sub_CAD0(sub_7000);
      goto LABEL_24;
    }
    v6 = setlocale(6, 0);
    if ( v6 && (v7 = strdup(v6)) != 0 )
    {
      setlocale(6, "C");
      v8 = qword_192D8;
      v9 = (const char *)sub_CAD0(6);
      __syslog_chk(6, 1, "group changed in %s (%s)", v9, v8);
      setlocale(6, v7);
      free(v7);
    }
    else
    {
      v16 = qword_192D8;
      v17 = (const char *)sub_CAD0(v6);
      __syslog_chk(6, 1, "group changed in %s (%s)", v17, v16);
    }
    sub_6970(sub_6C80);
    sub_7100(0);
    result = sub_6970(sub_7100);
  }
  if ( !byte_192C2 )
    return result;
  if ( !(unsigned int)sub_ABB0() )
  {
    ((void (*)(void))sub_AAC0)();
LABEL_24:
    v20 = qword_192B0;
    v21 = dcgettext(0, "%s: failure while writing changes to %s\n", 5);
    __fprintf_chk(stderr, 1, v21, v20);
    exit(10);
  }
  v12 = setlocale(6, 0);
  if ( v12 && (v13 = strdup(v12)) != 0 )
  {
    setlocale(6, "C");
    v14 = qword_19318;
    v15 = (const char *)sub_AAC0(6);
    __syslog_chk(6, 1, "group changed in %s (%s)", v15, v14);
    setlocale(6, v13);
    free(v13);
  }
  else
  {
    v18 = qword_19318;
    v19 = (const char *)sub_AAC0(v12);
    __syslog_chk(6, 1, "group changed in %s (%s)", v19, v18);
  }
  sub_6970(sub_72B0);
  sub_74D0(0);
  return sub_6970(sub_74D0);
}


// Function: grp_update @ 0x62e0
unsigned long long grp_update()
{
  char *v0; // rdi
  const __m128i *v1; // rax
  const __m128i *v2; // rbx
  __m128i *v3; // r12
  long long v4; // rax
  char *i; // rbp
  const __m128i *v7; // rax
  char *v8; // rdi
  char *v9; // rdi
  long long v10; // r12
  const char *v11; // rsi
  long long v12; // rcx
  __m128i *v13; // rdi
  char *v14; // rax
  char *v15; // rdx
  char *s1[2]; // [rsp+0h] [rbp-78h] BYREF
  __m128i v17; // [rsp+10h] [rbp-68h]
  __m128i v18; // [rsp+20h] [rbp-58h] BYREF
  __m128i v19; // [rsp+30h] [rbp-48h]
  unsigned long long v20; // [rsp+48h] [rbp-30h]

  v0 = ::s1;
  v20 = __readfsqword(0x28u);
  v1 = (const __m128i *)sub_9EC0(::s1);
  if ( !v1 )
  {
    sub_9E80(v0);
    v10 = qword_192B0;
    v11 = "%s: group '%s' does not exist in %s\n";
    goto LABEL_39;
  }
  v2 = v1;
  *(__m128i *)s1 = _mm_loadu_si128(v1);
  v17 = _mm_loadu_si128(v1 + 1);
  sub_5E10((long long)s1);
  if ( !byte_19350 || !byte_192C0 && !byte_192C1 )
    goto LABEL_3;
  v7 = (const __m128i *)sub_CB40(::s1);
  v3 = (__m128i *)v7;
  if ( v7 )
  {
    v18 = _mm_loadu_si128(v7);
    v19 = _mm_loadu_si128(v7 + 1);
    sub_5E80(&v18);
    goto LABEL_4;
  }
  if ( !byte_192C0 || strcmp(s1[1], "x") )
  {
LABEL_3:
    v3 = 0;
    goto LABEL_4;
  }
  v3 = &v18;
  v12 = 8;
  v13 = &v18;
  while ( v12 )
  {
    v13->m128i_i32[0] = 0;
    v13 = (__m128i *)((char *)v13 + 4);
    --v12;
  }
  v18.m128i_i64[0] = sub_8870(s1[0]);
  v18.m128i_i64[1] = sub_8870(s1[1]);
  v19.m128i_i64[0] = (long long)&unk_192B8;
  v19.m128i_i64[1] = sub_7910(v17.m128i_i64[1]);
  sub_5E80(&v18);
LABEL_4:
  if ( byte_192C2 )
    sub_5EC0(v2[1].m128i_i32[0], gid);
  if ( qword_19328 )
  {
    v4 = *(long long *)v17.m128i_i64[1];
    if ( byte_192C4 )
    {
      if ( v4 )
        v17.m128i_i64[1] = sub_7910(v17.m128i_i64[1]);
    }
    else
    {
      if ( v4 )
        sub_A000(s1);
      v17.m128i_i64[1] = sub_8800(8);
      *(long long *)v17.m128i_i64[1] = 0;
    }
    for ( i = strtok(qword_19328, ","); i; i = strtok(0, ",") )
    {
      if ( !sub_8130(i) )
      {
        v14 = dcgettext(0, "Invalid member username %s\n", 5);
        __fprintf_chk(stderr, 1, v14, i);
        exit(10);
      }
      v17.m128i_i64[1] = sub_76D0(v17.m128i_i64[1], i);
    }
  }
  if ( !(unsigned int)sub_9EE0(s1) )
  {
    sub_9E80(s1);
    goto LABEL_42;
  }
  if ( byte_192C1 )
  {
    v8 = ::s1;
    if ( !(unsigned int)sub_9F00(::s1) )
    {
      sub_9E80(v8);
LABEL_30:
      v10 = qword_192B0;
      v11 = "%s: cannot remove entry '%s' from %s\n";
LABEL_39:
      v15 = dcgettext(0, v11, 5);
      goto LABEL_40;
    }
  }
  if ( v3 )
  {
    if ( (unsigned int)sub_CB60(&v18) )
    {
      if ( byte_192C1 )
      {
        v9 = ::s1;
        if ( !(unsigned int)sub_CB80(::s1) )
        {
          sub_CAD0(v9);
          goto LABEL_30;
        }
      }
      return v20 - __readfsqword(0x28u);
    }
    sub_CAD0(&v18);
LABEL_42:
    v10 = qword_192B0;
    v15 = dcgettext(0, "%s: failed to prepare the new %s entry '%s'\n", 5);
LABEL_40:
    __fprintf_chk(stderr, 1, v15, v10);
    exit(10);
  }
  return v20 - __readfsqword(0x28u);
}


