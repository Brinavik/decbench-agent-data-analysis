


       












       
       
       
extern int _gl_cxxalias_dummy

                                      ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                             ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                       ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                            ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy


                                          ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                     ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                           ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                              ;


extern int _gl_cxxalias_dummy;





struct danetool_list
{
  const char **args;
  unsigned int count;
};

struct danetool_options
{

  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        verbose;
    
   _Bool 
        outfile;
    
   _Bool 
        load_pubkey;
    
   _Bool 
        load_certificate;
    
   _Bool 
        dlv;
    
   _Bool 
        hash;
    
   _Bool 
        check;
    
   _Bool 
        check_ee;
    
   _Bool 
        check_ca;
    
   _Bool 
        tlsa_rr;
    
   _Bool 
        host;
    
   _Bool 
        proto;
    
   _Bool 
        port;
    
   _Bool 
        starttls_proto;
    
   _Bool 
        ca;
    
   _Bool 
        x509;
    
   _Bool 
        domain;
    
   _Bool 
        local_dns;
    
   _Bool 
        insecure;
    
   _Bool 
        inder;
    
   _Bool 
        print_raw;
    
   _Bool 
        quiet;
    
   _Bool 
        version;
    
   _Bool 
        help;
    
   _Bool 
        more_help;
  } present;


  struct
  {
    const char *debug;
    const char *outfile;
    const char *load_pubkey;
    const char *load_certificate;
    const char *dlv;
    const char *hash;
    const char *check;
    const char *host;
    const char *proto;
    const char *port;
    const char *starttls_proto;
    const char *version;
  } arg;


  struct
  {
    int debug;
  } value;


  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        verbose;
    
   _Bool 
        outfile;
    
   _Bool 
        load_pubkey;
    
   _Bool 
        load_certificate;
    
   _Bool 
        dlv;
    
   _Bool 
        hash;
    
   _Bool 
        check;
    
   _Bool 
        check_ee;
    
   _Bool 
        check_ca;
    
   _Bool 
        tlsa_rr;
    
   _Bool 
        host;
    
   _Bool 
        proto;
    
   _Bool 
        port;
    
   _Bool 
        starttls_proto;
    
   _Bool 
        ca;
    
   _Bool 
        x509;
    
   _Bool 
        domain;
    
   _Bool 
        local_dns;
    
   _Bool 
        insecure;
    
   _Bool 
        inder;
    
   _Bool 
        print_raw;
    
   _Bool 
        quiet;
    
   _Bool 
        version;
    
   _Bool 
        help;
    
   _Bool 
        more_help;
  } enabled;
};
extern struct danetool_options danetool_options;
int process_options (int argc, char **argv);
void usage (FILE *out, int status);
       

extern void error (int __status, int __errnum, const char *__format, ...)



     __attribute__ ((__format__ (
    __printf__
    , 3, 4)))

     ;

extern void error_at_line (int __status, int __errnum, const char *__fname,
                           unsigned int __lineno, const char *__format, ...)



     __attribute__ ((__format__ (
    __printf__
    , 5, 6)))

     ;




extern void (*error_print_progname) (void);


extern unsigned int error_message_count;



extern int error_one_per_line;
       
       
       
       





extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                         ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                     ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
       
       







extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                 ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                             ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                          ;
extern int _gl_cxxalias_dummy

                                                              ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                     ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                             ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

       
       

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                               ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                               ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;




       


struct danetool_options danetool_options;

static long
parse_number (const char *arg)
{
  char *endptr = 
                ((void *)0)
                    ;
  
 (*__errno_location ()) 
       = 0;
  long result;

  if (strncmp (arg, "0x", 2) == 0)
    result = strtol (arg + 2, &endptr, 16);
  else if (strncmp (arg, "0", 1) == 0
           && strspn (arg, "012345678") == strlen (optarg))
    result = strtol (arg + 1, &endptr, 8);
  else
    result = strtol (arg, &endptr, 10);

  if (
     (*__errno_location ()) 
           != 0 || (endptr && *endptr != '\0'))
    error (
          1
                      , 
                        (*__errno_location ())
                             , "'%s' is not a recognizable number.",
           arg);

  return result;
}


