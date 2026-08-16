


       












       
       
       
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





struct gnutls_cli_list
{
  const char **args;
  unsigned int count;
};

struct gnutls_cli_options
{

  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        verbose;
    
   _Bool 
        tofu;
    
   _Bool 
        strict_tofu;
    
   _Bool 
        dane;
    
   _Bool 
        local_dns;
    
   _Bool 
        ca_verification;
    
   _Bool 
        ocsp;
    
   _Bool 
        resume;
    
   _Bool 
        earlydata;
    
   _Bool 
        rehandshake;
    
   _Bool 
        sni_hostname;
    
   _Bool 
        verify_hostname;
    
   _Bool 
        starttls;
    
   _Bool 
        starttls_proto;
    
   _Bool 
        udp;
    
   _Bool 
        mtu;
    
   _Bool 
        crlf;
    
   _Bool 
        fastopen;
    
   _Bool 
        x509fmtder;
    
   _Bool 
        print_cert;
    
   _Bool 
        save_cert;
    
   _Bool 
        save_ocsp;
    
   _Bool 
        save_ocsp_multi;
    
   _Bool 
        save_server_trace;
    
   _Bool 
        save_client_trace;
    
   _Bool 
        dh_bits;
    
   _Bool 
        priority;
    
   _Bool 
        x509cafile;
    
   _Bool 
        x509crlfile;
    
   _Bool 
        x509keyfile;
    
   _Bool 
        x509certfile;
    
   _Bool 
        rawpkkeyfile;
    
   _Bool 
        rawpkfile;
    
   _Bool 
        srpusername;
    
   _Bool 
        srppasswd;
    
   _Bool 
        pskusername;
    
   _Bool 
        pskkey;
    
   _Bool 
        port;
    
   _Bool 
        insecure;
    
   _Bool 
        verify_allow_broken;
    
   _Bool 
        ranges;
    
   _Bool 
        benchmark_ciphers;
    
   _Bool 
        benchmark_tls_kx;
    
   _Bool 
        benchmark_tls_ciphers;
    
   _Bool 
        list;
    
   _Bool 
        priority_list;
    
   _Bool 
        noticket;
    
   _Bool 
        srtp_profiles;
    
   _Bool 
        alpn;
    
   _Bool 
        compress_cert;
    
   _Bool 
        heartbeat;
    
   _Bool 
        recordsize;
    
   _Bool 
        disable_sni;
    
   _Bool 
        disable_extensions;
    
   _Bool 
        single_key_share;
    
   _Bool 
        post_handshake_auth;
    
   _Bool 
        inline_commands;
    
   _Bool 
        inline_commands_prefix;
    
   _Bool 
        provider;
    
   _Bool 
        fips140_mode;
    
   _Bool 
        list_config;
    
   _Bool 
        logfile;
    
   _Bool 
        keymatexport;
    
   _Bool 
        keymatexportsize;
    
   _Bool 
        waitresumption;
    
