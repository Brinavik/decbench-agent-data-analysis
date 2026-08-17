// Function: main @ 0x2a40
void main(int a1, char **a2, char **a3)
{
  int *v4; // rax
  int *v5; // r15
  __uid_t v6; // eax
  __uid_t v7; // eax
  const char *v8; // rdx
  char *v9; // rdi
  long long v10; // rcx
  int v11; // eax
  char *v12; // rax
  long long v13; // r12
  FILE *v14; // r14
  char *v15; // rax
  char v16; // dl
  FILE *v17; // rax
  FILE *v18; // r12
  int v19; // r12d
  long long v20; // r12
  size_t v21; // rax
  const char *v22; // r15
  const char *v23; // rdx
  int v24; // eax
  char v25; // bl
  int v26; // eax
  FILE *v27; // rdi
  char *p_file; // r14
  struct utmp *v29; // rax
  struct utmp *v30; // r12
  __dev_t st_rdev; // r13
  const char *ut_user; // r12
  long long i; // r14
  const char *v34; // rdi
  FILE *v35; // rax
  FILE *v36; // rbp
  FILE *v37; // rbp
  __pid_t v38; // eax
  long long v39; // rcx
  __sigset_t *p_sa_mask; // rdi
  char *j; // rdx
  char v42; // al
  const char *v43; // rbp
  unsigned long long v44; // rsi
  struct tm *v45; // rax
  int v46; // r12d
  int v47; // r12d
  long long v48; // rdx
  time_t v49; // rbp
  unsigned int v50; // r14d
  int v51; // eax
  int v52; // eax
  int v53; // eax
  unsigned int v54; // [rsp+0h] [rbp-3B8h]
  int v55; // [rsp+4h] [rbp-3B4h]
  char *src; // [rsp+8h] [rbp-3B0h]
  int buf; // [rsp+10h] [rbp-3A8h]
  struct stat *bufa; // [rsp+10h] [rbp-3A8h]
  char modes; // [rsp+20h] [rbp-398h]
  int modesa; // [rsp+20h] [rbp-398h]
  const char *v61; // [rsp+28h] [rbp-390h]
  char *v62; // [rsp+28h] [rbp-390h]
  int v63; // [rsp+3Ch] [rbp-37Ch] BYREF
  int v64; // [rsp+40h] [rbp-378h] BYREF
  __pid_t pid; // [rsp+44h] [rbp-374h] BYREF
  time_t timer; // [rsp+48h] [rbp-370h] BYREF
  struct stat v67; // [rsp+50h] [rbp-368h] BYREF
  struct sigaction act; // [rsp+E0h] [rbp-2D8h] BYREF
  long long v69[32]; // [rsp+180h] [rbp-238h]
  char file; // [rsp+280h] [rbp-138h] BYREF
  char v71[64]; // [rsp+2B0h] [rbp-108h] BYREF
  char s[136]; // [rsp+2F0h] [rbp-C8h] BYREF
  unsigned long long v73; // [rsp+378h] [rbp-40h]

  v73 = __readfsqword(0x28u);
  pid = 0;
  v4 = __errno_location();
  *v4 = 0;
  v5 = v4;
  v6 = geteuid();
  if ( setuid(v6) == -1 )
  {
    v12 = strerror(*v5);
    __fprintf_chk(stderr, 1, "%s (%d): %s\n", "shutdown.c", 541, v12);
    abort();
  }
  v7 = getuid();
  v8 = "shutdown: you must be root to do that!\n";
  if ( v7 )
    goto LABEL_12;
  v9 = v71;
  v10 = 16;
  word_8268 = 49;
  while ( v10 )
  {
    *(int *)v9 = 0;
    v9 += 4;
    --v10;
  }
  v54 = 0;
  buf = 0;
  v55 = 0;
  src = 0;
  while ( 2 )
  {
    v11 = getopt(a1, a2, "HPacqQkrhnfFyt:g:i:");
    if ( v11 != -1 )
    {
      switch ( v11 )
      {
        case 'F':
          dword_8260 = 1;
          continue;
        case 'H':
          src = (char *)"HALT";
          continue;
        case 'P':
          src = "POWEROFF";
          continue;
        case 'Q':
          v54 = 2;
          continue;
        case 'a':
          buf = 1;
          continue;
        case 'c':
          v55 = 1;
          continue;
        case 'f':
          dword_8264 = 1;
          continue;
        case 'g':
          strncpy(v71, optarg, 0x3Fu);
          continue;
        case 'h':
          LOBYTE(word_8268) = 48;
          continue;
        case 'i':
          v61 = optarg;
          modes = *optarg;
          if ( !strchr("0156aAbBcCsS", *optarg) )
          {
            __fprintf_chk(stderr, 1, "shutdown: `%s': bad runlevel\n", v61);
            exit(1);
          }
          LOBYTE(word_8268) = modes;
          continue;
        case 'k':
          dword_826C = 1;
          continue;
        case 'n':
          dword_80E4 = 1;
          continue;
        case 'q':
          v54 = 1;
          continue;
        case 'r':
          LOBYTE(word_8268) = 54;
          continue;
        case 't':
          nptr = optarg;
          continue;
        case 'y':
          continue;
        default:
          goto LABEL_13;
      }
    }
    break;
  }
  if ( src && (char)word_8268 != 48 )
  {
    v8 = "shutdown: -H and -P flags can only be used along with -h flag.\n";
LABEL_12:
    __fprintf_chk(stderr, 1, v8);
    goto LABEL_13;
  }
  if ( buf )
  {
    v13 = 0;
    v14 = fopen("/etc/shutdown.allow", "r");
    if ( v14 )
    {
      while ( fgets(s, 128, v14) )
      {
        if ( s[0] != 10 && s[0] != 35 && (int)v13 <= 31 )
        {
          v15 = s;
          if ( s[0] )
          {
            while ( 1 )
            {
              v16 = *++v15;
              if ( !v16 )
                break;
              if ( v16 == 10 )
                *v15 = 0;
            }
          }
          v69[v13++] = strdup(s);
        }
      }
      if ( (int)v13 != 32 )
        v69[(int)v13] = 0;
      v27 = v14;
      p_file = &file;
      fclose(v27);
      while ( 1 )
      {
        v29 = getutent();
        v30 = v29;
        if ( !v29 )
          break;
        if ( v29->ut_type == 7 )
        {
          __sprintf_chk(p_file, 1, 38, "/dev/%.*s", 32, v29->ut_line);
          if ( stat(p_file, &v67) >= 0 )
          {
            st_rdev = v67.st_rdev;
            if ( gnu_dev_major(v67.st_rdev) == 4 && gnu_dev_minor(st_rdev) <= 0x3F )
            {
              ut_user = v30->ut_user;
              if ( !strcmp(ut_user, "root") )
              {
LABEL_40:
                endutent();
                goto LABEL_41;
              }
              v62 = p_file;
              for ( i = 0; i != 32; ++i )
              {
                v34 = (const char *)v69[i];
                if ( !v34 )
                  break;
                if ( !strncmp(v34, ut_user, 0x20u) )
                  goto LABEL_40;
              }
              p_file = v62;
            }
          }
        }
      }
      endutent();
      v35 = fopen("/dev/console", "w");
      v36 = v35;
      if ( v35 )
      {
        __fprintf_chk(v35, 1, "\rshutdown: no authorized users logged in.\r\n");
        fclose(v36);
      }
LABEL_68:
      exit(1);
    }
  }
LABEL_41:
  v17 = fopen("/var/run/shutdown.pid", "r");
  v18 = v17;
  if ( v17 )
  {
    if ( fscanf(v17, "%d", &pid) != 1 )
      pid = 0;
    fclose(v18);
  }
  v19 = 0;
  byte_8160 = 0;
  if ( !v55 )
    v19 = v71[0] == 0;
  bufa = (struct stat *)v5;
  modesa = optind;
  v20 = optind + v19;
  while ( a1 > (int)v20 )
  {
    v21 = strlen(&byte_8160);
    v22 = a2[v20++];
    if ( v21 + strlen(v22) + 4 > 0x100 )
      break;
    __strcat_chk(&byte_8160, v22, 256);
    __strcat_chk(&byte_8160, " ", 256);
  }
  if ( byte_8160 )
    __strcat_chk(&byte_8160, "\r\n", 256);
  if ( v55 )
  {
    v23 = "shutdown: cannot find pid of running shutdown.\n";
    if ( pid > 0 )
    {
      sub_3800("INIT_HALT", 0);
      v26 = kill(pid, 2);
      v23 = "shutdown: not running.\n";
      if ( v26 >= 0 )
      {
        if ( byte_8160 )
          sub_4540(&byte_8160, 0, "shutdown: not running.\n");
        exit(0);
      }
    }
    goto LABEL_67;
  }
  if ( !v71[0] )
  {
    if ( modesa == a1 )
      goto LABEL_13;
    optind = modesa + 1;
    strncpy(v71, a2[modesa], 0x3Fu);
  }
  if ( pid > 0 && !kill(pid, 0) )
  {
    __fprintf_chk(stderr, 1, "\rshutdown: already running.\r\n");
    exit(1);
  }
  if ( dword_80E4 )
  {
    if ( (char)word_8268 != 48 )
    {
      v23 = "shutdown: can use \"-n\" for halt or reboot only.\r\n";
      if ( (char)word_8268 != 54 )
        goto LABEL_67;
    }
  }
  switch ( (char)word_8268 )
  {
    case '1':
      strncpy(dest, "to maintenance mode", 0x40u);
      break;
    case '6':
      strncpy(dest, "for reboot", 0x40u);
      break;
    case '0':
      strncpy(dest, "for system halt", 0x40u);
      break;
    default:
      __snprintf_chk(dest, 64, 1, 64, "to runlevel %s", (const char *)&word_8268);
      break;
  }
  v24 = chdir("/");
  v25 = v24;
  if ( v24 )
  {
    v23 = "shutdown: chdir(/): %m\n";
LABEL_67:
    __fprintf_chk(stderr, 1, v23);
    goto LABEL_68;
  }
  unlink("/var/run/shutdown.pid");
  umask(0x12u);
  v37 = fopen("/var/run/shutdown.pid", "w");
  if ( v37 )
  {
    v38 = getpid();
    __fprintf_chk(v37, 1, "%d\n", v38);
    fclose(v37);
  }
  else if ( LODWORD(bufa->st_dev) != 30 )
  {
    __fprintf_chk(stderr, 1, "shutdown: warning: cannot open %s\n", "/var/run/shutdown.pid");
  }
  signal(3, (__sighandler_t)((char *)&dword_0 + 1));
  signal(17, (__sighandler_t)((char *)&dword_0 + 1));
  signal(1, (__sighandler_t)((char *)&dword_0 + 1));
  signal(20, (__sighandler_t)((char *)&dword_0 + 1));
  signal(21, (__sighandler_t)((char *)&dword_0 + 1));
  signal(22, (__sighandler_t)((char *)&dword_0 + 1));
  v39 = 36;
  p_sa_mask = &act.sa_mask;
  while ( v39 )
  {
    LODWORD(p_sa_mask->__val[0]) = 0;
    p_sa_mask = (__sigset_t *)((char *)p_sa_mask + 4);
    --v39;
  }
  act.sa_handler = (__sighandler_t)sub_36F0;
  sigaction(2, &act, 0);
  if ( dword_8264 )
  {
    v53 = open("/fastboot", 66, 420);
    close(v53);
  }
  if ( dword_8260 )
  {
    v52 = open("/forcefsck", 66, 420);
    close(v52);
  }
  if ( !strcmp(v71, "now") )
    *(short *)v71 = 48;
  for ( j = v71; ; ++j )
  {
    v42 = *j;
    if ( !*j )
      break;
    if ( v42 != 43 && (unsigned char)(v42 - 48) > 0xAu )
      goto LABEL_13;
  }
  v43 = v71;
  if ( v71[0] == 43 )
    v43 = &v71[1];
  v44 = 58;
  if ( strchr(v71, 58) )
  {
    v44 = (unsigned long long)"%d:%2d";
    if ( sscanf(v71, "%d:%2d", &v63, &v64) == 2 )
    {
      if ( v71[0] == 43 )
      {
        if ( v63 <= 99999 && v64 <= 59 )
        {
          v47 = v64 + 60 * v63;
          if ( v47 >= 0 )
          {
LABEL_117:
            if ( !v47 )
              goto LABEL_118;
            goto LABEL_124;
          }
        }
      }
      else if ( v63 <= 23 && v64 <= 59 )
      {
        time(&timer);
        v45 = localtime(&timer);
        v46 = v64 + 60 * v63 - (v45->tm_min + 60 * v45->tm_hour);
        v47 = v46 + (v46 < 0 ? 0x5A0 : 0);
        goto LABEL_117;
      }
    }
  }
  else
  {
    v47 = atoi(v43);
    if ( v47 )
    {
LABEL_124:
      time(&timer);
      v49 = timer + 60 * v47;
      if ( v47 > 14 || (v44 = v54, (unsigned int)sub_3650((unsigned int)v47, v54)) )
      {
        v50 = v54;
      }
      else
      {
        sub_3A30((unsigned int)v47);
        v50 = v54;
      }
      while ( 1 )
      {
        if ( v47 <= 5 && (v25 & 1) == 0 )
        {
          v25 = 1;
          sub_3B20((unsigned int)v47, v44, v48);
        }
        v44 = v50;
        if ( (unsigned int)sub_3650((unsigned int)v47, v50) )
          sub_3A30((unsigned int)v47);
        sub_3750(60);
        time(&timer);
        if ( timer >= v49 )
          goto LABEL_118;
        v51 = v49 - timer;
        if ( v49 - timer <= 60 )
          break;
        v48 = (unsigned int)(v51 >> 31);
        LODWORD(v48) = v51 % 60;
        v47 = v51 / 60;
        if ( !(v51 / 60) )
          goto LABEL_118;
      }
      sub_3750((unsigned int)v51);
LABEL_118:
      sub_4030(src);
    }
    if ( *v43 == 48 )
      goto LABEL_118;
  }
LABEL_13:
  sub_37D0();
}


