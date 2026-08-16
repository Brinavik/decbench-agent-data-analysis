


       












       
       
       
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





struct ocsptool_list
{
  const char **args;
  unsigned int count;
};

struct ocsptool_options
{

  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        verbose;
    
   _Bool 
        infile;
    
   _Bool 
        outfile;
    
   _Bool 
        ask;
    
   _Bool 
        verify_response;
    
   _Bool 
        request_info;
    
   _Bool 
        response_info;
    
   _Bool 
        generate_request;
    
   _Bool 
        nonce;
    
   _Bool 
        load_chain;
    
   _Bool 
        load_issuer;
    
   _Bool 
        load_cert;
    
   _Bool 
        load_trust;
    
   _Bool 
        load_signer;
    
   _Bool 
        inder;
    
   _Bool 
        outder;
    
   _Bool 
        outpem;
    
   _Bool 
        load_request;
    
   _Bool 
        load_response;
    
   _Bool 
        ignore_errors;
    
   _Bool 
        verify_allow_broken;
    
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
    const char *infile;
    const char *outfile;
    const char *ask;
    const char *load_chain;
    const char *load_issuer;
    const char *load_cert;
    const char *load_trust;
    const char *load_signer;
    const char *load_request;
    const char *load_response;
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
        infile;
    
   _Bool 
        outfile;
    
   _Bool 
        ask;
    
   _Bool 
        verify_response;
    
   _Bool 
        request_info;
    
   _Bool 
        response_info;
    
   _Bool 
        generate_request;
    
   _Bool 
        nonce;
    
   _Bool 
        load_chain;
    
   _Bool 
        load_issuer;
    
   _Bool 
        load_cert;
    
   _Bool 
        load_trust;
    
   _Bool 
        load_signer;
    
   _Bool 
        inder;
    
   _Bool 
        outder;
    
   _Bool 
        outpem;
    
   _Bool 
        load_request;
    
   _Bool 
        load_response;
    
   _Bool 
        ignore_errors;
    
   _Bool 
        verify_allow_broken;
    
   _Bool 
        version;
    
   _Bool 
        help;
    
   _Bool 
        more_help;
  } enabled;
};
extern struct ocsptool_options ocsptool_options;
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




       


