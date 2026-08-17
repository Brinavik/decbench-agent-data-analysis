// Function: main @ 0x3be0
void main(int a1, const char **a2, char **a3)
{
  char *v3; // rdx
  __pid_t v4; // eax
  int v5; // edi

  ident = strrchr(*a2, 47);
  v3 = ident + 1;
  if ( !ident )
    v3 = (char *)*a2;
  ident = v3;
  v4 = getpid();
  byte_2E2E0 = 0;
  dword_51580 = v4;
  byte_E2E0 = 0;
  setlocale(6, "");
  sub_49C0(a1, (char **)a2);
  sub_8430();
  if ( (unsigned int)sub_64B0(s2, "/usr/local/etc/cron.allow", "/usr/local/etc/cron.deny") )
  {
    switch ( dword_4F328 )
    {
      case 0:
        goto LABEL_6;
      case 1:
        sub_40D0();
        v5 = 0;
        break;
      case 2:
        sub_4380();
        v5 = 0;
        break;
      case 3:
        sub_5820();
        v5 = 0;
        break;
      case 4:
        if ( (int)sub_53D0() >= 0 )
          goto LABEL_13;
        goto LABEL_6;
      case 5:
        if ( (int)sub_50E0() < 0 )
          goto LABEL_6;
        v5 = 0;
        break;
      case 6:
        if ( (int)sub_4820() < 0 )
          goto LABEL_6;
        v5 = 0;
        break;
      case 7:
        if ( (int)sub_47C0() >= 0 )
LABEL_13:
          v5 = 0;
        else
LABEL_6:
          v5 = 1;
        break;
      default:
        abort();
    }
    exit(v5);
  }
  __fprintf_chk(stderr, 1, "You (%s) are not allowed to use this program (%s)\n", s1, ident);
  __fprintf_chk(stderr, 1, "See crontab(1) for more information\n");
  sub_8720(s2, (unsigned int)dword_51580, "AUTH", "crontab command not allowed", 0);
  exit(1);
}


// Function: check_error @ 0x3e80
long long check_error(const char *a1)
{
  ++dword_4F334;
  return __fprintf_chk(stderr, 1, "\"%s\":%d: %s\n", filename, dword_4E2FC - 1, a1);
}


// Function: usage @ 0x3ec0
void usage(const char *a1)
{
  __fprintf_chk(stderr, 1, "%s: usage error: %s\n", ident, a1);
  __fprintf_chk(stderr, 1, "Usage:\n");
  __fprintf_chk(stderr, 1, " %s [options] file\n", ident);
  __fprintf_chk(stderr, 1, " %s [options]\n", ident);
  __fprintf_chk(stderr, 1, " %s -n [hostname]\n", ident);
  __fprintf_chk(stderr, 1, "\n");
  __fprintf_chk(stderr, 1, "Options:\n");
  __fprintf_chk(stderr, 1, " -u <user>  define user\n");
  __fprintf_chk(stderr, 1, " -e         edit user's crontab\n");
  __fprintf_chk(stderr, 1, " -l         list user's crontab\n");
  __fprintf_chk(stderr, 1, " -r         delete user's crontab\n");
  __fprintf_chk(stderr, 1, " -i         prompt before deleting\n");
  __fprintf_chk(stderr, 1, " -n <host>  set host in cluster to run users' crontabs\n");
  __fprintf_chk(stderr, 1, " -c         get host in cluster to run users' crontabs\n");
  __fprintf_chk(stderr, 1, " -T <file>  test a crontab file syntax\n");
  __fprintf_chk(stderr, 1, " -V         print version and exit\n");
  __fprintf_chk(stderr, 1, " -x <mask>  enable debugging\n");
  __fprintf_chk(stderr, 1, "\nDefault operation is replace, per 1003.2\n");
  exit(1);
}


// Function: list_cmd @ 0x40d0
unsigned long long list_cmd()
{
  long long v0; // r12
  FILE *v1; // rbp
  int v2; // r13d
  long long v3; // rbx
  int v4; // r15d
  int v5; // ebx
  char v7[24]; // [rsp+0h] [rbp-1048h] BYREF
  unsigned long long v8; // [rsp+1008h] [rbp-40h]

  v8 = __readfsqword(0x28u);
  LODWORD(v0) = isatty(1);
  if ( (int)v0 )
    v0 = getenv("NO_COLOR") == 0;
  sub_8720(s2, (unsigned int)dword_51580, "LIST", s1, 0);
  if ( !(unsigned int)sub_8130(v7, 4096, "/usr/local/var/spool/cron", s1, 47) )
  {
    __fprintf_chk(stderr, 1, "path too long\n");
    exit(1);
  }
  v1 = fopen(v7, "r");
  if ( !v1 )
  {
    if ( *__errno_location() == 2 )
      __fprintf_chk(stderr, 1, "no crontab for %s\n", s1);
    else
      perror(v7);
    exit(1);
  }
  if ( (dword_E2C0 & 9) != 0 )
    __printf_chk(1, "linenum=%d\n", 1);
  v2 = 0;
  LODWORD(v3) = 1;
  dword_4E2FC = 1;
  while ( 1 )
  {
    v4 = sub_8570(v1);
    if ( v4 == -1 )
      break;
    if ( (int)v0 )
    {
      v5 = !v2 && v3;
      if ( v5 )
      {
        v2 = 0;
        if ( v4 == 35 )
        {
          v2 = v5;
          fputs("\x1B[34;1m", stdout);
        }
      }
      else if ( v4 == 10 && v2 )
      {
        v2 = 0;
        fputs("\x1B[0m", stdout);
      }
    }
    putchar(v4);
    v3 = v4 == 10;
  }
  if ( (unsigned int)v0 & !v3 )
  {
    putchar(10);
    fputs("\x1B[31;1mNo end-of-line character at the end of file\x1B[0m", stdout);
    putchar(10);
  }
  fclose(v1);
  return v8 - __readfsqword(0x28u);
}


// Function: poke_daemon @ 0x4330
void poke_daemon()
{
  if ( utime("/usr/local/var/spool/cron", 0) < 0 )
  {
    __fprintf_chk(stderr, 1, "crontab: can't update mtime on spooldir\n");
    perror("/usr/local/var/spool/cron");
  }
}


// Function: delete_cmd @ 0x4380
unsigned long long delete_cmd()
{
  _OWORD v1[256]; // [rsp+0h] [rbp-1028h] BYREF
  unsigned long long v2; // [rsp+1008h] [rbp-20h]

  v2 = __readfsqword(0x28u);
  memset(v1, 0, sizeof(v1));
  if ( dword_4F330 == 1 )
  {
    __printf_chk(1, "crontab: really delete %s's crontab? ", s1);
    fflush(stdout);
    if ( !fgets((char *)v1, 4095, stdin) || (v1[0] & 0xDF) != 0x59 )
      exit(0);
  }
  sub_8720(s2, (unsigned int)dword_51580, "DELETE", s1, 0);
  if ( !(unsigned int)sub_8130(v1, 4096, "/usr/local/var/spool/cron", s1, 47) )
  {
    __fprintf_chk(stderr, 1, "path too long\n");
    exit(1);
  }
  if ( unlink((const char *)v1) )
  {
    if ( *__errno_location() == 2 )
      __fprintf_chk(stderr, 1, "no crontab for %s\n", s1);
    else
      perror((const char *)v1);
    exit(1);
  }
  sub_4330();
  return v2 - __readfsqword(0x28u);
}


// Function: tmp_path @ 0x4500
char *tmp_path()
{
  __uid_t v0; // ebx
  char *result; // rax
  __gid_t v2; // ebx

  v0 = getuid();
  if ( v0 != geteuid() )
    return "/tmp";
  v2 = getgid();
  if ( v2 != getegid() )
    return "/tmp";
  result = getenv("TMPDIR");
  if ( !result )
    return "/tmp";
  return result;
}


// Function: die @ 0x4540
void die()
{
  if ( old )
    unlink(&old);
  _exit(1);
}


// Function: check_syntax @ 0x4570
// positive sp value has been detected, the output may be wrong!
long long check_syntax(long long a1)
{
  long long v2; // rax
  void *v3; // r12
  int v4; // ebp
  int v5; // r13d
  int v6; // eax
  void *v7; // rdi
  char v9; // [rsp-10h] [rbp-20038h] BYREF
  char v10; // [rsp+0h] [rbp-20028h] BYREF
  long long v11[15877]; // [rsp+1000h] [rbp-1F028h] BYREF

  while ( &v10 != (char *)&v11[-16384] )
    ;
  v11[15871] = __readfsqword(0x28u);
  v2 = sub_7800();
  dword_4F334 = 0;
  v3 = (void *)v2;
  if ( (dword_E2C0 & 9) != 0 )
    __printf_chk(1, "linenum=%d\n", 1);
  dword_4E2FC = 1;
  if ( !v3 )
  {
    __fprintf_chk(stderr, 1, "%s: Cannot allocate memory.\n", ident);
    return 4294967294LL;
  }
  v4 = dword_4F334;
  v5 = 0;
  if ( dword_4F334 )
  {
    sub_7830(v3);
    return (unsigned int)-(dword_4F334 != 0);
  }
  while ( 1 )
  {
    if ( !(unsigned int)((long long (*)(long long))sub_8690)(a1) )
    {
      sub_3E80("too much non-parseable content (comments, empty lines, spaces)");
      goto LABEL_19;
    }
    v6 = ((long long (*)(char *, long long))sub_7B20)(&v9, a1);
    if ( !v6 )
    {
      v7 = (void *)((long long (*)(long long, long long (*)(const char *), long long, void *))sub_6D50)(
                     a1,
                     sub_3E80,
                     qword_4F320,
                     v3);
      if ( v7 )
      {
        ++v5;
        sub_6D20(v7);
      }
      goto LABEL_8;
    }
    if ( v6 == 1 )
    {
      ++v4;
      goto LABEL_8;
    }
    if ( v6 == -1 )
      break;
LABEL_8:
    if ( dword_4F334 )
      goto LABEL_19;
  }
  if ( v9 )
  {
    if ( (dword_E2C0 & 9) != 0 )
      __printf_chk(1, "linenum=%d\n", dword_4E2FC + 1);
    ++dword_4E2FC;
    sub_3E80("premature EOF");
  }
LABEL_19:
  sub_7830(v3);
  if ( v4 > 1000 )
  {
    __fprintf_chk(stderr, 1, "There are too many environment variables in the crontab file. Limit: %d\n", 1000);
  }
  else
  {
    if ( v5 <= 10000 )
      return (unsigned int)-(dword_4F334 != 0);
    __fprintf_chk(stderr, 1, "There are too many entries in the crontab file. Limit: %d\n", 10000);
  }
  return 0xFFFFFFFFLL;
}


// Function: test_cmd @ 0x47c0
long long test_cmd()
{
  if ( (int)sub_4570((long long)stream) < 0 )
  {
    __fprintf_chk(stderr, 1, "Invalid crontab file. Syntax issues were found.\n");
    return 4294967294LL;
  }
  else
  {
    __fprintf_chk(stderr, 1, "No syntax issues were found in the crontab file.\n");
    return 0;
  }
}