// Function: alrm_handler @ 0x3640
void alrm_handler(int a1)
{
  dword_80E0 = a1;
}


// Function: needwarning @ 0x3650
long long needwarning(int a1, int a2)
{
  long long result; // rax

  result = 0;
  if ( a2 != 2 )
  {
    if ( a2 == 1 )
    {
      if ( a1 == 10 || a1 == 5 )
        return 1;
    }
    else
    {
      result = 1;
      if ( a1 <= 9 )
        return result;
      if ( a1 <= 59 )
        return (unsigned int)(-286331153 * a1 + 143165576) <= 0x11111110;
      if ( a1 <= 179 )
        return __ROR4__(-286331153 * a1 + 143165576, 1) <= 0x8888888u;
    }
    return __ROR4__(-286331153 * a1 + 143165576, 2) <= 0x4444444u;
  }
  return result;
}


// Function: stopit @ 0x36f0
void stopit()
{
  unlink("/etc/nologin");
  unlink("/fastboot");
  unlink("/forcefsck");
  unlink("/var/run/shutdown.pid");
  __printf_chk(1, "\r\nShutdown cancelled.\r\n");
  exit(0);
}


// Function: hardsleep @ 0x3750
unsigned long long hardsleep(int a1)
{
  unsigned __int128 i; // [rsp+0h] [rbp-48h] BYREF
  struct timespec remaining; // [rsp+10h] [rbp-38h] BYREF
  unsigned long long v4; // [rsp+28h] [rbp-20h]

  v4 = __readfsqword(0x28u);
  for ( i = (unsigned long long)a1;
        nanosleep((const struct timespec *)&i, &remaining) < 0 && *__errno_location() == 4;
        i = (unsigned __int128)_mm_load_si128((const __m128i *)&remaining) )
  {
    ;
  }
  return v4 - __readfsqword(0x28u);
}


