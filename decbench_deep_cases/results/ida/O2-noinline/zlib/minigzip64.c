// Function: main @ 0x2400
long long main(int a1, const char **a2, char **a3)
{
  const char *v3; // r12
  char *v4; // rax
  int v5; // ebp
  const char **v6; // rbx
  int v7; // r13d
  const char *v8; // r14
  int v9; // eax
  long long v10; // rsi
  int v12; // eax
  long long v13; // rdi
  const char **v14; // rbp
  long long v15; // rdi
  char *v16; // rdi
  FILE *v17; // rax
  int v18; // eax
  int v19; // [rsp+4h] [rbp-64h]
  FILE *v20; // [rsp+8h] [rbp-60h]
  char v21[24]; // [rsp+10h] [rbp-58h] BYREF
  unsigned long long v22; // [rsp+28h] [rbp-40h]

  v3 = *a2;
  v22 = __readfsqword(0x28u);
  strcpy(v21, "wb6 ");
  qword_17050 = (long long)v3;
  v4 = strrchr(v3, 47);
  if ( v4 )
    v3 = v4 + 1;
  v5 = a1 - 1;
  v6 = a2 + 1;
  v19 = 1;
  v7 = strcmp(v3, "gunzip");
  if ( v7 )
  {
    v19 = strcmp(v3, "zcat") == 0;
    v7 = v19;
  }
  if ( v5 <= 0 )
  {
    if ( v21[3] == 32 )
LABEL_30:
      v21[3] = 0;
    if ( v5 )
    {
LABEL_32:
      v14 = &v6[v5];
      while ( 1 )
      {
        v16 = (char *)*v6;
        if ( v19 )
        {
          if ( v7 )
          {
            v15 = sub_3320(v16, "rb");
            if ( v15 )
              sub_29A0(v15, stdout);
            else
              __fprintf_chk(stderr, 1, "%s: can't gzopen %s\n", (const char *)qword_17050, *v6);
          }
          else
          {
            sub_2BF0(v16);
          }
        }
        else if ( v7 )
        {
          v17 = fopen64(v16, "rb");
          if ( v17 )
          {
            v20 = v17;
            v18 = fileno(stdout);
            v10 = sub_3350(v18);
            if ( !v10 )
              goto LABEL_48;
            sub_28A0(v20, v10);
          }
          else
          {
            perror(*v6);
          }
        }
        else
        {
          sub_2AA0(v16);
        }
        if ( ++v6 == v14 )
          return 0;
      }
    }
  }
  else
  {
    do
    {
      while ( 1 )
      {
        v8 = *v6;
        if ( !strcmp(*v6, "-c") )
          break;
        if ( !strcmp(v8, "-d") )
        {
          v19 = 1;
        }
        else if ( !strcmp(v8, "-f") )
        {
          v21[3] = 102;
        }
        else if ( !strcmp(v8, "-h") )
        {
          v21[3] = 104;
        }
        else if ( !strcmp(v8, "-r") )
        {
          v21[3] = 82;
        }
        else
        {
          if ( *v8 != 45 || (unsigned char)(v8[1] - 49) > 8u || v8[2] )
          {
            if ( v21[3] == 32 )
              goto LABEL_30;
            goto LABEL_32;
          }
          v21[2] = v8[1];
        }
        ++v6;
        if ( !--v5 )
          goto LABEL_13;
      }
      v7 = 1;
      ++v6;
      --v5;
    }
    while ( v5 );
LABEL_13:
    if ( v21[3] == 32 )
      goto LABEL_30;
  }
  if ( v19 )
  {
    v12 = fileno(stdin);
    v13 = sub_3350(v12);
    if ( !v13 )
      error("can't gzdopen stdin", "rb");
    sub_29A0(v13, stdout);
  }
  else
  {
    v9 = fileno(stdout);
    v10 = sub_3350(v9);
    if ( !v10 )
LABEL_48:
      error("can't gzdopen stdout", v10);
    sub_28A0(stdin, v10);
  }
  return 0;
}


// Function: error @ 0x2860
void error(const char *a1)
{
  __fprintf_chk(stderr, 1, "%s: %s\n", (const char *)qword_17050, a1);
  exit(1);
}


// Function: gz_compress @ 0x28a0
// positive sp value has been detected, the output may be wrong!
unsigned long long gz_compress(FILE *a1, long long a2)
{
  unsigned int v2; // ebx
  const char *v4; // rax
  int v5; // [rsp-14h] [rbp-403Ch] BYREF
  char v6[16]; // [rsp-10h] [rbp-4038h] BYREF
  char v7; // [rsp+0h] [rbp-4028h] BYREF
  long long v8; // [rsp+1000h] [rbp-3028h] BYREF
  unsigned long long v9; // [rsp+3FF8h] [rbp-30h]

  while ( &v7 != (char *)(&v8 - 2048) )
    ;
  v9 = __readfsqword(0x28u);
  while ( 1 )
  {
    v2 = fread(v6, 1u, 0x4000u, a1);
    if ( ferror(a1) )
    {
      perror("fread");
      exit(1);
    }
    if ( !v2 )
      break;
    if ( (unsigned int)((long long (*)(long long, char *, long long))sub_4910)(a2, v6, v2) != v2 )
    {
      v4 = (const char *)((long long (*)(long long, int *))sub_2EF0)(a2, &v5);
      error(v4);
    }
  }
  fclose(a1);
  if ( (unsigned int)((long long (*)(long long))sub_2D90)(a2) )
    error("failed gzclose");
  return v9 - __readfsqword(0x28u);
}


// Function: gz_uncompress @ 0x29a0
// positive sp value has been detected, the output may be wrong!
unsigned long long gz_uncompress(long long a1, FILE *a2)
{
  int v2; // eax
  const char *v4; // rax
  int v5; // [rsp-1Ch] [rbp-403Ch] BYREF
  char v6[24]; // [rsp-18h] [rbp-4038h] BYREF
  char v7; // [rsp+0h] [rbp-4020h] BYREF
  long long v8; // [rsp+1000h] [rbp-3020h] BYREF
  unsigned long long v9; // [rsp+3FF0h] [rbp-30h]

  while ( &v7 != (char *)(&v8 - 2048) )
    ;
  v9 = __readfsqword(0x28u);
  while ( 1 )
  {
    v2 = ((long long (*)(long long, char *, long long))sub_3E00)(a1, v6, 0x4000);
    if ( v2 < 0 )
    {
      v4 = (const char *)((long long (*)(long long, int *))sub_2EF0)(a1, &v5);
      error(v4);
    }
    if ( !v2 )
      break;
    if ( v2 != (unsigned int)fwrite(v6, 1u, v2, a2) )
      error("failed fwrite");
  }
  if ( fclose(a2) )
    error("failed fclose");
  if ( (unsigned int)((long long (*)(long long))sub_2D90)(a1) )
    error("failed gzclose");
  return v9 - __readfsqword(0x28u);
}


// Function: file_compress @ 0x2aa0
unsigned long long file_compress(char *s, long long a2)
{
  size_t v2; // rbx
  FILE *v3; // r12
  long long v4; // rsi
  char v6[1032]; // [rsp+0h] [rbp-438h] BYREF
  unsigned long long v7; // [rsp+408h] [rbp-30h]

  v7 = __readfsqword(0x28u);
  v2 = strlen(s);
  if ( strlen(".gz") + v2 > 0x3FF )
  {
    __fprintf_chk(stderr, 1, "%s: filename too long\n", (const char *)qword_17050);
    exit(1);
  }
  __snprintf_chk(v6, 1024, 1, 1024, "%s%s", s, ".gz");
  v3 = fopen64(s, "rb");
  if ( !v3 )
  {
    perror(s);
    exit(1);
  }
  v4 = sub_3320(v6, a2);
  if ( !v4 )
  {
    __fprintf_chk(stderr, 1, "%s: can't gzopen %s\n", (const char *)qword_17050, v6);
    exit(1);
  }
  sub_28A0(v3, v4);
  unlink(s);
  return v7 - __readfsqword(0x28u);
}


// Function: file_uncompress @ 0x2bf0
unsigned long long file_uncompress(char *s)
{
  size_t v1; // rbx
  const char *v2; // r15
  const char *v3; // r13
  long long v4; // r12
  FILE *v5; // rsi
  char v7[3]; // [rsp+1h] [rbp-44Bh]
  char v8[1032]; // [rsp+4h] [rbp-448h] BYREF
  unsigned long long v9; // [rsp+40Ch] [rbp-40h]

  v9 = __readfsqword(0x28u);
  v1 = strlen(s);
  if ( v1 + strlen(".gz") > 0x3FF )
  {
    __fprintf_chk(stderr, 1, "%s: filename too long\n", (const char *)qword_17050);
    exit(1);
  }
  snprintf(v8, 0x400u, "%s", s);
  if ( v1 > 3 && !strcmp(&s[v1 - 3], ".gz") )
  {
    v7[v1] = 0;
    v3 = s;
    v2 = v8;
  }
  else
  {
    v2 = s;
    v3 = v8;
    snprintf(&v8[v1], 1024 - v1, "%s", ".gz");
  }
  v4 = sub_3320(v3, "rb");
  if ( !v4 )
  {
    __fprintf_chk(stderr, 1, "%s: can't gzopen %s\n", (const char *)qword_17050, v3);
    exit(1);
  }
  v5 = fopen64(v2, "wb");
  if ( !v5 )
  {
    perror(s);
    exit(1);
  }
  sub_29A0(v4, v5);
  unlink(v3);
  return v9 - __readfsqword(0x28u);
}


// Function: gzclose @ 0x2d90
long long gzclose(int *a1)
{
  if ( !a1 )
    return 4294967294LL;
  if ( a1[6] == 7247 )
    return sub_42C0(a1);
  return sub_4F30(a1);
}


// Function: gzerror @ 0x2ef0
char *gzerror(long long a1, int *a2)
{
  int v2; // edx
  char *result; // rax

  if ( !a1 )
    return 0;
  v2 = *(int *)(a1 + 24);
  if ( v2 == 7247 || (result = 0, v2 == 31153) )
  {
    if ( a2 )
      *a2 = *(int *)(a1 + 116);
    result = "out of memory";
    if ( *(int *)(a1 + 116) != -4 )
    {
      result = *(char **)(a1 + 120);
      if ( !result )
        return "";
    }
  }
  return result;
}


// Function: gz_error @ 0x2f50
void gz_error(long long a1, int a2, const char *a3)
{
  void *v5; // rdi
  size_t v6; // rbp
  size_t v7; // rax
  void *v8; // rax
  void *v9; // rbp
  const char *v10; // r13
  size_t v11; // rbx
  size_t v12; // rax

  v5 = *(void **)(a1 + 120);
  if ( v5 )
  {
    if ( *(int *)(a1 + 116) != -4 )
      free(v5);
    *(long long *)(a1 + 120) = 0;
  }
  if ( a2 && a2 != -5 )
    *(int *)a1 = 0;
  *(int *)(a1 + 116) = a2;
  if ( a2 != -4 && a3 )
  {
    v6 = strlen(*(const char **)(a1 + 32));
    v7 = strlen(a3);
    v8 = malloc(v6 + v7 + 3);
    *(long long *)(a1 + 120) = v8;
    v9 = v8;
    if ( v8 )
    {
      v10 = *(const char **)(a1 + 32);
      v11 = strlen(v10);
      v12 = strlen(a3);
      __snprintf_chk(v9, v11 + v12 + 3, 1, -1, "%s%s%s", v10, ": ", a3);
    }
    else
    {
      *(int *)(a1 + 116) = -4;
    }
  }
}


// Function: gz_reset @ 0x3040
void gz_reset(long long a1)
{
  bool v1; // zf

  v1 = *(int *)(a1 + 24) == 7247;
  *(int *)a1 = 0;
  if ( v1 )
  {
    *(long long *)(a1 + 80) = 0;
    *(int *)(a1 + 68) = 0;
  }
  else
  {
    *(int *)(a1 + 96) = 0;
  }
  *(int *)(a1 + 112) = 0;
  sub_2F50(a1, 0, 0);
  *(long long *)(a1 + 16) = 0;
  *(int *)(a1 + 136) = 0;
}


// Function: gz_open @ 0x30a0
long long gz_open(char *file, int fd, char *a3)
{
  long long *v5; // rax
  long long v6; // r13
  int v7; // r12d
  int v8; // ebx
  char v9; // al
  int v11; // eax
  size_t v12; // r15
  char *v13; // rax
  int v14; // eax
  int v15; // esi
  int v16; // ecx
  int v17; // eax
  __off64_t v18; // rax

  if ( !file )
    return 0;
  v5 = malloc(0xF0u);
  v6 = (long long)v5;
  if ( !v5 )
    return 0;
  v7 = 0;
  v8 = 0;
  v5[15] = 0;
  v5[5] = 0x200000000000LL;
  v5[11] = 0xFFFFFFFFLL;
  v9 = *a3;
  *(int *)(v6 + 24) = 0;
  *(int *)(v6 + 64) = 0;
  if ( !v9 )
  {
LABEL_10:
    free((void *)v6);
    return 0;
  }
  do
  {
    while ( 2 )
    {
      if ( (unsigned char)(v9 - 48) > 9u )
      {
        switch ( v9 )
        {
          case '+':
            goto LABEL_10;
          case 'F':
            *(int *)(v6 + 92) = 4;
            goto LABEL_6;
          case 'R':
            *(int *)(v6 + 92) = 3;
            goto LABEL_6;
          case 'T':
            *(int *)(v6 + 64) = 1;
            goto LABEL_6;
          case 'a':
            *(int *)(v6 + 24) = 1;
            goto LABEL_6;
          case 'e':
            v8 = 1;
            goto LABEL_6;
          case 'f':
            *(int *)(v6 + 92) = 1;
            goto LABEL_6;
          case 'h':
            *(int *)(v6 + 92) = 2;
            goto LABEL_6;
          case 'r':
            *(int *)(v6 + 24) = 7247;
            goto LABEL_6;
          case 'w':
            *(int *)(v6 + 24) = 31153;
            goto LABEL_6;
          case 'x':
            v9 = *++a3;
            v7 = 1;
            if ( !v9 )
              goto LABEL_14;
            continue;
          default:
            goto LABEL_6;
        }
      }
      break;
    }
    *(int *)(v6 + 88) = (char)(v9 - 48);
LABEL_6:
    v9 = *++a3;
  }
  while ( v9 );
LABEL_14:
  v11 = *(int *)(v6 + 24);
  if ( !v11 )
    goto LABEL_10;
  if ( v11 == 7247 )
  {
    if ( *(int *)(v6 + 64) )
      goto LABEL_10;
    *(int *)(v6 + 64) = 1;
  }
  v12 = strlen(file) + 1;
  v13 = (char *)malloc(v12);
  *(long long *)(v6 + 32) = v13;
  if ( !v13 )
    goto LABEL_10;
  snprintf(v13, v12, "%s", file);
  v14 = *(int *)(v6 + 24);
  v15 = v8 << 19;
  if ( v14 != 7247 )
  {
    v16 = 1024;
    if ( v14 == 31153 )
      v16 = 512;
    v15 |= v16 | (v7 == 0 ? 65 : 193);
  }
  if ( fd < 0 )
  {
    v17 = open(file, v15, 438);
    *(int *)(v6 + 28) = v17;
    fd = v17;
    if ( v17 == -1 )
    {
      free(*(void **)(v6 + 32));
      goto LABEL_10;
    }
    v14 = *(int *)(v6 + 24);
  }
  else
  {
    *(int *)(v6 + 28) = fd;
  }
  if ( v14 == 1 )
  {
    lseek64(fd, 0, 2);
    *(int *)(v6 + 24) = 31153;
  }
  else if ( v14 == 7247 )
  {
    v18 = lseek64(*(int *)(v6 + 28), 0, 1);
    if ( v18 == -1 )
      v18 = 0;
    *(long long *)(v6 + 72) = v18;
  }
  sub_3040(v6);
  return v6;
}


// Function: gzopen64 @ 0x3320
long long gzopen64(char *a1, char *a2)
{
  return sub_30A0(a1, -1, a2);
}


// Function: gzdopen @ 0x3350
long long gzdopen(int fd, char *a2)
{
  char *v2; // rax
  char *v3; // rbp
  long long v4; // r12

  if ( fd == -1 )
    return 0;
  v2 = (char *)malloc(0x13u);
  v3 = v2;
  if ( !v2 )
    return 0;
  __snprintf_chk(v2, 19, 1, 19, "<fd:%d>", fd);
  v4 = sub_30A0(v3, fd, a2);
  free(v3);
  return v4;
}


// Function: gzrewind @ 0x33d0
long long gzrewind(long long a1)
{
  int v1; // eax

  if ( !a1 )
    return 0xFFFFFFFFLL;
  if ( *(int *)(a1 + 24) != 7247 )
    return 0xFFFFFFFFLL;
  v1 = *(int *)(a1 + 116);
  if ( v1 )
  {
    if ( v1 != -5 )
      return 0xFFFFFFFFLL;
  }
  if ( lseek64(*(int *)(a1 + 28), *(long long *)(a1 + 72), 0) == -1 )
    return 0xFFFFFFFFLL;
  sub_3040(a1);
  return 0;
}


// Function: gz_load @ 0x3610
long long gz_load(long long a1, long long a2, unsigned int a3, int *a4)
{
  long long v4; // rax
  size_t v7; // rdx
  int v8; // eax
  unsigned int v9; // r8d
  int *v11; // rax
  char *v12; // rax

  v4 = 0;
  *a4 = 0;
  while ( 1 )
  {
    v7 = a3 - (unsigned int)v4;
    if ( (unsigned int)v7 > 0x40000000 )
      v7 = 0x40000000;
    v8 = read(*(int *)(a1 + 28), (void *)(a2 + v4), v7);
    v9 = v8;
    if ( v8 <= 0 )
      break;
    v4 = (unsigned int)(*a4 + v8);
    *a4 = v4;
    if ( (unsigned int)v4 >= a3 )
      return 0;
  }
  if ( v8 )
  {
    v11 = __errno_location();
    v12 = strerror(*v11);
    sub_2F50(a1, -1, v12);
    return (unsigned int)-1;
  }
  else
  {
    *(int *)(a1 + 80) = 1;
  }
  return v9;
}


// Function: gz_avail @ 0x36c0
long long gz_avail(long long a1)
{
  int v2; // eax
  unsigned int v3; // r12d
  long long v4; // rdx
  long long v5; // rdi
  long long v6; // rsi
  long long i; // rax
  int v9; // [rsp+4h] [rbp-24h] BYREF
  unsigned long long v10; // [rsp+8h] [rbp-20h]

  v10 = __readfsqword(0x28u);
  v2 = *(int *)(a1 + 116);
  if ( v2 && v2 != -5 )
    return (unsigned int)-1;
  v3 = *(int *)(a1 + 80);
  if ( v3 )
    return 0;
  v4 = *(unsigned int *)(a1 + 136);
  if ( (int)v4 )
  {
    v5 = *(long long *)(a1 + 48);
    v6 = *(long long *)(a1 + 128);
    for ( i = 0; i != v4; ++i )
      *(char *)(v5 + i) = *(char *)(v6 + i);
    LODWORD(v4) = *(int *)(a1 + 136);
  }
  if ( (unsigned int)sub_3610(a1, *(long long *)(a1 + 48) + (unsigned int)v4, *(int *)(a1 + 40) - (int)v4, &v9) == -1 )
    return (unsigned int)-1;
  *(int *)(a1 + 136) += v9;
  *(long long *)(a1 + 128) = *(long long *)(a1 + 48);
  return v3;
}


// Function: gz_look @ 0x3790
long long gz_look(long long a1)
{
  long long v1; // r12
  size_t v3; // rdx
  char *v4; // rax
  long long result; // rax
  void *v6; // rdi
  const void *v7; // rsi
  int v8; // eax
  void *v9; // rax
  bool v10; // zf
  int v11; // eax

  v1 = a1 + 128;
  if ( !*(int *)(a1 + 40) )
  {
    *(long long *)(a1 + 48) = malloc(*(unsigned int *)(a1 + 44));
    v9 = malloc((unsigned int)(2 * *(int *)(a1 + 44)));
    v10 = *(long long *)(a1 + 48) == 0;
    *(long long *)(a1 + 56) = v9;
    if ( v10 || !v9 )
    {
      free(v9);
      free(*(void **)(a1 + 48));
    }
    else
    {
      v11 = *(int *)(a1 + 44);
      *(long long *)(a1 + 192) = 0;
      *(int *)(a1 + 40) = v11;
      *(long long *)(a1 + 200) = 0;
      *(long long *)(a1 + 208) = 0;
      *(int *)(a1 + 136) = 0;
      *(long long *)(a1 + 128) = 0;
      if ( !(unsigned int)sub_8B80(v1, 31, "1.2.13", 112) )
        goto LABEL_2;
      free(*(void **)(a1 + 56));
      free(*(void **)(a1 + 48));
      *(int *)(a1 + 40) = 0;
    }
    sub_2F50(a1, -4, "out of memory");
    return 0xFFFFFFFFLL;
  }
LABEL_2:
  v3 = *(unsigned int *)(a1 + 136);
  if ( (unsigned int)v3 > 1 )
    goto LABEL_3;
  result = sub_36C0(a1);
  if ( (int)result != -1 )
  {
    v3 = *(unsigned int *)(a1 + 136);
    result = 0;
    if ( (int)v3 )
    {
      if ( (int)v3 == 1 )
      {
        result = *(unsigned int *)(a1 + 64);
        if ( !(int)result )
        {
LABEL_5:
          *(int *)(a1 + 136) = 0;
          *(int *)(a1 + 80) = 1;
          *(int *)a1 = 0;
          return result;
        }
LABEL_7:
        v6 = *(void **)(a1 + 56);
        v7 = *(const void **)(a1 + 128);
        *(long long *)(a1 + 8) = v6;
        memcpy(v6, v7, v3);
        v8 = *(int *)(a1 + 136);
        *(int *)(a1 + 136) = 0;
        *(int *)a1 = v8;
        *(long long *)(a1 + 64) = 0x100000001LL;
        return 0;
      }
LABEL_3:
      v4 = *(char **)(a1 + 128);
      if ( *v4 == 31 && v4[1] == 0x8B )
      {
        sub_8AB0(v1);
        *(long long *)(a1 + 64) = 0x200000000LL;
        return 0;
      }
      result = *(unsigned int *)(a1 + 64);
      if ( !(int)result )
        goto LABEL_5;
      goto LABEL_7;
    }
  }
  return result;
}


// Function: gz_decomp @ 0x3990
long long gz_decomp(long long a1)
{
  long long v1; // r12
  int v2; // eax
  int v3; // edx
  unsigned int v4; // r8d
  long long v5; // rax
  long long v6; // r12
  const char *v8; // rdx
  long long v9; // rdx
  long long v10; // rax
  long long v11; // r12

  v1 = *(unsigned int *)(a1 + 160);
  do
  {
    if ( !*(int *)(a1 + 136) )
    {
      v4 = sub_36C0(a1);
      if ( v4 == -1 )
        return v4;
      if ( !*(int *)(a1 + 136) )
      {
        sub_2F50(a1, -5, "unexpected end of file");
        v5 = *(long long *)(a1 + 152);
        v6 = (unsigned int)(v1 - *(int *)(a1 + 160));
        v4 = 0;
        *(int *)a1 = v6;
        *(long long *)(a1 + 8) = v5 - v6;
        return v4;
      }
    }
    v2 = sub_8D00(a1 + 128, 0);
    if ( ((v2 + 2) & 0xFFFFFFFB) == 0 )
    {
      sub_2F50(a1, -2, "internal error: inflate stream corrupt");
      return 0xFFFFFFFFLL;
    }
    if ( v2 == -4 )
    {
      sub_2F50(a1, -4, "out of memory");
      return 0xFFFFFFFFLL;
    }
    if ( v2 == -3 )
    {
      v8 = *(const char **)(a1 + 176);
      if ( !v8 )
        v8 = "compressed data error";
      sub_2F50(a1, -3, v8);
      return 0xFFFFFFFFLL;
    }
    v3 = *(int *)(a1 + 160);
    if ( !v3 )
    {
      v9 = *(long long *)(a1 + 152);
      *(int *)a1 = v1;
      v4 = 0;
      *(long long *)(a1 + 8) = v9 - v1;
      if ( v2 == 1 )
      {
        *(int *)(a1 + 68) = 0;
        return 0;
      }
      return v4;
    }
  }
  while ( v2 != 1 );
  v10 = *(long long *)(a1 + 152);
  v11 = (unsigned int)(v1 - v3);
  *(int *)(a1 + 68) = 0;
  *(int *)a1 = v11;
  *(long long *)(a1 + 8) = v10 - v11;
  return 0;
}


// Function: gz_fetch @ 0x3b30
long long gz_fetch(long long a1)
{
  int v1; // eax

  while ( 1 )
  {
    v1 = *(int *)(a1 + 68);
    if ( v1 == 1 )
      break;
    if ( v1 == 2 )
    {
      *(int *)(a1 + 160) = 2 * *(int *)(a1 + 40);
      *(long long *)(a1 + 152) = *(long long *)(a1 + 56);
      if ( (unsigned int)sub_3990(a1) == -1 )
        return 0xFFFFFFFFLL;
    }
    else if ( !v1 )
    {
      if ( (unsigned int)sub_3790(a1) == -1 )
        return 0xFFFFFFFFLL;
      if ( !*(int *)(a1 + 68) )
        return 0;
    }
    if ( *(int *)a1 || *(int *)(a1 + 80) && !*(int *)(a1 + 136) )
      return 0;
  }
  if ( (unsigned int)sub_3610(a1, *(long long *)(a1 + 56), 2 * *(int *)(a1 + 40), (int *)a1) == -1 )
    return 0xFFFFFFFFLL;
  *(long long *)(a1 + 8) = *(long long *)(a1 + 56);
  return 0;
}


// Function: gz_read @ 0x3c60
long long gz_read(unsigned int *a1, char *a2, unsigned long long a3)
{
  unsigned long long v4; // r15
  long long v5; // r12
  unsigned int v6; // ebp
  unsigned int v7; // eax
  long long v8; // r14
  unsigned int v10; // edx
  unsigned int v11; // [rsp+4h] [rbp-44h] BYREF
  unsigned long long v12; // [rsp+8h] [rbp-40h]

  v12 = __readfsqword(0x28u);
  if ( a3 )
  {
    v4 = a3;
    if ( !a1[28] || (a1[28] = 0, (unsigned int)sub_3BE0(a1, *((long long *)a1 + 13)) != -1) )
    {
      v5 = 0;
      while ( 1 )
      {
        v6 = -1;
        v7 = *a1;
        if ( v4 <= 0xFFFFFFFE )
          v6 = v4;
        v11 = v6;
        if ( v7 )
          break;
        if ( a1[20] && !a1[34] )
        {
          a1[21] = 1;
          return v5;
        }
        v10 = a1[17];
        if ( v10 && 2 * a1[10] <= v11 )
        {
          if ( v10 == 1 )
          {
            if ( (unsigned int)sub_3610((long long)a1, (long long)a2, v11, &v11) == -1 )
              return 0;
            v8 = v11;
          }
          else
          {
            a1[40] = v11;
            *((long long *)a1 + 19) = a2;
            if ( (unsigned int)sub_3990((long long)a1) == -1 )
              return 0;
            v8 = *a1;
            *a1 = 0;
            v11 = v8;
          }
LABEL_10:
          *((long long *)a1 + 2) += v8;
          a2 += v8;
          v5 += v8;
          v4 -= v8;
          if ( !v4 )
            return v5;
        }
        else if ( (unsigned int)sub_3B30((long long)a1) == -1 )
        {
          return 0;
        }
      }
      if ( v7 < v6 )
      {
        v11 = v7;
        v6 = v7;
      }
      v8 = v6;
      memcpy(a2, *((const void **)a1 + 1), v6);
      *((long long *)a1 + 1) += v6;
      *a1 -= v6;
      goto LABEL_10;
    }
  }
  return 0;
}


// Function: gzread @ 0x3e00
long long gzread(unsigned int *a1, char *a2, int a3)
{
  unsigned int v3; // eax
  long long result; // rax
  unsigned int v5; // edx

  if ( !a1 )
    return 0xFFFFFFFFLL;
  if ( a1[6] != 7247 )
    return 0xFFFFFFFFLL;
  v3 = a1[29];
  if ( v3 )
  {
    if ( v3 != -5 )
      return 0xFFFFFFFFLL;
  }
  if ( a3 < 0 )
  {
    sub_2F50((long long)a1, -2, "request does not fit in an int");
    return 0xFFFFFFFFLL;
  }
  result = sub_3C60(a1, a2, (unsigned int)a3);
  if ( !(int)result )
  {
    v5 = a1[29];
    if ( v5 )
    {
      if ( v5 != -5 )
        return 0xFFFFFFFFLL;
    }
  }
  return result;
}


// Function: gzgetc @ 0x3f00
long long gzgetc(long long a1)
{
  int v1; // eax
  unsigned int v2; // eax
  unsigned char *v3; // rax
  unsigned char v5; // [rsp+7h] [rbp-11h] BYREF
  unsigned long long v6; // [rsp+8h] [rbp-10h]

  v6 = __readfsqword(0x28u);
  if ( !a1 )
    return 0xFFFFFFFFLL;
  if ( *(int *)(a1 + 24) != 7247 )
    return 0xFFFFFFFFLL;
  v1 = *(int *)(a1 + 116);
  if ( v1 )
  {
    if ( v1 != -5 )
      return 0xFFFFFFFFLL;
  }
  v2 = *(int *)a1;
  if ( *(int *)a1 )
  {
    ++*(long long *)(a1 + 16);
    *(int *)a1 = v2 - 1;
    v3 = *(unsigned char **)(a1 + 8);
    *(long long *)(a1 + 8) = v3 + 1;
    return *v3;
  }
  if ( sub_3C60((unsigned int *)a1, (char *)&v5, 1u) )
    return v5;
  else
    return 0xFFFFFFFFLL;
}


// Function: gzgets @ 0x40f0
char *gzgets(long long a1, char *a2, int a3)
{
  int v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // eax
  char *v8; // r12
  const void *v9; // r13
  size_t v10; // r15
  void *v11; // rax
  void *v12; // rdi
  size_t v13; // r14
  char *result; // rax
  void *v15; // rdi
  unsigned int v16; // eax

  if ( a3 <= 0 || a2 == 0 )
    return 0;
  if ( !a1 )
    return 0;
  if ( *(int *)(a1 + 24) != 7247 )
    return 0;
  v5 = *(int *)(a1 + 116);
  if ( v5 )
  {
    if ( v5 != -5 )
      return 0;
  }
  if ( *(int *)(a1 + 112) )
  {
    *(int *)(a1 + 112) = 0;
    if ( (unsigned int)sub_3BE0(a1, *(long long *)(a1 + 104)) == -1 )
      return 0;
  }
  v6 = a3 - 1;
  if ( !v6 )
    return 0;
  v7 = *(int *)a1;
  v8 = a2;
  if ( !*(int *)a1 )
    goto LABEL_19;
  do
  {
    do
    {
      v9 = *(const void **)(a1 + 8);
      if ( v6 <= v7 )
        v7 = v6;
      v10 = v7;
      v11 = memchr(*(const void **)(a1 + 8), 10, v7);
      if ( v11 )
      {
        v12 = v8;
        v13 = (unsigned int)((int)v11 - (int)v9 + 1);
        v8 += v13;
        memcpy(v12, v9, v13);
        *(int *)a1 -= v13;
        *(long long *)(a1 + 8) += v13;
        *(long long *)(a1 + 16) += v13;
        goto LABEL_13;
      }
      v15 = v8;
      v8 += v10;
      memcpy(v15, v9, v10);
      v16 = *(int *)a1;
      *(long long *)(a1 + 8) += v10;
      *(long long *)(a1 + 16) += v10;
      v7 = v16 - v10;
      *(int *)a1 = v7;
      v6 -= v10;
      if ( !v6 )
        goto LABEL_13;
    }
    while ( v7 );
LABEL_19:
    if ( (unsigned int)sub_3B30(a1) == -1 )
      return 0;
    v7 = *(int *)a1;
  }
  while ( *(int *)a1 );
  *(int *)(a1 + 84) = 1;
LABEL_13:
  result = a2;
  if ( v8 == a2 )
    return 0;
  *v8 = 0;
  return result;
}


// Function: gzclose_r @ 0x42c0
long long gzclose_r(char *ptr)
{
  unsigned int v1; // r12d
  int v2; // ebx

  if ( ptr && *((int *)ptr + 6) == 7247 )
  {
    if ( *((int *)ptr + 10) )
    {
      sub_AA00(ptr + 128);
      free(*((void **)ptr + 7));
      free(*((void **)ptr + 6));
    }
    v1 = *((int *)ptr + 29);
    if ( v1 != -5 )
      v1 = 0;
    sub_2F50((long long)ptr, 0, 0);
    free(*((void **)ptr + 4));
    v2 = close(*((int *)ptr + 7));
    free(ptr);
    if ( v2 )
      return (unsigned int)-1;
  }
  else
  {
    return (unsigned int)-2;
  }
  return v1;
}


// Function: gz_init @ 0x4360
long long gz_init(long long a1)
{
  void *v2; // rax
  size_t v3; // rdi
  long long result; // rax
  void *v5; // rax
  int v6; // esi
  int v7; // r9d
  int v8; // edx
  long long v9; // rdx

  v2 = malloc((unsigned int)(2 * *(int *)(a1 + 44)));
  *(long long *)(a1 + 48) = v2;
  if ( !v2 )
    goto LABEL_11;
  v3 = *(unsigned int *)(a1 + 44);
  if ( *(int *)(a1 + 64) )
  {
    *(int *)(a1 + 40) = v3;
    return 0;
  }
  v5 = malloc(v3);
  *(long long *)(a1 + 56) = v5;
  if ( !v5 )
  {
LABEL_10:
    free(*(void **)(a1 + 48));
LABEL_11:
    sub_2F50(a1, -4, "out of memory");
    return 0xFFFFFFFFLL;
  }
  v6 = *(int *)(a1 + 88);
  v7 = *(int *)(a1 + 92);
  *(long long *)(a1 + 192) = 0;
  *(long long *)(a1 + 200) = 0;
  *(long long *)(a1 + 208) = 0;
  if ( (unsigned int)sub_82B0((int)a1 + 128, v6, 8, 31, 8, v7, (long long)"1.2.13", 112) )
  {
    free(*(void **)(a1 + 56));
    goto LABEL_10;
  }
  v8 = *(int *)(a1 + 44);
  result = *(unsigned int *)(a1 + 64);
  *(long long *)(a1 + 128) = 0;
  *(int *)(a1 + 40) = v8;
  if ( (int)result )
    return 0;
  *(int *)(a1 + 160) = v8;
  v9 = *(long long *)(a1 + 56);
  *(long long *)(a1 + 152) = v9;
  *(long long *)(a1 + 8) = v9;
  return result;
}


// Function: gz_comp @ 0x4460
long long gz_comp(long long a1, unsigned int a2)
{
  unsigned int v3; // r12d
  size_t v4; // rdx
  const void *v5; // rsi
  int v6; // edx
  int v7; // eax
  int *v8; // rax
  char *v9; // rax
  int v11; // ecx
  int v12; // eax
  int v13; // r14d
  unsigned long long v14; // rdx
  const void *v15; // rsi
  long long v16; // rdx
  int v17; // eax
  long long v18; // rax

  if ( !*(int *)(a1 + 40) )
  {
    v3 = sub_4360(a1);
    if ( v3 == -1 )
      return v3;
  }
  v3 = *(int *)(a1 + 64);
  if ( !v3 )
  {
    if ( *(int *)(a1 + 96) )
    {
      if ( !*(int *)(a1 + 136) )
        return 0;
      sub_7150(a1 + 128);
      *(int *)(a1 + 96) = 0;
    }
    v11 = *(int *)(a1 + 160);
    v12 = 0;
    do
    {
      if ( v11 )
      {
        if ( a2 && (a2 != 4 || v12 == 1) )
        {
          v14 = *(long long *)(a1 + 152);
          v15 = *(const void **)(a1 + 8);
          if ( v14 > (unsigned long long)v15 )
          {
            while ( 1 )
            {
LABEL_28:
              v16 = v14 - (long long)v15;
              if ( v16 > 0x40000000 )
                LODWORD(v16) = 0x40000000;
              v17 = write(*(int *)(a1 + 28), v15, (unsigned int)v16);
              if ( v17 < 0 )
                goto LABEL_9;
              v14 = *(long long *)(a1 + 152);
              v15 = (const void *)(*(long long *)(a1 + 8) + v17);
              *(long long *)(a1 + 8) = v15;
              if ( (unsigned long long)v15 >= v14 )
              {
                v13 = *(int *)(a1 + 160);
                if ( v13 )
                  goto LABEL_21;
                goto LABEL_35;
              }
            }
          }
        }
        v13 = v11;
      }
      else
      {
        v14 = *(long long *)(a1 + 152);
        v15 = *(const void **)(a1 + 8);
        if ( v14 > (unsigned long long)v15 )
          goto LABEL_28;
LABEL_35:
        v18 = *(long long *)(a1 + 56);
        v13 = *(int *)(a1 + 40);
        *(long long *)(a1 + 152) = v18;
        *(int *)(a1 + 160) = v13;
        *(long long *)(a1 + 8) = v18;
      }
LABEL_21:
      v12 = sub_7460(a1 + 128, a2);
      if ( v12 == -2 )
      {
        v3 = -1;
        sub_2F50(a1, -2, "internal error: deflate stream corrupt");
        return v3;
      }
      v11 = *(int *)(a1 + 160);
    }
    while ( v11 != v13 );
    if ( a2 != 4 )
      return 0;
    *(int *)(a1 + 96) = 1;
    return v3;
  }
  v4 = *(unsigned int *)(a1 + 136);
  if ( (int)v4 )
  {
    v5 = *(const void **)(a1 + 128);
    while ( 1 )
    {
      if ( (unsigned int)v4 > 0x40000000 )
        v4 = 0x40000000;
      v7 = write(*(int *)(a1 + 28), v5, v4);
      if ( v7 < 0 )
        break;
      v6 = *(int *)(a1 + 136);
      v5 = (const void *)(*(long long *)(a1 + 128) + v7);
      *(long long *)(a1 + 128) = v5;
      v4 = (unsigned int)(v6 - v7);
      *(int *)(a1 + 136) = v4;
      if ( !(int)v4 )
        return 0;
    }
LABEL_9:
    v8 = __errno_location();
    v3 = -1;
    v9 = strerror(*v8);
    sub_2F50(a1, -1, v9);
    return v3;
  }
  return 0;
}


