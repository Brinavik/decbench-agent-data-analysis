











































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







static u_int16_t
(_ssh_compat_getshort(const u_char *msgp))
{
 u_int16_t u;

 
do { const unsigned char *t_cp = (const unsigned char *)(
msgp
); (
u
) = ((uint16_t)t_cp[0] << 8) | ((uint16_t)t_cp[1]) ; (
msgp
) += 2; } while (0)
                 ;
 return (u);
}

static u_int32_t
(_ssh_compat_getlong(const u_char *msgp))
{
 u_int32_t u;

 
do { const unsigned char *t_cp = (const unsigned char *)(
msgp
); (
u
) = ((uint32_t)t_cp[0] << 24) | ((uint32_t)t_cp[1] << 16) | ((uint32_t)t_cp[2] << 8) | ((uint32_t)t_cp[3]) ; (
msgp
) += 4; } while (0)
                ;
 return (u);
}






struct dns_query {
 char *name;
 u_int16_t type;
 u_int16_t class;
 struct dns_query *next;
};

struct dns_rr {
 char *name;
 u_int16_t type;
 u_int16_t class;
 u_int16_t ttl;
 u_int16_t size;
 void *rdata;
 struct dns_rr *next;
};

struct dns_response {
 HEADER header;
 struct dns_query *query;
 struct dns_rr *answer;
 struct dns_rr *authority;
 struct dns_rr *additional;
};

static struct dns_response *parse_dns_response(const u_char *, int);
static struct dns_query *parse_dns_qsection(const u_char *, int,
    const u_char **, int);
static struct dns_rr *parse_dns_rrsection(const u_char *, int, const u_char **,
    int);

static void free_dns_query(struct dns_query *);
static void free_dns_rr(struct dns_rr *);
static void free_dns_response(struct dns_response *);

static int count_dns_rr(struct dns_rr *, u_int16_t, u_int16_t);

int
getrrsetbyname(const char *hostname, unsigned int rdclass,
    unsigned int rdtype, unsigned int flags,
    struct rrsetinfo **res)
{
 struct __res_state *_resp = (&
                            (*__res_state())
                            );
 int result;
 struct rrsetinfo *rrset = 
                          ((void *)0)
                              ;
 struct dns_response *response = 
                                ((void *)0)
                                    ;
 struct dns_rr *rr;
 struct rdatainfo *rdata;
 int length;
 unsigned int index_ans, index_sig;
 u_char answer[0xffff];


 if (rdclass > 0xffff || rdtype > 0xffff) {
  result = 3;
  goto fail;
 }


 if (rdclass == 0xff || rdtype == 0xff) {
  result = 3;
  goto fail;
 }


 if (flags) {
  result = 3;
  goto fail;
 }


 if ((_resp->options & 
                      0x00000001
                              ) == 0 && 
                                        __res_init
                                                () == -1) {
  result = 2;
  goto fail;
 }







 if (_resp->options & 
                     0x00100000
                                  )
  _resp->options |= 
                   0x00800000
                                 ;



 length = res_query(hostname, (signed int) rdclass, (signed int) rdtype,
     answer, sizeof(answer));
 if (length < 0) {
  switch(
        (*__h_errno_location ())
               ) {
  case 
      1
                    :
   result = 4;
   goto fail;
  case 
      4
             :
   result = 5;
   goto fail;
  default:
   result = 2;
   goto fail;
  }
 }


 response = parse_dns_response(answer, length);
 if (response == 
                ((void *)0)
                    ) {
  result = 2;
  goto fail;
 }

 if (response->header.qdcount != 1) {
  result = 2;
  goto fail;
 }


 rrset = calloc(1, sizeof(struct rrsetinfo));
 if (rrset == 
             ((void *)0)
                 ) {
  result = 1;
  goto fail;
 }
 rrset->rri_rdclass = response->query->class;
 rrset->rri_rdtype = response->query->type;
 rrset->rri_ttl = response->answer->ttl;
 rrset->rri_nrdatas = response->header.ancount;



 if (response->header.ad == 1)
  rrset->rri_flags |= 1;



 rrset->rri_name = strdup(response->answer->name);
 if (rrset->rri_name == 
                       ((void *)0)
                           ) {
  result = 1;
  goto fail;
 }