// Function: hostget_cmd @ 0x4820
long long hostget_cmd()
{
  FILE *v0; // rax
  FILE *v1; // rbp
  char v3[16]; // [rsp+0h] [rbp-1028h] BYREF
  unsigned long long v4; // [rsp+1008h] [rbp-20h]

  v4 = __readfsqword(0x28u);
  if ( (unsigned int)sub_8130(v3, 4096, "/usr/local/var/spool/cron", ".cron.hostname", 47) )
  {
    v0 = fopen(v3, "r");
    v1 = v0;
    if ( v0 )
    {
      if ( (unsigned int)sub_8620(byte_4F340, 64, v0, "\n") == -1 )
      {
        __fprintf_chk(stderr, 1, "Error reading from %s\n", v3);
        fclose(v1);
        return 4294967294LL;
      }
      else
      {
        fclose(v1);
        __printf_chk(1, "%s\n", byte_4F340);
        fflush(stdout);
        sub_8720(s2, (unsigned int)dword_51580, "GET HOST", byte_4F340, 0);
        return 0;
      }
    }
    else
    {
      if ( *__errno_location() == 2 )
        __fprintf_chk(stderr, 1, "File %s not found\n", v3);
      else
        perror(v3);
      return 4294967294LL;
    }
  }
  else
  {
    __fprintf_chk(stderr, 1, "path too long\n");
    return 4294967294LL;
  }
}


// Function: parse_args @ 0x49c0
unsigned long long parse_args(int argc, char **argv)
{
  __uid_t v3; // eax
  struct passwd *v4; // rax
  const char *pw_name; // r13
  int v6; // eax
  char *v7; // rsi
  char *v8; // r12
  int v9; // ebx
  int v10; // ebx
  const char *v12; // r12
  int v13; // eax
  struct stat buf; // [rsp+10h] [rbp-D8h] BYREF
  unsigned long long v15; // [rsp+A8h] [rbp-40h]

  v15 = __readfsqword(0x28u);
  v3 = getuid();
  v4 = getpwuid(v3);
  qword_4F320 = (long long)v4;
  if ( !v4 )
  {
    __fprintf_chk(stderr, 1, "%s: your UID isn't in the passwd file.\n", ident);
    __fprintf_chk(stderr, 1, "bailing out.\n");
    goto LABEL_60;
  }
  pw_name = v4->pw_name;
  if ( strlen(v4->pw_name) > 0xFF )
  {
    __fprintf_chk(stderr, 1, "username too long\n");
    goto LABEL_60;
  }
  __strcpy_chk(s1, pw_name, 256);
  __strcpy_chk(s2, s1, 256);
  filename[0] = 0;
  dword_4F328 = 0;
  dword_4F330 = 0;
  dword_4F32C = 0;
  while ( 1 )
  {
    v6 = getopt(argc, argv, "u:lerincx:VT");
    if ( v6 == -1 )
      break;
    switch ( v6 )
    {
      case 'T':
        if ( dword_4F328 )
          goto LABEL_58;
        dword_4F328 = 7;
        continue;
      case 'V':
        puts("cronie 1.6.1");
        exit(0);
      case 'c':
        if ( dword_4F328 )
          goto LABEL_58;
        if ( strcmp(s1, s2) )
          goto LABEL_59;
        dword_4F328 = 6;
        continue;
      case 'e':
        if ( dword_4F328 )
          goto LABEL_58;
        dword_4F328 = 3;
        continue;
      case 'i':
        dword_4F330 = 1;
        continue;
      case 'l':
        if ( dword_4F328 )
          goto LABEL_58;
        dword_4F328 = 1;
        continue;
      case 'n':
        if ( getuid() )
        {
          __fprintf_chk(stderr, 1, "must be privileged to set host with -n\n");
          goto LABEL_60;
        }
        if ( dword_4F328 )
LABEL_58:
          sub_3EC0("only one operation permitted");
        if ( strcmp(s1, s2) )
        {
LABEL_59:
          __fprintf_chk(stderr, 1, "cannot use -u with -n or -c\n");
          goto LABEL_60;
        }
        dword_4F328 = 5;
        continue;
      case 'r':
        if ( dword_4F328 )
          goto LABEL_58;
        dword_4F328 = 2;
        continue;
      case 'u':
        if ( getuid() )
        {
          __fprintf_chk(stderr, 1, "must be privileged to use -u\n");
LABEL_60:
          exit(1);
        }
        if ( (unsigned int)(dword_4F328 - 5) <= 2 )
        {
          __fprintf_chk(stderr, 1, "cannot use -u with -n, -c or -T\n");
          goto LABEL_60;
        }
        qword_4F320 = (long long)getpwnam(optarg);
        if ( !qword_4F320 )
        {
          __fprintf_chk(stderr, 1, "%s:  user `%s' unknown\n", ident, optarg);
          exit(1);
        }
        v7 = optarg;
        if ( strlen(optarg) > 0xFF )
          sub_3EC0("username too long");
        __strcpy_chk(s1, v7, 256);
        break;
      case 'x':
        if ( !(unsigned int)sub_8280(optarg) )
          sub_3EC0("bad debug option");
        continue;
      default:
        sub_3EC0("unrecognized option");
    }
  }
  endpwent();
  if ( dword_4F328 != 5 )
  {
    if ( dword_4F328 )
    {
      if ( dword_4F328 != 4 && dword_4F328 != 7 )
        goto LABEL_47;
    }
    else
    {
      dword_4F328 = 4;
    }
    v8 = argv[optind];
    v9 = optind;
    if ( v8 )
    {
      if ( strlen(argv[optind]) > 0xFFF )
        sub_3EC0("filename too long");
      v10 = v9 + 1;
      __strcpy_chk(filename, v8, 4096);
      optind = v10;
      goto LABEL_35;
    }
    if ( isatty(0) )
      sub_3EC0("file name or - (for stdin) must be specified");
    strcpy(filename, "-");
LABEL_47:
    v10 = optind;
    goto LABEL_35;
  }
  v12 = argv[optind];
  v10 = optind;
  if ( v12 )
  {
    dword_4F32C = 1;
    if ( strlen(v12) > 0x3F )
      sub_3EC0("hostname too long");
    ++v10;
    __strcpy_chk(byte_4F340, v12, 64);
    optind = v10;
  }
LABEL_35:
  if ( argv[v10] )
    sub_3EC0("no arguments permitted after this option");
  if ( filename[0] )
  {
    if ( !strcmp(filename, "-") )
    {
      stream = stdin;
    }
    else
    {
      if ( (int)sub_8D30() < 0 )
      {
        perror("swapping uids");
        exit(1);
      }
      stream = fopen(filename, "r");
      if ( !stream || (v13 = fileno(stream), fstat(v13, &buf) < 0) )
      {
        perror(filename);
        exit(1);
      }
      if ( (buf.st_mode & 0xF000) == 0x4000 )
      {
        __fprintf_chk(stderr, 1, "invalid crontab file: '%s' is a directory\n", filename);
        fclose(stream);
        exit(1);
      }
      if ( (int)sub_8D80() < 0 )
      {
        perror("swapping uids back");
        exit(1);
      }
    }
  }
  if ( (dword_E2C0 & 0x20) != 0 )
    return __printf_chk(1, "user=%s, file=%s, option=%s\n", s1, filename, off_DA40[dword_4F328]);
  else
    return v15 - __readfsqword(0x28u);
}


// Function: hostset_cmd @ 0x50e0
long long hostset_cmd()
{
  long long v0; // rcx
  int v1; // eax
  int v2; // ebp
  FILE *v3; // r12
  unsigned int v4; // r12d
  char v6[16]; // [rsp+0h] [rbp-1038h] BYREF
  unsigned long long v7; // [rsp+1008h] [rbp-30h]

  v7 = __readfsqword(0x28u);
  if ( !dword_4F32C )
    gethostname(byte_4F340, 0x40u);
  v0 = sub_5010();
  if ( !v0 || !(unsigned int)sub_8130(&old, 4096, "/usr/local/var/spool/cron", v0, 47) )
  {
    old = 0;
    v4 = -2;
    __fprintf_chk(stderr, 1, "path too long\n", v0);
    return v4;
  }
  v1 = mkstemp(&old);
  v2 = v1;
  if ( v1 == -1 )
  {
    perror(&old);
LABEL_20:
    old = 0;
    return (unsigned int)-2;
  }
  v3 = fdopen(v1, "w");
  if ( !v3 )
  {
    perror(&old);
    close(v2);
    unlink(&old);
    goto LABEL_20;
  }
  signal(1, (__sighandler_t)handler);
  signal(2, (__sighandler_t)handler);
  signal(3, (__sighandler_t)handler);
  fchmod(v2, 0x180u);
  if ( (int)__fprintf_chk(v3, 1, "%s\n", byte_4F340) < 0 || fclose(v3) == -1 )
  {
    v4 = -2;
    __fprintf_chk(stderr, 1, "%s: error while writing to %s\n", ident, &old);
  }
  else if ( (unsigned int)sub_8130(v6, 4096, "/usr/local/var/spool/cron", ".cron.hostname", 47) )
  {
    v4 = rename(&old, v6);
    if ( v4 )
    {
      v4 = -2;
      __fprintf_chk(stderr, 1, "%s: error renaming %s to %s\n", ident, &old, v6);
      perror("rename");
    }
    else
    {
      old = 0;
      sub_8720(s2, (unsigned int)dword_51580, "SET HOST", byte_4F340, 0);
      sub_4330();
    }
  }
  else
  {
    v4 = -2;
    __fprintf_chk(stderr, 1, "path too long\n");
  }
  signal(1, 0);
  signal(2, 0);
  signal(3, 0);
  if ( old )
  {
    unlink(&old);
    old = 0;
  }
  return v4;
}


// Function: replace_cmd @ 0x53d0
long long replace_cmd()
{
  long long v0; // rax
  int v1; // eax
  int v2; // r12d
  FILE *v3; // rbp
  int v4; // edi
  __off_t v5; // r12
  int v6; // eax
  int v7; // r12d
  int v9; // eax
  __gid_t v10; // ebx
  __uid_t v11; // r15d
  int v12; // eax
  __gid_t v13; // ebx
  char v14[24]; // [rsp+0h] [rbp-1048h] BYREF
  unsigned long long v15; // [rsp+1008h] [rbp-40h]

  v15 = __readfsqword(0x28u);
  v0 = sub_5010();
  if ( !v0 || !(unsigned int)sub_8130(&old, 4096, "/usr/local/var/spool/cron", v0, 47) )
  {
    old = 0;
    v7 = -2;
    __fprintf_chk(stderr, 1, "path too long\n");
    return (unsigned int)v7;
  }
  v1 = mkstemp(&old);
  v2 = v1;
  if ( v1 == -1 )
  {
    perror(&old);
LABEL_35:
    old = 0;
    return (unsigned int)-2;
  }
  v3 = fdopen(v1, "w+");
  if ( !v3 )
  {
    perror(&old);
    close(v2);
    unlink(&old);
    goto LABEL_35;
  }
  signal(1, (__sighandler_t)handler);
  signal(2, (__sighandler_t)handler);
  signal(3, (__sighandler_t)handler);
  rewind(stream);
  if ( (dword_E2C0 & 9) != 0 )
    __printf_chk(1, "linenum=%d\n", 1);
  dword_4E2FC = 1;
  while ( 1 )
  {
    v4 = sub_8570(stream);
    if ( v4 == -1 )
      break;
    putc(v4, v3);
  }
  v5 = ftell(v3);
  v6 = fileno(v3);
  if ( ftruncate(v6, v5) == -1 || ferror(v3) || fflush(v3) || (v9 = fileno(v3), fsync(v9)) )
  {
    v7 = -2;
    __fprintf_chk(stderr, 1, "%s: error while writing new crontab to %s\n", ident, &old);
    fclose(v3);
  }
  else
  {
    rewind(v3);
    v7 = sub_4570((long long)v3);
    if ( v7 < 0 )
    {
      __fprintf_chk(stderr, 1, "Invalid crontab file, can't install.\n");
      fclose(v3);
    }
    else
    {
      v10 = getgid();
      if ( v10 == geteuid() && (v13 = getgid(), v13 == getegid()) )
        v11 = 0;
      else
        v11 = *(int *)(qword_4F320 + 16);
      v12 = fileno(v3);
      if ( fchown(v12, v11, 0xFFFFFFFF) < 0 )
      {
        v7 = -2;
        perror("fchown");
        fclose(v3);
      }
      else if ( fclose(v3) == -1 )
      {
        v7 = -2;
        perror("fclose");
      }
      else if ( (unsigned int)sub_8130(v14, 4096, "/usr/local/var/spool/cron", s1, 47) )
      {
        if ( rename(&old, v14) )
        {
          v7 = -2;
          __fprintf_chk(stderr, 1, "%s: error renaming %s to %s\n", ident, &old, v14);
          perror("rename");
        }
        else
        {
          old = 0;
          sub_8720(s2, (unsigned int)dword_51580, "REPLACE", s1, 0);
          sub_4330();
        }
      }
      else
      {
        v7 = -2;
        __fprintf_chk(stderr, 1, "path too long\n");
      }
    }
  }
  signal(1, 0);
  signal(2, 0);
  signal(3, 0);
  if ( old )
  {
    unlink(&old);
    old = 0;
  }
  return (unsigned int)v7;
}