// Function: gz_write @ 0x4750
unsigned long long gz_write(long long a1, char *a2, unsigned long long a3)
{
  char *v4; // rbx
  int v5; // edx
  unsigned long long v6; // r13
  unsigned long long v7; // r14
  long long v8; // rdi
  long long i; // rax
  unsigned int v10; // eax
  unsigned int v11; // r13d
  long long v12; // r12
  size_t v13; // r15
  unsigned long long v14; // rbx
  unsigned long long v16; // [rsp+8h] [rbp-40h]

  v16 = a3;
  if ( !a3 )
    return 0;
  v4 = a2;
  if ( *(int *)(a1 + 40) )
  {
    if ( !*(int *)(a1 + 112) )
      goto LABEL_4;
  }
  else
  {
    if ( (unsigned int)sub_4360(a1) == -1 )
      return 0;
    if ( !*(int *)(a1 + 112) )
      goto LABEL_4;
  }
  *(int *)(a1 + 112) = 0;
  if ( (unsigned int)sub_4690(a1, *(long long *)(a1 + 104)) == -1 )
    return 0;
LABEL_4:
  v5 = *(int *)(a1 + 136);
  v6 = *(unsigned int *)(a1 + 40);
  if ( v6 > v16 )
  {
    v7 = v16;
    v8 = *(long long *)(a1 + 48);
    if ( !v5 )
      goto LABEL_12;
LABEL_6:
    for ( i = *(long long *)(a1 + 128); ; LODWORD(i) = v8 )
    {
      v10 = v5 + i - v8;
      v11 = v6 - v10;
      v12 = v11;
      v13 = v11;
      if ( v11 > v7 )
      {
        v12 = (unsigned int)v7;
        v13 = v7;
        v11 = v7;
      }
      memcpy((void *)(v10 + v8), v4, v13);
      *(int *)(a1 + 136) += v11;
      *(long long *)(a1 + 16) += v12;
      v7 -= v13;
      if ( !v7 )
        break;
      if ( (unsigned int)sub_4460(a1, 0) == -1 )
        return 0;
      v5 = *(int *)(a1 + 136);
      LODWORD(v6) = *(int *)(a1 + 40);
      v4 += v13;
      v8 = *(long long *)(a1 + 48);
      if ( v5 )
        goto LABEL_6;
LABEL_12:
      *(long long *)(a1 + 128) = v8;
    }
    return v16;
  }
  if ( v5 && (unsigned int)sub_4460(a1, 0) == -1 )
    return 0;
  *(long long *)(a1 + 128) = a2;
  v14 = v16;
  while ( v14 > 0xFFFFFFFE )
  {
    *(long long *)(a1 + 16) += 0xFFFFFFFFLL;
    *(int *)(a1 + 136) = -1;
    if ( (unsigned int)sub_4460(a1, 0) == -1 )
      return 0;
    v14 -= 0xFFFFFFFFLL;
    if ( !v14 )
      return v16;
  }
  *(long long *)(a1 + 16) += v14;
  *(int *)(a1 + 136) = v14;
  if ( (unsigned int)sub_4460(a1, 0) == -1 )
    return 0;
  return v16;
}


// Function: gzwrite @ 0x4910
unsigned long long gzwrite(long long a1, char *a2, int a3)
{
  unsigned long long result; // rax
  unsigned int v4; // [rsp+0h] [rbp-Ch]

  result = 0;
  if ( a1 && *(int *)(a1 + 24) == 31153 )
  {
    if ( *(int *)(a1 + 116) )
    {
      return 0;
    }
    else if ( a3 < 0 )
    {
      v4 = *(int *)(a1 + 116);
      sub_2F50(a1, -3, "requested length does not fit in int");
      return v4;
    }
    else
    {
      return sub_4750(a1, a2, (unsigned int)a3);
    }
  }
  return result;
}


// Function: gzputc @ 0x4a00
long long gzputc(long long a1, unsigned char a2)
{
  unsigned int v3; // ecx
  long long v4; // rdx
  long long v5; // rsi
  long long v6; // rdx
  unsigned char v8; // [rsp+17h] [rbp-11h] BYREF
  unsigned long long v9; // [rsp+18h] [rbp-10h]

  v9 = __readfsqword(0x28u);
  if ( !a1 )
    return 0xFFFFFFFFLL;
  if ( *(int *)(a1 + 24) != 31153 )
    return 0xFFFFFFFFLL;
  if ( *(int *)(a1 + 116) )
    return 0xFFFFFFFFLL;
  if ( *(int *)(a1 + 112) )
  {
    *(int *)(a1 + 112) = 0;
    if ( (unsigned int)sub_4690(a1, *(long long *)(a1 + 104)) == -1 )
      return 0xFFFFFFFFLL;
  }
  v3 = *(int *)(a1 + 40);
  if ( v3 )
  {
    v4 = *(unsigned int *)(a1 + 136);
    v5 = *(long long *)(a1 + 48);
    if ( !(int)v4 )
    {
      *(long long *)(a1 + 128) = v5;
      LODWORD(v6) = 0;
LABEL_8:
      *(char *)(v5 + (unsigned int)v6) = a2;
      ++*(int *)(a1 + 136);
      ++*(long long *)(a1 + 16);
      return a2;
    }
    v6 = *(long long *)(a1 + 128) + v4 - v5;
    if ( v3 > (unsigned int)v6 )
      goto LABEL_8;
  }
  v8 = a2;
  if ( sub_4750(a1, (char *)&v8, 1u) == 1 )
    return a2;
  return 0xFFFFFFFFLL;
}


// Function: gzputs @ 0x4b00
long long gzputs(long long a1, char *a2)
{
  size_t v2; // rax
  unsigned int v3; // r13d

  if ( !a1 || *(int *)(a1 + 24) != 31153 || *(int *)(a1 + 116) )
    return (unsigned int)-1;
  v2 = strlen(a2);
  v3 = v2;
  if ( (v2 & 0x80000000) != 0LL || (unsigned int)v2 != v2 )
  {
    sub_2F50(a1, -2, "string length does not fit in int");
    return (unsigned int)-1;
  }
  if ( (unsigned int)v2 > sub_4750(a1, a2, (unsigned int)v2) )
    return (unsigned int)-1;
  return v3;
}


// Function: gzvprintf @ 0x4b80
long long gzvprintf(long long a1, long long a2, long long a3)
{
  long long v4; // rax
  long long v5; // rdx
  long long v6; // r13
  unsigned int v7; // eax
  unsigned int v8; // r12d
  unsigned int v9; // ebp
  int v10; // r13d
  unsigned int v11; // r13d
  unsigned int v13; // r13d
  long long v14; // rax

  if ( !a1 || *(int *)(a1 + 24) != 31153 || *(int *)(a1 + 116) )
    return (unsigned int)-2;
  if ( !*(int *)(a1 + 40) && (unsigned int)sub_4360(a1) == -1 )
    return *(unsigned int *)(a1 + 116);
  if ( *(int *)(a1 + 112) )
  {
    *(int *)(a1 + 112) = 0;
    if ( (unsigned int)sub_4690(a1, *(long long *)(a1 + 104)) == -1 )
      return *(unsigned int *)(a1 + 116);
  }
  v4 = *(unsigned int *)(a1 + 136);
  if ( (int)v4 )
  {
    v5 = *(long long *)(a1 + 128);
  }
  else
  {
    v5 = *(long long *)(a1 + 48);
    *(long long *)(a1 + 128) = v5;
  }
  v6 = v5 + v4;
  *(char *)(v5 + v4 + (unsigned int)(*(int *)(a1 + 40) - 1)) = 0;
  v7 = __vsnprintf_chk(v5 + v4, *(unsigned int *)(a1 + 40), 1, -1, a2, a3);
  v8 = v7;
  if ( !v7 )
    return v8;
  v9 = *(int *)(a1 + 40);
  if ( v9 > v7 && !*(char *)(v6 + v9 - 1) )
  {
    v10 = *(int *)(a1 + 136);
    *(long long *)(a1 + 16) += (int)v7;
    v11 = v7 + v10;
    *(int *)(a1 + 136) = v11;
    if ( v9 <= v11 )
    {
      *(int *)(a1 + 136) = v9;
      if ( (unsigned int)sub_4460(a1, 0) == -1 )
        return *(unsigned int *)(a1 + 116);
      v13 = v11 - v9;
      memmove(*(void **)(a1 + 48), (const void *)(*(long long *)(a1 + 48) + *(unsigned int *)(a1 + 40)), v13);
      v14 = *(long long *)(a1 + 48);
      *(int *)(a1 + 136) = v13;
      *(long long *)(a1 + 128) = v14;
    }
    return v8;
  }
  return 0;
}


// Function: gzprintf @ 0x4d20
long long gzprintf(long long a1, long long a2, ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-D8h] BYREF
  unsigned long long v4; // [rsp+18h] [rbp-C0h]

  va_start(va, a2);
  v4 = __readfsqword(0x28u);
  return sub_4B80(a1, a2, (long long)va);
}


// Function: gzsetparams @ 0x4e50
long long gzsetparams(long long a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r13d

  if ( !a1 )
    return (unsigned int)-2;
  if ( *(int *)(a1 + 24) != 31153 )
    return (unsigned int)-2;
  v3 = *(int *)(a1 + 116);
  if ( v3 )
    return (unsigned int)-2;
  if ( *(int *)(a1 + 88) == a2 )
  {
    if ( *(int *)(a1 + 92) == a3 )
      return v3;
    if ( !*(int *)(a1 + 112) )
      goto LABEL_6;
LABEL_14:
    *(int *)(a1 + 112) = 0;
    if ( (unsigned int)sub_4690(a1, *(long long *)(a1 + 104)) == -1 )
      return *(unsigned int *)(a1 + 116);
    goto LABEL_6;
  }
  if ( *(int *)(a1 + 112) )
    goto LABEL_14;
LABEL_6:
  if ( !*(int *)(a1 + 40) )
  {
LABEL_10:
    *(int *)(a1 + 88) = a2;
    *(int *)(a1 + 92) = a3;
    return v3;
  }
  if ( !*(int *)(a1 + 136) || (unsigned int)sub_4460(a1, 5u) != -1 )
  {
    sub_8030(a1 + 128, a2, a3);
    goto LABEL_10;
  }
  return *(unsigned int *)(a1 + 116);
}


// Function: gzclose_w @ 0x4f30
long long gzclose_w(char *ptr)
{
  unsigned int v1; // r12d

  if ( ptr && *((int *)ptr + 6) == 31153 )
  {
    if ( *((int *)ptr + 28) && (*((int *)ptr + 28) = 0, (unsigned int)sub_4690(ptr, *((long long *)ptr + 13)) == -1) )
      v1 = *((int *)ptr + 29);
    else
      v1 = 0;
    if ( (unsigned int)sub_4460((long long)ptr, 4u) == -1 )
      v1 = *((int *)ptr + 29);
    if ( *((int *)ptr + 10) )
    {
      if ( !*((int *)ptr + 16) )
      {
        sub_8200(ptr + 128);
        free(*((void **)ptr + 7));
      }
      free(*((void **)ptr + 6));
    }
    sub_2F50((long long)ptr, 0, 0);
    free(*((void **)ptr + 4));
    if ( close(*((int *)ptr + 7)) == -1 )
      v1 = -1;
    free(ptr);
  }
  else
  {
    return (unsigned int)-2;
  }
  return v1;
}


// Function: slide_hash @ 0x5020
short *slide_hash(long long a1)
{
  unsigned int v1; // edx
  short *v2; // rax
  short *v3; // r9
  unsigned int v4; // esi
  short v5; // cx
  short *result; // rax
  short *v7; // r8
  unsigned int v8; // esi
  short v9; // cx

  v1 = *(int *)(a1 + 80);
  v2 = (short *)(*(long long *)(a1 + 120) + 2LL * *(unsigned int *)(a1 + 132));
  v3 = &v2[~(unsigned long long)(unsigned int)(*(int *)(a1 + 132) - 1)];
  do
  {
    v4 = (unsigned short)*--v2;
    v5 = v4 - v1;
    if ( v1 > v4 )
      v5 = 0;
    *v2 = v5;
  }
  while ( v2 != v3 );
  result = (short *)(*(long long *)(a1 + 112) + 2LL * v1);
  v7 = &result[~(unsigned long long)(v1 - 1)];
  do
  {
    v8 = (unsigned short)*--result;
    v9 = v8 - v1;
    if ( v1 > v8 )
      v9 = 0;
    *result = v9;
  }
  while ( result != v7 );
  return result;
}


// Function: deflateStateCheck @ 0x50a0
long long deflateStateCheck(long long *a1)
{
  long long v1; // rdx
  long long result; // rax
  int v3; // ecx

  if ( !a1 || !a1[8] || !a1[9] )
    return 1;
  v1 = a1[7];
  result = 1;
  if ( v1 && *(long long **)v1 == a1 )
  {
    v3 = *(int *)(v1 + 8);
    if ( v3 == 42 || v3 == 57 )
    {
      return 0;
    }
    else if ( v3 > 113 )
    {
      return v3 != 666;
    }
    else if ( v3 > 68 )
    {
      return !((0x100400400011uLL >> ((unsigned char)v3 - 69)) & 1);
    }
  }
  return result;
}


// Function: putShortMSB @ 0x5130
long long putShortMSB(long long a1, unsigned int a2)
{
  long long v2; // rdx
  long long v3; // rcx
  long long v5; // rdx
  long long v6; // rcx

  v2 = *(long long *)(a1 + 40);
  v3 = *(long long *)(a1 + 16);
  *(long long *)(a1 + 40) = v2 + 1;
  *(char *)(v3 + v2) = BYTE1(a2);
  v5 = *(long long *)(a1 + 40);
  v6 = *(long long *)(a1 + 16);
  *(long long *)(a1 + 40) = v5 + 1;
  *(char *)(v6 + v5) = a2;
  return a2;
}


// Function: longest_match @ 0x5160
long long longest_match(long long a1, unsigned int a2)
{
  int v4; // r10d
  long long result; // rax
  long long v6; // r9
  unsigned int v7; // esi
  long long v8; // rdi
  unsigned int v9; // r15d
  int v10; // ebx
  char *v11; // r12
  unsigned int v12; // r8d
  bool v13; // cc
  long long v14; // r11
  long long v15; // rdi
  char v16; // r13
  char v17; // r10
  unsigned int v18; // r14d
  unsigned long long v19; // r15
  char *v20; // rdx
  char *v21; // rdi
  char *v22; // rdx
  int v23; // edi
  int v24; // [rsp+0h] [rbp-38h]

  v4 = *(int *)(a1 + 80);
  result = *(unsigned int *)(a1 + 184);
  v6 = *(long long *)(a1 + 96);
  v7 = *(int *)(a1 + 188);
  v8 = *(unsigned int *)(a1 + 172);
  v9 = *(int *)(a1 + 208);
  v10 = *(int *)(a1 + 88);
  v11 = (char *)(v6 + v8);
  v12 = v8 + 262 - v4;
  v13 = (unsigned int)v8 <= v4 - 262;
  v14 = *(long long *)(a1 + 112);
  v15 = v6 + v8 + 258;
  if ( v13 )
    v12 = 0;
  v16 = v11[(int)result - 1];
  v17 = v11[(int)result];
  if ( (unsigned int)result >= *(int *)(a1 + 204) )
    v7 >>= 2;
  v18 = *(int *)(a1 + 180);
  if ( v9 > v18 )
    v9 = *(int *)(a1 + 180);
  v24 = v9;
  v19 = v15;
  while ( 1 )
  {
    v20 = (char *)(v6 + a2);
    if ( v20[(int)result] != v17 || v20[(int)result - 1] != v16 || *v20 != *v11 || v20[1] != v11[1] )
      goto LABEL_8;
    v21 = v11 + 2;
    v22 = v20 + 2;
    while ( 1 )
    {
      if ( v21[1] != v22[1] )
      {
        result = (unsigned int)result;
        LODWORD(v21) = (int)v21 + 1;
        goto LABEL_25;
      }
      if ( v21[2] != v22[2] )
      {
        result = (unsigned int)result;
        LODWORD(v21) = (int)v21 + 2;
        goto LABEL_25;
      }
      if ( v21[3] != v22[3] )
      {
        result = (unsigned int)result;
        LODWORD(v21) = (int)v21 + 3;
        goto LABEL_25;
      }
      if ( v21[4] != v22[4] )
      {
        result = (unsigned int)result;
        LODWORD(v21) = (int)v21 + 4;
        goto LABEL_25;
      }
      if ( v21[5] != v22[5] )
      {
        result = (unsigned int)result;
        LODWORD(v21) = (int)v21 + 5;
        goto LABEL_25;
      }
      if ( v21[6] != v22[6] )
      {
        result = (unsigned int)result;
        LODWORD(v21) = (int)v21 + 6;
        goto LABEL_25;
      }
      if ( v21[7] != v22[7] )
        break;
      v21 += 8;
      v22 += 8;
      if ( *v21 != *v22 || v19 <= (unsigned long long)v21 )
      {
        result = (unsigned int)result;
        goto LABEL_25;
      }
    }
    result = (unsigned int)result;
    LODWORD(v21) = (int)v21 + 7;
LABEL_25:
    v23 = 258 - (v19 - (int)v21);
    if ( (int)result >= v23 )
    {
LABEL_8:
      a2 = *(unsigned short *)(v14 + 2LL * (v10 & a2));
      if ( v12 >= a2 )
        goto LABEL_28;
      goto LABEL_9;
    }
    *(int *)(a1 + 176) = a2;
    if ( v23 >= v24 )
      break;
    a2 = *(unsigned short *)(v14 + 2LL * (v10 & a2));
    v16 = v11[v23 - 1];
    v17 = v11[v23];
    result = (unsigned int)v23;
    if ( v12 >= a2 )
      goto LABEL_28;
LABEL_9:
    if ( !--v7 )
      goto LABEL_28;
  }
  result = (unsigned int)v23;
LABEL_28:
  if ( (unsigned int)result > v18 )
    return v18;
  return result;
}


// Function: lm_init @ 0x5370
long long lm_init(long long a1)
{
  unsigned int v2; // eax
  short *v3; // rdi
  long long v4; // rdx
  int v5; // eax

  *(long long *)(a1 + 104) = 2LL * *(unsigned int *)(a1 + 80);
  v2 = *(int *)(a1 + 132);
  v3 = *(short **)(a1 + 120);
  v3[--v2] = 0;
  memset(v3, 0, 2LL * v2);
  v4 = *(int *)(a1 + 196);
  *(long long *)(a1 + 152) = 0;
  *(int *)(a1 + 5932) = 0;
  *(int *)(a1 + 160) = 2;
  v4 *= 16;
  *(long long *)(a1 + 168) = 0;
  *(int *)(a1 + 128) = 0;
  *(int *)(a1 + 192) = *(unsigned short *)((char *)&unk_16B80 + v4 + 2);
  *(int *)(a1 + 204) = *(unsigned short *)((char *)&unk_16B80 + v4);
  v5 = *(unsigned short *)((char *)&unk_16B80 + v4 + 6);
  *(int *)(a1 + 208) = *(unsigned short *)((char *)&unk_16B80 + v4 + 4);
  *(int *)(a1 + 188) = v5;
  *(long long *)(a1 + 180) = 0x200000000LL;
  return 0x200000000LL;
}


// Function: read_buf @ 0x5420
long long read_buf(long long a1, void *a2, unsigned int a3)
{
  unsigned int v3; // eax
  unsigned int v4; // r12d
  long long v7; // rbp
  const void *v8; // rsi
  void *v9; // r8
  int v10; // eax

  v3 = *(int *)(a1 + 8);
  if ( v3 <= a3 )
    a3 = *(int *)(a1 + 8);
  v4 = a3;
  if ( !a3 )
    return 0;
  v7 = a3;
  v8 = *(const void **)a1;
  *(int *)(a1 + 8) = v3 - a3;
  v9 = memcpy(a2, v8, a3);
  v10 = *(int *)(*(long long *)(a1 + 56) + 48LL);
  if ( v10 == 1 )
  {
    *(long long *)(a1 + 96) = sub_D8E0(*(long long *)(a1 + 96), v9, v4);
  }
  else if ( v10 == 2 )
  {
    *(long long *)(a1 + 96) = sub_DD50(*(long long *)(a1 + 96), v9, v4);
  }
  *(long long *)a1 += v7;
  *(long long *)(a1 + 16) += v7;
  return v4;
}


// Function: fill_window @ 0x54b0
char *fill_window(long long a1)
{
  long long v2; // r13
  unsigned int v3; // esi
  int i; // edx
  long long v5; // rdi
  int v6; // eax
  long long v7; // rcx
  unsigned int v8; // eax
  unsigned int v9; // r14d
  int v10; // eax
  unsigned int v11; // eax
  unsigned long long v12; // rdi
  char *result; // rax
  unsigned long long v14; // rsi
  int v15; // edi
  long long v16; // r8
  int v17; // ecx
  int v18; // r9d
  unsigned int v19; // edx
  int v20; // r10d
  long long v21; // r14
  long long v22; // r11
  long long v23; // rax
  short *v24; // rax
  long long v25; // rdx
  long long *v26; // rcx
  char *v27; // rax
  unsigned long long v28; // rbp

  v2 = *(unsigned int *)(a1 + 80);
  v3 = *(int *)(a1 + 180);
  for ( i = *(int *)(a1 + 80); ; i = *(int *)(a1 + 80) )
  {
    v7 = *(long long *)(a1 + 104);
    v8 = *(int *)(a1 + 172);
    v9 = v7 - v8 - v3;
    if ( v8 >= (int)v2 - 262 + i )
      break;
    v5 = *(long long *)a1;
    if ( !*(int *)(*(long long *)a1 + 8LL) )
      goto LABEL_11;
LABEL_3:
    v3 = *(int *)(a1 + 180)
       + sub_5420(
           v5,
           (void *)(*(long long *)(a1 + 96) + *(unsigned int *)(a1 + 180) + (unsigned long long)*(unsigned int *)(a1 + 172)),
           v9);
    *(int *)(a1 + 180) = v3;
    v6 = *(int *)(a1 + 5932);
    if ( v3 + v6 > 2 )
    {
      v15 = *(int *)(a1 + 172);
      v16 = *(long long *)(a1 + 96);
      v17 = *(int *)(a1 + 144);
      v18 = *(int *)(a1 + 140);
      v19 = v15 - v6;
      v20 = *(unsigned char *)(v16 + (unsigned int)(v15 - v6));
      *(int *)(a1 + 128) = v20;
      *(int *)(a1 + 128) = v18 & ((v20 << v17) ^ *(unsigned char *)(v16 + (unsigned int)(v15 - v6 + 1)));
      do
      {
        if ( v19 == v15 )
          break;
        v21 = *(int *)(a1 + 88) & v19;
        v22 = *(long long *)(a1 + 120);
        v23 = v18 & ((*(int *)(a1 + 128) << v17) ^ (unsigned int)*(unsigned char *)(v16 + v19 + 2));
        *(int *)(a1 + 128) = v23;
        v24 = (short *)(v22 + 2 * v23);
        *(short *)(*(long long *)(a1 + 112) + 2 * v21) = *v24;
        *v24 = v19++;
        *(int *)(a1 + 5932) = v15 - v19;
      }
      while ( v3 + v15 - v19 > 2 );
    }
    if ( v3 > 0x105 || !*(int *)(*(long long *)a1 + 8LL) )
      goto LABEL_11;
  }
  memcpy(*(void **)(a1 + 96), (const void *)(*(long long *)(a1 + 96) + v2), (int)v2 + v8 - (int)v7 + v3);
  v10 = *(int *)(a1 + 172);
  *(int *)(a1 + 176) -= v2;
  *(long long *)(a1 + 152) -= v2;
  v11 = v10 - v2;
  *(int *)(a1 + 172) = v11;
  if ( v11 < *(int *)(a1 + 5932) )
    *(int *)(a1 + 5932) = v11;
  v9 += v2;
  sub_5020(a1);
  v5 = *(long long *)a1;
  if ( *(int *)(*(long long *)a1 + 8LL) )
    goto LABEL_3;
LABEL_11:
  v12 = *(long long *)(a1 + 5944);
  result = *(char **)(a1 + 104);
  if ( v12 < (unsigned long long)result )
  {
    v14 = *(unsigned int *)(a1 + 180) + (unsigned long long)*(unsigned int *)(a1 + 172);
    if ( v12 < v14 )
    {
      v25 = (long long)&result[-v14];
      if ( (unsigned long long)&result[-v14] > 0x102 )
        v25 = 258;
      v26 = (long long *)(v14 + *(long long *)(a1 + 96));
      if ( (unsigned int)v25 >= 8 )
      {
        *v26 = 0;
        *(long long *)((char *)v26 + (unsigned int)v25 - 8) = 0;
        memset(
          (void *)((unsigned long long)(v26 + 1) & 0xFFFFFFFFFFFFFFF8LL),
          0,
          8LL * (((unsigned int)v25 + (int)v26 - (((int)v26 + 8) & 0xFFFFFFF8)) >> 3));
      }
      else if ( (v25 & 4) != 0 )
      {
        *(int *)v26 = 0;
        *(int *)((char *)v26 + (unsigned int)v25 - 4) = 0;
      }
      else if ( (int)v25 )
      {
        *(char *)v26 = 0;
        if ( (v25 & 2) != 0 )
          *(short *)((char *)v26 + (unsigned int)v25 - 2) = 0;
      }
      *(long long *)(a1 + 5944) = v25 + v14;
      return (char *)(v25 + v14);
    }
    else if ( v12 < v14 + 258 )
    {
      v27 = &result[-v12];
      v28 = v14 - v12 + 258;
      if ( v28 > (unsigned long long)v27 )
        v28 = (unsigned long long)v27;
      result = (char *)memset((void *)(*(long long *)(a1 + 96) + v12), 0, (unsigned int)v28);
      *(long long *)(a1 + 5944) += v28;
    }
  }
  return result;
}


// Function: flush_pending @ 0x5790
void *flush_pending(long long a1)
{
  long long v1; // r12
  void *result; // rax
  unsigned int v3; // edx
  long long v4; // r13
  unsigned int v5; // ebp
  bool v6; // zf

  v1 = *(long long *)(a1 + 56);
  sub_CEF0(v1);
  result = (void *)*(unsigned int *)(a1 + 32);
  v3 = *(int *)(v1 + 40);
  if ( (unsigned int)result <= v3 )
    v3 = *(int *)(a1 + 32);
  if ( v3 )
  {
    v4 = v3;
    v5 = v3;
    result = memcpy(*(void **)(a1 + 24), *(const void **)(v1 + 32), v3);
    *(long long *)(a1 + 24) += v4;
    *(long long *)(v1 + 32) += v4;
    *(long long *)(a1 + 40) += v4;
    *(int *)(a1 + 32) -= v5;
    v6 = *(long long *)(v1 + 40) == v4;
    *(long long *)(v1 + 40) -= v4;
    if ( v6 )
    {
      result = *(void **)(v1 + 16);
      *(long long *)(v1 + 32) = result;
    }
  }
  return result;
}


// Function: deflate_slow @ 0x5810
long long deflate_slow(long long a1, int a2)
{
  unsigned int v4; // ebp
  unsigned int v5; // r15d
  unsigned int v6; // edx
  int v7; // r13d
  long long v8; // rcx
  long long v9; // rax
  long long v10; // rdi
  short *v11; // rax
  unsigned int v12; // esi
  long long v13; // rcx
  long long v14; // rax
  long long v15; // rdx
  long long v16; // rdx
  long long v17; // rcx
  long long v18; // rdx
  long long v19; // rcx
  int v20; // eax
  long long v21; // rax
  long long result; // rax
  long long v23; // rax
  long long v24; // rsi
  unsigned int v25; // r8d
  short v26; // r15
  short v27; // cx
  unsigned char v28; // dl
  unsigned short v29; // r15
  long long v30; // rax
  long long v31; // rsi
  long long v32; // rax
  long long v33; // rcx
  long long v34; // rax
  int v35; // edx
  int v36; // ecx
  int v37; // r10d
  int v38; // r9d
  int v39; // eax
  int v40; // edx
  unsigned int v41; // esi
  int v42; // edi
  unsigned int v43; // eax
  long long v44; // rcx
  long long v45; // rdx
  long long v46; // r11
  short *v47; // rdx
  int v48; // edx
  long long v49; // rax
  long long v50; // rdx
  long long v51; // rsi
  long long v52; // rdx
  long long v53; // rdi
  long long v54; // rax
  long long v55; // rsi
  long long v56; // rdi
  unsigned int v57; // eax
  long long v58; // rdx
  int v59; // eax
  long long v60; // rax
  long long v61; // rsi
  long long v62; // rdx
  long long v63; // rdi
  long long v64; // rcx
  long long v65; // rax
  long long v66; // rdx
  long long v67; // rdx
  long long v68; // rcx
  long long v69; // rdx
  long long v70; // rcx
  long long v71; // rax
  long long v72; // rsi
  long long v73; // rdx
  long long v74; // rdi
  unsigned int v75; // [rsp+Ch] [rbp-3Ch]

  v4 = *(int *)(a1 + 180);
LABEL_2:
  if ( v4 > 0x105 )
  {
LABEL_3:
    v5 = *(int *)(a1 + 172);
    v6 = *(int *)(a1 + 160);
    v7 = *(int *)(a1 + 176);
    goto LABEL_4;
  }
  while ( 1 )
  {
    sub_54B0(a1);
    v4 = *(int *)(a1 + 180);
    if ( v4 > 0x105 )
      goto LABEL_3;
    if ( !a2 )
      return 0;
    if ( !v4 )
      break;
    v5 = *(int *)(a1 + 172);
    v6 = *(int *)(a1 + 160);
    v7 = *(int *)(a1 + 176);
    if ( v4 > 2 )
    {
LABEL_4:
      v8 = *(long long *)(a1 + 120);
      v9 = *(int *)(a1 + 140)
         & ((*(int *)(a1 + 128) << *(int *)(a1 + 144))
          ^ (unsigned int)*(unsigned char *)(*(long long *)(a1 + 96) + v5 + 2));
      v10 = *(int *)(a1 + 88) & v5;
      *(int *)(a1 + 128) = v9;
      v11 = (short *)(v8 + 2 * v9);
      v12 = (unsigned short)*v11;
      *(short *)(*(long long *)(a1 + 112) + 2 * v10) = v12;
      *v11 = v5;
      *(int *)(a1 + 184) = v6;
      *(int *)(a1 + 164) = v7;
      *(int *)(a1 + 160) = 2;
      if ( v12 )
      {
        if ( *(int *)(a1 + 192) > v6 && v5 - v12 <= *(int *)(a1 + 80) - 262 )
        {
          v75 = v6;
          v57 = sub_5160(a1, v12);
          v6 = v75;
          *(int *)(a1 + 160) = v57;
          if ( v57 <= 5 && (*(int *)(a1 + 200) == 1 || v57 == 3 && v5 - *(int *)(a1 + 176) > 0x1000) )
          {
            *(int *)(a1 + 160) = 2;
            goto LABEL_20;
          }
        }
      }
      if ( v6 > 2 && *(int *)(a1 + 160) <= v6 )
      {
LABEL_21:
        v23 = *(unsigned int *)(a1 + 5900);
        v24 = *(long long *)(a1 + 5888);
        v25 = v4 + v5 - 3;
        v26 = v5 - v7;
        v27 = v26 - 1;
        v28 = v6 - 3;
        v29 = v26 - 2;
        *(int *)(a1 + 5900) = v23 + 1;
        *(char *)(v24 + v23) = v27;
        v30 = *(unsigned int *)(a1 + 5900);
        v31 = *(long long *)(a1 + 5888);
        *(int *)(a1 + 5900) = v30 + 1;
        *(char *)(v31 + v30) = HIBYTE(v27);
        v32 = *(unsigned int *)(a1 + 5900);
        v33 = *(long long *)(a1 + 5888);
        *(int *)(a1 + 5900) = v32 + 1;
        *(char *)(v33 + v32) = v28;
        ++*(short *)(a1 + 4LL * byte_10100[v28] + 1240);
        if ( v29 > 0xFFu )
          v34 = (unsigned char)byte_10200[((v29 >> 7) + 256) & 0x3FF];
        else
          v34 = (unsigned char)byte_10200[v29];
        ++*(short *)(a1 + 4 * v34 + 2504);
        v35 = *(int *)(a1 + 184);
        v36 = *(int *)(a1 + 172);
        v37 = *(int *)(a1 + 5900);
        v38 = *(int *)(a1 + 5904);
        v4 = *(int *)(a1 + 180) + 1 - v35;
        v39 = v35 - 2;
        v40 = v36 + v35;
        *(int *)(a1 + 180) = v4;
        v41 = v40 - 1;
        v42 = v40 - 2;
        *(int *)(a1 + 184) = v39;
        v43 = v36 + 1;
        do
        {
          *(int *)(a1 + 172) = v43;
          if ( v25 >= v43 )
          {
            v44 = *(long long *)(a1 + 120);
            v45 = *(int *)(a1 + 140)
                & ((*(int *)(a1 + 128) << *(int *)(a1 + 144))
                 ^ (unsigned int)*(unsigned char *)(*(long long *)(a1 + 96) + v43 + 2));
            v46 = *(int *)(a1 + 88) & v43;
            *(int *)(a1 + 128) = v45;
            v47 = (short *)(v44 + 2 * v45);
            *(short *)(*(long long *)(a1 + 112) + 2 * v46) = *v47;
            *v47 = v43;
          }
          v48 = v42 - v43++;
          *(int *)(a1 + 184) = v48;
        }
        while ( v41 != v43 );
        *(int *)(a1 + 168) = 0;
        *(int *)(a1 + 160) = 2;
        *(int *)(a1 + 172) = v41;
        if ( v37 == v38 )
        {
          v49 = *(long long *)(a1 + 152);
          v50 = v41;
          v51 = 0;
          v52 = v50 - v49;
          if ( v49 >= 0 )
            v51 = *(long long *)(a1 + 96) + (unsigned int)v49;
          sub_CFD0(a1, v51, v52, 0);
          v53 = *(long long *)a1;
          *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
          sub_5790(v53);
          if ( !*(int *)(*(long long *)a1 + 32LL) )
            return 0;
          v4 = *(int *)(a1 + 180);
        }
        goto LABEL_2;
      }
    }
    else
    {
      *(int *)(a1 + 184) = v6;
      *(int *)(a1 + 164) = v7;
      *(int *)(a1 + 160) = 2;
LABEL_20:
      if ( v6 > 2 )
        goto LABEL_21;
    }
    if ( *(int *)(a1 + 168) )
    {
      v13 = *(long long *)(a1 + 5888);
      v14 = *(unsigned char *)(*(long long *)(a1 + 96) + v5 - 1);
      v15 = *(unsigned int *)(a1 + 5900);
      *(int *)(a1 + 5900) = v15 + 1;
      *(char *)(v13 + v15) = 0;
      v16 = *(unsigned int *)(a1 + 5900);
      v17 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v16 + 1;
      *(char *)(v17 + v16) = 0;
      v18 = *(unsigned int *)(a1 + 5900);
      v19 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v18 + 1;
      *(char *)(v19 + v18) = v14;
      ++*(short *)(a1 + 4 * v14 + 212);
      if ( *(int *)(a1 + 5900) == *(int *)(a1 + 5904) )
      {
        v54 = *(long long *)(a1 + 152);
        v55 = 0;
        if ( v54 >= 0 )
          v55 = *(long long *)(a1 + 96) + (unsigned int)v54;
        sub_CFD0(a1, v55, *(unsigned int *)(a1 + 172) - v54, 0);
        v56 = *(long long *)a1;
        *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
        sub_5790(v56);
      }
      v20 = *(int *)(a1 + 180);
      ++*(int *)(a1 + 172);
      v4 = v20 - 1;
      v21 = *(long long *)a1;
      *(int *)(a1 + 180) = v4;
      if ( !*(int *)(v21 + 32) )
        return 0;
      goto LABEL_2;
    }
    --v4;
    *(int *)(a1 + 168) = 1;
    *(int *)(a1 + 172) = v5 + 1;
    *(int *)(a1 + 180) = v4;
    if ( v4 > 0x105 )
      goto LABEL_3;
  }
  if ( *(int *)(a1 + 168) )
  {
    v64 = *(long long *)(a1 + 5888);
    v65 = *(unsigned char *)(*(long long *)(a1 + 96) + (unsigned int)(*(int *)(a1 + 172) - 1));
    v66 = *(unsigned int *)(a1 + 5900);
    *(int *)(a1 + 5900) = v66 + 1;
    *(char *)(v64 + v66) = 0;
    v67 = *(unsigned int *)(a1 + 5900);
    v68 = *(long long *)(a1 + 5888);
    *(int *)(a1 + 5900) = v67 + 1;
    *(char *)(v68 + v67) = 0;
    v69 = *(unsigned int *)(a1 + 5900);
    v70 = *(long long *)(a1 + 5888);
    *(int *)(a1 + 5900) = v69 + 1;
    *(char *)(v70 + v69) = v65;
    ++*(short *)(a1 + 4 * v65 + 212);
    *(int *)(a1 + 168) = 0;
  }
  v58 = *(unsigned int *)(a1 + 172);
  v59 = 2;
  if ( (unsigned int)v58 <= 2 )
    v59 = *(int *)(a1 + 172);
  *(int *)(a1 + 5932) = v59;
  if ( a2 == 4 )
  {
    v71 = *(long long *)(a1 + 152);
    v72 = 0;
    v73 = v58 - v71;
    if ( v71 >= 0 )
      v72 = *(long long *)(a1 + 96) + (unsigned int)v71;
    sub_CFD0(a1, v72, v73, 1);
    v74 = *(long long *)a1;
    *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
    sub_5790(v74);
    return 2 - ((unsigned int)(*(int *)(*(long long *)a1 + 32LL) == 0) - 1);
  }
  else
  {
    result = 1;
    if ( *(int *)(a1 + 5900) )
    {
      v60 = *(long long *)(a1 + 152);
      v61 = 0;
      v62 = v58 - v60;
      if ( v60 >= 0 )
        v61 = *(long long *)(a1 + 96) + (unsigned int)v60;
      sub_CFD0(a1, v61, v62, 0);
      v63 = *(long long *)a1;
      *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
      sub_5790(v63);
      return *(int *)(*(long long *)a1 + 32LL) != 0;
    }
  }
  return result;
}


