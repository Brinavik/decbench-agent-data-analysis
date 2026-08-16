











































void platform_pre_listen(void);
void platform_pre_fork(void);
void platform_pre_restart(void);
void platform_post_fork_parent(pid_t child_pid);
void platform_post_fork_child(void);
int platform_privileged_uidswap(void);
void platform_setusercontext(struct passwd *);
void platform_setusercontext_post_groups(struct passwd *);
char *platform_get_krb5_client(const char *);
char *platform_krb5_get_principal_name(const char *);
int platform_locked_account(struct passwd *);
int platform_sys_dir_uid(uid_t);
void platform_disable_tracing(int);


void platform_pledge_agent(void);
void platform_pledge_sftp_server(void);
void platform_pledge_mux(void);









int b64_ntop(u_char const *src, size_t srclength, char *target,
    size_t targsize);






int b64_pton(char const *src, u_char *target, size_t targsize);
char * readpassphrase(const char *, char *, size_t, int);
char *vis(char *, int, int, int);
int strvis(char *, const char *, int);
int stravis(char **, const char *, int);
int strnvis(char *, const char *, size_t, int)
  __attribute__ (());
int strvisx(char *, const char *, size_t, int)
  __attribute__ (());
int strunvis(char *, const char *);
int unvis(char *, char, int *, int);
ssize_t strnunvis(char *, const char *, size_t)
  __attribute__ (());

struct rdatainfo {
 unsigned int rdi_length;
 unsigned char *rdi_data;
};

struct rrsetinfo {
 unsigned int rri_flags;
 unsigned int rri_rdclass;
 unsigned int rri_rdtype;
 unsigned int rri_ttl;
 unsigned int rri_nrdatas;
 unsigned int rri_nsigs;
 char *rri_name;
 struct rdatainfo *rri_rdatas;
 struct rdatainfo *rri_sigs;
};

int getrrsetbyname(const char *, unsigned int, unsigned int, unsigned int, struct rrsetinfo **);
void freerrset(struct rrsetinfo *);
typedef struct BlowfishContext {
 u_int32_t S[4][256];
 u_int32_t P[16 + 2];
} blf_ctx;







void Blowfish_encipher(blf_ctx *, u_int32_t *, u_int32_t *);
void Blowfish_decipher(blf_ctx *, u_int32_t *, u_int32_t *);
void Blowfish_initstate(blf_ctx *);
void Blowfish_expand0state(blf_ctx *, const u_int8_t *, u_int16_t);
void Blowfish_expandstate
(blf_ctx *, const u_int8_t *, u_int16_t, const u_int8_t *, u_int16_t);



void blf_key(blf_ctx *, const u_int8_t *, u_int16_t);
void blf_enc(blf_ctx *, u_int32_t *, u_int16_t);
void blf_dec(blf_ctx *, u_int32_t *, u_int16_t);

void blf_ecb_encrypt(blf_ctx *, u_int8_t *, u_int32_t);
void blf_ecb_decrypt(blf_ctx *, u_int8_t *, u_int32_t);

void blf_cbc_encrypt(blf_ctx *, u_int8_t *, u_int8_t *, u_int32_t);
void blf_cbc_decrypt(blf_ctx *, u_int8_t *, u_int8_t *, u_int32_t);


u_int32_t Blowfish_stream2word(const u_int8_t *, u_int16_t , u_int16_t *);
int bindresvport_sa(int sd, struct sockaddr *sa);
void *memmem(const void *, size_t, const void *, size_t);







void *recallocarray(void *, size_t, size_t, size_t);







size_t strlcpy(char *dst, const char *src, size_t siz);



size_t strlcat(char *dst, const char *src, size_t siz);
void strmode(int mode, char *p);
int fmt_scaled(long long number, char *result);



int scan_scaled(char *, long long *);
void setproctitle(const char *fmt, ...);
void compat_init_setproctitle(int argc, char *argv[]);







int BSDgetopt(int argc, char * const *argv, const char *opts);
struct option {

 const char *name;




 int has_arg;

 int *flag;

 int val;
};

int getopt_long(int, char * const *, const char *,
     const struct option *, int *);