// Function: edit_cmd @ 0x5820
// positive sp value has been detected, the output may be wrong!
unsigned long long edit_cmd()
{
  const char *v0; // r12
  FILE *v1; // rbp
  char *v2; // rax
  int v3; // r12d
  int v4; // edi
  char *v5; // rax
  __pid_t v6; // eax
  __pid_t v7; // ebx
  int v8; // edi
  __pid_t v9; // eax
  int v10; // eax
  char *v11; // rax
  __gid_t v12; // eax
  __uid_t v13; // eax
  char *v14; // rax
  const char *v16; // rax
  long long v17; // [rsp-D0h] [rbp-21100h]
  int v18; // [rsp-BCh] [rbp-210ECh] BYREF
  struct utimbuf v19; // [rsp-B8h] [rbp-210E8h] BYREF
  struct stat v20; // [rsp-A8h] [rbp-210D8h] BYREF
  char v21[24]; // [rsp-18h] [rbp-21048h] BYREF
  char v22; // [rsp+0h] [rbp-21030h] BYREF
  char v23[24]; // [rsp+FE8h] [rbp-20048h] BYREF
  long long v24; // [rsp+1000h] [rbp-20030h] BYREF
  unsigned long long v25; // [rsp+20FF0h] [rbp-40h]

  while ( &v22 != (char *)(&v24 - 16896) )
    ;
  v25 = __readfsqword(0x28u);
  v0 = v21;
  sub_8720(s2, (unsigned int)dword_51580, "BEGIN EDIT", s1, 0);
  if ( !(unsigned int)sub_8130(v21, 4096, "/usr/local/var/spool/cron", s1, 47) )
    goto LABEL_66;
  v1 = fopen(v21, "r");
  if ( !v1 )
  {
    if ( *__errno_location() != 2 )
      goto LABEL_48;
    v0 = "/dev/null";
    __fprintf_chk(stderr, 1, "no crontab for %s - using an empty one\n", s1);
    v1 = fopen("/dev/null", "r");
    if ( !v1 )
      goto LABEL_48;
  }
  signal(1, (__sighandler_t)((char *)&dword_0 + 1));
  signal(2, (__sighandler_t)((char *)&dword_0 + 1));
  signal(3, (__sighandler_t)((char *)&dword_0 + 1));
  v2 = sub_4500();
  if ( !(unsigned int)sub_8130(filename, 4096, v2, "crontab.XXXXXX", 47) )
  {
LABEL_66:
    __fprintf_chk(stderr, 1, "path too long\n");
    exit(1);
  }
  if ( (unsigned int)sub_8D30() == -1 )
    goto LABEL_68;
  v3 = mkstemp(filename);
  if ( v3 == -1 )
  {
    perror(filename);
    goto LABEL_40;
  }
  if ( (unsigned int)sub_8D80() == -1 )
  {
    perror("swapping uids back");
    goto LABEL_40;
  }
  stream = fdopen(v3, "r+");
  if ( !stream )
  {
    perror("fdopen");
    goto LABEL_40;
  }
  if ( (dword_E2C0 & 9) != 0 )
    __printf_chk(1, "linenum=%d\n", 1);
  dword_4E2FC = 1;
  while ( 1 )
  {
    v4 = sub_8570(v1);
    if ( v4 == -1 )
      break;
    putc(v4, stream);
  }
  fclose(v1);
  if ( fflush(stream) < 0 )
  {
    perror(filename);
    exit(1);
  }
  if ( (unsigned int)sub_8D30() == -1
    || (v19.actime = 0, v19.modtime = 0, utime(filename, &v19), (unsigned int)sub_8D80() == -1) )
  {
LABEL_68:
    perror("swapping uids");
    exit(1);
  }
LABEL_17:
  rewind(stream);
  if ( ferror(stream) )
  {
    __fprintf_chk(stderr, 1, "%s: error while writing new crontab to %s\n", ident, filename);
    goto LABEL_40;
  }
  v5 = getenv("VISUAL");
  v0 = v5;
  if ( !v5 || !*v5 )
  {
    v11 = getenv("EDITOR");
    v0 = v11;
    if ( !v11 || !*v11 )
      v0 = "/usr/bin/vi";
  }
  v6 = fork();
  v7 = v6;
  if ( v6 == -1 )
  {
    perror("fork");
    goto LABEL_40;
  }
  if ( !v6 )
  {
    v12 = getgid();
    if ( setgid(v12) < 0 )
    {
      perror("setgid(getgid())");
      exit(1);
    }
    v13 = getuid();
    if ( setuid(v13) < 0 )
    {
      perror("setuid(getuid())");
      exit(1);
    }
    if ( !(unsigned int)sub_8130(v23, &unk_20000, v0, filename, 32) )
    {
      __fprintf_chk(stderr, 1, "%s: editor command line too long\n", ident);
      exit(1);
    }
    execlp("/bin/sh", "/bin/sh", "-c", v23, 0);
LABEL_48:
    perror(v0);
    exit(1);
  }
  v17 = v6;
  while ( 1 )
  {
    v9 = waitpid(v7, &v18, 0);
    if ( v9 != -1 )
      break;
    v8 = *__errno_location();
    if ( v8 != 4 )
    {
      v14 = strerror(v8);
      __fprintf_chk(stderr, 1, "%s: waitpid() failed waiting for PID %ld from \"%s\": %s\n", ident, v17, v0, v14);
    }
  }
  if ( v7 != v9 )
  {
    __fprintf_chk(stderr, 1, "%s: wrong PID (%ld != %ld) from \"%s\"\n", ident, v9, v7, v0);
    goto LABEL_40;
  }
  if ( (v18 & 0x7F) == 0 && BYTE1(v18) )
  {
    __fprintf_chk(stderr, 1, "%s: \"%s\" exited with status %d\n", ident, v0, BYTE1(v18));
    goto LABEL_40;
  }
  if ( !__OFSUB__((v18 & 0x7F) + 1, 1) && (v18 & 0x7F) != 0 )
  {
    v16 = "";
    if ( (v18 & 0x80u) == 0 )
      v16 = "no ";
    __fprintf_chk(stderr, 1, "%s: \"%s\" killed; signal %d (%score dumped)\n", ident, v0, v18 & 0x7F, v16);
LABEL_40:
    unlink(filename);
    exit(1);
  }
  signal(1, 0);
  signal(2, 0);
  signal(3, 0);
  if ( lstat(filename, &v20) < 0 )
  {
    perror("lstat");
    goto LABEL_40;
  }
  if ( (v20.st_mode & 0xF000) != 0x8000 )
  {
    __fprintf_chk(stderr, 1, "%s: illegal crontab\n", ident);
    goto LABEL_55;
  }
  if ( !v20.st_mtim.tv_sec )
  {
    __fprintf_chk(stderr, 1, "%s: no changes made to crontab\n", ident);
    goto LABEL_55;
  }
  __fprintf_chk(stderr, 1, "%s: installing new crontab\n", ident);
  fclose(stream);
  if ( (int)sub_8D30() < 0 )
  {
    perror("swapping uids");
    goto LABEL_55;
  }
  stream = fopen(filename, "r+");
  if ( !stream )
  {
    perror("cannot read new crontab");
    goto LABEL_55;
  }
  if ( (int)sub_8D80() < 0 )
  {
    perror("swapping uids back");
    exit(1);
  }
  if ( !stream )
  {
    perror("fopen");
    goto LABEL_40;
  }
  v10 = sub_53D0();
  if ( v10 != -1 )
  {
    if ( v10 )
    {
      if ( v10 != -2 )
      {
        __fprintf_chk(stderr, 1, "%s: panic: bad switch() in replace_cmd()\n", ident);
        goto LABEL_40;
      }
      goto LABEL_52;
    }
LABEL_55:
    unlink(filename);
    goto LABEL_53;
  }
  while ( 1 )
  {
    do
    {
      __printf_chk(1, "Do you want to retry the same edit? (Y/N) ");
      fflush(stdout);
      v23[0] = 0;
    }
    while ( !fgets(v23, (int)&unk_20000, stdin) );
    if ( v23[0] == 110 )
      break;
    if ( v23[0] > 110 )
    {
      if ( v23[0] == 121 )
        goto LABEL_17;
    }
    else
    {
      if ( v23[0] == 78 )
        break;
      if ( v23[0] == 89 )
        goto LABEL_17;
    }
    __fprintf_chk(stderr, 1, "Enter Y or N\n");
  }
LABEL_52:
  __fprintf_chk(stderr, 1, "%s: edits left in %s\n", ident, filename);
LABEL_53:
  sub_8720(s2, (unsigned int)dword_51580, "END EDIT", s1, 0);
  return v25 - __readfsqword(0x28u);
}


// Function: build_env @ 0x6090
long long build_env()
{
  long long result; // rax
  unsigned int v1; // eax

  result = sub_7870();
  if ( !result )
  {
    v1 = getpid();
    sub_8720("CRON", v1, "ERROR", "Initialization of cron environment variables failed", 0);
    return 0;
  }
  return result;
}


// Function: cron_change_groups @ 0x61e0
int cron_change_groups(long long a1)
{
  unsigned int v1; // ebp
  int result; // eax
  int *v3; // rax
  const char *v4; // rcx
  long long v5; // r8
  int *v6; // rax

  v1 = getpid();
  if ( setgid(*(int *)(a1 + 20)) )
  {
    v3 = __errno_location();
    v4 = "setgid failed";
    v5 = (unsigned int)*v3;
LABEL_5:
    sub_8720("CRON", v1, "ERROR", v4, v5);
    return -1;
  }
  result = initgroups(*(const char **)a1, *(int *)(a1 + 20));
  if ( result )
  {
    v6 = __errno_location();
    v4 = "initgroups failed";
    v5 = (unsigned int)*v6;
    goto LABEL_5;
  }
  return result;
}