// Function: usage @ 0x37d0
void usage()
{
  __fprintf_chk(
    stderr,
    1,
    "Usage:\t  shutdown [-akrhPHfFnc] [-t sec] time [warning message]\n"
    "\t\t  -a:      use /etc/shutdown.allow\n"
    "\t\t  -k:      don't really shutdown, only warn.\n"
    "\t\t  -r:      reboot after shutdown.\n"
    "\t\t  -h:      halt after shutdown.\n"
    "\t\t  -P:      halt action is to turn off power.\n"
    "\t\t           can only be used along with -h flag.\n"
    "\t\t  -H:      halt action is to just halt.\n"
    "\t\t           can only be used along with -h flag.\n"
    "\t\t  -f:      do a 'fast' reboot (skip fsck).\n"
    "\t\t  -F:      Force fsck on reboot.\n"
    "\t\t  -n:      do not go through \"init\" but go down real fast.\n"
    "\t\t  -c:      cancel a running shutdown.\n"
    "\t\t  -q:      quiet mode - display fewer shutdown warnings.\n"
    "\t\t  -Q:      full quiet mode - display only final shutdown warning.\n"
    "\t\t  -t secs: delay between warning and kill signal.\n"
    "\t\t  ** the \"time\" argument is mandatory! (try \"now\") **\n");
  exit(1);
}


