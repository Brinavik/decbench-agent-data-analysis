











































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









struct xaddr {
 sa_family_t af;
 union {
  struct in_addr v4;
  struct in6_addr v6;
  u_int8_t addr8[16];
  u_int16_t addr16[8];
  u_int32_t addr32[4];
 } xa;
 u_int32_t scope_id;





};

int addr_unicast_masklen(int af);
int addr_xaddr_to_sa(const struct xaddr *xa, struct sockaddr *sa,
    socklen_t *len, u_int16_t port);
int addr_sa_to_xaddr(struct sockaddr *sa, socklen_t slen, struct xaddr *xa);
int addr_netmask(int af, u_int l, struct xaddr *n);
int addr_hostmask(int af, u_int l, struct xaddr *n);
int addr_invert(struct xaddr *n);
int addr_pton(const char *p, struct xaddr *n);
int addr_sa_pton(const char *h, const char *s, struct sockaddr *sa,
    socklen_t slen);
int addr_pton_cidr(const char *p, struct xaddr *n, u_int *l);
int addr_ntop(const struct xaddr *n, char *p, size_t len);
int addr_and(struct xaddr *dst, const struct xaddr *a, const struct xaddr *b);
int addr_cmp(const struct xaddr *a, const struct xaddr *b);
int addr_is_all0s(const struct xaddr *n);
int addr_host_is_all0s(const struct xaddr *n, u_int masklen);
int addr_netmatch(const struct xaddr *host, const struct xaddr *net,
    u_int masklen);



int
addr_unicast_masklen(int af)
{
 switch (af) {
 case 
     2
            :
  return 32;
 case 
     10
             :
  return 128;
 default:
  return -1;
 }
}

static inline int
masklen_valid(int af, u_int masklen)
{
 switch (af) {
 case 
     2
            :
  return masklen <= 32 ? 0 : -1;
 case 
     10
             :
  return masklen <= 128 ? 0 : -1;
 default:
  return -1;
 }
}

int
addr_xaddr_to_sa(const struct xaddr *xa, struct sockaddr *sa, socklen_t *len,
    u_int16_t port)
{
 struct sockaddr_in *in4 = (struct sockaddr_in *)sa;
 struct sockaddr_in6 *in6 = (struct sockaddr_in6 *)sa;

 if (xa == 
          ((void *)0) 
               || sa == 
                        ((void *)0) 
                             || len == 
                                       ((void *)0)
                                           )
  return -1;

 switch (xa->af) {
 case 
     2
            :
  if (*len < sizeof(*in4))
   return -1;
  memset(sa, '\0', sizeof(*in4));
  *len = sizeof(*in4);



  in4->sin_family = 
                   2
                          ;
  in4->sin_port = htons(port);
  memcpy(&in4->sin_addr, &xa->xa.v4, sizeof(in4->sin_addr));
  break;
 case 
     10
             :
  if (*len < sizeof(*in6))
   return -1;
  memset(sa, '\0', sizeof(*in6));
  *len = sizeof(*in6);



  in6->sin6_family = 
                    10
                            ;
  in6->sin6_port = htons(port);
  memcpy(&in6->sin6_addr, &xa->xa.v6, sizeof(in6->sin6_addr));

  in6->sin6_scope_id = xa->scope_id;

  break;
 default:
  return -1;
 }
 return 0;
}





int
addr_sa_to_xaddr(struct sockaddr *sa, socklen_t slen, struct xaddr *xa)
{
 struct sockaddr_in *in4 = (struct sockaddr_in *)sa;
 struct sockaddr_in6 *in6 = (struct sockaddr_in6 *)sa;

 memset(xa, '\0', sizeof(*xa));

 switch (sa->sa_family) {
 case 
     2
            :
  if (slen < (socklen_t)sizeof(*in4))
   return -1;
  xa->af = 
          2
                 ;
  memcpy(&xa->xa.v4, &in4->sin_addr, sizeof(xa->xa.v4));
  break;
 case 
     10
             :
  if (slen < (socklen_t)sizeof(*in6))
   return -1;
  xa->af = 
          10
                  ;
  memcpy(&xa->xa.v6, &in6->sin6_addr, sizeof(xa->xa.v6));

  xa->scope_id = in6->sin6_scope_id;

  break;
 default:
  return -1;
 }

 return 0;
}