// Function: deflate_fast @ 0x5e20
long long deflate_fast(long long a1, int a2)
{
  unsigned int v3; // r13d
  long long v4; // rbp
  long long v5; // rcx
  long long v6; // rdx
  long long v7; // rax
  short *v8; // rax
  unsigned int v9; // esi
  unsigned int v10; // eax
  long long v11; // rdx
  int v12; // esi
  char *v13; // rdx
  short v14; // bp
  unsigned char v15; // al
  long long v16; // rdx
  char v17; // ch
  unsigned short v18; // bp
  long long v19; // rsi
  long long v20; // rdx
  long long v21; // rsi
  long long v22; // rax
  unsigned int v23; // eax
  int v24; // r12d
  int v25; // ebp
  int v26; // r11d
  long long v27; // r9
  int v28; // ecx
  int v29; // r10d
  long long v30; // rdx
  long long v31; // rax
  long long v32; // rsi
  long long v33; // rdi
  unsigned int v34; // r8d
  long long v35; // rax
  long long v36; // rdx
  long long v37; // rcx
  long long v38; // rdx
  long long v39; // rcx
  unsigned int v40; // r13d
  unsigned int v41; // eax
  unsigned int v42; // edi
  long long v43; // r15
  int v44; // r8d
  long long v45; // r14
  unsigned int v46; // edx
  unsigned int v47; // esi
  int v48; // r12d
  short *v49; // r8
  unsigned int v50; // eax
  int v51; // edx
  long long v52; // rcx
  long long v53; // rsi
  long long v54; // rdi
  long long v55; // rcx
  long long v56; // rsi
  long long v57; // rdi
  int v60; // [rsp+4h] [rbp-44h]

LABEL_1:
  v3 = *(int *)(a1 + 180);
LABEL_2:
  if ( v3 > 0x105 )
  {
LABEL_3:
    v4 = *(unsigned int *)(a1 + 172);
    goto LABEL_4;
  }
  while ( 1 )
  {
    sub_54B0(a1);
    v41 = *(int *)(a1 + 180);
    if ( v41 > 0x105 )
      goto LABEL_3;
    if ( !a2 )
      return 0;
    if ( !v41 )
      break;
    v4 = *(unsigned int *)(a1 + 172);
    if ( v41 <= 2 )
      goto LABEL_6;
LABEL_4:
    v5 = *(int *)(a1 + 88) & (unsigned int)v4;
    v6 = *(long long *)(a1 + 120);
    v7 = *(int *)(a1 + 140)
       & ((*(int *)(a1 + 128) << *(int *)(a1 + 144))
        ^ (unsigned int)*(unsigned char *)(*(long long *)(a1 + 96) + (unsigned int)(v4 + 2)));
    *(int *)(a1 + 128) = v7;
    v8 = (short *)(v6 + 2 * v7);
    v9 = (unsigned short)*v8;
    *(short *)(*(long long *)(a1 + 112) + 2 * v5) = v9;
    *v8 = v4;
    if ( !v9 || (unsigned int)v4 - v9 > *(int *)(a1 + 80) - 262 )
    {
LABEL_6:
      v10 = *(int *)(a1 + 160);
      goto LABEL_7;
    }
    v10 = sub_5160(a1, v9);
    *(int *)(a1 + 160) = v10;
LABEL_7:
    v11 = *(unsigned int *)(a1 + 5900);
    v12 = v11 + 1;
    v13 = (char *)(*(long long *)(a1 + 5888) + v11);
    if ( v10 > 2 )
    {
      v14 = v4 - *(short *)(a1 + 176);
      *(int *)(a1 + 5900) = v12;
      v15 = v10 - 3;
      *v13 = v14;
      v16 = *(unsigned int *)(a1 + 5900);
      v17 = HIBYTE(v14);
      v18 = v14 - 1;
      v19 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v16 + 1;
      *(char *)(v19 + v16) = v17;
      v20 = *(unsigned int *)(a1 + 5900);
      v21 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v20 + 1;
      *(char *)(v21 + v20) = v15;
      ++*(short *)(a1 + 4LL * byte_10100[v15] + 1240);
      if ( v18 > 0xFFu )
        v22 = (unsigned char)byte_10200[((v18 >> 7) + 256) & 0x3FF];
      else
        v22 = (unsigned char)byte_10200[v18];
      ++*(short *)(a1 + 4 * v22 + 2504);
      v23 = *(int *)(a1 + 160);
      v24 = *(int *)(a1 + 5900);
      v25 = *(int *)(a1 + 5904);
      v26 = *(int *)(a1 + 172);
      v3 = *(int *)(a1 + 180) - v23;
      v27 = *(long long *)(a1 + 96);
      v28 = *(int *)(a1 + 144);
      *(int *)(a1 + 180) = v3;
      v29 = *(int *)(a1 + 140);
      if ( v23 <= *(int *)(a1 + 192) && v3 > 2 )
      {
        v42 = v23 - 1;
        v43 = *(long long *)(a1 + 112);
        v44 = *(int *)(a1 + 88);
        *(int *)(a1 + 160) = v23 - 1;
        v45 = *(long long *)(a1 + 120);
        v46 = v26 + 1;
        v47 = *(int *)(a1 + 128);
        v60 = v24;
        v48 = v44;
        do
        {
          *(int *)(a1 + 172) = v46;
          --v42;
          v47 = v29 & ((v47 << v28) ^ *(unsigned char *)(v27 + v46 + 2));
          *(int *)(a1 + 128) = v47;
          v49 = (short *)(v45 + 2LL * v47);
          *(short *)(v43 + 2LL * (v48 & v46)) = *v49;
          *v49 = v46++;
          *(int *)(a1 + 160) = v42;
        }
        while ( v42 );
        v24 = v60;
        *(int *)(a1 + 172) = v23 + v26;
      }
      else
      {
        *(int *)(a1 + 160) = 0;
        v30 = v23 + v26;
        *(int *)(a1 + 172) = v30;
        LODWORD(v30) = *(unsigned char *)(v27 + v30);
        *(int *)(a1 + 128) = v30;
        *(int *)(a1 + 128) = v29 & (((int)v30 << v28) ^ *(unsigned char *)(v27 + v23 + v26 + 1));
      }
      if ( v24 != v25 )
        goto LABEL_2;
LABEL_14:
      v31 = *(long long *)(a1 + 152);
      v32 = 0;
      if ( v31 >= 0 )
        v32 = *(long long *)(a1 + 96) + (unsigned int)v31;
      sub_CFD0(a1, v32, *(unsigned int *)(a1 + 172) - v31, 0);
      v33 = *(long long *)a1;
      *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
      sub_5790(v33);
      if ( !*(int *)(*(long long *)a1 + 32LL) )
        return 0;
      goto LABEL_1;
    }
    v35 = *(unsigned char *)(*(long long *)(a1 + 96) + v4);
    *(int *)(a1 + 5900) = v12;
    *v13 = 0;
    v36 = *(unsigned int *)(a1 + 5900);
    v37 = *(long long *)(a1 + 5888);
    *(int *)(a1 + 5900) = v36 + 1;
    *(char *)(v37 + v36) = 0;
    v38 = *(unsigned int *)(a1 + 5900);
    v39 = *(long long *)(a1 + 5888);
    *(int *)(a1 + 5900) = v38 + 1;
    *(char *)(v39 + v38) = v35;
    ++*(short *)(a1 + 4 * v35 + 212);
    LODWORD(v35) = *(int *)(a1 + 180);
    ++*(int *)(a1 + 172);
    v40 = v35 - 1;
    LODWORD(v35) = *(int *)(a1 + 5904);
    *(int *)(a1 + 180) = v40;
    if ( *(int *)(a1 + 5900) == (int)v35 )
      goto LABEL_14;
    if ( v40 > 0x105 )
      goto LABEL_3;
  }
  v50 = *(int *)(a1 + 172);
  v51 = 2;
  if ( v50 <= 2 )
    v51 = *(int *)(a1 + 172);
  *(int *)(a1 + 5932) = v51;
  if ( a2 == 4 )
  {
    v55 = *(long long *)(a1 + 152);
    v56 = 0;
    if ( v55 >= 0 )
      v56 = *(long long *)(a1 + 96) + (unsigned int)v55;
    sub_CFD0(a1, v56, v50 - v55, 1);
    v57 = *(long long *)a1;
    *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
    sub_5790(v57);
    return 2 - ((unsigned int)(*(int *)(*(long long *)a1 + 32LL) == 0) - 1);
  }
  else
  {
    v34 = 1;
    if ( *(int *)(a1 + 5900) )
    {
      v52 = *(long long *)(a1 + 152);
      v53 = 0;
      if ( v52 >= 0 )
        v53 = *(long long *)(a1 + 96) + (unsigned int)v52;
      sub_CFD0(a1, v53, v50 - v52, 0);
      v54 = *(long long *)a1;
      *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
      sub_5790(v54);
      return *(int *)(*(long long *)a1 + 32LL) != 0;
    }
  }
  return v34;
}


// Function: deflate_huff @ 0x62c0
long long deflate_huff(long long a1, int a2)
{
  int v4; // eax
  long long v5; // rax
  long long v6; // rdx
  long long v7; // rcx
  long long v8; // rax
  long long v9; // rdx
  long long v10; // rdx
  long long v11; // rcx
  long long v12; // rdx
  long long v13; // rcx
  int v14; // edi
  long long v15; // rdx
  int v16; // edi
  long long result; // rax
  long long v18; // rax
  long long v19; // rsi
  long long v20; // rdi
  long long v21; // rax
  long long v22; // rsi
  long long v23; // rdx
  long long v24; // rdi
  long long v25; // rax
  long long v26; // rsi
  long long v27; // rdi

LABEL_1:
  v4 = *(int *)(a1 + 180);
  while ( 1 )
  {
    if ( !v4 )
    {
      sub_54B0(a1);
      if ( !*(int *)(a1 + 180) )
        break;
    }
    v5 = *(unsigned int *)(a1 + 172);
    v6 = *(long long *)(a1 + 96);
    *(int *)(a1 + 160) = 0;
    v7 = *(long long *)(a1 + 5888);
    v8 = *(unsigned char *)(v6 + v5);
    v9 = *(unsigned int *)(a1 + 5900);
    *(int *)(a1 + 5900) = v9 + 1;
    *(char *)(v7 + v9) = 0;
    v10 = *(unsigned int *)(a1 + 5900);
    v11 = *(long long *)(a1 + 5888);
    *(int *)(a1 + 5900) = v10 + 1;
    *(char *)(v11 + v10) = 0;
    v12 = *(unsigned int *)(a1 + 5900);
    v13 = *(long long *)(a1 + 5888);
    *(int *)(a1 + 5900) = v12 + 1;
    *(char *)(v13 + v12) = v8;
    v14 = *(int *)(a1 + 172);
    ++*(short *)(a1 + 4 * v8 + 212);
    v15 = (unsigned int)(v14 + 1);
    v16 = *(int *)(a1 + 5904);
    v4 = *(int *)(a1 + 180) - 1;
    *(int *)(a1 + 172) = v15;
    *(int *)(a1 + 180) = v4;
    if ( *(int *)(a1 + 5900) == v16 )
    {
      v21 = *(long long *)(a1 + 152);
      v22 = 0;
      v23 = v15 - v21;
      if ( v21 >= 0 )
        v22 = *(long long *)(a1 + 96) + (unsigned int)v21;
      sub_CFD0(a1, v22, v23, 0);
      v24 = *(long long *)a1;
      *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
      sub_5790(v24);
      if ( !*(int *)(*(long long *)a1 + 32LL) )
        return 0;
      goto LABEL_1;
    }
  }
  if ( !a2 )
    return 0;
  *(int *)(a1 + 5932) = 0;
  if ( a2 == 4 )
  {
    v25 = *(long long *)(a1 + 152);
    v26 = 0;
    if ( v25 >= 0 )
      v26 = *(long long *)(a1 + 96) + (unsigned int)v25;
    sub_CFD0(a1, v26, *(unsigned int *)(a1 + 172) - v25, 1);
    v27 = *(long long *)a1;
    *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
    sub_5790(v27);
    return 2 - ((unsigned int)(*(int *)(*(long long *)a1 + 32LL) == 0) - 1);
  }
  else
  {
    result = 1;
    if ( *(int *)(a1 + 5900) )
    {
      v18 = *(long long *)(a1 + 152);
      v19 = 0;
      if ( v18 >= 0 )
        v19 = *(long long *)(a1 + 96) + (unsigned int)v18;
      sub_CFD0(a1, v19, *(unsigned int *)(a1 + 172) - v18, 0);
      v20 = *(long long *)a1;
      *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
      sub_5790(v20);
      return *(int *)(*(long long *)a1 + 32LL) != 0;
    }
  }
  return result;
}


// Function: deflate_rle @ 0x64d0
long long deflate_rle(long long a1, int a2)
{
  unsigned int v4; // eax
  long long v5; // rcx
  long long v6; // rsi
  int v7; // edx
  char *v8; // rdx
  char v9; // di
  long long v10; // rdx
  long long v11; // rax
  long long v12; // rcx
  long long v13; // rdx
  long long v14; // rcx
  long long v15; // rdx
  long long v16; // rcx
  int v17; // edi
  long long v18; // rdx
  int v19; // edi
  char *v20; // rdx
  unsigned int v21; // edx
  unsigned char v22; // al
  long long v23; // rdx
  long long v24; // rcx
  long long v25; // rdx
  long long v26; // rcx
  long long v27; // rdx
  long long v28; // rcx
  int v29; // edi
  int v30; // eax
  long long v31; // rax
  long long v32; // rsi
  long long v33; // rdx
  long long v34; // rdi
  long long result; // rax
  long long v36; // rax
  long long v37; // rsi
  long long v38; // rdi
  long long v39; // rax
  long long v40; // rsi
  long long v41; // rdi

LABEL_1:
  v4 = *(int *)(a1 + 180);
  while ( 1 )
  {
    if ( v4 <= 0x102 )
    {
      sub_54B0(a1);
      v4 = *(int *)(a1 + 180);
      if ( v4 <= 0x102 )
        break;
    }
    v5 = *(unsigned int *)(a1 + 172);
    v6 = *(long long *)(a1 + 96);
    *(int *)(a1 + 160) = 0;
    v7 = v5;
LABEL_3:
    if ( !v7 )
      goto LABEL_5;
    v8 = (char *)(v6 + v5 - 1);
    v9 = *v8;
    if ( *v8 != *(char *)(v6 + v5) || v9 != v8[2] || v9 != v8[3] )
      goto LABEL_5;
    v20 = v8 + 3;
    while ( 1 )
    {
      if ( v9 != v20[1] )
      {
        LODWORD(v20) = (int)v20 + 1;
        goto LABEL_25;
      }
      if ( v9 != v20[2] )
      {
        LODWORD(v20) = (int)v20 + 2;
        goto LABEL_25;
      }
      if ( v9 != v20[3] )
      {
        LODWORD(v20) = (int)v20 + 3;
        goto LABEL_25;
      }
      if ( v9 != v20[4] )
      {
        LODWORD(v20) = (int)v20 + 4;
        goto LABEL_25;
      }
      if ( v9 != v20[5] )
      {
        LODWORD(v20) = (int)v20 + 5;
        goto LABEL_25;
      }
      if ( v9 != v20[6] )
      {
        LODWORD(v20) = (int)v20 + 6;
        goto LABEL_25;
      }
      if ( v9 != v20[7] )
        break;
      v20 += 8;
      if ( *v20 != v9 || v6 + v5 + 258 <= (unsigned long long)v20 )
        goto LABEL_25;
    }
    LODWORD(v20) = (int)v20 + 7;
LABEL_25:
    v21 = (int)v20 - (v6 + v5);
    *(int *)(a1 + 160) = v21;
    if ( v21 > v4 )
    {
      *(int *)(a1 + 160) = v4;
      LOBYTE(v21) = v4;
      goto LABEL_27;
    }
    if ( v21 > 2 )
    {
LABEL_27:
      v22 = v21 - 3;
      v23 = *(unsigned int *)(a1 + 5900);
      v24 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v23 + 1;
      *(char *)(v24 + v23) = 1;
      v25 = *(unsigned int *)(a1 + 5900);
      v26 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v25 + 1;
      *(char *)(v26 + v25) = 0;
      v27 = *(unsigned int *)(a1 + 5900);
      v28 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v27 + 1;
      *(char *)(v28 + v27) = v22;
      LODWORD(v27) = *(int *)(a1 + 160);
      v29 = *(int *)(a1 + 5904);
      ++*(short *)(a1 + 4LL * byte_10100[v22] + 1240);
      ++*(short *)(a1 + 2504);
      v30 = *(int *)(a1 + 180);
      *(int *)(a1 + 160) = 0;
      v4 = v30 - v27;
      v18 = (unsigned int)(*(int *)(a1 + 172) + v27);
      *(int *)(a1 + 180) = v4;
      *(int *)(a1 + 172) = v18;
      if ( *(int *)(a1 + 5900) == v29 )
      {
LABEL_28:
        v31 = *(long long *)(a1 + 152);
        v32 = 0;
        v33 = v18 - v31;
        if ( v31 >= 0 )
          v32 = *(long long *)(a1 + 96) + (unsigned int)v31;
        sub_CFD0(a1, v32, v33, 0);
        v34 = *(long long *)a1;
        *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
        sub_5790(v34);
        if ( !*(int *)(*(long long *)a1 + 32LL) )
          return 0;
        goto LABEL_1;
      }
    }
    else
    {
LABEL_5:
      v10 = *(unsigned int *)(a1 + 5900);
      v11 = *(unsigned char *)(v6 + v5);
      v12 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v10 + 1;
      *(char *)(v12 + v10) = 0;
      v13 = *(unsigned int *)(a1 + 5900);
      v14 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v13 + 1;
      *(char *)(v14 + v13) = 0;
      v15 = *(unsigned int *)(a1 + 5900);
      v16 = *(long long *)(a1 + 5888);
      *(int *)(a1 + 5900) = v15 + 1;
      *(char *)(v16 + v15) = v11;
      v17 = *(int *)(a1 + 172);
      ++*(short *)(a1 + 4 * v11 + 212);
      v18 = (unsigned int)(v17 + 1);
      v19 = *(int *)(a1 + 5904);
      v4 = *(int *)(a1 + 180) - 1;
      *(int *)(a1 + 172) = v18;
      *(int *)(a1 + 180) = v4;
      if ( *(int *)(a1 + 5900) == v19 )
        goto LABEL_28;
    }
  }
  if ( !a2 )
    return 0;
  if ( v4 )
  {
    v5 = *(unsigned int *)(a1 + 172);
    v6 = *(long long *)(a1 + 96);
    *(int *)(a1 + 160) = 0;
    v7 = v5;
    if ( v4 <= 2 )
      goto LABEL_5;
    goto LABEL_3;
  }
  *(int *)(a1 + 5932) = 0;
  if ( a2 == 4 )
  {
    v39 = *(long long *)(a1 + 152);
    v40 = 0;
    if ( v39 >= 0 )
      v40 = *(long long *)(a1 + 96) + (unsigned int)v39;
    sub_CFD0(a1, v40, *(unsigned int *)(a1 + 172) - v39, 1);
    v41 = *(long long *)a1;
    *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
    sub_5790(v41);
    return 2 - ((unsigned int)(*(int *)(*(long long *)a1 + 32LL) == 0) - 1);
  }
  else
  {
    result = 1;
    if ( *(int *)(a1 + 5900) )
    {
      v36 = *(long long *)(a1 + 152);
      v37 = 0;
      if ( v36 >= 0 )
        v37 = *(long long *)(a1 + 96) + (unsigned int)v36;
      sub_CFD0(a1, v37, *(unsigned int *)(a1 + 172) - v36, 0);
      v38 = *(long long *)a1;
      *(long long *)(a1 + 152) = *(unsigned int *)(a1 + 172);
      sub_5790(v38);
      return *(int *)(*(long long *)a1 + 32LL) != 0;
    }
  }
  return result;
}


// Function: deflate_stored @ 0x68b0
long long deflate_stored(long long a1, int a2)
{
  unsigned long long v4; // r13
  unsigned long long v5; // rax
  long long v6; // rdi
  unsigned int v7; // esi
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // r12d
  long long v11; // r14
  int v12; // r15d
  unsigned int v13; // r12d
  unsigned int v14; // r15d
  long long v15; // rax
  char *v16; // r8
  long long v17; // rsi
  unsigned int v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // edx
  unsigned long long v21; // rsi
  long long v22; // rdi
  unsigned int v23; // ecx
  unsigned int v24; // edi
  long long v25; // rsi
  unsigned long long v26; // rdx
  unsigned int v27; // eax
  unsigned int v28; // r8d
  unsigned int v30; // r13d
  long long v31; // r8
  long long v32; // rdx
  unsigned int v33; // edx
  long long v34; // rbp
  unsigned int v35; // eax
  char *v36; // rdi
  unsigned int v37; // eax
  long long v38; // rbp
  size_t v39; // rdx
  void *v40; // rdi
  unsigned int v41; // eax
  unsigned int v42; // [rsp+Ch] [rbp-3Ch]

  v4 = *(long long *)(a1 + 24) - 5LL;
  v5 = *(unsigned int *)(a1 + 80);
  v6 = *(long long *)a1;
  if ( v4 > v5 )
    LODWORD(v4) = v5;
  v42 = *(int *)(v6 + 8);
  v7 = v42;
  do
  {
    while ( 1 )
    {
      v8 = *(int *)(v6 + 32);
      v9 = (*(int *)(a1 + 5940) + 42) >> 3;
      if ( v8 < v9 )
        goto LABEL_29;
      v10 = 0xFFFF;
      v11 = (unsigned int)(*(int *)(a1 + 172) - *(int *)(a1 + 152));
      if ( (unsigned long long)v7 + v11 < 0xFFFF )
        v10 = v11 + v7;
      if ( v10 > v8 - v9 )
        v10 = v8 - v9;
      if ( (unsigned int)v4 > v10 && (a2 != 4 && v10 == 0 || !a2 || (int)v11 + v7 != v10) )
      {
LABEL_29:
        v13 = 0;
        v14 = v42 - v7;
        if ( v42 != v7 )
          goto LABEL_23;
LABEL_30:
        v19 = *(int *)(a1 + 172);
        goto LABEL_31;
      }
      v12 = 0;
      if ( a2 == 4 )
        v12 = (int)v11 + v7 == v10;
      sub_CDD0(a1, 0, 0, v12);
      *(short *)(*(long long *)(a1 + 16) + *(long long *)(a1 + 40) - 4LL) = v10;
      *(short *)(*(long long *)(a1 + 16) + *(long long *)(a1 + 40) - 2LL) = ~(short)v10;
      sub_5790(*(long long *)a1);
      if ( (int)v11 )
        break;
      v6 = *(long long *)a1;
      if ( v10 )
        goto LABEL_21;
LABEL_5:
      v7 = *(int *)(v6 + 8);
      if ( v12 )
        goto LABEL_22;
    }
    if ( (unsigned int)v11 > v10 )
      LODWORD(v11) = v10;
    memcpy(
      *(void **)(*(long long *)a1 + 24LL),
      (const void *)(*(long long *)(a1 + 96) + *(long long *)(a1 + 152)),
      (unsigned int)v11);
    v6 = *(long long *)a1;
    v10 -= v11;
    *(long long *)(v6 + 24) += (unsigned int)v11;
    *(int *)(v6 + 32) -= v11;
    *(long long *)(v6 + 40) += (unsigned int)v11;
    *(long long *)(a1 + 152) += (unsigned int)v11;
    if ( !v10 )
      goto LABEL_5;
LABEL_21:
    sub_5420(v6, *(void **)(v6 + 24), v10);
    v6 = *(long long *)a1;
    *(int *)(v6 + 32) -= v10;
    v7 = *(int *)(v6 + 8);
    *(long long *)(v6 + 24) += v10;
    *(long long *)(v6 + 40) += v10;
  }
  while ( !v12 );
LABEL_22:
  v13 = 1;
  v14 = v42 - v7;
  if ( v42 == v7 )
    goto LABEL_30;
LABEL_23:
  v15 = *(unsigned int *)(a1 + 80);
  v16 = *(char **)(a1 + 96);
  if ( (unsigned int)v15 <= v14 )
  {
    *(int *)(a1 + 5928) = 2;
    memcpy(v16, (const void *)(*(long long *)v6 - (unsigned int)v15), (unsigned int)v15);
    v19 = *(int *)(a1 + 80);
    *(int *)(a1 + 172) = v19;
    v20 = v19;
  }
  else
  {
    v17 = *(unsigned int *)(a1 + 172);
    if ( *(long long *)(a1 + 104) - v17 <= (unsigned long long)v14 )
    {
      v39 = (unsigned int)(*(int *)(a1 + 172) - v15);
      v40 = *(void **)(a1 + 96);
      *(int *)(a1 + 172) = v39;
      memcpy(v40, &v16[v15], v39);
      v41 = *(int *)(a1 + 5928);
      if ( v41 <= 1 )
        *(int *)(a1 + 5928) = v41 + 1;
      v17 = *(unsigned int *)(a1 + 172);
      if ( *(int *)(a1 + 5932) > (unsigned int)v17 )
        *(int *)(a1 + 5932) = v17;
      v6 = *(long long *)a1;
      v16 = *(char **)(a1 + 96);
    }
    memcpy(&v16[v17], (const void *)(*(long long *)v6 - v14), v14);
    v18 = *(int *)(a1 + 80) - *(int *)(a1 + 5932);
    v19 = v14 + *(int *)(a1 + 172);
    *(int *)(a1 + 172) = v19;
    if ( v18 > v14 )
      v18 = v14;
    v20 = *(int *)(a1 + 5932) + v18;
  }
  *(int *)(a1 + 5932) = v20;
  *(long long *)(a1 + 152) = v19;
LABEL_31:
  v21 = v19;
  if ( *(long long *)(a1 + 5944) < (unsigned long long)v19 )
    *(long long *)(a1 + 5944) = v19;
  if ( v13 )
    return 3;
  v22 = *(long long *)a1;
  v23 = *(int *)(*(long long *)a1 + 8LL);
  if ( (a2 & 0xFFFFFFFB) == 0 || v23 )
  {
    v30 = *(int *)(a1 + 104) - v19;
    if ( v30 < v23 && (v31 = *(long long *)(a1 + 152), v32 = *(unsigned int *)(a1 + 80), v31 >= v32) )
    {
      v35 = v19 - v32;
      v36 = *(char **)(a1 + 96);
      *(long long *)(a1 + 152) = v31 - v32;
      *(int *)(a1 + 172) = v35;
      memcpy(v36, &v36[v32], v35);
      v37 = *(int *)(a1 + 5928);
      if ( v37 <= 1 )
        *(int *)(a1 + 5928) = v37 + 1;
      v21 = *(unsigned int *)(a1 + 172);
      v30 += *(int *)(a1 + 80);
      v19 = v21;
      if ( *(int *)(a1 + 5932) > (unsigned int)v21 )
        *(int *)(a1 + 5932) = v21;
      v22 = *(long long *)a1;
      if ( v30 > *(int *)(*(long long *)a1 + 8LL) )
        v30 = *(int *)(*(long long *)a1 + 8LL);
      if ( v30 )
        goto LABEL_53;
    }
    else
    {
      if ( v30 > v23 )
        v30 = *(int *)(*(long long *)a1 + 8LL);
      if ( v30 )
      {
LABEL_53:
        sub_5420(v22, (void *)(*(long long *)(a1 + 96) + v21), v30);
        v24 = *(int *)(a1 + 80);
        v33 = v24 - *(int *)(a1 + 5932);
        v19 = v30 + *(int *)(a1 + 172);
        *(int *)(a1 + 172) = v19;
        v21 = v19;
        if ( v33 > v30 )
          v33 = v30;
        *(int *)(a1 + 5932) += v33;
LABEL_38:
        if ( *(long long *)(a1 + 5944) < v21 )
          *(long long *)(a1 + 5944) = v21;
        v25 = *(long long *)(a1 + 152);
        v26 = *(long long *)(a1 + 24) - (unsigned int)((*(int *)(a1 + 5940) + 42) >> 3);
        if ( v26 > 0xFFFF )
          LODWORD(v26) = 0xFFFF;
        v27 = v19 - v25;
        v28 = v26;
        if ( v24 > (unsigned int)v26 )
          v24 = v26;
        if ( v24 <= v27 )
        {
          if ( v27 <= (unsigned int)v26 )
            LODWORD(v26) = v27;
          if ( a2 == 4 && !*(int *)(*(long long *)a1 + 8LL) && v28 >= v27 )
            goto LABEL_75;
        }
        else
        {
          if ( a2 != 4 && v27 == 0 || !a2 || *(int *)(*(long long *)a1 + 8LL) || (unsigned int)v26 < v27 )
            return v13;
          if ( (unsigned int)v26 <= v27 )
            v27 = v26;
          LODWORD(v26) = v27;
          if ( a2 == 4 )
          {
LABEL_75:
            v38 = (unsigned int)v26;
            v13 = 2;
            sub_CDD0(a1, *(long long *)(a1 + 96) + v25, (unsigned int)v26, 1);
            *(long long *)(a1 + 152) += v38;
            sub_5790(*(long long *)a1);
            return v13;
          }
        }
        v34 = (unsigned int)v26;
        sub_CDD0(a1, *(long long *)(a1 + 96) + v25, (unsigned int)v26, 0);
        *(long long *)(a1 + 152) += v34;
        sub_5790(*(long long *)a1);
        return v13;
      }
    }
LABEL_37:
    v24 = *(int *)(a1 + 80);
    goto LABEL_38;
  }
  if ( v19 != *(long long *)(a1 + 152) )
    goto LABEL_37;
  return 1;
}


// Function: deflateSetDictionary @ 0x6df0
long long deflateSetDictionary(long long *a1, long long a2, unsigned int a3)
{
  int v5; // eax
  long long v6; // r13
  int v7; // ebp
  long long v8; // r14
  unsigned int v9; // eax
  short *v10; // rdi
  unsigned int v11; // eax
  long long result; // rax
  int v13; // ecx
  long long v14; // r12
  unsigned int v15; // esi
  int v16; // eax
  int v17; // ecx
  long long v18; // r15
  int v19; // r14d
  long long v20; // r11
  long long v21; // r10
  int v22; // r8d
  unsigned int v23; // r9d
  unsigned int v24; // edx
  short *v25; // rsi
  long long v26; // rax
  int v27; // [rsp+Ch] [rbp-3Ch]

  v5 = sub_50A0(a1);
  if ( !a2 )
    return 4294967294LL;
  if ( v5 )
    return 4294967294LL;
  v6 = a1[7];
  v7 = *(int *)(v6 + 48);
  if ( v7 == 2 )
    return 4294967294LL;
  v8 = a2;
  if ( v7 == 1 )
  {
    if ( *(int *)(v6 + 8) == 42 )
    {
      result = 4294967294LL;
      if ( *(int *)(v6 + 180) )
        return result;
      a1[12] = sub_D8E0(a1[12], a2, a3);
      v9 = *(int *)(v6 + 80);
      *(int *)(v6 + 48) = 0;
      if ( a3 >= v9 )
        goto LABEL_9;
      goto LABEL_13;
    }
    return 4294967294LL;
  }
  if ( *(int *)(v6 + 180) )
    return 4294967294LL;
  v9 = *(int *)(v6 + 80);
  *(int *)(v6 + 48) = 0;
  if ( v9 <= a3 )
  {
    if ( !v7 )
    {
      v10 = *(short **)(v6 + 120);
      v11 = *(int *)(v6 + 132) - 1;
      v10[v11] = 0;
      memset(v10, 0, 2LL * v11);
      v9 = *(int *)(v6 + 80);
      *(int *)(v6 + 172) = 0;
      *(long long *)(v6 + 152) = 0;
      *(int *)(v6 + 5932) = 0;
    }
LABEL_9:
    v8 = a3 - v9 + a2;
    goto LABEL_14;
  }
LABEL_13:
  v9 = a3;
LABEL_14:
  v13 = *((int *)a1 + 2);
  v14 = *a1;
  *((int *)a1 + 2) = v9;
  *a1 = v8;
  v27 = v13;
  while ( 1 )
  {
    sub_54B0(v6);
    v15 = *(int *)(v6 + 180);
    if ( v15 <= 2 )
      break;
    v16 = *(int *)(v6 + 172);
    v17 = *(int *)(v6 + 144);
    v18 = *(long long *)(v6 + 96);
    v19 = *(int *)(v6 + 140);
    v20 = *(long long *)(v6 + 120);
    v21 = *(long long *)(v6 + 112);
    v22 = v15 + v16 - 2;
    v23 = *(int *)(v6 + 88);
    v24 = *(int *)(v6 + 128);
    do
    {
      v24 = v19 & ((v24 << v17) ^ *(unsigned char *)(v18 + (unsigned int)(v16 + 2)));
      *(int *)(v6 + 128) = v24;
      v25 = (short *)(v20 + 2LL * v24);
      *(short *)(v21 + 2LL * (v16 & v23)) = *v25;
      *v25 = v16++;
    }
    while ( v16 != v22 );
    *(int *)(v6 + 172) = v16;
    *(int *)(v6 + 180) = 2;
  }
  v26 = *(int *)(v6 + 172) + v15;
  *(int *)(v6 + 5932) = v15;
  *(int *)(v6 + 172) = v26;
  *(long long *)(v6 + 152) = v26;
  *(long long *)(v6 + 180) = 0x200000000LL;
  *(int *)(v6 + 160) = 2;
  *(int *)(v6 + 168) = 0;
  *((int *)a1 + 2) = v27;
  result = 0;
  *a1 = v14;
  *(int *)(v6 + 48) = v7;
  return result;
}


// Function: deflateGetDictionary @ 0x7020
long long deflateGetDictionary(long long *a1, void *a2, unsigned int *a3)
{
  long long v4; // rcx
  unsigned int v5; // r12d
  unsigned int v6; // eax
  long long v7; // rdi
  unsigned int v8; // edx
  unsigned int v9; // ebp

  if ( sub_50A0(a1) )
  {
    return (unsigned int)-2;
  }
  else
  {
    v4 = a1[7];
    v5 = 0;
    v6 = *(int *)(v4 + 172);
    v7 = *(unsigned int *)(v4 + 180);
    v8 = *(int *)(v4 + 80);
    if ( v6 + (unsigned int)v7 <= v8 )
      v8 = v6 + v7;
    v9 = v8;
    if ( a2 && v8 )
      memcpy(a2, (const void *)(*(long long *)(v4 + 96) + v7 + v6 - v8), v8);
    if ( a3 )
      *a3 = v9;
  }
  return v5;
}


// Function: deflateResetKeep @ 0x70a0
long long deflateResetKeep(long long a1)
{
  long long v1; // rbp
  unsigned int v2; // r12d
  long long v3; // rax
  int v4; // eax
  long long v5; // rax

  if ( sub_50A0((long long *)a1) )
  {
    return (unsigned int)-2;
  }
  else
  {
    v1 = *(long long *)(a1 + 56);
    v2 = 0;
    *(long long *)(a1 + 40) = 0;
    *(long long *)(a1 + 16) = 0;
    v3 = *(long long *)(v1 + 16);
    *(long long *)(a1 + 48) = 0;
    *(int *)(a1 + 88) = 2;
    *(long long *)(v1 + 32) = v3;
    v4 = *(int *)(v1 + 48);
    *(long long *)(v1 + 40) = 0;
    if ( v4 < 0 )
    {
      v4 = -v4;
      *(int *)(v1 + 48) = v4;
    }
    if ( v4 == 2 )
    {
      *(int *)(v1 + 8) = 57;
      v5 = sub_DD50(0, 0, 0);
    }
    else
    {
      *(int *)(v1 + 8) = 42;
      v5 = sub_D8E0(0, 0, 0);
    }
    *(long long *)(a1 + 96) = v5;
    *(int *)(v1 + 76) = -2;
    sub_CD60(v1);
  }
  return v2;
}


// Function: deflateReset @ 0x7150
long long deflateReset(long long a1)
{
  long long result; // rax

  result = sub_70A0(a1);
  if ( !(int)result )
  {
    sub_5370(*(long long *)(a1 + 56));
    return 0;
  }
  return result;
}


// Function: deflatePrime @ 0x7200
long long deflatePrime(long long *a1, unsigned int a2, int a3)
{
  long long v4; // r14
  unsigned int v5; // r12d
  int v6; // edx
  unsigned int v7; // ebp

  if ( sub_50A0(a1) )
  {
    return (unsigned int)-2;
  }
  else
  {
    v4 = a1[7];
    v5 = a2;
    if ( a2 > 0x10 || *(long long *)(v4 + 5888) < (unsigned long long)(*(long long *)(v4 + 32) + 2LL) )
    {
      return (unsigned int)-5;
    }
    else
    {
      do
      {
        v6 = *(int *)(v4 + 5940);
        v7 = 16 - v6;
        if ( 16 - v6 > (int)v5 )
          v7 = v5;
        *(int *)(v4 + 5940) = v7 + v6;
        *(short *)(v4 + 5936) |= (a3 & ((1 << v7) - 1)) << v6;
        sub_CEF0(v4);
        a3 >>= v7;
        v5 -= v7;
      }
      while ( v5 );
    }
  }
  return v5;
}


