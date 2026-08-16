





static char location_base[((500) + 1)] = "";

static char th_page_and_sec[128] = { '\0' };
static char th_datestr[128] = { '\0' };
static char th_version[128] = { '\0' };

char *signature = "<HR>\nThis document was created by man2html from %s.<BR>\nTime: %s\n";




char *manpage;
static char *
strgrow(char *old, int len)
{
 char *new = realloc(old, (strlen(old) + len + 1) * sizeof(char));

 if (!new) {
  fprintf(
         stderr
               , "man2html: out of memory");
  exit(
      1
                  );
 }
 return new;
}

static char *
stralloc(int len)
{

 char *new = malloc((len + 1) * sizeof(char));

 if (!new) {
  fprintf(
         stderr
               , "man2html: out of memory");
  exit(
      1
                  );
 }
 return new;
}

void *
xmalloc (size_t size)
{
 void *ret;

 ret = malloc (size);
 if (ret == 0) {
  fprintf(
         stderr
               , "man2html: out of memory");
  exit(
      1
                  );
 }
 return ret;
}





static char *
strduplicate(char *from)
{
 char *new = stralloc(strlen(from));

 strcpy(new, from);
 return new;
}


static char *
strmaxcpy(char *to, char *from, int n)
{
 int len = strlen(from);

 strncpy(to, from, n);
 to[(len <= n) ? len : n] = '\0';
 return to;
}

static char *
strmaxcat(char *to, char *from, int n)
{
 int to_len = strlen(to);

 if (to_len < n) {
  int from_len = strlen(from);
  int cp = (to_len + from_len <= n) ? from_len : n - to_len;

  strncpy(to + to_len, from, cp);
  to[to_len + cp] = '\0';
 }
 return to;
}


static char *
strlimitcpy(char *to, char *from, int n, int limit)
{
 int len = n > limit ? limit : n;

 strmaxcpy(to, from, len);
 to[len] = '\0';
 return to;
}





static char *
escape_input(char *str)
{
 int i, j = 0;
 static char new[((500) + 1)];

 if (strlen(str) * 2 + 1 > 500) {
  fprintf(
         stderr
               ,
   "man2html: escape_input - str too long:\n%-80s...\n",
   str);
  exit(
      1
                  );
 }
 for (i = 0; i < strlen(str); i++) {
  if (!(((str[i] >= 'A') && (str[i] <= 'Z')) ||
        ((str[i] >= 'a') && (str[i] <= 'z')) ||
        ((str[i] >= '0') && (str[i] <= '9')))) {
   new[j] = '\\';
   j++;
  }
  new[j] = str[i];
  j++;
 }
 new[j] = '\0';
 return new;
}

static void
usage(void)
{
 fprintf(
        stderr
              , "man2html: usage: man2html filename\n");
}
typedef struct STRDEF STRDEF;
struct STRDEF {
 int nr, slen;
 char *st;
 STRDEF *next;
};

typedef struct INTDEF INTDEF;
struct INTDEF {
 int nr;
 int val;
 int incr;
 INTDEF *next;
};

static char NEWLINE[2] = "\n";
static char idxlabel[6] = "ixAAA";



static char *fname;
static FILE *idxfile;

static STRDEF *chardef, *strdef, *defdef;
static INTDEF *intdef;



static INTDEF standardint[] = {
 {(('n')*256+(' ')), 0, 0, 
                        ((void *)0)
                            },
 {(('t')*256+(' ')), 1 - 0, 0, 
                            ((void *)0)
                                },
 {(('o')*256+(' ')), 1, 0, 
                    ((void *)0)
                        },
 {(('e')*256+(' ')), 0, 0, 
                    ((void *)0)
                        },
 {(('.')*256+('l')), 70, 0, 
                     ((void *)0)
                         },
 {(('.')*256+('$')), 0, 0, 
                    ((void *)0)
                        },
 {(('.')*256+('A')), 0, 0, 
                        ((void *)0)
                            },
 {(('.')*256+('T')), 1 - 0, 0, 
                            ((void *)0)
                                },
 {(('.')*256+('V')), 1, 0, 
                    ((void *)0)
                        },
{0, 0, 0, 
         ((void *)0)
             }};

static STRDEF standardstring[] = {
 {(('R')*256+(' ')), 1, "&#174;", 
                           ((void *)0)
                               },
 {(('l')*256+('q')), 2, "``", 
                       ((void *)0)
                           },
 {(('r')*256+('q')), 2, "''", 
                       ((void *)0)
                           },
 {0, 0, 
       ((void *)0)
           , 
             ((void *)0)
                 }
};


static STRDEF standardchar[] = {
 {(('*')*256+('*')), 1, "*", 
                      ((void *)0)
                          },
 {(('*')*256+('A')), 1, "A", 
                      ((void *)0)
                          },
 {(('*')*256+('B')), 1, "B", 
                      ((void *)0)
                          },
 {(('*')*256+('C')), 2, "Xi", 
                       ((void *)0)
                           },
 {(('*')*256+('D')), 5, "Delta", 
                          ((void *)0)
                              },
 {(('*')*256+('E')), 1, "E", 
                      ((void *)0)
                          },
 {(('*')*256+('F')), 3, "Phi", 
                        ((void *)0)
                            },
 {(('*')*256+('G')), 5, "Gamma", 
                          ((void *)0)
                              },
 {(('*')*256+('H')), 5, "Theta", 
                          ((void *)0)
                              },
 {(('*')*256+('I')), 1, "I", 
                      ((void *)0)
                          },
 {(('*')*256+('K')), 1, "K", 
                      ((void *)0)
                          },
 {(('*')*256+('L')), 6, "Lambda", 
                           ((void *)0)
                               },
 {(('*')*256+('M')), 1, "M", 
                      ((void *)0)
                          },
 {(('*')*256+('N')), 1, "N", 
                      ((void *)0)
                          },
 {(('*')*256+('O')), 1, "O", 
                      ((void *)0)
                          },
 {(('*')*256+('P')), 2, "Pi", 
                       ((void *)0)
                           },
 {(('*')*256+('Q')), 3, "Psi", 
                        ((void *)0)
                            },
 {(('*')*256+('R')), 1, "P", 
                      ((void *)0)
                          },
 {(('*')*256+('S')), 5, "Sigma", 
                          ((void *)0)
                              },
 {(('*')*256+('T')), 1, "T", 
                      ((void *)0)
                          },
 {(('*')*256+('U')), 1, "Y", 
                      ((void *)0)
                          },
 {(('*')*256+('W')), 5, "Omega", 
                          ((void *)0)
                              },
 {(('*')*256+('X')), 1, "X", 
                      ((void *)0)
                          },
 {(('*')*256+('Y')), 1, "H", 
                      ((void *)0)
                          },
 {(('*')*256+('Z')), 1, "Z", 
                      ((void *)0)
                          },
 {(('*')*256+('a')), 5, "alpha", 
                          ((void *)0)
                              },
 {(('*')*256+('b')), 4, "beta", 
                         ((void *)0)
                             },
 {(('*')*256+('c')), 2, "xi", 
                       ((void *)0)
                           },
 {(('*')*256+('d')), 5, "delta", 
                          ((void *)0)
                              },
 {(('*')*256+('e')), 7, "epsilon", 
                            ((void *)0)
                                },
 {(('*')*256+('f')), 3, "phi", 
                        ((void *)0)
                            },
 {(('*')*256+('g')), 5, "gamma", 
                          ((void *)0)
                              },
 {(('*')*256+('h')), 5, "theta", 
                          ((void *)0)
                              },
 {(('*')*256+('i')), 4, "iota", 
                         ((void *)0)
                             },
 {(('*')*256+('k')), 5, "kappa", 
                          ((void *)0)
                              },
 {(('*')*256+('l')), 6, "lambda", 
                           ((void *)0)
                               },
 {(('*')*256+('m')), 1, "&#181;", 
                           ((void *)0)
                               },
 {(('*')*256+('n')), 2, "nu", 
                       ((void *)0)
                           },
 {(('*')*256+('o')), 1, "o", 
                      ((void *)0)
                          },
 {(('*')*256+('p')), 2, "pi", 
                       ((void *)0)
                           },
 {(('*')*256+('q')), 3, "psi", 
                        ((void *)0)
                            },
 {(('*')*256+('r')), 3, "rho", 
                        ((void *)0)
                            },
 {(('*')*256+('s')), 5, "sigma", 
                          ((void *)0)
                              },
 {(('*')*256+('t')), 3, "tau", 
                        ((void *)0)
                            },
 {(('*')*256+('u')), 7, "upsilon", 
                            ((void *)0)
                                },
 {(('*')*256+('w')), 5, "omega", 
                          ((void *)0)
                              },
 {(('*')*256+('x')), 3, "chi", 
                        ((void *)0)
                            },
 {(('*')*256+('y')), 3, "eta", 
                        ((void *)0)
                            },
 {(('*')*256+('z')), 4, "zeta", 
                         ((void *)0)
                             },
 {(('t')*256+('s')), 5, "sigma", 
                          ((void *)0)
                              },
 {(('+')*256+('-')), 1, "&#177;", 
                           ((void *)0)
                               },
 {(('1')*256+('2')), 1, "&#189;", 
                           ((void *)0)
                               },
 {(('1')*256+('4')), 1, "&#188;", 
                           ((void *)0)
                               },
 {(('3')*256+('4')), 1, "&#190;", 
                           ((void *)0)
                               },
 {(('F')*256+('i')), 3, "ffi", 
                        ((void *)0)
                            },
 {(('F')*256+('l')), 3, "ffl", 
                        ((void *)0)
                            },
 {(('a')*256+('a')), 1, "&#180;", 
                           ((void *)0)
                               },
 {(('a')*256+('p')), 1, "~", 
                      ((void *)0)
                          },
 {(('b')*256+('r')), 1, "|", 
                      ((void *)0)
                          },
 {(('b')*256+('u')), 1, "*", 
                      ((void *)0)
                          },
 {(('b')*256+('v')), 1, "|", 
                      ((void *)0)
                          },
 {(('c')*256+('i')), 1, "o", 
                      ((void *)0)
                          },
 {(('c')*256+('o')), 1, "&#169;", 
                           ((void *)0)
                               },
 {(('c')*256+('t')), 1, "&#162;", 
                           ((void *)0)
                               },
 {(('d')*256+('e')), 1, "&#176;", 
                           ((void *)0)
                               },
 {(('d')*256+('g')), 1, "+", 
                      ((void *)0)
                          },
 {(('d')*256+('i')), 1, "&#247;", 
                           ((void *)0)
                               },
 {(('e')*256+('m')), 1, "-", 
                      ((void *)0)
                          },
 {(('e')*256+('m')), 3, "---", 
                        ((void *)0)
                            },
 {(('e')*256+('q')), 1, "=", 
                      ((void *)0)
                          },
 {(('e')*256+('s')), 1, "&#216;", 
                           ((void *)0)
                               },
 {(('f')*256+('f')), 2, "ff", 
                       ((void *)0)
                           },
 {(('f')*256+('i')), 2, "fi", 
                       ((void *)0)
                           },
 {(('f')*256+('l')), 2, "fl", 
                       ((void *)0)
                           },
 {(('f')*256+('m')), 1, "&#180;", 
                           ((void *)0)
                               },
 {(('g')*256+('a')), 1, "`", 
                      ((void *)0)
                          },
 {(('h')*256+('y')), 1, "-", 
                      ((void *)0)
                          },
 {(('l')*256+('c')), 2, "|&#175;", 
                            ((void *)0)
                                },
 {(('l')*256+('f')), 2, "|_", 
                       ((void *)0)
                           },
 {(('l')*256+('k')), 1, "<FONT SIZE=+2>{</FONT>", 
                                           ((void *)0)
                                               },
 {(('m')*256+('i')), 1, "-", 
                      ((void *)0)
                          },
 {(('m')*256+('u')), 1, "&#215;", 
                           ((void *)0)
                               },
 {(('n')*256+('o')), 1, "&#172;", 
                           ((void *)0)
                               },
 {(('o')*256+('r')), 1, "|", 
                      ((void *)0)
                          },
 {(('p')*256+('l')), 1, "+", 
                      ((void *)0)
                          },
 {(('r')*256+('c')), 2, "&#175;|", 
                            ((void *)0)
                                },
 {(('r')*256+('f')), 2, "_|", 
                       ((void *)0)
                           },
 {(('r')*256+('g')), 1, "&#174;", 
                           ((void *)0)
                               },
 {(('r')*256+('k')), 1, "<FONT SIZE=+2>}</FONT>", 
                                           ((void *)0)
                                               },
 {(('r')*256+('n')), 1, "&#175;", 
                           ((void *)0)
                               },
 {(('r')*256+('u')), 1, "_", 
                      ((void *)0)
                          },
 {(('s')*256+('c')), 1, "&#167;", 
                           ((void *)0)
                               },
 {(('s')*256+('l')), 1, "/", 
                      ((void *)0)
                          },
 {(('s')*256+('q')), 2, "[]", 
                       ((void *)0)
                           },
 {(('u')*256+('l')), 1, "_", 
                      ((void *)0)
                          },
 {0, 0, 
       ((void *)0)
           , 
             ((void *)0)
                 }
};