// Function: init_setenv @ 0x3800
long long init_setenv(char *s, const char *src)
{
  long long *v2; // rbx
  size_t v3; // rax
  size_t v4; // r12
  size_t v5; // rax
  unsigned long long v6; // rdx
  size_t v7; // r14
  long long result; // rax
  long long v9; // rax
  int v10; // ebp
  size_t v11; // r12
  ssize_t v12; // rax
  int v13; // eax
  struct sigaction v14; // [rsp+0h] [rbp-258h] BYREF
  long long buf[55]; // [rsp+A0h] [rbp-1B8h] BYREF

  buf[49] = __readfsqword(0x28u);
  v2 = buf;
  memset(buf, 0, 0x180u);
  buf[0] = 0x603091969LL;
  v3 = strlen(s);
  v4 = v3;
  if ( src )
  {
    v5 = strlen(src);
    v6 = v4 + v5 + 3;
    v7 = v5;
    result = 0xFFFFFFFFLL;
    if ( v6 > 0x16F )
      return result;
    v9 = __memcpy_chk(&buf[2], s, v4, 368);
    *((char *)&buf[2] + v4) = 61;
    memcpy((void *)(v9 + v4 + 1), src, v7);
  }
  else
  {
    if ( v3 + 3 > 0x16F )
      return 0xFFFFFFFFLL;
    __memcpy_chk(&buf[2], s, v3, 368);
  }
  memset(&v14.sa_mask, 0, 0x90u);
  v14.sa_handler = sub_3640;
  sigaction(14, &v14, 0);
  dword_80E0 = 0;
  alarm(3u);
  v10 = open("/run/initctl", 1);
  if ( v10 < 0 )
  {
    __fprintf_chk(stderr, 1, "shutdown: ");
    if ( dword_80E0 )
      __fprintf_chk(stderr, 1, "timeout opening/writing control channel %s\n", "/run/initctl");
    else
      perror("/run/initctl");
    return 0xFFFFFFFFLL;
  }
  else
  {
    v11 = 384;
    do
    {
      while ( 1 )
      {
        v12 = write(v10, v2, v11);
        if ( v12 < 0 )
          break;
        v2 = (long long *)((char *)v2 + v12);
        v11 -= v12;
        if ( !v11 )
          goto LABEL_8;
      }
      v13 = *__errno_location();
    }
    while ( v13 == 4 || v13 == 11 );
LABEL_8:
    close(v10);
    alarm(0);
    return 0;
  }
}