// Function: deflate @ 0x7460
long long deflate(long long a1, unsigned int a2)
{
  long long v2; // rcx
  long long v4; // rbx
  int v6; // edx
  unsigned int v7; // r13d
  int v8; // eax
  bool v9; // zf
  int v10; // esi
  int v11; // r8d
  long long v12; // rax
  int v13; // edx
  int v14; // eax
  unsigned int v15; // ecx
  int v17; // edi
  int v18; // edx
  int v19; // eax
  unsigned long long v20; // rsi
  long long v21; // rax
  long long v22; // rdx
  long long v23; // rax
  long long v24; // rcx
  long long v25; // rdx
  long long v26; // rdx
  long long v27; // rcx
  long long v28; // rax
  long long v29; // rdx
  long long v30; // rcx
  long long v31; // rax
  long long v32; // rax
  long long v33; // rcx
  long long v34; // rdx
  long long v35; // rax
  long long v36; // rcx
  long long v37; // rdx
  long long v38; // rdx
  long long v39; // rcx
  long long v40; // rax
  long long v41; // rdx
  long long v42; // rcx
  long long v43; // rax
  int v44; // eax
  unsigned int v45; // eax
  long long v46; // rax
  long long v47; // rdx
  long long v48; // rax
  long long v49; // rax
  long long v50; // rdx
  long long v51; // rax
  long long v52; // rdx
  long long v53; // rax
  long long v54; // rsi
  long long v55; // rcx
  char v56; // al
  long long v57; // rdx
  long long v58; // rcx
  long long v59; // rax
  long long v60; // rdx
  long long v61; // rcx
  long long v62; // rax
  long long v63; // rdx
  long long v64; // rcx
  long long v65; // rax
  long long v66; // rdx
  long long v67; // rcx
  long long v68; // rax
  int v69; // edx
  char v70; // al
  long long v71; // rdx
  long long v72; // rcx
  long long v73; // rdx
  long long v74; // rax
  long long v75; // rax
  int v76; // ecx
  long long v77; // rax
  long long v78; // rdx
  long long v79; // rdx
  int v80; // ecx
  long long v81; // rax
  long long v82; // rsi
  int v83; // r14d
  long long v84; // rdi
  unsigned long long v85; // r9
  unsigned long long v86; // rax
  unsigned int v87; // r14d
  size_t v88; // r12
  size_t v89; // r12
  unsigned long long v90; // rdx
  int v91; // eax
  long long v92; // rax
  long long v93; // rdx
  long long v94; // rax
  long long v95; // rdx
  long long v96; // rax
  long long v97; // rdx
  long long v98; // rax
  long long v99; // rdx
  long long v100; // rax
  long long v101; // rdx
  int v102; // edx
  char v103; // al
  long long v104; // rdx
  long long v105; // rcx
  long long v106; // rax
  long long v107; // rdx
  int v108; // edx
  size_t v109; // r12
  unsigned long long v110; // rsi
  unsigned long long v111; // rdx
  long long v112; // rcx
  long long v113; // rax
  long long v114; // rcx
  unsigned long long v115; // rdx
  unsigned long long v116; // rsi
  unsigned long long v117; // rdx
  long long v118; // rcx
  long long v119; // rax
  long long v120; // rcx
  int v121; // eax
  unsigned long long v122; // rdx
  long long v123; // rax
  long long v124; // rcx
  long long v125; // rdx
  long long v126; // rax
  long long v127; // rcx
  long long v128; // rdx
  int v129; // ecx
  short *v130; // rdi
  unsigned int v131; // eax
  int v132; // [rsp+8h] [rbp-50h]
  unsigned long long v133; // [rsp+8h] [rbp-50h]
  int v134; // [rsp+14h] [rbp-44h]
  unsigned long long v135; // [rsp+18h] [rbp-40h]

  if ( sub_50A0((long long *)a1) || a2 > 5 )
    return (unsigned int)-2;
  v4 = *(long long *)(a1 + 56);
  if ( !*(long long *)(a1 + 24)
    || (v6 = *(int *)(a1 + 8), v7 = 0, v6) && !*(long long *)a1
    || (v8 = *(int *)(v4 + 8), LOBYTE(v2) = a2 != 4, v8 == 666) && a2 != 4 )
  {
    v7 = -2;
    *(long long *)(a1 + 48) = "stream error";
    return v7;
  }
  if ( !*(int *)(a1 + 32) )
    goto LABEL_141;
  v9 = *(long long *)(v4 + 40) == 0;
  v10 = *(int *)(v4 + 76);
  *(int *)(v4 + 76) = a2;
  if ( v9 )
  {
    if ( v6 )
    {
      if ( v8 != 666 )
        goto LABEL_12;
LABEL_141:
      v7 = -5;
      *(long long *)(a1 + 48) = "buffer error";
      return v7;
    }
    v17 = 2 * a2;
    if ( a2 == 5 )
      v17 = 1;
    v18 = 2 * v10;
    if ( v10 > 4 )
      v18 = 2 * v10 - 9;
    if ( v17 <= v18 && a2 != 4 )
      goto LABEL_141;
  }
  else
  {
    sub_5790(a1);
    if ( !*(int *)(a1 + 32) )
      goto LABEL_26;
    v8 = *(int *)(v4 + 8);
  }
  if ( v8 == 666 )
  {
    if ( !*(int *)(a1 + 8) )
      goto LABEL_36;
    goto LABEL_141;
  }
LABEL_12:
  if ( v8 != 42 )
    goto LABEL_54;
  if ( *(int *)(v4 + 48) )
  {
    v45 = (*(int *)(v4 + 84) << 12) - 30720;
    if ( *(int *)(v4 + 200) <= 1 )
    {
      v108 = *(int *)(v4 + 196);
      if ( v108 > 1 )
      {
        if ( v108 > 5 )
        {
          v129 = (*(int *)(v4 + 84) << 12) - 30720;
          LOBYTE(v45) = -64;
          LOBYTE(v129) = 0x80;
          if ( v108 == 6 )
            v45 = v129;
        }
        else
        {
          v45 |= 0x40u;
        }
      }
    }
    if ( *(int *)(v4 + 172) )
      v45 |= 0x20u;
    sub_5130(v4, 31 * (v45 / 0x1F) + 31);
    if ( *(int *)(v4 + 172) )
    {
      sub_5130(v4, *(int *)(a1 + 98));
      sub_5130(v4, *(unsigned short *)(a1 + 96));
    }
    *(long long *)(a1 + 96) = sub_D8E0(0, 0, 0);
    *(int *)(v4 + 8) = 113;
    sub_5790(a1);
    if ( *(long long *)(v4 + 40) )
      goto LABEL_26;
    v8 = *(int *)(v4 + 8);
LABEL_54:
    if ( v8 == 57 )
    {
      v46 = sub_DD50(0, 0, 0);
      v47 = *(long long *)(v4 + 16);
      *(long long *)(a1 + 96) = v46;
      v48 = *(long long *)(v4 + 40);
      *(long long *)(v4 + 40) = v48 + 1;
      *(char *)(v47 + v48) = 31;
      v49 = *(long long *)(v4 + 40);
      v50 = *(long long *)(v4 + 16);
      *(long long *)(v4 + 40) = v49 + 1;
      *(char *)(v50 + v49) = -117;
      v51 = *(long long *)(v4 + 40);
      v52 = *(long long *)(v4 + 16);
      *(long long *)(v4 + 40) = v51 + 1;
      *(char *)(v52 + v51) = 8;
      v53 = *(long long *)(v4 + 56);
      if ( v53 )
      {
        v54 = *(long long *)(v4 + 16);
        v55 = *(long long *)(v4 + 40);
        v56 = 4 * (*(long long *)(v53 + 24) != 0)
            + 2 * (*(int *)(v53 + 68) != 0)
            - ((*(int *)v53 == 0)
             - 1)
            + 8 * (*(long long *)(v53 + 40) != 0)
            + 16 * (*(long long *)(v53 + 56) != 0);
        *(long long *)(v4 + 40) = v55 + 1;
        *(char *)(v54 + v55) = v56;
        v57 = *(long long *)(v4 + 16);
        v58 = *(long long *)(*(long long *)(v4 + 56) + 8LL);
        v59 = *(long long *)(v4 + 40);
        *(long long *)(v4 + 40) = v59 + 1;
        *(char *)(v57 + v59) = v58;
        v60 = *(long long *)(v4 + 16);
        v61 = *(long long *)(*(long long *)(v4 + 56) + 8LL);
        v62 = *(long long *)(v4 + 40);
        *(long long *)(v4 + 40) = v62 + 1;
        *(char *)(v60 + v62) = BYTE1(v61);
        v63 = *(long long *)(v4 + 40);
        v64 = *(long long *)(v4 + 16);
        v65 = *(long long *)(*(long long *)(v4 + 56) + 8LL) >> 16;
        *(long long *)(v4 + 40) = v63 + 1;
        *(char *)(v64 + v63) = v65;
        v66 = *(long long *)(v4 + 40);
        v67 = *(long long *)(v4 + 16);
        v68 = *(long long *)(*(long long *)(v4 + 56) + 8LL) >> 24;
        *(long long *)(v4 + 40) = v66 + 1;
        *(char *)(v67 + v66) = v68;
        v69 = *(int *)(v4 + 196);
        v70 = 2;
        if ( v69 != 9 )
          v70 = 4 * (v69 <= 1 || *(int *)(v4 + 200) > 1);
        v71 = *(long long *)(v4 + 40);
        v72 = *(long long *)(v4 + 16);
        *(long long *)(v4 + 40) = v71 + 1;
        *(char *)(v72 + v71) = v70;
        v73 = *(long long *)(v4 + 16);
        LODWORD(v72) = *(int *)(*(long long *)(v4 + 56) + 20LL);
        v74 = *(long long *)(v4 + 40);
        *(long long *)(v4 + 40) = v74 + 1;
        *(char *)(v73 + v74) = v72;
        v75 = *(long long *)(v4 + 56);
        if ( *(long long *)(v75 + 24) )
        {
          v76 = *(int *)(v75 + 32);
          v77 = *(long long *)(v4 + 40);
          v78 = *(long long *)(v4 + 16);
          *(long long *)(v4 + 40) = v77 + 1;
          *(char *)(v78 + v77) = v76;
          v79 = *(long long *)(v4 + 16);
          v80 = *(int *)(*(long long *)(v4 + 56) + 32LL);
          v81 = *(long long *)(v4 + 40);
          *(long long *)(v4 + 40) = v81 + 1;
          *(char *)(v79 + v81) = BYTE1(v80);
          v75 = *(long long *)(v4 + 56);
        }
        if ( *(int *)(v75 + 68) )
        {
          *(long long *)(a1 + 96) = sub_DD50(*(long long *)(a1 + 96), *(long long *)(v4 + 16), *(unsigned int *)(v4 + 40));
          v75 = *(long long *)(v4 + 56);
        }
        *(long long *)(v4 + 64) = 0;
        *(int *)(v4 + 8) = 69;
        goto LABEL_63;
      }
      v92 = *(long long *)(v4 + 40);
      v93 = *(long long *)(v4 + 16);
      *(long long *)(v4 + 40) = v92 + 1;
      *(char *)(v93 + v92) = 0;
      v94 = *(long long *)(v4 + 40);
      v95 = *(long long *)(v4 + 16);
      *(long long *)(v4 + 40) = v94 + 1;
      *(char *)(v95 + v94) = 0;
      v96 = *(long long *)(v4 + 40);
      v97 = *(long long *)(v4 + 16);
      *(long long *)(v4 + 40) = v96 + 1;
      *(char *)(v97 + v96) = 0;
      v98 = *(long long *)(v4 + 40);
      v99 = *(long long *)(v4 + 16);
      *(long long *)(v4 + 40) = v98 + 1;
      *(char *)(v99 + v98) = 0;
      v100 = *(long long *)(v4 + 40);
      v101 = *(long long *)(v4 + 16);
      *(long long *)(v4 + 40) = v100 + 1;
      *(char *)(v101 + v100) = 0;
      v102 = *(int *)(v4 + 196);
      v103 = 2;
      if ( v102 != 9 )
        v103 = 4 * (v102 <= 1 || *(int *)(v4 + 200) > 1);
      v104 = *(long long *)(v4 + 40);
      v105 = *(long long *)(v4 + 16);
      *(long long *)(v4 + 40) = v104 + 1;
      *(char *)(v105 + v104) = v103;
      v106 = *(long long *)(v4 + 40);
      v107 = *(long long *)(v4 + 16);
      *(long long *)(v4 + 40) = v106 + 1;
      *(char *)(v107 + v106) = 3;
      *(int *)(v4 + 8) = 113;
      sub_5790(a1);
      if ( *(long long *)(v4 + 40) )
        goto LABEL_26;
      v8 = *(int *)(v4 + 8);
    }
    if ( v8 != 69 )
    {
      if ( v8 != 73 )
      {
        if ( v8 != 91 )
        {
          if ( v8 != 103 )
            goto LABEL_36;
          v121 = *(int *)(*(long long *)(v4 + 56) + 68LL);
          goto LABEL_118;
        }
        v75 = *(long long *)(v4 + 56);
LABEL_104:
        if ( *(long long *)(v75 + 56) )
        {
          v116 = *(long long *)(v4 + 40);
          v117 = v116;
          while ( 1 )
          {
            if ( *(long long *)(v4 + 24) == v117 )
            {
              if ( *(int *)(v75 + 68) && v116 < v117 )
                *(long long *)(a1 + 96) = sub_DD50(
                                         *(long long *)(a1 + 96),
                                         *(long long *)(v4 + 16) + v116,
                                         (unsigned int)(v117 - v116));
              sub_5790(a1);
              v117 = *(long long *)(v4 + 40);
              if ( v117 )
                goto LABEL_26;
              v75 = *(long long *)(v4 + 56);
              v116 = 0;
            }
            v118 = *(long long *)(v75 + 56);
            v119 = *(long long *)(v4 + 64);
            *(long long *)(v4 + 64) = v119 + 1;
            LOBYTE(v119) = *(char *)(v118 + v119);
            v120 = *(long long *)(v4 + 16);
            *(long long *)(v4 + 40) = v117 + 1;
            *(char *)(v120 + v117) = v119;
            if ( !(char)v119 )
              break;
            v117 = *(long long *)(v4 + 40);
            v75 = *(long long *)(v4 + 56);
          }
          v121 = *(int *)(*(long long *)(v4 + 56) + 68LL);
          if ( !v121 )
            goto LABEL_122;
          v122 = *(long long *)(v4 + 40);
          if ( v122 <= v116 )
            goto LABEL_117;
          *(long long *)(a1 + 96) = sub_DD50(
                                   *(long long *)(a1 + 96),
                                   *(long long *)(v4 + 16) + v116,
                                   (unsigned int)(v122 - v116));
          v75 = *(long long *)(v4 + 56);
        }
        v121 = *(int *)(v75 + 68);
LABEL_117:
        *(int *)(v4 + 8) = 103;
LABEL_118:
        if ( v121 )
        {
          v123 = *(long long *)(v4 + 40);
          if ( (unsigned long long)(v123 + 2) > *(long long *)(v4 + 24) )
          {
            sub_5790(a1);
            v123 = *(long long *)(v4 + 40);
            if ( v123 )
              goto LABEL_26;
          }
          v124 = *(long long *)(a1 + 96);
          v125 = *(long long *)(v4 + 16);
          *(long long *)(v4 + 40) = v123 + 1;
          *(char *)(v125 + v123) = v124;
          v126 = *(long long *)(v4 + 40);
          v127 = *(long long *)(a1 + 96);
          v128 = *(long long *)(v4 + 16);
          *(long long *)(v4 + 40) = v126 + 1;
          *(char *)(v128 + v126) = BYTE1(v127);
          *(long long *)(a1 + 96) = sub_DD50(0, 0, 0);
        }
LABEL_122:
        *(int *)(v4 + 8) = 113;
        sub_5790(a1);
        if ( *(long long *)(v4 + 40) )
          goto LABEL_26;
LABEL_36:
        if ( *(int *)(a1 + 8) )
          goto LABEL_15;
        goto LABEL_37;
      }
      v75 = *(long long *)(v4 + 56);
LABEL_89:
      if ( *(long long *)(v75 + 40) )
      {
        v110 = *(long long *)(v4 + 40);
        v111 = v110;
        while ( 1 )
        {
          if ( *(long long *)(v4 + 24) == v111 )
          {
            if ( *(int *)(v75 + 68) && v110 < v111 )
              *(long long *)(a1 + 96) = sub_DD50(
                                       *(long long *)(a1 + 96),
                                       *(long long *)(v4 + 16) + v110,
                                       (unsigned int)(v111 - v110));
            sub_5790(a1);
            v111 = *(long long *)(v4 + 40);
            if ( v111 )
              goto LABEL_26;
            v75 = *(long long *)(v4 + 56);
            v110 = 0;
          }
          v112 = *(long long *)(v75 + 40);
          v113 = *(long long *)(v4 + 64);
          *(long long *)(v4 + 64) = v113 + 1;
          LOBYTE(v113) = *(char *)(v112 + v113);
          v114 = *(long long *)(v4 + 16);
          *(long long *)(v4 + 40) = v111 + 1;
          *(char *)(v114 + v111) = v113;
          if ( !(char)v113 )
            break;
          v111 = *(long long *)(v4 + 40);
          v75 = *(long long *)(v4 + 56);
        }
        v75 = *(long long *)(v4 + 56);
        if ( *(int *)(v75 + 68) )
        {
          v115 = *(long long *)(v4 + 40);
          if ( v115 > v110 )
          {
            *(long long *)(a1 + 96) = sub_DD50(
                                     *(long long *)(a1 + 96),
                                     *(long long *)(v4 + 16) + v110,
                                     (unsigned int)(v115 - v110));
            v75 = *(long long *)(v4 + 56);
          }
        }
        *(long long *)(v4 + 64) = 0;
      }
      *(int *)(v4 + 8) = 91;
      goto LABEL_104;
    }
    v75 = *(long long *)(v4 + 56);
LABEL_63:
    v82 = *(long long *)(v75 + 24);
    if ( v82 )
    {
      v83 = *(unsigned short *)(v75 + 32);
      v84 = *(long long *)(v4 + 64);
      v85 = *(long long *)(v4 + 40);
      v86 = *(long long *)(v4 + 24);
      v87 = v83 - v84;
      v88 = v87;
      if ( v87 + v85 > v86 )
      {
        do
        {
          v89 = (unsigned int)(v86 - v85);
          v134 = v86;
          v132 = v85;
          v135 = v85;
          memcpy((void *)(*(long long *)(v4 + 16) + v85), (const void *)(v84 + v82), v89);
          v90 = *(long long *)(v4 + 24);
          v91 = *(int *)(*(long long *)(v4 + 56) + 68LL);
          *(long long *)(v4 + 40) = v90;
          if ( v91 && v90 > v135 )
            *(long long *)(a1 + 96) = sub_DD50(
                                     *(long long *)(a1 + 96),
                                     v135 + *(long long *)(v4 + 16),
                                     (unsigned int)(v90 - v132));
          *(long long *)(v4 + 64) += v89;
          sub_5790(a1);
          v85 = *(long long *)(v4 + 40);
          if ( v85 )
            goto LABEL_26;
          v86 = *(long long *)(v4 + 24);
          v82 = *(long long *)(*(long long *)(v4 + 56) + 24LL);
          v84 = *(long long *)(v4 + 64);
          v87 += v132 - v134;
          v88 = v87;
        }
        while ( v87 > v86 );
      }
      v133 = v85;
      memcpy((void *)(*(long long *)(v4 + 16) + v85), (const void *)(v84 + v82), v88);
      v75 = *(long long *)(v4 + 56);
      v109 = *(long long *)(v4 + 40) + v88;
      *(long long *)(v4 + 40) = v109;
      if ( *(int *)(v75 + 68) && v109 > v133 )
      {
        *(long long *)(a1 + 96) = sub_DD50(*(long long *)(a1 + 96), v133 + *(long long *)(v4 + 16), (unsigned int)(v109 - v133));
        v75 = *(long long *)(v4 + 56);
      }
      *(long long *)(v4 + 64) = 0;
    }
    *(int *)(v4 + 8) = 73;
    goto LABEL_89;
  }
  v11 = *(int *)(a1 + 8);
  *(int *)(v4 + 8) = 113;
  if ( v11 )
    goto LABEL_15;
LABEL_37:
  if ( !*(int *)(v4 + 180) )
  {
    if ( !a2 )
      return v7;
    if ( *(int *)(v4 + 8) == 666 )
      goto LABEL_40;
  }
LABEL_15:
  v12 = *(int *)(v4 + 196);
  if ( (int)v12 )
  {
    v13 = *(int *)(v4 + 200);
    if ( v13 == 2 )
    {
      v14 = sub_62C0(v4, a2);
    }
    else if ( v13 == 3 )
    {
      v14 = sub_64D0(v4, a2);
    }
    else
    {
      v14 = (*((long long (**)(long long, long long, void *, long long))&unk_16B80 + 2 * v12 + 1))(
              v4,
              a2,
              &unk_16B80,
              v2);
    }
  }
  else
  {
    v14 = sub_68B0(v4, a2);
  }
  v15 = v14 & 0xFFFFFFFD;
  if ( (unsigned int)(v14 - 2) > 1 )
  {
    if ( !v15 )
      goto LABEL_25;
    if ( v14 == 1 )
    {
      if ( a2 == 1 )
      {
        sub_CF00(v4);
        goto LABEL_24;
      }
      if ( a2 == 5 )
      {
LABEL_24:
        sub_5790(a1);
        goto LABEL_25;
      }
      sub_CDD0(v4, 0, 0, 0);
      if ( a2 == 3 )
      {
        v130 = *(short **)(v4 + 120);
        v131 = *(int *)(v4 + 132) - 1;
        v130[v131] = 0;
        memset(v130, 0, 2LL * v131);
        if ( !*(int *)(v4 + 180) )
        {
          *(int *)(v4 + 172) = 0;
          *(long long *)(v4 + 152) = 0;
          *(int *)(v4 + 5932) = 0;
        }
        goto LABEL_24;
      }
      sub_5790(a1);
      if ( !*(int *)(a1 + 32) )
        goto LABEL_26;
    }
LABEL_40:
    if ( a2 == 4 )
    {
      v19 = *(int *)(v4 + 48);
      v7 = 1;
      if ( v19 > 0 )
      {
        v20 = *(long long *)(a1 + 96);
        if ( v19 == 2 )
        {
          v21 = *(long long *)(v4 + 40);
          v22 = *(long long *)(v4 + 16);
          *(long long *)(v4 + 40) = v21 + 1;
          *(char *)(v22 + v21) = v20;
          v23 = *(long long *)(v4 + 40);
          v24 = *(long long *)(a1 + 96);
          v25 = *(long long *)(v4 + 16);
          *(long long *)(v4 + 40) = v23 + 1;
          *(char *)(v25 + v23) = BYTE1(v24);
          v26 = *(long long *)(v4 + 40);
          v27 = *(long long *)(v4 + 16);
          v28 = *(long long *)(a1 + 96) >> 16;
          *(long long *)(v4 + 40) = v26 + 1;
          *(char *)(v27 + v26) = v28;
          v29 = *(long long *)(v4 + 40);
          v30 = *(long long *)(v4 + 16);
          v31 = *(long long *)(a1 + 96) >> 24;
          *(long long *)(v4 + 40) = v29 + 1;
          *(char *)(v30 + v29) = v31;
          v32 = *(long long *)(v4 + 40);
          v33 = *(long long *)(a1 + 16);
          v34 = *(long long *)(v4 + 16);
          *(long long *)(v4 + 40) = v32 + 1;
          *(char *)(v34 + v32) = v33;
          v35 = *(long long *)(v4 + 40);
          v36 = *(long long *)(a1 + 16);
          v37 = *(long long *)(v4 + 16);
          *(long long *)(v4 + 40) = v35 + 1;
          *(char *)(v37 + v35) = BYTE1(v36);
          v38 = *(long long *)(v4 + 40);
          v39 = *(long long *)(v4 + 16);
          v40 = *(long long *)(a1 + 16) >> 16;
          *(long long *)(v4 + 40) = v38 + 1;
          *(char *)(v39 + v38) = v40;
          v41 = *(long long *)(v4 + 40);
          v42 = *(long long *)(v4 + 16);
          v43 = *(long long *)(a1 + 16) >> 24;
          *(long long *)(v4 + 40) = v41 + 1;
          *(char *)(v42 + v41) = v43;
        }
        else
        {
          sub_5130(v4, v20 >> 16);
          sub_5130(v4, *(unsigned short *)(a1 + 96));
        }
        sub_5790(a1);
        v44 = *(int *)(v4 + 48);
        if ( v44 > 0 )
          *(int *)(v4 + 48) = -v44;
        return *(long long *)(v4 + 40) == 0;
      }
    }
    return v7;
  }
  *(int *)(v4 + 8) = 666;
  if ( v15 )
    goto LABEL_40;
LABEL_25:
  if ( !*(int *)(a1 + 32) )
LABEL_26:
    *(int *)(v4 + 76) = -1;
  return v7;
}


// Function: deflateParams @ 0x8030
long long deflateParams(long long a1, unsigned int a2, unsigned int a3)
{
  long long v4; // rbp
  long long v5; // rbx
  unsigned int v6; // r15d
  bool v7; // al
  long long v8; // rax
  long long v9; // rbp
  int v10; // eax
  int v12; // eax
  short *v13; // rdi
  unsigned int v14; // eax

  if ( sub_50A0((long long *)a1) )
    return (unsigned int)-2;
  v4 = (int)a2;
  v5 = *(long long *)(a1 + 56);
  v6 = 0;
  if ( a2 == -1 )
  {
    v7 = 0;
    v4 = 6;
  }
  else
  {
    v7 = a2 > 9;
  }
  if ( a3 > 4 || v7 )
    return (unsigned int)-2;
  v8 = *(int *)(v5 + 196);
  if ( (*(int *)(v5 + 200) != a3 || *((long long *)&unk_16B80 + 2 * (int)v4 + 1) != *((long long *)&unk_16B80 + 2 * v8 + 1))
    && *(int *)(v5 + 76) != -2 )
  {
    if ( (unsigned int)sub_7460(a1, 5u) != -2 )
    {
      if ( *(int *)(a1 + 8) || *(unsigned int *)(v5 + 180) + *(unsigned int *)(v5 + 172) - *(long long *)(v5 + 152) )
        return (unsigned int)-5;
      LODWORD(v8) = *(int *)(v5 + 196);
      goto LABEL_8;
    }
    return (unsigned int)-2;
  }
LABEL_8:
  if ( (int)v4 != (int)v8 )
  {
    if ( !(int)v8 )
    {
      v12 = *(int *)(v5 + 5928);
      if ( v12 )
      {
        if ( v12 == 1 )
        {
          sub_5020(v5);
        }
        else
        {
          v13 = *(short **)(v5 + 120);
          v14 = *(int *)(v5 + 132) - 1;
          v13[v14] = 0;
          memset(v13, 0, 2LL * v14);
        }
        *(int *)(v5 + 5928) = 0;
      }
    }
    *(int *)(v5 + 196) = v4;
    v9 = 16 * v4;
    *(int *)(v5 + 192) = *(unsigned short *)((char *)&unk_16B80 + v9 + 2);
    *(int *)(v5 + 204) = *(unsigned short *)((char *)&unk_16B80 + v9);
    v10 = *(unsigned short *)((char *)&unk_16B80 + v9 + 6);
    *(int *)(v5 + 208) = *(unsigned short *)((char *)&unk_16B80 + v9 + 4);
    *(int *)(v5 + 188) = v10;
  }
  *(int *)(v5 + 200) = a3;
  return v6;
}


// Function: deflateEnd @ 0x8200
long long deflateEnd(long long a1)
{
  long long v1; // rsi
  unsigned int v2; // r12d
  int v3; // ebp

  if ( sub_50A0((long long *)a1) )
  {
    return (unsigned int)-2;
  }
  else
  {
    v1 = *(long long *)(a1 + 56);
    v2 = 0;
    v3 = *(int *)(v1 + 8);
    if ( *(long long *)(v1 + 16) )
    {
      (*(void (**)(long long, long long))(a1 + 72))(*(long long *)(a1 + 80), *(long long *)(v1 + 16));
      v1 = *(long long *)(a1 + 56);
    }
    if ( *(long long *)(v1 + 120) )
    {
      (*(void (**)(long long, long long))(a1 + 72))(*(long long *)(a1 + 80), *(long long *)(v1 + 120));
      v1 = *(long long *)(a1 + 56);
    }
    if ( *(long long *)(v1 + 112) )
    {
      (*(void (**)(long long, long long))(a1 + 72))(*(long long *)(a1 + 80), *(long long *)(v1 + 112));
      v1 = *(long long *)(a1 + 56);
    }
    if ( *(long long *)(v1 + 96) )
    {
      (*(void (**)(long long, long long))(a1 + 72))(*(long long *)(a1 + 80), *(long long *)(v1 + 96));
      v1 = *(long long *)(a1 + 56);
    }
    (*(void (**)(long long, long long))(a1 + 72))(*(long long *)(a1 + 80), v1);
    *(long long *)(a1 + 56) = 0;
    if ( v3 == 113 )
      return (unsigned int)-3;
  }
  return v2;
}


// Function: deflateInit2_ @ 0x82b0
long long deflateInit2_(long long *a1, unsigned int a2, int a3, int a4, int a5, unsigned int a6, char *a7, int a8)
{
  bool v10; // zf
  unsigned int v11; // r14d
  int v14; // ecx
  long long v15; // rdi
  long long v16; // rax
  long long v17; // rbx
  long long v18; // rdi
  long long v19; // rsi
  int v20; // eax
  long long v21; // rax
  long long v22; // rsi
  long long v23; // rdi
  long long v24; // rax
  long long v25; // rsi
  long long v26; // rdi
  long long v27; // rax
  long long v28; // rdi
  long long v29; // rsi
  long long v30; // rax
  long long v31; // rcx
  int v33; // [rsp+Ch] [rbp-3Ch]

  if ( !a7 || *a7 != 49 || a8 != 112 )
    return 4294967290LL;
  if ( !a1 )
    return 4294967294LL;
  v10 = a1[8] == 0;
  v11 = a2;
  a1[6] = 0;
  if ( v10 )
  {
    a1[10] = 0;
    a1[8] = sub_D360;
  }
  if ( !a1[9] )
    a1[9] = &sub_D370;
  if ( a2 == -1 )
    v11 = 6;
  v14 = 1;
  if ( a4 > 15 )
  {
    a4 -= 16;
    v14 = 2;
  }
  if ( (unsigned int)(a5 - 1) > 8 || (unsigned int)(a4 - 8) > 7 || a3 != 8 || v11 > 9 || a6 > 4 || a4 == 8 && v14 != 1 )
    return 4294967294LL;
  v33 = v14;
  v15 = a1[10];
  if ( a4 == 8 )
    a4 = 9;
  v16 = ((long long (*)(long long, long long, long long))a1[8])(v15, 1, 5952);
  v17 = v16;
  if ( !v16 )
    return 4294967292LL;
  a1[7] = v16;
  *(long long *)v16 = a1;
  v18 = a1[10];
  *(int *)(v16 + 48) = v33;
  v19 = (unsigned int)(1 << a4);
  *(int *)(v16 + 8) = 42;
  *(int *)(v16 + 80) = v19;
  *(long long *)(v16 + 56) = 0;
  *(int *)(v16 + 84) = a4;
  *(int *)(v16 + 88) = v19 - 1;
  v20 = 1 << (a5 + 7);
  *(int *)(v17 + 136) = a5 + 7;
  *(int *)(v17 + 132) = v20;
  *(int *)(v17 + 140) = v20 - 1;
  *(int *)(v17 + 144) = (a5 + 9) / 3u;
  v21 = ((long long (*)(long long, long long, long long))a1[8])(v18, v19, 2);
  v22 = *(unsigned int *)(v17 + 80);
  v23 = a1[10];
  *(long long *)(v17 + 96) = v21;
  v24 = ((long long (*)(long long, long long, long long))a1[8])(v23, v22, 2);
  v25 = *(unsigned int *)(v17 + 132);
  v26 = a1[10];
  *(long long *)(v17 + 112) = v24;
  v27 = ((long long (*)(long long, long long, long long))a1[8])(v26, v25, 2);
  v28 = a1[10];
  v29 = (unsigned int)(1 << (a5 + 6));
  *(long long *)(v17 + 120) = v27;
  *(int *)(v17 + 5896) = v29;
  *(long long *)(v17 + 5944) = 0;
  v30 = ((long long (*)(long long, long long, long long))a1[8])(v28, v29, 4);
  v31 = *(unsigned int *)(v17 + 5896);
  v10 = *(long long *)(v17 + 96) == 0;
  *(long long *)(v17 + 16) = v30;
  *(long long *)(v17 + 24) = 4 * v31;
  if ( !v10 && *(long long *)(v17 + 112) && *(long long *)(v17 + 120) && v30 )
  {
    *(int *)(v17 + 196) = v11;
    *(long long *)(v17 + 5888) = v31 + v30;
    *(int *)(v17 + 5904) = 3 * v31 - 3;
    *(int *)(v17 + 200) = a6;
    *(char *)(v17 + 72) = 8;
    return sub_7150((long long)a1);
  }
  else
  {
    *(int *)(v17 + 8) = 666;
    a1[6] = "insufficient memory";
    sub_8200((long long)a1);
    return 4294967292LL;
  }
}


// Function: deflateInit_ @ 0x85a0
long long deflateInit_(long long *a1, unsigned int a2, char *a3, int a4)
{
  return sub_82B0(a1, a2, 8, 15, 8, 0, a3, a4);
}


// Function: deflateCopy @ 0x85d0
long long deflateCopy(__m128i *a1, __m128i *a2)
{
  int v3; // eax
  long long v4; // r12
  long long v5; // rdi
  long long v6; // rax
  long long v7; // rbx
  long long v8; // rax
  long long v9; // rsi
  long long v10; // rdi
  long long v11; // rax
  long long v12; // rsi
  long long v13; // rdi
  long long v14; // rax
  long long v15; // rdi
  long long v16; // rsi
  long long v17; // rax
  void *v18; // rdi
  long long v19; // rax

  v3 = sub_50A0(a2);
  if ( !a1 || v3 )
    return 4294967294LL;
  v4 = a2[3].m128i_i64[1];
  *a1 = _mm_loadu_si128(a2);
  a1[1] = _mm_loadu_si128(a2 + 1);
  a1[2] = _mm_loadu_si128(a2 + 2);
  a1[3] = _mm_loadu_si128(a2 + 3);
  a1[4] = _mm_loadu_si128(a2 + 4);
  a1[5] = _mm_loadu_si128(a2 + 5);
  v5 = a1[5].m128i_i64[0];
  a1[6] = _mm_loadu_si128(a2 + 6);
  v6 = ((long long (*)(long long, long long, long long))a1[4].m128i_i64[0])(v5, 1, 5952);
  v7 = v6;
  if ( !v6 )
    return 4294967292LL;
  a1[3].m128i_i64[1] = v6;
  *(long long *)v6 = *(long long *)v4;
  *(long long *)(v6 + 5944) = *(long long *)(v4 + 5944);
  qmemcpy(
    (void *)((v6 + 8) & 0xFFFFFFFFFFFFFFF8LL),
    (const void *)(v4 - (v6 - ((v6 + 8) & 0xFFFFFFFFFFFFFFF8LL))),
    8LL * (((unsigned int)v6 - (((int)v6 + 8) & 0xFFFFFFF8) + 5952) >> 3));
  *(long long *)v6 = a1;
  v8 = ((long long (*)(long long, long long, long long))a1[4].m128i_i64[0])(
         a1[5].m128i_i64[0],
         *(unsigned int *)(v6 + 80),
         2);
  v9 = *(unsigned int *)(v7 + 80);
  v10 = a1[5].m128i_i64[0];
  *(long long *)(v7 + 96) = v8;
  v11 = ((long long (*)(long long, long long, long long))a1[4].m128i_i64[0])(v10, v9, 2);
  v12 = *(unsigned int *)(v7 + 132);
  v13 = a1[5].m128i_i64[0];
  *(long long *)(v7 + 112) = v11;
  v14 = ((long long (*)(long long, long long, long long))a1[4].m128i_i64[0])(v13, v12, 2);
  v15 = a1[5].m128i_i64[0];
  v16 = *(unsigned int *)(v7 + 5896);
  *(long long *)(v7 + 120) = v14;
  v17 = ((long long (*)(long long, long long, long long))a1[4].m128i_i64[0])(v15, v16, 4);
  v18 = *(void **)(v7 + 96);
  *(long long *)(v7 + 16) = v17;
  if ( v18 && *(long long *)(v7 + 112) && *(long long *)(v7 + 120) && v17 )
  {
    memcpy(v18, *(const void **)(v4 + 96), (unsigned int)(2 * *(int *)(v7 + 80)));
    memcpy(*(void **)(v7 + 112), *(const void **)(v4 + 112), 2LL * *(unsigned int *)(v7 + 80));
    memcpy(*(void **)(v7 + 120), *(const void **)(v4 + 120), 2LL * *(unsigned int *)(v7 + 132));
    memcpy(*(void **)(v7 + 16), *(const void **)(v4 + 16), *(unsigned int *)(v7 + 24));
    v19 = *(long long *)(v7 + 16);
    *(long long *)(v7 + 32) = v19 + *(long long *)(v4 + 32) - *(long long *)(v4 + 16);
    *(long long *)(v7 + 5888) = *(unsigned int *)(v7 + 5896) + v19;
    *(long long *)(v7 + 2904) = v7 + 212;
    *(long long *)(v7 + 2928) = v7 + 2504;
    *(long long *)(v7 + 2952) = v7 + 2748;
    return 0;
  }
  else
  {
    sub_8200((long long)a1);
    return 4294967292LL;
  }
}


// Function: inflateStateCheck @ 0x87d0
long long inflateStateCheck(long long *a1)
{
  long long v1; // rdx
  long long result; // rax

  if ( !a1 || !a1[8] || !a1[9] )
    return 1;
  v1 = a1[7];
  result = 1;
  if ( v1 )
  {
    if ( *(long long **)v1 == a1 )
      return (unsigned int)(*(int *)(v1 + 8) - 16180) > 0x1F;
  }
  return result;
}


// Function: fixedtables @ 0x8820
long long fixedtables(long long *a1)
{
  a1[13] = &unk_F680;
  a1[14] = &unk_F600;
  a1[15] = 0x500000009LL;
  return 0x500000009LL;
}


// Function: syncsearch @ 0x8850
long long syncsearch(unsigned int *a1, long long a2, unsigned int a3)
{
  unsigned int v4; // edi
  bool v5; // r9
  long long result; // rax
  bool v7; // cl
  char v8; // r8

  v4 = *a1;
  v5 = v4 <= 3 && a3 != 0;
  result = 0;
  if ( v5 )
  {
    do
    {
      v8 = *(char *)(a2 + (unsigned int)result);
      if ( v8 == -(v4 >= 2) )
      {
        v7 = ++v4 <= 3;
        result = (unsigned int)(result + 1);
        if ( a3 <= (unsigned int)result )
          break;
      }
      else
      {
        if ( v8 )
        {
          v7 = v5;
          v4 = 0;
        }
        else
        {
          v4 = 4 - v4;
          v7 = v4 <= 3;
        }
        result = (unsigned int)(result + 1);
        if ( a3 <= (unsigned int)result )
          break;
      }
    }
    while ( v7 );
  }
  *a1 = v4;
  return result;
}


// Function: updatewindow @ 0x88d0
long long updatewindow(long long a1, long long a2, unsigned int a3)
{
  long long v5; // rbp
  char *v6; // rdi
  size_t v7; // rdx
  int v8; // ecx
  int v9; // eax
  long long result; // rax
  unsigned int v11; // ebx
  unsigned int v12; // r12d
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // eax
  long long v16; // rax
  int v17; // eax

  v5 = *(long long *)(a1 + 56);
  v6 = *(char **)(v5 + 72);
  if ( !v6 )
  {
    v16 = (*(long long (**)(long long, long long, long long))(a1 + 64))(
            *(long long *)(a1 + 80),
            (unsigned int)(1 << *(int *)(v5 + 56)),
            1);
    *(long long *)(v5 + 72) = v16;
    v6 = (char *)v16;
    if ( !v16 )
      return 1;
  }
  v7 = *(unsigned int *)(v5 + 60);
  if ( !(int)v7 )
  {
    v8 = *(int *)(v5 + 56);
    *(long long *)(v5 + 64) = 0;
    v7 = (unsigned int)(1 << v8);
    *(int *)(v5 + 60) = v7;
  }
  if ( a3 < (unsigned int)v7 )
  {
    v11 = v7 - *(int *)(v5 + 68);
    if ( v11 > a3 )
      v11 = a3;
    memcpy(&v6[*(unsigned int *)(v5 + 68)], (const void *)(a2 - a3), v11);
    v12 = a3 - v11;
    if ( v12 )
    {
      memcpy(*(void **)(v5 + 72), (const void *)(a2 - v12), v12);
      v17 = *(int *)(v5 + 60);
      *(int *)(v5 + 68) = v12;
      *(int *)(v5 + 64) = v17;
      return 0;
    }
    else
    {
      v13 = *(int *)(v5 + 60);
      v14 = *(int *)(v5 + 64);
      v15 = v11 + *(int *)(v5 + 68);
      if ( v15 == v13 )
        v15 = 0;
      *(int *)(v5 + 68) = v15;
      result = 0;
      if ( v13 > v14 )
        *(int *)(v5 + 64) = v11 + v14;
    }
  }
  else
  {
    memcpy(v6, (const void *)(a2 - v7), v7);
    v9 = *(int *)(v5 + 60);
    *(int *)(v5 + 68) = 0;
    *(int *)(v5 + 64) = v9;
    return 0;
  }
  return result;
}