static char eqndelimopen = 0, eqndelimclose = 0;
static char escapesym = '\\', nobreaksym = '\'', controlsym = '.', fieldsym = 0, padsym = 0;

static char *buffer = 
                     ((void *)0)
                         ;
static int buffpos = 0, buffmax = 0;
static int scaninbuff = 0;
static int itemdepth = 0;
static int dl_set[20] = {0};
static int still_dd = 0;
static int tabstops[20] = {8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96};
static int maxtstop = 12;
static int curpos = 0;

static char *scan_troff(char *c, int san, char **result);
static char *scan_troff_mandoc(char *c, int san, char **result);

static char **argument = 
                        ((void *)0)
                            ;

static char charb[10];

static void
print_sig(void)
{
 char datbuf[((500) + 1)];
 struct tm *timetm;
 time_t clock;

 datbuf[0] = '\0';
 clock = time(
             ((void *)0)
                 );
 timetm = localtime(&clock);
 strftime(datbuf, 500, "%d %B %Y %T %Z", timetm);
 printf(signature, manpage, datbuf);
}

static char *
expand_char(int nr)
{
 STRDEF *h;

 h = chardef;
 if (!nr)
  return 
        ((void *)0)
            ;
 while (h)
  if (h->nr == nr) {
   curpos += h->slen;
   return h->st;
  } else
   h = h->next;
 charb[0] = nr / 256;
 charb[1] = nr % 256;
 charb[2] = '\0';
 if (charb[0] == '<') {
  charb[4] = charb[1];
  strncpy(charb, "&lt;", 4);
  charb[5] = '\0';
 }
 curpos += 2;
 return charb;
}

static char *
expand_string(int nr)
{
 STRDEF *h = strdef;

 if (!nr)
  return 
        ((void *)0)
            ;
 while (h)
  if (h->nr == nr) {
   curpos += h->slen;
   return h->st;
  } else
   h = h->next;
 return 
       ((void *)0)
           ;
}

static char *
read_man_page(char *filename)
{
 char *man_buf = 
                  ((void *)0)
                      ;
 int i;
 FILE *man_stream = 
                     ((void *)0)
                         ;
 struct stat stbuf;
 int buf_size;

 if (stat(filename, &stbuf) == -1)
  return 
        ((void *)0)
            ;

 buf_size = stbuf.st_size;
 man_buf = stralloc(buf_size + 5);
 man_stream = fopen(filename, "r");
 if (man_stream) {
  man_buf[0] = '\n';
  if (fread(man_buf + 1, 1, buf_size, man_stream) == buf_size) {
   man_buf[buf_size] = '\n';
   man_buf[buf_size + 1] = man_buf[buf_size + 2] = '\0';
  } else {
   free(man_buf);
   man_buf = 
            ((void *)0)
                ;
  }
  fclose(man_stream);
 }
 return man_buf;
}


static char outbuffer[((10000) + 1)];
static int obp = 0;
static int no_newline_output = 0;
static int newline_for_fun = 0;
static int output_possible = 0;
static int out_length = 0;
static void
add_links(char *c)
{
 int i, j, nr;
 char *f, *g, *h;
 char *idtest[6];

 out_length += strlen(c);

 nr = 0;
 idtest[0] = strstr(c + 1, "://");
 idtest[1] = strchr(c + 1, '@');
 idtest[2] = strstr(c, "www.");
 idtest[3] = strstr(c, "ftp.");



 idtest[4] = 0;

 idtest[5] = strstr(c + 1, ".h&gt;");
 for (i = 0; i < 6; i++)
  nr += (idtest[i] != 
                     ((void *)0)
                         );
 while (nr) {
  j = -1;
  for (i = 0; i < 6; i++)
   if (idtest[i] && (j < 0 || idtest[i] < idtest[j]))
    j = i;
  switch (j) {
  case 5:
   f = idtest[5];
   h = f + 2;
   g = f;
   while (g > c && g[-1] != ';')
    g--;
   if (g != c) {
    char t;

    t = *g;
    *g = '\0';
    fputs(c, 
            stdout
                  );
    *g = t;
    *h = '\0';
    printf("<A HREF=\"file:/usr/include/%s\">%s</A>&gt;", g, g);
    c = f + 6;
   } else {
    f[5] = '\0';
    fputs(c, 
            stdout
                  );
    f[5] = ';';
    c = f + 5;
   }
   break;
  case 4:
   break;
  case 3:
  case 2:
   g = f = idtest[j];
   while (*g && (
                ((*__ctype_b_loc ())[(int) ((
                *g
                ))] & (unsigned short int) _ISalnum) 
                            || *g == '_' || *g == '-' || *g == '+' ||
          *g == '.'))
    g++;
   if (g[-1] == '.')
    g--;
   if (g - f > 4) {
    char t;

    t = *f;
    *f = '\0';
    fputs(c, 
            stdout
                  );
    *f = t;
    t = *g;
    *g = '\0';
    printf("<A HREF=\"%s://%s\">%s</A>", (j == 3 ? "ftp" : "http"),
           f, f);
    *g = t;
    c = g;
   } else {
    f[3] = '\0';
    fputs(c, 
            stdout
                  );
    c = f + 3;
    f[3] = '.';
   }
   break;
  case 1:
   g = f = idtest[1];
   while (g > c && (
                   ((*__ctype_b_loc ())[(int) ((
                   g[-1]
                   ))] & (unsigned short int) _ISalnum) 
                                  || g[-1] == '_' || g[-1] == '-' ||
         g[-1] == '+' || g[-1] == '.' || g[-1] == '%'))
    g--;
   h = f + 1;
   while (*h && (
                ((*__ctype_b_loc ())[(int) ((
                *h
                ))] & (unsigned short int) _ISalnum) 
                            || *h == '_' || *h == '-' || *h == '+' ||
          *h == '.'))
    h++;
   if (*h == '.')
    h--;
   if (h - f > 4 && f - g > 1) {
    char t;

    t = *g;
    *g = '\0';
    fputs(c, 
            stdout
                  );
    *g = t;
    t = *h;
    *h = '\0';
    printf("<A HREF=\"mailto:%s\">%s</A>", g, g);
    *h = t;
    c = h;
   } else {
    *f = '\0';
    fputs(c, 
            stdout
                  );
    *f = '@';
    idtest[1] = c;
    c = f;
   }
   break;
  case 0:
   g = f = idtest[0];
   while (g > c && 
                  ((*__ctype_b_loc ())[(int) ((
                  g[-1]
                  ))] & (unsigned short int) _ISalpha) 
                                 && 
                                    ((*__ctype_b_loc ())[(int) ((
                                    g[-1]
                                    ))] & (unsigned short int) _ISlower)
                                                  )
    g--;
   h = f + 3;
   while (*h && !
                ((*__ctype_b_loc ())[(int) ((
                *h
                ))] & (unsigned short int) _ISspace) 
                            && *h != '<' && *h != '>' && *h != '"' &&
          *h != '&')
    h++;
   if (f - g > 2 && f - g < 7 && h - f > 3) {
    char t;

    t = *g;
    *g = '\0';
    fputs(c, 
            stdout
                  );
    *g = t;
    t = *h;
    *h = '\0';
    printf("<A HREF=\"%s\">%s</A>", g, g);
    *h = t;
    c = h;
   } else {
    f[1] = '\0';
    fputs(c, 
            stdout
                  );
    f[1] = '/';
    c = f + 1;
   }
   break;
  default:
   break;
  }
  nr = 0;
  if (idtest[0] && idtest[0] < c)
   idtest[0] = strstr(c + 1, "://");
  if (idtest[1] && idtest[1] < c)
   idtest[1] = strchr(c + 1, '@');
  if (idtest[2] && idtest[2] < c)
   idtest[2] = strstr(c, "www.");
  if (idtest[3] && idtest[3] < c)
   idtest[3] = strstr(c, "ftp.");
  if (idtest[4] && idtest[4] < c)
   idtest[4] = strchr(c + 1, '(');
  if (idtest[5] && idtest[5] < c)
   idtest[5] = strstr(c + 1, ".h&gt;");
  for (i = 0; i < 6; i++)
   nr += (idtest[i] != 
                      ((void *)0)
                          );
 }
 fputs(c, 
         stdout
               );
}

static int current_font = 0;
static int current_size = 0;
static int fillout = 1;

static void
out_html(char *c)
{
 if (!c)
  return;
 if (no_newline_output) {
  int i = 0;

  no_newline_output = 1;
  while (c[i]) {
   if (!no_newline_output)
    c[i - 1] = c[i];
   if (c[i] == '\n')
    no_newline_output = 1;
   i++;
  }
  if (!no_newline_output)
   c[i - 1] = 0;
 }
 if (scaninbuff) {
  while (*c) {
   if (buffpos >= buffmax) {
    char *h;

    h = realloc(buffer, buffmax * 2);
    if (!h)
     return;
    buffer = h;
    buffmax *= 2;
   }
   buffer[buffpos++] = *c++;
  }
 } else if (output_possible) {
  while (*c) {
   outbuffer[obp++] = *c;
   if (*c == '\n' || obp > 10000) {
    outbuffer[obp] = '\0';
    add_links(outbuffer);
    obp = 0;
   }
   c++;
  }
 }
}
static char *switchfont[16] = {
 "", "" "<I>", "" "<B>", "" "<TT>",
 "</I>" "", "", "</I>" "<B>", "</I>" "<TT>",
 "</B>" "", "</B>" "<I>", "", "</B>" "<TT>",
 "</TT>" "", "</TT>" "<I>", "</TT>" "<B>", ""
};

static char *
change_to_font(int nr)
{
 int i;

 switch (nr) {
 case '0':
  nr++;
 case '1':
 case '2':
 case '3':
 case '4':
  nr = nr - '1';
  break;
 case (('C')*256+('W')):
  nr = 3;
  break;
 case 'L':
  nr = 3;
  break;
 case 'B':
  nr = 2;
  break;
 case 'I':
  nr = 1;
  break;
 case 'P':
 case 'R':
  nr = 0;
  break;
 case 0:
 case 1:
 case 2:
 case 3:
  break;
 default:
  nr = 0;
  break;
 }
 i = current_font * 4 + nr % 4;
 current_font = nr % 4;
 return switchfont[i];
}

static char sizebuf[200];

static char *
change_to_size(int nr)
{
 int i;

 switch (nr) {
 case '0':
 case '1':
 case '2':
 case '3':
 case '4':
 case '5':
 case '6':
 case '7':
 case '8':
 case '9':
  nr = nr - '0';
  break;
 case '\0':
  break;
 default:
  nr = current_size + nr;
  if (nr > 9)
   nr = 9;
  if (nr < -9)
   nr = -9;
  break;
 }
 if (nr == current_size)
  return "";
 i = current_font;
 sizebuf[0] = '\0';
 strcat(sizebuf, change_to_font(0));
 if (current_size)
  strcat(sizebuf, "</FONT>");
 current_size = nr;
 if (nr) {
  int l;

  strcat(sizebuf, "<FONT SIZE=");
  l = strlen(sizebuf);
  if (nr > 0)
   sizebuf[l++] = '+';
  else
   sizebuf[l++] = '-', nr = -nr;
  sizebuf[l++] = nr + '0';
  sizebuf[l++] = '>';
  sizebuf[l] = '\0';
 }
 strcat(sizebuf, change_to_font(i));
 return sizebuf;
}

static int asint = 0;
static int intresult = 0;



static int skip_escape = 0;
static int single_escape = 0;