struct ocsptool_options ocsptool_options;

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
  { "infile", 
             1
                              , 0, 0x7f + 1 },
  { "outfile", 
              1
                               , 0, 0x7f + 2 },
  { "ask", 
          2
                           , 0, 0x7f + 3 },
  { "verify-response", 
                      0
                                 , 0, 'e' },
  { "request-info", 
                   0
                              , 0, 'i' },
  { "response-info", 
                    0
                               , 0, 'j' },
  { "generate-request", 
                       0
                                  , 0, 'q' },
  { "nonce", 
            0
                       , 0, 0x7f + 4 },
  { "no-nonce", 
               0
                          , 0, 0x7f + 5 },
  { "load-chain", 
                 1
                                  , 0, 0x7f + 6 },
  { "load-issuer", 
                  1
                                   , 0, 0x7f + 7 },
  { "load-cert", 
                1
                                 , 0, 0x7f + 8 },
  { "load-trust", 
                 1
                                  , 0, 0x7f + 9 },
  { "load-signer", 
                  1
                                   , 0, 0x7f + 10 },
  { "inder", 
            0
                       , 0, 0x7f + 11 },
  { "no-inder", 
               0
                          , 0, 0x7f + 12 },
  { "outder", 
             0
                        , 0, 0x7f + 13 },
  { "outpem", 
             0
                        , 0, 0x7f + 14 },
  { "load-request", 
                   1
                                    , 0, 'Q' },
  { "load-response", 
                    1
                                     , 0, 'S' },
  { "ignore-errors", 
                    0
                               , 0, 0x7f + 15 },
  { "verify-allow-broken", 
                          0
                                     , 0, 0x7f + 16 },
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
  struct ocsptool_options *opts = &ocsptool_options;
  int opt;


  while ((opt = getopt_long (argc, argv, "!Q:S:Vd:ehijqv:",
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
        opts->present.infile = 
                              1
                                  ;
        opts->arg.infile = optarg;
        opts->enabled.infile = 
                              1
                                  ;
        break;
      case 0x7f + 2:
        opts->present.outfile = 
                               1
                                   ;
        opts->arg.outfile = optarg;
        opts->enabled.outfile = 
                               1
                                   ;
        break;
      case 0x7f + 3:
        opts->present.ask = 
                           1
                               ;
        opts->arg.ask = optarg;
        opts->enabled.ask = 
                           1
                               ;
        break;
      case 'e':
        opts->present.verify_response = 
                                       1
                                           ;
        opts->enabled.verify_response = 
                                       1
                                           ;
        break;
      case 'i':
        opts->present.request_info = 
                                    1
                                        ;
        opts->enabled.request_info = 
                                    1
                                        ;
        break;
      case 'j':
        opts->present.response_info = 
                                     1
                                         ;
        opts->enabled.response_info = 
                                     1
                                         ;
        break;
      case 'q':
        opts->present.generate_request = 
                                        1
                                            ;
        opts->enabled.generate_request = 
                                        1
                                            ;
        break;
      case 0x7f + 4:
        opts->present.nonce = 
                             1
                                 ;
        opts->enabled.nonce = 
                             1
                                 ;
        break;
      case 0x7f + 5:
        opts->present.nonce = 
                             1
                                 ;
        opts->enabled.nonce = 
                             0
                                  ;
        break;
      case 0x7f + 6:
        opts->present.load_chain = 
                                  1
                                      ;
        opts->arg.load_chain = optarg;
        opts->enabled.load_chain = 
                                  1
                                      ;
        break;
      case 0x7f + 7:
        opts->present.load_issuer = 
                                   1
                                       ;
        opts->arg.load_issuer = optarg;
        opts->enabled.load_issuer = 
                                   1
                                       ;
        break;
      case 0x7f + 8:
        opts->present.load_cert = 
                                 1
                                     ;
        opts->arg.load_cert = optarg;
        opts->enabled.load_cert = 
                                 1
                                     ;
        break;
      case 0x7f + 9:
        opts->present.load_trust = 
                                  1
                                      ;
        opts->arg.load_trust = optarg;
        opts->enabled.load_trust = 
                                  1
                                      ;
        break;
      case 0x7f + 10:
        opts->present.load_signer = 
                                   1
                                       ;
        opts->arg.load_signer = optarg;
        opts->enabled.load_signer = 
                                   1
                                       ;
        break;
      case 0x7f + 11:
        opts->present.inder = 
                             1
                                 ;
        opts->enabled.inder = 
                             1
                                 ;
        break;
      case 0x7f + 12:
        opts->present.inder = 
                             1
                                 ;
        opts->enabled.inder = 
                             0
                                  ;
        break;
      case 0x7f + 13:
        opts->present.outder = 
                              1
                                  ;
        opts->enabled.outder = 
                              1
                                  ;
        break;
      case 0x7f + 14:
        opts->present.outpem = 
                              1
                                  ;
        opts->enabled.outpem = 
                              1
                                  ;
        break;
      case 'Q':
        opts->present.load_request = 
                                    1
                                        ;
        opts->arg.load_request = optarg;
        opts->enabled.load_request = 
                                    1
                                        ;
        break;
      case 'S':
        opts->present.load_response = 
                                     1
                                         ;
        opts->arg.load_response = optarg;
        opts->enabled.load_response = 
                                     1
                                         ;
        break;
      case 0x7f + 15:
        opts->present.ignore_errors = 
                                     1
                                         ;
        opts->enabled.ignore_errors = 
                                     1
                                         ;
        break;
      case 0x7f + 16:
        opts->present.verify_allow_broken = 
                                           1
                                               ;
        opts->enabled.verify_allow_broken = 
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

  if (ocsptool_options.present.debug && ocsptool_options.value.debug < 0)
    {
      error (
            1
                        , 0, "%s option value %d is out of range.",
             "debug", opts->value.debug);
    }
  if (ocsptool_options.present.debug && ocsptool_options.value.debug > 9999)
    {
      error (
            1
                        , 0, "%s option value %d is out of range",
             "debug", opts->value.debug);
    }
  if (ocsptool_options.present.load_trust && ocsptool_options.present.load_signer)
    {
      error (
            1
                        , 0, "the '%s' and '%s' options conflict",
             "load-trust", "load_signer");
    }
  if (ocsptool_options.present.load_signer && ocsptool_options.present.load_trust)
    {
      error (
            1
                        , 0, "the '%s' and '%s' options conflict",
             "load-signer", "load_trust");
    }
  if (optind < argc)
    {
      error (
            1
                        , 0, "Command line arguments are not allowed.");
    }


  if (ocsptool_options.present.help)
    {
      usage (
     stdout
     , (0));
    }

  if (ocsptool_options.present.more_help)





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


  if (ocsptool_options.present.version)
    {
      if (!ocsptool_options.arg.version || !strcmp (ocsptool_options.arg.version, "c"))
        {
          const char str[] =
            "ocsptool 3.7.8\n"
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
      else if (!strcmp (ocsptool_options.arg.version, "v"))
        {
          const char str[] =
            "ocsptool 3.7.8\n";
          fprintf (
                  stdout
                        , "%s", str);
          exit(0);
        }
      else if (!strcmp (ocsptool_options.arg.version, "n"))
        {
          const char str[] =
            "ocsptool 3.7.8\n"
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
    "ocsptool - GnuTLS OCSP tool\n"
    "Usage:  ocsptool [ -<flag> [<val>] | --<name>[{=| }<val>] ]... \n"
    "\n"
    "None:\n"
    "\n"
    "   -d, --debug=num            Enable debugging\n"
    "				- it must be in the range:\n"
    "				  0 to 9999\n"
    "   -V, --verbose              More verbose output\n"
    "       --infile=file          Input file\n"
    "				- file must pre-exist\n"
    "       --outfile=str          Output file\n"
    "       --ask[=str]            Ask an OCSP/HTTP server on a certificate validity\n"
    "   -e, --verify-response      Verify response\n"
    "   -i, --request-info         Print information on a OCSP request\n"
    "   -j, --response-info        Print information on a OCSP response\n"
    "   -q, --generate-request     Generates an OCSP request\n"
    "       --nonce                Use (or not) a nonce to OCSP request\n"
    "       --load-chain=file      Reads a set of certificates forming a chain from file\n"
    "				- file must pre-exist\n"
    "       --load-issuer=file     Reads issuer's certificate from file\n"
    "				- file must pre-exist\n"
    "       --load-cert=file       Reads the certificate to check from file\n"
    "				- file must pre-exist\n"
    "       --load-trust=file      Read OCSP trust anchors from file\n"
    "				- prohibits the option 'load-signer'\n"
    "				- file must pre-exist\n"
    "       --load-signer=file     Reads the OCSP response signer from file\n"
    "				- prohibits the option 'load-trust'\n"
    "				- file must pre-exist\n"
    "       --inder                Use DER format for input certificates and private keys\n"
    "       --outder               Use DER format for output of responses (this is the default)\n"
    "       --outpem               Use PEM format for output of responses\n"
    "   -Q, --load-request=file    Reads the DER encoded OCSP request from file\n"
    "				- file must pre-exist\n"
    "   -S, --load-response=file   Reads the DER encoded OCSP response from file\n"
    "				- file must pre-exist\n"
    "       --ignore-errors        Ignore any verification errors\n"
    "       --verify-allow-broken  Allow broken algorithms, such as MD5 for verification\n"
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
    "ocsptool is a program that can parse and print information about\n"
    "OCSP requests/responses, generate requests and verify responses. Unlike\n"
    "other GnuTLS applications it outputs DER encoded structures by default\n"
    "unless the '--outpem' option is specified.\n"
    "\n"
    "Please send bug reports to:  <bugs@gnutls.org>\n"
    "\n";
  fprintf (out, "%s", str);
  exit (status);
}