 rrset->rri_nrdatas = count_dns_rr(response->answer, rrset->rri_rdclass,
     rrset->rri_rdtype);
 rrset->rri_nsigs = count_dns_rr(response->answer, rrset->rri_rdclass,
     
    ns_t_rrsig
           );


 rrset->rri_rdatas = calloc(rrset->rri_nrdatas,
     sizeof(struct rdatainfo));
 if (rrset->rri_rdatas == 
                         ((void *)0)
                             ) {
  result = 1;
  goto fail;
 }


 if (rrset->rri_nsigs > 0) {
  rrset->rri_sigs = calloc(rrset->rri_nsigs, sizeof(struct rdatainfo));
  if (rrset->rri_sigs == 
                        ((void *)0)
                            ) {
   result = 1;
   goto fail;
  }
 }


 for (rr = response->answer, index_ans = 0, index_sig = 0;
     rr; rr = rr->next) {

  rdata = 
         ((void *)0)
             ;

  if (rr->class == rrset->rri_rdclass &&
      rr->type == rrset->rri_rdtype)
   rdata = &rrset->rri_rdatas[index_ans++];

  if (rr->class == rrset->rri_rdclass &&
      rr->type == 
                  ns_t_rrsig
                         )
   rdata = &rrset->rri_sigs[index_sig++];

  if (rdata) {
   rdata->rdi_length = rr->size;
   rdata->rdi_data = malloc(rr->size);

   if (rdata->rdi_data == 
                         ((void *)0)
                             ) {
    result = 1;
    goto fail;
   }
   memcpy(rdata->rdi_data, rr->rdata, rr->size);
  }
 }
 free_dns_response(response);

 *res = rrset;
 return (0);

fail:
 if (rrset != 
             ((void *)0)
                 )
  freerrset(rrset);
 if (response != 
                ((void *)0)
                    )
  free_dns_response(response);
 return (result);
}

void
freerrset(struct rrsetinfo *rrset)
{
 u_int16_t i;

 if (rrset == 
             ((void *)0)
                 )
  return;

 if (rrset->rri_rdatas) {
  for (i = 0; i < rrset->rri_nrdatas; i++) {
   if (rrset->rri_rdatas[i].rdi_data == 
                                       ((void *)0)
                                           )
    break;
   free(rrset->rri_rdatas[i].rdi_data);
  }
  free(rrset->rri_rdatas);
 }

 if (rrset->rri_sigs) {
  for (i = 0; i < rrset->rri_nsigs; i++) {
   if (rrset->rri_sigs[i].rdi_data == 
                                     ((void *)0)
                                         )
    break;
   free(rrset->rri_sigs[i].rdi_data);
  }
  free(rrset->rri_sigs);
 }

 if (rrset->rri_name)
  free(rrset->rri_name);
 free(rrset);
}




static struct dns_response *
parse_dns_response(const u_char *answer, int size)
{
 struct dns_response *resp;
 const u_char *cp;


 resp = calloc(1, sizeof(*resp));
 if (resp == 
            ((void *)0)
                )
  return (
         ((void *)0)
             );


 cp = answer;


 memcpy(&resp->header, cp, 
                          12
                                  );
 cp += 
      12
              ;


 resp->header.qdcount = ntohs(resp->header.qdcount);
 resp->header.ancount = ntohs(resp->header.ancount);
 resp->header.nscount = ntohs(resp->header.nscount);
 resp->header.arcount = ntohs(resp->header.arcount);


 if (resp->header.qdcount < 1) {
  free_dns_response(resp);
  return (
         ((void *)0)
             );
 }


 resp->query = parse_dns_qsection(answer, size, &cp,
     resp->header.qdcount);
 if (resp->header.qdcount && resp->query == 
                                           ((void *)0)
                                               ) {
  free_dns_response(resp);
  return (
         ((void *)0)
             );
 }


 resp->answer = parse_dns_rrsection(answer, size, &cp,
     resp->header.ancount);
 if (resp->header.ancount && resp->answer == 
                                            ((void *)0)
                                                ) {
  free_dns_response(resp);
  return (
         ((void *)0)
             );
 }


 resp->authority = parse_dns_rrsection(answer, size, &cp,
     resp->header.nscount);
 if (resp->header.nscount && resp->authority == 
                                               ((void *)0)
                                                   ) {
  free_dns_response(resp);
  return (
         ((void *)0)
             );
 }


 resp->additional = parse_dns_rrsection(answer, size, &cp,
     resp->header.arcount);
 if (resp->header.arcount && resp->additional == 
                                                ((void *)0)
                                                    ) {
  free_dns_response(resp);
  return (
         ((void *)0)
             );
 }

 return (resp);
}