static char *
scan_escape(char *c)
{
 char *h = 
            ((void *)0)
                ;
 char b[5];
 INTDEF *intd;
 int exoutputp, exskipescape;
 int i, j;

 intresult = 0;
 switch (*c) {
 case 'e':
  h = "\\";
  curpos++;
  break;
 case '0':
 case ' ':
  h = "&nbsp;";
  curpos++;
  break;
 case '|':
  h = "";
  break;
 case '"':
  while (*c && *c++!='\n');
  c--;
  h = "";
  break;
 case '$':
  if (argument) {
   c++;
   i = (*c - '1');
   if (!(h = argument[i]))
    h = "";
  }
  break;
 case 'z':
  c++;
  if (*c == '\\') {
   c = scan_escape(c + 1);
   c--;
   h = "";
  } else {
   b[0] = *c;
   b[1] = '\0';
   h = "";
  }
  break;
 case 'k':
  c++;
  if (*c == '(')
   c += 2;
 case '^':
 case '!':
 case '%':
 case 'a':
 case 'd':
 case 'r':
 case 'u':
 case '\n':
 case '&':
  h = "";
  break;
 case '(':
  c++;
  i = c[0] * 256 + c[1];
  c++;
  h = expand_char(i);
  break;
 case '*':
  c++;
  if (*c == '(') {
   c++;
   i = c[0] * 256 + c[1];
   c++;
  } else
   i = *c * 256 + ' ';
  h = expand_string(i);
  break;
 case 'f':
  c++;
  if (*c == '\\') {
   c++;
   c = scan_escape(c);
   c--;
   i = intresult;
  } else if (*c != '(')
   i = *c;
  else {
   c++;
   i = c[0] * 256 + c[1];
   c++;
  }
  if (!skip_escape)
   h = change_to_font(i);
  else
   h = "";
  break;
 case 's':
  c++;
  j = 0;
  i = 0;
  if (*c == '-') {
   j = -1;
   c++;
  } else if (*c == '+') {
   j = 1;
   c++;
  }
  if (*c == '0')
   c++;
  else if (*c == '\\') {
   c++;
   c = scan_escape(c);
   i = intresult;
   if (!j)
    j = 1;
  } else
   while (
         ((*__ctype_b_loc ())[(int) ((
         *c
         ))] & (unsigned short int) _ISdigit) 
                     && (!i || (!j && i < 4)))
    i = i * 10 + (*c++) - '0';
  if (!j) {
   j = 1;
   if (i)
    i = i - 10;
  }
  if (!skip_escape)
   h = change_to_size(i * j);
  else
   h = "";
  c--;
  break;
 case 'n':
  c++;
  j = 0;
  switch (*c) {
  case '+':
   j = 1;
   c++;
   break;
  case '-':
   j = -1;
   c++;
   break;
  default:
   break;
  }
  if (*c == '(') {
   c++;
   i = ((c[0])*256+(c[1]));
   c = c + 1;
  } else {
   i = ((c[0])*256+(' '));
  }
  intd = intdef;
  while (intd && intd->nr != i)
   intd = intd->next;
  if (intd) {
   intd->val = intd->val + j * intd->incr;
   intresult = intd->val;
  } else {
   switch (i) {
   case (('.')*256+('s')):
    intresult = current_size;
    break;
   case (('.')*256+('f')):
    intresult = current_font;
    break;
   default:
    intresult = 0;
    break;
   }
  }
  h = "";
  break;
 case 'w':
  c++;
  i = *c;
  c++;
  exoutputp = output_possible;
  exskipescape = skip_escape;
  output_possible = 0;
  skip_escape = 1;
  j = 0;
  while (*c != i) {
   j++;
   if (*c == escapesym)
    c = scan_escape(c + 1);
   else
    c++;
  }
  output_possible = exoutputp;
  skip_escape = exskipescape;
  intresult = j;
  break;
 case 'l':
  h = "<HR>";
  curpos = 0;
 case 'b':
 case 'v':
 case 'x':
 case 'o':
 case 'L':
 case 'h':
  c++;
  i = *c;
  c++;
  exoutputp = output_possible;
  exskipescape = skip_escape;
  output_possible = 0;
  skip_escape = 1;
  while (*c != i)
   if (*c == escapesym)
    c = scan_escape(c + 1);
   else
    c++;
  output_possible = exoutputp;
  skip_escape = exskipescape;
  break;
 case 'c':
  no_newline_output = 1;
  break;
 case '{':
  newline_for_fun++;
  h = "";
  break;
 case '}':
  if (newline_for_fun)
   newline_for_fun--;
  h = "";
  break;
 case 'p':
  h = "<BR>\n";
  curpos = 0;
  break;
 case 't':
  h = "\t";
  curpos = (curpos + 8) & 0xfff8;
  break;
 case '<':
  h = "&lt;";
  curpos++;
  break;
 case '>':
  h = "&gt;";
  curpos++;
  break;
 case '\\':
  if (single_escape) {
   c--;
   break;
  }
 default:
  b[0] = *c;
  b[1] = 0;
  h = b;
  curpos++;
  break;
 }
 c++;
 if (!skip_escape)
  out_html(h);
 return c;
}

typedef struct TABLEITEM TABLEITEM;

struct TABLEITEM {
 char *contents;
 int size, align, valign, colspan, rowspan, font, vleft, vright, space,
         width;
 TABLEITEM *next;
};

static TABLEITEM emptyfield = {
                              ((void *)0)
                                  , 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                                                  ((void *)0)
                                                                      };

typedef struct TABLEROW TABLEROW;

struct TABLEROW {
 TABLEITEM *first;
 TABLEROW *prev, *next;
};

static char *tableopt[] = {
 "center", "expand", "box", "allbox", "doublebox",
 "tab", "linesize", "delim", 
                            ((void *)0)

};
static int tableoptl[] = {6, 6, 3, 6, 9, 3, 8, 5, 0};

static void
clear_table(TABLEROW * table)
{
 TABLEROW *tr1, *tr2;
 TABLEITEM *ti1, *ti2;

 tr1 = table;
 while (tr1->prev)
  tr1 = tr1->prev;
 while (tr1) {
  ti1 = tr1->first;
  while (ti1) {
   ti2 = ti1->next;
   if (ti1->contents)
    free(ti1->contents);
   free(ti1);
   ti1 = ti2;
  }
  tr2 = tr1;
  tr1 = tr1->next;
  free(tr2);
 }
}

static char *scan_expression(char *c, int *result);

static char *
scan_format(char *c, TABLEROW ** result, int *maxcol)
{
 TABLEROW *layout, *currow;
 TABLEITEM *curfield;
 int i, j;

 if (*result) {
  clear_table(*result);
 }
 layout = currow = (TABLEROW *) xmalloc(sizeof(TABLEROW));
 currow->next = currow->prev = 
                              ((void *)0)
                                  ;
 currow->first = curfield = (TABLEITEM *) xmalloc(sizeof(TABLEITEM));
 *curfield = emptyfield;
 while (*c && *c != '.') {
  switch (*c) {
  case 'C':
  case 'c':
  case 'N':
  case 'n':
  case 'R':
  case 'r':
  case 'A':
  case 'a':
  case 'L':
  case 'l':
  case 'S':
  case 's':
  case '^':
  case '_':
   if (curfield->align) {
    curfield->next = (TABLEITEM *) xmalloc(sizeof(TABLEITEM));
    curfield = curfield->next;
    *curfield = emptyfield;
   }
   curfield->align = toupper(*c);
   c++;
   break;
  case 'i':
  case 'I':
  case 'B':
  case 'b':
   curfield->font = toupper(*c);
   c++;
   break;
  case 'f':
  case 'F':
   c++;
   curfield->font = toupper(*c);
   c++;
   if (!
       ((*__ctype_b_loc ())[(int) ((
       *c
       ))] & (unsigned short int) _ISspace)
                  )
    c++;
   break;
  case 't':
  case 'T':
   curfield->valign = 't';
   c++;
   break;
  case 'p':
  case 'P':
   c++;
   i = j = 0;
   if (*c == '+') {
    j = 1;
    c++;
   }
   if (*c == '-') {
    j = -1;
    c++;
   }
   while (
         ((*__ctype_b_loc ())[(int) ((
         *c
         ))] & (unsigned short int) _ISdigit)
                    )
    i = i * 10 + (*c++) - '0';
   if (j)
    curfield->size = i * j;
   else
    curfield->size = j - 10;
   break;
  case 'v':
  case 'V':
  case 'w':
  case 'W':
   c = scan_expression(c + 2, &curfield->width);
   break;
  case '|':
   if (curfield->align)
    curfield->vleft++;
   else
    curfield->vright++;
   c++;
   break;
  case 'e':
  case 'E':
   c++;
   break;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
   i = 0;
   while (
         ((*__ctype_b_loc ())[(int) ((
         *c
         ))] & (unsigned short int) _ISdigit)
                    )
    i = i * 10 + (*c++) - '0';
   curfield->space = i;
   break;
  case ',':
  case '\n':
   currow->next = (TABLEROW *) xmalloc(sizeof(TABLEROW));
   currow->next->prev = currow;
   currow = currow->next;
   currow->next = 
                 ((void *)0)
                     ;
   curfield = currow->first = (TABLEITEM *) xmalloc(sizeof(TABLEITEM));
   *curfield = emptyfield;
   c++;
   break;
  default:
   c++;
   break;
  }
 }
 if (*c == '.')
  while (*c++ != '\n');
 *maxcol = 0;
 currow = layout;
 while (currow) {
  curfield = layout->first;
  i = 0;
  while (curfield) {
   i++;
   curfield = curfield->next;
  }
  if (i > *maxcol)
   *maxcol = i;
  currow = currow->next;
 }
 *result = layout;
 return c;
}

static TABLEROW *
next_row(TABLEROW * tr)
{
 if (tr->next) {
  tr = tr->next;
  if (!tr->next)
   next_row(tr);
  return tr;
 } else {
  TABLEITEM *ti, *ti2;

  tr->next = (TABLEROW *) xmalloc(sizeof(TABLEROW));
  tr->next->prev = tr;
  ti = tr->first;
  tr = tr->next;
  tr->next = 
            ((void *)0)
                ;
  if (ti)
   tr->first = ti2 = (TABLEITEM *) xmalloc(sizeof(TABLEITEM));
  else
   tr->first = ti2 = 
                    ((void *)0)
                        ;
  while (ti != ti2) {
   *ti2 = *ti;
   ti2->contents = 
                  ((void *)0)
                      ;
   if ((ti = ti->next)) {
    ti2->next = (TABLEITEM *) xmalloc(sizeof(TABLEITEM));
   }
   ti2 = ti2->next;
  }
  return tr;
 }
}

static char itemreset[20] = "\\fR\\s0";