// Function: inflateReset @ 0x8ab0
long long inflateReset(long long *a1)
{
  long long result; // rax
  long long v2; // rdx
  int v3; // ecx
  long long v4; // rax

  if ( sub_87D0(a1) )
    return 4294967294LL;
  v4 = a1[7];
  *(int *)(v4 + 60) = 0;
  *(long long *)(v4 + 64) = 0;
  result = sub_87D0(a1);
  if ( (int)result )
    return 4294967294LL;
  v2 = a1[7];
  v3 = *(int *)(v2 + 16);
  *(long long *)(v2 + 40) = 0;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  if ( v3 )
    a1[12] = v3 & 1;
  *(long long *)(v2 + 8) = 16180;
  *(long long *)(v2 + 24) = 0x8000FFFFFFFFLL;
  *(int *)(v2 + 20) = 0;
  *(long long *)(v2 + 48) = 0;
  *(long long *)(v2 + 80) = 0;
  *(int *)(v2 + 88) = 0;
  *(long long *)(v2 + 144) = v2 + 1368;
  *(long long *)(v2 + 112) = v2 + 1368;
  *(long long *)(v2 + 104) = v2 + 1368;
  *(long long *)(v2 + 7144) = 0xFFFFFFFF00000001LL;
  return result;
}


// Function: inflateReset2 @ 0x8ae0
long long inflateReset2(long long a1, int a2)
{
  long long v2; // r13
  int v3; // ebx
  int v4; // r12d

  if ( sub_87D0((long long *)a1) )
    return 4294967294LL;
  v2 = *(long long *)(a1 + 56);
  v3 = a2;
  if ( a2 < 0 )
  {
    if ( a2 < -15 )
      return 4294967294LL;
    v4 = 0;
    v3 = -a2;
  }
  else
  {
    v4 = (a2 >> 4) + 5;
    if ( a2 < 48 )
      v3 = a2 & 0xF;
  }
  if ( (unsigned int)(v3 - 8) > 7 && v3 )
    return 4294967294LL;
  if ( *(long long *)(v2 + 72) )
  {
    if ( v3 != *(int *)(v2 + 56) )
    {
      (*(void (**)(long long))(a1 + 72))(*(long long *)(a1 + 80));
      *(long long *)(v2 + 72) = 0;
    }
  }
  *(int *)(v2 + 16) = v4;
  *(int *)(v2 + 56) = v3;
  return sub_8AB0((long long *)a1);
}


// Function: inflateInit2_ @ 0x8b80
long long inflateInit2_(long long *a1, int a2, char *a3, int a4)
{
  long long (*v5)(); // rax
  long long v6; // rdi
  long long v7; // rax
  long long v8; // rbp
  unsigned int v9; // r12d

  if ( a3 && *a3 == 49 && a4 == 112 )
  {
    if ( a1 )
    {
      v5 = (long long (*)())a1[8];
      a1[6] = 0;
      if ( v5 )
      {
        v6 = a1[10];
      }
      else
      {
        v5 = sub_D360;
        a1[10] = 0;
        a1[8] = sub_D360;
        v6 = 0;
      }
      if ( !a1[9] )
        a1[9] = &sub_D370;
      v7 = ((long long (*)(long long, long long, long long))v5)(v6, 1, 7160);
      v8 = v7;
      if ( v7 )
      {
        a1[7] = v7;
        *(long long *)v7 = a1;
        *(long long *)(v7 + 72) = 0;
        *(int *)(v7 + 8) = 16180;
        v9 = sub_8AE0((long long)a1, a2);
        if ( v9 )
        {
          ((void (*)(long long, long long))a1[9])(a1[10], v8);
          a1[7] = 0;
        }
      }
      else
      {
        return (unsigned int)-4;
      }
    }
    else
    {
      return (unsigned int)-2;
    }
  }
  else
  {
    return (unsigned int)-6;
  }
  return v9;
}


// Function: inflate @ 0x8d00
long long inflate(long long a1, int a2)
{
  char *v2; // r11
  unsigned char *v4; // r12
  long long v5; // r13
  int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // ebp
  unsigned long long v9; // r14
  unsigned int v10; // ecx
  long long v11; // rax
  long long v12; // rax
  long long v13; // rax
  unsigned long long v14; // rdx
  unsigned long long v15; // rax
  long long v16; // rax
  char v17; // cl
  unsigned long long v18; // r10
  int v19; // edx
  unsigned int v20; // ecx
  long long v21; // rax
  long long v22; // rax
  unsigned int v23; // r8d
  long long v24; // rax
  int v25; // ecx
  unsigned long long v26; // rax
  unsigned char *v27; // rdx
  char v28; // cl
  unsigned char *v29; // rdx
  long long v30; // rax
  char v31; // cl
  long long v32; // rax
  long long v33; // rax
  unsigned int v34; // esi
  long long v35; // rax
  int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // r14d
  int v39; // r9d
  unsigned int v40; // eax
  int v41; // ecx
  int v42; // edx
  int v43; // eax
  unsigned int v45; // edx
  int v46; // eax
  long long v47; // rdi
  int v48; // r10d
  char *v49; // rax
  unsigned char v50; // dl
  char v51; // si
  int v52; // r8d
  int v53; // eax
  int v54; // r9d
  long long v55; // rax
  long long v56; // rax
  char *v57; // rax
  int v58; // r10d
  int v59; // r10d
  int v60; // eax
  long long v61; // rdx
  long long v62; // rax
  long long v63; // rdx
  long long v64; // rdx
  long long v65; // rdx
  unsigned int v66; // eax
  char *v67; // r11
  long long v68; // rsi
  unsigned int v69; // edi
  unsigned char *v70; // rdx
  unsigned long long v71; // rax
  unsigned int v72; // eax
  long long v73; // rsi
  short v74; // r8
  long long v75; // r8
  unsigned int v76; // r9d
  long long v77; // rsi
  int v78; // edx
  long long v79; // rax
  unsigned char v80; // cl
  unsigned short v81; // di
  int v82; // eax
  long long v83; // rax
  long long v84; // rax
  long long v85; // rax
  unsigned char v86; // r10
  long long v87; // rdi
  long long v88; // rdi
  unsigned long long v89; // r14
  char v90; // cl
  short v91; // di
  int v92; // ecx
  unsigned int v93; // eax
  long long v94; // rcx
  long long v95; // rax
  long long v96; // rax
  int v97; // edx
  long long v98; // rax
  long long v99; // rax
  long long v100; // rax
  long long v101; // rax
  long long v102; // rax
  long long v103; // rax
  int v104; // edx
  long long v105; // rdi
  long long v106; // rax
  long long v107; // rax
  unsigned int v108; // edx
  unsigned int v109; // ecx
  long long v110; // r8
  long long v111; // r10
  long long v112; // rsi
  int v113; // r9d
  unsigned int v114; // r8d
  long long v115; // rdi
  size_t v116; // rax
  long long v117; // rdx
  long long v118; // rax
  long long v119; // rax
  long long v120; // rax
  long long v121; // rax
  unsigned int v122; // eax
  int v123; // edi
  unsigned int v124; // edx
  long long v125; // rdi
  long long v126; // rsi
  long long v127; // rax
  unsigned char *v128; // rsi
  long long v129; // rdx
  long long v130; // rax
  unsigned char v131; // cl
  long long v132; // r8
  long long v133; // rdi
  long long v134; // rax
  int v135; // ecx
  long long v136; // rdi
  int v137; // r8d
  char *v138; // rax
  unsigned char v139; // cl
  char v140; // dl
  int v141; // esi
  int v142; // eax
  long long v143; // rax
  long long v144; // rax
  char *v145; // rax
  unsigned char v146; // r9
  unsigned char *v147; // rsi
  long long v148; // rdx
  long long v149; // rax
  unsigned char v150; // cl
  long long v151; // r8
  long long v152; // rdi
  long long v153; // rax
  unsigned int v154; // esi
  char *v155; // rcx
  unsigned int v156; // edx
  unsigned int v157; // edx
  unsigned int v158; // edi
  long long v159; // rsi
  long long v160; // rax
  long long v161; // rdx
  long long v162; // rax
  long long v163; // rax
  char *v164; // rax
  long long v165; // rax
  char v166; // cl
  char *v167; // rax
  char v168; // cl
  char v169; // cl
  long long v170; // rax
  long long v171; // rax
  long long v172; // rax
  long long v173; // rax
  long long v174; // rax
  int v175; // eax
  long long v176; // rax
  long long v177; // rax
  long long v178; // rax
  unsigned long long v179; // r14
  unsigned int v180; // eax
  unsigned int v181; // ecx
  long long v182; // rdi
  long long v183; // rdi
  unsigned long long v184; // r14
  char v185; // cl
  unsigned short *v186; // rax
  long long v187; // rdx
  int v188; // eax
  long long v189; // rax
  long long v190; // rdi
  long long v191; // rax
  long long v192; // rdi
  long long v193; // rdi
  char v194; // cl
  char *v195; // rsi
  long long v196; // rdi
  long long v197; // rax
  char *v198; // rcx
  int v199; // r8d
  int v200; // r10d
  int v201; // r9d
  long long v202; // rdx
  char v203; // cl
  char *v204; // rcx
  int v205; // ecx
  int *v206; // rcx
  long long v207; // rdi
  long long v208; // rax
  long long v209; // rax
  long long v210; // rax
  int v211; // eax
  long long v212; // rax
  long long v213; // rdi
  long long v214; // rax
  long long v215; // rax
  long long v216; // rdx
  int v217; // eax
  unsigned int n; // [rsp+8h] [rbp-80h]
  unsigned int n_4; // [rsp+Ch] [rbp-7Ch]
  unsigned int v220; // [rsp+10h] [rbp-78h]
  char *v221; // [rsp+10h] [rbp-78h]
  unsigned int v222; // [rsp+18h] [rbp-70h]
  char *v224; // [rsp+20h] [rbp-68h]
  char *v225; // [rsp+20h] [rbp-68h]
  long long v226; // [rsp+20h] [rbp-68h]
  unsigned int v227; // [rsp+20h] [rbp-68h]
  char *v228; // [rsp+20h] [rbp-68h]
  unsigned int v229; // [rsp+20h] [rbp-68h]
  unsigned int v230; // [rsp+20h] [rbp-68h]
  unsigned int v231; // [rsp+20h] [rbp-68h]
  int v232; // [rsp+20h] [rbp-68h]
  char *v233; // [rsp+20h] [rbp-68h]
  unsigned int v234; // [rsp+20h] [rbp-68h]
  char *v235; // [rsp+20h] [rbp-68h]
  unsigned long long v236; // [rsp+20h] [rbp-68h]
  int v237; // [rsp+20h] [rbp-68h]
  char *v238; // [rsp+20h] [rbp-68h]
  char *v239; // [rsp+20h] [rbp-68h]
  char *v240; // [rsp+20h] [rbp-68h]
  char *v241; // [rsp+20h] [rbp-68h]
  unsigned int v242; // [rsp+28h] [rbp-60h]
  long long v243; // [rsp+28h] [rbp-60h]
  unsigned char v244; // [rsp+28h] [rbp-60h]
  unsigned char v245; // [rsp+28h] [rbp-60h]
  int v246; // [rsp+28h] [rbp-60h]
  long long v247; // [rsp+28h] [rbp-60h]
  char *v248; // [rsp+30h] [rbp-58h]
  char *v249; // [rsp+30h] [rbp-58h]
  char *v250; // [rsp+30h] [rbp-58h]
  char *v251; // [rsp+30h] [rbp-58h]
  char *v252; // [rsp+38h] [rbp-50h]
  int v253; // [rsp+44h] [rbp-44h] BYREF
  unsigned long long v254; // [rsp+48h] [rbp-40h]

  v254 = __readfsqword(0x28u);
  v222 = sub_87D0((long long *)a1);
  if ( v222 )
    return (unsigned int)-2;
  v2 = *(char **)(a1 + 24);
  if ( !v2 )
    return (unsigned int)-2;
  v4 = *(unsigned char **)a1;
  n_4 = *(int *)(a1 + 8);
  if ( !*(long long *)a1 )
  {
    if ( *(int *)(a1 + 8) )
      return (unsigned int)-2;
  }
  v5 = *(long long *)(a1 + 56);
  v6 = *(int *)(v5 + 8);
  if ( v6 == 16191 )
  {
    *(int *)(v5 + 8) = 16192;
    v6 = 16192;
  }
  v7 = *(int *)(v5 + 88);
  v8 = n_4;
  v220 = *(int *)(a1 + 32);
  v9 = *(long long *)(v5 + 80);
  n = v220;
LABEL_7:
  while ( 2 )
  {
    switch ( v6 )
    {
      case 16180:
        v97 = *(int *)(v5 + 16);
        if ( !v97 )
        {
          *(int *)(v5 + 8) = 16192;
          goto LABEL_17;
        }
        if ( v7 > 0xF )
          goto LABEL_347;
        if ( !v8 )
          goto LABEL_240;
        v10 = v7;
        break;
      case 16181:
        if ( v7 <= 0xF )
          goto LABEL_219;
        goto LABEL_224;
      case 16182:
        if ( v7 <= 0x1F )
          goto LABEL_170;
        goto LABEL_174;
      case 16183:
        if ( v7 <= 0xF )
          goto LABEL_181;
        goto LABEL_185;
      case 16184:
        v104 = *(int *)(v5 + 24);
        if ( (v104 & 0x400) == 0 )
          goto LABEL_193;
        if ( v7 > 0xF )
          goto LABEL_326;
        goto LABEL_322;
      case 16185:
        v104 = *(int *)(v5 + 24);
        goto LABEL_196;
      case 16186:
        v60 = *(int *)(v5 + 24);
        goto LABEL_213;
      case 16187:
        v60 = *(int *)(v5 + 24);
        goto LABEL_101;
      case 16188:
        v60 = *(int *)(v5 + 24);
        if ( (v60 & 0x200) == 0 )
          goto LABEL_97;
        goto LABEL_105;
      case 16189:
        if ( v7 <= 0x1F )
          goto LABEL_9;
        goto LABEL_13;
      case 16190:
        goto LABEL_14;
      case 16191:
        goto LABEL_16;
      case 16192:
        goto LABEL_17;
      case 16193:
        goto LABEL_49;
      case 16194:
        v66 = *(int *)(v5 + 92);
        goto LABEL_115;
      case 16195:
        v66 = *(int *)(v5 + 92);
        goto LABEL_116;
      case 16196:
        goto LABEL_227;
      case 16197:
        v68 = *(unsigned int *)(v5 + 140);
        v69 = *(int *)(v5 + 128);
        v10 = v7;
        if ( v69 > (unsigned int)v68 )
          goto LABEL_126;
        goto LABEL_372;
      case 16198:
        v75 = *(unsigned int *)(v5 + 140);
        goto LABEL_133;
      case 16199:
        goto LABEL_37;
      case 16200:
        goto LABEL_38;
      case 16201:
        v45 = *(int *)(v5 + 100);
        goto LABEL_83;
      case 16202:
        goto LABEL_86;
      case 16203:
        v34 = *(int *)(v5 + 100);
        goto LABEL_58;
      case 16204:
        goto LABEL_60;
      case 16205:
        goto LABEL_238;
      case 16206:
        v18 = v9;
        goto LABEL_19;
      case 16207:
        v19 = *(int *)(v5 + 16);
        v18 = v9;
        goto LABEL_156;
      case 16208:
        v18 = v9;
        v222 = 1;
        v38 = v220 - n;
        goto LABEL_66;
      case 16209:
        goto LABEL_430;
      case 16210:
        return (unsigned int)-4;
      default:
        return (unsigned int)-2;
    }
    while ( 1 )
    {
      v176 = *v4++;
      --v8;
      v177 = v176 << v10;
      v10 += 8;
      v9 += v177;
      if ( v10 > 0xF )
        break;
      if ( !v8 )
        goto LABEL_241;
    }
    v7 = v10;
LABEL_347:
    if ( (v97 & 2) == 0 || v9 != 35615 )
    {
      v178 = *(long long *)(v5 + 48);
      if ( v178 )
        *(int *)(v178 + 72) = -1;
      if ( (v97 & 1) == 0
        || (v9 >> 8) + (unsigned short)((short)v9 << 8) != 31
                                                           * (((v9 >> 8) + (unsigned short)((short)v9 << 8))
                                                            / 0x1F) )
      {
        v18 = v9;
        *(long long *)(a1 + 48) = "incorrect header check";
        *(int *)(v5 + 8) = 16209;
        goto LABEL_65;
      }
      if ( (v9 & 0xF) == 8 )
      {
        v179 = v9 >> 4;
        v180 = *(int *)(v5 + 56);
        v7 -= 4;
        v181 = (v179 & 0xF) + 8;
        if ( v180 )
        {
          if ( v181 > 0xF || v180 < v181 )
            goto LABEL_356;
        }
        else
        {
          *(int *)(v5 + 56) = v181;
          if ( v181 > 0xF )
          {
LABEL_356:
            v18 = v179;
            *(long long *)(a1 + 48) = "invalid window size";
            *(int *)(v5 + 8) = 16209;
            goto LABEL_65;
          }
        }
        *(int *)(v5 + 24) = 0;
        *(int *)(v5 + 28) = 1 << ((v179 & 0xF) + 8);
        v240 = v2;
        v212 = sub_D8E0(0, 0, 0);
        v9 = v179 & 0x200;
        v2 = v240;
        *(long long *)(v5 + 32) = v212;
        *(long long *)(a1 + 96) = v212;
        if ( !(int)v9 )
        {
          *(int *)(v5 + 8) = 16191;
          v7 = 0;
          goto LABEL_16;
        }
        *(int *)(v5 + 8) = 16189;
        v9 = 0;
        v7 = 0;
LABEL_9:
        if ( !v8 )
          goto LABEL_240;
        v10 = v7;
        do
        {
          v11 = *v4++;
          --v8;
          v12 = v11 << v10;
          v10 += 8;
          v9 += v12;
          if ( v10 > 0x1F )
          {
LABEL_13:
            v7 = 0;
            v13 = (v9 >> 8) & 0xFF00 | BYTE3(v9);
            v14 = (unsigned int)((int)v9 << 24) + (unsigned long long)(((int)v9 << 8) & 0xFF0000);
            v9 = 0;
            v15 = v14 + v13;
            *(long long *)(v5 + 32) = v15;
            *(long long *)(a1 + 96) = v15;
            *(int *)(v5 + 8) = 16190;
LABEL_14:
            if ( !*(int *)(v5 + 20) )
            {
              *(long long *)(a1 + 24) = v2;
              *(long long *)a1 = v4;
              *(int *)(a1 + 32) = n;
              *(int *)(a1 + 8) = v8;
              v222 = 2;
              *(long long *)(v5 + 80) = v9;
              *(int *)(v5 + 88) = v7;
              return v222;
            }
            v224 = v2;
            v16 = sub_D8E0(0, 0, 0);
            v2 = v224;
            *(long long *)(v5 + 32) = v16;
            *(long long *)(a1 + 96) = v16;
            *(int *)(v5 + 8) = 16191;
            goto LABEL_16;
          }
        }
        while ( v8 );
        goto LABEL_241;
      }
LABEL_225:
      v18 = v9;
      *(long long *)(a1 + 48) = "unknown compression method";
      *(int *)(v5 + 8) = 16209;
      goto LABEL_65;
    }
    if ( !*(int *)(v5 + 56) )
      *(int *)(v5 + 56) = 15;
    v239 = v2;
    v209 = sub_DD50(0, 0, 0);
    v7 = 0;
    v9 = 0;
    *(long long *)(v5 + 32) = v209;
    LOWORD(v253) = -29921;
    v210 = sub_DD50(v209, &v253, 2);
    *(int *)(v5 + 8) = 16181;
    v2 = v239;
    *(long long *)(v5 + 32) = v210;
LABEL_219:
    if ( !v8 )
      goto LABEL_240;
    v10 = v7;
    while ( 1 )
    {
      v118 = *v4++;
      --v8;
      v119 = v118 << v10;
      v10 += 8;
      v9 += v119;
      if ( v10 > 0xF )
        break;
      if ( !v8 )
        goto LABEL_241;
    }
    v7 = v10;
LABEL_224:
    *(int *)(v5 + 24) = v9;
    if ( (char)v9 != 8 )
      goto LABEL_225;
    if ( (v9 & 0xE000) != 0 )
    {
      v18 = v9;
      *(long long *)(a1 + 48) = "unknown header flags set";
      *(int *)(v5 + 8) = 16209;
      goto LABEL_65;
    }
    v206 = *(int **)(v5 + 48);
    if ( v206 )
      *v206 = (v9 >> 8) & 1;
    if ( (v9 & 0x200) != 0 && (*(char *)(v5 + 16) & 4) != 0 )
    {
      v213 = *(long long *)(v5 + 32);
      v241 = v2;
      LOWORD(v253) = v9;
      v214 = sub_DD50(v213, &v253, 2);
      v2 = v241;
      *(long long *)(v5 + 32) = v214;
    }
    *(int *)(v5 + 8) = 16182;
    v7 = 0;
    v9 = 0;
LABEL_170:
    if ( !v8 )
      goto LABEL_240;
    v10 = v7;
    while ( 1 )
    {
      v98 = *v4++;
      --v8;
      v99 = v98 << v10;
      v10 += 8;
      v9 += v99;
      if ( v10 > 0x1F )
        break;
      if ( !v8 )
        goto LABEL_241;
    }
LABEL_174:
    v100 = *(long long *)(v5 + 48);
    if ( v100 )
      *(long long *)(v100 + 8) = v9;
    if ( (*(char *)(v5 + 25) & 2) != 0 && (*(char *)(v5 + 16) & 4) != 0 )
    {
      v190 = *(long long *)(v5 + 32);
      v235 = v2;
      v253 = v9;
      v191 = sub_DD50(v190, &v253, 4);
      v2 = v235;
      *(long long *)(v5 + 32) = v191;
    }
    *(int *)(v5 + 8) = 16183;
    v9 = 0;
    v7 = 0;
LABEL_181:
    if ( !v8 )
      goto LABEL_240;
    v10 = v7;
    while ( 1 )
    {
      v101 = *v4++;
      --v8;
      v102 = v101 << v10;
      v10 += 8;
      v9 += v102;
      if ( v10 > 0xF )
        break;
      if ( !v8 )
        goto LABEL_241;
    }
LABEL_185:
    v103 = *(long long *)(v5 + 48);
    if ( v103 )
    {
      *(int *)(v103 + 16) = (unsigned char)v9;
      *(int *)(v103 + 20) = v9 >> 8;
    }
    v104 = *(int *)(v5 + 24);
    if ( (v104 & 0x200) != 0 && (*(char *)(v5 + 16) & 4) != 0 )
    {
      v105 = *(long long *)(v5 + 32);
      v228 = v2;
      LOWORD(v253) = v9;
      v106 = sub_DD50(v105, &v253, 2);
      v104 = *(int *)(v5 + 24);
      v2 = v228;
      *(long long *)(v5 + 32) = v106;
    }
    *(int *)(v5 + 8) = 16184;
    if ( (v104 & 0x400) != 0 )
    {
      v9 = 0;
      v7 = 0;
LABEL_322:
      if ( !v8 )
        goto LABEL_240;
      v10 = v7;
      while ( 1 )
      {
        v170 = *v4++;
        --v8;
        v171 = v170 << v10;
        v10 += 8;
        v9 += v171;
        if ( v10 > 0xF )
          break;
        if ( !v8 )
          goto LABEL_241;
      }
LABEL_326:
      v172 = *(long long *)(v5 + 48);
      *(int *)(v5 + 92) = v9;
      if ( v172 )
        *(int *)(v172 + 32) = v9;
      if ( (v104 & 0x200) != 0 && (*(char *)(v5 + 16) & 4) != 0 )
      {
        v207 = *(long long *)(v5 + 32);
        v7 = 0;
        v238 = v2;
        LOWORD(v253) = v9;
        v9 = 0;
        v208 = sub_DD50(v207, &v253, 2);
        v104 = *(int *)(v5 + 24);
        v2 = v238;
        *(long long *)(v5 + 32) = v208;
      }
      else
      {
        v7 = 0;
        v9 = 0;
      }
    }
    else
    {
      v7 = 0;
      v9 = 0;
LABEL_193:
      v107 = *(long long *)(v5 + 48);
      if ( v107 )
        *(long long *)(v107 + 24) = 0;
    }
    *(int *)(v5 + 8) = 16185;
LABEL_196:
    v60 = v104;
    if ( (v104 & 0x400) != 0 )
    {
      v108 = *(int *)(v5 + 92);
      v109 = v108;
      if ( v8 <= v108 )
        v109 = v8;
      if ( v109 )
      {
        v110 = *(long long *)(v5 + 48);
        v111 = v109;
        if ( v110 )
        {
          v112 = *(long long *)(v110 + 24);
          if ( v112 )
          {
            v113 = *(int *)(v110 + 32);
            v114 = *(int *)(v110 + 36);
            v115 = v113 - v108;
            if ( v114 > (unsigned int)v115 )
            {
              v116 = v109;
              if ( v114 < v109 + (unsigned int)v115 )
                v116 = v108 + v114 - v113;
              v248 = v2;
              v243 = v109;
              v229 = v109;
              memcpy((void *)(v112 + v115), v4, v116);
              v60 = *(int *)(v5 + 24);
              v2 = v248;
              v111 = v243;
              v109 = v229;
            }
          }
        }
        if ( (v60 & 0x200) != 0 && (*(char *)(v5 + 16) & 4) != 0 )
        {
          v251 = v2;
          v247 = v111;
          v234 = v109;
          v189 = sub_DD50(*(long long *)(v5 + 32), v4, v109);
          v2 = v251;
          v111 = v247;
          *(long long *)(v5 + 32) = v189;
          v109 = v234;
        }
        v8 -= v109;
        v4 += v111;
        v108 = *(int *)(v5 + 92) - v109;
        *(int *)(v5 + 92) = v108;
      }
      if ( v108 )
        goto LABEL_240;
      v60 = *(int *)(v5 + 24);
    }
    *(int *)(v5 + 92) = 0;
    *(int *)(v5 + 8) = 16186;
LABEL_213:
    if ( (v60 & 0x800) != 0 )
    {
      if ( !v8 )
        goto LABEL_240;
      v147 = v4;
      LODWORD(v148) = 0;
      do
      {
        v149 = *(long long *)(v5 + 48);
        v150 = *v147;
        v148 = (unsigned int)(v148 + 1);
        if ( v149 )
        {
          v151 = *(long long *)(v149 + 40);
          if ( v151 )
          {
            v152 = *(unsigned int *)(v5 + 92);
            if ( (unsigned int)v152 < *(int *)(v149 + 48) )
            {
              *(int *)(v5 + 92) = v152 + 1;
              *(char *)(v151 + v152) = v150;
            }
          }
        }
        ++v147;
      }
      while ( v150 && v8 > (unsigned int)v148 );
      if ( (*(char *)(v5 + 25) & 2) != 0 && (*(char *)(v5 + 16) & 4) != 0 )
      {
        v250 = v2;
        v245 = v150;
        v231 = v148;
        v153 = sub_DD50(*(long long *)(v5 + 32), v4, v148);
        v2 = v250;
        v150 = v245;
        *(long long *)(v5 + 32) = v153;
        v148 = v231;
      }
      v8 -= v148;
      v4 += v148;
      if ( v150 )
        goto LABEL_240;
      v60 = *(int *)(v5 + 24);
    }
    else
    {
      v117 = *(long long *)(v5 + 48);
      if ( v117 )
        *(long long *)(v117 + 40) = 0;
    }
    *(int *)(v5 + 92) = 0;
    *(int *)(v5 + 8) = 16187;
LABEL_101:
    if ( (v60 & 0x1000) != 0 )
    {
      if ( !v8 )
        goto LABEL_240;
      v128 = v4;
      LODWORD(v129) = 0;
      do
      {
        v130 = *(long long *)(v5 + 48);
        v131 = *v128;
        v129 = (unsigned int)(v129 + 1);
        if ( v130 )
        {
          v132 = *(long long *)(v130 + 56);
          if ( v132 )
          {
            v133 = *(unsigned int *)(v5 + 92);
            if ( (unsigned int)v133 < *(int *)(v130 + 64) )
            {
              *(int *)(v5 + 92) = v133 + 1;
              *(char *)(v132 + v133) = v131;
            }
          }
        }
        ++v128;
      }
      while ( v131 && v8 > (unsigned int)v129 );
      if ( (*(char *)(v5 + 25) & 2) != 0 && (*(char *)(v5 + 16) & 4) != 0 )
      {
        v249 = v2;
        v244 = v131;
        v230 = v129;
        v134 = sub_DD50(*(long long *)(v5 + 32), v4, v129);
        v2 = v249;
        v131 = v244;
        *(long long *)(v5 + 32) = v134;
        v129 = v230;
      }
      v8 -= v129;
      v4 += v129;
      if ( v131 )
        goto LABEL_240;
      v60 = *(int *)(v5 + 24);
    }
    else
    {
      v63 = *(long long *)(v5 + 48);
      if ( v63 )
        *(long long *)(v63 + 56) = 0;
    }
    *(int *)(v5 + 8) = 16188;
    if ( (v60 & 0x200) != 0 )
    {
LABEL_105:
      if ( v7 <= 0xF )
      {
        if ( !v8 )
          goto LABEL_240;
        v10 = v7;
        while ( 1 )
        {
          v64 = *v4++;
          --v8;
          v65 = v64 << v10;
          v10 += 8;
          v9 += v65;
          if ( v10 > 0xF )
            break;
          if ( !v8 )
            goto LABEL_241;
        }
        v7 = v10;
      }
      if ( (*(char *)(v5 + 16) & 4) != 0 && *(unsigned short *)(v5 + 32) != v9 )
      {
        v18 = v9;
        *(long long *)(a1 + 48) = "header crc mismatch";
        *(int *)(v5 + 8) = 16209;
        goto LABEL_65;
      }
      v7 = 0;
      v9 = 0;
    }
LABEL_97:
    v61 = *(long long *)(v5 + 48);
    if ( v61 )
    {
      *(int *)(v61 + 72) = 1;
      *(int *)(v61 + 68) = (v60 >> 9) & 1;
    }
    v225 = v2;
    v62 = sub_DD50(0, 0, 0);
    v2 = v225;
    *(long long *)(v5 + 32) = v62;
    *(long long *)(a1 + 96) = v62;
    for ( *(int *)(v5 + 8) = 16191; ; *(int *)(v5 + 8) = 16191 )
    {
LABEL_16:
      if ( (unsigned int)(a2 - 5) <= 1 )
        goto LABEL_240;
LABEL_17:
      if ( *(int *)(v5 + 12) )
      {
        v17 = v7;
        *(int *)(v5 + 8) = 16206;
        v7 &= 0xFFFFFFF8;
        v18 = v9 >> (v17 & 7);
LABEL_19:
        v19 = *(int *)(v5 + 16);
        if ( v19 )
        {
          if ( v7 <= 0x1F )
          {
            v20 = v7;
            if ( v8 )
            {
              do
              {
                v21 = *v4++;
                --v8;
                v22 = v21 << v20;
                v20 += 8;
                v18 += v22;
                if ( v20 > 0x1F )
                {
                  v7 = v20;
                  goto LABEL_26;
                }
              }
              while ( v8 );
LABEL_271:
              v7 = v20;
            }
            goto LABEL_272;
          }
LABEL_26:
          v23 = v220 - n;
          v24 = v220 - n;
          *(long long *)(a1 + 40) += v24;
          *(long long *)(v5 + 40) += v24;
          v25 = v19 & 4;
          if ( (v19 & 4) != 0 )
          {
            if ( v23 )
            {
              v236 = v18;
              v195 = &v2[-v24];
              v221 = v2;
              v196 = *(long long *)(v5 + 32);
              if ( *(int *)(v5 + 24) )
              {
                v197 = sub_DD50(v196, v195, v23);
                v2 = v221;
                v18 = v236;
              }
              else
              {
                v197 = sub_D8E0(v196, v195, v23);
                v18 = v236;
                v2 = v221;
              }
              v19 = *(int *)(v5 + 16);
              *(long long *)(v5 + 32) = v197;
              *(long long *)(a1 + 96) = v197;
              v25 = v19 & 4;
            }
            if ( v25 )
            {
              v26 = v18;
              if ( !*(int *)(v5 + 24) )
                v26 = (unsigned int)((int)v18 << 24)
                    + (unsigned long long)(((int)v18 << 8) & 0xFF0000)
                    + ((v18 >> 8) & 0xFF00 | BYTE3(v18));
              if ( *(long long *)(v5 + 32) != v26 )
              {
                *(long long *)(a1 + 48) = "incorrect data check";
                *(int *)(v5 + 8) = 16209;
                v220 = n;
                goto LABEL_65;
              }
            }
          }
          v7 = 0;
          v18 = 0;
          v220 = n;
        }
        *(int *)(v5 + 8) = 16207;
LABEL_156:
        if ( v19 && *(int *)(v5 + 24) )
        {
          if ( v7 <= 0x1F )
          {
            v20 = v7;
            if ( !v8 )
            {
LABEL_272:
              v38 = v220 - n;
              goto LABEL_66;
            }
            while ( 1 )
            {
              v95 = *v4++;
              --v8;
              v96 = v95 << v20;
              v20 += 8;
              v18 += v96;
              if ( v20 > 0x1F )
                break;
              if ( !v8 )
                goto LABEL_271;
            }
            v7 = v20;
          }
          if ( (v19 & 4) != 0 && *(int *)(v5 + 40) != v18 )
          {
            *(long long *)(a1 + 48) = "incorrect length check";
            *(int *)(v5 + 8) = 16209;
            goto LABEL_65;
          }
          v7 = 0;
          v18 = 0;
        }
        *(int *)(v5 + 8) = 16208;
        v222 = 1;
        v38 = v220 - n;
        goto LABEL_66;
      }
      if ( v7 > 2 )
      {
        v29 = v4;
      }
      else
      {
        if ( !v8 )
          goto LABEL_414;
        v28 = v7;
        --v8;
        v29 = v4 + 1;
        v7 += 8;
        v9 += (unsigned long long)*v4 << v28;
      }
      *(int *)(v5 + 12) = v9 & 1;
      v30 = (v9 >> 1) & 3;
      if ( (int)v30 == 2 )
      {
        *(int *)(v5 + 8) = 16196;
        v9 >>= 3;
        v7 -= 3;
        v4 = v29;
LABEL_227:
        if ( v7 <= 0xD )
        {
          if ( !v8 )
            goto LABEL_240;
          v10 = v7;
          while ( 1 )
          {
            v120 = *v4++;
            --v8;
            v121 = v120 << v10;
            v10 += 8;
            v9 += v121;
            if ( v10 > 0xD )
              break;
            if ( !v8 )
              goto LABEL_241;
          }
          v7 = v10;
        }
        v7 -= 14;
        v122 = (v9 >> 5) & 0x1F;
        v123 = (v9 >> 10) & 0xF;
        v124 = (v9 & 0x1F) + 257;
        v9 >>= 14;
        ++v122;
        v69 = v123 + 4;
        *(int *)(v5 + 132) = v124;
        *(int *)(v5 + 136) = v122;
        *(int *)(v5 + 128) = v69;
        if ( v122 > 0x1E || v124 > 0x11E )
        {
          v18 = v9;
          *(long long *)(a1 + 48) = "too many length or distance symbols";
          *(int *)(v5 + 8) = 16209;
          goto LABEL_65;
        }
        *(int *)(v5 + 140) = 0;
        v68 = 0;
        v10 = v7;
        *(int *)(v5 + 8) = 16197;
LABEL_126:
        if ( v10 > 2 )
          goto LABEL_131;
LABEL_127:
        if ( v8 )
        {
          --v8;
          v70 = v4 + 1;
          v71 = (unsigned long long)*v4 << v10;
          v10 += 8;
          v9 += v71;
          while ( 1 )
          {
            v72 = v68 + 1;
            v10 -= 3;
            v73 = word_FE80[v68];
            v74 = v9 & 7;
            *(int *)(v5 + 140) = v72;
            v9 >>= 3;
            *(short *)(v5 + 2 * v73 + 152) = v74;
            if ( v72 >= v69 )
              break;
            v4 = v70;
            v68 = v72;
            if ( v10 <= 2 )
              goto LABEL_127;
LABEL_131:
            v70 = v4;
          }
          v7 = v10;
          LODWORD(v68) = v72;
          v4 = v70;
LABEL_372:
          if ( (unsigned int)v68 <= 0x12 )
          {
            v186 = &word_FE80[(unsigned int)v68];
            do
            {
              v187 = *v186++;
              *(short *)(v5 + 2 * v187 + 152) = 0;
            }
            while ( (unsigned short *)((char *)&unk_FE82
                                       + 2 * (unsigned int)v68
                                       + 2 * (unsigned long long)(unsigned int)(18 - v68)) != v186 );
            *(int *)(v5 + 140) = 19;
          }
          *(int *)(v5 + 120) = 7;
          *(long long *)(v5 + 144) = v5 + 1368;
          *(long long *)(v5 + 104) = v5 + 1368;
          v233 = v2;
          v188 = sub_B130(0, v5 + 152, 19, v5 + 144, v5 + 120, v5 + 792);
          v2 = v233;
          if ( v188 )
          {
            v18 = v9;
            *(long long *)(a1 + 48) = "invalid code lengths set";
            *(int *)(v5 + 8) = 16209;
            goto LABEL_65;
          }
          *(int *)(v5 + 140) = 0;
          v75 = 0;
          *(int *)(v5 + 8) = 16198;
LABEL_133:
          v76 = *(int *)(v5 + 132) + *(int *)(v5 + 136);
          v227 = *(int *)(v5 + 132);
          if ( v76 > (unsigned int)v75 )
          {
            v77 = *(long long *)(v5 + 104);
            v78 = ~(-1 << *(int *)(v5 + 120));
            do
            {
              v79 = v77 + 4LL * ((unsigned int)v9 & v78);
              v80 = *(char *)(v79 + 1);
              v81 = *(short *)(v79 + 2);
              v82 = v80;
              if ( v80 > v7 )
              {
                if ( !v8 )
                  goto LABEL_240;
                v10 = v7;
                while ( 1 )
                {
                  v83 = *v4++;
                  --v8;
                  v84 = v83 << v10;
                  v10 += 8;
                  v9 += v84;
                  v85 = v77 + 4LL * ((unsigned int)v9 & v78);
                  v86 = *(char *)(v85 + 1);
                  v81 = *(short *)(v85 + 2);
                  v82 = v86;
                  if ( v86 <= v10 )
                    break;
                  if ( !v8 )
                    goto LABEL_241;
                }
                v7 = v10;
                v80 = v86;
              }
              if ( v81 <= 0xFu )
              {
                v7 -= v82;
                v9 >>= v80;
                *(int *)(v5 + 140) = v75 + 1;
                *(short *)(v5 + 2 * v75 + 152) = v81;
                v75 = (unsigned int)(v75 + 1);
              }
              else
              {
                if ( v81 == 16 )
                {
                  if ( v82 + 2 > v7 )
                  {
                    if ( !v8 )
                      goto LABEL_240;
                    v10 = v7;
                    while ( 1 )
                    {
                      v192 = *v4++;
                      --v8;
                      v193 = v192 << v10;
                      v10 += 8;
                      v9 += v193;
                      if ( v10 >= v82 + 2 )
                        break;
                      if ( !v8 )
                        goto LABEL_241;
                    }
                    v7 = v10;
                  }
                  v7 -= v82;
                  v9 >>= v82;
                  if ( !(int)v75 )
                  {
LABEL_429:
                    v18 = v9;
                    *(long long *)(a1 + 48) = "invalid bit length repeat";
                    *(int *)(v5 + 8) = 16209;
                    goto LABEL_65;
                  }
                  v194 = v9;
                  v9 >>= 2;
                  v7 -= 2;
                  v91 = *(short *)(v5 + 2LL * (unsigned int)(v75 - 1) + 152);
                  v92 = (v194 & 3) + 3;
                }
                else if ( v81 == 17 )
                {
                  if ( v7 < v82 + 3 )
                  {
                    if ( !v8 )
                      goto LABEL_240;
                    v10 = v7;
                    while ( 1 )
                    {
                      v182 = *v4++;
                      --v8;
                      v183 = v182 << v10;
                      v10 += 8;
                      v9 += v183;
                      if ( v10 >= v82 + 3 )
                        break;
                      if ( !v8 )
                        goto LABEL_241;
                    }
                    v7 = v10;
                  }
                  v184 = v9 >> v82;
                  v185 = v184;
                  v7 += -3 - v82;
                  v9 = v184 >> 3;
                  v91 = 0;
                  v92 = (v185 & 7) + 3;
                }
                else
                {
                  if ( v7 < v82 + 7 )
                  {
                    if ( !v8 )
                      goto LABEL_240;
                    v10 = v7;
                    while ( 1 )
                    {
                      v87 = *v4++;
                      --v8;
                      v88 = v87 << v10;
                      v10 += 8;
                      v9 += v88;
                      if ( v10 >= v82 + 7 )
                        break;
                      if ( !v8 )
                        goto LABEL_241;
                    }
                    v7 = v10;
                  }
                  v89 = v9 >> v82;
                  v90 = v89;
                  v7 += -7 - v82;
                  v9 = v89 >> 7;
                  v91 = 0;
                  v92 = (v90 & 0x7F) + 11;
                }
                if ( v92 + (int)v75 > v76 )
                  goto LABEL_429;
                v93 = *(int *)(v5 + 140);
                v75 = v92 + v93;
                do
                {
                  v94 = v93++;
                  *(short *)(v5 + 2 * v94 + 152) = v91;
                }
                while ( (int)v75 != v93 );
                *(int *)(v5 + 140) = v75;
              }
            }
            while ( v76 > (unsigned int)v75 );
          }
          if ( *(int *)(v5 + 8) == 16209 )
          {
LABEL_430:
            v18 = v9;
            goto LABEL_65;
          }
          if ( !*(short *)(v5 + 664) )
          {
            v18 = v9;
            *(long long *)(a1 + 48) = "invalid code -- missing end-of-block";
            *(int *)(v5 + 8) = 16209;
            goto LABEL_65;
          }
          *(int *)(v5 + 120) = 9;
          *(long long *)(v5 + 144) = v5 + 1368;
          *(long long *)(v5 + 104) = v5 + 1368;
          v252 = v2;
          v211 = sub_B130(1, v5 + 152, v227, v5 + 144, v5 + 120, v5 + 792);
          v2 = v252;
          if ( !v211 )
          {
            v215 = *(long long *)(v5 + 144);
            *(int *)(v5 + 124) = 6;
            v216 = *(unsigned int *)(v5 + 136);
            *(long long *)(v5 + 112) = v215;
            v217 = sub_B130(2, 2LL * *(unsigned int *)(v5 + 132) + v5 + 152, v216, v5 + 144, v5 + 124, v5 + 792);
            v2 = v252;
            if ( v217 )
            {
              v18 = v9;
              *(long long *)(a1 + 48) = "invalid distances set";
              *(int *)(v5 + 8) = 16209;
              goto LABEL_65;
            }
            *(int *)(v5 + 8) = 16199;
            if ( a2 != 6 )
              goto LABEL_37;
LABEL_414:
            v18 = v9;
            v222 = 0;
            v38 = v220 - n;
            goto LABEL_66;
          }
          v18 = v9;
          *(long long *)(a1 + 48) = "invalid literal/lengths set";
          *(int *)(v5 + 8) = 16209;
LABEL_65:
          v222 = -3;
          v38 = v220 - n;
          goto LABEL_66;
        }
LABEL_241:
        v18 = v9;
        v7 = v10;
        v38 = v220 - n;
        goto LABEL_66;
      }
      if ( (int)v30 == 3 )
      {
        v7 -= 3;
        v4 = v29;
        *(long long *)(a1 + 48) = "invalid block type";
        v18 = v9 >> 3;
        *(int *)(v5 + 8) = 16209;
        goto LABEL_65;
      }
      if ( (int)v30 == 1 )
        break;
      *(int *)(v5 + 8) = 16193;
      v9 >>= 3;
      v7 -= 3;
      v4 = v29;
LABEL_49:
      v31 = v7;
      v7 &= 0xFFFFFFF8;
      v9 >>= v31 & 7;
      if ( v7 <= 0x1F )
      {
        if ( !v8 )
          goto LABEL_240;
        v10 = v7;
        while ( 1 )
        {
          v32 = *v4++;
          --v8;
          v33 = v32 << v10;
          v10 += 8;
          v9 += v33;
          if ( v10 > 0x1F )
            break;
          if ( !v8 )
            goto LABEL_241;
        }
        v7 = v10;
      }
      if ( (unsigned short)v9 != ((v9 >> 16) ^ 0xFFFF) )
      {
        v18 = v9;
        *(long long *)(a1 + 48) = "invalid stored block lengths";
        *(int *)(v5 + 8) = 16209;
        goto LABEL_65;
      }
      v66 = (unsigned short)v9;
      *(int *)(v5 + 8) = 16194;
      *(int *)(v5 + 92) = (unsigned short)v9;
      if ( a2 == 6 )
      {
        v7 = 0;
        v38 = v220 - n;
        v18 = 0;
        goto LABEL_66;
      }
      v7 = 0;
      v9 = 0;
LABEL_115:
      *(int *)(v5 + 8) = 16195;
LABEL_116:
      if ( v66 )
      {
        if ( v8 <= v66 )
          v66 = v8;
        if ( v66 > n )
          v66 = n;
        if ( !v66 )
        {
          v18 = v9;
          v38 = v220 - n;
          goto LABEL_66;
        }
        v242 = v66;
        v226 = v66;
        v67 = (char *)memcpy(v2, v4, v66);
        n -= v242;
        v6 = *(int *)(v5 + 8);
        *(int *)(v5 + 92) -= v242;
        v8 -= v242;
        v4 += v226;
        v2 = &v67[v226];
        goto LABEL_7;
      }
LABEL_270:
      ;
    }
    sub_8820((long long *)v5);
    *(int *)(v5 + 8) = 16199;
    if ( a2 == 6 )
    {
      v7 -= 3;
      v4 = v27;
      v222 = 0;
      v18 = v9 >> 3;
      v38 = v220 - n;
      goto LABEL_66;
    }
    v9 >>= 3;
    v7 -= 3;
    v4 = v27;
LABEL_37:
    for ( *(int *)(v5 + 8) = 16200; ; *(int *)(v5 + 8) = 16200 )
    {
LABEL_38:
      if ( v8 > 5 && n > 0x101 )
      {
        *(long long *)(a1 + 24) = v2;
        *(int *)(a1 + 32) = n;
        *(long long *)a1 = v4;
        *(int *)(a1 + 8) = v8;
        *(long long *)(v5 + 80) = v9;
        *(int *)(v5 + 88) = v7;
        sub_DDE0(a1, v220);
        v2 = *(char **)(a1 + 24);
        v4 = *(unsigned char **)a1;
        v8 = *(int *)(a1 + 8);
        v9 = *(long long *)(v5 + 80);
        v7 = *(int *)(v5 + 88);
        n = *(int *)(a1 + 32);
        v6 = *(int *)(v5 + 8);
        if ( v6 != 16191 )
          goto LABEL_7;
        *(int *)(v5 + 7148) = -1;
        goto LABEL_16;
      }
      v135 = *(int *)(v5 + 120);
      v136 = *(long long *)(v5 + 104);
      *(int *)(v5 + 7148) = 0;
      v137 = ~(-1 << v135);
      v138 = (char *)(v136 + 4LL * ((unsigned int)v9 & v137));
      v139 = v138[1];
      v140 = *v138;
      v141 = *((unsigned short *)v138 + 1);
      v142 = v139;
      if ( v7 < v139 )
      {
        if ( !v8 )
          goto LABEL_240;
        v10 = v7;
        while ( 1 )
        {
          v143 = *v4++;
          --v8;
          v144 = v143 << v10;
          v10 += 8;
          v9 += v144;
          v145 = (char *)(v136 + 4LL * ((unsigned int)v9 & v137));
          v146 = v145[1];
          v140 = *v145;
          v141 = *((unsigned short *)v145 + 1);
          v142 = v146;
          if ( v146 <= v10 )
            break;
          if ( !v8 )
            goto LABEL_241;
        }
        v7 = v10;
        v139 = v146;
      }
      if ( !v140 )
      {
        *(int *)(v5 + 7148) = v142;
        v9 >>= v139;
        v7 -= v142;
        *(int *)(v5 + 92) = v141;
        goto LABEL_237;
      }
      if ( (v140 & 0xF0) != 0 )
        break;
      v237 = ~(-1 << (v142 + v140));
      v198 = (char *)(v136 + 4LL * (v141 + (((unsigned int)v9 & v237) >> v142)));
      v199 = (unsigned char)v198[1];
      v140 = *v198;
      v200 = *((unsigned short *)v198 + 1);
      v201 = v199 + v142;
      if ( v199 + v142 > v7 )
      {
        if ( !v8 )
          goto LABEL_240;
        while ( 1 )
        {
          v202 = *v4;
          v203 = v7;
          v7 += 8;
          ++v4;
          --v8;
          v9 += v202 << v203;
          v204 = (char *)(v136 + 4LL * (v141 + (((unsigned int)v9 & v237) >> v142)));
          v140 = *v204;
          v200 = *((unsigned short *)v204 + 1);
          v205 = (unsigned char)v204[1];
          v201 = v205 + v142;
          if ( v205 + v142 <= v7 )
            break;
          if ( !v8 )
            goto LABEL_240;
        }
        v199 = v205;
      }
      *(int *)(v5 + 7148) = v201;
      *(int *)(v5 + 92) = v200;
      v7 = v7 - v142 - v199;
      v9 = v9 >> v142 >> v199;
      if ( v140 )
        goto LABEL_268;
LABEL_237:
      *(int *)(v5 + 8) = 16205;
LABEL_238:
      if ( !n )
        goto LABEL_395;
      ++v2;
      --n;
      *(v2 - 1) = *(int *)(v5 + 92);
    }
    *(int *)(v5 + 7148) = v142;
    v7 -= v142;
    *(int *)(v5 + 92) = v141;
    v9 >>= v142;
LABEL_268:
    if ( (v140 & 0x20) != 0 )
    {
      *(int *)(v5 + 7148) = -1;
      goto LABEL_270;
    }
    if ( (v140 & 0x40) != 0 )
    {
      v18 = v9;
      *(long long *)(a1 + 48) = "invalid literal/length code";
      *(int *)(v5 + 8) = 16209;
      goto LABEL_65;
    }
    v45 = v140 & 0xF;
    *(int *)(v5 + 8) = 16201;
    *(int *)(v5 + 100) = v45;
LABEL_83:
    if ( v45 )
    {
      if ( v7 < v45 )
      {
        if ( !v8 )
          goto LABEL_240;
        v10 = v7;
        while ( 1 )
        {
          v162 = *v4++;
          --v8;
          v163 = v162 << v10;
          v10 += 8;
          v9 += v163;
          if ( v10 >= v45 )
            break;
          if ( !v8 )
            goto LABEL_241;
        }
        v7 = v10;
      }
      *(int *)(v5 + 7148) += v45;
      v7 -= v45;
      v46 = *(int *)(v5 + 92) + (v9 & ~(-1 << v45));
      v9 >>= v45;
      *(int *)(v5 + 92) = v46;
      goto LABEL_85;
    }
    v46 = *(int *)(v5 + 92);
LABEL_85:
    *(int *)(v5 + 7152) = v46;
    *(int *)(v5 + 8) = 16202;
LABEL_86:
    v47 = *(long long *)(v5 + 112);
    v48 = ~(-1 << *(int *)(v5 + 124));
    v49 = (char *)(v47 + 4LL * ((unsigned int)v9 & v48));
    v50 = v49[1];
    v51 = *v49;
    v52 = *((unsigned short *)v49 + 1);
    v53 = v50;
    v54 = v50;
    if ( v50 <= v7 )
    {
LABEL_92:
      v58 = v53;
      if ( (v51 & 0xF0) != 0 )
      {
        v59 = *(int *)(v5 + 7148);
      }
      else
      {
        v246 = v52;
        v232 = ~(-1 << (v51 + v53));
        v164 = (char *)(v47 + 4LL * (v52 + (((unsigned int)v9 & v232) >> v50)));
        v51 = *v164;
        v52 = *((unsigned short *)v164 + 1);
        v53 = (unsigned char)v164[1];
        if ( v7 < v53 + v58 )
        {
          if ( !v8 )
            goto LABEL_240;
          while ( 1 )
          {
            v165 = *v4;
            v166 = v7;
            v7 += 8;
            ++v4;
            --v8;
            v9 += v165 << v166;
            v167 = (char *)(v47 + 4LL * (v246 + (((unsigned int)v9 & v232) >> v58)));
            v168 = *v167;
            v52 = *((unsigned short *)v167 + 1);
            v53 = (unsigned char)v167[1];
            if ( v53 + v58 <= v7 )
              break;
            if ( !v8 )
              goto LABEL_240;
          }
          v51 = v168;
        }
        v169 = v58;
        v7 -= v54;
        v59 = *(int *)(v5 + 7148) + v58;
        v9 >>= v169;
      }
      v7 -= v53;
      *(int *)(v5 + 7148) = v59 + v53;
      v9 >>= v53;
      if ( (v51 & 0x40) != 0 )
      {
        v18 = v9;
        *(long long *)(a1 + 48) = "invalid distance code";
        *(int *)(v5 + 8) = 16209;
        goto LABEL_65;
      }
      v34 = v51 & 0xF;
      *(int *)(v5 + 96) = v52;
      *(int *)(v5 + 100) = v34;
      *(int *)(v5 + 8) = 16203;
LABEL_58:
      if ( v34 )
      {
        if ( v7 < v34 )
        {
          if ( !v8 )
            goto LABEL_240;
          v10 = v7;
          while ( 1 )
          {
            v173 = *v4++;
            --v8;
            v174 = v173 << v10;
            v10 += 8;
            v9 += v174;
            if ( v10 >= v34 )
              break;
            if ( !v8 )
              goto LABEL_241;
          }
          v7 = v10;
        }
        *(int *)(v5 + 7148) += v34;
        v7 -= v34;
        v175 = v9 & ~(-1 << v34);
        v9 >>= v34;
        *(int *)(v5 + 96) += v175;
      }
      *(int *)(v5 + 8) = 16204;
LABEL_60:
      if ( !n )
      {
LABEL_395:
        v18 = v9;
        v38 = v220;
        goto LABEL_66;
      }
      v35 = *(unsigned int *)(v5 + 96);
      if ( (unsigned int)v35 <= v220 - n )
      {
        v155 = &v2[-v35];
        v37 = *(int *)(v5 + 92);
        v156 = v37;
      }
      else
      {
        v36 = v35 + n;
        v37 = v35 + n - v220;
        if ( *(int *)(v5 + 64) < v37 && *(int *)(v5 + 7144) )
        {
          v18 = v9;
          *(long long *)(a1 + 48) = "invalid distance too far back";
          *(int *)(v5 + 8) = 16209;
          goto LABEL_65;
        }
        v154 = *(int *)(v5 + 68);
        if ( v154 < v37 )
        {
          v37 -= v154;
          v154 += *(int *)(v5 + 60);
        }
        v155 = (char *)(v154 + v220 - v36 + *(long long *)(v5 + 72));
        v156 = *(int *)(v5 + 92);
        if ( v156 <= v37 )
          v37 = *(int *)(v5 + 92);
      }
      if ( v37 > n )
        v37 = n;
      v157 = v156 - v37;
      v158 = n - v37;
      v159 = v37 - 1;
      v160 = 0;
      *(int *)(v5 + 92) = v157;
      n = v158;
      do
      {
        v2[v160] = v155[v160];
        v161 = v160++;
      }
      while ( v159 != v161 );
      v2 += v159 + 1;
      if ( *(int *)(v5 + 92) )
      {
        v6 = *(int *)(v5 + 8);
        continue;
      }
      goto LABEL_37;
    }
    break;
  }
  if ( v8 )
  {
    v10 = v7;
    while ( 1 )
    {
      v55 = *v4++;
      --v8;
      v56 = v55 << v10;
      v10 += 8;
      v9 += v56;
      v57 = (char *)(v47 + 4LL * ((unsigned int)v9 & v48));
      v50 = v57[1];
      v51 = *v57;
      v52 = *((unsigned short *)v57 + 1);
      v53 = v50;
      v54 = v50;
      if ( v50 <= v10 )
        break;
      if ( !v8 )
        goto LABEL_241;
    }
    v7 = v10;
    goto LABEL_92;
  }
LABEL_240:
  v18 = v9;
  v38 = v220 - n;
LABEL_66:
  v39 = *(int *)(v5 + 60);
  *(long long *)(a1 + 24) = v2;
  *(long long *)a1 = v4;
  *(int *)(a1 + 32) = n;
  *(int *)(a1 + 8) = v8;
  *(long long *)(v5 + 80) = v18;
  *(int *)(v5 + 88) = v7;
  if ( !v39 && (v220 == n || (v40 = *(int *)(v5 + 8), v40 > 0x3F50) || v40 > 0x3F4D && a2 == 4) )
  {
LABEL_73:
    *(long long *)(a1 + 16) += n_4 - v8;
    *(long long *)(a1 + 40) += v38;
    *(long long *)(v5 + 40) += v38;
    if ( (*(char *)(v5 + 16) & 4) != 0 && v38 )
    {
      v125 = *(long long *)(v5 + 32);
      v126 = *(long long *)(a1 + 24) - v38;
      if ( *(int *)(v5 + 24) )
        v127 = sub_DD50(v125, v126, v38);
      else
        v127 = sub_D8E0(v125, v126, v38);
      *(long long *)(v5 + 32) = v127;
      *(long long *)(a1 + 96) = v127;
    }
    v41 = *(int *)(v5 + 8);
    v42 = *(int *)(v5 + 88) + ((*(int *)(v5 + 12) != 0) << 6);
    v43 = v42 + 128;
    if ( v41 != 16191 )
      v43 = v42 + ((v41 == 16194 || v41 == 16199) << 8);
    *(int *)(a1 + 88) = v43;
    if ( (!(v38 | (n_4 - v8)) || a2 == 4) && !v222 )
      return (unsigned int)-5;
  }
  else
  {
    if ( !(unsigned int)sub_88D0(a1, (long long)v2, v38) )
    {
      v8 = *(int *)(a1 + 8);
      v38 = v220 - *(int *)(a1 + 32);
      goto LABEL_73;
    }
    *(int *)(v5 + 8) = 16210;
    return (unsigned int)-4;
  }
  return v222;
}


