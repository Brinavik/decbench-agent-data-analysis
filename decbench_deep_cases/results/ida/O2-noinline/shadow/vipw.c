// Function: main @ 0x3d60
long long main(unsigned int a1, char **a2, char **a3)
{
  bool v3; // zf
  const char *v4; // rax
  char v5; // r15
  int v6; // eax
  char *v7; // rdi
  long long v8; // r13
  long long v9; // r12
  char *v10; // rax
  const char *v11; // r8
  char *v12; // rsi
  char *v14; // rdi
  char *v15; // rax
  char *v16; // rdi
  char *v17; // rax
  char *v18; // rdi
  char *v19; // rax
  bool v20; // [rsp+Fh] [rbp-39h]

  s1 = (char *)sub_4EE0(*a2);
  sub_5FD0(s1);
  sub_5FF0(stderr);
  setlocale(6, "");
  bindtextdomain("shadow", "/usr/share/locale");
  textdomain("shadow");
  sub_50D0("-R", a1, a2);
  v3 = strcmp(s1, "vigr") == 0;
  v4 = "vipw";
  if ( v3 )
    v4 = "vigr";
  v20 = !v3;
  v5 = 0;
  openlog(v4, 1, 80);
  while ( 2 )
  {
    v6 = getopt_long(a1, a2, "ghpqR:s", &longopts, 0);
    if ( v6 != -1 )
    {
      switch ( v6 )
      {
        case 'R':
          continue;
        case 'g':
          v20 = 0;
          continue;
        case 'h':
          sub_4160(0);
        case 'p':
          v20 = 1;
          continue;
        case 'q':
          byte_11958 = 1;
          continue;
        case 's':
          v5 = 1;
          continue;
        default:
          goto LABEL_22;
      }
    }
    break;
  }
  if ( optind != a1 )
LABEL_22:
    sub_4160(2);
  if ( v20 )
  {
    if ( v5 )
    {
      v14 = (char *)sub_73B0();
      sub_4630(v14);
      v8 = sub_6600(v14, sub_73F0);
      v9 = sub_73B0();
      v15 = dcgettext(
              0,
              "You have modified %s.\n"
              "You may need to modify %s for consistency.\n"
              "Please use the command '%s' to do so.\n",
              5);
      v11 = "vipw";
      v12 = v15;
    }
    else
    {
      v18 = (char *)((long long (*)(void))sub_6600)();
      sub_4630(v18);
      if ( !(unsigned char)sub_73C0(v18, sub_6610) )
        goto LABEL_15;
      v8 = sub_73B0();
      v9 = ((long long (*)(void))sub_6600)();
      v19 = dcgettext(
              0,
              "You have modified %s.\n"
              "You may need to modify %s for consistency.\n"
              "Please use the command '%s' to do so.\n",
              5);
      v11 = "vipw -s";
      v12 = v19;
    }
  }
  else if ( v5 )
  {
    v7 = (char *)sub_7140();
    sub_4630(v7);
    v8 = sub_59C0(v7, sub_7180);
    v9 = sub_7140();
    v10 = dcgettext(
            0,
            "You have modified %s.\nYou may need to modify %s for consistency.\nPlease use the command '%s' to do so.\n",
            5);
    v11 = "vigr";
    v12 = v10;
  }
  else
  {
    v16 = (char *)((long long (*)(void))sub_59C0)();
    sub_4630(v16);
    if ( !(unsigned char)sub_7150(v16, sub_59D0) )
      goto LABEL_15;
    v8 = sub_7140();
    v9 = ((long long (*)(void))sub_59C0)();
    v17 = dcgettext(
            0,
            "You have modified %s.\nYou may need to modify %s for consistency.\nPlease use the command '%s' to do so.\n",
            5);
    v11 = "vigr -s";
    v12 = v17;
  }
  __printf_chk(1, v12, v9, v8, v11);
LABEL_15:
  sub_5E10("passwd");
  sub_5E10("group");
  sub_6050(3);
  return 0;
}


// Function: usage @ 0x4160
void usage(int status)
{
  char *v1; // r13
  FILE *v2; // rbp
  char *v3; // rax
  char *v4; // rax
  char *v5; // rax
  char *v6; // rax
  char *v7; // rax
  char *v8; // rax
  char *v9; // rax
  char *v10; // rax

  v1 = s1;
  v2 = stderr;
  if ( !status )
    v2 = stdout;
  v3 = dcgettext(0, "Usage: %s [options]\n\nOptions:\n", 5);
  __fprintf_chk(stderr, 1, v3, v1);
  v4 = dcgettext(0, "  -g, --group                   edit group database\n", 5);
  fputs(v4, v2);
  v5 = dcgettext(0, "  -h, --help                    display this help message and exit\n", 5);
  fputs(v5, v2);
  v6 = dcgettext(0, "  -p, --passwd                  edit passwd database\n", 5);
  fputs(v6, v2);
  v7 = dcgettext(0, "  -q, --quiet                   quiet mode\n", 5);
  fputs(v7, v2);
  v8 = dcgettext(0, "  -R, --root CHROOT_DIR         directory to chroot into\n", 5);
  fputs(v8, v2);
  v9 = dcgettext(0, "  -s, --shadow                  edit shadow or gshadow database\n", 5);
  fputs(v9, v2);
  v10 = dcgettext(0, "\n", 5);
  fputs(v10, v2);
  exit(status);
}