static const struct option long_options[] =
{
  { "debug", 
            1
                             , 0, 'd' },
  { "verbose", 
              0
                         , 0, 'V' },
  { "outfile", 
              1
                               , 0, 0x7f + 1 },
  { "load-pubkey", 
                  1
                                   , 0, 0x7f + 2 },
  { "load-certificate", 
                       1
                                        , 0, 0x7f + 3 },
  { "dlv", 
          1
                           , 0, 0x7f + 4 },
  { "hash", 
           1
                            , 0, 0x7f + 5 },
  { "check", 
            1
                             , 0, 0x7f + 6 },
  { "check-ee", 
               0
                          , 0, 0x7f + 7 },
  { "check-ca", 
               0
                          , 0, 0x7f + 8 },
  { "tlsa-rr", 
              0
                         , 0, 0x7f + 9 },
  { "host", 
           1
                            , 0, 0x7f + 10 },
  { "proto", 
            1
                             , 0, 0x7f + 11 },
  { "port", 
           1
                            , 0, 0x7f + 12 },
  { "starttls-proto", 
                     1
                                      , 0, 0x7f + 14 },
  { "app-proto", 
                1
                                 , 0, 0x7f + 13 },
  { "ca", 
         0
                    , 0, 0x7f + 15 },
  { "x509", 
           0
                      , 0, 0x7f + 16 },
  { "domain", 
             0
                        , 0, 0x7f + 18 },
  { "local", 
            0
                       , 0, 0x7f + 17 },
  { "no-domain", 
                0
                           , 0, 0x7f + 19 },
  { "local-dns", 
                0
                           , 0, 0x7f + 20 },
  { "no-local-dns", 
                   0
                              , 0, 0x7f + 21 },
  { "insecure", 
               0
                          , 0, 0x7f + 22 },
  { "inder", 
            0
                       , 0, 0x7f + 23 },
  { "inraw", 
            0
                       , 0, 0x7f + 25 },
  { "no-inder", 
               0
                          , 0, 0x7f + 24 },
  { "print-raw", 
                0
                           , 0, 0x7f + 26 },
  { "no-print-raw", 
                   0
                              , 0, 0x7f + 27 },
  { "quiet", 
            0
                       , 0, 0x7f + 28 },
  { "version", 
              2
                               , 0, 'v' },
  { "help", 
           0
                      , 0, 'h' },
  { "more-help", 
                0
                           , 0, '!' },
  { 0, 0, 0, 0 }

};