static char *
scan_table(char *c)
{
 char *t, *h, *g;
 int center = 0, expand = 0, box = 0, border = 0, linesize = 1;
 int i, j, maxcol = 0, finished = 0;
 int oldfont, oldsize, oldfillout;
 char itemsep = '\t';
 TABLEROW *layout = 
                   ((void *)0)
                       , *currow, *ftable;
 TABLEITEM *curfield;

 while (*c++ != '\n');
 h = c;
 if (*h == '.')
  return c - 1;
 oldfont = current_font;
 oldsize = current_size;
 oldfillout = fillout;
 out_html(change_to_font(0));
 out_html(change_to_size(0));
 if (!fillout) {
  fillout = 1;
  out_html("</PRE>");
 }
 while (*h && *h != '\n')
  h++;
 if (h[-1] == ';') {

  while (c < h) {
   while (
         ((*__ctype_b_loc ())[(int) ((
         *c
         ))] & (unsigned short int) _ISspace)
                    )
    c++;
   for (i = 0; tableopt[i] && strncmp(tableopt[i], c, tableoptl[i]); i++);
   c = c + tableoptl[i];
   switch (i) {
   case 0:
    center = 1;
    break;
   case 1:
    expand = 1;
    break;
   case 2:
    box = 1;
    break;
   case 3:
    border = 1;
    break;
   case 4:
    box = 2;
    break;
   case 5:
    while (*c++ != '(');
    itemsep = *c++;
    break;
   case 6:
    while (*c++ != '(');
    linesize = 0;
    while (
          ((*__ctype_b_loc ())[(int) ((
          *c
          ))] & (unsigned short int) _ISdigit)
                     )
     linesize = linesize * 10 + (*c++) - '0';
    break;
   case 7:
    while (*c != ')')
     c++;
   default:
    break;
   }
   c++;
  }
  c = h + 1;
 }

 c = scan_format(c, &layout, &maxcol);
 currow = layout;
 next_row(currow);
 curfield = layout->first;
 i = 0;
 while (!finished) {

  h = c;
  if ((*c == '_' || *c == '=') && (c[1] == itemsep || c[1] == '\n')) {
   if (c[-1] == '\n' && c[1] == '\n') {
    if (currow->prev) {
     currow->prev->next = (TABLEROW *) xmalloc(sizeof(TABLEROW));
     currow->prev->next->next = currow;
     currow->prev->next->prev = currow->prev;
     currow->prev = currow->prev->next;
    } else {
     currow->prev = layout = (TABLEROW *) xmalloc(sizeof(TABLEROW));
     currow->prev->prev = 
                         ((void *)0)
                             ;
     currow->prev->next = currow;
    }
    curfield = currow->prev->first =
     (TABLEITEM *) xmalloc(sizeof(TABLEITEM));
    *curfield = emptyfield;
    curfield->align = *c;
    curfield->colspan = maxcol;
    curfield = currow->first;
    c = c + 2;
   } else {
    if (curfield) {
     curfield->align = *c;
     do {
      curfield = curfield->next;
     } while (curfield && curfield->align == 'S');
    }
    if (c[1] == '\n') {
     currow = next_row(currow);
     curfield = currow->first;
    }
    c = c + 2;
   }
  } else if (*c == 'T' && c[1] == '{') {
   h = c + 2;
   c = strstr(h, "\nT}");
   c++;
   *c = '\0';
   g = 
      ((void *)0)
          ;
   scan_troff(h, 0, &g);
   scan_troff(itemreset, 0, &g);
   *c = 'T';
   c += 3;
   if (curfield) {
    curfield->contents = g;
    do {
     curfield = curfield->next;
    } while (curfield && curfield->align == 'S');
   } else if (g)
    free(g);
   if (c[-1] == '\n') {
    currow = next_row(currow);
    curfield = currow->first;
   }
  } else if (*c == '.' && c[1] == 'T' && c[2] == '&' && c[-1] == '\n') {
   TABLEROW *hr;

   while (*c++ != '\n');
   hr = currow;
   currow = currow->prev;
   hr->prev = 
             ((void *)0)
                 ;
   c = scan_format(c, &hr, &i);
   hr->prev = currow;
   currow->next = hr;
   currow = hr;
   next_row(currow);
   curfield = currow->first;
  } else if (*c == '.' && c[1] == 'T' && c[2] == 'E' && c[-1] == '\n') {
   finished = 1;
   while (*c++ != '\n');
   if (currow->prev)
    currow->prev->next = 
                        ((void *)0)
                            ;
   currow->prev = 
                 ((void *)0)
                     ;
   clear_table(currow);
  } else if (*c == '.' && c[-1] == '\n' && !
                                           ((*__ctype_b_loc ())[(int) ((
                                           c[1]
                                           ))] & (unsigned short int) _ISdigit)
                                                        ) {




   while (*c++ != '\n');
  } else {
   h = c;
   while (*c && (*c != itemsep || c[-1] == '\\') &&
          (*c != '\n' || c[-1] == '\\'))
    c++;
   i = 0;
   if (*c == itemsep) {
    i = 1;
    *c = '\n';
   }
   if (h[0] == '\\' && h[2] == '\n' &&
       (h[1] == '_' || h[1] == '^')) {
    if (curfield) {
     curfield->align = h[1];
     do {
      curfield = curfield->next;
     } while (curfield && curfield->align == 'S');
    }
    h = h + 3;
   } else {
    g = 
       ((void *)0)
           ;
    h = scan_troff(h, 1, &g);
    scan_troff(itemreset, 0, &g);
    if (curfield) {
     curfield->contents = g;
     do {
      curfield = curfield->next;
     } while (curfield && curfield->align == 'S');
    } else if (g)
     free(g);
   }
   if (i)
    *c = itemsep;
   c = h;
   if (c[-1] == '\n') {
    currow = next_row(currow);
    curfield = currow->first;
   }
  }
 }

 currow = layout;
 while (currow->next)
  currow = currow->next;
 while (currow) {
  TABLEITEM *ti, *ti1 = 
                       ((void *)0)
                           , *ti2 = 
                                    ((void *)0)
                                        ;

  ti = currow->first;
  if (currow->prev)
   ti1 = currow->prev->first;
  while (ti) {
   switch (ti->align) {
   case 'S':
    if (ti2) {
     ti2->colspan++;
     if (ti2->rowspan < ti->rowspan)
      ti2->rowspan = ti->rowspan;
    }
    break;
   case '^':
    if (ti1)
     ti1->rowspan++;
   default:
    if (!ti2)
     ti2 = ti;
    else {
     do {
      ti2 = ti2->next;
     } while (ti2 && curfield->align == 'S');
    }
    break;
   }
   ti = ti->next;
   if (ti1)
    ti1 = ti1->next;
  }
  currow = currow->prev;
 }

 if (center)
  out_html("<CENTER>");
 if (box == 2)
  out_html("<TABLE BORDER><TR><TD>");
 out_html("<TABLE");
 if (box || border) {
  out_html(" BORDER");
  if (!border)
   out_html("><TR><TD><TABLE");
  if (expand)
   out_html(" WIDTH=100%");
 }
 out_html(">\n");
 currow = layout;
 while (currow) {
  j = 0;
  out_html("<TR VALIGN=top>");
  curfield = currow->first;
  while (curfield) {
   if (curfield->align != 'S' && curfield->align != '^') {
    out_html("<TD");
    switch (curfield->align) {
    case 'N':
     curfield->space += 4;
    case 'R':
     out_html(" ALIGN=right");
     break;
    case 'C':
     out_html(" ALIGN=center");
    default:
     break;
    }
    if (!curfield->valign && curfield->rowspan > 1)
     out_html(" VALIGN=center");
    if (curfield->colspan > 1) {
     char buf[5];

     out_html(" COLSPAN=");
     sprintf(buf, "%i", curfield->colspan);
     out_html(buf);
    }
    if (curfield->rowspan > 1) {
     char buf[5];

     out_html(" ROWSPAN=");
     sprintf(buf, "%i", curfield->rowspan);
     out_html(buf);
    }
    j = j + curfield->colspan;
    out_html(">");
    if (curfield->size)
     out_html(change_to_size(curfield->size));
    if (curfield->font)
     out_html(change_to_font(curfield->font));
    switch (curfield->align) {
    case '=':
     out_html("<HR><HR>");
     break;
    case '_':
     out_html("<HR>");
     break;
    default:
     if (curfield->contents)
      out_html(curfield->contents);
     break;
    }
    if (curfield->space)
     for (i = 0; i < curfield->space; i++)
      out_html("&nbsp;");
    if (curfield->font)
     out_html(change_to_font(0));
    if (curfield->size)
     out_html(change_to_size(0));
    if (j >= maxcol && curfield->align > '@' && curfield->align != '_')
     out_html("<BR>");
    out_html("</TD>");
   }
   curfield = curfield->next;
  }
  out_html("</TR>\n");
  currow = currow->next;
 }
 if (box && !border)
  out_html("</TABLE>");
 out_html("</TABLE>");
 if (box == 2)
  out_html("</TABLE>");
 if (center)
  out_html("</CENTER>\n");
 else
  out_html("\n");
 if (!oldfillout)
  out_html("<PRE>");
 fillout = oldfillout;
 out_html(change_to_size(oldsize));
 out_html(change_to_font(oldfont));
 return c;
}

static char *
scan_expression(char *c, int *result)
{
 int value = 0, value2, j = 0, sign = 1, opex = 0;
 char oper = 'c';

 if (*c == '!') {
  c = scan_expression(c + 1, &value);
  value = (!value);
 } else if (*c == 'n') {
  c++;
  value = 0;
 } else if (*c == 't') {
  c++;
  value = 1 - 0;
 } else if (*c == '\'' || *c == '"' || *c < ' ' || (*c == '\\' && c[1] == '(')) {



  char *st1 = 
               ((void *)0)
                   , *st2 = 
                            ((void *)0)
                                , *h;
  char *tcmp = 
                ((void *)0)
                    ;
  char sep;

  sep = *c;
  if (sep == '\\') {
   tcmp = c;
   c = c + 3;
  }
  c++;
  h = c;
  while (*c != sep && (!tcmp || strncmp(c, tcmp, 4)))
   c++;
  *c = '\n';
  scan_troff(h, 1, &st1);
  *c = sep;
  if (tcmp)
   c = c + 3;
  c++;
  h = c;
  while (*c != sep && (!tcmp || strncmp(c, tcmp, 4)))
   c++;
  *c = '\n';
  scan_troff(h, 1, &st2);
  *c = sep;
  if (!st1 && !st2)
   value = 1;
  else if (!st1 || !st2)
   value = 0;
  else
   value = (!strcmp(st1, st2));
  if (st1)
   free(st1);
  if (st2)
   free(st2);
  if (tcmp)
   c = c + 3;
  c++;
 } else {
  while (*c && !
               ((*__ctype_b_loc ())[(int) ((
               *c
               ))] & (unsigned short int) _ISspace) 
                           && *c != ')') {
   opex = 0;
   switch (*c) {
   case '(':
    c = scan_expression(c + 1, &value2);
    value2 = sign * value2;
    opex = 1;
    break;
   case '.':
   case '0':
   case '1':
   case '2':
   case '3':
   case '4':
   case '5':
   case '6':
   case '7':
   case '8':
   case '9':{
     int num = 0, denum = 1;

     value2 = 0;
     while (
           ((*__ctype_b_loc ())[(int) ((
           *c
           ))] & (unsigned short int) _ISdigit)
                      )
      value2 = value2 * 10 + ((*c++) - '0');
     if (*c == '.') {
      c++;
      while (
            ((*__ctype_b_loc ())[(int) ((
            *c
            ))] & (unsigned short int) _ISdigit)
                       ) {
       num = num * 10 + ((*c++) - '0');
       denum = denum * 10;
      }
     }
     if (
        ((*__ctype_b_loc ())[(int) ((
        *c
        ))] & (unsigned short int) _ISalpha)
                   ) {

      switch (*c) {
      case 'i':
       value2 = value2 * 10 + (num * 10 + denum / 2) / denum;
       num = 0;
       break;
      default:
       break;
      }
      c++;
     }
     value2 = value2 + (num + denum / 2) / denum;
     value2 = sign * value2;
     opex = 1;
     break;
    }
   case '\\':
    c = scan_escape(c + 1);
    value2 = intresult * sign;
    if (
       ((*__ctype_b_loc ())[(int) ((
       *c
       ))] & (unsigned short int) _ISalpha)
                  )
     c++;
    opex = 1;
    break;
   case '-':
    if (oper) {
     sign = -1;
     c++;
     break;
    }
   case '>':
   case '<':
   case '+':
   case '/':
   case '*':
   case '%':
   case '&':
   case '=':
   case ':':
    if (c[1] == '=')
     oper = (*c++) + 16;
    else
     oper = *c;
    c++;
    break;
   default:
    c++;
    break;
   }
   if (opex) {
    sign = 1;
    switch (oper) {
    case 'c':
     value = value2;
     break;
    case '-':
     value = value - value2;
     break;
    case '+':
     value = value + value2;
     break;
    case '*':
     value = value * value2;
     break;
    case '/':
     if (value2)
      value = value / value2;
     break;
    case '%':
     if (value2)
      value = value % value2;
     break;
    case '<':
     value = (value < value2);
     break;
    case '>':
     value = (value > value2);
     break;
    case '>' + 16:
     value = (value >= value2);
     break;
    case '<' + 16:
     value = (value <= value2);
     break;
    case '=':
    case '=' + 16:
     value = (value == value2);
     break;
    case '&':
     value = (value && value2);
     break;
    case ':':
     value = (value || value2);
     break;
    default:
     fprintf(
            stderr
                  , "man2html: unknown operator %c.\n", oper);
    }
    oper = 0;
   }
  }
  if (*c == ')')
   c++;
 }
 *result = value;
 return c;
}

static void
trans_char(char *c, char s, char t)
{
 char *sl = c;
 int slash = 0;

 while (*sl != '\n' || slash) {
  if (!slash) {
   if (*sl == escapesym)
    slash = 1;
   else if (*sl == s)
    *sl = t;
  } else
   slash = 0;
  sl++;
 }
}


static char *
unescape (char *c)
{
 int i, l;

 l = strlen (c);
 i = 0;
 while (i < l && c[i]) {
  if (c[i] == '\a') {
   if (c[i+1])
    memmove (c + i, c + i + 1, l - i);
   else {
    c[i] = '\0';
    break;
   }
  }
  i++;
 }
 return c;
}