// Function: inflateEnd @ 0xaa00
long long inflateEnd(long long a1)
{
  long long v1; // rsi
  unsigned int v2; // r12d

  if ( sub_87D0((long long *)a1) )
  {
    return (unsigned int)-2;
  }
  else
  {
    v1 = *(long long *)(a1 + 56);
    v2 = 0;
    if ( *(long long *)(v1 + 72) )
    {
      (*(void (**)(long long, long long))(a1 + 72))(*(long long *)(a1 + 80), *(long long *)(v1 + 72));
      v1 = *(long long *)(a1 + 56);
    }
    (*(void (**)(long long, long long))(a1 + 72))(*(long long *)(a1 + 80), v1);
    *(long long *)(a1 + 56) = 0;
  }
  return v2;
}


// Function: inflateGetDictionary @ 0xaa60
long long inflateGetDictionary(long long *a1, char *a2, int *a3)
{
  long long v4; // rbp
  unsigned int v5; // r12d
  int v6; // edx

  if ( sub_87D0(a1) )
  {
    return (unsigned int)-2;
  }
  else
  {
    v4 = a1[7];
    v5 = 0;
    v6 = *(int *)(v4 + 64);
    if ( v6 && a2 )
    {
      memcpy(
        a2,
        (const void *)(*(long long *)(v4 + 72) + *(unsigned int *)(v4 + 68)),
        (unsigned int)(v6 - *(int *)(v4 + 68)));
      memcpy(
        &a2[*(unsigned int *)(v4 + 64) - (unsigned long long)*(unsigned int *)(v4 + 68)],
        *(const void **)(v4 + 72),
        *(unsigned int *)(v4 + 68));
    }
    if ( a3 )
      *a3 = *(int *)(v4 + 64);
  }
  return v5;
}


// Function: inflateSetDictionary @ 0xaaf0
long long inflateSetDictionary(long long *a1, long long a2, unsigned int a3)
{
  long long v4; // r13
  int v5; // eax
  long long result; // rax
  long long v7; // rax

  if ( sub_87D0(a1) )
    return 4294967294LL;
  v4 = a1[7];
  v5 = *(int *)(v4 + 8);
  if ( *(int *)(v4 + 16) )
  {
    if ( v5 == 16190 )
    {
LABEL_7:
      v7 = sub_D8E0(0, 0, 0);
      if ( *(long long *)(v4 + 32) != sub_D8E0(v7, a2, a3) )
        return 4294967293LL;
      goto LABEL_4;
    }
    return 4294967294LL;
  }
  if ( v5 == 16190 )
    goto LABEL_7;
LABEL_4:
  result = sub_88D0((long long)a1, a2 + a3, a3);
  if ( (int)result )
  {
    *(int *)(v4 + 8) = 16210;
    return 4294967292LL;
  }
  else
  {
    *(int *)(v4 + 20) = 1;
  }
  return result;
}


// Function: inflateSync @ 0xabd0
long long inflateSync(long long a1)
{
  unsigned int v1; // edx
  long long v2; // rbp
  unsigned int v3; // r12d
  int v4; // edx
  long long v5; // rax
  char v6; // cl
  unsigned int v7; // edx
  unsigned long long v8; // rax
  unsigned int v9; // edx
  char *v10; // rcx
  unsigned int v11; // edx
  long long v12; // rsi
  unsigned int v13; // eax
  long long v14; // rsi
  long long v15; // rax
  bool v16; // zf
  unsigned int v17; // eax
  long long v18; // r8
  long long v19; // r10
  int v20; // r9d
  char v22[4]; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v23; // [rsp+8h] [rbp-30h]

  v23 = __readfsqword(0x28u);
  if ( sub_87D0((long long *)a1) )
  {
    return (unsigned int)-2;
  }
  else
  {
    v1 = *(int *)(a1 + 8);
    v2 = *(long long *)(a1 + 56);
    v3 = 0;
    if ( v1 || *(int *)(v2 + 88) > 7u )
    {
      if ( *(int *)(v2 + 8) != 16211 )
      {
        v4 = *(int *)(v2 + 88);
        v5 = *(long long *)(v2 + 80);
        *(int *)(v2 + 8) = 16211;
        v6 = v4;
        v7 = v4 & 0xFFFFFFF8;
        *(int *)(v2 + 88) = v7;
        v8 = v5 << (v6 & 7);
        *(long long *)(v2 + 80) = v8;
        if ( v7 <= 7 )
        {
          v11 = 0;
        }
        else
        {
          v9 = (v7 - 8) >> 3;
          v10 = v22;
          do
          {
            *v10++ = v8;
            v8 >>= 8;
          }
          while ( v10 != &v22[v9 + 1] );
          *(long long *)(v2 + 80) = v8;
          v11 = v9 + 1;
          *(int *)(v2 + 88) = 0;
        }
        *(int *)(v2 + 140) = 0;
        sub_8850((unsigned int *)(v2 + 140), (long long)v22, v11);
        v1 = *(int *)(a1 + 8);
      }
      v12 = *(long long *)a1;
      v13 = sub_8850((unsigned int *)(v2 + 140), *(long long *)a1, v1);
      *(int *)(a1 + 8) -= v13;
      v14 = v13 + v12;
      v15 = *(long long *)(a1 + 16) + v13;
      v16 = *(int *)(v2 + 140) == 4;
      *(long long *)a1 = v14;
      *(long long *)(a1 + 16) = v15;
      if ( v16 )
      {
        v17 = 0;
        if ( *(int *)(v2 + 24) != -1 )
          v17 = *(int *)(v2 + 16) & 0xFFFFFFFB;
        *(int *)(v2 + 16) = v17;
        sub_8AB0((long long *)a1);
        *(long long *)(a1 + 16) = v18;
        *(long long *)(a1 + 40) = v19;
        *(int *)(v2 + 24) = v20;
        *(int *)(v2 + 8) = 16191;
      }
      else
      {
        return (unsigned int)-3;
      }
    }
    else
    {
      return (unsigned int)-5;
    }
  }
  return v3;
}


// Function: inflateCopy @ 0xad90
long long inflateCopy(__m128i *a1, long long a2)
{
  long long v2; // r13
  __m128i **v3; // rax
  __m128i **v4; // rbp
  __m128i *v5; // r8
  long long v6; // rdx
  unsigned long long v7; // rax
  long long *v8; // rcx

  if ( sub_87D0((long long *)a2) || !a1 )
    return 4294967294LL;
  v2 = *(long long *)(a2 + 56);
  v3 = (__m128i **)(*(long long (**)(long long, long long, long long))(a2 + 64))(*(long long *)(a2 + 80), 1, 7160);
  v4 = v3;
  if ( !v3 )
    return 4294967292LL;
  v5 = *(__m128i **)(v2 + 72);
  if ( !v5 )
  {
    v6 = v2 + 1368;
    *a1 = _mm_loadu_si128((const __m128i *)a2);
    a1[1] = _mm_loadu_si128((const __m128i *)(a2 + 16));
    a1[2] = _mm_loadu_si128((const __m128i *)(a2 + 32));
    a1[3] = _mm_loadu_si128((const __m128i *)(a2 + 48));
    a1[4] = _mm_loadu_si128((const __m128i *)(a2 + 64));
    a1[5] = _mm_loadu_si128((const __m128i *)(a2 + 80));
    a1[6] = _mm_loadu_si128((const __m128i *)(a2 + 96));
    *v3 = *(__m128i **)v2;
    v3[894] = *(__m128i **)(v2 + 7152);
    qmemcpy(
      (void *)((unsigned long long)(v3 + 1) & 0xFFFFFFFFFFFFFFF8LL),
      (const void *)(v2 - ((long long)v3 - ((unsigned long long)(v3 + 1) & 0xFFFFFFFFFFFFFFF8LL))),
      8LL * (((unsigned int)v3 - (((int)v3 + 8) & 0xFFFFFFF8) + 7160) >> 3));
    *v3 = a1;
    v7 = *(long long *)(v2 + 104);
    if ( v7 < v2 + 1368 )
    {
      v4[18] = (__m128i *)((char *)v4 + *(long long *)(v2 + 144) - v2);
      goto LABEL_10;
    }
    goto LABEL_7;
  }
  v5 = (__m128i *)(*(long long (**)(long long, long long, long long))(a2 + 64))(
                    *(long long *)(a2 + 80),
                    (unsigned int)(1 << *(int *)(v2 + 56)),
                    1);
  if ( v5 )
  {
    v6 = v2 + 1368;
    *a1 = _mm_loadu_si128((const __m128i *)a2);
    a1[1] = _mm_loadu_si128((const __m128i *)(a2 + 16));
    a1[2] = _mm_loadu_si128((const __m128i *)(a2 + 32));
    a1[3] = _mm_loadu_si128((const __m128i *)(a2 + 48));
    a1[4] = _mm_loadu_si128((const __m128i *)(a2 + 64));
    a1[5] = _mm_loadu_si128((const __m128i *)(a2 + 80));
    a1[6] = _mm_loadu_si128((const __m128i *)(a2 + 96));
    *v4 = *(__m128i **)v2;
    v4[894] = *(__m128i **)(v2 + 7152);
    qmemcpy(
      (void *)((unsigned long long)(v4 + 1) & 0xFFFFFFFFFFFFFFF8LL),
      (const void *)(v2 - ((long long)v4 - ((unsigned long long)(v4 + 1) & 0xFFFFFFFFFFFFFFF8LL))),
      8LL * (((unsigned int)v4 - (((int)v4 + 8) & 0xFFFFFFF8) + 7160) >> 3));
    *v4 = a1;
    v7 = *(long long *)(v2 + 104);
    if ( v7 < v2 + 1368 )
    {
      v4[18] = (__m128i *)((char *)v4 + *(long long *)(v2 + 144) - v2);
LABEL_12:
      v5 = (__m128i *)memcpy(v5, *(const void **)(v2 + 72), (unsigned int)(1 << *(int *)(v2 + 56)));
LABEL_10:
      v4[9] = v5;
      a1[3].m128i_i64[1] = (long long)v4;
      return 0;
    }
LABEL_7:
    v8 = v4 + 171;
    if ( v7 <= v2 + 7140 )
    {
      v4[13] = (__m128i *)((char *)v8 + v7 - v6);
      v4[14] = (__m128i *)((char *)v8 + *(long long *)(v2 + 112) - v6);
    }
    v4[18] = (__m128i *)((char *)v8 + *(long long *)(v2 + 144) - v6);
    if ( !v5 )
      goto LABEL_10;
    goto LABEL_12;
  }
  (*(void (**)(long long, __m128i **))(a2 + 72))(*(long long *)(a2 + 80), v4);
  return 4294967292LL;
}


// Function: inflate_table @ 0xb130
long long inflate_table(int a1, unsigned short *a2, unsigned int a3, long long *a4, unsigned int *a5, short *a6)
{
  short *v8; // rdx
  unsigned short *v9; // rdx
  long long v10; // rdi
  char *v11; // rdx
  unsigned int v12; // r10d
  unsigned int v13; // ebx
  int *v14; // rax
  long long v15; // rdx
  unsigned int v17; // r8d
  short *v18; // rdx
  short *v19; // rdi
  int v20; // edx
  long long v21; // rdx
  short v22; // cx
  long long v23; // rdi
  long long v24; // rdx
  long long v25; // rcx
  long long v26; // rsi
  unsigned int v27; // esi
  unsigned int v28; // r13d
  int *v29; // rbp
  int v30; // r14d
  unsigned int v31; // r12d
  char v32; // r9
  char v33; // r11
  unsigned int v34; // eax
  short v35; // di
  int v36; // eax
  int v37; // eax
  int *v38; // rdx
  long long v39; // rax
  int v41; // ecx
  unsigned short *v42; // rsi
  int v43; // edi
  int v44; // ecx
  int *v45; // rcx
  int *v46; // rax
  unsigned int v49; // [rsp+18h] [rbp-D0h]
  unsigned int v50; // [rsp+1Ch] [rbp-CCh]
  int v51; // [rsp+24h] [rbp-C4h]
  int *v54; // [rsp+40h] [rbp-A8h]
  short *v55; // [rsp+48h] [rbp-A0h]
  char *v56; // [rsp+50h] [rbp-98h]
  unsigned int v57; // [rsp+58h] [rbp-90h]
  bool v58; // [rsp+5Eh] [rbp-8Ah]
  bool v59; // [rsp+5Fh] [rbp-89h]
  short v60; // [rsp+60h] [rbp-88h] BYREF
  char v61[28]; // [rsp+62h] [rbp-86h] BYREF
  char v62; // [rsp+7Eh] [rbp-6Ah] BYREF
  short v63[20]; // [rsp+80h] [rbp-68h] BYREF
  unsigned long long v64; // [rsp+A8h] [rbp-40h]

  v64 = __readfsqword(0x28u);
  v8 = &v60;
  do
    *v8++ = 0;
  while ( v63 != v8 );
  if ( a3 )
  {
    v9 = a2;
    do
    {
      v10 = *v9++;
      ++*(short *)&v61[2 * v10 - 2];
    }
    while ( &a2[a3] != v9 );
  }
  v11 = &v62;
  v12 = 15;
  v13 = *a5;
  while ( !*(short *)v11 )
  {
    v11 -= 2;
    if ( !--v12 )
    {
      v14 = (int *)*a4;
      v15 = *a4 + 8;
      *v14 = 320;
      *a4 = v15;
      v14[1] = 320;
      *a5 = 1;
      return 0;
    }
  }
  v17 = 1;
  v18 = v61;
  if ( v12 != 1 )
  {
    do
    {
      if ( *v18 )
        break;
      ++v17;
      ++v18;
    }
    while ( v17 != v12 );
  }
  v19 = v61;
  v20 = 1;
  do
  {
    v20 = 2 * v20 - (unsigned short)*v19;
    if ( v20 < 0 )
      return 0xFFFFFFFFLL;
    ++v19;
  }
  while ( v63 != v19 );
  if ( v20 && (!a1 || v12 != 1) )
    return 0xFFFFFFFFLL;
  v21 = 0;
  v63[1] = 0;
  v22 = 0;
  do
  {
    v22 += *(short *)&v61[v21 * 2];
    v63[v21 + 2] = v22;
    ++v21;
  }
  while ( v21 != 14 );
  v23 = a3;
  v24 = 0;
  if ( a3 )
  {
    do
    {
      v25 = a2[v24];
      if ( (short)v25 )
      {
        v26 = (unsigned short)v63[v25];
        a6[v26] = v24;
        v63[v25] = v26 + 1;
      }
      ++v24;
    }
    while ( v23 != v24 );
  }
  if ( v13 > v12 )
    v13 = v12;
  if ( v13 < v17 )
    v13 = v17;
  v54 = (int *)*a4;
  v50 = 1 << v13;
  if ( !a1 )
  {
    v49 = 20;
    v58 = 0;
    v56 = a6;
    v55 = a6;
    goto LABEL_39;
  }
  if ( a1 == 1 )
  {
    if ( v50 <= 0x354 )
    {
      v49 = 257;
      v56 = &unk_FF40;
      v55 = &unk_FF80;
      v59 = 1;
      v58 = 0;
      goto LABEL_40;
    }
    return 1;
  }
  v58 = a1 == 2;
  if ( v50 > 0x250 && a1 == 2 )
    return 1;
  v49 = 0;
  v56 = &unk_FEC0;
  v55 = &unk_FF00;
LABEL_39:
  v59 = a1 == 1;
LABEL_40:
  v27 = 0;
  v28 = 0;
  v51 = -1;
  v29 = (int *)*a4;
  v30 = 0;
  LOBYTE(v31) = v13;
  v57 = v50 - 1;
  while ( 1 )
  {
    v32 = 0;
    v33 = v17 - v28;
    v34 = (unsigned short)a6[v30];
    v35 = a6[v30];
    if ( v34 + 1 >= v49 )
    {
      if ( v34 < v49 )
      {
        v35 = 0;
        v32 = 96;
      }
      else
      {
        v36 = v34 - v49;
        v32 = v56[2 * v36];
        v35 = v55[v36];
      }
    }
    v37 = 1 << v31;
    do
    {
      v37 -= 1 << (v17 - v28);
      v38 = &v29[(v27 >> v28) + v37];
      *(char *)v38 = v32;
      *((char *)v38 + 1) = v33;
      *((short *)v38 + 1) = v35;
    }
    while ( v37 );
    LODWORD(v39) = 1 << (v17 - 1);
    if ( ((unsigned int)v39 & v27) == 0 )
      goto LABEL_67;
    do
      v39 = (unsigned int)v39 >> 1;
    while ( ((unsigned int)v39 & v27) != 0 );
    if ( (int)v39 )
LABEL_67:
      v39 = (v27 & ((int)v39 - 1)) + (unsigned int)v39;
    ++v30;
    if ( (*(short *)&v61[2 * v17 - 2])-- != 1 )
      goto LABEL_52;
    if ( v17 == v12 )
      break;
    v17 = a2[(unsigned short)a6[v30]];
LABEL_52:
    if ( v17 <= v13 || ((unsigned int)v39 & v57) == v51 )
    {
      v27 = v39;
    }
    else
    {
      v29 += (unsigned int)(1 << v31);
      if ( !v28 )
        v28 = v13;
      v31 = v17 - v28;
      if ( v17 < v12 )
      {
        v41 = (1 << (v17 - v28)) - *(unsigned short *)&v61[2 * v17 - 2];
        if ( v41 > 0 )
        {
          v42 = (unsigned short *)&v61[2 * v17];
          do
          {
            ++v31;
            v44 = 2 * v41;
            if ( v28 + v31 >= v12 )
              break;
            v43 = *v42++;
            v41 = v44 - v43;
          }
          while ( v41 > 0 );
        }
      }
      v50 += 1 << v31;
      if ( v50 > 0x354 && v59 || v50 > 0x250 && v58 )
        return 1;
      v51 = v39 & v57;
      v45 = &v54[(unsigned int)v39 & v57];
      *(char *)v45 = v31;
      *((short *)v45 + 1) = v29 - v54;
      v27 = v39;
      *((char *)v45 + 1) = v13;
    }
  }
  if ( (int)v39 )
  {
    v46 = &v29[v39];
    *(char *)v46 = 64;
    *((char *)v46 + 1) = v33;
    *((short *)v46 + 1) = 0;
  }
  *a4 = (long long)&v54[v50];
  *a5 = v13;
  return 0;
}


// Function: init_block @ 0xb660
long long init_block(long long a1)
{
  long long v1; // rax
  long long v2; // rax
  long long v3; // rax

  v1 = a1 + 212;
  do
  {
    v1 += 4;
    *(short *)(v1 - 4) = 0;
  }
  while ( v1 != a1 + 1356 );
  v2 = a1 + 2504;
  do
  {
    v2 += 4;
    *(short *)(v2 - 4) = 0;
  }
  while ( v2 != a1 + 2624 );
  v3 = a1 + 2748;
  do
  {
    v3 += 4;
    *(short *)(v3 - 4) = 0;
  }
  while ( v3 != a1 + 2824 );
  *(long long *)(a1 + 5920) = 0;
  *(short *)(a1 + 1236) = 1;
  *(long long *)(a1 + 5912) = 0;
  *(int *)(a1 + 5928) = 0;
  *(int *)(a1 + 5900) = 0;
  return 1;
}


// Function: pqdownheap @ 0xb700
void pqdownheap(long long a1, long long a2, int a3)
{
  long long v3; // r8
  int v4; // edx
  int v6; // r9d
  int v7; // r14d
  unsigned short v9; // r12
  long long v10; // r10
  int v11; // eax
  unsigned short v12; // di
  int v13; // esi
  long long v14; // r15
  unsigned short v15; // bp

  v3 = a3;
  v4 = 2 * a3;
  v6 = *(int *)(a1 + 5300);
  v7 = *(int *)(a1 + 4 * v3 + 3008);
  if ( v4 <= v6 )
  {
    v9 = *(short *)(a2 + 4LL * v7);
    do
    {
      v10 = *(int *)(a1 + 4LL * v4 + 3008);
      v11 = v4;
      v12 = *(short *)(a2 + 4 * v10);
      v13 = *(int *)(a1 + 4LL * v4 + 3008);
      if ( v6 > v4 )
      {
        v11 = v4 + 1;
        v14 = *(int *)(a1 + 4LL * (v4 + 1) + 3008);
        v15 = *(short *)(a2 + 4 * v14);
        if ( v15 < v12 )
        {
          v12 = *(short *)(a2 + 4 * v14);
          v13 = *(int *)(a1 + 4LL * (v4 + 1) + 3008);
        }
        else if ( v15 == v12 )
        {
          if ( *(char *)(a1 + v14 + 5308) > *(char *)(a1 + v10 + 5308) )
            v11 = v4;
          else
            v13 = *(int *)(a1 + 4LL * (v4 + 1) + 3008);
        }
        else
        {
          v11 = v4;
        }
      }
      if ( v9 < v12 || v9 == v12 && *(char *)(a1 + v7 + 5308) <= *(char *)(a1 + v13 + 5308) )
        break;
      v4 = 2 * v11;
      *(int *)(a1 + 4 * v3 + 3008) = v13;
      v3 = v11;
    }
    while ( 2 * v11 <= v6 );
  }
  *(int *)(a1 + 4 * v3 + 3008) = v7;
}