// Function: issue_warn @ 0x3a30
unsigned long long issue_warn(int a1)
{
  int v1; // eax
  const char *v2; // rdx
  long long v3; // rdx
  long long v5; // [rsp-8h] [rbp-8h]
  char _0[328]; // [rsp+0h] [rbp+0h] BYREF
  unsigned long long vars148; // [rsp+148h] [rbp+148h]

  vars148 = __readfsqword(0x28u);
  strncpy(_0, &byte_8160, 0x100u);
  v1 = strlen(_0);
  if ( a1 )
  {
    v2 = "";
    if ( a1 != 1 )
      v2 = "s";
    __snprintf_chk(&_0[v1], 321LL - v1, 1, -1, "\rThe system is going DOWN %s in %d minute%s!\r\n", dest, a1, v2);
    v3 = v5;
  }
  else
  {
    __snprintf_chk(&_0[v1], 321LL - v1, 1, -1, "\rThe system is going down %s NOW!\r\n", dest);
  }
  sub_4540(_0, 0, v3);
  return vars148 - __readfsqword(0x28u);
}


// Function: donologin @ 0x3b20
unsigned long long donologin(int a1)
{
  FILE *v1; // rax
  FILE *v2; // rbp
  char *v3; // rax
  time_t v5; // [rsp+0h] [rbp-28h] BYREF
  unsigned long long v6; // [rsp+8h] [rbp-20h]

  v6 = __readfsqword(0x28u);
  time(&v5);
  v5 += 60 * a1;
  v1 = fopen("/etc/nologin", "w");
  if ( v1 )
  {
    v2 = v1;
    v3 = ctime(&v5);
    __fprintf_chk(v2, 1, "\rThe system is going down on %s\r\n", v3);
    if ( byte_8160 )
      fputs(&byte_8160, v2);
    fclose(v2);
  }
  return v6 - __readfsqword(0x28u);
}


// Function: spawn @ 0x3be0
long long spawn(
        int a1,
        char *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        ...)
{
  int v10; // r12d
  int i; // eax
  __pid_t v12; // eax
  __pid_t v13; // ebx
  char v14; // r8
  unsigned int v15; // esi
  char **overflow_arg_area; // rdi
  char **v17; // rdx
  int v18; // eax
  long long v19; // rcx
  char *v20; // rcx
  char **v21; // rcx
  char *v22; // rcx
  __pid_t v23; // eax
  int v25; // [rsp+4h] [rbp-C4h] BYREF
  gcc_va_list va; // [rsp+8h] [rbp-C0h] BYREF
  char *argv[10]; // [rsp+20h] [rbp-A8h] BYREF

  argv[9] = (char *)__readfsqword(0x28u);
  for ( i = 0; ; i = v25 + 1 )
  {
    v25 = i;
    v12 = fork();
    v13 = v12;
    if ( v12 >= 0 )
      break;
    if ( v25 > 9 )
      return 0xFFFFFFFFLL;
    perror("fork");
    sleep(5u);
  }
  if ( !v12 )
  {
    if ( a1 )
      fclose(stderr);
    v14 = 0;
    argv[0] = a2;
    va_start(va, a10);
    v15 = 16;
    overflow_arg_area = (char **)va[0].overflow_arg_area;
    v17 = argv;
    v18 = 1;
    v25 = 1;
    while ( 1 )
    {
      if ( v15 <= 0x2F )
      {
        v19 = v15;
        v15 += 8;
        v20 = *(char **)((char *)va[0].reg_save_area + v19);
        v17[1] = v20;
        if ( !v20 )
          goto LABEL_14;
      }
      else
      {
        v21 = overflow_arg_area++;
        v22 = *v21;
        v17[1] = v22;
        if ( !v22 )
        {
LABEL_14:
          if ( v14 )
            v25 = v10;
LABEL_23:
          argv[v18] = 0;
          if ( !chdir("/") )
          {
            _environ = off_8020;
            execvp(argv[0], argv);
            perror(argv[0]);
          }
          exit(1);
        }
      }
      ++v18;
      ++v17;
      v14 = 1;
      if ( v18 == 7 )
      {
        v25 = 7;
        goto LABEL_23;
      }
      v10 = v18;
    }
  }
  while ( 1 )
  {
    v23 = wait((__WAIT_STATUS)&v25);
    if ( v13 == v23 )
      break;
    while ( v23 >= 0 )
    {
      v23 = wait((__WAIT_STATUS)&v25);
      if ( v13 == v23 )
        return BYTE1(v25);
    }
    if ( *__errno_location() == 10 )
      return 0xFFFFFFFFLL;
  }
  return BYTE1(v25);
}