static char *
fill_words(char *c, char *words[], int *n)
{
 char *sl = c;
 int slash = 0;
 int skipspace = 0;

 *n = 0;
 words[*n] = sl;
 while (*sl && (*sl != '\n' || slash)) {
  if (!slash) {
   if (*sl == '"') {
    *sl = '\a';
    skipspace = !skipspace;
   } else if (*sl == '\a') {

    skipspace = !skipspace;
   } else if (*sl == escapesym)
    slash = 1;
   else if ((*sl == ' ' || *sl == '\t') && !skipspace) {
    *sl = '\n';
    if (words[*n] != sl)
     (*n)++;
    words[*n] = sl + 1;
   }
  } else {
   if (*sl == '"') {
    sl--;
    *sl = '\n';
    if (words[*n] != sl)
     (*n)++;
    sl++;
    while (*sl && *sl != '\n')
     sl++;
    words[*n] = sl;
    sl--;
   }
   slash = 0;
  }
  sl++;
 }
 if (sl != words[*n])
  (*n)++;
 return sl;
}

static char *abbrev_list[] = {
 "GSBG", "Getting Started ",
 "SUBG", "Customizing SunOS",
 "SHBG", "Basic Troubleshooting",
 "SVBG", "SunView User's Guide",
 "MMBG", "Mail and Messages",
 "DMBG", "Doing More with SunOS",
 "UNBG", "Using the Network",
 "GDBG", "Games, Demos &amp; Other Pursuits",
 "CHANGE", "SunOS 4.1 Release Manual",
 "INSTALL", "Installing SunOS 4.1",
 "ADMIN", "System and Network Administration",
 "SECUR", "Security Features Guide",
 "PROM", "PROM User's Manual",
 "DIAG", "Sun System Diagnostics",
 "SUNDIAG", "Sundiag User's Guide",
 "MANPAGES", "SunOS Reference Manual",
 "REFMAN", "SunOS Reference Manual",
 "SSI", "Sun System Introduction",
 "SSO", "System Services Overview",
 "TEXT", "Editing Text Files",
 "DOCS", "Formatting Documents",
 "TROFF", "Using <B>nroff</B> and <B>troff</B>",
 "INDEX", "Global Index",
 "CPG", "C Programmer's Guide",
 "CREF", "C Reference Manual",
 "ASSY", "Assembly Language Reference",
 "PUL", "Programming Utilities and Libraries",
 "DEBUG", "Debugging Tools",
 "NETP", "Network Programming",
 "DRIVER", "Writing Device Drivers",
 "STREAMS", "STREAMS Programming",
 "SBDK", "SBus Developer's Kit",
 "WDDS", "Writing Device Drivers for the SBus",
 "FPOINT", "Floating-Point Programmer's Guide",
 "SVPG", "SunView 1 Programmer's Guide",
 "SVSPG", "SunView 1 System Programmer's Guide",
 "PIXRCT", "Pixrect Reference Manual",
 "CGI", "SunCGI Reference Manual",
 "CORE", "SunCore Reference Manual",
 "4ASSY", "Sun-4 Assembly Language Reference",
 "SARCH", "<FONT SIZE=-1>SPARC</FONT> Architecture Manual",
 "KR", "The C Programming Language",

((void *)0)
   , 
     ((void *)0)
         };

static char *
lookup_abbrev(char *c)
{
 int i = 0;

 if (!c)
  return "";
 while (abbrev_list[i] && strcmp(c, abbrev_list[i]))
  i = i + 2;
 if (abbrev_list[i])
  return abbrev_list[i + 1];
 else
  return c;
}

static char manidx[((10000) + 1)];
static int subs = 0;
static int mip = 0;
static char label[5] = "lbAA";

static void
add_to_index(int level, char *item)
{
 char *c = 
            ((void *)0)
                ;

 label[3]++;
 if (label[3] > 'Z') {
  label[3] = 'A';
  label[2]++;
 }
 if (level != subs) {
  if (subs) {
   strmaxcpy(manidx + mip, "</DL>\n", 10000 - mip);
   mip += 6;
  } else {
   strmaxcpy(manidx + mip, "<DL>\n", 10000 - mip);
   mip += 5;
  }
 }
 subs = level;
 scan_troff(item, 1, &c);
 sprintf(manidx + mip, "<DT><A HREF=\"#%s\">%s</A><DD>\n", label, c);
 if (c)
  free(c);
 while (manidx[mip])
  mip++;
}

static char *
skip_till_newline(char *c)
{
 int lvl = 0;

 while (*c && *c != '\n' || lvl > 0) {
  if (*c == '\\') {
   c++;
   if (*c == '}')
    lvl--;
   else if (*c == '{')
    lvl++;
  }
  c++;
 }
 c++;
 if (lvl < 0 && newline_for_fun) {
  newline_for_fun = newline_for_fun + lvl;
  if (newline_for_fun < 0)
   newline_for_fun = 0;
 }
 return c;
}

static void
outputPageHeader(char *l, char *c, char *r)
{
 out_html("<TABLE WIDTH=100%>\n<TR>\n");
 out_html("<TH ALIGN=LEFT width=33%>");
 out_html(l);
 out_html("<TH ALIGN=CENTER width=33%>");
 out_html(c);
 out_html("<TH ALIGN=RIGHT width=33%>");
 out_html(r);
 out_html("\n</TR>\n</TABLE>\n");
}

static void
outputPageFooter(char *l, char *c, char *r)
{
 out_html("<HR>\n");
 outputPageHeader(l, c, r);
}

static int ifelseval = 0;