// Function: create_backup_file @ 0x4290
int create_backup_file(FILE *stream, char *name, long long a3)
{
  __mode_t v5; // r14d
  FILE *v6; // rbp
  int v7; // edi
  int v8; // eax
  int result; // eax
  struct utimbuf v10; // [rsp+0h] [rbp-48h] BYREF
  unsigned long long v11; // [rsp+18h] [rbp-30h]

  v11 = __readfsqword(0x28u);
  v5 = umask(0x3Fu);
  v6 = fopen(name, "w");
  umask(v5);
  if ( !v6 )
    return -1;
  if ( fseeko(stream, 0, 0) )
    goto LABEL_16;
  while ( 1 )
  {
    v7 = getc(stream);
    if ( v7 == -1 )
      break;
    if ( putc(v7, v6) == -1 )
      goto LABEL_16;
  }
  if ( ferror(stream) || fflush(v6) || (v8 = fileno(v6), fsync(v8)) )
  {
LABEL_16:
    fclose(v6);
    unlink(name);
    return -1;
  }
  else if ( fclose(v6)
         || (v10.actime = *(long long *)(a3 + 72), v10.modtime = *(long long *)(a3 + 88), utime(name, &v10))
         || chmod(name, *(int *)(a3 + 24))
         || (result = chown(name, *(int *)(a3 + 28), *(int *)(a3 + 32))) != 0 )
  {
    unlink(name);
    return -1;
  }
  return result;
}


// Function: vipwexit @ 0x4400
void vipwexit(long long a1, int a2, int a3)
{
  int v4; // r13d
  char *v5; // rax
  char *v6; // r14
  char *v7; // r15
  char *v8; // rax
  long long v9; // rbx
  char *v10; // r12
  char *v11; // rax
  char *v12; // r15
  char *v13; // r14
  char *v14; // rax
  char *v15; // rax
  const char *v16; // r15
  char *v17; // rax
  char *v18; // r14

  v4 = *__errno_location();
  if ( byte_11968 )
  {
    v6 = name;
    if ( unlink(name) )
    {
      v7 = s1;
      v8 = dcgettext(0, "%s: failed to remove %s\n", 5);
      __fprintf_chk(stderr, 1, v8, v7, v6);
    }
  }
  if ( byte_11969 && !(unsigned int)qword_11960() )
  {
    v12 = name;
    v13 = s1;
    v14 = dcgettext(0, "%s: failed to unlock %s\n", 5);
    __fprintf_chk(stderr, 1, v14, v13, v12);
    v15 = setlocale(6, 0);
    v16 = name;
    if ( v15 && (v17 = strdup(v15), v16 = name, (v18 = v17) != 0) )
    {
      setlocale(6, "C");
      __syslog_chk(3, 1, "failed to unlock %s", v16);
      setlocale(6, v18);
      free(v18);
    }
    else
    {
      __syslog_chk(3, 1, "failed to unlock %s", v16);
    }
  }
  if ( a1 )
  {
    __fprintf_chk(stderr, 1, "%s: %s", s1);
    if ( !a2 )
    {
LABEL_7:
      fputs("\n", stderr);
      goto LABEL_8;
    }
  }
  else if ( !a2 )
  {
LABEL_8:
    if ( !byte_11958 )
    {
      v9 = qword_11978;
      v10 = s1;
      v11 = dcgettext(0, "%s: %s is unchanged\n", 5);
      __fprintf_chk(stdout, 1, v11, v10, v9);
    }
    exit(a3);
  }
  v5 = strerror(v4);
  __fprintf_chk(stderr, 1, ": %s", v5);
  goto LABEL_7;
}