int
addr_invert(struct xaddr *n)
{
 int i;

 if (n == 
         ((void *)0)
             )
  return -1;

 switch (n->af) {
 case 
     2
            :
  n->xa.v4.s_addr = ~n->xa.v4.s_addr;
  return 0;
 case 
     10
             :
  for (i = 0; i < 4; i++)
   n->xa.addr32[i] = ~n->xa.addr32[i];
  return 0;
 default:
  return -1;
 }
}






int
addr_netmask(int af, u_int l, struct xaddr *n)
{
 int i;

 if (masklen_valid(af, l) != 0 || n == 
                                      ((void *)0)
                                          )
  return -1;

 memset(n, '\0', sizeof(*n));
 switch (af) {
 case 
     2
            :
  n->af = 
         2
                ;
  if (l == 0)
   return 0;
  n->xa.v4.s_addr = htonl((0xffffffff << (32 - l)) & 0xffffffff);
  return 0;
 case 
     10
             :
  n->af = 
         10
                 ;
  for (i = 0; i < 4 && l >= 32; i++, l -= 32)
   n->xa.addr32[i] = 0xffffffffU;
  if (i < 4 && l != 0)
   n->xa.addr32[i] = htonl((0xffffffff << (32 - l)) &
       0xffffffff);
  return 0;
 default:
  return -1;
 }
}

int
addr_hostmask(int af, u_int l, struct xaddr *n)
{
 if (addr_netmask(af, l, n) == -1 || addr_invert(n) == -1)
  return -1;
 return 0;
}





int
addr_and(struct xaddr *dst, const struct xaddr *a, const struct xaddr *b)
{
 int i;

 if (dst == 
           ((void *)0) 
                || a == 
                        ((void *)0) 
                             || b == 
                                     ((void *)0) 
                                          || a->af != b->af)
  return -1;

 memcpy(dst, a, sizeof(*dst));
 switch (a->af) {
 case 
     2
            :
  dst->xa.v4.s_addr &= b->xa.v4.s_addr;
  return 0;
 case 
     10
             :
  dst->scope_id = a->scope_id;
  for (i = 0; i < 4; i++)
   dst->xa.addr32[i] &= b->xa.addr32[i];
  return 0;
 default:
  return -1;
 }
}

int
addr_cmp(const struct xaddr *a, const struct xaddr *b)
{
 int i;

 if (a->af != b->af)
  return (a->af == 
                  10 
                           ? 1 : -1);

 switch (a->af) {
 case 
     2
            :




  if (a->xa.v4.s_addr == b->xa.v4.s_addr)
   return 0;
  return (ntohl(a->xa.v4.s_addr) > ntohl(b->xa.v4.s_addr) ? 1 : -1);
 case 
     10
             :




  for (i = 0; i < 16; i++)
   if (a->xa.addr8[i] - b->xa.addr8[i] != 0)
    return (a->xa.addr8[i] - b->xa.addr8[i]);
  if (a->scope_id == b->scope_id)
   return (0);
  return (a->scope_id > b->scope_id ? 1 : -1);
 default:
  return (-1);
 }
}

int
addr_is_all0s(const struct xaddr *a)
{
 int i;

 switch (a->af) {
 case 
     2
            :
  return (a->xa.v4.s_addr == 0 ? 0 : -1);
 case 
     10
             :
  for (i = 0; i < 4; i++)
   if (a->xa.addr32[i] != 0)
    return -1;
  return 0;
 default:
  return -1;
 }
}







int
addr_host_is_all0s(const struct xaddr *a, u_int masklen)
{
 struct xaddr tmp_addr, tmp_mask, tmp_result;

 memcpy(&tmp_addr, a, sizeof(tmp_addr));
 if (addr_hostmask(a->af, masklen, &tmp_mask) == -1)
  return -1;
 if (addr_and(&tmp_result, &tmp_addr, &tmp_mask) == -1)
  return -1;
 return addr_is_all0s(&tmp_result);
}