static char *
scan_request(char *c)
{

 static int mandoc_synopsis = 0;

 static int mandoc_command = 0;
 static int mandoc_bd_options;

 int i, j, mode = 0;
 char *h;
 char *wordlist[100];
 int words;
 char *sl;
 STRDEF *owndef;

 while (*c == ' ' || *c == '\t')
  c++;
 if (c[0] == '\n')
  return c + 1;
 if (c[1] == '\n')
  j = 1;
 else
  j = 2;
 while (c[j] == ' ' || c[j] == '\t')
  j++;
 if (c[0] == escapesym) {


  if (c[1] == '$')
   c = skip_till_newline(c);
  else
   c = scan_escape(c + 1);
 } else {
  i = ((c[0])*256+(c[1]));
  switch (i) {
  case (('a')*256+('b')):
   h = c + j;
   while (*h && *h != '\n')
    h++;
   *h = '\0';
   if (scaninbuff && buffpos) {
    buffer[buffpos] = '\0';
    puts(buffer);
   }

   exit(0);
   break;
  case (('d')*256+('i')):
   {
    STRDEF *de;
    int oldcurpos = curpos;

    c = c + j;
    i = ((c[0])*256+(c[1]));
    if (*c == '\n') {
     c++;
     break;
    }
    while (*c && *c != '\n')
     c++;
    c++;
    h = c;
    while (*c && strncmp(c, ".di", 3))
     while (*c && *c++ != '\n');
    *c = '\0';
    de = strdef;
    while (de && de->nr != i)
     de = de->next;
    if (!de) {
     de = (STRDEF *) xmalloc(sizeof(STRDEF));
     de->nr = i;
     de->slen = 0;
     de->next = strdef;
     de->st = 
             ((void *)0)
                 ;
     strdef = de;
    } else {
     if (de->st)
      free(de->st);
     de->slen = 0;
     de->st = 
             ((void *)0)
                 ;
    }
    scan_troff(h, 0, &de->st);
    *c = '.';
    while (*c && *c++ != '\n');
    break;
   }
  case (('d')*256+('s')):
   mode = 1;
  case (('a')*256+('s')):
   {
    STRDEF *de;
    int oldcurpos = curpos;

    c = c + j;
    i = ((c[0])*256+(c[1]));
    j = 0;
    while (c[j] && c[j] != '\n')
     j++;
    if (j < 3) {
     c = c + j;
     break;
    }
    if (c[1] == ' ')
     c = c + 1;
    else
     c = c + 2;
    while (
          ((*__ctype_b_loc ())[(int) ((
          *c
          ))] & (unsigned short int) _ISspace)
                     )
     c++;
    if (*c == '"')
     c++;
    de = strdef;
    while (de && de->nr != i)
     de = de->next;
    single_escape = 1;
    curpos = 0;
    if (!de) {
     char *h;

     de = (STRDEF *) xmalloc(sizeof(STRDEF));
     de->nr = i;
     de->slen = 0;
     de->next = strdef;
     de->st = 
             ((void *)0)
                 ;
     strdef = de;
     h = 
        ((void *)0)
            ;
     c = scan_troff(c, 1, &h);
     de->st = h;
     de->slen = curpos;
    } else {
     if (mode) {
      char *h = 
                 ((void *)0)
                     ;

      c = scan_troff(c, 1, &h);
      free(de->st);
      de->slen = 0;
      de->st = h;
     } else
      c = scan_troff(c, 1, &de->st);
     de->slen += curpos;
    }
    single_escape = 0;
    curpos = oldcurpos;
   }
   break;
  case (('b')*256+('r')):
   if (still_dd)
    out_html("<DD>");
   else
    out_html("<BR>\n");
   curpos = 0;
   c = c + j;
   if (c[0] == escapesym) {
    c = scan_escape(c + 1);
   }
   c = skip_till_newline(c);
   break;
  case (('c')*256+('2')):
   c = c + j;
   if (*c != '\n') {
    nobreaksym = *c;
   } else
    nobreaksym = '\'';
   c = skip_till_newline(c);
   break;
  case (('c')*256+('c')):
   c = c + j;
   if (*c != '\n') {
    controlsym = *c;
   } else
    controlsym = '.';
   c = skip_till_newline(c);
   break;
  case (('c')*256+('e')):
   c = c + j;
   if (*c == '\n') {
    i = 1;
   } else {
    i = 0;
    while ('0' <= *c && *c <= '9') {
     i = i * 10 + *c - '0';
     c++;
    }
   }
   c = skip_till_newline(c);

   if (i > 0) {
    out_html("<CENTER>\n");
    while (i && *c) {
     char *line = 
                   ((void *)0)
                       ;

     c = scan_troff(c, 1, &line);
     if (line && strncmp(line, "<BR>", 4)) {
      out_html(line);
      out_html("<BR>\n");
      i--;
     }
    }
    out_html("</CENTER>\n");
    curpos = 0;
   }
   break;
  case (('e')*256+('c')):
   c = c + j;
   if (*c != '\n') {
    escapesym = *c;
   } else
    escapesym = '\\';
   break;
   c = skip_till_newline(c);
  case (('e')*256+('o')):
   escapesym = '\0';
   c = skip_till_newline(c);
   break;
  case (('e')*256+('x')):
   exit(0);
   break;
  case (('f')*256+('c')):
   c = c + j;
   if (*c == '\n') {
    fieldsym = padsym = '\0';
   } else {
    fieldsym = c[0];
    padsym = c[1];
   }
   c = skip_till_newline(c);
   break;
  case (('f')*256+('i')):
   if (!fillout) {
    out_html(change_to_font(0));
    out_html(change_to_size('0'));
    out_html("</PRE>\n");
   }
   curpos = 0;
   fillout = 1;
   c = skip_till_newline(c);
   break;
  case (('f')*256+('t')):
   c = c + j;
   if (*c == '\n') {
    out_html(change_to_font(0));
   } else {
    if (*c == escapesym) {
     int fn;

     c = scan_expression(c, &fn);
     c--;
     out_html(change_to_font(fn));
    } else {
     out_html(change_to_font(*c));
     c++;
    }
   }
   c = skip_till_newline(c);
   break;
  case (('e')*256+('l')):

   if (ifelseval) {
    c = c + j;
    c[-1] = '\n';
    c = scan_troff(c, 1, 
                        ((void *)0)
                            );
   } else
    c = skip_till_newline(c + j);
   break;
  case (('i')*256+('e')):

  case (('i')*256+('f')):





   c = c + j;
   c = scan_expression(c, &i);
   ifelseval = !i;
   if (i) {
    *c = '\n';
    c++;
    c = scan_troff(c, 1, 
                        ((void *)0)
                            );
   } else
    c = skip_till_newline(c);
   break;
  case (('i')*256+('g')):
   {
    char *endwith = "..\n";

    i = 3;
    c = c + j;
    if (*c != '\n') {
     endwith = c - 1;
     i = 1;
     c[-1] = '.';
     while (*c && *c != '\n')
      c++, i++;
    }
    c++;
    while (*c && strncmp(c, endwith, i))
     while (*c++ != '\n');
    while (*c++ != '\n');
    break;
   }
  case (('n')*256+('f')):
   if (fillout) {
    out_html(change_to_font(0));
    out_html(change_to_size('0'));
    out_html("<PRE>\n");
   }
   curpos = 0;
   fillout = 0;
   c = skip_till_newline(c);
   break;
  case (('p')*256+('s')):
   c = c + j;
   if (*c == '\n') {
    out_html(change_to_size('0'));
   } else {
    j = 0;
    i = 0;
    if (*c == '-') {
     j = -1;
     c++;
    } else if (*c == '+') {
     j = 1;
     c++;
    }
    c = scan_expression(c, &i);
    if (!j) {
     j = 1;
     if (i > 5)
      i = i - 10;
    }
    out_html(change_to_size(i * j));
   }
   c = skip_till_newline(c);
   break;
  case (('s')*256+('p')):
   c = c + j;
   if (fillout)
    out_html("<P>");
   else {
    out_html(NEWLINE);
    NEWLINE[0] = '\n';
   }
   curpos = 0;
   c = skip_till_newline(c);
   break;
  case (('s')*256+('o')):
   {
    FILE *f;
    struct stat stbuf;
    int l = 0;
    char *buf;
    char *name = 
                  ((void *)0)
                      ;

    curpos = 0;
    c = c + j;
    if (*c == '/') {
     h = c;
    } else {
     h = c - 3;
     h[0] = '.';
     h[1] = '.';
     h[2] = '/';
    }
    while (*c != '\n')
     c++;
    *c = '\0';
    scan_troff(h, 1, &name);
    if (name[3] == '/')
     h = name + 3;
    else
     h = name;
    if (stat(h, &stbuf) != -1)
     l = stbuf.st_size;
    {




     buf = read_man_page(h);
     if (!buf) {

      fprintf(
             stderr
                   , "man2html: unable to open or read file %s.\n",
       h);
      out_html("<BLOCKQUOTE>"
        "man2html: unable to open or read file.\n");
      out_html(h);
      out_html("</BLOCKQUOTE>\n");
     } else {
      buf[0] = buf[l] = '\n';
      buf[l + 1] = buf[l + 2] = '\0';
      scan_troff(buf + 1, 0, 
                            ((void *)0)
                                );
     }
     if (buf)
      free(buf);
    }
    *c++ = '\n';
    break;
   }
  case (('t')*256+('a')):
   c = c + j;
   j = 0;
   while (*c != '\n') {
    sl = scan_expression(c, &tabstops[j]);
    if (*c == '-' || *c == '+')
     tabstops[j] += tabstops[j - 1];
    c = sl;
    while (*c == ' ' || *c == '\t')
     c++;
    j++;
   }
   maxtstop = j;
   curpos = 0;
   break;
  case (('t')*256+('i')):





   out_html("<BR>\n");
   c = c + j;
   c = scan_expression(c, &j);
   for (i = 0; i < j; i++)
    out_html("&nbsp;");
   curpos = j;
   c = skip_till_newline(c);
   break;
  case (('t')*256+('m')):
   c = c + j;
   h = c;
   while (*c != '\n')
    c++;
   *c = '\0';

   *c = '\n';
   break;
  case (('B')*256+(' ')):
  case (('B')*256+('\n')):
  case (('I')*256+(' ')):
  case (('I')*256+('\n')):

   out_html(change_to_font(*c));
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   c = scan_troff(c, 1, 
                       ((void *)0)
                           );
   out_html(change_to_font('R'));
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('O')*256+('P')):


   mode = 1;
   c[0] = 'B';
   c[1] = 'I';
   out_html(change_to_font('R'));
   out_html("[");
   curpos++;
  case (('B')*256+('R')):
  case (('B')*256+('I')):
  case (('I')*256+('B')):
  case (('I')*256+('R')):
  case (('R')*256+('B')):
  case (('R')*256+('I')):
   {
    char font[2];

    font[0] = c[0];
    font[1] = c[1];
    c = c + j;
    if (*c == '\n')
     c++;
    sl = fill_words(c, wordlist, &words);
    c = sl + 1;




    for (i = 0; i < words; i++) {
     if (mode) {
      out_html(" ");
      curpos++;
     }
     wordlist[i][-1] = ' ';
     out_html(change_to_font(font[i & 1]));
     scan_troff(wordlist[i], 1, 
                               ((void *)0)
                                   );
    }
    out_html(change_to_font('R'));
    if (mode) {
     out_html(" ]");
     curpos++;
    }
    out_html(NEWLINE);
    if (!fillout)
     curpos = 0;
    else
     curpos++;
   }
   break;
  case (('D')*256+('T')):
   for (j = 0; j < 20; j++)
    tabstops[j] = (j + 1) * 8;
   maxtstop = 20;
   c = skip_till_newline(c);
   break;
  case (('I')*256+('P')):
   sl = fill_words(c + j, wordlist, &words);
   c = sl + 1;
   if (!dl_set[itemdepth]) {
    out_html("<DL COMPACT>\n");
    dl_set[itemdepth] = 1;
   }
   out_html("<DT>");
   if (words) {
    scan_troff(wordlist[0], 1, 
                              ((void *)0)
                                  );
   }
   out_html("<DD>");
   curpos = 0;
   break;
  case (('T')*256+('P')):
   if (!dl_set[itemdepth]) {
    out_html("<DL COMPACT>\n");
    dl_set[itemdepth] = 1;
   }
   out_html("<DT>");
   c = skip_till_newline(c);

   if (!*c)
    still_dd = 1;
   else {
    c = scan_troff(c, 1, 
                        ((void *)0)
                            );
    out_html("<DD>");
   }
   curpos = 0;
   break;
  case (('I')*256+('X')):

   sl = fill_words(c + j, wordlist, &words);
   c = sl + 1;
   j = 4;
   while (idxlabel[j] == 'Z')
    idxlabel[j--] = 'A';
   idxlabel[j]++;
   out_html("<A NAME=\"");
   out_html(idxlabel);





   out_html("\"></A>");
   break;
  case (('L')*256+('P')):
  case (('P')*256+('P')):
   if (dl_set[itemdepth]) {
    out_html("</DL>\n");
    dl_set[itemdepth] = 0;
   }
   if (fillout)
    out_html("<P>\n");
   else {
    out_html(NEWLINE);
    NEWLINE[0] = '\n';
   }
   curpos = 0;
   c = skip_till_newline(c);
   break;
  case (('H')*256+('P')):
   if (!dl_set[itemdepth]) {
    out_html("<DL COMPACT>");
    dl_set[itemdepth] = 1;
   }
   out_html("<DT>\n");
   still_dd = 1;
   c = skip_till_newline(c);
   curpos = 0;
   break;
  case (('P')*256+('D')):
   c = skip_till_newline(c);
   break;
  case (('R')*256+('s')):
  case (('R')*256+('S')):
   sl = fill_words(c + j, wordlist, &words);
   j = 1;
   if (words > 0)
    scan_expression(wordlist[0], &j);
   if (j >= 0) {
    itemdepth++;
    dl_set[itemdepth] = 0;
    out_html("<DL COMPACT><DT><DD>");
    c = skip_till_newline(c);
    curpos = 0;
    break;
   }
  case (('R')*256+('e')):
  case (('R')*256+('E')):
   if (itemdepth > 0) {
    if (dl_set[itemdepth])
     out_html("</DL>");
    out_html("</DL>\n");
    itemdepth--;
   }
   c = skip_till_newline(c);
   curpos = 0;
   break;
  case (('S')*256+('B')):
   out_html(change_to_size(-1));
   out_html(change_to_font('B'));
   c = scan_troff(c + j, 1, 
                           ((void *)0)
                               );
   out_html(change_to_font('R'));
   out_html(change_to_size('0'));
   break;
  case (('S')*256+('M')):
   c = c + j;
   if (*c == '\n')
    c++;
   out_html(change_to_size(-1));
   trans_char(c, '"', '\a');
   c = scan_troff(c, 1, 
                       ((void *)0)
                           );
   out_html(change_to_size('0'));
   break;
  case (('S')*256+('s')):
   mandoc_command = 1;
  case (('S')*256+('S')):
   mode = 1;
  case (('S')*256+('h')):

   mandoc_command = !mode || mandoc_command;
  case (('S')*256+('H')):
   c = c + j;
   if (*c == '\n')
    c++;
   while (itemdepth || dl_set[itemdepth]) {
    out_html("</DL>\n");
    if (dl_set[itemdepth])
     dl_set[itemdepth] = 0;
    else if (itemdepth > 0)
     itemdepth--;
   }
   out_html(change_to_font(0));
   out_html(change_to_size(0));
   if (!fillout) {
    fillout = 1;
    out_html("</PRE>");
   }
   trans_char(c, '"', '\a');
   add_to_index(mode, c);
   out_html("<A NAME=\"");
   out_html(label);

   if (mode)
    out_html("\">&nbsp;</A>\n<H4>");
   else
    out_html("\">&nbsp;</A>\n<H3>");
   mandoc_synopsis = strncmp(c, "SYNOPSIS", 8) == 0;
   c = mandoc_command ? scan_troff_mandoc(c, 1, 
                                               ((void *)0)
                                                   ) : scan_troff(c, 1, 
                                                                        ((void *)0)
                                                                            );
   if (mode)
    out_html("</H4>\n");
   else
    out_html("</H3>\n");
   curpos = 0;
   break;
  case (('T')*256+('S')):
   c = scan_table(c);
   break;
  case (('D')*256+('t')):
   mandoc_command = 1;
  case (('T')*256+('H')):
   if (!output_possible) {
    sl = fill_words(c + j, wordlist, &words);
    if (words > 1) {
     char *t;
     for (i = 1; i < words; i++)
      wordlist[i][-1] = '\0';
     *sl = '\0';
     output_possible = 1;
     sprintf(th_page_and_sec, "%s(%s)", wordlist[0], wordlist[1]);
     if (words > 2) {
      t = unescape(wordlist[2]);
      strncpy(th_datestr, t, sizeof(th_datestr));
      th_datestr[sizeof(th_datestr) - 1] = '\0';
     } else
      th_datestr[0] = '\0';
     if (words > 3) {
      t = unescape(wordlist[3]);
      strncpy(th_version, t, sizeof(th_version));
      th_version[sizeof(th_version) - 1] = '\0';
     } else
      th_version[0] = '\0';
     out_html("<HTML><HEAD>\n<TITLE>");
     out_html(th_page_and_sec);
     out_html(" Manual Page");
     out_html("</TITLE>\n</HEAD>\n<BODY>");

     outputPageHeader(th_page_and_sec, th_datestr, th_page_and_sec);

     out_html("<BR><A HREF=\"#index\">Index</A>\n");
     *sl = '\n';
     out_html("<HR>\n");
     if (mandoc_command)
      out_html("<BR>BSD mandoc<BR>");
    }
    c = sl + 1;
   } else
    c = skip_till_newline(c);
   curpos = 0;
   break;
  case (('T')*256+('X')):
   sl = fill_words(c + j, wordlist, &words);
   *sl = '\0';
   out_html(change_to_font('I'));
   if (words > 1)
    wordlist[1][-1] = '\0';
   c = lookup_abbrev(wordlist[0]);
   curpos += strlen(c);
   out_html(c);
   out_html(change_to_font('R'));
   if (words > 1)
    out_html(wordlist[1]);
   *sl = '\n';
   c = sl + 1;
   break;
  case (('r')*256+('m')):

  case (('r')*256+('n')):




   {
    STRDEF *de;

    c = c + j;
    i = ((c[0])*256+(c[1]));
    c = c + 2;
    while (
          ((*__ctype_b_loc ())[(int) ((
          *c
          ))] & (unsigned short int) _ISspace) 
                      && *c != '\n')
     c++;
    j = ((c[0])*256+(c[1]));
    while (*c && *c != '\n')
     c++;
    c++;
    de = strdef;
    while (de && de->nr != j)
     de = de->next;
    if (de) {
     if (de->st)
      free(de->st);
     de->nr = 0;
    }
    de = strdef;
    while (de && de->nr != i)
     de = de->next;
    if (de)
     de->nr = j;
    break;
   }
  case (('n')*256+('x')):

  case (('i')*256+('n')):

   c = skip_till_newline(c);
   break;
  case (('n')*256+('r')):




   {
    INTDEF *intd;

    c = c + j;
    i = ((c[0])*256+(c[1]));
    c = c + 2;
    intd = intdef;
    while (intd && intd->nr != i)
     intd = intd->next;
    if (!intd) {
     intd = (INTDEF *) xmalloc(sizeof(INTDEF));
     intd->nr = i;
     intd->val = 0;
     intd->incr = 0;
     intd->next = intdef;
     intdef = intd;
    }
    while (*c == ' ' || *c == '\t')
     c++;
    c = scan_expression(c, &intd->val);
    if (*c != '\n') {
     while (*c == ' ' || *c == '\t')
      c++;
     c = scan_expression(c, &intd->incr);
    }
    c = skip_till_newline(c);
    break;
   }
  case (('a')*256+('m')):


   mode = 1;
  case (('d')*256+('e')):





   {
    STRDEF *de;
    int olen = 0;

    c = c + j;
    sl = fill_words(c, wordlist, &words);
    i = ((c[0])*256+(c[1]));
    j = 2;
    if (words == 1)
     wordlist[1] = "..";
    else {
     wordlist[1]--;
     wordlist[1][0] = '.';
     j = 3;
    }
    c = sl + 1;
    sl = c;
    while (*c && strncmp(c, wordlist[1], j))
     c = skip_till_newline(c);
    de = defdef;
    while (de && de->nr != i)
     de = de->next;
    if (mode && de)
     olen = strlen(de->st);
    j = olen + c - sl;
    h = stralloc(j * 2 + 4);
    if (h) {
     for (j = 0; j < olen; j++)
      h[j] = de->st[j];
     if (!j || h[j - 1] != '\n')
      h[j++] = '\n';
     while (sl != c) {
      if (sl[0] == '\\' && sl[1] == '\\') {
       h[j++] = '\\';
       sl++;
      } else
       h[j++] = *sl;
      sl++;
     }
     h[j] = '\0';
     if (de) {
      if (de->st)
       free(de->st);
      de->st = h;
     } else {
      de = (STRDEF *) xmalloc(sizeof(STRDEF));
      de->nr = i;
      de->next = defdef;
      de->st = h;
      defdef = de;
     }
    }
   }
   c = skip_till_newline(c);
   break;
  case (('B')*256+('l')):
   {
    char list_options[((500) + 1)];
    char *nl = strchr(c, '\n');

    c = c + j;
    if (dl_set[itemdepth]) {

     itemdepth++;
    }
    if (nl) {
     strlimitcpy(list_options, c, nl - c, 500);
    }
    if (strstr(list_options, "-bullet")) {
     dl_set[itemdepth] = 2;
     out_html("<UL>\n");
    } else if (strstr(list_options, "-enum")) {
     dl_set[itemdepth] = 4;
     out_html("<OL>\n");
    } else {
     dl_set[itemdepth] = 1;
     out_html("<DL COMPACT>\n");
    }
    if (fillout)
     out_html("<P>\n");
    else {
     out_html(NEWLINE);
     NEWLINE[0] = '\n';
    }
    curpos = 0;
    c = skip_till_newline(c);
    break;
   }
  case (('E')*256+('l')):
   c = c + j;
   if (dl_set[itemdepth] & 1) {
    out_html("</DL>\n");
   } else if (dl_set[itemdepth] & 2) {
    out_html("</UL>\n");
   } else if (dl_set[itemdepth] & 4) {
    out_html("</OL>\n");
   }
   dl_set[itemdepth] = 0;
   if (itemdepth > 0)
    itemdepth--;
   if (fillout)
    out_html("<P>\n");
   else {
    out_html(NEWLINE);
    NEWLINE[0] = '\n';
   }
   curpos = 0;
   c = skip_till_newline(c);
   break;
  case (('I')*256+('t')):
   c = c + j;
   if (strncmp(c, "Xo", 2) == 0 && 
                                  ((*__ctype_b_loc ())[(int) ((
                                  *(c + 2)
                                  ))] & (unsigned short int) _ISspace)
                                                   ) {
    c = skip_till_newline(c);
   }
   if (dl_set[itemdepth] & 1) {
    out_html("<DT>");
    out_html(change_to_font('B'));
    if (*c == '\n') {

     c++;
     c = scan_troff(c, 1, 
                         ((void *)0)
                             );
    } else {

     c = scan_troff_mandoc(c, 1, 
                                ((void *)0)
                                    );
    }
    out_html(change_to_font('R'));
    out_html(NEWLINE);
    out_html("<DD>");
   } else if (dl_set[itemdepth] & (2 | 4)) {
    out_html("<LI>");
    c = scan_troff_mandoc(c, 1, 
                               ((void *)0)
                                   );
    out_html(NEWLINE);
   }
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('B')*256+('k')):
  case (('E')*256+('k')):
  case (('D')*256+('d')):
  case (('O')*256+('s')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('B')*256+('t')):
   trans_char(c, '"', '\a');
   c = c + j;
   out_html(" is currently in beta test.");
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('B')*256+('x')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   out_html("BSD ");
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('D')*256+('l')):
   c = c + j;
   out_html(NEWLINE);
   out_html("<BLOCKQUOTE>");
   out_html(change_to_font('L'));
   if (*c == '\n')
    c++;
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(change_to_font('R'));
   out_html("</BLOCKQUOTE>");
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('B')*256+('d')):
   {
    char bd_options[((500) + 1)];
    char *nl = strchr(c, '\n');

    c = c + j;
    if (nl) {
     strlimitcpy(bd_options, c, nl - c, 500);
    }
    out_html(NEWLINE);
    mandoc_bd_options = 0;

    if (strstr(bd_options, "-offset indent")) {
     mandoc_bd_options |= 2;
     out_html("<BLOCKQUOTE>\n");
    }
    if (strstr(bd_options, "-literal")
        || strstr(bd_options, "-unfilled")) {
     if (fillout) {
      mandoc_bd_options |= 1;
      out_html(change_to_font(0));
      out_html(change_to_size('0'));
      out_html("<PRE>\n");
     }
     curpos = 0;
     fillout = 0;
    }
    c = skip_till_newline(c);
    break;
   }
  case (('E')*256+('d')):
   if (mandoc_bd_options & 1) {
    if (!fillout) {
     out_html(change_to_font(0));
     out_html(change_to_size('0'));
     out_html("</PRE>\n");
    }
   }
   if (mandoc_bd_options & 2)
    out_html("</BLOCKQUOTE>\n");
   curpos = 0;
   fillout = 1;
   c = skip_till_newline(c);
   break;
  case (('B')*256+('e')):
   c = c + j;
   if (fillout)
    out_html("<P>");
   else {
    out_html(NEWLINE);
    NEWLINE[0] = '\n';
   }
   curpos = 0;
   c = skip_till_newline(c);
   break;
  case (('X')*256+('r')):
   {





    char buff[((500) + 1)];
    char *bufptr;

    trans_char(c, '"', '\a');
    bufptr = buff;
    c = c + j;
    if (*c == '\n')
     c++;
    while (
          ((*__ctype_b_loc ())[(int) ((
          *c
          ))] & (unsigned short int) _ISspace) 
                      && *c != '\n')
     c++;
    while (
          ((*__ctype_b_loc ())[(int) ((
          *c
          ))] & (unsigned short int) _ISalnum)
                     ) {
     *bufptr = *c;
     bufptr++;
     if (bufptr >= buff + 500)
      break;
     c++;
    }
    while (
          ((*__ctype_b_loc ())[(int) ((
          *c
          ))] & (unsigned short int) _ISspace) 
                      && *c != '\n')
     c++;
    if (
       ((*__ctype_b_loc ())[(int) ((
       *c
       ))] & (unsigned short int) _ISdigit)
                  ) {

     *bufptr = '(';
     bufptr++;
     if (bufptr < buff + 500) {
      while (
            ((*__ctype_b_loc ())[(int) ((
            *c
            ))] & (unsigned short int) _ISalnum)
                       ) {
       *bufptr = *c;
       bufptr++;
       if (bufptr >= buff + 500)
        break;
       c++;
      }
      if (bufptr < buff + 500) {
       *bufptr = ')';
       bufptr++;
      }
     }
    }
    while (*c != '\n') {
     if (!
         ((*__ctype_b_loc ())[(int) ((
         *c
         ))] & (unsigned short int) _ISspace)
                    ) {
      *bufptr = *c;
      bufptr++;
      if (bufptr >= buff + 500)
       break;
     }
     c++;
    }
    *bufptr = '\n';
    scan_troff_mandoc(buff, 1, 
                              ((void *)0)
                                  );

    out_html(NEWLINE);
    if (fillout)
     curpos++;
    else
     curpos = 0;
   }
   break;
  case (('F')*256+('l')):
   trans_char(c, '"', '\a');
   c = c + j;
   out_html("-");
   if (*c != '\n') {
    out_html(change_to_font('B'));
    c = scan_troff_mandoc(c, 1, 
                               ((void *)0)
                                   );
    out_html(change_to_font('R'));
   }
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('P')*256+('a')):
  case (('P')*256+('f')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('P')*256+('p')):
   if (fillout)
    out_html("<P>\n");
   else {
    out_html(NEWLINE);
    NEWLINE[0] = '\n';
   }
   curpos = 0;
   c = skip_till_newline(c);
   break;
  case (('D')*256+('q')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   out_html("``");
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html("''");
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('O')*256+('p')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   out_html(change_to_font('R'));
   out_html("[");
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(change_to_font('R'));
   out_html("]");
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('O')*256+('o')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   out_html(change_to_font('R'));
   out_html("[");
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('O')*256+('c')):
   trans_char(c, '"', '\a');
   c = c + j;
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(change_to_font('R'));
   out_html("]");
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('P')*256+('q')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   out_html("(");
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(")");
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('Q')*256+('l')):
   {
    char *sp;

    trans_char(c, '"', '\a');
    c = c + j;
    if (*c == '\n')
     c++;
    sp = c;
    do {


     while (*sp && 
                  ((*__ctype_b_loc ())[(int) ((
                  *sp
                  ))] & (unsigned short int) _ISspace)
                              )
      sp++;
     while (*sp && !
                   ((*__ctype_b_loc ())[(int) ((
                   *sp
                   ))] & (unsigned short int) _ISspace)
                               )
      sp++;
    } while (*sp && 
                   ((*__ctype_b_loc ())[(int) ((
                   *(sp - 2)
                   ))] & (unsigned short int) _ISupper) 
                                      && 
                                         ((*__ctype_b_loc ())[(int) ((
                                         *(sp - 1)
                                         ))] & (unsigned short int) _ISlower)
                                                           );





    if (*sp)
     *sp = '\n';
    out_html("`");
    c = scan_troff_mandoc(c, 1, 
                               ((void *)0)
                                   );
    out_html("'");
    out_html(NEWLINE);
    if (fillout)
     curpos++;
    else
     curpos = 0;
    break;
   }
  case (('S')*256+('q')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   out_html("`");
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html("'");
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('A')*256+('r')):

   out_html(change_to_font('I'));
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n') {

    out_html("file ...");
   } else {
    c = scan_troff_mandoc(c, 1, 
                               ((void *)0)
                                   );
   }
   out_html(change_to_font('R'));
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('A')*256+('d')):
  case (('E')*256+('m')):
  case (('V')*256+('a')):
  case (('X')*256+('c')):

   out_html(change_to_font('I'));
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(change_to_font('R'));
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('N')*256+('d')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   out_html(" - ");
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('N')*256+('m')):
   {
    static char mandoc_name[((100) + 1)] = "";

    trans_char(c, '"', '\a');
    c = c + j;
    if (mandoc_synopsis) {





     static int count = 0;


     if (count) {
      out_html("<BR>");
     } else {
      char *end = strchr(c, '\n');

      if (end) {

       strlimitcpy(mandoc_name, c, end - c, 100);
      }
     }
     count++;
    }
    out_html(change_to_font('B'));
    while (*c == ' ' || *c == '\t')
     c++;
    if (*c == '\n') {







     out_html(mandoc_name);
    } else {
     c = scan_troff_mandoc(c, 1, 
                                ((void *)0)
                                    );
    }
    out_html(change_to_font('R'));
    out_html(NEWLINE);
    if (fillout)
     curpos++;
    else
     curpos = 0;
    break;
   }
  case (('C')*256+('d')):
  case (('C')*256+('m')):
  case (('I')*256+('c')):
  case (('M')*256+('s')):
  case (('O')*256+('r')):
  case (('S')*256+('y')):

   out_html(change_to_font('B'));
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(change_to_font('R'));
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('D')*256+('v')):
  case (('E')*256+('v')):
  case (('F')*256+('r')):
  case (('L')*256+('i')):
  case (('N')*256+('o')):
  case (('N')*256+('s')):
  case (('T')*256+('n')):
  case (('n')*256+('N')):
   trans_char(c, '"', '\a');
   c = c + j;
   if (*c == '\n')
    c++;
   out_html(change_to_font('B'));
   c = scan_troff_mandoc(c, 1, 
                              ((void *)0)
                                  );
   out_html(change_to_font('R'));
   out_html(NEWLINE);
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('%')*256+('A')):
  case (('%')*256+('D')):
  case (('%')*256+('N')):
  case (('%')*256+('O')):
  case (('%')*256+('P')):
  case (('%')*256+('Q')):
  case (('%')*256+('V')):
   c = c + j;
   if (*c == '\n')
    c++;
   c = scan_troff(c, 1, 
                       ((void *)0)
                           );

   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  case (('%')*256+('B')):
  case (('%')*256+('J')):
  case (('%')*256+('R')):
  case (('%')*256+('T')):
   c = c + j;
   out_html(change_to_font('I'));
   if (*c == '\n')
    c++;
   c = scan_troff(c, 1, 
                       ((void *)0)
                           );

   out_html(change_to_font('R'));
   if (fillout)
    curpos++;
   else
    curpos = 0;
   break;
  default:

   owndef = defdef;
   while (owndef && owndef->nr != i)
    owndef = owndef->next;
   if (owndef) {
    char **oldargument;
    int deflen;
    int onff;

    sl = fill_words(c + j, wordlist, &words);
    c = sl + 1;
    *sl = '\0';
    for (i = 1; i < words; i++)
     wordlist[i][-1] = '\0';
    for (i = 0; i < words; i++) {
     char *h = 
                ((void *)0)
                    ;

     if (mandoc_command) {
      scan_troff_mandoc(wordlist[i], 1, &h);
     } else {
      scan_troff(wordlist[i], 1, &h);
     }
     wordlist[i] = h;
    }
    for (i = words; i < 20; i++)
     wordlist[i] = 
                  ((void *)0)
                      ;
    deflen = strlen(owndef->st);
    for (i = 0; owndef->st[deflen + 2 + i] = owndef->st[i]; i++);
    oldargument = argument;
    argument = wordlist;
    onff = newline_for_fun;
    if (mandoc_command) {
     scan_troff_mandoc(owndef->st + deflen + 2, 0, 
                                                  ((void *)0)
                                                      );
    } else {
     scan_troff(owndef->st + deflen + 2, 0, 
                                           ((void *)0)
                                               );
    }
    newline_for_fun = onff;
    argument = oldargument;
    for (i = 0; i < words; i++)
     if (wordlist[i])
      free(wordlist[i]);
    *sl = '\n';
   } else if (mandoc_command &&
       ((
        ((*__ctype_b_loc ())[(int) ((
        *c
        ))] & (unsigned short int) _ISupper) 
                    && 
                       ((*__ctype_b_loc ())[(int) ((
                       *(c + 1)
                       ))] & (unsigned short int) _ISlower)
                                        )
        || (
           ((*__ctype_b_loc ())[(int) ((
           *c
           ))] & (unsigned short int) _ISlower) 
                       && 
                          ((*__ctype_b_loc ())[(int) ((
                          *(c + 1)
                          ))] & (unsigned short int) _ISupper)
                                           ))
    ) {



    char buf[4];

    strncpy(buf, c, 2);
    buf[2] = ' ';
    buf[3] = '\0';
    out_html(buf);

    c = c + j;
    trans_char(c, '"', '\a');
    if (*c == '\n')
     c++;
    out_html(change_to_font('R'));
    c = scan_troff(c, 1, 
                        ((void *)0)
                            );
    out_html(NEWLINE);
    if (fillout)
     curpos++;
    else
     curpos = 0;
   } else {
    c = skip_till_newline(c);
   }
   break;
  }
 }
 if (fillout) {
  out_html(NEWLINE);
  curpos++;
 }
 NEWLINE[0] = '\n';
 return c;
}