int getopt_long_only(int, char * const *, const char *,
     const struct option *, int *);


int BSDgetopt(int, char * const *, const char *);
int getsubopt(char **, char * const *, char **);

extern char *BSDoptarg;
extern int BSDopterr;
extern int BSDoptind;
extern int BSDoptopt;
extern int BSDoptreset;
extern char *suboptarg;
char *ssh_get_progname(char *);
int seed_from_prngd(unsigned char *, size_t);
int setlogin(const char *);
int pledge(const char *promises, const char *paths[]);



int getpeereid(int , uid_t *, gid_t *);



uint32_t arc4random(void);



void arc4random_buf(void *, size_t);







uint32_t arc4random_uniform(uint32_t);
long long strtonum(const char *, long long, long long, const char **);
char *user_from_uid(uid_t, int);



char *group_from_gid(gid_t, int);



int timingsafe_bcmp(const void *, const void *, size_t);



int bcrypt_pbkdf(const char *, size_t, const uint8_t *, size_t,
    uint8_t *, size_t, unsigned int);







void freezero(void *, size_t);
char *xcrypt(const char *password, const char *salt);
char *shadow_pw(struct passwd *pw);





void oom_adjust_restore(void);
void oom_adjust_setup(void);
void solaris_contract_pre_fork(void);
void solaris_contract_post_fork_child(void);
void solaris_contract_post_fork_parent(pid_t pid);
void solaris_set_default_project(struct passwd *);
struct Channel;
struct ssh;



int sys_tun_open(int, int, char **);




int sys_tun_infilter(struct ssh *, struct Channel *, char *, int);
u_char *sys_tun_outfilter(struct ssh *, struct Channel *, u_char **, size_t *);






char *sys_get_rdomain(int fd);
int sys_set_rdomain(int fd, const char *name);
int sys_valid_rdomain(const char *name);
void kludge_FD_SET(int, fd_set *);
int kludge_FD_ISSET(int, fd_set *);

struct sshbuf;

void seed_rng(void);
void rexec_send_rng_seed(struct sshbuf *);
void rexec_recv_rng_seed(struct sshbuf *);







typedef enum {
 NONE = 0, KILO = 1, MEGA = 2, GIGA = 3, TERA = 4, PETA = 5, EXA = 6
} unit_type;


static const unit_type units[] = { NONE, KILO, MEGA, GIGA, TERA, PETA, EXA };
static const char scale_chars[] = "BKMGTPE";
static const long long scale_factors[] = {
 1LL,
 1024LL,
 1024LL*1024,
 1024LL*1024*1024,
 1024LL*1024*1024*1024,
 1024LL*1024*1024*1024*1024,
 1024LL*1024*1024*1024*1024*1024,
};