// Function: cron_set_job_security_context @ 0x6260
long long cron_set_job_security_context(long long a1, long long a2, long long *a3)
{
  unsigned int v4; // r12d
  time_t v5; // rax
  time_t v7; // rax
  unsigned int v8; // eax
  time_t v9; // [rsp+0h] [rbp-1B8h] BYREF
  time_t timer; // [rsp+8h] [rbp-1B0h] BYREF
  struct tm v11; // [rsp+10h] [rbp-1A8h] BYREF
  struct tm tp; // [rsp+50h] [rbp-168h] BYREF
  char v13[264]; // [rsp+90h] [rbp-128h] BYREF
  unsigned long long v14; // [rsp+198h] [rbp-20h]

  v14 = __readfsqword(0x28u);
  v9 = 0;
  if ( (*(char *)(a1 + 52) & 1) != 0 )
  {
    v7 = time(0);
    v9 = v7;
    if ( (dword_E2C0 & 2) != 0 )
      __printf_chk(1, "Minute-ly job. Recording time %lld\n", v7);
  }
  v4 = sub_61E0(*(long long *)(a1 + 8));
  if ( v4 )
  {
    return (unsigned int)-1;
  }
  else
  {
    *a3 = sub_6090(*(long long *)(a1 + 16));
    v5 = time(0);
    timer = v5;
    if ( v9 > 0 && v5 / 60 != v9 / 60 )
    {
      localtime_r(&timer, &tp);
      localtime_r(&v9, &v11);
      __snprintf_chk(
        v13,
        256,
        1,
        256,
        "Job execution of per-minute job scheduled for %.2u:%.2u delayed into subsequent minute %.2u:%.2u. Skipping job run.",
        v11.tm_hour,
        v11.tm_min,
        tp.tm_hour,
        tp.tm_min);
      v8 = getpid();
      v4 = -1;
      sub_8720(**(long long **)(a1 + 8), v8, "INFO", v13, 0);
    }
  }
  return v4;
}


// Function: cron_change_user_permanently @ 0x6400
long long cron_change_user_permanently(long long a1, const char *a2)
{
  unsigned int v2; // r12d
  unsigned int v4; // r12d
  unsigned int v5; // eax
  long long v6; // r8
  unsigned int v7; // r12d
  unsigned int v8; // eax
  long long v9; // r8

  if ( setreuid(*(int *)(a1 + 16), *(int *)(a1 + 16)) )
  {
    v4 = *__errno_location();
    v5 = getpid();
    v6 = v4;
    v2 = -1;
    sub_8720("CRON", v5, "ERROR", "setreuid failed", v6);
  }
  else
  {
    v2 = 0;
    if ( chdir(a2) == -1 )
    {
      v7 = *__errno_location();
      v8 = getpid();
      v9 = v7;
      v2 = -1;
      sub_8720("CRON", v8, "ERROR chdir failed", a2, v9);
    }
    else
    {
      sub_8BE0();
    }
  }
  return v2;
}


// Function: allowed @ 0x64b0
long long allowed(long long a1, const char *a2, const char *a3)
{
  long long v4; // r12
  FILE *v6; // rax
  FILE *v7; // rbp
  unsigned int v8; // eax
  FILE *v9; // rax
  FILE *v10; // rbp
  int v11; // r13d
  __uid_t v12; // eax
  long long v13[23]; // [rsp+0h] [rbp-B8h] BYREF

  LODWORD(v4) = 1;
  v13[17] = __readfsqword(0x28u);
  if ( !getuid() )
    return (unsigned int)v4;
  v6 = fopen(a2, "r");
  v7 = v6;
  if ( v6 )
  {
    LODWORD(v4) = sub_60E0(a1, v6);
    fclose(v7);
    if ( (unsigned int)v4 | getuid() )
      return (unsigned int)v4;
    __snprintf_chk(v13, 128, 1, 128, "root used -u for user %s not in cron.allow", a1);
LABEL_6:
    v8 = getpid();
    LODWORD(v4) = 1;
    sub_8720("crontab", v8, "warning", v13, 0);
    return (unsigned int)v4;
  }
  v9 = fopen(a3, "r");
  v10 = v9;
  if ( !v9 )
  {
    LODWORD(v4) = 0;
    return (unsigned int)v4;
  }
  v11 = sub_60E0(a1, v9);
  v4 = v11 == 0;
  fclose(v10);
  v12 = getuid();
  if ( v11 && !v12 )
  {
    __snprintf_chk(v13, 128, 1, 128, "root used -u for user %s in cron.deny", a1);
    goto LABEL_6;
  }
  return (unsigned int)v4;
}


// Function: is_separator @ 0x6620
unsigned long long is_separator(unsigned int a1)
{
  if ( a1 > 0x2C )
    return 0;
  else
    return (0x100100000600uLL >> a1) & 1;
}


// Function: set_element @ 0x6650
long long set_element(long long a1, int a2, int a3, int a4)
{
  if ( (dword_E2C0 & 9) != 0 )
    __printf_chk(1, "set_element(?,%d,%d,%d)\n", a2, a3, a4);
  if ( a2 > a4 || a3 < a4 )
    return 0xFFFFFFFFLL;
  *(char *)(a1 + ((a4 - a2) >> 3)) |= 1 << ((a4 - a2) & 7);
  return 0;
}


// Function: get_number @ 0x66d0
// positive sp value has been detected, the output may be wrong!
int get_number(int *a1, int a2, const char **a3, long long a4)
{
  int v4; // ebx
  char *i; // r13
  const unsigned short *v8; // r12
  unsigned int v9; // eax
  unsigned int v10; // r15d
  int v11; // eax
  char *v12; // rdx
  int result; // eax
  const char *v14; // rdx
  long long v15; // r13
  const unsigned short **v16; // [rsp-50h] [rbp-20080h]
  char *v17; // [rsp-20h] [rbp-20050h] BYREF
  char v18[24]; // [rsp-18h] [rbp-20048h] BYREF
  char v19; // [rsp+0h] [rbp-20030h] BYREF
  long long v20; // [rsp+1000h] [rbp-1F030h] BYREF
  char v21[73]; // [rsp+1FFE7h] [rbp-49h] BYREF

  while ( &v19 != (char *)(&v20 - 0x4000) )
    ;
  v4 = 0;
  *(long long *)&v21[9] = __readfsqword(0x28u);
  v16 = __ctype_b_loc();
  for ( i = v18; ; ++i )
  {
    v8 = *v16;
    v9 = sub_8570(a4);
    v10 = v9;
    if ( (v8[v9] & 8) == 0 )
      break;
    ++v4;
    if ( i == v21 )
      goto LABEL_16;
    *i = v9;
  }
  *i = 0;
  if ( !v4 )
    goto LABEL_16;
  ((void (*)(long long, long long))sub_85D0)(v9, a4);
  v11 = strtol(v18, &v17, 10);
  v12 = v17;
  *a1 = v11;
  if ( !*v12 )
  {
    result = 0;
    if ( v12 != v18 )
      return result;
  }
  if ( !a3 || (v14 = *a3) == 0 )
  {
LABEL_16:
    ((void (*)(long long, long long))sub_85D0)(v10, a4);
    return -1;
  }
  v15 = 0;
  while ( 1 )
  {
    if ( (dword_E2C0 & 9) != 0 )
      __printf_chk(1, "get_num, compare(%s,%s)\n", v14, v18);
    result = strcasecmp(a3[v15], v18);
    if ( !result )
      break;
    v14 = a3[++v15];
    if ( !v14 )
      goto LABEL_16;
  }
  *a1 = v15 + a2;
  return result;
}


// Function: get_range @ 0x6880
long long get_range(long long a1, int a2, int a3, const char **a4, long long a5)
{
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // r12d
  long long v12; // rdi
  int v13; // r15d
  int v14; // r15d
  unsigned int v16; // eax
  unsigned int v17; // eax
  int v18; // r12d
  int v19; // r15d
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  int v23; // [rsp+Ch] [rbp-5Ch]
  int v24; // [rsp+1Ch] [rbp-4Ch] BYREF
  int v25; // [rsp+20h] [rbp-48h] BYREF
  int v26; // [rsp+24h] [rbp-44h] BYREF
  unsigned long long v27; // [rsp+28h] [rbp-40h]

  v27 = __readfsqword(0x28u);
  v26 = 1;
  v9 = sub_8570(a5);
  if ( v9 == -1 )
    return (unsigned int)-1;
  if ( v9 != 42 )
  {
    if ( v9 == 126 )
    {
      v24 = a2;
LABEL_5:
      v10 = sub_8570(a5);
      v11 = v10;
      if ( v10 != -1 )
      {
        v12 = v10;
        if ( (unsigned int)sub_6620(v10) )
        {
          v13 = v24;
          v25 = a3;
          if ( v24 <= a3 )
          {
            v14 = random() % (a3 - v13 + 1) + v13;
            v23 = v14;
            goto LABEL_10;
          }
        }
        else
        {
          sub_85D0(v12, a5);
          if ( sub_66D0(&v25, a2, a4, a5) != -1 )
          {
            v18 = v24;
            v19 = v25;
            if ( v25 >= v24 )
            {
              v14 = v18 + random() % (v19 - v18 + 1);
              v25 = v14;
              v24 = v14;
              v20 = sub_8570(a5);
              v11 = v20;
              if ( v20 != -1 )
              {
                if ( (unsigned int)sub_6620(v20) )
                {
                  v23 = v14;
                  goto LABEL_10;
                }
              }
            }
          }
        }
      }
      return (unsigned int)-1;
    }
    sub_85D0(v9, a5);
    if ( sub_66D0(&v24, a2, a4, a5) != -1 )
    {
      v21 = sub_8570(a5);
      v11 = v21;
      if ( v21 != -1 )
      {
        if ( v21 != 45 )
        {
          if ( v21 != 126 )
          {
            if ( (unsigned int)sub_6620(v21) )
            {
              v14 = v24;
              v23 = v24;
              goto LABEL_10;
            }
            return (unsigned int)-1;
          }
          goto LABEL_5;
        }
        v22 = sub_8570(a5);
        if ( v22 != -1 )
        {
          sub_85D0(v22, a5);
          if ( sub_66D0(&v25, a2, a4, a5) != -1 )
          {
            v11 = sub_8570(a5);
            if ( v11 != -1 )
            {
              if ( v11 != 47 )
                goto LABEL_20;
              goto LABEL_16;
            }
          }
        }
      }
    }
    return (unsigned int)-1;
  }
  v24 = a2;
  v25 = a3;
  v16 = sub_8570(a5);
  v11 = v16;
  if ( v16 == -1 )
    return (unsigned int)-1;
  if ( v16 != 47 )
  {
    if ( (unsigned int)sub_6620(v16) )
    {
      v23 = a3;
      v14 = a2;
LABEL_10:
      while ( (unsigned int)sub_6650(a1, a2, a3, v14) != -1 )
      {
        v14 += v26;
        if ( v23 < v14 )
          return v11;
      }
      sub_85D0(v11, a5);
    }
    return (unsigned int)-1;
  }
LABEL_16:
  v17 = sub_8570(a5);
  if ( v17 == -1 )
    return (unsigned int)-1;
  sub_85D0(v17, a5);
  if ( sub_66D0(&v26, 0, 0, a5) == -1 )
    return (unsigned int)-1;
  if ( !v26 )
    return (unsigned int)-1;
  v11 = sub_8570(a5);
  if ( v11 == -1 )
    return (unsigned int)-1;
LABEL_20:
  if ( !(unsigned int)sub_6620(v11) )
    return (unsigned int)-1;
  v14 = v24;
  v23 = v25;
  if ( v24 <= v25 )
    goto LABEL_10;
  return v11;
}