   _Bool 
        ca_auto_retrieve;
    
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
    const char *earlydata;
    const char *sni_hostname;
    const char *verify_hostname;
    const char *starttls_proto;
    const char *mtu;
    const char *save_cert;
    const char *save_ocsp;
    const char *save_ocsp_multi;
    const char *save_server_trace;
    const char *save_client_trace;
    const char *dh_bits;
    const char *priority;
    const char *x509cafile;
    const char *x509crlfile;
    const char *x509keyfile;
    const char *x509certfile;
    const char *rawpkkeyfile;
    const char *rawpkfile;
    const char *srpusername;
    const char *srppasswd;
    const char *pskusername;
    const char *pskkey;
    const char *port;
    const char *srtp_profiles;
    const char *recordsize;
    const char *inline_commands_prefix;
    const char *provider;
    const char *logfile;
    const char *keymatexport;
    const char *keymatexportsize;
    const char *version;
  } arg;


  struct
  {
    int debug;
    int mtu;
    int dh_bits;
    int recordsize;
    int keymatexportsize;
  } value;


  struct
  {
    struct gnutls_cli_list alpn;
    struct gnutls_cli_list compress_cert;
  } list;


  struct
  {
    
   _Bool 
        debug;
    
   _Bool 
        verbose;
    
   _Bool 
        tofu;
    
   _Bool 
        strict_tofu;
    
   _Bool 
        dane;
    
   _Bool 
        local_dns;
    
   _Bool 
        ca_verification;
    
   _Bool 
        ocsp;
    
   _Bool 
        resume;
    
   _Bool 
        earlydata;
    
   _Bool 
        rehandshake;
    
   _Bool 
        sni_hostname;
    
   _Bool 
        verify_hostname;
    
   _Bool 
        starttls;
    
   _Bool 
        starttls_proto;
    
   _Bool 
        udp;
    
   _Bool 
        mtu;
    
   _Bool 
        crlf;
    
   _Bool 
        fastopen;
    
   _Bool 
        x509fmtder;
    
   _Bool 
        print_cert;
    
   _Bool 
        save_cert;
    
   _Bool 
        save_ocsp;
    
   _Bool 
        save_ocsp_multi;
    
   _Bool 
        save_server_trace;
    
   _Bool 
        save_client_trace;
    
   _Bool 
        dh_bits;
    
   _Bool 
        priority;
    
   _Bool 
        x509cafile;
    
   _Bool 
        x509crlfile;
    
   _Bool 
        x509keyfile;
    
   _Bool 
        x509certfile;
    
   _Bool 
        rawpkkeyfile;
    
   _Bool 
        rawpkfile;
    
   _Bool 
        srpusername;
    
   _Bool 
        srppasswd;
    
   _Bool 
        pskusername;
    
   _Bool 
        pskkey;
    
   _Bool 
        port;
    
   _Bool 
        insecure;
    
   _Bool 
        verify_allow_broken;
    
   _Bool 
        ranges;
    
   _Bool 
        benchmark_ciphers;
    
   _Bool 
        benchmark_tls_kx;
    
   _Bool 
        benchmark_tls_ciphers;
    
   _Bool 
        list;
    
   _Bool 
        priority_list;
    
   _Bool 
        noticket;
    
   _Bool 
        srtp_profiles;
    
   _Bool 
        alpn;
    
   _Bool 
        compress_cert;
    
   _Bool 
        heartbeat;
    
   _Bool 
        recordsize;
    
   _Bool 
        disable_sni;
    
   _Bool 
        disable_extensions;
    
   _Bool 
        single_key_share;
    
   _Bool 
        post_handshake_auth;
    
   _Bool 
        inline_commands;
    
   _Bool 
        inline_commands_prefix;
    
   _Bool 
        provider;
    
   _Bool 
        fips140_mode;
    
   _Bool 
        list_config;
    
   _Bool 
        logfile;
    
   _Bool 
        keymatexport;
    
   _Bool 
        keymatexportsize;
    
   _Bool 
        waitresumption;
    
   _Bool 
        ca_auto_retrieve;
    
   _Bool 
        version;
    
   _Bool 
        help;
    
   _Bool 
        more_help;
  } enabled;
};
extern struct gnutls_cli_options gnutls_cli_options;
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




       


struct gnutls_cli_options gnutls_cli_options;




static inline size_t
xsum (size_t size1, size_t size2)
{
  size_t sum = size1 + size2;
  return (sum >= size1 ? sum : 
                              (18446744073709551615UL)
                                      );
}