static void
flush(void)
{
}

static int contained_tab = 0;
static int mandoc_line = 0;



static char *
scan_troff(char *c, int san, char **result)
{
 char *h;
 char intbuff[((500) + 1)];
 int ibp = 0;
 int i;
 char *exbuffer;
 int exbuffpos, exbuffmax, exscaninbuff, exnewline_for_fun;
 int usenbsp = 0;



 exbuffer = buffer;
 exbuffpos = buffpos;
 exbuffmax = buffmax;
 exnewline_for_fun = newline_for_fun;
 exscaninbuff = scaninbuff;
 newline_for_fun = 0;
 if (result) {
  if (*result) {
   buffer = *result;
   buffpos = strlen(buffer);
   buffmax = buffpos;
  } else {
   buffer = stralloc(2000);
   buffpos = 0;
   buffmax = 2000;
  }
  scaninbuff = 1;
 }
 h = c;


 while (*h && (!san || newline_for_fun || *h != '\n')) {

  if (*h == escapesym) {
   h++;
   if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };
   h = scan_escape(h);
  } else if (*h == controlsym && h[-1] == '\n') {
   h++;
   if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };
   h = scan_request(h);
   if (san && h[-1] == '\n')
    h--;
  } else if (mandoc_line
      && *(h) && 
                ((*__ctype_b_loc ())[(int) ((
                *(h)
                ))] & (unsigned short int) _ISupper)
      
     && *(h + 1) && 
                    ((*__ctype_b_loc ())[(int) ((
                    *(h + 1)
                    ))] & (unsigned short int) _ISlower)
      
     && *(h + 2) && 
                    ((*__ctype_b_loc ())[(int) ((
                    *(h + 2)
                    ))] & (unsigned short int) _ISspace)
                                     ) {




   if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };
   h = scan_request(h);
   if (san && h[-1] == '\n')
    h--;
  } else if (*h == nobreaksym && h[-1] == '\n') {
   h++;
   if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };
   h = scan_request(h);
   if (san && h[-1] == '\n')
    h--;
  } else {
   int mx;

   if (h[-1] == '\n' && still_dd && 
                                   ((*__ctype_b_loc ())[(int) ((
                                   *h
                                   ))] & (unsigned short int) _ISalnum)
                                              ) {




    if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };
    out_html("<DD>");
    curpos = 0;
    still_dd = 0;
   }
   switch (*h) {
   case '&':
    intbuff[ibp++] = '&';
    intbuff[ibp++] = 'a';
    intbuff[ibp++] = 'm';
    intbuff[ibp++] = 'p';
    intbuff[ibp++] = ';';
    curpos++;
    break;
   case '<':
    intbuff[ibp++] = '&';
    intbuff[ibp++] = 'l';
    intbuff[ibp++] = 't';
    intbuff[ibp++] = ';';
    curpos++;
    break;
   case '>':
    intbuff[ibp++] = '&';
    intbuff[ibp++] = 'g';
    intbuff[ibp++] = 't';
    intbuff[ibp++] = ';';
    curpos++;
    break;
   case '"':
    intbuff[ibp++] = '&';
    intbuff[ibp++] = 'q';
    intbuff[ibp++] = 'u';
    intbuff[ibp++] = 'o';
    intbuff[ibp++] = 't';
    intbuff[ibp++] = ';';
    curpos++;
    break;
   case '\n':
    if (h[-1] == '\n' && fillout) {
     intbuff[ibp++] = '<';
     intbuff[ibp++] = 'P';
     intbuff[ibp++] = '>';
    }
    if (contained_tab && fillout) {
     intbuff[ibp++] = '<';
     intbuff[ibp++] = 'B';
     intbuff[ibp++] = 'R';
     intbuff[ibp++] = '>';
    }
    contained_tab = 0;
    curpos = 0;
    usenbsp = 0;
    intbuff[ibp++] = '\n';
    break;
   case '\t':
    {
     int curtab = 0;

     contained_tab = 1;
     if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };

     tabstops[19] = curpos + 1;
     while (curtab < maxtstop && tabstops[curtab] <= curpos)
      curtab++;
     if (curtab < maxtstop) {
      if (!fillout) {
       while (curpos < tabstops[curtab]) {
        intbuff[ibp++] = ' ';
        if (ibp > 480) {
         if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };
        }
        curpos++;
       }
      } else {
       out_html("<TT>");
       while (curpos < tabstops[curtab]) {
        out_html("&nbsp;");
        curpos++;
       }
       out_html("</TT>");
      }
     }
    }
    break;
   default:
    if (*h == ' ' && (h[-1] == '\n' || usenbsp)) {
     if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };
     if (!usenbsp && fillout) {
      out_html("<BR>");
      curpos = 0;
     }
     usenbsp = fillout;
     if (usenbsp)
      out_html("&nbsp;");
     else
      intbuff[ibp++] = ' ';
    } else if (*h > 31 && *h < 127)
     intbuff[ibp++] = *h;
    else if (((unsigned char) (*h)) > 127) {
     intbuff[ibp++] = '&';
     intbuff[ibp++] = '#';
     intbuff[ibp++] = '0' + ((unsigned char) (*h)) / 100;
     intbuff[ibp++] = '0' + (((unsigned char) (*h)) % 100) / 10;
     intbuff[ibp++] = '0' + ((unsigned char) (*h)) % 10;
     intbuff[ibp++] = ';';
    }
    curpos++;
    break;
   }
   if (ibp > (500 - 20))
    if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };
   h++;
  }
 }
 if (ibp) { intbuff[ibp]=0; out_html(intbuff); ibp=0; };
 if (buffer)
  buffer[buffpos] = '\0';
 if (san && *h)
  h++;
 newline_for_fun = exnewline_for_fun;
 if (result) {
  *result = buffer;
  buffer = exbuffer;
  buffpos = exbuffpos;
  buffmax = exbuffmax;
  scaninbuff = exscaninbuff;
 }
 return h;
}