// Function: get_list @ 0x6bb0
long long get_list(char *a1, int a2, int a3, const char **a4, unsigned int a5, long long a6)
{
  char v11; // cl
  int v12; // esi
  unsigned int v13; // r12d
  unsigned int v14; // eax
  unsigned int v15; // eax
  char *v17; // rax

  if ( (dword_E2C0 & 9) != 0 )
    __printf_chk(1, "get_list()...entered\n");
  v11 = a3 - a2;
  v12 = (a3 - a2) >> 3;
  if ( (a3 - a2) >> 3 )
  {
    *a1 = 0;
    if ( v12 != 1 )
    {
      v17 = a1 + 1;
      do
        *v17++ = 0;
      while ( &a1[v12 - 2 + 2] != v17 );
    }
    a1[v12] &= 255 << ((v11 & 7) + 1);
  }
  else
  {
    *a1 &= 255 << (v11 + 1);
  }
  sub_85D0(a5, a6);
  while ( 1 )
  {
    v13 = sub_6880((long long)a1, a2, a3, a4, a6);
    if ( v13 == -1 )
      return v13;
    if ( v13 != 44 )
    {
      if ( v13 == 9 )
        goto LABEL_16;
      if ( v13 != 32 )
      {
        if ( v13 == 10 )
          goto LABEL_20;
        while ( 1 )
        {
          v14 = sub_8570(a6);
          v13 = v14;
          if ( v14 == 9 )
            break;
          if ( v14 == 32 )
            goto LABEL_18;
          if ( v14 == 10 || v14 == -1 )
            goto LABEL_20;
        }
LABEL_16:
        if ( v13 != 32 && v13 != 9 )
        {
LABEL_20:
          if ( (dword_E2C0 & 9) != 0 )
            __printf_chk(1, "get_list()...exiting w/ %02x\n", v13);
          return v13;
        }
      }
      do
      {
        do
        {
LABEL_18:
          v15 = sub_8570(a6);
          v13 = v15;
        }
        while ( v15 == 9 );
      }
      while ( v15 == 32 );
      goto LABEL_20;
    }
  }
}


// Function: free_entry @ 0x6d20
void free_entry(void **ptr)
{
  free(ptr[3]);
  free(ptr[1]);
  sub_7830(ptr[2]);
  free(ptr);
}


// Function: load_entry @ 0x6d50
// positive sp value has been detected, the output may be wrong!
char *load_entry(FILE *a1, void (*a2)(char *), struct passwd *a3, char **a4)
{
  unsigned int v7; // ebx
  char *v8; // rax
  char *v9; // r15
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  char v14; // al
  long long v15; // r14
  long long v16; // rax
  char *v17; // r14
  size_t v18; // rax
  unsigned long long v19; // rsi
  const char *v20; // r14
  int *v21; // rax
  unsigned long long v22; // rax
  long long v23; // rax
  long long v24; // rax
  char *v25; // rdx
  long long v26; // rdi
  long long v27; // rax
  long long v28; // rax
  long long v29; // rax
  char *v30; // rax
  void *v32; // rdi
  int v33; // r12d
  int v34; // eax
  unsigned int v35; // eax
  struct passwd *v36; // rax
  unsigned int v37; // eax
  long long v38; // rsi
  unsigned int v39; // eax
  char *v40; // rcx
  long long v41; // rax
  unsigned int v42; // eax
  long long v43; // rax
  unsigned int v44; // eax
  unsigned int v45; // eax
  int *v47; // [rsp-60h] [rbp-40090h]
  char *v48; // [rsp-50h] [rbp-40080h] BYREF
  long long v49[2]; // [rsp-48h] [rbp-40078h] BYREF
  __int128 v50; // [rsp-38h] [rbp-40068h]
  __int128 v51; // [rsp-28h] [rbp-40058h]
  char v52[24]; // [rsp-18h] [rbp-40048h] BYREF
  char v53; // [rsp+0h] [rbp-40030h] BYREF
  long long v54; // [rsp+1000h] [rbp-3F030h] BYREF
  char v55[126896]; // [rsp+1FFE8h] [rbp-20048h] BYREF
  unsigned long long v56; // [rsp+3FFF0h] [rbp-40h]

  while ( &v53 != (char *)(&v54 - 0x8000) )
    ;
  v56 = __readfsqword(0x28u);
  if ( (dword_E2C0 & 8) != 0 )
    __printf_chk(1, "load_entry()...about to eat comments\n");
  v7 = sub_8570(a1);
  if ( v7 == -1 )
    return 0;
  v8 = (char *)calloc(0x40u, 1u);
  v9 = v8;
  if ( !v8 )
  {
    v15 = 10;
LABEL_60:
    v33 = 0;
    if ( v7 != 10 )
    {
      do
      {
        if ( feof(a1) )
          break;
        ++v33;
        v34 = sub_8570(a1);
        if ( v33 > (int)&unk_1FFFF )
          break;
      }
      while ( v34 != 10 );
    }
    if ( a2 )
    {
      v9 = 0;
      a2(off_DA80[v15]);
      return v9;
    }
    return 0;
  }
  if ( v7 == 45 )
  {
    if ( a3 && a3->pw_uid )
    {
      v38 = (unsigned int)getpid();
      v15 = 9;
      sub_8720("CRON", v38, "ERROR", "Only privileged user can disable logging", 0);
      goto LABEL_57;
    }
    *((int *)v8 + 13) |= 0x20u;
    v7 = sub_8570(a1);
    if ( v7 == -1 )
    {
      free(v9);
      return 0;
    }
  }
  if ( v7 != 64 )
  {
    if ( (dword_E2C0 & 8) != 0 )
    {
      __printf_chk(1, "load_entry()...about to parse numerics\n");
      if ( v7 != 42 )
        goto LABEL_10;
    }
    else if ( v7 != 42 )
    {
LABEL_10:
      v10 = sub_6BB0(v9 + 32, 0, 59, 0, v7, (long long)a1);
      v7 = v10;
      if ( v10 == -1 )
      {
        v15 = 1;
        goto LABEL_57;
      }
      if ( v10 == 42 )
        *((int *)v9 + 13) |= 2u;
      v11 = sub_6BB0(v9 + 40, 0, 23, 0, v10, (long long)a1);
      v7 = v11;
      if ( v11 == -1 )
      {
        v15 = 2;
        goto LABEL_57;
      }
      if ( v11 == 42 )
        *((int *)v9 + 13) |= 4u;
      v12 = sub_6BB0(v9 + 43, 1, 31, 0, v11, (long long)a1);
      v7 = v12;
      if ( v12 == -1 )
      {
        v15 = 3;
        goto LABEL_57;
      }
      v13 = sub_6BB0(v9 + 47, 1, 12, (const char **)off_E0E0, v12, (long long)a1);
      v7 = v13;
      if ( v13 == -1 )
      {
        v15 = 4;
        goto LABEL_57;
      }
      if ( v13 == 42 )
        *((int *)v9 + 13) |= 8u;
      v7 = sub_6BB0(v9 + 49, 0, 7, (const char **)off_E080, v13, (long long)a1);
      if ( v7 != -1 )
        goto LABEL_21;
      v15 = 5;
LABEL_57:
      v32 = (void *)*((long long *)v9 + 2);
      if ( v32 )
        sub_7830(v32);
      goto LABEL_59;
    }
    *((int *)v9 + 13) |= 1u;
    goto LABEL_10;
  }
  v7 = sub_8620(v52, &unk_20000, a1, " \t\n");
  if ( !strcmp("reboot", v52) )
  {
    *((int *)v9 + 13) |= 0x10u;
  }
  else if ( !strcmp("yearly", v52) || !strcmp("annually", v52) )
  {
    v9[32] |= 1u;
    v9[40] |= 1u;
    v9[43] |= 1u;
    v9[47] |= 1u;
    *((int *)v9 + 13) |= 8u;
    v9[49] = -1;
  }
  else if ( !strcmp("monthly", v52) )
  {
    v9[32] |= 1u;
    v9[40] |= 1u;
    v9[43] |= 1u;
    v9[48] |= 0xFu;
    *((int *)v9 + 13) |= 8u;
    v9[47] = -1;
    v9[49] = -1;
  }
  else if ( !strcmp("weekly", v52) )
  {
    v9[32] |= 1u;
    v9[40] |= 1u;
    v9[46] |= 0x7Fu;
    *((short *)v9 + 24) |= 0x10Fu;
    *((int *)v9 + 13) |= 4u;
    *(short *)(v9 + 43) = -1;
    v9[45] = -1;
    v9[47] = -1;
  }
  else if ( !strcmp("daily", v52) || !strcmp("midnight", v52) )
  {
    v9[32] |= 1u;
    v9[40] |= 1u;
    v9[46] |= 0x7Fu;
    v9[48] |= 0xFu;
    *(short *)(v9 + 43) = -1;
    v9[45] = -1;
    v9[47] = -1;
    v9[49] = -1;
  }
  else
  {
    if ( strcmp("hourly", v52) )
    {
      v15 = 7;
      goto LABEL_57;
    }
    v9[32] |= 1u;
    v9[46] |= 0x7Fu;
    v9[48] |= 0xFu;
    *((int *)v9 + 13) |= 2u;
    *((int *)v9 + 10) = -1;
    *((short *)v9 + 22) = -1;
    v9[47] = -1;
    v9[49] = -1;
  }
  if ( v7 == 32 || v7 == 9 )
  {
    do
    {
      do
      {
        v35 = sub_8570(a1);
        v7 = v35;
      }
      while ( v35 == 9 );
    }
    while ( v35 == 32 );
  }
  if ( v7 == -1 || v7 == 10 )
    goto LABEL_77;
LABEL_21:
  v14 = v9[49];
  if ( (v14 & 1) != 0 || v14 < 0 )
    v9[49] = v14 | 0x81;
  v15 = 6;
  if ( (v7 & 0xFFFFFFDF) == 0xA )
    goto LABEL_57;
  sub_85D0(v7, a1);
  if ( !a3 )
  {
    if ( (dword_E2C0 & 8) != 0 )
      __printf_chk(1, "load_entry()...about to parse username\n");
    v7 = sub_8620(v52, &unk_20000, a1, " \t\n");
    if ( (dword_E2C0 & 8) != 0 )
      __printf_chk(1, "load_entry()...got %s\n", v52);
    if ( v7 == -1 || v7 == 10 || v7 == 42 )
      goto LABEL_77;
    v36 = getpwnam(v52);
    a3 = v36;
    if ( v36 )
    {
      if ( (dword_E2C0 & 8) != 0 )
        __printf_chk(1, "load_entry()...uid %ld, gid %ld\n", v36->pw_uid, v36->pw_gid);
    }
    else
    {
      if ( (dword_E2C0 & 8) != 0 )
        __printf_chk(1, "load_entry()...unknown user entry\n");
      v49[0] = v52;
      a3 = (struct passwd *)v49;
      v49[1] = "";
      v50 = 0;
      v51 = 0;
    }
    if ( v7 == 32 || v7 == 9 )
    {
      do
      {
        do
        {
          v37 = sub_8570(a1);
          v7 = v37;
        }
        while ( v37 == 9 );
      }
      while ( v37 == 32 );
      if ( v37 == -1 || v37 == 10 )
        goto LABEL_77;
    }
    sub_85D0(v7, a1);
  }
  v16 = ((long long (*)(struct passwd *))sub_8E90)(a3);
  *((long long *)v9 + 1) = v16;
  if ( !v16 )
    goto LABEL_104;
  v17 = *(char **)(v16 + 8);
  v18 = strlen(v17);
  memset(v17, 0, v18);
  v19 = (unsigned long long)a4;
  v20 = (const char *)sub_7F10("RANDOM_DELAY");
  if ( v20 )
  {
    v21 = __errno_location();
    v19 = (unsigned long long)&v48;
    *v21 = 0;
    v47 = v21;
    v22 = strtol(v20, &v48, 10);
    if ( *v47 || v22 > 0x5A0 )
    {
      v19 = (unsigned int)getpid();
      sub_8720("CRON", v19, "ERROR", "bad value of RANDOM_DELAY", 0);
    }
    else
    {
      *((int *)v9 + 14) = (int)((double)(int)v22 * *(double *)&qword_E2C8);
    }
  }
  v23 = ((long long (*)(char **, unsigned long long))sub_7870)(a4, v19);
  *((long long *)v9 + 2) = v23;
  if ( !v23 )
  {
    v15 = 10;
LABEL_59:
    free(*((void **)v9 + 1));
    free(*((void **)v9 + 3));
    free(v9);
    goto LABEL_60;
  }
  v24 = sub_7F10("SHELL");
  v25 = "SHELL";
  if ( v24 )
    goto LABEL_32;
  if ( !(unsigned int)sub_8130(v55, &unk_20000, "SHELL", "/bin/sh", 61) )
  {
    v45 = getpid();
    sub_8720("CRON", v45, "ERROR", "can't set SHELL", 0);
LABEL_32:
    v26 = *((long long *)v9 + 2);
    goto LABEL_33;
  }
  v43 = sub_7940(*((void **)v9 + 2), v55);
  v26 = v43;
  if ( !v43 )
    goto LABEL_104;
  *((long long *)v9 + 2) = v43;
LABEL_33:
  v27 = ((long long (*)(long long, char *, char *))sub_7F90)(v26, a3->pw_dir, v25);
  if ( !v27 )
    goto LABEL_104;
  *((long long *)v9 + 2) = v27;
  if ( !sub_7F10("PATH") )
  {
    if ( dword_E2D0 || (v40 = getenv("PATH")) == 0 )
      v40 = "/usr/bin:/bin";
    if ( (unsigned int)sub_8130(v55, &unk_20000, "PATH", v40, 61) )
    {
      v41 = sub_7940(*((void **)v9 + 2), v55);
      if ( !v41 )
        goto LABEL_104;
      *((long long *)v9 + 2) = v41;
    }
    else
    {
      v44 = getpid();
      sub_8720("CRON", v44, "ERROR", "can't set PATH", 0);
    }
  }
  if ( (unsigned int)sub_8130(v55, &unk_20000, "LOGNAME", a3->pw_name, 61) )
  {
    v28 = sub_7940(*((void **)v9 + 2), v55);
    if ( !v28 )
      goto LABEL_104;
    *((long long *)v9 + 2) = v28;
  }
  else
  {
    v39 = getpid();
    sub_8720("CRON", v39, "ERROR", "can't set LOGNAME", 0);
  }
  if ( (unsigned int)sub_8130(v55, &unk_20000, "USER", a3->pw_name, 61) )
  {
    v29 = sub_7940(*((void **)v9 + 2), v55);
    if ( v29 )
    {
      *((long long *)v9 + 2) = v29;
      goto LABEL_41;
    }
LABEL_104:
    v15 = 10;
    goto LABEL_57;
  }
  v42 = getpid();
  sub_8720("CRON", v42, "ERROR", "can't set USER", 0);
LABEL_41:
  if ( (dword_E2C0 & 8) != 0 )
    __printf_chk(1, "load_entry()...about to parse command\n");
  v7 = sub_8620(v52, &unk_20000, a1, "\n");
  if ( v7 == -1 )
  {
LABEL_77:
    v15 = 6;
    goto LABEL_57;
  }
  v30 = strdup(v52);
  *((long long *)v9 + 3) = v30;
  if ( !v30 )
    goto LABEL_104;
  if ( (dword_E2C0 & 8) != 0 )
    __printf_chk(1, "load_entry()...returning successfully\n");
  return v9;
}