// Function: fastdown @ 0x3df0
void fastdown(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  char v8; // bp
  int v9; // ebx
  int v10; // edi
  unsigned int v11; // edi
  double v12; // xmm4_8
  double v13; // xmm5_8
  double v14; // xmm4_8
  double v15; // xmm5_8
  double v16; // xmm4_8
  double v17; // xmm5_8
  double v18; // xmm4_8
  double v19; // xmm5_8
  int *v20; // rax
  char *v21; // rax

  v8 = word_8268;
  v9 = 0;
  while ( 1 )
  {
    if ( !isatty(v9) )
    {
      close(v9);
      open("/dev/null", 2);
    }
    if ( ++v9 == 3 )
    {
      do
      {
        v10 = v9++;
        close(v10);
      }
      while ( v9 != 20 );
      close(255);
      if ( kill(1, 20) >= 0 )
      {
        __fprintf_chk(stderr, 1, "shutdown: sending all processes the TERM signal...\r\n");
        kill(-1, 15);
        if ( nptr )
          v11 = atoi(nptr);
        else
          v11 = 3;
        sleep(v11);
        __fprintf_chk(stderr, 1, "shutdown: sending all processes the KILL signal.\r\n");
        kill(-1, 9);
        sub_4AB0("shutdown", "~~");
        sub_3BE0(1, "accton", a1, a2, a3, a4, v12, v13, a7, a8, 0);
        sub_3BE0(1, "quotaoff", a1, a2, a3, a4, v14, v15, a7, a8, "-a", 0);
        sync();
        __fprintf_chk(stderr, 1, "shutdown: turning off swap\r\n");
        sub_3BE0(0, "swapoff", a1, a2, a3, a4, v16, v17, a7, a8, "-a", 0);
        __fprintf_chk(stderr, 1, "shutdown: unmounting all file systems\r\n");
        sub_3BE0(0, "umount", a1, a2, a3, a4, v18, v19, a7, a8, "-a", 0);
        if ( v8 != 48 )
        {
          __fprintf_chk(stderr, 1, "Please stand by while rebooting the system.\r\n");
          reboot(19088743);
          exit(0);
        }
        __fprintf_chk(stderr, 1, "The system is halted. Press CTRL-ALT-DEL or turn off power\r\n");
        reboot(-839974621);
        exit(0);
      }
      v20 = __errno_location();
      v21 = strerror(*v20);
      __fprintf_chk(stderr, 1, "shutdown: can't idle init: %s.\r\n", v21);
      exit(1);
    }
  }
}


// Function: issue_shutdown @ 0x4030
void issue_shutdown(
        const char *src,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char v9; // bl
  double v10; // xmm4_8
  double v11; // xmm5_8
  int v12; // eax
  char *v13[15]; // [rsp+0h] [rbp-78h] BYREF

  v9 = word_8268;
  v13[9] = (char *)__readfsqword(0x28u);
  sub_3A30(0);
  if ( dword_826C )
  {
    sub_3750(1);
    sub_36F0(0);
  }
  openlog("shutdown", 1, 8);
  if ( v9 == 48 )
    __syslog_chk(5, 1, "shutting down for system halt");
  else
    __syslog_chk(5, 1, "shutting down for system reboot");
  closelog();
  if ( !dword_80E4 )
  {
    v13[0] = "/sbin/init";
    if ( nptr )
    {
      v13[2] = nptr;
      v12 = 3;
      v13[1] = "-t";
    }
    else
    {
      v12 = 1;
    }
    v13[v12] = (char *)&word_8268;
    v13[v12 + 1] = 0;
    unlink("/var/run/shutdown.pid");
    unlink("/etc/nologin");
    sync();
    sub_3800("INIT_HALT", src);
    execv("/sbin/init", v13);
    __fprintf_chk(stderr, 1, "\rshutdown: cannot execute %s\r\n", "/sbin/init");
    unlink("/fastboot");
    unlink("/forcefsck");
    sub_3800("INIT_HALT", 0);
    openlog("shutdown", 1, 8);
    __syslog_chk(5, 1, "shutdown failed");
    closelog();
    exit(1);
  }
  sub_3DF0(a2, a3, a4, a5, v10, v11, a8, a9);
}


// Function: handler @ 0x4200
void handler()
{
  __longjmp_chk(&env, 1);
}


// Function: file_isatty @ 0x4220
long long file_isatty(const char *a1)
{
  unsigned int v1; // r12d
  unsigned int v3; // ecx
  struct stat dev; // [rsp+0h] [rbp-A8h] BYREF
  unsigned long long v5; // [rsp+98h] [rbp-10h]

  v1 = 0;
  v5 = __readfsqword(0x28u);
  if ( stat(a1, &dev) >= 0 && dev.st_nlink == 1 && (dev.st_mode & 0xF000) == 0x2000 )
  {
    v3 = gnu_dev_major(dev.st_dev);
    if ( v3 - 1 <= 1 || v3 == 6 )
    {
      return 0;
    }
    else if ( v3 > 0x1B )
    {
      if ( v3 != 206 )
      {
        if ( v3 > 0xCE )
        {
          return v3 != 230;
        }
        else if ( v3 != 37 )
        {
          return v3 - 96 > 1;
        }
      }
    }
    else
    {
      v1 = 1;
      if ( v3 > 8 )
        return !((0x8211200uLL >> v3) & 1);
    }
  }
  return v1;
}


