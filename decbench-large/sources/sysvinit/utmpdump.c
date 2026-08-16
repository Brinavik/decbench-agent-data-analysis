
struct oldutmp {
 short ut_type;
 int ut_pid;
 char ut_line[12];
 char ut_id[4];
 long ut_oldtime;
 char ut_user[8];
 char ut_host[16];
 long ut_oldaddr;
};

struct utmp
oldtonew(struct oldutmp src)
{
        struct utmp dest;

 memset(&dest, 0, sizeof dest);
 dest.ut_type = src.ut_type;
 dest.ut_pid = src.ut_pid;
 dest.
     ut_tv.tv_sec 
             = src.ut_oldtime;
 dest.
     ut_addr_v6[0] 
             = src.ut_oldaddr;
 strncpy(dest.ut_id, src.ut_id, 4);
 strncpy(dest.ut_line, src.ut_line, 12);
 strncpy(dest.ut_user, src.ut_user, 8);
 strncpy(dest.ut_host, src.ut_host, 16);

        return dest;
}

struct oldutmp
newtoold(struct utmp src)
{
        struct oldutmp dest;

 memset(&dest, 0, sizeof dest);
 dest.ut_type = src.ut_type;
 dest.ut_pid = src.ut_pid;
 dest.ut_oldtime = src.
                      ut_tv.tv_sec
                             ;
 dest.ut_oldaddr = src.
                      ut_addr_v6[0]
                             ;
 strncpy(dest.ut_id, src.ut_id, 4);
 strncpy(dest.ut_line, src.ut_line, 12);
 strncpy(dest.ut_user, src.ut_user, 8);
 strncpy(dest.ut_host, src.ut_host, 16);

        return dest;
}

char *
timetostr(const time_t time)
{
 static char s[29];

 if (time != 0)
  strftime(s, 29, "%a %b %d %T %Y %Z", localtime(&time));
 else
  s[0] = '\0';

 return s;
}

time_t
strtotime(const char *s_time)
{
 struct tm tm;

 memset(&tm, '\0', sizeof(struct tm));

 if (s_time[0] == ' ' || s_time[0] == '\0')
  return (time_t)0;

 strptime(s_time, "%a %b %d %T %Y", &tm);


 if (s_time[26] == 'D')
  tm.tm_isdst = 1;

 return mktime(&tm);
}


void
xcleanse(char *s, int len)
{
 for ( ; *s && len-- > 0; s++)
  if (!
      ((*__ctype_b_loc ())[(int) ((
      *s
      ))] & (unsigned short int) _ISprint) 
                  || *s == '[' || *s == ']')
   *s = '?';
}

void
unspace(char *s, int len)
{
 while (*s && *s != ' ' && len--)
  ++s;

 if (len > 0)
  *s = '\0';
}

void
print_utline(struct utmp ut)
{
 char addr_buf[
              46
                              +1];
 const char *addr_string, *time_string;
 void *in_addr = &ut.ut_addr_v6;
 size_t addr_length = 
                     46
                                     ;
 int addr_family = 
                  10
                          ;

 if (!ut.ut_addr_v6[1] && !ut.ut_addr_v6[2] && !ut.ut_addr_v6[3]) {
  addr_family = 
               2
                      ;
  addr_length = 
               16
                              ;
  in_addr = &ut.
               ut_addr_v6[0]
                      ;
 }
 if ((addr_string = inet_ntop(addr_family, in_addr, addr_buf, addr_length)) == 0) {
  addr_buf[0] = '\0';
  addr_string = &addr_buf[0];
 }
 time_string = timetostr(ut.
                           ut_tv.tv_sec
                                  );
 xcleanse(ut.ut_id, sizeof(ut.ut_id));
 xcleanse(ut.ut_user, sizeof(ut.ut_user));
 xcleanse(ut.ut_line, sizeof(ut.ut_line));
 xcleanse(ut.ut_host, sizeof(ut.ut_host));


 printf("[%d] [%05d] [%-4.4s] [%-*.*s] [%-*.*s] [%-*.*s] [%-15.15s] [%-28.28s]\n",
        ut.ut_type, ut.ut_pid, ut.ut_id, 8, 
                                           32
                                                      , ut.ut_user,
        12, 
           32
                      , ut.ut_line, 20, 
                                        256
                                                   , ut.ut_host,
               addr_string, time_string);
}