int
process_options (int argc, char **argv)
{
  struct danetool_options *opts = &danetool_options;
  int opt;

  opts->enabled.domain = 
                        1
                            ;
  while ((opt = getopt_long (argc, argv, "!Vd:hv:",
                             long_options, 
                                          ((void *)0)
                                              )) != 
                                                    (-1)
                                                       )
    switch (opt)
      {
      case '\0':
        break;
      case 'd':
        opts->present.debug = 
                             1
                                 ;
        opts->arg.debug = optarg;
        opts->value.debug = parse_number(optarg);
        opts->enabled.debug = 
                             1
                                 ;
        break;
      case 'V':
        opts->present.verbose = 
                               1
                                   ;
        opts->enabled.verbose = 
                               1
                                   ;
        break;
      case 0x7f + 1:
        opts->present.outfile = 
                               1
                                   ;
        opts->arg.outfile = optarg;
        opts->enabled.outfile = 
                               1
                                   ;
        break;
      case 0x7f + 2:
        opts->present.load_pubkey = 
                                   1
                                       ;
        opts->arg.load_pubkey = optarg;
        opts->enabled.load_pubkey = 
                                   1
                                       ;
        break;
      case 0x7f + 3:
        opts->present.load_certificate = 
                                        1
                                            ;
        opts->arg.load_certificate = optarg;
        opts->enabled.load_certificate = 
                                        1
                                            ;
        break;
      case 0x7f + 4:
        opts->present.dlv = 
                           1
                               ;
        opts->arg.dlv = optarg;
        opts->enabled.dlv = 
                           1
                               ;
        break;
      case 0x7f + 5:
        opts->present.hash = 
                            1
                                ;
        opts->arg.hash = optarg;
        opts->enabled.hash = 
                            1
                                ;
        break;
      case 0x7f + 6:
        opts->present.check = 
                             1
                                 ;
        opts->arg.check = optarg;
        opts->enabled.check = 
                             1
                                 ;
        break;
      case 0x7f + 7:
        opts->present.check_ee = 
                                1
                                    ;
        opts->enabled.check_ee = 
                                1
                                    ;
        break;
      case 0x7f + 8:
        opts->present.check_ca = 
                                1
                                    ;
        opts->enabled.check_ca = 
                                1
                                    ;
        break;
      case 0x7f + 9:
        opts->present.tlsa_rr = 
                               1
                                   ;
        opts->enabled.tlsa_rr = 
                               1
                                   ;
        break;
      case 0x7f + 10:
        opts->present.host = 
                            1
                                ;
        opts->arg.host = optarg;
        opts->enabled.host = 
                            1
                                ;
        break;
      case 0x7f + 11:
        opts->present.proto = 
                             1
                                 ;
        opts->arg.proto = optarg;
        opts->enabled.proto = 
                             1
                                 ;
        break;
      case 0x7f + 12:
        opts->present.port = 
                            1
                                ;
        opts->arg.port = optarg;
        opts->enabled.port = 
                            1
                                ;
        break;
      case 0x7f + 14:
      case 0x7f + 13:
        opts->present.starttls_proto = 
                                      1
                                          ;
        opts->arg.starttls_proto = optarg;
        opts->enabled.starttls_proto = 
                                      1
                                          ;
        break;
      case 0x7f + 15:
        opts->present.ca = 
                          1
                              ;
        opts->enabled.ca = 
                          1
                              ;
        break;
      case 0x7f + 16:
        opts->present.x509 = 
                            1
                                ;
        opts->enabled.x509 = 
                            1
                                ;
        break;
      case 0x7f + 18:
      case 0x7f + 17:
        opts->present.domain = 
                              1
                                  ;
        opts->enabled.domain = 
                              1
                                  ;
        break;
      case 0x7f + 19:
        opts->present.domain = 
                              1
                                  ;
        opts->enabled.domain = 
                              0
                                   ;
        break;
      case 0x7f + 20:
        opts->present.local_dns = 
                                 1
                                     ;
        opts->enabled.local_dns = 
                                 1
                                     ;
        break;
      case 0x7f + 21:
        opts->present.local_dns = 
                                 1
                                     ;
        opts->enabled.local_dns = 
                                 0
                                      ;
        break;
      case 0x7f + 22:
        opts->present.insecure = 
                                1
                                    ;
        opts->enabled.insecure = 
                                1
                                    ;
        break;
      case 0x7f + 23:
      case 0x7f + 25:
        opts->present.inder = 
                             1
                                 ;
        opts->enabled.inder = 
                             1
                                 ;
        break;
      case 0x7f + 24:
        opts->present.inder = 
                             1
                                 ;
        opts->enabled.inder = 
                             0
                                  ;
        break;
      case 0x7f + 26:
        opts->present.print_raw = 
                                 1
                                     ;
        opts->enabled.print_raw = 
                                 1
                                     ;
        break;
      case 0x7f + 27:
        opts->present.print_raw = 
                                 1
                                     ;
        opts->enabled.print_raw = 
                                 0
                                      ;
        break;
      case 0x7f + 28:
        opts->present.quiet = 
                             1
                                 ;
        opts->enabled.quiet = 
                             1
                                 ;
        break;
      case 'v':
        opts->present.version = 
                               1
                                   ;
        opts->arg.version = optarg;
        opts->enabled.version = 
                               1
                                   ;
        break;
      case 'h':
        opts->present.help = 
                            1
                                ;
        opts->enabled.help = 
                            1
                                ;
        break;
      case '!':
        opts->present.more_help = 
                                 1
                                     ;
        opts->enabled.more_help = 
                                 1
                                     ;
        break;
      default:
        usage (
              stderr
                    , 
                      1
                                  );
        break;
      }

  if (danetool_options.present.debug && danetool_options.value.debug < 0)
    {
      error (
            1
                        , 0, "%s option value %d is out of range.",
             "debug", opts->value.debug);
    }
  if (danetool_options.present.debug && danetool_options.value.debug > 9999)
    {
      error (
            1
                        , 0, "%s option value %d is out of range",
             "debug", opts->value.debug);
    }
  if (danetool_options.present.tlsa_rr && !danetool_options.present.host)
    {
      error (
            1
                        , 0, "%s option requires the %s options",
             "tlsa-rr", "host");
    }
  if (optind < argc)
    {
      error (
            1
                        , 0, "Command line arguments are not allowed.");
    }


  if (danetool_options.present.help)
    {
      usage (
     stdout
     , (0));
    }

  if (danetool_options.present.more_help)





    {
      pid_t pid;
      int pfds[2];

      if (pipe (pfds) < 0)
        error (
              1
                          , 
                            (*__errno_location ())
                                 , "pipe");

      pid = fork ();
      if (pid < 0)
        error (
              1
                          , 
                            (*__errno_location ())
                                 , "fork");

      if (pid == 0)
        {
          close (pfds[0]);
          dup2 (pfds[1], 
                        1
                                     );
          close (pfds[1]);

          usage (
                stdout
                      , 0);
        }
      else
        {
          const char *args[2];
          const char *envvar;

          close (pfds[1]);
          dup2 (pfds[0], 
                        0
                                    );
          close (pfds[0]);

          envvar = secure_getenv ("PAGER");
          if (!envvar || *envvar == '\0')
            args[0] = "more";
          else
            args[0] = envvar;

          args[1] = 
                   ((void *)0)
                       ;

          execvp (args[0], (char * const *)args);

          exit (
               1
                           );
        }
    }


  if (danetool_options.present.version)
    {
      if (!danetool_options.arg.version || !strcmp (danetool_options.arg.version, "c"))
        {
          const char str[] =
            "danetool 3.7.8\n"
            "Copyright (C) 2000-2021 Free Software Foundation, and others\n"
            "This is free software. It is licensed for use, modification and\n"
            "redistribution under the terms of the GNU General Public License,\n"
            "version 3 or later <http://gnu.org/licenses/gpl.html>\n"
            "\n"
            "Please send bug reports to:  <bugs@gnutls.org>            \n";
          fprintf (
                  stdout
                        , "%s", str);
          exit(0);
        }
      else if (!strcmp (danetool_options.arg.version, "v"))
        {
          const char str[] =
            "danetool 3.7.8\n";
          fprintf (
                  stdout
                        , "%s", str);
          exit(0);
        }
      else if (!strcmp (danetool_options.arg.version, "n"))
        {
          const char str[] =
            "danetool 3.7.8\n"
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
            "Please send bug reports to:  <bugs@gnutls.org>            \n";
          fprintf (
                  stdout
                        , "%s", str);
          exit(0);
        }
      else
        {
          error (
                1
                            , 0,
                 "version option argument 'a' invalid.  Use:\n"
                 "	'v' - version only\n"
                 "	'c' - version and copyright\n"
                 "	'n' - version and full copyright notice");
        }
    }

  return optind;
}