// Function: env_init @ 0x7800
long long *env_init()
{
  long long *result; // rax

  result = malloc(8u);
  if ( result )
    *result = 0;
  return result;
}


// Function: env_free @ 0x7830
void env_free(void **ptr)
{
  void *v2; // rdi
  void **v3; // rbx

  v2 = *ptr;
  if ( v2 )
  {
    v3 = ptr;
    do
    {
      free(v2);
      v2 = v3[1];
      ++v3;
    }
    while ( v2 );
  }
  free(ptr);
}


// Function: env_copy @ 0x7870
long long *env_copy(long long *a1)
{
  long long v1; // rax
  long long v2; // rbp
  long long v3; // r13
  long long *v4; // r12
  long long i; // rbx
  char *v6; // rax
  long long *v7; // r13
  long long *v9; // rax
  int *v10; // rax
  long long v11; // rbp
  int v12; // r14d
  int *v13; // r13

  if ( *a1 )
  {
    v1 = 0;
    do
    {
      v2 = v1++;
      v3 = v1;
    }
    while ( a1[v1] );
    v4 = malloc(v3 * 8 + 8);
    if ( v4 )
    {
      for ( i = 0; ; ++i )
      {
        v6 = strdup((const char *)a1[i]);
        v4[i] = v6;
        if ( !v6 )
          break;
        if ( v2 == i )
        {
          v7 = &v4[v3];
          goto LABEL_10;
        }
      }
      v10 = __errno_location();
      v11 = i - 1;
      v12 = *v10;
      v13 = v10;
      if ( i )
      {
        do
          free((void *)v4[v11]);
        while ( v11-- != 0 );
      }
      free(v4);
      *v13 = v12;
    }
    return 0;
  }
  v9 = malloc(8u);
  v4 = v9;
  if ( !v9 )
    return 0;
  v7 = v9;
LABEL_10:
  *v7 = 0;
  return v4;
}


// Function: env_set @ 0x7940
long long *env_set(long long *ptr, char *s)
{
  long long v3; // rdi
  long long v4; // r12
  long long i; // rbx
  long long v6; // rbp
  int v7; // eax
  char *v8; // rbx
  void **v9; // rbp
  long long *result; // rax
  long long v11; // rbx
  char *v12; // r12
  char **v13; // rdx

  v3 = *ptr;
  if ( v3 )
  {
    v4 = -1;
    for ( i = 0; ; ++i )
    {
      v6 = i + 1;
      v7 = sub_81D0(v3, s, 61);
      v3 = ptr[i + 1];
      if ( !v7 )
        v4 = i;
      if ( !v3 )
        break;
    }
    if ( v4 != -1 )
    {
      v8 = strdup(s);
      if ( v8 )
      {
        v9 = (void **)&ptr[v4];
        free(*v9);
        *v9 = v8;
        return ptr;
      }
      return 0;
    }
    v11 = i + 2;
  }
  else
  {
    v6 = 0;
    v11 = 1;
  }
  v12 = strdup(s);
  if ( !v12 )
    return 0;
  result = (long long *)realloc(ptr, 8 * v6 + 16);
  if ( result )
  {
    v13 = (char **)&result[v11 - 1];
    result[v11] = (long long)*v13;
    *v13 = v12;
  }
  else
  {
    free(v12);
    return 0;
  }
  return result;
}


// Function: env_set_from_environ @ 0x7a40
long long env_set_from_environ(long long **a1)
{
  const char **v1; // r12
  const char *v2; // rbp
  char **v3; // r14
  size_t v4; // rax
  char *v5; // r13
  size_t v6; // rbx
  unsigned int v7; // r15d
  long long *v8; // rax

  v1 = (const char **)_environ;
  if ( *_environ )
  {
    while ( 1 )
    {
      v2 = off_E1A0[0];
      v3 = off_E1A0;
      if ( off_E1A0[0] )
        break;
LABEL_9:
      if ( !*++v1 )
        return 1;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        v4 = strlen(v2);
        v5 = (char *)*v1;
        v6 = v4;
        v7 = strncmp(v2, *v1, v4);
        if ( !v7 && v5[v6] == 61 )
          break;
        v2 = v3[1];
        ++v3;
        if ( !v2 )
          goto LABEL_9;
      }
      v8 = sub_7940(*a1, v5);
      if ( !v8 )
        break;
      v2 = v3[1];
      ++v3;
      *a1 = v8;
      if ( !v2 )
        goto LABEL_9;
    }
  }
  else
  {
    return 1;
  }
  return v7;
}


// Function: load_env @ 0x7b20
long long load_env(const char *a1, FILE *a2)
{
  unsigned char *v2; // rbp
  long long v3; // rax
  char *v4; // r15
  char v5; // di
  unsigned int v6; // r14d
  long long v7; // rbx
  long long v8; // kr00_8
  unsigned char v9; // r14
  unsigned char *v10; // rbx
  unsigned char v11; // r14
  unsigned int v12; // r12d
  const unsigned short **v14; // rax
  const char *v15; // [rsp+8h] [rbp-50h]
  long long off; // [rsp+10h] [rbp-48h]
  int v17; // [rsp+1Ch] [rbp-3Ch]

  v2 = (unsigned char *)a1;
  off = ftell(a2);
  v17 = dword_4E2FC;
  v3 = sub_8620(a1, &unk_20000, a2, "\n");
  if ( (int)v3 == -1 )
    return (unsigned int)-1;
  if ( (dword_E2C0 & 8) != 0 )
    v3 = __printf_chk(1, "load_env, read <%s>\n", a1);
  v15 = a1;
  v4 = (char *)a1;
  v5 = 0;
  v6 = 0;
LABEL_5:
  while ( 2 )
  {
    v7 = *v2;
    if ( !(char)v7 )
      goto LABEL_18;
LABEL_6:
    v8 = v3;
    v3 = v6;
    switch ( v6 )
    {
      case 1u:
      case 5u:
        break;
      case 2u:
        goto LABEL_31;
      case 3u:
      case 6u:
        goto LABEL_16;
      default:
        v3 = v8;
        if ( (char)v7 == 39 || (char)v7 == 34 )
        {
          v3 = v2[1];
          v5 = v7;
          ++v2;
          LOBYTE(v7) = v3;
        }
        ++v6;
        break;
    }
    while ( v5 )
    {
      if ( v5 == (char)v7 )
      {
        ++v6;
        ++v2;
        goto LABEL_5;
      }
      if ( v6 != 1 )
      {
LABEL_28:
        *v4 = v7;
        ++v2;
        ++v4;
        goto LABEL_5;
      }
      if ( (char)v7 == 61 )
        goto LABEL_37;
LABEL_47:
      *v4 = v7;
      LOBYTE(v7) = v2[1];
      v3 = (long long)(v4 + 1);
      if ( !(char)v7 )
      {
        v6 = 1;
        goto LABEL_38;
      }
      ++v4;
      ++v2;
      v6 = 1;
    }
    if ( v6 != 1 )
      goto LABEL_28;
    if ( ((*__ctype_b_loc())[(unsigned char)v7] & 0x2000) == 0 )
    {
      if ( (char)v7 == 61 )
        goto LABEL_10;
      goto LABEL_47;
    }
    v7 = v2[1];
    if ( !(char)v7 )
    {
LABEL_34:
      v6 = 2;
      goto LABEL_38;
    }
    ++v2;
LABEL_31:
    while ( (char)v7 != 61 )
    {
      if ( ((*__ctype_b_loc())[v7] & 0x2000) == 0 )
        goto LABEL_37;
      v7 = *++v2;
      if ( !(char)v7 )
        goto LABEL_34;
    }
LABEL_10:
    *v4 = 61;
    v9 = v2[1];
    v10 = v2 + 1;
    v15 = v4 + 1;
    if ( !v9 )
      goto LABEL_58;
    v3 = (long long)*__ctype_b_loc();
    if ( (*(char *)(v3 + 2LL * v9 + 1) & 0x20) == 0 )
    {
LABEL_35:
      ++v4;
      v2 = v10;
      v5 = 0;
      v6 = 3;
      goto LABEL_36;
    }
    v11 = v2[2];
    v10 = v2 + 2;
    if ( !v11 )
    {
LABEL_58:
      v4[1] = 0;
      return 1;
    }
    v3 = (long long)*__ctype_b_loc();
    if ( (*(char *)(v3 + 2LL * v11 + 1) & 0x20) == 0 )
      goto LABEL_35;
    v7 = v2[3];
    if ( !(char)v7 )
    {
      ++v4;
LABEL_19:
      *v4 = 0;
      return 1;
    }
    ++v4;
    v2 += 3;
    v5 = 0;
    v6 = 3;
LABEL_16:
    v3 = (long long)*__ctype_b_loc();
    if ( (*(char *)(v3 + 2 * v7 + 1) & 0x20) == 0 )
    {
LABEL_36:
      if ( ++v6 != 7 )
        continue;
LABEL_37:
      v6 = 7;
      goto LABEL_38;
    }
    break;
  }
  v7 = *++v2;
  if ( (char)v7 )
    goto LABEL_6;
LABEL_18:
  if ( v6 == 6 || v6 == 3 )
    goto LABEL_19;
  if ( v6 != 5 || v5 )
  {
LABEL_38:
    if ( (dword_E2C0 & 8) != 0 )
      __printf_chk(1, "load_env, not an env var, state = %d\n", v6);
    v12 = fseek(a2, off, 0);
    if ( !v12 )
    {
      if ( (dword_E2C0 & 9) != 0 )
        __printf_chk(1, "linenum=%d\n", v17);
      dword_4E2FC = v17;
      return v12;
    }
    return (unsigned int)-1;
  }
  *v4 = 0;
  if ( v15 < v4 )
  {
    v14 = __ctype_b_loc();
    do
    {
      if ( ((*v14)[(unsigned char)*(v4 - 1)] & 0x2000) == 0 )
        break;
      *--v4 = 0;
    }
    while ( v4 != v15 );
  }
  return 1;
}