static void
append_to_list (struct gnutls_cli_list *list,
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
  { "verbose", 
              0
                         , 0, 'V' },
  { "tofu", 
           0
                      , 0, 0x7f + 1 },
  { "no-tofu", 
              0
                         , 0, 0x7f + 2 },
  { "strict-tofu", 
                  0
                             , 0, 0x7f + 3 },
  { "no-strict-tofu", 
                     0
                                , 0, 0x7f + 4 },
  { "dane", 
           0
                      , 0, 0x7f + 5 },
  { "no-dane", 
              0
                         , 0, 0x7f + 6 },
  { "local-dns", 
                0
                           , 0, 0x7f + 7 },
  { "no-local-dns", 
                   0
                              , 0, 0x7f + 8 },
  { "ca-verification", 
                      0
                                 , 0, 0x7f + 9 },
  { "no-ca-verification", 
                         0
                                    , 0, 0x7f + 10 },
  { "ocsp", 
           0
                      , 0, 0x7f + 11 },
  { "no-ocsp", 
              0
                         , 0, 0x7f + 12 },
  { "resume", 
             0
                        , 0, 'r' },
  { "earlydata", 
                1
                                 , 0, 0x7f + 13 },
  { "rehandshake", 
                  0
                             , 0, 'e' },
  { "sni-hostname", 
                   1
                                    , 0, 0x7f + 14 },
  { "verify-hostname", 
                      1
                                       , 0, 0x7f + 15 },
  { "starttls", 
               0
                          , 0, 's' },
  { "starttls-proto", 
                     1
                                      , 0, 0x7f + 17 },
  { "app-proto", 
                1
                                 , 0, 0x7f + 16 },
  { "udp", 
          0
                     , 0, 'u' },
  { "mtu", 
          1
                           , 0, 0x7f + 18 },
  { "crlf", 
           0
                      , 0, 0x7f + 19 },
  { "fastopen", 
               0
                          , 0, 0x7f + 20 },
  { "x509fmtder", 
                 0
                            , 0, 0x7f + 21 },
  { "print-cert", 
                 0
                            , 0, 0x7f + 22 },
  { "save-cert", 
                1
                                 , 0, 0x7f + 23 },
  { "save-ocsp", 
                1
                                 , 0, 0x7f + 24 },
  { "save-ocsp-multi", 
                      1
                                       , 0, 0x7f + 25 },
  { "save-server-trace", 
                        1
                                         , 0, 0x7f + 26 },
  { "save-client-trace", 
                        1
                                         , 0, 0x7f + 27 },
  { "dh-bits", 
              1
                               , 0, 0x7f + 28 },
  { "priority", 
               1
                                , 0, 0x7f + 29 },
  { "x509cafile", 
                 1
                                  , 0, 0x7f + 30 },
  { "x509crlfile", 
                  1
                                   , 0, 0x7f + 31 },
  { "x509keyfile", 
                  1
                                   , 0, 0x7f + 32 },
  { "x509certfile", 
                   1
                                    , 0, 0x7f + 33 },
  { "rawpkkeyfile", 
                   1
                                    , 0, 0x7f + 34 },
  { "rawpkfile", 
                1
                                 , 0, 0x7f + 35 },
  { "srpusername", 
                  1
                                   , 0, 0x7f + 36 },
  { "srppasswd", 
                1
                                 , 0, 0x7f + 37 },
  { "pskusername", 
                  1
                                   , 0, 0x7f + 38 },
  { "pskkey", 
             1
                              , 0, 0x7f + 39 },
  { "port", 
           1
                            , 0, 'p' },
  { "insecure", 
               0
                          , 0, 0x7f + 40 },
  { "verify-allow-broken", 
                          0
                                     , 0, 0x7f + 41 },
  { "ranges", 
             0
                        , 0, 0x7f + 42 },
  { "benchmark-ciphers", 
                        0
                                   , 0, 0x7f + 43 },
  { "benchmark-tls-kx", 
                       0
                                  , 0, 0x7f + 44 },
  { "benchmark-tls-ciphers", 
                            0
                                       , 0, 0x7f + 45 },
  { "list", 
           0
                      , 0, 'l' },
  { "priority-list", 
                    0
                               , 0, 0x7f + 46 },
  { "noticket", 
               0
                          , 0, 0x7f + 47 },
  { "srtp-profiles", 
                    1
                                     , 0, 0x7f + 48 },
  { "alpn", 
           1
                            , 0, 0x7f + 49 },
  { "compress-cert", 
                    1
                                     , 0, 0x7f + 50 },
  { "heartbeat", 
                0
                           , 0, 'b' },
  { "recordsize", 
                 1
                                  , 0, 0x7f + 51 },
  { "disable-sni", 
                  0
                             , 0, 0x7f + 52 },
  { "disable-extensions", 
                         0
                                    , 0, 0x7f + 53 },
  { "single-key-share", 
                       0
                                  , 0, 0x7f + 54 },
  { "post-handshake-auth", 
                          0
                                     , 0, 0x7f + 55 },
  { "inline-commands", 
                      0
                                 , 0, 0x7f + 56 },
  { "inline-commands-prefix", 
                             1
                                              , 0, 0x7f + 57 },
  { "provider", 
               1
                                , 0, 0x7f + 58 },
  { "fips140-mode", 
                   0
                              , 0, 0x7f + 59 },
  { "list-config", 
                  0
                             , 0, 0x7f + 60 },
  { "logfile", 
              1
                               , 0, 0x7f + 61 },
  { "keymatexport", 
                   1
                                    , 0, 0x7f + 62 },
  { "keymatexportsize", 
                       1
                                        , 0, 0x7f + 63 },
  { "waitresumption", 
                     0
                                , 0, 0x7f + 64 },
  { "ca-auto-retrieve", 
                       0
                                  , 0, 0x7f + 65 },
  { "no-ca-auto-retrieve", 
                          0
                                     , 0, 0x7f + 66 },
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
  struct gnutls_cli_options *opts = &gnutls_cli_options;
  int opt;

  opts->enabled.ca_verification = 
                                 1
                                     ;
  while ((opt = getopt_long (argc, argv, "!Vbd:ehlp:rsuv:",
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
        opts->present.tofu = 
                            1
                                ;
        opts->enabled.tofu = 
                            1
                                ;
        break;
      case 0x7f + 2:
        opts->present.tofu = 
                            1
                                ;
        opts->enabled.tofu = 
                            0
                                 ;
        break;
      case 0x7f + 3:
        opts->present.strict_tofu = 
                                   1
                                       ;
        opts->enabled.strict_tofu = 
                                   1
                                       ;
        break;
      case 0x7f + 4:
        opts->present.strict_tofu = 
                                   1
                                       ;
        opts->enabled.strict_tofu = 
                                   0
                                        ;
        break;
      case 0x7f + 5:
        opts->present.dane = 
                            1
                                ;
        opts->enabled.dane = 
                            1
                                ;
        break;
      case 0x7f + 6:
        opts->present.dane = 
                            1
                                ;
        opts->enabled.dane = 
                            0
                                 ;
        break;
      case 0x7f + 7:
        opts->present.local_dns = 
                                 1
                                     ;
        opts->enabled.local_dns = 
                                 1
                                     ;
        break;
      case 0x7f + 8:
        opts->present.local_dns = 
                                 1
                                     ;
        opts->enabled.local_dns = 
                                 0
                                      ;
        break;
      case 0x7f + 9:
        opts->present.ca_verification = 
                                       1
                                           ;
        opts->enabled.ca_verification = 
                                       1
                                           ;
        break;
      case 0x7f + 10:
        opts->present.ca_verification = 
                                       1
                                           ;
        opts->enabled.ca_verification = 
                                       0
                                            ;
        break;
      case 0x7f + 11:
        opts->present.ocsp = 
                            1
                                ;
        opts->enabled.ocsp = 
                            1
                                ;
        break;
      case 0x7f + 12:
        opts->present.ocsp = 
                            1
                                ;
        opts->enabled.ocsp = 
                            0
                                 ;
        break;
      case 'r':
        opts->present.resume = 
                              1
                                  ;
        opts->enabled.resume = 
                              1
                                  ;
        break;
      case 0x7f + 13:
        opts->present.earlydata = 
                                 1
                                     ;
        opts->arg.earlydata = optarg;
        opts->enabled.earlydata = 
                                 1
                                     ;
        break;
      case 'e':
        opts->present.rehandshake = 
                                   1
                                       ;
        opts->enabled.rehandshake = 
                                   1
                                       ;
        break;
      case 0x7f + 14:
        opts->present.sni_hostname = 
                                    1
                                        ;
        opts->arg.sni_hostname = optarg;
        opts->enabled.sni_hostname = 
                                    1
                                        ;
        break;
      case 0x7f + 15:
        opts->present.verify_hostname = 
                                       1
                                           ;
        opts->arg.verify_hostname = optarg;
        opts->enabled.verify_hostname = 
                                       1
                                           ;
        break;
      case 's':
        opts->present.starttls = 
                                1
                                    ;
        opts->enabled.starttls = 
                                1
                                    ;
        break;
      case 0x7f + 17:
      case 0x7f + 16:
        opts->present.starttls_proto = 
                                      1
                                          ;
        opts->arg.starttls_proto = optarg;
        opts->enabled.starttls_proto = 
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
      case 0x7f + 18:
        opts->present.mtu = 
                           1
                               ;
        opts->arg.mtu = optarg;
        opts->value.mtu = parse_number(optarg);
        opts->enabled.mtu = 
                           1
                               ;
        break;
      case 0x7f + 19:
        opts->present.crlf = 
                            1
                                ;
        opts->enabled.crlf = 
                            1
                                ;
        break;
      case 0x7f + 20:
        opts->present.fastopen = 
                                1
                                    ;
        opts->enabled.fastopen = 
                                1
                                    ;
        break;
      case 0x7f + 21:
        opts->present.x509fmtder = 
                                  1
                                      ;
        opts->enabled.x509fmtder = 
                                  1
                                      ;
        break;
      case 0x7f + 22:
        opts->present.print_cert = 
                                  1
                                      ;
        opts->enabled.print_cert = 
                                  1
                                      ;
        break;
      case 0x7f + 23:
        opts->present.save_cert = 
                                 1
                                     ;
        opts->arg.save_cert = optarg;
        opts->enabled.save_cert = 
                                 1
                                     ;
        break;
      case 0x7f + 24:
        opts->present.save_ocsp = 
                                 1
                                     ;
        opts->arg.save_ocsp = optarg;
        opts->enabled.save_ocsp = 
                                 1
                                     ;
        break;
      case 0x7f + 25:
        opts->present.save_ocsp_multi = 
                                       1
                                           ;
        opts->arg.save_ocsp_multi = optarg;
        opts->enabled.save_ocsp_multi = 
                                       1
                                           ;
        break;
      case 0x7f + 26:
        opts->present.save_server_trace = 
                                         1
                                             ;
        opts->arg.save_server_trace = optarg;
        opts->enabled.save_server_trace = 
                                         1
                                             ;
        break;
      case 0x7f + 27:
        opts->present.save_client_trace = 
                                         1
                                             ;
        opts->arg.save_client_trace = optarg;
        opts->enabled.save_client_trace = 
                                         1
                                             ;
        break;
      case 0x7f + 28:
        opts->present.dh_bits = 
                               1
                                   ;
        opts->arg.dh_bits = optarg;
        opts->value.dh_bits = parse_number(optarg);
        opts->enabled.dh_bits = 
                               1
                                   ;
        break;
      case 0x7f + 29:
        opts->present.priority = 
                                1
                                    ;
        opts->arg.priority = optarg;
        opts->enabled.priority = 
                                1
                                    ;
        break;
      case 0x7f + 30:
        opts->present.x509cafile = 
                                  1
                                      ;
        opts->arg.x509cafile = optarg;
        opts->enabled.x509cafile = 
                                  1
                                      ;
        break;
      case 0x7f + 31:
        opts->present.x509crlfile = 
                                   1
                                       ;
        opts->arg.x509crlfile = optarg;
        opts->enabled.x509crlfile = 
                                   1
                                       ;
        break;
      case 0x7f + 32:
        opts->present.x509keyfile = 
                                   1
                                       ;
        opts->arg.x509keyfile = optarg;
        opts->enabled.x509keyfile = 
                                   1
                                       ;
        break;
      case 0x7f + 33:
        opts->present.x509certfile = 
                                    1
                                        ;
        opts->arg.x509certfile = optarg;
        opts->enabled.x509certfile = 
                                    1
                                        ;
        break;
      case 0x7f + 34:
        opts->present.rawpkkeyfile = 
                                    1
                                        ;
        opts->arg.rawpkkeyfile = optarg;
        opts->enabled.rawpkkeyfile = 
                                    1
                                        ;
        break;
      case 0x7f + 35:
        opts->present.rawpkfile = 
                                 1
                                     ;
        opts->arg.rawpkfile = optarg;
        opts->enabled.rawpkfile = 
                                 1
                                     ;
        break;
      case 0x7f + 36:
        opts->present.srpusername = 
                                   1
                                       ;
        opts->arg.srpusername = optarg;
        opts->enabled.srpusername = 
                                   1
                                       ;
        break;
      case 0x7f + 37:
        opts->present.srppasswd = 
                                 1
                                     ;
        opts->arg.srppasswd = optarg;
        opts->enabled.srppasswd = 
                                 1
                                     ;
        break;
      case 0x7f + 38:
        opts->present.pskusername = 
                                   1
                                       ;
        opts->arg.pskusername = optarg;
        opts->enabled.pskusername = 
                                   1
                                       ;
        break;
      case 0x7f + 39:
        opts->present.pskkey = 
                              1
                                  ;
        opts->arg.pskkey = optarg;
        opts->enabled.pskkey = 
                              1
                                  ;
        break;
      case 'p':
        opts->present.port = 
                            1
                                ;
        opts->arg.port = optarg;
        opts->enabled.port = 
                            1
                                ;
        break;
      case 0x7f + 40:
        opts->present.insecure = 
                                1
                                    ;
        opts->enabled.insecure = 
                                1
                                    ;
        break;
      case 0x7f + 41:
        opts->present.verify_allow_broken = 
                                           1
                                               ;
        opts->enabled.verify_allow_broken = 
                                           1
                                               ;
        break;
      case 0x7f + 42:
        opts->present.ranges = 
                              1
                                  ;
        opts->enabled.ranges = 
                              1
                                  ;
        break;
      case 0x7f + 43:
        opts->present.benchmark_ciphers = 
                                         1
                                             ;
        opts->enabled.benchmark_ciphers = 
                                         1
                                             ;
        break;
      case 0x7f + 44:
        opts->present.benchmark_tls_kx = 
                                        1
                                            ;
        opts->enabled.benchmark_tls_kx = 
                                        1
                                            ;
        break;
      case 0x7f + 45:
        opts->present.benchmark_tls_ciphers = 
                                             1
                                                 ;
        opts->enabled.benchmark_tls_ciphers = 
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
      case 0x7f + 46:
        opts->present.priority_list = 
                                     1
                                         ;
        opts->enabled.priority_list = 
                                     1
                                         ;
        break;
      case 0x7f + 47:
        opts->present.noticket = 
                                1
                                    ;
        opts->enabled.noticket = 
                                1
                                    ;
        break;
      case 0x7f + 48:
        opts->present.srtp_profiles = 
                                     1
                                         ;
        opts->arg.srtp_profiles = optarg;
        opts->enabled.srtp_profiles = 
                                     1
                                         ;
        break;
      case 0x7f + 49:
        opts->present.alpn = 
                            1
                                ;
        append_to_list (&opts->list.alpn, "alpn", optarg);
        opts->enabled.alpn = 
                            1
                                ;
        break;
      case 0x7f + 50:
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
      case 0x7f + 51:
        opts->present.recordsize = 
                                  1
                                      ;
        opts->arg.recordsize = optarg;
        opts->value.recordsize = parse_number(optarg);
        opts->enabled.recordsize = 
                                  1
                                      ;
        break;
      case 0x7f + 52:
        opts->present.disable_sni = 
                                   1
                                       ;
        opts->enabled.disable_sni = 
                                   1
                                       ;
        break;
      case 0x7f + 53:
        opts->present.disable_extensions = 
                                          1
                                              ;
        opts->enabled.disable_extensions = 
                                          1
                                              ;
        break;
      case 0x7f + 54:
        opts->present.single_key_share = 
                                        1
                                            ;
        opts->enabled.single_key_share = 
                                        1
                                            ;
        break;
      case 0x7f + 55:
        opts->present.post_handshake_auth = 
                                           1
                                               ;
        opts->enabled.post_handshake_auth = 
                                           1
                                               ;
        break;
      case 0x7f + 56:
        opts->present.inline_commands = 
                                       1
                                           ;
        opts->enabled.inline_commands = 
                                       1
                                           ;
        break;
      case 0x7f + 57:
        opts->present.inline_commands_prefix = 
                                              1
                                                  ;
        opts->arg.inline_commands_prefix = optarg;
        opts->enabled.inline_commands_prefix = 
                                              1
                                                  ;
        break;
      case 0x7f + 58:
        opts->present.provider = 
                                1
                                    ;
        opts->arg.provider = optarg;
        opts->enabled.provider = 
                                1
                                    ;
        break;
      case 0x7f + 59:
        opts->present.fips140_mode = 
                                    1
                                        ;
        opts->enabled.fips140_mode = 
                                    1
                                        ;
        break;
      case 0x7f + 60:
        opts->present.list_config = 
                                   1
                                       ;
        opts->enabled.list_config = 
                                   1
                                       ;
        break;
      case 0x7f + 61:
        opts->present.logfile = 
                               1
                                   ;
        opts->arg.logfile = optarg;
        opts->enabled.logfile = 
                               1
                                   ;
        break;
      case 0x7f + 62:
        opts->present.keymatexport = 
                                    1
                                        ;
        opts->arg.keymatexport = optarg;
        opts->enabled.keymatexport = 
                                    1
                                        ;
        break;
      case 0x7f + 63:
        opts->present.keymatexportsize = 
                                        1
                                            ;
        opts->arg.keymatexportsize = optarg;
        opts->value.keymatexportsize = parse_number(optarg);
        opts->enabled.keymatexportsize = 
                                        1
                                            ;
        break;
      case 0x7f + 64:
        opts->present.waitresumption = 
                                      1
                                          ;
        opts->enabled.waitresumption = 
                                      1
                                          ;
        break;
      case 0x7f + 65:
        opts->present.ca_auto_retrieve = 
                                        1
                                            ;
        opts->enabled.ca_auto_retrieve = 
                                        1
                                            ;
        break;
      case 0x7f + 66:
        opts->present.ca_auto_retrieve = 
                                        1
                                            ;
        opts->enabled.ca_auto_retrieve = 
                                        0
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

  if (gnutls_cli_options.present.debug && gnutls_cli_options.value.debug < 0)
    {
      error (
            1
                        , 0, "%s option value %d is out of range.",
             "debug", opts->value.debug);
    }
  if (gnutls_cli_options.present.debug && gnutls_cli_options.value.debug > 9999)
    {
      error (
            1
                        , 0, "%s option value %d is out of range",
             "debug", opts->value.debug);
    }
  if (gnutls_cli_options.present.starttls_proto && gnutls_cli_options.present.starttls)
    {
      error (
            1
                        , 0, "the '%s' and '%s' options conflict",
             "starttls-proto", "starttls");
    }
  if (gnutls_cli_options.present.mtu && gnutls_cli_options.value.mtu < 0)
    {
      error (
            1
                        , 0, "%s option value %d is out of range.",
             "mtu", opts->value.mtu);
    }
  if (gnutls_cli_options.present.mtu && gnutls_cli_options.value.mtu > 17000)
    {
      error (
            1
                        , 0, "%s option value %d is out of range",
             "mtu", opts->value.mtu);
    }
  if (gnutls_cli_options.present.save_ocsp && gnutls_cli_options.present.save_ocsp_multi)
    {
      error (
            1
                        , 0, "the '%s' and '%s' options conflict",
             "save-ocsp", "save_ocsp_multi");
    }
  if (gnutls_cli_options.present.save_ocsp_multi && gnutls_cli_options.present.save_ocsp)
    {
      error (
            1
                        , 0, "the '%s' and '%s' options conflict",
             "save-ocsp-multi", "save_ocsp");
    }
  if (gnutls_cli_options.present.x509certfile && !gnutls_cli_options.present.x509keyfile)
    {
      error (
            1
                        , 0, "%s option requires the %s options",
             "x509certfile", "x509keyfile");
    }
  if (gnutls_cli_options.present.rawpkfile && !gnutls_cli_options.present.rawpkkeyfile)
    {
      error (
            1
                        , 0, "%s option requires the %s options",
             "rawpkfile", "rawpkkeyfile");
    }
  if (gnutls_cli_options.present.list && gnutls_cli_options.present.port)
    {
      error (
            1
                        , 0, "the '%s' and '%s' options conflict",
             "list", "port");
    }
  if (gnutls_cli_options.present.recordsize && gnutls_cli_options.value.recordsize < 0)
    {
      error (
            1
                        , 0, "%s option value %d is out of range.",
             "recordsize", opts->value.recordsize);
    }
  if (gnutls_cli_options.present.recordsize && gnutls_cli_options.value.recordsize > 4096)
    {
      error (
            1
                        , 0, "%s option value %d is out of range",
             "recordsize", opts->value.recordsize);
    }


  if (gnutls_cli_options.present.help)
    {
      usage (
     stdout
     , (0));
    }

  if (gnutls_cli_options.present.more_help)





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


  if (gnutls_cli_options.present.version)
    {
      if (!gnutls_cli_options.arg.version || !strcmp (gnutls_cli_options.arg.version, "c"))
        {
          const char str[] =
            "gnutls-cli 3.7.8\n"
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
      else if (!strcmp (gnutls_cli_options.arg.version, "v"))
        {
          const char str[] =
            "gnutls-cli 3.7.8\n";
          fprintf (
                  stdout
                        , "%s", str);
          exit(0);
        }
      else if (!strcmp (gnutls_cli_options.arg.version, "n"))
        {
          const char str[] =
            "gnutls-cli 3.7.8\n"
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
    "gnutls-cli - GnuTLS client\n"
    "Usage:  gnutls-cli [ -<flag> [<val>] | --<name>[{=| }<val>] ]... [hostname]\n"
    "\n"
    "None:\n"
    "\n"
    "   -d, --debug=num            Enable debugging\n"
    "				- it must be in the range:\n"
    "				  0 to 9999\n"
    "   -V, --verbose              More verbose output\n"
    "       --tofu                 Enable trust on first use authentication\n"
    "       --strict-tofu          Fail to connect if a certificate is unknown or a known certificate has changed\n"
    "       --dane                 Enable DANE certificate verification (DNSSEC)\n"
    "       --local-dns            Use the local DNS server for DNSSEC resolving\n"
    "       --ca-verification      Enable CA certificate verification\n"
    "				- enabled by default\n"
    "				- disabled as '--no-ca-verification'\n"
    "       --ocsp                 Enable OCSP certificate verification\n"
    "   -r, --resume               Establish a session and resume\n"
    "       --earlydata=str        Send early data on resumption from the specified file\n"
    "   -e, --rehandshake          Establish a session and rehandshake\n"
    "       --sni-hostname=str     Server's hostname for server name indication extension\n"
    "       --verify-hostname=str  Server's hostname to use for validation\n"
    "   -s, --starttls             Connect, establish a plain session and start TLS\n"
    "       --app-proto            an alias for the 'starttls-proto' option\n"
    "       --starttls-proto=str   The application protocol to be used to obtain the server's certificate (https, ftp, smtp, imap, ldap, xmpp, lmtp, pop3, nntp, sieve, postgres)\n"
    "				- prohibits the option 'starttls'\n"
    "   -u, --udp                  Use DTLS (datagram TLS) over UDP\n"
    "       --mtu=num              Set MTU for datagram TLS\n"
    "				- it must be in the range:\n"
    "				  0 to 17000\n"
    "       --crlf                 Send CR LF instead of LF\n"
    "       --fastopen             Enable TCP Fast Open\n"
    "       --x509fmtder           Use DER format for certificates to read from\n"
    "       --print-cert           Print peer's certificate in PEM format\n"
    "       --save-cert=str        Save the peer's certificate chain in the specified file in PEM format\n"
    "       --save-ocsp=str        Save the peer's OCSP status response in the provided file\n"
    "				- prohibits the option 'save-ocsp-multi'\n"
    "       --save-ocsp-multi=str  Save all OCSP responses provided by the peer in this file\n"
    "				- prohibits the option 'save-ocsp'\n"
    "       --save-server-trace=str Save the server-side TLS message trace in the provided file\n"
    "       --save-client-trace=str Save the client-side TLS message trace in the provided file\n"
    "       --dh-bits=num          The minimum number of bits allowed for DH\n"
    "       --priority=str         Priorities string\n"
    "       --x509cafile=str       Certificate file or PKCS #11 URL to use\n"
    "       --x509crlfile=file     CRL file to use\n"
    "				- file must pre-exist\n"
    "       --x509keyfile=str      X.509 key file or PKCS #11 URL to use\n"
    "       --x509certfile=str     X.509 Certificate file or PKCS #11 URL to use\n"
    "				- requires the option 'x509keyfile'\n"
    "       --rawpkkeyfile=str     Private key file (PKCS #8 or PKCS #12) or PKCS #11 URL to use\n"
    "       --rawpkfile=str        Raw public-key file to use\n"
    "				- requires the option 'rawpkkeyfile'\n"
    "       --srpusername=str      SRP username to use\n"
    "       --srppasswd=str        SRP password to use\n"
    "       --pskusername=str      PSK username to use\n"
    "       --pskkey=str           PSK key (in hex) to use\n"
    "   -p, --port=str             The port or service to connect to\n"
    "       --insecure             Don't abort program if server certificate can't be validated\n"
    "       --verify-allow-broken  Allow broken algorithms, such as MD5 for certificate verification\n"
    "       --benchmark-ciphers    Benchmark individual ciphers\n"
    "       --benchmark-tls-kx     Benchmark TLS key exchange methods\n"
    "       --benchmark-tls-ciphers  Benchmark TLS ciphers\n"
    "   -l, --list                 Print a list of the supported algorithms and modes\n"
    "				- prohibits the option 'port'\n"
    "       --priority-list        Print a list of the supported priority strings\n"
    "       --noticket             Don't allow session tickets\n"
    "       --srtp-profiles=str    Offer SRTP profiles\n"
    "       --alpn=str             Application layer protocol\n"
    "       --compress-cert=str    Compress certificate\n"
    "   -b, --heartbeat            Activate heartbeat support\n"
    "       --recordsize=num       The maximum record size to advertise\n"
    "				- it must be in the range:\n"
    "				  0 to 4096\n"
    "       --disable-sni          Do not send a Server Name Indication (SNI)\n"
    "       --single-key-share     Send a single key share under TLS1.3\n"
    "       --post-handshake-auth  Enable post-handshake authentication under TLS1.3\n"
    "       --inline-commands      Inline commands of the form ^<cmd>^\n"
    "       --inline-commands-prefix=str Change the default delimiter for inline commands\n"
    "       --provider=file        Specify the PKCS #11 provider library\n"
    "				- file must pre-exist\n"
    "       --fips140-mode         Reports the status of the FIPS140-2 mode in gnutls library\n"
    "       --list-config          Reports the configuration of the library\n"
    "       --logfile=str          Redirect informational messages to a specific file\n"
    "       --keymatexport=str     Label used for exporting keying material\n"
    "       --keymatexportsize=num Size of the exported keying material\n"
    "       --waitresumption       Block waiting for the resumption data under TLS1.3\n"
    "       --ca-auto-retrieve     Enable automatic retrieval of missing CA certificates\n"
    "\n"
    "Version, usage and configuration options:\n"
    "\n"
    "   -v, --version[=arg]        output version information and exit\n"
    "   -h, --help                 display extended usage information and exit\n"
    "   -!, --more-help            extended usage information passed thru pager\n"
    "\n"
    "Options are specified by doubled hyphens and their name or by a single\n"
    "hyphen and the flag character.\n"
    "Operands and options may be intermixed.  They will be reordered.\n"
    "\n"
    "Simple client program to set up a TLS connection to some other computer. \n"
    "It sets up a TLS connection and forwards data from the standard input to the secured socket and vice versa.\n"
    "\n"
    "Please send bug reports to:  <bugs@gnutls.org>\n"
    "\n";
  fprintf (out, "%s", str);
  exit (status);
}