void
usage (FILE *out, int status)
{
  const char str[] =
    "danetool - GnuTLS DANE tool\n"
    "Usage:  danetool [ -<flag> [<val>] | --<name>[{=| }<val>] ]... \n"
    "\n"
    "None:\n"
    "\n"
    "   -d, --debug=num            Enable debugging\n"
    "				- it must be in the range:\n"
    "				  0 to 9999\n"
    "   -V, --verbose              More verbose output\n"
    "       --outfile=str          Output file\n"
    "       --load-pubkey=str      Loads a public key file\n"
    "       --load-certificate=str Loads a certificate file\n"
    "       --dlv=str              Sets a DLV file\n"
    "       --hash=str             Hash algorithm to use for signing\n"
    "       --check=str            Check a host's DANE TLSA entry\n"
    "       --check-ee             Check only the end-entity's certificate\n"
    "       --check-ca             Check only the CA's certificate\n"
    "       --tlsa-rr              Print the DANE RR data on a certificate or public key\n"
    "				- requires the option 'host'\n"
    "       --host=str             Specify the hostname to be used in the DANE RR\n"
    "       --proto=str            The protocol set for DANE data (tcp, udp etc.)\n"
    "       --port=str             The port or service to connect to, for DANE data\n"
    "       --app-proto            an alias for the 'starttls-proto' option\n"
    "       --starttls-proto=str   The application protocol to be used to obtain the server's certificate (https, ftp, smtp, imap, ldap, xmpp, lmtp, pop3, nntp, sieve, postgres)\n"
    "       --ca                   Whether the provided certificate or public key is a Certificate Authority\n"
    "       --x509                 Use the hash of the X.509 certificate, rather than the public key\n"
    "       --local                an alias for the 'domain' option\n"
    "       --domain               The provided certificate or public key is issued by the local domain\n"
    "				- enabled by default\n"
    "				- disabled as '--no-domain'\n"
    "       --local-dns            Use the local DNS server for DNSSEC resolving\n"
    "       --insecure             Do not verify any DNSSEC signature\n"
    "       --inder                Use DER format for input certificates and private keys\n"
    "       --inraw                an alias for the 'inder' option\n"
    "       --print-raw            Print the received DANE data in raw format\n"
    "       --quiet                Suppress several informational messages\n"
    "\n"
    "Version, usage and configuration options:\n"
    "\n"
    "   -v, --version[=arg]        output version information and exit\n"
    "   -h, --help                 display extended usage information and exit\n"
    "   -!, --more-help            extended usage information passed thru pager\n"
    "\n"
    "Options are specified by doubled hyphens and their name or by a single\n"
    "hyphen and the flag character.\n"
    "\n"
    "Tool to generate and check DNS resource records for the DANE protocol.\n"
    "\n"
    "Please send bug reports to:  <bugs@gnutls.org>\n"
    "\n";
  fprintf (out, "%s", str);
  exit (status);
}