// Function: env_get @ 0x7f10
const char *env_get(char *s2, const char **a2)
{
  size_t v2; // rax
  const char *v3; // rbp
  size_t v4; // r13
  const char **i; // r12
  char *v6; // rax
  char *v7; // rbx

  v2 = strlen(s2);
  v3 = *a2;
  if ( *a2 )
  {
    v4 = v2;
    for ( i = a2 + 1; ; ++i )
    {
      v6 = strchr(v3, 61);
      v7 = v6;
      if ( v6 )
      {
        if ( v6 - v3 == v4 && !strncmp(v3, s2, v4) )
          break;
      }
      v3 = *i;
      if ( !v3 )
        return v3;
    }
    return v7 + 1;
  }
  return v3;
}


// Function: env_update_home @ 0x7f90
// positive sp value has been detected, the output may be wrong!
long long *env_update_home(long long *a1, char *a2)
{
  long long *v2; // r13
  unsigned int v4; // eax
  char v5[24]; // [rsp-18h] [rbp-20038h] BYREF
  char v6; // [rsp+0h] [rbp-20020h] BYREF
  long long v7[15876]; // [rsp+1000h] [rbp-1F020h] BYREF

  while ( &v6 != (char *)&v7[-16384] )
    ;
  v7[15870] = __readfsqword(0x28u);
  v2 = a1;
  if ( a2 && *a2 && !sub_7F10("HOME", (const char **)a1) )
  {
    if ( (unsigned int)sub_8130(v5, &unk_20000, "HOME", a2, 61) )
    {
      return sub_7940(a1, v5);
    }
    else
    {
      v4 = getpid();
      sub_8720("CRON", v4, "ERROR", "can't set HOME", 0);
    }
  }
  return v2;
}


// Function: mkprint @ 0x8080
long long mkprint(char *a1, unsigned char *a2, long long a3)
{
  unsigned char *v4; // rbx
  unsigned char *v5; // r12
  int v6; // r8d
  long long result; // rax
  char *v8; // rdi

  if ( a3 )
  {
    v4 = a2;
    v5 = &a2[a3];
    do
    {
      while ( 1 )
      {
        v6 = *v4++;
        if ( (unsigned char)v6 > 0x1Fu )
          break;
        *a1 = 94;
        a1 += 2;
        *(a1 - 1) = v6 + 64;
LABEL_4:
        if ( v5 == v4 )
          goto LABEL_8;
      }
      if ( (unsigned char)v6 > 0x7Eu )
      {
        if ( (char)v6 == 127 )
        {
          result = 16222;
          a1 += 2;
          *((short *)a1 - 1) = 16222;
        }
        else
        {
          v8 = a1;
          a1 += 4;
          result = __sprintf_chk(v8, 1, -1, "\\%03o", v6);
        }
        goto LABEL_4;
      }
      *a1++ = v6;
    }
    while ( v5 != v4 );
  }
LABEL_8:
  *a1 = 0;
  return result;
}


// Function: glue_strings @ 0x8130
long long glue_strings(char *a1, long long a2, char *a3, char *a4, char a5)
{
  char *v6; // r9
  char *v7; // rsi
  char *v8; // rax
  char v9; // di
  char *v10; // rdx

  if ( !a2 )
    return 0;
  v6 = &a1[a2];
  if ( a1 >= &a1[a2] )
  {
    v8 = a1;
    if ( a1 == &a1[a2] )
      return 0;
    goto LABEL_9;
  }
  v7 = &a3[a2];
  v8 = a1;
  while ( 1 )
  {
    v9 = *a3;
    if ( !*a3 )
      break;
    ++a3;
    *v8++ = v9;
    if ( v7 == a3 )
    {
      if ( v6 == v8 )
        return 0;
      break;
    }
  }
  if ( a5 != 47 || a1 == v8 || (v10 = v8, *(v8 - 1) != 47) )
  {
LABEL_9:
    *v8 = a5;
    v10 = v8 + 1;
  }
  if ( v10 != v6 )
  {
    if ( v10 >= v6 )
      goto LABEL_16;
    while ( *a4 )
    {
      *v10++ = *a4++;
      if ( v6 == v10 )
        return 0;
    }
    if ( v6 != v10 )
    {
LABEL_16:
      *v10 = 0;
      return 1;
    }
  }
  return 0;
}


// Function: strcmp_until @ 0x81d0
long long strcmp_until(char *a1, char *a2, char a3)
{
  int v3; // eax
  int v4; // ecx

  v3 = (char)*a1;
  if ( *a1 )
  {
    do
    {
      v4 = (char)*a2;
      if ( (char)v3 == a3 )
        break;
      if ( (char)v3 != (char)v4 )
        return (unsigned int)(v3 - v4);
      v3 = (char)*++a1;
      ++a2;
    }
    while ( (char)v3 );
  }
  v4 = (char)*a2;
  if ( *a2 == a3 || !(char)v4 )
    return 0;
  else
    return (unsigned int)(v3 - v4);
}


// Function: strdtb @ 0x8220
long long strdtb(unsigned char *a1)
{
  unsigned char *v1; // rbx
  unsigned char *v2; // r12

  v1 = a1;
  if ( !*a1 )
    goto LABEL_5;
  do
    ++v1;
  while ( *v1 );
  v2 = v1--;
  if ( a1 <= v1 )
  {
    while ( ((*__ctype_b_loc())[*v1] & 0x2000) != 0 )
    {
LABEL_5:
      v2 = v1--;
      if ( a1 > v1 )
        break;
    }
  }
  v1[1] = 0;
  return v2 - a1;
}


// Function: set_debug_flags @ 0x8280
long long set_debug_flags(const char *a1)
{
  char *v1; // r9
  char *v3; // rbp
  char *v4; // rdi
  long long v5; // r10
  int v6; // r11d
  int v7; // r11d
  char i; // al
  long long v10; // rbp
  const char *j; // rcx
  int v12; // eax

  v1 = (char *)a1;
  v3 = off_E020[0];
  dword_E2C0 = 0;
  if ( *a1 )
  {
    do
    {
      if ( !v3 )
      {
LABEL_13:
        __fprintf_chk(stderr, 1, "unrecognized debug flag <%s> <%s>\n", a1, v1);
        return 0;
      }
      v4 = v3;
      while ( (unsigned int)sub_81D0(v4, v1, 44) )
      {
        v4 = *(char **)(v5 + 8);
        if ( !v4 )
          goto LABEL_13;
      }
      v7 = dword_E2C0 | v6;
      dword_E2C0 = v7;
      for ( i = *v1; i; i = *++v1 )
      {
        if ( i == 44 )
          break;
      }
      v1 += i == 44;
    }
    while ( *v1 );
    if ( v7 )
    {
      v10 = 0;
      __fprintf_chk(stderr, 1, "debug flags enabled:");
      for ( j = off_E020[0]; j; j = off_E020[v10] )
      {
        while ( 1 )
        {
          v12 = dword_E2C0;
          if ( _bittest(&v12, v10) )
            break;
          j = off_E020[++v10];
          if ( !j )
            goto LABEL_19;
        }
        ++v10;
        __fprintf_chk(stderr, 1, " %s", j);
      }
LABEL_19:
      __fprintf_chk(stderr, 1, "\n");
    }
  }
  return 1;
}


// Function: set_cron_uid @ 0x8400
int set_cron_uid()
{
  int result; // eax

  result = setuid(0);
  if ( result < 0 )
  {
    perror("setuid");
    exit(1);
  }
  return result;
}


// Function: check_spool_dir @ 0x8430
unsigned long long check_spool_dir()
{
  struct stat _0; // [rsp+0h] [rbp+0h] BYREF
  unsigned long long vars98; // [rsp+98h] [rbp+98h]

  vars98 = __readfsqword(0x28u);
  if ( stat("/usr/local/var/spool/cron", &_0) < 0 && *__errno_location() == 2 )
  {
    perror("/usr/local/var/spool/cron");
    if ( mkdir("/usr/local/var/spool/cron", 0x1C0u) )
    {
      __fprintf_chk(stderr, 1, "%s: ", "/usr/local/var/spool/cron");
      perror("mkdir");
      exit(1);
    }
    __fprintf_chk(stderr, 1, "%s: created\n", "/usr/local/var/spool/cron");
    if ( stat("/usr/local/var/spool/cron", &_0) < 0 )
    {
      perror("stat retry");
      exit(1);
    }
  }
  if ( (_0.st_mode & 0xF000) != 0x4000 )
  {
    __fprintf_chk(stderr, 1, "'%s' is not a directory, bailing out.\n", "/usr/local/var/spool/cron");
    exit(1);
  }
  return vars98 - __readfsqword(0x28u);
}


// Function: get_char @ 0x8570
long long get_char(FILE *a1)
{
  unsigned int v1; // r12d

  v1 = getc(a1);
  if ( v1 != 10 )
    return v1;
  if ( (dword_E2C0 & 9) != 0 )
    __printf_chk(1, "linenum=%d\n", dword_4E2FC + 1);
  ++dword_4E2FC;
  return v1;
}


// Function: unget_char @ 0x85d0
int unget_char(int a1, FILE *a2)
{
  int result; // eax

  result = ungetc(a1, a2);
  if ( a1 == 10 )
  {
    if ( (dword_E2C0 & 9) != 0 )
      result = __printf_chk(1, "linenum=%d\n", dword_4E2FC - 1);
    --dword_4E2FC;
  }
  return result;
}


// Function: get_string @ 0x8620
long long get_string(char *a1, int a2, FILE *a3, const char *a4)
{
  int v8; // eax
  unsigned int v9; // r12d

  while ( 1 )
  {
    v8 = sub_8570(a3);
    v9 = v8;
    if ( v8 == -1 || strchr(a4, v8) )
      break;
    if ( a2 > 1 )
    {
      ++a1;
      --a2;
      *(a1 - 1) = v9;
    }
  }
  if ( a2 > 0 )
    *a1 = 0;
  return v9;
}