int
scan_scaled(char *scaled, long long *result)
{
 char *p = scaled;
 int sign = 0;
 unsigned int i, ndigits = 0, fract_digits = 0;
 long long scale_fact = 1, whole = 0, fpart = 0;


 while (
       (((
       (unsigned char)*p
       ) & ~0x7f) == 0) 
                                  && 
                                     ((*__ctype_b_loc ())[(int) ((
                                     (unsigned char)*p
                                     ))] & (unsigned short int) _ISspace)
                                                               )
  ++p;


 while (*p == '-' || *p == '+') {
  if (*p == '-') {
   if (sign) {
    
   (*__errno_location ()) 
         = 
           22
                 ;
    return -1;
   }
   sign = -1;
   ++p;
  } else if (*p == '+') {
   if (sign) {
    
   (*__errno_location ()) 
         = 
           22
                 ;
    return -1;
   }
   sign = +1;
   ++p;
  }
 }






 for (; 
       (((
       (unsigned char)*p
       ) & ~0x7f) == 0) 
                                  &&
     (
     ((*__ctype_b_loc ())[(int) ((
     (unsigned char)*p
     ))] & (unsigned short int) _ISdigit) 
                                || *p=='.'); ++p) {
  if (*p == '.') {
   if (fract_digits > 0) {
    
   (*__errno_location ()) 
         = 
           22
                 ;
    return -1;
   }
   fract_digits = 1;
   continue;
  }

  i = (*p) - '0';
  if (fract_digits > 0) {
   if (fract_digits >= ((sizeof(units)/sizeof(units[0])) * 3)-1)

    continue;
   fract_digits++;
   if (fpart > 0x7fffffffffffffffLL / 10) {
    
   (*__errno_location ()) 
         = 
           34
                 ;
    return -1;
   }
   fpart *= 10;
   if (i > 0x7fffffffffffffffLL - fpart) {
    
   (*__errno_location ()) 
         = 
           34
                 ;
    return -1;
   }
   fpart += i;
  } else {
   if (++ndigits >= ((sizeof(units)/sizeof(units[0])) * 3)) {
    
   (*__errno_location ()) 
         = 
           34
                 ;
    return -1;
   }
   if (whole > 0x7fffffffffffffffLL / 10) {
    
   (*__errno_location ()) 
         = 
           34
                 ;
    return -1;
   }
   whole *= 10;
   if (i > 0x7fffffffffffffffLL - whole) {
    
   (*__errno_location ()) 
         = 
           34
                 ;
    return -1;
   }
   whole += i;
  }
 }

 if (sign)
  whole *= sign;


 if (!*p) {
  *result = whole;
  return 0;
 }


 for (i = 0; i < (sizeof(units)/sizeof(units[0])); i++) {


  if (*p == scale_chars[i] ||
   *p == tolower((unsigned char)scale_chars[i])) {


   if (
      ((*__ctype_b_loc ())[(int) ((
      (unsigned char)*(p+1)
      ))] & (unsigned short int) _ISalnum)
                                    ) {
    
   (*__errno_location ()) 
         = 
           22
                 ;
    return -1;
   }
   scale_fact = scale_factors[i];


   if (whole > 0x7fffffffffffffffLL / scale_fact ||
       whole < 
              (-0x7fffffffffffffffLL - 1LL) 
                        / scale_fact) {
    
   (*__errno_location ()) 
         = 
           34
                 ;
    return -1;
   }


   whole *= scale_fact;




   while (fpart >= 0x7fffffffffffffffLL / scale_fact ||
       fpart <= 
               (-0x7fffffffffffffffLL - 1LL) 
                         / scale_fact) {
    fpart /= 10;
    fract_digits--;
   }
   fpart *= scale_fact;
   if (fract_digits > 0) {
    for (i = 0; i < fract_digits -1; i++)
     fpart /= 10;
   }
   if (sign == -1)
    whole -= fpart;
   else
    whole += fpart;
   *result = whole;
   return 0;
  }
 }


 
(*__errno_location ()) 
      = 
        22
              ;
 return -1;
}





int
fmt_scaled(long long number, char *result)
{
 long long abval, fract = 0;
 unsigned int i;
 unit_type unit = NONE;


 if (number == 
              (-0x7fffffffffffffffLL - 1LL)
                       ) {
  
 (*__errno_location ()) 
       = 
         34
               ;
  return -1;
 }

 abval = llabs(number);


 if (abval / 1024 >= scale_factors[(sizeof(units)/sizeof(units[0]))-1]) {
  
 (*__errno_location ()) 
       = 
         34
               ;
  return -1;
 }


 for (i = 0; i < (sizeof(units)/sizeof(units[0])); i++) {
  if (abval/1024 < scale_factors[i]) {
   unit = units[i];
   fract = (i == 0) ? 0 : abval % scale_factors[i];
   number /= scale_factors[i];
   if (i > 0)
    fract /= scale_factors[i - 1];
   break;
  }
 }

 fract = (10 * fract + 512) / 1024;

 if (fract >= 10) {
  if (number >= 0)
   number++;
  else
   number--;
  fract = 0;
 } else if (fract < 0) {

  fract = 0;
 }

 if (number == 0)
  strlcpy(result, "0B", 7);
 else if (unit == NONE || number >= 100 || number <= -100) {
  if (fract >= 5) {
   if (number >= 0)
    number++;
   else
    number--;
  }
  (void)snprintf(result, 7, "%lld%c",
   number, scale_chars[unit]);
 } else
  (void)snprintf(result, 7, "%lld.%1lld%c",
   number, fract, scale_chars[unit]);

 return 0;
}