static char *
scan_troff_mandoc(char *c, int san, char **result)
{
 char *ret, *end = c;
 int oldval = mandoc_line;

 mandoc_line = 1;
 while (*end && *end != '\n') {
  end++;
 }

 if (end > c + 2
     && 
       ((*__ctype_b_loc ())[(int) ((
       *(end - 1)
       ))] & (unsigned short int) _ISpunct)
     
    && 
       ((*__ctype_b_loc ())[(int) ((
       *(end - 2)
       ))] & (unsigned short int) _ISspace) 
                           && *(end - 2) != '\n') {




  *(end - 2) = '\n';
  ret = scan_troff(c, san, result);
  *(end - 2) = *(end - 1);
  *(end - 1) = ' ';
 } else {
  ret = scan_troff(c, san, result);
 }
 mandoc_line = oldval;
 return ret;
}

int
main(int argc, char **argv)
{
 FILE *f;
 char *t;
 int l, i;
 char *buf;
 char *h, *fullname;
 STRDEF *stdf;

 t = 
    ((void *)0)
        ;
 while ((i = getopt(argc, argv, "")) != 
                                       (-1)
                                          ) {
  switch (i) {
  default:
   usage();
   exit(2);
  }
 }

 if (argc != 2) {
  usage();
  exit(2);
 }
 manpage = h = t = argv[1];
 i = 0;

 buf = read_man_page(h);
 if (!buf) {
  fprintf(
         stderr
               , "man2html: cannot read %s: %s\n", h, strerror(
                                                               (*__errno_location ())
                                                                    ));
  exit(1);
 }



 stdf = &standardchar[0];
 i = 0;
 while (stdf->nr) {
  stdf->next = &standardchar[i];
  stdf = stdf->next;
  i++;
 }
 chardef = &standardchar[0];

 stdf = &standardstring[0];
 i = 0;
 while (stdf->nr) {
  stdf->next = &standardstring[i];
  stdf = stdf->next;
  i++;
 }
 strdef = &standardstring[0];

 intdef = &standardint[0];
 i = 0;
 while (intdef->nr) {
  intdef->next = &standardint[i];
  intdef = intdef->next;
  i++;
 }
 intdef = &standardint[0];

 defdef = 
         ((void *)0)
             ;

 scan_troff(buf + 1, 0, 
                       ((void *)0)
                           );

 while (itemdepth || dl_set[itemdepth]) {
  out_html("</DL>\n");
  if (dl_set[itemdepth])
   dl_set[itemdepth] = 0;
  else if (itemdepth > 0)
   itemdepth--;
 }

 out_html(change_to_font(0));
 out_html(change_to_size(0));
 if (!fillout) {
  fillout = 1;
  out_html("</PRE>");
 }
 out_html(NEWLINE);

 if (output_possible) {
  outputPageFooter(th_version, th_datestr, th_page_and_sec);

  fputs("<HR>\n<A NAME=\"index\">&nbsp;</A><H2>Index</H2>\n<DL>\n", 
                                                                   stdout
                                                                         );
  manidx[mip] = 0;
  fputs(manidx, 
               stdout
                     );
  if (subs)
   fputs("</DL>\n", 
                   stdout
                         );
  fputs("</DL>\n", 
                  stdout
                        );
  print_sig();
  fputs("</BODY>\n</HTML>\n", 
                             stdout
                                   );
 } else
  fprintf(
         stderr
               , "man2html: no output produced\n");




 exit(
     0
                 );
}