// Function: feputs @ 0x4330
int feputs(unsigned char *a1, FILE *a2)
{
  unsigned char v2; // bl
  unsigned char *v3; // rbp

  v2 = *a1;
  if ( *a1 )
  {
    v3 = a1;
    do
    {
      while ( strchr("\t\r\n", v2) || (unsigned char)(v2 - 32) <= 0x5Fu || v2 > 0x9Fu )
      {
        ++v3;
        fputc(v2, a2);
        v2 = *v3;
        if ( !*v3 )
          return fflush(a2);
      }
      ++v3;
      __fprintf_chk(a2, 1, "^%c", (unsigned char)((v2 & 0x1F) + 64));
      v2 = *v3;
    }
    while ( *v3 );
  }
  return fflush(a2);
}


// Function: getuidtty @ 0x43e0
void getuidtty(long long *a1, long long *a2)
{
  __uid_t v2; // ebp
  struct passwd *v3; // rax
  char *v4; // rbp
  size_t v5; // r14

  if ( !dword_82E0 )
  {
    v2 = getuid();
    v3 = getpwuid(v2);
    if ( v3 )
    {
      LOBYTE(dword_82C0) = 0;
      __strncat_chk(&dword_82C0, v3->pw_name, 31, 32);
    }
    else if ( v2 )
    {
      __sprintf_chk(&dword_82C0, 1, 32, "uid %d", v2);
    }
    else
    {
      strcpy((char *)&dword_82C0, "root");
    }
    v4 = ttyname(0);
    if ( v4 )
    {
      v5 = strlen("/dev/");
      if ( !strncmp(v4, "/dev/", v5) )
        v4 += (v4[v5] == 47) + v5;
      __snprintf_chk(&byte_8280, 36, 1, 36, "(%.*s) ", 32, v4);
    }
    else
    {
      byte_8280 = 0;
    }
    ++dword_82E0;
  }
  *a1 = &dword_82C0;
  *a2 = &byte_8280;
}