// Function: skip_comments @ 0x8690
long long skip_comments(FILE *a1)
{
  int v1; // ebx
  int v2; // eax

  v1 = 0;
  while ( 1 )
  {
    v2 = sub_8570(a1);
    if ( v2 == -1 )
      break;
    while ( 1 )
    {
      if ( ++v1 == 32769 )
        return 0;
      if ( v2 != 32 && v2 != 9 )
        break;
      v2 = sub_8570(a1);
    }
    if ( v2 == -1 )
      return 1;
    if ( v2 != 10 )
    {
      if ( v2 != 35 )
      {
        sub_85D0(v2, a1);
        return 1;
      }
      while ( v2 != 10 && v2 != -1 )
      {
        ++v1;
        v2 = sub_8570(a1);
        if ( v1 == 32769 )
          return 0;
      }
    }
  }
  return 1;
}


// Function: log_it @ 0x8720
char *log_it(const char *a1, int a2, const char *a3, const char *a4, int a5)
{
  const char *v8; // rbx
  char *result; // rax
  char *v10; // rax

  if ( !dword_915B0 )
  {
    openlog(ident, 1, 72);
    dword_915B0 = 1;
  }
  if ( !a5 )
  {
    v8 = "";
    __syslog_chk(6, 1, "(%s) %s (%s)%s%s", a1, a3, a4, "", "");
    result = "";
    if ( !dword_E2C0 )
      return result;
    return (char *)__fprintf_chk(stderr, 1, "log_it: (%s %ld) %s (%s)%s%s\n", a1, a2, a3, a4, v8, result);
  }
  v8 = ": ";
  v10 = strerror(a5);
  result = (char *)__syslog_chk(3, 1, "(%s) %s (%s)%s%s", a1, a3, a4, ": ", v10);
  if ( dword_E2C0 )
  {
    result = strerror(a5);
    return (char *)__fprintf_chk(stderr, 1, "log_it: (%s %ld) %s (%s)%s%s\n", a1, a2, a3, a4, v8, result);
  }
  return result;
}


// Function: acquire_daemonlock @ 0x8850
__sighandler_t acquire_daemonlock(int a1)
{
  __pid_t v1; // eax
  int v2; // ebp
  int v3; // r14d
  size_t v4; // r12
  int *v5; // rax
  int v7; // eax
  int v8; // r12d
  int *v9; // rax
  int v10; // r13d
  char *v11; // rax
  int v12; // r8d
  int v13; // r14d
  long long v14; // rax
  char *v15; // rax
  char *endptr; // [rsp+8h] [rbp-3040h] BYREF
  char s[16]; // [rsp+10h] [rbp-3038h] BYREF
  unsigned long long v18; // [rsp+3018h] [rbp-30h]

  v18 = __readfsqword(0x28u);
  v1 = getpid();
  if ( !a1 )
  {
    v2 = v1;
    if ( fd != -1 )
    {
LABEL_3:
      __sprintf_chk(s, 1, 12288, "%ld\n", v2);
      v3 = fd;
      lseek(fd, 0, 0);
      v4 = strlen(s);
      if ( v4 == write(v3, s, v4) )
      {
        if ( ftruncate(fd, v4) == -1 )
        {
          v9 = __errno_location();
          sub_8720("CRON", v2, "ERROR", "ftruncate() failed", *v9);
        }
      }
      else
      {
        v5 = __errno_location();
        sub_8720("CRON", v2, "ERROR", "write() failed", *v5);
      }
      return (__sighandler_t)(v18 - __readfsqword(0x28u));
    }
    v7 = open("/usr/local/var/run/crond.pid", 66, 384);
    fd = v7;
    v8 = v7;
    if ( v7 == -1 )
    {
      v10 = *__errno_location();
      __sprintf_chk(s, 1, 12288, "can't open or create %s", "/usr/local/var/run/crond.pid");
      v11 = strerror(v10);
      __fprintf_chk(stderr, 1, "%s: %s: %s\n", ident, s, v11);
      v12 = v10;
    }
    else
    {
      if ( flock(v7, 6) >= 0 )
      {
        fchmod(v8, 0x1A4u);
        fcntl(v8, 2, 1);
        goto LABEL_3;
      }
      v13 = *__errno_location();
      memset(s, 0, 0x3000u);
      if ( read(v8, s, 0x2FFFu) <= 0
        || (v14 = strtol(s, &endptr, 10), v14 <= 0)
        || endptr == s
        || *endptr != 10
        || v14 == 0x7FFFFFFFFFFFFFFFLL )
      {
        __snprintf_chk(s, 12288, 1, 12288, "can't lock %s, otherpid unknown", "/usr/local/var/run/crond.pid");
      }
      else
      {
        __snprintf_chk(s, 12288, 1, 12288, "can't lock %s, otherpid may be %ld", "/usr/local/var/run/crond.pid", v14);
      }
      v15 = strerror(v13);
      __fprintf_chk(stderr, 1, "%s: %s: %s\n", ident, s, v15);
      v12 = v13;
    }
    sub_8720("CRON", v2, "DEATH", s, v12);
    exit(1);
  }
  if ( fd != -1 )
  {
    close(fd);
    fd = -1;
  }
  signal(2, 0);
  return signal(15, 0);
}


// Function: log_close @ 0x8be0
void log_close()
{
  if ( dword_E22C != -1 )
  {
    close(dword_E22C);
    dword_E22C = -1;
  }
  closelog();
  dword_915B0 = 0;
}


// Function: first_word @ 0x8c20
char *first_word(char *a1, const char *a2)
{
  char *v3; // rbx
  int v4; // esi
  char *v5; // r13
  char v6; // r14
  char *v7; // rbp

  v3 = a1;
  v4 = *a1;
  dword_915A4 = 1 - dword_915A4;
  v5 = (char *)&unk_515A0 + 131073 * dword_915A4;
  if ( !(char)v4 )
    goto LABEL_11;
  while ( strchr(a2, v4) )
  {
    v4 = *++v3;
    if ( !(char)v4 )
      goto LABEL_11;
  }
  v6 = *v3;
  if ( *v3 )
  {
    v7 = v5;
    do
    {
      if ( strchr(a2, v6) )
        break;
      if ( &byte_20000[(long long)v5] == v7 )
        break;
      ++v3;
      *v7++ = v6;
      v6 = *v3;
    }
    while ( *v3 );
  }
  else
  {
LABEL_11:
    v7 = v5;
  }
  *v7 = 0;
  return v5;
}


// Function: mkprints @ 0x8cf0
char *mkprints(unsigned char *a1, long long a2)
{
  char *v2; // rax
  char *v3; // r12

  v2 = malloc(4 * a2 + 1);
  v3 = v2;
  if ( v2 )
    sub_8080(v2, a1, a2);
  return v3;
}


// Function: swap_uids @ 0x8d30
long long swap_uids()
{
  __gid_t v0; // eax
  __uid_t v1; // eax

  gid = getegid();
  uid = geteuid();
  v0 = getgid();
  if ( setegid(v0) )
    return 0xFFFFFFFFLL;
  v1 = getuid();
  return (unsigned int)-(seteuid(v1) != 0);
}


// Function: swap_uids_back @ 0x8d80
long long swap_uids_back()
{
  if ( setegid(gid) )
    return 0xFFFFFFFFLL;
  else
    return (unsigned int)-(seteuid(uid) != 0);
}


// Function: strlens @ 0x8dc0
long long strlens(
        const char *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        ...)
{
  long long v9; // r12
  unsigned int gp_offset; // eax
  const char *v11; // kr00_8
  gcc_va_list va; // [rsp+0h] [rbp-68h] BYREF

  va_start(va, a9);
  if ( !a1 )
    return 0;
  v9 = 0;
  do
  {
    while ( 1 )
    {
      v9 += strlen(a1);
      gp_offset = va[0].gp_offset;
      if ( va[0].gp_offset > 0x2F )
        break;
      va[0].gp_offset += 8;
      a1 = *(const char **)((char *)va[0].reg_save_area + gp_offset);
      if ( !a1 )
        return v9;
    }
    v11 = va_arg(va, const char *);
    a1 = v11;
  }
  while ( v11 );
  return v9;
}


// Function: pw_dup @ 0x8e90
long long *pw_dup(const __m128i *a1)
{
  const char *v2; // rdi
  size_t v3; // rax
  size_t v4; // r15
  const char *v5; // rdi
  size_t v6; // r13
  const char *v7; // rdi
  size_t v8; // r12
  const char *v9; // rdi
  size_t v10; // rbp
  const char *v11; // rdi
  size_t v12; // r14
  __m128i *v13; // rax
  long long *v14; // r15
  __m128i v15; // xmm1
  __m128i *v16; // rcx
  __m128i v17; // xmm2
  const void *v18; // rsi
  char *v19; // rax
  const void *v20; // rsi
  char *v21; // rax
  const void *v22; // rsi
  char *v23; // rax
  const void *v24; // rsi
  char *v25; // rax
  const void *v26; // rsi
  size_t n; // [rsp+8h] [rbp-40h]

  v2 = (const char *)a1->m128i_i64[0];
  if ( v2 )
  {
    v3 = strlen(v2);
    v4 = v3 + 49;
    n = v3 + 1;
  }
  else
  {
    n = 0;
    v4 = 48;
  }
  v5 = (const char *)a1->m128i_i64[1];
  v6 = 0;
  if ( v5 )
  {
    v6 = strlen(v5) + 1;
    v4 += v6;
  }
  v7 = (const char *)a1[1].m128i_i64[1];
  v8 = 0;
  if ( v7 )
  {
    v8 = strlen(v7) + 1;
    v4 += v8;
  }
  v9 = (const char *)a1[2].m128i_i64[0];
  v10 = 0;
  if ( v9 )
  {
    v10 = strlen(v9) + 1;
    v4 += v10;
  }
  v11 = (const char *)a1[2].m128i_i64[1];
  v12 = 0;
  if ( v11 )
  {
    v12 = strlen(v11) + 1;
    v4 += v12;
  }
  v13 = (__m128i *)malloc(v4);
  v14 = (long long *)v13;
  if ( v13 )
  {
    v15 = _mm_loadu_si128(a1 + 1);
    v16 = v13 + 3;
    v17 = _mm_loadu_si128(a1 + 2);
    v18 = (const void *)a1->m128i_i64[0];
    *v13 = _mm_loadu_si128(a1);
    v13[1] = v15;
    v13[2] = v17;
    if ( v18 )
    {
      v19 = (char *)memcpy(&v13[3], v18, n);
      *v14 = (long long)v19;
      v16 = (__m128i *)&v19[n];
    }
    v20 = (const void *)a1->m128i_i64[1];
    if ( v20 )
    {
      v21 = (char *)memcpy(v16, v20, v6);
      v14[1] = (long long)v21;
      v16 = (__m128i *)&v21[v6];
    }
    v22 = (const void *)a1[1].m128i_i64[1];
    if ( v22 )
    {
      v23 = (char *)memcpy(v16, v22, v8);
      v14[3] = (long long)v23;
      v16 = (__m128i *)&v23[v8];
    }
    v24 = (const void *)a1[2].m128i_i64[0];
    if ( v24 )
    {
      v25 = (char *)memcpy(v16, v24, v10);
      v14[4] = (long long)v25;
      v16 = (__m128i *)&v25[v10];
    }
    v26 = (const void *)a1[2].m128i_i64[1];
    if ( v26 )
      v14[5] = (long long)memcpy(v16, v26, v12);
  }
  return v14;
}