// Function: gen_bitlen @ 0xb7f0
long long gen_bitlen(long long a1, long long *a2)
{
  long long v3; // rdx
  long long *v4; // rax
  long long v5; // r9
  int v6; // r8d
  long long v7; // r11
  long long v8; // rbp
  int v9; // ebx
  int v10; // edi
  long long v11; // rax
  int v12; // r10d
  long long result; // rax
  long long v14; // r12
  long long v15; // rdx
  long long v16; // rsi
  unsigned short *v17; // r14
  int v18; // r13d
  long long v19; // rdx
  int v20; // r12d
  int v21; // r11d
  unsigned int v22; // r13d
  long long v23; // r10
  long long v24; // rbp
  short v25; // si
  long long v26; // rdx
  long long v27; // rbx
  int v28; // ebp
  int v29; // esi
  long long v30; // rdx
  unsigned short *v31; // rbx
  long long v32; // rdx

  v3 = a1 + 3008;
  v4 = (long long *)a2[2];
  v5 = *a2;
  v6 = *((int *)a2 + 2);
  v7 = *v4;
  v8 = v4[1];
  v9 = *((int *)v4 + 4);
  v10 = *((int *)v4 + 6);
  v11 = a1 + 2976;
  do
  {
    v11 += 2;
    *(short *)(v11 - 2) = 0;
  }
  while ( v11 != v3 );
  v12 = 0;
  result = (unsigned int)(*(int *)(a1 + 5304) + 1);
  *(short *)(v5 + 4LL * *(int *)(a1 + 4LL * *(int *)(a1 + 5304) + 3008) + 2) = 0;
  v14 = (int)result;
  if ( (int)result <= 572 )
  {
    do
    {
      v15 = *(int *)(a1 + 4 * v14 + 3008);
      v16 = 4 * v15;
      v17 = (unsigned short *)(v5 + 4 * v15);
      result = (unsigned int)*(unsigned short *)(v5 + 4LL * v17[1] + 2) + 1;
      if ( v10 < (int)result )
      {
        ++v12;
        result = (unsigned int)v10;
      }
      v17[1] = result;
      if ( v6 >= (int)v15 )
      {
        ++*(short *)(a1 + 2LL * (int)result + 2976);
        v18 = 0;
        if ( v9 <= (int)v15 )
        {
          v18 = *(int *)(v8 + 4LL * ((int)v15 - v9));
          LODWORD(result) = v18 + result;
        }
        v19 = *v17;
        result = v19 * (unsigned int)result;
        *(long long *)(a1 + 5912) += result;
        if ( v7 )
        {
          result = v19 * (v18 + (unsigned int)*(unsigned short *)(v7 + v16 + 2));
          *(long long *)(a1 + 5920) += result;
        }
      }
      ++v14;
    }
    while ( (int)v14 <= 572 );
    if ( v12 )
    {
      v20 = v12 - 2;
      v21 = v10 - 1;
      v22 = v12 - 2 - ((v12 - 1) & 0xFFFFFFFE);
      v23 = v10;
      v24 = a1 + 2LL * v10;
      v25 = *(short *)(v24 + 2974);
      if ( v25 )
        goto LABEL_18;
LABEL_14:
      v26 = a1 + 2LL * v10;
      LODWORD(result) = v10 - 1;
      do
      {
        v25 = *(short *)(v26 + 2972);
        v27 = (int)result;
        v26 -= 2;
        LODWORD(result) = result - 1;
      }
      while ( !v25 );
      while ( 1 )
      {
        result = (int)result;
        *(short *)(a1 + 2LL * (int)result + 2976) = v25 - 1;
        *(short *)(a1 + 2 * v27 + 2976) += 2;
        --*(short *)(v24 + 2976);
        if ( v20 == v22 )
          break;
        v25 = *(short *)(v24 + 2974);
        v20 -= 2;
        if ( !v25 )
          goto LABEL_14;
LABEL_18:
        v27 = v10;
        LODWORD(result) = v10 - 1;
      }
      if ( v10 )
      {
        v28 = 573;
        while ( 1 )
        {
          v29 = *(unsigned short *)(a1 + 2 * v23 + 2976);
          if ( *(short *)(a1 + 2 * v23 + 2976) )
          {
            result = v28 - 1;
            do
            {
              while ( 1 )
              {
                v30 = *(int *)(a1 + 4 * result + 3008);
                v28 = result;
                if ( v6 >= (int)v30 )
                  break;
                --result;
              }
              v31 = (unsigned short *)(v5 + 4 * v30);
              v32 = v31[1];
              if ( (int)v32 != v10 )
              {
                *(long long *)(a1 + 5912) += (v23 - v32) * *v31;
                v31[1] = v10;
              }
              --result;
              --v29;
            }
            while ( v29 );
          }
          v10 = v21;
          --v23;
          if ( !v21 )
            break;
          --v21;
        }
      }
    }
  }
  return result;
}


// Function: scan_tree @ 0xba40
long long scan_tree(short *a1, long long a2, int a3)
{
  int v3; // ecx
  long long result; // rax
  int v6; // r9d
  int v7; // edi
  long long v8; // r11
  unsigned short *v9; // rdx
  int v10; // r10d
  int v11; // esi

  v3 = *(unsigned short *)(a2 + 2);
  result = a3;
  *(short *)(a2 + 4LL * a3 + 6) = -1;
  v6 = 4 - (v3 == 0);
  v7 = v3 == 0 ? 138 : 7;
  if ( a3 >= 0 )
  {
    v8 = a2 + 4LL * a3 + 10;
    v9 = (unsigned short *)(a2 + 6);
    LODWORD(result) = 0;
    v10 = -1;
    while ( 1 )
    {
      result = (unsigned int)(result + 1);
      v11 = v3;
      v3 = *v9;
      if ( (int)result < v7 )
      {
        if ( v3 == v11 )
          goto LABEL_10;
        if ( (int)result < v6 )
        {
          a1[2 * v11 + 1374] += result;
          if ( v3 )
            goto LABEL_15;
LABEL_17:
          v10 = v11;
          v6 = 3;
          v7 = 138;
          result = 0;
          goto LABEL_10;
        }
      }
      if ( v11 )
      {
        if ( v11 != v10 )
          ++a1[2 * v11 + 1374];
        ++a1[1406];
      }
      else if ( (int)result > 10 )
      {
        ++a1[1410];
      }
      else
      {
        ++a1[1408];
      }
      if ( !v3 )
        goto LABEL_17;
      if ( v3 == v11 )
      {
        v10 = v3;
        v6 = 3;
        v7 = 6;
        result = 0;
LABEL_10:
        v9 += 2;
        if ( (unsigned short *)v8 == v9 )
          return result;
      }
      else
      {
LABEL_15:
        v9 += 2;
        v10 = v11;
        v6 = 4;
        result = 0;
        v7 = 7;
        if ( (unsigned short *)v8 == v9 )
          return result;
      }
    }
  }
  return result;
}


// Function: send_tree @ 0xbb60
long long send_tree(long long a1, long long a2, int a3)
{
  long long result; // rax
  int v4; // ebp
  int v5; // edi
  int v6; // ecx
  unsigned short *v7; // r12
  int v8; // r9d
  long long v9; // r14
  int v10; // esi
  int v11; // edx
  int v12; // r13d
  long long v13; // r10
  int v14; // edi
  int v15; // r9d
  int v16; // ecx
  int v17; // r8d
  short v18; // si
  long long v19; // rcx
  long long v20; // r8
  long long v21; // rcx
  long long v22; // rsi
  int v23; // edi
  int v24; // r8d
  int v25; // r9d
  long long v26; // rcx
  long long v27; // rdi
  long long v28; // rcx
  char v29; // r8
  long long v30; // rdi
  int v31; // r9d
  int v32; // esi
  int v33; // ecx
  int v34; // r8d
  long long v35; // rcx
  long long v36; // rdi
  long long v37; // rcx
  char v38; // r8
  long long v39; // rdi
  int v40; // edx
  long long v41; // rsi
  long long v42; // rdi
  short v43; // cx
  long long v44; // rcx
  long long v45; // rsi
  int v46; // r9d
  int v47; // r10d
  long long v48; // rdi
  short v49; // cx
  long long v50; // r8
  long long v51; // rcx
  long long v52; // rdi
  int v53; // ecx
  int v54; // r8d
  long long v55; // rdi
  int v56; // esi
  int v57; // edx
  long long v58; // rcx
  long long v59; // rdx
  long long v60; // rcx
  int v61; // r10d
  int v62; // r9d
  int v63; // ecx
  int v64; // r8d
  long long v65; // rcx
  long long v66; // rdi
  long long v67; // rcx
  char v68; // r8
  long long v69; // rdi
  long long v70; // rdi
  int v71; // esi
  int v72; // edx
  long long v73; // rcx
  long long v74; // rdx
  long long v75; // rcx

  result = a1;
  v4 = *(unsigned short *)(a2 + 2);
  v5 = 4 - (v4 == 0);
  v6 = v4 == 0 ? 138 : 7;
  if ( a3 >= 0 )
  {
    v7 = (unsigned short *)(a2 + 6);
    v8 = -1;
    v9 = a2 + 4LL * a3 + 10;
    v10 = 0;
    do
    {
      v11 = v10 + 1;
      v12 = v4;
      v4 = *v7;
      if ( v10 + 1 >= v6 )
        goto LABEL_14;
      if ( v4 == v12 )
      {
        ++v10;
        goto LABEL_12;
      }
      if ( v11 >= v5 )
      {
LABEL_14:
        v23 = *(int *)(result + 5940);
        v24 = *(unsigned short *)(result + 5936);
        if ( v12 )
        {
          if ( v8 != v12 )
          {
            v25 = *(unsigned short *)(result + 4LL * v12 + 2748);
            v11 = *(unsigned short *)(result + 4LL * v12 + 2750);
            v24 |= v25 << v23;
            if ( 16 - v11 >= v23 )
            {
              v23 += v11;
              LOWORD(v11) = v10;
              *(int *)(result + 5940) = v23;
            }
            else
            {
              v26 = *(long long *)(result + 40);
              v27 = *(long long *)(result + 16);
              *(short *)(result + 5936) = v24;
              *(long long *)(result + 40) = v26 + 1;
              *(char *)(v27 + v26) = v24;
              v28 = *(long long *)(result + 40);
              v29 = *(char *)(result + 5937);
              v30 = *(long long *)(result + 16);
              *(long long *)(result + 40) = v28 + 1;
              *(char *)(v30 + v28) = v29;
              LODWORD(v30) = *(int *)(result + 5940);
              LOBYTE(v28) = 16 - v30;
              v23 = v30 + v11 - 16;
              LOWORD(v11) = v10;
              *(int *)(result + 5940) = v23;
              v24 = v25 >> v28;
            }
          }
          v31 = *(unsigned short *)(result + 2812);
          v32 = *(unsigned short *)(result + 2814);
          v33 = v32 + v23;
          v34 = (v31 << v23) | v24;
          if ( 16 - v32 < v23 )
          {
            v35 = *(long long *)(result + 40);
            v36 = *(long long *)(result + 16);
            *(short *)(result + 5936) = v34;
            *(long long *)(result + 40) = v35 + 1;
            *(char *)(v36 + v35) = v34;
            v37 = *(long long *)(result + 40);
            v38 = *(char *)(result + 5937);
            v39 = *(long long *)(result + 16);
            *(long long *)(result + 40) = v37 + 1;
            *(char *)(v39 + v37) = v38;
            LODWORD(v39) = *(int *)(result + 5940);
            v33 = v39 + v32 - 16;
            v34 = v31 >> (16 - v39);
          }
          *(int *)(result + 5940) = v33;
          v40 = (unsigned short)(v11 - 3);
          if ( v33 <= 14 )
          {
            *(int *)(result + 5940) = v33 + 2;
            *(short *)(result + 5936) = ((short)v40 << v33) | v34;
          }
          else
          {
            v41 = *(long long *)(result + 40);
            v42 = *(long long *)(result + 16);
            v43 = v34 | (v40 << v33);
            *(short *)(result + 5936) = v43;
            *(long long *)(result + 40) = v41 + 1;
            *(char *)(v42 + v41) = v43;
            v44 = *(long long *)(result + 40);
            LOBYTE(v42) = *(char *)(result + 5937);
            v45 = *(long long *)(result + 16);
            *(long long *)(result + 40) = v44 + 1;
            *(char *)(v45 + v44) = v42;
            LODWORD(v45) = *(int *)(result + 5940);
            *(int *)(result + 5940) = v45 - 14;
            *(short *)(result + 5936) = v40 >> (16 - v45);
          }
        }
        else if ( v11 > 10 )
        {
          v61 = *(unsigned short *)(result + 2820);
          v62 = *(unsigned short *)(result + 2822);
          v63 = v62 + v23;
          v64 = (v61 << v23) | v24;
          if ( 16 - v62 < v23 )
          {
            v65 = *(long long *)(result + 40);
            v66 = *(long long *)(result + 16);
            *(short *)(result + 5936) = v64;
            *(long long *)(result + 40) = v65 + 1;
            *(char *)(v66 + v65) = v64;
            v67 = *(long long *)(result + 40);
            v68 = *(char *)(result + 5937);
            v69 = *(long long *)(result + 16);
            *(long long *)(result + 40) = v67 + 1;
            *(char *)(v69 + v67) = v68;
            LODWORD(v69) = *(int *)(result + 5940);
            v63 = v69 + v62 - 16;
            v64 = v61 >> (16 - v69);
          }
          *(int *)(result + 5940) = v63;
          if ( v63 <= 9 )
          {
            *(short *)(result + 5936) = (((short)v10 - 10) << v63) | v64;
            *(int *)(result + 5940) = v63 + 7;
          }
          else
          {
            v70 = *(long long *)(result + 16);
            v71 = (unsigned short)(v10 - 10);
            v72 = v71 << v63;
            v73 = *(long long *)(result + 40);
            LOWORD(v72) = v64 | v72;
            *(short *)(result + 5936) = v72;
            *(long long *)(result + 40) = v73 + 1;
            *(char *)(v70 + v73) = v72;
            v74 = *(long long *)(result + 40);
            LOBYTE(v70) = *(char *)(result + 5937);
            v75 = *(long long *)(result + 16);
            *(long long *)(result + 40) = v74 + 1;
            *(char *)(v75 + v74) = v70;
            LODWORD(v74) = *(int *)(result + 5940);
            *(int *)(result + 5940) = v74 - 9;
            *(short *)(result + 5936) = v71 >> (16 - v74);
          }
        }
        else
        {
          v46 = *(unsigned short *)(result + 2818);
          v47 = *(unsigned short *)(result + 2816);
          if ( 16 - v46 >= v23 )
          {
            v53 = v46 + v23;
            v54 = (v47 << v23) | v24;
          }
          else
          {
            v48 = *(long long *)(result + 40);
            v49 = v24 | (v47 << *(int *)(result + 5940));
            v50 = *(long long *)(result + 16);
            *(long long *)(result + 40) = v48 + 1;
            *(short *)(result + 5936) = v49;
            *(char *)(v50 + v48) = v49;
            v51 = *(long long *)(result + 40);
            LOBYTE(v50) = *(char *)(result + 5937);
            v52 = *(long long *)(result + 16);
            *(long long *)(result + 40) = v51 + 1;
            *(char *)(v52 + v51) = v50;
            LODWORD(v52) = *(int *)(result + 5940);
            v53 = v52 + v46 - 16;
            v54 = v47 >> (16 - v52);
          }
          *(int *)(result + 5940) = v53;
          if ( v53 <= 13 )
          {
            *(int *)(result + 5940) = v53 + 3;
            *(short *)(result + 5936) = (((short)v10 - 2) << v53) | v54;
          }
          else
          {
            v55 = *(long long *)(result + 16);
            v56 = (unsigned short)(v10 - 2);
            v57 = v56 << v53;
            v58 = *(long long *)(result + 40);
            LOWORD(v57) = v54 | v57;
            *(short *)(result + 5936) = v57;
            *(long long *)(result + 40) = v58 + 1;
            *(char *)(v55 + v58) = v57;
            v59 = *(long long *)(result + 40);
            LOBYTE(v55) = *(char *)(result + 5937);
            v60 = *(long long *)(result + 16);
            *(long long *)(result + 40) = v59 + 1;
            *(char *)(v60 + v59) = v55;
            LODWORD(v59) = *(int *)(result + 5940);
            *(int *)(result + 5940) = v59 - 13;
            *(short *)(result + 5936) = v56 >> (16 - v59);
          }
        }
        if ( !v4 )
        {
LABEL_25:
          v8 = v12;
          v5 = 3;
          v6 = 138;
          v10 = 0;
          goto LABEL_12;
        }
        if ( v4 == v12 )
        {
          v8 = v4;
          v5 = 3;
          v6 = 6;
          v10 = 0;
          goto LABEL_12;
        }
      }
      else
      {
        v13 = v12 + 684LL;
        do
        {
          v14 = *(unsigned short *)(result + 4 * v13 + 14);
          v15 = *(unsigned short *)(result + 4 * v13 + 12);
          v16 = *(int *)(result + 5940);
          v17 = v16 + v14;
          v18 = *(short *)(result + 5936) | (v15 << v16);
          if ( v16 > 16 - v14 )
          {
            v19 = *(long long *)(result + 40);
            v20 = *(long long *)(result + 16);
            *(short *)(result + 5936) = v18;
            *(long long *)(result + 40) = v19 + 1;
            *(char *)(v20 + v19) = v18;
            v21 = *(long long *)(result + 40);
            LOBYTE(v20) = *(char *)(result + 5937);
            v22 = *(long long *)(result + 16);
            *(long long *)(result + 40) = v21 + 1;
            *(char *)(v22 + v21) = v20;
            LODWORD(v20) = *(int *)(result + 5940);
            LOBYTE(v21) = 16 - v20;
            v17 = v20 + v14 - 16;
            v18 = v15 >> v21;
          }
          *(short *)(result + 5936) = v18;
          *(int *)(result + 5940) = v17;
          --v11;
        }
        while ( v11 );
        if ( !v4 )
          goto LABEL_25;
      }
      v8 = v12;
      v5 = 4;
      v6 = 7;
      v10 = 0;
LABEL_12:
      v7 += 2;
    }
    while ( (unsigned short *)v9 != v7 );
  }
  return result;
}


// Function: send_all_trees @ 0xc100
long long send_all_trees(long long a1, int a2, int a3, int a4)
{
  int v8; // ecx
  short v9; // dx
  int v10; // eax
  long long v11; // rcx
  short v12; // dx
  long long v13; // rax
  long long v14; // rax
  long long v15; // rdx
  int v16; // ecx
  int v17; // edx
  int v18; // r12d
  int v19; // eax
  long long v20; // rcx
  short v21; // dx
  long long v22; // rax
  long long v23; // rax
  long long v24; // rdx
  int v25; // ecx
  int v26; // eax
  long long v27; // rcx
  short v28; // dx
  long long v29; // rax
  long long v30; // rax
  long long v31; // rdx
  int v32; // ecx
  short v33; // dx
  char *v34; // rsi
  long long v35; // rax
  char *v36; // r9
  int v37; // edi
  int v38; // ecx
  int v39; // edx
  short v40; // ax
  long long v41; // rdx
  long long v42; // rcx
  long long v43; // rax
  long long v44; // rdx
  int v46; // esi

  v8 = *(int *)(a1 + 5940);
  v9 = *(short *)(a1 + 5936);
  v10 = (unsigned short)(a2 - 257) << v8;
  if ( v8 <= 11 )
  {
    v16 = v8 + 5;
    LOWORD(v17) = v10 | v9;
  }
  else
  {
    v11 = *(long long *)(a1 + 16);
    v12 = v10 | v9;
    v13 = *(long long *)(a1 + 40);
    *(short *)(a1 + 5936) = v12;
    *(long long *)(a1 + 40) = v13 + 1;
    *(char *)(v11 + v13) = v12;
    v14 = *(long long *)(a1 + 40);
    LOBYTE(v11) = *(char *)(a1 + 5937);
    v15 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v14 + 1;
    *(char *)(v15 + v14) = v11;
    LODWORD(v14) = *(int *)(a1 + 5940);
    v16 = v14 - 11;
    v17 = (int)(unsigned short)(a2 - 257) >> (16 - v14);
  }
  *(int *)(a1 + 5940) = v16;
  v18 = a3 - 1;
  if ( v16 <= 11 )
  {
    v46 = (unsigned short)(a3 - 1) << v16;
    v25 = v16 + 5;
    LOWORD(v17) = v46 | v17;
  }
  else
  {
    v19 = (unsigned short)v18 << v16;
    v20 = *(long long *)(a1 + 16);
    v21 = v19 | v17;
    v22 = *(long long *)(a1 + 40);
    *(short *)(a1 + 5936) = v21;
    *(long long *)(a1 + 40) = v22 + 1;
    *(char *)(v20 + v22) = v21;
    v23 = *(long long *)(a1 + 40);
    LOBYTE(v20) = *(char *)(a1 + 5937);
    v24 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v23 + 1;
    *(char *)(v24 + v23) = v20;
    LODWORD(v23) = *(int *)(a1 + 5940);
    v25 = v23 - 11;
    v17 = (int)(unsigned short)v18 >> (16 - v23);
  }
  *(int *)(a1 + 5940) = v25;
  v26 = (unsigned short)(a4 - 4) << v25;
  if ( v25 <= 12 )
  {
    v32 = v25 + 4;
    v33 = v26 | v17;
  }
  else
  {
    v27 = *(long long *)(a1 + 16);
    v28 = v26 | v17;
    v29 = *(long long *)(a1 + 40);
    *(short *)(a1 + 5936) = v28;
    *(long long *)(a1 + 40) = v29 + 1;
    *(char *)(v27 + v29) = v28;
    v30 = *(long long *)(a1 + 40);
    LOBYTE(v27) = *(char *)(a1 + 5937);
    v31 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v30 + 1;
    *(char *)(v31 + v30) = v27;
    LODWORD(v30) = *(int *)(a1 + 5940);
    v32 = v30 - 12;
    v33 = (int)(unsigned short)(a4 - 4) >> (16 - v30);
  }
  *(short *)(a1 + 5936) = v33;
  *(int *)(a1 + 5940) = v32;
  if ( a4 > 0 )
  {
    v34 = (char *)&unk_10901;
    v35 = 16;
    v36 = (char *)&unk_10901 + (unsigned int)(a4 - 1);
    while ( 1 )
    {
      v37 = *(unsigned short *)(a1 + 4 * v35 + 2750);
      v38 = *(int *)(a1 + 5940);
      v39 = v38 + 3;
      v40 = *(short *)(a1 + 5936) | (v37 << v38);
      if ( v38 > 13 )
      {
        v41 = *(long long *)(a1 + 40);
        v42 = *(long long *)(a1 + 16);
        *(short *)(a1 + 5936) = v40;
        *(long long *)(a1 + 40) = v41 + 1;
        *(char *)(v42 + v41) = v40;
        v43 = *(long long *)(a1 + 40);
        LOBYTE(v42) = *(char *)(a1 + 5937);
        v44 = *(long long *)(a1 + 16);
        *(long long *)(a1 + 40) = v43 + 1;
        *(char *)(v44 + v43) = v42;
        LODWORD(v44) = *(int *)(a1 + 5940);
        LOBYTE(v42) = 16 - v44;
        v39 = v44 - 13;
        v40 = v37 >> v42;
      }
      *(short *)(a1 + 5936) = v40;
      *(int *)(a1 + 5940) = v39;
      if ( v34 == v36 )
        break;
      v35 = (unsigned char)*v34++;
    }
  }
  sub_BB60(a1, a1 + 212, a2 - 1);
  return sub_BB60(a1, a1 + 2504, v18);
}


// Function: compress_block @ 0xc380
long long compress_block(long long a1, long long a2, long long a3)
{
  long long result; // rax
  int v5; // ecx
  int v6; // esi
  int v7; // edi
  unsigned int v9; // r8d
  unsigned short *v10; // rdx
  int v11; // r10d
  int v12; // edx
  long long v13; // rcx
  long long v14; // rdi
  long long v15; // rcx
  long long v16; // rsi
  int v17; // edx
  long long v18; // r10
  int v19; // ebx
  long long v20; // rdx
  long long v21; // rcx
  int v22; // edx
  long long v23; // r10
  short v24; // bx
  unsigned short *v25; // rcx
  int v26; // r12d
  int v27; // ebp
  int v28; // ecx
  int v29; // r15d
  long long v30; // rcx
  long long v31; // rsi
  long long v32; // rcx
  long long v33; // rsi
  char v34; // di
  int v35; // esi
  int v36; // ebx
  long long v37; // rcx
  long long v38; // rdi
  long long v39; // rcx
  long long v40; // rdi
  char v41; // r10
  unsigned int v42; // edx
  long long v43; // r10
  unsigned short *v44; // rsi
  int v45; // ebp
  int v46; // ebx
  long long v47; // rcx
  long long v48; // rdi
  long long v49; // rcx
  long long v50; // rsi
  int v51; // ebx
  int v52; // edx
  long long v53; // rcx
  long long v54; // rdi
  long long v55; // rcx
  long long v56; // rsi
  int v57; // edx
  int v58; // r9d
  int v59; // edx
  int v60; // r8d
  long long v61; // rsi
  long long v62; // rdi
  long long v63; // r8
  long long v64; // rdi

  result = a1;
  v5 = *(int *)(a1 + 5900);
  v6 = *(unsigned short *)(a1 + 5936);
  v7 = *(int *)(a1 + 5940);
  if ( v5 )
  {
    v9 = 0;
    while ( 1 )
    {
      v18 = *(long long *)(result + 5888);
      v19 = *(unsigned char *)(v18 + v9);
      v20 = v9 + 1;
      v21 = *(unsigned char *)(v18 + v9 + 2);
      v9 += 3;
      v22 = v19 + (*(unsigned char *)(v18 + v20) << 8);
      if ( !v22 )
        break;
      v23 = byte_10100[v21];
      v24 = (unsigned char)v21;
      v25 = (unsigned short *)(a2 + 4LL * (unsigned int)(v23 + 257));
      v26 = *v25;
      v27 = v25[1];
      v28 = v27 + v7;
      v29 = v6 | (v26 << v7);
      if ( 16 - v27 < v7 )
      {
        v30 = *(long long *)(result + 40);
        v31 = *(long long *)(result + 16);
        *(short *)(result + 5936) = v29;
        *(long long *)(result + 40) = v30 + 1;
        *(char *)(v31 + v30) = v29;
        v32 = *(long long *)(result + 40);
        v33 = *(long long *)(result + 16);
        v34 = *(char *)(result + 5937);
        *(long long *)(result + 40) = v32 + 1;
        *(char *)(v33 + v32) = v34;
        LODWORD(v33) = *(int *)(result + 5940);
        v28 = v33 + v27 - 16;
        v29 = v26 >> (16 - v33);
      }
      *(int *)(result + 5940) = v28;
      v35 = dword_10A00[v23];
      if ( v35 )
      {
        v36 = (unsigned short)(v24 - word_10080[2 * v23]);
        v29 |= v36 << v28;
        if ( 16 - v35 >= v28 )
        {
          v28 += v35;
          *(int *)(result + 5940) = v28;
        }
        else
        {
          v37 = *(long long *)(result + 40);
          v38 = *(long long *)(result + 16);
          *(short *)(result + 5936) = v29;
          *(long long *)(result + 40) = v37 + 1;
          *(char *)(v38 + v37) = v29;
          v39 = *(long long *)(result + 40);
          v40 = *(long long *)(result + 16);
          v41 = *(char *)(result + 5937);
          *(long long *)(result + 40) = v39 + 1;
          *(char *)(v40 + v39) = v41;
          LODWORD(v40) = *(int *)(result + 5940);
          v28 = v40 + v35 - 16;
          *(int *)(result + 5940) = v28;
          v29 = v36 >> (16 - v40);
        }
      }
      v42 = v22 - 1;
      if ( v42 > 0xFF )
        v43 = (unsigned char)byte_10200[(v42 >> 7) + 256];
      else
        v43 = (unsigned char)byte_10200[v42];
      v44 = (unsigned short *)(a3 + 4 * v43);
      v45 = *v44;
      v46 = v44[1];
      v7 = v46 + v28;
      v6 = v29 | (v45 << v28);
      if ( 16 - v46 < v28 )
      {
        v47 = *(long long *)(result + 40);
        v48 = *(long long *)(result + 16);
        *(short *)(result + 5936) = v6;
        *(long long *)(result + 40) = v47 + 1;
        *(char *)(v48 + v47) = v6;
        v49 = *(long long *)(result + 40);
        LOBYTE(v48) = *(char *)(result + 5937);
        v50 = *(long long *)(result + 16);
        *(long long *)(result + 40) = v49 + 1;
        *(char *)(v50 + v49) = v48;
        LODWORD(v48) = *(int *)(result + 5940);
        LOBYTE(v49) = 16 - v48;
        v7 = v48 + v46 - 16;
        v6 = v45 >> v49;
      }
      *(short *)(result + 5936) = v6;
      v51 = dword_10980[v43];
      *(int *)(result + 5940) = v7;
      if ( !v51 )
        goto LABEL_5;
      v52 = (unsigned short)(v42 - word_10000[2 * v43]);
      v6 |= v52 << v7;
      *(short *)(result + 5936) = v6;
      if ( 16 - v51 >= v7 )
      {
        v7 += v51;
        *(int *)(result + 5940) = v7;
LABEL_5:
        if ( *(int *)(result + 5900) <= v9 )
          goto LABEL_19;
      }
      else
      {
        v53 = *(long long *)(result + 40);
        v54 = *(long long *)(result + 16);
        *(long long *)(result + 40) = v53 + 1;
        *(char *)(v54 + v53) = v6;
        v55 = *(long long *)(result + 40);
        LOBYTE(v54) = *(char *)(result + 5937);
        v56 = *(long long *)(result + 16);
        *(long long *)(result + 40) = v55 + 1;
        *(char *)(v56 + v55) = v54;
        LODWORD(v54) = *(int *)(result + 5940);
        LOBYTE(v55) = 16 - v54;
        v7 = v54 + v51 - 16;
        v57 = v52 >> v55;
        *(int *)(result + 5940) = v7;
        *(short *)(result + 5936) = v57;
        v6 = v57;
        if ( *(int *)(result + 5900) <= v9 )
          goto LABEL_19;
      }
    }
    v10 = (unsigned short *)(a2 + 4 * v21);
    v11 = v10[1];
    v12 = *v10;
    v6 |= v12 << v7;
    *(short *)(result + 5936) = v6;
    if ( 16 - v11 >= v7 )
    {
      v7 += v11;
      *(int *)(result + 5940) = v7;
    }
    else
    {
      v13 = *(long long *)(result + 40);
      v14 = *(long long *)(result + 16);
      *(long long *)(result + 40) = v13 + 1;
      *(char *)(v14 + v13) = v6;
      v15 = *(long long *)(result + 40);
      LOBYTE(v14) = *(char *)(result + 5937);
      v16 = *(long long *)(result + 16);
      *(long long *)(result + 40) = v15 + 1;
      *(char *)(v16 + v15) = v14;
      LODWORD(v14) = *(int *)(result + 5940);
      LOBYTE(v15) = 16 - v14;
      v7 = v14 + v11 - 16;
      v17 = v12 >> v15;
      *(int *)(result + 5940) = v7;
      *(short *)(result + 5936) = v17;
      v6 = v17;
    }
    goto LABEL_5;
  }
LABEL_19:
  v58 = *(unsigned short *)(a2 + 1024);
  v59 = *(unsigned short *)(a2 + 1026);
  v60 = v59 + v7;
  LODWORD(v61) = (v58 << v7) | v6;
  if ( 16 - v59 < v7 )
  {
    v62 = *(long long *)(result + 40);
    v63 = *(long long *)(result + 16);
    *(short *)(result + 5936) = v61;
    *(long long *)(result + 40) = v62 + 1;
    *(char *)(v63 + v62) = v61;
    v61 = *(long long *)(result + 40);
    LOBYTE(v63) = *(char *)(result + 5937);
    v64 = *(long long *)(result + 16);
    *(long long *)(result + 40) = v61 + 1;
    *(char *)(v64 + v61) = v63;
    LODWORD(v64) = *(int *)(result + 5940);
    v60 = v64 + v59 - 16;
    LOWORD(v61) = v58 >> (16 - v64);
  }
  *(short *)(result + 5936) = v61;
  *(int *)(result + 5940) = v60;
  return result;
}


// Function: detect_data_type @ 0xc7a0
long long detect_data_type(long long a1)
{
  short *v1; // rax
  unsigned long long v2; // rdx
  short *v3; // rdi

  v1 = (short *)(a1 + 212);
  v2 = 4093624447LL;
  do
  {
    if ( (v2 & 1) != 0 && *v1 )
      return 0;
    v1 += 2;
    v2 >>= 1;
  }
  while ( v1 != (short *)(a1 + 340) );
  if ( (*(long long *)(a1 + 248) & 0xFFFF0000FFFFLL) == 0 && !*(short *)(a1 + 264) )
  {
    v3 = (short *)(a1 + 1236);
    while ( !*v1 )
    {
      v1 += 2;
      if ( v3 == v1 )
        return 0;
    }
  }
  return 1;
}


// Function: bi_reverse @ 0xc830
long long bi_reverse(unsigned int a1, int a2)
{
  int v2; // edx
  char v3; // al
  int v4; // eax

  v2 = 0;
  do
  {
    v3 = a1;
    --a2;
    a1 >>= 1;
    v4 = v2 | v3 & 1;
    v2 = 2 * v4;
  }
  while ( a2 > 0 );
  return v4 & 0x7FFFFFFF;
}


// Function: gen_codes @ 0xc860
unsigned long long gen_codes(short *a1, int a2, long long a3)
{
  long long v3; // rcx
  int v4; // eax
  short *v5; // rcx
  long long v6; // r8
  int v7; // esi
  unsigned int v8; // edi
  short v9; // ax
  short v11[20]; // [rsp+0h] [rbp-38h]
  unsigned long long v12; // [rsp+28h] [rbp-10h]

  v3 = 0;
  v12 = __readfsqword(0x28u);
  v4 = 0;
  do
  {
    v4 = 2 * (*(unsigned short *)(a3 + v3 * 2) + v4);
    v11[++v3] = v4;
  }
  while ( v3 != 15 );
  if ( a2 >= 0 )
  {
    v5 = a1;
    v6 = (long long)&a1[2 * a2 + 2];
    do
    {
      v7 = (unsigned short)v5[1];
      if ( v5[1] )
      {
        v8 = (unsigned short)v11[(unsigned short)v5[1]];
        v11[(unsigned short)v5[1]] = v8 + 1;
        v9 = sub_C830(v8, v7);
        *v5 = v9;
      }
      v5 += 2;
    }
    while ( (short *)v6 != v5 );
  }
  return v12 - __readfsqword(0x28u);
}


// Function: build_tree @ 0xc900
unsigned long long build_tree(long long a1, long long a2)
{
  long long *v3; // rax
  short *v4; // rbp
  int v5; // r15d
  long long v6; // r8
  long long v7; // r12
  long long v8; // rdx
  int v9; // eax
  long long v10; // rdi
  long long v11; // rdx
  short *v12; // r10
  long long v13; // rsi
  int v14; // ecx
  int v15; // r13d
  long long v16; // r13
  long long v17; // rsi
  long long v18; // rdx
  int *v19; // r14
  int v20; // r15d
  short *v21; // rdi
  short *v22; // rsi
  unsigned char v23; // r10
  unsigned char v24; // cl
  char v25; // dl
  short v26; // dx
  int v27; // eax
  int v29; // [rsp+Ch] [rbp-4Ch]
  int v30; // [rsp+10h] [rbp-48h]
  short v31; // [rsp+16h] [rbp-42h]

  v3 = *(long long **)(a2 + 16);
  v4 = *(short **)a2;
  v5 = *((int *)v3 + 5);
  v6 = *v3;
  *(long long *)(a1 + 5300) = 0x23D00000000LL;
  if ( v5 <= 0 )
  {
    v29 = -1;
    v9 = 0;
    v7 = v5;
LABEL_7:
    v10 = *(long long *)(a1 + 5912) + v9;
    v11 = v9 + 1;
    do
    {
      if ( v29 > 1 )
      {
        v12 = v4;
        v13 = 0;
        v14 = 0;
      }
      else
      {
        v14 = v29 + 1;
        v29 = v14;
        v13 = 2LL * v14;
        v12 = &v4[v13];
      }
      *(int *)(a1 + 5300) = v11;
      *(int *)(a1 + 4 * v11 + 3008) = v14;
      *v12 = 1;
      *(char *)(a1 + v14 + 5308) = 0;
      *(long long *)(a1 + 5912) = v10 - v11;
      if ( v6 )
        *(long long *)(a1 + 5920) -= *(unsigned short *)(v6 + v13 * 2 + 2);
      ++v11;
    }
    while ( (int)v11 - 1 <= 1 );
    v9 = 2;
    goto LABEL_15;
  }
  v29 = -1;
  v7 = v5;
  v8 = 0;
  v9 = 0;
  do
  {
    while ( v4[2 * v8] )
    {
      ++v9;
      v29 = v8;
      *(int *)(a1 + 5300) = v9;
      *(int *)(a1 + 4LL * v9 + 3008) = v8;
      *(char *)(a1 + v8++ + 5308) = 0;
      if ( v8 == v5 )
        goto LABEL_6;
    }
    v4[2 * v8++ + 1] = 0;
  }
  while ( v8 != v5 );
LABEL_6:
  if ( v9 <= 1 )
    goto LABEL_7;
LABEL_15:
  v15 = v9 >> 1;
  *(int *)(a2 + 8) = v29;
  do
    sub_B700(a1, (long long)v4, v15--);
  while ( v15 );
  v16 = *(int *)(a1 + 5300) - 1;
  v31 = *(short *)(a1 + 5300) - 1 + v5;
  do
  {
    *(int *)(a1 + 5300) = v16;
    v30 = *(int *)(a1 + 3012);
    *(int *)(a1 + 3012) = *(int *)(a1 + 4 * v16 + 3012);
    sub_B700(a1, (long long)v4, 1);
    v17 = *(int *)(a1 + 5304);
    v18 = *(int *)(a1 + 3012);
    v19 = (int *)(a1 + 4 * v17);
    v20 = *(int *)(a1 + 5304);
    v19[751] = v30;
    v21 = &v4[2 * v18];
    *(int *)(a1 + 5304) = v17 - 2;
    v22 = &v4[2 * v30];
    v19[750] = v18;
    v4[2 * v7] = *v22 + *v21;
    v23 = *(char *)(a1 + v30 + 5308);
    v24 = *(char *)(a1 + v18 + 5308);
    v25 = v24 + 1;
    if ( v23 >= v24 )
      v25 = v23 + 1;
    *(char *)(a1 + v7 + 5308) = v25;
    v26 = v31 - v16--;
    v21[1] = v26;
    v22[1] = v26;
    *(int *)(a1 + 3012) = v7++;
    sub_B700(a1, (long long)v4, 1);
  }
  while ( (int)v16 + 1 > 1 );
  v27 = *(int *)(a1 + 3012);
  *(int *)(a1 + 5304) = v20 - 3;
  v19[749] = v27;
  sub_B7F0(a1, (long long *)a2);
  return sub_C860(v4, v29, a1 + 2976);
}


