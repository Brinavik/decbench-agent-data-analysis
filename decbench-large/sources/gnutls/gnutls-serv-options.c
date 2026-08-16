


       












       
       
       
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





struct gnutls_serv_list
{
  const char **args;
  unsigned int count;
};

struct gnutls_serv_options
{

  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        sni_hostname;
    
   _Bool 
        sni_hostname_fatal;
    
   _Bool 
        alpn;
    
   _Bool 
        alpn_fatal;
    
   _Bool 
        noticket;
    
   _Bool 
        earlydata;
    
   _Bool 
        maxearlydata;
    
   _Bool 
        nocookie;
    
   _Bool 
        generate;
    
   _Bool 
        quiet;
    
   _Bool 
        nodb;
    
   _Bool 
        http;
    
   _Bool 
        echo;
    
   _Bool 
        crlf;
    
   _Bool 
        udp;
    
   _Bool 
        mtu;
    
   _Bool 
        srtp_profiles;
    
   _Bool 
        disable_client_cert;
    
   _Bool 
        require_client_cert;
    
   _Bool 
        verify_client_cert;
    
   _Bool 
        compress_cert;
    
   _Bool 
        heartbeat;
    
   _Bool 
        x509fmtder;
    
   _Bool 
        priority;
    
   _Bool 
        dhparams;
    
   _Bool 
        x509cafile;
    
   _Bool 
        x509crlfile;
    
   _Bool 
        pgpkeyfile;
    
   _Bool 
        x509keyfile;
    
   _Bool 
        x509certfile;
    
   _Bool 
        rawpkkeyfile;
    
   _Bool 
        rawpkfile;
    
   _Bool 
        srppasswd;
    
   _Bool 
        srppasswdconf;
    
   _Bool 
        pskpasswd;
    
   _Bool 
        pskhint;
    
   _Bool 
        ocsp_response;
    
   _Bool 
        ignore_ocsp_response_errors;
    
   _Bool 
        port;
    
   _Bool 
        list;
    
   _Bool 
        provider;
    
   _Bool 
        keymatexport;
    
   _Bool 
        keymatexportsize;
    
   _Bool 
        recordsize;
    
   _Bool 
        httpdata;
    
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
    const char *sni_hostname;
    const char *maxearlydata;
    const char *mtu;
    const char *srtp_profiles;
    const char *priority;
    const char *dhparams;
    const char *x509cafile;
    const char *x509crlfile;
    const char *pgpkeyfile;
    const char *srppasswd;
    const char *srppasswdconf;
    const char *pskpasswd;
    const char *pskhint;
    const char *port;
    const char *provider;
    const char *keymatexport;
    const char *keymatexportsize;
    const char *recordsize;
    const char *httpdata;
    const char *version;
  } arg;


  struct
  {
    int debug;
    int maxearlydata;
    int mtu;
    int port;
    int keymatexportsize;
    int recordsize;
  } value;


  struct
  {
    struct gnutls_serv_list alpn;
    struct gnutls_serv_list compress_cert;
    struct gnutls_serv_list x509keyfile;
    struct gnutls_serv_list x509certfile;
    struct gnutls_serv_list rawpkkeyfile;
    struct gnutls_serv_list rawpkfile;
    struct gnutls_serv_list ocsp_response;
  } list;


  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        sni_hostname;
    
   _Bool 
        sni_hostname_fatal;
    
   _Bool 
        alpn;
    
   _Bool 
        alpn_fatal;
    
   _Bool 
        noticket;
    
   _Bool 
        earlydata;
    
   _Bool 
        maxearlydata;
    
   _Bool 
        nocookie;
    
   _Bool 
        generate;
    
   _Bool 
        quiet;
    
   _Bool 
        nodb;
    
   _Bool 
        http;
    
   _Bool 
        echo;
    
   _Bool 
        crlf;
    
   _Bool 
        udp;
    
   _Bool 
        mtu;
    
   _Bool 
        srtp_profiles;
    
   _Bool 
        disable_client_cert;
    
   _Bool 
        require_client_cert;
    
   _Bool 
        verify_client_cert;
    
   _Bool 
        compress_cert;
    
   _Bool 
        heartbeat;
    
   _Bool 
        x509fmtder;
    
   _Bool 
        priority;
    
   _Bool 
        dhparams;
    
   _Bool 
        x509cafile;
    
   _Bool 
        x509crlfile;
    
   _Bool 
        pgpkeyfile;
    
   _Bool 
        x509keyfile;
    
   _Bool 
        x509certfile;
    
   _Bool 
        rawpkkeyfile;
    
   _Bool 
        rawpkfile;
    
   _Bool 
        srppasswd;
    
   _Bool 
        srppasswdconf;
    
   _Bool 
        pskpasswd;
    
   _Bool 
        pskhint;
    
   _Bool 
        ocsp_response;
    
   _Bool 
        ignore_ocsp_response_errors;
    
   _Bool 
        port;
    
   _Bool 
        list;
    
   _Bool 
        provider;
    
   _Bool 
        keymatexport;
    
   _Bool 
        keymatexportsize;
    
   _Bool 
        recordsize;
    
   _Bool 
        httpdata;
    
   _Bool 
        version;
    
   _Bool 
        help;
    
   _Bool 
        more_help;
  } enabled;
};
extern struct gnutls_serv_options gnutls_serv_options;
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




       