void
dump(FILE *fp, int forever, int oldfmt)
{
 struct utmp ut;
 struct oldutmp uto;

 if (forever)
  fseek(fp, -10 * (oldfmt ? sizeof uto : sizeof ut), 
                                                    2
                                                            );

 do {
  if (oldfmt)
   while (fread(&uto, sizeof uto, 1, fp) == 1)
    print_utline(oldtonew(uto));
  else
   while (fread(&ut, sizeof ut, 1, fp) == 1)
    print_utline(ut);
  if (forever) sleep(1);
 } while (forever);
}



int
gettok(char *line, char *dest, int size, int eatspace)
{
 int bpos, epos, eaten;
        char *t;

 bpos = strchr(line, '[') - line;
 if (bpos < 0) {
  fprintf(
         stderr
               , "Extraneous newline in file.  Exiting.");
                exit(1);
        }
 line += 1 + bpos;

 epos = strchr(line, ']') - line;
 if (epos < 0) {
  fprintf(
         stderr
               , "Extraneous newline in file.  Exiting.");
                exit(1);
        }
 line[epos] = '\0';

 eaten = bpos + epos + 1;

 if (eatspace)
                if ((t = strchr(line, ' ')))
                    *t = 0;

        strncpy(dest, line, size);

 return eaten + 1;
}

void

undump(FILE *fp, int forever __attribute__((unused)), int oldfmt)



{
 struct utmp ut;
 struct oldutmp uto;
 char s_addr[16], s_time[29], *linestart;

 linestart = malloc(1024 * sizeof *linestart);
 s_addr[15] = 0;
 s_time[28] = 0;

 while(fgets(linestart, 1023, fp))
 {
  char *line = linestart;
                memset(&ut, '\0', sizeof(ut));
                sscanf(line, "[%hd] [%d] [%4c] ", &ut.ut_type, &ut.ut_pid, ut.ut_id);

  line += 19;
                line += gettok(line, ut.ut_user, sizeof(ut.ut_user), 1);
                line += gettok(line, ut.ut_line, sizeof(ut.ut_line), 1);
                line += gettok(line, ut.ut_host, sizeof(ut.ut_host), 1);
  line += gettok(line, s_addr, sizeof(s_addr)-1, 1);
  line += gettok(line, s_time, sizeof(s_time)-1, 0);
  (void)line;

                ut.
                  ut_addr_v6[0] 
                          = inet_addr(s_addr);
                ut.
                  ut_tv.tv_sec 
                          = strtotime(s_time);

                if (oldfmt) {
                        uto = newtoold(ut);
                        fwrite(&uto, sizeof(uto), 1, 
                                                    stdout
                                                          );
                } else
                        fwrite(&ut, sizeof(ut), 1, 
                                                  stdout
                                                        );

 }

 free(linestart);
}

void
usage(int result)
{
 printf("Usage: utmpdump [ -froh ] [ filename ]\n");
 exit(result);
}

int main(int argc, char **argv)
{
 int c;
 FILE *fp;
 int reverse = 0, forever = 0, oldfmt = 0;

 while ((c = getopt(argc, argv, "froh")) != 
                                           (-1)
                                              ) {
  switch (c) {
  case 'r':
   reverse = 1;
   break;

  case 'f':
   forever = 1;
   break;

  case 'o':
   oldfmt = 1;
   break;

  case 'h':
   usage(0);
   break;

  default:
   usage(1);
  }
 }

 if (optind < argc) {
  fprintf(
         stderr
               , "Utmp %sdump of %s\n", reverse ? "un" : "", argv[optind]);
  if ((fp = fopen(argv[optind], "r")) == 
                                        ((void *)0)
                                            ) {
   perror("Unable to open file");
   exit(1);
  }
 }
 else {
  fprintf(
         stderr
               , "Utmp %sdump of stdin\n", reverse ? "un" : "");
  fp = 
      stdin
           ;
 }

 if (reverse)
  undump(fp, forever, oldfmt);
 else
  dump(fp, forever, oldfmt);

 fclose(fp);

 return 0;
}