// Function: wall @ 0x4540
unsigned long long wall(unsigned char *a1, int a2)
{
  size_t v2; // rax
  FILE **v3; // rcx
  signed long long v4; // rdx
  void *v5; // rsp
  char *v6; // r9
  char *v7; // rdx
  char v8; // cl
  long long v10; // rcx
  __sigset_t *p_sa_mask; // rdi
  struct utmp *v12; // rax
  const char *ut_line; // r12
  size_t v14; // rax
  long long v15; // rax
  char *v16; // rax
  size_t v17; // rdx
  int v18; // eax
  int v19; // ebx
  FILE *v20; // rax
  FILE *v21; // rbx
  long long v22; // [rsp+0h] [rbp-1268h]
  char v23[4088]; // [rsp+8h] [rbp-1260h] BYREF
  FILE *stream; // [rsp+1008h] [rbp-260h] BYREF
  int fd; // [rsp+1014h] [rbp-254h]
  char *dest; // [rsp+1018h] [rbp-250h]
  unsigned char *v27; // [rsp+1020h] [rbp-248h]
  size_t n; // [rsp+1028h] [rbp-240h]
  size_t v29; // [rsp+1030h] [rbp-238h]
  time_t timer; // [rsp+1040h] [rbp-228h] BYREF
  const char *v31; // [rsp+1048h] [rbp-220h] BYREF
  const char *v32; // [rsp+1050h] [rbp-218h] BYREF
  struct sigaction act; // [rsp+1058h] [rbp-210h] BYREF
  char name[16]; // [rsp+10F8h] [rbp-170h] BYREF
  __int128 v35; // [rsp+1108h] [rbp-160h]
  __int128 v36; // [rsp+1118h] [rbp-150h]
  __int128 v37; // [rsp+1128h] [rbp-140h]
  char v38; // [rsp+1138h] [rbp-130h]
  char s[264]; // [rsp+1148h] [rbp-120h] BYREF
  unsigned long long v40; // [rsp+1250h] [rbp-18h]

  v27 = a1;
  v40 = __readfsqword(0x28u);
  v2 = strlen("/dev/");
  v29 = v2 + 33;
  n = v2 + 32;
  v3 = (FILE **)((char *)&stream - ((v2 + 48) & 0xFFFFFFFFFFFFF000LL));
  if ( &stream != v3 )
  {
    while ( v23 != (char *)v3 )
      ;
  }
  v4 = ((short)v2 + 48) & 0xFF0;
  v5 = alloca(v4);
  if ( (((short)v2 + 48) & 0xFF0) != 0 )
    *(long long *)&v23[v4 - 8] = *(long long *)&v23[v4 - 8];
  dest = v23;
  sub_43E0(&v31, &v32);
  if ( gethostname(name, 0x41u) )
  {
    *(__m128i *)name = _mm_load_si128((const __m128i *)&xmmword_5A40);
    v35 = 0;
    v36 = 0;
    v37 = 0;
  }
  v38 = 0;
  time(&timer);
  v6 = ctime(&timer);
  v7 = v6;
  if ( *v6 && *v6 != 10 )
  {
    do
      v8 = *++v7;
    while ( v8 && v8 != 10 );
  }
  *v7 = 0;
  if ( a2 )
    __snprintf_chk(s, 256, 1, 256, "\r\nRemote broadcast message (%s):\r\n\r\n", v6);
  else
    __snprintf_chk(s, 256, 1, 256, "\r\nBroadcast message from %s@%s %s(%s):\r\n\r\n", v31, name, v32, v6);
  if ( !fork() )
  {
    v10 = 36;
    p_sa_mask = &act.sa_mask;
    while ( v10 )
    {
      LODWORD(p_sa_mask->__val[0]) = 0;
      p_sa_mask = (__sigset_t *)((char *)p_sa_mask + 4);
      --v10;
    }
    act.sa_handler = (__sighandler_t)sub_4200;
    sigemptyset(&act.sa_mask);
    sigaction(14, &act, 0);
    setutent();
    while ( 1 )
    {
      while ( 1 )
      {
        v12 = getutent();
        if ( !v12 )
        {
          endutent();
          exit(0);
        }
        if ( v12->ut_type == 7 && v12->ut_user[0] )
        {
          ut_line = v12->ut_line;
          v14 = strlen("/dev/");
          LODWORD(v15) = strncmp(ut_line, "/dev/", v14);
          if ( (int)v15 )
          {
            v22 = v15;
            __snprintf_chk(dest, v29, 1, -1, "/dev/%.*s", 32, ut_line);
          }
          else
          {
            v16 = dest;
            v17 = n;
            *dest = 0;
            strncat(v16, ut_line, v17);
          }
          stream = (FILE *)strstr(dest, "/../");
          if ( !stream )
            break;
        }
      }
      fd = -1;
      if ( !__sigsetjmp(&env, 1) )
      {
        alarm(2u);
        if ( (unsigned int)sub_4220(dest) )
        {
          v18 = open(dest, 2305);
          fd = v18;
          v19 = v18;
          if ( v18 < 0 )
          {
            alarm(0);
            goto LABEL_28;
          }
          if ( !isatty(v18) || (v20 = fdopen(fd, "w"), (stream = v20) == 0) )
          {
            alarm(0);
            fd = v19;
LABEL_34:
            close(fd);
            goto LABEL_28;
          }
          v21 = v20;
          fputs(s, v20);
          sub_4330(v27, v21);
          fflush(v21);
        }
      }
      alarm(0);
      if ( fd >= 0 )
        goto LABEL_34;
LABEL_28:
      if ( stream )
        fclose(stream);
    }
  }
  return v40 - __readfsqword(0x28u);
}


// Function: write_wtmp @ 0x4ab0
unsigned long long write_wtmp(char *src, char *a2, pid_t a3, short a4, const char *a5)
{
  int v7; // r14d
  struct timeval tv; // [rsp+10h] [rbp-358h] BYREF
  struct utmp v11; // [rsp+20h] [rbp-348h] BYREF
  struct utsname name; // [rsp+1A0h] [rbp-1C8h] BYREF
  unsigned long long v13; // [rsp+328h] [rbp-40h]

  v13 = __readfsqword(0x28u);
  if ( access("/var/log/wtmp", 2) >= 0 )
  {
    v7 = open("/var/log/wtmp", 1025);
    if ( v7 >= 0 )
    {
      memset(&v11, 0, sizeof(v11));
      gettimeofday(&tv, 0);
      v11.ut_type = a4;
      v11.ut_tv.tv_sec = tv.tv_sec;
      v11.ut_tv.tv_usec = tv.tv_usec;
      v11.ut_pid = a3;
      strncpy(v11.ut_user, src, 0x20u);
      strncpy(v11.ut_id, a2, 4u);
      strncpy(v11.ut_line, a5, 0x20u);
      if ( !uname(&name) )
        strncpy(v11.ut_host, name.release, 0x100u);
      updwtmp("/var/log/wtmp", &v11);
      close(v7);
    }
  }
  return v13 - __readfsqword(0x28u);
}


// Function: write_utmp_wtmp @ 0x4c20
unsigned long long write_utmp_wtmp(char *src, char *a2, pid_t a3, short a4, const char *a5)
{
  char v9[40]; // [rsp+0h] [rbp-68h] BYREF
  unsigned long long v10; // [rsp+28h] [rbp-40h]

  v10 = __readfsqword(0x28u);
  if ( src )
  {
    v9[0] = 0;
    sub_4940(src, a2);
    if ( a5 )
    {
      if ( !*a5 )
        a5 = v9;
    }
    else
    {
      a5 = v9;
    }
    sub_4AB0(src, a2, a3, a4, a5);
  }
  return v10 - __readfsqword(0x28u);
}