struct gnutls_serv_options gnutls_serv_options;




static inline size_t
xsum (size_t size1, size_t size2)
{
  size_t sum = size1 + size2;
  return (sum >= size1 ? sum : 
                              (18446744073709551615UL)
                                      );
}




static void
append_to_list (struct gnutls_serv_list *list,
                const char *name, const char *arg)
{
  const char **tmp;
  size_t new_count = xsum (list->count, 1);

  if (((new_count) == 
     (18446744073709551615UL)
     ))
    error (
          1
                      , 0, "too many arguments for %s",
           name);

  tmp = reallocarray (list->args, new_count, sizeof (char *));
  if (!tmp)
    error (
          1
                      , 0, "unable to allocate memory for %s",
           name);

  list->args = tmp;
  list->args[list->count] = optarg;
  list->count = new_count;
}

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
  { "sni-hostname", 
                   1
                                    , 0, 0x7f + 1 },
  { "sni-hostname-fatal", 
                         0
                                    , 0, 0x7f + 2 },
  { "alpn", 
           1
                            , 0, 0x7f + 3 },
  { "alpn-fatal", 
                 0
                            , 0, 0x7f + 4 },
  { "noticket", 
               0
                          , 0, 0x7f + 5 },
  { "earlydata", 
                0
                           , 0, 0x7f + 6 },
  { "maxearlydata", 
                   1
                                    , 0, 0x7f + 7 },
  { "nocookie", 
               0
                          , 0, 0x7f + 8 },
  { "generate", 
               0
                          , 0, 'g' },
  { "quiet", 
            0
                       , 0, 'q' },
  { "nodb", 
           0
                      , 0, 0x7f + 9 },
  { "http", 
           0
                      , 0, 0x7f + 10 },
  { "echo", 
           0
                      , 0, 0x7f + 11 },
  { "crlf", 
           0
                      , 0, 0x7f + 12 },
  { "udp", 
          0
                     , 0, 'u' },
  { "mtu", 
          1
                           , 0, 0x7f + 13 },
  { "srtp-profiles", 
                    1
                                     , 0, 0x7f + 14 },
  { "disable-client-cert", 
                          0
                                     , 0, 'a' },
  { "require-client-cert", 
                          0
                                     , 0, 'r' },
  { "verify-client-cert", 
                         0
                                    , 0, 0x7f + 15 },
  { "compress-cert", 
                    1
                                     , 0, 0x7f + 16 },
  { "heartbeat", 
                0
                           , 0, 'b' },
  { "x509fmtder", 
                 0
                            , 0, 0x7f + 17 },
  { "priority", 
               1
                                , 0, 0x7f + 18 },
  { "dhparams", 
               1
                                , 0, 0x7f + 19 },
  { "x509cafile", 
                 1
                                  , 0, 0x7f + 20 },
  { "x509crlfile", 
                  1
                                   , 0, 0x7f + 21 },
  { "pgpkeyfile", 
                 1
                                  , 0, 0x7f + 22 },
  { "x509keyfile", 
                  1
                                   , 0, 0x7f + 23 },
  { "x509dsakeyfile", 
                     1
                                      , 0, 0x7f + 25 },
  { "x509ecckeyfile", 
                     1
                                      , 0, 0x7f + 27 },
  { "x509certfile", 
                   1
                                    , 0, 0x7f + 24 },
  { "x509dsacertfile", 
                      1
                                       , 0, 0x7f + 26 },
  { "x509ecccertfile", 
                      1
                                       , 0, 0x7f + 28 },
  { "rawpkkeyfile", 
                   1
                                    , 0, 0x7f + 29 },
  { "rawpkfile", 
                1
                                 , 0, 0x7f + 30 },
  { "srppasswd", 
                1
                                 , 0, 0x7f + 31 },
  { "srppasswdconf", 
                    1
                                     , 0, 0x7f + 32 },
  { "pskpasswd", 
                1
                                 , 0, 0x7f + 33 },
  { "pskhint", 
              1
                               , 0, 0x7f + 34 },
  { "ocsp-response", 
                    1
                                     , 0, 0x7f + 35 },
  { "ignore-ocsp-response-errors", 
                                  0
                                             , 0, 0x7f + 36 },
  { "port", 
           1
                            , 0, 'p' },
  { "list", 
           0
                      , 0, 'l' },
  { "provider", 
               1
                                , 0, 0x7f + 37 },
  { "keymatexport", 
                   1
                                    , 0, 0x7f + 38 },
  { "keymatexportsize", 
                       1
                                        , 0, 0x7f + 39 },
  { "recordsize", 
                 1
                                  , 0, 0x7f + 40 },
  { "httpdata", 
               1
                                , 0, 0x7f + 41 },
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
  struct gnutls_serv_options *opts = &gnutls_serv_options;
  int opt;


  while ((opt = getopt_long (argc, argv, "!abd:ghlp:qruv:",
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
      case 0x7f + 1:
        opts->present.sni_hostname = 
                                    1
                                        ;
        opts->arg.sni_hostname = optarg;
        opts->enabled.sni_hostname = 
                                    1
                                        ;
        break;
      case 0x7f + 2:
        opts->present.sni_hostname_fatal = 
                                          1
                                              ;
        opts->enabled.sni_hostname_fatal = 
                                          1
                                              ;
        break;
      case 0x7f + 3:
        opts->present.alpn = 
                            1
                                ;
        append_to_list (&opts->list.alpn, "alpn", optarg);
        opts->enabled.alpn = 
                            1
                                ;
        break;
      case 0x7f + 4:
        opts->present.alpn_fatal = 
                                  1
                                      ;
        opts->enabled.alpn_fatal = 
                                  1
                                      ;
        break;
      case 0x7f + 5:
        opts->present.noticket = 
                                1
                                    ;
        opts->enabled.noticket = 
                                1
                                    ;
        break;
      case 0x7f + 6:
        opts->present.earlydata = 
                                 1
                                     ;
        opts->enabled.earlydata = 
                                 1
                                     ;
        break;
      case 0x7f + 7:
        opts->present.maxearlydata = 
                                    1
                                        ;
        opts->arg.maxearlydata = optarg;
        opts->value.maxearlydata = parse_number(optarg);
        opts->enabled.maxearlydata = 
                                    1
                                        ;
        break;
      case 0x7f + 8:
        opts->present.nocookie = 
                                1
                                    ;
        opts->enabled.nocookie = 
                                1
                                    ;
        break;
      case 'g':
        opts->present.generate = 
                                1
                                    ;
        opts->enabled.generate = 
                                1
                                    ;
        break;
      case 'q':
        opts->present.quiet = 
                             1
                                 ;
        opts->enabled.quiet = 
                             1
                                 ;
        break;
      case 0x7f + 9:
        opts->present.nodb = 
                            1
                                ;
        opts->enabled.nodb = 
                            1
                                ;
        break;
      case 0x7f + 10:
        opts->present.http = 
                            1
                                ;
        opts->enabled.http = 
                            1
                                ;
        break;
      case 0x7f + 11:
        opts->present.echo = 
                            1
                                ;
        opts->enabled.echo = 
                            1
                                ;
        break;
      case 0x7f + 12:
        opts->present.crlf = 
                            1
                                ;
        opts->enabled.crlf = 
                            1
                                ;
        break;
      case 'u':
        opts->present.udp = 
                           1
                               ;
        opts->enabled.udp = 
                           1
                               ;
        break;
      case 0x7f + 13:
        opts->present.mtu = 
                           1
                               ;
        opts->arg.mtu = optarg;
        opts->value.mtu = parse_number(optarg);
        opts->enabled.mtu = 
                           1
                               ;
        break;
      case 0x7f + 14:
        opts->present.srtp_profiles = 
                                     1
                                         ;
        opts->arg.srtp_profiles = optarg;
        opts->enabled.srtp_profiles = 
                                     1
                                         ;
        break;
      case 'a':
        opts->present.disable_client_cert = 
                                           1
                                               ;
        opts->enabled.disable_client_cert = 
                                           1
                                               ;
        break;
      case 'r':
        opts->present.require_client_cert = 
                                           1
                                               ;
        opts->enabled.require_client_cert = 
                                           1
                                               ;
        break;
      case 0x7f + 15:
        opts->present.verify_client_cert = 
                                          1
                                              ;
        opts->enabled.verify_client_cert = 
                                          1
                                              ;
        break;
      case 0x7f + 16:
        opts->present.compress_cert = 
                                     1
                                         ;
        append_to_list (&opts->list.compress_cert, "compress-cert", optarg);
        opts->enabled.compress_cert = 
                                     1
                                         ;
        break;
      case 'b':
        opts->present.heartbeat = 
                                 1
                                     ;
        opts->enabled.heartbeat = 
                                 1
                                     ;
        break;
      case 0x7f + 17:
        opts->present.x509fmtder = 
                                  1
                                      ;
        opts->enabled.x509fmtder = 
                                  1
                                      ;
        break;
      case 0x7f + 18:
        opts->present.priority = 
                                1
                                    ;
        opts->arg.priority = optarg;
        opts->enabled.priority = 
                                1
                                    ;
        break;
      case 0x7f + 19:
        opts->present.dhparams = 
                                1
                                    ;
        opts->arg.dhparams = optarg;
        opts->enabled.dhparams = 
                                1
                                    ;
        break;
      case 0x7f + 20:
        opts->present.x509cafile = 
                                  1
                                      ;
        opts->arg.x509cafile = optarg;
        opts->enabled.x509cafile = 
                                  1
                                      ;
        break;
      case 0x7f + 21:
        opts->present.x509crlfile = 
                                   1
                                       ;
        opts->arg.x509crlfile = optarg;
        opts->enabled.x509crlfile = 
                                   1
                                       ;
        break;
      case 0x7f + 22:
        opts->present.pgpkeyfile = 
                                  1
                                      ;
        opts->arg.pgpkeyfile = optarg;
        opts->enabled.pgpkeyfile = 
                                  1
                                      ;
        break;
      case 0x7f + 23:
      case 0x7f + 25:
      case 0x7f + 27:
        opts->present.x509keyfile = 
                                   1
                                       ;
        append_to_list (&opts->list.x509keyfile, "x509keyfile", optarg);
        opts->enabled.x509keyfile = 
                                   1
                                       ;
        break;
      case 0x7f + 24:
      case 0x7f + 26:
      case 0x7f + 28:
        opts->present.x509certfile = 
                                    1
                                        ;
        append_to_list (&opts->list.x509certfile, "x509certfile", optarg);
        opts->enabled.x509certfile = 
                                    1
                                        ;
        break;
      case 0x7f + 29:
        opts->present.rawpkkeyfile = 
                                    1
                                        ;
        append_to_list (&opts->list.rawpkkeyfile, "rawpkkeyfile", optarg);
        opts->enabled.rawpkkeyfile = 
                                    1
                                        ;
        break;
      case 0x7f + 30:
        opts->present.rawpkfile = 
                                 1
                                     ;
        append_to_list (&opts->list.rawpkfile, "rawpkfile", optarg);
        opts->enabled.rawpkfile = 
                                 1
                                     ;
        break;
      case 0x7f + 31:
        opts->present.srppasswd = 
                                 1
                                     ;
        opts->arg.srppasswd = optarg;
        opts->enabled.srppasswd = 
                                 1
                                     ;
        break;
      case 0x7f + 32:
        opts->present.srppasswdconf = 
                                     1
                                         ;
        opts->arg.srppasswdconf = optarg;
        opts->enabled.srppasswdconf = 
                                     1
                                         ;
        break;
      case 0x7f + 33:
        opts->present.pskpasswd = 
                                 1
                                     ;
        opts->arg.pskpasswd = optarg;
        opts->enabled.pskpasswd = 
                                 1
                                     ;
        break;
      case 0x7f + 34:
        opts->present.pskhint = 
                               1
                                   ;
        opts->arg.pskhint = optarg;
        opts->enabled.pskhint = 
                               1
                                   ;
        break;
      case 0x7f + 35:
        opts->present.ocsp_response = 
                                     1
                                         ;
        append_to_list (&opts->list.ocsp_response, "ocsp-response", optarg);
        opts->enabled.ocsp_response = 
                                     1
                                         ;
        break;
      case 0x7f + 36:
        opts->present.ignore_ocsp_response_errors = 
                                                   1
                                                       ;
        opts->enabled.ignore_ocsp_response_errors = 
                                                   1
                                                       ;
        break;
      case 'p':
        opts->present.port = 
                            1
                                ;
        opts->arg.port = optarg;
        opts->value.port = parse_number(optarg);
        opts->enabled.port = 
                            1
                                ;
        break;
      case 'l':
        opts->present.list = 
                            1
                                ;
        opts->enabled.list = 
                            1
                                ;
        break;
      case 0x7f + 37:
        opts->present.provider = 
                                1
                                    ;
        opts->arg.provider = optarg;
        opts->enabled.provider = 
                                1
                                    ;
        break;
      case 0x7f + 38:
        opts->present.keymatexport = 
                                    1
                                        ;
        opts->arg.keymatexport = optarg;
        opts->enabled.keymatexport = 
                                    1
                                        ;
        break;
      case 0x7f + 39:
        opts->present.keymatexportsize = 
                                        1
                                            ;
        opts->arg.keymatexportsize = optarg;
        opts->value.keymatexportsize = parse_number(optarg);
        opts->enabled.keymatexportsize = 
                                        1
                                            ;
        break;
      case 0x7f + 40:
        opts->present.recordsize = 
                                  1
                                      ;
        opts->arg.recordsize = optarg;
        opts->value.recordsize = parse_number(optarg);
        opts->enabled.recordsize = 
                                  1
                                      ;
        break;
      case 0x7f + 41:
        opts->present.httpdata = 
                                1
                                    ;
        opts->arg.httpdata = optarg;
        opts->enabled.httpdata = 
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

  if (gnutls_serv_options.present.debug && gnutls_serv_options.value.debug < 0)
    {
      error (
            1
                        , 0, "%s option value %d is out of range.",
             "debug", opts->value.debug);
    }
  if (gnutls_serv_options.present.debug && gnutls_serv_options.value.debug > 9999)
    {
      error (
            1
                        , 0, "%s option value %d is out of range",
             "debug", opts->value.debug);
    }
  if (gnutls_serv_options.present.maxearlydata && gnutls_serv_options.value.maxearlydata < 1)
    {
      error (
            1
                        , 0, "%s option value %d is out of range.",
             "maxearlydata", opts->value.maxearlydata);
    }
  if (gnutls_serv_options.present.maxearlydata && gnutls_serv_options.value.maxearlydata > 2147483648)
    {
      error (
            1
                        , 0, "%s option value %d is out of range",
             "maxearlydata", opts->value.maxearlydata);
    }
  if (gnutls_serv_options.present.mtu && gnutls_serv_options.value.mtu < 0)
    {
      error (
            1
                        , 0, "%s option value %d is out of range.",
             "mtu", opts->value.mtu);
    }
  if (gnutls_serv_options.present.mtu && gnutls_serv_options.value.mtu > 17000)
    {
      error (
            1
                        , 0, "%s option value %d is out of range",
             "mtu", opts->value.mtu);
    }
  if (gnutls_serv_options.present.disable_client_cert && gnutls_serv_options.present.require_client_cert)
    {
      error (
            1
                        , 0, "the '%s' and '%s' options conflict",
             "disable-client-cert", "require_client_cert");
    }
  if (gnutls_serv_options.present.rawpkfile && !gnutls_serv_options.present.rawpkkeyfile)
    {
      error (
            1
                        , 0, "%s option requires the %s options",
             "rawpkfile", "rawpkkeyfile");
    }
  if (gnutls_serv_options.present.recordsize && gnutls_serv_options.value.recordsize < 0)
    {
      error (
            1
                        , 0, "%s option value %d is out of range.",
             "recordsize", opts->value.recordsize);
    }
  if (gnutls_serv_options.present.recordsize && gnutls_serv_options.value.recordsize > 16384)
    {
      error (
            1
                        , 0, "%s option value %d is out of range",
             "recordsize", opts->value.recordsize);
    }
  if (optind < argc)
    {
      error (
            1
                        , 0, "Command line arguments are not allowed.");
    }


  if (gnutls_serv_options.present.help)
    {
      usage (
     stdout
     , (0));
    }

  if (gnutls_serv_options.present.more_help)





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


  if (gnutls_serv_options.present.version)
    {
      if (!gnutls_serv_options.arg.version || !strcmp (gnutls_serv_options.arg.version, "c"))
        {
          const char str[] =
            "gnutls-serv 3.7.8\n"
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
      else if (!strcmp (gnutls_serv_options.arg.version, "v"))
        {
          const char str[] =
            "gnutls-serv 3.7.8\n";
          fprintf (
                  stdout
                        , "%s", str);
          exit(0);
        }
      else if (!strcmp (gnutls_serv_options.arg.version, "n"))
        {
          const char str[] =
            "gnutls-serv 3.7.8\n"
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
    "gnutls-serv - GnuTLS server\n"
    "Usage:  gnutls-serv [ -<flag> [<val>] | --<name>[{=| }<val>] ]... \n"
    "\n"
    "None:\n"
    "\n"
    "   -d, --debug=num            Enable debugging\n"
    "				- it must be in the range:\n"
    "				  0 to 9999\n"
    "       --sni-hostname=str     Server's hostname for server name extension\n"
    "       --sni-hostname-fatal   Send fatal alert on sni-hostname mismatch\n"
    "       --alpn=str             Specify ALPN protocol to be enabled by the server\n"
    "       --alpn-fatal           Send fatal alert on non-matching ALPN name\n"
    "       --noticket             Don't accept session tickets\n"
    "       --earlydata            Accept early data\n"
    "       --maxearlydata=num     The maximum early data size to accept\n"
    "				- it must be in the range:\n"
    "				  1 to 2147483648\n"
    "       --nocookie             Don't require cookie on DTLS sessions\n"
    "   -g, --generate             Generate Diffie-Hellman parameters\n"
    "   -q, --quiet                Suppress some messages\n"
    "       --nodb                 Do not use a resumption database\n"
    "       --http                 Act as an HTTP server\n"
    "       --echo                 Act as an Echo server\n"
    "       --crlf                 Do not replace CRLF by LF in Echo server mode\n"
    "   -u, --udp                  Use DTLS (datagram TLS) over UDP\n"
    "       --mtu=num              Set MTU for datagram TLS\n"
    "				- it must be in the range:\n"
    "				  0 to 17000\n"
    "       --srtp-profiles=str    Offer SRTP profiles\n"
    "   -a, --disable-client-cert  Do not request a client certificate\n"
    "				- prohibits the option 'require-client-cert'\n"
    "   -r, --require-client-cert  Require a client certificate\n"
    "       --verify-client-cert   If a client certificate is sent then verify it\n"
    "       --compress-cert=str    Compress certificate\n"
    "   -b, --heartbeat            Activate heartbeat support\n"
    "       --x509fmtder           Use DER format for certificates to read from\n"
    "       --priority=str         Priorities string\n"
    "       --dhparams=file        DH params file to use\n"
    "				- file must pre-exist\n"
    "       --x509cafile=str       Certificate file or PKCS #11 URL to use\n"
    "       --x509crlfile=file     CRL file to use\n"
    "				- file must pre-exist\n"
    "       --x509keyfile=str      X.509 key file or PKCS #11 URL to use\n"
    "       --x509certfile=str     X.509 Certificate file or PKCS #11 URL to use\n"
    "       --rawpkkeyfile=str     Private key file (PKCS #8 or PKCS #12) or PKCS #11 URL to use\n"
    "       --rawpkfile=str        Raw public-key file to use\n"
    "				- requires the option 'rawpkkeyfile'\n"
    "       --srppasswd=file       SRP password file to use\n"
    "				- file must pre-exist\n"
    "       --srppasswdconf=file   SRP password configuration file to use\n"
    "				- file must pre-exist\n"
    "       --pskpasswd=file       PSK password file to use\n"
    "				- file must pre-exist\n"
    "       --pskhint=str          PSK identity hint to use\n"
    "       --ocsp-response=str    The OCSP response to send to client\n"
    "       --ignore-ocsp-response-errors  Ignore any errors when setting the OCSP response\n"
    "   -p, --port=num             The port to connect to\n"
    "   -l, --list                 Print a list of the supported algorithms and modes\n"
    "       --provider=file        Specify the PKCS #11 provider library\n"
    "				- file must pre-exist\n"
    "       --keymatexport=str     Label used for exporting keying material\n"
    "       --keymatexportsize=num Size of the exported keying material\n"
    "       --recordsize=num       The maximum record size to advertise\n"
    "				- it must be in the range:\n"
    "				  0 to 16384\n"
    "       --httpdata=file        The data used as HTTP response\n"
    "				- file must pre-exist\n"
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
    "Server program that listens to incoming TLS connections.\n"
    "\n"
    "Please send bug reports to:  <bugs@gnutls.org>\n"
    "\n";
  fprintf (out, "%s", str);
  exit (status);
}