int
addr_pton(const char *p, struct xaddr *n)
{
 struct addrinfo hints, *ai;

 memset(&hints, '\0', sizeof(hints));
 hints.ai_flags = 
                 0x0004
                               ;

 if (p == 
         ((void *)0) 
              || getaddrinfo(p, 
                                ((void *)0)
                                    , &hints, &ai) != 0)
  return -1;

 if (ai == 
          ((void *)0)
              )
  return -1;

 if (ai->ai_addr == 
                   ((void *)0)
                       ) {
  freeaddrinfo(ai);
  return -1;
 }

 if (n != 
         ((void *)0) 
              && addr_sa_to_xaddr(ai->ai_addr, ai->ai_addrlen,
     n) == -1) {
  freeaddrinfo(ai);
  return -1;
 }

 freeaddrinfo(ai);
 return 0;
}

int
addr_sa_pton(const char *h, const char *s, struct sockaddr *sa, socklen_t slen)
{
 struct addrinfo hints, *ai;

 memset(&hints, '\0', sizeof(hints));
 hints.ai_flags = 
                 0x0004
                               ;

 if (h == 
         ((void *)0) 
              || getaddrinfo(h, s, &hints, &ai) != 0)
  return -1;

 if (ai == 
          ((void *)0)
              )
  return -1;

 if (ai->ai_addr == 
                   ((void *)0)
                       ) {
  freeaddrinfo(ai);
  return -1;
 }

 if (sa != 
          ((void *)0)
              ) {
  if (slen < ai->ai_addrlen) {
   freeaddrinfo(ai);
   return -1;
  }
  memcpy(sa, &ai->ai_addr, ai->ai_addrlen);
 }

 freeaddrinfo(ai);
 return 0;
}

int
addr_ntop(const struct xaddr *n, char *p, size_t len)
{
 struct sockaddr_storage ss;
 socklen_t slen = sizeof(ss);

 if (addr_xaddr_to_sa(n, ((struct sockaddr *)(&ss)), &slen, 0) == -1)
  return -1;
 if (p == 
         ((void *)0) 
              || len == 0)
  return -1;
 if (getnameinfo(((struct sockaddr *)(&ss)), slen, p, len, 
                                        ((void *)0)
                                            , 0,
     
    1
                  ) == -1)
  return -1;

 return 0;
}





int
addr_pton_cidr(const char *p, struct xaddr *n, u_int *l)
{
 struct xaddr tmp;
 long unsigned int masklen = 999;
 char addrbuf[64], *mp, *cp;


 if (p == 
         ((void *)0) 
              || strlcpy(addrbuf, p, sizeof(addrbuf)) >= sizeof(addrbuf))
  return -1;

 if ((mp = strchr(addrbuf, '/')) != 
                                   ((void *)0)
                                       ) {
  *mp = '\0';
  mp++;
  masklen = strtoul(mp, &cp, 10);
  if (*mp < '0' || *mp > '9' || *cp != '\0' || masklen > 128)
   return -1;
 }

 if (addr_pton(addrbuf, &tmp) == -1)
  return -1;

 if (mp == 
          ((void *)0)
              )
  masklen = addr_unicast_masklen(tmp.af);
 if (masklen_valid(tmp.af, masklen) == -1)
  return -2;
 if (addr_host_is_all0s(&tmp, masklen) != 0)
  return -2;

 if (n != 
         ((void *)0)
             )
  memcpy(n, &tmp, sizeof(*n));
 if (l != 
         ((void *)0)
             )
  *l = masklen;

 return 0;
}

int
addr_netmatch(const struct xaddr *host, const struct xaddr *net, u_int masklen)
{
 struct xaddr tmp_mask, tmp_result;

 if (host->af != net->af)
  return -1;

 if (addr_netmask(host->af, masklen, &tmp_mask) == -1)
  return -1;
 if (addr_and(&tmp_result, host, &tmp_mask) == -1)
  return -1;
 return addr_cmp(&tmp_result, net);
}