// Function: vipwedit @ 0x4630
unsigned long long vipwedit(char *a1, unsigned int (*a2)(void), long long (*a3)(void))
{
  FILE *v4; // rax
  FILE *v5; // rbp
  __pid_t v6; // r12d
  __pid_t v7; // eax
  __pid_t v8; // ebp
  __pid_t v9; // ebx
  __pid_t v10; // eax
  short v11; // ax
  __pid_t v12; // eax
  int *v13; // rax
  char *v14; // rax
  __pid_t v15; // ebx
  size_t v16; // rbx
  size_t v17; // rax
  const char *v18; // rbp
  size_t v19; // rbx
  size_t v20; // rax
  int v21; // eax
  unsigned int v22; // ebx
  unsigned int v23; // ebp
  char *v24; // r12
  char *v25; // rax
  int *v26; // rax
  char *v27; // rax
  int *v28; // rax
  char *v29; // rax
  __pid_t v30; // eax
  unsigned int v31; // ebx
  int v32; // edx
  char *v33; // rax
  const char *v34; // r12
  char *v35; // rbp
  char *v37; // r12
  char *v38; // rbx
  char *v39; // rax
  char *v40; // rax
  const char *v41; // r12
  char *v42; // rax
  char *v43; // rbp
  int v44; // ebp
  char *v45; // rax
  int v46; // ebp
  char *v47; // rax
  char *v48; // r12
  char *v49; // rax
  int *v50; // rax
  char *v51; // rax
  char *v52; // r12
  char *v53; // rbx
  char *v54; // rax
  int *v55; // rax
  char *v56; // rax
  char *v57; // r12
  char *v58; // rbx
  char *v59; // rax
  char *v60; // r12
  char *v61; // rax
  const char *s; // [rsp+8h] [rbp-A90h]
  int stat_loc; // [rsp+2Ch] [rbp-A6Ch] BYREF
  sigset_t set; // [rsp+30h] [rbp-A68h] BYREF
  sigset_t oset; // [rsp+B0h] [rbp-9E8h] BYREF
  struct stat buf; // [rsp+130h] [rbp-968h] BYREF
  struct stat v68; // [rsp+1C0h] [rbp-8D8h] BYREF
  char v69[1024]; // [rsp+250h] [rbp-848h] BYREF
  char file[1032]; // [rsp+650h] [rbp-448h] BYREF
  unsigned long long v71; // [rsp+A58h] [rbp-40h]

  v71 = __readfsqword(0x28u);
  __snprintf_chk(v69, 1024, 1, 1024, "%s-", a1);
  __snprintf_chk(file, 1024, 1, 1024, "%s.edit", a1);
  qword_11960 = a3;
  qword_11978 = (long long)a1;
  name = file;
  if ( access(a1, 0) )
    goto LABEL_57;
  if ( !a2() )
  {
    v46 = *__errno_location();
    v47 = dcgettext(0, "Couldn't lock file", 5);
    sub_4400((long long)v47, v46, 5);
  }
  byte_11969 = 1;
  if ( stat(a1, &buf) || (v4 = fopen(a1, "r"), (v5 = v4) == 0) )
LABEL_57:
    sub_4400((long long)a1, 1, 1);
  if ( sub_4290(v4, file, (long long)&buf) )
  {
    v44 = *__errno_location();
    v45 = dcgettext(0, "Couldn't make backup", 5);
    sub_4400((long long)v45, v44, 1);
  }
  fclose(v5);
  byte_11968 = 1;
  s = getenv("VISUAL");
  if ( !s )
  {
    s = getenv("EDITOR");
    if ( !s )
      s = "vi";
  }
  v6 = tcgetpgrp(0);
  v7 = fork();
  v8 = v7;
  if ( v7 == -1 )
    sub_4400((long long)"fork", 1, 1);
  if ( !v7 )
  {
    if ( v6 != -1 )
    {
      v15 = getpid();
      setpgid(0, 0);
      while ( tcgetpgrp(0) != v15 )
        ;
    }
    v16 = strlen(s);
    v17 = strlen(file);
    v18 = (const char *)malloc(v16 + v17 + 2);
    v19 = strlen(s);
    v20 = strlen(file);
    __snprintf_chk(v18, v19 + v20 + 2, 1, -1, "%s %s", s, file);
    v21 = system(v18);
    stat_loc = v21;
    if ( v21 != -1 )
    {
      v22 = v21 & 0x7F;
      if ( (v21 & 0x7F) != 0 || (v23 = BYTE1(v21), !BYTE1(v21)) )
      {
        if ( (char)((v21 & 0x7F) + 1) > 1 )
        {
          v24 = s1;
          v25 = dcgettext(0, "%s: %s killed by signal %d\n", 5);
          __fprintf_chk(stderr, 1, v25, v24, s, v22);
          exit(1);
        }
        exit(0);
      }
      v60 = s1;
      v61 = dcgettext(0, "%s: %s returned with status %d\n", 5);
      __fprintf_chk(stderr, 1, v61, v60, s, v23);
      exit(BYTE1(stat_loc));
    }
    v55 = __errno_location();
    v56 = strerror(*v55);
    v57 = s1;
    v58 = v56;
    v59 = dcgettext(0, "%s: %s: %s\n", 5);
    __fprintf_chk(stderr, 1, v59, v57, s, v58);
    exit(1);
  }
  if ( v6 != -1 )
  {
    setpgid(v7, v7);
    tcsetpgrp(0, v8);
    sigemptyset(&set);
    sigaddset(&set, 22);
    sigprocmask(0, &set, &oset);
  }
  v9 = -1;
  signal(17, 0);
  while ( 1 )
  {
    v8 = waitpid(v8, &stat_loc, 2);
    if ( v8 == -1 )
    {
      if ( v6 != -1 )
        sigprocmask(2, &oset, 0);
      sub_4400((long long)s, 1, 1);
    }
    v11 = stat_loc;
    if ( (char)stat_loc != 127 )
      break;
    if ( v6 != -1 )
    {
      v9 = tcgetpgrp(0);
      if ( v9 == -1 )
      {
        v28 = __errno_location();
        v29 = strerror(*v28);
        __fprintf_chk(stderr, 1, "%s: %s: %s", s1, "tcgetpgrp", v29);
        if ( tcsetpgrp(0, v6) != -1 )
        {
          v30 = getpid();
          kill(v30, 19);
          goto LABEL_15;
        }
      }
      else if ( tcsetpgrp(0, v6) != -1 )
      {
        v10 = getpid();
        kill(v10, 19);
        if ( tcsetpgrp(0, v9) != -1 )
          goto LABEL_15;
LABEL_21:
        v13 = __errno_location();
        v14 = strerror(*v13);
        __fprintf_chk(stderr, 1, "%s: %s: %s", s1, "tcsetpgrp", v14);
        goto LABEL_15;
      }
      v26 = __errno_location();
      v27 = strerror(*v26);
      __fprintf_chk(stderr, 1, "%s: %s: %s", s1, "tcsetpgrp", v27);
    }
    v12 = getpid();
    kill(v12, 19);
    if ( v9 != -1 && tcsetpgrp(0, v9) == -1 )
      goto LABEL_21;
LABEL_15:
    killpg(v8, 18);
  }
  if ( v6 != -1 )
  {
    sigprocmask(2, &oset, 0);
    v11 = stat_loc;
  }
  v31 = v11 & 0x7F;
  if ( (v11 & 0x7F) == 0 )
  {
    v32 = HIBYTE(v11);
    if ( HIBYTE(v11) )
LABEL_62:
      sub_4400(0, 0, v32);
  }
  if ( (char)((v11 & 0x7F) + 1) > 1 )
  {
    v48 = s1;
    v49 = dcgettext(0, "%s: %s killed by signal %d\n", 5);
    __fprintf_chk(stderr, 1, v49, v48, s, v31);
    v32 = 1;
    goto LABEL_62;
  }
  if ( stat(file, &v68) )
    sub_4400((long long)file, 1, 1);
  if ( buf.st_mtim.tv_sec == v68.st_mtim.tv_sec )
    sub_4400(0, 0, 0);
  byte_11968 = 0;
  unlink(v69);
  link(a1, v69);
  if ( rename(file, a1) == -1 )
  {
    v50 = __errno_location();
    v51 = strerror(*v50);
    v52 = s1;
    v53 = v51;
    v54 = dcgettext(0, "%s: can't restore %s: %s (your changes are in %s)\n", 5);
    __fprintf_chk(stderr, 1, v54, v52, a1, v53, file, v54);
    sub_4400(0, 0, 1);
  }
  if ( !(unsigned int)a3() )
  {
    v37 = s1;
    v38 = name;
    v39 = dcgettext(0, "%s: failed to unlock %s\n", 5);
    __fprintf_chk(stderr, 1, v39, v37, v38);
    v40 = setlocale(6, 0);
    v41 = name;
    if ( v40 && (v42 = strdup(v40), v41 = name, (v43 = v42) != 0) )
    {
      setlocale(6, "C");
      __syslog_chk(3, 1, "failed to unlock %s", v41);
      setlocale(6, v43);
      free(v43);
    }
    else
    {
      __syslog_chk(3, 1, "failed to unlock %s", v41);
    }
  }
  v33 = setlocale(6, 0);
  v34 = name;
  if ( v33 && (v35 = strdup(v33)) != 0 )
  {
    setlocale(6, "C");
    __syslog_chk(6, 1, "file %s edited", v34);
    setlocale(6, v35);
    free(v35);
  }
  else
  {
    __syslog_chk(6, 1, "file %s edited", v34);
  }
  return v71 - __readfsqword(0x28u);
}