static struct dns_query *
parse_dns_qsection(const u_char *answer, int size, const u_char **cp, int count)
{
 struct dns_query *head, *curr, *prev;
 int i, length;
 char name[
          1025
                  ];

 for (i = 1, head = 
                   ((void *)0)
                       , prev = 
                                ((void *)0)
                                    ; i <= count; i++, prev = curr) {


  curr = calloc(1, sizeof(struct dns_query));
  if (curr == 
             ((void *)0)
                 ) {
   free_dns_query(head);
   return (
          ((void *)0)
              );
  }
  if (head == 
             ((void *)0)
                 )
   head = curr;
  if (prev != 
             ((void *)0)
                 )
   prev->next = curr;


  length = dn_expand(answer, answer + size, *cp, name,
      sizeof(name));
  if (length < 0) {
   free_dns_query(head);
   return (
          ((void *)0)
              );
  }
  curr->name = strdup(name);
  if (curr->name == 
                   ((void *)0)
                       ) {
   free_dns_query(head);
   return (
          ((void *)0)
              );
  }
  *cp += length;


  curr->type = (_ssh_compat_getshort(*cp));
  *cp += 
        2
               ;


  curr->class = (_ssh_compat_getshort(*cp));
  *cp += 
        2
               ;
 }

 return (head);
}

static struct dns_rr *
parse_dns_rrsection(const u_char *answer, int size, const u_char **cp,
    int count)
{
 struct dns_rr *head, *curr, *prev;
 int i, length;
 char name[
          1025
                  ];

 for (i = 1, head = 
                   ((void *)0)
                       , prev = 
                                ((void *)0)
                                    ; i <= count; i++, prev = curr) {


  curr = calloc(1, sizeof(struct dns_rr));
  if (curr == 
             ((void *)0)
                 ) {
   free_dns_rr(head);
   return (
          ((void *)0)
              );
  }
  if (head == 
             ((void *)0)
                 )
   head = curr;
  if (prev != 
             ((void *)0)
                 )
   prev->next = curr;


  length = dn_expand(answer, answer + size, *cp, name,
      sizeof(name));
  if (length < 0) {
   free_dns_rr(head);
   return (
          ((void *)0)
              );
  }
  curr->name = strdup(name);
  if (curr->name == 
                   ((void *)0)
                       ) {
   free_dns_rr(head);
   return (
          ((void *)0)
              );
  }
  *cp += length;


  curr->type = (_ssh_compat_getshort(*cp));
  *cp += 
        2
               ;


  curr->class = (_ssh_compat_getshort(*cp));
  *cp += 
        2
               ;


  curr->ttl = (_ssh_compat_getlong(*cp));
  *cp += 
        4
               ;


  curr->size = (_ssh_compat_getshort(*cp));
  *cp += 
        2
               ;


  curr->rdata = malloc(curr->size);
  if (curr->rdata == 
                    ((void *)0)
                        ) {
   free_dns_rr(head);
   return (
          ((void *)0)
              );
  }
  memcpy(curr->rdata, *cp, curr->size);
  *cp += curr->size;
 }

 return (head);
}

static void
free_dns_query(struct dns_query *p)
{
 if (p == 
         ((void *)0)
             )
  return;

 if (p->name)
  free(p->name);
 free_dns_query(p->next);
 free(p);
}

static void
free_dns_rr(struct dns_rr *p)
{
 if (p == 
         ((void *)0)
             )
  return;

 if (p->name)
  free(p->name);
 if (p->rdata)
  free(p->rdata);
 free_dns_rr(p->next);
 free(p);
}

static void
free_dns_response(struct dns_response *p)
{
 if (p == 
         ((void *)0)
             )
  return;

 free_dns_query(p->query);
 free_dns_rr(p->answer);
 free_dns_rr(p->authority);
 free_dns_rr(p->additional);
 free(p);
}

static int
count_dns_rr(struct dns_rr *p, u_int16_t class, u_int16_t type)
{
 int n = 0;

 while(p) {
  if (p->class == class && p->type == type)
   n++;
  p = p->next;
 }

 return (n);
}