// Function: build_bl_tree @ 0xcbc0
long long build_bl_tree(long long a1)
{
  long long v1; // rax
  long long i; // rdx
  unsigned int v3; // r8d
  long long v4; // rdx

  sub_BA40((short *)a1, a1 + 212, *(int *)(a1 + 2912));
  sub_BA40((short *)a1, a1 + 2504, *(int *)(a1 + 2936));
  sub_C900(a1, a1 + 2952);
  v1 = 18;
  for ( i = 15; ; i = *((unsigned char *)&unk_10900 + v1) )
  {
    v3 = v1;
    if ( *(short *)(a1 + 4 * i + 2750) )
      break;
    if ( --v1 == 2 )
    {
      v4 = 9;
      v3 = 2;
      goto LABEL_6;
    }
  }
  v4 = 3LL * ((int)v1 + 1);
LABEL_6:
  *(long long *)(a1 + 5912) += v4 + 14;
  return v3;
}


// Function: bi_flush @ 0xcc60
long long bi_flush(long long a1)
{
  long long result; // rax
  short v2; // cx
  long long v3; // rdx
  long long v4; // rax
  short v5; // cx
  long long v6; // rdx
  long long v7; // rax
  long long v8; // rdx

  result = *(unsigned int *)(a1 + 5940);
  if ( (int)result == 16 )
  {
    v4 = *(long long *)(a1 + 40);
    v5 = *(short *)(a1 + 5936);
    v6 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v4 + 1;
    *(char *)(v6 + v4) = v5;
    v7 = *(long long *)(a1 + 40);
    LOBYTE(v5) = *(char *)(a1 + 5937);
    v8 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v7 + 1;
    *(char *)(v8 + v7) = v5;
    *(short *)(a1 + 5936) = 0;
    *(int *)(a1 + 5940) = 0;
    return 0;
  }
  else if ( (int)result > 7 )
  {
    result = *(long long *)(a1 + 40);
    v2 = *(short *)(a1 + 5936);
    v3 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = result + 1;
    *(char *)(v3 + result) = v2;
    *(int *)(a1 + 5940) -= 8;
    *(short *)(a1 + 5936) >>= 8;
  }
  return result;
}


// Function: bi_windup @ 0xccf0
long long bi_windup(long long a1)
{
  int v1; // eax
  long long v2; // rax
  long long v3; // rdx
  short v4; // cx
  long long v5; // rax
  long long v6; // rdx

  v1 = *(int *)(a1 + 5940);
  if ( v1 <= 8 )
  {
    if ( v1 <= 0 )
      goto LABEL_4;
    v4 = *(short *)(a1 + 5936);
  }
  else
  {
    v2 = *(long long *)(a1 + 40);
    v4 = *(short *)(a1 + 5936);
    v3 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v2 + 1;
    *(char *)(v3 + v2) = v4;
    LOBYTE(v4) = *(char *)(a1 + 5937);
  }
  v5 = *(long long *)(a1 + 40);
  v6 = *(long long *)(a1 + 16);
  *(long long *)(a1 + 40) = v5 + 1;
  *(char *)(v6 + v5) = v4;
LABEL_4:
  *(int *)(a1 + 5940) = 0;
  *(short *)(a1 + 5936) = 0;
  return 0;
}


// Function: _tr_init @ 0xcd60
long long _tr_init(long long a1)
{
  *(int *)(a1 + 5940) = 0;
  *(long long *)(a1 + 2904) = a1 + 212;
  *(long long *)(a1 + 2920) = &off_16C60;
  *(long long *)(a1 + 2928) = a1 + 2504;
  *(long long *)(a1 + 2944) = &off_16C40;
  *(long long *)(a1 + 2952) = a1 + 2748;
  *(long long *)(a1 + 2968) = &unk_16C20;
  *(short *)(a1 + 5936) = 0;
  return sub_B660(a1);
}


// Function: _tr_stored_block @ 0xcdd0
char *_tr_stored_block(long long a1, long long a2, size_t a3, unsigned short a4)
{
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // esi
  short v9; // ax
  long long v10; // rcx
  long long v11; // rsi
  long long v12; // rax
  long long v13; // rcx
  const void *v14; // r8
  long long v15; // rax
  long long v16; // rdx
  long long v17; // rax
  long long v18; // rdx
  long long v19; // rax
  long long v20; // rdx
  char *result; // rax
  long long v22; // rdx

  v5 = a4;
  v6 = a4;
  v7 = *(int *)(a1 + 5940);
  v8 = v7 + 3;
  v9 = *(short *)(a1 + 5936) | (v6 << v7);
  if ( v7 > 13 )
  {
    v10 = *(long long *)(a1 + 40);
    v11 = *(long long *)(a1 + 16);
    *(short *)(a1 + 5936) = v9;
    *(long long *)(a1 + 40) = v10 + 1;
    *(char *)(v11 + v10) = v9;
    v12 = *(long long *)(a1 + 40);
    LOBYTE(v11) = *(char *)(a1 + 5937);
    v13 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v12 + 1;
    *(char *)(v13 + v12) = v11;
    LODWORD(v11) = *(int *)(a1 + 5940);
    LOBYTE(v13) = 16 - v11;
    v8 = v11 - 13;
    v9 = v5 >> v13;
  }
  *(short *)(a1 + 5936) = v9;
  *(int *)(a1 + 5940) = v8;
  sub_CCF0(a1);
  v15 = *(long long *)(a1 + 40);
  v16 = *(long long *)(a1 + 16);
  *(long long *)(a1 + 40) = v15 + 1;
  *(char *)(v16 + v15) = a3;
  v17 = *(long long *)(a1 + 40);
  v18 = *(long long *)(a1 + 16);
  *(long long *)(a1 + 40) = v17 + 1;
  *(char *)(v18 + v17) = BYTE1(a3);
  v19 = *(long long *)(a1 + 40);
  v20 = *(long long *)(a1 + 16);
  *(long long *)(a1 + 40) = v19 + 1;
  *(char *)(v20 + v19) = ~(char)a3;
  result = *(char **)(a1 + 40);
  v22 = *(long long *)(a1 + 16);
  *(long long *)(a1 + 40) = result + 1;
  result[v22] = (unsigned short)~(short)a3 >> 8;
  if ( a3 )
  {
    result = memcpy((void *)(*(long long *)(a1 + 16) + *(long long *)(a1 + 40)), v14, a3);
    *(long long *)(a1 + 40) += a3;
  }
  else
  {
    *(long long *)(a1 + 40) = *(long long *)(a1 + 40);
  }
  return result;
}


// Function: _tr_align @ 0xcf00
long long _tr_align(long long a1)
{
  int v1; // ecx
  int v2; // edx
  int v3; // eax
  long long v4; // rdx
  long long v5; // rcx
  long long v6; // rax
  long long v7; // rdx
  int v8; // ecx
  long long v9; // rdx
  long long v10; // rcx
  long long v11; // rax
  long long v12; // rdx

  v1 = *(int *)(a1 + 5940);
  v2 = v1 + 3;
  LOWORD(v3) = *(short *)(a1 + 5936) | (2 << v1);
  if ( v1 > 13 )
  {
    v4 = *(long long *)(a1 + 40);
    v5 = *(long long *)(a1 + 16);
    *(short *)(a1 + 5936) = v3;
    *(long long *)(a1 + 40) = v4 + 1;
    *(char *)(v5 + v4) = v3;
    v6 = *(long long *)(a1 + 40);
    LOBYTE(v5) = *(char *)(a1 + 5937);
    v7 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v6 + 1;
    *(char *)(v7 + v6) = v5;
    LODWORD(v7) = *(int *)(a1 + 5940);
    LOBYTE(v5) = 16 - v7;
    v2 = v7 - 13;
    v3 = 2 >> v5;
  }
  *(short *)(a1 + 5936) = v3;
  v8 = v2 + 7;
  *(int *)(a1 + 5940) = v2;
  if ( v2 > 9 )
  {
    v9 = *(long long *)(a1 + 40);
    v10 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v9 + 1;
    *(char *)(v10 + v9) = v3;
    v11 = *(long long *)(a1 + 40);
    LOBYTE(v10) = *(char *)(a1 + 5937);
    v12 = *(long long *)(a1 + 16);
    *(long long *)(a1 + 40) = v11 + 1;
    *(char *)(v12 + v11) = v10;
    *(short *)(a1 + 5936) = 0;
    v8 = *(int *)(a1 + 5940) - 9;
  }
  *(int *)(a1 + 5940) = v8;
  return sub_CC60(a1);
}


// Function: _tr_flush_block @ 0xcfd0
long long _tr_flush_block(long long a1, long long a2, size_t a3, int a4)
{
  long long v8; // rsi
  int v9; // esi
  unsigned long long v10; // rdx
  unsigned long long v11; // rax
  long long v12; // rdi
  long long result; // rax
  int v14; // ecx
  short v15; // ax
  int v16; // edx
  int v17; // edi
  long long v18; // rcx
  short v19; // ax
  long long v20; // rdi
  long long v21; // rax
  long long v22; // rcx
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  short v27; // ax
  int v28; // edx
  int v29; // ecx
  int v30; // edx
  long long v31; // rsi
  int v32; // edi
  long long v33; // rcx
  short v34; // ax
  long long v35; // rax
  long long v36; // rcx

  if ( *(int *)(a1 + 196) <= 0 )
  {
    if ( a3 + 4 > a3 + 5 )
      goto LABEL_18;
    goto LABEL_6;
  }
  if ( *(int *)(*(long long *)a1 + 88LL) == 2 )
  {
    v8 = *(long long *)a1;
    *(int *)(v8 + 88) = sub_C7A0(a1);
  }
  sub_C900(a1, a1 + 2904);
  sub_C900(a1, a1 + 2928);
  v9 = sub_CBC0(a1);
  v10 = (unsigned long long)(*(long long *)(a1 + 5912) + 10LL) >> 3;
  v11 = (unsigned long long)(*(long long *)(a1 + 5920) + 10LL) >> 3;
  if ( v10 < v11 && *(int *)(a1 + 200) != 4 )
  {
    if ( a3 + 4 > v10 || !a2 )
    {
      v14 = *(int *)(a1 + 5940);
      v15 = *(short *)(a1 + 5936);
      v16 = (unsigned short)(a4 + 4);
      if ( v14 <= 13 )
      {
        v23 = v16 << v14;
        v24 = v14 + 3;
        LOWORD(v23) = v15 | v23;
      }
      else
      {
        v17 = v16 << v14;
        v18 = *(long long *)(a1 + 40);
        v19 = v17 | v15;
        v20 = *(long long *)(a1 + 16);
        *(short *)(a1 + 5936) = v19;
        *(long long *)(a1 + 40) = v18 + 1;
        *(char *)(v20 + v18) = v19;
        v21 = *(long long *)(a1 + 40);
        v22 = *(long long *)(a1 + 16);
        LOBYTE(v20) = *(char *)(a1 + 5937);
        *(long long *)(a1 + 40) = v21 + 1;
        *(char *)(v22 + v21) = v20;
        LODWORD(v21) = *(int *)(a1 + 5940);
        v23 = v16 >> (16 - v21);
        v24 = v21 - 13;
      }
      v25 = *(int *)(a1 + 2936);
      *(short *)(a1 + 5936) = v23;
      *(int *)(a1 + 5940) = v24;
      sub_C100(a1, *(int *)(a1 + 2912) + 1, v25 + 1, v9 + 1);
      sub_C380(a1, a1 + 212, a1 + 2504);
      v12 = a1;
      result = sub_B660(a1);
      if ( a4 )
        return sub_CCF0(v12);
      return result;
    }
    goto LABEL_7;
  }
  if ( a3 + 4 <= v11 )
  {
LABEL_6:
    if ( a2 )
    {
LABEL_7:
      sub_CDD0(a1, a2, a3, a4);
      goto LABEL_8;
    }
  }
LABEL_18:
  v26 = *(int *)(a1 + 5940);
  v27 = *(short *)(a1 + 5936);
  v28 = (unsigned short)(a4 + 2);
  if ( v26 > 13 )
  {
    v31 = *(long long *)(a1 + 16);
    v32 = v28 << v26;
    v33 = *(long long *)(a1 + 40);
    v34 = v32 | v27;
    *(short *)(a1 + 5936) = v34;
    *(long long *)(a1 + 40) = v33 + 1;
    *(char *)(v31 + v33) = v34;
    v35 = *(long long *)(a1 + 40);
    v36 = *(long long *)(a1 + 16);
    LOBYTE(v31) = *(char *)(a1 + 5937);
    *(long long *)(a1 + 40) = v35 + 1;
    *(char *)(v36 + v35) = v31;
    LODWORD(v35) = *(int *)(a1 + 5940);
    v30 = v28 >> (16 - v35);
    v29 = v35 - 13;
  }
  else
  {
    v30 = v28 << v26;
    v29 = v26 + 3;
    LOWORD(v30) = v27 | v30;
  }
  *(int *)(a1 + 5940) = v29;
  *(short *)(a1 + 5936) = v30;
  sub_C380(a1, (long long)&unk_10480, (long long)&unk_10400);
LABEL_8:
  v12 = a1;
  result = sub_B660(a1);
  if ( a4 )
    return sub_CCF0(v12);
  return result;
}


// Function: zcalloc @ 0xd360
void *zcalloc(long long a1, int a2, int a3)
{
  return malloc((unsigned int)(a3 * a2));
}


// Function: zcfree @ 0xd370
void zcfree(long long a1, void *a2)
{
  free(a2);
}


// Function: adler32_z @ 0xd470
unsigned long long adler32_z(int a1, unsigned char *a2, unsigned long long a3)
{
  unsigned char *v3; // rcx
  unsigned long long v4; // r15
  unsigned char *v5; // rsi
  long long v6; // rax
  long long v7; // r14
  long long v8; // rax
  long long v9; // r14
  long long v10; // r13
  long long v11; // r12
  long long v12; // rbp
  long long v13; // rbx
  long long v14; // r11
  long long v15; // r10
  long long v16; // r9
  long long v17; // r8
  long long v18; // rdi
  long long v19; // rcx
  long long v20; // rdx
  unsigned char *v21; // r9
  unsigned char *v23; // rdx
  unsigned long long v24; // rax
  long long v25; // rsi
  unsigned long long v26; // rdx
  unsigned long long v27; // rax
  long long v28; // rax
  long long v29; // r14
  long long v30; // rax
  long long v31; // r14
  long long v32; // r13
  long long v33; // r12
  long long v34; // rbp
  long long v35; // rbx
  long long v36; // r11
  long long v37; // r10
  long long v38; // r9
  long long v39; // r8
  long long v40; // rdi
  long long v41; // rsi
  long long v42; // rdx
  long long v43; // rax
  long long v44; // rdx
  unsigned long long v45; // rax
  long long v46; // rcx
  long long v47; // [rsp+0h] [rbp-60h]
  long long v48; // [rsp+0h] [rbp-60h]
  long long v49; // [rsp+8h] [rbp-58h]
  unsigned long long v50; // [rsp+10h] [rbp-50h]
  unsigned char *v51; // [rsp+18h] [rbp-48h]
  unsigned char *v52; // [rsp+18h] [rbp-48h]
  unsigned long long v53; // [rsp+20h] [rbp-40h]
  unsigned long long v54; // [rsp+28h] [rbp-38h]
  unsigned long long v55; // [rsp+28h] [rbp-38h]

  v3 = a2;
  v4 = (unsigned short)a1;
  v53 = a3;
  v50 = HIWORD(a1);
  if ( a3 == 1 )
  {
    v26 = (unsigned short)a1 + (unsigned long long)*a2;
    if ( v26 > 0xFFF0 )
      v26 -= 65521LL;
    v27 = v26 + HIWORD(a1);
    if ( v27 > 0xFFF0 )
      v27 = v26 + HIWORD(a1) - 65521;
    return v26 | (v27 << 16);
  }
  else if ( a2 )
  {
    if ( a3 > 0xF )
    {
      v51 = a2 + 5552;
      if ( a3 <= 0x15AF )
        goto LABEL_23;
      do
      {
        v5 = v51 - 5552;
        v54 = v53;
        v53 -= 5552LL;
        do
        {
          v6 = *v5;
          v7 = v5[1];
          v5 += 16;
          v8 = v4 + v6;
          v9 = v8 + v7;
          v10 = v9 + *(v5 - 14);
          v11 = v10 + *(v5 - 13);
          v12 = v11 + *(v5 - 12);
          v13 = v12 + *(v5 - 11);
          v14 = v13 + *(v5 - 10);
          v47 = *(v5 - 9) + v14;
          v15 = v47 + *(v5 - 8) + *(v5 - 7);
          v16 = v15 + *(v5 - 6);
          v17 = v16 + *(v5 - 5);
          v18 = v17 + *(v5 - 4);
          v19 = v18 + *(v5 - 3);
          v20 = v19 + *(v5 - 2);
          v4 = v20 + *(v5 - 1);
          v50 += v4 + v20 + v19 + v18 + v17 + v16 + v15 + v47 + *(v5 - 8) + v47 + v14 + v13 + v12 + v11 + v10 + v9 + v8;
          v3 = v51;
        }
        while ( v5 != v51 );
        v4 %= 0xFFF1u;
        v50 %= 0xFFF1u;
        v51 = v5 + 5552;
      }
      while ( v53 > 0x15AF );
      v21 = v5;
      if ( !v53 )
        return v4 | (v50 << 16);
      if ( v53 <= 0xF )
      {
        v43 = v54 - 5553;
      }
      else
      {
LABEL_23:
        v55 = (v53 - 16) >> 4;
        v52 = &v3[16 * v55 + 16];
        do
        {
          v28 = *v3;
          v29 = v3[1];
          v3 += 16;
          v30 = v4 + v28;
          v31 = v30 + v29;
          v32 = v31 + *(v3 - 14);
          v33 = v32 + *(v3 - 13);
          v34 = v33 + *(v3 - 12);
          v35 = v34 + *(v3 - 11);
          v36 = v35 + *(v3 - 10);
          v37 = v36 + *(v3 - 9);
          v38 = v37 + *(v3 - 8);
          v39 = v38 + *(v3 - 7);
          v48 = *(v3 - 6) + v39;
          v49 = v48 + *(v3 - 5);
          v40 = v49 + *(v3 - 4);
          v41 = v40 + *(v3 - 3);
          v42 = v41 + *(v3 - 2);
          v4 = v42 + *(v3 - 1);
          v50 += v4 + v42 + v41 + v40 + v49 + v48 + v39 + v38 + v37 + v36 + v35 + v34 + v33 + v32 + v31 + v30;
        }
        while ( v3 != v52 );
        v21 = v52;
        v43 = v53 - 16 * v55 - 17;
        if ( (v53 & 0xF) == 0 )
          goto LABEL_29;
      }
      v44 = (long long)&v21[v43 + 1];
      v45 = v50;
      do
      {
        v46 = *v21++;
        v4 += v46;
        v45 += v4;
      }
      while ( v21 != (unsigned char *)v44 );
      v50 = v45;
LABEL_29:
      v4 %= 0xFFF1u;
      v50 %= 0xFFF1u;
      return v4 | (v50 << 16);
    }
    if ( a3 )
    {
      v23 = &a2[a3];
      v24 = HIWORD(a1);
      do
      {
        v25 = *v3++;
        v4 += v25;
        v24 += v4;
      }
      while ( v3 != v23 );
      v50 = v24;
    }
    if ( v4 > 0xFFF0 )
      v4 -= 65521LL;
    return v4 | ((v50 % 0xFFF1) << 16);
  }
  else
  {
    return 1;
  }
}


// Function: adler32 @ 0xd8e0
unsigned long long adler32(int a1, unsigned char *a2, unsigned int a3)
{
  return sub_D470(a1, a2, a3);
}


// Function: multmodp @ 0xd910
long long multmodp(int a1, unsigned int a2)
{
  unsigned int v2; // r8d
  unsigned int i; // eax
  char v4; // cl

  v2 = 0;
  for ( i = 0x80000000; ; i >>= 1 )
  {
    if ( (a1 & i) != 0 )
    {
      v2 ^= a2;
      if ( (a1 & (i - 1)) == 0 )
        break;
    }
    v4 = a2;
    a2 >>= 1;
    if ( (v4 & 1) != 0 )
      a2 ^= 0xEDB88320;
  }
  return v2;
}


// Function: crc_word @ 0xd950
unsigned long long crc_word(unsigned long long a1)
{
  unsigned long long result; // rax
  int v2; // edx

  result = a1;
  v2 = 8;
  do
  {
    result = (result >> 8) ^ dword_12B60[(unsigned char)result];
    --v2;
  }
  while ( v2 );
  return result;
}


// Function: crc32_z @ 0xd9e0
long long crc32_z(int a1, long long *a2, unsigned long long a3)
{
  unsigned long long v3; // rax
  long long *v4; // r8
  unsigned long long v5; // rdi
  char *v6; // rsi
  unsigned long long v7; // rax
  unsigned char v8; // di
  unsigned long long v9; // rcx
  unsigned long long v10; // rax
  unsigned long long v11; // rcx
  unsigned long long v12; // rax
  unsigned long long v13; // rcx
  unsigned long long v14; // rax
  unsigned long long v15; // rdi
  char *v16; // rcx
  long long v18; // r13
  long long v19; // r9
  long long v20; // r10
  unsigned long long v21; // rbx
  long long v22; // r15
  int v23; // esi
  long long v24; // rdi
  unsigned long long v25; // rbp
  long long v26; // r14
  unsigned long long v27; // r11
  unsigned long long v28; // rdi
  unsigned long long v29; // r8
  unsigned long long v30; // r14
  char v31; // cl
  long long v32; // rax
  int v33; // eax
  long long v34; // r8
  int v35; // eax
  long long v36; // r8
  unsigned int v37; // eax
  int v38; // r10d
  long long v39; // r8
  unsigned int v40; // eax
  int v41; // r9d
  long long v42; // r8
  long long *v43; // [rsp+0h] [rbp-58h]
  unsigned long long v44; // [rsp+8h] [rbp-50h]
  unsigned long long v45; // [rsp+10h] [rbp-48h]
  unsigned long long v46; // [rsp+18h] [rbp-40h]
  long long *v47; // [rsp+20h] [rbp-38h]

  v45 = a3;
  if ( !a2 )
    return 0;
  v3 = a3;
  v4 = a2;
  v5 = (unsigned int)~a1;
  if ( a3 > 0x2E )
  {
    while ( ((unsigned char)v4 & 7) != 0 )
    {
      v4 = (long long *)((char *)v4 + 1);
      v5 = (v5 >> 8) ^ dword_12B60[(unsigned char)(*((char *)v4 - 1) ^ v5)];
      if ( !--v3 )
      {
        v45 = 0;
        v18 = (unsigned int)v5;
        v46 = -1;
        goto LABEL_14;
      }
    }
    v18 = (unsigned int)v5;
    v45 = v3 % 0x28;
    v46 = v3 / 0x28 - 1;
    if ( v3 / 0x28 == 1 )
    {
      LODWORD(v21) = 0;
      LODWORD(v22) = 0;
      goto LABEL_19;
    }
LABEL_14:
    v43 = v4;
    v19 = 0;
    v20 = 0;
    v47 = v4;
    v21 = 0;
    v22 = 0;
    v44 = v46;
    do
    {
      v23 = 1;
      v21 ^= v43[2];
      v24 = v43[3];
      v25 = v18 ^ *v43;
      v26 = v43[4];
      v27 = v22 ^ v43[1];
      v43 += 5;
      v28 = v20 ^ v24;
      v29 = v21;
      LODWORD(v18) = dword_10B60[(unsigned char)v25];
      v30 = v19 ^ v26;
      LODWORD(v22) = dword_10B60[(unsigned char)v27];
      LODWORD(v21) = dword_10B60[(unsigned char)v21];
      LODWORD(v20) = dword_10B60[(unsigned char)v28];
      LODWORD(v19) = dword_10B60[(unsigned char)v30];
      do
      {
        v31 = 8 * v23;
        v32 = v23++;
        v32 <<= 8;
        v18 = dword_10B60[v32 + (unsigned char)(v25 >> v31)] ^ (unsigned int)v18;
        v22 = dword_10B60[v32 + (unsigned char)(v27 >> v31)] ^ (unsigned int)v22;
        v21 = dword_10B60[v32 + (unsigned char)(v29 >> v31)] ^ (unsigned int)v21;
        v20 = dword_10B60[v32 + (unsigned char)(v28 >> v31)] ^ (unsigned int)v20;
        v19 = dword_10B60[(unsigned char)(v30 >> v31) + v32] ^ (unsigned int)v19;
      }
      while ( v23 != 8 );
      --v44;
    }
    while ( v44 );
    v5 = (unsigned int)v18;
    v4 = &v47[5 * v46];
LABEL_19:
    v33 = sub_D950(*v4 ^ v5);
    v35 = sub_D950(*(long long *)(v34 - 32) ^ (unsigned int)v22 ^ v33);
    v37 = sub_D950(*(long long *)(v36 - 24) ^ (unsigned int)v21 ^ v35);
    v40 = sub_D950(*(long long *)(v39 - 16) ^ v38 ^ v37);
    v5 = (unsigned int)sub_D950(*(long long *)(v42 - 8) ^ v41 ^ v40);
  }
  if ( v45 <= 7 )
  {
    v6 = v4;
  }
  else
  {
    v6 = &v4[((v45 - 8) >> 3) + 1];
    do
    {
      v7 = v5;
      v8 = *(char *)v4++ ^ v5;
      v9 = dword_12B60[v8] ^ (v7 >> 8);
      v10 = dword_12B60[(unsigned char)(*((char *)v4 - 7) ^ v9)] ^ (v9 >> 8);
      v11 = dword_12B60[(unsigned char)(*((char *)v4 - 6) ^ v10)] ^ (v10 >> 8);
      v12 = dword_12B60[(unsigned char)(*((char *)v4 - 5) ^ v11)] ^ (v11 >> 8);
      v13 = dword_12B60[(unsigned char)(*((char *)v4 - 4) ^ v12)] ^ (v12 >> 8);
      v14 = dword_12B60[(unsigned char)(*((char *)v4 - 3) ^ v13)] ^ (v13 >> 8);
      v15 = dword_12B60[(unsigned char)(*((char *)v4 - 2) ^ v14)] ^ (v14 >> 8);
      v5 = dword_12B60[(unsigned char)(*((char *)v4 - 1) ^ v15)] ^ (v15 >> 8);
    }
    while ( v4 != (long long *)v6 );
    v45 &= 7u;
  }
  if ( v45 )
  {
    v16 = &v6[v45];
    do
      v5 = (v5 >> 8) ^ dword_12B60[(unsigned char)(*v6++ ^ v5)];
    while ( v6 != v16 );
  }
  return v5 ^ 0xFFFFFFFF;
}


// Function: crc32 @ 0xdd50
long long crc32(int a1, long long *a2, unsigned int a3)
{
  return sub_D9E0(a1, a2, a3);
}


// Function: inflate_fast @ 0xdde0
long long inflate_fast(unsigned char **a1, int a2)
{
  unsigned char *v3; // r9
  unsigned char *v4; // r10
  long long v5; // rax
  unsigned char *v6; // rdi
  unsigned char *v7; // r14
  unsigned int v8; // r12d
  long long v9; // r8
  long long v10; // r13
  unsigned char *v11; // r15
  unsigned int v12; // edx
  int v13; // ebp
  unsigned long long v14; // rax
  unsigned char *v15; // r12
  unsigned char **v16; // rbp
  long long v17; // r10
  long long v18; // r11
  long long v19; // r10
  char v20; // cl
  unsigned long long i; // rcx
  char *v22; // r11
  int v23; // ecx
  char v24; // cl
  unsigned char *v25; // r10
  unsigned char **v26; // r11
  unsigned char v27; // r10
  long long v28; // rcx
  long long v29; // r11
  char *v30; // rbx
  int v31; // ecx
  char v32; // cl
  char v33; // r10
  int v34; // ecx
  unsigned int v35; // ecx
  int v36; // edx
  unsigned char *v37; // r9
  long long v38; // rsi
  long long result; // rax
  long long v40; // r10
  long long v41; // rbx
  long long v42; // r10
  char v43; // cl
  char v44; // bl
  unsigned int v45; // r10d
  char v46; // bl
  char v47; // cl
  int v48; // ecx
  long long v49; // r10
  int v50; // ebx
  unsigned char *v51; // rcx
  unsigned int v52; // r11d
  unsigned char v53; // r10
  unsigned int v54; // r10d
  long long v55; // rbx
  long long v56; // r10
  long long v57; // rax
  long long v58; // rbx
  long long v59; // rcx
  unsigned int v60; // r11d
  unsigned char *v61; // rcx
  unsigned char v62; // r10
  unsigned char *v63; // rbx
  unsigned char *v64; // r10
  long long v65; // r11
  unsigned int v66; // r11d
  long long v67; // rbx
  unsigned int v68; // r11d
  long long v69; // rbx
  long long v70; // r10
  unsigned int v71; // [rsp+0h] [rbp-88h]
  long long v72; // [rsp+8h] [rbp-80h]
  long long v73; // [rsp+10h] [rbp-78h]
  int v74; // [rsp+18h] [rbp-70h]
  unsigned char *v75; // [rsp+20h] [rbp-68h]
  unsigned int v76; // [rsp+28h] [rbp-60h]
  unsigned int v77; // [rsp+2Ch] [rbp-5Ch]
  int v78; // [rsp+30h] [rbp-58h]
  int v79; // [rsp+34h] [rbp-54h]
  long long v80; // [rsp+38h] [rbp-50h]
  int v81; // [rsp+40h] [rbp-48h]
  unsigned int v82; // [rsp+40h] [rbp-48h]
  long long v83; // [rsp+48h] [rbp-40h]
  unsigned long long v84; // [rsp+50h] [rbp-38h]

  v3 = *a1;
  v4 = a1[7];
  v5 = (unsigned int)(*((int *)a1 + 2) - 5);
  v6 = a1[3];
  v7 = &v3[v5];
  LODWORD(v5) = *((int *)a1 + 8);
  v8 = *((int *)v4 + 17);
  v9 = *((long long *)v4 + 13);
  v10 = *((long long *)v4 + 14);
  v11 = &v6[(unsigned int)(v5 - 257)];
  v74 = (int)v6 - (a2 - v5);
  v12 = *((int *)v4 + 22);
  v77 = *((int *)v4 + 16);
  v78 = *((int *)v4 + 15);
  v13 = v8 + v78;
  v73 = (unsigned int)((1 << *((int *)v4 + 31)) - 1);
  v80 = v8;
  v75 = (unsigned char *)*((long long *)v4 + 9);
  v14 = *((long long *)v4 + 10);
  v76 = v8;
  v15 = v4;
  v72 = (unsigned int)((1 << *((int *)v4 + 30)) - 1);
  v79 = v13;
  v16 = a1;
LABEL_2:
  if ( v12 <= 0xE )
  {
    v17 = v3[1];
    v18 = *v3;
    v3 += 2;
    v19 = v17 << ((unsigned char)v12 + 8);
    v20 = v12;
    v12 += 16;
    v14 += (v18 << v20) + v19;
  }
  for ( i = v14 & v72; ; i = *((unsigned short *)v22 + 1) + (unsigned long long)((unsigned int)v14 & ((1 << v24) - 1)) )
  {
    v22 = (char *)(v9 + 4 * i);
    v23 = (unsigned char)v22[1];
    v14 >>= v23;
    v12 -= v23;
    v24 = *v22;
    if ( !*v22 )
    {
      *v6++ = *((short *)v22 + 1);
LABEL_10:
      if ( v3 >= v7 || v6 >= v11 )
      {
        v25 = v15;
        v26 = v16;
        goto LABEL_24;
      }
      goto LABEL_2;
    }
    if ( (v24 & 0x10) != 0 )
      break;
    if ( (v24 & 0x40) != 0 )
    {
      v26 = v16;
      v25 = v15;
      if ( (v24 & 0x20) != 0 )
      {
        *((int *)v15 + 2) = 16191;
      }
      else
      {
        v16[6] = "invalid literal/length code";
        *((int *)v15 + 2) = 16209;
      }
      goto LABEL_24;
    }
  }
  v71 = *((unsigned short *)v22 + 1);
  v27 = *v22 & 0xF;
  if ( v27 )
  {
    if ( v27 > v12 )
    {
      v28 = *v3++;
      v29 = v28;
      LOBYTE(v28) = v12;
      v12 += 8;
      v14 += v29 << v28;
    }
    v12 -= v27;
    v71 += v14 & ~(-1 << v27);
    v14 >>= v27;
  }
  if ( v12 <= 0xE )
  {
    v40 = v3[1];
    v41 = *v3;
    v3 += 2;
    v42 = v40 << ((unsigned char)v12 + 8);
    v43 = v12;
    v12 += 16;
    v14 += (v41 << v43) + v42;
  }
  v30 = (char *)(v10 + 4 * (v14 & v73));
  v31 = (unsigned char)v30[1];
  v14 >>= v31;
  v12 -= v31;
  v32 = *v30;
  v33 = *v30;
  if ( (*v30 & 0x10) != 0 )
  {
LABEL_28:
    v81 = *((unsigned short *)v30 + 1);
    v44 = v33;
    v45 = v33 & 0xF;
    v46 = v44 & 0xF;
    if ( v45 > v12 )
    {
      v47 = v12 + 8;
      v14 += (unsigned long long)*v3 << v12;
      if ( v45 > v12 + 8 )
      {
        v65 = v3[1];
        v12 += 16;
        v3 += 2;
        v14 += v65 << v47;
      }
      else
      {
        ++v3;
        v12 += 8;
      }
    }
    v12 -= v45;
    v82 = v81 + (v14 & ~(-1 << v46));
    v14 >>= v46;
    v48 = (int)v6 - v74;
    if ( v82 <= (int)v6 - v74 )
    {
      v60 = v71;
      v61 = &v6[-v82];
      do
      {
        v62 = *v61;
        v63 = v61;
        v61 += 3;
        v60 -= 3;
        *v6 = v62;
        v6[1] = *(v61 - 2);
        v64 = v6;
        v6 += 3;
        *(v6 - 1) = *(v61 - 1);
      }
      while ( v60 > 2 );
      if ( v60 )
      {
        v6 = v64 + 4;
        v64[3] = v63[3];
        if ( v60 == 2 )
        {
          v6 = v64 + 5;
          v64[4] = v63[4];
        }
      }
    }
    else
    {
      v49 = v82 - v48;
      if ( v77 < (unsigned int)v49 && *((int *)v15 + 1786) )
      {
        v25 = v15;
        v26 = v16;
        v16[6] = "invalid distance too far back";
        *((int *)v15 + 2) = 16209;
        goto LABEL_24;
      }
      v50 = v48 - v82;
      if ( v76 )
      {
        if ( v76 >= (unsigned int)v49 )
        {
          v51 = &v75[v50 + v76];
          if ( v71 > (unsigned int)v49 )
          {
            v66 = v50 + v71;
            v67 = 0;
            do
            {
              v6[v67] = v51[v67];
              ++v67;
            }
            while ( v49 != v67 );
            v6 += v49;
            v71 = v66;
            v51 = &v6[-v82];
          }
        }
        else
        {
          v54 = v49 - v76;
          v51 = &v75[v50 + v79];
          if ( v71 > v54 )
          {
            v84 = v14;
            v71 += v76 + v50;
            v55 = v54 - 1;
            v56 = 0;
            v57 = v55;
            v83 = v55 + 1;
            do
            {
              v6[v56] = v51[v56];
              v58 = v56++;
            }
            while ( v57 != v58 );
            v14 = v84;
            v51 = v75;
            v6 += v83;
            if ( v76 < v71 )
            {
              v59 = 0;
              do
              {
                v6[v59] = v75[v59];
                ++v59;
              }
              while ( v80 != v59 );
              v6 += v80;
              v71 -= v76;
              v51 = &v6[-v82];
            }
          }
        }
      }
      else
      {
        v51 = &v75[v50 + v78];
        if ( v71 > (unsigned int)v49 )
        {
          v68 = v50 + v71;
          v69 = (unsigned int)v49;
          v70 = 0;
          do
          {
            v6[v70] = v51[v70];
            ++v70;
          }
          while ( v69 != v70 );
          v6 += v69;
          v71 = v68;
          v51 = &v6[-v82];
        }
      }
      v52 = v71;
      if ( v71 > 2 )
      {
        do
        {
          v53 = *v51;
          v51 += 3;
          v6 += 3;
          v52 -= 3;
          *(v6 - 3) = v53;
          *(v6 - 2) = *(v51 - 2);
          *(v6 - 1) = *(v51 - 1);
        }
        while ( v52 > 2 );
        v71 = v52;
      }
      if ( v71 )
      {
        *v6 = *v51;
        if ( v71 == 2 )
        {
          v6 += 2;
          *(v6 - 1) = v51[1];
        }
        else
        {
          ++v6;
        }
      }
    }
    goto LABEL_10;
  }
  while ( (v33 & 0x40) == 0 )
  {
    v30 = (char *)(v10 + 4 * (*((unsigned short *)v30 + 1) + (unsigned long long)((unsigned int)v14 & ((1 << v32) - 1))));
    v34 = (unsigned char)v30[1];
    v14 >>= v34;
    v12 -= v34;
    v32 = *v30;
    v33 = *v30;
    if ( (*v30 & 0x10) != 0 )
      goto LABEL_28;
  }
  v25 = v15;
  v26 = v16;
  v16[6] = "invalid distance code";
  *((int *)v15 + 2) = 16209;
LABEL_24:
  v35 = v12;
  v36 = v12 & 7;
  v26[3] = v6;
  v37 = &v3[-(v35 >> 3)];
  *v26 = v37;
  v38 = (unsigned int)v14 & ((1 << v36) - 1);
  *((int *)v26 + 2) = (int)v7 - (int)v37 + 5;
  result = (unsigned int)((int)v11 - (int)v6 + 257);
  *((int *)v26 + 8) = result;
  *((long long *)v25 + 10) = v38;
  *((int *)v25 + 22) = v36;
  return result;
}


